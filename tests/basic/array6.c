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
#include <stdarg.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifdef __WINDOWS__
#include <windows.h>
#endif

typedef struct td_delete_cb delete_cb;
typedef struct td_delete_cb_list delete_cb_list;
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
__hash_func(key, &k); i = k % h->n_buckets;                 \
inc = 1 + k % (h->n_buckets - 1); last = i;                 \
bool isEqual;                                               \
__hash_equal(h->keys[i], key, &isEqual);                    \
while (!__ac_isempty(h->flags, i) && (__ac_isdel(h->flags, i) || !isEqual)) { \
if (i + inc >= h->n_buckets) i = i + inc - h->n_buckets; \
else i += inc;                                          \
if (i == last) return h->n_buckets;                     \
__hash_equal(h->keys[i], key, &isEqual);                \
}                                                           \
return __ac_iseither(h->flags, i)? h->n_buckets : i;            \
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
#define sjs_object_typeId 1
#define sjs_array_i32_typeId 2
#define sjs_array_f32_typeId 3
#define cb_i32_f32_typeId 4
#define cb_i32_f32_heap_typeId 5
#define cb_f32_bool_typeId 6
#define cb_f32_bool_heap_typeId 7
#define sjs_sum_typeId 8
#define cb_sum_f32_sum_typeId 9
#define cb_sum_f32_sum_heap_typeId 10
#define cb_sum_f32_sum_heap_sum_typeId 11
#define cb_sum_f32_sum_heap_sum_heap_typeId 12

typedef struct td_sjs_object sjs_object;
typedef struct td_sjs_array_i32 sjs_array_i32;
typedef struct td_sjs_array_f32 sjs_array_f32;
typedef struct td_cb_i32_f32 cb_i32_f32;
typedef struct td_cb_i32_f32_heap cb_i32_f32_heap;
typedef struct td_cb_f32_bool cb_f32_bool;
typedef struct td_cb_f32_bool_heap cb_f32_bool_heap;
typedef struct td_sjs_sum sjs_sum;
typedef struct td_cb_sum_f32_sum cb_sum_f32_sum;
typedef struct td_cb_sum_f32_sum_heap cb_sum_f32_sum_heap;
typedef struct td_cb_sum_f32_sum_heap_sum cb_sum_f32_sum_heap_sum;
typedef struct td_cb_sum_f32_sum_heap_sum_heap cb_sum_f32_sum_heap_sum_heap;

struct td_sjs_object {
    intptr_t _refCount;
};

struct td_sjs_array_i32 {
    int _refCount;
    int32_t datasize;
    void* data;
    bool _isglobal;
    int32_t count;
};

struct td_sjs_array_f32 {
    int _refCount;
    int32_t datasize;
    void* data;
    bool _isglobal;
    int32_t count;
};

struct td_cb_i32_f32 {
    void* _parent;
    void (*_cb)(void* _parent, int32_t, float* _return);
};

struct td_cb_i32_f32_heap {
    cb_i32_f32 inner;
    void (*_destroy)(void*);
};

struct td_cb_f32_bool {
    void* _parent;
    void (*_cb)(void* _parent, float, bool* _return);
};

struct td_cb_f32_bool_heap {
    cb_f32_bool inner;
    void (*_destroy)(void*);
};

struct td_sjs_sum {
    int _refCount;
    float x;
};

struct td_cb_sum_f32_sum {
    void* _parent;
    void (*_cb)(void* _parent, sjs_sum*, float, sjs_sum* _return);
};

struct td_cb_sum_f32_sum_heap {
    cb_sum_f32_sum inner;
    void (*_destroy)(void*);
};

struct td_cb_sum_f32_sum_heap_sum {
    void* _parent;
    void (*_cb)(void* _parent, sjs_sum*, float, sjs_sum* _return);
    void (*_cb_heap)(void* _parent, sjs_sum*, float, sjs_sum** _return);
};

