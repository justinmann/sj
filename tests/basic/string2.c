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
#define sjs_array_char_typeId 4
#define sjs_array_char_heap_typeId 5
#define sjs_string_typeId 6
#define sjs_string_heap_typeId 7

typedef struct td_sjs_object sjs_object;
typedef struct td_sjs_anon1 sjs_anon1;
typedef struct td_sjs_anon1_heap sjs_anon1_heap;
typedef struct td_sjs_array_char sjs_array_char;
typedef struct td_sjs_array_char_heap sjs_array_char_heap;
typedef struct td_sjs_string sjs_string;
typedef struct td_sjs_string_heap sjs_string_heap;

struct td_sjs_object {
    intptr_t _refCount;
};

struct td_sjs_anon1 {
    int structsNeedAValue;
};

struct td_sjs_anon1_heap {
    intptr_t _refCount;
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
sjs_string sjt_call1;
sjs_string* sjt_functionParam1;
int32_t sjt_math1;
int32_t sjt_math2;
int32_t sjt_negate1;
sjs_anon1* sjt_parent1;
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
void sjf_func(sjs_string* _return);
void sjf_func_heap(sjs_string_heap** _return);
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
    sjs_array_char* sjt_dot4;
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
    sjt_dot4 = _parent;
#line 130
    _return->count = (sjt_dot4)->count;
#line 130
    sjf_array_char(_return);
}

