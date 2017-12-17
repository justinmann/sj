#include <stdarg.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

const char* sjg_string1 = ", ";
const char* sjg_string3 = "";
const char* sjg_string4 = "c";

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
#define sjs_anon1_typeId 2
#define sjs_anon1_heap_typeId 3
#define sjs_class_typeId 4
#define sjs_class_heap_typeId 5
#define sjs_array_class_typeId 6
#define sjs_array_class_heap_typeId 7
#define sjs_array_char_typeId 8
#define sjs_array_char_heap_typeId 9
#define sjs_string_typeId 10
#define sjs_string_heap_typeId 11
#define cb_class_class_i32_typeId 12
#define cb_class_class_i32_heap_typeId 13

typedef struct td_sjs_object sjs_object;
typedef struct td_sjs_anon1 sjs_anon1;
typedef struct td_sjs_anon1_heap sjs_anon1_heap;
typedef struct td_sjs_class sjs_class;
typedef struct td_sjs_class_heap sjs_class_heap;
typedef struct td_sjs_array_class sjs_array_class;
typedef struct td_sjs_array_class_heap sjs_array_class_heap;
typedef struct td_sjs_array_char sjs_array_char;
typedef struct td_sjs_array_char_heap sjs_array_char_heap;
typedef struct td_sjs_string sjs_string;
typedef struct td_sjs_string_heap sjs_string_heap;
typedef struct td_cb_class_class_i32 cb_class_class_i32;
typedef struct td_cb_class_class_i32_heap cb_class_class_i32_heap;

struct td_sjs_object {
    intptr_t _refCount;
};

struct td_sjs_anon1 {
    int structsNeedAValue;
};

struct td_sjs_anon1_heap {
    intptr_t _refCount;
};

struct td_sjs_class {
    int32_t x;
};

struct td_sjs_class_heap {
    intptr_t _refCount;
    int32_t x;
};

struct td_sjs_array_class {
    int32_t datasize;
    void* data;
    bool _isglobal;
    int32_t count;
};

struct td_sjs_array_class_heap {
    intptr_t _refCount;
    int32_t datasize;
    void* data;
    bool _isglobal;
    int32_t count;
};

struct td_sjs_array_char {
    int32_t datasize;
    void* data;
    bool _isglobal;
    int32_t count;
};

struct td_sjs_array_char_heap {
    intptr_t _refCount;
    int32_t datasize;
    void* data;
    bool _isglobal;
    int32_t count;
};

struct td_sjs_string {
    int32_t count;
    sjs_array_char data;
};

struct td_sjs_string_heap {
    intptr_t _refCount;
    int32_t count;
    sjs_array_char data;
};

struct td_cb_class_class_i32 {
    void* _parent;
    void (*_cb)(void* _parent, sjs_class*, sjs_class*, int32_t* _return);
};

struct td_cb_class_class_i32_heap {
    cb_class_class_i32 inner;
    void (*_destroy)(void*);
};

