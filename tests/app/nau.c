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
    bool isempty;
    int32_t value;
};
const int32_option int32_empty = { true };

typedef struct td_uint32_option uint32_option;
struct td_uint32_option {
    bool isempty;
    uint32_t value;
};
const uint32_option uint32_empty = { true };

typedef struct td_int64_option int64_option;
struct td_int64_option {
    bool isempty;
    int64_t value;
};
const int64_option int64_empty = { true };

typedef struct td_uint64_option uint64_option;
struct td_uint64_option {
    bool isempty;
    uint64_t value;
};
const uint64_option uint64_empty = { true };

typedef struct td_void_option void_option;
struct td_void_option {
    bool isempty;
    void* value;
};
const void_option void_empty = { true };

typedef struct td_char_option char_option;
struct td_char_option {
    bool isempty;
    char value;
};
const char_option char_empty = { true };

typedef struct td_float_option float_option;
struct td_float_option {
    bool isempty;
    float value;
};
const float_option float_empty = { true };

typedef struct td_double_option double_option;
struct td_double_option {
    bool isempty;
    double value;
};
const double_option double_empty = { true };

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
bool isEqual;                                           \
__hash_equal(h->keys[i], key, &isEqual);                \
while (!__ac_isempty(h->flags, i) && (__ac_isdel(h->flags, i) || !isEqual)) { \
if (__ac_isdel(h->flags, i)) site = i;              \
if (i + inc >= h->n_buckets) i = i + inc - h->n_buckets; \
else i += inc;                                      \
if (i == last) { x = site; break; }                 \
__hash_equal(h->keys[i], key, &isEqual);            \
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
bool isEqual;                                           \
__hash_equal(&h->keys[i], &key, &isEqual);                \
while (!__ac_isempty(h->flags, i) && (__ac_isdel(h->flags, i) || !isEqual)) { \
if (__ac_isdel(h->flags, i)) site = i;              \
if (i + inc >= h->n_buckets) i = i + inc - h->n_buckets; \
else i += inc;                                      \
if (i == last) { x = site; break; }                 \
__hash_equal(&h->keys[i], &key, &isEqual);            \
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
#define sjs_windowrenderer_typeId 2
#define sjs_size_typeId 3
#define sjs_mat4_typeId 4
#define sjs_scene2d_typeId 5
#define sjs_array_heap_animation_typeId 6
#define sjs_list_heap_animation_typeId 7
#define sjs_anon1_typeId 8
#define sji_animation_typeId 9
#define sjs_anon2_typeId 10
#define sjs_anon3_typeId 11
#define sjs_anon4_typeId 12
#define sjs_array_char_typeId 13
#define sjs_string_typeId 14
#define sjs_shader_typeId 15
#define sjs_anon5_typeId 16
#define sjs_array_heap_element_typeId 17
#define sjs_rect_typeId 18
#define sjs_fillelement_typeId 19
#define sjs_point_typeId 20
#define sjs_mouseevent_typeId 21
#define sji_element_typeId 22
#define sjs_array_heap_model_typeId 23
#define sjs_vec3_typeId 24
#define sjs_color_typeId 25
#define sjs_light_typeId 26
#define sjs_nauscene3delement_typeId 27
#define sji_model_typeId 28
#define sjs_list_heap_model_typeId 29
#define cb_heap_model_heap_model_i32_typeId 30
#define cb_heap_model_heap_model_i32_heap_typeId 31
#define sjs_array_i32_typeId 32
#define sjs_array_vertex_location_texture_normal_typeId 33
#define sjs_vertexbuffer_vertex_location_texture_normal_typeId 34
#define sjs_texture_typeId 35
#define sjs_model_typeId 36
#define sjs_vec4_typeId 37
#define sjs_vec2_typeId 38
#define sjs_vertex_location_texture_normal_typeId 39
#define sjs_array_texture_typeId 40
#define sjs_leafpanel_typeId 41
#define cb_texture_heap_model_typeId 42
#define cb_texture_heap_model_heap_typeId 43
#define sjs_array_mat4_typeId 44
#define sjs_peoplepanel_typeId 45
#define cb_heap_model_mat4_typeId 46
#define cb_heap_model_mat4_heap_typeId 47
#define cb_heap_model_mat4_heap_mat4_typeId 48
#define cb_heap_model_mat4_heap_mat4_heap_typeId 49
#define sjs_framebuffer_typeId 50
#define sjs_renderbuffer_typeId 51
#define sjs_scene2dmodel_typeId 52
#define sjs_boxrenderer_typeId 53
#define sjs_boxelement_typeId 54
#define sjs_margin_typeId 55
#define sjs_image_typeId 56
#define sjs_imagerenderer_typeId 57
#define sjs_imageelement_typeId 58
#define sjs_crosshairselement_typeId 59
#define sjs_panel3d_typeId 60

typedef struct td_sjs_object sjs_object;
typedef struct td_sjs_windowrenderer sjs_windowrenderer;
typedef struct td_sjs_size sjs_size;
typedef struct td_sjs_mat4 sjs_mat4;
typedef struct td_sjs_scene2d sjs_scene2d;
typedef struct td_sjs_array_heap_animation sjs_array_heap_animation;
typedef struct td_sjs_list_heap_animation sjs_list_heap_animation;
typedef struct td_sjs_anon1 sjs_anon1;
typedef struct td_sji_animation sji_animation;
typedef struct td_sjs_anon2 sjs_anon2;
typedef struct td_sjs_anon3 sjs_anon3;
typedef struct td_sjs_anon4 sjs_anon4;
typedef struct td_sjs_array_char sjs_array_char;
typedef struct td_sjs_string sjs_string;
typedef struct td_sjs_shader sjs_shader;
typedef struct td_sjs_anon5 sjs_anon5;
typedef struct td_sjs_array_heap_element sjs_array_heap_element;
typedef struct td_sjs_rect sjs_rect;
typedef struct td_sjs_fillelement sjs_fillelement;
typedef struct td_sjs_point sjs_point;
typedef struct td_sjs_mouseevent sjs_mouseevent;
typedef struct td_sji_element sji_element;
typedef struct td_sjs_array_heap_model sjs_array_heap_model;
typedef struct td_sjs_vec3 sjs_vec3;
typedef struct td_sjs_color sjs_color;
typedef struct td_sjs_light sjs_light;
typedef struct td_sjs_nauscene3delement sjs_nauscene3delement;
typedef struct td_sji_model sji_model;
typedef struct td_sjs_list_heap_model sjs_list_heap_model;
typedef struct td_cb_heap_model_heap_model_i32 cb_heap_model_heap_model_i32;
typedef struct td_cb_heap_model_heap_model_i32_heap cb_heap_model_heap_model_i32_heap;
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
typedef struct td_cb_texture_heap_model cb_texture_heap_model;
typedef struct td_cb_texture_heap_model_heap cb_texture_heap_model_heap;
typedef struct td_sjs_array_mat4 sjs_array_mat4;
typedef struct td_sjs_peoplepanel sjs_peoplepanel;
typedef struct td_cb_heap_model_mat4 cb_heap_model_mat4;
typedef struct td_cb_heap_model_mat4_heap cb_heap_model_mat4_heap;
typedef struct td_cb_heap_model_mat4_heap_mat4 cb_heap_model_mat4_heap_mat4;
typedef struct td_cb_heap_model_mat4_heap_mat4_heap cb_heap_model_mat4_heap_mat4_heap;
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

struct td_sjs_array_heap_animation {
    int _refCount;
    int32_t datasize;
    void* data;
    bool _isglobal;
    int32_t count;
};

struct td_sjs_list_heap_animation {
    int _refCount;
    sjs_array_heap_animation array;
};

struct td_sjs_anon1 {
    int _refCount;
    sjs_list_heap_animation animations;
    int32_t current;
};

struct td_sji_animation {
    intptr_t _refCount;
    sjs_object* _parent;
    void (*destroy)(void* _this);
    sjs_object* (*asInterface)(sjs_object* _this, int typeId);
    void (*nextframe)(void* _parent, int32_t time, bool* _return);
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

struct td_sjs_shader {
    int _refCount;
    sjs_string vertex;
    sjs_string pixel;
    GLuint id;
};

struct td_sjs_anon5 {
    int _refCount;
};

struct td_sjs_array_heap_element {
    int _refCount;
    int32_t datasize;
    void* data;
    bool _isglobal;
    int32_t count;
};

struct td_sjs_rect {
    int _refCount;
    int32_t x;
    int32_t y;
    int32_t w;
    int32_t h;
};

struct td_sjs_fillelement {
    int _refCount;
    sjs_array_heap_element children;
    sjs_rect _rect;
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

struct td_sji_element {
    intptr_t _refCount;
    sjs_object* _parent;
    void (*destroy)(void* _this);
    sjs_object* (*asInterface)(sjs_object* _this, int typeId);
    void (*getsize)(void* _parent, sjs_size* maxsize, sjs_size* _return);
    void (*getsize_heap)(void* _parent, sjs_size* maxsize, sjs_size** _return);
    void (*getrect)(void* _parent, sjs_rect** _return);
    void (*setrect)(void* _parent, sjs_rect* rect);
    void (*render)(void* _parent, sjs_scene2d* scene);
    void (*firemouseevent)(void* _parent, sjs_mouseevent* mouseevent);
};

struct td_sjs_array_heap_model {
    int _refCount;
    int32_t datasize;
    void* data;
    bool _isglobal;
    int32_t count;
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

struct td_sjs_nauscene3delement {
    int _refCount;
    sjs_array_heap_model children;
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

struct td_sji_model {
    intptr_t _refCount;
    sjs_object* _parent;
    void (*destroy)(void* _this);
    sjs_object* (*asInterface)(sjs_object* _this, int typeId);
    void (*update)(void* _parent, sjs_rect* scenerect, sjs_mat4* projection, sjs_mat4* view, sjs_mat4* world, sjs_light* light);
    void (*getz)(void* _parent, float* _return);
    void (*renderorqueue)(void* _parent, sjs_list_heap_model* zqueue);
    void (*render)(void* _parent);
    void (*firemouseevent)(void* _parent, sjs_mouseevent* mouseevent);
};

struct td_sjs_list_heap_model {
    int _refCount;
    sjs_array_heap_model array;
};

struct td_cb_heap_model_heap_model_i32 {
    void* _parent;
    void (*_cb)(void* _parent, sji_model*, sji_model*, int32_t* _return);
};

struct td_cb_heap_model_heap_model_i32_heap {
    cb_heap_model_heap_model_i32 inner;
    void (*_destroy)(void*);
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
    sjs_array_heap_model children;
    float _angle;
};

struct td_cb_texture_heap_model {
    void* _parent;
    void (*_cb_heap)(void* _parent, sjs_texture*, sji_model** _return);
};

struct td_cb_texture_heap_model_heap {
    cb_texture_heap_model inner;
    void (*_destroy)(void*);
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
    sjs_array_heap_model children;
    sjs_array_mat4 _childrenmodel;
    int32_t _index;
    int32_t _depth;
    float _xincrement;
    float _zincrement;
    float _xoffset;
};

struct td_cb_heap_model_mat4 {
    void* _parent;
    void (*_cb)(void* _parent, sji_model*, sjs_mat4* _return);
};

struct td_cb_heap_model_mat4_heap {
    cb_heap_model_mat4 inner;
    void (*_destroy)(void*);
};

struct td_cb_heap_model_mat4_heap_mat4 {
    void* _parent;
    void (*_cb)(void* _parent, sji_model*, sjs_mat4* _return);
    void (*_cb_heap)(void* _parent, sji_model*, sjs_mat4** _return);
};

struct td_cb_heap_model_mat4_heap_mat4_heap {
    cb_heap_model_mat4_heap_mat4 inner;
    void (*_destroy)(void*);
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
    sjs_array_heap_element children;
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
    sjs_array_heap_model children;
};

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
void ptr_init();
void ptr_retain(void* ptr);
bool ptr_release(void* ptr);
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
float result62;
float result63;
float result64;
float result65;
sjs_mat4 sjt_call100 = { -1 };
sjs_string sjt_call101 = { -1 };
sjs_mat4 sjt_call102 = { -1 };
sjs_mat4 sjt_call103 = { -1 };
sjs_string sjt_call104 = { -1 };
sjs_mat4 sjt_call105 = { -1 };
sjs_mat4 sjt_call106 = { -1 };
sjs_vec3 sjt_call107 = { -1 };
sjs_vec3 sjt_call108 = { -1 };
sjs_vec3 sjt_call109 = { -1 };
sjs_string sjt_call30 = { -1 };
sjs_mat4 sjt_call31 = { -1 };
sjs_mat4 sjt_call32 = { -1 };
sjs_texture sjt_call37 = { -1 };
sjs_string sjt_call38 = { -1 };
sjs_texture sjt_call39 = { -1 };
sjs_string sjt_call40 = { -1 };
sjs_texture sjt_call41 = { -1 };
sjs_string sjt_call42 = { -1 };
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
sjs_string sjt_call75 = { -1 };
sjs_string sjt_call76 = { -1 };
sjs_string sjt_call77 = { -1 };
sjs_mat4 sjt_call78 = { -1 };
sjs_mat4 sjt_call79 = { -1 };
sjs_string sjt_call80 = { -1 };
sjs_mat4 sjt_call81 = { -1 };
sjs_mat4 sjt_call82 = { -1 };
sjs_string sjt_call83 = { -1 };
sjs_mat4 sjt_call84 = { -1 };
sjs_mat4 sjt_call85 = { -1 };
sjs_string sjt_call86 = { -1 };
sjs_mat4 sjt_call87 = { -1 };
sjs_mat4 sjt_call88 = { -1 };
sjs_string sjt_call89 = { -1 };
sjs_mat4 sjt_call90 = { -1 };
sjs_mat4 sjt_call91 = { -1 };
sjs_string sjt_call92 = { -1 };
sjs_mat4 sjt_call93 = { -1 };
sjs_mat4 sjt_call94 = { -1 };
sjs_string sjt_call95 = { -1 };
sjs_mat4 sjt_call96 = { -1 };
sjs_mat4 sjt_call97 = { -1 };
sjs_string sjt_call98 = { -1 };
sjs_mat4 sjt_call99 = { -1 };
sjs_fillelement* sjt_cast1 = 0;
sjs_model* sjt_cast11 = 0;
sjs_leafpanel* sjt_cast13 = 0;
sjs_peoplepanel* sjt_cast19 = 0;
sjs_nauscene3delement* sjt_cast2 = 0;
sjs_scene2dmodel* sjt_cast30 = 0;
sjs_boxelement* sjt_cast42 = 0;
sjs_imageelement* sjt_cast43 = 0;
sjs_crosshairselement* sjt_cast44 = 0;
sjs_scene2dmodel* sjt_cast45 = 0;
sjs_boxelement* sjt_cast46 = 0;
sjs_imageelement* sjt_cast47 = 0;
sjs_crosshairselement* sjt_cast48 = 0;
sjs_panel3d* sjt_cast49 = 0;
sjs_model* sjt_cast50 = 0;
sjs_model* sjt_cast51 = 0;
sjs_model* sjt_cast52 = 0;
sjs_model* sjt_cast53 = 0;
sjs_model* sjt_cast54 = 0;
sjs_model* sjt_cast55 = 0;
sjs_model* sjt_cast56 = 0;
sjs_model* sjt_cast57 = 0;
sjs_model* sjt_cast58 = 0;
sjs_model* sjt_cast59 = 0;
sjs_crosshairselement* sjt_cast60 = 0;
sjs_shader* sjt_copy11;
sjs_shader* sjt_copy33;
sjs_shader* sjt_copy45;
sjs_shader* sjt_copy46;
sjs_shader* sjt_copy47;
sjs_shader* sjt_copy48;
sjs_shader* sjt_copy49;
sjs_shader* sjt_copy50;
sjs_shader* sjt_copy51;
sjs_shader* sjt_copy52;
sjs_shader* sjt_copy53;
sjs_shader* sjt_copy54;
sjs_shader* sjt_copy55;
int32_t sjt_functionParam103;
sji_model* sjt_functionParam104 = 0;
float sjt_functionParam191;
float sjt_functionParam192;
float sjt_functionParam193;
float sjt_functionParam194;
float sjt_functionParam195;
float sjt_functionParam196;
float sjt_functionParam197;
float sjt_functionParam198;
float sjt_functionParam199;
sjs_string* sjt_functionParam200;
float sjt_functionParam201;
float sjt_functionParam202;
float sjt_functionParam203;
sjs_mat4* sjt_functionParam204;
float sjt_functionParam205;
float sjt_functionParam206;
float sjt_functionParam207;
int32_t sjt_functionParam208;
sji_model* sjt_functionParam209 = 0;
int32_t sjt_functionParam253;
sjs_texture* sjt_functionParam254;
sjs_string* sjt_functionParam255;
int32_t sjt_functionParam256;
sjs_texture* sjt_functionParam257;
sjs_string* sjt_functionParam258;
int32_t sjt_functionParam259;
sjs_texture* sjt_functionParam260;
sjs_string* sjt_functionParam261;
int32_t sjt_functionParam262;
sjs_texture* sjt_functionParam263;
sjs_string* sjt_functionParam264;
int32_t sjt_functionParam265;
sjs_texture* sjt_functionParam266;
sjs_string* sjt_functionParam267;
int32_t sjt_functionParam268;
sjs_texture* sjt_functionParam269;
sjs_string* sjt_functionParam270;
int32_t sjt_functionParam271;
sjs_texture* sjt_functionParam272;
sjs_string* sjt_functionParam273;
int32_t sjt_functionParam274;
sjs_texture* sjt_functionParam275;
sjs_string* sjt_functionParam276;
int32_t sjt_functionParam277;
sji_model* sjt_functionParam278 = 0;
float sjt_functionParam301;
float sjt_functionParam302;
float sjt_functionParam303;
int32_t sjt_functionParam304;
sji_model* sjt_functionParam305 = 0;
int32_t sjt_functionParam4;
float sjt_functionParam470;
float sjt_functionParam471;
float sjt_functionParam472;
float sjt_functionParam473;
float sjt_functionParam474;
float sjt_functionParam475;
float sjt_functionParam476;
float sjt_functionParam477;
float sjt_functionParam478;
int32_t sjt_functionParam479;
sji_element* sjt_functionParam480 = 0;
int32_t sjt_functionParam485;
sji_element* sjt_functionParam486 = 0;
sjs_string* sjt_functionParam490;
int32_t sjt_functionParam491;
sji_element* sjt_functionParam492 = 0;
int32_t sjt_functionParam497;
sji_model* sjt_functionParam498 = 0;
float sjt_functionParam499;
sji_element* sjt_functionParam5 = 0;
float sjt_functionParam500;
float sjt_functionParam501;
float sjt_functionParam502;
float sjt_functionParam503;
float sjt_functionParam504;
float sjt_functionParam505;
float sjt_functionParam506;
float sjt_functionParam507;
int32_t sjt_functionParam508;
sji_element* sjt_functionParam509 = 0;
int32_t sjt_functionParam510;
sji_element* sjt_functionParam511 = 0;
sjs_string* sjt_functionParam512;
int32_t sjt_functionParam513;
sji_element* sjt_functionParam514 = 0;
int32_t sjt_functionParam515;
sji_model* sjt_functionParam516 = 0;
float sjt_functionParam521;
float sjt_functionParam522;
float sjt_functionParam523;
int32_t sjt_functionParam524;
sji_model* sjt_functionParam525 = 0;
float sjt_functionParam526;
float sjt_functionParam527;
float sjt_functionParam528;
float sjt_functionParam529;
float sjt_functionParam530;
float sjt_functionParam531;
float sjt_functionParam532;
float sjt_functionParam533;
float sjt_functionParam534;
sjs_string* sjt_functionParam535;
float sjt_functionParam536;
float sjt_functionParam537;
float sjt_functionParam538;
sjs_mat4* sjt_functionParam539;
float sjt_functionParam540;
float sjt_functionParam541;
float sjt_functionParam542;
int32_t sjt_functionParam543;
sji_model* sjt_functionParam544 = 0;
float sjt_functionParam545;
float sjt_functionParam546;
float sjt_functionParam547;
float sjt_functionParam548;
float sjt_functionParam549;
float sjt_functionParam550;
float sjt_functionParam551;
float sjt_functionParam552;
float sjt_functionParam553;
sjs_string* sjt_functionParam554;
float sjt_functionParam555;
float sjt_functionParam556;
float sjt_functionParam557;
sjs_mat4* sjt_functionParam558;
float sjt_functionParam559;
float sjt_functionParam560;
float sjt_functionParam561;
int32_t sjt_functionParam562;
sji_model* sjt_functionParam563 = 0;
float sjt_functionParam564;
float sjt_functionParam565;
float sjt_functionParam566;
float sjt_functionParam567;
float sjt_functionParam568;
float sjt_functionParam569;
float sjt_functionParam570;
float sjt_functionParam571;
float sjt_functionParam572;
sjs_string* sjt_functionParam573;
float sjt_functionParam574;
float sjt_functionParam575;
float sjt_functionParam576;
sjs_mat4* sjt_functionParam577;
float sjt_functionParam578;
float sjt_functionParam579;
float sjt_functionParam580;
int32_t sjt_functionParam581;
sji_model* sjt_functionParam582 = 0;
float sjt_functionParam583;
float sjt_functionParam584;
float sjt_functionParam585;
float sjt_functionParam586;
float sjt_functionParam587;
float sjt_functionParam588;
float sjt_functionParam589;
float sjt_functionParam590;
float sjt_functionParam591;
sjs_string* sjt_functionParam592;
float sjt_functionParam593;
float sjt_functionParam594;
float sjt_functionParam595;
sjs_mat4* sjt_functionParam596;
float sjt_functionParam597;
float sjt_functionParam598;
float sjt_functionParam599;
int32_t sjt_functionParam600;
sji_model* sjt_functionParam601 = 0;
float sjt_functionParam602;
float sjt_functionParam603;
float sjt_functionParam604;
float sjt_functionParam605;
float sjt_functionParam606;
float sjt_functionParam607;
float sjt_functionParam608;
float sjt_functionParam609;
float sjt_functionParam610;
sjs_string* sjt_functionParam611;
float sjt_functionParam612;
float sjt_functionParam613;
float sjt_functionParam614;
sjs_mat4* sjt_functionParam615;
float sjt_functionParam616;
float sjt_functionParam617;
float sjt_functionParam618;
int32_t sjt_functionParam619;
sji_model* sjt_functionParam620 = 0;
float sjt_functionParam621;
float sjt_functionParam622;
float sjt_functionParam623;
float sjt_functionParam624;
float sjt_functionParam625;
float sjt_functionParam626;
float sjt_functionParam627;
float sjt_functionParam628;
float sjt_functionParam629;
sjs_string* sjt_functionParam630;
float sjt_functionParam631;
float sjt_functionParam632;
float sjt_functionParam633;
sjs_mat4* sjt_functionParam634;
float sjt_functionParam635;
float sjt_functionParam636;
float sjt_functionParam637;
int32_t sjt_functionParam638;
sji_model* sjt_functionParam639 = 0;
float sjt_functionParam640;
float sjt_functionParam641;
float sjt_functionParam642;
float sjt_functionParam643;
float sjt_functionParam644;
float sjt_functionParam645;
float sjt_functionParam646;
float sjt_functionParam647;
float sjt_functionParam648;
sjs_string* sjt_functionParam649;
float sjt_functionParam650;
float sjt_functionParam651;
float sjt_functionParam652;
sjs_mat4* sjt_functionParam653;
float sjt_functionParam654;
float sjt_functionParam655;
float sjt_functionParam656;
int32_t sjt_functionParam657;
sji_model* sjt_functionParam658 = 0;
float sjt_functionParam659;
float sjt_functionParam660;
float sjt_functionParam661;
float sjt_functionParam662;
float sjt_functionParam663;
float sjt_functionParam664;
float sjt_functionParam665;
float sjt_functionParam666;
float sjt_functionParam667;
sjs_string* sjt_functionParam668;
float sjt_functionParam669;
float sjt_functionParam670;
float sjt_functionParam671;
sjs_mat4* sjt_functionParam672;
float sjt_functionParam673;
float sjt_functionParam674;
float sjt_functionParam675;
int32_t sjt_functionParam676;
sji_model* sjt_functionParam677 = 0;
float sjt_functionParam678;
float sjt_functionParam679;
float sjt_functionParam680;
float sjt_functionParam681;
float sjt_functionParam682;
float sjt_functionParam683;
float sjt_functionParam684;
float sjt_functionParam685;
float sjt_functionParam686;
sjs_string* sjt_functionParam687;
float sjt_functionParam688;
float sjt_functionParam689;
float sjt_functionParam690;
sjs_mat4* sjt_functionParam691;
float sjt_functionParam692;
float sjt_functionParam693;
float sjt_functionParam694;
int32_t sjt_functionParam695;
sji_model* sjt_functionParam696 = 0;
float sjt_functionParam697;
float sjt_functionParam698;
float sjt_functionParam699;
float sjt_functionParam700;
float sjt_functionParam701;
float sjt_functionParam702;
float sjt_functionParam703;
float sjt_functionParam704;
float sjt_functionParam705;
sjs_string* sjt_functionParam706;
float sjt_functionParam707;
float sjt_functionParam708;
float sjt_functionParam709;
sjs_mat4* sjt_functionParam710;
float sjt_functionParam711;
float sjt_functionParam712;
float sjt_functionParam713;
sjs_vec3* sjt_functionParam714;
sjs_vec3* sjt_functionParam715;
sjs_vec3* sjt_functionParam716;
int32_t sjt_functionParam717;
sji_element* sjt_functionParam718 = 0;
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
sjs_array_texture* sjt_parent101;
sjs_array_texture* sjt_parent102;
sjs_array_texture* sjt_parent103;
sjs_array_texture* sjt_parent104;
sjs_array_texture* sjt_parent105;
sjs_array_texture* sjt_parent106;
sjs_array_texture* sjt_parent107;
sjs_array_texture* sjt_parent108;
sjs_array_heap_model* sjt_parent109;
sjs_array_heap_model* sjt_parent121;
sjs_array_heap_element* sjt_parent184;
sjs_anon4* sjt_parent189;
sjs_array_heap_element* sjt_parent190;
sjs_array_heap_element* sjt_parent196;
sjs_anon4* sjt_parent201;
sjs_array_heap_model* sjt_parent202;
sjs_array_heap_element* sjt_parent203;
sjs_anon4* sjt_parent204;
sjs_array_heap_element* sjt_parent205;
sjs_array_heap_element* sjt_parent206;
sjs_anon4* sjt_parent207;
sjs_array_heap_model* sjt_parent208;
sjs_array_heap_model* sjt_parent216;
sjs_mat4* sjt_parent217;
sjs_array_heap_model* sjt_parent218;
sjs_mat4* sjt_parent219;
sjs_array_heap_model* sjt_parent220;
sjs_mat4* sjt_parent221;
sjs_array_heap_model* sjt_parent222;
sjs_mat4* sjt_parent223;
sjs_array_heap_model* sjt_parent224;
sjs_mat4* sjt_parent225;
sjs_array_heap_model* sjt_parent226;
sjs_mat4* sjt_parent227;
sjs_array_heap_model* sjt_parent228;
sjs_mat4* sjt_parent229;
sjs_array_heap_model* sjt_parent230;
sjs_mat4* sjt_parent231;
sjs_array_heap_model* sjt_parent232;
sjs_mat4* sjt_parent233;
sjs_array_heap_model* sjt_parent234;
sjs_mat4* sjt_parent235;
sjs_array_heap_element* sjt_parent236;
sjs_anon4* sjt_parent237;
sjs_array_heap_model* sjt_parent41;
sjs_array_heap_element* sjt_parent7;
sjs_mat4* sjt_parent77;
sjs_array_heap_model* sjt_parent78;
sjs_anon1 sjv_animator = { -1 };
sjs_shader sjv_blurhorizontalshader = { -1 };
sjs_shader sjv_blurverticalshader = { -1 };
sjs_anon2 sjv_borderposition = { -1 };
sjs_shader sjv_boxshader = { -1 };
sjs_anon3 sjv_buttonstate = { -1 };
sjs_anon4 sjv_colors = { -1 };
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
sji_element* sjv_mouse_captureelement = 0;
int32_t sjv_mouseeventtype_down;
int32_t sjv_mouseeventtype_move;
int32_t sjv_mouseeventtype_up;
sjs_shader sjv_phongcolorshader = { -1 };
sjs_shader sjv_phongtextureshader = { -1 };
sji_element* sjv_root = 0;
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
void sjf_array_char_setat(sjs_array_char* _parent, int32_t index, char item);
void sjf_array_heap_animation(sjs_array_heap_animation* _this);
void sjf_array_heap_animation_copy(sjs_array_heap_animation* _this, sjs_array_heap_animation* _from);
void sjf_array_heap_animation_destroy(sjs_array_heap_animation* _this);
void sjf_array_heap_animation_getat_heap(sjs_array_heap_animation* _parent, int32_t index, sji_animation** _return);
void sjf_array_heap_animation_heap(sjs_array_heap_animation* _this);
void sjf_array_heap_element(sjs_array_heap_element* _this);
void sjf_array_heap_element_copy(sjs_array_heap_element* _this, sjs_array_heap_element* _from);
void sjf_array_heap_element_destroy(sjs_array_heap_element* _this);
void sjf_array_heap_element_getat_heap(sjs_array_heap_element* _parent, int32_t index, sji_element** _return);
void sjf_array_heap_element_heap(sjs_array_heap_element* _this);
void sjf_array_heap_element_initat(sjs_array_heap_element* _parent, int32_t index, sji_element* item);
void sjf_array_heap_model(sjs_array_heap_model* _this);
void sjf_array_heap_model__quicksortcallback(sjs_array_heap_model* _parent, int32_t left, int32_t right, cb_heap_model_heap_model_i32 cb);
void sjf_array_heap_model_copy(sjs_array_heap_model* _this, sjs_array_heap_model* _from);
void sjf_array_heap_model_destroy(sjs_array_heap_model* _this);
void sjf_array_heap_model_getat_heap(sjs_array_heap_model* _parent, int32_t index, sji_model** _return);
void sjf_array_heap_model_grow(sjs_array_heap_model* _parent, int32_t newsize, sjs_array_heap_model* _return);
void sjf_array_heap_model_grow_heap(sjs_array_heap_model* _parent, int32_t newsize, sjs_array_heap_model** _return);
void sjf_array_heap_model_heap(sjs_array_heap_model* _this);
void sjf_array_heap_model_initat(sjs_array_heap_model* _parent, int32_t index, sji_model* item);
void sjf_array_heap_model_map_mat4(sjs_array_heap_model* _parent, cb_heap_model_mat4 cb, sjs_array_mat4* _return);
void sjf_array_heap_model_map_mat4_heap(sjs_array_heap_model* _parent, cb_heap_model_mat4 cb, sjs_array_mat4** _return);
void sjf_array_heap_model_setat(sjs_array_heap_model* _parent, int32_t index, sji_model* item);
void sjf_array_heap_model_sortcb(sjs_array_heap_model* _parent, cb_heap_model_heap_model_i32 cb);
void sjf_array_i32(sjs_array_i32* _this);
void sjf_array_i32_copy(sjs_array_i32* _this, sjs_array_i32* _from);
void sjf_array_i32_destroy(sjs_array_i32* _this);
void sjf_array_i32_getat(sjs_array_i32* _parent, int32_t index, int32_t* _return);
void sjf_array_i32_heap(sjs_array_i32* _this);
void sjf_array_i32_initat(sjs_array_i32* _parent, int32_t index, int32_t item);
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
void sjf_array_texture_map_heap_model(sjs_array_texture* _parent, cb_texture_heap_model cb, sjs_array_heap_model* _return);
void sjf_array_texture_map_heap_model_heap(sjs_array_texture* _parent, cb_texture_heap_model cb, sjs_array_heap_model** _return);
void sjf_array_vertex_location_texture_normal(sjs_array_vertex_location_texture_normal* _this);
void sjf_array_vertex_location_texture_normal_copy(sjs_array_vertex_location_texture_normal* _this, sjs_array_vertex_location_texture_normal* _from);
void sjf_array_vertex_location_texture_normal_destroy(sjs_array_vertex_location_texture_normal* _this);
void sjf_array_vertex_location_texture_normal_getat(sjs_array_vertex_location_texture_normal* _parent, int32_t index, sjs_vertex_location_texture_normal* _return);
void sjf_array_vertex_location_texture_normal_heap(sjs_array_vertex_location_texture_normal* _this);
void sjf_array_vertex_location_texture_normal_initat(sjs_array_vertex_location_texture_normal* _parent, int32_t index, sjs_vertex_location_texture_normal* item);
void sjf_boxelement(sjs_boxelement* _this);
sjs_object* sjf_boxelement_asInterface(sjs_boxelement* _this, int typeId);
sji_element* sjf_boxelement_as_sji_element(sjs_boxelement* _this);
void sjf_boxelement_copy(sjs_boxelement* _this, sjs_boxelement* _from);
void sjf_boxelement_destroy(sjs_boxelement* _this);
void sjf_boxelement_firemouseevent(sjs_boxelement* _parent, sjs_mouseevent* mouseevent);
void sjf_boxelement_getrect(sjs_boxelement* _parent, sjs_rect** _return);
void sjf_boxelement_getsize(sjs_boxelement* _parent, sjs_size* maxsize, sjs_size* _return);
void sjf_boxelement_getsize_heap(sjs_boxelement* _parent, sjs_size* maxsize, sjs_size** _return);
void sjf_boxelement_heap(sjs_boxelement* _this);
sjs_object* sjf_boxelement_heap_asInterface(sjs_boxelement* _this, int typeId);
sji_element* sjf_boxelement_heap_as_sji_element(sjs_boxelement* _this);
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
sjs_object* sjf_crosshairselement_asInterface(sjs_crosshairselement* _this, int typeId);
sji_element* sjf_crosshairselement_as_sji_element(sjs_crosshairselement* _this);
void sjf_crosshairselement_copy(sjs_crosshairselement* _this, sjs_crosshairselement* _from);
void sjf_crosshairselement_destroy(sjs_crosshairselement* _this);
void sjf_crosshairselement_firemouseevent(sjs_crosshairselement* _parent, sjs_mouseevent* mouseevent);
void sjf_crosshairselement_getrect(sjs_crosshairselement* _parent, sjs_rect** _return);
void sjf_crosshairselement_getsize(sjs_crosshairselement* _parent, sjs_size* maxsize, sjs_size* _return);
void sjf_crosshairselement_getsize_heap(sjs_crosshairselement* _parent, sjs_size* maxsize, sjs_size** _return);
void sjf_crosshairselement_heap(sjs_crosshairselement* _this);
sjs_object* sjf_crosshairselement_heap_asInterface(sjs_crosshairselement* _this, int typeId);
sji_element* sjf_crosshairselement_heap_as_sji_element(sjs_crosshairselement* _this);
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
sjs_object* sjf_fillelement_asInterface(sjs_fillelement* _this, int typeId);
sji_element* sjf_fillelement_as_sji_element(sjs_fillelement* _this);
void sjf_fillelement_copy(sjs_fillelement* _this, sjs_fillelement* _from);
void sjf_fillelement_destroy(sjs_fillelement* _this);
void sjf_fillelement_firemouseevent(sjs_fillelement* _parent, sjs_mouseevent* mouseevent);
void sjf_fillelement_getrect(sjs_fillelement* _parent, sjs_rect** _return);
void sjf_fillelement_getsize(sjs_fillelement* _parent, sjs_size* maxsize, sjs_size* _return);
void sjf_fillelement_getsize_heap(sjs_fillelement* _parent, sjs_size* maxsize, sjs_size** _return);
void sjf_fillelement_heap(sjs_fillelement* _this);
sjs_object* sjf_fillelement_heap_asInterface(sjs_fillelement* _this, int typeId);
sji_element* sjf_fillelement_heap_as_sji_element(sjs_fillelement* _this);
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
void sjf_i32_max(int32_t a, int32_t b, int32_t* _return);
void sjf_image(sjs_image* _this);
void sjf_image_copy(sjs_image* _this, sjs_image* _from);
void sjf_image_destroy(sjs_image* _this);
void sjf_image_heap(sjs_image* _this);
void sjf_imageelement(sjs_imageelement* _this);
sjs_object* sjf_imageelement_asInterface(sjs_imageelement* _this, int typeId);
sji_element* sjf_imageelement_as_sji_element(sjs_imageelement* _this);
void sjf_imageelement_copy(sjs_imageelement* _this, sjs_imageelement* _from);
void sjf_imageelement_destroy(sjs_imageelement* _this);
void sjf_imageelement_firemouseevent(sjs_imageelement* _parent, sjs_mouseevent* mouseevent);
void sjf_imageelement_getrect(sjs_imageelement* _parent, sjs_rect** _return);
void sjf_imageelement_getsize(sjs_imageelement* _parent, sjs_size* maxsize, sjs_size* _return);
void sjf_imageelement_getsize_heap(sjs_imageelement* _parent, sjs_size* maxsize, sjs_size** _return);
void sjf_imageelement_heap(sjs_imageelement* _this);
sjs_object* sjf_imageelement_heap_asInterface(sjs_imageelement* _this, int typeId);
sji_element* sjf_imageelement_heap_as_sji_element(sjs_imageelement* _this);
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
sjs_object* sjf_leafpanel_asInterface(sjs_leafpanel* _this, int typeId);
sji_model* sjf_leafpanel_as_sji_model(sjs_leafpanel* _this);
void sjf_leafpanel_copy(sjs_leafpanel* _this, sjs_leafpanel* _from);
void sjf_leafpanel_destroy(sjs_leafpanel* _this);
void sjf_leafpanel_firemouseevent(sjs_leafpanel* _parent, sjs_mouseevent* mouseevent);
void sjf_leafpanel_getz(sjs_leafpanel* _parent, float* _return);
void sjf_leafpanel_heap(sjs_leafpanel* _this);
sjs_object* sjf_leafpanel_heap_asInterface(sjs_leafpanel* _this, int typeId);
sji_model* sjf_leafpanel_heap_as_sji_model(sjs_leafpanel* _this);
void sjf_leafpanel_render(sjs_leafpanel* _parent);
void sjf_leafpanel_renderorqueue(sjs_leafpanel* _parent, sjs_list_heap_model* zqueue);
void sjf_leafpanel_texturetomodel_heap(sjs_leafpanel* _parent, sjs_texture* texture, sji_model** _return);
void sjf_leafpanel_update(sjs_leafpanel* _parent, sjs_rect* scenerect, sjs_mat4* projection, sjs_mat4* view, sjs_mat4* world, sjs_light* light);
void sjf_light(sjs_light* _this);
void sjf_light_copy(sjs_light* _this, sjs_light* _from);
void sjf_light_destroy(sjs_light* _this);
void sjf_light_heap(sjs_light* _this);
void sjf_list_heap_animation(sjs_list_heap_animation* _this);
void sjf_list_heap_animation_copy(sjs_list_heap_animation* _this, sjs_list_heap_animation* _from);
void sjf_list_heap_animation_destroy(sjs_list_heap_animation* _this);
void sjf_list_heap_animation_getat_heap(sjs_list_heap_animation* _parent, int32_t index, sji_animation** _return);
void sjf_list_heap_animation_getcount(sjs_list_heap_animation* _parent, int32_t* _return);
void sjf_list_heap_animation_heap(sjs_list_heap_animation* _this);
void sjf_list_heap_animation_removeat(sjs_list_heap_animation* _parent, int32_t index);
void sjf_list_heap_model(sjs_list_heap_model* _this);
void sjf_list_heap_model_add(sjs_list_heap_model* _parent, sji_model* item);
void sjf_list_heap_model_copy(sjs_list_heap_model* _this, sjs_list_heap_model* _from);
void sjf_list_heap_model_destroy(sjs_list_heap_model* _this);
void sjf_list_heap_model_getat_heap(sjs_list_heap_model* _parent, int32_t index, sji_model** _return);
void sjf_list_heap_model_getcount(sjs_list_heap_model* _parent, int32_t* _return);
void sjf_list_heap_model_heap(sjs_list_heap_model* _this);
void sjf_list_heap_model_sortcb(sjs_list_heap_model* _parent, cb_heap_model_heap_model_i32 cb);
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
sjs_object* sjf_model_asInterface(sjs_model* _this, int typeId);
sji_model* sjf_model_as_sji_model(sjs_model* _this);
void sjf_model_copy(sjs_model* _this, sjs_model* _from);
void sjf_model_destroy(sjs_model* _this);
void sjf_model_firemouseevent(sjs_model* _parent, sjs_mouseevent* mouseevent);
void sjf_model_getz(sjs_model* _parent, float* _return);
void sjf_model_heap(sjs_model* _this);
sjs_object* sjf_model_heap_asInterface(sjs_model* _this, int typeId);
sji_model* sjf_model_heap_as_sji_model(sjs_model* _this);
void sjf_model_render(sjs_model* _parent);
void sjf_model_renderorqueue(sjs_model* _parent, sjs_list_heap_model* zqueue);
void sjf_model_update(sjs_model* _parent, sjs_rect* scenerect, sjs_mat4* projection, sjs_mat4* view, sjs_mat4* world, sjs_light* light);
void sjf_model_zsort(sji_model* l, sji_model* r, int32_t* _return);
void sjf_model_zsort_callback(void * _parent, sji_model* l, sji_model* r, int32_t* _return);
void sjf_mouse_capture(sji_element* element);
void sjf_mouse_release(sji_element* element);
void sjf_mouseevent(sjs_mouseevent* _this);
void sjf_mouseevent_copy(sjs_mouseevent* _this, sjs_mouseevent* _from);
void sjf_mouseevent_destroy(sjs_mouseevent* _this);
void sjf_mouseevent_heap(sjs_mouseevent* _this);
void sjf_nauscene3delement(sjs_nauscene3delement* _this);
sjs_object* sjf_nauscene3delement_asInterface(sjs_nauscene3delement* _this, int typeId);
sji_element* sjf_nauscene3delement_as_sji_element(sjs_nauscene3delement* _this);
void sjf_nauscene3delement_copy(sjs_nauscene3delement* _this, sjs_nauscene3delement* _from);
void sjf_nauscene3delement_destroy(sjs_nauscene3delement* _this);
void sjf_nauscene3delement_firemouseevent(sjs_nauscene3delement* _parent, sjs_mouseevent* mouseevent);
void sjf_nauscene3delement_getrect(sjs_nauscene3delement* _parent, sjs_rect** _return);
void sjf_nauscene3delement_getsize(sjs_nauscene3delement* _parent, sjs_size* maxsize, sjs_size* _return);
void sjf_nauscene3delement_getsize_heap(sjs_nauscene3delement* _parent, sjs_size* maxsize, sjs_size** _return);
void sjf_nauscene3delement_heap(sjs_nauscene3delement* _this);
sjs_object* sjf_nauscene3delement_heap_asInterface(sjs_nauscene3delement* _this, int typeId);
sji_element* sjf_nauscene3delement_heap_as_sji_element(sjs_nauscene3delement* _this);
void sjf_nauscene3delement_render(sjs_nauscene3delement* _parent, sjs_scene2d* scene);
void sjf_nauscene3delement_setrect(sjs_nauscene3delement* _parent, sjs_rect* rect_);
void sjf_panel3d(sjs_panel3d* _this);
sjs_object* sjf_panel3d_asInterface(sjs_panel3d* _this, int typeId);
sji_model* sjf_panel3d_as_sji_model(sjs_panel3d* _this);
void sjf_panel3d_copy(sjs_panel3d* _this, sjs_panel3d* _from);
void sjf_panel3d_destroy(sjs_panel3d* _this);
void sjf_panel3d_firemouseevent(sjs_panel3d* _parent, sjs_mouseevent* mouseevent);
void sjf_panel3d_getz(sjs_panel3d* _parent, float* _return);
void sjf_panel3d_heap(sjs_panel3d* _this);
sjs_object* sjf_panel3d_heap_asInterface(sjs_panel3d* _this, int typeId);
sji_model* sjf_panel3d_heap_as_sji_model(sjs_panel3d* _this);
void sjf_panel3d_render(sjs_panel3d* _parent);
void sjf_panel3d_renderorqueue(sjs_panel3d* _parent, sjs_list_heap_model* zqueue);
void sjf_panel3d_update(sjs_panel3d* _parent, sjs_rect* scenerect, sjs_mat4* projection, sjs_mat4* view, sjs_mat4* world, sjs_light* light);
void sjf_peoplepanel(sjs_peoplepanel* _this);
sjs_object* sjf_peoplepanel_asInterface(sjs_peoplepanel* _this, int typeId);
sji_model* sjf_peoplepanel_as_sji_model(sjs_peoplepanel* _this);
void sjf_peoplepanel_copy(sjs_peoplepanel* _this, sjs_peoplepanel* _from);
void sjf_peoplepanel_destroy(sjs_peoplepanel* _this);
void sjf_peoplepanel_firemouseevent(sjs_peoplepanel* _parent, sjs_mouseevent* mouseevent);
void sjf_peoplepanel_getmodelmatrix(sjs_peoplepanel* _parent, sji_model* model, sjs_mat4* _return);
void sjf_peoplepanel_getmodelmatrix_heap(sjs_peoplepanel* _parent, sji_model* model, sjs_mat4** _return);
void sjf_peoplepanel_getz(sjs_peoplepanel* _parent, float* _return);
void sjf_peoplepanel_heap(sjs_peoplepanel* _this);
sjs_object* sjf_peoplepanel_heap_asInterface(sjs_peoplepanel* _this, int typeId);
sji_model* sjf_peoplepanel_heap_as_sji_model(sjs_peoplepanel* _this);
void sjf_peoplepanel_render(sjs_peoplepanel* _parent);
void sjf_peoplepanel_renderorqueue(sjs_peoplepanel* _parent, sjs_list_heap_model* zqueue);
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
sjs_object* sjf_scene2dmodel_asInterface(sjs_scene2dmodel* _this, int typeId);
sji_model* sjf_scene2dmodel_as_sji_model(sjs_scene2dmodel* _this);
void sjf_scene2dmodel_copy(sjs_scene2dmodel* _this, sjs_scene2dmodel* _from);
void sjf_scene2dmodel_destroy(sjs_scene2dmodel* _this);
void sjf_scene2dmodel_firemouseevent(sjs_scene2dmodel* _parent, sjs_mouseevent* mouseevent);
void sjf_scene2dmodel_getz(sjs_scene2dmodel* _parent, float* _return);
void sjf_scene2dmodel_heap(sjs_scene2dmodel* _this);
sjs_object* sjf_scene2dmodel_heap_asInterface(sjs_scene2dmodel* _this, int typeId);
sji_model* sjf_scene2dmodel_heap_as_sji_model(sjs_scene2dmodel* _this);
void sjf_scene2dmodel_render(sjs_scene2dmodel* _parent);
void sjf_scene2dmodel_renderorqueue(sjs_scene2dmodel* _parent, sjs_list_heap_model* alphamodels);
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
void sjf_string_heap(sjs_string* _this);
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
void sji_animation_copy(sji_animation* _this, sji_animation* _from);
void sji_animation_destroy(sji_animation* _this);
void sji_element_copy(sji_element* _this, sji_element* _from);
void sji_element_destroy(sji_element* _this);
void sji_model_copy(sji_model* _this, sji_model* _from);
void sji_model_destroy(sji_model* _this);
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
    sjf_list_heap_animation_copy(&_this->animations, &_from->animations);
    _this->current = _from->current;
}

void sjf_anon1_destroy(sjs_anon1* _this) {
}

void sjf_anon1_heap(sjs_anon1* _this) {
}

void sjf_anon1_nextframe(sjs_anon1* _parent, int32_t time) {
    int32_t sjt_compare123;
    int32_t sjt_compare124;
    sjs_anon1* sjt_dot1695;
    sjs_anon1* sjt_dot1698;
    bool sjt_ifElse59;
    sjs_list_heap_animation* sjt_parent238;

    sjt_dot1695 = _parent;
    sjt_dot1695->current = time;
    sjt_dot1698 = _parent;
    sjt_parent238 = &(sjt_dot1698)->animations;
    sjf_list_heap_animation_getcount(sjt_parent238, &sjt_compare123);
    sjt_compare124 = 0;
    sjt_ifElse59 = sjt_compare123 > sjt_compare124;
    if (sjt_ifElse59) {
        int32_t i;
        sjs_anon1* sjt_dot1699;
        int32_t sjt_forEnd28;
        int32_t sjt_forStart28;
        sjs_list_heap_animation* sjt_parent239;

        sjt_forStart28 = 0;
        sjt_dot1699 = _parent;
        sjt_parent239 = &(sjt_dot1699)->animations;
        sjf_list_heap_animation_getcount(sjt_parent239, &sjt_forEnd28);
        i = sjt_forStart28;
        while (i < sjt_forEnd28) {
            sjs_anon1* sjt_dot1700;
            sjs_anon1* sjt_dot1702;
            int32_t sjt_functionParam720;
            bool sjt_ifElse60;
            int32_t sjt_interfaceParam36;
            int32_t sjt_math2431;
            int32_t sjt_math2432;
            int32_t sjt_math2433;
            int32_t sjt_math2434;
            sjs_list_heap_animation* sjt_parent240;
            sjs_list_heap_animation* sjt_parent242;
            sji_animation* sjt_parent243;
            sji_animation* sjv_a = 0;
            int32_t sjv_index;

            sjt_dot1700 = _parent;
            sjt_parent240 = &(sjt_dot1700)->animations;
            sjf_list_heap_animation_getcount(sjt_parent240, &sjt_math2433);
            sjt_math2434 = 0;
            sjt_math2431 = sjt_math2433 - sjt_math2434;
            sjt_math2432 = 1;
            sjv_index = sjt_math2431 - sjt_math2432;
            sjt_dot1702 = _parent;
            sjt_parent242 = &(sjt_dot1702)->animations;
            sjt_functionParam720 = sjv_index;
            sjf_list_heap_animation_getat_heap(sjt_parent242, sjt_functionParam720, &sjv_a);
            sjt_parent243 = sjv_a;
            sjt_interfaceParam36 = time;
            sjt_parent243->nextframe(sjt_parent243->_parent, sjt_interfaceParam36, &sjt_ifElse60);
            if (sjt_ifElse60) {
                sjs_anon1* sjt_dot1703;
                int32_t sjt_functionParam721;
                sjs_list_heap_animation* sjt_parent244;

                sjt_dot1703 = _parent;
                sjt_parent244 = &(sjt_dot1703)->animations;
                sjt_functionParam721 = sjv_index;
                sjf_list_heap_animation_removeat(sjt_parent244, sjt_functionParam721);
            }

            i++;

            sjv_a->_refCount--;
            if (sjv_a->_refCount <= 0) {
                sji_animation_destroy(sjv_a);
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
            free((char*)_this->data);
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
    sjs_array_char* sjt_dot1336;
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
        memcpy(sjv_newdata, _parent->data, _parent->datasize * sizeof(char));
    }
    _return->_refCount = 1;
    _return->datasize = newsize;
    _return->data = sjv_newdata;
    _return->_isglobal = false;
    sjt_dot1336 = _parent;
    _return->count = (sjt_dot1336)->count;
    sjf_array_char(_return);
}

void sjf_array_char_grow_heap(sjs_array_char* _parent, int32_t newsize, sjs_array_char** _return) {
    sjs_array_char* sjt_dot1337;
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
        memcpy(sjv_newdata, _parent->data, _parent->datasize * sizeof(char));
    }
    (*_return) = (sjs_array_char*)malloc(sizeof(sjs_array_char));
    (*_return)->_refCount = 1;
    (*_return)->datasize = newsize;
    (*_return)->data = sjv_newdata;
    (*_return)->_isglobal = false;
    sjt_dot1337 = _parent;
    (*_return)->count = (sjt_dot1337)->count;
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

void sjf_array_char_setat(sjs_array_char* _parent, int32_t index, char item) {
    if (index >= _parent->count || index < 0) {
        halt("setAt: out of bounds %d:%d\n", index, _parent->count);
    }
    char* p = (char*)_parent->data;
    ;
    p[index] = item;
;
}

void sjf_array_heap_animation(sjs_array_heap_animation* _this) {
    if (_this->datasize < 0) {
        halt("size is less than zero");
    }
    if (!_this->data) {
        _this->data = malloc(_this->datasize * sizeof(sji_animation*));
        if (!_this->data) {
            halt("grow: out of memory\n");
        }
    }
}

void sjf_array_heap_animation_copy(sjs_array_heap_animation* _this, sjs_array_heap_animation* _from) {
    _this->datasize = _from->datasize;
    _this->data = _from->data;
    _this->_isglobal = _from->_isglobal;
    _this->count = _from->count;
    _this->data = _from->data;
    if (!_this->_isglobal && _this->data) {
        ptr_retain(_this->data);
    }
}

void sjf_array_heap_animation_destroy(sjs_array_heap_animation* _this) {
    if (!_this->_isglobal && _this->data) {
        if (ptr_release(_this->data)) {
            free((sji_animation**)_this->data);
        }
    }
}

void sjf_array_heap_animation_getat_heap(sjs_array_heap_animation* _parent, int32_t index, sji_animation** _return) {
    if (index >= _parent->count || index < 0) {
        halt("getAt: out of bounds\n");
    }
    sji_animation** p = (sji_animation**)_parent->data;
    (*_return) = p[index];
(*_return)->_refCount++;
return;;		
}

void sjf_array_heap_animation_heap(sjs_array_heap_animation* _this) {
    if (_this->datasize < 0) {
        halt("size is less than zero");
    }
    if (!_this->data) {
        _this->data = malloc(_this->datasize * sizeof(sji_animation*));
        if (!_this->data) {
            halt("grow: out of memory\n");
        }
    }
}

void sjf_array_heap_element(sjs_array_heap_element* _this) {
    if (_this->datasize < 0) {
        halt("size is less than zero");
    }
    if (!_this->data) {
        _this->data = malloc(_this->datasize * sizeof(sji_element*));
        if (!_this->data) {
            halt("grow: out of memory\n");
        }
    }
}

void sjf_array_heap_element_copy(sjs_array_heap_element* _this, sjs_array_heap_element* _from) {
    _this->datasize = _from->datasize;
    _this->data = _from->data;
    _this->_isglobal = _from->_isglobal;
    _this->count = _from->count;
    _this->data = _from->data;
    if (!_this->_isglobal && _this->data) {
        ptr_retain(_this->data);
    }
}

void sjf_array_heap_element_destroy(sjs_array_heap_element* _this) {
    if (!_this->_isglobal && _this->data) {
        if (ptr_release(_this->data)) {
            free((sji_element**)_this->data);
        }
    }
}

void sjf_array_heap_element_getat_heap(sjs_array_heap_element* _parent, int32_t index, sji_element** _return) {
    if (index >= _parent->count || index < 0) {
        halt("getAt: out of bounds\n");
    }
    sji_element** p = (sji_element**)_parent->data;
    (*_return) = p[index];
(*_return)->_refCount++;
return;;		
}

void sjf_array_heap_element_heap(sjs_array_heap_element* _this) {
    if (_this->datasize < 0) {
        halt("size is less than zero");
    }
    if (!_this->data) {
        _this->data = malloc(_this->datasize * sizeof(sji_element*));
        if (!_this->data) {
            halt("grow: out of memory\n");
        }
    }
}

void sjf_array_heap_element_initat(sjs_array_heap_element* _parent, int32_t index, sji_element* item) {
    if (index != _parent->count) {
        halt("initAt: can only initialize last element\n");		
    }
    if (index >= _parent->datasize || index < 0) {
        halt("initAt: out of bounds %d:%d\n", index, _parent->datasize);
    }
    sji_element** p = (sji_element**)_parent->data;
    p[index] = item;
p[index]->_refCount++;
;
    _parent->count = index + 1;
}

void sjf_array_heap_model(sjs_array_heap_model* _this) {
    if (_this->datasize < 0) {
        halt("size is less than zero");
    }
    if (!_this->data) {
        _this->data = malloc(_this->datasize * sizeof(sji_model*));
        if (!_this->data) {
            halt("grow: out of memory\n");
        }
    }
}

void sjf_array_heap_model__quicksortcallback(sjs_array_heap_model* _parent, int32_t left, int32_t right, cb_heap_model_heap_model_i32 cb) {
    int32_t sjt_compare11;
    int32_t sjt_compare12;
    int32_t sjt_compare25;
    int32_t sjt_compare26;
    int32_t sjt_compare27;
    int32_t sjt_compare28;
    int32_t sjt_functionParam16;
    bool sjt_ifElse4;
    bool sjt_ifElse5;
    int32_t sjt_math45;
    int32_t sjt_math46;
    int32_t sjt_math47;
    int32_t sjt_math48;
    bool sjt_while1;
    int32_t sjv_i;
    int32_t sjv_j;
    sji_model* sjv_pivot = 0;

    sjv_i = left;
    sjv_j = right;
    sjt_math47 = left;
    sjt_math48 = right;
    sjt_math45 = sjt_math47 + sjt_math48;
    sjt_math46 = 2;
    sjt_functionParam16 = sjt_math45 / sjt_math46;
    sjf_array_heap_model_getat_heap(_parent, sjt_functionParam16, &sjv_pivot);
    sjt_compare11 = sjv_i;
    sjt_compare12 = sjv_j;
    sjt_while1 = sjt_compare11 <= sjt_compare12;
    while (sjt_while1) {
        cb_heap_model_heap_model_i32 sjt_callback1;
        cb_heap_model_heap_model_i32 sjt_callback3;
        int32_t sjt_compare13;
        int32_t sjt_compare14;
        int32_t sjt_compare17;
        int32_t sjt_compare18;
        int32_t sjt_compare21;
        int32_t sjt_compare22;
        int32_t sjt_compare23;
        int32_t sjt_compare24;
        sji_model* sjt_functionParam17 = 0;
        int32_t sjt_functionParam18;
        sji_model* sjt_functionParam19 = 0;
        sji_model* sjt_functionParam23 = 0;
        int32_t sjt_functionParam24;
        sji_model* sjt_functionParam25 = 0;
        bool sjt_ifElse3;
        bool sjt_while2;
        bool sjt_while3;

        sjt_callback1 = cb;
        sjt_functionParam18 = sjv_i;
        sjf_array_heap_model_getat_heap(_parent, sjt_functionParam18, &sjt_functionParam17);
        sjt_functionParam19 = sjv_pivot;
        sjt_functionParam19->_refCount++;
        sjt_callback1._cb(sjt_callback1._parent, sjt_functionParam17, sjt_functionParam19, &sjt_compare13);
        sjt_compare14 = 0;
        sjt_while2 = sjt_compare13 < sjt_compare14;
        while (sjt_while2) {
            cb_heap_model_heap_model_i32 sjt_callback2;
            int32_t sjt_compare15;
            int32_t sjt_compare16;
            sji_model* sjt_functionParam20 = 0;
            int32_t sjt_functionParam21;
            sji_model* sjt_functionParam22 = 0;
            int32_t sjt_math49;
            int32_t sjt_math50;

            sjt_math49 = sjv_i;
            sjt_math50 = 1;
            sjv_i = sjt_math49 + sjt_math50;
            sjt_callback2 = cb;
            sjt_functionParam21 = sjv_i;
            sjf_array_heap_model_getat_heap(_parent, sjt_functionParam21, &sjt_functionParam20);
            sjt_functionParam22 = sjv_pivot;
            sjt_functionParam22->_refCount++;
            sjt_callback2._cb(sjt_callback2._parent, sjt_functionParam20, sjt_functionParam22, &sjt_compare15);
            sjt_compare16 = 0;
            sjt_while2 = sjt_compare15 < sjt_compare16;

            sjt_functionParam20->_refCount--;
            if (sjt_functionParam20->_refCount <= 0) {
                sji_model_destroy(sjt_functionParam20);
            }
            sjt_functionParam22->_refCount--;
            if (sjt_functionParam22->_refCount <= 0) {
                sji_model_destroy(sjt_functionParam22);
            }
        }

        sjt_callback3 = cb;
        sjt_functionParam24 = sjv_j;
        sjf_array_heap_model_getat_heap(_parent, sjt_functionParam24, &sjt_functionParam23);
        sjt_functionParam25 = sjv_pivot;
        sjt_functionParam25->_refCount++;
        sjt_callback3._cb(sjt_callback3._parent, sjt_functionParam23, sjt_functionParam25, &sjt_compare17);
        sjt_compare18 = 0;
        sjt_while3 = sjt_compare17 > sjt_compare18;
        while (sjt_while3) {
            cb_heap_model_heap_model_i32 sjt_callback4;
            int32_t sjt_compare19;
            int32_t sjt_compare20;
            sji_model* sjt_functionParam26 = 0;
            int32_t sjt_functionParam27;
            sji_model* sjt_functionParam28 = 0;
            int32_t sjt_math51;
            int32_t sjt_math52;

            sjt_math51 = sjv_j;
            sjt_math52 = 1;
            sjv_j = sjt_math51 - sjt_math52;
            sjt_callback4 = cb;
            sjt_functionParam27 = sjv_j;
            sjf_array_heap_model_getat_heap(_parent, sjt_functionParam27, &sjt_functionParam26);
            sjt_functionParam28 = sjv_pivot;
            sjt_functionParam28->_refCount++;
            sjt_callback4._cb(sjt_callback4._parent, sjt_functionParam26, sjt_functionParam28, &sjt_compare19);
            sjt_compare20 = 0;
            sjt_while3 = sjt_compare19 > sjt_compare20;

            sjt_functionParam26->_refCount--;
            if (sjt_functionParam26->_refCount <= 0) {
                sji_model_destroy(sjt_functionParam26);
            }
            sjt_functionParam28->_refCount--;
            if (sjt_functionParam28->_refCount <= 0) {
                sji_model_destroy(sjt_functionParam28);
            }
        }

        sjt_compare21 = sjv_i;
        sjt_compare22 = sjv_j;
        sjt_ifElse3 = sjt_compare21 <= sjt_compare22;
        if (sjt_ifElse3) {
            int32_t sjt_functionParam29;
            int32_t sjt_functionParam30;
            sji_model* sjt_functionParam31 = 0;
            int32_t sjt_functionParam32;
            int32_t sjt_functionParam33;
            sji_model* sjt_functionParam34 = 0;
            int32_t sjt_math53;
            int32_t sjt_math54;
            int32_t sjt_math55;
            int32_t sjt_math56;
            sji_model* sjv_tmp = 0;

            sjt_functionParam29 = sjv_i;
            sjf_array_heap_model_getat_heap(_parent, sjt_functionParam29, &sjv_tmp);
            sjt_functionParam30 = sjv_i;
            sjt_functionParam32 = sjv_j;
            sjf_array_heap_model_getat_heap(_parent, sjt_functionParam32, &sjt_functionParam31);
            sjf_array_heap_model_setat(_parent, sjt_functionParam30, sjt_functionParam31);
            sjt_functionParam33 = sjv_j;
            sjt_functionParam34 = sjv_tmp;
            sjt_functionParam34->_refCount++;
            sjf_array_heap_model_setat(_parent, sjt_functionParam33, sjt_functionParam34);
            sjt_math53 = sjv_i;
            sjt_math54 = 1;
            sjv_i = sjt_math53 + sjt_math54;
            sjt_math55 = sjv_j;
            sjt_math56 = 1;
            sjv_j = sjt_math55 - sjt_math56;

            sjt_functionParam31->_refCount--;
            if (sjt_functionParam31->_refCount <= 0) {
                sji_model_destroy(sjt_functionParam31);
            }
            sjt_functionParam34->_refCount--;
            if (sjt_functionParam34->_refCount <= 0) {
                sji_model_destroy(sjt_functionParam34);
            }
            sjv_tmp->_refCount--;
            if (sjv_tmp->_refCount <= 0) {
                sji_model_destroy(sjv_tmp);
            }
        }

        sjt_compare23 = sjv_i;
        sjt_compare24 = sjv_j;
        sjt_while1 = sjt_compare23 <= sjt_compare24;

        sjt_functionParam17->_refCount--;
        if (sjt_functionParam17->_refCount <= 0) {
            sji_model_destroy(sjt_functionParam17);
        }
        sjt_functionParam19->_refCount--;
        if (sjt_functionParam19->_refCount <= 0) {
            sji_model_destroy(sjt_functionParam19);
        }
        sjt_functionParam23->_refCount--;
        if (sjt_functionParam23->_refCount <= 0) {
            sji_model_destroy(sjt_functionParam23);
        }
        sjt_functionParam25->_refCount--;
        if (sjt_functionParam25->_refCount <= 0) {
            sji_model_destroy(sjt_functionParam25);
        }
    }

    sjt_compare25 = left;
    sjt_compare26 = sjv_j;
    sjt_ifElse4 = sjt_compare25 < sjt_compare26;
    if (sjt_ifElse4) {
        int32_t sjt_functionParam35;
        int32_t sjt_functionParam36;
        cb_heap_model_heap_model_i32 sjt_functionParam37;

        sjt_functionParam35 = left;
        sjt_functionParam36 = sjv_j;
        sjt_functionParam37 = cb;
        sjf_array_heap_model__quicksortcallback(_parent, sjt_functionParam35, sjt_functionParam36, sjt_functionParam37);
    }

    sjt_compare27 = sjv_i;
    sjt_compare28 = right;
    sjt_ifElse5 = sjt_compare27 < sjt_compare28;
    if (sjt_ifElse5) {
        int32_t sjt_functionParam38;
        int32_t sjt_functionParam39;
        cb_heap_model_heap_model_i32 sjt_functionParam40;

        sjt_functionParam38 = sjv_i;
        sjt_functionParam39 = right;
        sjt_functionParam40 = cb;
        sjf_array_heap_model__quicksortcallback(_parent, sjt_functionParam38, sjt_functionParam39, sjt_functionParam40);
    }

    sjv_pivot->_refCount--;
    if (sjv_pivot->_refCount <= 0) {
        sji_model_destroy(sjv_pivot);
    }
}

void sjf_array_heap_model_copy(sjs_array_heap_model* _this, sjs_array_heap_model* _from) {
    _this->datasize = _from->datasize;
    _this->data = _from->data;
    _this->_isglobal = _from->_isglobal;
    _this->count = _from->count;
    _this->data = _from->data;
    if (!_this->_isglobal && _this->data) {
        ptr_retain(_this->data);
    }
}

void sjf_array_heap_model_destroy(sjs_array_heap_model* _this) {
    if (!_this->_isglobal && _this->data) {
        if (ptr_release(_this->data)) {
            free((sji_model**)_this->data);
        }
    }
}

void sjf_array_heap_model_getat_heap(sjs_array_heap_model* _parent, int32_t index, sji_model** _return) {
    if (index >= _parent->count || index < 0) {
        halt("getAt: out of bounds\n");
    }
    sji_model** p = (sji_model**)_parent->data;
    (*_return) = p[index];
(*_return)->_refCount++;
return;;		
}

void sjf_array_heap_model_grow(sjs_array_heap_model* _parent, int32_t newsize, sjs_array_heap_model* _return) {
    sjs_array_heap_model* sjt_dot550;
    void* sjv_newdata;

    sjv_newdata = 0;
    if (_parent->datasize != newsize) {
        if (newsize < _parent->datasize) {
            halt("grow: new size smaller than old _parent->datasize %d:%d\n", newsize, _parent->datasize);
        }
        sjv_newdata = malloc(newsize * sizeof(sji_model*));
        if (!_parent->data) {
            halt("grow: out of memory\n");
        }
        memcpy(sjv_newdata, _parent->data, _parent->datasize * sizeof(sji_model*));
    }
    _return->_refCount = 1;
    _return->datasize = newsize;
    _return->data = sjv_newdata;
    _return->_isglobal = false;
    sjt_dot550 = _parent;
    _return->count = (sjt_dot550)->count;
    sjf_array_heap_model(_return);
}

void sjf_array_heap_model_grow_heap(sjs_array_heap_model* _parent, int32_t newsize, sjs_array_heap_model** _return) {
    sjs_array_heap_model* sjt_dot551;
    void* sjv_newdata;

    sjv_newdata = 0;
    if (_parent->datasize != newsize) {
        if (newsize < _parent->datasize) {
            halt("grow: new size smaller than old _parent->datasize %d:%d\n", newsize, _parent->datasize);
        }
        sjv_newdata = malloc(newsize * sizeof(sji_model*));
        if (!_parent->data) {
            halt("grow: out of memory\n");
        }
        memcpy(sjv_newdata, _parent->data, _parent->datasize * sizeof(sji_model*));
    }
    (*_return) = (sjs_array_heap_model*)malloc(sizeof(sjs_array_heap_model));
    (*_return)->_refCount = 1;
    (*_return)->datasize = newsize;
    (*_return)->data = sjv_newdata;
    (*_return)->_isglobal = false;
    sjt_dot551 = _parent;
    (*_return)->count = (sjt_dot551)->count;
    sjf_array_heap_model_heap((*_return));
}

void sjf_array_heap_model_heap(sjs_array_heap_model* _this) {
    if (_this->datasize < 0) {
        halt("size is less than zero");
    }
    if (!_this->data) {
        _this->data = malloc(_this->datasize * sizeof(sji_model*));
        if (!_this->data) {
            halt("grow: out of memory\n");
        }
    }
}

void sjf_array_heap_model_initat(sjs_array_heap_model* _parent, int32_t index, sji_model* item) {
    if (index != _parent->count) {
        halt("initAt: can only initialize last element\n");		
    }
    if (index >= _parent->datasize || index < 0) {
        halt("initAt: out of bounds %d:%d\n", index, _parent->datasize);
    }
    sji_model** p = (sji_model**)_parent->data;
    p[index] = item;
p[index]->_refCount++;
;
    _parent->count = index + 1;
}

void sjf_array_heap_model_map_mat4(sjs_array_heap_model* _parent, cb_heap_model_mat4 cb, sjs_array_mat4* _return) {
    int32_t i;
    sjs_array_heap_model* sjt_dot1363;
    sjs_array_heap_model* sjt_dot1364;
    sjs_array_heap_model* sjt_dot1365;
    int32_t sjt_forEnd15;
    int32_t sjt_forStart15;
    void* sjv_newdata;

    sjv_newdata = 0;
    sjv_newdata = malloc(_parent->count * sizeof(sjs_mat4));
    sjt_forStart15 = 0;
    sjt_dot1363 = _parent;
    sjt_forEnd15 = (sjt_dot1363)->count;
    i = sjt_forStart15;
    while (i < sjt_forEnd15) {
        cb_heap_model_mat4 sjt_callback7;
        sji_model* sjt_functionParam280 = 0;
        int32_t sjt_functionParam281;
        sjs_mat4 sjv_newitem = { -1 };

        sjt_callback7 = cb;
        sjt_functionParam281 = i;
        sjf_array_heap_model_getat_heap(_parent, sjt_functionParam281, &sjt_functionParam280);
        sjt_callback7._cb(sjt_callback7._parent, sjt_functionParam280, &sjv_newitem);
        sjs_mat4* p = (sjs_mat4*)sjv_newdata;
        p[i]._refCount = 1;
sjf_mat4_copy(&p[i], &sjv_newitem);
;
        i++;

        sjt_functionParam280->_refCount--;
        if (sjt_functionParam280->_refCount <= 0) {
            sji_model_destroy(sjt_functionParam280);
        }
        if (sjv_newitem._refCount == 1) { sjf_mat4_destroy(&sjv_newitem); }
    }

    _return->_refCount = 1;
    sjt_dot1364 = _parent;
    _return->datasize = (sjt_dot1364)->count;
    _return->data = sjv_newdata;
    _return->_isglobal = false;
    sjt_dot1365 = _parent;
    _return->count = (sjt_dot1365)->count;
    sjf_array_mat4(_return);
}

void sjf_array_heap_model_map_mat4_heap(sjs_array_heap_model* _parent, cb_heap_model_mat4 cb, sjs_array_mat4** _return) {
    int32_t i;
    sjs_array_heap_model* sjt_dot1366;
    sjs_array_heap_model* sjt_dot1367;
    sjs_array_heap_model* sjt_dot1368;
    int32_t sjt_forEnd16;
    int32_t sjt_forStart16;
    void* sjv_newdata;

    sjv_newdata = 0;
    sjv_newdata = malloc(_parent->count * sizeof(sjs_mat4));
    sjt_forStart16 = 0;
    sjt_dot1366 = _parent;
    sjt_forEnd16 = (sjt_dot1366)->count;
    i = sjt_forStart16;
    while (i < sjt_forEnd16) {
        cb_heap_model_mat4 sjt_callback8;
        sji_model* sjt_functionParam282 = 0;
        int32_t sjt_functionParam283;
        sjs_mat4 sjv_newitem = { -1 };

        sjt_callback8 = cb;
        sjt_functionParam283 = i;
        sjf_array_heap_model_getat_heap(_parent, sjt_functionParam283, &sjt_functionParam282);
        sjt_callback8._cb(sjt_callback8._parent, sjt_functionParam282, &sjv_newitem);
        sjs_mat4* p = (sjs_mat4*)sjv_newdata;
        p[i]._refCount = 1;
sjf_mat4_copy(&p[i], &sjv_newitem);
;
        i++;

        sjt_functionParam282->_refCount--;
        if (sjt_functionParam282->_refCount <= 0) {
            sji_model_destroy(sjt_functionParam282);
        }
        if (sjv_newitem._refCount == 1) { sjf_mat4_destroy(&sjv_newitem); }
    }

    (*_return) = (sjs_array_mat4*)malloc(sizeof(sjs_array_mat4));
    (*_return)->_refCount = 1;
    sjt_dot1367 = _parent;
    (*_return)->datasize = (sjt_dot1367)->count;
    (*_return)->data = sjv_newdata;
    (*_return)->_isglobal = false;
    sjt_dot1368 = _parent;
    (*_return)->count = (sjt_dot1368)->count;
    sjf_array_mat4_heap((*_return));
}

void sjf_array_heap_model_setat(sjs_array_heap_model* _parent, int32_t index, sji_model* item) {
    if (index >= _parent->count || index < 0) {
        halt("setAt: out of bounds %d:%d\n", index, _parent->count);
    }
    sji_model** p = (sji_model**)_parent->data;
    p[index]->_refCount--;
if (p[index]->_refCount <= 0) {
    sji_model_destroy(p[index]);
}
;
    p[index] = item;
p[index]->_refCount++;
;
}

void sjf_array_heap_model_sortcb(sjs_array_heap_model* _parent, cb_heap_model_heap_model_i32 cb) {
    int32_t sjt_compare10;
    int32_t sjt_compare9;
    sjs_array_heap_model* sjt_dot51;
    bool sjt_ifElse2;

    sjt_dot51 = _parent;
    sjt_compare9 = (sjt_dot51)->count;
    sjt_compare10 = 1;
    sjt_ifElse2 = sjt_compare9 > sjt_compare10;
    if (sjt_ifElse2) {
        sjs_array_heap_model* sjt_dot52;
        int32_t sjt_functionParam41;
        int32_t sjt_functionParam42;
        cb_heap_model_heap_model_i32 sjt_functionParam43;
        int32_t sjt_math57;
        int32_t sjt_math58;

        sjt_functionParam41 = 0;
        sjt_dot52 = _parent;
        sjt_math57 = (sjt_dot52)->count;
        sjt_math58 = 1;
        sjt_functionParam42 = sjt_math57 - sjt_math58;
        sjt_functionParam43 = cb;
        sjf_array_heap_model__quicksortcallback(_parent, sjt_functionParam41, sjt_functionParam42, sjt_functionParam43);
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
            free((int32_t*)_this->data);
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
            free((sjs_mat4*)_this->data);
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
            free((sjs_texture*)_this->data);
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

void sjf_array_texture_map_heap_model(sjs_array_texture* _parent, cb_texture_heap_model cb, sjs_array_heap_model* _return) {
    int32_t i;
    sjs_array_texture* sjt_dot1323;
    sjs_array_texture* sjt_dot1324;
    sjs_array_texture* sjt_dot1325;
    int32_t sjt_forEnd8;
    int32_t sjt_forStart8;
    void* sjv_newdata;

    sjv_newdata = 0;
    sjv_newdata = malloc(_parent->count * sizeof(sji_model*));
    sjt_forStart8 = 0;
    sjt_dot1323 = _parent;
    sjt_forEnd8 = (sjt_dot1323)->count;
    i = sjt_forStart8;
    while (i < sjt_forEnd8) {
        sjs_texture sjt_call33 = { -1 };
        cb_texture_heap_model sjt_callback5;
        sjs_texture* sjt_functionParam210;
        int32_t sjt_functionParam211;
        sji_model* sjv_newitem = 0;

        sjt_callback5 = cb;
        sjt_functionParam211 = i;
        sjf_array_texture_getat(_parent, sjt_functionParam211, &sjt_call33);
        sjt_functionParam210 = &sjt_call33;
        sjt_callback5._cb_heap(sjt_callback5._parent, sjt_functionParam210, &sjv_newitem);
        sji_model** p = (sji_model**)sjv_newdata;
        p[i] = sjv_newitem;
p[i]->_refCount++;
;
        i++;

        sjv_newitem->_refCount--;
        if (sjv_newitem->_refCount <= 0) {
            sji_model_destroy(sjv_newitem);
        }
        if (sjt_call33._refCount == 1) { sjf_texture_destroy(&sjt_call33); }
    }

    _return->_refCount = 1;
    sjt_dot1324 = _parent;
    _return->datasize = (sjt_dot1324)->count;
    _return->data = sjv_newdata;
    _return->_isglobal = false;
    sjt_dot1325 = _parent;
    _return->count = (sjt_dot1325)->count;
    sjf_array_heap_model(_return);
}

void sjf_array_texture_map_heap_model_heap(sjs_array_texture* _parent, cb_texture_heap_model cb, sjs_array_heap_model** _return) {
    int32_t i;
    sjs_array_texture* sjt_dot1326;
    sjs_array_texture* sjt_dot1327;
    sjs_array_texture* sjt_dot1328;
    int32_t sjt_forEnd9;
    int32_t sjt_forStart9;
    void* sjv_newdata;

    sjv_newdata = 0;
    sjv_newdata = malloc(_parent->count * sizeof(sji_model*));
    sjt_forStart9 = 0;
    sjt_dot1326 = _parent;
    sjt_forEnd9 = (sjt_dot1326)->count;
    i = sjt_forStart9;
    while (i < sjt_forEnd9) {
        sjs_texture sjt_call34 = { -1 };
        cb_texture_heap_model sjt_callback6;
        sjs_texture* sjt_functionParam212;
        int32_t sjt_functionParam213;
        sji_model* sjv_newitem = 0;

        sjt_callback6 = cb;
        sjt_functionParam213 = i;
        sjf_array_texture_getat(_parent, sjt_functionParam213, &sjt_call34);
        sjt_functionParam212 = &sjt_call34;
        sjt_callback6._cb_heap(sjt_callback6._parent, sjt_functionParam212, &sjv_newitem);
        sji_model** p = (sji_model**)sjv_newdata;
        p[i] = sjv_newitem;
p[i]->_refCount++;
;
        i++;

        sjv_newitem->_refCount--;
        if (sjv_newitem->_refCount <= 0) {
            sji_model_destroy(sjv_newitem);
        }
        if (sjt_call34._refCount == 1) { sjf_texture_destroy(&sjt_call34); }
    }

    (*_return) = (sjs_array_heap_model*)malloc(sizeof(sjs_array_heap_model));
    (*_return)->_refCount = 1;
    sjt_dot1327 = _parent;
    (*_return)->datasize = (sjt_dot1327)->count;
    (*_return)->data = sjv_newdata;
    (*_return)->_isglobal = false;
    sjt_dot1328 = _parent;
    (*_return)->count = (sjt_dot1328)->count;
    sjf_array_heap_model_heap((*_return));
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
            free((sjs_vertex_location_texture_normal*)_this->data);
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

sjs_object* sjf_boxelement_asInterface(sjs_boxelement* _this, int typeId) {
    switch (typeId) {
        case sji_element_typeId:  {
            return (sjs_object*)sjf_boxelement_as_sji_element(_this);
        }
    }

    return 0;
}

sji_element* sjf_boxelement_as_sji_element(sjs_boxelement* _this) {
    sji_element* _interface;
    _interface = (sji_element*)malloc(sizeof(sji_element));
    _interface->_refCount = 1;
    _interface->_parent = (sjs_object*)_this;
    _interface->_parent->_refCount++;
    _interface->destroy = (void(*)(void*))sjf_boxelement_destroy;
    _interface->asInterface = (sjs_object*(*)(sjs_object*,int))sjf_boxelement_asInterface;
    _interface->getsize = (void(*)(void*,sjs_size*, sjs_size*))sjf_boxelement_getsize;
    _interface->getsize_heap = (void(*)(void*,sjs_size*, sjs_size**))sjf_boxelement_getsize_heap;
    _interface->getrect = (void(*)(void*, sjs_rect**))sjf_boxelement_getrect;
    _interface->setrect = (void(*)(void*,sjs_rect*))sjf_boxelement_setrect;
    _interface->render = (void(*)(void*,sjs_scene2d*))sjf_boxelement_render;
    _interface->firemouseevent = (void(*)(void*,sjs_mouseevent*))sjf_boxelement_firemouseevent;

    return _interface;
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

void sjf_boxelement_getrect(sjs_boxelement* _parent, sjs_rect** _return) {
    sjs_boxelement* sjt_dot1576;

    sjt_dot1576 = _parent;
    (*_return) = &(sjt_dot1576)->rect;
}

void sjf_boxelement_getsize(sjs_boxelement* _parent, sjs_size* maxsize, sjs_size* _return) {
    sjs_boxelement* sjt_dot1574;
    sjs_size* sjt_functionParam481;
    sjs_size* sjt_parent185;

    sjt_dot1574 = _parent;
    sjt_parent185 = &(sjt_dot1574)->idealsize;
    sjt_functionParam481 = maxsize;
    sjf_size_cap(sjt_parent185, sjt_functionParam481, _return);
}

void sjf_boxelement_getsize_heap(sjs_boxelement* _parent, sjs_size* maxsize, sjs_size** _return) {
    sjs_boxelement* sjt_dot1575;
    sjs_size* sjt_functionParam482;
    sjs_size* sjt_parent186;

    sjt_dot1575 = _parent;
    sjt_parent186 = &(sjt_dot1575)->idealsize;
    sjt_functionParam482 = maxsize;
    sjf_size_cap_heap(sjt_parent186, sjt_functionParam482, _return);
}

void sjf_boxelement_heap(sjs_boxelement* _this) {
}

sjs_object* sjf_boxelement_heap_asInterface(sjs_boxelement* _this, int typeId) {
    switch (typeId) {
        case sji_element_typeId:  {
            return (sjs_object*)sjf_boxelement_heap_as_sji_element(_this);
        }
    }

    return 0;
}

sji_element* sjf_boxelement_heap_as_sji_element(sjs_boxelement* _this) {
    sji_element* _interface;
    _interface = (sji_element*)malloc(sizeof(sji_element));
    _interface->_refCount = 1;
    _interface->_parent = (sjs_object*)_this;
    _interface->_parent->_refCount++;
    _interface->destroy = (void(*)(void*))sjf_boxelement_destroy;
    _interface->asInterface = (sjs_object*(*)(sjs_object*,int))sjf_boxelement_heap_asInterface;
    _interface->getsize = (void(*)(void*,sjs_size*, sjs_size*))sjf_boxelement_getsize;
    _interface->getsize_heap = (void(*)(void*,sjs_size*, sjs_size**))sjf_boxelement_getsize_heap;
    _interface->getrect = (void(*)(void*, sjs_rect**))sjf_boxelement_getrect;
    _interface->setrect = (void(*)(void*,sjs_rect*))sjf_boxelement_setrect;
    _interface->render = (void(*)(void*,sjs_scene2d*))sjf_boxelement_render;
    _interface->firemouseevent = (void(*)(void*,sjs_mouseevent*))sjf_boxelement_firemouseevent;

    return _interface;
}

void sjf_boxelement_render(sjs_boxelement* _parent, sjs_scene2d* scene) {
    bool result27;
    sjs_boxelement* sjt_dot1580;
    sjs_boxelement* sjt_dot1584;
    bool sjt_ifElse45;
    bool sjt_ifElse46;
    sjs_boxrenderer* sjt_isEmpty12;
    sjs_boxrenderer* sjt_isEmpty13;
    bool sjt_not5;

    sjt_dot1580 = _parent;
    sjt_isEmpty12 = ((sjt_dot1580)->boxrenderer._refCount != -1 ? &(sjt_dot1580)->boxrenderer : 0);
    sjt_ifElse45 = (sjt_isEmpty12 == 0);
    if (sjt_ifElse45) {
        sjs_rect* sjt_copy35;
        sjs_color* sjt_copy36;
        sjs_boxelement* sjt_dot1581;
        sjs_boxelement* sjt_dot1582;
        sjs_boxelement* sjt_dot1583;

        sjt_dot1581 = _parent;
        sjt_dot1581->boxrenderer._refCount = 1;
        sjt_dot1582 = _parent;
        sjt_copy35 = &(sjt_dot1582)->rect;
        sjt_dot1581->boxrenderer.rect._refCount = 1;
        sjf_rect_copy(&sjt_dot1581->boxrenderer.rect, sjt_copy35);
        sjt_dot1583 = _parent;
        sjt_copy36 = &(sjt_dot1583)->color;
        sjt_dot1581->boxrenderer.color._refCount = 1;
        sjf_color_copy(&sjt_dot1581->boxrenderer.color, sjt_copy36);
        sjf_boxrenderer(&sjt_dot1581->boxrenderer);
    }

    sjt_dot1584 = _parent;
    sjt_isEmpty13 = ((sjt_dot1584)->boxrenderer._refCount != -1 ? &(sjt_dot1584)->boxrenderer : 0);
    sjt_not5 = (sjt_isEmpty13 == 0);
    result27 = !sjt_not5;
    sjt_ifElse46 = result27;
    if (sjt_ifElse46) {
        sjs_boxelement* sjt_dot1585;
        sjs_scene2d* sjt_functionParam484;
        sjs_boxrenderer* sjt_parent188;

        sjt_dot1585 = _parent;
        sjt_parent188 = ((sjt_dot1585)->boxrenderer._refCount != -1 ? &(sjt_dot1585)->boxrenderer : 0);
        sjt_functionParam484 = scene;
        sjf_boxrenderer_render(sjt_parent188, sjt_functionParam484);
    }
}

void sjf_boxelement_setrect(sjs_boxelement* _parent, sjs_rect* rect_) {
    bool result26;
    sjs_boxelement* sjt_dot1577;
    sjs_rect* sjt_functionParam483;
    bool sjt_ifElse44;
    bool sjt_not4;
    sjs_rect* sjt_parent187;

    sjt_dot1577 = _parent;
    sjt_parent187 = &(sjt_dot1577)->rect;
    sjt_functionParam483 = rect_;
    sjf_rect_isequal(sjt_parent187, sjt_functionParam483, &sjt_not4);
    result26 = !sjt_not4;
    sjt_ifElse44 = result26;
    if (sjt_ifElse44) {
        sjs_rect* sjt_copy34;
        sjs_boxelement* sjt_dot1578;
        sjs_boxelement* sjt_dot1579;

        sjt_dot1578 = _parent;
        sjt_copy34 = rect_;
        sjf_rect_copy(&sjt_dot1578->rect, sjt_copy34);
        sjt_dot1579 = _parent;
        sjt_dot1579->boxrenderer._refCount = -1;
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
    sjs_color* sjt_dot1307;
    sjs_color* sjt_dot1308;
    sjs_color* sjt_dot1309;

    _return->_refCount = 1;
    sjt_dot1307 = _parent;
    _return->x = (sjt_dot1307)->r;
    sjt_dot1308 = _parent;
    _return->y = (sjt_dot1308)->g;
    sjt_dot1309 = _parent;
    _return->z = (sjt_dot1309)->b;
    sjf_vec3(_return);
}

void sjf_color_asvec3_heap(sjs_color* _parent, sjs_vec3** _return) {
    sjs_color* sjt_dot1310;
    sjs_color* sjt_dot1311;
    sjs_color* sjt_dot1312;

    (*_return) = (sjs_vec3*)malloc(sizeof(sjs_vec3));
    (*_return)->_refCount = 1;
    sjt_dot1310 = _parent;
    (*_return)->x = (sjt_dot1310)->r;
    sjt_dot1311 = _parent;
    (*_return)->y = (sjt_dot1311)->g;
    sjt_dot1312 = _parent;
    (*_return)->z = (sjt_dot1312)->b;
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

sjs_object* sjf_crosshairselement_asInterface(sjs_crosshairselement* _this, int typeId) {
    switch (typeId) {
        case sji_element_typeId:  {
            return (sjs_object*)sjf_crosshairselement_as_sji_element(_this);
        }
    }

    return 0;
}

sji_element* sjf_crosshairselement_as_sji_element(sjs_crosshairselement* _this) {
    sji_element* _interface;
    _interface = (sji_element*)malloc(sizeof(sji_element));
    _interface->_refCount = 1;
    _interface->_parent = (sjs_object*)_this;
    _interface->_parent->_refCount++;
    _interface->destroy = (void(*)(void*))sjf_crosshairselement_destroy;
    _interface->asInterface = (sjs_object*(*)(sjs_object*,int))sjf_crosshairselement_asInterface;
    _interface->getsize = (void(*)(void*,sjs_size*, sjs_size*))sjf_crosshairselement_getsize;
    _interface->getsize_heap = (void(*)(void*,sjs_size*, sjs_size**))sjf_crosshairselement_getsize_heap;
    _interface->getrect = (void(*)(void*, sjs_rect**))sjf_crosshairselement_getrect;
    _interface->setrect = (void(*)(void*,sjs_rect*))sjf_crosshairselement_setrect;
    _interface->render = (void(*)(void*,sjs_scene2d*))sjf_crosshairselement_render;
    _interface->firemouseevent = (void(*)(void*,sjs_mouseevent*))sjf_crosshairselement_firemouseevent;

    return _interface;
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
    sjs_crosshairselement* sjt_dot1678;
    sjs_mouseevent* sjt_dot1679;
    sjs_point* sjt_functionParam496;
    bool sjt_ifElse57;
    sjs_rect* sjt_parent200;

    sjt_dot1678 = _parent;
    sjt_parent200 = &(sjt_dot1678)->_rect;
    sjt_dot1679 = mouseevent;
    sjt_functionParam496 = &(sjt_dot1679)->point;
    sjf_rect_containspoint(sjt_parent200, sjt_functionParam496, &sjt_ifElse57);
    if (sjt_ifElse57) {
        int32_t sjt_compare121;
        int32_t sjt_compare122;
        sjs_mouseevent* sjt_dot1680;
        bool sjt_ifElse58;

        sjt_dot1680 = mouseevent;
        sjt_compare121 = (sjt_dot1680)->type;
        sjt_compare122 = sjv_mouseeventtype_move;
        sjt_ifElse58 = sjt_compare121 == sjt_compare122;
        if (sjt_ifElse58) {
            sjs_point* sjt_copy44;
            sjs_crosshairselement* sjt_dot1681;
            sjs_mouseevent* sjt_dot1682;
            sjs_crosshairselement* sjt_dot1683;
            sjs_crosshairselement* sjt_dot1684;

            sjt_dot1681 = _parent;
            sjt_dot1682 = mouseevent;
            sjt_copy44 = &(sjt_dot1682)->point;
            sjf_point_copy(&sjt_dot1681->_point, sjt_copy44);
            sjt_dot1683 = _parent;
            sjt_dot1683->_topdownrenderer._refCount = -1;
            sjt_dot1684 = _parent;
            sjt_dot1684->_leftrightrenderer._refCount = -1;
        }
    }
}

void sjf_crosshairselement_getrect(sjs_crosshairselement* _parent, sjs_rect** _return) {
    sjs_crosshairselement* sjt_dot1641;

    sjt_dot1641 = _parent;
    (*_return) = &(sjt_dot1641)->_rect;
}

void sjf_crosshairselement_getsize(sjs_crosshairselement* _parent, sjs_size* maxsize, sjs_size* _return) {
    sjs_size* sjt_dot1637;
    sjs_size* sjt_dot1638;

    _return->_refCount = 1;
    sjt_dot1637 = maxsize;
    _return->w = (sjt_dot1637)->w;
    sjt_dot1638 = maxsize;
    _return->h = (sjt_dot1638)->h;
    sjf_size(_return);
}

void sjf_crosshairselement_getsize_heap(sjs_crosshairselement* _parent, sjs_size* maxsize, sjs_size** _return) {
    sjs_size* sjt_dot1639;
    sjs_size* sjt_dot1640;

    (*_return) = (sjs_size*)malloc(sizeof(sjs_size));
    (*_return)->_refCount = 1;
    sjt_dot1639 = maxsize;
    (*_return)->w = (sjt_dot1639)->w;
    sjt_dot1640 = maxsize;
    (*_return)->h = (sjt_dot1640)->h;
    sjf_size_heap((*_return));
}

void sjf_crosshairselement_heap(sjs_crosshairselement* _this) {
}

sjs_object* sjf_crosshairselement_heap_asInterface(sjs_crosshairselement* _this, int typeId) {
    switch (typeId) {
        case sji_element_typeId:  {
            return (sjs_object*)sjf_crosshairselement_heap_as_sji_element(_this);
        }
    }

    return 0;
}

sji_element* sjf_crosshairselement_heap_as_sji_element(sjs_crosshairselement* _this) {
    sji_element* _interface;
    _interface = (sji_element*)malloc(sizeof(sji_element));
    _interface->_refCount = 1;
    _interface->_parent = (sjs_object*)_this;
    _interface->_parent->_refCount++;
    _interface->destroy = (void(*)(void*))sjf_crosshairselement_destroy;
    _interface->asInterface = (sjs_object*(*)(sjs_object*,int))sjf_crosshairselement_heap_asInterface;
    _interface->getsize = (void(*)(void*,sjs_size*, sjs_size*))sjf_crosshairselement_getsize;
    _interface->getsize_heap = (void(*)(void*,sjs_size*, sjs_size**))sjf_crosshairselement_getsize_heap;
    _interface->getrect = (void(*)(void*, sjs_rect**))sjf_crosshairselement_getrect;
    _interface->setrect = (void(*)(void*,sjs_rect*))sjf_crosshairselement_setrect;
    _interface->render = (void(*)(void*,sjs_scene2d*))sjf_crosshairselement_render;
    _interface->firemouseevent = (void(*)(void*,sjs_mouseevent*))sjf_crosshairselement_firemouseevent;

    return _interface;
}

void sjf_crosshairselement_render(sjs_crosshairselement* _parent, sjs_scene2d* scene) {
    bool result31;
    bool result32;
    sjs_crosshairselement* sjt_dot1646;
    sjs_crosshairselement* sjt_dot1655;
    sjs_crosshairselement* sjt_dot1664;
    sjs_crosshairselement* sjt_dot1666;
    bool sjt_ifElse53;
    bool sjt_ifElse54;
    bool sjt_ifElse55;
    bool sjt_ifElse56;
    sjs_boxrenderer* sjt_isEmpty16;
    sjs_boxrenderer* sjt_isEmpty17;
    sjs_boxrenderer* sjt_isEmpty18;
    sjs_boxrenderer* sjt_isEmpty19;
    bool sjt_not10;
    bool sjt_not9;

    sjt_dot1646 = _parent;
    sjt_isEmpty16 = ((sjt_dot1646)->_topdownrenderer._refCount != -1 ? &(sjt_dot1646)->_topdownrenderer : 0);
    sjt_ifElse53 = (sjt_isEmpty16 == 0);
    if (sjt_ifElse53) {
        sjs_color* sjt_copy42;
        sjs_crosshairselement* sjt_dot1647;
        sjs_point* sjt_dot1648;
        sjs_crosshairselement* sjt_dot1649;
        sjs_rect* sjt_dot1650;
        sjs_crosshairselement* sjt_dot1651;
        sjs_rect* sjt_dot1652;
        sjs_crosshairselement* sjt_dot1653;
        sjs_crosshairselement* sjt_dot1654;

        sjt_dot1647 = _parent;
        sjt_dot1647->_topdownrenderer._refCount = 1;
        sjt_dot1647->_topdownrenderer.rect._refCount = 1;
        sjt_dot1649 = _parent;
        sjt_dot1648 = &(sjt_dot1649)->_point;
        sjt_dot1647->_topdownrenderer.rect.x = (sjt_dot1648)->x;
        sjt_dot1651 = _parent;
        sjt_dot1650 = &(sjt_dot1651)->_rect;
        sjt_dot1647->_topdownrenderer.rect.y = (sjt_dot1650)->y;
        sjt_dot1647->_topdownrenderer.rect.w = 1;
        sjt_dot1653 = _parent;
        sjt_dot1652 = &(sjt_dot1653)->_rect;
        sjt_dot1647->_topdownrenderer.rect.h = (sjt_dot1652)->h;
        sjf_rect(&sjt_dot1647->_topdownrenderer.rect);
        sjt_dot1654 = _parent;
        sjt_copy42 = &(sjt_dot1654)->color;
        sjt_dot1647->_topdownrenderer.color._refCount = 1;
        sjf_color_copy(&sjt_dot1647->_topdownrenderer.color, sjt_copy42);
        sjf_boxrenderer(&sjt_dot1647->_topdownrenderer);
    }

    sjt_dot1655 = _parent;
    sjt_isEmpty17 = ((sjt_dot1655)->_leftrightrenderer._refCount != -1 ? &(sjt_dot1655)->_leftrightrenderer : 0);
    sjt_ifElse54 = (sjt_isEmpty17 == 0);
    if (sjt_ifElse54) {
        sjs_color* sjt_copy43;
        sjs_crosshairselement* sjt_dot1656;
        sjs_rect* sjt_dot1657;
        sjs_crosshairselement* sjt_dot1658;
        sjs_point* sjt_dot1659;
        sjs_crosshairselement* sjt_dot1660;
        sjs_rect* sjt_dot1661;
        sjs_crosshairselement* sjt_dot1662;
        sjs_crosshairselement* sjt_dot1663;

        sjt_dot1656 = _parent;
        sjt_dot1656->_leftrightrenderer._refCount = 1;
        sjt_dot1656->_leftrightrenderer.rect._refCount = 1;
        sjt_dot1658 = _parent;
        sjt_dot1657 = &(sjt_dot1658)->_rect;
        sjt_dot1656->_leftrightrenderer.rect.x = (sjt_dot1657)->x;
        sjt_dot1660 = _parent;
        sjt_dot1659 = &(sjt_dot1660)->_point;
        sjt_dot1656->_leftrightrenderer.rect.y = (sjt_dot1659)->y;
        sjt_dot1662 = _parent;
        sjt_dot1661 = &(sjt_dot1662)->_rect;
        sjt_dot1656->_leftrightrenderer.rect.w = (sjt_dot1661)->w;
        sjt_dot1656->_leftrightrenderer.rect.h = 1;
        sjf_rect(&sjt_dot1656->_leftrightrenderer.rect);
        sjt_dot1663 = _parent;
        sjt_copy43 = &(sjt_dot1663)->color;
        sjt_dot1656->_leftrightrenderer.color._refCount = 1;
        sjf_color_copy(&sjt_dot1656->_leftrightrenderer.color, sjt_copy43);
        sjf_boxrenderer(&sjt_dot1656->_leftrightrenderer);
    }

    sjt_dot1664 = _parent;
    sjt_isEmpty18 = ((sjt_dot1664)->_topdownrenderer._refCount != -1 ? &(sjt_dot1664)->_topdownrenderer : 0);
    sjt_not9 = (sjt_isEmpty18 == 0);
    result31 = !sjt_not9;
    sjt_ifElse55 = result31;
    if (sjt_ifElse55) {
        sjs_crosshairselement* sjt_dot1665;
        sjs_scene2d* sjt_functionParam494;
        sjs_boxrenderer* sjt_parent198;

        sjt_dot1665 = _parent;
        sjt_parent198 = ((sjt_dot1665)->_topdownrenderer._refCount != -1 ? &(sjt_dot1665)->_topdownrenderer : 0);
        sjt_functionParam494 = scene;
        sjf_boxrenderer_render(sjt_parent198, sjt_functionParam494);
    }

    sjt_dot1666 = _parent;
    sjt_isEmpty19 = ((sjt_dot1666)->_leftrightrenderer._refCount != -1 ? &(sjt_dot1666)->_leftrightrenderer : 0);
    sjt_not10 = (sjt_isEmpty19 == 0);
    result32 = !sjt_not10;
    sjt_ifElse56 = result32;
    if (sjt_ifElse56) {
        sjs_crosshairselement* sjt_dot1667;
        sjs_scene2d* sjt_functionParam495;
        sjs_boxrenderer* sjt_parent199;

        sjt_dot1667 = _parent;
        sjt_parent199 = ((sjt_dot1667)->_leftrightrenderer._refCount != -1 ? &(sjt_dot1667)->_leftrightrenderer : 0);
        sjt_functionParam495 = scene;
        sjf_boxrenderer_render(sjt_parent199, sjt_functionParam495);
    }
}

void sjf_crosshairselement_setrect(sjs_crosshairselement* _parent, sjs_rect* rect_) {
    bool result30;
    sjs_crosshairselement* sjt_dot1642;
    sjs_rect* sjt_functionParam493;
    bool sjt_ifElse52;
    bool sjt_not8;
    sjs_rect* sjt_parent197;

    sjt_dot1642 = _parent;
    sjt_parent197 = &(sjt_dot1642)->_rect;
    sjt_functionParam493 = rect_;
    sjf_rect_isequal(sjt_parent197, sjt_functionParam493, &sjt_not8);
    result30 = !sjt_not8;
    sjt_ifElse52 = result30;
    if (sjt_ifElse52) {
        sjs_rect* sjt_copy41;
        sjs_crosshairselement* sjt_dot1643;
        sjs_crosshairselement* sjt_dot1644;
        sjs_crosshairselement* sjt_dot1645;

        sjt_dot1643 = _parent;
        sjt_copy41 = rect_;
        sjf_rect_copy(&sjt_dot1643->_rect, sjt_copy41);
        sjt_dot1644 = _parent;
        sjt_dot1644->_topdownrenderer._refCount = -1;
        sjt_dot1645 = _parent;
        sjt_dot1645->_leftrightrenderer._refCount = -1;
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

sjs_object* sjf_fillelement_asInterface(sjs_fillelement* _this, int typeId) {
    switch (typeId) {
        case sji_element_typeId:  {
            return (sjs_object*)sjf_fillelement_as_sji_element(_this);
        }
    }

    return 0;
}

sji_element* sjf_fillelement_as_sji_element(sjs_fillelement* _this) {
    sji_element* _interface;
    _interface = (sji_element*)malloc(sizeof(sji_element));
    _interface->_refCount = 1;
    _interface->_parent = (sjs_object*)_this;
    _interface->_parent->_refCount++;
    _interface->destroy = (void(*)(void*))sjf_fillelement_destroy;
    _interface->asInterface = (sjs_object*(*)(sjs_object*,int))sjf_fillelement_asInterface;
    _interface->getsize = (void(*)(void*,sjs_size*, sjs_size*))sjf_fillelement_getsize;
    _interface->getsize_heap = (void(*)(void*,sjs_size*, sjs_size**))sjf_fillelement_getsize_heap;
    _interface->getrect = (void(*)(void*, sjs_rect**))sjf_fillelement_getrect;
    _interface->setrect = (void(*)(void*,sjs_rect*))sjf_fillelement_setrect;
    _interface->render = (void(*)(void*,sjs_scene2d*))sjf_fillelement_render;
    _interface->firemouseevent = (void(*)(void*,sjs_mouseevent*))sjf_fillelement_firemouseevent;

    return _interface;
}

void sjf_fillelement_copy(sjs_fillelement* _this, sjs_fillelement* _from) {
    _this->children._refCount = 1;
    sjf_array_heap_element_copy(&_this->children, &_from->children);
    _this->_rect._refCount = 1;
    sjf_rect_copy(&_this->_rect, &_from->_rect);
}

void sjf_fillelement_destroy(sjs_fillelement* _this) {
}

void sjf_fillelement_firemouseevent(sjs_fillelement* _parent, sjs_mouseevent* mouseevent) {
    int32_t i;
    sjs_array_heap_element* sjt_dot14;
    sjs_fillelement* sjt_dot15;
    int32_t sjt_forEnd3;
    int32_t sjt_forStart3;

    sjt_forStart3 = 0;
    sjt_dot15 = _parent;
    sjt_dot14 = &(sjt_dot15)->children;
    sjt_forEnd3 = (sjt_dot14)->count;
    i = sjt_forStart3;
    while (i < sjt_forEnd3) {
        sjs_fillelement* sjt_dot16;
        int32_t sjt_functionParam3;
        sjs_mouseevent* sjt_interfaceParam3;
        sjs_array_heap_element* sjt_parent5;
        sji_element* sjt_parent6;
        sji_element* sjv_child = 0;

        sjt_dot16 = _parent;
        sjt_parent5 = &(sjt_dot16)->children;
        sjt_functionParam3 = i;
        sjf_array_heap_element_getat_heap(sjt_parent5, sjt_functionParam3, &sjv_child);
        sjt_parent6 = sjv_child;
        sjt_interfaceParam3 = mouseevent;
        sjt_parent6->firemouseevent(sjt_parent6->_parent, sjt_interfaceParam3);
        i++;

        sjv_child->_refCount--;
        if (sjv_child->_refCount <= 0) {
            sji_element_destroy(sjv_child);
        }
    }
}

void sjf_fillelement_getrect(sjs_fillelement* _parent, sjs_rect** _return) {
    sjs_fillelement* sjt_dot5;

    sjt_dot5 = _parent;
    (*_return) = &(sjt_dot5)->_rect;
}

void sjf_fillelement_getsize(sjs_fillelement* _parent, sjs_size* maxsize, sjs_size* _return) {
    sjs_size* sjt_dot1;
    sjs_size* sjt_dot2;

    _return->_refCount = 1;
    sjt_dot1 = maxsize;
    _return->w = (sjt_dot1)->w;
    sjt_dot2 = maxsize;
    _return->h = (sjt_dot2)->h;
    sjf_size(_return);
}

void sjf_fillelement_getsize_heap(sjs_fillelement* _parent, sjs_size* maxsize, sjs_size** _return) {
    sjs_size* sjt_dot3;
    sjs_size* sjt_dot4;

    (*_return) = (sjs_size*)malloc(sizeof(sjs_size));
    (*_return)->_refCount = 1;
    sjt_dot3 = maxsize;
    (*_return)->w = (sjt_dot3)->w;
    sjt_dot4 = maxsize;
    (*_return)->h = (sjt_dot4)->h;
    sjf_size_heap((*_return));
}

void sjf_fillelement_heap(sjs_fillelement* _this) {
}

sjs_object* sjf_fillelement_heap_asInterface(sjs_fillelement* _this, int typeId) {
    switch (typeId) {
        case sji_element_typeId:  {
            return (sjs_object*)sjf_fillelement_heap_as_sji_element(_this);
        }
    }

    return 0;
}

sji_element* sjf_fillelement_heap_as_sji_element(sjs_fillelement* _this) {
    sji_element* _interface;
    _interface = (sji_element*)malloc(sizeof(sji_element));
    _interface->_refCount = 1;
    _interface->_parent = (sjs_object*)_this;
    _interface->_parent->_refCount++;
    _interface->destroy = (void(*)(void*))sjf_fillelement_destroy;
    _interface->asInterface = (sjs_object*(*)(sjs_object*,int))sjf_fillelement_heap_asInterface;
    _interface->getsize = (void(*)(void*,sjs_size*, sjs_size*))sjf_fillelement_getsize;
    _interface->getsize_heap = (void(*)(void*,sjs_size*, sjs_size**))sjf_fillelement_getsize_heap;
    _interface->getrect = (void(*)(void*, sjs_rect**))sjf_fillelement_getrect;
    _interface->setrect = (void(*)(void*,sjs_rect*))sjf_fillelement_setrect;
    _interface->render = (void(*)(void*,sjs_scene2d*))sjf_fillelement_render;
    _interface->firemouseevent = (void(*)(void*,sjs_mouseevent*))sjf_fillelement_firemouseevent;

    return _interface;
}

void sjf_fillelement_render(sjs_fillelement* _parent, sjs_scene2d* scene) {
    int32_t i;
    sjs_array_heap_element* sjt_dot11;
    sjs_fillelement* sjt_dot12;
    int32_t sjt_forEnd2;
    int32_t sjt_forStart2;

    sjt_forStart2 = 0;
    sjt_dot12 = _parent;
    sjt_dot11 = &(sjt_dot12)->children;
    sjt_forEnd2 = (sjt_dot11)->count;
    i = sjt_forStart2;
    while (i < sjt_forEnd2) {
        sjs_fillelement* sjt_dot13;
        int32_t sjt_functionParam2;
        sjs_scene2d* sjt_interfaceParam2;
        sjs_array_heap_element* sjt_parent3;
        sji_element* sjt_parent4;
        sji_element* sjv_child = 0;

        sjt_dot13 = _parent;
        sjt_parent3 = &(sjt_dot13)->children;
        sjt_functionParam2 = i;
        sjf_array_heap_element_getat_heap(sjt_parent3, sjt_functionParam2, &sjv_child);
        sjt_parent4 = sjv_child;
        sjt_interfaceParam2 = scene;
        sjt_parent4->render(sjt_parent4->_parent, sjt_interfaceParam2);
        i++;

        sjv_child->_refCount--;
        if (sjv_child->_refCount <= 0) {
            sji_element_destroy(sjv_child);
        }
    }
}

void sjf_fillelement_setrect(sjs_fillelement* _parent, sjs_rect* rect_) {
    int32_t i;
    sjs_rect* sjt_copy1;
    sjs_fillelement* sjt_dot6;
    sjs_array_heap_element* sjt_dot7;
    sjs_fillelement* sjt_dot8;
    int32_t sjt_forEnd1;
    int32_t sjt_forStart1;

    sjt_dot6 = _parent;
    sjt_copy1 = rect_;
    sjf_rect_copy(&sjt_dot6->_rect, sjt_copy1);
    sjt_forStart1 = 0;
    sjt_dot8 = _parent;
    sjt_dot7 = &(sjt_dot8)->children;
    sjt_forEnd1 = (sjt_dot7)->count;
    i = sjt_forStart1;
    while (i < sjt_forEnd1) {
        sjs_fillelement* sjt_dot10;
        sjs_fillelement* sjt_dot9;
        int32_t sjt_functionParam1;
        sjs_rect* sjt_interfaceParam1;
        sjs_array_heap_element* sjt_parent1;
        sji_element* sjt_parent2;
        sji_element* sjv_child = 0;

        sjt_dot9 = _parent;
        sjt_parent1 = &(sjt_dot9)->children;
        sjt_functionParam1 = i;
        sjf_array_heap_element_getat_heap(sjt_parent1, sjt_functionParam1, &sjv_child);
        sjt_parent2 = sjv_child;
        sjt_dot10 = _parent;
        sjt_interfaceParam1 = &(sjt_dot10)->_rect;
        sjt_parent2->setrect(sjt_parent2->_parent, sjt_interfaceParam1);
        i++;

        sjv_child->_refCount--;
        if (sjv_child->_refCount <= 0) {
            sji_element_destroy(sjv_child);
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
    sjs_size* sjt_copy20;
    uint32_t sjv_id;

    sjv_id = (uint32_t)0u;
    glGenRenderbuffers(1, &sjv_id); 
    _return->_refCount = 1;
    sjt_copy20 = size;
    _return->size._refCount = 1;
    sjf_size_copy(&_return->size, sjt_copy20);
    _return->id = sjv_id;
    sjf_renderbuffer(_return);
}

void sjf_glgenrenderbuffer_heap(sjs_size* size, sjs_renderbuffer** _return) {
    sjs_size* sjt_copy21;
    uint32_t sjv_id;

    sjv_id = (uint32_t)0u;
    glGenRenderbuffers(1, &sjv_id); 
    (*_return) = (sjs_renderbuffer*)malloc(sizeof(sjs_renderbuffer));
    (*_return)->_refCount = 1;
    sjt_copy21 = size;
    (*_return)->size._refCount = 1;
    sjf_size_copy(&(*_return)->size, sjt_copy21);
    (*_return)->id = sjv_id;
    sjf_renderbuffer_heap((*_return));
}

void sjf_glgentexture(sjs_size* size, sjs_texture* _return) {
    sjs_size* sjt_copy18;
    uint32_t sjv_id;

    sjv_id = (uint32_t)0u;
    glGenTextures(1, &sjv_id);
    _return->_refCount = 1;
    sjt_copy18 = size;
    _return->size._refCount = 1;
    sjf_size_copy(&_return->size, sjt_copy18);
    _return->id = sjv_id;
    sjf_texture(_return);
}

void sjf_glgentexture_heap(sjs_size* size, sjs_texture** _return) {
    sjs_size* sjt_copy19;
    uint32_t sjv_id;

    sjv_id = (uint32_t)0u;
    glGenTextures(1, &sjv_id);
    (*_return) = (sjs_texture*)malloc(sizeof(sjs_texture));
    (*_return)->_refCount = 1;
    sjt_copy19 = size;
    (*_return)->size._refCount = 1;
    sjf_size_copy(&(*_return)->size, sjt_copy19);
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

void sjf_i32_max(int32_t a, int32_t b, int32_t* _return) {
    int32_t sjt_compare45;
    int32_t sjt_compare46;
    bool sjt_ifElse14;

    sjt_compare45 = a;
    sjt_compare46 = b;
    sjt_ifElse14 = sjt_compare45 < sjt_compare46;
    if (sjt_ifElse14) {
        (*_return) = b;
    } else {
        (*_return) = a;
    }
}

void sjf_image(sjs_image* _this) {
    bool sjt_and10;
    bool sjt_and9;
    sjs_rect sjt_call73 = { -1 };
    int32_t sjt_compare105;
    int32_t sjt_compare106;
    int32_t sjt_compare107;
    int32_t sjt_compare108;
    sjs_rect* sjt_dot1621;
    sjs_rect* sjt_dot1622;
    bool sjt_ifElse50;
    sjs_size sjv_size = { -1 };

    sjt_dot1621 = &_this->rect;
    sjt_compare105 = (sjt_dot1621)->w;
    sjt_compare106 = 0;
    sjt_and9 = sjt_compare105 == sjt_compare106;
    sjt_dot1622 = &_this->rect;
    sjt_compare107 = (sjt_dot1622)->h;
    sjt_compare108 = 0;
    sjt_and10 = sjt_compare107 == sjt_compare108;
    sjt_ifElse50 = sjt_and9 && sjt_and10;
    if (sjt_ifElse50) {
        sjs_rect* sjt_copy39;
        sjs_size* sjt_dot1631;
        sjs_size* sjt_dot1632;
        sjs_texture* sjt_parent194;

        sjt_parent194 = &_this->texture;
        sjf_texture_getsize(sjt_parent194, &sjv_size);
        sjt_call73._refCount = 1;
        sjt_call73.x = 0;
        sjt_call73.y = 0;
        sjt_dot1631 = &sjv_size;
        sjt_call73.w = (sjt_dot1631)->w;
        sjt_dot1632 = &sjv_size;
        sjt_call73.h = (sjt_dot1632)->h;
        sjf_rect(&sjt_call73);
        sjt_copy39 = &sjt_call73;
        sjf_rect_copy(&_this->rect, sjt_copy39);
    }

    if (sjt_call73._refCount == 1) { sjf_rect_destroy(&sjt_call73); }
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
    sjs_rect sjt_call74 = { -1 };
    int32_t sjt_compare109;
    int32_t sjt_compare110;
    int32_t sjt_compare111;
    int32_t sjt_compare112;
    sjs_rect* sjt_dot1633;
    sjs_rect* sjt_dot1634;
    bool sjt_ifElse51;
    sjs_size sjv_size = { -1 };

    sjt_dot1633 = &_this->rect;
    sjt_compare109 = (sjt_dot1633)->w;
    sjt_compare110 = 0;
    sjt_and11 = sjt_compare109 == sjt_compare110;
    sjt_dot1634 = &_this->rect;
    sjt_compare111 = (sjt_dot1634)->h;
    sjt_compare112 = 0;
    sjt_and12 = sjt_compare111 == sjt_compare112;
    sjt_ifElse51 = sjt_and11 && sjt_and12;
    if (sjt_ifElse51) {
        sjs_rect* sjt_copy40;
        sjs_size* sjt_dot1635;
        sjs_size* sjt_dot1636;
        sjs_texture* sjt_parent195;

        sjt_parent195 = &_this->texture;
        sjf_texture_getsize(sjt_parent195, &sjv_size);
        sjt_call74._refCount = 1;
        sjt_call74.x = 0;
        sjt_call74.y = 0;
        sjt_dot1635 = &sjv_size;
        sjt_call74.w = (sjt_dot1635)->w;
        sjt_dot1636 = &sjv_size;
        sjt_call74.h = (sjt_dot1636)->h;
        sjf_rect(&sjt_call74);
        sjt_copy40 = &sjt_call74;
        sjf_rect_copy(&_this->rect, sjt_copy40);
    }

    if (sjt_call74._refCount == 1) { sjf_rect_destroy(&sjt_call74); }
    if (sjv_size._refCount == 1) { sjf_size_destroy(&sjv_size); }
}

void sjf_imageelement(sjs_imageelement* _this) {
}

sjs_object* sjf_imageelement_asInterface(sjs_imageelement* _this, int typeId) {
    switch (typeId) {
        case sji_element_typeId:  {
            return (sjs_object*)sjf_imageelement_as_sji_element(_this);
        }
    }

    return 0;
}

sji_element* sjf_imageelement_as_sji_element(sjs_imageelement* _this) {
    sji_element* _interface;
    _interface = (sji_element*)malloc(sizeof(sji_element));
    _interface->_refCount = 1;
    _interface->_parent = (sjs_object*)_this;
    _interface->_parent->_refCount++;
    _interface->destroy = (void(*)(void*))sjf_imageelement_destroy;
    _interface->asInterface = (sjs_object*(*)(sjs_object*,int))sjf_imageelement_asInterface;
    _interface->getsize = (void(*)(void*,sjs_size*, sjs_size*))sjf_imageelement_getsize;
    _interface->getsize_heap = (void(*)(void*,sjs_size*, sjs_size**))sjf_imageelement_getsize_heap;
    _interface->getrect = (void(*)(void*, sjs_rect**))sjf_imageelement_getrect;
    _interface->setrect = (void(*)(void*,sjs_rect*))sjf_imageelement_setrect;
    _interface->render = (void(*)(void*,sjs_scene2d*))sjf_imageelement_render;
    _interface->firemouseevent = (void(*)(void*,sjs_mouseevent*))sjf_imageelement_firemouseevent;

    return _interface;
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

void sjf_imageelement_getrect(sjs_imageelement* _parent, sjs_rect** _return) {
    sjs_imageelement* sjt_dot1590;

    sjt_dot1590 = _parent;
    (*_return) = &(sjt_dot1590)->_rect;
}

void sjf_imageelement_getsize(sjs_imageelement* _parent, sjs_size* maxsize, sjs_size* _return) {
    sjs_size* sjt_dot1586;
    sjs_size* sjt_dot1587;

    _return->_refCount = 1;
    sjt_dot1586 = maxsize;
    _return->w = (sjt_dot1586)->w;
    sjt_dot1587 = maxsize;
    _return->h = (sjt_dot1587)->h;
    sjf_size(_return);
}

void sjf_imageelement_getsize_heap(sjs_imageelement* _parent, sjs_size* maxsize, sjs_size** _return) {
    sjs_size* sjt_dot1588;
    sjs_size* sjt_dot1589;

    (*_return) = (sjs_size*)malloc(sizeof(sjs_size));
    (*_return)->_refCount = 1;
    sjt_dot1588 = maxsize;
    (*_return)->w = (sjt_dot1588)->w;
    sjt_dot1589 = maxsize;
    (*_return)->h = (sjt_dot1589)->h;
    sjf_size_heap((*_return));
}

void sjf_imageelement_heap(sjs_imageelement* _this) {
}

sjs_object* sjf_imageelement_heap_asInterface(sjs_imageelement* _this, int typeId) {
    switch (typeId) {
        case sji_element_typeId:  {
            return (sjs_object*)sjf_imageelement_heap_as_sji_element(_this);
        }
    }

    return 0;
}

sji_element* sjf_imageelement_heap_as_sji_element(sjs_imageelement* _this) {
    sji_element* _interface;
    _interface = (sji_element*)malloc(sizeof(sji_element));
    _interface->_refCount = 1;
    _interface->_parent = (sjs_object*)_this;
    _interface->_parent->_refCount++;
    _interface->destroy = (void(*)(void*))sjf_imageelement_destroy;
    _interface->asInterface = (sjs_object*(*)(sjs_object*,int))sjf_imageelement_heap_asInterface;
    _interface->getsize = (void(*)(void*,sjs_size*, sjs_size*))sjf_imageelement_getsize;
    _interface->getsize_heap = (void(*)(void*,sjs_size*, sjs_size**))sjf_imageelement_getsize_heap;
    _interface->getrect = (void(*)(void*, sjs_rect**))sjf_imageelement_getrect;
    _interface->setrect = (void(*)(void*,sjs_rect*))sjf_imageelement_setrect;
    _interface->render = (void(*)(void*,sjs_scene2d*))sjf_imageelement_render;
    _interface->firemouseevent = (void(*)(void*,sjs_mouseevent*))sjf_imageelement_firemouseevent;

    return _interface;
}

void sjf_imageelement_render(sjs_imageelement* _parent, sjs_scene2d* scene) {
    bool result29;
    sjs_imageelement* sjt_dot1594;
    sjs_imageelement* sjt_dot1619;
    bool sjt_ifElse48;
    bool sjt_ifElse49;
    sjs_imagerenderer* sjt_isEmpty14;
    sjs_imagerenderer* sjt_isEmpty15;
    bool sjt_not7;

    sjt_dot1594 = _parent;
    sjt_isEmpty14 = ((sjt_dot1594)->_imagerenderer._refCount != -1 ? &(sjt_dot1594)->_imagerenderer : 0);
    sjt_ifElse48 = (sjt_isEmpty14 == 0);
    if (sjt_ifElse48) {
        sjs_image* sjt_copy38;
        sjs_imageelement* sjt_dot1595;
        sjs_imageelement* sjt_dot1616;
        sjs_imageelement* sjt_dot1617;
        sjs_imageelement* sjt_dot1618;
        sjs_margin* sjt_functionParam488;
        sjs_rect* sjt_parent192;

        sjt_dot1595 = _parent;
        sjt_dot1595->_imagerenderer._refCount = 1;
        sjt_dot1616 = _parent;
        sjt_parent192 = &(sjt_dot1616)->_rect;
        sjt_dot1617 = _parent;
        sjt_functionParam488 = &(sjt_dot1617)->_margin;
        sjf_rect_subtractmargin(sjt_parent192, sjt_functionParam488, &sjt_dot1595->_imagerenderer.rect);
        sjt_dot1618 = _parent;
        sjt_copy38 = &(sjt_dot1618)->image;
        sjt_dot1595->_imagerenderer.image._refCount = 1;
        sjf_image_copy(&sjt_dot1595->_imagerenderer.image, sjt_copy38);
        sjf_imagerenderer(&sjt_dot1595->_imagerenderer);
    }

    sjt_dot1619 = _parent;
    sjt_isEmpty15 = ((sjt_dot1619)->_imagerenderer._refCount != -1 ? &(sjt_dot1619)->_imagerenderer : 0);
    sjt_not7 = (sjt_isEmpty15 == 0);
    result29 = !sjt_not7;
    sjt_ifElse49 = result29;
    if (sjt_ifElse49) {
        sjs_imageelement* sjt_dot1620;
        sjs_scene2d* sjt_functionParam489;
        sjs_imagerenderer* sjt_parent193;

        sjt_dot1620 = _parent;
        sjt_parent193 = ((sjt_dot1620)->_imagerenderer._refCount != -1 ? &(sjt_dot1620)->_imagerenderer : 0);
        sjt_functionParam489 = scene;
        sjf_imagerenderer_render(sjt_parent193, sjt_functionParam489);
    }
}

void sjf_imageelement_setrect(sjs_imageelement* _parent, sjs_rect* rect_) {
    bool result28;
    sjs_imageelement* sjt_dot1591;
    sjs_rect* sjt_functionParam487;
    bool sjt_ifElse47;
    bool sjt_not6;
    sjs_rect* sjt_parent191;

    sjt_dot1591 = _parent;
    sjt_parent191 = &(sjt_dot1591)->_rect;
    sjt_functionParam487 = rect_;
    sjf_rect_isequal(sjt_parent191, sjt_functionParam487, &sjt_not6);
    result28 = !sjt_not6;
    sjt_ifElse47 = result28;
    if (sjt_ifElse47) {
        sjs_rect* sjt_copy37;
        sjs_imageelement* sjt_dot1592;
        sjs_imageelement* sjt_dot1593;

        sjt_dot1592 = _parent;
        sjt_copy37 = rect_;
        sjf_rect_copy(&sjt_dot1592->_rect, sjt_copy37);
        sjt_dot1593 = _parent;
        sjt_dot1593->_imagerenderer._refCount = -1;
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
    float sjt_compare69;
    float sjt_compare70;
    float sjt_compare71;
    float sjt_compare72;
    sjs_vec3* sjt_functionParam403;
    sjs_vec3* sjt_functionParam404;
    sjs_vec3* sjt_functionParam405;
    sjs_vec3* sjt_functionParam406;
    bool sjt_ifElse26;
    bool sjt_ifElse27;
    sjs_vec3* sjt_parent157;
    sjs_vec3* sjt_parent158;
    sjs_vec3* sjt_parent159;
    sjs_vec3* sjt_parent160;
    float sjv_det;
    sjs_vec3 sjv_edge1 = { -1 };
    sjs_vec3 sjv_edge2 = { -1 };
    sjs_vec3 sjv_pvec = { -1 };
    sjs_vec3 sjv_qvec = { -1 };
    sjs_vec3 sjv_tvec = { -1 };

    sjt_parent157 = v1;
    sjt_functionParam403 = v0;
    sjf_vec3_subtract(sjt_parent157, sjt_functionParam403, &sjv_edge1);
    sjt_parent158 = v2;
    sjt_functionParam404 = v0;
    sjf_vec3_subtract(sjt_parent158, sjt_functionParam404, &sjv_edge2);
    sjt_parent159 = dir;
    sjt_functionParam405 = &sjv_edge2;
    sjf_vec3_cross(sjt_parent159, sjt_functionParam405, &sjv_pvec);
    sjt_parent160 = &sjv_edge1;
    sjt_functionParam406 = &sjv_pvec;
    sjf_vec3_dot(sjt_parent160, sjt_functionParam406, &sjv_det);
    sjt_compare69 = sjv_det;
    sjt_compare70 = 0.0f;
    sjt_ifElse26 = sjt_compare69 > sjt_compare70;
    if (sjt_ifElse26) {
        sjs_vec3* sjt_functionParam407;
        sjs_vec3* sjt_parent161;

        sjt_parent161 = orig;
        sjt_functionParam407 = v0;
        sjf_vec3_subtract(sjt_parent161, sjt_functionParam407, &sjv_tvec);
    } else {
        sjs_vec3* sjt_functionParam408;
        float sjt_math2347;
        float sjt_math2348;
        sjs_vec3* sjt_parent162;

        sjt_math2347 = 0.0f;
        sjt_math2348 = sjv_det;
        sjv_det = sjt_math2347 - sjt_math2348;
        sjt_parent162 = v0;
        sjt_functionParam408 = orig;
        sjf_vec3_subtract(sjt_parent162, sjt_functionParam408, &sjv_tvec);
    }

    sjt_compare71 = sjv_det;
    sjt_compare72 = 0.0001f;
    sjt_ifElse27 = sjt_compare71 < sjt_compare72;
    if (sjt_ifElse27) {
        _return->_refCount = -1;
    } else {
        float sjt_compare73;
        float sjt_compare74;
        float sjt_compare75;
        float sjt_compare76;
        sjs_vec3* sjt_functionParam409;
        bool sjt_ifElse28;
        bool sjt_or1;
        bool sjt_or2;
        sjs_vec3* sjt_parent163;
        float sjv_u;

        sjt_parent163 = &sjv_tvec;
        sjt_functionParam409 = &sjv_pvec;
        sjf_vec3_dot(sjt_parent163, sjt_functionParam409, &sjv_u);
        sjt_compare73 = sjv_u;
        sjt_compare74 = 0.0f;
        sjt_or1 = sjt_compare73 < sjt_compare74;
        sjt_compare75 = sjv_u;
        sjt_compare76 = sjv_det;
        sjt_or2 = sjt_compare75 > sjt_compare76;
        sjt_ifElse28 = sjt_or1 || sjt_or2;
        if (sjt_ifElse28) {
            _return->_refCount = -1;
        } else {
            float sjt_compare77;
            float sjt_compare78;
            float sjt_compare79;
            float sjt_compare80;
            sjs_vec3* sjt_functionParam410;
            sjs_vec3* sjt_functionParam411;
            bool sjt_ifElse29;
            float sjt_math2349;
            float sjt_math2350;
            bool sjt_or3;
            bool sjt_or4;
            sjs_vec3* sjt_parent164;
            sjs_vec3* sjt_parent165;
            float sjv_v;

            sjt_parent164 = &sjv_tvec;
            sjt_functionParam410 = &sjv_edge1;
            sjf_vec3_cross(sjt_parent164, sjt_functionParam410, &sjv_qvec);
            sjt_parent165 = dir;
            sjt_functionParam411 = &sjv_qvec;
            sjf_vec3_dot(sjt_parent165, sjt_functionParam411, &sjv_v);
            sjt_compare77 = sjv_v;
            sjt_compare78 = 0.0f;
            sjt_or3 = sjt_compare77 < sjt_compare78;
            sjt_math2349 = sjv_u;
            sjt_math2350 = sjv_v;
            sjt_compare79 = sjt_math2349 + sjt_math2350;
            sjt_compare80 = sjv_det;
            sjt_or4 = sjt_compare79 > sjt_compare80;
            sjt_ifElse29 = sjt_or3 || sjt_or4;
            if (sjt_ifElse29) {
                _return->_refCount = -1;
            } else {
                sjs_vec3* sjt_functionParam412;
                float sjt_math2351;
                float sjt_math2352;
                float sjt_math2353;
                float sjt_math2354;
                float sjt_math2355;
                float sjt_math2356;
                float sjt_math2357;
                float sjt_math2358;
                sjs_vec3* sjt_parent166;
                float sjv_finvdet;
                float sjv_t;

                sjt_parent166 = &sjv_edge2;
                sjt_functionParam412 = &sjv_qvec;
                sjf_vec3_dot(sjt_parent166, sjt_functionParam412, &sjv_t);
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
    float sjt_compare81;
    float sjt_compare82;
    float sjt_compare83;
    float sjt_compare84;
    sjs_vec3* sjt_functionParam413;
    sjs_vec3* sjt_functionParam414;
    sjs_vec3* sjt_functionParam415;
    sjs_vec3* sjt_functionParam416;
    bool sjt_ifElse30;
    bool sjt_ifElse31;
    sjs_vec3* sjt_parent167;
    sjs_vec3* sjt_parent168;
    sjs_vec3* sjt_parent169;
    sjs_vec3* sjt_parent170;
    float sjv_det;
    sjs_vec3 sjv_edge1 = { -1 };
    sjs_vec3 sjv_edge2 = { -1 };
    sjs_vec3 sjv_pvec = { -1 };
    sjs_vec3 sjv_qvec = { -1 };
    sjs_vec3 sjv_tvec = { -1 };

    sjt_parent167 = v1;
    sjt_functionParam413 = v0;
    sjf_vec3_subtract(sjt_parent167, sjt_functionParam413, &sjv_edge1);
    sjt_parent168 = v2;
    sjt_functionParam414 = v0;
    sjf_vec3_subtract(sjt_parent168, sjt_functionParam414, &sjv_edge2);
    sjt_parent169 = dir;
    sjt_functionParam415 = &sjv_edge2;
    sjf_vec3_cross(sjt_parent169, sjt_functionParam415, &sjv_pvec);
    sjt_parent170 = &sjv_edge1;
    sjt_functionParam416 = &sjv_pvec;
    sjf_vec3_dot(sjt_parent170, sjt_functionParam416, &sjv_det);
    sjt_compare81 = sjv_det;
    sjt_compare82 = 0.0f;
    sjt_ifElse30 = sjt_compare81 > sjt_compare82;
    if (sjt_ifElse30) {
        sjs_vec3* sjt_functionParam417;
        sjs_vec3* sjt_parent171;

        sjt_parent171 = orig;
        sjt_functionParam417 = v0;
        sjf_vec3_subtract(sjt_parent171, sjt_functionParam417, &sjv_tvec);
    } else {
        sjs_vec3* sjt_functionParam418;
        float sjt_math2359;
        float sjt_math2360;
        sjs_vec3* sjt_parent172;

        sjt_math2359 = 0.0f;
        sjt_math2360 = sjv_det;
        sjv_det = sjt_math2359 - sjt_math2360;
        sjt_parent172 = v0;
        sjt_functionParam418 = orig;
        sjf_vec3_subtract(sjt_parent172, sjt_functionParam418, &sjv_tvec);
    }

    sjt_compare83 = sjv_det;
    sjt_compare84 = 0.0001f;
    sjt_ifElse31 = sjt_compare83 < sjt_compare84;
    if (sjt_ifElse31) {
        (*_return) = 0;
        if ((*_return) != 0) {
            (*_return)->_refCount++;
        }
    } else {
        float sjt_compare85;
        float sjt_compare86;
        float sjt_compare87;
        float sjt_compare88;
        sjs_vec3* sjt_functionParam419;
        bool sjt_ifElse32;
        bool sjt_or5;
        bool sjt_or6;
        sjs_vec3* sjt_parent173;
        float sjv_u;

        sjt_parent173 = &sjv_tvec;
        sjt_functionParam419 = &sjv_pvec;
        sjf_vec3_dot(sjt_parent173, sjt_functionParam419, &sjv_u);
        sjt_compare85 = sjv_u;
        sjt_compare86 = 0.0f;
        sjt_or5 = sjt_compare85 < sjt_compare86;
        sjt_compare87 = sjv_u;
        sjt_compare88 = sjv_det;
        sjt_or6 = sjt_compare87 > sjt_compare88;
        sjt_ifElse32 = sjt_or5 || sjt_or6;
        if (sjt_ifElse32) {
            (*_return) = 0;
            if ((*_return) != 0) {
                (*_return)->_refCount++;
            }
        } else {
            float sjt_compare89;
            float sjt_compare90;
            float sjt_compare91;
            float sjt_compare92;
            sjs_vec3* sjt_functionParam420;
            sjs_vec3* sjt_functionParam421;
            bool sjt_ifElse33;
            float sjt_math2361;
            float sjt_math2362;
            bool sjt_or7;
            bool sjt_or8;
            sjs_vec3* sjt_parent174;
            sjs_vec3* sjt_parent175;
            float sjv_v;

            sjt_parent174 = &sjv_tvec;
            sjt_functionParam420 = &sjv_edge1;
            sjf_vec3_cross(sjt_parent174, sjt_functionParam420, &sjv_qvec);
            sjt_parent175 = dir;
            sjt_functionParam421 = &sjv_qvec;
            sjf_vec3_dot(sjt_parent175, sjt_functionParam421, &sjv_v);
            sjt_compare89 = sjv_v;
            sjt_compare90 = 0.0f;
            sjt_or7 = sjt_compare89 < sjt_compare90;
            sjt_math2361 = sjv_u;
            sjt_math2362 = sjv_v;
            sjt_compare91 = sjt_math2361 + sjt_math2362;
            sjt_compare92 = sjv_det;
            sjt_or8 = sjt_compare91 > sjt_compare92;
            sjt_ifElse33 = sjt_or7 || sjt_or8;
            if (sjt_ifElse33) {
                (*_return) = 0;
                if ((*_return) != 0) {
                    (*_return)->_refCount++;
                }
            } else {
                sjs_vec3* sjt_functionParam422;
                float sjt_math2363;
                float sjt_math2364;
                float sjt_math2365;
                float sjt_math2366;
                float sjt_math2367;
                float sjt_math2368;
                float sjt_math2369;
                float sjt_math2370;
                sjs_vec3* sjt_parent176;
                sjs_vec3* sjt_value2 = 0;
                float sjv_finvdet;
                float sjv_t;

                sjt_parent176 = &sjv_edge2;
                sjt_functionParam422 = &sjv_qvec;
                sjf_vec3_dot(sjt_parent176, sjt_functionParam422, &sjv_t);
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
    int32_t sjt_cast14;
    sjs_array_texture* sjt_dot1322;
    cb_texture_heap_model sjt_functionParam214;
    float sjt_math2103;
    float sjt_math2104;
    float sjt_math2105;
    float sjt_math2106;
    sjs_array_texture* sjt_parent79;

    sjt_dot1322 = &_this->textures;
    sjt_cast14 = (sjt_dot1322)->count;
    sjt_math2105 = (float)sjt_cast14;
    sjt_math2106 = 0.8f;
    sjt_math2103 = sjt_math2105 * sjt_math2106;
    sjt_math2104 = 2.0f;
    _this->_angle = sjt_math2103 / sjt_math2104;
    sjt_parent79 = &_this->textures;
    sjt_functionParam214._parent = &_this;
    sjt_functionParam214._cb_heap = (void(*)(void*,sjs_texture*, sji_model**))sjf_leafpanel_texturetomodel_heap;
    sjf_array_texture_map_heap_model(sjt_parent79, sjt_functionParam214, &_this->children);
}

sjs_object* sjf_leafpanel_asInterface(sjs_leafpanel* _this, int typeId) {
    switch (typeId) {
        case sji_model_typeId:  {
            return (sjs_object*)sjf_leafpanel_as_sji_model(_this);
        }
    }

    return 0;
}

sji_model* sjf_leafpanel_as_sji_model(sjs_leafpanel* _this) {
    sji_model* _interface;
    _interface = (sji_model*)malloc(sizeof(sji_model));
    _interface->_refCount = 1;
    _interface->_parent = (sjs_object*)_this;
    _interface->_parent->_refCount++;
    _interface->destroy = (void(*)(void*))sjf_leafpanel_destroy;
    _interface->asInterface = (sjs_object*(*)(sjs_object*,int))sjf_leafpanel_asInterface;
    _interface->update = (void(*)(void*,sjs_rect*,sjs_mat4*,sjs_mat4*,sjs_mat4*,sjs_light*))sjf_leafpanel_update;
    _interface->getz = (void(*)(void*, float*))sjf_leafpanel_getz;
    _interface->renderorqueue = (void(*)(void*,sjs_list_heap_model*))sjf_leafpanel_renderorqueue;
    _interface->render = (void(*)(void*))sjf_leafpanel_render;
    _interface->firemouseevent = (void(*)(void*,sjs_mouseevent*))sjf_leafpanel_firemouseevent;

    return _interface;
}

void sjf_leafpanel_copy(sjs_leafpanel* _this, sjs_leafpanel* _from) {
    _this->textures._refCount = 1;
    sjf_array_texture_copy(&_this->textures, &_from->textures);
    _this->children._refCount = 1;
    sjf_array_heap_model_copy(&_this->children, &_from->children);
    _this->_angle = _from->_angle;
}

void sjf_leafpanel_destroy(sjs_leafpanel* _this) {
}

void sjf_leafpanel_firemouseevent(sjs_leafpanel* _parent, sjs_mouseevent* mouseevent) {
    int32_t i;
    sjs_array_heap_model* sjt_dot1358;
    sjs_leafpanel* sjt_dot1359;
    int32_t sjt_forEnd14;
    int32_t sjt_forStart14;

    sjt_forStart14 = 0;
    sjt_dot1359 = _parent;
    sjt_dot1358 = &(sjt_dot1359)->children;
    sjt_forEnd14 = (sjt_dot1358)->count;
    i = sjt_forStart14;
    while (i < sjt_forEnd14) {
        sjs_leafpanel* sjt_dot1360;
        int32_t sjt_functionParam251;
        sjs_mouseevent* sjt_interfaceParam17;
        sjs_array_heap_model* sjt_parent98;
        sji_model* sjt_parent99;
        sji_model* sjv_c = 0;

        sjt_dot1360 = _parent;
        sjt_parent98 = &(sjt_dot1360)->children;
        sjt_functionParam251 = i;
        sjf_array_heap_model_getat_heap(sjt_parent98, sjt_functionParam251, &sjv_c);
        sjt_parent99 = sjv_c;
        sjt_interfaceParam17 = mouseevent;
        sjt_parent99->firemouseevent(sjt_parent99->_parent, sjt_interfaceParam17);
        i++;

        sjv_c->_refCount--;
        if (sjv_c->_refCount <= 0) {
            sji_model_destroy(sjv_c);
        }
    }
}

void sjf_leafpanel_getz(sjs_leafpanel* _parent, float* _return) {
    (*_return) = 0.0f;
}

void sjf_leafpanel_heap(sjs_leafpanel* _this) {
    int32_t sjt_cast18;
    sjs_array_texture* sjt_dot1361;
    cb_texture_heap_model sjt_functionParam252;
    float sjt_math2149;
    float sjt_math2150;
    float sjt_math2151;
    float sjt_math2152;
    sjs_array_texture* sjt_parent100;

    sjt_dot1361 = &_this->textures;
    sjt_cast18 = (sjt_dot1361)->count;
    sjt_math2151 = (float)sjt_cast18;
    sjt_math2152 = 0.8f;
    sjt_math2149 = sjt_math2151 * sjt_math2152;
    sjt_math2150 = 2.0f;
    _this->_angle = sjt_math2149 / sjt_math2150;
    sjt_parent100 = &_this->textures;
    sjt_functionParam252._parent = _this;
    sjt_functionParam252._cb_heap = (void(*)(void*,sjs_texture*, sji_model**))sjf_leafpanel_texturetomodel_heap;
    sjf_array_texture_map_heap_model(sjt_parent100, sjt_functionParam252, &_this->children);
}

sjs_object* sjf_leafpanel_heap_asInterface(sjs_leafpanel* _this, int typeId) {
    switch (typeId) {
        case sji_model_typeId:  {
            return (sjs_object*)sjf_leafpanel_heap_as_sji_model(_this);
        }
    }

    return 0;
}

sji_model* sjf_leafpanel_heap_as_sji_model(sjs_leafpanel* _this) {
    sji_model* _interface;
    _interface = (sji_model*)malloc(sizeof(sji_model));
    _interface->_refCount = 1;
    _interface->_parent = (sjs_object*)_this;
    _interface->_parent->_refCount++;
    _interface->destroy = (void(*)(void*))sjf_leafpanel_destroy;
    _interface->asInterface = (sjs_object*(*)(sjs_object*,int))sjf_leafpanel_heap_asInterface;
    _interface->update = (void(*)(void*,sjs_rect*,sjs_mat4*,sjs_mat4*,sjs_mat4*,sjs_light*))sjf_leafpanel_update;
    _interface->getz = (void(*)(void*, float*))sjf_leafpanel_getz;
    _interface->renderorqueue = (void(*)(void*,sjs_list_heap_model*))sjf_leafpanel_renderorqueue;
    _interface->render = (void(*)(void*))sjf_leafpanel_render;
    _interface->firemouseevent = (void(*)(void*,sjs_mouseevent*))sjf_leafpanel_firemouseevent;

    return _interface;
}

void sjf_leafpanel_render(sjs_leafpanel* _parent) {
}

void sjf_leafpanel_renderorqueue(sjs_leafpanel* _parent, sjs_list_heap_model* zqueue) {
    int32_t i;
    sjs_array_heap_model* sjt_dot1355;
    sjs_leafpanel* sjt_dot1356;
    int32_t sjt_forEnd13;
    int32_t sjt_forStart13;

    sjt_forStart13 = 0;
    sjt_dot1356 = _parent;
    sjt_dot1355 = &(sjt_dot1356)->children;
    sjt_forEnd13 = (sjt_dot1355)->count;
    i = sjt_forStart13;
    while (i < sjt_forEnd13) {
        sjs_leafpanel* sjt_dot1357;
        int32_t sjt_functionParam250;
        sjs_list_heap_model* sjt_interfaceParam16;
        sjs_array_heap_model* sjt_parent96;
        sji_model* sjt_parent97;
        sji_model* sjv_c = 0;

        sjt_dot1357 = _parent;
        sjt_parent96 = &(sjt_dot1357)->children;
        sjt_functionParam250 = i;
        sjf_array_heap_model_getat_heap(sjt_parent96, sjt_functionParam250, &sjv_c);
        sjt_parent97 = sjv_c;
        sjt_interfaceParam16 = zqueue;
        sjt_parent97->renderorqueue(sjt_parent97->_parent, sjt_interfaceParam16);
        i++;

        sjv_c->_refCount--;
        if (sjv_c->_refCount <= 0) {
            sji_model_destroy(sjv_c);
        }
    }
}

void sjf_leafpanel_texturetomodel_heap(sjs_leafpanel* _parent, sjs_texture* texture, sji_model** _return) {
    float result15;
    float result16;
    sjs_string sjt_call35 = { -1 };
    sjs_string sjt_call36 = { -1 };
    sjs_model* sjt_cast15 = 0;
    sjs_shader* sjt_copy12;
    sjs_texture* sjt_copy13;
    sjs_leafpanel* sjt_dot1329;
    sjs_leafpanel* sjt_dot1330;
    sjs_leafpanel* sjt_dot1331;
    sjs_leafpanel* sjt_dot1332;
    float sjt_functionParam215;
    float sjt_functionParam216;
    float sjt_functionParam217;
    float sjt_functionParam218;
    float sjt_functionParam219;
    float sjt_functionParam220;
    float sjt_functionParam221;
    float sjt_functionParam222;
    float sjt_functionParam223;
    float sjt_functionParam224;
    float sjt_functionParam225;
    float sjt_functionParam226;
    float sjt_functionParam227;
    sjs_string* sjt_functionParam247;
    float sjt_functionParam248;
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
    sjs_string* sjt_parent93;
    float sjv_noise;
    float sjv_x;
    float sjv_y;
    float sjv_z;

    sjf_f32_random(&sjt_math2107);
    sjt_math2108 = 0.5f;
    sjv_noise = sjt_math2107 - sjt_math2108;
    sjt_dot1329 = _parent;
    sjt_math2111 = (sjt_dot1329)->_angle;
    sjt_math2112 = 2.0f;
    sjt_math2109 = sjt_math2111 * sjt_math2112;
    sjt_math2113 = sjv_noise;
    sjt_math2114 = 0.2f;
    sjt_math2110 = sjt_math2113 * sjt_math2114;
    sjv_x = sjt_math2109 + sjt_math2110;
    sjt_math2115 = sjv_noise;
    sjt_math2116 = 3.0f;
    sjv_y = sjt_math2115 * sjt_math2116;
    sjt_dot1330 = _parent;
    sjt_math2119 = (sjt_dot1330)->_angle;
    sjt_math2121 = sjv_noise;
    sjt_math2122 = 0.2f;
    sjt_math2120 = sjt_math2121 * sjt_math2122;
    sjt_functionParam215 = sjt_math2119 + sjt_math2120;
    sjf_f32_cos(sjt_functionParam215, &sjt_math2117);
    sjt_math2118 = 2.0f;
    sjv_z = sjt_math2117 * sjt_math2118;
    sjt_dot1331 = _parent;
    sjt_dot1332 = _parent;
    sjt_math2123 = (sjt_dot1332)->_angle;
    sjt_math2124 = 0.8f;
    sjt_dot1331->_angle = sjt_math2123 + sjt_math2124;
    sjt_cast15 = (sjs_model*)malloc(sizeof(sjs_model));
    sjt_cast15->_refCount = 1;
    sjt_negate13 = 1.0f;
    result15 = -sjt_negate13;
    sjt_functionParam216 = result15;
    sjt_functionParam217 = 1.0f;
    sjt_negate14 = 1.0f;
    result16 = -sjt_negate14;
    sjt_functionParam218 = result16;
    sjt_functionParam219 = 1.0f;
    sjt_functionParam220 = 0.0f;
    sjt_functionParam221 = 0.0f;
    sjt_functionParam222 = 1.0f;
    sjt_functionParam223 = 0.0f;
    sjt_functionParam224 = 1.0f;
    sjf_planevertexbuffer(sjt_functionParam216, sjt_functionParam217, sjt_functionParam218, sjt_functionParam219, sjt_functionParam220, sjt_functionParam221, sjt_functionParam222, sjt_functionParam223, sjt_functionParam224, &sjt_cast15->vertexbuffer);
    sjt_copy12 = &sjv_phongtextureshader;
    sjt_cast15->shader._refCount = 1;
    sjf_shader_copy(&sjt_cast15->shader, sjt_copy12);
    sjt_copy13 = texture;
    sjt_cast15->texture._refCount = 1;
    sjf_texture_copy(&sjt_cast15->texture, sjt_copy13);
    sjt_functionParam225 = sjv_x;
    sjt_functionParam226 = sjv_y;
    sjt_functionParam227 = sjv_z;
    sjf_mat4_translate(sjt_functionParam225, sjt_functionParam226, sjt_functionParam227, &sjt_cast15->model);
    sjt_cast15->center._refCount = 1;
    sjt_cast15->center.x = 0.0f;
    sjt_cast15->center.y = 0.0f;
    sjt_cast15->center.z = 0.0f;
    sjf_vec3(&sjt_cast15->center);
    sjt_cast15->hasalpha = true;
    sjt_call35._refCount = 1;
    sjt_call35.count = 4;
    sjt_call35.data._refCount = 1;
    sjt_call35.data.datasize = 5;
    sjt_call35.data.data = (void*)sjg_string18;
    sjt_call35.data._isglobal = true;
    sjt_call35.data.count = 5;
    sjf_array_char(&sjt_call35.data);
    sjf_string(&sjt_call35);
    sjt_parent93 = &sjt_call35;
    sjt_functionParam248 = sjv_z;
    sjf_f32_tostring(sjt_functionParam248, &sjt_call36);
    sjt_functionParam247 = &sjt_call36;
    sjf_string_add(sjt_parent93, sjt_functionParam247, &sjt_cast15->id);
    sjt_cast15->_projection._refCount = 1;
    sjt_cast15->_projection.m00 = 0.0f;
    sjt_cast15->_projection.m01 = 0.0f;
    sjt_cast15->_projection.m02 = 0.0f;
    sjt_cast15->_projection.m03 = 0.0f;
    sjt_cast15->_projection.m10 = 0.0f;
    sjt_cast15->_projection.m11 = 0.0f;
    sjt_cast15->_projection.m12 = 0.0f;
    sjt_cast15->_projection.m13 = 0.0f;
    sjt_cast15->_projection.m20 = 0.0f;
    sjt_cast15->_projection.m21 = 0.0f;
    sjt_cast15->_projection.m22 = 0.0f;
    sjt_cast15->_projection.m23 = 0.0f;
    sjt_cast15->_projection.m30 = 0.0f;
    sjt_cast15->_projection.m31 = 0.0f;
    sjt_cast15->_projection.m32 = 0.0f;
    sjt_cast15->_projection.m33 = 0.0f;
    sjf_mat4(&sjt_cast15->_projection);
    sjt_cast15->_view._refCount = 1;
    sjt_cast15->_view.m00 = 0.0f;
    sjt_cast15->_view.m01 = 0.0f;
    sjt_cast15->_view.m02 = 0.0f;
    sjt_cast15->_view.m03 = 0.0f;
    sjt_cast15->_view.m10 = 0.0f;
    sjt_cast15->_view.m11 = 0.0f;
    sjt_cast15->_view.m12 = 0.0f;
    sjt_cast15->_view.m13 = 0.0f;
    sjt_cast15->_view.m20 = 0.0f;
    sjt_cast15->_view.m21 = 0.0f;
    sjt_cast15->_view.m22 = 0.0f;
    sjt_cast15->_view.m23 = 0.0f;
    sjt_cast15->_view.m30 = 0.0f;
    sjt_cast15->_view.m31 = 0.0f;
    sjt_cast15->_view.m32 = 0.0f;
    sjt_cast15->_view.m33 = 0.0f;
    sjf_mat4(&sjt_cast15->_view);
    sjt_cast15->_world._refCount = 1;
    sjt_cast15->_world.m00 = 0.0f;
    sjt_cast15->_world.m01 = 0.0f;
    sjt_cast15->_world.m02 = 0.0f;
    sjt_cast15->_world.m03 = 0.0f;
    sjt_cast15->_world.m10 = 0.0f;
    sjt_cast15->_world.m11 = 0.0f;
    sjt_cast15->_world.m12 = 0.0f;
    sjt_cast15->_world.m13 = 0.0f;
    sjt_cast15->_world.m20 = 0.0f;
    sjt_cast15->_world.m21 = 0.0f;
    sjt_cast15->_world.m22 = 0.0f;
    sjt_cast15->_world.m23 = 0.0f;
    sjt_cast15->_world.m30 = 0.0f;
    sjt_cast15->_world.m31 = 0.0f;
    sjt_cast15->_world.m32 = 0.0f;
    sjt_cast15->_world.m33 = 0.0f;
    sjf_mat4(&sjt_cast15->_world);
    sjt_cast15->_light._refCount = 1;
    sjt_cast15->_light.pos._refCount = 1;
    sjt_cast15->_light.pos.x = 1.0f;
    sjt_cast15->_light.pos.y = 1.0f;
    sjt_cast15->_light.pos.z = 1.0f;
    sjf_vec3(&sjt_cast15->_light.pos);
    sjt_cast15->_light.diffusecolor._refCount = 1;
    sjt_cast15->_light.diffusecolor.r = 0.5f;
    sjt_cast15->_light.diffusecolor.g = 0.5f;
    sjt_cast15->_light.diffusecolor.b = 0.0f;
    sjt_cast15->_light.diffusecolor.a = 1.0f;
    sjf_color(&sjt_cast15->_light.diffusecolor);
    sjt_cast15->_light.speccolor._refCount = 1;
    sjt_cast15->_light.speccolor.r = 1.0f;
    sjt_cast15->_light.speccolor.g = 1.0f;
    sjt_cast15->_light.speccolor.b = 1.0f;
    sjt_cast15->_light.speccolor.a = 1.0f;
    sjf_color(&sjt_cast15->_light.speccolor);
    sjf_light(&sjt_cast15->_light);
    sjt_cast15->_projectedcenter._refCount = 1;
    sjt_cast15->_projectedcenter.x = 0.0f;
    sjt_cast15->_projectedcenter.y = 0.0f;
    sjt_cast15->_projectedcenter.z = 0.0f;
    sjf_vec3(&sjt_cast15->_projectedcenter);
    sjf_model_heap(sjt_cast15);
    (*_return) = (sji_model*)sjf_model_heap_as_sji_model(sjt_cast15);

    sjt_cast15->_refCount--;
    if (sjt_cast15->_refCount <= 0) {
        sjf_model_destroy(sjt_cast15);
    }
    if (sjt_call35._refCount == 1) { sjf_string_destroy(&sjt_call35); }
    if (sjt_call36._refCount == 1) { sjf_string_destroy(&sjt_call36); }
}

void sjf_leafpanel_update(sjs_leafpanel* _parent, sjs_rect* scenerect, sjs_mat4* projection, sjs_mat4* view, sjs_mat4* world, sjs_light* light) {
    int32_t i;
    sjs_array_heap_model* sjt_dot1352;
    sjs_leafpanel* sjt_dot1353;
    int32_t sjt_forEnd12;
    int32_t sjt_forStart12;

    sjt_forStart12 = 0;
    sjt_dot1353 = _parent;
    sjt_dot1352 = &(sjt_dot1353)->children;
    sjt_forEnd12 = (sjt_dot1352)->count;
    i = sjt_forStart12;
    while (i < sjt_forEnd12) {
        sjs_leafpanel* sjt_dot1354;
        int32_t sjt_functionParam249;
        sjs_rect* sjt_interfaceParam11;
        sjs_mat4* sjt_interfaceParam12;
        sjs_mat4* sjt_interfaceParam13;
        sjs_mat4* sjt_interfaceParam14;
        sjs_light* sjt_interfaceParam15;
        sjs_array_heap_model* sjt_parent94;
        sji_model* sjt_parent95;
        sji_model* sjv_c = 0;

        sjt_dot1354 = _parent;
        sjt_parent94 = &(sjt_dot1354)->children;
        sjt_functionParam249 = i;
        sjf_array_heap_model_getat_heap(sjt_parent94, sjt_functionParam249, &sjv_c);
        sjt_parent95 = sjv_c;
        sjt_interfaceParam11 = scenerect;
        sjt_interfaceParam12 = projection;
        sjt_interfaceParam13 = view;
        sjt_interfaceParam14 = world;
        sjt_interfaceParam15 = light;
        sjt_parent95->update(sjt_parent95->_parent, sjt_interfaceParam11, sjt_interfaceParam12, sjt_interfaceParam13, sjt_interfaceParam14, sjt_interfaceParam15);
        i++;

        sjv_c->_refCount--;
        if (sjv_c->_refCount <= 0) {
            sji_model_destroy(sjv_c);
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

void sjf_list_heap_animation(sjs_list_heap_animation* _this) {
}

void sjf_list_heap_animation_copy(sjs_list_heap_animation* _this, sjs_list_heap_animation* _from) {
    _this->array._refCount = 1;
    sjf_array_heap_animation_copy(&_this->array, &_from->array);
}

void sjf_list_heap_animation_destroy(sjs_list_heap_animation* _this) {
}

void sjf_list_heap_animation_getat_heap(sjs_list_heap_animation* _parent, int32_t index, sji_animation** _return) {
    sjs_list_heap_animation* sjt_dot1701;
    int32_t sjt_functionParam719;
    sjs_array_heap_animation* sjt_parent241;

    sjt_dot1701 = _parent;
    sjt_parent241 = &(sjt_dot1701)->array;
    sjt_functionParam719 = index;
    sjf_array_heap_animation_getat_heap(sjt_parent241, sjt_functionParam719, _return);
}

void sjf_list_heap_animation_getcount(sjs_list_heap_animation* _parent, int32_t* _return) {
    sjs_array_heap_animation* sjt_dot1696;
    sjs_list_heap_animation* sjt_dot1697;

    sjt_dot1697 = _parent;
    sjt_dot1696 = &(sjt_dot1697)->array;
    (*_return) = (sjt_dot1696)->count;
}

void sjf_list_heap_animation_heap(sjs_list_heap_animation* _this) {
}

void sjf_list_heap_animation_removeat(sjs_list_heap_animation* _parent, int32_t index) {
    if (index < 0 || index >= _parent->array.count) {
        halt("removeAt: out of bounds %d:%d\n", index, _parent->array.count);
    }
    sji_animation** p = (sji_animation**)_parent->array.data;
    if (index != _parent->array.count - 1) {
        memcpy(p + index, p + index + 1, _parent->array.count - index - 1);
    }
    _parent->array.count--;
}

void sjf_list_heap_model(sjs_list_heap_model* _this) {
}

void sjf_list_heap_model_add(sjs_list_heap_model* _parent, sji_model* item) {
    int32_t sjt_compare43;
    int32_t sjt_compare44;
    sjs_array_heap_model* sjt_dot545;
    sjs_list_heap_model* sjt_dot546;
    sjs_array_heap_model* sjt_dot547;
    sjs_list_heap_model* sjt_dot548;
    sjs_list_heap_model* sjt_dot555;
    sjs_array_heap_model* sjt_dot556;
    sjs_list_heap_model* sjt_dot557;
    int32_t sjt_functionParam111;
    sji_model* sjt_functionParam112 = 0;
    bool sjt_ifElse13;
    sjs_array_heap_model* sjt_parent46;

    sjt_dot546 = _parent;
    sjt_dot545 = &(sjt_dot546)->array;
    sjt_compare43 = (sjt_dot545)->count;
    sjt_dot548 = _parent;
    sjt_dot547 = &(sjt_dot548)->array;
    sjt_compare44 = (sjt_dot547)->datasize;
    sjt_ifElse13 = sjt_compare43 >= sjt_compare44;
    if (sjt_ifElse13) {
        sjs_list_heap_model* sjt_dot549;
        sjs_list_heap_model* sjt_dot552;
        sjs_array_heap_model* sjt_dot553;
        sjs_list_heap_model* sjt_dot554;
        int32_t sjt_functionParam108;
        int32_t sjt_functionParam109;
        int32_t sjt_functionParam110;
        int32_t sjt_math751;
        int32_t sjt_math752;
        sjs_array_heap_model* sjt_parent45;

        sjt_dot549 = _parent;
        sjt_dot552 = _parent;
        sjt_parent45 = &(sjt_dot552)->array;
        sjt_functionParam109 = 10;
        sjt_dot554 = _parent;
        sjt_dot553 = &(sjt_dot554)->array;
        sjt_math751 = (sjt_dot553)->datasize;
        sjt_math752 = 2;
        sjt_functionParam110 = sjt_math751 * sjt_math752;
        sjf_i32_max(sjt_functionParam109, sjt_functionParam110, &sjt_functionParam108);
        sjf_array_heap_model_grow(sjt_parent45, sjt_functionParam108, &sjt_dot549->array);
    }

    sjt_dot555 = _parent;
    sjt_parent46 = &(sjt_dot555)->array;
    sjt_dot557 = _parent;
    sjt_dot556 = &(sjt_dot557)->array;
    sjt_functionParam111 = (sjt_dot556)->count;
    sjt_functionParam112 = item;
    sjt_functionParam112->_refCount++;
    sjf_array_heap_model_initat(sjt_parent46, sjt_functionParam111, sjt_functionParam112);

    sjt_functionParam112->_refCount--;
    if (sjt_functionParam112->_refCount <= 0) {
        sji_model_destroy(sjt_functionParam112);
    }
}

void sjf_list_heap_model_copy(sjs_list_heap_model* _this, sjs_list_heap_model* _from) {
    _this->array._refCount = 1;
    sjf_array_heap_model_copy(&_this->array, &_from->array);
}

void sjf_list_heap_model_destroy(sjs_list_heap_model* _this) {
}

void sjf_list_heap_model_getat_heap(sjs_list_heap_model* _parent, int32_t index, sji_model** _return) {
    sjs_list_heap_model* sjt_dot56;
    int32_t sjt_functionParam48;
    sjs_array_heap_model* sjt_parent18;

    sjt_dot56 = _parent;
    sjt_parent18 = &(sjt_dot56)->array;
    sjt_functionParam48 = index;
    sjf_array_heap_model_getat_heap(sjt_parent18, sjt_functionParam48, _return);
}

void sjf_list_heap_model_getcount(sjs_list_heap_model* _parent, int32_t* _return) {
    sjs_array_heap_model* sjt_dot54;
    sjs_list_heap_model* sjt_dot55;

    sjt_dot55 = _parent;
    sjt_dot54 = &(sjt_dot55)->array;
    (*_return) = (sjt_dot54)->count;
}

void sjf_list_heap_model_heap(sjs_list_heap_model* _this) {
}

void sjf_list_heap_model_sortcb(sjs_list_heap_model* _parent, cb_heap_model_heap_model_i32 cb) {
    sjs_list_heap_model* sjt_dot53;
    cb_heap_model_heap_model_i32 sjt_functionParam44;
    sjs_array_heap_model* sjt_parent13;

    sjt_dot53 = _parent;
    sjt_parent13 = &(sjt_dot53)->array;
    sjt_functionParam44 = cb;
    sjf_array_heap_model_sortcb(sjt_parent13, sjt_functionParam44);
}

void sjf_mainloop(void) {
    sjs_size* sjt_dot1704;
    sjs_size* sjt_dot1705;
    int32_t sjt_functionParam722;
    sjs_size* sjt_functionParam723;
    sjs_rect* sjt_interfaceParam37;
    sjs_scene2d* sjt_interfaceParam38;
    bool sjt_isEmpty20;
    int32_option sjt_isEmpty21;
    sjs_anon1* sjt_parent245;
    sjs_windowrenderer* sjt_parent246;
    sjs_scene2d* sjt_parent247;
    sjs_scene2d* sjt_parent248;
    sji_element* sjt_parent249;
    sji_element* sjt_parent250;
    sjs_windowrenderer* sjt_parent251;
    int32_option sjv_mouseeventtype;
    sjs_rect sjv_rect = { -1 };
    sjs_size sjv_size = { -1 };
    int32_t sjv_ticks;
    int32_t sjv_x;
    int32_t sjv_y;

    sjv_ticks = 0;
    sjv_ticks = SDL_GetTicks();
    sjt_parent245 = &sjv_animator;
    sjt_functionParam722 = sjv_ticks;
    sjf_anon1_nextframe(sjt_parent245, sjt_functionParam722);
    sjt_parent246 = &sjv_rootwindowrenderer;
    sjf_windowrenderer_getsize(sjt_parent246, &sjv_size);
    sjt_parent247 = &sjv_rootscene;
    sjt_functionParam723 = &sjv_size;
    sjf_scene2d_setsize(sjt_parent247, sjt_functionParam723);
    sjt_parent248 = &sjv_rootscene;
    sjf_scene2d_clear(sjt_parent248);
    sjv_rect._refCount = 1;
    sjv_rect.x = 0;
    sjv_rect.y = 0;
    sjt_dot1704 = &sjv_size;
    sjv_rect.w = (sjt_dot1704)->w;
    sjt_dot1705 = &sjv_size;
    sjv_rect.h = (sjt_dot1705)->h;
    sjf_rect(&sjv_rect);
    sjt_parent249 = sjv_root;
    sjt_interfaceParam37 = &sjv_rect;
    sjt_parent249->setrect(sjt_parent249->_parent, sjt_interfaceParam37);
    sjt_parent250 = sjv_root;
    sjt_interfaceParam38 = &sjv_rootscene;
    sjt_parent250->render(sjt_parent250->_parent, sjt_interfaceParam38);
    sjt_parent251 = &sjv_rootwindowrenderer;
    sjf_windowrenderer_present(sjt_parent251);
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
            sjv_mouseeventtype.isempty = false;
            sjv_mouseeventtype.value = sjv_mouseeventtype_down;
            sjv_x = e.button.x;
            sjv_y = e.button.y;
            break;
            case SDL_MOUSEBUTTONUP:
            printf("SDL_MOUSEBUTTONUP\n");
            sjv_mouseeventtype.isempty = false;
            sjv_mouseeventtype.value = sjv_mouseeventtype_up;
            sjv_x = e.button.x;
            sjv_y = e.button.y;
            break;
            case SDL_MOUSEMOTION:
            sjv_mouseeventtype.isempty = false;
            sjv_mouseeventtype.value = sjv_mouseeventtype_move;
            sjv_x = e.motion.x;
            sjv_y = e.motion.y;
            break;
        }
    }
    sjt_isEmpty21 = sjv_mouseeventtype;
    sjt_isEmpty20 = sjt_isEmpty21.isempty;
    if (!sjt_isEmpty20) {
        int32_t ifValue1;
        int32_option sjt_getValue2;
        bool sjt_isEmpty22;
        sji_element* sjt_isEmpty23;

        sjt_getValue2 = sjv_mouseeventtype;
        ifValue1 = sjt_getValue2.value;
        sjt_isEmpty23 = sjv_mouse_captureelement;
        sjt_isEmpty22 = (sjt_isEmpty23 == 0);
        if (!sjt_isEmpty22) {
            sji_element* ifValue2 = 0;
            sjs_mouseevent sjt_call110 = { -1 };
            sjs_mouseevent* sjt_interfaceParam39;
            sji_element* sjt_parent252;

            ifValue2 = sjv_mouse_captureelement;
            if (ifValue2 != 0) {
                ifValue2->_refCount++;
            }

            sjt_parent252 = ifValue2;
            sjt_call110._refCount = 1;
            sjt_call110.type = ifValue1;
            sjt_call110.point._refCount = 1;
            sjt_call110.point.x = sjv_x;
            sjt_call110.point.y = sjv_y;
            sjf_point(&sjt_call110.point);
            sjt_call110.iscaptured = true;
            sjf_mouseevent(&sjt_call110);
            sjt_interfaceParam39 = &sjt_call110;
            sjt_parent252->firemouseevent(sjt_parent252->_parent, sjt_interfaceParam39);

            ifValue2->_refCount--;
            if (ifValue2->_refCount <= 0) {
                sji_element_destroy(ifValue2);
            }
            if (sjt_call110._refCount == 1) { sjf_mouseevent_destroy(&sjt_call110); }
        } else {
            sjs_mouseevent sjt_call111 = { -1 };
            sjs_mouseevent* sjt_interfaceParam40;
            sji_element* sjt_parent253;

            sjt_parent253 = sjv_root;
            sjt_call111._refCount = 1;
            sjt_call111.type = ifValue1;
            sjt_call111.point._refCount = 1;
            sjt_call111.point.x = sjv_x;
            sjt_call111.point.y = sjv_y;
            sjf_point(&sjt_call111.point);
            sjt_call111.iscaptured = false;
            sjf_mouseevent(&sjt_call111);
            sjt_interfaceParam40 = &sjt_call111;
            sjt_parent253->firemouseevent(sjt_parent253->_parent, sjt_interfaceParam40);

            if (sjt_call111._refCount == 1) { sjf_mouseevent_destroy(&sjt_call111); }
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
    sjs_mat4* sjt_dot1000;
    sjs_mat4* sjt_dot1001;
    sjs_mat4* sjt_dot1002;
    sjs_mat4* sjt_dot1003;
    sjs_mat4* sjt_dot1004;
    sjs_mat4* sjt_dot1005;
    sjs_mat4* sjt_dot1006;
    sjs_mat4* sjt_dot1007;
    sjs_mat4* sjt_dot1008;
    sjs_mat4* sjt_dot913;
    sjs_mat4* sjt_dot914;
    sjs_mat4* sjt_dot915;
    sjs_mat4* sjt_dot916;
    sjs_mat4* sjt_dot917;
    sjs_mat4* sjt_dot918;
    sjs_mat4* sjt_dot919;
    sjs_mat4* sjt_dot920;
    sjs_mat4* sjt_dot921;
    sjs_mat4* sjt_dot922;
    sjs_mat4* sjt_dot923;
    sjs_mat4* sjt_dot924;
    sjs_mat4* sjt_dot925;
    sjs_mat4* sjt_dot926;
    sjs_mat4* sjt_dot927;
    sjs_mat4* sjt_dot928;
    sjs_mat4* sjt_dot929;
    sjs_mat4* sjt_dot930;
    sjs_mat4* sjt_dot931;
    sjs_mat4* sjt_dot932;
    sjs_mat4* sjt_dot933;
    sjs_mat4* sjt_dot934;
    sjs_mat4* sjt_dot935;
    sjs_mat4* sjt_dot936;
    sjs_mat4* sjt_dot937;
    sjs_mat4* sjt_dot938;
    sjs_mat4* sjt_dot939;
    sjs_mat4* sjt_dot940;
    sjs_mat4* sjt_dot941;
    sjs_mat4* sjt_dot942;
    sjs_mat4* sjt_dot943;
    sjs_mat4* sjt_dot944;
    sjs_mat4* sjt_dot945;
    sjs_mat4* sjt_dot946;
    sjs_mat4* sjt_dot947;
    sjs_mat4* sjt_dot948;
    sjs_mat4* sjt_dot949;
    sjs_mat4* sjt_dot950;
    sjs_mat4* sjt_dot951;
    sjs_mat4* sjt_dot952;
    sjs_mat4* sjt_dot953;
    sjs_mat4* sjt_dot954;
    sjs_mat4* sjt_dot955;
    sjs_mat4* sjt_dot956;
    sjs_mat4* sjt_dot957;
    sjs_mat4* sjt_dot958;
    sjs_mat4* sjt_dot959;
    sjs_mat4* sjt_dot960;
    sjs_mat4* sjt_dot961;
    sjs_mat4* sjt_dot962;
    sjs_mat4* sjt_dot963;
    sjs_mat4* sjt_dot964;
    sjs_mat4* sjt_dot965;
    sjs_mat4* sjt_dot966;
    sjs_mat4* sjt_dot967;
    sjs_mat4* sjt_dot968;
    sjs_mat4* sjt_dot969;
    sjs_mat4* sjt_dot970;
    sjs_mat4* sjt_dot971;
    sjs_mat4* sjt_dot972;
    sjs_mat4* sjt_dot973;
    sjs_mat4* sjt_dot974;
    sjs_mat4* sjt_dot975;
    sjs_mat4* sjt_dot976;
    sjs_mat4* sjt_dot977;
    sjs_mat4* sjt_dot978;
    sjs_mat4* sjt_dot979;
    sjs_mat4* sjt_dot980;
    sjs_mat4* sjt_dot981;
    sjs_mat4* sjt_dot982;
    sjs_mat4* sjt_dot983;
    sjs_mat4* sjt_dot984;
    sjs_mat4* sjt_dot985;
    sjs_mat4* sjt_dot986;
    sjs_mat4* sjt_dot987;
    sjs_mat4* sjt_dot988;
    sjs_mat4* sjt_dot989;
    sjs_mat4* sjt_dot990;
    sjs_mat4* sjt_dot991;
    sjs_mat4* sjt_dot992;
    sjs_mat4* sjt_dot993;
    sjs_mat4* sjt_dot994;
    sjs_mat4* sjt_dot995;
    sjs_mat4* sjt_dot996;
    sjs_mat4* sjt_dot997;
    sjs_mat4* sjt_dot998;
    sjs_mat4* sjt_dot999;
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

    sjt_dot913 = _parent;
    sjt_math1413 = (sjt_dot913)->m03;
    sjt_dot914 = _parent;
    sjt_math1414 = (sjt_dot914)->m12;
    sjt_math1411 = sjt_math1413 * sjt_math1414;
    sjt_dot915 = _parent;
    sjt_math1412 = (sjt_dot915)->m21;
    sjt_math1409 = sjt_math1411 * sjt_math1412;
    sjt_dot916 = _parent;
    sjt_math1410 = (sjt_dot916)->m30;
    sjt_math1407 = sjt_math1409 * sjt_math1410;
    sjt_dot917 = _parent;
    sjt_math1419 = (sjt_dot917)->m02;
    sjt_dot918 = _parent;
    sjt_math1420 = (sjt_dot918)->m13;
    sjt_math1417 = sjt_math1419 * sjt_math1420;
    sjt_dot919 = _parent;
    sjt_math1418 = (sjt_dot919)->m21;
    sjt_math1415 = sjt_math1417 * sjt_math1418;
    sjt_dot920 = _parent;
    sjt_math1416 = (sjt_dot920)->m30;
    sjt_math1408 = sjt_math1415 * sjt_math1416;
    sjt_math1405 = sjt_math1407 - sjt_math1408;
    sjt_dot921 = _parent;
    sjt_math1425 = (sjt_dot921)->m03;
    sjt_dot922 = _parent;
    sjt_math1426 = (sjt_dot922)->m11;
    sjt_math1423 = sjt_math1425 * sjt_math1426;
    sjt_dot923 = _parent;
    sjt_math1424 = (sjt_dot923)->m22;
    sjt_math1421 = sjt_math1423 * sjt_math1424;
    sjt_dot924 = _parent;
    sjt_math1422 = (sjt_dot924)->m30;
    sjt_math1406 = sjt_math1421 * sjt_math1422;
    sjt_math1403 = sjt_math1405 - sjt_math1406;
    sjt_dot925 = _parent;
    sjt_math1431 = (sjt_dot925)->m01;
    sjt_dot926 = _parent;
    sjt_math1432 = (sjt_dot926)->m13;
    sjt_math1429 = sjt_math1431 * sjt_math1432;
    sjt_dot927 = _parent;
    sjt_math1430 = (sjt_dot927)->m22;
    sjt_math1427 = sjt_math1429 * sjt_math1430;
    sjt_dot928 = _parent;
    sjt_math1428 = (sjt_dot928)->m30;
    sjt_math1404 = sjt_math1427 * sjt_math1428;
    sjt_math1401 = sjt_math1403 + sjt_math1404;
    sjt_dot929 = _parent;
    sjt_math1437 = (sjt_dot929)->m02;
    sjt_dot930 = _parent;
    sjt_math1438 = (sjt_dot930)->m11;
    sjt_math1435 = sjt_math1437 * sjt_math1438;
    sjt_dot931 = _parent;
    sjt_math1436 = (sjt_dot931)->m23;
    sjt_math1433 = sjt_math1435 * sjt_math1436;
    sjt_dot932 = _parent;
    sjt_math1434 = (sjt_dot932)->m30;
    sjt_math1402 = sjt_math1433 * sjt_math1434;
    sjt_math1399 = sjt_math1401 + sjt_math1402;
    sjt_dot933 = _parent;
    sjt_math1443 = (sjt_dot933)->m01;
    sjt_dot934 = _parent;
    sjt_math1444 = (sjt_dot934)->m12;
    sjt_math1441 = sjt_math1443 * sjt_math1444;
    sjt_dot935 = _parent;
    sjt_math1442 = (sjt_dot935)->m23;
    sjt_math1439 = sjt_math1441 * sjt_math1442;
    sjt_dot936 = _parent;
    sjt_math1440 = (sjt_dot936)->m30;
    sjt_math1400 = sjt_math1439 * sjt_math1440;
    sjt_math1397 = sjt_math1399 - sjt_math1400;
    sjt_dot937 = _parent;
    sjt_math1449 = (sjt_dot937)->m03;
    sjt_dot938 = _parent;
    sjt_math1450 = (sjt_dot938)->m12;
    sjt_math1447 = sjt_math1449 * sjt_math1450;
    sjt_dot939 = _parent;
    sjt_math1448 = (sjt_dot939)->m20;
    sjt_math1445 = sjt_math1447 * sjt_math1448;
    sjt_dot940 = _parent;
    sjt_math1446 = (sjt_dot940)->m31;
    sjt_math1398 = sjt_math1445 * sjt_math1446;
    sjt_math1395 = sjt_math1397 - sjt_math1398;
    sjt_dot941 = _parent;
    sjt_math1455 = (sjt_dot941)->m02;
    sjt_dot942 = _parent;
    sjt_math1456 = (sjt_dot942)->m13;
    sjt_math1453 = sjt_math1455 * sjt_math1456;
    sjt_dot943 = _parent;
    sjt_math1454 = (sjt_dot943)->m20;
    sjt_math1451 = sjt_math1453 * sjt_math1454;
    sjt_dot944 = _parent;
    sjt_math1452 = (sjt_dot944)->m31;
    sjt_math1396 = sjt_math1451 * sjt_math1452;
    sjt_math1393 = sjt_math1395 + sjt_math1396;
    sjt_dot945 = _parent;
    sjt_math1461 = (sjt_dot945)->m03;
    sjt_dot946 = _parent;
    sjt_math1462 = (sjt_dot946)->m10;
    sjt_math1459 = sjt_math1461 * sjt_math1462;
    sjt_dot947 = _parent;
    sjt_math1460 = (sjt_dot947)->m22;
    sjt_math1457 = sjt_math1459 * sjt_math1460;
    sjt_dot948 = _parent;
    sjt_math1458 = (sjt_dot948)->m31;
    sjt_math1394 = sjt_math1457 * sjt_math1458;
    sjt_math1391 = sjt_math1393 + sjt_math1394;
    sjt_dot949 = _parent;
    sjt_math1467 = (sjt_dot949)->m00;
    sjt_dot950 = _parent;
    sjt_math1468 = (sjt_dot950)->m13;
    sjt_math1465 = sjt_math1467 * sjt_math1468;
    sjt_dot951 = _parent;
    sjt_math1466 = (sjt_dot951)->m22;
    sjt_math1463 = sjt_math1465 * sjt_math1466;
    sjt_dot952 = _parent;
    sjt_math1464 = (sjt_dot952)->m31;
    sjt_math1392 = sjt_math1463 * sjt_math1464;
    sjt_math1389 = sjt_math1391 - sjt_math1392;
    sjt_dot953 = _parent;
    sjt_math1473 = (sjt_dot953)->m02;
    sjt_dot954 = _parent;
    sjt_math1474 = (sjt_dot954)->m10;
    sjt_math1471 = sjt_math1473 * sjt_math1474;
    sjt_dot955 = _parent;
    sjt_math1472 = (sjt_dot955)->m23;
    sjt_math1469 = sjt_math1471 * sjt_math1472;
    sjt_dot956 = _parent;
    sjt_math1470 = (sjt_dot956)->m31;
    sjt_math1390 = sjt_math1469 * sjt_math1470;
    sjt_math1387 = sjt_math1389 - sjt_math1390;
    sjt_dot957 = _parent;
    sjt_math1479 = (sjt_dot957)->m00;
    sjt_dot958 = _parent;
    sjt_math1480 = (sjt_dot958)->m12;
    sjt_math1477 = sjt_math1479 * sjt_math1480;
    sjt_dot959 = _parent;
    sjt_math1478 = (sjt_dot959)->m23;
    sjt_math1475 = sjt_math1477 * sjt_math1478;
    sjt_dot960 = _parent;
    sjt_math1476 = (sjt_dot960)->m31;
    sjt_math1388 = sjt_math1475 * sjt_math1476;
    sjt_math1385 = sjt_math1387 + sjt_math1388;
    sjt_dot961 = _parent;
    sjt_math1485 = (sjt_dot961)->m03;
    sjt_dot962 = _parent;
    sjt_math1486 = (sjt_dot962)->m11;
    sjt_math1483 = sjt_math1485 * sjt_math1486;
    sjt_dot963 = _parent;
    sjt_math1484 = (sjt_dot963)->m20;
    sjt_math1481 = sjt_math1483 * sjt_math1484;
    sjt_dot964 = _parent;
    sjt_math1482 = (sjt_dot964)->m32;
    sjt_math1386 = sjt_math1481 * sjt_math1482;
    sjt_math1383 = sjt_math1385 + sjt_math1386;
    sjt_dot965 = _parent;
    sjt_math1491 = (sjt_dot965)->m01;
    sjt_dot966 = _parent;
    sjt_math1492 = (sjt_dot966)->m13;
    sjt_math1489 = sjt_math1491 * sjt_math1492;
    sjt_dot967 = _parent;
    sjt_math1490 = (sjt_dot967)->m20;
    sjt_math1487 = sjt_math1489 * sjt_math1490;
    sjt_dot968 = _parent;
    sjt_math1488 = (sjt_dot968)->m32;
    sjt_math1384 = sjt_math1487 * sjt_math1488;
    sjt_math1381 = sjt_math1383 - sjt_math1384;
    sjt_dot969 = _parent;
    sjt_math1497 = (sjt_dot969)->m03;
    sjt_dot970 = _parent;
    sjt_math1498 = (sjt_dot970)->m10;
    sjt_math1495 = sjt_math1497 * sjt_math1498;
    sjt_dot971 = _parent;
    sjt_math1496 = (sjt_dot971)->m21;
    sjt_math1493 = sjt_math1495 * sjt_math1496;
    sjt_dot972 = _parent;
    sjt_math1494 = (sjt_dot972)->m32;
    sjt_math1382 = sjt_math1493 * sjt_math1494;
    sjt_math1379 = sjt_math1381 - sjt_math1382;
    sjt_dot973 = _parent;
    sjt_math1503 = (sjt_dot973)->m00;
    sjt_dot974 = _parent;
    sjt_math1504 = (sjt_dot974)->m13;
    sjt_math1501 = sjt_math1503 * sjt_math1504;
    sjt_dot975 = _parent;
    sjt_math1502 = (sjt_dot975)->m21;
    sjt_math1499 = sjt_math1501 * sjt_math1502;
    sjt_dot976 = _parent;
    sjt_math1500 = (sjt_dot976)->m32;
    sjt_math1380 = sjt_math1499 * sjt_math1500;
    sjt_math1377 = sjt_math1379 + sjt_math1380;
    sjt_dot977 = _parent;
    sjt_math1509 = (sjt_dot977)->m01;
    sjt_dot978 = _parent;
    sjt_math1510 = (sjt_dot978)->m10;
    sjt_math1507 = sjt_math1509 * sjt_math1510;
    sjt_dot979 = _parent;
    sjt_math1508 = (sjt_dot979)->m23;
    sjt_math1505 = sjt_math1507 * sjt_math1508;
    sjt_dot980 = _parent;
    sjt_math1506 = (sjt_dot980)->m32;
    sjt_math1378 = sjt_math1505 * sjt_math1506;
    sjt_math1375 = sjt_math1377 + sjt_math1378;
    sjt_dot981 = _parent;
    sjt_math1515 = (sjt_dot981)->m00;
    sjt_dot982 = _parent;
    sjt_math1516 = (sjt_dot982)->m11;
    sjt_math1513 = sjt_math1515 * sjt_math1516;
    sjt_dot983 = _parent;
    sjt_math1514 = (sjt_dot983)->m23;
    sjt_math1511 = sjt_math1513 * sjt_math1514;
    sjt_dot984 = _parent;
    sjt_math1512 = (sjt_dot984)->m32;
    sjt_math1376 = sjt_math1511 * sjt_math1512;
    sjt_math1373 = sjt_math1375 - sjt_math1376;
    sjt_dot985 = _parent;
    sjt_math1521 = (sjt_dot985)->m02;
    sjt_dot986 = _parent;
    sjt_math1522 = (sjt_dot986)->m11;
    sjt_math1519 = sjt_math1521 * sjt_math1522;
    sjt_dot987 = _parent;
    sjt_math1520 = (sjt_dot987)->m20;
    sjt_math1517 = sjt_math1519 * sjt_math1520;
    sjt_dot988 = _parent;
    sjt_math1518 = (sjt_dot988)->m33;
    sjt_math1374 = sjt_math1517 * sjt_math1518;
    sjt_math1371 = sjt_math1373 - sjt_math1374;
    sjt_dot989 = _parent;
    sjt_math1527 = (sjt_dot989)->m01;
    sjt_dot990 = _parent;
    sjt_math1528 = (sjt_dot990)->m12;
    sjt_math1525 = sjt_math1527 * sjt_math1528;
    sjt_dot991 = _parent;
    sjt_math1526 = (sjt_dot991)->m20;
    sjt_math1523 = sjt_math1525 * sjt_math1526;
    sjt_dot992 = _parent;
    sjt_math1524 = (sjt_dot992)->m33;
    sjt_math1372 = sjt_math1523 * sjt_math1524;
    sjt_math1369 = sjt_math1371 + sjt_math1372;
    sjt_dot993 = _parent;
    sjt_math1533 = (sjt_dot993)->m02;
    sjt_dot994 = _parent;
    sjt_math1534 = (sjt_dot994)->m10;
    sjt_math1531 = sjt_math1533 * sjt_math1534;
    sjt_dot995 = _parent;
    sjt_math1532 = (sjt_dot995)->m21;
    sjt_math1529 = sjt_math1531 * sjt_math1532;
    sjt_dot996 = _parent;
    sjt_math1530 = (sjt_dot996)->m33;
    sjt_math1370 = sjt_math1529 * sjt_math1530;
    sjt_math1367 = sjt_math1369 + sjt_math1370;
    sjt_dot997 = _parent;
    sjt_math1539 = (sjt_dot997)->m00;
    sjt_dot998 = _parent;
    sjt_math1540 = (sjt_dot998)->m12;
    sjt_math1537 = sjt_math1539 * sjt_math1540;
    sjt_dot999 = _parent;
    sjt_math1538 = (sjt_dot999)->m21;
    sjt_math1535 = sjt_math1537 * sjt_math1538;
    sjt_dot1000 = _parent;
    sjt_math1536 = (sjt_dot1000)->m33;
    sjt_math1368 = sjt_math1535 * sjt_math1536;
    sjt_math1365 = sjt_math1367 - sjt_math1368;
    sjt_dot1001 = _parent;
    sjt_math1545 = (sjt_dot1001)->m01;
    sjt_dot1002 = _parent;
    sjt_math1546 = (sjt_dot1002)->m10;
    sjt_math1543 = sjt_math1545 * sjt_math1546;
    sjt_dot1003 = _parent;
    sjt_math1544 = (sjt_dot1003)->m22;
    sjt_math1541 = sjt_math1543 * sjt_math1544;
    sjt_dot1004 = _parent;
    sjt_math1542 = (sjt_dot1004)->m33;
    sjt_math1366 = sjt_math1541 * sjt_math1542;
    sjt_math1363 = sjt_math1365 - sjt_math1366;
    sjt_dot1005 = _parent;
    sjt_math1551 = (sjt_dot1005)->m00;
    sjt_dot1006 = _parent;
    sjt_math1552 = (sjt_dot1006)->m11;
    sjt_math1549 = sjt_math1551 * sjt_math1552;
    sjt_dot1007 = _parent;
    sjt_math1550 = (sjt_dot1007)->m22;
    sjt_math1547 = sjt_math1549 * sjt_math1550;
    sjt_dot1008 = _parent;
    sjt_math1548 = (sjt_dot1008)->m33;
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
    sjs_mat4* sjt_dot593;
    sjs_mat4* sjt_dot594;
    sjs_mat4* sjt_dot595;
    sjs_mat4* sjt_dot596;
    sjs_mat4* sjt_dot597;
    sjs_mat4* sjt_dot598;
    sjs_mat4* sjt_dot599;
    sjs_mat4* sjt_dot600;
    sjs_mat4* sjt_dot601;
    sjs_mat4* sjt_dot602;
    sjs_mat4* sjt_dot603;
    sjs_mat4* sjt_dot604;
    sjs_mat4* sjt_dot605;
    sjs_mat4* sjt_dot606;
    sjs_mat4* sjt_dot607;
    sjs_mat4* sjt_dot608;
    sjs_mat4* sjt_dot609;
    sjs_mat4* sjt_dot610;
    sjs_mat4* sjt_dot611;
    sjs_mat4* sjt_dot612;
    sjs_mat4* sjt_dot613;
    sjs_mat4* sjt_dot614;
    sjs_mat4* sjt_dot615;
    sjs_mat4* sjt_dot616;
    sjs_mat4* sjt_dot617;
    sjs_mat4* sjt_dot618;
    sjs_mat4* sjt_dot619;
    sjs_mat4* sjt_dot620;
    sjs_mat4* sjt_dot621;
    sjs_mat4* sjt_dot622;
    sjs_mat4* sjt_dot623;
    sjs_mat4* sjt_dot624;
    sjs_mat4* sjt_dot625;
    sjs_mat4* sjt_dot626;
    sjs_mat4* sjt_dot627;
    sjs_mat4* sjt_dot628;
    sjs_mat4* sjt_dot629;
    sjs_mat4* sjt_dot630;
    sjs_mat4* sjt_dot631;
    sjs_mat4* sjt_dot632;
    sjs_mat4* sjt_dot633;
    sjs_mat4* sjt_dot634;
    sjs_mat4* sjt_dot635;
    sjs_mat4* sjt_dot636;
    sjs_mat4* sjt_dot637;
    sjs_mat4* sjt_dot638;
    sjs_mat4* sjt_dot639;
    sjs_mat4* sjt_dot640;
    sjs_mat4* sjt_dot641;
    sjs_mat4* sjt_dot642;
    sjs_mat4* sjt_dot643;
    sjs_mat4* sjt_dot644;
    sjs_mat4* sjt_dot645;
    sjs_mat4* sjt_dot646;
    sjs_mat4* sjt_dot647;
    sjs_mat4* sjt_dot648;
    sjs_mat4* sjt_dot649;
    sjs_mat4* sjt_dot650;
    sjs_mat4* sjt_dot651;
    sjs_mat4* sjt_dot652;
    sjs_mat4* sjt_dot653;
    sjs_mat4* sjt_dot654;
    sjs_mat4* sjt_dot655;
    sjs_mat4* sjt_dot656;
    sjs_mat4* sjt_dot657;
    sjs_mat4* sjt_dot658;
    sjs_mat4* sjt_dot659;
    sjs_mat4* sjt_dot660;
    sjs_mat4* sjt_dot661;
    sjs_mat4* sjt_dot662;
    sjs_mat4* sjt_dot663;
    sjs_mat4* sjt_dot664;
    sjs_mat4* sjt_dot665;
    sjs_mat4* sjt_dot666;
    sjs_mat4* sjt_dot667;
    sjs_mat4* sjt_dot668;
    sjs_mat4* sjt_dot669;
    sjs_mat4* sjt_dot670;
    sjs_mat4* sjt_dot671;
    sjs_mat4* sjt_dot672;
    sjs_mat4* sjt_dot673;
    sjs_mat4* sjt_dot674;
    sjs_mat4* sjt_dot675;
    sjs_mat4* sjt_dot676;
    sjs_mat4* sjt_dot677;
    sjs_mat4* sjt_dot678;
    sjs_mat4* sjt_dot679;
    sjs_mat4* sjt_dot680;
    sjs_mat4* sjt_dot681;
    sjs_mat4* sjt_dot682;
    sjs_mat4* sjt_dot683;
    sjs_mat4* sjt_dot684;
    sjs_mat4* sjt_dot685;
    sjs_mat4* sjt_dot686;
    sjs_mat4* sjt_dot687;
    sjs_mat4* sjt_dot688;
    sjs_mat4* sjt_dot689;
    sjs_mat4* sjt_dot690;
    sjs_mat4* sjt_dot691;
    sjs_mat4* sjt_dot692;
    sjs_mat4* sjt_dot693;
    sjs_mat4* sjt_dot694;
    sjs_mat4* sjt_dot695;
    sjs_mat4* sjt_dot696;
    sjs_mat4* sjt_dot697;
    sjs_mat4* sjt_dot698;
    sjs_mat4* sjt_dot699;
    sjs_mat4* sjt_dot700;
    sjs_mat4* sjt_dot701;
    sjs_mat4* sjt_dot702;
    sjs_mat4* sjt_dot703;
    sjs_mat4* sjt_dot704;
    sjs_mat4* sjt_dot705;
    sjs_mat4* sjt_dot706;
    sjs_mat4* sjt_dot707;
    sjs_mat4* sjt_dot708;
    sjs_mat4* sjt_dot709;
    sjs_mat4* sjt_dot710;
    sjs_mat4* sjt_dot711;
    sjs_mat4* sjt_dot712;
    sjs_mat4* sjt_dot713;
    sjs_mat4* sjt_dot714;
    sjs_mat4* sjt_dot715;
    sjs_mat4* sjt_dot716;
    sjs_mat4* sjt_dot717;
    sjs_mat4* sjt_dot718;
    sjs_mat4* sjt_dot719;
    sjs_mat4* sjt_dot720;
    sjs_mat4* sjt_dot721;
    sjs_mat4* sjt_dot722;
    sjs_mat4* sjt_dot723;
    sjs_mat4* sjt_dot724;
    sjs_mat4* sjt_dot725;
    sjs_mat4* sjt_dot726;
    sjs_mat4* sjt_dot727;
    sjs_mat4* sjt_dot728;
    sjs_mat4* sjt_dot729;
    sjs_mat4* sjt_dot730;
    sjs_mat4* sjt_dot731;
    sjs_mat4* sjt_dot732;
    sjs_mat4* sjt_dot733;
    sjs_mat4* sjt_dot734;
    sjs_mat4* sjt_dot735;
    sjs_mat4* sjt_dot736;
    sjs_mat4* sjt_dot737;
    sjs_mat4* sjt_dot738;
    sjs_mat4* sjt_dot739;
    sjs_mat4* sjt_dot740;
    sjs_mat4* sjt_dot741;
    sjs_mat4* sjt_dot742;
    sjs_mat4* sjt_dot743;
    sjs_mat4* sjt_dot744;
    sjs_mat4* sjt_dot745;
    sjs_mat4* sjt_dot746;
    sjs_mat4* sjt_dot747;
    sjs_mat4* sjt_dot748;
    sjs_mat4* sjt_dot749;
    sjs_mat4* sjt_dot750;
    sjs_mat4* sjt_dot751;
    sjs_mat4* sjt_dot752;
    sjs_mat4* sjt_dot753;
    sjs_mat4* sjt_dot754;
    sjs_mat4* sjt_dot755;
    sjs_mat4* sjt_dot756;
    sjs_mat4* sjt_dot757;
    sjs_mat4* sjt_dot758;
    sjs_mat4* sjt_dot759;
    sjs_mat4* sjt_dot760;
    sjs_mat4* sjt_dot761;
    sjs_mat4* sjt_dot762;
    sjs_mat4* sjt_dot763;
    sjs_mat4* sjt_dot764;
    sjs_mat4* sjt_dot765;
    sjs_mat4* sjt_dot766;
    sjs_mat4* sjt_dot767;
    sjs_mat4* sjt_dot768;
    sjs_mat4* sjt_dot769;
    sjs_mat4* sjt_dot770;
    sjs_mat4* sjt_dot771;
    sjs_mat4* sjt_dot772;
    sjs_mat4* sjt_dot773;
    sjs_mat4* sjt_dot774;
    sjs_mat4* sjt_dot775;
    sjs_mat4* sjt_dot776;
    sjs_mat4* sjt_dot777;
    sjs_mat4* sjt_dot778;
    sjs_mat4* sjt_dot779;
    sjs_mat4* sjt_dot780;
    sjs_mat4* sjt_dot781;
    sjs_mat4* sjt_dot782;
    sjs_mat4* sjt_dot783;
    sjs_mat4* sjt_dot784;
    sjs_mat4* sjt_dot785;
    sjs_mat4* sjt_dot786;
    sjs_mat4* sjt_dot787;
    sjs_mat4* sjt_dot788;
    sjs_mat4* sjt_dot789;
    sjs_mat4* sjt_dot790;
    sjs_mat4* sjt_dot791;
    sjs_mat4* sjt_dot792;
    sjs_mat4* sjt_dot793;
    sjs_mat4* sjt_dot794;
    sjs_mat4* sjt_dot795;
    sjs_mat4* sjt_dot796;
    sjs_mat4* sjt_dot797;
    sjs_mat4* sjt_dot798;
    sjs_mat4* sjt_dot799;
    sjs_mat4* sjt_dot800;
    sjs_mat4* sjt_dot801;
    sjs_mat4* sjt_dot802;
    sjs_mat4* sjt_dot803;
    sjs_mat4* sjt_dot804;
    sjs_mat4* sjt_dot805;
    sjs_mat4* sjt_dot806;
    sjs_mat4* sjt_dot807;
    sjs_mat4* sjt_dot808;
    sjs_mat4* sjt_dot809;
    sjs_mat4* sjt_dot810;
    sjs_mat4* sjt_dot811;
    sjs_mat4* sjt_dot812;
    sjs_mat4* sjt_dot813;
    sjs_mat4* sjt_dot814;
    sjs_mat4* sjt_dot815;
    sjs_mat4* sjt_dot816;
    sjs_mat4* sjt_dot817;
    sjs_mat4* sjt_dot818;
    sjs_mat4* sjt_dot819;
    sjs_mat4* sjt_dot820;
    sjs_mat4* sjt_dot821;
    sjs_mat4* sjt_dot822;
    sjs_mat4* sjt_dot823;
    sjs_mat4* sjt_dot824;
    sjs_mat4* sjt_dot825;
    sjs_mat4* sjt_dot826;
    sjs_mat4* sjt_dot827;
    sjs_mat4* sjt_dot828;
    sjs_mat4* sjt_dot829;
    sjs_mat4* sjt_dot830;
    sjs_mat4* sjt_dot831;
    sjs_mat4* sjt_dot832;
    sjs_mat4* sjt_dot833;
    sjs_mat4* sjt_dot834;
    sjs_mat4* sjt_dot835;
    sjs_mat4* sjt_dot836;
    sjs_mat4* sjt_dot837;
    sjs_mat4* sjt_dot838;
    sjs_mat4* sjt_dot839;
    sjs_mat4* sjt_dot840;
    sjs_mat4* sjt_dot841;
    sjs_mat4* sjt_dot842;
    sjs_mat4* sjt_dot843;
    sjs_mat4* sjt_dot844;
    sjs_mat4* sjt_dot845;
    sjs_mat4* sjt_dot846;
    sjs_mat4* sjt_dot847;
    sjs_mat4* sjt_dot848;
    sjs_mat4* sjt_dot849;
    sjs_mat4* sjt_dot850;
    sjs_mat4* sjt_dot851;
    sjs_mat4* sjt_dot852;
    sjs_mat4* sjt_dot853;
    sjs_mat4* sjt_dot854;
    sjs_mat4* sjt_dot855;
    sjs_mat4* sjt_dot856;
    sjs_mat4* sjt_dot857;
    sjs_mat4* sjt_dot858;
    sjs_mat4* sjt_dot859;
    sjs_mat4* sjt_dot860;
    sjs_mat4* sjt_dot861;
    sjs_mat4* sjt_dot862;
    sjs_mat4* sjt_dot863;
    sjs_mat4* sjt_dot864;
    sjs_mat4* sjt_dot865;
    sjs_mat4* sjt_dot866;
    sjs_mat4* sjt_dot867;
    sjs_mat4* sjt_dot868;
    sjs_mat4* sjt_dot869;
    sjs_mat4* sjt_dot870;
    sjs_mat4* sjt_dot871;
    sjs_mat4* sjt_dot872;
    sjs_mat4* sjt_dot873;
    sjs_mat4* sjt_dot874;
    sjs_mat4* sjt_dot875;
    sjs_mat4* sjt_dot876;
    sjs_mat4* sjt_dot877;
    sjs_mat4* sjt_dot878;
    sjs_mat4* sjt_dot879;
    sjs_mat4* sjt_dot880;
    float sjt_functionParam116;
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
    sjs_mat4* sjt_parent51;
    sjs_mat4 sjv_t = { -1 };

    sjv_t._refCount = 1;
    sjt_dot593 = _parent;
    sjt_math765 = (sjt_dot593)->m12;
    sjt_dot594 = _parent;
    sjt_math766 = (sjt_dot594)->m23;
    sjt_math763 = sjt_math765 * sjt_math766;
    sjt_dot595 = _parent;
    sjt_math764 = (sjt_dot595)->m31;
    sjt_math761 = sjt_math763 * sjt_math764;
    sjt_dot596 = _parent;
    sjt_math769 = (sjt_dot596)->m13;
    sjt_dot597 = _parent;
    sjt_math770 = (sjt_dot597)->m22;
    sjt_math767 = sjt_math769 * sjt_math770;
    sjt_dot598 = _parent;
    sjt_math768 = (sjt_dot598)->m31;
    sjt_math762 = sjt_math767 * sjt_math768;
    sjt_math759 = sjt_math761 - sjt_math762;
    sjt_dot599 = _parent;
    sjt_math773 = (sjt_dot599)->m13;
    sjt_dot600 = _parent;
    sjt_math774 = (sjt_dot600)->m21;
    sjt_math771 = sjt_math773 * sjt_math774;
    sjt_dot601 = _parent;
    sjt_math772 = (sjt_dot601)->m32;
    sjt_math760 = sjt_math771 * sjt_math772;
    sjt_math757 = sjt_math759 + sjt_math760;
    sjt_dot602 = _parent;
    sjt_math777 = (sjt_dot602)->m11;
    sjt_dot603 = _parent;
    sjt_math778 = (sjt_dot603)->m23;
    sjt_math775 = sjt_math777 * sjt_math778;
    sjt_dot604 = _parent;
    sjt_math776 = (sjt_dot604)->m32;
    sjt_math758 = sjt_math775 * sjt_math776;
    sjt_math755 = sjt_math757 - sjt_math758;
    sjt_dot605 = _parent;
    sjt_math781 = (sjt_dot605)->m12;
    sjt_dot606 = _parent;
    sjt_math782 = (sjt_dot606)->m21;
    sjt_math779 = sjt_math781 * sjt_math782;
    sjt_dot607 = _parent;
    sjt_math780 = (sjt_dot607)->m33;
    sjt_math756 = sjt_math779 * sjt_math780;
    sjt_math753 = sjt_math755 - sjt_math756;
    sjt_dot608 = _parent;
    sjt_math785 = (sjt_dot608)->m11;
    sjt_dot609 = _parent;
    sjt_math786 = (sjt_dot609)->m22;
    sjt_math783 = sjt_math785 * sjt_math786;
    sjt_dot610 = _parent;
    sjt_math784 = (sjt_dot610)->m33;
    sjt_math754 = sjt_math783 * sjt_math784;
    sjv_t.m00 = sjt_math753 + sjt_math754;
    sjt_dot611 = _parent;
    sjt_math799 = (sjt_dot611)->m03;
    sjt_dot612 = _parent;
    sjt_math800 = (sjt_dot612)->m22;
    sjt_math797 = sjt_math799 * sjt_math800;
    sjt_dot613 = _parent;
    sjt_math798 = (sjt_dot613)->m31;
    sjt_math795 = sjt_math797 * sjt_math798;
    sjt_dot614 = _parent;
    sjt_math803 = (sjt_dot614)->m02;
    sjt_dot615 = _parent;
    sjt_math804 = (sjt_dot615)->m23;
    sjt_math801 = sjt_math803 * sjt_math804;
    sjt_dot616 = _parent;
    sjt_math802 = (sjt_dot616)->m31;
    sjt_math796 = sjt_math801 * sjt_math802;
    sjt_math793 = sjt_math795 - sjt_math796;
    sjt_dot617 = _parent;
    sjt_math807 = (sjt_dot617)->m03;
    sjt_dot618 = _parent;
    sjt_math808 = (sjt_dot618)->m21;
    sjt_math805 = sjt_math807 * sjt_math808;
    sjt_dot619 = _parent;
    sjt_math806 = (sjt_dot619)->m32;
    sjt_math794 = sjt_math805 * sjt_math806;
    sjt_math791 = sjt_math793 - sjt_math794;
    sjt_dot620 = _parent;
    sjt_math811 = (sjt_dot620)->m01;
    sjt_dot621 = _parent;
    sjt_math812 = (sjt_dot621)->m23;
    sjt_math809 = sjt_math811 * sjt_math812;
    sjt_dot622 = _parent;
    sjt_math810 = (sjt_dot622)->m32;
    sjt_math792 = sjt_math809 * sjt_math810;
    sjt_math789 = sjt_math791 + sjt_math792;
    sjt_dot623 = _parent;
    sjt_math815 = (sjt_dot623)->m02;
    sjt_dot624 = _parent;
    sjt_math816 = (sjt_dot624)->m21;
    sjt_math813 = sjt_math815 * sjt_math816;
    sjt_dot625 = _parent;
    sjt_math814 = (sjt_dot625)->m33;
    sjt_math790 = sjt_math813 * sjt_math814;
    sjt_math787 = sjt_math789 + sjt_math790;
    sjt_dot626 = _parent;
    sjt_math819 = (sjt_dot626)->m01;
    sjt_dot627 = _parent;
    sjt_math820 = (sjt_dot627)->m22;
    sjt_math817 = sjt_math819 * sjt_math820;
    sjt_dot628 = _parent;
    sjt_math818 = (sjt_dot628)->m33;
    sjt_math788 = sjt_math817 * sjt_math818;
    sjv_t.m01 = sjt_math787 - sjt_math788;
    sjt_dot629 = _parent;
    sjt_math833 = (sjt_dot629)->m02;
    sjt_dot630 = _parent;
    sjt_math834 = (sjt_dot630)->m13;
    sjt_math831 = sjt_math833 * sjt_math834;
    sjt_dot631 = _parent;
    sjt_math832 = (sjt_dot631)->m31;
    sjt_math829 = sjt_math831 * sjt_math832;
    sjt_dot632 = _parent;
    sjt_math837 = (sjt_dot632)->m03;
    sjt_dot633 = _parent;
    sjt_math838 = (sjt_dot633)->m12;
    sjt_math835 = sjt_math837 * sjt_math838;
    sjt_dot634 = _parent;
    sjt_math836 = (sjt_dot634)->m31;
    sjt_math830 = sjt_math835 * sjt_math836;
    sjt_math827 = sjt_math829 - sjt_math830;
    sjt_dot635 = _parent;
    sjt_math841 = (sjt_dot635)->m03;
    sjt_dot636 = _parent;
    sjt_math842 = (sjt_dot636)->m11;
    sjt_math839 = sjt_math841 * sjt_math842;
    sjt_dot637 = _parent;
    sjt_math840 = (sjt_dot637)->m32;
    sjt_math828 = sjt_math839 * sjt_math840;
    sjt_math825 = sjt_math827 + sjt_math828;
    sjt_dot638 = _parent;
    sjt_math845 = (sjt_dot638)->m01;
    sjt_dot639 = _parent;
    sjt_math846 = (sjt_dot639)->m13;
    sjt_math843 = sjt_math845 * sjt_math846;
    sjt_dot640 = _parent;
    sjt_math844 = (sjt_dot640)->m32;
    sjt_math826 = sjt_math843 * sjt_math844;
    sjt_math823 = sjt_math825 - sjt_math826;
    sjt_dot641 = _parent;
    sjt_math849 = (sjt_dot641)->m02;
    sjt_dot642 = _parent;
    sjt_math850 = (sjt_dot642)->m11;
    sjt_math847 = sjt_math849 * sjt_math850;
    sjt_dot643 = _parent;
    sjt_math848 = (sjt_dot643)->m33;
    sjt_math824 = sjt_math847 * sjt_math848;
    sjt_math821 = sjt_math823 - sjt_math824;
    sjt_dot644 = _parent;
    sjt_math853 = (sjt_dot644)->m01;
    sjt_dot645 = _parent;
    sjt_math854 = (sjt_dot645)->m12;
    sjt_math851 = sjt_math853 * sjt_math854;
    sjt_dot646 = _parent;
    sjt_math852 = (sjt_dot646)->m33;
    sjt_math822 = sjt_math851 * sjt_math852;
    sjv_t.m02 = sjt_math821 + sjt_math822;
    sjt_dot647 = _parent;
    sjt_math867 = (sjt_dot647)->m03;
    sjt_dot648 = _parent;
    sjt_math868 = (sjt_dot648)->m12;
    sjt_math865 = sjt_math867 * sjt_math868;
    sjt_dot649 = _parent;
    sjt_math866 = (sjt_dot649)->m21;
    sjt_math863 = sjt_math865 * sjt_math866;
    sjt_dot650 = _parent;
    sjt_math871 = (sjt_dot650)->m02;
    sjt_dot651 = _parent;
    sjt_math872 = (sjt_dot651)->m13;
    sjt_math869 = sjt_math871 * sjt_math872;
    sjt_dot652 = _parent;
    sjt_math870 = (sjt_dot652)->m21;
    sjt_math864 = sjt_math869 * sjt_math870;
    sjt_math861 = sjt_math863 - sjt_math864;
    sjt_dot653 = _parent;
    sjt_math875 = (sjt_dot653)->m03;
    sjt_dot654 = _parent;
    sjt_math876 = (sjt_dot654)->m11;
    sjt_math873 = sjt_math875 * sjt_math876;
    sjt_dot655 = _parent;
    sjt_math874 = (sjt_dot655)->m22;
    sjt_math862 = sjt_math873 * sjt_math874;
    sjt_math859 = sjt_math861 - sjt_math862;
    sjt_dot656 = _parent;
    sjt_math879 = (sjt_dot656)->m01;
    sjt_dot657 = _parent;
    sjt_math880 = (sjt_dot657)->m13;
    sjt_math877 = sjt_math879 * sjt_math880;
    sjt_dot658 = _parent;
    sjt_math878 = (sjt_dot658)->m22;
    sjt_math860 = sjt_math877 * sjt_math878;
    sjt_math857 = sjt_math859 + sjt_math860;
    sjt_dot659 = _parent;
    sjt_math883 = (sjt_dot659)->m02;
    sjt_dot660 = _parent;
    sjt_math884 = (sjt_dot660)->m11;
    sjt_math881 = sjt_math883 * sjt_math884;
    sjt_dot661 = _parent;
    sjt_math882 = (sjt_dot661)->m23;
    sjt_math858 = sjt_math881 * sjt_math882;
    sjt_math855 = sjt_math857 + sjt_math858;
    sjt_dot662 = _parent;
    sjt_math887 = (sjt_dot662)->m01;
    sjt_dot663 = _parent;
    sjt_math888 = (sjt_dot663)->m12;
    sjt_math885 = sjt_math887 * sjt_math888;
    sjt_dot664 = _parent;
    sjt_math886 = (sjt_dot664)->m23;
    sjt_math856 = sjt_math885 * sjt_math886;
    sjv_t.m03 = sjt_math855 - sjt_math856;
    sjt_dot665 = _parent;
    sjt_math901 = (sjt_dot665)->m13;
    sjt_dot666 = _parent;
    sjt_math902 = (sjt_dot666)->m22;
    sjt_math899 = sjt_math901 * sjt_math902;
    sjt_dot667 = _parent;
    sjt_math900 = (sjt_dot667)->m30;
    sjt_math897 = sjt_math899 * sjt_math900;
    sjt_dot668 = _parent;
    sjt_math905 = (sjt_dot668)->m12;
    sjt_dot669 = _parent;
    sjt_math906 = (sjt_dot669)->m23;
    sjt_math903 = sjt_math905 * sjt_math906;
    sjt_dot670 = _parent;
    sjt_math904 = (sjt_dot670)->m30;
    sjt_math898 = sjt_math903 * sjt_math904;
    sjt_math895 = sjt_math897 - sjt_math898;
    sjt_dot671 = _parent;
    sjt_math909 = (sjt_dot671)->m13;
    sjt_dot672 = _parent;
    sjt_math910 = (sjt_dot672)->m20;
    sjt_math907 = sjt_math909 * sjt_math910;
    sjt_dot673 = _parent;
    sjt_math908 = (sjt_dot673)->m32;
    sjt_math896 = sjt_math907 * sjt_math908;
    sjt_math893 = sjt_math895 - sjt_math896;
    sjt_dot674 = _parent;
    sjt_math913 = (sjt_dot674)->m10;
    sjt_dot675 = _parent;
    sjt_math914 = (sjt_dot675)->m23;
    sjt_math911 = sjt_math913 * sjt_math914;
    sjt_dot676 = _parent;
    sjt_math912 = (sjt_dot676)->m32;
    sjt_math894 = sjt_math911 * sjt_math912;
    sjt_math891 = sjt_math893 + sjt_math894;
    sjt_dot677 = _parent;
    sjt_math917 = (sjt_dot677)->m12;
    sjt_dot678 = _parent;
    sjt_math918 = (sjt_dot678)->m20;
    sjt_math915 = sjt_math917 * sjt_math918;
    sjt_dot679 = _parent;
    sjt_math916 = (sjt_dot679)->m33;
    sjt_math892 = sjt_math915 * sjt_math916;
    sjt_math889 = sjt_math891 + sjt_math892;
    sjt_dot680 = _parent;
    sjt_math921 = (sjt_dot680)->m10;
    sjt_dot681 = _parent;
    sjt_math922 = (sjt_dot681)->m22;
    sjt_math919 = sjt_math921 * sjt_math922;
    sjt_dot682 = _parent;
    sjt_math920 = (sjt_dot682)->m33;
    sjt_math890 = sjt_math919 * sjt_math920;
    sjv_t.m10 = sjt_math889 - sjt_math890;
    sjt_dot683 = _parent;
    sjt_math935 = (sjt_dot683)->m02;
    sjt_dot684 = _parent;
    sjt_math936 = (sjt_dot684)->m23;
    sjt_math933 = sjt_math935 * sjt_math936;
    sjt_dot685 = _parent;
    sjt_math934 = (sjt_dot685)->m30;
    sjt_math931 = sjt_math933 * sjt_math934;
    sjt_dot686 = _parent;
    sjt_math939 = (sjt_dot686)->m03;
    sjt_dot687 = _parent;
    sjt_math940 = (sjt_dot687)->m22;
    sjt_math937 = sjt_math939 * sjt_math940;
    sjt_dot688 = _parent;
    sjt_math938 = (sjt_dot688)->m30;
    sjt_math932 = sjt_math937 * sjt_math938;
    sjt_math929 = sjt_math931 - sjt_math932;
    sjt_dot689 = _parent;
    sjt_math943 = (sjt_dot689)->m03;
    sjt_dot690 = _parent;
    sjt_math944 = (sjt_dot690)->m20;
    sjt_math941 = sjt_math943 * sjt_math944;
    sjt_dot691 = _parent;
    sjt_math942 = (sjt_dot691)->m32;
    sjt_math930 = sjt_math941 * sjt_math942;
    sjt_math927 = sjt_math929 + sjt_math930;
    sjt_dot692 = _parent;
    sjt_math947 = (sjt_dot692)->m00;
    sjt_dot693 = _parent;
    sjt_math948 = (sjt_dot693)->m23;
    sjt_math945 = sjt_math947 * sjt_math948;
    sjt_dot694 = _parent;
    sjt_math946 = (sjt_dot694)->m32;
    sjt_math928 = sjt_math945 * sjt_math946;
    sjt_math925 = sjt_math927 - sjt_math928;
    sjt_dot695 = _parent;
    sjt_math951 = (sjt_dot695)->m02;
    sjt_dot696 = _parent;
    sjt_math952 = (sjt_dot696)->m20;
    sjt_math949 = sjt_math951 * sjt_math952;
    sjt_dot697 = _parent;
    sjt_math950 = (sjt_dot697)->m33;
    sjt_math926 = sjt_math949 * sjt_math950;
    sjt_math923 = sjt_math925 - sjt_math926;
    sjt_dot698 = _parent;
    sjt_math955 = (sjt_dot698)->m00;
    sjt_dot699 = _parent;
    sjt_math956 = (sjt_dot699)->m22;
    sjt_math953 = sjt_math955 * sjt_math956;
    sjt_dot700 = _parent;
    sjt_math954 = (sjt_dot700)->m33;
    sjt_math924 = sjt_math953 * sjt_math954;
    sjv_t.m11 = sjt_math923 + sjt_math924;
    sjt_dot701 = _parent;
    sjt_math969 = (sjt_dot701)->m03;
    sjt_dot702 = _parent;
    sjt_math970 = (sjt_dot702)->m12;
    sjt_math967 = sjt_math969 * sjt_math970;
    sjt_dot703 = _parent;
    sjt_math968 = (sjt_dot703)->m30;
    sjt_math965 = sjt_math967 * sjt_math968;
    sjt_dot704 = _parent;
    sjt_math973 = (sjt_dot704)->m02;
    sjt_dot705 = _parent;
    sjt_math974 = (sjt_dot705)->m13;
    sjt_math971 = sjt_math973 * sjt_math974;
    sjt_dot706 = _parent;
    sjt_math972 = (sjt_dot706)->m30;
    sjt_math966 = sjt_math971 * sjt_math972;
    sjt_math963 = sjt_math965 - sjt_math966;
    sjt_dot707 = _parent;
    sjt_math977 = (sjt_dot707)->m03;
    sjt_dot708 = _parent;
    sjt_math978 = (sjt_dot708)->m10;
    sjt_math975 = sjt_math977 * sjt_math978;
    sjt_dot709 = _parent;
    sjt_math976 = (sjt_dot709)->m32;
    sjt_math964 = sjt_math975 * sjt_math976;
    sjt_math961 = sjt_math963 - sjt_math964;
    sjt_dot710 = _parent;
    sjt_math981 = (sjt_dot710)->m00;
    sjt_dot711 = _parent;
    sjt_math982 = (sjt_dot711)->m13;
    sjt_math979 = sjt_math981 * sjt_math982;
    sjt_dot712 = _parent;
    sjt_math980 = (sjt_dot712)->m32;
    sjt_math962 = sjt_math979 * sjt_math980;
    sjt_math959 = sjt_math961 + sjt_math962;
    sjt_dot713 = _parent;
    sjt_math985 = (sjt_dot713)->m02;
    sjt_dot714 = _parent;
    sjt_math986 = (sjt_dot714)->m10;
    sjt_math983 = sjt_math985 * sjt_math986;
    sjt_dot715 = _parent;
    sjt_math984 = (sjt_dot715)->m33;
    sjt_math960 = sjt_math983 * sjt_math984;
    sjt_math957 = sjt_math959 + sjt_math960;
    sjt_dot716 = _parent;
    sjt_math989 = (sjt_dot716)->m00;
    sjt_dot717 = _parent;
    sjt_math990 = (sjt_dot717)->m12;
    sjt_math987 = sjt_math989 * sjt_math990;
    sjt_dot718 = _parent;
    sjt_math988 = (sjt_dot718)->m33;
    sjt_math958 = sjt_math987 * sjt_math988;
    sjv_t.m12 = sjt_math957 - sjt_math958;
    sjt_dot719 = _parent;
    sjt_math1003 = (sjt_dot719)->m02;
    sjt_dot720 = _parent;
    sjt_math1004 = (sjt_dot720)->m13;
    sjt_math1001 = sjt_math1003 * sjt_math1004;
    sjt_dot721 = _parent;
    sjt_math1002 = (sjt_dot721)->m20;
    sjt_math999 = sjt_math1001 * sjt_math1002;
    sjt_dot722 = _parent;
    sjt_math1007 = (sjt_dot722)->m03;
    sjt_dot723 = _parent;
    sjt_math1008 = (sjt_dot723)->m12;
    sjt_math1005 = sjt_math1007 * sjt_math1008;
    sjt_dot724 = _parent;
    sjt_math1006 = (sjt_dot724)->m20;
    sjt_math1000 = sjt_math1005 * sjt_math1006;
    sjt_math997 = sjt_math999 - sjt_math1000;
    sjt_dot725 = _parent;
    sjt_math1011 = (sjt_dot725)->m03;
    sjt_dot726 = _parent;
    sjt_math1012 = (sjt_dot726)->m10;
    sjt_math1009 = sjt_math1011 * sjt_math1012;
    sjt_dot727 = _parent;
    sjt_math1010 = (sjt_dot727)->m22;
    sjt_math998 = sjt_math1009 * sjt_math1010;
    sjt_math995 = sjt_math997 + sjt_math998;
    sjt_dot728 = _parent;
    sjt_math1015 = (sjt_dot728)->m00;
    sjt_dot729 = _parent;
    sjt_math1016 = (sjt_dot729)->m13;
    sjt_math1013 = sjt_math1015 * sjt_math1016;
    sjt_dot730 = _parent;
    sjt_math1014 = (sjt_dot730)->m22;
    sjt_math996 = sjt_math1013 * sjt_math1014;
    sjt_math993 = sjt_math995 - sjt_math996;
    sjt_dot731 = _parent;
    sjt_math1019 = (sjt_dot731)->m02;
    sjt_dot732 = _parent;
    sjt_math1020 = (sjt_dot732)->m10;
    sjt_math1017 = sjt_math1019 * sjt_math1020;
    sjt_dot733 = _parent;
    sjt_math1018 = (sjt_dot733)->m23;
    sjt_math994 = sjt_math1017 * sjt_math1018;
    sjt_math991 = sjt_math993 - sjt_math994;
    sjt_dot734 = _parent;
    sjt_math1023 = (sjt_dot734)->m00;
    sjt_dot735 = _parent;
    sjt_math1024 = (sjt_dot735)->m12;
    sjt_math1021 = sjt_math1023 * sjt_math1024;
    sjt_dot736 = _parent;
    sjt_math1022 = (sjt_dot736)->m23;
    sjt_math992 = sjt_math1021 * sjt_math1022;
    sjv_t.m13 = sjt_math991 + sjt_math992;
    sjt_dot737 = _parent;
    sjt_math1037 = (sjt_dot737)->m11;
    sjt_dot738 = _parent;
    sjt_math1038 = (sjt_dot738)->m23;
    sjt_math1035 = sjt_math1037 * sjt_math1038;
    sjt_dot739 = _parent;
    sjt_math1036 = (sjt_dot739)->m30;
    sjt_math1033 = sjt_math1035 * sjt_math1036;
    sjt_dot740 = _parent;
    sjt_math1041 = (sjt_dot740)->m13;
    sjt_dot741 = _parent;
    sjt_math1042 = (sjt_dot741)->m21;
    sjt_math1039 = sjt_math1041 * sjt_math1042;
    sjt_dot742 = _parent;
    sjt_math1040 = (sjt_dot742)->m30;
    sjt_math1034 = sjt_math1039 * sjt_math1040;
    sjt_math1031 = sjt_math1033 - sjt_math1034;
    sjt_dot743 = _parent;
    sjt_math1045 = (sjt_dot743)->m13;
    sjt_dot744 = _parent;
    sjt_math1046 = (sjt_dot744)->m20;
    sjt_math1043 = sjt_math1045 * sjt_math1046;
    sjt_dot745 = _parent;
    sjt_math1044 = (sjt_dot745)->m31;
    sjt_math1032 = sjt_math1043 * sjt_math1044;
    sjt_math1029 = sjt_math1031 + sjt_math1032;
    sjt_dot746 = _parent;
    sjt_math1049 = (sjt_dot746)->m10;
    sjt_dot747 = _parent;
    sjt_math1050 = (sjt_dot747)->m23;
    sjt_math1047 = sjt_math1049 * sjt_math1050;
    sjt_dot748 = _parent;
    sjt_math1048 = (sjt_dot748)->m31;
    sjt_math1030 = sjt_math1047 * sjt_math1048;
    sjt_math1027 = sjt_math1029 - sjt_math1030;
    sjt_dot749 = _parent;
    sjt_math1053 = (sjt_dot749)->m11;
    sjt_dot750 = _parent;
    sjt_math1054 = (sjt_dot750)->m20;
    sjt_math1051 = sjt_math1053 * sjt_math1054;
    sjt_dot751 = _parent;
    sjt_math1052 = (sjt_dot751)->m33;
    sjt_math1028 = sjt_math1051 * sjt_math1052;
    sjt_math1025 = sjt_math1027 - sjt_math1028;
    sjt_dot752 = _parent;
    sjt_math1057 = (sjt_dot752)->m10;
    sjt_dot753 = _parent;
    sjt_math1058 = (sjt_dot753)->m21;
    sjt_math1055 = sjt_math1057 * sjt_math1058;
    sjt_dot754 = _parent;
    sjt_math1056 = (sjt_dot754)->m33;
    sjt_math1026 = sjt_math1055 * sjt_math1056;
    sjv_t.m20 = sjt_math1025 + sjt_math1026;
    sjt_dot755 = _parent;
    sjt_math1071 = (sjt_dot755)->m03;
    sjt_dot756 = _parent;
    sjt_math1072 = (sjt_dot756)->m21;
    sjt_math1069 = sjt_math1071 * sjt_math1072;
    sjt_dot757 = _parent;
    sjt_math1070 = (sjt_dot757)->m30;
    sjt_math1067 = sjt_math1069 * sjt_math1070;
    sjt_dot758 = _parent;
    sjt_math1075 = (sjt_dot758)->m01;
    sjt_dot759 = _parent;
    sjt_math1076 = (sjt_dot759)->m23;
    sjt_math1073 = sjt_math1075 * sjt_math1076;
    sjt_dot760 = _parent;
    sjt_math1074 = (sjt_dot760)->m30;
    sjt_math1068 = sjt_math1073 * sjt_math1074;
    sjt_math1065 = sjt_math1067 - sjt_math1068;
    sjt_dot761 = _parent;
    sjt_math1079 = (sjt_dot761)->m03;
    sjt_dot762 = _parent;
    sjt_math1080 = (sjt_dot762)->m20;
    sjt_math1077 = sjt_math1079 * sjt_math1080;
    sjt_dot763 = _parent;
    sjt_math1078 = (sjt_dot763)->m31;
    sjt_math1066 = sjt_math1077 * sjt_math1078;
    sjt_math1063 = sjt_math1065 - sjt_math1066;
    sjt_dot764 = _parent;
    sjt_math1083 = (sjt_dot764)->m00;
    sjt_dot765 = _parent;
    sjt_math1084 = (sjt_dot765)->m23;
    sjt_math1081 = sjt_math1083 * sjt_math1084;
    sjt_dot766 = _parent;
    sjt_math1082 = (sjt_dot766)->m31;
    sjt_math1064 = sjt_math1081 * sjt_math1082;
    sjt_math1061 = sjt_math1063 + sjt_math1064;
    sjt_dot767 = _parent;
    sjt_math1087 = (sjt_dot767)->m01;
    sjt_dot768 = _parent;
    sjt_math1088 = (sjt_dot768)->m20;
    sjt_math1085 = sjt_math1087 * sjt_math1088;
    sjt_dot769 = _parent;
    sjt_math1086 = (sjt_dot769)->m33;
    sjt_math1062 = sjt_math1085 * sjt_math1086;
    sjt_math1059 = sjt_math1061 + sjt_math1062;
    sjt_dot770 = _parent;
    sjt_math1091 = (sjt_dot770)->m00;
    sjt_dot771 = _parent;
    sjt_math1092 = (sjt_dot771)->m21;
    sjt_math1089 = sjt_math1091 * sjt_math1092;
    sjt_dot772 = _parent;
    sjt_math1090 = (sjt_dot772)->m33;
    sjt_math1060 = sjt_math1089 * sjt_math1090;
    sjv_t.m21 = sjt_math1059 - sjt_math1060;
    sjt_dot773 = _parent;
    sjt_math1105 = (sjt_dot773)->m01;
    sjt_dot774 = _parent;
    sjt_math1106 = (sjt_dot774)->m13;
    sjt_math1103 = sjt_math1105 * sjt_math1106;
    sjt_dot775 = _parent;
    sjt_math1104 = (sjt_dot775)->m30;
    sjt_math1101 = sjt_math1103 * sjt_math1104;
    sjt_dot776 = _parent;
    sjt_math1109 = (sjt_dot776)->m03;
    sjt_dot777 = _parent;
    sjt_math1110 = (sjt_dot777)->m11;
    sjt_math1107 = sjt_math1109 * sjt_math1110;
    sjt_dot778 = _parent;
    sjt_math1108 = (sjt_dot778)->m30;
    sjt_math1102 = sjt_math1107 * sjt_math1108;
    sjt_math1099 = sjt_math1101 - sjt_math1102;
    sjt_dot779 = _parent;
    sjt_math1113 = (sjt_dot779)->m03;
    sjt_dot780 = _parent;
    sjt_math1114 = (sjt_dot780)->m10;
    sjt_math1111 = sjt_math1113 * sjt_math1114;
    sjt_dot781 = _parent;
    sjt_math1112 = (sjt_dot781)->m31;
    sjt_math1100 = sjt_math1111 * sjt_math1112;
    sjt_math1097 = sjt_math1099 + sjt_math1100;
    sjt_dot782 = _parent;
    sjt_math1117 = (sjt_dot782)->m00;
    sjt_dot783 = _parent;
    sjt_math1118 = (sjt_dot783)->m13;
    sjt_math1115 = sjt_math1117 * sjt_math1118;
    sjt_dot784 = _parent;
    sjt_math1116 = (sjt_dot784)->m31;
    sjt_math1098 = sjt_math1115 * sjt_math1116;
    sjt_math1095 = sjt_math1097 - sjt_math1098;
    sjt_dot785 = _parent;
    sjt_math1121 = (sjt_dot785)->m01;
    sjt_dot786 = _parent;
    sjt_math1122 = (sjt_dot786)->m10;
    sjt_math1119 = sjt_math1121 * sjt_math1122;
    sjt_dot787 = _parent;
    sjt_math1120 = (sjt_dot787)->m33;
    sjt_math1096 = sjt_math1119 * sjt_math1120;
    sjt_math1093 = sjt_math1095 - sjt_math1096;
    sjt_dot788 = _parent;
    sjt_math1125 = (sjt_dot788)->m00;
    sjt_dot789 = _parent;
    sjt_math1126 = (sjt_dot789)->m11;
    sjt_math1123 = sjt_math1125 * sjt_math1126;
    sjt_dot790 = _parent;
    sjt_math1124 = (sjt_dot790)->m33;
    sjt_math1094 = sjt_math1123 * sjt_math1124;
    sjv_t.m22 = sjt_math1093 + sjt_math1094;
    sjt_dot791 = _parent;
    sjt_math1139 = (sjt_dot791)->m03;
    sjt_dot792 = _parent;
    sjt_math1140 = (sjt_dot792)->m11;
    sjt_math1137 = sjt_math1139 * sjt_math1140;
    sjt_dot793 = _parent;
    sjt_math1138 = (sjt_dot793)->m20;
    sjt_math1135 = sjt_math1137 * sjt_math1138;
    sjt_dot794 = _parent;
    sjt_math1143 = (sjt_dot794)->m01;
    sjt_dot795 = _parent;
    sjt_math1144 = (sjt_dot795)->m13;
    sjt_math1141 = sjt_math1143 * sjt_math1144;
    sjt_dot796 = _parent;
    sjt_math1142 = (sjt_dot796)->m20;
    sjt_math1136 = sjt_math1141 * sjt_math1142;
    sjt_math1133 = sjt_math1135 - sjt_math1136;
    sjt_dot797 = _parent;
    sjt_math1147 = (sjt_dot797)->m03;
    sjt_dot798 = _parent;
    sjt_math1148 = (sjt_dot798)->m10;
    sjt_math1145 = sjt_math1147 * sjt_math1148;
    sjt_dot799 = _parent;
    sjt_math1146 = (sjt_dot799)->m21;
    sjt_math1134 = sjt_math1145 * sjt_math1146;
    sjt_math1131 = sjt_math1133 - sjt_math1134;
    sjt_dot800 = _parent;
    sjt_math1151 = (sjt_dot800)->m00;
    sjt_dot801 = _parent;
    sjt_math1152 = (sjt_dot801)->m13;
    sjt_math1149 = sjt_math1151 * sjt_math1152;
    sjt_dot802 = _parent;
    sjt_math1150 = (sjt_dot802)->m21;
    sjt_math1132 = sjt_math1149 * sjt_math1150;
    sjt_math1129 = sjt_math1131 + sjt_math1132;
    sjt_dot803 = _parent;
    sjt_math1155 = (sjt_dot803)->m01;
    sjt_dot804 = _parent;
    sjt_math1156 = (sjt_dot804)->m10;
    sjt_math1153 = sjt_math1155 * sjt_math1156;
    sjt_dot805 = _parent;
    sjt_math1154 = (sjt_dot805)->m23;
    sjt_math1130 = sjt_math1153 * sjt_math1154;
    sjt_math1127 = sjt_math1129 + sjt_math1130;
    sjt_dot806 = _parent;
    sjt_math1159 = (sjt_dot806)->m00;
    sjt_dot807 = _parent;
    sjt_math1160 = (sjt_dot807)->m11;
    sjt_math1157 = sjt_math1159 * sjt_math1160;
    sjt_dot808 = _parent;
    sjt_math1158 = (sjt_dot808)->m23;
    sjt_math1128 = sjt_math1157 * sjt_math1158;
    sjv_t.m23 = sjt_math1127 - sjt_math1128;
    sjt_dot809 = _parent;
    sjt_math1173 = (sjt_dot809)->m12;
    sjt_dot810 = _parent;
    sjt_math1174 = (sjt_dot810)->m21;
    sjt_math1171 = sjt_math1173 * sjt_math1174;
    sjt_dot811 = _parent;
    sjt_math1172 = (sjt_dot811)->m30;
    sjt_math1169 = sjt_math1171 * sjt_math1172;
    sjt_dot812 = _parent;
    sjt_math1177 = (sjt_dot812)->m11;
    sjt_dot813 = _parent;
    sjt_math1178 = (sjt_dot813)->m22;
    sjt_math1175 = sjt_math1177 * sjt_math1178;
    sjt_dot814 = _parent;
    sjt_math1176 = (sjt_dot814)->m30;
    sjt_math1170 = sjt_math1175 * sjt_math1176;
    sjt_math1167 = sjt_math1169 - sjt_math1170;
    sjt_dot815 = _parent;
    sjt_math1181 = (sjt_dot815)->m12;
    sjt_dot816 = _parent;
    sjt_math1182 = (sjt_dot816)->m20;
    sjt_math1179 = sjt_math1181 * sjt_math1182;
    sjt_dot817 = _parent;
    sjt_math1180 = (sjt_dot817)->m31;
    sjt_math1168 = sjt_math1179 * sjt_math1180;
    sjt_math1165 = sjt_math1167 - sjt_math1168;
    sjt_dot818 = _parent;
    sjt_math1185 = (sjt_dot818)->m10;
    sjt_dot819 = _parent;
    sjt_math1186 = (sjt_dot819)->m22;
    sjt_math1183 = sjt_math1185 * sjt_math1186;
    sjt_dot820 = _parent;
    sjt_math1184 = (sjt_dot820)->m31;
    sjt_math1166 = sjt_math1183 * sjt_math1184;
    sjt_math1163 = sjt_math1165 + sjt_math1166;
    sjt_dot821 = _parent;
    sjt_math1189 = (sjt_dot821)->m11;
    sjt_dot822 = _parent;
    sjt_math1190 = (sjt_dot822)->m20;
    sjt_math1187 = sjt_math1189 * sjt_math1190;
    sjt_dot823 = _parent;
    sjt_math1188 = (sjt_dot823)->m32;
    sjt_math1164 = sjt_math1187 * sjt_math1188;
    sjt_math1161 = sjt_math1163 + sjt_math1164;
    sjt_dot824 = _parent;
    sjt_math1193 = (sjt_dot824)->m10;
    sjt_dot825 = _parent;
    sjt_math1194 = (sjt_dot825)->m21;
    sjt_math1191 = sjt_math1193 * sjt_math1194;
    sjt_dot826 = _parent;
    sjt_math1192 = (sjt_dot826)->m32;
    sjt_math1162 = sjt_math1191 * sjt_math1192;
    sjv_t.m30 = sjt_math1161 - sjt_math1162;
    sjt_dot827 = _parent;
    sjt_math1207 = (sjt_dot827)->m01;
    sjt_dot828 = _parent;
    sjt_math1208 = (sjt_dot828)->m22;
    sjt_math1205 = sjt_math1207 * sjt_math1208;
    sjt_dot829 = _parent;
    sjt_math1206 = (sjt_dot829)->m30;
    sjt_math1203 = sjt_math1205 * sjt_math1206;
    sjt_dot830 = _parent;
    sjt_math1211 = (sjt_dot830)->m02;
    sjt_dot831 = _parent;
    sjt_math1212 = (sjt_dot831)->m21;
    sjt_math1209 = sjt_math1211 * sjt_math1212;
    sjt_dot832 = _parent;
    sjt_math1210 = (sjt_dot832)->m30;
    sjt_math1204 = sjt_math1209 * sjt_math1210;
    sjt_math1201 = sjt_math1203 - sjt_math1204;
    sjt_dot833 = _parent;
    sjt_math1215 = (sjt_dot833)->m02;
    sjt_dot834 = _parent;
    sjt_math1216 = (sjt_dot834)->m20;
    sjt_math1213 = sjt_math1215 * sjt_math1216;
    sjt_dot835 = _parent;
    sjt_math1214 = (sjt_dot835)->m31;
    sjt_math1202 = sjt_math1213 * sjt_math1214;
    sjt_math1199 = sjt_math1201 + sjt_math1202;
    sjt_dot836 = _parent;
    sjt_math1219 = (sjt_dot836)->m00;
    sjt_dot837 = _parent;
    sjt_math1220 = (sjt_dot837)->m22;
    sjt_math1217 = sjt_math1219 * sjt_math1220;
    sjt_dot838 = _parent;
    sjt_math1218 = (sjt_dot838)->m31;
    sjt_math1200 = sjt_math1217 * sjt_math1218;
    sjt_math1197 = sjt_math1199 - sjt_math1200;
    sjt_dot839 = _parent;
    sjt_math1223 = (sjt_dot839)->m01;
    sjt_dot840 = _parent;
    sjt_math1224 = (sjt_dot840)->m20;
    sjt_math1221 = sjt_math1223 * sjt_math1224;
    sjt_dot841 = _parent;
    sjt_math1222 = (sjt_dot841)->m32;
    sjt_math1198 = sjt_math1221 * sjt_math1222;
    sjt_math1195 = sjt_math1197 - sjt_math1198;
    sjt_dot842 = _parent;
    sjt_math1227 = (sjt_dot842)->m00;
    sjt_dot843 = _parent;
    sjt_math1228 = (sjt_dot843)->m21;
    sjt_math1225 = sjt_math1227 * sjt_math1228;
    sjt_dot844 = _parent;
    sjt_math1226 = (sjt_dot844)->m32;
    sjt_math1196 = sjt_math1225 * sjt_math1226;
    sjv_t.m31 = sjt_math1195 + sjt_math1196;
    sjt_dot845 = _parent;
    sjt_math1241 = (sjt_dot845)->m02;
    sjt_dot846 = _parent;
    sjt_math1242 = (sjt_dot846)->m11;
    sjt_math1239 = sjt_math1241 * sjt_math1242;
    sjt_dot847 = _parent;
    sjt_math1240 = (sjt_dot847)->m30;
    sjt_math1237 = sjt_math1239 * sjt_math1240;
    sjt_dot848 = _parent;
    sjt_math1245 = (sjt_dot848)->m01;
    sjt_dot849 = _parent;
    sjt_math1246 = (sjt_dot849)->m12;
    sjt_math1243 = sjt_math1245 * sjt_math1246;
    sjt_dot850 = _parent;
    sjt_math1244 = (sjt_dot850)->m30;
    sjt_math1238 = sjt_math1243 * sjt_math1244;
    sjt_math1235 = sjt_math1237 - sjt_math1238;
    sjt_dot851 = _parent;
    sjt_math1249 = (sjt_dot851)->m02;
    sjt_dot852 = _parent;
    sjt_math1250 = (sjt_dot852)->m10;
    sjt_math1247 = sjt_math1249 * sjt_math1250;
    sjt_dot853 = _parent;
    sjt_math1248 = (sjt_dot853)->m31;
    sjt_math1236 = sjt_math1247 * sjt_math1248;
    sjt_math1233 = sjt_math1235 - sjt_math1236;
    sjt_dot854 = _parent;
    sjt_math1253 = (sjt_dot854)->m00;
    sjt_dot855 = _parent;
    sjt_math1254 = (sjt_dot855)->m12;
    sjt_math1251 = sjt_math1253 * sjt_math1254;
    sjt_dot856 = _parent;
    sjt_math1252 = (sjt_dot856)->m31;
    sjt_math1234 = sjt_math1251 * sjt_math1252;
    sjt_math1231 = sjt_math1233 + sjt_math1234;
    sjt_dot857 = _parent;
    sjt_math1257 = (sjt_dot857)->m01;
    sjt_dot858 = _parent;
    sjt_math1258 = (sjt_dot858)->m10;
    sjt_math1255 = sjt_math1257 * sjt_math1258;
    sjt_dot859 = _parent;
    sjt_math1256 = (sjt_dot859)->m32;
    sjt_math1232 = sjt_math1255 * sjt_math1256;
    sjt_math1229 = sjt_math1231 + sjt_math1232;
    sjt_dot860 = _parent;
    sjt_math1261 = (sjt_dot860)->m00;
    sjt_dot861 = _parent;
    sjt_math1262 = (sjt_dot861)->m11;
    sjt_math1259 = sjt_math1261 * sjt_math1262;
    sjt_dot862 = _parent;
    sjt_math1260 = (sjt_dot862)->m32;
    sjt_math1230 = sjt_math1259 * sjt_math1260;
    sjv_t.m32 = sjt_math1229 - sjt_math1230;
    sjt_dot863 = _parent;
    sjt_math1275 = (sjt_dot863)->m01;
    sjt_dot864 = _parent;
    sjt_math1276 = (sjt_dot864)->m12;
    sjt_math1273 = sjt_math1275 * sjt_math1276;
    sjt_dot865 = _parent;
    sjt_math1274 = (sjt_dot865)->m20;
    sjt_math1271 = sjt_math1273 * sjt_math1274;
    sjt_dot866 = _parent;
    sjt_math1279 = (sjt_dot866)->m02;
    sjt_dot867 = _parent;
    sjt_math1280 = (sjt_dot867)->m11;
    sjt_math1277 = sjt_math1279 * sjt_math1280;
    sjt_dot868 = _parent;
    sjt_math1278 = (sjt_dot868)->m20;
    sjt_math1272 = sjt_math1277 * sjt_math1278;
    sjt_math1269 = sjt_math1271 - sjt_math1272;
    sjt_dot869 = _parent;
    sjt_math1283 = (sjt_dot869)->m02;
    sjt_dot870 = _parent;
    sjt_math1284 = (sjt_dot870)->m10;
    sjt_math1281 = sjt_math1283 * sjt_math1284;
    sjt_dot871 = _parent;
    sjt_math1282 = (sjt_dot871)->m21;
    sjt_math1270 = sjt_math1281 * sjt_math1282;
    sjt_math1267 = sjt_math1269 + sjt_math1270;
    sjt_dot872 = _parent;
    sjt_math1287 = (sjt_dot872)->m00;
    sjt_dot873 = _parent;
    sjt_math1288 = (sjt_dot873)->m12;
    sjt_math1285 = sjt_math1287 * sjt_math1288;
    sjt_dot874 = _parent;
    sjt_math1286 = (sjt_dot874)->m21;
    sjt_math1268 = sjt_math1285 * sjt_math1286;
    sjt_math1265 = sjt_math1267 - sjt_math1268;
    sjt_dot875 = _parent;
    sjt_math1291 = (sjt_dot875)->m01;
    sjt_dot876 = _parent;
    sjt_math1292 = (sjt_dot876)->m10;
    sjt_math1289 = sjt_math1291 * sjt_math1292;
    sjt_dot877 = _parent;
    sjt_math1290 = (sjt_dot877)->m22;
    sjt_math1266 = sjt_math1289 * sjt_math1290;
    sjt_math1263 = sjt_math1265 - sjt_math1266;
    sjt_dot878 = _parent;
    sjt_math1295 = (sjt_dot878)->m00;
    sjt_dot879 = _parent;
    sjt_math1296 = (sjt_dot879)->m11;
    sjt_math1293 = sjt_math1295 * sjt_math1296;
    sjt_dot880 = _parent;
    sjt_math1294 = (sjt_dot880)->m22;
    sjt_math1264 = sjt_math1293 * sjt_math1294;
    sjv_t.m33 = sjt_math1263 + sjt_math1264;
    sjf_mat4(&sjv_t);
    sjt_parent51 = &sjv_t;
    sjt_math1361 = 1.0f;
    sjf_mat4_determinant(_parent, &sjt_math1362);
    sjt_functionParam116 = sjt_math1361 / sjt_math1362;
    sjf_mat4_multiplyf32(sjt_parent51, sjt_functionParam116, _return);

    if (sjv_t._refCount == 1) { sjf_mat4_destroy(&sjv_t); }
}

void sjf_mat4_invert_heap(sjs_mat4* _parent, sjs_mat4** _return) {
    sjs_mat4* sjt_dot1009;
    sjs_mat4* sjt_dot1010;
    sjs_mat4* sjt_dot1011;
    sjs_mat4* sjt_dot1012;
    sjs_mat4* sjt_dot1013;
    sjs_mat4* sjt_dot1014;
    sjs_mat4* sjt_dot1015;
    sjs_mat4* sjt_dot1016;
    sjs_mat4* sjt_dot1017;
    sjs_mat4* sjt_dot1018;
    sjs_mat4* sjt_dot1019;
    sjs_mat4* sjt_dot1020;
    sjs_mat4* sjt_dot1021;
    sjs_mat4* sjt_dot1022;
    sjs_mat4* sjt_dot1023;
    sjs_mat4* sjt_dot1024;
    sjs_mat4* sjt_dot1025;
    sjs_mat4* sjt_dot1026;
    sjs_mat4* sjt_dot1027;
    sjs_mat4* sjt_dot1028;
    sjs_mat4* sjt_dot1029;
    sjs_mat4* sjt_dot1030;
    sjs_mat4* sjt_dot1031;
    sjs_mat4* sjt_dot1032;
    sjs_mat4* sjt_dot1033;
    sjs_mat4* sjt_dot1034;
    sjs_mat4* sjt_dot1035;
    sjs_mat4* sjt_dot1036;
    sjs_mat4* sjt_dot1037;
    sjs_mat4* sjt_dot1038;
    sjs_mat4* sjt_dot1039;
    sjs_mat4* sjt_dot1040;
    sjs_mat4* sjt_dot1041;
    sjs_mat4* sjt_dot1042;
    sjs_mat4* sjt_dot1043;
    sjs_mat4* sjt_dot1044;
    sjs_mat4* sjt_dot1045;
    sjs_mat4* sjt_dot1046;
    sjs_mat4* sjt_dot1047;
    sjs_mat4* sjt_dot1048;
    sjs_mat4* sjt_dot1049;
    sjs_mat4* sjt_dot1050;
    sjs_mat4* sjt_dot1051;
    sjs_mat4* sjt_dot1052;
    sjs_mat4* sjt_dot1053;
    sjs_mat4* sjt_dot1054;
    sjs_mat4* sjt_dot1055;
    sjs_mat4* sjt_dot1056;
    sjs_mat4* sjt_dot1057;
    sjs_mat4* sjt_dot1058;
    sjs_mat4* sjt_dot1059;
    sjs_mat4* sjt_dot1060;
    sjs_mat4* sjt_dot1061;
    sjs_mat4* sjt_dot1062;
    sjs_mat4* sjt_dot1063;
    sjs_mat4* sjt_dot1064;
    sjs_mat4* sjt_dot1065;
    sjs_mat4* sjt_dot1066;
    sjs_mat4* sjt_dot1067;
    sjs_mat4* sjt_dot1068;
    sjs_mat4* sjt_dot1069;
    sjs_mat4* sjt_dot1070;
    sjs_mat4* sjt_dot1071;
    sjs_mat4* sjt_dot1072;
    sjs_mat4* sjt_dot1073;
    sjs_mat4* sjt_dot1074;
    sjs_mat4* sjt_dot1075;
    sjs_mat4* sjt_dot1076;
    sjs_mat4* sjt_dot1077;
    sjs_mat4* sjt_dot1078;
    sjs_mat4* sjt_dot1079;
    sjs_mat4* sjt_dot1080;
    sjs_mat4* sjt_dot1081;
    sjs_mat4* sjt_dot1082;
    sjs_mat4* sjt_dot1083;
    sjs_mat4* sjt_dot1084;
    sjs_mat4* sjt_dot1085;
    sjs_mat4* sjt_dot1086;
    sjs_mat4* sjt_dot1087;
    sjs_mat4* sjt_dot1088;
    sjs_mat4* sjt_dot1089;
    sjs_mat4* sjt_dot1090;
    sjs_mat4* sjt_dot1091;
    sjs_mat4* sjt_dot1092;
    sjs_mat4* sjt_dot1093;
    sjs_mat4* sjt_dot1094;
    sjs_mat4* sjt_dot1095;
    sjs_mat4* sjt_dot1096;
    sjs_mat4* sjt_dot1097;
    sjs_mat4* sjt_dot1098;
    sjs_mat4* sjt_dot1099;
    sjs_mat4* sjt_dot1100;
    sjs_mat4* sjt_dot1101;
    sjs_mat4* sjt_dot1102;
    sjs_mat4* sjt_dot1103;
    sjs_mat4* sjt_dot1104;
    sjs_mat4* sjt_dot1105;
    sjs_mat4* sjt_dot1106;
    sjs_mat4* sjt_dot1107;
    sjs_mat4* sjt_dot1108;
    sjs_mat4* sjt_dot1109;
    sjs_mat4* sjt_dot1110;
    sjs_mat4* sjt_dot1111;
    sjs_mat4* sjt_dot1112;
    sjs_mat4* sjt_dot1113;
    sjs_mat4* sjt_dot1114;
    sjs_mat4* sjt_dot1115;
    sjs_mat4* sjt_dot1116;
    sjs_mat4* sjt_dot1117;
    sjs_mat4* sjt_dot1118;
    sjs_mat4* sjt_dot1119;
    sjs_mat4* sjt_dot1120;
    sjs_mat4* sjt_dot1121;
    sjs_mat4* sjt_dot1122;
    sjs_mat4* sjt_dot1123;
    sjs_mat4* sjt_dot1124;
    sjs_mat4* sjt_dot1125;
    sjs_mat4* sjt_dot1126;
    sjs_mat4* sjt_dot1127;
    sjs_mat4* sjt_dot1128;
    sjs_mat4* sjt_dot1129;
    sjs_mat4* sjt_dot1130;
    sjs_mat4* sjt_dot1131;
    sjs_mat4* sjt_dot1132;
    sjs_mat4* sjt_dot1133;
    sjs_mat4* sjt_dot1134;
    sjs_mat4* sjt_dot1135;
    sjs_mat4* sjt_dot1136;
    sjs_mat4* sjt_dot1137;
    sjs_mat4* sjt_dot1138;
    sjs_mat4* sjt_dot1139;
    sjs_mat4* sjt_dot1140;
    sjs_mat4* sjt_dot1141;
    sjs_mat4* sjt_dot1142;
    sjs_mat4* sjt_dot1143;
    sjs_mat4* sjt_dot1144;
    sjs_mat4* sjt_dot1145;
    sjs_mat4* sjt_dot1146;
    sjs_mat4* sjt_dot1147;
    sjs_mat4* sjt_dot1148;
    sjs_mat4* sjt_dot1149;
    sjs_mat4* sjt_dot1150;
    sjs_mat4* sjt_dot1151;
    sjs_mat4* sjt_dot1152;
    sjs_mat4* sjt_dot1153;
    sjs_mat4* sjt_dot1154;
    sjs_mat4* sjt_dot1155;
    sjs_mat4* sjt_dot1156;
    sjs_mat4* sjt_dot1157;
    sjs_mat4* sjt_dot1158;
    sjs_mat4* sjt_dot1159;
    sjs_mat4* sjt_dot1160;
    sjs_mat4* sjt_dot1161;
    sjs_mat4* sjt_dot1162;
    sjs_mat4* sjt_dot1163;
    sjs_mat4* sjt_dot1164;
    sjs_mat4* sjt_dot1165;
    sjs_mat4* sjt_dot1166;
    sjs_mat4* sjt_dot1167;
    sjs_mat4* sjt_dot1168;
    sjs_mat4* sjt_dot1169;
    sjs_mat4* sjt_dot1170;
    sjs_mat4* sjt_dot1171;
    sjs_mat4* sjt_dot1172;
    sjs_mat4* sjt_dot1173;
    sjs_mat4* sjt_dot1174;
    sjs_mat4* sjt_dot1175;
    sjs_mat4* sjt_dot1176;
    sjs_mat4* sjt_dot1177;
    sjs_mat4* sjt_dot1178;
    sjs_mat4* sjt_dot1179;
    sjs_mat4* sjt_dot1180;
    sjs_mat4* sjt_dot1181;
    sjs_mat4* sjt_dot1182;
    sjs_mat4* sjt_dot1183;
    sjs_mat4* sjt_dot1184;
    sjs_mat4* sjt_dot1185;
    sjs_mat4* sjt_dot1186;
    sjs_mat4* sjt_dot1187;
    sjs_mat4* sjt_dot1188;
    sjs_mat4* sjt_dot1189;
    sjs_mat4* sjt_dot1190;
    sjs_mat4* sjt_dot1191;
    sjs_mat4* sjt_dot1192;
    sjs_mat4* sjt_dot1193;
    sjs_mat4* sjt_dot1194;
    sjs_mat4* sjt_dot1195;
    sjs_mat4* sjt_dot1196;
    sjs_mat4* sjt_dot1197;
    sjs_mat4* sjt_dot1198;
    sjs_mat4* sjt_dot1199;
    sjs_mat4* sjt_dot1200;
    sjs_mat4* sjt_dot1201;
    sjs_mat4* sjt_dot1202;
    sjs_mat4* sjt_dot1203;
    sjs_mat4* sjt_dot1204;
    sjs_mat4* sjt_dot1205;
    sjs_mat4* sjt_dot1206;
    sjs_mat4* sjt_dot1207;
    sjs_mat4* sjt_dot1208;
    sjs_mat4* sjt_dot1209;
    sjs_mat4* sjt_dot1210;
    sjs_mat4* sjt_dot1211;
    sjs_mat4* sjt_dot1212;
    sjs_mat4* sjt_dot1213;
    sjs_mat4* sjt_dot1214;
    sjs_mat4* sjt_dot1215;
    sjs_mat4* sjt_dot1216;
    sjs_mat4* sjt_dot1217;
    sjs_mat4* sjt_dot1218;
    sjs_mat4* sjt_dot1219;
    sjs_mat4* sjt_dot1220;
    sjs_mat4* sjt_dot1221;
    sjs_mat4* sjt_dot1222;
    sjs_mat4* sjt_dot1223;
    sjs_mat4* sjt_dot1224;
    sjs_mat4* sjt_dot1225;
    sjs_mat4* sjt_dot1226;
    sjs_mat4* sjt_dot1227;
    sjs_mat4* sjt_dot1228;
    sjs_mat4* sjt_dot1229;
    sjs_mat4* sjt_dot1230;
    sjs_mat4* sjt_dot1231;
    sjs_mat4* sjt_dot1232;
    sjs_mat4* sjt_dot1233;
    sjs_mat4* sjt_dot1234;
    sjs_mat4* sjt_dot1235;
    sjs_mat4* sjt_dot1236;
    sjs_mat4* sjt_dot1237;
    sjs_mat4* sjt_dot1238;
    sjs_mat4* sjt_dot1239;
    sjs_mat4* sjt_dot1240;
    sjs_mat4* sjt_dot1241;
    sjs_mat4* sjt_dot1242;
    sjs_mat4* sjt_dot1243;
    sjs_mat4* sjt_dot1244;
    sjs_mat4* sjt_dot1245;
    sjs_mat4* sjt_dot1246;
    sjs_mat4* sjt_dot1247;
    sjs_mat4* sjt_dot1248;
    sjs_mat4* sjt_dot1249;
    sjs_mat4* sjt_dot1250;
    sjs_mat4* sjt_dot1251;
    sjs_mat4* sjt_dot1252;
    sjs_mat4* sjt_dot1253;
    sjs_mat4* sjt_dot1254;
    sjs_mat4* sjt_dot1255;
    sjs_mat4* sjt_dot1256;
    sjs_mat4* sjt_dot1257;
    sjs_mat4* sjt_dot1258;
    sjs_mat4* sjt_dot1259;
    sjs_mat4* sjt_dot1260;
    sjs_mat4* sjt_dot1261;
    sjs_mat4* sjt_dot1262;
    sjs_mat4* sjt_dot1263;
    sjs_mat4* sjt_dot1264;
    sjs_mat4* sjt_dot1265;
    sjs_mat4* sjt_dot1266;
    sjs_mat4* sjt_dot1267;
    sjs_mat4* sjt_dot1268;
    sjs_mat4* sjt_dot1269;
    sjs_mat4* sjt_dot1270;
    sjs_mat4* sjt_dot1271;
    sjs_mat4* sjt_dot1272;
    sjs_mat4* sjt_dot1273;
    sjs_mat4* sjt_dot1274;
    sjs_mat4* sjt_dot1275;
    sjs_mat4* sjt_dot1276;
    sjs_mat4* sjt_dot1277;
    sjs_mat4* sjt_dot1278;
    sjs_mat4* sjt_dot1279;
    sjs_mat4* sjt_dot1280;
    sjs_mat4* sjt_dot1281;
    sjs_mat4* sjt_dot1282;
    sjs_mat4* sjt_dot1283;
    sjs_mat4* sjt_dot1284;
    sjs_mat4* sjt_dot1285;
    sjs_mat4* sjt_dot1286;
    sjs_mat4* sjt_dot1287;
    sjs_mat4* sjt_dot1288;
    sjs_mat4* sjt_dot1289;
    sjs_mat4* sjt_dot1290;
    sjs_mat4* sjt_dot1291;
    sjs_mat4* sjt_dot1292;
    sjs_mat4* sjt_dot1293;
    sjs_mat4* sjt_dot1294;
    sjs_mat4* sjt_dot1295;
    sjs_mat4* sjt_dot1296;
    float sjt_functionParam117;
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
    sjs_mat4* sjt_parent52;
    sjs_mat4 sjv_t = { -1 };

    sjv_t._refCount = 1;
    sjt_dot1009 = _parent;
    sjt_math1565 = (sjt_dot1009)->m12;
    sjt_dot1010 = _parent;
    sjt_math1566 = (sjt_dot1010)->m23;
    sjt_math1563 = sjt_math1565 * sjt_math1566;
    sjt_dot1011 = _parent;
    sjt_math1564 = (sjt_dot1011)->m31;
    sjt_math1561 = sjt_math1563 * sjt_math1564;
    sjt_dot1012 = _parent;
    sjt_math1569 = (sjt_dot1012)->m13;
    sjt_dot1013 = _parent;
    sjt_math1570 = (sjt_dot1013)->m22;
    sjt_math1567 = sjt_math1569 * sjt_math1570;
    sjt_dot1014 = _parent;
    sjt_math1568 = (sjt_dot1014)->m31;
    sjt_math1562 = sjt_math1567 * sjt_math1568;
    sjt_math1559 = sjt_math1561 - sjt_math1562;
    sjt_dot1015 = _parent;
    sjt_math1573 = (sjt_dot1015)->m13;
    sjt_dot1016 = _parent;
    sjt_math1574 = (sjt_dot1016)->m21;
    sjt_math1571 = sjt_math1573 * sjt_math1574;
    sjt_dot1017 = _parent;
    sjt_math1572 = (sjt_dot1017)->m32;
    sjt_math1560 = sjt_math1571 * sjt_math1572;
    sjt_math1557 = sjt_math1559 + sjt_math1560;
    sjt_dot1018 = _parent;
    sjt_math1577 = (sjt_dot1018)->m11;
    sjt_dot1019 = _parent;
    sjt_math1578 = (sjt_dot1019)->m23;
    sjt_math1575 = sjt_math1577 * sjt_math1578;
    sjt_dot1020 = _parent;
    sjt_math1576 = (sjt_dot1020)->m32;
    sjt_math1558 = sjt_math1575 * sjt_math1576;
    sjt_math1555 = sjt_math1557 - sjt_math1558;
    sjt_dot1021 = _parent;
    sjt_math1581 = (sjt_dot1021)->m12;
    sjt_dot1022 = _parent;
    sjt_math1582 = (sjt_dot1022)->m21;
    sjt_math1579 = sjt_math1581 * sjt_math1582;
    sjt_dot1023 = _parent;
    sjt_math1580 = (sjt_dot1023)->m33;
    sjt_math1556 = sjt_math1579 * sjt_math1580;
    sjt_math1553 = sjt_math1555 - sjt_math1556;
    sjt_dot1024 = _parent;
    sjt_math1585 = (sjt_dot1024)->m11;
    sjt_dot1025 = _parent;
    sjt_math1586 = (sjt_dot1025)->m22;
    sjt_math1583 = sjt_math1585 * sjt_math1586;
    sjt_dot1026 = _parent;
    sjt_math1584 = (sjt_dot1026)->m33;
    sjt_math1554 = sjt_math1583 * sjt_math1584;
    sjv_t.m00 = sjt_math1553 + sjt_math1554;
    sjt_dot1027 = _parent;
    sjt_math1599 = (sjt_dot1027)->m03;
    sjt_dot1028 = _parent;
    sjt_math1600 = (sjt_dot1028)->m22;
    sjt_math1597 = sjt_math1599 * sjt_math1600;
    sjt_dot1029 = _parent;
    sjt_math1598 = (sjt_dot1029)->m31;
    sjt_math1595 = sjt_math1597 * sjt_math1598;
    sjt_dot1030 = _parent;
    sjt_math1603 = (sjt_dot1030)->m02;
    sjt_dot1031 = _parent;
    sjt_math1604 = (sjt_dot1031)->m23;
    sjt_math1601 = sjt_math1603 * sjt_math1604;
    sjt_dot1032 = _parent;
    sjt_math1602 = (sjt_dot1032)->m31;
    sjt_math1596 = sjt_math1601 * sjt_math1602;
    sjt_math1593 = sjt_math1595 - sjt_math1596;
    sjt_dot1033 = _parent;
    sjt_math1607 = (sjt_dot1033)->m03;
    sjt_dot1034 = _parent;
    sjt_math1608 = (sjt_dot1034)->m21;
    sjt_math1605 = sjt_math1607 * sjt_math1608;
    sjt_dot1035 = _parent;
    sjt_math1606 = (sjt_dot1035)->m32;
    sjt_math1594 = sjt_math1605 * sjt_math1606;
    sjt_math1591 = sjt_math1593 - sjt_math1594;
    sjt_dot1036 = _parent;
    sjt_math1611 = (sjt_dot1036)->m01;
    sjt_dot1037 = _parent;
    sjt_math1612 = (sjt_dot1037)->m23;
    sjt_math1609 = sjt_math1611 * sjt_math1612;
    sjt_dot1038 = _parent;
    sjt_math1610 = (sjt_dot1038)->m32;
    sjt_math1592 = sjt_math1609 * sjt_math1610;
    sjt_math1589 = sjt_math1591 + sjt_math1592;
    sjt_dot1039 = _parent;
    sjt_math1615 = (sjt_dot1039)->m02;
    sjt_dot1040 = _parent;
    sjt_math1616 = (sjt_dot1040)->m21;
    sjt_math1613 = sjt_math1615 * sjt_math1616;
    sjt_dot1041 = _parent;
    sjt_math1614 = (sjt_dot1041)->m33;
    sjt_math1590 = sjt_math1613 * sjt_math1614;
    sjt_math1587 = sjt_math1589 + sjt_math1590;
    sjt_dot1042 = _parent;
    sjt_math1619 = (sjt_dot1042)->m01;
    sjt_dot1043 = _parent;
    sjt_math1620 = (sjt_dot1043)->m22;
    sjt_math1617 = sjt_math1619 * sjt_math1620;
    sjt_dot1044 = _parent;
    sjt_math1618 = (sjt_dot1044)->m33;
    sjt_math1588 = sjt_math1617 * sjt_math1618;
    sjv_t.m01 = sjt_math1587 - sjt_math1588;
    sjt_dot1045 = _parent;
    sjt_math1633 = (sjt_dot1045)->m02;
    sjt_dot1046 = _parent;
    sjt_math1634 = (sjt_dot1046)->m13;
    sjt_math1631 = sjt_math1633 * sjt_math1634;
    sjt_dot1047 = _parent;
    sjt_math1632 = (sjt_dot1047)->m31;
    sjt_math1629 = sjt_math1631 * sjt_math1632;
    sjt_dot1048 = _parent;
    sjt_math1637 = (sjt_dot1048)->m03;
    sjt_dot1049 = _parent;
    sjt_math1638 = (sjt_dot1049)->m12;
    sjt_math1635 = sjt_math1637 * sjt_math1638;
    sjt_dot1050 = _parent;
    sjt_math1636 = (sjt_dot1050)->m31;
    sjt_math1630 = sjt_math1635 * sjt_math1636;
    sjt_math1627 = sjt_math1629 - sjt_math1630;
    sjt_dot1051 = _parent;
    sjt_math1641 = (sjt_dot1051)->m03;
    sjt_dot1052 = _parent;
    sjt_math1642 = (sjt_dot1052)->m11;
    sjt_math1639 = sjt_math1641 * sjt_math1642;
    sjt_dot1053 = _parent;
    sjt_math1640 = (sjt_dot1053)->m32;
    sjt_math1628 = sjt_math1639 * sjt_math1640;
    sjt_math1625 = sjt_math1627 + sjt_math1628;
    sjt_dot1054 = _parent;
    sjt_math1645 = (sjt_dot1054)->m01;
    sjt_dot1055 = _parent;
    sjt_math1646 = (sjt_dot1055)->m13;
    sjt_math1643 = sjt_math1645 * sjt_math1646;
    sjt_dot1056 = _parent;
    sjt_math1644 = (sjt_dot1056)->m32;
    sjt_math1626 = sjt_math1643 * sjt_math1644;
    sjt_math1623 = sjt_math1625 - sjt_math1626;
    sjt_dot1057 = _parent;
    sjt_math1649 = (sjt_dot1057)->m02;
    sjt_dot1058 = _parent;
    sjt_math1650 = (sjt_dot1058)->m11;
    sjt_math1647 = sjt_math1649 * sjt_math1650;
    sjt_dot1059 = _parent;
    sjt_math1648 = (sjt_dot1059)->m33;
    sjt_math1624 = sjt_math1647 * sjt_math1648;
    sjt_math1621 = sjt_math1623 - sjt_math1624;
    sjt_dot1060 = _parent;
    sjt_math1653 = (sjt_dot1060)->m01;
    sjt_dot1061 = _parent;
    sjt_math1654 = (sjt_dot1061)->m12;
    sjt_math1651 = sjt_math1653 * sjt_math1654;
    sjt_dot1062 = _parent;
    sjt_math1652 = (sjt_dot1062)->m33;
    sjt_math1622 = sjt_math1651 * sjt_math1652;
    sjv_t.m02 = sjt_math1621 + sjt_math1622;
    sjt_dot1063 = _parent;
    sjt_math1667 = (sjt_dot1063)->m03;
    sjt_dot1064 = _parent;
    sjt_math1668 = (sjt_dot1064)->m12;
    sjt_math1665 = sjt_math1667 * sjt_math1668;
    sjt_dot1065 = _parent;
    sjt_math1666 = (sjt_dot1065)->m21;
    sjt_math1663 = sjt_math1665 * sjt_math1666;
    sjt_dot1066 = _parent;
    sjt_math1671 = (sjt_dot1066)->m02;
    sjt_dot1067 = _parent;
    sjt_math1672 = (sjt_dot1067)->m13;
    sjt_math1669 = sjt_math1671 * sjt_math1672;
    sjt_dot1068 = _parent;
    sjt_math1670 = (sjt_dot1068)->m21;
    sjt_math1664 = sjt_math1669 * sjt_math1670;
    sjt_math1661 = sjt_math1663 - sjt_math1664;
    sjt_dot1069 = _parent;
    sjt_math1675 = (sjt_dot1069)->m03;
    sjt_dot1070 = _parent;
    sjt_math1676 = (sjt_dot1070)->m11;
    sjt_math1673 = sjt_math1675 * sjt_math1676;
    sjt_dot1071 = _parent;
    sjt_math1674 = (sjt_dot1071)->m22;
    sjt_math1662 = sjt_math1673 * sjt_math1674;
    sjt_math1659 = sjt_math1661 - sjt_math1662;
    sjt_dot1072 = _parent;
    sjt_math1679 = (sjt_dot1072)->m01;
    sjt_dot1073 = _parent;
    sjt_math1680 = (sjt_dot1073)->m13;
    sjt_math1677 = sjt_math1679 * sjt_math1680;
    sjt_dot1074 = _parent;
    sjt_math1678 = (sjt_dot1074)->m22;
    sjt_math1660 = sjt_math1677 * sjt_math1678;
    sjt_math1657 = sjt_math1659 + sjt_math1660;
    sjt_dot1075 = _parent;
    sjt_math1683 = (sjt_dot1075)->m02;
    sjt_dot1076 = _parent;
    sjt_math1684 = (sjt_dot1076)->m11;
    sjt_math1681 = sjt_math1683 * sjt_math1684;
    sjt_dot1077 = _parent;
    sjt_math1682 = (sjt_dot1077)->m23;
    sjt_math1658 = sjt_math1681 * sjt_math1682;
    sjt_math1655 = sjt_math1657 + sjt_math1658;
    sjt_dot1078 = _parent;
    sjt_math1687 = (sjt_dot1078)->m01;
    sjt_dot1079 = _parent;
    sjt_math1688 = (sjt_dot1079)->m12;
    sjt_math1685 = sjt_math1687 * sjt_math1688;
    sjt_dot1080 = _parent;
    sjt_math1686 = (sjt_dot1080)->m23;
    sjt_math1656 = sjt_math1685 * sjt_math1686;
    sjv_t.m03 = sjt_math1655 - sjt_math1656;
    sjt_dot1081 = _parent;
    sjt_math1701 = (sjt_dot1081)->m13;
    sjt_dot1082 = _parent;
    sjt_math1702 = (sjt_dot1082)->m22;
    sjt_math1699 = sjt_math1701 * sjt_math1702;
    sjt_dot1083 = _parent;
    sjt_math1700 = (sjt_dot1083)->m30;
    sjt_math1697 = sjt_math1699 * sjt_math1700;
    sjt_dot1084 = _parent;
    sjt_math1705 = (sjt_dot1084)->m12;
    sjt_dot1085 = _parent;
    sjt_math1706 = (sjt_dot1085)->m23;
    sjt_math1703 = sjt_math1705 * sjt_math1706;
    sjt_dot1086 = _parent;
    sjt_math1704 = (sjt_dot1086)->m30;
    sjt_math1698 = sjt_math1703 * sjt_math1704;
    sjt_math1695 = sjt_math1697 - sjt_math1698;
    sjt_dot1087 = _parent;
    sjt_math1709 = (sjt_dot1087)->m13;
    sjt_dot1088 = _parent;
    sjt_math1710 = (sjt_dot1088)->m20;
    sjt_math1707 = sjt_math1709 * sjt_math1710;
    sjt_dot1089 = _parent;
    sjt_math1708 = (sjt_dot1089)->m32;
    sjt_math1696 = sjt_math1707 * sjt_math1708;
    sjt_math1693 = sjt_math1695 - sjt_math1696;
    sjt_dot1090 = _parent;
    sjt_math1713 = (sjt_dot1090)->m10;
    sjt_dot1091 = _parent;
    sjt_math1714 = (sjt_dot1091)->m23;
    sjt_math1711 = sjt_math1713 * sjt_math1714;
    sjt_dot1092 = _parent;
    sjt_math1712 = (sjt_dot1092)->m32;
    sjt_math1694 = sjt_math1711 * sjt_math1712;
    sjt_math1691 = sjt_math1693 + sjt_math1694;
    sjt_dot1093 = _parent;
    sjt_math1717 = (sjt_dot1093)->m12;
    sjt_dot1094 = _parent;
    sjt_math1718 = (sjt_dot1094)->m20;
    sjt_math1715 = sjt_math1717 * sjt_math1718;
    sjt_dot1095 = _parent;
    sjt_math1716 = (sjt_dot1095)->m33;
    sjt_math1692 = sjt_math1715 * sjt_math1716;
    sjt_math1689 = sjt_math1691 + sjt_math1692;
    sjt_dot1096 = _parent;
    sjt_math1721 = (sjt_dot1096)->m10;
    sjt_dot1097 = _parent;
    sjt_math1722 = (sjt_dot1097)->m22;
    sjt_math1719 = sjt_math1721 * sjt_math1722;
    sjt_dot1098 = _parent;
    sjt_math1720 = (sjt_dot1098)->m33;
    sjt_math1690 = sjt_math1719 * sjt_math1720;
    sjv_t.m10 = sjt_math1689 - sjt_math1690;
    sjt_dot1099 = _parent;
    sjt_math1735 = (sjt_dot1099)->m02;
    sjt_dot1100 = _parent;
    sjt_math1736 = (sjt_dot1100)->m23;
    sjt_math1733 = sjt_math1735 * sjt_math1736;
    sjt_dot1101 = _parent;
    sjt_math1734 = (sjt_dot1101)->m30;
    sjt_math1731 = sjt_math1733 * sjt_math1734;
    sjt_dot1102 = _parent;
    sjt_math1739 = (sjt_dot1102)->m03;
    sjt_dot1103 = _parent;
    sjt_math1740 = (sjt_dot1103)->m22;
    sjt_math1737 = sjt_math1739 * sjt_math1740;
    sjt_dot1104 = _parent;
    sjt_math1738 = (sjt_dot1104)->m30;
    sjt_math1732 = sjt_math1737 * sjt_math1738;
    sjt_math1729 = sjt_math1731 - sjt_math1732;
    sjt_dot1105 = _parent;
    sjt_math1743 = (sjt_dot1105)->m03;
    sjt_dot1106 = _parent;
    sjt_math1744 = (sjt_dot1106)->m20;
    sjt_math1741 = sjt_math1743 * sjt_math1744;
    sjt_dot1107 = _parent;
    sjt_math1742 = (sjt_dot1107)->m32;
    sjt_math1730 = sjt_math1741 * sjt_math1742;
    sjt_math1727 = sjt_math1729 + sjt_math1730;
    sjt_dot1108 = _parent;
    sjt_math1747 = (sjt_dot1108)->m00;
    sjt_dot1109 = _parent;
    sjt_math1748 = (sjt_dot1109)->m23;
    sjt_math1745 = sjt_math1747 * sjt_math1748;
    sjt_dot1110 = _parent;
    sjt_math1746 = (sjt_dot1110)->m32;
    sjt_math1728 = sjt_math1745 * sjt_math1746;
    sjt_math1725 = sjt_math1727 - sjt_math1728;
    sjt_dot1111 = _parent;
    sjt_math1751 = (sjt_dot1111)->m02;
    sjt_dot1112 = _parent;
    sjt_math1752 = (sjt_dot1112)->m20;
    sjt_math1749 = sjt_math1751 * sjt_math1752;
    sjt_dot1113 = _parent;
    sjt_math1750 = (sjt_dot1113)->m33;
    sjt_math1726 = sjt_math1749 * sjt_math1750;
    sjt_math1723 = sjt_math1725 - sjt_math1726;
    sjt_dot1114 = _parent;
    sjt_math1755 = (sjt_dot1114)->m00;
    sjt_dot1115 = _parent;
    sjt_math1756 = (sjt_dot1115)->m22;
    sjt_math1753 = sjt_math1755 * sjt_math1756;
    sjt_dot1116 = _parent;
    sjt_math1754 = (sjt_dot1116)->m33;
    sjt_math1724 = sjt_math1753 * sjt_math1754;
    sjv_t.m11 = sjt_math1723 + sjt_math1724;
    sjt_dot1117 = _parent;
    sjt_math1769 = (sjt_dot1117)->m03;
    sjt_dot1118 = _parent;
    sjt_math1770 = (sjt_dot1118)->m12;
    sjt_math1767 = sjt_math1769 * sjt_math1770;
    sjt_dot1119 = _parent;
    sjt_math1768 = (sjt_dot1119)->m30;
    sjt_math1765 = sjt_math1767 * sjt_math1768;
    sjt_dot1120 = _parent;
    sjt_math1773 = (sjt_dot1120)->m02;
    sjt_dot1121 = _parent;
    sjt_math1774 = (sjt_dot1121)->m13;
    sjt_math1771 = sjt_math1773 * sjt_math1774;
    sjt_dot1122 = _parent;
    sjt_math1772 = (sjt_dot1122)->m30;
    sjt_math1766 = sjt_math1771 * sjt_math1772;
    sjt_math1763 = sjt_math1765 - sjt_math1766;
    sjt_dot1123 = _parent;
    sjt_math1777 = (sjt_dot1123)->m03;
    sjt_dot1124 = _parent;
    sjt_math1778 = (sjt_dot1124)->m10;
    sjt_math1775 = sjt_math1777 * sjt_math1778;
    sjt_dot1125 = _parent;
    sjt_math1776 = (sjt_dot1125)->m32;
    sjt_math1764 = sjt_math1775 * sjt_math1776;
    sjt_math1761 = sjt_math1763 - sjt_math1764;
    sjt_dot1126 = _parent;
    sjt_math1781 = (sjt_dot1126)->m00;
    sjt_dot1127 = _parent;
    sjt_math1782 = (sjt_dot1127)->m13;
    sjt_math1779 = sjt_math1781 * sjt_math1782;
    sjt_dot1128 = _parent;
    sjt_math1780 = (sjt_dot1128)->m32;
    sjt_math1762 = sjt_math1779 * sjt_math1780;
    sjt_math1759 = sjt_math1761 + sjt_math1762;
    sjt_dot1129 = _parent;
    sjt_math1785 = (sjt_dot1129)->m02;
    sjt_dot1130 = _parent;
    sjt_math1786 = (sjt_dot1130)->m10;
    sjt_math1783 = sjt_math1785 * sjt_math1786;
    sjt_dot1131 = _parent;
    sjt_math1784 = (sjt_dot1131)->m33;
    sjt_math1760 = sjt_math1783 * sjt_math1784;
    sjt_math1757 = sjt_math1759 + sjt_math1760;
    sjt_dot1132 = _parent;
    sjt_math1789 = (sjt_dot1132)->m00;
    sjt_dot1133 = _parent;
    sjt_math1790 = (sjt_dot1133)->m12;
    sjt_math1787 = sjt_math1789 * sjt_math1790;
    sjt_dot1134 = _parent;
    sjt_math1788 = (sjt_dot1134)->m33;
    sjt_math1758 = sjt_math1787 * sjt_math1788;
    sjv_t.m12 = sjt_math1757 - sjt_math1758;
    sjt_dot1135 = _parent;
    sjt_math1803 = (sjt_dot1135)->m02;
    sjt_dot1136 = _parent;
    sjt_math1804 = (sjt_dot1136)->m13;
    sjt_math1801 = sjt_math1803 * sjt_math1804;
    sjt_dot1137 = _parent;
    sjt_math1802 = (sjt_dot1137)->m20;
    sjt_math1799 = sjt_math1801 * sjt_math1802;
    sjt_dot1138 = _parent;
    sjt_math1807 = (sjt_dot1138)->m03;
    sjt_dot1139 = _parent;
    sjt_math1808 = (sjt_dot1139)->m12;
    sjt_math1805 = sjt_math1807 * sjt_math1808;
    sjt_dot1140 = _parent;
    sjt_math1806 = (sjt_dot1140)->m20;
    sjt_math1800 = sjt_math1805 * sjt_math1806;
    sjt_math1797 = sjt_math1799 - sjt_math1800;
    sjt_dot1141 = _parent;
    sjt_math1811 = (sjt_dot1141)->m03;
    sjt_dot1142 = _parent;
    sjt_math1812 = (sjt_dot1142)->m10;
    sjt_math1809 = sjt_math1811 * sjt_math1812;
    sjt_dot1143 = _parent;
    sjt_math1810 = (sjt_dot1143)->m22;
    sjt_math1798 = sjt_math1809 * sjt_math1810;
    sjt_math1795 = sjt_math1797 + sjt_math1798;
    sjt_dot1144 = _parent;
    sjt_math1815 = (sjt_dot1144)->m00;
    sjt_dot1145 = _parent;
    sjt_math1816 = (sjt_dot1145)->m13;
    sjt_math1813 = sjt_math1815 * sjt_math1816;
    sjt_dot1146 = _parent;
    sjt_math1814 = (sjt_dot1146)->m22;
    sjt_math1796 = sjt_math1813 * sjt_math1814;
    sjt_math1793 = sjt_math1795 - sjt_math1796;
    sjt_dot1147 = _parent;
    sjt_math1819 = (sjt_dot1147)->m02;
    sjt_dot1148 = _parent;
    sjt_math1820 = (sjt_dot1148)->m10;
    sjt_math1817 = sjt_math1819 * sjt_math1820;
    sjt_dot1149 = _parent;
    sjt_math1818 = (sjt_dot1149)->m23;
    sjt_math1794 = sjt_math1817 * sjt_math1818;
    sjt_math1791 = sjt_math1793 - sjt_math1794;
    sjt_dot1150 = _parent;
    sjt_math1823 = (sjt_dot1150)->m00;
    sjt_dot1151 = _parent;
    sjt_math1824 = (sjt_dot1151)->m12;
    sjt_math1821 = sjt_math1823 * sjt_math1824;
    sjt_dot1152 = _parent;
    sjt_math1822 = (sjt_dot1152)->m23;
    sjt_math1792 = sjt_math1821 * sjt_math1822;
    sjv_t.m13 = sjt_math1791 + sjt_math1792;
    sjt_dot1153 = _parent;
    sjt_math1837 = (sjt_dot1153)->m11;
    sjt_dot1154 = _parent;
    sjt_math1838 = (sjt_dot1154)->m23;
    sjt_math1835 = sjt_math1837 * sjt_math1838;
    sjt_dot1155 = _parent;
    sjt_math1836 = (sjt_dot1155)->m30;
    sjt_math1833 = sjt_math1835 * sjt_math1836;
    sjt_dot1156 = _parent;
    sjt_math1841 = (sjt_dot1156)->m13;
    sjt_dot1157 = _parent;
    sjt_math1842 = (sjt_dot1157)->m21;
    sjt_math1839 = sjt_math1841 * sjt_math1842;
    sjt_dot1158 = _parent;
    sjt_math1840 = (sjt_dot1158)->m30;
    sjt_math1834 = sjt_math1839 * sjt_math1840;
    sjt_math1831 = sjt_math1833 - sjt_math1834;
    sjt_dot1159 = _parent;
    sjt_math1845 = (sjt_dot1159)->m13;
    sjt_dot1160 = _parent;
    sjt_math1846 = (sjt_dot1160)->m20;
    sjt_math1843 = sjt_math1845 * sjt_math1846;
    sjt_dot1161 = _parent;
    sjt_math1844 = (sjt_dot1161)->m31;
    sjt_math1832 = sjt_math1843 * sjt_math1844;
    sjt_math1829 = sjt_math1831 + sjt_math1832;
    sjt_dot1162 = _parent;
    sjt_math1849 = (sjt_dot1162)->m10;
    sjt_dot1163 = _parent;
    sjt_math1850 = (sjt_dot1163)->m23;
    sjt_math1847 = sjt_math1849 * sjt_math1850;
    sjt_dot1164 = _parent;
    sjt_math1848 = (sjt_dot1164)->m31;
    sjt_math1830 = sjt_math1847 * sjt_math1848;
    sjt_math1827 = sjt_math1829 - sjt_math1830;
    sjt_dot1165 = _parent;
    sjt_math1853 = (sjt_dot1165)->m11;
    sjt_dot1166 = _parent;
    sjt_math1854 = (sjt_dot1166)->m20;
    sjt_math1851 = sjt_math1853 * sjt_math1854;
    sjt_dot1167 = _parent;
    sjt_math1852 = (sjt_dot1167)->m33;
    sjt_math1828 = sjt_math1851 * sjt_math1852;
    sjt_math1825 = sjt_math1827 - sjt_math1828;
    sjt_dot1168 = _parent;
    sjt_math1857 = (sjt_dot1168)->m10;
    sjt_dot1169 = _parent;
    sjt_math1858 = (sjt_dot1169)->m21;
    sjt_math1855 = sjt_math1857 * sjt_math1858;
    sjt_dot1170 = _parent;
    sjt_math1856 = (sjt_dot1170)->m33;
    sjt_math1826 = sjt_math1855 * sjt_math1856;
    sjv_t.m20 = sjt_math1825 + sjt_math1826;
    sjt_dot1171 = _parent;
    sjt_math1871 = (sjt_dot1171)->m03;
    sjt_dot1172 = _parent;
    sjt_math1872 = (sjt_dot1172)->m21;
    sjt_math1869 = sjt_math1871 * sjt_math1872;
    sjt_dot1173 = _parent;
    sjt_math1870 = (sjt_dot1173)->m30;
    sjt_math1867 = sjt_math1869 * sjt_math1870;
    sjt_dot1174 = _parent;
    sjt_math1875 = (sjt_dot1174)->m01;
    sjt_dot1175 = _parent;
    sjt_math1876 = (sjt_dot1175)->m23;
    sjt_math1873 = sjt_math1875 * sjt_math1876;
    sjt_dot1176 = _parent;
    sjt_math1874 = (sjt_dot1176)->m30;
    sjt_math1868 = sjt_math1873 * sjt_math1874;
    sjt_math1865 = sjt_math1867 - sjt_math1868;
    sjt_dot1177 = _parent;
    sjt_math1879 = (sjt_dot1177)->m03;
    sjt_dot1178 = _parent;
    sjt_math1880 = (sjt_dot1178)->m20;
    sjt_math1877 = sjt_math1879 * sjt_math1880;
    sjt_dot1179 = _parent;
    sjt_math1878 = (sjt_dot1179)->m31;
    sjt_math1866 = sjt_math1877 * sjt_math1878;
    sjt_math1863 = sjt_math1865 - sjt_math1866;
    sjt_dot1180 = _parent;
    sjt_math1883 = (sjt_dot1180)->m00;
    sjt_dot1181 = _parent;
    sjt_math1884 = (sjt_dot1181)->m23;
    sjt_math1881 = sjt_math1883 * sjt_math1884;
    sjt_dot1182 = _parent;
    sjt_math1882 = (sjt_dot1182)->m31;
    sjt_math1864 = sjt_math1881 * sjt_math1882;
    sjt_math1861 = sjt_math1863 + sjt_math1864;
    sjt_dot1183 = _parent;
    sjt_math1887 = (sjt_dot1183)->m01;
    sjt_dot1184 = _parent;
    sjt_math1888 = (sjt_dot1184)->m20;
    sjt_math1885 = sjt_math1887 * sjt_math1888;
    sjt_dot1185 = _parent;
    sjt_math1886 = (sjt_dot1185)->m33;
    sjt_math1862 = sjt_math1885 * sjt_math1886;
    sjt_math1859 = sjt_math1861 + sjt_math1862;
    sjt_dot1186 = _parent;
    sjt_math1891 = (sjt_dot1186)->m00;
    sjt_dot1187 = _parent;
    sjt_math1892 = (sjt_dot1187)->m21;
    sjt_math1889 = sjt_math1891 * sjt_math1892;
    sjt_dot1188 = _parent;
    sjt_math1890 = (sjt_dot1188)->m33;
    sjt_math1860 = sjt_math1889 * sjt_math1890;
    sjv_t.m21 = sjt_math1859 - sjt_math1860;
    sjt_dot1189 = _parent;
    sjt_math1905 = (sjt_dot1189)->m01;
    sjt_dot1190 = _parent;
    sjt_math1906 = (sjt_dot1190)->m13;
    sjt_math1903 = sjt_math1905 * sjt_math1906;
    sjt_dot1191 = _parent;
    sjt_math1904 = (sjt_dot1191)->m30;
    sjt_math1901 = sjt_math1903 * sjt_math1904;
    sjt_dot1192 = _parent;
    sjt_math1909 = (sjt_dot1192)->m03;
    sjt_dot1193 = _parent;
    sjt_math1910 = (sjt_dot1193)->m11;
    sjt_math1907 = sjt_math1909 * sjt_math1910;
    sjt_dot1194 = _parent;
    sjt_math1908 = (sjt_dot1194)->m30;
    sjt_math1902 = sjt_math1907 * sjt_math1908;
    sjt_math1899 = sjt_math1901 - sjt_math1902;
    sjt_dot1195 = _parent;
    sjt_math1913 = (sjt_dot1195)->m03;
    sjt_dot1196 = _parent;
    sjt_math1914 = (sjt_dot1196)->m10;
    sjt_math1911 = sjt_math1913 * sjt_math1914;
    sjt_dot1197 = _parent;
    sjt_math1912 = (sjt_dot1197)->m31;
    sjt_math1900 = sjt_math1911 * sjt_math1912;
    sjt_math1897 = sjt_math1899 + sjt_math1900;
    sjt_dot1198 = _parent;
    sjt_math1917 = (sjt_dot1198)->m00;
    sjt_dot1199 = _parent;
    sjt_math1918 = (sjt_dot1199)->m13;
    sjt_math1915 = sjt_math1917 * sjt_math1918;
    sjt_dot1200 = _parent;
    sjt_math1916 = (sjt_dot1200)->m31;
    sjt_math1898 = sjt_math1915 * sjt_math1916;
    sjt_math1895 = sjt_math1897 - sjt_math1898;
    sjt_dot1201 = _parent;
    sjt_math1921 = (sjt_dot1201)->m01;
    sjt_dot1202 = _parent;
    sjt_math1922 = (sjt_dot1202)->m10;
    sjt_math1919 = sjt_math1921 * sjt_math1922;
    sjt_dot1203 = _parent;
    sjt_math1920 = (sjt_dot1203)->m33;
    sjt_math1896 = sjt_math1919 * sjt_math1920;
    sjt_math1893 = sjt_math1895 - sjt_math1896;
    sjt_dot1204 = _parent;
    sjt_math1925 = (sjt_dot1204)->m00;
    sjt_dot1205 = _parent;
    sjt_math1926 = (sjt_dot1205)->m11;
    sjt_math1923 = sjt_math1925 * sjt_math1926;
    sjt_dot1206 = _parent;
    sjt_math1924 = (sjt_dot1206)->m33;
    sjt_math1894 = sjt_math1923 * sjt_math1924;
    sjv_t.m22 = sjt_math1893 + sjt_math1894;
    sjt_dot1207 = _parent;
    sjt_math1939 = (sjt_dot1207)->m03;
    sjt_dot1208 = _parent;
    sjt_math1940 = (sjt_dot1208)->m11;
    sjt_math1937 = sjt_math1939 * sjt_math1940;
    sjt_dot1209 = _parent;
    sjt_math1938 = (sjt_dot1209)->m20;
    sjt_math1935 = sjt_math1937 * sjt_math1938;
    sjt_dot1210 = _parent;
    sjt_math1943 = (sjt_dot1210)->m01;
    sjt_dot1211 = _parent;
    sjt_math1944 = (sjt_dot1211)->m13;
    sjt_math1941 = sjt_math1943 * sjt_math1944;
    sjt_dot1212 = _parent;
    sjt_math1942 = (sjt_dot1212)->m20;
    sjt_math1936 = sjt_math1941 * sjt_math1942;
    sjt_math1933 = sjt_math1935 - sjt_math1936;
    sjt_dot1213 = _parent;
    sjt_math1947 = (sjt_dot1213)->m03;
    sjt_dot1214 = _parent;
    sjt_math1948 = (sjt_dot1214)->m10;
    sjt_math1945 = sjt_math1947 * sjt_math1948;
    sjt_dot1215 = _parent;
    sjt_math1946 = (sjt_dot1215)->m21;
    sjt_math1934 = sjt_math1945 * sjt_math1946;
    sjt_math1931 = sjt_math1933 - sjt_math1934;
    sjt_dot1216 = _parent;
    sjt_math1951 = (sjt_dot1216)->m00;
    sjt_dot1217 = _parent;
    sjt_math1952 = (sjt_dot1217)->m13;
    sjt_math1949 = sjt_math1951 * sjt_math1952;
    sjt_dot1218 = _parent;
    sjt_math1950 = (sjt_dot1218)->m21;
    sjt_math1932 = sjt_math1949 * sjt_math1950;
    sjt_math1929 = sjt_math1931 + sjt_math1932;
    sjt_dot1219 = _parent;
    sjt_math1955 = (sjt_dot1219)->m01;
    sjt_dot1220 = _parent;
    sjt_math1956 = (sjt_dot1220)->m10;
    sjt_math1953 = sjt_math1955 * sjt_math1956;
    sjt_dot1221 = _parent;
    sjt_math1954 = (sjt_dot1221)->m23;
    sjt_math1930 = sjt_math1953 * sjt_math1954;
    sjt_math1927 = sjt_math1929 + sjt_math1930;
    sjt_dot1222 = _parent;
    sjt_math1959 = (sjt_dot1222)->m00;
    sjt_dot1223 = _parent;
    sjt_math1960 = (sjt_dot1223)->m11;
    sjt_math1957 = sjt_math1959 * sjt_math1960;
    sjt_dot1224 = _parent;
    sjt_math1958 = (sjt_dot1224)->m23;
    sjt_math1928 = sjt_math1957 * sjt_math1958;
    sjv_t.m23 = sjt_math1927 - sjt_math1928;
    sjt_dot1225 = _parent;
    sjt_math1973 = (sjt_dot1225)->m12;
    sjt_dot1226 = _parent;
    sjt_math1974 = (sjt_dot1226)->m21;
    sjt_math1971 = sjt_math1973 * sjt_math1974;
    sjt_dot1227 = _parent;
    sjt_math1972 = (sjt_dot1227)->m30;
    sjt_math1969 = sjt_math1971 * sjt_math1972;
    sjt_dot1228 = _parent;
    sjt_math1977 = (sjt_dot1228)->m11;
    sjt_dot1229 = _parent;
    sjt_math1978 = (sjt_dot1229)->m22;
    sjt_math1975 = sjt_math1977 * sjt_math1978;
    sjt_dot1230 = _parent;
    sjt_math1976 = (sjt_dot1230)->m30;
    sjt_math1970 = sjt_math1975 * sjt_math1976;
    sjt_math1967 = sjt_math1969 - sjt_math1970;
    sjt_dot1231 = _parent;
    sjt_math1981 = (sjt_dot1231)->m12;
    sjt_dot1232 = _parent;
    sjt_math1982 = (sjt_dot1232)->m20;
    sjt_math1979 = sjt_math1981 * sjt_math1982;
    sjt_dot1233 = _parent;
    sjt_math1980 = (sjt_dot1233)->m31;
    sjt_math1968 = sjt_math1979 * sjt_math1980;
    sjt_math1965 = sjt_math1967 - sjt_math1968;
    sjt_dot1234 = _parent;
    sjt_math1985 = (sjt_dot1234)->m10;
    sjt_dot1235 = _parent;
    sjt_math1986 = (sjt_dot1235)->m22;
    sjt_math1983 = sjt_math1985 * sjt_math1986;
    sjt_dot1236 = _parent;
    sjt_math1984 = (sjt_dot1236)->m31;
    sjt_math1966 = sjt_math1983 * sjt_math1984;
    sjt_math1963 = sjt_math1965 + sjt_math1966;
    sjt_dot1237 = _parent;
    sjt_math1989 = (sjt_dot1237)->m11;
    sjt_dot1238 = _parent;
    sjt_math1990 = (sjt_dot1238)->m20;
    sjt_math1987 = sjt_math1989 * sjt_math1990;
    sjt_dot1239 = _parent;
    sjt_math1988 = (sjt_dot1239)->m32;
    sjt_math1964 = sjt_math1987 * sjt_math1988;
    sjt_math1961 = sjt_math1963 + sjt_math1964;
    sjt_dot1240 = _parent;
    sjt_math1993 = (sjt_dot1240)->m10;
    sjt_dot1241 = _parent;
    sjt_math1994 = (sjt_dot1241)->m21;
    sjt_math1991 = sjt_math1993 * sjt_math1994;
    sjt_dot1242 = _parent;
    sjt_math1992 = (sjt_dot1242)->m32;
    sjt_math1962 = sjt_math1991 * sjt_math1992;
    sjv_t.m30 = sjt_math1961 - sjt_math1962;
    sjt_dot1243 = _parent;
    sjt_math2007 = (sjt_dot1243)->m01;
    sjt_dot1244 = _parent;
    sjt_math2008 = (sjt_dot1244)->m22;
    sjt_math2005 = sjt_math2007 * sjt_math2008;
    sjt_dot1245 = _parent;
    sjt_math2006 = (sjt_dot1245)->m30;
    sjt_math2003 = sjt_math2005 * sjt_math2006;
    sjt_dot1246 = _parent;
    sjt_math2011 = (sjt_dot1246)->m02;
    sjt_dot1247 = _parent;
    sjt_math2012 = (sjt_dot1247)->m21;
    sjt_math2009 = sjt_math2011 * sjt_math2012;
    sjt_dot1248 = _parent;
    sjt_math2010 = (sjt_dot1248)->m30;
    sjt_math2004 = sjt_math2009 * sjt_math2010;
    sjt_math2001 = sjt_math2003 - sjt_math2004;
    sjt_dot1249 = _parent;
    sjt_math2015 = (sjt_dot1249)->m02;
    sjt_dot1250 = _parent;
    sjt_math2016 = (sjt_dot1250)->m20;
    sjt_math2013 = sjt_math2015 * sjt_math2016;
    sjt_dot1251 = _parent;
    sjt_math2014 = (sjt_dot1251)->m31;
    sjt_math2002 = sjt_math2013 * sjt_math2014;
    sjt_math1999 = sjt_math2001 + sjt_math2002;
    sjt_dot1252 = _parent;
    sjt_math2019 = (sjt_dot1252)->m00;
    sjt_dot1253 = _parent;
    sjt_math2020 = (sjt_dot1253)->m22;
    sjt_math2017 = sjt_math2019 * sjt_math2020;
    sjt_dot1254 = _parent;
    sjt_math2018 = (sjt_dot1254)->m31;
    sjt_math2000 = sjt_math2017 * sjt_math2018;
    sjt_math1997 = sjt_math1999 - sjt_math2000;
    sjt_dot1255 = _parent;
    sjt_math2023 = (sjt_dot1255)->m01;
    sjt_dot1256 = _parent;
    sjt_math2024 = (sjt_dot1256)->m20;
    sjt_math2021 = sjt_math2023 * sjt_math2024;
    sjt_dot1257 = _parent;
    sjt_math2022 = (sjt_dot1257)->m32;
    sjt_math1998 = sjt_math2021 * sjt_math2022;
    sjt_math1995 = sjt_math1997 - sjt_math1998;
    sjt_dot1258 = _parent;
    sjt_math2027 = (sjt_dot1258)->m00;
    sjt_dot1259 = _parent;
    sjt_math2028 = (sjt_dot1259)->m21;
    sjt_math2025 = sjt_math2027 * sjt_math2028;
    sjt_dot1260 = _parent;
    sjt_math2026 = (sjt_dot1260)->m32;
    sjt_math1996 = sjt_math2025 * sjt_math2026;
    sjv_t.m31 = sjt_math1995 + sjt_math1996;
    sjt_dot1261 = _parent;
    sjt_math2041 = (sjt_dot1261)->m02;
    sjt_dot1262 = _parent;
    sjt_math2042 = (sjt_dot1262)->m11;
    sjt_math2039 = sjt_math2041 * sjt_math2042;
    sjt_dot1263 = _parent;
    sjt_math2040 = (sjt_dot1263)->m30;
    sjt_math2037 = sjt_math2039 * sjt_math2040;
    sjt_dot1264 = _parent;
    sjt_math2045 = (sjt_dot1264)->m01;
    sjt_dot1265 = _parent;
    sjt_math2046 = (sjt_dot1265)->m12;
    sjt_math2043 = sjt_math2045 * sjt_math2046;
    sjt_dot1266 = _parent;
    sjt_math2044 = (sjt_dot1266)->m30;
    sjt_math2038 = sjt_math2043 * sjt_math2044;
    sjt_math2035 = sjt_math2037 - sjt_math2038;
    sjt_dot1267 = _parent;
    sjt_math2049 = (sjt_dot1267)->m02;
    sjt_dot1268 = _parent;
    sjt_math2050 = (sjt_dot1268)->m10;
    sjt_math2047 = sjt_math2049 * sjt_math2050;
    sjt_dot1269 = _parent;
    sjt_math2048 = (sjt_dot1269)->m31;
    sjt_math2036 = sjt_math2047 * sjt_math2048;
    sjt_math2033 = sjt_math2035 - sjt_math2036;
    sjt_dot1270 = _parent;
    sjt_math2053 = (sjt_dot1270)->m00;
    sjt_dot1271 = _parent;
    sjt_math2054 = (sjt_dot1271)->m12;
    sjt_math2051 = sjt_math2053 * sjt_math2054;
    sjt_dot1272 = _parent;
    sjt_math2052 = (sjt_dot1272)->m31;
    sjt_math2034 = sjt_math2051 * sjt_math2052;
    sjt_math2031 = sjt_math2033 + sjt_math2034;
    sjt_dot1273 = _parent;
    sjt_math2057 = (sjt_dot1273)->m01;
    sjt_dot1274 = _parent;
    sjt_math2058 = (sjt_dot1274)->m10;
    sjt_math2055 = sjt_math2057 * sjt_math2058;
    sjt_dot1275 = _parent;
    sjt_math2056 = (sjt_dot1275)->m32;
    sjt_math2032 = sjt_math2055 * sjt_math2056;
    sjt_math2029 = sjt_math2031 + sjt_math2032;
    sjt_dot1276 = _parent;
    sjt_math2061 = (sjt_dot1276)->m00;
    sjt_dot1277 = _parent;
    sjt_math2062 = (sjt_dot1277)->m11;
    sjt_math2059 = sjt_math2061 * sjt_math2062;
    sjt_dot1278 = _parent;
    sjt_math2060 = (sjt_dot1278)->m32;
    sjt_math2030 = sjt_math2059 * sjt_math2060;
    sjv_t.m32 = sjt_math2029 - sjt_math2030;
    sjt_dot1279 = _parent;
    sjt_math2075 = (sjt_dot1279)->m01;
    sjt_dot1280 = _parent;
    sjt_math2076 = (sjt_dot1280)->m12;
    sjt_math2073 = sjt_math2075 * sjt_math2076;
    sjt_dot1281 = _parent;
    sjt_math2074 = (sjt_dot1281)->m20;
    sjt_math2071 = sjt_math2073 * sjt_math2074;
    sjt_dot1282 = _parent;
    sjt_math2079 = (sjt_dot1282)->m02;
    sjt_dot1283 = _parent;
    sjt_math2080 = (sjt_dot1283)->m11;
    sjt_math2077 = sjt_math2079 * sjt_math2080;
    sjt_dot1284 = _parent;
    sjt_math2078 = (sjt_dot1284)->m20;
    sjt_math2072 = sjt_math2077 * sjt_math2078;
    sjt_math2069 = sjt_math2071 - sjt_math2072;
    sjt_dot1285 = _parent;
    sjt_math2083 = (sjt_dot1285)->m02;
    sjt_dot1286 = _parent;
    sjt_math2084 = (sjt_dot1286)->m10;
    sjt_math2081 = sjt_math2083 * sjt_math2084;
    sjt_dot1287 = _parent;
    sjt_math2082 = (sjt_dot1287)->m21;
    sjt_math2070 = sjt_math2081 * sjt_math2082;
    sjt_math2067 = sjt_math2069 + sjt_math2070;
    sjt_dot1288 = _parent;
    sjt_math2087 = (sjt_dot1288)->m00;
    sjt_dot1289 = _parent;
    sjt_math2088 = (sjt_dot1289)->m12;
    sjt_math2085 = sjt_math2087 * sjt_math2088;
    sjt_dot1290 = _parent;
    sjt_math2086 = (sjt_dot1290)->m21;
    sjt_math2068 = sjt_math2085 * sjt_math2086;
    sjt_math2065 = sjt_math2067 - sjt_math2068;
    sjt_dot1291 = _parent;
    sjt_math2091 = (sjt_dot1291)->m01;
    sjt_dot1292 = _parent;
    sjt_math2092 = (sjt_dot1292)->m10;
    sjt_math2089 = sjt_math2091 * sjt_math2092;
    sjt_dot1293 = _parent;
    sjt_math2090 = (sjt_dot1293)->m22;
    sjt_math2066 = sjt_math2089 * sjt_math2090;
    sjt_math2063 = sjt_math2065 - sjt_math2066;
    sjt_dot1294 = _parent;
    sjt_math2095 = (sjt_dot1294)->m00;
    sjt_dot1295 = _parent;
    sjt_math2096 = (sjt_dot1295)->m11;
    sjt_math2093 = sjt_math2095 * sjt_math2096;
    sjt_dot1296 = _parent;
    sjt_math2094 = (sjt_dot1296)->m22;
    sjt_math2064 = sjt_math2093 * sjt_math2094;
    sjv_t.m33 = sjt_math2063 + sjt_math2064;
    sjf_mat4(&sjv_t);
    sjt_parent52 = &sjv_t;
    sjt_math2097 = 1.0f;
    sjf_mat4_determinant(_parent, &sjt_math2098);
    sjt_functionParam117 = sjt_math2097 / sjt_math2098;
    sjf_mat4_multiplyf32_heap(sjt_parent52, sjt_functionParam117, _return);

    if (sjv_t._refCount == 1) { sjf_mat4_destroy(&sjv_t); }
}

void sjf_mat4_lookatlh(sjs_vec3* camera, sjs_vec3* target, sjs_vec3* up, sjs_mat4* _return) {
    sjs_vec3 sjt_call5 = { -1 };
    sjs_vec3* sjt_dot172;
    sjs_vec3* sjt_dot173;
    sjs_vec3* sjt_dot174;
    sjs_vec3* sjt_dot175;
    sjs_vec3* sjt_dot176;
    sjs_vec3* sjt_dot177;
    sjs_vec3* sjt_dot178;
    sjs_vec3* sjt_dot179;
    sjs_vec3* sjt_dot180;
    sjs_vec3* sjt_functionParam82;
    sjs_vec3* sjt_functionParam85;
    sjs_vec3* sjt_functionParam86;
    sjs_vec3* sjt_functionParam87;
    sjs_vec3* sjt_functionParam88;
    sjs_vec3* sjt_functionParam89;
    float sjt_math163;
    float sjt_math164;
    float sjt_math175;
    float sjt_math176;
    float sjt_math177;
    float sjt_math178;
    sjs_vec3* sjt_parent23;
    sjs_vec3* sjt_parent24;
    sjs_vec3* sjt_parent25;
    sjs_vec3* sjt_parent26;
    sjs_vec3* sjt_parent27;
    sjs_vec3* sjt_parent28;
    sjs_vec3* sjt_parent29;
    sjs_vec3* sjt_parent30;
    sjs_vec3 sjv_temp = { -1 };
    sjs_vec3 sjv_xaxis = { -1 };
    sjs_vec3 sjv_yaxis = { -1 };
    sjs_vec3 sjv_zaxis = { -1 };

    sjt_parent23 = target;
    sjt_functionParam82 = camera;
    sjf_vec3_subtract(sjt_parent23, sjt_functionParam82, &sjv_temp);
    sjt_parent24 = &sjv_temp;
    sjf_vec3_normalize(sjt_parent24, &sjv_zaxis);
    sjt_parent26 = up;
    sjt_functionParam85 = &sjv_zaxis;
    sjf_vec3_cross(sjt_parent26, sjt_functionParam85, &sjt_call5);
    sjt_parent25 = &sjt_call5;
    sjf_vec3_normalize(sjt_parent25, &sjv_xaxis);
    sjt_parent27 = &sjv_zaxis;
    sjt_functionParam86 = &sjv_xaxis;
    sjf_vec3_cross(sjt_parent27, sjt_functionParam86, &sjv_yaxis);
    _return->_refCount = 1;
    sjt_dot172 = &sjv_xaxis;
    _return->m00 = (sjt_dot172)->x;
    sjt_dot173 = &sjv_yaxis;
    _return->m01 = (sjt_dot173)->x;
    sjt_dot174 = &sjv_zaxis;
    _return->m02 = (sjt_dot174)->x;
    _return->m03 = 0.0f;
    sjt_dot175 = &sjv_xaxis;
    _return->m10 = (sjt_dot175)->y;
    sjt_dot176 = &sjv_yaxis;
    _return->m11 = (sjt_dot176)->y;
    sjt_dot177 = &sjv_zaxis;
    _return->m12 = (sjt_dot177)->y;
    _return->m13 = 0.0f;
    sjt_dot178 = &sjv_xaxis;
    _return->m20 = (sjt_dot178)->z;
    sjt_dot179 = &sjv_yaxis;
    _return->m21 = (sjt_dot179)->z;
    sjt_dot180 = &sjv_zaxis;
    _return->m22 = (sjt_dot180)->z;
    _return->m23 = 0.0f;
    sjt_math163 = 0.0f;
    sjt_parent28 = &sjv_xaxis;
    sjt_functionParam87 = camera;
    sjf_vec3_dot(sjt_parent28, sjt_functionParam87, &sjt_math164);
    _return->m30 = sjt_math163 - sjt_math164;
    sjt_math175 = 0.0f;
    sjt_parent29 = &sjv_yaxis;
    sjt_functionParam88 = camera;
    sjf_vec3_dot(sjt_parent29, sjt_functionParam88, &sjt_math176);
    _return->m31 = sjt_math175 - sjt_math176;
    sjt_math177 = 0.0f;
    sjt_parent30 = &sjv_zaxis;
    sjt_functionParam89 = camera;
    sjf_vec3_dot(sjt_parent30, sjt_functionParam89, &sjt_math178);
    _return->m32 = sjt_math177 - sjt_math178;
    _return->m33 = 1.0f;
    sjf_mat4(_return);

    if (sjt_call5._refCount == 1) { sjf_vec3_destroy(&sjt_call5); }
    if (sjv_temp._refCount == 1) { sjf_vec3_destroy(&sjv_temp); }
    if (sjv_xaxis._refCount == 1) { sjf_vec3_destroy(&sjv_xaxis); }
    if (sjv_yaxis._refCount == 1) { sjf_vec3_destroy(&sjv_yaxis); }
    if (sjv_zaxis._refCount == 1) { sjf_vec3_destroy(&sjv_zaxis); }
}

void sjf_mat4_lookatlh_heap(sjs_vec3* camera, sjs_vec3* target, sjs_vec3* up, sjs_mat4** _return) {
    sjs_vec3 sjt_call6 = { -1 };
    sjs_vec3* sjt_dot187;
    sjs_vec3* sjt_dot188;
    sjs_vec3* sjt_dot189;
    sjs_vec3* sjt_dot190;
    sjs_vec3* sjt_dot191;
    sjs_vec3* sjt_dot192;
    sjs_vec3* sjt_dot193;
    sjs_vec3* sjt_dot194;
    sjs_vec3* sjt_dot195;
    sjs_vec3* sjt_functionParam90;
    sjs_vec3* sjt_functionParam91;
    sjs_vec3* sjt_functionParam92;
    sjs_vec3* sjt_functionParam93;
    sjs_vec3* sjt_functionParam94;
    sjs_vec3* sjt_functionParam95;
    float sjt_math179;
    float sjt_math180;
    float sjt_math181;
    float sjt_math182;
    float sjt_math183;
    float sjt_math184;
    sjs_vec3* sjt_parent31;
    sjs_vec3* sjt_parent32;
    sjs_vec3* sjt_parent33;
    sjs_vec3* sjt_parent34;
    sjs_vec3* sjt_parent35;
    sjs_vec3* sjt_parent36;
    sjs_vec3* sjt_parent37;
    sjs_vec3* sjt_parent38;
    sjs_vec3 sjv_temp = { -1 };
    sjs_vec3 sjv_xaxis = { -1 };
    sjs_vec3 sjv_yaxis = { -1 };
    sjs_vec3 sjv_zaxis = { -1 };

    sjt_parent31 = target;
    sjt_functionParam90 = camera;
    sjf_vec3_subtract(sjt_parent31, sjt_functionParam90, &sjv_temp);
    sjt_parent32 = &sjv_temp;
    sjf_vec3_normalize(sjt_parent32, &sjv_zaxis);
    sjt_parent34 = up;
    sjt_functionParam91 = &sjv_zaxis;
    sjf_vec3_cross(sjt_parent34, sjt_functionParam91, &sjt_call6);
    sjt_parent33 = &sjt_call6;
    sjf_vec3_normalize(sjt_parent33, &sjv_xaxis);
    sjt_parent35 = &sjv_zaxis;
    sjt_functionParam92 = &sjv_xaxis;
    sjf_vec3_cross(sjt_parent35, sjt_functionParam92, &sjv_yaxis);
    (*_return) = (sjs_mat4*)malloc(sizeof(sjs_mat4));
    (*_return)->_refCount = 1;
    sjt_dot187 = &sjv_xaxis;
    (*_return)->m00 = (sjt_dot187)->x;
    sjt_dot188 = &sjv_yaxis;
    (*_return)->m01 = (sjt_dot188)->x;
    sjt_dot189 = &sjv_zaxis;
    (*_return)->m02 = (sjt_dot189)->x;
    (*_return)->m03 = 0.0f;
    sjt_dot190 = &sjv_xaxis;
    (*_return)->m10 = (sjt_dot190)->y;
    sjt_dot191 = &sjv_yaxis;
    (*_return)->m11 = (sjt_dot191)->y;
    sjt_dot192 = &sjv_zaxis;
    (*_return)->m12 = (sjt_dot192)->y;
    (*_return)->m13 = 0.0f;
    sjt_dot193 = &sjv_xaxis;
    (*_return)->m20 = (sjt_dot193)->z;
    sjt_dot194 = &sjv_yaxis;
    (*_return)->m21 = (sjt_dot194)->z;
    sjt_dot195 = &sjv_zaxis;
    (*_return)->m22 = (sjt_dot195)->z;
    (*_return)->m23 = 0.0f;
    sjt_math179 = 0.0f;
    sjt_parent36 = &sjv_xaxis;
    sjt_functionParam93 = camera;
    sjf_vec3_dot(sjt_parent36, sjt_functionParam93, &sjt_math180);
    (*_return)->m30 = sjt_math179 - sjt_math180;
    sjt_math181 = 0.0f;
    sjt_parent37 = &sjv_yaxis;
    sjt_functionParam94 = camera;
    sjf_vec3_dot(sjt_parent37, sjt_functionParam94, &sjt_math182);
    (*_return)->m31 = sjt_math181 - sjt_math182;
    sjt_math183 = 0.0f;
    sjt_parent38 = &sjv_zaxis;
    sjt_functionParam95 = camera;
    sjf_vec3_dot(sjt_parent38, sjt_functionParam95, &sjt_math184);
    (*_return)->m32 = sjt_math183 - sjt_math184;
    (*_return)->m33 = 1.0f;
    sjf_mat4_heap((*_return));

    if (sjt_call6._refCount == 1) { sjf_vec3_destroy(&sjt_call6); }
    if (sjv_temp._refCount == 1) { sjf_vec3_destroy(&sjv_temp); }
    if (sjv_xaxis._refCount == 1) { sjf_vec3_destroy(&sjv_xaxis); }
    if (sjv_yaxis._refCount == 1) { sjf_vec3_destroy(&sjv_yaxis); }
    if (sjv_zaxis._refCount == 1) { sjf_vec3_destroy(&sjv_zaxis); }
}

void sjf_mat4_multiply(sjs_mat4* _parent, sjs_mat4* m, sjs_mat4* _return) {
    sjs_mat4* sjt_dot269;
    sjs_mat4* sjt_dot270;
    sjs_mat4* sjt_dot271;
    sjs_mat4* sjt_dot272;
    sjs_mat4* sjt_dot273;
    sjs_mat4* sjt_dot274;
    sjs_mat4* sjt_dot275;
    sjs_mat4* sjt_dot276;
    sjs_mat4* sjt_dot277;
    sjs_mat4* sjt_dot278;
    sjs_mat4* sjt_dot279;
    sjs_mat4* sjt_dot280;
    sjs_mat4* sjt_dot281;
    sjs_mat4* sjt_dot282;
    sjs_mat4* sjt_dot283;
    sjs_mat4* sjt_dot284;
    sjs_mat4* sjt_dot285;
    sjs_mat4* sjt_dot286;
    sjs_mat4* sjt_dot287;
    sjs_mat4* sjt_dot288;
    sjs_mat4* sjt_dot289;
    sjs_mat4* sjt_dot290;
    sjs_mat4* sjt_dot291;
    sjs_mat4* sjt_dot292;
    sjs_mat4* sjt_dot293;
    sjs_mat4* sjt_dot294;
    sjs_mat4* sjt_dot295;
    sjs_mat4* sjt_dot296;
    sjs_mat4* sjt_dot297;
    sjs_mat4* sjt_dot298;
    sjs_mat4* sjt_dot299;
    sjs_mat4* sjt_dot300;
    sjs_mat4* sjt_dot301;
    sjs_mat4* sjt_dot302;
    sjs_mat4* sjt_dot303;
    sjs_mat4* sjt_dot304;
    sjs_mat4* sjt_dot305;
    sjs_mat4* sjt_dot306;
    sjs_mat4* sjt_dot307;
    sjs_mat4* sjt_dot308;
    sjs_mat4* sjt_dot309;
    sjs_mat4* sjt_dot310;
    sjs_mat4* sjt_dot311;
    sjs_mat4* sjt_dot312;
    sjs_mat4* sjt_dot313;
    sjs_mat4* sjt_dot314;
    sjs_mat4* sjt_dot315;
    sjs_mat4* sjt_dot316;
    sjs_mat4* sjt_dot317;
    sjs_mat4* sjt_dot318;
    sjs_mat4* sjt_dot319;
    sjs_mat4* sjt_dot320;
    sjs_mat4* sjt_dot321;
    sjs_mat4* sjt_dot322;
    sjs_mat4* sjt_dot323;
    sjs_mat4* sjt_dot324;
    sjs_mat4* sjt_dot325;
    sjs_mat4* sjt_dot326;
    sjs_mat4* sjt_dot327;
    sjs_mat4* sjt_dot328;
    sjs_mat4* sjt_dot329;
    sjs_mat4* sjt_dot330;
    sjs_mat4* sjt_dot331;
    sjs_mat4* sjt_dot332;
    sjs_mat4* sjt_dot333;
    sjs_mat4* sjt_dot334;
    sjs_mat4* sjt_dot335;
    sjs_mat4* sjt_dot336;
    sjs_mat4* sjt_dot337;
    sjs_mat4* sjt_dot338;
    sjs_mat4* sjt_dot339;
    sjs_mat4* sjt_dot340;
    sjs_mat4* sjt_dot341;
    sjs_mat4* sjt_dot342;
    sjs_mat4* sjt_dot343;
    sjs_mat4* sjt_dot344;
    sjs_mat4* sjt_dot345;
    sjs_mat4* sjt_dot346;
    sjs_mat4* sjt_dot347;
    sjs_mat4* sjt_dot348;
    sjs_mat4* sjt_dot349;
    sjs_mat4* sjt_dot350;
    sjs_mat4* sjt_dot351;
    sjs_mat4* sjt_dot352;
    sjs_mat4* sjt_dot353;
    sjs_mat4* sjt_dot354;
    sjs_mat4* sjt_dot355;
    sjs_mat4* sjt_dot356;
    sjs_mat4* sjt_dot357;
    sjs_mat4* sjt_dot358;
    sjs_mat4* sjt_dot359;
    sjs_mat4* sjt_dot360;
    sjs_mat4* sjt_dot361;
    sjs_mat4* sjt_dot362;
    sjs_mat4* sjt_dot363;
    sjs_mat4* sjt_dot364;
    sjs_mat4* sjt_dot365;
    sjs_mat4* sjt_dot366;
    sjs_mat4* sjt_dot367;
    sjs_mat4* sjt_dot368;
    sjs_mat4* sjt_dot369;
    sjs_mat4* sjt_dot370;
    sjs_mat4* sjt_dot371;
    sjs_mat4* sjt_dot372;
    sjs_mat4* sjt_dot373;
    sjs_mat4* sjt_dot374;
    sjs_mat4* sjt_dot375;
    sjs_mat4* sjt_dot376;
    sjs_mat4* sjt_dot377;
    sjs_mat4* sjt_dot378;
    sjs_mat4* sjt_dot379;
    sjs_mat4* sjt_dot380;
    sjs_mat4* sjt_dot381;
    sjs_mat4* sjt_dot382;
    sjs_mat4* sjt_dot383;
    sjs_mat4* sjt_dot384;
    sjs_mat4* sjt_dot385;
    sjs_mat4* sjt_dot386;
    sjs_mat4* sjt_dot387;
    sjs_mat4* sjt_dot388;
    sjs_mat4* sjt_dot389;
    sjs_mat4* sjt_dot390;
    sjs_mat4* sjt_dot391;
    sjs_mat4* sjt_dot392;
    sjs_mat4* sjt_dot393;
    sjs_mat4* sjt_dot394;
    sjs_mat4* sjt_dot395;
    sjs_mat4* sjt_dot396;
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
    sjt_dot269 = m;
    sjt_math303 = (sjt_dot269)->m00;
    sjt_dot270 = _parent;
    sjt_math304 = (sjt_dot270)->m00;
    sjt_math301 = sjt_math303 * sjt_math304;
    sjt_dot271 = m;
    sjt_math305 = (sjt_dot271)->m01;
    sjt_dot272 = _parent;
    sjt_math306 = (sjt_dot272)->m10;
    sjt_math302 = sjt_math305 * sjt_math306;
    sjt_math299 = sjt_math301 + sjt_math302;
    sjt_dot273 = m;
    sjt_math307 = (sjt_dot273)->m02;
    sjt_dot274 = _parent;
    sjt_math308 = (sjt_dot274)->m20;
    sjt_math300 = sjt_math307 * sjt_math308;
    sjt_math297 = sjt_math299 + sjt_math300;
    sjt_dot275 = m;
    sjt_math309 = (sjt_dot275)->m03;
    sjt_dot276 = _parent;
    sjt_math310 = (sjt_dot276)->m30;
    sjt_math298 = sjt_math309 * sjt_math310;
    _return->m00 = sjt_math297 + sjt_math298;
    sjt_dot277 = m;
    sjt_math317 = (sjt_dot277)->m00;
    sjt_dot278 = _parent;
    sjt_math318 = (sjt_dot278)->m01;
    sjt_math315 = sjt_math317 * sjt_math318;
    sjt_dot279 = m;
    sjt_math319 = (sjt_dot279)->m01;
    sjt_dot280 = _parent;
    sjt_math320 = (sjt_dot280)->m11;
    sjt_math316 = sjt_math319 * sjt_math320;
    sjt_math313 = sjt_math315 + sjt_math316;
    sjt_dot281 = m;
    sjt_math321 = (sjt_dot281)->m02;
    sjt_dot282 = _parent;
    sjt_math322 = (sjt_dot282)->m21;
    sjt_math314 = sjt_math321 * sjt_math322;
    sjt_math311 = sjt_math313 + sjt_math314;
    sjt_dot283 = m;
    sjt_math323 = (sjt_dot283)->m03;
    sjt_dot284 = _parent;
    sjt_math324 = (sjt_dot284)->m31;
    sjt_math312 = sjt_math323 * sjt_math324;
    _return->m01 = sjt_math311 + sjt_math312;
    sjt_dot285 = m;
    sjt_math331 = (sjt_dot285)->m00;
    sjt_dot286 = _parent;
    sjt_math332 = (sjt_dot286)->m02;
    sjt_math329 = sjt_math331 * sjt_math332;
    sjt_dot287 = m;
    sjt_math333 = (sjt_dot287)->m01;
    sjt_dot288 = _parent;
    sjt_math334 = (sjt_dot288)->m12;
    sjt_math330 = sjt_math333 * sjt_math334;
    sjt_math327 = sjt_math329 + sjt_math330;
    sjt_dot289 = m;
    sjt_math335 = (sjt_dot289)->m02;
    sjt_dot290 = _parent;
    sjt_math336 = (sjt_dot290)->m22;
    sjt_math328 = sjt_math335 * sjt_math336;
    sjt_math325 = sjt_math327 + sjt_math328;
    sjt_dot291 = m;
    sjt_math337 = (sjt_dot291)->m03;
    sjt_dot292 = _parent;
    sjt_math338 = (sjt_dot292)->m32;
    sjt_math326 = sjt_math337 * sjt_math338;
    _return->m02 = sjt_math325 + sjt_math326;
    sjt_dot293 = m;
    sjt_math345 = (sjt_dot293)->m00;
    sjt_dot294 = _parent;
    sjt_math346 = (sjt_dot294)->m03;
    sjt_math343 = sjt_math345 * sjt_math346;
    sjt_dot295 = m;
    sjt_math347 = (sjt_dot295)->m01;
    sjt_dot296 = _parent;
    sjt_math348 = (sjt_dot296)->m13;
    sjt_math344 = sjt_math347 * sjt_math348;
    sjt_math341 = sjt_math343 + sjt_math344;
    sjt_dot297 = m;
    sjt_math349 = (sjt_dot297)->m02;
    sjt_dot298 = _parent;
    sjt_math350 = (sjt_dot298)->m23;
    sjt_math342 = sjt_math349 * sjt_math350;
    sjt_math339 = sjt_math341 + sjt_math342;
    sjt_dot299 = m;
    sjt_math351 = (sjt_dot299)->m03;
    sjt_dot300 = _parent;
    sjt_math352 = (sjt_dot300)->m33;
    sjt_math340 = sjt_math351 * sjt_math352;
    _return->m03 = sjt_math339 + sjt_math340;
    sjt_dot301 = m;
    sjt_math359 = (sjt_dot301)->m10;
    sjt_dot302 = _parent;
    sjt_math360 = (sjt_dot302)->m00;
    sjt_math357 = sjt_math359 * sjt_math360;
    sjt_dot303 = m;
    sjt_math361 = (sjt_dot303)->m11;
    sjt_dot304 = _parent;
    sjt_math362 = (sjt_dot304)->m10;
    sjt_math358 = sjt_math361 * sjt_math362;
    sjt_math355 = sjt_math357 + sjt_math358;
    sjt_dot305 = m;
    sjt_math363 = (sjt_dot305)->m12;
    sjt_dot306 = _parent;
    sjt_math364 = (sjt_dot306)->m20;
    sjt_math356 = sjt_math363 * sjt_math364;
    sjt_math353 = sjt_math355 + sjt_math356;
    sjt_dot307 = m;
    sjt_math365 = (sjt_dot307)->m13;
    sjt_dot308 = _parent;
    sjt_math366 = (sjt_dot308)->m30;
    sjt_math354 = sjt_math365 * sjt_math366;
    _return->m10 = sjt_math353 + sjt_math354;
    sjt_dot309 = m;
    sjt_math373 = (sjt_dot309)->m10;
    sjt_dot310 = _parent;
    sjt_math374 = (sjt_dot310)->m01;
    sjt_math371 = sjt_math373 * sjt_math374;
    sjt_dot311 = m;
    sjt_math375 = (sjt_dot311)->m11;
    sjt_dot312 = _parent;
    sjt_math376 = (sjt_dot312)->m11;
    sjt_math372 = sjt_math375 * sjt_math376;
    sjt_math369 = sjt_math371 + sjt_math372;
    sjt_dot313 = m;
    sjt_math377 = (sjt_dot313)->m12;
    sjt_dot314 = _parent;
    sjt_math378 = (sjt_dot314)->m21;
    sjt_math370 = sjt_math377 * sjt_math378;
    sjt_math367 = sjt_math369 + sjt_math370;
    sjt_dot315 = m;
    sjt_math379 = (sjt_dot315)->m13;
    sjt_dot316 = _parent;
    sjt_math380 = (sjt_dot316)->m31;
    sjt_math368 = sjt_math379 * sjt_math380;
    _return->m11 = sjt_math367 + sjt_math368;
    sjt_dot317 = m;
    sjt_math387 = (sjt_dot317)->m10;
    sjt_dot318 = _parent;
    sjt_math388 = (sjt_dot318)->m02;
    sjt_math385 = sjt_math387 * sjt_math388;
    sjt_dot319 = m;
    sjt_math389 = (sjt_dot319)->m11;
    sjt_dot320 = _parent;
    sjt_math390 = (sjt_dot320)->m12;
    sjt_math386 = sjt_math389 * sjt_math390;
    sjt_math383 = sjt_math385 + sjt_math386;
    sjt_dot321 = m;
    sjt_math391 = (sjt_dot321)->m12;
    sjt_dot322 = _parent;
    sjt_math392 = (sjt_dot322)->m22;
    sjt_math384 = sjt_math391 * sjt_math392;
    sjt_math381 = sjt_math383 + sjt_math384;
    sjt_dot323 = m;
    sjt_math393 = (sjt_dot323)->m13;
    sjt_dot324 = _parent;
    sjt_math394 = (sjt_dot324)->m32;
    sjt_math382 = sjt_math393 * sjt_math394;
    _return->m12 = sjt_math381 + sjt_math382;
    sjt_dot325 = m;
    sjt_math401 = (sjt_dot325)->m10;
    sjt_dot326 = _parent;
    sjt_math402 = (sjt_dot326)->m03;
    sjt_math399 = sjt_math401 * sjt_math402;
    sjt_dot327 = m;
    sjt_math403 = (sjt_dot327)->m11;
    sjt_dot328 = _parent;
    sjt_math404 = (sjt_dot328)->m13;
    sjt_math400 = sjt_math403 * sjt_math404;
    sjt_math397 = sjt_math399 + sjt_math400;
    sjt_dot329 = m;
    sjt_math405 = (sjt_dot329)->m12;
    sjt_dot330 = _parent;
    sjt_math406 = (sjt_dot330)->m23;
    sjt_math398 = sjt_math405 * sjt_math406;
    sjt_math395 = sjt_math397 + sjt_math398;
    sjt_dot331 = m;
    sjt_math407 = (sjt_dot331)->m13;
    sjt_dot332 = _parent;
    sjt_math408 = (sjt_dot332)->m33;
    sjt_math396 = sjt_math407 * sjt_math408;
    _return->m13 = sjt_math395 + sjt_math396;
    sjt_dot333 = m;
    sjt_math415 = (sjt_dot333)->m20;
    sjt_dot334 = _parent;
    sjt_math416 = (sjt_dot334)->m00;
    sjt_math413 = sjt_math415 * sjt_math416;
    sjt_dot335 = m;
    sjt_math417 = (sjt_dot335)->m21;
    sjt_dot336 = _parent;
    sjt_math418 = (sjt_dot336)->m10;
    sjt_math414 = sjt_math417 * sjt_math418;
    sjt_math411 = sjt_math413 + sjt_math414;
    sjt_dot337 = m;
    sjt_math419 = (sjt_dot337)->m22;
    sjt_dot338 = _parent;
    sjt_math420 = (sjt_dot338)->m20;
    sjt_math412 = sjt_math419 * sjt_math420;
    sjt_math409 = sjt_math411 + sjt_math412;
    sjt_dot339 = m;
    sjt_math421 = (sjt_dot339)->m23;
    sjt_dot340 = _parent;
    sjt_math422 = (sjt_dot340)->m30;
    sjt_math410 = sjt_math421 * sjt_math422;
    _return->m20 = sjt_math409 + sjt_math410;
    sjt_dot341 = m;
    sjt_math429 = (sjt_dot341)->m20;
    sjt_dot342 = _parent;
    sjt_math430 = (sjt_dot342)->m01;
    sjt_math427 = sjt_math429 * sjt_math430;
    sjt_dot343 = m;
    sjt_math431 = (sjt_dot343)->m21;
    sjt_dot344 = _parent;
    sjt_math432 = (sjt_dot344)->m11;
    sjt_math428 = sjt_math431 * sjt_math432;
    sjt_math425 = sjt_math427 + sjt_math428;
    sjt_dot345 = m;
    sjt_math433 = (sjt_dot345)->m22;
    sjt_dot346 = _parent;
    sjt_math434 = (sjt_dot346)->m21;
    sjt_math426 = sjt_math433 * sjt_math434;
    sjt_math423 = sjt_math425 + sjt_math426;
    sjt_dot347 = m;
    sjt_math435 = (sjt_dot347)->m23;
    sjt_dot348 = _parent;
    sjt_math436 = (sjt_dot348)->m31;
    sjt_math424 = sjt_math435 * sjt_math436;
    _return->m21 = sjt_math423 + sjt_math424;
    sjt_dot349 = m;
    sjt_math443 = (sjt_dot349)->m20;
    sjt_dot350 = _parent;
    sjt_math444 = (sjt_dot350)->m02;
    sjt_math441 = sjt_math443 * sjt_math444;
    sjt_dot351 = m;
    sjt_math445 = (sjt_dot351)->m21;
    sjt_dot352 = _parent;
    sjt_math446 = (sjt_dot352)->m12;
    sjt_math442 = sjt_math445 * sjt_math446;
    sjt_math439 = sjt_math441 + sjt_math442;
    sjt_dot353 = m;
    sjt_math447 = (sjt_dot353)->m22;
    sjt_dot354 = _parent;
    sjt_math448 = (sjt_dot354)->m22;
    sjt_math440 = sjt_math447 * sjt_math448;
    sjt_math437 = sjt_math439 + sjt_math440;
    sjt_dot355 = m;
    sjt_math449 = (sjt_dot355)->m23;
    sjt_dot356 = _parent;
    sjt_math450 = (sjt_dot356)->m32;
    sjt_math438 = sjt_math449 * sjt_math450;
    _return->m22 = sjt_math437 + sjt_math438;
    sjt_dot357 = m;
    sjt_math457 = (sjt_dot357)->m20;
    sjt_dot358 = _parent;
    sjt_math458 = (sjt_dot358)->m03;
    sjt_math455 = sjt_math457 * sjt_math458;
    sjt_dot359 = m;
    sjt_math459 = (sjt_dot359)->m21;
    sjt_dot360 = _parent;
    sjt_math460 = (sjt_dot360)->m13;
    sjt_math456 = sjt_math459 * sjt_math460;
    sjt_math453 = sjt_math455 + sjt_math456;
    sjt_dot361 = m;
    sjt_math461 = (sjt_dot361)->m22;
    sjt_dot362 = _parent;
    sjt_math462 = (sjt_dot362)->m23;
    sjt_math454 = sjt_math461 * sjt_math462;
    sjt_math451 = sjt_math453 + sjt_math454;
    sjt_dot363 = m;
    sjt_math463 = (sjt_dot363)->m23;
    sjt_dot364 = _parent;
    sjt_math464 = (sjt_dot364)->m33;
    sjt_math452 = sjt_math463 * sjt_math464;
    _return->m23 = sjt_math451 + sjt_math452;
    sjt_dot365 = m;
    sjt_math471 = (sjt_dot365)->m30;
    sjt_dot366 = _parent;
    sjt_math472 = (sjt_dot366)->m00;
    sjt_math469 = sjt_math471 * sjt_math472;
    sjt_dot367 = m;
    sjt_math473 = (sjt_dot367)->m31;
    sjt_dot368 = _parent;
    sjt_math474 = (sjt_dot368)->m10;
    sjt_math470 = sjt_math473 * sjt_math474;
    sjt_math467 = sjt_math469 + sjt_math470;
    sjt_dot369 = m;
    sjt_math475 = (sjt_dot369)->m32;
    sjt_dot370 = _parent;
    sjt_math476 = (sjt_dot370)->m20;
    sjt_math468 = sjt_math475 * sjt_math476;
    sjt_math465 = sjt_math467 + sjt_math468;
    sjt_dot371 = m;
    sjt_math477 = (sjt_dot371)->m33;
    sjt_dot372 = _parent;
    sjt_math478 = (sjt_dot372)->m30;
    sjt_math466 = sjt_math477 * sjt_math478;
    _return->m30 = sjt_math465 + sjt_math466;
    sjt_dot373 = m;
    sjt_math485 = (sjt_dot373)->m30;
    sjt_dot374 = _parent;
    sjt_math486 = (sjt_dot374)->m01;
    sjt_math483 = sjt_math485 * sjt_math486;
    sjt_dot375 = m;
    sjt_math487 = (sjt_dot375)->m31;
    sjt_dot376 = _parent;
    sjt_math488 = (sjt_dot376)->m11;
    sjt_math484 = sjt_math487 * sjt_math488;
    sjt_math481 = sjt_math483 + sjt_math484;
    sjt_dot377 = m;
    sjt_math489 = (sjt_dot377)->m32;
    sjt_dot378 = _parent;
    sjt_math490 = (sjt_dot378)->m21;
    sjt_math482 = sjt_math489 * sjt_math490;
    sjt_math479 = sjt_math481 + sjt_math482;
    sjt_dot379 = m;
    sjt_math491 = (sjt_dot379)->m33;
    sjt_dot380 = _parent;
    sjt_math492 = (sjt_dot380)->m31;
    sjt_math480 = sjt_math491 * sjt_math492;
    _return->m31 = sjt_math479 + sjt_math480;
    sjt_dot381 = m;
    sjt_math499 = (sjt_dot381)->m30;
    sjt_dot382 = _parent;
    sjt_math500 = (sjt_dot382)->m02;
    sjt_math497 = sjt_math499 * sjt_math500;
    sjt_dot383 = m;
    sjt_math501 = (sjt_dot383)->m31;
    sjt_dot384 = _parent;
    sjt_math502 = (sjt_dot384)->m12;
    sjt_math498 = sjt_math501 * sjt_math502;
    sjt_math495 = sjt_math497 + sjt_math498;
    sjt_dot385 = m;
    sjt_math503 = (sjt_dot385)->m32;
    sjt_dot386 = _parent;
    sjt_math504 = (sjt_dot386)->m22;
    sjt_math496 = sjt_math503 * sjt_math504;
    sjt_math493 = sjt_math495 + sjt_math496;
    sjt_dot387 = m;
    sjt_math505 = (sjt_dot387)->m33;
    sjt_dot388 = _parent;
    sjt_math506 = (sjt_dot388)->m32;
    sjt_math494 = sjt_math505 * sjt_math506;
    _return->m32 = sjt_math493 + sjt_math494;
    sjt_dot389 = m;
    sjt_math513 = (sjt_dot389)->m30;
    sjt_dot390 = _parent;
    sjt_math514 = (sjt_dot390)->m03;
    sjt_math511 = sjt_math513 * sjt_math514;
    sjt_dot391 = m;
    sjt_math515 = (sjt_dot391)->m31;
    sjt_dot392 = _parent;
    sjt_math516 = (sjt_dot392)->m13;
    sjt_math512 = sjt_math515 * sjt_math516;
    sjt_math509 = sjt_math511 + sjt_math512;
    sjt_dot393 = m;
    sjt_math517 = (sjt_dot393)->m32;
    sjt_dot394 = _parent;
    sjt_math518 = (sjt_dot394)->m23;
    sjt_math510 = sjt_math517 * sjt_math518;
    sjt_math507 = sjt_math509 + sjt_math510;
    sjt_dot395 = m;
    sjt_math519 = (sjt_dot395)->m33;
    sjt_dot396 = _parent;
    sjt_math520 = (sjt_dot396)->m33;
    sjt_math508 = sjt_math519 * sjt_math520;
    _return->m33 = sjt_math507 + sjt_math508;
    sjf_mat4(_return);
}

void sjf_mat4_multiply_heap(sjs_mat4* _parent, sjs_mat4* m, sjs_mat4** _return) {
    sjs_mat4* sjt_dot397;
    sjs_mat4* sjt_dot398;
    sjs_mat4* sjt_dot399;
    sjs_mat4* sjt_dot400;
    sjs_mat4* sjt_dot401;
    sjs_mat4* sjt_dot402;
    sjs_mat4* sjt_dot403;
    sjs_mat4* sjt_dot404;
    sjs_mat4* sjt_dot405;
    sjs_mat4* sjt_dot406;
    sjs_mat4* sjt_dot407;
    sjs_mat4* sjt_dot408;
    sjs_mat4* sjt_dot409;
    sjs_mat4* sjt_dot410;
    sjs_mat4* sjt_dot411;
    sjs_mat4* sjt_dot412;
    sjs_mat4* sjt_dot413;
    sjs_mat4* sjt_dot414;
    sjs_mat4* sjt_dot415;
    sjs_mat4* sjt_dot416;
    sjs_mat4* sjt_dot417;
    sjs_mat4* sjt_dot418;
    sjs_mat4* sjt_dot419;
    sjs_mat4* sjt_dot420;
    sjs_mat4* sjt_dot421;
    sjs_mat4* sjt_dot422;
    sjs_mat4* sjt_dot423;
    sjs_mat4* sjt_dot424;
    sjs_mat4* sjt_dot425;
    sjs_mat4* sjt_dot426;
    sjs_mat4* sjt_dot427;
    sjs_mat4* sjt_dot428;
    sjs_mat4* sjt_dot429;
    sjs_mat4* sjt_dot430;
    sjs_mat4* sjt_dot431;
    sjs_mat4* sjt_dot432;
    sjs_mat4* sjt_dot433;
    sjs_mat4* sjt_dot434;
    sjs_mat4* sjt_dot435;
    sjs_mat4* sjt_dot436;
    sjs_mat4* sjt_dot437;
    sjs_mat4* sjt_dot438;
    sjs_mat4* sjt_dot439;
    sjs_mat4* sjt_dot440;
    sjs_mat4* sjt_dot441;
    sjs_mat4* sjt_dot442;
    sjs_mat4* sjt_dot443;
    sjs_mat4* sjt_dot444;
    sjs_mat4* sjt_dot445;
    sjs_mat4* sjt_dot446;
    sjs_mat4* sjt_dot447;
    sjs_mat4* sjt_dot448;
    sjs_mat4* sjt_dot449;
    sjs_mat4* sjt_dot450;
    sjs_mat4* sjt_dot451;
    sjs_mat4* sjt_dot452;
    sjs_mat4* sjt_dot453;
    sjs_mat4* sjt_dot454;
    sjs_mat4* sjt_dot455;
    sjs_mat4* sjt_dot456;
    sjs_mat4* sjt_dot457;
    sjs_mat4* sjt_dot458;
    sjs_mat4* sjt_dot459;
    sjs_mat4* sjt_dot460;
    sjs_mat4* sjt_dot461;
    sjs_mat4* sjt_dot462;
    sjs_mat4* sjt_dot463;
    sjs_mat4* sjt_dot464;
    sjs_mat4* sjt_dot465;
    sjs_mat4* sjt_dot466;
    sjs_mat4* sjt_dot467;
    sjs_mat4* sjt_dot468;
    sjs_mat4* sjt_dot469;
    sjs_mat4* sjt_dot470;
    sjs_mat4* sjt_dot471;
    sjs_mat4* sjt_dot472;
    sjs_mat4* sjt_dot473;
    sjs_mat4* sjt_dot474;
    sjs_mat4* sjt_dot475;
    sjs_mat4* sjt_dot476;
    sjs_mat4* sjt_dot477;
    sjs_mat4* sjt_dot478;
    sjs_mat4* sjt_dot479;
    sjs_mat4* sjt_dot480;
    sjs_mat4* sjt_dot481;
    sjs_mat4* sjt_dot482;
    sjs_mat4* sjt_dot483;
    sjs_mat4* sjt_dot484;
    sjs_mat4* sjt_dot485;
    sjs_mat4* sjt_dot486;
    sjs_mat4* sjt_dot487;
    sjs_mat4* sjt_dot488;
    sjs_mat4* sjt_dot489;
    sjs_mat4* sjt_dot490;
    sjs_mat4* sjt_dot491;
    sjs_mat4* sjt_dot492;
    sjs_mat4* sjt_dot493;
    sjs_mat4* sjt_dot494;
    sjs_mat4* sjt_dot495;
    sjs_mat4* sjt_dot496;
    sjs_mat4* sjt_dot497;
    sjs_mat4* sjt_dot498;
    sjs_mat4* sjt_dot499;
    sjs_mat4* sjt_dot500;
    sjs_mat4* sjt_dot501;
    sjs_mat4* sjt_dot502;
    sjs_mat4* sjt_dot503;
    sjs_mat4* sjt_dot504;
    sjs_mat4* sjt_dot505;
    sjs_mat4* sjt_dot506;
    sjs_mat4* sjt_dot507;
    sjs_mat4* sjt_dot508;
    sjs_mat4* sjt_dot509;
    sjs_mat4* sjt_dot510;
    sjs_mat4* sjt_dot511;
    sjs_mat4* sjt_dot512;
    sjs_mat4* sjt_dot513;
    sjs_mat4* sjt_dot514;
    sjs_mat4* sjt_dot515;
    sjs_mat4* sjt_dot516;
    sjs_mat4* sjt_dot517;
    sjs_mat4* sjt_dot518;
    sjs_mat4* sjt_dot519;
    sjs_mat4* sjt_dot520;
    sjs_mat4* sjt_dot521;
    sjs_mat4* sjt_dot522;
    sjs_mat4* sjt_dot523;
    sjs_mat4* sjt_dot524;
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
    sjt_dot397 = m;
    sjt_math527 = (sjt_dot397)->m00;
    sjt_dot398 = _parent;
    sjt_math528 = (sjt_dot398)->m00;
    sjt_math525 = sjt_math527 * sjt_math528;
    sjt_dot399 = m;
    sjt_math529 = (sjt_dot399)->m01;
    sjt_dot400 = _parent;
    sjt_math530 = (sjt_dot400)->m10;
    sjt_math526 = sjt_math529 * sjt_math530;
    sjt_math523 = sjt_math525 + sjt_math526;
    sjt_dot401 = m;
    sjt_math531 = (sjt_dot401)->m02;
    sjt_dot402 = _parent;
    sjt_math532 = (sjt_dot402)->m20;
    sjt_math524 = sjt_math531 * sjt_math532;
    sjt_math521 = sjt_math523 + sjt_math524;
    sjt_dot403 = m;
    sjt_math533 = (sjt_dot403)->m03;
    sjt_dot404 = _parent;
    sjt_math534 = (sjt_dot404)->m30;
    sjt_math522 = sjt_math533 * sjt_math534;
    (*_return)->m00 = sjt_math521 + sjt_math522;
    sjt_dot405 = m;
    sjt_math541 = (sjt_dot405)->m00;
    sjt_dot406 = _parent;
    sjt_math542 = (sjt_dot406)->m01;
    sjt_math539 = sjt_math541 * sjt_math542;
    sjt_dot407 = m;
    sjt_math543 = (sjt_dot407)->m01;
    sjt_dot408 = _parent;
    sjt_math544 = (sjt_dot408)->m11;
    sjt_math540 = sjt_math543 * sjt_math544;
    sjt_math537 = sjt_math539 + sjt_math540;
    sjt_dot409 = m;
    sjt_math545 = (sjt_dot409)->m02;
    sjt_dot410 = _parent;
    sjt_math546 = (sjt_dot410)->m21;
    sjt_math538 = sjt_math545 * sjt_math546;
    sjt_math535 = sjt_math537 + sjt_math538;
    sjt_dot411 = m;
    sjt_math547 = (sjt_dot411)->m03;
    sjt_dot412 = _parent;
    sjt_math548 = (sjt_dot412)->m31;
    sjt_math536 = sjt_math547 * sjt_math548;
    (*_return)->m01 = sjt_math535 + sjt_math536;
    sjt_dot413 = m;
    sjt_math555 = (sjt_dot413)->m00;
    sjt_dot414 = _parent;
    sjt_math556 = (sjt_dot414)->m02;
    sjt_math553 = sjt_math555 * sjt_math556;
    sjt_dot415 = m;
    sjt_math557 = (sjt_dot415)->m01;
    sjt_dot416 = _parent;
    sjt_math558 = (sjt_dot416)->m12;
    sjt_math554 = sjt_math557 * sjt_math558;
    sjt_math551 = sjt_math553 + sjt_math554;
    sjt_dot417 = m;
    sjt_math559 = (sjt_dot417)->m02;
    sjt_dot418 = _parent;
    sjt_math560 = (sjt_dot418)->m22;
    sjt_math552 = sjt_math559 * sjt_math560;
    sjt_math549 = sjt_math551 + sjt_math552;
    sjt_dot419 = m;
    sjt_math561 = (sjt_dot419)->m03;
    sjt_dot420 = _parent;
    sjt_math562 = (sjt_dot420)->m32;
    sjt_math550 = sjt_math561 * sjt_math562;
    (*_return)->m02 = sjt_math549 + sjt_math550;
    sjt_dot421 = m;
    sjt_math569 = (sjt_dot421)->m00;
    sjt_dot422 = _parent;
    sjt_math570 = (sjt_dot422)->m03;
    sjt_math567 = sjt_math569 * sjt_math570;
    sjt_dot423 = m;
    sjt_math571 = (sjt_dot423)->m01;
    sjt_dot424 = _parent;
    sjt_math572 = (sjt_dot424)->m13;
    sjt_math568 = sjt_math571 * sjt_math572;
    sjt_math565 = sjt_math567 + sjt_math568;
    sjt_dot425 = m;
    sjt_math573 = (sjt_dot425)->m02;
    sjt_dot426 = _parent;
    sjt_math574 = (sjt_dot426)->m23;
    sjt_math566 = sjt_math573 * sjt_math574;
    sjt_math563 = sjt_math565 + sjt_math566;
    sjt_dot427 = m;
    sjt_math575 = (sjt_dot427)->m03;
    sjt_dot428 = _parent;
    sjt_math576 = (sjt_dot428)->m33;
    sjt_math564 = sjt_math575 * sjt_math576;
    (*_return)->m03 = sjt_math563 + sjt_math564;
    sjt_dot429 = m;
    sjt_math583 = (sjt_dot429)->m10;
    sjt_dot430 = _parent;
    sjt_math584 = (sjt_dot430)->m00;
    sjt_math581 = sjt_math583 * sjt_math584;
    sjt_dot431 = m;
    sjt_math585 = (sjt_dot431)->m11;
    sjt_dot432 = _parent;
    sjt_math586 = (sjt_dot432)->m10;
    sjt_math582 = sjt_math585 * sjt_math586;
    sjt_math579 = sjt_math581 + sjt_math582;
    sjt_dot433 = m;
    sjt_math587 = (sjt_dot433)->m12;
    sjt_dot434 = _parent;
    sjt_math588 = (sjt_dot434)->m20;
    sjt_math580 = sjt_math587 * sjt_math588;
    sjt_math577 = sjt_math579 + sjt_math580;
    sjt_dot435 = m;
    sjt_math589 = (sjt_dot435)->m13;
    sjt_dot436 = _parent;
    sjt_math590 = (sjt_dot436)->m30;
    sjt_math578 = sjt_math589 * sjt_math590;
    (*_return)->m10 = sjt_math577 + sjt_math578;
    sjt_dot437 = m;
    sjt_math597 = (sjt_dot437)->m10;
    sjt_dot438 = _parent;
    sjt_math598 = (sjt_dot438)->m01;
    sjt_math595 = sjt_math597 * sjt_math598;
    sjt_dot439 = m;
    sjt_math599 = (sjt_dot439)->m11;
    sjt_dot440 = _parent;
    sjt_math600 = (sjt_dot440)->m11;
    sjt_math596 = sjt_math599 * sjt_math600;
    sjt_math593 = sjt_math595 + sjt_math596;
    sjt_dot441 = m;
    sjt_math601 = (sjt_dot441)->m12;
    sjt_dot442 = _parent;
    sjt_math602 = (sjt_dot442)->m21;
    sjt_math594 = sjt_math601 * sjt_math602;
    sjt_math591 = sjt_math593 + sjt_math594;
    sjt_dot443 = m;
    sjt_math603 = (sjt_dot443)->m13;
    sjt_dot444 = _parent;
    sjt_math604 = (sjt_dot444)->m31;
    sjt_math592 = sjt_math603 * sjt_math604;
    (*_return)->m11 = sjt_math591 + sjt_math592;
    sjt_dot445 = m;
    sjt_math611 = (sjt_dot445)->m10;
    sjt_dot446 = _parent;
    sjt_math612 = (sjt_dot446)->m02;
    sjt_math609 = sjt_math611 * sjt_math612;
    sjt_dot447 = m;
    sjt_math613 = (sjt_dot447)->m11;
    sjt_dot448 = _parent;
    sjt_math614 = (sjt_dot448)->m12;
    sjt_math610 = sjt_math613 * sjt_math614;
    sjt_math607 = sjt_math609 + sjt_math610;
    sjt_dot449 = m;
    sjt_math615 = (sjt_dot449)->m12;
    sjt_dot450 = _parent;
    sjt_math616 = (sjt_dot450)->m22;
    sjt_math608 = sjt_math615 * sjt_math616;
    sjt_math605 = sjt_math607 + sjt_math608;
    sjt_dot451 = m;
    sjt_math617 = (sjt_dot451)->m13;
    sjt_dot452 = _parent;
    sjt_math618 = (sjt_dot452)->m32;
    sjt_math606 = sjt_math617 * sjt_math618;
    (*_return)->m12 = sjt_math605 + sjt_math606;
    sjt_dot453 = m;
    sjt_math625 = (sjt_dot453)->m10;
    sjt_dot454 = _parent;
    sjt_math626 = (sjt_dot454)->m03;
    sjt_math623 = sjt_math625 * sjt_math626;
    sjt_dot455 = m;
    sjt_math627 = (sjt_dot455)->m11;
    sjt_dot456 = _parent;
    sjt_math628 = (sjt_dot456)->m13;
    sjt_math624 = sjt_math627 * sjt_math628;
    sjt_math621 = sjt_math623 + sjt_math624;
    sjt_dot457 = m;
    sjt_math629 = (sjt_dot457)->m12;
    sjt_dot458 = _parent;
    sjt_math630 = (sjt_dot458)->m23;
    sjt_math622 = sjt_math629 * sjt_math630;
    sjt_math619 = sjt_math621 + sjt_math622;
    sjt_dot459 = m;
    sjt_math631 = (sjt_dot459)->m13;
    sjt_dot460 = _parent;
    sjt_math632 = (sjt_dot460)->m33;
    sjt_math620 = sjt_math631 * sjt_math632;
    (*_return)->m13 = sjt_math619 + sjt_math620;
    sjt_dot461 = m;
    sjt_math639 = (sjt_dot461)->m20;
    sjt_dot462 = _parent;
    sjt_math640 = (sjt_dot462)->m00;
    sjt_math637 = sjt_math639 * sjt_math640;
    sjt_dot463 = m;
    sjt_math641 = (sjt_dot463)->m21;
    sjt_dot464 = _parent;
    sjt_math642 = (sjt_dot464)->m10;
    sjt_math638 = sjt_math641 * sjt_math642;
    sjt_math635 = sjt_math637 + sjt_math638;
    sjt_dot465 = m;
    sjt_math643 = (sjt_dot465)->m22;
    sjt_dot466 = _parent;
    sjt_math644 = (sjt_dot466)->m20;
    sjt_math636 = sjt_math643 * sjt_math644;
    sjt_math633 = sjt_math635 + sjt_math636;
    sjt_dot467 = m;
    sjt_math645 = (sjt_dot467)->m23;
    sjt_dot468 = _parent;
    sjt_math646 = (sjt_dot468)->m30;
    sjt_math634 = sjt_math645 * sjt_math646;
    (*_return)->m20 = sjt_math633 + sjt_math634;
    sjt_dot469 = m;
    sjt_math653 = (sjt_dot469)->m20;
    sjt_dot470 = _parent;
    sjt_math654 = (sjt_dot470)->m01;
    sjt_math651 = sjt_math653 * sjt_math654;
    sjt_dot471 = m;
    sjt_math655 = (sjt_dot471)->m21;
    sjt_dot472 = _parent;
    sjt_math656 = (sjt_dot472)->m11;
    sjt_math652 = sjt_math655 * sjt_math656;
    sjt_math649 = sjt_math651 + sjt_math652;
    sjt_dot473 = m;
    sjt_math657 = (sjt_dot473)->m22;
    sjt_dot474 = _parent;
    sjt_math658 = (sjt_dot474)->m21;
    sjt_math650 = sjt_math657 * sjt_math658;
    sjt_math647 = sjt_math649 + sjt_math650;
    sjt_dot475 = m;
    sjt_math659 = (sjt_dot475)->m23;
    sjt_dot476 = _parent;
    sjt_math660 = (sjt_dot476)->m31;
    sjt_math648 = sjt_math659 * sjt_math660;
    (*_return)->m21 = sjt_math647 + sjt_math648;
    sjt_dot477 = m;
    sjt_math667 = (sjt_dot477)->m20;
    sjt_dot478 = _parent;
    sjt_math668 = (sjt_dot478)->m02;
    sjt_math665 = sjt_math667 * sjt_math668;
    sjt_dot479 = m;
    sjt_math669 = (sjt_dot479)->m21;
    sjt_dot480 = _parent;
    sjt_math670 = (sjt_dot480)->m12;
    sjt_math666 = sjt_math669 * sjt_math670;
    sjt_math663 = sjt_math665 + sjt_math666;
    sjt_dot481 = m;
    sjt_math671 = (sjt_dot481)->m22;
    sjt_dot482 = _parent;
    sjt_math672 = (sjt_dot482)->m22;
    sjt_math664 = sjt_math671 * sjt_math672;
    sjt_math661 = sjt_math663 + sjt_math664;
    sjt_dot483 = m;
    sjt_math673 = (sjt_dot483)->m23;
    sjt_dot484 = _parent;
    sjt_math674 = (sjt_dot484)->m32;
    sjt_math662 = sjt_math673 * sjt_math674;
    (*_return)->m22 = sjt_math661 + sjt_math662;
    sjt_dot485 = m;
    sjt_math681 = (sjt_dot485)->m20;
    sjt_dot486 = _parent;
    sjt_math682 = (sjt_dot486)->m03;
    sjt_math679 = sjt_math681 * sjt_math682;
    sjt_dot487 = m;
    sjt_math683 = (sjt_dot487)->m21;
    sjt_dot488 = _parent;
    sjt_math684 = (sjt_dot488)->m13;
    sjt_math680 = sjt_math683 * sjt_math684;
    sjt_math677 = sjt_math679 + sjt_math680;
    sjt_dot489 = m;
    sjt_math685 = (sjt_dot489)->m22;
    sjt_dot490 = _parent;
    sjt_math686 = (sjt_dot490)->m23;
    sjt_math678 = sjt_math685 * sjt_math686;
    sjt_math675 = sjt_math677 + sjt_math678;
    sjt_dot491 = m;
    sjt_math687 = (sjt_dot491)->m23;
    sjt_dot492 = _parent;
    sjt_math688 = (sjt_dot492)->m33;
    sjt_math676 = sjt_math687 * sjt_math688;
    (*_return)->m23 = sjt_math675 + sjt_math676;
    sjt_dot493 = m;
    sjt_math695 = (sjt_dot493)->m30;
    sjt_dot494 = _parent;
    sjt_math696 = (sjt_dot494)->m00;
    sjt_math693 = sjt_math695 * sjt_math696;
    sjt_dot495 = m;
    sjt_math697 = (sjt_dot495)->m31;
    sjt_dot496 = _parent;
    sjt_math698 = (sjt_dot496)->m10;
    sjt_math694 = sjt_math697 * sjt_math698;
    sjt_math691 = sjt_math693 + sjt_math694;
    sjt_dot497 = m;
    sjt_math699 = (sjt_dot497)->m32;
    sjt_dot498 = _parent;
    sjt_math700 = (sjt_dot498)->m20;
    sjt_math692 = sjt_math699 * sjt_math700;
    sjt_math689 = sjt_math691 + sjt_math692;
    sjt_dot499 = m;
    sjt_math701 = (sjt_dot499)->m33;
    sjt_dot500 = _parent;
    sjt_math702 = (sjt_dot500)->m30;
    sjt_math690 = sjt_math701 * sjt_math702;
    (*_return)->m30 = sjt_math689 + sjt_math690;
    sjt_dot501 = m;
    sjt_math709 = (sjt_dot501)->m30;
    sjt_dot502 = _parent;
    sjt_math710 = (sjt_dot502)->m01;
    sjt_math707 = sjt_math709 * sjt_math710;
    sjt_dot503 = m;
    sjt_math711 = (sjt_dot503)->m31;
    sjt_dot504 = _parent;
    sjt_math712 = (sjt_dot504)->m11;
    sjt_math708 = sjt_math711 * sjt_math712;
    sjt_math705 = sjt_math707 + sjt_math708;
    sjt_dot505 = m;
    sjt_math713 = (sjt_dot505)->m32;
    sjt_dot506 = _parent;
    sjt_math714 = (sjt_dot506)->m21;
    sjt_math706 = sjt_math713 * sjt_math714;
    sjt_math703 = sjt_math705 + sjt_math706;
    sjt_dot507 = m;
    sjt_math715 = (sjt_dot507)->m33;
    sjt_dot508 = _parent;
    sjt_math716 = (sjt_dot508)->m31;
    sjt_math704 = sjt_math715 * sjt_math716;
    (*_return)->m31 = sjt_math703 + sjt_math704;
    sjt_dot509 = m;
    sjt_math723 = (sjt_dot509)->m30;
    sjt_dot510 = _parent;
    sjt_math724 = (sjt_dot510)->m02;
    sjt_math721 = sjt_math723 * sjt_math724;
    sjt_dot511 = m;
    sjt_math725 = (sjt_dot511)->m31;
    sjt_dot512 = _parent;
    sjt_math726 = (sjt_dot512)->m12;
    sjt_math722 = sjt_math725 * sjt_math726;
    sjt_math719 = sjt_math721 + sjt_math722;
    sjt_dot513 = m;
    sjt_math727 = (sjt_dot513)->m32;
    sjt_dot514 = _parent;
    sjt_math728 = (sjt_dot514)->m22;
    sjt_math720 = sjt_math727 * sjt_math728;
    sjt_math717 = sjt_math719 + sjt_math720;
    sjt_dot515 = m;
    sjt_math729 = (sjt_dot515)->m33;
    sjt_dot516 = _parent;
    sjt_math730 = (sjt_dot516)->m32;
    sjt_math718 = sjt_math729 * sjt_math730;
    (*_return)->m32 = sjt_math717 + sjt_math718;
    sjt_dot517 = m;
    sjt_math737 = (sjt_dot517)->m30;
    sjt_dot518 = _parent;
    sjt_math738 = (sjt_dot518)->m03;
    sjt_math735 = sjt_math737 * sjt_math738;
    sjt_dot519 = m;
    sjt_math739 = (sjt_dot519)->m31;
    sjt_dot520 = _parent;
    sjt_math740 = (sjt_dot520)->m13;
    sjt_math736 = sjt_math739 * sjt_math740;
    sjt_math733 = sjt_math735 + sjt_math736;
    sjt_dot521 = m;
    sjt_math741 = (sjt_dot521)->m32;
    sjt_dot522 = _parent;
    sjt_math742 = (sjt_dot522)->m23;
    sjt_math734 = sjt_math741 * sjt_math742;
    sjt_math731 = sjt_math733 + sjt_math734;
    sjt_dot523 = m;
    sjt_math743 = (sjt_dot523)->m33;
    sjt_dot524 = _parent;
    sjt_math744 = (sjt_dot524)->m33;
    sjt_math732 = sjt_math743 * sjt_math744;
    (*_return)->m33 = sjt_math731 + sjt_math732;
    sjf_mat4_heap((*_return));
}

void sjf_mat4_multiplyf32(sjs_mat4* _parent, float x, sjs_mat4* _return) {
    sjs_mat4* sjt_dot881;
    sjs_mat4* sjt_dot882;
    sjs_mat4* sjt_dot883;
    sjs_mat4* sjt_dot884;
    sjs_mat4* sjt_dot885;
    sjs_mat4* sjt_dot886;
    sjs_mat4* sjt_dot887;
    sjs_mat4* sjt_dot888;
    sjs_mat4* sjt_dot889;
    sjs_mat4* sjt_dot890;
    sjs_mat4* sjt_dot891;
    sjs_mat4* sjt_dot892;
    sjs_mat4* sjt_dot893;
    sjs_mat4* sjt_dot894;
    sjs_mat4* sjt_dot895;
    sjs_mat4* sjt_dot896;
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
    sjt_dot881 = _parent;
    sjt_math1297 = (sjt_dot881)->m00;
    sjt_math1298 = x;
    _return->m00 = sjt_math1297 * sjt_math1298;
    sjt_dot882 = _parent;
    sjt_math1299 = (sjt_dot882)->m01;
    sjt_math1300 = x;
    _return->m01 = sjt_math1299 * sjt_math1300;
    sjt_dot883 = _parent;
    sjt_math1301 = (sjt_dot883)->m02;
    sjt_math1302 = x;
    _return->m02 = sjt_math1301 * sjt_math1302;
    sjt_dot884 = _parent;
    sjt_math1303 = (sjt_dot884)->m03;
    sjt_math1304 = x;
    _return->m03 = sjt_math1303 * sjt_math1304;
    sjt_dot885 = _parent;
    sjt_math1305 = (sjt_dot885)->m10;
    sjt_math1306 = x;
    _return->m10 = sjt_math1305 * sjt_math1306;
    sjt_dot886 = _parent;
    sjt_math1307 = (sjt_dot886)->m11;
    sjt_math1308 = x;
    _return->m11 = sjt_math1307 * sjt_math1308;
    sjt_dot887 = _parent;
    sjt_math1309 = (sjt_dot887)->m12;
    sjt_math1310 = x;
    _return->m12 = sjt_math1309 * sjt_math1310;
    sjt_dot888 = _parent;
    sjt_math1311 = (sjt_dot888)->m13;
    sjt_math1312 = x;
    _return->m13 = sjt_math1311 * sjt_math1312;
    sjt_dot889 = _parent;
    sjt_math1313 = (sjt_dot889)->m20;
    sjt_math1314 = x;
    _return->m20 = sjt_math1313 * sjt_math1314;
    sjt_dot890 = _parent;
    sjt_math1315 = (sjt_dot890)->m21;
    sjt_math1316 = x;
    _return->m21 = sjt_math1315 * sjt_math1316;
    sjt_dot891 = _parent;
    sjt_math1317 = (sjt_dot891)->m22;
    sjt_math1318 = x;
    _return->m22 = sjt_math1317 * sjt_math1318;
    sjt_dot892 = _parent;
    sjt_math1319 = (sjt_dot892)->m23;
    sjt_math1320 = x;
    _return->m23 = sjt_math1319 * sjt_math1320;
    sjt_dot893 = _parent;
    sjt_math1321 = (sjt_dot893)->m30;
    sjt_math1322 = x;
    _return->m30 = sjt_math1321 * sjt_math1322;
    sjt_dot894 = _parent;
    sjt_math1323 = (sjt_dot894)->m31;
    sjt_math1324 = x;
    _return->m31 = sjt_math1323 * sjt_math1324;
    sjt_dot895 = _parent;
    sjt_math1325 = (sjt_dot895)->m32;
    sjt_math1326 = x;
    _return->m32 = sjt_math1325 * sjt_math1326;
    sjt_dot896 = _parent;
    sjt_math1327 = (sjt_dot896)->m33;
    sjt_math1328 = x;
    _return->m33 = sjt_math1327 * sjt_math1328;
    sjf_mat4(_return);
}

void sjf_mat4_multiplyf32_heap(sjs_mat4* _parent, float x, sjs_mat4** _return) {
    sjs_mat4* sjt_dot897;
    sjs_mat4* sjt_dot898;
    sjs_mat4* sjt_dot899;
    sjs_mat4* sjt_dot900;
    sjs_mat4* sjt_dot901;
    sjs_mat4* sjt_dot902;
    sjs_mat4* sjt_dot903;
    sjs_mat4* sjt_dot904;
    sjs_mat4* sjt_dot905;
    sjs_mat4* sjt_dot906;
    sjs_mat4* sjt_dot907;
    sjs_mat4* sjt_dot908;
    sjs_mat4* sjt_dot909;
    sjs_mat4* sjt_dot910;
    sjs_mat4* sjt_dot911;
    sjs_mat4* sjt_dot912;
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
    sjt_dot897 = _parent;
    sjt_math1329 = (sjt_dot897)->m00;
    sjt_math1330 = x;
    (*_return)->m00 = sjt_math1329 * sjt_math1330;
    sjt_dot898 = _parent;
    sjt_math1331 = (sjt_dot898)->m01;
    sjt_math1332 = x;
    (*_return)->m01 = sjt_math1331 * sjt_math1332;
    sjt_dot899 = _parent;
    sjt_math1333 = (sjt_dot899)->m02;
    sjt_math1334 = x;
    (*_return)->m02 = sjt_math1333 * sjt_math1334;
    sjt_dot900 = _parent;
    sjt_math1335 = (sjt_dot900)->m03;
    sjt_math1336 = x;
    (*_return)->m03 = sjt_math1335 * sjt_math1336;
    sjt_dot901 = _parent;
    sjt_math1337 = (sjt_dot901)->m10;
    sjt_math1338 = x;
    (*_return)->m10 = sjt_math1337 * sjt_math1338;
    sjt_dot902 = _parent;
    sjt_math1339 = (sjt_dot902)->m11;
    sjt_math1340 = x;
    (*_return)->m11 = sjt_math1339 * sjt_math1340;
    sjt_dot903 = _parent;
    sjt_math1341 = (sjt_dot903)->m12;
    sjt_math1342 = x;
    (*_return)->m12 = sjt_math1341 * sjt_math1342;
    sjt_dot904 = _parent;
    sjt_math1343 = (sjt_dot904)->m13;
    sjt_math1344 = x;
    (*_return)->m13 = sjt_math1343 * sjt_math1344;
    sjt_dot905 = _parent;
    sjt_math1345 = (sjt_dot905)->m20;
    sjt_math1346 = x;
    (*_return)->m20 = sjt_math1345 * sjt_math1346;
    sjt_dot906 = _parent;
    sjt_math1347 = (sjt_dot906)->m21;
    sjt_math1348 = x;
    (*_return)->m21 = sjt_math1347 * sjt_math1348;
    sjt_dot907 = _parent;
    sjt_math1349 = (sjt_dot907)->m22;
    sjt_math1350 = x;
    (*_return)->m22 = sjt_math1349 * sjt_math1350;
    sjt_dot908 = _parent;
    sjt_math1351 = (sjt_dot908)->m23;
    sjt_math1352 = x;
    (*_return)->m23 = sjt_math1351 * sjt_math1352;
    sjt_dot909 = _parent;
    sjt_math1353 = (sjt_dot909)->m30;
    sjt_math1354 = x;
    (*_return)->m30 = sjt_math1353 * sjt_math1354;
    sjt_dot910 = _parent;
    sjt_math1355 = (sjt_dot910)->m31;
    sjt_math1356 = x;
    (*_return)->m31 = sjt_math1355 * sjt_math1356;
    sjt_dot911 = _parent;
    sjt_math1357 = (sjt_dot911)->m32;
    sjt_math1358 = x;
    (*_return)->m32 = sjt_math1357 * sjt_math1358;
    sjt_dot912 = _parent;
    sjt_math1359 = (sjt_dot912)->m33;
    sjt_math1360 = x;
    (*_return)->m33 = sjt_math1359 * sjt_math1360;
    sjf_mat4_heap((*_return));
}

void sjf_mat4_multiplyvec4(sjs_mat4* _parent, sjs_vec4* v, sjs_vec4* _return) {
    sjs_mat4* sjt_dot205;
    sjs_vec4* sjt_dot206;
    sjs_mat4* sjt_dot207;
    sjs_vec4* sjt_dot208;
    sjs_mat4* sjt_dot209;
    sjs_vec4* sjt_dot210;
    sjs_mat4* sjt_dot211;
    sjs_vec4* sjt_dot212;
    sjs_mat4* sjt_dot213;
    sjs_vec4* sjt_dot214;
    sjs_mat4* sjt_dot215;
    sjs_vec4* sjt_dot216;
    sjs_mat4* sjt_dot217;
    sjs_vec4* sjt_dot218;
    sjs_mat4* sjt_dot219;
    sjs_vec4* sjt_dot220;
    sjs_mat4* sjt_dot221;
    sjs_vec4* sjt_dot222;
    sjs_mat4* sjt_dot223;
    sjs_vec4* sjt_dot224;
    sjs_mat4* sjt_dot225;
    sjs_vec4* sjt_dot226;
    sjs_mat4* sjt_dot227;
    sjs_vec4* sjt_dot228;
    sjs_mat4* sjt_dot229;
    sjs_vec4* sjt_dot230;
    sjs_mat4* sjt_dot231;
    sjs_vec4* sjt_dot232;
    sjs_mat4* sjt_dot233;
    sjs_vec4* sjt_dot234;
    sjs_mat4* sjt_dot235;
    sjs_vec4* sjt_dot236;
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
    sjt_dot205 = _parent;
    sjt_math191 = (sjt_dot205)->m00;
    sjt_dot206 = v;
    sjt_math192 = (sjt_dot206)->x;
    sjt_math189 = sjt_math191 * sjt_math192;
    sjt_dot207 = _parent;
    sjt_math193 = (sjt_dot207)->m10;
    sjt_dot208 = v;
    sjt_math194 = (sjt_dot208)->y;
    sjt_math190 = sjt_math193 * sjt_math194;
    sjt_math187 = sjt_math189 + sjt_math190;
    sjt_dot209 = _parent;
    sjt_math195 = (sjt_dot209)->m20;
    sjt_dot210 = v;
    sjt_math196 = (sjt_dot210)->z;
    sjt_math188 = sjt_math195 * sjt_math196;
    sjt_math185 = sjt_math187 + sjt_math188;
    sjt_dot211 = _parent;
    sjt_math197 = (sjt_dot211)->m30;
    sjt_dot212 = v;
    sjt_math198 = (sjt_dot212)->w;
    sjt_math186 = sjt_math197 * sjt_math198;
    _return->x = sjt_math185 + sjt_math186;
    sjt_dot213 = _parent;
    sjt_math205 = (sjt_dot213)->m01;
    sjt_dot214 = v;
    sjt_math206 = (sjt_dot214)->x;
    sjt_math203 = sjt_math205 * sjt_math206;
    sjt_dot215 = _parent;
    sjt_math207 = (sjt_dot215)->m11;
    sjt_dot216 = v;
    sjt_math208 = (sjt_dot216)->y;
    sjt_math204 = sjt_math207 * sjt_math208;
    sjt_math201 = sjt_math203 + sjt_math204;
    sjt_dot217 = _parent;
    sjt_math209 = (sjt_dot217)->m21;
    sjt_dot218 = v;
    sjt_math210 = (sjt_dot218)->z;
    sjt_math202 = sjt_math209 * sjt_math210;
    sjt_math199 = sjt_math201 + sjt_math202;
    sjt_dot219 = _parent;
    sjt_math211 = (sjt_dot219)->m31;
    sjt_dot220 = v;
    sjt_math212 = (sjt_dot220)->w;
    sjt_math200 = sjt_math211 * sjt_math212;
    _return->y = sjt_math199 + sjt_math200;
    sjt_dot221 = _parent;
    sjt_math219 = (sjt_dot221)->m02;
    sjt_dot222 = v;
    sjt_math220 = (sjt_dot222)->x;
    sjt_math217 = sjt_math219 * sjt_math220;
    sjt_dot223 = _parent;
    sjt_math221 = (sjt_dot223)->m12;
    sjt_dot224 = v;
    sjt_math222 = (sjt_dot224)->y;
    sjt_math218 = sjt_math221 * sjt_math222;
    sjt_math215 = sjt_math217 + sjt_math218;
    sjt_dot225 = _parent;
    sjt_math223 = (sjt_dot225)->m22;
    sjt_dot226 = v;
    sjt_math224 = (sjt_dot226)->z;
    sjt_math216 = sjt_math223 * sjt_math224;
    sjt_math213 = sjt_math215 + sjt_math216;
    sjt_dot227 = _parent;
    sjt_math225 = (sjt_dot227)->m32;
    sjt_dot228 = v;
    sjt_math226 = (sjt_dot228)->w;
    sjt_math214 = sjt_math225 * sjt_math226;
    _return->z = sjt_math213 + sjt_math214;
    sjt_dot229 = _parent;
    sjt_math233 = (sjt_dot229)->m03;
    sjt_dot230 = v;
    sjt_math234 = (sjt_dot230)->x;
    sjt_math231 = sjt_math233 * sjt_math234;
    sjt_dot231 = _parent;
    sjt_math235 = (sjt_dot231)->m13;
    sjt_dot232 = v;
    sjt_math236 = (sjt_dot232)->y;
    sjt_math232 = sjt_math235 * sjt_math236;
    sjt_math229 = sjt_math231 + sjt_math232;
    sjt_dot233 = _parent;
    sjt_math237 = (sjt_dot233)->m23;
    sjt_dot234 = v;
    sjt_math238 = (sjt_dot234)->z;
    sjt_math230 = sjt_math237 * sjt_math238;
    sjt_math227 = sjt_math229 + sjt_math230;
    sjt_dot235 = _parent;
    sjt_math239 = (sjt_dot235)->m33;
    sjt_dot236 = v;
    sjt_math240 = (sjt_dot236)->w;
    sjt_math228 = sjt_math239 * sjt_math240;
    _return->w = sjt_math227 + sjt_math228;
    sjf_vec4(_return);
}

void sjf_mat4_multiplyvec4_heap(sjs_mat4* _parent, sjs_vec4* v, sjs_vec4** _return) {
    sjs_mat4* sjt_dot237;
    sjs_vec4* sjt_dot238;
    sjs_mat4* sjt_dot239;
    sjs_vec4* sjt_dot240;
    sjs_mat4* sjt_dot241;
    sjs_vec4* sjt_dot242;
    sjs_mat4* sjt_dot243;
    sjs_vec4* sjt_dot244;
    sjs_mat4* sjt_dot245;
    sjs_vec4* sjt_dot246;
    sjs_mat4* sjt_dot247;
    sjs_vec4* sjt_dot248;
    sjs_mat4* sjt_dot249;
    sjs_vec4* sjt_dot250;
    sjs_mat4* sjt_dot251;
    sjs_vec4* sjt_dot252;
    sjs_mat4* sjt_dot253;
    sjs_vec4* sjt_dot254;
    sjs_mat4* sjt_dot255;
    sjs_vec4* sjt_dot256;
    sjs_mat4* sjt_dot257;
    sjs_vec4* sjt_dot258;
    sjs_mat4* sjt_dot259;
    sjs_vec4* sjt_dot260;
    sjs_mat4* sjt_dot261;
    sjs_vec4* sjt_dot262;
    sjs_mat4* sjt_dot263;
    sjs_vec4* sjt_dot264;
    sjs_mat4* sjt_dot265;
    sjs_vec4* sjt_dot266;
    sjs_mat4* sjt_dot267;
    sjs_vec4* sjt_dot268;
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
    sjt_dot237 = _parent;
    sjt_math247 = (sjt_dot237)->m00;
    sjt_dot238 = v;
    sjt_math248 = (sjt_dot238)->x;
    sjt_math245 = sjt_math247 * sjt_math248;
    sjt_dot239 = _parent;
    sjt_math249 = (sjt_dot239)->m10;
    sjt_dot240 = v;
    sjt_math250 = (sjt_dot240)->y;
    sjt_math246 = sjt_math249 * sjt_math250;
    sjt_math243 = sjt_math245 + sjt_math246;
    sjt_dot241 = _parent;
    sjt_math251 = (sjt_dot241)->m20;
    sjt_dot242 = v;
    sjt_math252 = (sjt_dot242)->z;
    sjt_math244 = sjt_math251 * sjt_math252;
    sjt_math241 = sjt_math243 + sjt_math244;
    sjt_dot243 = _parent;
    sjt_math253 = (sjt_dot243)->m30;
    sjt_dot244 = v;
    sjt_math254 = (sjt_dot244)->w;
    sjt_math242 = sjt_math253 * sjt_math254;
    (*_return)->x = sjt_math241 + sjt_math242;
    sjt_dot245 = _parent;
    sjt_math261 = (sjt_dot245)->m01;
    sjt_dot246 = v;
    sjt_math262 = (sjt_dot246)->x;
    sjt_math259 = sjt_math261 * sjt_math262;
    sjt_dot247 = _parent;
    sjt_math263 = (sjt_dot247)->m11;
    sjt_dot248 = v;
    sjt_math264 = (sjt_dot248)->y;
    sjt_math260 = sjt_math263 * sjt_math264;
    sjt_math257 = sjt_math259 + sjt_math260;
    sjt_dot249 = _parent;
    sjt_math265 = (sjt_dot249)->m21;
    sjt_dot250 = v;
    sjt_math266 = (sjt_dot250)->z;
    sjt_math258 = sjt_math265 * sjt_math266;
    sjt_math255 = sjt_math257 + sjt_math258;
    sjt_dot251 = _parent;
    sjt_math267 = (sjt_dot251)->m31;
    sjt_dot252 = v;
    sjt_math268 = (sjt_dot252)->w;
    sjt_math256 = sjt_math267 * sjt_math268;
    (*_return)->y = sjt_math255 + sjt_math256;
    sjt_dot253 = _parent;
    sjt_math275 = (sjt_dot253)->m02;
    sjt_dot254 = v;
    sjt_math276 = (sjt_dot254)->x;
    sjt_math273 = sjt_math275 * sjt_math276;
    sjt_dot255 = _parent;
    sjt_math277 = (sjt_dot255)->m12;
    sjt_dot256 = v;
    sjt_math278 = (sjt_dot256)->y;
    sjt_math274 = sjt_math277 * sjt_math278;
    sjt_math271 = sjt_math273 + sjt_math274;
    sjt_dot257 = _parent;
    sjt_math279 = (sjt_dot257)->m22;
    sjt_dot258 = v;
    sjt_math280 = (sjt_dot258)->z;
    sjt_math272 = sjt_math279 * sjt_math280;
    sjt_math269 = sjt_math271 + sjt_math272;
    sjt_dot259 = _parent;
    sjt_math281 = (sjt_dot259)->m32;
    sjt_dot260 = v;
    sjt_math282 = (sjt_dot260)->w;
    sjt_math270 = sjt_math281 * sjt_math282;
    (*_return)->z = sjt_math269 + sjt_math270;
    sjt_dot261 = _parent;
    sjt_math289 = (sjt_dot261)->m03;
    sjt_dot262 = v;
    sjt_math290 = (sjt_dot262)->x;
    sjt_math287 = sjt_math289 * sjt_math290;
    sjt_dot263 = _parent;
    sjt_math291 = (sjt_dot263)->m13;
    sjt_dot264 = v;
    sjt_math292 = (sjt_dot264)->y;
    sjt_math288 = sjt_math291 * sjt_math292;
    sjt_math285 = sjt_math287 + sjt_math288;
    sjt_dot265 = _parent;
    sjt_math293 = (sjt_dot265)->m23;
    sjt_dot266 = v;
    sjt_math294 = (sjt_dot266)->z;
    sjt_math286 = sjt_math293 * sjt_math294;
    sjt_math283 = sjt_math285 + sjt_math286;
    sjt_dot267 = _parent;
    sjt_math295 = (sjt_dot267)->m33;
    sjt_dot268 = v;
    sjt_math296 = (sjt_dot268)->w;
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
    float sjt_functionParam7;
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
    sjt_functionParam7 = sjt_math5 / sjt_math6;
    sjf_f32_tan(sjt_functionParam7, &sjt_math4);
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
    float sjt_functionParam8;
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
    sjt_functionParam8 = sjt_math25 / sjt_math26;
    sjf_f32_tan(sjt_functionParam8, &sjt_math24);
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
    sjs_mat4* sjt_dot561;
    sjs_mat4* sjt_dot562;
    sjs_mat4* sjt_dot563;
    sjs_mat4* sjt_dot564;
    sjs_mat4* sjt_dot565;
    sjs_mat4* sjt_dot566;
    sjs_mat4* sjt_dot567;
    sjs_mat4* sjt_dot568;
    sjs_mat4* sjt_dot569;
    sjs_mat4* sjt_dot570;
    sjs_mat4* sjt_dot571;
    sjs_mat4* sjt_dot572;
    sjs_mat4* sjt_dot573;
    sjs_mat4* sjt_dot574;
    sjs_mat4* sjt_dot575;
    sjs_mat4* sjt_dot576;

    _return->_refCount = 1;
    sjt_dot561 = _parent;
    _return->m00 = (sjt_dot561)->m00;
    sjt_dot562 = _parent;
    _return->m01 = (sjt_dot562)->m10;
    sjt_dot563 = _parent;
    _return->m02 = (sjt_dot563)->m20;
    sjt_dot564 = _parent;
    _return->m03 = (sjt_dot564)->m30;
    sjt_dot565 = _parent;
    _return->m10 = (sjt_dot565)->m01;
    sjt_dot566 = _parent;
    _return->m11 = (sjt_dot566)->m11;
    sjt_dot567 = _parent;
    _return->m12 = (sjt_dot567)->m21;
    sjt_dot568 = _parent;
    _return->m13 = (sjt_dot568)->m31;
    sjt_dot569 = _parent;
    _return->m20 = (sjt_dot569)->m02;
    sjt_dot570 = _parent;
    _return->m21 = (sjt_dot570)->m12;
    sjt_dot571 = _parent;
    _return->m22 = (sjt_dot571)->m22;
    sjt_dot572 = _parent;
    _return->m23 = (sjt_dot572)->m32;
    sjt_dot573 = _parent;
    _return->m30 = (sjt_dot573)->m03;
    sjt_dot574 = _parent;
    _return->m31 = (sjt_dot574)->m13;
    sjt_dot575 = _parent;
    _return->m32 = (sjt_dot575)->m23;
    sjt_dot576 = _parent;
    _return->m33 = (sjt_dot576)->m33;
    sjf_mat4(_return);
}

void sjf_mat4_transpose_heap(sjs_mat4* _parent, sjs_mat4** _return) {
    sjs_mat4* sjt_dot577;
    sjs_mat4* sjt_dot578;
    sjs_mat4* sjt_dot579;
    sjs_mat4* sjt_dot580;
    sjs_mat4* sjt_dot581;
    sjs_mat4* sjt_dot582;
    sjs_mat4* sjt_dot583;
    sjs_mat4* sjt_dot584;
    sjs_mat4* sjt_dot585;
    sjs_mat4* sjt_dot586;
    sjs_mat4* sjt_dot587;
    sjs_mat4* sjt_dot588;
    sjs_mat4* sjt_dot589;
    sjs_mat4* sjt_dot590;
    sjs_mat4* sjt_dot591;
    sjs_mat4* sjt_dot592;

    (*_return) = (sjs_mat4*)malloc(sizeof(sjs_mat4));
    (*_return)->_refCount = 1;
    sjt_dot577 = _parent;
    (*_return)->m00 = (sjt_dot577)->m00;
    sjt_dot578 = _parent;
    (*_return)->m01 = (sjt_dot578)->m10;
    sjt_dot579 = _parent;
    (*_return)->m02 = (sjt_dot579)->m20;
    sjt_dot580 = _parent;
    (*_return)->m03 = (sjt_dot580)->m30;
    sjt_dot581 = _parent;
    (*_return)->m10 = (sjt_dot581)->m01;
    sjt_dot582 = _parent;
    (*_return)->m11 = (sjt_dot582)->m11;
    sjt_dot583 = _parent;
    (*_return)->m12 = (sjt_dot583)->m21;
    sjt_dot584 = _parent;
    (*_return)->m13 = (sjt_dot584)->m31;
    sjt_dot585 = _parent;
    (*_return)->m20 = (sjt_dot585)->m02;
    sjt_dot586 = _parent;
    (*_return)->m21 = (sjt_dot586)->m12;
    sjt_dot587 = _parent;
    (*_return)->m22 = (sjt_dot587)->m22;
    sjt_dot588 = _parent;
    (*_return)->m23 = (sjt_dot588)->m32;
    sjt_dot589 = _parent;
    (*_return)->m30 = (sjt_dot589)->m03;
    sjt_dot590 = _parent;
    (*_return)->m31 = (sjt_dot590)->m13;
    sjt_dot591 = _parent;
    (*_return)->m32 = (sjt_dot591)->m23;
    sjt_dot592 = _parent;
    (*_return)->m33 = (sjt_dot592)->m33;
    sjf_mat4_heap((*_return));
}

void sjf_model(sjs_model* _this) {
}

sjs_object* sjf_model_asInterface(sjs_model* _this, int typeId) {
    switch (typeId) {
        case sji_model_typeId:  {
            return (sjs_object*)sjf_model_as_sji_model(_this);
        }
    }

    return 0;
}

sji_model* sjf_model_as_sji_model(sjs_model* _this) {
    sji_model* _interface;
    _interface = (sji_model*)malloc(sizeof(sji_model));
    _interface->_refCount = 1;
    _interface->_parent = (sjs_object*)_this;
    _interface->_parent->_refCount++;
    _interface->destroy = (void(*)(void*))sjf_model_destroy;
    _interface->asInterface = (sjs_object*(*)(sjs_object*,int))sjf_model_asInterface;
    _interface->update = (void(*)(void*,sjs_rect*,sjs_mat4*,sjs_mat4*,sjs_mat4*,sjs_light*))sjf_model_update;
    _interface->getz = (void(*)(void*, float*))sjf_model_getz;
    _interface->renderorqueue = (void(*)(void*,sjs_list_heap_model*))sjf_model_renderorqueue;
    _interface->render = (void(*)(void*))sjf_model_render;
    _interface->firemouseevent = (void(*)(void*,sjs_mouseevent*))sjf_model_firemouseevent;

    return _interface;
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
    sjs_vec3* sjt_dot542;
    sjs_model* sjt_dot543;

    sjt_dot543 = _parent;
    sjt_dot542 = &(sjt_dot543)->_projectedcenter;
    (*_return) = (sjt_dot542)->z;
}

void sjf_model_heap(sjs_model* _this) {
}

sjs_object* sjf_model_heap_asInterface(sjs_model* _this, int typeId) {
    switch (typeId) {
        case sji_model_typeId:  {
            return (sjs_object*)sjf_model_heap_as_sji_model(_this);
        }
    }

    return 0;
}

sji_model* sjf_model_heap_as_sji_model(sjs_model* _this) {
    sji_model* _interface;
    _interface = (sji_model*)malloc(sizeof(sji_model));
    _interface->_refCount = 1;
    _interface->_parent = (sjs_object*)_this;
    _interface->_parent->_refCount++;
    _interface->destroy = (void(*)(void*))sjf_model_destroy;
    _interface->asInterface = (sjs_object*(*)(sjs_object*,int))sjf_model_heap_asInterface;
    _interface->update = (void(*)(void*,sjs_rect*,sjs_mat4*,sjs_mat4*,sjs_mat4*,sjs_light*))sjf_model_update;
    _interface->getz = (void(*)(void*, float*))sjf_model_getz;
    _interface->renderorqueue = (void(*)(void*,sjs_list_heap_model*))sjf_model_renderorqueue;
    _interface->render = (void(*)(void*))sjf_model_render;
    _interface->firemouseevent = (void(*)(void*,sjs_mouseevent*))sjf_model_firemouseevent;

    return _interface;
}

void sjf_model_render(sjs_model* _parent) {
    sjs_mat4 sjt_call13 = { -1 };
    sjs_string sjt_call14 = { -1 };
    sjs_string sjt_call15 = { -1 };
    sjs_string sjt_call16 = { -1 };
    sjs_string sjt_call17 = { -1 };
    sjs_string sjt_call18 = { -1 };
    sjs_vec3 sjt_call19 = { -1 };
    sjs_string sjt_call20 = { -1 };
    sjs_vec3 sjt_call21 = { -1 };
    sjs_model* sjt_dot1297;
    sjs_model* sjt_dot1298;
    sjs_model* sjt_dot1299;
    sjs_model* sjt_dot1300;
    sjs_model* sjt_dot1301;
    sjs_model* sjt_dot1302;
    sjs_model* sjt_dot1303;
    sjs_light* sjt_dot1304;
    sjs_model* sjt_dot1305;
    sjs_model* sjt_dot1306;
    sjs_light* sjt_dot1313;
    sjs_model* sjt_dot1314;
    sjs_model* sjt_dot1315;
    sjs_light* sjt_dot1316;
    sjs_model* sjt_dot1317;
    sjs_model* sjt_dot1318;
    sjs_model* sjt_dot558;
    sjs_model* sjt_dot559;
    sjs_model* sjt_dot560;
    sjs_mat4* sjt_functionParam114;
    sjs_mat4* sjt_functionParam115;
    sjs_shader* sjt_functionParam118;
    int32_t sjt_functionParam119;
    sjs_texture* sjt_functionParam120;
    int32_t sjt_functionParam121;
    sjs_shader* sjt_functionParam122;
    sjs_string* sjt_functionParam123;
    sjs_mat4* sjt_functionParam124;
    int32_t sjt_functionParam125;
    sjs_shader* sjt_functionParam126;
    sjs_string* sjt_functionParam127;
    sjs_mat4* sjt_functionParam128;
    int32_t sjt_functionParam129;
    sjs_shader* sjt_functionParam130;
    sjs_string* sjt_functionParam131;
    sjs_mat4* sjt_functionParam132;
    int32_t sjt_functionParam133;
    sjs_shader* sjt_functionParam134;
    sjs_string* sjt_functionParam135;
    sjs_vec3* sjt_functionParam136;
    int32_t sjt_functionParam137;
    sjs_shader* sjt_functionParam138;
    sjs_string* sjt_functionParam139;
    sjs_vec3* sjt_functionParam140;
    int32_t sjt_functionParam141;
    sjs_shader* sjt_functionParam142;
    sjs_string* sjt_functionParam143;
    sjs_vec3* sjt_functionParam144;
    sjs_mat4* sjt_parent48;
    sjs_mat4* sjt_parent49;
    sjs_mat4* sjt_parent50;
    sjs_mat4* sjt_parent53;
    sjs_color* sjt_parent54;
    sjs_color* sjt_parent55;
    sjs_vertexbuffer_vertex_location_texture_normal* sjt_parent56;
    sjs_mat4 sjv_normalmat = { -1 };
    sjs_mat4 sjv_viewworld = { -1 };
    sjs_mat4 sjv_world = { -1 };

    sjt_dot558 = _parent;
    sjt_parent48 = &(sjt_dot558)->_world;
    sjt_dot559 = _parent;
    sjt_functionParam114 = &(sjt_dot559)->model;
    sjf_mat4_multiply(sjt_parent48, sjt_functionParam114, &sjv_world);
    sjt_dot560 = _parent;
    sjt_parent49 = &(sjt_dot560)->_view;
    sjt_functionParam115 = &sjv_world;
    sjf_mat4_multiply(sjt_parent49, sjt_functionParam115, &sjv_viewworld);
    sjt_parent53 = &sjv_viewworld;
    sjf_mat4_invert(sjt_parent53, &sjt_call13);
    sjt_parent50 = &sjt_call13;
    sjf_mat4_transpose(sjt_parent50, &sjv_normalmat);
    sjt_dot1297 = _parent;
    sjt_functionParam118 = &(sjt_dot1297)->shader;
    sjf_gluseprogram(sjt_functionParam118);
    sjt_functionParam119 = sjv_gltexture_gl_texture_2d;
    sjt_dot1298 = _parent;
    sjt_functionParam120 = &(sjt_dot1298)->texture;
    sjf_glbindtexture(sjt_functionParam119, sjt_functionParam120);
    sjt_dot1299 = _parent;
    sjt_functionParam122 = &(sjt_dot1299)->shader;
    sjt_call14._refCount = 1;
    sjt_call14.count = 9;
    sjt_call14.data._refCount = 1;
    sjt_call14.data.datasize = 10;
    sjt_call14.data.data = (void*)sjg_string101;
    sjt_call14.data._isglobal = true;
    sjt_call14.data.count = 10;
    sjf_array_char(&sjt_call14.data);
    sjf_string(&sjt_call14);
    sjt_functionParam123 = &sjt_call14;
    sjf_glgetuniformlocation(sjt_functionParam122, sjt_functionParam123, &sjt_functionParam121);
    sjt_functionParam124 = &sjv_viewworld;
    sjf_gluniformmat4(sjt_functionParam121, sjt_functionParam124);
    sjt_dot1300 = _parent;
    sjt_functionParam126 = &(sjt_dot1300)->shader;
    sjt_call15._refCount = 1;
    sjt_call15.count = 9;
    sjt_call15.data._refCount = 1;
    sjt_call15.data.datasize = 10;
    sjt_call15.data.data = (void*)sjg_string102;
    sjt_call15.data._isglobal = true;
    sjt_call15.data.count = 10;
    sjf_array_char(&sjt_call15.data);
    sjf_string(&sjt_call15);
    sjt_functionParam127 = &sjt_call15;
    sjf_glgetuniformlocation(sjt_functionParam126, sjt_functionParam127, &sjt_functionParam125);
    sjt_functionParam128 = &sjv_normalmat;
    sjf_gluniformmat4(sjt_functionParam125, sjt_functionParam128);
    sjt_dot1301 = _parent;
    sjt_functionParam130 = &(sjt_dot1301)->shader;
    sjt_call16._refCount = 1;
    sjt_call16.count = 10;
    sjt_call16.data._refCount = 1;
    sjt_call16.data.datasize = 11;
    sjt_call16.data.data = (void*)sjg_string103;
    sjt_call16.data._isglobal = true;
    sjt_call16.data.count = 11;
    sjf_array_char(&sjt_call16.data);
    sjf_string(&sjt_call16);
    sjt_functionParam131 = &sjt_call16;
    sjf_glgetuniformlocation(sjt_functionParam130, sjt_functionParam131, &sjt_functionParam129);
    sjt_dot1302 = _parent;
    sjt_functionParam132 = &(sjt_dot1302)->_projection;
    sjf_gluniformmat4(sjt_functionParam129, sjt_functionParam132);
    sjt_dot1303 = _parent;
    sjt_functionParam134 = &(sjt_dot1303)->shader;
    sjt_call17._refCount = 1;
    sjt_call17.count = 8;
    sjt_call17.data._refCount = 1;
    sjt_call17.data.datasize = 9;
    sjt_call17.data.data = (void*)sjg_string104;
    sjt_call17.data._isglobal = true;
    sjt_call17.data.count = 9;
    sjf_array_char(&sjt_call17.data);
    sjf_string(&sjt_call17);
    sjt_functionParam135 = &sjt_call17;
    sjf_glgetuniformlocation(sjt_functionParam134, sjt_functionParam135, &sjt_functionParam133);
    sjt_dot1305 = _parent;
    sjt_dot1304 = &(sjt_dot1305)->_light;
    sjt_functionParam136 = &(sjt_dot1304)->pos;
    sjf_gluniformvec3(sjt_functionParam133, sjt_functionParam136);
    sjt_dot1306 = _parent;
    sjt_functionParam138 = &(sjt_dot1306)->shader;
    sjt_call18._refCount = 1;
    sjt_call18.count = 12;
    sjt_call18.data._refCount = 1;
    sjt_call18.data.datasize = 13;
    sjt_call18.data.data = (void*)sjg_string105;
    sjt_call18.data._isglobal = true;
    sjt_call18.data.count = 13;
    sjf_array_char(&sjt_call18.data);
    sjf_string(&sjt_call18);
    sjt_functionParam139 = &sjt_call18;
    sjf_glgetuniformlocation(sjt_functionParam138, sjt_functionParam139, &sjt_functionParam137);
    sjt_dot1314 = _parent;
    sjt_dot1313 = &(sjt_dot1314)->_light;
    sjt_parent54 = &(sjt_dot1313)->diffusecolor;
    sjf_color_asvec3(sjt_parent54, &sjt_call19);
    sjt_functionParam140 = &sjt_call19;
    sjf_gluniformvec3(sjt_functionParam137, sjt_functionParam140);
    sjt_dot1315 = _parent;
    sjt_functionParam142 = &(sjt_dot1315)->shader;
    sjt_call20._refCount = 1;
    sjt_call20.count = 9;
    sjt_call20.data._refCount = 1;
    sjt_call20.data.datasize = 10;
    sjt_call20.data.data = (void*)sjg_string106;
    sjt_call20.data._isglobal = true;
    sjt_call20.data.count = 10;
    sjf_array_char(&sjt_call20.data);
    sjf_string(&sjt_call20);
    sjt_functionParam143 = &sjt_call20;
    sjf_glgetuniformlocation(sjt_functionParam142, sjt_functionParam143, &sjt_functionParam141);
    sjt_dot1317 = _parent;
    sjt_dot1316 = &(sjt_dot1317)->_light;
    sjt_parent55 = &(sjt_dot1316)->speccolor;
    sjf_color_asvec3(sjt_parent55, &sjt_call21);
    sjt_functionParam144 = &sjt_call21;
    sjf_gluniformvec3(sjt_functionParam141, sjt_functionParam144);
    sjt_dot1318 = _parent;
    sjt_parent56 = &(sjt_dot1318)->vertexbuffer;
    sjf_vertexbuffer_vertex_location_texture_normal_render(sjt_parent56);

    if (sjt_call13._refCount == 1) { sjf_mat4_destroy(&sjt_call13); }
    if (sjt_call14._refCount == 1) { sjf_string_destroy(&sjt_call14); }
    if (sjt_call15._refCount == 1) { sjf_string_destroy(&sjt_call15); }
    if (sjt_call16._refCount == 1) { sjf_string_destroy(&sjt_call16); }
    if (sjt_call17._refCount == 1) { sjf_string_destroy(&sjt_call17); }
    if (sjt_call18._refCount == 1) { sjf_string_destroy(&sjt_call18); }
    if (sjt_call19._refCount == 1) { sjf_vec3_destroy(&sjt_call19); }
    if (sjt_call20._refCount == 1) { sjf_string_destroy(&sjt_call20); }
    if (sjt_call21._refCount == 1) { sjf_vec3_destroy(&sjt_call21); }
    if (sjv_normalmat._refCount == 1) { sjf_mat4_destroy(&sjv_normalmat); }
    if (sjv_viewworld._refCount == 1) { sjf_mat4_destroy(&sjv_viewworld); }
    if (sjv_world._refCount == 1) { sjf_mat4_destroy(&sjv_world); }
}

void sjf_model_renderorqueue(sjs_model* _parent, sjs_list_heap_model* zqueue) {
    sjs_model* sjt_dot544;
    bool sjt_ifElse12;

    sjt_dot544 = _parent;
    sjt_ifElse12 = (sjt_dot544)->hasalpha;
    if (sjt_ifElse12) {
        sjs_model* sjt_cast12 = 0;
        sji_model* sjt_functionParam113 = 0;
        sjs_list_heap_model* sjt_parent47;

        sjt_parent47 = zqueue;
        sjt_cast12 = _parent;
        sjt_cast12->_refCount++;
        sjt_functionParam113 = (sji_model*)sjf_model_heap_as_sji_model(sjt_cast12);
        sjf_list_heap_model_add(sjt_parent47, sjt_functionParam113);

        sjt_cast12->_refCount--;
        if (sjt_cast12->_refCount <= 0) {
            sjf_model_destroy(sjt_cast12);
        }
        sjt_functionParam113->_refCount--;
        if (sjt_functionParam113->_refCount <= 0) {
            sji_model_destroy(sjt_functionParam113);
        }
    } else {
        sjf_model_render(_parent);
    }
}

void sjf_model_update(sjs_model* _parent, sjs_rect* scenerect, sjs_mat4* projection, sjs_mat4* view, sjs_mat4* world, sjs_light* light) {
    sjs_mat4 sjt_call10 = { -1 };
    sjs_mat4 sjt_call11 = { -1 };
    sjs_vec4 sjt_call12 = { -1 };
    sjs_mat4* sjt_copy5;
    sjs_mat4* sjt_copy6;
    sjs_mat4* sjt_copy7;
    sjs_light* sjt_copy8;
    sjs_model* sjt_dot202;
    sjs_model* sjt_dot203;
    sjs_model* sjt_dot204;
    sjs_model* sjt_dot525;
    sjs_model* sjt_dot526;
    sjs_model* sjt_dot527;
    sjs_vec3* sjt_dot528;
    sjs_model* sjt_dot529;
    sjs_vec3* sjt_dot530;
    sjs_model* sjt_dot531;
    sjs_vec3* sjt_dot532;
    sjs_model* sjt_dot533;
    sjs_model* sjt_dot534;
    sjs_vec4* sjt_dot535;
    sjs_vec4* sjt_dot536;
    sjs_vec4* sjt_dot537;
    sjs_vec4* sjt_dot538;
    sjs_vec4* sjt_dot539;
    sjs_vec4* sjt_dot540;
    sjs_model* sjt_dot541;
    sjs_mat4* sjt_functionParam105;
    sjs_mat4* sjt_functionParam106;
    sjs_vec4* sjt_functionParam107;
    float sjt_math745;
    float sjt_math746;
    float sjt_math747;
    float sjt_math748;
    float sjt_math749;
    float sjt_math750;
    sjs_mat4* sjt_parent42;
    sjs_mat4* sjt_parent43;
    sjs_mat4* sjt_parent44;
    sjs_vec4 sjv_t2 = { -1 };

    sjt_dot202 = _parent;
    sjt_copy5 = projection;
    sjf_mat4_copy(&sjt_dot202->_projection, sjt_copy5);
    sjt_dot203 = _parent;
    sjt_copy6 = view;
    sjf_mat4_copy(&sjt_dot203->_view, sjt_copy6);
    sjt_dot204 = _parent;
    sjt_copy7 = world;
    sjf_mat4_copy(&sjt_dot204->_world, sjt_copy7);
    sjt_dot525 = _parent;
    sjt_parent44 = &(sjt_dot525)->_view;
    sjt_dot526 = _parent;
    sjt_functionParam105 = &(sjt_dot526)->_world;
    sjf_mat4_multiply(sjt_parent44, sjt_functionParam105, &sjt_call11);
    sjt_parent43 = &sjt_call11;
    sjt_dot527 = _parent;
    sjt_functionParam106 = &(sjt_dot527)->model;
    sjf_mat4_multiply(sjt_parent43, sjt_functionParam106, &sjt_call10);
    sjt_parent42 = &sjt_call10;
    sjt_call12._refCount = 1;
    sjt_dot529 = _parent;
    sjt_dot528 = &(sjt_dot529)->center;
    sjt_call12.x = (sjt_dot528)->x;
    sjt_dot531 = _parent;
    sjt_dot530 = &(sjt_dot531)->center;
    sjt_call12.y = (sjt_dot530)->y;
    sjt_dot533 = _parent;
    sjt_dot532 = &(sjt_dot533)->center;
    sjt_call12.z = (sjt_dot532)->z;
    sjt_call12.w = 1.0f;
    sjf_vec4(&sjt_call12);
    sjt_functionParam107 = &sjt_call12;
    sjf_mat4_multiplyvec4(sjt_parent42, sjt_functionParam107, &sjv_t2);
    sjt_dot534 = _parent;
    sjt_dot534->_projectedcenter._refCount = 1;
    sjt_dot535 = &sjv_t2;
    sjt_math745 = (sjt_dot535)->x;
    sjt_dot536 = &sjv_t2;
    sjt_math746 = (sjt_dot536)->w;
    sjt_dot534->_projectedcenter.x = sjt_math745 / sjt_math746;
    sjt_dot537 = &sjv_t2;
    sjt_math747 = (sjt_dot537)->y;
    sjt_dot538 = &sjv_t2;
    sjt_math748 = (sjt_dot538)->w;
    sjt_dot534->_projectedcenter.y = sjt_math747 / sjt_math748;
    sjt_dot539 = &sjv_t2;
    sjt_math749 = (sjt_dot539)->z;
    sjt_dot540 = &sjv_t2;
    sjt_math750 = (sjt_dot540)->w;
    sjt_dot534->_projectedcenter.z = sjt_math749 / sjt_math750;
    sjf_vec3(&sjt_dot534->_projectedcenter);
    sjt_dot541 = _parent;
    sjt_copy8 = light;
    sjf_light_copy(&sjt_dot541->_light, sjt_copy8);

    if (sjt_call10._refCount == 1) { sjf_mat4_destroy(&sjt_call10); }
    if (sjt_call11._refCount == 1) { sjf_mat4_destroy(&sjt_call11); }
    if (sjt_call12._refCount == 1) { sjf_vec4_destroy(&sjt_call12); }
    if (sjv_t2._refCount == 1) { sjf_vec4_destroy(&sjv_t2); }
}

void sjf_model_zsort(sji_model* l, sji_model* r, int32_t* _return) {
    float sjt_functionParam46;
    float sjt_functionParam47;
    sji_model* sjt_parent15;
    sji_model* sjt_parent16;

    sjt_parent15 = l;
    sjt_parent15->getz(sjt_parent15->_parent, &sjt_functionParam46);
    sjt_parent16 = r;
    sjt_parent16->getz(sjt_parent16->_parent, &sjt_functionParam47);
    sjf_f32_compare(sjt_functionParam46, sjt_functionParam47, _return);
}

void sjf_model_zsort_callback(void * _parent, sji_model* l, sji_model* r, int32_t* _return) {
    sjf_model_zsort(l, r, _return);
}

void sjf_mouse_capture(sji_element* element) {
    sji_element* sjt_value1 = 0;

    sjt_value1 = element;
    sjt_value1->_refCount++;
    if (sjv_mouse_captureelement != 0) {
        sjv_mouse_captureelement->_refCount--;
        if (sjv_mouse_captureelement->_refCount <= 0) {
            sji_element_destroy(sjv_mouse_captureelement);
        }
    }

    sjv_mouse_captureelement = sjt_value1;
    if (sjv_mouse_captureelement != 0) {
        sjv_mouse_captureelement->_refCount++;
    }

    SDL_CaptureMouse(true);

    sjt_value1->_refCount--;
    if (sjt_value1->_refCount <= 0) {
        sji_element_destroy(sjt_value1);
    }
}

void sjf_mouse_release(sji_element* element) {
    sjs_string sjt_call8 = { -1 };
    sjs_string* sjt_functionParam99;
    bool sjt_isEmpty1;
    sji_element* sjt_isEmpty2;

    sjt_call8._refCount = 1;
    sjt_call8.count = 7;
    sjt_call8.data._refCount = 1;
    sjt_call8.data.datasize = 8;
    sjt_call8.data.data = (void*)sjg_string97;
    sjt_call8.data._isglobal = true;
    sjt_call8.data.count = 8;
    sjf_array_char(&sjt_call8.data);
    sjf_string(&sjt_call8);
    sjt_functionParam99 = &sjt_call8;
    sjf_console_writeline(sjt_functionParam99);
    sjt_isEmpty2 = sjv_mouse_captureelement;
    sjt_isEmpty1 = (sjt_isEmpty2 == 0);
    if (!sjt_isEmpty1) {
        sji_element* ifValue5 = 0;
        sjs_string sjt_call9 = { -1 };
        sjs_string* sjt_functionParam100;

        ifValue5 = sjv_mouse_captureelement;
        if (ifValue5 != 0) {
            ifValue5->_refCount++;
        }

        sjt_call9._refCount = 1;
        sjt_call9.count = 12;
        sjt_call9.data._refCount = 1;
        sjt_call9.data.datasize = 13;
        sjt_call9.data.data = (void*)sjg_string98;
        sjt_call9.data._isglobal = true;
        sjt_call9.data.count = 13;
        sjf_array_char(&sjt_call9.data);
        sjf_string(&sjt_call9);
        sjt_functionParam100 = &sjt_call9;
        sjf_console_writeline(sjt_functionParam100);
        if (sjv_mouse_captureelement != 0) {
            sjv_mouse_captureelement->_refCount--;
            if (sjv_mouse_captureelement->_refCount <= 0) {
                sji_element_destroy(sjv_mouse_captureelement);
            }
        }

        sjv_mouse_captureelement = 0;
        if (sjv_mouse_captureelement != 0) {
            sjv_mouse_captureelement->_refCount++;
        }

        SDL_CaptureMouse(false);

        ifValue5->_refCount--;
        if (ifValue5->_refCount <= 0) {
            sji_element_destroy(ifValue5);
        }
        if (sjt_call9._refCount == 1) { sjf_string_destroy(&sjt_call9); }
    }

    if (sjt_call8._refCount == 1) { sjf_string_destroy(&sjt_call8); }
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

sjs_object* sjf_nauscene3delement_asInterface(sjs_nauscene3delement* _this, int typeId) {
    switch (typeId) {
        case sji_element_typeId:  {
            return (sjs_object*)sjf_nauscene3delement_as_sji_element(_this);
        }
    }

    return 0;
}

sji_element* sjf_nauscene3delement_as_sji_element(sjs_nauscene3delement* _this) {
    sji_element* _interface;
    _interface = (sji_element*)malloc(sizeof(sji_element));
    _interface->_refCount = 1;
    _interface->_parent = (sjs_object*)_this;
    _interface->_parent->_refCount++;
    _interface->destroy = (void(*)(void*))sjf_nauscene3delement_destroy;
    _interface->asInterface = (sjs_object*(*)(sjs_object*,int))sjf_nauscene3delement_asInterface;
    _interface->getsize = (void(*)(void*,sjs_size*, sjs_size*))sjf_nauscene3delement_getsize;
    _interface->getsize_heap = (void(*)(void*,sjs_size*, sjs_size**))sjf_nauscene3delement_getsize_heap;
    _interface->getrect = (void(*)(void*, sjs_rect**))sjf_nauscene3delement_getrect;
    _interface->setrect = (void(*)(void*,sjs_rect*))sjf_nauscene3delement_setrect;
    _interface->render = (void(*)(void*,sjs_scene2d*))sjf_nauscene3delement_render;
    _interface->firemouseevent = (void(*)(void*,sjs_mouseevent*))sjf_nauscene3delement_firemouseevent;

    return _interface;
}

void sjf_nauscene3delement_copy(sjs_nauscene3delement* _this, sjs_nauscene3delement* _from) {
    _this->children._refCount = 1;
    sjf_array_heap_model_copy(&_this->children, &_from->children);
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
    sjs_mouseevent* sjt_dot198;
    sjs_mouseevent* sjt_dot57;
    bool sjt_ifElse11;
    bool sjt_not2;
    bool sjt_switch1;
    int32_t underscore1;

    sjt_dot57 = mouseevent;
    underscore1 = (sjt_dot57)->type;
    sjt_compare33 = underscore1;
    sjt_compare34 = sjv_mouseeventtype_down;
    sjt_switch1 = sjt_compare33 == sjt_compare34;
    if (sjt_switch1) {
        sjs_nauscene3delement* sjt_cast5 = 0;
        sjs_point* sjt_copy3;
        sjs_vec3* sjt_copy4;
        sjs_nauscene3delement* sjt_dot58;
        sjs_nauscene3delement* sjt_dot59;
        sjs_mouseevent* sjt_dot60;
        sjs_nauscene3delement* sjt_dot61;
        sjs_nauscene3delement* sjt_dot62;
        sji_element* sjt_functionParam51 = 0;

        sjt_dot58 = _parent;
        sjt_dot58->_isdragging = true;
        sjt_dot59 = _parent;
        sjt_dot60 = mouseevent;
        sjt_copy3 = &(sjt_dot60)->point;
        sjf_point_copy(&sjt_dot59->_startdrag, sjt_copy3);
        sjt_dot61 = _parent;
        sjt_dot62 = _parent;
        sjt_copy4 = &(sjt_dot62)->_lookat;
        sjf_vec3_copy(&sjt_dot61->_lookatdrag, sjt_copy4);
        sjt_cast5 = _parent;
        sjt_cast5->_refCount++;
        sjt_functionParam51 = (sji_element*)sjf_nauscene3delement_heap_as_sji_element(sjt_cast5);
        sjf_mouse_capture(sjt_functionParam51);

        sjt_cast5->_refCount--;
        if (sjt_cast5->_refCount <= 0) {
            sjf_nauscene3delement_destroy(sjt_cast5);
        }
        sjt_functionParam51->_refCount--;
        if (sjt_functionParam51->_refCount <= 0) {
            sji_element_destroy(sjt_functionParam51);
        }
    } else {
        int32_t sjt_compare35;
        int32_t sjt_compare36;
        bool sjt_switch2;

        sjt_compare35 = underscore1;
        sjt_compare36 = sjv_mouseeventtype_move;
        sjt_switch2 = sjt_compare35 == sjt_compare36;
        if (sjt_switch2) {
            sjs_vec3 sjt_call1 = { -1 };
            sjs_vec3 sjt_call2 = { -1 };
            sjs_vec3 sjt_call3 = { -1 };
            sjs_vec3 sjt_call4 = { -1 };
            sjs_vec3 sjt_call7 = { -1 };
            sjs_nauscene3delement* sjt_dot63;
            bool sjt_ifElse8;
            sjs_vec3 sjv_camera = { -1 };

            sjt_dot63 = _parent;
            sjt_ifElse8 = (sjt_dot63)->_isdragging;
            if (sjt_ifElse8) {
                int32_t sjt_cast6;
                int32_t sjt_cast7;
                int32_t sjt_cast8;
                int32_t sjt_cast9;
                sjs_nauscene3delement* sjt_dot103;
                sjs_point* sjt_dot104;
                sjs_nauscene3delement* sjt_dot105;
                sjs_point* sjt_dot106;
                sjs_mouseevent* sjt_dot107;
                sjs_rect* sjt_dot108;
                sjs_nauscene3delement* sjt_dot109;
                sjs_point* sjt_dot110;
                sjs_mouseevent* sjt_dot111;
                sjs_point* sjt_dot112;
                sjs_nauscene3delement* sjt_dot113;
                sjs_rect* sjt_dot114;
                sjs_nauscene3delement* sjt_dot115;
                sjs_nauscene3delement* sjt_dot128;
                sjs_nauscene3delement* sjt_dot129;
                sjs_nauscene3delement* sjt_dot196;
                sjs_nauscene3delement* sjt_dot64;
                sjs_nauscene3delement* sjt_dot77;
                sjs_nauscene3delement* sjt_dot90;
                sjs_vec3* sjt_functionParam64;
                sjs_vec3* sjt_functionParam65;
                sjs_vec3* sjt_functionParam78;
                sjs_vec3* sjt_functionParam79;
                sjs_vec3* sjt_functionParam80;
                sjs_vec3* sjt_functionParam81;
                sjs_vec3* sjt_functionParam96;
                sjs_vec3* sjt_functionParam97;
                sjs_vec3* sjt_functionParam98;
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
                sjs_vec3* sjt_parent21;
                sjs_vec3* sjt_parent22;

                sjt_dot64 = _parent;
                sjt_dot77 = _parent;
                sjt_functionParam64 = &(sjt_dot77)->lookatmax;
                sjt_dot90 = _parent;
                sjt_functionParam78 = &(sjt_dot90)->lookatmin;
                sjt_dot103 = _parent;
                sjt_parent21 = &(sjt_dot103)->_lookatdrag;
                sjt_call3._refCount = 1;
                sjt_dot105 = _parent;
                sjt_dot104 = &(sjt_dot105)->_startdrag;
                sjt_math75 = (sjt_dot104)->x;
                sjt_dot107 = mouseevent;
                sjt_dot106 = &(sjt_dot107)->point;
                sjt_math76 = (sjt_dot106)->x;
                sjt_cast6 = sjt_math75 - sjt_math76;
                sjt_math73 = (float)sjt_cast6;
                sjt_dot109 = _parent;
                sjt_dot108 = &(sjt_dot109)->_rect;
                sjt_cast7 = (sjt_dot108)->w;
                sjt_math74 = (float)sjt_cast7;
                sjt_math71 = sjt_math73 / sjt_math74;
                sjt_math72 = 2.0f;
                sjt_call3.x = sjt_math71 * sjt_math72;
                sjt_dot111 = mouseevent;
                sjt_dot110 = &(sjt_dot111)->point;
                sjt_math81 = (sjt_dot110)->y;
                sjt_dot113 = _parent;
                sjt_dot112 = &(sjt_dot113)->_startdrag;
                sjt_math82 = (sjt_dot112)->y;
                sjt_cast8 = sjt_math81 - sjt_math82;
                sjt_math79 = (float)sjt_cast8;
                sjt_dot115 = _parent;
                sjt_dot114 = &(sjt_dot115)->_rect;
                sjt_cast9 = (sjt_dot114)->h;
                sjt_math80 = (float)sjt_cast9;
                sjt_math77 = sjt_math79 / sjt_math80;
                sjt_math78 = 2.0f;
                sjt_call3.y = sjt_math77 * sjt_math78;
                sjt_call3.z = 0.0f;
                sjf_vec3(&sjt_call3);
                sjt_functionParam80 = &sjt_call3;
                sjf_vec3_add(sjt_parent21, sjt_functionParam80, &sjt_call2);
                sjt_functionParam79 = &sjt_call2;
                sjf_vec3_max(sjt_functionParam78, sjt_functionParam79, &sjt_call1);
                sjt_functionParam65 = &sjt_call1;
                sjf_vec3_min(sjt_functionParam64, sjt_functionParam65, &sjt_dot64->_lookat);
                sjt_dot128 = _parent;
                sjt_parent22 = &(sjt_dot128)->_lookat;
                sjt_call4._refCount = 1;
                sjt_call4.x = 0.0f;
                sjt_call4.y = 0.0f;
                sjt_call4.z = 5.0f;
                sjf_vec3(&sjt_call4);
                sjt_functionParam81 = &sjt_call4;
                sjf_vec3_subtract(sjt_parent22, sjt_functionParam81, &sjv_camera);
                sjt_dot129 = _parent;
                sjt_functionParam96 = &sjv_camera;
                sjt_dot196 = _parent;
                sjt_functionParam97 = &(sjt_dot196)->_lookat;
                sjt_call7._refCount = 1;
                sjt_call7.x = 0.0f;
                sjt_call7.y = 1.0f;
                sjt_call7.z = 0.0f;
                sjf_vec3(&sjt_call7);
                sjt_functionParam98 = &sjt_call7;
                sjf_mat4_lookatlh(sjt_functionParam96, sjt_functionParam97, sjt_functionParam98, &sjt_dot129->view);
            }

            if (sjt_call1._refCount == 1) { sjf_vec3_destroy(&sjt_call1); }
            if (sjt_call2._refCount == 1) { sjf_vec3_destroy(&sjt_call2); }
            if (sjt_call3._refCount == 1) { sjf_vec3_destroy(&sjt_call3); }
            if (sjt_call4._refCount == 1) { sjf_vec3_destroy(&sjt_call4); }
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
                sjs_nauscene3delement* sjt_dot197;
                sji_element* sjt_functionParam101 = 0;

                sjt_dot197 = _parent;
                sjt_dot197->_isdragging = false;
                sjt_cast10 = _parent;
                sjt_cast10->_refCount++;
                sjt_functionParam101 = (sji_element*)sjf_nauscene3delement_heap_as_sji_element(sjt_cast10);
                sjf_mouse_release(sjt_functionParam101);

                sjt_cast10->_refCount--;
                if (sjt_cast10->_refCount <= 0) {
                    sjf_nauscene3delement_destroy(sjt_cast10);
                }
                sjt_functionParam101->_refCount--;
                if (sjt_functionParam101->_refCount <= 0) {
                    sji_element_destroy(sjt_functionParam101);
                }
            }
        }
    }

    sjt_dot198 = mouseevent;
    sjt_not2 = (sjt_dot198)->iscaptured;
    result4 = !sjt_not2;
    sjt_ifElse11 = result4;
    if (sjt_ifElse11) {
        int32_t i;
        sjs_array_heap_model* sjt_dot199;
        sjs_nauscene3delement* sjt_dot200;
        int32_t sjt_forEnd7;
        int32_t sjt_forStart7;

        sjt_forStart7 = 0;
        sjt_dot200 = _parent;
        sjt_dot199 = &(sjt_dot200)->children;
        sjt_forEnd7 = (sjt_dot199)->count;
        i = sjt_forStart7;
        while (i < sjt_forEnd7) {
            sjs_nauscene3delement* sjt_dot201;
            int32_t sjt_functionParam102;
            sjs_mouseevent* sjt_interfaceParam10;
            sjs_array_heap_model* sjt_parent39;
            sji_model* sjt_parent40;
            sji_model* sjv_child = 0;

            sjt_dot201 = _parent;
            sjt_parent39 = &(sjt_dot201)->children;
            sjt_functionParam102 = i;
            sjf_array_heap_model_getat_heap(sjt_parent39, sjt_functionParam102, &sjv_child);
            sjt_parent40 = sjv_child;
            sjt_interfaceParam10 = mouseevent;
            sjt_parent40->firemouseevent(sjt_parent40->_parent, sjt_interfaceParam10);
            i++;

            sjv_child->_refCount--;
            if (sjv_child->_refCount <= 0) {
                sji_model_destroy(sjv_child);
            }
        }
    }
}

void sjf_nauscene3delement_getrect(sjs_nauscene3delement* _parent, sjs_rect** _return) {
    sjs_nauscene3delement* sjt_dot21;

    sjt_dot21 = _parent;
    (*_return) = &(sjt_dot21)->_rect;
}

void sjf_nauscene3delement_getsize(sjs_nauscene3delement* _parent, sjs_size* maxsize, sjs_size* _return) {
    sjs_size* sjt_dot17;
    sjs_size* sjt_dot18;

    _return->_refCount = 1;
    sjt_dot17 = maxsize;
    _return->w = (sjt_dot17)->w;
    sjt_dot18 = maxsize;
    _return->h = (sjt_dot18)->h;
    sjf_size(_return);
}

void sjf_nauscene3delement_getsize_heap(sjs_nauscene3delement* _parent, sjs_size* maxsize, sjs_size** _return) {
    sjs_size* sjt_dot19;
    sjs_size* sjt_dot20;

    (*_return) = (sjs_size*)malloc(sizeof(sjs_size));
    (*_return)->_refCount = 1;
    sjt_dot19 = maxsize;
    (*_return)->w = (sjt_dot19)->w;
    sjt_dot20 = maxsize;
    (*_return)->h = (sjt_dot20)->h;
    sjf_size_heap((*_return));
}

void sjf_nauscene3delement_heap(sjs_nauscene3delement* _this) {
}

sjs_object* sjf_nauscene3delement_heap_asInterface(sjs_nauscene3delement* _this, int typeId) {
    switch (typeId) {
        case sji_element_typeId:  {
            return (sjs_object*)sjf_nauscene3delement_heap_as_sji_element(_this);
        }
    }

    return 0;
}

sji_element* sjf_nauscene3delement_heap_as_sji_element(sjs_nauscene3delement* _this) {
    sji_element* _interface;
    _interface = (sji_element*)malloc(sizeof(sji_element));
    _interface->_refCount = 1;
    _interface->_parent = (sjs_object*)_this;
    _interface->_parent->_refCount++;
    _interface->destroy = (void(*)(void*))sjf_nauscene3delement_destroy;
    _interface->asInterface = (sjs_object*(*)(sjs_object*,int))sjf_nauscene3delement_heap_asInterface;
    _interface->getsize = (void(*)(void*,sjs_size*, sjs_size*))sjf_nauscene3delement_getsize;
    _interface->getsize_heap = (void(*)(void*,sjs_size*, sjs_size**))sjf_nauscene3delement_getsize_heap;
    _interface->getrect = (void(*)(void*, sjs_rect**))sjf_nauscene3delement_getrect;
    _interface->setrect = (void(*)(void*,sjs_rect*))sjf_nauscene3delement_setrect;
    _interface->render = (void(*)(void*,sjs_scene2d*))sjf_nauscene3delement_render;
    _interface->firemouseevent = (void(*)(void*,sjs_mouseevent*))sjf_nauscene3delement_firemouseevent;

    return _interface;
}

void sjf_nauscene3delement_render(sjs_nauscene3delement* _parent, sjs_scene2d* scene) {
    int32_t i;
    sjs_array_heap_model* sjt_dot40;
    sjs_nauscene3delement* sjt_dot41;
    sjs_array_heap_model* sjt_dot48;
    sjs_nauscene3delement* sjt_dot49;
    int32_t sjt_forEnd4;
    int32_t sjt_forEnd5;
    int32_t sjt_forEnd6;
    int32_t sjt_forStart4;
    int32_t sjt_forStart5;
    int32_t sjt_forStart6;
    int32_t sjt_functionParam14;
    cb_heap_model_heap_model_i32 sjt_functionParam45;
    int32_t sjt_functionParam50;
    sjs_list_heap_model* sjt_parent14;
    sjs_list_heap_model* sjt_parent17;
    sjs_list_heap_model sjv_a = { -1 };

    sjt_forStart4 = 0;
    sjt_dot41 = _parent;
    sjt_dot40 = &(sjt_dot41)->children;
    sjt_forEnd4 = (sjt_dot40)->count;
    i = sjt_forStart4;
    while (i < sjt_forEnd4) {
        sjs_nauscene3delement* sjt_dot42;
        sjs_nauscene3delement* sjt_dot43;
        sjs_nauscene3delement* sjt_dot44;
        sjs_nauscene3delement* sjt_dot45;
        sjs_nauscene3delement* sjt_dot46;
        sjs_nauscene3delement* sjt_dot47;
        int32_t sjt_functionParam13;
        sjs_rect* sjt_interfaceParam4;
        sjs_mat4* sjt_interfaceParam5;
        sjs_mat4* sjt_interfaceParam6;
        sjs_mat4* sjt_interfaceParam7;
        sjs_light* sjt_interfaceParam8;
        sji_model* sjt_parent10;
        sjs_array_heap_model* sjt_parent9;
        sji_model* sjv_child = 0;

        sjt_dot42 = _parent;
        sjt_parent9 = &(sjt_dot42)->children;
        sjt_functionParam13 = i;
        sjf_array_heap_model_getat_heap(sjt_parent9, sjt_functionParam13, &sjv_child);
        sjt_parent10 = sjv_child;
        sjt_dot43 = _parent;
        sjt_interfaceParam4 = &(sjt_dot43)->_rect;
        sjt_dot44 = _parent;
        sjt_interfaceParam5 = &(sjt_dot44)->projection;
        sjt_dot45 = _parent;
        sjt_interfaceParam6 = &(sjt_dot45)->view;
        sjt_dot46 = _parent;
        sjt_interfaceParam7 = &(sjt_dot46)->world;
        sjt_dot47 = _parent;
        sjt_interfaceParam8 = &(sjt_dot47)->light;
        sjt_parent10->update(sjt_parent10->_parent, sjt_interfaceParam4, sjt_interfaceParam5, sjt_interfaceParam6, sjt_interfaceParam7, sjt_interfaceParam8);
        i++;

        sjv_child->_refCount--;
        if (sjv_child->_refCount <= 0) {
            sji_model_destroy(sjv_child);
        }
    }

    sjt_functionParam14 = sjv_glfeature_gl_depth_test;
    sjf_glenable(sjt_functionParam14);
    sjv_a._refCount = 1;
    sjv_a.array._refCount = 1;
    sjv_a.array.datasize = 0;
    sjv_a.array.data = 0;
    sjv_a.array._isglobal = false;
    sjv_a.array.count = 0;
    sjf_array_heap_model(&sjv_a.array);
    sjf_list_heap_model(&sjv_a);
    sjt_forStart5 = 0;
    sjt_dot49 = _parent;
    sjt_dot48 = &(sjt_dot49)->children;
    sjt_forEnd5 = (sjt_dot48)->count;
    i = sjt_forStart5;
    while (i < sjt_forEnd5) {
        sjs_nauscene3delement* sjt_dot50;
        int32_t sjt_functionParam15;
        sjs_list_heap_model* sjt_interfaceParam9;
        sjs_array_heap_model* sjt_parent11;
        sji_model* sjt_parent12;
        sji_model* sjv_child = 0;

        sjt_dot50 = _parent;
        sjt_parent11 = &(sjt_dot50)->children;
        sjt_functionParam15 = i;
        sjf_array_heap_model_getat_heap(sjt_parent11, sjt_functionParam15, &sjv_child);
        sjt_parent12 = sjv_child;
        sjt_interfaceParam9 = &sjv_a;
        sjt_parent12->renderorqueue(sjt_parent12->_parent, sjt_interfaceParam9);
        i++;

        sjv_child->_refCount--;
        if (sjv_child->_refCount <= 0) {
            sji_model_destroy(sjv_child);
        }
    }

    sjt_parent14 = &sjv_a;
    sjt_functionParam45._parent = (void*)1;
    sjt_functionParam45._cb = (void(*)(void*,sji_model*,sji_model*, int32_t*))sjf_model_zsort_callback;
    sjf_list_heap_model_sortcb(sjt_parent14, sjt_functionParam45);
    sjt_forStart6 = 0;
    sjt_parent17 = &sjv_a;
    sjf_list_heap_model_getcount(sjt_parent17, &sjt_forEnd6);
    i = sjt_forEnd6 - 1;
    while (i >= sjt_forStart6) {
        int32_t sjt_functionParam49;
        sjs_list_heap_model* sjt_parent19;
        sji_model* sjt_parent20;
        sji_model* sjv_child = 0;

        sjt_parent19 = &sjv_a;
        sjt_functionParam49 = i;
        sjf_list_heap_model_getat_heap(sjt_parent19, sjt_functionParam49, &sjv_child);
        sjt_parent20 = sjv_child;
        sjt_parent20->render(sjt_parent20->_parent);
        i--;

        sjv_child->_refCount--;
        if (sjv_child->_refCount <= 0) {
            sji_model_destroy(sjv_child);
        }
    }

    sjt_functionParam50 = sjv_glfeature_gl_depth_test;
    sjf_gldisable(sjt_functionParam50);

    if (sjv_a._refCount == 1) { sjf_list_heap_model_destroy(&sjv_a); }
}

void sjf_nauscene3delement_setrect(sjs_nauscene3delement* _parent, sjs_rect* rect_) {
    bool result2;
    sjs_nauscene3delement* sjt_dot30;
    sjs_rect* sjt_functionParam6;
    bool sjt_ifElse1;
    bool sjt_not1;
    sjs_rect* sjt_parent8;

    sjt_dot30 = _parent;
    sjt_parent8 = &(sjt_dot30)->_rect;
    sjt_functionParam6 = rect_;
    sjf_rect_isequal(sjt_parent8, sjt_functionParam6, &sjt_not1);
    result2 = !sjt_not1;
    sjt_ifElse1 = result2;
    if (sjt_ifElse1) {
        int32_t sjt_cast3;
        int32_t sjt_cast4;
        sjs_rect* sjt_copy2;
        sjs_nauscene3delement* sjt_dot31;
        sjs_nauscene3delement* sjt_dot32;
        sjs_nauscene3delement* sjt_dot33;
        sjs_rect* sjt_dot34;
        sjs_nauscene3delement* sjt_dot35;
        sjs_rect* sjt_dot36;
        sjs_nauscene3delement* sjt_dot37;
        sjs_nauscene3delement* sjt_dot38;
        sjs_nauscene3delement* sjt_dot39;
        float sjt_functionParam10;
        float sjt_functionParam11;
        float sjt_functionParam12;
        float sjt_functionParam9;
        float sjt_math43;
        float sjt_math44;

        sjt_dot31 = _parent;
        sjt_copy2 = rect_;
        sjf_rect_copy(&sjt_dot31->_rect, sjt_copy2);
        sjt_dot32 = _parent;
        sjt_dot33 = _parent;
        sjt_functionParam9 = (sjt_dot33)->fieldofview;
        sjt_dot35 = _parent;
        sjt_dot34 = &(sjt_dot35)->_rect;
        sjt_cast3 = (sjt_dot34)->h;
        sjt_math43 = (float)sjt_cast3;
        sjt_dot37 = _parent;
        sjt_dot36 = &(sjt_dot37)->_rect;
        sjt_cast4 = (sjt_dot36)->w;
        sjt_math44 = (float)sjt_cast4;
        sjt_functionParam10 = sjt_math43 / sjt_math44;
        sjt_dot38 = _parent;
        sjt_functionParam11 = (sjt_dot38)->znear;
        sjt_dot39 = _parent;
        sjt_functionParam12 = (sjt_dot39)->zfar;
        sjf_mat4_perspective(sjt_functionParam9, sjt_functionParam10, sjt_functionParam11, sjt_functionParam12, &sjt_dot32->projection);
    }
}

void sjf_panel3d(sjs_panel3d* _this) {
}

sjs_object* sjf_panel3d_asInterface(sjs_panel3d* _this, int typeId) {
    switch (typeId) {
        case sji_model_typeId:  {
            return (sjs_object*)sjf_panel3d_as_sji_model(_this);
        }
    }

    return 0;
}

sji_model* sjf_panel3d_as_sji_model(sjs_panel3d* _this) {
    sji_model* _interface;
    _interface = (sji_model*)malloc(sizeof(sji_model));
    _interface->_refCount = 1;
    _interface->_parent = (sjs_object*)_this;
    _interface->_parent->_refCount++;
    _interface->destroy = (void(*)(void*))sjf_panel3d_destroy;
    _interface->asInterface = (sjs_object*(*)(sjs_object*,int))sjf_panel3d_asInterface;
    _interface->update = (void(*)(void*,sjs_rect*,sjs_mat4*,sjs_mat4*,sjs_mat4*,sjs_light*))sjf_panel3d_update;
    _interface->getz = (void(*)(void*, float*))sjf_panel3d_getz;
    _interface->renderorqueue = (void(*)(void*,sjs_list_heap_model*))sjf_panel3d_renderorqueue;
    _interface->render = (void(*)(void*))sjf_panel3d_render;
    _interface->firemouseevent = (void(*)(void*,sjs_mouseevent*))sjf_panel3d_firemouseevent;

    return _interface;
}

void sjf_panel3d_copy(sjs_panel3d* _this, sjs_panel3d* _from) {
    _this->model._refCount = 1;
    sjf_mat4_copy(&_this->model, &_from->model);
    _this->children._refCount = 1;
    sjf_array_heap_model_copy(&_this->children, &_from->children);
}

void sjf_panel3d_destroy(sjs_panel3d* _this) {
}

void sjf_panel3d_firemouseevent(sjs_panel3d* _parent, sjs_mouseevent* mouseevent) {
    int32_t i;
    sjs_array_heap_model* sjt_dot1692;
    sjs_panel3d* sjt_dot1693;
    int32_t sjt_forEnd27;
    int32_t sjt_forStart27;

    sjt_forStart27 = 0;
    sjt_dot1693 = _parent;
    sjt_dot1692 = &(sjt_dot1693)->children;
    sjt_forEnd27 = (sjt_dot1692)->count;
    i = sjt_forStart27;
    while (i < sjt_forEnd27) {
        sjs_panel3d* sjt_dot1694;
        int32_t sjt_functionParam520;
        sjs_mouseevent* sjt_interfaceParam35;
        sjs_array_heap_model* sjt_parent214;
        sji_model* sjt_parent215;
        sji_model* sjv_c = 0;

        sjt_dot1694 = _parent;
        sjt_parent214 = &(sjt_dot1694)->children;
        sjt_functionParam520 = i;
        sjf_array_heap_model_getat_heap(sjt_parent214, sjt_functionParam520, &sjv_c);
        sjt_parent215 = sjv_c;
        sjt_interfaceParam35 = mouseevent;
        sjt_parent215->firemouseevent(sjt_parent215->_parent, sjt_interfaceParam35);
        i++;

        sjv_c->_refCount--;
        if (sjv_c->_refCount <= 0) {
            sji_model_destroy(sjv_c);
        }
    }
}

void sjf_panel3d_getz(sjs_panel3d* _parent, float* _return) {
    (*_return) = 0.0f;
}

void sjf_panel3d_heap(sjs_panel3d* _this) {
}

sjs_object* sjf_panel3d_heap_asInterface(sjs_panel3d* _this, int typeId) {
    switch (typeId) {
        case sji_model_typeId:  {
            return (sjs_object*)sjf_panel3d_heap_as_sji_model(_this);
        }
    }

    return 0;
}

sji_model* sjf_panel3d_heap_as_sji_model(sjs_panel3d* _this) {
    sji_model* _interface;
    _interface = (sji_model*)malloc(sizeof(sji_model));
    _interface->_refCount = 1;
    _interface->_parent = (sjs_object*)_this;
    _interface->_parent->_refCount++;
    _interface->destroy = (void(*)(void*))sjf_panel3d_destroy;
    _interface->asInterface = (sjs_object*(*)(sjs_object*,int))sjf_panel3d_heap_asInterface;
    _interface->update = (void(*)(void*,sjs_rect*,sjs_mat4*,sjs_mat4*,sjs_mat4*,sjs_light*))sjf_panel3d_update;
    _interface->getz = (void(*)(void*, float*))sjf_panel3d_getz;
    _interface->renderorqueue = (void(*)(void*,sjs_list_heap_model*))sjf_panel3d_renderorqueue;
    _interface->render = (void(*)(void*))sjf_panel3d_render;
    _interface->firemouseevent = (void(*)(void*,sjs_mouseevent*))sjf_panel3d_firemouseevent;

    return _interface;
}

void sjf_panel3d_render(sjs_panel3d* _parent) {
}

void sjf_panel3d_renderorqueue(sjs_panel3d* _parent, sjs_list_heap_model* zqueue) {
    int32_t i;
    sjs_array_heap_model* sjt_dot1689;
    sjs_panel3d* sjt_dot1690;
    int32_t sjt_forEnd26;
    int32_t sjt_forStart26;

    sjt_forStart26 = 0;
    sjt_dot1690 = _parent;
    sjt_dot1689 = &(sjt_dot1690)->children;
    sjt_forEnd26 = (sjt_dot1689)->count;
    i = sjt_forStart26;
    while (i < sjt_forEnd26) {
        sjs_panel3d* sjt_dot1691;
        int32_t sjt_functionParam519;
        sjs_list_heap_model* sjt_interfaceParam34;
        sjs_array_heap_model* sjt_parent212;
        sji_model* sjt_parent213;
        sji_model* sjv_c = 0;

        sjt_dot1691 = _parent;
        sjt_parent212 = &(sjt_dot1691)->children;
        sjt_functionParam519 = i;
        sjf_array_heap_model_getat_heap(sjt_parent212, sjt_functionParam519, &sjv_c);
        sjt_parent213 = sjv_c;
        sjt_interfaceParam34 = zqueue;
        sjt_parent213->renderorqueue(sjt_parent213->_parent, sjt_interfaceParam34);
        i++;

        sjv_c->_refCount--;
        if (sjv_c->_refCount <= 0) {
            sji_model_destroy(sjv_c);
        }
    }
}

void sjf_panel3d_update(sjs_panel3d* _parent, sjs_rect* scenerect, sjs_mat4* projection, sjs_mat4* view, sjs_mat4* world, sjs_light* light) {
    int32_t i;
    sjs_panel3d* sjt_dot1685;
    sjs_array_heap_model* sjt_dot1686;
    sjs_panel3d* sjt_dot1687;
    int32_t sjt_forEnd25;
    int32_t sjt_forStart25;
    sjs_mat4* sjt_functionParam517;
    sjs_mat4* sjt_parent209;
    sjs_mat4 sjv_childworld = { -1 };

    sjt_parent209 = world;
    sjt_dot1685 = _parent;
    sjt_functionParam517 = &(sjt_dot1685)->model;
    sjf_mat4_multiply(sjt_parent209, sjt_functionParam517, &sjv_childworld);
    sjt_forStart25 = 0;
    sjt_dot1687 = _parent;
    sjt_dot1686 = &(sjt_dot1687)->children;
    sjt_forEnd25 = (sjt_dot1686)->count;
    i = sjt_forStart25;
    while (i < sjt_forEnd25) {
        sjs_panel3d* sjt_dot1688;
        int32_t sjt_functionParam518;
        sjs_rect* sjt_interfaceParam29;
        sjs_mat4* sjt_interfaceParam30;
        sjs_mat4* sjt_interfaceParam31;
        sjs_mat4* sjt_interfaceParam32;
        sjs_light* sjt_interfaceParam33;
        sjs_array_heap_model* sjt_parent210;
        sji_model* sjt_parent211;
        sji_model* sjv_c = 0;

        sjt_dot1688 = _parent;
        sjt_parent210 = &(sjt_dot1688)->children;
        sjt_functionParam518 = i;
        sjf_array_heap_model_getat_heap(sjt_parent210, sjt_functionParam518, &sjv_c);
        sjt_parent211 = sjv_c;
        sjt_interfaceParam29 = scenerect;
        sjt_interfaceParam30 = projection;
        sjt_interfaceParam31 = view;
        sjt_interfaceParam32 = &sjv_childworld;
        sjt_interfaceParam33 = light;
        sjt_parent211->update(sjt_parent211->_parent, sjt_interfaceParam29, sjt_interfaceParam30, sjt_interfaceParam31, sjt_interfaceParam32, sjt_interfaceParam33);
        i++;

        sjv_c->_refCount--;
        if (sjv_c->_refCount <= 0) {
            sji_model_destroy(sjv_c);
        }
    }

    if (sjv_childworld._refCount == 1) { sjf_mat4_destroy(&sjv_childworld); }
}

void sjf_peoplepanel(sjs_peoplepanel* _this) {
    float result17;
    int32_t sjt_cast20;
    int32_t sjt_cast21;
    sjs_array_heap_model* sjt_dot1362;
    float sjt_functionParam279;
    cb_heap_model_mat4 sjt_functionParam284;
    float sjt_math2153;
    float sjt_math2154;
    float sjt_math2155;
    float sjt_math2156;
    float sjt_math2157;
    float sjt_math2158;
    float sjt_negate15;
    sjs_array_heap_model* sjt_parent110;

    sjt_math2155 = _this->_xincrement;
    sjt_dot1362 = &_this->children;
    sjt_cast20 = (sjt_dot1362)->count;
    sjt_math2157 = (float)sjt_cast20;
    sjt_cast21 = _this->_depth;
    sjt_math2158 = (float)sjt_cast21;
    sjt_functionParam279 = sjt_math2157 / sjt_math2158;
    sjf_f32_ceil(sjt_functionParam279, &sjt_math2156);
    sjt_math2153 = sjt_math2155 * sjt_math2156;
    sjt_math2154 = 2.0f;
    sjt_negate15 = sjt_math2153 / sjt_math2154;
    result17 = -sjt_negate15;
    _this->_xoffset = result17;
    sjt_parent110 = &_this->children;
    sjt_functionParam284._parent = &_this;
    sjt_functionParam284._cb = (void(*)(void*,sji_model*, sjs_mat4*))sjf_peoplepanel_getmodelmatrix;
    sjf_array_heap_model_map_mat4(sjt_parent110, sjt_functionParam284, &_this->_childrenmodel);
}

sjs_object* sjf_peoplepanel_asInterface(sjs_peoplepanel* _this, int typeId) {
    switch (typeId) {
        case sji_model_typeId:  {
            return (sjs_object*)sjf_peoplepanel_as_sji_model(_this);
        }
    }

    return 0;
}

sji_model* sjf_peoplepanel_as_sji_model(sjs_peoplepanel* _this) {
    sji_model* _interface;
    _interface = (sji_model*)malloc(sizeof(sji_model));
    _interface->_refCount = 1;
    _interface->_parent = (sjs_object*)_this;
    _interface->_parent->_refCount++;
    _interface->destroy = (void(*)(void*))sjf_peoplepanel_destroy;
    _interface->asInterface = (sjs_object*(*)(sjs_object*,int))sjf_peoplepanel_asInterface;
    _interface->update = (void(*)(void*,sjs_rect*,sjs_mat4*,sjs_mat4*,sjs_mat4*,sjs_light*))sjf_peoplepanel_update;
    _interface->getz = (void(*)(void*, float*))sjf_peoplepanel_getz;
    _interface->renderorqueue = (void(*)(void*,sjs_list_heap_model*))sjf_peoplepanel_renderorqueue;
    _interface->render = (void(*)(void*))sjf_peoplepanel_render;
    _interface->firemouseevent = (void(*)(void*,sjs_mouseevent*))sjf_peoplepanel_firemouseevent;

    return _interface;
}

void sjf_peoplepanel_copy(sjs_peoplepanel* _this, sjs_peoplepanel* _from) {
    _this->model._refCount = 1;
    sjf_mat4_copy(&_this->model, &_from->model);
    _this->children._refCount = 1;
    sjf_array_heap_model_copy(&_this->children, &_from->children);
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
    sjs_array_heap_model* sjt_dot1397;
    sjs_peoplepanel* sjt_dot1398;
    int32_t sjt_forEnd19;
    int32_t sjt_forStart19;

    sjt_forStart19 = 0;
    sjt_dot1398 = _parent;
    sjt_dot1397 = &(sjt_dot1398)->children;
    sjt_forEnd19 = (sjt_dot1397)->count;
    i = sjt_forStart19;
    while (i < sjt_forEnd19) {
        sjs_peoplepanel* sjt_dot1399;
        int32_t sjt_functionParam298;
        sjs_mouseevent* sjt_interfaceParam24;
        sjs_array_heap_model* sjt_parent118;
        sji_model* sjt_parent119;
        sji_model* sjv_c = 0;

        sjt_dot1399 = _parent;
        sjt_parent118 = &(sjt_dot1399)->children;
        sjt_functionParam298 = i;
        sjf_array_heap_model_getat_heap(sjt_parent118, sjt_functionParam298, &sjv_c);
        sjt_parent119 = sjv_c;
        sjt_interfaceParam24 = mouseevent;
        sjt_parent119->firemouseevent(sjt_parent119->_parent, sjt_interfaceParam24);
        i++;

        sjv_c->_refCount--;
        if (sjv_c->_refCount <= 0) {
            sji_model_destroy(sjv_c);
        }
    }
}

void sjf_peoplepanel_getmodelmatrix(sjs_peoplepanel* _parent, sji_model* model, sjs_mat4* _return) {
    int32_t sjt_cast22;
    int32_t sjt_cast23;
    int32_t sjt_cast24;
    int32_t sjt_compare51;
    int32_t sjt_compare52;
    sjs_peoplepanel* sjt_dot1369;
    sjs_peoplepanel* sjt_dot1370;
    sjs_peoplepanel* sjt_dot1371;
    sjs_peoplepanel* sjt_dot1372;
    sjs_peoplepanel* sjt_dot1373;
    sjs_peoplepanel* sjt_dot1374;
    sjs_peoplepanel* sjt_dot1376;
    sjs_peoplepanel* sjt_dot1377;
    sjs_peoplepanel* sjt_dot1378;
    float sjt_functionParam285;
    float sjt_functionParam286;
    float sjt_functionParam287;
    float sjt_functionParam288;
    bool sjt_ifElse17;
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
    sjt_dot1369 = _parent;
    sjt_cast22 = (sjt_dot1369)->_index;
    sjt_math2161 = (float)sjt_cast22;
    sjt_dot1370 = _parent;
    sjt_cast23 = (sjt_dot1370)->_depth;
    sjt_math2162 = (float)sjt_cast23;
    sjt_functionParam285 = sjt_math2161 / sjt_math2162;
    sjf_f32_floor(sjt_functionParam285, &sjv_row);
    sjt_dot1371 = _parent;
    sjt_math2163 = (sjt_dot1371)->_index;
    sjt_dot1372 = _parent;
    sjt_math2164 = (sjt_dot1372)->_depth;
    sjv_col = sjt_math2163 % sjt_math2164;
    sjt_math2169 = sjv_row;
    sjt_dot1373 = _parent;
    sjt_math2170 = (sjt_dot1373)->_xincrement;
    sjt_math2167 = sjt_math2169 * sjt_math2170;
    sjt_dot1374 = _parent;
    sjt_math2168 = (sjt_dot1374)->_xoffset;
    sjt_math2165 = sjt_math2167 + sjt_math2168;
    sjt_math2166 = sjv_noise;
    sjv_x = sjt_math2165 + sjt_math2166;
    sjt_math2171 = sjv_col;
    sjt_math2172 = 2;
    sjt_compare51 = sjt_math2171 % sjt_math2172;
    sjt_compare52 = 1;
    sjt_ifElse17 = sjt_compare51 == sjt_compare52;
    if (sjt_ifElse17) {
        sjs_peoplepanel* sjt_dot1375;
        float sjt_math2173;
        float sjt_math2174;
        float sjt_math2175;
        float sjt_math2176;

        sjt_math2173 = sjv_x;
        sjt_dot1375 = _parent;
        sjt_math2175 = (sjt_dot1375)->_xincrement;
        sjt_math2176 = 2.0f;
        sjt_math2174 = sjt_math2175 / sjt_math2176;
        sjv_x = sjt_math2173 + sjt_math2174;
    }

    sjt_cast24 = sjv_col;
    sjt_math2179 = (float)sjt_cast24;
    sjt_dot1376 = _parent;
    sjt_math2180 = (sjt_dot1376)->_zincrement;
    sjt_math2177 = sjt_math2179 * sjt_math2180;
    sjt_math2181 = sjv_noise;
    sjt_math2182 = 0.2f;
    sjt_math2178 = sjt_math2181 * sjt_math2182;
    sjv_z = sjt_math2177 + sjt_math2178;
    sjt_dot1377 = _parent;
    sjt_dot1378 = _parent;
    sjt_math2183 = (sjt_dot1378)->_index;
    sjt_math2184 = 1;
    sjt_dot1377->_index = sjt_math2183 + sjt_math2184;
    sjt_functionParam286 = sjv_x;
    sjt_functionParam287 = 0.0f;
    sjt_functionParam288 = sjv_z;
    sjf_mat4_translate(sjt_functionParam286, sjt_functionParam287, sjt_functionParam288, _return);
}

void sjf_peoplepanel_getmodelmatrix_heap(sjs_peoplepanel* _parent, sji_model* model, sjs_mat4** _return) {
    int32_t sjt_cast25;
    int32_t sjt_cast26;
    int32_t sjt_cast27;
    int32_t sjt_compare53;
    int32_t sjt_compare54;
    sjs_peoplepanel* sjt_dot1379;
    sjs_peoplepanel* sjt_dot1380;
    sjs_peoplepanel* sjt_dot1381;
    sjs_peoplepanel* sjt_dot1382;
    sjs_peoplepanel* sjt_dot1383;
    sjs_peoplepanel* sjt_dot1384;
    sjs_peoplepanel* sjt_dot1386;
    sjs_peoplepanel* sjt_dot1387;
    sjs_peoplepanel* sjt_dot1388;
    float sjt_functionParam289;
    float sjt_functionParam290;
    float sjt_functionParam291;
    float sjt_functionParam292;
    bool sjt_ifElse18;
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
    sjt_dot1379 = _parent;
    sjt_cast25 = (sjt_dot1379)->_index;
    sjt_math2187 = (float)sjt_cast25;
    sjt_dot1380 = _parent;
    sjt_cast26 = (sjt_dot1380)->_depth;
    sjt_math2188 = (float)sjt_cast26;
    sjt_functionParam289 = sjt_math2187 / sjt_math2188;
    sjf_f32_floor(sjt_functionParam289, &sjv_row);
    sjt_dot1381 = _parent;
    sjt_math2189 = (sjt_dot1381)->_index;
    sjt_dot1382 = _parent;
    sjt_math2190 = (sjt_dot1382)->_depth;
    sjv_col = sjt_math2189 % sjt_math2190;
    sjt_math2195 = sjv_row;
    sjt_dot1383 = _parent;
    sjt_math2196 = (sjt_dot1383)->_xincrement;
    sjt_math2193 = sjt_math2195 * sjt_math2196;
    sjt_dot1384 = _parent;
    sjt_math2194 = (sjt_dot1384)->_xoffset;
    sjt_math2191 = sjt_math2193 + sjt_math2194;
    sjt_math2192 = sjv_noise;
    sjv_x = sjt_math2191 + sjt_math2192;
    sjt_math2197 = sjv_col;
    sjt_math2198 = 2;
    sjt_compare53 = sjt_math2197 % sjt_math2198;
    sjt_compare54 = 1;
    sjt_ifElse18 = sjt_compare53 == sjt_compare54;
    if (sjt_ifElse18) {
        sjs_peoplepanel* sjt_dot1385;
        float sjt_math2199;
        float sjt_math2200;
        float sjt_math2201;
        float sjt_math2202;

        sjt_math2199 = sjv_x;
        sjt_dot1385 = _parent;
        sjt_math2201 = (sjt_dot1385)->_xincrement;
        sjt_math2202 = 2.0f;
        sjt_math2200 = sjt_math2201 / sjt_math2202;
        sjv_x = sjt_math2199 + sjt_math2200;
    }

    sjt_cast27 = sjv_col;
    sjt_math2205 = (float)sjt_cast27;
    sjt_dot1386 = _parent;
    sjt_math2206 = (sjt_dot1386)->_zincrement;
    sjt_math2203 = sjt_math2205 * sjt_math2206;
    sjt_math2207 = sjv_noise;
    sjt_math2208 = 0.2f;
    sjt_math2204 = sjt_math2207 * sjt_math2208;
    sjv_z = sjt_math2203 + sjt_math2204;
    sjt_dot1387 = _parent;
    sjt_dot1388 = _parent;
    sjt_math2209 = (sjt_dot1388)->_index;
    sjt_math2210 = 1;
    sjt_dot1387->_index = sjt_math2209 + sjt_math2210;
    sjt_functionParam290 = sjv_x;
    sjt_functionParam291 = 0.0f;
    sjt_functionParam292 = sjv_z;
    sjf_mat4_translate_heap(sjt_functionParam290, sjt_functionParam291, sjt_functionParam292, _return);
}

void sjf_peoplepanel_getz(sjs_peoplepanel* _parent, float* _return) {
    (*_return) = 0.0f;
}

void sjf_peoplepanel_heap(sjs_peoplepanel* _this) {
    float result18;
    int32_t sjt_cast28;
    int32_t sjt_cast29;
    sjs_array_heap_model* sjt_dot1400;
    float sjt_functionParam299;
    cb_heap_model_mat4 sjt_functionParam300;
    float sjt_math2211;
    float sjt_math2212;
    float sjt_math2213;
    float sjt_math2214;
    float sjt_math2215;
    float sjt_math2216;
    float sjt_negate16;
    sjs_array_heap_model* sjt_parent120;

    sjt_math2213 = _this->_xincrement;
    sjt_dot1400 = &_this->children;
    sjt_cast28 = (sjt_dot1400)->count;
    sjt_math2215 = (float)sjt_cast28;
    sjt_cast29 = _this->_depth;
    sjt_math2216 = (float)sjt_cast29;
    sjt_functionParam299 = sjt_math2215 / sjt_math2216;
    sjf_f32_ceil(sjt_functionParam299, &sjt_math2214);
    sjt_math2211 = sjt_math2213 * sjt_math2214;
    sjt_math2212 = 2.0f;
    sjt_negate16 = sjt_math2211 / sjt_math2212;
    result18 = -sjt_negate16;
    _this->_xoffset = result18;
    sjt_parent120 = &_this->children;
    sjt_functionParam300._parent = _this;
    sjt_functionParam300._cb = (void(*)(void*,sji_model*, sjs_mat4*))sjf_peoplepanel_getmodelmatrix;
    sjf_array_heap_model_map_mat4(sjt_parent120, sjt_functionParam300, &_this->_childrenmodel);
}

sjs_object* sjf_peoplepanel_heap_asInterface(sjs_peoplepanel* _this, int typeId) {
    switch (typeId) {
        case sji_model_typeId:  {
            return (sjs_object*)sjf_peoplepanel_heap_as_sji_model(_this);
        }
    }

    return 0;
}

sji_model* sjf_peoplepanel_heap_as_sji_model(sjs_peoplepanel* _this) {
    sji_model* _interface;
    _interface = (sji_model*)malloc(sizeof(sji_model));
    _interface->_refCount = 1;
    _interface->_parent = (sjs_object*)_this;
    _interface->_parent->_refCount++;
    _interface->destroy = (void(*)(void*))sjf_peoplepanel_destroy;
    _interface->asInterface = (sjs_object*(*)(sjs_object*,int))sjf_peoplepanel_heap_asInterface;
    _interface->update = (void(*)(void*,sjs_rect*,sjs_mat4*,sjs_mat4*,sjs_mat4*,sjs_light*))sjf_peoplepanel_update;
    _interface->getz = (void(*)(void*, float*))sjf_peoplepanel_getz;
    _interface->renderorqueue = (void(*)(void*,sjs_list_heap_model*))sjf_peoplepanel_renderorqueue;
    _interface->render = (void(*)(void*))sjf_peoplepanel_render;
    _interface->firemouseevent = (void(*)(void*,sjs_mouseevent*))sjf_peoplepanel_firemouseevent;

    return _interface;
}

void sjf_peoplepanel_render(sjs_peoplepanel* _parent) {
}

void sjf_peoplepanel_renderorqueue(sjs_peoplepanel* _parent, sjs_list_heap_model* zqueue) {
    int32_t i;
    sjs_array_heap_model* sjt_dot1394;
    sjs_peoplepanel* sjt_dot1395;
    int32_t sjt_forEnd18;
    int32_t sjt_forStart18;

    sjt_forStart18 = 0;
    sjt_dot1395 = _parent;
    sjt_dot1394 = &(sjt_dot1395)->children;
    sjt_forEnd18 = (sjt_dot1394)->count;
    i = sjt_forStart18;
    while (i < sjt_forEnd18) {
        sjs_peoplepanel* sjt_dot1396;
        int32_t sjt_functionParam297;
        sjs_list_heap_model* sjt_interfaceParam23;
        sjs_array_heap_model* sjt_parent116;
        sji_model* sjt_parent117;
        sji_model* sjv_c = 0;

        sjt_dot1396 = _parent;
        sjt_parent116 = &(sjt_dot1396)->children;
        sjt_functionParam297 = i;
        sjf_array_heap_model_getat_heap(sjt_parent116, sjt_functionParam297, &sjv_c);
        sjt_parent117 = sjv_c;
        sjt_interfaceParam23 = zqueue;
        sjt_parent117->renderorqueue(sjt_parent117->_parent, sjt_interfaceParam23);
        i++;

        sjv_c->_refCount--;
        if (sjv_c->_refCount <= 0) {
            sji_model_destroy(sjv_c);
        }
    }
}

void sjf_peoplepanel_update(sjs_peoplepanel* _parent, sjs_rect* scenerect, sjs_mat4* projection, sjs_mat4* view, sjs_mat4* world, sjs_light* light) {
    int32_t i;
    sjs_array_heap_model* sjt_dot1389;
    sjs_peoplepanel* sjt_dot1390;
    int32_t sjt_forEnd17;
    int32_t sjt_forStart17;

    sjt_forStart17 = 0;
    sjt_dot1390 = _parent;
    sjt_dot1389 = &(sjt_dot1390)->children;
    sjt_forEnd17 = (sjt_dot1389)->count;
    i = sjt_forStart17;
    while (i < sjt_forEnd17) {
        sjs_mat4 sjt_call53 = { -1 };
        sjs_peoplepanel* sjt_dot1391;
        sjs_peoplepanel* sjt_dot1392;
        sjs_peoplepanel* sjt_dot1393;
        int32_t sjt_functionParam293;
        int32_t sjt_functionParam294;
        sjs_mat4* sjt_functionParam295;
        sjs_mat4* sjt_functionParam296;
        sjs_rect* sjt_interfaceParam18;
        sjs_mat4* sjt_interfaceParam19;
        sjs_mat4* sjt_interfaceParam20;
        sjs_mat4* sjt_interfaceParam21;
        sjs_light* sjt_interfaceParam22;
        sjs_array_heap_model* sjt_parent111;
        sjs_array_mat4* sjt_parent112;
        sjs_mat4* sjt_parent113;
        sjs_mat4* sjt_parent114;
        sji_model* sjt_parent115;
        sji_model* sjv_c = 0;
        sjs_mat4 sjv_childmodel = { -1 };
        sjs_mat4 sjv_newworld = { -1 };

        sjt_dot1391 = _parent;
        sjt_parent111 = &(sjt_dot1391)->children;
        sjt_functionParam293 = i;
        sjf_array_heap_model_getat_heap(sjt_parent111, sjt_functionParam293, &sjv_c);
        sjt_dot1392 = _parent;
        sjt_parent112 = &(sjt_dot1392)->_childrenmodel;
        sjt_functionParam294 = i;
        sjf_array_mat4_getat(sjt_parent112, sjt_functionParam294, &sjv_childmodel);
        sjt_parent114 = world;
        sjt_dot1393 = _parent;
        sjt_functionParam295 = &(sjt_dot1393)->model;
        sjf_mat4_multiply(sjt_parent114, sjt_functionParam295, &sjt_call53);
        sjt_parent113 = &sjt_call53;
        sjt_functionParam296 = &sjv_childmodel;
        sjf_mat4_multiply(sjt_parent113, sjt_functionParam296, &sjv_newworld);
        sjt_parent115 = sjv_c;
        sjt_interfaceParam18 = scenerect;
        sjt_interfaceParam19 = projection;
        sjt_interfaceParam20 = view;
        sjt_interfaceParam21 = &sjv_newworld;
        sjt_interfaceParam22 = light;
        sjt_parent115->update(sjt_parent115->_parent, sjt_interfaceParam18, sjt_interfaceParam19, sjt_interfaceParam20, sjt_interfaceParam21, sjt_interfaceParam22);
        i++;

        sjv_c->_refCount--;
        if (sjv_c->_refCount <= 0) {
            sji_model_destroy(sjv_c);
        }
        if (sjt_call53._refCount == 1) { sjf_mat4_destroy(&sjt_call53); }
        if (sjv_childmodel._refCount == 1) { sjf_mat4_destroy(&sjv_childmodel); }
        if (sjv_newworld._refCount == 1) { sjf_mat4_destroy(&sjv_newworld); }
    }
}

void sjf_planevertexbuffer(float x0, float x1, float y0, float y1, float z0, float s0, float s1, float t0, float t1, sjs_vertexbuffer_vertex_location_texture_normal* _return) {
    float result5;
    float result6;
    float result7;
    float result8;
    sjs_vertex_location_texture_normal sjt_call22 = { -1 };
    sjs_vertex_location_texture_normal sjt_call23 = { -1 };
    sjs_vertex_location_texture_normal sjt_call24 = { -1 };
    sjs_vertex_location_texture_normal sjt_call25 = { -1 };
    sjs_string* sjt_copy9;
    int32_t sjt_functionParam151;
    int32_t sjt_functionParam152;
    int32_t sjt_functionParam153;
    int32_t sjt_functionParam154;
    int32_t sjt_functionParam155;
    int32_t sjt_functionParam156;
    int32_t sjt_functionParam157;
    int32_t sjt_functionParam158;
    int32_t sjt_functionParam159;
    int32_t sjt_functionParam160;
    int32_t sjt_functionParam161;
    int32_t sjt_functionParam162;
    int32_t sjt_functionParam163;
    sjs_vertex_location_texture_normal* sjt_functionParam164;
    int32_t sjt_functionParam165;
    sjs_vertex_location_texture_normal* sjt_functionParam166;
    int32_t sjt_functionParam167;
    sjs_vertex_location_texture_normal* sjt_functionParam168;
    int32_t sjt_functionParam169;
    sjs_vertex_location_texture_normal* sjt_functionParam170;
    float sjt_negate3;
    float sjt_negate4;
    float sjt_negate5;
    float sjt_negate6;
    sjs_array_i32* sjt_parent57;
    sjs_array_i32* sjt_parent58;
    sjs_array_i32* sjt_parent59;
    sjs_array_i32* sjt_parent60;
    sjs_array_i32* sjt_parent61;
    sjs_array_i32* sjt_parent62;
    sjs_array_vertex_location_texture_normal* sjt_parent63;
    sjs_array_vertex_location_texture_normal* sjt_parent64;
    sjs_array_vertex_location_texture_normal* sjt_parent65;
    sjs_array_vertex_location_texture_normal* sjt_parent66;

    _return->_refCount = 1;
    sjt_copy9 = &sjv_vertex_location_texture_normal_format;
    _return->format._refCount = 1;
    sjf_string_copy(&_return->format, sjt_copy9);
    _return->indices._refCount = 1;
    _return->indices.datasize = 6;
    _return->indices.data = 0;
    _return->indices._isglobal = false;
    _return->indices.count = 0;
    sjf_array_i32(&_return->indices);
    sjs_array_i32* array1;
    array1 = &_return->indices;
    sjt_parent57 = array1;
    sjt_functionParam151 = 0;
    sjt_functionParam152 = 0;
    sjf_array_i32_initat(sjt_parent57, sjt_functionParam151, sjt_functionParam152);
    sjt_parent58 = array1;
    sjt_functionParam153 = 1;
    sjt_functionParam154 = 1;
    sjf_array_i32_initat(sjt_parent58, sjt_functionParam153, sjt_functionParam154);
    sjt_parent59 = array1;
    sjt_functionParam155 = 2;
    sjt_functionParam156 = 2;
    sjf_array_i32_initat(sjt_parent59, sjt_functionParam155, sjt_functionParam156);
    sjt_parent60 = array1;
    sjt_functionParam157 = 3;
    sjt_functionParam158 = 0;
    sjf_array_i32_initat(sjt_parent60, sjt_functionParam157, sjt_functionParam158);
    sjt_parent61 = array1;
    sjt_functionParam159 = 4;
    sjt_functionParam160 = 2;
    sjf_array_i32_initat(sjt_parent61, sjt_functionParam159, sjt_functionParam160);
    sjt_parent62 = array1;
    sjt_functionParam161 = 5;
    sjt_functionParam162 = 3;
    sjf_array_i32_initat(sjt_parent62, sjt_functionParam161, sjt_functionParam162);
    _return->vertices._refCount = 1;
    _return->vertices.datasize = 4;
    _return->vertices.data = 0;
    _return->vertices._isglobal = false;
    _return->vertices.count = 0;
    sjf_array_vertex_location_texture_normal(&_return->vertices);
    sjs_array_vertex_location_texture_normal* array2;
    array2 = &_return->vertices;
    sjt_parent63 = array2;
    sjt_functionParam163 = 0;
    sjt_call22._refCount = 1;
    sjt_call22.location._refCount = 1;
    sjt_call22.location.x = x0;
    sjt_call22.location.y = y0;
    sjt_call22.location.z = z0;
    sjf_vec3(&sjt_call22.location);
    sjt_call22.texture._refCount = 1;
    sjt_call22.texture.x = s0;
    sjt_call22.texture.y = t0;
    sjf_vec2(&sjt_call22.texture);
    sjt_call22.normal._refCount = 1;
    sjt_call22.normal.x = 0.0f;
    sjt_call22.normal.y = 0.0f;
    sjt_negate3 = 1.0f;
    result5 = -sjt_negate3;
    sjt_call22.normal.z = result5;
    sjf_vec3(&sjt_call22.normal);
    sjf_vertex_location_texture_normal(&sjt_call22);
    sjt_functionParam164 = &sjt_call22;
    sjf_array_vertex_location_texture_normal_initat(sjt_parent63, sjt_functionParam163, sjt_functionParam164);
    sjt_parent64 = array2;
    sjt_functionParam165 = 1;
    sjt_call23._refCount = 1;
    sjt_call23.location._refCount = 1;
    sjt_call23.location.x = x0;
    sjt_call23.location.y = y1;
    sjt_call23.location.z = z0;
    sjf_vec3(&sjt_call23.location);
    sjt_call23.texture._refCount = 1;
    sjt_call23.texture.x = s0;
    sjt_call23.texture.y = t1;
    sjf_vec2(&sjt_call23.texture);
    sjt_call23.normal._refCount = 1;
    sjt_call23.normal.x = 0.0f;
    sjt_call23.normal.y = 0.0f;
    sjt_negate4 = 1.0f;
    result6 = -sjt_negate4;
    sjt_call23.normal.z = result6;
    sjf_vec3(&sjt_call23.normal);
    sjf_vertex_location_texture_normal(&sjt_call23);
    sjt_functionParam166 = &sjt_call23;
    sjf_array_vertex_location_texture_normal_initat(sjt_parent64, sjt_functionParam165, sjt_functionParam166);
    sjt_parent65 = array2;
    sjt_functionParam167 = 2;
    sjt_call24._refCount = 1;
    sjt_call24.location._refCount = 1;
    sjt_call24.location.x = x1;
    sjt_call24.location.y = y1;
    sjt_call24.location.z = z0;
    sjf_vec3(&sjt_call24.location);
    sjt_call24.texture._refCount = 1;
    sjt_call24.texture.x = s1;
    sjt_call24.texture.y = t1;
    sjf_vec2(&sjt_call24.texture);
    sjt_call24.normal._refCount = 1;
    sjt_call24.normal.x = 0.0f;
    sjt_call24.normal.y = 0.0f;
    sjt_negate5 = 1.0f;
    result7 = -sjt_negate5;
    sjt_call24.normal.z = result7;
    sjf_vec3(&sjt_call24.normal);
    sjf_vertex_location_texture_normal(&sjt_call24);
    sjt_functionParam168 = &sjt_call24;
    sjf_array_vertex_location_texture_normal_initat(sjt_parent65, sjt_functionParam167, sjt_functionParam168);
    sjt_parent66 = array2;
    sjt_functionParam169 = 3;
    sjt_call25._refCount = 1;
    sjt_call25.location._refCount = 1;
    sjt_call25.location.x = x1;
    sjt_call25.location.y = y0;
    sjt_call25.location.z = z0;
    sjf_vec3(&sjt_call25.location);
    sjt_call25.texture._refCount = 1;
    sjt_call25.texture.x = s1;
    sjt_call25.texture.y = t0;
    sjf_vec2(&sjt_call25.texture);
    sjt_call25.normal._refCount = 1;
    sjt_call25.normal.x = 0.0f;
    sjt_call25.normal.y = 0.0f;
    sjt_negate6 = 1.0f;
    result8 = -sjt_negate6;
    sjt_call25.normal.z = result8;
    sjf_vec3(&sjt_call25.normal);
    sjf_vertex_location_texture_normal(&sjt_call25);
    sjt_functionParam170 = &sjt_call25;
    sjf_array_vertex_location_texture_normal_initat(sjt_parent66, sjt_functionParam169, sjt_functionParam170);
    sjf_vertexbuffer_vertex_location_texture_normal(_return);

    if (sjt_call22._refCount == 1) { sjf_vertex_location_texture_normal_destroy(&sjt_call22); }
    if (sjt_call23._refCount == 1) { sjf_vertex_location_texture_normal_destroy(&sjt_call23); }
    if (sjt_call24._refCount == 1) { sjf_vertex_location_texture_normal_destroy(&sjt_call24); }
    if (sjt_call25._refCount == 1) { sjf_vertex_location_texture_normal_destroy(&sjt_call25); }
}

void sjf_planevertexbuffer_heap(float x0, float x1, float y0, float y1, float z0, float s0, float s1, float t0, float t1, sjs_vertexbuffer_vertex_location_texture_normal** _return) {
    float result10;
    float result11;
    float result12;
    float result9;
    sjs_vertex_location_texture_normal sjt_call26 = { -1 };
    sjs_vertex_location_texture_normal sjt_call27 = { -1 };
    sjs_vertex_location_texture_normal sjt_call28 = { -1 };
    sjs_vertex_location_texture_normal sjt_call29 = { -1 };
    sjs_string* sjt_copy10;
    int32_t sjt_functionParam171;
    int32_t sjt_functionParam172;
    int32_t sjt_functionParam173;
    int32_t sjt_functionParam174;
    int32_t sjt_functionParam175;
    int32_t sjt_functionParam176;
    int32_t sjt_functionParam177;
    int32_t sjt_functionParam178;
    int32_t sjt_functionParam179;
    int32_t sjt_functionParam180;
    int32_t sjt_functionParam181;
    int32_t sjt_functionParam182;
    int32_t sjt_functionParam183;
    sjs_vertex_location_texture_normal* sjt_functionParam184;
    int32_t sjt_functionParam185;
    sjs_vertex_location_texture_normal* sjt_functionParam186;
    int32_t sjt_functionParam187;
    sjs_vertex_location_texture_normal* sjt_functionParam188;
    int32_t sjt_functionParam189;
    sjs_vertex_location_texture_normal* sjt_functionParam190;
    float sjt_negate10;
    float sjt_negate7;
    float sjt_negate8;
    float sjt_negate9;
    sjs_array_i32* sjt_parent67;
    sjs_array_i32* sjt_parent68;
    sjs_array_i32* sjt_parent69;
    sjs_array_i32* sjt_parent70;
    sjs_array_i32* sjt_parent71;
    sjs_array_i32* sjt_parent72;
    sjs_array_vertex_location_texture_normal* sjt_parent73;
    sjs_array_vertex_location_texture_normal* sjt_parent74;
    sjs_array_vertex_location_texture_normal* sjt_parent75;
    sjs_array_vertex_location_texture_normal* sjt_parent76;

    (*_return) = (sjs_vertexbuffer_vertex_location_texture_normal*)malloc(sizeof(sjs_vertexbuffer_vertex_location_texture_normal));
    (*_return)->_refCount = 1;
    sjt_copy10 = &sjv_vertex_location_texture_normal_format;
    (*_return)->format._refCount = 1;
    sjf_string_copy(&(*_return)->format, sjt_copy10);
    (*_return)->indices._refCount = 1;
    (*_return)->indices.datasize = 6;
    (*_return)->indices.data = 0;
    (*_return)->indices._isglobal = false;
    (*_return)->indices.count = 0;
    sjf_array_i32(&(*_return)->indices);
    sjs_array_i32* array3;
    array3 = &(*_return)->indices;
    sjt_parent67 = array3;
    sjt_functionParam171 = 0;
    sjt_functionParam172 = 0;
    sjf_array_i32_initat(sjt_parent67, sjt_functionParam171, sjt_functionParam172);
    sjt_parent68 = array3;
    sjt_functionParam173 = 1;
    sjt_functionParam174 = 1;
    sjf_array_i32_initat(sjt_parent68, sjt_functionParam173, sjt_functionParam174);
    sjt_parent69 = array3;
    sjt_functionParam175 = 2;
    sjt_functionParam176 = 2;
    sjf_array_i32_initat(sjt_parent69, sjt_functionParam175, sjt_functionParam176);
    sjt_parent70 = array3;
    sjt_functionParam177 = 3;
    sjt_functionParam178 = 0;
    sjf_array_i32_initat(sjt_parent70, sjt_functionParam177, sjt_functionParam178);
    sjt_parent71 = array3;
    sjt_functionParam179 = 4;
    sjt_functionParam180 = 2;
    sjf_array_i32_initat(sjt_parent71, sjt_functionParam179, sjt_functionParam180);
    sjt_parent72 = array3;
    sjt_functionParam181 = 5;
    sjt_functionParam182 = 3;
    sjf_array_i32_initat(sjt_parent72, sjt_functionParam181, sjt_functionParam182);
    (*_return)->vertices._refCount = 1;
    (*_return)->vertices.datasize = 4;
    (*_return)->vertices.data = 0;
    (*_return)->vertices._isglobal = false;
    (*_return)->vertices.count = 0;
    sjf_array_vertex_location_texture_normal(&(*_return)->vertices);
    sjs_array_vertex_location_texture_normal* array4;
    array4 = &(*_return)->vertices;
    sjt_parent73 = array4;
    sjt_functionParam183 = 0;
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
    sjt_negate7 = 1.0f;
    result9 = -sjt_negate7;
    sjt_call26.normal.z = result9;
    sjf_vec3(&sjt_call26.normal);
    sjf_vertex_location_texture_normal(&sjt_call26);
    sjt_functionParam184 = &sjt_call26;
    sjf_array_vertex_location_texture_normal_initat(sjt_parent73, sjt_functionParam183, sjt_functionParam184);
    sjt_parent74 = array4;
    sjt_functionParam185 = 1;
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
    sjt_negate8 = 1.0f;
    result10 = -sjt_negate8;
    sjt_call27.normal.z = result10;
    sjf_vec3(&sjt_call27.normal);
    sjf_vertex_location_texture_normal(&sjt_call27);
    sjt_functionParam186 = &sjt_call27;
    sjf_array_vertex_location_texture_normal_initat(sjt_parent74, sjt_functionParam185, sjt_functionParam186);
    sjt_parent75 = array4;
    sjt_functionParam187 = 2;
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
    sjt_negate9 = 1.0f;
    result11 = -sjt_negate9;
    sjt_call28.normal.z = result11;
    sjf_vec3(&sjt_call28.normal);
    sjf_vertex_location_texture_normal(&sjt_call28);
    sjt_functionParam188 = &sjt_call28;
    sjf_array_vertex_location_texture_normal_initat(sjt_parent75, sjt_functionParam187, sjt_functionParam188);
    sjt_parent76 = array4;
    sjt_functionParam189 = 3;
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
    sjt_negate10 = 1.0f;
    result12 = -sjt_negate10;
    sjt_call29.normal.z = result12;
    sjf_vec3(&sjt_call29.normal);
    sjf_vertex_location_texture_normal(&sjt_call29);
    sjt_functionParam190 = &sjt_call29;
    sjf_array_vertex_location_texture_normal_initat(sjt_parent76, sjt_functionParam189, sjt_functionParam190);
    sjf_vertexbuffer_vertex_location_texture_normal_heap((*_return));

    if (sjt_call26._refCount == 1) { sjf_vertex_location_texture_normal_destroy(&sjt_call26); }
    if (sjt_call27._refCount == 1) { sjf_vertex_location_texture_normal_destroy(&sjt_call27); }
    if (sjt_call28._refCount == 1) { sjf_vertex_location_texture_normal_destroy(&sjt_call28); }
    if (sjt_call29._refCount == 1) { sjf_vertex_location_texture_normal_destroy(&sjt_call29); }
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
    int32_t sjt_compare113;
    int32_t sjt_compare114;
    int32_t sjt_compare115;
    int32_t sjt_compare116;
    int32_t sjt_compare117;
    int32_t sjt_compare118;
    int32_t sjt_compare119;
    int32_t sjt_compare120;
    sjs_rect* sjt_dot1668;
    sjs_point* sjt_dot1669;
    sjs_rect* sjt_dot1670;
    sjs_point* sjt_dot1671;
    sjs_point* sjt_dot1672;
    sjs_rect* sjt_dot1673;
    sjs_rect* sjt_dot1674;
    sjs_point* sjt_dot1675;
    sjs_rect* sjt_dot1676;
    sjs_rect* sjt_dot1677;
    int32_t sjt_math2427;
    int32_t sjt_math2428;
    int32_t sjt_math2429;
    int32_t sjt_math2430;

    sjt_dot1668 = _parent;
    sjt_compare113 = (sjt_dot1668)->x;
    sjt_dot1669 = point;
    sjt_compare114 = (sjt_dot1669)->x;
    sjt_and13 = sjt_compare113 <= sjt_compare114;
    sjt_dot1670 = _parent;
    sjt_compare115 = (sjt_dot1670)->y;
    sjt_dot1671 = point;
    sjt_compare116 = (sjt_dot1671)->x;
    sjt_and15 = sjt_compare115 <= sjt_compare116;
    sjt_dot1672 = point;
    sjt_compare117 = (sjt_dot1672)->x;
    sjt_dot1673 = _parent;
    sjt_math2427 = (sjt_dot1673)->x;
    sjt_dot1674 = _parent;
    sjt_math2428 = (sjt_dot1674)->w;
    sjt_compare118 = sjt_math2427 + sjt_math2428;
    sjt_and17 = sjt_compare117 < sjt_compare118;
    sjt_dot1675 = point;
    sjt_compare119 = (sjt_dot1675)->y;
    sjt_dot1676 = _parent;
    sjt_math2429 = (sjt_dot1676)->y;
    sjt_dot1677 = _parent;
    sjt_math2430 = (sjt_dot1677)->h;
    sjt_compare120 = sjt_math2429 + sjt_math2430;
    sjt_and18 = sjt_compare119 < sjt_compare120;
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
    sjs_rect* sjt_dot22;
    sjs_rect* sjt_dot23;
    sjs_rect* sjt_dot24;
    sjs_rect* sjt_dot25;
    sjs_rect* sjt_dot26;
    sjs_rect* sjt_dot27;
    sjs_rect* sjt_dot28;
    sjs_rect* sjt_dot29;

    sjt_dot22 = _parent;
    sjt_compare1 = (sjt_dot22)->x;
    sjt_dot23 = rect;
    sjt_compare2 = (sjt_dot23)->x;
    sjt_and1 = sjt_compare1 == sjt_compare2;
    sjt_dot24 = _parent;
    sjt_compare3 = (sjt_dot24)->y;
    sjt_dot25 = rect;
    sjt_compare4 = (sjt_dot25)->y;
    sjt_and3 = sjt_compare3 == sjt_compare4;
    sjt_dot26 = _parent;
    sjt_compare5 = (sjt_dot26)->w;
    sjt_dot27 = rect;
    sjt_compare6 = (sjt_dot27)->w;
    sjt_and5 = sjt_compare5 == sjt_compare6;
    sjt_dot28 = _parent;
    sjt_compare7 = (sjt_dot28)->h;
    sjt_dot29 = rect;
    sjt_compare8 = (sjt_dot29)->h;
    sjt_and6 = sjt_compare7 == sjt_compare8;
    sjt_and4 = sjt_and5 && sjt_and6;
    sjt_and2 = sjt_and3 && sjt_and4;
    (*_return) = sjt_and1 && sjt_and2;
}

void sjf_rect_subtractmargin(sjs_rect* _parent, sjs_margin* margin, sjs_rect* _return) {
    sjs_rect* sjt_dot1596;
    sjs_margin* sjt_dot1597;
    sjs_rect* sjt_dot1598;
    sjs_margin* sjt_dot1599;
    sjs_rect* sjt_dot1600;
    sjs_margin* sjt_dot1601;
    sjs_margin* sjt_dot1602;
    sjs_rect* sjt_dot1603;
    sjs_margin* sjt_dot1604;
    sjs_margin* sjt_dot1605;
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
    sjt_dot1596 = _parent;
    sjt_math2403 = (sjt_dot1596)->x;
    sjt_dot1597 = margin;
    sjt_math2404 = (sjt_dot1597)->l;
    _return->x = sjt_math2403 + sjt_math2404;
    sjt_dot1598 = _parent;
    sjt_math2405 = (sjt_dot1598)->y;
    sjt_dot1599 = margin;
    sjt_math2406 = (sjt_dot1599)->t;
    _return->y = sjt_math2405 + sjt_math2406;
    sjt_dot1600 = _parent;
    sjt_math2409 = (sjt_dot1600)->w;
    sjt_dot1601 = margin;
    sjt_math2410 = (sjt_dot1601)->l;
    sjt_math2407 = sjt_math2409 - sjt_math2410;
    sjt_dot1602 = margin;
    sjt_math2408 = (sjt_dot1602)->r;
    _return->w = sjt_math2407 - sjt_math2408;
    sjt_dot1603 = _parent;
    sjt_math2413 = (sjt_dot1603)->h;
    sjt_dot1604 = margin;
    sjt_math2414 = (sjt_dot1604)->t;
    sjt_math2411 = sjt_math2413 - sjt_math2414;
    sjt_dot1605 = margin;
    sjt_math2412 = (sjt_dot1605)->b;
    _return->h = sjt_math2411 - sjt_math2412;
    sjf_rect(_return);
}

void sjf_rect_subtractmargin_heap(sjs_rect* _parent, sjs_margin* margin, sjs_rect** _return) {
    sjs_rect* sjt_dot1606;
    sjs_margin* sjt_dot1607;
    sjs_rect* sjt_dot1608;
    sjs_margin* sjt_dot1609;
    sjs_rect* sjt_dot1610;
    sjs_margin* sjt_dot1611;
    sjs_margin* sjt_dot1612;
    sjs_rect* sjt_dot1613;
    sjs_margin* sjt_dot1614;
    sjs_margin* sjt_dot1615;
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
    sjt_dot1606 = _parent;
    sjt_math2415 = (sjt_dot1606)->x;
    sjt_dot1607 = margin;
    sjt_math2416 = (sjt_dot1607)->l;
    (*_return)->x = sjt_math2415 + sjt_math2416;
    sjt_dot1608 = _parent;
    sjt_math2417 = (sjt_dot1608)->y;
    sjt_dot1609 = margin;
    sjt_math2418 = (sjt_dot1609)->t;
    (*_return)->y = sjt_math2417 + sjt_math2418;
    sjt_dot1610 = _parent;
    sjt_math2421 = (sjt_dot1610)->w;
    sjt_dot1611 = margin;
    sjt_math2422 = (sjt_dot1611)->l;
    sjt_math2419 = sjt_math2421 - sjt_math2422;
    sjt_dot1612 = margin;
    sjt_math2420 = (sjt_dot1612)->r;
    (*_return)->w = sjt_math2419 - sjt_math2420;
    sjt_dot1613 = _parent;
    sjt_math2425 = (sjt_dot1613)->h;
    sjt_dot1614 = margin;
    sjt_math2426 = (sjt_dot1614)->t;
    sjt_math2423 = sjt_math2425 - sjt_math2426;
    sjt_dot1615 = margin;
    sjt_math2424 = (sjt_dot1615)->b;
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
    sjs_scene2d* sjt_dot1405;
    sjs_size* sjt_functionParam339;
    bool sjt_ifElse20;
    bool sjt_not3;
    sjs_size* sjt_parent122;

    sjt_dot1405 = _parent;
    sjt_parent122 = &(sjt_dot1405)->_size;
    sjt_functionParam339 = size;
    sjf_size_isequal(sjt_parent122, sjt_functionParam339, &sjt_not3);
    result19 = !sjt_not3;
    sjt_ifElse20 = result19;
    if (sjt_ifElse20) {
        float result22;
        float result23;
        int32_t sjt_cast31;
        int32_t sjt_cast32;
        sjs_size* sjt_copy22;
        sjs_scene2d* sjt_dot1406;
        sjs_scene2d* sjt_dot1407;
        sjs_size* sjt_dot1408;
        sjs_scene2d* sjt_dot1409;
        sjs_size* sjt_dot1410;
        sjs_scene2d* sjt_dot1411;
        sjs_scene2d* sjt_dot1412;
        sjs_scene2d* sjt_dot1413;
        float sjt_functionParam340;
        float sjt_functionParam341;
        float sjt_functionParam342;
        float sjt_functionParam343;
        float sjt_functionParam344;
        float sjt_functionParam345;
        float sjt_functionParam346;
        float sjt_functionParam347;
        float sjt_functionParam348;
        int32_t sjt_math2289;
        int32_t sjt_math2290;
        float sjt_negate19;
        float sjt_negate20;

        sjt_dot1406 = _parent;
        sjt_copy22 = size;
        sjf_size_copy(&sjt_dot1406->_size, sjt_copy22);
        sjt_dot1407 = _parent;
        sjt_functionParam340 = 0.0f;
        sjt_dot1409 = _parent;
        sjt_dot1408 = &(sjt_dot1409)->_size;
        sjt_cast31 = (sjt_dot1408)->w;
        sjt_functionParam341 = (float)sjt_cast31;
        sjt_math2289 = 0;
        sjt_dot1411 = _parent;
        sjt_dot1410 = &(sjt_dot1411)->_size;
        sjt_math2290 = (sjt_dot1410)->h;
        sjt_cast32 = sjt_math2289 - sjt_math2290;
        sjt_functionParam342 = (float)sjt_cast32;
        sjt_functionParam343 = 0.0f;
        sjt_negate19 = 1.0f;
        result22 = -sjt_negate19;
        sjt_functionParam344 = result22;
        sjt_functionParam345 = 1.0f;
        sjf_mat4_orthographic(sjt_functionParam340, sjt_functionParam341, sjt_functionParam342, sjt_functionParam343, sjt_functionParam344, sjt_functionParam345, &sjt_dot1407->projection);
        sjt_dot1412 = _parent;
        sjt_functionParam346 = 1.0f;
        sjt_negate20 = 1.0f;
        result23 = -sjt_negate20;
        sjt_functionParam347 = result23;
        sjt_functionParam348 = 1.0f;
        sjf_mat4_scale(sjt_functionParam346, sjt_functionParam347, sjt_functionParam348, &sjt_dot1412->model);
        sjt_dot1413 = _parent;
        sjf_mat4_identity(&sjt_dot1413->view);
    }
}

void sjf_scene2d_updateviewport(sjs_scene2d* _parent) {
    glViewport(0, 0, _parent->_size.w, _parent->_size.h);
}

void sjf_scene2dmodel(sjs_scene2dmodel* _this) {
    int32_t i;
    sjs_string sjt_call54 = { -1 };
    int32_t sjt_compare55;
    int32_t sjt_compare56;
    sjs_size* sjt_dot1414;
    sjs_size* sjt_dot1415;
    sjs_array_heap_element* sjt_dot1416;
    int32_t sjt_forEnd20;
    int32_t sjt_forStart20;
    sjs_size* sjt_functionParam306;
    sjs_size* sjt_functionParam307;
    sjs_framebuffer* sjt_functionParam308;
    int32_t sjt_functionParam309;
    sjs_texture* sjt_functionParam310;
    int32_t sjt_functionParam311;
    int32_t sjt_functionParam312;
    int32_t sjt_functionParam313;
    int32_t sjt_functionParam314;
    int32_t sjt_functionParam315;
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
    sjs_size* sjt_functionParam326;
    int32_t sjt_functionParam327;
    void* sjt_functionParam328;
    int32_t sjt_functionParam329;
    int32_t sjt_functionParam330;
    sjs_texture* sjt_functionParam331;
    int32_t sjt_functionParam332;
    sjs_renderbuffer* sjt_functionParam333;
    int32_t sjt_functionParam334;
    sjs_size* sjt_functionParam335;
    int32_t sjt_functionParam336;
    sjs_renderbuffer* sjt_functionParam337;
    sjs_size* sjt_functionParam349;
    bool sjt_ifElse19;
    sjs_scene2d* sjt_parent123;
    sjs_rect sjv_rect = { -1 };
    int32_t sjv_status;

    sjt_functionParam306 = &_this->texturesize;
    sjf_glgentexture(sjt_functionParam306, &_this->_texture);
    sjt_functionParam307 = &_this->texturesize;
    sjf_glgenrenderbuffer(sjt_functionParam307, &_this->_renderbuffer);
    sjt_functionParam308 = &_this->_framebuffer;
    sjf_glbindframebuffer(sjt_functionParam308);
    sjt_functionParam309 = sjv_gltexture_gl_texture_2d;
    sjt_functionParam310 = &_this->_texture;
    sjf_glbindtexture(sjt_functionParam309, sjt_functionParam310);
    sjt_functionParam311 = sjv_gltexture_gl_texture_2d;
    sjt_functionParam312 = sjv_gltextureattribute_gl_texture_wrap_s;
    sjt_functionParam313 = sjv_gltexturevalue_gl_clamp_to_edge;
    sjf_gltexparameteri(sjt_functionParam311, sjt_functionParam312, sjt_functionParam313);
    sjt_functionParam314 = sjv_gltexture_gl_texture_2d;
    sjt_functionParam315 = sjv_gltextureattribute_gl_texture_wrap_t;
    sjt_functionParam316 = sjv_gltexturevalue_gl_clamp_to_edge;
    sjf_gltexparameteri(sjt_functionParam314, sjt_functionParam315, sjt_functionParam316);
    sjt_functionParam317 = sjv_gltexture_gl_texture_2d;
    sjt_functionParam318 = sjv_gltextureattribute_gl_texture_min_filter;
    sjt_functionParam319 = sjv_gltexturevalue_gl_nearest;
    sjf_gltexparameteri(sjt_functionParam317, sjt_functionParam318, sjt_functionParam319);
    sjt_functionParam320 = sjv_gltexture_gl_texture_2d;
    sjt_functionParam321 = sjv_gltextureattribute_gl_texture_mag_filter;
    sjt_functionParam322 = sjv_gltexturevalue_gl_nearest;
    sjf_gltexparameteri(sjt_functionParam320, sjt_functionParam321, sjt_functionParam322);
    sjt_functionParam323 = sjv_gltexture_gl_texture_2d;
    sjt_functionParam324 = 0;
    sjt_functionParam325 = sjv_gltextureformat_gl_rgba;
    sjt_functionParam326 = &_this->texturesize;
    sjt_functionParam327 = sjv_gltexturetype_gl_unsigned_byte;
    sjt_functionParam328 = 0;
    sjf_glteximage2d(sjt_functionParam323, sjt_functionParam324, sjt_functionParam325, sjt_functionParam326, sjt_functionParam327, sjt_functionParam328);
    sjt_functionParam329 = sjv_glframebufferattachment_gl_color_attachment0;
    sjt_functionParam330 = sjv_glframebuffertexture_gl_texture_2d;
    sjt_functionParam331 = &_this->_texture;
    sjt_functionParam332 = 0;
    sjf_glframebuffertexture2d(sjt_functionParam329, sjt_functionParam330, sjt_functionParam331, sjt_functionParam332);
    sjt_functionParam333 = &_this->_renderbuffer;
    sjf_glbindrenderbuffer(sjt_functionParam333);
    sjt_functionParam334 = sjv_glrenderbufferformat_gl_depth_component16;
    sjt_functionParam335 = &_this->texturesize;
    sjf_glrenderbufferstorage(sjt_functionParam334, sjt_functionParam335);
    sjt_functionParam336 = sjv_glframebufferattachment_gl_depth_attachment;
    sjt_functionParam337 = &_this->_renderbuffer;
    sjf_glframebufferrenderbuffer(sjt_functionParam336, sjt_functionParam337);
    sjf_glcheckframebufferstatus(&sjv_status);
    sjt_compare55 = sjv_status;
    sjt_compare56 = sjv_glframebufferstatus_gl_framebuffer_complete;
    sjt_ifElse19 = sjt_compare55 != sjt_compare56;
    if (sjt_ifElse19) {
        sjs_string* sjt_functionParam338;

        sjt_call54._refCount = 1;
        sjt_call54.count = 18;
        sjt_call54.data._refCount = 1;
        sjt_call54.data.datasize = 19;
        sjt_call54.data.data = (void*)sjg_string27;
        sjt_call54.data._isglobal = true;
        sjt_call54.data.count = 19;
        sjf_array_char(&sjt_call54.data);
        sjf_string(&sjt_call54);
        sjt_functionParam338 = &sjt_call54;
        sjf_halt(sjt_functionParam338);
    }

    sjt_parent123 = &_this->_innerscene;
    sjt_functionParam349 = &_this->texturesize;
    sjf_scene2d_setsize(sjt_parent123, sjt_functionParam349);
    sjv_rect._refCount = 1;
    sjv_rect.x = 0;
    sjv_rect.y = 0;
    sjt_dot1414 = &_this->texturesize;
    sjv_rect.w = (sjt_dot1414)->w;
    sjt_dot1415 = &_this->texturesize;
    sjv_rect.h = (sjt_dot1415)->h;
    sjf_rect(&sjv_rect);
    sjt_forStart20 = 0;
    sjt_dot1416 = &_this->children;
    sjt_forEnd20 = (sjt_dot1416)->count;
    i = sjt_forStart20;
    while (i < sjt_forEnd20) {
        int32_t sjt_functionParam350;
        sjs_rect* sjt_interfaceParam25;
        sjs_array_heap_element* sjt_parent124;
        sji_element* sjt_parent125;
        sji_element* sjv_child = 0;

        sjt_parent124 = &_this->children;
        sjt_functionParam350 = i;
        sjf_array_heap_element_getat_heap(sjt_parent124, sjt_functionParam350, &sjv_child);
        sjt_parent125 = sjv_child;
        sjt_interfaceParam25 = &sjv_rect;
        sjt_parent125->setrect(sjt_parent125->_parent, sjt_interfaceParam25);
        i++;

        sjv_child->_refCount--;
        if (sjv_child->_refCount <= 0) {
            sji_element_destroy(sjv_child);
        }
    }

    if (sjt_call54._refCount == 1) { sjf_string_destroy(&sjt_call54); }
    if (sjv_rect._refCount == 1) { sjf_rect_destroy(&sjv_rect); }
}

sjs_object* sjf_scene2dmodel_asInterface(sjs_scene2dmodel* _this, int typeId) {
    switch (typeId) {
        case sji_model_typeId:  {
            return (sjs_object*)sjf_scene2dmodel_as_sji_model(_this);
        }
    }

    return 0;
}

sji_model* sjf_scene2dmodel_as_sji_model(sjs_scene2dmodel* _this) {
    sji_model* _interface;
    _interface = (sji_model*)malloc(sizeof(sji_model));
    _interface->_refCount = 1;
    _interface->_parent = (sjs_object*)_this;
    _interface->_parent->_refCount++;
    _interface->destroy = (void(*)(void*))sjf_scene2dmodel_destroy;
    _interface->asInterface = (sjs_object*(*)(sjs_object*,int))sjf_scene2dmodel_asInterface;
    _interface->update = (void(*)(void*,sjs_rect*,sjs_mat4*,sjs_mat4*,sjs_mat4*,sjs_light*))sjf_scene2dmodel_update;
    _interface->getz = (void(*)(void*, float*))sjf_scene2dmodel_getz;
    _interface->renderorqueue = (void(*)(void*,sjs_list_heap_model*))sjf_scene2dmodel_renderorqueue;
    _interface->render = (void(*)(void*))sjf_scene2dmodel_render;
    _interface->firemouseevent = (void(*)(void*,sjs_mouseevent*))sjf_scene2dmodel_firemouseevent;

    return _interface;
}

void sjf_scene2dmodel_copy(sjs_scene2dmodel* _this, sjs_scene2dmodel* _from) {
    _this->vertexbuffer._refCount = 1;
    sjf_vertexbuffer_vertex_location_texture_normal_copy(&_this->vertexbuffer, &_from->vertexbuffer);
    _this->shader._refCount = 1;
    sjf_shader_copy(&_this->shader, &_from->shader);
    _this->texturesize._refCount = 1;
    sjf_size_copy(&_this->texturesize, &_from->texturesize);
    _this->children._refCount = 1;
    sjf_array_heap_element_copy(&_this->children, &_from->children);
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
    sjs_mat4 sjt_call70 = { -1 };
    sjs_scene2dmodel* sjt_dot1535;
    sjs_mouseevent* sjt_dot1536;
    sjs_scene2dmodel* sjt_dot1537;
    sjs_scene2dmodel* sjt_dot1538;
    sjs_scene2dmodel* sjt_dot1539;
    sjs_scene2dmodel* sjt_dot1540;
    sjs_scene2dmodel* sjt_dot1541;
    sjs_point* sjt_functionParam428;
    sjs_rect* sjt_functionParam429;
    sjs_mat4* sjt_functionParam430;
    sjs_mat4* sjt_functionParam431;
    sjs_mat4* sjt_functionParam432;
    sjs_mat4* sjt_functionParam433;
    bool sjt_isEmpty10;
    sjs_vec2* sjt_isEmpty11;
    sjs_vertexbuffer_vertex_location_texture_normal* sjt_parent177;
    sjs_mat4* sjt_parent178;
    sjs_vec2 sjv_texture = { -1 };

    sjt_dot1535 = _parent;
    sjt_parent177 = &(sjt_dot1535)->vertexbuffer;
    sjt_dot1536 = mouseevent;
    sjt_functionParam428 = &(sjt_dot1536)->point;
    sjt_dot1537 = _parent;
    sjt_functionParam429 = &(sjt_dot1537)->_scenerect;
    sjt_dot1538 = _parent;
    sjt_functionParam430 = &(sjt_dot1538)->_projection;
    sjt_dot1539 = _parent;
    sjt_functionParam431 = &(sjt_dot1539)->_view;
    sjt_dot1540 = _parent;
    sjt_parent178 = &(sjt_dot1540)->_world;
    sjt_dot1541 = _parent;
    sjt_functionParam433 = &(sjt_dot1541)->model;
    sjf_mat4_multiply(sjt_parent178, sjt_functionParam433, &sjt_call70);
    sjt_functionParam432 = &sjt_call70;
    sjf_vertexbuffer_vertex_location_texture_normal_translatescreentotexture(sjt_parent177, sjt_functionParam428, sjt_functionParam429, sjt_functionParam430, sjt_functionParam431, sjt_functionParam432, &sjv_texture);
    sjt_isEmpty11 = (sjv_texture._refCount != -1 ? &sjv_texture : 0);
    sjt_isEmpty10 = (sjt_isEmpty11 == 0);
    if (!sjt_isEmpty10) {
        int32_t i;
        sjs_vec2* ifValue9;
        float sjt_cast38;
        int32_t sjt_cast39;
        float sjt_cast40;
        int32_t sjt_cast41;
        sjs_vec2* sjt_dot1542;
        sjs_size* sjt_dot1543;
        sjs_scene2dmodel* sjt_dot1544;
        sjs_size* sjt_dot1545;
        sjs_scene2dmodel* sjt_dot1546;
        sjs_vec2* sjt_dot1547;
        sjs_size* sjt_dot1548;
        sjs_scene2dmodel* sjt_dot1549;
        sjs_array_heap_element* sjt_dot1550;
        sjs_scene2dmodel* sjt_dot1551;
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
        sjt_dot1542 = ifValue9;
        sjt_math2395 = (sjt_dot1542)->x;
        sjt_dot1544 = _parent;
        sjt_dot1543 = &(sjt_dot1544)->texturesize;
        sjt_cast39 = (sjt_dot1543)->w;
        sjt_math2396 = (float)sjt_cast39;
        sjt_cast38 = sjt_math2395 * sjt_math2396;
        sjv_scenepoint.x = (int32_t)sjt_cast38;
        sjt_dot1546 = _parent;
        sjt_dot1545 = &(sjt_dot1546)->texturesize;
        sjt_math2399 = (sjt_dot1545)->h;
        sjt_math2400 = 1;
        sjt_math2397 = sjt_math2399 - sjt_math2400;
        sjt_dot1547 = ifValue9;
        sjt_math2401 = (sjt_dot1547)->y;
        sjt_dot1549 = _parent;
        sjt_dot1548 = &(sjt_dot1549)->texturesize;
        sjt_cast41 = (sjt_dot1548)->h;
        sjt_math2402 = (float)sjt_cast41;
        sjt_cast40 = sjt_math2401 * sjt_math2402;
        sjt_math2398 = (int32_t)sjt_cast40;
        sjv_scenepoint.y = sjt_math2397 - sjt_math2398;
        sjf_point(&sjv_scenepoint);
        sjt_forStart23 = 0;
        sjt_dot1551 = _parent;
        sjt_dot1550 = &(sjt_dot1551)->children;
        sjt_forEnd23 = (sjt_dot1550)->count;
        i = sjt_forStart23;
        while (i < sjt_forEnd23) {
            sjs_mouseevent sjt_call71 = { -1 };
            sjs_point* sjt_copy32;
            sjs_scene2dmodel* sjt_dot1552;
            sjs_mouseevent* sjt_dot1553;
            sjs_mouseevent* sjt_dot1554;
            int32_t sjt_functionParam434;
            sjs_mouseevent* sjt_interfaceParam27;
            sjs_array_heap_element* sjt_parent179;
            sji_element* sjt_parent180;
            sji_element* sjv_child = 0;

            sjt_dot1552 = _parent;
            sjt_parent179 = &(sjt_dot1552)->children;
            sjt_functionParam434 = i;
            sjf_array_heap_element_getat_heap(sjt_parent179, sjt_functionParam434, &sjv_child);
            sjt_parent180 = sjv_child;
            sjt_call71._refCount = 1;
            sjt_dot1553 = mouseevent;
            sjt_call71.type = (sjt_dot1553)->type;
            sjt_copy32 = &sjv_scenepoint;
            sjt_call71.point._refCount = 1;
            sjf_point_copy(&sjt_call71.point, sjt_copy32);
            sjt_dot1554 = mouseevent;
            sjt_call71.iscaptured = (sjt_dot1554)->iscaptured;
            sjf_mouseevent(&sjt_call71);
            sjt_interfaceParam27 = &sjt_call71;
            sjt_parent180->firemouseevent(sjt_parent180->_parent, sjt_interfaceParam27);
            i++;

            sjv_child->_refCount--;
            if (sjv_child->_refCount <= 0) {
                sji_element_destroy(sjv_child);
            }
            if (sjt_call71._refCount == 1) { sjf_mouseevent_destroy(&sjt_call71); }
        }

        if (sjv_scenepoint._refCount == 1) { sjf_point_destroy(&sjv_scenepoint); }
    }

    if (sjt_call70._refCount == 1) { sjf_mat4_destroy(&sjt_call70); }
    if (sjv_texture._refCount == 1) { sjf_vec2_destroy(&sjv_texture); }
}

void sjf_scene2dmodel_getz(sjs_scene2dmodel* _parent, float* _return) {
    sjs_vec4* sjt_dot1433;
    sjs_scene2dmodel* sjt_dot1434;

    sjt_dot1434 = _parent;
    sjt_dot1433 = &(sjt_dot1434)->_projectedcenter;
    (*_return) = (sjt_dot1433)->z;
}

void sjf_scene2dmodel_heap(sjs_scene2dmodel* _this) {
    int32_t i;
    sjs_string sjt_call72 = { -1 };
    int32_t sjt_compare95;
    int32_t sjt_compare96;
    sjs_size* sjt_dot1555;
    sjs_size* sjt_dot1556;
    sjs_array_heap_element* sjt_dot1557;
    int32_t sjt_forEnd24;
    int32_t sjt_forStart24;
    sjs_size* sjt_functionParam435;
    sjs_size* sjt_functionParam436;
    sjs_framebuffer* sjt_functionParam437;
    int32_t sjt_functionParam438;
    sjs_texture* sjt_functionParam439;
    int32_t sjt_functionParam440;
    int32_t sjt_functionParam441;
    int32_t sjt_functionParam442;
    int32_t sjt_functionParam443;
    int32_t sjt_functionParam444;
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
    sjs_size* sjt_functionParam455;
    int32_t sjt_functionParam456;
    void* sjt_functionParam457;
    int32_t sjt_functionParam458;
    int32_t sjt_functionParam459;
    sjs_texture* sjt_functionParam460;
    int32_t sjt_functionParam461;
    sjs_renderbuffer* sjt_functionParam462;
    int32_t sjt_functionParam463;
    sjs_size* sjt_functionParam464;
    int32_t sjt_functionParam465;
    sjs_renderbuffer* sjt_functionParam466;
    sjs_size* sjt_functionParam468;
    bool sjt_ifElse39;
    sjs_scene2d* sjt_parent181;
    sjs_rect sjv_rect = { -1 };
    int32_t sjv_status;

    sjt_functionParam435 = &_this->texturesize;
    sjf_glgentexture(sjt_functionParam435, &_this->_texture);
    sjt_functionParam436 = &_this->texturesize;
    sjf_glgenrenderbuffer(sjt_functionParam436, &_this->_renderbuffer);
    sjt_functionParam437 = &_this->_framebuffer;
    sjf_glbindframebuffer(sjt_functionParam437);
    sjt_functionParam438 = sjv_gltexture_gl_texture_2d;
    sjt_functionParam439 = &_this->_texture;
    sjf_glbindtexture(sjt_functionParam438, sjt_functionParam439);
    sjt_functionParam440 = sjv_gltexture_gl_texture_2d;
    sjt_functionParam441 = sjv_gltextureattribute_gl_texture_wrap_s;
    sjt_functionParam442 = sjv_gltexturevalue_gl_clamp_to_edge;
    sjf_gltexparameteri(sjt_functionParam440, sjt_functionParam441, sjt_functionParam442);
    sjt_functionParam443 = sjv_gltexture_gl_texture_2d;
    sjt_functionParam444 = sjv_gltextureattribute_gl_texture_wrap_t;
    sjt_functionParam445 = sjv_gltexturevalue_gl_clamp_to_edge;
    sjf_gltexparameteri(sjt_functionParam443, sjt_functionParam444, sjt_functionParam445);
    sjt_functionParam446 = sjv_gltexture_gl_texture_2d;
    sjt_functionParam447 = sjv_gltextureattribute_gl_texture_min_filter;
    sjt_functionParam448 = sjv_gltexturevalue_gl_nearest;
    sjf_gltexparameteri(sjt_functionParam446, sjt_functionParam447, sjt_functionParam448);
    sjt_functionParam449 = sjv_gltexture_gl_texture_2d;
    sjt_functionParam450 = sjv_gltextureattribute_gl_texture_mag_filter;
    sjt_functionParam451 = sjv_gltexturevalue_gl_nearest;
    sjf_gltexparameteri(sjt_functionParam449, sjt_functionParam450, sjt_functionParam451);
    sjt_functionParam452 = sjv_gltexture_gl_texture_2d;
    sjt_functionParam453 = 0;
    sjt_functionParam454 = sjv_gltextureformat_gl_rgba;
    sjt_functionParam455 = &_this->texturesize;
    sjt_functionParam456 = sjv_gltexturetype_gl_unsigned_byte;
    sjt_functionParam457 = 0;
    sjf_glteximage2d(sjt_functionParam452, sjt_functionParam453, sjt_functionParam454, sjt_functionParam455, sjt_functionParam456, sjt_functionParam457);
    sjt_functionParam458 = sjv_glframebufferattachment_gl_color_attachment0;
    sjt_functionParam459 = sjv_glframebuffertexture_gl_texture_2d;
    sjt_functionParam460 = &_this->_texture;
    sjt_functionParam461 = 0;
    sjf_glframebuffertexture2d(sjt_functionParam458, sjt_functionParam459, sjt_functionParam460, sjt_functionParam461);
    sjt_functionParam462 = &_this->_renderbuffer;
    sjf_glbindrenderbuffer(sjt_functionParam462);
    sjt_functionParam463 = sjv_glrenderbufferformat_gl_depth_component16;
    sjt_functionParam464 = &_this->texturesize;
    sjf_glrenderbufferstorage(sjt_functionParam463, sjt_functionParam464);
    sjt_functionParam465 = sjv_glframebufferattachment_gl_depth_attachment;
    sjt_functionParam466 = &_this->_renderbuffer;
    sjf_glframebufferrenderbuffer(sjt_functionParam465, sjt_functionParam466);
    sjf_glcheckframebufferstatus(&sjv_status);
    sjt_compare95 = sjv_status;
    sjt_compare96 = sjv_glframebufferstatus_gl_framebuffer_complete;
    sjt_ifElse39 = sjt_compare95 != sjt_compare96;
    if (sjt_ifElse39) {
        sjs_string* sjt_functionParam467;

        sjt_call72._refCount = 1;
        sjt_call72.count = 18;
        sjt_call72.data._refCount = 1;
        sjt_call72.data.datasize = 19;
        sjt_call72.data.data = (void*)sjg_string28;
        sjt_call72.data._isglobal = true;
        sjt_call72.data.count = 19;
        sjf_array_char(&sjt_call72.data);
        sjf_string(&sjt_call72);
        sjt_functionParam467 = &sjt_call72;
        sjf_halt(sjt_functionParam467);
    }

    sjt_parent181 = &_this->_innerscene;
    sjt_functionParam468 = &_this->texturesize;
    sjf_scene2d_setsize(sjt_parent181, sjt_functionParam468);
    sjv_rect._refCount = 1;
    sjv_rect.x = 0;
    sjv_rect.y = 0;
    sjt_dot1555 = &_this->texturesize;
    sjv_rect.w = (sjt_dot1555)->w;
    sjt_dot1556 = &_this->texturesize;
    sjv_rect.h = (sjt_dot1556)->h;
    sjf_rect(&sjv_rect);
    sjt_forStart24 = 0;
    sjt_dot1557 = &_this->children;
    sjt_forEnd24 = (sjt_dot1557)->count;
    i = sjt_forStart24;
    while (i < sjt_forEnd24) {
        int32_t sjt_functionParam469;
        sjs_rect* sjt_interfaceParam28;
        sjs_array_heap_element* sjt_parent182;
        sji_element* sjt_parent183;
        sji_element* sjv_child = 0;

        sjt_parent182 = &_this->children;
        sjt_functionParam469 = i;
        sjf_array_heap_element_getat_heap(sjt_parent182, sjt_functionParam469, &sjv_child);
        sjt_parent183 = sjv_child;
        sjt_interfaceParam28 = &sjv_rect;
        sjt_parent183->setrect(sjt_parent183->_parent, sjt_interfaceParam28);
        i++;

        sjv_child->_refCount--;
        if (sjv_child->_refCount <= 0) {
            sji_element_destroy(sjv_child);
        }
    }

    if (sjt_call72._refCount == 1) { sjf_string_destroy(&sjt_call72); }
    if (sjv_rect._refCount == 1) { sjf_rect_destroy(&sjv_rect); }
}

sjs_object* sjf_scene2dmodel_heap_asInterface(sjs_scene2dmodel* _this, int typeId) {
    switch (typeId) {
        case sji_model_typeId:  {
            return (sjs_object*)sjf_scene2dmodel_heap_as_sji_model(_this);
        }
    }

    return 0;
}

sji_model* sjf_scene2dmodel_heap_as_sji_model(sjs_scene2dmodel* _this) {
    sji_model* _interface;
    _interface = (sji_model*)malloc(sizeof(sji_model));
    _interface->_refCount = 1;
    _interface->_parent = (sjs_object*)_this;
    _interface->_parent->_refCount++;
    _interface->destroy = (void(*)(void*))sjf_scene2dmodel_destroy;
    _interface->asInterface = (sjs_object*(*)(sjs_object*,int))sjf_scene2dmodel_heap_asInterface;
    _interface->update = (void(*)(void*,sjs_rect*,sjs_mat4*,sjs_mat4*,sjs_mat4*,sjs_light*))sjf_scene2dmodel_update;
    _interface->getz = (void(*)(void*, float*))sjf_scene2dmodel_getz;
    _interface->renderorqueue = (void(*)(void*,sjs_list_heap_model*))sjf_scene2dmodel_renderorqueue;
    _interface->render = (void(*)(void*))sjf_scene2dmodel_render;
    _interface->firemouseevent = (void(*)(void*,sjs_mouseevent*))sjf_scene2dmodel_firemouseevent;

    return _interface;
}

void sjf_scene2dmodel_render(sjs_scene2dmodel* _parent) {
    int32_t i;
    sjs_mat4 sjt_call59 = { -1 };
    sjs_mat4 sjt_call60 = { -1 };
    sjs_string sjt_call61 = { -1 };
    sjs_string sjt_call62 = { -1 };
    sjs_string sjt_call63 = { -1 };
    sjs_string sjt_call64 = { -1 };
    sjs_string sjt_call65 = { -1 };
    sjs_vec3 sjt_call66 = { -1 };
    sjs_string sjt_call67 = { -1 };
    sjs_vec3 sjt_call68 = { -1 };
    sjs_scene2dmodel* sjt_dot1436;
    sjs_scene2dmodel* sjt_dot1437;
    sjs_array_heap_element* sjt_dot1438;
    sjs_scene2dmodel* sjt_dot1439;
    sjs_scene2dmodel* sjt_dot1442;
    sjs_scene2dmodel* sjt_dot1443;
    sjs_scene2dmodel* sjt_dot1444;
    sjs_scene2dmodel* sjt_dot1445;
    sjs_scene2dmodel* sjt_dot1446;
    sjs_scene2dmodel* sjt_dot1447;
    sjs_scene2dmodel* sjt_dot1448;
    sjs_scene2dmodel* sjt_dot1449;
    sjs_scene2dmodel* sjt_dot1450;
    sjs_scene2dmodel* sjt_dot1451;
    sjs_scene2dmodel* sjt_dot1452;
    sjs_light* sjt_dot1453;
    sjs_scene2dmodel* sjt_dot1454;
    sjs_scene2dmodel* sjt_dot1455;
    sjs_light* sjt_dot1456;
    sjs_scene2dmodel* sjt_dot1457;
    sjs_scene2dmodel* sjt_dot1458;
    sjs_light* sjt_dot1459;
    sjs_scene2dmodel* sjt_dot1460;
    sjs_scene2dmodel* sjt_dot1461;
    int32_t sjt_forEnd21;
    int32_t sjt_forStart21;
    sjs_framebuffer* sjt_functionParam356;
    sjs_rect* sjt_functionParam358;
    int32_t sjt_functionParam359;
    sjs_mat4* sjt_functionParam360;
    sjs_mat4* sjt_functionParam361;
    sjs_shader* sjt_functionParam362;
    int32_t sjt_functionParam363;
    sjs_texture* sjt_functionParam364;
    int32_t sjt_functionParam365;
    sjs_shader* sjt_functionParam366;
    sjs_string* sjt_functionParam367;
    sjs_mat4* sjt_functionParam368;
    int32_t sjt_functionParam369;
    sjs_shader* sjt_functionParam370;
    sjs_string* sjt_functionParam371;
    sjs_mat4* sjt_functionParam372;
    int32_t sjt_functionParam373;
    sjs_shader* sjt_functionParam374;
    sjs_string* sjt_functionParam375;
    sjs_mat4* sjt_functionParam376;
    int32_t sjt_functionParam377;
    sjs_shader* sjt_functionParam378;
    sjs_string* sjt_functionParam379;
    sjs_vec3* sjt_functionParam380;
    int32_t sjt_functionParam381;
    sjs_shader* sjt_functionParam382;
    sjs_string* sjt_functionParam383;
    sjs_vec3* sjt_functionParam384;
    int32_t sjt_functionParam385;
    sjs_shader* sjt_functionParam386;
    sjs_string* sjt_functionParam387;
    sjs_vec3* sjt_functionParam388;
    sjs_scene2d* sjt_parent131;
    sjs_mat4* sjt_parent134;
    sjs_mat4* sjt_parent135;
    sjs_mat4* sjt_parent136;
    sjs_mat4* sjt_parent137;
    sjs_color* sjt_parent138;
    sjs_color* sjt_parent139;
    sjs_vertexbuffer_vertex_location_texture_normal* sjt_parent140;
    sjs_mat4 sjv_normalmat = { -1 };
    sjs_mat4 sjv_viewworld = { -1 };

    sjt_dot1436 = _parent;
    sjt_functionParam356 = &(sjt_dot1436)->_framebuffer;
    sjf_glbindframebuffer(sjt_functionParam356);
    sjt_dot1437 = _parent;
    sjt_parent131 = &(sjt_dot1437)->_innerscene;
    sjf_scene2d_clear(sjt_parent131);
    sjt_forStart21 = 0;
    sjt_dot1439 = _parent;
    sjt_dot1438 = &(sjt_dot1439)->children;
    sjt_forEnd21 = (sjt_dot1438)->count;
    i = sjt_forStart21;
    while (i < sjt_forEnd21) {
        sjs_scene2dmodel* sjt_dot1440;
        sjs_scene2dmodel* sjt_dot1441;
        int32_t sjt_functionParam357;
        sjs_scene2d* sjt_interfaceParam26;
        sjs_array_heap_element* sjt_parent132;
        sji_element* sjt_parent133;
        sji_element* sjv_child = 0;

        sjt_dot1440 = _parent;
        sjt_parent132 = &(sjt_dot1440)->children;
        sjt_functionParam357 = i;
        sjf_array_heap_element_getat_heap(sjt_parent132, sjt_functionParam357, &sjv_child);
        sjt_parent133 = sjv_child;
        sjt_dot1441 = _parent;
        sjt_interfaceParam26 = &(sjt_dot1441)->_innerscene;
        sjt_parent133->render(sjt_parent133->_parent, sjt_interfaceParam26);
        i++;

        sjv_child->_refCount--;
        if (sjv_child->_refCount <= 0) {
            sji_element_destroy(sjv_child);
        }
    }

    sjf_glunbindframebuffer();
    sjt_dot1442 = _parent;
    sjt_functionParam358 = &(sjt_dot1442)->_scenerect;
    sjf_glviewport(sjt_functionParam358);
    sjt_functionParam359 = sjv_glfeature_gl_depth_test;
    sjf_glenable(sjt_functionParam359);
    sjt_dot1443 = _parent;
    sjt_parent135 = &(sjt_dot1443)->_view;
    sjt_dot1444 = _parent;
    sjt_functionParam360 = &(sjt_dot1444)->_world;
    sjf_mat4_multiply(sjt_parent135, sjt_functionParam360, &sjt_call59);
    sjt_parent134 = &sjt_call59;
    sjt_dot1445 = _parent;
    sjt_functionParam361 = &(sjt_dot1445)->model;
    sjf_mat4_multiply(sjt_parent134, sjt_functionParam361, &sjv_viewworld);
    sjt_parent137 = &sjv_viewworld;
    sjf_mat4_invert(sjt_parent137, &sjt_call60);
    sjt_parent136 = &sjt_call60;
    sjf_mat4_transpose(sjt_parent136, &sjv_normalmat);
    sjt_dot1446 = _parent;
    sjt_functionParam362 = &(sjt_dot1446)->shader;
    sjf_gluseprogram(sjt_functionParam362);
    sjt_functionParam363 = sjv_gltexture_gl_texture_2d;
    sjt_dot1447 = _parent;
    sjt_functionParam364 = &(sjt_dot1447)->_texture;
    sjf_glbindtexture(sjt_functionParam363, sjt_functionParam364);
    sjt_dot1448 = _parent;
    sjt_functionParam366 = &(sjt_dot1448)->shader;
    sjt_call61._refCount = 1;
    sjt_call61.count = 9;
    sjt_call61.data._refCount = 1;
    sjt_call61.data.datasize = 10;
    sjt_call61.data.data = (void*)sjg_string113;
    sjt_call61.data._isglobal = true;
    sjt_call61.data.count = 10;
    sjf_array_char(&sjt_call61.data);
    sjf_string(&sjt_call61);
    sjt_functionParam367 = &sjt_call61;
    sjf_glgetuniformlocation(sjt_functionParam366, sjt_functionParam367, &sjt_functionParam365);
    sjt_functionParam368 = &sjv_viewworld;
    sjf_gluniformmat4(sjt_functionParam365, sjt_functionParam368);
    sjt_dot1449 = _parent;
    sjt_functionParam370 = &(sjt_dot1449)->shader;
    sjt_call62._refCount = 1;
    sjt_call62.count = 9;
    sjt_call62.data._refCount = 1;
    sjt_call62.data.datasize = 10;
    sjt_call62.data.data = (void*)sjg_string114;
    sjt_call62.data._isglobal = true;
    sjt_call62.data.count = 10;
    sjf_array_char(&sjt_call62.data);
    sjf_string(&sjt_call62);
    sjt_functionParam371 = &sjt_call62;
    sjf_glgetuniformlocation(sjt_functionParam370, sjt_functionParam371, &sjt_functionParam369);
    sjt_functionParam372 = &sjv_normalmat;
    sjf_gluniformmat4(sjt_functionParam369, sjt_functionParam372);
    sjt_dot1450 = _parent;
    sjt_functionParam374 = &(sjt_dot1450)->shader;
    sjt_call63._refCount = 1;
    sjt_call63.count = 10;
    sjt_call63.data._refCount = 1;
    sjt_call63.data.datasize = 11;
    sjt_call63.data.data = (void*)sjg_string115;
    sjt_call63.data._isglobal = true;
    sjt_call63.data.count = 11;
    sjf_array_char(&sjt_call63.data);
    sjf_string(&sjt_call63);
    sjt_functionParam375 = &sjt_call63;
    sjf_glgetuniformlocation(sjt_functionParam374, sjt_functionParam375, &sjt_functionParam373);
    sjt_dot1451 = _parent;
    sjt_functionParam376 = &(sjt_dot1451)->_projection;
    sjf_gluniformmat4(sjt_functionParam373, sjt_functionParam376);
    sjt_dot1452 = _parent;
    sjt_functionParam378 = &(sjt_dot1452)->shader;
    sjt_call64._refCount = 1;
    sjt_call64.count = 8;
    sjt_call64.data._refCount = 1;
    sjt_call64.data.datasize = 9;
    sjt_call64.data.data = (void*)sjg_string116;
    sjt_call64.data._isglobal = true;
    sjt_call64.data.count = 9;
    sjf_array_char(&sjt_call64.data);
    sjf_string(&sjt_call64);
    sjt_functionParam379 = &sjt_call64;
    sjf_glgetuniformlocation(sjt_functionParam378, sjt_functionParam379, &sjt_functionParam377);
    sjt_dot1454 = _parent;
    sjt_dot1453 = &(sjt_dot1454)->_light;
    sjt_functionParam380 = &(sjt_dot1453)->pos;
    sjf_gluniformvec3(sjt_functionParam377, sjt_functionParam380);
    sjt_dot1455 = _parent;
    sjt_functionParam382 = &(sjt_dot1455)->shader;
    sjt_call65._refCount = 1;
    sjt_call65.count = 12;
    sjt_call65.data._refCount = 1;
    sjt_call65.data.datasize = 13;
    sjt_call65.data.data = (void*)sjg_string117;
    sjt_call65.data._isglobal = true;
    sjt_call65.data.count = 13;
    sjf_array_char(&sjt_call65.data);
    sjf_string(&sjt_call65);
    sjt_functionParam383 = &sjt_call65;
    sjf_glgetuniformlocation(sjt_functionParam382, sjt_functionParam383, &sjt_functionParam381);
    sjt_dot1457 = _parent;
    sjt_dot1456 = &(sjt_dot1457)->_light;
    sjt_parent138 = &(sjt_dot1456)->diffusecolor;
    sjf_color_asvec3(sjt_parent138, &sjt_call66);
    sjt_functionParam384 = &sjt_call66;
    sjf_gluniformvec3(sjt_functionParam381, sjt_functionParam384);
    sjt_dot1458 = _parent;
    sjt_functionParam386 = &(sjt_dot1458)->shader;
    sjt_call67._refCount = 1;
    sjt_call67.count = 9;
    sjt_call67.data._refCount = 1;
    sjt_call67.data.datasize = 10;
    sjt_call67.data.data = (void*)sjg_string118;
    sjt_call67.data._isglobal = true;
    sjt_call67.data.count = 10;
    sjf_array_char(&sjt_call67.data);
    sjf_string(&sjt_call67);
    sjt_functionParam387 = &sjt_call67;
    sjf_glgetuniformlocation(sjt_functionParam386, sjt_functionParam387, &sjt_functionParam385);
    sjt_dot1460 = _parent;
    sjt_dot1459 = &(sjt_dot1460)->_light;
    sjt_parent139 = &(sjt_dot1459)->speccolor;
    sjf_color_asvec3(sjt_parent139, &sjt_call68);
    sjt_functionParam388 = &sjt_call68;
    sjf_gluniformvec3(sjt_functionParam385, sjt_functionParam388);
    sjt_dot1461 = _parent;
    sjt_parent140 = &(sjt_dot1461)->vertexbuffer;
    sjf_vertexbuffer_vertex_location_texture_normal_render(sjt_parent140);

    if (sjt_call59._refCount == 1) { sjf_mat4_destroy(&sjt_call59); }
    if (sjt_call60._refCount == 1) { sjf_mat4_destroy(&sjt_call60); }
    if (sjt_call61._refCount == 1) { sjf_string_destroy(&sjt_call61); }
    if (sjt_call62._refCount == 1) { sjf_string_destroy(&sjt_call62); }
    if (sjt_call63._refCount == 1) { sjf_string_destroy(&sjt_call63); }
    if (sjt_call64._refCount == 1) { sjf_string_destroy(&sjt_call64); }
    if (sjt_call65._refCount == 1) { sjf_string_destroy(&sjt_call65); }
    if (sjt_call66._refCount == 1) { sjf_vec3_destroy(&sjt_call66); }
    if (sjt_call67._refCount == 1) { sjf_string_destroy(&sjt_call67); }
    if (sjt_call68._refCount == 1) { sjf_vec3_destroy(&sjt_call68); }
    if (sjv_normalmat._refCount == 1) { sjf_mat4_destroy(&sjv_normalmat); }
    if (sjv_viewworld._refCount == 1) { sjf_mat4_destroy(&sjv_viewworld); }
}

void sjf_scene2dmodel_renderorqueue(sjs_scene2dmodel* _parent, sjs_list_heap_model* alphamodels) {
    sjs_scene2dmodel* sjt_dot1435;
    bool sjt_ifElse21;

    sjt_dot1435 = _parent;
    sjt_ifElse21 = (sjt_dot1435)->hasalpha;
    if (sjt_ifElse21) {
        sjs_scene2dmodel* sjt_cast33 = 0;
        sji_model* sjt_functionParam355 = 0;
        sjs_list_heap_model* sjt_parent130;

        sjt_parent130 = alphamodels;
        sjt_cast33 = _parent;
        sjt_cast33->_refCount++;
        sjt_functionParam355 = (sji_model*)sjf_scene2dmodel_heap_as_sji_model(sjt_cast33);
        sjf_list_heap_model_add(sjt_parent130, sjt_functionParam355);

        sjt_cast33->_refCount--;
        if (sjt_cast33->_refCount <= 0) {
            sjf_scene2dmodel_destroy(sjt_cast33);
        }
        sjt_functionParam355->_refCount--;
        if (sjt_functionParam355->_refCount <= 0) {
            sji_model_destroy(sjt_functionParam355);
        }
    } else {
        sjf_scene2dmodel_render(_parent);
    }
}

void sjf_scene2dmodel_update(sjs_scene2dmodel* _parent, sjs_rect* scenerect, sjs_mat4* projection, sjs_mat4* view, sjs_mat4* world, sjs_light* light) {
    sjs_mat4 sjt_call55 = { -1 };
    sjs_mat4 sjt_call56 = { -1 };
    sjs_mat4 sjt_call57 = { -1 };
    sjs_vec4 sjt_call58 = { -1 };
    sjs_rect* sjt_copy23;
    sjs_mat4* sjt_copy24;
    sjs_mat4* sjt_copy25;
    sjs_mat4* sjt_copy26;
    sjs_light* sjt_copy27;
    sjs_scene2dmodel* sjt_dot1417;
    sjs_scene2dmodel* sjt_dot1418;
    sjs_scene2dmodel* sjt_dot1419;
    sjs_scene2dmodel* sjt_dot1420;
    sjs_scene2dmodel* sjt_dot1421;
    sjs_scene2dmodel* sjt_dot1422;
    sjs_scene2dmodel* sjt_dot1423;
    sjs_scene2dmodel* sjt_dot1424;
    sjs_scene2dmodel* sjt_dot1425;
    sjs_scene2dmodel* sjt_dot1426;
    sjs_vec3* sjt_dot1427;
    sjs_scene2dmodel* sjt_dot1428;
    sjs_vec3* sjt_dot1429;
    sjs_scene2dmodel* sjt_dot1430;
    sjs_vec3* sjt_dot1431;
    sjs_scene2dmodel* sjt_dot1432;
    sjs_mat4* sjt_functionParam351;
    sjs_mat4* sjt_functionParam352;
    sjs_mat4* sjt_functionParam353;
    sjs_vec4* sjt_functionParam354;
    sjs_mat4* sjt_parent126;
    sjs_mat4* sjt_parent127;
    sjs_mat4* sjt_parent128;
    sjs_mat4* sjt_parent129;

    sjt_dot1417 = _parent;
    sjt_copy23 = scenerect;
    sjf_rect_copy(&sjt_dot1417->_scenerect, sjt_copy23);
    sjt_dot1418 = _parent;
    sjt_copy24 = projection;
    sjf_mat4_copy(&sjt_dot1418->_projection, sjt_copy24);
    sjt_dot1419 = _parent;
    sjt_copy25 = view;
    sjf_mat4_copy(&sjt_dot1419->_view, sjt_copy25);
    sjt_dot1420 = _parent;
    sjt_copy26 = world;
    sjf_mat4_copy(&sjt_dot1420->_world, sjt_copy26);
    sjt_dot1421 = _parent;
    sjt_copy27 = light;
    sjf_light_copy(&sjt_dot1421->_light, sjt_copy27);
    sjt_dot1422 = _parent;
    sjt_dot1423 = _parent;
    sjt_parent129 = &(sjt_dot1423)->_projection;
    sjt_dot1424 = _parent;
    sjt_functionParam351 = &(sjt_dot1424)->_view;
    sjf_mat4_multiply(sjt_parent129, sjt_functionParam351, &sjt_call57);
    sjt_parent128 = &sjt_call57;
    sjt_dot1425 = _parent;
    sjt_functionParam352 = &(sjt_dot1425)->_world;
    sjf_mat4_multiply(sjt_parent128, sjt_functionParam352, &sjt_call56);
    sjt_parent127 = &sjt_call56;
    sjt_dot1426 = _parent;
    sjt_functionParam353 = &(sjt_dot1426)->model;
    sjf_mat4_multiply(sjt_parent127, sjt_functionParam353, &sjt_call55);
    sjt_parent126 = &sjt_call55;
    sjt_call58._refCount = 1;
    sjt_dot1428 = _parent;
    sjt_dot1427 = &(sjt_dot1428)->center;
    sjt_call58.x = (sjt_dot1427)->x;
    sjt_dot1430 = _parent;
    sjt_dot1429 = &(sjt_dot1430)->center;
    sjt_call58.y = (sjt_dot1429)->y;
    sjt_dot1432 = _parent;
    sjt_dot1431 = &(sjt_dot1432)->center;
    sjt_call58.z = (sjt_dot1431)->z;
    sjt_call58.w = 1.0f;
    sjf_vec4(&sjt_call58);
    sjt_functionParam354 = &sjt_call58;
    sjf_mat4_multiplyvec4(sjt_parent126, sjt_functionParam354, &sjt_dot1422->_projectedcenter);

    if (sjt_call55._refCount == 1) { sjf_mat4_destroy(&sjt_call55); }
    if (sjt_call56._refCount == 1) { sjf_mat4_destroy(&sjt_call56); }
    if (sjt_call57._refCount == 1) { sjf_mat4_destroy(&sjt_call57); }
    if (sjt_call58._refCount == 1) { sjf_vec4_destroy(&sjt_call58); }
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
    int32_t sjt_compare100;
    int32_t sjt_compare97;
    int32_t sjt_compare98;
    int32_t sjt_compare99;
    sjs_size* sjt_dot1558;
    sjs_size* sjt_dot1559;
    sjs_size* sjt_dot1562;
    sjs_size* sjt_dot1563;
    bool sjt_ifElse40;
    bool sjt_ifElse41;

    _return->_refCount = 1;
    sjt_dot1558 = _parent;
    sjt_compare97 = (sjt_dot1558)->w;
    sjt_dot1559 = maxsize;
    sjt_compare98 = (sjt_dot1559)->w;
    sjt_ifElse40 = sjt_compare97 < sjt_compare98;
    if (sjt_ifElse40) {
        sjs_size* sjt_dot1560;

        sjt_dot1560 = _parent;
        _return->w = (sjt_dot1560)->w;
    } else {
        sjs_size* sjt_dot1561;

        sjt_dot1561 = maxsize;
        _return->w = (sjt_dot1561)->w;
    }

    sjt_dot1562 = _parent;
    sjt_compare99 = (sjt_dot1562)->h;
    sjt_dot1563 = maxsize;
    sjt_compare100 = (sjt_dot1563)->h;
    sjt_ifElse41 = sjt_compare99 < sjt_compare100;
    if (sjt_ifElse41) {
        sjs_size* sjt_dot1564;

        sjt_dot1564 = _parent;
        _return->h = (sjt_dot1564)->h;
    } else {
        sjs_size* sjt_dot1565;

        sjt_dot1565 = maxsize;
        _return->h = (sjt_dot1565)->h;
    }

    sjf_size(_return);
}

void sjf_size_cap_heap(sjs_size* _parent, sjs_size* maxsize, sjs_size** _return) {
    int32_t sjt_compare101;
    int32_t sjt_compare102;
    int32_t sjt_compare103;
    int32_t sjt_compare104;
    sjs_size* sjt_dot1566;
    sjs_size* sjt_dot1567;
    sjs_size* sjt_dot1570;
    sjs_size* sjt_dot1571;
    bool sjt_ifElse42;
    bool sjt_ifElse43;

    (*_return) = (sjs_size*)malloc(sizeof(sjs_size));
    (*_return)->_refCount = 1;
    sjt_dot1566 = _parent;
    sjt_compare101 = (sjt_dot1566)->w;
    sjt_dot1567 = maxsize;
    sjt_compare102 = (sjt_dot1567)->w;
    sjt_ifElse42 = sjt_compare101 < sjt_compare102;
    if (sjt_ifElse42) {
        sjs_size* sjt_dot1568;

        sjt_dot1568 = _parent;
        (*_return)->w = (sjt_dot1568)->w;
    } else {
        sjs_size* sjt_dot1569;

        sjt_dot1569 = maxsize;
        (*_return)->w = (sjt_dot1569)->w;
    }

    sjt_dot1570 = _parent;
    sjt_compare103 = (sjt_dot1570)->h;
    sjt_dot1571 = maxsize;
    sjt_compare104 = (sjt_dot1571)->h;
    sjt_ifElse43 = sjt_compare103 < sjt_compare104;
    if (sjt_ifElse43) {
        sjs_size* sjt_dot1572;

        sjt_dot1572 = _parent;
        (*_return)->h = (sjt_dot1572)->h;
    } else {
        sjs_size* sjt_dot1573;

        sjt_dot1573 = maxsize;
        (*_return)->h = (sjt_dot1573)->h;
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
    int32_t sjt_compare57;
    int32_t sjt_compare58;
    int32_t sjt_compare59;
    int32_t sjt_compare60;
    sjs_size* sjt_dot1401;
    sjs_size* sjt_dot1402;
    sjs_size* sjt_dot1403;
    sjs_size* sjt_dot1404;

    sjt_dot1401 = _parent;
    sjt_compare57 = (sjt_dot1401)->w;
    sjt_dot1402 = size;
    sjt_compare58 = (sjt_dot1402)->w;
    sjt_and7 = sjt_compare57 == sjt_compare58;
    sjt_dot1403 = _parent;
    sjt_compare59 = (sjt_dot1403)->h;
    sjt_dot1404 = size;
    sjt_compare60 = (sjt_dot1404)->h;
    sjt_and8 = sjt_compare59 == sjt_compare60;
    (*_return) = sjt_and7 && sjt_and8;
}

void sjf_string(sjs_string* _this) {
}

void sjf_string_add(sjs_string* _parent, sjs_string* item, sjs_string* _return) {
    int32_t sjt_compare47;
    int32_t sjt_compare48;
    sjs_string* sjt_dot1333;
    bool sjt_ifElse15;
    sjs_array_char sjv_newdata = { -1 };

    sjt_dot1333 = item;
    sjt_compare47 = (sjt_dot1333)->count;
    sjt_compare48 = 0;
    sjt_ifElse15 = sjt_compare47 == sjt_compare48;
    if (sjt_ifElse15) {
        sjs_array_char* sjt_copy14;
        sjs_string* sjt_dot1334;
        sjs_string* sjt_dot1335;

        _return->_refCount = 1;
        sjt_dot1334 = _parent;
        _return->count = (sjt_dot1334)->count;
        sjt_dot1335 = _parent;
        sjt_copy14 = &(sjt_dot1335)->data;
        _return->data._refCount = 1;
        sjf_array_char_copy(&_return->data, sjt_copy14);
        sjf_string(_return);
    } else {
        int32_t i;
        int32_t sjt_cast16;
        sjs_array_char* sjt_copy15;
        sjs_string* sjt_dot1338;
        sjs_string* sjt_dot1339;
        sjs_string* sjt_dot1340;
        sjs_string* sjt_dot1341;
        sjs_string* sjt_dot1343;
        int32_t sjt_forEnd10;
        int32_t sjt_forStart10;
        int32_t sjt_functionParam228;
        int32_t sjt_functionParam229;
        char sjt_functionParam230;
        int32_t sjt_functionParam232;
        int32_t sjt_functionParam236;
        char sjt_functionParam237;
        int32_t sjt_math2125;
        int32_t sjt_math2126;
        int32_t sjt_math2127;
        int32_t sjt_math2128;
        int32_t sjt_math2129;
        int32_t sjt_math2130;
        sjs_array_char* sjt_parent80;
        sjs_array_char* sjt_parent81;
        sjs_string* sjt_parent83;
        sjs_array_char* sjt_parent86;
        int32_t sjv_newcount;

        sjt_dot1338 = _parent;
        sjt_parent80 = &(sjt_dot1338)->data;
        sjt_dot1339 = _parent;
        sjt_math2127 = (sjt_dot1339)->count;
        sjt_dot1340 = item;
        sjt_math2128 = (sjt_dot1340)->count;
        sjt_math2125 = sjt_math2127 + sjt_math2128;
        sjt_math2126 = 1;
        sjt_functionParam228 = sjt_math2125 + sjt_math2126;
        sjf_array_char_grow(sjt_parent80, sjt_functionParam228, &sjv_newdata);
        sjt_dot1341 = _parent;
        sjv_newcount = (sjt_dot1341)->count;
        sjt_parent81 = &sjv_newdata;
        sjt_functionParam229 = sjv_newcount;
        sjt_parent83 = item;
        sjt_functionParam232 = 0;
        sjf_string_getat(sjt_parent83, sjt_functionParam232, &sjt_functionParam230);
        sjf_array_char_setat(sjt_parent81, sjt_functionParam229, sjt_functionParam230);
        sjt_math2129 = sjv_newcount;
        sjt_math2130 = 1;
        sjv_newcount = sjt_math2129 + sjt_math2130;
        sjt_forStart10 = 1;
        sjt_dot1343 = item;
        sjt_forEnd10 = (sjt_dot1343)->count;
        i = sjt_forStart10;
        while (i < sjt_forEnd10) {
            int32_t sjt_functionParam233;
            char sjt_functionParam234;
            int32_t sjt_functionParam235;
            int32_t sjt_math2131;
            int32_t sjt_math2132;
            sjs_array_char* sjt_parent84;
            sjs_string* sjt_parent85;

            sjt_parent84 = &sjv_newdata;
            sjt_functionParam233 = sjv_newcount;
            sjt_parent85 = item;
            sjt_functionParam235 = i;
            sjf_string_getat(sjt_parent85, sjt_functionParam235, &sjt_functionParam234);
            sjf_array_char_initat(sjt_parent84, sjt_functionParam233, sjt_functionParam234);
            sjt_math2131 = sjv_newcount;
            sjt_math2132 = 1;
            sjv_newcount = sjt_math2131 + sjt_math2132;
            i++;
        }

        sjt_parent86 = &sjv_newdata;
        sjt_functionParam236 = sjv_newcount;
        sjt_cast16 = 0;
        sjt_functionParam237 = (char)sjt_cast16;
        sjf_array_char_initat(sjt_parent86, sjt_functionParam236, sjt_functionParam237);
        _return->_refCount = 1;
        _return->count = sjv_newcount;
        sjt_copy15 = &sjv_newdata;
        _return->data._refCount = 1;
        sjf_array_char_copy(&_return->data, sjt_copy15);
        sjf_string(_return);
    }

    if (sjv_newdata._refCount == 1) { sjf_array_char_destroy(&sjv_newdata); }
}

void sjf_string_add_heap(sjs_string* _parent, sjs_string* item, sjs_string** _return) {
    int32_t sjt_compare49;
    int32_t sjt_compare50;
    sjs_string* sjt_dot1344;
    bool sjt_ifElse16;
    sjs_array_char sjv_newdata = { -1 };

    sjt_dot1344 = item;
    sjt_compare49 = (sjt_dot1344)->count;
    sjt_compare50 = 0;
    sjt_ifElse16 = sjt_compare49 == sjt_compare50;
    if (sjt_ifElse16) {
        sjs_array_char* sjt_copy16;
        sjs_string* sjt_dot1345;
        sjs_string* sjt_dot1346;

        (*_return) = (sjs_string*)malloc(sizeof(sjs_string));
        (*_return)->_refCount = 1;
        sjt_dot1345 = _parent;
        (*_return)->count = (sjt_dot1345)->count;
        sjt_dot1346 = _parent;
        sjt_copy16 = &(sjt_dot1346)->data;
        (*_return)->data._refCount = 1;
        sjf_array_char_copy(&(*_return)->data, sjt_copy16);
        sjf_string_heap((*_return));
    } else {
        int32_t i;
        int32_t sjt_cast17;
        sjs_array_char* sjt_copy17;
        sjs_string* sjt_dot1347;
        sjs_string* sjt_dot1348;
        sjs_string* sjt_dot1349;
        sjs_string* sjt_dot1350;
        sjs_string* sjt_dot1351;
        int32_t sjt_forEnd11;
        int32_t sjt_forStart11;
        int32_t sjt_functionParam238;
        int32_t sjt_functionParam239;
        char sjt_functionParam240;
        int32_t sjt_functionParam241;
        int32_t sjt_functionParam245;
        char sjt_functionParam246;
        int32_t sjt_math2133;
        int32_t sjt_math2134;
        int32_t sjt_math2135;
        int32_t sjt_math2136;
        int32_t sjt_math2137;
        int32_t sjt_math2138;
        sjs_array_char* sjt_parent87;
        sjs_array_char* sjt_parent88;
        sjs_string* sjt_parent89;
        sjs_array_char* sjt_parent92;
        int32_t sjv_newcount;

        sjt_dot1347 = _parent;
        sjt_parent87 = &(sjt_dot1347)->data;
        sjt_dot1348 = _parent;
        sjt_math2135 = (sjt_dot1348)->count;
        sjt_dot1349 = item;
        sjt_math2136 = (sjt_dot1349)->count;
        sjt_math2133 = sjt_math2135 + sjt_math2136;
        sjt_math2134 = 1;
        sjt_functionParam238 = sjt_math2133 + sjt_math2134;
        sjf_array_char_grow(sjt_parent87, sjt_functionParam238, &sjv_newdata);
        sjt_dot1350 = _parent;
        sjv_newcount = (sjt_dot1350)->count;
        sjt_parent88 = &sjv_newdata;
        sjt_functionParam239 = sjv_newcount;
        sjt_parent89 = item;
        sjt_functionParam241 = 0;
        sjf_string_getat(sjt_parent89, sjt_functionParam241, &sjt_functionParam240);
        sjf_array_char_setat(sjt_parent88, sjt_functionParam239, sjt_functionParam240);
        sjt_math2137 = sjv_newcount;
        sjt_math2138 = 1;
        sjv_newcount = sjt_math2137 + sjt_math2138;
        sjt_forStart11 = 1;
        sjt_dot1351 = item;
        sjt_forEnd11 = (sjt_dot1351)->count;
        i = sjt_forStart11;
        while (i < sjt_forEnd11) {
            int32_t sjt_functionParam242;
            char sjt_functionParam243;
            int32_t sjt_functionParam244;
            int32_t sjt_math2139;
            int32_t sjt_math2140;
            sjs_array_char* sjt_parent90;
            sjs_string* sjt_parent91;

            sjt_parent90 = &sjv_newdata;
            sjt_functionParam242 = sjv_newcount;
            sjt_parent91 = item;
            sjt_functionParam244 = i;
            sjf_string_getat(sjt_parent91, sjt_functionParam244, &sjt_functionParam243);
            sjf_array_char_initat(sjt_parent90, sjt_functionParam242, sjt_functionParam243);
            sjt_math2139 = sjv_newcount;
            sjt_math2140 = 1;
            sjv_newcount = sjt_math2139 + sjt_math2140;
            i++;
        }

        sjt_parent92 = &sjv_newdata;
        sjt_functionParam245 = sjv_newcount;
        sjt_cast17 = 0;
        sjt_functionParam246 = (char)sjt_cast17;
        sjf_array_char_initat(sjt_parent92, sjt_functionParam245, sjt_functionParam246);
        (*_return) = (sjs_string*)malloc(sizeof(sjs_string));
        (*_return)->_refCount = 1;
        (*_return)->count = sjv_newcount;
        sjt_copy17 = &sjv_newdata;
        (*_return)->data._refCount = 1;
        sjf_array_char_copy(&(*_return)->data, sjt_copy17);
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
    sjs_string* sjt_dot1342;
    int32_t sjt_functionParam231;
    sjs_array_char* sjt_parent82;

    sjt_dot1342 = _parent;
    sjt_parent82 = &(sjt_dot1342)->data;
    sjt_functionParam231 = index;
    sjf_array_char_getat(sjt_parent82, sjt_functionParam231, _return);
}

void sjf_string_heap(sjs_string* _this) {
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
    sjs_size* sjt_dot1623;
    sjs_texture* sjt_dot1624;
    sjs_size* sjt_dot1625;
    sjs_texture* sjt_dot1626;

    _return->_refCount = 1;
    sjt_dot1624 = _parent;
    sjt_dot1623 = &(sjt_dot1624)->size;
    _return->w = (sjt_dot1623)->w;
    sjt_dot1626 = _parent;
    sjt_dot1625 = &(sjt_dot1626)->size;
    _return->h = (sjt_dot1625)->h;
    sjf_size(_return);
}

void sjf_texture_getsize_heap(sjs_texture* _parent, sjs_size** _return) {
    sjs_size* sjt_dot1627;
    sjs_texture* sjt_dot1628;
    sjs_size* sjt_dot1629;
    sjs_texture* sjt_dot1630;

    (*_return) = (sjs_size*)malloc(sizeof(sjs_size));
    (*_return)->_refCount = 1;
    sjt_dot1628 = _parent;
    sjt_dot1627 = &(sjt_dot1628)->size;
    (*_return)->w = (sjt_dot1627)->w;
    sjt_dot1630 = _parent;
    sjt_dot1629 = &(sjt_dot1630)->size;
    (*_return)->h = (sjt_dot1629)->h;
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
    sjs_vec3* sjt_dot91;
    sjs_vec3* sjt_dot92;
    sjs_vec3* sjt_dot93;
    sjs_vec3* sjt_dot94;
    sjs_vec3* sjt_dot95;
    sjs_vec3* sjt_dot96;
    float sjt_math59;
    float sjt_math60;
    float sjt_math61;
    float sjt_math62;
    float sjt_math63;
    float sjt_math64;

    _return->_refCount = 1;
    sjt_dot91 = _parent;
    sjt_math59 = (sjt_dot91)->x;
    sjt_dot92 = v;
    sjt_math60 = (sjt_dot92)->x;
    _return->x = sjt_math59 + sjt_math60;
    sjt_dot93 = _parent;
    sjt_math61 = (sjt_dot93)->y;
    sjt_dot94 = v;
    sjt_math62 = (sjt_dot94)->y;
    _return->y = sjt_math61 + sjt_math62;
    sjt_dot95 = _parent;
    sjt_math63 = (sjt_dot95)->z;
    sjt_dot96 = v;
    sjt_math64 = (sjt_dot96)->z;
    _return->z = sjt_math63 + sjt_math64;
    sjf_vec3(_return);
}

void sjf_vec3_add_heap(sjs_vec3* _parent, sjs_vec3* v, sjs_vec3** _return) {
    sjs_vec3* sjt_dot100;
    sjs_vec3* sjt_dot101;
    sjs_vec3* sjt_dot102;
    sjs_vec3* sjt_dot97;
    sjs_vec3* sjt_dot98;
    sjs_vec3* sjt_dot99;
    float sjt_math65;
    float sjt_math66;
    float sjt_math67;
    float sjt_math68;
    float sjt_math69;
    float sjt_math70;

    (*_return) = (sjs_vec3*)malloc(sizeof(sjs_vec3));
    (*_return)->_refCount = 1;
    sjt_dot97 = _parent;
    sjt_math65 = (sjt_dot97)->x;
    sjt_dot98 = v;
    sjt_math66 = (sjt_dot98)->x;
    (*_return)->x = sjt_math65 + sjt_math66;
    sjt_dot99 = _parent;
    sjt_math67 = (sjt_dot99)->y;
    sjt_dot100 = v;
    sjt_math68 = (sjt_dot100)->y;
    (*_return)->y = sjt_math67 + sjt_math68;
    sjt_dot101 = _parent;
    sjt_math69 = (sjt_dot101)->z;
    sjt_dot102 = v;
    sjt_math70 = (sjt_dot102)->z;
    (*_return)->z = sjt_math69 + sjt_math70;
    sjf_vec3_heap((*_return));
}

void sjf_vec3_copy(sjs_vec3* _this, sjs_vec3* _from) {
    _this->x = _from->x;
    _this->y = _from->y;
    _this->z = _from->z;
}

void sjf_vec3_cross(sjs_vec3* _parent, sjs_vec3* v, sjs_vec3* _return) {
    sjs_vec3* sjt_dot148;
    sjs_vec3* sjt_dot149;
    sjs_vec3* sjt_dot150;
    sjs_vec3* sjt_dot151;
    sjs_vec3* sjt_dot152;
    sjs_vec3* sjt_dot153;
    sjs_vec3* sjt_dot154;
    sjs_vec3* sjt_dot155;
    sjs_vec3* sjt_dot156;
    sjs_vec3* sjt_dot157;
    sjs_vec3* sjt_dot158;
    sjs_vec3* sjt_dot159;
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
    sjt_dot148 = _parent;
    sjt_math129 = (sjt_dot148)->y;
    sjt_dot149 = v;
    sjt_math130 = (sjt_dot149)->z;
    sjt_math127 = sjt_math129 * sjt_math130;
    sjt_dot150 = _parent;
    sjt_math131 = (sjt_dot150)->z;
    sjt_dot151 = v;
    sjt_math132 = (sjt_dot151)->y;
    sjt_math128 = sjt_math131 * sjt_math132;
    _return->x = sjt_math127 - sjt_math128;
    sjt_dot152 = _parent;
    sjt_math135 = (sjt_dot152)->z;
    sjt_dot153 = v;
    sjt_math136 = (sjt_dot153)->x;
    sjt_math133 = sjt_math135 * sjt_math136;
    sjt_dot154 = _parent;
    sjt_math137 = (sjt_dot154)->x;
    sjt_dot155 = v;
    sjt_math138 = (sjt_dot155)->z;
    sjt_math134 = sjt_math137 * sjt_math138;
    _return->y = sjt_math133 - sjt_math134;
    sjt_dot156 = _parent;
    sjt_math141 = (sjt_dot156)->x;
    sjt_dot157 = v;
    sjt_math142 = (sjt_dot157)->y;
    sjt_math139 = sjt_math141 * sjt_math142;
    sjt_dot158 = _parent;
    sjt_math143 = (sjt_dot158)->y;
    sjt_dot159 = v;
    sjt_math144 = (sjt_dot159)->x;
    sjt_math140 = sjt_math143 * sjt_math144;
    _return->z = sjt_math139 - sjt_math140;
    sjf_vec3(_return);
}

void sjf_vec3_cross_heap(sjs_vec3* _parent, sjs_vec3* v, sjs_vec3** _return) {
    sjs_vec3* sjt_dot160;
    sjs_vec3* sjt_dot161;
    sjs_vec3* sjt_dot162;
    sjs_vec3* sjt_dot163;
    sjs_vec3* sjt_dot164;
    sjs_vec3* sjt_dot165;
    sjs_vec3* sjt_dot166;
    sjs_vec3* sjt_dot167;
    sjs_vec3* sjt_dot168;
    sjs_vec3* sjt_dot169;
    sjs_vec3* sjt_dot170;
    sjs_vec3* sjt_dot171;
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
    sjt_dot160 = _parent;
    sjt_math147 = (sjt_dot160)->y;
    sjt_dot161 = v;
    sjt_math148 = (sjt_dot161)->z;
    sjt_math145 = sjt_math147 * sjt_math148;
    sjt_dot162 = _parent;
    sjt_math149 = (sjt_dot162)->z;
    sjt_dot163 = v;
    sjt_math150 = (sjt_dot163)->y;
    sjt_math146 = sjt_math149 * sjt_math150;
    (*_return)->x = sjt_math145 - sjt_math146;
    sjt_dot164 = _parent;
    sjt_math153 = (sjt_dot164)->z;
    sjt_dot165 = v;
    sjt_math154 = (sjt_dot165)->x;
    sjt_math151 = sjt_math153 * sjt_math154;
    sjt_dot166 = _parent;
    sjt_math155 = (sjt_dot166)->x;
    sjt_dot167 = v;
    sjt_math156 = (sjt_dot167)->z;
    sjt_math152 = sjt_math155 * sjt_math156;
    (*_return)->y = sjt_math151 - sjt_math152;
    sjt_dot168 = _parent;
    sjt_math159 = (sjt_dot168)->x;
    sjt_dot169 = v;
    sjt_math160 = (sjt_dot169)->y;
    sjt_math157 = sjt_math159 * sjt_math160;
    sjt_dot170 = _parent;
    sjt_math161 = (sjt_dot170)->y;
    sjt_dot171 = v;
    sjt_math162 = (sjt_dot171)->x;
    sjt_math158 = sjt_math161 * sjt_math162;
    (*_return)->z = sjt_math157 - sjt_math158;
    sjf_vec3_heap((*_return));
}

void sjf_vec3_destroy(sjs_vec3* _this) {
}

void sjf_vec3_dot(sjs_vec3* _parent, sjs_vec3* v, float* _return) {
    sjs_vec3* sjt_dot181;
    sjs_vec3* sjt_dot182;
    sjs_vec3* sjt_dot183;
    sjs_vec3* sjt_dot184;
    sjs_vec3* sjt_dot185;
    sjs_vec3* sjt_dot186;
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

    sjt_dot181 = _parent;
    sjt_math169 = (sjt_dot181)->x;
    sjt_dot182 = v;
    sjt_math170 = (sjt_dot182)->x;
    sjt_math167 = sjt_math169 * sjt_math170;
    sjt_dot183 = _parent;
    sjt_math171 = (sjt_dot183)->y;
    sjt_dot184 = v;
    sjt_math172 = (sjt_dot184)->y;
    sjt_math168 = sjt_math171 * sjt_math172;
    sjt_math165 = sjt_math167 + sjt_math168;
    sjt_dot185 = _parent;
    sjt_math173 = (sjt_dot185)->z;
    sjt_dot186 = v;
    sjt_math174 = (sjt_dot186)->z;
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
    sjs_vec3* sjt_dot78;
    sjs_vec3* sjt_dot79;
    sjs_vec3* sjt_dot80;
    sjs_vec3* sjt_dot81;
    sjs_vec3* sjt_dot82;
    sjs_vec3* sjt_dot83;
    float sjt_functionParam66;
    float sjt_functionParam67;
    float sjt_functionParam68;
    float sjt_functionParam69;
    float sjt_functionParam70;
    float sjt_functionParam71;

    _return->_refCount = 1;
    sjt_dot78 = a;
    sjt_functionParam66 = (sjt_dot78)->x;
    sjt_dot79 = b;
    sjt_functionParam67 = (sjt_dot79)->x;
    sjf_f32_max(sjt_functionParam66, sjt_functionParam67, &_return->x);
    sjt_dot80 = a;
    sjt_functionParam68 = (sjt_dot80)->y;
    sjt_dot81 = b;
    sjt_functionParam69 = (sjt_dot81)->y;
    sjf_f32_max(sjt_functionParam68, sjt_functionParam69, &_return->y);
    sjt_dot82 = a;
    sjt_functionParam70 = (sjt_dot82)->z;
    sjt_dot83 = b;
    sjt_functionParam71 = (sjt_dot83)->z;
    sjf_f32_max(sjt_functionParam70, sjt_functionParam71, &_return->z);
    sjf_vec3(_return);
}

void sjf_vec3_max_heap(sjs_vec3* a, sjs_vec3* b, sjs_vec3** _return) {
    sjs_vec3* sjt_dot84;
    sjs_vec3* sjt_dot85;
    sjs_vec3* sjt_dot86;
    sjs_vec3* sjt_dot87;
    sjs_vec3* sjt_dot88;
    sjs_vec3* sjt_dot89;
    float sjt_functionParam72;
    float sjt_functionParam73;
    float sjt_functionParam74;
    float sjt_functionParam75;
    float sjt_functionParam76;
    float sjt_functionParam77;

    (*_return) = (sjs_vec3*)malloc(sizeof(sjs_vec3));
    (*_return)->_refCount = 1;
    sjt_dot84 = a;
    sjt_functionParam72 = (sjt_dot84)->x;
    sjt_dot85 = b;
    sjt_functionParam73 = (sjt_dot85)->x;
    sjf_f32_max(sjt_functionParam72, sjt_functionParam73, &(*_return)->x);
    sjt_dot86 = a;
    sjt_functionParam74 = (sjt_dot86)->y;
    sjt_dot87 = b;
    sjt_functionParam75 = (sjt_dot87)->y;
    sjf_f32_max(sjt_functionParam74, sjt_functionParam75, &(*_return)->y);
    sjt_dot88 = a;
    sjt_functionParam76 = (sjt_dot88)->z;
    sjt_dot89 = b;
    sjt_functionParam77 = (sjt_dot89)->z;
    sjf_f32_max(sjt_functionParam76, sjt_functionParam77, &(*_return)->z);
    sjf_vec3_heap((*_return));
}

void sjf_vec3_min(sjs_vec3* a, sjs_vec3* b, sjs_vec3* _return) {
    sjs_vec3* sjt_dot65;
    sjs_vec3* sjt_dot66;
    sjs_vec3* sjt_dot67;
    sjs_vec3* sjt_dot68;
    sjs_vec3* sjt_dot69;
    sjs_vec3* sjt_dot70;
    float sjt_functionParam52;
    float sjt_functionParam53;
    float sjt_functionParam54;
    float sjt_functionParam55;
    float sjt_functionParam56;
    float sjt_functionParam57;

    _return->_refCount = 1;
    sjt_dot65 = a;
    sjt_functionParam52 = (sjt_dot65)->x;
    sjt_dot66 = b;
    sjt_functionParam53 = (sjt_dot66)->x;
    sjf_f32_min(sjt_functionParam52, sjt_functionParam53, &_return->x);
    sjt_dot67 = a;
    sjt_functionParam54 = (sjt_dot67)->y;
    sjt_dot68 = b;
    sjt_functionParam55 = (sjt_dot68)->y;
    sjf_f32_min(sjt_functionParam54, sjt_functionParam55, &_return->y);
    sjt_dot69 = a;
    sjt_functionParam56 = (sjt_dot69)->z;
    sjt_dot70 = b;
    sjt_functionParam57 = (sjt_dot70)->z;
    sjf_f32_min(sjt_functionParam56, sjt_functionParam57, &_return->z);
    sjf_vec3(_return);
}

void sjf_vec3_min_heap(sjs_vec3* a, sjs_vec3* b, sjs_vec3** _return) {
    sjs_vec3* sjt_dot71;
    sjs_vec3* sjt_dot72;
    sjs_vec3* sjt_dot73;
    sjs_vec3* sjt_dot74;
    sjs_vec3* sjt_dot75;
    sjs_vec3* sjt_dot76;
    float sjt_functionParam58;
    float sjt_functionParam59;
    float sjt_functionParam60;
    float sjt_functionParam61;
    float sjt_functionParam62;
    float sjt_functionParam63;

    (*_return) = (sjs_vec3*)malloc(sizeof(sjs_vec3));
    (*_return)->_refCount = 1;
    sjt_dot71 = a;
    sjt_functionParam58 = (sjt_dot71)->x;
    sjt_dot72 = b;
    sjt_functionParam59 = (sjt_dot72)->x;
    sjf_f32_min(sjt_functionParam58, sjt_functionParam59, &(*_return)->x);
    sjt_dot73 = a;
    sjt_functionParam60 = (sjt_dot73)->y;
    sjt_dot74 = b;
    sjt_functionParam61 = (sjt_dot74)->y;
    sjf_f32_min(sjt_functionParam60, sjt_functionParam61, &(*_return)->y);
    sjt_dot75 = a;
    sjt_functionParam62 = (sjt_dot75)->z;
    sjt_dot76 = b;
    sjt_functionParam63 = (sjt_dot76)->z;
    sjf_f32_min(sjt_functionParam62, sjt_functionParam63, &(*_return)->z);
    sjf_vec3_heap((*_return));
}

void sjf_vec3_normalize(sjs_vec3* _parent, sjs_vec3* _return) {
    sjs_vec3* sjt_dot130;
    sjs_vec3* sjt_dot131;
    sjs_vec3* sjt_dot132;
    sjs_vec3* sjt_dot133;
    sjs_vec3* sjt_dot134;
    sjs_vec3* sjt_dot135;
    sjs_vec3* sjt_dot136;
    sjs_vec3* sjt_dot137;
    sjs_vec3* sjt_dot138;
    float sjt_functionParam83;
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

    sjt_dot130 = _parent;
    sjt_math99 = (sjt_dot130)->x;
    sjt_dot131 = _parent;
    sjt_math100 = (sjt_dot131)->x;
    sjt_math97 = sjt_math99 * sjt_math100;
    sjt_dot132 = _parent;
    sjt_math101 = (sjt_dot132)->y;
    sjt_dot133 = _parent;
    sjt_math102 = (sjt_dot133)->y;
    sjt_math98 = sjt_math101 * sjt_math102;
    sjt_math95 = sjt_math97 + sjt_math98;
    sjt_dot134 = _parent;
    sjt_math103 = (sjt_dot134)->z;
    sjt_dot135 = _parent;
    sjt_math104 = (sjt_dot135)->z;
    sjt_math96 = sjt_math103 * sjt_math104;
    sjt_functionParam83 = sjt_math95 + sjt_math96;
    sjf_f32_sqrt(sjt_functionParam83, &sjv_t);
    _return->_refCount = 1;
    sjt_dot136 = _parent;
    sjt_math105 = (sjt_dot136)->x;
    sjt_math106 = sjv_t;
    _return->x = sjt_math105 / sjt_math106;
    sjt_dot137 = _parent;
    sjt_math107 = (sjt_dot137)->y;
    sjt_math108 = sjv_t;
    _return->y = sjt_math107 / sjt_math108;
    sjt_dot138 = _parent;
    sjt_math109 = (sjt_dot138)->z;
    sjt_math110 = sjv_t;
    _return->z = sjt_math109 / sjt_math110;
    sjf_vec3(_return);
}

void sjf_vec3_normalize_heap(sjs_vec3* _parent, sjs_vec3** _return) {
    sjs_vec3* sjt_dot139;
    sjs_vec3* sjt_dot140;
    sjs_vec3* sjt_dot141;
    sjs_vec3* sjt_dot142;
    sjs_vec3* sjt_dot143;
    sjs_vec3* sjt_dot144;
    sjs_vec3* sjt_dot145;
    sjs_vec3* sjt_dot146;
    sjs_vec3* sjt_dot147;
    float sjt_functionParam84;
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

    sjt_dot139 = _parent;
    sjt_math115 = (sjt_dot139)->x;
    sjt_dot140 = _parent;
    sjt_math116 = (sjt_dot140)->x;
    sjt_math113 = sjt_math115 * sjt_math116;
    sjt_dot141 = _parent;
    sjt_math117 = (sjt_dot141)->y;
    sjt_dot142 = _parent;
    sjt_math118 = (sjt_dot142)->y;
    sjt_math114 = sjt_math117 * sjt_math118;
    sjt_math111 = sjt_math113 + sjt_math114;
    sjt_dot143 = _parent;
    sjt_math119 = (sjt_dot143)->z;
    sjt_dot144 = _parent;
    sjt_math120 = (sjt_dot144)->z;
    sjt_math112 = sjt_math119 * sjt_math120;
    sjt_functionParam84 = sjt_math111 + sjt_math112;
    sjf_f32_sqrt(sjt_functionParam84, &sjv_t);
    (*_return) = (sjs_vec3*)malloc(sizeof(sjs_vec3));
    (*_return)->_refCount = 1;
    sjt_dot145 = _parent;
    sjt_math121 = (sjt_dot145)->x;
    sjt_math122 = sjv_t;
    (*_return)->x = sjt_math121 / sjt_math122;
    sjt_dot146 = _parent;
    sjt_math123 = (sjt_dot146)->y;
    sjt_math124 = sjv_t;
    (*_return)->y = sjt_math123 / sjt_math124;
    sjt_dot147 = _parent;
    sjt_math125 = (sjt_dot147)->z;
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
    sjs_vec3* sjt_dot116;
    sjs_vec3* sjt_dot117;
    sjs_vec3* sjt_dot118;
    sjs_vec3* sjt_dot119;
    sjs_vec3* sjt_dot120;
    sjs_vec3* sjt_dot121;
    float sjt_math83;
    float sjt_math84;
    float sjt_math85;
    float sjt_math86;
    float sjt_math87;
    float sjt_math88;

    _return->_refCount = 1;
    sjt_dot116 = _parent;
    sjt_math83 = (sjt_dot116)->x;
    sjt_dot117 = v;
    sjt_math84 = (sjt_dot117)->x;
    _return->x = sjt_math83 - sjt_math84;
    sjt_dot118 = _parent;
    sjt_math85 = (sjt_dot118)->y;
    sjt_dot119 = v;
    sjt_math86 = (sjt_dot119)->y;
    _return->y = sjt_math85 - sjt_math86;
    sjt_dot120 = _parent;
    sjt_math87 = (sjt_dot120)->z;
    sjt_dot121 = v;
    sjt_math88 = (sjt_dot121)->z;
    _return->z = sjt_math87 - sjt_math88;
    sjf_vec3(_return);
}

void sjf_vec3_subtract_heap(sjs_vec3* _parent, sjs_vec3* v, sjs_vec3** _return) {
    sjs_vec3* sjt_dot122;
    sjs_vec3* sjt_dot123;
    sjs_vec3* sjt_dot124;
    sjs_vec3* sjt_dot125;
    sjs_vec3* sjt_dot126;
    sjs_vec3* sjt_dot127;
    float sjt_math89;
    float sjt_math90;
    float sjt_math91;
    float sjt_math92;
    float sjt_math93;
    float sjt_math94;

    (*_return) = (sjs_vec3*)malloc(sizeof(sjs_vec3));
    (*_return)->_refCount = 1;
    sjt_dot122 = _parent;
    sjt_math89 = (sjt_dot122)->x;
    sjt_dot123 = v;
    sjt_math90 = (sjt_dot123)->x;
    (*_return)->x = sjt_math89 - sjt_math90;
    sjt_dot124 = _parent;
    sjt_math91 = (sjt_dot124)->y;
    sjt_dot125 = v;
    sjt_math92 = (sjt_dot125)->y;
    (*_return)->y = sjt_math91 - sjt_math92;
    sjt_dot126 = _parent;
    sjt_math93 = (sjt_dot126)->z;
    sjt_dot127 = v;
    sjt_math94 = (sjt_dot127)->z;
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
    sjs_vertex_location_texture_normal* sjt_dot1319;
    sjs_vertex_location_texture_normal* sjt_dot1320;
    sjs_vertex_location_texture_normal* sjt_dot1321;
    sjs_vec3* sjt_functionParam145;
    void* sjt_functionParam146;
    sjs_vec2* sjt_functionParam147;
    void* sjt_functionParam148;
    sjs_vec3* sjt_functionParam149;
    void* sjt_functionParam150;

    sjt_dot1319 = v;
    sjt_functionParam145 = &(sjt_dot1319)->location;
    sjt_functionParam146 = p;
    sjf_vec3_rawcopy(sjt_functionParam145, sjt_functionParam146, &p);
    sjt_dot1320 = v;
    sjt_functionParam147 = &(sjt_dot1320)->texture;
    sjt_functionParam148 = p;
    sjf_vec2_rawcopy(sjt_functionParam147, sjt_functionParam148, &p);
    sjt_dot1321 = v;
    sjt_functionParam149 = &(sjt_dot1321)->normal;
    sjt_functionParam150 = p;
    sjf_vec3_rawcopy(sjt_functionParam149, sjt_functionParam150, &p);
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
    sjs_mat4 sjt_call69 = { -1 };
    int32_t sjt_cast34;
    int32_t sjt_cast35;
    int32_t sjt_cast36;
    int32_t sjt_cast37;
    int32_t sjt_compare61;
    int32_t sjt_compare62;
    sjs_vec3* sjt_copy28;
    sjs_point* sjt_dot1462;
    sjs_rect* sjt_dot1463;
    sjs_rect* sjt_dot1464;
    sjs_point* sjt_dot1465;
    sjs_rect* sjt_dot1466;
    sjs_rect* sjt_dot1467;
    sjs_vec2* sjt_dot1468;
    sjs_vec2* sjt_dot1469;
    sjs_vec2* sjt_dot1470;
    sjs_vec2* sjt_dot1471;
    sjs_vec4* sjt_dot1472;
    sjs_vec4* sjt_dot1473;
    sjs_vec4* sjt_dot1474;
    sjs_vec4* sjt_dot1475;
    sjs_vec4* sjt_dot1476;
    sjs_vec4* sjt_dot1477;
    sjs_vec4* sjt_dot1478;
    sjs_vec4* sjt_dot1479;
    sjs_vec4* sjt_dot1480;
    sjs_vec4* sjt_dot1481;
    sjs_vec4* sjt_dot1482;
    sjs_vec4* sjt_dot1483;
    sjs_array_i32* sjt_dot1484;
    sjs_vertexbuffer_vertex_location_texture_normal* sjt_dot1485;
    int32_t sjt_forEnd22;
    int32_t sjt_forStart22;
    sjs_mat4* sjt_functionParam389;
    sjs_mat4* sjt_functionParam390;
    sjs_vec4* sjt_functionParam391;
    sjs_vec4* sjt_functionParam392;
    sjs_vec3* sjt_functionParam393;
    bool sjt_ifElse22;
    bool sjt_ifElse38;
    sjs_vec2* sjt_isEmpty9;
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
    sjs_mat4* sjt_parent141;
    sjs_mat4* sjt_parent142;
    sjs_mat4* sjt_parent143;
    sjs_mat4* sjt_parent144;
    sjs_mat4* sjt_parent145;
    sjs_vec3* sjt_parent146;
    sjs_vec3* sjt_parent147;
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
    sjt_dot1462 = screen;
    sjt_math2297 = (sjt_dot1462)->x;
    sjt_dot1463 = viewport;
    sjt_math2298 = (sjt_dot1463)->x;
    sjt_cast34 = sjt_math2297 - sjt_math2298;
    sjt_math2295 = (float)sjt_cast34;
    sjt_dot1464 = viewport;
    sjt_cast35 = (sjt_dot1464)->w;
    sjt_math2296 = (float)sjt_cast35;
    sjt_math2293 = sjt_math2295 / sjt_math2296;
    sjt_math2294 = 2.0f;
    sjt_math2291 = sjt_math2293 * sjt_math2294;
    sjt_math2292 = 1.0f;
    sjv_start.x = sjt_math2291 - sjt_math2292;
    sjt_math2299 = 1.0f;
    sjt_dot1465 = screen;
    sjt_math2305 = (sjt_dot1465)->y;
    sjt_dot1466 = viewport;
    sjt_math2306 = (sjt_dot1466)->y;
    sjt_cast36 = sjt_math2305 - sjt_math2306;
    sjt_math2303 = (float)sjt_cast36;
    sjt_dot1467 = viewport;
    sjt_cast37 = (sjt_dot1467)->h;
    sjt_math2304 = (float)sjt_cast37;
    sjt_math2301 = sjt_math2303 / sjt_math2304;
    sjt_math2302 = 2.0f;
    sjt_math2300 = sjt_math2301 * sjt_math2302;
    sjv_start.y = sjt_math2299 - sjt_math2300;
    sjf_vec2(&sjv_start);
    sjv_vscreenorigin1._refCount = 1;
    sjt_dot1468 = &sjv_start;
    sjv_vscreenorigin1.x = (sjt_dot1468)->x;
    sjt_dot1469 = &sjv_start;
    sjv_vscreenorigin1.y = (sjt_dot1469)->y;
    sjv_vscreenorigin1.z = 0.0f;
    sjv_vscreenorigin1.w = 1.0f;
    sjf_vec4(&sjv_vscreenorigin1);
    sjv_vscreenorigin2._refCount = 1;
    sjt_dot1470 = &sjv_start;
    sjv_vscreenorigin2.x = (sjt_dot1470)->x;
    sjt_dot1471 = &sjv_start;
    sjv_vscreenorigin2.y = (sjt_dot1471)->y;
    sjv_vscreenorigin2.z = 1.0f;
    sjv_vscreenorigin2.w = 1.0f;
    sjf_vec4(&sjv_vscreenorigin2);
    sjt_parent142 = projection;
    sjt_functionParam389 = view;
    sjf_mat4_multiply(sjt_parent142, sjt_functionParam389, &sjt_call69);
    sjt_parent141 = &sjt_call69;
    sjt_functionParam390 = world;
    sjf_mat4_multiply(sjt_parent141, sjt_functionParam390, &sjv_all);
    sjt_parent143 = &sjv_all;
    sjf_mat4_invert(sjt_parent143, &sjv_allinverse);
    sjt_parent144 = &sjv_allinverse;
    sjt_functionParam391 = &sjv_vscreenorigin1;
    sjf_mat4_multiplyvec4(sjt_parent144, sjt_functionParam391, &sjv_vprojectedorigin1);
    sjt_parent145 = &sjv_allinverse;
    sjt_functionParam392 = &sjv_vscreenorigin2;
    sjf_mat4_multiplyvec4(sjt_parent145, sjt_functionParam392, &sjv_vprojectedorigin2);
    sjv_vflattenedorigin1._refCount = 1;
    sjt_dot1472 = &sjv_vprojectedorigin1;
    sjt_math2307 = (sjt_dot1472)->x;
    sjt_dot1473 = &sjv_vprojectedorigin1;
    sjt_math2308 = (sjt_dot1473)->w;
    sjv_vflattenedorigin1.x = sjt_math2307 / sjt_math2308;
    sjt_dot1474 = &sjv_vprojectedorigin1;
    sjt_math2309 = (sjt_dot1474)->y;
    sjt_dot1475 = &sjv_vprojectedorigin1;
    sjt_math2310 = (sjt_dot1475)->w;
    sjv_vflattenedorigin1.y = sjt_math2309 / sjt_math2310;
    sjt_dot1476 = &sjv_vprojectedorigin1;
    sjt_math2311 = (sjt_dot1476)->z;
    sjt_dot1477 = &sjv_vprojectedorigin1;
    sjt_math2312 = (sjt_dot1477)->w;
    sjv_vflattenedorigin1.z = sjt_math2311 / sjt_math2312;
    sjf_vec3(&sjv_vflattenedorigin1);
    sjv_vflattenedorigin2._refCount = 1;
    sjt_dot1478 = &sjv_vprojectedorigin2;
    sjt_math2313 = (sjt_dot1478)->x;
    sjt_dot1479 = &sjv_vprojectedorigin2;
    sjt_math2314 = (sjt_dot1479)->w;
    sjv_vflattenedorigin2.x = sjt_math2313 / sjt_math2314;
    sjt_dot1480 = &sjv_vprojectedorigin2;
    sjt_math2315 = (sjt_dot1480)->y;
    sjt_dot1481 = &sjv_vprojectedorigin2;
    sjt_math2316 = (sjt_dot1481)->w;
    sjv_vflattenedorigin2.y = sjt_math2315 / sjt_math2316;
    sjt_dot1482 = &sjv_vprojectedorigin2;
    sjt_math2317 = (sjt_dot1482)->z;
    sjt_dot1483 = &sjv_vprojectedorigin2;
    sjt_math2318 = (sjt_dot1483)->w;
    sjv_vflattenedorigin2.z = sjt_math2317 / sjt_math2318;
    sjf_vec3(&sjv_vflattenedorigin2);
    sjt_parent146 = &sjv_vflattenedorigin2;
    sjt_functionParam393 = &sjv_vflattenedorigin1;
    sjf_vec3_subtract(sjt_parent146, sjt_functionParam393, &sjv_vflatteneddir);
    sjt_copy28 = &sjv_vflattenedorigin1;
    sjv_vpickrayorig._refCount = 1;
    sjf_vec3_copy(&sjv_vpickrayorig, sjt_copy28);
    sjt_parent147 = &sjv_vflatteneddir;
    sjf_vec3_normalize(sjt_parent147, &sjv_vpickraydir);
    sjt_dot1485 = _parent;
    sjt_dot1484 = &(sjt_dot1485)->indices;
    sjt_compare61 = (sjt_dot1484)->count;
    sjt_compare62 = 0;
    sjt_ifElse22 = sjt_compare61 > sjt_compare62;
    if (sjt_ifElse22) {
        sjs_array_i32* sjt_dot1486;
        sjs_vertexbuffer_vertex_location_texture_normal* sjt_dot1487;
        int32_t sjt_math2319;
        int32_t sjt_math2320;

        sjt_dot1487 = _parent;
        sjt_dot1486 = &(sjt_dot1487)->indices;
        sjt_math2319 = (sjt_dot1486)->count;
        sjt_math2320 = 3;
        sjv_ctriangles = sjt_math2319 / sjt_math2320;
    } else {
        sjs_array_vertex_location_texture_normal* sjt_dot1488;
        sjs_vertexbuffer_vertex_location_texture_normal* sjt_dot1489;
        int32_t sjt_math2321;
        int32_t sjt_math2322;

        sjt_dot1489 = _parent;
        sjt_dot1488 = &(sjt_dot1489)->vertices;
        sjt_math2321 = (sjt_dot1488)->count;
        sjt_math2322 = 3;
        sjv_ctriangles = sjt_math2321 / sjt_math2322;
    }

    sjt_forStart22 = 0;
    sjt_forEnd22 = sjv_ctriangles;
    i = sjt_forStart22;
    while (i < sjt_forEnd22) {
        int32_t sjt_compare63;
        int32_t sjt_compare64;
        int32_t sjt_compare65;
        int32_t sjt_compare66;
        int32_t sjt_compare67;
        int32_t sjt_compare68;
        sjs_array_i32* sjt_dot1490;
        sjs_vertexbuffer_vertex_location_texture_normal* sjt_dot1491;
        sjs_array_i32* sjt_dot1495;
        sjs_vertexbuffer_vertex_location_texture_normal* sjt_dot1496;
        sjs_array_i32* sjt_dot1500;
        sjs_vertexbuffer_vertex_location_texture_normal* sjt_dot1501;
        sjs_vertex_location_texture_normal* sjt_dot1505;
        sjs_vertex_location_texture_normal* sjt_dot1506;
        sjs_vertex_location_texture_normal* sjt_dot1507;
        sjs_vec3* sjt_functionParam423;
        sjs_vec3* sjt_functionParam424;
        sjs_vec3* sjt_functionParam425;
        sjs_vec3* sjt_functionParam426;
        sjs_vec3* sjt_functionParam427;
        bool sjt_ifElse23;
        bool sjt_ifElse24;
        bool sjt_ifElse25;
        bool sjt_isEmpty3;
        sjs_vec3* sjt_isEmpty4;
        sjs_vec3 sjv_result = { -1 };
        sjs_vertex_location_texture_normal sjv_vertex0 = { -1 };
        sjs_vertex_location_texture_normal sjv_vertex1 = { -1 };
        sjs_vertex_location_texture_normal sjv_vertex2 = { -1 };

        sjt_dot1491 = _parent;
        sjt_dot1490 = &(sjt_dot1491)->indices;
        sjt_compare63 = (sjt_dot1490)->count;
        sjt_compare64 = 0;
        sjt_ifElse23 = sjt_compare63 > sjt_compare64;
        if (sjt_ifElse23) {
            sjs_vertexbuffer_vertex_location_texture_normal* sjt_dot1492;
            sjs_vertexbuffer_vertex_location_texture_normal* sjt_dot1493;
            int32_t sjt_functionParam394;
            int32_t sjt_functionParam395;
            int32_t sjt_math2323;
            int32_t sjt_math2324;
            int32_t sjt_math2325;
            int32_t sjt_math2326;
            sjs_array_vertex_location_texture_normal* sjt_parent148;
            sjs_array_i32* sjt_parent149;

            sjt_dot1492 = _parent;
            sjt_parent148 = &(sjt_dot1492)->vertices;
            sjt_dot1493 = _parent;
            sjt_parent149 = &(sjt_dot1493)->indices;
            sjt_math2325 = i;
            sjt_math2326 = 3;
            sjt_math2323 = sjt_math2325 * sjt_math2326;
            sjt_math2324 = 0;
            sjt_functionParam395 = sjt_math2323 + sjt_math2324;
            sjf_array_i32_getat(sjt_parent149, sjt_functionParam395, &sjt_functionParam394);
            sjf_array_vertex_location_texture_normal_getat(sjt_parent148, sjt_functionParam394, &sjv_vertex0);
        } else {
            sjs_vertexbuffer_vertex_location_texture_normal* sjt_dot1494;
            int32_t sjt_functionParam396;
            int32_t sjt_math2327;
            int32_t sjt_math2328;
            int32_t sjt_math2329;
            int32_t sjt_math2330;
            sjs_array_vertex_location_texture_normal* sjt_parent150;

            sjt_dot1494 = _parent;
            sjt_parent150 = &(sjt_dot1494)->vertices;
            sjt_math2329 = i;
            sjt_math2330 = 3;
            sjt_math2327 = sjt_math2329 * sjt_math2330;
            sjt_math2328 = 0;
            sjt_functionParam396 = sjt_math2327 + sjt_math2328;
            sjf_array_vertex_location_texture_normal_getat(sjt_parent150, sjt_functionParam396, &sjv_vertex0);
        }

        sjt_dot1496 = _parent;
        sjt_dot1495 = &(sjt_dot1496)->indices;
        sjt_compare65 = (sjt_dot1495)->count;
        sjt_compare66 = 0;
        sjt_ifElse24 = sjt_compare65 > sjt_compare66;
        if (sjt_ifElse24) {
            sjs_vertexbuffer_vertex_location_texture_normal* sjt_dot1497;
            sjs_vertexbuffer_vertex_location_texture_normal* sjt_dot1498;
            int32_t sjt_functionParam397;
            int32_t sjt_functionParam398;
            int32_t sjt_math2331;
            int32_t sjt_math2332;
            int32_t sjt_math2333;
            int32_t sjt_math2334;
            sjs_array_vertex_location_texture_normal* sjt_parent151;
            sjs_array_i32* sjt_parent152;

            sjt_dot1497 = _parent;
            sjt_parent151 = &(sjt_dot1497)->vertices;
            sjt_dot1498 = _parent;
            sjt_parent152 = &(sjt_dot1498)->indices;
            sjt_math2333 = i;
            sjt_math2334 = 3;
            sjt_math2331 = sjt_math2333 * sjt_math2334;
            sjt_math2332 = 1;
            sjt_functionParam398 = sjt_math2331 + sjt_math2332;
            sjf_array_i32_getat(sjt_parent152, sjt_functionParam398, &sjt_functionParam397);
            sjf_array_vertex_location_texture_normal_getat(sjt_parent151, sjt_functionParam397, &sjv_vertex1);
        } else {
            sjs_vertexbuffer_vertex_location_texture_normal* sjt_dot1499;
            int32_t sjt_functionParam399;
            int32_t sjt_math2335;
            int32_t sjt_math2336;
            int32_t sjt_math2337;
            int32_t sjt_math2338;
            sjs_array_vertex_location_texture_normal* sjt_parent153;

            sjt_dot1499 = _parent;
            sjt_parent153 = &(sjt_dot1499)->vertices;
            sjt_math2337 = i;
            sjt_math2338 = 3;
            sjt_math2335 = sjt_math2337 * sjt_math2338;
            sjt_math2336 = 1;
            sjt_functionParam399 = sjt_math2335 + sjt_math2336;
            sjf_array_vertex_location_texture_normal_getat(sjt_parent153, sjt_functionParam399, &sjv_vertex1);
        }

        sjt_dot1501 = _parent;
        sjt_dot1500 = &(sjt_dot1501)->indices;
        sjt_compare67 = (sjt_dot1500)->count;
        sjt_compare68 = 0;
        sjt_ifElse25 = sjt_compare67 > sjt_compare68;
        if (sjt_ifElse25) {
            sjs_vertexbuffer_vertex_location_texture_normal* sjt_dot1502;
            sjs_vertexbuffer_vertex_location_texture_normal* sjt_dot1503;
            int32_t sjt_functionParam400;
            int32_t sjt_functionParam401;
            int32_t sjt_math2339;
            int32_t sjt_math2340;
            int32_t sjt_math2341;
            int32_t sjt_math2342;
            sjs_array_vertex_location_texture_normal* sjt_parent154;
            sjs_array_i32* sjt_parent155;

            sjt_dot1502 = _parent;
            sjt_parent154 = &(sjt_dot1502)->vertices;
            sjt_dot1503 = _parent;
            sjt_parent155 = &(sjt_dot1503)->indices;
            sjt_math2341 = i;
            sjt_math2342 = 3;
            sjt_math2339 = sjt_math2341 * sjt_math2342;
            sjt_math2340 = 2;
            sjt_functionParam401 = sjt_math2339 + sjt_math2340;
            sjf_array_i32_getat(sjt_parent155, sjt_functionParam401, &sjt_functionParam400);
            sjf_array_vertex_location_texture_normal_getat(sjt_parent154, sjt_functionParam400, &sjv_vertex2);
        } else {
            sjs_vertexbuffer_vertex_location_texture_normal* sjt_dot1504;
            int32_t sjt_functionParam402;
            int32_t sjt_math2343;
            int32_t sjt_math2344;
            int32_t sjt_math2345;
            int32_t sjt_math2346;
            sjs_array_vertex_location_texture_normal* sjt_parent156;

            sjt_dot1504 = _parent;
            sjt_parent156 = &(sjt_dot1504)->vertices;
            sjt_math2345 = i;
            sjt_math2346 = 3;
            sjt_math2343 = sjt_math2345 * sjt_math2346;
            sjt_math2344 = 2;
            sjt_functionParam402 = sjt_math2343 + sjt_math2344;
            sjf_array_vertex_location_texture_normal_getat(sjt_parent156, sjt_functionParam402, &sjv_vertex2);
        }

        sjt_functionParam423 = &sjv_vpickrayorig;
        sjt_functionParam424 = &sjv_vpickraydir;
        sjt_dot1505 = &sjv_vertex0;
        sjt_functionParam425 = &(sjt_dot1505)->location;
        sjt_dot1506 = &sjv_vertex1;
        sjt_functionParam426 = &(sjt_dot1506)->location;
        sjt_dot1507 = &sjv_vertex2;
        sjt_functionParam427 = &(sjt_dot1507)->location;
        sjf_intersecttriangle(sjt_functionParam423, sjt_functionParam424, sjt_functionParam425, sjt_functionParam426, sjt_functionParam427, &sjv_result);
        sjt_isEmpty4 = (sjv_result._refCount != -1 ? &sjv_result : 0);
        sjt_isEmpty3 = (sjt_isEmpty4 == 0);
        if (!sjt_isEmpty3) {
            sjs_vec3* ifValue7;
            float sjt_compare93;
            float sjt_compare94;
            sjs_vec3* sjt_dot1508;
            bool sjt_ifElse34;
            bool sjt_ifElse35;
            bool sjt_ifElse36;
            sjs_vec3* sjt_isEmpty5;
            float_option sjt_isEmpty6;
            sjs_vec3* sjt_isEmpty7;
            bool sjt_or10;
            bool sjt_or9;
            sjs_vec3 sjv_t = { -1 };

            ifValue7 = (sjv_result._refCount != -1 ? &sjv_result : 0);
            sjt_isEmpty5 = (sjv_intersection._refCount != -1 ? &sjv_intersection : 0);
            sjt_or9 = (sjt_isEmpty5 == 0);
            sjt_dot1508 = ifValue7;
            sjt_compare93 = (sjt_dot1508)->z;
            sjt_isEmpty7 = (sjv_intersection._refCount != -1 ? &sjv_intersection : 0);
            sjt_ifElse36 = (sjt_isEmpty7 == 0);
            if (sjt_ifElse36) {
                sjt_isEmpty6 = float_empty;
            } else {
                sjs_vec3* sjt_dot1509;
                float sjt_value3;
                float_option value1;

                sjt_dot1509 = (sjv_intersection._refCount != -1 ? &sjv_intersection : 0);
                sjt_value3 = (sjt_dot1509)->z;
                value1.isempty = false;
                value1.value = sjt_value3;
                sjt_isEmpty6 = value1;
            }

            sjt_ifElse35 = sjt_isEmpty6.isempty;
            if (sjt_ifElse35) {
                sjt_compare94 = 0.0f;
            } else {
                float_option sjt_getValue1;
                bool sjt_ifElse37;
                sjs_vec3* sjt_isEmpty8;

                sjt_isEmpty8 = (sjv_intersection._refCount != -1 ? &sjv_intersection : 0);
                sjt_ifElse37 = (sjt_isEmpty8 == 0);
                if (sjt_ifElse37) {
                    sjt_getValue1 = float_empty;
                } else {
                    sjs_vec3* sjt_dot1510;
                    float sjt_value4;
                    float_option value2;

                    sjt_dot1510 = (sjv_intersection._refCount != -1 ? &sjv_intersection : 0);
                    sjt_value4 = (sjt_dot1510)->z;
                    value2.isempty = false;
                    value2.value = sjt_value4;
                    sjt_getValue1 = value2;
                }

                sjt_compare94 = sjt_getValue1.value;
            }

            sjt_or10 = sjt_compare93 < sjt_compare94;
            sjt_ifElse34 = sjt_or9 || sjt_or10;
            if (sjt_ifElse34) {
                sjs_vec3* sjt_copy29;
                sjs_vec3* sjt_copy30;
                sjs_vec2* sjt_dot1511;
                sjs_vertex_location_texture_normal* sjt_dot1512;
                sjs_vec2* sjt_dot1513;
                sjs_vertex_location_texture_normal* sjt_dot1514;
                sjs_vec2* sjt_dot1515;
                sjs_vertex_location_texture_normal* sjt_dot1516;
                sjs_vec2* sjt_dot1517;
                sjs_vertex_location_texture_normal* sjt_dot1518;
                sjs_vec2* sjt_dot1519;
                sjs_vertex_location_texture_normal* sjt_dot1520;
                sjs_vec2* sjt_dot1521;
                sjs_vertex_location_texture_normal* sjt_dot1522;
                sjs_vec2* sjt_dot1523;
                sjs_vertex_location_texture_normal* sjt_dot1524;
                sjs_vec2* sjt_dot1525;
                sjs_vertex_location_texture_normal* sjt_dot1526;
                sjs_vec2* sjt_dot1527;
                sjs_vertex_location_texture_normal* sjt_dot1528;
                sjs_vec3* sjt_dot1529;
                sjs_vec3* sjt_dot1530;
                sjs_vec2* sjt_dot1531;
                sjs_vertex_location_texture_normal* sjt_dot1532;
                sjs_vec3* sjt_dot1533;
                sjs_vec3* sjt_dot1534;
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

                sjt_copy29 = ifValue7;
                sjf_vec3_copy(&sjv_intersection, sjt_copy29);
                sjt_copy30 = (sjv_intersection._refCount != -1 ? &sjv_intersection : 0);
                if (sjt_copy30->_refCount == -1) { exit(-1); }
                sjv_t._refCount = 1;
                sjf_vec3_copy(&sjv_t, sjt_copy30);
                sjt_dot1512 = &sjv_vertex1;
                sjt_dot1511 = &(sjt_dot1512)->texture;
                sjt_math2371 = (sjt_dot1511)->x;
                sjt_dot1514 = &sjv_vertex0;
                sjt_dot1513 = &(sjt_dot1514)->texture;
                sjt_math2372 = (sjt_dot1513)->x;
                sjv_dtu1 = sjt_math2371 - sjt_math2372;
                sjt_dot1516 = &sjv_vertex2;
                sjt_dot1515 = &(sjt_dot1516)->texture;
                sjt_math2373 = (sjt_dot1515)->x;
                sjt_dot1518 = &sjv_vertex0;
                sjt_dot1517 = &(sjt_dot1518)->texture;
                sjt_math2374 = (sjt_dot1517)->x;
                sjv_dtu2 = sjt_math2373 - sjt_math2374;
                sjt_dot1520 = &sjv_vertex1;
                sjt_dot1519 = &(sjt_dot1520)->texture;
                sjt_math2375 = (sjt_dot1519)->y;
                sjt_dot1522 = &sjv_vertex0;
                sjt_dot1521 = &(sjt_dot1522)->texture;
                sjt_math2376 = (sjt_dot1521)->y;
                sjv_dtv1 = sjt_math2375 - sjt_math2376;
                sjt_dot1524 = &sjv_vertex2;
                sjt_dot1523 = &(sjt_dot1524)->texture;
                sjt_math2377 = (sjt_dot1523)->y;
                sjt_dot1526 = &sjv_vertex0;
                sjt_dot1525 = &(sjt_dot1526)->texture;
                sjt_math2378 = (sjt_dot1525)->y;
                sjv_dtv2 = sjt_math2377 - sjt_math2378;
                sjv_texture._refCount = 1;
                sjt_dot1528 = &sjv_vertex0;
                sjt_dot1527 = &(sjt_dot1528)->texture;
                sjt_math2381 = (sjt_dot1527)->x;
                sjt_dot1529 = &sjv_t;
                sjt_math2383 = (sjt_dot1529)->x;
                sjt_math2384 = sjv_dtu1;
                sjt_math2382 = sjt_math2383 * sjt_math2384;
                sjt_math2379 = sjt_math2381 + sjt_math2382;
                sjt_dot1530 = &sjv_t;
                sjt_math2385 = (sjt_dot1530)->y;
                sjt_math2386 = sjv_dtu2;
                sjt_math2380 = sjt_math2385 * sjt_math2386;
                sjv_texture.x = sjt_math2379 + sjt_math2380;
                sjt_dot1532 = &sjv_vertex0;
                sjt_dot1531 = &(sjt_dot1532)->texture;
                sjt_math2389 = (sjt_dot1531)->y;
                sjt_dot1533 = &sjv_t;
                sjt_math2391 = (sjt_dot1533)->x;
                sjt_math2392 = sjv_dtv1;
                sjt_math2390 = sjt_math2391 * sjt_math2392;
                sjt_math2387 = sjt_math2389 + sjt_math2390;
                sjt_dot1534 = &sjv_t;
                sjt_math2393 = (sjt_dot1534)->y;
                sjt_math2394 = sjv_dtv2;
                sjt_math2388 = sjt_math2393 * sjt_math2394;
                sjv_texture.y = sjt_math2387 + sjt_math2388;
                sjf_vec2(&sjv_texture);
            }

            if (sjv_t._refCount == 1) { sjf_vec3_destroy(&sjv_t); }
        }

        i++;

        if (sjv_result._refCount == 1) { sjf_vec3_destroy(&sjv_result); }
        if (sjv_vertex0._refCount == 1) { sjf_vertex_location_texture_normal_destroy(&sjv_vertex0); }
        if (sjv_vertex1._refCount == 1) { sjf_vertex_location_texture_normal_destroy(&sjv_vertex1); }
        if (sjv_vertex2._refCount == 1) { sjf_vertex_location_texture_normal_destroy(&sjv_vertex2); }
    }

    sjt_isEmpty9 = (sjv_texture._refCount != -1 ? &sjv_texture : 0);
    sjt_ifElse38 = (sjt_isEmpty9 == 0);
    if (sjt_ifElse38) {
        _return->_refCount = -1;
    } else {
        sjs_vec2* sjt_copy31;

        sjt_copy31 = (sjv_texture._refCount != -1 ? &sjv_texture : 0);
        _return->_refCount = 1;
        sjf_vec2_copy(_return, sjt_copy31);
    }

    if (sjt_call69._refCount == 1) { sjf_mat4_destroy(&sjt_call69); }
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

void sji_animation_copy(sji_animation* _this, sji_animation* _from) {
    _this->_refCount = 1;
    _this->_parent = _from->_parent;
    _this->_parent->_refCount++;
    _this->destroy = _from->destroy;
    _this->asInterface = _from->asInterface;
    _this->nextframe = _from->nextframe;
}

void sji_animation_destroy(sji_animation* _this) {
    _this->_parent->_refCount--;
    if (_this->_parent->_refCount <= 0) {
        _this->destroy(_this->_parent);
        free(_this->_parent);
    }
}

void sji_element_copy(sji_element* _this, sji_element* _from) {
    _this->_refCount = 1;
    _this->_parent = _from->_parent;
    _this->_parent->_refCount++;
    _this->destroy = _from->destroy;
    _this->asInterface = _from->asInterface;
    _this->getsize = _from->getsize;
    _this->getsize = _from->getsize;
    _this->getrect = _from->getrect;
    _this->setrect = _from->setrect;
    _this->render = _from->render;
    _this->firemouseevent = _from->firemouseevent;
}

void sji_element_destroy(sji_element* _this) {
    _this->_parent->_refCount--;
    if (_this->_parent->_refCount <= 0) {
        _this->destroy(_this->_parent);
        free(_this->_parent);
    }
}

void sji_model_copy(sji_model* _this, sji_model* _from) {
    _this->_refCount = 1;
    _this->_parent = _from->_parent;
    _this->_parent->_refCount++;
    _this->destroy = _from->destroy;
    _this->asInterface = _from->asInterface;
    _this->update = _from->update;
    _this->getz = _from->getz;
    _this->renderorqueue = _from->renderorqueue;
    _this->render = _from->render;
    _this->firemouseevent = _from->firemouseevent;
}

void sji_model_destroy(sji_model* _this) {
    _this->_parent->_refCount--;
    if (_this->_parent->_refCount <= 0) {
        _this->destroy(_this->_parent);
        free(_this->_parent);
    }
}

int main(int argc, char** argv) {
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
    sjv_animator._refCount = 1;
    sjv_animator.animations._refCount = 1;
    sjv_animator.animations.array._refCount = 1;
    sjv_animator.animations.array.datasize = 0;
    sjv_animator.animations.array.data = 0;
    sjv_animator.animations.array._isglobal = false;
    sjv_animator.animations.array.count = 0;
    sjf_array_heap_animation(&sjv_animator.animations.array);
    sjf_list_heap_animation(&sjv_animator.animations);
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
    sjv_mouse_captureelement = 0;
    if (sjv_mouse_captureelement != 0) {
        sjv_mouse_captureelement->_refCount++;
    }

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
    sjt_cast1 = (sjs_fillelement*)malloc(sizeof(sjs_fillelement));
    sjt_cast1->_refCount = 1;
    sjt_cast1->children._refCount = 1;
    sjt_cast1->children.datasize = 2;
    sjt_cast1->children.data = 0;
    sjt_cast1->children._isglobal = false;
    sjt_cast1->children.count = 0;
    sjf_array_heap_element(&sjt_cast1->children);
    sjs_array_heap_element* array11;
    array11 = &sjt_cast1->children;
    sjt_parent7 = array11;
    sjt_functionParam4 = 0;
    sjt_cast2 = (sjs_nauscene3delement*)malloc(sizeof(sjs_nauscene3delement));
    sjt_cast2->_refCount = 1;
    sjt_cast2->children._refCount = 1;
    sjt_cast2->children.datasize = 4;
    sjt_cast2->children.data = 0;
    sjt_cast2->children._isglobal = false;
    sjt_cast2->children.count = 0;
    sjf_array_heap_model(&sjt_cast2->children);
    sjs_array_heap_model* array5;
    array5 = &sjt_cast2->children;
    sjt_parent41 = array5;
    sjt_functionParam103 = 0;
    sjt_cast11 = (sjs_model*)malloc(sizeof(sjs_model));
    sjt_cast11->_refCount = 1;
    sjt_negate11 = 6.3f;
    result13 = -sjt_negate11;
    sjt_functionParam191 = result13;
    sjt_functionParam192 = 6.3f;
    sjt_negate12 = 1.0f;
    result14 = -sjt_negate12;
    sjt_functionParam193 = result14;
    sjt_functionParam194 = 1.0f;
    sjt_functionParam195 = 0.0f;
    sjt_functionParam196 = 0.0f;
    sjt_functionParam197 = 1.0f;
    sjt_functionParam198 = 0.0f;
    sjt_functionParam199 = 1.0f;
    sjf_planevertexbuffer(sjt_functionParam191, sjt_functionParam192, sjt_functionParam193, sjt_functionParam194, sjt_functionParam195, sjt_functionParam196, sjt_functionParam197, sjt_functionParam198, sjt_functionParam199, &sjt_cast11->vertexbuffer);
    sjt_copy11 = &sjv_phongtextureshader;
    sjt_cast11->shader._refCount = 1;
    sjf_shader_copy(&sjt_cast11->shader, sjt_copy11);
    sjt_call30._refCount = 1;
    sjt_call30.count = 26;
    sjt_call30.data._refCount = 1;
    sjt_call30.data.datasize = 27;
    sjt_call30.data.data = (void*)sjg_string16;
    sjt_call30.data._isglobal = true;
    sjt_call30.data.count = 27;
    sjf_array_char(&sjt_call30.data);
    sjf_string(&sjt_call30);
    sjt_functionParam200 = &sjt_call30;
    sjf_texturefrompng(sjt_functionParam200, &sjt_cast11->texture);
    sjt_functionParam201 = 0.0f;
    sjt_functionParam202 = 8.0f;
    sjt_functionParam203 = 20.0f;
    sjf_mat4_translate(sjt_functionParam201, sjt_functionParam202, sjt_functionParam203, &sjt_call31);
    sjt_parent77 = &sjt_call31;
    sjt_functionParam205 = 12.0f;
    sjt_functionParam206 = 12.0f;
    sjt_functionParam207 = 12.0f;
    sjf_mat4_scale(sjt_functionParam205, sjt_functionParam206, sjt_functionParam207, &sjt_call32);
    sjt_functionParam204 = &sjt_call32;
    sjf_mat4_multiply(sjt_parent77, sjt_functionParam204, &sjt_cast11->model);
    sjt_cast11->center._refCount = 1;
    sjt_cast11->center.x = 0.0f;
    sjt_cast11->center.y = 0.0f;
    sjt_cast11->center.z = 0.0f;
    sjf_vec3(&sjt_cast11->center);
    sjt_cast11->hasalpha = false;
    sjt_cast11->id._refCount = 1;
    sjt_cast11->id.count = 0;
    sjt_cast11->id.data._refCount = 1;
    sjt_cast11->id.data.datasize = 1;
    sjt_cast11->id.data.data = sjv_emptystringdata;
    sjt_cast11->id.data._isglobal = true;
    sjt_cast11->id.data.count = 1;
    sjf_array_char(&sjt_cast11->id.data);
    sjf_string(&sjt_cast11->id);
    sjt_cast11->_projection._refCount = 1;
    sjt_cast11->_projection.m00 = 0.0f;
    sjt_cast11->_projection.m01 = 0.0f;
    sjt_cast11->_projection.m02 = 0.0f;
    sjt_cast11->_projection.m03 = 0.0f;
    sjt_cast11->_projection.m10 = 0.0f;
    sjt_cast11->_projection.m11 = 0.0f;
    sjt_cast11->_projection.m12 = 0.0f;
    sjt_cast11->_projection.m13 = 0.0f;
    sjt_cast11->_projection.m20 = 0.0f;
    sjt_cast11->_projection.m21 = 0.0f;
    sjt_cast11->_projection.m22 = 0.0f;
    sjt_cast11->_projection.m23 = 0.0f;
    sjt_cast11->_projection.m30 = 0.0f;
    sjt_cast11->_projection.m31 = 0.0f;
    sjt_cast11->_projection.m32 = 0.0f;
    sjt_cast11->_projection.m33 = 0.0f;
    sjf_mat4(&sjt_cast11->_projection);
    sjt_cast11->_view._refCount = 1;
    sjt_cast11->_view.m00 = 0.0f;
    sjt_cast11->_view.m01 = 0.0f;
    sjt_cast11->_view.m02 = 0.0f;
    sjt_cast11->_view.m03 = 0.0f;
    sjt_cast11->_view.m10 = 0.0f;
    sjt_cast11->_view.m11 = 0.0f;
    sjt_cast11->_view.m12 = 0.0f;
    sjt_cast11->_view.m13 = 0.0f;
    sjt_cast11->_view.m20 = 0.0f;
    sjt_cast11->_view.m21 = 0.0f;
    sjt_cast11->_view.m22 = 0.0f;
    sjt_cast11->_view.m23 = 0.0f;
    sjt_cast11->_view.m30 = 0.0f;
    sjt_cast11->_view.m31 = 0.0f;
    sjt_cast11->_view.m32 = 0.0f;
    sjt_cast11->_view.m33 = 0.0f;
    sjf_mat4(&sjt_cast11->_view);
    sjt_cast11->_world._refCount = 1;
    sjt_cast11->_world.m00 = 0.0f;
    sjt_cast11->_world.m01 = 0.0f;
    sjt_cast11->_world.m02 = 0.0f;
    sjt_cast11->_world.m03 = 0.0f;
    sjt_cast11->_world.m10 = 0.0f;
    sjt_cast11->_world.m11 = 0.0f;
    sjt_cast11->_world.m12 = 0.0f;
    sjt_cast11->_world.m13 = 0.0f;
    sjt_cast11->_world.m20 = 0.0f;
    sjt_cast11->_world.m21 = 0.0f;
    sjt_cast11->_world.m22 = 0.0f;
    sjt_cast11->_world.m23 = 0.0f;
    sjt_cast11->_world.m30 = 0.0f;
    sjt_cast11->_world.m31 = 0.0f;
    sjt_cast11->_world.m32 = 0.0f;
    sjt_cast11->_world.m33 = 0.0f;
    sjf_mat4(&sjt_cast11->_world);
    sjt_cast11->_light._refCount = 1;
    sjt_cast11->_light.pos._refCount = 1;
    sjt_cast11->_light.pos.x = 1.0f;
    sjt_cast11->_light.pos.y = 1.0f;
    sjt_cast11->_light.pos.z = 1.0f;
    sjf_vec3(&sjt_cast11->_light.pos);
    sjt_cast11->_light.diffusecolor._refCount = 1;
    sjt_cast11->_light.diffusecolor.r = 0.5f;
    sjt_cast11->_light.diffusecolor.g = 0.5f;
    sjt_cast11->_light.diffusecolor.b = 0.0f;
    sjt_cast11->_light.diffusecolor.a = 1.0f;
    sjf_color(&sjt_cast11->_light.diffusecolor);
    sjt_cast11->_light.speccolor._refCount = 1;
    sjt_cast11->_light.speccolor.r = 1.0f;
    sjt_cast11->_light.speccolor.g = 1.0f;
    sjt_cast11->_light.speccolor.b = 1.0f;
    sjt_cast11->_light.speccolor.a = 1.0f;
    sjf_color(&sjt_cast11->_light.speccolor);
    sjf_light(&sjt_cast11->_light);
    sjt_cast11->_projectedcenter._refCount = 1;
    sjt_cast11->_projectedcenter.x = 0.0f;
    sjt_cast11->_projectedcenter.y = 0.0f;
    sjt_cast11->_projectedcenter.z = 0.0f;
    sjf_vec3(&sjt_cast11->_projectedcenter);
    sjf_model_heap(sjt_cast11);
    sjt_functionParam104 = (sji_model*)sjf_model_heap_as_sji_model(sjt_cast11);
    sjf_array_heap_model_initat(sjt_parent41, sjt_functionParam103, sjt_functionParam104);
    sjt_parent78 = array5;
    sjt_functionParam208 = 1;
    sjt_cast13 = (sjs_leafpanel*)malloc(sizeof(sjs_leafpanel));
    sjt_cast13->_refCount = 1;
    sjt_cast13->textures._refCount = 1;
    sjt_cast13->textures.datasize = 8;
    sjt_cast13->textures.data = 0;
    sjt_cast13->textures._isglobal = false;
    sjt_cast13->textures.count = 0;
    sjf_array_texture(&sjt_cast13->textures);
    sjs_array_texture* array6;
    array6 = &sjt_cast13->textures;
    sjt_parent101 = array6;
    sjt_functionParam253 = 0;
    sjt_call38._refCount = 1;
    sjt_call38.count = 21;
    sjt_call38.data._refCount = 1;
    sjt_call38.data.datasize = 22;
    sjt_call38.data.data = (void*)sjg_string19;
    sjt_call38.data._isglobal = true;
    sjt_call38.data.count = 22;
    sjf_array_char(&sjt_call38.data);
    sjf_string(&sjt_call38);
    sjt_functionParam255 = &sjt_call38;
    sjf_texturefrompng(sjt_functionParam255, &sjt_call37);
    sjt_functionParam254 = &sjt_call37;
    sjf_array_texture_initat(sjt_parent101, sjt_functionParam253, sjt_functionParam254);
    sjt_parent102 = array6;
    sjt_functionParam256 = 1;
    sjt_call40._refCount = 1;
    sjt_call40.count = 21;
    sjt_call40.data._refCount = 1;
    sjt_call40.data.datasize = 22;
    sjt_call40.data.data = (void*)sjg_string20;
    sjt_call40.data._isglobal = true;
    sjt_call40.data.count = 22;
    sjf_array_char(&sjt_call40.data);
    sjf_string(&sjt_call40);
    sjt_functionParam258 = &sjt_call40;
    sjf_texturefrompng(sjt_functionParam258, &sjt_call39);
    sjt_functionParam257 = &sjt_call39;
    sjf_array_texture_initat(sjt_parent102, sjt_functionParam256, sjt_functionParam257);
    sjt_parent103 = array6;
    sjt_functionParam259 = 2;
    sjt_call42._refCount = 1;
    sjt_call42.count = 21;
    sjt_call42.data._refCount = 1;
    sjt_call42.data.datasize = 22;
    sjt_call42.data.data = (void*)sjg_string21;
    sjt_call42.data._isglobal = true;
    sjt_call42.data.count = 22;
    sjf_array_char(&sjt_call42.data);
    sjf_string(&sjt_call42);
    sjt_functionParam261 = &sjt_call42;
    sjf_texturefrompng(sjt_functionParam261, &sjt_call41);
    sjt_functionParam260 = &sjt_call41;
    sjf_array_texture_initat(sjt_parent103, sjt_functionParam259, sjt_functionParam260);
    sjt_parent104 = array6;
    sjt_functionParam262 = 3;
    sjt_call44._refCount = 1;
    sjt_call44.count = 21;
    sjt_call44.data._refCount = 1;
    sjt_call44.data.datasize = 22;
    sjt_call44.data.data = (void*)sjg_string22;
    sjt_call44.data._isglobal = true;
    sjt_call44.data.count = 22;
    sjf_array_char(&sjt_call44.data);
    sjf_string(&sjt_call44);
    sjt_functionParam264 = &sjt_call44;
    sjf_texturefrompng(sjt_functionParam264, &sjt_call43);
    sjt_functionParam263 = &sjt_call43;
    sjf_array_texture_initat(sjt_parent104, sjt_functionParam262, sjt_functionParam263);
    sjt_parent105 = array6;
    sjt_functionParam265 = 4;
    sjt_call46._refCount = 1;
    sjt_call46.count = 21;
    sjt_call46.data._refCount = 1;
    sjt_call46.data.datasize = 22;
    sjt_call46.data.data = (void*)sjg_string23;
    sjt_call46.data._isglobal = true;
    sjt_call46.data.count = 22;
    sjf_array_char(&sjt_call46.data);
    sjf_string(&sjt_call46);
    sjt_functionParam267 = &sjt_call46;
    sjf_texturefrompng(sjt_functionParam267, &sjt_call45);
    sjt_functionParam266 = &sjt_call45;
    sjf_array_texture_initat(sjt_parent105, sjt_functionParam265, sjt_functionParam266);
    sjt_parent106 = array6;
    sjt_functionParam268 = 5;
    sjt_call48._refCount = 1;
    sjt_call48.count = 21;
    sjt_call48.data._refCount = 1;
    sjt_call48.data.datasize = 22;
    sjt_call48.data.data = (void*)sjg_string24;
    sjt_call48.data._isglobal = true;
    sjt_call48.data.count = 22;
    sjf_array_char(&sjt_call48.data);
    sjf_string(&sjt_call48);
    sjt_functionParam270 = &sjt_call48;
    sjf_texturefrompng(sjt_functionParam270, &sjt_call47);
    sjt_functionParam269 = &sjt_call47;
    sjf_array_texture_initat(sjt_parent106, sjt_functionParam268, sjt_functionParam269);
    sjt_parent107 = array6;
    sjt_functionParam271 = 6;
    sjt_call50._refCount = 1;
    sjt_call50.count = 21;
    sjt_call50.data._refCount = 1;
    sjt_call50.data.datasize = 22;
    sjt_call50.data.data = (void*)sjg_string25;
    sjt_call50.data._isglobal = true;
    sjt_call50.data.count = 22;
    sjf_array_char(&sjt_call50.data);
    sjf_string(&sjt_call50);
    sjt_functionParam273 = &sjt_call50;
    sjf_texturefrompng(sjt_functionParam273, &sjt_call49);
    sjt_functionParam272 = &sjt_call49;
    sjf_array_texture_initat(sjt_parent107, sjt_functionParam271, sjt_functionParam272);
    sjt_parent108 = array6;
    sjt_functionParam274 = 7;
    sjt_call52._refCount = 1;
    sjt_call52.count = 21;
    sjt_call52.data._refCount = 1;
    sjt_call52.data.datasize = 22;
    sjt_call52.data.data = (void*)sjg_string26;
    sjt_call52.data._isglobal = true;
    sjt_call52.data.count = 22;
    sjf_array_char(&sjt_call52.data);
    sjf_string(&sjt_call52);
    sjt_functionParam276 = &sjt_call52;
    sjf_texturefrompng(sjt_functionParam276, &sjt_call51);
    sjt_functionParam275 = &sjt_call51;
    sjf_array_texture_initat(sjt_parent108, sjt_functionParam274, sjt_functionParam275);
    sjt_cast13->children._refCount = 1;
    sjt_cast13->children.datasize = 0;
    sjt_cast13->children.data = 0;
    sjt_cast13->children._isglobal = false;
    sjt_cast13->children.count = 0;
    sjf_array_heap_model(&sjt_cast13->children);
    sjt_cast13->_angle = 0.1f;
    sjf_leafpanel_heap(sjt_cast13);
    sjt_functionParam209 = (sji_model*)sjf_leafpanel_heap_as_sji_model(sjt_cast13);
    sjf_array_heap_model_initat(sjt_parent78, sjt_functionParam208, sjt_functionParam209);
    sjt_parent109 = array5;
    sjt_functionParam277 = 2;
    sjt_cast19 = (sjs_peoplepanel*)malloc(sizeof(sjs_peoplepanel));
    sjt_cast19->_refCount = 1;
    sjt_functionParam301 = 0.0f;
    sjt_functionParam302 = 0.0f;
    sjt_functionParam303 = 0.0f;
    sjf_mat4_translate(sjt_functionParam301, sjt_functionParam302, sjt_functionParam303, &sjt_cast19->model);
    sjt_cast19->children._refCount = 1;
    sjt_cast19->children.datasize = 2;
    sjt_cast19->children.data = 0;
    sjt_cast19->children._isglobal = false;
    sjt_cast19->children.count = 0;
    sjf_array_heap_model(&sjt_cast19->children);
    sjs_array_heap_model* array8;
    array8 = &sjt_cast19->children;
    sjt_parent121 = array8;
    sjt_functionParam304 = 0;
    sjt_cast30 = (sjs_scene2dmodel*)malloc(sizeof(sjs_scene2dmodel));
    sjt_cast30->_refCount = 1;
    sjt_negate21 = 1.0f;
    result24 = -sjt_negate21;
    sjt_functionParam470 = result24;
    sjt_functionParam471 = 1.0f;
    sjt_negate22 = 1.0f;
    result25 = -sjt_negate22;
    sjt_functionParam472 = result25;
    sjt_functionParam473 = 1.0f;
    sjt_functionParam474 = 0.0f;
    sjt_functionParam475 = 0.0f;
    sjt_functionParam476 = 1.0f;
    sjt_functionParam477 = 0.0f;
    sjt_functionParam478 = 1.0f;
    sjf_planevertexbuffer(sjt_functionParam470, sjt_functionParam471, sjt_functionParam472, sjt_functionParam473, sjt_functionParam474, sjt_functionParam475, sjt_functionParam476, sjt_functionParam477, sjt_functionParam478, &sjt_cast30->vertexbuffer);
    sjt_copy33 = &sjv_phongtextureshader;
    sjt_cast30->shader._refCount = 1;
    sjf_shader_copy(&sjt_cast30->shader, sjt_copy33);
    sjt_cast30->texturesize._refCount = 1;
    sjt_cast30->texturesize.w = 512;
    sjt_cast30->texturesize.h = 512;
    sjf_size(&sjt_cast30->texturesize);
    sjt_cast30->children._refCount = 1;
    sjt_cast30->children.datasize = 3;
    sjt_cast30->children.data = 0;
    sjt_cast30->children._isglobal = false;
    sjt_cast30->children.count = 0;
    sjf_array_heap_element(&sjt_cast30->children);
    sjs_array_heap_element* array7;
    array7 = &sjt_cast30->children;
    sjt_parent184 = array7;
    sjt_functionParam479 = 0;
    sjt_cast42 = (sjs_boxelement*)malloc(sizeof(sjs_boxelement));
    sjt_cast42->_refCount = 1;
    sjt_parent189 = &sjv_colors;
    sjf_anon4_white(sjt_parent189, &sjt_cast42->color);
    sjt_cast42->idealsize._refCount = 1;
    sjt_cast42->idealsize.w = 0;
    sjt_cast42->idealsize.h = 0;
    sjf_size(&sjt_cast42->idealsize);
    sjt_cast42->rect._refCount = 1;
    sjt_cast42->rect.x = 0;
    sjt_cast42->rect.y = 0;
    sjt_cast42->rect.w = 0;
    sjt_cast42->rect.h = 0;
    sjf_rect(&sjt_cast42->rect);
    sjt_cast42->boxrenderer._refCount = -1;
    sjf_boxelement_heap(sjt_cast42);
    sjt_functionParam480 = (sji_element*)sjf_boxelement_heap_as_sji_element(sjt_cast42);
    sjf_array_heap_element_initat(sjt_parent184, sjt_functionParam479, sjt_functionParam480);
    sjt_parent190 = array7;
    sjt_functionParam485 = 1;
    sjt_cast43 = (sjs_imageelement*)malloc(sizeof(sjs_imageelement));
    sjt_cast43->_refCount = 1;
    sjt_cast43->image._refCount = 1;
    sjt_call75._refCount = 1;
    sjt_call75.count = 24;
    sjt_call75.data._refCount = 1;
    sjt_call75.data.datasize = 25;
    sjt_call75.data.data = (void*)sjg_string29;
    sjt_call75.data._isglobal = true;
    sjt_call75.data.count = 25;
    sjf_array_char(&sjt_call75.data);
    sjf_string(&sjt_call75);
    sjt_functionParam490 = &sjt_call75;
    sjf_texturefrompng(sjt_functionParam490, &sjt_cast43->image.texture);
    sjt_cast43->image.rect._refCount = 1;
    sjt_cast43->image.rect.x = 0;
    sjt_cast43->image.rect.y = 0;
    sjt_cast43->image.rect.w = 0;
    sjt_cast43->image.rect.h = 0;
    sjf_rect(&sjt_cast43->image.rect);
    sjt_cast43->image.margin._refCount = 1;
    sjt_cast43->image.margin.l = 0;
    sjt_cast43->image.margin.t = 0;
    sjt_cast43->image.margin.r = 0;
    sjt_cast43->image.margin.b = 0;
    sjf_margin(&sjt_cast43->image.margin);
    sjf_image(&sjt_cast43->image);
    sjt_cast43->_rect._refCount = 1;
    sjt_cast43->_rect.x = 0;
    sjt_cast43->_rect.y = 0;
    sjt_cast43->_rect.w = 0;
    sjt_cast43->_rect.h = 0;
    sjf_rect(&sjt_cast43->_rect);
    sjt_cast43->_margin._refCount = 1;
    sjt_cast43->_margin.l = 10;
    sjt_cast43->_margin.t = 10;
    sjt_cast43->_margin.r = 10;
    sjt_cast43->_margin.b = 10;
    sjf_margin(&sjt_cast43->_margin);
    sjt_cast43->_imagerenderer._refCount = -1;
    sjf_imageelement_heap(sjt_cast43);
    sjt_functionParam486 = (sji_element*)sjf_imageelement_heap_as_sji_element(sjt_cast43);
    sjf_array_heap_element_initat(sjt_parent190, sjt_functionParam485, sjt_functionParam486);
    sjt_parent196 = array7;
    sjt_functionParam491 = 2;
    sjt_cast44 = (sjs_crosshairselement*)malloc(sizeof(sjs_crosshairselement));
    sjt_cast44->_refCount = 1;
    sjt_parent201 = &sjv_colors;
    sjf_anon4_blue(sjt_parent201, &sjt_cast44->color);
    sjt_cast44->_rect._refCount = 1;
    sjt_cast44->_rect.x = 0;
    sjt_cast44->_rect.y = 0;
    sjt_cast44->_rect.w = 0;
    sjt_cast44->_rect.h = 0;
    sjf_rect(&sjt_cast44->_rect);
    sjt_cast44->_topdownrenderer._refCount = -1;
    sjt_cast44->_leftrightrenderer._refCount = -1;
    sjt_cast44->_point._refCount = 1;
    sjt_cast44->_point.x = 0;
    sjt_cast44->_point.y = 0;
    sjf_point(&sjt_cast44->_point);
    sjf_crosshairselement_heap(sjt_cast44);
    sjt_functionParam492 = (sji_element*)sjf_crosshairselement_heap_as_sji_element(sjt_cast44);
    sjf_array_heap_element_initat(sjt_parent196, sjt_functionParam491, sjt_functionParam492);
    sjt_cast30->hasalpha = false;
    sjt_cast30->center._refCount = 1;
    sjt_cast30->center.x = 0.0f;
    sjt_cast30->center.y = 0.0f;
    sjt_cast30->center.z = 0.0f;
    sjf_vec3(&sjt_cast30->center);
    sjf_mat4_identity(&sjt_cast30->model);
    sjt_cast30->_innerscene._refCount = 1;
    sjt_cast30->_innerscene._size._refCount = 1;
    sjt_cast30->_innerscene._size.w = 0;
    sjt_cast30->_innerscene._size.h = 0;
    sjf_size(&sjt_cast30->_innerscene._size);
    sjt_cast30->_innerscene.model._refCount = 1;
    sjt_cast30->_innerscene.model.m00 = 0.0f;
    sjt_cast30->_innerscene.model.m01 = 0.0f;
    sjt_cast30->_innerscene.model.m02 = 0.0f;
    sjt_cast30->_innerscene.model.m03 = 0.0f;
    sjt_cast30->_innerscene.model.m10 = 0.0f;
    sjt_cast30->_innerscene.model.m11 = 0.0f;
    sjt_cast30->_innerscene.model.m12 = 0.0f;
    sjt_cast30->_innerscene.model.m13 = 0.0f;
    sjt_cast30->_innerscene.model.m20 = 0.0f;
    sjt_cast30->_innerscene.model.m21 = 0.0f;
    sjt_cast30->_innerscene.model.m22 = 0.0f;
    sjt_cast30->_innerscene.model.m23 = 0.0f;
    sjt_cast30->_innerscene.model.m30 = 0.0f;
    sjt_cast30->_innerscene.model.m31 = 0.0f;
    sjt_cast30->_innerscene.model.m32 = 0.0f;
    sjt_cast30->_innerscene.model.m33 = 0.0f;
    sjf_mat4(&sjt_cast30->_innerscene.model);
    sjt_cast30->_innerscene.view._refCount = 1;
    sjt_cast30->_innerscene.view.m00 = 0.0f;
    sjt_cast30->_innerscene.view.m01 = 0.0f;
    sjt_cast30->_innerscene.view.m02 = 0.0f;
    sjt_cast30->_innerscene.view.m03 = 0.0f;
    sjt_cast30->_innerscene.view.m10 = 0.0f;
    sjt_cast30->_innerscene.view.m11 = 0.0f;
    sjt_cast30->_innerscene.view.m12 = 0.0f;
    sjt_cast30->_innerscene.view.m13 = 0.0f;
    sjt_cast30->_innerscene.view.m20 = 0.0f;
    sjt_cast30->_innerscene.view.m21 = 0.0f;
    sjt_cast30->_innerscene.view.m22 = 0.0f;
    sjt_cast30->_innerscene.view.m23 = 0.0f;
    sjt_cast30->_innerscene.view.m30 = 0.0f;
    sjt_cast30->_innerscene.view.m31 = 0.0f;
    sjt_cast30->_innerscene.view.m32 = 0.0f;
    sjt_cast30->_innerscene.view.m33 = 0.0f;
    sjf_mat4(&sjt_cast30->_innerscene.view);
    sjt_cast30->_innerscene.projection._refCount = 1;
    sjt_cast30->_innerscene.projection.m00 = 0.0f;
    sjt_cast30->_innerscene.projection.m01 = 0.0f;
    sjt_cast30->_innerscene.projection.m02 = 0.0f;
    sjt_cast30->_innerscene.projection.m03 = 0.0f;
    sjt_cast30->_innerscene.projection.m10 = 0.0f;
    sjt_cast30->_innerscene.projection.m11 = 0.0f;
    sjt_cast30->_innerscene.projection.m12 = 0.0f;
    sjt_cast30->_innerscene.projection.m13 = 0.0f;
    sjt_cast30->_innerscene.projection.m20 = 0.0f;
    sjt_cast30->_innerscene.projection.m21 = 0.0f;
    sjt_cast30->_innerscene.projection.m22 = 0.0f;
    sjt_cast30->_innerscene.projection.m23 = 0.0f;
    sjt_cast30->_innerscene.projection.m30 = 0.0f;
    sjt_cast30->_innerscene.projection.m31 = 0.0f;
    sjt_cast30->_innerscene.projection.m32 = 0.0f;
    sjt_cast30->_innerscene.projection.m33 = 0.0f;
    sjf_mat4(&sjt_cast30->_innerscene.projection);
    sjf_scene2d(&sjt_cast30->_innerscene);
    sjt_cast30->_scenerect._refCount = 1;
    sjt_cast30->_scenerect.x = 0;
    sjt_cast30->_scenerect.y = 0;
    sjt_cast30->_scenerect.w = 0;
    sjt_cast30->_scenerect.h = 0;
    sjf_rect(&sjt_cast30->_scenerect);
    sjt_cast30->_projection._refCount = 1;
    sjt_cast30->_projection.m00 = 0.0f;
    sjt_cast30->_projection.m01 = 0.0f;
    sjt_cast30->_projection.m02 = 0.0f;
    sjt_cast30->_projection.m03 = 0.0f;
    sjt_cast30->_projection.m10 = 0.0f;
    sjt_cast30->_projection.m11 = 0.0f;
    sjt_cast30->_projection.m12 = 0.0f;
    sjt_cast30->_projection.m13 = 0.0f;
    sjt_cast30->_projection.m20 = 0.0f;
    sjt_cast30->_projection.m21 = 0.0f;
    sjt_cast30->_projection.m22 = 0.0f;
    sjt_cast30->_projection.m23 = 0.0f;
    sjt_cast30->_projection.m30 = 0.0f;
    sjt_cast30->_projection.m31 = 0.0f;
    sjt_cast30->_projection.m32 = 0.0f;
    sjt_cast30->_projection.m33 = 0.0f;
    sjf_mat4(&sjt_cast30->_projection);
    sjt_cast30->_world._refCount = 1;
    sjt_cast30->_world.m00 = 0.0f;
    sjt_cast30->_world.m01 = 0.0f;
    sjt_cast30->_world.m02 = 0.0f;
    sjt_cast30->_world.m03 = 0.0f;
    sjt_cast30->_world.m10 = 0.0f;
    sjt_cast30->_world.m11 = 0.0f;
    sjt_cast30->_world.m12 = 0.0f;
    sjt_cast30->_world.m13 = 0.0f;
    sjt_cast30->_world.m20 = 0.0f;
    sjt_cast30->_world.m21 = 0.0f;
    sjt_cast30->_world.m22 = 0.0f;
    sjt_cast30->_world.m23 = 0.0f;
    sjt_cast30->_world.m30 = 0.0f;
    sjt_cast30->_world.m31 = 0.0f;
    sjt_cast30->_world.m32 = 0.0f;
    sjt_cast30->_world.m33 = 0.0f;
    sjf_mat4(&sjt_cast30->_world);
    sjt_cast30->_view._refCount = 1;
    sjt_cast30->_view.m00 = 0.0f;
    sjt_cast30->_view.m01 = 0.0f;
    sjt_cast30->_view.m02 = 0.0f;
    sjt_cast30->_view.m03 = 0.0f;
    sjt_cast30->_view.m10 = 0.0f;
    sjt_cast30->_view.m11 = 0.0f;
    sjt_cast30->_view.m12 = 0.0f;
    sjt_cast30->_view.m13 = 0.0f;
    sjt_cast30->_view.m20 = 0.0f;
    sjt_cast30->_view.m21 = 0.0f;
    sjt_cast30->_view.m22 = 0.0f;
    sjt_cast30->_view.m23 = 0.0f;
    sjt_cast30->_view.m30 = 0.0f;
    sjt_cast30->_view.m31 = 0.0f;
    sjt_cast30->_view.m32 = 0.0f;
    sjt_cast30->_view.m33 = 0.0f;
    sjf_mat4(&sjt_cast30->_view);
    sjt_cast30->_light._refCount = 1;
    sjt_cast30->_light.pos._refCount = 1;
    sjt_cast30->_light.pos.x = 1.0f;
    sjt_cast30->_light.pos.y = 1.0f;
    sjt_cast30->_light.pos.z = 1.0f;
    sjf_vec3(&sjt_cast30->_light.pos);
    sjt_cast30->_light.diffusecolor._refCount = 1;
    sjt_cast30->_light.diffusecolor.r = 0.5f;
    sjt_cast30->_light.diffusecolor.g = 0.5f;
    sjt_cast30->_light.diffusecolor.b = 0.0f;
    sjt_cast30->_light.diffusecolor.a = 1.0f;
    sjf_color(&sjt_cast30->_light.diffusecolor);
    sjt_cast30->_light.speccolor._refCount = 1;
    sjt_cast30->_light.speccolor.r = 1.0f;
    sjt_cast30->_light.speccolor.g = 1.0f;
    sjt_cast30->_light.speccolor.b = 1.0f;
    sjt_cast30->_light.speccolor.a = 1.0f;
    sjf_color(&sjt_cast30->_light.speccolor);
    sjf_light(&sjt_cast30->_light);
    sjt_cast30->_projectedcenter._refCount = 1;
    sjt_cast30->_projectedcenter.x = 0.0f;
    sjt_cast30->_projectedcenter.y = 0.0f;
    sjt_cast30->_projectedcenter.z = 0.0f;
    sjt_cast30->_projectedcenter.w = 0.0f;
    sjf_vec4(&sjt_cast30->_projectedcenter);
    sjf_glgenframebuffer(&sjt_cast30->_framebuffer);
    sjt_cast30->_texture._refCount = 1;
    sjt_cast30->_texture.size._refCount = 1;
    sjt_cast30->_texture.size.w = 0;
    sjt_cast30->_texture.size.h = 0;
    sjf_size(&sjt_cast30->_texture.size);
    sjt_cast30->_texture.id = (uint32_t)0u;
    sjf_texture(&sjt_cast30->_texture);
    sjt_cast30->_renderbuffer._refCount = 1;
    sjt_cast30->_renderbuffer.size._refCount = 1;
    sjt_cast30->_renderbuffer.size.w = 0;
    sjt_cast30->_renderbuffer.size.h = 0;
    sjf_size(&sjt_cast30->_renderbuffer.size);
    sjt_cast30->_renderbuffer.id = (uint32_t)0u;
    sjf_renderbuffer(&sjt_cast30->_renderbuffer);
    sjf_scene2dmodel_heap(sjt_cast30);
    sjt_functionParam305 = (sji_model*)sjf_scene2dmodel_heap_as_sji_model(sjt_cast30);
    sjf_array_heap_model_initat(sjt_parent121, sjt_functionParam304, sjt_functionParam305);
    sjt_parent202 = array8;
    sjt_functionParam497 = 1;
    sjt_cast45 = (sjs_scene2dmodel*)malloc(sizeof(sjs_scene2dmodel));
    sjt_cast45->_refCount = 1;
    sjt_negate23 = 1.0f;
    result33 = -sjt_negate23;
    sjt_functionParam499 = result33;
    sjt_functionParam500 = 1.0f;
    sjt_negate24 = 1.0f;
    result34 = -sjt_negate24;
    sjt_functionParam501 = result34;
    sjt_functionParam502 = 1.0f;
    sjt_functionParam503 = 0.0f;
    sjt_functionParam504 = 0.0f;
    sjt_functionParam505 = 1.0f;
    sjt_functionParam506 = 0.0f;
    sjt_functionParam507 = 1.0f;
    sjf_planevertexbuffer(sjt_functionParam499, sjt_functionParam500, sjt_functionParam501, sjt_functionParam502, sjt_functionParam503, sjt_functionParam504, sjt_functionParam505, sjt_functionParam506, sjt_functionParam507, &sjt_cast45->vertexbuffer);
    sjt_copy45 = &sjv_phongtextureshader;
    sjt_cast45->shader._refCount = 1;
    sjf_shader_copy(&sjt_cast45->shader, sjt_copy45);
    sjt_cast45->texturesize._refCount = 1;
    sjt_cast45->texturesize.w = 512;
    sjt_cast45->texturesize.h = 512;
    sjf_size(&sjt_cast45->texturesize);
    sjt_cast45->children._refCount = 1;
    sjt_cast45->children.datasize = 3;
    sjt_cast45->children.data = 0;
    sjt_cast45->children._isglobal = false;
    sjt_cast45->children.count = 0;
    sjf_array_heap_element(&sjt_cast45->children);
    sjs_array_heap_element* array9;
    array9 = &sjt_cast45->children;
    sjt_parent203 = array9;
    sjt_functionParam508 = 0;
    sjt_cast46 = (sjs_boxelement*)malloc(sizeof(sjs_boxelement));
    sjt_cast46->_refCount = 1;
    sjt_parent204 = &sjv_colors;
    sjf_anon4_white(sjt_parent204, &sjt_cast46->color);
    sjt_cast46->idealsize._refCount = 1;
    sjt_cast46->idealsize.w = 0;
    sjt_cast46->idealsize.h = 0;
    sjf_size(&sjt_cast46->idealsize);
    sjt_cast46->rect._refCount = 1;
    sjt_cast46->rect.x = 0;
    sjt_cast46->rect.y = 0;
    sjt_cast46->rect.w = 0;
    sjt_cast46->rect.h = 0;
    sjf_rect(&sjt_cast46->rect);
    sjt_cast46->boxrenderer._refCount = -1;
    sjf_boxelement_heap(sjt_cast46);
    sjt_functionParam509 = (sji_element*)sjf_boxelement_heap_as_sji_element(sjt_cast46);
    sjf_array_heap_element_initat(sjt_parent203, sjt_functionParam508, sjt_functionParam509);
    sjt_parent205 = array9;
    sjt_functionParam510 = 1;
    sjt_cast47 = (sjs_imageelement*)malloc(sizeof(sjs_imageelement));
    sjt_cast47->_refCount = 1;
    sjt_cast47->image._refCount = 1;
    sjt_call76._refCount = 1;
    sjt_call76.count = 24;
    sjt_call76.data._refCount = 1;
    sjt_call76.data.datasize = 25;
    sjt_call76.data.data = (void*)sjg_string30;
    sjt_call76.data._isglobal = true;
    sjt_call76.data.count = 25;
    sjf_array_char(&sjt_call76.data);
    sjf_string(&sjt_call76);
    sjt_functionParam512 = &sjt_call76;
    sjf_texturefrompng(sjt_functionParam512, &sjt_cast47->image.texture);
    sjt_cast47->image.rect._refCount = 1;
    sjt_cast47->image.rect.x = 0;
    sjt_cast47->image.rect.y = 0;
    sjt_cast47->image.rect.w = 0;
    sjt_cast47->image.rect.h = 0;
    sjf_rect(&sjt_cast47->image.rect);
    sjt_cast47->image.margin._refCount = 1;
    sjt_cast47->image.margin.l = 0;
    sjt_cast47->image.margin.t = 0;
    sjt_cast47->image.margin.r = 0;
    sjt_cast47->image.margin.b = 0;
    sjf_margin(&sjt_cast47->image.margin);
    sjf_image(&sjt_cast47->image);
    sjt_cast47->_rect._refCount = 1;
    sjt_cast47->_rect.x = 0;
    sjt_cast47->_rect.y = 0;
    sjt_cast47->_rect.w = 0;
    sjt_cast47->_rect.h = 0;
    sjf_rect(&sjt_cast47->_rect);
    sjt_cast47->_margin._refCount = 1;
    sjt_cast47->_margin.l = 10;
    sjt_cast47->_margin.t = 10;
    sjt_cast47->_margin.r = 10;
    sjt_cast47->_margin.b = 10;
    sjf_margin(&sjt_cast47->_margin);
    sjt_cast47->_imagerenderer._refCount = -1;
    sjf_imageelement_heap(sjt_cast47);
    sjt_functionParam511 = (sji_element*)sjf_imageelement_heap_as_sji_element(sjt_cast47);
    sjf_array_heap_element_initat(sjt_parent205, sjt_functionParam510, sjt_functionParam511);
    sjt_parent206 = array9;
    sjt_functionParam513 = 2;
    sjt_cast48 = (sjs_crosshairselement*)malloc(sizeof(sjs_crosshairselement));
    sjt_cast48->_refCount = 1;
    sjt_parent207 = &sjv_colors;
    sjf_anon4_green(sjt_parent207, &sjt_cast48->color);
    sjt_cast48->_rect._refCount = 1;
    sjt_cast48->_rect.x = 0;
    sjt_cast48->_rect.y = 0;
    sjt_cast48->_rect.w = 0;
    sjt_cast48->_rect.h = 0;
    sjf_rect(&sjt_cast48->_rect);
    sjt_cast48->_topdownrenderer._refCount = -1;
    sjt_cast48->_leftrightrenderer._refCount = -1;
    sjt_cast48->_point._refCount = 1;
    sjt_cast48->_point.x = 0;
    sjt_cast48->_point.y = 0;
    sjf_point(&sjt_cast48->_point);
    sjf_crosshairselement_heap(sjt_cast48);
    sjt_functionParam514 = (sji_element*)sjf_crosshairselement_heap_as_sji_element(sjt_cast48);
    sjf_array_heap_element_initat(sjt_parent206, sjt_functionParam513, sjt_functionParam514);
    sjt_cast45->hasalpha = false;
    sjt_cast45->center._refCount = 1;
    sjt_cast45->center.x = 0.0f;
    sjt_cast45->center.y = 0.0f;
    sjt_cast45->center.z = 0.0f;
    sjf_vec3(&sjt_cast45->center);
    sjf_mat4_identity(&sjt_cast45->model);
    sjt_cast45->_innerscene._refCount = 1;
    sjt_cast45->_innerscene._size._refCount = 1;
    sjt_cast45->_innerscene._size.w = 0;
    sjt_cast45->_innerscene._size.h = 0;
    sjf_size(&sjt_cast45->_innerscene._size);
    sjt_cast45->_innerscene.model._refCount = 1;
    sjt_cast45->_innerscene.model.m00 = 0.0f;
    sjt_cast45->_innerscene.model.m01 = 0.0f;
    sjt_cast45->_innerscene.model.m02 = 0.0f;
    sjt_cast45->_innerscene.model.m03 = 0.0f;
    sjt_cast45->_innerscene.model.m10 = 0.0f;
    sjt_cast45->_innerscene.model.m11 = 0.0f;
    sjt_cast45->_innerscene.model.m12 = 0.0f;
    sjt_cast45->_innerscene.model.m13 = 0.0f;
    sjt_cast45->_innerscene.model.m20 = 0.0f;
    sjt_cast45->_innerscene.model.m21 = 0.0f;
    sjt_cast45->_innerscene.model.m22 = 0.0f;
    sjt_cast45->_innerscene.model.m23 = 0.0f;
    sjt_cast45->_innerscene.model.m30 = 0.0f;
    sjt_cast45->_innerscene.model.m31 = 0.0f;
    sjt_cast45->_innerscene.model.m32 = 0.0f;
    sjt_cast45->_innerscene.model.m33 = 0.0f;
    sjf_mat4(&sjt_cast45->_innerscene.model);
    sjt_cast45->_innerscene.view._refCount = 1;
    sjt_cast45->_innerscene.view.m00 = 0.0f;
    sjt_cast45->_innerscene.view.m01 = 0.0f;
    sjt_cast45->_innerscene.view.m02 = 0.0f;
    sjt_cast45->_innerscene.view.m03 = 0.0f;
    sjt_cast45->_innerscene.view.m10 = 0.0f;
    sjt_cast45->_innerscene.view.m11 = 0.0f;
    sjt_cast45->_innerscene.view.m12 = 0.0f;
    sjt_cast45->_innerscene.view.m13 = 0.0f;
    sjt_cast45->_innerscene.view.m20 = 0.0f;
    sjt_cast45->_innerscene.view.m21 = 0.0f;
    sjt_cast45->_innerscene.view.m22 = 0.0f;
    sjt_cast45->_innerscene.view.m23 = 0.0f;
    sjt_cast45->_innerscene.view.m30 = 0.0f;
    sjt_cast45->_innerscene.view.m31 = 0.0f;
    sjt_cast45->_innerscene.view.m32 = 0.0f;
    sjt_cast45->_innerscene.view.m33 = 0.0f;
    sjf_mat4(&sjt_cast45->_innerscene.view);
    sjt_cast45->_innerscene.projection._refCount = 1;
    sjt_cast45->_innerscene.projection.m00 = 0.0f;
    sjt_cast45->_innerscene.projection.m01 = 0.0f;
    sjt_cast45->_innerscene.projection.m02 = 0.0f;
    sjt_cast45->_innerscene.projection.m03 = 0.0f;
    sjt_cast45->_innerscene.projection.m10 = 0.0f;
    sjt_cast45->_innerscene.projection.m11 = 0.0f;
    sjt_cast45->_innerscene.projection.m12 = 0.0f;
    sjt_cast45->_innerscene.projection.m13 = 0.0f;
    sjt_cast45->_innerscene.projection.m20 = 0.0f;
    sjt_cast45->_innerscene.projection.m21 = 0.0f;
    sjt_cast45->_innerscene.projection.m22 = 0.0f;
    sjt_cast45->_innerscene.projection.m23 = 0.0f;
    sjt_cast45->_innerscene.projection.m30 = 0.0f;
    sjt_cast45->_innerscene.projection.m31 = 0.0f;
    sjt_cast45->_innerscene.projection.m32 = 0.0f;
    sjt_cast45->_innerscene.projection.m33 = 0.0f;
    sjf_mat4(&sjt_cast45->_innerscene.projection);
    sjf_scene2d(&sjt_cast45->_innerscene);
    sjt_cast45->_scenerect._refCount = 1;
    sjt_cast45->_scenerect.x = 0;
    sjt_cast45->_scenerect.y = 0;
    sjt_cast45->_scenerect.w = 0;
    sjt_cast45->_scenerect.h = 0;
    sjf_rect(&sjt_cast45->_scenerect);
    sjt_cast45->_projection._refCount = 1;
    sjt_cast45->_projection.m00 = 0.0f;
    sjt_cast45->_projection.m01 = 0.0f;
    sjt_cast45->_projection.m02 = 0.0f;
    sjt_cast45->_projection.m03 = 0.0f;
    sjt_cast45->_projection.m10 = 0.0f;
    sjt_cast45->_projection.m11 = 0.0f;
    sjt_cast45->_projection.m12 = 0.0f;
    sjt_cast45->_projection.m13 = 0.0f;
    sjt_cast45->_projection.m20 = 0.0f;
    sjt_cast45->_projection.m21 = 0.0f;
    sjt_cast45->_projection.m22 = 0.0f;
    sjt_cast45->_projection.m23 = 0.0f;
    sjt_cast45->_projection.m30 = 0.0f;
    sjt_cast45->_projection.m31 = 0.0f;
    sjt_cast45->_projection.m32 = 0.0f;
    sjt_cast45->_projection.m33 = 0.0f;
    sjf_mat4(&sjt_cast45->_projection);
    sjt_cast45->_world._refCount = 1;
    sjt_cast45->_world.m00 = 0.0f;
    sjt_cast45->_world.m01 = 0.0f;
    sjt_cast45->_world.m02 = 0.0f;
    sjt_cast45->_world.m03 = 0.0f;
    sjt_cast45->_world.m10 = 0.0f;
    sjt_cast45->_world.m11 = 0.0f;
    sjt_cast45->_world.m12 = 0.0f;
    sjt_cast45->_world.m13 = 0.0f;
    sjt_cast45->_world.m20 = 0.0f;
    sjt_cast45->_world.m21 = 0.0f;
    sjt_cast45->_world.m22 = 0.0f;
    sjt_cast45->_world.m23 = 0.0f;
    sjt_cast45->_world.m30 = 0.0f;
    sjt_cast45->_world.m31 = 0.0f;
    sjt_cast45->_world.m32 = 0.0f;
    sjt_cast45->_world.m33 = 0.0f;
    sjf_mat4(&sjt_cast45->_world);
    sjt_cast45->_view._refCount = 1;
    sjt_cast45->_view.m00 = 0.0f;
    sjt_cast45->_view.m01 = 0.0f;
    sjt_cast45->_view.m02 = 0.0f;
    sjt_cast45->_view.m03 = 0.0f;
    sjt_cast45->_view.m10 = 0.0f;
    sjt_cast45->_view.m11 = 0.0f;
    sjt_cast45->_view.m12 = 0.0f;
    sjt_cast45->_view.m13 = 0.0f;
    sjt_cast45->_view.m20 = 0.0f;
    sjt_cast45->_view.m21 = 0.0f;
    sjt_cast45->_view.m22 = 0.0f;
    sjt_cast45->_view.m23 = 0.0f;
    sjt_cast45->_view.m30 = 0.0f;
    sjt_cast45->_view.m31 = 0.0f;
    sjt_cast45->_view.m32 = 0.0f;
    sjt_cast45->_view.m33 = 0.0f;
    sjf_mat4(&sjt_cast45->_view);
    sjt_cast45->_light._refCount = 1;
    sjt_cast45->_light.pos._refCount = 1;
    sjt_cast45->_light.pos.x = 1.0f;
    sjt_cast45->_light.pos.y = 1.0f;
    sjt_cast45->_light.pos.z = 1.0f;
    sjf_vec3(&sjt_cast45->_light.pos);
    sjt_cast45->_light.diffusecolor._refCount = 1;
    sjt_cast45->_light.diffusecolor.r = 0.5f;
    sjt_cast45->_light.diffusecolor.g = 0.5f;
    sjt_cast45->_light.diffusecolor.b = 0.0f;
    sjt_cast45->_light.diffusecolor.a = 1.0f;
    sjf_color(&sjt_cast45->_light.diffusecolor);
    sjt_cast45->_light.speccolor._refCount = 1;
    sjt_cast45->_light.speccolor.r = 1.0f;
    sjt_cast45->_light.speccolor.g = 1.0f;
    sjt_cast45->_light.speccolor.b = 1.0f;
    sjt_cast45->_light.speccolor.a = 1.0f;
    sjf_color(&sjt_cast45->_light.speccolor);
    sjf_light(&sjt_cast45->_light);
    sjt_cast45->_projectedcenter._refCount = 1;
    sjt_cast45->_projectedcenter.x = 0.0f;
    sjt_cast45->_projectedcenter.y = 0.0f;
    sjt_cast45->_projectedcenter.z = 0.0f;
    sjt_cast45->_projectedcenter.w = 0.0f;
    sjf_vec4(&sjt_cast45->_projectedcenter);
    sjf_glgenframebuffer(&sjt_cast45->_framebuffer);
    sjt_cast45->_texture._refCount = 1;
    sjt_cast45->_texture.size._refCount = 1;
    sjt_cast45->_texture.size.w = 0;
    sjt_cast45->_texture.size.h = 0;
    sjf_size(&sjt_cast45->_texture.size);
    sjt_cast45->_texture.id = (uint32_t)0u;
    sjf_texture(&sjt_cast45->_texture);
    sjt_cast45->_renderbuffer._refCount = 1;
    sjt_cast45->_renderbuffer.size._refCount = 1;
    sjt_cast45->_renderbuffer.size.w = 0;
    sjt_cast45->_renderbuffer.size.h = 0;
    sjf_size(&sjt_cast45->_renderbuffer.size);
    sjt_cast45->_renderbuffer.id = (uint32_t)0u;
    sjf_renderbuffer(&sjt_cast45->_renderbuffer);
    sjf_scene2dmodel_heap(sjt_cast45);
    sjt_functionParam498 = (sji_model*)sjf_scene2dmodel_heap_as_sji_model(sjt_cast45);
    sjf_array_heap_model_initat(sjt_parent202, sjt_functionParam497, sjt_functionParam498);
    sjt_cast19->_childrenmodel._refCount = 1;
    sjt_cast19->_childrenmodel.datasize = 0;
    sjt_cast19->_childrenmodel.data = 0;
    sjt_cast19->_childrenmodel._isglobal = false;
    sjt_cast19->_childrenmodel.count = 0;
    sjf_array_mat4(&sjt_cast19->_childrenmodel);
    sjt_cast19->_index = 0;
    sjt_cast19->_depth = 4;
    sjt_cast19->_xincrement = 8.0f;
    sjt_cast19->_zincrement = 2.0f;
    sjt_cast19->_xoffset = 0.0f;
    sjf_peoplepanel_heap(sjt_cast19);
    sjt_functionParam278 = (sji_model*)sjf_peoplepanel_heap_as_sji_model(sjt_cast19);
    sjf_array_heap_model_initat(sjt_parent109, sjt_functionParam277, sjt_functionParam278);
    sjt_parent208 = array5;
    sjt_functionParam515 = 3;
    sjt_cast49 = (sjs_panel3d*)malloc(sizeof(sjs_panel3d));
    sjt_cast49->_refCount = 1;
    sjt_functionParam521 = 0.0f;
    sjt_negate25 = 1.3f;
    result35 = -sjt_negate25;
    sjt_functionParam522 = result35;
    sjt_functionParam523 = 0.0f;
    sjf_mat4_translate(sjt_functionParam521, sjt_functionParam522, sjt_functionParam523, &sjt_cast49->model);
    sjt_cast49->children._refCount = 1;
    sjt_cast49->children.datasize = 10;
    sjt_cast49->children.data = 0;
    sjt_cast49->children._isglobal = false;
    sjt_cast49->children.count = 0;
    sjf_array_heap_model(&sjt_cast49->children);
    sjs_array_heap_model* array10;
    array10 = &sjt_cast49->children;
    sjt_parent216 = array10;
    sjt_functionParam524 = 0;
    sjt_cast50 = (sjs_model*)malloc(sizeof(sjs_model));
    sjt_cast50->_refCount = 1;
    sjt_negate26 = 4.3f;
    result36 = -sjt_negate26;
    sjt_functionParam526 = result36;
    sjt_functionParam527 = 4.3f;
    sjt_negate27 = 1.0f;
    result37 = -sjt_negate27;
    sjt_functionParam528 = result37;
    sjt_functionParam529 = 1.0f;
    sjt_functionParam530 = 0.0f;
    sjt_functionParam531 = 0.0f;
    sjt_functionParam532 = 1.0f;
    sjt_functionParam533 = 0.0f;
    sjt_functionParam534 = 1.0f;
    sjf_planevertexbuffer(sjt_functionParam526, sjt_functionParam527, sjt_functionParam528, sjt_functionParam529, sjt_functionParam530, sjt_functionParam531, sjt_functionParam532, sjt_functionParam533, sjt_functionParam534, &sjt_cast50->vertexbuffer);
    sjt_copy46 = &sjv_phongtextureshader;
    sjt_cast50->shader._refCount = 1;
    sjf_shader_copy(&sjt_cast50->shader, sjt_copy46);
    sjt_call77._refCount = 1;
    sjt_call77.count = 16;
    sjt_call77.data._refCount = 1;
    sjt_call77.data.datasize = 17;
    sjt_call77.data.data = (void*)sjg_string32;
    sjt_call77.data._isglobal = true;
    sjt_call77.data.count = 17;
    sjf_array_char(&sjt_call77.data);
    sjf_string(&sjt_call77);
    sjt_functionParam535 = &sjt_call77;
    sjf_texturefrompng(sjt_functionParam535, &sjt_cast50->texture);
    sjt_negate28 = 8.6f;
    result38 = -sjt_negate28;
    sjt_functionParam536 = result38;
    sjt_functionParam537 = 0.0f;
    sjt_functionParam538 = 6.2f;
    sjf_mat4_translate(sjt_functionParam536, sjt_functionParam537, sjt_functionParam538, &sjt_call78);
    sjt_parent217 = &sjt_call78;
    sjt_functionParam540 = 2.0f;
    sjt_functionParam541 = 2.0f;
    sjt_functionParam542 = 2.0f;
    sjf_mat4_scale(sjt_functionParam540, sjt_functionParam541, sjt_functionParam542, &sjt_call79);
    sjt_functionParam539 = &sjt_call79;
    sjf_mat4_multiply(sjt_parent217, sjt_functionParam539, &sjt_cast50->model);
    sjt_cast50->center._refCount = 1;
    sjt_cast50->center.x = 0.0f;
    sjt_cast50->center.y = 0.0f;
    sjt_cast50->center.z = 0.0f;
    sjf_vec3(&sjt_cast50->center);
    sjt_cast50->hasalpha = true;
    sjt_cast50->id._refCount = 1;
    sjt_cast50->id.count = 8;
    sjt_cast50->id.data._refCount = 1;
    sjt_cast50->id.data.datasize = 9;
    sjt_cast50->id.data.data = (void*)sjg_string31;
    sjt_cast50->id.data._isglobal = true;
    sjt_cast50->id.data.count = 9;
    sjf_array_char(&sjt_cast50->id.data);
    sjf_string(&sjt_cast50->id);
    sjt_cast50->_projection._refCount = 1;
    sjt_cast50->_projection.m00 = 0.0f;
    sjt_cast50->_projection.m01 = 0.0f;
    sjt_cast50->_projection.m02 = 0.0f;
    sjt_cast50->_projection.m03 = 0.0f;
    sjt_cast50->_projection.m10 = 0.0f;
    sjt_cast50->_projection.m11 = 0.0f;
    sjt_cast50->_projection.m12 = 0.0f;
    sjt_cast50->_projection.m13 = 0.0f;
    sjt_cast50->_projection.m20 = 0.0f;
    sjt_cast50->_projection.m21 = 0.0f;
    sjt_cast50->_projection.m22 = 0.0f;
    sjt_cast50->_projection.m23 = 0.0f;
    sjt_cast50->_projection.m30 = 0.0f;
    sjt_cast50->_projection.m31 = 0.0f;
    sjt_cast50->_projection.m32 = 0.0f;
    sjt_cast50->_projection.m33 = 0.0f;
    sjf_mat4(&sjt_cast50->_projection);
    sjt_cast50->_view._refCount = 1;
    sjt_cast50->_view.m00 = 0.0f;
    sjt_cast50->_view.m01 = 0.0f;
    sjt_cast50->_view.m02 = 0.0f;
    sjt_cast50->_view.m03 = 0.0f;
    sjt_cast50->_view.m10 = 0.0f;
    sjt_cast50->_view.m11 = 0.0f;
    sjt_cast50->_view.m12 = 0.0f;
    sjt_cast50->_view.m13 = 0.0f;
    sjt_cast50->_view.m20 = 0.0f;
    sjt_cast50->_view.m21 = 0.0f;
    sjt_cast50->_view.m22 = 0.0f;
    sjt_cast50->_view.m23 = 0.0f;
    sjt_cast50->_view.m30 = 0.0f;
    sjt_cast50->_view.m31 = 0.0f;
    sjt_cast50->_view.m32 = 0.0f;
    sjt_cast50->_view.m33 = 0.0f;
    sjf_mat4(&sjt_cast50->_view);
    sjt_cast50->_world._refCount = 1;
    sjt_cast50->_world.m00 = 0.0f;
    sjt_cast50->_world.m01 = 0.0f;
    sjt_cast50->_world.m02 = 0.0f;
    sjt_cast50->_world.m03 = 0.0f;
    sjt_cast50->_world.m10 = 0.0f;
    sjt_cast50->_world.m11 = 0.0f;
    sjt_cast50->_world.m12 = 0.0f;
    sjt_cast50->_world.m13 = 0.0f;
    sjt_cast50->_world.m20 = 0.0f;
    sjt_cast50->_world.m21 = 0.0f;
    sjt_cast50->_world.m22 = 0.0f;
    sjt_cast50->_world.m23 = 0.0f;
    sjt_cast50->_world.m30 = 0.0f;
    sjt_cast50->_world.m31 = 0.0f;
    sjt_cast50->_world.m32 = 0.0f;
    sjt_cast50->_world.m33 = 0.0f;
    sjf_mat4(&sjt_cast50->_world);
    sjt_cast50->_light._refCount = 1;
    sjt_cast50->_light.pos._refCount = 1;
    sjt_cast50->_light.pos.x = 1.0f;
    sjt_cast50->_light.pos.y = 1.0f;
    sjt_cast50->_light.pos.z = 1.0f;
    sjf_vec3(&sjt_cast50->_light.pos);
    sjt_cast50->_light.diffusecolor._refCount = 1;
    sjt_cast50->_light.diffusecolor.r = 0.5f;
    sjt_cast50->_light.diffusecolor.g = 0.5f;
    sjt_cast50->_light.diffusecolor.b = 0.0f;
    sjt_cast50->_light.diffusecolor.a = 1.0f;
    sjf_color(&sjt_cast50->_light.diffusecolor);
    sjt_cast50->_light.speccolor._refCount = 1;
    sjt_cast50->_light.speccolor.r = 1.0f;
    sjt_cast50->_light.speccolor.g = 1.0f;
    sjt_cast50->_light.speccolor.b = 1.0f;
    sjt_cast50->_light.speccolor.a = 1.0f;
    sjf_color(&sjt_cast50->_light.speccolor);
    sjf_light(&sjt_cast50->_light);
    sjt_cast50->_projectedcenter._refCount = 1;
    sjt_cast50->_projectedcenter.x = 0.0f;
    sjt_cast50->_projectedcenter.y = 0.0f;
    sjt_cast50->_projectedcenter.z = 0.0f;
    sjf_vec3(&sjt_cast50->_projectedcenter);
    sjf_model_heap(sjt_cast50);
    sjt_functionParam525 = (sji_model*)sjf_model_heap_as_sji_model(sjt_cast50);
    sjf_array_heap_model_initat(sjt_parent216, sjt_functionParam524, sjt_functionParam525);
    sjt_parent218 = array10;
    sjt_functionParam543 = 1;
    sjt_cast51 = (sjs_model*)malloc(sizeof(sjs_model));
    sjt_cast51->_refCount = 1;
    sjt_negate29 = 4.3f;
    result39 = -sjt_negate29;
    sjt_functionParam545 = result39;
    sjt_functionParam546 = 4.3f;
    sjt_negate30 = 1.0f;
    result40 = -sjt_negate30;
    sjt_functionParam547 = result40;
    sjt_functionParam548 = 1.0f;
    sjt_functionParam549 = 0.0f;
    sjt_functionParam550 = 0.0f;
    sjt_functionParam551 = 1.0f;
    sjt_functionParam552 = 0.0f;
    sjt_functionParam553 = 1.0f;
    sjf_planevertexbuffer(sjt_functionParam545, sjt_functionParam546, sjt_functionParam547, sjt_functionParam548, sjt_functionParam549, sjt_functionParam550, sjt_functionParam551, sjt_functionParam552, sjt_functionParam553, &sjt_cast51->vertexbuffer);
    sjt_copy47 = &sjv_phongtextureshader;
    sjt_cast51->shader._refCount = 1;
    sjf_shader_copy(&sjt_cast51->shader, sjt_copy47);
    sjt_call80._refCount = 1;
    sjt_call80.count = 16;
    sjt_call80.data._refCount = 1;
    sjt_call80.data.datasize = 17;
    sjt_call80.data.data = (void*)sjg_string34;
    sjt_call80.data._isglobal = true;
    sjt_call80.data.count = 17;
    sjf_array_char(&sjt_call80.data);
    sjf_string(&sjt_call80);
    sjt_functionParam554 = &sjt_call80;
    sjf_texturefrompng(sjt_functionParam554, &sjt_cast51->texture);
    sjt_functionParam555 = 8.6f;
    sjt_functionParam556 = 0.0f;
    sjt_functionParam557 = 6.2f;
    sjf_mat4_translate(sjt_functionParam555, sjt_functionParam556, sjt_functionParam557, &sjt_call81);
    sjt_parent219 = &sjt_call81;
    sjt_functionParam559 = 2.0f;
    sjt_functionParam560 = 2.0f;
    sjt_functionParam561 = 2.0f;
    sjf_mat4_scale(sjt_functionParam559, sjt_functionParam560, sjt_functionParam561, &sjt_call82);
    sjt_functionParam558 = &sjt_call82;
    sjf_mat4_multiply(sjt_parent219, sjt_functionParam558, &sjt_cast51->model);
    sjt_cast51->center._refCount = 1;
    sjt_cast51->center.x = 0.0f;
    sjt_cast51->center.y = 0.0f;
    sjt_cast51->center.z = 0.0f;
    sjf_vec3(&sjt_cast51->center);
    sjt_cast51->hasalpha = true;
    sjt_cast51->id._refCount = 1;
    sjt_cast51->id.count = 8;
    sjt_cast51->id.data._refCount = 1;
    sjt_cast51->id.data.datasize = 9;
    sjt_cast51->id.data.data = (void*)sjg_string33;
    sjt_cast51->id.data._isglobal = true;
    sjt_cast51->id.data.count = 9;
    sjf_array_char(&sjt_cast51->id.data);
    sjf_string(&sjt_cast51->id);
    sjt_cast51->_projection._refCount = 1;
    sjt_cast51->_projection.m00 = 0.0f;
    sjt_cast51->_projection.m01 = 0.0f;
    sjt_cast51->_projection.m02 = 0.0f;
    sjt_cast51->_projection.m03 = 0.0f;
    sjt_cast51->_projection.m10 = 0.0f;
    sjt_cast51->_projection.m11 = 0.0f;
    sjt_cast51->_projection.m12 = 0.0f;
    sjt_cast51->_projection.m13 = 0.0f;
    sjt_cast51->_projection.m20 = 0.0f;
    sjt_cast51->_projection.m21 = 0.0f;
    sjt_cast51->_projection.m22 = 0.0f;
    sjt_cast51->_projection.m23 = 0.0f;
    sjt_cast51->_projection.m30 = 0.0f;
    sjt_cast51->_projection.m31 = 0.0f;
    sjt_cast51->_projection.m32 = 0.0f;
    sjt_cast51->_projection.m33 = 0.0f;
    sjf_mat4(&sjt_cast51->_projection);
    sjt_cast51->_view._refCount = 1;
    sjt_cast51->_view.m00 = 0.0f;
    sjt_cast51->_view.m01 = 0.0f;
    sjt_cast51->_view.m02 = 0.0f;
    sjt_cast51->_view.m03 = 0.0f;
    sjt_cast51->_view.m10 = 0.0f;
    sjt_cast51->_view.m11 = 0.0f;
    sjt_cast51->_view.m12 = 0.0f;
    sjt_cast51->_view.m13 = 0.0f;
    sjt_cast51->_view.m20 = 0.0f;
    sjt_cast51->_view.m21 = 0.0f;
    sjt_cast51->_view.m22 = 0.0f;
    sjt_cast51->_view.m23 = 0.0f;
    sjt_cast51->_view.m30 = 0.0f;
    sjt_cast51->_view.m31 = 0.0f;
    sjt_cast51->_view.m32 = 0.0f;
    sjt_cast51->_view.m33 = 0.0f;
    sjf_mat4(&sjt_cast51->_view);
    sjt_cast51->_world._refCount = 1;
    sjt_cast51->_world.m00 = 0.0f;
    sjt_cast51->_world.m01 = 0.0f;
    sjt_cast51->_world.m02 = 0.0f;
    sjt_cast51->_world.m03 = 0.0f;
    sjt_cast51->_world.m10 = 0.0f;
    sjt_cast51->_world.m11 = 0.0f;
    sjt_cast51->_world.m12 = 0.0f;
    sjt_cast51->_world.m13 = 0.0f;
    sjt_cast51->_world.m20 = 0.0f;
    sjt_cast51->_world.m21 = 0.0f;
    sjt_cast51->_world.m22 = 0.0f;
    sjt_cast51->_world.m23 = 0.0f;
    sjt_cast51->_world.m30 = 0.0f;
    sjt_cast51->_world.m31 = 0.0f;
    sjt_cast51->_world.m32 = 0.0f;
    sjt_cast51->_world.m33 = 0.0f;
    sjf_mat4(&sjt_cast51->_world);
    sjt_cast51->_light._refCount = 1;
    sjt_cast51->_light.pos._refCount = 1;
    sjt_cast51->_light.pos.x = 1.0f;
    sjt_cast51->_light.pos.y = 1.0f;
    sjt_cast51->_light.pos.z = 1.0f;
    sjf_vec3(&sjt_cast51->_light.pos);
    sjt_cast51->_light.diffusecolor._refCount = 1;
    sjt_cast51->_light.diffusecolor.r = 0.5f;
    sjt_cast51->_light.diffusecolor.g = 0.5f;
    sjt_cast51->_light.diffusecolor.b = 0.0f;
    sjt_cast51->_light.diffusecolor.a = 1.0f;
    sjf_color(&sjt_cast51->_light.diffusecolor);
    sjt_cast51->_light.speccolor._refCount = 1;
    sjt_cast51->_light.speccolor.r = 1.0f;
    sjt_cast51->_light.speccolor.g = 1.0f;
    sjt_cast51->_light.speccolor.b = 1.0f;
    sjt_cast51->_light.speccolor.a = 1.0f;
    sjf_color(&sjt_cast51->_light.speccolor);
    sjf_light(&sjt_cast51->_light);
    sjt_cast51->_projectedcenter._refCount = 1;
    sjt_cast51->_projectedcenter.x = 0.0f;
    sjt_cast51->_projectedcenter.y = 0.0f;
    sjt_cast51->_projectedcenter.z = 0.0f;
    sjf_vec3(&sjt_cast51->_projectedcenter);
    sjf_model_heap(sjt_cast51);
    sjt_functionParam544 = (sji_model*)sjf_model_heap_as_sji_model(sjt_cast51);
    sjf_array_heap_model_initat(sjt_parent218, sjt_functionParam543, sjt_functionParam544);
    sjt_parent220 = array10;
    sjt_functionParam562 = 2;
    sjt_cast52 = (sjs_model*)malloc(sizeof(sjs_model));
    sjt_cast52->_refCount = 1;
    sjt_negate31 = 4.3f;
    result41 = -sjt_negate31;
    sjt_functionParam564 = result41;
    sjt_functionParam565 = 4.3f;
    sjt_negate32 = 1.0f;
    result42 = -sjt_negate32;
    sjt_functionParam566 = result42;
    sjt_functionParam567 = 1.0f;
    sjt_functionParam568 = 0.0f;
    sjt_functionParam569 = 0.0f;
    sjt_functionParam570 = 1.0f;
    sjt_functionParam571 = 0.0f;
    sjt_functionParam572 = 1.0f;
    sjf_planevertexbuffer(sjt_functionParam564, sjt_functionParam565, sjt_functionParam566, sjt_functionParam567, sjt_functionParam568, sjt_functionParam569, sjt_functionParam570, sjt_functionParam571, sjt_functionParam572, &sjt_cast52->vertexbuffer);
    sjt_copy48 = &sjv_phongtextureshader;
    sjt_cast52->shader._refCount = 1;
    sjf_shader_copy(&sjt_cast52->shader, sjt_copy48);
    sjt_call83._refCount = 1;
    sjt_call83.count = 16;
    sjt_call83.data._refCount = 1;
    sjt_call83.data.datasize = 17;
    sjt_call83.data.data = (void*)sjg_string36;
    sjt_call83.data._isglobal = true;
    sjt_call83.data.count = 17;
    sjf_array_char(&sjt_call83.data);
    sjf_string(&sjt_call83);
    sjt_functionParam573 = &sjt_call83;
    sjf_texturefrompng(sjt_functionParam573, &sjt_cast52->texture);
    sjt_negate33 = 8.6f;
    result43 = -sjt_negate33;
    sjt_functionParam574 = result43;
    sjt_functionParam575 = 0.0f;
    sjt_functionParam576 = 4.2f;
    sjf_mat4_translate(sjt_functionParam574, sjt_functionParam575, sjt_functionParam576, &sjt_call84);
    sjt_parent221 = &sjt_call84;
    sjt_functionParam578 = 2.0f;
    sjt_functionParam579 = 2.0f;
    sjt_functionParam580 = 2.0f;
    sjf_mat4_scale(sjt_functionParam578, sjt_functionParam579, sjt_functionParam580, &sjt_call85);
    sjt_functionParam577 = &sjt_call85;
    sjf_mat4_multiply(sjt_parent221, sjt_functionParam577, &sjt_cast52->model);
    sjt_cast52->center._refCount = 1;
    sjt_cast52->center.x = 0.0f;
    sjt_cast52->center.y = 0.0f;
    sjt_cast52->center.z = 0.0f;
    sjf_vec3(&sjt_cast52->center);
    sjt_cast52->hasalpha = true;
    sjt_cast52->id._refCount = 1;
    sjt_cast52->id.count = 8;
    sjt_cast52->id.data._refCount = 1;
    sjt_cast52->id.data.datasize = 9;
    sjt_cast52->id.data.data = (void*)sjg_string35;
    sjt_cast52->id.data._isglobal = true;
    sjt_cast52->id.data.count = 9;
    sjf_array_char(&sjt_cast52->id.data);
    sjf_string(&sjt_cast52->id);
    sjt_cast52->_projection._refCount = 1;
    sjt_cast52->_projection.m00 = 0.0f;
    sjt_cast52->_projection.m01 = 0.0f;
    sjt_cast52->_projection.m02 = 0.0f;
    sjt_cast52->_projection.m03 = 0.0f;
    sjt_cast52->_projection.m10 = 0.0f;
    sjt_cast52->_projection.m11 = 0.0f;
    sjt_cast52->_projection.m12 = 0.0f;
    sjt_cast52->_projection.m13 = 0.0f;
    sjt_cast52->_projection.m20 = 0.0f;
    sjt_cast52->_projection.m21 = 0.0f;
    sjt_cast52->_projection.m22 = 0.0f;
    sjt_cast52->_projection.m23 = 0.0f;
    sjt_cast52->_projection.m30 = 0.0f;
    sjt_cast52->_projection.m31 = 0.0f;
    sjt_cast52->_projection.m32 = 0.0f;
    sjt_cast52->_projection.m33 = 0.0f;
    sjf_mat4(&sjt_cast52->_projection);
    sjt_cast52->_view._refCount = 1;
    sjt_cast52->_view.m00 = 0.0f;
    sjt_cast52->_view.m01 = 0.0f;
    sjt_cast52->_view.m02 = 0.0f;
    sjt_cast52->_view.m03 = 0.0f;
    sjt_cast52->_view.m10 = 0.0f;
    sjt_cast52->_view.m11 = 0.0f;
    sjt_cast52->_view.m12 = 0.0f;
    sjt_cast52->_view.m13 = 0.0f;
    sjt_cast52->_view.m20 = 0.0f;
    sjt_cast52->_view.m21 = 0.0f;
    sjt_cast52->_view.m22 = 0.0f;
    sjt_cast52->_view.m23 = 0.0f;
    sjt_cast52->_view.m30 = 0.0f;
    sjt_cast52->_view.m31 = 0.0f;
    sjt_cast52->_view.m32 = 0.0f;
    sjt_cast52->_view.m33 = 0.0f;
    sjf_mat4(&sjt_cast52->_view);
    sjt_cast52->_world._refCount = 1;
    sjt_cast52->_world.m00 = 0.0f;
    sjt_cast52->_world.m01 = 0.0f;
    sjt_cast52->_world.m02 = 0.0f;
    sjt_cast52->_world.m03 = 0.0f;
    sjt_cast52->_world.m10 = 0.0f;
    sjt_cast52->_world.m11 = 0.0f;
    sjt_cast52->_world.m12 = 0.0f;
    sjt_cast52->_world.m13 = 0.0f;
    sjt_cast52->_world.m20 = 0.0f;
    sjt_cast52->_world.m21 = 0.0f;
    sjt_cast52->_world.m22 = 0.0f;
    sjt_cast52->_world.m23 = 0.0f;
    sjt_cast52->_world.m30 = 0.0f;
    sjt_cast52->_world.m31 = 0.0f;
    sjt_cast52->_world.m32 = 0.0f;
    sjt_cast52->_world.m33 = 0.0f;
    sjf_mat4(&sjt_cast52->_world);
    sjt_cast52->_light._refCount = 1;
    sjt_cast52->_light.pos._refCount = 1;
    sjt_cast52->_light.pos.x = 1.0f;
    sjt_cast52->_light.pos.y = 1.0f;
    sjt_cast52->_light.pos.z = 1.0f;
    sjf_vec3(&sjt_cast52->_light.pos);
    sjt_cast52->_light.diffusecolor._refCount = 1;
    sjt_cast52->_light.diffusecolor.r = 0.5f;
    sjt_cast52->_light.diffusecolor.g = 0.5f;
    sjt_cast52->_light.diffusecolor.b = 0.0f;
    sjt_cast52->_light.diffusecolor.a = 1.0f;
    sjf_color(&sjt_cast52->_light.diffusecolor);
    sjt_cast52->_light.speccolor._refCount = 1;
    sjt_cast52->_light.speccolor.r = 1.0f;
    sjt_cast52->_light.speccolor.g = 1.0f;
    sjt_cast52->_light.speccolor.b = 1.0f;
    sjt_cast52->_light.speccolor.a = 1.0f;
    sjf_color(&sjt_cast52->_light.speccolor);
    sjf_light(&sjt_cast52->_light);
    sjt_cast52->_projectedcenter._refCount = 1;
    sjt_cast52->_projectedcenter.x = 0.0f;
    sjt_cast52->_projectedcenter.y = 0.0f;
    sjt_cast52->_projectedcenter.z = 0.0f;
    sjf_vec3(&sjt_cast52->_projectedcenter);
    sjf_model_heap(sjt_cast52);
    sjt_functionParam563 = (sji_model*)sjf_model_heap_as_sji_model(sjt_cast52);
    sjf_array_heap_model_initat(sjt_parent220, sjt_functionParam562, sjt_functionParam563);
    sjt_parent222 = array10;
    sjt_functionParam581 = 3;
    sjt_cast53 = (sjs_model*)malloc(sizeof(sjs_model));
    sjt_cast53->_refCount = 1;
    sjt_negate34 = 4.3f;
    result44 = -sjt_negate34;
    sjt_functionParam583 = result44;
    sjt_functionParam584 = 4.3f;
    sjt_negate35 = 1.0f;
    result45 = -sjt_negate35;
    sjt_functionParam585 = result45;
    sjt_functionParam586 = 1.0f;
    sjt_functionParam587 = 0.0f;
    sjt_functionParam588 = 0.0f;
    sjt_functionParam589 = 1.0f;
    sjt_functionParam590 = 0.0f;
    sjt_functionParam591 = 1.0f;
    sjf_planevertexbuffer(sjt_functionParam583, sjt_functionParam584, sjt_functionParam585, sjt_functionParam586, sjt_functionParam587, sjt_functionParam588, sjt_functionParam589, sjt_functionParam590, sjt_functionParam591, &sjt_cast53->vertexbuffer);
    sjt_copy49 = &sjv_phongtextureshader;
    sjt_cast53->shader._refCount = 1;
    sjf_shader_copy(&sjt_cast53->shader, sjt_copy49);
    sjt_call86._refCount = 1;
    sjt_call86.count = 16;
    sjt_call86.data._refCount = 1;
    sjt_call86.data.datasize = 17;
    sjt_call86.data.data = (void*)sjg_string38;
    sjt_call86.data._isglobal = true;
    sjt_call86.data.count = 17;
    sjf_array_char(&sjt_call86.data);
    sjf_string(&sjt_call86);
    sjt_functionParam592 = &sjt_call86;
    sjf_texturefrompng(sjt_functionParam592, &sjt_cast53->texture);
    sjt_functionParam593 = 8.6f;
    sjt_functionParam594 = 0.0f;
    sjt_functionParam595 = 4.2f;
    sjf_mat4_translate(sjt_functionParam593, sjt_functionParam594, sjt_functionParam595, &sjt_call87);
    sjt_parent223 = &sjt_call87;
    sjt_functionParam597 = 2.0f;
    sjt_functionParam598 = 2.0f;
    sjt_functionParam599 = 2.0f;
    sjf_mat4_scale(sjt_functionParam597, sjt_functionParam598, sjt_functionParam599, &sjt_call88);
    sjt_functionParam596 = &sjt_call88;
    sjf_mat4_multiply(sjt_parent223, sjt_functionParam596, &sjt_cast53->model);
    sjt_cast53->center._refCount = 1;
    sjt_cast53->center.x = 0.0f;
    sjt_cast53->center.y = 0.0f;
    sjt_cast53->center.z = 0.0f;
    sjf_vec3(&sjt_cast53->center);
    sjt_cast53->hasalpha = true;
    sjt_cast53->id._refCount = 1;
    sjt_cast53->id.count = 8;
    sjt_cast53->id.data._refCount = 1;
    sjt_cast53->id.data.datasize = 9;
    sjt_cast53->id.data.data = (void*)sjg_string37;
    sjt_cast53->id.data._isglobal = true;
    sjt_cast53->id.data.count = 9;
    sjf_array_char(&sjt_cast53->id.data);
    sjf_string(&sjt_cast53->id);
    sjt_cast53->_projection._refCount = 1;
    sjt_cast53->_projection.m00 = 0.0f;
    sjt_cast53->_projection.m01 = 0.0f;
    sjt_cast53->_projection.m02 = 0.0f;
    sjt_cast53->_projection.m03 = 0.0f;
    sjt_cast53->_projection.m10 = 0.0f;
    sjt_cast53->_projection.m11 = 0.0f;
    sjt_cast53->_projection.m12 = 0.0f;
    sjt_cast53->_projection.m13 = 0.0f;
    sjt_cast53->_projection.m20 = 0.0f;
    sjt_cast53->_projection.m21 = 0.0f;
    sjt_cast53->_projection.m22 = 0.0f;
    sjt_cast53->_projection.m23 = 0.0f;
    sjt_cast53->_projection.m30 = 0.0f;
    sjt_cast53->_projection.m31 = 0.0f;
    sjt_cast53->_projection.m32 = 0.0f;
    sjt_cast53->_projection.m33 = 0.0f;
    sjf_mat4(&sjt_cast53->_projection);
    sjt_cast53->_view._refCount = 1;
    sjt_cast53->_view.m00 = 0.0f;
    sjt_cast53->_view.m01 = 0.0f;
    sjt_cast53->_view.m02 = 0.0f;
    sjt_cast53->_view.m03 = 0.0f;
    sjt_cast53->_view.m10 = 0.0f;
    sjt_cast53->_view.m11 = 0.0f;
    sjt_cast53->_view.m12 = 0.0f;
    sjt_cast53->_view.m13 = 0.0f;
    sjt_cast53->_view.m20 = 0.0f;
    sjt_cast53->_view.m21 = 0.0f;
    sjt_cast53->_view.m22 = 0.0f;
    sjt_cast53->_view.m23 = 0.0f;
    sjt_cast53->_view.m30 = 0.0f;
    sjt_cast53->_view.m31 = 0.0f;
    sjt_cast53->_view.m32 = 0.0f;
    sjt_cast53->_view.m33 = 0.0f;
    sjf_mat4(&sjt_cast53->_view);
    sjt_cast53->_world._refCount = 1;
    sjt_cast53->_world.m00 = 0.0f;
    sjt_cast53->_world.m01 = 0.0f;
    sjt_cast53->_world.m02 = 0.0f;
    sjt_cast53->_world.m03 = 0.0f;
    sjt_cast53->_world.m10 = 0.0f;
    sjt_cast53->_world.m11 = 0.0f;
    sjt_cast53->_world.m12 = 0.0f;
    sjt_cast53->_world.m13 = 0.0f;
    sjt_cast53->_world.m20 = 0.0f;
    sjt_cast53->_world.m21 = 0.0f;
    sjt_cast53->_world.m22 = 0.0f;
    sjt_cast53->_world.m23 = 0.0f;
    sjt_cast53->_world.m30 = 0.0f;
    sjt_cast53->_world.m31 = 0.0f;
    sjt_cast53->_world.m32 = 0.0f;
    sjt_cast53->_world.m33 = 0.0f;
    sjf_mat4(&sjt_cast53->_world);
    sjt_cast53->_light._refCount = 1;
    sjt_cast53->_light.pos._refCount = 1;
    sjt_cast53->_light.pos.x = 1.0f;
    sjt_cast53->_light.pos.y = 1.0f;
    sjt_cast53->_light.pos.z = 1.0f;
    sjf_vec3(&sjt_cast53->_light.pos);
    sjt_cast53->_light.diffusecolor._refCount = 1;
    sjt_cast53->_light.diffusecolor.r = 0.5f;
    sjt_cast53->_light.diffusecolor.g = 0.5f;
    sjt_cast53->_light.diffusecolor.b = 0.0f;
    sjt_cast53->_light.diffusecolor.a = 1.0f;
    sjf_color(&sjt_cast53->_light.diffusecolor);
    sjt_cast53->_light.speccolor._refCount = 1;
    sjt_cast53->_light.speccolor.r = 1.0f;
    sjt_cast53->_light.speccolor.g = 1.0f;
    sjt_cast53->_light.speccolor.b = 1.0f;
    sjt_cast53->_light.speccolor.a = 1.0f;
    sjf_color(&sjt_cast53->_light.speccolor);
    sjf_light(&sjt_cast53->_light);
    sjt_cast53->_projectedcenter._refCount = 1;
    sjt_cast53->_projectedcenter.x = 0.0f;
    sjt_cast53->_projectedcenter.y = 0.0f;
    sjt_cast53->_projectedcenter.z = 0.0f;
    sjf_vec3(&sjt_cast53->_projectedcenter);
    sjf_model_heap(sjt_cast53);
    sjt_functionParam582 = (sji_model*)sjf_model_heap_as_sji_model(sjt_cast53);
    sjf_array_heap_model_initat(sjt_parent222, sjt_functionParam581, sjt_functionParam582);
    sjt_parent224 = array10;
    sjt_functionParam600 = 4;
    sjt_cast54 = (sjs_model*)malloc(sizeof(sjs_model));
    sjt_cast54->_refCount = 1;
    sjt_negate36 = 4.3f;
    result46 = -sjt_negate36;
    sjt_functionParam602 = result46;
    sjt_functionParam603 = 4.3f;
    sjt_negate37 = 1.0f;
    result47 = -sjt_negate37;
    sjt_functionParam604 = result47;
    sjt_functionParam605 = 1.0f;
    sjt_functionParam606 = 0.0f;
    sjt_functionParam607 = 0.0f;
    sjt_functionParam608 = 1.0f;
    sjt_functionParam609 = 0.0f;
    sjt_functionParam610 = 1.0f;
    sjf_planevertexbuffer(sjt_functionParam602, sjt_functionParam603, sjt_functionParam604, sjt_functionParam605, sjt_functionParam606, sjt_functionParam607, sjt_functionParam608, sjt_functionParam609, sjt_functionParam610, &sjt_cast54->vertexbuffer);
    sjt_copy50 = &sjv_phongtextureshader;
    sjt_cast54->shader._refCount = 1;
    sjf_shader_copy(&sjt_cast54->shader, sjt_copy50);
    sjt_call89._refCount = 1;
    sjt_call89.count = 16;
    sjt_call89.data._refCount = 1;
    sjt_call89.data.datasize = 17;
    sjt_call89.data.data = (void*)sjg_string40;
    sjt_call89.data._isglobal = true;
    sjt_call89.data.count = 17;
    sjf_array_char(&sjt_call89.data);
    sjf_string(&sjt_call89);
    sjt_functionParam611 = &sjt_call89;
    sjf_texturefrompng(sjt_functionParam611, &sjt_cast54->texture);
    sjt_negate38 = 9.6f;
    result48 = -sjt_negate38;
    sjt_functionParam612 = result48;
    sjt_functionParam613 = 0.0f;
    sjt_functionParam614 = 2.2f;
    sjf_mat4_translate(sjt_functionParam612, sjt_functionParam613, sjt_functionParam614, &sjt_call90);
    sjt_parent225 = &sjt_call90;
    sjt_functionParam616 = 2.0f;
    sjt_functionParam617 = 2.0f;
    sjt_functionParam618 = 2.0f;
    sjf_mat4_scale(sjt_functionParam616, sjt_functionParam617, sjt_functionParam618, &sjt_call91);
    sjt_functionParam615 = &sjt_call91;
    sjf_mat4_multiply(sjt_parent225, sjt_functionParam615, &sjt_cast54->model);
    sjt_cast54->center._refCount = 1;
    sjt_cast54->center.x = 0.0f;
    sjt_cast54->center.y = 0.0f;
    sjt_cast54->center.z = 0.0f;
    sjf_vec3(&sjt_cast54->center);
    sjt_cast54->hasalpha = true;
    sjt_cast54->id._refCount = 1;
    sjt_cast54->id.count = 8;
    sjt_cast54->id.data._refCount = 1;
    sjt_cast54->id.data.datasize = 9;
    sjt_cast54->id.data.data = (void*)sjg_string39;
    sjt_cast54->id.data._isglobal = true;
    sjt_cast54->id.data.count = 9;
    sjf_array_char(&sjt_cast54->id.data);
    sjf_string(&sjt_cast54->id);
    sjt_cast54->_projection._refCount = 1;
    sjt_cast54->_projection.m00 = 0.0f;
    sjt_cast54->_projection.m01 = 0.0f;
    sjt_cast54->_projection.m02 = 0.0f;
    sjt_cast54->_projection.m03 = 0.0f;
    sjt_cast54->_projection.m10 = 0.0f;
    sjt_cast54->_projection.m11 = 0.0f;
    sjt_cast54->_projection.m12 = 0.0f;
    sjt_cast54->_projection.m13 = 0.0f;
    sjt_cast54->_projection.m20 = 0.0f;
    sjt_cast54->_projection.m21 = 0.0f;
    sjt_cast54->_projection.m22 = 0.0f;
    sjt_cast54->_projection.m23 = 0.0f;
    sjt_cast54->_projection.m30 = 0.0f;
    sjt_cast54->_projection.m31 = 0.0f;
    sjt_cast54->_projection.m32 = 0.0f;
    sjt_cast54->_projection.m33 = 0.0f;
    sjf_mat4(&sjt_cast54->_projection);
    sjt_cast54->_view._refCount = 1;
    sjt_cast54->_view.m00 = 0.0f;
    sjt_cast54->_view.m01 = 0.0f;
    sjt_cast54->_view.m02 = 0.0f;
    sjt_cast54->_view.m03 = 0.0f;
    sjt_cast54->_view.m10 = 0.0f;
    sjt_cast54->_view.m11 = 0.0f;
    sjt_cast54->_view.m12 = 0.0f;
    sjt_cast54->_view.m13 = 0.0f;
    sjt_cast54->_view.m20 = 0.0f;
    sjt_cast54->_view.m21 = 0.0f;
    sjt_cast54->_view.m22 = 0.0f;
    sjt_cast54->_view.m23 = 0.0f;
    sjt_cast54->_view.m30 = 0.0f;
    sjt_cast54->_view.m31 = 0.0f;
    sjt_cast54->_view.m32 = 0.0f;
    sjt_cast54->_view.m33 = 0.0f;
    sjf_mat4(&sjt_cast54->_view);
    sjt_cast54->_world._refCount = 1;
    sjt_cast54->_world.m00 = 0.0f;
    sjt_cast54->_world.m01 = 0.0f;
    sjt_cast54->_world.m02 = 0.0f;
    sjt_cast54->_world.m03 = 0.0f;
    sjt_cast54->_world.m10 = 0.0f;
    sjt_cast54->_world.m11 = 0.0f;
    sjt_cast54->_world.m12 = 0.0f;
    sjt_cast54->_world.m13 = 0.0f;
    sjt_cast54->_world.m20 = 0.0f;
    sjt_cast54->_world.m21 = 0.0f;
    sjt_cast54->_world.m22 = 0.0f;
    sjt_cast54->_world.m23 = 0.0f;
    sjt_cast54->_world.m30 = 0.0f;
    sjt_cast54->_world.m31 = 0.0f;
    sjt_cast54->_world.m32 = 0.0f;
    sjt_cast54->_world.m33 = 0.0f;
    sjf_mat4(&sjt_cast54->_world);
    sjt_cast54->_light._refCount = 1;
    sjt_cast54->_light.pos._refCount = 1;
    sjt_cast54->_light.pos.x = 1.0f;
    sjt_cast54->_light.pos.y = 1.0f;
    sjt_cast54->_light.pos.z = 1.0f;
    sjf_vec3(&sjt_cast54->_light.pos);
    sjt_cast54->_light.diffusecolor._refCount = 1;
    sjt_cast54->_light.diffusecolor.r = 0.5f;
    sjt_cast54->_light.diffusecolor.g = 0.5f;
    sjt_cast54->_light.diffusecolor.b = 0.0f;
    sjt_cast54->_light.diffusecolor.a = 1.0f;
    sjf_color(&sjt_cast54->_light.diffusecolor);
    sjt_cast54->_light.speccolor._refCount = 1;
    sjt_cast54->_light.speccolor.r = 1.0f;
    sjt_cast54->_light.speccolor.g = 1.0f;
    sjt_cast54->_light.speccolor.b = 1.0f;
    sjt_cast54->_light.speccolor.a = 1.0f;
    sjf_color(&sjt_cast54->_light.speccolor);
    sjf_light(&sjt_cast54->_light);
    sjt_cast54->_projectedcenter._refCount = 1;
    sjt_cast54->_projectedcenter.x = 0.0f;
    sjt_cast54->_projectedcenter.y = 0.0f;
    sjt_cast54->_projectedcenter.z = 0.0f;
    sjf_vec3(&sjt_cast54->_projectedcenter);
    sjf_model_heap(sjt_cast54);
    sjt_functionParam601 = (sji_model*)sjf_model_heap_as_sji_model(sjt_cast54);
    sjf_array_heap_model_initat(sjt_parent224, sjt_functionParam600, sjt_functionParam601);
    sjt_parent226 = array10;
    sjt_functionParam619 = 5;
    sjt_cast55 = (sjs_model*)malloc(sizeof(sjs_model));
    sjt_cast55->_refCount = 1;
    sjt_negate39 = 4.3f;
    result49 = -sjt_negate39;
    sjt_functionParam621 = result49;
    sjt_functionParam622 = 4.3f;
    sjt_negate40 = 1.0f;
    result50 = -sjt_negate40;
    sjt_functionParam623 = result50;
    sjt_functionParam624 = 1.0f;
    sjt_functionParam625 = 0.0f;
    sjt_functionParam626 = 0.0f;
    sjt_functionParam627 = 1.0f;
    sjt_functionParam628 = 0.0f;
    sjt_functionParam629 = 1.0f;
    sjf_planevertexbuffer(sjt_functionParam621, sjt_functionParam622, sjt_functionParam623, sjt_functionParam624, sjt_functionParam625, sjt_functionParam626, sjt_functionParam627, sjt_functionParam628, sjt_functionParam629, &sjt_cast55->vertexbuffer);
    sjt_copy51 = &sjv_phongtextureshader;
    sjt_cast55->shader._refCount = 1;
    sjf_shader_copy(&sjt_cast55->shader, sjt_copy51);
    sjt_call92._refCount = 1;
    sjt_call92.count = 16;
    sjt_call92.data._refCount = 1;
    sjt_call92.data.datasize = 17;
    sjt_call92.data.data = (void*)sjg_string42;
    sjt_call92.data._isglobal = true;
    sjt_call92.data.count = 17;
    sjf_array_char(&sjt_call92.data);
    sjf_string(&sjt_call92);
    sjt_functionParam630 = &sjt_call92;
    sjf_texturefrompng(sjt_functionParam630, &sjt_cast55->texture);
    sjt_functionParam631 = 7.6f;
    sjt_functionParam632 = 0.0f;
    sjt_functionParam633 = 2.2f;
    sjf_mat4_translate(sjt_functionParam631, sjt_functionParam632, sjt_functionParam633, &sjt_call93);
    sjt_parent227 = &sjt_call93;
    sjt_functionParam635 = 2.0f;
    sjt_functionParam636 = 2.0f;
    sjt_functionParam637 = 2.0f;
    sjf_mat4_scale(sjt_functionParam635, sjt_functionParam636, sjt_functionParam637, &sjt_call94);
    sjt_functionParam634 = &sjt_call94;
    sjf_mat4_multiply(sjt_parent227, sjt_functionParam634, &sjt_cast55->model);
    sjt_cast55->center._refCount = 1;
    sjt_cast55->center.x = 0.0f;
    sjt_cast55->center.y = 0.0f;
    sjt_cast55->center.z = 0.0f;
    sjf_vec3(&sjt_cast55->center);
    sjt_cast55->hasalpha = true;
    sjt_cast55->id._refCount = 1;
    sjt_cast55->id.count = 8;
    sjt_cast55->id.data._refCount = 1;
    sjt_cast55->id.data.datasize = 9;
    sjt_cast55->id.data.data = (void*)sjg_string41;
    sjt_cast55->id.data._isglobal = true;
    sjt_cast55->id.data.count = 9;
    sjf_array_char(&sjt_cast55->id.data);
    sjf_string(&sjt_cast55->id);
    sjt_cast55->_projection._refCount = 1;
    sjt_cast55->_projection.m00 = 0.0f;
    sjt_cast55->_projection.m01 = 0.0f;
    sjt_cast55->_projection.m02 = 0.0f;
    sjt_cast55->_projection.m03 = 0.0f;
    sjt_cast55->_projection.m10 = 0.0f;
    sjt_cast55->_projection.m11 = 0.0f;
    sjt_cast55->_projection.m12 = 0.0f;
    sjt_cast55->_projection.m13 = 0.0f;
    sjt_cast55->_projection.m20 = 0.0f;
    sjt_cast55->_projection.m21 = 0.0f;
    sjt_cast55->_projection.m22 = 0.0f;
    sjt_cast55->_projection.m23 = 0.0f;
    sjt_cast55->_projection.m30 = 0.0f;
    sjt_cast55->_projection.m31 = 0.0f;
    sjt_cast55->_projection.m32 = 0.0f;
    sjt_cast55->_projection.m33 = 0.0f;
    sjf_mat4(&sjt_cast55->_projection);
    sjt_cast55->_view._refCount = 1;
    sjt_cast55->_view.m00 = 0.0f;
    sjt_cast55->_view.m01 = 0.0f;
    sjt_cast55->_view.m02 = 0.0f;
    sjt_cast55->_view.m03 = 0.0f;
    sjt_cast55->_view.m10 = 0.0f;
    sjt_cast55->_view.m11 = 0.0f;
    sjt_cast55->_view.m12 = 0.0f;
    sjt_cast55->_view.m13 = 0.0f;
    sjt_cast55->_view.m20 = 0.0f;
    sjt_cast55->_view.m21 = 0.0f;
    sjt_cast55->_view.m22 = 0.0f;
    sjt_cast55->_view.m23 = 0.0f;
    sjt_cast55->_view.m30 = 0.0f;
    sjt_cast55->_view.m31 = 0.0f;
    sjt_cast55->_view.m32 = 0.0f;
    sjt_cast55->_view.m33 = 0.0f;
    sjf_mat4(&sjt_cast55->_view);
    sjt_cast55->_world._refCount = 1;
    sjt_cast55->_world.m00 = 0.0f;
    sjt_cast55->_world.m01 = 0.0f;
    sjt_cast55->_world.m02 = 0.0f;
    sjt_cast55->_world.m03 = 0.0f;
    sjt_cast55->_world.m10 = 0.0f;
    sjt_cast55->_world.m11 = 0.0f;
    sjt_cast55->_world.m12 = 0.0f;
    sjt_cast55->_world.m13 = 0.0f;
    sjt_cast55->_world.m20 = 0.0f;
    sjt_cast55->_world.m21 = 0.0f;
    sjt_cast55->_world.m22 = 0.0f;
    sjt_cast55->_world.m23 = 0.0f;
    sjt_cast55->_world.m30 = 0.0f;
    sjt_cast55->_world.m31 = 0.0f;
    sjt_cast55->_world.m32 = 0.0f;
    sjt_cast55->_world.m33 = 0.0f;
    sjf_mat4(&sjt_cast55->_world);
    sjt_cast55->_light._refCount = 1;
    sjt_cast55->_light.pos._refCount = 1;
    sjt_cast55->_light.pos.x = 1.0f;
    sjt_cast55->_light.pos.y = 1.0f;
    sjt_cast55->_light.pos.z = 1.0f;
    sjf_vec3(&sjt_cast55->_light.pos);
    sjt_cast55->_light.diffusecolor._refCount = 1;
    sjt_cast55->_light.diffusecolor.r = 0.5f;
    sjt_cast55->_light.diffusecolor.g = 0.5f;
    sjt_cast55->_light.diffusecolor.b = 0.0f;
    sjt_cast55->_light.diffusecolor.a = 1.0f;
    sjf_color(&sjt_cast55->_light.diffusecolor);
    sjt_cast55->_light.speccolor._refCount = 1;
    sjt_cast55->_light.speccolor.r = 1.0f;
    sjt_cast55->_light.speccolor.g = 1.0f;
    sjt_cast55->_light.speccolor.b = 1.0f;
    sjt_cast55->_light.speccolor.a = 1.0f;
    sjf_color(&sjt_cast55->_light.speccolor);
    sjf_light(&sjt_cast55->_light);
    sjt_cast55->_projectedcenter._refCount = 1;
    sjt_cast55->_projectedcenter.x = 0.0f;
    sjt_cast55->_projectedcenter.y = 0.0f;
    sjt_cast55->_projectedcenter.z = 0.0f;
    sjf_vec3(&sjt_cast55->_projectedcenter);
    sjf_model_heap(sjt_cast55);
    sjt_functionParam620 = (sji_model*)sjf_model_heap_as_sji_model(sjt_cast55);
    sjf_array_heap_model_initat(sjt_parent226, sjt_functionParam619, sjt_functionParam620);
    sjt_parent228 = array10;
    sjt_functionParam638 = 6;
    sjt_cast56 = (sjs_model*)malloc(sizeof(sjs_model));
    sjt_cast56->_refCount = 1;
    sjt_negate41 = 4.3f;
    result51 = -sjt_negate41;
    sjt_functionParam640 = result51;
    sjt_functionParam641 = 4.3f;
    sjt_negate42 = 1.0f;
    result52 = -sjt_negate42;
    sjt_functionParam642 = result52;
    sjt_functionParam643 = 1.0f;
    sjt_functionParam644 = 0.0f;
    sjt_functionParam645 = 0.0f;
    sjt_functionParam646 = 1.0f;
    sjt_functionParam647 = 0.0f;
    sjt_functionParam648 = 1.0f;
    sjf_planevertexbuffer(sjt_functionParam640, sjt_functionParam641, sjt_functionParam642, sjt_functionParam643, sjt_functionParam644, sjt_functionParam645, sjt_functionParam646, sjt_functionParam647, sjt_functionParam648, &sjt_cast56->vertexbuffer);
    sjt_copy52 = &sjv_phongtextureshader;
    sjt_cast56->shader._refCount = 1;
    sjf_shader_copy(&sjt_cast56->shader, sjt_copy52);
    sjt_call95._refCount = 1;
    sjt_call95.count = 16;
    sjt_call95.data._refCount = 1;
    sjt_call95.data.datasize = 17;
    sjt_call95.data.data = (void*)sjg_string44;
    sjt_call95.data._isglobal = true;
    sjt_call95.data.count = 17;
    sjf_array_char(&sjt_call95.data);
    sjf_string(&sjt_call95);
    sjt_functionParam649 = &sjt_call95;
    sjf_texturefrompng(sjt_functionParam649, &sjt_cast56->texture);
    sjt_negate43 = 10.6f;
    result53 = -sjt_negate43;
    sjt_functionParam650 = result53;
    sjt_functionParam651 = 0.0f;
    sjt_functionParam652 = 0.2f;
    sjf_mat4_translate(sjt_functionParam650, sjt_functionParam651, sjt_functionParam652, &sjt_call96);
    sjt_parent229 = &sjt_call96;
    sjt_functionParam654 = 2.0f;
    sjt_functionParam655 = 2.0f;
    sjt_functionParam656 = 2.0f;
    sjf_mat4_scale(sjt_functionParam654, sjt_functionParam655, sjt_functionParam656, &sjt_call97);
    sjt_functionParam653 = &sjt_call97;
    sjf_mat4_multiply(sjt_parent229, sjt_functionParam653, &sjt_cast56->model);
    sjt_cast56->center._refCount = 1;
    sjt_cast56->center.x = 0.0f;
    sjt_cast56->center.y = 0.0f;
    sjt_cast56->center.z = 0.0f;
    sjf_vec3(&sjt_cast56->center);
    sjt_cast56->hasalpha = true;
    sjt_cast56->id._refCount = 1;
    sjt_cast56->id.count = 8;
    sjt_cast56->id.data._refCount = 1;
    sjt_cast56->id.data.datasize = 9;
    sjt_cast56->id.data.data = (void*)sjg_string43;
    sjt_cast56->id.data._isglobal = true;
    sjt_cast56->id.data.count = 9;
    sjf_array_char(&sjt_cast56->id.data);
    sjf_string(&sjt_cast56->id);
    sjt_cast56->_projection._refCount = 1;
    sjt_cast56->_projection.m00 = 0.0f;
    sjt_cast56->_projection.m01 = 0.0f;
    sjt_cast56->_projection.m02 = 0.0f;
    sjt_cast56->_projection.m03 = 0.0f;
    sjt_cast56->_projection.m10 = 0.0f;
    sjt_cast56->_projection.m11 = 0.0f;
    sjt_cast56->_projection.m12 = 0.0f;
    sjt_cast56->_projection.m13 = 0.0f;
    sjt_cast56->_projection.m20 = 0.0f;
    sjt_cast56->_projection.m21 = 0.0f;
    sjt_cast56->_projection.m22 = 0.0f;
    sjt_cast56->_projection.m23 = 0.0f;
    sjt_cast56->_projection.m30 = 0.0f;
    sjt_cast56->_projection.m31 = 0.0f;
    sjt_cast56->_projection.m32 = 0.0f;
    sjt_cast56->_projection.m33 = 0.0f;
    sjf_mat4(&sjt_cast56->_projection);
    sjt_cast56->_view._refCount = 1;
    sjt_cast56->_view.m00 = 0.0f;
    sjt_cast56->_view.m01 = 0.0f;
    sjt_cast56->_view.m02 = 0.0f;
    sjt_cast56->_view.m03 = 0.0f;
    sjt_cast56->_view.m10 = 0.0f;
    sjt_cast56->_view.m11 = 0.0f;
    sjt_cast56->_view.m12 = 0.0f;
    sjt_cast56->_view.m13 = 0.0f;
    sjt_cast56->_view.m20 = 0.0f;
    sjt_cast56->_view.m21 = 0.0f;
    sjt_cast56->_view.m22 = 0.0f;
    sjt_cast56->_view.m23 = 0.0f;
    sjt_cast56->_view.m30 = 0.0f;
    sjt_cast56->_view.m31 = 0.0f;
    sjt_cast56->_view.m32 = 0.0f;
    sjt_cast56->_view.m33 = 0.0f;
    sjf_mat4(&sjt_cast56->_view);
    sjt_cast56->_world._refCount = 1;
    sjt_cast56->_world.m00 = 0.0f;
    sjt_cast56->_world.m01 = 0.0f;
    sjt_cast56->_world.m02 = 0.0f;
    sjt_cast56->_world.m03 = 0.0f;
    sjt_cast56->_world.m10 = 0.0f;
    sjt_cast56->_world.m11 = 0.0f;
    sjt_cast56->_world.m12 = 0.0f;
    sjt_cast56->_world.m13 = 0.0f;
    sjt_cast56->_world.m20 = 0.0f;
    sjt_cast56->_world.m21 = 0.0f;
    sjt_cast56->_world.m22 = 0.0f;
    sjt_cast56->_world.m23 = 0.0f;
    sjt_cast56->_world.m30 = 0.0f;
    sjt_cast56->_world.m31 = 0.0f;
    sjt_cast56->_world.m32 = 0.0f;
    sjt_cast56->_world.m33 = 0.0f;
    sjf_mat4(&sjt_cast56->_world);
    sjt_cast56->_light._refCount = 1;
    sjt_cast56->_light.pos._refCount = 1;
    sjt_cast56->_light.pos.x = 1.0f;
    sjt_cast56->_light.pos.y = 1.0f;
    sjt_cast56->_light.pos.z = 1.0f;
    sjf_vec3(&sjt_cast56->_light.pos);
    sjt_cast56->_light.diffusecolor._refCount = 1;
    sjt_cast56->_light.diffusecolor.r = 0.5f;
    sjt_cast56->_light.diffusecolor.g = 0.5f;
    sjt_cast56->_light.diffusecolor.b = 0.0f;
    sjt_cast56->_light.diffusecolor.a = 1.0f;
    sjf_color(&sjt_cast56->_light.diffusecolor);
    sjt_cast56->_light.speccolor._refCount = 1;
    sjt_cast56->_light.speccolor.r = 1.0f;
    sjt_cast56->_light.speccolor.g = 1.0f;
    sjt_cast56->_light.speccolor.b = 1.0f;
    sjt_cast56->_light.speccolor.a = 1.0f;
    sjf_color(&sjt_cast56->_light.speccolor);
    sjf_light(&sjt_cast56->_light);
    sjt_cast56->_projectedcenter._refCount = 1;
    sjt_cast56->_projectedcenter.x = 0.0f;
    sjt_cast56->_projectedcenter.y = 0.0f;
    sjt_cast56->_projectedcenter.z = 0.0f;
    sjf_vec3(&sjt_cast56->_projectedcenter);
    sjf_model_heap(sjt_cast56);
    sjt_functionParam639 = (sji_model*)sjf_model_heap_as_sji_model(sjt_cast56);
    sjf_array_heap_model_initat(sjt_parent228, sjt_functionParam638, sjt_functionParam639);
    sjt_parent230 = array10;
    sjt_functionParam657 = 7;
    sjt_cast57 = (sjs_model*)malloc(sizeof(sjs_model));
    sjt_cast57->_refCount = 1;
    sjt_negate44 = 4.3f;
    result54 = -sjt_negate44;
    sjt_functionParam659 = result54;
    sjt_functionParam660 = 4.3f;
    sjt_negate45 = 1.0f;
    result55 = -sjt_negate45;
    sjt_functionParam661 = result55;
    sjt_functionParam662 = 1.0f;
    sjt_functionParam663 = 0.0f;
    sjt_functionParam664 = 0.0f;
    sjt_functionParam665 = 1.0f;
    sjt_functionParam666 = 0.0f;
    sjt_functionParam667 = 1.0f;
    sjf_planevertexbuffer(sjt_functionParam659, sjt_functionParam660, sjt_functionParam661, sjt_functionParam662, sjt_functionParam663, sjt_functionParam664, sjt_functionParam665, sjt_functionParam666, sjt_functionParam667, &sjt_cast57->vertexbuffer);
    sjt_copy53 = &sjv_phongtextureshader;
    sjt_cast57->shader._refCount = 1;
    sjf_shader_copy(&sjt_cast57->shader, sjt_copy53);
    sjt_call98._refCount = 1;
    sjt_call98.count = 16;
    sjt_call98.data._refCount = 1;
    sjt_call98.data.datasize = 17;
    sjt_call98.data.data = (void*)sjg_string46;
    sjt_call98.data._isglobal = true;
    sjt_call98.data.count = 17;
    sjf_array_char(&sjt_call98.data);
    sjf_string(&sjt_call98);
    sjt_functionParam668 = &sjt_call98;
    sjf_texturefrompng(sjt_functionParam668, &sjt_cast57->texture);
    sjt_functionParam669 = 6.6f;
    sjt_functionParam670 = 0.0f;
    sjt_functionParam671 = 0.2f;
    sjf_mat4_translate(sjt_functionParam669, sjt_functionParam670, sjt_functionParam671, &sjt_call99);
    sjt_parent231 = &sjt_call99;
    sjt_functionParam673 = 2.0f;
    sjt_functionParam674 = 2.0f;
    sjt_functionParam675 = 2.0f;
    sjf_mat4_scale(sjt_functionParam673, sjt_functionParam674, sjt_functionParam675, &sjt_call100);
    sjt_functionParam672 = &sjt_call100;
    sjf_mat4_multiply(sjt_parent231, sjt_functionParam672, &sjt_cast57->model);
    sjt_cast57->center._refCount = 1;
    sjt_cast57->center.x = 0.0f;
    sjt_cast57->center.y = 0.0f;
    sjt_cast57->center.z = 0.0f;
    sjf_vec3(&sjt_cast57->center);
    sjt_cast57->hasalpha = true;
    sjt_cast57->id._refCount = 1;
    sjt_cast57->id.count = 8;
    sjt_cast57->id.data._refCount = 1;
    sjt_cast57->id.data.datasize = 9;
    sjt_cast57->id.data.data = (void*)sjg_string45;
    sjt_cast57->id.data._isglobal = true;
    sjt_cast57->id.data.count = 9;
    sjf_array_char(&sjt_cast57->id.data);
    sjf_string(&sjt_cast57->id);
    sjt_cast57->_projection._refCount = 1;
    sjt_cast57->_projection.m00 = 0.0f;
    sjt_cast57->_projection.m01 = 0.0f;
    sjt_cast57->_projection.m02 = 0.0f;
    sjt_cast57->_projection.m03 = 0.0f;
    sjt_cast57->_projection.m10 = 0.0f;
    sjt_cast57->_projection.m11 = 0.0f;
    sjt_cast57->_projection.m12 = 0.0f;
    sjt_cast57->_projection.m13 = 0.0f;
    sjt_cast57->_projection.m20 = 0.0f;
    sjt_cast57->_projection.m21 = 0.0f;
    sjt_cast57->_projection.m22 = 0.0f;
    sjt_cast57->_projection.m23 = 0.0f;
    sjt_cast57->_projection.m30 = 0.0f;
    sjt_cast57->_projection.m31 = 0.0f;
    sjt_cast57->_projection.m32 = 0.0f;
    sjt_cast57->_projection.m33 = 0.0f;
    sjf_mat4(&sjt_cast57->_projection);
    sjt_cast57->_view._refCount = 1;
    sjt_cast57->_view.m00 = 0.0f;
    sjt_cast57->_view.m01 = 0.0f;
    sjt_cast57->_view.m02 = 0.0f;
    sjt_cast57->_view.m03 = 0.0f;
    sjt_cast57->_view.m10 = 0.0f;
    sjt_cast57->_view.m11 = 0.0f;
    sjt_cast57->_view.m12 = 0.0f;
    sjt_cast57->_view.m13 = 0.0f;
    sjt_cast57->_view.m20 = 0.0f;
    sjt_cast57->_view.m21 = 0.0f;
    sjt_cast57->_view.m22 = 0.0f;
    sjt_cast57->_view.m23 = 0.0f;
    sjt_cast57->_view.m30 = 0.0f;
    sjt_cast57->_view.m31 = 0.0f;
    sjt_cast57->_view.m32 = 0.0f;
    sjt_cast57->_view.m33 = 0.0f;
    sjf_mat4(&sjt_cast57->_view);
    sjt_cast57->_world._refCount = 1;
    sjt_cast57->_world.m00 = 0.0f;
    sjt_cast57->_world.m01 = 0.0f;
    sjt_cast57->_world.m02 = 0.0f;
    sjt_cast57->_world.m03 = 0.0f;
    sjt_cast57->_world.m10 = 0.0f;
    sjt_cast57->_world.m11 = 0.0f;
    sjt_cast57->_world.m12 = 0.0f;
    sjt_cast57->_world.m13 = 0.0f;
    sjt_cast57->_world.m20 = 0.0f;
    sjt_cast57->_world.m21 = 0.0f;
    sjt_cast57->_world.m22 = 0.0f;
    sjt_cast57->_world.m23 = 0.0f;
    sjt_cast57->_world.m30 = 0.0f;
    sjt_cast57->_world.m31 = 0.0f;
    sjt_cast57->_world.m32 = 0.0f;
    sjt_cast57->_world.m33 = 0.0f;
    sjf_mat4(&sjt_cast57->_world);
    sjt_cast57->_light._refCount = 1;
    sjt_cast57->_light.pos._refCount = 1;
    sjt_cast57->_light.pos.x = 1.0f;
    sjt_cast57->_light.pos.y = 1.0f;
    sjt_cast57->_light.pos.z = 1.0f;
    sjf_vec3(&sjt_cast57->_light.pos);
    sjt_cast57->_light.diffusecolor._refCount = 1;
    sjt_cast57->_light.diffusecolor.r = 0.5f;
    sjt_cast57->_light.diffusecolor.g = 0.5f;
    sjt_cast57->_light.diffusecolor.b = 0.0f;
    sjt_cast57->_light.diffusecolor.a = 1.0f;
    sjf_color(&sjt_cast57->_light.diffusecolor);
    sjt_cast57->_light.speccolor._refCount = 1;
    sjt_cast57->_light.speccolor.r = 1.0f;
    sjt_cast57->_light.speccolor.g = 1.0f;
    sjt_cast57->_light.speccolor.b = 1.0f;
    sjt_cast57->_light.speccolor.a = 1.0f;
    sjf_color(&sjt_cast57->_light.speccolor);
    sjf_light(&sjt_cast57->_light);
    sjt_cast57->_projectedcenter._refCount = 1;
    sjt_cast57->_projectedcenter.x = 0.0f;
    sjt_cast57->_projectedcenter.y = 0.0f;
    sjt_cast57->_projectedcenter.z = 0.0f;
    sjf_vec3(&sjt_cast57->_projectedcenter);
    sjf_model_heap(sjt_cast57);
    sjt_functionParam658 = (sji_model*)sjf_model_heap_as_sji_model(sjt_cast57);
    sjf_array_heap_model_initat(sjt_parent230, sjt_functionParam657, sjt_functionParam658);
    sjt_parent232 = array10;
    sjt_functionParam676 = 8;
    sjt_cast58 = (sjs_model*)malloc(sizeof(sjs_model));
    sjt_cast58->_refCount = 1;
    sjt_negate46 = 4.3f;
    result56 = -sjt_negate46;
    sjt_functionParam678 = result56;
    sjt_functionParam679 = 4.3f;
    sjt_negate47 = 1.0f;
    result57 = -sjt_negate47;
    sjt_functionParam680 = result57;
    sjt_functionParam681 = 1.0f;
    sjt_functionParam682 = 0.0f;
    sjt_functionParam683 = 0.0f;
    sjt_functionParam684 = 1.0f;
    sjt_functionParam685 = 0.0f;
    sjt_functionParam686 = 1.0f;
    sjf_planevertexbuffer(sjt_functionParam678, sjt_functionParam679, sjt_functionParam680, sjt_functionParam681, sjt_functionParam682, sjt_functionParam683, sjt_functionParam684, sjt_functionParam685, sjt_functionParam686, &sjt_cast58->vertexbuffer);
    sjt_copy54 = &sjv_phongtextureshader;
    sjt_cast58->shader._refCount = 1;
    sjf_shader_copy(&sjt_cast58->shader, sjt_copy54);
    sjt_call101._refCount = 1;
    sjt_call101.count = 16;
    sjt_call101.data._refCount = 1;
    sjt_call101.data.datasize = 17;
    sjt_call101.data.data = (void*)sjg_string48;
    sjt_call101.data._isglobal = true;
    sjt_call101.data.count = 17;
    sjf_array_char(&sjt_call101.data);
    sjf_string(&sjt_call101);
    sjt_functionParam687 = &sjt_call101;
    sjf_texturefrompng(sjt_functionParam687, &sjt_cast58->texture);
    sjt_negate48 = 8.6f;
    result58 = -sjt_negate48;
    sjt_functionParam688 = result58;
    sjt_functionParam689 = 0.0f;
    sjt_negate49 = 1.8f;
    result59 = -sjt_negate49;
    sjt_functionParam690 = result59;
    sjf_mat4_translate(sjt_functionParam688, sjt_functionParam689, sjt_functionParam690, &sjt_call102);
    sjt_parent233 = &sjt_call102;
    sjt_functionParam692 = 2.0f;
    sjt_functionParam693 = 2.0f;
    sjt_functionParam694 = 2.0f;
    sjf_mat4_scale(sjt_functionParam692, sjt_functionParam693, sjt_functionParam694, &sjt_call103);
    sjt_functionParam691 = &sjt_call103;
    sjf_mat4_multiply(sjt_parent233, sjt_functionParam691, &sjt_cast58->model);
    sjt_cast58->center._refCount = 1;
    sjt_cast58->center.x = 0.0f;
    sjt_cast58->center.y = 0.0f;
    sjt_cast58->center.z = 0.0f;
    sjf_vec3(&sjt_cast58->center);
    sjt_cast58->hasalpha = true;
    sjt_cast58->id._refCount = 1;
    sjt_cast58->id.count = 9;
    sjt_cast58->id.data._refCount = 1;
    sjt_cast58->id.data.datasize = 10;
    sjt_cast58->id.data.data = (void*)sjg_string47;
    sjt_cast58->id.data._isglobal = true;
    sjt_cast58->id.data.count = 10;
    sjf_array_char(&sjt_cast58->id.data);
    sjf_string(&sjt_cast58->id);
    sjt_cast58->_projection._refCount = 1;
    sjt_cast58->_projection.m00 = 0.0f;
    sjt_cast58->_projection.m01 = 0.0f;
    sjt_cast58->_projection.m02 = 0.0f;
    sjt_cast58->_projection.m03 = 0.0f;
    sjt_cast58->_projection.m10 = 0.0f;
    sjt_cast58->_projection.m11 = 0.0f;
    sjt_cast58->_projection.m12 = 0.0f;
    sjt_cast58->_projection.m13 = 0.0f;
    sjt_cast58->_projection.m20 = 0.0f;
    sjt_cast58->_projection.m21 = 0.0f;
    sjt_cast58->_projection.m22 = 0.0f;
    sjt_cast58->_projection.m23 = 0.0f;
    sjt_cast58->_projection.m30 = 0.0f;
    sjt_cast58->_projection.m31 = 0.0f;
    sjt_cast58->_projection.m32 = 0.0f;
    sjt_cast58->_projection.m33 = 0.0f;
    sjf_mat4(&sjt_cast58->_projection);
    sjt_cast58->_view._refCount = 1;
    sjt_cast58->_view.m00 = 0.0f;
    sjt_cast58->_view.m01 = 0.0f;
    sjt_cast58->_view.m02 = 0.0f;
    sjt_cast58->_view.m03 = 0.0f;
    sjt_cast58->_view.m10 = 0.0f;
    sjt_cast58->_view.m11 = 0.0f;
    sjt_cast58->_view.m12 = 0.0f;
    sjt_cast58->_view.m13 = 0.0f;
    sjt_cast58->_view.m20 = 0.0f;
    sjt_cast58->_view.m21 = 0.0f;
    sjt_cast58->_view.m22 = 0.0f;
    sjt_cast58->_view.m23 = 0.0f;
    sjt_cast58->_view.m30 = 0.0f;
    sjt_cast58->_view.m31 = 0.0f;
    sjt_cast58->_view.m32 = 0.0f;
    sjt_cast58->_view.m33 = 0.0f;
    sjf_mat4(&sjt_cast58->_view);
    sjt_cast58->_world._refCount = 1;
    sjt_cast58->_world.m00 = 0.0f;
    sjt_cast58->_world.m01 = 0.0f;
    sjt_cast58->_world.m02 = 0.0f;
    sjt_cast58->_world.m03 = 0.0f;
    sjt_cast58->_world.m10 = 0.0f;
    sjt_cast58->_world.m11 = 0.0f;
    sjt_cast58->_world.m12 = 0.0f;
    sjt_cast58->_world.m13 = 0.0f;
    sjt_cast58->_world.m20 = 0.0f;
    sjt_cast58->_world.m21 = 0.0f;
    sjt_cast58->_world.m22 = 0.0f;
    sjt_cast58->_world.m23 = 0.0f;
    sjt_cast58->_world.m30 = 0.0f;
    sjt_cast58->_world.m31 = 0.0f;
    sjt_cast58->_world.m32 = 0.0f;
    sjt_cast58->_world.m33 = 0.0f;
    sjf_mat4(&sjt_cast58->_world);
    sjt_cast58->_light._refCount = 1;
    sjt_cast58->_light.pos._refCount = 1;
    sjt_cast58->_light.pos.x = 1.0f;
    sjt_cast58->_light.pos.y = 1.0f;
    sjt_cast58->_light.pos.z = 1.0f;
    sjf_vec3(&sjt_cast58->_light.pos);
    sjt_cast58->_light.diffusecolor._refCount = 1;
    sjt_cast58->_light.diffusecolor.r = 0.5f;
    sjt_cast58->_light.diffusecolor.g = 0.5f;
    sjt_cast58->_light.diffusecolor.b = 0.0f;
    sjt_cast58->_light.diffusecolor.a = 1.0f;
    sjf_color(&sjt_cast58->_light.diffusecolor);
    sjt_cast58->_light.speccolor._refCount = 1;
    sjt_cast58->_light.speccolor.r = 1.0f;
    sjt_cast58->_light.speccolor.g = 1.0f;
    sjt_cast58->_light.speccolor.b = 1.0f;
    sjt_cast58->_light.speccolor.a = 1.0f;
    sjf_color(&sjt_cast58->_light.speccolor);
    sjf_light(&sjt_cast58->_light);
    sjt_cast58->_projectedcenter._refCount = 1;
    sjt_cast58->_projectedcenter.x = 0.0f;
    sjt_cast58->_projectedcenter.y = 0.0f;
    sjt_cast58->_projectedcenter.z = 0.0f;
    sjf_vec3(&sjt_cast58->_projectedcenter);
    sjf_model_heap(sjt_cast58);
    sjt_functionParam677 = (sji_model*)sjf_model_heap_as_sji_model(sjt_cast58);
    sjf_array_heap_model_initat(sjt_parent232, sjt_functionParam676, sjt_functionParam677);
    sjt_parent234 = array10;
    sjt_functionParam695 = 9;
    sjt_cast59 = (sjs_model*)malloc(sizeof(sjs_model));
    sjt_cast59->_refCount = 1;
    sjt_negate50 = 4.3f;
    result60 = -sjt_negate50;
    sjt_functionParam697 = result60;
    sjt_functionParam698 = 4.3f;
    sjt_negate51 = 1.0f;
    result61 = -sjt_negate51;
    sjt_functionParam699 = result61;
    sjt_functionParam700 = 1.0f;
    sjt_functionParam701 = 0.0f;
    sjt_functionParam702 = 0.0f;
    sjt_functionParam703 = 1.0f;
    sjt_functionParam704 = 0.0f;
    sjt_functionParam705 = 1.0f;
    sjf_planevertexbuffer(sjt_functionParam697, sjt_functionParam698, sjt_functionParam699, sjt_functionParam700, sjt_functionParam701, sjt_functionParam702, sjt_functionParam703, sjt_functionParam704, sjt_functionParam705, &sjt_cast59->vertexbuffer);
    sjt_copy55 = &sjv_phongtextureshader;
    sjt_cast59->shader._refCount = 1;
    sjf_shader_copy(&sjt_cast59->shader, sjt_copy55);
    sjt_call104._refCount = 1;
    sjt_call104.count = 16;
    sjt_call104.data._refCount = 1;
    sjt_call104.data.datasize = 17;
    sjt_call104.data.data = (void*)sjg_string50;
    sjt_call104.data._isglobal = true;
    sjt_call104.data.count = 17;
    sjf_array_char(&sjt_call104.data);
    sjf_string(&sjt_call104);
    sjt_functionParam706 = &sjt_call104;
    sjf_texturefrompng(sjt_functionParam706, &sjt_cast59->texture);
    sjt_functionParam707 = 8.6f;
    sjt_functionParam708 = 0.0f;
    sjt_negate52 = 1.8f;
    result62 = -sjt_negate52;
    sjt_functionParam709 = result62;
    sjf_mat4_translate(sjt_functionParam707, sjt_functionParam708, sjt_functionParam709, &sjt_call105);
    sjt_parent235 = &sjt_call105;
    sjt_functionParam711 = 2.0f;
    sjt_functionParam712 = 2.0f;
    sjt_functionParam713 = 2.0f;
    sjf_mat4_scale(sjt_functionParam711, sjt_functionParam712, sjt_functionParam713, &sjt_call106);
    sjt_functionParam710 = &sjt_call106;
    sjf_mat4_multiply(sjt_parent235, sjt_functionParam710, &sjt_cast59->model);
    sjt_cast59->center._refCount = 1;
    sjt_cast59->center.x = 0.0f;
    sjt_cast59->center.y = 0.0f;
    sjt_cast59->center.z = 0.0f;
    sjf_vec3(&sjt_cast59->center);
    sjt_cast59->hasalpha = true;
    sjt_cast59->id._refCount = 1;
    sjt_cast59->id.count = 9;
    sjt_cast59->id.data._refCount = 1;
    sjt_cast59->id.data.datasize = 10;
    sjt_cast59->id.data.data = (void*)sjg_string49;
    sjt_cast59->id.data._isglobal = true;
    sjt_cast59->id.data.count = 10;
    sjf_array_char(&sjt_cast59->id.data);
    sjf_string(&sjt_cast59->id);
    sjt_cast59->_projection._refCount = 1;
    sjt_cast59->_projection.m00 = 0.0f;
    sjt_cast59->_projection.m01 = 0.0f;
    sjt_cast59->_projection.m02 = 0.0f;
    sjt_cast59->_projection.m03 = 0.0f;
    sjt_cast59->_projection.m10 = 0.0f;
    sjt_cast59->_projection.m11 = 0.0f;
    sjt_cast59->_projection.m12 = 0.0f;
    sjt_cast59->_projection.m13 = 0.0f;
    sjt_cast59->_projection.m20 = 0.0f;
    sjt_cast59->_projection.m21 = 0.0f;
    sjt_cast59->_projection.m22 = 0.0f;
    sjt_cast59->_projection.m23 = 0.0f;
    sjt_cast59->_projection.m30 = 0.0f;
    sjt_cast59->_projection.m31 = 0.0f;
    sjt_cast59->_projection.m32 = 0.0f;
    sjt_cast59->_projection.m33 = 0.0f;
    sjf_mat4(&sjt_cast59->_projection);
    sjt_cast59->_view._refCount = 1;
    sjt_cast59->_view.m00 = 0.0f;
    sjt_cast59->_view.m01 = 0.0f;
    sjt_cast59->_view.m02 = 0.0f;
    sjt_cast59->_view.m03 = 0.0f;
    sjt_cast59->_view.m10 = 0.0f;
    sjt_cast59->_view.m11 = 0.0f;
    sjt_cast59->_view.m12 = 0.0f;
    sjt_cast59->_view.m13 = 0.0f;
    sjt_cast59->_view.m20 = 0.0f;
    sjt_cast59->_view.m21 = 0.0f;
    sjt_cast59->_view.m22 = 0.0f;
    sjt_cast59->_view.m23 = 0.0f;
    sjt_cast59->_view.m30 = 0.0f;
    sjt_cast59->_view.m31 = 0.0f;
    sjt_cast59->_view.m32 = 0.0f;
    sjt_cast59->_view.m33 = 0.0f;
    sjf_mat4(&sjt_cast59->_view);
    sjt_cast59->_world._refCount = 1;
    sjt_cast59->_world.m00 = 0.0f;
    sjt_cast59->_world.m01 = 0.0f;
    sjt_cast59->_world.m02 = 0.0f;
    sjt_cast59->_world.m03 = 0.0f;
    sjt_cast59->_world.m10 = 0.0f;
    sjt_cast59->_world.m11 = 0.0f;
    sjt_cast59->_world.m12 = 0.0f;
    sjt_cast59->_world.m13 = 0.0f;
    sjt_cast59->_world.m20 = 0.0f;
    sjt_cast59->_world.m21 = 0.0f;
    sjt_cast59->_world.m22 = 0.0f;
    sjt_cast59->_world.m23 = 0.0f;
    sjt_cast59->_world.m30 = 0.0f;
    sjt_cast59->_world.m31 = 0.0f;
    sjt_cast59->_world.m32 = 0.0f;
    sjt_cast59->_world.m33 = 0.0f;
    sjf_mat4(&sjt_cast59->_world);
    sjt_cast59->_light._refCount = 1;
    sjt_cast59->_light.pos._refCount = 1;
    sjt_cast59->_light.pos.x = 1.0f;
    sjt_cast59->_light.pos.y = 1.0f;
    sjt_cast59->_light.pos.z = 1.0f;
    sjf_vec3(&sjt_cast59->_light.pos);
    sjt_cast59->_light.diffusecolor._refCount = 1;
    sjt_cast59->_light.diffusecolor.r = 0.5f;
    sjt_cast59->_light.diffusecolor.g = 0.5f;
    sjt_cast59->_light.diffusecolor.b = 0.0f;
    sjt_cast59->_light.diffusecolor.a = 1.0f;
    sjf_color(&sjt_cast59->_light.diffusecolor);
    sjt_cast59->_light.speccolor._refCount = 1;
    sjt_cast59->_light.speccolor.r = 1.0f;
    sjt_cast59->_light.speccolor.g = 1.0f;
    sjt_cast59->_light.speccolor.b = 1.0f;
    sjt_cast59->_light.speccolor.a = 1.0f;
    sjf_color(&sjt_cast59->_light.speccolor);
    sjf_light(&sjt_cast59->_light);
    sjt_cast59->_projectedcenter._refCount = 1;
    sjt_cast59->_projectedcenter.x = 0.0f;
    sjt_cast59->_projectedcenter.y = 0.0f;
    sjt_cast59->_projectedcenter.z = 0.0f;
    sjf_vec3(&sjt_cast59->_projectedcenter);
    sjf_model_heap(sjt_cast59);
    sjt_functionParam696 = (sji_model*)sjf_model_heap_as_sji_model(sjt_cast59);
    sjf_array_heap_model_initat(sjt_parent234, sjt_functionParam695, sjt_functionParam696);
    sjf_panel3d_heap(sjt_cast49);
    sjt_functionParam516 = (sji_model*)sjf_panel3d_heap_as_sji_model(sjt_cast49);
    sjf_array_heap_model_initat(sjt_parent208, sjt_functionParam515, sjt_functionParam516);
    sjt_cast2->lookatmin._refCount = 1;
    sjt_negate53 = 16.0f;
    result63 = -sjt_negate53;
    sjt_cast2->lookatmin.x = result63;
    sjt_negate54 = 1.0f;
    result64 = -sjt_negate54;
    sjt_cast2->lookatmin.y = result64;
    sjt_cast2->lookatmin.z = 0.0f;
    sjf_vec3(&sjt_cast2->lookatmin);
    sjt_cast2->lookatmax._refCount = 1;
    sjt_cast2->lookatmax.x = 16.0f;
    sjt_cast2->lookatmax.y = 1.0f;
    sjt_cast2->lookatmax.z = 6.0f;
    sjf_vec3(&sjt_cast2->lookatmax);
    sjt_cast2->fieldofview = 90.0f;
    sjt_cast2->znear = 1.0f;
    sjt_cast2->zfar = 50.0f;
    sjt_cast2->light._refCount = 1;
    sjt_cast2->light.pos._refCount = 1;
    sjt_cast2->light.pos.x = 1.0f;
    sjt_cast2->light.pos.y = 1.0f;
    sjt_cast2->light.pos.z = 1.0f;
    sjf_vec3(&sjt_cast2->light.pos);
    sjt_cast2->light.diffusecolor._refCount = 1;
    sjt_cast2->light.diffusecolor.r = 0.5f;
    sjt_cast2->light.diffusecolor.g = 0.5f;
    sjt_cast2->light.diffusecolor.b = 0.0f;
    sjt_cast2->light.diffusecolor.a = 1.0f;
    sjf_color(&sjt_cast2->light.diffusecolor);
    sjt_cast2->light.speccolor._refCount = 1;
    sjt_cast2->light.speccolor.r = 1.0f;
    sjt_cast2->light.speccolor.g = 1.0f;
    sjt_cast2->light.speccolor.b = 1.0f;
    sjt_cast2->light.speccolor.a = 1.0f;
    sjf_color(&sjt_cast2->light.speccolor);
    sjf_light(&sjt_cast2->light);
    sjt_cast2->projection._refCount = 1;
    sjt_cast2->projection.m00 = 0.0f;
    sjt_cast2->projection.m01 = 0.0f;
    sjt_cast2->projection.m02 = 0.0f;
    sjt_cast2->projection.m03 = 0.0f;
    sjt_cast2->projection.m10 = 0.0f;
    sjt_cast2->projection.m11 = 0.0f;
    sjt_cast2->projection.m12 = 0.0f;
    sjt_cast2->projection.m13 = 0.0f;
    sjt_cast2->projection.m20 = 0.0f;
    sjt_cast2->projection.m21 = 0.0f;
    sjt_cast2->projection.m22 = 0.0f;
    sjt_cast2->projection.m23 = 0.0f;
    sjt_cast2->projection.m30 = 0.0f;
    sjt_cast2->projection.m31 = 0.0f;
    sjt_cast2->projection.m32 = 0.0f;
    sjt_cast2->projection.m33 = 0.0f;
    sjf_mat4(&sjt_cast2->projection);
    sjt_call107._refCount = 1;
    sjt_call107.x = 0.0f;
    sjt_call107.y = 0.0f;
    sjt_negate55 = 5.0f;
    result65 = -sjt_negate55;
    sjt_call107.z = result65;
    sjf_vec3(&sjt_call107);
    sjt_functionParam714 = &sjt_call107;
    sjt_call108._refCount = 1;
    sjt_call108.x = 0.0f;
    sjt_call108.y = 0.0f;
    sjt_call108.z = 0.0f;
    sjf_vec3(&sjt_call108);
    sjt_functionParam715 = &sjt_call108;
    sjt_call109._refCount = 1;
    sjt_call109.x = 0.0f;
    sjt_call109.y = 1.0f;
    sjt_call109.z = 0.0f;
    sjf_vec3(&sjt_call109);
    sjt_functionParam716 = &sjt_call109;
    sjf_mat4_lookatlh(sjt_functionParam714, sjt_functionParam715, sjt_functionParam716, &sjt_cast2->view);
    sjf_mat4_identity(&sjt_cast2->world);
    sjt_cast2->_rect._refCount = 1;
    sjt_cast2->_rect.x = 0;
    sjt_cast2->_rect.y = 0;
    sjt_cast2->_rect.w = 0;
    sjt_cast2->_rect.h = 0;
    sjf_rect(&sjt_cast2->_rect);
    sjt_cast2->_isdragging = false;
    sjt_cast2->_startdrag._refCount = 1;
    sjt_cast2->_startdrag.x = 0;
    sjt_cast2->_startdrag.y = 0;
    sjf_point(&sjt_cast2->_startdrag);
    sjt_cast2->_lookat._refCount = 1;
    sjt_cast2->_lookat.x = 0.0f;
    sjt_cast2->_lookat.y = 0.0f;
    sjt_cast2->_lookat.z = 0.0f;
    sjf_vec3(&sjt_cast2->_lookat);
    sjt_cast2->_lookatdrag._refCount = 1;
    sjt_cast2->_lookatdrag.x = 0.0f;
    sjt_cast2->_lookatdrag.y = 0.0f;
    sjt_cast2->_lookatdrag.z = 0.0f;
    sjf_vec3(&sjt_cast2->_lookatdrag);
    sjf_nauscene3delement_heap(sjt_cast2);
    sjt_functionParam5 = (sji_element*)sjf_nauscene3delement_heap_as_sji_element(sjt_cast2);
    sjf_array_heap_element_initat(sjt_parent7, sjt_functionParam4, sjt_functionParam5);
    sjt_parent236 = array11;
    sjt_functionParam717 = 1;
    sjt_cast60 = (sjs_crosshairselement*)malloc(sizeof(sjs_crosshairselement));
    sjt_cast60->_refCount = 1;
    sjt_parent237 = &sjv_colors;
    sjf_anon4_red(sjt_parent237, &sjt_cast60->color);
    sjt_cast60->_rect._refCount = 1;
    sjt_cast60->_rect.x = 0;
    sjt_cast60->_rect.y = 0;
    sjt_cast60->_rect.w = 0;
    sjt_cast60->_rect.h = 0;
    sjf_rect(&sjt_cast60->_rect);
    sjt_cast60->_topdownrenderer._refCount = -1;
    sjt_cast60->_leftrightrenderer._refCount = -1;
    sjt_cast60->_point._refCount = 1;
    sjt_cast60->_point.x = 0;
    sjt_cast60->_point.y = 0;
    sjf_point(&sjt_cast60->_point);
    sjf_crosshairselement_heap(sjt_cast60);
    sjt_functionParam718 = (sji_element*)sjf_crosshairselement_heap_as_sji_element(sjt_cast60);
    sjf_array_heap_element_initat(sjt_parent236, sjt_functionParam717, sjt_functionParam718);
    sjt_cast1->_rect._refCount = 1;
    sjt_cast1->_rect.x = 0;
    sjt_cast1->_rect.y = 0;
    sjt_cast1->_rect.w = 0;
    sjt_cast1->_rect.h = 0;
    sjf_rect(&sjt_cast1->_rect);
    sjf_fillelement_heap(sjt_cast1);
    sjv_root = (sji_element*)sjf_fillelement_heap_as_sji_element(sjt_cast1);
    sjf_runloop();
    main_destroy();
    #ifdef _DEBUG
    printf("\npress return to end\n");
    getchar();
    #endif
    return 0;
}

void main_destroy() {

    sjt_cast1->_refCount--;
    if (sjt_cast1->_refCount <= 0) {
        sjf_fillelement_destroy(sjt_cast1);
    }
    sjt_cast11->_refCount--;
    if (sjt_cast11->_refCount <= 0) {
        sjf_model_destroy(sjt_cast11);
    }
    sjt_cast13->_refCount--;
    if (sjt_cast13->_refCount <= 0) {
        sjf_leafpanel_destroy(sjt_cast13);
    }
    sjt_cast19->_refCount--;
    if (sjt_cast19->_refCount <= 0) {
        sjf_peoplepanel_destroy(sjt_cast19);
    }
    sjt_cast2->_refCount--;
    if (sjt_cast2->_refCount <= 0) {
        sjf_nauscene3delement_destroy(sjt_cast2);
    }
    sjt_cast30->_refCount--;
    if (sjt_cast30->_refCount <= 0) {
        sjf_scene2dmodel_destroy(sjt_cast30);
    }
    sjt_cast42->_refCount--;
    if (sjt_cast42->_refCount <= 0) {
        sjf_boxelement_destroy(sjt_cast42);
    }
    sjt_cast43->_refCount--;
    if (sjt_cast43->_refCount <= 0) {
        sjf_imageelement_destroy(sjt_cast43);
    }
    sjt_cast44->_refCount--;
    if (sjt_cast44->_refCount <= 0) {
        sjf_crosshairselement_destroy(sjt_cast44);
    }
    sjt_cast45->_refCount--;
    if (sjt_cast45->_refCount <= 0) {
        sjf_scene2dmodel_destroy(sjt_cast45);
    }
    sjt_cast46->_refCount--;
    if (sjt_cast46->_refCount <= 0) {
        sjf_boxelement_destroy(sjt_cast46);
    }
    sjt_cast47->_refCount--;
    if (sjt_cast47->_refCount <= 0) {
        sjf_imageelement_destroy(sjt_cast47);
    }
    sjt_cast48->_refCount--;
    if (sjt_cast48->_refCount <= 0) {
        sjf_crosshairselement_destroy(sjt_cast48);
    }
    sjt_cast49->_refCount--;
    if (sjt_cast49->_refCount <= 0) {
        sjf_panel3d_destroy(sjt_cast49);
    }
    sjt_cast50->_refCount--;
    if (sjt_cast50->_refCount <= 0) {
        sjf_model_destroy(sjt_cast50);
    }
    sjt_cast51->_refCount--;
    if (sjt_cast51->_refCount <= 0) {
        sjf_model_destroy(sjt_cast51);
    }
    sjt_cast52->_refCount--;
    if (sjt_cast52->_refCount <= 0) {
        sjf_model_destroy(sjt_cast52);
    }
    sjt_cast53->_refCount--;
    if (sjt_cast53->_refCount <= 0) {
        sjf_model_destroy(sjt_cast53);
    }
    sjt_cast54->_refCount--;
    if (sjt_cast54->_refCount <= 0) {
        sjf_model_destroy(sjt_cast54);
    }
    sjt_cast55->_refCount--;
    if (sjt_cast55->_refCount <= 0) {
        sjf_model_destroy(sjt_cast55);
    }
    sjt_cast56->_refCount--;
    if (sjt_cast56->_refCount <= 0) {
        sjf_model_destroy(sjt_cast56);
    }
    sjt_cast57->_refCount--;
    if (sjt_cast57->_refCount <= 0) {
        sjf_model_destroy(sjt_cast57);
    }
    sjt_cast58->_refCount--;
    if (sjt_cast58->_refCount <= 0) {
        sjf_model_destroy(sjt_cast58);
    }
    sjt_cast59->_refCount--;
    if (sjt_cast59->_refCount <= 0) {
        sjf_model_destroy(sjt_cast59);
    }
    sjt_cast60->_refCount--;
    if (sjt_cast60->_refCount <= 0) {
        sjf_crosshairselement_destroy(sjt_cast60);
    }
    sjt_functionParam104->_refCount--;
    if (sjt_functionParam104->_refCount <= 0) {
        sji_model_destroy(sjt_functionParam104);
    }
    sjt_functionParam209->_refCount--;
    if (sjt_functionParam209->_refCount <= 0) {
        sji_model_destroy(sjt_functionParam209);
    }
    sjt_functionParam278->_refCount--;
    if (sjt_functionParam278->_refCount <= 0) {
        sji_model_destroy(sjt_functionParam278);
    }
    sjt_functionParam305->_refCount--;
    if (sjt_functionParam305->_refCount <= 0) {
        sji_model_destroy(sjt_functionParam305);
    }
    sjt_functionParam480->_refCount--;
    if (sjt_functionParam480->_refCount <= 0) {
        sji_element_destroy(sjt_functionParam480);
    }
    sjt_functionParam486->_refCount--;
    if (sjt_functionParam486->_refCount <= 0) {
        sji_element_destroy(sjt_functionParam486);
    }
    sjt_functionParam492->_refCount--;
    if (sjt_functionParam492->_refCount <= 0) {
        sji_element_destroy(sjt_functionParam492);
    }
    sjt_functionParam498->_refCount--;
    if (sjt_functionParam498->_refCount <= 0) {
        sji_model_destroy(sjt_functionParam498);
    }
    sjt_functionParam5->_refCount--;
    if (sjt_functionParam5->_refCount <= 0) {
        sji_element_destroy(sjt_functionParam5);
    }
    sjt_functionParam509->_refCount--;
    if (sjt_functionParam509->_refCount <= 0) {
        sji_element_destroy(sjt_functionParam509);
    }
    sjt_functionParam511->_refCount--;
    if (sjt_functionParam511->_refCount <= 0) {
        sji_element_destroy(sjt_functionParam511);
    }
    sjt_functionParam514->_refCount--;
    if (sjt_functionParam514->_refCount <= 0) {
        sji_element_destroy(sjt_functionParam514);
    }
    sjt_functionParam516->_refCount--;
    if (sjt_functionParam516->_refCount <= 0) {
        sji_model_destroy(sjt_functionParam516);
    }
    sjt_functionParam525->_refCount--;
    if (sjt_functionParam525->_refCount <= 0) {
        sji_model_destroy(sjt_functionParam525);
    }
    sjt_functionParam544->_refCount--;
    if (sjt_functionParam544->_refCount <= 0) {
        sji_model_destroy(sjt_functionParam544);
    }
    sjt_functionParam563->_refCount--;
    if (sjt_functionParam563->_refCount <= 0) {
        sji_model_destroy(sjt_functionParam563);
    }
    sjt_functionParam582->_refCount--;
    if (sjt_functionParam582->_refCount <= 0) {
        sji_model_destroy(sjt_functionParam582);
    }
    sjt_functionParam601->_refCount--;
    if (sjt_functionParam601->_refCount <= 0) {
        sji_model_destroy(sjt_functionParam601);
    }
    sjt_functionParam620->_refCount--;
    if (sjt_functionParam620->_refCount <= 0) {
        sji_model_destroy(sjt_functionParam620);
    }
    sjt_functionParam639->_refCount--;
    if (sjt_functionParam639->_refCount <= 0) {
        sji_model_destroy(sjt_functionParam639);
    }
    sjt_functionParam658->_refCount--;
    if (sjt_functionParam658->_refCount <= 0) {
        sji_model_destroy(sjt_functionParam658);
    }
    sjt_functionParam677->_refCount--;
    if (sjt_functionParam677->_refCount <= 0) {
        sji_model_destroy(sjt_functionParam677);
    }
    sjt_functionParam696->_refCount--;
    if (sjt_functionParam696->_refCount <= 0) {
        sji_model_destroy(sjt_functionParam696);
    }
    sjt_functionParam718->_refCount--;
    if (sjt_functionParam718->_refCount <= 0) {
        sji_element_destroy(sjt_functionParam718);
    }
    if (sjv_mouse_captureelement != 0) {
        sjv_mouse_captureelement->_refCount--;
        if (sjv_mouse_captureelement->_refCount <= 0) {
            sji_element_destroy(sjv_mouse_captureelement);
        }
    }
    sjv_root->_refCount--;
    if (sjv_root->_refCount <= 0) {
        sji_element_destroy(sjv_root);
    }
    if (sjt_call100._refCount == 1) { sjf_mat4_destroy(&sjt_call100); }
    if (sjt_call101._refCount == 1) { sjf_string_destroy(&sjt_call101); }
    if (sjt_call102._refCount == 1) { sjf_mat4_destroy(&sjt_call102); }
    if (sjt_call103._refCount == 1) { sjf_mat4_destroy(&sjt_call103); }
    if (sjt_call104._refCount == 1) { sjf_string_destroy(&sjt_call104); }
    if (sjt_call105._refCount == 1) { sjf_mat4_destroy(&sjt_call105); }
    if (sjt_call106._refCount == 1) { sjf_mat4_destroy(&sjt_call106); }
    if (sjt_call107._refCount == 1) { sjf_vec3_destroy(&sjt_call107); }
    if (sjt_call108._refCount == 1) { sjf_vec3_destroy(&sjt_call108); }
    if (sjt_call109._refCount == 1) { sjf_vec3_destroy(&sjt_call109); }
    if (sjt_call30._refCount == 1) { sjf_string_destroy(&sjt_call30); }
    if (sjt_call31._refCount == 1) { sjf_mat4_destroy(&sjt_call31); }
    if (sjt_call32._refCount == 1) { sjf_mat4_destroy(&sjt_call32); }
    if (sjt_call37._refCount == 1) { sjf_texture_destroy(&sjt_call37); }
    if (sjt_call38._refCount == 1) { sjf_string_destroy(&sjt_call38); }
    if (sjt_call39._refCount == 1) { sjf_texture_destroy(&sjt_call39); }
    if (sjt_call40._refCount == 1) { sjf_string_destroy(&sjt_call40); }
    if (sjt_call41._refCount == 1) { sjf_texture_destroy(&sjt_call41); }
    if (sjt_call42._refCount == 1) { sjf_string_destroy(&sjt_call42); }
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
    if (sjt_call75._refCount == 1) { sjf_string_destroy(&sjt_call75); }
    if (sjt_call76._refCount == 1) { sjf_string_destroy(&sjt_call76); }
    if (sjt_call77._refCount == 1) { sjf_string_destroy(&sjt_call77); }
    if (sjt_call78._refCount == 1) { sjf_mat4_destroy(&sjt_call78); }
    if (sjt_call79._refCount == 1) { sjf_mat4_destroy(&sjt_call79); }
    if (sjt_call80._refCount == 1) { sjf_string_destroy(&sjt_call80); }
    if (sjt_call81._refCount == 1) { sjf_mat4_destroy(&sjt_call81); }
    if (sjt_call82._refCount == 1) { sjf_mat4_destroy(&sjt_call82); }
    if (sjt_call83._refCount == 1) { sjf_string_destroy(&sjt_call83); }
    if (sjt_call84._refCount == 1) { sjf_mat4_destroy(&sjt_call84); }
    if (sjt_call85._refCount == 1) { sjf_mat4_destroy(&sjt_call85); }
    if (sjt_call86._refCount == 1) { sjf_string_destroy(&sjt_call86); }
    if (sjt_call87._refCount == 1) { sjf_mat4_destroy(&sjt_call87); }
    if (sjt_call88._refCount == 1) { sjf_mat4_destroy(&sjt_call88); }
    if (sjt_call89._refCount == 1) { sjf_string_destroy(&sjt_call89); }
    if (sjt_call90._refCount == 1) { sjf_mat4_destroy(&sjt_call90); }
    if (sjt_call91._refCount == 1) { sjf_mat4_destroy(&sjt_call91); }
    if (sjt_call92._refCount == 1) { sjf_string_destroy(&sjt_call92); }
    if (sjt_call93._refCount == 1) { sjf_mat4_destroy(&sjt_call93); }
    if (sjt_call94._refCount == 1) { sjf_mat4_destroy(&sjt_call94); }
    if (sjt_call95._refCount == 1) { sjf_string_destroy(&sjt_call95); }
    if (sjt_call96._refCount == 1) { sjf_mat4_destroy(&sjt_call96); }
    if (sjt_call97._refCount == 1) { sjf_mat4_destroy(&sjt_call97); }
    if (sjt_call98._refCount == 1) { sjf_string_destroy(&sjt_call98); }
    if (sjt_call99._refCount == 1) { sjf_mat4_destroy(&sjt_call99); }
    if (sjv_animator._refCount == 1) { sjf_anon1_destroy(&sjv_animator); }
    if (sjv_blurhorizontalshader._refCount == 1) { sjf_shader_destroy(&sjv_blurhorizontalshader); }
    if (sjv_blurverticalshader._refCount == 1) { sjf_shader_destroy(&sjv_blurverticalshader); }
    if (sjv_borderposition._refCount == 1) { sjf_anon2_destroy(&sjv_borderposition); }
    if (sjv_boxshader._refCount == 1) { sjf_shader_destroy(&sjv_boxshader); }
    if (sjv_buttonstate._refCount == 1) { sjf_anon3_destroy(&sjv_buttonstate); }
    if (sjv_colors._refCount == 1) { sjf_anon4_destroy(&sjv_colors); }
    if (sjv_imageshader._refCount == 1) { sjf_shader_destroy(&sjv_imageshader); }
    if (sjv_phongcolorshader._refCount == 1) { sjf_shader_destroy(&sjv_phongcolorshader); }
    if (sjv_phongtextureshader._refCount == 1) { sjf_shader_destroy(&sjv_phongtextureshader); }
    if (sjv_rootscene._refCount == 1) { sjf_scene2d_destroy(&sjv_rootscene); }
    if (sjv_rootwindowrenderer._refCount == 1) { sjf_windowrenderer_destroy(&sjv_rootwindowrenderer); }
    if (sjv_style._refCount == 1) { sjf_anon5_destroy(&sjv_style); }
    if (sjv_textshader._refCount == 1) { sjf_shader_destroy(&sjv_textshader); }
    if (sjv_vertex_location_texture_normal_format._refCount == 1) { sjf_string_destroy(&sjv_vertex_location_texture_normal_format); }
}
