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

const char* sjg_string1 = "shaders/v3f-t2f.vert";
const char* sjg_string10 = "shaders/v3f-t2f.frag";
const char* sjg_string11 = "shaders/v3f-n3f-phong.vert";
const char* sjg_string12 = "shaders/v3f-n3f-phong.frag";
const char* sjg_string13 = "shaders/v3f-t2f-n3f-phong.vert";
const char* sjg_string14 = "shaders/v3f-t2f-n3f-phong.frag";
const char* sjg_string15 = "shaders/v3f-t2f-c4f.vert";
const char* sjg_string16 = "shaders/v3f-t2f-c4f.frag";
const char* sjg_string17 = "vertex:3f,tex_coord:2f,normal:3f";
const char* sjg_string19 = "framebuffer being pop'ed is wrong";
const char* sjg_string2 = "shaders/blur-horizontal.frag";
const char* sjg_string21 = "Framebuffer failed";
const char* sjg_string22 = "assets/test.png";
const char* sjg_string23 = "viewport being pop'ed is wrong";
const char* sjg_string3 = "shaders/v3f-t2f.vert";
const char* sjg_string4 = "shaders/blur-vertical.frag";
const char* sjg_string43 = "x: ";
const char* sjg_string44 = " y: ";
const char* sjg_string45 = " w: ";
const char* sjg_string46 = " h: ";
const char* sjg_string47 = "x: ";
const char* sjg_string48 = " y: ";
const char* sjg_string49 = " w: ";
const char* sjg_string5 = "shaders/v3f-t2f.vert";
const char* sjg_string50 = " h: ";
const char* sjg_string51 = "viewModel";
const char* sjg_string52 = "normalMat";
const char* sjg_string53 = "projection";
const char* sjg_string54 = "lightPos";
const char* sjg_string55 = "diffuseColor";
const char* sjg_string56 = "specColor";
const char* sjg_string6 = "shaders/fade.frag";
const char* sjg_string7 = "shaders/v3f-c4f.vert";
const char* sjg_string8 = "shaders/v3f-c4f.frag";
const char* sjg_string9 = "shaders/v3f-t2f.vert";

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
#define sjs_rect_typeId 6
#define sjs_scene2d_typeId 7
#define sjs_array_char_typeId 8
#define sjs_string_typeId 9
#define sjs_vec3_typeId 10
#define sjs_color_typeId 11
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
#define sji_effect_vtbl_typeId 39
#define sji_effect_typeId 40
#define sjs_filllayout_typeId 41
#define cb_rect_void_typeId 42
#define cb_rect_void_heap_typeId 43
#define cb_scene2d_void_typeId 44
#define cb_scene2d_void_heap_typeId 45
#define sjs_scene3delement_typeId 46
#define cb_heap_iface_model_heap_iface_model_i32_typeId 47
#define cb_heap_iface_model_heap_iface_model_i32_heap_typeId 48
#define cb_local_iface_model_local_iface_model_i32_typeId 49
#define cb_local_iface_model_local_iface_model_i32_heap_typeId 50
#define sjs_array_i32_typeId 51
#define sjs_array_vertex_location_texture_normal_typeId 52
#define sjs_vertexbuffer_vertex_location_texture_normal_typeId 53
#define sjs_vec4_typeId 54
#define sjs_framebuffer_typeId 55
#define sjs_texture_typeId 56
#define sjs_renderbuffer_typeId 57
#define sjs_scene2dmodel_typeId 58
#define sjs_vec2_typeId 59
#define sjs_vertex_location_texture_normal_typeId 60
#define sjs_array_local_iface_model_typeId 61
#define sjs_list_local_iface_model_typeId 62
#define sjs_image_typeId 63
#define sjs_imagerenderer_typeId 64
#define sjs_imageelement_typeId 65
#define sjs_boxrenderer_typeId 66
#define sjs_crosshairselement_typeId 67

typedef struct td_sjs_object sjs_object;
typedef struct td_sjs_interface sjs_interface;
typedef struct td_sjs_windowrenderer sjs_windowrenderer;
typedef struct td_sjs_size sjs_size;
typedef struct td_sjs_mat4 sjs_mat4;
typedef struct td_sjs_rect sjs_rect;
typedef struct td_sjs_scene2d sjs_scene2d;
typedef struct td_sjs_array_char sjs_array_char;
typedef struct td_sjs_string sjs_string;
typedef struct td_sjs_vec3 sjs_vec3;
typedef struct td_sjs_color sjs_color;
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
typedef struct td_sjs_array_local_iface_model sjs_array_local_iface_model;
typedef struct td_sjs_list_local_iface_model sjs_list_local_iface_model;
typedef struct td_sjs_image sjs_image;
typedef struct td_sjs_imagerenderer sjs_imagerenderer;
typedef struct td_sjs_imageelement sjs_imageelement;
typedef struct td_sjs_boxrenderer sjs_boxrenderer;
typedef struct td_sjs_crosshairselement sjs_crosshairselement;

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
int32_t result1;
float result12;
sjs_filllayout* sjt_call1 = 0;
sjs_scene2dmodel* sjt_call38 = 0;
sjs_scene3delement* sjt_call4 = 0;
sjs_vec3 sjt_call57 = { -1 };
sjs_vec3 sjt_call58 = { -1 };
sjs_imageelement* sjt_call59 = 0;
sjs_string sjt_call65 = { -1 };
sjs_crosshairselement* sjt_call66 = 0;
sjs_crosshairselement* sjt_call67 = 0;
sjs_filllayout* sjt_cast1 = 0;
sjs_scene3delement* sjt_cast2 = 0;
sjs_imageelement* sjt_cast36 = 0;
sjs_crosshairselement* sjt_cast45 = 0;
sjs_crosshairselement* sjt_cast46 = 0;
sjs_scene2dmodel* sjt_cast7 = 0;
sjs_shader* sjt_copy35 = 0;
sjs_color* sjt_copy49 = 0;
sjs_color* sjt_copy50 = 0;
int32_t sjt_functionParam142;
sji_model sjt_functionParam143 = { 0 };
int32_t sjt_functionParam19;
sji_element sjt_functionParam20 = { 0 };
int32_t sjt_functionParam343;
int32_t sjt_functionParam344;
sjs_vec3* sjt_functionParam345 = 0;
sjs_vec3* sjt_functionParam346 = 0;
int32_t sjt_functionParam347;
sji_element sjt_functionParam348 = { 0 };
sjs_string* sjt_functionParam353 = 0;
int32_t sjt_functionParam354;
sji_element sjt_functionParam355 = { 0 };
int32_t sjt_functionParam360;
sji_element sjt_functionParam361 = { 0 };
int32_t sjt_math1;
int32_t sjt_math2;
int32_t sjt_negate1;
float sjt_negate7;
sjs_array_heap_iface_element* sjt_parent190 = 0;
sjs_array_heap_iface_element* sjt_parent200 = 0;
sjs_array_heap_iface_element* sjt_parent205 = 0;
sjs_array_heap_iface_element* sjt_parent24 = 0;
sjs_array_heap_iface_model* sjt_parent96 = 0;
sjs_anon1 sjv_animator = { -1 };
sjs_shader sjv_blurhorizontalshader = { -1 };
sjs_shader sjv_blurverticalshader = { -1 };
int32_t sjv_borderposition_bottom;
int32_t sjv_borderposition_fill;
int32_t sjv_borderposition_left;
int32_t sjv_borderposition_right;
int32_t sjv_borderposition_top;
sjs_shader sjv_boxshader = { -1 };
int32_t sjv_buttonstate_hot;
int32_t sjv_buttonstate_normal;
int32_t sjv_buttonstate_pressed;
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
int32_t sjv_flowlayoutorientation_bottomtop;
int32_t sjv_flowlayoutorientation_leftright;
int32_t sjv_flowlayoutorientation_rightleft;
int32_t sjv_flowlayoutorientation_topbottom;
sjs_hash_fontkey_weak_font sjv_fonthash = { -1 };
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
sjs_list_u32 sjv_glframebuffers = { -1 };
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
sjs_list_rect sjv_glviewports = { -1 };
int32_t sjv_gridunittype_fixed;
int32_t sjv_gridunittype_star;
int32_t sjv_i32_maxvalue;
int32_t sjv_i32_minvalue;
sjs_shader sjv_imageshader = { -1 };
int32_t sjv_imagestretch_aspectratio;
int32_t sjv_imagestretch_center;
int32_t sjv_imagestretch_fill;
int32_t sjv_listlayoutorientation_bottomtop;
int32_t sjv_listlayoutorientation_leftright;
int32_t sjv_listlayoutorientation_rightleft;
int32_t sjv_listlayoutorientation_topbottom;
sjs_rect sjv_looplastrect = { -1 };
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
sjs_anon2 sjv_style = { -1 };
int32_t sjv_texthorizontal_center;
int32_t sjv_texthorizontal_left;
int32_t sjv_texthorizontal_right;
sjs_shader sjv_textshader = { -1 };
int32_t sjv_textvertical_bottom;
int32_t sjv_textvertical_center;
int32_t sjv_textvertical_top;
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
void sjf_array_local_iface_model(sjs_array_local_iface_model* _this);
void sjf_array_local_iface_model_copy(sjs_array_local_iface_model* _this, sjs_array_local_iface_model* _from);
void sjf_array_local_iface_model_destroy(sjs_array_local_iface_model* _this);
void sjf_array_local_iface_model_grow(sjs_array_local_iface_model* _parent, int32_t newsize, sjs_array_local_iface_model* _return);
void sjf_array_local_iface_model_grow_heap(sjs_array_local_iface_model* _parent, int32_t newsize, sjs_array_local_iface_model** _return);
void sjf_array_local_iface_model_heap(sjs_array_local_iface_model* _this);
void sjf_array_local_iface_model_initat(sjs_array_local_iface_model* _parent, int32_t index, sji_model item);
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
void sjf_array_vertex_location_texture_normal(sjs_array_vertex_location_texture_normal* _this);
void sjf_array_vertex_location_texture_normal_copy(sjs_array_vertex_location_texture_normal* _this, sjs_array_vertex_location_texture_normal* _from);
void sjf_array_vertex_location_texture_normal_destroy(sjs_array_vertex_location_texture_normal* _this);
void sjf_array_vertex_location_texture_normal_getat(sjs_array_vertex_location_texture_normal* _parent, int32_t index, sjs_vertex_location_texture_normal* _return);
void sjf_array_vertex_location_texture_normal_heap(sjs_array_vertex_location_texture_normal* _this);
void sjf_array_vertex_location_texture_normal_initat(sjs_array_vertex_location_texture_normal* _parent, int32_t index, sjs_vertex_location_texture_normal* item);
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
void sjf_crosshairselement(sjs_crosshairselement* _this);
void sjf_crosshairselement_as_sji_element(sjs_crosshairselement* _this, sji_element* _return);
void sjf_crosshairselement_asinterface(sjs_crosshairselement* _this, int typeId, sjs_interface* _return);
void sjf_crosshairselement_copy(sjs_crosshairselement* _this, sjs_crosshairselement* _from);
void sjf_crosshairselement_destroy(sjs_crosshairselement* _this);
void sjf_crosshairselement_firemouseevent(sjs_crosshairselement* _parent, sjs_mouseevent* mouseevent, bool* _return);
void sjf_crosshairselement_getrect(sjs_crosshairselement* _parent, sjs_rect* _return);
void sjf_crosshairselement_getrect_heap(sjs_crosshairselement* _parent, sjs_rect** _return);
void sjf_crosshairselement_getsize(sjs_crosshairselement* _parent, sjs_size* maxsize, sjs_size* _return);
void sjf_crosshairselement_getsize_heap(sjs_crosshairselement* _parent, sjs_size* maxsize, sjs_size** _return);
void sjf_crosshairselement_heap(sjs_crosshairselement* _this);
void sjf_crosshairselement_heap_as_sji_element(sjs_crosshairselement* _this, sji_element* _return);
void sjf_crosshairselement_heap_asinterface(sjs_crosshairselement* _this, int typeId, sjs_interface* _return);
void sjf_crosshairselement_render(sjs_crosshairselement* _parent, sjs_scene2d* scene);
void sjf_crosshairselement_setrect(sjs_crosshairselement* _parent, sjs_rect* rect_);
void sjf_debug_writeline(sjs_string* data);
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
void sjf_filllayout_getrect(sjs_filllayout* _parent, sjs_rect* _return);
void sjf_filllayout_getrect_heap(sjs_filllayout* _parent, sjs_rect** _return);
void sjf_filllayout_getsize(sjs_filllayout* _parent, sjs_size* maxsize, sjs_size* _return);
void sjf_filllayout_getsize_heap(sjs_filllayout* _parent, sjs_size* maxsize, sjs_size** _return);
void sjf_filllayout_heap(sjs_filllayout* _this);
void sjf_filllayout_heap_as_sji_element(sjs_filllayout* _this, sji_element* _return);
void sjf_filllayout_heap_asinterface(sjs_filllayout* _this, int typeId, sjs_interface* _return);
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
void sjf_glbindtexture(int32_t type, sjs_texture* texture);
void sjf_glcheckframebufferstatus(int32_t* _return);
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
void sjf_i32_asstring(int32_t val, sjs_string* _return);
void sjf_i32_asstring_heap(int32_t val, sjs_string** _return);
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
void sjf_list_heap_iface_model_getat_heap(sjs_list_heap_iface_model* _parent, int32_t index, sji_model* _return);
void sjf_list_heap_iface_model_getcount(sjs_list_heap_iface_model* _parent, int32_t* _return);
void sjf_list_heap_iface_model_heap(sjs_list_heap_iface_model* _this);
void sjf_list_heap_iface_model_sortcb(sjs_list_heap_iface_model* _parent, cb_heap_iface_model_heap_iface_model_i32 cb);
void sjf_list_local_iface_model(sjs_list_local_iface_model* _this);
void sjf_list_local_iface_model_add(sjs_list_local_iface_model* _parent, sji_model item);
void sjf_list_local_iface_model_copy(sjs_list_local_iface_model* _this, sjs_list_local_iface_model* _from);
void sjf_list_local_iface_model_destroy(sjs_list_local_iface_model* _this);
void sjf_list_local_iface_model_heap(sjs_list_local_iface_model* _this);
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
void sjf_mouseevent_copy(sjs_mouseevent* _this, sjs_mouseevent* _from);
void sjf_mouseevent_destroy(sjs_mouseevent* _this);
void sjf_mouseevent_firechildren(sjs_mouseevent* _parent, sjs_array_heap_iface_element* children, bool* _return);
void sjf_mouseevent_heap(sjs_mouseevent* _this);
void sjf_point(sjs_point* _this);
void sjf_point_copy(sjs_point* _this, sjs_point* _from);
void sjf_point_destroy(sjs_point* _this);
void sjf_point_heap(sjs_point* _this);
void sjf_rect(sjs_rect* _this);
void sjf_rect_asstring(sjs_rect* _parent, sjs_string* _return);
void sjf_rect_asstring_heap(sjs_rect* _parent, sjs_string** _return);
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
void sjf_scene2dmodel_copy(sjs_scene2dmodel* _this, sjs_scene2dmodel* _from);
void sjf_scene2dmodel_destroy(sjs_scene2dmodel* _this);
void sjf_scene2dmodel_firemouseevent(sjs_scene2dmodel* _parent, sjs_mouseevent* mouseevent);
void sjf_scene2dmodel_getcenter(sjs_scene2dmodel* _parent, sjs_vec3* _return);
void sjf_scene2dmodel_getcenter_heap(sjs_scene2dmodel* _parent, sjs_vec3** _return);
void sjf_scene2dmodel_getworld(sjs_scene2dmodel* _parent, sjs_mat4* _return);
void sjf_scene2dmodel_getworld_heap(sjs_scene2dmodel* _parent, sjs_mat4** _return);
void sjf_scene2dmodel_getz(sjs_scene2dmodel* _parent, float* _return);
void sjf_scene2dmodel_heap(sjs_scene2dmodel* _this);
void sjf_scene2dmodel_heap_as_sji_model(sjs_scene2dmodel* _this, sji_model* _return);
void sjf_scene2dmodel_heap_asinterface(sjs_scene2dmodel* _this, int typeId, sjs_interface* _return);
void sjf_scene2dmodel_render(sjs_scene2dmodel* _parent);
void sjf_scene2dmodel_renderorqueue(sjs_scene2dmodel* _parent, sjs_list_local_iface_model* alphamodels);
void sjf_scene2dmodel_update(sjs_scene2dmodel* _parent, sjs_rect* scenerect, sjs_mat4* projection, sjs_mat4* view, sjs_mat4* world, sjs_light* light);
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
void sjf_scene3delement_heap_as_sji_element(sjs_scene3delement* _this, sji_element* _return);
void sjf_scene3delement_heap_asinterface(sjs_scene3delement* _this, int typeId, sjs_interface* _return);
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
    int32_t sjt_compare135;
    int32_t sjt_compare136;
    sjs_anon1* sjt_dot1684 = 0;
    sjs_anon1* sjt_dot1687 = 0;
    bool sjt_ifElse60;
    sjs_list_heap_iface_animation* sjt_parent206 = 0;

    sjt_dot1684 = _parent;
    sjt_dot1684->current = time;
    sjt_dot1687 = _parent;
    sjt_parent206 = &(sjt_dot1687)->animations;
    sjf_list_heap_iface_animation_getcount(sjt_parent206, &sjt_compare135);
    sjt_compare136 = 0;
    sjt_ifElse60 = sjt_compare135 > sjt_compare136;
    if (sjt_ifElse60) {
        int32_t i;
        sjs_anon1* sjt_dot1688 = 0;
        int32_t sjt_forEnd23;
        int32_t sjt_forStart23;
        sjs_list_heap_iface_animation* sjt_parent207 = 0;

        sjt_forStart23 = 0;
        sjt_dot1688 = _parent;
        sjt_parent207 = &(sjt_dot1688)->animations;
        sjf_list_heap_iface_animation_getcount(sjt_parent207, &sjt_forEnd23);
        i = sjt_forEnd23 - 1;
        while (i >= sjt_forStart23) {
            sjs_anon1* sjt_dot1690 = 0;
            int32_t sjt_functionParam363;
            bool sjt_ifElse61;
            int32_t sjt_interfaceParam19;
            sjs_list_heap_iface_animation* sjt_parent209 = 0;
            sji_animation sjt_parent210 = { 0 };
            sji_animation sjv_a = { 0 };

            sjt_dot1690 = _parent;
            sjt_parent209 = &(sjt_dot1690)->animations;
            sjt_functionParam363 = i;
            sjf_list_heap_iface_animation_getat_heap(sjt_parent209, sjt_functionParam363, &sjv_a);
            sjt_parent210 = sjv_a;
            sjt_interfaceParam19 = time;
            sjt_parent210._vtbl->nextframe(sjt_parent210._parent, sjt_interfaceParam19, &sjt_ifElse61);
            if (sjt_ifElse61) {
                sjs_anon1* sjt_dot1691 = 0;
                int32_t sjt_functionParam364;
                sjs_list_heap_iface_animation* sjt_parent211 = 0;

                sjt_dot1691 = _parent;
                sjt_parent211 = &(sjt_dot1691)->animations;
                sjt_functionParam364 = i;
                sjf_list_heap_iface_animation_removeat(sjt_parent211, sjt_functionParam364);
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

void sjf_array_char_getat(sjs_array_char* _parent, int32_t index, char* _return) {
    if (index >= _parent->count || index < 0) {
        halt("getAt: out of bounds\n");
    }
    char* p = (char*)_parent->data;
    (*_return) = p[index];
return;;		
}

void sjf_array_char_grow(sjs_array_char* _parent, int32_t newsize, sjs_array_char* _return) {
    sjs_array_char* sjt_dot234 = 0;
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
    sjt_dot234 = _parent;
    _return->count = (sjt_dot234)->count;
    sjf_array_char(_return);
}

void sjf_array_char_grow_heap(sjs_array_char* _parent, int32_t newsize, sjs_array_char** _return) {
    sjs_array_char* sjt_dot235 = 0;
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
    sjt_dot235 = _parent;
    (*_return)->count = (sjt_dot235)->count;
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
    int32_t sjt_compare29;
    int32_t sjt_compare30;
    int32_t sjt_compare43;
    int32_t sjt_compare44;
    int32_t sjt_compare45;
    int32_t sjt_compare46;
    int32_t sjt_functionParam98;
    bool sjt_ifElse13;
    bool sjt_ifElse14;
    int32_t sjt_math235;
    int32_t sjt_math236;
    int32_t sjt_math237;
    int32_t sjt_math238;
    bool sjt_while1;
    int32_t sjv_i;
    int32_t sjv_j;
    sji_model sjv_pivot = { 0 };

    sjv_i = left;
    sjv_j = right;
    sjt_math237 = left;
    sjt_math238 = right;
    sjt_math235 = sjt_math237 + sjt_math238;
    sjt_math236 = 2;
    sjt_functionParam98 = sjt_math235 / sjt_math236;
    sjf_array_heap_iface_model_getat_heap(_parent, sjt_functionParam98, &sjv_pivot);
    sjt_compare29 = sjv_i;
    sjt_compare30 = sjv_j;
    sjt_while1 = sjt_compare29 <= sjt_compare30;
    while (sjt_while1) {
        cb_heap_iface_model_heap_iface_model_i32 sjt_callback1;
        cb_heap_iface_model_heap_iface_model_i32 sjt_callback3;
        int32_t sjt_compare31;
        int32_t sjt_compare32;
        int32_t sjt_compare35;
        int32_t sjt_compare36;
        int32_t sjt_compare39;
        int32_t sjt_compare40;
        int32_t sjt_compare41;
        int32_t sjt_compare42;
        int32_t sjt_functionParam100;
        sji_model sjt_functionParam101 = { 0 };
        sji_model sjt_functionParam105 = { 0 };
        int32_t sjt_functionParam106;
        sji_model sjt_functionParam107 = { 0 };
        sji_model sjt_functionParam99 = { 0 };
        bool sjt_ifElse12;
        bool sjt_while2;
        bool sjt_while3;

        sjt_callback1 = cb;
        sjt_functionParam100 = sjv_i;
        sjf_array_heap_iface_model_getat_heap(_parent, sjt_functionParam100, &sjt_functionParam99);
        sjt_functionParam101 = sjv_pivot;
        if (sjt_functionParam101._parent != 0) {
            sjt_functionParam101._parent->_refCount++;
        }

        sjt_callback1._cb(sjt_callback1._parent, sjt_functionParam99, sjt_functionParam101, &sjt_compare31);
        sjt_compare32 = 0;
        sjt_while2 = sjt_compare31 < sjt_compare32;
        while (sjt_while2) {
            cb_heap_iface_model_heap_iface_model_i32 sjt_callback2;
            int32_t sjt_compare33;
            int32_t sjt_compare34;
            sji_model sjt_functionParam102 = { 0 };
            int32_t sjt_functionParam103;
            sji_model sjt_functionParam104 = { 0 };
            int32_t sjt_math239;
            int32_t sjt_math240;

            sjt_math239 = sjv_i;
            sjt_math240 = 1;
            sjv_i = sjt_math239 + sjt_math240;
            sjt_callback2 = cb;
            sjt_functionParam103 = sjv_i;
            sjf_array_heap_iface_model_getat_heap(_parent, sjt_functionParam103, &sjt_functionParam102);
            sjt_functionParam104 = sjv_pivot;
            if (sjt_functionParam104._parent != 0) {
                sjt_functionParam104._parent->_refCount++;
            }

            sjt_callback2._cb(sjt_callback2._parent, sjt_functionParam102, sjt_functionParam104, &sjt_compare33);
            sjt_compare34 = 0;
            sjt_while2 = sjt_compare33 < sjt_compare34;

            if (sjt_functionParam102._parent != 0) {
                sjt_functionParam102._parent->_refCount--;
                if (sjt_functionParam102._parent->_refCount <= 0) {
                    sjt_functionParam102._vtbl->destroy(sjt_functionParam102._parent);
                    free(sjt_functionParam102._parent);
                }
            }
            if (sjt_functionParam104._parent != 0) {
                sjt_functionParam104._parent->_refCount--;
                if (sjt_functionParam104._parent->_refCount <= 0) {
                    sjt_functionParam104._vtbl->destroy(sjt_functionParam104._parent);
                    free(sjt_functionParam104._parent);
                }
            }
        }

        sjt_callback3 = cb;
        sjt_functionParam106 = sjv_j;
        sjf_array_heap_iface_model_getat_heap(_parent, sjt_functionParam106, &sjt_functionParam105);
        sjt_functionParam107 = sjv_pivot;
        if (sjt_functionParam107._parent != 0) {
            sjt_functionParam107._parent->_refCount++;
        }

        sjt_callback3._cb(sjt_callback3._parent, sjt_functionParam105, sjt_functionParam107, &sjt_compare35);
        sjt_compare36 = 0;
        sjt_while3 = sjt_compare35 > sjt_compare36;
        while (sjt_while3) {
            cb_heap_iface_model_heap_iface_model_i32 sjt_callback4;
            int32_t sjt_compare37;
            int32_t sjt_compare38;
            sji_model sjt_functionParam108 = { 0 };
            int32_t sjt_functionParam109;
            sji_model sjt_functionParam110 = { 0 };
            int32_t sjt_math241;
            int32_t sjt_math242;

            sjt_math241 = sjv_j;
            sjt_math242 = 1;
            sjv_j = sjt_math241 - sjt_math242;
            sjt_callback4 = cb;
            sjt_functionParam109 = sjv_j;
            sjf_array_heap_iface_model_getat_heap(_parent, sjt_functionParam109, &sjt_functionParam108);
            sjt_functionParam110 = sjv_pivot;
            if (sjt_functionParam110._parent != 0) {
                sjt_functionParam110._parent->_refCount++;
            }

            sjt_callback4._cb(sjt_callback4._parent, sjt_functionParam108, sjt_functionParam110, &sjt_compare37);
            sjt_compare38 = 0;
            sjt_while3 = sjt_compare37 > sjt_compare38;

            if (sjt_functionParam108._parent != 0) {
                sjt_functionParam108._parent->_refCount--;
                if (sjt_functionParam108._parent->_refCount <= 0) {
                    sjt_functionParam108._vtbl->destroy(sjt_functionParam108._parent);
                    free(sjt_functionParam108._parent);
                }
            }
            if (sjt_functionParam110._parent != 0) {
                sjt_functionParam110._parent->_refCount--;
                if (sjt_functionParam110._parent->_refCount <= 0) {
                    sjt_functionParam110._vtbl->destroy(sjt_functionParam110._parent);
                    free(sjt_functionParam110._parent);
                }
            }
        }

        sjt_compare39 = sjv_i;
        sjt_compare40 = sjv_j;
        sjt_ifElse12 = sjt_compare39 <= sjt_compare40;
        if (sjt_ifElse12) {
            int32_t sjt_functionParam111;
            int32_t sjt_functionParam112;
            sji_model sjt_functionParam113 = { 0 };
            int32_t sjt_functionParam114;
            int32_t sjt_functionParam115;
            sji_model sjt_functionParam116 = { 0 };
            int32_t sjt_math243;
            int32_t sjt_math244;
            int32_t sjt_math245;
            int32_t sjt_math246;
            sji_model sjv_tmp = { 0 };

            sjt_functionParam111 = sjv_i;
            sjf_array_heap_iface_model_getat_heap(_parent, sjt_functionParam111, &sjv_tmp);
            sjt_functionParam112 = sjv_i;
            sjt_functionParam114 = sjv_j;
            sjf_array_heap_iface_model_getat_heap(_parent, sjt_functionParam114, &sjt_functionParam113);
            sjf_array_heap_iface_model_setat(_parent, sjt_functionParam112, sjt_functionParam113);
            sjt_functionParam115 = sjv_j;
            sjt_functionParam116 = sjv_tmp;
            if (sjt_functionParam116._parent != 0) {
                sjt_functionParam116._parent->_refCount++;
            }

            sjf_array_heap_iface_model_setat(_parent, sjt_functionParam115, sjt_functionParam116);
            sjt_math243 = sjv_i;
            sjt_math244 = 1;
            sjv_i = sjt_math243 + sjt_math244;
            sjt_math245 = sjv_j;
            sjt_math246 = 1;
            sjv_j = sjt_math245 - sjt_math246;

            if (sjt_functionParam113._parent != 0) {
                sjt_functionParam113._parent->_refCount--;
                if (sjt_functionParam113._parent->_refCount <= 0) {
                    sjt_functionParam113._vtbl->destroy(sjt_functionParam113._parent);
                    free(sjt_functionParam113._parent);
                }
            }
            if (sjt_functionParam116._parent != 0) {
                sjt_functionParam116._parent->_refCount--;
                if (sjt_functionParam116._parent->_refCount <= 0) {
                    sjt_functionParam116._vtbl->destroy(sjt_functionParam116._parent);
                    free(sjt_functionParam116._parent);
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

        sjt_compare41 = sjv_i;
        sjt_compare42 = sjv_j;
        sjt_while1 = sjt_compare41 <= sjt_compare42;

        if (sjt_functionParam101._parent != 0) {
            sjt_functionParam101._parent->_refCount--;
            if (sjt_functionParam101._parent->_refCount <= 0) {
                sjt_functionParam101._vtbl->destroy(sjt_functionParam101._parent);
                free(sjt_functionParam101._parent);
            }
        }
        if (sjt_functionParam105._parent != 0) {
            sjt_functionParam105._parent->_refCount--;
            if (sjt_functionParam105._parent->_refCount <= 0) {
                sjt_functionParam105._vtbl->destroy(sjt_functionParam105._parent);
                free(sjt_functionParam105._parent);
            }
        }
        if (sjt_functionParam107._parent != 0) {
            sjt_functionParam107._parent->_refCount--;
            if (sjt_functionParam107._parent->_refCount <= 0) {
                sjt_functionParam107._vtbl->destroy(sjt_functionParam107._parent);
                free(sjt_functionParam107._parent);
            }
        }
        if (sjt_functionParam99._parent != 0) {
            sjt_functionParam99._parent->_refCount--;
            if (sjt_functionParam99._parent->_refCount <= 0) {
                sjt_functionParam99._vtbl->destroy(sjt_functionParam99._parent);
                free(sjt_functionParam99._parent);
            }
        }
    }

    sjt_compare43 = left;
    sjt_compare44 = sjv_j;
    sjt_ifElse13 = sjt_compare43 < sjt_compare44;
    if (sjt_ifElse13) {
        int32_t sjt_functionParam117;
        int32_t sjt_functionParam118;
        cb_heap_iface_model_heap_iface_model_i32 sjt_functionParam119;

        sjt_functionParam117 = left;
        sjt_functionParam118 = sjv_j;
        sjt_functionParam119 = cb;
        sjf_array_heap_iface_model__quicksortcallback(_parent, sjt_functionParam117, sjt_functionParam118, sjt_functionParam119);
    }

    sjt_compare45 = sjv_i;
    sjt_compare46 = right;
    sjt_ifElse14 = sjt_compare45 < sjt_compare46;
    if (sjt_ifElse14) {
        int32_t sjt_functionParam120;
        int32_t sjt_functionParam121;
        cb_heap_iface_model_heap_iface_model_i32 sjt_functionParam122;

        sjt_functionParam120 = sjv_i;
        sjt_functionParam121 = right;
        sjt_functionParam122 = cb;
        sjf_array_heap_iface_model__quicksortcallback(_parent, sjt_functionParam120, sjt_functionParam121, sjt_functionParam122);
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
    int32_t sjt_compare27;
    int32_t sjt_compare28;
    sjs_array_heap_iface_model* sjt_dot262 = 0;
    bool sjt_ifElse11;

    sjt_dot262 = _parent;
    sjt_compare27 = (sjt_dot262)->count;
    sjt_compare28 = 1;
    sjt_ifElse11 = sjt_compare27 > sjt_compare28;
    if (sjt_ifElse11) {
        sjs_array_heap_iface_model* sjt_dot263 = 0;
        int32_t sjt_functionParam123;
        int32_t sjt_functionParam124;
        cb_heap_iface_model_heap_iface_model_i32 sjt_functionParam125;
        int32_t sjt_math247;
        int32_t sjt_math248;

        sjt_functionParam123 = 0;
        sjt_dot263 = _parent;
        sjt_math247 = (sjt_dot263)->count;
        sjt_math248 = 1;
        sjt_functionParam124 = sjt_math247 - sjt_math248;
        sjt_functionParam125 = cb;
        sjf_array_heap_iface_model__quicksortcallback(_parent, sjt_functionParam123, sjt_functionParam124, sjt_functionParam125);
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

void sjf_array_local_iface_model_grow(sjs_array_local_iface_model* _parent, int32_t newsize, sjs_array_local_iface_model* _return) {
    sjs_array_local_iface_model* sjt_dot669 = 0;
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
    sjt_dot669 = _parent;
    _return->count = (sjt_dot669)->count;
    sjf_array_local_iface_model(_return);
}

void sjf_array_local_iface_model_grow_heap(sjs_array_local_iface_model* _parent, int32_t newsize, sjs_array_local_iface_model** _return) {
    sjs_array_local_iface_model* sjt_dot670 = 0;
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
    sjt_dot670 = _parent;
    (*_return)->count = (sjt_dot670)->count;
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
    sjs_array_rect* sjt_dot221 = 0;
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
    sjt_dot221 = _parent;
    _return->count = (sjt_dot221)->count;
    sjf_array_rect(_return);
}

void sjf_array_rect_grow_heap(sjs_array_rect* _parent, int32_t newsize, sjs_array_rect** _return) {
    sjs_array_rect* sjt_dot222 = 0;
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
    sjt_dot222 = _parent;
    (*_return)->count = (sjt_dot222)->count;
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
    sjs_array_u32* sjt_dot287 = 0;
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
    sjt_dot287 = _parent;
    _return->count = (sjt_dot287)->count;
    sjf_array_u32(_return);
}

void sjf_array_u32_grow_heap(sjs_array_u32* _parent, int32_t newsize, sjs_array_u32** _return) {
    sjs_array_u32* sjt_dot288 = 0;
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
    sjt_dot288 = _parent;
    (*_return)->count = (sjt_dot288)->count;
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
    sjs_color* sjt_dot1443 = 0;
    sjs_color* sjt_dot1444 = 0;
    sjs_color* sjt_dot1445 = 0;

    _return->_refCount = 1;
    sjt_dot1443 = _parent;
    _return->x = (sjt_dot1443)->r;
    sjt_dot1444 = _parent;
    _return->y = (sjt_dot1444)->g;
    sjt_dot1445 = _parent;
    _return->z = (sjt_dot1445)->b;
    sjf_vec3(_return);
}

void sjf_color_asvec3_heap(sjs_color* _parent, sjs_vec3** _return) {
    sjs_color* sjt_dot1446 = 0;
    sjs_color* sjt_dot1447 = 0;
    sjs_color* sjt_dot1448 = 0;

    (*_return) = (sjs_vec3*)malloc(sizeof(sjs_vec3));
    (*_return)->_refCount = 1;
    sjt_dot1446 = _parent;
    (*_return)->x = (sjt_dot1446)->r;
    sjt_dot1447 = _parent;
    (*_return)->y = (sjt_dot1447)->g;
    sjt_dot1448 = _parent;
    (*_return)->z = (sjt_dot1448)->b;
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

void sjf_crosshairselement_firemouseevent(sjs_crosshairselement* _parent, sjs_mouseevent* mouseevent, bool* _return) {
    sjs_crosshairselement* sjt_dot1677 = 0;
    sjs_mouseevent* sjt_dot1678 = 0;
    sjs_point* sjt_functionParam359 = 0;
    bool sjt_ifElse58;
    sjs_rect* sjt_parent204 = 0;

    sjt_dot1677 = _parent;
    sjt_parent204 = &(sjt_dot1677)->_rect;
    sjt_dot1678 = mouseevent;
    sjt_functionParam359 = &(sjt_dot1678)->point;
    sjf_rect_containspoint(sjt_parent204, sjt_functionParam359, &sjt_ifElse58);
    if (sjt_ifElse58) {
        int32_t sjt_compare133;
        int32_t sjt_compare134;
        sjs_mouseevent* sjt_dot1679 = 0;
        bool sjt_ifElse59;

        sjt_dot1679 = mouseevent;
        sjt_compare133 = (sjt_dot1679)->type;
        sjt_compare134 = sjv_mouseeventtype_move;
        sjt_ifElse59 = sjt_compare133 == sjt_compare134;
        if (sjt_ifElse59) {
            sjs_point* sjt_copy48 = 0;
            sjs_crosshairselement* sjt_dot1680 = 0;
            sjs_mouseevent* sjt_dot1681 = 0;
            sjs_crosshairselement* sjt_dot1682 = 0;
            sjs_crosshairselement* sjt_dot1683 = 0;

            sjt_dot1680 = _parent;
            sjt_dot1681 = mouseevent;
            sjt_copy48 = &(sjt_dot1681)->point;
            sjt_dot1680->_point._refCount = 1;
            sjf_point_copy(&sjt_dot1680->_point, sjt_copy48);
            sjt_dot1682 = _parent;
            sjt_dot1682->_topdownrenderer._refCount = -1;
            sjt_dot1683 = _parent;
            sjt_dot1683->_leftrightrenderer._refCount = -1;
        }
    }

    (*_return) = true;
}

void sjf_crosshairselement_getrect(sjs_crosshairselement* _parent, sjs_rect* _return) {
    sjs_rect* sjt_copy43 = 0;
    sjs_crosshairselement* sjt_dot1639 = 0;

    sjt_dot1639 = _parent;
    sjt_copy43 = &(sjt_dot1639)->_rect;
    _return->_refCount = 1;
    sjf_rect_copy(_return, sjt_copy43);
}

void sjf_crosshairselement_getrect_heap(sjs_crosshairselement* _parent, sjs_rect** _return) {
    sjs_rect* sjt_copy44 = 0;
    sjs_crosshairselement* sjt_dot1640 = 0;

    sjt_dot1640 = _parent;
    sjt_copy44 = &(sjt_dot1640)->_rect;
    (*_return) = (sjs_rect*)malloc(sizeof(sjs_rect));
    (*_return)->_refCount = 1;
    sjf_rect_copy((*_return), sjt_copy44);
}

void sjf_crosshairselement_getsize(sjs_crosshairselement* _parent, sjs_size* maxsize, sjs_size* _return) {
    sjs_size* sjt_dot1635 = 0;
    sjs_size* sjt_dot1636 = 0;

    _return->_refCount = 1;
    sjt_dot1635 = maxsize;
    _return->w = (sjt_dot1635)->w;
    sjt_dot1636 = maxsize;
    _return->h = (sjt_dot1636)->h;
    sjf_size(_return);
}

void sjf_crosshairselement_getsize_heap(sjs_crosshairselement* _parent, sjs_size* maxsize, sjs_size** _return) {
    sjs_size* sjt_dot1637 = 0;
    sjs_size* sjt_dot1638 = 0;

    (*_return) = (sjs_size*)malloc(sizeof(sjs_size));
    (*_return)->_refCount = 1;
    sjt_dot1637 = maxsize;
    (*_return)->w = (sjt_dot1637)->w;
    sjt_dot1638 = maxsize;
    (*_return)->h = (sjt_dot1638)->h;
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

        default: {
            _return->_parent = 0;
            break;
        }
    }
}

void sjf_crosshairselement_render(sjs_crosshairselement* _parent, sjs_scene2d* scene) {
    sjs_crosshairselement* sjt_dot1645 = 0;
    sjs_crosshairselement* sjt_dot1654 = 0;
    sjs_crosshairselement* sjt_dot1663 = 0;
    sjs_crosshairselement* sjt_dot1665 = 0;
    bool sjt_ifElse54;
    bool sjt_ifElse55;
    bool sjt_ifElse56;
    bool sjt_ifElse57;
    sjs_boxrenderer* sjt_isEmpty18 = 0;
    sjs_boxrenderer* sjt_isEmpty19 = 0;
    sjs_boxrenderer* sjt_isEmpty20 = 0;
    sjs_boxrenderer* sjt_isEmpty21 = 0;

    sjt_dot1645 = _parent;
    sjt_isEmpty18 = ((sjt_dot1645)->_topdownrenderer._refCount != -1 ? &(sjt_dot1645)->_topdownrenderer : 0);
    sjt_ifElse54 = (sjt_isEmpty18 == 0);
    if (sjt_ifElse54) {
        sjs_color* sjt_copy46 = 0;
        sjs_crosshairselement* sjt_dot1646 = 0;
        sjs_point* sjt_dot1647 = 0;
        sjs_crosshairselement* sjt_dot1648 = 0;
        sjs_rect* sjt_dot1649 = 0;
        sjs_crosshairselement* sjt_dot1650 = 0;
        sjs_rect* sjt_dot1651 = 0;
        sjs_crosshairselement* sjt_dot1652 = 0;
        sjs_crosshairselement* sjt_dot1653 = 0;

        sjt_dot1646 = _parent;
        sjt_dot1646->_topdownrenderer._refCount = 1;
        sjt_dot1646->_topdownrenderer.rect._refCount = 1;
        sjt_dot1648 = _parent;
        sjt_dot1647 = &(sjt_dot1648)->_point;
        sjt_dot1646->_topdownrenderer.rect.x = (sjt_dot1647)->x;
        sjt_dot1650 = _parent;
        sjt_dot1649 = &(sjt_dot1650)->_rect;
        sjt_dot1646->_topdownrenderer.rect.y = (sjt_dot1649)->y;
        sjt_dot1646->_topdownrenderer.rect.w = 1;
        sjt_dot1652 = _parent;
        sjt_dot1651 = &(sjt_dot1652)->_rect;
        sjt_dot1646->_topdownrenderer.rect.h = (sjt_dot1651)->h;
        sjf_rect(&sjt_dot1646->_topdownrenderer.rect);
        sjt_dot1653 = _parent;
        sjt_copy46 = &(sjt_dot1653)->color;
        sjt_dot1646->_topdownrenderer.color._refCount = 1;
        sjf_color_copy(&sjt_dot1646->_topdownrenderer.color, sjt_copy46);
        sjf_boxrenderer(&sjt_dot1646->_topdownrenderer);
    }

    sjt_dot1654 = _parent;
    sjt_isEmpty19 = ((sjt_dot1654)->_leftrightrenderer._refCount != -1 ? &(sjt_dot1654)->_leftrightrenderer : 0);
    sjt_ifElse55 = (sjt_isEmpty19 == 0);
    if (sjt_ifElse55) {
        sjs_color* sjt_copy47 = 0;
        sjs_crosshairselement* sjt_dot1655 = 0;
        sjs_rect* sjt_dot1656 = 0;
        sjs_crosshairselement* sjt_dot1657 = 0;
        sjs_point* sjt_dot1658 = 0;
        sjs_crosshairselement* sjt_dot1659 = 0;
        sjs_rect* sjt_dot1660 = 0;
        sjs_crosshairselement* sjt_dot1661 = 0;
        sjs_crosshairselement* sjt_dot1662 = 0;

        sjt_dot1655 = _parent;
        sjt_dot1655->_leftrightrenderer._refCount = 1;
        sjt_dot1655->_leftrightrenderer.rect._refCount = 1;
        sjt_dot1657 = _parent;
        sjt_dot1656 = &(sjt_dot1657)->_rect;
        sjt_dot1655->_leftrightrenderer.rect.x = (sjt_dot1656)->x;
        sjt_dot1659 = _parent;
        sjt_dot1658 = &(sjt_dot1659)->_point;
        sjt_dot1655->_leftrightrenderer.rect.y = (sjt_dot1658)->y;
        sjt_dot1661 = _parent;
        sjt_dot1660 = &(sjt_dot1661)->_rect;
        sjt_dot1655->_leftrightrenderer.rect.w = (sjt_dot1660)->w;
        sjt_dot1655->_leftrightrenderer.rect.h = 1;
        sjf_rect(&sjt_dot1655->_leftrightrenderer.rect);
        sjt_dot1662 = _parent;
        sjt_copy47 = &(sjt_dot1662)->color;
        sjt_dot1655->_leftrightrenderer.color._refCount = 1;
        sjf_color_copy(&sjt_dot1655->_leftrightrenderer.color, sjt_copy47);
        sjf_boxrenderer(&sjt_dot1655->_leftrightrenderer);
    }

    sjt_dot1663 = _parent;
    sjt_isEmpty20 = ((sjt_dot1663)->_topdownrenderer._refCount != -1 ? &(sjt_dot1663)->_topdownrenderer : 0);
    sjt_ifElse56 = (sjt_isEmpty20 != 0);
    if (sjt_ifElse56) {
        sjs_crosshairselement* sjt_dot1664 = 0;
        sjs_scene2d* sjt_functionParam357 = 0;
        sjs_boxrenderer* sjt_parent202 = 0;

        sjt_dot1664 = _parent;
        sjt_parent202 = ((sjt_dot1664)->_topdownrenderer._refCount != -1 ? &(sjt_dot1664)->_topdownrenderer : 0);
        sjt_functionParam357 = scene;
        sjf_boxrenderer_render(sjt_parent202, sjt_functionParam357);
    }

    sjt_dot1665 = _parent;
    sjt_isEmpty21 = ((sjt_dot1665)->_leftrightrenderer._refCount != -1 ? &(sjt_dot1665)->_leftrightrenderer : 0);
    sjt_ifElse57 = (sjt_isEmpty21 != 0);
    if (sjt_ifElse57) {
        sjs_crosshairselement* sjt_dot1666 = 0;
        sjs_scene2d* sjt_functionParam358 = 0;
        sjs_boxrenderer* sjt_parent203 = 0;

        sjt_dot1666 = _parent;
        sjt_parent203 = ((sjt_dot1666)->_leftrightrenderer._refCount != -1 ? &(sjt_dot1666)->_leftrightrenderer : 0);
        sjt_functionParam358 = scene;
        sjf_boxrenderer_render(sjt_parent203, sjt_functionParam358);
    }
}

void sjf_crosshairselement_setrect(sjs_crosshairselement* _parent, sjs_rect* rect_) {
    bool result11;
    sjs_crosshairselement* sjt_dot1641 = 0;
    sjs_rect* sjt_functionParam356 = 0;
    bool sjt_ifElse53;
    bool sjt_not5;
    sjs_rect* sjt_parent201 = 0;

    sjt_dot1641 = _parent;
    sjt_parent201 = &(sjt_dot1641)->_rect;
    sjt_functionParam356 = rect_;
    sjf_rect_isequal(sjt_parent201, sjt_functionParam356, &sjt_not5);
    result11 = !sjt_not5;
    sjt_ifElse53 = result11;
    if (sjt_ifElse53) {
        sjs_rect* sjt_copy45 = 0;
        sjs_crosshairselement* sjt_dot1642 = 0;
        sjs_crosshairselement* sjt_dot1643 = 0;
        sjs_crosshairselement* sjt_dot1644 = 0;

        sjt_dot1642 = _parent;
        sjt_copy45 = rect_;
        sjt_dot1642->_rect._refCount = 1;
        sjf_rect_copy(&sjt_dot1642->_rect, sjt_copy45);
        sjt_dot1643 = _parent;
        sjt_dot1643->_topdownrenderer._refCount = -1;
        sjt_dot1644 = _parent;
        sjt_dot1644->_leftrightrenderer._refCount = -1;
    }
}

void sjf_debug_writeline(sjs_string* data) {
    printf("%s\n", (char*)data->data.data);
}

void sjf_f32_compare(float l, float r, int32_t* _return) {
    float sjt_compare47;
    float sjt_compare48;
    bool sjt_ifElse15;

    sjt_compare47 = l;
    sjt_compare48 = r;
    sjt_ifElse15 = sjt_compare47 == sjt_compare48;
    if (sjt_ifElse15) {
        (*_return) = 0;
    } else {
        float sjt_compare49;
        float sjt_compare50;
        bool sjt_ifElse16;

        sjt_compare49 = l;
        sjt_compare50 = r;
        sjt_ifElse16 = sjt_compare49 < sjt_compare50;
        if (sjt_ifElse16) {
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

void sjf_f32_hash(float val, uint32_t* _return) {
    uint32_t sjv_result;

    sjv_result = (uint32_t)0u;
    int32_t* p = (int32_t*)&val;
    sjv_result = *p;
    (*_return) = sjv_result;
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
    sjs_filllayout* sjt_dot95 = 0;
    sjs_array_heap_iface_element* sjt_functionParam18 = 0;
    sjs_mouseevent* sjt_parent23 = 0;

    sjt_parent23 = mouseevent;
    sjt_dot95 = _parent;
    sjt_functionParam18 = &(sjt_dot95)->children;
    sjf_mouseevent_firechildren(sjt_parent23, sjt_functionParam18, _return);
}

void sjf_filllayout_getrect(sjs_filllayout* _parent, sjs_rect* _return) {
    sjs_rect* sjt_copy1 = 0;
    sjs_filllayout* sjt_dot59 = 0;

    sjt_dot59 = _parent;
    sjt_copy1 = &(sjt_dot59)->_rect;
    _return->_refCount = 1;
    sjf_rect_copy(_return, sjt_copy1);
}

void sjf_filllayout_getrect_heap(sjs_filllayout* _parent, sjs_rect** _return) {
    sjs_rect* sjt_copy2 = 0;
    sjs_filllayout* sjt_dot60 = 0;

    sjt_dot60 = _parent;
    sjt_copy2 = &(sjt_dot60)->_rect;
    (*_return) = (sjs_rect*)malloc(sizeof(sjs_rect));
    (*_return)->_refCount = 1;
    sjf_rect_copy((*_return), sjt_copy2);
}

void sjf_filllayout_getsize(sjs_filllayout* _parent, sjs_size* maxsize, sjs_size* _return) {
    int32_t i;
    sjs_filllayout* sjt_dot21 = 0;
    sjs_array_heap_iface_element* sjt_dot22 = 0;
    sjs_filllayout* sjt_dot23 = 0;
    sjs_filllayout* sjt_dot53 = 0;
    int32_t sjt_forEnd1;
    int32_t sjt_forStart1;
    sjs_margin* sjt_functionParam4 = 0;
    sjs_margin* sjt_functionParam7 = 0;
    sjs_size* sjt_parent4 = 0;
    sjs_size* sjt_parent8 = 0;
    sjs_size sjv_innersize = { -1 };
    sjs_size sjv_size = { -1 };

    sjv_size._refCount = 1;
    sjv_size.w = 0;
    sjv_size.h = 0;
    sjf_size(&sjv_size);
    sjt_parent4 = maxsize;
    sjt_dot21 = _parent;
    sjt_functionParam4 = &(sjt_dot21)->margin;
    sjf_size_subtractmargin(sjt_parent4, sjt_functionParam4, &sjv_innersize);
    sjt_forStart1 = 0;
    sjt_dot23 = _parent;
    sjt_dot22 = &(sjt_dot23)->children;
    sjt_forEnd1 = (sjt_dot22)->count;
    i = sjt_forStart1;
    while (i < sjt_forEnd1) {
        sjs_size sjt_call2 = { -1 };
        sjs_filllayout* sjt_dot24 = 0;
        int32_t sjt_functionParam5;
        sjs_size* sjt_functionParam6 = 0;
        sjs_size* sjt_interfaceParam1 = 0;
        sjs_array_heap_iface_element* sjt_parent5 = 0;
        sjs_size* sjt_parent6 = 0;
        sji_element sjt_parent7 = { 0 };
        sji_element sjv_child = { 0 };

        sjt_dot24 = _parent;
        sjt_parent5 = &(sjt_dot24)->children;
        sjt_functionParam5 = i;
        sjf_array_heap_iface_element_getat_heap(sjt_parent5, sjt_functionParam5, &sjv_child);
        sjt_parent6 = &sjv_size;
        sjt_parent7 = sjv_child;
        sjt_interfaceParam1 = &sjv_innersize;
        sjt_call2._refCount = 1;
        sjt_parent7._vtbl->getsize(sjt_parent7._parent, sjt_interfaceParam1, &sjt_call2);
        sjt_functionParam6 = &sjt_call2;
        sjf_size_max(sjt_parent6, sjt_functionParam6, &sjv_size);
        i++;

        if (sjv_child._parent != 0) {
            sjv_child._parent->_refCount--;
            if (sjv_child._parent->_refCount <= 0) {
                sjv_child._vtbl->destroy(sjv_child._parent);
                free(sjv_child._parent);
            }
        }
        if (sjt_call2._refCount == 1) { sjf_size_destroy(&sjt_call2); }
    }

    sjt_parent8 = &sjv_size;
    sjt_dot53 = _parent;
    sjt_functionParam7 = &(sjt_dot53)->margin;
    sjf_size_addmargin(sjt_parent8, sjt_functionParam7, _return);

    if (sjv_innersize._refCount == 1) { sjf_size_destroy(&sjv_innersize); }
    if (sjv_size._refCount == 1) { sjf_size_destroy(&sjv_size); }
}

void sjf_filllayout_getsize_heap(sjs_filllayout* _parent, sjs_size* maxsize, sjs_size** _return) {
    int32_t i;
    sjs_filllayout* sjt_dot54 = 0;
    sjs_array_heap_iface_element* sjt_dot55 = 0;
    sjs_filllayout* sjt_dot56 = 0;
    sjs_filllayout* sjt_dot58 = 0;
    int32_t sjt_forEnd2;
    int32_t sjt_forStart2;
    sjs_margin* sjt_functionParam11 = 0;
    sjs_margin* sjt_functionParam8 = 0;
    sjs_size* sjt_parent13 = 0;
    sjs_size* sjt_parent9 = 0;
    sjs_size sjv_innersize = { -1 };
    sjs_size sjv_size = { -1 };

    sjv_size._refCount = 1;
    sjv_size.w = 0;
    sjv_size.h = 0;
    sjf_size(&sjv_size);
    sjt_parent9 = maxsize;
    sjt_dot54 = _parent;
    sjt_functionParam8 = &(sjt_dot54)->margin;
    sjf_size_subtractmargin(sjt_parent9, sjt_functionParam8, &sjv_innersize);
    sjt_forStart2 = 0;
    sjt_dot56 = _parent;
    sjt_dot55 = &(sjt_dot56)->children;
    sjt_forEnd2 = (sjt_dot55)->count;
    i = sjt_forStart2;
    while (i < sjt_forEnd2) {
        sjs_size sjt_call3 = { -1 };
        sjs_filllayout* sjt_dot57 = 0;
        sjs_size* sjt_functionParam10 = 0;
        int32_t sjt_functionParam9;
        sjs_size* sjt_interfaceParam2 = 0;
        sjs_array_heap_iface_element* sjt_parent10 = 0;
        sjs_size* sjt_parent11 = 0;
        sji_element sjt_parent12 = { 0 };
        sji_element sjv_child = { 0 };

        sjt_dot57 = _parent;
        sjt_parent10 = &(sjt_dot57)->children;
        sjt_functionParam9 = i;
        sjf_array_heap_iface_element_getat_heap(sjt_parent10, sjt_functionParam9, &sjv_child);
        sjt_parent11 = &sjv_size;
        sjt_parent12 = sjv_child;
        sjt_interfaceParam2 = &sjv_innersize;
        sjt_call3._refCount = 1;
        sjt_parent12._vtbl->getsize(sjt_parent12._parent, sjt_interfaceParam2, &sjt_call3);
        sjt_functionParam10 = &sjt_call3;
        sjf_size_max(sjt_parent11, sjt_functionParam10, &sjv_size);
        i++;

        if (sjv_child._parent != 0) {
            sjv_child._parent->_refCount--;
            if (sjv_child._parent->_refCount <= 0) {
                sjv_child._vtbl->destroy(sjv_child._parent);
                free(sjv_child._parent);
            }
        }
        if (sjt_call3._refCount == 1) { sjf_size_destroy(&sjt_call3); }
    }

    sjt_parent13 = &sjv_size;
    sjt_dot58 = _parent;
    sjt_functionParam11 = &(sjt_dot58)->margin;
    sjf_size_addmargin_heap(sjt_parent13, sjt_functionParam11, _return);

    if (sjv_innersize._refCount == 1) { sjf_size_destroy(&sjv_innersize); }
    if (sjv_size._refCount == 1) { sjf_size_destroy(&sjv_size); }
}

void sjf_filllayout_heap(sjs_filllayout* _this) {
}

void sjf_filllayout_heap_as_sji_element(sjs_filllayout* _this, sji_element* _return) {
    _return->_parent = (sjs_object*)_this;
    _return->_vtbl = &sjs_filllayout_element_vtbl;
}

void sjf_filllayout_heap_asinterface(sjs_filllayout* _this, int typeId, sjs_interface* _return) {
    switch (typeId) {
        case sji_element_typeId:  {
            sjf_filllayout_heap_as_sji_element(_this, (sji_element*)_return);
            break;
        }

        default: {
            _return->_parent = 0;
            break;
        }
    }
}

void sjf_filllayout_render(sjs_filllayout* _parent, sjs_scene2d* scene) {
    sjs_filllayout* sjt_dot89 = 0;
    bool sjt_isEmpty3;
    sji_effect sjt_isEmpty4 = { 0 };

    sjt_dot89 = _parent;
    sjt_isEmpty4 = (sjt_dot89)->effect;
    sjt_isEmpty3 = (sjt_isEmpty4._parent != 0);
    if (sjt_isEmpty3) {
        sji_effect ifValue9 = { 0 };
        sjs_filllayout* sjt_dot90 = 0;
        sjs_scene2d* sjt_interfaceParam6 = 0;
        cb_scene2d_void sjt_interfaceParam7;
        sji_effect sjt_parent18 = { 0 };

        sjt_dot90 = _parent;
        ifValue9 = (sjt_dot90)->effect;
        if (ifValue9._parent != 0) {
            ifValue9._parent->_refCount++;
        }

        sjt_parent18 = ifValue9;
        sjt_interfaceParam6 = scene;
        sjt_interfaceParam7._parent = (sjs_object*)_parent;
        sjt_interfaceParam7._cb = (void(*)(sjs_object*,sjs_scene2d*))sjf_filllayout_renderinner;
        sjt_parent18._vtbl->render(sjt_parent18._parent, sjt_interfaceParam6, sjt_interfaceParam7);

        if (ifValue9._parent != 0) {
            ifValue9._parent->_refCount--;
            if (ifValue9._parent->_refCount <= 0) {
                ifValue9._vtbl->destroy(ifValue9._parent);
                free(ifValue9._parent);
            }
        }
    } else {
        sjs_scene2d* sjt_functionParam16 = 0;

        sjt_functionParam16 = scene;
        sjf_filllayout_renderinner(_parent, sjt_functionParam16);
    }
}

void sjf_filllayout_renderinner(sjs_filllayout* _parent, sjs_scene2d* scene) {
    int32_t i;
    sjs_array_heap_iface_element* sjt_dot91 = 0;
    sjs_filllayout* sjt_dot92 = 0;
    int32_t sjt_forEnd4;
    int32_t sjt_forStart4;

    sjt_forStart4 = 0;
    sjt_dot92 = _parent;
    sjt_dot91 = &(sjt_dot92)->children;
    sjt_forEnd4 = (sjt_dot91)->count;
    i = sjt_forStart4;
    while (i < sjt_forEnd4) {
        sjs_filllayout* sjt_dot93 = 0;
        int32_t sjt_functionParam15;
        sjs_scene2d* sjt_interfaceParam8 = 0;
        sjs_array_heap_iface_element* sjt_parent19 = 0;
        sji_element sjt_parent20 = { 0 };
        sji_element sjv_child = { 0 };

        sjt_dot93 = _parent;
        sjt_parent19 = &(sjt_dot93)->children;
        sjt_functionParam15 = i;
        sjf_array_heap_iface_element_getat_heap(sjt_parent19, sjt_functionParam15, &sjv_child);
        sjt_parent20 = sjv_child;
        sjt_interfaceParam8 = scene;
        sjt_parent20._vtbl->render(sjt_parent20._parent, sjt_interfaceParam8);
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
    sjs_rect* sjt_copy3 = 0;
    sjs_filllayout* sjt_dot61 = 0;
    sjs_filllayout* sjt_dot82 = 0;
    sjs_filllayout* sjt_dot83 = 0;
    sjs_filllayout* sjt_dot84 = 0;
    sjs_margin* sjt_functionParam12 = 0;
    bool sjt_isEmpty1;
    sji_effect sjt_isEmpty2 = { 0 };
    sjs_rect* sjt_parent14 = 0;
    sjs_rect sjv_innerrect = { -1 };

    sjt_dot61 = _parent;
    sjt_copy3 = rect_;
    sjt_dot61->_rect._refCount = 1;
    sjf_rect_copy(&sjt_dot61->_rect, sjt_copy3);
    sjt_dot82 = _parent;
    sjt_parent14 = &(sjt_dot82)->_rect;
    sjt_dot83 = _parent;
    sjt_functionParam12 = &(sjt_dot83)->margin;
    sjf_rect_subtractmargin(sjt_parent14, sjt_functionParam12, &sjv_innerrect);
    sjt_dot84 = _parent;
    sjt_isEmpty2 = (sjt_dot84)->effect;
    sjt_isEmpty1 = (sjt_isEmpty2._parent != 0);
    if (sjt_isEmpty1) {
        sji_effect ifValue7 = { 0 };
        sjs_filllayout* sjt_dot85 = 0;
        sjs_rect* sjt_interfaceParam3 = 0;
        cb_rect_void sjt_interfaceParam4;
        sji_effect sjt_parent15 = { 0 };

        sjt_dot85 = _parent;
        ifValue7 = (sjt_dot85)->effect;
        if (ifValue7._parent != 0) {
            ifValue7._parent->_refCount++;
        }

        sjt_parent15 = ifValue7;
        sjt_interfaceParam3 = &sjv_innerrect;
        sjt_interfaceParam4._parent = (sjs_object*)_parent;
        sjt_interfaceParam4._cb = (void(*)(sjs_object*,sjs_rect*))sjf_filllayout_setrectinner;
        sjt_parent15._vtbl->setrect(sjt_parent15._parent, sjt_interfaceParam3, sjt_interfaceParam4);

        if (ifValue7._parent != 0) {
            ifValue7._parent->_refCount--;
            if (ifValue7._parent->_refCount <= 0) {
                ifValue7._vtbl->destroy(ifValue7._parent);
                free(ifValue7._parent);
            }
        }
    } else {
        sjs_rect* sjt_functionParam14 = 0;

        sjt_functionParam14 = &sjv_innerrect;
        sjf_filllayout_setrectinner(_parent, sjt_functionParam14);
    }

    if (sjv_innerrect._refCount == 1) { sjf_rect_destroy(&sjv_innerrect); }
}

void sjf_filllayout_setrectinner(sjs_filllayout* _parent, sjs_rect* innerrect) {
    int32_t i;
    sjs_array_heap_iface_element* sjt_dot86 = 0;
    sjs_filllayout* sjt_dot87 = 0;
    int32_t sjt_forEnd3;
    int32_t sjt_forStart3;

    sjt_forStart3 = 0;
    sjt_dot87 = _parent;
    sjt_dot86 = &(sjt_dot87)->children;
    sjt_forEnd3 = (sjt_dot86)->count;
    i = sjt_forStart3;
    while (i < sjt_forEnd3) {
        sjs_filllayout* sjt_dot88 = 0;
        int32_t sjt_functionParam13;
        sjs_rect* sjt_interfaceParam5 = 0;
        sjs_array_heap_iface_element* sjt_parent16 = 0;
        sji_element sjt_parent17 = { 0 };
        sji_element sjv_child = { 0 };

        sjt_dot88 = _parent;
        sjt_parent16 = &(sjt_dot88)->children;
        sjt_functionParam13 = i;
        sjf_array_heap_iface_element_getat_heap(sjt_parent16, sjt_functionParam13, &sjv_child);
        sjt_parent17 = sjv_child;
        sjt_interfaceParam5 = innerrect;
        sjt_parent17._vtbl->setrect(sjt_parent17._parent, sjt_interfaceParam5);
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
    float sjt_functionParam2;
    uint32_t sjt_math3;
    uint32_t sjt_math4;
    sjs_string* sjt_parent2 = 0;

    sjt_dot3 = _parent;
    sjt_parent2 = &(sjt_dot3)->src;
    sjf_string_hash(sjt_parent2, &sjt_math3);
    sjt_dot4 = _parent;
    sjt_functionParam2 = (sjt_dot4)->size;
    sjf_f32_hash(sjt_functionParam2, &sjt_math4);
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
    sjs_string* sjt_functionParam3 = 0;
    sjs_string* sjt_parent3 = 0;

    sjt_dot5 = _parent;
    sjt_parent3 = &(sjt_dot5)->src;
    sjt_dot6 = x;
    sjt_functionParam3 = &(sjt_dot6)->src;
    sjf_string_isequal(sjt_parent3, sjt_functionParam3, &sjt_and1);
    sjt_dot7 = _parent;
    sjt_compare1 = (sjt_dot7)->size;
    sjt_dot8 = x;
    sjt_compare2 = (sjt_dot8)->size;
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
}

void sjf_framebuffer_heap(sjs_framebuffer* _this) {
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

void sjf_glgenframebuffer(sjs_size* size, sjs_framebuffer* _return) {
    sjs_size* sjt_copy11 = 0;
    uint32_t sjv_id;

    sjv_id = (uint32_t)0u;
    glGenFramebuffers(1, &sjv_id);
    _return->_refCount = 1;
    sjt_copy11 = size;
    _return->size._refCount = 1;
    sjf_size_copy(&_return->size, sjt_copy11);
    _return->id = sjv_id;
    sjf_framebuffer(_return);
}

void sjf_glgenframebuffer_heap(sjs_size* size, sjs_framebuffer** _return) {
    sjs_size* sjt_copy12 = 0;
    uint32_t sjv_id;

    sjv_id = (uint32_t)0u;
    glGenFramebuffers(1, &sjv_id);
    (*_return) = (sjs_framebuffer*)malloc(sizeof(sjs_framebuffer));
    (*_return)->_refCount = 1;
    sjt_copy12 = size;
    (*_return)->size._refCount = 1;
    sjf_size_copy(&(*_return)->size, sjt_copy12);
    (*_return)->id = sjv_id;
    sjf_framebuffer_heap((*_return));
}

void sjf_glgenrenderbuffer(sjs_size* size, sjs_renderbuffer* _return) {
    sjs_size* sjt_copy15 = 0;
    uint32_t sjv_id;

    sjv_id = (uint32_t)0u;
    glGenRenderbuffers(1, &sjv_id); 
    _return->_refCount = 1;
    sjt_copy15 = size;
    _return->size._refCount = 1;
    sjf_size_copy(&_return->size, sjt_copy15);
    _return->id = sjv_id;
    sjf_renderbuffer(_return);
}

void sjf_glgenrenderbuffer_heap(sjs_size* size, sjs_renderbuffer** _return) {
    sjs_size* sjt_copy16 = 0;
    uint32_t sjv_id;

    sjv_id = (uint32_t)0u;
    glGenRenderbuffers(1, &sjv_id); 
    (*_return) = (sjs_renderbuffer*)malloc(sizeof(sjs_renderbuffer));
    (*_return)->_refCount = 1;
    sjt_copy16 = size;
    (*_return)->size._refCount = 1;
    sjf_size_copy(&(*_return)->size, sjt_copy16);
    (*_return)->id = sjv_id;
    sjf_renderbuffer_heap((*_return));
}

void sjf_glgentexture(sjs_size* size, sjs_texture* _return) {
    sjs_size* sjt_copy13 = 0;
    uint32_t sjv_id;

    sjv_id = (uint32_t)0u;
    glGenTextures(1, &sjv_id);
    _return->_refCount = 1;
    sjt_copy13 = size;
    _return->size._refCount = 1;
    sjf_size_copy(&_return->size, sjt_copy13);
    _return->id = sjv_id;
    sjf_texture(_return);
}

void sjf_glgentexture_heap(sjs_size* size, sjs_texture** _return) {
    sjs_size* sjt_copy14 = 0;
    uint32_t sjv_id;

    sjv_id = (uint32_t)0u;
    glGenTextures(1, &sjv_id);
    (*_return) = (sjs_texture*)malloc(sizeof(sjs_texture));
    (*_return)->_refCount = 1;
    sjt_copy14 = size;
    (*_return)->size._refCount = 1;
    sjf_size_copy(&(*_return)->size, sjt_copy14);
    (*_return)->id = sjv_id;
    sjf_texture_heap((*_return));
}

void sjf_glgetuniformlocation(sjs_shader* shader, sjs_string* name, int32_t* _return) {
    int result = glGetUniformLocation(shader->id, (char*)name->data.data);
    (*_return) = result;
return;;
}

void sjf_glpopframebuffer(sjs_framebuffer* framebuffer) {
    sjs_string sjt_call40 = { -1 };
    uint32_t sjt_compare57;
    uint32_t sjt_compare58;
    int32_t sjt_compare59;
    int32_t sjt_compare60;
    sjs_framebuffer* sjt_dot299 = 0;
    int32_t sjt_functionParam187;
    int32_t sjt_functionParam189;
    bool sjt_ifElse21;
    bool sjt_ifElse22;
    int32_t sjt_math261;
    int32_t sjt_math262;
    int32_t sjt_math263;
    int32_t sjt_math264;
    sjs_list_u32* sjt_parent102 = 0;
    sjs_list_u32* sjt_parent103 = 0;
    sjs_list_u32* sjt_parent104 = 0;
    sjs_list_u32* sjt_parent105 = 0;
    sjs_list_u32* sjt_parent106 = 0;
    uint32_t sjv_id;

    sjt_parent102 = &sjv_glframebuffers;
    sjt_parent103 = &sjv_glframebuffers;
    sjf_list_u32_getcount(sjt_parent103, &sjt_math261);
    sjt_math262 = 1;
    sjt_functionParam187 = sjt_math261 - sjt_math262;
    sjf_list_u32_getat(sjt_parent102, sjt_functionParam187, &sjt_compare57);
    sjt_dot299 = framebuffer;
    sjt_compare58 = (sjt_dot299)->id;
    sjt_ifElse21 = sjt_compare57 != sjt_compare58;
    if (sjt_ifElse21) {
        sjs_string* sjt_functionParam188 = 0;

        sjt_call40._refCount = 1;
        sjt_call40.count = 33;
        sjt_call40.data._refCount = 1;
        sjt_call40.data.datasize = 34;
        sjt_call40.data.data = (void*)sjg_string19;
        sjt_call40.data._isglobal = true;
        sjt_call40.data.count = 34;
        sjf_array_char(&sjt_call40.data);
        sjf_string(&sjt_call40);
        sjt_functionParam188 = &sjt_call40;
        sjf_halt(sjt_functionParam188);
    }

    sjt_parent104 = &sjv_glframebuffers;
    sjt_parent105 = &sjv_glframebuffers;
    sjf_list_u32_getcount(sjt_parent105, &sjt_math263);
    sjt_math264 = 1;
    sjt_functionParam189 = sjt_math263 - sjt_math264;
    sjf_list_u32_removeat(sjt_parent104, sjt_functionParam189);
    sjt_parent106 = &sjv_glframebuffers;
    sjf_list_u32_getcount(sjt_parent106, &sjt_compare59);
    sjt_compare60 = 0;
    sjt_ifElse22 = sjt_compare59 > sjt_compare60;
    if (sjt_ifElse22) {
        int32_t sjt_functionParam190;
        int32_t sjt_math265;
        int32_t sjt_math266;
        sjs_list_u32* sjt_parent107 = 0;
        sjs_list_u32* sjt_parent108 = 0;

        sjt_parent107 = &sjv_glframebuffers;
        sjt_parent108 = &sjv_glframebuffers;
        sjf_list_u32_getcount(sjt_parent108, &sjt_math265);
        sjt_math266 = 1;
        sjt_functionParam190 = sjt_math265 - sjt_math266;
        sjf_list_u32_getat(sjt_parent107, sjt_functionParam190, &sjv_id);
    } else {
        sjv_id = (uint32_t)0u;
    }

    glBindFramebuffer(GL_FRAMEBUFFER, sjv_id);

    if (sjt_call40._refCount == 1) { sjf_string_destroy(&sjt_call40); }
}

void sjf_glpopviewport(sjs_rect* rect, sjs_rect* scenerect) {
    bool result4;
    sjs_rect sjt_call36 = { -1 };
    sjs_string sjt_call37 = { -1 };
    int32_t sjt_compare51;
    int32_t sjt_compare52;
    sjs_rect* sjt_dot268 = 0;
    sjs_rect* sjt_dot269 = 0;
    sjs_rect* sjt_dot270 = 0;
    sjs_rect* sjt_dot271 = 0;
    sjs_rect* sjt_dot272 = 0;
    sjs_rect* sjt_dot273 = 0;
    int32_t sjt_functionParam133;
    sjs_rect* sjt_functionParam134 = 0;
    int32_t sjt_functionParam136;
    bool sjt_ifElse17;
    bool sjt_ifElse18;
    int32_t sjt_math249;
    int32_t sjt_math250;
    int32_t sjt_math251;
    int32_t sjt_math252;
    int32_t sjt_math253;
    int32_t sjt_math254;
    int32_t sjt_math255;
    int32_t sjt_math256;
    bool sjt_not2;
    sjs_rect* sjt_parent85 = 0;
    sjs_list_rect* sjt_parent87 = 0;
    sjs_list_rect* sjt_parent88 = 0;
    sjs_list_rect* sjt_parent89 = 0;
    sjs_list_rect* sjt_parent90 = 0;
    sjs_list_rect* sjt_parent91 = 0;
    sjs_rect sjv_newrect = { -1 };
    sjs_rect sjv_oldrect = { -1 };

    sjv_oldrect._refCount = 1;
    sjt_dot268 = rect;
    sjv_oldrect.x = (sjt_dot268)->x;
    sjt_dot269 = scenerect;
    sjt_math249 = (sjt_dot269)->h;
    sjt_dot270 = rect;
    sjt_math251 = (sjt_dot270)->y;
    sjt_dot271 = rect;
    sjt_math252 = (sjt_dot271)->h;
    sjt_math250 = sjt_math251 + sjt_math252;
    sjv_oldrect.y = sjt_math249 - sjt_math250;
    sjt_dot272 = rect;
    sjv_oldrect.w = (sjt_dot272)->w;
    sjt_dot273 = rect;
    sjv_oldrect.h = (sjt_dot273)->h;
    sjf_rect(&sjv_oldrect);
    sjt_parent87 = &sjv_glviewports;
    sjt_parent88 = &sjv_glviewports;
    sjf_list_rect_getcount(sjt_parent88, &sjt_math253);
    sjt_math254 = 1;
    sjt_functionParam133 = sjt_math253 - sjt_math254;
    sjf_list_rect_getat(sjt_parent87, sjt_functionParam133, &sjt_call36);
    sjt_parent85 = &sjt_call36;
    sjt_functionParam134 = &sjv_oldrect;
    sjf_rect_isequal(sjt_parent85, sjt_functionParam134, &sjt_not2);
    result4 = !sjt_not2;
    sjt_ifElse17 = result4;
    if (sjt_ifElse17) {
        sjs_string* sjt_functionParam135 = 0;

        sjt_call37._refCount = 1;
        sjt_call37.count = 30;
        sjt_call37.data._refCount = 1;
        sjt_call37.data.datasize = 31;
        sjt_call37.data.data = (void*)sjg_string23;
        sjt_call37.data._isglobal = true;
        sjt_call37.data.count = 31;
        sjf_array_char(&sjt_call37.data);
        sjf_string(&sjt_call37);
        sjt_functionParam135 = &sjt_call37;
        sjf_halt(sjt_functionParam135);
    }

    sjt_parent89 = &sjv_glviewports;
    sjt_parent90 = &sjv_glviewports;
    sjf_list_rect_getcount(sjt_parent90, &sjt_math255);
    sjt_math256 = 1;
    sjt_functionParam136 = sjt_math255 - sjt_math256;
    sjf_list_rect_removeat(sjt_parent89, sjt_functionParam136);
    sjt_parent91 = &sjv_glviewports;
    sjf_list_rect_getcount(sjt_parent91, &sjt_compare51);
    sjt_compare52 = 0;
    sjt_ifElse18 = sjt_compare51 > sjt_compare52;
    if (sjt_ifElse18) {
        int32_t sjt_functionParam137;
        int32_t sjt_math257;
        int32_t sjt_math258;
        sjs_list_rect* sjt_parent92 = 0;
        sjs_list_rect* sjt_parent93 = 0;

        sjt_parent92 = &sjv_glviewports;
        sjt_parent93 = &sjv_glviewports;
        sjf_list_rect_getcount(sjt_parent93, &sjt_math257);
        sjt_math258 = 1;
        sjt_functionParam137 = sjt_math257 - sjt_math258;
        sjf_list_rect_getat(sjt_parent92, sjt_functionParam137, &sjv_newrect);
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
    if (sjt_call37._refCount == 1) { sjf_string_destroy(&sjt_call37); }
    if (sjv_newrect._refCount == 1) { sjf_rect_destroy(&sjv_newrect); }
    if (sjv_oldrect._refCount == 1) { sjf_rect_destroy(&sjv_oldrect); }
}

void sjf_glpushframebuffer(sjs_framebuffer* framebuffer) {
    sjs_framebuffer* sjt_dot295 = 0;
    uint32_t sjt_functionParam154;
    sjs_list_u32* sjt_parent100 = 0;

    sjt_parent100 = &sjv_glframebuffers;
    sjt_dot295 = framebuffer;
    sjt_functionParam154 = (sjt_dot295)->id;
    sjf_list_u32_add(sjt_parent100, sjt_functionParam154);
    glBindFramebuffer(GL_FRAMEBUFFER, framebuffer->id);
}

void sjf_glpushviewport(sjs_rect* rect, sjs_rect* scenerect) {
    sjs_rect* sjt_dot210 = 0;
    sjs_rect* sjt_dot211 = 0;
    sjs_rect* sjt_dot212 = 0;
    sjs_rect* sjt_dot213 = 0;
    sjs_rect* sjt_dot214 = 0;
    sjs_rect* sjt_dot215 = 0;
    sjs_rect* sjt_functionParam52 = 0;
    int32_t sjt_math205;
    int32_t sjt_math206;
    int32_t sjt_math207;
    int32_t sjt_math208;
    sjs_list_rect* sjt_parent46 = 0;
    sjs_rect sjv_newrect = { -1 };

    sjv_newrect._refCount = 1;
    sjt_dot210 = rect;
    sjv_newrect.x = (sjt_dot210)->x;
    sjt_dot211 = scenerect;
    sjt_math205 = (sjt_dot211)->h;
    sjt_dot212 = rect;
    sjt_math207 = (sjt_dot212)->y;
    sjt_dot213 = rect;
    sjt_math208 = (sjt_dot213)->h;
    sjt_math206 = sjt_math207 + sjt_math208;
    sjv_newrect.y = sjt_math205 - sjt_math206;
    sjt_dot214 = rect;
    sjv_newrect.w = (sjt_dot214)->w;
    sjt_dot215 = rect;
    sjv_newrect.h = (sjt_dot215)->h;
    sjf_rect(&sjv_newrect);
    sjt_parent46 = &sjv_glviewports;
    sjt_functionParam52 = &sjv_newrect;
    sjf_list_rect_add(sjt_parent46, sjt_functionParam52);
    glViewport(sjv_newrect.x, sjv_newrect.y, sjv_newrect.w, sjv_newrect.h);

    if (sjv_newrect._refCount == 1) { sjf_rect_destroy(&sjv_newrect); }
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

void sjf_gluniformmat4(int32_t loc, sjs_mat4* m) {
    glUniformMatrix4fv(loc, 1, 0, (GLfloat*)&m->m00);
}

void sjf_gluniformvec3(int32_t loc, sjs_vec3* v) {
    glUniform3fv(loc, 1, (GLfloat*)&v->x);
}

void sjf_gluseprogram(sjs_shader* shader) {
    glUseProgram(shader->id);
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

void sjf_hash_string_weak_iface_model_setat(sjs_hash_string_weak_iface_model* _parent, sjs_string* key, sji_model val) {
    khash_t(string_weak_iface_model_hash_type)* p = (khash_t(string_weak_iface_model_hash_type)*)_parent->_hash;
    #if true
    khiter_t k = kh_get(string_weak_iface_model_hash_type, p, *key);
    #else
    khiter_t k = kh_get(string_weak_iface_model_hash_type, p, key);
    #endif
    if (k != kh_end(p)) {            
    delete_cb weakptrcb12 = { &kh_val(p, k)._parent, weakptr_clear };
if (kh_val(p, k)._parent != 0) { weakptr_cb_remove(kh_val(p, k)._parent, weakptrcb12); }
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
delete_cb weakptrcb13 = { &kh_val(p, k)._parent, weakptr_clear };
if (kh_val(p, k)._parent != 0) { weakptr_cb_add(kh_val(p, k)._parent, weakptrcb13); }
;
#endif
}

void sjf_i32_asstring(int32_t val, sjs_string* _return) {
    int32_t sjt_math227;
    int32_t sjt_math228;
    int32_t sjt_math229;
    int32_t sjt_math230;
    int32_t sjv_count;
    void* sjv_data;

    sjv_count = 0;
    sjv_data = 0;
    sjv_data = malloc(sizeof(char) * 50);
    snprintf((char*)sjv_data, 50, "%d", val);
    sjv_count = strlen((char*)sjv_data);
    _return->_refCount = 1;
    _return->count = sjv_count;
    _return->data._refCount = 1;
    sjt_math227 = sjv_count;
    sjt_math228 = 1;
    _return->data.datasize = sjt_math227 + sjt_math228;
    _return->data.data = sjv_data;
    _return->data._isglobal = false;
    sjt_math229 = sjv_count;
    sjt_math230 = 1;
    _return->data.count = sjt_math229 + sjt_math230;
    sjf_array_char(&_return->data);
    sjf_string(_return);
}

void sjf_i32_asstring_heap(int32_t val, sjs_string** _return) {
    int32_t sjt_math231;
    int32_t sjt_math232;
    int32_t sjt_math233;
    int32_t sjt_math234;
    int32_t sjv_count;
    void* sjv_data;

    sjv_count = 0;
    sjv_data = 0;
    sjv_data = malloc(sizeof(char) * 50);
    snprintf((char*)sjv_data, 50, "%d", val);
    sjv_count = strlen((char*)sjv_data);
    (*_return) = (sjs_string*)malloc(sizeof(sjs_string));
    (*_return)->_refCount = 1;
    (*_return)->count = sjv_count;
    (*_return)->data._refCount = 1;
    sjt_math231 = sjv_count;
    sjt_math232 = 1;
    (*_return)->data.datasize = sjt_math231 + sjt_math232;
    (*_return)->data.data = sjv_data;
    (*_return)->data._isglobal = false;
    sjt_math233 = sjv_count;
    sjt_math234 = 1;
    (*_return)->data.count = sjt_math233 + sjt_math234;
    sjf_array_char(&(*_return)->data);
    sjf_string_heap((*_return));
}

void sjf_i32_max(int32_t a, int32_t b, int32_t* _return) {
    int32_t sjt_compare21;
    int32_t sjt_compare22;
    bool sjt_ifElse8;

    sjt_compare21 = a;
    sjt_compare22 = b;
    sjt_ifElse8 = sjt_compare21 < sjt_compare22;
    if (sjt_ifElse8) {
        (*_return) = b;
    } else {
        (*_return) = a;
    }
}

void sjf_image(sjs_image* _this) {
    bool sjt_and11;
    bool sjt_and12;
    sjs_rect sjt_call60 = { -1 };
    int32_t sjt_compare101;
    int32_t sjt_compare102;
    int32_t sjt_compare103;
    int32_t sjt_compare104;
    sjs_rect* sjt_dot1558 = 0;
    sjs_rect* sjt_dot1559 = 0;
    bool sjt_ifElse43;
    sjs_size sjv_size = { -1 };

    sjt_dot1558 = &_this->rect;
    sjt_compare101 = (sjt_dot1558)->w;
    sjt_compare102 = 0;
    sjt_and11 = sjt_compare101 == sjt_compare102;
    sjt_dot1559 = &_this->rect;
    sjt_compare103 = (sjt_dot1559)->h;
    sjt_compare104 = 0;
    sjt_and12 = sjt_compare103 == sjt_compare104;
    sjt_ifElse43 = sjt_and11 && sjt_and12;
    if (sjt_ifElse43) {
        sjs_rect* sjt_copy36 = 0;
        sjs_size* sjt_dot1568 = 0;
        sjs_size* sjt_dot1569 = 0;
        sjs_texture* sjt_parent191 = 0;

        sjt_parent191 = &_this->texture;
        sjf_texture_getsize(sjt_parent191, &sjv_size);
        sjt_call60._refCount = 1;
        sjt_call60.x = 0;
        sjt_call60.y = 0;
        sjt_dot1568 = &sjv_size;
        sjt_call60.w = (sjt_dot1568)->w;
        sjt_dot1569 = &sjv_size;
        sjt_call60.h = (sjt_dot1569)->h;
        sjf_rect(&sjt_call60);
        sjt_copy36 = &sjt_call60;
        _this->rect._refCount = 1;
        sjf_rect_copy(&_this->rect, sjt_copy36);
    }

    if (sjt_call60._refCount == 1) { sjf_rect_destroy(&sjt_call60); }
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
    bool sjt_and13;
    bool sjt_and14;
    sjs_rect sjt_call61 = { -1 };
    int32_t sjt_compare105;
    int32_t sjt_compare106;
    int32_t sjt_compare107;
    int32_t sjt_compare108;
    sjs_rect* sjt_dot1570 = 0;
    sjs_rect* sjt_dot1571 = 0;
    bool sjt_ifElse44;
    sjs_size sjv_size = { -1 };

    sjt_dot1570 = &_this->rect;
    sjt_compare105 = (sjt_dot1570)->w;
    sjt_compare106 = 0;
    sjt_and13 = sjt_compare105 == sjt_compare106;
    sjt_dot1571 = &_this->rect;
    sjt_compare107 = (sjt_dot1571)->h;
    sjt_compare108 = 0;
    sjt_and14 = sjt_compare107 == sjt_compare108;
    sjt_ifElse44 = sjt_and13 && sjt_and14;
    if (sjt_ifElse44) {
        sjs_rect* sjt_copy37 = 0;
        sjs_size* sjt_dot1572 = 0;
        sjs_size* sjt_dot1573 = 0;
        sjs_texture* sjt_parent192 = 0;

        sjt_parent192 = &_this->texture;
        sjf_texture_getsize(sjt_parent192, &sjv_size);
        sjt_call61._refCount = 1;
        sjt_call61.x = 0;
        sjt_call61.y = 0;
        sjt_dot1572 = &sjv_size;
        sjt_call61.w = (sjt_dot1572)->w;
        sjt_dot1573 = &sjv_size;
        sjt_call61.h = (sjt_dot1573)->h;
        sjf_rect(&sjt_call61);
        sjt_copy37 = &sjt_call61;
        _this->rect._refCount = 1;
        sjf_rect_copy(&_this->rect, sjt_copy37);
    }

    if (sjt_call61._refCount == 1) { sjf_rect_destroy(&sjt_call61); }
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

        default: {
            _return->_parent = 0;
            break;
        }
    }
}

void sjf_imageelement_copy(sjs_imageelement* _this, sjs_imageelement* _from) {
    _this->image._refCount = 1;
    sjf_image_copy(&_this->image, &_from->image);
    _this->margin._refCount = 1;
    sjf_margin_copy(&_this->margin, &_from->margin);
    _this->stretch = _from->stretch;
    _this->_rect._refCount = 1;
    sjf_rect_copy(&_this->_rect, &_from->_rect);
    _this->_imagerenderer._refCount = 1;
    sjf_imagerenderer_copy((_this->_imagerenderer._refCount != -1 ? &_this->_imagerenderer : 0), (_from->_imagerenderer._refCount != -1 ? &_from->_imagerenderer : 0));
}

void sjf_imageelement_destroy(sjs_imageelement* _this) {
}

void sjf_imageelement_firemouseevent(sjs_imageelement* _parent, sjs_mouseevent* mouseevent, bool* _return) {
    (*_return) = true;
}

void sjf_imageelement_getrect(sjs_imageelement* _parent, sjs_rect* _return) {
    sjs_rect* sjt_copy38 = 0;
    sjs_imageelement* sjt_dot1578 = 0;

    sjt_dot1578 = _parent;
    sjt_copy38 = &(sjt_dot1578)->_rect;
    _return->_refCount = 1;
    sjf_rect_copy(_return, sjt_copy38);
}

void sjf_imageelement_getrect_heap(sjs_imageelement* _parent, sjs_rect** _return) {
    sjs_rect* sjt_copy39 = 0;
    sjs_imageelement* sjt_dot1579 = 0;

    sjt_dot1579 = _parent;
    sjt_copy39 = &(sjt_dot1579)->_rect;
    (*_return) = (sjs_rect*)malloc(sizeof(sjs_rect));
    (*_return)->_refCount = 1;
    sjf_rect_copy((*_return), sjt_copy39);
}

void sjf_imageelement_getsize(sjs_imageelement* _parent, sjs_size* maxsize, sjs_size* _return) {
    sjs_size* sjt_dot1574 = 0;
    sjs_size* sjt_dot1575 = 0;

    _return->_refCount = 1;
    sjt_dot1574 = maxsize;
    _return->w = (sjt_dot1574)->w;
    sjt_dot1575 = maxsize;
    _return->h = (sjt_dot1575)->h;
    sjf_size(_return);
}

void sjf_imageelement_getsize_heap(sjs_imageelement* _parent, sjs_size* maxsize, sjs_size** _return) {
    sjs_size* sjt_dot1576 = 0;
    sjs_size* sjt_dot1577 = 0;

    (*_return) = (sjs_size*)malloc(sizeof(sjs_size));
    (*_return)->_refCount = 1;
    sjt_dot1576 = maxsize;
    (*_return)->w = (sjt_dot1576)->w;
    sjt_dot1577 = maxsize;
    (*_return)->h = (sjt_dot1577)->h;
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

        default: {
            _return->_parent = 0;
            break;
        }
    }
}

void sjf_imageelement_render(sjs_imageelement* _parent, sjs_scene2d* scene) {
    sjs_imageelement* sjt_dot1583 = 0;
    sjs_imageelement* sjt_dot1633 = 0;
    bool sjt_ifElse46;
    bool sjt_ifElse52;
    sjs_imagerenderer* sjt_isEmpty16 = 0;
    sjs_imagerenderer* sjt_isEmpty17 = 0;
    sjs_rect sjv_r = { -1 };

    sjt_dot1583 = _parent;
    sjt_isEmpty16 = ((sjt_dot1583)->_imagerenderer._refCount != -1 ? &(sjt_dot1583)->_imagerenderer : 0);
    sjt_ifElse46 = (sjt_isEmpty16 == 0);
    if (sjt_ifElse46) {
        int32_t sjt_compare109;
        int32_t sjt_compare110;
        sjs_rect* sjt_copy41 = 0;
        sjs_image* sjt_copy42 = 0;
        sjs_imageelement* sjt_dot1584 = 0;
        sjs_imageelement* sjt_dot1585 = 0;
        sjs_imageelement* sjt_dot1586 = 0;
        sjs_imageelement* sjt_dot1631 = 0;
        sjs_imageelement* sjt_dot1632 = 0;
        sjs_margin* sjt_functionParam350 = 0;
        sjs_rect* sjt_parent194 = 0;
        bool sjt_switch1;
        int32_t underscore1;

        sjt_dot1584 = _parent;
        sjt_parent194 = &(sjt_dot1584)->_rect;
        sjt_dot1585 = _parent;
        sjt_functionParam350 = &(sjt_dot1585)->margin;
        sjf_rect_subtractmargin(sjt_parent194, sjt_functionParam350, &sjv_r);
        sjt_dot1586 = _parent;
        underscore1 = (sjt_dot1586)->stretch;
        sjt_compare109 = underscore1;
        sjt_compare110 = sjv_imagestretch_fill;
        sjt_switch1 = sjt_compare109 == sjt_compare110;
        if (sjt_switch1) {
        } else {
            int32_t sjt_compare111;
            int32_t sjt_compare112;
            bool sjt_switch2;

            sjt_compare111 = underscore1;
            sjt_compare112 = sjv_imagestretch_center;
            sjt_switch2 = sjt_compare111 == sjt_compare112;
            if (sjt_switch2) {
                sjs_size sjt_call62 = { -1 };
                sjs_rect* sjt_dot1587 = 0;
                sjs_rect* sjt_dot1588 = 0;
                sjs_image* sjt_dot1605 = 0;
                sjs_imageelement* sjt_dot1606 = 0;
                sjs_rect* sjt_dot1607 = 0;
                sjs_size* sjt_dot1608 = 0;
                sjs_rect* sjt_dot1609 = 0;
                sjs_size* sjt_dot1610 = 0;
                sjs_size* sjt_dot1611 = 0;
                sjs_size* sjt_dot1612 = 0;
                sjs_size* sjt_functionParam351 = 0;
                int32_t sjt_math2633;
                int32_t sjt_math2634;
                int32_t sjt_math2635;
                int32_t sjt_math2636;
                int32_t sjt_math2637;
                int32_t sjt_math2638;
                int32_t sjt_math2639;
                int32_t sjt_math2640;
                sjs_size* sjt_parent195 = 0;
                sjs_texture* sjt_parent196 = 0;
                sjs_size sjv_finalsize = { -1 };
                sjs_size sjv_s = { -1 };

                sjv_s._refCount = 1;
                sjt_dot1587 = &sjv_r;
                sjv_s.w = (sjt_dot1587)->w;
                sjt_dot1588 = &sjv_r;
                sjv_s.h = (sjt_dot1588)->h;
                sjf_size(&sjv_s);
                sjt_parent195 = &sjv_s;
                sjt_dot1606 = _parent;
                sjt_dot1605 = &(sjt_dot1606)->image;
                sjt_parent196 = &(sjt_dot1605)->texture;
                sjf_texture_getsize(sjt_parent196, &sjt_call62);
                sjt_functionParam351 = &sjt_call62;
                sjf_size_min(sjt_parent195, sjt_functionParam351, &sjv_finalsize);
                sjv_r._refCount = 1;
                sjt_dot1607 = &sjv_r;
                sjt_math2635 = (sjt_dot1607)->w;
                sjt_dot1608 = &sjv_finalsize;
                sjt_math2636 = (sjt_dot1608)->w;
                sjt_math2633 = sjt_math2635 - sjt_math2636;
                sjt_math2634 = 2;
                sjv_r.x = sjt_math2633 / sjt_math2634;
                sjt_dot1609 = &sjv_r;
                sjt_math2639 = (sjt_dot1609)->h;
                sjt_dot1610 = &sjv_finalsize;
                sjt_math2640 = (sjt_dot1610)->h;
                sjt_math2637 = sjt_math2639 - sjt_math2640;
                sjt_math2638 = 2;
                sjv_r.y = sjt_math2637 / sjt_math2638;
                sjt_dot1611 = &sjv_finalsize;
                sjv_r.w = (sjt_dot1611)->w;
                sjt_dot1612 = &sjv_finalsize;
                sjv_r.h = (sjt_dot1612)->h;
                sjf_rect(&sjv_r);

                if (sjt_call62._refCount == 1) { sjf_size_destroy(&sjt_call62); }
                if (sjv_finalsize._refCount == 1) { sjf_size_destroy(&sjv_finalsize); }
                if (sjv_s._refCount == 1) { sjf_size_destroy(&sjv_s); }
            } else {
                int32_t sjt_compare121;
                int32_t sjt_compare122;
                bool sjt_switch3;

                sjt_compare121 = underscore1;
                sjt_compare122 = sjv_imagestretch_aspectratio;
                sjt_switch3 = sjt_compare121 == sjt_compare122;
                if (sjt_switch3) {
                    sjs_size sjt_call63 = { -1 };
                    sjs_size sjt_call64 = { -1 };
                    int32_t sjt_cast37;
                    int32_t sjt_cast38;
                    int32_t sjt_cast39;
                    int32_t sjt_cast40;
                    float sjt_compare123;
                    float sjt_compare124;
                    sjs_size* sjt_dot1613 = 0;
                    sjs_image* sjt_dot1614 = 0;
                    sjs_imageelement* sjt_dot1615 = 0;
                    sjs_size* sjt_dot1616 = 0;
                    sjs_image* sjt_dot1617 = 0;
                    sjs_imageelement* sjt_dot1618 = 0;
                    sjs_rect* sjt_dot1619 = 0;
                    sjs_rect* sjt_dot1620 = 0;
                    sjs_rect* sjt_dot1625 = 0;
                    sjs_size* sjt_dot1626 = 0;
                    sjs_rect* sjt_dot1627 = 0;
                    sjs_size* sjt_dot1628 = 0;
                    sjs_size* sjt_dot1629 = 0;
                    sjs_size* sjt_dot1630 = 0;
                    bool sjt_ifElse51;
                    float sjt_math2641;
                    float sjt_math2642;
                    float sjt_math2643;
                    float sjt_math2644;
                    int32_t sjt_math2649;
                    int32_t sjt_math2650;
                    int32_t sjt_math2651;
                    int32_t sjt_math2652;
                    int32_t sjt_math2653;
                    int32_t sjt_math2654;
                    int32_t sjt_math2655;
                    int32_t sjt_math2656;
                    sjs_texture* sjt_parent197 = 0;
                    sjs_texture* sjt_parent198 = 0;
                    sjs_size sjv_finalsize = { -1 };
                    float sjv_imageaspectratio;
                    float sjv_rectaspectratio;

                    sjt_dot1615 = _parent;
                    sjt_dot1614 = &(sjt_dot1615)->image;
                    sjt_parent197 = &(sjt_dot1614)->texture;
                    sjf_texture_getsize(sjt_parent197, &sjt_call63);
                    sjt_dot1613 = &sjt_call63;
                    sjt_cast37 = (sjt_dot1613)->w;
                    sjt_math2641 = (float)sjt_cast37;
                    sjt_dot1618 = _parent;
                    sjt_dot1617 = &(sjt_dot1618)->image;
                    sjt_parent198 = &(sjt_dot1617)->texture;
                    sjf_texture_getsize(sjt_parent198, &sjt_call64);
                    sjt_dot1616 = &sjt_call64;
                    sjt_cast38 = (sjt_dot1616)->h;
                    sjt_math2642 = (float)sjt_cast38;
                    sjv_imageaspectratio = sjt_math2641 / sjt_math2642;
                    sjt_dot1619 = &sjv_r;
                    sjt_cast39 = (sjt_dot1619)->w;
                    sjt_math2643 = (float)sjt_cast39;
                    sjt_dot1620 = &sjv_r;
                    sjt_cast40 = (sjt_dot1620)->h;
                    sjt_math2644 = (float)sjt_cast40;
                    sjv_rectaspectratio = sjt_math2643 / sjt_math2644;
                    sjt_compare123 = sjv_imageaspectratio;
                    sjt_compare124 = sjv_rectaspectratio;
                    sjt_ifElse51 = sjt_compare123 > sjt_compare124;
                    if (sjt_ifElse51) {
                        float sjt_cast41;
                        int32_t sjt_cast42;
                        sjs_rect* sjt_dot1621 = 0;
                        sjs_rect* sjt_dot1622 = 0;
                        float sjt_math2645;
                        float sjt_math2646;

                        sjv_finalsize._refCount = 1;
                        sjt_dot1621 = &sjv_r;
                        sjv_finalsize.w = (sjt_dot1621)->w;
                        sjt_dot1622 = &sjv_r;
                        sjt_cast42 = (sjt_dot1622)->h;
                        sjt_math2645 = (float)sjt_cast42;
                        sjt_math2646 = sjv_imageaspectratio;
                        sjt_cast41 = sjt_math2645 / sjt_math2646;
                        sjv_finalsize.h = (int32_t)sjt_cast41;
                        sjf_size(&sjv_finalsize);
                    } else {
                        float sjt_cast43;
                        int32_t sjt_cast44;
                        sjs_rect* sjt_dot1623 = 0;
                        sjs_rect* sjt_dot1624 = 0;
                        float sjt_math2647;
                        float sjt_math2648;

                        sjv_finalsize._refCount = 1;
                        sjt_dot1623 = &sjv_r;
                        sjt_cast44 = (sjt_dot1623)->w;
                        sjt_math2647 = (float)sjt_cast44;
                        sjt_math2648 = sjv_imageaspectratio;
                        sjt_cast43 = sjt_math2647 * sjt_math2648;
                        sjv_finalsize.w = (int32_t)sjt_cast43;
                        sjt_dot1624 = &sjv_r;
                        sjv_finalsize.h = (sjt_dot1624)->h;
                        sjf_size(&sjv_finalsize);
                    }

                    sjv_r._refCount = 1;
                    sjt_dot1625 = &sjv_r;
                    sjt_math2651 = (sjt_dot1625)->w;
                    sjt_dot1626 = &sjv_finalsize;
                    sjt_math2652 = (sjt_dot1626)->w;
                    sjt_math2649 = sjt_math2651 - sjt_math2652;
                    sjt_math2650 = 2;
                    sjv_r.x = sjt_math2649 / sjt_math2650;
                    sjt_dot1627 = &sjv_r;
                    sjt_math2655 = (sjt_dot1627)->h;
                    sjt_dot1628 = &sjv_finalsize;
                    sjt_math2656 = (sjt_dot1628)->h;
                    sjt_math2653 = sjt_math2655 - sjt_math2656;
                    sjt_math2654 = 2;
                    sjv_r.y = sjt_math2653 / sjt_math2654;
                    sjt_dot1629 = &sjv_finalsize;
                    sjv_r.w = (sjt_dot1629)->w;
                    sjt_dot1630 = &sjv_finalsize;
                    sjv_r.h = (sjt_dot1630)->h;
                    sjf_rect(&sjv_r);

                    if (sjt_call63._refCount == 1) { sjf_size_destroy(&sjt_call63); }
                    if (sjt_call64._refCount == 1) { sjf_size_destroy(&sjt_call64); }
                    if (sjv_finalsize._refCount == 1) { sjf_size_destroy(&sjv_finalsize); }
                }
            }
        }

        sjt_dot1631 = _parent;
        sjt_dot1631->_imagerenderer._refCount = 1;
        sjt_copy41 = &sjv_r;
        sjt_dot1631->_imagerenderer.rect._refCount = 1;
        sjf_rect_copy(&sjt_dot1631->_imagerenderer.rect, sjt_copy41);
        sjt_dot1632 = _parent;
        sjt_copy42 = &(sjt_dot1632)->image;
        sjt_dot1631->_imagerenderer.image._refCount = 1;
        sjf_image_copy(&sjt_dot1631->_imagerenderer.image, sjt_copy42);
        sjf_imagerenderer(&sjt_dot1631->_imagerenderer);
    }

    sjt_dot1633 = _parent;
    sjt_isEmpty17 = ((sjt_dot1633)->_imagerenderer._refCount != -1 ? &(sjt_dot1633)->_imagerenderer : 0);
    sjt_ifElse52 = (sjt_isEmpty17 != 0);
    if (sjt_ifElse52) {
        sjs_imageelement* sjt_dot1634 = 0;
        sjs_scene2d* sjt_functionParam352 = 0;
        sjs_imagerenderer* sjt_parent199 = 0;

        sjt_dot1634 = _parent;
        sjt_parent199 = ((sjt_dot1634)->_imagerenderer._refCount != -1 ? &(sjt_dot1634)->_imagerenderer : 0);
        sjt_functionParam352 = scene;
        sjf_imagerenderer_render(sjt_parent199, sjt_functionParam352);
    }

    if (sjv_r._refCount == 1) { sjf_rect_destroy(&sjv_r); }
}

void sjf_imageelement_setrect(sjs_imageelement* _parent, sjs_rect* rect_) {
    bool result10;
    sjs_imageelement* sjt_dot1580 = 0;
    sjs_rect* sjt_functionParam349 = 0;
    bool sjt_ifElse45;
    bool sjt_not4;
    sjs_rect* sjt_parent193 = 0;

    sjt_dot1580 = _parent;
    sjt_parent193 = &(sjt_dot1580)->_rect;
    sjt_functionParam349 = rect_;
    sjf_rect_isequal(sjt_parent193, sjt_functionParam349, &sjt_not4);
    result10 = !sjt_not4;
    sjt_ifElse45 = result10;
    if (sjt_ifElse45) {
        sjs_rect* sjt_copy40 = 0;
        sjs_imageelement* sjt_dot1581 = 0;
        sjs_imageelement* sjt_dot1582 = 0;

        sjt_dot1581 = _parent;
        sjt_copy40 = rect_;
        sjt_dot1581->_rect._refCount = 1;
        sjf_rect_copy(&sjt_dot1581->_rect, sjt_copy40);
        sjt_dot1582 = _parent;
        sjt_dot1582->_imagerenderer._refCount = -1;
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
    float sjt_compare75;
    float sjt_compare76;
    float sjt_compare77;
    float sjt_compare78;
    sjs_vec3* sjt_functionParam275 = 0;
    sjs_vec3* sjt_functionParam276 = 0;
    sjs_vec3* sjt_functionParam277 = 0;
    sjs_vec3* sjt_functionParam278 = 0;
    bool sjt_ifElse30;
    bool sjt_ifElse31;
    sjs_vec3* sjt_parent151 = 0;
    sjs_vec3* sjt_parent152 = 0;
    sjs_vec3* sjt_parent153 = 0;
    sjs_vec3* sjt_parent154 = 0;
    float sjv_det;
    sjs_vec3 sjv_edge1 = { -1 };
    sjs_vec3 sjv_edge2 = { -1 };
    sjs_vec3 sjv_pvec = { -1 };
    sjs_vec3 sjv_qvec = { -1 };
    sjs_vec3 sjv_tvec = { -1 };

    sjt_parent151 = v1;
    sjt_functionParam275 = v0;
    sjf_vec3_subtract(sjt_parent151, sjt_functionParam275, &sjv_edge1);
    sjt_parent152 = v2;
    sjt_functionParam276 = v0;
    sjf_vec3_subtract(sjt_parent152, sjt_functionParam276, &sjv_edge2);
    sjt_parent153 = dir;
    sjt_functionParam277 = &sjv_edge2;
    sjf_vec3_cross(sjt_parent153, sjt_functionParam277, &sjv_pvec);
    sjt_parent154 = &sjv_edge1;
    sjt_functionParam278 = &sjv_pvec;
    sjf_vec3_dot(sjt_parent154, sjt_functionParam278, &sjv_det);
    sjt_compare75 = sjv_det;
    sjt_compare76 = 0.0f;
    sjt_ifElse30 = sjt_compare75 > sjt_compare76;
    if (sjt_ifElse30) {
        sjs_vec3* sjt_functionParam279 = 0;
        sjs_vec3* sjt_parent155 = 0;

        sjt_parent155 = orig;
        sjt_functionParam279 = v0;
        sjf_vec3_subtract(sjt_parent155, sjt_functionParam279, &sjv_tvec);
    } else {
        sjs_vec3* sjt_functionParam280 = 0;
        float sjt_math2309;
        float sjt_math2310;
        sjs_vec3* sjt_parent156 = 0;

        sjt_math2309 = 0.0f;
        sjt_math2310 = sjv_det;
        sjv_det = sjt_math2309 - sjt_math2310;
        sjt_parent156 = v0;
        sjt_functionParam280 = orig;
        sjf_vec3_subtract(sjt_parent156, sjt_functionParam280, &sjv_tvec);
    }

    sjt_compare77 = sjv_det;
    sjt_compare78 = 0.0001f;
    sjt_ifElse31 = sjt_compare77 < sjt_compare78;
    if (sjt_ifElse31) {
        _return->_refCount = -1;
    } else {
        float sjt_compare79;
        float sjt_compare80;
        float sjt_compare81;
        float sjt_compare82;
        sjs_vec3* sjt_functionParam281 = 0;
        bool sjt_ifElse32;
        bool sjt_or1;
        bool sjt_or2;
        sjs_vec3* sjt_parent157 = 0;
        float sjv_u;

        sjt_parent157 = &sjv_tvec;
        sjt_functionParam281 = &sjv_pvec;
        sjf_vec3_dot(sjt_parent157, sjt_functionParam281, &sjv_u);
        sjt_compare79 = sjv_u;
        sjt_compare80 = 0.0f;
        sjt_or1 = sjt_compare79 < sjt_compare80;
        sjt_compare81 = sjv_u;
        sjt_compare82 = sjv_det;
        sjt_or2 = sjt_compare81 > sjt_compare82;
        sjt_ifElse32 = sjt_or1 || sjt_or2;
        if (sjt_ifElse32) {
            _return->_refCount = -1;
        } else {
            float sjt_compare83;
            float sjt_compare84;
            float sjt_compare85;
            float sjt_compare86;
            sjs_vec3* sjt_functionParam282 = 0;
            sjs_vec3* sjt_functionParam283 = 0;
            bool sjt_ifElse33;
            float sjt_math2311;
            float sjt_math2312;
            bool sjt_or3;
            bool sjt_or4;
            sjs_vec3* sjt_parent158 = 0;
            sjs_vec3* sjt_parent159 = 0;
            float sjv_v;

            sjt_parent158 = &sjv_tvec;
            sjt_functionParam282 = &sjv_edge1;
            sjf_vec3_cross(sjt_parent158, sjt_functionParam282, &sjv_qvec);
            sjt_parent159 = dir;
            sjt_functionParam283 = &sjv_qvec;
            sjf_vec3_dot(sjt_parent159, sjt_functionParam283, &sjv_v);
            sjt_compare83 = sjv_v;
            sjt_compare84 = 0.0f;
            sjt_or3 = sjt_compare83 < sjt_compare84;
            sjt_math2311 = sjv_u;
            sjt_math2312 = sjv_v;
            sjt_compare85 = sjt_math2311 + sjt_math2312;
            sjt_compare86 = sjv_det;
            sjt_or4 = sjt_compare85 > sjt_compare86;
            sjt_ifElse33 = sjt_or3 || sjt_or4;
            if (sjt_ifElse33) {
                _return->_refCount = -1;
            } else {
                sjs_vec3* sjt_functionParam284 = 0;
                float sjt_math2313;
                float sjt_math2314;
                float sjt_math2315;
                float sjt_math2316;
                float sjt_math2317;
                float sjt_math2318;
                float sjt_math2319;
                float sjt_math2320;
                sjs_vec3* sjt_parent160 = 0;
                float sjv_finvdet;
                float sjv_t;

                sjt_parent160 = &sjv_edge2;
                sjt_functionParam284 = &sjv_qvec;
                sjf_vec3_dot(sjt_parent160, sjt_functionParam284, &sjv_t);
                sjt_math2313 = 1.0f;
                sjt_math2314 = sjv_det;
                sjv_finvdet = sjt_math2313 / sjt_math2314;
                _return->_refCount = 1;
                sjt_math2315 = sjv_u;
                sjt_math2316 = sjv_finvdet;
                _return->x = sjt_math2315 * sjt_math2316;
                sjt_math2317 = sjv_v;
                sjt_math2318 = sjv_finvdet;
                _return->y = sjt_math2317 * sjt_math2318;
                sjt_math2319 = sjv_t;
                sjt_math2320 = sjv_finvdet;
                _return->z = sjt_math2319 * sjt_math2320;
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
    float sjt_compare87;
    float sjt_compare88;
    float sjt_compare89;
    float sjt_compare90;
    sjs_vec3* sjt_functionParam285 = 0;
    sjs_vec3* sjt_functionParam286 = 0;
    sjs_vec3* sjt_functionParam287 = 0;
    sjs_vec3* sjt_functionParam288 = 0;
    bool sjt_ifElse34;
    bool sjt_ifElse35;
    sjs_vec3* sjt_parent161 = 0;
    sjs_vec3* sjt_parent162 = 0;
    sjs_vec3* sjt_parent163 = 0;
    sjs_vec3* sjt_parent164 = 0;
    float sjv_det;
    sjs_vec3 sjv_edge1 = { -1 };
    sjs_vec3 sjv_edge2 = { -1 };
    sjs_vec3 sjv_pvec = { -1 };
    sjs_vec3 sjv_qvec = { -1 };
    sjs_vec3 sjv_tvec = { -1 };

    sjt_parent161 = v1;
    sjt_functionParam285 = v0;
    sjf_vec3_subtract(sjt_parent161, sjt_functionParam285, &sjv_edge1);
    sjt_parent162 = v2;
    sjt_functionParam286 = v0;
    sjf_vec3_subtract(sjt_parent162, sjt_functionParam286, &sjv_edge2);
    sjt_parent163 = dir;
    sjt_functionParam287 = &sjv_edge2;
    sjf_vec3_cross(sjt_parent163, sjt_functionParam287, &sjv_pvec);
    sjt_parent164 = &sjv_edge1;
    sjt_functionParam288 = &sjv_pvec;
    sjf_vec3_dot(sjt_parent164, sjt_functionParam288, &sjv_det);
    sjt_compare87 = sjv_det;
    sjt_compare88 = 0.0f;
    sjt_ifElse34 = sjt_compare87 > sjt_compare88;
    if (sjt_ifElse34) {
        sjs_vec3* sjt_functionParam289 = 0;
        sjs_vec3* sjt_parent165 = 0;

        sjt_parent165 = orig;
        sjt_functionParam289 = v0;
        sjf_vec3_subtract(sjt_parent165, sjt_functionParam289, &sjv_tvec);
    } else {
        sjs_vec3* sjt_functionParam290 = 0;
        float sjt_math2321;
        float sjt_math2322;
        sjs_vec3* sjt_parent166 = 0;

        sjt_math2321 = 0.0f;
        sjt_math2322 = sjv_det;
        sjv_det = sjt_math2321 - sjt_math2322;
        sjt_parent166 = v0;
        sjt_functionParam290 = orig;
        sjf_vec3_subtract(sjt_parent166, sjt_functionParam290, &sjv_tvec);
    }

    sjt_compare89 = sjv_det;
    sjt_compare90 = 0.0001f;
    sjt_ifElse35 = sjt_compare89 < sjt_compare90;
    if (sjt_ifElse35) {
        (*_return) = 0;
        if ((*_return) != 0) {
            (*_return)->_refCount++;
        }
    } else {
        float sjt_compare91;
        float sjt_compare92;
        float sjt_compare93;
        float sjt_compare94;
        sjs_vec3* sjt_functionParam291 = 0;
        bool sjt_ifElse36;
        bool sjt_or5;
        bool sjt_or6;
        sjs_vec3* sjt_parent167 = 0;
        float sjv_u;

        sjt_parent167 = &sjv_tvec;
        sjt_functionParam291 = &sjv_pvec;
        sjf_vec3_dot(sjt_parent167, sjt_functionParam291, &sjv_u);
        sjt_compare91 = sjv_u;
        sjt_compare92 = 0.0f;
        sjt_or5 = sjt_compare91 < sjt_compare92;
        sjt_compare93 = sjv_u;
        sjt_compare94 = sjv_det;
        sjt_or6 = sjt_compare93 > sjt_compare94;
        sjt_ifElse36 = sjt_or5 || sjt_or6;
        if (sjt_ifElse36) {
            (*_return) = 0;
            if ((*_return) != 0) {
                (*_return)->_refCount++;
            }
        } else {
            float sjt_compare95;
            float sjt_compare96;
            float sjt_compare97;
            float sjt_compare98;
            sjs_vec3* sjt_functionParam292 = 0;
            sjs_vec3* sjt_functionParam293 = 0;
            bool sjt_ifElse37;
            float sjt_math2323;
            float sjt_math2324;
            bool sjt_or7;
            bool sjt_or8;
            sjs_vec3* sjt_parent168 = 0;
            sjs_vec3* sjt_parent169 = 0;
            float sjv_v;

            sjt_parent168 = &sjv_tvec;
            sjt_functionParam292 = &sjv_edge1;
            sjf_vec3_cross(sjt_parent168, sjt_functionParam292, &sjv_qvec);
            sjt_parent169 = dir;
            sjt_functionParam293 = &sjv_qvec;
            sjf_vec3_dot(sjt_parent169, sjt_functionParam293, &sjv_v);
            sjt_compare95 = sjv_v;
            sjt_compare96 = 0.0f;
            sjt_or7 = sjt_compare95 < sjt_compare96;
            sjt_math2323 = sjv_u;
            sjt_math2324 = sjv_v;
            sjt_compare97 = sjt_math2323 + sjt_math2324;
            sjt_compare98 = sjv_det;
            sjt_or8 = sjt_compare97 > sjt_compare98;
            sjt_ifElse37 = sjt_or7 || sjt_or8;
            if (sjt_ifElse37) {
                (*_return) = 0;
                if ((*_return) != 0) {
                    (*_return)->_refCount++;
                }
            } else {
                sjs_vec3* sjt_functionParam294 = 0;
                float sjt_math2325;
                float sjt_math2326;
                float sjt_math2327;
                float sjt_math2328;
                float sjt_math2329;
                float sjt_math2330;
                float sjt_math2331;
                float sjt_math2332;
                sjs_vec3* sjt_parent170 = 0;
                sjs_vec3* sjt_value1 = 0;
                float sjv_finvdet;
                float sjv_t;

                sjt_parent170 = &sjv_edge2;
                sjt_functionParam294 = &sjv_qvec;
                sjf_vec3_dot(sjt_parent170, sjt_functionParam294, &sjv_t);
                sjt_math2325 = 1.0f;
                sjt_math2326 = sjv_det;
                sjv_finvdet = sjt_math2325 / sjt_math2326;
                sjt_value1 = (sjs_vec3*)malloc(sizeof(sjs_vec3));
                sjt_value1->_refCount = 1;
                sjt_math2327 = sjv_u;
                sjt_math2328 = sjv_finvdet;
                sjt_value1->x = sjt_math2327 * sjt_math2328;
                sjt_math2329 = sjv_v;
                sjt_math2330 = sjv_finvdet;
                sjt_value1->y = sjt_math2329 * sjt_math2330;
                sjt_math2331 = sjv_t;
                sjt_math2332 = sjv_finvdet;
                sjt_value1->z = sjt_math2331 * sjt_math2332;
                sjf_vec3_heap(sjt_value1);
                (*_return) = sjt_value1;
                if ((*_return) != 0) {
                    (*_return)->_refCount++;
                }

                sjt_value1->_refCount--;
                if (sjt_value1->_refCount <= 0) {
                    weakptr_release(sjt_value1);
                    sjf_vec3_destroy(sjt_value1);
                    free(sjt_value1);
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
    sjs_list_heap_iface_animation* sjt_dot1689 = 0;
    int32_t sjt_functionParam362;
    sjs_array_heap_iface_animation* sjt_parent208 = 0;

    sjt_dot1689 = _parent;
    sjt_parent208 = &(sjt_dot1689)->array;
    sjt_functionParam362 = index;
    sjf_array_heap_iface_animation_getat_heap(sjt_parent208, sjt_functionParam362, _return);
}

void sjf_list_heap_iface_animation_getcount(sjs_list_heap_iface_animation* _parent, int32_t* _return) {
    sjs_array_heap_iface_animation* sjt_dot1685 = 0;
    sjs_list_heap_iface_animation* sjt_dot1686 = 0;

    sjt_dot1686 = _parent;
    sjt_dot1685 = &(sjt_dot1686)->array;
    (*_return) = (sjt_dot1685)->count;
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

void sjf_list_heap_iface_model_getat_heap(sjs_list_heap_iface_model* _parent, int32_t index, sji_model* _return) {
    sjs_list_heap_iface_model* sjt_dot267 = 0;
    int32_t sjt_functionParam130;
    sjs_array_heap_iface_model* sjt_parent82 = 0;

    sjt_dot267 = _parent;
    sjt_parent82 = &(sjt_dot267)->array;
    sjt_functionParam130 = index;
    sjf_array_heap_iface_model_getat_heap(sjt_parent82, sjt_functionParam130, _return);
}

void sjf_list_heap_iface_model_getcount(sjs_list_heap_iface_model* _parent, int32_t* _return) {
    sjs_array_heap_iface_model* sjt_dot265 = 0;
    sjs_list_heap_iface_model* sjt_dot266 = 0;

    sjt_dot266 = _parent;
    sjt_dot265 = &(sjt_dot266)->array;
    (*_return) = (sjt_dot265)->count;
}

void sjf_list_heap_iface_model_heap(sjs_list_heap_iface_model* _this) {
}

void sjf_list_heap_iface_model_sortcb(sjs_list_heap_iface_model* _parent, cb_heap_iface_model_heap_iface_model_i32 cb) {
    sjs_list_heap_iface_model* sjt_dot264 = 0;
    cb_heap_iface_model_heap_iface_model_i32 sjt_functionParam126;
    sjs_array_heap_iface_model* sjt_parent77 = 0;

    sjt_dot264 = _parent;
    sjt_parent77 = &(sjt_dot264)->array;
    sjt_functionParam126 = cb;
    sjf_array_heap_iface_model_sortcb(sjt_parent77, sjt_functionParam126);
}

void sjf_list_local_iface_model(sjs_list_local_iface_model* _this) {
}

void sjf_list_local_iface_model_add(sjs_list_local_iface_model* _parent, sji_model item) {
    int32_t sjt_compare65;
    int32_t sjt_compare66;
    sjs_array_local_iface_model* sjt_dot664 = 0;
    sjs_list_local_iface_model* sjt_dot665 = 0;
    sjs_array_local_iface_model* sjt_dot666 = 0;
    sjs_list_local_iface_model* sjt_dot667 = 0;
    sjs_list_local_iface_model* sjt_dot674 = 0;
    sjs_array_local_iface_model* sjt_dot675 = 0;
    sjs_list_local_iface_model* sjt_dot676 = 0;
    int32_t sjt_functionParam219;
    sji_model sjt_functionParam220 = { 0 };
    bool sjt_ifElse25;
    sjs_array_local_iface_model* sjt_parent120 = 0;

    sjt_dot665 = _parent;
    sjt_dot664 = &(sjt_dot665)->array;
    sjt_compare65 = (sjt_dot664)->count;
    sjt_dot667 = _parent;
    sjt_dot666 = &(sjt_dot667)->array;
    sjt_compare66 = (sjt_dot666)->datasize;
    sjt_ifElse25 = sjt_compare65 >= sjt_compare66;
    if (sjt_ifElse25) {
        sjs_list_local_iface_model* sjt_dot668 = 0;
        sjs_list_local_iface_model* sjt_dot671 = 0;
        sjs_array_local_iface_model* sjt_dot672 = 0;
        sjs_list_local_iface_model* sjt_dot673 = 0;
        int32_t sjt_functionParam216;
        int32_t sjt_functionParam217;
        int32_t sjt_functionParam218;
        int32_t sjt_math905;
        int32_t sjt_math906;
        sjs_array_local_iface_model* sjt_parent119 = 0;

        sjt_dot668 = _parent;
        sjt_dot671 = _parent;
        sjt_parent119 = &(sjt_dot671)->array;
        sjt_functionParam217 = 10;
        sjt_dot673 = _parent;
        sjt_dot672 = &(sjt_dot673)->array;
        sjt_math905 = (sjt_dot672)->datasize;
        sjt_math906 = 2;
        sjt_functionParam218 = sjt_math905 * sjt_math906;
        sjf_i32_max(sjt_functionParam217, sjt_functionParam218, &sjt_functionParam216);
        sjf_array_local_iface_model_grow(sjt_parent119, sjt_functionParam216, &sjt_dot668->array);
    }

    sjt_dot674 = _parent;
    sjt_parent120 = &(sjt_dot674)->array;
    sjt_dot676 = _parent;
    sjt_dot675 = &(sjt_dot676)->array;
    sjt_functionParam219 = (sjt_dot675)->count;
    sjt_functionParam220 = item;
    sjf_array_local_iface_model_initat(sjt_parent120, sjt_functionParam219, sjt_functionParam220);
}

void sjf_list_local_iface_model_copy(sjs_list_local_iface_model* _this, sjs_list_local_iface_model* _from) {
    _this->array._refCount = 1;
    sjf_array_local_iface_model_copy(&_this->array, &_from->array);
}

void sjf_list_local_iface_model_destroy(sjs_list_local_iface_model* _this) {
}

void sjf_list_local_iface_model_heap(sjs_list_local_iface_model* _this) {
}

void sjf_list_rect(sjs_list_rect* _this) {
}

void sjf_list_rect_add(sjs_list_rect* _parent, sjs_rect* item) {
    int32_t sjt_compare19;
    int32_t sjt_compare20;
    sjs_array_rect* sjt_dot216 = 0;
    sjs_list_rect* sjt_dot217 = 0;
    sjs_array_rect* sjt_dot218 = 0;
    sjs_list_rect* sjt_dot219 = 0;
    sjs_list_rect* sjt_dot226 = 0;
    sjs_array_rect* sjt_dot227 = 0;
    sjs_list_rect* sjt_dot228 = 0;
    int32_t sjt_functionParam50;
    sjs_rect* sjt_functionParam51 = 0;
    bool sjt_ifElse7;
    sjs_array_rect* sjt_parent45 = 0;

    sjt_dot217 = _parent;
    sjt_dot216 = &(sjt_dot217)->array;
    sjt_compare19 = (sjt_dot216)->count;
    sjt_dot219 = _parent;
    sjt_dot218 = &(sjt_dot219)->array;
    sjt_compare20 = (sjt_dot218)->datasize;
    sjt_ifElse7 = sjt_compare19 >= sjt_compare20;
    if (sjt_ifElse7) {
        sjs_list_rect* sjt_dot220 = 0;
        sjs_list_rect* sjt_dot223 = 0;
        sjs_array_rect* sjt_dot224 = 0;
        sjs_list_rect* sjt_dot225 = 0;
        int32_t sjt_functionParam47;
        int32_t sjt_functionParam48;
        int32_t sjt_functionParam49;
        int32_t sjt_math209;
        int32_t sjt_math210;
        sjs_array_rect* sjt_parent44 = 0;

        sjt_dot220 = _parent;
        sjt_dot223 = _parent;
        sjt_parent44 = &(sjt_dot223)->array;
        sjt_functionParam48 = 10;
        sjt_dot225 = _parent;
        sjt_dot224 = &(sjt_dot225)->array;
        sjt_math209 = (sjt_dot224)->datasize;
        sjt_math210 = 2;
        sjt_functionParam49 = sjt_math209 * sjt_math210;
        sjf_i32_max(sjt_functionParam48, sjt_functionParam49, &sjt_functionParam47);
        sjf_array_rect_grow(sjt_parent44, sjt_functionParam47, &sjt_dot220->array);
    }

    sjt_dot226 = _parent;
    sjt_parent45 = &(sjt_dot226)->array;
    sjt_dot228 = _parent;
    sjt_dot227 = &(sjt_dot228)->array;
    sjt_functionParam50 = (sjt_dot227)->count;
    sjt_functionParam51 = item;
    sjf_array_rect_initat(sjt_parent45, sjt_functionParam50, sjt_functionParam51);
}

void sjf_list_rect_copy(sjs_list_rect* _this, sjs_list_rect* _from) {
    _this->array._refCount = 1;
    sjf_array_rect_copy(&_this->array, &_from->array);
}

void sjf_list_rect_destroy(sjs_list_rect* _this) {
}

void sjf_list_rect_getat(sjs_list_rect* _parent, int32_t index, sjs_rect* _return) {
    sjs_list_rect* sjt_dot274 = 0;
    int32_t sjt_functionParam132;
    sjs_array_rect* sjt_parent86 = 0;

    sjt_dot274 = _parent;
    sjt_parent86 = &(sjt_dot274)->array;
    sjt_functionParam132 = index;
    sjf_array_rect_getat(sjt_parent86, sjt_functionParam132, _return);
}

void sjf_list_rect_getcount(sjs_list_rect* _parent, int32_t* _return) {
    sjs_array_rect* sjt_dot275 = 0;
    sjs_list_rect* sjt_dot276 = 0;

    sjt_dot276 = _parent;
    sjt_dot275 = &(sjt_dot276)->array;
    (*_return) = (sjt_dot275)->count;
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

void sjf_list_u32_add(sjs_list_u32* _parent, uint32_t item) {
    int32_t sjt_compare53;
    int32_t sjt_compare54;
    sjs_array_u32* sjt_dot282 = 0;
    sjs_list_u32* sjt_dot283 = 0;
    sjs_array_u32* sjt_dot284 = 0;
    sjs_list_u32* sjt_dot285 = 0;
    sjs_list_u32* sjt_dot292 = 0;
    sjs_array_u32* sjt_dot293 = 0;
    sjs_list_u32* sjt_dot294 = 0;
    int32_t sjt_functionParam152;
    uint32_t sjt_functionParam153;
    bool sjt_ifElse19;
    sjs_array_u32* sjt_parent99 = 0;

    sjt_dot283 = _parent;
    sjt_dot282 = &(sjt_dot283)->array;
    sjt_compare53 = (sjt_dot282)->count;
    sjt_dot285 = _parent;
    sjt_dot284 = &(sjt_dot285)->array;
    sjt_compare54 = (sjt_dot284)->datasize;
    sjt_ifElse19 = sjt_compare53 >= sjt_compare54;
    if (sjt_ifElse19) {
        sjs_list_u32* sjt_dot286 = 0;
        sjs_list_u32* sjt_dot289 = 0;
        sjs_array_u32* sjt_dot290 = 0;
        sjs_list_u32* sjt_dot291 = 0;
        int32_t sjt_functionParam149;
        int32_t sjt_functionParam150;
        int32_t sjt_functionParam151;
        int32_t sjt_math259;
        int32_t sjt_math260;
        sjs_array_u32* sjt_parent98 = 0;

        sjt_dot286 = _parent;
        sjt_dot289 = _parent;
        sjt_parent98 = &(sjt_dot289)->array;
        sjt_functionParam150 = 10;
        sjt_dot291 = _parent;
        sjt_dot290 = &(sjt_dot291)->array;
        sjt_math259 = (sjt_dot290)->datasize;
        sjt_math260 = 2;
        sjt_functionParam151 = sjt_math259 * sjt_math260;
        sjf_i32_max(sjt_functionParam150, sjt_functionParam151, &sjt_functionParam149);
        sjf_array_u32_grow(sjt_parent98, sjt_functionParam149, &sjt_dot286->array);
    }

    sjt_dot292 = _parent;
    sjt_parent99 = &(sjt_dot292)->array;
    sjt_dot294 = _parent;
    sjt_dot293 = &(sjt_dot294)->array;
    sjt_functionParam152 = (sjt_dot293)->count;
    sjt_functionParam153 = item;
    sjf_array_u32_initat(sjt_parent99, sjt_functionParam152, sjt_functionParam153);
}

void sjf_list_u32_copy(sjs_list_u32* _this, sjs_list_u32* _from) {
    _this->array._refCount = 1;
    sjf_array_u32_copy(&_this->array, &_from->array);
}

void sjf_list_u32_destroy(sjs_list_u32* _this) {
}

void sjf_list_u32_getat(sjs_list_u32* _parent, int32_t index, uint32_t* _return) {
    sjs_list_u32* sjt_dot296 = 0;
    int32_t sjt_functionParam186;
    sjs_array_u32* sjt_parent101 = 0;

    sjt_dot296 = _parent;
    sjt_parent101 = &(sjt_dot296)->array;
    sjt_functionParam186 = index;
    sjf_array_u32_getat(sjt_parent101, sjt_functionParam186, _return);
}

void sjf_list_u32_getcount(sjs_list_u32* _parent, int32_t* _return) {
    sjs_array_u32* sjt_dot297 = 0;
    sjs_list_u32* sjt_dot298 = 0;

    sjt_dot298 = _parent;
    sjt_dot297 = &(sjt_dot298)->array;
    (*_return) = (sjt_dot297)->count;
}

void sjf_list_u32_heap(sjs_list_u32* _this) {
}

void sjf_list_u32_removeat(sjs_list_u32* _parent, int32_t index) {
    if (index < 0 || index >= _parent->array.count) {
        halt("removeAt: out of bounds %d:%d\n", index, _parent->array.count);
    }
    uint32_t* p = (uint32_t*)_parent->array.data;
    if (index != _parent->array.count - 1) {
        memcpy(p + index, p + index + 1, (_parent->array.count - index - 1) * sizeof(uint32_t));
    }
    _parent->array.count--;
}

void sjf_mainloop(void) {
    bool result13;
    sjs_size* sjt_dot1692 = 0;
    sjs_size* sjt_dot1693 = 0;
    int32_t sjt_functionParam365;
    sjs_size* sjt_functionParam366 = 0;
    sjs_rect* sjt_functionParam367 = 0;
    bool sjt_ifElse62;
    sjs_scene2d* sjt_interfaceParam21 = 0;
    bool sjt_isEmpty22;
    int32_option sjt_isEmpty23;
    bool sjt_not6;
    sjs_anon1* sjt_parent212 = 0;
    sjs_windowrenderer* sjt_parent213 = 0;
    sjs_scene2d* sjt_parent214 = 0;
    sjs_scene2d* sjt_parent215 = 0;
    sjs_rect* sjt_parent216 = 0;
    sji_element sjt_parent218 = { 0 };
    sjs_scene2d* sjt_parent219 = 0;
    sjs_windowrenderer* sjt_parent220 = 0;
    int32_option sjv_mouseeventtype;
    sjs_rect sjv_rect = { -1 };
    bool sjv_shouldcontinue;
    sjs_size sjv_size = { -1 };
    int32_t sjv_ticks;
    int32_t sjv_x;
    int32_t sjv_y;

    sjv_ticks = 0;
    sjv_ticks = SDL_GetTicks();
    sjt_parent212 = &sjv_animator;
    sjt_functionParam365 = sjv_ticks;
    sjf_anon1_nextframe(sjt_parent212, sjt_functionParam365);
    sjt_parent213 = &sjv_rootwindowrenderer;
    sjf_windowrenderer_getsize(sjt_parent213, &sjv_size);
    sjt_parent214 = &sjv_rootscene;
    sjt_functionParam366 = &sjv_size;
    sjf_scene2d_setsize(sjt_parent214, sjt_functionParam366);
    sjt_parent215 = &sjv_rootscene;
    sjf_scene2d_start(sjt_parent215);
    sjv_rect._refCount = 1;
    sjv_rect.x = 0;
    sjv_rect.y = 0;
    sjt_dot1692 = &sjv_size;
    sjv_rect.w = (sjt_dot1692)->w;
    sjt_dot1693 = &sjv_size;
    sjv_rect.h = (sjt_dot1693)->h;
    sjf_rect(&sjv_rect);
    sjt_parent216 = &sjv_looplastrect;
    sjt_functionParam367 = &sjv_rect;
    sjf_rect_isequal(sjt_parent216, sjt_functionParam367, &sjt_not6);
    result13 = !sjt_not6;
    sjt_ifElse62 = result13;
    if (sjt_ifElse62) {
        sjs_rect* sjt_interfaceParam20 = 0;
        sji_element sjt_parent217 = { 0 };

        sjt_parent217 = sjv_root;
        sjt_interfaceParam20 = &sjv_rect;
        sjt_parent217._vtbl->setrect(sjt_parent217._parent, sjt_interfaceParam20);
    }

    sjt_parent218 = sjv_root;
    sjt_interfaceParam21 = &sjv_rootscene;
    sjt_parent218._vtbl->render(sjt_parent218._parent, sjt_interfaceParam21);
    sjt_parent219 = &sjv_rootscene;
    sjf_scene2d_end(sjt_parent219);
    sjt_parent220 = &sjv_rootwindowrenderer;
    sjf_windowrenderer_present(sjt_parent220);
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
    sjt_isEmpty23 = sjv_mouseeventtype;
    sjt_isEmpty22 = sjt_isEmpty23.isvalid;
    if (sjt_isEmpty22) {
        int32_t ifValue3;
        int32_option sjt_getValue2;
        bool sjt_isEmpty24;
        sji_element sjt_isEmpty25 = { 0 };

        sjt_getValue2 = sjv_mouseeventtype;
        ifValue3 = sjt_getValue2.value;
        sjt_isEmpty25 = sjv_mouse_captureelement;
        sjt_isEmpty24 = (sjt_isEmpty25._parent != 0);
        if (sjt_isEmpty24) {
            sji_element ifValue4 = { 0 };
            sjs_mouseevent sjt_call68 = { -1 };
            sjs_mouseevent* sjt_interfaceParam22 = 0;
            sji_element sjt_parent221 = { 0 };

            ifValue4 = sjv_mouse_captureelement;
            if (ifValue4._parent != 0) {
                ifValue4._parent->_refCount++;
            }

            sjt_parent221 = ifValue4;
            sjt_call68._refCount = 1;
            sjt_call68.type = ifValue3;
            sjt_call68.point._refCount = 1;
            sjt_call68.point.x = sjv_x;
            sjt_call68.point.y = sjv_y;
            sjf_point(&sjt_call68.point);
            sjt_call68.iscaptured = true;
            sjf_mouseevent(&sjt_call68);
            sjt_interfaceParam22 = &sjt_call68;
            sjt_parent221._vtbl->firemouseevent(sjt_parent221._parent, sjt_interfaceParam22, &sjv_shouldcontinue);

            if (ifValue4._parent != 0) {
                ifValue4._parent->_refCount--;
                if (ifValue4._parent->_refCount <= 0) {
                    ifValue4._vtbl->destroy(ifValue4._parent);
                    free(ifValue4._parent);
                }
            }
            if (sjt_call68._refCount == 1) { sjf_mouseevent_destroy(&sjt_call68); }
        } else {
            sjs_mouseevent sjt_call69 = { -1 };
            sjs_mouseevent* sjt_interfaceParam23 = 0;
            sji_element sjt_parent222 = { 0 };

            sjt_parent222 = sjv_root;
            sjt_call69._refCount = 1;
            sjt_call69.type = ifValue3;
            sjt_call69.point._refCount = 1;
            sjt_call69.point.x = sjv_x;
            sjt_call69.point.y = sjv_y;
            sjf_point(&sjt_call69.point);
            sjt_call69.iscaptured = false;
            sjf_mouseevent(&sjt_call69);
            sjt_interfaceParam23 = &sjt_call69;
            sjt_parent222._vtbl->firemouseevent(sjt_parent222._parent, sjt_interfaceParam23, &sjv_shouldcontinue);

            if (sjt_call69._refCount == 1) { sjf_mouseevent_destroy(&sjt_call69); }
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

    sjt_dot1049 = _parent;
    sjt_math1567 = (sjt_dot1049)->m03;
    sjt_dot1050 = _parent;
    sjt_math1568 = (sjt_dot1050)->m12;
    sjt_math1565 = sjt_math1567 * sjt_math1568;
    sjt_dot1051 = _parent;
    sjt_math1566 = (sjt_dot1051)->m21;
    sjt_math1563 = sjt_math1565 * sjt_math1566;
    sjt_dot1052 = _parent;
    sjt_math1564 = (sjt_dot1052)->m30;
    sjt_math1561 = sjt_math1563 * sjt_math1564;
    sjt_dot1053 = _parent;
    sjt_math1573 = (sjt_dot1053)->m02;
    sjt_dot1054 = _parent;
    sjt_math1574 = (sjt_dot1054)->m13;
    sjt_math1571 = sjt_math1573 * sjt_math1574;
    sjt_dot1055 = _parent;
    sjt_math1572 = (sjt_dot1055)->m21;
    sjt_math1569 = sjt_math1571 * sjt_math1572;
    sjt_dot1056 = _parent;
    sjt_math1570 = (sjt_dot1056)->m30;
    sjt_math1562 = sjt_math1569 * sjt_math1570;
    sjt_math1559 = sjt_math1561 - sjt_math1562;
    sjt_dot1057 = _parent;
    sjt_math1579 = (sjt_dot1057)->m03;
    sjt_dot1058 = _parent;
    sjt_math1580 = (sjt_dot1058)->m11;
    sjt_math1577 = sjt_math1579 * sjt_math1580;
    sjt_dot1059 = _parent;
    sjt_math1578 = (sjt_dot1059)->m22;
    sjt_math1575 = sjt_math1577 * sjt_math1578;
    sjt_dot1060 = _parent;
    sjt_math1576 = (sjt_dot1060)->m30;
    sjt_math1560 = sjt_math1575 * sjt_math1576;
    sjt_math1557 = sjt_math1559 - sjt_math1560;
    sjt_dot1061 = _parent;
    sjt_math1585 = (sjt_dot1061)->m01;
    sjt_dot1062 = _parent;
    sjt_math1586 = (sjt_dot1062)->m13;
    sjt_math1583 = sjt_math1585 * sjt_math1586;
    sjt_dot1063 = _parent;
    sjt_math1584 = (sjt_dot1063)->m22;
    sjt_math1581 = sjt_math1583 * sjt_math1584;
    sjt_dot1064 = _parent;
    sjt_math1582 = (sjt_dot1064)->m30;
    sjt_math1558 = sjt_math1581 * sjt_math1582;
    sjt_math1555 = sjt_math1557 + sjt_math1558;
    sjt_dot1065 = _parent;
    sjt_math1591 = (sjt_dot1065)->m02;
    sjt_dot1066 = _parent;
    sjt_math1592 = (sjt_dot1066)->m11;
    sjt_math1589 = sjt_math1591 * sjt_math1592;
    sjt_dot1067 = _parent;
    sjt_math1590 = (sjt_dot1067)->m23;
    sjt_math1587 = sjt_math1589 * sjt_math1590;
    sjt_dot1068 = _parent;
    sjt_math1588 = (sjt_dot1068)->m30;
    sjt_math1556 = sjt_math1587 * sjt_math1588;
    sjt_math1553 = sjt_math1555 + sjt_math1556;
    sjt_dot1069 = _parent;
    sjt_math1597 = (sjt_dot1069)->m01;
    sjt_dot1070 = _parent;
    sjt_math1598 = (sjt_dot1070)->m12;
    sjt_math1595 = sjt_math1597 * sjt_math1598;
    sjt_dot1071 = _parent;
    sjt_math1596 = (sjt_dot1071)->m23;
    sjt_math1593 = sjt_math1595 * sjt_math1596;
    sjt_dot1072 = _parent;
    sjt_math1594 = (sjt_dot1072)->m30;
    sjt_math1554 = sjt_math1593 * sjt_math1594;
    sjt_math1551 = sjt_math1553 - sjt_math1554;
    sjt_dot1073 = _parent;
    sjt_math1603 = (sjt_dot1073)->m03;
    sjt_dot1074 = _parent;
    sjt_math1604 = (sjt_dot1074)->m12;
    sjt_math1601 = sjt_math1603 * sjt_math1604;
    sjt_dot1075 = _parent;
    sjt_math1602 = (sjt_dot1075)->m20;
    sjt_math1599 = sjt_math1601 * sjt_math1602;
    sjt_dot1076 = _parent;
    sjt_math1600 = (sjt_dot1076)->m31;
    sjt_math1552 = sjt_math1599 * sjt_math1600;
    sjt_math1549 = sjt_math1551 - sjt_math1552;
    sjt_dot1077 = _parent;
    sjt_math1609 = (sjt_dot1077)->m02;
    sjt_dot1078 = _parent;
    sjt_math1610 = (sjt_dot1078)->m13;
    sjt_math1607 = sjt_math1609 * sjt_math1610;
    sjt_dot1079 = _parent;
    sjt_math1608 = (sjt_dot1079)->m20;
    sjt_math1605 = sjt_math1607 * sjt_math1608;
    sjt_dot1080 = _parent;
    sjt_math1606 = (sjt_dot1080)->m31;
    sjt_math1550 = sjt_math1605 * sjt_math1606;
    sjt_math1547 = sjt_math1549 + sjt_math1550;
    sjt_dot1081 = _parent;
    sjt_math1615 = (sjt_dot1081)->m03;
    sjt_dot1082 = _parent;
    sjt_math1616 = (sjt_dot1082)->m10;
    sjt_math1613 = sjt_math1615 * sjt_math1616;
    sjt_dot1083 = _parent;
    sjt_math1614 = (sjt_dot1083)->m22;
    sjt_math1611 = sjt_math1613 * sjt_math1614;
    sjt_dot1084 = _parent;
    sjt_math1612 = (sjt_dot1084)->m31;
    sjt_math1548 = sjt_math1611 * sjt_math1612;
    sjt_math1545 = sjt_math1547 + sjt_math1548;
    sjt_dot1085 = _parent;
    sjt_math1621 = (sjt_dot1085)->m00;
    sjt_dot1086 = _parent;
    sjt_math1622 = (sjt_dot1086)->m13;
    sjt_math1619 = sjt_math1621 * sjt_math1622;
    sjt_dot1087 = _parent;
    sjt_math1620 = (sjt_dot1087)->m22;
    sjt_math1617 = sjt_math1619 * sjt_math1620;
    sjt_dot1088 = _parent;
    sjt_math1618 = (sjt_dot1088)->m31;
    sjt_math1546 = sjt_math1617 * sjt_math1618;
    sjt_math1543 = sjt_math1545 - sjt_math1546;
    sjt_dot1089 = _parent;
    sjt_math1627 = (sjt_dot1089)->m02;
    sjt_dot1090 = _parent;
    sjt_math1628 = (sjt_dot1090)->m10;
    sjt_math1625 = sjt_math1627 * sjt_math1628;
    sjt_dot1091 = _parent;
    sjt_math1626 = (sjt_dot1091)->m23;
    sjt_math1623 = sjt_math1625 * sjt_math1626;
    sjt_dot1092 = _parent;
    sjt_math1624 = (sjt_dot1092)->m31;
    sjt_math1544 = sjt_math1623 * sjt_math1624;
    sjt_math1541 = sjt_math1543 - sjt_math1544;
    sjt_dot1093 = _parent;
    sjt_math1633 = (sjt_dot1093)->m00;
    sjt_dot1094 = _parent;
    sjt_math1634 = (sjt_dot1094)->m12;
    sjt_math1631 = sjt_math1633 * sjt_math1634;
    sjt_dot1095 = _parent;
    sjt_math1632 = (sjt_dot1095)->m23;
    sjt_math1629 = sjt_math1631 * sjt_math1632;
    sjt_dot1096 = _parent;
    sjt_math1630 = (sjt_dot1096)->m31;
    sjt_math1542 = sjt_math1629 * sjt_math1630;
    sjt_math1539 = sjt_math1541 + sjt_math1542;
    sjt_dot1097 = _parent;
    sjt_math1639 = (sjt_dot1097)->m03;
    sjt_dot1098 = _parent;
    sjt_math1640 = (sjt_dot1098)->m11;
    sjt_math1637 = sjt_math1639 * sjt_math1640;
    sjt_dot1099 = _parent;
    sjt_math1638 = (sjt_dot1099)->m20;
    sjt_math1635 = sjt_math1637 * sjt_math1638;
    sjt_dot1100 = _parent;
    sjt_math1636 = (sjt_dot1100)->m32;
    sjt_math1540 = sjt_math1635 * sjt_math1636;
    sjt_math1537 = sjt_math1539 + sjt_math1540;
    sjt_dot1101 = _parent;
    sjt_math1645 = (sjt_dot1101)->m01;
    sjt_dot1102 = _parent;
    sjt_math1646 = (sjt_dot1102)->m13;
    sjt_math1643 = sjt_math1645 * sjt_math1646;
    sjt_dot1103 = _parent;
    sjt_math1644 = (sjt_dot1103)->m20;
    sjt_math1641 = sjt_math1643 * sjt_math1644;
    sjt_dot1104 = _parent;
    sjt_math1642 = (sjt_dot1104)->m32;
    sjt_math1538 = sjt_math1641 * sjt_math1642;
    sjt_math1535 = sjt_math1537 - sjt_math1538;
    sjt_dot1105 = _parent;
    sjt_math1651 = (sjt_dot1105)->m03;
    sjt_dot1106 = _parent;
    sjt_math1652 = (sjt_dot1106)->m10;
    sjt_math1649 = sjt_math1651 * sjt_math1652;
    sjt_dot1107 = _parent;
    sjt_math1650 = (sjt_dot1107)->m21;
    sjt_math1647 = sjt_math1649 * sjt_math1650;
    sjt_dot1108 = _parent;
    sjt_math1648 = (sjt_dot1108)->m32;
    sjt_math1536 = sjt_math1647 * sjt_math1648;
    sjt_math1533 = sjt_math1535 - sjt_math1536;
    sjt_dot1109 = _parent;
    sjt_math1657 = (sjt_dot1109)->m00;
    sjt_dot1110 = _parent;
    sjt_math1658 = (sjt_dot1110)->m13;
    sjt_math1655 = sjt_math1657 * sjt_math1658;
    sjt_dot1111 = _parent;
    sjt_math1656 = (sjt_dot1111)->m21;
    sjt_math1653 = sjt_math1655 * sjt_math1656;
    sjt_dot1112 = _parent;
    sjt_math1654 = (sjt_dot1112)->m32;
    sjt_math1534 = sjt_math1653 * sjt_math1654;
    sjt_math1531 = sjt_math1533 + sjt_math1534;
    sjt_dot1113 = _parent;
    sjt_math1663 = (sjt_dot1113)->m01;
    sjt_dot1114 = _parent;
    sjt_math1664 = (sjt_dot1114)->m10;
    sjt_math1661 = sjt_math1663 * sjt_math1664;
    sjt_dot1115 = _parent;
    sjt_math1662 = (sjt_dot1115)->m23;
    sjt_math1659 = sjt_math1661 * sjt_math1662;
    sjt_dot1116 = _parent;
    sjt_math1660 = (sjt_dot1116)->m32;
    sjt_math1532 = sjt_math1659 * sjt_math1660;
    sjt_math1529 = sjt_math1531 + sjt_math1532;
    sjt_dot1117 = _parent;
    sjt_math1669 = (sjt_dot1117)->m00;
    sjt_dot1118 = _parent;
    sjt_math1670 = (sjt_dot1118)->m11;
    sjt_math1667 = sjt_math1669 * sjt_math1670;
    sjt_dot1119 = _parent;
    sjt_math1668 = (sjt_dot1119)->m23;
    sjt_math1665 = sjt_math1667 * sjt_math1668;
    sjt_dot1120 = _parent;
    sjt_math1666 = (sjt_dot1120)->m32;
    sjt_math1530 = sjt_math1665 * sjt_math1666;
    sjt_math1527 = sjt_math1529 - sjt_math1530;
    sjt_dot1121 = _parent;
    sjt_math1675 = (sjt_dot1121)->m02;
    sjt_dot1122 = _parent;
    sjt_math1676 = (sjt_dot1122)->m11;
    sjt_math1673 = sjt_math1675 * sjt_math1676;
    sjt_dot1123 = _parent;
    sjt_math1674 = (sjt_dot1123)->m20;
    sjt_math1671 = sjt_math1673 * sjt_math1674;
    sjt_dot1124 = _parent;
    sjt_math1672 = (sjt_dot1124)->m33;
    sjt_math1528 = sjt_math1671 * sjt_math1672;
    sjt_math1525 = sjt_math1527 - sjt_math1528;
    sjt_dot1125 = _parent;
    sjt_math1681 = (sjt_dot1125)->m01;
    sjt_dot1126 = _parent;
    sjt_math1682 = (sjt_dot1126)->m12;
    sjt_math1679 = sjt_math1681 * sjt_math1682;
    sjt_dot1127 = _parent;
    sjt_math1680 = (sjt_dot1127)->m20;
    sjt_math1677 = sjt_math1679 * sjt_math1680;
    sjt_dot1128 = _parent;
    sjt_math1678 = (sjt_dot1128)->m33;
    sjt_math1526 = sjt_math1677 * sjt_math1678;
    sjt_math1523 = sjt_math1525 + sjt_math1526;
    sjt_dot1129 = _parent;
    sjt_math1687 = (sjt_dot1129)->m02;
    sjt_dot1130 = _parent;
    sjt_math1688 = (sjt_dot1130)->m10;
    sjt_math1685 = sjt_math1687 * sjt_math1688;
    sjt_dot1131 = _parent;
    sjt_math1686 = (sjt_dot1131)->m21;
    sjt_math1683 = sjt_math1685 * sjt_math1686;
    sjt_dot1132 = _parent;
    sjt_math1684 = (sjt_dot1132)->m33;
    sjt_math1524 = sjt_math1683 * sjt_math1684;
    sjt_math1521 = sjt_math1523 + sjt_math1524;
    sjt_dot1133 = _parent;
    sjt_math1693 = (sjt_dot1133)->m00;
    sjt_dot1134 = _parent;
    sjt_math1694 = (sjt_dot1134)->m12;
    sjt_math1691 = sjt_math1693 * sjt_math1694;
    sjt_dot1135 = _parent;
    sjt_math1692 = (sjt_dot1135)->m21;
    sjt_math1689 = sjt_math1691 * sjt_math1692;
    sjt_dot1136 = _parent;
    sjt_math1690 = (sjt_dot1136)->m33;
    sjt_math1522 = sjt_math1689 * sjt_math1690;
    sjt_math1519 = sjt_math1521 - sjt_math1522;
    sjt_dot1137 = _parent;
    sjt_math1699 = (sjt_dot1137)->m01;
    sjt_dot1138 = _parent;
    sjt_math1700 = (sjt_dot1138)->m10;
    sjt_math1697 = sjt_math1699 * sjt_math1700;
    sjt_dot1139 = _parent;
    sjt_math1698 = (sjt_dot1139)->m22;
    sjt_math1695 = sjt_math1697 * sjt_math1698;
    sjt_dot1140 = _parent;
    sjt_math1696 = (sjt_dot1140)->m33;
    sjt_math1520 = sjt_math1695 * sjt_math1696;
    sjt_math1517 = sjt_math1519 - sjt_math1520;
    sjt_dot1141 = _parent;
    sjt_math1705 = (sjt_dot1141)->m00;
    sjt_dot1142 = _parent;
    sjt_math1706 = (sjt_dot1142)->m11;
    sjt_math1703 = sjt_math1705 * sjt_math1706;
    sjt_dot1143 = _parent;
    sjt_math1704 = (sjt_dot1143)->m22;
    sjt_math1701 = sjt_math1703 * sjt_math1704;
    sjt_dot1144 = _parent;
    sjt_math1702 = (sjt_dot1144)->m33;
    sjt_math1518 = sjt_math1701 * sjt_math1702;
    (*_return) = sjt_math1517 + sjt_math1518;
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
    float sjt_functionParam232;
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
    float sjt_math1515;
    float sjt_math1516;
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
    sjs_mat4* sjt_parent129 = 0;
    sjs_mat4 sjv_t = { -1 };

    sjv_t._refCount = 1;
    sjt_dot729 = _parent;
    sjt_math919 = (sjt_dot729)->m12;
    sjt_dot730 = _parent;
    sjt_math920 = (sjt_dot730)->m23;
    sjt_math917 = sjt_math919 * sjt_math920;
    sjt_dot731 = _parent;
    sjt_math918 = (sjt_dot731)->m31;
    sjt_math915 = sjt_math917 * sjt_math918;
    sjt_dot732 = _parent;
    sjt_math923 = (sjt_dot732)->m13;
    sjt_dot733 = _parent;
    sjt_math924 = (sjt_dot733)->m22;
    sjt_math921 = sjt_math923 * sjt_math924;
    sjt_dot734 = _parent;
    sjt_math922 = (sjt_dot734)->m31;
    sjt_math916 = sjt_math921 * sjt_math922;
    sjt_math913 = sjt_math915 - sjt_math916;
    sjt_dot735 = _parent;
    sjt_math927 = (sjt_dot735)->m13;
    sjt_dot736 = _parent;
    sjt_math928 = (sjt_dot736)->m21;
    sjt_math925 = sjt_math927 * sjt_math928;
    sjt_dot737 = _parent;
    sjt_math926 = (sjt_dot737)->m32;
    sjt_math914 = sjt_math925 * sjt_math926;
    sjt_math911 = sjt_math913 + sjt_math914;
    sjt_dot738 = _parent;
    sjt_math931 = (sjt_dot738)->m11;
    sjt_dot739 = _parent;
    sjt_math932 = (sjt_dot739)->m23;
    sjt_math929 = sjt_math931 * sjt_math932;
    sjt_dot740 = _parent;
    sjt_math930 = (sjt_dot740)->m32;
    sjt_math912 = sjt_math929 * sjt_math930;
    sjt_math909 = sjt_math911 - sjt_math912;
    sjt_dot741 = _parent;
    sjt_math935 = (sjt_dot741)->m12;
    sjt_dot742 = _parent;
    sjt_math936 = (sjt_dot742)->m21;
    sjt_math933 = sjt_math935 * sjt_math936;
    sjt_dot743 = _parent;
    sjt_math934 = (sjt_dot743)->m33;
    sjt_math910 = sjt_math933 * sjt_math934;
    sjt_math907 = sjt_math909 - sjt_math910;
    sjt_dot744 = _parent;
    sjt_math939 = (sjt_dot744)->m11;
    sjt_dot745 = _parent;
    sjt_math940 = (sjt_dot745)->m22;
    sjt_math937 = sjt_math939 * sjt_math940;
    sjt_dot746 = _parent;
    sjt_math938 = (sjt_dot746)->m33;
    sjt_math908 = sjt_math937 * sjt_math938;
    sjv_t.m00 = sjt_math907 + sjt_math908;
    sjt_dot747 = _parent;
    sjt_math953 = (sjt_dot747)->m03;
    sjt_dot748 = _parent;
    sjt_math954 = (sjt_dot748)->m22;
    sjt_math951 = sjt_math953 * sjt_math954;
    sjt_dot749 = _parent;
    sjt_math952 = (sjt_dot749)->m31;
    sjt_math949 = sjt_math951 * sjt_math952;
    sjt_dot750 = _parent;
    sjt_math957 = (sjt_dot750)->m02;
    sjt_dot751 = _parent;
    sjt_math958 = (sjt_dot751)->m23;
    sjt_math955 = sjt_math957 * sjt_math958;
    sjt_dot752 = _parent;
    sjt_math956 = (sjt_dot752)->m31;
    sjt_math950 = sjt_math955 * sjt_math956;
    sjt_math947 = sjt_math949 - sjt_math950;
    sjt_dot753 = _parent;
    sjt_math961 = (sjt_dot753)->m03;
    sjt_dot754 = _parent;
    sjt_math962 = (sjt_dot754)->m21;
    sjt_math959 = sjt_math961 * sjt_math962;
    sjt_dot755 = _parent;
    sjt_math960 = (sjt_dot755)->m32;
    sjt_math948 = sjt_math959 * sjt_math960;
    sjt_math945 = sjt_math947 - sjt_math948;
    sjt_dot756 = _parent;
    sjt_math965 = (sjt_dot756)->m01;
    sjt_dot757 = _parent;
    sjt_math966 = (sjt_dot757)->m23;
    sjt_math963 = sjt_math965 * sjt_math966;
    sjt_dot758 = _parent;
    sjt_math964 = (sjt_dot758)->m32;
    sjt_math946 = sjt_math963 * sjt_math964;
    sjt_math943 = sjt_math945 + sjt_math946;
    sjt_dot759 = _parent;
    sjt_math969 = (sjt_dot759)->m02;
    sjt_dot760 = _parent;
    sjt_math970 = (sjt_dot760)->m21;
    sjt_math967 = sjt_math969 * sjt_math970;
    sjt_dot761 = _parent;
    sjt_math968 = (sjt_dot761)->m33;
    sjt_math944 = sjt_math967 * sjt_math968;
    sjt_math941 = sjt_math943 + sjt_math944;
    sjt_dot762 = _parent;
    sjt_math973 = (sjt_dot762)->m01;
    sjt_dot763 = _parent;
    sjt_math974 = (sjt_dot763)->m22;
    sjt_math971 = sjt_math973 * sjt_math974;
    sjt_dot764 = _parent;
    sjt_math972 = (sjt_dot764)->m33;
    sjt_math942 = sjt_math971 * sjt_math972;
    sjv_t.m01 = sjt_math941 - sjt_math942;
    sjt_dot765 = _parent;
    sjt_math987 = (sjt_dot765)->m02;
    sjt_dot766 = _parent;
    sjt_math988 = (sjt_dot766)->m13;
    sjt_math985 = sjt_math987 * sjt_math988;
    sjt_dot767 = _parent;
    sjt_math986 = (sjt_dot767)->m31;
    sjt_math983 = sjt_math985 * sjt_math986;
    sjt_dot768 = _parent;
    sjt_math991 = (sjt_dot768)->m03;
    sjt_dot769 = _parent;
    sjt_math992 = (sjt_dot769)->m12;
    sjt_math989 = sjt_math991 * sjt_math992;
    sjt_dot770 = _parent;
    sjt_math990 = (sjt_dot770)->m31;
    sjt_math984 = sjt_math989 * sjt_math990;
    sjt_math981 = sjt_math983 - sjt_math984;
    sjt_dot771 = _parent;
    sjt_math995 = (sjt_dot771)->m03;
    sjt_dot772 = _parent;
    sjt_math996 = (sjt_dot772)->m11;
    sjt_math993 = sjt_math995 * sjt_math996;
    sjt_dot773 = _parent;
    sjt_math994 = (sjt_dot773)->m32;
    sjt_math982 = sjt_math993 * sjt_math994;
    sjt_math979 = sjt_math981 + sjt_math982;
    sjt_dot774 = _parent;
    sjt_math999 = (sjt_dot774)->m01;
    sjt_dot775 = _parent;
    sjt_math1000 = (sjt_dot775)->m13;
    sjt_math997 = sjt_math999 * sjt_math1000;
    sjt_dot776 = _parent;
    sjt_math998 = (sjt_dot776)->m32;
    sjt_math980 = sjt_math997 * sjt_math998;
    sjt_math977 = sjt_math979 - sjt_math980;
    sjt_dot777 = _parent;
    sjt_math1003 = (sjt_dot777)->m02;
    sjt_dot778 = _parent;
    sjt_math1004 = (sjt_dot778)->m11;
    sjt_math1001 = sjt_math1003 * sjt_math1004;
    sjt_dot779 = _parent;
    sjt_math1002 = (sjt_dot779)->m33;
    sjt_math978 = sjt_math1001 * sjt_math1002;
    sjt_math975 = sjt_math977 - sjt_math978;
    sjt_dot780 = _parent;
    sjt_math1007 = (sjt_dot780)->m01;
    sjt_dot781 = _parent;
    sjt_math1008 = (sjt_dot781)->m12;
    sjt_math1005 = sjt_math1007 * sjt_math1008;
    sjt_dot782 = _parent;
    sjt_math1006 = (sjt_dot782)->m33;
    sjt_math976 = sjt_math1005 * sjt_math1006;
    sjv_t.m02 = sjt_math975 + sjt_math976;
    sjt_dot783 = _parent;
    sjt_math1021 = (sjt_dot783)->m03;
    sjt_dot784 = _parent;
    sjt_math1022 = (sjt_dot784)->m12;
    sjt_math1019 = sjt_math1021 * sjt_math1022;
    sjt_dot785 = _parent;
    sjt_math1020 = (sjt_dot785)->m21;
    sjt_math1017 = sjt_math1019 * sjt_math1020;
    sjt_dot786 = _parent;
    sjt_math1025 = (sjt_dot786)->m02;
    sjt_dot787 = _parent;
    sjt_math1026 = (sjt_dot787)->m13;
    sjt_math1023 = sjt_math1025 * sjt_math1026;
    sjt_dot788 = _parent;
    sjt_math1024 = (sjt_dot788)->m21;
    sjt_math1018 = sjt_math1023 * sjt_math1024;
    sjt_math1015 = sjt_math1017 - sjt_math1018;
    sjt_dot789 = _parent;
    sjt_math1029 = (sjt_dot789)->m03;
    sjt_dot790 = _parent;
    sjt_math1030 = (sjt_dot790)->m11;
    sjt_math1027 = sjt_math1029 * sjt_math1030;
    sjt_dot791 = _parent;
    sjt_math1028 = (sjt_dot791)->m22;
    sjt_math1016 = sjt_math1027 * sjt_math1028;
    sjt_math1013 = sjt_math1015 - sjt_math1016;
    sjt_dot792 = _parent;
    sjt_math1033 = (sjt_dot792)->m01;
    sjt_dot793 = _parent;
    sjt_math1034 = (sjt_dot793)->m13;
    sjt_math1031 = sjt_math1033 * sjt_math1034;
    sjt_dot794 = _parent;
    sjt_math1032 = (sjt_dot794)->m22;
    sjt_math1014 = sjt_math1031 * sjt_math1032;
    sjt_math1011 = sjt_math1013 + sjt_math1014;
    sjt_dot795 = _parent;
    sjt_math1037 = (sjt_dot795)->m02;
    sjt_dot796 = _parent;
    sjt_math1038 = (sjt_dot796)->m11;
    sjt_math1035 = sjt_math1037 * sjt_math1038;
    sjt_dot797 = _parent;
    sjt_math1036 = (sjt_dot797)->m23;
    sjt_math1012 = sjt_math1035 * sjt_math1036;
    sjt_math1009 = sjt_math1011 + sjt_math1012;
    sjt_dot798 = _parent;
    sjt_math1041 = (sjt_dot798)->m01;
    sjt_dot799 = _parent;
    sjt_math1042 = (sjt_dot799)->m12;
    sjt_math1039 = sjt_math1041 * sjt_math1042;
    sjt_dot800 = _parent;
    sjt_math1040 = (sjt_dot800)->m23;
    sjt_math1010 = sjt_math1039 * sjt_math1040;
    sjv_t.m03 = sjt_math1009 - sjt_math1010;
    sjt_dot801 = _parent;
    sjt_math1055 = (sjt_dot801)->m13;
    sjt_dot802 = _parent;
    sjt_math1056 = (sjt_dot802)->m22;
    sjt_math1053 = sjt_math1055 * sjt_math1056;
    sjt_dot803 = _parent;
    sjt_math1054 = (sjt_dot803)->m30;
    sjt_math1051 = sjt_math1053 * sjt_math1054;
    sjt_dot804 = _parent;
    sjt_math1059 = (sjt_dot804)->m12;
    sjt_dot805 = _parent;
    sjt_math1060 = (sjt_dot805)->m23;
    sjt_math1057 = sjt_math1059 * sjt_math1060;
    sjt_dot806 = _parent;
    sjt_math1058 = (sjt_dot806)->m30;
    sjt_math1052 = sjt_math1057 * sjt_math1058;
    sjt_math1049 = sjt_math1051 - sjt_math1052;
    sjt_dot807 = _parent;
    sjt_math1063 = (sjt_dot807)->m13;
    sjt_dot808 = _parent;
    sjt_math1064 = (sjt_dot808)->m20;
    sjt_math1061 = sjt_math1063 * sjt_math1064;
    sjt_dot809 = _parent;
    sjt_math1062 = (sjt_dot809)->m32;
    sjt_math1050 = sjt_math1061 * sjt_math1062;
    sjt_math1047 = sjt_math1049 - sjt_math1050;
    sjt_dot810 = _parent;
    sjt_math1067 = (sjt_dot810)->m10;
    sjt_dot811 = _parent;
    sjt_math1068 = (sjt_dot811)->m23;
    sjt_math1065 = sjt_math1067 * sjt_math1068;
    sjt_dot812 = _parent;
    sjt_math1066 = (sjt_dot812)->m32;
    sjt_math1048 = sjt_math1065 * sjt_math1066;
    sjt_math1045 = sjt_math1047 + sjt_math1048;
    sjt_dot813 = _parent;
    sjt_math1071 = (sjt_dot813)->m12;
    sjt_dot814 = _parent;
    sjt_math1072 = (sjt_dot814)->m20;
    sjt_math1069 = sjt_math1071 * sjt_math1072;
    sjt_dot815 = _parent;
    sjt_math1070 = (sjt_dot815)->m33;
    sjt_math1046 = sjt_math1069 * sjt_math1070;
    sjt_math1043 = sjt_math1045 + sjt_math1046;
    sjt_dot816 = _parent;
    sjt_math1075 = (sjt_dot816)->m10;
    sjt_dot817 = _parent;
    sjt_math1076 = (sjt_dot817)->m22;
    sjt_math1073 = sjt_math1075 * sjt_math1076;
    sjt_dot818 = _parent;
    sjt_math1074 = (sjt_dot818)->m33;
    sjt_math1044 = sjt_math1073 * sjt_math1074;
    sjv_t.m10 = sjt_math1043 - sjt_math1044;
    sjt_dot819 = _parent;
    sjt_math1089 = (sjt_dot819)->m02;
    sjt_dot820 = _parent;
    sjt_math1090 = (sjt_dot820)->m23;
    sjt_math1087 = sjt_math1089 * sjt_math1090;
    sjt_dot821 = _parent;
    sjt_math1088 = (sjt_dot821)->m30;
    sjt_math1085 = sjt_math1087 * sjt_math1088;
    sjt_dot822 = _parent;
    sjt_math1093 = (sjt_dot822)->m03;
    sjt_dot823 = _parent;
    sjt_math1094 = (sjt_dot823)->m22;
    sjt_math1091 = sjt_math1093 * sjt_math1094;
    sjt_dot824 = _parent;
    sjt_math1092 = (sjt_dot824)->m30;
    sjt_math1086 = sjt_math1091 * sjt_math1092;
    sjt_math1083 = sjt_math1085 - sjt_math1086;
    sjt_dot825 = _parent;
    sjt_math1097 = (sjt_dot825)->m03;
    sjt_dot826 = _parent;
    sjt_math1098 = (sjt_dot826)->m20;
    sjt_math1095 = sjt_math1097 * sjt_math1098;
    sjt_dot827 = _parent;
    sjt_math1096 = (sjt_dot827)->m32;
    sjt_math1084 = sjt_math1095 * sjt_math1096;
    sjt_math1081 = sjt_math1083 + sjt_math1084;
    sjt_dot828 = _parent;
    sjt_math1101 = (sjt_dot828)->m00;
    sjt_dot829 = _parent;
    sjt_math1102 = (sjt_dot829)->m23;
    sjt_math1099 = sjt_math1101 * sjt_math1102;
    sjt_dot830 = _parent;
    sjt_math1100 = (sjt_dot830)->m32;
    sjt_math1082 = sjt_math1099 * sjt_math1100;
    sjt_math1079 = sjt_math1081 - sjt_math1082;
    sjt_dot831 = _parent;
    sjt_math1105 = (sjt_dot831)->m02;
    sjt_dot832 = _parent;
    sjt_math1106 = (sjt_dot832)->m20;
    sjt_math1103 = sjt_math1105 * sjt_math1106;
    sjt_dot833 = _parent;
    sjt_math1104 = (sjt_dot833)->m33;
    sjt_math1080 = sjt_math1103 * sjt_math1104;
    sjt_math1077 = sjt_math1079 - sjt_math1080;
    sjt_dot834 = _parent;
    sjt_math1109 = (sjt_dot834)->m00;
    sjt_dot835 = _parent;
    sjt_math1110 = (sjt_dot835)->m22;
    sjt_math1107 = sjt_math1109 * sjt_math1110;
    sjt_dot836 = _parent;
    sjt_math1108 = (sjt_dot836)->m33;
    sjt_math1078 = sjt_math1107 * sjt_math1108;
    sjv_t.m11 = sjt_math1077 + sjt_math1078;
    sjt_dot837 = _parent;
    sjt_math1123 = (sjt_dot837)->m03;
    sjt_dot838 = _parent;
    sjt_math1124 = (sjt_dot838)->m12;
    sjt_math1121 = sjt_math1123 * sjt_math1124;
    sjt_dot839 = _parent;
    sjt_math1122 = (sjt_dot839)->m30;
    sjt_math1119 = sjt_math1121 * sjt_math1122;
    sjt_dot840 = _parent;
    sjt_math1127 = (sjt_dot840)->m02;
    sjt_dot841 = _parent;
    sjt_math1128 = (sjt_dot841)->m13;
    sjt_math1125 = sjt_math1127 * sjt_math1128;
    sjt_dot842 = _parent;
    sjt_math1126 = (sjt_dot842)->m30;
    sjt_math1120 = sjt_math1125 * sjt_math1126;
    sjt_math1117 = sjt_math1119 - sjt_math1120;
    sjt_dot843 = _parent;
    sjt_math1131 = (sjt_dot843)->m03;
    sjt_dot844 = _parent;
    sjt_math1132 = (sjt_dot844)->m10;
    sjt_math1129 = sjt_math1131 * sjt_math1132;
    sjt_dot845 = _parent;
    sjt_math1130 = (sjt_dot845)->m32;
    sjt_math1118 = sjt_math1129 * sjt_math1130;
    sjt_math1115 = sjt_math1117 - sjt_math1118;
    sjt_dot846 = _parent;
    sjt_math1135 = (sjt_dot846)->m00;
    sjt_dot847 = _parent;
    sjt_math1136 = (sjt_dot847)->m13;
    sjt_math1133 = sjt_math1135 * sjt_math1136;
    sjt_dot848 = _parent;
    sjt_math1134 = (sjt_dot848)->m32;
    sjt_math1116 = sjt_math1133 * sjt_math1134;
    sjt_math1113 = sjt_math1115 + sjt_math1116;
    sjt_dot849 = _parent;
    sjt_math1139 = (sjt_dot849)->m02;
    sjt_dot850 = _parent;
    sjt_math1140 = (sjt_dot850)->m10;
    sjt_math1137 = sjt_math1139 * sjt_math1140;
    sjt_dot851 = _parent;
    sjt_math1138 = (sjt_dot851)->m33;
    sjt_math1114 = sjt_math1137 * sjt_math1138;
    sjt_math1111 = sjt_math1113 + sjt_math1114;
    sjt_dot852 = _parent;
    sjt_math1143 = (sjt_dot852)->m00;
    sjt_dot853 = _parent;
    sjt_math1144 = (sjt_dot853)->m12;
    sjt_math1141 = sjt_math1143 * sjt_math1144;
    sjt_dot854 = _parent;
    sjt_math1142 = (sjt_dot854)->m33;
    sjt_math1112 = sjt_math1141 * sjt_math1142;
    sjv_t.m12 = sjt_math1111 - sjt_math1112;
    sjt_dot855 = _parent;
    sjt_math1157 = (sjt_dot855)->m02;
    sjt_dot856 = _parent;
    sjt_math1158 = (sjt_dot856)->m13;
    sjt_math1155 = sjt_math1157 * sjt_math1158;
    sjt_dot857 = _parent;
    sjt_math1156 = (sjt_dot857)->m20;
    sjt_math1153 = sjt_math1155 * sjt_math1156;
    sjt_dot858 = _parent;
    sjt_math1161 = (sjt_dot858)->m03;
    sjt_dot859 = _parent;
    sjt_math1162 = (sjt_dot859)->m12;
    sjt_math1159 = sjt_math1161 * sjt_math1162;
    sjt_dot860 = _parent;
    sjt_math1160 = (sjt_dot860)->m20;
    sjt_math1154 = sjt_math1159 * sjt_math1160;
    sjt_math1151 = sjt_math1153 - sjt_math1154;
    sjt_dot861 = _parent;
    sjt_math1165 = (sjt_dot861)->m03;
    sjt_dot862 = _parent;
    sjt_math1166 = (sjt_dot862)->m10;
    sjt_math1163 = sjt_math1165 * sjt_math1166;
    sjt_dot863 = _parent;
    sjt_math1164 = (sjt_dot863)->m22;
    sjt_math1152 = sjt_math1163 * sjt_math1164;
    sjt_math1149 = sjt_math1151 + sjt_math1152;
    sjt_dot864 = _parent;
    sjt_math1169 = (sjt_dot864)->m00;
    sjt_dot865 = _parent;
    sjt_math1170 = (sjt_dot865)->m13;
    sjt_math1167 = sjt_math1169 * sjt_math1170;
    sjt_dot866 = _parent;
    sjt_math1168 = (sjt_dot866)->m22;
    sjt_math1150 = sjt_math1167 * sjt_math1168;
    sjt_math1147 = sjt_math1149 - sjt_math1150;
    sjt_dot867 = _parent;
    sjt_math1173 = (sjt_dot867)->m02;
    sjt_dot868 = _parent;
    sjt_math1174 = (sjt_dot868)->m10;
    sjt_math1171 = sjt_math1173 * sjt_math1174;
    sjt_dot869 = _parent;
    sjt_math1172 = (sjt_dot869)->m23;
    sjt_math1148 = sjt_math1171 * sjt_math1172;
    sjt_math1145 = sjt_math1147 - sjt_math1148;
    sjt_dot870 = _parent;
    sjt_math1177 = (sjt_dot870)->m00;
    sjt_dot871 = _parent;
    sjt_math1178 = (sjt_dot871)->m12;
    sjt_math1175 = sjt_math1177 * sjt_math1178;
    sjt_dot872 = _parent;
    sjt_math1176 = (sjt_dot872)->m23;
    sjt_math1146 = sjt_math1175 * sjt_math1176;
    sjv_t.m13 = sjt_math1145 + sjt_math1146;
    sjt_dot873 = _parent;
    sjt_math1191 = (sjt_dot873)->m11;
    sjt_dot874 = _parent;
    sjt_math1192 = (sjt_dot874)->m23;
    sjt_math1189 = sjt_math1191 * sjt_math1192;
    sjt_dot875 = _parent;
    sjt_math1190 = (sjt_dot875)->m30;
    sjt_math1187 = sjt_math1189 * sjt_math1190;
    sjt_dot876 = _parent;
    sjt_math1195 = (sjt_dot876)->m13;
    sjt_dot877 = _parent;
    sjt_math1196 = (sjt_dot877)->m21;
    sjt_math1193 = sjt_math1195 * sjt_math1196;
    sjt_dot878 = _parent;
    sjt_math1194 = (sjt_dot878)->m30;
    sjt_math1188 = sjt_math1193 * sjt_math1194;
    sjt_math1185 = sjt_math1187 - sjt_math1188;
    sjt_dot879 = _parent;
    sjt_math1199 = (sjt_dot879)->m13;
    sjt_dot880 = _parent;
    sjt_math1200 = (sjt_dot880)->m20;
    sjt_math1197 = sjt_math1199 * sjt_math1200;
    sjt_dot881 = _parent;
    sjt_math1198 = (sjt_dot881)->m31;
    sjt_math1186 = sjt_math1197 * sjt_math1198;
    sjt_math1183 = sjt_math1185 + sjt_math1186;
    sjt_dot882 = _parent;
    sjt_math1203 = (sjt_dot882)->m10;
    sjt_dot883 = _parent;
    sjt_math1204 = (sjt_dot883)->m23;
    sjt_math1201 = sjt_math1203 * sjt_math1204;
    sjt_dot884 = _parent;
    sjt_math1202 = (sjt_dot884)->m31;
    sjt_math1184 = sjt_math1201 * sjt_math1202;
    sjt_math1181 = sjt_math1183 - sjt_math1184;
    sjt_dot885 = _parent;
    sjt_math1207 = (sjt_dot885)->m11;
    sjt_dot886 = _parent;
    sjt_math1208 = (sjt_dot886)->m20;
    sjt_math1205 = sjt_math1207 * sjt_math1208;
    sjt_dot887 = _parent;
    sjt_math1206 = (sjt_dot887)->m33;
    sjt_math1182 = sjt_math1205 * sjt_math1206;
    sjt_math1179 = sjt_math1181 - sjt_math1182;
    sjt_dot888 = _parent;
    sjt_math1211 = (sjt_dot888)->m10;
    sjt_dot889 = _parent;
    sjt_math1212 = (sjt_dot889)->m21;
    sjt_math1209 = sjt_math1211 * sjt_math1212;
    sjt_dot890 = _parent;
    sjt_math1210 = (sjt_dot890)->m33;
    sjt_math1180 = sjt_math1209 * sjt_math1210;
    sjv_t.m20 = sjt_math1179 + sjt_math1180;
    sjt_dot891 = _parent;
    sjt_math1225 = (sjt_dot891)->m03;
    sjt_dot892 = _parent;
    sjt_math1226 = (sjt_dot892)->m21;
    sjt_math1223 = sjt_math1225 * sjt_math1226;
    sjt_dot893 = _parent;
    sjt_math1224 = (sjt_dot893)->m30;
    sjt_math1221 = sjt_math1223 * sjt_math1224;
    sjt_dot894 = _parent;
    sjt_math1229 = (sjt_dot894)->m01;
    sjt_dot895 = _parent;
    sjt_math1230 = (sjt_dot895)->m23;
    sjt_math1227 = sjt_math1229 * sjt_math1230;
    sjt_dot896 = _parent;
    sjt_math1228 = (sjt_dot896)->m30;
    sjt_math1222 = sjt_math1227 * sjt_math1228;
    sjt_math1219 = sjt_math1221 - sjt_math1222;
    sjt_dot897 = _parent;
    sjt_math1233 = (sjt_dot897)->m03;
    sjt_dot898 = _parent;
    sjt_math1234 = (sjt_dot898)->m20;
    sjt_math1231 = sjt_math1233 * sjt_math1234;
    sjt_dot899 = _parent;
    sjt_math1232 = (sjt_dot899)->m31;
    sjt_math1220 = sjt_math1231 * sjt_math1232;
    sjt_math1217 = sjt_math1219 - sjt_math1220;
    sjt_dot900 = _parent;
    sjt_math1237 = (sjt_dot900)->m00;
    sjt_dot901 = _parent;
    sjt_math1238 = (sjt_dot901)->m23;
    sjt_math1235 = sjt_math1237 * sjt_math1238;
    sjt_dot902 = _parent;
    sjt_math1236 = (sjt_dot902)->m31;
    sjt_math1218 = sjt_math1235 * sjt_math1236;
    sjt_math1215 = sjt_math1217 + sjt_math1218;
    sjt_dot903 = _parent;
    sjt_math1241 = (sjt_dot903)->m01;
    sjt_dot904 = _parent;
    sjt_math1242 = (sjt_dot904)->m20;
    sjt_math1239 = sjt_math1241 * sjt_math1242;
    sjt_dot905 = _parent;
    sjt_math1240 = (sjt_dot905)->m33;
    sjt_math1216 = sjt_math1239 * sjt_math1240;
    sjt_math1213 = sjt_math1215 + sjt_math1216;
    sjt_dot906 = _parent;
    sjt_math1245 = (sjt_dot906)->m00;
    sjt_dot907 = _parent;
    sjt_math1246 = (sjt_dot907)->m21;
    sjt_math1243 = sjt_math1245 * sjt_math1246;
    sjt_dot908 = _parent;
    sjt_math1244 = (sjt_dot908)->m33;
    sjt_math1214 = sjt_math1243 * sjt_math1244;
    sjv_t.m21 = sjt_math1213 - sjt_math1214;
    sjt_dot909 = _parent;
    sjt_math1259 = (sjt_dot909)->m01;
    sjt_dot910 = _parent;
    sjt_math1260 = (sjt_dot910)->m13;
    sjt_math1257 = sjt_math1259 * sjt_math1260;
    sjt_dot911 = _parent;
    sjt_math1258 = (sjt_dot911)->m30;
    sjt_math1255 = sjt_math1257 * sjt_math1258;
    sjt_dot912 = _parent;
    sjt_math1263 = (sjt_dot912)->m03;
    sjt_dot913 = _parent;
    sjt_math1264 = (sjt_dot913)->m11;
    sjt_math1261 = sjt_math1263 * sjt_math1264;
    sjt_dot914 = _parent;
    sjt_math1262 = (sjt_dot914)->m30;
    sjt_math1256 = sjt_math1261 * sjt_math1262;
    sjt_math1253 = sjt_math1255 - sjt_math1256;
    sjt_dot915 = _parent;
    sjt_math1267 = (sjt_dot915)->m03;
    sjt_dot916 = _parent;
    sjt_math1268 = (sjt_dot916)->m10;
    sjt_math1265 = sjt_math1267 * sjt_math1268;
    sjt_dot917 = _parent;
    sjt_math1266 = (sjt_dot917)->m31;
    sjt_math1254 = sjt_math1265 * sjt_math1266;
    sjt_math1251 = sjt_math1253 + sjt_math1254;
    sjt_dot918 = _parent;
    sjt_math1271 = (sjt_dot918)->m00;
    sjt_dot919 = _parent;
    sjt_math1272 = (sjt_dot919)->m13;
    sjt_math1269 = sjt_math1271 * sjt_math1272;
    sjt_dot920 = _parent;
    sjt_math1270 = (sjt_dot920)->m31;
    sjt_math1252 = sjt_math1269 * sjt_math1270;
    sjt_math1249 = sjt_math1251 - sjt_math1252;
    sjt_dot921 = _parent;
    sjt_math1275 = (sjt_dot921)->m01;
    sjt_dot922 = _parent;
    sjt_math1276 = (sjt_dot922)->m10;
    sjt_math1273 = sjt_math1275 * sjt_math1276;
    sjt_dot923 = _parent;
    sjt_math1274 = (sjt_dot923)->m33;
    sjt_math1250 = sjt_math1273 * sjt_math1274;
    sjt_math1247 = sjt_math1249 - sjt_math1250;
    sjt_dot924 = _parent;
    sjt_math1279 = (sjt_dot924)->m00;
    sjt_dot925 = _parent;
    sjt_math1280 = (sjt_dot925)->m11;
    sjt_math1277 = sjt_math1279 * sjt_math1280;
    sjt_dot926 = _parent;
    sjt_math1278 = (sjt_dot926)->m33;
    sjt_math1248 = sjt_math1277 * sjt_math1278;
    sjv_t.m22 = sjt_math1247 + sjt_math1248;
    sjt_dot927 = _parent;
    sjt_math1293 = (sjt_dot927)->m03;
    sjt_dot928 = _parent;
    sjt_math1294 = (sjt_dot928)->m11;
    sjt_math1291 = sjt_math1293 * sjt_math1294;
    sjt_dot929 = _parent;
    sjt_math1292 = (sjt_dot929)->m20;
    sjt_math1289 = sjt_math1291 * sjt_math1292;
    sjt_dot930 = _parent;
    sjt_math1297 = (sjt_dot930)->m01;
    sjt_dot931 = _parent;
    sjt_math1298 = (sjt_dot931)->m13;
    sjt_math1295 = sjt_math1297 * sjt_math1298;
    sjt_dot932 = _parent;
    sjt_math1296 = (sjt_dot932)->m20;
    sjt_math1290 = sjt_math1295 * sjt_math1296;
    sjt_math1287 = sjt_math1289 - sjt_math1290;
    sjt_dot933 = _parent;
    sjt_math1301 = (sjt_dot933)->m03;
    sjt_dot934 = _parent;
    sjt_math1302 = (sjt_dot934)->m10;
    sjt_math1299 = sjt_math1301 * sjt_math1302;
    sjt_dot935 = _parent;
    sjt_math1300 = (sjt_dot935)->m21;
    sjt_math1288 = sjt_math1299 * sjt_math1300;
    sjt_math1285 = sjt_math1287 - sjt_math1288;
    sjt_dot936 = _parent;
    sjt_math1305 = (sjt_dot936)->m00;
    sjt_dot937 = _parent;
    sjt_math1306 = (sjt_dot937)->m13;
    sjt_math1303 = sjt_math1305 * sjt_math1306;
    sjt_dot938 = _parent;
    sjt_math1304 = (sjt_dot938)->m21;
    sjt_math1286 = sjt_math1303 * sjt_math1304;
    sjt_math1283 = sjt_math1285 + sjt_math1286;
    sjt_dot939 = _parent;
    sjt_math1309 = (sjt_dot939)->m01;
    sjt_dot940 = _parent;
    sjt_math1310 = (sjt_dot940)->m10;
    sjt_math1307 = sjt_math1309 * sjt_math1310;
    sjt_dot941 = _parent;
    sjt_math1308 = (sjt_dot941)->m23;
    sjt_math1284 = sjt_math1307 * sjt_math1308;
    sjt_math1281 = sjt_math1283 + sjt_math1284;
    sjt_dot942 = _parent;
    sjt_math1313 = (sjt_dot942)->m00;
    sjt_dot943 = _parent;
    sjt_math1314 = (sjt_dot943)->m11;
    sjt_math1311 = sjt_math1313 * sjt_math1314;
    sjt_dot944 = _parent;
    sjt_math1312 = (sjt_dot944)->m23;
    sjt_math1282 = sjt_math1311 * sjt_math1312;
    sjv_t.m23 = sjt_math1281 - sjt_math1282;
    sjt_dot945 = _parent;
    sjt_math1327 = (sjt_dot945)->m12;
    sjt_dot946 = _parent;
    sjt_math1328 = (sjt_dot946)->m21;
    sjt_math1325 = sjt_math1327 * sjt_math1328;
    sjt_dot947 = _parent;
    sjt_math1326 = (sjt_dot947)->m30;
    sjt_math1323 = sjt_math1325 * sjt_math1326;
    sjt_dot948 = _parent;
    sjt_math1331 = (sjt_dot948)->m11;
    sjt_dot949 = _parent;
    sjt_math1332 = (sjt_dot949)->m22;
    sjt_math1329 = sjt_math1331 * sjt_math1332;
    sjt_dot950 = _parent;
    sjt_math1330 = (sjt_dot950)->m30;
    sjt_math1324 = sjt_math1329 * sjt_math1330;
    sjt_math1321 = sjt_math1323 - sjt_math1324;
    sjt_dot951 = _parent;
    sjt_math1335 = (sjt_dot951)->m12;
    sjt_dot952 = _parent;
    sjt_math1336 = (sjt_dot952)->m20;
    sjt_math1333 = sjt_math1335 * sjt_math1336;
    sjt_dot953 = _parent;
    sjt_math1334 = (sjt_dot953)->m31;
    sjt_math1322 = sjt_math1333 * sjt_math1334;
    sjt_math1319 = sjt_math1321 - sjt_math1322;
    sjt_dot954 = _parent;
    sjt_math1339 = (sjt_dot954)->m10;
    sjt_dot955 = _parent;
    sjt_math1340 = (sjt_dot955)->m22;
    sjt_math1337 = sjt_math1339 * sjt_math1340;
    sjt_dot956 = _parent;
    sjt_math1338 = (sjt_dot956)->m31;
    sjt_math1320 = sjt_math1337 * sjt_math1338;
    sjt_math1317 = sjt_math1319 + sjt_math1320;
    sjt_dot957 = _parent;
    sjt_math1343 = (sjt_dot957)->m11;
    sjt_dot958 = _parent;
    sjt_math1344 = (sjt_dot958)->m20;
    sjt_math1341 = sjt_math1343 * sjt_math1344;
    sjt_dot959 = _parent;
    sjt_math1342 = (sjt_dot959)->m32;
    sjt_math1318 = sjt_math1341 * sjt_math1342;
    sjt_math1315 = sjt_math1317 + sjt_math1318;
    sjt_dot960 = _parent;
    sjt_math1347 = (sjt_dot960)->m10;
    sjt_dot961 = _parent;
    sjt_math1348 = (sjt_dot961)->m21;
    sjt_math1345 = sjt_math1347 * sjt_math1348;
    sjt_dot962 = _parent;
    sjt_math1346 = (sjt_dot962)->m32;
    sjt_math1316 = sjt_math1345 * sjt_math1346;
    sjv_t.m30 = sjt_math1315 - sjt_math1316;
    sjt_dot963 = _parent;
    sjt_math1361 = (sjt_dot963)->m01;
    sjt_dot964 = _parent;
    sjt_math1362 = (sjt_dot964)->m22;
    sjt_math1359 = sjt_math1361 * sjt_math1362;
    sjt_dot965 = _parent;
    sjt_math1360 = (sjt_dot965)->m30;
    sjt_math1357 = sjt_math1359 * sjt_math1360;
    sjt_dot966 = _parent;
    sjt_math1365 = (sjt_dot966)->m02;
    sjt_dot967 = _parent;
    sjt_math1366 = (sjt_dot967)->m21;
    sjt_math1363 = sjt_math1365 * sjt_math1366;
    sjt_dot968 = _parent;
    sjt_math1364 = (sjt_dot968)->m30;
    sjt_math1358 = sjt_math1363 * sjt_math1364;
    sjt_math1355 = sjt_math1357 - sjt_math1358;
    sjt_dot969 = _parent;
    sjt_math1369 = (sjt_dot969)->m02;
    sjt_dot970 = _parent;
    sjt_math1370 = (sjt_dot970)->m20;
    sjt_math1367 = sjt_math1369 * sjt_math1370;
    sjt_dot971 = _parent;
    sjt_math1368 = (sjt_dot971)->m31;
    sjt_math1356 = sjt_math1367 * sjt_math1368;
    sjt_math1353 = sjt_math1355 + sjt_math1356;
    sjt_dot972 = _parent;
    sjt_math1373 = (sjt_dot972)->m00;
    sjt_dot973 = _parent;
    sjt_math1374 = (sjt_dot973)->m22;
    sjt_math1371 = sjt_math1373 * sjt_math1374;
    sjt_dot974 = _parent;
    sjt_math1372 = (sjt_dot974)->m31;
    sjt_math1354 = sjt_math1371 * sjt_math1372;
    sjt_math1351 = sjt_math1353 - sjt_math1354;
    sjt_dot975 = _parent;
    sjt_math1377 = (sjt_dot975)->m01;
    sjt_dot976 = _parent;
    sjt_math1378 = (sjt_dot976)->m20;
    sjt_math1375 = sjt_math1377 * sjt_math1378;
    sjt_dot977 = _parent;
    sjt_math1376 = (sjt_dot977)->m32;
    sjt_math1352 = sjt_math1375 * sjt_math1376;
    sjt_math1349 = sjt_math1351 - sjt_math1352;
    sjt_dot978 = _parent;
    sjt_math1381 = (sjt_dot978)->m00;
    sjt_dot979 = _parent;
    sjt_math1382 = (sjt_dot979)->m21;
    sjt_math1379 = sjt_math1381 * sjt_math1382;
    sjt_dot980 = _parent;
    sjt_math1380 = (sjt_dot980)->m32;
    sjt_math1350 = sjt_math1379 * sjt_math1380;
    sjv_t.m31 = sjt_math1349 + sjt_math1350;
    sjt_dot981 = _parent;
    sjt_math1395 = (sjt_dot981)->m02;
    sjt_dot982 = _parent;
    sjt_math1396 = (sjt_dot982)->m11;
    sjt_math1393 = sjt_math1395 * sjt_math1396;
    sjt_dot983 = _parent;
    sjt_math1394 = (sjt_dot983)->m30;
    sjt_math1391 = sjt_math1393 * sjt_math1394;
    sjt_dot984 = _parent;
    sjt_math1399 = (sjt_dot984)->m01;
    sjt_dot985 = _parent;
    sjt_math1400 = (sjt_dot985)->m12;
    sjt_math1397 = sjt_math1399 * sjt_math1400;
    sjt_dot986 = _parent;
    sjt_math1398 = (sjt_dot986)->m30;
    sjt_math1392 = sjt_math1397 * sjt_math1398;
    sjt_math1389 = sjt_math1391 - sjt_math1392;
    sjt_dot987 = _parent;
    sjt_math1403 = (sjt_dot987)->m02;
    sjt_dot988 = _parent;
    sjt_math1404 = (sjt_dot988)->m10;
    sjt_math1401 = sjt_math1403 * sjt_math1404;
    sjt_dot989 = _parent;
    sjt_math1402 = (sjt_dot989)->m31;
    sjt_math1390 = sjt_math1401 * sjt_math1402;
    sjt_math1387 = sjt_math1389 - sjt_math1390;
    sjt_dot990 = _parent;
    sjt_math1407 = (sjt_dot990)->m00;
    sjt_dot991 = _parent;
    sjt_math1408 = (sjt_dot991)->m12;
    sjt_math1405 = sjt_math1407 * sjt_math1408;
    sjt_dot992 = _parent;
    sjt_math1406 = (sjt_dot992)->m31;
    sjt_math1388 = sjt_math1405 * sjt_math1406;
    sjt_math1385 = sjt_math1387 + sjt_math1388;
    sjt_dot993 = _parent;
    sjt_math1411 = (sjt_dot993)->m01;
    sjt_dot994 = _parent;
    sjt_math1412 = (sjt_dot994)->m10;
    sjt_math1409 = sjt_math1411 * sjt_math1412;
    sjt_dot995 = _parent;
    sjt_math1410 = (sjt_dot995)->m32;
    sjt_math1386 = sjt_math1409 * sjt_math1410;
    sjt_math1383 = sjt_math1385 + sjt_math1386;
    sjt_dot996 = _parent;
    sjt_math1415 = (sjt_dot996)->m00;
    sjt_dot997 = _parent;
    sjt_math1416 = (sjt_dot997)->m11;
    sjt_math1413 = sjt_math1415 * sjt_math1416;
    sjt_dot998 = _parent;
    sjt_math1414 = (sjt_dot998)->m32;
    sjt_math1384 = sjt_math1413 * sjt_math1414;
    sjv_t.m32 = sjt_math1383 - sjt_math1384;
    sjt_dot999 = _parent;
    sjt_math1429 = (sjt_dot999)->m01;
    sjt_dot1000 = _parent;
    sjt_math1430 = (sjt_dot1000)->m12;
    sjt_math1427 = sjt_math1429 * sjt_math1430;
    sjt_dot1001 = _parent;
    sjt_math1428 = (sjt_dot1001)->m20;
    sjt_math1425 = sjt_math1427 * sjt_math1428;
    sjt_dot1002 = _parent;
    sjt_math1433 = (sjt_dot1002)->m02;
    sjt_dot1003 = _parent;
    sjt_math1434 = (sjt_dot1003)->m11;
    sjt_math1431 = sjt_math1433 * sjt_math1434;
    sjt_dot1004 = _parent;
    sjt_math1432 = (sjt_dot1004)->m20;
    sjt_math1426 = sjt_math1431 * sjt_math1432;
    sjt_math1423 = sjt_math1425 - sjt_math1426;
    sjt_dot1005 = _parent;
    sjt_math1437 = (sjt_dot1005)->m02;
    sjt_dot1006 = _parent;
    sjt_math1438 = (sjt_dot1006)->m10;
    sjt_math1435 = sjt_math1437 * sjt_math1438;
    sjt_dot1007 = _parent;
    sjt_math1436 = (sjt_dot1007)->m21;
    sjt_math1424 = sjt_math1435 * sjt_math1436;
    sjt_math1421 = sjt_math1423 + sjt_math1424;
    sjt_dot1008 = _parent;
    sjt_math1441 = (sjt_dot1008)->m00;
    sjt_dot1009 = _parent;
    sjt_math1442 = (sjt_dot1009)->m12;
    sjt_math1439 = sjt_math1441 * sjt_math1442;
    sjt_dot1010 = _parent;
    sjt_math1440 = (sjt_dot1010)->m21;
    sjt_math1422 = sjt_math1439 * sjt_math1440;
    sjt_math1419 = sjt_math1421 - sjt_math1422;
    sjt_dot1011 = _parent;
    sjt_math1445 = (sjt_dot1011)->m01;
    sjt_dot1012 = _parent;
    sjt_math1446 = (sjt_dot1012)->m10;
    sjt_math1443 = sjt_math1445 * sjt_math1446;
    sjt_dot1013 = _parent;
    sjt_math1444 = (sjt_dot1013)->m22;
    sjt_math1420 = sjt_math1443 * sjt_math1444;
    sjt_math1417 = sjt_math1419 - sjt_math1420;
    sjt_dot1014 = _parent;
    sjt_math1449 = (sjt_dot1014)->m00;
    sjt_dot1015 = _parent;
    sjt_math1450 = (sjt_dot1015)->m11;
    sjt_math1447 = sjt_math1449 * sjt_math1450;
    sjt_dot1016 = _parent;
    sjt_math1448 = (sjt_dot1016)->m22;
    sjt_math1418 = sjt_math1447 * sjt_math1448;
    sjv_t.m33 = sjt_math1417 + sjt_math1418;
    sjf_mat4(&sjv_t);
    sjt_parent129 = &sjv_t;
    sjt_math1515 = 1.0f;
    sjf_mat4_determinant(_parent, &sjt_math1516);
    sjt_functionParam232 = sjt_math1515 / sjt_math1516;
    sjf_mat4_multiplyf32(sjt_parent129, sjt_functionParam232, _return);

    if (sjv_t._refCount == 1) { sjf_mat4_destroy(&sjv_t); }
}

void sjf_mat4_invert_heap(sjs_mat4* _parent, sjs_mat4** _return) {
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
    float sjt_functionParam233;
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
    sjs_mat4* sjt_parent130 = 0;
    sjs_mat4 sjv_t = { -1 };

    sjv_t._refCount = 1;
    sjt_dot1145 = _parent;
    sjt_math1719 = (sjt_dot1145)->m12;
    sjt_dot1146 = _parent;
    sjt_math1720 = (sjt_dot1146)->m23;
    sjt_math1717 = sjt_math1719 * sjt_math1720;
    sjt_dot1147 = _parent;
    sjt_math1718 = (sjt_dot1147)->m31;
    sjt_math1715 = sjt_math1717 * sjt_math1718;
    sjt_dot1148 = _parent;
    sjt_math1723 = (sjt_dot1148)->m13;
    sjt_dot1149 = _parent;
    sjt_math1724 = (sjt_dot1149)->m22;
    sjt_math1721 = sjt_math1723 * sjt_math1724;
    sjt_dot1150 = _parent;
    sjt_math1722 = (sjt_dot1150)->m31;
    sjt_math1716 = sjt_math1721 * sjt_math1722;
    sjt_math1713 = sjt_math1715 - sjt_math1716;
    sjt_dot1151 = _parent;
    sjt_math1727 = (sjt_dot1151)->m13;
    sjt_dot1152 = _parent;
    sjt_math1728 = (sjt_dot1152)->m21;
    sjt_math1725 = sjt_math1727 * sjt_math1728;
    sjt_dot1153 = _parent;
    sjt_math1726 = (sjt_dot1153)->m32;
    sjt_math1714 = sjt_math1725 * sjt_math1726;
    sjt_math1711 = sjt_math1713 + sjt_math1714;
    sjt_dot1154 = _parent;
    sjt_math1731 = (sjt_dot1154)->m11;
    sjt_dot1155 = _parent;
    sjt_math1732 = (sjt_dot1155)->m23;
    sjt_math1729 = sjt_math1731 * sjt_math1732;
    sjt_dot1156 = _parent;
    sjt_math1730 = (sjt_dot1156)->m32;
    sjt_math1712 = sjt_math1729 * sjt_math1730;
    sjt_math1709 = sjt_math1711 - sjt_math1712;
    sjt_dot1157 = _parent;
    sjt_math1735 = (sjt_dot1157)->m12;
    sjt_dot1158 = _parent;
    sjt_math1736 = (sjt_dot1158)->m21;
    sjt_math1733 = sjt_math1735 * sjt_math1736;
    sjt_dot1159 = _parent;
    sjt_math1734 = (sjt_dot1159)->m33;
    sjt_math1710 = sjt_math1733 * sjt_math1734;
    sjt_math1707 = sjt_math1709 - sjt_math1710;
    sjt_dot1160 = _parent;
    sjt_math1739 = (sjt_dot1160)->m11;
    sjt_dot1161 = _parent;
    sjt_math1740 = (sjt_dot1161)->m22;
    sjt_math1737 = sjt_math1739 * sjt_math1740;
    sjt_dot1162 = _parent;
    sjt_math1738 = (sjt_dot1162)->m33;
    sjt_math1708 = sjt_math1737 * sjt_math1738;
    sjv_t.m00 = sjt_math1707 + sjt_math1708;
    sjt_dot1163 = _parent;
    sjt_math1753 = (sjt_dot1163)->m03;
    sjt_dot1164 = _parent;
    sjt_math1754 = (sjt_dot1164)->m22;
    sjt_math1751 = sjt_math1753 * sjt_math1754;
    sjt_dot1165 = _parent;
    sjt_math1752 = (sjt_dot1165)->m31;
    sjt_math1749 = sjt_math1751 * sjt_math1752;
    sjt_dot1166 = _parent;
    sjt_math1757 = (sjt_dot1166)->m02;
    sjt_dot1167 = _parent;
    sjt_math1758 = (sjt_dot1167)->m23;
    sjt_math1755 = sjt_math1757 * sjt_math1758;
    sjt_dot1168 = _parent;
    sjt_math1756 = (sjt_dot1168)->m31;
    sjt_math1750 = sjt_math1755 * sjt_math1756;
    sjt_math1747 = sjt_math1749 - sjt_math1750;
    sjt_dot1169 = _parent;
    sjt_math1761 = (sjt_dot1169)->m03;
    sjt_dot1170 = _parent;
    sjt_math1762 = (sjt_dot1170)->m21;
    sjt_math1759 = sjt_math1761 * sjt_math1762;
    sjt_dot1171 = _parent;
    sjt_math1760 = (sjt_dot1171)->m32;
    sjt_math1748 = sjt_math1759 * sjt_math1760;
    sjt_math1745 = sjt_math1747 - sjt_math1748;
    sjt_dot1172 = _parent;
    sjt_math1765 = (sjt_dot1172)->m01;
    sjt_dot1173 = _parent;
    sjt_math1766 = (sjt_dot1173)->m23;
    sjt_math1763 = sjt_math1765 * sjt_math1766;
    sjt_dot1174 = _parent;
    sjt_math1764 = (sjt_dot1174)->m32;
    sjt_math1746 = sjt_math1763 * sjt_math1764;
    sjt_math1743 = sjt_math1745 + sjt_math1746;
    sjt_dot1175 = _parent;
    sjt_math1769 = (sjt_dot1175)->m02;
    sjt_dot1176 = _parent;
    sjt_math1770 = (sjt_dot1176)->m21;
    sjt_math1767 = sjt_math1769 * sjt_math1770;
    sjt_dot1177 = _parent;
    sjt_math1768 = (sjt_dot1177)->m33;
    sjt_math1744 = sjt_math1767 * sjt_math1768;
    sjt_math1741 = sjt_math1743 + sjt_math1744;
    sjt_dot1178 = _parent;
    sjt_math1773 = (sjt_dot1178)->m01;
    sjt_dot1179 = _parent;
    sjt_math1774 = (sjt_dot1179)->m22;
    sjt_math1771 = sjt_math1773 * sjt_math1774;
    sjt_dot1180 = _parent;
    sjt_math1772 = (sjt_dot1180)->m33;
    sjt_math1742 = sjt_math1771 * sjt_math1772;
    sjv_t.m01 = sjt_math1741 - sjt_math1742;
    sjt_dot1181 = _parent;
    sjt_math1787 = (sjt_dot1181)->m02;
    sjt_dot1182 = _parent;
    sjt_math1788 = (sjt_dot1182)->m13;
    sjt_math1785 = sjt_math1787 * sjt_math1788;
    sjt_dot1183 = _parent;
    sjt_math1786 = (sjt_dot1183)->m31;
    sjt_math1783 = sjt_math1785 * sjt_math1786;
    sjt_dot1184 = _parent;
    sjt_math1791 = (sjt_dot1184)->m03;
    sjt_dot1185 = _parent;
    sjt_math1792 = (sjt_dot1185)->m12;
    sjt_math1789 = sjt_math1791 * sjt_math1792;
    sjt_dot1186 = _parent;
    sjt_math1790 = (sjt_dot1186)->m31;
    sjt_math1784 = sjt_math1789 * sjt_math1790;
    sjt_math1781 = sjt_math1783 - sjt_math1784;
    sjt_dot1187 = _parent;
    sjt_math1795 = (sjt_dot1187)->m03;
    sjt_dot1188 = _parent;
    sjt_math1796 = (sjt_dot1188)->m11;
    sjt_math1793 = sjt_math1795 * sjt_math1796;
    sjt_dot1189 = _parent;
    sjt_math1794 = (sjt_dot1189)->m32;
    sjt_math1782 = sjt_math1793 * sjt_math1794;
    sjt_math1779 = sjt_math1781 + sjt_math1782;
    sjt_dot1190 = _parent;
    sjt_math1799 = (sjt_dot1190)->m01;
    sjt_dot1191 = _parent;
    sjt_math1800 = (sjt_dot1191)->m13;
    sjt_math1797 = sjt_math1799 * sjt_math1800;
    sjt_dot1192 = _parent;
    sjt_math1798 = (sjt_dot1192)->m32;
    sjt_math1780 = sjt_math1797 * sjt_math1798;
    sjt_math1777 = sjt_math1779 - sjt_math1780;
    sjt_dot1193 = _parent;
    sjt_math1803 = (sjt_dot1193)->m02;
    sjt_dot1194 = _parent;
    sjt_math1804 = (sjt_dot1194)->m11;
    sjt_math1801 = sjt_math1803 * sjt_math1804;
    sjt_dot1195 = _parent;
    sjt_math1802 = (sjt_dot1195)->m33;
    sjt_math1778 = sjt_math1801 * sjt_math1802;
    sjt_math1775 = sjt_math1777 - sjt_math1778;
    sjt_dot1196 = _parent;
    sjt_math1807 = (sjt_dot1196)->m01;
    sjt_dot1197 = _parent;
    sjt_math1808 = (sjt_dot1197)->m12;
    sjt_math1805 = sjt_math1807 * sjt_math1808;
    sjt_dot1198 = _parent;
    sjt_math1806 = (sjt_dot1198)->m33;
    sjt_math1776 = sjt_math1805 * sjt_math1806;
    sjv_t.m02 = sjt_math1775 + sjt_math1776;
    sjt_dot1199 = _parent;
    sjt_math1821 = (sjt_dot1199)->m03;
    sjt_dot1200 = _parent;
    sjt_math1822 = (sjt_dot1200)->m12;
    sjt_math1819 = sjt_math1821 * sjt_math1822;
    sjt_dot1201 = _parent;
    sjt_math1820 = (sjt_dot1201)->m21;
    sjt_math1817 = sjt_math1819 * sjt_math1820;
    sjt_dot1202 = _parent;
    sjt_math1825 = (sjt_dot1202)->m02;
    sjt_dot1203 = _parent;
    sjt_math1826 = (sjt_dot1203)->m13;
    sjt_math1823 = sjt_math1825 * sjt_math1826;
    sjt_dot1204 = _parent;
    sjt_math1824 = (sjt_dot1204)->m21;
    sjt_math1818 = sjt_math1823 * sjt_math1824;
    sjt_math1815 = sjt_math1817 - sjt_math1818;
    sjt_dot1205 = _parent;
    sjt_math1829 = (sjt_dot1205)->m03;
    sjt_dot1206 = _parent;
    sjt_math1830 = (sjt_dot1206)->m11;
    sjt_math1827 = sjt_math1829 * sjt_math1830;
    sjt_dot1207 = _parent;
    sjt_math1828 = (sjt_dot1207)->m22;
    sjt_math1816 = sjt_math1827 * sjt_math1828;
    sjt_math1813 = sjt_math1815 - sjt_math1816;
    sjt_dot1208 = _parent;
    sjt_math1833 = (sjt_dot1208)->m01;
    sjt_dot1209 = _parent;
    sjt_math1834 = (sjt_dot1209)->m13;
    sjt_math1831 = sjt_math1833 * sjt_math1834;
    sjt_dot1210 = _parent;
    sjt_math1832 = (sjt_dot1210)->m22;
    sjt_math1814 = sjt_math1831 * sjt_math1832;
    sjt_math1811 = sjt_math1813 + sjt_math1814;
    sjt_dot1211 = _parent;
    sjt_math1837 = (sjt_dot1211)->m02;
    sjt_dot1212 = _parent;
    sjt_math1838 = (sjt_dot1212)->m11;
    sjt_math1835 = sjt_math1837 * sjt_math1838;
    sjt_dot1213 = _parent;
    sjt_math1836 = (sjt_dot1213)->m23;
    sjt_math1812 = sjt_math1835 * sjt_math1836;
    sjt_math1809 = sjt_math1811 + sjt_math1812;
    sjt_dot1214 = _parent;
    sjt_math1841 = (sjt_dot1214)->m01;
    sjt_dot1215 = _parent;
    sjt_math1842 = (sjt_dot1215)->m12;
    sjt_math1839 = sjt_math1841 * sjt_math1842;
    sjt_dot1216 = _parent;
    sjt_math1840 = (sjt_dot1216)->m23;
    sjt_math1810 = sjt_math1839 * sjt_math1840;
    sjv_t.m03 = sjt_math1809 - sjt_math1810;
    sjt_dot1217 = _parent;
    sjt_math1855 = (sjt_dot1217)->m13;
    sjt_dot1218 = _parent;
    sjt_math1856 = (sjt_dot1218)->m22;
    sjt_math1853 = sjt_math1855 * sjt_math1856;
    sjt_dot1219 = _parent;
    sjt_math1854 = (sjt_dot1219)->m30;
    sjt_math1851 = sjt_math1853 * sjt_math1854;
    sjt_dot1220 = _parent;
    sjt_math1859 = (sjt_dot1220)->m12;
    sjt_dot1221 = _parent;
    sjt_math1860 = (sjt_dot1221)->m23;
    sjt_math1857 = sjt_math1859 * sjt_math1860;
    sjt_dot1222 = _parent;
    sjt_math1858 = (sjt_dot1222)->m30;
    sjt_math1852 = sjt_math1857 * sjt_math1858;
    sjt_math1849 = sjt_math1851 - sjt_math1852;
    sjt_dot1223 = _parent;
    sjt_math1863 = (sjt_dot1223)->m13;
    sjt_dot1224 = _parent;
    sjt_math1864 = (sjt_dot1224)->m20;
    sjt_math1861 = sjt_math1863 * sjt_math1864;
    sjt_dot1225 = _parent;
    sjt_math1862 = (sjt_dot1225)->m32;
    sjt_math1850 = sjt_math1861 * sjt_math1862;
    sjt_math1847 = sjt_math1849 - sjt_math1850;
    sjt_dot1226 = _parent;
    sjt_math1867 = (sjt_dot1226)->m10;
    sjt_dot1227 = _parent;
    sjt_math1868 = (sjt_dot1227)->m23;
    sjt_math1865 = sjt_math1867 * sjt_math1868;
    sjt_dot1228 = _parent;
    sjt_math1866 = (sjt_dot1228)->m32;
    sjt_math1848 = sjt_math1865 * sjt_math1866;
    sjt_math1845 = sjt_math1847 + sjt_math1848;
    sjt_dot1229 = _parent;
    sjt_math1871 = (sjt_dot1229)->m12;
    sjt_dot1230 = _parent;
    sjt_math1872 = (sjt_dot1230)->m20;
    sjt_math1869 = sjt_math1871 * sjt_math1872;
    sjt_dot1231 = _parent;
    sjt_math1870 = (sjt_dot1231)->m33;
    sjt_math1846 = sjt_math1869 * sjt_math1870;
    sjt_math1843 = sjt_math1845 + sjt_math1846;
    sjt_dot1232 = _parent;
    sjt_math1875 = (sjt_dot1232)->m10;
    sjt_dot1233 = _parent;
    sjt_math1876 = (sjt_dot1233)->m22;
    sjt_math1873 = sjt_math1875 * sjt_math1876;
    sjt_dot1234 = _parent;
    sjt_math1874 = (sjt_dot1234)->m33;
    sjt_math1844 = sjt_math1873 * sjt_math1874;
    sjv_t.m10 = sjt_math1843 - sjt_math1844;
    sjt_dot1235 = _parent;
    sjt_math1889 = (sjt_dot1235)->m02;
    sjt_dot1236 = _parent;
    sjt_math1890 = (sjt_dot1236)->m23;
    sjt_math1887 = sjt_math1889 * sjt_math1890;
    sjt_dot1237 = _parent;
    sjt_math1888 = (sjt_dot1237)->m30;
    sjt_math1885 = sjt_math1887 * sjt_math1888;
    sjt_dot1238 = _parent;
    sjt_math1893 = (sjt_dot1238)->m03;
    sjt_dot1239 = _parent;
    sjt_math1894 = (sjt_dot1239)->m22;
    sjt_math1891 = sjt_math1893 * sjt_math1894;
    sjt_dot1240 = _parent;
    sjt_math1892 = (sjt_dot1240)->m30;
    sjt_math1886 = sjt_math1891 * sjt_math1892;
    sjt_math1883 = sjt_math1885 - sjt_math1886;
    sjt_dot1241 = _parent;
    sjt_math1897 = (sjt_dot1241)->m03;
    sjt_dot1242 = _parent;
    sjt_math1898 = (sjt_dot1242)->m20;
    sjt_math1895 = sjt_math1897 * sjt_math1898;
    sjt_dot1243 = _parent;
    sjt_math1896 = (sjt_dot1243)->m32;
    sjt_math1884 = sjt_math1895 * sjt_math1896;
    sjt_math1881 = sjt_math1883 + sjt_math1884;
    sjt_dot1244 = _parent;
    sjt_math1901 = (sjt_dot1244)->m00;
    sjt_dot1245 = _parent;
    sjt_math1902 = (sjt_dot1245)->m23;
    sjt_math1899 = sjt_math1901 * sjt_math1902;
    sjt_dot1246 = _parent;
    sjt_math1900 = (sjt_dot1246)->m32;
    sjt_math1882 = sjt_math1899 * sjt_math1900;
    sjt_math1879 = sjt_math1881 - sjt_math1882;
    sjt_dot1247 = _parent;
    sjt_math1905 = (sjt_dot1247)->m02;
    sjt_dot1248 = _parent;
    sjt_math1906 = (sjt_dot1248)->m20;
    sjt_math1903 = sjt_math1905 * sjt_math1906;
    sjt_dot1249 = _parent;
    sjt_math1904 = (sjt_dot1249)->m33;
    sjt_math1880 = sjt_math1903 * sjt_math1904;
    sjt_math1877 = sjt_math1879 - sjt_math1880;
    sjt_dot1250 = _parent;
    sjt_math1909 = (sjt_dot1250)->m00;
    sjt_dot1251 = _parent;
    sjt_math1910 = (sjt_dot1251)->m22;
    sjt_math1907 = sjt_math1909 * sjt_math1910;
    sjt_dot1252 = _parent;
    sjt_math1908 = (sjt_dot1252)->m33;
    sjt_math1878 = sjt_math1907 * sjt_math1908;
    sjv_t.m11 = sjt_math1877 + sjt_math1878;
    sjt_dot1253 = _parent;
    sjt_math1923 = (sjt_dot1253)->m03;
    sjt_dot1254 = _parent;
    sjt_math1924 = (sjt_dot1254)->m12;
    sjt_math1921 = sjt_math1923 * sjt_math1924;
    sjt_dot1255 = _parent;
    sjt_math1922 = (sjt_dot1255)->m30;
    sjt_math1919 = sjt_math1921 * sjt_math1922;
    sjt_dot1256 = _parent;
    sjt_math1927 = (sjt_dot1256)->m02;
    sjt_dot1257 = _parent;
    sjt_math1928 = (sjt_dot1257)->m13;
    sjt_math1925 = sjt_math1927 * sjt_math1928;
    sjt_dot1258 = _parent;
    sjt_math1926 = (sjt_dot1258)->m30;
    sjt_math1920 = sjt_math1925 * sjt_math1926;
    sjt_math1917 = sjt_math1919 - sjt_math1920;
    sjt_dot1259 = _parent;
    sjt_math1931 = (sjt_dot1259)->m03;
    sjt_dot1260 = _parent;
    sjt_math1932 = (sjt_dot1260)->m10;
    sjt_math1929 = sjt_math1931 * sjt_math1932;
    sjt_dot1261 = _parent;
    sjt_math1930 = (sjt_dot1261)->m32;
    sjt_math1918 = sjt_math1929 * sjt_math1930;
    sjt_math1915 = sjt_math1917 - sjt_math1918;
    sjt_dot1262 = _parent;
    sjt_math1935 = (sjt_dot1262)->m00;
    sjt_dot1263 = _parent;
    sjt_math1936 = (sjt_dot1263)->m13;
    sjt_math1933 = sjt_math1935 * sjt_math1936;
    sjt_dot1264 = _parent;
    sjt_math1934 = (sjt_dot1264)->m32;
    sjt_math1916 = sjt_math1933 * sjt_math1934;
    sjt_math1913 = sjt_math1915 + sjt_math1916;
    sjt_dot1265 = _parent;
    sjt_math1939 = (sjt_dot1265)->m02;
    sjt_dot1266 = _parent;
    sjt_math1940 = (sjt_dot1266)->m10;
    sjt_math1937 = sjt_math1939 * sjt_math1940;
    sjt_dot1267 = _parent;
    sjt_math1938 = (sjt_dot1267)->m33;
    sjt_math1914 = sjt_math1937 * sjt_math1938;
    sjt_math1911 = sjt_math1913 + sjt_math1914;
    sjt_dot1268 = _parent;
    sjt_math1943 = (sjt_dot1268)->m00;
    sjt_dot1269 = _parent;
    sjt_math1944 = (sjt_dot1269)->m12;
    sjt_math1941 = sjt_math1943 * sjt_math1944;
    sjt_dot1270 = _parent;
    sjt_math1942 = (sjt_dot1270)->m33;
    sjt_math1912 = sjt_math1941 * sjt_math1942;
    sjv_t.m12 = sjt_math1911 - sjt_math1912;
    sjt_dot1271 = _parent;
    sjt_math1957 = (sjt_dot1271)->m02;
    sjt_dot1272 = _parent;
    sjt_math1958 = (sjt_dot1272)->m13;
    sjt_math1955 = sjt_math1957 * sjt_math1958;
    sjt_dot1273 = _parent;
    sjt_math1956 = (sjt_dot1273)->m20;
    sjt_math1953 = sjt_math1955 * sjt_math1956;
    sjt_dot1274 = _parent;
    sjt_math1961 = (sjt_dot1274)->m03;
    sjt_dot1275 = _parent;
    sjt_math1962 = (sjt_dot1275)->m12;
    sjt_math1959 = sjt_math1961 * sjt_math1962;
    sjt_dot1276 = _parent;
    sjt_math1960 = (sjt_dot1276)->m20;
    sjt_math1954 = sjt_math1959 * sjt_math1960;
    sjt_math1951 = sjt_math1953 - sjt_math1954;
    sjt_dot1277 = _parent;
    sjt_math1965 = (sjt_dot1277)->m03;
    sjt_dot1278 = _parent;
    sjt_math1966 = (sjt_dot1278)->m10;
    sjt_math1963 = sjt_math1965 * sjt_math1966;
    sjt_dot1279 = _parent;
    sjt_math1964 = (sjt_dot1279)->m22;
    sjt_math1952 = sjt_math1963 * sjt_math1964;
    sjt_math1949 = sjt_math1951 + sjt_math1952;
    sjt_dot1280 = _parent;
    sjt_math1969 = (sjt_dot1280)->m00;
    sjt_dot1281 = _parent;
    sjt_math1970 = (sjt_dot1281)->m13;
    sjt_math1967 = sjt_math1969 * sjt_math1970;
    sjt_dot1282 = _parent;
    sjt_math1968 = (sjt_dot1282)->m22;
    sjt_math1950 = sjt_math1967 * sjt_math1968;
    sjt_math1947 = sjt_math1949 - sjt_math1950;
    sjt_dot1283 = _parent;
    sjt_math1973 = (sjt_dot1283)->m02;
    sjt_dot1284 = _parent;
    sjt_math1974 = (sjt_dot1284)->m10;
    sjt_math1971 = sjt_math1973 * sjt_math1974;
    sjt_dot1285 = _parent;
    sjt_math1972 = (sjt_dot1285)->m23;
    sjt_math1948 = sjt_math1971 * sjt_math1972;
    sjt_math1945 = sjt_math1947 - sjt_math1948;
    sjt_dot1286 = _parent;
    sjt_math1977 = (sjt_dot1286)->m00;
    sjt_dot1287 = _parent;
    sjt_math1978 = (sjt_dot1287)->m12;
    sjt_math1975 = sjt_math1977 * sjt_math1978;
    sjt_dot1288 = _parent;
    sjt_math1976 = (sjt_dot1288)->m23;
    sjt_math1946 = sjt_math1975 * sjt_math1976;
    sjv_t.m13 = sjt_math1945 + sjt_math1946;
    sjt_dot1289 = _parent;
    sjt_math1991 = (sjt_dot1289)->m11;
    sjt_dot1290 = _parent;
    sjt_math1992 = (sjt_dot1290)->m23;
    sjt_math1989 = sjt_math1991 * sjt_math1992;
    sjt_dot1291 = _parent;
    sjt_math1990 = (sjt_dot1291)->m30;
    sjt_math1987 = sjt_math1989 * sjt_math1990;
    sjt_dot1292 = _parent;
    sjt_math1995 = (sjt_dot1292)->m13;
    sjt_dot1293 = _parent;
    sjt_math1996 = (sjt_dot1293)->m21;
    sjt_math1993 = sjt_math1995 * sjt_math1996;
    sjt_dot1294 = _parent;
    sjt_math1994 = (sjt_dot1294)->m30;
    sjt_math1988 = sjt_math1993 * sjt_math1994;
    sjt_math1985 = sjt_math1987 - sjt_math1988;
    sjt_dot1295 = _parent;
    sjt_math1999 = (sjt_dot1295)->m13;
    sjt_dot1296 = _parent;
    sjt_math2000 = (sjt_dot1296)->m20;
    sjt_math1997 = sjt_math1999 * sjt_math2000;
    sjt_dot1297 = _parent;
    sjt_math1998 = (sjt_dot1297)->m31;
    sjt_math1986 = sjt_math1997 * sjt_math1998;
    sjt_math1983 = sjt_math1985 + sjt_math1986;
    sjt_dot1298 = _parent;
    sjt_math2003 = (sjt_dot1298)->m10;
    sjt_dot1299 = _parent;
    sjt_math2004 = (sjt_dot1299)->m23;
    sjt_math2001 = sjt_math2003 * sjt_math2004;
    sjt_dot1300 = _parent;
    sjt_math2002 = (sjt_dot1300)->m31;
    sjt_math1984 = sjt_math2001 * sjt_math2002;
    sjt_math1981 = sjt_math1983 - sjt_math1984;
    sjt_dot1301 = _parent;
    sjt_math2007 = (sjt_dot1301)->m11;
    sjt_dot1302 = _parent;
    sjt_math2008 = (sjt_dot1302)->m20;
    sjt_math2005 = sjt_math2007 * sjt_math2008;
    sjt_dot1303 = _parent;
    sjt_math2006 = (sjt_dot1303)->m33;
    sjt_math1982 = sjt_math2005 * sjt_math2006;
    sjt_math1979 = sjt_math1981 - sjt_math1982;
    sjt_dot1304 = _parent;
    sjt_math2011 = (sjt_dot1304)->m10;
    sjt_dot1305 = _parent;
    sjt_math2012 = (sjt_dot1305)->m21;
    sjt_math2009 = sjt_math2011 * sjt_math2012;
    sjt_dot1306 = _parent;
    sjt_math2010 = (sjt_dot1306)->m33;
    sjt_math1980 = sjt_math2009 * sjt_math2010;
    sjv_t.m20 = sjt_math1979 + sjt_math1980;
    sjt_dot1307 = _parent;
    sjt_math2025 = (sjt_dot1307)->m03;
    sjt_dot1308 = _parent;
    sjt_math2026 = (sjt_dot1308)->m21;
    sjt_math2023 = sjt_math2025 * sjt_math2026;
    sjt_dot1309 = _parent;
    sjt_math2024 = (sjt_dot1309)->m30;
    sjt_math2021 = sjt_math2023 * sjt_math2024;
    sjt_dot1310 = _parent;
    sjt_math2029 = (sjt_dot1310)->m01;
    sjt_dot1311 = _parent;
    sjt_math2030 = (sjt_dot1311)->m23;
    sjt_math2027 = sjt_math2029 * sjt_math2030;
    sjt_dot1312 = _parent;
    sjt_math2028 = (sjt_dot1312)->m30;
    sjt_math2022 = sjt_math2027 * sjt_math2028;
    sjt_math2019 = sjt_math2021 - sjt_math2022;
    sjt_dot1313 = _parent;
    sjt_math2033 = (sjt_dot1313)->m03;
    sjt_dot1314 = _parent;
    sjt_math2034 = (sjt_dot1314)->m20;
    sjt_math2031 = sjt_math2033 * sjt_math2034;
    sjt_dot1315 = _parent;
    sjt_math2032 = (sjt_dot1315)->m31;
    sjt_math2020 = sjt_math2031 * sjt_math2032;
    sjt_math2017 = sjt_math2019 - sjt_math2020;
    sjt_dot1316 = _parent;
    sjt_math2037 = (sjt_dot1316)->m00;
    sjt_dot1317 = _parent;
    sjt_math2038 = (sjt_dot1317)->m23;
    sjt_math2035 = sjt_math2037 * sjt_math2038;
    sjt_dot1318 = _parent;
    sjt_math2036 = (sjt_dot1318)->m31;
    sjt_math2018 = sjt_math2035 * sjt_math2036;
    sjt_math2015 = sjt_math2017 + sjt_math2018;
    sjt_dot1319 = _parent;
    sjt_math2041 = (sjt_dot1319)->m01;
    sjt_dot1320 = _parent;
    sjt_math2042 = (sjt_dot1320)->m20;
    sjt_math2039 = sjt_math2041 * sjt_math2042;
    sjt_dot1321 = _parent;
    sjt_math2040 = (sjt_dot1321)->m33;
    sjt_math2016 = sjt_math2039 * sjt_math2040;
    sjt_math2013 = sjt_math2015 + sjt_math2016;
    sjt_dot1322 = _parent;
    sjt_math2045 = (sjt_dot1322)->m00;
    sjt_dot1323 = _parent;
    sjt_math2046 = (sjt_dot1323)->m21;
    sjt_math2043 = sjt_math2045 * sjt_math2046;
    sjt_dot1324 = _parent;
    sjt_math2044 = (sjt_dot1324)->m33;
    sjt_math2014 = sjt_math2043 * sjt_math2044;
    sjv_t.m21 = sjt_math2013 - sjt_math2014;
    sjt_dot1325 = _parent;
    sjt_math2059 = (sjt_dot1325)->m01;
    sjt_dot1326 = _parent;
    sjt_math2060 = (sjt_dot1326)->m13;
    sjt_math2057 = sjt_math2059 * sjt_math2060;
    sjt_dot1327 = _parent;
    sjt_math2058 = (sjt_dot1327)->m30;
    sjt_math2055 = sjt_math2057 * sjt_math2058;
    sjt_dot1328 = _parent;
    sjt_math2063 = (sjt_dot1328)->m03;
    sjt_dot1329 = _parent;
    sjt_math2064 = (sjt_dot1329)->m11;
    sjt_math2061 = sjt_math2063 * sjt_math2064;
    sjt_dot1330 = _parent;
    sjt_math2062 = (sjt_dot1330)->m30;
    sjt_math2056 = sjt_math2061 * sjt_math2062;
    sjt_math2053 = sjt_math2055 - sjt_math2056;
    sjt_dot1331 = _parent;
    sjt_math2067 = (sjt_dot1331)->m03;
    sjt_dot1332 = _parent;
    sjt_math2068 = (sjt_dot1332)->m10;
    sjt_math2065 = sjt_math2067 * sjt_math2068;
    sjt_dot1333 = _parent;
    sjt_math2066 = (sjt_dot1333)->m31;
    sjt_math2054 = sjt_math2065 * sjt_math2066;
    sjt_math2051 = sjt_math2053 + sjt_math2054;
    sjt_dot1334 = _parent;
    sjt_math2071 = (sjt_dot1334)->m00;
    sjt_dot1335 = _parent;
    sjt_math2072 = (sjt_dot1335)->m13;
    sjt_math2069 = sjt_math2071 * sjt_math2072;
    sjt_dot1336 = _parent;
    sjt_math2070 = (sjt_dot1336)->m31;
    sjt_math2052 = sjt_math2069 * sjt_math2070;
    sjt_math2049 = sjt_math2051 - sjt_math2052;
    sjt_dot1337 = _parent;
    sjt_math2075 = (sjt_dot1337)->m01;
    sjt_dot1338 = _parent;
    sjt_math2076 = (sjt_dot1338)->m10;
    sjt_math2073 = sjt_math2075 * sjt_math2076;
    sjt_dot1339 = _parent;
    sjt_math2074 = (sjt_dot1339)->m33;
    sjt_math2050 = sjt_math2073 * sjt_math2074;
    sjt_math2047 = sjt_math2049 - sjt_math2050;
    sjt_dot1340 = _parent;
    sjt_math2079 = (sjt_dot1340)->m00;
    sjt_dot1341 = _parent;
    sjt_math2080 = (sjt_dot1341)->m11;
    sjt_math2077 = sjt_math2079 * sjt_math2080;
    sjt_dot1342 = _parent;
    sjt_math2078 = (sjt_dot1342)->m33;
    sjt_math2048 = sjt_math2077 * sjt_math2078;
    sjv_t.m22 = sjt_math2047 + sjt_math2048;
    sjt_dot1343 = _parent;
    sjt_math2093 = (sjt_dot1343)->m03;
    sjt_dot1344 = _parent;
    sjt_math2094 = (sjt_dot1344)->m11;
    sjt_math2091 = sjt_math2093 * sjt_math2094;
    sjt_dot1345 = _parent;
    sjt_math2092 = (sjt_dot1345)->m20;
    sjt_math2089 = sjt_math2091 * sjt_math2092;
    sjt_dot1346 = _parent;
    sjt_math2097 = (sjt_dot1346)->m01;
    sjt_dot1347 = _parent;
    sjt_math2098 = (sjt_dot1347)->m13;
    sjt_math2095 = sjt_math2097 * sjt_math2098;
    sjt_dot1348 = _parent;
    sjt_math2096 = (sjt_dot1348)->m20;
    sjt_math2090 = sjt_math2095 * sjt_math2096;
    sjt_math2087 = sjt_math2089 - sjt_math2090;
    sjt_dot1349 = _parent;
    sjt_math2101 = (sjt_dot1349)->m03;
    sjt_dot1350 = _parent;
    sjt_math2102 = (sjt_dot1350)->m10;
    sjt_math2099 = sjt_math2101 * sjt_math2102;
    sjt_dot1351 = _parent;
    sjt_math2100 = (sjt_dot1351)->m21;
    sjt_math2088 = sjt_math2099 * sjt_math2100;
    sjt_math2085 = sjt_math2087 - sjt_math2088;
    sjt_dot1352 = _parent;
    sjt_math2105 = (sjt_dot1352)->m00;
    sjt_dot1353 = _parent;
    sjt_math2106 = (sjt_dot1353)->m13;
    sjt_math2103 = sjt_math2105 * sjt_math2106;
    sjt_dot1354 = _parent;
    sjt_math2104 = (sjt_dot1354)->m21;
    sjt_math2086 = sjt_math2103 * sjt_math2104;
    sjt_math2083 = sjt_math2085 + sjt_math2086;
    sjt_dot1355 = _parent;
    sjt_math2109 = (sjt_dot1355)->m01;
    sjt_dot1356 = _parent;
    sjt_math2110 = (sjt_dot1356)->m10;
    sjt_math2107 = sjt_math2109 * sjt_math2110;
    sjt_dot1357 = _parent;
    sjt_math2108 = (sjt_dot1357)->m23;
    sjt_math2084 = sjt_math2107 * sjt_math2108;
    sjt_math2081 = sjt_math2083 + sjt_math2084;
    sjt_dot1358 = _parent;
    sjt_math2113 = (sjt_dot1358)->m00;
    sjt_dot1359 = _parent;
    sjt_math2114 = (sjt_dot1359)->m11;
    sjt_math2111 = sjt_math2113 * sjt_math2114;
    sjt_dot1360 = _parent;
    sjt_math2112 = (sjt_dot1360)->m23;
    sjt_math2082 = sjt_math2111 * sjt_math2112;
    sjv_t.m23 = sjt_math2081 - sjt_math2082;
    sjt_dot1361 = _parent;
    sjt_math2127 = (sjt_dot1361)->m12;
    sjt_dot1362 = _parent;
    sjt_math2128 = (sjt_dot1362)->m21;
    sjt_math2125 = sjt_math2127 * sjt_math2128;
    sjt_dot1363 = _parent;
    sjt_math2126 = (sjt_dot1363)->m30;
    sjt_math2123 = sjt_math2125 * sjt_math2126;
    sjt_dot1364 = _parent;
    sjt_math2131 = (sjt_dot1364)->m11;
    sjt_dot1365 = _parent;
    sjt_math2132 = (sjt_dot1365)->m22;
    sjt_math2129 = sjt_math2131 * sjt_math2132;
    sjt_dot1366 = _parent;
    sjt_math2130 = (sjt_dot1366)->m30;
    sjt_math2124 = sjt_math2129 * sjt_math2130;
    sjt_math2121 = sjt_math2123 - sjt_math2124;
    sjt_dot1367 = _parent;
    sjt_math2135 = (sjt_dot1367)->m12;
    sjt_dot1368 = _parent;
    sjt_math2136 = (sjt_dot1368)->m20;
    sjt_math2133 = sjt_math2135 * sjt_math2136;
    sjt_dot1369 = _parent;
    sjt_math2134 = (sjt_dot1369)->m31;
    sjt_math2122 = sjt_math2133 * sjt_math2134;
    sjt_math2119 = sjt_math2121 - sjt_math2122;
    sjt_dot1370 = _parent;
    sjt_math2139 = (sjt_dot1370)->m10;
    sjt_dot1371 = _parent;
    sjt_math2140 = (sjt_dot1371)->m22;
    sjt_math2137 = sjt_math2139 * sjt_math2140;
    sjt_dot1372 = _parent;
    sjt_math2138 = (sjt_dot1372)->m31;
    sjt_math2120 = sjt_math2137 * sjt_math2138;
    sjt_math2117 = sjt_math2119 + sjt_math2120;
    sjt_dot1373 = _parent;
    sjt_math2143 = (sjt_dot1373)->m11;
    sjt_dot1374 = _parent;
    sjt_math2144 = (sjt_dot1374)->m20;
    sjt_math2141 = sjt_math2143 * sjt_math2144;
    sjt_dot1375 = _parent;
    sjt_math2142 = (sjt_dot1375)->m32;
    sjt_math2118 = sjt_math2141 * sjt_math2142;
    sjt_math2115 = sjt_math2117 + sjt_math2118;
    sjt_dot1376 = _parent;
    sjt_math2147 = (sjt_dot1376)->m10;
    sjt_dot1377 = _parent;
    sjt_math2148 = (sjt_dot1377)->m21;
    sjt_math2145 = sjt_math2147 * sjt_math2148;
    sjt_dot1378 = _parent;
    sjt_math2146 = (sjt_dot1378)->m32;
    sjt_math2116 = sjt_math2145 * sjt_math2146;
    sjv_t.m30 = sjt_math2115 - sjt_math2116;
    sjt_dot1379 = _parent;
    sjt_math2161 = (sjt_dot1379)->m01;
    sjt_dot1380 = _parent;
    sjt_math2162 = (sjt_dot1380)->m22;
    sjt_math2159 = sjt_math2161 * sjt_math2162;
    sjt_dot1381 = _parent;
    sjt_math2160 = (sjt_dot1381)->m30;
    sjt_math2157 = sjt_math2159 * sjt_math2160;
    sjt_dot1382 = _parent;
    sjt_math2165 = (sjt_dot1382)->m02;
    sjt_dot1383 = _parent;
    sjt_math2166 = (sjt_dot1383)->m21;
    sjt_math2163 = sjt_math2165 * sjt_math2166;
    sjt_dot1384 = _parent;
    sjt_math2164 = (sjt_dot1384)->m30;
    sjt_math2158 = sjt_math2163 * sjt_math2164;
    sjt_math2155 = sjt_math2157 - sjt_math2158;
    sjt_dot1385 = _parent;
    sjt_math2169 = (sjt_dot1385)->m02;
    sjt_dot1386 = _parent;
    sjt_math2170 = (sjt_dot1386)->m20;
    sjt_math2167 = sjt_math2169 * sjt_math2170;
    sjt_dot1387 = _parent;
    sjt_math2168 = (sjt_dot1387)->m31;
    sjt_math2156 = sjt_math2167 * sjt_math2168;
    sjt_math2153 = sjt_math2155 + sjt_math2156;
    sjt_dot1388 = _parent;
    sjt_math2173 = (sjt_dot1388)->m00;
    sjt_dot1389 = _parent;
    sjt_math2174 = (sjt_dot1389)->m22;
    sjt_math2171 = sjt_math2173 * sjt_math2174;
    sjt_dot1390 = _parent;
    sjt_math2172 = (sjt_dot1390)->m31;
    sjt_math2154 = sjt_math2171 * sjt_math2172;
    sjt_math2151 = sjt_math2153 - sjt_math2154;
    sjt_dot1391 = _parent;
    sjt_math2177 = (sjt_dot1391)->m01;
    sjt_dot1392 = _parent;
    sjt_math2178 = (sjt_dot1392)->m20;
    sjt_math2175 = sjt_math2177 * sjt_math2178;
    sjt_dot1393 = _parent;
    sjt_math2176 = (sjt_dot1393)->m32;
    sjt_math2152 = sjt_math2175 * sjt_math2176;
    sjt_math2149 = sjt_math2151 - sjt_math2152;
    sjt_dot1394 = _parent;
    sjt_math2181 = (sjt_dot1394)->m00;
    sjt_dot1395 = _parent;
    sjt_math2182 = (sjt_dot1395)->m21;
    sjt_math2179 = sjt_math2181 * sjt_math2182;
    sjt_dot1396 = _parent;
    sjt_math2180 = (sjt_dot1396)->m32;
    sjt_math2150 = sjt_math2179 * sjt_math2180;
    sjv_t.m31 = sjt_math2149 + sjt_math2150;
    sjt_dot1397 = _parent;
    sjt_math2195 = (sjt_dot1397)->m02;
    sjt_dot1398 = _parent;
    sjt_math2196 = (sjt_dot1398)->m11;
    sjt_math2193 = sjt_math2195 * sjt_math2196;
    sjt_dot1399 = _parent;
    sjt_math2194 = (sjt_dot1399)->m30;
    sjt_math2191 = sjt_math2193 * sjt_math2194;
    sjt_dot1400 = _parent;
    sjt_math2199 = (sjt_dot1400)->m01;
    sjt_dot1401 = _parent;
    sjt_math2200 = (sjt_dot1401)->m12;
    sjt_math2197 = sjt_math2199 * sjt_math2200;
    sjt_dot1402 = _parent;
    sjt_math2198 = (sjt_dot1402)->m30;
    sjt_math2192 = sjt_math2197 * sjt_math2198;
    sjt_math2189 = sjt_math2191 - sjt_math2192;
    sjt_dot1403 = _parent;
    sjt_math2203 = (sjt_dot1403)->m02;
    sjt_dot1404 = _parent;
    sjt_math2204 = (sjt_dot1404)->m10;
    sjt_math2201 = sjt_math2203 * sjt_math2204;
    sjt_dot1405 = _parent;
    sjt_math2202 = (sjt_dot1405)->m31;
    sjt_math2190 = sjt_math2201 * sjt_math2202;
    sjt_math2187 = sjt_math2189 - sjt_math2190;
    sjt_dot1406 = _parent;
    sjt_math2207 = (sjt_dot1406)->m00;
    sjt_dot1407 = _parent;
    sjt_math2208 = (sjt_dot1407)->m12;
    sjt_math2205 = sjt_math2207 * sjt_math2208;
    sjt_dot1408 = _parent;
    sjt_math2206 = (sjt_dot1408)->m31;
    sjt_math2188 = sjt_math2205 * sjt_math2206;
    sjt_math2185 = sjt_math2187 + sjt_math2188;
    sjt_dot1409 = _parent;
    sjt_math2211 = (sjt_dot1409)->m01;
    sjt_dot1410 = _parent;
    sjt_math2212 = (sjt_dot1410)->m10;
    sjt_math2209 = sjt_math2211 * sjt_math2212;
    sjt_dot1411 = _parent;
    sjt_math2210 = (sjt_dot1411)->m32;
    sjt_math2186 = sjt_math2209 * sjt_math2210;
    sjt_math2183 = sjt_math2185 + sjt_math2186;
    sjt_dot1412 = _parent;
    sjt_math2215 = (sjt_dot1412)->m00;
    sjt_dot1413 = _parent;
    sjt_math2216 = (sjt_dot1413)->m11;
    sjt_math2213 = sjt_math2215 * sjt_math2216;
    sjt_dot1414 = _parent;
    sjt_math2214 = (sjt_dot1414)->m32;
    sjt_math2184 = sjt_math2213 * sjt_math2214;
    sjv_t.m32 = sjt_math2183 - sjt_math2184;
    sjt_dot1415 = _parent;
    sjt_math2229 = (sjt_dot1415)->m01;
    sjt_dot1416 = _parent;
    sjt_math2230 = (sjt_dot1416)->m12;
    sjt_math2227 = sjt_math2229 * sjt_math2230;
    sjt_dot1417 = _parent;
    sjt_math2228 = (sjt_dot1417)->m20;
    sjt_math2225 = sjt_math2227 * sjt_math2228;
    sjt_dot1418 = _parent;
    sjt_math2233 = (sjt_dot1418)->m02;
    sjt_dot1419 = _parent;
    sjt_math2234 = (sjt_dot1419)->m11;
    sjt_math2231 = sjt_math2233 * sjt_math2234;
    sjt_dot1420 = _parent;
    sjt_math2232 = (sjt_dot1420)->m20;
    sjt_math2226 = sjt_math2231 * sjt_math2232;
    sjt_math2223 = sjt_math2225 - sjt_math2226;
    sjt_dot1421 = _parent;
    sjt_math2237 = (sjt_dot1421)->m02;
    sjt_dot1422 = _parent;
    sjt_math2238 = (sjt_dot1422)->m10;
    sjt_math2235 = sjt_math2237 * sjt_math2238;
    sjt_dot1423 = _parent;
    sjt_math2236 = (sjt_dot1423)->m21;
    sjt_math2224 = sjt_math2235 * sjt_math2236;
    sjt_math2221 = sjt_math2223 + sjt_math2224;
    sjt_dot1424 = _parent;
    sjt_math2241 = (sjt_dot1424)->m00;
    sjt_dot1425 = _parent;
    sjt_math2242 = (sjt_dot1425)->m12;
    sjt_math2239 = sjt_math2241 * sjt_math2242;
    sjt_dot1426 = _parent;
    sjt_math2240 = (sjt_dot1426)->m21;
    sjt_math2222 = sjt_math2239 * sjt_math2240;
    sjt_math2219 = sjt_math2221 - sjt_math2222;
    sjt_dot1427 = _parent;
    sjt_math2245 = (sjt_dot1427)->m01;
    sjt_dot1428 = _parent;
    sjt_math2246 = (sjt_dot1428)->m10;
    sjt_math2243 = sjt_math2245 * sjt_math2246;
    sjt_dot1429 = _parent;
    sjt_math2244 = (sjt_dot1429)->m22;
    sjt_math2220 = sjt_math2243 * sjt_math2244;
    sjt_math2217 = sjt_math2219 - sjt_math2220;
    sjt_dot1430 = _parent;
    sjt_math2249 = (sjt_dot1430)->m00;
    sjt_dot1431 = _parent;
    sjt_math2250 = (sjt_dot1431)->m11;
    sjt_math2247 = sjt_math2249 * sjt_math2250;
    sjt_dot1432 = _parent;
    sjt_math2248 = (sjt_dot1432)->m22;
    sjt_math2218 = sjt_math2247 * sjt_math2248;
    sjv_t.m33 = sjt_math2217 + sjt_math2218;
    sjf_mat4(&sjv_t);
    sjt_parent130 = &sjv_t;
    sjt_math2251 = 1.0f;
    sjf_mat4_determinant(_parent, &sjt_math2252);
    sjt_functionParam233 = sjt_math2251 / sjt_math2252;
    sjf_mat4_multiplyf32_heap(sjt_parent130, sjt_functionParam233, _return);

    if (sjv_t._refCount == 1) { sjf_mat4_destroy(&sjv_t); }
}

void sjf_mat4_lookatlh(sjs_vec3* camera, sjs_vec3* target, sjs_vec3* up, sjs_mat4* _return) {
    sjs_vec3 sjt_call5 = { -1 };
    sjs_vec3* sjt_dot175 = 0;
    sjs_vec3* sjt_dot176 = 0;
    sjs_vec3* sjt_dot177 = 0;
    sjs_vec3* sjt_dot178 = 0;
    sjs_vec3* sjt_dot179 = 0;
    sjs_vec3* sjt_dot180 = 0;
    sjs_vec3* sjt_dot181 = 0;
    sjs_vec3* sjt_dot182 = 0;
    sjs_vec3* sjt_dot183 = 0;
    sjs_vec3* sjt_functionParam28 = 0;
    sjs_vec3* sjt_functionParam31 = 0;
    sjs_vec3* sjt_functionParam32 = 0;
    sjs_vec3* sjt_functionParam33 = 0;
    sjs_vec3* sjt_functionParam34 = 0;
    sjs_vec3* sjt_functionParam35 = 0;
    float sjt_math183;
    float sjt_math184;
    float sjt_math195;
    float sjt_math196;
    float sjt_math197;
    float sjt_math198;
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

    sjt_parent26 = target;
    sjt_functionParam28 = camera;
    sjf_vec3_subtract(sjt_parent26, sjt_functionParam28, &sjv_temp);
    sjt_parent27 = &sjv_temp;
    sjf_vec3_normalize(sjt_parent27, &sjv_zaxis);
    sjt_parent29 = up;
    sjt_functionParam31 = &sjv_zaxis;
    sjf_vec3_cross(sjt_parent29, sjt_functionParam31, &sjt_call5);
    sjt_parent28 = &sjt_call5;
    sjf_vec3_normalize(sjt_parent28, &sjv_xaxis);
    sjt_parent30 = &sjv_zaxis;
    sjt_functionParam32 = &sjv_xaxis;
    sjf_vec3_cross(sjt_parent30, sjt_functionParam32, &sjv_yaxis);
    _return->_refCount = 1;
    sjt_dot175 = &sjv_xaxis;
    _return->m00 = (sjt_dot175)->x;
    sjt_dot176 = &sjv_yaxis;
    _return->m01 = (sjt_dot176)->x;
    sjt_dot177 = &sjv_zaxis;
    _return->m02 = (sjt_dot177)->x;
    _return->m03 = 0.0f;
    sjt_dot178 = &sjv_xaxis;
    _return->m10 = (sjt_dot178)->y;
    sjt_dot179 = &sjv_yaxis;
    _return->m11 = (sjt_dot179)->y;
    sjt_dot180 = &sjv_zaxis;
    _return->m12 = (sjt_dot180)->y;
    _return->m13 = 0.0f;
    sjt_dot181 = &sjv_xaxis;
    _return->m20 = (sjt_dot181)->z;
    sjt_dot182 = &sjv_yaxis;
    _return->m21 = (sjt_dot182)->z;
    sjt_dot183 = &sjv_zaxis;
    _return->m22 = (sjt_dot183)->z;
    _return->m23 = 0.0f;
    sjt_math183 = 0.0f;
    sjt_parent31 = &sjv_xaxis;
    sjt_functionParam33 = camera;
    sjf_vec3_dot(sjt_parent31, sjt_functionParam33, &sjt_math184);
    _return->m30 = sjt_math183 - sjt_math184;
    sjt_math195 = 0.0f;
    sjt_parent32 = &sjv_yaxis;
    sjt_functionParam34 = camera;
    sjf_vec3_dot(sjt_parent32, sjt_functionParam34, &sjt_math196);
    _return->m31 = sjt_math195 - sjt_math196;
    sjt_math197 = 0.0f;
    sjt_parent33 = &sjv_zaxis;
    sjt_functionParam35 = camera;
    sjf_vec3_dot(sjt_parent33, sjt_functionParam35, &sjt_math198);
    _return->m32 = sjt_math197 - sjt_math198;
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
    sjs_vec3* sjt_dot190 = 0;
    sjs_vec3* sjt_dot191 = 0;
    sjs_vec3* sjt_dot192 = 0;
    sjs_vec3* sjt_dot193 = 0;
    sjs_vec3* sjt_dot194 = 0;
    sjs_vec3* sjt_dot195 = 0;
    sjs_vec3* sjt_dot196 = 0;
    sjs_vec3* sjt_dot197 = 0;
    sjs_vec3* sjt_dot198 = 0;
    sjs_vec3* sjt_functionParam36 = 0;
    sjs_vec3* sjt_functionParam37 = 0;
    sjs_vec3* sjt_functionParam38 = 0;
    sjs_vec3* sjt_functionParam39 = 0;
    sjs_vec3* sjt_functionParam40 = 0;
    sjs_vec3* sjt_functionParam41 = 0;
    float sjt_math199;
    float sjt_math200;
    float sjt_math201;
    float sjt_math202;
    float sjt_math203;
    float sjt_math204;
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

    sjt_parent34 = target;
    sjt_functionParam36 = camera;
    sjf_vec3_subtract(sjt_parent34, sjt_functionParam36, &sjv_temp);
    sjt_parent35 = &sjv_temp;
    sjf_vec3_normalize(sjt_parent35, &sjv_zaxis);
    sjt_parent37 = up;
    sjt_functionParam37 = &sjv_zaxis;
    sjf_vec3_cross(sjt_parent37, sjt_functionParam37, &sjt_call6);
    sjt_parent36 = &sjt_call6;
    sjf_vec3_normalize(sjt_parent36, &sjv_xaxis);
    sjt_parent38 = &sjv_zaxis;
    sjt_functionParam38 = &sjv_xaxis;
    sjf_vec3_cross(sjt_parent38, sjt_functionParam38, &sjv_yaxis);
    (*_return) = (sjs_mat4*)malloc(sizeof(sjs_mat4));
    (*_return)->_refCount = 1;
    sjt_dot190 = &sjv_xaxis;
    (*_return)->m00 = (sjt_dot190)->x;
    sjt_dot191 = &sjv_yaxis;
    (*_return)->m01 = (sjt_dot191)->x;
    sjt_dot192 = &sjv_zaxis;
    (*_return)->m02 = (sjt_dot192)->x;
    (*_return)->m03 = 0.0f;
    sjt_dot193 = &sjv_xaxis;
    (*_return)->m10 = (sjt_dot193)->y;
    sjt_dot194 = &sjv_yaxis;
    (*_return)->m11 = (sjt_dot194)->y;
    sjt_dot195 = &sjv_zaxis;
    (*_return)->m12 = (sjt_dot195)->y;
    (*_return)->m13 = 0.0f;
    sjt_dot196 = &sjv_xaxis;
    (*_return)->m20 = (sjt_dot196)->z;
    sjt_dot197 = &sjv_yaxis;
    (*_return)->m21 = (sjt_dot197)->z;
    sjt_dot198 = &sjv_zaxis;
    (*_return)->m22 = (sjt_dot198)->z;
    (*_return)->m23 = 0.0f;
    sjt_math199 = 0.0f;
    sjt_parent39 = &sjv_xaxis;
    sjt_functionParam39 = camera;
    sjf_vec3_dot(sjt_parent39, sjt_functionParam39, &sjt_math200);
    (*_return)->m30 = sjt_math199 - sjt_math200;
    sjt_math201 = 0.0f;
    sjt_parent40 = &sjv_yaxis;
    sjt_functionParam40 = camera;
    sjf_vec3_dot(sjt_parent40, sjt_functionParam40, &sjt_math202);
    (*_return)->m31 = sjt_math201 - sjt_math202;
    sjt_math203 = 0.0f;
    sjt_parent41 = &sjv_zaxis;
    sjt_functionParam41 = camera;
    sjf_vec3_dot(sjt_parent41, sjt_functionParam41, &sjt_math204);
    (*_return)->m32 = sjt_math203 - sjt_math204;
    (*_return)->m33 = 1.0f;
    sjf_mat4_heap((*_return));

    if (sjt_call6._refCount == 1) { sjf_vec3_destroy(&sjt_call6); }
    if (sjv_temp._refCount == 1) { sjf_vec3_destroy(&sjv_temp); }
    if (sjv_xaxis._refCount == 1) { sjf_vec3_destroy(&sjv_xaxis); }
    if (sjv_yaxis._refCount == 1) { sjf_vec3_destroy(&sjv_yaxis); }
    if (sjv_zaxis._refCount == 1) { sjf_vec3_destroy(&sjv_zaxis); }
}

void sjf_mat4_multiply(sjs_mat4* _parent, sjs_mat4* m, sjs_mat4* _return) {
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

    _return->_refCount = 1;
    sjt_dot389 = m;
    sjt_math463 = (sjt_dot389)->m00;
    sjt_dot390 = _parent;
    sjt_math464 = (sjt_dot390)->m00;
    sjt_math461 = sjt_math463 * sjt_math464;
    sjt_dot391 = m;
    sjt_math465 = (sjt_dot391)->m01;
    sjt_dot392 = _parent;
    sjt_math466 = (sjt_dot392)->m10;
    sjt_math462 = sjt_math465 * sjt_math466;
    sjt_math459 = sjt_math461 + sjt_math462;
    sjt_dot393 = m;
    sjt_math467 = (sjt_dot393)->m02;
    sjt_dot394 = _parent;
    sjt_math468 = (sjt_dot394)->m20;
    sjt_math460 = sjt_math467 * sjt_math468;
    sjt_math457 = sjt_math459 + sjt_math460;
    sjt_dot395 = m;
    sjt_math469 = (sjt_dot395)->m03;
    sjt_dot396 = _parent;
    sjt_math470 = (sjt_dot396)->m30;
    sjt_math458 = sjt_math469 * sjt_math470;
    _return->m00 = sjt_math457 + sjt_math458;
    sjt_dot397 = m;
    sjt_math477 = (sjt_dot397)->m00;
    sjt_dot398 = _parent;
    sjt_math478 = (sjt_dot398)->m01;
    sjt_math475 = sjt_math477 * sjt_math478;
    sjt_dot399 = m;
    sjt_math479 = (sjt_dot399)->m01;
    sjt_dot400 = _parent;
    sjt_math480 = (sjt_dot400)->m11;
    sjt_math476 = sjt_math479 * sjt_math480;
    sjt_math473 = sjt_math475 + sjt_math476;
    sjt_dot401 = m;
    sjt_math481 = (sjt_dot401)->m02;
    sjt_dot402 = _parent;
    sjt_math482 = (sjt_dot402)->m21;
    sjt_math474 = sjt_math481 * sjt_math482;
    sjt_math471 = sjt_math473 + sjt_math474;
    sjt_dot403 = m;
    sjt_math483 = (sjt_dot403)->m03;
    sjt_dot404 = _parent;
    sjt_math484 = (sjt_dot404)->m31;
    sjt_math472 = sjt_math483 * sjt_math484;
    _return->m01 = sjt_math471 + sjt_math472;
    sjt_dot405 = m;
    sjt_math491 = (sjt_dot405)->m00;
    sjt_dot406 = _parent;
    sjt_math492 = (sjt_dot406)->m02;
    sjt_math489 = sjt_math491 * sjt_math492;
    sjt_dot407 = m;
    sjt_math493 = (sjt_dot407)->m01;
    sjt_dot408 = _parent;
    sjt_math494 = (sjt_dot408)->m12;
    sjt_math490 = sjt_math493 * sjt_math494;
    sjt_math487 = sjt_math489 + sjt_math490;
    sjt_dot409 = m;
    sjt_math495 = (sjt_dot409)->m02;
    sjt_dot410 = _parent;
    sjt_math496 = (sjt_dot410)->m22;
    sjt_math488 = sjt_math495 * sjt_math496;
    sjt_math485 = sjt_math487 + sjt_math488;
    sjt_dot411 = m;
    sjt_math497 = (sjt_dot411)->m03;
    sjt_dot412 = _parent;
    sjt_math498 = (sjt_dot412)->m32;
    sjt_math486 = sjt_math497 * sjt_math498;
    _return->m02 = sjt_math485 + sjt_math486;
    sjt_dot413 = m;
    sjt_math505 = (sjt_dot413)->m00;
    sjt_dot414 = _parent;
    sjt_math506 = (sjt_dot414)->m03;
    sjt_math503 = sjt_math505 * sjt_math506;
    sjt_dot415 = m;
    sjt_math507 = (sjt_dot415)->m01;
    sjt_dot416 = _parent;
    sjt_math508 = (sjt_dot416)->m13;
    sjt_math504 = sjt_math507 * sjt_math508;
    sjt_math501 = sjt_math503 + sjt_math504;
    sjt_dot417 = m;
    sjt_math509 = (sjt_dot417)->m02;
    sjt_dot418 = _parent;
    sjt_math510 = (sjt_dot418)->m23;
    sjt_math502 = sjt_math509 * sjt_math510;
    sjt_math499 = sjt_math501 + sjt_math502;
    sjt_dot419 = m;
    sjt_math511 = (sjt_dot419)->m03;
    sjt_dot420 = _parent;
    sjt_math512 = (sjt_dot420)->m33;
    sjt_math500 = sjt_math511 * sjt_math512;
    _return->m03 = sjt_math499 + sjt_math500;
    sjt_dot421 = m;
    sjt_math519 = (sjt_dot421)->m10;
    sjt_dot422 = _parent;
    sjt_math520 = (sjt_dot422)->m00;
    sjt_math517 = sjt_math519 * sjt_math520;
    sjt_dot423 = m;
    sjt_math521 = (sjt_dot423)->m11;
    sjt_dot424 = _parent;
    sjt_math522 = (sjt_dot424)->m10;
    sjt_math518 = sjt_math521 * sjt_math522;
    sjt_math515 = sjt_math517 + sjt_math518;
    sjt_dot425 = m;
    sjt_math523 = (sjt_dot425)->m12;
    sjt_dot426 = _parent;
    sjt_math524 = (sjt_dot426)->m20;
    sjt_math516 = sjt_math523 * sjt_math524;
    sjt_math513 = sjt_math515 + sjt_math516;
    sjt_dot427 = m;
    sjt_math525 = (sjt_dot427)->m13;
    sjt_dot428 = _parent;
    sjt_math526 = (sjt_dot428)->m30;
    sjt_math514 = sjt_math525 * sjt_math526;
    _return->m10 = sjt_math513 + sjt_math514;
    sjt_dot429 = m;
    sjt_math533 = (sjt_dot429)->m10;
    sjt_dot430 = _parent;
    sjt_math534 = (sjt_dot430)->m01;
    sjt_math531 = sjt_math533 * sjt_math534;
    sjt_dot431 = m;
    sjt_math535 = (sjt_dot431)->m11;
    sjt_dot432 = _parent;
    sjt_math536 = (sjt_dot432)->m11;
    sjt_math532 = sjt_math535 * sjt_math536;
    sjt_math529 = sjt_math531 + sjt_math532;
    sjt_dot433 = m;
    sjt_math537 = (sjt_dot433)->m12;
    sjt_dot434 = _parent;
    sjt_math538 = (sjt_dot434)->m21;
    sjt_math530 = sjt_math537 * sjt_math538;
    sjt_math527 = sjt_math529 + sjt_math530;
    sjt_dot435 = m;
    sjt_math539 = (sjt_dot435)->m13;
    sjt_dot436 = _parent;
    sjt_math540 = (sjt_dot436)->m31;
    sjt_math528 = sjt_math539 * sjt_math540;
    _return->m11 = sjt_math527 + sjt_math528;
    sjt_dot437 = m;
    sjt_math547 = (sjt_dot437)->m10;
    sjt_dot438 = _parent;
    sjt_math548 = (sjt_dot438)->m02;
    sjt_math545 = sjt_math547 * sjt_math548;
    sjt_dot439 = m;
    sjt_math549 = (sjt_dot439)->m11;
    sjt_dot440 = _parent;
    sjt_math550 = (sjt_dot440)->m12;
    sjt_math546 = sjt_math549 * sjt_math550;
    sjt_math543 = sjt_math545 + sjt_math546;
    sjt_dot441 = m;
    sjt_math551 = (sjt_dot441)->m12;
    sjt_dot442 = _parent;
    sjt_math552 = (sjt_dot442)->m22;
    sjt_math544 = sjt_math551 * sjt_math552;
    sjt_math541 = sjt_math543 + sjt_math544;
    sjt_dot443 = m;
    sjt_math553 = (sjt_dot443)->m13;
    sjt_dot444 = _parent;
    sjt_math554 = (sjt_dot444)->m32;
    sjt_math542 = sjt_math553 * sjt_math554;
    _return->m12 = sjt_math541 + sjt_math542;
    sjt_dot445 = m;
    sjt_math561 = (sjt_dot445)->m10;
    sjt_dot446 = _parent;
    sjt_math562 = (sjt_dot446)->m03;
    sjt_math559 = sjt_math561 * sjt_math562;
    sjt_dot447 = m;
    sjt_math563 = (sjt_dot447)->m11;
    sjt_dot448 = _parent;
    sjt_math564 = (sjt_dot448)->m13;
    sjt_math560 = sjt_math563 * sjt_math564;
    sjt_math557 = sjt_math559 + sjt_math560;
    sjt_dot449 = m;
    sjt_math565 = (sjt_dot449)->m12;
    sjt_dot450 = _parent;
    sjt_math566 = (sjt_dot450)->m23;
    sjt_math558 = sjt_math565 * sjt_math566;
    sjt_math555 = sjt_math557 + sjt_math558;
    sjt_dot451 = m;
    sjt_math567 = (sjt_dot451)->m13;
    sjt_dot452 = _parent;
    sjt_math568 = (sjt_dot452)->m33;
    sjt_math556 = sjt_math567 * sjt_math568;
    _return->m13 = sjt_math555 + sjt_math556;
    sjt_dot453 = m;
    sjt_math575 = (sjt_dot453)->m20;
    sjt_dot454 = _parent;
    sjt_math576 = (sjt_dot454)->m00;
    sjt_math573 = sjt_math575 * sjt_math576;
    sjt_dot455 = m;
    sjt_math577 = (sjt_dot455)->m21;
    sjt_dot456 = _parent;
    sjt_math578 = (sjt_dot456)->m10;
    sjt_math574 = sjt_math577 * sjt_math578;
    sjt_math571 = sjt_math573 + sjt_math574;
    sjt_dot457 = m;
    sjt_math579 = (sjt_dot457)->m22;
    sjt_dot458 = _parent;
    sjt_math580 = (sjt_dot458)->m20;
    sjt_math572 = sjt_math579 * sjt_math580;
    sjt_math569 = sjt_math571 + sjt_math572;
    sjt_dot459 = m;
    sjt_math581 = (sjt_dot459)->m23;
    sjt_dot460 = _parent;
    sjt_math582 = (sjt_dot460)->m30;
    sjt_math570 = sjt_math581 * sjt_math582;
    _return->m20 = sjt_math569 + sjt_math570;
    sjt_dot461 = m;
    sjt_math589 = (sjt_dot461)->m20;
    sjt_dot462 = _parent;
    sjt_math590 = (sjt_dot462)->m01;
    sjt_math587 = sjt_math589 * sjt_math590;
    sjt_dot463 = m;
    sjt_math591 = (sjt_dot463)->m21;
    sjt_dot464 = _parent;
    sjt_math592 = (sjt_dot464)->m11;
    sjt_math588 = sjt_math591 * sjt_math592;
    sjt_math585 = sjt_math587 + sjt_math588;
    sjt_dot465 = m;
    sjt_math593 = (sjt_dot465)->m22;
    sjt_dot466 = _parent;
    sjt_math594 = (sjt_dot466)->m21;
    sjt_math586 = sjt_math593 * sjt_math594;
    sjt_math583 = sjt_math585 + sjt_math586;
    sjt_dot467 = m;
    sjt_math595 = (sjt_dot467)->m23;
    sjt_dot468 = _parent;
    sjt_math596 = (sjt_dot468)->m31;
    sjt_math584 = sjt_math595 * sjt_math596;
    _return->m21 = sjt_math583 + sjt_math584;
    sjt_dot469 = m;
    sjt_math603 = (sjt_dot469)->m20;
    sjt_dot470 = _parent;
    sjt_math604 = (sjt_dot470)->m02;
    sjt_math601 = sjt_math603 * sjt_math604;
    sjt_dot471 = m;
    sjt_math605 = (sjt_dot471)->m21;
    sjt_dot472 = _parent;
    sjt_math606 = (sjt_dot472)->m12;
    sjt_math602 = sjt_math605 * sjt_math606;
    sjt_math599 = sjt_math601 + sjt_math602;
    sjt_dot473 = m;
    sjt_math607 = (sjt_dot473)->m22;
    sjt_dot474 = _parent;
    sjt_math608 = (sjt_dot474)->m22;
    sjt_math600 = sjt_math607 * sjt_math608;
    sjt_math597 = sjt_math599 + sjt_math600;
    sjt_dot475 = m;
    sjt_math609 = (sjt_dot475)->m23;
    sjt_dot476 = _parent;
    sjt_math610 = (sjt_dot476)->m32;
    sjt_math598 = sjt_math609 * sjt_math610;
    _return->m22 = sjt_math597 + sjt_math598;
    sjt_dot477 = m;
    sjt_math617 = (sjt_dot477)->m20;
    sjt_dot478 = _parent;
    sjt_math618 = (sjt_dot478)->m03;
    sjt_math615 = sjt_math617 * sjt_math618;
    sjt_dot479 = m;
    sjt_math619 = (sjt_dot479)->m21;
    sjt_dot480 = _parent;
    sjt_math620 = (sjt_dot480)->m13;
    sjt_math616 = sjt_math619 * sjt_math620;
    sjt_math613 = sjt_math615 + sjt_math616;
    sjt_dot481 = m;
    sjt_math621 = (sjt_dot481)->m22;
    sjt_dot482 = _parent;
    sjt_math622 = (sjt_dot482)->m23;
    sjt_math614 = sjt_math621 * sjt_math622;
    sjt_math611 = sjt_math613 + sjt_math614;
    sjt_dot483 = m;
    sjt_math623 = (sjt_dot483)->m23;
    sjt_dot484 = _parent;
    sjt_math624 = (sjt_dot484)->m33;
    sjt_math612 = sjt_math623 * sjt_math624;
    _return->m23 = sjt_math611 + sjt_math612;
    sjt_dot485 = m;
    sjt_math631 = (sjt_dot485)->m30;
    sjt_dot486 = _parent;
    sjt_math632 = (sjt_dot486)->m00;
    sjt_math629 = sjt_math631 * sjt_math632;
    sjt_dot487 = m;
    sjt_math633 = (sjt_dot487)->m31;
    sjt_dot488 = _parent;
    sjt_math634 = (sjt_dot488)->m10;
    sjt_math630 = sjt_math633 * sjt_math634;
    sjt_math627 = sjt_math629 + sjt_math630;
    sjt_dot489 = m;
    sjt_math635 = (sjt_dot489)->m32;
    sjt_dot490 = _parent;
    sjt_math636 = (sjt_dot490)->m20;
    sjt_math628 = sjt_math635 * sjt_math636;
    sjt_math625 = sjt_math627 + sjt_math628;
    sjt_dot491 = m;
    sjt_math637 = (sjt_dot491)->m33;
    sjt_dot492 = _parent;
    sjt_math638 = (sjt_dot492)->m30;
    sjt_math626 = sjt_math637 * sjt_math638;
    _return->m30 = sjt_math625 + sjt_math626;
    sjt_dot493 = m;
    sjt_math645 = (sjt_dot493)->m30;
    sjt_dot494 = _parent;
    sjt_math646 = (sjt_dot494)->m01;
    sjt_math643 = sjt_math645 * sjt_math646;
    sjt_dot495 = m;
    sjt_math647 = (sjt_dot495)->m31;
    sjt_dot496 = _parent;
    sjt_math648 = (sjt_dot496)->m11;
    sjt_math644 = sjt_math647 * sjt_math648;
    sjt_math641 = sjt_math643 + sjt_math644;
    sjt_dot497 = m;
    sjt_math649 = (sjt_dot497)->m32;
    sjt_dot498 = _parent;
    sjt_math650 = (sjt_dot498)->m21;
    sjt_math642 = sjt_math649 * sjt_math650;
    sjt_math639 = sjt_math641 + sjt_math642;
    sjt_dot499 = m;
    sjt_math651 = (sjt_dot499)->m33;
    sjt_dot500 = _parent;
    sjt_math652 = (sjt_dot500)->m31;
    sjt_math640 = sjt_math651 * sjt_math652;
    _return->m31 = sjt_math639 + sjt_math640;
    sjt_dot501 = m;
    sjt_math659 = (sjt_dot501)->m30;
    sjt_dot502 = _parent;
    sjt_math660 = (sjt_dot502)->m02;
    sjt_math657 = sjt_math659 * sjt_math660;
    sjt_dot503 = m;
    sjt_math661 = (sjt_dot503)->m31;
    sjt_dot504 = _parent;
    sjt_math662 = (sjt_dot504)->m12;
    sjt_math658 = sjt_math661 * sjt_math662;
    sjt_math655 = sjt_math657 + sjt_math658;
    sjt_dot505 = m;
    sjt_math663 = (sjt_dot505)->m32;
    sjt_dot506 = _parent;
    sjt_math664 = (sjt_dot506)->m22;
    sjt_math656 = sjt_math663 * sjt_math664;
    sjt_math653 = sjt_math655 + sjt_math656;
    sjt_dot507 = m;
    sjt_math665 = (sjt_dot507)->m33;
    sjt_dot508 = _parent;
    sjt_math666 = (sjt_dot508)->m32;
    sjt_math654 = sjt_math665 * sjt_math666;
    _return->m32 = sjt_math653 + sjt_math654;
    sjt_dot509 = m;
    sjt_math673 = (sjt_dot509)->m30;
    sjt_dot510 = _parent;
    sjt_math674 = (sjt_dot510)->m03;
    sjt_math671 = sjt_math673 * sjt_math674;
    sjt_dot511 = m;
    sjt_math675 = (sjt_dot511)->m31;
    sjt_dot512 = _parent;
    sjt_math676 = (sjt_dot512)->m13;
    sjt_math672 = sjt_math675 * sjt_math676;
    sjt_math669 = sjt_math671 + sjt_math672;
    sjt_dot513 = m;
    sjt_math677 = (sjt_dot513)->m32;
    sjt_dot514 = _parent;
    sjt_math678 = (sjt_dot514)->m23;
    sjt_math670 = sjt_math677 * sjt_math678;
    sjt_math667 = sjt_math669 + sjt_math670;
    sjt_dot515 = m;
    sjt_math679 = (sjt_dot515)->m33;
    sjt_dot516 = _parent;
    sjt_math680 = (sjt_dot516)->m33;
    sjt_math668 = sjt_math679 * sjt_math680;
    _return->m33 = sjt_math667 + sjt_math668;
    sjf_mat4(_return);
}

void sjf_mat4_multiply_heap(sjs_mat4* _parent, sjs_mat4* m, sjs_mat4** _return) {
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

    (*_return) = (sjs_mat4*)malloc(sizeof(sjs_mat4));
    (*_return)->_refCount = 1;
    sjt_dot517 = m;
    sjt_math687 = (sjt_dot517)->m00;
    sjt_dot518 = _parent;
    sjt_math688 = (sjt_dot518)->m00;
    sjt_math685 = sjt_math687 * sjt_math688;
    sjt_dot519 = m;
    sjt_math689 = (sjt_dot519)->m01;
    sjt_dot520 = _parent;
    sjt_math690 = (sjt_dot520)->m10;
    sjt_math686 = sjt_math689 * sjt_math690;
    sjt_math683 = sjt_math685 + sjt_math686;
    sjt_dot521 = m;
    sjt_math691 = (sjt_dot521)->m02;
    sjt_dot522 = _parent;
    sjt_math692 = (sjt_dot522)->m20;
    sjt_math684 = sjt_math691 * sjt_math692;
    sjt_math681 = sjt_math683 + sjt_math684;
    sjt_dot523 = m;
    sjt_math693 = (sjt_dot523)->m03;
    sjt_dot524 = _parent;
    sjt_math694 = (sjt_dot524)->m30;
    sjt_math682 = sjt_math693 * sjt_math694;
    (*_return)->m00 = sjt_math681 + sjt_math682;
    sjt_dot525 = m;
    sjt_math701 = (sjt_dot525)->m00;
    sjt_dot526 = _parent;
    sjt_math702 = (sjt_dot526)->m01;
    sjt_math699 = sjt_math701 * sjt_math702;
    sjt_dot527 = m;
    sjt_math703 = (sjt_dot527)->m01;
    sjt_dot528 = _parent;
    sjt_math704 = (sjt_dot528)->m11;
    sjt_math700 = sjt_math703 * sjt_math704;
    sjt_math697 = sjt_math699 + sjt_math700;
    sjt_dot529 = m;
    sjt_math705 = (sjt_dot529)->m02;
    sjt_dot530 = _parent;
    sjt_math706 = (sjt_dot530)->m21;
    sjt_math698 = sjt_math705 * sjt_math706;
    sjt_math695 = sjt_math697 + sjt_math698;
    sjt_dot531 = m;
    sjt_math707 = (sjt_dot531)->m03;
    sjt_dot532 = _parent;
    sjt_math708 = (sjt_dot532)->m31;
    sjt_math696 = sjt_math707 * sjt_math708;
    (*_return)->m01 = sjt_math695 + sjt_math696;
    sjt_dot533 = m;
    sjt_math715 = (sjt_dot533)->m00;
    sjt_dot534 = _parent;
    sjt_math716 = (sjt_dot534)->m02;
    sjt_math713 = sjt_math715 * sjt_math716;
    sjt_dot535 = m;
    sjt_math717 = (sjt_dot535)->m01;
    sjt_dot536 = _parent;
    sjt_math718 = (sjt_dot536)->m12;
    sjt_math714 = sjt_math717 * sjt_math718;
    sjt_math711 = sjt_math713 + sjt_math714;
    sjt_dot537 = m;
    sjt_math719 = (sjt_dot537)->m02;
    sjt_dot538 = _parent;
    sjt_math720 = (sjt_dot538)->m22;
    sjt_math712 = sjt_math719 * sjt_math720;
    sjt_math709 = sjt_math711 + sjt_math712;
    sjt_dot539 = m;
    sjt_math721 = (sjt_dot539)->m03;
    sjt_dot540 = _parent;
    sjt_math722 = (sjt_dot540)->m32;
    sjt_math710 = sjt_math721 * sjt_math722;
    (*_return)->m02 = sjt_math709 + sjt_math710;
    sjt_dot541 = m;
    sjt_math729 = (sjt_dot541)->m00;
    sjt_dot542 = _parent;
    sjt_math730 = (sjt_dot542)->m03;
    sjt_math727 = sjt_math729 * sjt_math730;
    sjt_dot543 = m;
    sjt_math731 = (sjt_dot543)->m01;
    sjt_dot544 = _parent;
    sjt_math732 = (sjt_dot544)->m13;
    sjt_math728 = sjt_math731 * sjt_math732;
    sjt_math725 = sjt_math727 + sjt_math728;
    sjt_dot545 = m;
    sjt_math733 = (sjt_dot545)->m02;
    sjt_dot546 = _parent;
    sjt_math734 = (sjt_dot546)->m23;
    sjt_math726 = sjt_math733 * sjt_math734;
    sjt_math723 = sjt_math725 + sjt_math726;
    sjt_dot547 = m;
    sjt_math735 = (sjt_dot547)->m03;
    sjt_dot548 = _parent;
    sjt_math736 = (sjt_dot548)->m33;
    sjt_math724 = sjt_math735 * sjt_math736;
    (*_return)->m03 = sjt_math723 + sjt_math724;
    sjt_dot549 = m;
    sjt_math743 = (sjt_dot549)->m10;
    sjt_dot550 = _parent;
    sjt_math744 = (sjt_dot550)->m00;
    sjt_math741 = sjt_math743 * sjt_math744;
    sjt_dot551 = m;
    sjt_math745 = (sjt_dot551)->m11;
    sjt_dot552 = _parent;
    sjt_math746 = (sjt_dot552)->m10;
    sjt_math742 = sjt_math745 * sjt_math746;
    sjt_math739 = sjt_math741 + sjt_math742;
    sjt_dot553 = m;
    sjt_math747 = (sjt_dot553)->m12;
    sjt_dot554 = _parent;
    sjt_math748 = (sjt_dot554)->m20;
    sjt_math740 = sjt_math747 * sjt_math748;
    sjt_math737 = sjt_math739 + sjt_math740;
    sjt_dot555 = m;
    sjt_math749 = (sjt_dot555)->m13;
    sjt_dot556 = _parent;
    sjt_math750 = (sjt_dot556)->m30;
    sjt_math738 = sjt_math749 * sjt_math750;
    (*_return)->m10 = sjt_math737 + sjt_math738;
    sjt_dot557 = m;
    sjt_math757 = (sjt_dot557)->m10;
    sjt_dot558 = _parent;
    sjt_math758 = (sjt_dot558)->m01;
    sjt_math755 = sjt_math757 * sjt_math758;
    sjt_dot559 = m;
    sjt_math759 = (sjt_dot559)->m11;
    sjt_dot560 = _parent;
    sjt_math760 = (sjt_dot560)->m11;
    sjt_math756 = sjt_math759 * sjt_math760;
    sjt_math753 = sjt_math755 + sjt_math756;
    sjt_dot561 = m;
    sjt_math761 = (sjt_dot561)->m12;
    sjt_dot562 = _parent;
    sjt_math762 = (sjt_dot562)->m21;
    sjt_math754 = sjt_math761 * sjt_math762;
    sjt_math751 = sjt_math753 + sjt_math754;
    sjt_dot563 = m;
    sjt_math763 = (sjt_dot563)->m13;
    sjt_dot564 = _parent;
    sjt_math764 = (sjt_dot564)->m31;
    sjt_math752 = sjt_math763 * sjt_math764;
    (*_return)->m11 = sjt_math751 + sjt_math752;
    sjt_dot565 = m;
    sjt_math771 = (sjt_dot565)->m10;
    sjt_dot566 = _parent;
    sjt_math772 = (sjt_dot566)->m02;
    sjt_math769 = sjt_math771 * sjt_math772;
    sjt_dot567 = m;
    sjt_math773 = (sjt_dot567)->m11;
    sjt_dot568 = _parent;
    sjt_math774 = (sjt_dot568)->m12;
    sjt_math770 = sjt_math773 * sjt_math774;
    sjt_math767 = sjt_math769 + sjt_math770;
    sjt_dot569 = m;
    sjt_math775 = (sjt_dot569)->m12;
    sjt_dot570 = _parent;
    sjt_math776 = (sjt_dot570)->m22;
    sjt_math768 = sjt_math775 * sjt_math776;
    sjt_math765 = sjt_math767 + sjt_math768;
    sjt_dot571 = m;
    sjt_math777 = (sjt_dot571)->m13;
    sjt_dot572 = _parent;
    sjt_math778 = (sjt_dot572)->m32;
    sjt_math766 = sjt_math777 * sjt_math778;
    (*_return)->m12 = sjt_math765 + sjt_math766;
    sjt_dot573 = m;
    sjt_math785 = (sjt_dot573)->m10;
    sjt_dot574 = _parent;
    sjt_math786 = (sjt_dot574)->m03;
    sjt_math783 = sjt_math785 * sjt_math786;
    sjt_dot575 = m;
    sjt_math787 = (sjt_dot575)->m11;
    sjt_dot576 = _parent;
    sjt_math788 = (sjt_dot576)->m13;
    sjt_math784 = sjt_math787 * sjt_math788;
    sjt_math781 = sjt_math783 + sjt_math784;
    sjt_dot577 = m;
    sjt_math789 = (sjt_dot577)->m12;
    sjt_dot578 = _parent;
    sjt_math790 = (sjt_dot578)->m23;
    sjt_math782 = sjt_math789 * sjt_math790;
    sjt_math779 = sjt_math781 + sjt_math782;
    sjt_dot579 = m;
    sjt_math791 = (sjt_dot579)->m13;
    sjt_dot580 = _parent;
    sjt_math792 = (sjt_dot580)->m33;
    sjt_math780 = sjt_math791 * sjt_math792;
    (*_return)->m13 = sjt_math779 + sjt_math780;
    sjt_dot581 = m;
    sjt_math799 = (sjt_dot581)->m20;
    sjt_dot582 = _parent;
    sjt_math800 = (sjt_dot582)->m00;
    sjt_math797 = sjt_math799 * sjt_math800;
    sjt_dot583 = m;
    sjt_math801 = (sjt_dot583)->m21;
    sjt_dot584 = _parent;
    sjt_math802 = (sjt_dot584)->m10;
    sjt_math798 = sjt_math801 * sjt_math802;
    sjt_math795 = sjt_math797 + sjt_math798;
    sjt_dot585 = m;
    sjt_math803 = (sjt_dot585)->m22;
    sjt_dot586 = _parent;
    sjt_math804 = (sjt_dot586)->m20;
    sjt_math796 = sjt_math803 * sjt_math804;
    sjt_math793 = sjt_math795 + sjt_math796;
    sjt_dot587 = m;
    sjt_math805 = (sjt_dot587)->m23;
    sjt_dot588 = _parent;
    sjt_math806 = (sjt_dot588)->m30;
    sjt_math794 = sjt_math805 * sjt_math806;
    (*_return)->m20 = sjt_math793 + sjt_math794;
    sjt_dot589 = m;
    sjt_math813 = (sjt_dot589)->m20;
    sjt_dot590 = _parent;
    sjt_math814 = (sjt_dot590)->m01;
    sjt_math811 = sjt_math813 * sjt_math814;
    sjt_dot591 = m;
    sjt_math815 = (sjt_dot591)->m21;
    sjt_dot592 = _parent;
    sjt_math816 = (sjt_dot592)->m11;
    sjt_math812 = sjt_math815 * sjt_math816;
    sjt_math809 = sjt_math811 + sjt_math812;
    sjt_dot593 = m;
    sjt_math817 = (sjt_dot593)->m22;
    sjt_dot594 = _parent;
    sjt_math818 = (sjt_dot594)->m21;
    sjt_math810 = sjt_math817 * sjt_math818;
    sjt_math807 = sjt_math809 + sjt_math810;
    sjt_dot595 = m;
    sjt_math819 = (sjt_dot595)->m23;
    sjt_dot596 = _parent;
    sjt_math820 = (sjt_dot596)->m31;
    sjt_math808 = sjt_math819 * sjt_math820;
    (*_return)->m21 = sjt_math807 + sjt_math808;
    sjt_dot597 = m;
    sjt_math827 = (sjt_dot597)->m20;
    sjt_dot598 = _parent;
    sjt_math828 = (sjt_dot598)->m02;
    sjt_math825 = sjt_math827 * sjt_math828;
    sjt_dot599 = m;
    sjt_math829 = (sjt_dot599)->m21;
    sjt_dot600 = _parent;
    sjt_math830 = (sjt_dot600)->m12;
    sjt_math826 = sjt_math829 * sjt_math830;
    sjt_math823 = sjt_math825 + sjt_math826;
    sjt_dot601 = m;
    sjt_math831 = (sjt_dot601)->m22;
    sjt_dot602 = _parent;
    sjt_math832 = (sjt_dot602)->m22;
    sjt_math824 = sjt_math831 * sjt_math832;
    sjt_math821 = sjt_math823 + sjt_math824;
    sjt_dot603 = m;
    sjt_math833 = (sjt_dot603)->m23;
    sjt_dot604 = _parent;
    sjt_math834 = (sjt_dot604)->m32;
    sjt_math822 = sjt_math833 * sjt_math834;
    (*_return)->m22 = sjt_math821 + sjt_math822;
    sjt_dot605 = m;
    sjt_math841 = (sjt_dot605)->m20;
    sjt_dot606 = _parent;
    sjt_math842 = (sjt_dot606)->m03;
    sjt_math839 = sjt_math841 * sjt_math842;
    sjt_dot607 = m;
    sjt_math843 = (sjt_dot607)->m21;
    sjt_dot608 = _parent;
    sjt_math844 = (sjt_dot608)->m13;
    sjt_math840 = sjt_math843 * sjt_math844;
    sjt_math837 = sjt_math839 + sjt_math840;
    sjt_dot609 = m;
    sjt_math845 = (sjt_dot609)->m22;
    sjt_dot610 = _parent;
    sjt_math846 = (sjt_dot610)->m23;
    sjt_math838 = sjt_math845 * sjt_math846;
    sjt_math835 = sjt_math837 + sjt_math838;
    sjt_dot611 = m;
    sjt_math847 = (sjt_dot611)->m23;
    sjt_dot612 = _parent;
    sjt_math848 = (sjt_dot612)->m33;
    sjt_math836 = sjt_math847 * sjt_math848;
    (*_return)->m23 = sjt_math835 + sjt_math836;
    sjt_dot613 = m;
    sjt_math855 = (sjt_dot613)->m30;
    sjt_dot614 = _parent;
    sjt_math856 = (sjt_dot614)->m00;
    sjt_math853 = sjt_math855 * sjt_math856;
    sjt_dot615 = m;
    sjt_math857 = (sjt_dot615)->m31;
    sjt_dot616 = _parent;
    sjt_math858 = (sjt_dot616)->m10;
    sjt_math854 = sjt_math857 * sjt_math858;
    sjt_math851 = sjt_math853 + sjt_math854;
    sjt_dot617 = m;
    sjt_math859 = (sjt_dot617)->m32;
    sjt_dot618 = _parent;
    sjt_math860 = (sjt_dot618)->m20;
    sjt_math852 = sjt_math859 * sjt_math860;
    sjt_math849 = sjt_math851 + sjt_math852;
    sjt_dot619 = m;
    sjt_math861 = (sjt_dot619)->m33;
    sjt_dot620 = _parent;
    sjt_math862 = (sjt_dot620)->m30;
    sjt_math850 = sjt_math861 * sjt_math862;
    (*_return)->m30 = sjt_math849 + sjt_math850;
    sjt_dot621 = m;
    sjt_math869 = (sjt_dot621)->m30;
    sjt_dot622 = _parent;
    sjt_math870 = (sjt_dot622)->m01;
    sjt_math867 = sjt_math869 * sjt_math870;
    sjt_dot623 = m;
    sjt_math871 = (sjt_dot623)->m31;
    sjt_dot624 = _parent;
    sjt_math872 = (sjt_dot624)->m11;
    sjt_math868 = sjt_math871 * sjt_math872;
    sjt_math865 = sjt_math867 + sjt_math868;
    sjt_dot625 = m;
    sjt_math873 = (sjt_dot625)->m32;
    sjt_dot626 = _parent;
    sjt_math874 = (sjt_dot626)->m21;
    sjt_math866 = sjt_math873 * sjt_math874;
    sjt_math863 = sjt_math865 + sjt_math866;
    sjt_dot627 = m;
    sjt_math875 = (sjt_dot627)->m33;
    sjt_dot628 = _parent;
    sjt_math876 = (sjt_dot628)->m31;
    sjt_math864 = sjt_math875 * sjt_math876;
    (*_return)->m31 = sjt_math863 + sjt_math864;
    sjt_dot629 = m;
    sjt_math883 = (sjt_dot629)->m30;
    sjt_dot630 = _parent;
    sjt_math884 = (sjt_dot630)->m02;
    sjt_math881 = sjt_math883 * sjt_math884;
    sjt_dot631 = m;
    sjt_math885 = (sjt_dot631)->m31;
    sjt_dot632 = _parent;
    sjt_math886 = (sjt_dot632)->m12;
    sjt_math882 = sjt_math885 * sjt_math886;
    sjt_math879 = sjt_math881 + sjt_math882;
    sjt_dot633 = m;
    sjt_math887 = (sjt_dot633)->m32;
    sjt_dot634 = _parent;
    sjt_math888 = (sjt_dot634)->m22;
    sjt_math880 = sjt_math887 * sjt_math888;
    sjt_math877 = sjt_math879 + sjt_math880;
    sjt_dot635 = m;
    sjt_math889 = (sjt_dot635)->m33;
    sjt_dot636 = _parent;
    sjt_math890 = (sjt_dot636)->m32;
    sjt_math878 = sjt_math889 * sjt_math890;
    (*_return)->m32 = sjt_math877 + sjt_math878;
    sjt_dot637 = m;
    sjt_math897 = (sjt_dot637)->m30;
    sjt_dot638 = _parent;
    sjt_math898 = (sjt_dot638)->m03;
    sjt_math895 = sjt_math897 * sjt_math898;
    sjt_dot639 = m;
    sjt_math899 = (sjt_dot639)->m31;
    sjt_dot640 = _parent;
    sjt_math900 = (sjt_dot640)->m13;
    sjt_math896 = sjt_math899 * sjt_math900;
    sjt_math893 = sjt_math895 + sjt_math896;
    sjt_dot641 = m;
    sjt_math901 = (sjt_dot641)->m32;
    sjt_dot642 = _parent;
    sjt_math902 = (sjt_dot642)->m23;
    sjt_math894 = sjt_math901 * sjt_math902;
    sjt_math891 = sjt_math893 + sjt_math894;
    sjt_dot643 = m;
    sjt_math903 = (sjt_dot643)->m33;
    sjt_dot644 = _parent;
    sjt_math904 = (sjt_dot644)->m33;
    sjt_math892 = sjt_math903 * sjt_math904;
    (*_return)->m33 = sjt_math891 + sjt_math892;
    sjf_mat4_heap((*_return));
}

void sjf_mat4_multiplyf32(sjs_mat4* _parent, float x, sjs_mat4* _return) {
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

    _return->_refCount = 1;
    sjt_dot1017 = _parent;
    sjt_math1451 = (sjt_dot1017)->m00;
    sjt_math1452 = x;
    _return->m00 = sjt_math1451 * sjt_math1452;
    sjt_dot1018 = _parent;
    sjt_math1453 = (sjt_dot1018)->m01;
    sjt_math1454 = x;
    _return->m01 = sjt_math1453 * sjt_math1454;
    sjt_dot1019 = _parent;
    sjt_math1455 = (sjt_dot1019)->m02;
    sjt_math1456 = x;
    _return->m02 = sjt_math1455 * sjt_math1456;
    sjt_dot1020 = _parent;
    sjt_math1457 = (sjt_dot1020)->m03;
    sjt_math1458 = x;
    _return->m03 = sjt_math1457 * sjt_math1458;
    sjt_dot1021 = _parent;
    sjt_math1459 = (sjt_dot1021)->m10;
    sjt_math1460 = x;
    _return->m10 = sjt_math1459 * sjt_math1460;
    sjt_dot1022 = _parent;
    sjt_math1461 = (sjt_dot1022)->m11;
    sjt_math1462 = x;
    _return->m11 = sjt_math1461 * sjt_math1462;
    sjt_dot1023 = _parent;
    sjt_math1463 = (sjt_dot1023)->m12;
    sjt_math1464 = x;
    _return->m12 = sjt_math1463 * sjt_math1464;
    sjt_dot1024 = _parent;
    sjt_math1465 = (sjt_dot1024)->m13;
    sjt_math1466 = x;
    _return->m13 = sjt_math1465 * sjt_math1466;
    sjt_dot1025 = _parent;
    sjt_math1467 = (sjt_dot1025)->m20;
    sjt_math1468 = x;
    _return->m20 = sjt_math1467 * sjt_math1468;
    sjt_dot1026 = _parent;
    sjt_math1469 = (sjt_dot1026)->m21;
    sjt_math1470 = x;
    _return->m21 = sjt_math1469 * sjt_math1470;
    sjt_dot1027 = _parent;
    sjt_math1471 = (sjt_dot1027)->m22;
    sjt_math1472 = x;
    _return->m22 = sjt_math1471 * sjt_math1472;
    sjt_dot1028 = _parent;
    sjt_math1473 = (sjt_dot1028)->m23;
    sjt_math1474 = x;
    _return->m23 = sjt_math1473 * sjt_math1474;
    sjt_dot1029 = _parent;
    sjt_math1475 = (sjt_dot1029)->m30;
    sjt_math1476 = x;
    _return->m30 = sjt_math1475 * sjt_math1476;
    sjt_dot1030 = _parent;
    sjt_math1477 = (sjt_dot1030)->m31;
    sjt_math1478 = x;
    _return->m31 = sjt_math1477 * sjt_math1478;
    sjt_dot1031 = _parent;
    sjt_math1479 = (sjt_dot1031)->m32;
    sjt_math1480 = x;
    _return->m32 = sjt_math1479 * sjt_math1480;
    sjt_dot1032 = _parent;
    sjt_math1481 = (sjt_dot1032)->m33;
    sjt_math1482 = x;
    _return->m33 = sjt_math1481 * sjt_math1482;
    sjf_mat4(_return);
}

void sjf_mat4_multiplyf32_heap(sjs_mat4* _parent, float x, sjs_mat4** _return) {
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

    (*_return) = (sjs_mat4*)malloc(sizeof(sjs_mat4));
    (*_return)->_refCount = 1;
    sjt_dot1033 = _parent;
    sjt_math1483 = (sjt_dot1033)->m00;
    sjt_math1484 = x;
    (*_return)->m00 = sjt_math1483 * sjt_math1484;
    sjt_dot1034 = _parent;
    sjt_math1485 = (sjt_dot1034)->m01;
    sjt_math1486 = x;
    (*_return)->m01 = sjt_math1485 * sjt_math1486;
    sjt_dot1035 = _parent;
    sjt_math1487 = (sjt_dot1035)->m02;
    sjt_math1488 = x;
    (*_return)->m02 = sjt_math1487 * sjt_math1488;
    sjt_dot1036 = _parent;
    sjt_math1489 = (sjt_dot1036)->m03;
    sjt_math1490 = x;
    (*_return)->m03 = sjt_math1489 * sjt_math1490;
    sjt_dot1037 = _parent;
    sjt_math1491 = (sjt_dot1037)->m10;
    sjt_math1492 = x;
    (*_return)->m10 = sjt_math1491 * sjt_math1492;
    sjt_dot1038 = _parent;
    sjt_math1493 = (sjt_dot1038)->m11;
    sjt_math1494 = x;
    (*_return)->m11 = sjt_math1493 * sjt_math1494;
    sjt_dot1039 = _parent;
    sjt_math1495 = (sjt_dot1039)->m12;
    sjt_math1496 = x;
    (*_return)->m12 = sjt_math1495 * sjt_math1496;
    sjt_dot1040 = _parent;
    sjt_math1497 = (sjt_dot1040)->m13;
    sjt_math1498 = x;
    (*_return)->m13 = sjt_math1497 * sjt_math1498;
    sjt_dot1041 = _parent;
    sjt_math1499 = (sjt_dot1041)->m20;
    sjt_math1500 = x;
    (*_return)->m20 = sjt_math1499 * sjt_math1500;
    sjt_dot1042 = _parent;
    sjt_math1501 = (sjt_dot1042)->m21;
    sjt_math1502 = x;
    (*_return)->m21 = sjt_math1501 * sjt_math1502;
    sjt_dot1043 = _parent;
    sjt_math1503 = (sjt_dot1043)->m22;
    sjt_math1504 = x;
    (*_return)->m22 = sjt_math1503 * sjt_math1504;
    sjt_dot1044 = _parent;
    sjt_math1505 = (sjt_dot1044)->m23;
    sjt_math1506 = x;
    (*_return)->m23 = sjt_math1505 * sjt_math1506;
    sjt_dot1045 = _parent;
    sjt_math1507 = (sjt_dot1045)->m30;
    sjt_math1508 = x;
    (*_return)->m30 = sjt_math1507 * sjt_math1508;
    sjt_dot1046 = _parent;
    sjt_math1509 = (sjt_dot1046)->m31;
    sjt_math1510 = x;
    (*_return)->m31 = sjt_math1509 * sjt_math1510;
    sjt_dot1047 = _parent;
    sjt_math1511 = (sjt_dot1047)->m32;
    sjt_math1512 = x;
    (*_return)->m32 = sjt_math1511 * sjt_math1512;
    sjt_dot1048 = _parent;
    sjt_math1513 = (sjt_dot1048)->m33;
    sjt_math1514 = x;
    (*_return)->m33 = sjt_math1513 * sjt_math1514;
    sjf_mat4_heap((*_return));
}

void sjf_mat4_multiplyvec4(sjs_mat4* _parent, sjs_vec4* v, sjs_vec4* _return) {
    sjs_mat4* sjt_dot325 = 0;
    sjs_vec4* sjt_dot326 = 0;
    sjs_mat4* sjt_dot327 = 0;
    sjs_vec4* sjt_dot328 = 0;
    sjs_mat4* sjt_dot329 = 0;
    sjs_vec4* sjt_dot330 = 0;
    sjs_mat4* sjt_dot331 = 0;
    sjs_vec4* sjt_dot332 = 0;
    sjs_mat4* sjt_dot333 = 0;
    sjs_vec4* sjt_dot334 = 0;
    sjs_mat4* sjt_dot335 = 0;
    sjs_vec4* sjt_dot336 = 0;
    sjs_mat4* sjt_dot337 = 0;
    sjs_vec4* sjt_dot338 = 0;
    sjs_mat4* sjt_dot339 = 0;
    sjs_vec4* sjt_dot340 = 0;
    sjs_mat4* sjt_dot341 = 0;
    sjs_vec4* sjt_dot342 = 0;
    sjs_mat4* sjt_dot343 = 0;
    sjs_vec4* sjt_dot344 = 0;
    sjs_mat4* sjt_dot345 = 0;
    sjs_vec4* sjt_dot346 = 0;
    sjs_mat4* sjt_dot347 = 0;
    sjs_vec4* sjt_dot348 = 0;
    sjs_mat4* sjt_dot349 = 0;
    sjs_vec4* sjt_dot350 = 0;
    sjs_mat4* sjt_dot351 = 0;
    sjs_vec4* sjt_dot352 = 0;
    sjs_mat4* sjt_dot353 = 0;
    sjs_vec4* sjt_dot354 = 0;
    sjs_mat4* sjt_dot355 = 0;
    sjs_vec4* sjt_dot356 = 0;
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

    _return->_refCount = 1;
    sjt_dot325 = _parent;
    sjt_math351 = (sjt_dot325)->m00;
    sjt_dot326 = v;
    sjt_math352 = (sjt_dot326)->x;
    sjt_math349 = sjt_math351 * sjt_math352;
    sjt_dot327 = _parent;
    sjt_math353 = (sjt_dot327)->m10;
    sjt_dot328 = v;
    sjt_math354 = (sjt_dot328)->y;
    sjt_math350 = sjt_math353 * sjt_math354;
    sjt_math347 = sjt_math349 + sjt_math350;
    sjt_dot329 = _parent;
    sjt_math355 = (sjt_dot329)->m20;
    sjt_dot330 = v;
    sjt_math356 = (sjt_dot330)->z;
    sjt_math348 = sjt_math355 * sjt_math356;
    sjt_math345 = sjt_math347 + sjt_math348;
    sjt_dot331 = _parent;
    sjt_math357 = (sjt_dot331)->m30;
    sjt_dot332 = v;
    sjt_math358 = (sjt_dot332)->w;
    sjt_math346 = sjt_math357 * sjt_math358;
    _return->x = sjt_math345 + sjt_math346;
    sjt_dot333 = _parent;
    sjt_math365 = (sjt_dot333)->m01;
    sjt_dot334 = v;
    sjt_math366 = (sjt_dot334)->x;
    sjt_math363 = sjt_math365 * sjt_math366;
    sjt_dot335 = _parent;
    sjt_math367 = (sjt_dot335)->m11;
    sjt_dot336 = v;
    sjt_math368 = (sjt_dot336)->y;
    sjt_math364 = sjt_math367 * sjt_math368;
    sjt_math361 = sjt_math363 + sjt_math364;
    sjt_dot337 = _parent;
    sjt_math369 = (sjt_dot337)->m21;
    sjt_dot338 = v;
    sjt_math370 = (sjt_dot338)->z;
    sjt_math362 = sjt_math369 * sjt_math370;
    sjt_math359 = sjt_math361 + sjt_math362;
    sjt_dot339 = _parent;
    sjt_math371 = (sjt_dot339)->m31;
    sjt_dot340 = v;
    sjt_math372 = (sjt_dot340)->w;
    sjt_math360 = sjt_math371 * sjt_math372;
    _return->y = sjt_math359 + sjt_math360;
    sjt_dot341 = _parent;
    sjt_math379 = (sjt_dot341)->m02;
    sjt_dot342 = v;
    sjt_math380 = (sjt_dot342)->x;
    sjt_math377 = sjt_math379 * sjt_math380;
    sjt_dot343 = _parent;
    sjt_math381 = (sjt_dot343)->m12;
    sjt_dot344 = v;
    sjt_math382 = (sjt_dot344)->y;
    sjt_math378 = sjt_math381 * sjt_math382;
    sjt_math375 = sjt_math377 + sjt_math378;
    sjt_dot345 = _parent;
    sjt_math383 = (sjt_dot345)->m22;
    sjt_dot346 = v;
    sjt_math384 = (sjt_dot346)->z;
    sjt_math376 = sjt_math383 * sjt_math384;
    sjt_math373 = sjt_math375 + sjt_math376;
    sjt_dot347 = _parent;
    sjt_math385 = (sjt_dot347)->m32;
    sjt_dot348 = v;
    sjt_math386 = (sjt_dot348)->w;
    sjt_math374 = sjt_math385 * sjt_math386;
    _return->z = sjt_math373 + sjt_math374;
    sjt_dot349 = _parent;
    sjt_math393 = (sjt_dot349)->m03;
    sjt_dot350 = v;
    sjt_math394 = (sjt_dot350)->x;
    sjt_math391 = sjt_math393 * sjt_math394;
    sjt_dot351 = _parent;
    sjt_math395 = (sjt_dot351)->m13;
    sjt_dot352 = v;
    sjt_math396 = (sjt_dot352)->y;
    sjt_math392 = sjt_math395 * sjt_math396;
    sjt_math389 = sjt_math391 + sjt_math392;
    sjt_dot353 = _parent;
    sjt_math397 = (sjt_dot353)->m23;
    sjt_dot354 = v;
    sjt_math398 = (sjt_dot354)->z;
    sjt_math390 = sjt_math397 * sjt_math398;
    sjt_math387 = sjt_math389 + sjt_math390;
    sjt_dot355 = _parent;
    sjt_math399 = (sjt_dot355)->m33;
    sjt_dot356 = v;
    sjt_math400 = (sjt_dot356)->w;
    sjt_math388 = sjt_math399 * sjt_math400;
    _return->w = sjt_math387 + sjt_math388;
    sjf_vec4(_return);
}

void sjf_mat4_multiplyvec4_heap(sjs_mat4* _parent, sjs_vec4* v, sjs_vec4** _return) {
    sjs_mat4* sjt_dot357 = 0;
    sjs_vec4* sjt_dot358 = 0;
    sjs_mat4* sjt_dot359 = 0;
    sjs_vec4* sjt_dot360 = 0;
    sjs_mat4* sjt_dot361 = 0;
    sjs_vec4* sjt_dot362 = 0;
    sjs_mat4* sjt_dot363 = 0;
    sjs_vec4* sjt_dot364 = 0;
    sjs_mat4* sjt_dot365 = 0;
    sjs_vec4* sjt_dot366 = 0;
    sjs_mat4* sjt_dot367 = 0;
    sjs_vec4* sjt_dot368 = 0;
    sjs_mat4* sjt_dot369 = 0;
    sjs_vec4* sjt_dot370 = 0;
    sjs_mat4* sjt_dot371 = 0;
    sjs_vec4* sjt_dot372 = 0;
    sjs_mat4* sjt_dot373 = 0;
    sjs_vec4* sjt_dot374 = 0;
    sjs_mat4* sjt_dot375 = 0;
    sjs_vec4* sjt_dot376 = 0;
    sjs_mat4* sjt_dot377 = 0;
    sjs_vec4* sjt_dot378 = 0;
    sjs_mat4* sjt_dot379 = 0;
    sjs_vec4* sjt_dot380 = 0;
    sjs_mat4* sjt_dot381 = 0;
    sjs_vec4* sjt_dot382 = 0;
    sjs_mat4* sjt_dot383 = 0;
    sjs_vec4* sjt_dot384 = 0;
    sjs_mat4* sjt_dot385 = 0;
    sjs_vec4* sjt_dot386 = 0;
    sjs_mat4* sjt_dot387 = 0;
    sjs_vec4* sjt_dot388 = 0;
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

    (*_return) = (sjs_vec4*)malloc(sizeof(sjs_vec4));
    (*_return)->_refCount = 1;
    sjt_dot357 = _parent;
    sjt_math407 = (sjt_dot357)->m00;
    sjt_dot358 = v;
    sjt_math408 = (sjt_dot358)->x;
    sjt_math405 = sjt_math407 * sjt_math408;
    sjt_dot359 = _parent;
    sjt_math409 = (sjt_dot359)->m10;
    sjt_dot360 = v;
    sjt_math410 = (sjt_dot360)->y;
    sjt_math406 = sjt_math409 * sjt_math410;
    sjt_math403 = sjt_math405 + sjt_math406;
    sjt_dot361 = _parent;
    sjt_math411 = (sjt_dot361)->m20;
    sjt_dot362 = v;
    sjt_math412 = (sjt_dot362)->z;
    sjt_math404 = sjt_math411 * sjt_math412;
    sjt_math401 = sjt_math403 + sjt_math404;
    sjt_dot363 = _parent;
    sjt_math413 = (sjt_dot363)->m30;
    sjt_dot364 = v;
    sjt_math414 = (sjt_dot364)->w;
    sjt_math402 = sjt_math413 * sjt_math414;
    (*_return)->x = sjt_math401 + sjt_math402;
    sjt_dot365 = _parent;
    sjt_math421 = (sjt_dot365)->m01;
    sjt_dot366 = v;
    sjt_math422 = (sjt_dot366)->x;
    sjt_math419 = sjt_math421 * sjt_math422;
    sjt_dot367 = _parent;
    sjt_math423 = (sjt_dot367)->m11;
    sjt_dot368 = v;
    sjt_math424 = (sjt_dot368)->y;
    sjt_math420 = sjt_math423 * sjt_math424;
    sjt_math417 = sjt_math419 + sjt_math420;
    sjt_dot369 = _parent;
    sjt_math425 = (sjt_dot369)->m21;
    sjt_dot370 = v;
    sjt_math426 = (sjt_dot370)->z;
    sjt_math418 = sjt_math425 * sjt_math426;
    sjt_math415 = sjt_math417 + sjt_math418;
    sjt_dot371 = _parent;
    sjt_math427 = (sjt_dot371)->m31;
    sjt_dot372 = v;
    sjt_math428 = (sjt_dot372)->w;
    sjt_math416 = sjt_math427 * sjt_math428;
    (*_return)->y = sjt_math415 + sjt_math416;
    sjt_dot373 = _parent;
    sjt_math435 = (sjt_dot373)->m02;
    sjt_dot374 = v;
    sjt_math436 = (sjt_dot374)->x;
    sjt_math433 = sjt_math435 * sjt_math436;
    sjt_dot375 = _parent;
    sjt_math437 = (sjt_dot375)->m12;
    sjt_dot376 = v;
    sjt_math438 = (sjt_dot376)->y;
    sjt_math434 = sjt_math437 * sjt_math438;
    sjt_math431 = sjt_math433 + sjt_math434;
    sjt_dot377 = _parent;
    sjt_math439 = (sjt_dot377)->m22;
    sjt_dot378 = v;
    sjt_math440 = (sjt_dot378)->z;
    sjt_math432 = sjt_math439 * sjt_math440;
    sjt_math429 = sjt_math431 + sjt_math432;
    sjt_dot379 = _parent;
    sjt_math441 = (sjt_dot379)->m32;
    sjt_dot380 = v;
    sjt_math442 = (sjt_dot380)->w;
    sjt_math430 = sjt_math441 * sjt_math442;
    (*_return)->z = sjt_math429 + sjt_math430;
    sjt_dot381 = _parent;
    sjt_math449 = (sjt_dot381)->m03;
    sjt_dot382 = v;
    sjt_math450 = (sjt_dot382)->x;
    sjt_math447 = sjt_math449 * sjt_math450;
    sjt_dot383 = _parent;
    sjt_math451 = (sjt_dot383)->m13;
    sjt_dot384 = v;
    sjt_math452 = (sjt_dot384)->y;
    sjt_math448 = sjt_math451 * sjt_math452;
    sjt_math445 = sjt_math447 + sjt_math448;
    sjt_dot385 = _parent;
    sjt_math453 = (sjt_dot385)->m23;
    sjt_dot386 = v;
    sjt_math454 = (sjt_dot386)->z;
    sjt_math446 = sjt_math453 * sjt_math454;
    sjt_math443 = sjt_math445 + sjt_math446;
    sjt_dot387 = _parent;
    sjt_math455 = (sjt_dot387)->m33;
    sjt_dot388 = v;
    sjt_math456 = (sjt_dot388)->w;
    sjt_math444 = sjt_math455 * sjt_math456;
    (*_return)->w = sjt_math443 + sjt_math444;
    sjf_vec4_heap((*_return));
}

void sjf_mat4_orthographic(float left, float right, float bottom, float top, float znear, float zfar, sjs_mat4* _return) {
    float result6;
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
    float sjt_math301;
    float sjt_math302;
    float sjt_negate3;

    _return->_refCount = 1;
    sjt_math267 = 2.0f;
    sjt_math269 = right;
    sjt_math270 = left;
    sjt_math268 = sjt_math269 - sjt_math270;
    _return->m00 = sjt_math267 / sjt_math268;
    _return->m01 = 0.0f;
    _return->m02 = 0.0f;
    _return->m03 = 0.0f;
    _return->m10 = 0.0f;
    sjt_math271 = 2.0f;
    sjt_math273 = top;
    sjt_math274 = bottom;
    sjt_math272 = sjt_math273 - sjt_math274;
    _return->m11 = sjt_math271 / sjt_math272;
    _return->m12 = 0.0f;
    _return->m13 = 0.0f;
    _return->m20 = 0.0f;
    _return->m21 = 0.0f;
    sjt_negate3 = 2.0f;
    result6 = -sjt_negate3;
    sjt_math275 = result6;
    sjt_math277 = zfar;
    sjt_math278 = znear;
    sjt_math276 = sjt_math277 - sjt_math278;
    _return->m22 = sjt_math275 / sjt_math276;
    _return->m23 = 0.0f;
    sjt_math279 = 0.0f;
    sjt_math283 = right;
    sjt_math284 = left;
    sjt_math281 = sjt_math283 + sjt_math284;
    sjt_math285 = right;
    sjt_math286 = left;
    sjt_math282 = sjt_math285 - sjt_math286;
    sjt_math280 = sjt_math281 / sjt_math282;
    _return->m30 = sjt_math279 - sjt_math280;
    sjt_math287 = 0.0f;
    sjt_math291 = top;
    sjt_math292 = bottom;
    sjt_math289 = sjt_math291 + sjt_math292;
    sjt_math293 = top;
    sjt_math294 = bottom;
    sjt_math290 = sjt_math293 - sjt_math294;
    sjt_math288 = sjt_math289 / sjt_math290;
    _return->m31 = sjt_math287 - sjt_math288;
    sjt_math295 = 0.0f;
    sjt_math299 = zfar;
    sjt_math300 = znear;
    sjt_math297 = sjt_math299 + sjt_math300;
    sjt_math301 = zfar;
    sjt_math302 = znear;
    sjt_math298 = sjt_math301 - sjt_math302;
    sjt_math296 = sjt_math297 / sjt_math298;
    _return->m32 = sjt_math295 - sjt_math296;
    _return->m33 = 1.0f;
    sjf_mat4(_return);
}

void sjf_mat4_orthographic_heap(float left, float right, float bottom, float top, float znear, float zfar, sjs_mat4** _return) {
    float result7;
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
    float sjt_negate4;

    (*_return) = (sjs_mat4*)malloc(sizeof(sjs_mat4));
    (*_return)->_refCount = 1;
    sjt_math303 = 2.0f;
    sjt_math305 = right;
    sjt_math306 = left;
    sjt_math304 = sjt_math305 - sjt_math306;
    (*_return)->m00 = sjt_math303 / sjt_math304;
    (*_return)->m01 = 0.0f;
    (*_return)->m02 = 0.0f;
    (*_return)->m03 = 0.0f;
    (*_return)->m10 = 0.0f;
    sjt_math307 = 2.0f;
    sjt_math309 = top;
    sjt_math310 = bottom;
    sjt_math308 = sjt_math309 - sjt_math310;
    (*_return)->m11 = sjt_math307 / sjt_math308;
    (*_return)->m12 = 0.0f;
    (*_return)->m13 = 0.0f;
    (*_return)->m20 = 0.0f;
    (*_return)->m21 = 0.0f;
    sjt_negate4 = 2.0f;
    result7 = -sjt_negate4;
    sjt_math311 = result7;
    sjt_math313 = zfar;
    sjt_math314 = znear;
    sjt_math312 = sjt_math313 - sjt_math314;
    (*_return)->m22 = sjt_math311 / sjt_math312;
    (*_return)->m23 = 0.0f;
    sjt_math315 = 0.0f;
    sjt_math319 = right;
    sjt_math320 = left;
    sjt_math317 = sjt_math319 + sjt_math320;
    sjt_math321 = right;
    sjt_math322 = left;
    sjt_math318 = sjt_math321 - sjt_math322;
    sjt_math316 = sjt_math317 / sjt_math318;
    (*_return)->m30 = sjt_math315 - sjt_math316;
    sjt_math323 = 0.0f;
    sjt_math327 = top;
    sjt_math328 = bottom;
    sjt_math325 = sjt_math327 + sjt_math328;
    sjt_math329 = top;
    sjt_math330 = bottom;
    sjt_math326 = sjt_math329 - sjt_math330;
    sjt_math324 = sjt_math325 / sjt_math326;
    (*_return)->m31 = sjt_math323 - sjt_math324;
    sjt_math331 = 0.0f;
    sjt_math335 = zfar;
    sjt_math336 = znear;
    sjt_math333 = sjt_math335 + sjt_math336;
    sjt_math337 = zfar;
    sjt_math338 = znear;
    sjt_math334 = sjt_math337 - sjt_math338;
    sjt_math332 = sjt_math333 / sjt_math334;
    (*_return)->m32 = sjt_math331 - sjt_math332;
    (*_return)->m33 = 1.0f;
    sjf_mat4_heap((*_return));
}

void sjf_mat4_perspective(float fovy, float aspect, float znear, float zfar, sjs_mat4* _return) {
    float sjt_functionParam22;
    float sjt_math61;
    float sjt_math62;
    float sjt_math63;
    float sjt_math64;
    float sjt_math65;
    float sjt_math66;
    float sjt_math67;
    float sjt_math68;
    float sjt_math69;
    float sjt_math70;
    float sjt_math71;
    float sjt_math72;
    float sjt_math73;
    float sjt_math74;
    float sjt_math75;
    float sjt_math76;
    float sjt_math77;
    float sjt_math78;
    float sjt_math79;
    float sjt_math80;
    float sjv_xscale;
    float sjv_yscale;

    sjt_math61 = 1.0f;
    sjt_math65 = fovy;
    sjt_math66 = 180.0f;
    sjt_math63 = sjt_math65 / sjt_math66;
    sjt_math64 = 2.0f;
    sjt_functionParam22 = sjt_math63 / sjt_math64;
    sjf_f32_tan(sjt_functionParam22, &sjt_math62);
    sjv_yscale = sjt_math61 / sjt_math62;
    sjt_math67 = sjv_yscale;
    sjt_math68 = aspect;
    sjv_xscale = sjt_math67 * sjt_math68;
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
    sjt_math69 = zfar;
    sjt_math71 = zfar;
    sjt_math72 = znear;
    sjt_math70 = sjt_math71 - sjt_math72;
    _return->m22 = sjt_math69 / sjt_math70;
    _return->m23 = 1.0f;
    _return->m30 = 0.0f;
    _return->m31 = 0.0f;
    sjt_math73 = 0.0f;
    sjt_math77 = znear;
    sjt_math78 = zfar;
    sjt_math75 = sjt_math77 * sjt_math78;
    sjt_math79 = zfar;
    sjt_math80 = znear;
    sjt_math76 = sjt_math79 - sjt_math80;
    sjt_math74 = sjt_math75 / sjt_math76;
    _return->m32 = sjt_math73 - sjt_math74;
    _return->m33 = 0.0f;
    sjf_mat4(_return);
}

void sjf_mat4_perspective_heap(float fovy, float aspect, float znear, float zfar, sjs_mat4** _return) {
    float sjt_functionParam23;
    float sjt_math100;
    float sjt_math81;
    float sjt_math82;
    float sjt_math83;
    float sjt_math84;
    float sjt_math85;
    float sjt_math86;
    float sjt_math87;
    float sjt_math88;
    float sjt_math89;
    float sjt_math90;
    float sjt_math91;
    float sjt_math92;
    float sjt_math93;
    float sjt_math94;
    float sjt_math95;
    float sjt_math96;
    float sjt_math97;
    float sjt_math98;
    float sjt_math99;
    float sjv_xscale;
    float sjv_yscale;

    sjt_math81 = 1.0f;
    sjt_math85 = fovy;
    sjt_math86 = 180.0f;
    sjt_math83 = sjt_math85 / sjt_math86;
    sjt_math84 = 2.0f;
    sjt_functionParam23 = sjt_math83 / sjt_math84;
    sjf_f32_tan(sjt_functionParam23, &sjt_math82);
    sjv_yscale = sjt_math81 / sjt_math82;
    sjt_math87 = sjv_yscale;
    sjt_math88 = aspect;
    sjv_xscale = sjt_math87 * sjt_math88;
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
    sjt_math89 = zfar;
    sjt_math91 = zfar;
    sjt_math92 = znear;
    sjt_math90 = sjt_math91 - sjt_math92;
    (*_return)->m22 = sjt_math89 / sjt_math90;
    (*_return)->m23 = 1.0f;
    (*_return)->m30 = 0.0f;
    (*_return)->m31 = 0.0f;
    sjt_math93 = 0.0f;
    sjt_math97 = znear;
    sjt_math98 = zfar;
    sjt_math95 = sjt_math97 * sjt_math98;
    sjt_math99 = zfar;
    sjt_math100 = znear;
    sjt_math96 = sjt_math99 - sjt_math100;
    sjt_math94 = sjt_math95 / sjt_math96;
    (*_return)->m32 = sjt_math93 - sjt_math94;
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

    _return->_refCount = 1;
    sjt_dot697 = _parent;
    _return->m00 = (sjt_dot697)->m00;
    sjt_dot698 = _parent;
    _return->m01 = (sjt_dot698)->m10;
    sjt_dot699 = _parent;
    _return->m02 = (sjt_dot699)->m20;
    sjt_dot700 = _parent;
    _return->m03 = (sjt_dot700)->m30;
    sjt_dot701 = _parent;
    _return->m10 = (sjt_dot701)->m01;
    sjt_dot702 = _parent;
    _return->m11 = (sjt_dot702)->m11;
    sjt_dot703 = _parent;
    _return->m12 = (sjt_dot703)->m21;
    sjt_dot704 = _parent;
    _return->m13 = (sjt_dot704)->m31;
    sjt_dot705 = _parent;
    _return->m20 = (sjt_dot705)->m02;
    sjt_dot706 = _parent;
    _return->m21 = (sjt_dot706)->m12;
    sjt_dot707 = _parent;
    _return->m22 = (sjt_dot707)->m22;
    sjt_dot708 = _parent;
    _return->m23 = (sjt_dot708)->m32;
    sjt_dot709 = _parent;
    _return->m30 = (sjt_dot709)->m03;
    sjt_dot710 = _parent;
    _return->m31 = (sjt_dot710)->m13;
    sjt_dot711 = _parent;
    _return->m32 = (sjt_dot711)->m23;
    sjt_dot712 = _parent;
    _return->m33 = (sjt_dot712)->m33;
    sjf_mat4(_return);
}

void sjf_mat4_transpose_heap(sjs_mat4* _parent, sjs_mat4** _return) {
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

    (*_return) = (sjs_mat4*)malloc(sizeof(sjs_mat4));
    (*_return)->_refCount = 1;
    sjt_dot713 = _parent;
    (*_return)->m00 = (sjt_dot713)->m00;
    sjt_dot714 = _parent;
    (*_return)->m01 = (sjt_dot714)->m10;
    sjt_dot715 = _parent;
    (*_return)->m02 = (sjt_dot715)->m20;
    sjt_dot716 = _parent;
    (*_return)->m03 = (sjt_dot716)->m30;
    sjt_dot717 = _parent;
    (*_return)->m10 = (sjt_dot717)->m01;
    sjt_dot718 = _parent;
    (*_return)->m11 = (sjt_dot718)->m11;
    sjt_dot719 = _parent;
    (*_return)->m12 = (sjt_dot719)->m21;
    sjt_dot720 = _parent;
    (*_return)->m13 = (sjt_dot720)->m31;
    sjt_dot721 = _parent;
    (*_return)->m20 = (sjt_dot721)->m02;
    sjt_dot722 = _parent;
    (*_return)->m21 = (sjt_dot722)->m12;
    sjt_dot723 = _parent;
    (*_return)->m22 = (sjt_dot723)->m22;
    sjt_dot724 = _parent;
    (*_return)->m23 = (sjt_dot724)->m32;
    sjt_dot725 = _parent;
    (*_return)->m30 = (sjt_dot725)->m03;
    sjt_dot726 = _parent;
    (*_return)->m31 = (sjt_dot726)->m13;
    sjt_dot727 = _parent;
    (*_return)->m32 = (sjt_dot727)->m23;
    sjt_dot728 = _parent;
    (*_return)->m33 = (sjt_dot728)->m33;
    sjf_mat4_heap((*_return));
}

void sjf_model_zsort(sji_model l, sji_model r, int32_t* _return) {
    float sjt_functionParam128;
    float sjt_functionParam129;
    sji_model sjt_parent79 = { 0 };
    sji_model sjt_parent80 = { 0 };

    sjt_parent79 = l;
    sjt_parent79._vtbl->getz(sjt_parent79._parent, &sjt_functionParam128);
    sjt_parent80 = r;
    sjt_parent80._vtbl->getz(sjt_parent80._parent, &sjt_functionParam129);
    sjf_f32_compare(sjt_functionParam128, sjt_functionParam129, _return);
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
}

void sjf_mouseevent_destroy(sjs_mouseevent* _this) {
}

void sjf_mouseevent_firechildren(sjs_mouseevent* _parent, sjs_array_heap_iface_element* children, bool* _return) {
    int32_t i;
    sjs_array_heap_iface_element* sjt_dot94 = 0;
    int32_t sjt_forEnd5;
    int32_t sjt_forStart5;
    bool sjv_shouldcontinue;

    sjv_shouldcontinue = true;
    sjt_forStart5 = 0;
    sjt_dot94 = children;
    sjt_forEnd5 = (sjt_dot94)->count;
    i = sjt_forEnd5 - 1;
    while (i >= sjt_forStart5) {
        bool sjt_ifElse5;

        sjt_ifElse5 = sjv_shouldcontinue;
        if (sjt_ifElse5) {
            int32_t sjt_functionParam17;
            sjs_mouseevent* sjt_interfaceParam9 = 0;
            sjs_array_heap_iface_element* sjt_parent21 = 0;
            sji_element sjt_parent22 = { 0 };
            sji_element sjv_child = { 0 };

            sjt_parent21 = children;
            sjt_functionParam17 = i;
            sjf_array_heap_iface_element_getat_heap(sjt_parent21, sjt_functionParam17, &sjv_child);
            sjt_parent22 = sjv_child;
            sjt_interfaceParam9 = _parent;
            sjt_parent22._vtbl->firemouseevent(sjt_parent22._parent, sjt_interfaceParam9, &sjv_shouldcontinue);

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

void sjf_rect_asstring(sjs_rect* _parent, sjs_string* _return) {
    sjs_string sjt_call10 = { -1 };
    sjs_string sjt_call11 = { -1 };
    sjs_string sjt_call12 = { -1 };
    sjs_string sjt_call13 = { -1 };
    sjs_string sjt_call14 = { -1 };
    sjs_string sjt_call15 = { -1 };
    sjs_string sjt_call16 = { -1 };
    sjs_string sjt_call17 = { -1 };
    sjs_string sjt_call18 = { -1 };
    sjs_string sjt_call19 = { -1 };
    sjs_string sjt_call20 = { -1 };
    sjs_string sjt_call21 = { -1 };
    sjs_string sjt_call8 = { -1 };
    sjs_string sjt_call9 = { -1 };
    sjs_rect* sjt_dot250 = 0;
    sjs_rect* sjt_dot251 = 0;
    sjs_rect* sjt_dot252 = 0;
    sjs_rect* sjt_dot253 = 0;
    sjs_string* sjt_functionParam75 = 0;
    int32_t sjt_functionParam76;
    sjs_string* sjt_functionParam77 = 0;
    sjs_string* sjt_functionParam78 = 0;
    int32_t sjt_functionParam79;
    sjs_string* sjt_functionParam80 = 0;
    sjs_string* sjt_functionParam81 = 0;
    int32_t sjt_functionParam82;
    sjs_string* sjt_functionParam83 = 0;
    sjs_string* sjt_functionParam84 = 0;
    int32_t sjt_functionParam85;
    sjs_string* sjt_parent60 = 0;
    sjs_string* sjt_parent61 = 0;
    sjs_string* sjt_parent62 = 0;
    sjs_string* sjt_parent63 = 0;
    sjs_string* sjt_parent64 = 0;
    sjs_string* sjt_parent65 = 0;
    sjs_string* sjt_parent66 = 0;

    sjt_call14._refCount = 1;
    sjt_call14.count = 3;
    sjt_call14.data._refCount = 1;
    sjt_call14.data.datasize = 4;
    sjt_call14.data.data = (void*)sjg_string43;
    sjt_call14.data._isglobal = true;
    sjt_call14.data.count = 4;
    sjf_array_char(&sjt_call14.data);
    sjf_string(&sjt_call14);
    sjt_parent66 = &sjt_call14;
    sjt_dot250 = _parent;
    sjt_functionParam76 = (sjt_dot250)->x;
    sjf_i32_asstring(sjt_functionParam76, &sjt_call15);
    sjt_functionParam75 = &sjt_call15;
    sjf_string_add(sjt_parent66, sjt_functionParam75, &sjt_call13);
    sjt_parent65 = &sjt_call13;
    sjt_call16._refCount = 1;
    sjt_call16.count = 4;
    sjt_call16.data._refCount = 1;
    sjt_call16.data.datasize = 5;
    sjt_call16.data.data = (void*)sjg_string44;
    sjt_call16.data._isglobal = true;
    sjt_call16.data.count = 5;
    sjf_array_char(&sjt_call16.data);
    sjf_string(&sjt_call16);
    sjt_functionParam77 = &sjt_call16;
    sjf_string_add(sjt_parent65, sjt_functionParam77, &sjt_call12);
    sjt_parent64 = &sjt_call12;
    sjt_dot251 = _parent;
    sjt_functionParam79 = (sjt_dot251)->y;
    sjf_i32_asstring(sjt_functionParam79, &sjt_call17);
    sjt_functionParam78 = &sjt_call17;
    sjf_string_add(sjt_parent64, sjt_functionParam78, &sjt_call11);
    sjt_parent63 = &sjt_call11;
    sjt_call18._refCount = 1;
    sjt_call18.count = 4;
    sjt_call18.data._refCount = 1;
    sjt_call18.data.datasize = 5;
    sjt_call18.data.data = (void*)sjg_string45;
    sjt_call18.data._isglobal = true;
    sjt_call18.data.count = 5;
    sjf_array_char(&sjt_call18.data);
    sjf_string(&sjt_call18);
    sjt_functionParam80 = &sjt_call18;
    sjf_string_add(sjt_parent63, sjt_functionParam80, &sjt_call10);
    sjt_parent62 = &sjt_call10;
    sjt_dot252 = _parent;
    sjt_functionParam82 = (sjt_dot252)->w;
    sjf_i32_asstring(sjt_functionParam82, &sjt_call19);
    sjt_functionParam81 = &sjt_call19;
    sjf_string_add(sjt_parent62, sjt_functionParam81, &sjt_call9);
    sjt_parent61 = &sjt_call9;
    sjt_call20._refCount = 1;
    sjt_call20.count = 4;
    sjt_call20.data._refCount = 1;
    sjt_call20.data.datasize = 5;
    sjt_call20.data.data = (void*)sjg_string46;
    sjt_call20.data._isglobal = true;
    sjt_call20.data.count = 5;
    sjf_array_char(&sjt_call20.data);
    sjf_string(&sjt_call20);
    sjt_functionParam83 = &sjt_call20;
    sjf_string_add(sjt_parent61, sjt_functionParam83, &sjt_call8);
    sjt_parent60 = &sjt_call8;
    sjt_dot253 = _parent;
    sjt_functionParam85 = (sjt_dot253)->h;
    sjf_i32_asstring(sjt_functionParam85, &sjt_call21);
    sjt_functionParam84 = &sjt_call21;
    sjf_string_add(sjt_parent60, sjt_functionParam84, _return);

    if (sjt_call10._refCount == 1) { sjf_string_destroy(&sjt_call10); }
    if (sjt_call11._refCount == 1) { sjf_string_destroy(&sjt_call11); }
    if (sjt_call12._refCount == 1) { sjf_string_destroy(&sjt_call12); }
    if (sjt_call13._refCount == 1) { sjf_string_destroy(&sjt_call13); }
    if (sjt_call14._refCount == 1) { sjf_string_destroy(&sjt_call14); }
    if (sjt_call15._refCount == 1) { sjf_string_destroy(&sjt_call15); }
    if (sjt_call16._refCount == 1) { sjf_string_destroy(&sjt_call16); }
    if (sjt_call17._refCount == 1) { sjf_string_destroy(&sjt_call17); }
    if (sjt_call18._refCount == 1) { sjf_string_destroy(&sjt_call18); }
    if (sjt_call19._refCount == 1) { sjf_string_destroy(&sjt_call19); }
    if (sjt_call20._refCount == 1) { sjf_string_destroy(&sjt_call20); }
    if (sjt_call21._refCount == 1) { sjf_string_destroy(&sjt_call21); }
    if (sjt_call8._refCount == 1) { sjf_string_destroy(&sjt_call8); }
    if (sjt_call9._refCount == 1) { sjf_string_destroy(&sjt_call9); }
}

void sjf_rect_asstring_heap(sjs_rect* _parent, sjs_string** _return) {
    sjs_string sjt_call22 = { -1 };
    sjs_string sjt_call23 = { -1 };
    sjs_string sjt_call24 = { -1 };
    sjs_string sjt_call25 = { -1 };
    sjs_string sjt_call26 = { -1 };
    sjs_string sjt_call27 = { -1 };
    sjs_string sjt_call28 = { -1 };
    sjs_string sjt_call29 = { -1 };
    sjs_string sjt_call30 = { -1 };
    sjs_string sjt_call31 = { -1 };
    sjs_string sjt_call32 = { -1 };
    sjs_string sjt_call33 = { -1 };
    sjs_string sjt_call34 = { -1 };
    sjs_string sjt_call35 = { -1 };
    sjs_rect* sjt_dot254 = 0;
    sjs_rect* sjt_dot255 = 0;
    sjs_rect* sjt_dot256 = 0;
    sjs_rect* sjt_dot257 = 0;
    sjs_string* sjt_functionParam86 = 0;
    int32_t sjt_functionParam87;
    sjs_string* sjt_functionParam88 = 0;
    sjs_string* sjt_functionParam89 = 0;
    int32_t sjt_functionParam90;
    sjs_string* sjt_functionParam91 = 0;
    sjs_string* sjt_functionParam92 = 0;
    int32_t sjt_functionParam93;
    sjs_string* sjt_functionParam94 = 0;
    sjs_string* sjt_functionParam95 = 0;
    int32_t sjt_functionParam96;
    sjs_string* sjt_parent67 = 0;
    sjs_string* sjt_parent68 = 0;
    sjs_string* sjt_parent69 = 0;
    sjs_string* sjt_parent70 = 0;
    sjs_string* sjt_parent71 = 0;
    sjs_string* sjt_parent72 = 0;
    sjs_string* sjt_parent73 = 0;

    sjt_call28._refCount = 1;
    sjt_call28.count = 3;
    sjt_call28.data._refCount = 1;
    sjt_call28.data.datasize = 4;
    sjt_call28.data.data = (void*)sjg_string47;
    sjt_call28.data._isglobal = true;
    sjt_call28.data.count = 4;
    sjf_array_char(&sjt_call28.data);
    sjf_string(&sjt_call28);
    sjt_parent73 = &sjt_call28;
    sjt_dot254 = _parent;
    sjt_functionParam87 = (sjt_dot254)->x;
    sjf_i32_asstring(sjt_functionParam87, &sjt_call29);
    sjt_functionParam86 = &sjt_call29;
    sjf_string_add(sjt_parent73, sjt_functionParam86, &sjt_call27);
    sjt_parent72 = &sjt_call27;
    sjt_call30._refCount = 1;
    sjt_call30.count = 4;
    sjt_call30.data._refCount = 1;
    sjt_call30.data.datasize = 5;
    sjt_call30.data.data = (void*)sjg_string48;
    sjt_call30.data._isglobal = true;
    sjt_call30.data.count = 5;
    sjf_array_char(&sjt_call30.data);
    sjf_string(&sjt_call30);
    sjt_functionParam88 = &sjt_call30;
    sjf_string_add(sjt_parent72, sjt_functionParam88, &sjt_call26);
    sjt_parent71 = &sjt_call26;
    sjt_dot255 = _parent;
    sjt_functionParam90 = (sjt_dot255)->y;
    sjf_i32_asstring(sjt_functionParam90, &sjt_call31);
    sjt_functionParam89 = &sjt_call31;
    sjf_string_add(sjt_parent71, sjt_functionParam89, &sjt_call25);
    sjt_parent70 = &sjt_call25;
    sjt_call32._refCount = 1;
    sjt_call32.count = 4;
    sjt_call32.data._refCount = 1;
    sjt_call32.data.datasize = 5;
    sjt_call32.data.data = (void*)sjg_string49;
    sjt_call32.data._isglobal = true;
    sjt_call32.data.count = 5;
    sjf_array_char(&sjt_call32.data);
    sjf_string(&sjt_call32);
    sjt_functionParam91 = &sjt_call32;
    sjf_string_add(sjt_parent70, sjt_functionParam91, &sjt_call24);
    sjt_parent69 = &sjt_call24;
    sjt_dot256 = _parent;
    sjt_functionParam93 = (sjt_dot256)->w;
    sjf_i32_asstring(sjt_functionParam93, &sjt_call33);
    sjt_functionParam92 = &sjt_call33;
    sjf_string_add(sjt_parent69, sjt_functionParam92, &sjt_call23);
    sjt_parent68 = &sjt_call23;
    sjt_call34._refCount = 1;
    sjt_call34.count = 4;
    sjt_call34.data._refCount = 1;
    sjt_call34.data.datasize = 5;
    sjt_call34.data.data = (void*)sjg_string50;
    sjt_call34.data._isglobal = true;
    sjt_call34.data.count = 5;
    sjf_array_char(&sjt_call34.data);
    sjf_string(&sjt_call34);
    sjt_functionParam94 = &sjt_call34;
    sjf_string_add(sjt_parent68, sjt_functionParam94, &sjt_call22);
    sjt_parent67 = &sjt_call22;
    sjt_dot257 = _parent;
    sjt_functionParam96 = (sjt_dot257)->h;
    sjf_i32_asstring(sjt_functionParam96, &sjt_call35);
    sjt_functionParam95 = &sjt_call35;
    sjf_string_add_heap(sjt_parent67, sjt_functionParam95, _return);

    if (sjt_call22._refCount == 1) { sjf_string_destroy(&sjt_call22); }
    if (sjt_call23._refCount == 1) { sjf_string_destroy(&sjt_call23); }
    if (sjt_call24._refCount == 1) { sjf_string_destroy(&sjt_call24); }
    if (sjt_call25._refCount == 1) { sjf_string_destroy(&sjt_call25); }
    if (sjt_call26._refCount == 1) { sjf_string_destroy(&sjt_call26); }
    if (sjt_call27._refCount == 1) { sjf_string_destroy(&sjt_call27); }
    if (sjt_call28._refCount == 1) { sjf_string_destroy(&sjt_call28); }
    if (sjt_call29._refCount == 1) { sjf_string_destroy(&sjt_call29); }
    if (sjt_call30._refCount == 1) { sjf_string_destroy(&sjt_call30); }
    if (sjt_call31._refCount == 1) { sjf_string_destroy(&sjt_call31); }
    if (sjt_call32._refCount == 1) { sjf_string_destroy(&sjt_call32); }
    if (sjt_call33._refCount == 1) { sjf_string_destroy(&sjt_call33); }
    if (sjt_call34._refCount == 1) { sjf_string_destroy(&sjt_call34); }
    if (sjt_call35._refCount == 1) { sjf_string_destroy(&sjt_call35); }
}

void sjf_rect_containspoint(sjs_rect* _parent, sjs_point* point, bool* _return) {
    bool sjt_and15;
    bool sjt_and16;
    bool sjt_and17;
    bool sjt_and18;
    bool sjt_and19;
    bool sjt_and20;
    int32_t sjt_compare125;
    int32_t sjt_compare126;
    int32_t sjt_compare127;
    int32_t sjt_compare128;
    int32_t sjt_compare129;
    int32_t sjt_compare130;
    int32_t sjt_compare131;
    int32_t sjt_compare132;
    sjs_rect* sjt_dot1667 = 0;
    sjs_point* sjt_dot1668 = 0;
    sjs_rect* sjt_dot1669 = 0;
    sjs_point* sjt_dot1670 = 0;
    sjs_point* sjt_dot1671 = 0;
    sjs_rect* sjt_dot1672 = 0;
    sjs_rect* sjt_dot1673 = 0;
    sjs_point* sjt_dot1674 = 0;
    sjs_rect* sjt_dot1675 = 0;
    sjs_rect* sjt_dot1676 = 0;
    int32_t sjt_math2657;
    int32_t sjt_math2658;
    int32_t sjt_math2659;
    int32_t sjt_math2660;

    sjt_dot1667 = _parent;
    sjt_compare125 = (sjt_dot1667)->x;
    sjt_dot1668 = point;
    sjt_compare126 = (sjt_dot1668)->x;
    sjt_and15 = sjt_compare125 <= sjt_compare126;
    sjt_dot1669 = _parent;
    sjt_compare127 = (sjt_dot1669)->y;
    sjt_dot1670 = point;
    sjt_compare128 = (sjt_dot1670)->x;
    sjt_and17 = sjt_compare127 <= sjt_compare128;
    sjt_dot1671 = point;
    sjt_compare129 = (sjt_dot1671)->x;
    sjt_dot1672 = _parent;
    sjt_math2657 = (sjt_dot1672)->x;
    sjt_dot1673 = _parent;
    sjt_math2658 = (sjt_dot1673)->w;
    sjt_compare130 = sjt_math2657 + sjt_math2658;
    sjt_and19 = sjt_compare129 < sjt_compare130;
    sjt_dot1674 = point;
    sjt_compare131 = (sjt_dot1674)->y;
    sjt_dot1675 = _parent;
    sjt_math2659 = (sjt_dot1675)->y;
    sjt_dot1676 = _parent;
    sjt_math2660 = (sjt_dot1676)->h;
    sjt_compare132 = sjt_math2659 + sjt_math2660;
    sjt_and20 = sjt_compare131 < sjt_compare132;
    sjt_and18 = sjt_and19 && sjt_and20;
    sjt_and16 = sjt_and17 && sjt_and18;
    (*_return) = sjt_and15 && sjt_and16;
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
    int32_t sjt_compare11;
    int32_t sjt_compare12;
    int32_t sjt_compare13;
    int32_t sjt_compare14;
    int32_t sjt_compare15;
    int32_t sjt_compare16;
    int32_t sjt_compare17;
    int32_t sjt_compare18;
    sjs_rect* sjt_dot102 = 0;
    sjs_rect* sjt_dot103 = 0;
    sjs_rect* sjt_dot104 = 0;
    sjs_rect* sjt_dot105 = 0;
    sjs_rect* sjt_dot106 = 0;
    sjs_rect* sjt_dot107 = 0;
    sjs_rect* sjt_dot108 = 0;
    sjs_rect* sjt_dot109 = 0;

    sjt_dot102 = _parent;
    sjt_compare11 = (sjt_dot102)->x;
    sjt_dot103 = rect;
    sjt_compare12 = (sjt_dot103)->x;
    sjt_and3 = sjt_compare11 == sjt_compare12;
    sjt_dot104 = _parent;
    sjt_compare13 = (sjt_dot104)->y;
    sjt_dot105 = rect;
    sjt_compare14 = (sjt_dot105)->y;
    sjt_and5 = sjt_compare13 == sjt_compare14;
    sjt_dot106 = _parent;
    sjt_compare15 = (sjt_dot106)->w;
    sjt_dot107 = rect;
    sjt_compare16 = (sjt_dot107)->w;
    sjt_and7 = sjt_compare15 == sjt_compare16;
    sjt_dot108 = _parent;
    sjt_compare17 = (sjt_dot108)->h;
    sjt_dot109 = rect;
    sjt_compare18 = (sjt_dot109)->h;
    sjt_and8 = sjt_compare17 == sjt_compare18;
    sjt_and6 = sjt_and7 && sjt_and8;
    sjt_and4 = sjt_and5 && sjt_and6;
    (*_return) = sjt_and3 && sjt_and4;
}

void sjf_rect_subtractmargin(sjs_rect* _parent, sjs_margin* margin, sjs_rect* _return) {
    sjs_rect* sjt_dot62 = 0;
    sjs_margin* sjt_dot63 = 0;
    sjs_rect* sjt_dot64 = 0;
    sjs_margin* sjt_dot65 = 0;
    sjs_rect* sjt_dot66 = 0;
    sjs_margin* sjt_dot67 = 0;
    sjs_margin* sjt_dot68 = 0;
    sjs_rect* sjt_dot69 = 0;
    sjs_margin* sjt_dot70 = 0;
    sjs_margin* sjt_dot71 = 0;
    int32_t sjt_math37;
    int32_t sjt_math38;
    int32_t sjt_math39;
    int32_t sjt_math40;
    int32_t sjt_math41;
    int32_t sjt_math42;
    int32_t sjt_math43;
    int32_t sjt_math44;
    int32_t sjt_math45;
    int32_t sjt_math46;
    int32_t sjt_math47;
    int32_t sjt_math48;

    _return->_refCount = 1;
    sjt_dot62 = _parent;
    sjt_math37 = (sjt_dot62)->x;
    sjt_dot63 = margin;
    sjt_math38 = (sjt_dot63)->l;
    _return->x = sjt_math37 + sjt_math38;
    sjt_dot64 = _parent;
    sjt_math39 = (sjt_dot64)->y;
    sjt_dot65 = margin;
    sjt_math40 = (sjt_dot65)->t;
    _return->y = sjt_math39 + sjt_math40;
    sjt_dot66 = _parent;
    sjt_math43 = (sjt_dot66)->w;
    sjt_dot67 = margin;
    sjt_math44 = (sjt_dot67)->l;
    sjt_math41 = sjt_math43 - sjt_math44;
    sjt_dot68 = margin;
    sjt_math42 = (sjt_dot68)->r;
    _return->w = sjt_math41 - sjt_math42;
    sjt_dot69 = _parent;
    sjt_math47 = (sjt_dot69)->h;
    sjt_dot70 = margin;
    sjt_math48 = (sjt_dot70)->t;
    sjt_math45 = sjt_math47 - sjt_math48;
    sjt_dot71 = margin;
    sjt_math46 = (sjt_dot71)->b;
    _return->h = sjt_math45 - sjt_math46;
    sjf_rect(_return);
}

void sjf_rect_subtractmargin_heap(sjs_rect* _parent, sjs_margin* margin, sjs_rect** _return) {
    sjs_rect* sjt_dot72 = 0;
    sjs_margin* sjt_dot73 = 0;
    sjs_rect* sjt_dot74 = 0;
    sjs_margin* sjt_dot75 = 0;
    sjs_rect* sjt_dot76 = 0;
    sjs_margin* sjt_dot77 = 0;
    sjs_margin* sjt_dot78 = 0;
    sjs_rect* sjt_dot79 = 0;
    sjs_margin* sjt_dot80 = 0;
    sjs_margin* sjt_dot81 = 0;
    int32_t sjt_math49;
    int32_t sjt_math50;
    int32_t sjt_math51;
    int32_t sjt_math52;
    int32_t sjt_math53;
    int32_t sjt_math54;
    int32_t sjt_math55;
    int32_t sjt_math56;
    int32_t sjt_math57;
    int32_t sjt_math58;
    int32_t sjt_math59;
    int32_t sjt_math60;

    (*_return) = (sjs_rect*)malloc(sizeof(sjs_rect));
    (*_return)->_refCount = 1;
    sjt_dot72 = _parent;
    sjt_math49 = (sjt_dot72)->x;
    sjt_dot73 = margin;
    sjt_math50 = (sjt_dot73)->l;
    (*_return)->x = sjt_math49 + sjt_math50;
    sjt_dot74 = _parent;
    sjt_math51 = (sjt_dot74)->y;
    sjt_dot75 = margin;
    sjt_math52 = (sjt_dot75)->t;
    (*_return)->y = sjt_math51 + sjt_math52;
    sjt_dot76 = _parent;
    sjt_math55 = (sjt_dot76)->w;
    sjt_dot77 = margin;
    sjt_math56 = (sjt_dot77)->l;
    sjt_math53 = sjt_math55 - sjt_math56;
    sjt_dot78 = margin;
    sjt_math54 = (sjt_dot78)->r;
    (*_return)->w = sjt_math53 - sjt_math54;
    sjt_dot79 = _parent;
    sjt_math59 = (sjt_dot79)->h;
    sjt_dot80 = margin;
    sjt_math60 = (sjt_dot80)->t;
    sjt_math57 = sjt_math59 - sjt_math60;
    sjt_dot81 = margin;
    sjt_math58 = (sjt_dot81)->b;
    (*_return)->h = sjt_math57 - sjt_math58;
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
    sjs_scene2d* sjt_dot690 = 0;
    sjs_scene2d* sjt_dot691 = 0;
    sjs_rect* sjt_functionParam226 = 0;
    sjs_rect* sjt_functionParam227 = 0;

    sjt_dot690 = _parent;
    sjt_functionParam226 = &(sjt_dot690)->windowrect;
    sjt_dot691 = _parent;
    sjt_functionParam227 = &(sjt_dot691)->windowrect;
    sjf_glpopviewport(sjt_functionParam226, sjt_functionParam227);
}

void sjf_scene2d_heap(sjs_scene2d* _this) {
}

void sjf_scene2d_setsize(sjs_scene2d* _parent, sjs_size* size) {
    bool result5;
    sjs_scene2d* sjt_dot304 = 0;
    sjs_size* sjt_functionParam192 = 0;
    bool sjt_ifElse23;
    bool sjt_not3;
    sjs_size* sjt_parent109 = 0;

    sjt_dot304 = _parent;
    sjt_parent109 = &(sjt_dot304)->_size;
    sjt_functionParam192 = size;
    sjf_size_isequal(sjt_parent109, sjt_functionParam192, &sjt_not3);
    result5 = !sjt_not3;
    sjt_ifElse23 = result5;
    if (sjt_ifElse23) {
        float result8;
        float result9;
        int32_t sjt_cast10;
        int32_t sjt_cast9;
        sjs_size* sjt_copy17 = 0;
        sjs_scene2d* sjt_dot305 = 0;
        sjs_scene2d* sjt_dot306 = 0;
        sjs_size* sjt_dot307 = 0;
        sjs_scene2d* sjt_dot308 = 0;
        sjs_size* sjt_dot309 = 0;
        sjs_scene2d* sjt_dot310 = 0;
        sjs_scene2d* sjt_dot311 = 0;
        sjs_scene2d* sjt_dot312 = 0;
        float sjt_functionParam193;
        float sjt_functionParam194;
        float sjt_functionParam195;
        float sjt_functionParam196;
        float sjt_functionParam197;
        float sjt_functionParam198;
        float sjt_functionParam199;
        float sjt_functionParam200;
        float sjt_functionParam201;
        int32_t sjt_math339;
        int32_t sjt_math340;
        float sjt_negate5;
        float sjt_negate6;

        sjt_dot305 = _parent;
        sjt_copy17 = size;
        sjt_dot305->_size._refCount = 1;
        sjf_size_copy(&sjt_dot305->_size, sjt_copy17);
        sjt_dot306 = _parent;
        sjt_functionParam193 = 0.0f;
        sjt_dot308 = _parent;
        sjt_dot307 = &(sjt_dot308)->_size;
        sjt_cast9 = (sjt_dot307)->w;
        sjt_functionParam194 = (float)sjt_cast9;
        sjt_math339 = 0;
        sjt_dot310 = _parent;
        sjt_dot309 = &(sjt_dot310)->_size;
        sjt_math340 = (sjt_dot309)->h;
        sjt_cast10 = sjt_math339 - sjt_math340;
        sjt_functionParam195 = (float)sjt_cast10;
        sjt_functionParam196 = 0.0f;
        sjt_negate5 = 1.0f;
        result8 = -sjt_negate5;
        sjt_functionParam197 = result8;
        sjt_functionParam198 = 1.0f;
        sjf_mat4_orthographic(sjt_functionParam193, sjt_functionParam194, sjt_functionParam195, sjt_functionParam196, sjt_functionParam197, sjt_functionParam198, &sjt_dot306->projection);
        sjt_dot311 = _parent;
        sjt_functionParam199 = 1.0f;
        sjt_negate6 = 1.0f;
        result9 = -sjt_negate6;
        sjt_functionParam200 = result9;
        sjt_functionParam201 = 1.0f;
        sjf_mat4_scale(sjt_functionParam199, sjt_functionParam200, sjt_functionParam201, &sjt_dot311->model);
        sjt_dot312 = _parent;
        sjf_mat4_identity(&sjt_dot312->view);
    }
}

void sjf_scene2d_start(sjs_scene2d* _parent) {
    sjs_scene2d* sjt_dot678 = 0;
    sjs_size* sjt_dot679 = 0;
    sjs_scene2d* sjt_dot680 = 0;
    sjs_size* sjt_dot681 = 0;
    sjs_scene2d* sjt_dot682 = 0;
    sjs_scene2d* sjt_dot683 = 0;
    sjs_scene2d* sjt_dot684 = 0;
    sjs_rect* sjt_functionParam223 = 0;
    sjs_rect* sjt_functionParam224 = 0;

    sjt_dot678 = _parent;
    sjt_dot678->windowrect._refCount = 1;
    sjt_dot678->windowrect.x = 0;
    sjt_dot678->windowrect.y = 0;
    sjt_dot680 = _parent;
    sjt_dot679 = &(sjt_dot680)->_size;
    sjt_dot678->windowrect.w = (sjt_dot679)->w;
    sjt_dot682 = _parent;
    sjt_dot681 = &(sjt_dot682)->_size;
    sjt_dot678->windowrect.h = (sjt_dot681)->h;
    sjf_rect(&sjt_dot678->windowrect);
    sjt_dot683 = _parent;
    sjt_functionParam223 = &(sjt_dot683)->windowrect;
    sjt_dot684 = _parent;
    sjt_functionParam224 = &(sjt_dot684)->windowrect;
    sjf_glpushviewport(sjt_functionParam223, sjt_functionParam224);
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
    glEnable( GL_TEXTURE_2D );
    glDisable( GL_DEPTH_TEST );
}

void sjf_scene2dmodel_copy(sjs_scene2dmodel* _this, sjs_scene2dmodel* _from) {
    _this->id._refCount = 1;
    sjf_string_copy((_this->id._refCount != -1 ? &_this->id : 0), (_from->id._refCount != -1 ? &_from->id : 0));
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
    sjs_mat4 sjt_call56 = { -1 };
    sjs_scene2dmodel* sjt_dot1528 = 0;
    sjs_mouseevent* sjt_dot1529 = 0;
    sjs_scene2dmodel* sjt_dot1530 = 0;
    sjs_scene2dmodel* sjt_dot1531 = 0;
    sjs_scene2dmodel* sjt_dot1532 = 0;
    sjs_scene2dmodel* sjt_dot1533 = 0;
    sjs_scene2dmodel* sjt_dot1534 = 0;
    sjs_point* sjt_functionParam300 = 0;
    sjs_rect* sjt_functionParam301 = 0;
    sjs_mat4* sjt_functionParam302 = 0;
    sjs_mat4* sjt_functionParam303 = 0;
    sjs_mat4* sjt_functionParam304 = 0;
    sjs_mat4* sjt_functionParam305 = 0;
    bool sjt_isEmpty14;
    sjs_vec2* sjt_isEmpty15 = 0;
    sjs_vertexbuffer_vertex_location_texture_normal* sjt_parent171 = 0;
    sjs_mat4* sjt_parent172 = 0;
    sjs_vec2 sjv_texture = { -1 };

    sjt_dot1528 = _parent;
    sjt_parent171 = &(sjt_dot1528)->vertexbuffer;
    sjt_dot1529 = mouseevent;
    sjt_functionParam300 = &(sjt_dot1529)->point;
    sjt_dot1530 = _parent;
    sjt_functionParam301 = &(sjt_dot1530)->_scenerect;
    sjt_dot1531 = _parent;
    sjt_functionParam302 = &(sjt_dot1531)->_projection;
    sjt_dot1532 = _parent;
    sjt_functionParam303 = &(sjt_dot1532)->_view;
    sjt_dot1533 = _parent;
    sjt_parent172 = &(sjt_dot1533)->_world;
    sjt_dot1534 = _parent;
    sjt_functionParam305 = &(sjt_dot1534)->model;
    sjf_mat4_multiply(sjt_parent172, sjt_functionParam305, &sjt_call56);
    sjt_functionParam304 = &sjt_call56;
    sjf_vertexbuffer_vertex_location_texture_normal_translatescreentotexture(sjt_parent171, sjt_functionParam300, sjt_functionParam301, sjt_functionParam302, sjt_functionParam303, sjt_functionParam304, &sjv_texture);
    sjt_isEmpty15 = (sjv_texture._refCount != -1 ? &sjv_texture : 0);
    sjt_isEmpty14 = (sjt_isEmpty15 != 0);
    if (sjt_isEmpty14) {
        sjs_vec2* ifValue13 = 0;
        float sjt_cast16;
        int32_t sjt_cast17;
        float sjt_cast18;
        int32_t sjt_cast19;
        sjs_point* sjt_copy28 = 0;
        sjs_vec2* sjt_dot1535 = 0;
        sjs_size* sjt_dot1536 = 0;
        sjs_scene2dmodel* sjt_dot1537 = 0;
        sjs_size* sjt_dot1538 = 0;
        sjs_scene2dmodel* sjt_dot1539 = 0;
        sjs_vec2* sjt_dot1540 = 0;
        sjs_size* sjt_dot1541 = 0;
        sjs_scene2dmodel* sjt_dot1542 = 0;
        sjs_mouseevent* sjt_dot1543 = 0;
        sjs_mouseevent* sjt_dot1544 = 0;
        sjs_scene2dmodel* sjt_dot1545 = 0;
        sjs_array_heap_iface_element* sjt_functionParam306 = 0;
        float sjt_math2357;
        float sjt_math2358;
        int32_t sjt_math2359;
        int32_t sjt_math2360;
        int32_t sjt_math2361;
        int32_t sjt_math2362;
        float sjt_math2363;
        float sjt_math2364;
        sjs_mouseevent* sjt_parent173 = 0;
        sjs_mouseevent sjv_newmouseevent = { -1 };
        sjs_point sjv_scenepoint = { -1 };
        bool void1;

        ifValue13 = (sjv_texture._refCount != -1 ? &sjv_texture : 0);
        sjv_scenepoint._refCount = 1;
        sjt_dot1535 = ifValue13;
        sjt_math2357 = (sjt_dot1535)->x;
        sjt_dot1537 = _parent;
        sjt_dot1536 = &(sjt_dot1537)->texturesize;
        sjt_cast17 = (sjt_dot1536)->w;
        sjt_math2358 = (float)sjt_cast17;
        sjt_cast16 = sjt_math2357 * sjt_math2358;
        sjv_scenepoint.x = (int32_t)sjt_cast16;
        sjt_dot1539 = _parent;
        sjt_dot1538 = &(sjt_dot1539)->texturesize;
        sjt_math2361 = (sjt_dot1538)->h;
        sjt_math2362 = 1;
        sjt_math2359 = sjt_math2361 - sjt_math2362;
        sjt_dot1540 = ifValue13;
        sjt_math2363 = (sjt_dot1540)->y;
        sjt_dot1542 = _parent;
        sjt_dot1541 = &(sjt_dot1542)->texturesize;
        sjt_cast19 = (sjt_dot1541)->h;
        sjt_math2364 = (float)sjt_cast19;
        sjt_cast18 = sjt_math2363 * sjt_math2364;
        sjt_math2360 = (int32_t)sjt_cast18;
        sjv_scenepoint.y = sjt_math2359 - sjt_math2360;
        sjf_point(&sjv_scenepoint);
        sjv_newmouseevent._refCount = 1;
        sjt_dot1543 = mouseevent;
        sjv_newmouseevent.type = (sjt_dot1543)->type;
        sjt_copy28 = &sjv_scenepoint;
        sjv_newmouseevent.point._refCount = 1;
        sjf_point_copy(&sjv_newmouseevent.point, sjt_copy28);
        sjt_dot1544 = mouseevent;
        sjv_newmouseevent.iscaptured = (sjt_dot1544)->iscaptured;
        sjf_mouseevent(&sjv_newmouseevent);
        sjt_parent173 = &sjv_newmouseevent;
        sjt_dot1545 = _parent;
        sjt_functionParam306 = &(sjt_dot1545)->children;
        sjf_mouseevent_firechildren(sjt_parent173, sjt_functionParam306, &void1);

        if (sjv_newmouseevent._refCount == 1) { sjf_mouseevent_destroy(&sjv_newmouseevent); }
        if (sjv_scenepoint._refCount == 1) { sjf_point_destroy(&sjv_scenepoint); }
    }

    if (sjt_call56._refCount == 1) { sjf_mat4_destroy(&sjt_call56); }
    if (sjv_texture._refCount == 1) { sjf_vec2_destroy(&sjv_texture); }
}

void sjf_scene2dmodel_getcenter(sjs_scene2dmodel* _parent, sjs_vec3* _return) {
    sjs_vec3* sjt_copy23 = 0;
    sjs_scene2dmodel* sjt_dot657 = 0;

    sjt_dot657 = _parent;
    sjt_copy23 = &(sjt_dot657)->center;
    _return->_refCount = 1;
    sjf_vec3_copy(_return, sjt_copy23);
}

void sjf_scene2dmodel_getcenter_heap(sjs_scene2dmodel* _parent, sjs_vec3** _return) {
    sjs_vec3* sjt_copy24 = 0;
    sjs_scene2dmodel* sjt_dot658 = 0;

    sjt_dot658 = _parent;
    sjt_copy24 = &(sjt_dot658)->center;
    (*_return) = (sjs_vec3*)malloc(sizeof(sjs_vec3));
    (*_return)->_refCount = 1;
    sjf_vec3_copy((*_return), sjt_copy24);
}

void sjf_scene2dmodel_getworld(sjs_scene2dmodel* _parent, sjs_mat4* _return) {
    sjs_scene2dmodel* sjt_dot659 = 0;
    sjs_scene2dmodel* sjt_dot660 = 0;
    sjs_mat4* sjt_functionParam214 = 0;
    sjs_mat4* sjt_parent117 = 0;

    sjt_dot659 = _parent;
    sjt_parent117 = &(sjt_dot659)->_world;
    sjt_dot660 = _parent;
    sjt_functionParam214 = &(sjt_dot660)->model;
    sjf_mat4_multiply(sjt_parent117, sjt_functionParam214, _return);
}

void sjf_scene2dmodel_getworld_heap(sjs_scene2dmodel* _parent, sjs_mat4** _return) {
    sjs_scene2dmodel* sjt_dot661 = 0;
    sjs_scene2dmodel* sjt_dot662 = 0;
    sjs_mat4* sjt_functionParam215 = 0;
    sjs_mat4* sjt_parent118 = 0;

    sjt_dot661 = _parent;
    sjt_parent118 = &(sjt_dot661)->_world;
    sjt_dot662 = _parent;
    sjt_functionParam215 = &(sjt_dot662)->model;
    sjf_mat4_multiply_heap(sjt_parent118, sjt_functionParam215, _return);
}

void sjf_scene2dmodel_getz(sjs_scene2dmodel* _parent, float* _return) {
    sjs_vec4* sjt_dot655 = 0;
    sjs_scene2dmodel* sjt_dot656 = 0;

    sjt_dot656 = _parent;
    sjt_dot655 = &(sjt_dot656)->_projectedcenter;
    (*_return) = (sjt_dot655)->z;
}

void sjf_scene2dmodel_heap(sjs_scene2dmodel* _this) {
    int32_t i;
    sjs_string sjt_call39 = { -1 };
    int32_t sjt_compare55;
    int32_t sjt_compare56;
    sjs_size* sjt_dot313 = 0;
    sjs_size* sjt_dot314 = 0;
    sjs_array_heap_iface_element* sjt_dot315 = 0;
    int32_t sjt_forEnd12;
    int32_t sjt_forStart12;
    sjs_size* sjt_functionParam146 = 0;
    sjs_size* sjt_functionParam147 = 0;
    sjs_size* sjt_functionParam148 = 0;
    sjs_framebuffer* sjt_functionParam155 = 0;
    int32_t sjt_functionParam156;
    sjs_texture* sjt_functionParam157 = 0;
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
    int32_t sjt_functionParam169;
    int32_t sjt_functionParam170;
    int32_t sjt_functionParam171;
    int32_t sjt_functionParam172;
    sjs_size* sjt_functionParam173 = 0;
    int32_t sjt_functionParam174;
    void* sjt_functionParam175;
    int32_t sjt_functionParam176;
    int32_t sjt_functionParam177;
    sjs_texture* sjt_functionParam178 = 0;
    int32_t sjt_functionParam179;
    sjs_renderbuffer* sjt_functionParam180 = 0;
    int32_t sjt_functionParam181;
    sjs_size* sjt_functionParam182 = 0;
    int32_t sjt_functionParam183;
    sjs_renderbuffer* sjt_functionParam184 = 0;
    sjs_framebuffer* sjt_functionParam191 = 0;
    sjs_size* sjt_functionParam202 = 0;
    bool sjt_ifElse20;
    bool sjt_isEmpty5;
    sjs_string* sjt_isEmpty6 = 0;
    sjs_scene2d* sjt_parent110 = 0;
    sjs_rect sjv_rect = { -1 };
    int32_t sjv_status;

    sjt_isEmpty6 = (_this->id._refCount != -1 ? &_this->id : 0);
    sjt_isEmpty5 = (sjt_isEmpty6 != 0);
    if (sjt_isEmpty5) {
        sjs_string* ifValue2 = 0;
        sjs_scene2dmodel* sjt_cast8 = 0;
        sjs_string* sjt_functionParam144 = 0;
        sji_model sjt_functionParam145 = { 0 };
        sjs_hash_string_weak_iface_model* sjt_parent97 = 0;

        ifValue2 = (_this->id._refCount != -1 ? &_this->id : 0);
        sjt_parent97 = &sjv_modelsbyid;
        sjt_functionParam144 = ifValue2;
        sjt_cast8 = _this;
        sjf_scene2dmodel_as_sji_model(sjt_cast8, &sjt_functionParam145);
        delete_cb weakptrcb14 = { &sjt_functionParam145._parent, weakptr_clear };
        if (sjt_functionParam145._parent != 0) { weakptr_cb_add(sjt_functionParam145._parent, weakptrcb14); }
        sjf_hash_string_weak_iface_model_setat(sjt_parent97, sjt_functionParam144, sjt_functionParam145);

        delete_cb weakptrcb15 = { &sjt_functionParam145._parent, weakptr_clear };
        if (sjt_functionParam145._parent != 0) { weakptr_cb_remove(sjt_functionParam145._parent, weakptrcb15); }
    }

    sjt_functionParam146 = &_this->texturesize;
    sjf_glgenframebuffer(sjt_functionParam146, &_this->_framebuffer);
    sjt_functionParam147 = &_this->texturesize;
    sjf_glgentexture(sjt_functionParam147, &_this->_texture);
    sjt_functionParam148 = &_this->texturesize;
    sjf_glgenrenderbuffer(sjt_functionParam148, &_this->_renderbuffer);
    sjt_functionParam155 = &_this->_framebuffer;
    sjf_glpushframebuffer(sjt_functionParam155);
    sjt_functionParam156 = sjv_gltexture_gl_texture_2d;
    sjt_functionParam157 = &_this->_texture;
    sjf_glbindtexture(sjt_functionParam156, sjt_functionParam157);
    sjt_functionParam158 = sjv_gltexture_gl_texture_2d;
    sjt_functionParam159 = sjv_gltextureattribute_gl_texture_wrap_s;
    sjt_functionParam160 = sjv_gltexturevalue_gl_clamp_to_edge;
    sjf_gltexparameteri(sjt_functionParam158, sjt_functionParam159, sjt_functionParam160);
    sjt_functionParam161 = sjv_gltexture_gl_texture_2d;
    sjt_functionParam162 = sjv_gltextureattribute_gl_texture_wrap_t;
    sjt_functionParam163 = sjv_gltexturevalue_gl_clamp_to_edge;
    sjf_gltexparameteri(sjt_functionParam161, sjt_functionParam162, sjt_functionParam163);
    sjt_functionParam164 = sjv_gltexture_gl_texture_2d;
    sjt_functionParam165 = sjv_gltextureattribute_gl_texture_min_filter;
    sjt_functionParam166 = sjv_gltexturevalue_gl_linear;
    sjf_gltexparameteri(sjt_functionParam164, sjt_functionParam165, sjt_functionParam166);
    sjt_functionParam167 = sjv_gltexture_gl_texture_2d;
    sjt_functionParam168 = sjv_gltextureattribute_gl_texture_mag_filter;
    sjt_functionParam169 = sjv_gltexturevalue_gl_linear;
    sjf_gltexparameteri(sjt_functionParam167, sjt_functionParam168, sjt_functionParam169);
    sjt_functionParam170 = sjv_gltexture_gl_texture_2d;
    sjt_functionParam171 = 0;
    sjt_functionParam172 = sjv_gltextureformat_gl_rgba;
    sjt_functionParam173 = &_this->texturesize;
    sjt_functionParam174 = sjv_gltexturetype_gl_unsigned_byte;
    sjt_functionParam175 = 0;
    sjf_glteximage2d(sjt_functionParam170, sjt_functionParam171, sjt_functionParam172, sjt_functionParam173, sjt_functionParam174, sjt_functionParam175);
    sjt_functionParam176 = sjv_glframebufferattachment_gl_color_attachment0;
    sjt_functionParam177 = sjv_glframebuffertexture_gl_texture_2d;
    sjt_functionParam178 = &_this->_texture;
    sjt_functionParam179 = 0;
    sjf_glframebuffertexture2d(sjt_functionParam176, sjt_functionParam177, sjt_functionParam178, sjt_functionParam179);
    sjt_functionParam180 = &_this->_renderbuffer;
    sjf_glbindrenderbuffer(sjt_functionParam180);
    sjt_functionParam181 = sjv_glrenderbufferformat_gl_depth_component16;
    sjt_functionParam182 = &_this->texturesize;
    sjf_glrenderbufferstorage(sjt_functionParam181, sjt_functionParam182);
    sjt_functionParam183 = sjv_glframebufferattachment_gl_depth_attachment;
    sjt_functionParam184 = &_this->_renderbuffer;
    sjf_glframebufferrenderbuffer(sjt_functionParam183, sjt_functionParam184);
    sjf_glcheckframebufferstatus(&sjv_status);
    sjt_compare55 = sjv_status;
    sjt_compare56 = sjv_glframebufferstatus_gl_framebuffer_complete;
    sjt_ifElse20 = sjt_compare55 != sjt_compare56;
    if (sjt_ifElse20) {
        sjs_string* sjt_functionParam185 = 0;

        sjt_call39._refCount = 1;
        sjt_call39.count = 18;
        sjt_call39.data._refCount = 1;
        sjt_call39.data.datasize = 19;
        sjt_call39.data.data = (void*)sjg_string21;
        sjt_call39.data._isglobal = true;
        sjt_call39.data.count = 19;
        sjf_array_char(&sjt_call39.data);
        sjf_string(&sjt_call39);
        sjt_functionParam185 = &sjt_call39;
        sjf_halt(sjt_functionParam185);
    }

    sjt_functionParam191 = &_this->_framebuffer;
    sjf_glpopframebuffer(sjt_functionParam191);
    sjt_parent110 = &_this->_innerscene;
    sjt_functionParam202 = &_this->texturesize;
    sjf_scene2d_setsize(sjt_parent110, sjt_functionParam202);
    sjv_rect._refCount = 1;
    sjv_rect.x = 0;
    sjv_rect.y = 0;
    sjt_dot313 = &_this->texturesize;
    sjv_rect.w = (sjt_dot313)->w;
    sjt_dot314 = &_this->texturesize;
    sjv_rect.h = (sjt_dot314)->h;
    sjf_rect(&sjv_rect);
    sjt_forStart12 = 0;
    sjt_dot315 = &_this->children;
    sjt_forEnd12 = (sjt_dot315)->count;
    i = sjt_forStart12;
    while (i < sjt_forEnd12) {
        int32_t sjt_functionParam203;
        sjs_rect* sjt_interfaceParam17 = 0;
        sjs_array_heap_iface_element* sjt_parent111 = 0;
        sji_element sjt_parent112 = { 0 };
        sji_element sjv_child = { 0 };

        sjt_parent111 = &_this->children;
        sjt_functionParam203 = i;
        sjf_array_heap_iface_element_getat_heap(sjt_parent111, sjt_functionParam203, &sjv_child);
        sjt_parent112 = sjv_child;
        sjt_interfaceParam17 = &sjv_rect;
        sjt_parent112._vtbl->setrect(sjt_parent112._parent, sjt_interfaceParam17);
        i++;

        if (sjv_child._parent != 0) {
            sjv_child._parent->_refCount--;
            if (sjv_child._parent->_refCount <= 0) {
                sjv_child._vtbl->destroy(sjv_child._parent);
                free(sjv_child._parent);
            }
        }
    }

    if (sjt_call39._refCount == 1) { sjf_string_destroy(&sjt_call39); }
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

        default: {
            _return->_parent = 0;
            break;
        }
    }
}

void sjf_scene2dmodel_render(sjs_scene2dmodel* _parent) {
    int32_t i;
    sjs_mat4 sjt_call45 = { -1 };
    sjs_mat4 sjt_call46 = { -1 };
    sjs_string sjt_call47 = { -1 };
    sjs_string sjt_call48 = { -1 };
    sjs_string sjt_call49 = { -1 };
    sjs_string sjt_call50 = { -1 };
    sjs_string sjt_call51 = { -1 };
    sjs_vec3 sjt_call52 = { -1 };
    sjs_string sjt_call53 = { -1 };
    sjs_vec3 sjt_call54 = { -1 };
    sjs_scene2dmodel* sjt_dot1433 = 0;
    sjs_scene2dmodel* sjt_dot1434 = 0;
    sjs_scene2dmodel* sjt_dot1435 = 0;
    sjs_scene2dmodel* sjt_dot1436 = 0;
    sjs_scene2dmodel* sjt_dot1437 = 0;
    sjs_scene2dmodel* sjt_dot1438 = 0;
    sjs_scene2dmodel* sjt_dot1439 = 0;
    sjs_light* sjt_dot1440 = 0;
    sjs_scene2dmodel* sjt_dot1441 = 0;
    sjs_scene2dmodel* sjt_dot1442 = 0;
    sjs_light* sjt_dot1449 = 0;
    sjs_scene2dmodel* sjt_dot1450 = 0;
    sjs_scene2dmodel* sjt_dot1451 = 0;
    sjs_light* sjt_dot1452 = 0;
    sjs_scene2dmodel* sjt_dot1453 = 0;
    sjs_scene2dmodel* sjt_dot1454 = 0;
    sjs_scene2dmodel* sjt_dot677 = 0;
    sjs_scene2dmodel* sjt_dot685 = 0;
    sjs_array_heap_iface_element* sjt_dot686 = 0;
    sjs_scene2dmodel* sjt_dot687 = 0;
    sjs_scene2dmodel* sjt_dot692 = 0;
    sjs_scene2dmodel* sjt_dot693 = 0;
    sjs_scene2dmodel* sjt_dot694 = 0;
    sjs_scene2dmodel* sjt_dot695 = 0;
    sjs_scene2dmodel* sjt_dot696 = 0;
    int32_t sjt_forEnd13;
    int32_t sjt_forStart13;
    sjs_framebuffer* sjt_functionParam222 = 0;
    sjs_framebuffer* sjt_functionParam228 = 0;
    int32_t sjt_functionParam229;
    sjs_mat4* sjt_functionParam230 = 0;
    sjs_mat4* sjt_functionParam231 = 0;
    sjs_shader* sjt_functionParam234 = 0;
    int32_t sjt_functionParam235;
    sjs_texture* sjt_functionParam236 = 0;
    int32_t sjt_functionParam237;
    sjs_shader* sjt_functionParam238 = 0;
    sjs_string* sjt_functionParam239 = 0;
    sjs_mat4* sjt_functionParam240 = 0;
    int32_t sjt_functionParam241;
    sjs_shader* sjt_functionParam242 = 0;
    sjs_string* sjt_functionParam243 = 0;
    sjs_mat4* sjt_functionParam244 = 0;
    int32_t sjt_functionParam245;
    sjs_shader* sjt_functionParam246 = 0;
    sjs_string* sjt_functionParam247 = 0;
    sjs_mat4* sjt_functionParam248 = 0;
    int32_t sjt_functionParam249;
    sjs_shader* sjt_functionParam250 = 0;
    sjs_string* sjt_functionParam251 = 0;
    sjs_vec3* sjt_functionParam252 = 0;
    int32_t sjt_functionParam253;
    sjs_shader* sjt_functionParam254 = 0;
    sjs_string* sjt_functionParam255 = 0;
    sjs_vec3* sjt_functionParam256 = 0;
    int32_t sjt_functionParam257;
    sjs_shader* sjt_functionParam258 = 0;
    sjs_string* sjt_functionParam259 = 0;
    sjs_vec3* sjt_functionParam260 = 0;
    sjs_scene2d* sjt_parent122 = 0;
    sjs_scene2d* sjt_parent125 = 0;
    sjs_mat4* sjt_parent126 = 0;
    sjs_mat4* sjt_parent127 = 0;
    sjs_mat4* sjt_parent128 = 0;
    sjs_mat4* sjt_parent131 = 0;
    sjs_color* sjt_parent132 = 0;
    sjs_color* sjt_parent133 = 0;
    sjs_vertexbuffer_vertex_location_texture_normal* sjt_parent134 = 0;
    sjs_mat4 sjv_normalmat = { -1 };
    sjs_mat4 sjv_viewworld = { -1 };

    sjt_dot677 = _parent;
    sjt_functionParam222 = &(sjt_dot677)->_framebuffer;
    sjf_glpushframebuffer(sjt_functionParam222);
    sjt_dot685 = _parent;
    sjt_parent122 = &(sjt_dot685)->_innerscene;
    sjf_scene2d_start(sjt_parent122);
    sjt_forStart13 = 0;
    sjt_dot687 = _parent;
    sjt_dot686 = &(sjt_dot687)->children;
    sjt_forEnd13 = (sjt_dot686)->count;
    i = sjt_forStart13;
    while (i < sjt_forEnd13) {
        sjs_scene2dmodel* sjt_dot688 = 0;
        sjs_scene2dmodel* sjt_dot689 = 0;
        int32_t sjt_functionParam225;
        sjs_scene2d* sjt_interfaceParam18 = 0;
        sjs_array_heap_iface_element* sjt_parent123 = 0;
        sji_element sjt_parent124 = { 0 };
        sji_element sjv_child = { 0 };

        sjt_dot688 = _parent;
        sjt_parent123 = &(sjt_dot688)->children;
        sjt_functionParam225 = i;
        sjf_array_heap_iface_element_getat_heap(sjt_parent123, sjt_functionParam225, &sjv_child);
        sjt_parent124 = sjv_child;
        sjt_dot689 = _parent;
        sjt_interfaceParam18 = &(sjt_dot689)->_innerscene;
        sjt_parent124._vtbl->render(sjt_parent124._parent, sjt_interfaceParam18);
        i++;

        if (sjv_child._parent != 0) {
            sjv_child._parent->_refCount--;
            if (sjv_child._parent->_refCount <= 0) {
                sjv_child._vtbl->destroy(sjv_child._parent);
                free(sjv_child._parent);
            }
        }
    }

    sjt_dot692 = _parent;
    sjt_parent125 = &(sjt_dot692)->_innerscene;
    sjf_scene2d_end(sjt_parent125);
    sjt_dot693 = _parent;
    sjt_functionParam228 = &(sjt_dot693)->_framebuffer;
    sjf_glpopframebuffer(sjt_functionParam228);
    sjt_functionParam229 = sjv_glfeature_gl_depth_test;
    sjf_glenable(sjt_functionParam229);
    sjt_dot694 = _parent;
    sjt_parent127 = &(sjt_dot694)->_view;
    sjt_dot695 = _parent;
    sjt_functionParam230 = &(sjt_dot695)->_world;
    sjf_mat4_multiply(sjt_parent127, sjt_functionParam230, &sjt_call45);
    sjt_parent126 = &sjt_call45;
    sjt_dot696 = _parent;
    sjt_functionParam231 = &(sjt_dot696)->model;
    sjf_mat4_multiply(sjt_parent126, sjt_functionParam231, &sjv_viewworld);
    sjt_parent131 = &sjv_viewworld;
    sjf_mat4_invert(sjt_parent131, &sjt_call46);
    sjt_parent128 = &sjt_call46;
    sjf_mat4_transpose(sjt_parent128, &sjv_normalmat);
    sjt_dot1433 = _parent;
    sjt_functionParam234 = &(sjt_dot1433)->shader;
    sjf_gluseprogram(sjt_functionParam234);
    sjt_functionParam235 = sjv_gltexture_gl_texture_2d;
    sjt_dot1434 = _parent;
    sjt_functionParam236 = &(sjt_dot1434)->_texture;
    sjf_glbindtexture(sjt_functionParam235, sjt_functionParam236);
    sjt_dot1435 = _parent;
    sjt_functionParam238 = &(sjt_dot1435)->shader;
    sjt_call47._refCount = 1;
    sjt_call47.count = 9;
    sjt_call47.data._refCount = 1;
    sjt_call47.data.datasize = 10;
    sjt_call47.data.data = (void*)sjg_string51;
    sjt_call47.data._isglobal = true;
    sjt_call47.data.count = 10;
    sjf_array_char(&sjt_call47.data);
    sjf_string(&sjt_call47);
    sjt_functionParam239 = &sjt_call47;
    sjf_glgetuniformlocation(sjt_functionParam238, sjt_functionParam239, &sjt_functionParam237);
    sjt_functionParam240 = &sjv_viewworld;
    sjf_gluniformmat4(sjt_functionParam237, sjt_functionParam240);
    sjt_dot1436 = _parent;
    sjt_functionParam242 = &(sjt_dot1436)->shader;
    sjt_call48._refCount = 1;
    sjt_call48.count = 9;
    sjt_call48.data._refCount = 1;
    sjt_call48.data.datasize = 10;
    sjt_call48.data.data = (void*)sjg_string52;
    sjt_call48.data._isglobal = true;
    sjt_call48.data.count = 10;
    sjf_array_char(&sjt_call48.data);
    sjf_string(&sjt_call48);
    sjt_functionParam243 = &sjt_call48;
    sjf_glgetuniformlocation(sjt_functionParam242, sjt_functionParam243, &sjt_functionParam241);
    sjt_functionParam244 = &sjv_normalmat;
    sjf_gluniformmat4(sjt_functionParam241, sjt_functionParam244);
    sjt_dot1437 = _parent;
    sjt_functionParam246 = &(sjt_dot1437)->shader;
    sjt_call49._refCount = 1;
    sjt_call49.count = 10;
    sjt_call49.data._refCount = 1;
    sjt_call49.data.datasize = 11;
    sjt_call49.data.data = (void*)sjg_string53;
    sjt_call49.data._isglobal = true;
    sjt_call49.data.count = 11;
    sjf_array_char(&sjt_call49.data);
    sjf_string(&sjt_call49);
    sjt_functionParam247 = &sjt_call49;
    sjf_glgetuniformlocation(sjt_functionParam246, sjt_functionParam247, &sjt_functionParam245);
    sjt_dot1438 = _parent;
    sjt_functionParam248 = &(sjt_dot1438)->_projection;
    sjf_gluniformmat4(sjt_functionParam245, sjt_functionParam248);
    sjt_dot1439 = _parent;
    sjt_functionParam250 = &(sjt_dot1439)->shader;
    sjt_call50._refCount = 1;
    sjt_call50.count = 8;
    sjt_call50.data._refCount = 1;
    sjt_call50.data.datasize = 9;
    sjt_call50.data.data = (void*)sjg_string54;
    sjt_call50.data._isglobal = true;
    sjt_call50.data.count = 9;
    sjf_array_char(&sjt_call50.data);
    sjf_string(&sjt_call50);
    sjt_functionParam251 = &sjt_call50;
    sjf_glgetuniformlocation(sjt_functionParam250, sjt_functionParam251, &sjt_functionParam249);
    sjt_dot1441 = _parent;
    sjt_dot1440 = &(sjt_dot1441)->_light;
    sjt_functionParam252 = &(sjt_dot1440)->pos;
    sjf_gluniformvec3(sjt_functionParam249, sjt_functionParam252);
    sjt_dot1442 = _parent;
    sjt_functionParam254 = &(sjt_dot1442)->shader;
    sjt_call51._refCount = 1;
    sjt_call51.count = 12;
    sjt_call51.data._refCount = 1;
    sjt_call51.data.datasize = 13;
    sjt_call51.data.data = (void*)sjg_string55;
    sjt_call51.data._isglobal = true;
    sjt_call51.data.count = 13;
    sjf_array_char(&sjt_call51.data);
    sjf_string(&sjt_call51);
    sjt_functionParam255 = &sjt_call51;
    sjf_glgetuniformlocation(sjt_functionParam254, sjt_functionParam255, &sjt_functionParam253);
    sjt_dot1450 = _parent;
    sjt_dot1449 = &(sjt_dot1450)->_light;
    sjt_parent132 = &(sjt_dot1449)->diffusecolor;
    sjf_color_asvec3(sjt_parent132, &sjt_call52);
    sjt_functionParam256 = &sjt_call52;
    sjf_gluniformvec3(sjt_functionParam253, sjt_functionParam256);
    sjt_dot1451 = _parent;
    sjt_functionParam258 = &(sjt_dot1451)->shader;
    sjt_call53._refCount = 1;
    sjt_call53.count = 9;
    sjt_call53.data._refCount = 1;
    sjt_call53.data.datasize = 10;
    sjt_call53.data.data = (void*)sjg_string56;
    sjt_call53.data._isglobal = true;
    sjt_call53.data.count = 10;
    sjf_array_char(&sjt_call53.data);
    sjf_string(&sjt_call53);
    sjt_functionParam259 = &sjt_call53;
    sjf_glgetuniformlocation(sjt_functionParam258, sjt_functionParam259, &sjt_functionParam257);
    sjt_dot1453 = _parent;
    sjt_dot1452 = &(sjt_dot1453)->_light;
    sjt_parent133 = &(sjt_dot1452)->speccolor;
    sjf_color_asvec3(sjt_parent133, &sjt_call54);
    sjt_functionParam260 = &sjt_call54;
    sjf_gluniformvec3(sjt_functionParam257, sjt_functionParam260);
    sjt_dot1454 = _parent;
    sjt_parent134 = &(sjt_dot1454)->vertexbuffer;
    sjf_vertexbuffer_vertex_location_texture_normal_render(sjt_parent134);

    if (sjt_call45._refCount == 1) { sjf_mat4_destroy(&sjt_call45); }
    if (sjt_call46._refCount == 1) { sjf_mat4_destroy(&sjt_call46); }
    if (sjt_call47._refCount == 1) { sjf_string_destroy(&sjt_call47); }
    if (sjt_call48._refCount == 1) { sjf_string_destroy(&sjt_call48); }
    if (sjt_call49._refCount == 1) { sjf_string_destroy(&sjt_call49); }
    if (sjt_call50._refCount == 1) { sjf_string_destroy(&sjt_call50); }
    if (sjt_call51._refCount == 1) { sjf_string_destroy(&sjt_call51); }
    if (sjt_call52._refCount == 1) { sjf_vec3_destroy(&sjt_call52); }
    if (sjt_call53._refCount == 1) { sjf_string_destroy(&sjt_call53); }
    if (sjt_call54._refCount == 1) { sjf_vec3_destroy(&sjt_call54); }
    if (sjv_normalmat._refCount == 1) { sjf_mat4_destroy(&sjv_normalmat); }
    if (sjv_viewworld._refCount == 1) { sjf_mat4_destroy(&sjv_viewworld); }
}

void sjf_scene2dmodel_renderorqueue(sjs_scene2dmodel* _parent, sjs_list_local_iface_model* alphamodels) {
    sjs_scene2dmodel* sjt_dot663 = 0;
    bool sjt_ifElse24;

    sjt_dot663 = _parent;
    sjt_ifElse24 = (sjt_dot663)->hasalpha;
    if (sjt_ifElse24) {
        sjs_scene2dmodel* sjt_cast11 = 0;
        sji_model sjt_functionParam221 = { 0 };
        sjs_list_local_iface_model* sjt_parent121 = 0;

        sjt_parent121 = alphamodels;
        sjt_cast11 = _parent;
        sjf_scene2dmodel_as_sji_model(sjt_cast11, &sjt_functionParam221);
        sjf_list_local_iface_model_add(sjt_parent121, sjt_functionParam221);
    } else {
        sjf_scene2dmodel_render(_parent);
    }
}

void sjf_scene2dmodel_update(sjs_scene2dmodel* _parent, sjs_rect* scenerect, sjs_mat4* projection, sjs_mat4* view, sjs_mat4* world, sjs_light* light) {
    sjs_mat4 sjt_call41 = { -1 };
    sjs_mat4 sjt_call42 = { -1 };
    sjs_mat4 sjt_call43 = { -1 };
    sjs_vec4 sjt_call44 = { -1 };
    sjs_rect* sjt_copy18 = 0;
    sjs_mat4* sjt_copy19 = 0;
    sjs_mat4* sjt_copy20 = 0;
    sjs_mat4* sjt_copy21 = 0;
    sjs_light* sjt_copy22 = 0;
    sjs_scene2dmodel* sjt_dot319 = 0;
    sjs_scene2dmodel* sjt_dot320 = 0;
    sjs_scene2dmodel* sjt_dot321 = 0;
    sjs_scene2dmodel* sjt_dot322 = 0;
    sjs_scene2dmodel* sjt_dot323 = 0;
    sjs_scene2dmodel* sjt_dot324 = 0;
    sjs_scene2dmodel* sjt_dot645 = 0;
    sjs_scene2dmodel* sjt_dot646 = 0;
    sjs_scene2dmodel* sjt_dot647 = 0;
    sjs_scene2dmodel* sjt_dot648 = 0;
    sjs_vec3* sjt_dot649 = 0;
    sjs_scene2dmodel* sjt_dot650 = 0;
    sjs_vec3* sjt_dot651 = 0;
    sjs_scene2dmodel* sjt_dot652 = 0;
    sjs_vec3* sjt_dot653 = 0;
    sjs_scene2dmodel* sjt_dot654 = 0;
    sjs_mat4* sjt_functionParam210 = 0;
    sjs_mat4* sjt_functionParam211 = 0;
    sjs_mat4* sjt_functionParam212 = 0;
    sjs_vec4* sjt_functionParam213 = 0;
    sjs_mat4* sjt_parent113 = 0;
    sjs_mat4* sjt_parent114 = 0;
    sjs_mat4* sjt_parent115 = 0;
    sjs_mat4* sjt_parent116 = 0;

    sjt_dot319 = _parent;
    sjt_copy18 = scenerect;
    sjt_dot319->_scenerect._refCount = 1;
    sjf_rect_copy(&sjt_dot319->_scenerect, sjt_copy18);
    sjt_dot320 = _parent;
    sjt_copy19 = projection;
    sjt_dot320->_projection._refCount = 1;
    sjf_mat4_copy(&sjt_dot320->_projection, sjt_copy19);
    sjt_dot321 = _parent;
    sjt_copy20 = view;
    sjt_dot321->_view._refCount = 1;
    sjf_mat4_copy(&sjt_dot321->_view, sjt_copy20);
    sjt_dot322 = _parent;
    sjt_copy21 = world;
    sjt_dot322->_world._refCount = 1;
    sjf_mat4_copy(&sjt_dot322->_world, sjt_copy21);
    sjt_dot323 = _parent;
    sjt_copy22 = light;
    sjt_dot323->_light._refCount = 1;
    sjf_light_copy(&sjt_dot323->_light, sjt_copy22);
    sjt_dot324 = _parent;
    sjt_dot645 = _parent;
    sjt_parent116 = &(sjt_dot645)->_projection;
    sjt_dot646 = _parent;
    sjt_functionParam210 = &(sjt_dot646)->_view;
    sjf_mat4_multiply(sjt_parent116, sjt_functionParam210, &sjt_call43);
    sjt_parent115 = &sjt_call43;
    sjt_dot647 = _parent;
    sjt_functionParam211 = &(sjt_dot647)->_world;
    sjf_mat4_multiply(sjt_parent115, sjt_functionParam211, &sjt_call42);
    sjt_parent114 = &sjt_call42;
    sjt_dot648 = _parent;
    sjt_functionParam212 = &(sjt_dot648)->model;
    sjf_mat4_multiply(sjt_parent114, sjt_functionParam212, &sjt_call41);
    sjt_parent113 = &sjt_call41;
    sjt_call44._refCount = 1;
    sjt_dot650 = _parent;
    sjt_dot649 = &(sjt_dot650)->center;
    sjt_call44.x = (sjt_dot649)->x;
    sjt_dot652 = _parent;
    sjt_dot651 = &(sjt_dot652)->center;
    sjt_call44.y = (sjt_dot651)->y;
    sjt_dot654 = _parent;
    sjt_dot653 = &(sjt_dot654)->center;
    sjt_call44.z = (sjt_dot653)->z;
    sjt_call44.w = 1.0f;
    sjf_vec4(&sjt_call44);
    sjt_functionParam213 = &sjt_call44;
    sjf_mat4_multiplyvec4(sjt_parent113, sjt_functionParam213, &sjt_dot324->_projectedcenter);

    if (sjt_call41._refCount == 1) { sjf_mat4_destroy(&sjt_call41); }
    if (sjt_call42._refCount == 1) { sjf_mat4_destroy(&sjt_call42); }
    if (sjt_call43._refCount == 1) { sjf_mat4_destroy(&sjt_call43); }
    if (sjt_call44._refCount == 1) { sjf_vec4_destroy(&sjt_call44); }
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
}

void sjf_scene3delement_firemouseevent(sjs_scene3delement* _parent, sjs_mouseevent* mouseevent, bool* _return) {
    int32_t i;
    sjs_array_heap_iface_model* sjt_dot279 = 0;
    sjs_scene3delement* sjt_dot280 = 0;
    int32_t sjt_forEnd11;
    int32_t sjt_forStart11;

    sjt_forStart11 = 0;
    sjt_dot280 = _parent;
    sjt_dot279 = &(sjt_dot280)->children;
    sjt_forEnd11 = (sjt_dot279)->count;
    i = sjt_forStart11;
    while (i < sjt_forEnd11) {
        sjs_scene3delement* sjt_dot281 = 0;
        int32_t sjt_functionParam141;
        sjs_mouseevent* sjt_interfaceParam16 = 0;
        sjs_array_heap_iface_model* sjt_parent94 = 0;
        sji_model sjt_parent95 = { 0 };
        sji_model sjv_child = { 0 };

        sjt_dot281 = _parent;
        sjt_parent94 = &(sjt_dot281)->children;
        sjt_functionParam141 = i;
        sjf_array_heap_iface_model_getat_heap(sjt_parent94, sjt_functionParam141, &sjv_child);
        sjt_parent95 = sjv_child;
        sjt_interfaceParam16 = mouseevent;
        sjt_parent95._vtbl->firemouseevent(sjt_parent95._parent, sjt_interfaceParam16);
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
    sjs_rect* sjt_copy4 = 0;
    sjs_scene3delement* sjt_dot100 = 0;

    sjt_dot100 = _parent;
    sjt_copy4 = &(sjt_dot100)->_rect;
    _return->_refCount = 1;
    sjf_rect_copy(_return, sjt_copy4);
}

void sjf_scene3delement_getrect_heap(sjs_scene3delement* _parent, sjs_rect** _return) {
    sjs_rect* sjt_copy5 = 0;
    sjs_scene3delement* sjt_dot101 = 0;

    sjt_dot101 = _parent;
    sjt_copy5 = &(sjt_dot101)->_rect;
    (*_return) = (sjs_rect*)malloc(sizeof(sjs_rect));
    (*_return)->_refCount = 1;
    sjf_rect_copy((*_return), sjt_copy5);
}

void sjf_scene3delement_getsize(sjs_scene3delement* _parent, sjs_size* maxsize, sjs_size* _return) {
    sjs_size* sjt_dot96 = 0;
    sjs_size* sjt_dot97 = 0;

    _return->_refCount = 1;
    sjt_dot96 = maxsize;
    _return->w = (sjt_dot96)->w;
    sjt_dot97 = maxsize;
    _return->h = (sjt_dot97)->h;
    sjf_size(_return);
}

void sjf_scene3delement_getsize_heap(sjs_scene3delement* _parent, sjs_size* maxsize, sjs_size** _return) {
    sjs_size* sjt_dot98 = 0;
    sjs_size* sjt_dot99 = 0;

    (*_return) = (sjs_size*)malloc(sizeof(sjs_size));
    (*_return)->_refCount = 1;
    sjt_dot98 = maxsize;
    (*_return)->w = (sjt_dot98)->w;
    sjt_dot99 = maxsize;
    (*_return)->h = (sjt_dot99)->h;
    sjf_size_heap((*_return));
}

void sjf_scene3delement_heap(sjs_scene3delement* _this) {
}

void sjf_scene3delement_heap_as_sji_element(sjs_scene3delement* _this, sji_element* _return) {
    _return->_parent = (sjs_object*)_this;
    _return->_vtbl = &sjs_scene3delement_element_vtbl;
}

void sjf_scene3delement_heap_asinterface(sjs_scene3delement* _this, int typeId, sjs_interface* _return) {
    switch (typeId) {
        case sji_element_typeId:  {
            sjf_scene3delement_heap_as_sji_element(_this, (sji_element*)_return);
            break;
        }

        default: {
            _return->_parent = 0;
            break;
        }
    }
}

void sjf_scene3delement_render(sjs_scene3delement* _parent, sjs_scene2d* scene) {
    int32_t i;
    sjs_string sjt_call7 = { -1 };
    sjs_array_heap_iface_model* sjt_dot202 = 0;
    sjs_scene3delement* sjt_dot203 = 0;
    sjs_scene3delement* sjt_dot229 = 0;
    sjs_scene2d* sjt_dot230 = 0;
    sjs_scene3delement* sjt_dot258 = 0;
    sjs_array_heap_iface_model* sjt_dot259 = 0;
    sjs_scene3delement* sjt_dot260 = 0;
    sjs_scene3delement* sjt_dot277 = 0;
    sjs_scene2d* sjt_dot278 = 0;
    int32_t sjt_forEnd10;
    int32_t sjt_forEnd6;
    int32_t sjt_forEnd9;
    int32_t sjt_forStart10;
    int32_t sjt_forStart6;
    int32_t sjt_forStart9;
    cb_heap_iface_model_heap_iface_model_i32 sjt_functionParam127;
    sjs_rect* sjt_functionParam138 = 0;
    sjs_rect* sjt_functionParam139 = 0;
    int32_t sjt_functionParam140;
    int32_t sjt_functionParam46;
    sjs_rect* sjt_functionParam53 = 0;
    sjs_rect* sjt_functionParam54 = 0;
    sjs_string* sjt_functionParam55 = 0;
    sjs_rect* sjt_parent74 = 0;
    sjs_list_heap_iface_model* sjt_parent78 = 0;
    sjs_list_heap_iface_model* sjt_parent81 = 0;
    sjs_list_heap_iface_model sjv_a = { -1 };

    sjt_forStart6 = 0;
    sjt_dot203 = _parent;
    sjt_dot202 = &(sjt_dot203)->children;
    sjt_forEnd6 = (sjt_dot202)->count;
    i = sjt_forStart6;
    while (i < sjt_forEnd6) {
        sjs_scene3delement* sjt_dot204 = 0;
        sjs_scene3delement* sjt_dot205 = 0;
        sjs_scene3delement* sjt_dot206 = 0;
        sjs_scene3delement* sjt_dot207 = 0;
        sjs_scene3delement* sjt_dot208 = 0;
        sjs_scene3delement* sjt_dot209 = 0;
        int32_t sjt_functionParam45;
        sjs_rect* sjt_interfaceParam10 = 0;
        sjs_mat4* sjt_interfaceParam11 = 0;
        sjs_mat4* sjt_interfaceParam12 = 0;
        sjs_mat4* sjt_interfaceParam13 = 0;
        sjs_light* sjt_interfaceParam14 = 0;
        sjs_array_heap_iface_model* sjt_parent42 = 0;
        sji_model sjt_parent43 = { 0 };
        sji_model sjv_child = { 0 };

        sjt_dot204 = _parent;
        sjt_parent42 = &(sjt_dot204)->children;
        sjt_functionParam45 = i;
        sjf_array_heap_iface_model_getat_heap(sjt_parent42, sjt_functionParam45, &sjv_child);
        sjt_parent43 = sjv_child;
        sjt_dot205 = _parent;
        sjt_interfaceParam10 = &(sjt_dot205)->_rect;
        sjt_dot206 = _parent;
        sjt_interfaceParam11 = &(sjt_dot206)->projection;
        sjt_dot207 = _parent;
        sjt_interfaceParam12 = &(sjt_dot207)->view;
        sjt_dot208 = _parent;
        sjt_interfaceParam13 = &(sjt_dot208)->world;
        sjt_dot209 = _parent;
        sjt_interfaceParam14 = &(sjt_dot209)->light;
        sjt_parent43._vtbl->update(sjt_parent43._parent, sjt_interfaceParam10, sjt_interfaceParam11, sjt_interfaceParam12, sjt_interfaceParam13, sjt_interfaceParam14);
        i++;

        if (sjv_child._parent != 0) {
            sjv_child._parent->_refCount--;
            if (sjv_child._parent->_refCount <= 0) {
                sjv_child._vtbl->destroy(sjv_child._parent);
                free(sjv_child._parent);
            }
        }
    }

    sjt_functionParam46 = sjv_glfeature_gl_depth_test;
    sjf_glenable(sjt_functionParam46);
    sjt_dot229 = _parent;
    sjt_functionParam53 = &(sjt_dot229)->_rect;
    sjt_dot230 = scene;
    sjt_functionParam54 = &(sjt_dot230)->windowrect;
    sjf_glpushviewport(sjt_functionParam53, sjt_functionParam54);
    sjt_dot258 = _parent;
    sjt_parent74 = &(sjt_dot258)->_rect;
    sjf_rect_asstring(sjt_parent74, &sjt_call7);
    sjt_functionParam55 = &sjt_call7;
    sjf_debug_writeline(sjt_functionParam55);
    sjv_a._refCount = 1;
    sjv_a.array._refCount = 1;
    sjv_a.array.datasize = 0;
    sjv_a.array.data = 0;
    sjv_a.array._isglobal = false;
    sjv_a.array.count = 0;
    sjf_array_heap_iface_model(&sjv_a.array);
    sjf_list_heap_iface_model(&sjv_a);
    sjt_forStart9 = 0;
    sjt_dot260 = _parent;
    sjt_dot259 = &(sjt_dot260)->children;
    sjt_forEnd9 = (sjt_dot259)->count;
    i = sjt_forStart9;
    while (i < sjt_forEnd9) {
        sjs_scene3delement* sjt_dot261 = 0;
        int32_t sjt_functionParam97;
        sjs_list_heap_iface_model* sjt_interfaceParam15 = 0;
        sjs_array_heap_iface_model* sjt_parent75 = 0;
        sji_model sjt_parent76 = { 0 };
        sji_model sjv_child = { 0 };

        sjt_dot261 = _parent;
        sjt_parent75 = &(sjt_dot261)->children;
        sjt_functionParam97 = i;
        sjf_array_heap_iface_model_getat_heap(sjt_parent75, sjt_functionParam97, &sjv_child);
        sjt_parent76 = sjv_child;
        sjt_interfaceParam15 = &sjv_a;
        sjt_parent76._vtbl->renderorqueue(sjt_parent76._parent, sjt_interfaceParam15);
        i++;

        if (sjv_child._parent != 0) {
            sjv_child._parent->_refCount--;
            if (sjv_child._parent->_refCount <= 0) {
                sjv_child._vtbl->destroy(sjv_child._parent);
                free(sjv_child._parent);
            }
        }
    }

    sjt_parent78 = &sjv_a;
    sjt_functionParam127._parent = (sjs_object*)1;
    sjt_functionParam127._cb = (void(*)(sjs_object*,sji_model,sji_model, int32_t*))sjf_model_zsort_callback;
    sjf_list_heap_iface_model_sortcb(sjt_parent78, sjt_functionParam127);
    sjt_forStart10 = 0;
    sjt_parent81 = &sjv_a;
    sjf_list_heap_iface_model_getcount(sjt_parent81, &sjt_forEnd10);
    i = sjt_forEnd10 - 1;
    while (i >= sjt_forStart10) {
        int32_t sjt_functionParam131;
        sjs_list_heap_iface_model* sjt_parent83 = 0;
        sji_model sjt_parent84 = { 0 };
        sji_model sjv_child = { 0 };

        sjt_parent83 = &sjv_a;
        sjt_functionParam131 = i;
        sjf_list_heap_iface_model_getat_heap(sjt_parent83, sjt_functionParam131, &sjv_child);
        sjt_parent84 = sjv_child;
        sjt_parent84._vtbl->render(sjt_parent84._parent);
        i--;

        if (sjv_child._parent != 0) {
            sjv_child._parent->_refCount--;
            if (sjv_child._parent->_refCount <= 0) {
                sjv_child._vtbl->destroy(sjv_child._parent);
                free(sjv_child._parent);
            }
        }
    }

    sjt_dot277 = _parent;
    sjt_functionParam138 = &(sjt_dot277)->_rect;
    sjt_dot278 = scene;
    sjt_functionParam139 = &(sjt_dot278)->windowrect;
    sjf_glpopviewport(sjt_functionParam138, sjt_functionParam139);
    sjt_functionParam140 = sjv_glfeature_gl_depth_test;
    sjf_gldisable(sjt_functionParam140);

    if (sjt_call7._refCount == 1) { sjf_string_destroy(&sjt_call7); }
    if (sjv_a._refCount == 1) { sjf_list_heap_iface_model_destroy(&sjv_a); }
}

void sjf_scene3delement_setrect(sjs_scene3delement* _parent, sjs_rect* rect_) {
    bool result2;
    sjs_scene3delement* sjt_dot110 = 0;
    sjs_rect* sjt_functionParam21 = 0;
    bool sjt_ifElse6;
    bool sjt_not1;
    sjs_rect* sjt_parent25 = 0;

    sjt_dot110 = _parent;
    sjt_parent25 = &(sjt_dot110)->_rect;
    sjt_functionParam21 = rect_;
    sjf_rect_isequal(sjt_parent25, sjt_functionParam21, &sjt_not1);
    result2 = !sjt_not1;
    sjt_ifElse6 = result2;
    if (sjt_ifElse6) {
        int32_t sjt_cast3;
        int32_t sjt_cast4;
        sjs_rect* sjt_copy6 = 0;
        sjs_scene3delement* sjt_dot111 = 0;
        sjs_scene3delement* sjt_dot112 = 0;
        sjs_scene3delement* sjt_dot113 = 0;
        sjs_rect* sjt_dot114 = 0;
        sjs_scene3delement* sjt_dot115 = 0;
        sjs_rect* sjt_dot116 = 0;
        sjs_scene3delement* sjt_dot117 = 0;
        sjs_scene3delement* sjt_dot118 = 0;
        sjs_scene3delement* sjt_dot119 = 0;
        sjs_scene3delement* sjt_dot120 = 0;
        sjs_scene3delement* sjt_dot199 = 0;
        sjs_scene3delement* sjt_dot200 = 0;
        sjs_scene3delement* sjt_dot201 = 0;
        float sjt_functionParam24;
        float sjt_functionParam25;
        float sjt_functionParam26;
        float sjt_functionParam27;
        sjs_vec3* sjt_functionParam42 = 0;
        sjs_vec3* sjt_functionParam43 = 0;
        sjs_vec3* sjt_functionParam44 = 0;
        float sjt_math101;
        float sjt_math102;

        sjt_dot111 = _parent;
        sjt_copy6 = rect_;
        sjt_dot111->_rect._refCount = 1;
        sjf_rect_copy(&sjt_dot111->_rect, sjt_copy6);
        sjt_dot112 = _parent;
        sjt_dot113 = _parent;
        sjt_functionParam24 = (sjt_dot113)->fieldofview;
        sjt_dot115 = _parent;
        sjt_dot114 = &(sjt_dot115)->_rect;
        sjt_cast3 = (sjt_dot114)->h;
        sjt_math101 = (float)sjt_cast3;
        sjt_dot117 = _parent;
        sjt_dot116 = &(sjt_dot117)->_rect;
        sjt_cast4 = (sjt_dot116)->w;
        sjt_math102 = (float)sjt_cast4;
        sjt_functionParam25 = sjt_math101 / sjt_math102;
        sjt_dot118 = _parent;
        sjt_functionParam26 = (sjt_dot118)->znear;
        sjt_dot119 = _parent;
        sjt_functionParam27 = (sjt_dot119)->zfar;
        sjf_mat4_perspective(sjt_functionParam24, sjt_functionParam25, sjt_functionParam26, sjt_functionParam27, &sjt_dot112->projection);
        sjt_dot120 = _parent;
        sjt_dot199 = _parent;
        sjt_functionParam42 = &(sjt_dot199)->camera;
        sjt_dot200 = _parent;
        sjt_functionParam43 = &(sjt_dot200)->lookat;
        sjt_dot201 = _parent;
        sjt_functionParam44 = &(sjt_dot201)->up;
        sjf_mat4_lookatlh(sjt_functionParam42, sjt_functionParam43, sjt_functionParam44, &sjt_dot120->view);
    }
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
    sjs_size* sjt_dot41 = 0;
    sjs_margin* sjt_dot42 = 0;
    sjs_margin* sjt_dot43 = 0;
    sjs_size* sjt_dot44 = 0;
    sjs_margin* sjt_dot45 = 0;
    sjs_margin* sjt_dot46 = 0;
    int32_t sjt_math21;
    int32_t sjt_math22;
    int32_t sjt_math23;
    int32_t sjt_math24;
    int32_t sjt_math25;
    int32_t sjt_math26;
    int32_t sjt_math27;
    int32_t sjt_math28;

    _return->_refCount = 1;
    sjt_dot41 = _parent;
    sjt_math23 = (sjt_dot41)->w;
    sjt_dot42 = margin;
    sjt_math24 = (sjt_dot42)->l;
    sjt_math21 = sjt_math23 + sjt_math24;
    sjt_dot43 = margin;
    sjt_math22 = (sjt_dot43)->r;
    _return->w = sjt_math21 + sjt_math22;
    sjt_dot44 = _parent;
    sjt_math27 = (sjt_dot44)->h;
    sjt_dot45 = margin;
    sjt_math28 = (sjt_dot45)->t;
    sjt_math25 = sjt_math27 + sjt_math28;
    sjt_dot46 = margin;
    sjt_math26 = (sjt_dot46)->b;
    _return->h = sjt_math25 + sjt_math26;
    sjf_size(_return);
}

void sjf_size_addmargin_heap(sjs_size* _parent, sjs_margin* margin, sjs_size** _return) {
    sjs_size* sjt_dot47 = 0;
    sjs_margin* sjt_dot48 = 0;
    sjs_margin* sjt_dot49 = 0;
    sjs_size* sjt_dot50 = 0;
    sjs_margin* sjt_dot51 = 0;
    sjs_margin* sjt_dot52 = 0;
    int32_t sjt_math29;
    int32_t sjt_math30;
    int32_t sjt_math31;
    int32_t sjt_math32;
    int32_t sjt_math33;
    int32_t sjt_math34;
    int32_t sjt_math35;
    int32_t sjt_math36;

    (*_return) = (sjs_size*)malloc(sizeof(sjs_size));
    (*_return)->_refCount = 1;
    sjt_dot47 = _parent;
    sjt_math31 = (sjt_dot47)->w;
    sjt_dot48 = margin;
    sjt_math32 = (sjt_dot48)->l;
    sjt_math29 = sjt_math31 + sjt_math32;
    sjt_dot49 = margin;
    sjt_math30 = (sjt_dot49)->r;
    (*_return)->w = sjt_math29 + sjt_math30;
    sjt_dot50 = _parent;
    sjt_math35 = (sjt_dot50)->h;
    sjt_dot51 = margin;
    sjt_math36 = (sjt_dot51)->t;
    sjt_math33 = sjt_math35 + sjt_math36;
    sjt_dot52 = margin;
    sjt_math34 = (sjt_dot52)->b;
    (*_return)->h = sjt_math33 + sjt_math34;
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
    int32_t sjt_compare61;
    int32_t sjt_compare62;
    int32_t sjt_compare63;
    int32_t sjt_compare64;
    sjs_size* sjt_dot300 = 0;
    sjs_size* sjt_dot301 = 0;
    sjs_size* sjt_dot302 = 0;
    sjs_size* sjt_dot303 = 0;

    sjt_dot300 = _parent;
    sjt_compare61 = (sjt_dot300)->w;
    sjt_dot301 = size;
    sjt_compare62 = (sjt_dot301)->w;
    sjt_and9 = sjt_compare61 == sjt_compare62;
    sjt_dot302 = _parent;
    sjt_compare63 = (sjt_dot302)->h;
    sjt_dot303 = size;
    sjt_compare64 = (sjt_dot303)->h;
    sjt_and10 = sjt_compare63 == sjt_compare64;
    (*_return) = sjt_and9 && sjt_and10;
}

void sjf_size_max(sjs_size* _parent, sjs_size* maxsize, sjs_size* _return) {
    int32_t sjt_compare3;
    int32_t sjt_compare4;
    int32_t sjt_compare5;
    int32_t sjt_compare6;
    sjs_size* sjt_dot25 = 0;
    sjs_size* sjt_dot26 = 0;
    sjs_size* sjt_dot29 = 0;
    sjs_size* sjt_dot30 = 0;
    bool sjt_ifElse1;
    bool sjt_ifElse2;

    _return->_refCount = 1;
    sjt_dot25 = _parent;
    sjt_compare3 = (sjt_dot25)->w;
    sjt_dot26 = maxsize;
    sjt_compare4 = (sjt_dot26)->w;
    sjt_ifElse1 = sjt_compare3 > sjt_compare4;
    if (sjt_ifElse1) {
        sjs_size* sjt_dot27 = 0;

        sjt_dot27 = _parent;
        _return->w = (sjt_dot27)->w;
    } else {
        sjs_size* sjt_dot28 = 0;

        sjt_dot28 = maxsize;
        _return->w = (sjt_dot28)->w;
    }

    sjt_dot29 = _parent;
    sjt_compare5 = (sjt_dot29)->h;
    sjt_dot30 = maxsize;
    sjt_compare6 = (sjt_dot30)->h;
    sjt_ifElse2 = sjt_compare5 > sjt_compare6;
    if (sjt_ifElse2) {
        sjs_size* sjt_dot31 = 0;

        sjt_dot31 = _parent;
        _return->h = (sjt_dot31)->h;
    } else {
        sjs_size* sjt_dot32 = 0;

        sjt_dot32 = maxsize;
        _return->h = (sjt_dot32)->h;
    }

    sjf_size(_return);
}

void sjf_size_max_heap(sjs_size* _parent, sjs_size* maxsize, sjs_size** _return) {
    int32_t sjt_compare10;
    int32_t sjt_compare7;
    int32_t sjt_compare8;
    int32_t sjt_compare9;
    sjs_size* sjt_dot33 = 0;
    sjs_size* sjt_dot34 = 0;
    sjs_size* sjt_dot37 = 0;
    sjs_size* sjt_dot38 = 0;
    bool sjt_ifElse3;
    bool sjt_ifElse4;

    (*_return) = (sjs_size*)malloc(sizeof(sjs_size));
    (*_return)->_refCount = 1;
    sjt_dot33 = _parent;
    sjt_compare7 = (sjt_dot33)->w;
    sjt_dot34 = maxsize;
    sjt_compare8 = (sjt_dot34)->w;
    sjt_ifElse3 = sjt_compare7 > sjt_compare8;
    if (sjt_ifElse3) {
        sjs_size* sjt_dot35 = 0;

        sjt_dot35 = _parent;
        (*_return)->w = (sjt_dot35)->w;
    } else {
        sjs_size* sjt_dot36 = 0;

        sjt_dot36 = maxsize;
        (*_return)->w = (sjt_dot36)->w;
    }

    sjt_dot37 = _parent;
    sjt_compare9 = (sjt_dot37)->h;
    sjt_dot38 = maxsize;
    sjt_compare10 = (sjt_dot38)->h;
    sjt_ifElse4 = sjt_compare9 > sjt_compare10;
    if (sjt_ifElse4) {
        sjs_size* sjt_dot39 = 0;

        sjt_dot39 = _parent;
        (*_return)->h = (sjt_dot39)->h;
    } else {
        sjs_size* sjt_dot40 = 0;

        sjt_dot40 = maxsize;
        (*_return)->h = (sjt_dot40)->h;
    }

    sjf_size_heap((*_return));
}

void sjf_size_min(sjs_size* _parent, sjs_size* maxsize, sjs_size* _return) {
    int32_t sjt_compare113;
    int32_t sjt_compare114;
    int32_t sjt_compare115;
    int32_t sjt_compare116;
    sjs_size* sjt_dot1589 = 0;
    sjs_size* sjt_dot1590 = 0;
    sjs_size* sjt_dot1593 = 0;
    sjs_size* sjt_dot1594 = 0;
    bool sjt_ifElse47;
    bool sjt_ifElse48;

    _return->_refCount = 1;
    sjt_dot1589 = _parent;
    sjt_compare113 = (sjt_dot1589)->w;
    sjt_dot1590 = maxsize;
    sjt_compare114 = (sjt_dot1590)->w;
    sjt_ifElse47 = sjt_compare113 < sjt_compare114;
    if (sjt_ifElse47) {
        sjs_size* sjt_dot1591 = 0;

        sjt_dot1591 = _parent;
        _return->w = (sjt_dot1591)->w;
    } else {
        sjs_size* sjt_dot1592 = 0;

        sjt_dot1592 = maxsize;
        _return->w = (sjt_dot1592)->w;
    }

    sjt_dot1593 = _parent;
    sjt_compare115 = (sjt_dot1593)->h;
    sjt_dot1594 = maxsize;
    sjt_compare116 = (sjt_dot1594)->h;
    sjt_ifElse48 = sjt_compare115 < sjt_compare116;
    if (sjt_ifElse48) {
        sjs_size* sjt_dot1595 = 0;

        sjt_dot1595 = _parent;
        _return->h = (sjt_dot1595)->h;
    } else {
        sjs_size* sjt_dot1596 = 0;

        sjt_dot1596 = maxsize;
        _return->h = (sjt_dot1596)->h;
    }

    sjf_size(_return);
}

void sjf_size_min_heap(sjs_size* _parent, sjs_size* maxsize, sjs_size** _return) {
    int32_t sjt_compare117;
    int32_t sjt_compare118;
    int32_t sjt_compare119;
    int32_t sjt_compare120;
    sjs_size* sjt_dot1597 = 0;
    sjs_size* sjt_dot1598 = 0;
    sjs_size* sjt_dot1601 = 0;
    sjs_size* sjt_dot1602 = 0;
    bool sjt_ifElse49;
    bool sjt_ifElse50;

    (*_return) = (sjs_size*)malloc(sizeof(sjs_size));
    (*_return)->_refCount = 1;
    sjt_dot1597 = _parent;
    sjt_compare117 = (sjt_dot1597)->w;
    sjt_dot1598 = maxsize;
    sjt_compare118 = (sjt_dot1598)->w;
    sjt_ifElse49 = sjt_compare117 < sjt_compare118;
    if (sjt_ifElse49) {
        sjs_size* sjt_dot1599 = 0;

        sjt_dot1599 = _parent;
        (*_return)->w = (sjt_dot1599)->w;
    } else {
        sjs_size* sjt_dot1600 = 0;

        sjt_dot1600 = maxsize;
        (*_return)->w = (sjt_dot1600)->w;
    }

    sjt_dot1601 = _parent;
    sjt_compare119 = (sjt_dot1601)->h;
    sjt_dot1602 = maxsize;
    sjt_compare120 = (sjt_dot1602)->h;
    sjt_ifElse50 = sjt_compare119 < sjt_compare120;
    if (sjt_ifElse50) {
        sjs_size* sjt_dot1603 = 0;

        sjt_dot1603 = _parent;
        (*_return)->h = (sjt_dot1603)->h;
    } else {
        sjs_size* sjt_dot1604 = 0;

        sjt_dot1604 = maxsize;
        (*_return)->h = (sjt_dot1604)->h;
    }

    sjf_size_heap((*_return));
}

void sjf_size_subtractmargin(sjs_size* _parent, sjs_margin* margin, sjs_size* _return) {
    sjs_margin* sjt_dot10 = 0;
    sjs_margin* sjt_dot11 = 0;
    sjs_size* sjt_dot12 = 0;
    sjs_margin* sjt_dot13 = 0;
    sjs_margin* sjt_dot14 = 0;
    sjs_size* sjt_dot9 = 0;
    int32_t sjt_math10;
    int32_t sjt_math11;
    int32_t sjt_math12;
    int32_t sjt_math5;
    int32_t sjt_math6;
    int32_t sjt_math7;
    int32_t sjt_math8;
    int32_t sjt_math9;

    _return->_refCount = 1;
    sjt_dot9 = _parent;
    sjt_math7 = (sjt_dot9)->w;
    sjt_dot10 = margin;
    sjt_math8 = (sjt_dot10)->l;
    sjt_math5 = sjt_math7 - sjt_math8;
    sjt_dot11 = margin;
    sjt_math6 = (sjt_dot11)->r;
    _return->w = sjt_math5 - sjt_math6;
    sjt_dot12 = _parent;
    sjt_math11 = (sjt_dot12)->h;
    sjt_dot13 = margin;
    sjt_math12 = (sjt_dot13)->t;
    sjt_math9 = sjt_math11 - sjt_math12;
    sjt_dot14 = margin;
    sjt_math10 = (sjt_dot14)->b;
    _return->h = sjt_math9 - sjt_math10;
    sjf_size(_return);
}

void sjf_size_subtractmargin_heap(sjs_size* _parent, sjs_margin* margin, sjs_size** _return) {
    sjs_size* sjt_dot15 = 0;
    sjs_margin* sjt_dot16 = 0;
    sjs_margin* sjt_dot17 = 0;
    sjs_size* sjt_dot18 = 0;
    sjs_margin* sjt_dot19 = 0;
    sjs_margin* sjt_dot20 = 0;
    int32_t sjt_math13;
    int32_t sjt_math14;
    int32_t sjt_math15;
    int32_t sjt_math16;
    int32_t sjt_math17;
    int32_t sjt_math18;
    int32_t sjt_math19;
    int32_t sjt_math20;

    (*_return) = (sjs_size*)malloc(sizeof(sjs_size));
    (*_return)->_refCount = 1;
    sjt_dot15 = _parent;
    sjt_math15 = (sjt_dot15)->w;
    sjt_dot16 = margin;
    sjt_math16 = (sjt_dot16)->l;
    sjt_math13 = sjt_math15 - sjt_math16;
    sjt_dot17 = margin;
    sjt_math14 = (sjt_dot17)->r;
    (*_return)->w = sjt_math13 - sjt_math14;
    sjt_dot18 = _parent;
    sjt_math19 = (sjt_dot18)->h;
    sjt_dot19 = margin;
    sjt_math20 = (sjt_dot19)->t;
    sjt_math17 = sjt_math19 - sjt_math20;
    sjt_dot20 = margin;
    sjt_math18 = (sjt_dot20)->b;
    (*_return)->h = sjt_math17 - sjt_math18;
    sjf_size_heap((*_return));
}

void sjf_spherevertexbuffer(int32_t slices, int32_t wedges, sjs_vec3* origin, sjs_vec3* radius, sjs_vertexbuffer_vertex_location_texture_normal* _return) {
    sjs_string* sjt_copy29 = 0;
    sjs_array_i32* sjt_copy30 = 0;
    sjs_array_vertex_location_texture_normal* sjt_copy31 = 0;
    int32_t sjt_forEnd15;
    int32_t sjt_forEnd17;
    int32_t sjt_forStart15;
    int32_t sjt_forStart17;
    int32_t sjt_math2365;
    int32_t sjt_math2366;
    int32_t sjt_math2367;
    int32_t sjt_math2368;
    int32_t sjt_math2369;
    int32_t sjt_math2370;
    int32_t sjt_math2371;
    int32_t sjt_math2372;
    int32_t sjt_math2417;
    int32_t sjt_math2418;
    int32_t sjt_math2419;
    int32_t sjt_math2420;
    sjs_array_i32 sjv_indices = { -1 };
    sjs_array_vertex_location_texture_normal sjv_vertices = { -1 };
    int32_t slice;

    sjv_vertices._refCount = 1;
    sjt_math2367 = slices;
    sjt_math2368 = 1;
    sjt_math2365 = sjt_math2367 + sjt_math2368;
    sjt_math2369 = wedges;
    sjt_math2370 = 1;
    sjt_math2366 = sjt_math2369 + sjt_math2370;
    sjv_vertices.datasize = sjt_math2365 * sjt_math2366;
    sjv_vertices.data = 0;
    sjv_vertices._isglobal = false;
    sjv_vertices.count = 0;
    sjf_array_vertex_location_texture_normal(&sjv_vertices);
    sjt_forStart15 = 0;
    sjt_math2371 = slices;
    sjt_math2372 = 1;
    sjt_forEnd15 = sjt_math2371 + sjt_math2372;
    slice = sjt_forStart15;
    while (slice < sjt_forEnd15) {
        int32_t sjt_cast20;
        int32_t sjt_cast21;
        int32_t sjt_cast22;
        int32_t sjt_cast23;
        sjs_vec3* sjt_dot1546 = 0;
        int32_t sjt_forEnd16;
        int32_t sjt_forStart16;
        float sjt_functionParam307;
        float sjt_functionParam308;
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
        int32_t sjt_math2383;
        int32_t sjt_math2384;
        float sjv_r0;
        float sjv_theta;
        float sjv_tv;
        float sjv_y0;
        int32_t wedge;

        sjt_cast20 = slice;
        sjt_math2373 = (float)sjt_cast20;
        sjt_cast21 = slices;
        sjt_math2374 = (float)sjt_cast21;
        sjv_tv = sjt_math2373 / sjt_math2374;
        sjt_math2379 = sjv_f32_pi;
        sjt_cast22 = slice;
        sjt_math2380 = (float)sjt_cast22;
        sjt_math2377 = sjt_math2379 * sjt_math2380;
        sjt_cast23 = slices;
        sjt_math2378 = (float)sjt_cast23;
        sjt_math2375 = sjt_math2377 / sjt_math2378;
        sjt_math2376 = sjv_f32_pi;
        sjv_theta = sjt_math2375 + sjt_math2376;
        sjt_functionParam307 = sjv_theta;
        sjf_f32_cos(sjt_functionParam307, &sjt_math2381);
        sjt_dot1546 = radius;
        sjt_math2382 = (sjt_dot1546)->y;
        sjv_y0 = sjt_math2381 * sjt_math2382;
        sjt_functionParam308 = sjv_theta;
        sjf_f32_sin(sjt_functionParam308, &sjv_r0);
        sjt_forStart16 = 0;
        sjt_math2383 = wedges;
        sjt_math2384 = 1;
        sjt_forEnd16 = sjt_math2383 + sjt_math2384;
        wedge = sjt_forStart16;
        while (wedge < sjt_forEnd16) {
            int32_t sjt_cast24;
            int32_t sjt_cast25;
            int32_t sjt_cast26;
            int32_t sjt_cast27;
            sjs_vec3* sjt_dot1547 = 0;
            sjs_vec3* sjt_dot1548 = 0;
            sjs_vec3* sjt_dot1549 = 0;
            sjs_vec3* sjt_dot1550 = 0;
            sjs_vec3* sjt_dot1551 = 0;
            float sjt_functionParam309;
            float sjt_functionParam310;
            int32_t sjt_functionParam311;
            sjs_vertex_location_texture_normal* sjt_functionParam312 = 0;
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
            float sjt_math2409;
            float sjt_math2410;
            int32_t sjt_math2411;
            int32_t sjt_math2412;
            int32_t sjt_math2413;
            int32_t sjt_math2414;
            int32_t sjt_math2415;
            int32_t sjt_math2416;
            sjs_vec3* sjt_parent174 = 0;
            sjs_array_vertex_location_texture_normal* sjt_parent175 = 0;
            float sjv_angle;
            sjs_vec3 sjv_normal = { -1 };
            float sjv_tu;
            sjs_vertex_location_texture_normal sjv_v = { -1 };
            float sjv_x0;
            float sjv_z0;

            sjt_cast24 = wedge;
            sjt_math2385 = (float)sjt_cast24;
            sjt_cast25 = wedges;
            sjt_math2386 = (float)sjt_cast25;
            sjv_tu = sjt_math2385 / sjt_math2386;
            sjt_math2393 = 2.0f;
            sjt_math2394 = sjv_f32_pi;
            sjt_math2391 = sjt_math2393 * sjt_math2394;
            sjt_cast26 = wedge;
            sjt_math2392 = (float)sjt_cast26;
            sjt_math2389 = sjt_math2391 * sjt_math2392;
            sjt_cast27 = wedges;
            sjt_math2390 = (float)sjt_cast27;
            sjt_math2387 = sjt_math2389 / sjt_math2390;
            sjt_math2395 = 1.5f;
            sjt_math2396 = sjv_f32_pi;
            sjt_math2388 = sjt_math2395 * sjt_math2396;
            sjv_angle = sjt_math2387 - sjt_math2388;
            sjt_functionParam309 = sjv_angle;
            sjf_f32_cos(sjt_functionParam309, &sjt_math2399);
            sjt_math2400 = sjv_r0;
            sjt_math2397 = sjt_math2399 * sjt_math2400;
            sjt_dot1547 = radius;
            sjt_math2398 = (sjt_dot1547)->x;
            sjv_x0 = sjt_math2397 * sjt_math2398;
            sjt_functionParam310 = sjv_angle;
            sjf_f32_sin(sjt_functionParam310, &sjt_math2403);
            sjt_math2404 = sjv_r0;
            sjt_math2401 = sjt_math2403 * sjt_math2404;
            sjt_dot1548 = radius;
            sjt_math2402 = (sjt_dot1548)->y;
            sjv_z0 = sjt_math2401 * sjt_math2402;
            sjv_normal._refCount = 1;
            sjv_normal.x = sjv_x0;
            sjv_normal.y = sjv_y0;
            sjv_normal.z = sjv_z0;
            sjf_vec3(&sjv_normal);
            sjv_v._refCount = 1;
            sjv_v.location._refCount = 1;
            sjt_math2405 = sjv_x0;
            sjt_dot1549 = origin;
            sjt_math2406 = (sjt_dot1549)->x;
            sjv_v.location.x = sjt_math2405 + sjt_math2406;
            sjt_math2407 = sjv_y0;
            sjt_dot1550 = origin;
            sjt_math2408 = (sjt_dot1550)->y;
            sjv_v.location.y = sjt_math2407 + sjt_math2408;
            sjt_math2409 = sjv_z0;
            sjt_dot1551 = origin;
            sjt_math2410 = (sjt_dot1551)->z;
            sjv_v.location.z = sjt_math2409 + sjt_math2410;
            sjf_vec3(&sjv_v.location);
            sjv_v.texture._refCount = 1;
            sjv_v.texture.x = sjv_tu;
            sjv_v.texture.y = sjv_tv;
            sjf_vec2(&sjv_v.texture);
            sjt_parent174 = &sjv_normal;
            sjf_vec3_normalize(sjt_parent174, &sjv_v.normal);
            sjf_vertex_location_texture_normal(&sjv_v);
            sjt_parent175 = &sjv_vertices;
            sjt_math2413 = slice;
            sjt_math2415 = wedges;
            sjt_math2416 = 1;
            sjt_math2414 = sjt_math2415 + sjt_math2416;
            sjt_math2411 = sjt_math2413 * sjt_math2414;
            sjt_math2412 = wedge;
            sjt_functionParam311 = sjt_math2411 + sjt_math2412;
            sjt_functionParam312 = &sjv_v;
            sjf_array_vertex_location_texture_normal_initat(sjt_parent175, sjt_functionParam311, sjt_functionParam312);
            wedge++;

            if (sjv_normal._refCount == 1) { sjf_vec3_destroy(&sjv_normal); }
            if (sjv_v._refCount == 1) { sjf_vertex_location_texture_normal_destroy(&sjv_v); }
        }

        slice++;
    }

    sjv_indices._refCount = 1;
    sjt_math2419 = slices;
    sjt_math2420 = wedges;
    sjt_math2417 = sjt_math2419 * sjt_math2420;
    sjt_math2418 = 6;
    sjv_indices.datasize = sjt_math2417 * sjt_math2418;
    sjv_indices.data = 0;
    sjv_indices._isglobal = false;
    sjv_indices.count = 0;
    sjf_array_i32(&sjv_indices);
    sjt_forStart17 = 0;
    sjt_forEnd17 = slices;
    slice = sjt_forStart17;
    while (slice < sjt_forEnd17) {
        int32_t sjt_forEnd18;
        int32_t sjt_forStart18;
        int32_t wedge;

        sjt_forStart18 = 0;
        sjt_forEnd18 = wedges;
        wedge = sjt_forStart18;
        while (wedge < sjt_forEnd18) {
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
            int32_t sjt_math2421;
            int32_t sjt_math2422;
            int32_t sjt_math2423;
            int32_t sjt_math2424;
            int32_t sjt_math2425;
            int32_t sjt_math2426;
            int32_t sjt_math2427;
            int32_t sjt_math2428;
            int32_t sjt_math2429;
            int32_t sjt_math2430;
            int32_t sjt_math2431;
            int32_t sjt_math2432;
            int32_t sjt_math2433;
            int32_t sjt_math2434;
            int32_t sjt_math2435;
            int32_t sjt_math2436;
            int32_t sjt_math2437;
            int32_t sjt_math2438;
            int32_t sjt_math2439;
            int32_t sjt_math2440;
            int32_t sjt_math2441;
            int32_t sjt_math2442;
            int32_t sjt_math2443;
            int32_t sjt_math2444;
            int32_t sjt_math2445;
            int32_t sjt_math2446;
            int32_t sjt_math2447;
            int32_t sjt_math2448;
            int32_t sjt_math2449;
            int32_t sjt_math2450;
            int32_t sjt_math2451;
            int32_t sjt_math2452;
            int32_t sjt_math2453;
            int32_t sjt_math2454;
            int32_t sjt_math2455;
            int32_t sjt_math2456;
            int32_t sjt_math2457;
            int32_t sjt_math2458;
            int32_t sjt_math2459;
            int32_t sjt_math2460;
            int32_t sjt_math2461;
            int32_t sjt_math2462;
            int32_t sjt_math2463;
            int32_t sjt_math2464;
            int32_t sjt_math2465;
            int32_t sjt_math2466;
            int32_t sjt_math2467;
            int32_t sjt_math2468;
            int32_t sjt_math2469;
            int32_t sjt_math2470;
            int32_t sjt_math2471;
            int32_t sjt_math2472;
            int32_t sjt_math2473;
            int32_t sjt_math2474;
            int32_t sjt_math2475;
            int32_t sjt_math2476;
            int32_t sjt_math2477;
            int32_t sjt_math2478;
            int32_t sjt_math2479;
            int32_t sjt_math2480;
            int32_t sjt_math2481;
            int32_t sjt_math2482;
            int32_t sjt_math2483;
            int32_t sjt_math2484;
            int32_t sjt_math2485;
            int32_t sjt_math2486;
            int32_t sjt_math2487;
            int32_t sjt_math2488;
            int32_t sjt_math2489;
            int32_t sjt_math2490;
            int32_t sjt_math2491;
            int32_t sjt_math2492;
            int32_t sjt_math2493;
            int32_t sjt_math2494;
            int32_t sjt_math2495;
            int32_t sjt_math2496;
            int32_t sjt_math2497;
            int32_t sjt_math2498;
            sjs_array_i32* sjt_parent176 = 0;
            sjs_array_i32* sjt_parent177 = 0;
            sjs_array_i32* sjt_parent178 = 0;
            sjs_array_i32* sjt_parent179 = 0;
            sjs_array_i32* sjt_parent180 = 0;
            sjs_array_i32* sjt_parent181 = 0;
            int32_t sjv_index0;
            int32_t sjv_index1;
            int32_t sjv_index2;
            int32_t sjv_index3;
            int32_t sjv_wedge0;
            int32_t sjv_wedge1;

            sjv_wedge0 = wedge;
            sjt_math2421 = wedge;
            sjt_math2422 = 1;
            sjv_wedge1 = sjt_math2421 + sjt_math2422;
            sjt_math2425 = slice;
            sjt_math2427 = wedges;
            sjt_math2428 = 1;
            sjt_math2426 = sjt_math2427 + sjt_math2428;
            sjt_math2423 = sjt_math2425 * sjt_math2426;
            sjt_math2424 = sjv_wedge0;
            sjv_index0 = sjt_math2423 + sjt_math2424;
            sjt_math2431 = slice;
            sjt_math2433 = wedges;
            sjt_math2434 = 1;
            sjt_math2432 = sjt_math2433 + sjt_math2434;
            sjt_math2429 = sjt_math2431 * sjt_math2432;
            sjt_math2430 = sjv_wedge1;
            sjv_index1 = sjt_math2429 + sjt_math2430;
            sjt_math2439 = slice;
            sjt_math2440 = 1;
            sjt_math2437 = sjt_math2439 + sjt_math2440;
            sjt_math2441 = wedges;
            sjt_math2442 = 1;
            sjt_math2438 = sjt_math2441 + sjt_math2442;
            sjt_math2435 = sjt_math2437 * sjt_math2438;
            sjt_math2436 = sjv_wedge1;
            sjv_index2 = sjt_math2435 + sjt_math2436;
            sjt_math2447 = slice;
            sjt_math2448 = 1;
            sjt_math2445 = sjt_math2447 + sjt_math2448;
            sjt_math2449 = wedges;
            sjt_math2450 = 1;
            sjt_math2446 = sjt_math2449 + sjt_math2450;
            sjt_math2443 = sjt_math2445 * sjt_math2446;
            sjt_math2444 = sjv_wedge0;
            sjv_index3 = sjt_math2443 + sjt_math2444;
            sjt_parent176 = &sjv_indices;
            sjt_math2457 = slice;
            sjt_math2458 = wedges;
            sjt_math2455 = sjt_math2457 * sjt_math2458;
            sjt_math2456 = wedge;
            sjt_math2453 = sjt_math2455 + sjt_math2456;
            sjt_math2454 = 6;
            sjt_math2451 = sjt_math2453 * sjt_math2454;
            sjt_math2452 = 0;
            sjt_functionParam313 = sjt_math2451 + sjt_math2452;
            sjt_functionParam314 = sjv_index0;
            sjf_array_i32_initat(sjt_parent176, sjt_functionParam313, sjt_functionParam314);
            sjt_parent177 = &sjv_indices;
            sjt_math2465 = slice;
            sjt_math2466 = wedges;
            sjt_math2463 = sjt_math2465 * sjt_math2466;
            sjt_math2464 = wedge;
            sjt_math2461 = sjt_math2463 + sjt_math2464;
            sjt_math2462 = 6;
            sjt_math2459 = sjt_math2461 * sjt_math2462;
            sjt_math2460 = 1;
            sjt_functionParam315 = sjt_math2459 + sjt_math2460;
            sjt_functionParam316 = sjv_index1;
            sjf_array_i32_initat(sjt_parent177, sjt_functionParam315, sjt_functionParam316);
            sjt_parent178 = &sjv_indices;
            sjt_math2473 = slice;
            sjt_math2474 = wedges;
            sjt_math2471 = sjt_math2473 * sjt_math2474;
            sjt_math2472 = wedge;
            sjt_math2469 = sjt_math2471 + sjt_math2472;
            sjt_math2470 = 6;
            sjt_math2467 = sjt_math2469 * sjt_math2470;
            sjt_math2468 = 2;
            sjt_functionParam317 = sjt_math2467 + sjt_math2468;
            sjt_functionParam318 = sjv_index2;
            sjf_array_i32_initat(sjt_parent178, sjt_functionParam317, sjt_functionParam318);
            sjt_parent179 = &sjv_indices;
            sjt_math2481 = slice;
            sjt_math2482 = wedges;
            sjt_math2479 = sjt_math2481 * sjt_math2482;
            sjt_math2480 = wedge;
            sjt_math2477 = sjt_math2479 + sjt_math2480;
            sjt_math2478 = 6;
            sjt_math2475 = sjt_math2477 * sjt_math2478;
            sjt_math2476 = 3;
            sjt_functionParam319 = sjt_math2475 + sjt_math2476;
            sjt_functionParam320 = sjv_index2;
            sjf_array_i32_initat(sjt_parent179, sjt_functionParam319, sjt_functionParam320);
            sjt_parent180 = &sjv_indices;
            sjt_math2489 = slice;
            sjt_math2490 = wedges;
            sjt_math2487 = sjt_math2489 * sjt_math2490;
            sjt_math2488 = wedge;
            sjt_math2485 = sjt_math2487 + sjt_math2488;
            sjt_math2486 = 6;
            sjt_math2483 = sjt_math2485 * sjt_math2486;
            sjt_math2484 = 4;
            sjt_functionParam321 = sjt_math2483 + sjt_math2484;
            sjt_functionParam322 = sjv_index3;
            sjf_array_i32_initat(sjt_parent180, sjt_functionParam321, sjt_functionParam322);
            sjt_parent181 = &sjv_indices;
            sjt_math2497 = slice;
            sjt_math2498 = wedges;
            sjt_math2495 = sjt_math2497 * sjt_math2498;
            sjt_math2496 = wedge;
            sjt_math2493 = sjt_math2495 + sjt_math2496;
            sjt_math2494 = 6;
            sjt_math2491 = sjt_math2493 * sjt_math2494;
            sjt_math2492 = 5;
            sjt_functionParam323 = sjt_math2491 + sjt_math2492;
            sjt_functionParam324 = sjv_index0;
            sjf_array_i32_initat(sjt_parent181, sjt_functionParam323, sjt_functionParam324);
            wedge++;
        }

        slice++;
    }

    _return->_refCount = 1;
    sjt_copy29 = &sjv_vertex_location_texture_normal_format;
    _return->format._refCount = 1;
    sjf_string_copy(&_return->format, sjt_copy29);
    sjt_copy30 = &sjv_indices;
    _return->indices._refCount = 1;
    sjf_array_i32_copy(&_return->indices, sjt_copy30);
    sjt_copy31 = &sjv_vertices;
    _return->vertices._refCount = 1;
    sjf_array_vertex_location_texture_normal_copy(&_return->vertices, sjt_copy31);
    sjf_vertexbuffer_vertex_location_texture_normal(_return);

    if (sjv_indices._refCount == 1) { sjf_array_i32_destroy(&sjv_indices); }
    if (sjv_vertices._refCount == 1) { sjf_array_vertex_location_texture_normal_destroy(&sjv_vertices); }
}

void sjf_spherevertexbuffer_heap(int32_t slices, int32_t wedges, sjs_vec3* origin, sjs_vec3* radius, sjs_vertexbuffer_vertex_location_texture_normal** _return) {
    sjs_string* sjt_copy32 = 0;
    sjs_array_i32* sjt_copy33 = 0;
    sjs_array_vertex_location_texture_normal* sjt_copy34 = 0;
    int32_t sjt_forEnd19;
    int32_t sjt_forEnd21;
    int32_t sjt_forStart19;
    int32_t sjt_forStart21;
    int32_t sjt_math2499;
    int32_t sjt_math2500;
    int32_t sjt_math2501;
    int32_t sjt_math2502;
    int32_t sjt_math2503;
    int32_t sjt_math2504;
    int32_t sjt_math2505;
    int32_t sjt_math2506;
    int32_t sjt_math2551;
    int32_t sjt_math2552;
    int32_t sjt_math2553;
    int32_t sjt_math2554;
    sjs_array_i32 sjv_indices = { -1 };
    sjs_array_vertex_location_texture_normal sjv_vertices = { -1 };
    int32_t slice;

    sjv_vertices._refCount = 1;
    sjt_math2501 = slices;
    sjt_math2502 = 1;
    sjt_math2499 = sjt_math2501 + sjt_math2502;
    sjt_math2503 = wedges;
    sjt_math2504 = 1;
    sjt_math2500 = sjt_math2503 + sjt_math2504;
    sjv_vertices.datasize = sjt_math2499 * sjt_math2500;
    sjv_vertices.data = 0;
    sjv_vertices._isglobal = false;
    sjv_vertices.count = 0;
    sjf_array_vertex_location_texture_normal(&sjv_vertices);
    sjt_forStart19 = 0;
    sjt_math2505 = slices;
    sjt_math2506 = 1;
    sjt_forEnd19 = sjt_math2505 + sjt_math2506;
    slice = sjt_forStart19;
    while (slice < sjt_forEnd19) {
        int32_t sjt_cast28;
        int32_t sjt_cast29;
        int32_t sjt_cast30;
        int32_t sjt_cast31;
        sjs_vec3* sjt_dot1552 = 0;
        int32_t sjt_forEnd20;
        int32_t sjt_forStart20;
        float sjt_functionParam325;
        float sjt_functionParam326;
        float sjt_math2507;
        float sjt_math2508;
        float sjt_math2509;
        float sjt_math2510;
        float sjt_math2511;
        float sjt_math2512;
        float sjt_math2513;
        float sjt_math2514;
        float sjt_math2515;
        float sjt_math2516;
        int32_t sjt_math2517;
        int32_t sjt_math2518;
        float sjv_r0;
        float sjv_theta;
        float sjv_tv;
        float sjv_y0;
        int32_t wedge;

        sjt_cast28 = slice;
        sjt_math2507 = (float)sjt_cast28;
        sjt_cast29 = slices;
        sjt_math2508 = (float)sjt_cast29;
        sjv_tv = sjt_math2507 / sjt_math2508;
        sjt_math2513 = sjv_f32_pi;
        sjt_cast30 = slice;
        sjt_math2514 = (float)sjt_cast30;
        sjt_math2511 = sjt_math2513 * sjt_math2514;
        sjt_cast31 = slices;
        sjt_math2512 = (float)sjt_cast31;
        sjt_math2509 = sjt_math2511 / sjt_math2512;
        sjt_math2510 = sjv_f32_pi;
        sjv_theta = sjt_math2509 + sjt_math2510;
        sjt_functionParam325 = sjv_theta;
        sjf_f32_cos(sjt_functionParam325, &sjt_math2515);
        sjt_dot1552 = radius;
        sjt_math2516 = (sjt_dot1552)->y;
        sjv_y0 = sjt_math2515 * sjt_math2516;
        sjt_functionParam326 = sjv_theta;
        sjf_f32_sin(sjt_functionParam326, &sjv_r0);
        sjt_forStart20 = 0;
        sjt_math2517 = wedges;
        sjt_math2518 = 1;
        sjt_forEnd20 = sjt_math2517 + sjt_math2518;
        wedge = sjt_forStart20;
        while (wedge < sjt_forEnd20) {
            int32_t sjt_cast32;
            int32_t sjt_cast33;
            int32_t sjt_cast34;
            int32_t sjt_cast35;
            sjs_vec3* sjt_dot1553 = 0;
            sjs_vec3* sjt_dot1554 = 0;
            sjs_vec3* sjt_dot1555 = 0;
            sjs_vec3* sjt_dot1556 = 0;
            sjs_vec3* sjt_dot1557 = 0;
            float sjt_functionParam327;
            float sjt_functionParam328;
            int32_t sjt_functionParam329;
            sjs_vertex_location_texture_normal* sjt_functionParam330 = 0;
            float sjt_math2519;
            float sjt_math2520;
            float sjt_math2521;
            float sjt_math2522;
            float sjt_math2523;
            float sjt_math2524;
            float sjt_math2525;
            float sjt_math2526;
            float sjt_math2527;
            float sjt_math2528;
            float sjt_math2529;
            float sjt_math2530;
            float sjt_math2531;
            float sjt_math2532;
            float sjt_math2533;
            float sjt_math2534;
            float sjt_math2535;
            float sjt_math2536;
            float sjt_math2537;
            float sjt_math2538;
            float sjt_math2539;
            float sjt_math2540;
            float sjt_math2541;
            float sjt_math2542;
            float sjt_math2543;
            float sjt_math2544;
            int32_t sjt_math2545;
            int32_t sjt_math2546;
            int32_t sjt_math2547;
            int32_t sjt_math2548;
            int32_t sjt_math2549;
            int32_t sjt_math2550;
            sjs_vec3* sjt_parent182 = 0;
            sjs_array_vertex_location_texture_normal* sjt_parent183 = 0;
            float sjv_angle;
            sjs_vec3 sjv_normal = { -1 };
            float sjv_tu;
            sjs_vertex_location_texture_normal sjv_v = { -1 };
            float sjv_x0;
            float sjv_z0;

            sjt_cast32 = wedge;
            sjt_math2519 = (float)sjt_cast32;
            sjt_cast33 = wedges;
            sjt_math2520 = (float)sjt_cast33;
            sjv_tu = sjt_math2519 / sjt_math2520;
            sjt_math2527 = 2.0f;
            sjt_math2528 = sjv_f32_pi;
            sjt_math2525 = sjt_math2527 * sjt_math2528;
            sjt_cast34 = wedge;
            sjt_math2526 = (float)sjt_cast34;
            sjt_math2523 = sjt_math2525 * sjt_math2526;
            sjt_cast35 = wedges;
            sjt_math2524 = (float)sjt_cast35;
            sjt_math2521 = sjt_math2523 / sjt_math2524;
            sjt_math2529 = 1.5f;
            sjt_math2530 = sjv_f32_pi;
            sjt_math2522 = sjt_math2529 * sjt_math2530;
            sjv_angle = sjt_math2521 - sjt_math2522;
            sjt_functionParam327 = sjv_angle;
            sjf_f32_cos(sjt_functionParam327, &sjt_math2533);
            sjt_math2534 = sjv_r0;
            sjt_math2531 = sjt_math2533 * sjt_math2534;
            sjt_dot1553 = radius;
            sjt_math2532 = (sjt_dot1553)->x;
            sjv_x0 = sjt_math2531 * sjt_math2532;
            sjt_functionParam328 = sjv_angle;
            sjf_f32_sin(sjt_functionParam328, &sjt_math2537);
            sjt_math2538 = sjv_r0;
            sjt_math2535 = sjt_math2537 * sjt_math2538;
            sjt_dot1554 = radius;
            sjt_math2536 = (sjt_dot1554)->y;
            sjv_z0 = sjt_math2535 * sjt_math2536;
            sjv_normal._refCount = 1;
            sjv_normal.x = sjv_x0;
            sjv_normal.y = sjv_y0;
            sjv_normal.z = sjv_z0;
            sjf_vec3(&sjv_normal);
            sjv_v._refCount = 1;
            sjv_v.location._refCount = 1;
            sjt_math2539 = sjv_x0;
            sjt_dot1555 = origin;
            sjt_math2540 = (sjt_dot1555)->x;
            sjv_v.location.x = sjt_math2539 + sjt_math2540;
            sjt_math2541 = sjv_y0;
            sjt_dot1556 = origin;
            sjt_math2542 = (sjt_dot1556)->y;
            sjv_v.location.y = sjt_math2541 + sjt_math2542;
            sjt_math2543 = sjv_z0;
            sjt_dot1557 = origin;
            sjt_math2544 = (sjt_dot1557)->z;
            sjv_v.location.z = sjt_math2543 + sjt_math2544;
            sjf_vec3(&sjv_v.location);
            sjv_v.texture._refCount = 1;
            sjv_v.texture.x = sjv_tu;
            sjv_v.texture.y = sjv_tv;
            sjf_vec2(&sjv_v.texture);
            sjt_parent182 = &sjv_normal;
            sjf_vec3_normalize(sjt_parent182, &sjv_v.normal);
            sjf_vertex_location_texture_normal(&sjv_v);
            sjt_parent183 = &sjv_vertices;
            sjt_math2547 = slice;
            sjt_math2549 = wedges;
            sjt_math2550 = 1;
            sjt_math2548 = sjt_math2549 + sjt_math2550;
            sjt_math2545 = sjt_math2547 * sjt_math2548;
            sjt_math2546 = wedge;
            sjt_functionParam329 = sjt_math2545 + sjt_math2546;
            sjt_functionParam330 = &sjv_v;
            sjf_array_vertex_location_texture_normal_initat(sjt_parent183, sjt_functionParam329, sjt_functionParam330);
            wedge++;

            if (sjv_normal._refCount == 1) { sjf_vec3_destroy(&sjv_normal); }
            if (sjv_v._refCount == 1) { sjf_vertex_location_texture_normal_destroy(&sjv_v); }
        }

        slice++;
    }

    sjv_indices._refCount = 1;
    sjt_math2553 = slices;
    sjt_math2554 = wedges;
    sjt_math2551 = sjt_math2553 * sjt_math2554;
    sjt_math2552 = 6;
    sjv_indices.datasize = sjt_math2551 * sjt_math2552;
    sjv_indices.data = 0;
    sjv_indices._isglobal = false;
    sjv_indices.count = 0;
    sjf_array_i32(&sjv_indices);
    sjt_forStart21 = 0;
    sjt_forEnd21 = slices;
    slice = sjt_forStart21;
    while (slice < sjt_forEnd21) {
        int32_t sjt_forEnd22;
        int32_t sjt_forStart22;
        int32_t wedge;

        sjt_forStart22 = 0;
        sjt_forEnd22 = wedges;
        wedge = sjt_forStart22;
        while (wedge < sjt_forEnd22) {
            int32_t sjt_functionParam331;
            int32_t sjt_functionParam332;
            int32_t sjt_functionParam333;
            int32_t sjt_functionParam334;
            int32_t sjt_functionParam335;
            int32_t sjt_functionParam336;
            int32_t sjt_functionParam337;
            int32_t sjt_functionParam338;
            int32_t sjt_functionParam339;
            int32_t sjt_functionParam340;
            int32_t sjt_functionParam341;
            int32_t sjt_functionParam342;
            int32_t sjt_math2555;
            int32_t sjt_math2556;
            int32_t sjt_math2557;
            int32_t sjt_math2558;
            int32_t sjt_math2559;
            int32_t sjt_math2560;
            int32_t sjt_math2561;
            int32_t sjt_math2562;
            int32_t sjt_math2563;
            int32_t sjt_math2564;
            int32_t sjt_math2565;
            int32_t sjt_math2566;
            int32_t sjt_math2567;
            int32_t sjt_math2568;
            int32_t sjt_math2569;
            int32_t sjt_math2570;
            int32_t sjt_math2571;
            int32_t sjt_math2572;
            int32_t sjt_math2573;
            int32_t sjt_math2574;
            int32_t sjt_math2575;
            int32_t sjt_math2576;
            int32_t sjt_math2577;
            int32_t sjt_math2578;
            int32_t sjt_math2579;
            int32_t sjt_math2580;
            int32_t sjt_math2581;
            int32_t sjt_math2582;
            int32_t sjt_math2583;
            int32_t sjt_math2584;
            int32_t sjt_math2585;
            int32_t sjt_math2586;
            int32_t sjt_math2587;
            int32_t sjt_math2588;
            int32_t sjt_math2589;
            int32_t sjt_math2590;
            int32_t sjt_math2591;
            int32_t sjt_math2592;
            int32_t sjt_math2593;
            int32_t sjt_math2594;
            int32_t sjt_math2595;
            int32_t sjt_math2596;
            int32_t sjt_math2597;
            int32_t sjt_math2598;
            int32_t sjt_math2599;
            int32_t sjt_math2600;
            int32_t sjt_math2601;
            int32_t sjt_math2602;
            int32_t sjt_math2603;
            int32_t sjt_math2604;
            int32_t sjt_math2605;
            int32_t sjt_math2606;
            int32_t sjt_math2607;
            int32_t sjt_math2608;
            int32_t sjt_math2609;
            int32_t sjt_math2610;
            int32_t sjt_math2611;
            int32_t sjt_math2612;
            int32_t sjt_math2613;
            int32_t sjt_math2614;
            int32_t sjt_math2615;
            int32_t sjt_math2616;
            int32_t sjt_math2617;
            int32_t sjt_math2618;
            int32_t sjt_math2619;
            int32_t sjt_math2620;
            int32_t sjt_math2621;
            int32_t sjt_math2622;
            int32_t sjt_math2623;
            int32_t sjt_math2624;
            int32_t sjt_math2625;
            int32_t sjt_math2626;
            int32_t sjt_math2627;
            int32_t sjt_math2628;
            int32_t sjt_math2629;
            int32_t sjt_math2630;
            int32_t sjt_math2631;
            int32_t sjt_math2632;
            sjs_array_i32* sjt_parent184 = 0;
            sjs_array_i32* sjt_parent185 = 0;
            sjs_array_i32* sjt_parent186 = 0;
            sjs_array_i32* sjt_parent187 = 0;
            sjs_array_i32* sjt_parent188 = 0;
            sjs_array_i32* sjt_parent189 = 0;
            int32_t sjv_index0;
            int32_t sjv_index1;
            int32_t sjv_index2;
            int32_t sjv_index3;
            int32_t sjv_wedge0;
            int32_t sjv_wedge1;

            sjv_wedge0 = wedge;
            sjt_math2555 = wedge;
            sjt_math2556 = 1;
            sjv_wedge1 = sjt_math2555 + sjt_math2556;
            sjt_math2559 = slice;
            sjt_math2561 = wedges;
            sjt_math2562 = 1;
            sjt_math2560 = sjt_math2561 + sjt_math2562;
            sjt_math2557 = sjt_math2559 * sjt_math2560;
            sjt_math2558 = sjv_wedge0;
            sjv_index0 = sjt_math2557 + sjt_math2558;
            sjt_math2565 = slice;
            sjt_math2567 = wedges;
            sjt_math2568 = 1;
            sjt_math2566 = sjt_math2567 + sjt_math2568;
            sjt_math2563 = sjt_math2565 * sjt_math2566;
            sjt_math2564 = sjv_wedge1;
            sjv_index1 = sjt_math2563 + sjt_math2564;
            sjt_math2573 = slice;
            sjt_math2574 = 1;
            sjt_math2571 = sjt_math2573 + sjt_math2574;
            sjt_math2575 = wedges;
            sjt_math2576 = 1;
            sjt_math2572 = sjt_math2575 + sjt_math2576;
            sjt_math2569 = sjt_math2571 * sjt_math2572;
            sjt_math2570 = sjv_wedge1;
            sjv_index2 = sjt_math2569 + sjt_math2570;
            sjt_math2581 = slice;
            sjt_math2582 = 1;
            sjt_math2579 = sjt_math2581 + sjt_math2582;
            sjt_math2583 = wedges;
            sjt_math2584 = 1;
            sjt_math2580 = sjt_math2583 + sjt_math2584;
            sjt_math2577 = sjt_math2579 * sjt_math2580;
            sjt_math2578 = sjv_wedge0;
            sjv_index3 = sjt_math2577 + sjt_math2578;
            sjt_parent184 = &sjv_indices;
            sjt_math2591 = slice;
            sjt_math2592 = wedges;
            sjt_math2589 = sjt_math2591 * sjt_math2592;
            sjt_math2590 = wedge;
            sjt_math2587 = sjt_math2589 + sjt_math2590;
            sjt_math2588 = 6;
            sjt_math2585 = sjt_math2587 * sjt_math2588;
            sjt_math2586 = 0;
            sjt_functionParam331 = sjt_math2585 + sjt_math2586;
            sjt_functionParam332 = sjv_index0;
            sjf_array_i32_initat(sjt_parent184, sjt_functionParam331, sjt_functionParam332);
            sjt_parent185 = &sjv_indices;
            sjt_math2599 = slice;
            sjt_math2600 = wedges;
            sjt_math2597 = sjt_math2599 * sjt_math2600;
            sjt_math2598 = wedge;
            sjt_math2595 = sjt_math2597 + sjt_math2598;
            sjt_math2596 = 6;
            sjt_math2593 = sjt_math2595 * sjt_math2596;
            sjt_math2594 = 1;
            sjt_functionParam333 = sjt_math2593 + sjt_math2594;
            sjt_functionParam334 = sjv_index1;
            sjf_array_i32_initat(sjt_parent185, sjt_functionParam333, sjt_functionParam334);
            sjt_parent186 = &sjv_indices;
            sjt_math2607 = slice;
            sjt_math2608 = wedges;
            sjt_math2605 = sjt_math2607 * sjt_math2608;
            sjt_math2606 = wedge;
            sjt_math2603 = sjt_math2605 + sjt_math2606;
            sjt_math2604 = 6;
            sjt_math2601 = sjt_math2603 * sjt_math2604;
            sjt_math2602 = 2;
            sjt_functionParam335 = sjt_math2601 + sjt_math2602;
            sjt_functionParam336 = sjv_index2;
            sjf_array_i32_initat(sjt_parent186, sjt_functionParam335, sjt_functionParam336);
            sjt_parent187 = &sjv_indices;
            sjt_math2615 = slice;
            sjt_math2616 = wedges;
            sjt_math2613 = sjt_math2615 * sjt_math2616;
            sjt_math2614 = wedge;
            sjt_math2611 = sjt_math2613 + sjt_math2614;
            sjt_math2612 = 6;
            sjt_math2609 = sjt_math2611 * sjt_math2612;
            sjt_math2610 = 3;
            sjt_functionParam337 = sjt_math2609 + sjt_math2610;
            sjt_functionParam338 = sjv_index2;
            sjf_array_i32_initat(sjt_parent187, sjt_functionParam337, sjt_functionParam338);
            sjt_parent188 = &sjv_indices;
            sjt_math2623 = slice;
            sjt_math2624 = wedges;
            sjt_math2621 = sjt_math2623 * sjt_math2624;
            sjt_math2622 = wedge;
            sjt_math2619 = sjt_math2621 + sjt_math2622;
            sjt_math2620 = 6;
            sjt_math2617 = sjt_math2619 * sjt_math2620;
            sjt_math2618 = 4;
            sjt_functionParam339 = sjt_math2617 + sjt_math2618;
            sjt_functionParam340 = sjv_index3;
            sjf_array_i32_initat(sjt_parent188, sjt_functionParam339, sjt_functionParam340);
            sjt_parent189 = &sjv_indices;
            sjt_math2631 = slice;
            sjt_math2632 = wedges;
            sjt_math2629 = sjt_math2631 * sjt_math2632;
            sjt_math2630 = wedge;
            sjt_math2627 = sjt_math2629 + sjt_math2630;
            sjt_math2628 = 6;
            sjt_math2625 = sjt_math2627 * sjt_math2628;
            sjt_math2626 = 5;
            sjt_functionParam341 = sjt_math2625 + sjt_math2626;
            sjt_functionParam342 = sjv_index0;
            sjf_array_i32_initat(sjt_parent189, sjt_functionParam341, sjt_functionParam342);
            wedge++;
        }

        slice++;
    }

    (*_return) = (sjs_vertexbuffer_vertex_location_texture_normal*)malloc(sizeof(sjs_vertexbuffer_vertex_location_texture_normal));
    (*_return)->_refCount = 1;
    sjt_copy32 = &sjv_vertex_location_texture_normal_format;
    (*_return)->format._refCount = 1;
    sjf_string_copy(&(*_return)->format, sjt_copy32);
    sjt_copy33 = &sjv_indices;
    (*_return)->indices._refCount = 1;
    sjf_array_i32_copy(&(*_return)->indices, sjt_copy33);
    sjt_copy34 = &sjv_vertices;
    (*_return)->vertices._refCount = 1;
    sjf_array_vertex_location_texture_normal_copy(&(*_return)->vertices, sjt_copy34);
    sjf_vertexbuffer_vertex_location_texture_normal_heap((*_return));

    if (sjv_indices._refCount == 1) { sjf_array_i32_destroy(&sjv_indices); }
    if (sjv_vertices._refCount == 1) { sjf_array_vertex_location_texture_normal_destroy(&sjv_vertices); }
}

void sjf_string(sjs_string* _this) {
}

void sjf_string_add(sjs_string* _parent, sjs_string* item, sjs_string* _return) {
    int32_t sjt_compare23;
    int32_t sjt_compare24;
    sjs_string* sjt_dot231 = 0;
    bool sjt_ifElse9;
    sjs_array_char sjv_newdata = { -1 };

    sjt_dot231 = item;
    sjt_compare23 = (sjt_dot231)->count;
    sjt_compare24 = 0;
    sjt_ifElse9 = sjt_compare23 == sjt_compare24;
    if (sjt_ifElse9) {
        sjs_array_char* sjt_copy7 = 0;
        sjs_string* sjt_dot232 = 0;
        sjs_string* sjt_dot233 = 0;

        _return->_refCount = 1;
        sjt_dot232 = _parent;
        _return->count = (sjt_dot232)->count;
        sjt_dot233 = _parent;
        sjt_copy7 = &(sjt_dot233)->data;
        _return->data._refCount = 1;
        sjf_array_char_copy(&_return->data, sjt_copy7);
        sjf_string(_return);
    } else {
        int32_t i;
        int32_t sjt_cast5;
        sjs_array_char* sjt_copy8 = 0;
        sjs_string* sjt_dot236 = 0;
        sjs_string* sjt_dot237 = 0;
        sjs_string* sjt_dot238 = 0;
        sjs_string* sjt_dot239 = 0;
        sjs_string* sjt_dot241 = 0;
        int32_t sjt_forEnd7;
        int32_t sjt_forStart7;
        int32_t sjt_functionParam56;
        int32_t sjt_functionParam57;
        char sjt_functionParam58;
        int32_t sjt_functionParam60;
        int32_t sjt_functionParam64;
        char sjt_functionParam65;
        int32_t sjt_math211;
        int32_t sjt_math212;
        int32_t sjt_math213;
        int32_t sjt_math214;
        int32_t sjt_math215;
        int32_t sjt_math216;
        sjs_array_char* sjt_parent47 = 0;
        sjs_array_char* sjt_parent48 = 0;
        sjs_string* sjt_parent50 = 0;
        sjs_array_char* sjt_parent53 = 0;
        int32_t sjv_newcount;

        sjt_dot236 = _parent;
        sjt_parent47 = &(sjt_dot236)->data;
        sjt_dot237 = _parent;
        sjt_math213 = (sjt_dot237)->count;
        sjt_dot238 = item;
        sjt_math214 = (sjt_dot238)->count;
        sjt_math211 = sjt_math213 + sjt_math214;
        sjt_math212 = 1;
        sjt_functionParam56 = sjt_math211 + sjt_math212;
        sjf_array_char_grow(sjt_parent47, sjt_functionParam56, &sjv_newdata);
        sjt_dot239 = _parent;
        sjv_newcount = (sjt_dot239)->count;
        sjt_parent48 = &sjv_newdata;
        sjt_functionParam57 = sjv_newcount;
        sjt_parent50 = item;
        sjt_functionParam60 = 0;
        sjf_string_getat(sjt_parent50, sjt_functionParam60, &sjt_functionParam58);
        sjf_array_char_setat(sjt_parent48, sjt_functionParam57, sjt_functionParam58);
        sjt_math215 = sjv_newcount;
        sjt_math216 = 1;
        sjv_newcount = sjt_math215 + sjt_math216;
        sjt_forStart7 = 1;
        sjt_dot241 = item;
        sjt_forEnd7 = (sjt_dot241)->count;
        i = sjt_forStart7;
        while (i < sjt_forEnd7) {
            int32_t sjt_functionParam61;
            char sjt_functionParam62;
            int32_t sjt_functionParam63;
            int32_t sjt_math217;
            int32_t sjt_math218;
            sjs_array_char* sjt_parent51 = 0;
            sjs_string* sjt_parent52 = 0;

            sjt_parent51 = &sjv_newdata;
            sjt_functionParam61 = sjv_newcount;
            sjt_parent52 = item;
            sjt_functionParam63 = i;
            sjf_string_getat(sjt_parent52, sjt_functionParam63, &sjt_functionParam62);
            sjf_array_char_initat(sjt_parent51, sjt_functionParam61, sjt_functionParam62);
            sjt_math217 = sjv_newcount;
            sjt_math218 = 1;
            sjv_newcount = sjt_math217 + sjt_math218;
            i++;
        }

        sjt_parent53 = &sjv_newdata;
        sjt_functionParam64 = sjv_newcount;
        sjt_cast5 = 0;
        sjt_functionParam65 = (char)sjt_cast5;
        sjf_array_char_initat(sjt_parent53, sjt_functionParam64, sjt_functionParam65);
        _return->_refCount = 1;
        _return->count = sjv_newcount;
        sjt_copy8 = &sjv_newdata;
        _return->data._refCount = 1;
        sjf_array_char_copy(&_return->data, sjt_copy8);
        sjf_string(_return);
    }

    if (sjv_newdata._refCount == 1) { sjf_array_char_destroy(&sjv_newdata); }
}

void sjf_string_add_heap(sjs_string* _parent, sjs_string* item, sjs_string** _return) {
    int32_t sjt_compare25;
    int32_t sjt_compare26;
    sjs_string* sjt_dot242 = 0;
    bool sjt_ifElse10;
    sjs_array_char sjv_newdata = { -1 };

    sjt_dot242 = item;
    sjt_compare25 = (sjt_dot242)->count;
    sjt_compare26 = 0;
    sjt_ifElse10 = sjt_compare25 == sjt_compare26;
    if (sjt_ifElse10) {
        sjs_array_char* sjt_copy9 = 0;
        sjs_string* sjt_dot243 = 0;
        sjs_string* sjt_dot244 = 0;

        (*_return) = (sjs_string*)malloc(sizeof(sjs_string));
        (*_return)->_refCount = 1;
        sjt_dot243 = _parent;
        (*_return)->count = (sjt_dot243)->count;
        sjt_dot244 = _parent;
        sjt_copy9 = &(sjt_dot244)->data;
        (*_return)->data._refCount = 1;
        sjf_array_char_copy(&(*_return)->data, sjt_copy9);
        sjf_string_heap((*_return));
    } else {
        int32_t i;
        int32_t sjt_cast6;
        sjs_array_char* sjt_copy10 = 0;
        sjs_string* sjt_dot245 = 0;
        sjs_string* sjt_dot246 = 0;
        sjs_string* sjt_dot247 = 0;
        sjs_string* sjt_dot248 = 0;
        sjs_string* sjt_dot249 = 0;
        int32_t sjt_forEnd8;
        int32_t sjt_forStart8;
        int32_t sjt_functionParam66;
        int32_t sjt_functionParam67;
        char sjt_functionParam68;
        int32_t sjt_functionParam69;
        int32_t sjt_functionParam73;
        char sjt_functionParam74;
        int32_t sjt_math219;
        int32_t sjt_math220;
        int32_t sjt_math221;
        int32_t sjt_math222;
        int32_t sjt_math223;
        int32_t sjt_math224;
        sjs_array_char* sjt_parent54 = 0;
        sjs_array_char* sjt_parent55 = 0;
        sjs_string* sjt_parent56 = 0;
        sjs_array_char* sjt_parent59 = 0;
        int32_t sjv_newcount;

        sjt_dot245 = _parent;
        sjt_parent54 = &(sjt_dot245)->data;
        sjt_dot246 = _parent;
        sjt_math221 = (sjt_dot246)->count;
        sjt_dot247 = item;
        sjt_math222 = (sjt_dot247)->count;
        sjt_math219 = sjt_math221 + sjt_math222;
        sjt_math220 = 1;
        sjt_functionParam66 = sjt_math219 + sjt_math220;
        sjf_array_char_grow(sjt_parent54, sjt_functionParam66, &sjv_newdata);
        sjt_dot248 = _parent;
        sjv_newcount = (sjt_dot248)->count;
        sjt_parent55 = &sjv_newdata;
        sjt_functionParam67 = sjv_newcount;
        sjt_parent56 = item;
        sjt_functionParam69 = 0;
        sjf_string_getat(sjt_parent56, sjt_functionParam69, &sjt_functionParam68);
        sjf_array_char_setat(sjt_parent55, sjt_functionParam67, sjt_functionParam68);
        sjt_math223 = sjv_newcount;
        sjt_math224 = 1;
        sjv_newcount = sjt_math223 + sjt_math224;
        sjt_forStart8 = 1;
        sjt_dot249 = item;
        sjt_forEnd8 = (sjt_dot249)->count;
        i = sjt_forStart8;
        while (i < sjt_forEnd8) {
            int32_t sjt_functionParam70;
            char sjt_functionParam71;
            int32_t sjt_functionParam72;
            int32_t sjt_math225;
            int32_t sjt_math226;
            sjs_array_char* sjt_parent57 = 0;
            sjs_string* sjt_parent58 = 0;

            sjt_parent57 = &sjv_newdata;
            sjt_functionParam70 = sjv_newcount;
            sjt_parent58 = item;
            sjt_functionParam72 = i;
            sjf_string_getat(sjt_parent58, sjt_functionParam72, &sjt_functionParam71);
            sjf_array_char_initat(sjt_parent57, sjt_functionParam70, sjt_functionParam71);
            sjt_math225 = sjv_newcount;
            sjt_math226 = 1;
            sjv_newcount = sjt_math225 + sjt_math226;
            i++;
        }

        sjt_parent59 = &sjv_newdata;
        sjt_functionParam73 = sjv_newcount;
        sjt_cast6 = 0;
        sjt_functionParam74 = (char)sjt_cast6;
        sjf_array_char_initat(sjt_parent59, sjt_functionParam73, sjt_functionParam74);
        (*_return) = (sjs_string*)malloc(sizeof(sjs_string));
        (*_return)->_refCount = 1;
        (*_return)->count = sjv_newcount;
        sjt_copy10 = &sjv_newdata;
        (*_return)->data._refCount = 1;
        sjf_array_char_copy(&(*_return)->data, sjt_copy10);
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
    sjs_string* sjt_dot240 = 0;
    int32_t sjt_functionParam59;
    sjs_array_char* sjt_parent49 = 0;

    sjt_dot240 = _parent;
    sjt_parent49 = &(sjt_dot240)->data;
    sjt_functionParam59 = index;
    sjf_array_char_getat(sjt_parent49, sjt_functionParam59, _return);
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
    sjs_size* sjt_dot1560 = 0;
    sjs_texture* sjt_dot1561 = 0;
    sjs_size* sjt_dot1562 = 0;
    sjs_texture* sjt_dot1563 = 0;

    _return->_refCount = 1;
    sjt_dot1561 = _parent;
    sjt_dot1560 = &(sjt_dot1561)->size;
    _return->w = (sjt_dot1560)->w;
    sjt_dot1563 = _parent;
    sjt_dot1562 = &(sjt_dot1563)->size;
    _return->h = (sjt_dot1562)->h;
    sjf_size(_return);
}

void sjf_texture_getsize_heap(sjs_texture* _parent, sjs_size** _return) {
    sjs_size* sjt_dot1564 = 0;
    sjs_texture* sjt_dot1565 = 0;
    sjs_size* sjt_dot1566 = 0;
    sjs_texture* sjt_dot1567 = 0;

    (*_return) = (sjs_size*)malloc(sizeof(sjs_size));
    (*_return)->_refCount = 1;
    sjt_dot1565 = _parent;
    sjt_dot1564 = &(sjt_dot1565)->size;
    (*_return)->w = (sjt_dot1564)->w;
    sjt_dot1567 = _parent;
    sjt_dot1566 = &(sjt_dot1567)->size;
    (*_return)->h = (sjt_dot1566)->h;
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

void sjf_vec3_copy(sjs_vec3* _this, sjs_vec3* _from) {
    _this->x = _from->x;
    _this->y = _from->y;
    _this->z = _from->z;
}

void sjf_vec3_cross(sjs_vec3* _parent, sjs_vec3* v, sjs_vec3* _return) {
    sjs_vec3* sjt_dot151 = 0;
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

    _return->_refCount = 1;
    sjt_dot151 = _parent;
    sjt_math149 = (sjt_dot151)->y;
    sjt_dot152 = v;
    sjt_math150 = (sjt_dot152)->z;
    sjt_math147 = sjt_math149 * sjt_math150;
    sjt_dot153 = _parent;
    sjt_math151 = (sjt_dot153)->z;
    sjt_dot154 = v;
    sjt_math152 = (sjt_dot154)->y;
    sjt_math148 = sjt_math151 * sjt_math152;
    _return->x = sjt_math147 - sjt_math148;
    sjt_dot155 = _parent;
    sjt_math155 = (sjt_dot155)->z;
    sjt_dot156 = v;
    sjt_math156 = (sjt_dot156)->x;
    sjt_math153 = sjt_math155 * sjt_math156;
    sjt_dot157 = _parent;
    sjt_math157 = (sjt_dot157)->x;
    sjt_dot158 = v;
    sjt_math158 = (sjt_dot158)->z;
    sjt_math154 = sjt_math157 * sjt_math158;
    _return->y = sjt_math153 - sjt_math154;
    sjt_dot159 = _parent;
    sjt_math161 = (sjt_dot159)->x;
    sjt_dot160 = v;
    sjt_math162 = (sjt_dot160)->y;
    sjt_math159 = sjt_math161 * sjt_math162;
    sjt_dot161 = _parent;
    sjt_math163 = (sjt_dot161)->y;
    sjt_dot162 = v;
    sjt_math164 = (sjt_dot162)->x;
    sjt_math160 = sjt_math163 * sjt_math164;
    _return->z = sjt_math159 - sjt_math160;
    sjf_vec3(_return);
}

void sjf_vec3_cross_heap(sjs_vec3* _parent, sjs_vec3* v, sjs_vec3** _return) {
    sjs_vec3* sjt_dot163 = 0;
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
    float sjt_math175;
    float sjt_math176;
    float sjt_math177;
    float sjt_math178;
    float sjt_math179;
    float sjt_math180;
    float sjt_math181;
    float sjt_math182;

    (*_return) = (sjs_vec3*)malloc(sizeof(sjs_vec3));
    (*_return)->_refCount = 1;
    sjt_dot163 = _parent;
    sjt_math167 = (sjt_dot163)->y;
    sjt_dot164 = v;
    sjt_math168 = (sjt_dot164)->z;
    sjt_math165 = sjt_math167 * sjt_math168;
    sjt_dot165 = _parent;
    sjt_math169 = (sjt_dot165)->z;
    sjt_dot166 = v;
    sjt_math170 = (sjt_dot166)->y;
    sjt_math166 = sjt_math169 * sjt_math170;
    (*_return)->x = sjt_math165 - sjt_math166;
    sjt_dot167 = _parent;
    sjt_math173 = (sjt_dot167)->z;
    sjt_dot168 = v;
    sjt_math174 = (sjt_dot168)->x;
    sjt_math171 = sjt_math173 * sjt_math174;
    sjt_dot169 = _parent;
    sjt_math175 = (sjt_dot169)->x;
    sjt_dot170 = v;
    sjt_math176 = (sjt_dot170)->z;
    sjt_math172 = sjt_math175 * sjt_math176;
    (*_return)->y = sjt_math171 - sjt_math172;
    sjt_dot171 = _parent;
    sjt_math179 = (sjt_dot171)->x;
    sjt_dot172 = v;
    sjt_math180 = (sjt_dot172)->y;
    sjt_math177 = sjt_math179 * sjt_math180;
    sjt_dot173 = _parent;
    sjt_math181 = (sjt_dot173)->y;
    sjt_dot174 = v;
    sjt_math182 = (sjt_dot174)->x;
    sjt_math178 = sjt_math181 * sjt_math182;
    (*_return)->z = sjt_math177 - sjt_math178;
    sjf_vec3_heap((*_return));
}

void sjf_vec3_destroy(sjs_vec3* _this) {
}

void sjf_vec3_dot(sjs_vec3* _parent, sjs_vec3* v, float* _return) {
    sjs_vec3* sjt_dot184 = 0;
    sjs_vec3* sjt_dot185 = 0;
    sjs_vec3* sjt_dot186 = 0;
    sjs_vec3* sjt_dot187 = 0;
    sjs_vec3* sjt_dot188 = 0;
    sjs_vec3* sjt_dot189 = 0;
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

    sjt_dot184 = _parent;
    sjt_math189 = (sjt_dot184)->x;
    sjt_dot185 = v;
    sjt_math190 = (sjt_dot185)->x;
    sjt_math187 = sjt_math189 * sjt_math190;
    sjt_dot186 = _parent;
    sjt_math191 = (sjt_dot186)->y;
    sjt_dot187 = v;
    sjt_math192 = (sjt_dot187)->y;
    sjt_math188 = sjt_math191 * sjt_math192;
    sjt_math185 = sjt_math187 + sjt_math188;
    sjt_dot188 = _parent;
    sjt_math193 = (sjt_dot188)->z;
    sjt_dot189 = v;
    sjt_math194 = (sjt_dot189)->z;
    sjt_math186 = sjt_math193 * sjt_math194;
    (*_return) = sjt_math185 + sjt_math186;
}

void sjf_vec3_getrawsize(int32_t* _return) {
    int x = sizeof(float) * 3;
    (*_return) = x;
return;;
}

void sjf_vec3_heap(sjs_vec3* _this) {
}

void sjf_vec3_normalize(sjs_vec3* _parent, sjs_vec3* _return) {
    sjs_vec3* sjt_dot133 = 0;
    sjs_vec3* sjt_dot134 = 0;
    sjs_vec3* sjt_dot135 = 0;
    sjs_vec3* sjt_dot136 = 0;
    sjs_vec3* sjt_dot137 = 0;
    sjs_vec3* sjt_dot138 = 0;
    sjs_vec3* sjt_dot139 = 0;
    sjs_vec3* sjt_dot140 = 0;
    sjs_vec3* sjt_dot141 = 0;
    float sjt_functionParam29;
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
    float sjt_math127;
    float sjt_math128;
    float sjt_math129;
    float sjt_math130;
    float sjv_t;

    sjt_dot133 = _parent;
    sjt_math119 = (sjt_dot133)->x;
    sjt_dot134 = _parent;
    sjt_math120 = (sjt_dot134)->x;
    sjt_math117 = sjt_math119 * sjt_math120;
    sjt_dot135 = _parent;
    sjt_math121 = (sjt_dot135)->y;
    sjt_dot136 = _parent;
    sjt_math122 = (sjt_dot136)->y;
    sjt_math118 = sjt_math121 * sjt_math122;
    sjt_math115 = sjt_math117 + sjt_math118;
    sjt_dot137 = _parent;
    sjt_math123 = (sjt_dot137)->z;
    sjt_dot138 = _parent;
    sjt_math124 = (sjt_dot138)->z;
    sjt_math116 = sjt_math123 * sjt_math124;
    sjt_functionParam29 = sjt_math115 + sjt_math116;
    sjf_f32_sqrt(sjt_functionParam29, &sjv_t);
    _return->_refCount = 1;
    sjt_dot139 = _parent;
    sjt_math125 = (sjt_dot139)->x;
    sjt_math126 = sjv_t;
    _return->x = sjt_math125 / sjt_math126;
    sjt_dot140 = _parent;
    sjt_math127 = (sjt_dot140)->y;
    sjt_math128 = sjv_t;
    _return->y = sjt_math127 / sjt_math128;
    sjt_dot141 = _parent;
    sjt_math129 = (sjt_dot141)->z;
    sjt_math130 = sjv_t;
    _return->z = sjt_math129 / sjt_math130;
    sjf_vec3(_return);
}

void sjf_vec3_normalize_heap(sjs_vec3* _parent, sjs_vec3** _return) {
    sjs_vec3* sjt_dot142 = 0;
    sjs_vec3* sjt_dot143 = 0;
    sjs_vec3* sjt_dot144 = 0;
    sjs_vec3* sjt_dot145 = 0;
    sjs_vec3* sjt_dot146 = 0;
    sjs_vec3* sjt_dot147 = 0;
    sjs_vec3* sjt_dot148 = 0;
    sjs_vec3* sjt_dot149 = 0;
    sjs_vec3* sjt_dot150 = 0;
    float sjt_functionParam30;
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
    float sjt_math145;
    float sjt_math146;
    float sjv_t;

    sjt_dot142 = _parent;
    sjt_math135 = (sjt_dot142)->x;
    sjt_dot143 = _parent;
    sjt_math136 = (sjt_dot143)->x;
    sjt_math133 = sjt_math135 * sjt_math136;
    sjt_dot144 = _parent;
    sjt_math137 = (sjt_dot144)->y;
    sjt_dot145 = _parent;
    sjt_math138 = (sjt_dot145)->y;
    sjt_math134 = sjt_math137 * sjt_math138;
    sjt_math131 = sjt_math133 + sjt_math134;
    sjt_dot146 = _parent;
    sjt_math139 = (sjt_dot146)->z;
    sjt_dot147 = _parent;
    sjt_math140 = (sjt_dot147)->z;
    sjt_math132 = sjt_math139 * sjt_math140;
    sjt_functionParam30 = sjt_math131 + sjt_math132;
    sjf_f32_sqrt(sjt_functionParam30, &sjv_t);
    (*_return) = (sjs_vec3*)malloc(sizeof(sjs_vec3));
    (*_return)->_refCount = 1;
    sjt_dot148 = _parent;
    sjt_math141 = (sjt_dot148)->x;
    sjt_math142 = sjv_t;
    (*_return)->x = sjt_math141 / sjt_math142;
    sjt_dot149 = _parent;
    sjt_math143 = (sjt_dot149)->y;
    sjt_math144 = sjv_t;
    (*_return)->y = sjt_math143 / sjt_math144;
    sjt_dot150 = _parent;
    sjt_math145 = (sjt_dot150)->z;
    sjt_math146 = sjv_t;
    (*_return)->z = sjt_math145 / sjt_math146;
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
    sjs_vec3* sjt_dot121 = 0;
    sjs_vec3* sjt_dot122 = 0;
    sjs_vec3* sjt_dot123 = 0;
    sjs_vec3* sjt_dot124 = 0;
    sjs_vec3* sjt_dot125 = 0;
    sjs_vec3* sjt_dot126 = 0;
    float sjt_math103;
    float sjt_math104;
    float sjt_math105;
    float sjt_math106;
    float sjt_math107;
    float sjt_math108;

    _return->_refCount = 1;
    sjt_dot121 = _parent;
    sjt_math103 = (sjt_dot121)->x;
    sjt_dot122 = v;
    sjt_math104 = (sjt_dot122)->x;
    _return->x = sjt_math103 - sjt_math104;
    sjt_dot123 = _parent;
    sjt_math105 = (sjt_dot123)->y;
    sjt_dot124 = v;
    sjt_math106 = (sjt_dot124)->y;
    _return->y = sjt_math105 - sjt_math106;
    sjt_dot125 = _parent;
    sjt_math107 = (sjt_dot125)->z;
    sjt_dot126 = v;
    sjt_math108 = (sjt_dot126)->z;
    _return->z = sjt_math107 - sjt_math108;
    sjf_vec3(_return);
}

void sjf_vec3_subtract_heap(sjs_vec3* _parent, sjs_vec3* v, sjs_vec3** _return) {
    sjs_vec3* sjt_dot127 = 0;
    sjs_vec3* sjt_dot128 = 0;
    sjs_vec3* sjt_dot129 = 0;
    sjs_vec3* sjt_dot130 = 0;
    sjs_vec3* sjt_dot131 = 0;
    sjs_vec3* sjt_dot132 = 0;
    float sjt_math109;
    float sjt_math110;
    float sjt_math111;
    float sjt_math112;
    float sjt_math113;
    float sjt_math114;

    (*_return) = (sjs_vec3*)malloc(sizeof(sjs_vec3));
    (*_return)->_refCount = 1;
    sjt_dot127 = _parent;
    sjt_math109 = (sjt_dot127)->x;
    sjt_dot128 = v;
    sjt_math110 = (sjt_dot128)->x;
    (*_return)->x = sjt_math109 - sjt_math110;
    sjt_dot129 = _parent;
    sjt_math111 = (sjt_dot129)->y;
    sjt_dot130 = v;
    sjt_math112 = (sjt_dot130)->y;
    (*_return)->y = sjt_math111 - sjt_math112;
    sjt_dot131 = _parent;
    sjt_math113 = (sjt_dot131)->z;
    sjt_dot132 = v;
    sjt_math114 = (sjt_dot132)->z;
    (*_return)->z = sjt_math113 - sjt_math114;
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
    int32_t sjt_math341;
    int32_t sjt_math342;
    int32_t sjt_math343;
    int32_t sjt_math344;

    sjf_vec3_getrawsize(&sjt_math343);
    sjf_vec2_getrawsize(&sjt_math344);
    sjt_math341 = sjt_math343 + sjt_math344;
    sjf_vec3_getrawsize(&sjt_math342);
    (*_return) = sjt_math341 + sjt_math342;
}

void sjf_vertex_location_texture_normal_heap(sjs_vertex_location_texture_normal* _this) {
}

void sjf_vertex_location_texture_normal_rawcopy(sjs_vertex_location_texture_normal* v, void* p, void** _return) {
    sjs_vertex_location_texture_normal* sjt_dot316 = 0;
    sjs_vertex_location_texture_normal* sjt_dot317 = 0;
    sjs_vertex_location_texture_normal* sjt_dot318 = 0;
    sjs_vec3* sjt_functionParam204 = 0;
    void* sjt_functionParam205;
    sjs_vec2* sjt_functionParam206 = 0;
    void* sjt_functionParam207;
    sjs_vec3* sjt_functionParam208 = 0;
    void* sjt_functionParam209;

    sjt_dot316 = v;
    sjt_functionParam204 = &(sjt_dot316)->location;
    sjt_functionParam205 = p;
    sjf_vec3_rawcopy(sjt_functionParam204, sjt_functionParam205, &p);
    sjt_dot317 = v;
    sjt_functionParam206 = &(sjt_dot317)->texture;
    sjt_functionParam207 = p;
    sjf_vec2_rawcopy(sjt_functionParam206, sjt_functionParam207, &p);
    sjt_dot318 = v;
    sjt_functionParam208 = &(sjt_dot318)->normal;
    sjt_functionParam209 = p;
    sjf_vec3_rawcopy(sjt_functionParam208, sjt_functionParam209, &p);
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
    sjs_mat4 sjt_call55 = { -1 };
    int32_t sjt_cast12;
    int32_t sjt_cast13;
    int32_t sjt_cast14;
    int32_t sjt_cast15;
    int32_t sjt_compare67;
    int32_t sjt_compare68;
    sjs_vec3* sjt_copy25 = 0;
    sjs_point* sjt_dot1455 = 0;
    sjs_rect* sjt_dot1456 = 0;
    sjs_rect* sjt_dot1457 = 0;
    sjs_point* sjt_dot1458 = 0;
    sjs_rect* sjt_dot1459 = 0;
    sjs_rect* sjt_dot1460 = 0;
    sjs_vec2* sjt_dot1461 = 0;
    sjs_vec2* sjt_dot1462 = 0;
    sjs_vec2* sjt_dot1463 = 0;
    sjs_vec2* sjt_dot1464 = 0;
    sjs_vec4* sjt_dot1465 = 0;
    sjs_vec4* sjt_dot1466 = 0;
    sjs_vec4* sjt_dot1467 = 0;
    sjs_vec4* sjt_dot1468 = 0;
    sjs_vec4* sjt_dot1469 = 0;
    sjs_vec4* sjt_dot1470 = 0;
    sjs_vec4* sjt_dot1471 = 0;
    sjs_vec4* sjt_dot1472 = 0;
    sjs_vec4* sjt_dot1473 = 0;
    sjs_vec4* sjt_dot1474 = 0;
    sjs_vec4* sjt_dot1475 = 0;
    sjs_vec4* sjt_dot1476 = 0;
    sjs_array_i32* sjt_dot1477 = 0;
    sjs_vertexbuffer_vertex_location_texture_normal* sjt_dot1478 = 0;
    int32_t sjt_forEnd14;
    int32_t sjt_forStart14;
    sjs_mat4* sjt_functionParam261 = 0;
    sjs_mat4* sjt_functionParam262 = 0;
    sjs_vec4* sjt_functionParam263 = 0;
    sjs_vec4* sjt_functionParam264 = 0;
    sjs_vec3* sjt_functionParam265 = 0;
    bool sjt_ifElse26;
    bool sjt_ifElse42;
    sjs_vec2* sjt_isEmpty13 = 0;
    float sjt_math2253;
    float sjt_math2254;
    float sjt_math2255;
    float sjt_math2256;
    float sjt_math2257;
    float sjt_math2258;
    int32_t sjt_math2259;
    int32_t sjt_math2260;
    float sjt_math2261;
    float sjt_math2262;
    float sjt_math2263;
    float sjt_math2264;
    float sjt_math2265;
    float sjt_math2266;
    int32_t sjt_math2267;
    int32_t sjt_math2268;
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
    sjs_mat4* sjt_parent135 = 0;
    sjs_mat4* sjt_parent136 = 0;
    sjs_mat4* sjt_parent137 = 0;
    sjs_mat4* sjt_parent138 = 0;
    sjs_mat4* sjt_parent139 = 0;
    sjs_vec3* sjt_parent140 = 0;
    sjs_vec3* sjt_parent141 = 0;
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
    sjt_dot1455 = screen;
    sjt_math2259 = (sjt_dot1455)->x;
    sjt_dot1456 = viewport;
    sjt_math2260 = (sjt_dot1456)->x;
    sjt_cast12 = sjt_math2259 - sjt_math2260;
    sjt_math2257 = (float)sjt_cast12;
    sjt_dot1457 = viewport;
    sjt_cast13 = (sjt_dot1457)->w;
    sjt_math2258 = (float)sjt_cast13;
    sjt_math2255 = sjt_math2257 / sjt_math2258;
    sjt_math2256 = 2.0f;
    sjt_math2253 = sjt_math2255 * sjt_math2256;
    sjt_math2254 = 1.0f;
    sjv_start.x = sjt_math2253 - sjt_math2254;
    sjt_math2261 = 1.0f;
    sjt_dot1458 = screen;
    sjt_math2267 = (sjt_dot1458)->y;
    sjt_dot1459 = viewport;
    sjt_math2268 = (sjt_dot1459)->y;
    sjt_cast14 = sjt_math2267 - sjt_math2268;
    sjt_math2265 = (float)sjt_cast14;
    sjt_dot1460 = viewport;
    sjt_cast15 = (sjt_dot1460)->h;
    sjt_math2266 = (float)sjt_cast15;
    sjt_math2263 = sjt_math2265 / sjt_math2266;
    sjt_math2264 = 2.0f;
    sjt_math2262 = sjt_math2263 * sjt_math2264;
    sjv_start.y = sjt_math2261 - sjt_math2262;
    sjf_vec2(&sjv_start);
    sjv_vscreenorigin1._refCount = 1;
    sjt_dot1461 = &sjv_start;
    sjv_vscreenorigin1.x = (sjt_dot1461)->x;
    sjt_dot1462 = &sjv_start;
    sjv_vscreenorigin1.y = (sjt_dot1462)->y;
    sjv_vscreenorigin1.z = 0.0f;
    sjv_vscreenorigin1.w = 1.0f;
    sjf_vec4(&sjv_vscreenorigin1);
    sjv_vscreenorigin2._refCount = 1;
    sjt_dot1463 = &sjv_start;
    sjv_vscreenorigin2.x = (sjt_dot1463)->x;
    sjt_dot1464 = &sjv_start;
    sjv_vscreenorigin2.y = (sjt_dot1464)->y;
    sjv_vscreenorigin2.z = 1.0f;
    sjv_vscreenorigin2.w = 1.0f;
    sjf_vec4(&sjv_vscreenorigin2);
    sjt_parent136 = projection;
    sjt_functionParam261 = view;
    sjf_mat4_multiply(sjt_parent136, sjt_functionParam261, &sjt_call55);
    sjt_parent135 = &sjt_call55;
    sjt_functionParam262 = world;
    sjf_mat4_multiply(sjt_parent135, sjt_functionParam262, &sjv_all);
    sjt_parent137 = &sjv_all;
    sjf_mat4_invert(sjt_parent137, &sjv_allinverse);
    sjt_parent138 = &sjv_allinverse;
    sjt_functionParam263 = &sjv_vscreenorigin1;
    sjf_mat4_multiplyvec4(sjt_parent138, sjt_functionParam263, &sjv_vprojectedorigin1);
    sjt_parent139 = &sjv_allinverse;
    sjt_functionParam264 = &sjv_vscreenorigin2;
    sjf_mat4_multiplyvec4(sjt_parent139, sjt_functionParam264, &sjv_vprojectedorigin2);
    sjv_vflattenedorigin1._refCount = 1;
    sjt_dot1465 = &sjv_vprojectedorigin1;
    sjt_math2269 = (sjt_dot1465)->x;
    sjt_dot1466 = &sjv_vprojectedorigin1;
    sjt_math2270 = (sjt_dot1466)->w;
    sjv_vflattenedorigin1.x = sjt_math2269 / sjt_math2270;
    sjt_dot1467 = &sjv_vprojectedorigin1;
    sjt_math2271 = (sjt_dot1467)->y;
    sjt_dot1468 = &sjv_vprojectedorigin1;
    sjt_math2272 = (sjt_dot1468)->w;
    sjv_vflattenedorigin1.y = sjt_math2271 / sjt_math2272;
    sjt_dot1469 = &sjv_vprojectedorigin1;
    sjt_math2273 = (sjt_dot1469)->z;
    sjt_dot1470 = &sjv_vprojectedorigin1;
    sjt_math2274 = (sjt_dot1470)->w;
    sjv_vflattenedorigin1.z = sjt_math2273 / sjt_math2274;
    sjf_vec3(&sjv_vflattenedorigin1);
    sjv_vflattenedorigin2._refCount = 1;
    sjt_dot1471 = &sjv_vprojectedorigin2;
    sjt_math2275 = (sjt_dot1471)->x;
    sjt_dot1472 = &sjv_vprojectedorigin2;
    sjt_math2276 = (sjt_dot1472)->w;
    sjv_vflattenedorigin2.x = sjt_math2275 / sjt_math2276;
    sjt_dot1473 = &sjv_vprojectedorigin2;
    sjt_math2277 = (sjt_dot1473)->y;
    sjt_dot1474 = &sjv_vprojectedorigin2;
    sjt_math2278 = (sjt_dot1474)->w;
    sjv_vflattenedorigin2.y = sjt_math2277 / sjt_math2278;
    sjt_dot1475 = &sjv_vprojectedorigin2;
    sjt_math2279 = (sjt_dot1475)->z;
    sjt_dot1476 = &sjv_vprojectedorigin2;
    sjt_math2280 = (sjt_dot1476)->w;
    sjv_vflattenedorigin2.z = sjt_math2279 / sjt_math2280;
    sjf_vec3(&sjv_vflattenedorigin2);
    sjt_parent140 = &sjv_vflattenedorigin2;
    sjt_functionParam265 = &sjv_vflattenedorigin1;
    sjf_vec3_subtract(sjt_parent140, sjt_functionParam265, &sjv_vflatteneddir);
    sjt_copy25 = &sjv_vflattenedorigin1;
    sjv_vpickrayorig._refCount = 1;
    sjf_vec3_copy(&sjv_vpickrayorig, sjt_copy25);
    sjt_parent141 = &sjv_vflatteneddir;
    sjf_vec3_normalize(sjt_parent141, &sjv_vpickraydir);
    sjt_dot1478 = _parent;
    sjt_dot1477 = &(sjt_dot1478)->indices;
    sjt_compare67 = (sjt_dot1477)->count;
    sjt_compare68 = 0;
    sjt_ifElse26 = sjt_compare67 > sjt_compare68;
    if (sjt_ifElse26) {
        sjs_array_i32* sjt_dot1479 = 0;
        sjs_vertexbuffer_vertex_location_texture_normal* sjt_dot1480 = 0;
        int32_t sjt_math2281;
        int32_t sjt_math2282;

        sjt_dot1480 = _parent;
        sjt_dot1479 = &(sjt_dot1480)->indices;
        sjt_math2281 = (sjt_dot1479)->count;
        sjt_math2282 = 3;
        sjv_ctriangles = sjt_math2281 / sjt_math2282;
    } else {
        sjs_array_vertex_location_texture_normal* sjt_dot1481 = 0;
        sjs_vertexbuffer_vertex_location_texture_normal* sjt_dot1482 = 0;
        int32_t sjt_math2283;
        int32_t sjt_math2284;

        sjt_dot1482 = _parent;
        sjt_dot1481 = &(sjt_dot1482)->vertices;
        sjt_math2283 = (sjt_dot1481)->count;
        sjt_math2284 = 3;
        sjv_ctriangles = sjt_math2283 / sjt_math2284;
    }

    sjt_forStart14 = 0;
    sjt_forEnd14 = sjv_ctriangles;
    i = sjt_forStart14;
    while (i < sjt_forEnd14) {
        int32_t sjt_compare69;
        int32_t sjt_compare70;
        int32_t sjt_compare71;
        int32_t sjt_compare72;
        int32_t sjt_compare73;
        int32_t sjt_compare74;
        sjs_array_i32* sjt_dot1483 = 0;
        sjs_vertexbuffer_vertex_location_texture_normal* sjt_dot1484 = 0;
        sjs_array_i32* sjt_dot1488 = 0;
        sjs_vertexbuffer_vertex_location_texture_normal* sjt_dot1489 = 0;
        sjs_array_i32* sjt_dot1493 = 0;
        sjs_vertexbuffer_vertex_location_texture_normal* sjt_dot1494 = 0;
        sjs_vertex_location_texture_normal* sjt_dot1498 = 0;
        sjs_vertex_location_texture_normal* sjt_dot1499 = 0;
        sjs_vertex_location_texture_normal* sjt_dot1500 = 0;
        sjs_vec3* sjt_functionParam295 = 0;
        sjs_vec3* sjt_functionParam296 = 0;
        sjs_vec3* sjt_functionParam297 = 0;
        sjs_vec3* sjt_functionParam298 = 0;
        sjs_vec3* sjt_functionParam299 = 0;
        bool sjt_ifElse27;
        bool sjt_ifElse28;
        bool sjt_ifElse29;
        bool sjt_isEmpty7;
        sjs_vec3* sjt_isEmpty8 = 0;
        sjs_vec3 sjv_result = { -1 };
        sjs_vertex_location_texture_normal sjv_vertex0 = { -1 };
        sjs_vertex_location_texture_normal sjv_vertex1 = { -1 };
        sjs_vertex_location_texture_normal sjv_vertex2 = { -1 };

        sjt_dot1484 = _parent;
        sjt_dot1483 = &(sjt_dot1484)->indices;
        sjt_compare69 = (sjt_dot1483)->count;
        sjt_compare70 = 0;
        sjt_ifElse27 = sjt_compare69 > sjt_compare70;
        if (sjt_ifElse27) {
            sjs_vertexbuffer_vertex_location_texture_normal* sjt_dot1485 = 0;
            sjs_vertexbuffer_vertex_location_texture_normal* sjt_dot1486 = 0;
            int32_t sjt_functionParam266;
            int32_t sjt_functionParam267;
            int32_t sjt_math2285;
            int32_t sjt_math2286;
            int32_t sjt_math2287;
            int32_t sjt_math2288;
            sjs_array_vertex_location_texture_normal* sjt_parent142 = 0;
            sjs_array_i32* sjt_parent143 = 0;

            sjt_dot1485 = _parent;
            sjt_parent142 = &(sjt_dot1485)->vertices;
            sjt_dot1486 = _parent;
            sjt_parent143 = &(sjt_dot1486)->indices;
            sjt_math2287 = i;
            sjt_math2288 = 3;
            sjt_math2285 = sjt_math2287 * sjt_math2288;
            sjt_math2286 = 0;
            sjt_functionParam267 = sjt_math2285 + sjt_math2286;
            sjf_array_i32_getat(sjt_parent143, sjt_functionParam267, &sjt_functionParam266);
            sjf_array_vertex_location_texture_normal_getat(sjt_parent142, sjt_functionParam266, &sjv_vertex0);
        } else {
            sjs_vertexbuffer_vertex_location_texture_normal* sjt_dot1487 = 0;
            int32_t sjt_functionParam268;
            int32_t sjt_math2289;
            int32_t sjt_math2290;
            int32_t sjt_math2291;
            int32_t sjt_math2292;
            sjs_array_vertex_location_texture_normal* sjt_parent144 = 0;

            sjt_dot1487 = _parent;
            sjt_parent144 = &(sjt_dot1487)->vertices;
            sjt_math2291 = i;
            sjt_math2292 = 3;
            sjt_math2289 = sjt_math2291 * sjt_math2292;
            sjt_math2290 = 0;
            sjt_functionParam268 = sjt_math2289 + sjt_math2290;
            sjf_array_vertex_location_texture_normal_getat(sjt_parent144, sjt_functionParam268, &sjv_vertex0);
        }

        sjt_dot1489 = _parent;
        sjt_dot1488 = &(sjt_dot1489)->indices;
        sjt_compare71 = (sjt_dot1488)->count;
        sjt_compare72 = 0;
        sjt_ifElse28 = sjt_compare71 > sjt_compare72;
        if (sjt_ifElse28) {
            sjs_vertexbuffer_vertex_location_texture_normal* sjt_dot1490 = 0;
            sjs_vertexbuffer_vertex_location_texture_normal* sjt_dot1491 = 0;
            int32_t sjt_functionParam269;
            int32_t sjt_functionParam270;
            int32_t sjt_math2293;
            int32_t sjt_math2294;
            int32_t sjt_math2295;
            int32_t sjt_math2296;
            sjs_array_vertex_location_texture_normal* sjt_parent145 = 0;
            sjs_array_i32* sjt_parent146 = 0;

            sjt_dot1490 = _parent;
            sjt_parent145 = &(sjt_dot1490)->vertices;
            sjt_dot1491 = _parent;
            sjt_parent146 = &(sjt_dot1491)->indices;
            sjt_math2295 = i;
            sjt_math2296 = 3;
            sjt_math2293 = sjt_math2295 * sjt_math2296;
            sjt_math2294 = 1;
            sjt_functionParam270 = sjt_math2293 + sjt_math2294;
            sjf_array_i32_getat(sjt_parent146, sjt_functionParam270, &sjt_functionParam269);
            sjf_array_vertex_location_texture_normal_getat(sjt_parent145, sjt_functionParam269, &sjv_vertex1);
        } else {
            sjs_vertexbuffer_vertex_location_texture_normal* sjt_dot1492 = 0;
            int32_t sjt_functionParam271;
            int32_t sjt_math2297;
            int32_t sjt_math2298;
            int32_t sjt_math2299;
            int32_t sjt_math2300;
            sjs_array_vertex_location_texture_normal* sjt_parent147 = 0;

            sjt_dot1492 = _parent;
            sjt_parent147 = &(sjt_dot1492)->vertices;
            sjt_math2299 = i;
            sjt_math2300 = 3;
            sjt_math2297 = sjt_math2299 * sjt_math2300;
            sjt_math2298 = 1;
            sjt_functionParam271 = sjt_math2297 + sjt_math2298;
            sjf_array_vertex_location_texture_normal_getat(sjt_parent147, sjt_functionParam271, &sjv_vertex1);
        }

        sjt_dot1494 = _parent;
        sjt_dot1493 = &(sjt_dot1494)->indices;
        sjt_compare73 = (sjt_dot1493)->count;
        sjt_compare74 = 0;
        sjt_ifElse29 = sjt_compare73 > sjt_compare74;
        if (sjt_ifElse29) {
            sjs_vertexbuffer_vertex_location_texture_normal* sjt_dot1495 = 0;
            sjs_vertexbuffer_vertex_location_texture_normal* sjt_dot1496 = 0;
            int32_t sjt_functionParam272;
            int32_t sjt_functionParam273;
            int32_t sjt_math2301;
            int32_t sjt_math2302;
            int32_t sjt_math2303;
            int32_t sjt_math2304;
            sjs_array_vertex_location_texture_normal* sjt_parent148 = 0;
            sjs_array_i32* sjt_parent149 = 0;

            sjt_dot1495 = _parent;
            sjt_parent148 = &(sjt_dot1495)->vertices;
            sjt_dot1496 = _parent;
            sjt_parent149 = &(sjt_dot1496)->indices;
            sjt_math2303 = i;
            sjt_math2304 = 3;
            sjt_math2301 = sjt_math2303 * sjt_math2304;
            sjt_math2302 = 2;
            sjt_functionParam273 = sjt_math2301 + sjt_math2302;
            sjf_array_i32_getat(sjt_parent149, sjt_functionParam273, &sjt_functionParam272);
            sjf_array_vertex_location_texture_normal_getat(sjt_parent148, sjt_functionParam272, &sjv_vertex2);
        } else {
            sjs_vertexbuffer_vertex_location_texture_normal* sjt_dot1497 = 0;
            int32_t sjt_functionParam274;
            int32_t sjt_math2305;
            int32_t sjt_math2306;
            int32_t sjt_math2307;
            int32_t sjt_math2308;
            sjs_array_vertex_location_texture_normal* sjt_parent150 = 0;

            sjt_dot1497 = _parent;
            sjt_parent150 = &(sjt_dot1497)->vertices;
            sjt_math2307 = i;
            sjt_math2308 = 3;
            sjt_math2305 = sjt_math2307 * sjt_math2308;
            sjt_math2306 = 2;
            sjt_functionParam274 = sjt_math2305 + sjt_math2306;
            sjf_array_vertex_location_texture_normal_getat(sjt_parent150, sjt_functionParam274, &sjv_vertex2);
        }

        sjt_functionParam295 = &sjv_vpickrayorig;
        sjt_functionParam296 = &sjv_vpickraydir;
        sjt_dot1498 = &sjv_vertex0;
        sjt_functionParam297 = &(sjt_dot1498)->location;
        sjt_dot1499 = &sjv_vertex1;
        sjt_functionParam298 = &(sjt_dot1499)->location;
        sjt_dot1500 = &sjv_vertex2;
        sjt_functionParam299 = &(sjt_dot1500)->location;
        sjf_intersecttriangle(sjt_functionParam295, sjt_functionParam296, sjt_functionParam297, sjt_functionParam298, sjt_functionParam299, &sjv_result);
        sjt_isEmpty8 = (sjv_result._refCount != -1 ? &sjv_result : 0);
        sjt_isEmpty7 = (sjt_isEmpty8 != 0);
        if (sjt_isEmpty7) {
            sjs_vec3* ifValue11 = 0;
            float sjt_compare100;
            float sjt_compare99;
            sjs_vec3* sjt_dot1501 = 0;
            bool sjt_ifElse38;
            bool sjt_ifElse39;
            bool sjt_ifElse40;
            float_option sjt_isEmpty10;
            sjs_vec3* sjt_isEmpty11 = 0;
            sjs_vec3* sjt_isEmpty9 = 0;
            bool sjt_or10;
            bool sjt_or9;

            ifValue11 = (sjv_result._refCount != -1 ? &sjv_result : 0);
            sjt_isEmpty9 = (sjv_intersection._refCount != -1 ? &sjv_intersection : 0);
            sjt_or9 = (sjt_isEmpty9 == 0);
            sjt_dot1501 = ifValue11;
            sjt_compare99 = (sjt_dot1501)->z;
            sjt_isEmpty11 = (sjv_intersection._refCount != -1 ? &sjv_intersection : 0);
            sjt_ifElse40 = (sjt_isEmpty11 != 0);
            if (sjt_ifElse40) {
                sjs_vec3* sjt_dot1502 = 0;
                float sjt_value2;
                float_option value1;

                sjt_dot1502 = (sjv_intersection._refCount != -1 ? &sjv_intersection : 0);
                sjt_value2 = (sjt_dot1502)->z;
                value1.isvalid = true;
                value1.value = sjt_value2;
                sjt_isEmpty10 = value1;
            } else {
                sjt_isEmpty10 = float_empty;
            }

            sjt_ifElse39 = sjt_isEmpty10.isvalid;
            if (sjt_ifElse39) {
                float_option sjt_getValue1;
                bool sjt_ifElse41;
                sjs_vec3* sjt_isEmpty12 = 0;

                sjt_isEmpty12 = (sjv_intersection._refCount != -1 ? &sjv_intersection : 0);
                sjt_ifElse41 = (sjt_isEmpty12 != 0);
                if (sjt_ifElse41) {
                    sjs_vec3* sjt_dot1503 = 0;
                    float sjt_value3;
                    float_option value2;

                    sjt_dot1503 = (sjv_intersection._refCount != -1 ? &sjv_intersection : 0);
                    sjt_value3 = (sjt_dot1503)->z;
                    value2.isvalid = true;
                    value2.value = sjt_value3;
                    sjt_getValue1 = value2;
                } else {
                    sjt_getValue1 = float_empty;
                }

                sjt_compare100 = sjt_getValue1.value;
            } else {
                sjt_compare100 = 0.0f;
            }

            sjt_or10 = sjt_compare99 < sjt_compare100;
            sjt_ifElse38 = sjt_or9 || sjt_or10;
            if (sjt_ifElse38) {
                sjs_vec3* sjt_copy26 = 0;
                sjs_vec2* sjt_dot1504 = 0;
                sjs_vertex_location_texture_normal* sjt_dot1505 = 0;
                sjs_vec2* sjt_dot1506 = 0;
                sjs_vertex_location_texture_normal* sjt_dot1507 = 0;
                sjs_vec2* sjt_dot1508 = 0;
                sjs_vertex_location_texture_normal* sjt_dot1509 = 0;
                sjs_vec2* sjt_dot1510 = 0;
                sjs_vertex_location_texture_normal* sjt_dot1511 = 0;
                sjs_vec2* sjt_dot1512 = 0;
                sjs_vertex_location_texture_normal* sjt_dot1513 = 0;
                sjs_vec2* sjt_dot1514 = 0;
                sjs_vertex_location_texture_normal* sjt_dot1515 = 0;
                sjs_vec2* sjt_dot1516 = 0;
                sjs_vertex_location_texture_normal* sjt_dot1517 = 0;
                sjs_vec2* sjt_dot1518 = 0;
                sjs_vertex_location_texture_normal* sjt_dot1519 = 0;
                sjs_vec2* sjt_dot1520 = 0;
                sjs_vertex_location_texture_normal* sjt_dot1521 = 0;
                sjs_vec3* sjt_dot1522 = 0;
                sjs_vec3* sjt_dot1523 = 0;
                sjs_vec2* sjt_dot1524 = 0;
                sjs_vertex_location_texture_normal* sjt_dot1525 = 0;
                sjs_vec3* sjt_dot1526 = 0;
                sjs_vec3* sjt_dot1527 = 0;
                float sjt_math2333;
                float sjt_math2334;
                float sjt_math2335;
                float sjt_math2336;
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
                float sjv_dtu1;
                float sjv_dtu2;
                float sjv_dtv1;
                float sjv_dtv2;

                sjt_copy26 = ifValue11;
                sjv_intersection._refCount = 1;
                sjf_vec3_copy(&sjv_intersection, sjt_copy26);
                sjt_dot1505 = &sjv_vertex1;
                sjt_dot1504 = &(sjt_dot1505)->texture;
                sjt_math2333 = (sjt_dot1504)->x;
                sjt_dot1507 = &sjv_vertex0;
                sjt_dot1506 = &(sjt_dot1507)->texture;
                sjt_math2334 = (sjt_dot1506)->x;
                sjv_dtu1 = sjt_math2333 - sjt_math2334;
                sjt_dot1509 = &sjv_vertex2;
                sjt_dot1508 = &(sjt_dot1509)->texture;
                sjt_math2335 = (sjt_dot1508)->x;
                sjt_dot1511 = &sjv_vertex0;
                sjt_dot1510 = &(sjt_dot1511)->texture;
                sjt_math2336 = (sjt_dot1510)->x;
                sjv_dtu2 = sjt_math2335 - sjt_math2336;
                sjt_dot1513 = &sjv_vertex1;
                sjt_dot1512 = &(sjt_dot1513)->texture;
                sjt_math2337 = (sjt_dot1512)->y;
                sjt_dot1515 = &sjv_vertex0;
                sjt_dot1514 = &(sjt_dot1515)->texture;
                sjt_math2338 = (sjt_dot1514)->y;
                sjv_dtv1 = sjt_math2337 - sjt_math2338;
                sjt_dot1517 = &sjv_vertex2;
                sjt_dot1516 = &(sjt_dot1517)->texture;
                sjt_math2339 = (sjt_dot1516)->y;
                sjt_dot1519 = &sjv_vertex0;
                sjt_dot1518 = &(sjt_dot1519)->texture;
                sjt_math2340 = (sjt_dot1518)->y;
                sjv_dtv2 = sjt_math2339 - sjt_math2340;
                sjv_texture._refCount = 1;
                sjt_dot1521 = &sjv_vertex0;
                sjt_dot1520 = &(sjt_dot1521)->texture;
                sjt_math2343 = (sjt_dot1520)->x;
                sjt_dot1522 = ifValue11;
                sjt_math2345 = (sjt_dot1522)->x;
                sjt_math2346 = sjv_dtu1;
                sjt_math2344 = sjt_math2345 * sjt_math2346;
                sjt_math2341 = sjt_math2343 + sjt_math2344;
                sjt_dot1523 = ifValue11;
                sjt_math2347 = (sjt_dot1523)->y;
                sjt_math2348 = sjv_dtu2;
                sjt_math2342 = sjt_math2347 * sjt_math2348;
                sjv_texture.x = sjt_math2341 + sjt_math2342;
                sjt_dot1525 = &sjv_vertex0;
                sjt_dot1524 = &(sjt_dot1525)->texture;
                sjt_math2351 = (sjt_dot1524)->y;
                sjt_dot1526 = ifValue11;
                sjt_math2353 = (sjt_dot1526)->x;
                sjt_math2354 = sjv_dtv1;
                sjt_math2352 = sjt_math2353 * sjt_math2354;
                sjt_math2349 = sjt_math2351 + sjt_math2352;
                sjt_dot1527 = ifValue11;
                sjt_math2355 = (sjt_dot1527)->y;
                sjt_math2356 = sjv_dtv2;
                sjt_math2350 = sjt_math2355 * sjt_math2356;
                sjv_texture.y = sjt_math2349 + sjt_math2350;
                sjf_vec2(&sjv_texture);
            }
        }

        i++;

        if (sjv_result._refCount == 1) { sjf_vec3_destroy(&sjv_result); }
        if (sjv_vertex0._refCount == 1) { sjf_vertex_location_texture_normal_destroy(&sjv_vertex0); }
        if (sjv_vertex1._refCount == 1) { sjf_vertex_location_texture_normal_destroy(&sjv_vertex1); }
        if (sjv_vertex2._refCount == 1) { sjf_vertex_location_texture_normal_destroy(&sjv_vertex2); }
    }

    sjt_isEmpty13 = (sjv_texture._refCount != -1 ? &sjv_texture : 0);
    sjt_ifElse42 = (sjt_isEmpty13 != 0);
    if (sjt_ifElse42) {
        sjs_vec2* sjt_copy27 = 0;

        sjt_copy27 = (sjv_texture._refCount != -1 ? &sjv_texture : 0);
        _return->_refCount = 1;
        sjf_vec2_copy(_return, sjt_copy27);
    } else {
        _return->_refCount = -1;
    }

    if (sjt_call55._refCount == 1) { sjf_mat4_destroy(&sjt_call55); }
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
    sjs_crosshairselement_element_vtbl.destroy = (void(*)(void*))sjf_crosshairselement_destroy;
    sjs_crosshairselement_element_vtbl.asinterface = (void(*)(sjs_object*,int,sjs_interface*))sjf_crosshairselement_asinterface;
    sjs_crosshairselement_element_vtbl.getsize = (void(*)(sjs_object*,sjs_size*, sjs_size*))sjf_crosshairselement_getsize;
    sjs_crosshairselement_element_vtbl.getsize_heap = (void(*)(sjs_object*,sjs_size*, sjs_size**))sjf_crosshairselement_getsize_heap;
    sjs_crosshairselement_element_vtbl.getrect = (void(*)(sjs_object*, sjs_rect*))sjf_crosshairselement_getrect;
    sjs_crosshairselement_element_vtbl.getrect_heap = (void(*)(sjs_object*, sjs_rect**))sjf_crosshairselement_getrect_heap;
    sjs_crosshairselement_element_vtbl.setrect = (void(*)(sjs_object*,sjs_rect*))sjf_crosshairselement_setrect;
    sjs_crosshairselement_element_vtbl.render = (void(*)(sjs_object*,sjs_scene2d*))sjf_crosshairselement_render;
    sjs_crosshairselement_element_vtbl.firemouseevent = (void(*)(sjs_object*,sjs_mouseevent*, bool*))sjf_crosshairselement_firemouseevent;
    sjs_filllayout_element_vtbl.destroy = (void(*)(void*))sjf_filllayout_destroy;
    sjs_filllayout_element_vtbl.asinterface = (void(*)(sjs_object*,int,sjs_interface*))sjf_filllayout_asinterface;
    sjs_filllayout_element_vtbl.getsize = (void(*)(sjs_object*,sjs_size*, sjs_size*))sjf_filllayout_getsize;
    sjs_filllayout_element_vtbl.getsize_heap = (void(*)(sjs_object*,sjs_size*, sjs_size**))sjf_filllayout_getsize_heap;
    sjs_filllayout_element_vtbl.getrect = (void(*)(sjs_object*, sjs_rect*))sjf_filllayout_getrect;
    sjs_filllayout_element_vtbl.getrect_heap = (void(*)(sjs_object*, sjs_rect**))sjf_filllayout_getrect_heap;
    sjs_filllayout_element_vtbl.setrect = (void(*)(sjs_object*,sjs_rect*))sjf_filllayout_setrect;
    sjs_filllayout_element_vtbl.render = (void(*)(sjs_object*,sjs_scene2d*))sjf_filllayout_render;
    sjs_filllayout_element_vtbl.firemouseevent = (void(*)(sjs_object*,sjs_mouseevent*, bool*))sjf_filllayout_firemouseevent;
    sjs_imageelement_element_vtbl.destroy = (void(*)(void*))sjf_imageelement_destroy;
    sjs_imageelement_element_vtbl.asinterface = (void(*)(sjs_object*,int,sjs_interface*))sjf_imageelement_asinterface;
    sjs_imageelement_element_vtbl.getsize = (void(*)(sjs_object*,sjs_size*, sjs_size*))sjf_imageelement_getsize;
    sjs_imageelement_element_vtbl.getsize_heap = (void(*)(sjs_object*,sjs_size*, sjs_size**))sjf_imageelement_getsize_heap;
    sjs_imageelement_element_vtbl.getrect = (void(*)(sjs_object*, sjs_rect*))sjf_imageelement_getrect;
    sjs_imageelement_element_vtbl.getrect_heap = (void(*)(sjs_object*, sjs_rect**))sjf_imageelement_getrect_heap;
    sjs_imageelement_element_vtbl.setrect = (void(*)(sjs_object*,sjs_rect*))sjf_imageelement_setrect;
    sjs_imageelement_element_vtbl.render = (void(*)(sjs_object*,sjs_scene2d*))sjf_imageelement_render;
    sjs_imageelement_element_vtbl.firemouseevent = (void(*)(sjs_object*,sjs_mouseevent*, bool*))sjf_imageelement_firemouseevent;
    sjs_scene2dmodel_model_vtbl.destroy = (void(*)(void*))sjf_scene2dmodel_destroy;
    sjs_scene2dmodel_model_vtbl.asinterface = (void(*)(sjs_object*,int,sjs_interface*))sjf_scene2dmodel_heap_asinterface;
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
    sjs_scene3delement_element_vtbl.getsize = (void(*)(sjs_object*,sjs_size*, sjs_size*))sjf_scene3delement_getsize;
    sjs_scene3delement_element_vtbl.getsize_heap = (void(*)(sjs_object*,sjs_size*, sjs_size**))sjf_scene3delement_getsize_heap;
    sjs_scene3delement_element_vtbl.getrect = (void(*)(sjs_object*, sjs_rect*))sjf_scene3delement_getrect;
    sjs_scene3delement_element_vtbl.getrect_heap = (void(*)(sjs_object*, sjs_rect**))sjf_scene3delement_getrect_heap;
    sjs_scene3delement_element_vtbl.setrect = (void(*)(sjs_object*,sjs_rect*))sjf_scene3delement_setrect;
    sjs_scene3delement_element_vtbl.render = (void(*)(sjs_object*,sjs_scene2d*))sjf_scene3delement_render;
    sjs_scene3delement_element_vtbl.firemouseevent = (void(*)(sjs_object*,sjs_mouseevent*, bool*))sjf_scene3delement_firemouseevent;
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
    sjv_borderposition_fill = 0;
    sjv_borderposition_left = 1;
    sjv_borderposition_right = 2;
    sjv_borderposition_top = 3;
    sjv_borderposition_bottom = 4;
    sjv_buttonstate_normal = 0;
    sjv_buttonstate_hot = 1;
    sjv_buttonstate_pressed = 2;
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
    sjv_flowlayoutorientation_topbottom = 0;
    sjv_flowlayoutorientation_leftright = 1;
    sjv_flowlayoutorientation_bottomtop = 2;
    sjv_flowlayoutorientation_rightleft = 3;
    sjv_fonthash._refCount = 1;
    sjf_hash_fontkey_weak_font(&sjv_fonthash);
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
    sjv_gridunittype_fixed = 0;
    sjv_gridunittype_star = 1;
    sjv_imagestretch_fill = 0;
    sjv_imagestretch_center = 1;
    sjv_imagestretch_aspectratio = 2;
    sjv_listlayoutorientation_topbottom = 0;
    sjv_listlayoutorientation_leftright = 1;
    sjv_listlayoutorientation_bottomtop = 2;
    sjv_listlayoutorientation_rightleft = 3;
    sjv_looplastrect._refCount = 1;
    sjv_looplastrect.x = 0;
    sjv_looplastrect.y = 0;
    sjv_looplastrect.w = 0;
    sjv_looplastrect.h = 0;
    sjf_rect(&sjv_looplastrect);
    sjv_mouse_captureelement._parent = 0;
    sjv_mouseeventtype_move = 0;
    sjv_mouseeventtype_up = 1;
    sjv_mouseeventtype_down = 2;
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
    sjv_texthorizontal_left = 0;
    sjv_texthorizontal_right = 1;
    sjv_texthorizontal_center = 2;
    sjv_textvertical_top = 0;
    sjv_textvertical_bottom = 1;
    sjv_textvertical_center = 2;
    sjv_vertex_location_texture_normal_format._refCount = 1;
    sjv_vertex_location_texture_normal_format.count = 32;
    sjv_vertex_location_texture_normal_format.data._refCount = 1;
    sjv_vertex_location_texture_normal_format.data.datasize = 33;
    sjv_vertex_location_texture_normal_format.data.data = (void*)sjg_string17;
    sjv_vertex_location_texture_normal_format.data._isglobal = true;
    sjv_vertex_location_texture_normal_format.data.count = 33;
    sjf_array_char(&sjv_vertex_location_texture_normal_format.data);
    sjf_string(&sjv_vertex_location_texture_normal_format);
    sjt_call1 = (sjs_filllayout*)malloc(sizeof(sjs_filllayout));
    sjt_call1->_refCount = 1;
    sjt_call1->children._refCount = 1;
    sjt_call1->children.datasize = 2;
    sjt_call1->children.data = 0;
    sjt_call1->children._isglobal = false;
    sjt_call1->children.count = 0;
    sjf_array_heap_iface_element(&sjt_call1->children);
    sjs_array_heap_iface_element* array3;
    array3 = &sjt_call1->children;
    sjt_parent24 = array3;
    sjt_functionParam19 = 0;
    sjt_call4 = (sjs_scene3delement*)malloc(sizeof(sjs_scene3delement));
    sjt_call4->_refCount = 1;
    sjt_call4->children._refCount = 1;
    sjt_call4->children.datasize = 1;
    sjt_call4->children.data = 0;
    sjt_call4->children._isglobal = false;
    sjt_call4->children.count = 0;
    sjf_array_heap_iface_model(&sjt_call4->children);
    sjs_array_heap_iface_model* array2;
    array2 = &sjt_call4->children;
    sjt_parent96 = array2;
    sjt_functionParam142 = 0;
    sjt_call38 = (sjs_scene2dmodel*)malloc(sizeof(sjs_scene2dmodel));
    sjt_call38->_refCount = 1;
    sjt_call38->id._refCount = -1;
    sjt_functionParam343 = 20;
    sjt_functionParam344 = 40;
    sjt_call57._refCount = 1;
    sjt_call57.x = 0.0f;
    sjt_call57.y = 0.0f;
    sjt_call57.z = 0.0f;
    sjf_vec3(&sjt_call57);
    sjt_functionParam345 = &sjt_call57;
    sjt_call58._refCount = 1;
    sjt_call58.x = 1.0f;
    sjt_call58.y = 1.0f;
    sjt_call58.z = 1.0f;
    sjf_vec3(&sjt_call58);
    sjt_functionParam346 = &sjt_call58;
    sjf_spherevertexbuffer(sjt_functionParam343, sjt_functionParam344, sjt_functionParam345, sjt_functionParam346, &sjt_call38->vertexbuffer);
    sjt_copy35 = &sjv_phongtextureshader;
    sjt_call38->shader._refCount = 1;
    sjf_shader_copy(&sjt_call38->shader, sjt_copy35);
    sjt_call38->texturesize._refCount = 1;
    sjt_call38->texturesize.w = 512;
    sjt_call38->texturesize.h = 512;
    sjf_size(&sjt_call38->texturesize);
    sjt_call38->children._refCount = 1;
    sjt_call38->children.datasize = 2;
    sjt_call38->children.data = 0;
    sjt_call38->children._isglobal = false;
    sjt_call38->children.count = 0;
    sjf_array_heap_iface_element(&sjt_call38->children);
    sjs_array_heap_iface_element* array1;
    array1 = &sjt_call38->children;
    sjt_parent190 = array1;
    sjt_functionParam347 = 0;
    sjt_call59 = (sjs_imageelement*)malloc(sizeof(sjs_imageelement));
    sjt_call59->_refCount = 1;
    sjt_call59->image._refCount = 1;
    sjt_call65._refCount = 1;
    sjt_call65.count = 15;
    sjt_call65.data._refCount = 1;
    sjt_call65.data.datasize = 16;
    sjt_call65.data.data = (void*)sjg_string22;
    sjt_call65.data._isglobal = true;
    sjt_call65.data.count = 16;
    sjf_array_char(&sjt_call65.data);
    sjf_string(&sjt_call65);
    sjt_functionParam353 = &sjt_call65;
    sjf_texturefrompng(sjt_functionParam353, &sjt_call59->image.texture);
    sjt_call59->image.rect._refCount = 1;
    sjt_call59->image.rect.x = 0;
    sjt_call59->image.rect.y = 0;
    sjt_call59->image.rect.w = 0;
    sjt_call59->image.rect.h = 0;
    sjf_rect(&sjt_call59->image.rect);
    sjt_call59->image.margin._refCount = 1;
    sjt_call59->image.margin.l = 150;
    sjt_call59->image.margin.t = 50;
    sjt_call59->image.margin.r = 150;
    sjt_call59->image.margin.b = 150;
    sjf_margin(&sjt_call59->image.margin);
    sjf_image(&sjt_call59->image);
    sjt_call59->margin._refCount = 1;
    sjt_call59->margin.l = 0;
    sjt_call59->margin.t = 0;
    sjt_call59->margin.r = 0;
    sjt_call59->margin.b = 0;
    sjf_margin(&sjt_call59->margin);
    sjt_call59->stretch = sjv_imagestretch_fill;
    sjt_call59->_rect._refCount = 1;
    sjt_call59->_rect.x = 0;
    sjt_call59->_rect.y = 0;
    sjt_call59->_rect.w = 0;
    sjt_call59->_rect.h = 0;
    sjf_rect(&sjt_call59->_rect);
    sjt_call59->_imagerenderer._refCount = -1;
    sjf_imageelement_heap(sjt_call59);
    sjt_cast36 = sjt_call59;
    sjf_imageelement_as_sji_element(sjt_cast36, &sjt_functionParam348);
    if (sjt_functionParam348._parent != 0) {
        sjt_functionParam348._parent->_refCount++;
    }

    sjf_array_heap_iface_element_initat(sjt_parent190, sjt_functionParam347, sjt_functionParam348);
    sjt_parent200 = array1;
    sjt_functionParam354 = 1;
    sjt_call66 = (sjs_crosshairselement*)malloc(sizeof(sjs_crosshairselement));
    sjt_call66->_refCount = 1;
    sjt_copy49 = &sjv_colors_blue;
    sjt_call66->color._refCount = 1;
    sjf_color_copy(&sjt_call66->color, sjt_copy49);
    sjt_call66->_rect._refCount = 1;
    sjt_call66->_rect.x = 0;
    sjt_call66->_rect.y = 0;
    sjt_call66->_rect.w = 0;
    sjt_call66->_rect.h = 0;
    sjf_rect(&sjt_call66->_rect);
    sjt_call66->_topdownrenderer._refCount = -1;
    sjt_call66->_leftrightrenderer._refCount = -1;
    sjt_call66->_point._refCount = 1;
    sjt_call66->_point.x = 0;
    sjt_call66->_point.y = 0;
    sjf_point(&sjt_call66->_point);
    sjf_crosshairselement_heap(sjt_call66);
    sjt_cast45 = sjt_call66;
    sjf_crosshairselement_as_sji_element(sjt_cast45, &sjt_functionParam355);
    if (sjt_functionParam355._parent != 0) {
        sjt_functionParam355._parent->_refCount++;
    }

    sjf_array_heap_iface_element_initat(sjt_parent200, sjt_functionParam354, sjt_functionParam355);
    sjt_call38->hasalpha = false;
    sjt_call38->center._refCount = 1;
    sjt_call38->center.x = 0.0f;
    sjt_call38->center.y = 0.0f;
    sjt_call38->center.z = 0.0f;
    sjf_vec3(&sjt_call38->center);
    sjf_mat4_identity(&sjt_call38->model);
    sjt_call38->_innerscene._refCount = 1;
    sjt_call38->_innerscene._size._refCount = 1;
    sjt_call38->_innerscene._size.w = 0;
    sjt_call38->_innerscene._size.h = 0;
    sjf_size(&sjt_call38->_innerscene._size);
    sjt_call38->_innerscene.model._refCount = 1;
    sjt_call38->_innerscene.model.m00 = 0.0f;
    sjt_call38->_innerscene.model.m01 = 0.0f;
    sjt_call38->_innerscene.model.m02 = 0.0f;
    sjt_call38->_innerscene.model.m03 = 0.0f;
    sjt_call38->_innerscene.model.m10 = 0.0f;
    sjt_call38->_innerscene.model.m11 = 0.0f;
    sjt_call38->_innerscene.model.m12 = 0.0f;
    sjt_call38->_innerscene.model.m13 = 0.0f;
    sjt_call38->_innerscene.model.m20 = 0.0f;
    sjt_call38->_innerscene.model.m21 = 0.0f;
    sjt_call38->_innerscene.model.m22 = 0.0f;
    sjt_call38->_innerscene.model.m23 = 0.0f;
    sjt_call38->_innerscene.model.m30 = 0.0f;
    sjt_call38->_innerscene.model.m31 = 0.0f;
    sjt_call38->_innerscene.model.m32 = 0.0f;
    sjt_call38->_innerscene.model.m33 = 0.0f;
    sjf_mat4(&sjt_call38->_innerscene.model);
    sjt_call38->_innerscene.view._refCount = 1;
    sjt_call38->_innerscene.view.m00 = 0.0f;
    sjt_call38->_innerscene.view.m01 = 0.0f;
    sjt_call38->_innerscene.view.m02 = 0.0f;
    sjt_call38->_innerscene.view.m03 = 0.0f;
    sjt_call38->_innerscene.view.m10 = 0.0f;
    sjt_call38->_innerscene.view.m11 = 0.0f;
    sjt_call38->_innerscene.view.m12 = 0.0f;
    sjt_call38->_innerscene.view.m13 = 0.0f;
    sjt_call38->_innerscene.view.m20 = 0.0f;
    sjt_call38->_innerscene.view.m21 = 0.0f;
    sjt_call38->_innerscene.view.m22 = 0.0f;
    sjt_call38->_innerscene.view.m23 = 0.0f;
    sjt_call38->_innerscene.view.m30 = 0.0f;
    sjt_call38->_innerscene.view.m31 = 0.0f;
    sjt_call38->_innerscene.view.m32 = 0.0f;
    sjt_call38->_innerscene.view.m33 = 0.0f;
    sjf_mat4(&sjt_call38->_innerscene.view);
    sjt_call38->_innerscene.projection._refCount = 1;
    sjt_call38->_innerscene.projection.m00 = 0.0f;
    sjt_call38->_innerscene.projection.m01 = 0.0f;
    sjt_call38->_innerscene.projection.m02 = 0.0f;
    sjt_call38->_innerscene.projection.m03 = 0.0f;
    sjt_call38->_innerscene.projection.m10 = 0.0f;
    sjt_call38->_innerscene.projection.m11 = 0.0f;
    sjt_call38->_innerscene.projection.m12 = 0.0f;
    sjt_call38->_innerscene.projection.m13 = 0.0f;
    sjt_call38->_innerscene.projection.m20 = 0.0f;
    sjt_call38->_innerscene.projection.m21 = 0.0f;
    sjt_call38->_innerscene.projection.m22 = 0.0f;
    sjt_call38->_innerscene.projection.m23 = 0.0f;
    sjt_call38->_innerscene.projection.m30 = 0.0f;
    sjt_call38->_innerscene.projection.m31 = 0.0f;
    sjt_call38->_innerscene.projection.m32 = 0.0f;
    sjt_call38->_innerscene.projection.m33 = 0.0f;
    sjf_mat4(&sjt_call38->_innerscene.projection);
    sjt_call38->_innerscene.windowrect._refCount = 1;
    sjt_call38->_innerscene.windowrect.x = 0;
    sjt_call38->_innerscene.windowrect.y = 0;
    sjt_call38->_innerscene.windowrect.w = 0;
    sjt_call38->_innerscene.windowrect.h = 0;
    sjf_rect(&sjt_call38->_innerscene.windowrect);
    sjf_scene2d(&sjt_call38->_innerscene);
    sjt_call38->_scenerect._refCount = 1;
    sjt_call38->_scenerect.x = 0;
    sjt_call38->_scenerect.y = 0;
    sjt_call38->_scenerect.w = 0;
    sjt_call38->_scenerect.h = 0;
    sjf_rect(&sjt_call38->_scenerect);
    sjt_call38->_projection._refCount = 1;
    sjt_call38->_projection.m00 = 0.0f;
    sjt_call38->_projection.m01 = 0.0f;
    sjt_call38->_projection.m02 = 0.0f;
    sjt_call38->_projection.m03 = 0.0f;
    sjt_call38->_projection.m10 = 0.0f;
    sjt_call38->_projection.m11 = 0.0f;
    sjt_call38->_projection.m12 = 0.0f;
    sjt_call38->_projection.m13 = 0.0f;
    sjt_call38->_projection.m20 = 0.0f;
    sjt_call38->_projection.m21 = 0.0f;
    sjt_call38->_projection.m22 = 0.0f;
    sjt_call38->_projection.m23 = 0.0f;
    sjt_call38->_projection.m30 = 0.0f;
    sjt_call38->_projection.m31 = 0.0f;
    sjt_call38->_projection.m32 = 0.0f;
    sjt_call38->_projection.m33 = 0.0f;
    sjf_mat4(&sjt_call38->_projection);
    sjt_call38->_world._refCount = 1;
    sjt_call38->_world.m00 = 0.0f;
    sjt_call38->_world.m01 = 0.0f;
    sjt_call38->_world.m02 = 0.0f;
    sjt_call38->_world.m03 = 0.0f;
    sjt_call38->_world.m10 = 0.0f;
    sjt_call38->_world.m11 = 0.0f;
    sjt_call38->_world.m12 = 0.0f;
    sjt_call38->_world.m13 = 0.0f;
    sjt_call38->_world.m20 = 0.0f;
    sjt_call38->_world.m21 = 0.0f;
    sjt_call38->_world.m22 = 0.0f;
    sjt_call38->_world.m23 = 0.0f;
    sjt_call38->_world.m30 = 0.0f;
    sjt_call38->_world.m31 = 0.0f;
    sjt_call38->_world.m32 = 0.0f;
    sjt_call38->_world.m33 = 0.0f;
    sjf_mat4(&sjt_call38->_world);
    sjt_call38->_view._refCount = 1;
    sjt_call38->_view.m00 = 0.0f;
    sjt_call38->_view.m01 = 0.0f;
    sjt_call38->_view.m02 = 0.0f;
    sjt_call38->_view.m03 = 0.0f;
    sjt_call38->_view.m10 = 0.0f;
    sjt_call38->_view.m11 = 0.0f;
    sjt_call38->_view.m12 = 0.0f;
    sjt_call38->_view.m13 = 0.0f;
    sjt_call38->_view.m20 = 0.0f;
    sjt_call38->_view.m21 = 0.0f;
    sjt_call38->_view.m22 = 0.0f;
    sjt_call38->_view.m23 = 0.0f;
    sjt_call38->_view.m30 = 0.0f;
    sjt_call38->_view.m31 = 0.0f;
    sjt_call38->_view.m32 = 0.0f;
    sjt_call38->_view.m33 = 0.0f;
    sjf_mat4(&sjt_call38->_view);
    sjt_call38->_light._refCount = 1;
    sjt_call38->_light.pos._refCount = 1;
    sjt_call38->_light.pos.x = 1.0f;
    sjt_call38->_light.pos.y = 1.0f;
    sjt_call38->_light.pos.z = 1.0f;
    sjf_vec3(&sjt_call38->_light.pos);
    sjt_call38->_light.diffusecolor._refCount = 1;
    sjt_call38->_light.diffusecolor.r = 0.5f;
    sjt_call38->_light.diffusecolor.g = 0.5f;
    sjt_call38->_light.diffusecolor.b = 0.0f;
    sjt_call38->_light.diffusecolor.a = 1.0f;
    sjf_color(&sjt_call38->_light.diffusecolor);
    sjt_call38->_light.speccolor._refCount = 1;
    sjt_call38->_light.speccolor.r = 1.0f;
    sjt_call38->_light.speccolor.g = 1.0f;
    sjt_call38->_light.speccolor.b = 1.0f;
    sjt_call38->_light.speccolor.a = 1.0f;
    sjf_color(&sjt_call38->_light.speccolor);
    sjf_light(&sjt_call38->_light);
    sjt_call38->_projectedcenter._refCount = 1;
    sjt_call38->_projectedcenter.x = 0.0f;
    sjt_call38->_projectedcenter.y = 0.0f;
    sjt_call38->_projectedcenter.z = 0.0f;
    sjt_call38->_projectedcenter.w = 0.0f;
    sjf_vec4(&sjt_call38->_projectedcenter);
    sjt_call38->_framebuffer._refCount = 1;
    sjt_call38->_framebuffer.size._refCount = 1;
    sjt_call38->_framebuffer.size.w = 0;
    sjt_call38->_framebuffer.size.h = 0;
    sjf_size(&sjt_call38->_framebuffer.size);
    sjt_call38->_framebuffer.id = (uint32_t)0u;
    sjf_framebuffer(&sjt_call38->_framebuffer);
    sjt_call38->_texture._refCount = 1;
    sjt_call38->_texture.size._refCount = 1;
    sjt_call38->_texture.size.w = 0;
    sjt_call38->_texture.size.h = 0;
    sjf_size(&sjt_call38->_texture.size);
    sjt_call38->_texture.id = (uint32_t)0u;
    sjf_texture(&sjt_call38->_texture);
    sjt_call38->_renderbuffer._refCount = 1;
    sjt_call38->_renderbuffer.size._refCount = 1;
    sjt_call38->_renderbuffer.size.w = 0;
    sjt_call38->_renderbuffer.size.h = 0;
    sjf_size(&sjt_call38->_renderbuffer.size);
    sjt_call38->_renderbuffer.id = (uint32_t)0u;
    sjf_renderbuffer(&sjt_call38->_renderbuffer);
    sjf_scene2dmodel_heap(sjt_call38);
    sjt_cast7 = sjt_call38;
    sjf_scene2dmodel_as_sji_model(sjt_cast7, &sjt_functionParam143);
    if (sjt_functionParam143._parent != 0) {
        sjt_functionParam143._parent->_refCount++;
    }

    sjf_array_heap_iface_model_initat(sjt_parent96, sjt_functionParam142, sjt_functionParam143);
    sjt_call4->camera._refCount = 1;
    sjt_call4->camera.x = 0.0f;
    sjt_call4->camera.y = 0.0f;
    sjt_negate7 = 5.0f;
    result12 = -sjt_negate7;
    sjt_call4->camera.z = result12;
    sjf_vec3(&sjt_call4->camera);
    sjt_call4->lookat._refCount = 1;
    sjt_call4->lookat.x = 0.0f;
    sjt_call4->lookat.y = 0.0f;
    sjt_call4->lookat.z = 0.0f;
    sjf_vec3(&sjt_call4->lookat);
    sjt_call4->up._refCount = 1;
    sjt_call4->up.x = 0.0f;
    sjt_call4->up.y = 1.0f;
    sjt_call4->up.z = 0.0f;
    sjf_vec3(&sjt_call4->up);
    sjt_call4->fieldofview = 90.0f;
    sjt_call4->znear = 1.0f;
    sjt_call4->zfar = 100.0f;
    sjt_call4->light._refCount = 1;
    sjt_call4->light.pos._refCount = 1;
    sjt_call4->light.pos.x = 1.0f;
    sjt_call4->light.pos.y = 1.0f;
    sjt_call4->light.pos.z = 1.0f;
    sjf_vec3(&sjt_call4->light.pos);
    sjt_call4->light.diffusecolor._refCount = 1;
    sjt_call4->light.diffusecolor.r = 0.5f;
    sjt_call4->light.diffusecolor.g = 0.5f;
    sjt_call4->light.diffusecolor.b = 0.0f;
    sjt_call4->light.diffusecolor.a = 1.0f;
    sjf_color(&sjt_call4->light.diffusecolor);
    sjt_call4->light.speccolor._refCount = 1;
    sjt_call4->light.speccolor.r = 1.0f;
    sjt_call4->light.speccolor.g = 1.0f;
    sjt_call4->light.speccolor.b = 1.0f;
    sjt_call4->light.speccolor.a = 1.0f;
    sjf_color(&sjt_call4->light.speccolor);
    sjf_light(&sjt_call4->light);
    sjt_call4->projection._refCount = 1;
    sjt_call4->projection.m00 = 0.0f;
    sjt_call4->projection.m01 = 0.0f;
    sjt_call4->projection.m02 = 0.0f;
    sjt_call4->projection.m03 = 0.0f;
    sjt_call4->projection.m10 = 0.0f;
    sjt_call4->projection.m11 = 0.0f;
    sjt_call4->projection.m12 = 0.0f;
    sjt_call4->projection.m13 = 0.0f;
    sjt_call4->projection.m20 = 0.0f;
    sjt_call4->projection.m21 = 0.0f;
    sjt_call4->projection.m22 = 0.0f;
    sjt_call4->projection.m23 = 0.0f;
    sjt_call4->projection.m30 = 0.0f;
    sjt_call4->projection.m31 = 0.0f;
    sjt_call4->projection.m32 = 0.0f;
    sjt_call4->projection.m33 = 0.0f;
    sjf_mat4(&sjt_call4->projection);
    sjt_call4->view._refCount = 1;
    sjt_call4->view.m00 = 0.0f;
    sjt_call4->view.m01 = 0.0f;
    sjt_call4->view.m02 = 0.0f;
    sjt_call4->view.m03 = 0.0f;
    sjt_call4->view.m10 = 0.0f;
    sjt_call4->view.m11 = 0.0f;
    sjt_call4->view.m12 = 0.0f;
    sjt_call4->view.m13 = 0.0f;
    sjt_call4->view.m20 = 0.0f;
    sjt_call4->view.m21 = 0.0f;
    sjt_call4->view.m22 = 0.0f;
    sjt_call4->view.m23 = 0.0f;
    sjt_call4->view.m30 = 0.0f;
    sjt_call4->view.m31 = 0.0f;
    sjt_call4->view.m32 = 0.0f;
    sjt_call4->view.m33 = 0.0f;
    sjf_mat4(&sjt_call4->view);
    sjf_mat4_identity(&sjt_call4->world);
    sjt_call4->_rect._refCount = 1;
    sjt_call4->_rect.x = 0;
    sjt_call4->_rect.y = 0;
    sjt_call4->_rect.w = 0;
    sjt_call4->_rect.h = 0;
    sjf_rect(&sjt_call4->_rect);
    sjf_scene3delement_heap(sjt_call4);
    sjt_cast2 = sjt_call4;
    sjf_scene3delement_as_sji_element(sjt_cast2, &sjt_functionParam20);
    if (sjt_functionParam20._parent != 0) {
        sjt_functionParam20._parent->_refCount++;
    }

    sjf_array_heap_iface_element_initat(sjt_parent24, sjt_functionParam19, sjt_functionParam20);
    sjt_parent205 = array3;
    sjt_functionParam360 = 1;
    sjt_call67 = (sjs_crosshairselement*)malloc(sizeof(sjs_crosshairselement));
    sjt_call67->_refCount = 1;
    sjt_copy50 = &sjv_colors_red;
    sjt_call67->color._refCount = 1;
    sjf_color_copy(&sjt_call67->color, sjt_copy50);
    sjt_call67->_rect._refCount = 1;
    sjt_call67->_rect.x = 0;
    sjt_call67->_rect.y = 0;
    sjt_call67->_rect.w = 0;
    sjt_call67->_rect.h = 0;
    sjf_rect(&sjt_call67->_rect);
    sjt_call67->_topdownrenderer._refCount = -1;
    sjt_call67->_leftrightrenderer._refCount = -1;
    sjt_call67->_point._refCount = 1;
    sjt_call67->_point.x = 0;
    sjt_call67->_point.y = 0;
    sjf_point(&sjt_call67->_point);
    sjf_crosshairselement_heap(sjt_call67);
    sjt_cast46 = sjt_call67;
    sjf_crosshairselement_as_sji_element(sjt_cast46, &sjt_functionParam361);
    if (sjt_functionParam361._parent != 0) {
        sjt_functionParam361._parent->_refCount++;
    }

    sjf_array_heap_iface_element_initat(sjt_parent205, sjt_functionParam360, sjt_functionParam361);
    sjt_call1->margin._refCount = 1;
    sjt_call1->margin.l = 0;
    sjt_call1->margin.t = 0;
    sjt_call1->margin.r = 0;
    sjt_call1->margin.b = 0;
    sjf_margin(&sjt_call1->margin);
    sjt_call1->effect._parent = 0;
    sjt_call1->_rect._refCount = 1;
    sjt_call1->_rect.x = 0;
    sjt_call1->_rect.y = 0;
    sjt_call1->_rect.w = 0;
    sjt_call1->_rect.h = 0;
    sjf_rect(&sjt_call1->_rect);
    sjf_filllayout_heap(sjt_call1);
    sjt_cast1 = sjt_call1;
    sjf_filllayout_as_sji_element(sjt_cast1, &sjv_root);
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

    sjt_call1->_refCount--;
    if (sjt_call1->_refCount <= 0) {
        weakptr_release(sjt_call1);
        sjf_filllayout_destroy(sjt_call1);
        free(sjt_call1);
    }
    sjt_call38->_refCount--;
    if (sjt_call38->_refCount <= 0) {
        weakptr_release(sjt_call38);
        sjf_scene2dmodel_destroy(sjt_call38);
        free(sjt_call38);
    }
    sjt_call4->_refCount--;
    if (sjt_call4->_refCount <= 0) {
        weakptr_release(sjt_call4);
        sjf_scene3delement_destroy(sjt_call4);
        free(sjt_call4);
    }
    sjt_call59->_refCount--;
    if (sjt_call59->_refCount <= 0) {
        weakptr_release(sjt_call59);
        sjf_imageelement_destroy(sjt_call59);
        free(sjt_call59);
    }
    sjt_call66->_refCount--;
    if (sjt_call66->_refCount <= 0) {
        weakptr_release(sjt_call66);
        sjf_crosshairselement_destroy(sjt_call66);
        free(sjt_call66);
    }
    sjt_call67->_refCount--;
    if (sjt_call67->_refCount <= 0) {
        weakptr_release(sjt_call67);
        sjf_crosshairselement_destroy(sjt_call67);
        free(sjt_call67);
    }
    if (sjt_functionParam143._parent != 0) {
        sjt_functionParam143._parent->_refCount--;
        if (sjt_functionParam143._parent->_refCount <= 0) {
            sjt_functionParam143._vtbl->destroy(sjt_functionParam143._parent);
            free(sjt_functionParam143._parent);
        }
    }
    if (sjt_functionParam20._parent != 0) {
        sjt_functionParam20._parent->_refCount--;
        if (sjt_functionParam20._parent->_refCount <= 0) {
            sjt_functionParam20._vtbl->destroy(sjt_functionParam20._parent);
            free(sjt_functionParam20._parent);
        }
    }
    if (sjt_functionParam348._parent != 0) {
        sjt_functionParam348._parent->_refCount--;
        if (sjt_functionParam348._parent->_refCount <= 0) {
            sjt_functionParam348._vtbl->destroy(sjt_functionParam348._parent);
            free(sjt_functionParam348._parent);
        }
    }
    if (sjt_functionParam355._parent != 0) {
        sjt_functionParam355._parent->_refCount--;
        if (sjt_functionParam355._parent->_refCount <= 0) {
            sjt_functionParam355._vtbl->destroy(sjt_functionParam355._parent);
            free(sjt_functionParam355._parent);
        }
    }
    if (sjt_functionParam361._parent != 0) {
        sjt_functionParam361._parent->_refCount--;
        if (sjt_functionParam361._parent->_refCount <= 0) {
            sjt_functionParam361._vtbl->destroy(sjt_functionParam361._parent);
            free(sjt_functionParam361._parent);
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
    if (sjt_call57._refCount == 1) { sjf_vec3_destroy(&sjt_call57); }
    if (sjt_call58._refCount == 1) { sjf_vec3_destroy(&sjt_call58); }
    if (sjt_call65._refCount == 1) { sjf_string_destroy(&sjt_call65); }
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
    if (sjv_style._refCount == 1) { sjf_anon2_destroy(&sjv_style); }
    if (sjv_textshader._refCount == 1) { sjf_shader_destroy(&sjv_textshader); }
    if (sjv_vertex_location_texture_normal_format._refCount == 1) { sjf_string_destroy(&sjv_vertex_location_texture_normal_format); }
}