void halt(const char * format, ...);
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
#define KHASH_INIT(name, khkey_t, khval_t, kh_is_map, __hash_func, __hash_equal) \
typedef struct {                                                    \
khint_t n_buckets, size, n_occupied, upper_bound;               \
uint32_t *flags;                                                \
khkey_t *keys;                                                  \
khval_t *vals;                                                  \
} kh_##name##_t;                                                    \
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
k = __hash_func(key); i = k % h->n_buckets;                 \
inc = 1 + k % (h->n_buckets - 1); last = i;                 \
while (!__ac_isempty(h->flags, i) && (__ac_isdel(h->flags, i) || !__hash_equal(h->keys[i], key))) { \
if (i + inc >= h->n_buckets) i = i + inc - h->n_buckets; \
else i += inc;                                          \
if (i == last) return h->n_buckets;                     \
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
k = __hash_func(key);                           \
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
x = site = h->n_buckets; k = __hash_func(key); i = k % h->n_buckets; \
if (__ac_isempty(h->flags, i)) x = i;                       \
else {                                                      \
inc = 1 + k % (h->n_buckets - 1); last = i;             \
while (!__ac_isempty(h->flags, i) && (__ac_isdel(h->flags, i) || !__hash_equal(h->keys[i], key))) { \
if (__ac_isdel(h->flags, i)) site = i;              \
if (i + inc >= h->n_buckets) i = i + inc - h->n_buckets; \
else i += inc;                                      \
if (i == last) { x = site; break; }                 \
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
uint32_t void_hash(void* p);
int void_equal(void *p1, void* p2);
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
sjs_class sjt_call1;
sjs_string sjt_call11;
sjs_string sjt_call19;
sjs_class sjt_call2;
sjs_string sjt_call21;
sjs_string sjt_call22;
sjs_string sjt_call28;
sjs_string sjt_call29;
sjs_class sjt_call3;
sjs_class sjt_call4;
sjs_class sjt_call5;
int32_t sjt_functionParam1;
sjs_class* sjt_functionParam10;
sjs_string* sjt_functionParam100;
sjs_class* sjt_functionParam2;
int32_t sjt_functionParam3;
sjs_string* sjt_functionParam32;
sjs_class* sjt_functionParam4;
int32_t sjt_functionParam5;
sjs_string* sjt_functionParam59;
sjs_class* sjt_functionParam6;
sjs_string* sjt_functionParam66;
sjs_string* sjt_functionParam67;
int32_t sjt_functionParam7;
sjs_class* sjt_functionParam8;
int32_t sjt_functionParam9;
cb_class_class_i32 sjt_functionParam96;
sjs_string* sjt_functionParam99;
int32_t sjt_math1;
int32_t sjt_math2;
int32_t sjt_negate1;
sjs_array_class* sjt_parent1;
sjs_array_class* sjt_parent10;
sjs_anon1* sjt_parent11;
sjs_array_class* sjt_parent2;
sjs_array_class* sjt_parent29;
sjs_array_class* sjt_parent3;
sjs_array_class* sjt_parent30;
sjs_anon1* sjt_parent31;
sjs_array_class* sjt_parent32;
sjs_array_class* sjt_parent33;
sjs_anon1* sjt_parent34;
sjs_array_class* sjt_parent35;
sjs_array_class* sjt_parent4;
sjs_array_class* sjt_parent5;
sjs_array_class sjv_a;
sjs_anon1 sjv_console;
void* sjv_emptystringdata;
float sjv_f32_pi;
int32_t sjv_i32_maxvalue;
int32_t sjv_i32_minvalue;
uint32_t sjv_u32_maxvalue;

void sjf_anon1(sjs_anon1* _this);
void sjf_anon1_copy(sjs_anon1* _this, sjs_anon1* _from);
void sjf_anon1_destroy(sjs_anon1* _this);
void sjf_anon1_heap(sjs_anon1_heap* _this);
void sjf_anon1_writeline(sjs_anon1* _parent, sjs_string* data);
void sjf_array_char(sjs_array_char* _this);
void sjf_array_char_copy(sjs_array_char* _this, sjs_array_char* _from);
void sjf_array_char_destroy(sjs_array_char* _this);
void sjf_array_char_getat(sjs_array_char* _parent, int32_t index, char* _return);
void sjf_array_char_grow(sjs_array_char* _parent, int32_t newsize, sjs_array_char* _return);
void sjf_array_char_grow_heap(sjs_array_char* _parent, int32_t newsize, sjs_array_char_heap** _return);
void sjf_array_char_heap(sjs_array_char_heap* _this);
void sjf_array_char_initat(sjs_array_char* _parent, int32_t index, char item);
void sjf_array_char_setat(sjs_array_char* _parent, int32_t index, char item);
void sjf_array_class(sjs_array_class* _this);
void sjf_array_class__quicksort(sjs_array_class* _parent, int32_t left, int32_t right);
void sjf_array_class__quicksortcallback(sjs_array_class* _parent, int32_t left, int32_t right, cb_class_class_i32 cb);
void sjf_array_class_copy(sjs_array_class* _this, sjs_array_class* _from);
void sjf_array_class_destroy(sjs_array_class* _this);
void sjf_array_class_getat(sjs_array_class* _parent, int32_t index, sjs_class* _return);
void sjf_array_class_heap(sjs_array_class_heap* _this);
void sjf_array_class_initat(sjs_array_class* _parent, int32_t index, sjs_class* item);
void sjf_array_class_reverse(sjs_array_class* _parent);
void sjf_array_class_setat(sjs_array_class* _parent, int32_t index, sjs_class* item);
void sjf_array_class_sort(sjs_array_class* _parent);
void sjf_array_class_sortcb(sjs_array_class* _parent, cb_class_class_i32 cb);
void sjf_array_class_tostring(sjs_array_class* _parent, sjs_string* sep, sjs_string* _return);
void sjf_class(sjs_class* _this);
void sjf_class_compare(sjs_class* l, sjs_class* r, int32_t* _return);
void sjf_class_compare_callback(void * _parent, sjs_class* l, sjs_class* r, int32_t* _return);
void sjf_class_copy(sjs_class* _this, sjs_class* _from);
void sjf_class_destroy(sjs_class* _this);
void sjf_class_heap(sjs_class_heap* _this);
void sjf_class_isgreater(sjs_class* _parent, sjs_class* c, bool* _return);
void sjf_class_isless(sjs_class* _parent, sjs_class* c, bool* _return);
void sjf_class_tostring(sjs_class* _parent, sjs_string* _return);
void sjf_i32_compare(int32_t l, int32_t r, int32_t* _return);
void sjf_i32_tostring(int32_t val, int32_t base, int32_t minlength, sjs_string* _return);
void sjf_i32_tostring_heap(int32_t val, int32_t base, int32_t minlength, sjs_string_heap** _return);
void sjf_string(sjs_string* _this);
void sjf_string_add(sjs_string* _parent, sjs_string* item, sjs_string* _return);
void sjf_string_add_heap(sjs_string* _parent, sjs_string* item, sjs_string_heap** _return);
void sjf_string_copy(sjs_string* _this, sjs_string* _from);
void sjf_string_destroy(sjs_string* _this);
void sjf_string_getat(sjs_string* _parent, int32_t index, char* _return);
void sjf_string_heap(sjs_string_heap* _this);
void main_destroy(void);

void halt(const char * format, ...) {
    va_list args;
    va_start (args, format);
    vprintf (format, args);
    va_end (args);
    exit(-1);
}
uint32_t void_hash(void* p) {
    return kh_int_hash_func((uintptr_t)p);
}
int void_equal(void *p1, void* p2) {
    return (p1 == p2);
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
KHASH_INIT(weakptr_hash_type, void*, delete_cb_list, 1, void_hash, void_equal)
khash_t(weakptr_hash_type)* weakptr_hash;
void weakptr_init() {
    weakptr_hash = kh_init(weakptr_hash_type);
}
void weakptr_release(void* v) {
    khiter_t k = kh_get(weakptr_hash_type, weakptr_hash, v);
    if (k != kh_end(weakptr_hash)) {
        delete_cb_list* d = &kh_value(weakptr_hash, k);
        delete_cb_list_invoke(d, v);
        if (d->next) {
            delete_cb_list_free(d->next);
        }
        kh_del(weakptr_hash_type, weakptr_hash, k);
    }
}
void weakptr_cb_add(void* v, delete_cb cb) {
    delete_cb_list* d;
    khiter_t k = kh_get(weakptr_hash_type, weakptr_hash, v);
    if (k == kh_end(weakptr_hash)) {
        int ret;
        khiter_t k = kh_put(weakptr_hash_type, weakptr_hash, v, &ret);
        if (!ret) kh_del(weakptr_hash_type, weakptr_hash, k);
        d = &kh_value(weakptr_hash, k);
        d->size = 0;
        d->next = 0;
    }
    else {
        d = &kh_value(weakptr_hash, k);
    }
    delete_cb_list_add(d, cb);
}
void weakptr_cb_remove(void* v, delete_cb cb) {
    khiter_t k = kh_get(weakptr_hash_type, weakptr_hash, v);
    if (k != kh_end(weakptr_hash)) {
        delete_cb_list* d = &kh_value(weakptr_hash, k);
        delete_cb_list_remove(d, cb);
    }
}
KHASH_INIT(ptr_hash_type, void*, int, 1, void_hash, void_equal)
khash_t(ptr_hash_type)* ptr_hash;
void ptr_init() {
    ptr_hash = kh_init(ptr_hash_type);
}
void ptr_retain(void* v) {
    khiter_t k = kh_get(ptr_hash_type, ptr_hash, v);
    if (k == kh_end(ptr_hash)) {
        int ret;
        khiter_t k = kh_put(ptr_hash_type, ptr_hash, v, &ret);
        if (!ret) kh_del(ptr_hash_type, ptr_hash, k);
        kh_value(ptr_hash, k) = 1;
    }
    else {
        kh_value(ptr_hash, k)++;
    }
}
bool ptr_release(void* v) {
    khiter_t k = kh_get(ptr_hash_type, ptr_hash, v);
    if (k != kh_end(ptr_hash)) {
        kh_value(ptr_hash, k)--;
        if (kh_value(ptr_hash, k) == 0) {
            kh_del(ptr_hash_type, ptr_hash, k);
        }
        return false;
    }
    return true;
}
void sjf_anon1(sjs_anon1* _this) {
}

void sjf_anon1_copy(sjs_anon1* _this, sjs_anon1* _from) {
}

void sjf_anon1_destroy(sjs_anon1* _this) {
}

void sjf_anon1_heap(sjs_anon1_heap* _this) {
}

void sjf_anon1_writeline(sjs_anon1* _parent, sjs_string* data) {
#line 14 "lib/common/console.sj"
    printf("%s\n", (char*)data->data.data);
}

void sjf_array_char(sjs_array_char* _this) {
#line 267 "lib/common/array.sj"
    if (_this->datasize < 0) {
#line 268
        halt("size is less than zero");
#line 269
    }
#line 271
    if (!_this->data) {
#line 272
        _this->data = malloc(_this->datasize * sizeof(char));
#line 273
        if (!_this->data) {
#line 274
            halt("grow: out of memory\n");
#line 275
        }
#line 276
    }
}

void sjf_array_char_copy(sjs_array_char* _this, sjs_array_char* _from) {
#line 1 "lib/common/array.sj"
    _this->datasize = _from->datasize;
#line 1
    _this->data = _from->data;
#line 1
    _this->_isglobal = _from->_isglobal;
#line 1
    _this->count = _from->count;
#line 281
    _this->data = _from->data;
#line 282
    if (!_this->_isglobal && _this->data) {
#line 283
        ptr_retain(_this->data);
#line 284
    }
}

void sjf_array_char_destroy(sjs_array_char* _this) {
#line 288 "lib/common/array.sj"
    if (!_this->_isglobal && _this->data) {
#line 289
        if (ptr_release(_this->data)) {
#line 290
            free((char*)_this->data);
#line 291
        }
#line 292
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
;		
}

void sjf_array_char_grow(sjs_array_char* _parent, int32_t newsize, sjs_array_char* _return) {
    sjs_array_char* sjt_dot11;
    void* sjv_newdata;

#line 116 "lib/common/array.sj"
    sjv_newdata = 0;
#line 118
    if (_parent->datasize != newsize) {
#line 119
        if (newsize < _parent->datasize) {
#line 120
            halt("grow: new size smaller than old _parent->datasize %d:%d\n", newsize, _parent->datasize);
#line 121
        }
#line 123
        sjv_newdata = malloc(newsize * sizeof(char));
#line 124
        if (!_parent->data) {
#line 125
            halt("grow: out of memory\n");
#line 126
        }
#line 127
        memcpy(sjv_newdata, _parent->data, _parent->datasize * sizeof(char));
#line 128
    }
#line 115
    _return->datasize = newsize;
#line 130
    _return->data = sjv_newdata;
#line 4
    _return->_isglobal = false;
#line 115
    sjt_dot11 = _parent;
#line 130
    _return->count = (sjt_dot11)->count;
#line 130
    sjf_array_char(_return);
}

void sjf_array_char_grow_heap(sjs_array_char* _parent, int32_t newsize, sjs_array_char_heap** _return) {
    sjs_array_char* sjt_dot12;
    void* sjv_newdata;

#line 116 "lib/common/array.sj"
    sjv_newdata = 0;
#line 118
    if (_parent->datasize != newsize) {
#line 119
        if (newsize < _parent->datasize) {
#line 120
            halt("grow: new size smaller than old _parent->datasize %d:%d\n", newsize, _parent->datasize);
#line 121
        }
#line 123
        sjv_newdata = malloc(newsize * sizeof(char));
#line 124
        if (!_parent->data) {
#line 125
            halt("grow: out of memory\n");
#line 126
        }
#line 127
        memcpy(sjv_newdata, _parent->data, _parent->datasize * sizeof(char));
#line 128
    }
#line 128
    (*_return) = (sjs_array_char_heap*)malloc(sizeof(sjs_array_char_heap));
#line 128
    (*_return)->_refCount = 1;
#line 115
    (*_return)->datasize = newsize;
#line 130
    (*_return)->data = sjv_newdata;
#line 4
    (*_return)->_isglobal = false;
#line 115
    sjt_dot12 = _parent;
#line 130
    (*_return)->count = (sjt_dot12)->count;
#line 130
    sjf_array_char_heap((*_return));
}

void sjf_array_char_heap(sjs_array_char_heap* _this) {
#line 267 "lib/common/array.sj"
    if (_this->datasize < 0) {
#line 268
        halt("size is less than zero");
#line 269
    }
#line 271
    if (!_this->data) {
#line 272
        _this->data = malloc(_this->datasize * sizeof(char));
#line 273
        if (!_this->data) {
#line 274
            halt("grow: out of memory\n");
#line 275
        }
#line 276
    }
}

void sjf_array_char_initat(sjs_array_char* _parent, int32_t index, char item) {
#line 21 "lib/common/array.sj"
    if (index != _parent->count) {
#line 22
        halt("initAt: can only initialize last element\n");		
#line 23
    }
#line 24
    if (index >= _parent->datasize || index < 0) {
#line 25
        halt("initAt: out of bounds %d:%d\n", index, _parent->datasize);
#line 26
    }
#line 28
    char* p = (char*)_parent->data;
#line 29
    #line 19 "lib/common/array.sj"
p[index] = item;
;
#line 30
    _parent->count = index + 1;
}

void sjf_array_char_setat(sjs_array_char* _parent, int32_t index, char item) {
#line 36 "lib/common/array.sj"
    if (index >= _parent->count || index < 0) {
#line 37
        halt("setAt: out of bounds %d:%d\n", index, _parent->count);
#line 38
    }
#line 40
    char* p = (char*)_parent->data;
#line 41
    ;
#line 42
    #line 34 "lib/common/array.sj"
p[index] = item;
;
}

void sjf_array_class(sjs_array_class* _this) {
#line 267 "lib/common/array.sj"
    if (_this->datasize < 0) {
#line 268
        halt("size is less than zero");
#line 269
    }
#line 271
    if (!_this->data) {
#line 272
        _this->data = malloc(_this->datasize * sizeof(sjs_class));
#line 273
        if (!_this->data) {
#line 274
            halt("grow: out of memory\n");
#line 275
        }
#line 276
    }
}

void sjf_array_class__quicksort(sjs_array_class* _parent, int32_t left, int32_t right) {
    int32_t sjt_compare13;
    int32_t sjt_compare14;
    int32_t sjt_compare15;
    int32_t sjt_compare16;
    int32_t sjt_compare3;
    int32_t sjt_compare4;
    int32_t sjt_functionParam11;
    bool sjt_ifElse3;
    bool sjt_ifElse4;
    int32_t sjt_math3;
    int32_t sjt_math4;
    int32_t sjt_math5;
    int32_t sjt_math6;
    bool sjt_while1;
    int32_t sjv_i;
    int32_t sjv_j;
    sjs_class sjv_pivot;

#line 133 "lib/common/array.sj"
    sjv_i = left;
#line 133
    sjv_j = right;
#line 133
    sjt_math5 = left;
#line 133
    sjt_math6 = right;
#line 137
    sjt_math3 = sjt_math5 + sjt_math6;
#line 137
    sjt_math4 = 2;
#line 137
    sjt_functionParam11 = sjt_math3 / sjt_math4;
#line 137
    sjf_array_class_getat(_parent, sjt_functionParam11, &sjv_pivot);
#line 138
    sjt_compare3 = sjv_i;
#line 138
    sjt_compare4 = sjv_j;
#line 138
    sjt_while1 = sjt_compare3 <= sjt_compare4;
    while (sjt_while1) {
        sjs_class sjt_call6;
        sjs_class sjt_call8;
        int32_t sjt_compare10;
        int32_t sjt_compare11;
        int32_t sjt_compare12;
        int32_t sjt_compare9;
        int32_t sjt_functionParam12;
        sjs_class* sjt_functionParam13;
        int32_t sjt_functionParam16;
        sjs_class* sjt_functionParam17;
        bool sjt_ifElse2;
        sjs_class* sjt_parent6;
        sjs_class* sjt_parent8;
        bool sjt_while2;
        bool sjt_while3;

#line 139 "lib/common/array.sj"
        sjt_functionParam12 = sjv_i;
#line 139
        sjf_array_class_getat(_parent, sjt_functionParam12, &sjt_call6);
#line 139
        sjt_parent6 = &sjt_call6;
#line 139
        sjt_functionParam13 = &sjv_pivot;
#line 139
        sjf_class_isless(sjt_parent6, sjt_functionParam13, &sjt_while2);
        while (sjt_while2) {
            sjs_class sjt_call7;
            int32_t sjt_functionParam14;
            sjs_class* sjt_functionParam15;
            int32_t sjt_math7;
            int32_t sjt_math8;
            sjs_class* sjt_parent7;

#line 140 "lib/common/array.sj"
            sjt_math7 = sjv_i;
#line 140
            sjt_math8 = 1;
#line 140
            sjv_i = sjt_math7 + sjt_math8;
#line 139
            sjt_functionParam14 = sjv_i;
#line 139
            sjf_array_class_getat(_parent, sjt_functionParam14, &sjt_call7);
#line 139
            sjt_parent7 = &sjt_call7;
#line 139
            sjt_functionParam15 = &sjv_pivot;
#line 139
            sjf_class_isless(sjt_parent7, sjt_functionParam15, &sjt_while2);

            sjf_class_destroy(&sjt_call7);
        }

#line 143
        sjt_functionParam16 = sjv_j;
#line 143
        sjf_array_class_getat(_parent, sjt_functionParam16, &sjt_call8);
#line 143
        sjt_parent8 = &sjt_call8;
#line 143
        sjt_functionParam17 = &sjv_pivot;
#line 143
        sjf_class_isgreater(sjt_parent8, sjt_functionParam17, &sjt_while3);
        while (sjt_while3) {
            sjs_class sjt_call9;
            int32_t sjt_functionParam18;
            sjs_class* sjt_functionParam19;
            int32_t sjt_math10;
            int32_t sjt_math9;
            sjs_class* sjt_parent9;

#line 144 "lib/common/array.sj"
            sjt_math9 = sjv_j;
#line 144
            sjt_math10 = 1;
#line 144
            sjv_j = sjt_math9 - sjt_math10;
#line 143
            sjt_functionParam18 = sjv_j;
#line 143
            sjf_array_class_getat(_parent, sjt_functionParam18, &sjt_call9);
#line 143
            sjt_parent9 = &sjt_call9;
#line 143
            sjt_functionParam19 = &sjv_pivot;
#line 143
            sjf_class_isgreater(sjt_parent9, sjt_functionParam19, &sjt_while3);

            sjf_class_destroy(&sjt_call9);
        }

#line 147
        sjt_compare9 = sjv_i;
#line 147
        sjt_compare10 = sjv_j;
#line 147
        sjt_ifElse2 = sjt_compare9 <= sjt_compare10;
        if (sjt_ifElse2) {
            sjs_class sjt_call10;
            int32_t sjt_functionParam20;
            int32_t sjt_functionParam21;
            sjs_class* sjt_functionParam22;
            int32_t sjt_functionParam23;
            int32_t sjt_functionParam24;
            sjs_class* sjt_functionParam25;
            int32_t sjt_math11;
            int32_t sjt_math12;
            int32_t sjt_math13;
            int32_t sjt_math14;
            sjs_class sjv_tmp;

#line 148 "lib/common/array.sj"
            sjt_functionParam20 = sjv_i;
#line 148
            sjf_array_class_getat(_parent, sjt_functionParam20, &sjv_tmp);
#line 149
            sjt_functionParam21 = sjv_i;
#line 149
            sjt_functionParam23 = sjv_j;
#line 149
            sjf_array_class_getat(_parent, sjt_functionParam23, &sjt_call10);
#line 149
            sjt_functionParam22 = &sjt_call10;
#line 149
            sjf_array_class_setat(_parent, sjt_functionParam21, sjt_functionParam22);
#line 150
            sjt_functionParam24 = sjv_j;
#line 150
            sjt_functionParam25 = &sjv_tmp;
#line 150
            sjf_array_class_setat(_parent, sjt_functionParam24, sjt_functionParam25);
#line 151
            sjt_math11 = sjv_i;
#line 151
            sjt_math12 = 1;
#line 151
            sjv_i = sjt_math11 + sjt_math12;
#line 152
            sjt_math13 = sjv_j;
#line 152
            sjt_math14 = 1;
#line 152
            sjv_j = sjt_math13 - sjt_math14;

            sjf_class_destroy(&sjt_call10);
            sjf_class_destroy(&sjv_tmp);
        }

#line 138
        sjt_compare11 = sjv_i;
#line 138
        sjt_compare12 = sjv_j;
#line 138
        sjt_while1 = sjt_compare11 <= sjt_compare12;

        sjf_class_destroy(&sjt_call6);
        sjf_class_destroy(&sjt_call8);
    }

#line 133
    sjt_compare13 = left;
#line 156
    sjt_compare14 = sjv_j;
#line 156
    sjt_ifElse3 = sjt_compare13 < sjt_compare14;
    if (sjt_ifElse3) {
        int32_t sjt_functionParam26;
        int32_t sjt_functionParam27;

#line 133 "lib/common/array.sj"
        sjt_functionParam26 = left;
#line 157
        sjt_functionParam27 = sjv_j;
#line 157
        sjf_array_class__quicksort(_parent, sjt_functionParam26, sjt_functionParam27);
    }

#line 159
    sjt_compare15 = sjv_i;
#line 133
    sjt_compare16 = right;
#line 159
    sjt_ifElse4 = sjt_compare15 < sjt_compare16;
    if (sjt_ifElse4) {
        int32_t sjt_functionParam28;
        int32_t sjt_functionParam29;

#line 160 "lib/common/array.sj"
        sjt_functionParam28 = sjv_i;
#line 133
        sjt_functionParam29 = right;
#line 133
        sjf_array_class__quicksort(_parent, sjt_functionParam28, sjt_functionParam29);
    }

    sjf_class_destroy(&sjv_pivot);
}

void sjf_array_class__quicksortcallback(sjs_array_class* _parent, int32_t left, int32_t right, cb_class_class_i32 cb) {
    int32_t sjt_compare25;
    int32_t sjt_compare26;
    int32_t sjt_compare39;
    int32_t sjt_compare40;
    int32_t sjt_compare41;
    int32_t sjt_compare42;
    int32_t sjt_functionParam68;
    bool sjt_ifElse10;
    bool sjt_ifElse11;
    int32_t sjt_math47;
    int32_t sjt_math48;
    int32_t sjt_math49;
    int32_t sjt_math50;
    bool sjt_while4;
    int32_t sjv_i;
    int32_t sjv_j;
    sjs_class sjv_pivot;

#line 164 "lib/common/array.sj"
    sjv_i = left;
#line 164
    sjv_j = right;
#line 164
    sjt_math49 = left;
#line 164
    sjt_math50 = right;
#line 168
    sjt_math47 = sjt_math49 + sjt_math50;
#line 168
    sjt_math48 = 2;
#line 168
    sjt_functionParam68 = sjt_math47 / sjt_math48;
#line 168
    sjf_array_class_getat(_parent, sjt_functionParam68, &sjv_pivot);
#line 169
    sjt_compare25 = sjv_i;
#line 169
    sjt_compare26 = sjv_j;
#line 169
    sjt_while4 = sjt_compare25 <= sjt_compare26;
    while (sjt_while4) {
        sjs_class sjt_call23;
        sjs_class sjt_call25;
        cb_class_class_i32 sjt_callback1;
        cb_class_class_i32 sjt_callback3;
        int32_t sjt_compare27;
        int32_t sjt_compare28;
        int32_t sjt_compare31;
        int32_t sjt_compare32;
        int32_t sjt_compare35;
        int32_t sjt_compare36;
        int32_t sjt_compare37;
        int32_t sjt_compare38;
        sjs_class* sjt_functionParam69;
        int32_t sjt_functionParam70;
        sjs_class* sjt_functionParam71;
        sjs_class* sjt_functionParam75;
        int32_t sjt_functionParam76;
        sjs_class* sjt_functionParam77;
        bool sjt_ifElse9;
        bool sjt_while5;
        bool sjt_while6;

#line 164 "lib/common/array.sj"
        sjt_callback1 = cb;
#line 170
        sjt_functionParam70 = sjv_i;
#line 170
        sjf_array_class_getat(_parent, sjt_functionParam70, &sjt_call23);
#line 170
        sjt_functionParam69 = &sjt_call23;
#line 170
        sjt_functionParam71 = &sjv_pivot;
#line 170
        sjt_callback1._cb(sjt_callback1._parent, sjt_functionParam69, sjt_functionParam71, &sjt_compare27);
#line 170
        sjt_compare28 = 0;
#line 170
        sjt_while5 = sjt_compare27 < sjt_compare28;
        while (sjt_while5) {
            sjs_class sjt_call24;
            cb_class_class_i32 sjt_callback2;
            int32_t sjt_compare29;
            int32_t sjt_compare30;
            sjs_class* sjt_functionParam72;
            int32_t sjt_functionParam73;
            sjs_class* sjt_functionParam74;
            int32_t sjt_math51;
            int32_t sjt_math52;

#line 171 "lib/common/array.sj"
            sjt_math51 = sjv_i;
#line 171
            sjt_math52 = 1;
#line 171
            sjv_i = sjt_math51 + sjt_math52;
#line 164
            sjt_callback2 = cb;
#line 170
            sjt_functionParam73 = sjv_i;
#line 170
            sjf_array_class_getat(_parent, sjt_functionParam73, &sjt_call24);
#line 170
            sjt_functionParam72 = &sjt_call24;
#line 170
            sjt_functionParam74 = &sjv_pivot;
#line 170
            sjt_callback2._cb(sjt_callback2._parent, sjt_functionParam72, sjt_functionParam74, &sjt_compare29);
#line 170
            sjt_compare30 = 0;
#line 170
            sjt_while5 = sjt_compare29 < sjt_compare30;

            sjf_class_destroy(&sjt_call24);
        }

#line 164
        sjt_callback3 = cb;
#line 174
        sjt_functionParam76 = sjv_j;
#line 174
        sjf_array_class_getat(_parent, sjt_functionParam76, &sjt_call25);
#line 174
        sjt_functionParam75 = &sjt_call25;
#line 174
        sjt_functionParam77 = &sjv_pivot;
#line 174
        sjt_callback3._cb(sjt_callback3._parent, sjt_functionParam75, sjt_functionParam77, &sjt_compare31);
#line 174
        sjt_compare32 = 0;
#line 174
        sjt_while6 = sjt_compare31 > sjt_compare32;
        while (sjt_while6) {
            sjs_class sjt_call26;
            cb_class_class_i32 sjt_callback4;
            int32_t sjt_compare33;
            int32_t sjt_compare34;
            sjs_class* sjt_functionParam78;
            int32_t sjt_functionParam79;
            sjs_class* sjt_functionParam80;
            int32_t sjt_math53;
            int32_t sjt_math54;

#line 175 "lib/common/array.sj"
            sjt_math53 = sjv_j;
#line 175
            sjt_math54 = 1;
#line 175
            sjv_j = sjt_math53 - sjt_math54;
#line 164
            sjt_callback4 = cb;
#line 174
            sjt_functionParam79 = sjv_j;
#line 174
            sjf_array_class_getat(_parent, sjt_functionParam79, &sjt_call26);
#line 174
            sjt_functionParam78 = &sjt_call26;
#line 174
            sjt_functionParam80 = &sjv_pivot;
#line 174
            sjt_callback4._cb(sjt_callback4._parent, sjt_functionParam78, sjt_functionParam80, &sjt_compare33);
#line 174
            sjt_compare34 = 0;
#line 174
            sjt_while6 = sjt_compare33 > sjt_compare34;

            sjf_class_destroy(&sjt_call26);
        }

#line 178
        sjt_compare35 = sjv_i;
#line 178
        sjt_compare36 = sjv_j;
#line 178
        sjt_ifElse9 = sjt_compare35 <= sjt_compare36;
        if (sjt_ifElse9) {
            sjs_class sjt_call27;
            int32_t sjt_functionParam81;
            int32_t sjt_functionParam82;
            sjs_class* sjt_functionParam83;
            int32_t sjt_functionParam84;
            int32_t sjt_functionParam85;
            sjs_class* sjt_functionParam86;
            int32_t sjt_math55;
            int32_t sjt_math56;
            int32_t sjt_math57;
            int32_t sjt_math58;
            sjs_class sjv_tmp;

#line 179 "lib/common/array.sj"
            sjt_functionParam81 = sjv_i;
#line 179
            sjf_array_class_getat(_parent, sjt_functionParam81, &sjv_tmp);
#line 180
            sjt_functionParam82 = sjv_i;
#line 180
            sjt_functionParam84 = sjv_j;
#line 180
            sjf_array_class_getat(_parent, sjt_functionParam84, &sjt_call27);
#line 180
            sjt_functionParam83 = &sjt_call27;
#line 180
            sjf_array_class_setat(_parent, sjt_functionParam82, sjt_functionParam83);
#line 181
            sjt_functionParam85 = sjv_j;
#line 181
            sjt_functionParam86 = &sjv_tmp;
#line 181
            sjf_array_class_setat(_parent, sjt_functionParam85, sjt_functionParam86);
#line 182
            sjt_math55 = sjv_i;
#line 182
            sjt_math56 = 1;
#line 182
            sjv_i = sjt_math55 + sjt_math56;
#line 183
            sjt_math57 = sjv_j;
#line 183
            sjt_math58 = 1;
#line 183
            sjv_j = sjt_math57 - sjt_math58;

            sjf_class_destroy(&sjt_call27);
            sjf_class_destroy(&sjv_tmp);
        }

#line 169
        sjt_compare37 = sjv_i;
#line 169
        sjt_compare38 = sjv_j;
#line 169
        sjt_while4 = sjt_compare37 <= sjt_compare38;

        sjf_class_destroy(&sjt_call23);
        sjf_class_destroy(&sjt_call25);
    }

#line 164
    sjt_compare39 = left;
#line 187
    sjt_compare40 = sjv_j;
#line 187
    sjt_ifElse10 = sjt_compare39 < sjt_compare40;
    if (sjt_ifElse10) {
        int32_t sjt_functionParam87;
        int32_t sjt_functionParam88;
        cb_class_class_i32 sjt_functionParam89;

#line 164 "lib/common/array.sj"
        sjt_functionParam87 = left;
#line 188
        sjt_functionParam88 = sjv_j;
#line 164
        sjt_functionParam89 = cb;
#line 164
        sjf_array_class__quicksortcallback(_parent, sjt_functionParam87, sjt_functionParam88, sjt_functionParam89);
    }

#line 190
    sjt_compare41 = sjv_i;
#line 164
    sjt_compare42 = right;
#line 190
    sjt_ifElse11 = sjt_compare41 < sjt_compare42;
    if (sjt_ifElse11) {
        int32_t sjt_functionParam90;
        int32_t sjt_functionParam91;
        cb_class_class_i32 sjt_functionParam92;

#line 191 "lib/common/array.sj"
        sjt_functionParam90 = sjv_i;
#line 164
        sjt_functionParam91 = right;
#line 164
        sjt_functionParam92 = cb;
#line 164
        sjf_array_class__quicksortcallback(_parent, sjt_functionParam90, sjt_functionParam91, sjt_functionParam92);
    }

    sjf_class_destroy(&sjv_pivot);
}

void sjf_array_class_copy(sjs_array_class* _this, sjs_array_class* _from) {
#line 1 "lib/common/array.sj"
    _this->datasize = _from->datasize;
#line 1
    _this->data = _from->data;
#line 1
    _this->_isglobal = _from->_isglobal;
#line 1
    _this->count = _from->count;
#line 281
    _this->data = _from->data;
#line 282
    if (!_this->_isglobal && _this->data) {
#line 283
        ptr_retain(_this->data);
#line 284
    }
}

void sjf_array_class_destroy(sjs_array_class* _this) {
#line 288 "lib/common/array.sj"
    if (!_this->_isglobal && _this->data) {
#line 289
        if (ptr_release(_this->data)) {
#line 290
            free((sjs_class*)_this->data);
#line 291
        }
#line 292
    }
}

void sjf_array_class_getat(sjs_array_class* _parent, int32_t index, sjs_class* _return) {
#line 9 "lib/common/array.sj"
    if (index >= _parent->count || index < 0) {
#line 10
        halt("getAt: out of bounds\n");
#line 11
    }
#line 13
    sjs_class* p = (sjs_class*)_parent->data;
#line 14
    #line 8 "lib/common/array.sj"
sjf_class_copy(_return, &p[index]);
;		
}

void sjf_array_class_heap(sjs_array_class_heap* _this) {
#line 267 "lib/common/array.sj"
    if (_this->datasize < 0) {
#line 268
        halt("size is less than zero");
#line 269
    }
#line 271
    if (!_this->data) {
#line 272
        _this->data = malloc(_this->datasize * sizeof(sjs_class));
#line 273
        if (!_this->data) {
#line 274
            halt("grow: out of memory\n");
#line 275
        }
#line 276
    }
}

void sjf_array_class_initat(sjs_array_class* _parent, int32_t index, sjs_class* item) {
#line 21 "lib/common/array.sj"
    if (index != _parent->count) {
#line 22
        halt("initAt: can only initialize last element\n");		
#line 23
    }
#line 24
    if (index >= _parent->datasize || index < 0) {
#line 25
        halt("initAt: out of bounds %d:%d\n", index, _parent->datasize);
#line 26
    }
#line 28
    sjs_class* p = (sjs_class*)_parent->data;
#line 29
    #line 19 "lib/common/array.sj"
sjf_class_copy(&p[index], item);
;
#line 30
    _parent->count = index + 1;
}

void sjf_array_class_reverse(sjs_array_class* _parent) {
    int32_t i;
    sjs_array_class* sjt_dot28;
    int32_t sjt_forEnd4;
    int32_t sjt_forStart4;
    int32_t sjt_math41;
    int32_t sjt_math42;

#line 208 "lib/common/array.sj"
    sjt_forStart4 = 0;
#line 207
    sjt_dot28 = _parent;
#line 208
    sjt_math41 = (sjt_dot28)->count;
#line 208
    sjt_math42 = 2;
#line 208
    sjt_forEnd4 = sjt_math41 / sjt_math42;
#line 208
    i = sjt_forStart4;
    while (i < sjt_forEnd4) {
        sjs_class sjt_call20;
        sjs_array_class* sjt_dot29;
        int32_t sjt_functionParam60;
        int32_t sjt_functionParam61;
        sjs_class* sjt_functionParam62;
        int32_t sjt_functionParam63;
        int32_t sjt_functionParam64;
        sjs_class* sjt_functionParam65;
        int32_t sjt_math43;
        int32_t sjt_math44;
        int32_t sjt_math45;
        int32_t sjt_math46;
        int32_t sjv_j;
        sjs_class sjv_tmp;

#line 207 "lib/common/array.sj"
        sjt_dot29 = _parent;
#line 209
        sjt_math45 = (sjt_dot29)->count;
#line 208
        sjt_math46 = i;
#line 209
        sjt_math43 = sjt_math45 - sjt_math46;
#line 209
        sjt_math44 = 1;
#line 209
        sjv_j = sjt_math43 - sjt_math44;
#line 208
        sjt_functionParam60 = i;
#line 208
        sjf_array_class_getat(_parent, sjt_functionParam60, &sjv_tmp);
#line 208
        sjt_functionParam61 = i;
#line 211
        sjt_functionParam63 = sjv_j;
#line 211
        sjf_array_class_getat(_parent, sjt_functionParam63, &sjt_call20);
#line 211
        sjt_functionParam62 = &sjt_call20;
#line 211
        sjf_array_class_setat(_parent, sjt_functionParam61, sjt_functionParam62);
#line 212
        sjt_functionParam64 = sjv_j;
#line 212
        sjt_functionParam65 = &sjv_tmp;
#line 212
        sjf_array_class_setat(_parent, sjt_functionParam64, sjt_functionParam65);
#line 208
        i++;

        sjf_class_destroy(&sjt_call20);
        sjf_class_destroy(&sjv_tmp);
    }
}

void sjf_array_class_setat(sjs_array_class* _parent, int32_t index, sjs_class* item) {
#line 36 "lib/common/array.sj"
    if (index >= _parent->count || index < 0) {
#line 37
        halt("setAt: out of bounds %d:%d\n", index, _parent->count);
#line 38
    }
#line 40
    sjs_class* p = (sjs_class*)_parent->data;
#line 41
    ;
#line 42
    #line 34 "lib/common/array.sj"
sjf_class_copy(&p[index], item);
;
}

void sjf_array_class_sort(sjs_array_class* _parent) {
    int32_t sjt_compare1;
    int32_t sjt_compare2;
    sjs_array_class* sjt_dot1;
    bool sjt_ifElse1;

#line 195 "lib/common/array.sj"
    sjt_dot1 = _parent;
#line 196
    sjt_compare1 = (sjt_dot1)->count;
#line 196
    sjt_compare2 = 1;
#line 196
    sjt_ifElse1 = sjt_compare1 > sjt_compare2;
    if (sjt_ifElse1) {
        sjs_array_class* sjt_dot6;
        int32_t sjt_functionParam30;
        int32_t sjt_functionParam31;
        int32_t sjt_math15;
        int32_t sjt_math16;

#line 197 "lib/common/array.sj"
        sjt_functionParam30 = 0;
#line 195
        sjt_dot6 = _parent;
#line 197
        sjt_math15 = (sjt_dot6)->count;
#line 197
        sjt_math16 = 1;
#line 197
        sjt_functionParam31 = sjt_math15 - sjt_math16;
#line 197
        sjf_array_class__quicksort(_parent, sjt_functionParam30, sjt_functionParam31);
    }
}

void sjf_array_class_sortcb(sjs_array_class* _parent, cb_class_class_i32 cb) {
    int32_t sjt_compare23;
    int32_t sjt_compare24;
    sjs_array_class* sjt_dot30;
    bool sjt_ifElse8;

#line 201 "lib/common/array.sj"
    sjt_dot30 = _parent;
#line 202
    sjt_compare23 = (sjt_dot30)->count;
#line 202
    sjt_compare24 = 1;
#line 202
    sjt_ifElse8 = sjt_compare23 > sjt_compare24;
    if (sjt_ifElse8) {
        sjs_array_class* sjt_dot31;
        int32_t sjt_functionParam93;
        int32_t sjt_functionParam94;
        cb_class_class_i32 sjt_functionParam95;
        int32_t sjt_math59;
        int32_t sjt_math60;

#line 203 "lib/common/array.sj"
        sjt_functionParam93 = 0;
#line 201
        sjt_dot31 = _parent;
#line 203
        sjt_math59 = (sjt_dot31)->count;
#line 203
        sjt_math60 = 1;
#line 203
        sjt_functionParam94 = sjt_math59 - sjt_math60;
#line 201
        sjt_functionParam95 = cb;
#line 201
        sjf_array_class__quicksortcallback(_parent, sjt_functionParam93, sjt_functionParam94, sjt_functionParam95);
    }
}

void sjf_array_class_tostring(sjs_array_class* _parent, sjs_string* sep, sjs_string* _return) {
    int32_t i;
    sjs_string* sjt_copy8;
    sjs_array_class* sjt_dot7;
    int32_t sjt_forEnd1;
    int32_t sjt_forStart1;
    sjs_string sjv_result;

#line 217 "lib/common/array.sj"
    sjv_result.count = 0;
#line 217
    sjv_result.data.datasize = 1;
#line 217
    sjv_result.data.data = (void*)sjg_string3;
#line 217
    sjv_result.data._isglobal = true;
#line 217
    sjv_result.data.count = 1;
#line 217
    sjf_array_char(&sjv_result.data);
#line 217
    sjf_string(&sjv_result);
#line 218
    sjt_forStart1 = 0;
#line 216
    sjt_dot7 = _parent;
#line 218
    sjt_forEnd1 = (sjt_dot7)->count;
#line 218
    i = sjt_forStart1;
    while (i < sjt_forEnd1) {
        sjs_string sjt_call13;
        sjs_string sjt_call14;
        sjs_class sjt_call18;
        int32_t sjt_compare17;
        int32_t sjt_compare18;
        sjs_string* sjt_copy6;
        sjs_string* sjt_functionParam53;
        int32_t sjt_functionParam58;
        bool sjt_ifElse5;
        sjs_string* sjt_parent26;
        sjs_class* sjt_parent28;

#line 218 "lib/common/array.sj"
        sjt_compare17 = i;
#line 219
        sjt_compare18 = 0;
#line 219
        sjt_ifElse5 = sjt_compare17 != sjt_compare18;
        if (sjt_ifElse5) {
            sjs_string sjt_call12;
            sjs_string* sjt_copy1;
            sjs_string* sjt_functionParam52;
            sjs_string* sjt_parent25;

#line 15 "lib/common/string.sj"
            sjt_parent25 = &sjv_result;
#line 216 "lib/common/array.sj"
            sjt_functionParam52 = sep;
#line 216
            sjf_string_add(sjt_parent25, sjt_functionParam52, &sjt_call12);
#line 220
            sjt_copy1 = &sjt_call12;
#line 220
            sjf_string_copy(&sjv_result, sjt_copy1);

            sjf_string_destroy(&sjt_call12);
        }

#line 15 "lib/common/string.sj"
        sjt_parent26 = &sjv_result;
#line 218 "lib/common/array.sj"
        sjt_functionParam58 = i;
#line 218
        sjf_array_class_getat(_parent, sjt_functionParam58, &sjt_call18);
#line 222
        sjt_parent28 = &sjt_call18;
#line 222
        sjf_class_tostring(sjt_parent28, &sjt_call14);
#line 222
        sjt_functionParam53 = &sjt_call14;
#line 222
        sjf_string_add(sjt_parent26, sjt_functionParam53, &sjt_call13);
#line 222
        sjt_copy6 = &sjt_call13;
#line 222
        sjf_string_copy(&sjv_result, sjt_copy6);
#line 218
        i++;

        sjf_string_destroy(&sjt_call13);
        sjf_string_destroy(&sjt_call14);
        sjf_class_destroy(&sjt_call18);
    }

#line 224
    sjt_copy8 = &sjv_result;
#line 224
    sjf_string_copy(_return, sjt_copy8);

    sjf_string_destroy(&sjv_result);
}

void sjf_class(sjs_class* _this) {
}

void sjf_class_compare(sjs_class* l, sjs_class* r, int32_t* _return) {
    sjs_class* sjt_dot32;
    sjs_class* sjt_dot33;
    int32_t sjt_functionParam97;
    int32_t sjt_functionParam98;

#line 19 "array7.sj"
    sjt_dot32 = l;
#line 20
    sjt_functionParam97 = (sjt_dot32)->x;
#line 19
    sjt_dot33 = r;
#line 20
    sjt_functionParam98 = (sjt_dot33)->x;
#line 20
    sjf_i32_compare(sjt_functionParam97, sjt_functionParam98, _return);
}

void sjf_class_compare_callback(void * _parent, sjs_class* l, sjs_class* r, int32_t* _return) {
    sjf_class_compare(l, r, _return);
}

void sjf_class_copy(sjs_class* _this, sjs_class* _from) {
#line 3 "array7.sj"
    _this->x = _from->x;
}

void sjf_class_destroy(sjs_class* _this) {
}

void sjf_class_heap(sjs_class_heap* _this) {
}

void sjf_class_isgreater(sjs_class* _parent, sjs_class* c, bool* _return) {
    int32_t sjt_compare7;
    int32_t sjt_compare8;
    sjs_class* sjt_dot4;
    sjs_class* sjt_dot5;

#line 10 "array7.sj"
    sjt_dot4 = _parent;
#line 11
    sjt_compare7 = (sjt_dot4)->x;
#line 10
    sjt_dot5 = c;
#line 11
    sjt_compare8 = (sjt_dot5)->x;
#line 11
    (*_return) = sjt_compare7 > sjt_compare8;
}

void sjf_class_isless(sjs_class* _parent, sjs_class* c, bool* _return) {
    int32_t sjt_compare5;
    int32_t sjt_compare6;
    sjs_class* sjt_dot2;
    sjs_class* sjt_dot3;

#line 6 "array7.sj"
    sjt_dot2 = _parent;
#line 7
    sjt_compare5 = (sjt_dot2)->x;
#line 6
    sjt_dot3 = c;
#line 7
    sjt_compare6 = (sjt_dot3)->x;
#line 7
    (*_return) = sjt_compare5 < sjt_compare6;
}

void sjf_class_tostring(sjs_class* _parent, sjs_string* _return) {
    sjs_string sjt_call15;
    sjs_string sjt_call16;
    sjs_string sjt_call17;
    sjs_string* sjt_copy7;
    sjs_class* sjt_dot27;
    sjs_string* sjt_functionParam54;
    int32_t sjt_functionParam55;
    int32_t sjt_functionParam56;
    int32_t sjt_functionParam57;
    sjs_string* sjt_parent27;

#line 15 "array7.sj"
    sjt_call16.count = 1;
#line 15
    sjt_call16.data.datasize = 2;
#line 15
    sjt_call16.data.data = (void*)sjg_string4;
#line 15
    sjt_call16.data._isglobal = true;
#line 15
    sjt_call16.data.count = 2;
#line 15
    sjf_array_char(&sjt_call16.data);
#line 15
    sjf_string(&sjt_call16);
#line 15
    sjt_parent27 = &sjt_call16;
#line 14
    sjt_dot27 = _parent;
#line 15
    sjt_functionParam55 = (sjt_dot27)->x;
#line 22 "lib/common/i32.sj"
    sjt_functionParam56 = 10;
#line 22
    sjt_functionParam57 = 0;
#line 22
    sjf_i32_tostring(sjt_functionParam55, sjt_functionParam56, sjt_functionParam57, &sjt_call17);
#line 15 "array7.sj"
    sjt_functionParam54 = &sjt_call17;
#line 15
    sjf_string_add(sjt_parent27, sjt_functionParam54, &sjt_call15);
#line 15
    sjt_copy7 = &sjt_call15;
#line 15
    sjf_string_copy(_return, sjt_copy7);

    sjf_string_destroy(&sjt_call15);
    sjf_string_destroy(&sjt_call16);
    sjf_string_destroy(&sjt_call17);
}

void sjf_i32_compare(int32_t l, int32_t r, int32_t* _return) {
    int32_t sjt_compare43;
    int32_t sjt_compare44;
    bool sjt_ifElse12;

#line 52 "lib/common/i32.sj"
    sjt_compare43 = l;
#line 52
    sjt_compare44 = r;
#line 53
    sjt_ifElse12 = sjt_compare43 == sjt_compare44;
    if (sjt_ifElse12) {
#line 54 "lib/common/i32.sj"
        (*_return) = 0;
    } else {
        int32_t sjt_compare45;
        int32_t sjt_compare46;
        bool sjt_ifElse13;

#line 52 "lib/common/i32.sj"
        sjt_compare45 = l;
#line 52
        sjt_compare46 = r;
#line 55
        sjt_ifElse13 = sjt_compare45 < sjt_compare46;
        if (sjt_ifElse13) {
            int32_t result2;
            int32_t sjt_negate2;

#line 56 "lib/common/i32.sj"
            sjt_negate2 = 1;
#line 56
            result2 = -sjt_negate2;
#line 56
            (*_return) = result2;
        } else {
#line 58 "lib/common/i32.sj"
            (*_return) = 1;
        }
    }
}

void sjf_i32_tostring(int32_t val, int32_t base, int32_t minlength, sjs_string* _return) {
    int32_t sjt_math33;
    int32_t sjt_math34;
    int32_t sjt_math35;
    int32_t sjt_math36;
    int32_t sjv_count;
    void* sjv_data;

#line 23 "lib/common/i32.sj"
    sjv_count = 0;
#line 24
    sjv_data = 0;
#line 26
    if (base < 2) {
#line 27
        halt("base is too small");
#line 28
    }
#line 30
    if (base > 16) {
#line 31
        halt("base is too large");
#line 32
    }
#line 34
    char buf[32] = { 0 };
#line 35
    int i = 30;	
#line 36
    do {
#line 37
        buf[i] = "0123456789ABCDEF"[val % base];	
#line 38
        i--;
#line 39
        val /= base;
#line 40
    } while (val && i);
#line 41
    sjv_count = 30 - i;
#line 43
    if (sjv_count < minlength) {				
#line 44
}
#line 46
sjv_data = malloc(sizeof(char) * (sjv_count + 1));
#line 47
memcpy(sjv_data, &buf[i+1], sjv_count + 1);
#line 49
_return->count = sjv_count;
#line 49
sjt_math33 = sjv_count;
#line 49
sjt_math34 = 1;
#line 49
_return->data.datasize = sjt_math33 + sjt_math34;
#line 49
_return->data.data = sjv_data;
#line 4 "lib/common/array.sj"
_return->data._isglobal = false;
#line 49 "lib/common/i32.sj"
sjt_math35 = sjv_count;
#line 49
sjt_math36 = 1;
#line 49
_return->data.count = sjt_math35 + sjt_math36;
#line 49
sjf_array_char(&_return->data);
#line 49
sjf_string(_return);
}

void sjf_i32_tostring_heap(int32_t val, int32_t base, int32_t minlength, sjs_string_heap** _return) {
    int32_t sjt_math37;
    int32_t sjt_math38;
    int32_t sjt_math39;
    int32_t sjt_math40;
    int32_t sjv_count;
    void* sjv_data;

#line 23 "lib/common/i32.sj"
    sjv_count = 0;
#line 24
    sjv_data = 0;
#line 26
    if (base < 2) {
#line 27
        halt("base is too small");
#line 28
    }
#line 30
    if (base > 16) {
#line 31
        halt("base is too large");
#line 32
    }
#line 34
    char buf[32] = { 0 };
#line 35
    int i = 30;	
#line 36
    do {
#line 37
        buf[i] = "0123456789ABCDEF"[val % base];	
#line 38
        i--;
#line 39
        val /= base;
#line 40
    } while (val && i);
#line 41
    sjv_count = 30 - i;
#line 43
    if (sjv_count < minlength) {				
#line 44
}
#line 46
sjv_data = malloc(sizeof(char) * (sjv_count + 1));
#line 47
memcpy(sjv_data, &buf[i+1], sjv_count + 1);
#line 47
(*_return) = (sjs_string_heap*)malloc(sizeof(sjs_string_heap));
#line 47
(*_return)->_refCount = 1;
#line 49
(*_return)->count = sjv_count;
#line 49
sjt_math37 = sjv_count;
#line 49
sjt_math38 = 1;
#line 49
(*_return)->data.datasize = sjt_math37 + sjt_math38;
#line 49
(*_return)->data.data = sjv_data;
#line 4 "lib/common/array.sj"
(*_return)->data._isglobal = false;
#line 49 "lib/common/i32.sj"
sjt_math39 = sjv_count;
#line 49
sjt_math40 = 1;
#line 49
(*_return)->data.count = sjt_math39 + sjt_math40;
#line 49
sjf_array_char(&(*_return)->data);
#line 49
sjf_string_heap((*_return));
}

void sjf_string(sjs_string* _this) {
}

void sjf_string_add(sjs_string* _parent, sjs_string* item, sjs_string* _return) {
    int32_t sjt_compare19;
    int32_t sjt_compare20;
    sjs_string* sjt_dot8;
    bool sjt_ifElse6;

#line 15 "lib/common/string.sj"
    sjt_dot8 = item;
#line 16
    sjt_compare19 = (sjt_dot8)->count;
#line 16
    sjt_compare20 = 0;
#line 16
    sjt_ifElse6 = sjt_compare19 == sjt_compare20;
    if (sjt_ifElse6) {
        sjs_array_char* sjt_copy2;
        sjs_string* sjt_dot10;
        sjs_string* sjt_dot9;

#line 15 "lib/common/string.sj"
        sjt_dot9 = _parent;
#line 17
        _return->count = (sjt_dot9)->count;
#line 15
        sjt_dot10 = _parent;
#line 17
        sjt_copy2 = &(sjt_dot10)->data;
#line 17
        sjf_array_char_copy(&_return->data, sjt_copy2);
#line 17
        sjf_string(_return);
    } else {
        int32_t i;
        int32_t sjt_cast1;
        sjs_array_char* sjt_copy3;
        sjs_string* sjt_dot13;
        sjs_string* sjt_dot14;
        sjs_string* sjt_dot15;
        sjs_string* sjt_dot16;
        sjs_string* sjt_dot18;
        int32_t sjt_forEnd2;
        int32_t sjt_forStart2;
        int32_t sjt_functionParam33;
        int32_t sjt_functionParam34;
        char sjt_functionParam35;
        int32_t sjt_functionParam37;
        int32_t sjt_functionParam41;
        char sjt_functionParam42;
        int32_t sjt_math17;
        int32_t sjt_math18;
        int32_t sjt_math19;
        int32_t sjt_math20;
        int32_t sjt_math21;
        int32_t sjt_math22;
        sjs_array_char* sjt_parent12;
        sjs_array_char* sjt_parent13;
        sjs_string* sjt_parent15;
        sjs_array_char* sjt_parent18;
        int32_t sjv_newcount;
        sjs_array_char sjv_newdata;

#line 15 "lib/common/string.sj"
        sjt_dot13 = _parent;
#line 115 "lib/common/array.sj"
        sjt_parent12 = &(sjt_dot13)->data;
#line 15 "lib/common/string.sj"
        sjt_dot14 = _parent;
#line 19
        sjt_math19 = (sjt_dot14)->count;
#line 15
        sjt_dot15 = item;
#line 19
        sjt_math20 = (sjt_dot15)->count;
#line 19
        sjt_math17 = sjt_math19 + sjt_math20;
#line 19
        sjt_math18 = 1;
#line 19
        sjt_functionParam33 = sjt_math17 + sjt_math18;
#line 19
        sjf_array_char_grow(sjt_parent12, sjt_functionParam33, &sjv_newdata);
#line 15
        sjt_dot16 = _parent;
#line 20
        sjv_newcount = (sjt_dot16)->count;
#line 34 "lib/common/array.sj"
        sjt_parent13 = &sjv_newdata;
#line 21 "lib/common/string.sj"
        sjt_functionParam34 = sjv_newcount;
#line 15
        sjt_parent15 = item;
#line 21
        sjt_functionParam37 = 0;
#line 21
        sjf_string_getat(sjt_parent15, sjt_functionParam37, &sjt_functionParam35);
#line 21
        sjf_array_char_setat(sjt_parent13, sjt_functionParam34, sjt_functionParam35);
#line 22
        sjt_math21 = sjv_newcount;
#line 22
        sjt_math22 = 1;
#line 22
        sjv_newcount = sjt_math21 + sjt_math22;
#line 24
        sjt_forStart2 = 1;
#line 15
        sjt_dot18 = item;
#line 24
        sjt_forEnd2 = (sjt_dot18)->count;
#line 24
        i = sjt_forStart2;
        while (i < sjt_forEnd2) {
            int32_t sjt_functionParam38;
            char sjt_functionParam39;
            int32_t sjt_functionParam40;
            int32_t sjt_math23;
            int32_t sjt_math24;
            sjs_array_char* sjt_parent16;
            sjs_string* sjt_parent17;

#line 19 "lib/common/array.sj"
            sjt_parent16 = &sjv_newdata;
#line 25 "lib/common/string.sj"
            sjt_functionParam38 = sjv_newcount;
#line 15
            sjt_parent17 = item;
#line 24
            sjt_functionParam40 = i;
#line 24
            sjf_string_getat(sjt_parent17, sjt_functionParam40, &sjt_functionParam39);
#line 24
            sjf_array_char_initat(sjt_parent16, sjt_functionParam38, sjt_functionParam39);
#line 26
            sjt_math23 = sjv_newcount;
#line 26
            sjt_math24 = 1;
#line 26
            sjv_newcount = sjt_math23 + sjt_math24;
#line 24
            i++;
        }

#line 19 "lib/common/array.sj"
        sjt_parent18 = &sjv_newdata;
#line 29 "lib/common/string.sj"
        sjt_functionParam41 = sjv_newcount;
#line 29
        sjt_cast1 = 0;
#line 29
        sjt_functionParam42 = (char)sjt_cast1;
#line 29
        sjf_array_char_initat(sjt_parent18, sjt_functionParam41, sjt_functionParam42);
#line 30
        _return->count = sjv_newcount;
#line 30
        sjt_copy3 = &sjv_newdata;
#line 30
        sjf_array_char_copy(&_return->data, sjt_copy3);
#line 30
        sjf_string(_return);

        sjf_array_char_destroy(&sjv_newdata);
    }
}

void sjf_string_add_heap(sjs_string* _parent, sjs_string* item, sjs_string_heap** _return) {
    int32_t sjt_compare21;
    int32_t sjt_compare22;
    sjs_string* sjt_dot19;
    bool sjt_ifElse7;

#line 15 "lib/common/string.sj"
    sjt_dot19 = item;
#line 16
    sjt_compare21 = (sjt_dot19)->count;
#line 16
    sjt_compare22 = 0;
#line 16
    sjt_ifElse7 = sjt_compare21 == sjt_compare22;
    if (sjt_ifElse7) {
        sjs_array_char* sjt_copy4;
        sjs_string* sjt_dot20;
        sjs_string* sjt_dot21;

        (*_return) = (sjs_string_heap*)malloc(sizeof(sjs_string_heap));
        (*_return)->_refCount = 1;
#line 15 "lib/common/string.sj"
        sjt_dot20 = _parent;
#line 17
        (*_return)->count = (sjt_dot20)->count;
#line 15
        sjt_dot21 = _parent;
#line 17
        sjt_copy4 = &(sjt_dot21)->data;
#line 17
        sjf_array_char_copy(&(*_return)->data, sjt_copy4);
#line 17
        sjf_string_heap((*_return));
    } else {
        int32_t i;
        int32_t sjt_cast2;
        sjs_array_char* sjt_copy5;
        sjs_string* sjt_dot22;
        sjs_string* sjt_dot23;
        sjs_string* sjt_dot24;
        sjs_string* sjt_dot25;
        sjs_string* sjt_dot26;
        int32_t sjt_forEnd3;
        int32_t sjt_forStart3;
        int32_t sjt_functionParam43;
        int32_t sjt_functionParam44;
        char sjt_functionParam45;
        int32_t sjt_functionParam46;
        int32_t sjt_functionParam50;
        char sjt_functionParam51;
        int32_t sjt_math25;
        int32_t sjt_math26;
        int32_t sjt_math27;
        int32_t sjt_math28;
        int32_t sjt_math29;
        int32_t sjt_math30;
        sjs_array_char* sjt_parent19;
        sjs_array_char* sjt_parent20;
        sjs_string* sjt_parent21;
        sjs_array_char* sjt_parent24;
        int32_t sjv_newcount;
        sjs_array_char sjv_newdata;

#line 15 "lib/common/string.sj"
        sjt_dot22 = _parent;
#line 115 "lib/common/array.sj"
        sjt_parent19 = &(sjt_dot22)->data;
#line 15 "lib/common/string.sj"
        sjt_dot23 = _parent;
#line 19
        sjt_math27 = (sjt_dot23)->count;
#line 15
        sjt_dot24 = item;
#line 19
        sjt_math28 = (sjt_dot24)->count;
#line 19
        sjt_math25 = sjt_math27 + sjt_math28;
#line 19
        sjt_math26 = 1;
#line 19
        sjt_functionParam43 = sjt_math25 + sjt_math26;
#line 19
        sjf_array_char_grow(sjt_parent19, sjt_functionParam43, &sjv_newdata);
#line 15
        sjt_dot25 = _parent;
#line 20
        sjv_newcount = (sjt_dot25)->count;
#line 34 "lib/common/array.sj"
        sjt_parent20 = &sjv_newdata;
#line 21 "lib/common/string.sj"
        sjt_functionParam44 = sjv_newcount;
#line 15
        sjt_parent21 = item;
#line 21
        sjt_functionParam46 = 0;
#line 21
        sjf_string_getat(sjt_parent21, sjt_functionParam46, &sjt_functionParam45);
#line 21
        sjf_array_char_setat(sjt_parent20, sjt_functionParam44, sjt_functionParam45);
#line 22
        sjt_math29 = sjv_newcount;
#line 22
        sjt_math30 = 1;
#line 22
        sjv_newcount = sjt_math29 + sjt_math30;
#line 24
        sjt_forStart3 = 1;
#line 15
        sjt_dot26 = item;
#line 24
        sjt_forEnd3 = (sjt_dot26)->count;
#line 24
        i = sjt_forStart3;
        while (i < sjt_forEnd3) {
            int32_t sjt_functionParam47;
            char sjt_functionParam48;
            int32_t sjt_functionParam49;
            int32_t sjt_math31;
            int32_t sjt_math32;
            sjs_array_char* sjt_parent22;
            sjs_string* sjt_parent23;

#line 19 "lib/common/array.sj"
            sjt_parent22 = &sjv_newdata;
#line 25 "lib/common/string.sj"
            sjt_functionParam47 = sjv_newcount;
#line 15
            sjt_parent23 = item;
#line 24
            sjt_functionParam49 = i;
#line 24
            sjf_string_getat(sjt_parent23, sjt_functionParam49, &sjt_functionParam48);
#line 24
            sjf_array_char_initat(sjt_parent22, sjt_functionParam47, sjt_functionParam48);
#line 26
            sjt_math31 = sjv_newcount;
#line 26
            sjt_math32 = 1;
#line 26
            sjv_newcount = sjt_math31 + sjt_math32;
#line 24
            i++;
        }

#line 19 "lib/common/array.sj"
        sjt_parent24 = &sjv_newdata;
#line 29 "lib/common/string.sj"
        sjt_functionParam50 = sjv_newcount;
#line 29
        sjt_cast2 = 0;
#line 29
        sjt_functionParam51 = (char)sjt_cast2;
#line 29
        sjf_array_char_initat(sjt_parent24, sjt_functionParam50, sjt_functionParam51);
#line 29
        (*_return) = (sjs_string_heap*)malloc(sizeof(sjs_string_heap));
#line 29
        (*_return)->_refCount = 1;
#line 30
        (*_return)->count = sjv_newcount;
#line 30
        sjt_copy5 = &sjv_newdata;
#line 30
        sjf_array_char_copy(&(*_return)->data, sjt_copy5);
#line 30
        sjf_string_heap((*_return));

        sjf_array_char_destroy(&sjv_newdata);
    }
}

void sjf_string_copy(sjs_string* _this, sjs_string* _from) {
#line 6 "lib/common/string.sj"
    _this->count = _from->count;
#line 6
    sjf_array_char_copy(&_this->data, &_from->data);
}

void sjf_string_destroy(sjs_string* _this) {
}

void sjf_string_getat(sjs_string* _parent, int32_t index, char* _return) {
    sjs_string* sjt_dot17;
    int32_t sjt_functionParam36;
    sjs_array_char* sjt_parent14;

#line 34 "lib/common/string.sj"
    sjt_dot17 = _parent;
#line 7 "lib/common/array.sj"
    sjt_parent14 = &(sjt_dot17)->data;
#line 34 "lib/common/string.sj"
    sjt_functionParam36 = index;
#line 34
    sjf_array_char_getat(sjt_parent14, sjt_functionParam36, _return);
}

void sjf_string_heap(sjs_string_heap* _this) {
}

int main(int argc, char** argv) {
    sjf_anon1(&sjv_console);
#line 1 "lib/common/f32.sj"
    sjv_f32_pi = 3.14159265358979323846f;
#line 1 "lib/common/i32.sj"
    sjv_u32_maxvalue = (uint32_t)4294967295u;
#line 3
    sjt_negate1 = 1;
#line 3
    result1 = -sjt_negate1;
#line 3
    sjt_math1 = result1;
#line 3
    sjt_math2 = 2147483647;
#line 3
    sjv_i32_maxvalue = sjt_math1 - sjt_math2;
#line 4
    sjv_i32_minvalue = 2147483647;
#line 1 "lib/common/string.sj"
    sjv_emptystringdata = 0;
#line 3
    sjv_emptystringdata = "";
#line 167 "lib/common/weakptr.sj"
    ptr_init();
#line 168
    weakptr_init();
#line 24 "array7.sj"
    sjv_a.datasize = 5;
#line 3 "lib/common/array.sj"
    sjv_a.data = 0;
#line 4
    sjv_a._isglobal = false;
#line 5
    sjv_a.count = 0;
#line 5
    sjf_array_class(&sjv_a);
#line 24 "array7.sj"
    sjs_array_class* array1;
#line 24
    array1 = &sjv_a;
#line 24
    sjt_parent1 = array1;
#line 24
    sjt_functionParam1 = 0;
#line 24
    sjt_call1.x = 1;
#line 24
    sjf_class(&sjt_call1);
#line 24
    sjt_functionParam2 = &sjt_call1;
#line 24
    sjf_array_class_initat(sjt_parent1, sjt_functionParam1, sjt_functionParam2);
#line 24
    sjt_parent2 = array1;
#line 24
    sjt_functionParam3 = 1;
#line 24
    sjt_call2.x = 4;
#line 24
    sjf_class(&sjt_call2);
#line 24
    sjt_functionParam4 = &sjt_call2;
#line 24
    sjf_array_class_initat(sjt_parent2, sjt_functionParam3, sjt_functionParam4);
#line 24
    sjt_parent3 = array1;
#line 24
    sjt_functionParam5 = 2;
#line 24
    sjt_call3.x = 5;
#line 24
    sjf_class(&sjt_call3);
#line 24
    sjt_functionParam6 = &sjt_call3;
#line 24
    sjf_array_class_initat(sjt_parent3, sjt_functionParam5, sjt_functionParam6);
#line 24
    sjt_parent4 = array1;
#line 24
    sjt_functionParam7 = 3;
#line 24
    sjt_call4.x = 6;
#line 24
    sjf_class(&sjt_call4);
#line 24
    sjt_functionParam8 = &sjt_call4;
#line 24
    sjf_array_class_initat(sjt_parent4, sjt_functionParam7, sjt_functionParam8);
#line 24
    sjt_parent5 = array1;
#line 24
    sjt_functionParam9 = 4;
#line 24
    sjt_call5.x = 2;
#line 24
    sjf_class(&sjt_call5);
#line 24
    sjt_functionParam10 = &sjt_call5;
#line 24
    sjf_array_class_initat(sjt_parent5, sjt_functionParam9, sjt_functionParam10);
#line 195 "lib/common/array.sj"
    sjt_parent10 = &sjv_a;
#line 195
    sjf_array_class_sort(sjt_parent10);
#line 12 "lib/common/console.sj"
    sjt_parent11 = &sjv_console;
#line 216 "lib/common/array.sj"
    sjt_parent29 = &sjv_a;
#line 216
    sjt_call19.count = 2;
#line 216
    sjt_call19.data.datasize = 3;
#line 216
    sjt_call19.data.data = (void*)sjg_string1;
#line 216
    sjt_call19.data._isglobal = true;
#line 216
    sjt_call19.data.count = 3;
#line 216
    sjf_array_char(&sjt_call19.data);
#line 216
    sjf_string(&sjt_call19);
#line 216
    sjt_functionParam59 = &sjt_call19;
#line 216
    sjf_array_class_tostring(sjt_parent29, sjt_functionParam59, &sjt_call11);
#line 26 "array7.sj"
    sjt_functionParam32 = &sjt_call11;
#line 26
    sjf_anon1_writeline(sjt_parent11, sjt_functionParam32);
#line 207 "lib/common/array.sj"
    sjt_parent30 = &sjv_a;
#line 207
    sjf_array_class_reverse(sjt_parent30);
#line 12 "lib/common/console.sj"
    sjt_parent31 = &sjv_console;
#line 216 "lib/common/array.sj"
    sjt_parent32 = &sjv_a;
#line 216
    sjt_call22.count = 2;
#line 216
    sjt_call22.data.datasize = 3;
#line 216
    sjt_call22.data.data = (void*)sjg_string1;
#line 216
    sjt_call22.data._isglobal = true;
#line 216
    sjt_call22.data.count = 3;
#line 216
    sjf_array_char(&sjt_call22.data);
#line 216
    sjf_string(&sjt_call22);
#line 216
    sjt_functionParam67 = &sjt_call22;
#line 216
    sjf_array_class_tostring(sjt_parent32, sjt_functionParam67, &sjt_call21);
#line 29 "array7.sj"
    sjt_functionParam66 = &sjt_call21;
#line 29
    sjf_anon1_writeline(sjt_parent31, sjt_functionParam66);
#line 201 "lib/common/array.sj"
    sjt_parent33 = &sjv_a;
#line 31 "array7.sj"
    sjt_functionParam96._parent = (void*)1;
#line 31
    sjt_functionParam96._cb = (void(*)(void*,sjs_class*,sjs_class*, int32_t*))sjf_class_compare_callback;
#line 31
    sjf_array_class_sortcb(sjt_parent33, sjt_functionParam96);
#line 12 "lib/common/console.sj"
    sjt_parent34 = &sjv_console;
#line 216 "lib/common/array.sj"
    sjt_parent35 = &sjv_a;
#line 216
    sjt_call29.count = 2;
#line 216
    sjt_call29.data.datasize = 3;
#line 216
    sjt_call29.data.data = (void*)sjg_string1;
#line 216
    sjt_call29.data._isglobal = true;
#line 216
    sjt_call29.data.count = 3;
#line 216
    sjf_array_char(&sjt_call29.data);
#line 216
    sjf_string(&sjt_call29);
#line 216
    sjt_functionParam100 = &sjt_call29;
#line 216
    sjf_array_class_tostring(sjt_parent35, sjt_functionParam100, &sjt_call28);
#line 32 "array7.sj"
    sjt_functionParam99 = &sjt_call28;
#line 32
    sjf_anon1_writeline(sjt_parent34, sjt_functionParam99);
    main_destroy();
    return 0;
}

void main_destroy() {

    sjf_class_destroy(&sjt_call1);
    sjf_string_destroy(&sjt_call11);
    sjf_string_destroy(&sjt_call19);
    sjf_class_destroy(&sjt_call2);
    sjf_string_destroy(&sjt_call21);
    sjf_string_destroy(&sjt_call22);
    sjf_string_destroy(&sjt_call28);
    sjf_string_destroy(&sjt_call29);
    sjf_class_destroy(&sjt_call3);
    sjf_class_destroy(&sjt_call4);
    sjf_class_destroy(&sjt_call5);
    sjf_array_class_destroy(&sjv_a);
    sjf_anon1_destroy(&sjv_console);
}
