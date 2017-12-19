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

const char* sjg_string1 = " = ";

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
#define sjs_object_typeId 1
#define sjs_interface_typeId 2
#define sji_interface_typeId 3
#define sji_interface_vtbl_typeId 4
#define sjs_hash_local_interface_i32_typeId 5
#define sjs_class_typeId 6
#define cb_local_interface_i32_void_typeId 7
#define cb_local_interface_i32_void_heap_typeId 8
#define sjs_array_char_typeId 9
#define sjs_string_typeId 10

typedef struct td_sjs_object sjs_object;
typedef struct td_sjs_interface sjs_interface;
typedef struct td_sji_interface sji_interface;
typedef struct td_sji_interface_vtbl sji_interface_vtbl;
typedef struct td_sjs_hash_local_interface_i32 sjs_hash_local_interface_i32;
typedef struct td_sjs_class sjs_class;
typedef struct td_cb_local_interface_i32_void cb_local_interface_i32_void;
typedef struct td_cb_local_interface_i32_void_heap cb_local_interface_i32_void_heap;
typedef struct td_sjs_array_char sjs_array_char;
typedef struct td_sjs_string sjs_string;

struct td_sjs_object {
    intptr_t _refCount;
};

struct td_sjs_interface {
    sjs_object* _parent;
    void* _vtbl;
};

struct td_sji_interface {
    sjs_object* _parent;
    sji_interface_vtbl* _vtbl;
};

struct td_sji_interface_vtbl {
    void (*destroy)(void* _this);
    void (*asinterface)(sjs_object* _this, int typeId, sjs_interface* _return);
    void (*bob)(sjs_object* _parent, int32_t* _return);
    void (*hash)(sjs_object* _parent, uint32_t* _return);
    void (*isequal)(sjs_object* _parent, sji_interface b, bool* _return);
};

struct td_sjs_hash_local_interface_i32 {
    int _refCount;
    void* _hash;
};

struct td_sjs_class {
    int _refCount;
    int32_t x;
};

struct td_cb_local_interface_i32_void {
    sjs_object* _parent;
    void (*_cb)(sjs_object* _parent, sji_interface, int32_t);
};

