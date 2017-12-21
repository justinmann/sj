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

const char* sjg_string1 = ", ";
const char* sjg_string3 = "";
const char* sjg_string4 = "";
const char* sjg_string5 = "";
const char* sjg_string6 = "";

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
#define sjs_class_typeId 3
#define sjs_array_weak_class_typeId 4
#define sjs_array_char_typeId 5
#define sjs_string_typeId 6

typedef struct td_sjs_object sjs_object;
typedef struct td_sjs_interface sjs_interface;
typedef struct td_sjs_class sjs_class;
typedef struct td_sjs_array_weak_class sjs_array_weak_class;
typedef struct td_sjs_array_char sjs_array_char;
typedef struct td_sjs_string sjs_string;

struct td_sjs_object {
    intptr_t _refCount;
};

struct td_sjs_interface {
    sjs_object* _parent;
    void* _vtbl;
};

struct td_sjs_class {
    int _refCount;
    int32_t x;
};

struct td_sjs_array_weak_class {
    int _refCount;
    int32_t datasize;
    void* data;
    bool _isglobal;
    int32_t count;
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
sjs_string sjt_call1 = { -1 };
sjs_string sjt_call12 = { -1 };
sjs_string sjt_call13 = { -1 };
sjs_string sjt_call14 = { -1 };
sjs_string sjt_call15 = { -1 };
sjs_string sjt_call16 = { -1 };
int32_t sjt_functionParam1;
sjs_class* sjt_functionParam2 = 0;
int32_t sjt_functionParam3;
sjs_string* sjt_functionParam39 = 0;
sjs_class* sjt_functionParam4 = 0;
sjs_string* sjt_functionParam40 = 0;
sjs_string* sjt_functionParam41 = 0;
sjs_string* sjt_functionParam42 = 0;
sjs_string* sjt_functionParam43 = 0;
sjs_string* sjt_functionParam5 = 0;
int32_t sjt_math1;
int32_t sjt_math2;
int32_t sjt_negate1;
sjs_array_weak_class* sjt_parent1 = 0;
sjs_array_weak_class* sjt_parent2 = 0;
sjs_array_weak_class* sjt_parent24 = 0;
sjs_array_weak_class* sjt_parent25 = 0;
sjs_array_weak_class* sjt_parent26 = 0;
sjs_array_weak_class sjv_a = { -1 };
sjs_class* sjv_c = 0;
sjs_class* sjv_d = 0;
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
void sjf_array_weak_class(sjs_array_weak_class* _this);
void sjf_array_weak_class_asstring(sjs_array_weak_class* _parent, sjs_string* sep, sjs_string* _return);
void sjf_array_weak_class_asstring_heap(sjs_array_weak_class* _parent, sjs_string* sep, sjs_string** _return);
void sjf_array_weak_class_copy(sjs_array_weak_class* _this, sjs_array_weak_class* _from);
void sjf_array_weak_class_destroy(sjs_array_weak_class* _this);
void sjf_array_weak_class_getat(sjs_array_weak_class* _parent, int32_t index, sjs_class** _return);
void sjf_array_weak_class_heap(sjs_array_weak_class* _this);
void sjf_array_weak_class_initat(sjs_array_weak_class* _parent, int32_t index, sjs_class* item);
void sjf_class(sjs_class* _this);
void sjf_class_asstring(sjs_class* _parent, sjs_string* _return);
void sjf_class_asstring_heap(sjs_class* _parent, sjs_string** _return);
void sjf_class_copy(sjs_class* _this, sjs_class* _from);
void sjf_class_destroy(sjs_class* _this);
void sjf_class_heap(sjs_class* _this);
void sjf_debug_writeline(sjs_string* data);
void sjf_i32_asstring(int32_t val, sjs_string* _return);
void sjf_i32_asstring_heap(int32_t val, sjs_string** _return);
void sjf_string(sjs_string* _this);
void sjf_string_add(sjs_string* _parent, sjs_string* item, sjs_string* _return);
void sjf_string_add_heap(sjs_string* _parent, sjs_string* item, sjs_string** _return);
void sjf_string_copy(sjs_string* _this, sjs_string* _from);
void sjf_string_destroy(sjs_string* _this);
void sjf_string_getat(sjs_string* _parent, int32_t index, char* _return);
void sjf_string_heap(sjs_string* _this);
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

void sjf_array_weak_class(sjs_array_weak_class* _this) {
    if (_this->datasize < 0) {
        halt("size is less than zero");
    }
    if (!_this->data) {
        _this->data = malloc(_this->datasize * sizeof(sjs_class*));
        if (!_this->data) {
            halt("grow: out of memory\n");
        }
    }
}

void sjf_array_weak_class_asstring(sjs_array_weak_class* _parent, sjs_string* sep, sjs_string* _return) {
    int32_t i;
    sjs_string* sjt_copy5 = 0;
    sjs_array_weak_class* sjt_dot1 = 0;
    int32_t sjt_forEnd1;
    int32_t sjt_forStart1;
    sjs_string sjv_result = { -1 };

    sjv_result._refCount = 1;
    sjv_result.count = 0;
    sjv_result.data._refCount = 1;
    sjv_result.data.datasize = 1;
    sjv_result.data.data = (void*)sjg_string3;
    sjv_result.data._isglobal = true;
    sjv_result.data.count = 1;
    sjf_array_char(&sjv_result.data);
    sjf_string(&sjv_result);
    sjt_forStart1 = 0;
    sjt_dot1 = _parent;
    sjt_forEnd1 = (sjt_dot1)->count;
    i = sjt_forStart1;
    while (i < sjt_forEnd1) {
        sjs_class* sjt_call2 = 0;
        sjs_string sjt_call6 = { -1 };
        int32_t sjt_compare1;
        int32_t sjt_compare2;
        sjs_string* sjt_functionParam26 = 0;
        int32_t sjt_functionParam27;
        bool sjt_ifElse1;
        bool sjt_ifElse4;
        bool sjt_ifElse5;
        sjs_string* sjt_isEmpty1 = 0;
        sjs_class* sjt_isEmpty2 = 0;
        sjs_string* sjt_parent17 = 0;
        sjs_string sjt_value1 = { -1 };
        sjs_string sjt_value2 = { -1 };

        sjt_compare1 = i;
        sjt_compare2 = 0;
        sjt_ifElse1 = sjt_compare1 != sjt_compare2;
        if (sjt_ifElse1) {
            sjs_string* sjt_functionParam25 = 0;
            sjs_string* sjt_parent16 = 0;

            sjt_parent16 = &sjv_result;
            sjt_functionParam25 = sep;
            sjf_string_add(sjt_parent16, sjt_functionParam25, &sjv_result);
        }

        sjt_parent17 = &sjv_result;
        sjt_functionParam27 = i;
        sjf_array_weak_class_getat(_parent, sjt_functionParam27, &sjt_call2);
        sjt_isEmpty2 = sjt_call2;
        sjt_ifElse5 = (sjt_isEmpty2 != 0);
        if (sjt_ifElse5) {
            sjs_class* sjt_call3 = 0;
            int32_t sjt_functionParam30;
            sjs_class* sjt_parent18 = 0;

            sjt_functionParam30 = i;
            sjf_array_weak_class_getat(_parent, sjt_functionParam30, &sjt_call3);
            sjt_parent18 = sjt_call3;
            sjf_class_asstring(sjt_parent18, &sjt_value1);
            sjt_isEmpty1 = (sjt_value1._refCount != -1 ? &sjt_value1 : 0);

            delete_cb weakptrcb8 = { &sjt_call3, weakptr_clear };
            if (sjt_call3 != 0) { weakptr_cb_remove(sjt_call3, weakptrcb8); }
        } else {
            sjt_isEmpty1 = 0;
        }

        sjt_ifElse4 = (sjt_isEmpty1 != 0);
        if (sjt_ifElse4) {
            sjs_class* sjt_call4 = 0;
            int32_t sjt_functionParam31;
            bool sjt_ifElse6;
            sjs_class* sjt_isEmpty3 = 0;

            sjt_functionParam31 = i;
            sjf_array_weak_class_getat(_parent, sjt_functionParam31, &sjt_call4);
            sjt_isEmpty3 = sjt_call4;
            sjt_ifElse6 = (sjt_isEmpty3 != 0);
            if (sjt_ifElse6) {
                sjs_class* sjt_call5 = 0;
                int32_t sjt_functionParam32;
                sjs_class* sjt_parent19 = 0;

                sjt_functionParam32 = i;
                sjf_array_weak_class_getat(_parent, sjt_functionParam32, &sjt_call5);
                sjt_parent19 = sjt_call5;
                sjf_class_asstring(sjt_parent19, &sjt_value2);
                sjt_functionParam26 = (sjt_value2._refCount != -1 ? &sjt_value2 : 0);

                delete_cb weakptrcb9 = { &sjt_call5, weakptr_clear };
                if (sjt_call5 != 0) { weakptr_cb_remove(sjt_call5, weakptrcb9); }
            } else {
                sjt_functionParam26 = 0;
            }

            delete_cb weakptrcb10 = { &sjt_call4, weakptr_clear };
            if (sjt_call4 != 0) { weakptr_cb_remove(sjt_call4, weakptrcb10); }
        } else {
            sjt_call6._refCount = 1;
            sjt_call6.count = 0;
            sjt_call6.data._refCount = 1;
            sjt_call6.data.datasize = 1;
            sjt_call6.data.data = (void*)sjg_string4;
            sjt_call6.data._isglobal = true;
            sjt_call6.data.count = 1;
            sjf_array_char(&sjt_call6.data);
            sjf_string(&sjt_call6);
            sjt_functionParam26 = &sjt_call6;
        }

        sjf_string_add(sjt_parent17, sjt_functionParam26, &sjv_result);
        i++;

        delete_cb weakptrcb11 = { &sjt_call2, weakptr_clear };
        if (sjt_call2 != 0) { weakptr_cb_remove(sjt_call2, weakptrcb11); }
        if (sjt_call6._refCount == 1) { sjf_string_destroy(&sjt_call6); }
        if (sjt_value1._refCount == 1) { sjf_string_destroy(&sjt_value1); }
        if (sjt_value2._refCount == 1) { sjf_string_destroy(&sjt_value2); }
    }

    sjt_copy5 = &sjv_result;
    _return->_refCount = 1;
    sjf_string_copy(_return, sjt_copy5);

    if (sjv_result._refCount == 1) { sjf_string_destroy(&sjv_result); }
}

void sjf_array_weak_class_asstring_heap(sjs_array_weak_class* _parent, sjs_string* sep, sjs_string** _return) {
    int32_t i;
    sjs_string* sjt_copy6 = 0;
    sjs_array_weak_class* sjt_dot23 = 0;
    int32_t sjt_forEnd4;
    int32_t sjt_forStart4;
    sjs_string sjv_result = { -1 };

    sjv_result._refCount = 1;
    sjv_result.count = 0;
    sjv_result.data._refCount = 1;
    sjv_result.data.datasize = 1;
    sjv_result.data.data = (void*)sjg_string5;
    sjv_result.data._isglobal = true;
    sjv_result.data.count = 1;
    sjf_array_char(&sjv_result.data);
    sjf_string(&sjv_result);
    sjt_forStart4 = 0;
    sjt_dot23 = _parent;
    sjt_forEnd4 = (sjt_dot23)->count;
    i = sjt_forStart4;
    while (i < sjt_forEnd4) {
        sjs_string sjt_call11 = { -1 };
        sjs_class* sjt_call7 = 0;
        int32_t sjt_compare7;
        int32_t sjt_compare8;
        sjs_string* sjt_functionParam34 = 0;
        int32_t sjt_functionParam35;
        bool sjt_ifElse7;
        bool sjt_ifElse8;
        bool sjt_ifElse9;
        sjs_string* sjt_isEmpty4 = 0;
        sjs_class* sjt_isEmpty5 = 0;
        sjs_string* sjt_parent21 = 0;
        sjs_string sjt_value3 = { -1 };
        sjs_string sjt_value4 = { -1 };

        sjt_compare7 = i;
        sjt_compare8 = 0;
        sjt_ifElse7 = sjt_compare7 != sjt_compare8;
        if (sjt_ifElse7) {
            sjs_string* sjt_functionParam33 = 0;
            sjs_string* sjt_parent20 = 0;

            sjt_parent20 = &sjv_result;
            sjt_functionParam33 = sep;
            sjf_string_add(sjt_parent20, sjt_functionParam33, &sjv_result);
        }

        sjt_parent21 = &sjv_result;
        sjt_functionParam35 = i;
        sjf_array_weak_class_getat(_parent, sjt_functionParam35, &sjt_call7);
        sjt_isEmpty5 = sjt_call7;
        sjt_ifElse9 = (sjt_isEmpty5 != 0);
        if (sjt_ifElse9) {
            sjs_class* sjt_call8 = 0;
            int32_t sjt_functionParam36;
            sjs_class* sjt_parent22 = 0;

            sjt_functionParam36 = i;
            sjf_array_weak_class_getat(_parent, sjt_functionParam36, &sjt_call8);
            sjt_parent22 = sjt_call8;
            sjf_class_asstring(sjt_parent22, &sjt_value3);
            sjt_isEmpty4 = (sjt_value3._refCount != -1 ? &sjt_value3 : 0);

            delete_cb weakptrcb12 = { &sjt_call8, weakptr_clear };
            if (sjt_call8 != 0) { weakptr_cb_remove(sjt_call8, weakptrcb12); }
        } else {
            sjt_isEmpty4 = 0;
        }

        sjt_ifElse8 = (sjt_isEmpty4 != 0);
        if (sjt_ifElse8) {
            sjs_class* sjt_call9 = 0;
            int32_t sjt_functionParam37;
            bool sjt_ifElse10;
            sjs_class* sjt_isEmpty6 = 0;

            sjt_functionParam37 = i;
            sjf_array_weak_class_getat(_parent, sjt_functionParam37, &sjt_call9);
            sjt_isEmpty6 = sjt_call9;
            sjt_ifElse10 = (sjt_isEmpty6 != 0);
            if (sjt_ifElse10) {
                sjs_class* sjt_call10 = 0;
                int32_t sjt_functionParam38;
                sjs_class* sjt_parent23 = 0;

                sjt_functionParam38 = i;
                sjf_array_weak_class_getat(_parent, sjt_functionParam38, &sjt_call10);
                sjt_parent23 = sjt_call10;
                sjf_class_asstring(sjt_parent23, &sjt_value4);
                sjt_functionParam34 = (sjt_value4._refCount != -1 ? &sjt_value4 : 0);

                delete_cb weakptrcb13 = { &sjt_call10, weakptr_clear };
                if (sjt_call10 != 0) { weakptr_cb_remove(sjt_call10, weakptrcb13); }
            } else {
                sjt_functionParam34 = 0;
            }

            delete_cb weakptrcb14 = { &sjt_call9, weakptr_clear };
            if (sjt_call9 != 0) { weakptr_cb_remove(sjt_call9, weakptrcb14); }
        } else {
            sjt_call11._refCount = 1;
            sjt_call11.count = 0;
            sjt_call11.data._refCount = 1;
            sjt_call11.data.datasize = 1;
            sjt_call11.data.data = (void*)sjg_string6;
            sjt_call11.data._isglobal = true;
            sjt_call11.data.count = 1;
            sjf_array_char(&sjt_call11.data);
            sjf_string(&sjt_call11);
            sjt_functionParam34 = &sjt_call11;
        }

        sjf_string_add(sjt_parent21, sjt_functionParam34, &sjv_result);
        i++;

        delete_cb weakptrcb15 = { &sjt_call7, weakptr_clear };
        if (sjt_call7 != 0) { weakptr_cb_remove(sjt_call7, weakptrcb15); }
        if (sjt_call11._refCount == 1) { sjf_string_destroy(&sjt_call11); }
        if (sjt_value3._refCount == 1) { sjf_string_destroy(&sjt_value3); }
        if (sjt_value4._refCount == 1) { sjf_string_destroy(&sjt_value4); }
    }

    sjt_copy6 = &sjv_result;
    (*_return) = (sjs_string*)malloc(sizeof(sjs_string));
    (*_return)->_refCount = 1;
    sjf_string_copy((*_return), sjt_copy6);

    if (sjv_result._refCount == 1) { sjf_string_destroy(&sjv_result); }
}

void sjf_array_weak_class_copy(sjs_array_weak_class* _this, sjs_array_weak_class* _from) {
    _this->datasize = _from->datasize;
    _this->data = _from->data;
    _this->_isglobal = _from->_isglobal;
    _this->count = _from->count;
    _this->data = _from->data;
    if (!_this->_isglobal && _this->data) {
        ptr_retain(_this->data);
    }
}

void sjf_array_weak_class_destroy(sjs_array_weak_class* _this) {
    if (!_this->_isglobal && _this->data) {
        if (ptr_release(_this->data)) {
            sjs_class** p = (sjs_class**)_this->data;
            for (int i = 0; i < _this->count; i++) {
                delete_cb weakptrcb3 = { &p[i], weakptr_clear };
if (p[i] != 0) { weakptr_cb_remove(p[i], weakptrcb3); }
;
            }
            free(p);
        }
    }
}

void sjf_array_weak_class_getat(sjs_array_weak_class* _parent, int32_t index, sjs_class** _return) {
    if (index >= _parent->count || index < 0) {
        halt("getAt: out of bounds\n");
    }
    sjs_class** p = (sjs_class**)_parent->data;
    (*_return) = p[index];
delete_cb weakptrcb7 = { &(*_return), weakptr_clear };
if ((*_return) != 0) { weakptr_cb_add((*_return), weakptrcb7); }
return;;		
}

void sjf_array_weak_class_heap(sjs_array_weak_class* _this) {
    if (_this->datasize < 0) {
        halt("size is less than zero");
    }
    if (!_this->data) {
        _this->data = malloc(_this->datasize * sizeof(sjs_class*));
        if (!_this->data) {
            halt("grow: out of memory\n");
        }
    }
}

void sjf_array_weak_class_initat(sjs_array_weak_class* _parent, int32_t index, sjs_class* item) {
    if (index != _parent->count) {
        halt("initAt: can only initialize last element\n");		
    }
    if (index >= _parent->datasize || index < 0) {
        halt("initAt: out of bounds %d:%d\n", index, _parent->datasize);
    }
    sjs_class** p = (sjs_class**)_parent->data;
    p[index] = item;
delete_cb weakptrcb4 = { &p[index], weakptr_clear };
if (p[index] != 0) { weakptr_cb_add(p[index], weakptrcb4); }
;
    _parent->count = index + 1;
}

void sjf_class(sjs_class* _this) {
}

void sjf_class_asstring(sjs_class* _parent, sjs_string* _return) {
    sjs_class* sjt_dot21 = 0;
    int32_t sjt_functionParam28;

    sjt_dot21 = _parent;
    sjt_functionParam28 = (sjt_dot21)->x;
    sjf_i32_asstring(sjt_functionParam28, _return);
}

void sjf_class_asstring_heap(sjs_class* _parent, sjs_string** _return) {
    sjs_class* sjt_dot22 = 0;
    int32_t sjt_functionParam29;

    sjt_dot22 = _parent;
    sjt_functionParam29 = (sjt_dot22)->x;
    sjf_i32_asstring_heap(sjt_functionParam29, _return);
}

void sjf_class_copy(sjs_class* _this, sjs_class* _from) {
    _this->x = _from->x;
}

void sjf_class_destroy(sjs_class* _this) {
}

void sjf_class_heap(sjs_class* _this) {
}

void sjf_debug_writeline(sjs_string* data) {
    printf("%s\n", (char*)data->data.data);
}

void sjf_i32_asstring(int32_t val, sjs_string* _return) {
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

void sjf_i32_asstring_heap(int32_t val, sjs_string** _return) {
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

void sjf_string(sjs_string* _this) {
}

void sjf_string_add(sjs_string* _parent, sjs_string* item, sjs_string* _return) {
    int32_t sjt_compare3;
    int32_t sjt_compare4;
    sjs_string* sjt_dot2 = 0;
    bool sjt_ifElse2;
    sjs_array_char sjv_newdata = { -1 };

    sjt_dot2 = item;
    sjt_compare3 = (sjt_dot2)->count;
    sjt_compare4 = 0;
    sjt_ifElse2 = sjt_compare3 == sjt_compare4;
    if (sjt_ifElse2) {
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
        int32_t sjt_cast1;
        sjs_array_char* sjt_copy2 = 0;
        sjs_string* sjt_dot10 = 0;
        sjs_string* sjt_dot12 = 0;
        sjs_string* sjt_dot7 = 0;
        sjs_string* sjt_dot8 = 0;
        sjs_string* sjt_dot9 = 0;
        int32_t sjt_forEnd2;
        int32_t sjt_forStart2;
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
        sjs_array_char* sjt_parent3 = 0;
        sjs_array_char* sjt_parent4 = 0;
        sjs_string* sjt_parent6 = 0;
        sjs_array_char* sjt_parent9 = 0;
        int32_t sjv_newcount;

        sjt_dot7 = _parent;
        sjt_parent3 = &(sjt_dot7)->data;
        sjt_dot8 = _parent;
        sjt_math5 = (sjt_dot8)->count;
        sjt_dot9 = item;
        sjt_math6 = (sjt_dot9)->count;
        sjt_math3 = sjt_math5 + sjt_math6;
        sjt_math4 = 1;
        sjt_functionParam6 = sjt_math3 + sjt_math4;
        sjf_array_char_grow(sjt_parent3, sjt_functionParam6, &sjv_newdata);
        sjt_dot10 = _parent;
        sjv_newcount = (sjt_dot10)->count;
        sjt_parent4 = &sjv_newdata;
        sjt_functionParam7 = sjv_newcount;
        sjt_parent6 = item;
        sjt_functionParam10 = 0;
        sjf_string_getat(sjt_parent6, sjt_functionParam10, &sjt_functionParam8);
        sjf_array_char_setat(sjt_parent4, sjt_functionParam7, sjt_functionParam8);
        sjt_math7 = sjv_newcount;
        sjt_math8 = 1;
        sjv_newcount = sjt_math7 + sjt_math8;
        sjt_forStart2 = 1;
        sjt_dot12 = item;
        sjt_forEnd2 = (sjt_dot12)->count;
        i = sjt_forStart2;
        while (i < sjt_forEnd2) {
            int32_t sjt_functionParam11;
            char sjt_functionParam12;
            int32_t sjt_functionParam13;
            int32_t sjt_math10;
            int32_t sjt_math9;
            sjs_array_char* sjt_parent7 = 0;
            sjs_string* sjt_parent8 = 0;

            sjt_parent7 = &sjv_newdata;
            sjt_functionParam11 = sjv_newcount;
            sjt_parent8 = item;
            sjt_functionParam13 = i;
            sjf_string_getat(sjt_parent8, sjt_functionParam13, &sjt_functionParam12);
            sjf_array_char_initat(sjt_parent7, sjt_functionParam11, sjt_functionParam12);
            sjt_math9 = sjv_newcount;
            sjt_math10 = 1;
            sjv_newcount = sjt_math9 + sjt_math10;
            i++;
        }

        sjt_parent9 = &sjv_newdata;
        sjt_functionParam14 = sjv_newcount;
        sjt_cast1 = 0;
        sjt_functionParam15 = (char)sjt_cast1;
        sjf_array_char_initat(sjt_parent9, sjt_functionParam14, sjt_functionParam15);
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
    bool sjt_ifElse3;
    sjs_array_char sjv_newdata = { -1 };

    sjt_dot13 = item;
    sjt_compare5 = (sjt_dot13)->count;
    sjt_compare6 = 0;
    sjt_ifElse3 = sjt_compare5 == sjt_compare6;
    if (sjt_ifElse3) {
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
        int32_t sjt_cast2;
        sjs_array_char* sjt_copy4 = 0;
        sjs_string* sjt_dot16 = 0;
        sjs_string* sjt_dot17 = 0;
        sjs_string* sjt_dot18 = 0;
        sjs_string* sjt_dot19 = 0;
        sjs_string* sjt_dot20 = 0;
        int32_t sjt_forEnd3;
        int32_t sjt_forStart3;
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
        sjs_array_char* sjt_parent10 = 0;
        sjs_array_char* sjt_parent11 = 0;
        sjs_string* sjt_parent12 = 0;
        sjs_array_char* sjt_parent15 = 0;
        int32_t sjv_newcount;

        sjt_dot16 = _parent;
        sjt_parent10 = &(sjt_dot16)->data;
        sjt_dot17 = _parent;
        sjt_math13 = (sjt_dot17)->count;
        sjt_dot18 = item;
        sjt_math14 = (sjt_dot18)->count;
        sjt_math11 = sjt_math13 + sjt_math14;
        sjt_math12 = 1;
        sjt_functionParam16 = sjt_math11 + sjt_math12;
        sjf_array_char_grow(sjt_parent10, sjt_functionParam16, &sjv_newdata);
        sjt_dot19 = _parent;
        sjv_newcount = (sjt_dot19)->count;
        sjt_parent11 = &sjv_newdata;
        sjt_functionParam17 = sjv_newcount;
        sjt_parent12 = item;
        sjt_functionParam19 = 0;
        sjf_string_getat(sjt_parent12, sjt_functionParam19, &sjt_functionParam18);
        sjf_array_char_setat(sjt_parent11, sjt_functionParam17, sjt_functionParam18);
        sjt_math15 = sjv_newcount;
        sjt_math16 = 1;
        sjv_newcount = sjt_math15 + sjt_math16;
        sjt_forStart3 = 1;
        sjt_dot20 = item;
        sjt_forEnd3 = (sjt_dot20)->count;
        i = sjt_forStart3;
        while (i < sjt_forEnd3) {
            int32_t sjt_functionParam20;
            char sjt_functionParam21;
            int32_t sjt_functionParam22;
            int32_t sjt_math17;
            int32_t sjt_math18;
            sjs_array_char* sjt_parent13 = 0;
            sjs_string* sjt_parent14 = 0;

            sjt_parent13 = &sjv_newdata;
            sjt_functionParam20 = sjv_newcount;
            sjt_parent14 = item;
            sjt_functionParam22 = i;
            sjf_string_getat(sjt_parent14, sjt_functionParam22, &sjt_functionParam21);
            sjf_array_char_initat(sjt_parent13, sjt_functionParam20, sjt_functionParam21);
            sjt_math17 = sjv_newcount;
            sjt_math18 = 1;
            sjv_newcount = sjt_math17 + sjt_math18;
            i++;
        }

        sjt_parent15 = &sjv_newdata;
        sjt_functionParam23 = sjv_newcount;
        sjt_cast2 = 0;
        sjt_functionParam24 = (char)sjt_cast2;
        sjf_array_char_initat(sjt_parent15, sjt_functionParam23, sjt_functionParam24);
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
    sjs_array_char* sjt_parent5 = 0;

    sjt_dot11 = _parent;
    sjt_parent5 = &(sjt_dot11)->data;
    sjt_functionParam9 = index;
    sjf_array_char_getat(sjt_parent5, sjt_functionParam9, _return);
}

void sjf_string_heap(sjs_string* _this) {
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
    sjv_c = (sjs_class*)malloc(sizeof(sjs_class));
    sjv_c->_refCount = 1;
    sjv_c->x = 1;
    sjf_class_heap(sjv_c);
    sjv_d = (sjs_class*)malloc(sizeof(sjs_class));
    sjv_d->_refCount = 1;
    sjv_d->x = 2;
    sjf_class_heap(sjv_d);
    sjv_a._refCount = 1;
    sjv_a.datasize = 2;
    sjv_a.data = 0;
    sjv_a._isglobal = false;
    sjv_a.count = 0;
    sjf_array_weak_class(&sjv_a);
    sjs_array_weak_class* array1;
    array1 = &sjv_a;
    sjt_parent1 = array1;
    sjt_functionParam1 = 0;
    sjt_functionParam2 = sjv_c;
    delete_cb weakptrcb5 = { &sjt_functionParam2, weakptr_clear };
    if (sjt_functionParam2 != 0) { weakptr_cb_add(sjt_functionParam2, weakptrcb5); }
    sjf_array_weak_class_initat(sjt_parent1, sjt_functionParam1, sjt_functionParam2);
    sjt_parent2 = array1;
    sjt_functionParam3 = 1;
    sjt_functionParam4 = sjv_d;
    delete_cb weakptrcb6 = { &sjt_functionParam4, weakptr_clear };
    if (sjt_functionParam4 != 0) { weakptr_cb_add(sjt_functionParam4, weakptrcb6); }
    sjf_array_weak_class_initat(sjt_parent2, sjt_functionParam3, sjt_functionParam4);
    sjt_parent24 = &sjv_a;
    sjt_call12._refCount = 1;
    sjt_call12.count = 2;
    sjt_call12.data._refCount = 1;
    sjt_call12.data.datasize = 3;
    sjt_call12.data.data = (void*)sjg_string1;
    sjt_call12.data._isglobal = true;
    sjt_call12.data.count = 3;
    sjf_array_char(&sjt_call12.data);
    sjf_string(&sjt_call12);
    sjt_functionParam39 = &sjt_call12;
    sjf_array_weak_class_asstring(sjt_parent24, sjt_functionParam39, &sjt_call1);
    sjt_functionParam5 = &sjt_call1;
    sjf_debug_writeline(sjt_functionParam5);
    sjv_c->_refCount--;
    if (sjv_c->_refCount <= 0) {
        weakptr_release(sjv_c);
        sjf_class_destroy(sjv_c);
        free(sjv_c);
    }

    sjv_c = (sjs_class*)malloc(sizeof(sjs_class));
    sjv_c->_refCount = 1;
    sjv_c->x = 3;
    sjf_class_heap(sjv_c);
    sjt_parent25 = &sjv_a;
    sjt_call14._refCount = 1;
    sjt_call14.count = 2;
    sjt_call14.data._refCount = 1;
    sjt_call14.data.datasize = 3;
    sjt_call14.data.data = (void*)sjg_string1;
    sjt_call14.data._isglobal = true;
    sjt_call14.data.count = 3;
    sjf_array_char(&sjt_call14.data);
    sjf_string(&sjt_call14);
    sjt_functionParam41 = &sjt_call14;
    sjf_array_weak_class_asstring(sjt_parent25, sjt_functionParam41, &sjt_call13);
    sjt_functionParam40 = &sjt_call13;
    sjf_debug_writeline(sjt_functionParam40);
    sjv_d->_refCount--;
    if (sjv_d->_refCount <= 0) {
        weakptr_release(sjv_d);
        sjf_class_destroy(sjv_d);
        free(sjv_d);
    }

    sjv_d = (sjs_class*)malloc(sizeof(sjs_class));
    sjv_d->_refCount = 1;
    sjv_d->x = 4;
    sjf_class_heap(sjv_d);
    sjt_parent26 = &sjv_a;
    sjt_call16._refCount = 1;
    sjt_call16.count = 2;
    sjt_call16.data._refCount = 1;
    sjt_call16.data.datasize = 3;
    sjt_call16.data.data = (void*)sjg_string1;
    sjt_call16.data._isglobal = true;
    sjt_call16.data.count = 3;
    sjf_array_char(&sjt_call16.data);
    sjf_string(&sjt_call16);
    sjt_functionParam43 = &sjt_call16;
    sjf_array_weak_class_asstring(sjt_parent26, sjt_functionParam43, &sjt_call15);
    sjt_functionParam42 = &sjt_call15;
    sjf_debug_writeline(sjt_functionParam42);
    main_destroy();
    #ifdef _DEBUG
    printf("\npress return to end\n");
    getchar();
    #endif
    return 0;
}

void main_destroy() {

    delete_cb weakptrcb16 = { &sjt_functionParam2, weakptr_clear };
    if (sjt_functionParam2 != 0) { weakptr_cb_remove(sjt_functionParam2, weakptrcb16); }
    delete_cb weakptrcb17 = { &sjt_functionParam4, weakptr_clear };
    if (sjt_functionParam4 != 0) { weakptr_cb_remove(sjt_functionParam4, weakptrcb17); }
    sjv_c->_refCount--;
    if (sjv_c->_refCount <= 0) {
        weakptr_release(sjv_c);
        sjf_class_destroy(sjv_c);
        free(sjv_c);
    }
    sjv_d->_refCount--;
    if (sjv_d->_refCount <= 0) {
        weakptr_release(sjv_d);
        sjf_class_destroy(sjv_d);
        free(sjv_d);
    }
    if (sjt_call1._refCount == 1) { sjf_string_destroy(&sjt_call1); }
    if (sjt_call12._refCount == 1) { sjf_string_destroy(&sjt_call12); }
    if (sjt_call13._refCount == 1) { sjf_string_destroy(&sjt_call13); }
    if (sjt_call14._refCount == 1) { sjf_string_destroy(&sjt_call14); }
    if (sjt_call15._refCount == 1) { sjf_string_destroy(&sjt_call15); }
    if (sjt_call16._refCount == 1) { sjf_string_destroy(&sjt_call16); }
    if (sjv_a._refCount == 1) { sjf_array_weak_class_destroy(&sjv_a); }
}