void sjf_array_char_grow_heap(sjs_array_char* _parent, int32_t newsize, sjs_array_char_heap** _return) {
    sjs_array_char* sjt_dot5;
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
    sjt_dot5 = _parent;
#line 130
    (*_return)->count = (sjt_dot5)->count;
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

void sjf_func(sjs_string* _return) {
    sjs_string sjt_call2;
    sjs_string sjt_call3;
    int32_t sjt_functionParam21;
    int32_t sjt_functionParam22;
    int32_t sjt_functionParam23;
    sjs_string* sjt_functionParam24;
    int32_t sjt_functionParam25;
    int32_t sjt_functionParam26;
    int32_t sjt_functionParam27;
    sjs_string* sjt_parent15;

#line 5 "string2.sj"
    sjt_functionParam21 = 1;
#line 22 "lib/common/i32.sj"
    sjt_functionParam22 = 10;
#line 22
    sjt_functionParam23 = 0;
#line 22
    sjf_i32_tostring(sjt_functionParam21, sjt_functionParam22, sjt_functionParam23, &sjt_call2);
#line 5 "string2.sj"
    sjt_parent15 = &sjt_call2;
#line 5
    sjt_functionParam25 = 2;
#line 22 "lib/common/i32.sj"
    sjt_functionParam26 = 10;
#line 22
    sjt_functionParam27 = 0;
#line 22
    sjf_i32_tostring(sjt_functionParam25, sjt_functionParam26, sjt_functionParam27, &sjt_call3);
#line 5 "string2.sj"
    sjt_functionParam24 = &sjt_call3;
#line 5
    sjf_string_add(sjt_parent15, sjt_functionParam24, _return);

    sjf_string_destroy(&sjt_call2);
    sjf_string_destroy(&sjt_call3);
}

void sjf_func_heap(sjs_string_heap** _return) {
    sjs_string sjt_call4;
    sjs_string sjt_call5;
    int32_t sjt_functionParam28;
    int32_t sjt_functionParam29;
    int32_t sjt_functionParam30;
    sjs_string* sjt_functionParam31;
    int32_t sjt_functionParam32;
    int32_t sjt_functionParam33;
    int32_t sjt_functionParam34;
    sjs_string* sjt_parent16;

#line 5 "string2.sj"
    sjt_functionParam28 = 1;
#line 22 "lib/common/i32.sj"
    sjt_functionParam29 = 10;
#line 22
    sjt_functionParam30 = 0;
#line 22
    sjf_i32_tostring(sjt_functionParam28, sjt_functionParam29, sjt_functionParam30, &sjt_call4);
#line 5 "string2.sj"
    sjt_parent16 = &sjt_call4;
#line 5
    sjt_functionParam32 = 2;
#line 22 "lib/common/i32.sj"
    sjt_functionParam33 = 10;
#line 22
    sjt_functionParam34 = 0;
#line 22
    sjf_i32_tostring(sjt_functionParam32, sjt_functionParam33, sjt_functionParam34, &sjt_call5);
#line 5 "string2.sj"
    sjt_functionParam31 = &sjt_call5;
#line 5
    sjf_string_add_heap(sjt_parent16, sjt_functionParam31, _return);

    sjf_string_destroy(&sjt_call4);
    sjf_string_destroy(&sjt_call5);
}

void sjf_i32_tostring(int32_t val, int32_t base, int32_t minlength, sjs_string* _return) {
    int32_t sjt_math19;
    int32_t sjt_math20;
    int32_t sjt_math21;
    int32_t sjt_math22;
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
sjt_math19 = sjv_count;
#line 49
sjt_math20 = 1;
#line 49
_return->data.datasize = sjt_math19 + sjt_math20;
#line 49
_return->data.data = sjv_data;
#line 4 "lib/common/array.sj"
_return->data._isglobal = false;
#line 49 "lib/common/i32.sj"
sjt_math21 = sjv_count;
#line 49
sjt_math22 = 1;
#line 49
_return->data.count = sjt_math21 + sjt_math22;
#line 49
sjf_array_char(&_return->data);
#line 49
sjf_string(_return);
}

void sjf_i32_tostring_heap(int32_t val, int32_t base, int32_t minlength, sjs_string_heap** _return) {
    int32_t sjt_math23;
    int32_t sjt_math24;
    int32_t sjt_math25;
    int32_t sjt_math26;
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
sjt_math23 = sjv_count;
#line 49
sjt_math24 = 1;
#line 49
(*_return)->data.datasize = sjt_math23 + sjt_math24;
#line 49
(*_return)->data.data = sjv_data;
#line 4 "lib/common/array.sj"
(*_return)->data._isglobal = false;
#line 49 "lib/common/i32.sj"
sjt_math25 = sjv_count;
#line 49
sjt_math26 = 1;
#line 49
(*_return)->data.count = sjt_math25 + sjt_math26;
#line 49
sjf_array_char(&(*_return)->data);
#line 49
sjf_string_heap((*_return));
}

void sjf_string(sjs_string* _this) {
}

void sjf_string_add(sjs_string* _parent, sjs_string* item, sjs_string* _return) {
    int32_t sjt_compare1;
    int32_t sjt_compare2;
    sjs_string* sjt_dot1;
    bool sjt_ifElse1;

#line 15 "lib/common/string.sj"
    sjt_dot1 = item;
#line 16
    sjt_compare1 = (sjt_dot1)->count;
#line 16
    sjt_compare2 = 0;
#line 16
    sjt_ifElse1 = sjt_compare1 == sjt_compare2;
    if (sjt_ifElse1) {
        sjs_array_char* sjt_copy1;
        sjs_string* sjt_dot2;
        sjs_string* sjt_dot3;

#line 15 "lib/common/string.sj"
        sjt_dot2 = _parent;
#line 17
        _return->count = (sjt_dot2)->count;
#line 15
        sjt_dot3 = _parent;
#line 17
        sjt_copy1 = &(sjt_dot3)->data;
#line 17
        sjf_array_char_copy(&_return->data, sjt_copy1);
#line 17
        sjf_string(_return);
    } else {
        int32_t i;
        int32_t sjt_cast1;
        sjs_array_char* sjt_copy2;
        sjs_string* sjt_dot11;
        sjs_string* sjt_dot6;
        sjs_string* sjt_dot7;
        sjs_string* sjt_dot8;
        sjs_string* sjt_dot9;
        int32_t sjt_forEnd1;
        int32_t sjt_forStart1;
        int32_t sjt_functionParam10;
        char sjt_functionParam11;
        int32_t sjt_functionParam2;
        int32_t sjt_functionParam3;
        char sjt_functionParam4;
        int32_t sjt_functionParam6;
        int32_t sjt_math3;
        int32_t sjt_math4;
        int32_t sjt_math5;
        int32_t sjt_math6;
        int32_t sjt_math7;
        int32_t sjt_math8;
        sjs_array_char* sjt_parent2;
        sjs_array_char* sjt_parent3;
        sjs_string* sjt_parent5;
        sjs_array_char* sjt_parent8;
        int32_t sjv_newcount;
        sjs_array_char sjv_newdata;

#line 15 "lib/common/string.sj"
        sjt_dot6 = _parent;
#line 115 "lib/common/array.sj"
        sjt_parent2 = &(sjt_dot6)->data;
#line 15 "lib/common/string.sj"
        sjt_dot7 = _parent;
#line 19
        sjt_math5 = (sjt_dot7)->count;
#line 15
        sjt_dot8 = item;
#line 19
        sjt_math6 = (sjt_dot8)->count;
#line 19
        sjt_math3 = sjt_math5 + sjt_math6;
#line 19
        sjt_math4 = 1;
#line 19
        sjt_functionParam2 = sjt_math3 + sjt_math4;
#line 19
        sjf_array_char_grow(sjt_parent2, sjt_functionParam2, &sjv_newdata);
#line 15
        sjt_dot9 = _parent;
#line 20
        sjv_newcount = (sjt_dot9)->count;
#line 34 "lib/common/array.sj"
        sjt_parent3 = &sjv_newdata;
#line 21 "lib/common/string.sj"
        sjt_functionParam3 = sjv_newcount;
#line 15
        sjt_parent5 = item;
#line 21
        sjt_functionParam6 = 0;
#line 21
        sjf_string_getat(sjt_parent5, sjt_functionParam6, &sjt_functionParam4);
#line 21
        sjf_array_char_setat(sjt_parent3, sjt_functionParam3, sjt_functionParam4);
#line 22
        sjt_math7 = sjv_newcount;
#line 22
        sjt_math8 = 1;
#line 22
        sjv_newcount = sjt_math7 + sjt_math8;
#line 24
        sjt_forStart1 = 1;
#line 15
        sjt_dot11 = item;
#line 24
        sjt_forEnd1 = (sjt_dot11)->count;
#line 24
        i = sjt_forStart1;
        while (i < sjt_forEnd1) {
            int32_t sjt_functionParam7;
            char sjt_functionParam8;
            int32_t sjt_functionParam9;
            int32_t sjt_math10;
            int32_t sjt_math9;
            sjs_array_char* sjt_parent6;
            sjs_string* sjt_parent7;

#line 19 "lib/common/array.sj"
            sjt_parent6 = &sjv_newdata;
#line 25 "lib/common/string.sj"
            sjt_functionParam7 = sjv_newcount;
#line 15
            sjt_parent7 = item;
#line 24
            sjt_functionParam9 = i;
#line 24
            sjf_string_getat(sjt_parent7, sjt_functionParam9, &sjt_functionParam8);
#line 24
            sjf_array_char_initat(sjt_parent6, sjt_functionParam7, sjt_functionParam8);
#line 26
            sjt_math9 = sjv_newcount;
#line 26
            sjt_math10 = 1;
#line 26
            sjv_newcount = sjt_math9 + sjt_math10;
#line 24
            i++;
        }

#line 19 "lib/common/array.sj"
        sjt_parent8 = &sjv_newdata;
#line 29 "lib/common/string.sj"
        sjt_functionParam10 = sjv_newcount;
#line 29
        sjt_cast1 = 0;
#line 29
        sjt_functionParam11 = (char)sjt_cast1;
#line 29
        sjf_array_char_initat(sjt_parent8, sjt_functionParam10, sjt_functionParam11);
#line 30
        _return->count = sjv_newcount;
#line 30
        sjt_copy2 = &sjv_newdata;
#line 30
        sjf_array_char_copy(&_return->data, sjt_copy2);
#line 30
        sjf_string(_return);

        sjf_array_char_destroy(&sjv_newdata);
    }
}

void sjf_string_add_heap(sjs_string* _parent, sjs_string* item, sjs_string_heap** _return) {
    int32_t sjt_compare3;
    int32_t sjt_compare4;
    sjs_string* sjt_dot12;
    bool sjt_ifElse2;

#line 15 "lib/common/string.sj"
    sjt_dot12 = item;
#line 16
    sjt_compare3 = (sjt_dot12)->count;
#line 16
    sjt_compare4 = 0;
#line 16
    sjt_ifElse2 = sjt_compare3 == sjt_compare4;
    if (sjt_ifElse2) {
        sjs_array_char* sjt_copy3;
        sjs_string* sjt_dot13;
        sjs_string* sjt_dot14;

        (*_return) = (sjs_string_heap*)malloc(sizeof(sjs_string_heap));
        (*_return)->_refCount = 1;
#line 15 "lib/common/string.sj"
        sjt_dot13 = _parent;
#line 17
        (*_return)->count = (sjt_dot13)->count;
#line 15
        sjt_dot14 = _parent;
#line 17
        sjt_copy3 = &(sjt_dot14)->data;
#line 17
        sjf_array_char_copy(&(*_return)->data, sjt_copy3);
#line 17
        sjf_string_heap((*_return));
    } else {
        int32_t i;
        int32_t sjt_cast2;
        sjs_array_char* sjt_copy4;
        sjs_string* sjt_dot15;
        sjs_string* sjt_dot16;
        sjs_string* sjt_dot17;
        sjs_string* sjt_dot18;
        sjs_string* sjt_dot19;
        int32_t sjt_forEnd2;
        int32_t sjt_forStart2;
        int32_t sjt_functionParam12;
        int32_t sjt_functionParam13;
        char sjt_functionParam14;
        int32_t sjt_functionParam15;
        int32_t sjt_functionParam19;
        char sjt_functionParam20;
        int32_t sjt_math11;
        int32_t sjt_math12;
        int32_t sjt_math13;
        int32_t sjt_math14;
        int32_t sjt_math15;
        int32_t sjt_math16;
        sjs_array_char* sjt_parent10;
        sjs_string* sjt_parent11;
        sjs_array_char* sjt_parent14;
        sjs_array_char* sjt_parent9;
        int32_t sjv_newcount;
        sjs_array_char sjv_newdata;

#line 15 "lib/common/string.sj"
        sjt_dot15 = _parent;
#line 115 "lib/common/array.sj"
        sjt_parent9 = &(sjt_dot15)->data;
#line 15 "lib/common/string.sj"
        sjt_dot16 = _parent;
#line 19
        sjt_math13 = (sjt_dot16)->count;
#line 15
        sjt_dot17 = item;
#line 19
        sjt_math14 = (sjt_dot17)->count;
#line 19
        sjt_math11 = sjt_math13 + sjt_math14;
#line 19
        sjt_math12 = 1;
#line 19
        sjt_functionParam12 = sjt_math11 + sjt_math12;
#line 19
        sjf_array_char_grow(sjt_parent9, sjt_functionParam12, &sjv_newdata);
#line 15
        sjt_dot18 = _parent;
#line 20
        sjv_newcount = (sjt_dot18)->count;
#line 34 "lib/common/array.sj"
        sjt_parent10 = &sjv_newdata;
#line 21 "lib/common/string.sj"
        sjt_functionParam13 = sjv_newcount;
#line 15
        sjt_parent11 = item;
#line 21
        sjt_functionParam15 = 0;
#line 21
        sjf_string_getat(sjt_parent11, sjt_functionParam15, &sjt_functionParam14);
#line 21
        sjf_array_char_setat(sjt_parent10, sjt_functionParam13, sjt_functionParam14);
#line 22
        sjt_math15 = sjv_newcount;
#line 22
        sjt_math16 = 1;
#line 22
        sjv_newcount = sjt_math15 + sjt_math16;
#line 24
        sjt_forStart2 = 1;
#line 15
        sjt_dot19 = item;
#line 24
        sjt_forEnd2 = (sjt_dot19)->count;
#line 24
        i = sjt_forStart2;
        while (i < sjt_forEnd2) {
            int32_t sjt_functionParam16;
            char sjt_functionParam17;
            int32_t sjt_functionParam18;
            int32_t sjt_math17;
            int32_t sjt_math18;
            sjs_array_char* sjt_parent12;
            sjs_string* sjt_parent13;

#line 19 "lib/common/array.sj"
            sjt_parent12 = &sjv_newdata;
#line 25 "lib/common/string.sj"
            sjt_functionParam16 = sjv_newcount;
#line 15
            sjt_parent13 = item;
#line 24
            sjt_functionParam18 = i;
#line 24
            sjf_string_getat(sjt_parent13, sjt_functionParam18, &sjt_functionParam17);
#line 24
            sjf_array_char_initat(sjt_parent12, sjt_functionParam16, sjt_functionParam17);
#line 26
            sjt_math17 = sjv_newcount;
#line 26
            sjt_math18 = 1;
#line 26
            sjv_newcount = sjt_math17 + sjt_math18;
#line 24
            i++;
        }

#line 19 "lib/common/array.sj"
        sjt_parent14 = &sjv_newdata;
#line 29 "lib/common/string.sj"
        sjt_functionParam19 = sjv_newcount;
#line 29
        sjt_cast2 = 0;
#line 29
        sjt_functionParam20 = (char)sjt_cast2;
#line 29
        sjf_array_char_initat(sjt_parent14, sjt_functionParam19, sjt_functionParam20);
#line 29
        (*_return) = (sjs_string_heap*)malloc(sizeof(sjs_string_heap));
#line 29
        (*_return)->_refCount = 1;
#line 30
        (*_return)->count = sjv_newcount;
#line 30
        sjt_copy4 = &sjv_newdata;
#line 30
        sjf_array_char_copy(&(*_return)->data, sjt_copy4);
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
    sjs_string* sjt_dot10;
    int32_t sjt_functionParam5;
    sjs_array_char* sjt_parent4;

#line 34 "lib/common/string.sj"
    sjt_dot10 = _parent;
#line 7 "lib/common/array.sj"
    sjt_parent4 = &(sjt_dot10)->data;
#line 34 "lib/common/string.sj"
    sjt_functionParam5 = index;
#line 34
    sjf_array_char_getat(sjt_parent4, sjt_functionParam5, _return);
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
#line 12 "lib/common/console.sj"
    sjt_parent1 = &sjv_console;
#line 12
    sjf_func(&sjt_call1);
#line 8 "string2.sj"
    sjt_functionParam1 = &sjt_call1;
#line 8
    sjf_anon1_writeline(sjt_parent1, sjt_functionParam1);
    main_destroy();
    return 0;
}

void main_destroy() {

    sjf_string_destroy(&sjt_call1);
    sjf_anon1_destroy(&sjv_console);
}