struct td_cb_local_interface_i32_void_heap {
    cb_local_interface_i32_void inner;
    void (*_destroy)(sjs_object*);
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

sji_interface_vtbl sjs_class_interface_vtbl;
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
#ifndef local_interface_i32_hash_typedef
#define local_interface_i32_hash_typedef
KHASH_INIT_TYPEDEF(local_interface_i32_hash_type, sji_interface, int32_t)
#endif
#ifndef local_interface_i32_hash_typedef
#define local_interface_i32_hash_typedef
KHASH_INIT_TYPEDEF(local_interface_i32_hash_type, sji_interface, int32_t)
#endif
int32_t result1;
sjs_class sjt_call1 = { -1 };
sjs_class sjt_call2 = { -1 };
sjs_string sjt_call8 = { -1 };
sjs_class* sjt_cast1 = 0;
sjs_class* sjt_cast3 = 0;
sji_interface sjt_functionParam1 = { 0 };
int32_t sjt_functionParam2;
sjs_string* sjt_functionParam29 = 0;
sji_interface sjt_functionParam3 = { 0 };
int32_t sjt_functionParam30;
cb_local_interface_i32_void sjt_functionParam4;
bool sjt_ifElse3;
int32_option sjt_isEmpty1;
int32_t sjt_math1;
int32_t sjt_math2;
int32_t sjt_negate1;
sjs_hash_local_interface_i32* sjt_parent1 = 0;
sjs_hash_local_interface_i32* sjt_parent3 = 0;
sjs_hash_local_interface_i32* sjt_parent4 = 0;
sjs_hash_local_interface_i32 sjv_a = { -1 };
int32_option sjv_b;
void* sjv_emptystringdata;
float sjv_f32_pi;
int32_t sjv_i32_maxvalue;
int32_t sjv_i32_minvalue;
uint32_t sjv_u32_maxvalue;

void sjf_array_char(sjs_array_char* _this);
void sjf_array_char_copy(sjs_array_char* _this, sjs_array_char* _from);
void sjf_array_char_destroy(sjs_array_char* _this);
void sjf_array_char_getat(sjs_array_char* _parent, int32_t index, char* _return);
void sjf_array_char_grow(sjs_array_char* _parent, int32_t newsize, sjs_array_char* _return);
void sjf_array_char_grow_heap(sjs_array_char* _parent, int32_t newsize, sjs_array_char** _return);
void sjf_array_char_heap(sjs_array_char* _this);
void sjf_array_char_initat(sjs_array_char* _parent, int32_t index, char item);
void sjf_array_char_setat(sjs_array_char* _parent, int32_t index, char item);
void sjf_class(sjs_class* _this);
void sjf_class_as_sji_interface(sjs_class* _this, sji_interface* _return);
void sjf_class_asinterface(sjs_class* _this, int typeId, sjs_interface* _return);
void sjf_class_bob(sjs_class* _parent, int32_t* _return);
void sjf_class_copy(sjs_class* _this, sjs_class* _from);
void sjf_class_destroy(sjs_class* _this);
void sjf_class_hash(sjs_class* _parent, uint32_t* _return);
void sjf_class_heap(sjs_class* _this);
void sjf_class_heap_as_sji_interface(sjs_class* _this, sji_interface* _return);
void sjf_class_heap_asinterface(sjs_class* _this, int typeId, sjs_interface* _return);
void sjf_class_isequal(sjs_class* _parent, sji_interface b, bool* _return);
void sjf_debug_writeline(sjs_string* data);
void sjf_hash_local_interface_i32(sjs_hash_local_interface_i32* _this);
void sjf_hash_local_interface_i32__weakptrremovekey(sjs_hash_local_interface_i32* _parent, sji_interface key);
void sjf_hash_local_interface_i32__weakptrremovevalue(sjs_hash_local_interface_i32* _parent, int32_t val);
void sjf_hash_local_interface_i32_copy(sjs_hash_local_interface_i32* _this, sjs_hash_local_interface_i32* _from);
void sjf_hash_local_interface_i32_destroy(sjs_hash_local_interface_i32* _this);
void sjf_hash_local_interface_i32_each(sjs_hash_local_interface_i32* _parent, cb_local_interface_i32_void cb);
void sjf_hash_local_interface_i32_getat(sjs_hash_local_interface_i32* _parent, sji_interface key, int32_option* _return);
void sjf_hash_local_interface_i32_heap(sjs_hash_local_interface_i32* _this);
void sjf_hash_local_interface_i32_setat(sjs_hash_local_interface_i32* _parent, sji_interface key, int32_t val);
void sjf_i32_tostring(int32_t val, sjs_string* _return);
void sjf_i32_tostring_heap(int32_t val, sjs_string** _return);
void sjf_print(sji_interface k, int32_t v);
void sjf_print_callback(void * _parent, sji_interface k, int32_t v);
void sjf_string(sjs_string* _this);
void sjf_string_add(sjs_string* _parent, sjs_string* item, sjs_string* _return);
void sjf_string_add_heap(sjs_string* _parent, sjs_string* item, sjs_string** _return);
void sjf_string_copy(sjs_string* _this, sjs_string* _from);
void sjf_string_destroy(sjs_string* _this);
void sjf_string_getat(sjs_string* _parent, int32_t index, char* _return);
void sjf_string_heap(sjs_string* _this);
void sji_interface_hash(sji_interface _parent, uint32_t* _return);
void sji_interface_isequal(sji_interface _parent, sji_interface b, bool* _return);
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
#ifndef local_interface_i32_hash_function
#define local_interface_i32_hash_function
#if false
KHASH_INIT_FUNCTION_DEREF(local_interface_i32_hash_type, sji_interface, int32_t, 1, sji_interface_hash, sji_interface_isequal)
#else
KHASH_INIT_FUNCTION(local_interface_i32_hash_type, sji_interface, int32_t, 1, sji_interface_hash, sji_interface_isequal)
#endif
#endif
#ifndef local_interface_i32_hash_function
#define local_interface_i32_hash_function
#if false
KHASH_INIT_FUNCTION_DEREF(local_interface_i32_hash_type, sji_interface, int32_t, 1, sji_interface_hash, sji_interface_isequal)
#else
KHASH_INIT_FUNCTION(local_interface_i32_hash_type, sji_interface, int32_t, 1, sji_interface_hash, sji_interface_isequal)
#endif
#endif
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
    sjs_array_char* sjt_dot5 = 0;
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
    sjt_dot5 = _parent;
    _return->count = (sjt_dot5)->count;
    sjf_array_char(_return);
}