struct td_cb_sum_f32_sum_heap_sum_heap {
    cb_sum_f32_sum_heap_sum inner;
    void (*_destroy)(void*);
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
int32_t result1;
sjs_sum sjt_call2;
int32_t sjt_functionParam1;
cb_i32_f32 sjt_functionParam11;
cb_f32_bool sjt_functionParam16;
int32_t sjt_functionParam2;
sjs_sum* sjt_functionParam20;
cb_sum_f32_sum sjt_functionParam21;
int32_t sjt_functionParam3;
int32_t sjt_functionParam4;
int32_t sjt_functionParam5;
int32_t sjt_functionParam6;
int32_t sjt_math1;
int32_t sjt_math2;
int32_t sjt_negate1;
sjs_array_i32* sjt_parent1;
sjs_array_i32* sjt_parent2;
sjs_array_i32* sjt_parent3;
sjs_array_i32* sjt_parent4;
sjs_array_f32* sjt_parent5;
sjs_array_f32* sjt_parent6;
sjs_array_i32 sjv_a;
sjs_array_f32 sjv_b;
sjs_array_f32 sjv_c;
sjs_sum* sjv_d;
void* sjv_emptystringdata;
float sjv_f32_pi;
int32_t sjv_i32_maxvalue;
int32_t sjv_i32_minvalue;
uint32_t sjv_u32_maxvalue;

void sjf_array_f32(sjs_array_f32* _this);
void sjf_array_f32_copy(sjs_array_f32* _this, sjs_array_f32* _from);
void sjf_array_f32_destroy(sjs_array_f32* _this);
void sjf_array_f32_filter(sjs_array_f32* _parent, cb_f32_bool cb, sjs_array_f32* _return);
void sjf_array_f32_filter_heap(sjs_array_f32* _parent, cb_f32_bool cb, sjs_array_f32** _return);
void sjf_array_f32_foldl_sum(sjs_array_f32* _parent, sjs_sum* initial, cb_sum_f32_sum cb, sjs_sum** _return);
void sjf_array_f32_getat(sjs_array_f32* _parent, int32_t index, float* _return);
void sjf_array_f32_heap(sjs_array_f32* _this);
void sjf_array_i32(sjs_array_i32* _this);
void sjf_array_i32_copy(sjs_array_i32* _this, sjs_array_i32* _from);
void sjf_array_i32_destroy(sjs_array_i32* _this);
void sjf_array_i32_getat(sjs_array_i32* _parent, int32_t index, int32_t* _return);
void sjf_array_i32_heap(sjs_array_i32* _this);
void sjf_array_i32_initat(sjs_array_i32* _parent, int32_t index, int32_t item);
void sjf_array_i32_map_f32(sjs_array_i32* _parent, cb_i32_f32 cb, sjs_array_f32* _return);
void sjf_array_i32_map_f32_heap(sjs_array_i32* _parent, cb_i32_f32 cb, sjs_array_f32** _return);
void sjf_double(int32_t x, float* _return);
void sjf_double_callback(void * _parent, int32_t x, float* _return);
void sjf_lessthan5(float x, bool* _return);
void sjf_lessthan5_callback(void * _parent, float x, bool* _return);
void sjf_sum(sjs_sum* _this);
void sjf_sum_copy(sjs_sum* _this, sjs_sum* _from);
void sjf_sum_destroy(sjs_sum* _this);
void sjf_sum_heap(sjs_sum* _this);
void sjf_sumadd(sjs_sum* sum, float x, sjs_sum* _return);
void sjf_sumadd_callback(void * _parent, sjs_sum* sum, float x, sjs_sum* _return);
void sjf_sumadd_heap(sjs_sum* sum, float x, sjs_sum** _return);
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
void sjf_array_f32(sjs_array_f32* _this) {
    if (_this->datasize < 0) {
        halt("size is less than zero");
    }
    if (!_this->data) {
        _this->data = malloc(_this->datasize * sizeof(float));
        if (!_this->data) {
            halt("grow: out of memory\n");
        }
    }
}

void sjf_array_f32_copy(sjs_array_f32* _this, sjs_array_f32* _from) {
    _this->datasize = _from->datasize;
    _this->data = _from->data;
    _this->_isglobal = _from->_isglobal;
    _this->count = _from->count;
    _this->data = _from->data;
    if (!_this->_isglobal && _this->data) {
        ptr_retain(_this->data);
    }
}

void sjf_array_f32_destroy(sjs_array_f32* _this) {
    if (!_this->_isglobal && _this->data) {
        if (ptr_release(_this->data)) {
            free((float*)_this->data);
        }
    }
}

void sjf_array_f32_filter(sjs_array_f32* _parent, cb_f32_bool cb, sjs_array_f32* _return) {
    int32_t i;
    sjs_array_f32* sjt_dot7;
    sjs_array_f32* sjt_dot8;
    int32_t sjt_forEnd3;
    int32_t sjt_forStart3;
    int32_t sjv_newcount;
    void* sjv_newdata;

    sjv_newdata = 0;
    sjv_newcount = 0;
    sjv_newdata = malloc(_parent->count * sizeof(float));
    sjt_forStart3 = 0;
    sjt_dot7 = _parent;
    sjt_forEnd3 = (sjt_dot7)->count;
    i = sjt_forStart3;
    while (i < sjt_forEnd3) {
        cb_f32_bool sjt_callback3;
        int32_t sjt_functionParam12;
        float sjt_functionParam13;
        bool sjt_ifElse1;
        float sjv_item;

        sjt_functionParam12 = i;
        sjf_array_f32_getat(_parent, sjt_functionParam12, &sjv_item);
        sjt_callback3 = cb;
        sjt_functionParam13 = sjv_item;
        sjt_callback3._cb(sjt_callback3._parent, sjt_functionParam13, &sjt_ifElse1);
        if (sjt_ifElse1) {
            int32_t sjt_math5;
            int32_t sjt_math6;

            float* p = (float*)sjv_newdata;
            p[sjv_newcount] = sjv_item;
;
            sjt_math5 = sjv_newcount;
            sjt_math6 = 1;
            sjv_newcount = sjt_math5 + sjt_math6;
        }

        i++;
    }

    sjt_dot8 = _parent;
    _return->datasize = (sjt_dot8)->count;
    _return->data = sjv_newdata;
    _return->_isglobal = false;
    _return->count = sjv_newcount;
    sjf_array_f32(_return);
}

void sjf_array_f32_filter_heap(sjs_array_f32* _parent, cb_f32_bool cb, sjs_array_f32** _return) {
    int32_t i;
    sjs_array_f32* sjt_dot10;
    sjs_array_f32* sjt_dot9;
    int32_t sjt_forEnd4;
    int32_t sjt_forStart4;
    int32_t sjv_newcount;
    void* sjv_newdata;

    sjv_newdata = 0;
    sjv_newcount = 0;
    sjv_newdata = malloc(_parent->count * sizeof(float));
    sjt_forStart4 = 0;
    sjt_dot9 = _parent;
    sjt_forEnd4 = (sjt_dot9)->count;
    i = sjt_forStart4;
    while (i < sjt_forEnd4) {
        cb_f32_bool sjt_callback4;
        int32_t sjt_functionParam14;
        float sjt_functionParam15;
        bool sjt_ifElse2;
        float sjv_item;

        sjt_functionParam14 = i;
        sjf_array_f32_getat(_parent, sjt_functionParam14, &sjv_item);
        sjt_callback4 = cb;
        sjt_functionParam15 = sjv_item;
        sjt_callback4._cb(sjt_callback4._parent, sjt_functionParam15, &sjt_ifElse2);
        if (sjt_ifElse2) {
            int32_t sjt_math7;
            int32_t sjt_math8;

            float* p = (float*)sjv_newdata;
            p[sjv_newcount] = sjv_item;
;
            sjt_math7 = sjv_newcount;
            sjt_math8 = 1;
            sjv_newcount = sjt_math7 + sjt_math8;
        }

        i++;
    }

    (*_return) = (sjs_array_f32*)malloc(sizeof(sjs_array_f32));
    (*_return)->_refCount = 1;
    sjt_dot10 = _parent;
    (*_return)->datasize = (sjt_dot10)->count;
    (*_return)->data = sjv_newdata;
    (*_return)->_isglobal = false;
    (*_return)->count = sjv_newcount;
    sjf_array_f32_heap((*_return));
}

void sjf_array_f32_foldl_sum(sjs_array_f32* _parent, sjs_sum* initial, cb_sum_f32_sum cb, sjs_sum** _return) {
    int32_t i;
    sjs_array_f32* sjt_dot11;
    int32_t sjt_forEnd5;
    int32_t sjt_forStart5;
    sjs_sum* sjv_r;

    sjv_r = initial;
    sjt_forStart5 = 0;
    sjt_dot11 = _parent;
    sjt_forEnd5 = (sjt_dot11)->count;
    i = sjt_forStart5;
    while (i < sjt_forEnd5) {
        sjs_sum sjt_call1;
        cb_sum_f32_sum sjt_callback5;
        sjs_sum* sjt_functionParam17;
        float sjt_functionParam18;
        int32_t sjt_functionParam19;

        sjt_callback5 = cb;
        sjt_functionParam17 = sjv_r;
        sjt_functionParam19 = i;
        sjf_array_f32_getat(_parent, sjt_functionParam19, &sjt_functionParam18);
        sjt_callback5._cb(sjt_callback5._parent, sjt_functionParam17, sjt_functionParam18, &sjt_call1);
        sjv_r = &sjt_call1;
        i++;

        sjf_sum_destroy(&sjt_call1);
    }

    (*_return) = sjv_r;
}

void sjf_array_f32_getat(sjs_array_f32* _parent, int32_t index, float* _return) {
    if (index >= _parent->count || index < 0) {
        halt("getAt: out of bounds\n");
    }
    float* p = (float*)_parent->data;
    (*_return) = p[index];
;		
}

void sjf_array_f32_heap(sjs_array_f32* _this) {
    if (_this->datasize < 0) {
        halt("size is less than zero");
    }
    if (!_this->data) {
        _this->data = malloc(_this->datasize * sizeof(float));
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
;		
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

void sjf_array_i32_map_f32(sjs_array_i32* _parent, cb_i32_f32 cb, sjs_array_f32* _return) {
    int32_t i;
    sjs_array_i32* sjt_dot1;
    sjs_array_i32* sjt_dot2;
    sjs_array_i32* sjt_dot3;
    int32_t sjt_forEnd1;
    int32_t sjt_forStart1;
    void* sjv_newdata;

    sjv_newdata = 0;
    sjv_newdata = malloc(_parent->count * sizeof(float));
    sjt_forStart1 = 0;
    sjt_dot1 = _parent;
    sjt_forEnd1 = (sjt_dot1)->count;
    i = sjt_forStart1;
    while (i < sjt_forEnd1) {
        cb_i32_f32 sjt_callback1;
        int32_t sjt_functionParam7;
        int32_t sjt_functionParam8;
        float sjv_newitem;

        sjt_callback1 = cb;
        sjt_functionParam8 = i;
        sjf_array_i32_getat(_parent, sjt_functionParam8, &sjt_functionParam7);
        sjt_callback1._cb(sjt_callback1._parent, sjt_functionParam7, &sjv_newitem);
        float* p = (float*)sjv_newdata;
        p[i] = sjv_newitem;
;
        i++;
    }

    sjt_dot2 = _parent;
    _return->datasize = (sjt_dot2)->count;
    _return->data = sjv_newdata;
    _return->_isglobal = false;
    sjt_dot3 = _parent;
    _return->count = (sjt_dot3)->count;
    sjf_array_f32(_return);
}

void sjf_array_i32_map_f32_heap(sjs_array_i32* _parent, cb_i32_f32 cb, sjs_array_f32** _return) {
    int32_t i;
    sjs_array_i32* sjt_dot4;
    sjs_array_i32* sjt_dot5;
    sjs_array_i32* sjt_dot6;
    int32_t sjt_forEnd2;
    int32_t sjt_forStart2;
    void* sjv_newdata;

    sjv_newdata = 0;
    sjv_newdata = malloc(_parent->count * sizeof(float));
    sjt_forStart2 = 0;
    sjt_dot4 = _parent;
    sjt_forEnd2 = (sjt_dot4)->count;
    i = sjt_forStart2;
    while (i < sjt_forEnd2) {
        cb_i32_f32 sjt_callback2;
        int32_t sjt_functionParam10;
        int32_t sjt_functionParam9;
        float sjv_newitem;

        sjt_callback2 = cb;
        sjt_functionParam10 = i;
        sjf_array_i32_getat(_parent, sjt_functionParam10, &sjt_functionParam9);
        sjt_callback2._cb(sjt_callback2._parent, sjt_functionParam9, &sjv_newitem);
        float* p = (float*)sjv_newdata;
        p[i] = sjv_newitem;
;
        i++;
    }

    (*_return) = (sjs_array_f32*)malloc(sizeof(sjs_array_f32));
    (*_return)->_refCount = 1;
    sjt_dot5 = _parent;
    (*_return)->datasize = (sjt_dot5)->count;
    (*_return)->data = sjv_newdata;
    (*_return)->_isglobal = false;
    sjt_dot6 = _parent;
    (*_return)->count = (sjt_dot6)->count;
    sjf_array_f32_heap((*_return));
}

void sjf_double(int32_t x, float* _return) {
    int32_t sjt_cast1;
    float sjt_math3;
    float sjt_math4;

    sjt_cast1 = x;
    sjt_math3 = (float)sjt_cast1;
    sjt_math4 = 2.0f;
    (*_return) = sjt_math3 * sjt_math4;
}

void sjf_double_callback(void * _parent, int32_t x, float* _return) {
    sjf_double(x, _return);
}

void sjf_lessthan5(float x, bool* _return) {
    float sjt_compare1;
    float sjt_compare2;

    sjt_compare1 = x;
    sjt_compare2 = 5.0f;
    (*_return) = sjt_compare1 < sjt_compare2;
}

void sjf_lessthan5_callback(void * _parent, float x, bool* _return) {
    sjf_lessthan5(x, _return);
}

void sjf_sum(sjs_sum* _this) {
}

void sjf_sum_copy(sjs_sum* _this, sjs_sum* _from) {
    _this->x = _from->x;
}

void sjf_sum_destroy(sjs_sum* _this) {
}

void sjf_sum_heap(sjs_sum* _this) {
}

void sjf_sumadd(sjs_sum* sum, float x, sjs_sum* _return) {
    sjs_sum* sjt_dot12;
    float sjt_math10;
    float sjt_math9;

    sjt_dot12 = sum;
    sjt_math9 = (sjt_dot12)->x;
    sjt_math10 = x;
    _return->x = sjt_math9 + sjt_math10;
    sjf_sum(_return);
}

void sjf_sumadd_callback(void * _parent, sjs_sum* sum, float x, sjs_sum* _return) {
    sjf_sumadd(sum, x, _return);
}

void sjf_sumadd_heap(sjs_sum* sum, float x, sjs_sum** _return) {
    sjs_sum* sjt_dot13;
    float sjt_math11;
    float sjt_math12;

    (*_return) = (sjs_sum*)malloc(sizeof(sjs_sum));
    (*_return)->_refCount = 1;
    sjt_dot13 = sum;
    sjt_math11 = (sjt_dot13)->x;
    sjt_math12 = x;
    (*_return)->x = sjt_math11 + sjt_math12;
    sjf_sum_heap((*_return));
}

int main(int argc, char** argv) {
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
    sjv_a.datasize = 3;
    sjv_a.data = 0;
    sjv_a._isglobal = false;
    sjv_a.count = 0;
    sjf_array_i32(&sjv_a);
    sjs_array_i32* array1;
    array1 = &sjv_a;
    sjt_parent1 = array1;
    sjt_functionParam1 = 0;
    sjt_functionParam2 = 1;
    sjf_array_i32_initat(sjt_parent1, sjt_functionParam1, sjt_functionParam2);
    sjt_parent2 = array1;
    sjt_functionParam3 = 1;
    sjt_functionParam4 = 2;
    sjf_array_i32_initat(sjt_parent2, sjt_functionParam3, sjt_functionParam4);
    sjt_parent3 = array1;
    sjt_functionParam5 = 2;
    sjt_functionParam6 = 3;
    sjf_array_i32_initat(sjt_parent3, sjt_functionParam5, sjt_functionParam6);
    sjt_parent4 = &sjv_a;
    sjt_functionParam11._parent = (void*)1;
    sjt_functionParam11._cb = (void(*)(void*,int32_t, float*))sjf_double_callback;
    sjf_array_i32_map_f32(sjt_parent4, sjt_functionParam11, &sjv_b);
    sjt_parent5 = &sjv_b;
    sjt_functionParam16._parent = (void*)1;
    sjt_functionParam16._cb = (void(*)(void*,float, bool*))sjf_lessthan5_callback;
    sjf_array_f32_filter(sjt_parent5, sjt_functionParam16, &sjv_c);
    sjt_parent6 = &sjv_c;
    sjt_call2.x = 0.0f;
    sjf_sum(&sjt_call2);
    sjt_functionParam20 = &sjt_call2;
    sjt_functionParam21._parent = (void*)1;
    sjt_functionParam21._cb = (void(*)(void*,sjs_sum*,float, sjs_sum*))sjf_sumadd_callback;
    sjf_array_f32_foldl_sum(sjt_parent6, sjt_functionParam20, sjt_functionParam21, &sjv_d);
    main_destroy();
    #ifdef _DEBUG
    printf("\npress return to end\n");
    getchar();
    #endif
    return 0;
}

void main_destroy() {

    sjf_sum_destroy(&sjt_call2);
    sjf_array_i32_destroy(&sjv_a);
    sjf_array_f32_destroy(&sjv_b);
    sjf_array_f32_destroy(&sjv_c);
}
