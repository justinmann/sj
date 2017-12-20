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
typedef struct td_int32_option int32_option;
struct td_int32_option {
    bool isvalid;
    int32_t value;
};
const int32_option int32_empty = { false };

typedef struct td_uint32_option uint32_option;
struct td_uint32_option {
    bool isvalid;
    uint32_t value;
};
const uint32_option uint32_empty = { false };

typedef struct td_int64_option int64_option;
struct td_int64_option {
    bool isvalid;
    int64_t value;
};
const int64_option int64_empty = { false };

typedef struct td_uint64_option uint64_option;
struct td_uint64_option {
    bool isvalid;
    uint64_t value;
};
const uint64_option uint64_empty = { false };

typedef struct td_void_option void_option;
struct td_void_option {
    bool isvalid;
    void* value;
};
const void_option void_empty = { false };

typedef struct td_char_option char_option;
struct td_char_option {
    bool isvalid;
    char value;
};
const char_option char_empty = { false };

typedef struct td_float_option float_option;
struct td_float_option {
    bool isvalid;
    float value;
};
const float_option float_empty = { false };

typedef struct td_double_option double_option;
struct td_double_option {
    bool isvalid;
    double value;
};
const double_option double_empty = { false };

const char* sjg_string1 = "shaders/v3f-c4f.vert";
const char* sjg_string10 = "shaders/v3f-n3f-phong.frag";
const char* sjg_string101 = "viewModel";
const char* sjg_string102 = "normalMat";
const char* sjg_string103 = "projection";
const char* sjg_string104 = "lightPos";
const char* sjg_string105 = "diffuseColor";
const char* sjg_string106 = "specColor";
const char* sjg_string11 = "shaders/v3f-t2f-n3f-phong.vert";
const char* sjg_string113 = "viewModel";
const char* sjg_string114 = "normalMat";
const char* sjg_string115 = "projection";
const char* sjg_string116 = "lightPos";
const char* sjg_string117 = "diffuseColor";
const char* sjg_string118 = "specColor";
const char* sjg_string12 = "shaders/v3f-t2f-n3f-phong.frag";
const char* sjg_string13 = "shaders/v3f-t2f-c4f.vert";
const char* sjg_string14 = "shaders/v3f-t2f-c4f.frag";
const char* sjg_string15 = "vertex:3f,tex_coord:2f,normal:3f";
const char* sjg_string16 = "assets/forest_backdrop.png";
const char* sjg_string18 = "leaf";
const char* sjg_string19 = "assets/whitestar1.png";
const char* sjg_string2 = "shaders/v3f-c4f.frag";
const char* sjg_string20 = "assets/whitestar2.png";
const char* sjg_string21 = "assets/whitestar1.png";
const char* sjg_string22 = "assets/whitestar2.png";
const char* sjg_string23 = "assets/whitestar1.png";
const char* sjg_string24 = "assets/whitestar2.png";
const char* sjg_string25 = "assets/whitestar1.png";
const char* sjg_string26 = "assets/whitestar2.png";
const char* sjg_string27 = "Framebuffer failed";
const char* sjg_string28 = "Framebuffer failed";
const char* sjg_string29 = "assets/forestperson1.png";
const char* sjg_string3 = "shaders/v3f-t2f-c4f.vert";
const char* sjg_string30 = "assets/forestperson2.png";
const char* sjg_string31 = "grass6.2";
const char* sjg_string32 = "assets/grass.png";
const char* sjg_string33 = "grass6.2";
const char* sjg_string34 = "assets/grass.png";
const char* sjg_string35 = "grass4.2";
const char* sjg_string36 = "assets/grass.png";
const char* sjg_string37 = "grass4.2";
const char* sjg_string38 = "assets/grass.png";
const char* sjg_string39 = "grass2.2";
const char* sjg_string4 = "shaders/blur-horizontal.frag";
const char* sjg_string40 = "assets/grass.png";
const char* sjg_string41 = "grass2.2";
const char* sjg_string42 = "assets/grass.png";
const char* sjg_string43 = "grass0.2";
const char* sjg_string44 = "assets/grass.png";
const char* sjg_string45 = "grass0.2";
const char* sjg_string46 = "assets/grass.png";
const char* sjg_string47 = "grass-1.8";
const char* sjg_string48 = "assets/grass.png";
const char* sjg_string49 = "grass-1.8";
const char* sjg_string5 = "shaders/v3f-t2f-c4f.vert";
const char* sjg_string50 = "assets/grass.png";
const char* sjg_string6 = "shaders/blur-vertical.frag";
const char* sjg_string7 = "shaders/v3f-t2f.vert";
const char* sjg_string8 = "shaders/v3f-t2f.frag";
const char* sjg_string9 = "shaders/v3f-n3f-phong.vert";
const char* sjg_string97 = "release";
const char* sjg_string98 = "release done";

/* The MIT License
Copyright (c) 2008, by Attractive Chaos <attractivechaos@aol.co.uk>
Permission is hereby granted, free of charge, to any person obtaining
a copy of this software and associated documentation files (the
"Software"), to deal in the Software without restriction, including
without limitation the rights to use, copy, modify, merge, publish,
distribute, sublicense, and/or sell copies of the Software, and to
permit persons to whom the Software is furnished to do so, subject to
the following conditions:
The above copyright notice and this permission notice shall be
included in all copies or substantial portions of the Software.
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/
/*
An example:
#include "khash.h"
KHASH_MAP_INIT_INT(32, char)
int main() {
    int ret, is_missing;
    khiter_t k;
    khash_t(32) *h = kh_init(32);
    k = kh_put(32, h, 5, &ret);
    if (!ret) kh_del(32, h, k);
    kh_value(h, k) = 10;
    k = kh_get(32, h, 10);
    is_missing = (k == kh_end(h));
    k = kh_get(32, h, 5);
    kh_del(32, h, k);
    for (k = kh_begin(h); k != kh_end(h); ++k)
    if (kh_exist(h, k)) kh_value(h, k) = 1;
    kh_destroy(32, h);
    return 0;
}
*/
/*
2008-09-19 (0.2.3):
* Corrected the example
* Improved interfaces
2008-09-11 (0.2.2):
* Improved speed a little in kh_put()
2008-09-10 (0.2.1):
* Added kh_clear()
* Fixed a compiling error
2008-09-02 (0.2.0):
* Changed to token concatenation which increases flexibility.
2008-08-31 (0.1.2):
* Fixed a bug in kh_get(), which has not been tested previously.
2008-08-31 (0.1.1):
* Added destructor
*/
#ifndef __AC_KHASH_H
#define __AC_KHASH_H
#define AC_VERSION_KHASH_H "0.2.2"
typedef uint32_t khint_t;
typedef khint_t khiter_t;
#define __ac_HASH_PRIME_SIZE 32
static const uint32_t __ac_prime_list[__ac_HASH_PRIME_SIZE] =
{
    0ul,          3ul,          11ul,         23ul,         53ul,
    97ul,         193ul,        389ul,        769ul,        1543ul,
    3079ul,       6151ul,       12289ul,      24593ul,      49157ul,
    98317ul,      196613ul,     393241ul,     786433ul,     1572869ul,
    3145739ul,    6291469ul,    12582917ul,   25165843ul,   50331653ul,
    100663319ul,  201326611ul,  402653189ul,  805306457ul,  1610612741ul,
    3221225473ul, 4294967291ul
};
#define __ac_isempty(flag, i) ((flag[i>>4]>>((i&0xfU)<<1))&2)
#define __ac_isdel(flag, i) ((flag[i>>4]>>((i&0xfU)<<1))&1)
#define __ac_iseither(flag, i) ((flag[i>>4]>>((i&0xfU)<<1))&3)
#define __ac_set_isdel_false(flag, i) (flag[i>>4]&=~(1ul<<((i&0xfU)<<1)))
#define __ac_set_isempty_false(flag, i) (flag[i>>4]&=~(2ul<<((i&0xfU)<<1)))
#define __ac_set_isboth_false(flag, i) (flag[i>>4]&=~(3ul<<((i&0xfU)<<1)))
#define __ac_set_isdel_true(flag, i) (flag[i>>4]|=1ul<<((i&0xfU)<<1))
static const double __ac_HASH_UPPER = 0.77;
#define KHASH_INIT_TYPEDEF(name, khkey_t, khval_t) \
typedef struct {                                                    \
khint_t n_buckets, size, n_occupied, upper_bound;               \
uint32_t *flags;                                                \
khkey_t *keys;                                                  \
khval_t *vals;                                                  \
} kh_##name##_t;                                                
#define KHASH_INIT_FUNCTION(name, khkey_t, khval_t, kh_is_map, __hash_func, __hash_equal) \
static inline kh_##name##_t *kh_init_##name() {                     \
return (kh_##name##_t*)calloc(1, sizeof(kh_##name##_t));        \
}                                                                   \
static inline void kh_destroy_##name(kh_##name##_t *h)              \
{                                                                   \
if (h) {                                                        \
free(h->keys); free(h->flags);                              \
free(h->vals);                                              \
free(h);                                                    \
}                                                               \
}                                                                   \
static inline void kh_clear_##name(kh_##name##_t *h)                \
{                                                                   \
if (h && h->flags) { \
memset(h->flags, 0xaa, ((h->n_buckets>>4) + 1) * sizeof(uint32_t)); \
h->size = h->n_occupied = 0;                                \
}                                                               \
}                                                                   \
static inline khint_t kh_get_##name(kh_##name##_t *h, khkey_t key)  \
{                                                                   \
if (h->n_buckets) {                                             \
khint_t inc, k, i, last;                                    \
__hash_func(key, &k); i = k % h->n_buckets;        \
inc = 1 + k % (h->n_buckets - 1); last = i;                 \
bool shouldContinue = false;                                \
if (!__ac_isempty(h->flags, i)) {                           \
bool isEqual;                                           \
__hash_equal(h->keys[i], key, &isEqual);  \
shouldContinue = __ac_isdel(h->flags, i) || !isEqual;   \
}                                                           \
while (shouldContinue) {                                    \
if (i + inc >= h->n_buckets) i = i + inc - h->n_buckets; \
else i += inc;                                          \
if (i == last) return h->n_buckets;                     \
shouldContinue = false;                                 \
if (!__ac_isempty(h->flags, i)) {                       \
bool isEqual;                                       \
__hash_equal(h->keys[i], key, &isEqual);  \
shouldContinue = __ac_isdel(h->flags, i) || !isEqual; \
}                                                       \
}                                                           \
return __ac_iseither(h->flags, i)? h->n_buckets : i;        \
} else return 0;                                                \
}                                                                   \
static inline void kh_resize_##name(kh_##name##_t *h, khint_t new_n_buckets) \
{                                                                   \
uint32_t *new_flags = 0;                                        \
khint_t j = 1;                                                  \
{                                                               \
khint_t t = __ac_HASH_PRIME_SIZE - 1;                       \
while (__ac_prime_list[t] > new_n_buckets) --t;             \
new_n_buckets = __ac_prime_list[t+1];                       \
if (h->size >= (khint_t)(new_n_buckets * __ac_HASH_UPPER + 0.5)) j = 0; \
else {                                                      \
new_flags = (uint32_t*)malloc(((new_n_buckets>>4) + 1) * sizeof(uint32_t)); \
memset(new_flags, 0xaa, ((new_n_buckets>>4) + 1) * sizeof(uint32_t)); \
if (h->n_buckets < new_n_buckets) {                     \
h->keys = (khkey_t*)realloc(h->keys, new_n_buckets * sizeof(khkey_t)); \
if (kh_is_map)                                      \
h->vals = (khval_t*)realloc(h->vals, new_n_buckets * sizeof(khval_t)); \
}                                                       \
}                                                           \
}                                                               \
if (j) {                                                        \
for (j = 0; j != h->n_buckets; ++j) {                       \
if (__ac_iseither(h->flags, j) == 0) {                  \
khkey_t key = h->keys[j];                           \
khval_t val;                                        \
if (kh_is_map) val = h->vals[j];                    \
__ac_set_isdel_true(h->flags, j);                   \
while (1) {                                         \
khint_t inc, k, i;                              \
__hash_func(key, &k);                           \
i = k % new_n_buckets;                          \
inc = 1 + k % (new_n_buckets - 1);              \
while (!__ac_isempty(new_flags, i)) {           \
if (i + inc >= new_n_buckets) i = i + inc - new_n_buckets; \
else i += inc;                              \
}                                               \
__ac_set_isempty_false(new_flags, i);           \
if (i < h->n_buckets && __ac_iseither(h->flags, i) == 0) { \
{ khkey_t tmp = h->keys[i]; h->keys[i] = key; key = tmp; } \
if (kh_is_map) { khval_t tmp = h->vals[i]; h->vals[i] = val; val = tmp; } \
__ac_set_isdel_true(h->flags, i);           \
} else {                                        \
h->keys[i] = key;                           \
if (kh_is_map) h->vals[i] = val;            \
break;                                      \
}                                               \
}                                                   \
}                                                       \
}                                                           \
if (h->n_buckets > new_n_buckets) {                         \
h->keys = (khkey_t*)realloc(h->keys, new_n_buckets * sizeof(khkey_t)); \
if (kh_is_map)                                          \
h->vals = (khval_t*)realloc(h->vals, new_n_buckets * sizeof(khval_t)); \
}                                                           \
free(h->flags);                                             \
h->flags = new_flags;                                       \
h->n_buckets = new_n_buckets;                               \
h->n_occupied = h->size;                                    \
h->upper_bound = (khint_t)(h->n_buckets * __ac_HASH_UPPER + 0.5); \
}                                                               \
}                                                                   \
static inline khint_t kh_put_##name(kh_##name##_t *h, khkey_t key, int *ret) \
{                                                                   \
khint_t x;                                                      \
if (h->n_occupied >= h->upper_bound) {                          \
if (h->n_buckets > (h->size<<1)) kh_resize_##name(h, h->n_buckets - 1); \
else kh_resize_##name(h, h->n_buckets + 1);                 \
}                                                               \
{                                                               \
khint_t inc, k, i, site, last;                              \
x = site = h->n_buckets; __hash_func(key, &k); i = k % h->n_buckets; \
if (__ac_isempty(h->flags, i)) x = i;                       \
else {                                                      \
inc = 1 + k % (h->n_buckets - 1); last = i;             \
bool shouldContinue = false;                                \
if (!__ac_isempty(h->flags, i)) {                           \
bool isEqual;                                           \
__hash_equal(h->keys[i], key, &isEqual);  \
shouldContinue = __ac_isdel(h->flags, i) || !isEqual;   \
}                                                           \
while (shouldContinue) { \
if (__ac_isdel(h->flags, i)) site = i;              \
if (i + inc >= h->n_buckets) i = i + inc - h->n_buckets; \
else i += inc;                                      \
if (i == last) { x = site; break; }                 \
shouldContinue = false;                             \
if (!__ac_isempty(h->flags, i)) {                           \
bool isEqual;                                           \
__hash_equal(h->keys[i], key, &isEqual);  \
shouldContinue = __ac_isdel(h->flags, i) || !isEqual;   \
}                                                           \
}                                                       \
if (x == h->n_buckets) {                                \
if (__ac_isempty(h->flags, i) && site != h->n_buckets) x = site; \
else x = i;                                         \
}                                                       \
}                                                           \
}                                                               \
if (__ac_isempty(h->flags, x)) {                                \
h->keys[x] = key;                                           \
__ac_set_isboth_false(h->flags, x);                         \
++h->size; ++h->n_occupied;                                 \
*ret = 1;                                                   \
} else if (__ac_isdel(h->flags, x)) {                           \
h->keys[x] = key;                                           \
__ac_set_isboth_false(h->flags, x);                         \
++h->size;                                                  \
*ret = 2;                                                   \
} else *ret = 0;                                                \
return x;                                                       \
}                                                                   \
static inline void kh_del_##name(kh_##name##_t *h, khint_t x)       \
{                                                                   \
if (x != h->n_buckets && !__ac_iseither(h->flags, x)) {         \
__ac_set_isdel_true(h->flags, x);                           \
--h->size;                                                  \
}                                                               \
}
#define KHASH_INIT_FUNCTION_DEREF(name, khkey_t, khval_t, kh_is_map, __hash_func, __hash_equal) \
static inline kh_##name##_t *kh_init_##name() {                     \
return (kh_##name##_t*)calloc(1, sizeof(kh_##name##_t));        \
}                                                                   \
static inline void kh_destroy_##name(kh_##name##_t *h)              \
{                                                                   \
if (h) {                                                        \
free(h->keys); free(h->flags);                              \
free(h->vals);                                              \
free(h);                                                    \
}                                                               \
}                                                                   \
static inline void kh_clear_##name(kh_##name##_t *h)                \
{                                                                   \
if (h && h->flags) { \
memset(h->flags, 0xaa, ((h->n_buckets>>4) + 1) * sizeof(uint32_t)); \
h->size = h->n_occupied = 0;                                \
}                                                               \
}                                                                   \
static inline khint_t kh_get_##name(kh_##name##_t *h, khkey_t key)  \
{                                                                   \
if (h->n_buckets) {                                             \
khint_t inc, k, i, last;                                    \
__hash_func(&key, &k); i = k % h->n_buckets;        \
inc = 1 + k % (h->n_buckets - 1); last = i;                 \
bool shouldContinue = false;                                \
if (!__ac_isempty(h->flags, i)) {                           \
bool isEqual;                                           \
__hash_equal(&h->keys[i], &key, &isEqual);  \
shouldContinue = __ac_isdel(h->flags, i) || !isEqual;   \
}                                                           \
while (shouldContinue) {                                    \
if (i + inc >= h->n_buckets) i = i + inc - h->n_buckets; \
else i += inc;                                          \
if (i == last) return h->n_buckets;                     \
shouldContinue = false;                                 \
if (!__ac_isempty(h->flags, i)) {                       \
bool isEqual;                                       \
__hash_equal(&h->keys[i], &key, &isEqual);  \
shouldContinue = __ac_isdel(h->flags, i) || !isEqual; \
}                                                       \
}                                                           \
return __ac_iseither(h->flags, i)? h->n_buckets : i;        \
} else return 0;                                                \
}                                                                   \
static inline void kh_resize_##name(kh_##name##_t *h, khint_t new_n_buckets) \
{                                                                   \
uint32_t *new_flags = 0;                                        \
khint_t j = 1;                                                  \
{                                                               \
khint_t t = __ac_HASH_PRIME_SIZE - 1;                       \
while (__ac_prime_list[t] > new_n_buckets) --t;             \
new_n_buckets = __ac_prime_list[t+1];                       \
if (h->size >= (khint_t)(new_n_buckets * __ac_HASH_UPPER + 0.5)) j = 0; \
else {                                                      \
new_flags = (uint32_t*)malloc(((new_n_buckets>>4) + 1) * sizeof(uint32_t)); \
memset(new_flags, 0xaa, ((new_n_buckets>>4) + 1) * sizeof(uint32_t)); \
if (h->n_buckets < new_n_buckets) {                     \
h->keys = (khkey_t*)realloc(h->keys, new_n_buckets * sizeof(khkey_t)); \
if (kh_is_map)                                      \
h->vals = (khval_t*)realloc(h->vals, new_n_buckets * sizeof(khval_t)); \
}                                                       \
}                                                           \
}                                                               \
if (j) {                                                        \
for (j = 0; j != h->n_buckets; ++j) {                       \
if (__ac_iseither(h->flags, j) == 0) {                  \
khkey_t key = h->keys[j];                           \
khval_t val;                                        \
if (kh_is_map) val = h->vals[j];                    \
__ac_set_isdel_true(h->flags, j);                   \
while (1) {                                         \
khint_t inc, k, i;                              \
__hash_func(&key, &k);                           \
i = k % new_n_buckets;                          \
inc = 1 + k % (new_n_buckets - 1);              \
while (!__ac_isempty(new_flags, i)) {           \
if (i + inc >= new_n_buckets) i = i + inc - new_n_buckets; \
else i += inc;                              \
}                                               \
__ac_set_isempty_false(new_flags, i);           \
if (i < h->n_buckets && __ac_iseither(h->flags, i) == 0) { \
{ khkey_t tmp = h->keys[i]; h->keys[i] = key; key = tmp; } \
if (kh_is_map) { khval_t tmp = h->vals[i]; h->vals[i] = val; val = tmp; } \
__ac_set_isdel_true(h->flags, i);           \
} else {                                        \
h->keys[i] = key;                           \
if (kh_is_map) h->vals[i] = val;            \
break;                                      \
}                                               \
}                                                   \
}                                                       \
}                                                           \
if (h->n_buckets > new_n_buckets) {                         \
h->keys = (khkey_t*)realloc(h->keys, new_n_buckets * sizeof(khkey_t)); \
if (kh_is_map)                                          \
h->vals = (khval_t*)realloc(h->vals, new_n_buckets * sizeof(khval_t)); \
}                                                           \
free(h->flags);                                             \
h->flags = new_flags;                                       \
h->n_buckets = new_n_buckets;                               \
h->n_occupied = h->size;                                    \
h->upper_bound = (khint_t)(h->n_buckets * __ac_HASH_UPPER + 0.5); \
}                                                               \
}                                                                   \
static inline khint_t kh_put_##name(kh_##name##_t *h, khkey_t key, int *ret) \
{                                                                   \
khint_t x;                                                      \
if (h->n_occupied >= h->upper_bound) {                          \
if (h->n_buckets > (h->size<<1)) kh_resize_##name(h, h->n_buckets - 1); \
else kh_resize_##name(h, h->n_buckets + 1);                 \
}                                                               \
{                                                               \
khint_t inc, k, i, site, last;                              \
x = site = h->n_buckets; __hash_func(&key, &k); i = k % h->n_buckets; \
if (__ac_isempty(h->flags, i)) x = i;                       \
else {                                                      \
inc = 1 + k % (h->n_buckets - 1); last = i;             \
bool shouldContinue = false;                                \
if (!__ac_isempty(h->flags, i)) {                           \
bool isEqual;                                           \
__hash_equal(&h->keys[i], &key, &isEqual);  \
shouldContinue = __ac_isdel(h->flags, i) || !isEqual;   \
}                                                           \
while (shouldContinue) { \
if (__ac_isdel(h->flags, i)) site = i;              \
if (i + inc >= h->n_buckets) i = i + inc - h->n_buckets; \
else i += inc;                                      \
if (i == last) { x = site; break; }                 \
shouldContinue = false;                             \
if (!__ac_isempty(h->flags, i)) {                           \
bool isEqual;                                           \
__hash_equal(&h->keys[i], &key, &isEqual);  \
shouldContinue = __ac_isdel(h->flags, i) || !isEqual;   \
}                                                           \
}                                                       \
if (x == h->n_buckets) {                                \
if (__ac_isempty(h->flags, i) && site != h->n_buckets) x = site; \
else x = i;                                         \
}                                                       \
}                                                           \
}                                                               \
if (__ac_isempty(h->flags, x)) {                                \
h->keys[x] = key;                                           \
__ac_set_isboth_false(h->flags, x);                         \
++h->size; ++h->n_occupied;                                 \
*ret = 1;                                                   \
} else if (__ac_isdel(h->flags, x)) {                           \
h->keys[x] = key;                                           \
__ac_set_isboth_false(h->flags, x);                         \
++h->size;                                                  \
*ret = 2;                                                   \
} else *ret = 0;                                                \
return x;                                                       \
}                                                                   \
static inline void kh_del_##name(kh_##name##_t *h, khint_t x)       \
{                                                                   \
if (x != h->n_buckets && !__ac_iseither(h->flags, x)) {         \
__ac_set_isdel_true(h->flags, x);                           \
--h->size;                                                  \
}                                                               \
}
/* --- BEGIN OF HASH FUNCTIONS --- */
#define kh_int_hash_func(key) (uint32_t)(key)
#define kh_int_hash_equal(a, b) (a == b)
#define kh_int64_hash_func(key) (uint32_t)((key)>>33^(key)^(key)<<11)
#define kh_int64_hash_equal(a, b) (a == b)
static inline khint_t __ac_X31_hash_string(const char *s)
{
khint_t h = *s;
if (h) for (++s; *s; ++s) h = (h << 5) - h + *s;
return h;
}
#define kh_str_hash_func(key) __ac_X31_hash_string(key)
#define kh_str_hash_equal(a, b) (strcmp(a, b) == 0)
/* --- END OF HASH FUNCTIONS --- */
/* Other necessary macros... */
#define khash_t(name) kh_##name##_t
#define kh_init(name) kh_init_##name()
#define kh_destroy(name, h) kh_destroy_##name(h)
#define kh_clear(name, h) kh_clear_##name(h)
#define kh_resize(name, h, s) kh_resize_##name(h, s)
#define kh_put(name, h, k, r) kh_put_##name(h, k, r)
#define kh_get(name, h, k) kh_get_##name(h, k)
#define kh_del(name, h, k) kh_del_##name(h, k)
#define kh_exist(h, x) (!__ac_iseither((h)->flags, (x)))
#define kh_key(h, x) ((h)->keys[x])
#define kh_val(h, x) ((h)->vals[x])
#define kh_value(h, x) ((h)->vals[x])
#define kh_begin(h) (khint_t)(0)
#define kh_end(h) ((h)->n_buckets)
#define kh_size(h) ((h)->size)
#define kh_n_buckets(h) ((h)->n_buckets)
/* More conenient interfaces */
#define KHASH_SET_INIT_INT(name)                                        \
KHASH_INIT(name, uint32_t, char, 0, kh_int_hash_func, kh_int_hash_equal)
#define KHASH_MAP_INIT_INT(name, khval_t)                               \
KHASH_INIT(name, uint32_t, khval_t, 1, kh_int_hash_func, kh_int_hash_equal)
#define KHASH_SET_INIT_INT64(name)                                      \
KHASH_INIT(name, uint64_t, char, 0, kh_int64_hash_func, kh_int64_hash_equal)
#define KHASH_MAP_INIT_INT64(name, khval_t)                             \
KHASH_INIT(name, uint64_t, khval_t, 1, kh_int64_hash_func, kh_int64_hash_equal)
typedef const char *kh_cstr_t;
#define KHASH_SET_INIT_STR(name)                                        \
KHASH_INIT(name, kh_cstr_t, char, 0, kh_str_hash_func, kh_str_hash_equal)
#define KHASH_MAP_INIT_STR(name, khval_t)                               \
KHASH_INIT(name, kh_cstr_t, khval_t, 1, kh_str_hash_func, kh_str_hash_equal)
#endif /* __AC_KHASH_H */
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
#define sjs_size_typeId 4
#define sjs_mat4_typeId 5
#define sjs_scene2d_typeId 6
#define sjs_array_char_typeId 7
#define sjs_string_typeId 8
#define sjs_rect_typeId 9
#define sjs_vec3_typeId 10
#define sjs_color_typeId 11
#define sjs_light_typeId 12
#define sji_model_typeId 13
#define sjs_array_local_iface_model_typeId 14
#define sjs_list_local_iface_model_typeId 15
#define sjs_point_typeId 16
#define sjs_mouseevent_typeId 17
#define sji_model_vtbl_typeId 18
#define sjs_hash_string_weak_iface_model_typeId 19
#define sji_element_vtbl_typeId 20
#define sji_element_typeId 21
#define sjs_hash_string_weak_iface_element_typeId 22
#define sjs_array_local_iface_animation_typeId 23
#define sjs_list_local_iface_animation_typeId 24
#define sjs_anon1_typeId 25
#define sji_animation_vtbl_typeId 26
#define sji_animation_typeId 27
#define sjs_anon2_typeId 28
#define sjs_anon3_typeId 29
#define sjs_anon4_typeId 30
#define sjs_shader_typeId 31
#define sjs_anon5_typeId 32
#define sjs_array_heap_iface_element_typeId 33
#define sjs_fillelement_typeId 34
#define sjs_array_heap_iface_model_typeId 35
#define sjs_nauscene3delement_typeId 36
#define cb_local_iface_model_local_iface_model_i32_typeId 37
#define cb_local_iface_model_local_iface_model_i32_heap_typeId 38
#define sjs_array_i32_typeId 39
#define sjs_array_vertex_location_texture_normal_typeId 40
#define sjs_vertexbuffer_vertex_location_texture_normal_typeId 41
#define sjs_texture_typeId 42
#define sjs_model_typeId 43
#define sjs_vec4_typeId 44
#define sjs_vec2_typeId 45
#define sjs_vertex_location_texture_normal_typeId 46
#define sjs_array_texture_typeId 47
#define sjs_leafpanel_typeId 48
#define cb_texture_heap_iface_model_typeId 49
#define cb_texture_heap_iface_model_heap_typeId 50
#define sjs_array_mat4_typeId 51
#define sjs_peoplepanel_typeId 52
#define cb_heap_iface_model_mat4_typeId 53
#define cb_heap_iface_model_mat4_heap_typeId 54
#define cb_local_iface_model_mat4_heap_mat4_typeId 55
#define cb_local_iface_model_mat4_heap_mat4_heap_typeId 56
#define sjs_framebuffer_typeId 57
#define sjs_renderbuffer_typeId 58
#define sjs_scene2dmodel_typeId 59
#define sjs_boxrenderer_typeId 60
#define sjs_boxelement_typeId 61
#define sjs_margin_typeId 62
#define sjs_image_typeId 63
#define sjs_imagerenderer_typeId 64
#define sjs_imageelement_typeId 65
#define sjs_crosshairselement_typeId 66
#define sjs_panel3d_typeId 67

typedef struct td_sjs_object sjs_object;
typedef struct td_sjs_interface sjs_interface;
typedef struct td_sjs_windowrenderer sjs_windowrenderer;
typedef struct td_sjs_size sjs_size;
typedef struct td_sjs_mat4 sjs_mat4;
typedef struct td_sjs_scene2d sjs_scene2d;
typedef struct td_sjs_array_char sjs_array_char;
typedef struct td_sjs_string sjs_string;
typedef struct td_sjs_rect sjs_rect;
typedef struct td_sjs_vec3 sjs_vec3;
typedef struct td_sjs_color sjs_color;
typedef struct td_sjs_light sjs_light;
typedef struct td_sji_model sji_model;
typedef struct td_sjs_array_local_iface_model sjs_array_local_iface_model;
typedef struct td_sjs_list_local_iface_model sjs_list_local_iface_model;
typedef struct td_sjs_point sjs_point;
typedef struct td_sjs_mouseevent sjs_mouseevent;
typedef struct td_sji_model_vtbl sji_model_vtbl;
typedef struct td_sjs_hash_string_weak_iface_model sjs_hash_string_weak_iface_model;
typedef struct td_sji_element_vtbl sji_element_vtbl;
typedef struct td_sji_element sji_element;
typedef struct td_sjs_hash_string_weak_iface_element sjs_hash_string_weak_iface_element;
typedef struct td_sjs_array_local_iface_animation sjs_array_local_iface_animation;
typedef struct td_sjs_list_local_iface_animation sjs_list_local_iface_animation;
typedef struct td_sjs_anon1 sjs_anon1;
typedef struct td_sji_animation_vtbl sji_animation_vtbl;
typedef struct td_sji_animation sji_animation;
typedef struct td_sjs_anon2 sjs_anon2;
typedef struct td_sjs_anon3 sjs_anon3;
typedef struct td_sjs_anon4 sjs_anon4;
typedef struct td_sjs_shader sjs_shader;
typedef struct td_sjs_anon5 sjs_anon5;
typedef struct td_sjs_array_heap_iface_element sjs_array_heap_iface_element;
typedef struct td_sjs_fillelement sjs_fillelement;
typedef struct td_sjs_array_heap_iface_model sjs_array_heap_iface_model;
typedef struct td_sjs_nauscene3delement sjs_nauscene3delement;
typedef struct td_cb_local_iface_model_local_iface_model_i32 cb_local_iface_model_local_iface_model_i32;
typedef struct td_cb_local_iface_model_local_iface_model_i32_heap cb_local_iface_model_local_iface_model_i32_heap;
typedef struct td_sjs_array_i32 sjs_array_i32;
typedef struct td_sjs_array_vertex_location_texture_normal sjs_array_vertex_location_texture_normal;
typedef struct td_sjs_vertexbuffer_vertex_location_texture_normal sjs_vertexbuffer_vertex_location_texture_normal;
typedef struct td_sjs_texture sjs_texture;
typedef struct td_sjs_model sjs_model;
typedef struct td_sjs_vec4 sjs_vec4;
typedef struct td_sjs_vec2 sjs_vec2;
typedef struct td_sjs_vertex_location_texture_normal sjs_vertex_location_texture_normal;
typedef struct td_sjs_array_texture sjs_array_texture;
typedef struct td_sjs_leafpanel sjs_leafpanel;
typedef struct td_cb_texture_heap_iface_model cb_texture_heap_iface_model;
typedef struct td_cb_texture_heap_iface_model_heap cb_texture_heap_iface_model_heap;
typedef struct td_sjs_array_mat4 sjs_array_mat4;
typedef struct td_sjs_peoplepanel sjs_peoplepanel;
typedef struct td_cb_heap_iface_model_mat4 cb_heap_iface_model_mat4;
typedef struct td_cb_heap_iface_model_mat4_heap cb_heap_iface_model_mat4_heap;
typedef struct td_cb_local_iface_model_mat4_heap_mat4 cb_local_iface_model_mat4_heap_mat4;
typedef struct td_cb_local_iface_model_mat4_heap_mat4_heap cb_local_iface_model_mat4_heap_mat4_heap;
typedef struct td_sjs_framebuffer sjs_framebuffer;
typedef struct td_sjs_renderbuffer sjs_renderbuffer;
typedef struct td_sjs_scene2dmodel sjs_scene2dmodel;
typedef struct td_sjs_boxrenderer sjs_boxrenderer;
typedef struct td_sjs_boxelement sjs_boxelement;
typedef struct td_sjs_margin sjs_margin;
typedef struct td_sjs_image sjs_image;
typedef struct td_sjs_imagerenderer sjs_imagerenderer;
typedef struct td_sjs_imageelement sjs_imageelement;
typedef struct td_sjs_crosshairselement sjs_crosshairselement;
typedef struct td_sjs_panel3d sjs_panel3d;

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

struct td_sjs_scene2d {
    int _refCount;
    sjs_size _size;
    sjs_mat4 model;
    sjs_mat4 view;
    sjs_mat4 projection;
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

struct td_sjs_rect {
    int _refCount;
    int32_t x;
    int32_t y;
    int32_t w;
    int32_t h;
};

struct td_sjs_vec3 {
    int _refCount;
    float x;
    float y;
    float z;
};

struct td_sjs_color {
    int _refCount;
    float r;
    float g;
    float b;
    float a;
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

struct td_sjs_array_local_iface_model {
    int _refCount;
    int32_t datasize;
    void* data;
    bool _isglobal;
    int32_t count;
};

struct td_sjs_list_local_iface_model {
    int _refCount;
    sjs_array_local_iface_model array;
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
    void (*renderorqueue)(sjs_object* _parent, sjs_list_local_iface_model* zqueue);
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
    void (*firemouseevent)(sjs_object* _parent, sjs_mouseevent* mouseevent);
};

struct td_sji_element {
    sjs_object* _parent;
    sji_element_vtbl* _vtbl;
};

struct td_sjs_hash_string_weak_iface_element {
    int _refCount;
    void* _hash;
};

struct td_sjs_array_local_iface_animation {
    int _refCount;
    int32_t datasize;
    void* data;
    bool _isglobal;
    int32_t count;
};

struct td_sjs_list_local_iface_animation {
    int _refCount;
    sjs_array_local_iface_animation array;
};

struct td_sjs_anon1 {
    int _refCount;
    sjs_list_local_iface_animation animations;
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

struct td_sjs_anon2 {
    int _refCount;
    int32_t fill;
    int32_t left;
    int32_t right;
    int32_t top;
    int32_t bottom;
};

struct td_sjs_anon3 {
    int _refCount;
    int32_t normal;
    int32_t hot;
    int32_t pressed;
};

struct td_sjs_anon4 {
    int _refCount;
};

struct td_sjs_shader {
    int _refCount;
    sjs_string vertex;
    sjs_string pixel;
    GLuint id;
};

struct td_sjs_anon5 {
    int _refCount;
};

struct td_sjs_array_heap_iface_element {
    int _refCount;
    int32_t datasize;
    void* data;
    bool _isglobal;
    int32_t count;
};

struct td_sjs_fillelement {
    int _refCount;
    sjs_array_heap_iface_element children;
    sjs_rect _rect;
};

struct td_sjs_array_heap_iface_model {
    int _refCount;
    int32_t datasize;
    void* data;
    bool _isglobal;
    int32_t count;
};

struct td_sjs_nauscene3delement {
    int _refCount;
    sjs_array_heap_iface_model children;
    sjs_vec3 lookatmin;
    sjs_vec3 lookatmax;
    float fieldofview;
    float znear;
    float zfar;
    sjs_light light;
    sjs_mat4 projection;
    sjs_mat4 view;
    sjs_mat4 world;
    sjs_rect _rect;
    bool _isdragging;
    sjs_point _startdrag;
    sjs_vec3 _lookat;
    sjs_vec3 _lookatdrag;
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
    bool _isglobal;
    int32_t count;
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

struct td_sjs_vec4 {
    int _refCount;
    float x;
    float y;
    float z;
    float w;
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

struct td_sjs_array_texture {
    int _refCount;
    int32_t datasize;
    void* data;
    bool _isglobal;
    int32_t count;
};

struct td_sjs_leafpanel {
    int _refCount;
    sjs_array_texture textures;
    sjs_array_heap_iface_model children;
    float _angle;
};

struct td_cb_texture_heap_iface_model {
    sjs_object* _parent;
    void (*_cb_heap)(sjs_object* _parent, sjs_texture*, sji_model* _return);
};

struct td_cb_texture_heap_iface_model_heap {
    cb_texture_heap_iface_model inner;
    void (*_destroy)(sjs_object*);
};

struct td_sjs_array_mat4 {
    int _refCount;
    int32_t datasize;
    void* data;
    bool _isglobal;
    int32_t count;
};

struct td_sjs_peoplepanel {
    int _refCount;
    sjs_mat4 model;
    sjs_array_heap_iface_model children;
    sjs_array_mat4 _childrenmodel;
    int32_t _index;
    int32_t _depth;
    float _xincrement;
    float _zincrement;
    float _xoffset;
};

struct td_cb_heap_iface_model_mat4 {
    sjs_object* _parent;
    void (*_cb)(sjs_object* _parent, sji_model, sjs_mat4* _return);
};

struct td_cb_heap_iface_model_mat4_heap {
    cb_heap_iface_model_mat4 inner;
    void (*_destroy)(sjs_object*);
};

struct td_cb_local_iface_model_mat4_heap_mat4 {
    sjs_object* _parent;
    void (*_cb)(sjs_object* _parent, sji_model, sjs_mat4* _return);
    void (*_cb_heap)(sjs_object* _parent, sji_model, sjs_mat4** _return);
};

struct td_cb_local_iface_model_mat4_heap_mat4_heap {
    cb_local_iface_model_mat4_heap_mat4 inner;
    void (*_destroy)(sjs_object*);
};

struct td_sjs_framebuffer {
    int _refCount;
    uint32_t id;
};

struct td_sjs_renderbuffer {
    int _refCount;
    sjs_size size;
    uint32_t id;
};

struct td_sjs_scene2dmodel {
    int _refCount;
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

struct td_sjs_margin {
    int _refCount;
    int32_t l;
    int32_t t;
    int32_t r;
    int32_t b;
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
    sjs_rect _rect;
    sjs_margin _margin;
    sjs_imagerenderer _imagerenderer;
};

struct td_sjs_crosshairselement {
    int _refCount;
    sjs_color color;
    sjs_rect _rect;
    sjs_boxrenderer _topdownrenderer;
    sjs_boxrenderer _leftrightrenderer;
    sjs_point _point;
};

struct td_sjs_panel3d {
    int _refCount;
    sjs_mat4 model;
    sjs_array_heap_iface_model children;
};

sji_element_vtbl sjs_boxelement_element_vtbl;
sji_element_vtbl sjs_crosshairselement_element_vtbl;
sji_element_vtbl sjs_fillelement_element_vtbl;
sji_element_vtbl sjs_imageelement_element_vtbl;
sji_model_vtbl sjs_leafpanel_model_vtbl;
sji_model_vtbl sjs_model_model_vtbl;
sji_element_vtbl sjs_nauscene3delement_element_vtbl;
sji_model_vtbl sjs_panel3d_model_vtbl;
sji_model_vtbl sjs_peoplepanel_model_vtbl;
sji_model_vtbl sjs_scene2dmodel_model_vtbl;
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
int32_t result1;
float result13;
float result14;
float result24;
float result25;
float result29;
float result30;
float result31;
float result32;
float result33;
float result34;
float result35;
float result36;
float result37;
float result38;
float result39;
float result40;
float result41;
float result42;
float result43;
float result44;
float result45;
float result46;
float result47;
float result48;
float result49;
float result50;
float result51;
float result52;
float result53;
float result54;
float result55;
float result56;
float result57;
float result58;
float result59;
float result60;
float result61;
sjs_fillelement sjt_call1 = { -1 };
sjs_mat4 sjt_call100 = { -1 };
sjs_model* sjt_call101 = 0;
sjs_string sjt_call102 = { -1 };
sjs_mat4 sjt_call103 = { -1 };
sjs_mat4 sjt_call104 = { -1 };
sjs_model* sjt_call105 = 0;
sjs_string sjt_call106 = { -1 };
sjs_mat4 sjt_call107 = { -1 };
sjs_mat4 sjt_call108 = { -1 };
sjs_model* sjt_call109 = 0;
sjs_string sjt_call110 = { -1 };
sjs_mat4 sjt_call111 = { -1 };
sjs_mat4 sjt_call112 = { -1 };
sjs_model* sjt_call113 = 0;
sjs_string sjt_call114 = { -1 };
sjs_mat4 sjt_call115 = { -1 };
sjs_mat4 sjt_call116 = { -1 };
sjs_model* sjt_call117 = 0;
sjs_string sjt_call118 = { -1 };
sjs_mat4 sjt_call119 = { -1 };
sjs_mat4 sjt_call120 = { -1 };
sjs_model* sjt_call121 = 0;
sjs_string sjt_call122 = { -1 };
sjs_mat4 sjt_call123 = { -1 };
sjs_mat4 sjt_call124 = { -1 };
sjs_model* sjt_call125 = 0;
sjs_string sjt_call126 = { -1 };
sjs_mat4 sjt_call127 = { -1 };
sjs_mat4 sjt_call128 = { -1 };
sjs_model* sjt_call129 = 0;
sjs_model* sjt_call13 = 0;
sjs_string sjt_call130 = { -1 };
sjs_mat4 sjt_call131 = { -1 };
sjs_mat4 sjt_call132 = { -1 };
sjs_vec3 sjt_call133 = { -1 };
sjs_vec3 sjt_call134 = { -1 };
sjs_vec3 sjt_call135 = { -1 };
sjs_crosshairselement* sjt_call136 = 0;
sjs_nauscene3delement* sjt_call2 = 0;
sjs_string sjt_call34 = { -1 };
sjs_mat4 sjt_call35 = { -1 };
sjs_mat4 sjt_call36 = { -1 };
sjs_leafpanel* sjt_call37 = 0;
sjs_texture sjt_call43 = { -1 };
sjs_string sjt_call44 = { -1 };
sjs_texture sjt_call45 = { -1 };
sjs_string sjt_call46 = { -1 };
sjs_texture sjt_call47 = { -1 };
sjs_string sjt_call48 = { -1 };
sjs_texture sjt_call49 = { -1 };
sjs_string sjt_call50 = { -1 };
sjs_texture sjt_call51 = { -1 };
sjs_string sjt_call52 = { -1 };
sjs_texture sjt_call53 = { -1 };
sjs_string sjt_call54 = { -1 };
sjs_texture sjt_call55 = { -1 };
sjs_string sjt_call56 = { -1 };
sjs_texture sjt_call57 = { -1 };
sjs_string sjt_call58 = { -1 };
sjs_peoplepanel* sjt_call59 = 0;
sjs_scene2dmodel* sjt_call61 = 0;
sjs_boxelement* sjt_call81 = 0;
sjs_imageelement* sjt_call82 = 0;
sjs_string sjt_call85 = { -1 };
sjs_crosshairselement* sjt_call86 = 0;
sjs_scene2dmodel* sjt_call87 = 0;
sjs_boxelement* sjt_call88 = 0;
sjs_imageelement* sjt_call89 = 0;
sjs_string sjt_call90 = { -1 };
sjs_crosshairselement* sjt_call91 = 0;
sjs_panel3d* sjt_call92 = 0;
sjs_model* sjt_call93 = 0;
sjs_string sjt_call94 = { -1 };
sjs_mat4 sjt_call95 = { -1 };
sjs_mat4 sjt_call96 = { -1 };
sjs_model* sjt_call97 = 0;
sjs_string sjt_call98 = { -1 };
sjs_mat4 sjt_call99 = { -1 };
sjs_fillelement* sjt_cast1 = 0;
sjs_model* sjt_cast11 = 0;
sjs_leafpanel* sjt_cast15 = 0;
sjs_nauscene3delement* sjt_cast2 = 0;
sjs_peoplepanel* sjt_cast21 = 0;
sjs_scene2dmodel* sjt_cast32 = 0;
sjs_boxelement* sjt_cast44 = 0;
sjs_imageelement* sjt_cast45 = 0;
sjs_crosshairselement* sjt_cast46 = 0;
sjs_scene2dmodel* sjt_cast47 = 0;
sjs_boxelement* sjt_cast48 = 0;
sjs_imageelement* sjt_cast49 = 0;
sjs_crosshairselement* sjt_cast50 = 0;
sjs_panel3d* sjt_cast51 = 0;
sjs_model* sjt_cast52 = 0;
sjs_model* sjt_cast53 = 0;
sjs_model* sjt_cast54 = 0;
sjs_model* sjt_cast55 = 0;
sjs_model* sjt_cast56 = 0;
sjs_model* sjt_cast57 = 0;
sjs_model* sjt_cast58 = 0;
sjs_model* sjt_cast59 = 0;
sjs_model* sjt_cast60 = 0;
sjs_model* sjt_cast61 = 0;
sjs_crosshairselement* sjt_cast62 = 0;
sjs_shader* sjt_copy15 = 0;
sjs_shader* sjt_copy36 = 0;
sjs_shader* sjt_copy54 = 0;
sjs_shader* sjt_copy55 = 0;
sjs_shader* sjt_copy56 = 0;
sjs_shader* sjt_copy57 = 0;
sjs_shader* sjt_copy58 = 0;
sjs_shader* sjt_copy59 = 0;
sjs_shader* sjt_copy60 = 0;
sjs_shader* sjt_copy61 = 0;
sjs_shader* sjt_copy62 = 0;
sjs_shader* sjt_copy63 = 0;
sjs_shader* sjt_copy64 = 0;
int32_t sjt_functionParam104;
sji_model sjt_functionParam105 = { 0 };
float sjt_functionParam196;
float sjt_functionParam197;
float sjt_functionParam198;
float sjt_functionParam199;
float sjt_functionParam200;
float sjt_functionParam201;
float sjt_functionParam202;
float sjt_functionParam203;
float sjt_functionParam204;
sjs_string* sjt_functionParam205 = 0;
float sjt_functionParam206;
float sjt_functionParam207;
float sjt_functionParam208;
sjs_mat4* sjt_functionParam209 = 0;
float sjt_functionParam210;
float sjt_functionParam211;
float sjt_functionParam212;
int32_t sjt_functionParam213;
sji_model sjt_functionParam214 = { 0 };
int32_t sjt_functionParam258;
sjs_texture* sjt_functionParam259 = 0;
sjs_string* sjt_functionParam260 = 0;
int32_t sjt_functionParam261;
sjs_texture* sjt_functionParam262 = 0;
sjs_string* sjt_functionParam263 = 0;
int32_t sjt_functionParam264;
sjs_texture* sjt_functionParam265 = 0;
sjs_string* sjt_functionParam266 = 0;
int32_t sjt_functionParam267;
sjs_texture* sjt_functionParam268 = 0;
sjs_string* sjt_functionParam269 = 0;
int32_t sjt_functionParam270;
sjs_texture* sjt_functionParam271 = 0;
sjs_string* sjt_functionParam272 = 0;
int32_t sjt_functionParam273;
sjs_texture* sjt_functionParam274 = 0;
sjs_string* sjt_functionParam275 = 0;
int32_t sjt_functionParam276;
sjs_texture* sjt_functionParam277 = 0;
sjs_string* sjt_functionParam278 = 0;
int32_t sjt_functionParam279;
sjs_texture* sjt_functionParam280 = 0;
sjs_string* sjt_functionParam281 = 0;
int32_t sjt_functionParam282;
sji_model sjt_functionParam283 = { 0 };
float sjt_functionParam306;
float sjt_functionParam307;
float sjt_functionParam308;
int32_t sjt_functionParam309;
sji_model sjt_functionParam310 = { 0 };
float sjt_functionParam475;
float sjt_functionParam476;
float sjt_functionParam477;
float sjt_functionParam478;
float sjt_functionParam479;
float sjt_functionParam480;
float sjt_functionParam481;
float sjt_functionParam482;
float sjt_functionParam483;
int32_t sjt_functionParam484;
sji_element sjt_functionParam485 = { 0 };
int32_t sjt_functionParam490;
sji_element sjt_functionParam491 = { 0 };
sjs_string* sjt_functionParam495 = 0;
int32_t sjt_functionParam496;
sji_element sjt_functionParam497 = { 0 };
int32_t sjt_functionParam5;
int32_t sjt_functionParam502;
sji_model sjt_functionParam503 = { 0 };
float sjt_functionParam504;
float sjt_functionParam505;
float sjt_functionParam506;
float sjt_functionParam507;
float sjt_functionParam508;
float sjt_functionParam509;
float sjt_functionParam510;
float sjt_functionParam511;
float sjt_functionParam512;
int32_t sjt_functionParam513;
sji_element sjt_functionParam514 = { 0 };
int32_t sjt_functionParam515;
sji_element sjt_functionParam516 = { 0 };
sjs_string* sjt_functionParam517 = 0;
int32_t sjt_functionParam518;
sji_element sjt_functionParam519 = { 0 };
int32_t sjt_functionParam520;
sji_model sjt_functionParam521 = { 0 };
float sjt_functionParam526;
float sjt_functionParam527;
float sjt_functionParam528;
int32_t sjt_functionParam529;
sji_model sjt_functionParam530 = { 0 };
float sjt_functionParam531;
float sjt_functionParam532;
float sjt_functionParam533;
float sjt_functionParam534;
float sjt_functionParam535;
float sjt_functionParam536;
float sjt_functionParam537;
float sjt_functionParam538;
float sjt_functionParam539;
sjs_string* sjt_functionParam540 = 0;
float sjt_functionParam541;
float sjt_functionParam542;
float sjt_functionParam543;
sjs_mat4* sjt_functionParam544 = 0;
float sjt_functionParam545;
float sjt_functionParam546;
float sjt_functionParam547;
int32_t sjt_functionParam548;
sji_model sjt_functionParam549 = { 0 };
float sjt_functionParam550;
float sjt_functionParam551;
float sjt_functionParam552;
float sjt_functionParam553;
float sjt_functionParam554;
float sjt_functionParam555;
float sjt_functionParam556;
float sjt_functionParam557;
float sjt_functionParam558;
sjs_string* sjt_functionParam559 = 0;
float sjt_functionParam560;
float sjt_functionParam561;
float sjt_functionParam562;
sjs_mat4* sjt_functionParam563 = 0;
float sjt_functionParam564;
float sjt_functionParam565;
float sjt_functionParam566;
int32_t sjt_functionParam567;
sji_model sjt_functionParam568 = { 0 };
float sjt_functionParam569;
float sjt_functionParam570;
float sjt_functionParam571;
float sjt_functionParam572;
float sjt_functionParam573;
float sjt_functionParam574;
float sjt_functionParam575;
float sjt_functionParam576;
float sjt_functionParam577;
sjs_string* sjt_functionParam578 = 0;
float sjt_functionParam579;
float sjt_functionParam580;
float sjt_functionParam581;
sjs_mat4* sjt_functionParam582 = 0;
float sjt_functionParam583;
float sjt_functionParam584;
float sjt_functionParam585;
int32_t sjt_functionParam586;
sji_model sjt_functionParam587 = { 0 };
float sjt_functionParam588;
float sjt_functionParam589;
float sjt_functionParam590;
float sjt_functionParam591;
float sjt_functionParam592;
float sjt_functionParam593;
float sjt_functionParam594;
float sjt_functionParam595;
float sjt_functionParam596;
sjs_string* sjt_functionParam597 = 0;
float sjt_functionParam598;
float sjt_functionParam599;
sji_element sjt_functionParam6 = { 0 };
float sjt_functionParam600;
sjs_mat4* sjt_functionParam601 = 0;
float sjt_functionParam602;
float sjt_functionParam603;
float sjt_functionParam604;
int32_t sjt_functionParam605;
sji_model sjt_functionParam606 = { 0 };
float sjt_functionParam607;
float sjt_functionParam608;
float sjt_functionParam609;
float sjt_functionParam610;
float sjt_functionParam611;
float sjt_functionParam612;
float sjt_functionParam613;
float sjt_functionParam614;
float sjt_functionParam615;
sjs_string* sjt_functionParam616 = 0;
float sjt_functionParam617;
float sjt_functionParam618;
float sjt_functionParam619;
sjs_mat4* sjt_functionParam620 = 0;
float sjt_functionParam621;
float sjt_functionParam622;
float sjt_functionParam623;
int32_t sjt_functionParam624;
sji_model sjt_functionParam625 = { 0 };
float sjt_functionParam626;
float sjt_functionParam627;
float sjt_functionParam628;
float sjt_functionParam629;
float sjt_functionParam630;
float sjt_functionParam631;
float sjt_functionParam632;
float sjt_functionParam633;
float sjt_functionParam634;
sjs_string* sjt_functionParam635 = 0;
float sjt_functionParam636;
float sjt_functionParam637;
float sjt_functionParam638;
sjs_mat4* sjt_functionParam639 = 0;
float sjt_functionParam640;
float sjt_functionParam641;
float sjt_functionParam642;
int32_t sjt_functionParam643;
sji_model sjt_functionParam644 = { 0 };
float sjt_functionParam645;
float sjt_functionParam646;
float sjt_functionParam647;
float sjt_functionParam648;
float sjt_functionParam649;
float sjt_functionParam650;
float sjt_functionParam651;
float sjt_functionParam652;
float sjt_functionParam653;
sjs_string* sjt_functionParam654 = 0;
float sjt_functionParam655;
float sjt_functionParam656;
float sjt_functionParam657;
sjs_mat4* sjt_functionParam658 = 0;
float sjt_functionParam659;
float sjt_functionParam660;
float sjt_functionParam661;
int32_t sjt_functionParam662;
sji_model sjt_functionParam663 = { 0 };
float sjt_functionParam664;
float sjt_functionParam665;
float sjt_functionParam666;
float sjt_functionParam667;
float sjt_functionParam668;
float sjt_functionParam669;
float sjt_functionParam670;
float sjt_functionParam671;
float sjt_functionParam672;
sjs_string* sjt_functionParam673 = 0;
float sjt_functionParam674;
float sjt_functionParam675;
float sjt_functionParam676;
sjs_mat4* sjt_functionParam677 = 0;
float sjt_functionParam678;
float sjt_functionParam679;
float sjt_functionParam680;
int32_t sjt_functionParam681;
sji_model sjt_functionParam682 = { 0 };
float sjt_functionParam683;
float sjt_functionParam684;
float sjt_functionParam685;
float sjt_functionParam686;
float sjt_functionParam687;
float sjt_functionParam688;
float sjt_functionParam689;
float sjt_functionParam690;
float sjt_functionParam691;
sjs_string* sjt_functionParam692 = 0;
float sjt_functionParam693;
float sjt_functionParam694;
float sjt_functionParam695;
sjs_mat4* sjt_functionParam696 = 0;
float sjt_functionParam697;
float sjt_functionParam698;
float sjt_functionParam699;
int32_t sjt_functionParam700;
sji_model sjt_functionParam701 = { 0 };
float sjt_functionParam702;
float sjt_functionParam703;
float sjt_functionParam704;
float sjt_functionParam705;
float sjt_functionParam706;
float sjt_functionParam707;
float sjt_functionParam708;
float sjt_functionParam709;
float sjt_functionParam710;
sjs_string* sjt_functionParam711 = 0;
float sjt_functionParam712;
float sjt_functionParam713;
float sjt_functionParam714;
sjs_mat4* sjt_functionParam715 = 0;
float sjt_functionParam716;
float sjt_functionParam717;
float sjt_functionParam718;
sjs_vec3* sjt_functionParam719 = 0;
sjs_vec3* sjt_functionParam720 = 0;
sjs_vec3* sjt_functionParam721 = 0;
int32_t sjt_functionParam722;
sji_element sjt_functionParam723 = { 0 };
int32_t sjt_math1;
int32_t sjt_math2;
int32_t sjt_negate1;
float sjt_negate11;
float sjt_negate12;
float sjt_negate21;
float sjt_negate22;
float sjt_negate23;
float sjt_negate24;
float sjt_negate25;
float sjt_negate26;
float sjt_negate27;
float sjt_negate28;
float sjt_negate29;
float sjt_negate30;
float sjt_negate31;
float sjt_negate32;
float sjt_negate33;
float sjt_negate34;
float sjt_negate35;
float sjt_negate36;
float sjt_negate37;
float sjt_negate38;
float sjt_negate39;
float sjt_negate40;
float sjt_negate41;
float sjt_negate42;
float sjt_negate43;
float sjt_negate44;
float sjt_negate45;
float sjt_negate46;
float sjt_negate47;
float sjt_negate48;
float sjt_negate49;
float sjt_negate50;
float sjt_negate51;
float sjt_negate52;
float sjt_negate53;
float sjt_negate54;
float sjt_negate55;
sjs_array_texture* sjt_parent104 = 0;
sjs_array_texture* sjt_parent105 = 0;
sjs_array_texture* sjt_parent106 = 0;
sjs_array_texture* sjt_parent107 = 0;
sjs_array_texture* sjt_parent108 = 0;
sjs_array_texture* sjt_parent109 = 0;
sjs_array_texture* sjt_parent110 = 0;
sjs_array_texture* sjt_parent111 = 0;
sjs_array_heap_iface_model* sjt_parent112 = 0;
sjs_array_heap_iface_model* sjt_parent124 = 0;
sjs_array_heap_iface_element* sjt_parent187 = 0;
sjs_anon4* sjt_parent192 = 0;
sjs_array_heap_iface_element* sjt_parent193 = 0;
sjs_array_heap_iface_element* sjt_parent199 = 0;
sjs_anon4* sjt_parent204 = 0;
sjs_array_heap_iface_model* sjt_parent205 = 0;
sjs_array_heap_iface_element* sjt_parent206 = 0;
sjs_anon4* sjt_parent207 = 0;
sjs_array_heap_iface_element* sjt_parent208 = 0;
sjs_array_heap_iface_element* sjt_parent209 = 0;
sjs_anon4* sjt_parent210 = 0;
sjs_array_heap_iface_model* sjt_parent211 = 0;
sjs_array_heap_iface_model* sjt_parent219 = 0;
sjs_mat4* sjt_parent220 = 0;
sjs_array_heap_iface_model* sjt_parent221 = 0;
sjs_mat4* sjt_parent222 = 0;
sjs_array_heap_iface_model* sjt_parent223 = 0;
sjs_mat4* sjt_parent224 = 0;
sjs_array_heap_iface_model* sjt_parent225 = 0;
sjs_mat4* sjt_parent226 = 0;
sjs_array_heap_iface_model* sjt_parent227 = 0;
sjs_mat4* sjt_parent228 = 0;
sjs_array_heap_iface_model* sjt_parent229 = 0;
sjs_mat4* sjt_parent230 = 0;
sjs_array_heap_iface_model* sjt_parent231 = 0;
sjs_mat4* sjt_parent232 = 0;
sjs_array_heap_iface_model* sjt_parent233 = 0;
sjs_mat4* sjt_parent234 = 0;
sjs_array_heap_iface_model* sjt_parent235 = 0;
sjs_mat4* sjt_parent236 = 0;
sjs_array_heap_iface_model* sjt_parent237 = 0;
sjs_mat4* sjt_parent238 = 0;
sjs_array_heap_iface_element* sjt_parent239 = 0;
sjs_anon4* sjt_parent240 = 0;
sjs_array_heap_iface_model* sjt_parent42 = 0;
sjs_array_heap_iface_element* sjt_parent8 = 0;
sjs_mat4* sjt_parent80 = 0;
sjs_array_heap_iface_model* sjt_parent81 = 0;
sjs_anon1 sjv_animator = { -1 };
sjs_shader sjv_blurhorizontalshader = { -1 };
sjs_shader sjv_blurverticalshader = { -1 };
sjs_anon2 sjv_borderposition = { -1 };
sjs_shader sjv_boxshader = { -1 };
sjs_anon3 sjv_buttonstate = { -1 };
sjs_anon4 sjv_colors = { -1 };
sjs_hash_string_weak_iface_element sjv_elementsbyid = { -1 };
void* sjv_emptystringdata;
float sjv_f32_pi;
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
int32_t sjv_i32_maxvalue;
int32_t sjv_i32_minvalue;
sjs_shader sjv_imageshader = { -1 };
sjs_hash_string_weak_iface_model sjv_modelsbyid = { -1 };
sji_element sjv_mouse_captureelement = { 0 };
int32_t sjv_mouseeventtype_down;
int32_t sjv_mouseeventtype_move;
int32_t sjv_mouseeventtype_up;
sjs_shader sjv_phongcolorshader = { -1 };
sjs_shader sjv_phongtextureshader = { -1 };
sji_element sjv_root = { 0 };
sjs_scene2d sjv_rootscene = { -1 };
sjs_windowrenderer sjv_rootwindowrenderer = { -1 };
sjs_anon5 sjv_style = { -1 };
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
void sjf_anon2_heap(sjs_anon2* _this);
void sjf_anon3(sjs_anon3* _this);
void sjf_anon3_copy(sjs_anon3* _this, sjs_anon3* _from);
void sjf_anon3_destroy(sjs_anon3* _this);
void sjf_anon3_heap(sjs_anon3* _this);
void sjf_anon4(sjs_anon4* _this);
void sjf_anon4_blue(sjs_anon4* _parent, sjs_color* _return);
void sjf_anon4_blue_heap(sjs_anon4* _parent, sjs_color** _return);
void sjf_anon4_copy(sjs_anon4* _this, sjs_anon4* _from);
void sjf_anon4_destroy(sjs_anon4* _this);
void sjf_anon4_green(sjs_anon4* _parent, sjs_color* _return);
void sjf_anon4_green_heap(sjs_anon4* _parent, sjs_color** _return);
void sjf_anon4_heap(sjs_anon4* _this);
void sjf_anon4_red(sjs_anon4* _parent, sjs_color* _return);
void sjf_anon4_red_heap(sjs_anon4* _parent, sjs_color** _return);
void sjf_anon4_white(sjs_anon4* _parent, sjs_color* _return);
void sjf_anon4_white_heap(sjs_anon4* _parent, sjs_color** _return);
void sjf_anon5(sjs_anon5* _this);
void sjf_anon5_copy(sjs_anon5* _this, sjs_anon5* _from);
void sjf_anon5_destroy(sjs_anon5* _this);
void sjf_anon5_heap(sjs_anon5* _this);
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
void sjf_array_heap_iface_element(sjs_array_heap_iface_element* _this);
void sjf_array_heap_iface_element_copy(sjs_array_heap_iface_element* _this, sjs_array_heap_iface_element* _from);
void sjf_array_heap_iface_element_destroy(sjs_array_heap_iface_element* _this);
void sjf_array_heap_iface_element_getat_heap(sjs_array_heap_iface_element* _parent, int32_t index, sji_element* _return);
void sjf_array_heap_iface_element_heap(sjs_array_heap_iface_element* _this);
void sjf_array_heap_iface_element_initat(sjs_array_heap_iface_element* _parent, int32_t index, sji_element item);
void sjf_array_heap_iface_model(sjs_array_heap_iface_model* _this);
void sjf_array_heap_iface_model_copy(sjs_array_heap_iface_model* _this, sjs_array_heap_iface_model* _from);
void sjf_array_heap_iface_model_destroy(sjs_array_heap_iface_model* _this);
void sjf_array_heap_iface_model_getat_heap(sjs_array_heap_iface_model* _parent, int32_t index, sji_model* _return);
void sjf_array_heap_iface_model_heap(sjs_array_heap_iface_model* _this);
void sjf_array_heap_iface_model_initat(sjs_array_heap_iface_model* _parent, int32_t index, sji_model item);
void sjf_array_heap_iface_model_map_mat4(sjs_array_heap_iface_model* _parent, cb_heap_iface_model_mat4 cb, sjs_array_mat4* _return);
void sjf_array_heap_iface_model_map_mat4_heap(sjs_array_heap_iface_model* _parent, cb_heap_iface_model_mat4 cb, sjs_array_mat4** _return);
void sjf_array_i32(sjs_array_i32* _this);
void sjf_array_i32_copy(sjs_array_i32* _this, sjs_array_i32* _from);
void sjf_array_i32_destroy(sjs_array_i32* _this);
void sjf_array_i32_getat(sjs_array_i32* _parent, int32_t index, int32_t* _return);
void sjf_array_i32_heap(sjs_array_i32* _this);
void sjf_array_i32_initat(sjs_array_i32* _parent, int32_t index, int32_t item);
void sjf_array_local_iface_animation(sjs_array_local_iface_animation* _this);
void sjf_array_local_iface_animation_copy(sjs_array_local_iface_animation* _this, sjs_array_local_iface_animation* _from);
void sjf_array_local_iface_animation_destroy(sjs_array_local_iface_animation* _this);
void sjf_array_local_iface_animation_getat_heap(sjs_array_local_iface_animation* _parent, int32_t index, sji_animation* _return);
void sjf_array_local_iface_animation_heap(sjs_array_local_iface_animation* _this);
void sjf_array_local_iface_model(sjs_array_local_iface_model* _this);
void sjf_array_local_iface_model__quicksortcallback(sjs_array_local_iface_model* _parent, int32_t left, int32_t right, cb_local_iface_model_local_iface_model_i32 cb);
void sjf_array_local_iface_model_copy(sjs_array_local_iface_model* _this, sjs_array_local_iface_model* _from);
void sjf_array_local_iface_model_destroy(sjs_array_local_iface_model* _this);
void sjf_array_local_iface_model_getat_heap(sjs_array_local_iface_model* _parent, int32_t index, sji_model* _return);
void sjf_array_local_iface_model_grow(sjs_array_local_iface_model* _parent, int32_t newsize, sjs_array_local_iface_model* _return);
void sjf_array_local_iface_model_grow_heap(sjs_array_local_iface_model* _parent, int32_t newsize, sjs_array_local_iface_model** _return);
void sjf_array_local_iface_model_heap(sjs_array_local_iface_model* _this);
void sjf_array_local_iface_model_initat(sjs_array_local_iface_model* _parent, int32_t index, sji_model item);
void sjf_array_local_iface_model_setat(sjs_array_local_iface_model* _parent, int32_t index, sji_model item);
void sjf_array_local_iface_model_sortcb(sjs_array_local_iface_model* _parent, cb_local_iface_model_local_iface_model_i32 cb);
void sjf_array_mat4(sjs_array_mat4* _this);
void sjf_array_mat4_copy(sjs_array_mat4* _this, sjs_array_mat4* _from);
void sjf_array_mat4_destroy(sjs_array_mat4* _this);
void sjf_array_mat4_getat(sjs_array_mat4* _parent, int32_t index, sjs_mat4* _return);
void sjf_array_mat4_heap(sjs_array_mat4* _this);
void sjf_array_texture(sjs_array_texture* _this);
void sjf_array_texture_copy(sjs_array_texture* _this, sjs_array_texture* _from);
void sjf_array_texture_destroy(sjs_array_texture* _this);
void sjf_array_texture_getat(sjs_array_texture* _parent, int32_t index, sjs_texture* _return);
void sjf_array_texture_heap(sjs_array_texture* _this);
void sjf_array_texture_initat(sjs_array_texture* _parent, int32_t index, sjs_texture* item);
void sjf_array_texture_map_heap_iface_model(sjs_array_texture* _parent, cb_texture_heap_iface_model cb, sjs_array_heap_iface_model* _return);
void sjf_array_texture_map_heap_iface_model_heap(sjs_array_texture* _parent, cb_texture_heap_iface_model cb, sjs_array_heap_iface_model** _return);
void sjf_array_vertex_location_texture_normal(sjs_array_vertex_location_texture_normal* _this);
void sjf_array_vertex_location_texture_normal_copy(sjs_array_vertex_location_texture_normal* _this, sjs_array_vertex_location_texture_normal* _from);
void sjf_array_vertex_location_texture_normal_destroy(sjs_array_vertex_location_texture_normal* _this);
void sjf_array_vertex_location_texture_normal_getat(sjs_array_vertex_location_texture_normal* _parent, int32_t index, sjs_vertex_location_texture_normal* _return);
void sjf_array_vertex_location_texture_normal_heap(sjs_array_vertex_location_texture_normal* _this);
void sjf_array_vertex_location_texture_normal_initat(sjs_array_vertex_location_texture_normal* _parent, int32_t index, sjs_vertex_location_texture_normal* item);
void sjf_boxelement(sjs_boxelement* _this);
void sjf_boxelement_as_sji_element(sjs_boxelement* _this, sji_element* _return);
void sjf_boxelement_asinterface(sjs_boxelement* _this, int typeId, sjs_interface* _return);
void sjf_boxelement_copy(sjs_boxelement* _this, sjs_boxelement* _from);
void sjf_boxelement_destroy(sjs_boxelement* _this);
void sjf_boxelement_firemouseevent(sjs_boxelement* _parent, sjs_mouseevent* mouseevent);
void sjf_boxelement_getrect(sjs_boxelement* _parent, sjs_rect* _return);
void sjf_boxelement_getrect_heap(sjs_boxelement* _parent, sjs_rect** _return);
void sjf_boxelement_getsize(sjs_boxelement* _parent, sjs_size* maxsize, sjs_size* _return);
void sjf_boxelement_getsize_heap(sjs_boxelement* _parent, sjs_size* maxsize, sjs_size** _return);
void sjf_boxelement_heap(sjs_boxelement* _this);
void sjf_boxelement_heap_as_sji_element(sjs_boxelement* _this, sji_element* _return);
void sjf_boxelement_heap_asinterface(sjs_boxelement* _this, int typeId, sjs_interface* _return);
void sjf_boxelement_render(sjs_boxelement* _parent, sjs_scene2d* scene);
void sjf_boxelement_setrect(sjs_boxelement* _parent, sjs_rect* rect_);
void sjf_boxrenderer(sjs_boxrenderer* _this);
void sjf_boxrenderer_copy(sjs_boxrenderer* _this, sjs_boxrenderer* _from);
void sjf_boxrenderer_destroy(sjs_boxrenderer* _this);
void sjf_boxrenderer_heap(sjs_boxrenderer* _this);
void sjf_boxrenderer_render(sjs_boxrenderer* _parent, sjs_scene2d* scene);
void sjf_color(sjs_color* _this);
void sjf_color_asvec3(sjs_color* _parent, sjs_vec3* _return);
void sjf_color_asvec3_heap(sjs_color* _parent, sjs_vec3** _return);
void sjf_color_copy(sjs_color* _this, sjs_color* _from);
void sjf_color_destroy(sjs_color* _this);
void sjf_color_heap(sjs_color* _this);
void sjf_console_writeline(sjs_string* data);
void sjf_crosshairselement(sjs_crosshairselement* _this);
void sjf_crosshairselement_as_sji_element(sjs_crosshairselement* _this, sji_element* _return);
void sjf_crosshairselement_asinterface(sjs_crosshairselement* _this, int typeId, sjs_interface* _return);
void sjf_crosshairselement_copy(sjs_crosshairselement* _this, sjs_crosshairselement* _from);
void sjf_crosshairselement_destroy(sjs_crosshairselement* _this);
void sjf_crosshairselement_firemouseevent(sjs_crosshairselement* _parent, sjs_mouseevent* mouseevent);
void sjf_crosshairselement_getrect(sjs_crosshairselement* _parent, sjs_rect* _return);
void sjf_crosshairselement_getrect_heap(sjs_crosshairselement* _parent, sjs_rect** _return);
void sjf_crosshairselement_getsize(sjs_crosshairselement* _parent, sjs_size* maxsize, sjs_size* _return);
void sjf_crosshairselement_getsize_heap(sjs_crosshairselement* _parent, sjs_size* maxsize, sjs_size** _return);
void sjf_crosshairselement_heap(sjs_crosshairselement* _this);
void sjf_crosshairselement_heap_as_sji_element(sjs_crosshairselement* _this, sji_element* _return);
void sjf_crosshairselement_heap_asinterface(sjs_crosshairselement* _this, int typeId, sjs_interface* _return);
void sjf_crosshairselement_render(sjs_crosshairselement* _parent, sjs_scene2d* scene);
void sjf_crosshairselement_setrect(sjs_crosshairselement* _parent, sjs_rect* rect_);
void sjf_f32_ceil(float v, float* _return);
void sjf_f32_compare(float l, float r, int32_t* _return);
void sjf_f32_cos(float v, float* _return);
void sjf_f32_floor(float v, float* _return);
void sjf_f32_max(float a, float b, float* _return);
void sjf_f32_min(float a, float b, float* _return);
void sjf_f32_random(float* _return);
void sjf_f32_sqrt(float v, float* _return);
void sjf_f32_tan(float v, float* _return);
void sjf_f32_tostring(float val, sjs_string* _return);
void sjf_f32_tostring_heap(float val, sjs_string** _return);
void sjf_fillelement(sjs_fillelement* _this);
void sjf_fillelement_as_sji_element(sjs_fillelement* _this, sji_element* _return);
void sjf_fillelement_asinterface(sjs_fillelement* _this, int typeId, sjs_interface* _return);
void sjf_fillelement_copy(sjs_fillelement* _this, sjs_fillelement* _from);
void sjf_fillelement_destroy(sjs_fillelement* _this);
void sjf_fillelement_firemouseevent(sjs_fillelement* _parent, sjs_mouseevent* mouseevent);
void sjf_fillelement_getrect(sjs_fillelement* _parent, sjs_rect* _return);
void sjf_fillelement_getrect_heap(sjs_fillelement* _parent, sjs_rect** _return);
void sjf_fillelement_getsize(sjs_fillelement* _parent, sjs_size* maxsize, sjs_size* _return);
void sjf_fillelement_getsize_heap(sjs_fillelement* _parent, sjs_size* maxsize, sjs_size** _return);
void sjf_fillelement_heap(sjs_fillelement* _this);
void sjf_fillelement_heap_as_sji_element(sjs_fillelement* _this, sji_element* _return);
void sjf_fillelement_heap_asinterface(sjs_fillelement* _this, int typeId, sjs_interface* _return);
void sjf_fillelement_render(sjs_fillelement* _parent, sjs_scene2d* scene);
void sjf_fillelement_setrect(sjs_fillelement* _parent, sjs_rect* rect_);
void sjf_framebuffer(sjs_framebuffer* _this);
void sjf_framebuffer_copy(sjs_framebuffer* _this, sjs_framebuffer* _from);
void sjf_framebuffer_destroy(sjs_framebuffer* _this);
void sjf_framebuffer_heap(sjs_framebuffer* _this);
void sjf_glbindframebuffer(sjs_framebuffer* framebuffer);
void sjf_glbindrenderbuffer(sjs_renderbuffer* renderbuffer);
void sjf_glbindtexture(int32_t type, sjs_texture* texture);
void sjf_glcheckframebufferstatus(int32_t* _return);
void sjf_gldisable(int32_t feature);
void sjf_glenable(int32_t feature);
void sjf_glframebufferrenderbuffer(int32_t attachment, sjs_renderbuffer* renderbuffer);
void sjf_glframebuffertexture2d(int32_t attachment, int32_t target, sjs_texture* texture, int32_t level);
void sjf_glgenframebuffer(sjs_framebuffer* _return);
void sjf_glgenframebuffer_heap(sjs_framebuffer** _return);
void sjf_glgenrenderbuffer(sjs_size* size, sjs_renderbuffer* _return);
void sjf_glgenrenderbuffer_heap(sjs_size* size, sjs_renderbuffer** _return);
void sjf_glgentexture(sjs_size* size, sjs_texture* _return);
void sjf_glgentexture_heap(sjs_size* size, sjs_texture** _return);
void sjf_glgetuniformlocation(sjs_shader* shader, sjs_string* name, int32_t* _return);
void sjf_glrenderbufferstorage(int32_t format, sjs_size* size);
void sjf_glteximage2d(int32_t type, int32_t level, int32_t format, sjs_size* size, int32_t datatype, void* data);
void sjf_gltexparameteri(int32_t type, int32_t attribute, int32_t val);
void sjf_glunbindframebuffer(void);
void sjf_gluniformmat4(int32_t loc, sjs_mat4* m);
void sjf_gluniformvec3(int32_t loc, sjs_vec3* v);
void sjf_gluseprogram(sjs_shader* shader);
void sjf_glviewport(sjs_rect* rect);
void sjf_halt(sjs_string* reason);
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
void sjf_imageelement_firemouseevent(sjs_imageelement* _parent, sjs_mouseevent* mouseevent);
void sjf_imageelement_getrect(sjs_imageelement* _parent, sjs_rect* _return);
void sjf_imageelement_getrect_heap(sjs_imageelement* _parent, sjs_rect** _return);
void sjf_imageelement_getsize(sjs_imageelement* _parent, sjs_size* maxsize, sjs_size* _return);
void sjf_imageelement_getsize_heap(sjs_imageelement* _parent, sjs_size* maxsize, sjs_size** _return);
void sjf_imageelement_heap(sjs_imageelement* _this);
void sjf_imageelement_heap_as_sji_element(sjs_imageelement* _this, sji_element* _return);
void sjf_imageelement_heap_asinterface(sjs_imageelement* _this, int typeId, sjs_interface* _return);
void sjf_imageelement_render(sjs_imageelement* _parent, sjs_scene2d* scene);
void sjf_imageelement_setrect(sjs_imageelement* _parent, sjs_rect* rect_);
void sjf_imagerenderer(sjs_imagerenderer* _this);
void sjf_imagerenderer_copy(sjs_imagerenderer* _this, sjs_imagerenderer* _from);
void sjf_imagerenderer_destroy(sjs_imagerenderer* _this);
void sjf_imagerenderer_heap(sjs_imagerenderer* _this);
void sjf_imagerenderer_render(sjs_imagerenderer* _parent, sjs_scene2d* scene);
void sjf_intersecttriangle(sjs_vec3* orig, sjs_vec3* dir, sjs_vec3* v0, sjs_vec3* v1, sjs_vec3* v2, sjs_vec3* _return);
void sjf_intersecttriangle_heap(sjs_vec3* orig, sjs_vec3* dir, sjs_vec3* v0, sjs_vec3* v1, sjs_vec3* v2, sjs_vec3** _return);
void sjf_leafpanel(sjs_leafpanel* _this);
void sjf_leafpanel_as_sji_model(sjs_leafpanel* _this, sji_model* _return);
void sjf_leafpanel_asinterface(sjs_leafpanel* _this, int typeId, sjs_interface* _return);
void sjf_leafpanel_copy(sjs_leafpanel* _this, sjs_leafpanel* _from);
void sjf_leafpanel_destroy(sjs_leafpanel* _this);
void sjf_leafpanel_firemouseevent(sjs_leafpanel* _parent, sjs_mouseevent* mouseevent);
void sjf_leafpanel_getz(sjs_leafpanel* _parent, float* _return);
void sjf_leafpanel_heap(sjs_leafpanel* _this);
void sjf_leafpanel_heap_as_sji_model(sjs_leafpanel* _this, sji_model* _return);
void sjf_leafpanel_heap_asinterface(sjs_leafpanel* _this, int typeId, sjs_interface* _return);
void sjf_leafpanel_render(sjs_leafpanel* _parent);
void sjf_leafpanel_renderorqueue(sjs_leafpanel* _parent, sjs_list_local_iface_model* zqueue);
void sjf_leafpanel_texturetomodel_heap(sjs_leafpanel* _parent, sjs_texture* texture, sji_model* _return);
void sjf_leafpanel_update(sjs_leafpanel* _parent, sjs_rect* scenerect, sjs_mat4* projection, sjs_mat4* view, sjs_mat4* world, sjs_light* light);
void sjf_light(sjs_light* _this);
void sjf_light_copy(sjs_light* _this, sjs_light* _from);
void sjf_light_destroy(sjs_light* _this);
void sjf_light_heap(sjs_light* _this);
void sjf_list_local_iface_animation(sjs_list_local_iface_animation* _this);
void sjf_list_local_iface_animation_copy(sjs_list_local_iface_animation* _this, sjs_list_local_iface_animation* _from);
void sjf_list_local_iface_animation_destroy(sjs_list_local_iface_animation* _this);
void sjf_list_local_iface_animation_getat_heap(sjs_list_local_iface_animation* _parent, int32_t index, sji_animation* _return);
void sjf_list_local_iface_animation_getcount(sjs_list_local_iface_animation* _parent, int32_t* _return);
void sjf_list_local_iface_animation_heap(sjs_list_local_iface_animation* _this);
void sjf_list_local_iface_animation_removeat(sjs_list_local_iface_animation* _parent, int32_t index);
void sjf_list_local_iface_model(sjs_list_local_iface_model* _this);
void sjf_list_local_iface_model_add(sjs_list_local_iface_model* _parent, sji_model item);
void sjf_list_local_iface_model_copy(sjs_list_local_iface_model* _this, sjs_list_local_iface_model* _from);
void sjf_list_local_iface_model_destroy(sjs_list_local_iface_model* _this);
void sjf_list_local_iface_model_getat_heap(sjs_list_local_iface_model* _parent, int32_t index, sji_model* _return);
void sjf_list_local_iface_model_getcount(sjs_list_local_iface_model* _parent, int32_t* _return);
void sjf_list_local_iface_model_heap(sjs_list_local_iface_model* _this);
void sjf_list_local_iface_model_sortcb(sjs_list_local_iface_model* _parent, cb_local_iface_model_local_iface_model_i32 cb);
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
void sjf_mat4_translate(float x, float y, float z, sjs_mat4* _return);
void sjf_mat4_translate_heap(float x, float y, float z, sjs_mat4** _return);
void sjf_mat4_transpose(sjs_mat4* _parent, sjs_mat4* _return);
void sjf_mat4_transpose_heap(sjs_mat4* _parent, sjs_mat4** _return);
void sjf_model(sjs_model* _this);
void sjf_model_as_sji_model(sjs_model* _this, sji_model* _return);
void sjf_model_asinterface(sjs_model* _this, int typeId, sjs_interface* _return);
void sjf_model_copy(sjs_model* _this, sjs_model* _from);
void sjf_model_destroy(sjs_model* _this);
void sjf_model_firemouseevent(sjs_model* _parent, sjs_mouseevent* mouseevent);
void sjf_model_getz(sjs_model* _parent, float* _return);
void sjf_model_heap(sjs_model* _this);
void sjf_model_heap_as_sji_model(sjs_model* _this, sji_model* _return);
void sjf_model_heap_asinterface(sjs_model* _this, int typeId, sjs_interface* _return);
void sjf_model_render(sjs_model* _parent);
void sjf_model_renderorqueue(sjs_model* _parent, sjs_list_local_iface_model* zqueue);
void sjf_model_update(sjs_model* _parent, sjs_rect* scenerect, sjs_mat4* projection, sjs_mat4* view, sjs_mat4* world, sjs_light* light);
void sjf_model_zsort(sji_model l, sji_model r, int32_t* _return);
void sjf_model_zsort_callback(void * _parent, sji_model l, sji_model r, int32_t* _return);
void sjf_mouse_capture(sji_element element);
void sjf_mouse_release(sji_element element);
void sjf_mouseevent(sjs_mouseevent* _this);
void sjf_mouseevent_copy(sjs_mouseevent* _this, sjs_mouseevent* _from);
void sjf_mouseevent_destroy(sjs_mouseevent* _this);
void sjf_mouseevent_heap(sjs_mouseevent* _this);
void sjf_nauscene3delement(sjs_nauscene3delement* _this);
void sjf_nauscene3delement_as_sji_element(sjs_nauscene3delement* _this, sji_element* _return);
void sjf_nauscene3delement_asinterface(sjs_nauscene3delement* _this, int typeId, sjs_interface* _return);
void sjf_nauscene3delement_copy(sjs_nauscene3delement* _this, sjs_nauscene3delement* _from);
void sjf_nauscene3delement_destroy(sjs_nauscene3delement* _this);
void sjf_nauscene3delement_firemouseevent(sjs_nauscene3delement* _parent, sjs_mouseevent* mouseevent);
void sjf_nauscene3delement_getrect(sjs_nauscene3delement* _parent, sjs_rect* _return);
void sjf_nauscene3delement_getrect_heap(sjs_nauscene3delement* _parent, sjs_rect** _return);
void sjf_nauscene3delement_getsize(sjs_nauscene3delement* _parent, sjs_size* maxsize, sjs_size* _return);
void sjf_nauscene3delement_getsize_heap(sjs_nauscene3delement* _parent, sjs_size* maxsize, sjs_size** _return);
void sjf_nauscene3delement_heap(sjs_nauscene3delement* _this);
void sjf_nauscene3delement_heap_as_sji_element(sjs_nauscene3delement* _this, sji_element* _return);
void sjf_nauscene3delement_heap_asinterface(sjs_nauscene3delement* _this, int typeId, sjs_interface* _return);
void sjf_nauscene3delement_render(sjs_nauscene3delement* _parent, sjs_scene2d* scene);
void sjf_nauscene3delement_setrect(sjs_nauscene3delement* _parent, sjs_rect* rect_);
void sjf_panel3d(sjs_panel3d* _this);
void sjf_panel3d_as_sji_model(sjs_panel3d* _this, sji_model* _return);
void sjf_panel3d_asinterface(sjs_panel3d* _this, int typeId, sjs_interface* _return);
void sjf_panel3d_copy(sjs_panel3d* _this, sjs_panel3d* _from);
void sjf_panel3d_destroy(sjs_panel3d* _this);
void sjf_panel3d_firemouseevent(sjs_panel3d* _parent, sjs_mouseevent* mouseevent);
void sjf_panel3d_getz(sjs_panel3d* _parent, float* _return);
void sjf_panel3d_heap(sjs_panel3d* _this);
void sjf_panel3d_heap_as_sji_model(sjs_panel3d* _this, sji_model* _return);
void sjf_panel3d_heap_asinterface(sjs_panel3d* _this, int typeId, sjs_interface* _return);
void sjf_panel3d_render(sjs_panel3d* _parent);
void sjf_panel3d_renderorqueue(sjs_panel3d* _parent, sjs_list_local_iface_model* zqueue);
void sjf_panel3d_update(sjs_panel3d* _parent, sjs_rect* scenerect, sjs_mat4* projection, sjs_mat4* view, sjs_mat4* world, sjs_light* light);
void sjf_peoplepanel(sjs_peoplepanel* _this);
void sjf_peoplepanel_as_sji_model(sjs_peoplepanel* _this, sji_model* _return);
void sjf_peoplepanel_asinterface(sjs_peoplepanel* _this, int typeId, sjs_interface* _return);
void sjf_peoplepanel_copy(sjs_peoplepanel* _this, sjs_peoplepanel* _from);
void sjf_peoplepanel_destroy(sjs_peoplepanel* _this);
void sjf_peoplepanel_firemouseevent(sjs_peoplepanel* _parent, sjs_mouseevent* mouseevent);
void sjf_peoplepanel_getmodelmatrix(sjs_peoplepanel* _parent, sji_model model, sjs_mat4* _return);
void sjf_peoplepanel_getmodelmatrix_heap(sjs_peoplepanel* _parent, sji_model model, sjs_mat4** _return);
void sjf_peoplepanel_getz(sjs_peoplepanel* _parent, float* _return);
void sjf_peoplepanel_heap(sjs_peoplepanel* _this);
void sjf_peoplepanel_heap_as_sji_model(sjs_peoplepanel* _this, sji_model* _return);
void sjf_peoplepanel_heap_asinterface(sjs_peoplepanel* _this, int typeId, sjs_interface* _return);
void sjf_peoplepanel_render(sjs_peoplepanel* _parent);
void sjf_peoplepanel_renderorqueue(sjs_peoplepanel* _parent, sjs_list_local_iface_model* zqueue);
void sjf_peoplepanel_update(sjs_peoplepanel* _parent, sjs_rect* scenerect, sjs_mat4* projection, sjs_mat4* view, sjs_mat4* world, sjs_light* light);
void sjf_planevertexbuffer(float x0, float x1, float y0, float y1, float z0, float s0, float s1, float t0, float t1, sjs_vertexbuffer_vertex_location_texture_normal* _return);
void sjf_planevertexbuffer_heap(float x0, float x1, float y0, float y1, float z0, float s0, float s1, float t0, float t1, sjs_vertexbuffer_vertex_location_texture_normal** _return);
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
void sjf_renderbuffer(sjs_renderbuffer* _this);
void sjf_renderbuffer_copy(sjs_renderbuffer* _this, sjs_renderbuffer* _from);
void sjf_renderbuffer_destroy(sjs_renderbuffer* _this);
void sjf_renderbuffer_heap(sjs_renderbuffer* _this);
void sjf_runloop(void);
void sjf_scene2d(sjs_scene2d* _this);
void sjf_scene2d_clear(sjs_scene2d* _parent);
void sjf_scene2d_copy(sjs_scene2d* _this, sjs_scene2d* _from);
void sjf_scene2d_destroy(sjs_scene2d* _this);
void sjf_scene2d_heap(sjs_scene2d* _this);
void sjf_scene2d_setsize(sjs_scene2d* _parent, sjs_size* size);
void sjf_scene2d_updateviewport(sjs_scene2d* _parent);
void sjf_scene2dmodel(sjs_scene2dmodel* _this);
void sjf_scene2dmodel_as_sji_model(sjs_scene2dmodel* _this, sji_model* _return);
void sjf_scene2dmodel_asinterface(sjs_scene2dmodel* _this, int typeId, sjs_interface* _return);
void sjf_scene2dmodel_copy(sjs_scene2dmodel* _this, sjs_scene2dmodel* _from);
void sjf_scene2dmodel_destroy(sjs_scene2dmodel* _this);
void sjf_scene2dmodel_firemouseevent(sjs_scene2dmodel* _parent, sjs_mouseevent* mouseevent);
void sjf_scene2dmodel_getz(sjs_scene2dmodel* _parent, float* _return);
void sjf_scene2dmodel_heap(sjs_scene2dmodel* _this);
void sjf_scene2dmodel_heap_as_sji_model(sjs_scene2dmodel* _this, sji_model* _return);
void sjf_scene2dmodel_heap_asinterface(sjs_scene2dmodel* _this, int typeId, sjs_interface* _return);
void sjf_scene2dmodel_render(sjs_scene2dmodel* _parent);
void sjf_scene2dmodel_renderorqueue(sjs_scene2dmodel* _parent, sjs_list_local_iface_model* alphamodels);
void sjf_scene2dmodel_update(sjs_scene2dmodel* _parent, sjs_rect* scenerect, sjs_mat4* projection, sjs_mat4* view, sjs_mat4* world, sjs_light* light);
void sjf_shader(sjs_shader* _this);
void sjf_shader_copy(sjs_shader* _this, sjs_shader* _from);
void sjf_shader_destroy(sjs_shader* _this);
void sjf_shader_heap(sjs_shader* _this);
void sjf_size(sjs_size* _this);
void sjf_size_cap(sjs_size* _parent, sjs_size* maxsize, sjs_size* _return);
void sjf_size_cap_heap(sjs_size* _parent, sjs_size* maxsize, sjs_size** _return);
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
void sjf_texture(sjs_texture* _this);
void sjf_texture_copy(sjs_texture* _this, sjs_texture* _from);
void sjf_texture_destroy(sjs_texture* _this);
void sjf_texture_getsize(sjs_texture* _parent, sjs_size* _return);
void sjf_texture_getsize_heap(sjs_texture* _parent, sjs_size** _return);
void sjf_texture_heap(sjs_texture* _this);
void sjf_texturefrompng(sjs_string* filename, sjs_texture* _return);
void sjf_texturefrompng_heap(sjs_string* filename, sjs_texture** _return);
void sjf_vec2(sjs_vec2* _this);
void sjf_vec2_copy(sjs_vec2* _this, sjs_vec2* _from);
void sjf_vec2_destroy(sjs_vec2* _this);
void sjf_vec2_getrawsize(int32_t* _return);
void sjf_vec2_heap(sjs_vec2* _this);
void sjf_vec2_rawcopy(sjs_vec2* v, void* p, void** _return);
void sjf_vec3(sjs_vec3* _this);
void sjf_vec3_add(sjs_vec3* _parent, sjs_vec3* v, sjs_vec3* _return);
void sjf_vec3_add_heap(sjs_vec3* _parent, sjs_vec3* v, sjs_vec3** _return);
void sjf_vec3_copy(sjs_vec3* _this, sjs_vec3* _from);
void sjf_vec3_cross(sjs_vec3* _parent, sjs_vec3* v, sjs_vec3* _return);
void sjf_vec3_cross_heap(sjs_vec3* _parent, sjs_vec3* v, sjs_vec3** _return);
void sjf_vec3_destroy(sjs_vec3* _this);
void sjf_vec3_dot(sjs_vec3* _parent, sjs_vec3* v, float* _return);
void sjf_vec3_getrawsize(int32_t* _return);
void sjf_vec3_heap(sjs_vec3* _this);
void sjf_vec3_max(sjs_vec3* a, sjs_vec3* b, sjs_vec3* _return);
void sjf_vec3_max_heap(sjs_vec3* a, sjs_vec3* b, sjs_vec3** _return);
void sjf_vec3_min(sjs_vec3* a, sjs_vec3* b, sjs_vec3* _return);
void sjf_vec3_min_heap(sjs_vec3* a, sjs_vec3* b, sjs_vec3** _return);
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
void sjf_vertexbuffer_vertex_location_texture_normal_render(sjs_vertexbuffer_vertex_location_texture_normal* _parent);
void sjf_vertexbuffer_vertex_location_texture_normal_translatescreentotexture(sjs_vertexbuffer_vertex_location_texture_normal* _parent, sjs_point* screen, sjs_rect* viewport, sjs_mat4* projection, sjs_mat4* view, sjs_mat4* world, sjs_vec2* _return);
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
void sjf_anon1(sjs_anon1* _this) {
}

void sjf_anon1_copy(sjs_anon1* _this, sjs_anon1* _from) {
    _this->animations._refCount = 1;
    sjf_list_local_iface_animation_copy(&_this->animations, &_from->animations);
    _this->current = _from->current;
}

void sjf_anon1_destroy(sjs_anon1* _this) {
}

void sjf_anon1_heap(sjs_anon1* _this) {
}

void sjf_anon1_nextframe(sjs_anon1* _parent, int32_t time) {
    int32_t sjt_compare127;
    int32_t sjt_compare128;
    sjs_anon1* sjt_dot1704 = 0;
    sjs_anon1* sjt_dot1707 = 0;
    bool sjt_ifElse61;
    sjs_list_local_iface_animation* sjt_parent241 = 0;

    sjt_dot1704 = _parent;
    sjt_dot1704->current = time;
    sjt_dot1707 = _parent;
    sjt_parent241 = &(sjt_dot1707)->animations;
    sjf_list_local_iface_animation_getcount(sjt_parent241, &sjt_compare127);
    sjt_compare128 = 0;
    sjt_ifElse61 = sjt_compare127 > sjt_compare128;
    if (sjt_ifElse61) {
        int32_t i;
        sjs_anon1* sjt_dot1708 = 0;
        int32_t sjt_forEnd28;
        int32_t sjt_forStart28;
        sjs_list_local_iface_animation* sjt_parent242 = 0;

        sjt_forStart28 = 0;
        sjt_dot1708 = _parent;
        sjt_parent242 = &(sjt_dot1708)->animations;
        sjf_list_local_iface_animation_getcount(sjt_parent242, &sjt_forEnd28);
        i = sjt_forStart28;
        while (i < sjt_forEnd28) {
            sjs_anon1* sjt_dot1709 = 0;
            sjs_anon1* sjt_dot1711 = 0;
            int32_t sjt_functionParam725;
            bool sjt_ifElse62;
            int32_t sjt_interfaceParam36;
            int32_t sjt_math2431;
            int32_t sjt_math2432;
            int32_t sjt_math2433;
            int32_t sjt_math2434;
            sjs_list_local_iface_animation* sjt_parent243 = 0;
            sjs_list_local_iface_animation* sjt_parent245 = 0;
            sji_animation sjt_parent246 = { 0 };
            sji_animation sjv_a = { 0 };
            int32_t sjv_index;

            sjt_dot1709 = _parent;
            sjt_parent243 = &(sjt_dot1709)->animations;
            sjf_list_local_iface_animation_getcount(sjt_parent243, &sjt_math2433);
            sjt_math2434 = 0;
            sjt_math2431 = sjt_math2433 - sjt_math2434;
            sjt_math2432 = 1;
            sjv_index = sjt_math2431 - sjt_math2432;
            sjt_dot1711 = _parent;
            sjt_parent245 = &(sjt_dot1711)->animations;
            sjt_functionParam725 = sjv_index;
            sjf_list_local_iface_animation_getat_heap(sjt_parent245, sjt_functionParam725, &sjv_a);
            sjt_parent246 = sjv_a;
            sjt_interfaceParam36 = time;
            sjt_parent246._vtbl->nextframe(sjt_parent246._parent, sjt_interfaceParam36, &sjt_ifElse62);
            if (sjt_ifElse62) {
                sjs_anon1* sjt_dot1712 = 0;
                int32_t sjt_functionParam726;
                sjs_list_local_iface_animation* sjt_parent247 = 0;

                sjt_dot1712 = _parent;
                sjt_parent247 = &(sjt_dot1712)->animations;
                sjt_functionParam726 = sjv_index;
                sjf_list_local_iface_animation_removeat(sjt_parent247, sjt_functionParam726);
            }

            i++;

            if (sjv_a._parent != 0) {
                sjv_a._parent->_refCount--;
                if (sjv_a._parent->_refCount <= 0) {
                    sjv_a._vtbl->destroy(sjv_a._parent);
                }
            }
        }
    }
}

void sjf_anon2(sjs_anon2* _this) {
}

void sjf_anon2_copy(sjs_anon2* _this, sjs_anon2* _from) {
    _this->fill = _from->fill;
    _this->left = _from->left;
    _this->right = _from->right;
    _this->top = _from->top;
    _this->bottom = _from->bottom;
}

void sjf_anon2_destroy(sjs_anon2* _this) {
}

void sjf_anon2_heap(sjs_anon2* _this) {
}

void sjf_anon3(sjs_anon3* _this) {
}

void sjf_anon3_copy(sjs_anon3* _this, sjs_anon3* _from) {
    _this->normal = _from->normal;
    _this->hot = _from->hot;
    _this->pressed = _from->pressed;
}

void sjf_anon3_destroy(sjs_anon3* _this) {
}

void sjf_anon3_heap(sjs_anon3* _this) {
}

void sjf_anon4(sjs_anon4* _this) {
}

void sjf_anon4_blue(sjs_anon4* _parent, sjs_color* _return) {
    _return->_refCount = 1;
    _return->r = 0.0f;
    _return->g = 0.0f;
    _return->b = 1.0f;
    _return->a = 1.0f;
    sjf_color(_return);
}

void sjf_anon4_blue_heap(sjs_anon4* _parent, sjs_color** _return) {
    (*_return) = (sjs_color*)malloc(sizeof(sjs_color));
    (*_return)->_refCount = 1;
    (*_return)->r = 0.0f;
    (*_return)->g = 0.0f;
    (*_return)->b = 1.0f;
    (*_return)->a = 1.0f;
    sjf_color_heap((*_return));
}

void sjf_anon4_copy(sjs_anon4* _this, sjs_anon4* _from) {
}

void sjf_anon4_destroy(sjs_anon4* _this) {
}

void sjf_anon4_green(sjs_anon4* _parent, sjs_color* _return) {
    _return->_refCount = 1;
    _return->r = 0.0f;
    _return->g = 1.0f;
    _return->b = 0.0f;
    _return->a = 1.0f;
    sjf_color(_return);
}

void sjf_anon4_green_heap(sjs_anon4* _parent, sjs_color** _return) {
    (*_return) = (sjs_color*)malloc(sizeof(sjs_color));
    (*_return)->_refCount = 1;
    (*_return)->r = 0.0f;
    (*_return)->g = 1.0f;
    (*_return)->b = 0.0f;
    (*_return)->a = 1.0f;
    sjf_color_heap((*_return));
}

void sjf_anon4_heap(sjs_anon4* _this) {
}

void sjf_anon4_red(sjs_anon4* _parent, sjs_color* _return) {
    _return->_refCount = 1;
    _return->r = 1.0f;
    _return->g = 0.0f;
    _return->b = 0.0f;
    _return->a = 1.0f;
    sjf_color(_return);
}

void sjf_anon4_red_heap(sjs_anon4* _parent, sjs_color** _return) {
    (*_return) = (sjs_color*)malloc(sizeof(sjs_color));
    (*_return)->_refCount = 1;
    (*_return)->r = 1.0f;
    (*_return)->g = 0.0f;
    (*_return)->b = 0.0f;
    (*_return)->a = 1.0f;
    sjf_color_heap((*_return));
}

void sjf_anon4_white(sjs_anon4* _parent, sjs_color* _return) {
    _return->_refCount = 1;
    _return->r = 1.0f;
    _return->g = 1.0f;
    _return->b = 1.0f;
    _return->a = 1.0f;
    sjf_color(_return);
}

void sjf_anon4_white_heap(sjs_anon4* _parent, sjs_color** _return) {
    (*_return) = (sjs_color*)malloc(sizeof(sjs_color));
    (*_return)->_refCount = 1;
    (*_return)->r = 1.0f;
    (*_return)->g = 1.0f;
    (*_return)->b = 1.0f;
    (*_return)->a = 1.0f;
    sjf_color_heap((*_return));
}

void sjf_anon5(sjs_anon5* _this) {
}

void sjf_anon5_copy(sjs_anon5* _this, sjs_anon5* _from) {
}

void sjf_anon5_destroy(sjs_anon5* _this) {
}

void sjf_anon5_heap(sjs_anon5* _this) {
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
    sjs_array_char* sjt_dot1342 = 0;
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
    sjt_dot1342 = _parent;
    _return->count = (sjt_dot1342)->count;
    sjf_array_char(_return);
}

void sjf_array_char_grow_heap(sjs_array_char* _parent, int32_t newsize, sjs_array_char** _return) {
    sjs_array_char* sjt_dot1343 = 0;
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
    sjt_dot1343 = _parent;
    (*_return)->count = (sjt_dot1343)->count;
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

void sjf_array_heap_iface_model_map_mat4(sjs_array_heap_iface_model* _parent, cb_heap_iface_model_mat4 cb, sjs_array_mat4* _return) {
    int32_t i;
    sjs_array_heap_iface_model* sjt_dot1369 = 0;
    sjs_array_heap_iface_model* sjt_dot1370 = 0;
    sjs_array_heap_iface_model* sjt_dot1371 = 0;
    int32_t sjt_forEnd15;
    int32_t sjt_forStart15;
    void* sjv_newdata;

    sjv_newdata = 0;
    sjv_newdata = malloc(_parent->count * sizeof(sjs_mat4));
    sjt_forStart15 = 0;
    sjt_dot1369 = _parent;
    sjt_forEnd15 = (sjt_dot1369)->count;
    i = sjt_forStart15;
    while (i < sjt_forEnd15) {
        cb_heap_iface_model_mat4 sjt_callback7;
        sji_model sjt_functionParam285 = { 0 };
        int32_t sjt_functionParam286;
        sjs_mat4 sjv_newitem = { -1 };

        sjt_callback7 = cb;
        sjt_functionParam286 = i;
        sjf_array_heap_iface_model_getat_heap(_parent, sjt_functionParam286, &sjt_functionParam285);
        sjt_callback7._cb(sjt_callback7._parent, sjt_functionParam285, &sjv_newitem);
        sjs_mat4* p = (sjs_mat4*)sjv_newdata;
        p[i]._refCount = 1;
sjf_mat4_copy(&p[i], &sjv_newitem);
;
        i++;

        if (sjt_functionParam285._parent != 0) {
            sjt_functionParam285._parent->_refCount--;
            if (sjt_functionParam285._parent->_refCount <= 0) {
                sjt_functionParam285._vtbl->destroy(sjt_functionParam285._parent);
            }
        }
        if (sjv_newitem._refCount == 1) { sjf_mat4_destroy(&sjv_newitem); }
    }

    _return->_refCount = 1;
    sjt_dot1370 = _parent;
    _return->datasize = (sjt_dot1370)->count;
    _return->data = sjv_newdata;
    _return->_isglobal = false;
    sjt_dot1371 = _parent;
    _return->count = (sjt_dot1371)->count;
    sjf_array_mat4(_return);
}

void sjf_array_heap_iface_model_map_mat4_heap(sjs_array_heap_iface_model* _parent, cb_heap_iface_model_mat4 cb, sjs_array_mat4** _return) {
    int32_t i;
    sjs_array_heap_iface_model* sjt_dot1372 = 0;
    sjs_array_heap_iface_model* sjt_dot1373 = 0;
    sjs_array_heap_iface_model* sjt_dot1374 = 0;
    int32_t sjt_forEnd16;
    int32_t sjt_forStart16;
    void* sjv_newdata;

    sjv_newdata = 0;
    sjv_newdata = malloc(_parent->count * sizeof(sjs_mat4));
    sjt_forStart16 = 0;
    sjt_dot1372 = _parent;
    sjt_forEnd16 = (sjt_dot1372)->count;
    i = sjt_forStart16;
    while (i < sjt_forEnd16) {
        cb_heap_iface_model_mat4 sjt_callback8;
        sji_model sjt_functionParam287 = { 0 };
        int32_t sjt_functionParam288;
        sjs_mat4 sjv_newitem = { -1 };

        sjt_callback8 = cb;
        sjt_functionParam288 = i;
        sjf_array_heap_iface_model_getat_heap(_parent, sjt_functionParam288, &sjt_functionParam287);
        sjt_callback8._cb(sjt_callback8._parent, sjt_functionParam287, &sjv_newitem);
        sjs_mat4* p = (sjs_mat4*)sjv_newdata;
        p[i]._refCount = 1;
sjf_mat4_copy(&p[i], &sjv_newitem);
;
        i++;

        if (sjt_functionParam287._parent != 0) {
            sjt_functionParam287._parent->_refCount--;
            if (sjt_functionParam287._parent->_refCount <= 0) {
                sjt_functionParam287._vtbl->destroy(sjt_functionParam287._parent);
            }
        }
        if (sjv_newitem._refCount == 1) { sjf_mat4_destroy(&sjv_newitem); }
    }

    (*_return) = (sjs_array_mat4*)malloc(sizeof(sjs_array_mat4));
    (*_return)->_refCount = 1;
    sjt_dot1373 = _parent;
    (*_return)->datasize = (sjt_dot1373)->count;
    (*_return)->data = sjv_newdata;
    (*_return)->_isglobal = false;
    sjt_dot1374 = _parent;
    (*_return)->count = (sjt_dot1374)->count;
    sjf_array_mat4_heap((*_return));
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

void sjf_array_local_iface_animation(sjs_array_local_iface_animation* _this) {
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

void sjf_array_local_iface_animation_copy(sjs_array_local_iface_animation* _this, sjs_array_local_iface_animation* _from) {
    _this->datasize = _from->datasize;
    _this->data = _from->data;
    _this->_isglobal = _from->_isglobal;
    _this->count = _from->count;
    _this->data = _from->data;
    if (!_this->_isglobal && _this->data) {
        ptr_retain(_this->data);
    }
}

void sjf_array_local_iface_animation_destroy(sjs_array_local_iface_animation* _this) {
    if (!_this->_isglobal && _this->data) {
        if (ptr_release(_this->data)) {
            sji_animation* p = (sji_animation*)_this->data;
            for (int i = 0; i < _this->count; i++) {
                ;
            }
            free(p);
        }
    }
}

void sjf_array_local_iface_animation_getat_heap(sjs_array_local_iface_animation* _parent, int32_t index, sji_animation* _return) {
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

void sjf_array_local_iface_animation_heap(sjs_array_local_iface_animation* _this) {
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

void sjf_array_local_iface_model(sjs_array_local_iface_model* _this) {
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

void sjf_array_local_iface_model__quicksortcallback(sjs_array_local_iface_model* _parent, int32_t left, int32_t right, cb_local_iface_model_local_iface_model_i32 cb) {
    int32_t sjt_compare11;
    int32_t sjt_compare12;
    int32_t sjt_compare25;
    int32_t sjt_compare26;
    int32_t sjt_compare27;
    int32_t sjt_compare28;
    int32_t sjt_functionParam17;
    bool sjt_ifElse4;
    bool sjt_ifElse5;
    int32_t sjt_math45;
    int32_t sjt_math46;
    int32_t sjt_math47;
    int32_t sjt_math48;
    bool sjt_while1;
    int32_t sjv_i;
    int32_t sjv_j;
    sji_model sjv_pivot = { 0 };

    sjv_i = left;
    sjv_j = right;
    sjt_math47 = left;
    sjt_math48 = right;
    sjt_math45 = sjt_math47 + sjt_math48;
    sjt_math46 = 2;
    sjt_functionParam17 = sjt_math45 / sjt_math46;
    sjf_array_local_iface_model_getat_heap(_parent, sjt_functionParam17, &sjv_pivot);
    sjt_compare11 = sjv_i;
    sjt_compare12 = sjv_j;
    sjt_while1 = sjt_compare11 <= sjt_compare12;
    while (sjt_while1) {
        cb_local_iface_model_local_iface_model_i32 sjt_callback1;
        cb_local_iface_model_local_iface_model_i32 sjt_callback3;
        int32_t sjt_compare13;
        int32_t sjt_compare14;
        int32_t sjt_compare17;
        int32_t sjt_compare18;
        int32_t sjt_compare21;
        int32_t sjt_compare22;
        int32_t sjt_compare23;
        int32_t sjt_compare24;
        sji_model sjt_functionParam18 = { 0 };
        int32_t sjt_functionParam19;
        sji_model sjt_functionParam20 = { 0 };
        sji_model sjt_functionParam24 = { 0 };
        int32_t sjt_functionParam25;
        sji_model sjt_functionParam26 = { 0 };
        bool sjt_ifElse3;
        bool sjt_while2;
        bool sjt_while3;

        sjt_callback1 = cb;
        sjt_functionParam19 = sjv_i;
        sjf_array_local_iface_model_getat_heap(_parent, sjt_functionParam19, &sjt_functionParam18);
        sjt_functionParam20 = sjv_pivot;
        if (sjt_functionParam20._parent != 0) {
            sjt_functionParam20._parent->_refCount++;
        }

        sjt_callback1._cb(sjt_callback1._parent, sjt_functionParam18, sjt_functionParam20, &sjt_compare13);
        sjt_compare14 = 0;
        sjt_while2 = sjt_compare13 < sjt_compare14;
        while (sjt_while2) {
            cb_local_iface_model_local_iface_model_i32 sjt_callback2;
            int32_t sjt_compare15;
            int32_t sjt_compare16;
            sji_model sjt_functionParam21 = { 0 };
            int32_t sjt_functionParam22;
            sji_model sjt_functionParam23 = { 0 };
            int32_t sjt_math49;
            int32_t sjt_math50;

            sjt_math49 = sjv_i;
            sjt_math50 = 1;
            sjv_i = sjt_math49 + sjt_math50;
            sjt_callback2 = cb;
            sjt_functionParam22 = sjv_i;
            sjf_array_local_iface_model_getat_heap(_parent, sjt_functionParam22, &sjt_functionParam21);
            sjt_functionParam23 = sjv_pivot;
            if (sjt_functionParam23._parent != 0) {
                sjt_functionParam23._parent->_refCount++;
            }

            sjt_callback2._cb(sjt_callback2._parent, sjt_functionParam21, sjt_functionParam23, &sjt_compare15);
            sjt_compare16 = 0;
            sjt_while2 = sjt_compare15 < sjt_compare16;

            if (sjt_functionParam21._parent != 0) {
                sjt_functionParam21._parent->_refCount--;
                if (sjt_functionParam21._parent->_refCount <= 0) {
                    sjt_functionParam21._vtbl->destroy(sjt_functionParam21._parent);
                }
            }
            if (sjt_functionParam23._parent != 0) {
                sjt_functionParam23._parent->_refCount--;
                if (sjt_functionParam23._parent->_refCount <= 0) {
                    sjt_functionParam23._vtbl->destroy(sjt_functionParam23._parent);
                }
            }
        }

        sjt_callback3 = cb;
        sjt_functionParam25 = sjv_j;
        sjf_array_local_iface_model_getat_heap(_parent, sjt_functionParam25, &sjt_functionParam24);
        sjt_functionParam26 = sjv_pivot;
        if (sjt_functionParam26._parent != 0) {
            sjt_functionParam26._parent->_refCount++;
        }

        sjt_callback3._cb(sjt_callback3._parent, sjt_functionParam24, sjt_functionParam26, &sjt_compare17);
        sjt_compare18 = 0;
        sjt_while3 = sjt_compare17 > sjt_compare18;
        while (sjt_while3) {
            cb_local_iface_model_local_iface_model_i32 sjt_callback4;
            int32_t sjt_compare19;
            int32_t sjt_compare20;
            sji_model sjt_functionParam27 = { 0 };
            int32_t sjt_functionParam28;
            sji_model sjt_functionParam29 = { 0 };
            int32_t sjt_math51;
            int32_t sjt_math52;

            sjt_math51 = sjv_j;
            sjt_math52 = 1;
            sjv_j = sjt_math51 - sjt_math52;
            sjt_callback4 = cb;
            sjt_functionParam28 = sjv_j;
            sjf_array_local_iface_model_getat_heap(_parent, sjt_functionParam28, &sjt_functionParam27);
            sjt_functionParam29 = sjv_pivot;
            if (sjt_functionParam29._parent != 0) {
                sjt_functionParam29._parent->_refCount++;
            }

            sjt_callback4._cb(sjt_callback4._parent, sjt_functionParam27, sjt_functionParam29, &sjt_compare19);
            sjt_compare20 = 0;
            sjt_while3 = sjt_compare19 > sjt_compare20;

            if (sjt_functionParam27._parent != 0) {
                sjt_functionParam27._parent->_refCount--;
                if (sjt_functionParam27._parent->_refCount <= 0) {
                    sjt_functionParam27._vtbl->destroy(sjt_functionParam27._parent);
                }
            }
            if (sjt_functionParam29._parent != 0) {
                sjt_functionParam29._parent->_refCount--;
                if (sjt_functionParam29._parent->_refCount <= 0) {
                    sjt_functionParam29._vtbl->destroy(sjt_functionParam29._parent);
                }
            }
        }

        sjt_compare21 = sjv_i;
        sjt_compare22 = sjv_j;
        sjt_ifElse3 = sjt_compare21 <= sjt_compare22;
        if (sjt_ifElse3) {
            sji_model sjt_call3 = { 0 };
            int32_t sjt_functionParam30;
            int32_t sjt_functionParam31;
            sji_model sjt_functionParam32 = { 0 };
            int32_t sjt_functionParam33;
            int32_t sjt_functionParam34;
            sji_model sjt_functionParam35 = { 0 };
            int32_t sjt_math53;
            int32_t sjt_math54;
            int32_t sjt_math55;
            int32_t sjt_math56;
            sji_model sjv_tmp = { 0 };

            sjt_functionParam30 = sjv_i;
            sjf_array_local_iface_model_getat_heap(_parent, sjt_functionParam30, &sjv_tmp);
            sjt_functionParam31 = sjv_i;
            sjt_functionParam33 = sjv_j;
            sjf_array_local_iface_model_getat_heap(_parent, sjt_functionParam33, &sjt_call3);
            sjt_functionParam32 = sjt_call3;
            sjf_array_local_iface_model_setat(_parent, sjt_functionParam31, sjt_functionParam32);
            sjt_functionParam34 = sjv_j;
            sjt_functionParam35 = sjv_tmp;
            sjf_array_local_iface_model_setat(_parent, sjt_functionParam34, sjt_functionParam35);
            sjt_math53 = sjv_i;
            sjt_math54 = 1;
            sjv_i = sjt_math53 + sjt_math54;
            sjt_math55 = sjv_j;
            sjt_math56 = 1;
            sjv_j = sjt_math55 - sjt_math56;

            if (sjt_call3._parent != 0) {
                sjt_call3._parent->_refCount--;
                if (sjt_call3._parent->_refCount <= 0) {
                    sjt_call3._vtbl->destroy(sjt_call3._parent);
                }
            }
            if (sjv_tmp._parent != 0) {
                sjv_tmp._parent->_refCount--;
                if (sjv_tmp._parent->_refCount <= 0) {
                    sjv_tmp._vtbl->destroy(sjv_tmp._parent);
                }
            }
        }

        sjt_compare23 = sjv_i;
        sjt_compare24 = sjv_j;
        sjt_while1 = sjt_compare23 <= sjt_compare24;

        if (sjt_functionParam18._parent != 0) {
            sjt_functionParam18._parent->_refCount--;
            if (sjt_functionParam18._parent->_refCount <= 0) {
                sjt_functionParam18._vtbl->destroy(sjt_functionParam18._parent);
            }
        }
        if (sjt_functionParam20._parent != 0) {
            sjt_functionParam20._parent->_refCount--;
            if (sjt_functionParam20._parent->_refCount <= 0) {
                sjt_functionParam20._vtbl->destroy(sjt_functionParam20._parent);
            }
        }
        if (sjt_functionParam24._parent != 0) {
            sjt_functionParam24._parent->_refCount--;
            if (sjt_functionParam24._parent->_refCount <= 0) {
                sjt_functionParam24._vtbl->destroy(sjt_functionParam24._parent);
            }
        }
        if (sjt_functionParam26._parent != 0) {
            sjt_functionParam26._parent->_refCount--;
            if (sjt_functionParam26._parent->_refCount <= 0) {
                sjt_functionParam26._vtbl->destroy(sjt_functionParam26._parent);
            }
        }
    }

    sjt_compare25 = left;
    sjt_compare26 = sjv_j;
    sjt_ifElse4 = sjt_compare25 < sjt_compare26;
    if (sjt_ifElse4) {
        int32_t sjt_functionParam36;
        int32_t sjt_functionParam37;
        cb_local_iface_model_local_iface_model_i32 sjt_functionParam38;

        sjt_functionParam36 = left;
        sjt_functionParam37 = sjv_j;
        sjt_functionParam38 = cb;
        sjf_array_local_iface_model__quicksortcallback(_parent, sjt_functionParam36, sjt_functionParam37, sjt_functionParam38);
    }

    sjt_compare27 = sjv_i;
    sjt_compare28 = right;
    sjt_ifElse5 = sjt_compare27 < sjt_compare28;
    if (sjt_ifElse5) {
        int32_t sjt_functionParam39;
        int32_t sjt_functionParam40;
        cb_local_iface_model_local_iface_model_i32 sjt_functionParam41;

        sjt_functionParam39 = sjv_i;
        sjt_functionParam40 = right;
        sjt_functionParam41 = cb;
        sjf_array_local_iface_model__quicksortcallback(_parent, sjt_functionParam39, sjt_functionParam40, sjt_functionParam41);
    }

    if (sjv_pivot._parent != 0) {
        sjv_pivot._parent->_refCount--;
        if (sjv_pivot._parent->_refCount <= 0) {
            sjv_pivot._vtbl->destroy(sjv_pivot._parent);
        }
    }
}

void sjf_array_local_iface_model_copy(sjs_array_local_iface_model* _this, sjs_array_local_iface_model* _from) {
    _this->datasize = _from->datasize;
    _this->data = _from->data;
    _this->_isglobal = _from->_isglobal;
    _this->count = _from->count;
    _this->data = _from->data;
    if (!_this->_isglobal && _this->data) {
        ptr_retain(_this->data);
    }
}

void sjf_array_local_iface_model_destroy(sjs_array_local_iface_model* _this) {
    if (!_this->_isglobal && _this->data) {
        if (ptr_release(_this->data)) {
            sji_model* p = (sji_model*)_this->data;
            for (int i = 0; i < _this->count; i++) {
                ;
            }
            free(p);
        }
    }
}

void sjf_array_local_iface_model_getat_heap(sjs_array_local_iface_model* _parent, int32_t index, sji_model* _return) {
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

void sjf_array_local_iface_model_grow(sjs_array_local_iface_model* _parent, int32_t newsize, sjs_array_local_iface_model* _return) {
    sjs_array_local_iface_model* sjt_dot555 = 0;
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
;
        }
    }
    _return->_refCount = 1;
    _return->datasize = newsize;
    _return->data = sjv_newdata;
    _return->_isglobal = false;
    sjt_dot555 = _parent;
    _return->count = (sjt_dot555)->count;
    sjf_array_local_iface_model(_return);
}

void sjf_array_local_iface_model_grow_heap(sjs_array_local_iface_model* _parent, int32_t newsize, sjs_array_local_iface_model** _return) {
    sjs_array_local_iface_model* sjt_dot556 = 0;
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
;
        }
    }
    (*_return) = (sjs_array_local_iface_model*)malloc(sizeof(sjs_array_local_iface_model));
    (*_return)->_refCount = 1;
    (*_return)->datasize = newsize;
    (*_return)->data = sjv_newdata;
    (*_return)->_isglobal = false;
    sjt_dot556 = _parent;
    (*_return)->count = (sjt_dot556)->count;
    sjf_array_local_iface_model_heap((*_return));
}

void sjf_array_local_iface_model_heap(sjs_array_local_iface_model* _this) {
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

void sjf_array_local_iface_model_initat(sjs_array_local_iface_model* _parent, int32_t index, sji_model item) {
    if (index != _parent->count) {
        halt("initAt: can only initialize last element\n");		
    }
    if (index >= _parent->datasize || index < 0) {
        halt("initAt: out of bounds %d:%d\n", index, _parent->datasize);
    }
    sji_model* p = (sji_model*)_parent->data;
    p[index] = item;
;
    _parent->count = index + 1;
}

void sjf_array_local_iface_model_setat(sjs_array_local_iface_model* _parent, int32_t index, sji_model item) {
    if (index >= _parent->count || index < 0) {
        halt("setAt: out of bounds %d:%d\n", index, _parent->count);
    }
    sji_model* p = (sji_model*)_parent->data;
    ;
    p[index] = item;
;
}

void sjf_array_local_iface_model_sortcb(sjs_array_local_iface_model* _parent, cb_local_iface_model_local_iface_model_i32 cb) {
    int32_t sjt_compare10;
    int32_t sjt_compare9;
    sjs_array_local_iface_model* sjt_dot55 = 0;
    bool sjt_ifElse2;

    sjt_dot55 = _parent;
    sjt_compare9 = (sjt_dot55)->count;
    sjt_compare10 = 1;
    sjt_ifElse2 = sjt_compare9 > sjt_compare10;
    if (sjt_ifElse2) {
        sjs_array_local_iface_model* sjt_dot56 = 0;
        int32_t sjt_functionParam42;
        int32_t sjt_functionParam43;
        cb_local_iface_model_local_iface_model_i32 sjt_functionParam44;
        int32_t sjt_math57;
        int32_t sjt_math58;

        sjt_functionParam42 = 0;
        sjt_dot56 = _parent;
        sjt_math57 = (sjt_dot56)->count;
        sjt_math58 = 1;
        sjt_functionParam43 = sjt_math57 - sjt_math58;
        sjt_functionParam44 = cb;
        sjf_array_local_iface_model__quicksortcallback(_parent, sjt_functionParam42, sjt_functionParam43, sjt_functionParam44);
    }
}

void sjf_array_mat4(sjs_array_mat4* _this) {
    if (_this->datasize < 0) {
        halt("size is less than zero");
    }
    if (!_this->data) {
        _this->data = malloc(_this->datasize * sizeof(sjs_mat4));
        if (!_this->data) {
            halt("grow: out of memory\n");
        }
    }
}

void sjf_array_mat4_copy(sjs_array_mat4* _this, sjs_array_mat4* _from) {
    _this->datasize = _from->datasize;
    _this->data = _from->data;
    _this->_isglobal = _from->_isglobal;
    _this->count = _from->count;
    _this->data = _from->data;
    if (!_this->_isglobal && _this->data) {
        ptr_retain(_this->data);
    }
}

void sjf_array_mat4_destroy(sjs_array_mat4* _this) {
    if (!_this->_isglobal && _this->data) {
        if (ptr_release(_this->data)) {
            sjs_mat4* p = (sjs_mat4*)_this->data;
            for (int i = 0; i < _this->count; i++) {
                ;
            }
            free(p);
        }
    }
}

void sjf_array_mat4_getat(sjs_array_mat4* _parent, int32_t index, sjs_mat4* _return) {
    if (index >= _parent->count || index < 0) {
        halt("getAt: out of bounds\n");
    }
    sjs_mat4* p = (sjs_mat4*)_parent->data;
    _return->_refCount = 1;
sjf_mat4_copy(_return, &p[index]);
return;;		
}

void sjf_array_mat4_heap(sjs_array_mat4* _this) {
    if (_this->datasize < 0) {
        halt("size is less than zero");
    }
    if (!_this->data) {
        _this->data = malloc(_this->datasize * sizeof(sjs_mat4));
        if (!_this->data) {
            halt("grow: out of memory\n");
        }
    }
}

void sjf_array_texture(sjs_array_texture* _this) {
    if (_this->datasize < 0) {
        halt("size is less than zero");
    }
    if (!_this->data) {
        _this->data = malloc(_this->datasize * sizeof(sjs_texture));
        if (!_this->data) {
            halt("grow: out of memory\n");
        }
    }
}

void sjf_array_texture_copy(sjs_array_texture* _this, sjs_array_texture* _from) {
    _this->datasize = _from->datasize;
    _this->data = _from->data;
    _this->_isglobal = _from->_isglobal;
    _this->count = _from->count;
    _this->data = _from->data;
    if (!_this->_isglobal && _this->data) {
        ptr_retain(_this->data);
    }
}

void sjf_array_texture_destroy(sjs_array_texture* _this) {
    if (!_this->_isglobal && _this->data) {
        if (ptr_release(_this->data)) {
            sjs_texture* p = (sjs_texture*)_this->data;
            for (int i = 0; i < _this->count; i++) {
                ;
            }
            free(p);
        }
    }
}

void sjf_array_texture_getat(sjs_array_texture* _parent, int32_t index, sjs_texture* _return) {
    if (index >= _parent->count || index < 0) {
        halt("getAt: out of bounds\n");
    }
    sjs_texture* p = (sjs_texture*)_parent->data;
    _return->_refCount = 1;
sjf_texture_copy(_return, &p[index]);
return;;		
}

void sjf_array_texture_heap(sjs_array_texture* _this) {
    if (_this->datasize < 0) {
        halt("size is less than zero");
    }
    if (!_this->data) {
        _this->data = malloc(_this->datasize * sizeof(sjs_texture));
        if (!_this->data) {
            halt("grow: out of memory\n");
        }
    }
}

void sjf_array_texture_initat(sjs_array_texture* _parent, int32_t index, sjs_texture* item) {
    if (index != _parent->count) {
        halt("initAt: can only initialize last element\n");		
    }
    if (index >= _parent->datasize || index < 0) {
        halt("initAt: out of bounds %d:%d\n", index, _parent->datasize);
    }
    sjs_texture* p = (sjs_texture*)_parent->data;
    p[index]._refCount = 1;
sjf_texture_copy(&p[index], item);
;
    _parent->count = index + 1;
}

void sjf_array_texture_map_heap_iface_model(sjs_array_texture* _parent, cb_texture_heap_iface_model cb, sjs_array_heap_iface_model* _return) {
    int32_t i;
    sjs_array_texture* sjt_dot1329 = 0;
    sjs_array_texture* sjt_dot1330 = 0;
    sjs_array_texture* sjt_dot1331 = 0;
    int32_t sjt_forEnd8;
    int32_t sjt_forStart8;
    void* sjv_newdata;

    sjv_newdata = 0;
    sjv_newdata = malloc(_parent->count * sizeof(sji_model));
    sjt_forStart8 = 0;
    sjt_dot1329 = _parent;
    sjt_forEnd8 = (sjt_dot1329)->count;
    i = sjt_forStart8;
    while (i < sjt_forEnd8) {
        sjs_texture sjt_call38 = { -1 };
        cb_texture_heap_iface_model sjt_callback5;
        sjs_texture* sjt_functionParam215 = 0;
        int32_t sjt_functionParam216;
        sji_model sjv_newitem = { 0 };

        sjt_callback5 = cb;
        sjt_functionParam216 = i;
        sjf_array_texture_getat(_parent, sjt_functionParam216, &sjt_call38);
        sjt_functionParam215 = &sjt_call38;
        sjt_callback5._cb_heap(sjt_callback5._parent, sjt_functionParam215, &sjv_newitem);
        sji_model* p = (sji_model*)sjv_newdata;
        p[i] = sjv_newitem;
if (p[i]._parent != 0) {
    p[i]._parent->_refCount++;
}
;
        i++;

        if (sjv_newitem._parent != 0) {
            sjv_newitem._parent->_refCount--;
            if (sjv_newitem._parent->_refCount <= 0) {
                sjv_newitem._vtbl->destroy(sjv_newitem._parent);
            }
        }
        if (sjt_call38._refCount == 1) { sjf_texture_destroy(&sjt_call38); }
    }

    _return->_refCount = 1;
    sjt_dot1330 = _parent;
    _return->datasize = (sjt_dot1330)->count;
    _return->data = sjv_newdata;
    _return->_isglobal = false;
    sjt_dot1331 = _parent;
    _return->count = (sjt_dot1331)->count;
    sjf_array_heap_iface_model(_return);
}

void sjf_array_texture_map_heap_iface_model_heap(sjs_array_texture* _parent, cb_texture_heap_iface_model cb, sjs_array_heap_iface_model** _return) {
    int32_t i;
    sjs_array_texture* sjt_dot1332 = 0;
    sjs_array_texture* sjt_dot1333 = 0;
    sjs_array_texture* sjt_dot1334 = 0;
    int32_t sjt_forEnd9;
    int32_t sjt_forStart9;
    void* sjv_newdata;

    sjv_newdata = 0;
    sjv_newdata = malloc(_parent->count * sizeof(sji_model));
    sjt_forStart9 = 0;
    sjt_dot1332 = _parent;
    sjt_forEnd9 = (sjt_dot1332)->count;
    i = sjt_forStart9;
    while (i < sjt_forEnd9) {
        sjs_texture sjt_call39 = { -1 };
        cb_texture_heap_iface_model sjt_callback6;
        sjs_texture* sjt_functionParam217 = 0;
        int32_t sjt_functionParam218;
        sji_model sjv_newitem = { 0 };

        sjt_callback6 = cb;
        sjt_functionParam218 = i;
        sjf_array_texture_getat(_parent, sjt_functionParam218, &sjt_call39);
        sjt_functionParam217 = &sjt_call39;
        sjt_callback6._cb_heap(sjt_callback6._parent, sjt_functionParam217, &sjv_newitem);
        sji_model* p = (sji_model*)sjv_newdata;
        p[i] = sjv_newitem;
if (p[i]._parent != 0) {
    p[i]._parent->_refCount++;
}
;
        i++;

        if (sjv_newitem._parent != 0) {
            sjv_newitem._parent->_refCount--;
            if (sjv_newitem._parent->_refCount <= 0) {
                sjv_newitem._vtbl->destroy(sjv_newitem._parent);
            }
        }
        if (sjt_call39._refCount == 1) { sjf_texture_destroy(&sjt_call39); }
    }

    (*_return) = (sjs_array_heap_iface_model*)malloc(sizeof(sjs_array_heap_iface_model));
    (*_return)->_refCount = 1;
    sjt_dot1333 = _parent;
    (*_return)->datasize = (sjt_dot1333)->count;
    (*_return)->data = sjv_newdata;
    (*_return)->_isglobal = false;
    sjt_dot1334 = _parent;
    (*_return)->count = (sjt_dot1334)->count;
    sjf_array_heap_iface_model_heap((*_return));
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
    }

    _return->_parent = 0;
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

void sjf_boxelement_firemouseevent(sjs_boxelement* _parent, sjs_mouseevent* mouseevent) {
}

void sjf_boxelement_getrect(sjs_boxelement* _parent, sjs_rect* _return) {
    sjs_rect* sjt_copy37 = 0;
    sjs_boxelement* sjt_dot1582 = 0;

    sjt_dot1582 = _parent;
    sjt_copy37 = &(sjt_dot1582)->rect;
    _return->_refCount = 1;
    sjf_rect_copy(_return, sjt_copy37);
}

void sjf_boxelement_getrect_heap(sjs_boxelement* _parent, sjs_rect** _return) {
    sjs_rect* sjt_copy38 = 0;
    sjs_boxelement* sjt_dot1583 = 0;

    sjt_dot1583 = _parent;
    sjt_copy38 = &(sjt_dot1583)->rect;
    (*_return) = (sjs_rect*)malloc(sizeof(sjs_rect));
    (*_return)->_refCount = 1;
    sjf_rect_copy((*_return), sjt_copy38);
}

void sjf_boxelement_getsize(sjs_boxelement* _parent, sjs_size* maxsize, sjs_size* _return) {
    sjs_boxelement* sjt_dot1580 = 0;
    sjs_size* sjt_functionParam486 = 0;
    sjs_size* sjt_parent188 = 0;

    sjt_dot1580 = _parent;
    sjt_parent188 = &(sjt_dot1580)->idealsize;
    sjt_functionParam486 = maxsize;
    sjf_size_cap(sjt_parent188, sjt_functionParam486, _return);
}

void sjf_boxelement_getsize_heap(sjs_boxelement* _parent, sjs_size* maxsize, sjs_size** _return) {
    sjs_boxelement* sjt_dot1581 = 0;
    sjs_size* sjt_functionParam487 = 0;
    sjs_size* sjt_parent189 = 0;

    sjt_dot1581 = _parent;
    sjt_parent189 = &(sjt_dot1581)->idealsize;
    sjt_functionParam487 = maxsize;
    sjf_size_cap_heap(sjt_parent189, sjt_functionParam487, _return);
}

void sjf_boxelement_heap(sjs_boxelement* _this) {
}

void sjf_boxelement_heap_as_sji_element(sjs_boxelement* _this, sji_element* _return) {
    _return->_parent = (sjs_object*)_this;
    _return->_vtbl = &sjs_boxelement_element_vtbl;
}

void sjf_boxelement_heap_asinterface(sjs_boxelement* _this, int typeId, sjs_interface* _return) {
    switch (typeId) {
        case sji_element_typeId:  {
            sjf_boxelement_heap_as_sji_element(_this, (sji_element*)_return);
            break;
        }
    }

    _return->_parent = 0;
}

void sjf_boxelement_render(sjs_boxelement* _parent, sjs_scene2d* scene) {
    sjs_boxelement* sjt_dot1587 = 0;
    sjs_boxelement* sjt_dot1591 = 0;
    bool sjt_ifElse47;
    bool sjt_ifElse48;
    sjs_boxrenderer* sjt_isEmpty12 = 0;
    sjs_boxrenderer* sjt_isEmpty13 = 0;

    sjt_dot1587 = _parent;
    sjt_isEmpty12 = ((sjt_dot1587)->boxrenderer._refCount != -1 ? &(sjt_dot1587)->boxrenderer : 0);
    sjt_ifElse47 = (sjt_isEmpty12 == 0);
    if (sjt_ifElse47) {
        sjs_rect* sjt_copy40 = 0;
        sjs_color* sjt_copy41 = 0;
        sjs_boxelement* sjt_dot1588 = 0;
        sjs_boxelement* sjt_dot1589 = 0;
        sjs_boxelement* sjt_dot1590 = 0;

        sjt_dot1588 = _parent;
        sjt_dot1588->boxrenderer._refCount = 1;
        sjt_dot1589 = _parent;
        sjt_copy40 = &(sjt_dot1589)->rect;
        sjt_dot1588->boxrenderer.rect._refCount = 1;
        sjf_rect_copy(&sjt_dot1588->boxrenderer.rect, sjt_copy40);
        sjt_dot1590 = _parent;
        sjt_copy41 = &(sjt_dot1590)->color;
        sjt_dot1588->boxrenderer.color._refCount = 1;
        sjf_color_copy(&sjt_dot1588->boxrenderer.color, sjt_copy41);
        sjf_boxrenderer(&sjt_dot1588->boxrenderer);
    }

    sjt_dot1591 = _parent;
    sjt_isEmpty13 = ((sjt_dot1591)->boxrenderer._refCount != -1 ? &(sjt_dot1591)->boxrenderer : 0);
    sjt_ifElse48 = (sjt_isEmpty13 != 0);
    if (sjt_ifElse48) {
        sjs_boxelement* sjt_dot1592 = 0;
        sjs_scene2d* sjt_functionParam489 = 0;
        sjs_boxrenderer* sjt_parent191 = 0;

        sjt_dot1592 = _parent;
        sjt_parent191 = ((sjt_dot1592)->boxrenderer._refCount != -1 ? &(sjt_dot1592)->boxrenderer : 0);
        sjt_functionParam489 = scene;
        sjf_boxrenderer_render(sjt_parent191, sjt_functionParam489);
    }
}

void sjf_boxelement_setrect(sjs_boxelement* _parent, sjs_rect* rect_) {
    bool result26;
    sjs_boxelement* sjt_dot1584 = 0;
    sjs_rect* sjt_functionParam488 = 0;
    bool sjt_ifElse46;
    bool sjt_not4;
    sjs_rect* sjt_parent190 = 0;

    sjt_dot1584 = _parent;
    sjt_parent190 = &(sjt_dot1584)->rect;
    sjt_functionParam488 = rect_;
    sjf_rect_isequal(sjt_parent190, sjt_functionParam488, &sjt_not4);
    result26 = !sjt_not4;
    sjt_ifElse46 = result26;
    if (sjt_ifElse46) {
        sjs_rect* sjt_copy39 = 0;
        sjs_boxelement* sjt_dot1585 = 0;
        sjs_boxelement* sjt_dot1586 = 0;

        sjt_dot1585 = _parent;
        sjt_copy39 = rect_;
        sjt_dot1585->rect._refCount = 1;
        sjf_rect_copy(&sjt_dot1585->rect, sjt_copy39);
        sjt_dot1586 = _parent;
        sjt_dot1586->boxrenderer._refCount = -1;
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

void sjf_color(sjs_color* _this) {
}

void sjf_color_asvec3(sjs_color* _parent, sjs_vec3* _return) {
    sjs_color* sjt_dot1312 = 0;
    sjs_color* sjt_dot1313 = 0;
    sjs_color* sjt_dot1314 = 0;

    _return->_refCount = 1;
    sjt_dot1312 = _parent;
    _return->x = (sjt_dot1312)->r;
    sjt_dot1313 = _parent;
    _return->y = (sjt_dot1313)->g;
    sjt_dot1314 = _parent;
    _return->z = (sjt_dot1314)->b;
    sjf_vec3(_return);
}

void sjf_color_asvec3_heap(sjs_color* _parent, sjs_vec3** _return) {
    sjs_color* sjt_dot1315 = 0;
    sjs_color* sjt_dot1316 = 0;
    sjs_color* sjt_dot1317 = 0;

    (*_return) = (sjs_vec3*)malloc(sizeof(sjs_vec3));
    (*_return)->_refCount = 1;
    sjt_dot1315 = _parent;
    (*_return)->x = (sjt_dot1315)->r;
    sjt_dot1316 = _parent;
    (*_return)->y = (sjt_dot1316)->g;
    sjt_dot1317 = _parent;
    (*_return)->z = (sjt_dot1317)->b;
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

void sjf_console_writeline(sjs_string* data) {
    printf("%s\n", (char*)data->data.data);
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
    }

    _return->_parent = 0;
}

void sjf_crosshairselement_copy(sjs_crosshairselement* _this, sjs_crosshairselement* _from) {
    _this->color._refCount = 1;
    sjf_color_copy(&_this->color, &_from->color);
    _this->_rect._refCount = 1;
    sjf_rect_copy(&_this->_rect, &_from->_rect);
    _this->_topdownrenderer._refCount = 1;
    sjf_boxrenderer_copy((_this->_topdownrenderer._refCount != -1 ? &_this->_topdownrenderer : 0), (_from->_topdownrenderer._refCount != -1 ? &_from->_topdownrenderer : 0));
    _this->_leftrightrenderer._refCount = 1;
    sjf_boxrenderer_copy((_this->_leftrightrenderer._refCount != -1 ? &_this->_leftrightrenderer : 0), (_from->_leftrightrenderer._refCount != -1 ? &_from->_leftrightrenderer : 0));
    _this->_point._refCount = 1;
    sjf_point_copy(&_this->_point, &_from->_point);
}

void sjf_crosshairselement_destroy(sjs_crosshairselement* _this) {
}

void sjf_crosshairselement_firemouseevent(sjs_crosshairselement* _parent, sjs_mouseevent* mouseevent) {
    sjs_crosshairselement* sjt_dot1687 = 0;
    sjs_mouseevent* sjt_dot1688 = 0;
    sjs_point* sjt_functionParam501 = 0;
    bool sjt_ifElse59;
    sjs_rect* sjt_parent203 = 0;

    sjt_dot1687 = _parent;
    sjt_parent203 = &(sjt_dot1687)->_rect;
    sjt_dot1688 = mouseevent;
    sjt_functionParam501 = &(sjt_dot1688)->point;
    sjf_rect_containspoint(sjt_parent203, sjt_functionParam501, &sjt_ifElse59);
    if (sjt_ifElse59) {
        int32_t sjt_compare125;
        int32_t sjt_compare126;
        sjs_mouseevent* sjt_dot1689 = 0;
        bool sjt_ifElse60;

        sjt_dot1689 = mouseevent;
        sjt_compare125 = (sjt_dot1689)->type;
        sjt_compare126 = sjv_mouseeventtype_move;
        sjt_ifElse60 = sjt_compare125 == sjt_compare126;
        if (sjt_ifElse60) {
            sjs_point* sjt_copy53 = 0;
            sjs_crosshairselement* sjt_dot1690 = 0;
            sjs_mouseevent* sjt_dot1691 = 0;
            sjs_crosshairselement* sjt_dot1692 = 0;
            sjs_crosshairselement* sjt_dot1693 = 0;

            sjt_dot1690 = _parent;
            sjt_dot1691 = mouseevent;
            sjt_copy53 = &(sjt_dot1691)->point;
            sjt_dot1690->_point._refCount = 1;
            sjf_point_copy(&sjt_dot1690->_point, sjt_copy53);
            sjt_dot1692 = _parent;
            sjt_dot1692->_topdownrenderer._refCount = -1;
            sjt_dot1693 = _parent;
            sjt_dot1693->_leftrightrenderer._refCount = -1;
        }
    }
}

void sjf_crosshairselement_getrect(sjs_crosshairselement* _parent, sjs_rect* _return) {
    sjs_rect* sjt_copy48 = 0;
    sjs_crosshairselement* sjt_dot1649 = 0;

    sjt_dot1649 = _parent;
    sjt_copy48 = &(sjt_dot1649)->_rect;
    _return->_refCount = 1;
    sjf_rect_copy(_return, sjt_copy48);
}

void sjf_crosshairselement_getrect_heap(sjs_crosshairselement* _parent, sjs_rect** _return) {
    sjs_rect* sjt_copy49 = 0;
    sjs_crosshairselement* sjt_dot1650 = 0;

    sjt_dot1650 = _parent;
    sjt_copy49 = &(sjt_dot1650)->_rect;
    (*_return) = (sjs_rect*)malloc(sizeof(sjs_rect));
    (*_return)->_refCount = 1;
    sjf_rect_copy((*_return), sjt_copy49);
}

void sjf_crosshairselement_getsize(sjs_crosshairselement* _parent, sjs_size* maxsize, sjs_size* _return) {
    sjs_size* sjt_dot1645 = 0;
    sjs_size* sjt_dot1646 = 0;

    _return->_refCount = 1;
    sjt_dot1645 = maxsize;
    _return->w = (sjt_dot1645)->w;
    sjt_dot1646 = maxsize;
    _return->h = (sjt_dot1646)->h;
    sjf_size(_return);
}

void sjf_crosshairselement_getsize_heap(sjs_crosshairselement* _parent, sjs_size* maxsize, sjs_size** _return) {
    sjs_size* sjt_dot1647 = 0;
    sjs_size* sjt_dot1648 = 0;

    (*_return) = (sjs_size*)malloc(sizeof(sjs_size));
    (*_return)->_refCount = 1;
    sjt_dot1647 = maxsize;
    (*_return)->w = (sjt_dot1647)->w;
    sjt_dot1648 = maxsize;
    (*_return)->h = (sjt_dot1648)->h;
    sjf_size_heap((*_return));
}

void sjf_crosshairselement_heap(sjs_crosshairselement* _this) {
}

void sjf_crosshairselement_heap_as_sji_element(sjs_crosshairselement* _this, sji_element* _return) {
    _return->_parent = (sjs_object*)_this;
    _return->_vtbl = &sjs_crosshairselement_element_vtbl;
}

void sjf_crosshairselement_heap_asinterface(sjs_crosshairselement* _this, int typeId, sjs_interface* _return) {
    switch (typeId) {
        case sji_element_typeId:  {
            sjf_crosshairselement_heap_as_sji_element(_this, (sji_element*)_return);
            break;
        }
    }

    _return->_parent = 0;
}

void sjf_crosshairselement_render(sjs_crosshairselement* _parent, sjs_scene2d* scene) {
    sjs_crosshairselement* sjt_dot1655 = 0;
    sjs_crosshairselement* sjt_dot1664 = 0;
    sjs_crosshairselement* sjt_dot1673 = 0;
    sjs_crosshairselement* sjt_dot1675 = 0;
    bool sjt_ifElse55;
    bool sjt_ifElse56;
    bool sjt_ifElse57;
    bool sjt_ifElse58;
    sjs_boxrenderer* sjt_isEmpty16 = 0;
    sjs_boxrenderer* sjt_isEmpty17 = 0;
    sjs_boxrenderer* sjt_isEmpty18 = 0;
    sjs_boxrenderer* sjt_isEmpty19 = 0;

    sjt_dot1655 = _parent;
    sjt_isEmpty16 = ((sjt_dot1655)->_topdownrenderer._refCount != -1 ? &(sjt_dot1655)->_topdownrenderer : 0);
    sjt_ifElse55 = (sjt_isEmpty16 == 0);
    if (sjt_ifElse55) {
        sjs_color* sjt_copy51 = 0;
        sjs_crosshairselement* sjt_dot1656 = 0;
        sjs_point* sjt_dot1657 = 0;
        sjs_crosshairselement* sjt_dot1658 = 0;
        sjs_rect* sjt_dot1659 = 0;
        sjs_crosshairselement* sjt_dot1660 = 0;
        sjs_rect* sjt_dot1661 = 0;
        sjs_crosshairselement* sjt_dot1662 = 0;
        sjs_crosshairselement* sjt_dot1663 = 0;

        sjt_dot1656 = _parent;
        sjt_dot1656->_topdownrenderer._refCount = 1;
        sjt_dot1656->_topdownrenderer.rect._refCount = 1;
        sjt_dot1658 = _parent;
        sjt_dot1657 = &(sjt_dot1658)->_point;
        sjt_dot1656->_topdownrenderer.rect.x = (sjt_dot1657)->x;
        sjt_dot1660 = _parent;
        sjt_dot1659 = &(sjt_dot1660)->_rect;
        sjt_dot1656->_topdownrenderer.rect.y = (sjt_dot1659)->y;
        sjt_dot1656->_topdownrenderer.rect.w = 1;
        sjt_dot1662 = _parent;
        sjt_dot1661 = &(sjt_dot1662)->_rect;
        sjt_dot1656->_topdownrenderer.rect.h = (sjt_dot1661)->h;
        sjf_rect(&sjt_dot1656->_topdownrenderer.rect);
        sjt_dot1663 = _parent;
        sjt_copy51 = &(sjt_dot1663)->color;
        sjt_dot1656->_topdownrenderer.color._refCount = 1;
        sjf_color_copy(&sjt_dot1656->_topdownrenderer.color, sjt_copy51);
        sjf_boxrenderer(&sjt_dot1656->_topdownrenderer);
    }

    sjt_dot1664 = _parent;
    sjt_isEmpty17 = ((sjt_dot1664)->_leftrightrenderer._refCount != -1 ? &(sjt_dot1664)->_leftrightrenderer : 0);
    sjt_ifElse56 = (sjt_isEmpty17 == 0);
    if (sjt_ifElse56) {
        sjs_color* sjt_copy52 = 0;
        sjs_crosshairselement* sjt_dot1665 = 0;
        sjs_rect* sjt_dot1666 = 0;
        sjs_crosshairselement* sjt_dot1667 = 0;
        sjs_point* sjt_dot1668 = 0;
        sjs_crosshairselement* sjt_dot1669 = 0;
        sjs_rect* sjt_dot1670 = 0;
        sjs_crosshairselement* sjt_dot1671 = 0;
        sjs_crosshairselement* sjt_dot1672 = 0;

        sjt_dot1665 = _parent;
        sjt_dot1665->_leftrightrenderer._refCount = 1;
        sjt_dot1665->_leftrightrenderer.rect._refCount = 1;
        sjt_dot1667 = _parent;
        sjt_dot1666 = &(sjt_dot1667)->_rect;
        sjt_dot1665->_leftrightrenderer.rect.x = (sjt_dot1666)->x;
        sjt_dot1669 = _parent;
        sjt_dot1668 = &(sjt_dot1669)->_point;
        sjt_dot1665->_leftrightrenderer.rect.y = (sjt_dot1668)->y;
        sjt_dot1671 = _parent;
        sjt_dot1670 = &(sjt_dot1671)->_rect;
        sjt_dot1665->_leftrightrenderer.rect.w = (sjt_dot1670)->w;
        sjt_dot1665->_leftrightrenderer.rect.h = 1;
        sjf_rect(&sjt_dot1665->_leftrightrenderer.rect);
        sjt_dot1672 = _parent;
        sjt_copy52 = &(sjt_dot1672)->color;
        sjt_dot1665->_leftrightrenderer.color._refCount = 1;
        sjf_color_copy(&sjt_dot1665->_leftrightrenderer.color, sjt_copy52);
        sjf_boxrenderer(&sjt_dot1665->_leftrightrenderer);
    }

    sjt_dot1673 = _parent;
    sjt_isEmpty18 = ((sjt_dot1673)->_topdownrenderer._refCount != -1 ? &(sjt_dot1673)->_topdownrenderer : 0);
    sjt_ifElse57 = (sjt_isEmpty18 != 0);
    if (sjt_ifElse57) {
        sjs_crosshairselement* sjt_dot1674 = 0;
        sjs_scene2d* sjt_functionParam499 = 0;
        sjs_boxrenderer* sjt_parent201 = 0;

        sjt_dot1674 = _parent;
        sjt_parent201 = ((sjt_dot1674)->_topdownrenderer._refCount != -1 ? &(sjt_dot1674)->_topdownrenderer : 0);
        sjt_functionParam499 = scene;
        sjf_boxrenderer_render(sjt_parent201, sjt_functionParam499);
    }

    sjt_dot1675 = _parent;
    sjt_isEmpty19 = ((sjt_dot1675)->_leftrightrenderer._refCount != -1 ? &(sjt_dot1675)->_leftrightrenderer : 0);
    sjt_ifElse58 = (sjt_isEmpty19 != 0);
    if (sjt_ifElse58) {
        sjs_crosshairselement* sjt_dot1676 = 0;
        sjs_scene2d* sjt_functionParam500 = 0;
        sjs_boxrenderer* sjt_parent202 = 0;

        sjt_dot1676 = _parent;
        sjt_parent202 = ((sjt_dot1676)->_leftrightrenderer._refCount != -1 ? &(sjt_dot1676)->_leftrightrenderer : 0);
        sjt_functionParam500 = scene;
        sjf_boxrenderer_render(sjt_parent202, sjt_functionParam500);
    }
}

void sjf_crosshairselement_setrect(sjs_crosshairselement* _parent, sjs_rect* rect_) {
    bool result28;
    sjs_crosshairselement* sjt_dot1651 = 0;
    sjs_rect* sjt_functionParam498 = 0;
    bool sjt_ifElse54;
    bool sjt_not6;
    sjs_rect* sjt_parent200 = 0;

    sjt_dot1651 = _parent;
    sjt_parent200 = &(sjt_dot1651)->_rect;
    sjt_functionParam498 = rect_;
    sjf_rect_isequal(sjt_parent200, sjt_functionParam498, &sjt_not6);
    result28 = !sjt_not6;
    sjt_ifElse54 = result28;
    if (sjt_ifElse54) {
        sjs_rect* sjt_copy50 = 0;
        sjs_crosshairselement* sjt_dot1652 = 0;
        sjs_crosshairselement* sjt_dot1653 = 0;
        sjs_crosshairselement* sjt_dot1654 = 0;

        sjt_dot1652 = _parent;
        sjt_copy50 = rect_;
        sjt_dot1652->_rect._refCount = 1;
        sjf_rect_copy(&sjt_dot1652->_rect, sjt_copy50);
        sjt_dot1653 = _parent;
        sjt_dot1653->_topdownrenderer._refCount = -1;
        sjt_dot1654 = _parent;
        sjt_dot1654->_leftrightrenderer._refCount = -1;
    }
}

void sjf_f32_ceil(float v, float* _return) {
    float sjv_x;

    sjv_x = 0.0f;
    sjv_x = ceilf(v);
    (*_return) = sjv_x;
}

void sjf_f32_compare(float l, float r, int32_t* _return) {
    float sjt_compare29;
    float sjt_compare30;
    bool sjt_ifElse6;

    sjt_compare29 = l;
    sjt_compare30 = r;
    sjt_ifElse6 = sjt_compare29 == sjt_compare30;
    if (sjt_ifElse6) {
        (*_return) = 0;
    } else {
        float sjt_compare31;
        float sjt_compare32;
        bool sjt_ifElse7;

        sjt_compare31 = l;
        sjt_compare32 = r;
        sjt_ifElse7 = sjt_compare31 < sjt_compare32;
        if (sjt_ifElse7) {
            int32_t result3;
            int32_t sjt_negate2;

            sjt_negate2 = 1;
            result3 = -sjt_negate2;
            (*_return) = result3;
        } else {
            (*_return) = 1;
        }
    }
}

void sjf_f32_cos(float v, float* _return) {
    float sjv_result;

    sjv_result = 0.0f;
    sjv_result = cosf(v);
    (*_return) = sjv_result;
}

void sjf_f32_floor(float v, float* _return) {
    float sjv_x;

    sjv_x = 0.0f;
    sjv_x = floorf(v);
    (*_return) = sjv_x;
}

void sjf_f32_max(float a, float b, float* _return) {
    float sjt_compare39;
    float sjt_compare40;
    bool sjt_ifElse10;

    sjt_compare39 = a;
    sjt_compare40 = b;
    sjt_ifElse10 = sjt_compare39 < sjt_compare40;
    if (sjt_ifElse10) {
        (*_return) = b;
    } else {
        (*_return) = a;
    }
}

void sjf_f32_min(float a, float b, float* _return) {
    float sjt_compare37;
    float sjt_compare38;
    bool sjt_ifElse9;

    sjt_compare37 = a;
    sjt_compare38 = b;
    sjt_ifElse9 = sjt_compare37 < sjt_compare38;
    if (sjt_ifElse9) {
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

void sjf_f32_tostring(float val, sjs_string* _return) {
    int32_t sjt_math2141;
    int32_t sjt_math2142;
    int32_t sjt_math2143;
    int32_t sjt_math2144;
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
    sjt_math2141 = sjv_count;
    sjt_math2142 = 1;
    _return->data.datasize = sjt_math2141 + sjt_math2142;
    _return->data.data = sjv_data;
    _return->data._isglobal = false;
    sjt_math2143 = sjv_count;
    sjt_math2144 = 1;
    _return->data.count = sjt_math2143 + sjt_math2144;
    sjf_array_char(&_return->data);
    sjf_string(_return);
}

void sjf_f32_tostring_heap(float val, sjs_string** _return) {
    int32_t sjt_math2145;
    int32_t sjt_math2146;
    int32_t sjt_math2147;
    int32_t sjt_math2148;
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
    sjt_math2145 = sjv_count;
    sjt_math2146 = 1;
    (*_return)->data.datasize = sjt_math2145 + sjt_math2146;
    (*_return)->data.data = sjv_data;
    (*_return)->data._isglobal = false;
    sjt_math2147 = sjv_count;
    sjt_math2148 = 1;
    (*_return)->data.count = sjt_math2147 + sjt_math2148;
    sjf_array_char(&(*_return)->data);
    sjf_string_heap((*_return));
}

void sjf_fillelement(sjs_fillelement* _this) {
}

void sjf_fillelement_as_sji_element(sjs_fillelement* _this, sji_element* _return) {
    _return->_parent = (sjs_object*)_this;
    _return->_vtbl = &sjs_fillelement_element_vtbl;
}

void sjf_fillelement_asinterface(sjs_fillelement* _this, int typeId, sjs_interface* _return) {
    switch (typeId) {
        case sji_element_typeId:  {
            sjf_fillelement_as_sji_element(_this, (sji_element*)_return);
            break;
        }
    }

    _return->_parent = 0;
}

void sjf_fillelement_copy(sjs_fillelement* _this, sjs_fillelement* _from) {
    _this->children._refCount = 1;
    sjf_array_heap_iface_element_copy(&_this->children, &_from->children);
    _this->_rect._refCount = 1;
    sjf_rect_copy(&_this->_rect, &_from->_rect);
}

void sjf_fillelement_destroy(sjs_fillelement* _this) {
}

void sjf_fillelement_firemouseevent(sjs_fillelement* _parent, sjs_mouseevent* mouseevent) {
    int32_t i;
    sjs_array_heap_iface_element* sjt_dot17 = 0;
    sjs_fillelement* sjt_dot18 = 0;
    int32_t sjt_forEnd3;
    int32_t sjt_forStart3;

    sjt_forStart3 = 0;
    sjt_dot18 = _parent;
    sjt_dot17 = &(sjt_dot18)->children;
    sjt_forEnd3 = (sjt_dot17)->count;
    i = sjt_forStart3;
    while (i < sjt_forEnd3) {
        sjs_fillelement* sjt_dot19 = 0;
        int32_t sjt_functionParam4;
        sjs_mouseevent* sjt_interfaceParam3 = 0;
        sjs_array_heap_iface_element* sjt_parent6 = 0;
        sji_element sjt_parent7 = { 0 };
        sji_element sjv_child = { 0 };

        sjt_dot19 = _parent;
        sjt_parent6 = &(sjt_dot19)->children;
        sjt_functionParam4 = i;
        sjf_array_heap_iface_element_getat_heap(sjt_parent6, sjt_functionParam4, &sjv_child);
        sjt_parent7 = sjv_child;
        sjt_interfaceParam3 = mouseevent;
        sjt_parent7._vtbl->firemouseevent(sjt_parent7._parent, sjt_interfaceParam3);
        i++;

        if (sjv_child._parent != 0) {
            sjv_child._parent->_refCount--;
            if (sjv_child._parent->_refCount <= 0) {
                sjv_child._vtbl->destroy(sjv_child._parent);
            }
        }
    }
}

void sjf_fillelement_getrect(sjs_fillelement* _parent, sjs_rect* _return) {
    sjs_rect* sjt_copy1 = 0;
    sjs_fillelement* sjt_dot7 = 0;

    sjt_dot7 = _parent;
    sjt_copy1 = &(sjt_dot7)->_rect;
    _return->_refCount = 1;
    sjf_rect_copy(_return, sjt_copy1);
}

void sjf_fillelement_getrect_heap(sjs_fillelement* _parent, sjs_rect** _return) {
    sjs_rect* sjt_copy2 = 0;
    sjs_fillelement* sjt_dot8 = 0;

    sjt_dot8 = _parent;
    sjt_copy2 = &(sjt_dot8)->_rect;
    (*_return) = (sjs_rect*)malloc(sizeof(sjs_rect));
    (*_return)->_refCount = 1;
    sjf_rect_copy((*_return), sjt_copy2);
}

void sjf_fillelement_getsize(sjs_fillelement* _parent, sjs_size* maxsize, sjs_size* _return) {
    sjs_size* sjt_dot3 = 0;
    sjs_size* sjt_dot4 = 0;

    _return->_refCount = 1;
    sjt_dot3 = maxsize;
    _return->w = (sjt_dot3)->w;
    sjt_dot4 = maxsize;
    _return->h = (sjt_dot4)->h;
    sjf_size(_return);
}

void sjf_fillelement_getsize_heap(sjs_fillelement* _parent, sjs_size* maxsize, sjs_size** _return) {
    sjs_size* sjt_dot5 = 0;
    sjs_size* sjt_dot6 = 0;

    (*_return) = (sjs_size*)malloc(sizeof(sjs_size));
    (*_return)->_refCount = 1;
    sjt_dot5 = maxsize;
    (*_return)->w = (sjt_dot5)->w;
    sjt_dot6 = maxsize;
    (*_return)->h = (sjt_dot6)->h;
    sjf_size_heap((*_return));
}

void sjf_fillelement_heap(sjs_fillelement* _this) {
}

void sjf_fillelement_heap_as_sji_element(sjs_fillelement* _this, sji_element* _return) {
    _return->_parent = (sjs_object*)_this;
    _return->_vtbl = &sjs_fillelement_element_vtbl;
}

void sjf_fillelement_heap_asinterface(sjs_fillelement* _this, int typeId, sjs_interface* _return) {
    switch (typeId) {
        case sji_element_typeId:  {
            sjf_fillelement_heap_as_sji_element(_this, (sji_element*)_return);
            break;
        }
    }

    _return->_parent = 0;
}

void sjf_fillelement_render(sjs_fillelement* _parent, sjs_scene2d* scene) {
    int32_t i;
    sjs_array_heap_iface_element* sjt_dot14 = 0;
    sjs_fillelement* sjt_dot15 = 0;
    int32_t sjt_forEnd2;
    int32_t sjt_forStart2;

    sjt_forStart2 = 0;
    sjt_dot15 = _parent;
    sjt_dot14 = &(sjt_dot15)->children;
    sjt_forEnd2 = (sjt_dot14)->count;
    i = sjt_forStart2;
    while (i < sjt_forEnd2) {
        sjs_fillelement* sjt_dot16 = 0;
        int32_t sjt_functionParam3;
        sjs_scene2d* sjt_interfaceParam2 = 0;
        sjs_array_heap_iface_element* sjt_parent4 = 0;
        sji_element sjt_parent5 = { 0 };
        sji_element sjv_child = { 0 };

        sjt_dot16 = _parent;
        sjt_parent4 = &(sjt_dot16)->children;
        sjt_functionParam3 = i;
        sjf_array_heap_iface_element_getat_heap(sjt_parent4, sjt_functionParam3, &sjv_child);
        sjt_parent5 = sjv_child;
        sjt_interfaceParam2 = scene;
        sjt_parent5._vtbl->render(sjt_parent5._parent, sjt_interfaceParam2);
        i++;

        if (sjv_child._parent != 0) {
            sjv_child._parent->_refCount--;
            if (sjv_child._parent->_refCount <= 0) {
                sjv_child._vtbl->destroy(sjv_child._parent);
            }
        }
    }
}

void sjf_fillelement_setrect(sjs_fillelement* _parent, sjs_rect* rect_) {
    int32_t i;
    sjs_rect* sjt_copy3 = 0;
    sjs_array_heap_iface_element* sjt_dot10 = 0;
    sjs_fillelement* sjt_dot11 = 0;
    sjs_fillelement* sjt_dot9 = 0;
    int32_t sjt_forEnd1;
    int32_t sjt_forStart1;

    sjt_dot9 = _parent;
    sjt_copy3 = rect_;
    sjt_dot9->_rect._refCount = 1;
    sjf_rect_copy(&sjt_dot9->_rect, sjt_copy3);
    sjt_forStart1 = 0;
    sjt_dot11 = _parent;
    sjt_dot10 = &(sjt_dot11)->children;
    sjt_forEnd1 = (sjt_dot10)->count;
    i = sjt_forStart1;
    while (i < sjt_forEnd1) {
        sjs_fillelement* sjt_dot12 = 0;
        sjs_fillelement* sjt_dot13 = 0;
        int32_t sjt_functionParam2;
        sjs_rect* sjt_interfaceParam1 = 0;
        sjs_array_heap_iface_element* sjt_parent2 = 0;
        sji_element sjt_parent3 = { 0 };
        sji_element sjv_child = { 0 };

        sjt_dot12 = _parent;
        sjt_parent2 = &(sjt_dot12)->children;
        sjt_functionParam2 = i;
        sjf_array_heap_iface_element_getat_heap(sjt_parent2, sjt_functionParam2, &sjv_child);
        sjt_parent3 = sjv_child;
        sjt_dot13 = _parent;
        sjt_interfaceParam1 = &(sjt_dot13)->_rect;
        sjt_parent3._vtbl->setrect(sjt_parent3._parent, sjt_interfaceParam1);
        i++;

        if (sjv_child._parent != 0) {
            sjv_child._parent->_refCount--;
            if (sjv_child._parent->_refCount <= 0) {
                sjv_child._vtbl->destroy(sjv_child._parent);
            }
        }
    }
}

void sjf_framebuffer(sjs_framebuffer* _this) {
}

void sjf_framebuffer_copy(sjs_framebuffer* _this, sjs_framebuffer* _from) {
    _this->id = _from->id;
    _this->id = _from->id;
    glid_retain(_this->id);
}

void sjf_framebuffer_destroy(sjs_framebuffer* _this) {
    if (glid_release(_this->id)) {
        glDeleteFramebuffers(1, &_this->id);
    }
}

void sjf_framebuffer_heap(sjs_framebuffer* _this) {
}

void sjf_glbindframebuffer(sjs_framebuffer* framebuffer) {
    glBindFramebuffer(GL_FRAMEBUFFER, framebuffer->id);
}

void sjf_glbindrenderbuffer(sjs_renderbuffer* renderbuffer) {
    glBindRenderbuffer(GL_RENDERBUFFER, renderbuffer->id);
}

void sjf_glbindtexture(int32_t type, sjs_texture* texture) {
    glBindTexture(type, texture->id);
}

void sjf_glcheckframebufferstatus(int32_t* _return) {
    int32_t sjv_status;

    sjv_status = sjv_glframebufferstatus_gl_framebuffer_unsupported;
    sjv_status = glCheckFramebufferStatus(GL_FRAMEBUFFER);
    (*_return) = sjv_status;
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

void sjf_glgenframebuffer(sjs_framebuffer* _return) {
    uint32_t sjv_id;

    sjv_id = (uint32_t)0u;
    glGenFramebuffers(1, &sjv_id);
    _return->_refCount = 1;
    _return->id = sjv_id;
    sjf_framebuffer(_return);
}

void sjf_glgenframebuffer_heap(sjs_framebuffer** _return) {
    uint32_t sjv_id;

    sjv_id = (uint32_t)0u;
    glGenFramebuffers(1, &sjv_id);
    (*_return) = (sjs_framebuffer*)malloc(sizeof(sjs_framebuffer));
    (*_return)->_refCount = 1;
    (*_return)->id = sjv_id;
    sjf_framebuffer_heap((*_return));
}

void sjf_glgenrenderbuffer(sjs_size* size, sjs_renderbuffer* _return) {
    sjs_size* sjt_copy24 = 0;
    uint32_t sjv_id;

    sjv_id = (uint32_t)0u;
    glGenRenderbuffers(1, &sjv_id); 
    _return->_refCount = 1;
    sjt_copy24 = size;
    _return->size._refCount = 1;
    sjf_size_copy(&_return->size, sjt_copy24);
    _return->id = sjv_id;
    sjf_renderbuffer(_return);
}

void sjf_glgenrenderbuffer_heap(sjs_size* size, sjs_renderbuffer** _return) {
    sjs_size* sjt_copy25 = 0;
    uint32_t sjv_id;

    sjv_id = (uint32_t)0u;
    glGenRenderbuffers(1, &sjv_id); 
    (*_return) = (sjs_renderbuffer*)malloc(sizeof(sjs_renderbuffer));
    (*_return)->_refCount = 1;
    sjt_copy25 = size;
    (*_return)->size._refCount = 1;
    sjf_size_copy(&(*_return)->size, sjt_copy25);
    (*_return)->id = sjv_id;
    sjf_renderbuffer_heap((*_return));
}

void sjf_glgentexture(sjs_size* size, sjs_texture* _return) {
    sjs_size* sjt_copy22 = 0;
    uint32_t sjv_id;

    sjv_id = (uint32_t)0u;
    glGenTextures(1, &sjv_id);
    _return->_refCount = 1;
    sjt_copy22 = size;
    _return->size._refCount = 1;
    sjf_size_copy(&_return->size, sjt_copy22);
    _return->id = sjv_id;
    sjf_texture(_return);
}

void sjf_glgentexture_heap(sjs_size* size, sjs_texture** _return) {
    sjs_size* sjt_copy23 = 0;
    uint32_t sjv_id;

    sjv_id = (uint32_t)0u;
    glGenTextures(1, &sjv_id);
    (*_return) = (sjs_texture*)malloc(sizeof(sjs_texture));
    (*_return)->_refCount = 1;
    sjt_copy23 = size;
    (*_return)->size._refCount = 1;
    sjf_size_copy(&(*_return)->size, sjt_copy23);
    (*_return)->id = sjv_id;
    sjf_texture_heap((*_return));
}

void sjf_glgetuniformlocation(sjs_shader* shader, sjs_string* name, int32_t* _return) {
    int result = glGetUniformLocation(shader->id, (char*)name->data.data);
    (*_return) = result;
return;;
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

void sjf_glunbindframebuffer(void) {
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
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

void sjf_glviewport(sjs_rect* rect) {
    glViewport(rect->x, rect->y, rect->w, rect->h);
}

void sjf_halt(sjs_string* reason) {
    halt("%s\n", (char*)reason->data.data);
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

void sjf_hash_string_weak_iface_model_setat(sjs_hash_string_weak_iface_model* _parent, sjs_string* key, sji_model val) {
    khash_t(string_weak_iface_model_hash_type)* p = (khash_t(string_weak_iface_model_hash_type)*)_parent->_hash;
    #if true
    khiter_t k = kh_get(string_weak_iface_model_hash_type, p, *key);
    #else
    khiter_t k = kh_get(string_weak_iface_model_hash_type, p, key);
    #endif
    if (k != kh_end(p)) {            
    delete_cb weakptrcb9 = { &kh_val(p, k)._parent, weakptr_clear };
if (kh_val(p, k)._parent != 0) { weakptr_cb_remove(kh_val(p, k)._parent, weakptrcb9); }
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
delete_cb weakptrcb10 = { &kh_val(p, k)._parent, weakptr_clear };
if (kh_val(p, k)._parent != 0) { weakptr_cb_add(kh_val(p, k)._parent, weakptrcb10); }
;
#endif
}

void sjf_i32_max(int32_t a, int32_t b, int32_t* _return) {
    int32_t sjt_compare47;
    int32_t sjt_compare48;
    bool sjt_ifElse15;

    sjt_compare47 = a;
    sjt_compare48 = b;
    sjt_ifElse15 = sjt_compare47 < sjt_compare48;
    if (sjt_ifElse15) {
        (*_return) = b;
    } else {
        (*_return) = a;
    }
}

void sjf_image(sjs_image* _this) {
    bool sjt_and10;
    bool sjt_and9;
    sjs_rect sjt_call83 = { -1 };
    int32_t sjt_compare109;
    int32_t sjt_compare110;
    int32_t sjt_compare111;
    int32_t sjt_compare112;
    sjs_rect* sjt_dot1629 = 0;
    sjs_rect* sjt_dot1630 = 0;
    bool sjt_ifElse52;
    sjs_size sjv_size = { -1 };

    sjt_dot1629 = &_this->rect;
    sjt_compare109 = (sjt_dot1629)->w;
    sjt_compare110 = 0;
    sjt_and9 = sjt_compare109 == sjt_compare110;
    sjt_dot1630 = &_this->rect;
    sjt_compare111 = (sjt_dot1630)->h;
    sjt_compare112 = 0;
    sjt_and10 = sjt_compare111 == sjt_compare112;
    sjt_ifElse52 = sjt_and9 && sjt_and10;
    if (sjt_ifElse52) {
        sjs_rect* sjt_copy46 = 0;
        sjs_size* sjt_dot1639 = 0;
        sjs_size* sjt_dot1640 = 0;
        sjs_texture* sjt_parent197 = 0;

        sjt_parent197 = &_this->texture;
        sjf_texture_getsize(sjt_parent197, &sjv_size);
        sjt_call83._refCount = 1;
        sjt_call83.x = 0;
        sjt_call83.y = 0;
        sjt_dot1639 = &sjv_size;
        sjt_call83.w = (sjt_dot1639)->w;
        sjt_dot1640 = &sjv_size;
        sjt_call83.h = (sjt_dot1640)->h;
        sjf_rect(&sjt_call83);
        sjt_copy46 = &sjt_call83;
        _this->rect._refCount = 1;
        sjf_rect_copy(&_this->rect, sjt_copy46);
    }

    if (sjt_call83._refCount == 1) { sjf_rect_destroy(&sjt_call83); }
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
    bool sjt_and11;
    bool sjt_and12;
    sjs_rect sjt_call84 = { -1 };
    int32_t sjt_compare113;
    int32_t sjt_compare114;
    int32_t sjt_compare115;
    int32_t sjt_compare116;
    sjs_rect* sjt_dot1641 = 0;
    sjs_rect* sjt_dot1642 = 0;
    bool sjt_ifElse53;
    sjs_size sjv_size = { -1 };

    sjt_dot1641 = &_this->rect;
    sjt_compare113 = (sjt_dot1641)->w;
    sjt_compare114 = 0;
    sjt_and11 = sjt_compare113 == sjt_compare114;
    sjt_dot1642 = &_this->rect;
    sjt_compare115 = (sjt_dot1642)->h;
    sjt_compare116 = 0;
    sjt_and12 = sjt_compare115 == sjt_compare116;
    sjt_ifElse53 = sjt_and11 && sjt_and12;
    if (sjt_ifElse53) {
        sjs_rect* sjt_copy47 = 0;
        sjs_size* sjt_dot1643 = 0;
        sjs_size* sjt_dot1644 = 0;
        sjs_texture* sjt_parent198 = 0;

        sjt_parent198 = &_this->texture;
        sjf_texture_getsize(sjt_parent198, &sjv_size);
        sjt_call84._refCount = 1;
        sjt_call84.x = 0;
        sjt_call84.y = 0;
        sjt_dot1643 = &sjv_size;
        sjt_call84.w = (sjt_dot1643)->w;
        sjt_dot1644 = &sjv_size;
        sjt_call84.h = (sjt_dot1644)->h;
        sjf_rect(&sjt_call84);
        sjt_copy47 = &sjt_call84;
        _this->rect._refCount = 1;
        sjf_rect_copy(&_this->rect, sjt_copy47);
    }

    if (sjt_call84._refCount == 1) { sjf_rect_destroy(&sjt_call84); }
    if (sjv_size._refCount == 1) { sjf_size_destroy(&sjv_size); }
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
    }

    _return->_parent = 0;
}

void sjf_imageelement_copy(sjs_imageelement* _this, sjs_imageelement* _from) {
    _this->image._refCount = 1;
    sjf_image_copy(&_this->image, &_from->image);
    _this->_rect._refCount = 1;
    sjf_rect_copy(&_this->_rect, &_from->_rect);
    _this->_margin._refCount = 1;
    sjf_margin_copy(&_this->_margin, &_from->_margin);
    _this->_imagerenderer._refCount = 1;
    sjf_imagerenderer_copy((_this->_imagerenderer._refCount != -1 ? &_this->_imagerenderer : 0), (_from->_imagerenderer._refCount != -1 ? &_from->_imagerenderer : 0));
}

void sjf_imageelement_destroy(sjs_imageelement* _this) {
}

void sjf_imageelement_firemouseevent(sjs_imageelement* _parent, sjs_mouseevent* mouseevent) {
}

void sjf_imageelement_getrect(sjs_imageelement* _parent, sjs_rect* _return) {
    sjs_rect* sjt_copy42 = 0;
    sjs_imageelement* sjt_dot1597 = 0;

    sjt_dot1597 = _parent;
    sjt_copy42 = &(sjt_dot1597)->_rect;
    _return->_refCount = 1;
    sjf_rect_copy(_return, sjt_copy42);
}

void sjf_imageelement_getrect_heap(sjs_imageelement* _parent, sjs_rect** _return) {
    sjs_rect* sjt_copy43 = 0;
    sjs_imageelement* sjt_dot1598 = 0;

    sjt_dot1598 = _parent;
    sjt_copy43 = &(sjt_dot1598)->_rect;
    (*_return) = (sjs_rect*)malloc(sizeof(sjs_rect));
    (*_return)->_refCount = 1;
    sjf_rect_copy((*_return), sjt_copy43);
}

void sjf_imageelement_getsize(sjs_imageelement* _parent, sjs_size* maxsize, sjs_size* _return) {
    sjs_size* sjt_dot1593 = 0;
    sjs_size* sjt_dot1594 = 0;

    _return->_refCount = 1;
    sjt_dot1593 = maxsize;
    _return->w = (sjt_dot1593)->w;
    sjt_dot1594 = maxsize;
    _return->h = (sjt_dot1594)->h;
    sjf_size(_return);
}

void sjf_imageelement_getsize_heap(sjs_imageelement* _parent, sjs_size* maxsize, sjs_size** _return) {
    sjs_size* sjt_dot1595 = 0;
    sjs_size* sjt_dot1596 = 0;

    (*_return) = (sjs_size*)malloc(sizeof(sjs_size));
    (*_return)->_refCount = 1;
    sjt_dot1595 = maxsize;
    (*_return)->w = (sjt_dot1595)->w;
    sjt_dot1596 = maxsize;
    (*_return)->h = (sjt_dot1596)->h;
    sjf_size_heap((*_return));
}

void sjf_imageelement_heap(sjs_imageelement* _this) {
}

void sjf_imageelement_heap_as_sji_element(sjs_imageelement* _this, sji_element* _return) {
    _return->_parent = (sjs_object*)_this;
    _return->_vtbl = &sjs_imageelement_element_vtbl;
}

void sjf_imageelement_heap_asinterface(sjs_imageelement* _this, int typeId, sjs_interface* _return) {
    switch (typeId) {
        case sji_element_typeId:  {
            sjf_imageelement_heap_as_sji_element(_this, (sji_element*)_return);
            break;
        }
    }

    _return->_parent = 0;
}

void sjf_imageelement_render(sjs_imageelement* _parent, sjs_scene2d* scene) {
    sjs_imageelement* sjt_dot1602 = 0;
    sjs_imageelement* sjt_dot1627 = 0;
    bool sjt_ifElse50;
    bool sjt_ifElse51;
    sjs_imagerenderer* sjt_isEmpty14 = 0;
    sjs_imagerenderer* sjt_isEmpty15 = 0;

    sjt_dot1602 = _parent;
    sjt_isEmpty14 = ((sjt_dot1602)->_imagerenderer._refCount != -1 ? &(sjt_dot1602)->_imagerenderer : 0);
    sjt_ifElse50 = (sjt_isEmpty14 == 0);
    if (sjt_ifElse50) {
        sjs_image* sjt_copy45 = 0;
        sjs_imageelement* sjt_dot1603 = 0;
        sjs_imageelement* sjt_dot1624 = 0;
        sjs_imageelement* sjt_dot1625 = 0;
        sjs_imageelement* sjt_dot1626 = 0;
        sjs_margin* sjt_functionParam493 = 0;
        sjs_rect* sjt_parent195 = 0;

        sjt_dot1603 = _parent;
        sjt_dot1603->_imagerenderer._refCount = 1;
        sjt_dot1624 = _parent;
        sjt_parent195 = &(sjt_dot1624)->_rect;
        sjt_dot1625 = _parent;
        sjt_functionParam493 = &(sjt_dot1625)->_margin;
        sjf_rect_subtractmargin(sjt_parent195, sjt_functionParam493, &sjt_dot1603->_imagerenderer.rect);
        sjt_dot1626 = _parent;
        sjt_copy45 = &(sjt_dot1626)->image;
        sjt_dot1603->_imagerenderer.image._refCount = 1;
        sjf_image_copy(&sjt_dot1603->_imagerenderer.image, sjt_copy45);
        sjf_imagerenderer(&sjt_dot1603->_imagerenderer);
    }

    sjt_dot1627 = _parent;
    sjt_isEmpty15 = ((sjt_dot1627)->_imagerenderer._refCount != -1 ? &(sjt_dot1627)->_imagerenderer : 0);
    sjt_ifElse51 = (sjt_isEmpty15 != 0);
    if (sjt_ifElse51) {
        sjs_imageelement* sjt_dot1628 = 0;
        sjs_scene2d* sjt_functionParam494 = 0;
        sjs_imagerenderer* sjt_parent196 = 0;

        sjt_dot1628 = _parent;
        sjt_parent196 = ((sjt_dot1628)->_imagerenderer._refCount != -1 ? &(sjt_dot1628)->_imagerenderer : 0);
        sjt_functionParam494 = scene;
        sjf_imagerenderer_render(sjt_parent196, sjt_functionParam494);
    }
}

void sjf_imageelement_setrect(sjs_imageelement* _parent, sjs_rect* rect_) {
    bool result27;
    sjs_imageelement* sjt_dot1599 = 0;
    sjs_rect* sjt_functionParam492 = 0;
    bool sjt_ifElse49;
    bool sjt_not5;
    sjs_rect* sjt_parent194 = 0;

    sjt_dot1599 = _parent;
    sjt_parent194 = &(sjt_dot1599)->_rect;
    sjt_functionParam492 = rect_;
    sjf_rect_isequal(sjt_parent194, sjt_functionParam492, &sjt_not5);
    result27 = !sjt_not5;
    sjt_ifElse49 = result27;
    if (sjt_ifElse49) {
        sjs_rect* sjt_copy44 = 0;
        sjs_imageelement* sjt_dot1600 = 0;
        sjs_imageelement* sjt_dot1601 = 0;

        sjt_dot1600 = _parent;
        sjt_copy44 = rect_;
        sjt_dot1600->_rect._refCount = 1;
        sjf_rect_copy(&sjt_dot1600->_rect, sjt_copy44);
        sjt_dot1601 = _parent;
        sjt_dot1601->_imagerenderer._refCount = -1;
    }
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
    glBindTexture(GL_TEXTURE_2D, _parent->image.texture.id);
    glUseProgram(sjv_imageshader.id);
    glUniform1i(glGetUniformLocation(sjv_imageshader.id, "texture" ), 0 );
    glUniformMatrix4fv(glGetUniformLocation(sjv_imageshader.id, "model" ), 1, 0, (GLfloat*)&scene->model.m00);
    glUniformMatrix4fv(glGetUniformLocation(sjv_imageshader.id, "view" ), 1, 0, (GLfloat*)&scene->view.m00);
    glUniformMatrix4fv(glGetUniformLocation(sjv_imageshader.id, "projection" ), 1, 0, (GLfloat*)&scene->projection.m00);
    vertex_buffer_render(_parent->buffer, GL_TRIANGLES);
}

void sjf_intersecttriangle(sjs_vec3* orig, sjs_vec3* dir, sjs_vec3* v0, sjs_vec3* v1, sjs_vec3* v2, sjs_vec3* _return) {
    float sjt_compare73;
    float sjt_compare74;
    float sjt_compare75;
    float sjt_compare76;
    sjs_vec3* sjt_functionParam408 = 0;
    sjs_vec3* sjt_functionParam409 = 0;
    sjs_vec3* sjt_functionParam410 = 0;
    sjs_vec3* sjt_functionParam411 = 0;
    bool sjt_ifElse28;
    bool sjt_ifElse29;
    sjs_vec3* sjt_parent160 = 0;
    sjs_vec3* sjt_parent161 = 0;
    sjs_vec3* sjt_parent162 = 0;
    sjs_vec3* sjt_parent163 = 0;
    float sjv_det;
    sjs_vec3 sjv_edge1 = { -1 };
    sjs_vec3 sjv_edge2 = { -1 };
    sjs_vec3 sjv_pvec = { -1 };
    sjs_vec3 sjv_qvec = { -1 };
    sjs_vec3 sjv_tvec = { -1 };

    sjt_parent160 = v1;
    sjt_functionParam408 = v0;
    sjf_vec3_subtract(sjt_parent160, sjt_functionParam408, &sjv_edge1);
    sjt_parent161 = v2;
    sjt_functionParam409 = v0;
    sjf_vec3_subtract(sjt_parent161, sjt_functionParam409, &sjv_edge2);
    sjt_parent162 = dir;
    sjt_functionParam410 = &sjv_edge2;
    sjf_vec3_cross(sjt_parent162, sjt_functionParam410, &sjv_pvec);
    sjt_parent163 = &sjv_edge1;
    sjt_functionParam411 = &sjv_pvec;
    sjf_vec3_dot(sjt_parent163, sjt_functionParam411, &sjv_det);
    sjt_compare73 = sjv_det;
    sjt_compare74 = 0.0f;
    sjt_ifElse28 = sjt_compare73 > sjt_compare74;
    if (sjt_ifElse28) {
        sjs_vec3* sjt_functionParam412 = 0;
        sjs_vec3* sjt_parent164 = 0;

        sjt_parent164 = orig;
        sjt_functionParam412 = v0;
        sjf_vec3_subtract(sjt_parent164, sjt_functionParam412, &sjv_tvec);
    } else {
        sjs_vec3* sjt_functionParam413 = 0;
        float sjt_math2347;
        float sjt_math2348;
        sjs_vec3* sjt_parent165 = 0;

        sjt_math2347 = 0.0f;
        sjt_math2348 = sjv_det;
        sjv_det = sjt_math2347 - sjt_math2348;
        sjt_parent165 = v0;
        sjt_functionParam413 = orig;
        sjf_vec3_subtract(sjt_parent165, sjt_functionParam413, &sjv_tvec);
    }

    sjt_compare75 = sjv_det;
    sjt_compare76 = 0.0001f;
    sjt_ifElse29 = sjt_compare75 < sjt_compare76;
    if (sjt_ifElse29) {
        _return->_refCount = -1;
    } else {
        float sjt_compare77;
        float sjt_compare78;
        float sjt_compare79;
        float sjt_compare80;
        sjs_vec3* sjt_functionParam414 = 0;
        bool sjt_ifElse30;
        bool sjt_or1;
        bool sjt_or2;
        sjs_vec3* sjt_parent166 = 0;
        float sjv_u;

        sjt_parent166 = &sjv_tvec;
        sjt_functionParam414 = &sjv_pvec;
        sjf_vec3_dot(sjt_parent166, sjt_functionParam414, &sjv_u);
        sjt_compare77 = sjv_u;
        sjt_compare78 = 0.0f;
        sjt_or1 = sjt_compare77 < sjt_compare78;
        sjt_compare79 = sjv_u;
        sjt_compare80 = sjv_det;
        sjt_or2 = sjt_compare79 > sjt_compare80;
        sjt_ifElse30 = sjt_or1 || sjt_or2;
        if (sjt_ifElse30) {
            _return->_refCount = -1;
        } else {
            float sjt_compare81;
            float sjt_compare82;
            float sjt_compare83;
            float sjt_compare84;
            sjs_vec3* sjt_functionParam415 = 0;
            sjs_vec3* sjt_functionParam416 = 0;
            bool sjt_ifElse31;
            float sjt_math2349;
            float sjt_math2350;
            bool sjt_or3;
            bool sjt_or4;
            sjs_vec3* sjt_parent167 = 0;
            sjs_vec3* sjt_parent168 = 0;
            float sjv_v;

            sjt_parent167 = &sjv_tvec;
            sjt_functionParam415 = &sjv_edge1;
            sjf_vec3_cross(sjt_parent167, sjt_functionParam415, &sjv_qvec);
            sjt_parent168 = dir;
            sjt_functionParam416 = &sjv_qvec;
            sjf_vec3_dot(sjt_parent168, sjt_functionParam416, &sjv_v);
            sjt_compare81 = sjv_v;
            sjt_compare82 = 0.0f;
            sjt_or3 = sjt_compare81 < sjt_compare82;
            sjt_math2349 = sjv_u;
            sjt_math2350 = sjv_v;
            sjt_compare83 = sjt_math2349 + sjt_math2350;
            sjt_compare84 = sjv_det;
            sjt_or4 = sjt_compare83 > sjt_compare84;
            sjt_ifElse31 = sjt_or3 || sjt_or4;
            if (sjt_ifElse31) {
                _return->_refCount = -1;
            } else {
                sjs_vec3* sjt_functionParam417 = 0;
                float sjt_math2351;
                float sjt_math2352;
                float sjt_math2353;
                float sjt_math2354;
                float sjt_math2355;
                float sjt_math2356;
                float sjt_math2357;
                float sjt_math2358;
                sjs_vec3* sjt_parent169 = 0;
                float sjv_finvdet;
                float sjv_t;

                sjt_parent169 = &sjv_edge2;
                sjt_functionParam417 = &sjv_qvec;
                sjf_vec3_dot(sjt_parent169, sjt_functionParam417, &sjv_t);
                sjt_math2351 = 1.0f;
                sjt_math2352 = sjv_det;
                sjv_finvdet = sjt_math2351 / sjt_math2352;
                _return->_refCount = 1;
                sjt_math2353 = sjv_u;
                sjt_math2354 = sjv_finvdet;
                _return->x = sjt_math2353 * sjt_math2354;
                sjt_math2355 = sjv_v;
                sjt_math2356 = sjv_finvdet;
                _return->y = sjt_math2355 * sjt_math2356;
                sjt_math2357 = sjv_t;
                sjt_math2358 = sjv_finvdet;
                _return->z = sjt_math2357 * sjt_math2358;
                sjf_vec3(_return);
            }
        }
    }

    if (sjv_edge1._refCount == 1) { sjf_vec3_destroy(&sjv_edge1); }
    if (sjv_edge2._refCount == 1) { sjf_vec3_destroy(&sjv_edge2); }
    if (sjv_pvec._refCount == 1) { sjf_vec3_destroy(&sjv_pvec); }
    if (sjv_qvec._refCount == 1) { sjf_vec3_destroy(&sjv_qvec); }
    if (sjv_tvec._refCount == 1) { sjf_vec3_destroy(&sjv_tvec); }
}

void sjf_intersecttriangle_heap(sjs_vec3* orig, sjs_vec3* dir, sjs_vec3* v0, sjs_vec3* v1, sjs_vec3* v2, sjs_vec3** _return) {
    float sjt_compare85;
    float sjt_compare86;
    float sjt_compare87;
    float sjt_compare88;
    sjs_vec3* sjt_functionParam418 = 0;
    sjs_vec3* sjt_functionParam419 = 0;
    sjs_vec3* sjt_functionParam420 = 0;
    sjs_vec3* sjt_functionParam421 = 0;
    bool sjt_ifElse32;
    bool sjt_ifElse33;
    sjs_vec3* sjt_parent170 = 0;
    sjs_vec3* sjt_parent171 = 0;
    sjs_vec3* sjt_parent172 = 0;
    sjs_vec3* sjt_parent173 = 0;
    float sjv_det;
    sjs_vec3 sjv_edge1 = { -1 };
    sjs_vec3 sjv_edge2 = { -1 };
    sjs_vec3 sjv_pvec = { -1 };
    sjs_vec3 sjv_qvec = { -1 };
    sjs_vec3 sjv_tvec = { -1 };

    sjt_parent170 = v1;
    sjt_functionParam418 = v0;
    sjf_vec3_subtract(sjt_parent170, sjt_functionParam418, &sjv_edge1);
    sjt_parent171 = v2;
    sjt_functionParam419 = v0;
    sjf_vec3_subtract(sjt_parent171, sjt_functionParam419, &sjv_edge2);
    sjt_parent172 = dir;
    sjt_functionParam420 = &sjv_edge2;
    sjf_vec3_cross(sjt_parent172, sjt_functionParam420, &sjv_pvec);
    sjt_parent173 = &sjv_edge1;
    sjt_functionParam421 = &sjv_pvec;
    sjf_vec3_dot(sjt_parent173, sjt_functionParam421, &sjv_det);
    sjt_compare85 = sjv_det;
    sjt_compare86 = 0.0f;
    sjt_ifElse32 = sjt_compare85 > sjt_compare86;
    if (sjt_ifElse32) {
        sjs_vec3* sjt_functionParam422 = 0;
        sjs_vec3* sjt_parent174 = 0;

        sjt_parent174 = orig;
        sjt_functionParam422 = v0;
        sjf_vec3_subtract(sjt_parent174, sjt_functionParam422, &sjv_tvec);
    } else {
        sjs_vec3* sjt_functionParam423 = 0;
        float sjt_math2359;
        float sjt_math2360;
        sjs_vec3* sjt_parent175 = 0;

        sjt_math2359 = 0.0f;
        sjt_math2360 = sjv_det;
        sjv_det = sjt_math2359 - sjt_math2360;
        sjt_parent175 = v0;
        sjt_functionParam423 = orig;
        sjf_vec3_subtract(sjt_parent175, sjt_functionParam423, &sjv_tvec);
    }

    sjt_compare87 = sjv_det;
    sjt_compare88 = 0.0001f;
    sjt_ifElse33 = sjt_compare87 < sjt_compare88;
    if (sjt_ifElse33) {
        (*_return) = 0;
        if ((*_return) != 0) {
            (*_return)->_refCount++;
        }
    } else {
        float sjt_compare89;
        float sjt_compare90;
        float sjt_compare91;
        float sjt_compare92;
        sjs_vec3* sjt_functionParam424 = 0;
        bool sjt_ifElse34;
        bool sjt_or5;
        bool sjt_or6;
        sjs_vec3* sjt_parent176 = 0;
        float sjv_u;

        sjt_parent176 = &sjv_tvec;
        sjt_functionParam424 = &sjv_pvec;
        sjf_vec3_dot(sjt_parent176, sjt_functionParam424, &sjv_u);
        sjt_compare89 = sjv_u;
        sjt_compare90 = 0.0f;
        sjt_or5 = sjt_compare89 < sjt_compare90;
        sjt_compare91 = sjv_u;
        sjt_compare92 = sjv_det;
        sjt_or6 = sjt_compare91 > sjt_compare92;
        sjt_ifElse34 = sjt_or5 || sjt_or6;
        if (sjt_ifElse34) {
            (*_return) = 0;
            if ((*_return) != 0) {
                (*_return)->_refCount++;
            }
        } else {
            float sjt_compare93;
            float sjt_compare94;
            float sjt_compare95;
            float sjt_compare96;
            sjs_vec3* sjt_functionParam425 = 0;
            sjs_vec3* sjt_functionParam426 = 0;
            bool sjt_ifElse35;
            float sjt_math2361;
            float sjt_math2362;
            bool sjt_or7;
            bool sjt_or8;
            sjs_vec3* sjt_parent177 = 0;
            sjs_vec3* sjt_parent178 = 0;
            float sjv_v;

            sjt_parent177 = &sjv_tvec;
            sjt_functionParam425 = &sjv_edge1;
            sjf_vec3_cross(sjt_parent177, sjt_functionParam425, &sjv_qvec);
            sjt_parent178 = dir;
            sjt_functionParam426 = &sjv_qvec;
            sjf_vec3_dot(sjt_parent178, sjt_functionParam426, &sjv_v);
            sjt_compare93 = sjv_v;
            sjt_compare94 = 0.0f;
            sjt_or7 = sjt_compare93 < sjt_compare94;
            sjt_math2361 = sjv_u;
            sjt_math2362 = sjv_v;
            sjt_compare95 = sjt_math2361 + sjt_math2362;
            sjt_compare96 = sjv_det;
            sjt_or8 = sjt_compare95 > sjt_compare96;
            sjt_ifElse35 = sjt_or7 || sjt_or8;
            if (sjt_ifElse35) {
                (*_return) = 0;
                if ((*_return) != 0) {
                    (*_return)->_refCount++;
                }
            } else {
                sjs_vec3* sjt_functionParam427 = 0;
                float sjt_math2363;
                float sjt_math2364;
                float sjt_math2365;
                float sjt_math2366;
                float sjt_math2367;
                float sjt_math2368;
                float sjt_math2369;
                float sjt_math2370;
                sjs_vec3* sjt_parent179 = 0;
                sjs_vec3* sjt_value2 = 0;
                float sjv_finvdet;
                float sjv_t;

                sjt_parent179 = &sjv_edge2;
                sjt_functionParam427 = &sjv_qvec;
                sjf_vec3_dot(sjt_parent179, sjt_functionParam427, &sjv_t);
                sjt_math2363 = 1.0f;
                sjt_math2364 = sjv_det;
                sjv_finvdet = sjt_math2363 / sjt_math2364;
                sjt_value2 = (sjs_vec3*)malloc(sizeof(sjs_vec3));
                sjt_value2->_refCount = 1;
                sjt_math2365 = sjv_u;
                sjt_math2366 = sjv_finvdet;
                sjt_value2->x = sjt_math2365 * sjt_math2366;
                sjt_math2367 = sjv_v;
                sjt_math2368 = sjv_finvdet;
                sjt_value2->y = sjt_math2367 * sjt_math2368;
                sjt_math2369 = sjv_t;
                sjt_math2370 = sjv_finvdet;
                sjt_value2->z = sjt_math2369 * sjt_math2370;
                sjf_vec3_heap(sjt_value2);
                (*_return) = sjt_value2;
                if ((*_return) != 0) {
                    (*_return)->_refCount++;
                }

                sjt_value2->_refCount--;
                if (sjt_value2->_refCount <= 0) {
                    weakptr_release(sjt_value2);
                    sjf_vec3_destroy(sjt_value2);
                }
            }
        }
    }

    if (sjv_edge1._refCount == 1) { sjf_vec3_destroy(&sjv_edge1); }
    if (sjv_edge2._refCount == 1) { sjf_vec3_destroy(&sjv_edge2); }
    if (sjv_pvec._refCount == 1) { sjf_vec3_destroy(&sjv_pvec); }
    if (sjv_qvec._refCount == 1) { sjf_vec3_destroy(&sjv_qvec); }
    if (sjv_tvec._refCount == 1) { sjf_vec3_destroy(&sjv_tvec); }
}

void sjf_leafpanel(sjs_leafpanel* _this) {
    int32_t sjt_cast16;
    sjs_array_texture* sjt_dot1328 = 0;
    cb_texture_heap_iface_model sjt_functionParam219;
    float sjt_math2103;
    float sjt_math2104;
    float sjt_math2105;
    float sjt_math2106;
    sjs_array_texture* sjt_parent82 = 0;

    sjt_dot1328 = &_this->textures;
    sjt_cast16 = (sjt_dot1328)->count;
    sjt_math2105 = (float)sjt_cast16;
    sjt_math2106 = 0.8f;
    sjt_math2103 = sjt_math2105 * sjt_math2106;
    sjt_math2104 = 2.0f;
    _this->_angle = sjt_math2103 / sjt_math2104;
    sjt_parent82 = &_this->textures;
    sjt_functionParam219._parent = (sjs_object*)&_this;
    sjt_functionParam219._cb_heap = (void(*)(sjs_object*,sjs_texture*, sji_model*))sjf_leafpanel_texturetomodel_heap;
    sjf_array_texture_map_heap_iface_model(sjt_parent82, sjt_functionParam219, &_this->children);
}

void sjf_leafpanel_as_sji_model(sjs_leafpanel* _this, sji_model* _return) {
    _return->_parent = (sjs_object*)_this;
    _return->_vtbl = &sjs_leafpanel_model_vtbl;
}

void sjf_leafpanel_asinterface(sjs_leafpanel* _this, int typeId, sjs_interface* _return) {
    switch (typeId) {
        case sji_model_typeId:  {
            sjf_leafpanel_as_sji_model(_this, (sji_model*)_return);
            break;
        }
    }

    _return->_parent = 0;
}

void sjf_leafpanel_copy(sjs_leafpanel* _this, sjs_leafpanel* _from) {
    _this->textures._refCount = 1;
    sjf_array_texture_copy(&_this->textures, &_from->textures);
    _this->children._refCount = 1;
    sjf_array_heap_iface_model_copy(&_this->children, &_from->children);
    _this->_angle = _from->_angle;
}

void sjf_leafpanel_destroy(sjs_leafpanel* _this) {
}

void sjf_leafpanel_firemouseevent(sjs_leafpanel* _parent, sjs_mouseevent* mouseevent) {
    int32_t i;
    sjs_array_heap_iface_model* sjt_dot1364 = 0;
    sjs_leafpanel* sjt_dot1365 = 0;
    int32_t sjt_forEnd14;
    int32_t sjt_forStart14;

    sjt_forStart14 = 0;
    sjt_dot1365 = _parent;
    sjt_dot1364 = &(sjt_dot1365)->children;
    sjt_forEnd14 = (sjt_dot1364)->count;
    i = sjt_forStart14;
    while (i < sjt_forEnd14) {
        sjs_leafpanel* sjt_dot1366 = 0;
        int32_t sjt_functionParam256;
        sjs_mouseevent* sjt_interfaceParam17 = 0;
        sjs_array_heap_iface_model* sjt_parent101 = 0;
        sji_model sjt_parent102 = { 0 };
        sji_model sjv_c = { 0 };

        sjt_dot1366 = _parent;
        sjt_parent101 = &(sjt_dot1366)->children;
        sjt_functionParam256 = i;
        sjf_array_heap_iface_model_getat_heap(sjt_parent101, sjt_functionParam256, &sjv_c);
        sjt_parent102 = sjv_c;
        sjt_interfaceParam17 = mouseevent;
        sjt_parent102._vtbl->firemouseevent(sjt_parent102._parent, sjt_interfaceParam17);
        i++;

        if (sjv_c._parent != 0) {
            sjv_c._parent->_refCount--;
            if (sjv_c._parent->_refCount <= 0) {
                sjv_c._vtbl->destroy(sjv_c._parent);
            }
        }
    }
}

void sjf_leafpanel_getz(sjs_leafpanel* _parent, float* _return) {
    (*_return) = 0.0f;
}

void sjf_leafpanel_heap(sjs_leafpanel* _this) {
    int32_t sjt_cast20;
    sjs_array_texture* sjt_dot1367 = 0;
    cb_texture_heap_iface_model sjt_functionParam257;
    float sjt_math2149;
    float sjt_math2150;
    float sjt_math2151;
    float sjt_math2152;
    sjs_array_texture* sjt_parent103 = 0;

    sjt_dot1367 = &_this->textures;
    sjt_cast20 = (sjt_dot1367)->count;
    sjt_math2151 = (float)sjt_cast20;
    sjt_math2152 = 0.8f;
    sjt_math2149 = sjt_math2151 * sjt_math2152;
    sjt_math2150 = 2.0f;
    _this->_angle = sjt_math2149 / sjt_math2150;
    sjt_parent103 = &_this->textures;
    sjt_functionParam257._parent = (sjs_object*)_this;
    sjt_functionParam257._cb_heap = (void(*)(sjs_object*,sjs_texture*, sji_model*))sjf_leafpanel_texturetomodel_heap;
    sjf_array_texture_map_heap_iface_model(sjt_parent103, sjt_functionParam257, &_this->children);
}

void sjf_leafpanel_heap_as_sji_model(sjs_leafpanel* _this, sji_model* _return) {
    _return->_parent = (sjs_object*)_this;
    _return->_vtbl = &sjs_leafpanel_model_vtbl;
}

void sjf_leafpanel_heap_asinterface(sjs_leafpanel* _this, int typeId, sjs_interface* _return) {
    switch (typeId) {
        case sji_model_typeId:  {
            sjf_leafpanel_heap_as_sji_model(_this, (sji_model*)_return);
            break;
        }
    }

    _return->_parent = 0;
}

void sjf_leafpanel_render(sjs_leafpanel* _parent) {
}

void sjf_leafpanel_renderorqueue(sjs_leafpanel* _parent, sjs_list_local_iface_model* zqueue) {
    int32_t i;
    sjs_array_heap_iface_model* sjt_dot1361 = 0;
    sjs_leafpanel* sjt_dot1362 = 0;
    int32_t sjt_forEnd13;
    int32_t sjt_forStart13;

    sjt_forStart13 = 0;
    sjt_dot1362 = _parent;
    sjt_dot1361 = &(sjt_dot1362)->children;
    sjt_forEnd13 = (sjt_dot1361)->count;
    i = sjt_forStart13;
    while (i < sjt_forEnd13) {
        sjs_leafpanel* sjt_dot1363 = 0;
        int32_t sjt_functionParam255;
        sjs_list_local_iface_model* sjt_interfaceParam16 = 0;
        sji_model sjt_parent100 = { 0 };
        sjs_array_heap_iface_model* sjt_parent99 = 0;
        sji_model sjv_c = { 0 };

        sjt_dot1363 = _parent;
        sjt_parent99 = &(sjt_dot1363)->children;
        sjt_functionParam255 = i;
        sjf_array_heap_iface_model_getat_heap(sjt_parent99, sjt_functionParam255, &sjv_c);
        sjt_parent100 = sjv_c;
        sjt_interfaceParam16 = zqueue;
        sjt_parent100._vtbl->renderorqueue(sjt_parent100._parent, sjt_interfaceParam16);
        i++;

        if (sjv_c._parent != 0) {
            sjv_c._parent->_refCount--;
            if (sjv_c._parent->_refCount <= 0) {
                sjv_c._vtbl->destroy(sjv_c._parent);
            }
        }
    }
}

void sjf_leafpanel_texturetomodel_heap(sjs_leafpanel* _parent, sjs_texture* texture, sji_model* _return) {
    float result15;
    float result16;
    sjs_model* sjt_call40 = 0;
    sjs_string sjt_call41 = { -1 };
    sjs_string sjt_call42 = { -1 };
    sjs_model* sjt_cast17 = 0;
    sjs_shader* sjt_copy16 = 0;
    sjs_texture* sjt_copy17 = 0;
    sjs_leafpanel* sjt_dot1335 = 0;
    sjs_leafpanel* sjt_dot1336 = 0;
    sjs_leafpanel* sjt_dot1337 = 0;
    sjs_leafpanel* sjt_dot1338 = 0;
    float sjt_functionParam220;
    float sjt_functionParam221;
    float sjt_functionParam222;
    float sjt_functionParam223;
    float sjt_functionParam224;
    float sjt_functionParam225;
    float sjt_functionParam226;
    float sjt_functionParam227;
    float sjt_functionParam228;
    float sjt_functionParam229;
    float sjt_functionParam230;
    float sjt_functionParam231;
    float sjt_functionParam232;
    sjs_string* sjt_functionParam252 = 0;
    float sjt_functionParam253;
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
    float sjt_negate13;
    float sjt_negate14;
    sjs_string* sjt_parent96 = 0;
    float sjv_noise;
    float sjv_x;
    float sjv_y;
    float sjv_z;

    sjf_f32_random(&sjt_math2107);
    sjt_math2108 = 0.5f;
    sjv_noise = sjt_math2107 - sjt_math2108;
    sjt_dot1335 = _parent;
    sjt_math2111 = (sjt_dot1335)->_angle;
    sjt_math2112 = 2.0f;
    sjt_math2109 = sjt_math2111 * sjt_math2112;
    sjt_math2113 = sjv_noise;
    sjt_math2114 = 0.2f;
    sjt_math2110 = sjt_math2113 * sjt_math2114;
    sjv_x = sjt_math2109 + sjt_math2110;
    sjt_math2115 = sjv_noise;
    sjt_math2116 = 3.0f;
    sjv_y = sjt_math2115 * sjt_math2116;
    sjt_dot1336 = _parent;
    sjt_math2119 = (sjt_dot1336)->_angle;
    sjt_math2121 = sjv_noise;
    sjt_math2122 = 0.2f;
    sjt_math2120 = sjt_math2121 * sjt_math2122;
    sjt_functionParam220 = sjt_math2119 + sjt_math2120;
    sjf_f32_cos(sjt_functionParam220, &sjt_math2117);
    sjt_math2118 = 2.0f;
    sjv_z = sjt_math2117 * sjt_math2118;
    sjt_dot1337 = _parent;
    sjt_dot1338 = _parent;
    sjt_math2123 = (sjt_dot1338)->_angle;
    sjt_math2124 = 0.8f;
    sjt_dot1337->_angle = sjt_math2123 + sjt_math2124;
    sjt_call40 = (sjs_model*)malloc(sizeof(sjs_model));
    sjt_call40->_refCount = 1;
    sjt_negate13 = 1.0f;
    result15 = -sjt_negate13;
    sjt_functionParam221 = result15;
    sjt_functionParam222 = 1.0f;
    sjt_negate14 = 1.0f;
    result16 = -sjt_negate14;
    sjt_functionParam223 = result16;
    sjt_functionParam224 = 1.0f;
    sjt_functionParam225 = 0.0f;
    sjt_functionParam226 = 0.0f;
    sjt_functionParam227 = 1.0f;
    sjt_functionParam228 = 0.0f;
    sjt_functionParam229 = 1.0f;
    sjf_planevertexbuffer(sjt_functionParam221, sjt_functionParam222, sjt_functionParam223, sjt_functionParam224, sjt_functionParam225, sjt_functionParam226, sjt_functionParam227, sjt_functionParam228, sjt_functionParam229, &sjt_call40->vertexbuffer);
    sjt_copy16 = &sjv_phongtextureshader;
    sjt_call40->shader._refCount = 1;
    sjf_shader_copy(&sjt_call40->shader, sjt_copy16);
    sjt_copy17 = texture;
    sjt_call40->texture._refCount = 1;
    sjf_texture_copy(&sjt_call40->texture, sjt_copy17);
    sjt_functionParam230 = sjv_x;
    sjt_functionParam231 = sjv_y;
    sjt_functionParam232 = sjv_z;
    sjf_mat4_translate(sjt_functionParam230, sjt_functionParam231, sjt_functionParam232, &sjt_call40->model);
    sjt_call40->center._refCount = 1;
    sjt_call40->center.x = 0.0f;
    sjt_call40->center.y = 0.0f;
    sjt_call40->center.z = 0.0f;
    sjf_vec3(&sjt_call40->center);
    sjt_call40->hasalpha = true;
    sjt_call41._refCount = 1;
    sjt_call41.count = 4;
    sjt_call41.data._refCount = 1;
    sjt_call41.data.datasize = 5;
    sjt_call41.data.data = (void*)sjg_string18;
    sjt_call41.data._isglobal = true;
    sjt_call41.data.count = 5;
    sjf_array_char(&sjt_call41.data);
    sjf_string(&sjt_call41);
    sjt_parent96 = &sjt_call41;
    sjt_functionParam253 = sjv_z;
    sjf_f32_tostring(sjt_functionParam253, &sjt_call42);
    sjt_functionParam252 = &sjt_call42;
    sjf_string_add(sjt_parent96, sjt_functionParam252, &sjt_call40->id);
    sjt_call40->_projection._refCount = 1;
    sjt_call40->_projection.m00 = 0.0f;
    sjt_call40->_projection.m01 = 0.0f;
    sjt_call40->_projection.m02 = 0.0f;
    sjt_call40->_projection.m03 = 0.0f;
    sjt_call40->_projection.m10 = 0.0f;
    sjt_call40->_projection.m11 = 0.0f;
    sjt_call40->_projection.m12 = 0.0f;
    sjt_call40->_projection.m13 = 0.0f;
    sjt_call40->_projection.m20 = 0.0f;
    sjt_call40->_projection.m21 = 0.0f;
    sjt_call40->_projection.m22 = 0.0f;
    sjt_call40->_projection.m23 = 0.0f;
    sjt_call40->_projection.m30 = 0.0f;
    sjt_call40->_projection.m31 = 0.0f;
    sjt_call40->_projection.m32 = 0.0f;
    sjt_call40->_projection.m33 = 0.0f;
    sjf_mat4(&sjt_call40->_projection);
    sjt_call40->_view._refCount = 1;
    sjt_call40->_view.m00 = 0.0f;
    sjt_call40->_view.m01 = 0.0f;
    sjt_call40->_view.m02 = 0.0f;
    sjt_call40->_view.m03 = 0.0f;
    sjt_call40->_view.m10 = 0.0f;
    sjt_call40->_view.m11 = 0.0f;
    sjt_call40->_view.m12 = 0.0f;
    sjt_call40->_view.m13 = 0.0f;
    sjt_call40->_view.m20 = 0.0f;
    sjt_call40->_view.m21 = 0.0f;
    sjt_call40->_view.m22 = 0.0f;
    sjt_call40->_view.m23 = 0.0f;
    sjt_call40->_view.m30 = 0.0f;
    sjt_call40->_view.m31 = 0.0f;
    sjt_call40->_view.m32 = 0.0f;
    sjt_call40->_view.m33 = 0.0f;
    sjf_mat4(&sjt_call40->_view);
    sjt_call40->_world._refCount = 1;
    sjt_call40->_world.m00 = 0.0f;
    sjt_call40->_world.m01 = 0.0f;
    sjt_call40->_world.m02 = 0.0f;
    sjt_call40->_world.m03 = 0.0f;
    sjt_call40->_world.m10 = 0.0f;
    sjt_call40->_world.m11 = 0.0f;
    sjt_call40->_world.m12 = 0.0f;
    sjt_call40->_world.m13 = 0.0f;
    sjt_call40->_world.m20 = 0.0f;
    sjt_call40->_world.m21 = 0.0f;
    sjt_call40->_world.m22 = 0.0f;
    sjt_call40->_world.m23 = 0.0f;
    sjt_call40->_world.m30 = 0.0f;
    sjt_call40->_world.m31 = 0.0f;
    sjt_call40->_world.m32 = 0.0f;
    sjt_call40->_world.m33 = 0.0f;
    sjf_mat4(&sjt_call40->_world);
    sjt_call40->_light._refCount = 1;
    sjt_call40->_light.pos._refCount = 1;
    sjt_call40->_light.pos.x = 1.0f;
    sjt_call40->_light.pos.y = 1.0f;
    sjt_call40->_light.pos.z = 1.0f;
    sjf_vec3(&sjt_call40->_light.pos);
    sjt_call40->_light.diffusecolor._refCount = 1;
    sjt_call40->_light.diffusecolor.r = 0.5f;
    sjt_call40->_light.diffusecolor.g = 0.5f;
    sjt_call40->_light.diffusecolor.b = 0.0f;
    sjt_call40->_light.diffusecolor.a = 1.0f;
    sjf_color(&sjt_call40->_light.diffusecolor);
    sjt_call40->_light.speccolor._refCount = 1;
    sjt_call40->_light.speccolor.r = 1.0f;
    sjt_call40->_light.speccolor.g = 1.0f;
    sjt_call40->_light.speccolor.b = 1.0f;
    sjt_call40->_light.speccolor.a = 1.0f;
    sjf_color(&sjt_call40->_light.speccolor);
    sjf_light(&sjt_call40->_light);
    sjt_call40->_projectedcenter._refCount = 1;
    sjt_call40->_projectedcenter.x = 0.0f;
    sjt_call40->_projectedcenter.y = 0.0f;
    sjt_call40->_projectedcenter.z = 0.0f;
    sjf_vec3(&sjt_call40->_projectedcenter);
    sjf_model_heap(sjt_call40);
    sjt_cast17 = sjt_call40;
    sjf_model_as_sji_model(sjt_cast17, &(*_return));
    if ((*_return)._parent != 0) {
        (*_return)._parent->_refCount++;
    }

    sjt_call40->_refCount--;
    if (sjt_call40->_refCount <= 0) {
        weakptr_release(sjt_call40);
        sjf_model_destroy(sjt_call40);
    }
    if (sjt_call41._refCount == 1) { sjf_string_destroy(&sjt_call41); }
    if (sjt_call42._refCount == 1) { sjf_string_destroy(&sjt_call42); }
}

void sjf_leafpanel_update(sjs_leafpanel* _parent, sjs_rect* scenerect, sjs_mat4* projection, sjs_mat4* view, sjs_mat4* world, sjs_light* light) {
    int32_t i;
    sjs_array_heap_iface_model* sjt_dot1358 = 0;
    sjs_leafpanel* sjt_dot1359 = 0;
    int32_t sjt_forEnd12;
    int32_t sjt_forStart12;

    sjt_forStart12 = 0;
    sjt_dot1359 = _parent;
    sjt_dot1358 = &(sjt_dot1359)->children;
    sjt_forEnd12 = (sjt_dot1358)->count;
    i = sjt_forStart12;
    while (i < sjt_forEnd12) {
        sjs_leafpanel* sjt_dot1360 = 0;
        int32_t sjt_functionParam254;
        sjs_rect* sjt_interfaceParam11 = 0;
        sjs_mat4* sjt_interfaceParam12 = 0;
        sjs_mat4* sjt_interfaceParam13 = 0;
        sjs_mat4* sjt_interfaceParam14 = 0;
        sjs_light* sjt_interfaceParam15 = 0;
        sjs_array_heap_iface_model* sjt_parent97 = 0;
        sji_model sjt_parent98 = { 0 };
        sji_model sjv_c = { 0 };

        sjt_dot1360 = _parent;
        sjt_parent97 = &(sjt_dot1360)->children;
        sjt_functionParam254 = i;
        sjf_array_heap_iface_model_getat_heap(sjt_parent97, sjt_functionParam254, &sjv_c);
        sjt_parent98 = sjv_c;
        sjt_interfaceParam11 = scenerect;
        sjt_interfaceParam12 = projection;
        sjt_interfaceParam13 = view;
        sjt_interfaceParam14 = world;
        sjt_interfaceParam15 = light;
        sjt_parent98._vtbl->update(sjt_parent98._parent, sjt_interfaceParam11, sjt_interfaceParam12, sjt_interfaceParam13, sjt_interfaceParam14, sjt_interfaceParam15);
        i++;

        if (sjv_c._parent != 0) {
            sjv_c._parent->_refCount--;
            if (sjv_c._parent->_refCount <= 0) {
                sjv_c._vtbl->destroy(sjv_c._parent);
            }
        }
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
}

void sjf_light_heap(sjs_light* _this) {
}

void sjf_list_local_iface_animation(sjs_list_local_iface_animation* _this) {
}

void sjf_list_local_iface_animation_copy(sjs_list_local_iface_animation* _this, sjs_list_local_iface_animation* _from) {
    _this->array._refCount = 1;
    sjf_array_local_iface_animation_copy(&_this->array, &_from->array);
}

void sjf_list_local_iface_animation_destroy(sjs_list_local_iface_animation* _this) {
}

void sjf_list_local_iface_animation_getat_heap(sjs_list_local_iface_animation* _parent, int32_t index, sji_animation* _return) {
    sjs_list_local_iface_animation* sjt_dot1710 = 0;
    int32_t sjt_functionParam724;
    sjs_array_local_iface_animation* sjt_parent244 = 0;

    sjt_dot1710 = _parent;
    sjt_parent244 = &(sjt_dot1710)->array;
    sjt_functionParam724 = index;
    sjf_array_local_iface_animation_getat_heap(sjt_parent244, sjt_functionParam724, _return);
}

void sjf_list_local_iface_animation_getcount(sjs_list_local_iface_animation* _parent, int32_t* _return) {
    sjs_array_local_iface_animation* sjt_dot1705 = 0;
    sjs_list_local_iface_animation* sjt_dot1706 = 0;

    sjt_dot1706 = _parent;
    sjt_dot1705 = &(sjt_dot1706)->array;
    (*_return) = (sjt_dot1705)->count;
}

void sjf_list_local_iface_animation_heap(sjs_list_local_iface_animation* _this) {
}

void sjf_list_local_iface_animation_removeat(sjs_list_local_iface_animation* _parent, int32_t index) {
    if (index < 0 || index >= _parent->array.count) {
        halt("removeAt: out of bounds %d:%d\n", index, _parent->array.count);
    }
    sji_animation* p = (sji_animation*)_parent->array.data;
    if (index != _parent->array.count - 1) {
        memcpy(p + index, p + index + 1, _parent->array.count - index - 1);
    }
    _parent->array.count--;
}

void sjf_list_local_iface_model(sjs_list_local_iface_model* _this) {
}

void sjf_list_local_iface_model_add(sjs_list_local_iface_model* _parent, sji_model item) {
    int32_t sjt_compare45;
    int32_t sjt_compare46;
    sjs_array_local_iface_model* sjt_dot550 = 0;
    sjs_list_local_iface_model* sjt_dot551 = 0;
    sjs_array_local_iface_model* sjt_dot552 = 0;
    sjs_list_local_iface_model* sjt_dot553 = 0;
    sjs_list_local_iface_model* sjt_dot560 = 0;
    sjs_array_local_iface_model* sjt_dot561 = 0;
    sjs_list_local_iface_model* sjt_dot562 = 0;
    int32_t sjt_functionParam114;
    sji_model sjt_functionParam115 = { 0 };
    bool sjt_ifElse14;
    sjs_array_local_iface_model* sjt_parent48 = 0;

    sjt_dot551 = _parent;
    sjt_dot550 = &(sjt_dot551)->array;
    sjt_compare45 = (sjt_dot550)->count;
    sjt_dot553 = _parent;
    sjt_dot552 = &(sjt_dot553)->array;
    sjt_compare46 = (sjt_dot552)->datasize;
    sjt_ifElse14 = sjt_compare45 >= sjt_compare46;
    if (sjt_ifElse14) {
        sjs_list_local_iface_model* sjt_dot554 = 0;
        sjs_list_local_iface_model* sjt_dot557 = 0;
        sjs_array_local_iface_model* sjt_dot558 = 0;
        sjs_list_local_iface_model* sjt_dot559 = 0;
        int32_t sjt_functionParam111;
        int32_t sjt_functionParam112;
        int32_t sjt_functionParam113;
        int32_t sjt_math751;
        int32_t sjt_math752;
        sjs_array_local_iface_model* sjt_parent47 = 0;

        sjt_dot554 = _parent;
        sjt_dot557 = _parent;
        sjt_parent47 = &(sjt_dot557)->array;
        sjt_functionParam112 = 10;
        sjt_dot559 = _parent;
        sjt_dot558 = &(sjt_dot559)->array;
        sjt_math751 = (sjt_dot558)->datasize;
        sjt_math752 = 2;
        sjt_functionParam113 = sjt_math751 * sjt_math752;
        sjf_i32_max(sjt_functionParam112, sjt_functionParam113, &sjt_functionParam111);
        sjf_array_local_iface_model_grow(sjt_parent47, sjt_functionParam111, &sjt_dot554->array);
    }

    sjt_dot560 = _parent;
    sjt_parent48 = &(sjt_dot560)->array;
    sjt_dot562 = _parent;
    sjt_dot561 = &(sjt_dot562)->array;
    sjt_functionParam114 = (sjt_dot561)->count;
    sjt_functionParam115 = item;
    sjf_array_local_iface_model_initat(sjt_parent48, sjt_functionParam114, sjt_functionParam115);
}

void sjf_list_local_iface_model_copy(sjs_list_local_iface_model* _this, sjs_list_local_iface_model* _from) {
    _this->array._refCount = 1;
    sjf_array_local_iface_model_copy(&_this->array, &_from->array);
}

void sjf_list_local_iface_model_destroy(sjs_list_local_iface_model* _this) {
}

void sjf_list_local_iface_model_getat_heap(sjs_list_local_iface_model* _parent, int32_t index, sji_model* _return) {
    sjs_list_local_iface_model* sjt_dot60 = 0;
    int32_t sjt_functionParam49;
    sjs_array_local_iface_model* sjt_parent19 = 0;

    sjt_dot60 = _parent;
    sjt_parent19 = &(sjt_dot60)->array;
    sjt_functionParam49 = index;
    sjf_array_local_iface_model_getat_heap(sjt_parent19, sjt_functionParam49, _return);
}

void sjf_list_local_iface_model_getcount(sjs_list_local_iface_model* _parent, int32_t* _return) {
    sjs_array_local_iface_model* sjt_dot58 = 0;
    sjs_list_local_iface_model* sjt_dot59 = 0;

    sjt_dot59 = _parent;
    sjt_dot58 = &(sjt_dot59)->array;
    (*_return) = (sjt_dot58)->count;
}

void sjf_list_local_iface_model_heap(sjs_list_local_iface_model* _this) {
}

void sjf_list_local_iface_model_sortcb(sjs_list_local_iface_model* _parent, cb_local_iface_model_local_iface_model_i32 cb) {
    sjs_list_local_iface_model* sjt_dot57 = 0;
    cb_local_iface_model_local_iface_model_i32 sjt_functionParam45;
    sjs_array_local_iface_model* sjt_parent14 = 0;

    sjt_dot57 = _parent;
    sjt_parent14 = &(sjt_dot57)->array;
    sjt_functionParam45 = cb;
    sjf_array_local_iface_model_sortcb(sjt_parent14, sjt_functionParam45);
}

void sjf_mainloop(void) {
    sjs_size* sjt_dot1713 = 0;
    sjs_size* sjt_dot1714 = 0;
    int32_t sjt_functionParam727;
    sjs_size* sjt_functionParam728 = 0;
    sjs_rect* sjt_interfaceParam37 = 0;
    sjs_scene2d* sjt_interfaceParam38 = 0;
    bool sjt_isEmpty20;
    int32_option sjt_isEmpty21;
    sjs_anon1* sjt_parent248 = 0;
    sjs_windowrenderer* sjt_parent249 = 0;
    sjs_scene2d* sjt_parent250 = 0;
    sjs_scene2d* sjt_parent251 = 0;
    sji_element sjt_parent252 = { 0 };
    sji_element sjt_parent253 = { 0 };
    sjs_windowrenderer* sjt_parent254 = 0;
    int32_option sjv_mouseeventtype;
    sjs_rect sjv_rect = { -1 };
    sjs_size sjv_size = { -1 };
    int32_t sjv_ticks;
    int32_t sjv_x;
    int32_t sjv_y;

    sjv_ticks = 0;
    sjv_ticks = SDL_GetTicks();
    sjt_parent248 = &sjv_animator;
    sjt_functionParam727 = sjv_ticks;
    sjf_anon1_nextframe(sjt_parent248, sjt_functionParam727);
    sjt_parent249 = &sjv_rootwindowrenderer;
    sjf_windowrenderer_getsize(sjt_parent249, &sjv_size);
    sjt_parent250 = &sjv_rootscene;
    sjt_functionParam728 = &sjv_size;
    sjf_scene2d_setsize(sjt_parent250, sjt_functionParam728);
    sjt_parent251 = &sjv_rootscene;
    sjf_scene2d_clear(sjt_parent251);
    sjv_rect._refCount = 1;
    sjv_rect.x = 0;
    sjv_rect.y = 0;
    sjt_dot1713 = &sjv_size;
    sjv_rect.w = (sjt_dot1713)->w;
    sjt_dot1714 = &sjv_size;
    sjv_rect.h = (sjt_dot1714)->h;
    sjf_rect(&sjv_rect);
    sjt_parent252 = sjv_root;
    sjt_interfaceParam37 = &sjv_rect;
    sjt_parent252._vtbl->setrect(sjt_parent252._parent, sjt_interfaceParam37);
    sjt_parent253 = sjv_root;
    sjt_interfaceParam38 = &sjv_rootscene;
    sjt_parent253._vtbl->render(sjt_parent253._parent, sjt_interfaceParam38);
    sjt_parent254 = &sjv_rootwindowrenderer;
    sjf_windowrenderer_present(sjt_parent254);
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
    sjt_isEmpty21 = sjv_mouseeventtype;
    sjt_isEmpty20 = sjt_isEmpty21.isvalid;
    if (sjt_isEmpty20) {
        int32_t ifValue1;
        int32_option sjt_getValue2;
        bool sjt_isEmpty22;
        sji_element sjt_isEmpty23 = { 0 };

        sjt_getValue2 = sjv_mouseeventtype;
        ifValue1 = sjt_getValue2.value;
        sjt_isEmpty23 = sjv_mouse_captureelement;
        sjt_isEmpty22 = (sjt_isEmpty23._parent != 0);
        if (sjt_isEmpty22) {
            sji_element ifValue2 = { 0 };
            sjs_mouseevent sjt_call137 = { -1 };
            sjs_mouseevent* sjt_interfaceParam39 = 0;
            sji_element sjt_parent255 = { 0 };

            ifValue2 = sjv_mouse_captureelement;
            if (ifValue2._parent != 0) {
                ifValue2._parent->_refCount++;
            }

            sjt_parent255 = ifValue2;
            sjt_call137._refCount = 1;
            sjt_call137.type = ifValue1;
            sjt_call137.point._refCount = 1;
            sjt_call137.point.x = sjv_x;
            sjt_call137.point.y = sjv_y;
            sjf_point(&sjt_call137.point);
            sjt_call137.iscaptured = true;
            sjf_mouseevent(&sjt_call137);
            sjt_interfaceParam39 = &sjt_call137;
            sjt_parent255._vtbl->firemouseevent(sjt_parent255._parent, sjt_interfaceParam39);

            if (ifValue2._parent != 0) {
                ifValue2._parent->_refCount--;
                if (ifValue2._parent->_refCount <= 0) {
                    ifValue2._vtbl->destroy(ifValue2._parent);
                }
            }
            if (sjt_call137._refCount == 1) { sjf_mouseevent_destroy(&sjt_call137); }
        } else {
            sjs_mouseevent sjt_call138 = { -1 };
            sjs_mouseevent* sjt_interfaceParam40 = 0;
            sji_element sjt_parent256 = { 0 };

            sjt_parent256 = sjv_root;
            sjt_call138._refCount = 1;
            sjt_call138.type = ifValue1;
            sjt_call138.point._refCount = 1;
            sjt_call138.point.x = sjv_x;
            sjt_call138.point.y = sjv_y;
            sjf_point(&sjt_call138.point);
            sjt_call138.iscaptured = false;
            sjf_mouseevent(&sjt_call138);
            sjt_interfaceParam40 = &sjt_call138;
            sjt_parent256._vtbl->firemouseevent(sjt_parent256._parent, sjt_interfaceParam40);

            if (sjt_call138._refCount == 1) { sjf_mouseevent_destroy(&sjt_call138); }
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

void sjf_mat4_determinant(sjs_mat4* _parent, float* _return) {
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
    float sjt_math1479;
    float sjt_math1480;
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

    sjt_dot918 = _parent;
    sjt_math1413 = (sjt_dot918)->m03;
    sjt_dot919 = _parent;
    sjt_math1414 = (sjt_dot919)->m12;
    sjt_math1411 = sjt_math1413 * sjt_math1414;
    sjt_dot920 = _parent;
    sjt_math1412 = (sjt_dot920)->m21;
    sjt_math1409 = sjt_math1411 * sjt_math1412;
    sjt_dot921 = _parent;
    sjt_math1410 = (sjt_dot921)->m30;
    sjt_math1407 = sjt_math1409 * sjt_math1410;
    sjt_dot922 = _parent;
    sjt_math1419 = (sjt_dot922)->m02;
    sjt_dot923 = _parent;
    sjt_math1420 = (sjt_dot923)->m13;
    sjt_math1417 = sjt_math1419 * sjt_math1420;
    sjt_dot924 = _parent;
    sjt_math1418 = (sjt_dot924)->m21;
    sjt_math1415 = sjt_math1417 * sjt_math1418;
    sjt_dot925 = _parent;
    sjt_math1416 = (sjt_dot925)->m30;
    sjt_math1408 = sjt_math1415 * sjt_math1416;
    sjt_math1405 = sjt_math1407 - sjt_math1408;
    sjt_dot926 = _parent;
    sjt_math1425 = (sjt_dot926)->m03;
    sjt_dot927 = _parent;
    sjt_math1426 = (sjt_dot927)->m11;
    sjt_math1423 = sjt_math1425 * sjt_math1426;
    sjt_dot928 = _parent;
    sjt_math1424 = (sjt_dot928)->m22;
    sjt_math1421 = sjt_math1423 * sjt_math1424;
    sjt_dot929 = _parent;
    sjt_math1422 = (sjt_dot929)->m30;
    sjt_math1406 = sjt_math1421 * sjt_math1422;
    sjt_math1403 = sjt_math1405 - sjt_math1406;
    sjt_dot930 = _parent;
    sjt_math1431 = (sjt_dot930)->m01;
    sjt_dot931 = _parent;
    sjt_math1432 = (sjt_dot931)->m13;
    sjt_math1429 = sjt_math1431 * sjt_math1432;
    sjt_dot932 = _parent;
    sjt_math1430 = (sjt_dot932)->m22;
    sjt_math1427 = sjt_math1429 * sjt_math1430;
    sjt_dot933 = _parent;
    sjt_math1428 = (sjt_dot933)->m30;
    sjt_math1404 = sjt_math1427 * sjt_math1428;
    sjt_math1401 = sjt_math1403 + sjt_math1404;
    sjt_dot934 = _parent;
    sjt_math1437 = (sjt_dot934)->m02;
    sjt_dot935 = _parent;
    sjt_math1438 = (sjt_dot935)->m11;
    sjt_math1435 = sjt_math1437 * sjt_math1438;
    sjt_dot936 = _parent;
    sjt_math1436 = (sjt_dot936)->m23;
    sjt_math1433 = sjt_math1435 * sjt_math1436;
    sjt_dot937 = _parent;
    sjt_math1434 = (sjt_dot937)->m30;
    sjt_math1402 = sjt_math1433 * sjt_math1434;
    sjt_math1399 = sjt_math1401 + sjt_math1402;
    sjt_dot938 = _parent;
    sjt_math1443 = (sjt_dot938)->m01;
    sjt_dot939 = _parent;
    sjt_math1444 = (sjt_dot939)->m12;
    sjt_math1441 = sjt_math1443 * sjt_math1444;
    sjt_dot940 = _parent;
    sjt_math1442 = (sjt_dot940)->m23;
    sjt_math1439 = sjt_math1441 * sjt_math1442;
    sjt_dot941 = _parent;
    sjt_math1440 = (sjt_dot941)->m30;
    sjt_math1400 = sjt_math1439 * sjt_math1440;
    sjt_math1397 = sjt_math1399 - sjt_math1400;
    sjt_dot942 = _parent;
    sjt_math1449 = (sjt_dot942)->m03;
    sjt_dot943 = _parent;
    sjt_math1450 = (sjt_dot943)->m12;
    sjt_math1447 = sjt_math1449 * sjt_math1450;
    sjt_dot944 = _parent;
    sjt_math1448 = (sjt_dot944)->m20;
    sjt_math1445 = sjt_math1447 * sjt_math1448;
    sjt_dot945 = _parent;
    sjt_math1446 = (sjt_dot945)->m31;
    sjt_math1398 = sjt_math1445 * sjt_math1446;
    sjt_math1395 = sjt_math1397 - sjt_math1398;
    sjt_dot946 = _parent;
    sjt_math1455 = (sjt_dot946)->m02;
    sjt_dot947 = _parent;
    sjt_math1456 = (sjt_dot947)->m13;
    sjt_math1453 = sjt_math1455 * sjt_math1456;
    sjt_dot948 = _parent;
    sjt_math1454 = (sjt_dot948)->m20;
    sjt_math1451 = sjt_math1453 * sjt_math1454;
    sjt_dot949 = _parent;
    sjt_math1452 = (sjt_dot949)->m31;
    sjt_math1396 = sjt_math1451 * sjt_math1452;
    sjt_math1393 = sjt_math1395 + sjt_math1396;
    sjt_dot950 = _parent;
    sjt_math1461 = (sjt_dot950)->m03;
    sjt_dot951 = _parent;
    sjt_math1462 = (sjt_dot951)->m10;
    sjt_math1459 = sjt_math1461 * sjt_math1462;
    sjt_dot952 = _parent;
    sjt_math1460 = (sjt_dot952)->m22;
    sjt_math1457 = sjt_math1459 * sjt_math1460;
    sjt_dot953 = _parent;
    sjt_math1458 = (sjt_dot953)->m31;
    sjt_math1394 = sjt_math1457 * sjt_math1458;
    sjt_math1391 = sjt_math1393 + sjt_math1394;
    sjt_dot954 = _parent;
    sjt_math1467 = (sjt_dot954)->m00;
    sjt_dot955 = _parent;
    sjt_math1468 = (sjt_dot955)->m13;
    sjt_math1465 = sjt_math1467 * sjt_math1468;
    sjt_dot956 = _parent;
    sjt_math1466 = (sjt_dot956)->m22;
    sjt_math1463 = sjt_math1465 * sjt_math1466;
    sjt_dot957 = _parent;
    sjt_math1464 = (sjt_dot957)->m31;
    sjt_math1392 = sjt_math1463 * sjt_math1464;
    sjt_math1389 = sjt_math1391 - sjt_math1392;
    sjt_dot958 = _parent;
    sjt_math1473 = (sjt_dot958)->m02;
    sjt_dot959 = _parent;
    sjt_math1474 = (sjt_dot959)->m10;
    sjt_math1471 = sjt_math1473 * sjt_math1474;
    sjt_dot960 = _parent;
    sjt_math1472 = (sjt_dot960)->m23;
    sjt_math1469 = sjt_math1471 * sjt_math1472;
    sjt_dot961 = _parent;
    sjt_math1470 = (sjt_dot961)->m31;
    sjt_math1390 = sjt_math1469 * sjt_math1470;
    sjt_math1387 = sjt_math1389 - sjt_math1390;
    sjt_dot962 = _parent;
    sjt_math1479 = (sjt_dot962)->m00;
    sjt_dot963 = _parent;
    sjt_math1480 = (sjt_dot963)->m12;
    sjt_math1477 = sjt_math1479 * sjt_math1480;
    sjt_dot964 = _parent;
    sjt_math1478 = (sjt_dot964)->m23;
    sjt_math1475 = sjt_math1477 * sjt_math1478;
    sjt_dot965 = _parent;
    sjt_math1476 = (sjt_dot965)->m31;
    sjt_math1388 = sjt_math1475 * sjt_math1476;
    sjt_math1385 = sjt_math1387 + sjt_math1388;
    sjt_dot966 = _parent;
    sjt_math1485 = (sjt_dot966)->m03;
    sjt_dot967 = _parent;
    sjt_math1486 = (sjt_dot967)->m11;
    sjt_math1483 = sjt_math1485 * sjt_math1486;
    sjt_dot968 = _parent;
    sjt_math1484 = (sjt_dot968)->m20;
    sjt_math1481 = sjt_math1483 * sjt_math1484;
    sjt_dot969 = _parent;
    sjt_math1482 = (sjt_dot969)->m32;
    sjt_math1386 = sjt_math1481 * sjt_math1482;
    sjt_math1383 = sjt_math1385 + sjt_math1386;
    sjt_dot970 = _parent;
    sjt_math1491 = (sjt_dot970)->m01;
    sjt_dot971 = _parent;
    sjt_math1492 = (sjt_dot971)->m13;
    sjt_math1489 = sjt_math1491 * sjt_math1492;
    sjt_dot972 = _parent;
    sjt_math1490 = (sjt_dot972)->m20;
    sjt_math1487 = sjt_math1489 * sjt_math1490;
    sjt_dot973 = _parent;
    sjt_math1488 = (sjt_dot973)->m32;
    sjt_math1384 = sjt_math1487 * sjt_math1488;
    sjt_math1381 = sjt_math1383 - sjt_math1384;
    sjt_dot974 = _parent;
    sjt_math1497 = (sjt_dot974)->m03;
    sjt_dot975 = _parent;
    sjt_math1498 = (sjt_dot975)->m10;
    sjt_math1495 = sjt_math1497 * sjt_math1498;
    sjt_dot976 = _parent;
    sjt_math1496 = (sjt_dot976)->m21;
    sjt_math1493 = sjt_math1495 * sjt_math1496;
    sjt_dot977 = _parent;
    sjt_math1494 = (sjt_dot977)->m32;
    sjt_math1382 = sjt_math1493 * sjt_math1494;
    sjt_math1379 = sjt_math1381 - sjt_math1382;
    sjt_dot978 = _parent;
    sjt_math1503 = (sjt_dot978)->m00;
    sjt_dot979 = _parent;
    sjt_math1504 = (sjt_dot979)->m13;
    sjt_math1501 = sjt_math1503 * sjt_math1504;
    sjt_dot980 = _parent;
    sjt_math1502 = (sjt_dot980)->m21;
    sjt_math1499 = sjt_math1501 * sjt_math1502;
    sjt_dot981 = _parent;
    sjt_math1500 = (sjt_dot981)->m32;
    sjt_math1380 = sjt_math1499 * sjt_math1500;
    sjt_math1377 = sjt_math1379 + sjt_math1380;
    sjt_dot982 = _parent;
    sjt_math1509 = (sjt_dot982)->m01;
    sjt_dot983 = _parent;
    sjt_math1510 = (sjt_dot983)->m10;
    sjt_math1507 = sjt_math1509 * sjt_math1510;
    sjt_dot984 = _parent;
    sjt_math1508 = (sjt_dot984)->m23;
    sjt_math1505 = sjt_math1507 * sjt_math1508;
    sjt_dot985 = _parent;
    sjt_math1506 = (sjt_dot985)->m32;
    sjt_math1378 = sjt_math1505 * sjt_math1506;
    sjt_math1375 = sjt_math1377 + sjt_math1378;
    sjt_dot986 = _parent;
    sjt_math1515 = (sjt_dot986)->m00;
    sjt_dot987 = _parent;
    sjt_math1516 = (sjt_dot987)->m11;
    sjt_math1513 = sjt_math1515 * sjt_math1516;
    sjt_dot988 = _parent;
    sjt_math1514 = (sjt_dot988)->m23;
    sjt_math1511 = sjt_math1513 * sjt_math1514;
    sjt_dot989 = _parent;
    sjt_math1512 = (sjt_dot989)->m32;
    sjt_math1376 = sjt_math1511 * sjt_math1512;
    sjt_math1373 = sjt_math1375 - sjt_math1376;
    sjt_dot990 = _parent;
    sjt_math1521 = (sjt_dot990)->m02;
    sjt_dot991 = _parent;
    sjt_math1522 = (sjt_dot991)->m11;
    sjt_math1519 = sjt_math1521 * sjt_math1522;
    sjt_dot992 = _parent;
    sjt_math1520 = (sjt_dot992)->m20;
    sjt_math1517 = sjt_math1519 * sjt_math1520;
    sjt_dot993 = _parent;
    sjt_math1518 = (sjt_dot993)->m33;
    sjt_math1374 = sjt_math1517 * sjt_math1518;
    sjt_math1371 = sjt_math1373 - sjt_math1374;
    sjt_dot994 = _parent;
    sjt_math1527 = (sjt_dot994)->m01;
    sjt_dot995 = _parent;
    sjt_math1528 = (sjt_dot995)->m12;
    sjt_math1525 = sjt_math1527 * sjt_math1528;
    sjt_dot996 = _parent;
    sjt_math1526 = (sjt_dot996)->m20;
    sjt_math1523 = sjt_math1525 * sjt_math1526;
    sjt_dot997 = _parent;
    sjt_math1524 = (sjt_dot997)->m33;
    sjt_math1372 = sjt_math1523 * sjt_math1524;
    sjt_math1369 = sjt_math1371 + sjt_math1372;
    sjt_dot998 = _parent;
    sjt_math1533 = (sjt_dot998)->m02;
    sjt_dot999 = _parent;
    sjt_math1534 = (sjt_dot999)->m10;
    sjt_math1531 = sjt_math1533 * sjt_math1534;
    sjt_dot1000 = _parent;
    sjt_math1532 = (sjt_dot1000)->m21;
    sjt_math1529 = sjt_math1531 * sjt_math1532;
    sjt_dot1001 = _parent;
    sjt_math1530 = (sjt_dot1001)->m33;
    sjt_math1370 = sjt_math1529 * sjt_math1530;
    sjt_math1367 = sjt_math1369 + sjt_math1370;
    sjt_dot1002 = _parent;
    sjt_math1539 = (sjt_dot1002)->m00;
    sjt_dot1003 = _parent;
    sjt_math1540 = (sjt_dot1003)->m12;
    sjt_math1537 = sjt_math1539 * sjt_math1540;
    sjt_dot1004 = _parent;
    sjt_math1538 = (sjt_dot1004)->m21;
    sjt_math1535 = sjt_math1537 * sjt_math1538;
    sjt_dot1005 = _parent;
    sjt_math1536 = (sjt_dot1005)->m33;
    sjt_math1368 = sjt_math1535 * sjt_math1536;
    sjt_math1365 = sjt_math1367 - sjt_math1368;
    sjt_dot1006 = _parent;
    sjt_math1545 = (sjt_dot1006)->m01;
    sjt_dot1007 = _parent;
    sjt_math1546 = (sjt_dot1007)->m10;
    sjt_math1543 = sjt_math1545 * sjt_math1546;
    sjt_dot1008 = _parent;
    sjt_math1544 = (sjt_dot1008)->m22;
    sjt_math1541 = sjt_math1543 * sjt_math1544;
    sjt_dot1009 = _parent;
    sjt_math1542 = (sjt_dot1009)->m33;
    sjt_math1366 = sjt_math1541 * sjt_math1542;
    sjt_math1363 = sjt_math1365 - sjt_math1366;
    sjt_dot1010 = _parent;
    sjt_math1551 = (sjt_dot1010)->m00;
    sjt_dot1011 = _parent;
    sjt_math1552 = (sjt_dot1011)->m11;
    sjt_math1549 = sjt_math1551 * sjt_math1552;
    sjt_dot1012 = _parent;
    sjt_math1550 = (sjt_dot1012)->m22;
    sjt_math1547 = sjt_math1549 * sjt_math1550;
    sjt_dot1013 = _parent;
    sjt_math1548 = (sjt_dot1013)->m33;
    sjt_math1364 = sjt_math1547 * sjt_math1548;
    (*_return) = sjt_math1363 + sjt_math1364;
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
    sjs_mat4* sjt_dot666 = 0;
    sjs_mat4* sjt_dot667 = 0;
    sjs_mat4* sjt_dot668 = 0;
    sjs_mat4* sjt_dot669 = 0;
    sjs_mat4* sjt_dot670 = 0;
    sjs_mat4* sjt_dot671 = 0;
    sjs_mat4* sjt_dot672 = 0;
    sjs_mat4* sjt_dot673 = 0;
    sjs_mat4* sjt_dot674 = 0;
    sjs_mat4* sjt_dot675 = 0;
    sjs_mat4* sjt_dot676 = 0;
    sjs_mat4* sjt_dot677 = 0;
    sjs_mat4* sjt_dot678 = 0;
    sjs_mat4* sjt_dot679 = 0;
    sjs_mat4* sjt_dot680 = 0;
    sjs_mat4* sjt_dot681 = 0;
    sjs_mat4* sjt_dot682 = 0;
    sjs_mat4* sjt_dot683 = 0;
    sjs_mat4* sjt_dot684 = 0;
    sjs_mat4* sjt_dot685 = 0;
    sjs_mat4* sjt_dot686 = 0;
    sjs_mat4* sjt_dot687 = 0;
    sjs_mat4* sjt_dot688 = 0;
    sjs_mat4* sjt_dot689 = 0;
    sjs_mat4* sjt_dot690 = 0;
    sjs_mat4* sjt_dot691 = 0;
    sjs_mat4* sjt_dot692 = 0;
    sjs_mat4* sjt_dot693 = 0;
    sjs_mat4* sjt_dot694 = 0;
    sjs_mat4* sjt_dot695 = 0;
    sjs_mat4* sjt_dot696 = 0;
    sjs_mat4* sjt_dot697 = 0;
    sjs_mat4* sjt_dot698 = 0;
    sjs_mat4* sjt_dot699 = 0;
    sjs_mat4* sjt_dot700 = 0;
    sjs_mat4* sjt_dot701 = 0;
    sjs_mat4* sjt_dot702 = 0;
    sjs_mat4* sjt_dot703 = 0;
    sjs_mat4* sjt_dot704 = 0;
    sjs_mat4* sjt_dot705 = 0;
    sjs_mat4* sjt_dot706 = 0;
    sjs_mat4* sjt_dot707 = 0;
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
    float sjt_functionParam119;
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
    float sjt_math1361;
    float sjt_math1362;
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
    float sjt_math863;
    float sjt_math864;
    float sjt_math865;
    float sjt_math866;
    float sjt_math867;
    float sjt_math868;
    float sjt_math869;
    float sjt_math870;
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
    sjs_mat4* sjt_parent53 = 0;
    sjs_mat4 sjv_t = { -1 };

    sjv_t._refCount = 1;
    sjt_dot598 = _parent;
    sjt_math765 = (sjt_dot598)->m12;
    sjt_dot599 = _parent;
    sjt_math766 = (sjt_dot599)->m23;
    sjt_math763 = sjt_math765 * sjt_math766;
    sjt_dot600 = _parent;
    sjt_math764 = (sjt_dot600)->m31;
    sjt_math761 = sjt_math763 * sjt_math764;
    sjt_dot601 = _parent;
    sjt_math769 = (sjt_dot601)->m13;
    sjt_dot602 = _parent;
    sjt_math770 = (sjt_dot602)->m22;
    sjt_math767 = sjt_math769 * sjt_math770;
    sjt_dot603 = _parent;
    sjt_math768 = (sjt_dot603)->m31;
    sjt_math762 = sjt_math767 * sjt_math768;
    sjt_math759 = sjt_math761 - sjt_math762;
    sjt_dot604 = _parent;
    sjt_math773 = (sjt_dot604)->m13;
    sjt_dot605 = _parent;
    sjt_math774 = (sjt_dot605)->m21;
    sjt_math771 = sjt_math773 * sjt_math774;
    sjt_dot606 = _parent;
    sjt_math772 = (sjt_dot606)->m32;
    sjt_math760 = sjt_math771 * sjt_math772;
    sjt_math757 = sjt_math759 + sjt_math760;
    sjt_dot607 = _parent;
    sjt_math777 = (sjt_dot607)->m11;
    sjt_dot608 = _parent;
    sjt_math778 = (sjt_dot608)->m23;
    sjt_math775 = sjt_math777 * sjt_math778;
    sjt_dot609 = _parent;
    sjt_math776 = (sjt_dot609)->m32;
    sjt_math758 = sjt_math775 * sjt_math776;
    sjt_math755 = sjt_math757 - sjt_math758;
    sjt_dot610 = _parent;
    sjt_math781 = (sjt_dot610)->m12;
    sjt_dot611 = _parent;
    sjt_math782 = (sjt_dot611)->m21;
    sjt_math779 = sjt_math781 * sjt_math782;
    sjt_dot612 = _parent;
    sjt_math780 = (sjt_dot612)->m33;
    sjt_math756 = sjt_math779 * sjt_math780;
    sjt_math753 = sjt_math755 - sjt_math756;
    sjt_dot613 = _parent;
    sjt_math785 = (sjt_dot613)->m11;
    sjt_dot614 = _parent;
    sjt_math786 = (sjt_dot614)->m22;
    sjt_math783 = sjt_math785 * sjt_math786;
    sjt_dot615 = _parent;
    sjt_math784 = (sjt_dot615)->m33;
    sjt_math754 = sjt_math783 * sjt_math784;
    sjv_t.m00 = sjt_math753 + sjt_math754;
    sjt_dot616 = _parent;
    sjt_math799 = (sjt_dot616)->m03;
    sjt_dot617 = _parent;
    sjt_math800 = (sjt_dot617)->m22;
    sjt_math797 = sjt_math799 * sjt_math800;
    sjt_dot618 = _parent;
    sjt_math798 = (sjt_dot618)->m31;
    sjt_math795 = sjt_math797 * sjt_math798;
    sjt_dot619 = _parent;
    sjt_math803 = (sjt_dot619)->m02;
    sjt_dot620 = _parent;
    sjt_math804 = (sjt_dot620)->m23;
    sjt_math801 = sjt_math803 * sjt_math804;
    sjt_dot621 = _parent;
    sjt_math802 = (sjt_dot621)->m31;
    sjt_math796 = sjt_math801 * sjt_math802;
    sjt_math793 = sjt_math795 - sjt_math796;
    sjt_dot622 = _parent;
    sjt_math807 = (sjt_dot622)->m03;
    sjt_dot623 = _parent;
    sjt_math808 = (sjt_dot623)->m21;
    sjt_math805 = sjt_math807 * sjt_math808;
    sjt_dot624 = _parent;
    sjt_math806 = (sjt_dot624)->m32;
    sjt_math794 = sjt_math805 * sjt_math806;
    sjt_math791 = sjt_math793 - sjt_math794;
    sjt_dot625 = _parent;
    sjt_math811 = (sjt_dot625)->m01;
    sjt_dot626 = _parent;
    sjt_math812 = (sjt_dot626)->m23;
    sjt_math809 = sjt_math811 * sjt_math812;
    sjt_dot627 = _parent;
    sjt_math810 = (sjt_dot627)->m32;
    sjt_math792 = sjt_math809 * sjt_math810;
    sjt_math789 = sjt_math791 + sjt_math792;
    sjt_dot628 = _parent;
    sjt_math815 = (sjt_dot628)->m02;
    sjt_dot629 = _parent;
    sjt_math816 = (sjt_dot629)->m21;
    sjt_math813 = sjt_math815 * sjt_math816;
    sjt_dot630 = _parent;
    sjt_math814 = (sjt_dot630)->m33;
    sjt_math790 = sjt_math813 * sjt_math814;
    sjt_math787 = sjt_math789 + sjt_math790;
    sjt_dot631 = _parent;
    sjt_math819 = (sjt_dot631)->m01;
    sjt_dot632 = _parent;
    sjt_math820 = (sjt_dot632)->m22;
    sjt_math817 = sjt_math819 * sjt_math820;
    sjt_dot633 = _parent;
    sjt_math818 = (sjt_dot633)->m33;
    sjt_math788 = sjt_math817 * sjt_math818;
    sjv_t.m01 = sjt_math787 - sjt_math788;
    sjt_dot634 = _parent;
    sjt_math833 = (sjt_dot634)->m02;
    sjt_dot635 = _parent;
    sjt_math834 = (sjt_dot635)->m13;
    sjt_math831 = sjt_math833 * sjt_math834;
    sjt_dot636 = _parent;
    sjt_math832 = (sjt_dot636)->m31;
    sjt_math829 = sjt_math831 * sjt_math832;
    sjt_dot637 = _parent;
    sjt_math837 = (sjt_dot637)->m03;
    sjt_dot638 = _parent;
    sjt_math838 = (sjt_dot638)->m12;
    sjt_math835 = sjt_math837 * sjt_math838;
    sjt_dot639 = _parent;
    sjt_math836 = (sjt_dot639)->m31;
    sjt_math830 = sjt_math835 * sjt_math836;
    sjt_math827 = sjt_math829 - sjt_math830;
    sjt_dot640 = _parent;
    sjt_math841 = (sjt_dot640)->m03;
    sjt_dot641 = _parent;
    sjt_math842 = (sjt_dot641)->m11;
    sjt_math839 = sjt_math841 * sjt_math842;
    sjt_dot642 = _parent;
    sjt_math840 = (sjt_dot642)->m32;
    sjt_math828 = sjt_math839 * sjt_math840;
    sjt_math825 = sjt_math827 + sjt_math828;
    sjt_dot643 = _parent;
    sjt_math845 = (sjt_dot643)->m01;
    sjt_dot644 = _parent;
    sjt_math846 = (sjt_dot644)->m13;
    sjt_math843 = sjt_math845 * sjt_math846;
    sjt_dot645 = _parent;
    sjt_math844 = (sjt_dot645)->m32;
    sjt_math826 = sjt_math843 * sjt_math844;
    sjt_math823 = sjt_math825 - sjt_math826;
    sjt_dot646 = _parent;
    sjt_math849 = (sjt_dot646)->m02;
    sjt_dot647 = _parent;
    sjt_math850 = (sjt_dot647)->m11;
    sjt_math847 = sjt_math849 * sjt_math850;
    sjt_dot648 = _parent;
    sjt_math848 = (sjt_dot648)->m33;
    sjt_math824 = sjt_math847 * sjt_math848;
    sjt_math821 = sjt_math823 - sjt_math824;
    sjt_dot649 = _parent;
    sjt_math853 = (sjt_dot649)->m01;
    sjt_dot650 = _parent;
    sjt_math854 = (sjt_dot650)->m12;
    sjt_math851 = sjt_math853 * sjt_math854;
    sjt_dot651 = _parent;
    sjt_math852 = (sjt_dot651)->m33;
    sjt_math822 = sjt_math851 * sjt_math852;
    sjv_t.m02 = sjt_math821 + sjt_math822;
    sjt_dot652 = _parent;
    sjt_math867 = (sjt_dot652)->m03;
    sjt_dot653 = _parent;
    sjt_math868 = (sjt_dot653)->m12;
    sjt_math865 = sjt_math867 * sjt_math868;
    sjt_dot654 = _parent;
    sjt_math866 = (sjt_dot654)->m21;
    sjt_math863 = sjt_math865 * sjt_math866;
    sjt_dot655 = _parent;
    sjt_math871 = (sjt_dot655)->m02;
    sjt_dot656 = _parent;
    sjt_math872 = (sjt_dot656)->m13;
    sjt_math869 = sjt_math871 * sjt_math872;
    sjt_dot657 = _parent;
    sjt_math870 = (sjt_dot657)->m21;
    sjt_math864 = sjt_math869 * sjt_math870;
    sjt_math861 = sjt_math863 - sjt_math864;
    sjt_dot658 = _parent;
    sjt_math875 = (sjt_dot658)->m03;
    sjt_dot659 = _parent;
    sjt_math876 = (sjt_dot659)->m11;
    sjt_math873 = sjt_math875 * sjt_math876;
    sjt_dot660 = _parent;
    sjt_math874 = (sjt_dot660)->m22;
    sjt_math862 = sjt_math873 * sjt_math874;
    sjt_math859 = sjt_math861 - sjt_math862;
    sjt_dot661 = _parent;
    sjt_math879 = (sjt_dot661)->m01;
    sjt_dot662 = _parent;
    sjt_math880 = (sjt_dot662)->m13;
    sjt_math877 = sjt_math879 * sjt_math880;
    sjt_dot663 = _parent;
    sjt_math878 = (sjt_dot663)->m22;
    sjt_math860 = sjt_math877 * sjt_math878;
    sjt_math857 = sjt_math859 + sjt_math860;
    sjt_dot664 = _parent;
    sjt_math883 = (sjt_dot664)->m02;
    sjt_dot665 = _parent;
    sjt_math884 = (sjt_dot665)->m11;
    sjt_math881 = sjt_math883 * sjt_math884;
    sjt_dot666 = _parent;
    sjt_math882 = (sjt_dot666)->m23;
    sjt_math858 = sjt_math881 * sjt_math882;
    sjt_math855 = sjt_math857 + sjt_math858;
    sjt_dot667 = _parent;
    sjt_math887 = (sjt_dot667)->m01;
    sjt_dot668 = _parent;
    sjt_math888 = (sjt_dot668)->m12;
    sjt_math885 = sjt_math887 * sjt_math888;
    sjt_dot669 = _parent;
    sjt_math886 = (sjt_dot669)->m23;
    sjt_math856 = sjt_math885 * sjt_math886;
    sjv_t.m03 = sjt_math855 - sjt_math856;
    sjt_dot670 = _parent;
    sjt_math901 = (sjt_dot670)->m13;
    sjt_dot671 = _parent;
    sjt_math902 = (sjt_dot671)->m22;
    sjt_math899 = sjt_math901 * sjt_math902;
    sjt_dot672 = _parent;
    sjt_math900 = (sjt_dot672)->m30;
    sjt_math897 = sjt_math899 * sjt_math900;
    sjt_dot673 = _parent;
    sjt_math905 = (sjt_dot673)->m12;
    sjt_dot674 = _parent;
    sjt_math906 = (sjt_dot674)->m23;
    sjt_math903 = sjt_math905 * sjt_math906;
    sjt_dot675 = _parent;
    sjt_math904 = (sjt_dot675)->m30;
    sjt_math898 = sjt_math903 * sjt_math904;
    sjt_math895 = sjt_math897 - sjt_math898;
    sjt_dot676 = _parent;
    sjt_math909 = (sjt_dot676)->m13;
    sjt_dot677 = _parent;
    sjt_math910 = (sjt_dot677)->m20;
    sjt_math907 = sjt_math909 * sjt_math910;
    sjt_dot678 = _parent;
    sjt_math908 = (sjt_dot678)->m32;
    sjt_math896 = sjt_math907 * sjt_math908;
    sjt_math893 = sjt_math895 - sjt_math896;
    sjt_dot679 = _parent;
    sjt_math913 = (sjt_dot679)->m10;
    sjt_dot680 = _parent;
    sjt_math914 = (sjt_dot680)->m23;
    sjt_math911 = sjt_math913 * sjt_math914;
    sjt_dot681 = _parent;
    sjt_math912 = (sjt_dot681)->m32;
    sjt_math894 = sjt_math911 * sjt_math912;
    sjt_math891 = sjt_math893 + sjt_math894;
    sjt_dot682 = _parent;
    sjt_math917 = (sjt_dot682)->m12;
    sjt_dot683 = _parent;
    sjt_math918 = (sjt_dot683)->m20;
    sjt_math915 = sjt_math917 * sjt_math918;
    sjt_dot684 = _parent;
    sjt_math916 = (sjt_dot684)->m33;
    sjt_math892 = sjt_math915 * sjt_math916;
    sjt_math889 = sjt_math891 + sjt_math892;
    sjt_dot685 = _parent;
    sjt_math921 = (sjt_dot685)->m10;
    sjt_dot686 = _parent;
    sjt_math922 = (sjt_dot686)->m22;
    sjt_math919 = sjt_math921 * sjt_math922;
    sjt_dot687 = _parent;
    sjt_math920 = (sjt_dot687)->m33;
    sjt_math890 = sjt_math919 * sjt_math920;
    sjv_t.m10 = sjt_math889 - sjt_math890;
    sjt_dot688 = _parent;
    sjt_math935 = (sjt_dot688)->m02;
    sjt_dot689 = _parent;
    sjt_math936 = (sjt_dot689)->m23;
    sjt_math933 = sjt_math935 * sjt_math936;
    sjt_dot690 = _parent;
    sjt_math934 = (sjt_dot690)->m30;
    sjt_math931 = sjt_math933 * sjt_math934;
    sjt_dot691 = _parent;
    sjt_math939 = (sjt_dot691)->m03;
    sjt_dot692 = _parent;
    sjt_math940 = (sjt_dot692)->m22;
    sjt_math937 = sjt_math939 * sjt_math940;
    sjt_dot693 = _parent;
    sjt_math938 = (sjt_dot693)->m30;
    sjt_math932 = sjt_math937 * sjt_math938;
    sjt_math929 = sjt_math931 - sjt_math932;
    sjt_dot694 = _parent;
    sjt_math943 = (sjt_dot694)->m03;
    sjt_dot695 = _parent;
    sjt_math944 = (sjt_dot695)->m20;
    sjt_math941 = sjt_math943 * sjt_math944;
    sjt_dot696 = _parent;
    sjt_math942 = (sjt_dot696)->m32;
    sjt_math930 = sjt_math941 * sjt_math942;
    sjt_math927 = sjt_math929 + sjt_math930;
    sjt_dot697 = _parent;
    sjt_math947 = (sjt_dot697)->m00;
    sjt_dot698 = _parent;
    sjt_math948 = (sjt_dot698)->m23;
    sjt_math945 = sjt_math947 * sjt_math948;
    sjt_dot699 = _parent;
    sjt_math946 = (sjt_dot699)->m32;
    sjt_math928 = sjt_math945 * sjt_math946;
    sjt_math925 = sjt_math927 - sjt_math928;
    sjt_dot700 = _parent;
    sjt_math951 = (sjt_dot700)->m02;
    sjt_dot701 = _parent;
    sjt_math952 = (sjt_dot701)->m20;
    sjt_math949 = sjt_math951 * sjt_math952;
    sjt_dot702 = _parent;
    sjt_math950 = (sjt_dot702)->m33;
    sjt_math926 = sjt_math949 * sjt_math950;
    sjt_math923 = sjt_math925 - sjt_math926;
    sjt_dot703 = _parent;
    sjt_math955 = (sjt_dot703)->m00;
    sjt_dot704 = _parent;
    sjt_math956 = (sjt_dot704)->m22;
    sjt_math953 = sjt_math955 * sjt_math956;
    sjt_dot705 = _parent;
    sjt_math954 = (sjt_dot705)->m33;
    sjt_math924 = sjt_math953 * sjt_math954;
    sjv_t.m11 = sjt_math923 + sjt_math924;
    sjt_dot706 = _parent;
    sjt_math969 = (sjt_dot706)->m03;
    sjt_dot707 = _parent;
    sjt_math970 = (sjt_dot707)->m12;
    sjt_math967 = sjt_math969 * sjt_math970;
    sjt_dot708 = _parent;
    sjt_math968 = (sjt_dot708)->m30;
    sjt_math965 = sjt_math967 * sjt_math968;
    sjt_dot709 = _parent;
    sjt_math973 = (sjt_dot709)->m02;
    sjt_dot710 = _parent;
    sjt_math974 = (sjt_dot710)->m13;
    sjt_math971 = sjt_math973 * sjt_math974;
    sjt_dot711 = _parent;
    sjt_math972 = (sjt_dot711)->m30;
    sjt_math966 = sjt_math971 * sjt_math972;
    sjt_math963 = sjt_math965 - sjt_math966;
    sjt_dot712 = _parent;
    sjt_math977 = (sjt_dot712)->m03;
    sjt_dot713 = _parent;
    sjt_math978 = (sjt_dot713)->m10;
    sjt_math975 = sjt_math977 * sjt_math978;
    sjt_dot714 = _parent;
    sjt_math976 = (sjt_dot714)->m32;
    sjt_math964 = sjt_math975 * sjt_math976;
    sjt_math961 = sjt_math963 - sjt_math964;
    sjt_dot715 = _parent;
    sjt_math981 = (sjt_dot715)->m00;
    sjt_dot716 = _parent;
    sjt_math982 = (sjt_dot716)->m13;
    sjt_math979 = sjt_math981 * sjt_math982;
    sjt_dot717 = _parent;
    sjt_math980 = (sjt_dot717)->m32;
    sjt_math962 = sjt_math979 * sjt_math980;
    sjt_math959 = sjt_math961 + sjt_math962;
    sjt_dot718 = _parent;
    sjt_math985 = (sjt_dot718)->m02;
    sjt_dot719 = _parent;
    sjt_math986 = (sjt_dot719)->m10;
    sjt_math983 = sjt_math985 * sjt_math986;
    sjt_dot720 = _parent;
    sjt_math984 = (sjt_dot720)->m33;
    sjt_math960 = sjt_math983 * sjt_math984;
    sjt_math957 = sjt_math959 + sjt_math960;
    sjt_dot721 = _parent;
    sjt_math989 = (sjt_dot721)->m00;
    sjt_dot722 = _parent;
    sjt_math990 = (sjt_dot722)->m12;
    sjt_math987 = sjt_math989 * sjt_math990;
    sjt_dot723 = _parent;
    sjt_math988 = (sjt_dot723)->m33;
    sjt_math958 = sjt_math987 * sjt_math988;
    sjv_t.m12 = sjt_math957 - sjt_math958;
    sjt_dot724 = _parent;
    sjt_math1003 = (sjt_dot724)->m02;
    sjt_dot725 = _parent;
    sjt_math1004 = (sjt_dot725)->m13;
    sjt_math1001 = sjt_math1003 * sjt_math1004;
    sjt_dot726 = _parent;
    sjt_math1002 = (sjt_dot726)->m20;
    sjt_math999 = sjt_math1001 * sjt_math1002;
    sjt_dot727 = _parent;
    sjt_math1007 = (sjt_dot727)->m03;
    sjt_dot728 = _parent;
    sjt_math1008 = (sjt_dot728)->m12;
    sjt_math1005 = sjt_math1007 * sjt_math1008;
    sjt_dot729 = _parent;
    sjt_math1006 = (sjt_dot729)->m20;
    sjt_math1000 = sjt_math1005 * sjt_math1006;
    sjt_math997 = sjt_math999 - sjt_math1000;
    sjt_dot730 = _parent;
    sjt_math1011 = (sjt_dot730)->m03;
    sjt_dot731 = _parent;
    sjt_math1012 = (sjt_dot731)->m10;
    sjt_math1009 = sjt_math1011 * sjt_math1012;
    sjt_dot732 = _parent;
    sjt_math1010 = (sjt_dot732)->m22;
    sjt_math998 = sjt_math1009 * sjt_math1010;
    sjt_math995 = sjt_math997 + sjt_math998;
    sjt_dot733 = _parent;
    sjt_math1015 = (sjt_dot733)->m00;
    sjt_dot734 = _parent;
    sjt_math1016 = (sjt_dot734)->m13;
    sjt_math1013 = sjt_math1015 * sjt_math1016;
    sjt_dot735 = _parent;
    sjt_math1014 = (sjt_dot735)->m22;
    sjt_math996 = sjt_math1013 * sjt_math1014;
    sjt_math993 = sjt_math995 - sjt_math996;
    sjt_dot736 = _parent;
    sjt_math1019 = (sjt_dot736)->m02;
    sjt_dot737 = _parent;
    sjt_math1020 = (sjt_dot737)->m10;
    sjt_math1017 = sjt_math1019 * sjt_math1020;
    sjt_dot738 = _parent;
    sjt_math1018 = (sjt_dot738)->m23;
    sjt_math994 = sjt_math1017 * sjt_math1018;
    sjt_math991 = sjt_math993 - sjt_math994;
    sjt_dot739 = _parent;
    sjt_math1023 = (sjt_dot739)->m00;
    sjt_dot740 = _parent;
    sjt_math1024 = (sjt_dot740)->m12;
    sjt_math1021 = sjt_math1023 * sjt_math1024;
    sjt_dot741 = _parent;
    sjt_math1022 = (sjt_dot741)->m23;
    sjt_math992 = sjt_math1021 * sjt_math1022;
    sjv_t.m13 = sjt_math991 + sjt_math992;
    sjt_dot742 = _parent;
    sjt_math1037 = (sjt_dot742)->m11;
    sjt_dot743 = _parent;
    sjt_math1038 = (sjt_dot743)->m23;
    sjt_math1035 = sjt_math1037 * sjt_math1038;
    sjt_dot744 = _parent;
    sjt_math1036 = (sjt_dot744)->m30;
    sjt_math1033 = sjt_math1035 * sjt_math1036;
    sjt_dot745 = _parent;
    sjt_math1041 = (sjt_dot745)->m13;
    sjt_dot746 = _parent;
    sjt_math1042 = (sjt_dot746)->m21;
    sjt_math1039 = sjt_math1041 * sjt_math1042;
    sjt_dot747 = _parent;
    sjt_math1040 = (sjt_dot747)->m30;
    sjt_math1034 = sjt_math1039 * sjt_math1040;
    sjt_math1031 = sjt_math1033 - sjt_math1034;
    sjt_dot748 = _parent;
    sjt_math1045 = (sjt_dot748)->m13;
    sjt_dot749 = _parent;
    sjt_math1046 = (sjt_dot749)->m20;
    sjt_math1043 = sjt_math1045 * sjt_math1046;
    sjt_dot750 = _parent;
    sjt_math1044 = (sjt_dot750)->m31;
    sjt_math1032 = sjt_math1043 * sjt_math1044;
    sjt_math1029 = sjt_math1031 + sjt_math1032;
    sjt_dot751 = _parent;
    sjt_math1049 = (sjt_dot751)->m10;
    sjt_dot752 = _parent;
    sjt_math1050 = (sjt_dot752)->m23;
    sjt_math1047 = sjt_math1049 * sjt_math1050;
    sjt_dot753 = _parent;
    sjt_math1048 = (sjt_dot753)->m31;
    sjt_math1030 = sjt_math1047 * sjt_math1048;
    sjt_math1027 = sjt_math1029 - sjt_math1030;
    sjt_dot754 = _parent;
    sjt_math1053 = (sjt_dot754)->m11;
    sjt_dot755 = _parent;
    sjt_math1054 = (sjt_dot755)->m20;
    sjt_math1051 = sjt_math1053 * sjt_math1054;
    sjt_dot756 = _parent;
    sjt_math1052 = (sjt_dot756)->m33;
    sjt_math1028 = sjt_math1051 * sjt_math1052;
    sjt_math1025 = sjt_math1027 - sjt_math1028;
    sjt_dot757 = _parent;
    sjt_math1057 = (sjt_dot757)->m10;
    sjt_dot758 = _parent;
    sjt_math1058 = (sjt_dot758)->m21;
    sjt_math1055 = sjt_math1057 * sjt_math1058;
    sjt_dot759 = _parent;
    sjt_math1056 = (sjt_dot759)->m33;
    sjt_math1026 = sjt_math1055 * sjt_math1056;
    sjv_t.m20 = sjt_math1025 + sjt_math1026;
    sjt_dot760 = _parent;
    sjt_math1071 = (sjt_dot760)->m03;
    sjt_dot761 = _parent;
    sjt_math1072 = (sjt_dot761)->m21;
    sjt_math1069 = sjt_math1071 * sjt_math1072;
    sjt_dot762 = _parent;
    sjt_math1070 = (sjt_dot762)->m30;
    sjt_math1067 = sjt_math1069 * sjt_math1070;
    sjt_dot763 = _parent;
    sjt_math1075 = (sjt_dot763)->m01;
    sjt_dot764 = _parent;
    sjt_math1076 = (sjt_dot764)->m23;
    sjt_math1073 = sjt_math1075 * sjt_math1076;
    sjt_dot765 = _parent;
    sjt_math1074 = (sjt_dot765)->m30;
    sjt_math1068 = sjt_math1073 * sjt_math1074;
    sjt_math1065 = sjt_math1067 - sjt_math1068;
    sjt_dot766 = _parent;
    sjt_math1079 = (sjt_dot766)->m03;
    sjt_dot767 = _parent;
    sjt_math1080 = (sjt_dot767)->m20;
    sjt_math1077 = sjt_math1079 * sjt_math1080;
    sjt_dot768 = _parent;
    sjt_math1078 = (sjt_dot768)->m31;
    sjt_math1066 = sjt_math1077 * sjt_math1078;
    sjt_math1063 = sjt_math1065 - sjt_math1066;
    sjt_dot769 = _parent;
    sjt_math1083 = (sjt_dot769)->m00;
    sjt_dot770 = _parent;
    sjt_math1084 = (sjt_dot770)->m23;
    sjt_math1081 = sjt_math1083 * sjt_math1084;
    sjt_dot771 = _parent;
    sjt_math1082 = (sjt_dot771)->m31;
    sjt_math1064 = sjt_math1081 * sjt_math1082;
    sjt_math1061 = sjt_math1063 + sjt_math1064;
    sjt_dot772 = _parent;
    sjt_math1087 = (sjt_dot772)->m01;
    sjt_dot773 = _parent;
    sjt_math1088 = (sjt_dot773)->m20;
    sjt_math1085 = sjt_math1087 * sjt_math1088;
    sjt_dot774 = _parent;
    sjt_math1086 = (sjt_dot774)->m33;
    sjt_math1062 = sjt_math1085 * sjt_math1086;
    sjt_math1059 = sjt_math1061 + sjt_math1062;
    sjt_dot775 = _parent;
    sjt_math1091 = (sjt_dot775)->m00;
    sjt_dot776 = _parent;
    sjt_math1092 = (sjt_dot776)->m21;
    sjt_math1089 = sjt_math1091 * sjt_math1092;
    sjt_dot777 = _parent;
    sjt_math1090 = (sjt_dot777)->m33;
    sjt_math1060 = sjt_math1089 * sjt_math1090;
    sjv_t.m21 = sjt_math1059 - sjt_math1060;
    sjt_dot778 = _parent;
    sjt_math1105 = (sjt_dot778)->m01;
    sjt_dot779 = _parent;
    sjt_math1106 = (sjt_dot779)->m13;
    sjt_math1103 = sjt_math1105 * sjt_math1106;
    sjt_dot780 = _parent;
    sjt_math1104 = (sjt_dot780)->m30;
    sjt_math1101 = sjt_math1103 * sjt_math1104;
    sjt_dot781 = _parent;
    sjt_math1109 = (sjt_dot781)->m03;
    sjt_dot782 = _parent;
    sjt_math1110 = (sjt_dot782)->m11;
    sjt_math1107 = sjt_math1109 * sjt_math1110;
    sjt_dot783 = _parent;
    sjt_math1108 = (sjt_dot783)->m30;
    sjt_math1102 = sjt_math1107 * sjt_math1108;
    sjt_math1099 = sjt_math1101 - sjt_math1102;
    sjt_dot784 = _parent;
    sjt_math1113 = (sjt_dot784)->m03;
    sjt_dot785 = _parent;
    sjt_math1114 = (sjt_dot785)->m10;
    sjt_math1111 = sjt_math1113 * sjt_math1114;
    sjt_dot786 = _parent;
    sjt_math1112 = (sjt_dot786)->m31;
    sjt_math1100 = sjt_math1111 * sjt_math1112;
    sjt_math1097 = sjt_math1099 + sjt_math1100;
    sjt_dot787 = _parent;
    sjt_math1117 = (sjt_dot787)->m00;
    sjt_dot788 = _parent;
    sjt_math1118 = (sjt_dot788)->m13;
    sjt_math1115 = sjt_math1117 * sjt_math1118;
    sjt_dot789 = _parent;
    sjt_math1116 = (sjt_dot789)->m31;
    sjt_math1098 = sjt_math1115 * sjt_math1116;
    sjt_math1095 = sjt_math1097 - sjt_math1098;
    sjt_dot790 = _parent;
    sjt_math1121 = (sjt_dot790)->m01;
    sjt_dot791 = _parent;
    sjt_math1122 = (sjt_dot791)->m10;
    sjt_math1119 = sjt_math1121 * sjt_math1122;
    sjt_dot792 = _parent;
    sjt_math1120 = (sjt_dot792)->m33;
    sjt_math1096 = sjt_math1119 * sjt_math1120;
    sjt_math1093 = sjt_math1095 - sjt_math1096;
    sjt_dot793 = _parent;
    sjt_math1125 = (sjt_dot793)->m00;
    sjt_dot794 = _parent;
    sjt_math1126 = (sjt_dot794)->m11;
    sjt_math1123 = sjt_math1125 * sjt_math1126;
    sjt_dot795 = _parent;
    sjt_math1124 = (sjt_dot795)->m33;
    sjt_math1094 = sjt_math1123 * sjt_math1124;
    sjv_t.m22 = sjt_math1093 + sjt_math1094;
    sjt_dot796 = _parent;
    sjt_math1139 = (sjt_dot796)->m03;
    sjt_dot797 = _parent;
    sjt_math1140 = (sjt_dot797)->m11;
    sjt_math1137 = sjt_math1139 * sjt_math1140;
    sjt_dot798 = _parent;
    sjt_math1138 = (sjt_dot798)->m20;
    sjt_math1135 = sjt_math1137 * sjt_math1138;
    sjt_dot799 = _parent;
    sjt_math1143 = (sjt_dot799)->m01;
    sjt_dot800 = _parent;
    sjt_math1144 = (sjt_dot800)->m13;
    sjt_math1141 = sjt_math1143 * sjt_math1144;
    sjt_dot801 = _parent;
    sjt_math1142 = (sjt_dot801)->m20;
    sjt_math1136 = sjt_math1141 * sjt_math1142;
    sjt_math1133 = sjt_math1135 - sjt_math1136;
    sjt_dot802 = _parent;
    sjt_math1147 = (sjt_dot802)->m03;
    sjt_dot803 = _parent;
    sjt_math1148 = (sjt_dot803)->m10;
    sjt_math1145 = sjt_math1147 * sjt_math1148;
    sjt_dot804 = _parent;
    sjt_math1146 = (sjt_dot804)->m21;
    sjt_math1134 = sjt_math1145 * sjt_math1146;
    sjt_math1131 = sjt_math1133 - sjt_math1134;
    sjt_dot805 = _parent;
    sjt_math1151 = (sjt_dot805)->m00;
    sjt_dot806 = _parent;
    sjt_math1152 = (sjt_dot806)->m13;
    sjt_math1149 = sjt_math1151 * sjt_math1152;
    sjt_dot807 = _parent;
    sjt_math1150 = (sjt_dot807)->m21;
    sjt_math1132 = sjt_math1149 * sjt_math1150;
    sjt_math1129 = sjt_math1131 + sjt_math1132;
    sjt_dot808 = _parent;
    sjt_math1155 = (sjt_dot808)->m01;
    sjt_dot809 = _parent;
    sjt_math1156 = (sjt_dot809)->m10;
    sjt_math1153 = sjt_math1155 * sjt_math1156;
    sjt_dot810 = _parent;
    sjt_math1154 = (sjt_dot810)->m23;
    sjt_math1130 = sjt_math1153 * sjt_math1154;
    sjt_math1127 = sjt_math1129 + sjt_math1130;
    sjt_dot811 = _parent;
    sjt_math1159 = (sjt_dot811)->m00;
    sjt_dot812 = _parent;
    sjt_math1160 = (sjt_dot812)->m11;
    sjt_math1157 = sjt_math1159 * sjt_math1160;
    sjt_dot813 = _parent;
    sjt_math1158 = (sjt_dot813)->m23;
    sjt_math1128 = sjt_math1157 * sjt_math1158;
    sjv_t.m23 = sjt_math1127 - sjt_math1128;
    sjt_dot814 = _parent;
    sjt_math1173 = (sjt_dot814)->m12;
    sjt_dot815 = _parent;
    sjt_math1174 = (sjt_dot815)->m21;
    sjt_math1171 = sjt_math1173 * sjt_math1174;
    sjt_dot816 = _parent;
    sjt_math1172 = (sjt_dot816)->m30;
    sjt_math1169 = sjt_math1171 * sjt_math1172;
    sjt_dot817 = _parent;
    sjt_math1177 = (sjt_dot817)->m11;
    sjt_dot818 = _parent;
    sjt_math1178 = (sjt_dot818)->m22;
    sjt_math1175 = sjt_math1177 * sjt_math1178;
    sjt_dot819 = _parent;
    sjt_math1176 = (sjt_dot819)->m30;
    sjt_math1170 = sjt_math1175 * sjt_math1176;
    sjt_math1167 = sjt_math1169 - sjt_math1170;
    sjt_dot820 = _parent;
    sjt_math1181 = (sjt_dot820)->m12;
    sjt_dot821 = _parent;
    sjt_math1182 = (sjt_dot821)->m20;
    sjt_math1179 = sjt_math1181 * sjt_math1182;
    sjt_dot822 = _parent;
    sjt_math1180 = (sjt_dot822)->m31;
    sjt_math1168 = sjt_math1179 * sjt_math1180;
    sjt_math1165 = sjt_math1167 - sjt_math1168;
    sjt_dot823 = _parent;
    sjt_math1185 = (sjt_dot823)->m10;
    sjt_dot824 = _parent;
    sjt_math1186 = (sjt_dot824)->m22;
    sjt_math1183 = sjt_math1185 * sjt_math1186;
    sjt_dot825 = _parent;
    sjt_math1184 = (sjt_dot825)->m31;
    sjt_math1166 = sjt_math1183 * sjt_math1184;
    sjt_math1163 = sjt_math1165 + sjt_math1166;
    sjt_dot826 = _parent;
    sjt_math1189 = (sjt_dot826)->m11;
    sjt_dot827 = _parent;
    sjt_math1190 = (sjt_dot827)->m20;
    sjt_math1187 = sjt_math1189 * sjt_math1190;
    sjt_dot828 = _parent;
    sjt_math1188 = (sjt_dot828)->m32;
    sjt_math1164 = sjt_math1187 * sjt_math1188;
    sjt_math1161 = sjt_math1163 + sjt_math1164;
    sjt_dot829 = _parent;
    sjt_math1193 = (sjt_dot829)->m10;
    sjt_dot830 = _parent;
    sjt_math1194 = (sjt_dot830)->m21;
    sjt_math1191 = sjt_math1193 * sjt_math1194;
    sjt_dot831 = _parent;
    sjt_math1192 = (sjt_dot831)->m32;
    sjt_math1162 = sjt_math1191 * sjt_math1192;
    sjv_t.m30 = sjt_math1161 - sjt_math1162;
    sjt_dot832 = _parent;
    sjt_math1207 = (sjt_dot832)->m01;
    sjt_dot833 = _parent;
    sjt_math1208 = (sjt_dot833)->m22;
    sjt_math1205 = sjt_math1207 * sjt_math1208;
    sjt_dot834 = _parent;
    sjt_math1206 = (sjt_dot834)->m30;
    sjt_math1203 = sjt_math1205 * sjt_math1206;
    sjt_dot835 = _parent;
    sjt_math1211 = (sjt_dot835)->m02;
    sjt_dot836 = _parent;
    sjt_math1212 = (sjt_dot836)->m21;
    sjt_math1209 = sjt_math1211 * sjt_math1212;
    sjt_dot837 = _parent;
    sjt_math1210 = (sjt_dot837)->m30;
    sjt_math1204 = sjt_math1209 * sjt_math1210;
    sjt_math1201 = sjt_math1203 - sjt_math1204;
    sjt_dot838 = _parent;
    sjt_math1215 = (sjt_dot838)->m02;
    sjt_dot839 = _parent;
    sjt_math1216 = (sjt_dot839)->m20;
    sjt_math1213 = sjt_math1215 * sjt_math1216;
    sjt_dot840 = _parent;
    sjt_math1214 = (sjt_dot840)->m31;
    sjt_math1202 = sjt_math1213 * sjt_math1214;
    sjt_math1199 = sjt_math1201 + sjt_math1202;
    sjt_dot841 = _parent;
    sjt_math1219 = (sjt_dot841)->m00;
    sjt_dot842 = _parent;
    sjt_math1220 = (sjt_dot842)->m22;
    sjt_math1217 = sjt_math1219 * sjt_math1220;
    sjt_dot843 = _parent;
    sjt_math1218 = (sjt_dot843)->m31;
    sjt_math1200 = sjt_math1217 * sjt_math1218;
    sjt_math1197 = sjt_math1199 - sjt_math1200;
    sjt_dot844 = _parent;
    sjt_math1223 = (sjt_dot844)->m01;
    sjt_dot845 = _parent;
    sjt_math1224 = (sjt_dot845)->m20;
    sjt_math1221 = sjt_math1223 * sjt_math1224;
    sjt_dot846 = _parent;
    sjt_math1222 = (sjt_dot846)->m32;
    sjt_math1198 = sjt_math1221 * sjt_math1222;
    sjt_math1195 = sjt_math1197 - sjt_math1198;
    sjt_dot847 = _parent;
    sjt_math1227 = (sjt_dot847)->m00;
    sjt_dot848 = _parent;
    sjt_math1228 = (sjt_dot848)->m21;
    sjt_math1225 = sjt_math1227 * sjt_math1228;
    sjt_dot849 = _parent;
    sjt_math1226 = (sjt_dot849)->m32;
    sjt_math1196 = sjt_math1225 * sjt_math1226;
    sjv_t.m31 = sjt_math1195 + sjt_math1196;
    sjt_dot850 = _parent;
    sjt_math1241 = (sjt_dot850)->m02;
    sjt_dot851 = _parent;
    sjt_math1242 = (sjt_dot851)->m11;
    sjt_math1239 = sjt_math1241 * sjt_math1242;
    sjt_dot852 = _parent;
    sjt_math1240 = (sjt_dot852)->m30;
    sjt_math1237 = sjt_math1239 * sjt_math1240;
    sjt_dot853 = _parent;
    sjt_math1245 = (sjt_dot853)->m01;
    sjt_dot854 = _parent;
    sjt_math1246 = (sjt_dot854)->m12;
    sjt_math1243 = sjt_math1245 * sjt_math1246;
    sjt_dot855 = _parent;
    sjt_math1244 = (sjt_dot855)->m30;
    sjt_math1238 = sjt_math1243 * sjt_math1244;
    sjt_math1235 = sjt_math1237 - sjt_math1238;
    sjt_dot856 = _parent;
    sjt_math1249 = (sjt_dot856)->m02;
    sjt_dot857 = _parent;
    sjt_math1250 = (sjt_dot857)->m10;
    sjt_math1247 = sjt_math1249 * sjt_math1250;
    sjt_dot858 = _parent;
    sjt_math1248 = (sjt_dot858)->m31;
    sjt_math1236 = sjt_math1247 * sjt_math1248;
    sjt_math1233 = sjt_math1235 - sjt_math1236;
    sjt_dot859 = _parent;
    sjt_math1253 = (sjt_dot859)->m00;
    sjt_dot860 = _parent;
    sjt_math1254 = (sjt_dot860)->m12;
    sjt_math1251 = sjt_math1253 * sjt_math1254;
    sjt_dot861 = _parent;
    sjt_math1252 = (sjt_dot861)->m31;
    sjt_math1234 = sjt_math1251 * sjt_math1252;
    sjt_math1231 = sjt_math1233 + sjt_math1234;
    sjt_dot862 = _parent;
    sjt_math1257 = (sjt_dot862)->m01;
    sjt_dot863 = _parent;
    sjt_math1258 = (sjt_dot863)->m10;
    sjt_math1255 = sjt_math1257 * sjt_math1258;
    sjt_dot864 = _parent;
    sjt_math1256 = (sjt_dot864)->m32;
    sjt_math1232 = sjt_math1255 * sjt_math1256;
    sjt_math1229 = sjt_math1231 + sjt_math1232;
    sjt_dot865 = _parent;
    sjt_math1261 = (sjt_dot865)->m00;
    sjt_dot866 = _parent;
    sjt_math1262 = (sjt_dot866)->m11;
    sjt_math1259 = sjt_math1261 * sjt_math1262;
    sjt_dot867 = _parent;
    sjt_math1260 = (sjt_dot867)->m32;
    sjt_math1230 = sjt_math1259 * sjt_math1260;
    sjv_t.m32 = sjt_math1229 - sjt_math1230;
    sjt_dot868 = _parent;
    sjt_math1275 = (sjt_dot868)->m01;
    sjt_dot869 = _parent;
    sjt_math1276 = (sjt_dot869)->m12;
    sjt_math1273 = sjt_math1275 * sjt_math1276;
    sjt_dot870 = _parent;
    sjt_math1274 = (sjt_dot870)->m20;
    sjt_math1271 = sjt_math1273 * sjt_math1274;
    sjt_dot871 = _parent;
    sjt_math1279 = (sjt_dot871)->m02;
    sjt_dot872 = _parent;
    sjt_math1280 = (sjt_dot872)->m11;
    sjt_math1277 = sjt_math1279 * sjt_math1280;
    sjt_dot873 = _parent;
    sjt_math1278 = (sjt_dot873)->m20;
    sjt_math1272 = sjt_math1277 * sjt_math1278;
    sjt_math1269 = sjt_math1271 - sjt_math1272;
    sjt_dot874 = _parent;
    sjt_math1283 = (sjt_dot874)->m02;
    sjt_dot875 = _parent;
    sjt_math1284 = (sjt_dot875)->m10;
    sjt_math1281 = sjt_math1283 * sjt_math1284;
    sjt_dot876 = _parent;
    sjt_math1282 = (sjt_dot876)->m21;
    sjt_math1270 = sjt_math1281 * sjt_math1282;
    sjt_math1267 = sjt_math1269 + sjt_math1270;
    sjt_dot877 = _parent;
    sjt_math1287 = (sjt_dot877)->m00;
    sjt_dot878 = _parent;
    sjt_math1288 = (sjt_dot878)->m12;
    sjt_math1285 = sjt_math1287 * sjt_math1288;
    sjt_dot879 = _parent;
    sjt_math1286 = (sjt_dot879)->m21;
    sjt_math1268 = sjt_math1285 * sjt_math1286;
    sjt_math1265 = sjt_math1267 - sjt_math1268;
    sjt_dot880 = _parent;
    sjt_math1291 = (sjt_dot880)->m01;
    sjt_dot881 = _parent;
    sjt_math1292 = (sjt_dot881)->m10;
    sjt_math1289 = sjt_math1291 * sjt_math1292;
    sjt_dot882 = _parent;
    sjt_math1290 = (sjt_dot882)->m22;
    sjt_math1266 = sjt_math1289 * sjt_math1290;
    sjt_math1263 = sjt_math1265 - sjt_math1266;
    sjt_dot883 = _parent;
    sjt_math1295 = (sjt_dot883)->m00;
    sjt_dot884 = _parent;
    sjt_math1296 = (sjt_dot884)->m11;
    sjt_math1293 = sjt_math1295 * sjt_math1296;
    sjt_dot885 = _parent;
    sjt_math1294 = (sjt_dot885)->m22;
    sjt_math1264 = sjt_math1293 * sjt_math1294;
    sjv_t.m33 = sjt_math1263 + sjt_math1264;
    sjf_mat4(&sjv_t);
    sjt_parent53 = &sjv_t;
    sjt_math1361 = 1.0f;
    sjf_mat4_determinant(_parent, &sjt_math1362);
    sjt_functionParam119 = sjt_math1361 / sjt_math1362;
    sjf_mat4_multiplyf32(sjt_parent53, sjt_functionParam119, _return);

    if (sjv_t._refCount == 1) { sjf_mat4_destroy(&sjv_t); }
}

void sjf_mat4_invert_heap(sjs_mat4* _parent, sjs_mat4** _return) {
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
    float sjt_functionParam120;
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
    sjs_mat4* sjt_parent54 = 0;
    sjs_mat4 sjv_t = { -1 };

    sjv_t._refCount = 1;
    sjt_dot1014 = _parent;
    sjt_math1565 = (sjt_dot1014)->m12;
    sjt_dot1015 = _parent;
    sjt_math1566 = (sjt_dot1015)->m23;
    sjt_math1563 = sjt_math1565 * sjt_math1566;
    sjt_dot1016 = _parent;
    sjt_math1564 = (sjt_dot1016)->m31;
    sjt_math1561 = sjt_math1563 * sjt_math1564;
    sjt_dot1017 = _parent;
    sjt_math1569 = (sjt_dot1017)->m13;
    sjt_dot1018 = _parent;
    sjt_math1570 = (sjt_dot1018)->m22;
    sjt_math1567 = sjt_math1569 * sjt_math1570;
    sjt_dot1019 = _parent;
    sjt_math1568 = (sjt_dot1019)->m31;
    sjt_math1562 = sjt_math1567 * sjt_math1568;
    sjt_math1559 = sjt_math1561 - sjt_math1562;
    sjt_dot1020 = _parent;
    sjt_math1573 = (sjt_dot1020)->m13;
    sjt_dot1021 = _parent;
    sjt_math1574 = (sjt_dot1021)->m21;
    sjt_math1571 = sjt_math1573 * sjt_math1574;
    sjt_dot1022 = _parent;
    sjt_math1572 = (sjt_dot1022)->m32;
    sjt_math1560 = sjt_math1571 * sjt_math1572;
    sjt_math1557 = sjt_math1559 + sjt_math1560;
    sjt_dot1023 = _parent;
    sjt_math1577 = (sjt_dot1023)->m11;
    sjt_dot1024 = _parent;
    sjt_math1578 = (sjt_dot1024)->m23;
    sjt_math1575 = sjt_math1577 * sjt_math1578;
    sjt_dot1025 = _parent;
    sjt_math1576 = (sjt_dot1025)->m32;
    sjt_math1558 = sjt_math1575 * sjt_math1576;
    sjt_math1555 = sjt_math1557 - sjt_math1558;
    sjt_dot1026 = _parent;
    sjt_math1581 = (sjt_dot1026)->m12;
    sjt_dot1027 = _parent;
    sjt_math1582 = (sjt_dot1027)->m21;
    sjt_math1579 = sjt_math1581 * sjt_math1582;
    sjt_dot1028 = _parent;
    sjt_math1580 = (sjt_dot1028)->m33;
    sjt_math1556 = sjt_math1579 * sjt_math1580;
    sjt_math1553 = sjt_math1555 - sjt_math1556;
    sjt_dot1029 = _parent;
    sjt_math1585 = (sjt_dot1029)->m11;
    sjt_dot1030 = _parent;
    sjt_math1586 = (sjt_dot1030)->m22;
    sjt_math1583 = sjt_math1585 * sjt_math1586;
    sjt_dot1031 = _parent;
    sjt_math1584 = (sjt_dot1031)->m33;
    sjt_math1554 = sjt_math1583 * sjt_math1584;
    sjv_t.m00 = sjt_math1553 + sjt_math1554;
    sjt_dot1032 = _parent;
    sjt_math1599 = (sjt_dot1032)->m03;
    sjt_dot1033 = _parent;
    sjt_math1600 = (sjt_dot1033)->m22;
    sjt_math1597 = sjt_math1599 * sjt_math1600;
    sjt_dot1034 = _parent;
    sjt_math1598 = (sjt_dot1034)->m31;
    sjt_math1595 = sjt_math1597 * sjt_math1598;
    sjt_dot1035 = _parent;
    sjt_math1603 = (sjt_dot1035)->m02;
    sjt_dot1036 = _parent;
    sjt_math1604 = (sjt_dot1036)->m23;
    sjt_math1601 = sjt_math1603 * sjt_math1604;
    sjt_dot1037 = _parent;
    sjt_math1602 = (sjt_dot1037)->m31;
    sjt_math1596 = sjt_math1601 * sjt_math1602;
    sjt_math1593 = sjt_math1595 - sjt_math1596;
    sjt_dot1038 = _parent;
    sjt_math1607 = (sjt_dot1038)->m03;
    sjt_dot1039 = _parent;
    sjt_math1608 = (sjt_dot1039)->m21;
    sjt_math1605 = sjt_math1607 * sjt_math1608;
    sjt_dot1040 = _parent;
    sjt_math1606 = (sjt_dot1040)->m32;
    sjt_math1594 = sjt_math1605 * sjt_math1606;
    sjt_math1591 = sjt_math1593 - sjt_math1594;
    sjt_dot1041 = _parent;
    sjt_math1611 = (sjt_dot1041)->m01;
    sjt_dot1042 = _parent;
    sjt_math1612 = (sjt_dot1042)->m23;
    sjt_math1609 = sjt_math1611 * sjt_math1612;
    sjt_dot1043 = _parent;
    sjt_math1610 = (sjt_dot1043)->m32;
    sjt_math1592 = sjt_math1609 * sjt_math1610;
    sjt_math1589 = sjt_math1591 + sjt_math1592;
    sjt_dot1044 = _parent;
    sjt_math1615 = (sjt_dot1044)->m02;
    sjt_dot1045 = _parent;
    sjt_math1616 = (sjt_dot1045)->m21;
    sjt_math1613 = sjt_math1615 * sjt_math1616;
    sjt_dot1046 = _parent;
    sjt_math1614 = (sjt_dot1046)->m33;
    sjt_math1590 = sjt_math1613 * sjt_math1614;
    sjt_math1587 = sjt_math1589 + sjt_math1590;
    sjt_dot1047 = _parent;
    sjt_math1619 = (sjt_dot1047)->m01;
    sjt_dot1048 = _parent;
    sjt_math1620 = (sjt_dot1048)->m22;
    sjt_math1617 = sjt_math1619 * sjt_math1620;
    sjt_dot1049 = _parent;
    sjt_math1618 = (sjt_dot1049)->m33;
    sjt_math1588 = sjt_math1617 * sjt_math1618;
    sjv_t.m01 = sjt_math1587 - sjt_math1588;
    sjt_dot1050 = _parent;
    sjt_math1633 = (sjt_dot1050)->m02;
    sjt_dot1051 = _parent;
    sjt_math1634 = (sjt_dot1051)->m13;
    sjt_math1631 = sjt_math1633 * sjt_math1634;
    sjt_dot1052 = _parent;
    sjt_math1632 = (sjt_dot1052)->m31;
    sjt_math1629 = sjt_math1631 * sjt_math1632;
    sjt_dot1053 = _parent;
    sjt_math1637 = (sjt_dot1053)->m03;
    sjt_dot1054 = _parent;
    sjt_math1638 = (sjt_dot1054)->m12;
    sjt_math1635 = sjt_math1637 * sjt_math1638;
    sjt_dot1055 = _parent;
    sjt_math1636 = (sjt_dot1055)->m31;
    sjt_math1630 = sjt_math1635 * sjt_math1636;
    sjt_math1627 = sjt_math1629 - sjt_math1630;
    sjt_dot1056 = _parent;
    sjt_math1641 = (sjt_dot1056)->m03;
    sjt_dot1057 = _parent;
    sjt_math1642 = (sjt_dot1057)->m11;
    sjt_math1639 = sjt_math1641 * sjt_math1642;
    sjt_dot1058 = _parent;
    sjt_math1640 = (sjt_dot1058)->m32;
    sjt_math1628 = sjt_math1639 * sjt_math1640;
    sjt_math1625 = sjt_math1627 + sjt_math1628;
    sjt_dot1059 = _parent;
    sjt_math1645 = (sjt_dot1059)->m01;
    sjt_dot1060 = _parent;
    sjt_math1646 = (sjt_dot1060)->m13;
    sjt_math1643 = sjt_math1645 * sjt_math1646;
    sjt_dot1061 = _parent;
    sjt_math1644 = (sjt_dot1061)->m32;
    sjt_math1626 = sjt_math1643 * sjt_math1644;
    sjt_math1623 = sjt_math1625 - sjt_math1626;
    sjt_dot1062 = _parent;
    sjt_math1649 = (sjt_dot1062)->m02;
    sjt_dot1063 = _parent;
    sjt_math1650 = (sjt_dot1063)->m11;
    sjt_math1647 = sjt_math1649 * sjt_math1650;
    sjt_dot1064 = _parent;
    sjt_math1648 = (sjt_dot1064)->m33;
    sjt_math1624 = sjt_math1647 * sjt_math1648;
    sjt_math1621 = sjt_math1623 - sjt_math1624;
    sjt_dot1065 = _parent;
    sjt_math1653 = (sjt_dot1065)->m01;
    sjt_dot1066 = _parent;
    sjt_math1654 = (sjt_dot1066)->m12;
    sjt_math1651 = sjt_math1653 * sjt_math1654;
    sjt_dot1067 = _parent;
    sjt_math1652 = (sjt_dot1067)->m33;
    sjt_math1622 = sjt_math1651 * sjt_math1652;
    sjv_t.m02 = sjt_math1621 + sjt_math1622;
    sjt_dot1068 = _parent;
    sjt_math1667 = (sjt_dot1068)->m03;
    sjt_dot1069 = _parent;
    sjt_math1668 = (sjt_dot1069)->m12;
    sjt_math1665 = sjt_math1667 * sjt_math1668;
    sjt_dot1070 = _parent;
    sjt_math1666 = (sjt_dot1070)->m21;
    sjt_math1663 = sjt_math1665 * sjt_math1666;
    sjt_dot1071 = _parent;
    sjt_math1671 = (sjt_dot1071)->m02;
    sjt_dot1072 = _parent;
    sjt_math1672 = (sjt_dot1072)->m13;
    sjt_math1669 = sjt_math1671 * sjt_math1672;
    sjt_dot1073 = _parent;
    sjt_math1670 = (sjt_dot1073)->m21;
    sjt_math1664 = sjt_math1669 * sjt_math1670;
    sjt_math1661 = sjt_math1663 - sjt_math1664;
    sjt_dot1074 = _parent;
    sjt_math1675 = (sjt_dot1074)->m03;
    sjt_dot1075 = _parent;
    sjt_math1676 = (sjt_dot1075)->m11;
    sjt_math1673 = sjt_math1675 * sjt_math1676;
    sjt_dot1076 = _parent;
    sjt_math1674 = (sjt_dot1076)->m22;
    sjt_math1662 = sjt_math1673 * sjt_math1674;
    sjt_math1659 = sjt_math1661 - sjt_math1662;
    sjt_dot1077 = _parent;
    sjt_math1679 = (sjt_dot1077)->m01;
    sjt_dot1078 = _parent;
    sjt_math1680 = (sjt_dot1078)->m13;
    sjt_math1677 = sjt_math1679 * sjt_math1680;
    sjt_dot1079 = _parent;
    sjt_math1678 = (sjt_dot1079)->m22;
    sjt_math1660 = sjt_math1677 * sjt_math1678;
    sjt_math1657 = sjt_math1659 + sjt_math1660;
    sjt_dot1080 = _parent;
    sjt_math1683 = (sjt_dot1080)->m02;
    sjt_dot1081 = _parent;
    sjt_math1684 = (sjt_dot1081)->m11;
    sjt_math1681 = sjt_math1683 * sjt_math1684;
    sjt_dot1082 = _parent;
    sjt_math1682 = (sjt_dot1082)->m23;
    sjt_math1658 = sjt_math1681 * sjt_math1682;
    sjt_math1655 = sjt_math1657 + sjt_math1658;
    sjt_dot1083 = _parent;
    sjt_math1687 = (sjt_dot1083)->m01;
    sjt_dot1084 = _parent;
    sjt_math1688 = (sjt_dot1084)->m12;
    sjt_math1685 = sjt_math1687 * sjt_math1688;
    sjt_dot1085 = _parent;
    sjt_math1686 = (sjt_dot1085)->m23;
    sjt_math1656 = sjt_math1685 * sjt_math1686;
    sjv_t.m03 = sjt_math1655 - sjt_math1656;
    sjt_dot1086 = _parent;
    sjt_math1701 = (sjt_dot1086)->m13;
    sjt_dot1087 = _parent;
    sjt_math1702 = (sjt_dot1087)->m22;
    sjt_math1699 = sjt_math1701 * sjt_math1702;
    sjt_dot1088 = _parent;
    sjt_math1700 = (sjt_dot1088)->m30;
    sjt_math1697 = sjt_math1699 * sjt_math1700;
    sjt_dot1089 = _parent;
    sjt_math1705 = (sjt_dot1089)->m12;
    sjt_dot1090 = _parent;
    sjt_math1706 = (sjt_dot1090)->m23;
    sjt_math1703 = sjt_math1705 * sjt_math1706;
    sjt_dot1091 = _parent;
    sjt_math1704 = (sjt_dot1091)->m30;
    sjt_math1698 = sjt_math1703 * sjt_math1704;
    sjt_math1695 = sjt_math1697 - sjt_math1698;
    sjt_dot1092 = _parent;
    sjt_math1709 = (sjt_dot1092)->m13;
    sjt_dot1093 = _parent;
    sjt_math1710 = (sjt_dot1093)->m20;
    sjt_math1707 = sjt_math1709 * sjt_math1710;
    sjt_dot1094 = _parent;
    sjt_math1708 = (sjt_dot1094)->m32;
    sjt_math1696 = sjt_math1707 * sjt_math1708;
    sjt_math1693 = sjt_math1695 - sjt_math1696;
    sjt_dot1095 = _parent;
    sjt_math1713 = (sjt_dot1095)->m10;
    sjt_dot1096 = _parent;
    sjt_math1714 = (sjt_dot1096)->m23;
    sjt_math1711 = sjt_math1713 * sjt_math1714;
    sjt_dot1097 = _parent;
    sjt_math1712 = (sjt_dot1097)->m32;
    sjt_math1694 = sjt_math1711 * sjt_math1712;
    sjt_math1691 = sjt_math1693 + sjt_math1694;
    sjt_dot1098 = _parent;
    sjt_math1717 = (sjt_dot1098)->m12;
    sjt_dot1099 = _parent;
    sjt_math1718 = (sjt_dot1099)->m20;
    sjt_math1715 = sjt_math1717 * sjt_math1718;
    sjt_dot1100 = _parent;
    sjt_math1716 = (sjt_dot1100)->m33;
    sjt_math1692 = sjt_math1715 * sjt_math1716;
    sjt_math1689 = sjt_math1691 + sjt_math1692;
    sjt_dot1101 = _parent;
    sjt_math1721 = (sjt_dot1101)->m10;
    sjt_dot1102 = _parent;
    sjt_math1722 = (sjt_dot1102)->m22;
    sjt_math1719 = sjt_math1721 * sjt_math1722;
    sjt_dot1103 = _parent;
    sjt_math1720 = (sjt_dot1103)->m33;
    sjt_math1690 = sjt_math1719 * sjt_math1720;
    sjv_t.m10 = sjt_math1689 - sjt_math1690;
    sjt_dot1104 = _parent;
    sjt_math1735 = (sjt_dot1104)->m02;
    sjt_dot1105 = _parent;
    sjt_math1736 = (sjt_dot1105)->m23;
    sjt_math1733 = sjt_math1735 * sjt_math1736;
    sjt_dot1106 = _parent;
    sjt_math1734 = (sjt_dot1106)->m30;
    sjt_math1731 = sjt_math1733 * sjt_math1734;
    sjt_dot1107 = _parent;
    sjt_math1739 = (sjt_dot1107)->m03;
    sjt_dot1108 = _parent;
    sjt_math1740 = (sjt_dot1108)->m22;
    sjt_math1737 = sjt_math1739 * sjt_math1740;
    sjt_dot1109 = _parent;
    sjt_math1738 = (sjt_dot1109)->m30;
    sjt_math1732 = sjt_math1737 * sjt_math1738;
    sjt_math1729 = sjt_math1731 - sjt_math1732;
    sjt_dot1110 = _parent;
    sjt_math1743 = (sjt_dot1110)->m03;
    sjt_dot1111 = _parent;
    sjt_math1744 = (sjt_dot1111)->m20;
    sjt_math1741 = sjt_math1743 * sjt_math1744;
    sjt_dot1112 = _parent;
    sjt_math1742 = (sjt_dot1112)->m32;
    sjt_math1730 = sjt_math1741 * sjt_math1742;
    sjt_math1727 = sjt_math1729 + sjt_math1730;
    sjt_dot1113 = _parent;
    sjt_math1747 = (sjt_dot1113)->m00;
    sjt_dot1114 = _parent;
    sjt_math1748 = (sjt_dot1114)->m23;
    sjt_math1745 = sjt_math1747 * sjt_math1748;
    sjt_dot1115 = _parent;
    sjt_math1746 = (sjt_dot1115)->m32;
    sjt_math1728 = sjt_math1745 * sjt_math1746;
    sjt_math1725 = sjt_math1727 - sjt_math1728;
    sjt_dot1116 = _parent;
    sjt_math1751 = (sjt_dot1116)->m02;
    sjt_dot1117 = _parent;
    sjt_math1752 = (sjt_dot1117)->m20;
    sjt_math1749 = sjt_math1751 * sjt_math1752;
    sjt_dot1118 = _parent;
    sjt_math1750 = (sjt_dot1118)->m33;
    sjt_math1726 = sjt_math1749 * sjt_math1750;
    sjt_math1723 = sjt_math1725 - sjt_math1726;
    sjt_dot1119 = _parent;
    sjt_math1755 = (sjt_dot1119)->m00;
    sjt_dot1120 = _parent;
    sjt_math1756 = (sjt_dot1120)->m22;
    sjt_math1753 = sjt_math1755 * sjt_math1756;
    sjt_dot1121 = _parent;
    sjt_math1754 = (sjt_dot1121)->m33;
    sjt_math1724 = sjt_math1753 * sjt_math1754;
    sjv_t.m11 = sjt_math1723 + sjt_math1724;
    sjt_dot1122 = _parent;
    sjt_math1769 = (sjt_dot1122)->m03;
    sjt_dot1123 = _parent;
    sjt_math1770 = (sjt_dot1123)->m12;
    sjt_math1767 = sjt_math1769 * sjt_math1770;
    sjt_dot1124 = _parent;
    sjt_math1768 = (sjt_dot1124)->m30;
    sjt_math1765 = sjt_math1767 * sjt_math1768;
    sjt_dot1125 = _parent;
    sjt_math1773 = (sjt_dot1125)->m02;
    sjt_dot1126 = _parent;
    sjt_math1774 = (sjt_dot1126)->m13;
    sjt_math1771 = sjt_math1773 * sjt_math1774;
    sjt_dot1127 = _parent;
    sjt_math1772 = (sjt_dot1127)->m30;
    sjt_math1766 = sjt_math1771 * sjt_math1772;
    sjt_math1763 = sjt_math1765 - sjt_math1766;
    sjt_dot1128 = _parent;
    sjt_math1777 = (sjt_dot1128)->m03;
    sjt_dot1129 = _parent;
    sjt_math1778 = (sjt_dot1129)->m10;
    sjt_math1775 = sjt_math1777 * sjt_math1778;
    sjt_dot1130 = _parent;
    sjt_math1776 = (sjt_dot1130)->m32;
    sjt_math1764 = sjt_math1775 * sjt_math1776;
    sjt_math1761 = sjt_math1763 - sjt_math1764;
    sjt_dot1131 = _parent;
    sjt_math1781 = (sjt_dot1131)->m00;
    sjt_dot1132 = _parent;
    sjt_math1782 = (sjt_dot1132)->m13;
    sjt_math1779 = sjt_math1781 * sjt_math1782;
    sjt_dot1133 = _parent;
    sjt_math1780 = (sjt_dot1133)->m32;
    sjt_math1762 = sjt_math1779 * sjt_math1780;
    sjt_math1759 = sjt_math1761 + sjt_math1762;
    sjt_dot1134 = _parent;
    sjt_math1785 = (sjt_dot1134)->m02;
    sjt_dot1135 = _parent;
    sjt_math1786 = (sjt_dot1135)->m10;
    sjt_math1783 = sjt_math1785 * sjt_math1786;
    sjt_dot1136 = _parent;
    sjt_math1784 = (sjt_dot1136)->m33;
    sjt_math1760 = sjt_math1783 * sjt_math1784;
    sjt_math1757 = sjt_math1759 + sjt_math1760;
    sjt_dot1137 = _parent;
    sjt_math1789 = (sjt_dot1137)->m00;
    sjt_dot1138 = _parent;
    sjt_math1790 = (sjt_dot1138)->m12;
    sjt_math1787 = sjt_math1789 * sjt_math1790;
    sjt_dot1139 = _parent;
    sjt_math1788 = (sjt_dot1139)->m33;
    sjt_math1758 = sjt_math1787 * sjt_math1788;
    sjv_t.m12 = sjt_math1757 - sjt_math1758;
    sjt_dot1140 = _parent;
    sjt_math1803 = (sjt_dot1140)->m02;
    sjt_dot1141 = _parent;
    sjt_math1804 = (sjt_dot1141)->m13;
    sjt_math1801 = sjt_math1803 * sjt_math1804;
    sjt_dot1142 = _parent;
    sjt_math1802 = (sjt_dot1142)->m20;
    sjt_math1799 = sjt_math1801 * sjt_math1802;
    sjt_dot1143 = _parent;
    sjt_math1807 = (sjt_dot1143)->m03;
    sjt_dot1144 = _parent;
    sjt_math1808 = (sjt_dot1144)->m12;
    sjt_math1805 = sjt_math1807 * sjt_math1808;
    sjt_dot1145 = _parent;
    sjt_math1806 = (sjt_dot1145)->m20;
    sjt_math1800 = sjt_math1805 * sjt_math1806;
    sjt_math1797 = sjt_math1799 - sjt_math1800;
    sjt_dot1146 = _parent;
    sjt_math1811 = (sjt_dot1146)->m03;
    sjt_dot1147 = _parent;
    sjt_math1812 = (sjt_dot1147)->m10;
    sjt_math1809 = sjt_math1811 * sjt_math1812;
    sjt_dot1148 = _parent;
    sjt_math1810 = (sjt_dot1148)->m22;
    sjt_math1798 = sjt_math1809 * sjt_math1810;
    sjt_math1795 = sjt_math1797 + sjt_math1798;
    sjt_dot1149 = _parent;
    sjt_math1815 = (sjt_dot1149)->m00;
    sjt_dot1150 = _parent;
    sjt_math1816 = (sjt_dot1150)->m13;
    sjt_math1813 = sjt_math1815 * sjt_math1816;
    sjt_dot1151 = _parent;
    sjt_math1814 = (sjt_dot1151)->m22;
    sjt_math1796 = sjt_math1813 * sjt_math1814;
    sjt_math1793 = sjt_math1795 - sjt_math1796;
    sjt_dot1152 = _parent;
    sjt_math1819 = (sjt_dot1152)->m02;
    sjt_dot1153 = _parent;
    sjt_math1820 = (sjt_dot1153)->m10;
    sjt_math1817 = sjt_math1819 * sjt_math1820;
    sjt_dot1154 = _parent;
    sjt_math1818 = (sjt_dot1154)->m23;
    sjt_math1794 = sjt_math1817 * sjt_math1818;
    sjt_math1791 = sjt_math1793 - sjt_math1794;
    sjt_dot1155 = _parent;
    sjt_math1823 = (sjt_dot1155)->m00;
    sjt_dot1156 = _parent;
    sjt_math1824 = (sjt_dot1156)->m12;
    sjt_math1821 = sjt_math1823 * sjt_math1824;
    sjt_dot1157 = _parent;
    sjt_math1822 = (sjt_dot1157)->m23;
    sjt_math1792 = sjt_math1821 * sjt_math1822;
    sjv_t.m13 = sjt_math1791 + sjt_math1792;
    sjt_dot1158 = _parent;
    sjt_math1837 = (sjt_dot1158)->m11;
    sjt_dot1159 = _parent;
    sjt_math1838 = (sjt_dot1159)->m23;
    sjt_math1835 = sjt_math1837 * sjt_math1838;
    sjt_dot1160 = _parent;
    sjt_math1836 = (sjt_dot1160)->m30;
    sjt_math1833 = sjt_math1835 * sjt_math1836;
    sjt_dot1161 = _parent;
    sjt_math1841 = (sjt_dot1161)->m13;
    sjt_dot1162 = _parent;
    sjt_math1842 = (sjt_dot1162)->m21;
    sjt_math1839 = sjt_math1841 * sjt_math1842;
    sjt_dot1163 = _parent;
    sjt_math1840 = (sjt_dot1163)->m30;
    sjt_math1834 = sjt_math1839 * sjt_math1840;
    sjt_math1831 = sjt_math1833 - sjt_math1834;
    sjt_dot1164 = _parent;
    sjt_math1845 = (sjt_dot1164)->m13;
    sjt_dot1165 = _parent;
    sjt_math1846 = (sjt_dot1165)->m20;
    sjt_math1843 = sjt_math1845 * sjt_math1846;
    sjt_dot1166 = _parent;
    sjt_math1844 = (sjt_dot1166)->m31;
    sjt_math1832 = sjt_math1843 * sjt_math1844;
    sjt_math1829 = sjt_math1831 + sjt_math1832;
    sjt_dot1167 = _parent;
    sjt_math1849 = (sjt_dot1167)->m10;
    sjt_dot1168 = _parent;
    sjt_math1850 = (sjt_dot1168)->m23;
    sjt_math1847 = sjt_math1849 * sjt_math1850;
    sjt_dot1169 = _parent;
    sjt_math1848 = (sjt_dot1169)->m31;
    sjt_math1830 = sjt_math1847 * sjt_math1848;
    sjt_math1827 = sjt_math1829 - sjt_math1830;
    sjt_dot1170 = _parent;
    sjt_math1853 = (sjt_dot1170)->m11;
    sjt_dot1171 = _parent;
    sjt_math1854 = (sjt_dot1171)->m20;
    sjt_math1851 = sjt_math1853 * sjt_math1854;
    sjt_dot1172 = _parent;
    sjt_math1852 = (sjt_dot1172)->m33;
    sjt_math1828 = sjt_math1851 * sjt_math1852;
    sjt_math1825 = sjt_math1827 - sjt_math1828;
    sjt_dot1173 = _parent;
    sjt_math1857 = (sjt_dot1173)->m10;
    sjt_dot1174 = _parent;
    sjt_math1858 = (sjt_dot1174)->m21;
    sjt_math1855 = sjt_math1857 * sjt_math1858;
    sjt_dot1175 = _parent;
    sjt_math1856 = (sjt_dot1175)->m33;
    sjt_math1826 = sjt_math1855 * sjt_math1856;
    sjv_t.m20 = sjt_math1825 + sjt_math1826;
    sjt_dot1176 = _parent;
    sjt_math1871 = (sjt_dot1176)->m03;
    sjt_dot1177 = _parent;
    sjt_math1872 = (sjt_dot1177)->m21;
    sjt_math1869 = sjt_math1871 * sjt_math1872;
    sjt_dot1178 = _parent;
    sjt_math1870 = (sjt_dot1178)->m30;
    sjt_math1867 = sjt_math1869 * sjt_math1870;
    sjt_dot1179 = _parent;
    sjt_math1875 = (sjt_dot1179)->m01;
    sjt_dot1180 = _parent;
    sjt_math1876 = (sjt_dot1180)->m23;
    sjt_math1873 = sjt_math1875 * sjt_math1876;
    sjt_dot1181 = _parent;
    sjt_math1874 = (sjt_dot1181)->m30;
    sjt_math1868 = sjt_math1873 * sjt_math1874;
    sjt_math1865 = sjt_math1867 - sjt_math1868;
    sjt_dot1182 = _parent;
    sjt_math1879 = (sjt_dot1182)->m03;
    sjt_dot1183 = _parent;
    sjt_math1880 = (sjt_dot1183)->m20;
    sjt_math1877 = sjt_math1879 * sjt_math1880;
    sjt_dot1184 = _parent;
    sjt_math1878 = (sjt_dot1184)->m31;
    sjt_math1866 = sjt_math1877 * sjt_math1878;
    sjt_math1863 = sjt_math1865 - sjt_math1866;
    sjt_dot1185 = _parent;
    sjt_math1883 = (sjt_dot1185)->m00;
    sjt_dot1186 = _parent;
    sjt_math1884 = (sjt_dot1186)->m23;
    sjt_math1881 = sjt_math1883 * sjt_math1884;
    sjt_dot1187 = _parent;
    sjt_math1882 = (sjt_dot1187)->m31;
    sjt_math1864 = sjt_math1881 * sjt_math1882;
    sjt_math1861 = sjt_math1863 + sjt_math1864;
    sjt_dot1188 = _parent;
    sjt_math1887 = (sjt_dot1188)->m01;
    sjt_dot1189 = _parent;
    sjt_math1888 = (sjt_dot1189)->m20;
    sjt_math1885 = sjt_math1887 * sjt_math1888;
    sjt_dot1190 = _parent;
    sjt_math1886 = (sjt_dot1190)->m33;
    sjt_math1862 = sjt_math1885 * sjt_math1886;
    sjt_math1859 = sjt_math1861 + sjt_math1862;
    sjt_dot1191 = _parent;
    sjt_math1891 = (sjt_dot1191)->m00;
    sjt_dot1192 = _parent;
    sjt_math1892 = (sjt_dot1192)->m21;
    sjt_math1889 = sjt_math1891 * sjt_math1892;
    sjt_dot1193 = _parent;
    sjt_math1890 = (sjt_dot1193)->m33;
    sjt_math1860 = sjt_math1889 * sjt_math1890;
    sjv_t.m21 = sjt_math1859 - sjt_math1860;
    sjt_dot1194 = _parent;
    sjt_math1905 = (sjt_dot1194)->m01;
    sjt_dot1195 = _parent;
    sjt_math1906 = (sjt_dot1195)->m13;
    sjt_math1903 = sjt_math1905 * sjt_math1906;
    sjt_dot1196 = _parent;
    sjt_math1904 = (sjt_dot1196)->m30;
    sjt_math1901 = sjt_math1903 * sjt_math1904;
    sjt_dot1197 = _parent;
    sjt_math1909 = (sjt_dot1197)->m03;
    sjt_dot1198 = _parent;
    sjt_math1910 = (sjt_dot1198)->m11;
    sjt_math1907 = sjt_math1909 * sjt_math1910;
    sjt_dot1199 = _parent;
    sjt_math1908 = (sjt_dot1199)->m30;
    sjt_math1902 = sjt_math1907 * sjt_math1908;
    sjt_math1899 = sjt_math1901 - sjt_math1902;
    sjt_dot1200 = _parent;
    sjt_math1913 = (sjt_dot1200)->m03;
    sjt_dot1201 = _parent;
    sjt_math1914 = (sjt_dot1201)->m10;
    sjt_math1911 = sjt_math1913 * sjt_math1914;
    sjt_dot1202 = _parent;
    sjt_math1912 = (sjt_dot1202)->m31;
    sjt_math1900 = sjt_math1911 * sjt_math1912;
    sjt_math1897 = sjt_math1899 + sjt_math1900;
    sjt_dot1203 = _parent;
    sjt_math1917 = (sjt_dot1203)->m00;
    sjt_dot1204 = _parent;
    sjt_math1918 = (sjt_dot1204)->m13;
    sjt_math1915 = sjt_math1917 * sjt_math1918;
    sjt_dot1205 = _parent;
    sjt_math1916 = (sjt_dot1205)->m31;
    sjt_math1898 = sjt_math1915 * sjt_math1916;
    sjt_math1895 = sjt_math1897 - sjt_math1898;
    sjt_dot1206 = _parent;
    sjt_math1921 = (sjt_dot1206)->m01;
    sjt_dot1207 = _parent;
    sjt_math1922 = (sjt_dot1207)->m10;
    sjt_math1919 = sjt_math1921 * sjt_math1922;
    sjt_dot1208 = _parent;
    sjt_math1920 = (sjt_dot1208)->m33;
    sjt_math1896 = sjt_math1919 * sjt_math1920;
    sjt_math1893 = sjt_math1895 - sjt_math1896;
    sjt_dot1209 = _parent;
    sjt_math1925 = (sjt_dot1209)->m00;
    sjt_dot1210 = _parent;
    sjt_math1926 = (sjt_dot1210)->m11;
    sjt_math1923 = sjt_math1925 * sjt_math1926;
    sjt_dot1211 = _parent;
    sjt_math1924 = (sjt_dot1211)->m33;
    sjt_math1894 = sjt_math1923 * sjt_math1924;
    sjv_t.m22 = sjt_math1893 + sjt_math1894;
    sjt_dot1212 = _parent;
    sjt_math1939 = (sjt_dot1212)->m03;
    sjt_dot1213 = _parent;
    sjt_math1940 = (sjt_dot1213)->m11;
    sjt_math1937 = sjt_math1939 * sjt_math1940;
    sjt_dot1214 = _parent;
    sjt_math1938 = (sjt_dot1214)->m20;
    sjt_math1935 = sjt_math1937 * sjt_math1938;
    sjt_dot1215 = _parent;
    sjt_math1943 = (sjt_dot1215)->m01;
    sjt_dot1216 = _parent;
    sjt_math1944 = (sjt_dot1216)->m13;
    sjt_math1941 = sjt_math1943 * sjt_math1944;
    sjt_dot1217 = _parent;
    sjt_math1942 = (sjt_dot1217)->m20;
    sjt_math1936 = sjt_math1941 * sjt_math1942;
    sjt_math1933 = sjt_math1935 - sjt_math1936;
    sjt_dot1218 = _parent;
    sjt_math1947 = (sjt_dot1218)->m03;
    sjt_dot1219 = _parent;
    sjt_math1948 = (sjt_dot1219)->m10;
    sjt_math1945 = sjt_math1947 * sjt_math1948;
    sjt_dot1220 = _parent;
    sjt_math1946 = (sjt_dot1220)->m21;
    sjt_math1934 = sjt_math1945 * sjt_math1946;
    sjt_math1931 = sjt_math1933 - sjt_math1934;
    sjt_dot1221 = _parent;
    sjt_math1951 = (sjt_dot1221)->m00;
    sjt_dot1222 = _parent;
    sjt_math1952 = (sjt_dot1222)->m13;
    sjt_math1949 = sjt_math1951 * sjt_math1952;
    sjt_dot1223 = _parent;
    sjt_math1950 = (sjt_dot1223)->m21;
    sjt_math1932 = sjt_math1949 * sjt_math1950;
    sjt_math1929 = sjt_math1931 + sjt_math1932;
    sjt_dot1224 = _parent;
    sjt_math1955 = (sjt_dot1224)->m01;
    sjt_dot1225 = _parent;
    sjt_math1956 = (sjt_dot1225)->m10;
    sjt_math1953 = sjt_math1955 * sjt_math1956;
    sjt_dot1226 = _parent;
    sjt_math1954 = (sjt_dot1226)->m23;
    sjt_math1930 = sjt_math1953 * sjt_math1954;
    sjt_math1927 = sjt_math1929 + sjt_math1930;
    sjt_dot1227 = _parent;
    sjt_math1959 = (sjt_dot1227)->m00;
    sjt_dot1228 = _parent;
    sjt_math1960 = (sjt_dot1228)->m11;
    sjt_math1957 = sjt_math1959 * sjt_math1960;
    sjt_dot1229 = _parent;
    sjt_math1958 = (sjt_dot1229)->m23;
    sjt_math1928 = sjt_math1957 * sjt_math1958;
    sjv_t.m23 = sjt_math1927 - sjt_math1928;
    sjt_dot1230 = _parent;
    sjt_math1973 = (sjt_dot1230)->m12;
    sjt_dot1231 = _parent;
    sjt_math1974 = (sjt_dot1231)->m21;
    sjt_math1971 = sjt_math1973 * sjt_math1974;
    sjt_dot1232 = _parent;
    sjt_math1972 = (sjt_dot1232)->m30;
    sjt_math1969 = sjt_math1971 * sjt_math1972;
    sjt_dot1233 = _parent;
    sjt_math1977 = (sjt_dot1233)->m11;
    sjt_dot1234 = _parent;
    sjt_math1978 = (sjt_dot1234)->m22;
    sjt_math1975 = sjt_math1977 * sjt_math1978;
    sjt_dot1235 = _parent;
    sjt_math1976 = (sjt_dot1235)->m30;
    sjt_math1970 = sjt_math1975 * sjt_math1976;
    sjt_math1967 = sjt_math1969 - sjt_math1970;
    sjt_dot1236 = _parent;
    sjt_math1981 = (sjt_dot1236)->m12;
    sjt_dot1237 = _parent;
    sjt_math1982 = (sjt_dot1237)->m20;
    sjt_math1979 = sjt_math1981 * sjt_math1982;
    sjt_dot1238 = _parent;
    sjt_math1980 = (sjt_dot1238)->m31;
    sjt_math1968 = sjt_math1979 * sjt_math1980;
    sjt_math1965 = sjt_math1967 - sjt_math1968;
    sjt_dot1239 = _parent;
    sjt_math1985 = (sjt_dot1239)->m10;
    sjt_dot1240 = _parent;
    sjt_math1986 = (sjt_dot1240)->m22;
    sjt_math1983 = sjt_math1985 * sjt_math1986;
    sjt_dot1241 = _parent;
    sjt_math1984 = (sjt_dot1241)->m31;
    sjt_math1966 = sjt_math1983 * sjt_math1984;
    sjt_math1963 = sjt_math1965 + sjt_math1966;
    sjt_dot1242 = _parent;
    sjt_math1989 = (sjt_dot1242)->m11;
    sjt_dot1243 = _parent;
    sjt_math1990 = (sjt_dot1243)->m20;
    sjt_math1987 = sjt_math1989 * sjt_math1990;
    sjt_dot1244 = _parent;
    sjt_math1988 = (sjt_dot1244)->m32;
    sjt_math1964 = sjt_math1987 * sjt_math1988;
    sjt_math1961 = sjt_math1963 + sjt_math1964;
    sjt_dot1245 = _parent;
    sjt_math1993 = (sjt_dot1245)->m10;
    sjt_dot1246 = _parent;
    sjt_math1994 = (sjt_dot1246)->m21;
    sjt_math1991 = sjt_math1993 * sjt_math1994;
    sjt_dot1247 = _parent;
    sjt_math1992 = (sjt_dot1247)->m32;
    sjt_math1962 = sjt_math1991 * sjt_math1992;
    sjv_t.m30 = sjt_math1961 - sjt_math1962;
    sjt_dot1248 = _parent;
    sjt_math2007 = (sjt_dot1248)->m01;
    sjt_dot1249 = _parent;
    sjt_math2008 = (sjt_dot1249)->m22;
    sjt_math2005 = sjt_math2007 * sjt_math2008;
    sjt_dot1250 = _parent;
    sjt_math2006 = (sjt_dot1250)->m30;
    sjt_math2003 = sjt_math2005 * sjt_math2006;
    sjt_dot1251 = _parent;
    sjt_math2011 = (sjt_dot1251)->m02;
    sjt_dot1252 = _parent;
    sjt_math2012 = (sjt_dot1252)->m21;
    sjt_math2009 = sjt_math2011 * sjt_math2012;
    sjt_dot1253 = _parent;
    sjt_math2010 = (sjt_dot1253)->m30;
    sjt_math2004 = sjt_math2009 * sjt_math2010;
    sjt_math2001 = sjt_math2003 - sjt_math2004;
    sjt_dot1254 = _parent;
    sjt_math2015 = (sjt_dot1254)->m02;
    sjt_dot1255 = _parent;
    sjt_math2016 = (sjt_dot1255)->m20;
    sjt_math2013 = sjt_math2015 * sjt_math2016;
    sjt_dot1256 = _parent;
    sjt_math2014 = (sjt_dot1256)->m31;
    sjt_math2002 = sjt_math2013 * sjt_math2014;
    sjt_math1999 = sjt_math2001 + sjt_math2002;
    sjt_dot1257 = _parent;
    sjt_math2019 = (sjt_dot1257)->m00;
    sjt_dot1258 = _parent;
    sjt_math2020 = (sjt_dot1258)->m22;
    sjt_math2017 = sjt_math2019 * sjt_math2020;
    sjt_dot1259 = _parent;
    sjt_math2018 = (sjt_dot1259)->m31;
    sjt_math2000 = sjt_math2017 * sjt_math2018;
    sjt_math1997 = sjt_math1999 - sjt_math2000;
    sjt_dot1260 = _parent;
    sjt_math2023 = (sjt_dot1260)->m01;
    sjt_dot1261 = _parent;
    sjt_math2024 = (sjt_dot1261)->m20;
    sjt_math2021 = sjt_math2023 * sjt_math2024;
    sjt_dot1262 = _parent;
    sjt_math2022 = (sjt_dot1262)->m32;
    sjt_math1998 = sjt_math2021 * sjt_math2022;
    sjt_math1995 = sjt_math1997 - sjt_math1998;
    sjt_dot1263 = _parent;
    sjt_math2027 = (sjt_dot1263)->m00;
    sjt_dot1264 = _parent;
    sjt_math2028 = (sjt_dot1264)->m21;
    sjt_math2025 = sjt_math2027 * sjt_math2028;
    sjt_dot1265 = _parent;
    sjt_math2026 = (sjt_dot1265)->m32;
    sjt_math1996 = sjt_math2025 * sjt_math2026;
    sjv_t.m31 = sjt_math1995 + sjt_math1996;
    sjt_dot1266 = _parent;
    sjt_math2041 = (sjt_dot1266)->m02;
    sjt_dot1267 = _parent;
    sjt_math2042 = (sjt_dot1267)->m11;
    sjt_math2039 = sjt_math2041 * sjt_math2042;
    sjt_dot1268 = _parent;
    sjt_math2040 = (sjt_dot1268)->m30;
    sjt_math2037 = sjt_math2039 * sjt_math2040;
    sjt_dot1269 = _parent;
    sjt_math2045 = (sjt_dot1269)->m01;
    sjt_dot1270 = _parent;
    sjt_math2046 = (sjt_dot1270)->m12;
    sjt_math2043 = sjt_math2045 * sjt_math2046;
    sjt_dot1271 = _parent;
    sjt_math2044 = (sjt_dot1271)->m30;
    sjt_math2038 = sjt_math2043 * sjt_math2044;
    sjt_math2035 = sjt_math2037 - sjt_math2038;
    sjt_dot1272 = _parent;
    sjt_math2049 = (sjt_dot1272)->m02;
    sjt_dot1273 = _parent;
    sjt_math2050 = (sjt_dot1273)->m10;
    sjt_math2047 = sjt_math2049 * sjt_math2050;
    sjt_dot1274 = _parent;
    sjt_math2048 = (sjt_dot1274)->m31;
    sjt_math2036 = sjt_math2047 * sjt_math2048;
    sjt_math2033 = sjt_math2035 - sjt_math2036;
    sjt_dot1275 = _parent;
    sjt_math2053 = (sjt_dot1275)->m00;
    sjt_dot1276 = _parent;
    sjt_math2054 = (sjt_dot1276)->m12;
    sjt_math2051 = sjt_math2053 * sjt_math2054;
    sjt_dot1277 = _parent;
    sjt_math2052 = (sjt_dot1277)->m31;
    sjt_math2034 = sjt_math2051 * sjt_math2052;
    sjt_math2031 = sjt_math2033 + sjt_math2034;
    sjt_dot1278 = _parent;
    sjt_math2057 = (sjt_dot1278)->m01;
    sjt_dot1279 = _parent;
    sjt_math2058 = (sjt_dot1279)->m10;
    sjt_math2055 = sjt_math2057 * sjt_math2058;
    sjt_dot1280 = _parent;
    sjt_math2056 = (sjt_dot1280)->m32;
    sjt_math2032 = sjt_math2055 * sjt_math2056;
    sjt_math2029 = sjt_math2031 + sjt_math2032;
    sjt_dot1281 = _parent;
    sjt_math2061 = (sjt_dot1281)->m00;
    sjt_dot1282 = _parent;
    sjt_math2062 = (sjt_dot1282)->m11;
    sjt_math2059 = sjt_math2061 * sjt_math2062;
    sjt_dot1283 = _parent;
    sjt_math2060 = (sjt_dot1283)->m32;
    sjt_math2030 = sjt_math2059 * sjt_math2060;
    sjv_t.m32 = sjt_math2029 - sjt_math2030;
    sjt_dot1284 = _parent;
    sjt_math2075 = (sjt_dot1284)->m01;
    sjt_dot1285 = _parent;
    sjt_math2076 = (sjt_dot1285)->m12;
    sjt_math2073 = sjt_math2075 * sjt_math2076;
    sjt_dot1286 = _parent;
    sjt_math2074 = (sjt_dot1286)->m20;
    sjt_math2071 = sjt_math2073 * sjt_math2074;
    sjt_dot1287 = _parent;
    sjt_math2079 = (sjt_dot1287)->m02;
    sjt_dot1288 = _parent;
    sjt_math2080 = (sjt_dot1288)->m11;
    sjt_math2077 = sjt_math2079 * sjt_math2080;
    sjt_dot1289 = _parent;
    sjt_math2078 = (sjt_dot1289)->m20;
    sjt_math2072 = sjt_math2077 * sjt_math2078;
    sjt_math2069 = sjt_math2071 - sjt_math2072;
    sjt_dot1290 = _parent;
    sjt_math2083 = (sjt_dot1290)->m02;
    sjt_dot1291 = _parent;
    sjt_math2084 = (sjt_dot1291)->m10;
    sjt_math2081 = sjt_math2083 * sjt_math2084;
    sjt_dot1292 = _parent;
    sjt_math2082 = (sjt_dot1292)->m21;
    sjt_math2070 = sjt_math2081 * sjt_math2082;
    sjt_math2067 = sjt_math2069 + sjt_math2070;
    sjt_dot1293 = _parent;
    sjt_math2087 = (sjt_dot1293)->m00;
    sjt_dot1294 = _parent;
    sjt_math2088 = (sjt_dot1294)->m12;
    sjt_math2085 = sjt_math2087 * sjt_math2088;
    sjt_dot1295 = _parent;
    sjt_math2086 = (sjt_dot1295)->m21;
    sjt_math2068 = sjt_math2085 * sjt_math2086;
    sjt_math2065 = sjt_math2067 - sjt_math2068;
    sjt_dot1296 = _parent;
    sjt_math2091 = (sjt_dot1296)->m01;
    sjt_dot1297 = _parent;
    sjt_math2092 = (sjt_dot1297)->m10;
    sjt_math2089 = sjt_math2091 * sjt_math2092;
    sjt_dot1298 = _parent;
    sjt_math2090 = (sjt_dot1298)->m22;
    sjt_math2066 = sjt_math2089 * sjt_math2090;
    sjt_math2063 = sjt_math2065 - sjt_math2066;
    sjt_dot1299 = _parent;
    sjt_math2095 = (sjt_dot1299)->m00;
    sjt_dot1300 = _parent;
    sjt_math2096 = (sjt_dot1300)->m11;
    sjt_math2093 = sjt_math2095 * sjt_math2096;
    sjt_dot1301 = _parent;
    sjt_math2094 = (sjt_dot1301)->m22;
    sjt_math2064 = sjt_math2093 * sjt_math2094;
    sjv_t.m33 = sjt_math2063 + sjt_math2064;
    sjf_mat4(&sjv_t);
    sjt_parent54 = &sjv_t;
    sjt_math2097 = 1.0f;
    sjf_mat4_determinant(_parent, &sjt_math2098);
    sjt_functionParam120 = sjt_math2097 / sjt_math2098;
    sjf_mat4_multiplyf32_heap(sjt_parent54, sjt_functionParam120, _return);

    if (sjv_t._refCount == 1) { sjf_mat4_destroy(&sjv_t); }
}

void sjf_mat4_lookatlh(sjs_vec3* camera, sjs_vec3* target, sjs_vec3* up, sjs_mat4* _return) {
    sjs_vec3 sjt_call8 = { -1 };
    sjs_vec3* sjt_dot176 = 0;
    sjs_vec3* sjt_dot177 = 0;
    sjs_vec3* sjt_dot178 = 0;
    sjs_vec3* sjt_dot179 = 0;
    sjs_vec3* sjt_dot180 = 0;
    sjs_vec3* sjt_dot181 = 0;
    sjs_vec3* sjt_dot182 = 0;
    sjs_vec3* sjt_dot183 = 0;
    sjs_vec3* sjt_dot184 = 0;
    sjs_vec3* sjt_functionParam83 = 0;
    sjs_vec3* sjt_functionParam86 = 0;
    sjs_vec3* sjt_functionParam87 = 0;
    sjs_vec3* sjt_functionParam88 = 0;
    sjs_vec3* sjt_functionParam89 = 0;
    sjs_vec3* sjt_functionParam90 = 0;
    float sjt_math163;
    float sjt_math164;
    float sjt_math175;
    float sjt_math176;
    float sjt_math177;
    float sjt_math178;
    sjs_vec3* sjt_parent24 = 0;
    sjs_vec3* sjt_parent25 = 0;
    sjs_vec3* sjt_parent26 = 0;
    sjs_vec3* sjt_parent27 = 0;
    sjs_vec3* sjt_parent28 = 0;
    sjs_vec3* sjt_parent29 = 0;
    sjs_vec3* sjt_parent30 = 0;
    sjs_vec3* sjt_parent31 = 0;
    sjs_vec3 sjv_temp = { -1 };
    sjs_vec3 sjv_xaxis = { -1 };
    sjs_vec3 sjv_yaxis = { -1 };
    sjs_vec3 sjv_zaxis = { -1 };

    sjt_parent24 = target;
    sjt_functionParam83 = camera;
    sjf_vec3_subtract(sjt_parent24, sjt_functionParam83, &sjv_temp);
    sjt_parent25 = &sjv_temp;
    sjf_vec3_normalize(sjt_parent25, &sjv_zaxis);
    sjt_parent27 = up;
    sjt_functionParam86 = &sjv_zaxis;
    sjf_vec3_cross(sjt_parent27, sjt_functionParam86, &sjt_call8);
    sjt_parent26 = &sjt_call8;
    sjf_vec3_normalize(sjt_parent26, &sjv_xaxis);
    sjt_parent28 = &sjv_zaxis;
    sjt_functionParam87 = &sjv_xaxis;
    sjf_vec3_cross(sjt_parent28, sjt_functionParam87, &sjv_yaxis);
    _return->_refCount = 1;
    sjt_dot176 = &sjv_xaxis;
    _return->m00 = (sjt_dot176)->x;
    sjt_dot177 = &sjv_yaxis;
    _return->m01 = (sjt_dot177)->x;
    sjt_dot178 = &sjv_zaxis;
    _return->m02 = (sjt_dot178)->x;
    _return->m03 = 0.0f;
    sjt_dot179 = &sjv_xaxis;
    _return->m10 = (sjt_dot179)->y;
    sjt_dot180 = &sjv_yaxis;
    _return->m11 = (sjt_dot180)->y;
    sjt_dot181 = &sjv_zaxis;
    _return->m12 = (sjt_dot181)->y;
    _return->m13 = 0.0f;
    sjt_dot182 = &sjv_xaxis;
    _return->m20 = (sjt_dot182)->z;
    sjt_dot183 = &sjv_yaxis;
    _return->m21 = (sjt_dot183)->z;
    sjt_dot184 = &sjv_zaxis;
    _return->m22 = (sjt_dot184)->z;
    _return->m23 = 0.0f;
    sjt_math163 = 0.0f;
    sjt_parent29 = &sjv_xaxis;
    sjt_functionParam88 = camera;
    sjf_vec3_dot(sjt_parent29, sjt_functionParam88, &sjt_math164);
    _return->m30 = sjt_math163 - sjt_math164;
    sjt_math175 = 0.0f;
    sjt_parent30 = &sjv_yaxis;
    sjt_functionParam89 = camera;
    sjf_vec3_dot(sjt_parent30, sjt_functionParam89, &sjt_math176);
    _return->m31 = sjt_math175 - sjt_math176;
    sjt_math177 = 0.0f;
    sjt_parent31 = &sjv_zaxis;
    sjt_functionParam90 = camera;
    sjf_vec3_dot(sjt_parent31, sjt_functionParam90, &sjt_math178);
    _return->m32 = sjt_math177 - sjt_math178;
    _return->m33 = 1.0f;
    sjf_mat4(_return);

    if (sjt_call8._refCount == 1) { sjf_vec3_destroy(&sjt_call8); }
    if (sjv_temp._refCount == 1) { sjf_vec3_destroy(&sjv_temp); }
    if (sjv_xaxis._refCount == 1) { sjf_vec3_destroy(&sjv_xaxis); }
    if (sjv_yaxis._refCount == 1) { sjf_vec3_destroy(&sjv_yaxis); }
    if (sjv_zaxis._refCount == 1) { sjf_vec3_destroy(&sjv_zaxis); }
}

void sjf_mat4_lookatlh_heap(sjs_vec3* camera, sjs_vec3* target, sjs_vec3* up, sjs_mat4** _return) {
    sjs_vec3 sjt_call9 = { -1 };
    sjs_vec3* sjt_dot191 = 0;
    sjs_vec3* sjt_dot192 = 0;
    sjs_vec3* sjt_dot193 = 0;
    sjs_vec3* sjt_dot194 = 0;
    sjs_vec3* sjt_dot195 = 0;
    sjs_vec3* sjt_dot196 = 0;
    sjs_vec3* sjt_dot197 = 0;
    sjs_vec3* sjt_dot198 = 0;
    sjs_vec3* sjt_dot199 = 0;
    sjs_vec3* sjt_functionParam91 = 0;
    sjs_vec3* sjt_functionParam92 = 0;
    sjs_vec3* sjt_functionParam93 = 0;
    sjs_vec3* sjt_functionParam94 = 0;
    sjs_vec3* sjt_functionParam95 = 0;
    sjs_vec3* sjt_functionParam96 = 0;
    float sjt_math179;
    float sjt_math180;
    float sjt_math181;
    float sjt_math182;
    float sjt_math183;
    float sjt_math184;
    sjs_vec3* sjt_parent32 = 0;
    sjs_vec3* sjt_parent33 = 0;
    sjs_vec3* sjt_parent34 = 0;
    sjs_vec3* sjt_parent35 = 0;
    sjs_vec3* sjt_parent36 = 0;
    sjs_vec3* sjt_parent37 = 0;
    sjs_vec3* sjt_parent38 = 0;
    sjs_vec3* sjt_parent39 = 0;
    sjs_vec3 sjv_temp = { -1 };
    sjs_vec3 sjv_xaxis = { -1 };
    sjs_vec3 sjv_yaxis = { -1 };
    sjs_vec3 sjv_zaxis = { -1 };

    sjt_parent32 = target;
    sjt_functionParam91 = camera;
    sjf_vec3_subtract(sjt_parent32, sjt_functionParam91, &sjv_temp);
    sjt_parent33 = &sjv_temp;
    sjf_vec3_normalize(sjt_parent33, &sjv_zaxis);
    sjt_parent35 = up;
    sjt_functionParam92 = &sjv_zaxis;
    sjf_vec3_cross(sjt_parent35, sjt_functionParam92, &sjt_call9);
    sjt_parent34 = &sjt_call9;
    sjf_vec3_normalize(sjt_parent34, &sjv_xaxis);
    sjt_parent36 = &sjv_zaxis;
    sjt_functionParam93 = &sjv_xaxis;
    sjf_vec3_cross(sjt_parent36, sjt_functionParam93, &sjv_yaxis);
    (*_return) = (sjs_mat4*)malloc(sizeof(sjs_mat4));
    (*_return)->_refCount = 1;
    sjt_dot191 = &sjv_xaxis;
    (*_return)->m00 = (sjt_dot191)->x;
    sjt_dot192 = &sjv_yaxis;
    (*_return)->m01 = (sjt_dot192)->x;
    sjt_dot193 = &sjv_zaxis;
    (*_return)->m02 = (sjt_dot193)->x;
    (*_return)->m03 = 0.0f;
    sjt_dot194 = &sjv_xaxis;
    (*_return)->m10 = (sjt_dot194)->y;
    sjt_dot195 = &sjv_yaxis;
    (*_return)->m11 = (sjt_dot195)->y;
    sjt_dot196 = &sjv_zaxis;
    (*_return)->m12 = (sjt_dot196)->y;
    (*_return)->m13 = 0.0f;
    sjt_dot197 = &sjv_xaxis;
    (*_return)->m20 = (sjt_dot197)->z;
    sjt_dot198 = &sjv_yaxis;
    (*_return)->m21 = (sjt_dot198)->z;
    sjt_dot199 = &sjv_zaxis;
    (*_return)->m22 = (sjt_dot199)->z;
    (*_return)->m23 = 0.0f;
    sjt_math179 = 0.0f;
    sjt_parent37 = &sjv_xaxis;
    sjt_functionParam94 = camera;
    sjf_vec3_dot(sjt_parent37, sjt_functionParam94, &sjt_math180);
    (*_return)->m30 = sjt_math179 - sjt_math180;
    sjt_math181 = 0.0f;
    sjt_parent38 = &sjv_yaxis;
    sjt_functionParam95 = camera;
    sjf_vec3_dot(sjt_parent38, sjt_functionParam95, &sjt_math182);
    (*_return)->m31 = sjt_math181 - sjt_math182;
    sjt_math183 = 0.0f;
    sjt_parent39 = &sjv_zaxis;
    sjt_functionParam96 = camera;
    sjf_vec3_dot(sjt_parent39, sjt_functionParam96, &sjt_math184);
    (*_return)->m32 = sjt_math183 - sjt_math184;
    (*_return)->m33 = 1.0f;
    sjf_mat4_heap((*_return));

    if (sjt_call9._refCount == 1) { sjf_vec3_destroy(&sjt_call9); }
    if (sjv_temp._refCount == 1) { sjf_vec3_destroy(&sjv_temp); }
    if (sjv_xaxis._refCount == 1) { sjf_vec3_destroy(&sjv_xaxis); }
    if (sjv_yaxis._refCount == 1) { sjf_vec3_destroy(&sjv_yaxis); }
    if (sjv_zaxis._refCount == 1) { sjf_vec3_destroy(&sjv_zaxis); }
}

void sjf_mat4_multiply(sjs_mat4* _parent, sjs_mat4* m, sjs_mat4* _return) {
    sjs_mat4* sjt_dot274 = 0;
    sjs_mat4* sjt_dot275 = 0;
    sjs_mat4* sjt_dot276 = 0;
    sjs_mat4* sjt_dot277 = 0;
    sjs_mat4* sjt_dot278 = 0;
    sjs_mat4* sjt_dot279 = 0;
    sjs_mat4* sjt_dot280 = 0;
    sjs_mat4* sjt_dot281 = 0;
    sjs_mat4* sjt_dot282 = 0;
    sjs_mat4* sjt_dot283 = 0;
    sjs_mat4* sjt_dot284 = 0;
    sjs_mat4* sjt_dot285 = 0;
    sjs_mat4* sjt_dot286 = 0;
    sjs_mat4* sjt_dot287 = 0;
    sjs_mat4* sjt_dot288 = 0;
    sjs_mat4* sjt_dot289 = 0;
    sjs_mat4* sjt_dot290 = 0;
    sjs_mat4* sjt_dot291 = 0;
    sjs_mat4* sjt_dot292 = 0;
    sjs_mat4* sjt_dot293 = 0;
    sjs_mat4* sjt_dot294 = 0;
    sjs_mat4* sjt_dot295 = 0;
    sjs_mat4* sjt_dot296 = 0;
    sjs_mat4* sjt_dot297 = 0;
    sjs_mat4* sjt_dot298 = 0;
    sjs_mat4* sjt_dot299 = 0;
    sjs_mat4* sjt_dot300 = 0;
    sjs_mat4* sjt_dot301 = 0;
    sjs_mat4* sjt_dot302 = 0;
    sjs_mat4* sjt_dot303 = 0;
    sjs_mat4* sjt_dot304 = 0;
    sjs_mat4* sjt_dot305 = 0;
    sjs_mat4* sjt_dot306 = 0;
    sjs_mat4* sjt_dot307 = 0;
    sjs_mat4* sjt_dot308 = 0;
    sjs_mat4* sjt_dot309 = 0;
    sjs_mat4* sjt_dot310 = 0;
    sjs_mat4* sjt_dot311 = 0;
    sjs_mat4* sjt_dot312 = 0;
    sjs_mat4* sjt_dot313 = 0;
    sjs_mat4* sjt_dot314 = 0;
    sjs_mat4* sjt_dot315 = 0;
    sjs_mat4* sjt_dot316 = 0;
    sjs_mat4* sjt_dot317 = 0;
    sjs_mat4* sjt_dot318 = 0;
    sjs_mat4* sjt_dot319 = 0;
    sjs_mat4* sjt_dot320 = 0;
    sjs_mat4* sjt_dot321 = 0;
    sjs_mat4* sjt_dot322 = 0;
    sjs_mat4* sjt_dot323 = 0;
    sjs_mat4* sjt_dot324 = 0;
    sjs_mat4* sjt_dot325 = 0;
    sjs_mat4* sjt_dot326 = 0;
    sjs_mat4* sjt_dot327 = 0;
    sjs_mat4* sjt_dot328 = 0;
    sjs_mat4* sjt_dot329 = 0;
    sjs_mat4* sjt_dot330 = 0;
    sjs_mat4* sjt_dot331 = 0;
    sjs_mat4* sjt_dot332 = 0;
    sjs_mat4* sjt_dot333 = 0;
    sjs_mat4* sjt_dot334 = 0;
    sjs_mat4* sjt_dot335 = 0;
    sjs_mat4* sjt_dot336 = 0;
    sjs_mat4* sjt_dot337 = 0;
    sjs_mat4* sjt_dot338 = 0;
    sjs_mat4* sjt_dot339 = 0;
    sjs_mat4* sjt_dot340 = 0;
    sjs_mat4* sjt_dot341 = 0;
    sjs_mat4* sjt_dot342 = 0;
    sjs_mat4* sjt_dot343 = 0;
    sjs_mat4* sjt_dot344 = 0;
    sjs_mat4* sjt_dot345 = 0;
    sjs_mat4* sjt_dot346 = 0;
    sjs_mat4* sjt_dot347 = 0;
    sjs_mat4* sjt_dot348 = 0;
    sjs_mat4* sjt_dot349 = 0;
    sjs_mat4* sjt_dot350 = 0;
    sjs_mat4* sjt_dot351 = 0;
    sjs_mat4* sjt_dot352 = 0;
    sjs_mat4* sjt_dot353 = 0;
    sjs_mat4* sjt_dot354 = 0;
    sjs_mat4* sjt_dot355 = 0;
    sjs_mat4* sjt_dot356 = 0;
    sjs_mat4* sjt_dot357 = 0;
    sjs_mat4* sjt_dot358 = 0;
    sjs_mat4* sjt_dot359 = 0;
    sjs_mat4* sjt_dot360 = 0;
    sjs_mat4* sjt_dot361 = 0;
    sjs_mat4* sjt_dot362 = 0;
    sjs_mat4* sjt_dot363 = 0;
    sjs_mat4* sjt_dot364 = 0;
    sjs_mat4* sjt_dot365 = 0;
    sjs_mat4* sjt_dot366 = 0;
    sjs_mat4* sjt_dot367 = 0;
    sjs_mat4* sjt_dot368 = 0;
    sjs_mat4* sjt_dot369 = 0;
    sjs_mat4* sjt_dot370 = 0;
    sjs_mat4* sjt_dot371 = 0;
    sjs_mat4* sjt_dot372 = 0;
    sjs_mat4* sjt_dot373 = 0;
    sjs_mat4* sjt_dot374 = 0;
    sjs_mat4* sjt_dot375 = 0;
    sjs_mat4* sjt_dot376 = 0;
    sjs_mat4* sjt_dot377 = 0;
    sjs_mat4* sjt_dot378 = 0;
    sjs_mat4* sjt_dot379 = 0;
    sjs_mat4* sjt_dot380 = 0;
    sjs_mat4* sjt_dot381 = 0;
    sjs_mat4* sjt_dot382 = 0;
    sjs_mat4* sjt_dot383 = 0;
    sjs_mat4* sjt_dot384 = 0;
    sjs_mat4* sjt_dot385 = 0;
    sjs_mat4* sjt_dot386 = 0;
    sjs_mat4* sjt_dot387 = 0;
    sjs_mat4* sjt_dot388 = 0;
    sjs_mat4* sjt_dot389 = 0;
    sjs_mat4* sjt_dot390 = 0;
    sjs_mat4* sjt_dot391 = 0;
    sjs_mat4* sjt_dot392 = 0;
    sjs_mat4* sjt_dot393 = 0;
    sjs_mat4* sjt_dot394 = 0;
    sjs_mat4* sjt_dot395 = 0;
    sjs_mat4* sjt_dot396 = 0;
    sjs_mat4* sjt_dot397 = 0;
    sjs_mat4* sjt_dot398 = 0;
    sjs_mat4* sjt_dot399 = 0;
    sjs_mat4* sjt_dot400 = 0;
    sjs_mat4* sjt_dot401 = 0;
    float sjt_math297;
    float sjt_math298;
    float sjt_math299;
    float sjt_math300;
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

    _return->_refCount = 1;
    sjt_dot274 = m;
    sjt_math303 = (sjt_dot274)->m00;
    sjt_dot275 = _parent;
    sjt_math304 = (sjt_dot275)->m00;
    sjt_math301 = sjt_math303 * sjt_math304;
    sjt_dot276 = m;
    sjt_math305 = (sjt_dot276)->m01;
    sjt_dot277 = _parent;
    sjt_math306 = (sjt_dot277)->m10;
    sjt_math302 = sjt_math305 * sjt_math306;
    sjt_math299 = sjt_math301 + sjt_math302;
    sjt_dot278 = m;
    sjt_math307 = (sjt_dot278)->m02;
    sjt_dot279 = _parent;
    sjt_math308 = (sjt_dot279)->m20;
    sjt_math300 = sjt_math307 * sjt_math308;
    sjt_math297 = sjt_math299 + sjt_math300;
    sjt_dot280 = m;
    sjt_math309 = (sjt_dot280)->m03;
    sjt_dot281 = _parent;
    sjt_math310 = (sjt_dot281)->m30;
    sjt_math298 = sjt_math309 * sjt_math310;
    _return->m00 = sjt_math297 + sjt_math298;
    sjt_dot282 = m;
    sjt_math317 = (sjt_dot282)->m00;
    sjt_dot283 = _parent;
    sjt_math318 = (sjt_dot283)->m01;
    sjt_math315 = sjt_math317 * sjt_math318;
    sjt_dot284 = m;
    sjt_math319 = (sjt_dot284)->m01;
    sjt_dot285 = _parent;
    sjt_math320 = (sjt_dot285)->m11;
    sjt_math316 = sjt_math319 * sjt_math320;
    sjt_math313 = sjt_math315 + sjt_math316;
    sjt_dot286 = m;
    sjt_math321 = (sjt_dot286)->m02;
    sjt_dot287 = _parent;
    sjt_math322 = (sjt_dot287)->m21;
    sjt_math314 = sjt_math321 * sjt_math322;
    sjt_math311 = sjt_math313 + sjt_math314;
    sjt_dot288 = m;
    sjt_math323 = (sjt_dot288)->m03;
    sjt_dot289 = _parent;
    sjt_math324 = (sjt_dot289)->m31;
    sjt_math312 = sjt_math323 * sjt_math324;
    _return->m01 = sjt_math311 + sjt_math312;
    sjt_dot290 = m;
    sjt_math331 = (sjt_dot290)->m00;
    sjt_dot291 = _parent;
    sjt_math332 = (sjt_dot291)->m02;
    sjt_math329 = sjt_math331 * sjt_math332;
    sjt_dot292 = m;
    sjt_math333 = (sjt_dot292)->m01;
    sjt_dot293 = _parent;
    sjt_math334 = (sjt_dot293)->m12;
    sjt_math330 = sjt_math333 * sjt_math334;
    sjt_math327 = sjt_math329 + sjt_math330;
    sjt_dot294 = m;
    sjt_math335 = (sjt_dot294)->m02;
    sjt_dot295 = _parent;
    sjt_math336 = (sjt_dot295)->m22;
    sjt_math328 = sjt_math335 * sjt_math336;
    sjt_math325 = sjt_math327 + sjt_math328;
    sjt_dot296 = m;
    sjt_math337 = (sjt_dot296)->m03;
    sjt_dot297 = _parent;
    sjt_math338 = (sjt_dot297)->m32;
    sjt_math326 = sjt_math337 * sjt_math338;
    _return->m02 = sjt_math325 + sjt_math326;
    sjt_dot298 = m;
    sjt_math345 = (sjt_dot298)->m00;
    sjt_dot299 = _parent;
    sjt_math346 = (sjt_dot299)->m03;
    sjt_math343 = sjt_math345 * sjt_math346;
    sjt_dot300 = m;
    sjt_math347 = (sjt_dot300)->m01;
    sjt_dot301 = _parent;
    sjt_math348 = (sjt_dot301)->m13;
    sjt_math344 = sjt_math347 * sjt_math348;
    sjt_math341 = sjt_math343 + sjt_math344;
    sjt_dot302 = m;
    sjt_math349 = (sjt_dot302)->m02;
    sjt_dot303 = _parent;
    sjt_math350 = (sjt_dot303)->m23;
    sjt_math342 = sjt_math349 * sjt_math350;
    sjt_math339 = sjt_math341 + sjt_math342;
    sjt_dot304 = m;
    sjt_math351 = (sjt_dot304)->m03;
    sjt_dot305 = _parent;
    sjt_math352 = (sjt_dot305)->m33;
    sjt_math340 = sjt_math351 * sjt_math352;
    _return->m03 = sjt_math339 + sjt_math340;
    sjt_dot306 = m;
    sjt_math359 = (sjt_dot306)->m10;
    sjt_dot307 = _parent;
    sjt_math360 = (sjt_dot307)->m00;
    sjt_math357 = sjt_math359 * sjt_math360;
    sjt_dot308 = m;
    sjt_math361 = (sjt_dot308)->m11;
    sjt_dot309 = _parent;
    sjt_math362 = (sjt_dot309)->m10;
    sjt_math358 = sjt_math361 * sjt_math362;
    sjt_math355 = sjt_math357 + sjt_math358;
    sjt_dot310 = m;
    sjt_math363 = (sjt_dot310)->m12;
    sjt_dot311 = _parent;
    sjt_math364 = (sjt_dot311)->m20;
    sjt_math356 = sjt_math363 * sjt_math364;
    sjt_math353 = sjt_math355 + sjt_math356;
    sjt_dot312 = m;
    sjt_math365 = (sjt_dot312)->m13;
    sjt_dot313 = _parent;
    sjt_math366 = (sjt_dot313)->m30;
    sjt_math354 = sjt_math365 * sjt_math366;
    _return->m10 = sjt_math353 + sjt_math354;
    sjt_dot314 = m;
    sjt_math373 = (sjt_dot314)->m10;
    sjt_dot315 = _parent;
    sjt_math374 = (sjt_dot315)->m01;
    sjt_math371 = sjt_math373 * sjt_math374;
    sjt_dot316 = m;
    sjt_math375 = (sjt_dot316)->m11;
    sjt_dot317 = _parent;
    sjt_math376 = (sjt_dot317)->m11;
    sjt_math372 = sjt_math375 * sjt_math376;
    sjt_math369 = sjt_math371 + sjt_math372;
    sjt_dot318 = m;
    sjt_math377 = (sjt_dot318)->m12;
    sjt_dot319 = _parent;
    sjt_math378 = (sjt_dot319)->m21;
    sjt_math370 = sjt_math377 * sjt_math378;
    sjt_math367 = sjt_math369 + sjt_math370;
    sjt_dot320 = m;
    sjt_math379 = (sjt_dot320)->m13;
    sjt_dot321 = _parent;
    sjt_math380 = (sjt_dot321)->m31;
    sjt_math368 = sjt_math379 * sjt_math380;
    _return->m11 = sjt_math367 + sjt_math368;
    sjt_dot322 = m;
    sjt_math387 = (sjt_dot322)->m10;
    sjt_dot323 = _parent;
    sjt_math388 = (sjt_dot323)->m02;
    sjt_math385 = sjt_math387 * sjt_math388;
    sjt_dot324 = m;
    sjt_math389 = (sjt_dot324)->m11;
    sjt_dot325 = _parent;
    sjt_math390 = (sjt_dot325)->m12;
    sjt_math386 = sjt_math389 * sjt_math390;
    sjt_math383 = sjt_math385 + sjt_math386;
    sjt_dot326 = m;
    sjt_math391 = (sjt_dot326)->m12;
    sjt_dot327 = _parent;
    sjt_math392 = (sjt_dot327)->m22;
    sjt_math384 = sjt_math391 * sjt_math392;
    sjt_math381 = sjt_math383 + sjt_math384;
    sjt_dot328 = m;
    sjt_math393 = (sjt_dot328)->m13;
    sjt_dot329 = _parent;
    sjt_math394 = (sjt_dot329)->m32;
    sjt_math382 = sjt_math393 * sjt_math394;
    _return->m12 = sjt_math381 + sjt_math382;
    sjt_dot330 = m;
    sjt_math401 = (sjt_dot330)->m10;
    sjt_dot331 = _parent;
    sjt_math402 = (sjt_dot331)->m03;
    sjt_math399 = sjt_math401 * sjt_math402;
    sjt_dot332 = m;
    sjt_math403 = (sjt_dot332)->m11;
    sjt_dot333 = _parent;
    sjt_math404 = (sjt_dot333)->m13;
    sjt_math400 = sjt_math403 * sjt_math404;
    sjt_math397 = sjt_math399 + sjt_math400;
    sjt_dot334 = m;
    sjt_math405 = (sjt_dot334)->m12;
    sjt_dot335 = _parent;
    sjt_math406 = (sjt_dot335)->m23;
    sjt_math398 = sjt_math405 * sjt_math406;
    sjt_math395 = sjt_math397 + sjt_math398;
    sjt_dot336 = m;
    sjt_math407 = (sjt_dot336)->m13;
    sjt_dot337 = _parent;
    sjt_math408 = (sjt_dot337)->m33;
    sjt_math396 = sjt_math407 * sjt_math408;
    _return->m13 = sjt_math395 + sjt_math396;
    sjt_dot338 = m;
    sjt_math415 = (sjt_dot338)->m20;
    sjt_dot339 = _parent;
    sjt_math416 = (sjt_dot339)->m00;
    sjt_math413 = sjt_math415 * sjt_math416;
    sjt_dot340 = m;
    sjt_math417 = (sjt_dot340)->m21;
    sjt_dot341 = _parent;
    sjt_math418 = (sjt_dot341)->m10;
    sjt_math414 = sjt_math417 * sjt_math418;
    sjt_math411 = sjt_math413 + sjt_math414;
    sjt_dot342 = m;
    sjt_math419 = (sjt_dot342)->m22;
    sjt_dot343 = _parent;
    sjt_math420 = (sjt_dot343)->m20;
    sjt_math412 = sjt_math419 * sjt_math420;
    sjt_math409 = sjt_math411 + sjt_math412;
    sjt_dot344 = m;
    sjt_math421 = (sjt_dot344)->m23;
    sjt_dot345 = _parent;
    sjt_math422 = (sjt_dot345)->m30;
    sjt_math410 = sjt_math421 * sjt_math422;
    _return->m20 = sjt_math409 + sjt_math410;
    sjt_dot346 = m;
    sjt_math429 = (sjt_dot346)->m20;
    sjt_dot347 = _parent;
    sjt_math430 = (sjt_dot347)->m01;
    sjt_math427 = sjt_math429 * sjt_math430;
    sjt_dot348 = m;
    sjt_math431 = (sjt_dot348)->m21;
    sjt_dot349 = _parent;
    sjt_math432 = (sjt_dot349)->m11;
    sjt_math428 = sjt_math431 * sjt_math432;
    sjt_math425 = sjt_math427 + sjt_math428;
    sjt_dot350 = m;
    sjt_math433 = (sjt_dot350)->m22;
    sjt_dot351 = _parent;
    sjt_math434 = (sjt_dot351)->m21;
    sjt_math426 = sjt_math433 * sjt_math434;
    sjt_math423 = sjt_math425 + sjt_math426;
    sjt_dot352 = m;
    sjt_math435 = (sjt_dot352)->m23;
    sjt_dot353 = _parent;
    sjt_math436 = (sjt_dot353)->m31;
    sjt_math424 = sjt_math435 * sjt_math436;
    _return->m21 = sjt_math423 + sjt_math424;
    sjt_dot354 = m;
    sjt_math443 = (sjt_dot354)->m20;
    sjt_dot355 = _parent;
    sjt_math444 = (sjt_dot355)->m02;
    sjt_math441 = sjt_math443 * sjt_math444;
    sjt_dot356 = m;
    sjt_math445 = (sjt_dot356)->m21;
    sjt_dot357 = _parent;
    sjt_math446 = (sjt_dot357)->m12;
    sjt_math442 = sjt_math445 * sjt_math446;
    sjt_math439 = sjt_math441 + sjt_math442;
    sjt_dot358 = m;
    sjt_math447 = (sjt_dot358)->m22;
    sjt_dot359 = _parent;
    sjt_math448 = (sjt_dot359)->m22;
    sjt_math440 = sjt_math447 * sjt_math448;
    sjt_math437 = sjt_math439 + sjt_math440;
    sjt_dot360 = m;
    sjt_math449 = (sjt_dot360)->m23;
    sjt_dot361 = _parent;
    sjt_math450 = (sjt_dot361)->m32;
    sjt_math438 = sjt_math449 * sjt_math450;
    _return->m22 = sjt_math437 + sjt_math438;
    sjt_dot362 = m;
    sjt_math457 = (sjt_dot362)->m20;
    sjt_dot363 = _parent;
    sjt_math458 = (sjt_dot363)->m03;
    sjt_math455 = sjt_math457 * sjt_math458;
    sjt_dot364 = m;
    sjt_math459 = (sjt_dot364)->m21;
    sjt_dot365 = _parent;
    sjt_math460 = (sjt_dot365)->m13;
    sjt_math456 = sjt_math459 * sjt_math460;
    sjt_math453 = sjt_math455 + sjt_math456;
    sjt_dot366 = m;
    sjt_math461 = (sjt_dot366)->m22;
    sjt_dot367 = _parent;
    sjt_math462 = (sjt_dot367)->m23;
    sjt_math454 = sjt_math461 * sjt_math462;
    sjt_math451 = sjt_math453 + sjt_math454;
    sjt_dot368 = m;
    sjt_math463 = (sjt_dot368)->m23;
    sjt_dot369 = _parent;
    sjt_math464 = (sjt_dot369)->m33;
    sjt_math452 = sjt_math463 * sjt_math464;
    _return->m23 = sjt_math451 + sjt_math452;
    sjt_dot370 = m;
    sjt_math471 = (sjt_dot370)->m30;
    sjt_dot371 = _parent;
    sjt_math472 = (sjt_dot371)->m00;
    sjt_math469 = sjt_math471 * sjt_math472;
    sjt_dot372 = m;
    sjt_math473 = (sjt_dot372)->m31;
    sjt_dot373 = _parent;
    sjt_math474 = (sjt_dot373)->m10;
    sjt_math470 = sjt_math473 * sjt_math474;
    sjt_math467 = sjt_math469 + sjt_math470;
    sjt_dot374 = m;
    sjt_math475 = (sjt_dot374)->m32;
    sjt_dot375 = _parent;
    sjt_math476 = (sjt_dot375)->m20;
    sjt_math468 = sjt_math475 * sjt_math476;
    sjt_math465 = sjt_math467 + sjt_math468;
    sjt_dot376 = m;
    sjt_math477 = (sjt_dot376)->m33;
    sjt_dot377 = _parent;
    sjt_math478 = (sjt_dot377)->m30;
    sjt_math466 = sjt_math477 * sjt_math478;
    _return->m30 = sjt_math465 + sjt_math466;
    sjt_dot378 = m;
    sjt_math485 = (sjt_dot378)->m30;
    sjt_dot379 = _parent;
    sjt_math486 = (sjt_dot379)->m01;
    sjt_math483 = sjt_math485 * sjt_math486;
    sjt_dot380 = m;
    sjt_math487 = (sjt_dot380)->m31;
    sjt_dot381 = _parent;
    sjt_math488 = (sjt_dot381)->m11;
    sjt_math484 = sjt_math487 * sjt_math488;
    sjt_math481 = sjt_math483 + sjt_math484;
    sjt_dot382 = m;
    sjt_math489 = (sjt_dot382)->m32;
    sjt_dot383 = _parent;
    sjt_math490 = (sjt_dot383)->m21;
    sjt_math482 = sjt_math489 * sjt_math490;
    sjt_math479 = sjt_math481 + sjt_math482;
    sjt_dot384 = m;
    sjt_math491 = (sjt_dot384)->m33;
    sjt_dot385 = _parent;
    sjt_math492 = (sjt_dot385)->m31;
    sjt_math480 = sjt_math491 * sjt_math492;
    _return->m31 = sjt_math479 + sjt_math480;
    sjt_dot386 = m;
    sjt_math499 = (sjt_dot386)->m30;
    sjt_dot387 = _parent;
    sjt_math500 = (sjt_dot387)->m02;
    sjt_math497 = sjt_math499 * sjt_math500;
    sjt_dot388 = m;
    sjt_math501 = (sjt_dot388)->m31;
    sjt_dot389 = _parent;
    sjt_math502 = (sjt_dot389)->m12;
    sjt_math498 = sjt_math501 * sjt_math502;
    sjt_math495 = sjt_math497 + sjt_math498;
    sjt_dot390 = m;
    sjt_math503 = (sjt_dot390)->m32;
    sjt_dot391 = _parent;
    sjt_math504 = (sjt_dot391)->m22;
    sjt_math496 = sjt_math503 * sjt_math504;
    sjt_math493 = sjt_math495 + sjt_math496;
    sjt_dot392 = m;
    sjt_math505 = (sjt_dot392)->m33;
    sjt_dot393 = _parent;
    sjt_math506 = (sjt_dot393)->m32;
    sjt_math494 = sjt_math505 * sjt_math506;
    _return->m32 = sjt_math493 + sjt_math494;
    sjt_dot394 = m;
    sjt_math513 = (sjt_dot394)->m30;
    sjt_dot395 = _parent;
    sjt_math514 = (sjt_dot395)->m03;
    sjt_math511 = sjt_math513 * sjt_math514;
    sjt_dot396 = m;
    sjt_math515 = (sjt_dot396)->m31;
    sjt_dot397 = _parent;
    sjt_math516 = (sjt_dot397)->m13;
    sjt_math512 = sjt_math515 * sjt_math516;
    sjt_math509 = sjt_math511 + sjt_math512;
    sjt_dot398 = m;
    sjt_math517 = (sjt_dot398)->m32;
    sjt_dot399 = _parent;
    sjt_math518 = (sjt_dot399)->m23;
    sjt_math510 = sjt_math517 * sjt_math518;
    sjt_math507 = sjt_math509 + sjt_math510;
    sjt_dot400 = m;
    sjt_math519 = (sjt_dot400)->m33;
    sjt_dot401 = _parent;
    sjt_math520 = (sjt_dot401)->m33;
    sjt_math508 = sjt_math519 * sjt_math520;
    _return->m33 = sjt_math507 + sjt_math508;
    sjf_mat4(_return);
}

void sjf_mat4_multiply_heap(sjs_mat4* _parent, sjs_mat4* m, sjs_mat4** _return) {
    sjs_mat4* sjt_dot402 = 0;
    sjs_mat4* sjt_dot403 = 0;
    sjs_mat4* sjt_dot404 = 0;
    sjs_mat4* sjt_dot405 = 0;
    sjs_mat4* sjt_dot406 = 0;
    sjs_mat4* sjt_dot407 = 0;
    sjs_mat4* sjt_dot408 = 0;
    sjs_mat4* sjt_dot409 = 0;
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

    (*_return) = (sjs_mat4*)malloc(sizeof(sjs_mat4));
    (*_return)->_refCount = 1;
    sjt_dot402 = m;
    sjt_math527 = (sjt_dot402)->m00;
    sjt_dot403 = _parent;
    sjt_math528 = (sjt_dot403)->m00;
    sjt_math525 = sjt_math527 * sjt_math528;
    sjt_dot404 = m;
    sjt_math529 = (sjt_dot404)->m01;
    sjt_dot405 = _parent;
    sjt_math530 = (sjt_dot405)->m10;
    sjt_math526 = sjt_math529 * sjt_math530;
    sjt_math523 = sjt_math525 + sjt_math526;
    sjt_dot406 = m;
    sjt_math531 = (sjt_dot406)->m02;
    sjt_dot407 = _parent;
    sjt_math532 = (sjt_dot407)->m20;
    sjt_math524 = sjt_math531 * sjt_math532;
    sjt_math521 = sjt_math523 + sjt_math524;
    sjt_dot408 = m;
    sjt_math533 = (sjt_dot408)->m03;
    sjt_dot409 = _parent;
    sjt_math534 = (sjt_dot409)->m30;
    sjt_math522 = sjt_math533 * sjt_math534;
    (*_return)->m00 = sjt_math521 + sjt_math522;
    sjt_dot410 = m;
    sjt_math541 = (sjt_dot410)->m00;
    sjt_dot411 = _parent;
    sjt_math542 = (sjt_dot411)->m01;
    sjt_math539 = sjt_math541 * sjt_math542;
    sjt_dot412 = m;
    sjt_math543 = (sjt_dot412)->m01;
    sjt_dot413 = _parent;
    sjt_math544 = (sjt_dot413)->m11;
    sjt_math540 = sjt_math543 * sjt_math544;
    sjt_math537 = sjt_math539 + sjt_math540;
    sjt_dot414 = m;
    sjt_math545 = (sjt_dot414)->m02;
    sjt_dot415 = _parent;
    sjt_math546 = (sjt_dot415)->m21;
    sjt_math538 = sjt_math545 * sjt_math546;
    sjt_math535 = sjt_math537 + sjt_math538;
    sjt_dot416 = m;
    sjt_math547 = (sjt_dot416)->m03;
    sjt_dot417 = _parent;
    sjt_math548 = (sjt_dot417)->m31;
    sjt_math536 = sjt_math547 * sjt_math548;
    (*_return)->m01 = sjt_math535 + sjt_math536;
    sjt_dot418 = m;
    sjt_math555 = (sjt_dot418)->m00;
    sjt_dot419 = _parent;
    sjt_math556 = (sjt_dot419)->m02;
    sjt_math553 = sjt_math555 * sjt_math556;
    sjt_dot420 = m;
    sjt_math557 = (sjt_dot420)->m01;
    sjt_dot421 = _parent;
    sjt_math558 = (sjt_dot421)->m12;
    sjt_math554 = sjt_math557 * sjt_math558;
    sjt_math551 = sjt_math553 + sjt_math554;
    sjt_dot422 = m;
    sjt_math559 = (sjt_dot422)->m02;
    sjt_dot423 = _parent;
    sjt_math560 = (sjt_dot423)->m22;
    sjt_math552 = sjt_math559 * sjt_math560;
    sjt_math549 = sjt_math551 + sjt_math552;
    sjt_dot424 = m;
    sjt_math561 = (sjt_dot424)->m03;
    sjt_dot425 = _parent;
    sjt_math562 = (sjt_dot425)->m32;
    sjt_math550 = sjt_math561 * sjt_math562;
    (*_return)->m02 = sjt_math549 + sjt_math550;
    sjt_dot426 = m;
    sjt_math569 = (sjt_dot426)->m00;
    sjt_dot427 = _parent;
    sjt_math570 = (sjt_dot427)->m03;
    sjt_math567 = sjt_math569 * sjt_math570;
    sjt_dot428 = m;
    sjt_math571 = (sjt_dot428)->m01;
    sjt_dot429 = _parent;
    sjt_math572 = (sjt_dot429)->m13;
    sjt_math568 = sjt_math571 * sjt_math572;
    sjt_math565 = sjt_math567 + sjt_math568;
    sjt_dot430 = m;
    sjt_math573 = (sjt_dot430)->m02;
    sjt_dot431 = _parent;
    sjt_math574 = (sjt_dot431)->m23;
    sjt_math566 = sjt_math573 * sjt_math574;
    sjt_math563 = sjt_math565 + sjt_math566;
    sjt_dot432 = m;
    sjt_math575 = (sjt_dot432)->m03;
    sjt_dot433 = _parent;
    sjt_math576 = (sjt_dot433)->m33;
    sjt_math564 = sjt_math575 * sjt_math576;
    (*_return)->m03 = sjt_math563 + sjt_math564;
    sjt_dot434 = m;
    sjt_math583 = (sjt_dot434)->m10;
    sjt_dot435 = _parent;
    sjt_math584 = (sjt_dot435)->m00;
    sjt_math581 = sjt_math583 * sjt_math584;
    sjt_dot436 = m;
    sjt_math585 = (sjt_dot436)->m11;
    sjt_dot437 = _parent;
    sjt_math586 = (sjt_dot437)->m10;
    sjt_math582 = sjt_math585 * sjt_math586;
    sjt_math579 = sjt_math581 + sjt_math582;
    sjt_dot438 = m;
    sjt_math587 = (sjt_dot438)->m12;
    sjt_dot439 = _parent;
    sjt_math588 = (sjt_dot439)->m20;
    sjt_math580 = sjt_math587 * sjt_math588;
    sjt_math577 = sjt_math579 + sjt_math580;
    sjt_dot440 = m;
    sjt_math589 = (sjt_dot440)->m13;
    sjt_dot441 = _parent;
    sjt_math590 = (sjt_dot441)->m30;
    sjt_math578 = sjt_math589 * sjt_math590;
    (*_return)->m10 = sjt_math577 + sjt_math578;
    sjt_dot442 = m;
    sjt_math597 = (sjt_dot442)->m10;
    sjt_dot443 = _parent;
    sjt_math598 = (sjt_dot443)->m01;
    sjt_math595 = sjt_math597 * sjt_math598;
    sjt_dot444 = m;
    sjt_math599 = (sjt_dot444)->m11;
    sjt_dot445 = _parent;
    sjt_math600 = (sjt_dot445)->m11;
    sjt_math596 = sjt_math599 * sjt_math600;
    sjt_math593 = sjt_math595 + sjt_math596;
    sjt_dot446 = m;
    sjt_math601 = (sjt_dot446)->m12;
    sjt_dot447 = _parent;
    sjt_math602 = (sjt_dot447)->m21;
    sjt_math594 = sjt_math601 * sjt_math602;
    sjt_math591 = sjt_math593 + sjt_math594;
    sjt_dot448 = m;
    sjt_math603 = (sjt_dot448)->m13;
    sjt_dot449 = _parent;
    sjt_math604 = (sjt_dot449)->m31;
    sjt_math592 = sjt_math603 * sjt_math604;
    (*_return)->m11 = sjt_math591 + sjt_math592;
    sjt_dot450 = m;
    sjt_math611 = (sjt_dot450)->m10;
    sjt_dot451 = _parent;
    sjt_math612 = (sjt_dot451)->m02;
    sjt_math609 = sjt_math611 * sjt_math612;
    sjt_dot452 = m;
    sjt_math613 = (sjt_dot452)->m11;
    sjt_dot453 = _parent;
    sjt_math614 = (sjt_dot453)->m12;
    sjt_math610 = sjt_math613 * sjt_math614;
    sjt_math607 = sjt_math609 + sjt_math610;
    sjt_dot454 = m;
    sjt_math615 = (sjt_dot454)->m12;
    sjt_dot455 = _parent;
    sjt_math616 = (sjt_dot455)->m22;
    sjt_math608 = sjt_math615 * sjt_math616;
    sjt_math605 = sjt_math607 + sjt_math608;
    sjt_dot456 = m;
    sjt_math617 = (sjt_dot456)->m13;
    sjt_dot457 = _parent;
    sjt_math618 = (sjt_dot457)->m32;
    sjt_math606 = sjt_math617 * sjt_math618;
    (*_return)->m12 = sjt_math605 + sjt_math606;
    sjt_dot458 = m;
    sjt_math625 = (sjt_dot458)->m10;
    sjt_dot459 = _parent;
    sjt_math626 = (sjt_dot459)->m03;
    sjt_math623 = sjt_math625 * sjt_math626;
    sjt_dot460 = m;
    sjt_math627 = (sjt_dot460)->m11;
    sjt_dot461 = _parent;
    sjt_math628 = (sjt_dot461)->m13;
    sjt_math624 = sjt_math627 * sjt_math628;
    sjt_math621 = sjt_math623 + sjt_math624;
    sjt_dot462 = m;
    sjt_math629 = (sjt_dot462)->m12;
    sjt_dot463 = _parent;
    sjt_math630 = (sjt_dot463)->m23;
    sjt_math622 = sjt_math629 * sjt_math630;
    sjt_math619 = sjt_math621 + sjt_math622;
    sjt_dot464 = m;
    sjt_math631 = (sjt_dot464)->m13;
    sjt_dot465 = _parent;
    sjt_math632 = (sjt_dot465)->m33;
    sjt_math620 = sjt_math631 * sjt_math632;
    (*_return)->m13 = sjt_math619 + sjt_math620;
    sjt_dot466 = m;
    sjt_math639 = (sjt_dot466)->m20;
    sjt_dot467 = _parent;
    sjt_math640 = (sjt_dot467)->m00;
    sjt_math637 = sjt_math639 * sjt_math640;
    sjt_dot468 = m;
    sjt_math641 = (sjt_dot468)->m21;
    sjt_dot469 = _parent;
    sjt_math642 = (sjt_dot469)->m10;
    sjt_math638 = sjt_math641 * sjt_math642;
    sjt_math635 = sjt_math637 + sjt_math638;
    sjt_dot470 = m;
    sjt_math643 = (sjt_dot470)->m22;
    sjt_dot471 = _parent;
    sjt_math644 = (sjt_dot471)->m20;
    sjt_math636 = sjt_math643 * sjt_math644;
    sjt_math633 = sjt_math635 + sjt_math636;
    sjt_dot472 = m;
    sjt_math645 = (sjt_dot472)->m23;
    sjt_dot473 = _parent;
    sjt_math646 = (sjt_dot473)->m30;
    sjt_math634 = sjt_math645 * sjt_math646;
    (*_return)->m20 = sjt_math633 + sjt_math634;
    sjt_dot474 = m;
    sjt_math653 = (sjt_dot474)->m20;
    sjt_dot475 = _parent;
    sjt_math654 = (sjt_dot475)->m01;
    sjt_math651 = sjt_math653 * sjt_math654;
    sjt_dot476 = m;
    sjt_math655 = (sjt_dot476)->m21;
    sjt_dot477 = _parent;
    sjt_math656 = (sjt_dot477)->m11;
    sjt_math652 = sjt_math655 * sjt_math656;
    sjt_math649 = sjt_math651 + sjt_math652;
    sjt_dot478 = m;
    sjt_math657 = (sjt_dot478)->m22;
    sjt_dot479 = _parent;
    sjt_math658 = (sjt_dot479)->m21;
    sjt_math650 = sjt_math657 * sjt_math658;
    sjt_math647 = sjt_math649 + sjt_math650;
    sjt_dot480 = m;
    sjt_math659 = (sjt_dot480)->m23;
    sjt_dot481 = _parent;
    sjt_math660 = (sjt_dot481)->m31;
    sjt_math648 = sjt_math659 * sjt_math660;
    (*_return)->m21 = sjt_math647 + sjt_math648;
    sjt_dot482 = m;
    sjt_math667 = (sjt_dot482)->m20;
    sjt_dot483 = _parent;
    sjt_math668 = (sjt_dot483)->m02;
    sjt_math665 = sjt_math667 * sjt_math668;
    sjt_dot484 = m;
    sjt_math669 = (sjt_dot484)->m21;
    sjt_dot485 = _parent;
    sjt_math670 = (sjt_dot485)->m12;
    sjt_math666 = sjt_math669 * sjt_math670;
    sjt_math663 = sjt_math665 + sjt_math666;
    sjt_dot486 = m;
    sjt_math671 = (sjt_dot486)->m22;
    sjt_dot487 = _parent;
    sjt_math672 = (sjt_dot487)->m22;
    sjt_math664 = sjt_math671 * sjt_math672;
    sjt_math661 = sjt_math663 + sjt_math664;
    sjt_dot488 = m;
    sjt_math673 = (sjt_dot488)->m23;
    sjt_dot489 = _parent;
    sjt_math674 = (sjt_dot489)->m32;
    sjt_math662 = sjt_math673 * sjt_math674;
    (*_return)->m22 = sjt_math661 + sjt_math662;
    sjt_dot490 = m;
    sjt_math681 = (sjt_dot490)->m20;
    sjt_dot491 = _parent;
    sjt_math682 = (sjt_dot491)->m03;
    sjt_math679 = sjt_math681 * sjt_math682;
    sjt_dot492 = m;
    sjt_math683 = (sjt_dot492)->m21;
    sjt_dot493 = _parent;
    sjt_math684 = (sjt_dot493)->m13;
    sjt_math680 = sjt_math683 * sjt_math684;
    sjt_math677 = sjt_math679 + sjt_math680;
    sjt_dot494 = m;
    sjt_math685 = (sjt_dot494)->m22;
    sjt_dot495 = _parent;
    sjt_math686 = (sjt_dot495)->m23;
    sjt_math678 = sjt_math685 * sjt_math686;
    sjt_math675 = sjt_math677 + sjt_math678;
    sjt_dot496 = m;
    sjt_math687 = (sjt_dot496)->m23;
    sjt_dot497 = _parent;
    sjt_math688 = (sjt_dot497)->m33;
    sjt_math676 = sjt_math687 * sjt_math688;
    (*_return)->m23 = sjt_math675 + sjt_math676;
    sjt_dot498 = m;
    sjt_math695 = (sjt_dot498)->m30;
    sjt_dot499 = _parent;
    sjt_math696 = (sjt_dot499)->m00;
    sjt_math693 = sjt_math695 * sjt_math696;
    sjt_dot500 = m;
    sjt_math697 = (sjt_dot500)->m31;
    sjt_dot501 = _parent;
    sjt_math698 = (sjt_dot501)->m10;
    sjt_math694 = sjt_math697 * sjt_math698;
    sjt_math691 = sjt_math693 + sjt_math694;
    sjt_dot502 = m;
    sjt_math699 = (sjt_dot502)->m32;
    sjt_dot503 = _parent;
    sjt_math700 = (sjt_dot503)->m20;
    sjt_math692 = sjt_math699 * sjt_math700;
    sjt_math689 = sjt_math691 + sjt_math692;
    sjt_dot504 = m;
    sjt_math701 = (sjt_dot504)->m33;
    sjt_dot505 = _parent;
    sjt_math702 = (sjt_dot505)->m30;
    sjt_math690 = sjt_math701 * sjt_math702;
    (*_return)->m30 = sjt_math689 + sjt_math690;
    sjt_dot506 = m;
    sjt_math709 = (sjt_dot506)->m30;
    sjt_dot507 = _parent;
    sjt_math710 = (sjt_dot507)->m01;
    sjt_math707 = sjt_math709 * sjt_math710;
    sjt_dot508 = m;
    sjt_math711 = (sjt_dot508)->m31;
    sjt_dot509 = _parent;
    sjt_math712 = (sjt_dot509)->m11;
    sjt_math708 = sjt_math711 * sjt_math712;
    sjt_math705 = sjt_math707 + sjt_math708;
    sjt_dot510 = m;
    sjt_math713 = (sjt_dot510)->m32;
    sjt_dot511 = _parent;
    sjt_math714 = (sjt_dot511)->m21;
    sjt_math706 = sjt_math713 * sjt_math714;
    sjt_math703 = sjt_math705 + sjt_math706;
    sjt_dot512 = m;
    sjt_math715 = (sjt_dot512)->m33;
    sjt_dot513 = _parent;
    sjt_math716 = (sjt_dot513)->m31;
    sjt_math704 = sjt_math715 * sjt_math716;
    (*_return)->m31 = sjt_math703 + sjt_math704;
    sjt_dot514 = m;
    sjt_math723 = (sjt_dot514)->m30;
    sjt_dot515 = _parent;
    sjt_math724 = (sjt_dot515)->m02;
    sjt_math721 = sjt_math723 * sjt_math724;
    sjt_dot516 = m;
    sjt_math725 = (sjt_dot516)->m31;
    sjt_dot517 = _parent;
    sjt_math726 = (sjt_dot517)->m12;
    sjt_math722 = sjt_math725 * sjt_math726;
    sjt_math719 = sjt_math721 + sjt_math722;
    sjt_dot518 = m;
    sjt_math727 = (sjt_dot518)->m32;
    sjt_dot519 = _parent;
    sjt_math728 = (sjt_dot519)->m22;
    sjt_math720 = sjt_math727 * sjt_math728;
    sjt_math717 = sjt_math719 + sjt_math720;
    sjt_dot520 = m;
    sjt_math729 = (sjt_dot520)->m33;
    sjt_dot521 = _parent;
    sjt_math730 = (sjt_dot521)->m32;
    sjt_math718 = sjt_math729 * sjt_math730;
    (*_return)->m32 = sjt_math717 + sjt_math718;
    sjt_dot522 = m;
    sjt_math737 = (sjt_dot522)->m30;
    sjt_dot523 = _parent;
    sjt_math738 = (sjt_dot523)->m03;
    sjt_math735 = sjt_math737 * sjt_math738;
    sjt_dot524 = m;
    sjt_math739 = (sjt_dot524)->m31;
    sjt_dot525 = _parent;
    sjt_math740 = (sjt_dot525)->m13;
    sjt_math736 = sjt_math739 * sjt_math740;
    sjt_math733 = sjt_math735 + sjt_math736;
    sjt_dot526 = m;
    sjt_math741 = (sjt_dot526)->m32;
    sjt_dot527 = _parent;
    sjt_math742 = (sjt_dot527)->m23;
    sjt_math734 = sjt_math741 * sjt_math742;
    sjt_math731 = sjt_math733 + sjt_math734;
    sjt_dot528 = m;
    sjt_math743 = (sjt_dot528)->m33;
    sjt_dot529 = _parent;
    sjt_math744 = (sjt_dot529)->m33;
    sjt_math732 = sjt_math743 * sjt_math744;
    (*_return)->m33 = sjt_math731 + sjt_math732;
    sjf_mat4_heap((*_return));
}

void sjf_mat4_multiplyf32(sjs_mat4* _parent, float x, sjs_mat4* _return) {
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

    _return->_refCount = 1;
    sjt_dot886 = _parent;
    sjt_math1297 = (sjt_dot886)->m00;
    sjt_math1298 = x;
    _return->m00 = sjt_math1297 * sjt_math1298;
    sjt_dot887 = _parent;
    sjt_math1299 = (sjt_dot887)->m01;
    sjt_math1300 = x;
    _return->m01 = sjt_math1299 * sjt_math1300;
    sjt_dot888 = _parent;
    sjt_math1301 = (sjt_dot888)->m02;
    sjt_math1302 = x;
    _return->m02 = sjt_math1301 * sjt_math1302;
    sjt_dot889 = _parent;
    sjt_math1303 = (sjt_dot889)->m03;
    sjt_math1304 = x;
    _return->m03 = sjt_math1303 * sjt_math1304;
    sjt_dot890 = _parent;
    sjt_math1305 = (sjt_dot890)->m10;
    sjt_math1306 = x;
    _return->m10 = sjt_math1305 * sjt_math1306;
    sjt_dot891 = _parent;
    sjt_math1307 = (sjt_dot891)->m11;
    sjt_math1308 = x;
    _return->m11 = sjt_math1307 * sjt_math1308;
    sjt_dot892 = _parent;
    sjt_math1309 = (sjt_dot892)->m12;
    sjt_math1310 = x;
    _return->m12 = sjt_math1309 * sjt_math1310;
    sjt_dot893 = _parent;
    sjt_math1311 = (sjt_dot893)->m13;
    sjt_math1312 = x;
    _return->m13 = sjt_math1311 * sjt_math1312;
    sjt_dot894 = _parent;
    sjt_math1313 = (sjt_dot894)->m20;
    sjt_math1314 = x;
    _return->m20 = sjt_math1313 * sjt_math1314;
    sjt_dot895 = _parent;
    sjt_math1315 = (sjt_dot895)->m21;
    sjt_math1316 = x;
    _return->m21 = sjt_math1315 * sjt_math1316;
    sjt_dot896 = _parent;
    sjt_math1317 = (sjt_dot896)->m22;
    sjt_math1318 = x;
    _return->m22 = sjt_math1317 * sjt_math1318;
    sjt_dot897 = _parent;
    sjt_math1319 = (sjt_dot897)->m23;
    sjt_math1320 = x;
    _return->m23 = sjt_math1319 * sjt_math1320;
    sjt_dot898 = _parent;
    sjt_math1321 = (sjt_dot898)->m30;
    sjt_math1322 = x;
    _return->m30 = sjt_math1321 * sjt_math1322;
    sjt_dot899 = _parent;
    sjt_math1323 = (sjt_dot899)->m31;
    sjt_math1324 = x;
    _return->m31 = sjt_math1323 * sjt_math1324;
    sjt_dot900 = _parent;
    sjt_math1325 = (sjt_dot900)->m32;
    sjt_math1326 = x;
    _return->m32 = sjt_math1325 * sjt_math1326;
    sjt_dot901 = _parent;
    sjt_math1327 = (sjt_dot901)->m33;
    sjt_math1328 = x;
    _return->m33 = sjt_math1327 * sjt_math1328;
    sjf_mat4(_return);
}

void sjf_mat4_multiplyf32_heap(sjs_mat4* _parent, float x, sjs_mat4** _return) {
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

    (*_return) = (sjs_mat4*)malloc(sizeof(sjs_mat4));
    (*_return)->_refCount = 1;
    sjt_dot902 = _parent;
    sjt_math1329 = (sjt_dot902)->m00;
    sjt_math1330 = x;
    (*_return)->m00 = sjt_math1329 * sjt_math1330;
    sjt_dot903 = _parent;
    sjt_math1331 = (sjt_dot903)->m01;
    sjt_math1332 = x;
    (*_return)->m01 = sjt_math1331 * sjt_math1332;
    sjt_dot904 = _parent;
    sjt_math1333 = (sjt_dot904)->m02;
    sjt_math1334 = x;
    (*_return)->m02 = sjt_math1333 * sjt_math1334;
    sjt_dot905 = _parent;
    sjt_math1335 = (sjt_dot905)->m03;
    sjt_math1336 = x;
    (*_return)->m03 = sjt_math1335 * sjt_math1336;
    sjt_dot906 = _parent;
    sjt_math1337 = (sjt_dot906)->m10;
    sjt_math1338 = x;
    (*_return)->m10 = sjt_math1337 * sjt_math1338;
    sjt_dot907 = _parent;
    sjt_math1339 = (sjt_dot907)->m11;
    sjt_math1340 = x;
    (*_return)->m11 = sjt_math1339 * sjt_math1340;
    sjt_dot908 = _parent;
    sjt_math1341 = (sjt_dot908)->m12;
    sjt_math1342 = x;
    (*_return)->m12 = sjt_math1341 * sjt_math1342;
    sjt_dot909 = _parent;
    sjt_math1343 = (sjt_dot909)->m13;
    sjt_math1344 = x;
    (*_return)->m13 = sjt_math1343 * sjt_math1344;
    sjt_dot910 = _parent;
    sjt_math1345 = (sjt_dot910)->m20;
    sjt_math1346 = x;
    (*_return)->m20 = sjt_math1345 * sjt_math1346;
    sjt_dot911 = _parent;
    sjt_math1347 = (sjt_dot911)->m21;
    sjt_math1348 = x;
    (*_return)->m21 = sjt_math1347 * sjt_math1348;
    sjt_dot912 = _parent;
    sjt_math1349 = (sjt_dot912)->m22;
    sjt_math1350 = x;
    (*_return)->m22 = sjt_math1349 * sjt_math1350;
    sjt_dot913 = _parent;
    sjt_math1351 = (sjt_dot913)->m23;
    sjt_math1352 = x;
    (*_return)->m23 = sjt_math1351 * sjt_math1352;
    sjt_dot914 = _parent;
    sjt_math1353 = (sjt_dot914)->m30;
    sjt_math1354 = x;
    (*_return)->m30 = sjt_math1353 * sjt_math1354;
    sjt_dot915 = _parent;
    sjt_math1355 = (sjt_dot915)->m31;
    sjt_math1356 = x;
    (*_return)->m31 = sjt_math1355 * sjt_math1356;
    sjt_dot916 = _parent;
    sjt_math1357 = (sjt_dot916)->m32;
    sjt_math1358 = x;
    (*_return)->m32 = sjt_math1357 * sjt_math1358;
    sjt_dot917 = _parent;
    sjt_math1359 = (sjt_dot917)->m33;
    sjt_math1360 = x;
    (*_return)->m33 = sjt_math1359 * sjt_math1360;
    sjf_mat4_heap((*_return));
}

void sjf_mat4_multiplyvec4(sjs_mat4* _parent, sjs_vec4* v, sjs_vec4* _return) {
    sjs_mat4* sjt_dot210 = 0;
    sjs_vec4* sjt_dot211 = 0;
    sjs_mat4* sjt_dot212 = 0;
    sjs_vec4* sjt_dot213 = 0;
    sjs_mat4* sjt_dot214 = 0;
    sjs_vec4* sjt_dot215 = 0;
    sjs_mat4* sjt_dot216 = 0;
    sjs_vec4* sjt_dot217 = 0;
    sjs_mat4* sjt_dot218 = 0;
    sjs_vec4* sjt_dot219 = 0;
    sjs_mat4* sjt_dot220 = 0;
    sjs_vec4* sjt_dot221 = 0;
    sjs_mat4* sjt_dot222 = 0;
    sjs_vec4* sjt_dot223 = 0;
    sjs_mat4* sjt_dot224 = 0;
    sjs_vec4* sjt_dot225 = 0;
    sjs_mat4* sjt_dot226 = 0;
    sjs_vec4* sjt_dot227 = 0;
    sjs_mat4* sjt_dot228 = 0;
    sjs_vec4* sjt_dot229 = 0;
    sjs_mat4* sjt_dot230 = 0;
    sjs_vec4* sjt_dot231 = 0;
    sjs_mat4* sjt_dot232 = 0;
    sjs_vec4* sjt_dot233 = 0;
    sjs_mat4* sjt_dot234 = 0;
    sjs_vec4* sjt_dot235 = 0;
    sjs_mat4* sjt_dot236 = 0;
    sjs_vec4* sjt_dot237 = 0;
    sjs_mat4* sjt_dot238 = 0;
    sjs_vec4* sjt_dot239 = 0;
    sjs_mat4* sjt_dot240 = 0;
    sjs_vec4* sjt_dot241 = 0;
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

    _return->_refCount = 1;
    sjt_dot210 = _parent;
    sjt_math191 = (sjt_dot210)->m00;
    sjt_dot211 = v;
    sjt_math192 = (sjt_dot211)->x;
    sjt_math189 = sjt_math191 * sjt_math192;
    sjt_dot212 = _parent;
    sjt_math193 = (sjt_dot212)->m10;
    sjt_dot213 = v;
    sjt_math194 = (sjt_dot213)->y;
    sjt_math190 = sjt_math193 * sjt_math194;
    sjt_math187 = sjt_math189 + sjt_math190;
    sjt_dot214 = _parent;
    sjt_math195 = (sjt_dot214)->m20;
    sjt_dot215 = v;
    sjt_math196 = (sjt_dot215)->z;
    sjt_math188 = sjt_math195 * sjt_math196;
    sjt_math185 = sjt_math187 + sjt_math188;
    sjt_dot216 = _parent;
    sjt_math197 = (sjt_dot216)->m30;
    sjt_dot217 = v;
    sjt_math198 = (sjt_dot217)->w;
    sjt_math186 = sjt_math197 * sjt_math198;
    _return->x = sjt_math185 + sjt_math186;
    sjt_dot218 = _parent;
    sjt_math205 = (sjt_dot218)->m01;
    sjt_dot219 = v;
    sjt_math206 = (sjt_dot219)->x;
    sjt_math203 = sjt_math205 * sjt_math206;
    sjt_dot220 = _parent;
    sjt_math207 = (sjt_dot220)->m11;
    sjt_dot221 = v;
    sjt_math208 = (sjt_dot221)->y;
    sjt_math204 = sjt_math207 * sjt_math208;
    sjt_math201 = sjt_math203 + sjt_math204;
    sjt_dot222 = _parent;
    sjt_math209 = (sjt_dot222)->m21;
    sjt_dot223 = v;
    sjt_math210 = (sjt_dot223)->z;
    sjt_math202 = sjt_math209 * sjt_math210;
    sjt_math199 = sjt_math201 + sjt_math202;
    sjt_dot224 = _parent;
    sjt_math211 = (sjt_dot224)->m31;
    sjt_dot225 = v;
    sjt_math212 = (sjt_dot225)->w;
    sjt_math200 = sjt_math211 * sjt_math212;
    _return->y = sjt_math199 + sjt_math200;
    sjt_dot226 = _parent;
    sjt_math219 = (sjt_dot226)->m02;
    sjt_dot227 = v;
    sjt_math220 = (sjt_dot227)->x;
    sjt_math217 = sjt_math219 * sjt_math220;
    sjt_dot228 = _parent;
    sjt_math221 = (sjt_dot228)->m12;
    sjt_dot229 = v;
    sjt_math222 = (sjt_dot229)->y;
    sjt_math218 = sjt_math221 * sjt_math222;
    sjt_math215 = sjt_math217 + sjt_math218;
    sjt_dot230 = _parent;
    sjt_math223 = (sjt_dot230)->m22;
    sjt_dot231 = v;
    sjt_math224 = (sjt_dot231)->z;
    sjt_math216 = sjt_math223 * sjt_math224;
    sjt_math213 = sjt_math215 + sjt_math216;
    sjt_dot232 = _parent;
    sjt_math225 = (sjt_dot232)->m32;
    sjt_dot233 = v;
    sjt_math226 = (sjt_dot233)->w;
    sjt_math214 = sjt_math225 * sjt_math226;
    _return->z = sjt_math213 + sjt_math214;
    sjt_dot234 = _parent;
    sjt_math233 = (sjt_dot234)->m03;
    sjt_dot235 = v;
    sjt_math234 = (sjt_dot235)->x;
    sjt_math231 = sjt_math233 * sjt_math234;
    sjt_dot236 = _parent;
    sjt_math235 = (sjt_dot236)->m13;
    sjt_dot237 = v;
    sjt_math236 = (sjt_dot237)->y;
    sjt_math232 = sjt_math235 * sjt_math236;
    sjt_math229 = sjt_math231 + sjt_math232;
    sjt_dot238 = _parent;
    sjt_math237 = (sjt_dot238)->m23;
    sjt_dot239 = v;
    sjt_math238 = (sjt_dot239)->z;
    sjt_math230 = sjt_math237 * sjt_math238;
    sjt_math227 = sjt_math229 + sjt_math230;
    sjt_dot240 = _parent;
    sjt_math239 = (sjt_dot240)->m33;
    sjt_dot241 = v;
    sjt_math240 = (sjt_dot241)->w;
    sjt_math228 = sjt_math239 * sjt_math240;
    _return->w = sjt_math227 + sjt_math228;
    sjf_vec4(_return);
}

void sjf_mat4_multiplyvec4_heap(sjs_mat4* _parent, sjs_vec4* v, sjs_vec4** _return) {
    sjs_mat4* sjt_dot242 = 0;
    sjs_vec4* sjt_dot243 = 0;
    sjs_mat4* sjt_dot244 = 0;
    sjs_vec4* sjt_dot245 = 0;
    sjs_mat4* sjt_dot246 = 0;
    sjs_vec4* sjt_dot247 = 0;
    sjs_mat4* sjt_dot248 = 0;
    sjs_vec4* sjt_dot249 = 0;
    sjs_mat4* sjt_dot250 = 0;
    sjs_vec4* sjt_dot251 = 0;
    sjs_mat4* sjt_dot252 = 0;
    sjs_vec4* sjt_dot253 = 0;
    sjs_mat4* sjt_dot254 = 0;
    sjs_vec4* sjt_dot255 = 0;
    sjs_mat4* sjt_dot256 = 0;
    sjs_vec4* sjt_dot257 = 0;
    sjs_mat4* sjt_dot258 = 0;
    sjs_vec4* sjt_dot259 = 0;
    sjs_mat4* sjt_dot260 = 0;
    sjs_vec4* sjt_dot261 = 0;
    sjs_mat4* sjt_dot262 = 0;
    sjs_vec4* sjt_dot263 = 0;
    sjs_mat4* sjt_dot264 = 0;
    sjs_vec4* sjt_dot265 = 0;
    sjs_mat4* sjt_dot266 = 0;
    sjs_vec4* sjt_dot267 = 0;
    sjs_mat4* sjt_dot268 = 0;
    sjs_vec4* sjt_dot269 = 0;
    sjs_mat4* sjt_dot270 = 0;
    sjs_vec4* sjt_dot271 = 0;
    sjs_mat4* sjt_dot272 = 0;
    sjs_vec4* sjt_dot273 = 0;
    float sjt_math241;
    float sjt_math242;
    float sjt_math243;
    float sjt_math244;
    float sjt_math245;
    float sjt_math246;
    float sjt_math247;
    float sjt_math248;
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
    float sjt_math259;
    float sjt_math260;
    float sjt_math261;
    float sjt_math262;
    float sjt_math263;
    float sjt_math264;
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

    (*_return) = (sjs_vec4*)malloc(sizeof(sjs_vec4));
    (*_return)->_refCount = 1;
    sjt_dot242 = _parent;
    sjt_math247 = (sjt_dot242)->m00;
    sjt_dot243 = v;
    sjt_math248 = (sjt_dot243)->x;
    sjt_math245 = sjt_math247 * sjt_math248;
    sjt_dot244 = _parent;
    sjt_math249 = (sjt_dot244)->m10;
    sjt_dot245 = v;
    sjt_math250 = (sjt_dot245)->y;
    sjt_math246 = sjt_math249 * sjt_math250;
    sjt_math243 = sjt_math245 + sjt_math246;
    sjt_dot246 = _parent;
    sjt_math251 = (sjt_dot246)->m20;
    sjt_dot247 = v;
    sjt_math252 = (sjt_dot247)->z;
    sjt_math244 = sjt_math251 * sjt_math252;
    sjt_math241 = sjt_math243 + sjt_math244;
    sjt_dot248 = _parent;
    sjt_math253 = (sjt_dot248)->m30;
    sjt_dot249 = v;
    sjt_math254 = (sjt_dot249)->w;
    sjt_math242 = sjt_math253 * sjt_math254;
    (*_return)->x = sjt_math241 + sjt_math242;
    sjt_dot250 = _parent;
    sjt_math261 = (sjt_dot250)->m01;
    sjt_dot251 = v;
    sjt_math262 = (sjt_dot251)->x;
    sjt_math259 = sjt_math261 * sjt_math262;
    sjt_dot252 = _parent;
    sjt_math263 = (sjt_dot252)->m11;
    sjt_dot253 = v;
    sjt_math264 = (sjt_dot253)->y;
    sjt_math260 = sjt_math263 * sjt_math264;
    sjt_math257 = sjt_math259 + sjt_math260;
    sjt_dot254 = _parent;
    sjt_math265 = (sjt_dot254)->m21;
    sjt_dot255 = v;
    sjt_math266 = (sjt_dot255)->z;
    sjt_math258 = sjt_math265 * sjt_math266;
    sjt_math255 = sjt_math257 + sjt_math258;
    sjt_dot256 = _parent;
    sjt_math267 = (sjt_dot256)->m31;
    sjt_dot257 = v;
    sjt_math268 = (sjt_dot257)->w;
    sjt_math256 = sjt_math267 * sjt_math268;
    (*_return)->y = sjt_math255 + sjt_math256;
    sjt_dot258 = _parent;
    sjt_math275 = (sjt_dot258)->m02;
    sjt_dot259 = v;
    sjt_math276 = (sjt_dot259)->x;
    sjt_math273 = sjt_math275 * sjt_math276;
    sjt_dot260 = _parent;
    sjt_math277 = (sjt_dot260)->m12;
    sjt_dot261 = v;
    sjt_math278 = (sjt_dot261)->y;
    sjt_math274 = sjt_math277 * sjt_math278;
    sjt_math271 = sjt_math273 + sjt_math274;
    sjt_dot262 = _parent;
    sjt_math279 = (sjt_dot262)->m22;
    sjt_dot263 = v;
    sjt_math280 = (sjt_dot263)->z;
    sjt_math272 = sjt_math279 * sjt_math280;
    sjt_math269 = sjt_math271 + sjt_math272;
    sjt_dot264 = _parent;
    sjt_math281 = (sjt_dot264)->m32;
    sjt_dot265 = v;
    sjt_math282 = (sjt_dot265)->w;
    sjt_math270 = sjt_math281 * sjt_math282;
    (*_return)->z = sjt_math269 + sjt_math270;
    sjt_dot266 = _parent;
    sjt_math289 = (sjt_dot266)->m03;
    sjt_dot267 = v;
    sjt_math290 = (sjt_dot267)->x;
    sjt_math287 = sjt_math289 * sjt_math290;
    sjt_dot268 = _parent;
    sjt_math291 = (sjt_dot268)->m13;
    sjt_dot269 = v;
    sjt_math292 = (sjt_dot269)->y;
    sjt_math288 = sjt_math291 * sjt_math292;
    sjt_math285 = sjt_math287 + sjt_math288;
    sjt_dot270 = _parent;
    sjt_math293 = (sjt_dot270)->m23;
    sjt_dot271 = v;
    sjt_math294 = (sjt_dot271)->z;
    sjt_math286 = sjt_math293 * sjt_math294;
    sjt_math283 = sjt_math285 + sjt_math286;
    sjt_dot272 = _parent;
    sjt_math295 = (sjt_dot272)->m33;
    sjt_dot273 = v;
    sjt_math296 = (sjt_dot273)->w;
    sjt_math284 = sjt_math295 * sjt_math296;
    (*_return)->w = sjt_math283 + sjt_math284;
    sjf_vec4_heap((*_return));
}

void sjf_mat4_orthographic(float left, float right, float bottom, float top, float znear, float zfar, sjs_mat4* _return) {
    float result20;
    float sjt_math2217;
    float sjt_math2218;
    float sjt_math2219;
    float sjt_math2220;
    float sjt_math2221;
    float sjt_math2222;
    float sjt_math2223;
    float sjt_math2224;
    float sjt_math2225;
    float sjt_math2226;
    float sjt_math2227;
    float sjt_math2228;
    float sjt_math2229;
    float sjt_math2230;
    float sjt_math2231;
    float sjt_math2232;
    float sjt_math2233;
    float sjt_math2234;
    float sjt_math2235;
    float sjt_math2236;
    float sjt_math2237;
    float sjt_math2238;
    float sjt_math2239;
    float sjt_math2240;
    float sjt_math2241;
    float sjt_math2242;
    float sjt_math2243;
    float sjt_math2244;
    float sjt_math2245;
    float sjt_math2246;
    float sjt_math2247;
    float sjt_math2248;
    float sjt_math2249;
    float sjt_math2250;
    float sjt_math2251;
    float sjt_math2252;
    float sjt_negate17;

    _return->_refCount = 1;
    sjt_math2217 = 2.0f;
    sjt_math2219 = right;
    sjt_math2220 = left;
    sjt_math2218 = sjt_math2219 - sjt_math2220;
    _return->m00 = sjt_math2217 / sjt_math2218;
    _return->m01 = 0.0f;
    _return->m02 = 0.0f;
    _return->m03 = 0.0f;
    _return->m10 = 0.0f;
    sjt_math2221 = 2.0f;
    sjt_math2223 = top;
    sjt_math2224 = bottom;
    sjt_math2222 = sjt_math2223 - sjt_math2224;
    _return->m11 = sjt_math2221 / sjt_math2222;
    _return->m12 = 0.0f;
    _return->m13 = 0.0f;
    _return->m20 = 0.0f;
    _return->m21 = 0.0f;
    sjt_negate17 = 2.0f;
    result20 = -sjt_negate17;
    sjt_math2225 = result20;
    sjt_math2227 = zfar;
    sjt_math2228 = znear;
    sjt_math2226 = sjt_math2227 - sjt_math2228;
    _return->m22 = sjt_math2225 / sjt_math2226;
    _return->m23 = 0.0f;
    sjt_math2229 = 0.0f;
    sjt_math2233 = right;
    sjt_math2234 = left;
    sjt_math2231 = sjt_math2233 + sjt_math2234;
    sjt_math2235 = right;
    sjt_math2236 = left;
    sjt_math2232 = sjt_math2235 - sjt_math2236;
    sjt_math2230 = sjt_math2231 / sjt_math2232;
    _return->m30 = sjt_math2229 - sjt_math2230;
    sjt_math2237 = 0.0f;
    sjt_math2241 = top;
    sjt_math2242 = bottom;
    sjt_math2239 = sjt_math2241 + sjt_math2242;
    sjt_math2243 = top;
    sjt_math2244 = bottom;
    sjt_math2240 = sjt_math2243 - sjt_math2244;
    sjt_math2238 = sjt_math2239 / sjt_math2240;
    _return->m31 = sjt_math2237 - sjt_math2238;
    sjt_math2245 = 0.0f;
    sjt_math2249 = zfar;
    sjt_math2250 = znear;
    sjt_math2247 = sjt_math2249 + sjt_math2250;
    sjt_math2251 = zfar;
    sjt_math2252 = znear;
    sjt_math2248 = sjt_math2251 - sjt_math2252;
    sjt_math2246 = sjt_math2247 / sjt_math2248;
    _return->m32 = sjt_math2245 - sjt_math2246;
    _return->m33 = 1.0f;
    sjf_mat4(_return);
}

void sjf_mat4_orthographic_heap(float left, float right, float bottom, float top, float znear, float zfar, sjs_mat4** _return) {
    float result21;
    float sjt_math2253;
    float sjt_math2254;
    float sjt_math2255;
    float sjt_math2256;
    float sjt_math2257;
    float sjt_math2258;
    float sjt_math2259;
    float sjt_math2260;
    float sjt_math2261;
    float sjt_math2262;
    float sjt_math2263;
    float sjt_math2264;
    float sjt_math2265;
    float sjt_math2266;
    float sjt_math2267;
    float sjt_math2268;
    float sjt_math2269;
    float sjt_math2270;
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
    float sjt_math2283;
    float sjt_math2284;
    float sjt_math2285;
    float sjt_math2286;
    float sjt_math2287;
    float sjt_math2288;
    float sjt_negate18;

    (*_return) = (sjs_mat4*)malloc(sizeof(sjs_mat4));
    (*_return)->_refCount = 1;
    sjt_math2253 = 2.0f;
    sjt_math2255 = right;
    sjt_math2256 = left;
    sjt_math2254 = sjt_math2255 - sjt_math2256;
    (*_return)->m00 = sjt_math2253 / sjt_math2254;
    (*_return)->m01 = 0.0f;
    (*_return)->m02 = 0.0f;
    (*_return)->m03 = 0.0f;
    (*_return)->m10 = 0.0f;
    sjt_math2257 = 2.0f;
    sjt_math2259 = top;
    sjt_math2260 = bottom;
    sjt_math2258 = sjt_math2259 - sjt_math2260;
    (*_return)->m11 = sjt_math2257 / sjt_math2258;
    (*_return)->m12 = 0.0f;
    (*_return)->m13 = 0.0f;
    (*_return)->m20 = 0.0f;
    (*_return)->m21 = 0.0f;
    sjt_negate18 = 2.0f;
    result21 = -sjt_negate18;
    sjt_math2261 = result21;
    sjt_math2263 = zfar;
    sjt_math2264 = znear;
    sjt_math2262 = sjt_math2263 - sjt_math2264;
    (*_return)->m22 = sjt_math2261 / sjt_math2262;
    (*_return)->m23 = 0.0f;
    sjt_math2265 = 0.0f;
    sjt_math2269 = right;
    sjt_math2270 = left;
    sjt_math2267 = sjt_math2269 + sjt_math2270;
    sjt_math2271 = right;
    sjt_math2272 = left;
    sjt_math2268 = sjt_math2271 - sjt_math2272;
    sjt_math2266 = sjt_math2267 / sjt_math2268;
    (*_return)->m30 = sjt_math2265 - sjt_math2266;
    sjt_math2273 = 0.0f;
    sjt_math2277 = top;
    sjt_math2278 = bottom;
    sjt_math2275 = sjt_math2277 + sjt_math2278;
    sjt_math2279 = top;
    sjt_math2280 = bottom;
    sjt_math2276 = sjt_math2279 - sjt_math2280;
    sjt_math2274 = sjt_math2275 / sjt_math2276;
    (*_return)->m31 = sjt_math2273 - sjt_math2274;
    sjt_math2281 = 0.0f;
    sjt_math2285 = zfar;
    sjt_math2286 = znear;
    sjt_math2283 = sjt_math2285 + sjt_math2286;
    sjt_math2287 = zfar;
    sjt_math2288 = znear;
    sjt_math2284 = sjt_math2287 - sjt_math2288;
    sjt_math2282 = sjt_math2283 / sjt_math2284;
    (*_return)->m32 = sjt_math2281 - sjt_math2282;
    (*_return)->m33 = 1.0f;
    sjf_mat4_heap((*_return));
}

void sjf_mat4_perspective(float fovy, float aspect, float znear, float zfar, sjs_mat4* _return) {
    float sjt_functionParam8;
    float sjt_math10;
    float sjt_math11;
    float sjt_math12;
    float sjt_math13;
    float sjt_math14;
    float sjt_math15;
    float sjt_math16;
    float sjt_math17;
    float sjt_math18;
    float sjt_math19;
    float sjt_math20;
    float sjt_math21;
    float sjt_math22;
    float sjt_math3;
    float sjt_math4;
    float sjt_math5;
    float sjt_math6;
    float sjt_math7;
    float sjt_math8;
    float sjt_math9;
    float sjv_xscale;
    float sjv_yscale;

    sjt_math3 = 1.0f;
    sjt_math7 = fovy;
    sjt_math8 = 180.0f;
    sjt_math5 = sjt_math7 / sjt_math8;
    sjt_math6 = 2.0f;
    sjt_functionParam8 = sjt_math5 / sjt_math6;
    sjf_f32_tan(sjt_functionParam8, &sjt_math4);
    sjv_yscale = sjt_math3 / sjt_math4;
    sjt_math9 = sjv_yscale;
    sjt_math10 = aspect;
    sjv_xscale = sjt_math9 * sjt_math10;
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
    sjt_math11 = zfar;
    sjt_math13 = zfar;
    sjt_math14 = znear;
    sjt_math12 = sjt_math13 - sjt_math14;
    _return->m22 = sjt_math11 / sjt_math12;
    _return->m23 = 1.0f;
    _return->m30 = 0.0f;
    _return->m31 = 0.0f;
    sjt_math15 = 0.0f;
    sjt_math19 = znear;
    sjt_math20 = zfar;
    sjt_math17 = sjt_math19 * sjt_math20;
    sjt_math21 = zfar;
    sjt_math22 = znear;
    sjt_math18 = sjt_math21 - sjt_math22;
    sjt_math16 = sjt_math17 / sjt_math18;
    _return->m32 = sjt_math15 - sjt_math16;
    _return->m33 = 0.0f;
    sjf_mat4(_return);
}

void sjf_mat4_perspective_heap(float fovy, float aspect, float znear, float zfar, sjs_mat4** _return) {
    float sjt_functionParam9;
    float sjt_math23;
    float sjt_math24;
    float sjt_math25;
    float sjt_math26;
    float sjt_math27;
    float sjt_math28;
    float sjt_math29;
    float sjt_math30;
    float sjt_math31;
    float sjt_math32;
    float sjt_math33;
    float sjt_math34;
    float sjt_math35;
    float sjt_math36;
    float sjt_math37;
    float sjt_math38;
    float sjt_math39;
    float sjt_math40;
    float sjt_math41;
    float sjt_math42;
    float sjv_xscale;
    float sjv_yscale;

    sjt_math23 = 1.0f;
    sjt_math27 = fovy;
    sjt_math28 = 180.0f;
    sjt_math25 = sjt_math27 / sjt_math28;
    sjt_math26 = 2.0f;
    sjt_functionParam9 = sjt_math25 / sjt_math26;
    sjf_f32_tan(sjt_functionParam9, &sjt_math24);
    sjv_yscale = sjt_math23 / sjt_math24;
    sjt_math29 = sjv_yscale;
    sjt_math30 = aspect;
    sjv_xscale = sjt_math29 * sjt_math30;
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
    sjt_math31 = zfar;
    sjt_math33 = zfar;
    sjt_math34 = znear;
    sjt_math32 = sjt_math33 - sjt_math34;
    (*_return)->m22 = sjt_math31 / sjt_math32;
    (*_return)->m23 = 1.0f;
    (*_return)->m30 = 0.0f;
    (*_return)->m31 = 0.0f;
    sjt_math35 = 0.0f;
    sjt_math39 = znear;
    sjt_math40 = zfar;
    sjt_math37 = sjt_math39 * sjt_math40;
    sjt_math41 = zfar;
    sjt_math42 = znear;
    sjt_math38 = sjt_math41 - sjt_math42;
    sjt_math36 = sjt_math37 / sjt_math38;
    (*_return)->m32 = sjt_math35 - sjt_math36;
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

void sjf_mat4_translate(float x, float y, float z, sjs_mat4* _return) {
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
    _return->m30 = x;
    _return->m31 = y;
    _return->m32 = z;
    _return->m33 = 1.0f;
    sjf_mat4(_return);
}

void sjf_mat4_translate_heap(float x, float y, float z, sjs_mat4** _return) {
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
    (*_return)->m30 = x;
    (*_return)->m31 = y;
    (*_return)->m32 = z;
    (*_return)->m33 = 1.0f;
    sjf_mat4_heap((*_return));
}

void sjf_mat4_transpose(sjs_mat4* _parent, sjs_mat4* _return) {
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

    _return->_refCount = 1;
    sjt_dot566 = _parent;
    _return->m00 = (sjt_dot566)->m00;
    sjt_dot567 = _parent;
    _return->m01 = (sjt_dot567)->m10;
    sjt_dot568 = _parent;
    _return->m02 = (sjt_dot568)->m20;
    sjt_dot569 = _parent;
    _return->m03 = (sjt_dot569)->m30;
    sjt_dot570 = _parent;
    _return->m10 = (sjt_dot570)->m01;
    sjt_dot571 = _parent;
    _return->m11 = (sjt_dot571)->m11;
    sjt_dot572 = _parent;
    _return->m12 = (sjt_dot572)->m21;
    sjt_dot573 = _parent;
    _return->m13 = (sjt_dot573)->m31;
    sjt_dot574 = _parent;
    _return->m20 = (sjt_dot574)->m02;
    sjt_dot575 = _parent;
    _return->m21 = (sjt_dot575)->m12;
    sjt_dot576 = _parent;
    _return->m22 = (sjt_dot576)->m22;
    sjt_dot577 = _parent;
    _return->m23 = (sjt_dot577)->m32;
    sjt_dot578 = _parent;
    _return->m30 = (sjt_dot578)->m03;
    sjt_dot579 = _parent;
    _return->m31 = (sjt_dot579)->m13;
    sjt_dot580 = _parent;
    _return->m32 = (sjt_dot580)->m23;
    sjt_dot581 = _parent;
    _return->m33 = (sjt_dot581)->m33;
    sjf_mat4(_return);
}

void sjf_mat4_transpose_heap(sjs_mat4* _parent, sjs_mat4** _return) {
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

    (*_return) = (sjs_mat4*)malloc(sizeof(sjs_mat4));
    (*_return)->_refCount = 1;
    sjt_dot582 = _parent;
    (*_return)->m00 = (sjt_dot582)->m00;
    sjt_dot583 = _parent;
    (*_return)->m01 = (sjt_dot583)->m10;
    sjt_dot584 = _parent;
    (*_return)->m02 = (sjt_dot584)->m20;
    sjt_dot585 = _parent;
    (*_return)->m03 = (sjt_dot585)->m30;
    sjt_dot586 = _parent;
    (*_return)->m10 = (sjt_dot586)->m01;
    sjt_dot587 = _parent;
    (*_return)->m11 = (sjt_dot587)->m11;
    sjt_dot588 = _parent;
    (*_return)->m12 = (sjt_dot588)->m21;
    sjt_dot589 = _parent;
    (*_return)->m13 = (sjt_dot589)->m31;
    sjt_dot590 = _parent;
    (*_return)->m20 = (sjt_dot590)->m02;
    sjt_dot591 = _parent;
    (*_return)->m21 = (sjt_dot591)->m12;
    sjt_dot592 = _parent;
    (*_return)->m22 = (sjt_dot592)->m22;
    sjt_dot593 = _parent;
    (*_return)->m23 = (sjt_dot593)->m32;
    sjt_dot594 = _parent;
    (*_return)->m30 = (sjt_dot594)->m03;
    sjt_dot595 = _parent;
    (*_return)->m31 = (sjt_dot595)->m13;
    sjt_dot596 = _parent;
    (*_return)->m32 = (sjt_dot596)->m23;
    sjt_dot597 = _parent;
    (*_return)->m33 = (sjt_dot597)->m33;
    sjf_mat4_heap((*_return));
}

void sjf_model(sjs_model* _this) {
    int32_t sjt_compare43;
    int32_t sjt_compare44;
    sjs_string* sjt_dot206 = 0;
    bool sjt_ifElse12;

    sjt_dot206 = &_this->id;
    sjt_compare43 = (sjt_dot206)->count;
    sjt_compare44 = 0;
    sjt_ifElse12 = sjt_compare43 > sjt_compare44;
    if (sjt_ifElse12) {
        sjs_model* sjt_cast12 = 0;
        sjs_string* sjt_functionParam106 = 0;
        sji_model sjt_functionParam107 = { 0 };
        sjs_hash_string_weak_iface_model* sjt_parent43 = 0;

        sjt_parent43 = &sjv_modelsbyid;
        sjt_functionParam106 = &_this->id;
        sjt_cast12 = &_this;
        sjf_model_as_sji_model(sjt_cast12, &sjt_functionParam107);
        delete_cb weakptrcb11 = { &sjt_functionParam107._parent, weakptr_clear };
        if (sjt_functionParam107._parent != 0) { weakptr_cb_add(sjt_functionParam107._parent, weakptrcb11); }
        sjf_hash_string_weak_iface_model_setat(sjt_parent43, sjt_functionParam106, sjt_functionParam107);

        delete_cb weakptrcb13 = { &sjt_functionParam107._parent, weakptr_clear };
        if (sjt_functionParam107._parent != 0) { weakptr_cb_remove(sjt_functionParam107._parent, weakptrcb13); }
    }
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
    }

    _return->_parent = 0;
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
    sjf_string_copy(&_this->id, &_from->id);
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
}

void sjf_model_firemouseevent(sjs_model* _parent, sjs_mouseevent* mouseevent) {
}

void sjf_model_getz(sjs_model* _parent, float* _return) {
    sjs_vec3* sjt_dot547 = 0;
    sjs_model* sjt_dot548 = 0;

    sjt_dot548 = _parent;
    sjt_dot547 = &(sjt_dot548)->_projectedcenter;
    (*_return) = (sjt_dot547)->z;
}

void sjf_model_heap(sjs_model* _this) {
    int32_t sjt_compare49;
    int32_t sjt_compare50;
    sjs_string* sjt_dot1324 = 0;
    bool sjt_ifElse16;

    sjt_dot1324 = &_this->id;
    sjt_compare49 = (sjt_dot1324)->count;
    sjt_compare50 = 0;
    sjt_ifElse16 = sjt_compare49 > sjt_compare50;
    if (sjt_ifElse16) {
        sjs_model* sjt_cast14 = 0;
        sjs_string* sjt_functionParam148 = 0;
        sji_model sjt_functionParam149 = { 0 };
        sjs_hash_string_weak_iface_model* sjt_parent59 = 0;

        sjt_parent59 = &sjv_modelsbyid;
        sjt_functionParam148 = &_this->id;
        sjt_cast14 = _this;
        sjf_model_as_sji_model(sjt_cast14, &sjt_functionParam149);
        delete_cb weakptrcb12 = { &sjt_functionParam149._parent, weakptr_clear };
        if (sjt_functionParam149._parent != 0) { weakptr_cb_add(sjt_functionParam149._parent, weakptrcb12); }
        sjf_hash_string_weak_iface_model_setat(sjt_parent59, sjt_functionParam148, sjt_functionParam149);

        delete_cb weakptrcb14 = { &sjt_functionParam149._parent, weakptr_clear };
        if (sjt_functionParam149._parent != 0) { weakptr_cb_remove(sjt_functionParam149._parent, weakptrcb14); }
    }
}

void sjf_model_heap_as_sji_model(sjs_model* _this, sji_model* _return) {
    _return->_parent = (sjs_object*)_this;
    _return->_vtbl = &sjs_model_model_vtbl;
}

void sjf_model_heap_asinterface(sjs_model* _this, int typeId, sjs_interface* _return) {
    switch (typeId) {
        case sji_model_typeId:  {
            sjf_model_heap_as_sji_model(_this, (sji_model*)_return);
            break;
        }
    }

    _return->_parent = 0;
}

void sjf_model_render(sjs_model* _parent) {
    sjs_mat4 sjt_call17 = { -1 };
    sjs_string sjt_call18 = { -1 };
    sjs_string sjt_call19 = { -1 };
    sjs_string sjt_call20 = { -1 };
    sjs_string sjt_call21 = { -1 };
    sjs_string sjt_call22 = { -1 };
    sjs_vec3 sjt_call23 = { -1 };
    sjs_string sjt_call24 = { -1 };
    sjs_vec3 sjt_call25 = { -1 };
    sjs_model* sjt_dot1302 = 0;
    sjs_model* sjt_dot1303 = 0;
    sjs_model* sjt_dot1304 = 0;
    sjs_model* sjt_dot1305 = 0;
    sjs_model* sjt_dot1306 = 0;
    sjs_model* sjt_dot1307 = 0;
    sjs_model* sjt_dot1308 = 0;
    sjs_light* sjt_dot1309 = 0;
    sjs_model* sjt_dot1310 = 0;
    sjs_model* sjt_dot1311 = 0;
    sjs_light* sjt_dot1318 = 0;
    sjs_model* sjt_dot1319 = 0;
    sjs_model* sjt_dot1320 = 0;
    sjs_light* sjt_dot1321 = 0;
    sjs_model* sjt_dot1322 = 0;
    sjs_model* sjt_dot1323 = 0;
    sjs_model* sjt_dot563 = 0;
    sjs_model* sjt_dot564 = 0;
    sjs_model* sjt_dot565 = 0;
    sjs_mat4* sjt_functionParam117 = 0;
    sjs_mat4* sjt_functionParam118 = 0;
    sjs_shader* sjt_functionParam121 = 0;
    int32_t sjt_functionParam122;
    sjs_texture* sjt_functionParam123 = 0;
    int32_t sjt_functionParam124;
    sjs_shader* sjt_functionParam125 = 0;
    sjs_string* sjt_functionParam126 = 0;
    sjs_mat4* sjt_functionParam127 = 0;
    int32_t sjt_functionParam128;
    sjs_shader* sjt_functionParam129 = 0;
    sjs_string* sjt_functionParam130 = 0;
    sjs_mat4* sjt_functionParam131 = 0;
    int32_t sjt_functionParam132;
    sjs_shader* sjt_functionParam133 = 0;
    sjs_string* sjt_functionParam134 = 0;
    sjs_mat4* sjt_functionParam135 = 0;
    int32_t sjt_functionParam136;
    sjs_shader* sjt_functionParam137 = 0;
    sjs_string* sjt_functionParam138 = 0;
    sjs_vec3* sjt_functionParam139 = 0;
    int32_t sjt_functionParam140;
    sjs_shader* sjt_functionParam141 = 0;
    sjs_string* sjt_functionParam142 = 0;
    sjs_vec3* sjt_functionParam143 = 0;
    int32_t sjt_functionParam144;
    sjs_shader* sjt_functionParam145 = 0;
    sjs_string* sjt_functionParam146 = 0;
    sjs_vec3* sjt_functionParam147 = 0;
    sjs_mat4* sjt_parent50 = 0;
    sjs_mat4* sjt_parent51 = 0;
    sjs_mat4* sjt_parent52 = 0;
    sjs_mat4* sjt_parent55 = 0;
    sjs_color* sjt_parent56 = 0;
    sjs_color* sjt_parent57 = 0;
    sjs_vertexbuffer_vertex_location_texture_normal* sjt_parent58 = 0;
    sjs_mat4 sjv_normalmat = { -1 };
    sjs_mat4 sjv_viewworld = { -1 };
    sjs_mat4 sjv_world = { -1 };

    sjt_dot563 = _parent;
    sjt_parent50 = &(sjt_dot563)->_world;
    sjt_dot564 = _parent;
    sjt_functionParam117 = &(sjt_dot564)->model;
    sjf_mat4_multiply(sjt_parent50, sjt_functionParam117, &sjv_world);
    sjt_dot565 = _parent;
    sjt_parent51 = &(sjt_dot565)->_view;
    sjt_functionParam118 = &sjv_world;
    sjf_mat4_multiply(sjt_parent51, sjt_functionParam118, &sjv_viewworld);
    sjt_parent55 = &sjv_viewworld;
    sjf_mat4_invert(sjt_parent55, &sjt_call17);
    sjt_parent52 = &sjt_call17;
    sjf_mat4_transpose(sjt_parent52, &sjv_normalmat);
    sjt_dot1302 = _parent;
    sjt_functionParam121 = &(sjt_dot1302)->shader;
    sjf_gluseprogram(sjt_functionParam121);
    sjt_functionParam122 = sjv_gltexture_gl_texture_2d;
    sjt_dot1303 = _parent;
    sjt_functionParam123 = &(sjt_dot1303)->texture;
    sjf_glbindtexture(sjt_functionParam122, sjt_functionParam123);
    sjt_dot1304 = _parent;
    sjt_functionParam125 = &(sjt_dot1304)->shader;
    sjt_call18._refCount = 1;
    sjt_call18.count = 9;
    sjt_call18.data._refCount = 1;
    sjt_call18.data.datasize = 10;
    sjt_call18.data.data = (void*)sjg_string101;
    sjt_call18.data._isglobal = true;
    sjt_call18.data.count = 10;
    sjf_array_char(&sjt_call18.data);
    sjf_string(&sjt_call18);
    sjt_functionParam126 = &sjt_call18;
    sjf_glgetuniformlocation(sjt_functionParam125, sjt_functionParam126, &sjt_functionParam124);
    sjt_functionParam127 = &sjv_viewworld;
    sjf_gluniformmat4(sjt_functionParam124, sjt_functionParam127);
    sjt_dot1305 = _parent;
    sjt_functionParam129 = &(sjt_dot1305)->shader;
    sjt_call19._refCount = 1;
    sjt_call19.count = 9;
    sjt_call19.data._refCount = 1;
    sjt_call19.data.datasize = 10;
    sjt_call19.data.data = (void*)sjg_string102;
    sjt_call19.data._isglobal = true;
    sjt_call19.data.count = 10;
    sjf_array_char(&sjt_call19.data);
    sjf_string(&sjt_call19);
    sjt_functionParam130 = &sjt_call19;
    sjf_glgetuniformlocation(sjt_functionParam129, sjt_functionParam130, &sjt_functionParam128);
    sjt_functionParam131 = &sjv_normalmat;
    sjf_gluniformmat4(sjt_functionParam128, sjt_functionParam131);
    sjt_dot1306 = _parent;
    sjt_functionParam133 = &(sjt_dot1306)->shader;
    sjt_call20._refCount = 1;
    sjt_call20.count = 10;
    sjt_call20.data._refCount = 1;
    sjt_call20.data.datasize = 11;
    sjt_call20.data.data = (void*)sjg_string103;
    sjt_call20.data._isglobal = true;
    sjt_call20.data.count = 11;
    sjf_array_char(&sjt_call20.data);
    sjf_string(&sjt_call20);
    sjt_functionParam134 = &sjt_call20;
    sjf_glgetuniformlocation(sjt_functionParam133, sjt_functionParam134, &sjt_functionParam132);
    sjt_dot1307 = _parent;
    sjt_functionParam135 = &(sjt_dot1307)->_projection;
    sjf_gluniformmat4(sjt_functionParam132, sjt_functionParam135);
    sjt_dot1308 = _parent;
    sjt_functionParam137 = &(sjt_dot1308)->shader;
    sjt_call21._refCount = 1;
    sjt_call21.count = 8;
    sjt_call21.data._refCount = 1;
    sjt_call21.data.datasize = 9;
    sjt_call21.data.data = (void*)sjg_string104;
    sjt_call21.data._isglobal = true;
    sjt_call21.data.count = 9;
    sjf_array_char(&sjt_call21.data);
    sjf_string(&sjt_call21);
    sjt_functionParam138 = &sjt_call21;
    sjf_glgetuniformlocation(sjt_functionParam137, sjt_functionParam138, &sjt_functionParam136);
    sjt_dot1310 = _parent;
    sjt_dot1309 = &(sjt_dot1310)->_light;
    sjt_functionParam139 = &(sjt_dot1309)->pos;
    sjf_gluniformvec3(sjt_functionParam136, sjt_functionParam139);
    sjt_dot1311 = _parent;
    sjt_functionParam141 = &(sjt_dot1311)->shader;
    sjt_call22._refCount = 1;
    sjt_call22.count = 12;
    sjt_call22.data._refCount = 1;
    sjt_call22.data.datasize = 13;
    sjt_call22.data.data = (void*)sjg_string105;
    sjt_call22.data._isglobal = true;
    sjt_call22.data.count = 13;
    sjf_array_char(&sjt_call22.data);
    sjf_string(&sjt_call22);
    sjt_functionParam142 = &sjt_call22;
    sjf_glgetuniformlocation(sjt_functionParam141, sjt_functionParam142, &sjt_functionParam140);
    sjt_dot1319 = _parent;
    sjt_dot1318 = &(sjt_dot1319)->_light;
    sjt_parent56 = &(sjt_dot1318)->diffusecolor;
    sjf_color_asvec3(sjt_parent56, &sjt_call23);
    sjt_functionParam143 = &sjt_call23;
    sjf_gluniformvec3(sjt_functionParam140, sjt_functionParam143);
    sjt_dot1320 = _parent;
    sjt_functionParam145 = &(sjt_dot1320)->shader;
    sjt_call24._refCount = 1;
    sjt_call24.count = 9;
    sjt_call24.data._refCount = 1;
    sjt_call24.data.datasize = 10;
    sjt_call24.data.data = (void*)sjg_string106;
    sjt_call24.data._isglobal = true;
    sjt_call24.data.count = 10;
    sjf_array_char(&sjt_call24.data);
    sjf_string(&sjt_call24);
    sjt_functionParam146 = &sjt_call24;
    sjf_glgetuniformlocation(sjt_functionParam145, sjt_functionParam146, &sjt_functionParam144);
    sjt_dot1322 = _parent;
    sjt_dot1321 = &(sjt_dot1322)->_light;
    sjt_parent57 = &(sjt_dot1321)->speccolor;
    sjf_color_asvec3(sjt_parent57, &sjt_call25);
    sjt_functionParam147 = &sjt_call25;
    sjf_gluniformvec3(sjt_functionParam144, sjt_functionParam147);
    sjt_dot1323 = _parent;
    sjt_parent58 = &(sjt_dot1323)->vertexbuffer;
    sjf_vertexbuffer_vertex_location_texture_normal_render(sjt_parent58);

    if (sjt_call17._refCount == 1) { sjf_mat4_destroy(&sjt_call17); }
    if (sjt_call18._refCount == 1) { sjf_string_destroy(&sjt_call18); }
    if (sjt_call19._refCount == 1) { sjf_string_destroy(&sjt_call19); }
    if (sjt_call20._refCount == 1) { sjf_string_destroy(&sjt_call20); }
    if (sjt_call21._refCount == 1) { sjf_string_destroy(&sjt_call21); }
    if (sjt_call22._refCount == 1) { sjf_string_destroy(&sjt_call22); }
    if (sjt_call23._refCount == 1) { sjf_vec3_destroy(&sjt_call23); }
    if (sjt_call24._refCount == 1) { sjf_string_destroy(&sjt_call24); }
    if (sjt_call25._refCount == 1) { sjf_vec3_destroy(&sjt_call25); }
    if (sjv_normalmat._refCount == 1) { sjf_mat4_destroy(&sjv_normalmat); }
    if (sjv_viewworld._refCount == 1) { sjf_mat4_destroy(&sjv_viewworld); }
    if (sjv_world._refCount == 1) { sjf_mat4_destroy(&sjv_world); }
}

void sjf_model_renderorqueue(sjs_model* _parent, sjs_list_local_iface_model* zqueue) {
    sjs_model* sjt_dot549 = 0;
    bool sjt_ifElse13;

    sjt_dot549 = _parent;
    sjt_ifElse13 = (sjt_dot549)->hasalpha;
    if (sjt_ifElse13) {
        sjs_model* sjt_cast13 = 0;
        sji_model sjt_functionParam116 = { 0 };
        sjs_list_local_iface_model* sjt_parent49 = 0;

        sjt_parent49 = zqueue;
        sjt_cast13 = _parent;
        sjf_model_as_sji_model(sjt_cast13, &sjt_functionParam116);
        sjf_list_local_iface_model_add(sjt_parent49, sjt_functionParam116);
    } else {
        sjf_model_render(_parent);
    }
}

void sjf_model_update(sjs_model* _parent, sjs_rect* scenerect, sjs_mat4* projection, sjs_mat4* view, sjs_mat4* world, sjs_light* light) {
    sjs_mat4 sjt_call14 = { -1 };
    sjs_mat4 sjt_call15 = { -1 };
    sjs_vec4 sjt_call16 = { -1 };
    sjs_mat4* sjt_copy10 = 0;
    sjs_mat4* sjt_copy11 = 0;
    sjs_light* sjt_copy12 = 0;
    sjs_mat4* sjt_copy9 = 0;
    sjs_model* sjt_dot207 = 0;
    sjs_model* sjt_dot208 = 0;
    sjs_model* sjt_dot209 = 0;
    sjs_model* sjt_dot530 = 0;
    sjs_model* sjt_dot531 = 0;
    sjs_model* sjt_dot532 = 0;
    sjs_vec3* sjt_dot533 = 0;
    sjs_model* sjt_dot534 = 0;
    sjs_vec3* sjt_dot535 = 0;
    sjs_model* sjt_dot536 = 0;
    sjs_vec3* sjt_dot537 = 0;
    sjs_model* sjt_dot538 = 0;
    sjs_model* sjt_dot539 = 0;
    sjs_vec4* sjt_dot540 = 0;
    sjs_vec4* sjt_dot541 = 0;
    sjs_vec4* sjt_dot542 = 0;
    sjs_vec4* sjt_dot543 = 0;
    sjs_vec4* sjt_dot544 = 0;
    sjs_vec4* sjt_dot545 = 0;
    sjs_model* sjt_dot546 = 0;
    sjs_mat4* sjt_functionParam108 = 0;
    sjs_mat4* sjt_functionParam109 = 0;
    sjs_vec4* sjt_functionParam110 = 0;
    float sjt_math745;
    float sjt_math746;
    float sjt_math747;
    float sjt_math748;
    float sjt_math749;
    float sjt_math750;
    sjs_mat4* sjt_parent44 = 0;
    sjs_mat4* sjt_parent45 = 0;
    sjs_mat4* sjt_parent46 = 0;
    sjs_vec4 sjv_t2 = { -1 };

    sjt_dot207 = _parent;
    sjt_copy9 = projection;
    sjt_dot207->_projection._refCount = 1;
    sjf_mat4_copy(&sjt_dot207->_projection, sjt_copy9);
    sjt_dot208 = _parent;
    sjt_copy10 = view;
    sjt_dot208->_view._refCount = 1;
    sjf_mat4_copy(&sjt_dot208->_view, sjt_copy10);
    sjt_dot209 = _parent;
    sjt_copy11 = world;
    sjt_dot209->_world._refCount = 1;
    sjf_mat4_copy(&sjt_dot209->_world, sjt_copy11);
    sjt_dot530 = _parent;
    sjt_parent46 = &(sjt_dot530)->_view;
    sjt_dot531 = _parent;
    sjt_functionParam108 = &(sjt_dot531)->_world;
    sjf_mat4_multiply(sjt_parent46, sjt_functionParam108, &sjt_call15);
    sjt_parent45 = &sjt_call15;
    sjt_dot532 = _parent;
    sjt_functionParam109 = &(sjt_dot532)->model;
    sjf_mat4_multiply(sjt_parent45, sjt_functionParam109, &sjt_call14);
    sjt_parent44 = &sjt_call14;
    sjt_call16._refCount = 1;
    sjt_dot534 = _parent;
    sjt_dot533 = &(sjt_dot534)->center;
    sjt_call16.x = (sjt_dot533)->x;
    sjt_dot536 = _parent;
    sjt_dot535 = &(sjt_dot536)->center;
    sjt_call16.y = (sjt_dot535)->y;
    sjt_dot538 = _parent;
    sjt_dot537 = &(sjt_dot538)->center;
    sjt_call16.z = (sjt_dot537)->z;
    sjt_call16.w = 1.0f;
    sjf_vec4(&sjt_call16);
    sjt_functionParam110 = &sjt_call16;
    sjf_mat4_multiplyvec4(sjt_parent44, sjt_functionParam110, &sjv_t2);
    sjt_dot539 = _parent;
    sjt_dot539->_projectedcenter._refCount = 1;
    sjt_dot540 = &sjv_t2;
    sjt_math745 = (sjt_dot540)->x;
    sjt_dot541 = &sjv_t2;
    sjt_math746 = (sjt_dot541)->w;
    sjt_dot539->_projectedcenter.x = sjt_math745 / sjt_math746;
    sjt_dot542 = &sjv_t2;
    sjt_math747 = (sjt_dot542)->y;
    sjt_dot543 = &sjv_t2;
    sjt_math748 = (sjt_dot543)->w;
    sjt_dot539->_projectedcenter.y = sjt_math747 / sjt_math748;
    sjt_dot544 = &sjv_t2;
    sjt_math749 = (sjt_dot544)->z;
    sjt_dot545 = &sjv_t2;
    sjt_math750 = (sjt_dot545)->w;
    sjt_dot539->_projectedcenter.z = sjt_math749 / sjt_math750;
    sjf_vec3(&sjt_dot539->_projectedcenter);
    sjt_dot546 = _parent;
    sjt_copy12 = light;
    sjt_dot546->_light._refCount = 1;
    sjf_light_copy(&sjt_dot546->_light, sjt_copy12);

    if (sjt_call14._refCount == 1) { sjf_mat4_destroy(&sjt_call14); }
    if (sjt_call15._refCount == 1) { sjf_mat4_destroy(&sjt_call15); }
    if (sjt_call16._refCount == 1) { sjf_vec4_destroy(&sjt_call16); }
    if (sjv_t2._refCount == 1) { sjf_vec4_destroy(&sjv_t2); }
}

void sjf_model_zsort(sji_model l, sji_model r, int32_t* _return) {
    float sjt_functionParam47;
    float sjt_functionParam48;
    sji_model sjt_parent16 = { 0 };
    sji_model sjt_parent17 = { 0 };

    sjt_parent16 = l;
    sjt_parent16._vtbl->getz(sjt_parent16._parent, &sjt_functionParam47);
    sjt_parent17 = r;
    sjt_parent17._vtbl->getz(sjt_parent17._parent, &sjt_functionParam48);
    sjf_f32_compare(sjt_functionParam47, sjt_functionParam48, _return);
}

void sjf_model_zsort_callback(void * _parent, sji_model l, sji_model r, int32_t* _return) {
    sjf_model_zsort(l, r, _return);
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
        }
    }
}

void sjf_mouse_release(sji_element element) {
    sjs_string sjt_call11 = { -1 };
    sjs_string* sjt_functionParam100 = 0;
    bool sjt_isEmpty1;
    sji_element sjt_isEmpty2 = { 0 };

    sjt_call11._refCount = 1;
    sjt_call11.count = 7;
    sjt_call11.data._refCount = 1;
    sjt_call11.data.datasize = 8;
    sjt_call11.data.data = (void*)sjg_string97;
    sjt_call11.data._isglobal = true;
    sjt_call11.data.count = 8;
    sjf_array_char(&sjt_call11.data);
    sjf_string(&sjt_call11);
    sjt_functionParam100 = &sjt_call11;
    sjf_console_writeline(sjt_functionParam100);
    sjt_isEmpty2 = sjv_mouse_captureelement;
    sjt_isEmpty1 = (sjt_isEmpty2._parent != 0);
    if (sjt_isEmpty1) {
        sji_element ifValue5 = { 0 };
        sjs_string sjt_call12 = { -1 };
        sjs_string* sjt_functionParam101 = 0;

        ifValue5 = sjv_mouse_captureelement;
        if (ifValue5._parent != 0) {
            ifValue5._parent->_refCount++;
        }

        sjt_call12._refCount = 1;
        sjt_call12.count = 12;
        sjt_call12.data._refCount = 1;
        sjt_call12.data.datasize = 13;
        sjt_call12.data.data = (void*)sjg_string98;
        sjt_call12.data._isglobal = true;
        sjt_call12.data.count = 13;
        sjf_array_char(&sjt_call12.data);
        sjf_string(&sjt_call12);
        sjt_functionParam101 = &sjt_call12;
        sjf_console_writeline(sjt_functionParam101);
        sjv_mouse_captureelement._parent = 0;
        SDL_CaptureMouse(false);

        if (ifValue5._parent != 0) {
            ifValue5._parent->_refCount--;
            if (ifValue5._parent->_refCount <= 0) {
                ifValue5._vtbl->destroy(ifValue5._parent);
            }
        }
        if (sjt_call12._refCount == 1) { sjf_string_destroy(&sjt_call12); }
    }

    if (sjt_call11._refCount == 1) { sjf_string_destroy(&sjt_call11); }
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

void sjf_mouseevent_heap(sjs_mouseevent* _this) {
}

void sjf_nauscene3delement(sjs_nauscene3delement* _this) {
}

void sjf_nauscene3delement_as_sji_element(sjs_nauscene3delement* _this, sji_element* _return) {
    _return->_parent = (sjs_object*)_this;
    _return->_vtbl = &sjs_nauscene3delement_element_vtbl;
}

void sjf_nauscene3delement_asinterface(sjs_nauscene3delement* _this, int typeId, sjs_interface* _return) {
    switch (typeId) {
        case sji_element_typeId:  {
            sjf_nauscene3delement_as_sji_element(_this, (sji_element*)_return);
            break;
        }
    }

    _return->_parent = 0;
}

void sjf_nauscene3delement_copy(sjs_nauscene3delement* _this, sjs_nauscene3delement* _from) {
    _this->children._refCount = 1;
    sjf_array_heap_iface_model_copy(&_this->children, &_from->children);
    _this->lookatmin._refCount = 1;
    sjf_vec3_copy(&_this->lookatmin, &_from->lookatmin);
    _this->lookatmax._refCount = 1;
    sjf_vec3_copy(&_this->lookatmax, &_from->lookatmax);
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
    _this->_isdragging = _from->_isdragging;
    _this->_startdrag._refCount = 1;
    sjf_point_copy(&_this->_startdrag, &_from->_startdrag);
    _this->_lookat._refCount = 1;
    sjf_vec3_copy(&_this->_lookat, &_from->_lookat);
    _this->_lookatdrag._refCount = 1;
    sjf_vec3_copy(&_this->_lookatdrag, &_from->_lookatdrag);
}

void sjf_nauscene3delement_destroy(sjs_nauscene3delement* _this) {
}

void sjf_nauscene3delement_firemouseevent(sjs_nauscene3delement* _parent, sjs_mouseevent* mouseevent) {
    bool result4;
    int32_t sjt_compare33;
    int32_t sjt_compare34;
    sjs_mouseevent* sjt_dot202 = 0;
    sjs_mouseevent* sjt_dot61 = 0;
    bool sjt_ifElse11;
    bool sjt_not2;
    bool sjt_switch1;
    int32_t underscore1;

    sjt_dot61 = mouseevent;
    underscore1 = (sjt_dot61)->type;
    sjt_compare33 = underscore1;
    sjt_compare34 = sjv_mouseeventtype_down;
    sjt_switch1 = sjt_compare33 == sjt_compare34;
    if (sjt_switch1) {
        sjs_nauscene3delement* sjt_cast5 = 0;
        sjs_point* sjt_copy7 = 0;
        sjs_vec3* sjt_copy8 = 0;
        sjs_nauscene3delement* sjt_dot62 = 0;
        sjs_nauscene3delement* sjt_dot63 = 0;
        sjs_mouseevent* sjt_dot64 = 0;
        sjs_nauscene3delement* sjt_dot65 = 0;
        sjs_nauscene3delement* sjt_dot66 = 0;
        sji_element sjt_functionParam52 = { 0 };

        sjt_dot62 = _parent;
        sjt_dot62->_isdragging = true;
        sjt_dot63 = _parent;
        sjt_dot64 = mouseevent;
        sjt_copy7 = &(sjt_dot64)->point;
        sjt_dot63->_startdrag._refCount = 1;
        sjf_point_copy(&sjt_dot63->_startdrag, sjt_copy7);
        sjt_dot65 = _parent;
        sjt_dot66 = _parent;
        sjt_copy8 = &(sjt_dot66)->_lookat;
        sjt_dot65->_lookatdrag._refCount = 1;
        sjf_vec3_copy(&sjt_dot65->_lookatdrag, sjt_copy8);
        sjt_cast5 = _parent;
        sjf_nauscene3delement_as_sji_element(sjt_cast5, &sjt_functionParam52);
        if (sjt_functionParam52._parent != 0) {
            sjt_functionParam52._parent->_refCount++;
        }

        sjf_mouse_capture(sjt_functionParam52);

        if (sjt_functionParam52._parent != 0) {
            sjt_functionParam52._parent->_refCount--;
            if (sjt_functionParam52._parent->_refCount <= 0) {
                sjt_functionParam52._vtbl->destroy(sjt_functionParam52._parent);
            }
        }
    } else {
        int32_t sjt_compare35;
        int32_t sjt_compare36;
        bool sjt_switch2;

        sjt_compare35 = underscore1;
        sjt_compare36 = sjv_mouseeventtype_move;
        sjt_switch2 = sjt_compare35 == sjt_compare36;
        if (sjt_switch2) {
            sjs_vec3 sjt_call10 = { -1 };
            sjs_vec3 sjt_call4 = { -1 };
            sjs_vec3 sjt_call5 = { -1 };
            sjs_vec3 sjt_call6 = { -1 };
            sjs_vec3 sjt_call7 = { -1 };
            sjs_nauscene3delement* sjt_dot67 = 0;
            bool sjt_ifElse8;
            sjs_vec3 sjv_camera = { -1 };

            sjt_dot67 = _parent;
            sjt_ifElse8 = (sjt_dot67)->_isdragging;
            if (sjt_ifElse8) {
                int32_t sjt_cast6;
                int32_t sjt_cast7;
                int32_t sjt_cast8;
                int32_t sjt_cast9;
                sjs_nauscene3delement* sjt_dot107 = 0;
                sjs_point* sjt_dot108 = 0;
                sjs_nauscene3delement* sjt_dot109 = 0;
                sjs_point* sjt_dot110 = 0;
                sjs_mouseevent* sjt_dot111 = 0;
                sjs_rect* sjt_dot112 = 0;
                sjs_nauscene3delement* sjt_dot113 = 0;
                sjs_point* sjt_dot114 = 0;
                sjs_mouseevent* sjt_dot115 = 0;
                sjs_point* sjt_dot116 = 0;
                sjs_nauscene3delement* sjt_dot117 = 0;
                sjs_rect* sjt_dot118 = 0;
                sjs_nauscene3delement* sjt_dot119 = 0;
                sjs_nauscene3delement* sjt_dot132 = 0;
                sjs_nauscene3delement* sjt_dot133 = 0;
                sjs_nauscene3delement* sjt_dot200 = 0;
                sjs_nauscene3delement* sjt_dot68 = 0;
                sjs_nauscene3delement* sjt_dot81 = 0;
                sjs_nauscene3delement* sjt_dot94 = 0;
                sjs_vec3* sjt_functionParam65 = 0;
                sjs_vec3* sjt_functionParam66 = 0;
                sjs_vec3* sjt_functionParam79 = 0;
                sjs_vec3* sjt_functionParam80 = 0;
                sjs_vec3* sjt_functionParam81 = 0;
                sjs_vec3* sjt_functionParam82 = 0;
                sjs_vec3* sjt_functionParam97 = 0;
                sjs_vec3* sjt_functionParam98 = 0;
                sjs_vec3* sjt_functionParam99 = 0;
                float sjt_math71;
                float sjt_math72;
                float sjt_math73;
                float sjt_math74;
                int32_t sjt_math75;
                int32_t sjt_math76;
                float sjt_math77;
                float sjt_math78;
                float sjt_math79;
                float sjt_math80;
                int32_t sjt_math81;
                int32_t sjt_math82;
                sjs_vec3* sjt_parent22 = 0;
                sjs_vec3* sjt_parent23 = 0;

                sjt_dot68 = _parent;
                sjt_dot81 = _parent;
                sjt_functionParam65 = &(sjt_dot81)->lookatmax;
                sjt_dot94 = _parent;
                sjt_functionParam79 = &(sjt_dot94)->lookatmin;
                sjt_dot107 = _parent;
                sjt_parent22 = &(sjt_dot107)->_lookatdrag;
                sjt_call6._refCount = 1;
                sjt_dot109 = _parent;
                sjt_dot108 = &(sjt_dot109)->_startdrag;
                sjt_math75 = (sjt_dot108)->x;
                sjt_dot111 = mouseevent;
                sjt_dot110 = &(sjt_dot111)->point;
                sjt_math76 = (sjt_dot110)->x;
                sjt_cast6 = sjt_math75 - sjt_math76;
                sjt_math73 = (float)sjt_cast6;
                sjt_dot113 = _parent;
                sjt_dot112 = &(sjt_dot113)->_rect;
                sjt_cast7 = (sjt_dot112)->w;
                sjt_math74 = (float)sjt_cast7;
                sjt_math71 = sjt_math73 / sjt_math74;
                sjt_math72 = 2.0f;
                sjt_call6.x = sjt_math71 * sjt_math72;
                sjt_dot115 = mouseevent;
                sjt_dot114 = &(sjt_dot115)->point;
                sjt_math81 = (sjt_dot114)->y;
                sjt_dot117 = _parent;
                sjt_dot116 = &(sjt_dot117)->_startdrag;
                sjt_math82 = (sjt_dot116)->y;
                sjt_cast8 = sjt_math81 - sjt_math82;
                sjt_math79 = (float)sjt_cast8;
                sjt_dot119 = _parent;
                sjt_dot118 = &(sjt_dot119)->_rect;
                sjt_cast9 = (sjt_dot118)->h;
                sjt_math80 = (float)sjt_cast9;
                sjt_math77 = sjt_math79 / sjt_math80;
                sjt_math78 = 2.0f;
                sjt_call6.y = sjt_math77 * sjt_math78;
                sjt_call6.z = 0.0f;
                sjf_vec3(&sjt_call6);
                sjt_functionParam81 = &sjt_call6;
                sjf_vec3_add(sjt_parent22, sjt_functionParam81, &sjt_call5);
                sjt_functionParam80 = &sjt_call5;
                sjf_vec3_max(sjt_functionParam79, sjt_functionParam80, &sjt_call4);
                sjt_functionParam66 = &sjt_call4;
                sjf_vec3_min(sjt_functionParam65, sjt_functionParam66, &sjt_dot68->_lookat);
                sjt_dot132 = _parent;
                sjt_parent23 = &(sjt_dot132)->_lookat;
                sjt_call7._refCount = 1;
                sjt_call7.x = 0.0f;
                sjt_call7.y = 0.0f;
                sjt_call7.z = 5.0f;
                sjf_vec3(&sjt_call7);
                sjt_functionParam82 = &sjt_call7;
                sjf_vec3_subtract(sjt_parent23, sjt_functionParam82, &sjv_camera);
                sjt_dot133 = _parent;
                sjt_functionParam97 = &sjv_camera;
                sjt_dot200 = _parent;
                sjt_functionParam98 = &(sjt_dot200)->_lookat;
                sjt_call10._refCount = 1;
                sjt_call10.x = 0.0f;
                sjt_call10.y = 1.0f;
                sjt_call10.z = 0.0f;
                sjf_vec3(&sjt_call10);
                sjt_functionParam99 = &sjt_call10;
                sjf_mat4_lookatlh(sjt_functionParam97, sjt_functionParam98, sjt_functionParam99, &sjt_dot133->view);
            }

            if (sjt_call10._refCount == 1) { sjf_vec3_destroy(&sjt_call10); }
            if (sjt_call4._refCount == 1) { sjf_vec3_destroy(&sjt_call4); }
            if (sjt_call5._refCount == 1) { sjf_vec3_destroy(&sjt_call5); }
            if (sjt_call6._refCount == 1) { sjf_vec3_destroy(&sjt_call6); }
            if (sjt_call7._refCount == 1) { sjf_vec3_destroy(&sjt_call7); }
            if (sjv_camera._refCount == 1) { sjf_vec3_destroy(&sjv_camera); }
        } else {
            int32_t sjt_compare41;
            int32_t sjt_compare42;
            bool sjt_switch3;

            sjt_compare41 = underscore1;
            sjt_compare42 = sjv_mouseeventtype_up;
            sjt_switch3 = sjt_compare41 == sjt_compare42;
            if (sjt_switch3) {
                sjs_nauscene3delement* sjt_cast10 = 0;
                sjs_nauscene3delement* sjt_dot201 = 0;
                sji_element sjt_functionParam102 = { 0 };

                sjt_dot201 = _parent;
                sjt_dot201->_isdragging = false;
                sjt_cast10 = _parent;
                sjf_nauscene3delement_as_sji_element(sjt_cast10, &sjt_functionParam102);
                if (sjt_functionParam102._parent != 0) {
                    sjt_functionParam102._parent->_refCount++;
                }

                sjf_mouse_release(sjt_functionParam102);

                if (sjt_functionParam102._parent != 0) {
                    sjt_functionParam102._parent->_refCount--;
                    if (sjt_functionParam102._parent->_refCount <= 0) {
                        sjt_functionParam102._vtbl->destroy(sjt_functionParam102._parent);
                    }
                }
            }
        }
    }

    sjt_dot202 = mouseevent;
    sjt_not2 = (sjt_dot202)->iscaptured;
    result4 = !sjt_not2;
    sjt_ifElse11 = result4;
    if (sjt_ifElse11) {
        int32_t i;
        sjs_array_heap_iface_model* sjt_dot203 = 0;
        sjs_nauscene3delement* sjt_dot204 = 0;
        int32_t sjt_forEnd7;
        int32_t sjt_forStart7;

        sjt_forStart7 = 0;
        sjt_dot204 = _parent;
        sjt_dot203 = &(sjt_dot204)->children;
        sjt_forEnd7 = (sjt_dot203)->count;
        i = sjt_forStart7;
        while (i < sjt_forEnd7) {
            sjs_nauscene3delement* sjt_dot205 = 0;
            int32_t sjt_functionParam103;
            sjs_mouseevent* sjt_interfaceParam10 = 0;
            sjs_array_heap_iface_model* sjt_parent40 = 0;
            sji_model sjt_parent41 = { 0 };
            sji_model sjv_child = { 0 };

            sjt_dot205 = _parent;
            sjt_parent40 = &(sjt_dot205)->children;
            sjt_functionParam103 = i;
            sjf_array_heap_iface_model_getat_heap(sjt_parent40, sjt_functionParam103, &sjv_child);
            sjt_parent41 = sjv_child;
            sjt_interfaceParam10 = mouseevent;
            sjt_parent41._vtbl->firemouseevent(sjt_parent41._parent, sjt_interfaceParam10);
            i++;

            if (sjv_child._parent != 0) {
                sjv_child._parent->_refCount--;
                if (sjv_child._parent->_refCount <= 0) {
                    sjv_child._vtbl->destroy(sjv_child._parent);
                }
            }
        }
    }
}

void sjf_nauscene3delement_getrect(sjs_nauscene3delement* _parent, sjs_rect* _return) {
    sjs_rect* sjt_copy4 = 0;
    sjs_nauscene3delement* sjt_dot24 = 0;

    sjt_dot24 = _parent;
    sjt_copy4 = &(sjt_dot24)->_rect;
    _return->_refCount = 1;
    sjf_rect_copy(_return, sjt_copy4);
}

void sjf_nauscene3delement_getrect_heap(sjs_nauscene3delement* _parent, sjs_rect** _return) {
    sjs_rect* sjt_copy5 = 0;
    sjs_nauscene3delement* sjt_dot25 = 0;

    sjt_dot25 = _parent;
    sjt_copy5 = &(sjt_dot25)->_rect;
    (*_return) = (sjs_rect*)malloc(sizeof(sjs_rect));
    (*_return)->_refCount = 1;
    sjf_rect_copy((*_return), sjt_copy5);
}

void sjf_nauscene3delement_getsize(sjs_nauscene3delement* _parent, sjs_size* maxsize, sjs_size* _return) {
    sjs_size* sjt_dot20 = 0;
    sjs_size* sjt_dot21 = 0;

    _return->_refCount = 1;
    sjt_dot20 = maxsize;
    _return->w = (sjt_dot20)->w;
    sjt_dot21 = maxsize;
    _return->h = (sjt_dot21)->h;
    sjf_size(_return);
}

void sjf_nauscene3delement_getsize_heap(sjs_nauscene3delement* _parent, sjs_size* maxsize, sjs_size** _return) {
    sjs_size* sjt_dot22 = 0;
    sjs_size* sjt_dot23 = 0;

    (*_return) = (sjs_size*)malloc(sizeof(sjs_size));
    (*_return)->_refCount = 1;
    sjt_dot22 = maxsize;
    (*_return)->w = (sjt_dot22)->w;
    sjt_dot23 = maxsize;
    (*_return)->h = (sjt_dot23)->h;
    sjf_size_heap((*_return));
}

void sjf_nauscene3delement_heap(sjs_nauscene3delement* _this) {
}

void sjf_nauscene3delement_heap_as_sji_element(sjs_nauscene3delement* _this, sji_element* _return) {
    _return->_parent = (sjs_object*)_this;
    _return->_vtbl = &sjs_nauscene3delement_element_vtbl;
}

void sjf_nauscene3delement_heap_asinterface(sjs_nauscene3delement* _this, int typeId, sjs_interface* _return) {
    switch (typeId) {
        case sji_element_typeId:  {
            sjf_nauscene3delement_heap_as_sji_element(_this, (sji_element*)_return);
            break;
        }
    }

    _return->_parent = 0;
}

void sjf_nauscene3delement_render(sjs_nauscene3delement* _parent, sjs_scene2d* scene) {
    int32_t i;
    sjs_array_heap_iface_model* sjt_dot44 = 0;
    sjs_nauscene3delement* sjt_dot45 = 0;
    sjs_array_heap_iface_model* sjt_dot52 = 0;
    sjs_nauscene3delement* sjt_dot53 = 0;
    int32_t sjt_forEnd4;
    int32_t sjt_forEnd5;
    int32_t sjt_forEnd6;
    int32_t sjt_forStart4;
    int32_t sjt_forStart5;
    int32_t sjt_forStart6;
    int32_t sjt_functionParam15;
    cb_local_iface_model_local_iface_model_i32 sjt_functionParam46;
    int32_t sjt_functionParam51;
    sjs_list_local_iface_model* sjt_parent15 = 0;
    sjs_list_local_iface_model* sjt_parent18 = 0;
    sjs_list_local_iface_model sjv_a = { -1 };

    sjt_forStart4 = 0;
    sjt_dot45 = _parent;
    sjt_dot44 = &(sjt_dot45)->children;
    sjt_forEnd4 = (sjt_dot44)->count;
    i = sjt_forStart4;
    while (i < sjt_forEnd4) {
        sjs_nauscene3delement* sjt_dot46 = 0;
        sjs_nauscene3delement* sjt_dot47 = 0;
        sjs_nauscene3delement* sjt_dot48 = 0;
        sjs_nauscene3delement* sjt_dot49 = 0;
        sjs_nauscene3delement* sjt_dot50 = 0;
        sjs_nauscene3delement* sjt_dot51 = 0;
        int32_t sjt_functionParam14;
        sjs_rect* sjt_interfaceParam4 = 0;
        sjs_mat4* sjt_interfaceParam5 = 0;
        sjs_mat4* sjt_interfaceParam6 = 0;
        sjs_mat4* sjt_interfaceParam7 = 0;
        sjs_light* sjt_interfaceParam8 = 0;
        sjs_array_heap_iface_model* sjt_parent10 = 0;
        sji_model sjt_parent11 = { 0 };
        sji_model sjv_child = { 0 };

        sjt_dot46 = _parent;
        sjt_parent10 = &(sjt_dot46)->children;
        sjt_functionParam14 = i;
        sjf_array_heap_iface_model_getat_heap(sjt_parent10, sjt_functionParam14, &sjv_child);
        sjt_parent11 = sjv_child;
        sjt_dot47 = _parent;
        sjt_interfaceParam4 = &(sjt_dot47)->_rect;
        sjt_dot48 = _parent;
        sjt_interfaceParam5 = &(sjt_dot48)->projection;
        sjt_dot49 = _parent;
        sjt_interfaceParam6 = &(sjt_dot49)->view;
        sjt_dot50 = _parent;
        sjt_interfaceParam7 = &(sjt_dot50)->world;
        sjt_dot51 = _parent;
        sjt_interfaceParam8 = &(sjt_dot51)->light;
        sjt_parent11._vtbl->update(sjt_parent11._parent, sjt_interfaceParam4, sjt_interfaceParam5, sjt_interfaceParam6, sjt_interfaceParam7, sjt_interfaceParam8);
        i++;

        if (sjv_child._parent != 0) {
            sjv_child._parent->_refCount--;
            if (sjv_child._parent->_refCount <= 0) {
                sjv_child._vtbl->destroy(sjv_child._parent);
            }
        }
    }

    sjt_functionParam15 = sjv_glfeature_gl_depth_test;
    sjf_glenable(sjt_functionParam15);
    sjv_a._refCount = 1;
    sjv_a.array._refCount = 1;
    sjv_a.array.datasize = 0;
    sjv_a.array.data = 0;
    sjv_a.array._isglobal = false;
    sjv_a.array.count = 0;
    sjf_array_local_iface_model(&sjv_a.array);
    sjf_list_local_iface_model(&sjv_a);
    sjt_forStart5 = 0;
    sjt_dot53 = _parent;
    sjt_dot52 = &(sjt_dot53)->children;
    sjt_forEnd5 = (sjt_dot52)->count;
    i = sjt_forStart5;
    while (i < sjt_forEnd5) {
        sjs_nauscene3delement* sjt_dot54 = 0;
        int32_t sjt_functionParam16;
        sjs_list_local_iface_model* sjt_interfaceParam9 = 0;
        sjs_array_heap_iface_model* sjt_parent12 = 0;
        sji_model sjt_parent13 = { 0 };
        sji_model sjv_child = { 0 };

        sjt_dot54 = _parent;
        sjt_parent12 = &(sjt_dot54)->children;
        sjt_functionParam16 = i;
        sjf_array_heap_iface_model_getat_heap(sjt_parent12, sjt_functionParam16, &sjv_child);
        sjt_parent13 = sjv_child;
        sjt_interfaceParam9 = &sjv_a;
        sjt_parent13._vtbl->renderorqueue(sjt_parent13._parent, sjt_interfaceParam9);
        i++;

        if (sjv_child._parent != 0) {
            sjv_child._parent->_refCount--;
            if (sjv_child._parent->_refCount <= 0) {
                sjv_child._vtbl->destroy(sjv_child._parent);
            }
        }
    }

    sjt_parent15 = &sjv_a;
    sjt_functionParam46._parent = (sjs_object*)1;
    sjt_functionParam46._cb = (void(*)(sjs_object*,sji_model,sji_model, int32_t*))sjf_model_zsort_callback;
    sjf_list_local_iface_model_sortcb(sjt_parent15, sjt_functionParam46);
    sjt_forStart6 = 0;
    sjt_parent18 = &sjv_a;
    sjf_list_local_iface_model_getcount(sjt_parent18, &sjt_forEnd6);
    i = sjt_forEnd6 - 1;
    while (i >= sjt_forStart6) {
        int32_t sjt_functionParam50;
        sjs_list_local_iface_model* sjt_parent20 = 0;
        sji_model sjt_parent21 = { 0 };
        sji_model sjv_child = { 0 };

        sjt_parent20 = &sjv_a;
        sjt_functionParam50 = i;
        sjf_list_local_iface_model_getat_heap(sjt_parent20, sjt_functionParam50, &sjv_child);
        sjt_parent21 = sjv_child;
        sjt_parent21._vtbl->render(sjt_parent21._parent);
        i--;

        if (sjv_child._parent != 0) {
            sjv_child._parent->_refCount--;
            if (sjv_child._parent->_refCount <= 0) {
                sjv_child._vtbl->destroy(sjv_child._parent);
            }
        }
    }

    sjt_functionParam51 = sjv_glfeature_gl_depth_test;
    sjf_gldisable(sjt_functionParam51);

    if (sjv_a._refCount == 1) { sjf_list_local_iface_model_destroy(&sjv_a); }
}

void sjf_nauscene3delement_setrect(sjs_nauscene3delement* _parent, sjs_rect* rect_) {
    bool result2;
    sjs_nauscene3delement* sjt_dot34 = 0;
    sjs_rect* sjt_functionParam7 = 0;
    bool sjt_ifElse1;
    bool sjt_not1;
    sjs_rect* sjt_parent9 = 0;

    sjt_dot34 = _parent;
    sjt_parent9 = &(sjt_dot34)->_rect;
    sjt_functionParam7 = rect_;
    sjf_rect_isequal(sjt_parent9, sjt_functionParam7, &sjt_not1);
    result2 = !sjt_not1;
    sjt_ifElse1 = result2;
    if (sjt_ifElse1) {
        int32_t sjt_cast3;
        int32_t sjt_cast4;
        sjs_rect* sjt_copy6 = 0;
        sjs_nauscene3delement* sjt_dot35 = 0;
        sjs_nauscene3delement* sjt_dot36 = 0;
        sjs_nauscene3delement* sjt_dot37 = 0;
        sjs_rect* sjt_dot38 = 0;
        sjs_nauscene3delement* sjt_dot39 = 0;
        sjs_rect* sjt_dot40 = 0;
        sjs_nauscene3delement* sjt_dot41 = 0;
        sjs_nauscene3delement* sjt_dot42 = 0;
        sjs_nauscene3delement* sjt_dot43 = 0;
        float sjt_functionParam10;
        float sjt_functionParam11;
        float sjt_functionParam12;
        float sjt_functionParam13;
        float sjt_math43;
        float sjt_math44;

        sjt_dot35 = _parent;
        sjt_copy6 = rect_;
        sjt_dot35->_rect._refCount = 1;
        sjf_rect_copy(&sjt_dot35->_rect, sjt_copy6);
        sjt_dot36 = _parent;
        sjt_dot37 = _parent;
        sjt_functionParam10 = (sjt_dot37)->fieldofview;
        sjt_dot39 = _parent;
        sjt_dot38 = &(sjt_dot39)->_rect;
        sjt_cast3 = (sjt_dot38)->h;
        sjt_math43 = (float)sjt_cast3;
        sjt_dot41 = _parent;
        sjt_dot40 = &(sjt_dot41)->_rect;
        sjt_cast4 = (sjt_dot40)->w;
        sjt_math44 = (float)sjt_cast4;
        sjt_functionParam11 = sjt_math43 / sjt_math44;
        sjt_dot42 = _parent;
        sjt_functionParam12 = (sjt_dot42)->znear;
        sjt_dot43 = _parent;
        sjt_functionParam13 = (sjt_dot43)->zfar;
        sjf_mat4_perspective(sjt_functionParam10, sjt_functionParam11, sjt_functionParam12, sjt_functionParam13, &sjt_dot36->projection);
    }
}

void sjf_panel3d(sjs_panel3d* _this) {
}

void sjf_panel3d_as_sji_model(sjs_panel3d* _this, sji_model* _return) {
    _return->_parent = (sjs_object*)_this;
    _return->_vtbl = &sjs_panel3d_model_vtbl;
}

void sjf_panel3d_asinterface(sjs_panel3d* _this, int typeId, sjs_interface* _return) {
    switch (typeId) {
        case sji_model_typeId:  {
            sjf_panel3d_as_sji_model(_this, (sji_model*)_return);
            break;
        }
    }

    _return->_parent = 0;
}

void sjf_panel3d_copy(sjs_panel3d* _this, sjs_panel3d* _from) {
    _this->model._refCount = 1;
    sjf_mat4_copy(&_this->model, &_from->model);
    _this->children._refCount = 1;
    sjf_array_heap_iface_model_copy(&_this->children, &_from->children);
}

void sjf_panel3d_destroy(sjs_panel3d* _this) {
}

void sjf_panel3d_firemouseevent(sjs_panel3d* _parent, sjs_mouseevent* mouseevent) {
    int32_t i;
    sjs_array_heap_iface_model* sjt_dot1701 = 0;
    sjs_panel3d* sjt_dot1702 = 0;
    int32_t sjt_forEnd27;
    int32_t sjt_forStart27;

    sjt_forStart27 = 0;
    sjt_dot1702 = _parent;
    sjt_dot1701 = &(sjt_dot1702)->children;
    sjt_forEnd27 = (sjt_dot1701)->count;
    i = sjt_forStart27;
    while (i < sjt_forEnd27) {
        sjs_panel3d* sjt_dot1703 = 0;
        int32_t sjt_functionParam525;
        sjs_mouseevent* sjt_interfaceParam35 = 0;
        sjs_array_heap_iface_model* sjt_parent217 = 0;
        sji_model sjt_parent218 = { 0 };
        sji_model sjv_c = { 0 };

        sjt_dot1703 = _parent;
        sjt_parent217 = &(sjt_dot1703)->children;
        sjt_functionParam525 = i;
        sjf_array_heap_iface_model_getat_heap(sjt_parent217, sjt_functionParam525, &sjv_c);
        sjt_parent218 = sjv_c;
        sjt_interfaceParam35 = mouseevent;
        sjt_parent218._vtbl->firemouseevent(sjt_parent218._parent, sjt_interfaceParam35);
        i++;

        if (sjv_c._parent != 0) {
            sjv_c._parent->_refCount--;
            if (sjv_c._parent->_refCount <= 0) {
                sjv_c._vtbl->destroy(sjv_c._parent);
            }
        }
    }
}

void sjf_panel3d_getz(sjs_panel3d* _parent, float* _return) {
    (*_return) = 0.0f;
}

void sjf_panel3d_heap(sjs_panel3d* _this) {
}

void sjf_panel3d_heap_as_sji_model(sjs_panel3d* _this, sji_model* _return) {
    _return->_parent = (sjs_object*)_this;
    _return->_vtbl = &sjs_panel3d_model_vtbl;
}

void sjf_panel3d_heap_asinterface(sjs_panel3d* _this, int typeId, sjs_interface* _return) {
    switch (typeId) {
        case sji_model_typeId:  {
            sjf_panel3d_heap_as_sji_model(_this, (sji_model*)_return);
            break;
        }
    }

    _return->_parent = 0;
}

void sjf_panel3d_render(sjs_panel3d* _parent) {
}

void sjf_panel3d_renderorqueue(sjs_panel3d* _parent, sjs_list_local_iface_model* zqueue) {
    int32_t i;
    sjs_array_heap_iface_model* sjt_dot1698 = 0;
    sjs_panel3d* sjt_dot1699 = 0;
    int32_t sjt_forEnd26;
    int32_t sjt_forStart26;

    sjt_forStart26 = 0;
    sjt_dot1699 = _parent;
    sjt_dot1698 = &(sjt_dot1699)->children;
    sjt_forEnd26 = (sjt_dot1698)->count;
    i = sjt_forStart26;
    while (i < sjt_forEnd26) {
        sjs_panel3d* sjt_dot1700 = 0;
        int32_t sjt_functionParam524;
        sjs_list_local_iface_model* sjt_interfaceParam34 = 0;
        sjs_array_heap_iface_model* sjt_parent215 = 0;
        sji_model sjt_parent216 = { 0 };
        sji_model sjv_c = { 0 };

        sjt_dot1700 = _parent;
        sjt_parent215 = &(sjt_dot1700)->children;
        sjt_functionParam524 = i;
        sjf_array_heap_iface_model_getat_heap(sjt_parent215, sjt_functionParam524, &sjv_c);
        sjt_parent216 = sjv_c;
        sjt_interfaceParam34 = zqueue;
        sjt_parent216._vtbl->renderorqueue(sjt_parent216._parent, sjt_interfaceParam34);
        i++;

        if (sjv_c._parent != 0) {
            sjv_c._parent->_refCount--;
            if (sjv_c._parent->_refCount <= 0) {
                sjv_c._vtbl->destroy(sjv_c._parent);
            }
        }
    }
}

void sjf_panel3d_update(sjs_panel3d* _parent, sjs_rect* scenerect, sjs_mat4* projection, sjs_mat4* view, sjs_mat4* world, sjs_light* light) {
    int32_t i;
    sjs_panel3d* sjt_dot1694 = 0;
    sjs_array_heap_iface_model* sjt_dot1695 = 0;
    sjs_panel3d* sjt_dot1696 = 0;
    int32_t sjt_forEnd25;
    int32_t sjt_forStart25;
    sjs_mat4* sjt_functionParam522 = 0;
    sjs_mat4* sjt_parent212 = 0;
    sjs_mat4 sjv_childworld = { -1 };

    sjt_parent212 = world;
    sjt_dot1694 = _parent;
    sjt_functionParam522 = &(sjt_dot1694)->model;
    sjf_mat4_multiply(sjt_parent212, sjt_functionParam522, &sjv_childworld);
    sjt_forStart25 = 0;
    sjt_dot1696 = _parent;
    sjt_dot1695 = &(sjt_dot1696)->children;
    sjt_forEnd25 = (sjt_dot1695)->count;
    i = sjt_forStart25;
    while (i < sjt_forEnd25) {
        sjs_panel3d* sjt_dot1697 = 0;
        int32_t sjt_functionParam523;
        sjs_rect* sjt_interfaceParam29 = 0;
        sjs_mat4* sjt_interfaceParam30 = 0;
        sjs_mat4* sjt_interfaceParam31 = 0;
        sjs_mat4* sjt_interfaceParam32 = 0;
        sjs_light* sjt_interfaceParam33 = 0;
        sjs_array_heap_iface_model* sjt_parent213 = 0;
        sji_model sjt_parent214 = { 0 };
        sji_model sjv_c = { 0 };

        sjt_dot1697 = _parent;
        sjt_parent213 = &(sjt_dot1697)->children;
        sjt_functionParam523 = i;
        sjf_array_heap_iface_model_getat_heap(sjt_parent213, sjt_functionParam523, &sjv_c);
        sjt_parent214 = sjv_c;
        sjt_interfaceParam29 = scenerect;
        sjt_interfaceParam30 = projection;
        sjt_interfaceParam31 = view;
        sjt_interfaceParam32 = &sjv_childworld;
        sjt_interfaceParam33 = light;
        sjt_parent214._vtbl->update(sjt_parent214._parent, sjt_interfaceParam29, sjt_interfaceParam30, sjt_interfaceParam31, sjt_interfaceParam32, sjt_interfaceParam33);
        i++;

        if (sjv_c._parent != 0) {
            sjv_c._parent->_refCount--;
            if (sjv_c._parent->_refCount <= 0) {
                sjv_c._vtbl->destroy(sjv_c._parent);
            }
        }
    }

    if (sjv_childworld._refCount == 1) { sjf_mat4_destroy(&sjv_childworld); }
}

void sjf_peoplepanel(sjs_peoplepanel* _this) {
    float result17;
    int32_t sjt_cast22;
    int32_t sjt_cast23;
    sjs_array_heap_iface_model* sjt_dot1368 = 0;
    float sjt_functionParam284;
    cb_heap_iface_model_mat4 sjt_functionParam289;
    float sjt_math2153;
    float sjt_math2154;
    float sjt_math2155;
    float sjt_math2156;
    float sjt_math2157;
    float sjt_math2158;
    float sjt_negate15;
    sjs_array_heap_iface_model* sjt_parent113 = 0;

    sjt_math2155 = _this->_xincrement;
    sjt_dot1368 = &_this->children;
    sjt_cast22 = (sjt_dot1368)->count;
    sjt_math2157 = (float)sjt_cast22;
    sjt_cast23 = _this->_depth;
    sjt_math2158 = (float)sjt_cast23;
    sjt_functionParam284 = sjt_math2157 / sjt_math2158;
    sjf_f32_ceil(sjt_functionParam284, &sjt_math2156);
    sjt_math2153 = sjt_math2155 * sjt_math2156;
    sjt_math2154 = 2.0f;
    sjt_negate15 = sjt_math2153 / sjt_math2154;
    result17 = -sjt_negate15;
    _this->_xoffset = result17;
    sjt_parent113 = &_this->children;
    sjt_functionParam289._parent = (sjs_object*)&_this;
    sjt_functionParam289._cb = (void(*)(sjs_object*,sji_model, sjs_mat4*))sjf_peoplepanel_getmodelmatrix;
    sjf_array_heap_iface_model_map_mat4(sjt_parent113, sjt_functionParam289, &_this->_childrenmodel);
}

void sjf_peoplepanel_as_sji_model(sjs_peoplepanel* _this, sji_model* _return) {
    _return->_parent = (sjs_object*)_this;
    _return->_vtbl = &sjs_peoplepanel_model_vtbl;
}

void sjf_peoplepanel_asinterface(sjs_peoplepanel* _this, int typeId, sjs_interface* _return) {
    switch (typeId) {
        case sji_model_typeId:  {
            sjf_peoplepanel_as_sji_model(_this, (sji_model*)_return);
            break;
        }
    }

    _return->_parent = 0;
}

void sjf_peoplepanel_copy(sjs_peoplepanel* _this, sjs_peoplepanel* _from) {
    _this->model._refCount = 1;
    sjf_mat4_copy(&_this->model, &_from->model);
    _this->children._refCount = 1;
    sjf_array_heap_iface_model_copy(&_this->children, &_from->children);
    _this->_childrenmodel._refCount = 1;
    sjf_array_mat4_copy(&_this->_childrenmodel, &_from->_childrenmodel);
    _this->_index = _from->_index;
    _this->_depth = _from->_depth;
    _this->_xincrement = _from->_xincrement;
    _this->_zincrement = _from->_zincrement;
    _this->_xoffset = _from->_xoffset;
}

void sjf_peoplepanel_destroy(sjs_peoplepanel* _this) {
}

void sjf_peoplepanel_firemouseevent(sjs_peoplepanel* _parent, sjs_mouseevent* mouseevent) {
    int32_t i;
    sjs_array_heap_iface_model* sjt_dot1403 = 0;
    sjs_peoplepanel* sjt_dot1404 = 0;
    int32_t sjt_forEnd19;
    int32_t sjt_forStart19;

    sjt_forStart19 = 0;
    sjt_dot1404 = _parent;
    sjt_dot1403 = &(sjt_dot1404)->children;
    sjt_forEnd19 = (sjt_dot1403)->count;
    i = sjt_forStart19;
    while (i < sjt_forEnd19) {
        sjs_peoplepanel* sjt_dot1405 = 0;
        int32_t sjt_functionParam303;
        sjs_mouseevent* sjt_interfaceParam24 = 0;
        sjs_array_heap_iface_model* sjt_parent121 = 0;
        sji_model sjt_parent122 = { 0 };
        sji_model sjv_c = { 0 };

        sjt_dot1405 = _parent;
        sjt_parent121 = &(sjt_dot1405)->children;
        sjt_functionParam303 = i;
        sjf_array_heap_iface_model_getat_heap(sjt_parent121, sjt_functionParam303, &sjv_c);
        sjt_parent122 = sjv_c;
        sjt_interfaceParam24 = mouseevent;
        sjt_parent122._vtbl->firemouseevent(sjt_parent122._parent, sjt_interfaceParam24);
        i++;

        if (sjv_c._parent != 0) {
            sjv_c._parent->_refCount--;
            if (sjv_c._parent->_refCount <= 0) {
                sjv_c._vtbl->destroy(sjv_c._parent);
            }
        }
    }
}

void sjf_peoplepanel_getmodelmatrix(sjs_peoplepanel* _parent, sji_model model, sjs_mat4* _return) {
    int32_t sjt_cast24;
    int32_t sjt_cast25;
    int32_t sjt_cast26;
    int32_t sjt_compare55;
    int32_t sjt_compare56;
    sjs_peoplepanel* sjt_dot1375 = 0;
    sjs_peoplepanel* sjt_dot1376 = 0;
    sjs_peoplepanel* sjt_dot1377 = 0;
    sjs_peoplepanel* sjt_dot1378 = 0;
    sjs_peoplepanel* sjt_dot1379 = 0;
    sjs_peoplepanel* sjt_dot1380 = 0;
    sjs_peoplepanel* sjt_dot1382 = 0;
    sjs_peoplepanel* sjt_dot1383 = 0;
    sjs_peoplepanel* sjt_dot1384 = 0;
    float sjt_functionParam290;
    float sjt_functionParam291;
    float sjt_functionParam292;
    float sjt_functionParam293;
    bool sjt_ifElse19;
    float sjt_math2159;
    float sjt_math2160;
    float sjt_math2161;
    float sjt_math2162;
    int32_t sjt_math2163;
    int32_t sjt_math2164;
    float sjt_math2165;
    float sjt_math2166;
    float sjt_math2167;
    float sjt_math2168;
    float sjt_math2169;
    float sjt_math2170;
    int32_t sjt_math2171;
    int32_t sjt_math2172;
    float sjt_math2177;
    float sjt_math2178;
    float sjt_math2179;
    float sjt_math2180;
    float sjt_math2181;
    float sjt_math2182;
    int32_t sjt_math2183;
    int32_t sjt_math2184;
    int32_t sjv_col;
    float sjv_noise;
    float sjv_row;
    float sjv_x;
    float sjv_z;

    sjf_f32_random(&sjt_math2159);
    sjt_math2160 = 0.5f;
    sjv_noise = sjt_math2159 - sjt_math2160;
    sjt_dot1375 = _parent;
    sjt_cast24 = (sjt_dot1375)->_index;
    sjt_math2161 = (float)sjt_cast24;
    sjt_dot1376 = _parent;
    sjt_cast25 = (sjt_dot1376)->_depth;
    sjt_math2162 = (float)sjt_cast25;
    sjt_functionParam290 = sjt_math2161 / sjt_math2162;
    sjf_f32_floor(sjt_functionParam290, &sjv_row);
    sjt_dot1377 = _parent;
    sjt_math2163 = (sjt_dot1377)->_index;
    sjt_dot1378 = _parent;
    sjt_math2164 = (sjt_dot1378)->_depth;
    sjv_col = sjt_math2163 % sjt_math2164;
    sjt_math2169 = sjv_row;
    sjt_dot1379 = _parent;
    sjt_math2170 = (sjt_dot1379)->_xincrement;
    sjt_math2167 = sjt_math2169 * sjt_math2170;
    sjt_dot1380 = _parent;
    sjt_math2168 = (sjt_dot1380)->_xoffset;
    sjt_math2165 = sjt_math2167 + sjt_math2168;
    sjt_math2166 = sjv_noise;
    sjv_x = sjt_math2165 + sjt_math2166;
    sjt_math2171 = sjv_col;
    sjt_math2172 = 2;
    sjt_compare55 = sjt_math2171 % sjt_math2172;
    sjt_compare56 = 1;
    sjt_ifElse19 = sjt_compare55 == sjt_compare56;
    if (sjt_ifElse19) {
        sjs_peoplepanel* sjt_dot1381 = 0;
        float sjt_math2173;
        float sjt_math2174;
        float sjt_math2175;
        float sjt_math2176;

        sjt_math2173 = sjv_x;
        sjt_dot1381 = _parent;
        sjt_math2175 = (sjt_dot1381)->_xincrement;
        sjt_math2176 = 2.0f;
        sjt_math2174 = sjt_math2175 / sjt_math2176;
        sjv_x = sjt_math2173 + sjt_math2174;
    }

    sjt_cast26 = sjv_col;
    sjt_math2179 = (float)sjt_cast26;
    sjt_dot1382 = _parent;
    sjt_math2180 = (sjt_dot1382)->_zincrement;
    sjt_math2177 = sjt_math2179 * sjt_math2180;
    sjt_math2181 = sjv_noise;
    sjt_math2182 = 0.2f;
    sjt_math2178 = sjt_math2181 * sjt_math2182;
    sjv_z = sjt_math2177 + sjt_math2178;
    sjt_dot1383 = _parent;
    sjt_dot1384 = _parent;
    sjt_math2183 = (sjt_dot1384)->_index;
    sjt_math2184 = 1;
    sjt_dot1383->_index = sjt_math2183 + sjt_math2184;
    sjt_functionParam291 = sjv_x;
    sjt_functionParam292 = 0.0f;
    sjt_functionParam293 = sjv_z;
    sjf_mat4_translate(sjt_functionParam291, sjt_functionParam292, sjt_functionParam293, _return);
}

void sjf_peoplepanel_getmodelmatrix_heap(sjs_peoplepanel* _parent, sji_model model, sjs_mat4** _return) {
    int32_t sjt_cast27;
    int32_t sjt_cast28;
    int32_t sjt_cast29;
    int32_t sjt_compare57;
    int32_t sjt_compare58;
    sjs_peoplepanel* sjt_dot1385 = 0;
    sjs_peoplepanel* sjt_dot1386 = 0;
    sjs_peoplepanel* sjt_dot1387 = 0;
    sjs_peoplepanel* sjt_dot1388 = 0;
    sjs_peoplepanel* sjt_dot1389 = 0;
    sjs_peoplepanel* sjt_dot1390 = 0;
    sjs_peoplepanel* sjt_dot1392 = 0;
    sjs_peoplepanel* sjt_dot1393 = 0;
    sjs_peoplepanel* sjt_dot1394 = 0;
    float sjt_functionParam294;
    float sjt_functionParam295;
    float sjt_functionParam296;
    float sjt_functionParam297;
    bool sjt_ifElse20;
    float sjt_math2185;
    float sjt_math2186;
    float sjt_math2187;
    float sjt_math2188;
    int32_t sjt_math2189;
    int32_t sjt_math2190;
    float sjt_math2191;
    float sjt_math2192;
    float sjt_math2193;
    float sjt_math2194;
    float sjt_math2195;
    float sjt_math2196;
    int32_t sjt_math2197;
    int32_t sjt_math2198;
    float sjt_math2203;
    float sjt_math2204;
    float sjt_math2205;
    float sjt_math2206;
    float sjt_math2207;
    float sjt_math2208;
    int32_t sjt_math2209;
    int32_t sjt_math2210;
    int32_t sjv_col;
    float sjv_noise;
    float sjv_row;
    float sjv_x;
    float sjv_z;

    sjf_f32_random(&sjt_math2185);
    sjt_math2186 = 0.5f;
    sjv_noise = sjt_math2185 - sjt_math2186;
    sjt_dot1385 = _parent;
    sjt_cast27 = (sjt_dot1385)->_index;
    sjt_math2187 = (float)sjt_cast27;
    sjt_dot1386 = _parent;
    sjt_cast28 = (sjt_dot1386)->_depth;
    sjt_math2188 = (float)sjt_cast28;
    sjt_functionParam294 = sjt_math2187 / sjt_math2188;
    sjf_f32_floor(sjt_functionParam294, &sjv_row);
    sjt_dot1387 = _parent;
    sjt_math2189 = (sjt_dot1387)->_index;
    sjt_dot1388 = _parent;
    sjt_math2190 = (sjt_dot1388)->_depth;
    sjv_col = sjt_math2189 % sjt_math2190;
    sjt_math2195 = sjv_row;
    sjt_dot1389 = _parent;
    sjt_math2196 = (sjt_dot1389)->_xincrement;
    sjt_math2193 = sjt_math2195 * sjt_math2196;
    sjt_dot1390 = _parent;
    sjt_math2194 = (sjt_dot1390)->_xoffset;
    sjt_math2191 = sjt_math2193 + sjt_math2194;
    sjt_math2192 = sjv_noise;
    sjv_x = sjt_math2191 + sjt_math2192;
    sjt_math2197 = sjv_col;
    sjt_math2198 = 2;
    sjt_compare57 = sjt_math2197 % sjt_math2198;
    sjt_compare58 = 1;
    sjt_ifElse20 = sjt_compare57 == sjt_compare58;
    if (sjt_ifElse20) {
        sjs_peoplepanel* sjt_dot1391 = 0;
        float sjt_math2199;
        float sjt_math2200;
        float sjt_math2201;
        float sjt_math2202;

        sjt_math2199 = sjv_x;
        sjt_dot1391 = _parent;
        sjt_math2201 = (sjt_dot1391)->_xincrement;
        sjt_math2202 = 2.0f;
        sjt_math2200 = sjt_math2201 / sjt_math2202;
        sjv_x = sjt_math2199 + sjt_math2200;
    }

    sjt_cast29 = sjv_col;
    sjt_math2205 = (float)sjt_cast29;
    sjt_dot1392 = _parent;
    sjt_math2206 = (sjt_dot1392)->_zincrement;
    sjt_math2203 = sjt_math2205 * sjt_math2206;
    sjt_math2207 = sjv_noise;
    sjt_math2208 = 0.2f;
    sjt_math2204 = sjt_math2207 * sjt_math2208;
    sjv_z = sjt_math2203 + sjt_math2204;
    sjt_dot1393 = _parent;
    sjt_dot1394 = _parent;
    sjt_math2209 = (sjt_dot1394)->_index;
    sjt_math2210 = 1;
    sjt_dot1393->_index = sjt_math2209 + sjt_math2210;
    sjt_functionParam295 = sjv_x;
    sjt_functionParam296 = 0.0f;
    sjt_functionParam297 = sjv_z;
    sjf_mat4_translate_heap(sjt_functionParam295, sjt_functionParam296, sjt_functionParam297, _return);
}

void sjf_peoplepanel_getz(sjs_peoplepanel* _parent, float* _return) {
    (*_return) = 0.0f;
}

void sjf_peoplepanel_heap(sjs_peoplepanel* _this) {
    float result18;
    int32_t sjt_cast30;
    int32_t sjt_cast31;
    sjs_array_heap_iface_model* sjt_dot1406 = 0;
    float sjt_functionParam304;
    cb_heap_iface_model_mat4 sjt_functionParam305;
    float sjt_math2211;
    float sjt_math2212;
    float sjt_math2213;
    float sjt_math2214;
    float sjt_math2215;
    float sjt_math2216;
    float sjt_negate16;
    sjs_array_heap_iface_model* sjt_parent123 = 0;

    sjt_math2213 = _this->_xincrement;
    sjt_dot1406 = &_this->children;
    sjt_cast30 = (sjt_dot1406)->count;
    sjt_math2215 = (float)sjt_cast30;
    sjt_cast31 = _this->_depth;
    sjt_math2216 = (float)sjt_cast31;
    sjt_functionParam304 = sjt_math2215 / sjt_math2216;
    sjf_f32_ceil(sjt_functionParam304, &sjt_math2214);
    sjt_math2211 = sjt_math2213 * sjt_math2214;
    sjt_math2212 = 2.0f;
    sjt_negate16 = sjt_math2211 / sjt_math2212;
    result18 = -sjt_negate16;
    _this->_xoffset = result18;
    sjt_parent123 = &_this->children;
    sjt_functionParam305._parent = (sjs_object*)_this;
    sjt_functionParam305._cb = (void(*)(sjs_object*,sji_model, sjs_mat4*))sjf_peoplepanel_getmodelmatrix;
    sjf_array_heap_iface_model_map_mat4(sjt_parent123, sjt_functionParam305, &_this->_childrenmodel);
}

void sjf_peoplepanel_heap_as_sji_model(sjs_peoplepanel* _this, sji_model* _return) {
    _return->_parent = (sjs_object*)_this;
    _return->_vtbl = &sjs_peoplepanel_model_vtbl;
}

void sjf_peoplepanel_heap_asinterface(sjs_peoplepanel* _this, int typeId, sjs_interface* _return) {
    switch (typeId) {
        case sji_model_typeId:  {
            sjf_peoplepanel_heap_as_sji_model(_this, (sji_model*)_return);
            break;
        }
    }

    _return->_parent = 0;
}

void sjf_peoplepanel_render(sjs_peoplepanel* _parent) {
}

void sjf_peoplepanel_renderorqueue(sjs_peoplepanel* _parent, sjs_list_local_iface_model* zqueue) {
    int32_t i;
    sjs_array_heap_iface_model* sjt_dot1400 = 0;
    sjs_peoplepanel* sjt_dot1401 = 0;
    int32_t sjt_forEnd18;
    int32_t sjt_forStart18;

    sjt_forStart18 = 0;
    sjt_dot1401 = _parent;
    sjt_dot1400 = &(sjt_dot1401)->children;
    sjt_forEnd18 = (sjt_dot1400)->count;
    i = sjt_forStart18;
    while (i < sjt_forEnd18) {
        sjs_peoplepanel* sjt_dot1402 = 0;
        int32_t sjt_functionParam302;
        sjs_list_local_iface_model* sjt_interfaceParam23 = 0;
        sjs_array_heap_iface_model* sjt_parent119 = 0;
        sji_model sjt_parent120 = { 0 };
        sji_model sjv_c = { 0 };

        sjt_dot1402 = _parent;
        sjt_parent119 = &(sjt_dot1402)->children;
        sjt_functionParam302 = i;
        sjf_array_heap_iface_model_getat_heap(sjt_parent119, sjt_functionParam302, &sjv_c);
        sjt_parent120 = sjv_c;
        sjt_interfaceParam23 = zqueue;
        sjt_parent120._vtbl->renderorqueue(sjt_parent120._parent, sjt_interfaceParam23);
        i++;

        if (sjv_c._parent != 0) {
            sjv_c._parent->_refCount--;
            if (sjv_c._parent->_refCount <= 0) {
                sjv_c._vtbl->destroy(sjv_c._parent);
            }
        }
    }
}

void sjf_peoplepanel_update(sjs_peoplepanel* _parent, sjs_rect* scenerect, sjs_mat4* projection, sjs_mat4* view, sjs_mat4* world, sjs_light* light) {
    int32_t i;
    sjs_array_heap_iface_model* sjt_dot1395 = 0;
    sjs_peoplepanel* sjt_dot1396 = 0;
    int32_t sjt_forEnd17;
    int32_t sjt_forStart17;

    sjt_forStart17 = 0;
    sjt_dot1396 = _parent;
    sjt_dot1395 = &(sjt_dot1396)->children;
    sjt_forEnd17 = (sjt_dot1395)->count;
    i = sjt_forStart17;
    while (i < sjt_forEnd17) {
        sjs_mat4 sjt_call60 = { -1 };
        sjs_peoplepanel* sjt_dot1397 = 0;
        sjs_peoplepanel* sjt_dot1398 = 0;
        sjs_peoplepanel* sjt_dot1399 = 0;
        int32_t sjt_functionParam298;
        int32_t sjt_functionParam299;
        sjs_mat4* sjt_functionParam300 = 0;
        sjs_mat4* sjt_functionParam301 = 0;
        sjs_rect* sjt_interfaceParam18 = 0;
        sjs_mat4* sjt_interfaceParam19 = 0;
        sjs_mat4* sjt_interfaceParam20 = 0;
        sjs_mat4* sjt_interfaceParam21 = 0;
        sjs_light* sjt_interfaceParam22 = 0;
        sjs_array_heap_iface_model* sjt_parent114 = 0;
        sjs_array_mat4* sjt_parent115 = 0;
        sjs_mat4* sjt_parent116 = 0;
        sjs_mat4* sjt_parent117 = 0;
        sji_model sjt_parent118 = { 0 };
        sji_model sjv_c = { 0 };
        sjs_mat4 sjv_childmodel = { -1 };
        sjs_mat4 sjv_newworld = { -1 };

        sjt_dot1397 = _parent;
        sjt_parent114 = &(sjt_dot1397)->children;
        sjt_functionParam298 = i;
        sjf_array_heap_iface_model_getat_heap(sjt_parent114, sjt_functionParam298, &sjv_c);
        sjt_dot1398 = _parent;
        sjt_parent115 = &(sjt_dot1398)->_childrenmodel;
        sjt_functionParam299 = i;
        sjf_array_mat4_getat(sjt_parent115, sjt_functionParam299, &sjv_childmodel);
        sjt_parent117 = world;
        sjt_dot1399 = _parent;
        sjt_functionParam300 = &(sjt_dot1399)->model;
        sjf_mat4_multiply(sjt_parent117, sjt_functionParam300, &sjt_call60);
        sjt_parent116 = &sjt_call60;
        sjt_functionParam301 = &sjv_childmodel;
        sjf_mat4_multiply(sjt_parent116, sjt_functionParam301, &sjv_newworld);
        sjt_parent118 = sjv_c;
        sjt_interfaceParam18 = scenerect;
        sjt_interfaceParam19 = projection;
        sjt_interfaceParam20 = view;
        sjt_interfaceParam21 = &sjv_newworld;
        sjt_interfaceParam22 = light;
        sjt_parent118._vtbl->update(sjt_parent118._parent, sjt_interfaceParam18, sjt_interfaceParam19, sjt_interfaceParam20, sjt_interfaceParam21, sjt_interfaceParam22);
        i++;

        if (sjv_c._parent != 0) {
            sjv_c._parent->_refCount--;
            if (sjv_c._parent->_refCount <= 0) {
                sjv_c._vtbl->destroy(sjv_c._parent);
            }
        }
        if (sjt_call60._refCount == 1) { sjf_mat4_destroy(&sjt_call60); }
        if (sjv_childmodel._refCount == 1) { sjf_mat4_destroy(&sjv_childmodel); }
        if (sjv_newworld._refCount == 1) { sjf_mat4_destroy(&sjv_newworld); }
    }
}

void sjf_planevertexbuffer(float x0, float x1, float y0, float y1, float z0, float s0, float s1, float t0, float t1, sjs_vertexbuffer_vertex_location_texture_normal* _return) {
    float result5;
    float result6;
    float result7;
    float result8;
    sjs_vertex_location_texture_normal sjt_call26 = { -1 };
    sjs_vertex_location_texture_normal sjt_call27 = { -1 };
    sjs_vertex_location_texture_normal sjt_call28 = { -1 };
    sjs_vertex_location_texture_normal sjt_call29 = { -1 };
    sjs_string* sjt_copy13 = 0;
    int32_t sjt_functionParam156;
    int32_t sjt_functionParam157;
    int32_t sjt_functionParam158;
    int32_t sjt_functionParam159;
    int32_t sjt_functionParam160;
    int32_t sjt_functionParam161;
    int32_t sjt_functionParam162;
    int32_t sjt_functionParam163;
    int32_t sjt_functionParam164;
    int32_t sjt_functionParam165;
    int32_t sjt_functionParam166;
    int32_t sjt_functionParam167;
    int32_t sjt_functionParam168;
    sjs_vertex_location_texture_normal* sjt_functionParam169 = 0;
    int32_t sjt_functionParam170;
    sjs_vertex_location_texture_normal* sjt_functionParam171 = 0;
    int32_t sjt_functionParam172;
    sjs_vertex_location_texture_normal* sjt_functionParam173 = 0;
    int32_t sjt_functionParam174;
    sjs_vertex_location_texture_normal* sjt_functionParam175 = 0;
    float sjt_negate3;
    float sjt_negate4;
    float sjt_negate5;
    float sjt_negate6;
    sjs_array_i32* sjt_parent60 = 0;
    sjs_array_i32* sjt_parent61 = 0;
    sjs_array_i32* sjt_parent62 = 0;
    sjs_array_i32* sjt_parent63 = 0;
    sjs_array_i32* sjt_parent64 = 0;
    sjs_array_i32* sjt_parent65 = 0;
    sjs_array_vertex_location_texture_normal* sjt_parent66 = 0;
    sjs_array_vertex_location_texture_normal* sjt_parent67 = 0;
    sjs_array_vertex_location_texture_normal* sjt_parent68 = 0;
    sjs_array_vertex_location_texture_normal* sjt_parent69 = 0;

    _return->_refCount = 1;
    sjt_copy13 = &sjv_vertex_location_texture_normal_format;
    _return->format._refCount = 1;
    sjf_string_copy(&_return->format, sjt_copy13);
    _return->indices._refCount = 1;
    _return->indices.datasize = 6;
    _return->indices.data = 0;
    _return->indices._isglobal = false;
    _return->indices.count = 0;
    sjf_array_i32(&_return->indices);
    sjs_array_i32* array1;
    array1 = &_return->indices;
    sjt_parent60 = array1;
    sjt_functionParam156 = 0;
    sjt_functionParam157 = 0;
    sjf_array_i32_initat(sjt_parent60, sjt_functionParam156, sjt_functionParam157);
    sjt_parent61 = array1;
    sjt_functionParam158 = 1;
    sjt_functionParam159 = 1;
    sjf_array_i32_initat(sjt_parent61, sjt_functionParam158, sjt_functionParam159);
    sjt_parent62 = array1;
    sjt_functionParam160 = 2;
    sjt_functionParam161 = 2;
    sjf_array_i32_initat(sjt_parent62, sjt_functionParam160, sjt_functionParam161);
    sjt_parent63 = array1;
    sjt_functionParam162 = 3;
    sjt_functionParam163 = 0;
    sjf_array_i32_initat(sjt_parent63, sjt_functionParam162, sjt_functionParam163);
    sjt_parent64 = array1;
    sjt_functionParam164 = 4;
    sjt_functionParam165 = 2;
    sjf_array_i32_initat(sjt_parent64, sjt_functionParam164, sjt_functionParam165);
    sjt_parent65 = array1;
    sjt_functionParam166 = 5;
    sjt_functionParam167 = 3;
    sjf_array_i32_initat(sjt_parent65, sjt_functionParam166, sjt_functionParam167);
    _return->vertices._refCount = 1;
    _return->vertices.datasize = 4;
    _return->vertices.data = 0;
    _return->vertices._isglobal = false;
    _return->vertices.count = 0;
    sjf_array_vertex_location_texture_normal(&_return->vertices);
    sjs_array_vertex_location_texture_normal* array2;
    array2 = &_return->vertices;
    sjt_parent66 = array2;
    sjt_functionParam168 = 0;
    sjt_call26._refCount = 1;
    sjt_call26.location._refCount = 1;
    sjt_call26.location.x = x0;
    sjt_call26.location.y = y0;
    sjt_call26.location.z = z0;
    sjf_vec3(&sjt_call26.location);
    sjt_call26.texture._refCount = 1;
    sjt_call26.texture.x = s0;
    sjt_call26.texture.y = t0;
    sjf_vec2(&sjt_call26.texture);
    sjt_call26.normal._refCount = 1;
    sjt_call26.normal.x = 0.0f;
    sjt_call26.normal.y = 0.0f;
    sjt_negate3 = 1.0f;
    result5 = -sjt_negate3;
    sjt_call26.normal.z = result5;
    sjf_vec3(&sjt_call26.normal);
    sjf_vertex_location_texture_normal(&sjt_call26);
    sjt_functionParam169 = &sjt_call26;
    sjf_array_vertex_location_texture_normal_initat(sjt_parent66, sjt_functionParam168, sjt_functionParam169);
    sjt_parent67 = array2;
    sjt_functionParam170 = 1;
    sjt_call27._refCount = 1;
    sjt_call27.location._refCount = 1;
    sjt_call27.location.x = x0;
    sjt_call27.location.y = y1;
    sjt_call27.location.z = z0;
    sjf_vec3(&sjt_call27.location);
    sjt_call27.texture._refCount = 1;
    sjt_call27.texture.x = s0;
    sjt_call27.texture.y = t1;
    sjf_vec2(&sjt_call27.texture);
    sjt_call27.normal._refCount = 1;
    sjt_call27.normal.x = 0.0f;
    sjt_call27.normal.y = 0.0f;
    sjt_negate4 = 1.0f;
    result6 = -sjt_negate4;
    sjt_call27.normal.z = result6;
    sjf_vec3(&sjt_call27.normal);
    sjf_vertex_location_texture_normal(&sjt_call27);
    sjt_functionParam171 = &sjt_call27;
    sjf_array_vertex_location_texture_normal_initat(sjt_parent67, sjt_functionParam170, sjt_functionParam171);
    sjt_parent68 = array2;
    sjt_functionParam172 = 2;
    sjt_call28._refCount = 1;
    sjt_call28.location._refCount = 1;
    sjt_call28.location.x = x1;
    sjt_call28.location.y = y1;
    sjt_call28.location.z = z0;
    sjf_vec3(&sjt_call28.location);
    sjt_call28.texture._refCount = 1;
    sjt_call28.texture.x = s1;
    sjt_call28.texture.y = t1;
    sjf_vec2(&sjt_call28.texture);
    sjt_call28.normal._refCount = 1;
    sjt_call28.normal.x = 0.0f;
    sjt_call28.normal.y = 0.0f;
    sjt_negate5 = 1.0f;
    result7 = -sjt_negate5;
    sjt_call28.normal.z = result7;
    sjf_vec3(&sjt_call28.normal);
    sjf_vertex_location_texture_normal(&sjt_call28);
    sjt_functionParam173 = &sjt_call28;
    sjf_array_vertex_location_texture_normal_initat(sjt_parent68, sjt_functionParam172, sjt_functionParam173);
    sjt_parent69 = array2;
    sjt_functionParam174 = 3;
    sjt_call29._refCount = 1;
    sjt_call29.location._refCount = 1;
    sjt_call29.location.x = x1;
    sjt_call29.location.y = y0;
    sjt_call29.location.z = z0;
    sjf_vec3(&sjt_call29.location);
    sjt_call29.texture._refCount = 1;
    sjt_call29.texture.x = s1;
    sjt_call29.texture.y = t0;
    sjf_vec2(&sjt_call29.texture);
    sjt_call29.normal._refCount = 1;
    sjt_call29.normal.x = 0.0f;
    sjt_call29.normal.y = 0.0f;
    sjt_negate6 = 1.0f;
    result8 = -sjt_negate6;
    sjt_call29.normal.z = result8;
    sjf_vec3(&sjt_call29.normal);
    sjf_vertex_location_texture_normal(&sjt_call29);
    sjt_functionParam175 = &sjt_call29;
    sjf_array_vertex_location_texture_normal_initat(sjt_parent69, sjt_functionParam174, sjt_functionParam175);
    sjf_vertexbuffer_vertex_location_texture_normal(_return);

    if (sjt_call26._refCount == 1) { sjf_vertex_location_texture_normal_destroy(&sjt_call26); }
    if (sjt_call27._refCount == 1) { sjf_vertex_location_texture_normal_destroy(&sjt_call27); }
    if (sjt_call28._refCount == 1) { sjf_vertex_location_texture_normal_destroy(&sjt_call28); }
    if (sjt_call29._refCount == 1) { sjf_vertex_location_texture_normal_destroy(&sjt_call29); }
}

void sjf_planevertexbuffer_heap(float x0, float x1, float y0, float y1, float z0, float s0, float s1, float t0, float t1, sjs_vertexbuffer_vertex_location_texture_normal** _return) {
    float result10;
    float result11;
    float result12;
    float result9;
    sjs_vertex_location_texture_normal sjt_call30 = { -1 };
    sjs_vertex_location_texture_normal sjt_call31 = { -1 };
    sjs_vertex_location_texture_normal sjt_call32 = { -1 };
    sjs_vertex_location_texture_normal sjt_call33 = { -1 };
    sjs_string* sjt_copy14 = 0;
    int32_t sjt_functionParam176;
    int32_t sjt_functionParam177;
    int32_t sjt_functionParam178;
    int32_t sjt_functionParam179;
    int32_t sjt_functionParam180;
    int32_t sjt_functionParam181;
    int32_t sjt_functionParam182;
    int32_t sjt_functionParam183;
    int32_t sjt_functionParam184;
    int32_t sjt_functionParam185;
    int32_t sjt_functionParam186;
    int32_t sjt_functionParam187;
    int32_t sjt_functionParam188;
    sjs_vertex_location_texture_normal* sjt_functionParam189 = 0;
    int32_t sjt_functionParam190;
    sjs_vertex_location_texture_normal* sjt_functionParam191 = 0;
    int32_t sjt_functionParam192;
    sjs_vertex_location_texture_normal* sjt_functionParam193 = 0;
    int32_t sjt_functionParam194;
    sjs_vertex_location_texture_normal* sjt_functionParam195 = 0;
    float sjt_negate10;
    float sjt_negate7;
    float sjt_negate8;
    float sjt_negate9;
    sjs_array_i32* sjt_parent70 = 0;
    sjs_array_i32* sjt_parent71 = 0;
    sjs_array_i32* sjt_parent72 = 0;
    sjs_array_i32* sjt_parent73 = 0;
    sjs_array_i32* sjt_parent74 = 0;
    sjs_array_i32* sjt_parent75 = 0;
    sjs_array_vertex_location_texture_normal* sjt_parent76 = 0;
    sjs_array_vertex_location_texture_normal* sjt_parent77 = 0;
    sjs_array_vertex_location_texture_normal* sjt_parent78 = 0;
    sjs_array_vertex_location_texture_normal* sjt_parent79 = 0;

    (*_return) = (sjs_vertexbuffer_vertex_location_texture_normal*)malloc(sizeof(sjs_vertexbuffer_vertex_location_texture_normal));
    (*_return)->_refCount = 1;
    sjt_copy14 = &sjv_vertex_location_texture_normal_format;
    (*_return)->format._refCount = 1;
    sjf_string_copy(&(*_return)->format, sjt_copy14);
    (*_return)->indices._refCount = 1;
    (*_return)->indices.datasize = 6;
    (*_return)->indices.data = 0;
    (*_return)->indices._isglobal = false;
    (*_return)->indices.count = 0;
    sjf_array_i32(&(*_return)->indices);
    sjs_array_i32* array3;
    array3 = &(*_return)->indices;
    sjt_parent70 = array3;
    sjt_functionParam176 = 0;
    sjt_functionParam177 = 0;
    sjf_array_i32_initat(sjt_parent70, sjt_functionParam176, sjt_functionParam177);
    sjt_parent71 = array3;
    sjt_functionParam178 = 1;
    sjt_functionParam179 = 1;
    sjf_array_i32_initat(sjt_parent71, sjt_functionParam178, sjt_functionParam179);
    sjt_parent72 = array3;
    sjt_functionParam180 = 2;
    sjt_functionParam181 = 2;
    sjf_array_i32_initat(sjt_parent72, sjt_functionParam180, sjt_functionParam181);
    sjt_parent73 = array3;
    sjt_functionParam182 = 3;
    sjt_functionParam183 = 0;
    sjf_array_i32_initat(sjt_parent73, sjt_functionParam182, sjt_functionParam183);
    sjt_parent74 = array3;
    sjt_functionParam184 = 4;
    sjt_functionParam185 = 2;
    sjf_array_i32_initat(sjt_parent74, sjt_functionParam184, sjt_functionParam185);
    sjt_parent75 = array3;
    sjt_functionParam186 = 5;
    sjt_functionParam187 = 3;
    sjf_array_i32_initat(sjt_parent75, sjt_functionParam186, sjt_functionParam187);
    (*_return)->vertices._refCount = 1;
    (*_return)->vertices.datasize = 4;
    (*_return)->vertices.data = 0;
    (*_return)->vertices._isglobal = false;
    (*_return)->vertices.count = 0;
    sjf_array_vertex_location_texture_normal(&(*_return)->vertices);
    sjs_array_vertex_location_texture_normal* array4;
    array4 = &(*_return)->vertices;
    sjt_parent76 = array4;
    sjt_functionParam188 = 0;
    sjt_call30._refCount = 1;
    sjt_call30.location._refCount = 1;
    sjt_call30.location.x = x0;
    sjt_call30.location.y = y0;
    sjt_call30.location.z = z0;
    sjf_vec3(&sjt_call30.location);
    sjt_call30.texture._refCount = 1;
    sjt_call30.texture.x = s0;
    sjt_call30.texture.y = t0;
    sjf_vec2(&sjt_call30.texture);
    sjt_call30.normal._refCount = 1;
    sjt_call30.normal.x = 0.0f;
    sjt_call30.normal.y = 0.0f;
    sjt_negate7 = 1.0f;
    result9 = -sjt_negate7;
    sjt_call30.normal.z = result9;
    sjf_vec3(&sjt_call30.normal);
    sjf_vertex_location_texture_normal(&sjt_call30);
    sjt_functionParam189 = &sjt_call30;
    sjf_array_vertex_location_texture_normal_initat(sjt_parent76, sjt_functionParam188, sjt_functionParam189);
    sjt_parent77 = array4;
    sjt_functionParam190 = 1;
    sjt_call31._refCount = 1;
    sjt_call31.location._refCount = 1;
    sjt_call31.location.x = x0;
    sjt_call31.location.y = y1;
    sjt_call31.location.z = z0;
    sjf_vec3(&sjt_call31.location);
    sjt_call31.texture._refCount = 1;
    sjt_call31.texture.x = s0;
    sjt_call31.texture.y = t1;
    sjf_vec2(&sjt_call31.texture);
    sjt_call31.normal._refCount = 1;
    sjt_call31.normal.x = 0.0f;
    sjt_call31.normal.y = 0.0f;
    sjt_negate8 = 1.0f;
    result10 = -sjt_negate8;
    sjt_call31.normal.z = result10;
    sjf_vec3(&sjt_call31.normal);
    sjf_vertex_location_texture_normal(&sjt_call31);
    sjt_functionParam191 = &sjt_call31;
    sjf_array_vertex_location_texture_normal_initat(sjt_parent77, sjt_functionParam190, sjt_functionParam191);
    sjt_parent78 = array4;
    sjt_functionParam192 = 2;
    sjt_call32._refCount = 1;
    sjt_call32.location._refCount = 1;
    sjt_call32.location.x = x1;
    sjt_call32.location.y = y1;
    sjt_call32.location.z = z0;
    sjf_vec3(&sjt_call32.location);
    sjt_call32.texture._refCount = 1;
    sjt_call32.texture.x = s1;
    sjt_call32.texture.y = t1;
    sjf_vec2(&sjt_call32.texture);
    sjt_call32.normal._refCount = 1;
    sjt_call32.normal.x = 0.0f;
    sjt_call32.normal.y = 0.0f;
    sjt_negate9 = 1.0f;
    result11 = -sjt_negate9;
    sjt_call32.normal.z = result11;
    sjf_vec3(&sjt_call32.normal);
    sjf_vertex_location_texture_normal(&sjt_call32);
    sjt_functionParam193 = &sjt_call32;
    sjf_array_vertex_location_texture_normal_initat(sjt_parent78, sjt_functionParam192, sjt_functionParam193);
    sjt_parent79 = array4;
    sjt_functionParam194 = 3;
    sjt_call33._refCount = 1;
    sjt_call33.location._refCount = 1;
    sjt_call33.location.x = x1;
    sjt_call33.location.y = y0;
    sjt_call33.location.z = z0;
    sjf_vec3(&sjt_call33.location);
    sjt_call33.texture._refCount = 1;
    sjt_call33.texture.x = s1;
    sjt_call33.texture.y = t0;
    sjf_vec2(&sjt_call33.texture);
    sjt_call33.normal._refCount = 1;
    sjt_call33.normal.x = 0.0f;
    sjt_call33.normal.y = 0.0f;
    sjt_negate10 = 1.0f;
    result12 = -sjt_negate10;
    sjt_call33.normal.z = result12;
    sjf_vec3(&sjt_call33.normal);
    sjf_vertex_location_texture_normal(&sjt_call33);
    sjt_functionParam195 = &sjt_call33;
    sjf_array_vertex_location_texture_normal_initat(sjt_parent79, sjt_functionParam194, sjt_functionParam195);
    sjf_vertexbuffer_vertex_location_texture_normal_heap((*_return));

    if (sjt_call30._refCount == 1) { sjf_vertex_location_texture_normal_destroy(&sjt_call30); }
    if (sjt_call31._refCount == 1) { sjf_vertex_location_texture_normal_destroy(&sjt_call31); }
    if (sjt_call32._refCount == 1) { sjf_vertex_location_texture_normal_destroy(&sjt_call32); }
    if (sjt_call33._refCount == 1) { sjf_vertex_location_texture_normal_destroy(&sjt_call33); }
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
    int32_t sjt_compare117;
    int32_t sjt_compare118;
    int32_t sjt_compare119;
    int32_t sjt_compare120;
    int32_t sjt_compare121;
    int32_t sjt_compare122;
    int32_t sjt_compare123;
    int32_t sjt_compare124;
    sjs_rect* sjt_dot1677 = 0;
    sjs_point* sjt_dot1678 = 0;
    sjs_rect* sjt_dot1679 = 0;
    sjs_point* sjt_dot1680 = 0;
    sjs_point* sjt_dot1681 = 0;
    sjs_rect* sjt_dot1682 = 0;
    sjs_rect* sjt_dot1683 = 0;
    sjs_point* sjt_dot1684 = 0;
    sjs_rect* sjt_dot1685 = 0;
    sjs_rect* sjt_dot1686 = 0;
    int32_t sjt_math2427;
    int32_t sjt_math2428;
    int32_t sjt_math2429;
    int32_t sjt_math2430;

    sjt_dot1677 = _parent;
    sjt_compare117 = (sjt_dot1677)->x;
    sjt_dot1678 = point;
    sjt_compare118 = (sjt_dot1678)->x;
    sjt_and13 = sjt_compare117 <= sjt_compare118;
    sjt_dot1679 = _parent;
    sjt_compare119 = (sjt_dot1679)->y;
    sjt_dot1680 = point;
    sjt_compare120 = (sjt_dot1680)->x;
    sjt_and15 = sjt_compare119 <= sjt_compare120;
    sjt_dot1681 = point;
    sjt_compare121 = (sjt_dot1681)->x;
    sjt_dot1682 = _parent;
    sjt_math2427 = (sjt_dot1682)->x;
    sjt_dot1683 = _parent;
    sjt_math2428 = (sjt_dot1683)->w;
    sjt_compare122 = sjt_math2427 + sjt_math2428;
    sjt_and17 = sjt_compare121 < sjt_compare122;
    sjt_dot1684 = point;
    sjt_compare123 = (sjt_dot1684)->y;
    sjt_dot1685 = _parent;
    sjt_math2429 = (sjt_dot1685)->y;
    sjt_dot1686 = _parent;
    sjt_math2430 = (sjt_dot1686)->h;
    sjt_compare124 = sjt_math2429 + sjt_math2430;
    sjt_and18 = sjt_compare123 < sjt_compare124;
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
    bool sjt_and1;
    bool sjt_and2;
    bool sjt_and3;
    bool sjt_and4;
    bool sjt_and5;
    bool sjt_and6;
    int32_t sjt_compare1;
    int32_t sjt_compare2;
    int32_t sjt_compare3;
    int32_t sjt_compare4;
    int32_t sjt_compare5;
    int32_t sjt_compare6;
    int32_t sjt_compare7;
    int32_t sjt_compare8;
    sjs_rect* sjt_dot26 = 0;
    sjs_rect* sjt_dot27 = 0;
    sjs_rect* sjt_dot28 = 0;
    sjs_rect* sjt_dot29 = 0;
    sjs_rect* sjt_dot30 = 0;
    sjs_rect* sjt_dot31 = 0;
    sjs_rect* sjt_dot32 = 0;
    sjs_rect* sjt_dot33 = 0;

    sjt_dot26 = _parent;
    sjt_compare1 = (sjt_dot26)->x;
    sjt_dot27 = rect;
    sjt_compare2 = (sjt_dot27)->x;
    sjt_and1 = sjt_compare1 == sjt_compare2;
    sjt_dot28 = _parent;
    sjt_compare3 = (sjt_dot28)->y;
    sjt_dot29 = rect;
    sjt_compare4 = (sjt_dot29)->y;
    sjt_and3 = sjt_compare3 == sjt_compare4;
    sjt_dot30 = _parent;
    sjt_compare5 = (sjt_dot30)->w;
    sjt_dot31 = rect;
    sjt_compare6 = (sjt_dot31)->w;
    sjt_and5 = sjt_compare5 == sjt_compare6;
    sjt_dot32 = _parent;
    sjt_compare7 = (sjt_dot32)->h;
    sjt_dot33 = rect;
    sjt_compare8 = (sjt_dot33)->h;
    sjt_and6 = sjt_compare7 == sjt_compare8;
    sjt_and4 = sjt_and5 && sjt_and6;
    sjt_and2 = sjt_and3 && sjt_and4;
    (*_return) = sjt_and1 && sjt_and2;
}

void sjf_rect_subtractmargin(sjs_rect* _parent, sjs_margin* margin, sjs_rect* _return) {
    sjs_rect* sjt_dot1604 = 0;
    sjs_margin* sjt_dot1605 = 0;
    sjs_rect* sjt_dot1606 = 0;
    sjs_margin* sjt_dot1607 = 0;
    sjs_rect* sjt_dot1608 = 0;
    sjs_margin* sjt_dot1609 = 0;
    sjs_margin* sjt_dot1610 = 0;
    sjs_rect* sjt_dot1611 = 0;
    sjs_margin* sjt_dot1612 = 0;
    sjs_margin* sjt_dot1613 = 0;
    int32_t sjt_math2403;
    int32_t sjt_math2404;
    int32_t sjt_math2405;
    int32_t sjt_math2406;
    int32_t sjt_math2407;
    int32_t sjt_math2408;
    int32_t sjt_math2409;
    int32_t sjt_math2410;
    int32_t sjt_math2411;
    int32_t sjt_math2412;
    int32_t sjt_math2413;
    int32_t sjt_math2414;

    _return->_refCount = 1;
    sjt_dot1604 = _parent;
    sjt_math2403 = (sjt_dot1604)->x;
    sjt_dot1605 = margin;
    sjt_math2404 = (sjt_dot1605)->l;
    _return->x = sjt_math2403 + sjt_math2404;
    sjt_dot1606 = _parent;
    sjt_math2405 = (sjt_dot1606)->y;
    sjt_dot1607 = margin;
    sjt_math2406 = (sjt_dot1607)->t;
    _return->y = sjt_math2405 + sjt_math2406;
    sjt_dot1608 = _parent;
    sjt_math2409 = (sjt_dot1608)->w;
    sjt_dot1609 = margin;
    sjt_math2410 = (sjt_dot1609)->l;
    sjt_math2407 = sjt_math2409 - sjt_math2410;
    sjt_dot1610 = margin;
    sjt_math2408 = (sjt_dot1610)->r;
    _return->w = sjt_math2407 - sjt_math2408;
    sjt_dot1611 = _parent;
    sjt_math2413 = (sjt_dot1611)->h;
    sjt_dot1612 = margin;
    sjt_math2414 = (sjt_dot1612)->t;
    sjt_math2411 = sjt_math2413 - sjt_math2414;
    sjt_dot1613 = margin;
    sjt_math2412 = (sjt_dot1613)->b;
    _return->h = sjt_math2411 - sjt_math2412;
    sjf_rect(_return);
}

void sjf_rect_subtractmargin_heap(sjs_rect* _parent, sjs_margin* margin, sjs_rect** _return) {
    sjs_rect* sjt_dot1614 = 0;
    sjs_margin* sjt_dot1615 = 0;
    sjs_rect* sjt_dot1616 = 0;
    sjs_margin* sjt_dot1617 = 0;
    sjs_rect* sjt_dot1618 = 0;
    sjs_margin* sjt_dot1619 = 0;
    sjs_margin* sjt_dot1620 = 0;
    sjs_rect* sjt_dot1621 = 0;
    sjs_margin* sjt_dot1622 = 0;
    sjs_margin* sjt_dot1623 = 0;
    int32_t sjt_math2415;
    int32_t sjt_math2416;
    int32_t sjt_math2417;
    int32_t sjt_math2418;
    int32_t sjt_math2419;
    int32_t sjt_math2420;
    int32_t sjt_math2421;
    int32_t sjt_math2422;
    int32_t sjt_math2423;
    int32_t sjt_math2424;
    int32_t sjt_math2425;
    int32_t sjt_math2426;

    (*_return) = (sjs_rect*)malloc(sizeof(sjs_rect));
    (*_return)->_refCount = 1;
    sjt_dot1614 = _parent;
    sjt_math2415 = (sjt_dot1614)->x;
    sjt_dot1615 = margin;
    sjt_math2416 = (sjt_dot1615)->l;
    (*_return)->x = sjt_math2415 + sjt_math2416;
    sjt_dot1616 = _parent;
    sjt_math2417 = (sjt_dot1616)->y;
    sjt_dot1617 = margin;
    sjt_math2418 = (sjt_dot1617)->t;
    (*_return)->y = sjt_math2417 + sjt_math2418;
    sjt_dot1618 = _parent;
    sjt_math2421 = (sjt_dot1618)->w;
    sjt_dot1619 = margin;
    sjt_math2422 = (sjt_dot1619)->l;
    sjt_math2419 = sjt_math2421 - sjt_math2422;
    sjt_dot1620 = margin;
    sjt_math2420 = (sjt_dot1620)->r;
    (*_return)->w = sjt_math2419 - sjt_math2420;
    sjt_dot1621 = _parent;
    sjt_math2425 = (sjt_dot1621)->h;
    sjt_dot1622 = margin;
    sjt_math2426 = (sjt_dot1622)->t;
    sjt_math2423 = sjt_math2425 - sjt_math2426;
    sjt_dot1623 = margin;
    sjt_math2424 = (sjt_dot1623)->b;
    (*_return)->h = sjt_math2423 - sjt_math2424;
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
}

void sjf_renderbuffer_heap(sjs_renderbuffer* _this) {
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

void sjf_scene2d_clear(sjs_scene2d* _parent) {
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
    glEnable( GL_TEXTURE_2D );
    glDisable( GL_DEPTH_TEST );
    sjf_scene2d_updateviewport(_parent);
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
}

void sjf_scene2d_destroy(sjs_scene2d* _this) {
}

void sjf_scene2d_heap(sjs_scene2d* _this) {
}

void sjf_scene2d_setsize(sjs_scene2d* _parent, sjs_size* size) {
    bool result19;
    sjs_scene2d* sjt_dot1411 = 0;
    sjs_size* sjt_functionParam344 = 0;
    bool sjt_ifElse22;
    bool sjt_not3;
    sjs_size* sjt_parent125 = 0;

    sjt_dot1411 = _parent;
    sjt_parent125 = &(sjt_dot1411)->_size;
    sjt_functionParam344 = size;
    sjf_size_isequal(sjt_parent125, sjt_functionParam344, &sjt_not3);
    result19 = !sjt_not3;
    sjt_ifElse22 = result19;
    if (sjt_ifElse22) {
        float result22;
        float result23;
        int32_t sjt_cast33;
        int32_t sjt_cast34;
        sjs_size* sjt_copy26 = 0;
        sjs_scene2d* sjt_dot1412 = 0;
        sjs_scene2d* sjt_dot1413 = 0;
        sjs_size* sjt_dot1414 = 0;
        sjs_scene2d* sjt_dot1415 = 0;
        sjs_size* sjt_dot1416 = 0;
        sjs_scene2d* sjt_dot1417 = 0;
        sjs_scene2d* sjt_dot1418 = 0;
        sjs_scene2d* sjt_dot1419 = 0;
        float sjt_functionParam345;
        float sjt_functionParam346;
        float sjt_functionParam347;
        float sjt_functionParam348;
        float sjt_functionParam349;
        float sjt_functionParam350;
        float sjt_functionParam351;
        float sjt_functionParam352;
        float sjt_functionParam353;
        int32_t sjt_math2289;
        int32_t sjt_math2290;
        float sjt_negate19;
        float sjt_negate20;

        sjt_dot1412 = _parent;
        sjt_copy26 = size;
        sjt_dot1412->_size._refCount = 1;
        sjf_size_copy(&sjt_dot1412->_size, sjt_copy26);
        sjt_dot1413 = _parent;
        sjt_functionParam345 = 0.0f;
        sjt_dot1415 = _parent;
        sjt_dot1414 = &(sjt_dot1415)->_size;
        sjt_cast33 = (sjt_dot1414)->w;
        sjt_functionParam346 = (float)sjt_cast33;
        sjt_math2289 = 0;
        sjt_dot1417 = _parent;
        sjt_dot1416 = &(sjt_dot1417)->_size;
        sjt_math2290 = (sjt_dot1416)->h;
        sjt_cast34 = sjt_math2289 - sjt_math2290;
        sjt_functionParam347 = (float)sjt_cast34;
        sjt_functionParam348 = 0.0f;
        sjt_negate19 = 1.0f;
        result22 = -sjt_negate19;
        sjt_functionParam349 = result22;
        sjt_functionParam350 = 1.0f;
        sjf_mat4_orthographic(sjt_functionParam345, sjt_functionParam346, sjt_functionParam347, sjt_functionParam348, sjt_functionParam349, sjt_functionParam350, &sjt_dot1413->projection);
        sjt_dot1418 = _parent;
        sjt_functionParam351 = 1.0f;
        sjt_negate20 = 1.0f;
        result23 = -sjt_negate20;
        sjt_functionParam352 = result23;
        sjt_functionParam353 = 1.0f;
        sjf_mat4_scale(sjt_functionParam351, sjt_functionParam352, sjt_functionParam353, &sjt_dot1418->model);
        sjt_dot1419 = _parent;
        sjf_mat4_identity(&sjt_dot1419->view);
    }
}

void sjf_scene2d_updateviewport(sjs_scene2d* _parent) {
    glViewport(0, 0, _parent->_size.w, _parent->_size.h);
}

void sjf_scene2dmodel(sjs_scene2dmodel* _this) {
    int32_t i;
    sjs_string sjt_call62 = { -1 };
    int32_t sjt_compare59;
    int32_t sjt_compare60;
    sjs_size* sjt_dot1420 = 0;
    sjs_size* sjt_dot1421 = 0;
    sjs_array_heap_iface_element* sjt_dot1422 = 0;
    int32_t sjt_forEnd20;
    int32_t sjt_forStart20;
    sjs_size* sjt_functionParam311 = 0;
    sjs_size* sjt_functionParam312 = 0;
    sjs_framebuffer* sjt_functionParam313 = 0;
    int32_t sjt_functionParam314;
    sjs_texture* sjt_functionParam315 = 0;
    int32_t sjt_functionParam316;
    int32_t sjt_functionParam317;
    int32_t sjt_functionParam318;
    int32_t sjt_functionParam319;
    int32_t sjt_functionParam320;
    int32_t sjt_functionParam321;
    int32_t sjt_functionParam322;
    int32_t sjt_functionParam323;
    int32_t sjt_functionParam324;
    int32_t sjt_functionParam325;
    int32_t sjt_functionParam326;
    int32_t sjt_functionParam327;
    int32_t sjt_functionParam328;
    int32_t sjt_functionParam329;
    int32_t sjt_functionParam330;
    sjs_size* sjt_functionParam331 = 0;
    int32_t sjt_functionParam332;
    void* sjt_functionParam333;
    int32_t sjt_functionParam334;
    int32_t sjt_functionParam335;
    sjs_texture* sjt_functionParam336 = 0;
    int32_t sjt_functionParam337;
    sjs_renderbuffer* sjt_functionParam338 = 0;
    int32_t sjt_functionParam339;
    sjs_size* sjt_functionParam340 = 0;
    int32_t sjt_functionParam341;
    sjs_renderbuffer* sjt_functionParam342 = 0;
    sjs_size* sjt_functionParam354 = 0;
    bool sjt_ifElse21;
    sjs_scene2d* sjt_parent126 = 0;
    sjs_rect sjv_rect = { -1 };
    int32_t sjv_status;

    sjt_functionParam311 = &_this->texturesize;
    sjf_glgentexture(sjt_functionParam311, &_this->_texture);
    sjt_functionParam312 = &_this->texturesize;
    sjf_glgenrenderbuffer(sjt_functionParam312, &_this->_renderbuffer);
    sjt_functionParam313 = &_this->_framebuffer;
    sjf_glbindframebuffer(sjt_functionParam313);
    sjt_functionParam314 = sjv_gltexture_gl_texture_2d;
    sjt_functionParam315 = &_this->_texture;
    sjf_glbindtexture(sjt_functionParam314, sjt_functionParam315);
    sjt_functionParam316 = sjv_gltexture_gl_texture_2d;
    sjt_functionParam317 = sjv_gltextureattribute_gl_texture_wrap_s;
    sjt_functionParam318 = sjv_gltexturevalue_gl_clamp_to_edge;
    sjf_gltexparameteri(sjt_functionParam316, sjt_functionParam317, sjt_functionParam318);
    sjt_functionParam319 = sjv_gltexture_gl_texture_2d;
    sjt_functionParam320 = sjv_gltextureattribute_gl_texture_wrap_t;
    sjt_functionParam321 = sjv_gltexturevalue_gl_clamp_to_edge;
    sjf_gltexparameteri(sjt_functionParam319, sjt_functionParam320, sjt_functionParam321);
    sjt_functionParam322 = sjv_gltexture_gl_texture_2d;
    sjt_functionParam323 = sjv_gltextureattribute_gl_texture_min_filter;
    sjt_functionParam324 = sjv_gltexturevalue_gl_nearest;
    sjf_gltexparameteri(sjt_functionParam322, sjt_functionParam323, sjt_functionParam324);
    sjt_functionParam325 = sjv_gltexture_gl_texture_2d;
    sjt_functionParam326 = sjv_gltextureattribute_gl_texture_mag_filter;
    sjt_functionParam327 = sjv_gltexturevalue_gl_nearest;
    sjf_gltexparameteri(sjt_functionParam325, sjt_functionParam326, sjt_functionParam327);
    sjt_functionParam328 = sjv_gltexture_gl_texture_2d;
    sjt_functionParam329 = 0;
    sjt_functionParam330 = sjv_gltextureformat_gl_rgba;
    sjt_functionParam331 = &_this->texturesize;
    sjt_functionParam332 = sjv_gltexturetype_gl_unsigned_byte;
    sjt_functionParam333 = 0;
    sjf_glteximage2d(sjt_functionParam328, sjt_functionParam329, sjt_functionParam330, sjt_functionParam331, sjt_functionParam332, sjt_functionParam333);
    sjt_functionParam334 = sjv_glframebufferattachment_gl_color_attachment0;
    sjt_functionParam335 = sjv_glframebuffertexture_gl_texture_2d;
    sjt_functionParam336 = &_this->_texture;
    sjt_functionParam337 = 0;
    sjf_glframebuffertexture2d(sjt_functionParam334, sjt_functionParam335, sjt_functionParam336, sjt_functionParam337);
    sjt_functionParam338 = &_this->_renderbuffer;
    sjf_glbindrenderbuffer(sjt_functionParam338);
    sjt_functionParam339 = sjv_glrenderbufferformat_gl_depth_component16;
    sjt_functionParam340 = &_this->texturesize;
    sjf_glrenderbufferstorage(sjt_functionParam339, sjt_functionParam340);
    sjt_functionParam341 = sjv_glframebufferattachment_gl_depth_attachment;
    sjt_functionParam342 = &_this->_renderbuffer;
    sjf_glframebufferrenderbuffer(sjt_functionParam341, sjt_functionParam342);
    sjf_glcheckframebufferstatus(&sjv_status);
    sjt_compare59 = sjv_status;
    sjt_compare60 = sjv_glframebufferstatus_gl_framebuffer_complete;
    sjt_ifElse21 = sjt_compare59 != sjt_compare60;
    if (sjt_ifElse21) {
        sjs_string* sjt_functionParam343 = 0;

        sjt_call62._refCount = 1;
        sjt_call62.count = 18;
        sjt_call62.data._refCount = 1;
        sjt_call62.data.datasize = 19;
        sjt_call62.data.data = (void*)sjg_string27;
        sjt_call62.data._isglobal = true;
        sjt_call62.data.count = 19;
        sjf_array_char(&sjt_call62.data);
        sjf_string(&sjt_call62);
        sjt_functionParam343 = &sjt_call62;
        sjf_halt(sjt_functionParam343);
    }

    sjt_parent126 = &_this->_innerscene;
    sjt_functionParam354 = &_this->texturesize;
    sjf_scene2d_setsize(sjt_parent126, sjt_functionParam354);
    sjv_rect._refCount = 1;
    sjv_rect.x = 0;
    sjv_rect.y = 0;
    sjt_dot1420 = &_this->texturesize;
    sjv_rect.w = (sjt_dot1420)->w;
    sjt_dot1421 = &_this->texturesize;
    sjv_rect.h = (sjt_dot1421)->h;
    sjf_rect(&sjv_rect);
    sjt_forStart20 = 0;
    sjt_dot1422 = &_this->children;
    sjt_forEnd20 = (sjt_dot1422)->count;
    i = sjt_forStart20;
    while (i < sjt_forEnd20) {
        int32_t sjt_functionParam355;
        sjs_rect* sjt_interfaceParam25 = 0;
        sjs_array_heap_iface_element* sjt_parent127 = 0;
        sji_element sjt_parent128 = { 0 };
        sji_element sjv_child = { 0 };

        sjt_parent127 = &_this->children;
        sjt_functionParam355 = i;
        sjf_array_heap_iface_element_getat_heap(sjt_parent127, sjt_functionParam355, &sjv_child);
        sjt_parent128 = sjv_child;
        sjt_interfaceParam25 = &sjv_rect;
        sjt_parent128._vtbl->setrect(sjt_parent128._parent, sjt_interfaceParam25);
        i++;

        if (sjv_child._parent != 0) {
            sjv_child._parent->_refCount--;
            if (sjv_child._parent->_refCount <= 0) {
                sjv_child._vtbl->destroy(sjv_child._parent);
            }
        }
    }

    if (sjt_call62._refCount == 1) { sjf_string_destroy(&sjt_call62); }
    if (sjv_rect._refCount == 1) { sjf_rect_destroy(&sjv_rect); }
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
    }

    _return->_parent = 0;
}

void sjf_scene2dmodel_copy(sjs_scene2dmodel* _this, sjs_scene2dmodel* _from) {
    _this->vertexbuffer._refCount = 1;
    sjf_vertexbuffer_vertex_location_texture_normal_copy(&_this->vertexbuffer, &_from->vertexbuffer);
    _this->shader._refCount = 1;
    sjf_shader_copy(&_this->shader, &_from->shader);
    _this->texturesize._refCount = 1;
    sjf_size_copy(&_this->texturesize, &_from->texturesize);
    _this->children._refCount = 1;
    sjf_array_heap_iface_element_copy(&_this->children, &_from->children);
    _this->hasalpha = _from->hasalpha;
    _this->center._refCount = 1;
    sjf_vec3_copy(&_this->center, &_from->center);
    _this->model._refCount = 1;
    sjf_mat4_copy(&_this->model, &_from->model);
    _this->_innerscene._refCount = 1;
    sjf_scene2d_copy(&_this->_innerscene, &_from->_innerscene);
    _this->_scenerect._refCount = 1;
    sjf_rect_copy(&_this->_scenerect, &_from->_scenerect);
    _this->_projection._refCount = 1;
    sjf_mat4_copy(&_this->_projection, &_from->_projection);
    _this->_world._refCount = 1;
    sjf_mat4_copy(&_this->_world, &_from->_world);
    _this->_view._refCount = 1;
    sjf_mat4_copy(&_this->_view, &_from->_view);
    _this->_light._refCount = 1;
    sjf_light_copy(&_this->_light, &_from->_light);
    _this->_projectedcenter._refCount = 1;
    sjf_vec4_copy(&_this->_projectedcenter, &_from->_projectedcenter);
    _this->_framebuffer._refCount = 1;
    sjf_framebuffer_copy(&_this->_framebuffer, &_from->_framebuffer);
    _this->_texture._refCount = 1;
    sjf_texture_copy(&_this->_texture, &_from->_texture);
    _this->_renderbuffer._refCount = 1;
    sjf_renderbuffer_copy(&_this->_renderbuffer, &_from->_renderbuffer);
}

void sjf_scene2dmodel_destroy(sjs_scene2dmodel* _this) {
}

void sjf_scene2dmodel_firemouseevent(sjs_scene2dmodel* _parent, sjs_mouseevent* mouseevent) {
    sjs_mat4 sjt_call78 = { -1 };
    sjs_scene2dmodel* sjt_dot1541 = 0;
    sjs_mouseevent* sjt_dot1542 = 0;
    sjs_scene2dmodel* sjt_dot1543 = 0;
    sjs_scene2dmodel* sjt_dot1544 = 0;
    sjs_scene2dmodel* sjt_dot1545 = 0;
    sjs_scene2dmodel* sjt_dot1546 = 0;
    sjs_scene2dmodel* sjt_dot1547 = 0;
    sjs_point* sjt_functionParam433 = 0;
    sjs_rect* sjt_functionParam434 = 0;
    sjs_mat4* sjt_functionParam435 = 0;
    sjs_mat4* sjt_functionParam436 = 0;
    sjs_mat4* sjt_functionParam437 = 0;
    sjs_mat4* sjt_functionParam438 = 0;
    bool sjt_isEmpty10;
    sjs_vec2* sjt_isEmpty11 = 0;
    sjs_vertexbuffer_vertex_location_texture_normal* sjt_parent180 = 0;
    sjs_mat4* sjt_parent181 = 0;
    sjs_vec2 sjv_texture = { -1 };

    sjt_dot1541 = _parent;
    sjt_parent180 = &(sjt_dot1541)->vertexbuffer;
    sjt_dot1542 = mouseevent;
    sjt_functionParam433 = &(sjt_dot1542)->point;
    sjt_dot1543 = _parent;
    sjt_functionParam434 = &(sjt_dot1543)->_scenerect;
    sjt_dot1544 = _parent;
    sjt_functionParam435 = &(sjt_dot1544)->_projection;
    sjt_dot1545 = _parent;
    sjt_functionParam436 = &(sjt_dot1545)->_view;
    sjt_dot1546 = _parent;
    sjt_parent181 = &(sjt_dot1546)->_world;
    sjt_dot1547 = _parent;
    sjt_functionParam438 = &(sjt_dot1547)->model;
    sjf_mat4_multiply(sjt_parent181, sjt_functionParam438, &sjt_call78);
    sjt_functionParam437 = &sjt_call78;
    sjf_vertexbuffer_vertex_location_texture_normal_translatescreentotexture(sjt_parent180, sjt_functionParam433, sjt_functionParam434, sjt_functionParam435, sjt_functionParam436, sjt_functionParam437, &sjv_texture);
    sjt_isEmpty11 = (sjv_texture._refCount != -1 ? &sjv_texture : 0);
    sjt_isEmpty10 = (sjt_isEmpty11 != 0);
    if (sjt_isEmpty10) {
        int32_t i;
        sjs_vec2* ifValue9 = 0;
        float sjt_cast40;
        int32_t sjt_cast41;
        float sjt_cast42;
        int32_t sjt_cast43;
        sjs_vec2* sjt_dot1548 = 0;
        sjs_size* sjt_dot1549 = 0;
        sjs_scene2dmodel* sjt_dot1550 = 0;
        sjs_size* sjt_dot1551 = 0;
        sjs_scene2dmodel* sjt_dot1552 = 0;
        sjs_vec2* sjt_dot1553 = 0;
        sjs_size* sjt_dot1554 = 0;
        sjs_scene2dmodel* sjt_dot1555 = 0;
        sjs_array_heap_iface_element* sjt_dot1556 = 0;
        sjs_scene2dmodel* sjt_dot1557 = 0;
        int32_t sjt_forEnd23;
        int32_t sjt_forStart23;
        float sjt_math2395;
        float sjt_math2396;
        int32_t sjt_math2397;
        int32_t sjt_math2398;
        int32_t sjt_math2399;
        int32_t sjt_math2400;
        float sjt_math2401;
        float sjt_math2402;
        sjs_point sjv_scenepoint = { -1 };

        ifValue9 = (sjv_texture._refCount != -1 ? &sjv_texture : 0);
        sjv_scenepoint._refCount = 1;
        sjt_dot1548 = ifValue9;
        sjt_math2395 = (sjt_dot1548)->x;
        sjt_dot1550 = _parent;
        sjt_dot1549 = &(sjt_dot1550)->texturesize;
        sjt_cast41 = (sjt_dot1549)->w;
        sjt_math2396 = (float)sjt_cast41;
        sjt_cast40 = sjt_math2395 * sjt_math2396;
        sjv_scenepoint.x = (int32_t)sjt_cast40;
        sjt_dot1552 = _parent;
        sjt_dot1551 = &(sjt_dot1552)->texturesize;
        sjt_math2399 = (sjt_dot1551)->h;
        sjt_math2400 = 1;
        sjt_math2397 = sjt_math2399 - sjt_math2400;
        sjt_dot1553 = ifValue9;
        sjt_math2401 = (sjt_dot1553)->y;
        sjt_dot1555 = _parent;
        sjt_dot1554 = &(sjt_dot1555)->texturesize;
        sjt_cast43 = (sjt_dot1554)->h;
        sjt_math2402 = (float)sjt_cast43;
        sjt_cast42 = sjt_math2401 * sjt_math2402;
        sjt_math2398 = (int32_t)sjt_cast42;
        sjv_scenepoint.y = sjt_math2397 - sjt_math2398;
        sjf_point(&sjv_scenepoint);
        sjt_forStart23 = 0;
        sjt_dot1557 = _parent;
        sjt_dot1556 = &(sjt_dot1557)->children;
        sjt_forEnd23 = (sjt_dot1556)->count;
        i = sjt_forStart23;
        while (i < sjt_forEnd23) {
            sjs_mouseevent sjt_call79 = { -1 };
            sjs_point* sjt_copy35 = 0;
            sjs_scene2dmodel* sjt_dot1558 = 0;
            sjs_mouseevent* sjt_dot1559 = 0;
            sjs_mouseevent* sjt_dot1560 = 0;
            int32_t sjt_functionParam439;
            sjs_mouseevent* sjt_interfaceParam27 = 0;
            sjs_array_heap_iface_element* sjt_parent182 = 0;
            sji_element sjt_parent183 = { 0 };
            sji_element sjv_child = { 0 };

            sjt_dot1558 = _parent;
            sjt_parent182 = &(sjt_dot1558)->children;
            sjt_functionParam439 = i;
            sjf_array_heap_iface_element_getat_heap(sjt_parent182, sjt_functionParam439, &sjv_child);
            sjt_parent183 = sjv_child;
            sjt_call79._refCount = 1;
            sjt_dot1559 = mouseevent;
            sjt_call79.type = (sjt_dot1559)->type;
            sjt_copy35 = &sjv_scenepoint;
            sjt_call79.point._refCount = 1;
            sjf_point_copy(&sjt_call79.point, sjt_copy35);
            sjt_dot1560 = mouseevent;
            sjt_call79.iscaptured = (sjt_dot1560)->iscaptured;
            sjf_mouseevent(&sjt_call79);
            sjt_interfaceParam27 = &sjt_call79;
            sjt_parent183._vtbl->firemouseevent(sjt_parent183._parent, sjt_interfaceParam27);
            i++;

            if (sjv_child._parent != 0) {
                sjv_child._parent->_refCount--;
                if (sjv_child._parent->_refCount <= 0) {
                    sjv_child._vtbl->destroy(sjv_child._parent);
                }
            }
            if (sjt_call79._refCount == 1) { sjf_mouseevent_destroy(&sjt_call79); }
        }

        if (sjv_scenepoint._refCount == 1) { sjf_point_destroy(&sjv_scenepoint); }
    }

    if (sjt_call78._refCount == 1) { sjf_mat4_destroy(&sjt_call78); }
    if (sjv_texture._refCount == 1) { sjf_vec2_destroy(&sjv_texture); }
}

void sjf_scene2dmodel_getz(sjs_scene2dmodel* _parent, float* _return) {
    sjs_vec4* sjt_dot1439 = 0;
    sjs_scene2dmodel* sjt_dot1440 = 0;

    sjt_dot1440 = _parent;
    sjt_dot1439 = &(sjt_dot1440)->_projectedcenter;
    (*_return) = (sjt_dot1439)->z;
}

void sjf_scene2dmodel_heap(sjs_scene2dmodel* _this) {
    int32_t i;
    sjs_string sjt_call80 = { -1 };
    int32_t sjt_compare100;
    int32_t sjt_compare99;
    sjs_size* sjt_dot1561 = 0;
    sjs_size* sjt_dot1562 = 0;
    sjs_array_heap_iface_element* sjt_dot1563 = 0;
    int32_t sjt_forEnd24;
    int32_t sjt_forStart24;
    sjs_size* sjt_functionParam440 = 0;
    sjs_size* sjt_functionParam441 = 0;
    sjs_framebuffer* sjt_functionParam442 = 0;
    int32_t sjt_functionParam443;
    sjs_texture* sjt_functionParam444 = 0;
    int32_t sjt_functionParam445;
    int32_t sjt_functionParam446;
    int32_t sjt_functionParam447;
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
    sjs_size* sjt_functionParam460 = 0;
    int32_t sjt_functionParam461;
    void* sjt_functionParam462;
    int32_t sjt_functionParam463;
    int32_t sjt_functionParam464;
    sjs_texture* sjt_functionParam465 = 0;
    int32_t sjt_functionParam466;
    sjs_renderbuffer* sjt_functionParam467 = 0;
    int32_t sjt_functionParam468;
    sjs_size* sjt_functionParam469 = 0;
    int32_t sjt_functionParam470;
    sjs_renderbuffer* sjt_functionParam471 = 0;
    sjs_size* sjt_functionParam473 = 0;
    bool sjt_ifElse41;
    sjs_scene2d* sjt_parent184 = 0;
    sjs_rect sjv_rect = { -1 };
    int32_t sjv_status;

    sjt_functionParam440 = &_this->texturesize;
    sjf_glgentexture(sjt_functionParam440, &_this->_texture);
    sjt_functionParam441 = &_this->texturesize;
    sjf_glgenrenderbuffer(sjt_functionParam441, &_this->_renderbuffer);
    sjt_functionParam442 = &_this->_framebuffer;
    sjf_glbindframebuffer(sjt_functionParam442);
    sjt_functionParam443 = sjv_gltexture_gl_texture_2d;
    sjt_functionParam444 = &_this->_texture;
    sjf_glbindtexture(sjt_functionParam443, sjt_functionParam444);
    sjt_functionParam445 = sjv_gltexture_gl_texture_2d;
    sjt_functionParam446 = sjv_gltextureattribute_gl_texture_wrap_s;
    sjt_functionParam447 = sjv_gltexturevalue_gl_clamp_to_edge;
    sjf_gltexparameteri(sjt_functionParam445, sjt_functionParam446, sjt_functionParam447);
    sjt_functionParam448 = sjv_gltexture_gl_texture_2d;
    sjt_functionParam449 = sjv_gltextureattribute_gl_texture_wrap_t;
    sjt_functionParam450 = sjv_gltexturevalue_gl_clamp_to_edge;
    sjf_gltexparameteri(sjt_functionParam448, sjt_functionParam449, sjt_functionParam450);
    sjt_functionParam451 = sjv_gltexture_gl_texture_2d;
    sjt_functionParam452 = sjv_gltextureattribute_gl_texture_min_filter;
    sjt_functionParam453 = sjv_gltexturevalue_gl_nearest;
    sjf_gltexparameteri(sjt_functionParam451, sjt_functionParam452, sjt_functionParam453);
    sjt_functionParam454 = sjv_gltexture_gl_texture_2d;
    sjt_functionParam455 = sjv_gltextureattribute_gl_texture_mag_filter;
    sjt_functionParam456 = sjv_gltexturevalue_gl_nearest;
    sjf_gltexparameteri(sjt_functionParam454, sjt_functionParam455, sjt_functionParam456);
    sjt_functionParam457 = sjv_gltexture_gl_texture_2d;
    sjt_functionParam458 = 0;
    sjt_functionParam459 = sjv_gltextureformat_gl_rgba;
    sjt_functionParam460 = &_this->texturesize;
    sjt_functionParam461 = sjv_gltexturetype_gl_unsigned_byte;
    sjt_functionParam462 = 0;
    sjf_glteximage2d(sjt_functionParam457, sjt_functionParam458, sjt_functionParam459, sjt_functionParam460, sjt_functionParam461, sjt_functionParam462);
    sjt_functionParam463 = sjv_glframebufferattachment_gl_color_attachment0;
    sjt_functionParam464 = sjv_glframebuffertexture_gl_texture_2d;
    sjt_functionParam465 = &_this->_texture;
    sjt_functionParam466 = 0;
    sjf_glframebuffertexture2d(sjt_functionParam463, sjt_functionParam464, sjt_functionParam465, sjt_functionParam466);
    sjt_functionParam467 = &_this->_renderbuffer;
    sjf_glbindrenderbuffer(sjt_functionParam467);
    sjt_functionParam468 = sjv_glrenderbufferformat_gl_depth_component16;
    sjt_functionParam469 = &_this->texturesize;
    sjf_glrenderbufferstorage(sjt_functionParam468, sjt_functionParam469);
    sjt_functionParam470 = sjv_glframebufferattachment_gl_depth_attachment;
    sjt_functionParam471 = &_this->_renderbuffer;
    sjf_glframebufferrenderbuffer(sjt_functionParam470, sjt_functionParam471);
    sjf_glcheckframebufferstatus(&sjv_status);
    sjt_compare99 = sjv_status;
    sjt_compare100 = sjv_glframebufferstatus_gl_framebuffer_complete;
    sjt_ifElse41 = sjt_compare99 != sjt_compare100;
    if (sjt_ifElse41) {
        sjs_string* sjt_functionParam472 = 0;

        sjt_call80._refCount = 1;
        sjt_call80.count = 18;
        sjt_call80.data._refCount = 1;
        sjt_call80.data.datasize = 19;
        sjt_call80.data.data = (void*)sjg_string28;
        sjt_call80.data._isglobal = true;
        sjt_call80.data.count = 19;
        sjf_array_char(&sjt_call80.data);
        sjf_string(&sjt_call80);
        sjt_functionParam472 = &sjt_call80;
        sjf_halt(sjt_functionParam472);
    }

    sjt_parent184 = &_this->_innerscene;
    sjt_functionParam473 = &_this->texturesize;
    sjf_scene2d_setsize(sjt_parent184, sjt_functionParam473);
    sjv_rect._refCount = 1;
    sjv_rect.x = 0;
    sjv_rect.y = 0;
    sjt_dot1561 = &_this->texturesize;
    sjv_rect.w = (sjt_dot1561)->w;
    sjt_dot1562 = &_this->texturesize;
    sjv_rect.h = (sjt_dot1562)->h;
    sjf_rect(&sjv_rect);
    sjt_forStart24 = 0;
    sjt_dot1563 = &_this->children;
    sjt_forEnd24 = (sjt_dot1563)->count;
    i = sjt_forStart24;
    while (i < sjt_forEnd24) {
        int32_t sjt_functionParam474;
        sjs_rect* sjt_interfaceParam28 = 0;
        sjs_array_heap_iface_element* sjt_parent185 = 0;
        sji_element sjt_parent186 = { 0 };
        sji_element sjv_child = { 0 };

        sjt_parent185 = &_this->children;
        sjt_functionParam474 = i;
        sjf_array_heap_iface_element_getat_heap(sjt_parent185, sjt_functionParam474, &sjv_child);
        sjt_parent186 = sjv_child;
        sjt_interfaceParam28 = &sjv_rect;
        sjt_parent186._vtbl->setrect(sjt_parent186._parent, sjt_interfaceParam28);
        i++;

        if (sjv_child._parent != 0) {
            sjv_child._parent->_refCount--;
            if (sjv_child._parent->_refCount <= 0) {
                sjv_child._vtbl->destroy(sjv_child._parent);
            }
        }
    }

    if (sjt_call80._refCount == 1) { sjf_string_destroy(&sjt_call80); }
    if (sjv_rect._refCount == 1) { sjf_rect_destroy(&sjv_rect); }
}

void sjf_scene2dmodel_heap_as_sji_model(sjs_scene2dmodel* _this, sji_model* _return) {
    _return->_parent = (sjs_object*)_this;
    _return->_vtbl = &sjs_scene2dmodel_model_vtbl;
}

void sjf_scene2dmodel_heap_asinterface(sjs_scene2dmodel* _this, int typeId, sjs_interface* _return) {
    switch (typeId) {
        case sji_model_typeId:  {
            sjf_scene2dmodel_heap_as_sji_model(_this, (sji_model*)_return);
            break;
        }
    }

    _return->_parent = 0;
}

void sjf_scene2dmodel_render(sjs_scene2dmodel* _parent) {
    int32_t i;
    sjs_mat4 sjt_call67 = { -1 };
    sjs_mat4 sjt_call68 = { -1 };
    sjs_string sjt_call69 = { -1 };
    sjs_string sjt_call70 = { -1 };
    sjs_string sjt_call71 = { -1 };
    sjs_string sjt_call72 = { -1 };
    sjs_string sjt_call73 = { -1 };
    sjs_vec3 sjt_call74 = { -1 };
    sjs_string sjt_call75 = { -1 };
    sjs_vec3 sjt_call76 = { -1 };
    sjs_scene2dmodel* sjt_dot1442 = 0;
    sjs_scene2dmodel* sjt_dot1443 = 0;
    sjs_array_heap_iface_element* sjt_dot1444 = 0;
    sjs_scene2dmodel* sjt_dot1445 = 0;
    sjs_scene2dmodel* sjt_dot1448 = 0;
    sjs_scene2dmodel* sjt_dot1449 = 0;
    sjs_scene2dmodel* sjt_dot1450 = 0;
    sjs_scene2dmodel* sjt_dot1451 = 0;
    sjs_scene2dmodel* sjt_dot1452 = 0;
    sjs_scene2dmodel* sjt_dot1453 = 0;
    sjs_scene2dmodel* sjt_dot1454 = 0;
    sjs_scene2dmodel* sjt_dot1455 = 0;
    sjs_scene2dmodel* sjt_dot1456 = 0;
    sjs_scene2dmodel* sjt_dot1457 = 0;
    sjs_scene2dmodel* sjt_dot1458 = 0;
    sjs_light* sjt_dot1459 = 0;
    sjs_scene2dmodel* sjt_dot1460 = 0;
    sjs_scene2dmodel* sjt_dot1461 = 0;
    sjs_light* sjt_dot1462 = 0;
    sjs_scene2dmodel* sjt_dot1463 = 0;
    sjs_scene2dmodel* sjt_dot1464 = 0;
    sjs_light* sjt_dot1465 = 0;
    sjs_scene2dmodel* sjt_dot1466 = 0;
    sjs_scene2dmodel* sjt_dot1467 = 0;
    int32_t sjt_forEnd21;
    int32_t sjt_forStart21;
    sjs_framebuffer* sjt_functionParam361 = 0;
    sjs_rect* sjt_functionParam363 = 0;
    int32_t sjt_functionParam364;
    sjs_mat4* sjt_functionParam365 = 0;
    sjs_mat4* sjt_functionParam366 = 0;
    sjs_shader* sjt_functionParam367 = 0;
    int32_t sjt_functionParam368;
    sjs_texture* sjt_functionParam369 = 0;
    int32_t sjt_functionParam370;
    sjs_shader* sjt_functionParam371 = 0;
    sjs_string* sjt_functionParam372 = 0;
    sjs_mat4* sjt_functionParam373 = 0;
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
    sjs_vec3* sjt_functionParam385 = 0;
    int32_t sjt_functionParam386;
    sjs_shader* sjt_functionParam387 = 0;
    sjs_string* sjt_functionParam388 = 0;
    sjs_vec3* sjt_functionParam389 = 0;
    int32_t sjt_functionParam390;
    sjs_shader* sjt_functionParam391 = 0;
    sjs_string* sjt_functionParam392 = 0;
    sjs_vec3* sjt_functionParam393 = 0;
    sjs_scene2d* sjt_parent134 = 0;
    sjs_mat4* sjt_parent137 = 0;
    sjs_mat4* sjt_parent138 = 0;
    sjs_mat4* sjt_parent139 = 0;
    sjs_mat4* sjt_parent140 = 0;
    sjs_color* sjt_parent141 = 0;
    sjs_color* sjt_parent142 = 0;
    sjs_vertexbuffer_vertex_location_texture_normal* sjt_parent143 = 0;
    sjs_mat4 sjv_normalmat = { -1 };
    sjs_mat4 sjv_viewworld = { -1 };

    sjt_dot1442 = _parent;
    sjt_functionParam361 = &(sjt_dot1442)->_framebuffer;
    sjf_glbindframebuffer(sjt_functionParam361);
    sjt_dot1443 = _parent;
    sjt_parent134 = &(sjt_dot1443)->_innerscene;
    sjf_scene2d_clear(sjt_parent134);
    sjt_forStart21 = 0;
    sjt_dot1445 = _parent;
    sjt_dot1444 = &(sjt_dot1445)->children;
    sjt_forEnd21 = (sjt_dot1444)->count;
    i = sjt_forStart21;
    while (i < sjt_forEnd21) {
        sjs_scene2dmodel* sjt_dot1446 = 0;
        sjs_scene2dmodel* sjt_dot1447 = 0;
        int32_t sjt_functionParam362;
        sjs_scene2d* sjt_interfaceParam26 = 0;
        sjs_array_heap_iface_element* sjt_parent135 = 0;
        sji_element sjt_parent136 = { 0 };
        sji_element sjv_child = { 0 };

        sjt_dot1446 = _parent;
        sjt_parent135 = &(sjt_dot1446)->children;
        sjt_functionParam362 = i;
        sjf_array_heap_iface_element_getat_heap(sjt_parent135, sjt_functionParam362, &sjv_child);
        sjt_parent136 = sjv_child;
        sjt_dot1447 = _parent;
        sjt_interfaceParam26 = &(sjt_dot1447)->_innerscene;
        sjt_parent136._vtbl->render(sjt_parent136._parent, sjt_interfaceParam26);
        i++;

        if (sjv_child._parent != 0) {
            sjv_child._parent->_refCount--;
            if (sjv_child._parent->_refCount <= 0) {
                sjv_child._vtbl->destroy(sjv_child._parent);
            }
        }
    }

    sjf_glunbindframebuffer();
    sjt_dot1448 = _parent;
    sjt_functionParam363 = &(sjt_dot1448)->_scenerect;
    sjf_glviewport(sjt_functionParam363);
    sjt_functionParam364 = sjv_glfeature_gl_depth_test;
    sjf_glenable(sjt_functionParam364);
    sjt_dot1449 = _parent;
    sjt_parent138 = &(sjt_dot1449)->_view;
    sjt_dot1450 = _parent;
    sjt_functionParam365 = &(sjt_dot1450)->_world;
    sjf_mat4_multiply(sjt_parent138, sjt_functionParam365, &sjt_call67);
    sjt_parent137 = &sjt_call67;
    sjt_dot1451 = _parent;
    sjt_functionParam366 = &(sjt_dot1451)->model;
    sjf_mat4_multiply(sjt_parent137, sjt_functionParam366, &sjv_viewworld);
    sjt_parent140 = &sjv_viewworld;
    sjf_mat4_invert(sjt_parent140, &sjt_call68);
    sjt_parent139 = &sjt_call68;
    sjf_mat4_transpose(sjt_parent139, &sjv_normalmat);
    sjt_dot1452 = _parent;
    sjt_functionParam367 = &(sjt_dot1452)->shader;
    sjf_gluseprogram(sjt_functionParam367);
    sjt_functionParam368 = sjv_gltexture_gl_texture_2d;
    sjt_dot1453 = _parent;
    sjt_functionParam369 = &(sjt_dot1453)->_texture;
    sjf_glbindtexture(sjt_functionParam368, sjt_functionParam369);
    sjt_dot1454 = _parent;
    sjt_functionParam371 = &(sjt_dot1454)->shader;
    sjt_call69._refCount = 1;
    sjt_call69.count = 9;
    sjt_call69.data._refCount = 1;
    sjt_call69.data.datasize = 10;
    sjt_call69.data.data = (void*)sjg_string113;
    sjt_call69.data._isglobal = true;
    sjt_call69.data.count = 10;
    sjf_array_char(&sjt_call69.data);
    sjf_string(&sjt_call69);
    sjt_functionParam372 = &sjt_call69;
    sjf_glgetuniformlocation(sjt_functionParam371, sjt_functionParam372, &sjt_functionParam370);
    sjt_functionParam373 = &sjv_viewworld;
    sjf_gluniformmat4(sjt_functionParam370, sjt_functionParam373);
    sjt_dot1455 = _parent;
    sjt_functionParam375 = &(sjt_dot1455)->shader;
    sjt_call70._refCount = 1;
    sjt_call70.count = 9;
    sjt_call70.data._refCount = 1;
    sjt_call70.data.datasize = 10;
    sjt_call70.data.data = (void*)sjg_string114;
    sjt_call70.data._isglobal = true;
    sjt_call70.data.count = 10;
    sjf_array_char(&sjt_call70.data);
    sjf_string(&sjt_call70);
    sjt_functionParam376 = &sjt_call70;
    sjf_glgetuniformlocation(sjt_functionParam375, sjt_functionParam376, &sjt_functionParam374);
    sjt_functionParam377 = &sjv_normalmat;
    sjf_gluniformmat4(sjt_functionParam374, sjt_functionParam377);
    sjt_dot1456 = _parent;
    sjt_functionParam379 = &(sjt_dot1456)->shader;
    sjt_call71._refCount = 1;
    sjt_call71.count = 10;
    sjt_call71.data._refCount = 1;
    sjt_call71.data.datasize = 11;
    sjt_call71.data.data = (void*)sjg_string115;
    sjt_call71.data._isglobal = true;
    sjt_call71.data.count = 11;
    sjf_array_char(&sjt_call71.data);
    sjf_string(&sjt_call71);
    sjt_functionParam380 = &sjt_call71;
    sjf_glgetuniformlocation(sjt_functionParam379, sjt_functionParam380, &sjt_functionParam378);
    sjt_dot1457 = _parent;
    sjt_functionParam381 = &(sjt_dot1457)->_projection;
    sjf_gluniformmat4(sjt_functionParam378, sjt_functionParam381);
    sjt_dot1458 = _parent;
    sjt_functionParam383 = &(sjt_dot1458)->shader;
    sjt_call72._refCount = 1;
    sjt_call72.count = 8;
    sjt_call72.data._refCount = 1;
    sjt_call72.data.datasize = 9;
    sjt_call72.data.data = (void*)sjg_string116;
    sjt_call72.data._isglobal = true;
    sjt_call72.data.count = 9;
    sjf_array_char(&sjt_call72.data);
    sjf_string(&sjt_call72);
    sjt_functionParam384 = &sjt_call72;
    sjf_glgetuniformlocation(sjt_functionParam383, sjt_functionParam384, &sjt_functionParam382);
    sjt_dot1460 = _parent;
    sjt_dot1459 = &(sjt_dot1460)->_light;
    sjt_functionParam385 = &(sjt_dot1459)->pos;
    sjf_gluniformvec3(sjt_functionParam382, sjt_functionParam385);
    sjt_dot1461 = _parent;
    sjt_functionParam387 = &(sjt_dot1461)->shader;
    sjt_call73._refCount = 1;
    sjt_call73.count = 12;
    sjt_call73.data._refCount = 1;
    sjt_call73.data.datasize = 13;
    sjt_call73.data.data = (void*)sjg_string117;
    sjt_call73.data._isglobal = true;
    sjt_call73.data.count = 13;
    sjf_array_char(&sjt_call73.data);
    sjf_string(&sjt_call73);
    sjt_functionParam388 = &sjt_call73;
    sjf_glgetuniformlocation(sjt_functionParam387, sjt_functionParam388, &sjt_functionParam386);
    sjt_dot1463 = _parent;
    sjt_dot1462 = &(sjt_dot1463)->_light;
    sjt_parent141 = &(sjt_dot1462)->diffusecolor;
    sjf_color_asvec3(sjt_parent141, &sjt_call74);
    sjt_functionParam389 = &sjt_call74;
    sjf_gluniformvec3(sjt_functionParam386, sjt_functionParam389);
    sjt_dot1464 = _parent;
    sjt_functionParam391 = &(sjt_dot1464)->shader;
    sjt_call75._refCount = 1;
    sjt_call75.count = 9;
    sjt_call75.data._refCount = 1;
    sjt_call75.data.datasize = 10;
    sjt_call75.data.data = (void*)sjg_string118;
    sjt_call75.data._isglobal = true;
    sjt_call75.data.count = 10;
    sjf_array_char(&sjt_call75.data);
    sjf_string(&sjt_call75);
    sjt_functionParam392 = &sjt_call75;
    sjf_glgetuniformlocation(sjt_functionParam391, sjt_functionParam392, &sjt_functionParam390);
    sjt_dot1466 = _parent;
    sjt_dot1465 = &(sjt_dot1466)->_light;
    sjt_parent142 = &(sjt_dot1465)->speccolor;
    sjf_color_asvec3(sjt_parent142, &sjt_call76);
    sjt_functionParam393 = &sjt_call76;
    sjf_gluniformvec3(sjt_functionParam390, sjt_functionParam393);
    sjt_dot1467 = _parent;
    sjt_parent143 = &(sjt_dot1467)->vertexbuffer;
    sjf_vertexbuffer_vertex_location_texture_normal_render(sjt_parent143);

    if (sjt_call67._refCount == 1) { sjf_mat4_destroy(&sjt_call67); }
    if (sjt_call68._refCount == 1) { sjf_mat4_destroy(&sjt_call68); }
    if (sjt_call69._refCount == 1) { sjf_string_destroy(&sjt_call69); }
    if (sjt_call70._refCount == 1) { sjf_string_destroy(&sjt_call70); }
    if (sjt_call71._refCount == 1) { sjf_string_destroy(&sjt_call71); }
    if (sjt_call72._refCount == 1) { sjf_string_destroy(&sjt_call72); }
    if (sjt_call73._refCount == 1) { sjf_string_destroy(&sjt_call73); }
    if (sjt_call74._refCount == 1) { sjf_vec3_destroy(&sjt_call74); }
    if (sjt_call75._refCount == 1) { sjf_string_destroy(&sjt_call75); }
    if (sjt_call76._refCount == 1) { sjf_vec3_destroy(&sjt_call76); }
    if (sjv_normalmat._refCount == 1) { sjf_mat4_destroy(&sjv_normalmat); }
    if (sjv_viewworld._refCount == 1) { sjf_mat4_destroy(&sjv_viewworld); }
}

void sjf_scene2dmodel_renderorqueue(sjs_scene2dmodel* _parent, sjs_list_local_iface_model* alphamodels) {
    sjs_scene2dmodel* sjt_dot1441 = 0;
    bool sjt_ifElse23;

    sjt_dot1441 = _parent;
    sjt_ifElse23 = (sjt_dot1441)->hasalpha;
    if (sjt_ifElse23) {
        sjs_scene2dmodel* sjt_cast35 = 0;
        sji_model sjt_functionParam360 = { 0 };
        sjs_list_local_iface_model* sjt_parent133 = 0;

        sjt_parent133 = alphamodels;
        sjt_cast35 = _parent;
        sjf_scene2dmodel_as_sji_model(sjt_cast35, &sjt_functionParam360);
        sjf_list_local_iface_model_add(sjt_parent133, sjt_functionParam360);
    } else {
        sjf_scene2dmodel_render(_parent);
    }
}

void sjf_scene2dmodel_update(sjs_scene2dmodel* _parent, sjs_rect* scenerect, sjs_mat4* projection, sjs_mat4* view, sjs_mat4* world, sjs_light* light) {
    sjs_mat4 sjt_call63 = { -1 };
    sjs_mat4 sjt_call64 = { -1 };
    sjs_mat4 sjt_call65 = { -1 };
    sjs_vec4 sjt_call66 = { -1 };
    sjs_rect* sjt_copy27 = 0;
    sjs_mat4* sjt_copy28 = 0;
    sjs_mat4* sjt_copy29 = 0;
    sjs_mat4* sjt_copy30 = 0;
    sjs_light* sjt_copy31 = 0;
    sjs_scene2dmodel* sjt_dot1423 = 0;
    sjs_scene2dmodel* sjt_dot1424 = 0;
    sjs_scene2dmodel* sjt_dot1425 = 0;
    sjs_scene2dmodel* sjt_dot1426 = 0;
    sjs_scene2dmodel* sjt_dot1427 = 0;
    sjs_scene2dmodel* sjt_dot1428 = 0;
    sjs_scene2dmodel* sjt_dot1429 = 0;
    sjs_scene2dmodel* sjt_dot1430 = 0;
    sjs_scene2dmodel* sjt_dot1431 = 0;
    sjs_scene2dmodel* sjt_dot1432 = 0;
    sjs_vec3* sjt_dot1433 = 0;
    sjs_scene2dmodel* sjt_dot1434 = 0;
    sjs_vec3* sjt_dot1435 = 0;
    sjs_scene2dmodel* sjt_dot1436 = 0;
    sjs_vec3* sjt_dot1437 = 0;
    sjs_scene2dmodel* sjt_dot1438 = 0;
    sjs_mat4* sjt_functionParam356 = 0;
    sjs_mat4* sjt_functionParam357 = 0;
    sjs_mat4* sjt_functionParam358 = 0;
    sjs_vec4* sjt_functionParam359 = 0;
    sjs_mat4* sjt_parent129 = 0;
    sjs_mat4* sjt_parent130 = 0;
    sjs_mat4* sjt_parent131 = 0;
    sjs_mat4* sjt_parent132 = 0;

    sjt_dot1423 = _parent;
    sjt_copy27 = scenerect;
    sjt_dot1423->_scenerect._refCount = 1;
    sjf_rect_copy(&sjt_dot1423->_scenerect, sjt_copy27);
    sjt_dot1424 = _parent;
    sjt_copy28 = projection;
    sjt_dot1424->_projection._refCount = 1;
    sjf_mat4_copy(&sjt_dot1424->_projection, sjt_copy28);
    sjt_dot1425 = _parent;
    sjt_copy29 = view;
    sjt_dot1425->_view._refCount = 1;
    sjf_mat4_copy(&sjt_dot1425->_view, sjt_copy29);
    sjt_dot1426 = _parent;
    sjt_copy30 = world;
    sjt_dot1426->_world._refCount = 1;
    sjf_mat4_copy(&sjt_dot1426->_world, sjt_copy30);
    sjt_dot1427 = _parent;
    sjt_copy31 = light;
    sjt_dot1427->_light._refCount = 1;
    sjf_light_copy(&sjt_dot1427->_light, sjt_copy31);
    sjt_dot1428 = _parent;
    sjt_dot1429 = _parent;
    sjt_parent132 = &(sjt_dot1429)->_projection;
    sjt_dot1430 = _parent;
    sjt_functionParam356 = &(sjt_dot1430)->_view;
    sjf_mat4_multiply(sjt_parent132, sjt_functionParam356, &sjt_call65);
    sjt_parent131 = &sjt_call65;
    sjt_dot1431 = _parent;
    sjt_functionParam357 = &(sjt_dot1431)->_world;
    sjf_mat4_multiply(sjt_parent131, sjt_functionParam357, &sjt_call64);
    sjt_parent130 = &sjt_call64;
    sjt_dot1432 = _parent;
    sjt_functionParam358 = &(sjt_dot1432)->model;
    sjf_mat4_multiply(sjt_parent130, sjt_functionParam358, &sjt_call63);
    sjt_parent129 = &sjt_call63;
    sjt_call66._refCount = 1;
    sjt_dot1434 = _parent;
    sjt_dot1433 = &(sjt_dot1434)->center;
    sjt_call66.x = (sjt_dot1433)->x;
    sjt_dot1436 = _parent;
    sjt_dot1435 = &(sjt_dot1436)->center;
    sjt_call66.y = (sjt_dot1435)->y;
    sjt_dot1438 = _parent;
    sjt_dot1437 = &(sjt_dot1438)->center;
    sjt_call66.z = (sjt_dot1437)->z;
    sjt_call66.w = 1.0f;
    sjf_vec4(&sjt_call66);
    sjt_functionParam359 = &sjt_call66;
    sjf_mat4_multiplyvec4(sjt_parent129, sjt_functionParam359, &sjt_dot1428->_projectedcenter);

    if (sjt_call63._refCount == 1) { sjf_mat4_destroy(&sjt_call63); }
    if (sjt_call64._refCount == 1) { sjf_mat4_destroy(&sjt_call64); }
    if (sjt_call65._refCount == 1) { sjf_mat4_destroy(&sjt_call65); }
    if (sjt_call66._refCount == 1) { sjf_vec4_destroy(&sjt_call66); }
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

void sjf_size_cap(sjs_size* _parent, sjs_size* maxsize, sjs_size* _return) {
    int32_t sjt_compare101;
    int32_t sjt_compare102;
    int32_t sjt_compare103;
    int32_t sjt_compare104;
    sjs_size* sjt_dot1564 = 0;
    sjs_size* sjt_dot1565 = 0;
    sjs_size* sjt_dot1568 = 0;
    sjs_size* sjt_dot1569 = 0;
    bool sjt_ifElse42;
    bool sjt_ifElse43;

    _return->_refCount = 1;
    sjt_dot1564 = _parent;
    sjt_compare101 = (sjt_dot1564)->w;
    sjt_dot1565 = maxsize;
    sjt_compare102 = (sjt_dot1565)->w;
    sjt_ifElse42 = sjt_compare101 < sjt_compare102;
    if (sjt_ifElse42) {
        sjs_size* sjt_dot1566 = 0;

        sjt_dot1566 = _parent;
        _return->w = (sjt_dot1566)->w;
    } else {
        sjs_size* sjt_dot1567 = 0;

        sjt_dot1567 = maxsize;
        _return->w = (sjt_dot1567)->w;
    }

    sjt_dot1568 = _parent;
    sjt_compare103 = (sjt_dot1568)->h;
    sjt_dot1569 = maxsize;
    sjt_compare104 = (sjt_dot1569)->h;
    sjt_ifElse43 = sjt_compare103 < sjt_compare104;
    if (sjt_ifElse43) {
        sjs_size* sjt_dot1570 = 0;

        sjt_dot1570 = _parent;
        _return->h = (sjt_dot1570)->h;
    } else {
        sjs_size* sjt_dot1571 = 0;

        sjt_dot1571 = maxsize;
        _return->h = (sjt_dot1571)->h;
    }

    sjf_size(_return);
}

void sjf_size_cap_heap(sjs_size* _parent, sjs_size* maxsize, sjs_size** _return) {
    int32_t sjt_compare105;
    int32_t sjt_compare106;
    int32_t sjt_compare107;
    int32_t sjt_compare108;
    sjs_size* sjt_dot1572 = 0;
    sjs_size* sjt_dot1573 = 0;
    sjs_size* sjt_dot1576 = 0;
    sjs_size* sjt_dot1577 = 0;
    bool sjt_ifElse44;
    bool sjt_ifElse45;

    (*_return) = (sjs_size*)malloc(sizeof(sjs_size));
    (*_return)->_refCount = 1;
    sjt_dot1572 = _parent;
    sjt_compare105 = (sjt_dot1572)->w;
    sjt_dot1573 = maxsize;
    sjt_compare106 = (sjt_dot1573)->w;
    sjt_ifElse44 = sjt_compare105 < sjt_compare106;
    if (sjt_ifElse44) {
        sjs_size* sjt_dot1574 = 0;

        sjt_dot1574 = _parent;
        (*_return)->w = (sjt_dot1574)->w;
    } else {
        sjs_size* sjt_dot1575 = 0;

        sjt_dot1575 = maxsize;
        (*_return)->w = (sjt_dot1575)->w;
    }

    sjt_dot1576 = _parent;
    sjt_compare107 = (sjt_dot1576)->h;
    sjt_dot1577 = maxsize;
    sjt_compare108 = (sjt_dot1577)->h;
    sjt_ifElse45 = sjt_compare107 < sjt_compare108;
    if (sjt_ifElse45) {
        sjs_size* sjt_dot1578 = 0;

        sjt_dot1578 = _parent;
        (*_return)->h = (sjt_dot1578)->h;
    } else {
        sjs_size* sjt_dot1579 = 0;

        sjt_dot1579 = maxsize;
        (*_return)->h = (sjt_dot1579)->h;
    }

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
    bool sjt_and7;
    bool sjt_and8;
    int32_t sjt_compare61;
    int32_t sjt_compare62;
    int32_t sjt_compare63;
    int32_t sjt_compare64;
    sjs_size* sjt_dot1407 = 0;
    sjs_size* sjt_dot1408 = 0;
    sjs_size* sjt_dot1409 = 0;
    sjs_size* sjt_dot1410 = 0;

    sjt_dot1407 = _parent;
    sjt_compare61 = (sjt_dot1407)->w;
    sjt_dot1408 = size;
    sjt_compare62 = (sjt_dot1408)->w;
    sjt_and7 = sjt_compare61 == sjt_compare62;
    sjt_dot1409 = _parent;
    sjt_compare63 = (sjt_dot1409)->h;
    sjt_dot1410 = size;
    sjt_compare64 = (sjt_dot1410)->h;
    sjt_and8 = sjt_compare63 == sjt_compare64;
    (*_return) = sjt_and7 && sjt_and8;
}

void sjf_string(sjs_string* _this) {
}

void sjf_string_add(sjs_string* _parent, sjs_string* item, sjs_string* _return) {
    int32_t sjt_compare51;
    int32_t sjt_compare52;
    sjs_string* sjt_dot1339 = 0;
    bool sjt_ifElse17;
    sjs_array_char sjv_newdata = { -1 };

    sjt_dot1339 = item;
    sjt_compare51 = (sjt_dot1339)->count;
    sjt_compare52 = 0;
    sjt_ifElse17 = sjt_compare51 == sjt_compare52;
    if (sjt_ifElse17) {
        sjs_array_char* sjt_copy18 = 0;
        sjs_string* sjt_dot1340 = 0;
        sjs_string* sjt_dot1341 = 0;

        _return->_refCount = 1;
        sjt_dot1340 = _parent;
        _return->count = (sjt_dot1340)->count;
        sjt_dot1341 = _parent;
        sjt_copy18 = &(sjt_dot1341)->data;
        _return->data._refCount = 1;
        sjf_array_char_copy(&_return->data, sjt_copy18);
        sjf_string(_return);
    } else {
        int32_t i;
        int32_t sjt_cast18;
        sjs_array_char* sjt_copy19 = 0;
        sjs_string* sjt_dot1344 = 0;
        sjs_string* sjt_dot1345 = 0;
        sjs_string* sjt_dot1346 = 0;
        sjs_string* sjt_dot1347 = 0;
        sjs_string* sjt_dot1349 = 0;
        int32_t sjt_forEnd10;
        int32_t sjt_forStart10;
        int32_t sjt_functionParam233;
        int32_t sjt_functionParam234;
        char sjt_functionParam235;
        int32_t sjt_functionParam237;
        int32_t sjt_functionParam241;
        char sjt_functionParam242;
        int32_t sjt_math2125;
        int32_t sjt_math2126;
        int32_t sjt_math2127;
        int32_t sjt_math2128;
        int32_t sjt_math2129;
        int32_t sjt_math2130;
        sjs_array_char* sjt_parent83 = 0;
        sjs_array_char* sjt_parent84 = 0;
        sjs_string* sjt_parent86 = 0;
        sjs_array_char* sjt_parent89 = 0;
        int32_t sjv_newcount;

        sjt_dot1344 = _parent;
        sjt_parent83 = &(sjt_dot1344)->data;
        sjt_dot1345 = _parent;
        sjt_math2127 = (sjt_dot1345)->count;
        sjt_dot1346 = item;
        sjt_math2128 = (sjt_dot1346)->count;
        sjt_math2125 = sjt_math2127 + sjt_math2128;
        sjt_math2126 = 1;
        sjt_functionParam233 = sjt_math2125 + sjt_math2126;
        sjf_array_char_grow(sjt_parent83, sjt_functionParam233, &sjv_newdata);
        sjt_dot1347 = _parent;
        sjv_newcount = (sjt_dot1347)->count;
        sjt_parent84 = &sjv_newdata;
        sjt_functionParam234 = sjv_newcount;
        sjt_parent86 = item;
        sjt_functionParam237 = 0;
        sjf_string_getat(sjt_parent86, sjt_functionParam237, &sjt_functionParam235);
        sjf_array_char_setat(sjt_parent84, sjt_functionParam234, sjt_functionParam235);
        sjt_math2129 = sjv_newcount;
        sjt_math2130 = 1;
        sjv_newcount = sjt_math2129 + sjt_math2130;
        sjt_forStart10 = 1;
        sjt_dot1349 = item;
        sjt_forEnd10 = (sjt_dot1349)->count;
        i = sjt_forStart10;
        while (i < sjt_forEnd10) {
            int32_t sjt_functionParam238;
            char sjt_functionParam239;
            int32_t sjt_functionParam240;
            int32_t sjt_math2131;
            int32_t sjt_math2132;
            sjs_array_char* sjt_parent87 = 0;
            sjs_string* sjt_parent88 = 0;

            sjt_parent87 = &sjv_newdata;
            sjt_functionParam238 = sjv_newcount;
            sjt_parent88 = item;
            sjt_functionParam240 = i;
            sjf_string_getat(sjt_parent88, sjt_functionParam240, &sjt_functionParam239);
            sjf_array_char_initat(sjt_parent87, sjt_functionParam238, sjt_functionParam239);
            sjt_math2131 = sjv_newcount;
            sjt_math2132 = 1;
            sjv_newcount = sjt_math2131 + sjt_math2132;
            i++;
        }

        sjt_parent89 = &sjv_newdata;
        sjt_functionParam241 = sjv_newcount;
        sjt_cast18 = 0;
        sjt_functionParam242 = (char)sjt_cast18;
        sjf_array_char_initat(sjt_parent89, sjt_functionParam241, sjt_functionParam242);
        _return->_refCount = 1;
        _return->count = sjv_newcount;
        sjt_copy19 = &sjv_newdata;
        _return->data._refCount = 1;
        sjf_array_char_copy(&_return->data, sjt_copy19);
        sjf_string(_return);
    }

    if (sjv_newdata._refCount == 1) { sjf_array_char_destroy(&sjv_newdata); }
}

void sjf_string_add_heap(sjs_string* _parent, sjs_string* item, sjs_string** _return) {
    int32_t sjt_compare53;
    int32_t sjt_compare54;
    sjs_string* sjt_dot1350 = 0;
    bool sjt_ifElse18;
    sjs_array_char sjv_newdata = { -1 };

    sjt_dot1350 = item;
    sjt_compare53 = (sjt_dot1350)->count;
    sjt_compare54 = 0;
    sjt_ifElse18 = sjt_compare53 == sjt_compare54;
    if (sjt_ifElse18) {
        sjs_array_char* sjt_copy20 = 0;
        sjs_string* sjt_dot1351 = 0;
        sjs_string* sjt_dot1352 = 0;

        (*_return) = (sjs_string*)malloc(sizeof(sjs_string));
        (*_return)->_refCount = 1;
        sjt_dot1351 = _parent;
        (*_return)->count = (sjt_dot1351)->count;
        sjt_dot1352 = _parent;
        sjt_copy20 = &(sjt_dot1352)->data;
        (*_return)->data._refCount = 1;
        sjf_array_char_copy(&(*_return)->data, sjt_copy20);
        sjf_string_heap((*_return));
    } else {
        int32_t i;
        int32_t sjt_cast19;
        sjs_array_char* sjt_copy21 = 0;
        sjs_string* sjt_dot1353 = 0;
        sjs_string* sjt_dot1354 = 0;
        sjs_string* sjt_dot1355 = 0;
        sjs_string* sjt_dot1356 = 0;
        sjs_string* sjt_dot1357 = 0;
        int32_t sjt_forEnd11;
        int32_t sjt_forStart11;
        int32_t sjt_functionParam243;
        int32_t sjt_functionParam244;
        char sjt_functionParam245;
        int32_t sjt_functionParam246;
        int32_t sjt_functionParam250;
        char sjt_functionParam251;
        int32_t sjt_math2133;
        int32_t sjt_math2134;
        int32_t sjt_math2135;
        int32_t sjt_math2136;
        int32_t sjt_math2137;
        int32_t sjt_math2138;
        sjs_array_char* sjt_parent90 = 0;
        sjs_array_char* sjt_parent91 = 0;
        sjs_string* sjt_parent92 = 0;
        sjs_array_char* sjt_parent95 = 0;
        int32_t sjv_newcount;

        sjt_dot1353 = _parent;
        sjt_parent90 = &(sjt_dot1353)->data;
        sjt_dot1354 = _parent;
        sjt_math2135 = (sjt_dot1354)->count;
        sjt_dot1355 = item;
        sjt_math2136 = (sjt_dot1355)->count;
        sjt_math2133 = sjt_math2135 + sjt_math2136;
        sjt_math2134 = 1;
        sjt_functionParam243 = sjt_math2133 + sjt_math2134;
        sjf_array_char_grow(sjt_parent90, sjt_functionParam243, &sjv_newdata);
        sjt_dot1356 = _parent;
        sjv_newcount = (sjt_dot1356)->count;
        sjt_parent91 = &sjv_newdata;
        sjt_functionParam244 = sjv_newcount;
        sjt_parent92 = item;
        sjt_functionParam246 = 0;
        sjf_string_getat(sjt_parent92, sjt_functionParam246, &sjt_functionParam245);
        sjf_array_char_setat(sjt_parent91, sjt_functionParam244, sjt_functionParam245);
        sjt_math2137 = sjv_newcount;
        sjt_math2138 = 1;
        sjv_newcount = sjt_math2137 + sjt_math2138;
        sjt_forStart11 = 1;
        sjt_dot1357 = item;
        sjt_forEnd11 = (sjt_dot1357)->count;
        i = sjt_forStart11;
        while (i < sjt_forEnd11) {
            int32_t sjt_functionParam247;
            char sjt_functionParam248;
            int32_t sjt_functionParam249;
            int32_t sjt_math2139;
            int32_t sjt_math2140;
            sjs_array_char* sjt_parent93 = 0;
            sjs_string* sjt_parent94 = 0;

            sjt_parent93 = &sjv_newdata;
            sjt_functionParam247 = sjv_newcount;
            sjt_parent94 = item;
            sjt_functionParam249 = i;
            sjf_string_getat(sjt_parent94, sjt_functionParam249, &sjt_functionParam248);
            sjf_array_char_initat(sjt_parent93, sjt_functionParam247, sjt_functionParam248);
            sjt_math2139 = sjv_newcount;
            sjt_math2140 = 1;
            sjv_newcount = sjt_math2139 + sjt_math2140;
            i++;
        }

        sjt_parent95 = &sjv_newdata;
        sjt_functionParam250 = sjv_newcount;
        sjt_cast19 = 0;
        sjt_functionParam251 = (char)sjt_cast19;
        sjf_array_char_initat(sjt_parent95, sjt_functionParam250, sjt_functionParam251);
        (*_return) = (sjs_string*)malloc(sizeof(sjs_string));
        (*_return)->_refCount = 1;
        (*_return)->count = sjv_newcount;
        sjt_copy21 = &sjv_newdata;
        (*_return)->data._refCount = 1;
        sjf_array_char_copy(&(*_return)->data, sjt_copy21);
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
    sjs_string* sjt_dot1348 = 0;
    int32_t sjt_functionParam236;
    sjs_array_char* sjt_parent85 = 0;

    sjt_dot1348 = _parent;
    sjt_parent85 = &(sjt_dot1348)->data;
    sjt_functionParam236 = index;
    sjf_array_char_getat(sjt_parent85, sjt_functionParam236, _return);
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
    sjs_array_char* sjt_functionParam1 = 0;
    sjs_array_char* sjt_parent1 = 0;

    sjt_dot1 = _parent;
    sjt_parent1 = &(sjt_dot1)->data;
    sjt_dot2 = test;
    sjt_functionParam1 = &(sjt_dot2)->data;
    sjf_array_char_isequal(sjt_parent1, sjt_functionParam1, _return);
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

void sjf_texture_getsize(sjs_texture* _parent, sjs_size* _return) {
    sjs_size* sjt_dot1631 = 0;
    sjs_texture* sjt_dot1632 = 0;
    sjs_size* sjt_dot1633 = 0;
    sjs_texture* sjt_dot1634 = 0;

    _return->_refCount = 1;
    sjt_dot1632 = _parent;
    sjt_dot1631 = &(sjt_dot1632)->size;
    _return->w = (sjt_dot1631)->w;
    sjt_dot1634 = _parent;
    sjt_dot1633 = &(sjt_dot1634)->size;
    _return->h = (sjt_dot1633)->h;
    sjf_size(_return);
}

void sjf_texture_getsize_heap(sjs_texture* _parent, sjs_size** _return) {
    sjs_size* sjt_dot1635 = 0;
    sjs_texture* sjt_dot1636 = 0;
    sjs_size* sjt_dot1637 = 0;
    sjs_texture* sjt_dot1638 = 0;

    (*_return) = (sjs_size*)malloc(sizeof(sjs_size));
    (*_return)->_refCount = 1;
    sjt_dot1636 = _parent;
    sjt_dot1635 = &(sjt_dot1636)->size;
    (*_return)->w = (sjt_dot1635)->w;
    sjt_dot1638 = _parent;
    sjt_dot1637 = &(sjt_dot1638)->size;
    (*_return)->h = (sjt_dot1637)->h;
    sjf_size_heap((*_return));
}

void sjf_texture_heap(sjs_texture* _this) {
}

void sjf_texturefrompng(sjs_string* filename, sjs_texture* _return) {
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

void sjf_texturefrompng_heap(sjs_string* filename, sjs_texture** _return) {
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

void sjf_vec2(sjs_vec2* _this) {
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
    sjs_vec3* sjt_dot100 = 0;
    sjs_vec3* sjt_dot95 = 0;
    sjs_vec3* sjt_dot96 = 0;
    sjs_vec3* sjt_dot97 = 0;
    sjs_vec3* sjt_dot98 = 0;
    sjs_vec3* sjt_dot99 = 0;
    float sjt_math59;
    float sjt_math60;
    float sjt_math61;
    float sjt_math62;
    float sjt_math63;
    float sjt_math64;

    _return->_refCount = 1;
    sjt_dot95 = _parent;
    sjt_math59 = (sjt_dot95)->x;
    sjt_dot96 = v;
    sjt_math60 = (sjt_dot96)->x;
    _return->x = sjt_math59 + sjt_math60;
    sjt_dot97 = _parent;
    sjt_math61 = (sjt_dot97)->y;
    sjt_dot98 = v;
    sjt_math62 = (sjt_dot98)->y;
    _return->y = sjt_math61 + sjt_math62;
    sjt_dot99 = _parent;
    sjt_math63 = (sjt_dot99)->z;
    sjt_dot100 = v;
    sjt_math64 = (sjt_dot100)->z;
    _return->z = sjt_math63 + sjt_math64;
    sjf_vec3(_return);
}

void sjf_vec3_add_heap(sjs_vec3* _parent, sjs_vec3* v, sjs_vec3** _return) {
    sjs_vec3* sjt_dot101 = 0;
    sjs_vec3* sjt_dot102 = 0;
    sjs_vec3* sjt_dot103 = 0;
    sjs_vec3* sjt_dot104 = 0;
    sjs_vec3* sjt_dot105 = 0;
    sjs_vec3* sjt_dot106 = 0;
    float sjt_math65;
    float sjt_math66;
    float sjt_math67;
    float sjt_math68;
    float sjt_math69;
    float sjt_math70;

    (*_return) = (sjs_vec3*)malloc(sizeof(sjs_vec3));
    (*_return)->_refCount = 1;
    sjt_dot101 = _parent;
    sjt_math65 = (sjt_dot101)->x;
    sjt_dot102 = v;
    sjt_math66 = (sjt_dot102)->x;
    (*_return)->x = sjt_math65 + sjt_math66;
    sjt_dot103 = _parent;
    sjt_math67 = (sjt_dot103)->y;
    sjt_dot104 = v;
    sjt_math68 = (sjt_dot104)->y;
    (*_return)->y = sjt_math67 + sjt_math68;
    sjt_dot105 = _parent;
    sjt_math69 = (sjt_dot105)->z;
    sjt_dot106 = v;
    sjt_math70 = (sjt_dot106)->z;
    (*_return)->z = sjt_math69 + sjt_math70;
    sjf_vec3_heap((*_return));
}

void sjf_vec3_copy(sjs_vec3* _this, sjs_vec3* _from) {
    _this->x = _from->x;
    _this->y = _from->y;
    _this->z = _from->z;
}

void sjf_vec3_cross(sjs_vec3* _parent, sjs_vec3* v, sjs_vec3* _return) {
    sjs_vec3* sjt_dot152 = 0;
    sjs_vec3* sjt_dot153 = 0;
    sjs_vec3* sjt_dot154 = 0;
    sjs_vec3* sjt_dot155 = 0;
    sjs_vec3* sjt_dot156 = 0;
    sjs_vec3* sjt_dot157 = 0;
    sjs_vec3* sjt_dot158 = 0;
    sjs_vec3* sjt_dot159 = 0;
    sjs_vec3* sjt_dot160 = 0;
    sjs_vec3* sjt_dot161 = 0;
    sjs_vec3* sjt_dot162 = 0;
    sjs_vec3* sjt_dot163 = 0;
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

    _return->_refCount = 1;
    sjt_dot152 = _parent;
    sjt_math129 = (sjt_dot152)->y;
    sjt_dot153 = v;
    sjt_math130 = (sjt_dot153)->z;
    sjt_math127 = sjt_math129 * sjt_math130;
    sjt_dot154 = _parent;
    sjt_math131 = (sjt_dot154)->z;
    sjt_dot155 = v;
    sjt_math132 = (sjt_dot155)->y;
    sjt_math128 = sjt_math131 * sjt_math132;
    _return->x = sjt_math127 - sjt_math128;
    sjt_dot156 = _parent;
    sjt_math135 = (sjt_dot156)->z;
    sjt_dot157 = v;
    sjt_math136 = (sjt_dot157)->x;
    sjt_math133 = sjt_math135 * sjt_math136;
    sjt_dot158 = _parent;
    sjt_math137 = (sjt_dot158)->x;
    sjt_dot159 = v;
    sjt_math138 = (sjt_dot159)->z;
    sjt_math134 = sjt_math137 * sjt_math138;
    _return->y = sjt_math133 - sjt_math134;
    sjt_dot160 = _parent;
    sjt_math141 = (sjt_dot160)->x;
    sjt_dot161 = v;
    sjt_math142 = (sjt_dot161)->y;
    sjt_math139 = sjt_math141 * sjt_math142;
    sjt_dot162 = _parent;
    sjt_math143 = (sjt_dot162)->y;
    sjt_dot163 = v;
    sjt_math144 = (sjt_dot163)->x;
    sjt_math140 = sjt_math143 * sjt_math144;
    _return->z = sjt_math139 - sjt_math140;
    sjf_vec3(_return);
}

void sjf_vec3_cross_heap(sjs_vec3* _parent, sjs_vec3* v, sjs_vec3** _return) {
    sjs_vec3* sjt_dot164 = 0;
    sjs_vec3* sjt_dot165 = 0;
    sjs_vec3* sjt_dot166 = 0;
    sjs_vec3* sjt_dot167 = 0;
    sjs_vec3* sjt_dot168 = 0;
    sjs_vec3* sjt_dot169 = 0;
    sjs_vec3* sjt_dot170 = 0;
    sjs_vec3* sjt_dot171 = 0;
    sjs_vec3* sjt_dot172 = 0;
    sjs_vec3* sjt_dot173 = 0;
    sjs_vec3* sjt_dot174 = 0;
    sjs_vec3* sjt_dot175 = 0;
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

    (*_return) = (sjs_vec3*)malloc(sizeof(sjs_vec3));
    (*_return)->_refCount = 1;
    sjt_dot164 = _parent;
    sjt_math147 = (sjt_dot164)->y;
    sjt_dot165 = v;
    sjt_math148 = (sjt_dot165)->z;
    sjt_math145 = sjt_math147 * sjt_math148;
    sjt_dot166 = _parent;
    sjt_math149 = (sjt_dot166)->z;
    sjt_dot167 = v;
    sjt_math150 = (sjt_dot167)->y;
    sjt_math146 = sjt_math149 * sjt_math150;
    (*_return)->x = sjt_math145 - sjt_math146;
    sjt_dot168 = _parent;
    sjt_math153 = (sjt_dot168)->z;
    sjt_dot169 = v;
    sjt_math154 = (sjt_dot169)->x;
    sjt_math151 = sjt_math153 * sjt_math154;
    sjt_dot170 = _parent;
    sjt_math155 = (sjt_dot170)->x;
    sjt_dot171 = v;
    sjt_math156 = (sjt_dot171)->z;
    sjt_math152 = sjt_math155 * sjt_math156;
    (*_return)->y = sjt_math151 - sjt_math152;
    sjt_dot172 = _parent;
    sjt_math159 = (sjt_dot172)->x;
    sjt_dot173 = v;
    sjt_math160 = (sjt_dot173)->y;
    sjt_math157 = sjt_math159 * sjt_math160;
    sjt_dot174 = _parent;
    sjt_math161 = (sjt_dot174)->y;
    sjt_dot175 = v;
    sjt_math162 = (sjt_dot175)->x;
    sjt_math158 = sjt_math161 * sjt_math162;
    (*_return)->z = sjt_math157 - sjt_math158;
    sjf_vec3_heap((*_return));
}

void sjf_vec3_destroy(sjs_vec3* _this) {
}

void sjf_vec3_dot(sjs_vec3* _parent, sjs_vec3* v, float* _return) {
    sjs_vec3* sjt_dot185 = 0;
    sjs_vec3* sjt_dot186 = 0;
    sjs_vec3* sjt_dot187 = 0;
    sjs_vec3* sjt_dot188 = 0;
    sjs_vec3* sjt_dot189 = 0;
    sjs_vec3* sjt_dot190 = 0;
    float sjt_math165;
    float sjt_math166;
    float sjt_math167;
    float sjt_math168;
    float sjt_math169;
    float sjt_math170;
    float sjt_math171;
    float sjt_math172;
    float sjt_math173;
    float sjt_math174;

    sjt_dot185 = _parent;
    sjt_math169 = (sjt_dot185)->x;
    sjt_dot186 = v;
    sjt_math170 = (sjt_dot186)->x;
    sjt_math167 = sjt_math169 * sjt_math170;
    sjt_dot187 = _parent;
    sjt_math171 = (sjt_dot187)->y;
    sjt_dot188 = v;
    sjt_math172 = (sjt_dot188)->y;
    sjt_math168 = sjt_math171 * sjt_math172;
    sjt_math165 = sjt_math167 + sjt_math168;
    sjt_dot189 = _parent;
    sjt_math173 = (sjt_dot189)->z;
    sjt_dot190 = v;
    sjt_math174 = (sjt_dot190)->z;
    sjt_math166 = sjt_math173 * sjt_math174;
    (*_return) = sjt_math165 + sjt_math166;
}

void sjf_vec3_getrawsize(int32_t* _return) {
    int x = sizeof(float) * 3;
    (*_return) = x;
return;;
}

void sjf_vec3_heap(sjs_vec3* _this) {
}

void sjf_vec3_max(sjs_vec3* a, sjs_vec3* b, sjs_vec3* _return) {
    sjs_vec3* sjt_dot82 = 0;
    sjs_vec3* sjt_dot83 = 0;
    sjs_vec3* sjt_dot84 = 0;
    sjs_vec3* sjt_dot85 = 0;
    sjs_vec3* sjt_dot86 = 0;
    sjs_vec3* sjt_dot87 = 0;
    float sjt_functionParam67;
    float sjt_functionParam68;
    float sjt_functionParam69;
    float sjt_functionParam70;
    float sjt_functionParam71;
    float sjt_functionParam72;

    _return->_refCount = 1;
    sjt_dot82 = a;
    sjt_functionParam67 = (sjt_dot82)->x;
    sjt_dot83 = b;
    sjt_functionParam68 = (sjt_dot83)->x;
    sjf_f32_max(sjt_functionParam67, sjt_functionParam68, &_return->x);
    sjt_dot84 = a;
    sjt_functionParam69 = (sjt_dot84)->y;
    sjt_dot85 = b;
    sjt_functionParam70 = (sjt_dot85)->y;
    sjf_f32_max(sjt_functionParam69, sjt_functionParam70, &_return->y);
    sjt_dot86 = a;
    sjt_functionParam71 = (sjt_dot86)->z;
    sjt_dot87 = b;
    sjt_functionParam72 = (sjt_dot87)->z;
    sjf_f32_max(sjt_functionParam71, sjt_functionParam72, &_return->z);
    sjf_vec3(_return);
}

void sjf_vec3_max_heap(sjs_vec3* a, sjs_vec3* b, sjs_vec3** _return) {
    sjs_vec3* sjt_dot88 = 0;
    sjs_vec3* sjt_dot89 = 0;
    sjs_vec3* sjt_dot90 = 0;
    sjs_vec3* sjt_dot91 = 0;
    sjs_vec3* sjt_dot92 = 0;
    sjs_vec3* sjt_dot93 = 0;
    float sjt_functionParam73;
    float sjt_functionParam74;
    float sjt_functionParam75;
    float sjt_functionParam76;
    float sjt_functionParam77;
    float sjt_functionParam78;

    (*_return) = (sjs_vec3*)malloc(sizeof(sjs_vec3));
    (*_return)->_refCount = 1;
    sjt_dot88 = a;
    sjt_functionParam73 = (sjt_dot88)->x;
    sjt_dot89 = b;
    sjt_functionParam74 = (sjt_dot89)->x;
    sjf_f32_max(sjt_functionParam73, sjt_functionParam74, &(*_return)->x);
    sjt_dot90 = a;
    sjt_functionParam75 = (sjt_dot90)->y;
    sjt_dot91 = b;
    sjt_functionParam76 = (sjt_dot91)->y;
    sjf_f32_max(sjt_functionParam75, sjt_functionParam76, &(*_return)->y);
    sjt_dot92 = a;
    sjt_functionParam77 = (sjt_dot92)->z;
    sjt_dot93 = b;
    sjt_functionParam78 = (sjt_dot93)->z;
    sjf_f32_max(sjt_functionParam77, sjt_functionParam78, &(*_return)->z);
    sjf_vec3_heap((*_return));
}

void sjf_vec3_min(sjs_vec3* a, sjs_vec3* b, sjs_vec3* _return) {
    sjs_vec3* sjt_dot69 = 0;
    sjs_vec3* sjt_dot70 = 0;
    sjs_vec3* sjt_dot71 = 0;
    sjs_vec3* sjt_dot72 = 0;
    sjs_vec3* sjt_dot73 = 0;
    sjs_vec3* sjt_dot74 = 0;
    float sjt_functionParam53;
    float sjt_functionParam54;
    float sjt_functionParam55;
    float sjt_functionParam56;
    float sjt_functionParam57;
    float sjt_functionParam58;

    _return->_refCount = 1;
    sjt_dot69 = a;
    sjt_functionParam53 = (sjt_dot69)->x;
    sjt_dot70 = b;
    sjt_functionParam54 = (sjt_dot70)->x;
    sjf_f32_min(sjt_functionParam53, sjt_functionParam54, &_return->x);
    sjt_dot71 = a;
    sjt_functionParam55 = (sjt_dot71)->y;
    sjt_dot72 = b;
    sjt_functionParam56 = (sjt_dot72)->y;
    sjf_f32_min(sjt_functionParam55, sjt_functionParam56, &_return->y);
    sjt_dot73 = a;
    sjt_functionParam57 = (sjt_dot73)->z;
    sjt_dot74 = b;
    sjt_functionParam58 = (sjt_dot74)->z;
    sjf_f32_min(sjt_functionParam57, sjt_functionParam58, &_return->z);
    sjf_vec3(_return);
}

void sjf_vec3_min_heap(sjs_vec3* a, sjs_vec3* b, sjs_vec3** _return) {
    sjs_vec3* sjt_dot75 = 0;
    sjs_vec3* sjt_dot76 = 0;
    sjs_vec3* sjt_dot77 = 0;
    sjs_vec3* sjt_dot78 = 0;
    sjs_vec3* sjt_dot79 = 0;
    sjs_vec3* sjt_dot80 = 0;
    float sjt_functionParam59;
    float sjt_functionParam60;
    float sjt_functionParam61;
    float sjt_functionParam62;
    float sjt_functionParam63;
    float sjt_functionParam64;

    (*_return) = (sjs_vec3*)malloc(sizeof(sjs_vec3));
    (*_return)->_refCount = 1;
    sjt_dot75 = a;
    sjt_functionParam59 = (sjt_dot75)->x;
    sjt_dot76 = b;
    sjt_functionParam60 = (sjt_dot76)->x;
    sjf_f32_min(sjt_functionParam59, sjt_functionParam60, &(*_return)->x);
    sjt_dot77 = a;
    sjt_functionParam61 = (sjt_dot77)->y;
    sjt_dot78 = b;
    sjt_functionParam62 = (sjt_dot78)->y;
    sjf_f32_min(sjt_functionParam61, sjt_functionParam62, &(*_return)->y);
    sjt_dot79 = a;
    sjt_functionParam63 = (sjt_dot79)->z;
    sjt_dot80 = b;
    sjt_functionParam64 = (sjt_dot80)->z;
    sjf_f32_min(sjt_functionParam63, sjt_functionParam64, &(*_return)->z);
    sjf_vec3_heap((*_return));
}

void sjf_vec3_normalize(sjs_vec3* _parent, sjs_vec3* _return) {
    sjs_vec3* sjt_dot134 = 0;
    sjs_vec3* sjt_dot135 = 0;
    sjs_vec3* sjt_dot136 = 0;
    sjs_vec3* sjt_dot137 = 0;
    sjs_vec3* sjt_dot138 = 0;
    sjs_vec3* sjt_dot139 = 0;
    sjs_vec3* sjt_dot140 = 0;
    sjs_vec3* sjt_dot141 = 0;
    sjs_vec3* sjt_dot142 = 0;
    float sjt_functionParam84;
    float sjt_math100;
    float sjt_math101;
    float sjt_math102;
    float sjt_math103;
    float sjt_math104;
    float sjt_math105;
    float sjt_math106;
    float sjt_math107;
    float sjt_math108;
    float sjt_math109;
    float sjt_math110;
    float sjt_math95;
    float sjt_math96;
    float sjt_math97;
    float sjt_math98;
    float sjt_math99;
    float sjv_t;

    sjt_dot134 = _parent;
    sjt_math99 = (sjt_dot134)->x;
    sjt_dot135 = _parent;
    sjt_math100 = (sjt_dot135)->x;
    sjt_math97 = sjt_math99 * sjt_math100;
    sjt_dot136 = _parent;
    sjt_math101 = (sjt_dot136)->y;
    sjt_dot137 = _parent;
    sjt_math102 = (sjt_dot137)->y;
    sjt_math98 = sjt_math101 * sjt_math102;
    sjt_math95 = sjt_math97 + sjt_math98;
    sjt_dot138 = _parent;
    sjt_math103 = (sjt_dot138)->z;
    sjt_dot139 = _parent;
    sjt_math104 = (sjt_dot139)->z;
    sjt_math96 = sjt_math103 * sjt_math104;
    sjt_functionParam84 = sjt_math95 + sjt_math96;
    sjf_f32_sqrt(sjt_functionParam84, &sjv_t);
    _return->_refCount = 1;
    sjt_dot140 = _parent;
    sjt_math105 = (sjt_dot140)->x;
    sjt_math106 = sjv_t;
    _return->x = sjt_math105 / sjt_math106;
    sjt_dot141 = _parent;
    sjt_math107 = (sjt_dot141)->y;
    sjt_math108 = sjv_t;
    _return->y = sjt_math107 / sjt_math108;
    sjt_dot142 = _parent;
    sjt_math109 = (sjt_dot142)->z;
    sjt_math110 = sjv_t;
    _return->z = sjt_math109 / sjt_math110;
    sjf_vec3(_return);
}

void sjf_vec3_normalize_heap(sjs_vec3* _parent, sjs_vec3** _return) {
    sjs_vec3* sjt_dot143 = 0;
    sjs_vec3* sjt_dot144 = 0;
    sjs_vec3* sjt_dot145 = 0;
    sjs_vec3* sjt_dot146 = 0;
    sjs_vec3* sjt_dot147 = 0;
    sjs_vec3* sjt_dot148 = 0;
    sjs_vec3* sjt_dot149 = 0;
    sjs_vec3* sjt_dot150 = 0;
    sjs_vec3* sjt_dot151 = 0;
    float sjt_functionParam85;
    float sjt_math111;
    float sjt_math112;
    float sjt_math113;
    float sjt_math114;
    float sjt_math115;
    float sjt_math116;
    float sjt_math117;
    float sjt_math118;
    float sjt_math119;
    float sjt_math120;
    float sjt_math121;
    float sjt_math122;
    float sjt_math123;
    float sjt_math124;
    float sjt_math125;
    float sjt_math126;
    float sjv_t;

    sjt_dot143 = _parent;
    sjt_math115 = (sjt_dot143)->x;
    sjt_dot144 = _parent;
    sjt_math116 = (sjt_dot144)->x;
    sjt_math113 = sjt_math115 * sjt_math116;
    sjt_dot145 = _parent;
    sjt_math117 = (sjt_dot145)->y;
    sjt_dot146 = _parent;
    sjt_math118 = (sjt_dot146)->y;
    sjt_math114 = sjt_math117 * sjt_math118;
    sjt_math111 = sjt_math113 + sjt_math114;
    sjt_dot147 = _parent;
    sjt_math119 = (sjt_dot147)->z;
    sjt_dot148 = _parent;
    sjt_math120 = (sjt_dot148)->z;
    sjt_math112 = sjt_math119 * sjt_math120;
    sjt_functionParam85 = sjt_math111 + sjt_math112;
    sjf_f32_sqrt(sjt_functionParam85, &sjv_t);
    (*_return) = (sjs_vec3*)malloc(sizeof(sjs_vec3));
    (*_return)->_refCount = 1;
    sjt_dot149 = _parent;
    sjt_math121 = (sjt_dot149)->x;
    sjt_math122 = sjv_t;
    (*_return)->x = sjt_math121 / sjt_math122;
    sjt_dot150 = _parent;
    sjt_math123 = (sjt_dot150)->y;
    sjt_math124 = sjv_t;
    (*_return)->y = sjt_math123 / sjt_math124;
    sjt_dot151 = _parent;
    sjt_math125 = (sjt_dot151)->z;
    sjt_math126 = sjv_t;
    (*_return)->z = sjt_math125 / sjt_math126;
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
    sjs_vec3* sjt_dot120 = 0;
    sjs_vec3* sjt_dot121 = 0;
    sjs_vec3* sjt_dot122 = 0;
    sjs_vec3* sjt_dot123 = 0;
    sjs_vec3* sjt_dot124 = 0;
    sjs_vec3* sjt_dot125 = 0;
    float sjt_math83;
    float sjt_math84;
    float sjt_math85;
    float sjt_math86;
    float sjt_math87;
    float sjt_math88;

    _return->_refCount = 1;
    sjt_dot120 = _parent;
    sjt_math83 = (sjt_dot120)->x;
    sjt_dot121 = v;
    sjt_math84 = (sjt_dot121)->x;
    _return->x = sjt_math83 - sjt_math84;
    sjt_dot122 = _parent;
    sjt_math85 = (sjt_dot122)->y;
    sjt_dot123 = v;
    sjt_math86 = (sjt_dot123)->y;
    _return->y = sjt_math85 - sjt_math86;
    sjt_dot124 = _parent;
    sjt_math87 = (sjt_dot124)->z;
    sjt_dot125 = v;
    sjt_math88 = (sjt_dot125)->z;
    _return->z = sjt_math87 - sjt_math88;
    sjf_vec3(_return);
}

void sjf_vec3_subtract_heap(sjs_vec3* _parent, sjs_vec3* v, sjs_vec3** _return) {
    sjs_vec3* sjt_dot126 = 0;
    sjs_vec3* sjt_dot127 = 0;
    sjs_vec3* sjt_dot128 = 0;
    sjs_vec3* sjt_dot129 = 0;
    sjs_vec3* sjt_dot130 = 0;
    sjs_vec3* sjt_dot131 = 0;
    float sjt_math89;
    float sjt_math90;
    float sjt_math91;
    float sjt_math92;
    float sjt_math93;
    float sjt_math94;

    (*_return) = (sjs_vec3*)malloc(sizeof(sjs_vec3));
    (*_return)->_refCount = 1;
    sjt_dot126 = _parent;
    sjt_math89 = (sjt_dot126)->x;
    sjt_dot127 = v;
    sjt_math90 = (sjt_dot127)->x;
    (*_return)->x = sjt_math89 - sjt_math90;
    sjt_dot128 = _parent;
    sjt_math91 = (sjt_dot128)->y;
    sjt_dot129 = v;
    sjt_math92 = (sjt_dot129)->y;
    (*_return)->y = sjt_math91 - sjt_math92;
    sjt_dot130 = _parent;
    sjt_math93 = (sjt_dot130)->z;
    sjt_dot131 = v;
    sjt_math94 = (sjt_dot131)->z;
    (*_return)->z = sjt_math93 - sjt_math94;
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
}

void sjf_vertex_location_texture_normal_getrawsize(int32_t* _return) {
    int32_t sjt_math2099;
    int32_t sjt_math2100;
    int32_t sjt_math2101;
    int32_t sjt_math2102;

    sjf_vec3_getrawsize(&sjt_math2101);
    sjf_vec2_getrawsize(&sjt_math2102);
    sjt_math2099 = sjt_math2101 + sjt_math2102;
    sjf_vec3_getrawsize(&sjt_math2100);
    (*_return) = sjt_math2099 + sjt_math2100;
}

void sjf_vertex_location_texture_normal_heap(sjs_vertex_location_texture_normal* _this) {
}

void sjf_vertex_location_texture_normal_rawcopy(sjs_vertex_location_texture_normal* v, void* p, void** _return) {
    sjs_vertex_location_texture_normal* sjt_dot1325 = 0;
    sjs_vertex_location_texture_normal* sjt_dot1326 = 0;
    sjs_vertex_location_texture_normal* sjt_dot1327 = 0;
    sjs_vec3* sjt_functionParam150 = 0;
    void* sjt_functionParam151;
    sjs_vec2* sjt_functionParam152 = 0;
    void* sjt_functionParam153;
    sjs_vec3* sjt_functionParam154 = 0;
    void* sjt_functionParam155;

    sjt_dot1325 = v;
    sjt_functionParam150 = &(sjt_dot1325)->location;
    sjt_functionParam151 = p;
    sjf_vec3_rawcopy(sjt_functionParam150, sjt_functionParam151, &p);
    sjt_dot1326 = v;
    sjt_functionParam152 = &(sjt_dot1326)->texture;
    sjt_functionParam153 = p;
    sjf_vec2_rawcopy(sjt_functionParam152, sjt_functionParam153, &p);
    sjt_dot1327 = v;
    sjt_functionParam154 = &(sjt_dot1327)->normal;
    sjt_functionParam155 = p;
    sjf_vec3_rawcopy(sjt_functionParam154, sjt_functionParam155, &p);
    (*_return) = p;
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

void sjf_vertexbuffer_vertex_location_texture_normal_translatescreentotexture(sjs_vertexbuffer_vertex_location_texture_normal* _parent, sjs_point* screen, sjs_rect* viewport, sjs_mat4* projection, sjs_mat4* view, sjs_mat4* world, sjs_vec2* _return) {
    int32_t i;
    sjs_mat4 sjt_call77 = { -1 };
    int32_t sjt_cast36;
    int32_t sjt_cast37;
    int32_t sjt_cast38;
    int32_t sjt_cast39;
    int32_t sjt_compare65;
    int32_t sjt_compare66;
    sjs_vec3* sjt_copy32 = 0;
    sjs_point* sjt_dot1468 = 0;
    sjs_rect* sjt_dot1469 = 0;
    sjs_rect* sjt_dot1470 = 0;
    sjs_point* sjt_dot1471 = 0;
    sjs_rect* sjt_dot1472 = 0;
    sjs_rect* sjt_dot1473 = 0;
    sjs_vec2* sjt_dot1474 = 0;
    sjs_vec2* sjt_dot1475 = 0;
    sjs_vec2* sjt_dot1476 = 0;
    sjs_vec2* sjt_dot1477 = 0;
    sjs_vec4* sjt_dot1478 = 0;
    sjs_vec4* sjt_dot1479 = 0;
    sjs_vec4* sjt_dot1480 = 0;
    sjs_vec4* sjt_dot1481 = 0;
    sjs_vec4* sjt_dot1482 = 0;
    sjs_vec4* sjt_dot1483 = 0;
    sjs_vec4* sjt_dot1484 = 0;
    sjs_vec4* sjt_dot1485 = 0;
    sjs_vec4* sjt_dot1486 = 0;
    sjs_vec4* sjt_dot1487 = 0;
    sjs_vec4* sjt_dot1488 = 0;
    sjs_vec4* sjt_dot1489 = 0;
    sjs_array_i32* sjt_dot1490 = 0;
    sjs_vertexbuffer_vertex_location_texture_normal* sjt_dot1491 = 0;
    int32_t sjt_forEnd22;
    int32_t sjt_forStart22;
    sjs_mat4* sjt_functionParam394 = 0;
    sjs_mat4* sjt_functionParam395 = 0;
    sjs_vec4* sjt_functionParam396 = 0;
    sjs_vec4* sjt_functionParam397 = 0;
    sjs_vec3* sjt_functionParam398 = 0;
    bool sjt_ifElse24;
    bool sjt_ifElse40;
    sjs_vec2* sjt_isEmpty9 = 0;
    float sjt_math2291;
    float sjt_math2292;
    float sjt_math2293;
    float sjt_math2294;
    float sjt_math2295;
    float sjt_math2296;
    int32_t sjt_math2297;
    int32_t sjt_math2298;
    float sjt_math2299;
    float sjt_math2300;
    float sjt_math2301;
    float sjt_math2302;
    float sjt_math2303;
    float sjt_math2304;
    int32_t sjt_math2305;
    int32_t sjt_math2306;
    float sjt_math2307;
    float sjt_math2308;
    float sjt_math2309;
    float sjt_math2310;
    float sjt_math2311;
    float sjt_math2312;
    float sjt_math2313;
    float sjt_math2314;
    float sjt_math2315;
    float sjt_math2316;
    float sjt_math2317;
    float sjt_math2318;
    sjs_mat4* sjt_parent144 = 0;
    sjs_mat4* sjt_parent145 = 0;
    sjs_mat4* sjt_parent146 = 0;
    sjs_mat4* sjt_parent147 = 0;
    sjs_mat4* sjt_parent148 = 0;
    sjs_vec3* sjt_parent149 = 0;
    sjs_vec3* sjt_parent150 = 0;
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

    sjv_intersection._refCount = -1;
    sjv_texture._refCount = -1;
    sjv_start._refCount = 1;
    sjt_dot1468 = screen;
    sjt_math2297 = (sjt_dot1468)->x;
    sjt_dot1469 = viewport;
    sjt_math2298 = (sjt_dot1469)->x;
    sjt_cast36 = sjt_math2297 - sjt_math2298;
    sjt_math2295 = (float)sjt_cast36;
    sjt_dot1470 = viewport;
    sjt_cast37 = (sjt_dot1470)->w;
    sjt_math2296 = (float)sjt_cast37;
    sjt_math2293 = sjt_math2295 / sjt_math2296;
    sjt_math2294 = 2.0f;
    sjt_math2291 = sjt_math2293 * sjt_math2294;
    sjt_math2292 = 1.0f;
    sjv_start.x = sjt_math2291 - sjt_math2292;
    sjt_math2299 = 1.0f;
    sjt_dot1471 = screen;
    sjt_math2305 = (sjt_dot1471)->y;
    sjt_dot1472 = viewport;
    sjt_math2306 = (sjt_dot1472)->y;
    sjt_cast38 = sjt_math2305 - sjt_math2306;
    sjt_math2303 = (float)sjt_cast38;
    sjt_dot1473 = viewport;
    sjt_cast39 = (sjt_dot1473)->h;
    sjt_math2304 = (float)sjt_cast39;
    sjt_math2301 = sjt_math2303 / sjt_math2304;
    sjt_math2302 = 2.0f;
    sjt_math2300 = sjt_math2301 * sjt_math2302;
    sjv_start.y = sjt_math2299 - sjt_math2300;
    sjf_vec2(&sjv_start);
    sjv_vscreenorigin1._refCount = 1;
    sjt_dot1474 = &sjv_start;
    sjv_vscreenorigin1.x = (sjt_dot1474)->x;
    sjt_dot1475 = &sjv_start;
    sjv_vscreenorigin1.y = (sjt_dot1475)->y;
    sjv_vscreenorigin1.z = 0.0f;
    sjv_vscreenorigin1.w = 1.0f;
    sjf_vec4(&sjv_vscreenorigin1);
    sjv_vscreenorigin2._refCount = 1;
    sjt_dot1476 = &sjv_start;
    sjv_vscreenorigin2.x = (sjt_dot1476)->x;
    sjt_dot1477 = &sjv_start;
    sjv_vscreenorigin2.y = (sjt_dot1477)->y;
    sjv_vscreenorigin2.z = 1.0f;
    sjv_vscreenorigin2.w = 1.0f;
    sjf_vec4(&sjv_vscreenorigin2);
    sjt_parent145 = projection;
    sjt_functionParam394 = view;
    sjf_mat4_multiply(sjt_parent145, sjt_functionParam394, &sjt_call77);
    sjt_parent144 = &sjt_call77;
    sjt_functionParam395 = world;
    sjf_mat4_multiply(sjt_parent144, sjt_functionParam395, &sjv_all);
    sjt_parent146 = &sjv_all;
    sjf_mat4_invert(sjt_parent146, &sjv_allinverse);
    sjt_parent147 = &sjv_allinverse;
    sjt_functionParam396 = &sjv_vscreenorigin1;
    sjf_mat4_multiplyvec4(sjt_parent147, sjt_functionParam396, &sjv_vprojectedorigin1);
    sjt_parent148 = &sjv_allinverse;
    sjt_functionParam397 = &sjv_vscreenorigin2;
    sjf_mat4_multiplyvec4(sjt_parent148, sjt_functionParam397, &sjv_vprojectedorigin2);
    sjv_vflattenedorigin1._refCount = 1;
    sjt_dot1478 = &sjv_vprojectedorigin1;
    sjt_math2307 = (sjt_dot1478)->x;
    sjt_dot1479 = &sjv_vprojectedorigin1;
    sjt_math2308 = (sjt_dot1479)->w;
    sjv_vflattenedorigin1.x = sjt_math2307 / sjt_math2308;
    sjt_dot1480 = &sjv_vprojectedorigin1;
    sjt_math2309 = (sjt_dot1480)->y;
    sjt_dot1481 = &sjv_vprojectedorigin1;
    sjt_math2310 = (sjt_dot1481)->w;
    sjv_vflattenedorigin1.y = sjt_math2309 / sjt_math2310;
    sjt_dot1482 = &sjv_vprojectedorigin1;
    sjt_math2311 = (sjt_dot1482)->z;
    sjt_dot1483 = &sjv_vprojectedorigin1;
    sjt_math2312 = (sjt_dot1483)->w;
    sjv_vflattenedorigin1.z = sjt_math2311 / sjt_math2312;
    sjf_vec3(&sjv_vflattenedorigin1);
    sjv_vflattenedorigin2._refCount = 1;
    sjt_dot1484 = &sjv_vprojectedorigin2;
    sjt_math2313 = (sjt_dot1484)->x;
    sjt_dot1485 = &sjv_vprojectedorigin2;
    sjt_math2314 = (sjt_dot1485)->w;
    sjv_vflattenedorigin2.x = sjt_math2313 / sjt_math2314;
    sjt_dot1486 = &sjv_vprojectedorigin2;
    sjt_math2315 = (sjt_dot1486)->y;
    sjt_dot1487 = &sjv_vprojectedorigin2;
    sjt_math2316 = (sjt_dot1487)->w;
    sjv_vflattenedorigin2.y = sjt_math2315 / sjt_math2316;
    sjt_dot1488 = &sjv_vprojectedorigin2;
    sjt_math2317 = (sjt_dot1488)->z;
    sjt_dot1489 = &sjv_vprojectedorigin2;
    sjt_math2318 = (sjt_dot1489)->w;
    sjv_vflattenedorigin2.z = sjt_math2317 / sjt_math2318;
    sjf_vec3(&sjv_vflattenedorigin2);
    sjt_parent149 = &sjv_vflattenedorigin2;
    sjt_functionParam398 = &sjv_vflattenedorigin1;
    sjf_vec3_subtract(sjt_parent149, sjt_functionParam398, &sjv_vflatteneddir);
    sjt_copy32 = &sjv_vflattenedorigin1;
    sjv_vpickrayorig._refCount = 1;
    sjf_vec3_copy(&sjv_vpickrayorig, sjt_copy32);
    sjt_parent150 = &sjv_vflatteneddir;
    sjf_vec3_normalize(sjt_parent150, &sjv_vpickraydir);
    sjt_dot1491 = _parent;
    sjt_dot1490 = &(sjt_dot1491)->indices;
    sjt_compare65 = (sjt_dot1490)->count;
    sjt_compare66 = 0;
    sjt_ifElse24 = sjt_compare65 > sjt_compare66;
    if (sjt_ifElse24) {
        sjs_array_i32* sjt_dot1492 = 0;
        sjs_vertexbuffer_vertex_location_texture_normal* sjt_dot1493 = 0;
        int32_t sjt_math2319;
        int32_t sjt_math2320;

        sjt_dot1493 = _parent;
        sjt_dot1492 = &(sjt_dot1493)->indices;
        sjt_math2319 = (sjt_dot1492)->count;
        sjt_math2320 = 3;
        sjv_ctriangles = sjt_math2319 / sjt_math2320;
    } else {
        sjs_array_vertex_location_texture_normal* sjt_dot1494 = 0;
        sjs_vertexbuffer_vertex_location_texture_normal* sjt_dot1495 = 0;
        int32_t sjt_math2321;
        int32_t sjt_math2322;

        sjt_dot1495 = _parent;
        sjt_dot1494 = &(sjt_dot1495)->vertices;
        sjt_math2321 = (sjt_dot1494)->count;
        sjt_math2322 = 3;
        sjv_ctriangles = sjt_math2321 / sjt_math2322;
    }

    sjt_forStart22 = 0;
    sjt_forEnd22 = sjv_ctriangles;
    i = sjt_forStart22;
    while (i < sjt_forEnd22) {
        int32_t sjt_compare67;
        int32_t sjt_compare68;
        int32_t sjt_compare69;
        int32_t sjt_compare70;
        int32_t sjt_compare71;
        int32_t sjt_compare72;
        sjs_array_i32* sjt_dot1496 = 0;
        sjs_vertexbuffer_vertex_location_texture_normal* sjt_dot1497 = 0;
        sjs_array_i32* sjt_dot1501 = 0;
        sjs_vertexbuffer_vertex_location_texture_normal* sjt_dot1502 = 0;
        sjs_array_i32* sjt_dot1506 = 0;
        sjs_vertexbuffer_vertex_location_texture_normal* sjt_dot1507 = 0;
        sjs_vertex_location_texture_normal* sjt_dot1511 = 0;
        sjs_vertex_location_texture_normal* sjt_dot1512 = 0;
        sjs_vertex_location_texture_normal* sjt_dot1513 = 0;
        sjs_vec3* sjt_functionParam428 = 0;
        sjs_vec3* sjt_functionParam429 = 0;
        sjs_vec3* sjt_functionParam430 = 0;
        sjs_vec3* sjt_functionParam431 = 0;
        sjs_vec3* sjt_functionParam432 = 0;
        bool sjt_ifElse25;
        bool sjt_ifElse26;
        bool sjt_ifElse27;
        bool sjt_isEmpty3;
        sjs_vec3* sjt_isEmpty4 = 0;
        sjs_vec3 sjv_result = { -1 };
        sjs_vertex_location_texture_normal sjv_vertex0 = { -1 };
        sjs_vertex_location_texture_normal sjv_vertex1 = { -1 };
        sjs_vertex_location_texture_normal sjv_vertex2 = { -1 };

        sjt_dot1497 = _parent;
        sjt_dot1496 = &(sjt_dot1497)->indices;
        sjt_compare67 = (sjt_dot1496)->count;
        sjt_compare68 = 0;
        sjt_ifElse25 = sjt_compare67 > sjt_compare68;
        if (sjt_ifElse25) {
            sjs_vertexbuffer_vertex_location_texture_normal* sjt_dot1498 = 0;
            sjs_vertexbuffer_vertex_location_texture_normal* sjt_dot1499 = 0;
            int32_t sjt_functionParam399;
            int32_t sjt_functionParam400;
            int32_t sjt_math2323;
            int32_t sjt_math2324;
            int32_t sjt_math2325;
            int32_t sjt_math2326;
            sjs_array_vertex_location_texture_normal* sjt_parent151 = 0;
            sjs_array_i32* sjt_parent152 = 0;

            sjt_dot1498 = _parent;
            sjt_parent151 = &(sjt_dot1498)->vertices;
            sjt_dot1499 = _parent;
            sjt_parent152 = &(sjt_dot1499)->indices;
            sjt_math2325 = i;
            sjt_math2326 = 3;
            sjt_math2323 = sjt_math2325 * sjt_math2326;
            sjt_math2324 = 0;
            sjt_functionParam400 = sjt_math2323 + sjt_math2324;
            sjf_array_i32_getat(sjt_parent152, sjt_functionParam400, &sjt_functionParam399);
            sjf_array_vertex_location_texture_normal_getat(sjt_parent151, sjt_functionParam399, &sjv_vertex0);
        } else {
            sjs_vertexbuffer_vertex_location_texture_normal* sjt_dot1500 = 0;
            int32_t sjt_functionParam401;
            int32_t sjt_math2327;
            int32_t sjt_math2328;
            int32_t sjt_math2329;
            int32_t sjt_math2330;
            sjs_array_vertex_location_texture_normal* sjt_parent153 = 0;

            sjt_dot1500 = _parent;
            sjt_parent153 = &(sjt_dot1500)->vertices;
            sjt_math2329 = i;
            sjt_math2330 = 3;
            sjt_math2327 = sjt_math2329 * sjt_math2330;
            sjt_math2328 = 0;
            sjt_functionParam401 = sjt_math2327 + sjt_math2328;
            sjf_array_vertex_location_texture_normal_getat(sjt_parent153, sjt_functionParam401, &sjv_vertex0);
        }

        sjt_dot1502 = _parent;
        sjt_dot1501 = &(sjt_dot1502)->indices;
        sjt_compare69 = (sjt_dot1501)->count;
        sjt_compare70 = 0;
        sjt_ifElse26 = sjt_compare69 > sjt_compare70;
        if (sjt_ifElse26) {
            sjs_vertexbuffer_vertex_location_texture_normal* sjt_dot1503 = 0;
            sjs_vertexbuffer_vertex_location_texture_normal* sjt_dot1504 = 0;
            int32_t sjt_functionParam402;
            int32_t sjt_functionParam403;
            int32_t sjt_math2331;
            int32_t sjt_math2332;
            int32_t sjt_math2333;
            int32_t sjt_math2334;
            sjs_array_vertex_location_texture_normal* sjt_parent154 = 0;
            sjs_array_i32* sjt_parent155 = 0;

            sjt_dot1503 = _parent;
            sjt_parent154 = &(sjt_dot1503)->vertices;
            sjt_dot1504 = _parent;
            sjt_parent155 = &(sjt_dot1504)->indices;
            sjt_math2333 = i;
            sjt_math2334 = 3;
            sjt_math2331 = sjt_math2333 * sjt_math2334;
            sjt_math2332 = 1;
            sjt_functionParam403 = sjt_math2331 + sjt_math2332;
            sjf_array_i32_getat(sjt_parent155, sjt_functionParam403, &sjt_functionParam402);
            sjf_array_vertex_location_texture_normal_getat(sjt_parent154, sjt_functionParam402, &sjv_vertex1);
        } else {
            sjs_vertexbuffer_vertex_location_texture_normal* sjt_dot1505 = 0;
            int32_t sjt_functionParam404;
            int32_t sjt_math2335;
            int32_t sjt_math2336;
            int32_t sjt_math2337;
            int32_t sjt_math2338;
            sjs_array_vertex_location_texture_normal* sjt_parent156 = 0;

            sjt_dot1505 = _parent;
            sjt_parent156 = &(sjt_dot1505)->vertices;
            sjt_math2337 = i;
            sjt_math2338 = 3;
            sjt_math2335 = sjt_math2337 * sjt_math2338;
            sjt_math2336 = 1;
            sjt_functionParam404 = sjt_math2335 + sjt_math2336;
            sjf_array_vertex_location_texture_normal_getat(sjt_parent156, sjt_functionParam404, &sjv_vertex1);
        }

        sjt_dot1507 = _parent;
        sjt_dot1506 = &(sjt_dot1507)->indices;
        sjt_compare71 = (sjt_dot1506)->count;
        sjt_compare72 = 0;
        sjt_ifElse27 = sjt_compare71 > sjt_compare72;
        if (sjt_ifElse27) {
            sjs_vertexbuffer_vertex_location_texture_normal* sjt_dot1508 = 0;
            sjs_vertexbuffer_vertex_location_texture_normal* sjt_dot1509 = 0;
            int32_t sjt_functionParam405;
            int32_t sjt_functionParam406;
            int32_t sjt_math2339;
            int32_t sjt_math2340;
            int32_t sjt_math2341;
            int32_t sjt_math2342;
            sjs_array_vertex_location_texture_normal* sjt_parent157 = 0;
            sjs_array_i32* sjt_parent158 = 0;

            sjt_dot1508 = _parent;
            sjt_parent157 = &(sjt_dot1508)->vertices;
            sjt_dot1509 = _parent;
            sjt_parent158 = &(sjt_dot1509)->indices;
            sjt_math2341 = i;
            sjt_math2342 = 3;
            sjt_math2339 = sjt_math2341 * sjt_math2342;
            sjt_math2340 = 2;
            sjt_functionParam406 = sjt_math2339 + sjt_math2340;
            sjf_array_i32_getat(sjt_parent158, sjt_functionParam406, &sjt_functionParam405);
            sjf_array_vertex_location_texture_normal_getat(sjt_parent157, sjt_functionParam405, &sjv_vertex2);
        } else {
            sjs_vertexbuffer_vertex_location_texture_normal* sjt_dot1510 = 0;
            int32_t sjt_functionParam407;
            int32_t sjt_math2343;
            int32_t sjt_math2344;
            int32_t sjt_math2345;
            int32_t sjt_math2346;
            sjs_array_vertex_location_texture_normal* sjt_parent159 = 0;

            sjt_dot1510 = _parent;
            sjt_parent159 = &(sjt_dot1510)->vertices;
            sjt_math2345 = i;
            sjt_math2346 = 3;
            sjt_math2343 = sjt_math2345 * sjt_math2346;
            sjt_math2344 = 2;
            sjt_functionParam407 = sjt_math2343 + sjt_math2344;
            sjf_array_vertex_location_texture_normal_getat(sjt_parent159, sjt_functionParam407, &sjv_vertex2);
        }

        sjt_functionParam428 = &sjv_vpickrayorig;
        sjt_functionParam429 = &sjv_vpickraydir;
        sjt_dot1511 = &sjv_vertex0;
        sjt_functionParam430 = &(sjt_dot1511)->location;
        sjt_dot1512 = &sjv_vertex1;
        sjt_functionParam431 = &(sjt_dot1512)->location;
        sjt_dot1513 = &sjv_vertex2;
        sjt_functionParam432 = &(sjt_dot1513)->location;
        sjf_intersecttriangle(sjt_functionParam428, sjt_functionParam429, sjt_functionParam430, sjt_functionParam431, sjt_functionParam432, &sjv_result);
        sjt_isEmpty4 = (sjv_result._refCount != -1 ? &sjv_result : 0);
        sjt_isEmpty3 = (sjt_isEmpty4 != 0);
        if (sjt_isEmpty3) {
            sjs_vec3* ifValue7 = 0;
            float sjt_compare97;
            float sjt_compare98;
            sjs_vec3* sjt_dot1514 = 0;
            bool sjt_ifElse36;
            bool sjt_ifElse37;
            bool sjt_ifElse38;
            sjs_vec3* sjt_isEmpty5 = 0;
            float_option sjt_isEmpty6;
            sjs_vec3* sjt_isEmpty7 = 0;
            bool sjt_or10;
            bool sjt_or9;

            ifValue7 = (sjv_result._refCount != -1 ? &sjv_result : 0);
            sjt_isEmpty5 = (sjv_intersection._refCount != -1 ? &sjv_intersection : 0);
            sjt_or9 = (sjt_isEmpty5 == 0);
            sjt_dot1514 = ifValue7;
            sjt_compare97 = (sjt_dot1514)->z;
            sjt_isEmpty7 = (sjv_intersection._refCount != -1 ? &sjv_intersection : 0);
            sjt_ifElse38 = (sjt_isEmpty7 != 0);
            if (sjt_ifElse38) {
                sjs_vec3* sjt_dot1515 = 0;
                float sjt_value3;
                float_option value1;

                sjt_dot1515 = (sjv_intersection._refCount != -1 ? &sjv_intersection : 0);
                sjt_value3 = (sjt_dot1515)->z;
                value1.isvalid = true;
                value1.value = sjt_value3;
                sjt_isEmpty6 = value1;
            } else {
                sjt_isEmpty6 = float_empty;
            }

            sjt_ifElse37 = sjt_isEmpty6.isvalid;
            if (sjt_ifElse37) {
                float_option sjt_getValue1;
                bool sjt_ifElse39;
                sjs_vec3* sjt_isEmpty8 = 0;

                sjt_isEmpty8 = (sjv_intersection._refCount != -1 ? &sjv_intersection : 0);
                sjt_ifElse39 = (sjt_isEmpty8 != 0);
                if (sjt_ifElse39) {
                    sjs_vec3* sjt_dot1516 = 0;
                    float sjt_value4;
                    float_option value2;

                    sjt_dot1516 = (sjv_intersection._refCount != -1 ? &sjv_intersection : 0);
                    sjt_value4 = (sjt_dot1516)->z;
                    value2.isvalid = true;
                    value2.value = sjt_value4;
                    sjt_getValue1 = value2;
                } else {
                    sjt_getValue1 = float_empty;
                }

                sjt_compare98 = sjt_getValue1.value;
            } else {
                sjt_compare98 = 0.0f;
            }

            sjt_or10 = sjt_compare97 < sjt_compare98;
            sjt_ifElse36 = sjt_or9 || sjt_or10;
            if (sjt_ifElse36) {
                sjs_vec3* sjt_copy33 = 0;
                sjs_vec2* sjt_dot1517 = 0;
                sjs_vertex_location_texture_normal* sjt_dot1518 = 0;
                sjs_vec2* sjt_dot1519 = 0;
                sjs_vertex_location_texture_normal* sjt_dot1520 = 0;
                sjs_vec2* sjt_dot1521 = 0;
                sjs_vertex_location_texture_normal* sjt_dot1522 = 0;
                sjs_vec2* sjt_dot1523 = 0;
                sjs_vertex_location_texture_normal* sjt_dot1524 = 0;
                sjs_vec2* sjt_dot1525 = 0;
                sjs_vertex_location_texture_normal* sjt_dot1526 = 0;
                sjs_vec2* sjt_dot1527 = 0;
                sjs_vertex_location_texture_normal* sjt_dot1528 = 0;
                sjs_vec2* sjt_dot1529 = 0;
                sjs_vertex_location_texture_normal* sjt_dot1530 = 0;
                sjs_vec2* sjt_dot1531 = 0;
                sjs_vertex_location_texture_normal* sjt_dot1532 = 0;
                sjs_vec2* sjt_dot1533 = 0;
                sjs_vertex_location_texture_normal* sjt_dot1534 = 0;
                sjs_vec3* sjt_dot1535 = 0;
                sjs_vec3* sjt_dot1536 = 0;
                sjs_vec2* sjt_dot1537 = 0;
                sjs_vertex_location_texture_normal* sjt_dot1538 = 0;
                sjs_vec3* sjt_dot1539 = 0;
                sjs_vec3* sjt_dot1540 = 0;
                float sjt_math2371;
                float sjt_math2372;
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
                float sjv_dtu1;
                float sjv_dtu2;
                float sjv_dtv1;
                float sjv_dtv2;

                sjt_copy33 = ifValue7;
                sjv_intersection._refCount = 1;
                sjf_vec3_copy(&sjv_intersection, sjt_copy33);
                sjt_dot1518 = &sjv_vertex1;
                sjt_dot1517 = &(sjt_dot1518)->texture;
                sjt_math2371 = (sjt_dot1517)->x;
                sjt_dot1520 = &sjv_vertex0;
                sjt_dot1519 = &(sjt_dot1520)->texture;
                sjt_math2372 = (sjt_dot1519)->x;
                sjv_dtu1 = sjt_math2371 - sjt_math2372;
                sjt_dot1522 = &sjv_vertex2;
                sjt_dot1521 = &(sjt_dot1522)->texture;
                sjt_math2373 = (sjt_dot1521)->x;
                sjt_dot1524 = &sjv_vertex0;
                sjt_dot1523 = &(sjt_dot1524)->texture;
                sjt_math2374 = (sjt_dot1523)->x;
                sjv_dtu2 = sjt_math2373 - sjt_math2374;
                sjt_dot1526 = &sjv_vertex1;
                sjt_dot1525 = &(sjt_dot1526)->texture;
                sjt_math2375 = (sjt_dot1525)->y;
                sjt_dot1528 = &sjv_vertex0;
                sjt_dot1527 = &(sjt_dot1528)->texture;
                sjt_math2376 = (sjt_dot1527)->y;
                sjv_dtv1 = sjt_math2375 - sjt_math2376;
                sjt_dot1530 = &sjv_vertex2;
                sjt_dot1529 = &(sjt_dot1530)->texture;
                sjt_math2377 = (sjt_dot1529)->y;
                sjt_dot1532 = &sjv_vertex0;
                sjt_dot1531 = &(sjt_dot1532)->texture;
                sjt_math2378 = (sjt_dot1531)->y;
                sjv_dtv2 = sjt_math2377 - sjt_math2378;
                sjv_texture._refCount = 1;
                sjt_dot1534 = &sjv_vertex0;
                sjt_dot1533 = &(sjt_dot1534)->texture;
                sjt_math2381 = (sjt_dot1533)->x;
                sjt_dot1535 = ifValue7;
                sjt_math2383 = (sjt_dot1535)->x;
                sjt_math2384 = sjv_dtu1;
                sjt_math2382 = sjt_math2383 * sjt_math2384;
                sjt_math2379 = sjt_math2381 + sjt_math2382;
                sjt_dot1536 = ifValue7;
                sjt_math2385 = (sjt_dot1536)->y;
                sjt_math2386 = sjv_dtu2;
                sjt_math2380 = sjt_math2385 * sjt_math2386;
                sjv_texture.x = sjt_math2379 + sjt_math2380;
                sjt_dot1538 = &sjv_vertex0;
                sjt_dot1537 = &(sjt_dot1538)->texture;
                sjt_math2389 = (sjt_dot1537)->y;
                sjt_dot1539 = ifValue7;
                sjt_math2391 = (sjt_dot1539)->x;
                sjt_math2392 = sjv_dtv1;
                sjt_math2390 = sjt_math2391 * sjt_math2392;
                sjt_math2387 = sjt_math2389 + sjt_math2390;
                sjt_dot1540 = ifValue7;
                sjt_math2393 = (sjt_dot1540)->y;
                sjt_math2394 = sjv_dtv2;
                sjt_math2388 = sjt_math2393 * sjt_math2394;
                sjv_texture.y = sjt_math2387 + sjt_math2388;
                sjf_vec2(&sjv_texture);
            }
        }

        i++;

        if (sjv_result._refCount == 1) { sjf_vec3_destroy(&sjv_result); }
        if (sjv_vertex0._refCount == 1) { sjf_vertex_location_texture_normal_destroy(&sjv_vertex0); }
        if (sjv_vertex1._refCount == 1) { sjf_vertex_location_texture_normal_destroy(&sjv_vertex1); }
        if (sjv_vertex2._refCount == 1) { sjf_vertex_location_texture_normal_destroy(&sjv_vertex2); }
    }

    sjt_isEmpty9 = (sjv_texture._refCount != -1 ? &sjv_texture : 0);
    sjt_ifElse40 = (sjt_isEmpty9 != 0);
    if (sjt_ifElse40) {
        sjs_vec2* sjt_copy34 = 0;

        sjt_copy34 = (sjv_texture._refCount != -1 ? &sjv_texture : 0);
        _return->_refCount = 1;
        sjf_vec2_copy(_return, sjt_copy34);
    } else {
        _return->_refCount = -1;
    }

    if (sjt_call77._refCount == 1) { sjf_mat4_destroy(&sjt_call77); }
    if (sjv_all._refCount == 1) { sjf_mat4_destroy(&sjv_all); }
    if (sjv_allinverse._refCount == 1) { sjf_mat4_destroy(&sjv_allinverse); }
    if (sjv_intersection._refCount == 1) { sjf_vec3_destroy(&sjv_intersection); }
    if (sjv_start._refCount == 1) { sjf_vec2_destroy(&sjv_start); }
    if (sjv_texture._refCount == 1) { sjf_vec2_destroy(&sjv_texture); }
    if (sjv_vflatteneddir._refCount == 1) { sjf_vec3_destroy(&sjv_vflatteneddir); }
    if (sjv_vflattenedorigin1._refCount == 1) { sjf_vec3_destroy(&sjv_vflattenedorigin1); }
    if (sjv_vflattenedorigin2._refCount == 1) { sjf_vec3_destroy(&sjv_vflattenedorigin2); }
    if (sjv_vpickraydir._refCount == 1) { sjf_vec3_destroy(&sjv_vpickraydir); }
    if (sjv_vpickrayorig._refCount == 1) { sjf_vec3_destroy(&sjv_vpickrayorig); }
    if (sjv_vprojectedorigin1._refCount == 1) { sjf_vec4_destroy(&sjv_vprojectedorigin1); }
    if (sjv_vprojectedorigin2._refCount == 1) { sjf_vec4_destroy(&sjv_vprojectedorigin2); }
    if (sjv_vscreenorigin1._refCount == 1) { sjf_vec4_destroy(&sjv_vscreenorigin1); }
    if (sjv_vscreenorigin2._refCount == 1) { sjf_vec4_destroy(&sjv_vscreenorigin2); }
}

void sjf_windowrenderer(sjs_windowrenderer* _this) {
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
    glClearColor( 0.0, 0.0, 0.0, 0.0 );
    glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );
    glEnable( GL_BLEND );
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
    glClearColor( 0.0, 0.0, 0.0, 0.0 );
    glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );
    glEnable( GL_BLEND );
}

void sjf_windowrenderer_present(sjs_windowrenderer* _parent) {
    SDL_GL_SwapWindow((SDL_Window*)_parent->win);
}

int main(int argc, char** argv) {
    sjs_boxelement_element_vtbl.destroy = (void(*)(void*))sjf_boxelement_destroy;
    sjs_boxelement_element_vtbl.asinterface = (void(*)(sjs_object*,int,sjs_interface*))sjf_boxelement_asinterface;
    sjs_boxelement_element_vtbl.getsize = (void(*)(sjs_object*,sjs_size*, sjs_size*))sjf_boxelement_getsize;
    sjs_boxelement_element_vtbl.getsize_heap = (void(*)(sjs_object*,sjs_size*, sjs_size**))sjf_boxelement_getsize_heap;
    sjs_boxelement_element_vtbl.getrect = (void(*)(sjs_object*, sjs_rect*))sjf_boxelement_getrect;
    sjs_boxelement_element_vtbl.getrect_heap = (void(*)(sjs_object*, sjs_rect**))sjf_boxelement_getrect_heap;
    sjs_boxelement_element_vtbl.setrect = (void(*)(sjs_object*,sjs_rect*))sjf_boxelement_setrect;
    sjs_boxelement_element_vtbl.render = (void(*)(sjs_object*,sjs_scene2d*))sjf_boxelement_render;
    sjs_boxelement_element_vtbl.firemouseevent = (void(*)(sjs_object*,sjs_mouseevent*))sjf_boxelement_firemouseevent;
    sjs_crosshairselement_element_vtbl.destroy = (void(*)(void*))sjf_crosshairselement_destroy;
    sjs_crosshairselement_element_vtbl.asinterface = (void(*)(sjs_object*,int,sjs_interface*))sjf_crosshairselement_asinterface;
    sjs_crosshairselement_element_vtbl.getsize = (void(*)(sjs_object*,sjs_size*, sjs_size*))sjf_crosshairselement_getsize;
    sjs_crosshairselement_element_vtbl.getsize_heap = (void(*)(sjs_object*,sjs_size*, sjs_size**))sjf_crosshairselement_getsize_heap;
    sjs_crosshairselement_element_vtbl.getrect = (void(*)(sjs_object*, sjs_rect*))sjf_crosshairselement_getrect;
    sjs_crosshairselement_element_vtbl.getrect_heap = (void(*)(sjs_object*, sjs_rect**))sjf_crosshairselement_getrect_heap;
    sjs_crosshairselement_element_vtbl.setrect = (void(*)(sjs_object*,sjs_rect*))sjf_crosshairselement_setrect;
    sjs_crosshairselement_element_vtbl.render = (void(*)(sjs_object*,sjs_scene2d*))sjf_crosshairselement_render;
    sjs_crosshairselement_element_vtbl.firemouseevent = (void(*)(sjs_object*,sjs_mouseevent*))sjf_crosshairselement_firemouseevent;
    sjs_fillelement_element_vtbl.destroy = (void(*)(void*))sjf_fillelement_destroy;
    sjs_fillelement_element_vtbl.asinterface = (void(*)(sjs_object*,int,sjs_interface*))sjf_fillelement_asinterface;
    sjs_fillelement_element_vtbl.getsize = (void(*)(sjs_object*,sjs_size*, sjs_size*))sjf_fillelement_getsize;
    sjs_fillelement_element_vtbl.getsize_heap = (void(*)(sjs_object*,sjs_size*, sjs_size**))sjf_fillelement_getsize_heap;
    sjs_fillelement_element_vtbl.getrect = (void(*)(sjs_object*, sjs_rect*))sjf_fillelement_getrect;
    sjs_fillelement_element_vtbl.getrect_heap = (void(*)(sjs_object*, sjs_rect**))sjf_fillelement_getrect_heap;
    sjs_fillelement_element_vtbl.setrect = (void(*)(sjs_object*,sjs_rect*))sjf_fillelement_setrect;
    sjs_fillelement_element_vtbl.render = (void(*)(sjs_object*,sjs_scene2d*))sjf_fillelement_render;
    sjs_fillelement_element_vtbl.firemouseevent = (void(*)(sjs_object*,sjs_mouseevent*))sjf_fillelement_firemouseevent;
    sjs_imageelement_element_vtbl.destroy = (void(*)(void*))sjf_imageelement_destroy;
    sjs_imageelement_element_vtbl.asinterface = (void(*)(sjs_object*,int,sjs_interface*))sjf_imageelement_asinterface;
    sjs_imageelement_element_vtbl.getsize = (void(*)(sjs_object*,sjs_size*, sjs_size*))sjf_imageelement_getsize;
    sjs_imageelement_element_vtbl.getsize_heap = (void(*)(sjs_object*,sjs_size*, sjs_size**))sjf_imageelement_getsize_heap;
    sjs_imageelement_element_vtbl.getrect = (void(*)(sjs_object*, sjs_rect*))sjf_imageelement_getrect;
    sjs_imageelement_element_vtbl.getrect_heap = (void(*)(sjs_object*, sjs_rect**))sjf_imageelement_getrect_heap;
    sjs_imageelement_element_vtbl.setrect = (void(*)(sjs_object*,sjs_rect*))sjf_imageelement_setrect;
    sjs_imageelement_element_vtbl.render = (void(*)(sjs_object*,sjs_scene2d*))sjf_imageelement_render;
    sjs_imageelement_element_vtbl.firemouseevent = (void(*)(sjs_object*,sjs_mouseevent*))sjf_imageelement_firemouseevent;
    sjs_leafpanel_model_vtbl.destroy = (void(*)(void*))sjf_leafpanel_destroy;
    sjs_leafpanel_model_vtbl.asinterface = (void(*)(sjs_object*,int,sjs_interface*))sjf_leafpanel_asinterface;
    sjs_leafpanel_model_vtbl.update = (void(*)(sjs_object*,sjs_rect*,sjs_mat4*,sjs_mat4*,sjs_mat4*,sjs_light*))sjf_leafpanel_update;
    sjs_leafpanel_model_vtbl.getz = (void(*)(sjs_object*, float*))sjf_leafpanel_getz;
    sjs_leafpanel_model_vtbl.renderorqueue = (void(*)(sjs_object*,sjs_list_local_iface_model*))sjf_leafpanel_renderorqueue;
    sjs_leafpanel_model_vtbl.render = (void(*)(sjs_object*))sjf_leafpanel_render;
    sjs_leafpanel_model_vtbl.firemouseevent = (void(*)(sjs_object*,sjs_mouseevent*))sjf_leafpanel_firemouseevent;
    sjs_model_model_vtbl.destroy = (void(*)(void*))sjf_model_destroy;
    sjs_model_model_vtbl.asinterface = (void(*)(sjs_object*,int,sjs_interface*))sjf_model_asinterface;
    sjs_model_model_vtbl.update = (void(*)(sjs_object*,sjs_rect*,sjs_mat4*,sjs_mat4*,sjs_mat4*,sjs_light*))sjf_model_update;
    sjs_model_model_vtbl.getz = (void(*)(sjs_object*, float*))sjf_model_getz;
    sjs_model_model_vtbl.renderorqueue = (void(*)(sjs_object*,sjs_list_local_iface_model*))sjf_model_renderorqueue;
    sjs_model_model_vtbl.render = (void(*)(sjs_object*))sjf_model_render;
    sjs_model_model_vtbl.firemouseevent = (void(*)(sjs_object*,sjs_mouseevent*))sjf_model_firemouseevent;
    sjs_nauscene3delement_element_vtbl.destroy = (void(*)(void*))sjf_nauscene3delement_destroy;
    sjs_nauscene3delement_element_vtbl.asinterface = (void(*)(sjs_object*,int,sjs_interface*))sjf_nauscene3delement_asinterface;
    sjs_nauscene3delement_element_vtbl.getsize = (void(*)(sjs_object*,sjs_size*, sjs_size*))sjf_nauscene3delement_getsize;
    sjs_nauscene3delement_element_vtbl.getsize_heap = (void(*)(sjs_object*,sjs_size*, sjs_size**))sjf_nauscene3delement_getsize_heap;
    sjs_nauscene3delement_element_vtbl.getrect = (void(*)(sjs_object*, sjs_rect*))sjf_nauscene3delement_getrect;
    sjs_nauscene3delement_element_vtbl.getrect_heap = (void(*)(sjs_object*, sjs_rect**))sjf_nauscene3delement_getrect_heap;
    sjs_nauscene3delement_element_vtbl.setrect = (void(*)(sjs_object*,sjs_rect*))sjf_nauscene3delement_setrect;
    sjs_nauscene3delement_element_vtbl.render = (void(*)(sjs_object*,sjs_scene2d*))sjf_nauscene3delement_render;
    sjs_nauscene3delement_element_vtbl.firemouseevent = (void(*)(sjs_object*,sjs_mouseevent*))sjf_nauscene3delement_firemouseevent;
    sjs_panel3d_model_vtbl.destroy = (void(*)(void*))sjf_panel3d_destroy;
    sjs_panel3d_model_vtbl.asinterface = (void(*)(sjs_object*,int,sjs_interface*))sjf_panel3d_asinterface;
    sjs_panel3d_model_vtbl.update = (void(*)(sjs_object*,sjs_rect*,sjs_mat4*,sjs_mat4*,sjs_mat4*,sjs_light*))sjf_panel3d_update;
    sjs_panel3d_model_vtbl.getz = (void(*)(sjs_object*, float*))sjf_panel3d_getz;
    sjs_panel3d_model_vtbl.renderorqueue = (void(*)(sjs_object*,sjs_list_local_iface_model*))sjf_panel3d_renderorqueue;
    sjs_panel3d_model_vtbl.render = (void(*)(sjs_object*))sjf_panel3d_render;
    sjs_panel3d_model_vtbl.firemouseevent = (void(*)(sjs_object*,sjs_mouseevent*))sjf_panel3d_firemouseevent;
    sjs_peoplepanel_model_vtbl.destroy = (void(*)(void*))sjf_peoplepanel_destroy;
    sjs_peoplepanel_model_vtbl.asinterface = (void(*)(sjs_object*,int,sjs_interface*))sjf_peoplepanel_asinterface;
    sjs_peoplepanel_model_vtbl.update = (void(*)(sjs_object*,sjs_rect*,sjs_mat4*,sjs_mat4*,sjs_mat4*,sjs_light*))sjf_peoplepanel_update;
    sjs_peoplepanel_model_vtbl.getz = (void(*)(sjs_object*, float*))sjf_peoplepanel_getz;
    sjs_peoplepanel_model_vtbl.renderorqueue = (void(*)(sjs_object*,sjs_list_local_iface_model*))sjf_peoplepanel_renderorqueue;
    sjs_peoplepanel_model_vtbl.render = (void(*)(sjs_object*))sjf_peoplepanel_render;
    sjs_peoplepanel_model_vtbl.firemouseevent = (void(*)(sjs_object*,sjs_mouseevent*))sjf_peoplepanel_firemouseevent;
    sjs_scene2dmodel_model_vtbl.destroy = (void(*)(void*))sjf_scene2dmodel_destroy;
    sjs_scene2dmodel_model_vtbl.asinterface = (void(*)(sjs_object*,int,sjs_interface*))sjf_scene2dmodel_asinterface;
    sjs_scene2dmodel_model_vtbl.update = (void(*)(sjs_object*,sjs_rect*,sjs_mat4*,sjs_mat4*,sjs_mat4*,sjs_light*))sjf_scene2dmodel_update;
    sjs_scene2dmodel_model_vtbl.getz = (void(*)(sjs_object*, float*))sjf_scene2dmodel_getz;
    sjs_scene2dmodel_model_vtbl.renderorqueue = (void(*)(sjs_object*,sjs_list_local_iface_model*))sjf_scene2dmodel_renderorqueue;
    sjs_scene2dmodel_model_vtbl.render = (void(*)(sjs_object*))sjf_scene2dmodel_render;
    sjs_scene2dmodel_model_vtbl.firemouseevent = (void(*)(sjs_object*,sjs_mouseevent*))sjf_scene2dmodel_firemouseevent;
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
    sjf_array_local_iface_animation(&sjv_animator.animations.array);
    sjf_list_local_iface_animation(&sjv_animator.animations);
    sjv_animator.current = 0;
    sjf_anon1(&sjv_animator);
    sjv_borderposition._refCount = 1;
    sjv_borderposition.fill = 0;
    sjv_borderposition.left = 1;
    sjv_borderposition.right = 2;
    sjv_borderposition.top = 3;
    sjv_borderposition.bottom = 4;
    sjf_anon2(&sjv_borderposition);
    sjv_buttonstate._refCount = 1;
    sjv_buttonstate.normal = 0;
    sjv_buttonstate.hot = 1;
    sjv_buttonstate.pressed = 2;
    sjf_anon3(&sjv_buttonstate);
    sjv_colors._refCount = 1;
    sjf_anon4(&sjv_colors);
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
    glid_init();
    sjv_mouse_captureelement._parent = 0;
    sjv_mouseeventtype_move = 0;
    sjv_mouseeventtype_up = 1;
    sjv_mouseeventtype_down = 2;
    sjv_boxshader._refCount = 1;
    sjv_boxshader.vertex._refCount = 1;
    sjv_boxshader.vertex.count = 20;
    sjv_boxshader.vertex.data._refCount = 1;
    sjv_boxshader.vertex.data.datasize = 21;
    sjv_boxshader.vertex.data.data = (void*)sjg_string1;
    sjv_boxshader.vertex.data._isglobal = true;
    sjv_boxshader.vertex.data.count = 21;
    sjf_array_char(&sjv_boxshader.vertex.data);
    sjf_string(&sjv_boxshader.vertex);
    sjv_boxshader.pixel._refCount = 1;
    sjv_boxshader.pixel.count = 20;
    sjv_boxshader.pixel.data._refCount = 1;
    sjv_boxshader.pixel.data.datasize = 21;
    sjv_boxshader.pixel.data.data = (void*)sjg_string2;
    sjv_boxshader.pixel.data._isglobal = true;
    sjv_boxshader.pixel.data.count = 21;
    sjf_array_char(&sjv_boxshader.pixel.data);
    sjf_string(&sjv_boxshader.pixel);
    sjf_shader(&sjv_boxshader);
    sjv_blurhorizontalshader._refCount = 1;
    sjv_blurhorizontalshader.vertex._refCount = 1;
    sjv_blurhorizontalshader.vertex.count = 24;
    sjv_blurhorizontalshader.vertex.data._refCount = 1;
    sjv_blurhorizontalshader.vertex.data.datasize = 25;
    sjv_blurhorizontalshader.vertex.data.data = (void*)sjg_string3;
    sjv_blurhorizontalshader.vertex.data._isglobal = true;
    sjv_blurhorizontalshader.vertex.data.count = 25;
    sjf_array_char(&sjv_blurhorizontalshader.vertex.data);
    sjf_string(&sjv_blurhorizontalshader.vertex);
    sjv_blurhorizontalshader.pixel._refCount = 1;
    sjv_blurhorizontalshader.pixel.count = 28;
    sjv_blurhorizontalshader.pixel.data._refCount = 1;
    sjv_blurhorizontalshader.pixel.data.datasize = 29;
    sjv_blurhorizontalshader.pixel.data.data = (void*)sjg_string4;
    sjv_blurhorizontalshader.pixel.data._isglobal = true;
    sjv_blurhorizontalshader.pixel.data.count = 29;
    sjf_array_char(&sjv_blurhorizontalshader.pixel.data);
    sjf_string(&sjv_blurhorizontalshader.pixel);
    sjf_shader(&sjv_blurhorizontalshader);
    sjv_blurverticalshader._refCount = 1;
    sjv_blurverticalshader.vertex._refCount = 1;
    sjv_blurverticalshader.vertex.count = 24;
    sjv_blurverticalshader.vertex.data._refCount = 1;
    sjv_blurverticalshader.vertex.data.datasize = 25;
    sjv_blurverticalshader.vertex.data.data = (void*)sjg_string5;
    sjv_blurverticalshader.vertex.data._isglobal = true;
    sjv_blurverticalshader.vertex.data.count = 25;
    sjf_array_char(&sjv_blurverticalshader.vertex.data);
    sjf_string(&sjv_blurverticalshader.vertex);
    sjv_blurverticalshader.pixel._refCount = 1;
    sjv_blurverticalshader.pixel.count = 26;
    sjv_blurverticalshader.pixel.data._refCount = 1;
    sjv_blurverticalshader.pixel.data.datasize = 27;
    sjv_blurverticalshader.pixel.data.data = (void*)sjg_string6;
    sjv_blurverticalshader.pixel.data._isglobal = true;
    sjv_blurverticalshader.pixel.data.count = 27;
    sjf_array_char(&sjv_blurverticalshader.pixel.data);
    sjf_string(&sjv_blurverticalshader.pixel);
    sjf_shader(&sjv_blurverticalshader);
    sjv_imageshader._refCount = 1;
    sjv_imageshader.vertex._refCount = 1;
    sjv_imageshader.vertex.count = 20;
    sjv_imageshader.vertex.data._refCount = 1;
    sjv_imageshader.vertex.data.datasize = 21;
    sjv_imageshader.vertex.data.data = (void*)sjg_string7;
    sjv_imageshader.vertex.data._isglobal = true;
    sjv_imageshader.vertex.data.count = 21;
    sjf_array_char(&sjv_imageshader.vertex.data);
    sjf_string(&sjv_imageshader.vertex);
    sjv_imageshader.pixel._refCount = 1;
    sjv_imageshader.pixel.count = 20;
    sjv_imageshader.pixel.data._refCount = 1;
    sjv_imageshader.pixel.data.datasize = 21;
    sjv_imageshader.pixel.data.data = (void*)sjg_string8;
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
    sjv_phongcolorshader.vertex.data.data = (void*)sjg_string9;
    sjv_phongcolorshader.vertex.data._isglobal = true;
    sjv_phongcolorshader.vertex.data.count = 27;
    sjf_array_char(&sjv_phongcolorshader.vertex.data);
    sjf_string(&sjv_phongcolorshader.vertex);
    sjv_phongcolorshader.pixel._refCount = 1;
    sjv_phongcolorshader.pixel.count = 26;
    sjv_phongcolorshader.pixel.data._refCount = 1;
    sjv_phongcolorshader.pixel.data.datasize = 27;
    sjv_phongcolorshader.pixel.data.data = (void*)sjg_string10;
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
    sjv_phongtextureshader.vertex.data.data = (void*)sjg_string11;
    sjv_phongtextureshader.vertex.data._isglobal = true;
    sjv_phongtextureshader.vertex.data.count = 31;
    sjf_array_char(&sjv_phongtextureshader.vertex.data);
    sjf_string(&sjv_phongtextureshader.vertex);
    sjv_phongtextureshader.pixel._refCount = 1;
    sjv_phongtextureshader.pixel.count = 30;
    sjv_phongtextureshader.pixel.data._refCount = 1;
    sjv_phongtextureshader.pixel.data.datasize = 31;
    sjv_phongtextureshader.pixel.data.data = (void*)sjg_string12;
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
    sjv_textshader.vertex.data.data = (void*)sjg_string13;
    sjv_textshader.vertex.data._isglobal = true;
    sjv_textshader.vertex.data.count = 25;
    sjf_array_char(&sjv_textshader.vertex.data);
    sjf_string(&sjv_textshader.vertex);
    sjv_textshader.pixel._refCount = 1;
    sjv_textshader.pixel.count = 24;
    sjv_textshader.pixel.data._refCount = 1;
    sjv_textshader.pixel.data.datasize = 25;
    sjv_textshader.pixel.data.data = (void*)sjg_string14;
    sjv_textshader.pixel.data._isglobal = true;
    sjv_textshader.pixel.data.count = 25;
    sjf_array_char(&sjv_textshader.pixel.data);
    sjf_string(&sjv_textshader.pixel);
    sjf_shader(&sjv_textshader);
    sjv_style._refCount = 1;
    sjf_anon5(&sjv_style);
    sjv_vertex_location_texture_normal_format._refCount = 1;
    sjv_vertex_location_texture_normal_format.count = 32;
    sjv_vertex_location_texture_normal_format.data._refCount = 1;
    sjv_vertex_location_texture_normal_format.data.datasize = 33;
    sjv_vertex_location_texture_normal_format.data.data = (void*)sjg_string15;
    sjv_vertex_location_texture_normal_format.data._isglobal = true;
    sjv_vertex_location_texture_normal_format.data.count = 33;
    sjf_array_char(&sjv_vertex_location_texture_normal_format.data);
    sjf_string(&sjv_vertex_location_texture_normal_format);
    sjt_call1._refCount = 1;
    sjt_call1.children._refCount = 1;
    sjt_call1.children.datasize = 2;
    sjt_call1.children.data = 0;
    sjt_call1.children._isglobal = false;
    sjt_call1.children.count = 0;
    sjf_array_heap_iface_element(&sjt_call1.children);
    sjs_array_heap_iface_element* array11;
    array11 = &sjt_call1.children;
    sjt_parent8 = array11;
    sjt_functionParam5 = 0;
    sjt_call2 = (sjs_nauscene3delement*)malloc(sizeof(sjs_nauscene3delement));
    sjt_call2->_refCount = 1;
    sjt_call2->children._refCount = 1;
    sjt_call2->children.datasize = 4;
    sjt_call2->children.data = 0;
    sjt_call2->children._isglobal = false;
    sjt_call2->children.count = 0;
    sjf_array_heap_iface_model(&sjt_call2->children);
    sjs_array_heap_iface_model* array5;
    array5 = &sjt_call2->children;
    sjt_parent42 = array5;
    sjt_functionParam104 = 0;
    sjt_call13 = (sjs_model*)malloc(sizeof(sjs_model));
    sjt_call13->_refCount = 1;
    sjt_negate11 = 6.3f;
    result13 = -sjt_negate11;
    sjt_functionParam196 = result13;
    sjt_functionParam197 = 6.3f;
    sjt_negate12 = 1.0f;
    result14 = -sjt_negate12;
    sjt_functionParam198 = result14;
    sjt_functionParam199 = 1.0f;
    sjt_functionParam200 = 0.0f;
    sjt_functionParam201 = 0.0f;
    sjt_functionParam202 = 1.0f;
    sjt_functionParam203 = 0.0f;
    sjt_functionParam204 = 1.0f;
    sjf_planevertexbuffer(sjt_functionParam196, sjt_functionParam197, sjt_functionParam198, sjt_functionParam199, sjt_functionParam200, sjt_functionParam201, sjt_functionParam202, sjt_functionParam203, sjt_functionParam204, &sjt_call13->vertexbuffer);
    sjt_copy15 = &sjv_phongtextureshader;
    sjt_call13->shader._refCount = 1;
    sjf_shader_copy(&sjt_call13->shader, sjt_copy15);
    sjt_call34._refCount = 1;
    sjt_call34.count = 26;
    sjt_call34.data._refCount = 1;
    sjt_call34.data.datasize = 27;
    sjt_call34.data.data = (void*)sjg_string16;
    sjt_call34.data._isglobal = true;
    sjt_call34.data.count = 27;
    sjf_array_char(&sjt_call34.data);
    sjf_string(&sjt_call34);
    sjt_functionParam205 = &sjt_call34;
    sjf_texturefrompng(sjt_functionParam205, &sjt_call13->texture);
    sjt_functionParam206 = 0.0f;
    sjt_functionParam207 = 8.0f;
    sjt_functionParam208 = 20.0f;
    sjf_mat4_translate(sjt_functionParam206, sjt_functionParam207, sjt_functionParam208, &sjt_call35);
    sjt_parent80 = &sjt_call35;
    sjt_functionParam210 = 12.0f;
    sjt_functionParam211 = 12.0f;
    sjt_functionParam212 = 12.0f;
    sjf_mat4_scale(sjt_functionParam210, sjt_functionParam211, sjt_functionParam212, &sjt_call36);
    sjt_functionParam209 = &sjt_call36;
    sjf_mat4_multiply(sjt_parent80, sjt_functionParam209, &sjt_call13->model);
    sjt_call13->center._refCount = 1;
    sjt_call13->center.x = 0.0f;
    sjt_call13->center.y = 0.0f;
    sjt_call13->center.z = 0.0f;
    sjf_vec3(&sjt_call13->center);
    sjt_call13->hasalpha = false;
    sjt_call13->id._refCount = 1;
    sjt_call13->id.count = 0;
    sjt_call13->id.data._refCount = 1;
    sjt_call13->id.data.datasize = 1;
    sjt_call13->id.data.data = sjv_emptystringdata;
    sjt_call13->id.data._isglobal = true;
    sjt_call13->id.data.count = 1;
    sjf_array_char(&sjt_call13->id.data);
    sjf_string(&sjt_call13->id);
    sjt_call13->_projection._refCount = 1;
    sjt_call13->_projection.m00 = 0.0f;
    sjt_call13->_projection.m01 = 0.0f;
    sjt_call13->_projection.m02 = 0.0f;
    sjt_call13->_projection.m03 = 0.0f;
    sjt_call13->_projection.m10 = 0.0f;
    sjt_call13->_projection.m11 = 0.0f;
    sjt_call13->_projection.m12 = 0.0f;
    sjt_call13->_projection.m13 = 0.0f;
    sjt_call13->_projection.m20 = 0.0f;
    sjt_call13->_projection.m21 = 0.0f;
    sjt_call13->_projection.m22 = 0.0f;
    sjt_call13->_projection.m23 = 0.0f;
    sjt_call13->_projection.m30 = 0.0f;
    sjt_call13->_projection.m31 = 0.0f;
    sjt_call13->_projection.m32 = 0.0f;
    sjt_call13->_projection.m33 = 0.0f;
    sjf_mat4(&sjt_call13->_projection);
    sjt_call13->_view._refCount = 1;
    sjt_call13->_view.m00 = 0.0f;
    sjt_call13->_view.m01 = 0.0f;
    sjt_call13->_view.m02 = 0.0f;
    sjt_call13->_view.m03 = 0.0f;
    sjt_call13->_view.m10 = 0.0f;
    sjt_call13->_view.m11 = 0.0f;
    sjt_call13->_view.m12 = 0.0f;
    sjt_call13->_view.m13 = 0.0f;
    sjt_call13->_view.m20 = 0.0f;
    sjt_call13->_view.m21 = 0.0f;
    sjt_call13->_view.m22 = 0.0f;
    sjt_call13->_view.m23 = 0.0f;
    sjt_call13->_view.m30 = 0.0f;
    sjt_call13->_view.m31 = 0.0f;
    sjt_call13->_view.m32 = 0.0f;
    sjt_call13->_view.m33 = 0.0f;
    sjf_mat4(&sjt_call13->_view);
    sjt_call13->_world._refCount = 1;
    sjt_call13->_world.m00 = 0.0f;
    sjt_call13->_world.m01 = 0.0f;
    sjt_call13->_world.m02 = 0.0f;
    sjt_call13->_world.m03 = 0.0f;
    sjt_call13->_world.m10 = 0.0f;
    sjt_call13->_world.m11 = 0.0f;
    sjt_call13->_world.m12 = 0.0f;
    sjt_call13->_world.m13 = 0.0f;
    sjt_call13->_world.m20 = 0.0f;
    sjt_call13->_world.m21 = 0.0f;
    sjt_call13->_world.m22 = 0.0f;
    sjt_call13->_world.m23 = 0.0f;
    sjt_call13->_world.m30 = 0.0f;
    sjt_call13->_world.m31 = 0.0f;
    sjt_call13->_world.m32 = 0.0f;
    sjt_call13->_world.m33 = 0.0f;
    sjf_mat4(&sjt_call13->_world);
    sjt_call13->_light._refCount = 1;
    sjt_call13->_light.pos._refCount = 1;
    sjt_call13->_light.pos.x = 1.0f;
    sjt_call13->_light.pos.y = 1.0f;
    sjt_call13->_light.pos.z = 1.0f;
    sjf_vec3(&sjt_call13->_light.pos);
    sjt_call13->_light.diffusecolor._refCount = 1;
    sjt_call13->_light.diffusecolor.r = 0.5f;
    sjt_call13->_light.diffusecolor.g = 0.5f;
    sjt_call13->_light.diffusecolor.b = 0.0f;
    sjt_call13->_light.diffusecolor.a = 1.0f;
    sjf_color(&sjt_call13->_light.diffusecolor);
    sjt_call13->_light.speccolor._refCount = 1;
    sjt_call13->_light.speccolor.r = 1.0f;
    sjt_call13->_light.speccolor.g = 1.0f;
    sjt_call13->_light.speccolor.b = 1.0f;
    sjt_call13->_light.speccolor.a = 1.0f;
    sjf_color(&sjt_call13->_light.speccolor);
    sjf_light(&sjt_call13->_light);
    sjt_call13->_projectedcenter._refCount = 1;
    sjt_call13->_projectedcenter.x = 0.0f;
    sjt_call13->_projectedcenter.y = 0.0f;
    sjt_call13->_projectedcenter.z = 0.0f;
    sjf_vec3(&sjt_call13->_projectedcenter);
    sjf_model_heap(sjt_call13);
    sjt_cast11 = sjt_call13;
    sjf_model_as_sji_model(sjt_cast11, &sjt_functionParam105);
    if (sjt_functionParam105._parent != 0) {
        sjt_functionParam105._parent->_refCount++;
    }

    sjf_array_heap_iface_model_initat(sjt_parent42, sjt_functionParam104, sjt_functionParam105);
    sjt_parent81 = array5;
    sjt_functionParam213 = 1;
    sjt_call37 = (sjs_leafpanel*)malloc(sizeof(sjs_leafpanel));
    sjt_call37->_refCount = 1;
    sjt_call37->textures._refCount = 1;
    sjt_call37->textures.datasize = 8;
    sjt_call37->textures.data = 0;
    sjt_call37->textures._isglobal = false;
    sjt_call37->textures.count = 0;
    sjf_array_texture(&sjt_call37->textures);
    sjs_array_texture* array6;
    array6 = &sjt_call37->textures;
    sjt_parent104 = array6;
    sjt_functionParam258 = 0;
    sjt_call44._refCount = 1;
    sjt_call44.count = 21;
    sjt_call44.data._refCount = 1;
    sjt_call44.data.datasize = 22;
    sjt_call44.data.data = (void*)sjg_string19;
    sjt_call44.data._isglobal = true;
    sjt_call44.data.count = 22;
    sjf_array_char(&sjt_call44.data);
    sjf_string(&sjt_call44);
    sjt_functionParam260 = &sjt_call44;
    sjf_texturefrompng(sjt_functionParam260, &sjt_call43);
    sjt_functionParam259 = &sjt_call43;
    sjf_array_texture_initat(sjt_parent104, sjt_functionParam258, sjt_functionParam259);
    sjt_parent105 = array6;
    sjt_functionParam261 = 1;
    sjt_call46._refCount = 1;
    sjt_call46.count = 21;
    sjt_call46.data._refCount = 1;
    sjt_call46.data.datasize = 22;
    sjt_call46.data.data = (void*)sjg_string20;
    sjt_call46.data._isglobal = true;
    sjt_call46.data.count = 22;
    sjf_array_char(&sjt_call46.data);
    sjf_string(&sjt_call46);
    sjt_functionParam263 = &sjt_call46;
    sjf_texturefrompng(sjt_functionParam263, &sjt_call45);
    sjt_functionParam262 = &sjt_call45;
    sjf_array_texture_initat(sjt_parent105, sjt_functionParam261, sjt_functionParam262);
    sjt_parent106 = array6;
    sjt_functionParam264 = 2;
    sjt_call48._refCount = 1;
    sjt_call48.count = 21;
    sjt_call48.data._refCount = 1;
    sjt_call48.data.datasize = 22;
    sjt_call48.data.data = (void*)sjg_string21;
    sjt_call48.data._isglobal = true;
    sjt_call48.data.count = 22;
    sjf_array_char(&sjt_call48.data);
    sjf_string(&sjt_call48);
    sjt_functionParam266 = &sjt_call48;
    sjf_texturefrompng(sjt_functionParam266, &sjt_call47);
    sjt_functionParam265 = &sjt_call47;
    sjf_array_texture_initat(sjt_parent106, sjt_functionParam264, sjt_functionParam265);
    sjt_parent107 = array6;
    sjt_functionParam267 = 3;
    sjt_call50._refCount = 1;
    sjt_call50.count = 21;
    sjt_call50.data._refCount = 1;
    sjt_call50.data.datasize = 22;
    sjt_call50.data.data = (void*)sjg_string22;
    sjt_call50.data._isglobal = true;
    sjt_call50.data.count = 22;
    sjf_array_char(&sjt_call50.data);
    sjf_string(&sjt_call50);
    sjt_functionParam269 = &sjt_call50;
    sjf_texturefrompng(sjt_functionParam269, &sjt_call49);
    sjt_functionParam268 = &sjt_call49;
    sjf_array_texture_initat(sjt_parent107, sjt_functionParam267, sjt_functionParam268);
    sjt_parent108 = array6;
    sjt_functionParam270 = 4;
    sjt_call52._refCount = 1;
    sjt_call52.count = 21;
    sjt_call52.data._refCount = 1;
    sjt_call52.data.datasize = 22;
    sjt_call52.data.data = (void*)sjg_string23;
    sjt_call52.data._isglobal = true;
    sjt_call52.data.count = 22;
    sjf_array_char(&sjt_call52.data);
    sjf_string(&sjt_call52);
    sjt_functionParam272 = &sjt_call52;
    sjf_texturefrompng(sjt_functionParam272, &sjt_call51);
    sjt_functionParam271 = &sjt_call51;
    sjf_array_texture_initat(sjt_parent108, sjt_functionParam270, sjt_functionParam271);
    sjt_parent109 = array6;
    sjt_functionParam273 = 5;
    sjt_call54._refCount = 1;
    sjt_call54.count = 21;
    sjt_call54.data._refCount = 1;
    sjt_call54.data.datasize = 22;
    sjt_call54.data.data = (void*)sjg_string24;
    sjt_call54.data._isglobal = true;
    sjt_call54.data.count = 22;
    sjf_array_char(&sjt_call54.data);
    sjf_string(&sjt_call54);
    sjt_functionParam275 = &sjt_call54;
    sjf_texturefrompng(sjt_functionParam275, &sjt_call53);
    sjt_functionParam274 = &sjt_call53;
    sjf_array_texture_initat(sjt_parent109, sjt_functionParam273, sjt_functionParam274);
    sjt_parent110 = array6;
    sjt_functionParam276 = 6;
    sjt_call56._refCount = 1;
    sjt_call56.count = 21;
    sjt_call56.data._refCount = 1;
    sjt_call56.data.datasize = 22;
    sjt_call56.data.data = (void*)sjg_string25;
    sjt_call56.data._isglobal = true;
    sjt_call56.data.count = 22;
    sjf_array_char(&sjt_call56.data);
    sjf_string(&sjt_call56);
    sjt_functionParam278 = &sjt_call56;
    sjf_texturefrompng(sjt_functionParam278, &sjt_call55);
    sjt_functionParam277 = &sjt_call55;
    sjf_array_texture_initat(sjt_parent110, sjt_functionParam276, sjt_functionParam277);
    sjt_parent111 = array6;
    sjt_functionParam279 = 7;
    sjt_call58._refCount = 1;
    sjt_call58.count = 21;
    sjt_call58.data._refCount = 1;
    sjt_call58.data.datasize = 22;
    sjt_call58.data.data = (void*)sjg_string26;
    sjt_call58.data._isglobal = true;
    sjt_call58.data.count = 22;
    sjf_array_char(&sjt_call58.data);
    sjf_string(&sjt_call58);
    sjt_functionParam281 = &sjt_call58;
    sjf_texturefrompng(sjt_functionParam281, &sjt_call57);
    sjt_functionParam280 = &sjt_call57;
    sjf_array_texture_initat(sjt_parent111, sjt_functionParam279, sjt_functionParam280);
    sjt_call37->children._refCount = 1;
    sjt_call37->children.datasize = 0;
    sjt_call37->children.data = 0;
    sjt_call37->children._isglobal = false;
    sjt_call37->children.count = 0;
    sjf_array_heap_iface_model(&sjt_call37->children);
    sjt_call37->_angle = 0.1f;
    sjf_leafpanel_heap(sjt_call37);
    sjt_cast15 = sjt_call37;
    sjf_leafpanel_as_sji_model(sjt_cast15, &sjt_functionParam214);
    if (sjt_functionParam214._parent != 0) {
        sjt_functionParam214._parent->_refCount++;
    }

    sjf_array_heap_iface_model_initat(sjt_parent81, sjt_functionParam213, sjt_functionParam214);
    sjt_parent112 = array5;
    sjt_functionParam282 = 2;
    sjt_call59 = (sjs_peoplepanel*)malloc(sizeof(sjs_peoplepanel));
    sjt_call59->_refCount = 1;
    sjt_functionParam306 = 0.0f;
    sjt_functionParam307 = 0.0f;
    sjt_functionParam308 = 0.0f;
    sjf_mat4_translate(sjt_functionParam306, sjt_functionParam307, sjt_functionParam308, &sjt_call59->model);
    sjt_call59->children._refCount = 1;
    sjt_call59->children.datasize = 2;
    sjt_call59->children.data = 0;
    sjt_call59->children._isglobal = false;
    sjt_call59->children.count = 0;
    sjf_array_heap_iface_model(&sjt_call59->children);
    sjs_array_heap_iface_model* array8;
    array8 = &sjt_call59->children;
    sjt_parent124 = array8;
    sjt_functionParam309 = 0;
    sjt_call61 = (sjs_scene2dmodel*)malloc(sizeof(sjs_scene2dmodel));
    sjt_call61->_refCount = 1;
    sjt_negate21 = 1.0f;
    result24 = -sjt_negate21;
    sjt_functionParam475 = result24;
    sjt_functionParam476 = 1.0f;
    sjt_negate22 = 1.0f;
    result25 = -sjt_negate22;
    sjt_functionParam477 = result25;
    sjt_functionParam478 = 1.0f;
    sjt_functionParam479 = 0.0f;
    sjt_functionParam480 = 0.0f;
    sjt_functionParam481 = 1.0f;
    sjt_functionParam482 = 0.0f;
    sjt_functionParam483 = 1.0f;
    sjf_planevertexbuffer(sjt_functionParam475, sjt_functionParam476, sjt_functionParam477, sjt_functionParam478, sjt_functionParam479, sjt_functionParam480, sjt_functionParam481, sjt_functionParam482, sjt_functionParam483, &sjt_call61->vertexbuffer);
    sjt_copy36 = &sjv_phongtextureshader;
    sjt_call61->shader._refCount = 1;
    sjf_shader_copy(&sjt_call61->shader, sjt_copy36);
    sjt_call61->texturesize._refCount = 1;
    sjt_call61->texturesize.w = 512;
    sjt_call61->texturesize.h = 512;
    sjf_size(&sjt_call61->texturesize);
    sjt_call61->children._refCount = 1;
    sjt_call61->children.datasize = 3;
    sjt_call61->children.data = 0;
    sjt_call61->children._isglobal = false;
    sjt_call61->children.count = 0;
    sjf_array_heap_iface_element(&sjt_call61->children);
    sjs_array_heap_iface_element* array7;
    array7 = &sjt_call61->children;
    sjt_parent187 = array7;
    sjt_functionParam484 = 0;
    sjt_call81 = (sjs_boxelement*)malloc(sizeof(sjs_boxelement));
    sjt_call81->_refCount = 1;
    sjt_parent192 = &sjv_colors;
    sjf_anon4_white(sjt_parent192, &sjt_call81->color);
    sjt_call81->idealsize._refCount = 1;
    sjt_call81->idealsize.w = 0;
    sjt_call81->idealsize.h = 0;
    sjf_size(&sjt_call81->idealsize);
    sjt_call81->rect._refCount = 1;
    sjt_call81->rect.x = 0;
    sjt_call81->rect.y = 0;
    sjt_call81->rect.w = 0;
    sjt_call81->rect.h = 0;
    sjf_rect(&sjt_call81->rect);
    sjt_call81->boxrenderer._refCount = -1;
    sjf_boxelement_heap(sjt_call81);
    sjt_cast44 = sjt_call81;
    sjf_boxelement_as_sji_element(sjt_cast44, &sjt_functionParam485);
    if (sjt_functionParam485._parent != 0) {
        sjt_functionParam485._parent->_refCount++;
    }

    sjf_array_heap_iface_element_initat(sjt_parent187, sjt_functionParam484, sjt_functionParam485);
    sjt_parent193 = array7;
    sjt_functionParam490 = 1;
    sjt_call82 = (sjs_imageelement*)malloc(sizeof(sjs_imageelement));
    sjt_call82->_refCount = 1;
    sjt_call82->image._refCount = 1;
    sjt_call85._refCount = 1;
    sjt_call85.count = 24;
    sjt_call85.data._refCount = 1;
    sjt_call85.data.datasize = 25;
    sjt_call85.data.data = (void*)sjg_string29;
    sjt_call85.data._isglobal = true;
    sjt_call85.data.count = 25;
    sjf_array_char(&sjt_call85.data);
    sjf_string(&sjt_call85);
    sjt_functionParam495 = &sjt_call85;
    sjf_texturefrompng(sjt_functionParam495, &sjt_call82->image.texture);
    sjt_call82->image.rect._refCount = 1;
    sjt_call82->image.rect.x = 0;
    sjt_call82->image.rect.y = 0;
    sjt_call82->image.rect.w = 0;
    sjt_call82->image.rect.h = 0;
    sjf_rect(&sjt_call82->image.rect);
    sjt_call82->image.margin._refCount = 1;
    sjt_call82->image.margin.l = 0;
    sjt_call82->image.margin.t = 0;
    sjt_call82->image.margin.r = 0;
    sjt_call82->image.margin.b = 0;
    sjf_margin(&sjt_call82->image.margin);
    sjf_image(&sjt_call82->image);
    sjt_call82->_rect._refCount = 1;
    sjt_call82->_rect.x = 0;
    sjt_call82->_rect.y = 0;
    sjt_call82->_rect.w = 0;
    sjt_call82->_rect.h = 0;
    sjf_rect(&sjt_call82->_rect);
    sjt_call82->_margin._refCount = 1;
    sjt_call82->_margin.l = 10;
    sjt_call82->_margin.t = 10;
    sjt_call82->_margin.r = 10;
    sjt_call82->_margin.b = 10;
    sjf_margin(&sjt_call82->_margin);
    sjt_call82->_imagerenderer._refCount = -1;
    sjf_imageelement_heap(sjt_call82);
    sjt_cast45 = sjt_call82;
    sjf_imageelement_as_sji_element(sjt_cast45, &sjt_functionParam491);
    if (sjt_functionParam491._parent != 0) {
        sjt_functionParam491._parent->_refCount++;
    }

    sjf_array_heap_iface_element_initat(sjt_parent193, sjt_functionParam490, sjt_functionParam491);
    sjt_parent199 = array7;
    sjt_functionParam496 = 2;
    sjt_call86 = (sjs_crosshairselement*)malloc(sizeof(sjs_crosshairselement));
    sjt_call86->_refCount = 1;
    sjt_parent204 = &sjv_colors;
    sjf_anon4_blue(sjt_parent204, &sjt_call86->color);
    sjt_call86->_rect._refCount = 1;
    sjt_call86->_rect.x = 0;
    sjt_call86->_rect.y = 0;
    sjt_call86->_rect.w = 0;
    sjt_call86->_rect.h = 0;
    sjf_rect(&sjt_call86->_rect);
    sjt_call86->_topdownrenderer._refCount = -1;
    sjt_call86->_leftrightrenderer._refCount = -1;
    sjt_call86->_point._refCount = 1;
    sjt_call86->_point.x = 0;
    sjt_call86->_point.y = 0;
    sjf_point(&sjt_call86->_point);
    sjf_crosshairselement_heap(sjt_call86);
    sjt_cast46 = sjt_call86;
    sjf_crosshairselement_as_sji_element(sjt_cast46, &sjt_functionParam497);
    if (sjt_functionParam497._parent != 0) {
        sjt_functionParam497._parent->_refCount++;
    }

    sjf_array_heap_iface_element_initat(sjt_parent199, sjt_functionParam496, sjt_functionParam497);
    sjt_call61->hasalpha = false;
    sjt_call61->center._refCount = 1;
    sjt_call61->center.x = 0.0f;
    sjt_call61->center.y = 0.0f;
    sjt_call61->center.z = 0.0f;
    sjf_vec3(&sjt_call61->center);
    sjf_mat4_identity(&sjt_call61->model);
    sjt_call61->_innerscene._refCount = 1;
    sjt_call61->_innerscene._size._refCount = 1;
    sjt_call61->_innerscene._size.w = 0;
    sjt_call61->_innerscene._size.h = 0;
    sjf_size(&sjt_call61->_innerscene._size);
    sjt_call61->_innerscene.model._refCount = 1;
    sjt_call61->_innerscene.model.m00 = 0.0f;
    sjt_call61->_innerscene.model.m01 = 0.0f;
    sjt_call61->_innerscene.model.m02 = 0.0f;
    sjt_call61->_innerscene.model.m03 = 0.0f;
    sjt_call61->_innerscene.model.m10 = 0.0f;
    sjt_call61->_innerscene.model.m11 = 0.0f;
    sjt_call61->_innerscene.model.m12 = 0.0f;
    sjt_call61->_innerscene.model.m13 = 0.0f;
    sjt_call61->_innerscene.model.m20 = 0.0f;
    sjt_call61->_innerscene.model.m21 = 0.0f;
    sjt_call61->_innerscene.model.m22 = 0.0f;
    sjt_call61->_innerscene.model.m23 = 0.0f;
    sjt_call61->_innerscene.model.m30 = 0.0f;
    sjt_call61->_innerscene.model.m31 = 0.0f;
    sjt_call61->_innerscene.model.m32 = 0.0f;
    sjt_call61->_innerscene.model.m33 = 0.0f;
    sjf_mat4(&sjt_call61->_innerscene.model);
    sjt_call61->_innerscene.view._refCount = 1;
    sjt_call61->_innerscene.view.m00 = 0.0f;
    sjt_call61->_innerscene.view.m01 = 0.0f;
    sjt_call61->_innerscene.view.m02 = 0.0f;
    sjt_call61->_innerscene.view.m03 = 0.0f;
    sjt_call61->_innerscene.view.m10 = 0.0f;
    sjt_call61->_innerscene.view.m11 = 0.0f;
    sjt_call61->_innerscene.view.m12 = 0.0f;
    sjt_call61->_innerscene.view.m13 = 0.0f;
    sjt_call61->_innerscene.view.m20 = 0.0f;
    sjt_call61->_innerscene.view.m21 = 0.0f;
    sjt_call61->_innerscene.view.m22 = 0.0f;
    sjt_call61->_innerscene.view.m23 = 0.0f;
    sjt_call61->_innerscene.view.m30 = 0.0f;
    sjt_call61->_innerscene.view.m31 = 0.0f;
    sjt_call61->_innerscene.view.m32 = 0.0f;
    sjt_call61->_innerscene.view.m33 = 0.0f;
    sjf_mat4(&sjt_call61->_innerscene.view);
    sjt_call61->_innerscene.projection._refCount = 1;
    sjt_call61->_innerscene.projection.m00 = 0.0f;
    sjt_call61->_innerscene.projection.m01 = 0.0f;
    sjt_call61->_innerscene.projection.m02 = 0.0f;
    sjt_call61->_innerscene.projection.m03 = 0.0f;
    sjt_call61->_innerscene.projection.m10 = 0.0f;
    sjt_call61->_innerscene.projection.m11 = 0.0f;
    sjt_call61->_innerscene.projection.m12 = 0.0f;
    sjt_call61->_innerscene.projection.m13 = 0.0f;
    sjt_call61->_innerscene.projection.m20 = 0.0f;
    sjt_call61->_innerscene.projection.m21 = 0.0f;
    sjt_call61->_innerscene.projection.m22 = 0.0f;
    sjt_call61->_innerscene.projection.m23 = 0.0f;
    sjt_call61->_innerscene.projection.m30 = 0.0f;
    sjt_call61->_innerscene.projection.m31 = 0.0f;
    sjt_call61->_innerscene.projection.m32 = 0.0f;
    sjt_call61->_innerscene.projection.m33 = 0.0f;
    sjf_mat4(&sjt_call61->_innerscene.projection);
    sjf_scene2d(&sjt_call61->_innerscene);
    sjt_call61->_scenerect._refCount = 1;
    sjt_call61->_scenerect.x = 0;
    sjt_call61->_scenerect.y = 0;
    sjt_call61->_scenerect.w = 0;
    sjt_call61->_scenerect.h = 0;
    sjf_rect(&sjt_call61->_scenerect);
    sjt_call61->_projection._refCount = 1;
    sjt_call61->_projection.m00 = 0.0f;
    sjt_call61->_projection.m01 = 0.0f;
    sjt_call61->_projection.m02 = 0.0f;
    sjt_call61->_projection.m03 = 0.0f;
    sjt_call61->_projection.m10 = 0.0f;
    sjt_call61->_projection.m11 = 0.0f;
    sjt_call61->_projection.m12 = 0.0f;
    sjt_call61->_projection.m13 = 0.0f;
    sjt_call61->_projection.m20 = 0.0f;
    sjt_call61->_projection.m21 = 0.0f;
    sjt_call61->_projection.m22 = 0.0f;
    sjt_call61->_projection.m23 = 0.0f;
    sjt_call61->_projection.m30 = 0.0f;
    sjt_call61->_projection.m31 = 0.0f;
    sjt_call61->_projection.m32 = 0.0f;
    sjt_call61->_projection.m33 = 0.0f;
    sjf_mat4(&sjt_call61->_projection);
    sjt_call61->_world._refCount = 1;
    sjt_call61->_world.m00 = 0.0f;
    sjt_call61->_world.m01 = 0.0f;
    sjt_call61->_world.m02 = 0.0f;
    sjt_call61->_world.m03 = 0.0f;
    sjt_call61->_world.m10 = 0.0f;
    sjt_call61->_world.m11 = 0.0f;
    sjt_call61->_world.m12 = 0.0f;
    sjt_call61->_world.m13 = 0.0f;
    sjt_call61->_world.m20 = 0.0f;
    sjt_call61->_world.m21 = 0.0f;
    sjt_call61->_world.m22 = 0.0f;
    sjt_call61->_world.m23 = 0.0f;
    sjt_call61->_world.m30 = 0.0f;
    sjt_call61->_world.m31 = 0.0f;
    sjt_call61->_world.m32 = 0.0f;
    sjt_call61->_world.m33 = 0.0f;
    sjf_mat4(&sjt_call61->_world);
    sjt_call61->_view._refCount = 1;
    sjt_call61->_view.m00 = 0.0f;
    sjt_call61->_view.m01 = 0.0f;
    sjt_call61->_view.m02 = 0.0f;
    sjt_call61->_view.m03 = 0.0f;
    sjt_call61->_view.m10 = 0.0f;
    sjt_call61->_view.m11 = 0.0f;
    sjt_call61->_view.m12 = 0.0f;
    sjt_call61->_view.m13 = 0.0f;
    sjt_call61->_view.m20 = 0.0f;
    sjt_call61->_view.m21 = 0.0f;
    sjt_call61->_view.m22 = 0.0f;
    sjt_call61->_view.m23 = 0.0f;
    sjt_call61->_view.m30 = 0.0f;
    sjt_call61->_view.m31 = 0.0f;
    sjt_call61->_view.m32 = 0.0f;
    sjt_call61->_view.m33 = 0.0f;
    sjf_mat4(&sjt_call61->_view);
    sjt_call61->_light._refCount = 1;
    sjt_call61->_light.pos._refCount = 1;
    sjt_call61->_light.pos.x = 1.0f;
    sjt_call61->_light.pos.y = 1.0f;
    sjt_call61->_light.pos.z = 1.0f;
    sjf_vec3(&sjt_call61->_light.pos);
    sjt_call61->_light.diffusecolor._refCount = 1;
    sjt_call61->_light.diffusecolor.r = 0.5f;
    sjt_call61->_light.diffusecolor.g = 0.5f;
    sjt_call61->_light.diffusecolor.b = 0.0f;
    sjt_call61->_light.diffusecolor.a = 1.0f;
    sjf_color(&sjt_call61->_light.diffusecolor);
    sjt_call61->_light.speccolor._refCount = 1;
    sjt_call61->_light.speccolor.r = 1.0f;
    sjt_call61->_light.speccolor.g = 1.0f;
    sjt_call61->_light.speccolor.b = 1.0f;
    sjt_call61->_light.speccolor.a = 1.0f;
    sjf_color(&sjt_call61->_light.speccolor);
    sjf_light(&sjt_call61->_light);
    sjt_call61->_projectedcenter._refCount = 1;
    sjt_call61->_projectedcenter.x = 0.0f;
    sjt_call61->_projectedcenter.y = 0.0f;
    sjt_call61->_projectedcenter.z = 0.0f;
    sjt_call61->_projectedcenter.w = 0.0f;
    sjf_vec4(&sjt_call61->_projectedcenter);
    sjf_glgenframebuffer(&sjt_call61->_framebuffer);
    sjt_call61->_texture._refCount = 1;
    sjt_call61->_texture.size._refCount = 1;
    sjt_call61->_texture.size.w = 0;
    sjt_call61->_texture.size.h = 0;
    sjf_size(&sjt_call61->_texture.size);
    sjt_call61->_texture.id = (uint32_t)0u;
    sjf_texture(&sjt_call61->_texture);
    sjt_call61->_renderbuffer._refCount = 1;
    sjt_call61->_renderbuffer.size._refCount = 1;
    sjt_call61->_renderbuffer.size.w = 0;
    sjt_call61->_renderbuffer.size.h = 0;
    sjf_size(&sjt_call61->_renderbuffer.size);
    sjt_call61->_renderbuffer.id = (uint32_t)0u;
    sjf_renderbuffer(&sjt_call61->_renderbuffer);
    sjf_scene2dmodel_heap(sjt_call61);
    sjt_cast32 = sjt_call61;
    sjf_scene2dmodel_as_sji_model(sjt_cast32, &sjt_functionParam310);
    if (sjt_functionParam310._parent != 0) {
        sjt_functionParam310._parent->_refCount++;
    }

    sjf_array_heap_iface_model_initat(sjt_parent124, sjt_functionParam309, sjt_functionParam310);
    sjt_parent205 = array8;
    sjt_functionParam502 = 1;
    sjt_call87 = (sjs_scene2dmodel*)malloc(sizeof(sjs_scene2dmodel));
    sjt_call87->_refCount = 1;
    sjt_negate23 = 1.0f;
    result29 = -sjt_negate23;
    sjt_functionParam504 = result29;
    sjt_functionParam505 = 1.0f;
    sjt_negate24 = 1.0f;
    result30 = -sjt_negate24;
    sjt_functionParam506 = result30;
    sjt_functionParam507 = 1.0f;
    sjt_functionParam508 = 0.0f;
    sjt_functionParam509 = 0.0f;
    sjt_functionParam510 = 1.0f;
    sjt_functionParam511 = 0.0f;
    sjt_functionParam512 = 1.0f;
    sjf_planevertexbuffer(sjt_functionParam504, sjt_functionParam505, sjt_functionParam506, sjt_functionParam507, sjt_functionParam508, sjt_functionParam509, sjt_functionParam510, sjt_functionParam511, sjt_functionParam512, &sjt_call87->vertexbuffer);
    sjt_copy54 = &sjv_phongtextureshader;
    sjt_call87->shader._refCount = 1;
    sjf_shader_copy(&sjt_call87->shader, sjt_copy54);
    sjt_call87->texturesize._refCount = 1;
    sjt_call87->texturesize.w = 512;
    sjt_call87->texturesize.h = 512;
    sjf_size(&sjt_call87->texturesize);
    sjt_call87->children._refCount = 1;
    sjt_call87->children.datasize = 3;
    sjt_call87->children.data = 0;
    sjt_call87->children._isglobal = false;
    sjt_call87->children.count = 0;
    sjf_array_heap_iface_element(&sjt_call87->children);
    sjs_array_heap_iface_element* array9;
    array9 = &sjt_call87->children;
    sjt_parent206 = array9;
    sjt_functionParam513 = 0;
    sjt_call88 = (sjs_boxelement*)malloc(sizeof(sjs_boxelement));
    sjt_call88->_refCount = 1;
    sjt_parent207 = &sjv_colors;
    sjf_anon4_white(sjt_parent207, &sjt_call88->color);
    sjt_call88->idealsize._refCount = 1;
    sjt_call88->idealsize.w = 0;
    sjt_call88->idealsize.h = 0;
    sjf_size(&sjt_call88->idealsize);
    sjt_call88->rect._refCount = 1;
    sjt_call88->rect.x = 0;
    sjt_call88->rect.y = 0;
    sjt_call88->rect.w = 0;
    sjt_call88->rect.h = 0;
    sjf_rect(&sjt_call88->rect);
    sjt_call88->boxrenderer._refCount = -1;
    sjf_boxelement_heap(sjt_call88);
    sjt_cast48 = sjt_call88;
    sjf_boxelement_as_sji_element(sjt_cast48, &sjt_functionParam514);
    if (sjt_functionParam514._parent != 0) {
        sjt_functionParam514._parent->_refCount++;
    }

    sjf_array_heap_iface_element_initat(sjt_parent206, sjt_functionParam513, sjt_functionParam514);
    sjt_parent208 = array9;
    sjt_functionParam515 = 1;
    sjt_call89 = (sjs_imageelement*)malloc(sizeof(sjs_imageelement));
    sjt_call89->_refCount = 1;
    sjt_call89->image._refCount = 1;
    sjt_call90._refCount = 1;
    sjt_call90.count = 24;
    sjt_call90.data._refCount = 1;
    sjt_call90.data.datasize = 25;
    sjt_call90.data.data = (void*)sjg_string30;
    sjt_call90.data._isglobal = true;
    sjt_call90.data.count = 25;
    sjf_array_char(&sjt_call90.data);
    sjf_string(&sjt_call90);
    sjt_functionParam517 = &sjt_call90;
    sjf_texturefrompng(sjt_functionParam517, &sjt_call89->image.texture);
    sjt_call89->image.rect._refCount = 1;
    sjt_call89->image.rect.x = 0;
    sjt_call89->image.rect.y = 0;
    sjt_call89->image.rect.w = 0;
    sjt_call89->image.rect.h = 0;
    sjf_rect(&sjt_call89->image.rect);
    sjt_call89->image.margin._refCount = 1;
    sjt_call89->image.margin.l = 0;
    sjt_call89->image.margin.t = 0;
    sjt_call89->image.margin.r = 0;
    sjt_call89->image.margin.b = 0;
    sjf_margin(&sjt_call89->image.margin);
    sjf_image(&sjt_call89->image);
    sjt_call89->_rect._refCount = 1;
    sjt_call89->_rect.x = 0;
    sjt_call89->_rect.y = 0;
    sjt_call89->_rect.w = 0;
    sjt_call89->_rect.h = 0;
    sjf_rect(&sjt_call89->_rect);
    sjt_call89->_margin._refCount = 1;
    sjt_call89->_margin.l = 10;
    sjt_call89->_margin.t = 10;
    sjt_call89->_margin.r = 10;
    sjt_call89->_margin.b = 10;
    sjf_margin(&sjt_call89->_margin);
    sjt_call89->_imagerenderer._refCount = -1;
    sjf_imageelement_heap(sjt_call89);
    sjt_cast49 = sjt_call89;
    sjf_imageelement_as_sji_element(sjt_cast49, &sjt_functionParam516);
    if (sjt_functionParam516._parent != 0) {
        sjt_functionParam516._parent->_refCount++;
    }

    sjf_array_heap_iface_element_initat(sjt_parent208, sjt_functionParam515, sjt_functionParam516);
    sjt_parent209 = array9;
    sjt_functionParam518 = 2;
    sjt_call91 = (sjs_crosshairselement*)malloc(sizeof(sjs_crosshairselement));
    sjt_call91->_refCount = 1;
    sjt_parent210 = &sjv_colors;
    sjf_anon4_green(sjt_parent210, &sjt_call91->color);
    sjt_call91->_rect._refCount = 1;
    sjt_call91->_rect.x = 0;
    sjt_call91->_rect.y = 0;
    sjt_call91->_rect.w = 0;
    sjt_call91->_rect.h = 0;
    sjf_rect(&sjt_call91->_rect);
    sjt_call91->_topdownrenderer._refCount = -1;
    sjt_call91->_leftrightrenderer._refCount = -1;
    sjt_call91->_point._refCount = 1;
    sjt_call91->_point.x = 0;
    sjt_call91->_point.y = 0;
    sjf_point(&sjt_call91->_point);
    sjf_crosshairselement_heap(sjt_call91);
    sjt_cast50 = sjt_call91;
    sjf_crosshairselement_as_sji_element(sjt_cast50, &sjt_functionParam519);
    if (sjt_functionParam519._parent != 0) {
        sjt_functionParam519._parent->_refCount++;
    }

    sjf_array_heap_iface_element_initat(sjt_parent209, sjt_functionParam518, sjt_functionParam519);
    sjt_call87->hasalpha = false;
    sjt_call87->center._refCount = 1;
    sjt_call87->center.x = 0.0f;
    sjt_call87->center.y = 0.0f;
    sjt_call87->center.z = 0.0f;
    sjf_vec3(&sjt_call87->center);
    sjf_mat4_identity(&sjt_call87->model);
    sjt_call87->_innerscene._refCount = 1;
    sjt_call87->_innerscene._size._refCount = 1;
    sjt_call87->_innerscene._size.w = 0;
    sjt_call87->_innerscene._size.h = 0;
    sjf_size(&sjt_call87->_innerscene._size);
    sjt_call87->_innerscene.model._refCount = 1;
    sjt_call87->_innerscene.model.m00 = 0.0f;
    sjt_call87->_innerscene.model.m01 = 0.0f;
    sjt_call87->_innerscene.model.m02 = 0.0f;
    sjt_call87->_innerscene.model.m03 = 0.0f;
    sjt_call87->_innerscene.model.m10 = 0.0f;
    sjt_call87->_innerscene.model.m11 = 0.0f;
    sjt_call87->_innerscene.model.m12 = 0.0f;
    sjt_call87->_innerscene.model.m13 = 0.0f;
    sjt_call87->_innerscene.model.m20 = 0.0f;
    sjt_call87->_innerscene.model.m21 = 0.0f;
    sjt_call87->_innerscene.model.m22 = 0.0f;
    sjt_call87->_innerscene.model.m23 = 0.0f;
    sjt_call87->_innerscene.model.m30 = 0.0f;
    sjt_call87->_innerscene.model.m31 = 0.0f;
    sjt_call87->_innerscene.model.m32 = 0.0f;
    sjt_call87->_innerscene.model.m33 = 0.0f;
    sjf_mat4(&sjt_call87->_innerscene.model);
    sjt_call87->_innerscene.view._refCount = 1;
    sjt_call87->_innerscene.view.m00 = 0.0f;
    sjt_call87->_innerscene.view.m01 = 0.0f;
    sjt_call87->_innerscene.view.m02 = 0.0f;
    sjt_call87->_innerscene.view.m03 = 0.0f;
    sjt_call87->_innerscene.view.m10 = 0.0f;
    sjt_call87->_innerscene.view.m11 = 0.0f;
    sjt_call87->_innerscene.view.m12 = 0.0f;
    sjt_call87->_innerscene.view.m13 = 0.0f;
    sjt_call87->_innerscene.view.m20 = 0.0f;
    sjt_call87->_innerscene.view.m21 = 0.0f;
    sjt_call87->_innerscene.view.m22 = 0.0f;
    sjt_call87->_innerscene.view.m23 = 0.0f;
    sjt_call87->_innerscene.view.m30 = 0.0f;
    sjt_call87->_innerscene.view.m31 = 0.0f;
    sjt_call87->_innerscene.view.m32 = 0.0f;
    sjt_call87->_innerscene.view.m33 = 0.0f;
    sjf_mat4(&sjt_call87->_innerscene.view);
    sjt_call87->_innerscene.projection._refCount = 1;
    sjt_call87->_innerscene.projection.m00 = 0.0f;
    sjt_call87->_innerscene.projection.m01 = 0.0f;
    sjt_call87->_innerscene.projection.m02 = 0.0f;
    sjt_call87->_innerscene.projection.m03 = 0.0f;
    sjt_call87->_innerscene.projection.m10 = 0.0f;
    sjt_call87->_innerscene.projection.m11 = 0.0f;
    sjt_call87->_innerscene.projection.m12 = 0.0f;
    sjt_call87->_innerscene.projection.m13 = 0.0f;
    sjt_call87->_innerscene.projection.m20 = 0.0f;
    sjt_call87->_innerscene.projection.m21 = 0.0f;
    sjt_call87->_innerscene.projection.m22 = 0.0f;
    sjt_call87->_innerscene.projection.m23 = 0.0f;
    sjt_call87->_innerscene.projection.m30 = 0.0f;
    sjt_call87->_innerscene.projection.m31 = 0.0f;
    sjt_call87->_innerscene.projection.m32 = 0.0f;
    sjt_call87->_innerscene.projection.m33 = 0.0f;
    sjf_mat4(&sjt_call87->_innerscene.projection);
    sjf_scene2d(&sjt_call87->_innerscene);
    sjt_call87->_scenerect._refCount = 1;
    sjt_call87->_scenerect.x = 0;
    sjt_call87->_scenerect.y = 0;
    sjt_call87->_scenerect.w = 0;
    sjt_call87->_scenerect.h = 0;
    sjf_rect(&sjt_call87->_scenerect);
    sjt_call87->_projection._refCount = 1;
    sjt_call87->_projection.m00 = 0.0f;
    sjt_call87->_projection.m01 = 0.0f;
    sjt_call87->_projection.m02 = 0.0f;
    sjt_call87->_projection.m03 = 0.0f;
    sjt_call87->_projection.m10 = 0.0f;
    sjt_call87->_projection.m11 = 0.0f;
    sjt_call87->_projection.m12 = 0.0f;
    sjt_call87->_projection.m13 = 0.0f;
    sjt_call87->_projection.m20 = 0.0f;
    sjt_call87->_projection.m21 = 0.0f;
    sjt_call87->_projection.m22 = 0.0f;
    sjt_call87->_projection.m23 = 0.0f;
    sjt_call87->_projection.m30 = 0.0f;
    sjt_call87->_projection.m31 = 0.0f;
    sjt_call87->_projection.m32 = 0.0f;
    sjt_call87->_projection.m33 = 0.0f;
    sjf_mat4(&sjt_call87->_projection);
    sjt_call87->_world._refCount = 1;
    sjt_call87->_world.m00 = 0.0f;
    sjt_call87->_world.m01 = 0.0f;
    sjt_call87->_world.m02 = 0.0f;
    sjt_call87->_world.m03 = 0.0f;
    sjt_call87->_world.m10 = 0.0f;
    sjt_call87->_world.m11 = 0.0f;
    sjt_call87->_world.m12 = 0.0f;
    sjt_call87->_world.m13 = 0.0f;
    sjt_call87->_world.m20 = 0.0f;
    sjt_call87->_world.m21 = 0.0f;
    sjt_call87->_world.m22 = 0.0f;
    sjt_call87->_world.m23 = 0.0f;
    sjt_call87->_world.m30 = 0.0f;
    sjt_call87->_world.m31 = 0.0f;
    sjt_call87->_world.m32 = 0.0f;
    sjt_call87->_world.m33 = 0.0f;
    sjf_mat4(&sjt_call87->_world);
    sjt_call87->_view._refCount = 1;
    sjt_call87->_view.m00 = 0.0f;
    sjt_call87->_view.m01 = 0.0f;
    sjt_call87->_view.m02 = 0.0f;
    sjt_call87->_view.m03 = 0.0f;
    sjt_call87->_view.m10 = 0.0f;
    sjt_call87->_view.m11 = 0.0f;
    sjt_call87->_view.m12 = 0.0f;
    sjt_call87->_view.m13 = 0.0f;
    sjt_call87->_view.m20 = 0.0f;
    sjt_call87->_view.m21 = 0.0f;
    sjt_call87->_view.m22 = 0.0f;
    sjt_call87->_view.m23 = 0.0f;
    sjt_call87->_view.m30 = 0.0f;
    sjt_call87->_view.m31 = 0.0f;
    sjt_call87->_view.m32 = 0.0f;
    sjt_call87->_view.m33 = 0.0f;
    sjf_mat4(&sjt_call87->_view);
    sjt_call87->_light._refCount = 1;
    sjt_call87->_light.pos._refCount = 1;
    sjt_call87->_light.pos.x = 1.0f;
    sjt_call87->_light.pos.y = 1.0f;
    sjt_call87->_light.pos.z = 1.0f;
    sjf_vec3(&sjt_call87->_light.pos);
    sjt_call87->_light.diffusecolor._refCount = 1;
    sjt_call87->_light.diffusecolor.r = 0.5f;
    sjt_call87->_light.diffusecolor.g = 0.5f;
    sjt_call87->_light.diffusecolor.b = 0.0f;
    sjt_call87->_light.diffusecolor.a = 1.0f;
    sjf_color(&sjt_call87->_light.diffusecolor);
    sjt_call87->_light.speccolor._refCount = 1;
    sjt_call87->_light.speccolor.r = 1.0f;
    sjt_call87->_light.speccolor.g = 1.0f;
    sjt_call87->_light.speccolor.b = 1.0f;
    sjt_call87->_light.speccolor.a = 1.0f;
    sjf_color(&sjt_call87->_light.speccolor);
    sjf_light(&sjt_call87->_light);
    sjt_call87->_projectedcenter._refCount = 1;
    sjt_call87->_projectedcenter.x = 0.0f;
    sjt_call87->_projectedcenter.y = 0.0f;
    sjt_call87->_projectedcenter.z = 0.0f;
    sjt_call87->_projectedcenter.w = 0.0f;
    sjf_vec4(&sjt_call87->_projectedcenter);
    sjf_glgenframebuffer(&sjt_call87->_framebuffer);
    sjt_call87->_texture._refCount = 1;
    sjt_call87->_texture.size._refCount = 1;
    sjt_call87->_texture.size.w = 0;
    sjt_call87->_texture.size.h = 0;
    sjf_size(&sjt_call87->_texture.size);
    sjt_call87->_texture.id = (uint32_t)0u;
    sjf_texture(&sjt_call87->_texture);
    sjt_call87->_renderbuffer._refCount = 1;
    sjt_call87->_renderbuffer.size._refCount = 1;
    sjt_call87->_renderbuffer.size.w = 0;
    sjt_call87->_renderbuffer.size.h = 0;
    sjf_size(&sjt_call87->_renderbuffer.size);
    sjt_call87->_renderbuffer.id = (uint32_t)0u;
    sjf_renderbuffer(&sjt_call87->_renderbuffer);
    sjf_scene2dmodel_heap(sjt_call87);
    sjt_cast47 = sjt_call87;
    sjf_scene2dmodel_as_sji_model(sjt_cast47, &sjt_functionParam503);
    if (sjt_functionParam503._parent != 0) {
        sjt_functionParam503._parent->_refCount++;
    }

    sjf_array_heap_iface_model_initat(sjt_parent205, sjt_functionParam502, sjt_functionParam503);
    sjt_call59->_childrenmodel._refCount = 1;
    sjt_call59->_childrenmodel.datasize = 0;
    sjt_call59->_childrenmodel.data = 0;
    sjt_call59->_childrenmodel._isglobal = false;
    sjt_call59->_childrenmodel.count = 0;
    sjf_array_mat4(&sjt_call59->_childrenmodel);
    sjt_call59->_index = 0;
    sjt_call59->_depth = 4;
    sjt_call59->_xincrement = 8.0f;
    sjt_call59->_zincrement = 2.0f;
    sjt_call59->_xoffset = 0.0f;
    sjf_peoplepanel_heap(sjt_call59);
    sjt_cast21 = sjt_call59;
    sjf_peoplepanel_as_sji_model(sjt_cast21, &sjt_functionParam283);
    if (sjt_functionParam283._parent != 0) {
        sjt_functionParam283._parent->_refCount++;
    }

    sjf_array_heap_iface_model_initat(sjt_parent112, sjt_functionParam282, sjt_functionParam283);
    sjt_parent211 = array5;
    sjt_functionParam520 = 3;
    sjt_call92 = (sjs_panel3d*)malloc(sizeof(sjs_panel3d));
    sjt_call92->_refCount = 1;
    sjt_functionParam526 = 0.0f;
    sjt_negate25 = 1.3f;
    result31 = -sjt_negate25;
    sjt_functionParam527 = result31;
    sjt_functionParam528 = 0.0f;
    sjf_mat4_translate(sjt_functionParam526, sjt_functionParam527, sjt_functionParam528, &sjt_call92->model);
    sjt_call92->children._refCount = 1;
    sjt_call92->children.datasize = 10;
    sjt_call92->children.data = 0;
    sjt_call92->children._isglobal = false;
    sjt_call92->children.count = 0;
    sjf_array_heap_iface_model(&sjt_call92->children);
    sjs_array_heap_iface_model* array10;
    array10 = &sjt_call92->children;
    sjt_parent219 = array10;
    sjt_functionParam529 = 0;
    sjt_call93 = (sjs_model*)malloc(sizeof(sjs_model));
    sjt_call93->_refCount = 1;
    sjt_negate26 = 4.3f;
    result32 = -sjt_negate26;
    sjt_functionParam531 = result32;
    sjt_functionParam532 = 4.3f;
    sjt_negate27 = 1.0f;
    result33 = -sjt_negate27;
    sjt_functionParam533 = result33;
    sjt_functionParam534 = 1.0f;
    sjt_functionParam535 = 0.0f;
    sjt_functionParam536 = 0.0f;
    sjt_functionParam537 = 1.0f;
    sjt_functionParam538 = 0.0f;
    sjt_functionParam539 = 1.0f;
    sjf_planevertexbuffer(sjt_functionParam531, sjt_functionParam532, sjt_functionParam533, sjt_functionParam534, sjt_functionParam535, sjt_functionParam536, sjt_functionParam537, sjt_functionParam538, sjt_functionParam539, &sjt_call93->vertexbuffer);
    sjt_copy55 = &sjv_phongtextureshader;
    sjt_call93->shader._refCount = 1;
    sjf_shader_copy(&sjt_call93->shader, sjt_copy55);
    sjt_call94._refCount = 1;
    sjt_call94.count = 16;
    sjt_call94.data._refCount = 1;
    sjt_call94.data.datasize = 17;
    sjt_call94.data.data = (void*)sjg_string32;
    sjt_call94.data._isglobal = true;
    sjt_call94.data.count = 17;
    sjf_array_char(&sjt_call94.data);
    sjf_string(&sjt_call94);
    sjt_functionParam540 = &sjt_call94;
    sjf_texturefrompng(sjt_functionParam540, &sjt_call93->texture);
    sjt_negate28 = 8.6f;
    result34 = -sjt_negate28;
    sjt_functionParam541 = result34;
    sjt_functionParam542 = 0.0f;
    sjt_functionParam543 = 6.2f;
    sjf_mat4_translate(sjt_functionParam541, sjt_functionParam542, sjt_functionParam543, &sjt_call95);
    sjt_parent220 = &sjt_call95;
    sjt_functionParam545 = 2.0f;
    sjt_functionParam546 = 2.0f;
    sjt_functionParam547 = 2.0f;
    sjf_mat4_scale(sjt_functionParam545, sjt_functionParam546, sjt_functionParam547, &sjt_call96);
    sjt_functionParam544 = &sjt_call96;
    sjf_mat4_multiply(sjt_parent220, sjt_functionParam544, &sjt_call93->model);
    sjt_call93->center._refCount = 1;
    sjt_call93->center.x = 0.0f;
    sjt_call93->center.y = 0.0f;
    sjt_call93->center.z = 0.0f;
    sjf_vec3(&sjt_call93->center);
    sjt_call93->hasalpha = true;
    sjt_call93->id._refCount = 1;
    sjt_call93->id.count = 8;
    sjt_call93->id.data._refCount = 1;
    sjt_call93->id.data.datasize = 9;
    sjt_call93->id.data.data = (void*)sjg_string31;
    sjt_call93->id.data._isglobal = true;
    sjt_call93->id.data.count = 9;
    sjf_array_char(&sjt_call93->id.data);
    sjf_string(&sjt_call93->id);
    sjt_call93->_projection._refCount = 1;
    sjt_call93->_projection.m00 = 0.0f;
    sjt_call93->_projection.m01 = 0.0f;
    sjt_call93->_projection.m02 = 0.0f;
    sjt_call93->_projection.m03 = 0.0f;
    sjt_call93->_projection.m10 = 0.0f;
    sjt_call93->_projection.m11 = 0.0f;
    sjt_call93->_projection.m12 = 0.0f;
    sjt_call93->_projection.m13 = 0.0f;
    sjt_call93->_projection.m20 = 0.0f;
    sjt_call93->_projection.m21 = 0.0f;
    sjt_call93->_projection.m22 = 0.0f;
    sjt_call93->_projection.m23 = 0.0f;
    sjt_call93->_projection.m30 = 0.0f;
    sjt_call93->_projection.m31 = 0.0f;
    sjt_call93->_projection.m32 = 0.0f;
    sjt_call93->_projection.m33 = 0.0f;
    sjf_mat4(&sjt_call93->_projection);
    sjt_call93->_view._refCount = 1;
    sjt_call93->_view.m00 = 0.0f;
    sjt_call93->_view.m01 = 0.0f;
    sjt_call93->_view.m02 = 0.0f;
    sjt_call93->_view.m03 = 0.0f;
    sjt_call93->_view.m10 = 0.0f;
    sjt_call93->_view.m11 = 0.0f;
    sjt_call93->_view.m12 = 0.0f;
    sjt_call93->_view.m13 = 0.0f;
    sjt_call93->_view.m20 = 0.0f;
    sjt_call93->_view.m21 = 0.0f;
    sjt_call93->_view.m22 = 0.0f;
    sjt_call93->_view.m23 = 0.0f;
    sjt_call93->_view.m30 = 0.0f;
    sjt_call93->_view.m31 = 0.0f;
    sjt_call93->_view.m32 = 0.0f;
    sjt_call93->_view.m33 = 0.0f;
    sjf_mat4(&sjt_call93->_view);
    sjt_call93->_world._refCount = 1;
    sjt_call93->_world.m00 = 0.0f;
    sjt_call93->_world.m01 = 0.0f;
    sjt_call93->_world.m02 = 0.0f;
    sjt_call93->_world.m03 = 0.0f;
    sjt_call93->_world.m10 = 0.0f;
    sjt_call93->_world.m11 = 0.0f;
    sjt_call93->_world.m12 = 0.0f;
    sjt_call93->_world.m13 = 0.0f;
    sjt_call93->_world.m20 = 0.0f;
    sjt_call93->_world.m21 = 0.0f;
    sjt_call93->_world.m22 = 0.0f;
    sjt_call93->_world.m23 = 0.0f;
    sjt_call93->_world.m30 = 0.0f;
    sjt_call93->_world.m31 = 0.0f;
    sjt_call93->_world.m32 = 0.0f;
    sjt_call93->_world.m33 = 0.0f;
    sjf_mat4(&sjt_call93->_world);
    sjt_call93->_light._refCount = 1;
    sjt_call93->_light.pos._refCount = 1;
    sjt_call93->_light.pos.x = 1.0f;
    sjt_call93->_light.pos.y = 1.0f;
    sjt_call93->_light.pos.z = 1.0f;
    sjf_vec3(&sjt_call93->_light.pos);
    sjt_call93->_light.diffusecolor._refCount = 1;
    sjt_call93->_light.diffusecolor.r = 0.5f;
    sjt_call93->_light.diffusecolor.g = 0.5f;
    sjt_call93->_light.diffusecolor.b = 0.0f;
    sjt_call93->_light.diffusecolor.a = 1.0f;
    sjf_color(&sjt_call93->_light.diffusecolor);
    sjt_call93->_light.speccolor._refCount = 1;
    sjt_call93->_light.speccolor.r = 1.0f;
    sjt_call93->_light.speccolor.g = 1.0f;
    sjt_call93->_light.speccolor.b = 1.0f;
    sjt_call93->_light.speccolor.a = 1.0f;
    sjf_color(&sjt_call93->_light.speccolor);
    sjf_light(&sjt_call93->_light);
    sjt_call93->_projectedcenter._refCount = 1;
    sjt_call93->_projectedcenter.x = 0.0f;
    sjt_call93->_projectedcenter.y = 0.0f;
    sjt_call93->_projectedcenter.z = 0.0f;
    sjf_vec3(&sjt_call93->_projectedcenter);
    sjf_model_heap(sjt_call93);
    sjt_cast52 = sjt_call93;
    sjf_model_as_sji_model(sjt_cast52, &sjt_functionParam530);
    if (sjt_functionParam530._parent != 0) {
        sjt_functionParam530._parent->_refCount++;
    }

    sjf_array_heap_iface_model_initat(sjt_parent219, sjt_functionParam529, sjt_functionParam530);
    sjt_parent221 = array10;
    sjt_functionParam548 = 1;
    sjt_call97 = (sjs_model*)malloc(sizeof(sjs_model));
    sjt_call97->_refCount = 1;
    sjt_negate29 = 4.3f;
    result35 = -sjt_negate29;
    sjt_functionParam550 = result35;
    sjt_functionParam551 = 4.3f;
    sjt_negate30 = 1.0f;
    result36 = -sjt_negate30;
    sjt_functionParam552 = result36;
    sjt_functionParam553 = 1.0f;
    sjt_functionParam554 = 0.0f;
    sjt_functionParam555 = 0.0f;
    sjt_functionParam556 = 1.0f;
    sjt_functionParam557 = 0.0f;
    sjt_functionParam558 = 1.0f;
    sjf_planevertexbuffer(sjt_functionParam550, sjt_functionParam551, sjt_functionParam552, sjt_functionParam553, sjt_functionParam554, sjt_functionParam555, sjt_functionParam556, sjt_functionParam557, sjt_functionParam558, &sjt_call97->vertexbuffer);
    sjt_copy56 = &sjv_phongtextureshader;
    sjt_call97->shader._refCount = 1;
    sjf_shader_copy(&sjt_call97->shader, sjt_copy56);
    sjt_call98._refCount = 1;
    sjt_call98.count = 16;
    sjt_call98.data._refCount = 1;
    sjt_call98.data.datasize = 17;
    sjt_call98.data.data = (void*)sjg_string34;
    sjt_call98.data._isglobal = true;
    sjt_call98.data.count = 17;
    sjf_array_char(&sjt_call98.data);
    sjf_string(&sjt_call98);
    sjt_functionParam559 = &sjt_call98;
    sjf_texturefrompng(sjt_functionParam559, &sjt_call97->texture);
    sjt_functionParam560 = 8.6f;
    sjt_functionParam561 = 0.0f;
    sjt_functionParam562 = 6.2f;
    sjf_mat4_translate(sjt_functionParam560, sjt_functionParam561, sjt_functionParam562, &sjt_call99);
    sjt_parent222 = &sjt_call99;
    sjt_functionParam564 = 2.0f;
    sjt_functionParam565 = 2.0f;
    sjt_functionParam566 = 2.0f;
    sjf_mat4_scale(sjt_functionParam564, sjt_functionParam565, sjt_functionParam566, &sjt_call100);
    sjt_functionParam563 = &sjt_call100;
    sjf_mat4_multiply(sjt_parent222, sjt_functionParam563, &sjt_call97->model);
    sjt_call97->center._refCount = 1;
    sjt_call97->center.x = 0.0f;
    sjt_call97->center.y = 0.0f;
    sjt_call97->center.z = 0.0f;
    sjf_vec3(&sjt_call97->center);
    sjt_call97->hasalpha = true;
    sjt_call97->id._refCount = 1;
    sjt_call97->id.count = 8;
    sjt_call97->id.data._refCount = 1;
    sjt_call97->id.data.datasize = 9;
    sjt_call97->id.data.data = (void*)sjg_string33;
    sjt_call97->id.data._isglobal = true;
    sjt_call97->id.data.count = 9;
    sjf_array_char(&sjt_call97->id.data);
    sjf_string(&sjt_call97->id);
    sjt_call97->_projection._refCount = 1;
    sjt_call97->_projection.m00 = 0.0f;
    sjt_call97->_projection.m01 = 0.0f;
    sjt_call97->_projection.m02 = 0.0f;
    sjt_call97->_projection.m03 = 0.0f;
    sjt_call97->_projection.m10 = 0.0f;
    sjt_call97->_projection.m11 = 0.0f;
    sjt_call97->_projection.m12 = 0.0f;
    sjt_call97->_projection.m13 = 0.0f;
    sjt_call97->_projection.m20 = 0.0f;
    sjt_call97->_projection.m21 = 0.0f;
    sjt_call97->_projection.m22 = 0.0f;
    sjt_call97->_projection.m23 = 0.0f;
    sjt_call97->_projection.m30 = 0.0f;
    sjt_call97->_projection.m31 = 0.0f;
    sjt_call97->_projection.m32 = 0.0f;
    sjt_call97->_projection.m33 = 0.0f;
    sjf_mat4(&sjt_call97->_projection);
    sjt_call97->_view._refCount = 1;
    sjt_call97->_view.m00 = 0.0f;
    sjt_call97->_view.m01 = 0.0f;
    sjt_call97->_view.m02 = 0.0f;
    sjt_call97->_view.m03 = 0.0f;
    sjt_call97->_view.m10 = 0.0f;
    sjt_call97->_view.m11 = 0.0f;
    sjt_call97->_view.m12 = 0.0f;
    sjt_call97->_view.m13 = 0.0f;
    sjt_call97->_view.m20 = 0.0f;
    sjt_call97->_view.m21 = 0.0f;
    sjt_call97->_view.m22 = 0.0f;
    sjt_call97->_view.m23 = 0.0f;
    sjt_call97->_view.m30 = 0.0f;
    sjt_call97->_view.m31 = 0.0f;
    sjt_call97->_view.m32 = 0.0f;
    sjt_call97->_view.m33 = 0.0f;
    sjf_mat4(&sjt_call97->_view);
    sjt_call97->_world._refCount = 1;
    sjt_call97->_world.m00 = 0.0f;
    sjt_call97->_world.m01 = 0.0f;
    sjt_call97->_world.m02 = 0.0f;
    sjt_call97->_world.m03 = 0.0f;
    sjt_call97->_world.m10 = 0.0f;
    sjt_call97->_world.m11 = 0.0f;
    sjt_call97->_world.m12 = 0.0f;
    sjt_call97->_world.m13 = 0.0f;
    sjt_call97->_world.m20 = 0.0f;
    sjt_call97->_world.m21 = 0.0f;
    sjt_call97->_world.m22 = 0.0f;
    sjt_call97->_world.m23 = 0.0f;
    sjt_call97->_world.m30 = 0.0f;
    sjt_call97->_world.m31 = 0.0f;
    sjt_call97->_world.m32 = 0.0f;
    sjt_call97->_world.m33 = 0.0f;
    sjf_mat4(&sjt_call97->_world);
    sjt_call97->_light._refCount = 1;
    sjt_call97->_light.pos._refCount = 1;
    sjt_call97->_light.pos.x = 1.0f;
    sjt_call97->_light.pos.y = 1.0f;
    sjt_call97->_light.pos.z = 1.0f;
    sjf_vec3(&sjt_call97->_light.pos);
    sjt_call97->_light.diffusecolor._refCount = 1;
    sjt_call97->_light.diffusecolor.r = 0.5f;
    sjt_call97->_light.diffusecolor.g = 0.5f;
    sjt_call97->_light.diffusecolor.b = 0.0f;
    sjt_call97->_light.diffusecolor.a = 1.0f;
    sjf_color(&sjt_call97->_light.diffusecolor);
    sjt_call97->_light.speccolor._refCount = 1;
    sjt_call97->_light.speccolor.r = 1.0f;
    sjt_call97->_light.speccolor.g = 1.0f;
    sjt_call97->_light.speccolor.b = 1.0f;
    sjt_call97->_light.speccolor.a = 1.0f;
    sjf_color(&sjt_call97->_light.speccolor);
    sjf_light(&sjt_call97->_light);
    sjt_call97->_projectedcenter._refCount = 1;
    sjt_call97->_projectedcenter.x = 0.0f;
    sjt_call97->_projectedcenter.y = 0.0f;
    sjt_call97->_projectedcenter.z = 0.0f;
    sjf_vec3(&sjt_call97->_projectedcenter);
    sjf_model_heap(sjt_call97);
    sjt_cast53 = sjt_call97;
    sjf_model_as_sji_model(sjt_cast53, &sjt_functionParam549);
    if (sjt_functionParam549._parent != 0) {
        sjt_functionParam549._parent->_refCount++;
    }

    sjf_array_heap_iface_model_initat(sjt_parent221, sjt_functionParam548, sjt_functionParam549);
    sjt_parent223 = array10;
    sjt_functionParam567 = 2;
    sjt_call101 = (sjs_model*)malloc(sizeof(sjs_model));
    sjt_call101->_refCount = 1;
    sjt_negate31 = 4.3f;
    result37 = -sjt_negate31;
    sjt_functionParam569 = result37;
    sjt_functionParam570 = 4.3f;
    sjt_negate32 = 1.0f;
    result38 = -sjt_negate32;
    sjt_functionParam571 = result38;
    sjt_functionParam572 = 1.0f;
    sjt_functionParam573 = 0.0f;
    sjt_functionParam574 = 0.0f;
    sjt_functionParam575 = 1.0f;
    sjt_functionParam576 = 0.0f;
    sjt_functionParam577 = 1.0f;
    sjf_planevertexbuffer(sjt_functionParam569, sjt_functionParam570, sjt_functionParam571, sjt_functionParam572, sjt_functionParam573, sjt_functionParam574, sjt_functionParam575, sjt_functionParam576, sjt_functionParam577, &sjt_call101->vertexbuffer);
    sjt_copy57 = &sjv_phongtextureshader;
    sjt_call101->shader._refCount = 1;
    sjf_shader_copy(&sjt_call101->shader, sjt_copy57);
    sjt_call102._refCount = 1;
    sjt_call102.count = 16;
    sjt_call102.data._refCount = 1;
    sjt_call102.data.datasize = 17;
    sjt_call102.data.data = (void*)sjg_string36;
    sjt_call102.data._isglobal = true;
    sjt_call102.data.count = 17;
    sjf_array_char(&sjt_call102.data);
    sjf_string(&sjt_call102);
    sjt_functionParam578 = &sjt_call102;
    sjf_texturefrompng(sjt_functionParam578, &sjt_call101->texture);
    sjt_negate33 = 8.6f;
    result39 = -sjt_negate33;
    sjt_functionParam579 = result39;
    sjt_functionParam580 = 0.0f;
    sjt_functionParam581 = 4.2f;
    sjf_mat4_translate(sjt_functionParam579, sjt_functionParam580, sjt_functionParam581, &sjt_call103);
    sjt_parent224 = &sjt_call103;
    sjt_functionParam583 = 2.0f;
    sjt_functionParam584 = 2.0f;
    sjt_functionParam585 = 2.0f;
    sjf_mat4_scale(sjt_functionParam583, sjt_functionParam584, sjt_functionParam585, &sjt_call104);
    sjt_functionParam582 = &sjt_call104;
    sjf_mat4_multiply(sjt_parent224, sjt_functionParam582, &sjt_call101->model);
    sjt_call101->center._refCount = 1;
    sjt_call101->center.x = 0.0f;
    sjt_call101->center.y = 0.0f;
    sjt_call101->center.z = 0.0f;
    sjf_vec3(&sjt_call101->center);
    sjt_call101->hasalpha = true;
    sjt_call101->id._refCount = 1;
    sjt_call101->id.count = 8;
    sjt_call101->id.data._refCount = 1;
    sjt_call101->id.data.datasize = 9;
    sjt_call101->id.data.data = (void*)sjg_string35;
    sjt_call101->id.data._isglobal = true;
    sjt_call101->id.data.count = 9;
    sjf_array_char(&sjt_call101->id.data);
    sjf_string(&sjt_call101->id);
    sjt_call101->_projection._refCount = 1;
    sjt_call101->_projection.m00 = 0.0f;
    sjt_call101->_projection.m01 = 0.0f;
    sjt_call101->_projection.m02 = 0.0f;
    sjt_call101->_projection.m03 = 0.0f;
    sjt_call101->_projection.m10 = 0.0f;
    sjt_call101->_projection.m11 = 0.0f;
    sjt_call101->_projection.m12 = 0.0f;
    sjt_call101->_projection.m13 = 0.0f;
    sjt_call101->_projection.m20 = 0.0f;
    sjt_call101->_projection.m21 = 0.0f;
    sjt_call101->_projection.m22 = 0.0f;
    sjt_call101->_projection.m23 = 0.0f;
    sjt_call101->_projection.m30 = 0.0f;
    sjt_call101->_projection.m31 = 0.0f;
    sjt_call101->_projection.m32 = 0.0f;
    sjt_call101->_projection.m33 = 0.0f;
    sjf_mat4(&sjt_call101->_projection);
    sjt_call101->_view._refCount = 1;
    sjt_call101->_view.m00 = 0.0f;
    sjt_call101->_view.m01 = 0.0f;
    sjt_call101->_view.m02 = 0.0f;
    sjt_call101->_view.m03 = 0.0f;
    sjt_call101->_view.m10 = 0.0f;
    sjt_call101->_view.m11 = 0.0f;
    sjt_call101->_view.m12 = 0.0f;
    sjt_call101->_view.m13 = 0.0f;
    sjt_call101->_view.m20 = 0.0f;
    sjt_call101->_view.m21 = 0.0f;
    sjt_call101->_view.m22 = 0.0f;
    sjt_call101->_view.m23 = 0.0f;
    sjt_call101->_view.m30 = 0.0f;
    sjt_call101->_view.m31 = 0.0f;
    sjt_call101->_view.m32 = 0.0f;
    sjt_call101->_view.m33 = 0.0f;
    sjf_mat4(&sjt_call101->_view);
    sjt_call101->_world._refCount = 1;
    sjt_call101->_world.m00 = 0.0f;
    sjt_call101->_world.m01 = 0.0f;
    sjt_call101->_world.m02 = 0.0f;
    sjt_call101->_world.m03 = 0.0f;
    sjt_call101->_world.m10 = 0.0f;
    sjt_call101->_world.m11 = 0.0f;
    sjt_call101->_world.m12 = 0.0f;
    sjt_call101->_world.m13 = 0.0f;
    sjt_call101->_world.m20 = 0.0f;
    sjt_call101->_world.m21 = 0.0f;
    sjt_call101->_world.m22 = 0.0f;
    sjt_call101->_world.m23 = 0.0f;
    sjt_call101->_world.m30 = 0.0f;
    sjt_call101->_world.m31 = 0.0f;
    sjt_call101->_world.m32 = 0.0f;
    sjt_call101->_world.m33 = 0.0f;
    sjf_mat4(&sjt_call101->_world);
    sjt_call101->_light._refCount = 1;
    sjt_call101->_light.pos._refCount = 1;
    sjt_call101->_light.pos.x = 1.0f;
    sjt_call101->_light.pos.y = 1.0f;
    sjt_call101->_light.pos.z = 1.0f;
    sjf_vec3(&sjt_call101->_light.pos);
    sjt_call101->_light.diffusecolor._refCount = 1;
    sjt_call101->_light.diffusecolor.r = 0.5f;
    sjt_call101->_light.diffusecolor.g = 0.5f;
    sjt_call101->_light.diffusecolor.b = 0.0f;
    sjt_call101->_light.diffusecolor.a = 1.0f;
    sjf_color(&sjt_call101->_light.diffusecolor);
    sjt_call101->_light.speccolor._refCount = 1;
    sjt_call101->_light.speccolor.r = 1.0f;
    sjt_call101->_light.speccolor.g = 1.0f;
    sjt_call101->_light.speccolor.b = 1.0f;
    sjt_call101->_light.speccolor.a = 1.0f;
    sjf_color(&sjt_call101->_light.speccolor);
    sjf_light(&sjt_call101->_light);
    sjt_call101->_projectedcenter._refCount = 1;
    sjt_call101->_projectedcenter.x = 0.0f;
    sjt_call101->_projectedcenter.y = 0.0f;
    sjt_call101->_projectedcenter.z = 0.0f;
    sjf_vec3(&sjt_call101->_projectedcenter);
    sjf_model_heap(sjt_call101);
    sjt_cast54 = sjt_call101;
    sjf_model_as_sji_model(sjt_cast54, &sjt_functionParam568);
    if (sjt_functionParam568._parent != 0) {
        sjt_functionParam568._parent->_refCount++;
    }

    sjf_array_heap_iface_model_initat(sjt_parent223, sjt_functionParam567, sjt_functionParam568);
    sjt_parent225 = array10;
    sjt_functionParam586 = 3;
    sjt_call105 = (sjs_model*)malloc(sizeof(sjs_model));
    sjt_call105->_refCount = 1;
    sjt_negate34 = 4.3f;
    result40 = -sjt_negate34;
    sjt_functionParam588 = result40;
    sjt_functionParam589 = 4.3f;
    sjt_negate35 = 1.0f;
    result41 = -sjt_negate35;
    sjt_functionParam590 = result41;
    sjt_functionParam591 = 1.0f;
    sjt_functionParam592 = 0.0f;
    sjt_functionParam593 = 0.0f;
    sjt_functionParam594 = 1.0f;
    sjt_functionParam595 = 0.0f;
    sjt_functionParam596 = 1.0f;
    sjf_planevertexbuffer(sjt_functionParam588, sjt_functionParam589, sjt_functionParam590, sjt_functionParam591, sjt_functionParam592, sjt_functionParam593, sjt_functionParam594, sjt_functionParam595, sjt_functionParam596, &sjt_call105->vertexbuffer);
    sjt_copy58 = &sjv_phongtextureshader;
    sjt_call105->shader._refCount = 1;
    sjf_shader_copy(&sjt_call105->shader, sjt_copy58);
    sjt_call106._refCount = 1;
    sjt_call106.count = 16;
    sjt_call106.data._refCount = 1;
    sjt_call106.data.datasize = 17;
    sjt_call106.data.data = (void*)sjg_string38;
    sjt_call106.data._isglobal = true;
    sjt_call106.data.count = 17;
    sjf_array_char(&sjt_call106.data);
    sjf_string(&sjt_call106);
    sjt_functionParam597 = &sjt_call106;
    sjf_texturefrompng(sjt_functionParam597, &sjt_call105->texture);
    sjt_functionParam598 = 8.6f;
    sjt_functionParam599 = 0.0f;
    sjt_functionParam600 = 4.2f;
    sjf_mat4_translate(sjt_functionParam598, sjt_functionParam599, sjt_functionParam600, &sjt_call107);
    sjt_parent226 = &sjt_call107;
    sjt_functionParam602 = 2.0f;
    sjt_functionParam603 = 2.0f;
    sjt_functionParam604 = 2.0f;
    sjf_mat4_scale(sjt_functionParam602, sjt_functionParam603, sjt_functionParam604, &sjt_call108);
    sjt_functionParam601 = &sjt_call108;
    sjf_mat4_multiply(sjt_parent226, sjt_functionParam601, &sjt_call105->model);
    sjt_call105->center._refCount = 1;
    sjt_call105->center.x = 0.0f;
    sjt_call105->center.y = 0.0f;
    sjt_call105->center.z = 0.0f;
    sjf_vec3(&sjt_call105->center);
    sjt_call105->hasalpha = true;
    sjt_call105->id._refCount = 1;
    sjt_call105->id.count = 8;
    sjt_call105->id.data._refCount = 1;
    sjt_call105->id.data.datasize = 9;
    sjt_call105->id.data.data = (void*)sjg_string37;
    sjt_call105->id.data._isglobal = true;
    sjt_call105->id.data.count = 9;
    sjf_array_char(&sjt_call105->id.data);
    sjf_string(&sjt_call105->id);
    sjt_call105->_projection._refCount = 1;
    sjt_call105->_projection.m00 = 0.0f;
    sjt_call105->_projection.m01 = 0.0f;
    sjt_call105->_projection.m02 = 0.0f;
    sjt_call105->_projection.m03 = 0.0f;
    sjt_call105->_projection.m10 = 0.0f;
    sjt_call105->_projection.m11 = 0.0f;
    sjt_call105->_projection.m12 = 0.0f;
    sjt_call105->_projection.m13 = 0.0f;
    sjt_call105->_projection.m20 = 0.0f;
    sjt_call105->_projection.m21 = 0.0f;
    sjt_call105->_projection.m22 = 0.0f;
    sjt_call105->_projection.m23 = 0.0f;
    sjt_call105->_projection.m30 = 0.0f;
    sjt_call105->_projection.m31 = 0.0f;
    sjt_call105->_projection.m32 = 0.0f;
    sjt_call105->_projection.m33 = 0.0f;
    sjf_mat4(&sjt_call105->_projection);
    sjt_call105->_view._refCount = 1;
    sjt_call105->_view.m00 = 0.0f;
    sjt_call105->_view.m01 = 0.0f;
    sjt_call105->_view.m02 = 0.0f;
    sjt_call105->_view.m03 = 0.0f;
    sjt_call105->_view.m10 = 0.0f;
    sjt_call105->_view.m11 = 0.0f;
    sjt_call105->_view.m12 = 0.0f;
    sjt_call105->_view.m13 = 0.0f;
    sjt_call105->_view.m20 = 0.0f;
    sjt_call105->_view.m21 = 0.0f;
    sjt_call105->_view.m22 = 0.0f;
    sjt_call105->_view.m23 = 0.0f;
    sjt_call105->_view.m30 = 0.0f;
    sjt_call105->_view.m31 = 0.0f;
    sjt_call105->_view.m32 = 0.0f;
    sjt_call105->_view.m33 = 0.0f;
    sjf_mat4(&sjt_call105->_view);
    sjt_call105->_world._refCount = 1;
    sjt_call105->_world.m00 = 0.0f;
    sjt_call105->_world.m01 = 0.0f;
    sjt_call105->_world.m02 = 0.0f;
    sjt_call105->_world.m03 = 0.0f;
    sjt_call105->_world.m10 = 0.0f;
    sjt_call105->_world.m11 = 0.0f;
    sjt_call105->_world.m12 = 0.0f;
    sjt_call105->_world.m13 = 0.0f;
    sjt_call105->_world.m20 = 0.0f;
    sjt_call105->_world.m21 = 0.0f;
    sjt_call105->_world.m22 = 0.0f;
    sjt_call105->_world.m23 = 0.0f;
    sjt_call105->_world.m30 = 0.0f;
    sjt_call105->_world.m31 = 0.0f;
    sjt_call105->_world.m32 = 0.0f;
    sjt_call105->_world.m33 = 0.0f;
    sjf_mat4(&sjt_call105->_world);
    sjt_call105->_light._refCount = 1;
    sjt_call105->_light.pos._refCount = 1;
    sjt_call105->_light.pos.x = 1.0f;
    sjt_call105->_light.pos.y = 1.0f;
    sjt_call105->_light.pos.z = 1.0f;
    sjf_vec3(&sjt_call105->_light.pos);
    sjt_call105->_light.diffusecolor._refCount = 1;
    sjt_call105->_light.diffusecolor.r = 0.5f;
    sjt_call105->_light.diffusecolor.g = 0.5f;
    sjt_call105->_light.diffusecolor.b = 0.0f;
    sjt_call105->_light.diffusecolor.a = 1.0f;
    sjf_color(&sjt_call105->_light.diffusecolor);
    sjt_call105->_light.speccolor._refCount = 1;
    sjt_call105->_light.speccolor.r = 1.0f;
    sjt_call105->_light.speccolor.g = 1.0f;
    sjt_call105->_light.speccolor.b = 1.0f;
    sjt_call105->_light.speccolor.a = 1.0f;
    sjf_color(&sjt_call105->_light.speccolor);
    sjf_light(&sjt_call105->_light);
    sjt_call105->_projectedcenter._refCount = 1;
    sjt_call105->_projectedcenter.x = 0.0f;
    sjt_call105->_projectedcenter.y = 0.0f;
    sjt_call105->_projectedcenter.z = 0.0f;
    sjf_vec3(&sjt_call105->_projectedcenter);
    sjf_model_heap(sjt_call105);
    sjt_cast55 = sjt_call105;
    sjf_model_as_sji_model(sjt_cast55, &sjt_functionParam587);
    if (sjt_functionParam587._parent != 0) {
        sjt_functionParam587._parent->_refCount++;
    }

    sjf_array_heap_iface_model_initat(sjt_parent225, sjt_functionParam586, sjt_functionParam587);
    sjt_parent227 = array10;
    sjt_functionParam605 = 4;
    sjt_call109 = (sjs_model*)malloc(sizeof(sjs_model));
    sjt_call109->_refCount = 1;
    sjt_negate36 = 4.3f;
    result42 = -sjt_negate36;
    sjt_functionParam607 = result42;
    sjt_functionParam608 = 4.3f;
    sjt_negate37 = 1.0f;
    result43 = -sjt_negate37;
    sjt_functionParam609 = result43;
    sjt_functionParam610 = 1.0f;
    sjt_functionParam611 = 0.0f;
    sjt_functionParam612 = 0.0f;
    sjt_functionParam613 = 1.0f;
    sjt_functionParam614 = 0.0f;
    sjt_functionParam615 = 1.0f;
    sjf_planevertexbuffer(sjt_functionParam607, sjt_functionParam608, sjt_functionParam609, sjt_functionParam610, sjt_functionParam611, sjt_functionParam612, sjt_functionParam613, sjt_functionParam614, sjt_functionParam615, &sjt_call109->vertexbuffer);
    sjt_copy59 = &sjv_phongtextureshader;
    sjt_call109->shader._refCount = 1;
    sjf_shader_copy(&sjt_call109->shader, sjt_copy59);
    sjt_call110._refCount = 1;
    sjt_call110.count = 16;
    sjt_call110.data._refCount = 1;
    sjt_call110.data.datasize = 17;
    sjt_call110.data.data = (void*)sjg_string40;
    sjt_call110.data._isglobal = true;
    sjt_call110.data.count = 17;
    sjf_array_char(&sjt_call110.data);
    sjf_string(&sjt_call110);
    sjt_functionParam616 = &sjt_call110;
    sjf_texturefrompng(sjt_functionParam616, &sjt_call109->texture);
    sjt_negate38 = 9.6f;
    result44 = -sjt_negate38;
    sjt_functionParam617 = result44;
    sjt_functionParam618 = 0.0f;
    sjt_functionParam619 = 2.2f;
    sjf_mat4_translate(sjt_functionParam617, sjt_functionParam618, sjt_functionParam619, &sjt_call111);
    sjt_parent228 = &sjt_call111;
    sjt_functionParam621 = 2.0f;
    sjt_functionParam622 = 2.0f;
    sjt_functionParam623 = 2.0f;
    sjf_mat4_scale(sjt_functionParam621, sjt_functionParam622, sjt_functionParam623, &sjt_call112);
    sjt_functionParam620 = &sjt_call112;
    sjf_mat4_multiply(sjt_parent228, sjt_functionParam620, &sjt_call109->model);
    sjt_call109->center._refCount = 1;
    sjt_call109->center.x = 0.0f;
    sjt_call109->center.y = 0.0f;
    sjt_call109->center.z = 0.0f;
    sjf_vec3(&sjt_call109->center);
    sjt_call109->hasalpha = true;
    sjt_call109->id._refCount = 1;
    sjt_call109->id.count = 8;
    sjt_call109->id.data._refCount = 1;
    sjt_call109->id.data.datasize = 9;
    sjt_call109->id.data.data = (void*)sjg_string39;
    sjt_call109->id.data._isglobal = true;
    sjt_call109->id.data.count = 9;
    sjf_array_char(&sjt_call109->id.data);
    sjf_string(&sjt_call109->id);
    sjt_call109->_projection._refCount = 1;
    sjt_call109->_projection.m00 = 0.0f;
    sjt_call109->_projection.m01 = 0.0f;
    sjt_call109->_projection.m02 = 0.0f;
    sjt_call109->_projection.m03 = 0.0f;
    sjt_call109->_projection.m10 = 0.0f;
    sjt_call109->_projection.m11 = 0.0f;
    sjt_call109->_projection.m12 = 0.0f;
    sjt_call109->_projection.m13 = 0.0f;
    sjt_call109->_projection.m20 = 0.0f;
    sjt_call109->_projection.m21 = 0.0f;
    sjt_call109->_projection.m22 = 0.0f;
    sjt_call109->_projection.m23 = 0.0f;
    sjt_call109->_projection.m30 = 0.0f;
    sjt_call109->_projection.m31 = 0.0f;
    sjt_call109->_projection.m32 = 0.0f;
    sjt_call109->_projection.m33 = 0.0f;
    sjf_mat4(&sjt_call109->_projection);
    sjt_call109->_view._refCount = 1;
    sjt_call109->_view.m00 = 0.0f;
    sjt_call109->_view.m01 = 0.0f;
    sjt_call109->_view.m02 = 0.0f;
    sjt_call109->_view.m03 = 0.0f;
    sjt_call109->_view.m10 = 0.0f;
    sjt_call109->_view.m11 = 0.0f;
    sjt_call109->_view.m12 = 0.0f;
    sjt_call109->_view.m13 = 0.0f;
    sjt_call109->_view.m20 = 0.0f;
    sjt_call109->_view.m21 = 0.0f;
    sjt_call109->_view.m22 = 0.0f;
    sjt_call109->_view.m23 = 0.0f;
    sjt_call109->_view.m30 = 0.0f;
    sjt_call109->_view.m31 = 0.0f;
    sjt_call109->_view.m32 = 0.0f;
    sjt_call109->_view.m33 = 0.0f;
    sjf_mat4(&sjt_call109->_view);
    sjt_call109->_world._refCount = 1;
    sjt_call109->_world.m00 = 0.0f;
    sjt_call109->_world.m01 = 0.0f;
    sjt_call109->_world.m02 = 0.0f;
    sjt_call109->_world.m03 = 0.0f;
    sjt_call109->_world.m10 = 0.0f;
    sjt_call109->_world.m11 = 0.0f;
    sjt_call109->_world.m12 = 0.0f;
    sjt_call109->_world.m13 = 0.0f;
    sjt_call109->_world.m20 = 0.0f;
    sjt_call109->_world.m21 = 0.0f;
    sjt_call109->_world.m22 = 0.0f;
    sjt_call109->_world.m23 = 0.0f;
    sjt_call109->_world.m30 = 0.0f;
    sjt_call109->_world.m31 = 0.0f;
    sjt_call109->_world.m32 = 0.0f;
    sjt_call109->_world.m33 = 0.0f;
    sjf_mat4(&sjt_call109->_world);
    sjt_call109->_light._refCount = 1;
    sjt_call109->_light.pos._refCount = 1;
    sjt_call109->_light.pos.x = 1.0f;
    sjt_call109->_light.pos.y = 1.0f;
    sjt_call109->_light.pos.z = 1.0f;
    sjf_vec3(&sjt_call109->_light.pos);
    sjt_call109->_light.diffusecolor._refCount = 1;
    sjt_call109->_light.diffusecolor.r = 0.5f;
    sjt_call109->_light.diffusecolor.g = 0.5f;
    sjt_call109->_light.diffusecolor.b = 0.0f;
    sjt_call109->_light.diffusecolor.a = 1.0f;
    sjf_color(&sjt_call109->_light.diffusecolor);
    sjt_call109->_light.speccolor._refCount = 1;
    sjt_call109->_light.speccolor.r = 1.0f;
    sjt_call109->_light.speccolor.g = 1.0f;
    sjt_call109->_light.speccolor.b = 1.0f;
    sjt_call109->_light.speccolor.a = 1.0f;
    sjf_color(&sjt_call109->_light.speccolor);
    sjf_light(&sjt_call109->_light);
    sjt_call109->_projectedcenter._refCount = 1;
    sjt_call109->_projectedcenter.x = 0.0f;
    sjt_call109->_projectedcenter.y = 0.0f;
    sjt_call109->_projectedcenter.z = 0.0f;
    sjf_vec3(&sjt_call109->_projectedcenter);
    sjf_model_heap(sjt_call109);
    sjt_cast56 = sjt_call109;
    sjf_model_as_sji_model(sjt_cast56, &sjt_functionParam606);
    if (sjt_functionParam606._parent != 0) {
        sjt_functionParam606._parent->_refCount++;
    }

    sjf_array_heap_iface_model_initat(sjt_parent227, sjt_functionParam605, sjt_functionParam606);
    sjt_parent229 = array10;
    sjt_functionParam624 = 5;
    sjt_call113 = (sjs_model*)malloc(sizeof(sjs_model));
    sjt_call113->_refCount = 1;
    sjt_negate39 = 4.3f;
    result45 = -sjt_negate39;
    sjt_functionParam626 = result45;
    sjt_functionParam627 = 4.3f;
    sjt_negate40 = 1.0f;
    result46 = -sjt_negate40;
    sjt_functionParam628 = result46;
    sjt_functionParam629 = 1.0f;
    sjt_functionParam630 = 0.0f;
    sjt_functionParam631 = 0.0f;
    sjt_functionParam632 = 1.0f;
    sjt_functionParam633 = 0.0f;
    sjt_functionParam634 = 1.0f;
    sjf_planevertexbuffer(sjt_functionParam626, sjt_functionParam627, sjt_functionParam628, sjt_functionParam629, sjt_functionParam630, sjt_functionParam631, sjt_functionParam632, sjt_functionParam633, sjt_functionParam634, &sjt_call113->vertexbuffer);
    sjt_copy60 = &sjv_phongtextureshader;
    sjt_call113->shader._refCount = 1;
    sjf_shader_copy(&sjt_call113->shader, sjt_copy60);
    sjt_call114._refCount = 1;
    sjt_call114.count = 16;
    sjt_call114.data._refCount = 1;
    sjt_call114.data.datasize = 17;
    sjt_call114.data.data = (void*)sjg_string42;
    sjt_call114.data._isglobal = true;
    sjt_call114.data.count = 17;
    sjf_array_char(&sjt_call114.data);
    sjf_string(&sjt_call114);
    sjt_functionParam635 = &sjt_call114;
    sjf_texturefrompng(sjt_functionParam635, &sjt_call113->texture);
    sjt_functionParam636 = 7.6f;
    sjt_functionParam637 = 0.0f;
    sjt_functionParam638 = 2.2f;
    sjf_mat4_translate(sjt_functionParam636, sjt_functionParam637, sjt_functionParam638, &sjt_call115);
    sjt_parent230 = &sjt_call115;
    sjt_functionParam640 = 2.0f;
    sjt_functionParam641 = 2.0f;
    sjt_functionParam642 = 2.0f;
    sjf_mat4_scale(sjt_functionParam640, sjt_functionParam641, sjt_functionParam642, &sjt_call116);
    sjt_functionParam639 = &sjt_call116;
    sjf_mat4_multiply(sjt_parent230, sjt_functionParam639, &sjt_call113->model);
    sjt_call113->center._refCount = 1;
    sjt_call113->center.x = 0.0f;
    sjt_call113->center.y = 0.0f;
    sjt_call113->center.z = 0.0f;
    sjf_vec3(&sjt_call113->center);
    sjt_call113->hasalpha = true;
    sjt_call113->id._refCount = 1;
    sjt_call113->id.count = 8;
    sjt_call113->id.data._refCount = 1;
    sjt_call113->id.data.datasize = 9;
    sjt_call113->id.data.data = (void*)sjg_string41;
    sjt_call113->id.data._isglobal = true;
    sjt_call113->id.data.count = 9;
    sjf_array_char(&sjt_call113->id.data);
    sjf_string(&sjt_call113->id);
    sjt_call113->_projection._refCount = 1;
    sjt_call113->_projection.m00 = 0.0f;
    sjt_call113->_projection.m01 = 0.0f;
    sjt_call113->_projection.m02 = 0.0f;
    sjt_call113->_projection.m03 = 0.0f;
    sjt_call113->_projection.m10 = 0.0f;
    sjt_call113->_projection.m11 = 0.0f;
    sjt_call113->_projection.m12 = 0.0f;
    sjt_call113->_projection.m13 = 0.0f;
    sjt_call113->_projection.m20 = 0.0f;
    sjt_call113->_projection.m21 = 0.0f;
    sjt_call113->_projection.m22 = 0.0f;
    sjt_call113->_projection.m23 = 0.0f;
    sjt_call113->_projection.m30 = 0.0f;
    sjt_call113->_projection.m31 = 0.0f;
    sjt_call113->_projection.m32 = 0.0f;
    sjt_call113->_projection.m33 = 0.0f;
    sjf_mat4(&sjt_call113->_projection);
    sjt_call113->_view._refCount = 1;
    sjt_call113->_view.m00 = 0.0f;
    sjt_call113->_view.m01 = 0.0f;
    sjt_call113->_view.m02 = 0.0f;
    sjt_call113->_view.m03 = 0.0f;
    sjt_call113->_view.m10 = 0.0f;
    sjt_call113->_view.m11 = 0.0f;
    sjt_call113->_view.m12 = 0.0f;
    sjt_call113->_view.m13 = 0.0f;
    sjt_call113->_view.m20 = 0.0f;
    sjt_call113->_view.m21 = 0.0f;
    sjt_call113->_view.m22 = 0.0f;
    sjt_call113->_view.m23 = 0.0f;
    sjt_call113->_view.m30 = 0.0f;
    sjt_call113->_view.m31 = 0.0f;
    sjt_call113->_view.m32 = 0.0f;
    sjt_call113->_view.m33 = 0.0f;
    sjf_mat4(&sjt_call113->_view);
    sjt_call113->_world._refCount = 1;
    sjt_call113->_world.m00 = 0.0f;
    sjt_call113->_world.m01 = 0.0f;
    sjt_call113->_world.m02 = 0.0f;
    sjt_call113->_world.m03 = 0.0f;
    sjt_call113->_world.m10 = 0.0f;
    sjt_call113->_world.m11 = 0.0f;
    sjt_call113->_world.m12 = 0.0f;
    sjt_call113->_world.m13 = 0.0f;
    sjt_call113->_world.m20 = 0.0f;
    sjt_call113->_world.m21 = 0.0f;
    sjt_call113->_world.m22 = 0.0f;
    sjt_call113->_world.m23 = 0.0f;
    sjt_call113->_world.m30 = 0.0f;
    sjt_call113->_world.m31 = 0.0f;
    sjt_call113->_world.m32 = 0.0f;
    sjt_call113->_world.m33 = 0.0f;
    sjf_mat4(&sjt_call113->_world);
    sjt_call113->_light._refCount = 1;
    sjt_call113->_light.pos._refCount = 1;
    sjt_call113->_light.pos.x = 1.0f;
    sjt_call113->_light.pos.y = 1.0f;
    sjt_call113->_light.pos.z = 1.0f;
    sjf_vec3(&sjt_call113->_light.pos);
    sjt_call113->_light.diffusecolor._refCount = 1;
    sjt_call113->_light.diffusecolor.r = 0.5f;
    sjt_call113->_light.diffusecolor.g = 0.5f;
    sjt_call113->_light.diffusecolor.b = 0.0f;
    sjt_call113->_light.diffusecolor.a = 1.0f;
    sjf_color(&sjt_call113->_light.diffusecolor);
    sjt_call113->_light.speccolor._refCount = 1;
    sjt_call113->_light.speccolor.r = 1.0f;
    sjt_call113->_light.speccolor.g = 1.0f;
    sjt_call113->_light.speccolor.b = 1.0f;
    sjt_call113->_light.speccolor.a = 1.0f;
    sjf_color(&sjt_call113->_light.speccolor);
    sjf_light(&sjt_call113->_light);
    sjt_call113->_projectedcenter._refCount = 1;
    sjt_call113->_projectedcenter.x = 0.0f;
    sjt_call113->_projectedcenter.y = 0.0f;
    sjt_call113->_projectedcenter.z = 0.0f;
    sjf_vec3(&sjt_call113->_projectedcenter);
    sjf_model_heap(sjt_call113);
    sjt_cast57 = sjt_call113;
    sjf_model_as_sji_model(sjt_cast57, &sjt_functionParam625);
    if (sjt_functionParam625._parent != 0) {
        sjt_functionParam625._parent->_refCount++;
    }

    sjf_array_heap_iface_model_initat(sjt_parent229, sjt_functionParam624, sjt_functionParam625);
    sjt_parent231 = array10;
    sjt_functionParam643 = 6;
    sjt_call117 = (sjs_model*)malloc(sizeof(sjs_model));
    sjt_call117->_refCount = 1;
    sjt_negate41 = 4.3f;
    result47 = -sjt_negate41;
    sjt_functionParam645 = result47;
    sjt_functionParam646 = 4.3f;
    sjt_negate42 = 1.0f;
    result48 = -sjt_negate42;
    sjt_functionParam647 = result48;
    sjt_functionParam648 = 1.0f;
    sjt_functionParam649 = 0.0f;
    sjt_functionParam650 = 0.0f;
    sjt_functionParam651 = 1.0f;
    sjt_functionParam652 = 0.0f;
    sjt_functionParam653 = 1.0f;
    sjf_planevertexbuffer(sjt_functionParam645, sjt_functionParam646, sjt_functionParam647, sjt_functionParam648, sjt_functionParam649, sjt_functionParam650, sjt_functionParam651, sjt_functionParam652, sjt_functionParam653, &sjt_call117->vertexbuffer);
    sjt_copy61 = &sjv_phongtextureshader;
    sjt_call117->shader._refCount = 1;
    sjf_shader_copy(&sjt_call117->shader, sjt_copy61);
    sjt_call118._refCount = 1;
    sjt_call118.count = 16;
    sjt_call118.data._refCount = 1;
    sjt_call118.data.datasize = 17;
    sjt_call118.data.data = (void*)sjg_string44;
    sjt_call118.data._isglobal = true;
    sjt_call118.data.count = 17;
    sjf_array_char(&sjt_call118.data);
    sjf_string(&sjt_call118);
    sjt_functionParam654 = &sjt_call118;
    sjf_texturefrompng(sjt_functionParam654, &sjt_call117->texture);
    sjt_negate43 = 10.6f;
    result49 = -sjt_negate43;
    sjt_functionParam655 = result49;
    sjt_functionParam656 = 0.0f;
    sjt_functionParam657 = 0.2f;
    sjf_mat4_translate(sjt_functionParam655, sjt_functionParam656, sjt_functionParam657, &sjt_call119);
    sjt_parent232 = &sjt_call119;
    sjt_functionParam659 = 2.0f;
    sjt_functionParam660 = 2.0f;
    sjt_functionParam661 = 2.0f;
    sjf_mat4_scale(sjt_functionParam659, sjt_functionParam660, sjt_functionParam661, &sjt_call120);
    sjt_functionParam658 = &sjt_call120;
    sjf_mat4_multiply(sjt_parent232, sjt_functionParam658, &sjt_call117->model);
    sjt_call117->center._refCount = 1;
    sjt_call117->center.x = 0.0f;
    sjt_call117->center.y = 0.0f;
    sjt_call117->center.z = 0.0f;
    sjf_vec3(&sjt_call117->center);
    sjt_call117->hasalpha = true;
    sjt_call117->id._refCount = 1;
    sjt_call117->id.count = 8;
    sjt_call117->id.data._refCount = 1;
    sjt_call117->id.data.datasize = 9;
    sjt_call117->id.data.data = (void*)sjg_string43;
    sjt_call117->id.data._isglobal = true;
    sjt_call117->id.data.count = 9;
    sjf_array_char(&sjt_call117->id.data);
    sjf_string(&sjt_call117->id);
    sjt_call117->_projection._refCount = 1;
    sjt_call117->_projection.m00 = 0.0f;
    sjt_call117->_projection.m01 = 0.0f;
    sjt_call117->_projection.m02 = 0.0f;
    sjt_call117->_projection.m03 = 0.0f;
    sjt_call117->_projection.m10 = 0.0f;
    sjt_call117->_projection.m11 = 0.0f;
    sjt_call117->_projection.m12 = 0.0f;
    sjt_call117->_projection.m13 = 0.0f;
    sjt_call117->_projection.m20 = 0.0f;
    sjt_call117->_projection.m21 = 0.0f;
    sjt_call117->_projection.m22 = 0.0f;
    sjt_call117->_projection.m23 = 0.0f;
    sjt_call117->_projection.m30 = 0.0f;
    sjt_call117->_projection.m31 = 0.0f;
    sjt_call117->_projection.m32 = 0.0f;
    sjt_call117->_projection.m33 = 0.0f;
    sjf_mat4(&sjt_call117->_projection);
    sjt_call117->_view._refCount = 1;
    sjt_call117->_view.m00 = 0.0f;
    sjt_call117->_view.m01 = 0.0f;
    sjt_call117->_view.m02 = 0.0f;
    sjt_call117->_view.m03 = 0.0f;
    sjt_call117->_view.m10 = 0.0f;
    sjt_call117->_view.m11 = 0.0f;
    sjt_call117->_view.m12 = 0.0f;
    sjt_call117->_view.m13 = 0.0f;
    sjt_call117->_view.m20 = 0.0f;
    sjt_call117->_view.m21 = 0.0f;
    sjt_call117->_view.m22 = 0.0f;
    sjt_call117->_view.m23 = 0.0f;
    sjt_call117->_view.m30 = 0.0f;
    sjt_call117->_view.m31 = 0.0f;
    sjt_call117->_view.m32 = 0.0f;
    sjt_call117->_view.m33 = 0.0f;
    sjf_mat4(&sjt_call117->_view);
    sjt_call117->_world._refCount = 1;
    sjt_call117->_world.m00 = 0.0f;
    sjt_call117->_world.m01 = 0.0f;
    sjt_call117->_world.m02 = 0.0f;
    sjt_call117->_world.m03 = 0.0f;
    sjt_call117->_world.m10 = 0.0f;
    sjt_call117->_world.m11 = 0.0f;
    sjt_call117->_world.m12 = 0.0f;
    sjt_call117->_world.m13 = 0.0f;
    sjt_call117->_world.m20 = 0.0f;
    sjt_call117->_world.m21 = 0.0f;
    sjt_call117->_world.m22 = 0.0f;
    sjt_call117->_world.m23 = 0.0f;
    sjt_call117->_world.m30 = 0.0f;
    sjt_call117->_world.m31 = 0.0f;
    sjt_call117->_world.m32 = 0.0f;
    sjt_call117->_world.m33 = 0.0f;
    sjf_mat4(&sjt_call117->_world);
    sjt_call117->_light._refCount = 1;
    sjt_call117->_light.pos._refCount = 1;
    sjt_call117->_light.pos.x = 1.0f;
    sjt_call117->_light.pos.y = 1.0f;
    sjt_call117->_light.pos.z = 1.0f;
    sjf_vec3(&sjt_call117->_light.pos);
    sjt_call117->_light.diffusecolor._refCount = 1;
    sjt_call117->_light.diffusecolor.r = 0.5f;
    sjt_call117->_light.diffusecolor.g = 0.5f;
    sjt_call117->_light.diffusecolor.b = 0.0f;
    sjt_call117->_light.diffusecolor.a = 1.0f;
    sjf_color(&sjt_call117->_light.diffusecolor);
    sjt_call117->_light.speccolor._refCount = 1;
    sjt_call117->_light.speccolor.r = 1.0f;
    sjt_call117->_light.speccolor.g = 1.0f;
    sjt_call117->_light.speccolor.b = 1.0f;
    sjt_call117->_light.speccolor.a = 1.0f;
    sjf_color(&sjt_call117->_light.speccolor);
    sjf_light(&sjt_call117->_light);
    sjt_call117->_projectedcenter._refCount = 1;
    sjt_call117->_projectedcenter.x = 0.0f;
    sjt_call117->_projectedcenter.y = 0.0f;
    sjt_call117->_projectedcenter.z = 0.0f;
    sjf_vec3(&sjt_call117->_projectedcenter);
    sjf_model_heap(sjt_call117);
    sjt_cast58 = sjt_call117;
    sjf_model_as_sji_model(sjt_cast58, &sjt_functionParam644);
    if (sjt_functionParam644._parent != 0) {
        sjt_functionParam644._parent->_refCount++;
    }

    sjf_array_heap_iface_model_initat(sjt_parent231, sjt_functionParam643, sjt_functionParam644);
    sjt_parent233 = array10;
    sjt_functionParam662 = 7;
    sjt_call121 = (sjs_model*)malloc(sizeof(sjs_model));
    sjt_call121->_refCount = 1;
    sjt_negate44 = 4.3f;
    result50 = -sjt_negate44;
    sjt_functionParam664 = result50;
    sjt_functionParam665 = 4.3f;
    sjt_negate45 = 1.0f;
    result51 = -sjt_negate45;
    sjt_functionParam666 = result51;
    sjt_functionParam667 = 1.0f;
    sjt_functionParam668 = 0.0f;
    sjt_functionParam669 = 0.0f;
    sjt_functionParam670 = 1.0f;
    sjt_functionParam671 = 0.0f;
    sjt_functionParam672 = 1.0f;
    sjf_planevertexbuffer(sjt_functionParam664, sjt_functionParam665, sjt_functionParam666, sjt_functionParam667, sjt_functionParam668, sjt_functionParam669, sjt_functionParam670, sjt_functionParam671, sjt_functionParam672, &sjt_call121->vertexbuffer);
    sjt_copy62 = &sjv_phongtextureshader;
    sjt_call121->shader._refCount = 1;
    sjf_shader_copy(&sjt_call121->shader, sjt_copy62);
    sjt_call122._refCount = 1;
    sjt_call122.count = 16;
    sjt_call122.data._refCount = 1;
    sjt_call122.data.datasize = 17;
    sjt_call122.data.data = (void*)sjg_string46;
    sjt_call122.data._isglobal = true;
    sjt_call122.data.count = 17;
    sjf_array_char(&sjt_call122.data);
    sjf_string(&sjt_call122);
    sjt_functionParam673 = &sjt_call122;
    sjf_texturefrompng(sjt_functionParam673, &sjt_call121->texture);
    sjt_functionParam674 = 6.6f;
    sjt_functionParam675 = 0.0f;
    sjt_functionParam676 = 0.2f;
    sjf_mat4_translate(sjt_functionParam674, sjt_functionParam675, sjt_functionParam676, &sjt_call123);
    sjt_parent234 = &sjt_call123;
    sjt_functionParam678 = 2.0f;
    sjt_functionParam679 = 2.0f;
    sjt_functionParam680 = 2.0f;
    sjf_mat4_scale(sjt_functionParam678, sjt_functionParam679, sjt_functionParam680, &sjt_call124);
    sjt_functionParam677 = &sjt_call124;
    sjf_mat4_multiply(sjt_parent234, sjt_functionParam677, &sjt_call121->model);
    sjt_call121->center._refCount = 1;
    sjt_call121->center.x = 0.0f;
    sjt_call121->center.y = 0.0f;
    sjt_call121->center.z = 0.0f;
    sjf_vec3(&sjt_call121->center);
    sjt_call121->hasalpha = true;
    sjt_call121->id._refCount = 1;
    sjt_call121->id.count = 8;
    sjt_call121->id.data._refCount = 1;
    sjt_call121->id.data.datasize = 9;
    sjt_call121->id.data.data = (void*)sjg_string45;
    sjt_call121->id.data._isglobal = true;
    sjt_call121->id.data.count = 9;
    sjf_array_char(&sjt_call121->id.data);
    sjf_string(&sjt_call121->id);
    sjt_call121->_projection._refCount = 1;
    sjt_call121->_projection.m00 = 0.0f;
    sjt_call121->_projection.m01 = 0.0f;
    sjt_call121->_projection.m02 = 0.0f;
    sjt_call121->_projection.m03 = 0.0f;
    sjt_call121->_projection.m10 = 0.0f;
    sjt_call121->_projection.m11 = 0.0f;
    sjt_call121->_projection.m12 = 0.0f;
    sjt_call121->_projection.m13 = 0.0f;
    sjt_call121->_projection.m20 = 0.0f;
    sjt_call121->_projection.m21 = 0.0f;
    sjt_call121->_projection.m22 = 0.0f;
    sjt_call121->_projection.m23 = 0.0f;
    sjt_call121->_projection.m30 = 0.0f;
    sjt_call121->_projection.m31 = 0.0f;
    sjt_call121->_projection.m32 = 0.0f;
    sjt_call121->_projection.m33 = 0.0f;
    sjf_mat4(&sjt_call121->_projection);
    sjt_call121->_view._refCount = 1;
    sjt_call121->_view.m00 = 0.0f;
    sjt_call121->_view.m01 = 0.0f;
    sjt_call121->_view.m02 = 0.0f;
    sjt_call121->_view.m03 = 0.0f;
    sjt_call121->_view.m10 = 0.0f;
    sjt_call121->_view.m11 = 0.0f;
    sjt_call121->_view.m12 = 0.0f;
    sjt_call121->_view.m13 = 0.0f;
    sjt_call121->_view.m20 = 0.0f;
    sjt_call121->_view.m21 = 0.0f;
    sjt_call121->_view.m22 = 0.0f;
    sjt_call121->_view.m23 = 0.0f;
    sjt_call121->_view.m30 = 0.0f;
    sjt_call121->_view.m31 = 0.0f;
    sjt_call121->_view.m32 = 0.0f;
    sjt_call121->_view.m33 = 0.0f;
    sjf_mat4(&sjt_call121->_view);
    sjt_call121->_world._refCount = 1;
    sjt_call121->_world.m00 = 0.0f;
    sjt_call121->_world.m01 = 0.0f;
    sjt_call121->_world.m02 = 0.0f;
    sjt_call121->_world.m03 = 0.0f;
    sjt_call121->_world.m10 = 0.0f;
    sjt_call121->_world.m11 = 0.0f;
    sjt_call121->_world.m12 = 0.0f;
    sjt_call121->_world.m13 = 0.0f;
    sjt_call121->_world.m20 = 0.0f;
    sjt_call121->_world.m21 = 0.0f;
    sjt_call121->_world.m22 = 0.0f;
    sjt_call121->_world.m23 = 0.0f;
    sjt_call121->_world.m30 = 0.0f;
    sjt_call121->_world.m31 = 0.0f;
    sjt_call121->_world.m32 = 0.0f;
    sjt_call121->_world.m33 = 0.0f;
    sjf_mat4(&sjt_call121->_world);
    sjt_call121->_light._refCount = 1;
    sjt_call121->_light.pos._refCount = 1;
    sjt_call121->_light.pos.x = 1.0f;
    sjt_call121->_light.pos.y = 1.0f;
    sjt_call121->_light.pos.z = 1.0f;
    sjf_vec3(&sjt_call121->_light.pos);
    sjt_call121->_light.diffusecolor._refCount = 1;
    sjt_call121->_light.diffusecolor.r = 0.5f;
    sjt_call121->_light.diffusecolor.g = 0.5f;
    sjt_call121->_light.diffusecolor.b = 0.0f;
    sjt_call121->_light.diffusecolor.a = 1.0f;
    sjf_color(&sjt_call121->_light.diffusecolor);
    sjt_call121->_light.speccolor._refCount = 1;
    sjt_call121->_light.speccolor.r = 1.0f;
    sjt_call121->_light.speccolor.g = 1.0f;
    sjt_call121->_light.speccolor.b = 1.0f;
    sjt_call121->_light.speccolor.a = 1.0f;
    sjf_color(&sjt_call121->_light.speccolor);
    sjf_light(&sjt_call121->_light);
    sjt_call121->_projectedcenter._refCount = 1;
    sjt_call121->_projectedcenter.x = 0.0f;
    sjt_call121->_projectedcenter.y = 0.0f;
    sjt_call121->_projectedcenter.z = 0.0f;
    sjf_vec3(&sjt_call121->_projectedcenter);
    sjf_model_heap(sjt_call121);
    sjt_cast59 = sjt_call121;
    sjf_model_as_sji_model(sjt_cast59, &sjt_functionParam663);
    if (sjt_functionParam663._parent != 0) {
        sjt_functionParam663._parent->_refCount++;
    }

    sjf_array_heap_iface_model_initat(sjt_parent233, sjt_functionParam662, sjt_functionParam663);
    sjt_parent235 = array10;
    sjt_functionParam681 = 8;
    sjt_call125 = (sjs_model*)malloc(sizeof(sjs_model));
    sjt_call125->_refCount = 1;
    sjt_negate46 = 4.3f;
    result52 = -sjt_negate46;
    sjt_functionParam683 = result52;
    sjt_functionParam684 = 4.3f;
    sjt_negate47 = 1.0f;
    result53 = -sjt_negate47;
    sjt_functionParam685 = result53;
    sjt_functionParam686 = 1.0f;
    sjt_functionParam687 = 0.0f;
    sjt_functionParam688 = 0.0f;
    sjt_functionParam689 = 1.0f;
    sjt_functionParam690 = 0.0f;
    sjt_functionParam691 = 1.0f;
    sjf_planevertexbuffer(sjt_functionParam683, sjt_functionParam684, sjt_functionParam685, sjt_functionParam686, sjt_functionParam687, sjt_functionParam688, sjt_functionParam689, sjt_functionParam690, sjt_functionParam691, &sjt_call125->vertexbuffer);
    sjt_copy63 = &sjv_phongtextureshader;
    sjt_call125->shader._refCount = 1;
    sjf_shader_copy(&sjt_call125->shader, sjt_copy63);
    sjt_call126._refCount = 1;
    sjt_call126.count = 16;
    sjt_call126.data._refCount = 1;
    sjt_call126.data.datasize = 17;
    sjt_call126.data.data = (void*)sjg_string48;
    sjt_call126.data._isglobal = true;
    sjt_call126.data.count = 17;
    sjf_array_char(&sjt_call126.data);
    sjf_string(&sjt_call126);
    sjt_functionParam692 = &sjt_call126;
    sjf_texturefrompng(sjt_functionParam692, &sjt_call125->texture);
    sjt_negate48 = 8.6f;
    result54 = -sjt_negate48;
    sjt_functionParam693 = result54;
    sjt_functionParam694 = 0.0f;
    sjt_negate49 = 1.8f;
    result55 = -sjt_negate49;
    sjt_functionParam695 = result55;
    sjf_mat4_translate(sjt_functionParam693, sjt_functionParam694, sjt_functionParam695, &sjt_call127);
    sjt_parent236 = &sjt_call127;
    sjt_functionParam697 = 2.0f;
    sjt_functionParam698 = 2.0f;
    sjt_functionParam699 = 2.0f;
    sjf_mat4_scale(sjt_functionParam697, sjt_functionParam698, sjt_functionParam699, &sjt_call128);
    sjt_functionParam696 = &sjt_call128;
    sjf_mat4_multiply(sjt_parent236, sjt_functionParam696, &sjt_call125->model);
    sjt_call125->center._refCount = 1;
    sjt_call125->center.x = 0.0f;
    sjt_call125->center.y = 0.0f;
    sjt_call125->center.z = 0.0f;
    sjf_vec3(&sjt_call125->center);
    sjt_call125->hasalpha = true;
    sjt_call125->id._refCount = 1;
    sjt_call125->id.count = 9;
    sjt_call125->id.data._refCount = 1;
    sjt_call125->id.data.datasize = 10;
    sjt_call125->id.data.data = (void*)sjg_string47;
    sjt_call125->id.data._isglobal = true;
    sjt_call125->id.data.count = 10;
    sjf_array_char(&sjt_call125->id.data);
    sjf_string(&sjt_call125->id);
    sjt_call125->_projection._refCount = 1;
    sjt_call125->_projection.m00 = 0.0f;
    sjt_call125->_projection.m01 = 0.0f;
    sjt_call125->_projection.m02 = 0.0f;
    sjt_call125->_projection.m03 = 0.0f;
    sjt_call125->_projection.m10 = 0.0f;
    sjt_call125->_projection.m11 = 0.0f;
    sjt_call125->_projection.m12 = 0.0f;
    sjt_call125->_projection.m13 = 0.0f;
    sjt_call125->_projection.m20 = 0.0f;
    sjt_call125->_projection.m21 = 0.0f;
    sjt_call125->_projection.m22 = 0.0f;
    sjt_call125->_projection.m23 = 0.0f;
    sjt_call125->_projection.m30 = 0.0f;
    sjt_call125->_projection.m31 = 0.0f;
    sjt_call125->_projection.m32 = 0.0f;
    sjt_call125->_projection.m33 = 0.0f;
    sjf_mat4(&sjt_call125->_projection);
    sjt_call125->_view._refCount = 1;
    sjt_call125->_view.m00 = 0.0f;
    sjt_call125->_view.m01 = 0.0f;
    sjt_call125->_view.m02 = 0.0f;
    sjt_call125->_view.m03 = 0.0f;
    sjt_call125->_view.m10 = 0.0f;
    sjt_call125->_view.m11 = 0.0f;
    sjt_call125->_view.m12 = 0.0f;
    sjt_call125->_view.m13 = 0.0f;
    sjt_call125->_view.m20 = 0.0f;
    sjt_call125->_view.m21 = 0.0f;
    sjt_call125->_view.m22 = 0.0f;
    sjt_call125->_view.m23 = 0.0f;
    sjt_call125->_view.m30 = 0.0f;
    sjt_call125->_view.m31 = 0.0f;
    sjt_call125->_view.m32 = 0.0f;
    sjt_call125->_view.m33 = 0.0f;
    sjf_mat4(&sjt_call125->_view);
    sjt_call125->_world._refCount = 1;
    sjt_call125->_world.m00 = 0.0f;
    sjt_call125->_world.m01 = 0.0f;
    sjt_call125->_world.m02 = 0.0f;
    sjt_call125->_world.m03 = 0.0f;
    sjt_call125->_world.m10 = 0.0f;
    sjt_call125->_world.m11 = 0.0f;
    sjt_call125->_world.m12 = 0.0f;
    sjt_call125->_world.m13 = 0.0f;
    sjt_call125->_world.m20 = 0.0f;
    sjt_call125->_world.m21 = 0.0f;
    sjt_call125->_world.m22 = 0.0f;
    sjt_call125->_world.m23 = 0.0f;
    sjt_call125->_world.m30 = 0.0f;
    sjt_call125->_world.m31 = 0.0f;
    sjt_call125->_world.m32 = 0.0f;
    sjt_call125->_world.m33 = 0.0f;
    sjf_mat4(&sjt_call125->_world);
    sjt_call125->_light._refCount = 1;
    sjt_call125->_light.pos._refCount = 1;
    sjt_call125->_light.pos.x = 1.0f;
    sjt_call125->_light.pos.y = 1.0f;
    sjt_call125->_light.pos.z = 1.0f;
    sjf_vec3(&sjt_call125->_light.pos);
    sjt_call125->_light.diffusecolor._refCount = 1;
    sjt_call125->_light.diffusecolor.r = 0.5f;
    sjt_call125->_light.diffusecolor.g = 0.5f;
    sjt_call125->_light.diffusecolor.b = 0.0f;
    sjt_call125->_light.diffusecolor.a = 1.0f;
    sjf_color(&sjt_call125->_light.diffusecolor);
    sjt_call125->_light.speccolor._refCount = 1;
    sjt_call125->_light.speccolor.r = 1.0f;
    sjt_call125->_light.speccolor.g = 1.0f;
    sjt_call125->_light.speccolor.b = 1.0f;
    sjt_call125->_light.speccolor.a = 1.0f;
    sjf_color(&sjt_call125->_light.speccolor);
    sjf_light(&sjt_call125->_light);
    sjt_call125->_projectedcenter._refCount = 1;
    sjt_call125->_projectedcenter.x = 0.0f;
    sjt_call125->_projectedcenter.y = 0.0f;
    sjt_call125->_projectedcenter.z = 0.0f;
    sjf_vec3(&sjt_call125->_projectedcenter);
    sjf_model_heap(sjt_call125);
    sjt_cast60 = sjt_call125;
    sjf_model_as_sji_model(sjt_cast60, &sjt_functionParam682);
    if (sjt_functionParam682._parent != 0) {
        sjt_functionParam682._parent->_refCount++;
    }

    sjf_array_heap_iface_model_initat(sjt_parent235, sjt_functionParam681, sjt_functionParam682);
    sjt_parent237 = array10;
    sjt_functionParam700 = 9;
    sjt_call129 = (sjs_model*)malloc(sizeof(sjs_model));
    sjt_call129->_refCount = 1;
    sjt_negate50 = 4.3f;
    result56 = -sjt_negate50;
    sjt_functionParam702 = result56;
    sjt_functionParam703 = 4.3f;
    sjt_negate51 = 1.0f;
    result57 = -sjt_negate51;
    sjt_functionParam704 = result57;
    sjt_functionParam705 = 1.0f;
    sjt_functionParam706 = 0.0f;
    sjt_functionParam707 = 0.0f;
    sjt_functionParam708 = 1.0f;
    sjt_functionParam709 = 0.0f;
    sjt_functionParam710 = 1.0f;
    sjf_planevertexbuffer(sjt_functionParam702, sjt_functionParam703, sjt_functionParam704, sjt_functionParam705, sjt_functionParam706, sjt_functionParam707, sjt_functionParam708, sjt_functionParam709, sjt_functionParam710, &sjt_call129->vertexbuffer);
    sjt_copy64 = &sjv_phongtextureshader;
    sjt_call129->shader._refCount = 1;
    sjf_shader_copy(&sjt_call129->shader, sjt_copy64);
    sjt_call130._refCount = 1;
    sjt_call130.count = 16;
    sjt_call130.data._refCount = 1;
    sjt_call130.data.datasize = 17;
    sjt_call130.data.data = (void*)sjg_string50;
    sjt_call130.data._isglobal = true;
    sjt_call130.data.count = 17;
    sjf_array_char(&sjt_call130.data);
    sjf_string(&sjt_call130);
    sjt_functionParam711 = &sjt_call130;
    sjf_texturefrompng(sjt_functionParam711, &sjt_call129->texture);
    sjt_functionParam712 = 8.6f;
    sjt_functionParam713 = 0.0f;
    sjt_negate52 = 1.8f;
    result58 = -sjt_negate52;
    sjt_functionParam714 = result58;
    sjf_mat4_translate(sjt_functionParam712, sjt_functionParam713, sjt_functionParam714, &sjt_call131);
    sjt_parent238 = &sjt_call131;
    sjt_functionParam716 = 2.0f;
    sjt_functionParam717 = 2.0f;
    sjt_functionParam718 = 2.0f;
    sjf_mat4_scale(sjt_functionParam716, sjt_functionParam717, sjt_functionParam718, &sjt_call132);
    sjt_functionParam715 = &sjt_call132;
    sjf_mat4_multiply(sjt_parent238, sjt_functionParam715, &sjt_call129->model);
    sjt_call129->center._refCount = 1;
    sjt_call129->center.x = 0.0f;
    sjt_call129->center.y = 0.0f;
    sjt_call129->center.z = 0.0f;
    sjf_vec3(&sjt_call129->center);
    sjt_call129->hasalpha = true;
    sjt_call129->id._refCount = 1;
    sjt_call129->id.count = 9;
    sjt_call129->id.data._refCount = 1;
    sjt_call129->id.data.datasize = 10;
    sjt_call129->id.data.data = (void*)sjg_string49;
    sjt_call129->id.data._isglobal = true;
    sjt_call129->id.data.count = 10;
    sjf_array_char(&sjt_call129->id.data);
    sjf_string(&sjt_call129->id);
    sjt_call129->_projection._refCount = 1;
    sjt_call129->_projection.m00 = 0.0f;
    sjt_call129->_projection.m01 = 0.0f;
    sjt_call129->_projection.m02 = 0.0f;
    sjt_call129->_projection.m03 = 0.0f;
    sjt_call129->_projection.m10 = 0.0f;
    sjt_call129->_projection.m11 = 0.0f;
    sjt_call129->_projection.m12 = 0.0f;
    sjt_call129->_projection.m13 = 0.0f;
    sjt_call129->_projection.m20 = 0.0f;
    sjt_call129->_projection.m21 = 0.0f;
    sjt_call129->_projection.m22 = 0.0f;
    sjt_call129->_projection.m23 = 0.0f;
    sjt_call129->_projection.m30 = 0.0f;
    sjt_call129->_projection.m31 = 0.0f;
    sjt_call129->_projection.m32 = 0.0f;
    sjt_call129->_projection.m33 = 0.0f;
    sjf_mat4(&sjt_call129->_projection);
    sjt_call129->_view._refCount = 1;
    sjt_call129->_view.m00 = 0.0f;
    sjt_call129->_view.m01 = 0.0f;
    sjt_call129->_view.m02 = 0.0f;
    sjt_call129->_view.m03 = 0.0f;
    sjt_call129->_view.m10 = 0.0f;
    sjt_call129->_view.m11 = 0.0f;
    sjt_call129->_view.m12 = 0.0f;
    sjt_call129->_view.m13 = 0.0f;
    sjt_call129->_view.m20 = 0.0f;
    sjt_call129->_view.m21 = 0.0f;
    sjt_call129->_view.m22 = 0.0f;
    sjt_call129->_view.m23 = 0.0f;
    sjt_call129->_view.m30 = 0.0f;
    sjt_call129->_view.m31 = 0.0f;
    sjt_call129->_view.m32 = 0.0f;
    sjt_call129->_view.m33 = 0.0f;
    sjf_mat4(&sjt_call129->_view);
    sjt_call129->_world._refCount = 1;
    sjt_call129->_world.m00 = 0.0f;
    sjt_call129->_world.m01 = 0.0f;
    sjt_call129->_world.m02 = 0.0f;
    sjt_call129->_world.m03 = 0.0f;
    sjt_call129->_world.m10 = 0.0f;
    sjt_call129->_world.m11 = 0.0f;
    sjt_call129->_world.m12 = 0.0f;
    sjt_call129->_world.m13 = 0.0f;
    sjt_call129->_world.m20 = 0.0f;
    sjt_call129->_world.m21 = 0.0f;
    sjt_call129->_world.m22 = 0.0f;
    sjt_call129->_world.m23 = 0.0f;
    sjt_call129->_world.m30 = 0.0f;
    sjt_call129->_world.m31 = 0.0f;
    sjt_call129->_world.m32 = 0.0f;
    sjt_call129->_world.m33 = 0.0f;
    sjf_mat4(&sjt_call129->_world);
    sjt_call129->_light._refCount = 1;
    sjt_call129->_light.pos._refCount = 1;
    sjt_call129->_light.pos.x = 1.0f;
    sjt_call129->_light.pos.y = 1.0f;
    sjt_call129->_light.pos.z = 1.0f;
    sjf_vec3(&sjt_call129->_light.pos);
    sjt_call129->_light.diffusecolor._refCount = 1;
    sjt_call129->_light.diffusecolor.r = 0.5f;
    sjt_call129->_light.diffusecolor.g = 0.5f;
    sjt_call129->_light.diffusecolor.b = 0.0f;
    sjt_call129->_light.diffusecolor.a = 1.0f;
    sjf_color(&sjt_call129->_light.diffusecolor);
    sjt_call129->_light.speccolor._refCount = 1;
    sjt_call129->_light.speccolor.r = 1.0f;
    sjt_call129->_light.speccolor.g = 1.0f;
    sjt_call129->_light.speccolor.b = 1.0f;
    sjt_call129->_light.speccolor.a = 1.0f;
    sjf_color(&sjt_call129->_light.speccolor);
    sjf_light(&sjt_call129->_light);
    sjt_call129->_projectedcenter._refCount = 1;
    sjt_call129->_projectedcenter.x = 0.0f;
    sjt_call129->_projectedcenter.y = 0.0f;
    sjt_call129->_projectedcenter.z = 0.0f;
    sjf_vec3(&sjt_call129->_projectedcenter);
    sjf_model_heap(sjt_call129);
    sjt_cast61 = sjt_call129;
    sjf_model_as_sji_model(sjt_cast61, &sjt_functionParam701);
    if (sjt_functionParam701._parent != 0) {
        sjt_functionParam701._parent->_refCount++;
    }

    sjf_array_heap_iface_model_initat(sjt_parent237, sjt_functionParam700, sjt_functionParam701);
    sjf_panel3d_heap(sjt_call92);
    sjt_cast51 = sjt_call92;
    sjf_panel3d_as_sji_model(sjt_cast51, &sjt_functionParam521);
    if (sjt_functionParam521._parent != 0) {
        sjt_functionParam521._parent->_refCount++;
    }

    sjf_array_heap_iface_model_initat(sjt_parent211, sjt_functionParam520, sjt_functionParam521);
    sjt_call2->lookatmin._refCount = 1;
    sjt_negate53 = 16.0f;
    result59 = -sjt_negate53;
    sjt_call2->lookatmin.x = result59;
    sjt_negate54 = 1.0f;
    result60 = -sjt_negate54;
    sjt_call2->lookatmin.y = result60;
    sjt_call2->lookatmin.z = 0.0f;
    sjf_vec3(&sjt_call2->lookatmin);
    sjt_call2->lookatmax._refCount = 1;
    sjt_call2->lookatmax.x = 16.0f;
    sjt_call2->lookatmax.y = 1.0f;
    sjt_call2->lookatmax.z = 6.0f;
    sjf_vec3(&sjt_call2->lookatmax);
    sjt_call2->fieldofview = 90.0f;
    sjt_call2->znear = 1.0f;
    sjt_call2->zfar = 50.0f;
    sjt_call2->light._refCount = 1;
    sjt_call2->light.pos._refCount = 1;
    sjt_call2->light.pos.x = 1.0f;
    sjt_call2->light.pos.y = 1.0f;
    sjt_call2->light.pos.z = 1.0f;
    sjf_vec3(&sjt_call2->light.pos);
    sjt_call2->light.diffusecolor._refCount = 1;
    sjt_call2->light.diffusecolor.r = 0.5f;
    sjt_call2->light.diffusecolor.g = 0.5f;
    sjt_call2->light.diffusecolor.b = 0.0f;
    sjt_call2->light.diffusecolor.a = 1.0f;
    sjf_color(&sjt_call2->light.diffusecolor);
    sjt_call2->light.speccolor._refCount = 1;
    sjt_call2->light.speccolor.r = 1.0f;
    sjt_call2->light.speccolor.g = 1.0f;
    sjt_call2->light.speccolor.b = 1.0f;
    sjt_call2->light.speccolor.a = 1.0f;
    sjf_color(&sjt_call2->light.speccolor);
    sjf_light(&sjt_call2->light);
    sjt_call2->projection._refCount = 1;
    sjt_call2->projection.m00 = 0.0f;
    sjt_call2->projection.m01 = 0.0f;
    sjt_call2->projection.m02 = 0.0f;
    sjt_call2->projection.m03 = 0.0f;
    sjt_call2->projection.m10 = 0.0f;
    sjt_call2->projection.m11 = 0.0f;
    sjt_call2->projection.m12 = 0.0f;
    sjt_call2->projection.m13 = 0.0f;
    sjt_call2->projection.m20 = 0.0f;
    sjt_call2->projection.m21 = 0.0f;
    sjt_call2->projection.m22 = 0.0f;
    sjt_call2->projection.m23 = 0.0f;
    sjt_call2->projection.m30 = 0.0f;
    sjt_call2->projection.m31 = 0.0f;
    sjt_call2->projection.m32 = 0.0f;
    sjt_call2->projection.m33 = 0.0f;
    sjf_mat4(&sjt_call2->projection);
    sjt_call133._refCount = 1;
    sjt_call133.x = 0.0f;
    sjt_call133.y = 0.0f;
    sjt_negate55 = 5.0f;
    result61 = -sjt_negate55;
    sjt_call133.z = result61;
    sjf_vec3(&sjt_call133);
    sjt_functionParam719 = &sjt_call133;
    sjt_call134._refCount = 1;
    sjt_call134.x = 0.0f;
    sjt_call134.y = 0.0f;
    sjt_call134.z = 0.0f;
    sjf_vec3(&sjt_call134);
    sjt_functionParam720 = &sjt_call134;
    sjt_call135._refCount = 1;
    sjt_call135.x = 0.0f;
    sjt_call135.y = 1.0f;
    sjt_call135.z = 0.0f;
    sjf_vec3(&sjt_call135);
    sjt_functionParam721 = &sjt_call135;
    sjf_mat4_lookatlh(sjt_functionParam719, sjt_functionParam720, sjt_functionParam721, &sjt_call2->view);
    sjf_mat4_identity(&sjt_call2->world);
    sjt_call2->_rect._refCount = 1;
    sjt_call2->_rect.x = 0;
    sjt_call2->_rect.y = 0;
    sjt_call2->_rect.w = 0;
    sjt_call2->_rect.h = 0;
    sjf_rect(&sjt_call2->_rect);
    sjt_call2->_isdragging = false;
    sjt_call2->_startdrag._refCount = 1;
    sjt_call2->_startdrag.x = 0;
    sjt_call2->_startdrag.y = 0;
    sjf_point(&sjt_call2->_startdrag);
    sjt_call2->_lookat._refCount = 1;
    sjt_call2->_lookat.x = 0.0f;
    sjt_call2->_lookat.y = 0.0f;
    sjt_call2->_lookat.z = 0.0f;
    sjf_vec3(&sjt_call2->_lookat);
    sjt_call2->_lookatdrag._refCount = 1;
    sjt_call2->_lookatdrag.x = 0.0f;
    sjt_call2->_lookatdrag.y = 0.0f;
    sjt_call2->_lookatdrag.z = 0.0f;
    sjf_vec3(&sjt_call2->_lookatdrag);
    sjf_nauscene3delement_heap(sjt_call2);
    sjt_cast2 = sjt_call2;
    sjf_nauscene3delement_as_sji_element(sjt_cast2, &sjt_functionParam6);
    if (sjt_functionParam6._parent != 0) {
        sjt_functionParam6._parent->_refCount++;
    }

    sjf_array_heap_iface_element_initat(sjt_parent8, sjt_functionParam5, sjt_functionParam6);
    sjt_parent239 = array11;
    sjt_functionParam722 = 1;
    sjt_call136 = (sjs_crosshairselement*)malloc(sizeof(sjs_crosshairselement));
    sjt_call136->_refCount = 1;
    sjt_parent240 = &sjv_colors;
    sjf_anon4_red(sjt_parent240, &sjt_call136->color);
    sjt_call136->_rect._refCount = 1;
    sjt_call136->_rect.x = 0;
    sjt_call136->_rect.y = 0;
    sjt_call136->_rect.w = 0;
    sjt_call136->_rect.h = 0;
    sjf_rect(&sjt_call136->_rect);
    sjt_call136->_topdownrenderer._refCount = -1;
    sjt_call136->_leftrightrenderer._refCount = -1;
    sjt_call136->_point._refCount = 1;
    sjt_call136->_point.x = 0;
    sjt_call136->_point.y = 0;
    sjf_point(&sjt_call136->_point);
    sjf_crosshairselement_heap(sjt_call136);
    sjt_cast62 = sjt_call136;
    sjf_crosshairselement_as_sji_element(sjt_cast62, &sjt_functionParam723);
    if (sjt_functionParam723._parent != 0) {
        sjt_functionParam723._parent->_refCount++;
    }

    sjf_array_heap_iface_element_initat(sjt_parent239, sjt_functionParam722, sjt_functionParam723);
    sjt_call1._rect._refCount = 1;
    sjt_call1._rect.x = 0;
    sjt_call1._rect.y = 0;
    sjt_call1._rect.w = 0;
    sjt_call1._rect.h = 0;
    sjf_rect(&sjt_call1._rect);
    sjf_fillelement(&sjt_call1);
    sjt_cast1 = &sjt_call1;
    sjf_fillelement_as_sji_element(sjt_cast1, &sjv_root);
    sjf_runloop();
    main_destroy();
    #ifdef _DEBUG
    printf("\npress return to end\n");
    getchar();
    #endif
    return 0;
}

void main_destroy() {

    sjt_call101->_refCount--;
    if (sjt_call101->_refCount <= 0) {
        weakptr_release(sjt_call101);
        sjf_model_destroy(sjt_call101);
    }
    sjt_call105->_refCount--;
    if (sjt_call105->_refCount <= 0) {
        weakptr_release(sjt_call105);
        sjf_model_destroy(sjt_call105);
    }
    sjt_call109->_refCount--;
    if (sjt_call109->_refCount <= 0) {
        weakptr_release(sjt_call109);
        sjf_model_destroy(sjt_call109);
    }
    sjt_call113->_refCount--;
    if (sjt_call113->_refCount <= 0) {
        weakptr_release(sjt_call113);
        sjf_model_destroy(sjt_call113);
    }
    sjt_call117->_refCount--;
    if (sjt_call117->_refCount <= 0) {
        weakptr_release(sjt_call117);
        sjf_model_destroy(sjt_call117);
    }
    sjt_call121->_refCount--;
    if (sjt_call121->_refCount <= 0) {
        weakptr_release(sjt_call121);
        sjf_model_destroy(sjt_call121);
    }
    sjt_call125->_refCount--;
    if (sjt_call125->_refCount <= 0) {
        weakptr_release(sjt_call125);
        sjf_model_destroy(sjt_call125);
    }
    sjt_call129->_refCount--;
    if (sjt_call129->_refCount <= 0) {
        weakptr_release(sjt_call129);
        sjf_model_destroy(sjt_call129);
    }
    sjt_call13->_refCount--;
    if (sjt_call13->_refCount <= 0) {
        weakptr_release(sjt_call13);
        sjf_model_destroy(sjt_call13);
    }
    sjt_call136->_refCount--;
    if (sjt_call136->_refCount <= 0) {
        weakptr_release(sjt_call136);
        sjf_crosshairselement_destroy(sjt_call136);
    }
    sjt_call2->_refCount--;
    if (sjt_call2->_refCount <= 0) {
        weakptr_release(sjt_call2);
        sjf_nauscene3delement_destroy(sjt_call2);
    }
    sjt_call37->_refCount--;
    if (sjt_call37->_refCount <= 0) {
        weakptr_release(sjt_call37);
        sjf_leafpanel_destroy(sjt_call37);
    }
    sjt_call59->_refCount--;
    if (sjt_call59->_refCount <= 0) {
        weakptr_release(sjt_call59);
        sjf_peoplepanel_destroy(sjt_call59);
    }
    sjt_call61->_refCount--;
    if (sjt_call61->_refCount <= 0) {
        weakptr_release(sjt_call61);
        sjf_scene2dmodel_destroy(sjt_call61);
    }
    sjt_call81->_refCount--;
    if (sjt_call81->_refCount <= 0) {
        weakptr_release(sjt_call81);
        sjf_boxelement_destroy(sjt_call81);
    }
    sjt_call82->_refCount--;
    if (sjt_call82->_refCount <= 0) {
        weakptr_release(sjt_call82);
        sjf_imageelement_destroy(sjt_call82);
    }
    sjt_call86->_refCount--;
    if (sjt_call86->_refCount <= 0) {
        weakptr_release(sjt_call86);
        sjf_crosshairselement_destroy(sjt_call86);
    }
    sjt_call87->_refCount--;
    if (sjt_call87->_refCount <= 0) {
        weakptr_release(sjt_call87);
        sjf_scene2dmodel_destroy(sjt_call87);
    }
    sjt_call88->_refCount--;
    if (sjt_call88->_refCount <= 0) {
        weakptr_release(sjt_call88);
        sjf_boxelement_destroy(sjt_call88);
    }
    sjt_call89->_refCount--;
    if (sjt_call89->_refCount <= 0) {
        weakptr_release(sjt_call89);
        sjf_imageelement_destroy(sjt_call89);
    }
    sjt_call91->_refCount--;
    if (sjt_call91->_refCount <= 0) {
        weakptr_release(sjt_call91);
        sjf_crosshairselement_destroy(sjt_call91);
    }
    sjt_call92->_refCount--;
    if (sjt_call92->_refCount <= 0) {
        weakptr_release(sjt_call92);
        sjf_panel3d_destroy(sjt_call92);
    }
    sjt_call93->_refCount--;
    if (sjt_call93->_refCount <= 0) {
        weakptr_release(sjt_call93);
        sjf_model_destroy(sjt_call93);
    }
    sjt_call97->_refCount--;
    if (sjt_call97->_refCount <= 0) {
        weakptr_release(sjt_call97);
        sjf_model_destroy(sjt_call97);
    }
    if (sjt_functionParam105._parent != 0) {
        sjt_functionParam105._parent->_refCount--;
        if (sjt_functionParam105._parent->_refCount <= 0) {
            sjt_functionParam105._vtbl->destroy(sjt_functionParam105._parent);
        }
    }
    if (sjt_functionParam214._parent != 0) {
        sjt_functionParam214._parent->_refCount--;
        if (sjt_functionParam214._parent->_refCount <= 0) {
            sjt_functionParam214._vtbl->destroy(sjt_functionParam214._parent);
        }
    }
    if (sjt_functionParam283._parent != 0) {
        sjt_functionParam283._parent->_refCount--;
        if (sjt_functionParam283._parent->_refCount <= 0) {
            sjt_functionParam283._vtbl->destroy(sjt_functionParam283._parent);
        }
    }
    if (sjt_functionParam310._parent != 0) {
        sjt_functionParam310._parent->_refCount--;
        if (sjt_functionParam310._parent->_refCount <= 0) {
            sjt_functionParam310._vtbl->destroy(sjt_functionParam310._parent);
        }
    }
    if (sjt_functionParam485._parent != 0) {
        sjt_functionParam485._parent->_refCount--;
        if (sjt_functionParam485._parent->_refCount <= 0) {
            sjt_functionParam485._vtbl->destroy(sjt_functionParam485._parent);
        }
    }
    if (sjt_functionParam491._parent != 0) {
        sjt_functionParam491._parent->_refCount--;
        if (sjt_functionParam491._parent->_refCount <= 0) {
            sjt_functionParam491._vtbl->destroy(sjt_functionParam491._parent);
        }
    }
    if (sjt_functionParam497._parent != 0) {
        sjt_functionParam497._parent->_refCount--;
        if (sjt_functionParam497._parent->_refCount <= 0) {
            sjt_functionParam497._vtbl->destroy(sjt_functionParam497._parent);
        }
    }
    if (sjt_functionParam503._parent != 0) {
        sjt_functionParam503._parent->_refCount--;
        if (sjt_functionParam503._parent->_refCount <= 0) {
            sjt_functionParam503._vtbl->destroy(sjt_functionParam503._parent);
        }
    }
    if (sjt_functionParam514._parent != 0) {
        sjt_functionParam514._parent->_refCount--;
        if (sjt_functionParam514._parent->_refCount <= 0) {
            sjt_functionParam514._vtbl->destroy(sjt_functionParam514._parent);
        }
    }
    if (sjt_functionParam516._parent != 0) {
        sjt_functionParam516._parent->_refCount--;
        if (sjt_functionParam516._parent->_refCount <= 0) {
            sjt_functionParam516._vtbl->destroy(sjt_functionParam516._parent);
        }
    }
    if (sjt_functionParam519._parent != 0) {
        sjt_functionParam519._parent->_refCount--;
        if (sjt_functionParam519._parent->_refCount <= 0) {
            sjt_functionParam519._vtbl->destroy(sjt_functionParam519._parent);
        }
    }
    if (sjt_functionParam521._parent != 0) {
        sjt_functionParam521._parent->_refCount--;
        if (sjt_functionParam521._parent->_refCount <= 0) {
            sjt_functionParam521._vtbl->destroy(sjt_functionParam521._parent);
        }
    }
    if (sjt_functionParam530._parent != 0) {
        sjt_functionParam530._parent->_refCount--;
        if (sjt_functionParam530._parent->_refCount <= 0) {
            sjt_functionParam530._vtbl->destroy(sjt_functionParam530._parent);
        }
    }
    if (sjt_functionParam549._parent != 0) {
        sjt_functionParam549._parent->_refCount--;
        if (sjt_functionParam549._parent->_refCount <= 0) {
            sjt_functionParam549._vtbl->destroy(sjt_functionParam549._parent);
        }
    }
    if (sjt_functionParam568._parent != 0) {
        sjt_functionParam568._parent->_refCount--;
        if (sjt_functionParam568._parent->_refCount <= 0) {
            sjt_functionParam568._vtbl->destroy(sjt_functionParam568._parent);
        }
    }
    if (sjt_functionParam587._parent != 0) {
        sjt_functionParam587._parent->_refCount--;
        if (sjt_functionParam587._parent->_refCount <= 0) {
            sjt_functionParam587._vtbl->destroy(sjt_functionParam587._parent);
        }
    }
    if (sjt_functionParam6._parent != 0) {
        sjt_functionParam6._parent->_refCount--;
        if (sjt_functionParam6._parent->_refCount <= 0) {
            sjt_functionParam6._vtbl->destroy(sjt_functionParam6._parent);
        }
    }
    if (sjt_functionParam606._parent != 0) {
        sjt_functionParam606._parent->_refCount--;
        if (sjt_functionParam606._parent->_refCount <= 0) {
            sjt_functionParam606._vtbl->destroy(sjt_functionParam606._parent);
        }
    }
    if (sjt_functionParam625._parent != 0) {
        sjt_functionParam625._parent->_refCount--;
        if (sjt_functionParam625._parent->_refCount <= 0) {
            sjt_functionParam625._vtbl->destroy(sjt_functionParam625._parent);
        }
    }
    if (sjt_functionParam644._parent != 0) {
        sjt_functionParam644._parent->_refCount--;
        if (sjt_functionParam644._parent->_refCount <= 0) {
            sjt_functionParam644._vtbl->destroy(sjt_functionParam644._parent);
        }
    }
    if (sjt_functionParam663._parent != 0) {
        sjt_functionParam663._parent->_refCount--;
        if (sjt_functionParam663._parent->_refCount <= 0) {
            sjt_functionParam663._vtbl->destroy(sjt_functionParam663._parent);
        }
    }
    if (sjt_functionParam682._parent != 0) {
        sjt_functionParam682._parent->_refCount--;
        if (sjt_functionParam682._parent->_refCount <= 0) {
            sjt_functionParam682._vtbl->destroy(sjt_functionParam682._parent);
        }
    }
    if (sjt_functionParam701._parent != 0) {
        sjt_functionParam701._parent->_refCount--;
        if (sjt_functionParam701._parent->_refCount <= 0) {
            sjt_functionParam701._vtbl->destroy(sjt_functionParam701._parent);
        }
    }
    if (sjt_functionParam723._parent != 0) {
        sjt_functionParam723._parent->_refCount--;
        if (sjt_functionParam723._parent->_refCount <= 0) {
            sjt_functionParam723._vtbl->destroy(sjt_functionParam723._parent);
        }
    }
    if (sjv_mouse_captureelement._parent != 0) {
        sjv_mouse_captureelement._parent->_refCount--;
        if (sjv_mouse_captureelement._parent->_refCount <= 0) {
            sjv_mouse_captureelement._vtbl->destroy(sjv_mouse_captureelement._parent);
        }
    }
    if (sjt_call1._refCount == 1) { sjf_fillelement_destroy(&sjt_call1); }
    if (sjt_call100._refCount == 1) { sjf_mat4_destroy(&sjt_call100); }
    if (sjt_call102._refCount == 1) { sjf_string_destroy(&sjt_call102); }
    if (sjt_call103._refCount == 1) { sjf_mat4_destroy(&sjt_call103); }
    if (sjt_call104._refCount == 1) { sjf_mat4_destroy(&sjt_call104); }
    if (sjt_call106._refCount == 1) { sjf_string_destroy(&sjt_call106); }
    if (sjt_call107._refCount == 1) { sjf_mat4_destroy(&sjt_call107); }
    if (sjt_call108._refCount == 1) { sjf_mat4_destroy(&sjt_call108); }
    if (sjt_call110._refCount == 1) { sjf_string_destroy(&sjt_call110); }
    if (sjt_call111._refCount == 1) { sjf_mat4_destroy(&sjt_call111); }
    if (sjt_call112._refCount == 1) { sjf_mat4_destroy(&sjt_call112); }
    if (sjt_call114._refCount == 1) { sjf_string_destroy(&sjt_call114); }
    if (sjt_call115._refCount == 1) { sjf_mat4_destroy(&sjt_call115); }
    if (sjt_call116._refCount == 1) { sjf_mat4_destroy(&sjt_call116); }
    if (sjt_call118._refCount == 1) { sjf_string_destroy(&sjt_call118); }
    if (sjt_call119._refCount == 1) { sjf_mat4_destroy(&sjt_call119); }
    if (sjt_call120._refCount == 1) { sjf_mat4_destroy(&sjt_call120); }
    if (sjt_call122._refCount == 1) { sjf_string_destroy(&sjt_call122); }
    if (sjt_call123._refCount == 1) { sjf_mat4_destroy(&sjt_call123); }
    if (sjt_call124._refCount == 1) { sjf_mat4_destroy(&sjt_call124); }
    if (sjt_call126._refCount == 1) { sjf_string_destroy(&sjt_call126); }
    if (sjt_call127._refCount == 1) { sjf_mat4_destroy(&sjt_call127); }
    if (sjt_call128._refCount == 1) { sjf_mat4_destroy(&sjt_call128); }
    if (sjt_call130._refCount == 1) { sjf_string_destroy(&sjt_call130); }
    if (sjt_call131._refCount == 1) { sjf_mat4_destroy(&sjt_call131); }
    if (sjt_call132._refCount == 1) { sjf_mat4_destroy(&sjt_call132); }
    if (sjt_call133._refCount == 1) { sjf_vec3_destroy(&sjt_call133); }
    if (sjt_call134._refCount == 1) { sjf_vec3_destroy(&sjt_call134); }
    if (sjt_call135._refCount == 1) { sjf_vec3_destroy(&sjt_call135); }
    if (sjt_call34._refCount == 1) { sjf_string_destroy(&sjt_call34); }
    if (sjt_call35._refCount == 1) { sjf_mat4_destroy(&sjt_call35); }
    if (sjt_call36._refCount == 1) { sjf_mat4_destroy(&sjt_call36); }
    if (sjt_call43._refCount == 1) { sjf_texture_destroy(&sjt_call43); }
    if (sjt_call44._refCount == 1) { sjf_string_destroy(&sjt_call44); }
    if (sjt_call45._refCount == 1) { sjf_texture_destroy(&sjt_call45); }
    if (sjt_call46._refCount == 1) { sjf_string_destroy(&sjt_call46); }
    if (sjt_call47._refCount == 1) { sjf_texture_destroy(&sjt_call47); }
    if (sjt_call48._refCount == 1) { sjf_string_destroy(&sjt_call48); }
    if (sjt_call49._refCount == 1) { sjf_texture_destroy(&sjt_call49); }
    if (sjt_call50._refCount == 1) { sjf_string_destroy(&sjt_call50); }
    if (sjt_call51._refCount == 1) { sjf_texture_destroy(&sjt_call51); }
    if (sjt_call52._refCount == 1) { sjf_string_destroy(&sjt_call52); }
    if (sjt_call53._refCount == 1) { sjf_texture_destroy(&sjt_call53); }
    if (sjt_call54._refCount == 1) { sjf_string_destroy(&sjt_call54); }
    if (sjt_call55._refCount == 1) { sjf_texture_destroy(&sjt_call55); }
    if (sjt_call56._refCount == 1) { sjf_string_destroy(&sjt_call56); }
    if (sjt_call57._refCount == 1) { sjf_texture_destroy(&sjt_call57); }
    if (sjt_call58._refCount == 1) { sjf_string_destroy(&sjt_call58); }
    if (sjt_call85._refCount == 1) { sjf_string_destroy(&sjt_call85); }
    if (sjt_call90._refCount == 1) { sjf_string_destroy(&sjt_call90); }
    if (sjt_call94._refCount == 1) { sjf_string_destroy(&sjt_call94); }
    if (sjt_call95._refCount == 1) { sjf_mat4_destroy(&sjt_call95); }
    if (sjt_call96._refCount == 1) { sjf_mat4_destroy(&sjt_call96); }
    if (sjt_call98._refCount == 1) { sjf_string_destroy(&sjt_call98); }
    if (sjt_call99._refCount == 1) { sjf_mat4_destroy(&sjt_call99); }
    if (sjv_animator._refCount == 1) { sjf_anon1_destroy(&sjv_animator); }
    if (sjv_blurhorizontalshader._refCount == 1) { sjf_shader_destroy(&sjv_blurhorizontalshader); }
    if (sjv_blurverticalshader._refCount == 1) { sjf_shader_destroy(&sjv_blurverticalshader); }
    if (sjv_borderposition._refCount == 1) { sjf_anon2_destroy(&sjv_borderposition); }
    if (sjv_boxshader._refCount == 1) { sjf_shader_destroy(&sjv_boxshader); }
    if (sjv_buttonstate._refCount == 1) { sjf_anon3_destroy(&sjv_buttonstate); }
    if (sjv_colors._refCount == 1) { sjf_anon4_destroy(&sjv_colors); }
    if (sjv_elementsbyid._refCount == 1) { sjf_hash_string_weak_iface_element_destroy(&sjv_elementsbyid); }
    if (sjv_imageshader._refCount == 1) { sjf_shader_destroy(&sjv_imageshader); }
    if (sjv_modelsbyid._refCount == 1) { sjf_hash_string_weak_iface_model_destroy(&sjv_modelsbyid); }
    if (sjv_phongcolorshader._refCount == 1) { sjf_shader_destroy(&sjv_phongcolorshader); }
    if (sjv_phongtextureshader._refCount == 1) { sjf_shader_destroy(&sjv_phongtextureshader); }
    if (sjv_rootscene._refCount == 1) { sjf_scene2d_destroy(&sjv_rootscene); }
    if (sjv_rootwindowrenderer._refCount == 1) { sjf_windowrenderer_destroy(&sjv_rootwindowrenderer); }
    if (sjv_style._refCount == 1) { sjf_anon5_destroy(&sjv_style); }
    if (sjv_textshader._refCount == 1) { sjf_shader_destroy(&sjv_textshader); }
    if (sjv_vertex_location_texture_normal_format._refCount == 1) { sjf_string_destroy(&sjv_vertex_location_texture_normal_format); }
}
