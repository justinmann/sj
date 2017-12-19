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

const char* sjg_string1 = "Shall we play\n";
const char* sjg_string2 = "Too high\n";
const char* sjg_string3 = "Too Low\n";
const char* sjg_string4 = "Correct\n";

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
#define sjs_object_typeId 1
#define sjs_array_char_typeId 2
#define sjs_string_typeId 3

typedef struct td_sjs_object sjs_object;
typedef struct td_sjs_array_char sjs_array_char;
typedef struct td_sjs_string sjs_string;

struct td_sjs_object {
    intptr_t _refCount;
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
int32_t result1;
bool result2;
sjs_string sjt_call1 = { -1 };
sjs_string sjt_call4 = { -1 };
sjs_string* sjt_functionParam1 = 0;
sjs_string* sjt_functionParam5 = 0;
int32_t sjt_math1;
int32_t sjt_math2;
int32_t sjt_math3;
int32_t sjt_math4;
int32_t sjt_math5;
int32_t sjt_math6;
int32_t sjt_negate1;
bool sjt_not1;
bool sjt_while1;
void* sjv_emptystringdata;
float sjv_f32_pi;
int32_t sjv_i32_maxvalue;
int32_t sjv_i32_minvalue;
bool sjv_iscorrect;
int32_t sjv_num;
uint32_t sjv_u32_maxvalue;

void sjf_array_char(sjs_array_char* _this);
void sjf_array_char_copy(sjs_array_char* _this, sjs_array_char* _from);
void sjf_array_char_destroy(sjs_array_char* _this);
void sjf_array_char_heap(sjs_array_char* _this);
void sjf_console_readline(sjs_string* _return);
void sjf_console_readline_heap(sjs_string** _return);
void sjf_console_write(sjs_string* data);
void sjf_i32_random(int32_t* _return);
void sjf_string(sjs_string* _this);
void sjf_string_copy(sjs_string* _this, sjs_string* _from);
void sjf_string_destroy(sjs_string* _this);
void sjf_string_heap(sjs_string* _this);
void sjf_string_toi32(sjs_string* text, int32_t* _return);
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

void sjf_console_readline(sjs_string* _return) {
    int32_t sjt_math7;
    int32_t sjt_math8;
    void* sjv_console_data;
    int32_t sjv_console_size;

    sjv_console_data = 0;
    sjv_console_size = 1024;
    char* str = (char*)malloc(size);
    int index = 0;
    char ch = ' ';
    do {
        ch = getchar();
        if (ch != '\n') {
            str[index] = ch;
            index++;
            if (index >= size) {
                size *= 2;
                str = (char*)realloc(str, size);
            }
        }
    } while (ch != '\n');
    str[index] = 0;
    index++;
    data = (void*)str;
    size = index;
    _return->_refCount = 1;
    sjt_math7 = sjv_console_size;
    sjt_math8 = 1;
    _return->count = sjt_math7 - sjt_math8;
    _return->data._refCount = 1;
    _return->data.datasize = sjv_console_size;
    _return->data.data = sjv_console_data;
    _return->data._isglobal = false;
    _return->data.count = sjv_console_size;
    sjf_array_char(&_return->data);
    sjf_string(_return);
}

void sjf_console_readline_heap(sjs_string** _return) {
    int32_t sjt_math10;
    int32_t sjt_math9;
    void* sjv_console_data;
    int32_t sjv_console_size;

    sjv_console_data = 0;
    sjv_console_size = 1024;
    char* str = (char*)malloc(size);
    int index = 0;
    char ch = ' ';
    do {
        ch = getchar();
        if (ch != '\n') {
            str[index] = ch;
            index++;
            if (index >= size) {
                size *= 2;
                str = (char*)realloc(str, size);
            }
        }
    } while (ch != '\n');
    str[index] = 0;
    index++;
    data = (void*)str;
    size = index;
    (*_return) = (sjs_string*)malloc(sizeof(sjs_string));
    (*_return)->_refCount = 1;
    sjt_math9 = sjv_console_size;
    sjt_math10 = 1;
    (*_return)->count = sjt_math9 - sjt_math10;
    (*_return)->data._refCount = 1;
    (*_return)->data.datasize = sjv_console_size;
    (*_return)->data.data = sjv_console_data;
    (*_return)->data._isglobal = false;
    (*_return)->data.count = sjv_console_size;
    sjf_array_char(&(*_return)->data);
    sjf_string_heap((*_return));
}

void sjf_console_write(sjs_string* data) {
    printf("%s", (char*)data->data.data);
}

void sjf_i32_random(int32_t* _return) {
    int32_t sjv_x;

    sjv_x = 0;
    sjv_x = rand();
    (*_return) = sjv_x;
}

void sjf_string(sjs_string* _this) {
}

void sjf_string_copy(sjs_string* _this, sjs_string* _from) {
    _this->count = _from->count;
    _this->data._refCount = 1;
    sjf_array_char_copy(&_this->data, &_from->data);
}

void sjf_string_destroy(sjs_string* _this) {
}

void sjf_string_heap(sjs_string* _this) {
}

void sjf_string_toi32(sjs_string* text, int32_t* _return) {
    int32_t sjv_x;

    sjv_x = 0;
    char* e;
    int v = (int)strtol((char*)text->data.data, &e, 10);
    if (*e != '\0') {
        sjv_x = 0;
    }
    else {
        sjv_x = v;
    }
    (*_return) = sjv_x;
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
    sjt_call1._refCount = 1;
    sjt_call1.count = 15;
    sjt_call1.data._refCount = 1;
    sjt_call1.data.datasize = 16;
    sjt_call1.data.data = (void*)sjg_string1;
    sjt_call1.data._isglobal = true;
    sjt_call1.data.count = 16;
    sjf_array_char(&sjt_call1.data);
    sjf_string(&sjt_call1);
    sjt_functionParam1 = &sjt_call1;
    sjf_console_write(sjt_functionParam1);
    sjf_i32_random(&sjt_math5);
    sjt_math6 = 10;
    sjt_math3 = sjt_math5 % sjt_math6;
    sjt_math4 = 1;
    sjv_num = sjt_math3 + sjt_math4;
    sjv_iscorrect = false;
    sjt_not1 = sjv_iscorrect;
    result2 = !sjt_not1;
    sjt_while1 = result2;
    while (sjt_while1) {
        bool result3;
        sjs_string sjt_call2 = { -1 };
        sjs_string sjt_call3 = { -1 };
        int32_t sjt_compare1;
        int32_t sjt_compare2;
        sjs_string* sjt_functionParam2 = 0;
        bool sjt_ifElse1;
        bool sjt_not2;
        int32_t sjv_guess;
        sjs_string sjv_str = { -1 };

        sjf_console_readline(&sjv_str);
        sjt_functionParam2 = &sjv_str;
        sjf_string_toi32(sjt_functionParam2, &sjv_guess);
        sjt_compare1 = sjv_guess;
        sjt_compare2 = sjv_num;
        sjt_ifElse1 = sjt_compare1 < sjt_compare2;
        if (sjt_ifElse1) {
            sjs_string* sjt_functionParam3 = 0;

            sjt_call2._refCount = 1;
            sjt_call2.count = 9;
            sjt_call2.data._refCount = 1;
            sjt_call2.data.datasize = 10;
            sjt_call2.data.data = (void*)sjg_string3;
            sjt_call2.data._isglobal = true;
            sjt_call2.data.count = 10;
            sjf_array_char(&sjt_call2.data);
            sjf_string(&sjt_call2);
            sjt_functionParam3 = &sjt_call2;
            sjf_console_write(sjt_functionParam3);
            sjv_iscorrect = false;
        } else {
            int32_t sjt_compare3;
            int32_t sjt_compare4;
            bool sjt_ifElse2;

            sjt_compare3 = sjv_guess;
            sjt_compare4 = sjv_num;
            sjt_ifElse2 = sjt_compare3 > sjt_compare4;
            if (sjt_ifElse2) {
                sjs_string* sjt_functionParam4 = 0;

                sjt_call3._refCount = 1;
                sjt_call3.count = 10;
                sjt_call3.data._refCount = 1;
                sjt_call3.data.datasize = 11;
                sjt_call3.data.data = (void*)sjg_string2;
                sjt_call3.data._isglobal = true;
                sjt_call3.data.count = 11;
                sjf_array_char(&sjt_call3.data);
                sjf_string(&sjt_call3);
                sjt_functionParam4 = &sjt_call3;
                sjf_console_write(sjt_functionParam4);
                sjv_iscorrect = false;
            } else {
                sjv_iscorrect = true;
            }
        }

        sjt_not2 = sjv_iscorrect;
        result3 = !sjt_not2;
        sjt_while1 = result3;

        if (sjt_call2._refCount == 1) { sjf_string_destroy(&sjt_call2); }
        if (sjt_call3._refCount == 1) { sjf_string_destroy(&sjt_call3); }
        if (sjv_str._refCount == 1) { sjf_string_destroy(&sjv_str); }
    }

    sjt_call4._refCount = 1;
    sjt_call4.count = 9;
    sjt_call4.data._refCount = 1;
    sjt_call4.data.datasize = 10;
    sjt_call4.data.data = (void*)sjg_string4;
    sjt_call4.data._isglobal = true;
    sjt_call4.data.count = 10;
    sjf_array_char(&sjt_call4.data);
    sjf_string(&sjt_call4);
    sjt_functionParam5 = &sjt_call4;
    sjf_console_write(sjt_functionParam5);
    main_destroy();
    #ifdef _DEBUG
    printf("\npress return to end\n");
    getchar();
    #endif
    return 0;
}

void main_destroy() {

    if (sjt_call1._refCount == 1) { sjf_string_destroy(&sjt_call1); }
    if (sjt_call4._refCount == 1) { sjf_string_destroy(&sjt_call4); }
}
