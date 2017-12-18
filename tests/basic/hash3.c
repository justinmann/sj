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

const char* sjg_string1 = "foo";
const char* sjg_string2 = "bob";
const char* sjg_string3 = "bob";
const char* sjg_string4 = "foo";
const char* sjg_string5 = "not found";

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
#define KHASH_INIT_FUNCTION(name, khkey_t, khval_t, kh_is_map, __hash_func, __hash_equal, deref) \
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
__hash_func(deref##key, &k); i = k % h->n_buckets;                 \
inc = 1 + k % (h->n_buckets - 1); last = i;                 \
bool isEqual;                                               \
__hash_equal(deref##h->keys[i], deref##key, &isEqual);                    \
while (!__ac_isempty(h->flags, i) && (__ac_isdel(h->flags, i) || !isEqual)) { \
if (i + inc >= h->n_buckets) i = i + inc - h->n_buckets; \
else i += inc;                                          \
if (i == last) return h->n_buckets;                     \
__hash_equal(deref##h->keys[i], deref##key, &isEqual);                \
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
__hash_func(deref##key, &k);                           \
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
x = site = h->n_buckets; __hash_func(deref##key, &k); i = k % h->n_buckets; \
if (__ac_isempty(h->flags, i)) x = i;                       \
else {                                                      \
inc = 1 + k % (h->n_buckets - 1); last = i;             \
bool isEqual;                                           \
__hash_equal(deref##h->keys[i], deref##key, &isEqual);                \
while (!__ac_isempty(h->flags, i) && (__ac_isdel(h->flags, i) || !isEqual)) { \
if (__ac_isdel(h->flags, i)) site = i;              \
if (i + inc >= h->n_buckets) i = i + inc - h->n_buckets; \
else i += inc;                                      \
if (i == last) { x = site; break; }                 \
__hash_equal(deref##h->keys[i], deref##key, &isEqual);            \
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
#define sji_interface_typeId 4
#define sjs_hash_string_heap_interface_typeId 5
#define sjs_class_typeId 6

typedef struct td_sjs_object sjs_object;
typedef struct td_sjs_array_char sjs_array_char;
typedef struct td_sjs_string sjs_string;
typedef struct td_sji_interface sji_interface;
typedef struct td_sjs_hash_string_heap_interface sjs_hash_string_heap_interface;
typedef struct td_sjs_class sjs_class;

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

struct td_sji_interface {
    intptr_t _refCount;
    sjs_object* _parent;
    void (*destroy)(void* _this);
    sjs_object* (*asInterface)(sjs_object* _this, int typeId);
    void (*bob)(void* _parent, sjs_string* _return);
    void (*bob_heap)(void* _parent, sjs_string** _return);
};

struct td_sjs_hash_string_heap_interface {
    int _refCount;
    void* _hash;
};

struct td_sjs_class {
    int _refCount;
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
#ifndef string_heap_interface_hash_typedef
#define string_heap_interface_hash_typedef
KHASH_INIT_TYPEDEF(string_heap_interface_hash_type, sjs_string, sji_interface*)
#endif
#ifndef string_heap_interface_hash_typedef
#define string_heap_interface_hash_typedef
KHASH_INIT_TYPEDEF(string_heap_interface_hash_type, sjs_string, sji_interface*)
#endif
int32_t result1;
sjs_string sjt_call1 = { -1 };
sjs_string sjt_call2 = { -1 };
sjs_string sjt_call3 = { -1 };
sjs_class* sjt_cast1 = 0;
sjs_string* sjt_functionParam2;
sji_interface* sjt_functionParam3 = 0;
sjs_string* sjt_functionParam4;
sjs_string* sjt_functionParam5;
bool sjt_ifElse1;
bool sjt_ifElse2;
sjs_string* sjt_isEmpty1;
sji_interface* sjt_isEmpty2;
int32_t sjt_math1;
int32_t sjt_math2;
int32_t sjt_negate1;
sjs_hash_string_heap_interface* sjt_parent2;
sjs_hash_string_heap_interface* sjt_parent3;
sjs_string sjt_value1 = { -1 };
sjs_string sjt_value2 = { -1 };
sjs_hash_string_heap_interface sjv_a = { -1 };
sji_interface* sjv_b = 0;
void* sjv_emptystringdata;
float sjv_f32_pi;
int32_t sjv_i32_maxvalue;
int32_t sjv_i32_minvalue;
uint32_t sjv_u32_maxvalue;

void sjf_array_char(sjs_array_char* _this);
void sjf_array_char_copy(sjs_array_char* _this, sjs_array_char* _from);
void sjf_array_char_destroy(sjs_array_char* _this);
void sjf_array_char_heap(sjs_array_char* _this);
void sjf_array_char_isequal(sjs_array_char* _parent, sjs_array_char* test, bool* _return);
void sjf_class(sjs_class* _this);
sjs_object* sjf_class_asInterface(sjs_class* _this, int typeId);
sji_interface* sjf_class_as_sji_interface(sjs_class* _this);
void sjf_class_bob(sjs_class* _parent, sjs_string* _return);
void sjf_class_bob_heap(sjs_class* _parent, sjs_string** _return);
void sjf_class_copy(sjs_class* _this, sjs_class* _from);
void sjf_class_destroy(sjs_class* _this);
void sjf_class_heap(sjs_class* _this);
sjs_object* sjf_class_heap_asInterface(sjs_class* _this, int typeId);
sji_interface* sjf_class_heap_as_sji_interface(sjs_class* _this);
void sjf_debug_writeline(sjs_string* data);
void sjf_hash_string_heap_interface(sjs_hash_string_heap_interface* _this);
void sjf_hash_string_heap_interface_copy(sjs_hash_string_heap_interface* _this, sjs_hash_string_heap_interface* _from);
void sjf_hash_string_heap_interface_destroy(sjs_hash_string_heap_interface* _this);
void sjf_hash_string_heap_interface_getat_heap(sjs_hash_string_heap_interface* _parent, sjs_string* key, sji_interface** _return);
void sjf_hash_string_heap_interface_heap(sjs_hash_string_heap_interface* _this);
void sjf_hash_string_heap_interface_setat(sjs_hash_string_heap_interface* _parent, sjs_string* key, sji_interface* val);
void sjf_string(sjs_string* _this);
void sjf_string_copy(sjs_string* _this, sjs_string* _from);
void sjf_string_destroy(sjs_string* _this);
void sjf_string_hash(sjs_string* _parent, uint32_t* _return);
void sjf_string_heap(sjs_string* _this);
void sjf_string_isequal(sjs_string* _parent, sjs_string* test, bool* _return);
void sji_interface_copy(sji_interface* _this, sji_interface* _from);
void sji_interface_destroy(sji_interface* _this);
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
KHASH_INIT_FUNCTION(weakptr_hashtable_type, void*, delete_cb_list, 1, ptr_hash, ptr_isequal, )
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
KHASH_INIT_FUNCTION(ptr_hashtable_type, void*, int, 1, ptr_hash, ptr_isequal, )
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
#ifndef string_heap_interface_hash_function
#define string_heap_interface_hash_function
#if true
KHASH_INIT_FUNCTION(string_heap_interface_hash_type, sjs_string, sji_interface*, 1, sjf_string_hash, sjf_string_isequal, &)
#else
KHASH_INIT_FUNCTION(string_heap_interface_hash_type, sjs_string, sji_interface*, 1, sjf_string_hash, sjf_string_isequal, )
#endif
#endif
#ifndef string_heap_interface_hash_function
#define string_heap_interface_hash_function
#if true
KHASH_INIT_FUNCTION(string_heap_interface_hash_type, sjs_string, sji_interface*, 1, sjf_string_hash, sjf_string_isequal, &)
#else
KHASH_INIT_FUNCTION(string_heap_interface_hash_type, sjs_string, sji_interface*, 1, sjf_string_hash, sjf_string_isequal, )
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
            free((char*)_this->data);
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

void sjf_array_char_isequal(sjs_array_char* _parent, sjs_array_char* test, bool* _return) {
    if (_parent->count != test->count) {
        *_return = false;
    }
    bool result = memcmp(_parent->data, test->data, _parent->count * sizeof(char)) == 0;
    (*_return) = result;
;		
}

void sjf_class(sjs_class* _this) {
}

sjs_object* sjf_class_asInterface(sjs_class* _this, int typeId) {
    switch (typeId) {
        case sji_interface_typeId:  {
            return (sjs_object*)sjf_class_as_sji_interface(_this);
        }
    }

    return 0;
}

sji_interface* sjf_class_as_sji_interface(sjs_class* _this) {
    sji_interface* _interface;
    _interface = (sji_interface*)malloc(sizeof(sji_interface));
    _interface->_refCount = 1;
    _interface->_parent = (sjs_object*)_this;
    _interface->_parent->_refCount++;
    _interface->destroy = (void(*)(void*))sjf_class_destroy;
    _interface->asInterface = (sjs_object*(*)(sjs_object*,int))sjf_class_asInterface;
    _interface->bob = (void(*)(void*, sjs_string*))sjf_class_bob;
    _interface->bob_heap = (void(*)(void*, sjs_string**))sjf_class_bob_heap;

    return _interface;
}

void sjf_class_bob(sjs_class* _parent, sjs_string* _return) {
    _return->_refCount = 1;
    _return->count = 3;
    _return->data._refCount = 1;
    _return->data.datasize = 4;
    _return->data.data = (void*)sjg_string2;
    _return->data._isglobal = true;
    _return->data.count = 4;
    sjf_array_char(&_return->data);
    sjf_string(_return);
}

void sjf_class_bob_heap(sjs_class* _parent, sjs_string** _return) {
    (*_return) = (sjs_string*)malloc(sizeof(sjs_string));
    (*_return)->_refCount = 1;
    (*_return)->count = 3;
    (*_return)->data._refCount = 1;
    (*_return)->data.datasize = 4;
    (*_return)->data.data = (void*)sjg_string3;
    (*_return)->data._isglobal = true;
    (*_return)->data.count = 4;
    sjf_array_char(&(*_return)->data);
    sjf_string_heap((*_return));
}

void sjf_class_copy(sjs_class* _this, sjs_class* _from) {
}

void sjf_class_destroy(sjs_class* _this) {
}

void sjf_class_heap(sjs_class* _this) {
}

sjs_object* sjf_class_heap_asInterface(sjs_class* _this, int typeId) {
    switch (typeId) {
        case sji_interface_typeId:  {
            return (sjs_object*)sjf_class_heap_as_sji_interface(_this);
        }
    }

    return 0;
}

sji_interface* sjf_class_heap_as_sji_interface(sjs_class* _this) {
    sji_interface* _interface;
    _interface = (sji_interface*)malloc(sizeof(sji_interface));
    _interface->_refCount = 1;
    _interface->_parent = (sjs_object*)_this;
    _interface->_parent->_refCount++;
    _interface->destroy = (void(*)(void*))sjf_class_destroy;
    _interface->asInterface = (sjs_object*(*)(sjs_object*,int))sjf_class_heap_asInterface;
    _interface->bob = (void(*)(void*, sjs_string*))sjf_class_bob;
    _interface->bob_heap = (void(*)(void*, sjs_string**))sjf_class_bob_heap;

    return _interface;
}

void sjf_debug_writeline(sjs_string* data) {
    printf("%s\n", (char*)data->data.data);
}

void sjf_hash_string_heap_interface(sjs_hash_string_heap_interface* _this) {
    _this->_hash = kh_init(string_heap_interface_hash_type);
}

void sjf_hash_string_heap_interface_copy(sjs_hash_string_heap_interface* _this, sjs_hash_string_heap_interface* _from) {
    _this->_hash = _from->_hash;
    ptr_retain(_this->_hash);
}

void sjf_hash_string_heap_interface_destroy(sjs_hash_string_heap_interface* _this) {
    if (ptr_release(_this->_hash)) {
        kh_destroy(string_heap_interface_hash_type, _this->_hash);
    }
}

void sjf_hash_string_heap_interface_getat_heap(sjs_hash_string_heap_interface* _parent, sjs_string* key, sji_interface** _return) {
    khash_t(string_heap_interface_hash_type)* p = (khash_t(string_heap_interface_hash_type)*)_parent->_hash;
    #if true
    khiter_t k = kh_get(string_heap_interface_hash_type, p, *key);
    #else
    khiter_t k = kh_get(string_heap_interface_hash_type, p, key);
    #endif
    if (k == kh_end(p)) {
        (*_return) = 0;
if ((*_return) != 0) {
    (*_return)->_refCount++;
}

    }
    (*_return) = kh_val(p, k);
if ((*_return) != 0) {
    (*_return)->_refCount++;
}
;
}

void sjf_hash_string_heap_interface_heap(sjs_hash_string_heap_interface* _this) {
    _this->_hash = kh_init(string_heap_interface_hash_type);
}

void sjf_hash_string_heap_interface_setat(sjs_hash_string_heap_interface* _parent, sjs_string* key, sji_interface* val) {
    khash_t(string_heap_interface_hash_type)* p = (khash_t(string_heap_interface_hash_type)*)_parent->_hash;
    #if true
    khiter_t k = kh_get(string_heap_interface_hash_type, p, *key);
    #else
    khiter_t k = kh_get(string_heap_interface_hash_type, p, key);
    #endif
    if (k != kh_end(p)) {            
    kh_val(p, k)->_refCount--;
if (kh_val(p, k)->_refCount <= 0) {
    sji_interface_destroy(kh_val(p, k));
}
;
}
int ret;
#if true
k = kh_put(string_heap_interface_hash_type, _parent->_hash, *key, &ret);
#else
k = kh_put(string_heap_interface_hash_type, _parent->_hash, key, &ret);
#endif
if (!ret) kh_del(string_heap_interface_hash_type, p, k);
sjs_string t;
t._refCount = 1;
sjf_string_copy(&t, key);
;
kh_val(p, k) = val;
kh_val(p, k)->_refCount++;
;
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

void sjf_string_hash(sjs_string* _parent, uint32_t* _return) {
    (*_return) = kh_str_hash_func((char*)_parent->data.data);
;
}

void sjf_string_heap(sjs_string* _this) {
}

void sjf_string_isequal(sjs_string* _parent, sjs_string* test, bool* _return) {
    sjs_string* sjt_dot1;
    sjs_string* sjt_dot2;
    sjs_array_char* sjt_functionParam1;
    sjs_array_char* sjt_parent1;

    sjt_dot1 = _parent;
    sjt_parent1 = &(sjt_dot1)->data;
    sjt_dot2 = test;
    sjt_functionParam1 = &(sjt_dot2)->data;
    sjf_array_char_isequal(sjt_parent1, sjt_functionParam1, _return);
}

void sji_interface_copy(sji_interface* _this, sji_interface* _from) {
    _this->_refCount = 1;
    _this->_parent = _from->_parent;
    _this->_parent->_refCount++;
    _this->destroy = _from->destroy;
    _this->asInterface = _from->asInterface;
    _this->bob = _from->bob;
    _this->bob = _from->bob;
}

void sji_interface_destroy(sji_interface* _this) {
    _this->_parent->_refCount--;
    if (_this->_parent->_refCount <= 0) {
        _this->destroy(_this->_parent);
        free(_this->_parent);
    }
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
    sjv_a._refCount = 1;
    sjf_hash_string_heap_interface(&sjv_a);
    sjt_parent2 = &sjv_a;
    sjt_call1._refCount = 1;
    sjt_call1.count = 3;
    sjt_call1.data._refCount = 1;
    sjt_call1.data.datasize = 4;
    sjt_call1.data.data = (void*)sjg_string1;
    sjt_call1.data._isglobal = true;
    sjt_call1.data.count = 4;
    sjf_array_char(&sjt_call1.data);
    sjf_string(&sjt_call1);
    sjt_functionParam2 = &sjt_call1;
    sjt_cast1 = (sjs_class*)malloc(sizeof(sjs_class));
    sjt_cast1->_refCount = 1;
    sjf_class_heap(sjt_cast1);
    sjt_functionParam3 = (sji_interface*)sjf_class_heap_as_sji_interface(sjt_cast1);
    sjf_hash_string_heap_interface_setat(sjt_parent2, sjt_functionParam2, sjt_functionParam3);
    sjt_parent3 = &sjv_a;
    sjt_call2._refCount = 1;
    sjt_call2.count = 3;
    sjt_call2.data._refCount = 1;
    sjt_call2.data.datasize = 4;
    sjt_call2.data.data = (void*)sjg_string4;
    sjt_call2.data._isglobal = true;
    sjt_call2.data.count = 4;
    sjf_array_char(&sjt_call2.data);
    sjf_string(&sjt_call2);
    sjt_functionParam4 = &sjt_call2;
    sjf_hash_string_heap_interface_getat_heap(sjt_parent3, sjt_functionParam4, &sjv_b);
    sjt_isEmpty2 = sjv_b;
    sjt_ifElse2 = (sjt_isEmpty2 == 0);
    if (sjt_ifElse2) {
        sjt_isEmpty1 = 0;
    } else {
        sji_interface* sjt_parent4;

        sjt_parent4 = sjv_b;
        sjt_value1._refCount = 1;
        sjt_parent4->bob(sjt_parent4->_parent, &sjt_value1);
        sjt_isEmpty1 = (sjt_value1._refCount != -1 ? &sjt_value1 : 0);
    }

    sjt_ifElse1 = (sjt_isEmpty1 == 0);
    if (sjt_ifElse1) {
        sjt_call3._refCount = 1;
        sjt_call3.count = 9;
        sjt_call3.data._refCount = 1;
        sjt_call3.data.datasize = 10;
        sjt_call3.data.data = (void*)sjg_string5;
        sjt_call3.data._isglobal = true;
        sjt_call3.data.count = 10;
        sjf_array_char(&sjt_call3.data);
        sjf_string(&sjt_call3);
        sjt_functionParam5 = &sjt_call3;
    } else {
        bool sjt_ifElse3;
        sji_interface* sjt_isEmpty3;

        sjt_isEmpty3 = sjv_b;
        sjt_ifElse3 = (sjt_isEmpty3 == 0);
        if (sjt_ifElse3) {
            sjt_functionParam5 = 0;
        } else {
            sji_interface* sjt_parent5;

            sjt_parent5 = sjv_b;
            sjt_value2._refCount = 1;
            sjt_parent5->bob(sjt_parent5->_parent, &sjt_value2);
            sjt_functionParam5 = (sjt_value2._refCount != -1 ? &sjt_value2 : 0);
        }
    }

    sjf_debug_writeline(sjt_functionParam5);
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
        sjf_class_destroy(sjt_cast1);
    }
    sjt_functionParam3->_refCount--;
    if (sjt_functionParam3->_refCount <= 0) {
        sji_interface_destroy(sjt_functionParam3);
    }
    if (sjv_b != 0) {
        sjv_b->_refCount--;
        if (sjv_b->_refCount <= 0) {
            sji_interface_destroy(sjv_b);
        }
    }
    if (sjt_call1._refCount == 1) { sjf_string_destroy(&sjt_call1); }
    if (sjt_call2._refCount == 1) { sjf_string_destroy(&sjt_call2); }
    if (sjt_call3._refCount == 1) { sjf_string_destroy(&sjt_call3); }
    if (sjt_value1._refCount == 1) { sjf_string_destroy(&sjt_value1); }
    if (sjt_value2._refCount == 1) { sjf_string_destroy(&sjt_value2); }
    if (sjv_a._refCount == 1) { sjf_hash_string_heap_interface_destroy(&sjv_a); }
}