void sjf_array_char_grow_heap(sjs_array_char* _parent, int32_t newsize, sjs_array_char** _return) {
    sjs_array_char* sjt_dot6 = 0;
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
    sjt_dot6 = _parent;
    (*_return)->count = (sjt_dot6)->count;
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

void sjf_class(sjs_class* _this) {
}

void sjf_class_as_sji_interface(sjs_class* _this, sji_interface* _return) {
    _return->_parent = (sjs_object*)_this;
    _return->_vtbl = &sjs_class_interface_vtbl;
}

void sjf_class_asinterface(sjs_class* _this, int typeId, sjs_interface* _return) {
    switch (typeId) {
        case sji_interface_typeId:  {
            sjf_class_as_sji_interface(_this, (sji_interface*)_return);
            break;
        }
    }

    _return->_parent = 0;
}

void sjf_class_bob(sjs_class* _parent, int32_t* _return) {
    sjs_class* sjt_dot1 = 0;

    sjt_dot1 = _parent;
    (*_return) = (sjt_dot1)->x;
}

void sjf_class_copy(sjs_class* _this, sjs_class* _from) {
    _this->x = _from->x;
}

void sjf_class_destroy(sjs_class* _this) {
}

void sjf_class_hash(sjs_class* _parent, uint32_t* _return) {
    int32_t sjt_cast2;

    sjf_class_bob(_parent, &sjt_cast2);
    (*_return) = (uint32_t)sjt_cast2;
}

void sjf_class_heap(sjs_class* _this) {
}

void sjf_class_heap_as_sji_interface(sjs_class* _this, sji_interface* _return) {
    _return->_parent = (sjs_object*)_this;
    _return->_vtbl = &sjs_class_interface_vtbl;
}

void sjf_class_heap_asinterface(sjs_class* _this, int typeId, sjs_interface* _return) {
    switch (typeId) {
        case sji_interface_typeId:  {
            sjf_class_heap_as_sji_interface(_this, (sji_interface*)_return);
            break;
        }
    }

    _return->_parent = 0;
}

void sjf_class_isequal(sjs_class* _parent, sji_interface b, bool* _return) {
    int32_t sjt_compare1;
    int32_t sjt_compare2;
    sji_interface sjt_parent2 = { 0 };

    sjf_class_bob(_parent, &sjt_compare1);
    sjt_parent2 = b;
    sjt_parent2._vtbl->bob(sjt_parent2._parent, &sjt_compare2);
    (*_return) = sjt_compare1 == sjt_compare2;
}

void sjf_debug_writeline(sjs_string* data) {
    printf("%s\n", (char*)data->data.data);
}

void sjf_hash_local_interface_i32(sjs_hash_local_interface_i32* _this) {
    _this->_hash = kh_init(local_interface_i32_hash_type);
}

void sjf_hash_local_interface_i32__weakptrremovekey(sjs_hash_local_interface_i32* _parent, sji_interface key) {
    #if false
    khash_t(local_interface_i32_hash_type)* p = (khash_t(local_interface_i32_hash_type)*)_parent->_hash;    
    khiter_t k = kh_get(local_interface_i32_hash_type, p, key);
    if (k != kh_end(p)) {
        kh_del(local_interface_i32_hash_type, p, k);
    }
    #endif
}

void sjf_hash_local_interface_i32__weakptrremovevalue(sjs_hash_local_interface_i32* _parent, int32_t val) {
    #if false
    khash_t(local_interface_i32_hash_type)* p = (khash_t(local_interface_i32_hash_type)*)_parent->_hash;
    for (khiter_t k = kh_begin(p); k != kh_end(p); ++k) {
        if (kh_exist(p, k)) {
            int32_t t = kh_value(p, k);
            if (t == val) {
                kh_del(local_interface_i32_hash_type, p, k);
            }
        }
    }
    #endif
}

void sjf_hash_local_interface_i32_copy(sjs_hash_local_interface_i32* _this, sjs_hash_local_interface_i32* _from) {
    _this->_hash = _from->_hash;
    ptr_retain(_this->_hash);
}

void sjf_hash_local_interface_i32_destroy(sjs_hash_local_interface_i32* _this) {
    if (ptr_release(_this->_hash)) {
        khash_t(local_interface_i32_hash_type)* p = (khash_t(local_interface_i32_hash_type)*)_this->_hash;
        for (khiter_t k = kh_begin(p); k != kh_end(p); ++k) {
            if (kh_exist(p, k)) {
                #if false
                delete_cb cb = { p, (void(*)(void*, void*))sjf_hash_local_interface_i32__weakptrremovekey };
                weakptr_cb_remove(kh_key(p, k), cb);
                #else
                ;
                #endif
                #if false
                delete_cb cb = { p, (void(*)(void*, void*))sjf_hash_local_interface_i32__weakptrremovevalue };
                weakptr_cb_remove(kh_value(p, k), cb);
                #else
                ;
                #endif
            }
        }
        kh_destroy(local_interface_i32_hash_type, _this->_hash);
    }
}

void sjf_hash_local_interface_i32_each(sjs_hash_local_interface_i32* _parent, cb_local_interface_i32_void cb) {
    khash_t(local_interface_i32_hash_type)* p = (khash_t(local_interface_i32_hash_type)*)_parent->_hash;
    for (khiter_t k = kh_begin(p); k != kh_end(p); ++k) {
        if (kh_exist(p, k)) {
            cb._cb(
            cb._parent, 
            #if false
            &kh_key(p, k), 
            #else
            kh_key(p, k), 
            #endif
            #if false
            &kh_value(p, k)
            #else
            kh_value(p, k)
            #endif
            );
        }
    }
}

void sjf_hash_local_interface_i32_getat(sjs_hash_local_interface_i32* _parent, sji_interface key, int32_option* _return) {
    khash_t(local_interface_i32_hash_type)* p = (khash_t(local_interface_i32_hash_type)*)_parent->_hash;
    #if false
    khiter_t k = kh_get(local_interface_i32_hash_type, p, *key);
    #else
    khiter_t k = kh_get(local_interface_i32_hash_type, p, key);
    #endif
    if (k == kh_end(p)) {
        (*_return) = int32_empty;
return;
    }
    _return->isvalid = true;
_return->value = kh_val(p, k);
return;;
}

void sjf_hash_local_interface_i32_heap(sjs_hash_local_interface_i32* _this) {
    _this->_hash = kh_init(local_interface_i32_hash_type);
}

void sjf_hash_local_interface_i32_setat(sjs_hash_local_interface_i32* _parent, sji_interface key, int32_t val) {
    khash_t(local_interface_i32_hash_type)* p = (khash_t(local_interface_i32_hash_type)*)_parent->_hash;
    #if false
    khiter_t k = kh_get(local_interface_i32_hash_type, p, *key);
    #else
    khiter_t k = kh_get(local_interface_i32_hash_type, p, key);
    #endif
    if (k != kh_end(p)) {            
    ;
}
int ret;
#if false
k = kh_put(local_interface_i32_hash_type, _parent->_hash, *key, &ret);
#else
k = kh_put(local_interface_i32_hash_type, _parent->_hash, key, &ret);
#endif
if (!ret) kh_del(local_interface_i32_hash_type, p, k);
#if false
delete_cb cb = { _parent, (void(*)(void*, void*))sjf_hash_local_interface_i32__weakptrremovekey };
weakptr_cb_add(key, cb);
#else
sji_interface t;
t = key;
;
#endif
#if false
delete_cb cb = { _parent, (void(*)(void*, void*))sjf_hash_local_interface_i32__weakptrremovevalue };
weakptr_cb_add(val, cb);
kh_val(p, k) = val;
#else
kh_val(p, k) = val;
;
#endif
}

void sjf_i32_tostring(int32_t val, sjs_string* _return) {
    int32_t sjt_math19;
    int32_t sjt_math20;
    int32_t sjt_math21;
    int32_t sjt_math22;
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
    sjt_math19 = sjv_count;
    sjt_math20 = 1;
    _return->data.datasize = sjt_math19 + sjt_math20;
    _return->data.data = sjv_data;
    _return->data._isglobal = false;
    sjt_math21 = sjv_count;
    sjt_math22 = 1;
    _return->data.count = sjt_math21 + sjt_math22;
    sjf_array_char(&_return->data);
    sjf_string(_return);
}

void sjf_i32_tostring_heap(int32_t val, sjs_string** _return) {
    int32_t sjt_math23;
    int32_t sjt_math24;
    int32_t sjt_math25;
    int32_t sjt_math26;
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
    sjt_math23 = sjv_count;
    sjt_math24 = 1;
    (*_return)->data.datasize = sjt_math23 + sjt_math24;
    (*_return)->data.data = sjv_data;
    (*_return)->data._isglobal = false;
    sjt_math25 = sjv_count;
    sjt_math26 = 1;
    (*_return)->data.count = sjt_math25 + sjt_math26;
    sjf_array_char(&(*_return)->data);
    sjf_string_heap((*_return));
}

void sjf_print(sji_interface k, int32_t v) {
    sjs_string sjt_call3 = { -1 };
    sjs_string sjt_call4 = { -1 };
    sjs_string sjt_call5 = { -1 };
    sjs_string sjt_call6 = { -1 };
    sjs_string sjt_call7 = { -1 };
    int32_t sjt_functionParam25;
    sjs_string* sjt_functionParam26 = 0;
    sjs_string* sjt_functionParam27 = 0;
    int32_t sjt_functionParam28;
    sjs_string* sjt_functionParam5 = 0;
    sjs_string* sjt_parent18 = 0;
    sjs_string* sjt_parent19 = 0;
    sji_interface sjt_parent20 = { 0 };

    sjt_parent20 = k;
    sjt_parent20._vtbl->bob(sjt_parent20._parent, &sjt_functionParam25);
    sjf_i32_tostring(sjt_functionParam25, &sjt_call5);
    sjt_parent19 = &sjt_call5;
    sjt_call6._refCount = 1;
    sjt_call6.count = 3;
    sjt_call6.data._refCount = 1;
    sjt_call6.data.datasize = 4;
    sjt_call6.data.data = (void*)sjg_string1;
    sjt_call6.data._isglobal = true;
    sjt_call6.data.count = 4;
    sjf_array_char(&sjt_call6.data);
    sjf_string(&sjt_call6);
    sjt_functionParam26 = &sjt_call6;
    sjf_string_add(sjt_parent19, sjt_functionParam26, &sjt_call4);
    sjt_parent18 = &sjt_call4;
    sjt_functionParam28 = v;
    sjf_i32_tostring(sjt_functionParam28, &sjt_call7);
    sjt_functionParam27 = &sjt_call7;
    sjf_string_add(sjt_parent18, sjt_functionParam27, &sjt_call3);
    sjt_functionParam5 = &sjt_call3;
    sjf_debug_writeline(sjt_functionParam5);

    if (sjt_call3._refCount == 1) { sjf_string_destroy(&sjt_call3); }
    if (sjt_call4._refCount == 1) { sjf_string_destroy(&sjt_call4); }
    if (sjt_call5._refCount == 1) { sjf_string_destroy(&sjt_call5); }
    if (sjt_call6._refCount == 1) { sjf_string_destroy(&sjt_call6); }
    if (sjt_call7._refCount == 1) { sjf_string_destroy(&sjt_call7); }
}

void sjf_print_callback(void * _parent, sji_interface k, int32_t v) {
    sjf_print(k, v);
}

void sjf_string(sjs_string* _this) {
}

void sjf_string_add(sjs_string* _parent, sjs_string* item, sjs_string* _return) {
    int32_t sjt_compare3;
    int32_t sjt_compare4;
    sjs_string* sjt_dot2 = 0;
    bool sjt_ifElse1;
    sjs_array_char sjv_newdata = { -1 };

    sjt_dot2 = item;
    sjt_compare3 = (sjt_dot2)->count;
    sjt_compare4 = 0;
    sjt_ifElse1 = sjt_compare3 == sjt_compare4;
    if (sjt_ifElse1) {
        sjs_array_char* sjt_copy1 = 0;
        sjs_string* sjt_dot3 = 0;
        sjs_string* sjt_dot4 = 0;

        _return->_refCount = 1;
        sjt_dot3 = _parent;
        _return->count = (sjt_dot3)->count;
        sjt_dot4 = _parent;
        sjt_copy1 = &(sjt_dot4)->data;
        _return->data._refCount = 1;
        sjf_array_char_copy(&_return->data, sjt_copy1);
        sjf_string(_return);
    } else {
        int32_t i;
        int32_t sjt_cast4;
        sjs_array_char* sjt_copy2 = 0;
        sjs_string* sjt_dot10 = 0;
        sjs_string* sjt_dot12 = 0;
        sjs_string* sjt_dot7 = 0;
        sjs_string* sjt_dot8 = 0;
        sjs_string* sjt_dot9 = 0;
        int32_t sjt_forEnd1;
        int32_t sjt_forStart1;
        int32_t sjt_functionParam10;
        int32_t sjt_functionParam14;
        char sjt_functionParam15;
        int32_t sjt_functionParam6;
        int32_t sjt_functionParam7;
        char sjt_functionParam8;
        int32_t sjt_math3;
        int32_t sjt_math4;
        int32_t sjt_math5;
        int32_t sjt_math6;
        int32_t sjt_math7;
        int32_t sjt_math8;
        sjs_array_char* sjt_parent11 = 0;
        sjs_array_char* sjt_parent5 = 0;
        sjs_array_char* sjt_parent6 = 0;
        sjs_string* sjt_parent8 = 0;
        int32_t sjv_newcount;

        sjt_dot7 = _parent;
        sjt_parent5 = &(sjt_dot7)->data;
        sjt_dot8 = _parent;
        sjt_math5 = (sjt_dot8)->count;
        sjt_dot9 = item;
        sjt_math6 = (sjt_dot9)->count;
        sjt_math3 = sjt_math5 + sjt_math6;
        sjt_math4 = 1;
        sjt_functionParam6 = sjt_math3 + sjt_math4;
        sjf_array_char_grow(sjt_parent5, sjt_functionParam6, &sjv_newdata);
        sjt_dot10 = _parent;
        sjv_newcount = (sjt_dot10)->count;
        sjt_parent6 = &sjv_newdata;
        sjt_functionParam7 = sjv_newcount;
        sjt_parent8 = item;
        sjt_functionParam10 = 0;
        sjf_string_getat(sjt_parent8, sjt_functionParam10, &sjt_functionParam8);
        sjf_array_char_setat(sjt_parent6, sjt_functionParam7, sjt_functionParam8);
        sjt_math7 = sjv_newcount;
        sjt_math8 = 1;
        sjv_newcount = sjt_math7 + sjt_math8;
        sjt_forStart1 = 1;
        sjt_dot12 = item;
        sjt_forEnd1 = (sjt_dot12)->count;
        i = sjt_forStart1;
        while (i < sjt_forEnd1) {
            int32_t sjt_functionParam11;
            char sjt_functionParam12;
            int32_t sjt_functionParam13;
            int32_t sjt_math10;
            int32_t sjt_math9;
            sjs_string* sjt_parent10 = 0;
            sjs_array_char* sjt_parent9 = 0;

            sjt_parent9 = &sjv_newdata;
            sjt_functionParam11 = sjv_newcount;
            sjt_parent10 = item;
            sjt_functionParam13 = i;
            sjf_string_getat(sjt_parent10, sjt_functionParam13, &sjt_functionParam12);
            sjf_array_char_initat(sjt_parent9, sjt_functionParam11, sjt_functionParam12);
            sjt_math9 = sjv_newcount;
            sjt_math10 = 1;
            sjv_newcount = sjt_math9 + sjt_math10;
            i++;
        }

        sjt_parent11 = &sjv_newdata;
        sjt_functionParam14 = sjv_newcount;
        sjt_cast4 = 0;
        sjt_functionParam15 = (char)sjt_cast4;
        sjf_array_char_initat(sjt_parent11, sjt_functionParam14, sjt_functionParam15);
        _return->_refCount = 1;
        _return->count = sjv_newcount;
        sjt_copy2 = &sjv_newdata;
        _return->data._refCount = 1;
        sjf_array_char_copy(&_return->data, sjt_copy2);
        sjf_string(_return);
    }

    if (sjv_newdata._refCount == 1) { sjf_array_char_destroy(&sjv_newdata); }
}

void sjf_string_add_heap(sjs_string* _parent, sjs_string* item, sjs_string** _return) {
    int32_t sjt_compare5;
    int32_t sjt_compare6;
    sjs_string* sjt_dot13 = 0;
    bool sjt_ifElse2;
    sjs_array_char sjv_newdata = { -1 };

    sjt_dot13 = item;
    sjt_compare5 = (sjt_dot13)->count;
    sjt_compare6 = 0;
    sjt_ifElse2 = sjt_compare5 == sjt_compare6;
    if (sjt_ifElse2) {
        sjs_array_char* sjt_copy3 = 0;
        sjs_string* sjt_dot14 = 0;
        sjs_string* sjt_dot15 = 0;

        (*_return) = (sjs_string*)malloc(sizeof(sjs_string));
        (*_return)->_refCount = 1;
        sjt_dot14 = _parent;
        (*_return)->count = (sjt_dot14)->count;
        sjt_dot15 = _parent;
        sjt_copy3 = &(sjt_dot15)->data;
        (*_return)->data._refCount = 1;
        sjf_array_char_copy(&(*_return)->data, sjt_copy3);
        sjf_string_heap((*_return));
    } else {
        int32_t i;
        int32_t sjt_cast5;
        sjs_array_char* sjt_copy4 = 0;
        sjs_string* sjt_dot16 = 0;
        sjs_string* sjt_dot17 = 0;
        sjs_string* sjt_dot18 = 0;
        sjs_string* sjt_dot19 = 0;
        sjs_string* sjt_dot20 = 0;
        int32_t sjt_forEnd2;
        int32_t sjt_forStart2;
        int32_t sjt_functionParam16;
        int32_t sjt_functionParam17;
        char sjt_functionParam18;
        int32_t sjt_functionParam19;
        int32_t sjt_functionParam23;
        char sjt_functionParam24;
        int32_t sjt_math11;
        int32_t sjt_math12;
        int32_t sjt_math13;
        int32_t sjt_math14;
        int32_t sjt_math15;
        int32_t sjt_math16;
        sjs_array_char* sjt_parent12 = 0;
        sjs_array_char* sjt_parent13 = 0;
        sjs_string* sjt_parent14 = 0;
        sjs_array_char* sjt_parent17 = 0;
        int32_t sjv_newcount;

        sjt_dot16 = _parent;
        sjt_parent12 = &(sjt_dot16)->data;
        sjt_dot17 = _parent;
        sjt_math13 = (sjt_dot17)->count;
        sjt_dot18 = item;
        sjt_math14 = (sjt_dot18)->count;
        sjt_math11 = sjt_math13 + sjt_math14;
        sjt_math12 = 1;
        sjt_functionParam16 = sjt_math11 + sjt_math12;
        sjf_array_char_grow(sjt_parent12, sjt_functionParam16, &sjv_newdata);
        sjt_dot19 = _parent;
        sjv_newcount = (sjt_dot19)->count;
        sjt_parent13 = &sjv_newdata;
        sjt_functionParam17 = sjv_newcount;
        sjt_parent14 = item;
        sjt_functionParam19 = 0;
        sjf_string_getat(sjt_parent14, sjt_functionParam19, &sjt_functionParam18);
        sjf_array_char_setat(sjt_parent13, sjt_functionParam17, sjt_functionParam18);
        sjt_math15 = sjv_newcount;
        sjt_math16 = 1;
        sjv_newcount = sjt_math15 + sjt_math16;
        sjt_forStart2 = 1;
        sjt_dot20 = item;
        sjt_forEnd2 = (sjt_dot20)->count;
        i = sjt_forStart2;
        while (i < sjt_forEnd2) {
            int32_t sjt_functionParam20;
            char sjt_functionParam21;
            int32_t sjt_functionParam22;
            int32_t sjt_math17;
            int32_t sjt_math18;
            sjs_array_char* sjt_parent15 = 0;
            sjs_string* sjt_parent16 = 0;

            sjt_parent15 = &sjv_newdata;
            sjt_functionParam20 = sjv_newcount;
            sjt_parent16 = item;
            sjt_functionParam22 = i;
            sjf_string_getat(sjt_parent16, sjt_functionParam22, &sjt_functionParam21);
            sjf_array_char_initat(sjt_parent15, sjt_functionParam20, sjt_functionParam21);
            sjt_math17 = sjv_newcount;
            sjt_math18 = 1;
            sjv_newcount = sjt_math17 + sjt_math18;
            i++;
        }

        sjt_parent17 = &sjv_newdata;
        sjt_functionParam23 = sjv_newcount;
        sjt_cast5 = 0;
        sjt_functionParam24 = (char)sjt_cast5;
        sjf_array_char_initat(sjt_parent17, sjt_functionParam23, sjt_functionParam24);
        (*_return) = (sjs_string*)malloc(sizeof(sjs_string));
        (*_return)->_refCount = 1;
        (*_return)->count = sjv_newcount;
        sjt_copy4 = &sjv_newdata;
        (*_return)->data._refCount = 1;
        sjf_array_char_copy(&(*_return)->data, sjt_copy4);
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
    sjs_string* sjt_dot11 = 0;
    int32_t sjt_functionParam9;
    sjs_array_char* sjt_parent7 = 0;

    sjt_dot11 = _parent;
    sjt_parent7 = &(sjt_dot11)->data;
    sjt_functionParam9 = index;
    sjf_array_char_getat(sjt_parent7, sjt_functionParam9, _return);
}

void sjf_string_heap(sjs_string* _this) {
}

void sji_interface_hash(sji_interface _parent, uint32_t* _return) {
    _parent._vtbl->hash(_parent._parent, _return);
}

void sji_interface_isequal(sji_interface _parent, sji_interface b, bool* _return) {
    _parent._vtbl->isequal(_parent._parent, b, _return);
}

int main(int argc, char** argv) {
    sjs_class_interface_vtbl.destroy = (void(*)(void*))sjf_class_destroy;
    sjs_class_interface_vtbl.asinterface = (void(*)(sjs_object*,int,sjs_interface*))sjf_class_asinterface;
    sjs_class_interface_vtbl.bob = (void(*)(sjs_object*, int32_t*))sjf_class_bob;
    sjs_class_interface_vtbl.hash = (void(*)(sjs_object*, uint32_t*))sjf_class_hash;
    sjs_class_interface_vtbl.isequal = (void(*)(sjs_object*,sji_interface, bool*))sjf_class_isequal;
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
    sjv_a._refCount = 1;
    sjf_hash_local_interface_i32(&sjv_a);
    sjt_parent1 = &sjv_a;
    sjt_call1._refCount = 1;
    sjt_call1.x = 32;
    sjf_class(&sjt_call1);
    sjt_cast1 = &sjt_call1;
    sjf_class_as_sji_interface(sjt_cast1, &sjt_functionParam1);
    sjt_functionParam2 = 1;
    sjf_hash_local_interface_i32_setat(sjt_parent1, sjt_functionParam1, sjt_functionParam2);
    sjt_parent3 = &sjv_a;
    sjt_call2._refCount = 1;
    sjt_call2.x = 1;
    sjf_class(&sjt_call2);
    sjt_cast3 = &sjt_call2;
    sjf_class_as_sji_interface(sjt_cast3, &sjt_functionParam3);
    sjf_hash_local_interface_i32_getat(sjt_parent3, sjt_functionParam3, &sjv_b);
    sjt_parent4 = &sjv_a;
    sjt_functionParam4._parent = (sjs_object*)1;
    sjt_functionParam4._cb = (void(*)(sjs_object*,sji_interface,int32_t))sjf_print_callback;
    sjf_hash_local_interface_i32_each(sjt_parent4, sjt_functionParam4);
    sjt_isEmpty1 = sjv_b;
    sjt_ifElse3 = sjt_isEmpty1.isvalid;
    if (sjt_ifElse3) {
        int32_option sjt_getValue1;

        sjt_getValue1 = sjv_b;
        sjt_functionParam30 = sjt_getValue1.value;
    } else {
        int32_t result2;
        int32_t sjt_negate2;

        sjt_negate2 = 1;
        result2 = -sjt_negate2;
        sjt_functionParam30 = result2;
    }

    sjf_i32_tostring(sjt_functionParam30, &sjt_call8);
    sjt_functionParam29 = &sjt_call8;
    sjf_debug_writeline(sjt_functionParam29);
    main_destroy();
    #ifdef _DEBUG
    printf("\npress return to end\n");
    getchar();
    #endif
    return 0;
}

void main_destroy() {

    if (sjt_call1._refCount == 1) { sjf_class_destroy(&sjt_call1); }
    if (sjt_call2._refCount == 1) { sjf_class_destroy(&sjt_call2); }
    if (sjt_call8._refCount == 1) { sjf_string_destroy(&sjt_call8); }
    if (sjv_a._refCount == 1) { sjf_hash_local_interface_i32_destroy(&sjv_a); }
}
