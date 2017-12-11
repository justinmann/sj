
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
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include FT_FREETYPE_H
#include FT_LCD_FILTER_H
#include FT_STROKER_H


/* memcmp, memset, strlen */
/* ptrdiff_t */
/* exit */
/* These macros use decltype or the earlier __typeof GNU extension.
As decltype is only available in newer compilers (VS2010 or gcc 4.3+
when compiling c++ source) this code uses whatever method is needed
or, for VS2008 where neither is available, uses casting workarounds. */
#if !defined(DECLTYPE) && !defined(NO_DECLTYPE)
#if defined(_MSC_VER)   /* MS compiler */
#if _MSC_VER >= 1600 && defined(__cplusplus)  /* VS2010 or newer in C++ mode */
#define DECLTYPE(x) (decltype(x))
#else                   /* VS2008 or older (or VS2010 in C mode) */
#define NO_DECLTYPE
#endif
#elif defined(__BORLANDC__) || defined(__ICCARM__) || defined(__LCC__) || defined(__WATCOMC__)
#define NO_DECLTYPE
#else                   /* GNU, Sun and other compilers */
#define DECLTYPE(x) (__typeof(x))
#endif
#endif
#ifdef NO_DECLTYPE
#define DECLTYPE(x)
#define DECLTYPE_ASSIGN(dst,src)                                                 \
do {                                                                             \
char **_da_dst = (char**)(&(dst));                                             \
*_da_dst = (char*)(src);                                                       \
} while (0)
#else
#define DECLTYPE_ASSIGN(dst,src)                                                 \
do {                                                                             \
(dst) = DECLTYPE(dst)(src);                                                    \
} while (0)
#endif
/* a number of the hash function use uint32_t which isn't defined on Pre VS2010 */
#if defined(_WIN32)
#if defined(_MSC_VER) && _MSC_VER >= 1600
#include <stdint.h>
#elif defined(__WATCOMC__) || defined(__MINGW32__) || defined(__CYGWIN__)
#include <stdint.h>
#else
typedef unsigned int uint32_t;
typedef unsigned char uint8_t;
#endif
#elif defined(__GNUC__) && !defined(__VXWORKS__)
#include <stdint.h>
#else
typedef unsigned int uint32_t;
typedef unsigned char uint8_t;
#endif
#ifndef uthash_malloc
#define uthash_malloc(sz) malloc(sz)      /* malloc fcn                      */
#endif
#ifndef uthash_free
#define uthash_free(ptr,sz) free(ptr)     /* free fcn                        */
#endif
#ifndef uthash_bzero
#define uthash_bzero(a,n) memset(a,'\0',n)
#endif
#ifndef uthash_memcmp
#define uthash_memcmp(a,b,n) memcmp(a,b,n)
#endif
#ifndef uthash_strlen
#define uthash_strlen(s) strlen(s)
#endif
#ifndef uthash_noexpand_fyi
#define uthash_noexpand_fyi(tbl)          /* can be defined to log noexpand  */
#endif
#ifndef uthash_expand_fyi
#define uthash_expand_fyi(tbl)            /* can be defined to log expands   */
#endif
#ifndef HASH_NONFATAL_OOM
#define HASH_NONFATAL_OOM 0
#endif
#if HASH_NONFATAL_OOM
/* malloc failures can be recovered from */
#ifndef uthash_nonfatal_oom
#define uthash_nonfatal_oom(obj) do {} while (0)    /* non-fatal OOM error */
#endif
#define HASH_RECORD_OOM(oomed) do { (oomed) = 1; } while (0)
#define IF_HASH_NONFATAL_OOM(x) x
#else
/* malloc failures result in lost memory, hash tables are unusable */
#ifndef uthash_fatal
#define uthash_fatal(msg) halt("Unknown")        /* fatal OOM error */
#endif
#define HASH_RECORD_OOM(oomed) uthash_fatal("out of memory")
#define IF_HASH_NONFATAL_OOM(x)
#endif
/* initial number of buckets */
#define HASH_INITIAL_NUM_BUCKETS 32U     /* initial number of buckets        */
#define HASH_INITIAL_NUM_BUCKETS_LOG2 5U /* lg2 of initial number of buckets */
#define HASH_BKT_CAPACITY_THRESH 10U     /* expand when bucket count reaches */
/* calculate the element whose hash handle address is hhp */
#define ELMT_FROM_HH(tbl,hhp) ((void*)(((char*)(hhp)) - ((tbl)->hho)))
/* calculate the hash handle from element address elp */
#define HH_FROM_ELMT(tbl,elp) ((UT_hash_handle *)(((char*)(elp)) + ((tbl)->hho)))
#define HASH_ROLLBACK_BKT(hh, head, itemptrhh)                                   \
do {                                                                             \
struct UT_hash_handle *_hd_hh_item = (itemptrhh);                              \
unsigned _hd_bkt;                                                              \
HASH_TO_BKT(_hd_hh_item->hashv, (head)->hh.tbl->num_buckets, _hd_bkt);         \
(head)->hh.tbl->buckets[_hd_bkt].count++;                                      \
_hd_hh_item->hh_next = NULL;                                                   \
_hd_hh_item->hh_prev = NULL;                                                   \
} while (0)
#define HASH_VALUE(keyptr,keylen,hashv)                                          \
do {                                                                             \
HASH_FCN(keyptr, keylen, hashv);                                               \
} while (0)
#define HASH_FIND_BYHASHVALUE(hh,head,keyptr,keylen,hashval,out)                 \
do {                                                                             \
(out) = NULL;                                                                  \
if (head) {                                                                    \
unsigned _hf_bkt;                                                            \
HASH_TO_BKT(hashval, (head)->hh.tbl->num_buckets, _hf_bkt);                  \
if (HASH_BLOOM_TEST((head)->hh.tbl, hashval) != 0) {                         \
HASH_FIND_IN_BKT((head)->hh.tbl, hh, (head)->hh.tbl->buckets[ _hf_bkt ], keyptr, keylen, hashval, out); \
}                                                                            \
}                                                                              \
} while (0)
#define HASH_FIND(hh,head,keyptr,keylen,out)                                     \
do {                                                                             \
unsigned _hf_hashv;                                                            \
HASH_VALUE(keyptr, keylen, _hf_hashv);                                         \
HASH_FIND_BYHASHVALUE(hh, head, keyptr, keylen, _hf_hashv, out);               \
} while (0)
#ifdef HASH_BLOOM
#define HASH_BLOOM_BITLEN (1UL << HASH_BLOOM)
#define HASH_BLOOM_BYTELEN (HASH_BLOOM_BITLEN/8UL) + (((HASH_BLOOM_BITLEN%8UL)!=0UL) ? 1UL : 0UL)
#define HASH_BLOOM_MAKE(tbl,oomed)                                               \
do {                                                                             \
(tbl)->bloom_nbits = HASH_BLOOM;                                               \
(tbl)->bloom_bv = (uint8_t*)uthash_malloc(HASH_BLOOM_BYTELEN);                 \
if (!(tbl)->bloom_bv) {                                                        \
HASH_RECORD_OOM(oomed);                                                      \
} else {                                                                       \
uthash_bzero((tbl)->bloom_bv, HASH_BLOOM_BYTELEN);                           \
(tbl)->bloom_sig = HASH_BLOOM_SIGNATURE;                                     \
}                                                                              \
} while (0)
#define HASH_BLOOM_FREE(tbl)                                                     \
do {                                                                             \
uthash_free((tbl)->bloom_bv, HASH_BLOOM_BYTELEN);                              \
} while (0)
#define HASH_BLOOM_BITSET(bv,idx) (bv[(idx)/8U] |= (1U << ((idx)%8U)))
#define HASH_BLOOM_BITTEST(bv,idx) (bv[(idx)/8U] & (1U << ((idx)%8U)))
#define HASH_BLOOM_ADD(tbl,hashv)                                                \
HASH_BLOOM_BITSET((tbl)->bloom_bv, ((hashv) & (uint32_t)((1UL << (tbl)->bloom_nbits) - 1U)))
#define HASH_BLOOM_TEST(tbl,hashv)                                               \
HASH_BLOOM_BITTEST((tbl)->bloom_bv, ((hashv) & (uint32_t)((1UL << (tbl)->bloom_nbits) - 1U)))
#else
#define HASH_BLOOM_MAKE(tbl,oomed)
#define HASH_BLOOM_FREE(tbl)
#define HASH_BLOOM_ADD(tbl,hashv)
#define HASH_BLOOM_TEST(tbl,hashv) (1)
#define HASH_BLOOM_BYTELEN 0U
#endif
#define HASH_MAKE_TABLE(hh,head,oomed)                                           \
do {                                                                             \
(head)->hh.tbl = (UT_hash_table*)uthash_malloc(sizeof(UT_hash_table));         \
if (!(head)->hh.tbl) {                                                         \
HASH_RECORD_OOM(oomed);                                                      \
} else {                                                                       \
uthash_bzero((head)->hh.tbl, sizeof(UT_hash_table));                         \
(head)->hh.tbl->tail = &((head)->hh);                                        \
(head)->hh.tbl->num_buckets = HASH_INITIAL_NUM_BUCKETS;                      \
(head)->hh.tbl->log2_num_buckets = HASH_INITIAL_NUM_BUCKETS_LOG2;            \
(head)->hh.tbl->hho = (char*)(&(head)->hh) - (char*)(head);                  \
(head)->hh.tbl->buckets = (UT_hash_bucket*)uthash_malloc(                    \
HASH_INITIAL_NUM_BUCKETS * sizeof(struct UT_hash_bucket));               \
(head)->hh.tbl->signature = HASH_SIGNATURE;                                  \
if (!(head)->hh.tbl->buckets) {                                              \
HASH_RECORD_OOM(oomed);                                                    \
uthash_free((head)->hh.tbl, sizeof(UT_hash_table));                        \
} else {                                                                     \
uthash_bzero((head)->hh.tbl->buckets,                                      \
HASH_INITIAL_NUM_BUCKETS * sizeof(struct UT_hash_bucket));             \
HASH_BLOOM_MAKE((head)->hh.tbl, oomed);                                    \
IF_HASH_NONFATAL_OOM(                                                      \
if (oomed) {                                                             \
uthash_free((head)->hh.tbl->buckets,                                   \
HASH_INITIAL_NUM_BUCKETS*sizeof(struct UT_hash_bucket));           \
uthash_free((head)->hh.tbl, sizeof(UT_hash_table));                    \
}                                                                        \
)                                                                          \
}                                                                            \
}                                                                              \
} while (0)
#define HASH_REPLACE_BYHASHVALUE_INORDER(hh,head,fieldname,keylen_in,hashval,add,replaced,cmpfcn) \
do {                                                                             \
(replaced) = NULL;                                                             \
HASH_FIND_BYHASHVALUE(hh, head, &((add)->fieldname), keylen_in, hashval, replaced); \
if (replaced) {                                                                \
HASH_DELETE(hh, head, replaced);                                             \
}                                                                              \
HASH_ADD_KEYPTR_BYHASHVALUE_INORDER(hh, head, &((add)->fieldname), keylen_in, hashval, add, cmpfcn); \
} while (0)
#define HASH_REPLACE_BYHASHVALUE(hh,head,fieldname,keylen_in,hashval,add,replaced) \
do {                                                                             \
(replaced) = NULL;                                                             \
HASH_FIND_BYHASHVALUE(hh, head, &((add)->fieldname), keylen_in, hashval, replaced); \
if (replaced) {                                                                \
HASH_DELETE(hh, head, replaced);                                             \
}                                                                              \
HASH_ADD_KEYPTR_BYHASHVALUE(hh, head, &((add)->fieldname), keylen_in, hashval, add); \
} while (0)
#define HASH_REPLACE(hh,head,fieldname,keylen_in,add,replaced)                   \
do {                                                                             \
unsigned _hr_hashv;                                                            \
HASH_VALUE(&((add)->fieldname), keylen_in, _hr_hashv);                         \
HASH_REPLACE_BYHASHVALUE(hh, head, fieldname, keylen_in, _hr_hashv, add, replaced); \
} while (0)
#define HASH_REPLACE_INORDER(hh,head,fieldname,keylen_in,add,replaced,cmpfcn)    \
do {                                                                             \
unsigned _hr_hashv;                                                            \
HASH_VALUE(&((add)->fieldname), keylen_in, _hr_hashv);                         \
HASH_REPLACE_BYHASHVALUE_INORDER(hh, head, fieldname, keylen_in, _hr_hashv, add, replaced, cmpfcn); \
} while (0)
#define HASH_APPEND_LIST(hh, head, add)                                          \
do {                                                                             \
(add)->hh.next = NULL;                                                         \
(add)->hh.prev = ELMT_FROM_HH((head)->hh.tbl, (head)->hh.tbl->tail);           \
(head)->hh.tbl->tail->next = (add);                                            \
(head)->hh.tbl->tail = &((add)->hh);                                           \
} while (0)
#define HASH_AKBI_INNER_LOOP(hh,head,add,cmpfcn)                                 \
do {                                                                             \
do {                                                                           \
if (cmpfcn(DECLTYPE(head)(_hs_iter), add) > 0) {                             \
break;                                                                     \
}                                                                            \
} while ((_hs_iter = HH_FROM_ELMT((head)->hh.tbl, _hs_iter)->next));           \
} while (0)
#ifdef NO_DECLTYPE
#undef HASH_AKBI_INNER_LOOP
#define HASH_AKBI_INNER_LOOP(hh,head,add,cmpfcn)                                 \
do {                                                                             \
char *_hs_saved_head = (char*)(head);                                          \
do {                                                                           \
DECLTYPE_ASSIGN(head, _hs_iter);                                             \
if (cmpfcn(head, add) > 0) {                                                 \
DECLTYPE_ASSIGN(head, _hs_saved_head);                                     \
break;                                                                     \
}                                                                            \
DECLTYPE_ASSIGN(head, _hs_saved_head);                                       \
} while ((_hs_iter = HH_FROM_ELMT((head)->hh.tbl, _hs_iter)->next));           \
} while (0)
#endif
#if HASH_NONFATAL_OOM
#define HASH_ADD_TO_TABLE(hh,head,keyptr,keylen_in,hashval,add,oomed)            \
do {                                                                             \
if (!(oomed)) {                                                                \
unsigned _ha_bkt;                                                            \
(head)->hh.tbl->num_items++;                                                 \
HASH_TO_BKT(hashval, (head)->hh.tbl->num_buckets, _ha_bkt);                  \
HASH_ADD_TO_BKT((head)->hh.tbl->buckets[_ha_bkt], hh, &(add)->hh, oomed);    \
if (oomed) {                                                                 \
HASH_ROLLBACK_BKT(hh, head, &(add)->hh);                                   \
HASH_DELETE_HH(hh, head, &(add)->hh);                                      \
(add)->hh.tbl = NULL;                                                      \
uthash_nonfatal_oom(add);                                                  \
} else {                                                                     \
HASH_BLOOM_ADD((head)->hh.tbl, hashval);                                   \
HASH_EMIT_KEY(hh, head, keyptr, keylen_in);                                \
}                                                                            \
} else {                                                                       \
(add)->hh.tbl = NULL;                                                        \
uthash_nonfatal_oom(add);                                                    \
}                                                                              \
} while (0)
#else
#define HASH_ADD_TO_TABLE(hh,head,keyptr,keylen_in,hashval,add,oomed)            \
do {                                                                             \
unsigned _ha_bkt;                                                              \
(head)->hh.tbl->num_items++;                                                   \
HASH_TO_BKT(hashval, (head)->hh.tbl->num_buckets, _ha_bkt);                    \
HASH_ADD_TO_BKT((head)->hh.tbl->buckets[_ha_bkt], hh, &(add)->hh, oomed);      \
HASH_BLOOM_ADD((head)->hh.tbl, hashval);                                       \
HASH_EMIT_KEY(hh, head, keyptr, keylen_in);                                    \
} while (0)
#endif
#define HASH_ADD_KEYPTR_BYHASHVALUE_INORDER(hh,head,keyptr,keylen_in,hashval,add,cmpfcn) \
do {                                                                             \
IF_HASH_NONFATAL_OOM( int _ha_oomed = 0; )                                     \
(add)->hh.hashv = (hashval);                                                   \
(add)->hh.key = (char*) (keyptr);                                              \
(add)->hh.keylen = (unsigned) (keylen_in);                                     \
if (!(head)) {                                                                 \
(add)->hh.next = NULL;                                                       \
(add)->hh.prev = NULL;                                                       \
HASH_MAKE_TABLE(hh, add, _ha_oomed);                                         \
IF_HASH_NONFATAL_OOM( if (!_ha_oomed) { )                                    \
(head) = (add);                                                            \
IF_HASH_NONFATAL_OOM( } )                                                    \
} else {                                                                       \
void *_hs_iter = (head);                                                     \
(add)->hh.tbl = (head)->hh.tbl;                                              \
HASH_AKBI_INNER_LOOP(hh, head, add, cmpfcn);                                 \
if (_hs_iter) {                                                              \
(add)->hh.next = _hs_iter;                                                 \
if (((add)->hh.prev = HH_FROM_ELMT((head)->hh.tbl, _hs_iter)->prev)) {     \
HH_FROM_ELMT((head)->hh.tbl, (add)->hh.prev)->next = (add);              \
} else {                                                                   \
(head) = (add);                                                          \
}                                                                          \
HH_FROM_ELMT((head)->hh.tbl, _hs_iter)->prev = (add);                      \
} else {                                                                     \
HASH_APPEND_LIST(hh, head, add);                                           \
}                                                                            \
}                                                                              \
HASH_ADD_TO_TABLE(hh, head, keyptr, keylen_in, hashval, add, _ha_oomed);       \
HASH_FSCK(hh, head, "HASH_ADD_KEYPTR_BYHASHVALUE_INORDER");                    \
} while (0)
#define HASH_ADD_KEYPTR_INORDER(hh,head,keyptr,keylen_in,add,cmpfcn)             \
do {                                                                             \
unsigned _hs_hashv;                                                            \
HASH_VALUE(keyptr, keylen_in, _hs_hashv);                                      \
HASH_ADD_KEYPTR_BYHASHVALUE_INORDER(hh, head, keyptr, keylen_in, _hs_hashv, add, cmpfcn); \
} while (0)
#define HASH_ADD_BYHASHVALUE_INORDER(hh,head,fieldname,keylen_in,hashval,add,cmpfcn) \
HASH_ADD_KEYPTR_BYHASHVALUE_INORDER(hh, head, &((add)->fieldname), keylen_in, hashval, add, cmpfcn)
#define HASH_ADD_INORDER(hh,head,fieldname,keylen_in,add,cmpfcn)                 \
HASH_ADD_KEYPTR_INORDER(hh, head, &((add)->fieldname), keylen_in, add, cmpfcn)
#define HASH_ADD_KEYPTR_BYHASHVALUE(hh,head,keyptr,keylen_in,hashval,add)        \
do {                                                                             \
IF_HASH_NONFATAL_OOM( int _ha_oomed = 0; )                                     \
(add)->hh.hashv = (hashval);                                                   \
(add)->hh.key = (char*) (keyptr);                                              \
(add)->hh.keylen = (unsigned) (keylen_in);                                     \
if (!(head)) {                                                                 \
(add)->hh.next = NULL;                                                       \
(add)->hh.prev = NULL;                                                       \
HASH_MAKE_TABLE(hh, add, _ha_oomed);                                         \
IF_HASH_NONFATAL_OOM( if (!_ha_oomed) { )                                    \
(head) = (add);                                                            \
IF_HASH_NONFATAL_OOM( } )                                                    \
} else {                                                                       \
(add)->hh.tbl = (head)->hh.tbl;                                              \
HASH_APPEND_LIST(hh, head, add);                                             \
}                                                                              \
HASH_ADD_TO_TABLE(hh, head, keyptr, keylen_in, hashval, add, _ha_oomed);       \
HASH_FSCK(hh, head, "HASH_ADD_KEYPTR_BYHASHVALUE");                            \
} while (0)
#define HASH_ADD_KEYPTR(hh,head,keyptr,keylen_in,add)                            \
do {                                                                             \
unsigned _ha_hashv;                                                            \
HASH_VALUE(keyptr, keylen_in, _ha_hashv);                                      \
HASH_ADD_KEYPTR_BYHASHVALUE(hh, head, keyptr, keylen_in, _ha_hashv, add);      \
} while (0)
#define HASH_ADD_BYHASHVALUE(hh,head,fieldname,keylen_in,hashval,add)            \
HASH_ADD_KEYPTR_BYHASHVALUE(hh, head, &((add)->fieldname), keylen_in, hashval, add)
#define HASH_ADD(hh,head,fieldname,keylen_in,add)                                \
HASH_ADD_KEYPTR(hh, head, &((add)->fieldname), keylen_in, add)
#define HASH_TO_BKT(hashv,num_bkts,bkt)                                          \
do {                                                                             \
bkt = ((hashv) & ((num_bkts) - 1U));                                           \
} while (0)
/* delete "delptr" from the hash table.
* "the usual" patch-up process for the app-order doubly-linked-list.
* The use of _hd_hh_del below deserves special explanation.
* These used to be expressed using (delptr) but that led to a bug
* if someone used the same symbol for the head and deletee, like
*  HASH_DELETE(hh,users,users);
* We want that to work, but by changing the head (users) below
* we were forfeiting our ability to further refer to the deletee (users)
* in the patch-up process. Solution: use scratch space to
* copy the deletee pointer, then the latter references are via that
* scratch pointer rather than through the repointed (users) symbol.
*/
#define HASH_DELETE(hh,head,delptr)                                              \
HASH_DELETE_HH(hh, head, &(delptr)->hh)
#define HASH_DELETE_HH(hh,head,delptrhh)                                         \
do {                                                                             \
struct UT_hash_handle *_hd_hh_del = (delptrhh);                                \
if ((_hd_hh_del->prev == NULL) && (_hd_hh_del->next == NULL)) {                \
HASH_BLOOM_FREE((head)->hh.tbl);                                             \
uthash_free((head)->hh.tbl->buckets,                                         \
(head)->hh.tbl->num_buckets * sizeof(struct UT_hash_bucket));    \
uthash_free((head)->hh.tbl, sizeof(UT_hash_table));                          \
(head) = NULL;                                                               \
} else {                                                                       \
unsigned _hd_bkt;                                                            \
if (_hd_hh_del == (head)->hh.tbl->tail) {                                    \
(head)->hh.tbl->tail = HH_FROM_ELMT((head)->hh.tbl, _hd_hh_del->prev);     \
}                                                                            \
if (_hd_hh_del->prev != NULL) {                                              \
HH_FROM_ELMT((head)->hh.tbl, _hd_hh_del->prev)->next = _hd_hh_del->next;   \
} else {                                                                     \
DECLTYPE_ASSIGN(head, _hd_hh_del->next);                                   \
}                                                                            \
if (_hd_hh_del->next != NULL) {                                              \
HH_FROM_ELMT((head)->hh.tbl, _hd_hh_del->next)->prev = _hd_hh_del->prev;   \
}                                                                            \
HASH_TO_BKT(_hd_hh_del->hashv, (head)->hh.tbl->num_buckets, _hd_bkt);        \
HASH_DEL_IN_BKT((head)->hh.tbl->buckets[_hd_bkt], _hd_hh_del);               \
(head)->hh.tbl->num_items--;                                                 \
}                                                                              \
HASH_FSCK(hh, head, "HASH_DELETE_HH");                                         \
} while (0)
/* convenience forms of HASH_FIND/HASH_ADD/HASH_DEL */
#define HASH_FIND_STR(head,findstr,out)                                          \
HASH_FIND(hh,head,findstr,(unsigned)uthash_strlen(findstr),out)
#define HASH_ADD_STR(head,strfield,add)                                          \
HASH_ADD(hh,head,strfield[0],(unsigned)uthash_strlen(add->strfield),add)
#define HASH_REPLACE_STR(head,strfield,add,replaced)                             \
HASH_REPLACE(hh,head,strfield[0],(unsigned)uthash_strlen(add->strfield),add,replaced)
#define HASH_FIND_INT(head,findint,out)                                          \
HASH_FIND(hh,head,findint,sizeof(int),out)
#define HASH_ADD_INT(head,intfield,add)                                          \
HASH_ADD(hh,head,intfield,sizeof(int),add)
#define HASH_REPLACE_INT(head,intfield,add,replaced)                             \
HASH_REPLACE(hh,head,intfield,sizeof(int),add,replaced)
#define HASH_FIND_PTR(head,findptr,out)                                          \
HASH_FIND(hh,head,findptr,sizeof(void *),out)
#define HASH_ADD_PTR(head,ptrfield,add)                                          \
HASH_ADD(hh,head,ptrfield,sizeof(void *),add)
#define HASH_REPLACE_PTR(head,ptrfield,add,replaced)                             \
HASH_REPLACE(hh,head,ptrfield,sizeof(void *),add,replaced)
#define HASH_DEL(head,delptr)                                                    \
HASH_DELETE(hh,head,delptr)
/* HASH_FSCK checks hash integrity on every add/delete when HASH_DEBUG is defined.
* This is for uthash developer only; it compiles away if HASH_DEBUG isn't defined.
*/
#ifdef HASH_DEBUG
#define HASH_OOPS(...) do { halt(__VA_ARGS__); } while (0)
#define HASH_FSCK(hh,head,where)                                                 \
do {                                                                             \
struct UT_hash_handle *_thh;                                                   \
if (head) {                                                                    \
unsigned _bkt_i;                                                             \
unsigned _count = 0;                                                         \
char *_prev;                                                                 \
for (_bkt_i = 0; _bkt_i < (head)->hh.tbl->num_buckets; ++_bkt_i) {           \
unsigned _bkt_count = 0;                                                   \
_thh = (head)->hh.tbl->buckets[_bkt_i].hh_head;                            \
_prev = NULL;                                                              \
while (_thh) {                                                             \
if (_prev != (char*)(_thh->hh_prev)) {                                   \
HASH_OOPS("%s: invalid hh_prev %p, actual %p\n",                       \
(where), (void*)_thh->hh_prev, (void*)_prev);                      \
}                                                                        \
_bkt_count++;                                                            \
_prev = (char*)(_thh);                                                   \
_thh = _thh->hh_next;                                                    \
}                                                                          \
_count += _bkt_count;                                                      \
if ((head)->hh.tbl->buckets[_bkt_i].count !=  _bkt_count) {                \
HASH_OOPS("%s: invalid bucket count %u, actual %u\n",                    \
(where), (head)->hh.tbl->buckets[_bkt_i].count, _bkt_count);         \
}                                                                          \
}                                                                            \
if (_count != (head)->hh.tbl->num_items) {                                   \
HASH_OOPS("%s: invalid hh item count %u, actual %u\n",                     \
(where), (head)->hh.tbl->num_items, _count);                           \
}                                                                            \
_count = 0;                                                                  \
_prev = NULL;                                                                \
_thh =  &(head)->hh;                                                         \
while (_thh) {                                                               \
_count++;                                                                  \
if (_prev != (char*)_thh->prev) {                                          \
HASH_OOPS("%s: invalid prev %p, actual %p\n",                            \
(where), (void*)_thh->prev, (void*)_prev);                           \
}                                                                          \
_prev = (char*)ELMT_FROM_HH((head)->hh.tbl, _thh);                         \
_thh = (_thh->next ? HH_FROM_ELMT((head)->hh.tbl, _thh->next) : NULL);     \
}                                                                            \
if (_count != (head)->hh.tbl->num_items) {                                   \
HASH_OOPS("%s: invalid app item count %u, actual %u\n",                    \
(where), (head)->hh.tbl->num_items, _count);                           \
}                                                                            \
}                                                                              \
} while (0)
#else
#define HASH_FSCK(hh,head,where)
#endif
/* When compiled with -DHASH_EMIT_KEYS, length-prefixed keys are emitted to
* the descriptor to which this macro is defined for tuning the hash function.
* The app can #include <unistd.h> to get the prototype for write(2). */
#ifdef HASH_EMIT_KEYS
#define HASH_EMIT_KEY(hh,head,keyptr,fieldlen)                                   \
do {                                                                             \
unsigned _klen = fieldlen;                                                     \
write(HASH_EMIT_KEYS, &_klen, sizeof(_klen));                                  \
write(HASH_EMIT_KEYS, keyptr, (unsigned long)fieldlen);                        \
} while (0)
#else
#define HASH_EMIT_KEY(hh,head,keyptr,fieldlen)
#endif
/* default to Jenkin's hash unless overridden e.g. DHASH_FUNCTION=HASH_SAX */
#ifdef HASH_FUNCTION
#define HASH_FCN HASH_FUNCTION
#else
#define HASH_FCN HASH_JEN
#endif
/* The Bernstein hash function, used in Perl prior to v5.6. Note (x<<5+x)=x*33. */
#define HASH_BER(key,keylen,hashv)                                               \
do {                                                                             \
unsigned _hb_keylen = (unsigned)keylen;                                        \
const unsigned char *_hb_key = (const unsigned char*)(key);                    \
(hashv) = 0;                                                                   \
while (_hb_keylen-- != 0U) {                                                   \
(hashv) = (((hashv) << 5) + (hashv)) + *_hb_key++;                           \
}                                                                              \
} while (0)
/* SAX/FNV/OAT/JEN hash functions are macro variants of those listed at
* http://eternallyconfuzzled.com/tuts/algorithms/jsw_tut_hashing.aspx */
#define HASH_SAX(key,keylen,hashv)                                               \
do {                                                                             \
unsigned _sx_i;                                                                \
const unsigned char *_hs_key = (const unsigned char*)(key);                    \
hashv = 0;                                                                     \
for (_sx_i=0; _sx_i < keylen; _sx_i++) {                                       \
hashv ^= (hashv << 5) + (hashv >> 2) + _hs_key[_sx_i];                       \
}                                                                              \
} while (0)
/* FNV-1a variation */
#define HASH_FNV(key,keylen,hashv)                                               \
do {                                                                             \
unsigned _fn_i;                                                                \
const unsigned char *_hf_key = (const unsigned char*)(key);                    \
(hashv) = 2166136261U;                                                         \
for (_fn_i=0; _fn_i < keylen; _fn_i++) {                                       \
hashv = hashv ^ _hf_key[_fn_i];                                              \
hashv = hashv * 16777619U;                                                   \
}                                                                              \
} while (0)
#define HASH_OAT(key,keylen,hashv)                                               \
do {                                                                             \
unsigned _ho_i;                                                                \
const unsigned char *_ho_key=(const unsigned char*)(key);                      \
hashv = 0;                                                                     \
for(_ho_i=0; _ho_i < keylen; _ho_i++) {                                        \
hashv += _ho_key[_ho_i];                                                   \
hashv += (hashv << 10);                                                    \
hashv ^= (hashv >> 6);                                                     \
}                                                                              \
hashv += (hashv << 3);                                                         \
hashv ^= (hashv >> 11);                                                        \
hashv += (hashv << 15);                                                        \
} while (0)
#define HASH_JEN_MIX(a,b,c)                                                      \
do {                                                                             \
a -= b; a -= c; a ^= ( c >> 13 );                                              \
b -= c; b -= a; b ^= ( a << 8 );                                               \
c -= a; c -= b; c ^= ( b >> 13 );                                              \
a -= b; a -= c; a ^= ( c >> 12 );                                              \
b -= c; b -= a; b ^= ( a << 16 );                                              \
c -= a; c -= b; c ^= ( b >> 5 );                                               \
a -= b; a -= c; a ^= ( c >> 3 );                                               \
b -= c; b -= a; b ^= ( a << 10 );                                              \
c -= a; c -= b; c ^= ( b >> 15 );                                              \
} while (0)
#define HASH_JEN(key,keylen,hashv)                                               \
do {                                                                             \
unsigned _hj_i,_hj_j,_hj_k;                                                    \
unsigned const char *_hj_key=(unsigned const char*)(key);                      \
hashv = 0xfeedbeefu;                                                           \
_hj_i = _hj_j = 0x9e3779b9u;                                                   \
_hj_k = (unsigned)(keylen);                                                    \
while (_hj_k >= 12U) {                                                         \
_hj_i +=    (_hj_key[0] + ( (unsigned)_hj_key[1] << 8 )                      \
+ ( (unsigned)_hj_key[2] << 16 )                                         \
+ ( (unsigned)_hj_key[3] << 24 ) );                                      \
_hj_j +=    (_hj_key[4] + ( (unsigned)_hj_key[5] << 8 )                      \
+ ( (unsigned)_hj_key[6] << 16 )                                         \
+ ( (unsigned)_hj_key[7] << 24 ) );                                      \
hashv += (_hj_key[8] + ( (unsigned)_hj_key[9] << 8 )                         \
+ ( (unsigned)_hj_key[10] << 16 )                                        \
+ ( (unsigned)_hj_key[11] << 24 ) );                                     \
\
HASH_JEN_MIX(_hj_i, _hj_j, hashv);                                          \
\
_hj_key += 12;                                                              \
_hj_k -= 12U;                                                               \
}                                                                              \
hashv += (unsigned)(keylen);                                                   \
switch ( _hj_k ) {                                                             \
case 11: hashv += ( (unsigned)_hj_key[10] << 24 ); /* FALLTHROUGH */         \
case 10: hashv += ( (unsigned)_hj_key[9] << 16 );  /* FALLTHROUGH */         \
case 9:  hashv += ( (unsigned)_hj_key[8] << 8 );   /* FALLTHROUGH */         \
case 8:  _hj_j += ( (unsigned)_hj_key[7] << 24 );  /* FALLTHROUGH */         \
case 7:  _hj_j += ( (unsigned)_hj_key[6] << 16 );  /* FALLTHROUGH */         \
case 6:  _hj_j += ( (unsigned)_hj_key[5] << 8 );   /* FALLTHROUGH */         \
case 5:  _hj_j += _hj_key[4];                      /* FALLTHROUGH */         \
case 4:  _hj_i += ( (unsigned)_hj_key[3] << 24 );  /* FALLTHROUGH */         \
case 3:  _hj_i += ( (unsigned)_hj_key[2] << 16 );  /* FALLTHROUGH */         \
case 2:  _hj_i += ( (unsigned)_hj_key[1] << 8 );   /* FALLTHROUGH */         \
case 1:  _hj_i += _hj_key[0];                                                \
}                                                                              \
HASH_JEN_MIX(_hj_i, _hj_j, hashv);                                             \
} while (0)
/* The Paul Hsieh hash function */
#undef get16bits
#if (defined(__GNUC__) && defined(__i386__)) || defined(__WATCOMC__)             \
|| defined(_MSC_VER) || defined (__BORLANDC__) || defined (__TURBOC__)
#define get16bits(d) (*((const uint16_t *) (d)))
#endif
#if !defined (get16bits)
#define get16bits(d) ((((uint32_t)(((const uint8_t *)(d))[1])) << 8)             \
+(uint32_t)(((const uint8_t *)(d))[0]) )
#endif
#define HASH_SFH(key,keylen,hashv)                                               \
do {                                                                             \
unsigned const char *_sfh_key=(unsigned const char*)(key);                     \
uint32_t _sfh_tmp, _sfh_len = (uint32_t)keylen;                                \
\
unsigned _sfh_rem = _sfh_len & 3U;                                             \
_sfh_len >>= 2;                                                                \
hashv = 0xcafebabeu;                                                           \
\
/* Main loop */                                                                \
for (;_sfh_len > 0U; _sfh_len--) {                                             \
hashv    += get16bits (_sfh_key);                                            \
_sfh_tmp  = ((uint32_t)(get16bits (_sfh_key+2)) << 11) ^ hashv;              \
hashv     = (hashv << 16) ^ _sfh_tmp;                                        \
_sfh_key += 2U*sizeof (uint16_t);                                            \
hashv    += hashv >> 11;                                                     \
}                                                                              \
\
/* Handle end cases */                                                         \
switch (_sfh_rem) {                                                            \
case 3: hashv += get16bits (_sfh_key);                                       \
hashv ^= hashv << 16;                                                \
hashv ^= (uint32_t)(_sfh_key[sizeof (uint16_t)]) << 18;              \
hashv += hashv >> 11;                                                \
break;                                                               \
case 2: hashv += get16bits (_sfh_key);                                       \
hashv ^= hashv << 11;                                                \
hashv += hashv >> 17;                                                \
break;                                                               \
case 1: hashv += *_sfh_key;                                                  \
hashv ^= hashv << 10;                                                \
hashv += hashv >> 1;                                                 \
}                                                                              \
\
/* Force "avalanching" of final 127 bits */                                    \
hashv ^= hashv << 3;                                                           \
hashv += hashv >> 5;                                                           \
hashv ^= hashv << 4;                                                           \
hashv += hashv >> 17;                                                          \
hashv ^= hashv << 25;                                                          \
hashv += hashv >> 6;                                                           \
} while (0)
#ifdef HASH_USING_NO_STRICT_ALIASING
/* The MurmurHash exploits some CPU's (x86,x86_64) tolerance for unaligned reads.
* For other types of CPU's (e.g. Sparc) an unaligned read causes a bus error.
* MurmurHash uses the faster approach only on CPU's where we know it's safe.
*
* Note the preprocessor built-in defines can be emitted using:
*
*   gcc -m64 -dM -E - < /dev/null                  (on gcc)
*   cc -## a.c (where a.c is a simple test file)   (Sun Studio)
*/
#if (defined(__i386__) || defined(__x86_64__)  || defined(_M_IX86))
#define MUR_GETBLOCK(p,i) p[i]
#else /* non intel */
#define MUR_PLUS0_ALIGNED(p) (((unsigned long)p & 3UL) == 0UL)
#define MUR_PLUS1_ALIGNED(p) (((unsigned long)p & 3UL) == 1UL)
#define MUR_PLUS2_ALIGNED(p) (((unsigned long)p & 3UL) == 2UL)
#define MUR_PLUS3_ALIGNED(p) (((unsigned long)p & 3UL) == 3UL)
#define WP(p) ((uint32_t*)((unsigned long)(p) & ~3UL))
#if (defined(__BIG_ENDIAN__) || defined(SPARC) || defined(__ppc__) || defined(__ppc64__))
#define MUR_THREE_ONE(p) ((((*WP(p))&0x00ffffff) << 8) | (((*(WP(p)+1))&0xff000000) >> 24))
#define MUR_TWO_TWO(p)   ((((*WP(p))&0x0000ffff) <<16) | (((*(WP(p)+1))&0xffff0000) >> 16))
#define MUR_ONE_THREE(p) ((((*WP(p))&0x000000ff) <<24) | (((*(WP(p)+1))&0xffffff00) >>  8))
#else /* assume little endian non-intel */
#define MUR_THREE_ONE(p) ((((*WP(p))&0xffffff00) >> 8) | (((*(WP(p)+1))&0x000000ff) << 24))
#define MUR_TWO_TWO(p)   ((((*WP(p))&0xffff0000) >>16) | (((*(WP(p)+1))&0x0000ffff) << 16))
#define MUR_ONE_THREE(p) ((((*WP(p))&0xff000000) >>24) | (((*(WP(p)+1))&0x00ffffff) <<  8))
#endif
#define MUR_GETBLOCK(p,i) (MUR_PLUS0_ALIGNED(p) ? ((p)[i]) :           \
(MUR_PLUS1_ALIGNED(p) ? MUR_THREE_ONE(p) : \
(MUR_PLUS2_ALIGNED(p) ? MUR_TWO_TWO(p) :  \
MUR_ONE_THREE(p))))
#endif
#define MUR_ROTL32(x,r) (((x) << (r)) | ((x) >> (32 - (r))))
#define MUR_FMIX(_h) \
do {                 \
_h ^= _h >> 16;    \
_h *= 0x85ebca6bu; \
_h ^= _h >> 13;    \
_h *= 0xc2b2ae35u; \
_h ^= _h >> 16;    \
} while (0)
#define HASH_MUR(key,keylen,hashv)                                     \
do {                                                                   \
const uint8_t *_mur_data = (const uint8_t*)(key);                    \
const int _mur_nblocks = (int)(keylen) / 4;                          \
uint32_t _mur_h1 = 0xf88D5353u;                                      \
uint32_t _mur_c1 = 0xcc9e2d51u;                                      \
uint32_t _mur_c2 = 0x1b873593u;                                      \
uint32_t _mur_k1 = 0;                                                \
const uint8_t *_mur_tail;                                            \
const uint32_t *_mur_blocks = (const uint32_t*)(_mur_data+(_mur_nblocks*4)); \
int _mur_i;                                                          \
for (_mur_i = -_mur_nblocks; _mur_i != 0; _mur_i++) {                \
_mur_k1 = MUR_GETBLOCK(_mur_blocks,_mur_i);                        \
_mur_k1 *= _mur_c1;                                                \
_mur_k1 = MUR_ROTL32(_mur_k1,15);                                  \
_mur_k1 *= _mur_c2;                                                \
\
_mur_h1 ^= _mur_k1;                                                \
_mur_h1 = MUR_ROTL32(_mur_h1,13);                                  \
_mur_h1 = (_mur_h1*5U) + 0xe6546b64u;                              \
}                                                                    \
_mur_tail = (const uint8_t*)(_mur_data + (_mur_nblocks*4));          \
_mur_k1=0;                                                           \
switch ((keylen) & 3U) {                                             \
case 0: break;                                                     \
case 3: _mur_k1 ^= (uint32_t)_mur_tail[2] << 16; /* FALLTHROUGH */ \
case 2: _mur_k1 ^= (uint32_t)_mur_tail[1] << 8;  /* FALLTHROUGH */ \
case 1: _mur_k1 ^= (uint32_t)_mur_tail[0];                         \
_mur_k1 *= _mur_c1;                                                \
_mur_k1 = MUR_ROTL32(_mur_k1,15);                                  \
_mur_k1 *= _mur_c2;                                                \
_mur_h1 ^= _mur_k1;                                                \
}                                                                    \
_mur_h1 ^= (uint32_t)(keylen);                                       \
MUR_FMIX(_mur_h1);                                                   \
hashv = _mur_h1;                                                     \
} while (0)
#endif  /* HASH_USING_NO_STRICT_ALIASING */
/* iterate over items in a known bucket to find desired item */
#define HASH_FIND_IN_BKT(tbl,hh,head,keyptr,keylen_in,hashval,out)               \
do {                                                                             \
if ((head).hh_head != NULL) {                                                  \
DECLTYPE_ASSIGN(out, ELMT_FROM_HH(tbl, (head).hh_head));                     \
} else {                                                                       \
(out) = NULL;                                                                \
}                                                                              \
while ((out) != NULL) {                                                        \
if ((out)->hh.hashv == (hashval) && (out)->hh.keylen == (keylen_in)) {       \
if (uthash_memcmp((out)->hh.key, keyptr, keylen_in) == 0) {                \
break;                                                                   \
}                                                                          \
}                                                                            \
if ((out)->hh.hh_next != NULL) {                                             \
DECLTYPE_ASSIGN(out, ELMT_FROM_HH(tbl, (out)->hh.hh_next));                \
} else {                                                                     \
(out) = NULL;                                                              \
}                                                                            \
}                                                                              \
} while (0)
/* add an item to a bucket  */
#define HASH_ADD_TO_BKT(head,hh,addhh,oomed)                                     \
do {                                                                             \
UT_hash_bucket *_ha_head = &(head);                                            \
_ha_head->count++;                                                             \
(addhh)->hh_next = _ha_head->hh_head;                                          \
(addhh)->hh_prev = NULL;                                                       \
if (_ha_head->hh_head != NULL) {                                               \
_ha_head->hh_head->hh_prev = (addhh);                                        \
}                                                                              \
_ha_head->hh_head = (addhh);                                                   \
if ((_ha_head->count >= ((_ha_head->expand_mult + 1U) * HASH_BKT_CAPACITY_THRESH)) \
&& !(addhh)->tbl->noexpand) {                                              \
HASH_EXPAND_BUCKETS(addhh,(addhh)->tbl, oomed);                              \
IF_HASH_NONFATAL_OOM(                                                        \
if (oomed) {                                                               \
HASH_DEL_IN_BKT(head,addhh);                                             \
}                                                                          \
)                                                                            \
}                                                                              \
} while (0)
/* remove an item from a given bucket */
#define HASH_DEL_IN_BKT(head,delhh)                                              \
do {                                                                             \
UT_hash_bucket *_hd_head = &(head);                                            \
_hd_head->count--;                                                             \
if (_hd_head->hh_head == (delhh)) {                                            \
_hd_head->hh_head = (delhh)->hh_next;                                        \
}                                                                              \
if ((delhh)->hh_prev) {                                                        \
(delhh)->hh_prev->hh_next = (delhh)->hh_next;                                \
}                                                                              \
if ((delhh)->hh_next) {                                                        \
(delhh)->hh_next->hh_prev = (delhh)->hh_prev;                                \
}                                                                              \
} while (0)
/* Bucket expansion has the effect of doubling the number of buckets
* and redistributing the items into the new buckets. Ideally the
* items will distribute more or less evenly into the new buckets
* (the extent to which this is true is a measure of the quality of
* the hash function as it applies to the key domain).
*
* With the items distributed into more buckets, the chain length
* (item count) in each bucket is reduced. Thus by expanding buckets
* the hash keeps a bound on the chain length. This bounded chain
* length is the essence of how a hash provides constant time lookup.
*
* The calculation of tbl->ideal_chain_maxlen below deserves some
* explanation. First, keep in mind that we're calculating the ideal
* maximum chain length based on the *new* (doubled) bucket count.
* In fractions this is just n/b (n=number of items,b=new num buckets).
* Since the ideal chain length is an integer, we want to calculate
* ceil(n/b). We don't depend on floating point arithmetic in this
* hash, so to calculate ceil(n/b) with integers we could write
*
*      ceil(n/b) = (n/b) + ((n%b)?1:0)
*
* and in fact a previous version of this hash did just that.
* But now we have improved things a bit by recognizing that b is
* always a power of two. We keep its base 2 log handy (call it lb),
* so now we can write this with a bit shift and logical AND:
*
*      ceil(n/b) = (n>>lb) + ( (n & (b-1)) ? 1:0)
*
*/
#define HASH_EXPAND_BUCKETS(hh,tbl,oomed)                                        \
do {                                                                             \
unsigned _he_bkt;                                                              \
unsigned _he_bkt_i;                                                            \
struct UT_hash_handle *_he_thh, *_he_hh_nxt;                                   \
UT_hash_bucket *_he_new_buckets, *_he_newbkt;                                  \
_he_new_buckets = (UT_hash_bucket*)uthash_malloc(                              \
2UL * (tbl)->num_buckets * sizeof(struct UT_hash_bucket));            \
if (!_he_new_buckets) {                                                        \
HASH_RECORD_OOM(oomed);                                                      \
} else {                                                                       \
uthash_bzero(_he_new_buckets,                                                \
2UL * (tbl)->num_buckets * sizeof(struct UT_hash_bucket));               \
(tbl)->ideal_chain_maxlen =                                                  \
((tbl)->num_items >> ((tbl)->log2_num_buckets+1U)) +                      \
((((tbl)->num_items & (((tbl)->num_buckets*2U)-1U)) != 0U) ? 1U : 0U);    \
(tbl)->nonideal_items = 0;                                                   \
for (_he_bkt_i = 0; _he_bkt_i < (tbl)->num_buckets; _he_bkt_i++) {           \
_he_thh = (tbl)->buckets[ _he_bkt_i ].hh_head;                             \
while (_he_thh != NULL) {                                                  \
_he_hh_nxt = _he_thh->hh_next;                                           \
HASH_TO_BKT(_he_thh->hashv, (tbl)->num_buckets * 2U, _he_bkt);           \
_he_newbkt = &(_he_new_buckets[_he_bkt]);                                \
if (++(_he_newbkt->count) > (tbl)->ideal_chain_maxlen) {                 \
(tbl)->nonideal_items++;                                               \
_he_newbkt->expand_mult = _he_newbkt->count / (tbl)->ideal_chain_maxlen; \
}                                                                        \
_he_thh->hh_prev = NULL;                                                 \
_he_thh->hh_next = _he_newbkt->hh_head;                                  \
if (_he_newbkt->hh_head != NULL) {                                       \
_he_newbkt->hh_head->hh_prev = _he_thh;                                \
}                                                                        \
_he_newbkt->hh_head = _he_thh;                                           \
_he_thh = _he_hh_nxt;                                                    \
}                                                                          \
}                                                                            \
uthash_free((tbl)->buckets, (tbl)->num_buckets * sizeof(struct UT_hash_bucket)); \
(tbl)->num_buckets *= 2U;                                                    \
(tbl)->log2_num_buckets++;                                                   \
(tbl)->buckets = _he_new_buckets;                                            \
(tbl)->ineff_expands = ((tbl)->nonideal_items > ((tbl)->num_items >> 1)) ?   \
((tbl)->ineff_expands+1U) : 0U;                                          \
if ((tbl)->ineff_expands > 1U) {                                             \
(tbl)->noexpand = 1;                                                       \
uthash_noexpand_fyi(tbl);                                                  \
}                                                                            \
uthash_expand_fyi(tbl);                                                      \
}                                                                              \
} while (0)
/* This is an adaptation of Simon Tatham's O(n log(n)) mergesort */
/* Note that HASH_SORT assumes the hash handle name to be hh.
* HASH_SRT was added to allow the hash handle name to be passed in. */
#define HASH_SORT(head,cmpfcn) HASH_SRT(hh,head,cmpfcn)
#define HASH_SRT(hh,head,cmpfcn)                                                 \
do {                                                                             \
unsigned _hs_i;                                                                \
unsigned _hs_looping,_hs_nmerges,_hs_insize,_hs_psize,_hs_qsize;               \
struct UT_hash_handle *_hs_p, *_hs_q, *_hs_e, *_hs_list, *_hs_tail;            \
if (head != NULL) {                                                            \
_hs_insize = 1;                                                              \
_hs_looping = 1;                                                             \
_hs_list = &((head)->hh);                                                    \
while (_hs_looping != 0U) {                                                  \
_hs_p = _hs_list;                                                          \
_hs_list = NULL;                                                           \
_hs_tail = NULL;                                                           \
_hs_nmerges = 0;                                                           \
while (_hs_p != NULL) {                                                    \
_hs_nmerges++;                                                           \
_hs_q = _hs_p;                                                           \
_hs_psize = 0;                                                           \
for (_hs_i = 0; _hs_i < _hs_insize; ++_hs_i) {                           \
_hs_psize++;                                                           \
_hs_q = ((_hs_q->next != NULL) ?                                       \
HH_FROM_ELMT((head)->hh.tbl, _hs_q->next) : NULL);                   \
if (_hs_q == NULL) {                                                   \
break;                                                               \
}                                                                      \
}                                                                        \
_hs_qsize = _hs_insize;                                                  \
while ((_hs_psize != 0U) || ((_hs_qsize != 0U) && (_hs_q != NULL))) {    \
if (_hs_psize == 0U) {                                                 \
_hs_e = _hs_q;                                                       \
_hs_q = ((_hs_q->next != NULL) ?                                     \
HH_FROM_ELMT((head)->hh.tbl, _hs_q->next) : NULL);                 \
_hs_qsize--;                                                         \
} else if ((_hs_qsize == 0U) || (_hs_q == NULL)) {                     \
_hs_e = _hs_p;                                                       \
if (_hs_p != NULL) {                                                 \
_hs_p = ((_hs_p->next != NULL) ?                                   \
HH_FROM_ELMT((head)->hh.tbl, _hs_p->next) : NULL);               \
}                                                                    \
_hs_psize--;                                                         \
} else if ((cmpfcn(                                                    \
DECLTYPE(head)(ELMT_FROM_HH((head)->hh.tbl, _hs_p)),             \
DECLTYPE(head)(ELMT_FROM_HH((head)->hh.tbl, _hs_q))              \
)) <= 0) {                                                       \
_hs_e = _hs_p;                                                       \
if (_hs_p != NULL) {                                                 \
_hs_p = ((_hs_p->next != NULL) ?                                   \
HH_FROM_ELMT((head)->hh.tbl, _hs_p->next) : NULL);               \
}                                                                    \
_hs_psize--;                                                         \
} else {                                                               \
_hs_e = _hs_q;                                                       \
_hs_q = ((_hs_q->next != NULL) ?                                     \
HH_FROM_ELMT((head)->hh.tbl, _hs_q->next) : NULL);                 \
_hs_qsize--;                                                         \
}                                                                      \
if ( _hs_tail != NULL ) {                                              \
_hs_tail->next = ((_hs_e != NULL) ?                                  \
ELMT_FROM_HH((head)->hh.tbl, _hs_e) : NULL);                       \
} else {                                                               \
_hs_list = _hs_e;                                                    \
}                                                                      \
if (_hs_e != NULL) {                                                   \
_hs_e->prev = ((_hs_tail != NULL) ?                                  \
ELMT_FROM_HH((head)->hh.tbl, _hs_tail) : NULL);                    \
}                                                                      \
_hs_tail = _hs_e;                                                      \
}                                                                        \
_hs_p = _hs_q;                                                           \
}                                                                          \
if (_hs_tail != NULL) {                                                    \
_hs_tail->next = NULL;                                                   \
}                                                                          \
if (_hs_nmerges <= 1U) {                                                   \
_hs_looping = 0;                                                         \
(head)->hh.tbl->tail = _hs_tail;                                         \
DECLTYPE_ASSIGN(head, ELMT_FROM_HH((head)->hh.tbl, _hs_list));           \
}                                                                          \
_hs_insize *= 2U;                                                          \
}                                                                            \
HASH_FSCK(hh, head, "HASH_SRT");                                             \
}                                                                              \
} while (0)
/* This function selects items from one hash into another hash.
* The end result is that the selected items have dual presence
* in both hashes. There is no copy of the items made; rather
* they are added into the new hash through a secondary hash
* hash handle that must be present in the structure. */
#define HASH_SELECT(hh_dst, dst, hh_src, src, cond)                              \
do {                                                                             \
unsigned _src_bkt, _dst_bkt;                                                   \
void *_last_elt = NULL, *_elt;                                                 \
UT_hash_handle *_src_hh, *_dst_hh, *_last_elt_hh=NULL;                         \
ptrdiff_t _dst_hho = ((char*)(&(dst)->hh_dst) - (char*)(dst));                 \
if ((src) != NULL) {                                                           \
for (_src_bkt=0; _src_bkt < (src)->hh_src.tbl->num_buckets; _src_bkt++) {    \
for (_src_hh = (src)->hh_src.tbl->buckets[_src_bkt].hh_head;               \
_src_hh != NULL;                                                         \
_src_hh = _src_hh->hh_next) {                                            \
_elt = ELMT_FROM_HH((src)->hh_src.tbl, _src_hh);                         \
if (cond(_elt)) {                                                        \
IF_HASH_NONFATAL_OOM( int _hs_oomed = 0; )                             \
_dst_hh = (UT_hash_handle*)(((char*)_elt) + _dst_hho);                 \
_dst_hh->key = _src_hh->key;                                           \
_dst_hh->keylen = _src_hh->keylen;                                     \
_dst_hh->hashv = _src_hh->hashv;                                       \
_dst_hh->prev = _last_elt;                                             \
_dst_hh->next = NULL;                                                  \
if (_last_elt_hh != NULL) {                                            \
_last_elt_hh->next = _elt;                                           \
}                                                                      \
if ((dst) == NULL) {                                                   \
DECLTYPE_ASSIGN(dst, _elt);                                          \
HASH_MAKE_TABLE(hh_dst, dst, _hs_oomed);                             \
IF_HASH_NONFATAL_OOM(                                                \
if (_hs_oomed) {                                                   \
uthash_nonfatal_oom(_elt);                                       \
(dst) = NULL;                                                    \
continue;                                                        \
}                                                                  \
)                                                                    \
} else {                                                               \
_dst_hh->tbl = (dst)->hh_dst.tbl;                                    \
}                                                                      \
HASH_TO_BKT(_dst_hh->hashv, _dst_hh->tbl->num_buckets, _dst_bkt);      \
HASH_ADD_TO_BKT(_dst_hh->tbl->buckets[_dst_bkt], hh_dst, _dst_hh, _hs_oomed); \
(dst)->hh_dst.tbl->num_items++;                                        \
IF_HASH_NONFATAL_OOM(                                                  \
if (_hs_oomed) {                                                     \
HASH_ROLLBACK_BKT(hh_dst, dst, _dst_hh);                           \
HASH_DELETE_HH(hh_dst, dst, _dst_hh);                              \
_dst_hh->tbl = NULL;                                               \
uthash_nonfatal_oom(_elt);                                         \
continue;                                                          \
}                                                                    \
)                                                                      \
HASH_BLOOM_ADD(_dst_hh->tbl, _dst_hh->hashv);                          \
_last_elt = _elt;                                                      \
_last_elt_hh = _dst_hh;                                                \
}                                                                        \
}                                                                          \
}                                                                            \
}                                                                              \
HASH_FSCK(hh_dst, dst, "HASH_SELECT");                                         \
} while (0)
#define HASH_CLEAR(hh,head)                                                      \
do {                                                                             \
if ((head) != NULL) {                                                          \
HASH_BLOOM_FREE((head)->hh.tbl);                                             \
uthash_free((head)->hh.tbl->buckets,                                         \
(head)->hh.tbl->num_buckets*sizeof(struct UT_hash_bucket));      \
uthash_free((head)->hh.tbl, sizeof(UT_hash_table));                          \
(head) = NULL;                                                               \
}                                                                              \
} while (0)
#define HASH_OVERHEAD(hh,head)                                                   \
(((head) != NULL) ? (                                                           \
(size_t)(((head)->hh.tbl->num_items   * sizeof(UT_hash_handle))   +             \
((head)->hh.tbl->num_buckets * sizeof(UT_hash_bucket))   +             \
sizeof(UT_hash_table)                                   +             \
(HASH_BLOOM_BYTELEN))) : 0U)
#ifdef NO_DECLTYPE
#define HASH_ITER(hh,head,el,tmp)                                                \
for(((el)=(head)), ((*(char**)(&(tmp)))=(char*)((head!=NULL)?(head)->hh.next:NULL)); \
(el) != NULL; ((el)=(tmp)), ((*(char**)(&(tmp)))=(char*)((tmp!=NULL)?(tmp)->hh.next:NULL)))
#else
#define HASH_ITER(hh,head,el,tmp)                                                \
for(((el)=(head)), ((tmp)=DECLTYPE(el)((head!=NULL)?(head)->hh.next:NULL));      \
(el) != NULL; ((el)=(tmp)), ((tmp)=DECLTYPE(el)((tmp!=NULL)?(tmp)->hh.next:NULL)))
#endif
/* obtain a count of items in the hash */
#define HASH_COUNT(head) HASH_CNT(hh,head)
#define HASH_CNT(hh,head) ((head != NULL)?((head)->hh.tbl->num_items):0U)
typedef struct UT_hash_bucket {
struct UT_hash_handle *hh_head;
unsigned count;
/* expand_mult is normally set to 0. In this situation, the max chain length
* threshold is enforced at its default value, HASH_BKT_CAPACITY_THRESH. (If
* the bucket's chain exceeds this length, bucket expansion is triggered).
* However, setting expand_mult to a non-zero value delays bucket expansion
* (that would be triggered by additions to this particular bucket)
* until its chain length reaches a *multiple* of HASH_BKT_CAPACITY_THRESH.
* (The multiplier is simply expand_mult+1). The whole idea of this
* multiplier is to reduce bucket expansions, since they are expensive, in
* situations where we know that a particular bucket tends to be overused.
* It is better to let its chain length grow to a longer yet-still-bounded
* value, than to do an O(n) bucket expansion too often.
*/
unsigned expand_mult;
} UT_hash_bucket;
/* random signature used only to find hash tables in external analysis */
#define HASH_SIGNATURE 0xa0111fe1u
#define HASH_BLOOM_SIGNATURE 0xb12220f2u
typedef struct UT_hash_table {
UT_hash_bucket *buckets;
unsigned num_buckets, log2_num_buckets;
unsigned num_items;
struct UT_hash_handle *tail; /* tail hh in app order, for fast append    */
ptrdiff_t hho; /* hash handle offset (byte pos of hash handle in element */
/* in an ideal situation (all buckets used equally), no bucket would have
* more than ceil(#items/#buckets) items. that's the ideal chain length. */
unsigned ideal_chain_maxlen;
/* nonideal_items is the number of items in the hash whose chain position
* exceeds the ideal chain maxlen. these items pay the penalty for an uneven
* hash distribution; reaching them in a chain traversal takes >ideal steps */
unsigned nonideal_items;
/* ineffective expands occur when a bucket doubling was performed, but
* afterward, more than half the items in the hash had nonideal chain
* positions. If this happens on two consecutive expansions we inhibit any
* further expansion, as it's not helping; this happens when the hash
* function isn't a good fit for the key domain. When expansion is inhibited
* the hash will still work, albeit no longer in constant time. */
unsigned ineff_expands, noexpand;
uint32_t signature; /* used only to find hash tables in external analysis */
#ifdef HASH_BLOOM
uint32_t bloom_sig; /* used only to test bloom exists in external analysis */
uint8_t *bloom_bv;
uint8_t bloom_nbits;
#endif
} UT_hash_table;
typedef struct UT_hash_handle {
struct UT_hash_table *tbl;
void *prev;                       /* prev element in app order      */
void *next;                       /* next element in app order      */
struct UT_hash_handle *hh_prev;   /* previous hh in bucket order    */
struct UT_hash_handle *hh_next;   /* next hh in bucket order        */
void *key;                        /* ptr to enclosing struct's key  */
unsigned keylen;                  /* enclosing struct's key len     */
unsigned hashv;                   /* result of hash-fcn(key)        */
} UT_hash_handle;


typedef struct vector_td vector_t;


typedef struct vertex_attribute_td vertex_attribute_t;


typedef struct vertex_buffer_td vertex_buffer_t;

typedef struct td_int32_option int32_option;
struct td_int32_option {
    bool isEmpty;
    int32_t value;
};
const int32_option int32_empty = { true };

typedef struct td_uint32_option uint32_option;
struct td_uint32_option {
    bool isEmpty;
    uint32_t value;
};
const uint32_option uint32_empty = { true };

typedef struct td_int64_option int64_option;
struct td_int64_option {
    bool isEmpty;
    int64_t value;
};
const int64_option int64_empty = { true };

typedef struct td_uint64_option uint64_option;
struct td_uint64_option {
    bool isEmpty;
    uint64_t value;
};
const uint64_option uint64_empty = { true };

typedef struct td_uintptr_option uintptr_option;
struct td_uintptr_option {
    bool isEmpty;
    uintptr_t value;
};
const uintptr_option uintptr_empty = { true };

typedef struct td_char_option char_option;
struct td_char_option {
    bool isEmpty;
    char value;
};
const char_option char_empty = { true };

typedef struct td_float_option float_option;
struct td_float_option {
    bool isEmpty;
    float value;
};
const float_option float_empty = { true };

typedef struct td_double_option double_option;
struct td_double_option {
    bool isEmpty;
    double value;
};
const double_option double_empty = { true };

const char* sjg_string1 = "shaders/v3f-c4f.vert";
const char* sjg_string10 = "shaders/v3f-n3f-phong.frag";
const char* sjg_string11 = "shaders/v3f-t2f-n3f-phong.vert";
const char* sjg_string12 = "shaders/v3f-t2f-n3f-phong.frag";
const char* sjg_string13 = "shaders/v3f-t2f-c4f.vert";
const char* sjg_string14 = "shaders/v3f-t2f-c4f.frag";
const char* sjg_string15 = "vertex:3f,tex_coord:2f,normal:3f";
const char* sjg_string16 = "assets/test.png";
const char* sjg_string2 = "shaders/v3f-c4f.frag";
const char* sjg_string3 = "shaders/v3f-t2f-c4f.vert";
const char* sjg_string4 = "shaders/blur-horizontal.frag";
const char* sjg_string5 = "shaders/v3f-t2f-c4f.vert";
const char* sjg_string6 = "shaders/blur-vertical.frag";
const char* sjg_string7 = "shaders/v3f-t2f.vert";
const char* sjg_string8 = "shaders/v3f-t2f.frag";
const char* sjg_string9 = "shaders/v3f-n3f-phong.vert";


typedef struct pointer_td pointer;
struct pointer_td {
    void* ptr;
    int refCount;
    UT_hash_handle hh;
};
pointer* g_pointers = 0;


typedef struct {
    float x, y, z;    // position
    float r, g, b, a; // color
} vertex3_color4_t;


typedef struct GLid_td GLid_s;
struct GLid_td {
    GLuint id;
    int refCount;
    UT_hash_handle hh;
};
GLid_s* g_GLids = 0;


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
#define sjs_windowRenderer_typeId 2
#define sjs_windowRenderer_heap_typeId 3
#define sjs_size_typeId 4
#define sjs_size_heap_typeId 5
#define sjs_mat4_typeId 6
#define sjs_mat4_heap_typeId 7
#define sjs_scene2d_typeId 8
#define sjs_scene2d_heap_typeId 9
#define sjs_anon1_typeId 10
#define sjs_anon1_heap_typeId 11
#define sjs_anon2_typeId 12
#define sjs_anon2_heap_typeId 13
#define sjs_anon3_typeId 14
#define sjs_anon3_heap_typeId 15
#define sjs_anon4_typeId 16
#define sjs_anon4_heap_typeId 17
#define sji_anon5_animation_typeId 18
#define sjs_array_heap_animation_typeId 19
#define sjs_array_heap_animation_heap_typeId 20
#define sjs_list_heap_animation_typeId 21
#define sjs_list_heap_animation_heap_typeId 22
#define sjs_anon5_typeId 23
#define sjs_anon5_heap_typeId 24
#define sjs_anon6_typeId 25
#define sjs_anon6_heap_typeId 26
#define sjs_anon7_typeId 27
#define sjs_anon7_heap_typeId 28
#define sjs_anon8_typeId 29
#define sjs_anon8_heap_typeId 30
#define sjs_array_char_typeId 31
#define sjs_array_char_heap_typeId 32
#define sjs_string_typeId 33
#define sjs_string_heap_typeId 34
#define sjs_shader_typeId 35
#define sjs_shader_heap_typeId 36
#define sjs_anon9_typeId 37
#define sjs_anon9_heap_typeId 38
#define sjs_rect_typeId 39
#define sjs_rect_heap_typeId 40
#define sjs_point_typeId 41
#define sjs_point_heap_typeId 42
#define sji_element_typeId 43
#define sjs_array_heap_element_typeId 44
#define sjs_array_heap_element_heap_typeId 45
#define sjs_fillElement_typeId 46
#define sjs_fillElement_heap_typeId 47
#define sjs_vec3_typeId 48
#define sjs_vec3_heap_typeId 49
#define cb_vec3_void_typeId 50
#define cb_vec3_void_heap_typeId 51
#define sjs_animation_vec3_typeId 52
#define sjs_animation_vec3_heap_typeId 53
#define sji_scene3dElement_model_typeId 54
#define sjs_array_heap_model_typeId 55
#define sjs_array_heap_model_heap_typeId 56
#define cb_void_typeId 57
#define cb_void_heap_typeId 58
#define sjs_array_local_cb_void_typeId 59
#define sjs_array_local_cb_void_heap_typeId 60
#define sjs_list_local_cb_void_typeId 61
#define sjs_list_local_cb_void_heap_typeId 62
#define sjs_property_vec3_typeId 63
#define sjs_property_vec3_heap_typeId 64
#define sjs_color_typeId 65
#define sjs_color_heap_typeId 66
#define sjs_vec2_typeId 67
#define sjs_vec2_heap_typeId 68
#define sjs_vertex_location_texture_normal_typeId 69
#define sjs_vertex_location_texture_normal_heap_typeId 70
#define sjs_array_i32_typeId 71
#define sjs_array_i32_heap_typeId 72
#define sjs_array_vertex_location_texture_normal_typeId 73
#define sjs_array_vertex_location_texture_normal_heap_typeId 74
#define sjs_vertexBuffer_vertex_location_texture_normal_typeId 75
#define sjs_vertexBuffer_vertex_location_texture_normal_heap_typeId 76
#define sjs_scene3dElement_typeId 77
#define sjs_scene3dElement_heap_typeId 78
#define sjs_frameBuffer_typeId 79
#define sjs_frameBuffer_heap_typeId 80
#define sjs_scene2dModel_typeId 81
#define sjs_scene2dModel_heap_typeId 82
#define sjs_texture_typeId 83
#define sjs_texture_heap_typeId 84
#define sjs_margin_typeId 85
#define sjs_margin_heap_typeId 86
#define sjs_image_typeId 87
#define sjs_image_heap_typeId 88
#define sjs_imageRenderer_typeId 89
#define sjs_imageRenderer_heap_typeId 90
#define sjs_imageElement_typeId 91
#define sjs_imageElement_heap_typeId 92
#define sjs_boxRenderer_typeId 93
#define sjs_boxRenderer_heap_typeId 94
#define sjs_crossHairsElement_typeId 95
#define sjs_crossHairsElement_heap_typeId 96

typedef struct td_sjs_object sjs_object;
typedef struct td_sjs_windowRenderer sjs_windowRenderer;
typedef struct td_sjs_windowRenderer_heap sjs_windowRenderer_heap;
typedef struct td_sjs_size sjs_size;
typedef struct td_sjs_size_heap sjs_size_heap;
typedef struct td_sjs_mat4 sjs_mat4;
typedef struct td_sjs_mat4_heap sjs_mat4_heap;
typedef struct td_sjs_scene2d sjs_scene2d;
typedef struct td_sjs_scene2d_heap sjs_scene2d_heap;
typedef struct td_sjs_anon1 sjs_anon1;
typedef struct td_sjs_anon1_heap sjs_anon1_heap;
typedef struct td_sjs_anon2 sjs_anon2;
typedef struct td_sjs_anon2_heap sjs_anon2_heap;
typedef struct td_sjs_anon3 sjs_anon3;
typedef struct td_sjs_anon3_heap sjs_anon3_heap;
typedef struct td_sjs_anon4 sjs_anon4;
typedef struct td_sjs_anon4_heap sjs_anon4_heap;
typedef struct td_sji_anon5_animation sji_anon5_animation;
typedef struct td_sjs_array_heap_animation sjs_array_heap_animation;
typedef struct td_sjs_array_heap_animation_heap sjs_array_heap_animation_heap;
typedef struct td_sjs_list_heap_animation sjs_list_heap_animation;
typedef struct td_sjs_list_heap_animation_heap sjs_list_heap_animation_heap;
typedef struct td_sjs_anon5 sjs_anon5;
typedef struct td_sjs_anon5_heap sjs_anon5_heap;
typedef struct td_sjs_anon6 sjs_anon6;
typedef struct td_sjs_anon6_heap sjs_anon6_heap;
typedef struct td_sjs_anon7 sjs_anon7;
typedef struct td_sjs_anon7_heap sjs_anon7_heap;
typedef struct td_sjs_anon8 sjs_anon8;
typedef struct td_sjs_anon8_heap sjs_anon8_heap;
typedef struct td_sjs_array_char sjs_array_char;
typedef struct td_sjs_array_char_heap sjs_array_char_heap;
typedef struct td_sjs_string sjs_string;
typedef struct td_sjs_string_heap sjs_string_heap;
typedef struct td_sjs_shader sjs_shader;
typedef struct td_sjs_shader_heap sjs_shader_heap;
typedef struct td_sjs_anon9 sjs_anon9;
typedef struct td_sjs_anon9_heap sjs_anon9_heap;
typedef struct td_sjs_rect sjs_rect;
typedef struct td_sjs_rect_heap sjs_rect_heap;
typedef struct td_sjs_point sjs_point;
typedef struct td_sjs_point_heap sjs_point_heap;
typedef struct td_sji_element sji_element;
typedef struct td_sjs_array_heap_element sjs_array_heap_element;
typedef struct td_sjs_array_heap_element_heap sjs_array_heap_element_heap;
typedef struct td_sjs_fillElement sjs_fillElement;
typedef struct td_sjs_fillElement_heap sjs_fillElement_heap;
typedef struct td_sjs_vec3 sjs_vec3;
typedef struct td_sjs_vec3_heap sjs_vec3_heap;
typedef struct td_cb_vec3_void cb_vec3_void;
typedef struct td_cb_vec3_void_heap cb_vec3_void_heap;
typedef struct td_sjs_animation_vec3 sjs_animation_vec3;
typedef struct td_sjs_animation_vec3_heap sjs_animation_vec3_heap;
typedef struct td_sji_scene3dElement_model sji_scene3dElement_model;
typedef struct td_sjs_array_heap_model sjs_array_heap_model;
typedef struct td_sjs_array_heap_model_heap sjs_array_heap_model_heap;
typedef struct td_cb_void cb_void;
typedef struct td_cb_void_heap cb_void_heap;
typedef struct td_sjs_array_local_cb_void sjs_array_local_cb_void;
typedef struct td_sjs_array_local_cb_void_heap sjs_array_local_cb_void_heap;
typedef struct td_sjs_list_local_cb_void sjs_list_local_cb_void;
typedef struct td_sjs_list_local_cb_void_heap sjs_list_local_cb_void_heap;
typedef struct td_sjs_property_vec3 sjs_property_vec3;
typedef struct td_sjs_property_vec3_heap sjs_property_vec3_heap;
typedef struct td_sjs_color sjs_color;
typedef struct td_sjs_color_heap sjs_color_heap;
typedef struct td_sjs_vec2 sjs_vec2;
typedef struct td_sjs_vec2_heap sjs_vec2_heap;
typedef struct td_sjs_vertex_location_texture_normal sjs_vertex_location_texture_normal;
typedef struct td_sjs_vertex_location_texture_normal_heap sjs_vertex_location_texture_normal_heap;
typedef struct td_sjs_array_i32 sjs_array_i32;
typedef struct td_sjs_array_i32_heap sjs_array_i32_heap;
typedef struct td_sjs_array_vertex_location_texture_normal sjs_array_vertex_location_texture_normal;
typedef struct td_sjs_array_vertex_location_texture_normal_heap sjs_array_vertex_location_texture_normal_heap;
typedef struct td_sjs_vertexBuffer_vertex_location_texture_normal sjs_vertexBuffer_vertex_location_texture_normal;
typedef struct td_sjs_vertexBuffer_vertex_location_texture_normal_heap sjs_vertexBuffer_vertex_location_texture_normal_heap;
typedef struct td_sjs_scene3dElement sjs_scene3dElement;
typedef struct td_sjs_scene3dElement_heap sjs_scene3dElement_heap;
typedef struct td_sjs_frameBuffer sjs_frameBuffer;
typedef struct td_sjs_frameBuffer_heap sjs_frameBuffer_heap;
typedef struct td_sjs_scene2dModel sjs_scene2dModel;
typedef struct td_sjs_scene2dModel_heap sjs_scene2dModel_heap;
typedef struct td_sjs_texture sjs_texture;
typedef struct td_sjs_texture_heap sjs_texture_heap;
typedef struct td_sjs_margin sjs_margin;
typedef struct td_sjs_margin_heap sjs_margin_heap;
typedef struct td_sjs_image sjs_image;
typedef struct td_sjs_image_heap sjs_image_heap;
typedef struct td_sjs_imageRenderer sjs_imageRenderer;
typedef struct td_sjs_imageRenderer_heap sjs_imageRenderer_heap;
typedef struct td_sjs_imageElement sjs_imageElement;
typedef struct td_sjs_imageElement_heap sjs_imageElement_heap;
typedef struct td_sjs_boxRenderer sjs_boxRenderer;
typedef struct td_sjs_boxRenderer_heap sjs_boxRenderer_heap;
typedef struct td_sjs_crossHairsElement sjs_crossHairsElement;
typedef struct td_sjs_crossHairsElement_heap sjs_crossHairsElement_heap;

struct td_sjs_object {
    intptr_t _refCount;
};

struct td_sjs_windowRenderer {
    SDL_Window* win;
    SDL_Renderer* ren;
    int structsNeedAValue;
};

struct td_sjs_windowRenderer_heap {
    intptr_t _refCount;
    SDL_Window* win;
    SDL_Renderer* ren;
};

struct td_sjs_size {
    int32_t w;
    int32_t h;
};

struct td_sjs_size_heap {
    intptr_t _refCount;
    int32_t w;
    int32_t h;
};

struct td_sjs_mat4 {
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

struct td_sjs_mat4_heap {
    intptr_t _refCount;
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
    sjs_size _size;
    sjs_mat4 model;
    sjs_mat4 view;
    sjs_mat4 projection;
};

struct td_sjs_scene2d_heap {
    intptr_t _refCount;
    sjs_size _size;
    sjs_mat4 model;
    sjs_mat4 view;
    sjs_mat4 projection;
};

struct td_sjs_anon1 {
    int structsNeedAValue;
};

struct td_sjs_anon1_heap {
    intptr_t _refCount;
};

struct td_sjs_anon2 {
    int structsNeedAValue;
};

struct td_sjs_anon2_heap {
    intptr_t _refCount;
};

struct td_sjs_anon3 {
    int structsNeedAValue;
};

struct td_sjs_anon3_heap {
    intptr_t _refCount;
};

struct td_sjs_anon4 {
    int structsNeedAValue;
};

struct td_sjs_anon4_heap {
    intptr_t _refCount;
};

struct td_sji_anon5_animation {
    intptr_t _refCount;
    sjs_object* _parent;
    void (*destroy)(void* _this);
    sjs_object* (*asInterface)(sjs_object* _this, int typeId);
    void (*nextFrame)(void* _parent, int32_t time, bool* _return);
};

struct td_sjs_array_heap_animation {
    int32_t size;
    uintptr_t data;
    bool _isGlobal;
};

struct td_sjs_array_heap_animation_heap {
    intptr_t _refCount;
    int32_t size;
    uintptr_t data;
    bool _isGlobal;
};

struct td_sjs_list_heap_animation {
    int32_t count;
    sjs_array_heap_animation data;
};

struct td_sjs_list_heap_animation_heap {
    intptr_t _refCount;
    int32_t count;
    sjs_array_heap_animation data;
};

struct td_sjs_anon5 {
    sjs_list_heap_animation animations;
    int32_t current;
};

struct td_sjs_anon5_heap {
    intptr_t _refCount;
    sjs_list_heap_animation animations;
    int32_t current;
};

struct td_sjs_anon6 {
    int32_t fill;
    int32_t left;
    int32_t right;
    int32_t top;
    int32_t bottom;
};

struct td_sjs_anon6_heap {
    intptr_t _refCount;
    int32_t fill;
    int32_t left;
    int32_t right;
    int32_t top;
    int32_t bottom;
};

struct td_sjs_anon7 {
    int32_t normal;
    int32_t hot;
    int32_t pressed;
};

struct td_sjs_anon7_heap {
    intptr_t _refCount;
    int32_t normal;
    int32_t hot;
    int32_t pressed;
};

struct td_sjs_anon8 {
    int structsNeedAValue;
};

struct td_sjs_anon8_heap {
    intptr_t _refCount;
};

struct td_sjs_array_char {
    int32_t size;
    uintptr_t data;
    bool _isGlobal;
};

struct td_sjs_array_char_heap {
    intptr_t _refCount;
    int32_t size;
    uintptr_t data;
    bool _isGlobal;
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

struct td_sjs_shader {
    sjs_string vertex;
    sjs_string pixel;
    GLuint id;
};

struct td_sjs_shader_heap {
    intptr_t _refCount;
    sjs_string vertex;
    sjs_string pixel;
    GLuint id;
};

struct td_sjs_anon9 {
    int structsNeedAValue;
};

struct td_sjs_anon9_heap {
    intptr_t _refCount;
};

struct td_sjs_rect {
    int32_t x;
    int32_t y;
    int32_t w;
    int32_t h;
};

struct td_sjs_rect_heap {
    intptr_t _refCount;
    int32_t x;
    int32_t y;
    int32_t w;
    int32_t h;
};

struct td_sjs_point {
    int32_t x;
    int32_t y;
};

struct td_sjs_point_heap {
    intptr_t _refCount;
    int32_t x;
    int32_t y;
};

struct td_sji_element {
    intptr_t _refCount;
    sjs_object* _parent;
    void (*destroy)(void* _this);
    sjs_object* (*asInterface)(sjs_object* _this, int typeId);
    void (*getSize)(void* _parent, sjs_size* maxSize, sjs_size* _return);
    void (*getSize_heap)(void* _parent, sjs_size* maxSize, sjs_size_heap** _return);
    void (*getRect)(void* _parent, sjs_rect** _return);
    void (*setRect)(void* _parent, sjs_rect* rect);
    void (*render)(void* _parent, sjs_scene2d* scene);
    void (*getChildren)(void* _parent, sjs_array_heap_element** _return);
    void (*fireMouseEvent)(void* _parent, sjs_point* point, int32_t eventId);
};

struct td_sjs_array_heap_element {
    int32_t size;
    uintptr_t data;
    bool _isGlobal;
};

struct td_sjs_array_heap_element_heap {
    intptr_t _refCount;
    int32_t size;
    uintptr_t data;
    bool _isGlobal;
};

struct td_sjs_fillElement {
    sjs_array_heap_element children;
    sjs_rect _rect;
};

struct td_sjs_fillElement_heap {
    intptr_t _refCount;
    sjs_array_heap_element children;
    sjs_rect _rect;
};

struct td_sjs_vec3 {
    float x;
    float y;
    float z;
};

struct td_sjs_vec3_heap {
    intptr_t _refCount;
    float x;
    float y;
    float z;
};

struct td_cb_vec3_void {
    void* _parent;
    void (*_cb)(void* _parent, sjs_vec3*);
};

struct td_cb_vec3_void_heap {
    cb_vec3_void inner;
    void (*_destroy)(void*);
};

struct td_sjs_animation_vec3 {
    int32_t start;
    sjs_vec3 startValue;
    int32_t end;
    sjs_vec3 endValue;
    cb_vec3_void_heap setValue;
};

struct td_sjs_animation_vec3_heap {
    intptr_t _refCount;
    int32_t start;
    sjs_vec3 startValue;
    int32_t end;
    sjs_vec3 endValue;
    cb_vec3_void_heap setValue;
};

struct td_sji_scene3dElement_model {
    intptr_t _refCount;
    sjs_object* _parent;
    void (*destroy)(void* _this);
    sjs_object* (*asInterface)(sjs_object* _this, int typeId);
    void (*setWorld)(void* _parent, sjs_mat4* world);
    void (*render)(void* _parent, sjs_scene3dElement* scene3d);
    void (*fireMouseEvent)(void* _parent, sjs_scene3dElement* scene3d, sjs_point* point, int32_t eventId);
};

struct td_sjs_array_heap_model {
    int32_t size;
    uintptr_t data;
    bool _isGlobal;
};

struct td_sjs_array_heap_model_heap {
    intptr_t _refCount;
    int32_t size;
    uintptr_t data;
    bool _isGlobal;
};

struct td_cb_void {
    void* _parent;
    void (*_cb)(void* _parent);
};

struct td_cb_void_heap {
    cb_void inner;
    void (*_destroy)(void*);
};

struct td_sjs_array_local_cb_void {
    int32_t size;
    uintptr_t data;
    bool _isGlobal;
};

struct td_sjs_array_local_cb_void_heap {
    intptr_t _refCount;
    int32_t size;
    uintptr_t data;
    bool _isGlobal;
};

struct td_sjs_list_local_cb_void {
    int32_t count;
    sjs_array_local_cb_void data;
};

struct td_sjs_list_local_cb_void_heap {
    intptr_t _refCount;
    int32_t count;
    sjs_array_local_cb_void data;
};

struct td_sjs_property_vec3 {
    sjs_vec3 t;
    sjs_list_local_cb_void invalidate;
    bool _isDirty;
};

struct td_sjs_property_vec3_heap {
    intptr_t _refCount;
    sjs_vec3 t;
    sjs_list_local_cb_void invalidate;
    bool _isDirty;
};

struct td_sjs_color {
    float r;
    float g;
    float b;
    float a;
};

struct td_sjs_color_heap {
    intptr_t _refCount;
    float r;
    float g;
    float b;
    float a;
};

struct td_sjs_vec2 {
    float x;
    float y;
};

struct td_sjs_vec2_heap {
    intptr_t _refCount;
    float x;
    float y;
};

struct td_sjs_vertex_location_texture_normal {
    sjs_vec3 location;
    sjs_vec2 texture;
    sjs_vec3 normal;
};

struct td_sjs_vertex_location_texture_normal_heap {
    intptr_t _refCount;
    sjs_vec3 location;
    sjs_vec2 texture;
    sjs_vec3 normal;
};

struct td_sjs_array_i32 {
    int32_t size;
    uintptr_t data;
    bool _isGlobal;
};

struct td_sjs_array_i32_heap {
    intptr_t _refCount;
    int32_t size;
    uintptr_t data;
    bool _isGlobal;
};

struct td_sjs_array_vertex_location_texture_normal {
    int32_t size;
    uintptr_t data;
    bool _isGlobal;
};

struct td_sjs_array_vertex_location_texture_normal_heap {
    intptr_t _refCount;
    int32_t size;
    uintptr_t data;
    bool _isGlobal;
};

struct td_sjs_vertexBuffer_vertex_location_texture_normal {
    sjs_string format;
    sjs_array_i32 indices;
    sjs_array_vertex_location_texture_normal vertices;
    vertex_buffer_t* buffer;
};

struct td_sjs_vertexBuffer_vertex_location_texture_normal_heap {
    intptr_t _refCount;
    sjs_string format;
    sjs_array_i32 indices;
    sjs_array_vertex_location_texture_normal vertices;
    vertex_buffer_t* buffer;
};

struct td_sjs_scene3dElement {
    sjs_array_heap_model children;
    sjs_property_vec3_heap* camera;
    sjs_vec3 lookAt;
    sjs_vec3 up;
    float fieldOfView;
    float zNear;
    float zFar;
    sjs_vec3 lightPos;
    sjs_color diffuseColor;
    sjs_color specColor;
    sjs_mat4 projection;
    sjs_mat4 view;
    sjs_rect _rect;
    float _angle;
    bool _isUp;
    sjs_vertexBuffer_vertex_location_texture_normal _cube;
};

struct td_sjs_scene3dElement_heap {
    intptr_t _refCount;
    sjs_array_heap_model children;
    sjs_property_vec3_heap* camera;
    sjs_vec3 lookAt;
    sjs_vec3 up;
    float fieldOfView;
    float zNear;
    float zFar;
    sjs_vec3 lightPos;
    sjs_color diffuseColor;
    sjs_color specColor;
    sjs_mat4 projection;
    sjs_mat4 view;
    sjs_rect _rect;
    float _angle;
    bool _isUp;
    sjs_vertexBuffer_vertex_location_texture_normal _cube;
};

struct td_sjs_frameBuffer {
    sjs_size size;
    GLuint frameBufferId;
    GLuint textureId;
    GLuint depthBufferId;
};

struct td_sjs_frameBuffer_heap {
    intptr_t _refCount;
    sjs_size size;
    GLuint frameBufferId;
    GLuint textureId;
    GLuint depthBufferId;
};

struct td_sjs_scene2dModel {
    sjs_vertexBuffer_vertex_location_texture_normal vertexBuffer;
    sjs_shader shader;
    sjs_frameBuffer frameBuffer;
    sjs_array_heap_element children;
    sjs_scene2d _innerScene;
    sjs_mat4 _world;
};

struct td_sjs_scene2dModel_heap {
    intptr_t _refCount;
    sjs_vertexBuffer_vertex_location_texture_normal vertexBuffer;
    sjs_shader shader;
    sjs_frameBuffer frameBuffer;
    sjs_array_heap_element children;
    sjs_scene2d _innerScene;
    sjs_mat4 _world;
};

struct td_sjs_texture {
    sjs_size size;
    uint32_t id;
};

struct td_sjs_texture_heap {
    intptr_t _refCount;
    sjs_size size;
    uint32_t id;
};

struct td_sjs_margin {
    int32_t l;
    int32_t t;
    int32_t r;
    int32_t b;
};

struct td_sjs_margin_heap {
    intptr_t _refCount;
    int32_t l;
    int32_t t;
    int32_t r;
    int32_t b;
};

struct td_sjs_image {
    sjs_texture texture;
    sjs_rect rect;
    sjs_margin margin;
};

struct td_sjs_image_heap {
    intptr_t _refCount;
    sjs_texture texture;
    sjs_rect rect;
    sjs_margin margin;
};

struct td_sjs_imageRenderer {
    sjs_rect rect;
    sjs_image image;
    vertex_buffer_t* buffer;
};

struct td_sjs_imageRenderer_heap {
    intptr_t _refCount;
    sjs_rect rect;
    sjs_image image;
    vertex_buffer_t* buffer;
};

struct td_sjs_imageElement {
    sjs_image image;
    sjs_rect _rect;
    sjs_margin _margin;
    sjs_imageRenderer_heap* _imageRenderer;
};

struct td_sjs_imageElement_heap {
    intptr_t _refCount;
    sjs_image image;
    sjs_rect _rect;
    sjs_margin _margin;
    sjs_imageRenderer_heap* _imageRenderer;
};

struct td_sjs_boxRenderer {
    sjs_rect rect;
    sjs_color color;
    vertex_buffer_t* buffer;
};

struct td_sjs_boxRenderer_heap {
    intptr_t _refCount;
    sjs_rect rect;
    sjs_color color;
    vertex_buffer_t* buffer;
};

struct td_sjs_crossHairsElement {
    sjs_color color;
    sjs_rect _rect;
    sjs_boxRenderer_heap* _topDownRenderer;
    sjs_boxRenderer_heap* _leftRightRenderer;
    sjs_point _point;
};

struct td_sjs_crossHairsElement_heap {
    intptr_t _refCount;
    sjs_color color;
    sjs_rect _rect;
    sjs_boxRenderer_heap* _topDownRenderer;
    sjs_boxRenderer_heap* _leftRightRenderer;
    sjs_point _point;
};


void halt(const char * format, ...);


void _retain(void* ptr);
bool _release(void* ptr);


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


void _retainGLid(GLuint id);
bool _releaseGLid(GLuint id);


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
float result19;
float result44;
float result45;
float result46;
sjs_vec3 sjt_call7;
sjs_vec3 sjt_call8;
sjs_string sjt_call9;
int32_t sjt_cast1;
int32_t sjt_cast10;
sjs_scene2dModel_heap* sjt_cast11;
sjs_fillElement_heap* sjt_cast2;
int32_t sjt_cast3;
sjs_scene3dElement_heap* sjt_cast4;
int32_t sjt_cast42;
sjs_imageElement_heap* sjt_cast43;
sjs_crossHairsElement_heap* sjt_cast44;
int32_t sjt_cast45;
sjs_crossHairsElement_heap* sjt_cast50;
int32_t sjt_functionParam149;
int32_t sjt_functionParam150;
sjs_vec3* sjt_functionParam151;
sjs_vec3* sjt_functionParam152;
int32_t sjt_functionParam153;
sji_element* sjt_functionParam154;
sjs_string* sjt_functionParam158;
int32_t sjt_functionParam159;
sji_element* sjt_functionParam160;
int32_t sjt_functionParam4;
float sjt_functionParam405;
float sjt_functionParam406;
float sjt_functionParam407;
float sjt_functionParam408;
float sjt_functionParam409;
float sjt_functionParam410;
float sjt_functionParam411;
float sjt_functionParam412;
float sjt_functionParam413;
float sjt_functionParam414;
int32_t sjt_functionParam415;
sji_element* sjt_functionParam416;
sji_element* sjt_functionParam5;
int32_t sjt_functionParam63;
sji_scene3dElement_model* sjt_functionParam64;
int32_t sjt_math1;
int32_t sjt_math2;
int32_t sjt_negate1;
float sjt_negate34;
float sjt_negate35;
float sjt_negate36;
float sjt_negate9;
sjs_array_heap_element* sjt_parent101;
sjs_array_heap_element* sjt_parent107;
sjs_anon8* sjt_parent112;
sjs_array_heap_element* sjt_parent233;
sjs_anon8* sjt_parent234;
sjs_array_heap_model* sjt_parent43;
sjs_array_heap_element* sjt_parent7;
sjs_anon5 sjv_animator;
sjs_shader sjv_blurHorizontalShader;
sjs_shader sjv_blurVerticalShader;
sjs_anon6 sjv_borderPosition;
sjs_shader sjv_boxShader;
sjs_anon7 sjv_buttonState;
sjs_anon8 sjv_colors;
sjs_anon1 sjv_console;
sjs_anon2 sjv_convert;
float sjv_f32_pi;
int32_t sjv_i32_maxValue;
int32_t sjv_i32_minValue;
sjs_shader sjv_imageShader;
int32_t sjv_mouseEvent_down;
int32_t sjv_mouseEvent_move;
int32_t sjv_mouseEvent_up;
sjs_anon3 sjv_parse;
sjs_shader sjv_phongColorShader;
sjs_shader sjv_phongTextureShader;
sjs_anon4 sjv_random;
sji_element* sjv_root;
sjs_scene2d sjv_rootScene;
sjs_windowRenderer sjv_rootWindowRenderer;
sjs_anon9 sjv_style;
sjs_shader sjv_textShader;
uint32_t sjv_u32_maxValue;
sjs_string sjv_vertex_location_texture_normal_format;

void sjf_animation_vec3(sjs_animation_vec3* _this);
sjs_object* sjf_animation_vec3_asInterface(sjs_animation_vec3* _this, int typeId);
sji_anon5_animation* sjf_animation_vec3_as_sji_anon5_animation(sjs_animation_vec3* _this);
void sjf_animation_vec3_copy(sjs_animation_vec3* _this, sjs_animation_vec3* _from);
void sjf_animation_vec3_destroy(sjs_animation_vec3* _this);
void sjf_animation_vec3_heap(sjs_animation_vec3_heap* _this);
sjs_object* sjf_animation_vec3_heap_asInterface(sjs_animation_vec3_heap* _this, int typeId);
sji_anon5_animation* sjf_animation_vec3_heap_as_sji_anon5_animation(sjs_animation_vec3_heap* _this);
void sjf_animation_vec3_nextFrame(sjs_animation_vec3* _parent, int32_t time, bool* _return);
void sjf_anon1(sjs_anon1* _this);
void sjf_anon1_copy(sjs_anon1* _this, sjs_anon1* _from);
void sjf_anon1_destroy(sjs_anon1* _this);
void sjf_anon1_heap(sjs_anon1_heap* _this);
void sjf_anon2(sjs_anon2* _this);
void sjf_anon2_copy(sjs_anon2* _this, sjs_anon2* _from);
void sjf_anon2_destroy(sjs_anon2* _this);
void sjf_anon2_heap(sjs_anon2_heap* _this);
void sjf_anon3(sjs_anon3* _this);
void sjf_anon3_copy(sjs_anon3* _this, sjs_anon3* _from);
void sjf_anon3_destroy(sjs_anon3* _this);
void sjf_anon3_heap(sjs_anon3_heap* _this);
void sjf_anon4(sjs_anon4* _this);
void sjf_anon4_copy(sjs_anon4* _this, sjs_anon4* _from);
void sjf_anon4_destroy(sjs_anon4* _this);
void sjf_anon4_heap(sjs_anon4_heap* _this);
void sjf_anon5(sjs_anon5* _this);
void sjf_anon5_copy(sjs_anon5* _this, sjs_anon5* _from);
void sjf_anon5_destroy(sjs_anon5* _this);
void sjf_anon5_heap(sjs_anon5_heap* _this);
void sjf_anon5_nextFrame(sjs_anon5* _parent, int32_t time);
void sjf_anon6(sjs_anon6* _this);
void sjf_anon6_copy(sjs_anon6* _this, sjs_anon6* _from);
void sjf_anon6_destroy(sjs_anon6* _this);
void sjf_anon6_heap(sjs_anon6_heap* _this);
void sjf_anon7(sjs_anon7* _this);
void sjf_anon7_copy(sjs_anon7* _this, sjs_anon7* _from);
void sjf_anon7_destroy(sjs_anon7* _this);
void sjf_anon7_heap(sjs_anon7_heap* _this);
void sjf_anon8(sjs_anon8* _this);
void sjf_anon8_blue(sjs_anon8* _parent, sjs_color* _return);
void sjf_anon8_blue_heap(sjs_anon8* _parent, sjs_color_heap** _return);
void sjf_anon8_copy(sjs_anon8* _this, sjs_anon8* _from);
void sjf_anon8_destroy(sjs_anon8* _this);
void sjf_anon8_heap(sjs_anon8_heap* _this);
void sjf_anon8_red(sjs_anon8* _parent, sjs_color* _return);
void sjf_anon8_red_heap(sjs_anon8* _parent, sjs_color_heap** _return);
void sjf_anon9(sjs_anon9* _this);
void sjf_anon9_copy(sjs_anon9* _this, sjs_anon9* _from);
void sjf_anon9_destroy(sjs_anon9* _this);
void sjf_anon9_heap(sjs_anon9_heap* _this);
void sjf_array_char(sjs_array_char* _this);
void sjf_array_char_copy(sjs_array_char* _this, sjs_array_char* _from);
void sjf_array_char_destroy(sjs_array_char* _this);
void sjf_array_char_heap(sjs_array_char_heap* _this);
void sjf_array_heap_animation(sjs_array_heap_animation* _this);
void sjf_array_heap_animation_copy(sjs_array_heap_animation* _this, sjs_array_heap_animation* _from);
void sjf_array_heap_animation_destroy(sjs_array_heap_animation* _this);
void sjf_array_heap_animation_getAt_heap(sjs_array_heap_animation* _parent, int32_t index, sji_anon5_animation** _return);
void sjf_array_heap_animation_grow(sjs_array_heap_animation* _parent, int32_t new_size);
void sjf_array_heap_animation_heap(sjs_array_heap_animation_heap* _this);
void sjf_array_heap_animation_initAt(sjs_array_heap_animation* _parent, int32_t index, sji_anon5_animation* item);
void sjf_array_heap_element(sjs_array_heap_element* _this);
void sjf_array_heap_element_copy(sjs_array_heap_element* _this, sjs_array_heap_element* _from);
void sjf_array_heap_element_destroy(sjs_array_heap_element* _this);
void sjf_array_heap_element_getAt_heap(sjs_array_heap_element* _parent, int32_t index, sji_element** _return);
void sjf_array_heap_element_heap(sjs_array_heap_element_heap* _this);
void sjf_array_heap_element_initAt(sjs_array_heap_element* _parent, int32_t index, sji_element* item);
void sjf_array_heap_model(sjs_array_heap_model* _this);
void sjf_array_heap_model_copy(sjs_array_heap_model* _this, sjs_array_heap_model* _from);
void sjf_array_heap_model_destroy(sjs_array_heap_model* _this);
void sjf_array_heap_model_getAt_heap(sjs_array_heap_model* _parent, int32_t index, sji_scene3dElement_model** _return);
void sjf_array_heap_model_heap(sjs_array_heap_model_heap* _this);
void sjf_array_heap_model_initAt(sjs_array_heap_model* _parent, int32_t index, sji_scene3dElement_model* item);
void sjf_array_i32(sjs_array_i32* _this);
void sjf_array_i32_copy(sjs_array_i32* _this, sjs_array_i32* _from);
void sjf_array_i32_destroy(sjs_array_i32* _this);
void sjf_array_i32_getAt(sjs_array_i32* _parent, int32_t index, int32_t* _return);
void sjf_array_i32_heap(sjs_array_i32_heap* _this);
void sjf_array_i32_initAt(sjs_array_i32* _parent, int32_t index, int32_t item);
void sjf_array_local_cb_void(sjs_array_local_cb_void* _this);
void sjf_array_local_cb_void_copy(sjs_array_local_cb_void* _this, sjs_array_local_cb_void* _from);
void sjf_array_local_cb_void_destroy(sjs_array_local_cb_void* _this);
void sjf_array_local_cb_void_getAt(sjs_array_local_cb_void* _parent, int32_t index, cb_void* _return);
void sjf_array_local_cb_void_heap(sjs_array_local_cb_void_heap* _this);
void sjf_array_vertex_location_texture_normal(sjs_array_vertex_location_texture_normal* _this);
void sjf_array_vertex_location_texture_normal_copy(sjs_array_vertex_location_texture_normal* _this, sjs_array_vertex_location_texture_normal* _from);
void sjf_array_vertex_location_texture_normal_destroy(sjs_array_vertex_location_texture_normal* _this);
void sjf_array_vertex_location_texture_normal_getAt(sjs_array_vertex_location_texture_normal* _parent, int32_t index, sjs_vertex_location_texture_normal* _return);
void sjf_array_vertex_location_texture_normal_heap(sjs_array_vertex_location_texture_normal_heap* _this);
void sjf_array_vertex_location_texture_normal_initAt(sjs_array_vertex_location_texture_normal* _parent, int32_t index, sjs_vertex_location_texture_normal* item);
void sjf_boxRenderer(sjs_boxRenderer* _this);
void sjf_boxRenderer_copy(sjs_boxRenderer* _this, sjs_boxRenderer* _from);
void sjf_boxRenderer_destroy(sjs_boxRenderer* _this);
void sjf_boxRenderer_heap(sjs_boxRenderer_heap* _this);
void sjf_boxRenderer_render(sjs_boxRenderer* _parent, sjs_scene2d* scene);
void sjf_color(sjs_color* _this);
void sjf_color_copy(sjs_color* _this, sjs_color* _from);
void sjf_color_destroy(sjs_color* _this);
void sjf_color_heap(sjs_color_heap* _this);
void sjf_crossHairsElement(sjs_crossHairsElement* _this);
sjs_object* sjf_crossHairsElement_asInterface(sjs_crossHairsElement* _this, int typeId);
sji_element* sjf_crossHairsElement_as_sji_element(sjs_crossHairsElement* _this);
void sjf_crossHairsElement_copy(sjs_crossHairsElement* _this, sjs_crossHairsElement* _from);
void sjf_crossHairsElement_destroy(sjs_crossHairsElement* _this);
void sjf_crossHairsElement_fireMouseEvent(sjs_crossHairsElement* _parent, sjs_point* point, int32_t eventId);
void sjf_crossHairsElement_getChildren(sjs_crossHairsElement* _parent, sjs_array_heap_element** _return);
void sjf_crossHairsElement_getRect(sjs_crossHairsElement* _parent, sjs_rect** _return);
void sjf_crossHairsElement_getSize(sjs_crossHairsElement* _parent, sjs_size* maxSize, sjs_size* _return);
void sjf_crossHairsElement_getSize_heap(sjs_crossHairsElement* _parent, sjs_size* maxSize, sjs_size_heap** _return);
void sjf_crossHairsElement_heap(sjs_crossHairsElement_heap* _this);
sjs_object* sjf_crossHairsElement_heap_asInterface(sjs_crossHairsElement_heap* _this, int typeId);
sji_element* sjf_crossHairsElement_heap_as_sji_element(sjs_crossHairsElement_heap* _this);
void sjf_crossHairsElement_render(sjs_crossHairsElement* _parent, sjs_scene2d* scene);
void sjf_crossHairsElement_setRect(sjs_crossHairsElement* _parent, sjs_rect* rect_);
void sjf_cubeVertexBuffer(float x0, float x1, float y0, float y1, float z0, float z1, float s0, float s1, float t0, float t1, sjs_vertexBuffer_vertex_location_texture_normal* _return);
void sjf_cubeVertexBuffer_heap(float x0, float x1, float y0, float y1, float z0, float z1, float s0, float s1, float t0, float t1, sjs_vertexBuffer_vertex_location_texture_normal_heap** _return);
void sjf_f32_cos(float v, float* _return);
void sjf_f32_sin(float v, float* _return);
void sjf_f32_sqrt(float v, float* _return);
void sjf_f32_tan(float v, float* _return);
void sjf_fillElement(sjs_fillElement* _this);
sjs_object* sjf_fillElement_asInterface(sjs_fillElement* _this, int typeId);
sji_element* sjf_fillElement_as_sji_element(sjs_fillElement* _this);
void sjf_fillElement_copy(sjs_fillElement* _this, sjs_fillElement* _from);
void sjf_fillElement_destroy(sjs_fillElement* _this);
void sjf_fillElement_fireMouseEvent(sjs_fillElement* _parent, sjs_point* point, int32_t eventId);
void sjf_fillElement_getChildren(sjs_fillElement* _parent, sjs_array_heap_element** _return);
void sjf_fillElement_getRect(sjs_fillElement* _parent, sjs_rect** _return);
void sjf_fillElement_getSize(sjs_fillElement* _parent, sjs_size* maxSize, sjs_size* _return);
void sjf_fillElement_getSize_heap(sjs_fillElement* _parent, sjs_size* maxSize, sjs_size_heap** _return);
void sjf_fillElement_heap(sjs_fillElement_heap* _this);
sjs_object* sjf_fillElement_heap_asInterface(sjs_fillElement_heap* _this, int typeId);
sji_element* sjf_fillElement_heap_as_sji_element(sjs_fillElement_heap* _this);
void sjf_fillElement_render(sjs_fillElement* _parent, sjs_scene2d* scene);
void sjf_fillElement_setRect(sjs_fillElement* _parent, sjs_rect* rect_);
void sjf_frameBuffer(sjs_frameBuffer* _this);
void sjf_frameBuffer_copy(sjs_frameBuffer* _this, sjs_frameBuffer* _from);
void sjf_frameBuffer_destroy(sjs_frameBuffer* _this);
void sjf_frameBuffer_heap(sjs_frameBuffer_heap* _this);
void sjf_i32_max(int32_t a, int32_t b, int32_t* _return);
void sjf_image(sjs_image* _this);
void sjf_imageElement(sjs_imageElement* _this);
sjs_object* sjf_imageElement_asInterface(sjs_imageElement* _this, int typeId);
sji_element* sjf_imageElement_as_sji_element(sjs_imageElement* _this);
void sjf_imageElement_copy(sjs_imageElement* _this, sjs_imageElement* _from);
void sjf_imageElement_destroy(sjs_imageElement* _this);
void sjf_imageElement_fireMouseEvent(sjs_imageElement* _parent, sjs_point* point, int32_t eventId);
void sjf_imageElement_getChildren(sjs_imageElement* _parent, sjs_array_heap_element** _return);
void sjf_imageElement_getRect(sjs_imageElement* _parent, sjs_rect** _return);
void sjf_imageElement_getSize(sjs_imageElement* _parent, sjs_size* maxSize, sjs_size* _return);
void sjf_imageElement_getSize_heap(sjs_imageElement* _parent, sjs_size* maxSize, sjs_size_heap** _return);
void sjf_imageElement_heap(sjs_imageElement_heap* _this);
sjs_object* sjf_imageElement_heap_asInterface(sjs_imageElement_heap* _this, int typeId);
sji_element* sjf_imageElement_heap_as_sji_element(sjs_imageElement_heap* _this);
void sjf_imageElement_render(sjs_imageElement* _parent, sjs_scene2d* scene);
void sjf_imageElement_setRect(sjs_imageElement* _parent, sjs_rect* rect_);
void sjf_imageRenderer(sjs_imageRenderer* _this);
void sjf_imageRenderer_copy(sjs_imageRenderer* _this, sjs_imageRenderer* _from);
void sjf_imageRenderer_destroy(sjs_imageRenderer* _this);
void sjf_imageRenderer_heap(sjs_imageRenderer_heap* _this);
void sjf_imageRenderer_render(sjs_imageRenderer* _parent, sjs_scene2d* scene);
void sjf_image_copy(sjs_image* _this, sjs_image* _from);
void sjf_image_destroy(sjs_image* _this);
void sjf_image_heap(sjs_image_heap* _this);
void sjf_intersectTriangle_heap(sjs_vec3* orig, sjs_vec3* dir, sjs_vec3* v0, sjs_vec3* v1, sjs_vec3* v2, sjs_vec3_heap** _return);
void sjf_list_heap_animation(sjs_list_heap_animation* _this);
void sjf_list_heap_animation_add(sjs_list_heap_animation* _parent, sji_anon5_animation* item, int32_t* _return);
void sjf_list_heap_animation_copy(sjs_list_heap_animation* _this, sjs_list_heap_animation* _from);
void sjf_list_heap_animation_destroy(sjs_list_heap_animation* _this);
void sjf_list_heap_animation_getAt_heap(sjs_list_heap_animation* _parent, int32_t index, sji_anon5_animation** _return);
void sjf_list_heap_animation_heap(sjs_list_heap_animation_heap* _this);
void sjf_list_heap_animation_removeAt(sjs_list_heap_animation* _parent, int32_t index);
void sjf_list_heap_animation_setSize(sjs_list_heap_animation* _parent, int32_t size);
void sjf_list_local_cb_void(sjs_list_local_cb_void* _this);
void sjf_list_local_cb_void_copy(sjs_list_local_cb_void* _this, sjs_list_local_cb_void* _from);
void sjf_list_local_cb_void_destroy(sjs_list_local_cb_void* _this);
void sjf_list_local_cb_void_getAt(sjs_list_local_cb_void* _parent, int32_t index, cb_void* _return);
void sjf_list_local_cb_void_heap(sjs_list_local_cb_void_heap* _this);
void sjf_mainLoop(void);
void sjf_margin(sjs_margin* _this);
void sjf_margin_copy(sjs_margin* _this, sjs_margin* _from);
void sjf_margin_destroy(sjs_margin* _this);
void sjf_margin_heap(sjs_margin_heap* _this);
void sjf_mat4(sjs_mat4* _this);
void sjf_mat4_copy(sjs_mat4* _this, sjs_mat4* _from);
void sjf_mat4_destroy(sjs_mat4* _this);
void sjf_mat4_determinant(sjs_mat4* _parent, float* _return);
void sjf_mat4_heap(sjs_mat4_heap* _this);
void sjf_mat4_identity(sjs_mat4* _return);
void sjf_mat4_identity_heap(sjs_mat4_heap** _return);
void sjf_mat4_invert(sjs_mat4* _parent, sjs_mat4* _return);
void sjf_mat4_invert_heap(sjs_mat4* _parent, sjs_mat4_heap** _return);
void sjf_mat4_lookAtLH(sjs_vec3* camera, sjs_vec3* target, sjs_vec3* up, sjs_mat4* _return);
void sjf_mat4_lookAtLH_heap(sjs_vec3* camera, sjs_vec3* target, sjs_vec3* up, sjs_mat4_heap** _return);
void sjf_mat4_multiply(sjs_mat4* _parent, sjs_mat4* m, sjs_mat4* _return);
void sjf_mat4_multiply_f32(sjs_mat4* _parent, float x, sjs_mat4* _return);
void sjf_mat4_multiply_f32_heap(sjs_mat4* _parent, float x, sjs_mat4_heap** _return);
void sjf_mat4_multiply_heap(sjs_mat4* _parent, sjs_mat4* m, sjs_mat4_heap** _return);
void sjf_mat4_orthographic(float left, float right, float bottom, float top, float znear, float zfar, sjs_mat4* _return);
void sjf_mat4_orthographic_heap(float left, float right, float bottom, float top, float znear, float zfar, sjs_mat4_heap** _return);
void sjf_mat4_perspective(float fovy, float aspect, float znear, float zfar, sjs_mat4* _return);
void sjf_mat4_perspective_heap(float fovy, float aspect, float znear, float zfar, sjs_mat4_heap** _return);
void sjf_mat4_rotation(float angle, float x, float y, float z, sjs_mat4* _return);
void sjf_mat4_rotation_heap(float angle, float x, float y, float z, sjs_mat4_heap** _return);
void sjf_mat4_scale(float x, float y, float z, sjs_mat4* _return);
void sjf_mat4_scale_heap(float x, float y, float z, sjs_mat4_heap** _return);
void sjf_mat4_transpose(sjs_mat4* _parent, sjs_mat4* _return);
void sjf_mat4_transpose_heap(sjs_mat4* _parent, sjs_mat4_heap** _return);
void sjf_point(sjs_point* _this);
void sjf_point_copy(sjs_point* _this, sjs_point* _from);
void sjf_point_destroy(sjs_point* _this);
void sjf_point_heap(sjs_point_heap* _this);
void sjf_property_vec3(sjs_property_vec3* _this);
void sjf_property_vec3_animate(sjs_property_vec3* _parent, sjs_vec3* x, int32_t duration);
void sjf_property_vec3_copy(sjs_property_vec3* _this, sjs_property_vec3* _from);
void sjf_property_vec3_destroy(sjs_property_vec3* _this);
void sjf_property_vec3_get(sjs_property_vec3* _parent, sjs_vec3** _return);
void sjf_property_vec3_getIsDirty(sjs_property_vec3* _parent, bool* _return);
void sjf_property_vec3_heap(sjs_property_vec3_heap* _this);
void sjf_property_vec3_set(sjs_property_vec3* _parent, sjs_vec3* x);
void sjf_rect(sjs_rect* _this);
void sjf_rect_containsPoint(sjs_rect* _parent, sjs_point* point, bool* _return);
void sjf_rect_copy(sjs_rect* _this, sjs_rect* _from);
void sjf_rect_destroy(sjs_rect* _this);
void sjf_rect_heap(sjs_rect_heap* _this);
void sjf_rect_isEqual(sjs_rect* _parent, sjs_rect* rect, bool* _return);
void sjf_rect_subtractMargin(sjs_rect* _parent, sjs_margin* margin, sjs_rect* _return);
void sjf_rect_subtractMargin_heap(sjs_rect* _parent, sjs_margin* margin, sjs_rect_heap** _return);
void sjf_runLoop(void);
void sjf_scene2d(sjs_scene2d* _this);
void sjf_scene2dModel(sjs_scene2dModel* _this);
sjs_object* sjf_scene2dModel_asInterface(sjs_scene2dModel* _this, int typeId);
sji_scene3dElement_model* sjf_scene2dModel_as_sji_scene3dElement_model(sjs_scene2dModel* _this);
void sjf_scene2dModel_copy(sjs_scene2dModel* _this, sjs_scene2dModel* _from);
void sjf_scene2dModel_destroy(sjs_scene2dModel* _this);
void sjf_scene2dModel_fireMouseEvent(sjs_scene2dModel* _parent, sjs_scene3dElement* scene3d, sjs_point* point, int32_t eventId);
void sjf_scene2dModel_heap(sjs_scene2dModel_heap* _this);
sjs_object* sjf_scene2dModel_heap_asInterface(sjs_scene2dModel_heap* _this, int typeId);
sji_scene3dElement_model* sjf_scene2dModel_heap_as_sji_scene3dElement_model(sjs_scene2dModel_heap* _this);
void sjf_scene2dModel_render(sjs_scene2dModel* _parent, sjs_scene3dElement* scene3d);
void sjf_scene2dModel_setWorld(sjs_scene2dModel* _parent, sjs_mat4* world);
void sjf_scene2d_clear(sjs_scene2d* _parent);
void sjf_scene2d_copy(sjs_scene2d* _this, sjs_scene2d* _from);
void sjf_scene2d_destroy(sjs_scene2d* _this);
void sjf_scene2d_heap(sjs_scene2d_heap* _this);
void sjf_scene2d_setSize(sjs_scene2d* _parent, sjs_size* size);
void sjf_scene2d_updateViewport(sjs_scene2d* _parent);
void sjf_scene3dElement(sjs_scene3dElement* _this);
sjs_object* sjf_scene3dElement_asInterface(sjs_scene3dElement* _this, int typeId);
sji_element* sjf_scene3dElement_as_sji_element(sjs_scene3dElement* _this);
void sjf_scene3dElement_copy(sjs_scene3dElement* _this, sjs_scene3dElement* _from);
void sjf_scene3dElement_destroy(sjs_scene3dElement* _this);
void sjf_scene3dElement_fireMouseEvent(sjs_scene3dElement* _parent, sjs_point* point, int32_t eventId);
void sjf_scene3dElement_getChildren(sjs_scene3dElement* _parent, sjs_array_heap_element** _return);
void sjf_scene3dElement_getRect(sjs_scene3dElement* _parent, sjs_rect** _return);
void sjf_scene3dElement_getSize(sjs_scene3dElement* _parent, sjs_size* maxSize, sjs_size* _return);
void sjf_scene3dElement_getSize_heap(sjs_scene3dElement* _parent, sjs_size* maxSize, sjs_size_heap** _return);
void sjf_scene3dElement_heap(sjs_scene3dElement_heap* _this);
sjs_object* sjf_scene3dElement_heap_asInterface(sjs_scene3dElement_heap* _this, int typeId);
sji_element* sjf_scene3dElement_heap_as_sji_element(sjs_scene3dElement_heap* _this);
void sjf_scene3dElement_render(sjs_scene3dElement* _parent, sjs_scene2d* scene);
void sjf_scene3dElement_setRect(sjs_scene3dElement* _parent, sjs_rect* rect_);
void sjf_scene3dElement_updateViewport(sjs_scene3dElement* _parent);
void sjf_shader(sjs_shader* _this);
void sjf_shader_copy(sjs_shader* _this, sjs_shader* _from);
void sjf_shader_destroy(sjs_shader* _this);
void sjf_shader_heap(sjs_shader_heap* _this);
void sjf_size(sjs_size* _this);
void sjf_size_copy(sjs_size* _this, sjs_size* _from);
void sjf_size_destroy(sjs_size* _this);
void sjf_size_heap(sjs_size_heap* _this);
void sjf_size_isEqual(sjs_size* _parent, sjs_size* size, bool* _return);
void sjf_sphereVertexBuffer(int32_t slices, int32_t wedges, sjs_vec3* origin, sjs_vec3* radius, sjs_vertexBuffer_vertex_location_texture_normal* _return);
void sjf_sphereVertexBuffer_heap(int32_t slices, int32_t wedges, sjs_vec3* origin, sjs_vec3* radius, sjs_vertexBuffer_vertex_location_texture_normal_heap** _return);
void sjf_string(sjs_string* _this);
void sjf_string_copy(sjs_string* _this, sjs_string* _from);
void sjf_string_destroy(sjs_string* _this);
void sjf_string_heap(sjs_string_heap* _this);
void sjf_texture(sjs_texture* _this);
void sjf_textureFromPng(sjs_string* fileName, sjs_texture* _return);
void sjf_textureFromPng_heap(sjs_string* fileName, sjs_texture_heap** _return);
void sjf_texture_copy(sjs_texture* _this, sjs_texture* _from);
void sjf_texture_destroy(sjs_texture* _this);
void sjf_texture_getSize(sjs_texture* _parent, sjs_size* _return);
void sjf_texture_getSize_heap(sjs_texture* _parent, sjs_size_heap** _return);
void sjf_texture_heap(sjs_texture_heap* _this);
void sjf_vec2(sjs_vec2* _this);
void sjf_vec2_copy(sjs_vec2* _this, sjs_vec2* _from);
void sjf_vec2_destroy(sjs_vec2* _this);
void sjf_vec2_heap(sjs_vec2_heap* _this);
void sjf_vec3(sjs_vec3* _this);
void sjf_vec3_copy(sjs_vec3* _this, sjs_vec3* _from);
void sjf_vec3_cross(sjs_vec3* _parent, sjs_vec3* v, sjs_vec3* _return);
void sjf_vec3_cross_heap(sjs_vec3* _parent, sjs_vec3* v, sjs_vec3_heap** _return);
void sjf_vec3_destroy(sjs_vec3* _this);
void sjf_vec3_dot(sjs_vec3* _parent, sjs_vec3* v, float* _return);
void sjf_vec3_heap(sjs_vec3_heap* _this);
void sjf_vec3_interpolate(sjs_vec3* _parent, sjs_vec3* v, float percent, sjs_vec3* _return);
void sjf_vec3_interpolate_heap(sjs_vec3* _parent, sjs_vec3* v, float percent, sjs_vec3_heap** _return);
void sjf_vec3_isEqual(sjs_vec3* _parent, sjs_vec3* v, bool* _return);
void sjf_vec3_normalize(sjs_vec3* _parent, sjs_vec3* _return);
void sjf_vec3_normalize_heap(sjs_vec3* _parent, sjs_vec3_heap** _return);
void sjf_vec3_subtract(sjs_vec3* _parent, sjs_vec3* v, sjs_vec3* _return);
void sjf_vec3_subtract_heap(sjs_vec3* _parent, sjs_vec3* v, sjs_vec3_heap** _return);
void sjf_vertexBuffer_vertex_location_texture_normal(sjs_vertexBuffer_vertex_location_texture_normal* _this);
void sjf_vertexBuffer_vertex_location_texture_normal_copy(sjs_vertexBuffer_vertex_location_texture_normal* _this, sjs_vertexBuffer_vertex_location_texture_normal* _from);
void sjf_vertexBuffer_vertex_location_texture_normal_destroy(sjs_vertexBuffer_vertex_location_texture_normal* _this);
void sjf_vertexBuffer_vertex_location_texture_normal_heap(sjs_vertexBuffer_vertex_location_texture_normal_heap* _this);
void sjf_vertexBuffer_vertex_location_texture_normal_render(sjs_vertexBuffer_vertex_location_texture_normal* _parent);
void sjf_vertexBuffer_vertex_location_texture_normal_translateScreenToTexture_heap(sjs_vertexBuffer_vertex_location_texture_normal* _parent, sjs_point* screen, sjs_rect* viewport, sjs_mat4* projection, sjs_mat4* view, sjs_mat4* world, sjs_vec2_heap** _return);
void sjf_vertex_location_texture_normal(sjs_vertex_location_texture_normal* _this);
void sjf_vertex_location_texture_normal_copy(sjs_vertex_location_texture_normal* _this, sjs_vertex_location_texture_normal* _from);
void sjf_vertex_location_texture_normal_destroy(sjs_vertex_location_texture_normal* _this);
void sjf_vertex_location_texture_normal_heap(sjs_vertex_location_texture_normal_heap* _this);
void sjf_windowRenderer(sjs_windowRenderer* _this);
void sjf_windowRenderer_copy(sjs_windowRenderer* _this, sjs_windowRenderer* _from);
void sjf_windowRenderer_destroy(sjs_windowRenderer* _this);
void sjf_windowRenderer_getSize(sjs_windowRenderer* _parent, sjs_size* _return);
void sjf_windowRenderer_getSize_heap(sjs_windowRenderer* _parent, sjs_size_heap** _return);
void sjf_windowRenderer_heap(sjs_windowRenderer_heap* _this);
void sjf_windowRenderer_present(sjs_windowRenderer* _parent);
void sji_anon5_animation_copy(sji_anon5_animation* _this, sji_anon5_animation* _from);
void sji_anon5_animation_destroy(sji_anon5_animation* _this);
void sji_element_copy(sji_element* _this, sji_element* _from);
void sji_element_destroy(sji_element* _this);
void sji_scene3dElement_model_copy(sji_scene3dElement_model* _this, sji_scene3dElement_model* _from);
void sji_scene3dElement_model_destroy(sji_scene3dElement_model* _this);
void main_destroy(void);


void halt(const char * format, ...) {
    va_list args;
    va_start (args, format);
    vprintf (format, args);
    va_end (args);
    exit(-1);
}


void _retain(void* ptr) {
    pointer* p;
    HASH_FIND_PTR(g_pointers, &ptr, p);
    if (p) {
        p->refCount++;
    } else {
        p = (pointer*)malloc(sizeof(pointer));
        p->ptr = ptr;
        p->refCount = 1;
        HASH_ADD_PTR(g_pointers, ptr, p);
    }
}
bool _release(void* ptr) {
    pointer* p;
    HASH_FIND_PTR(g_pointers, &ptr, p);
    if (p) {
        p->refCount--;
        if (p->refCount == 0) {
            HASH_DEL(g_pointers, p);
            free(p);
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


void _retainGLid(GLuint id) {
    GLid_s* p;
    HASH_FIND_PTR(g_GLids, &id, p);
    if (p) {
        p->refCount++;
    } else {
        p = (GLid_s*)malloc(sizeof(GLid_s));
        p->id = id;
        p->refCount = 1;
        HASH_ADD_PTR(g_GLids, id, p);
    }
}
bool _releaseGLid(GLuint id) {
    GLid_s* p;
    HASH_FIND_PTR(g_GLids, &id, p);
    if (p) {
        p->refCount--;
        if (p->refCount == 0) {
            HASH_DEL(g_GLids, p);
            free(p);
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

void sjf_animation_vec3(sjs_animation_vec3* _this) {
}

sjs_object* sjf_animation_vec3_asInterface(sjs_animation_vec3* _this, int typeId) {
    switch (typeId) {
        case sji_anon5_animation_typeId:  {
            return (sjs_object*)sjf_animation_vec3_as_sji_anon5_animation(_this);
        }
    }

    return 0;
}

sji_anon5_animation* sjf_animation_vec3_as_sji_anon5_animation(sjs_animation_vec3* _this) {
    sji_anon5_animation* _interface;
    _interface = (sji_anon5_animation*)malloc(sizeof(sji_anon5_animation));
    _interface->_refCount = 1;
    _interface->_parent = (sjs_object*)_this;
    _interface->_parent->_refCount++;
    _interface->destroy = (void(*)(void*))sjf_animation_vec3_destroy;
    _interface->asInterface = (sjs_object*(*)(sjs_object*,int))sjf_animation_vec3_asInterface;
    _interface->nextFrame = (void(*)(void*,int32_t, bool*))sjf_animation_vec3_nextFrame;

    return _interface;
}

void sjf_animation_vec3_copy(sjs_animation_vec3* _this, sjs_animation_vec3* _from) {
#line 5 ".\..\lib\ui\animation.sj"
    _this->start = _from->start;
#line 5
    sjf_vec3_copy(&_this->startValue, &_from->startValue);
#line 5
    _this->end = _from->end;
#line 5
    sjf_vec3_copy(&_this->endValue, &_from->endValue);
#line 0 ""
    _this->setValue.inner._parent = _from->setValue.inner._parent;
    ((sjs_object*)((char*)_this->setValue.inner._parent - sizeof(intptr_t)))->_refCount++;
    _this->setValue.inner._cb = _from->setValue.inner._cb;
    _this->setValue._destroy = _from->setValue._destroy;
}

void sjf_animation_vec3_destroy(sjs_animation_vec3* _this) {
    if ((uintptr_t)_this->setValue.inner._parent > 1) {
        ((sjs_object*)((char*)_this->setValue.inner._parent - sizeof(intptr_t)))->_refCount--;
        if (((sjs_object*)((char*)_this->setValue.inner._parent - sizeof(intptr_t)))->_refCount <= 0) {
            _this->setValue._destroy(_this->setValue.inner._parent);
        }
    }
}

void sjf_animation_vec3_heap(sjs_animation_vec3_heap* _this) {
}

sjs_object* sjf_animation_vec3_heap_asInterface(sjs_animation_vec3_heap* _this, int typeId) {
    switch (typeId) {
        case sji_anon5_animation_typeId:  {
            return (sjs_object*)sjf_animation_vec3_heap_as_sji_anon5_animation(_this);
        }
    }

    return 0;
}

sji_anon5_animation* sjf_animation_vec3_heap_as_sji_anon5_animation(sjs_animation_vec3_heap* _this) {
    sji_anon5_animation* _interface;
    _interface = (sji_anon5_animation*)malloc(sizeof(sji_anon5_animation));
    _interface->_refCount = 1;
    _interface->_parent = (sjs_object*)_this;
    _interface->_parent->_refCount++;
    _interface->destroy = (void(*)(void*))sjf_animation_vec3_destroy;
    _interface->asInterface = (sjs_object*(*)(sjs_object*,int))sjf_animation_vec3_heap_asInterface;
    _interface->nextFrame = (void(*)(void*,int32_t, bool*))sjf_animation_vec3_nextFrame;

    return _interface;
}

void sjf_animation_vec3_nextFrame(sjs_animation_vec3* _parent, int32_t time, bool* _return) {
    sjs_vec3 sjt_call1;
    cb_vec3_void sjt_callback1;
    int32_t sjt_cast6;
    int32_t sjt_cast7;
    float sjt_compare10;
    float sjt_compare5;
    float sjt_compare6;
    float sjt_compare9;
    sjs_animation_vec3* sjt_dot29;
    sjs_animation_vec3* sjt_dot30;
    sjs_animation_vec3* sjt_dot31;
    sjs_animation_vec3* sjt_dot32;
    sjs_animation_vec3* sjt_dot45;
    sjs_animation_vec3* sjt_dot46;
    sjs_vec3* sjt_functionParam13;
    sjs_vec3* sjt_functionParam14;
    float sjt_functionParam15;
    bool sjt_ifElse3;
    int32_t sjt_math10;
    int32_t sjt_math11;
    int32_t sjt_math12;
    float sjt_math7;
    float sjt_math8;
    int32_t sjt_math9;
    sjs_vec3* sjt_parent11;
    float sjv_percent;

#line 12 ".\..\lib\ui\animation.sj"
    sjt_math9 = time;
#line 12
    sjt_dot29 = _parent;
#line 13
    sjt_math10 = (sjt_dot29)->start;
#line 13
    sjt_cast6 = sjt_math9 - sjt_math10;
#line 13
    sjt_math7 = (float)sjt_cast6;
#line 12
    sjt_dot30 = _parent;
#line 13
    sjt_math11 = (sjt_dot30)->end;
#line 12
    sjt_dot31 = _parent;
#line 13
    sjt_math12 = (sjt_dot31)->start;
#line 13
    sjt_cast7 = sjt_math11 - sjt_math12;
#line 13
    sjt_math8 = (float)sjt_cast7;
#line 13
    sjv_percent = sjt_math7 / sjt_math8;
#line 14
    sjt_compare5 = sjv_percent;
#line 14
    sjt_compare6 = 0.0f;
#line 14
    sjt_ifElse3 = sjt_compare5 < sjt_compare6;
    if (sjt_ifElse3) {
#line 15 ".\..\lib\ui\animation.sj"
        sjv_percent = 0.0f;
    } else {
        float sjt_compare7;
        float sjt_compare8;
        bool sjt_ifElse4;

#line 16 ".\..\lib\ui\animation.sj"
        sjt_compare7 = sjv_percent;
#line 16
        sjt_compare8 = 1.0f;
#line 16
        sjt_ifElse4 = sjt_compare7 > sjt_compare8;
        if (sjt_ifElse4) {
#line 17 ".\..\lib\ui\animation.sj"
            sjv_percent = 1.0f;
        }
    }

#line 12
    sjt_dot32 = _parent;
#line 21
    sjt_callback1 = (sjt_dot32)->setValue.inner;
#line 12
    sjt_dot45 = _parent;
#line 10 ".\..\lib\ui\vec3.sj"
    sjt_parent11 = &(sjt_dot45)->startValue;
#line 12 ".\..\lib\ui\animation.sj"
    sjt_dot46 = _parent;
#line 21
    sjt_functionParam14 = &(sjt_dot46)->endValue;
#line 21
    sjt_functionParam15 = sjv_percent;
#line 0 ""
    sjf_vec3_interpolate(sjt_parent11, sjt_functionParam14, sjt_functionParam15, &sjt_call1);
#line 21 ".\..\lib\ui\animation.sj"
    sjt_functionParam13 = &sjt_call1;
#line 0 ""
    sjt_callback1._cb(sjt_callback1._parent, sjt_functionParam13);
#line 23 ".\..\lib\ui\animation.sj"
    sjt_compare9 = sjv_percent;
#line 23
    sjt_compare10 = 1.0f;
#line 23
    (*_return) = sjt_compare9 == sjt_compare10;

    sjf_vec3_destroy(&sjt_call1);
}

void sjf_anon1(sjs_anon1* _this) {
}

void sjf_anon1_copy(sjs_anon1* _this, sjs_anon1* _from) {
}

void sjf_anon1_destroy(sjs_anon1* _this) {
}

void sjf_anon1_heap(sjs_anon1_heap* _this) {
}

void sjf_anon2(sjs_anon2* _this) {
}

void sjf_anon2_copy(sjs_anon2* _this, sjs_anon2* _from) {
}

void sjf_anon2_destroy(sjs_anon2* _this) {
}

void sjf_anon2_heap(sjs_anon2_heap* _this) {
}

void sjf_anon3(sjs_anon3* _this) {
}

void sjf_anon3_copy(sjs_anon3* _this, sjs_anon3* _from) {
}

void sjf_anon3_destroy(sjs_anon3* _this) {
}

void sjf_anon3_heap(sjs_anon3_heap* _this) {
}

void sjf_anon4(sjs_anon4* _this) {
}

void sjf_anon4_copy(sjs_anon4* _this, sjs_anon4* _from) {
}

void sjf_anon4_destroy(sjs_anon4* _this) {
}

void sjf_anon4_heap(sjs_anon4_heap* _this) {
}

void sjf_anon5(sjs_anon5* _this) {
}

void sjf_anon5_copy(sjs_anon5* _this, sjs_anon5* _from) {
#line 27 ".\..\lib\ui\animation.sj"
    sjf_list_heap_animation_copy(&_this->animations, &_from->animations);
#line 27
    _this->current = _from->current;
}

void sjf_anon5_destroy(sjs_anon5* _this) {
}

void sjf_anon5_heap(sjs_anon5_heap* _this) {
}

void sjf_anon5_nextFrame(sjs_anon5* _parent, int32_t time) {
    int32_t sjt_compare73;
    int32_t sjt_compare74;
    sjs_anon5* sjt_dot1428;
    sjs_list_heap_animation* sjt_dot1429;
    sjs_anon5* sjt_dot1430;
    bool sjt_ifElse42;

#line 31 ".\..\lib\ui\animation.sj"
    sjt_dot1428 = _parent;
#line 31
    sjt_dot1428->current = time;
#line 31
    sjt_dot1430 = _parent;
#line 1 ".\..\lib\common\list.sj"
    sjt_dot1429 = &(sjt_dot1430)->animations;
#line 33 ".\..\lib\ui\animation.sj"
    sjt_compare73 = (sjt_dot1429)->count;
#line 33
    sjt_compare74 = 0;
#line 33
    sjt_ifElse42 = sjt_compare73 > sjt_compare74;
    if (sjt_ifElse42) {
        int32_t i;
        sjs_list_heap_animation* sjt_dot1431;
        sjs_anon5* sjt_dot1432;
        int32_t sjt_forEnd21;
        int32_t sjt_forStart21;

#line 35 ".\..\lib\ui\animation.sj"
        sjt_forStart21 = 0;
#line 35
        i = sjt_forStart21;
#line 31
        sjt_dot1432 = _parent;
#line 1 ".\..\lib\common\list.sj"
        sjt_dot1431 = &(sjt_dot1432)->animations;
#line 35 ".\..\lib\ui\animation.sj"
        sjt_forEnd21 = (sjt_dot1431)->count;
        while (i < sjt_forEnd21) {
            sjs_list_heap_animation* sjt_dot1433;
            sjs_anon5* sjt_dot1434;
            sjs_anon5* sjt_dot1436;
            int32_t sjt_functionParam418;
            bool sjt_ifElse43;
            int32_t sjt_interfaceParam15;
            int32_t sjt_math2709;
            int32_t sjt_math2710;
            int32_t sjt_math2711;
            int32_t sjt_math2712;
            sjs_list_heap_animation* sjt_parent236;
            sji_anon5_animation* sjt_parent237;
            sji_anon5_animation* sjv_a;
            int32_t sjv_index;

#line 31 ".\..\lib\ui\animation.sj"
            sjt_dot1434 = _parent;
#line 1 ".\..\lib\common\list.sj"
            sjt_dot1433 = &(sjt_dot1434)->animations;
#line 36 ".\..\lib\ui\animation.sj"
            sjt_math2711 = (sjt_dot1433)->count;
#line 36
            sjt_math2712 = 0;
#line 36
            sjt_math2709 = sjt_math2711 - sjt_math2712;
#line 36
            sjt_math2710 = 1;
#line 36
            sjv_index = sjt_math2709 - sjt_math2710;
#line 31
            sjt_dot1436 = _parent;
#line 19 ".\..\lib\common\list.sj"
            sjt_parent236 = &(sjt_dot1436)->animations;
#line 37 ".\..\lib\ui\animation.sj"
            sjt_functionParam418 = sjv_index;
#line 0 ""
            sjf_list_heap_animation_getAt_heap(sjt_parent236, sjt_functionParam418, &sjv_a);
#line 2 ".\..\lib\ui\animation.sj"
            sjt_parent237 = sjv_a;
#line 31
            sjt_interfaceParam15 = time;
#line 38
            sjt_parent237->nextFrame((void*)(((char*)sjt_parent237->_parent) + sizeof(intptr_t)), sjt_interfaceParam15, &sjt_ifElse43);
            if (sjt_ifElse43) {
                sjs_anon5* sjt_dot1437;
                int32_t sjt_functionParam419;
                sjs_list_heap_animation* sjt_parent238;

#line 31 ".\..\lib\ui\animation.sj"
                sjt_dot1437 = _parent;
#line 27 ".\..\lib\common\list.sj"
                sjt_parent238 = &(sjt_dot1437)->animations;
#line 39 ".\..\lib\ui\animation.sj"
                sjt_functionParam419 = sjv_index;
#line 0 ""
                sjf_list_heap_animation_removeAt(sjt_parent238, sjt_functionParam419);
            }

#line 35
            i++;

            sjv_a->_refCount--;
            if (sjv_a->_refCount <= 0) {
                sji_anon5_animation_destroy(sjv_a);
            }
        }
    }
}

void sjf_anon6(sjs_anon6* _this) {
}

void sjf_anon6_copy(sjs_anon6* _this, sjs_anon6* _from) {
#line 1 ".\..\lib\ui\borderLayout.sj"
    _this->fill = _from->fill;
#line 1
    _this->left = _from->left;
#line 1
    _this->right = _from->right;
#line 1
    _this->top = _from->top;
#line 1
    _this->bottom = _from->bottom;
}

void sjf_anon6_destroy(sjs_anon6* _this) {
}

void sjf_anon6_heap(sjs_anon6_heap* _this) {
}

void sjf_anon7(sjs_anon7* _this) {
}

void sjf_anon7_copy(sjs_anon7* _this, sjs_anon7* _from) {
#line 1 ".\..\lib\ui\buttonElement.sj"
    _this->normal = _from->normal;
#line 1
    _this->hot = _from->hot;
#line 1
    _this->pressed = _from->pressed;
}

void sjf_anon7_destroy(sjs_anon7* _this) {
}

void sjf_anon7_heap(sjs_anon7_heap* _this) {
}

void sjf_anon8(sjs_anon8* _this) {
}

void sjf_anon8_blue(sjs_anon8* _parent, sjs_color* _return) {
#line 4 ".\..\lib\ui\color.sj"
    _return->r = 0.0f;
#line 4
    _return->g = 0.0f;
#line 4
    _return->b = 1.0f;
#line 13
    _return->a = 1.0f;
#line 0 ""
    sjf_color(_return);
}

void sjf_anon8_blue_heap(sjs_anon8* _parent, sjs_color_heap** _return) {
    (*_return) = (sjs_color_heap*)malloc(sizeof(sjs_color_heap));
    (*_return)->_refCount = 1;
#line 4 ".\..\lib\ui\color.sj"
    (*_return)->r = 0.0f;
#line 4
    (*_return)->g = 0.0f;
#line 4
    (*_return)->b = 1.0f;
#line 13
    (*_return)->a = 1.0f;
#line 0 ""
    sjf_color_heap((*_return));
}

void sjf_anon8_copy(sjs_anon8* _this, sjs_anon8* _from) {
}

void sjf_anon8_destroy(sjs_anon8* _this) {
}

void sjf_anon8_heap(sjs_anon8_heap* _this) {
}

void sjf_anon8_red(sjs_anon8* _parent, sjs_color* _return) {
#line 2 ".\..\lib\ui\color.sj"
    _return->r = 1.0f;
#line 2
    _return->g = 0.0f;
#line 2
    _return->b = 0.0f;
#line 13
    _return->a = 1.0f;
#line 0 ""
    sjf_color(_return);
}

void sjf_anon8_red_heap(sjs_anon8* _parent, sjs_color_heap** _return) {
    (*_return) = (sjs_color_heap*)malloc(sizeof(sjs_color_heap));
    (*_return)->_refCount = 1;
#line 2 ".\..\lib\ui\color.sj"
    (*_return)->r = 1.0f;
#line 2
    (*_return)->g = 0.0f;
#line 2
    (*_return)->b = 0.0f;
#line 13
    (*_return)->a = 1.0f;
#line 0 ""
    sjf_color_heap((*_return));
}

void sjf_anon9(sjs_anon9* _this) {
}

void sjf_anon9_copy(sjs_anon9* _this, sjs_anon9* _from) {
}

void sjf_anon9_destroy(sjs_anon9* _this) {
}

void sjf_anon9_heap(sjs_anon9_heap* _this) {
}

void sjf_array_char(sjs_array_char* _this) {
#line 110 ".\..\lib\common\array.sj"
    if (_this->size < 0) {
#line 110
        halt("size is less than zero");
#line 110
    }
#line 110
    if (_this->data) {
#line 110
        _this->_isGlobal = true;
#line 110
    } else {
#line 110
        _this->data = (uintptr_t)calloc(_this->size * sizeof(char), 1);
#line 110
        if (!_this->data) {
#line 110
            halt("grow: out of memory\n");
#line 110
        }
#line 110
    }
}

void sjf_array_char_copy(sjs_array_char* _this, sjs_array_char* _from) {
#line 1 ".\..\lib\common\array.sj"
    _this->size = _from->size;
#line 1
    _this->data = _from->data;
#line 1
    _this->_isGlobal = _from->_isGlobal;
#line 128
    _this->data = _from->data;
#line 128
    if (!_this->_isGlobal && _this->data) {
#line 128
        _retain((void*)_this->data);
#line 128
    }
}

void sjf_array_char_destroy(sjs_array_char* _this) {
#line 135 ".\..\lib\common\array.sj"
    if (!_this->_isGlobal && _this->data) {
#line 135
        if (_release((void*)_this->data)) {
#line 135
            free((char*)_this->data);
#line 135
        }
#line 135
    }
}

void sjf_array_char_heap(sjs_array_char_heap* _this) {
#line 110 ".\..\lib\common\array.sj"
    if (_this->size < 0) {
#line 110
        halt("size is less than zero");
#line 110
    }
#line 110
    if (_this->data) {
#line 110
        _this->_isGlobal = true;
#line 110
    } else {
#line 110
        _this->data = (uintptr_t)calloc(_this->size * sizeof(char), 1);
#line 110
        if (!_this->data) {
#line 110
            halt("grow: out of memory\n");
#line 110
        }
#line 110
    }
}

void sjf_array_heap_animation(sjs_array_heap_animation* _this) {
#line 110 ".\..\lib\common\array.sj"
    if (_this->size < 0) {
#line 110
        halt("size is less than zero");
#line 110
    }
#line 110
    if (_this->data) {
#line 110
        _this->_isGlobal = true;
#line 110
    } else {
#line 110
        _this->data = (uintptr_t)calloc(_this->size * sizeof(sji_anon5_animation*), 1);
#line 110
        if (!_this->data) {
#line 110
            halt("grow: out of memory\n");
#line 110
        }
#line 110
    }
}

void sjf_array_heap_animation_copy(sjs_array_heap_animation* _this, sjs_array_heap_animation* _from) {
#line 1 ".\..\lib\common\array.sj"
    _this->size = _from->size;
#line 1
    _this->data = _from->data;
#line 1
    _this->_isGlobal = _from->_isGlobal;
#line 128
    _this->data = _from->data;
#line 128
    if (!_this->_isGlobal && _this->data) {
#line 128
        _retain((void*)_this->data);
#line 128
    }
}

void sjf_array_heap_animation_destroy(sjs_array_heap_animation* _this) {
#line 135 ".\..\lib\common\array.sj"
    if (!_this->_isGlobal && _this->data) {
#line 135
        if (_release((void*)_this->data)) {
#line 135
            free((sji_anon5_animation**)_this->data);
#line 135
        }
#line 135
    }
}

void sjf_array_heap_animation_getAt_heap(sjs_array_heap_animation* _parent, int32_t index, sji_anon5_animation** _return) {
#line 6 ".\..\lib\common\array.sj"
    if (index >= _parent->size || index < 0) {
#line 6
        halt("getAt: out of bounds\n");
#line 6
    }
#line 6
    sji_anon5_animation** p = (sji_anon5_animation**)_parent->data;
#line 6
    #line 6 ".\..\lib\common\array.sj"
#line 6
    (*_return) = p[index];
#line 6
    #line 0 ""
#line 6
    (*_return)->_refCount++;
#line 6
    ;
}

void sjf_array_heap_animation_grow(sjs_array_heap_animation* _parent, int32_t new_size) {
#line 59 ".\..\lib\common\array.sj"
    if (_parent->size != new_size) {
#line 59
        if (new_size < _parent->size) {
#line 59
            halt("grow: new _parent->size smaller than old _parent->size %d:%d\n", new_size, _parent->size);
#line 59
        }
#line 59
        if (_parent->_isGlobal) {
#line 59
            _parent->_isGlobal = false;
#line 59
            sji_anon5_animation** p = (sji_anon5_animation**)_parent->data;
#line 59
            _parent->data = (uintptr_t)calloc(new_size * sizeof(sji_anon5_animation*), 1);
#line 59
            if (!_parent->data) {
#line 59
                halt("grow: out of memory\n");
#line 59
            }
#line 59
            memcpy((void*)_parent->data, p, _parent->size * sizeof(sji_anon5_animation*));
#line 59
        } else {
#line 59
            _parent->data = (uintptr_t)realloc((void*)_parent->data, new_size * sizeof(sji_anon5_animation*));
#line 59
            if (!_parent->data) {
#line 59
                halt("grow: out of memory\n");
#line 59
            }
#line 59
            memset((sji_anon5_animation**)_parent->data + _parent->size, 0, (new_size - _parent->size) * sizeof(sji_anon5_animation*));
#line 59
        }
#line 59
        _parent->size = new_size;
#line 59
    }
}

void sjf_array_heap_animation_heap(sjs_array_heap_animation_heap* _this) {
#line 110 ".\..\lib\common\array.sj"
    if (_this->size < 0) {
#line 110
        halt("size is less than zero");
#line 110
    }
#line 110
    if (_this->data) {
#line 110
        _this->_isGlobal = true;
#line 110
    } else {
#line 110
        _this->data = (uintptr_t)calloc(_this->size * sizeof(sji_anon5_animation*), 1);
#line 110
        if (!_this->data) {
#line 110
            halt("grow: out of memory\n");
#line 110
        }
#line 110
    }
}

void sjf_array_heap_animation_initAt(sjs_array_heap_animation* _parent, int32_t index, sji_anon5_animation* item) {
#line 17 ".\..\lib\common\array.sj"
    if (index >= _parent->size || index < 0) {
#line 17
        halt("setAt: out of bounds %d:%d\n", index, _parent->size);
#line 17
    }
#line 17
    sji_anon5_animation** p = (sji_anon5_animation**)_parent->data;
#line 17
    #line 16 ".\..\lib\common\array.sj"
#line 17
    p[index] = item;
#line 17
    #line 0 ""
#line 17
    p[index]->_refCount++;
#line 17
    ;
}

void sjf_array_heap_element(sjs_array_heap_element* _this) {
#line 110 ".\..\lib\common\array.sj"
    if (_this->size < 0) {
#line 110
        halt("size is less than zero");
#line 110
    }
#line 110
    if (_this->data) {
#line 110
        _this->_isGlobal = true;
#line 110
    } else {
#line 110
        _this->data = (uintptr_t)calloc(_this->size * sizeof(sji_element*), 1);
#line 110
        if (!_this->data) {
#line 110
            halt("grow: out of memory\n");
#line 110
        }
#line 110
    }
}

void sjf_array_heap_element_copy(sjs_array_heap_element* _this, sjs_array_heap_element* _from) {
#line 1 ".\..\lib\common\array.sj"
    _this->size = _from->size;
#line 1
    _this->data = _from->data;
#line 1
    _this->_isGlobal = _from->_isGlobal;
#line 128
    _this->data = _from->data;
#line 128
    if (!_this->_isGlobal && _this->data) {
#line 128
        _retain((void*)_this->data);
#line 128
    }
}

void sjf_array_heap_element_destroy(sjs_array_heap_element* _this) {
#line 135 ".\..\lib\common\array.sj"
    if (!_this->_isGlobal && _this->data) {
#line 135
        if (_release((void*)_this->data)) {
#line 135
            free((sji_element**)_this->data);
#line 135
        }
#line 135
    }
}

void sjf_array_heap_element_getAt_heap(sjs_array_heap_element* _parent, int32_t index, sji_element** _return) {
#line 6 ".\..\lib\common\array.sj"
    if (index >= _parent->size || index < 0) {
#line 6
        halt("getAt: out of bounds\n");
#line 6
    }
#line 6
    sji_element** p = (sji_element**)_parent->data;
#line 6
    #line 6 ".\..\lib\common\array.sj"
#line 6
    (*_return) = p[index];
#line 6
    #line 0 ""
#line 6
    (*_return)->_refCount++;
#line 6
    ;
}

void sjf_array_heap_element_heap(sjs_array_heap_element_heap* _this) {
#line 110 ".\..\lib\common\array.sj"
    if (_this->size < 0) {
#line 110
        halt("size is less than zero");
#line 110
    }
#line 110
    if (_this->data) {
#line 110
        _this->_isGlobal = true;
#line 110
    } else {
#line 110
        _this->data = (uintptr_t)calloc(_this->size * sizeof(sji_element*), 1);
#line 110
        if (!_this->data) {
#line 110
            halt("grow: out of memory\n");
#line 110
        }
#line 110
    }
}

void sjf_array_heap_element_initAt(sjs_array_heap_element* _parent, int32_t index, sji_element* item) {
#line 17 ".\..\lib\common\array.sj"
    if (index >= _parent->size || index < 0) {
#line 17
        halt("setAt: out of bounds %d:%d\n", index, _parent->size);
#line 17
    }
#line 17
    sji_element** p = (sji_element**)_parent->data;
#line 17
    #line 16 ".\..\lib\common\array.sj"
#line 17
    p[index] = item;
#line 17
    #line 0 ""
#line 17
    p[index]->_refCount++;
#line 17
    ;
}

void sjf_array_heap_model(sjs_array_heap_model* _this) {
#line 110 ".\..\lib\common\array.sj"
    if (_this->size < 0) {
#line 110
        halt("size is less than zero");
#line 110
    }
#line 110
    if (_this->data) {
#line 110
        _this->_isGlobal = true;
#line 110
    } else {
#line 110
        _this->data = (uintptr_t)calloc(_this->size * sizeof(sji_scene3dElement_model*), 1);
#line 110
        if (!_this->data) {
#line 110
            halt("grow: out of memory\n");
#line 110
        }
#line 110
    }
}

void sjf_array_heap_model_copy(sjs_array_heap_model* _this, sjs_array_heap_model* _from) {
#line 1 ".\..\lib\common\array.sj"
    _this->size = _from->size;
#line 1
    _this->data = _from->data;
#line 1
    _this->_isGlobal = _from->_isGlobal;
#line 128
    _this->data = _from->data;
#line 128
    if (!_this->_isGlobal && _this->data) {
#line 128
        _retain((void*)_this->data);
#line 128
    }
}

void sjf_array_heap_model_destroy(sjs_array_heap_model* _this) {
#line 135 ".\..\lib\common\array.sj"
    if (!_this->_isGlobal && _this->data) {
#line 135
        if (_release((void*)_this->data)) {
#line 135
            free((sji_scene3dElement_model**)_this->data);
#line 135
        }
#line 135
    }
}

void sjf_array_heap_model_getAt_heap(sjs_array_heap_model* _parent, int32_t index, sji_scene3dElement_model** _return) {
#line 6 ".\..\lib\common\array.sj"
    if (index >= _parent->size || index < 0) {
#line 6
        halt("getAt: out of bounds\n");
#line 6
    }
#line 6
    sji_scene3dElement_model** p = (sji_scene3dElement_model**)_parent->data;
#line 6
    #line 6 ".\..\lib\common\array.sj"
#line 6
    (*_return) = p[index];
#line 6
    #line 0 ""
#line 6
    (*_return)->_refCount++;
#line 6
    ;
}

void sjf_array_heap_model_heap(sjs_array_heap_model_heap* _this) {
#line 110 ".\..\lib\common\array.sj"
    if (_this->size < 0) {
#line 110
        halt("size is less than zero");
#line 110
    }
#line 110
    if (_this->data) {
#line 110
        _this->_isGlobal = true;
#line 110
    } else {
#line 110
        _this->data = (uintptr_t)calloc(_this->size * sizeof(sji_scene3dElement_model*), 1);
#line 110
        if (!_this->data) {
#line 110
            halt("grow: out of memory\n");
#line 110
        }
#line 110
    }
}

void sjf_array_heap_model_initAt(sjs_array_heap_model* _parent, int32_t index, sji_scene3dElement_model* item) {
#line 17 ".\..\lib\common\array.sj"
    if (index >= _parent->size || index < 0) {
#line 17
        halt("setAt: out of bounds %d:%d\n", index, _parent->size);
#line 17
    }
#line 17
    sji_scene3dElement_model** p = (sji_scene3dElement_model**)_parent->data;
#line 17
    #line 16 ".\..\lib\common\array.sj"
#line 17
    p[index] = item;
#line 17
    #line 0 ""
#line 17
    p[index]->_refCount++;
#line 17
    ;
}

void sjf_array_i32(sjs_array_i32* _this) {
#line 110 ".\..\lib\common\array.sj"
    if (_this->size < 0) {
#line 110
        halt("size is less than zero");
#line 110
    }
#line 110
    if (_this->data) {
#line 110
        _this->_isGlobal = true;
#line 110
    } else {
#line 110
        _this->data = (uintptr_t)calloc(_this->size * sizeof(int32_t), 1);
#line 110
        if (!_this->data) {
#line 110
            halt("grow: out of memory\n");
#line 110
        }
#line 110
    }
}

void sjf_array_i32_copy(sjs_array_i32* _this, sjs_array_i32* _from) {
#line 1 ".\..\lib\common\array.sj"
    _this->size = _from->size;
#line 1
    _this->data = _from->data;
#line 1
    _this->_isGlobal = _from->_isGlobal;
#line 128
    _this->data = _from->data;
#line 128
    if (!_this->_isGlobal && _this->data) {
#line 128
        _retain((void*)_this->data);
#line 128
    }
}

void sjf_array_i32_destroy(sjs_array_i32* _this) {
#line 135 ".\..\lib\common\array.sj"
    if (!_this->_isGlobal && _this->data) {
#line 135
        if (_release((void*)_this->data)) {
#line 135
            free((int32_t*)_this->data);
#line 135
        }
#line 135
    }
}

void sjf_array_i32_getAt(sjs_array_i32* _parent, int32_t index, int32_t* _return) {
#line 6 ".\..\lib\common\array.sj"
    if (index >= _parent->size || index < 0) {
#line 6
        halt("getAt: out of bounds\n");
#line 6
    }
#line 6
    int32_t* p = (int32_t*)_parent->data;
#line 6
    #line 6 ".\..\lib\common\array.sj"
#line 6
    (*_return) = p[index];
#line 6
    ;
}

void sjf_array_i32_heap(sjs_array_i32_heap* _this) {
#line 110 ".\..\lib\common\array.sj"
    if (_this->size < 0) {
#line 110
        halt("size is less than zero");
#line 110
    }
#line 110
    if (_this->data) {
#line 110
        _this->_isGlobal = true;
#line 110
    } else {
#line 110
        _this->data = (uintptr_t)calloc(_this->size * sizeof(int32_t), 1);
#line 110
        if (!_this->data) {
#line 110
            halt("grow: out of memory\n");
#line 110
        }
#line 110
    }
}

void sjf_array_i32_initAt(sjs_array_i32* _parent, int32_t index, int32_t item) {
#line 17 ".\..\lib\common\array.sj"
    if (index >= _parent->size || index < 0) {
#line 17
        halt("setAt: out of bounds %d:%d\n", index, _parent->size);
#line 17
    }
#line 17
    int32_t* p = (int32_t*)_parent->data;
#line 17
    #line 16 ".\..\lib\common\array.sj"
#line 17
    p[index] = item;
#line 17
    ;
}

void sjf_array_local_cb_void(sjs_array_local_cb_void* _this) {
#line 110 ".\..\lib\common\array.sj"
    if (_this->size < 0) {
#line 110
        halt("size is less than zero");
#line 110
    }
#line 110
    if (_this->data) {
#line 110
        _this->_isGlobal = true;
#line 110
    } else {
#line 110
        _this->data = (uintptr_t)calloc(_this->size * sizeof(cb_void), 1);
#line 110
        if (!_this->data) {
#line 110
            halt("grow: out of memory\n");
#line 110
        }
#line 110
    }
}

void sjf_array_local_cb_void_copy(sjs_array_local_cb_void* _this, sjs_array_local_cb_void* _from) {
#line 1 ".\..\lib\common\array.sj"
    _this->size = _from->size;
#line 1
    _this->data = _from->data;
#line 1
    _this->_isGlobal = _from->_isGlobal;
#line 128
    _this->data = _from->data;
#line 128
    if (!_this->_isGlobal && _this->data) {
#line 128
        _retain((void*)_this->data);
#line 128
    }
}

void sjf_array_local_cb_void_destroy(sjs_array_local_cb_void* _this) {
#line 135 ".\..\lib\common\array.sj"
    if (!_this->_isGlobal && _this->data) {
#line 135
        if (_release((void*)_this->data)) {
#line 135
            free((cb_void*)_this->data);
#line 135
        }
#line 135
    }
}

void sjf_array_local_cb_void_getAt(sjs_array_local_cb_void* _parent, int32_t index, cb_void* _return) {
#line 6 ".\..\lib\common\array.sj"
    if (index >= _parent->size || index < 0) {
#line 6
        halt("getAt: out of bounds\n");
#line 6
    }
#line 6
    cb_void* p = (cb_void*)_parent->data;
#line 6
    #line 6 ".\..\lib\common\array.sj"
#line 6
    (*_return) = p[index];
#line 6
    ;
}

void sjf_array_local_cb_void_heap(sjs_array_local_cb_void_heap* _this) {
#line 110 ".\..\lib\common\array.sj"
    if (_this->size < 0) {
#line 110
        halt("size is less than zero");
#line 110
    }
#line 110
    if (_this->data) {
#line 110
        _this->_isGlobal = true;
#line 110
    } else {
#line 110
        _this->data = (uintptr_t)calloc(_this->size * sizeof(cb_void), 1);
#line 110
        if (!_this->data) {
#line 110
            halt("grow: out of memory\n");
#line 110
        }
#line 110
    }
}

void sjf_array_vertex_location_texture_normal(sjs_array_vertex_location_texture_normal* _this) {
#line 110 ".\..\lib\common\array.sj"
    if (_this->size < 0) {
#line 110
        halt("size is less than zero");
#line 110
    }
#line 110
    if (_this->data) {
#line 110
        _this->_isGlobal = true;
#line 110
    } else {
#line 110
        _this->data = (uintptr_t)calloc(_this->size * sizeof(sjs_vertex_location_texture_normal), 1);
#line 110
        if (!_this->data) {
#line 110
            halt("grow: out of memory\n");
#line 110
        }
#line 110
    }
}

void sjf_array_vertex_location_texture_normal_copy(sjs_array_vertex_location_texture_normal* _this, sjs_array_vertex_location_texture_normal* _from) {
#line 1 ".\..\lib\common\array.sj"
    _this->size = _from->size;
#line 1
    _this->data = _from->data;
#line 1
    _this->_isGlobal = _from->_isGlobal;
#line 128
    _this->data = _from->data;
#line 128
    if (!_this->_isGlobal && _this->data) {
#line 128
        _retain((void*)_this->data);
#line 128
    }
}

void sjf_array_vertex_location_texture_normal_destroy(sjs_array_vertex_location_texture_normal* _this) {
#line 135 ".\..\lib\common\array.sj"
    if (!_this->_isGlobal && _this->data) {
#line 135
        if (_release((void*)_this->data)) {
#line 135
            free((sjs_vertex_location_texture_normal*)_this->data);
#line 135
        }
#line 135
    }
}

void sjf_array_vertex_location_texture_normal_getAt(sjs_array_vertex_location_texture_normal* _parent, int32_t index, sjs_vertex_location_texture_normal* _return) {
#line 6 ".\..\lib\common\array.sj"
    if (index >= _parent->size || index < 0) {
#line 6
        halt("getAt: out of bounds\n");
#line 6
    }
#line 6
    sjs_vertex_location_texture_normal* p = (sjs_vertex_location_texture_normal*)_parent->data;
#line 6
    #line 6 ".\..\lib\common\array.sj"
#line 6
    sjf_vertex_location_texture_normal_copy(_return, &p[index]);
#line 6
    ;
}

void sjf_array_vertex_location_texture_normal_heap(sjs_array_vertex_location_texture_normal_heap* _this) {
#line 110 ".\..\lib\common\array.sj"
    if (_this->size < 0) {
#line 110
        halt("size is less than zero");
#line 110
    }
#line 110
    if (_this->data) {
#line 110
        _this->_isGlobal = true;
#line 110
    } else {
#line 110
        _this->data = (uintptr_t)calloc(_this->size * sizeof(sjs_vertex_location_texture_normal), 1);
#line 110
        if (!_this->data) {
#line 110
            halt("grow: out of memory\n");
#line 110
        }
#line 110
    }
}

void sjf_array_vertex_location_texture_normal_initAt(sjs_array_vertex_location_texture_normal* _parent, int32_t index, sjs_vertex_location_texture_normal* item) {
#line 17 ".\..\lib\common\array.sj"
    if (index >= _parent->size || index < 0) {
#line 17
        halt("setAt: out of bounds %d:%d\n", index, _parent->size);
#line 17
    }
#line 17
    sjs_vertex_location_texture_normal* p = (sjs_vertex_location_texture_normal*)_parent->data;
#line 17
    #line 16 ".\..\lib\common\array.sj"
#line 17
    sjf_vertex_location_texture_normal_copy(&p[index], item);
#line 17
    ;
}

void sjf_boxRenderer(sjs_boxRenderer* _this) {
#line 19 ".\..\lib\ui\boxRenderer.sj"
    _this->buffer = vertex_buffer_new("vertex:3f,color:4f");
#line 19
    float x0 = (float)_this->rect.x;
#line 19
    float y0 = (float)(_this->rect.y + _this->rect.h);
#line 19
    float x1 = (float)(_this->rect.x + _this->rect.w);
#line 19
    float y1 = (float)_this->rect.y;
#line 19
    GLuint index = (GLuint)_this->buffer->vertices->size;
#line 19
    GLuint indices[] = { //
#line 19
    index, index+1, index+2,
#line 19
    index, index+2, index+3 };
#line 19
    vertex3_color4_t vertices[] = { //
#line 19
    { x0, y1, 0.0f,  _this->color.r, _this->color.g, _this->color.b, _this->color.a },
#line 19
    { x0, y0, 0.0f,  _this->color.r, _this->color.g, _this->color.b, _this->color.a },
#line 19
    { x1, y0, 0.0f,  _this->color.r, _this->color.g, _this->color.b, _this->color.a },
#line 19
    { x1, y1, 0.0f,  _this->color.r, _this->color.g, _this->color.b, _this->color.a } };
#line 19
    vertex_buffer_push_back_indices( _this->buffer, indices, 6 );
#line 19
    vertex_buffer_push_back_vertices( _this->buffer, vertices, 4 );
}

void sjf_boxRenderer_copy(sjs_boxRenderer* _this, sjs_boxRenderer* _from) {
#line 1 ".\..\lib\ui\boxRenderer.sj"
    sjf_rect_copy(&_this->rect, &_from->rect);
#line 1
    sjf_color_copy(&_this->color, &_from->color);
#line 39
    _this->buffer = _from->buffer;
#line 39
    _retain(_this->buffer);
}

void sjf_boxRenderer_destroy(sjs_boxRenderer* _this) {
#line 44 ".\..\lib\ui\boxRenderer.sj"
    if (_release(_this->buffer)) {
#line 44
        vertex_buffer_delete(_this->buffer);
#line 44
    }
}

void sjf_boxRenderer_heap(sjs_boxRenderer_heap* _this) {
#line 19 ".\..\lib\ui\boxRenderer.sj"
    _this->buffer = vertex_buffer_new("vertex:3f,color:4f");
#line 19
    float x0 = (float)_this->rect.x;
#line 19
    float y0 = (float)(_this->rect.y + _this->rect.h);
#line 19
    float x1 = (float)(_this->rect.x + _this->rect.w);
#line 19
    float y1 = (float)_this->rect.y;
#line 19
    GLuint index = (GLuint)_this->buffer->vertices->size;
#line 19
    GLuint indices[] = { //
#line 19
    index, index+1, index+2,
#line 19
    index, index+2, index+3 };
#line 19
    vertex3_color4_t vertices[] = { //
#line 19
    { x0, y1, 0.0f,  _this->color.r, _this->color.g, _this->color.b, _this->color.a },
#line 19
    { x0, y0, 0.0f,  _this->color.r, _this->color.g, _this->color.b, _this->color.a },
#line 19
    { x1, y0, 0.0f,  _this->color.r, _this->color.g, _this->color.b, _this->color.a },
#line 19
    { x1, y1, 0.0f,  _this->color.r, _this->color.g, _this->color.b, _this->color.a } };
#line 19
    vertex_buffer_push_back_indices( _this->buffer, indices, 6 );
#line 19
    vertex_buffer_push_back_vertices( _this->buffer, vertices, 4 );
}

void sjf_boxRenderer_render(sjs_boxRenderer* _parent, sjs_scene2d* scene) {
#line 9 ".\..\lib\ui\boxRenderer.sj"
    glUseProgram(sjv_boxShader.id);
#line 9
    glUniformMatrix4fv(glGetUniformLocation(sjv_boxShader.id, "model" ), 1, 0, (GLfloat*)&scene->model);
#line 9
    glUniformMatrix4fv(glGetUniformLocation(sjv_boxShader.id, "view" ), 1, 0, (GLfloat*)&scene->view);
#line 9
    glUniformMatrix4fv(glGetUniformLocation(sjv_boxShader.id, "projection" ), 1, 0, (GLfloat*)&scene->projection);
#line 9
    vertex_buffer_render(_parent->buffer, GL_TRIANGLES);
}

void sjf_color(sjs_color* _this) {
}

void sjf_color_copy(sjs_color* _this, sjs_color* _from) {
#line 9 ".\..\lib\ui\color.sj"
    _this->r = _from->r;
#line 9
    _this->g = _from->g;
#line 9
    _this->b = _from->b;
#line 9
    _this->a = _from->a;
}

void sjf_color_destroy(sjs_color* _this) {
}

void sjf_color_heap(sjs_color_heap* _this) {
}

void sjf_crossHairsElement(sjs_crossHairsElement* _this) {
}

sjs_object* sjf_crossHairsElement_asInterface(sjs_crossHairsElement* _this, int typeId) {
    switch (typeId) {
        case sji_element_typeId:  {
            return (sjs_object*)sjf_crossHairsElement_as_sji_element(_this);
        }
    }

    return 0;
}

sji_element* sjf_crossHairsElement_as_sji_element(sjs_crossHairsElement* _this) {
    sji_element* _interface;
    _interface = (sji_element*)malloc(sizeof(sji_element));
    _interface->_refCount = 1;
    _interface->_parent = (sjs_object*)_this;
    _interface->_parent->_refCount++;
    _interface->destroy = (void(*)(void*))sjf_crossHairsElement_destroy;
    _interface->asInterface = (sjs_object*(*)(sjs_object*,int))sjf_crossHairsElement_asInterface;
    _interface->getSize = (void(*)(void*,sjs_size*, sjs_size*))sjf_crossHairsElement_getSize;
    _interface->getSize_heap = (void(*)(void*,sjs_size*, sjs_size_heap**))sjf_crossHairsElement_getSize_heap;
    _interface->getRect = (void(*)(void*, sjs_rect**))sjf_crossHairsElement_getRect;
    _interface->setRect = (void(*)(void*,sjs_rect*))sjf_crossHairsElement_setRect;
    _interface->render = (void(*)(void*,sjs_scene2d*))sjf_crossHairsElement_render;
    _interface->getChildren = (void(*)(void*, sjs_array_heap_element**))sjf_crossHairsElement_getChildren;
    _interface->fireMouseEvent = (void(*)(void*,sjs_point*,int32_t))sjf_crossHairsElement_fireMouseEvent;

    return _interface;
}

void sjf_crossHairsElement_copy(sjs_crossHairsElement* _this, sjs_crossHairsElement* _from) {
#line 1 ".\..\lib\ui\crossHairsElement.sj"
    sjf_color_copy(&_this->color, &_from->color);
#line 1
    sjf_rect_copy(&_this->_rect, &_from->_rect);
#line 0 ""
    _this->_topDownRenderer = 0;
#line 1 ".\..\lib\ui\crossHairsElement.sj"
    sjf_boxRenderer_copy((sjs_boxRenderer*)(((char*)_this->_topDownRenderer) + sizeof(intptr_t)), (sjs_boxRenderer*)(((char*)_from->_topDownRenderer) + sizeof(intptr_t)));
#line 0 ""
    _this->_leftRightRenderer = 0;
#line 1 ".\..\lib\ui\crossHairsElement.sj"
    sjf_boxRenderer_copy((sjs_boxRenderer*)(((char*)_this->_leftRightRenderer) + sizeof(intptr_t)), (sjs_boxRenderer*)(((char*)_from->_leftRightRenderer) + sizeof(intptr_t)));
#line 1
    sjf_point_copy(&_this->_point, &_from->_point);
}

void sjf_crossHairsElement_destroy(sjs_crossHairsElement* _this) {
    if (_this->_topDownRenderer != 0) {
        _this->_topDownRenderer->_refCount--;
        if (_this->_topDownRenderer->_refCount <= 0) {
            sjf_boxRenderer_destroy((sjs_boxRenderer*)(((char*)_this->_topDownRenderer) + sizeof(intptr_t)));
        }
    }

    if (_this->_leftRightRenderer != 0) {
        _this->_leftRightRenderer->_refCount--;
        if (_this->_leftRightRenderer->_refCount <= 0) {
            sjf_boxRenderer_destroy((sjs_boxRenderer*)(((char*)_this->_leftRightRenderer) + sizeof(intptr_t)));
        }
    }
}

void sjf_crossHairsElement_fireMouseEvent(sjs_crossHairsElement* _parent, sjs_point* point, int32_t eventId) {
    sjs_crossHairsElement* sjt_dot1424;
    sjs_point* sjt_functionParam164;
    bool sjt_ifElse40;
    sjs_rect* sjt_parent111;

#line 45 ".\..\lib\ui\crossHairsElement.sj"
    sjt_dot1424 = _parent;
#line 11 ".\..\lib\ui\rect.sj"
    sjt_parent111 = &(sjt_dot1424)->_rect;
#line 45 ".\..\lib\ui\crossHairsElement.sj"
    sjt_functionParam164 = point;
#line 0 ""
    sjf_rect_containsPoint(sjt_parent111, sjt_functionParam164, &sjt_ifElse40);
    if (sjt_ifElse40) {
        int32_t sjt_compare71;
        int32_t sjt_compare72;
        bool sjt_ifElse41;

#line 45 ".\..\lib\ui\crossHairsElement.sj"
        sjt_compare71 = eventId;
#line 47
        sjt_compare72 = sjv_mouseEvent_move;
#line 47
        sjt_ifElse41 = sjt_compare71 == sjt_compare72;
        if (sjt_ifElse41) {
            sjs_crossHairsElement* sjt_dot1425;
            sjs_crossHairsElement* sjt_dot1426;
            sjs_crossHairsElement* sjt_dot1427;

#line 45 ".\..\lib\ui\crossHairsElement.sj"
            sjt_dot1425 = _parent;
#line 45
            sjf_point_copy(&sjt_dot1425->_point, point);
#line 45
            sjt_dot1426 = _parent;
            if (sjt_dot1426->_topDownRenderer != 0) {
                sjt_dot1426->_topDownRenderer->_refCount--;
                if (sjt_dot1426->_topDownRenderer->_refCount <= 0) {
                    sjf_boxRenderer_destroy((sjs_boxRenderer*)(((char*)sjt_dot1426->_topDownRenderer) + sizeof(intptr_t)));
                }
            }

#line 49
            sjt_dot1426->_topDownRenderer = 0;
            if (sjt_dot1426->_topDownRenderer != 0) {
                sjt_dot1426->_topDownRenderer->_refCount++;
            }

#line 45
            sjt_dot1427 = _parent;
            if (sjt_dot1427->_leftRightRenderer != 0) {
                sjt_dot1427->_leftRightRenderer->_refCount--;
                if (sjt_dot1427->_leftRightRenderer->_refCount <= 0) {
                    sjf_boxRenderer_destroy((sjs_boxRenderer*)(((char*)sjt_dot1427->_leftRightRenderer) + sizeof(intptr_t)));
                }
            }

#line 50
            sjt_dot1427->_leftRightRenderer = 0;
            if (sjt_dot1427->_leftRightRenderer != 0) {
                sjt_dot1427->_leftRightRenderer->_refCount++;
            }
        }
    }
}

void sjf_crossHairsElement_getChildren(sjs_crossHairsElement* _parent, sjs_array_heap_element** _return) {
#line 42 ".\..\lib\ui\crossHairsElement.sj"
    (*_return) = 0;
}

void sjf_crossHairsElement_getRect(sjs_crossHairsElement* _parent, sjs_rect** _return) {
    sjs_crossHairsElement* sjt_dot1387;

#line 12 ".\..\lib\ui\crossHairsElement.sj"
    sjt_dot1387 = _parent;
#line 12
    (*_return) = &(sjt_dot1387)->_rect;
}

void sjf_crossHairsElement_getSize(sjs_crossHairsElement* _parent, sjs_size* maxSize, sjs_size* _return) {
    sjs_size* sjt_dot1383;
    sjs_size* sjt_dot1384;

#line 8 ".\..\lib\ui\crossHairsElement.sj"
    sjt_dot1383 = maxSize;
#line 9
    _return->w = (sjt_dot1383)->w;
#line 8
    sjt_dot1384 = maxSize;
#line 9
    _return->h = (sjt_dot1384)->h;
#line 0 ""
    sjf_size(_return);
}

void sjf_crossHairsElement_getSize_heap(sjs_crossHairsElement* _parent, sjs_size* maxSize, sjs_size_heap** _return) {
    sjs_size* sjt_dot1385;
    sjs_size* sjt_dot1386;

    (*_return) = (sjs_size_heap*)malloc(sizeof(sjs_size_heap));
    (*_return)->_refCount = 1;
#line 8 ".\..\lib\ui\crossHairsElement.sj"
    sjt_dot1385 = maxSize;
#line 9
    (*_return)->w = (sjt_dot1385)->w;
#line 8
    sjt_dot1386 = maxSize;
#line 9
    (*_return)->h = (sjt_dot1386)->h;
#line 0 ""
    sjf_size_heap((*_return));
}

void sjf_crossHairsElement_heap(sjs_crossHairsElement_heap* _this) {
}

sjs_object* sjf_crossHairsElement_heap_asInterface(sjs_crossHairsElement_heap* _this, int typeId) {
    switch (typeId) {
        case sji_element_typeId:  {
            return (sjs_object*)sjf_crossHairsElement_heap_as_sji_element(_this);
        }
    }

    return 0;
}

sji_element* sjf_crossHairsElement_heap_as_sji_element(sjs_crossHairsElement_heap* _this) {
    sji_element* _interface;
    _interface = (sji_element*)malloc(sizeof(sji_element));
    _interface->_refCount = 1;
    _interface->_parent = (sjs_object*)_this;
    _interface->_parent->_refCount++;
    _interface->destroy = (void(*)(void*))sjf_crossHairsElement_destroy;
    _interface->asInterface = (sjs_object*(*)(sjs_object*,int))sjf_crossHairsElement_heap_asInterface;
    _interface->getSize = (void(*)(void*,sjs_size*, sjs_size*))sjf_crossHairsElement_getSize;
    _interface->getSize_heap = (void(*)(void*,sjs_size*, sjs_size_heap**))sjf_crossHairsElement_getSize_heap;
    _interface->getRect = (void(*)(void*, sjs_rect**))sjf_crossHairsElement_getRect;
    _interface->setRect = (void(*)(void*,sjs_rect*))sjf_crossHairsElement_setRect;
    _interface->render = (void(*)(void*,sjs_scene2d*))sjf_crossHairsElement_render;
    _interface->getChildren = (void(*)(void*, sjs_array_heap_element**))sjf_crossHairsElement_getChildren;
    _interface->fireMouseEvent = (void(*)(void*,sjs_point*,int32_t))sjf_crossHairsElement_fireMouseEvent;

    return _interface;
}

void sjf_crossHairsElement_render(sjs_crossHairsElement* _parent, sjs_scene2d* scene) {
    bool result17;
    bool result18;
    sjs_crossHairsElement* sjt_dot1392;
    sjs_crossHairsElement* sjt_dot1401;
    sjs_crossHairsElement* sjt_dot1410;
    sjs_crossHairsElement* sjt_dot1412;
    bool sjt_ifElse36;
    bool sjt_ifElse37;
    bool sjt_ifElse38;
    bool sjt_ifElse39;
    sjs_boxRenderer_heap* sjt_isEmpty12;
    sjs_boxRenderer_heap* sjt_isEmpty13;
    sjs_boxRenderer_heap* sjt_isEmpty14;
    sjs_boxRenderer_heap* sjt_isEmpty15;
    bool sjt_not10;
    bool sjt_not9;

#line 24 ".\..\lib\ui\crossHairsElement.sj"
    sjt_dot1392 = _parent;
#line 25
    sjt_isEmpty12 = (sjt_dot1392)->_topDownRenderer;
    if (sjt_isEmpty12 != 0) {
        sjt_isEmpty12->_refCount++;
    }

#line 25
    sjt_ifElse36 = (sjt_isEmpty12 == 0);
    if (sjt_ifElse36) {
        sjs_crossHairsElement* sjt_dot1393;
        sjs_point* sjt_dot1394;
        sjs_crossHairsElement* sjt_dot1395;
        sjs_rect* sjt_dot1396;
        sjs_crossHairsElement* sjt_dot1397;
        sjs_rect* sjt_dot1398;
        sjs_crossHairsElement* sjt_dot1399;
        sjs_crossHairsElement* sjt_dot1400;
        sjs_boxRenderer_heap* sjt_value9;

#line 24 ".\..\lib\ui\crossHairsElement.sj"
        sjt_dot1393 = _parent;
#line 0 ""
        sjt_value9 = (sjs_boxRenderer_heap*)malloc(sizeof(sjs_boxRenderer_heap));
        sjt_value9->_refCount = 1;
#line 24 ".\..\lib\ui\crossHairsElement.sj"
        sjt_dot1395 = _parent;
#line 1 ".\..\lib\ui\point.sj"
        sjt_dot1394 = &(sjt_dot1395)->_point;
#line 27 ".\..\lib\ui\crossHairsElement.sj"
        sjt_value9->rect.x = (sjt_dot1394)->x;
#line 24
        sjt_dot1397 = _parent;
#line 1 ".\..\lib\ui\rect.sj"
        sjt_dot1396 = &(sjt_dot1397)->_rect;
#line 27 ".\..\lib\ui\crossHairsElement.sj"
        sjt_value9->rect.y = (sjt_dot1396)->y;
#line 27
        sjt_value9->rect.w = 1;
#line 24
        sjt_dot1399 = _parent;
#line 1 ".\..\lib\ui\rect.sj"
        sjt_dot1398 = &(sjt_dot1399)->_rect;
#line 27 ".\..\lib\ui\crossHairsElement.sj"
        sjt_value9->rect.h = (sjt_dot1398)->h;
#line 0 ""
        sjf_rect(&sjt_value9->rect);
#line 24 ".\..\lib\ui\crossHairsElement.sj"
        sjt_dot1400 = _parent;
#line 26
        sjf_color_copy(&sjt_value9->color, &(sjt_dot1400)->color);
#line 0 ""
        sjf_boxRenderer_heap(sjt_value9);
        if (sjt_dot1393->_topDownRenderer != 0) {
            sjt_dot1393->_topDownRenderer->_refCount--;
            if (sjt_dot1393->_topDownRenderer->_refCount <= 0) {
                sjf_boxRenderer_destroy((sjs_boxRenderer*)(((char*)sjt_dot1393->_topDownRenderer) + sizeof(intptr_t)));
            }
        }

#line 26 ".\..\lib\ui\crossHairsElement.sj"
        sjt_dot1393->_topDownRenderer = sjt_value9;
        if (sjt_dot1393->_topDownRenderer != 0) {
            sjt_dot1393->_topDownRenderer->_refCount++;
        }

        sjt_value9->_refCount--;
        if (sjt_value9->_refCount <= 0) {
            sjf_boxRenderer_destroy((sjs_boxRenderer*)(((char*)sjt_value9) + sizeof(intptr_t)));
        }
    }

#line 24
    sjt_dot1401 = _parent;
#line 31
    sjt_isEmpty13 = (sjt_dot1401)->_leftRightRenderer;
    if (sjt_isEmpty13 != 0) {
        sjt_isEmpty13->_refCount++;
    }

#line 31
    sjt_ifElse37 = (sjt_isEmpty13 == 0);
    if (sjt_ifElse37) {
        sjs_crossHairsElement* sjt_dot1402;
        sjs_rect* sjt_dot1403;
        sjs_crossHairsElement* sjt_dot1404;
        sjs_point* sjt_dot1405;
        sjs_crossHairsElement* sjt_dot1406;
        sjs_rect* sjt_dot1407;
        sjs_crossHairsElement* sjt_dot1408;
        sjs_crossHairsElement* sjt_dot1409;
        sjs_boxRenderer_heap* sjt_value10;

#line 24 ".\..\lib\ui\crossHairsElement.sj"
        sjt_dot1402 = _parent;
#line 0 ""
        sjt_value10 = (sjs_boxRenderer_heap*)malloc(sizeof(sjs_boxRenderer_heap));
        sjt_value10->_refCount = 1;
#line 24 ".\..\lib\ui\crossHairsElement.sj"
        sjt_dot1404 = _parent;
#line 1 ".\..\lib\ui\rect.sj"
        sjt_dot1403 = &(sjt_dot1404)->_rect;
#line 33 ".\..\lib\ui\crossHairsElement.sj"
        sjt_value10->rect.x = (sjt_dot1403)->x;
#line 24
        sjt_dot1406 = _parent;
#line 1 ".\..\lib\ui\point.sj"
        sjt_dot1405 = &(sjt_dot1406)->_point;
#line 33 ".\..\lib\ui\crossHairsElement.sj"
        sjt_value10->rect.y = (sjt_dot1405)->y;
#line 24
        sjt_dot1408 = _parent;
#line 1 ".\..\lib\ui\rect.sj"
        sjt_dot1407 = &(sjt_dot1408)->_rect;
#line 33 ".\..\lib\ui\crossHairsElement.sj"
        sjt_value10->rect.w = (sjt_dot1407)->w;
#line 33
        sjt_value10->rect.h = 1;
#line 0 ""
        sjf_rect(&sjt_value10->rect);
#line 24 ".\..\lib\ui\crossHairsElement.sj"
        sjt_dot1409 = _parent;
#line 32
        sjf_color_copy(&sjt_value10->color, &(sjt_dot1409)->color);
#line 0 ""
        sjf_boxRenderer_heap(sjt_value10);
        if (sjt_dot1402->_leftRightRenderer != 0) {
            sjt_dot1402->_leftRightRenderer->_refCount--;
            if (sjt_dot1402->_leftRightRenderer->_refCount <= 0) {
                sjf_boxRenderer_destroy((sjs_boxRenderer*)(((char*)sjt_dot1402->_leftRightRenderer) + sizeof(intptr_t)));
            }
        }

#line 32 ".\..\lib\ui\crossHairsElement.sj"
        sjt_dot1402->_leftRightRenderer = sjt_value10;
        if (sjt_dot1402->_leftRightRenderer != 0) {
            sjt_dot1402->_leftRightRenderer->_refCount++;
        }

        sjt_value10->_refCount--;
        if (sjt_value10->_refCount <= 0) {
            sjf_boxRenderer_destroy((sjs_boxRenderer*)(((char*)sjt_value10) + sizeof(intptr_t)));
        }
    }

#line 24
    sjt_dot1410 = _parent;
#line 37
    sjt_isEmpty14 = (sjt_dot1410)->_topDownRenderer;
    if (sjt_isEmpty14 != 0) {
        sjt_isEmpty14->_refCount++;
    }

#line 37
    sjt_not9 = (sjt_isEmpty14 == 0);
#line 37
    result17 = !sjt_not9;
#line 37
    sjt_ifElse38 = result17;
    if (sjt_ifElse38) {
        sjs_crossHairsElement* sjt_dot1411;
        sjs_scene2d* sjt_functionParam162;
        sjs_boxRenderer_heap* sjt_getValue9;
        sjs_boxRenderer* sjt_parent109;

#line 24 ".\..\lib\ui\crossHairsElement.sj"
        sjt_dot1411 = _parent;
#line 37
        sjt_getValue9 = (sjt_dot1411)->_topDownRenderer;
        if (sjt_getValue9 != 0) {
            sjt_getValue9->_refCount++;
        }

#line 37
        sjt_parent109 = (sjs_boxRenderer*)(((char*)sjt_getValue9) + sizeof(intptr_t));
#line 24
        sjt_functionParam162 = scene;
#line 0 ""
        sjf_boxRenderer_render(sjt_parent109, sjt_functionParam162);

        if (sjt_getValue9 != 0) {
            sjt_getValue9->_refCount--;
            if (sjt_getValue9->_refCount <= 0) {
                sjf_boxRenderer_destroy((sjs_boxRenderer*)(((char*)sjt_getValue9) + sizeof(intptr_t)));
            }
        }
    }

#line 24
    sjt_dot1412 = _parent;
#line 38
    sjt_isEmpty15 = (sjt_dot1412)->_leftRightRenderer;
    if (sjt_isEmpty15 != 0) {
        sjt_isEmpty15->_refCount++;
    }

#line 38
    sjt_not10 = (sjt_isEmpty15 == 0);
#line 38
    result18 = !sjt_not10;
#line 38
    sjt_ifElse39 = result18;
    if (sjt_ifElse39) {
        sjs_crossHairsElement* sjt_dot1413;
        sjs_scene2d* sjt_functionParam163;
        sjs_boxRenderer_heap* sjt_getValue10;
        sjs_boxRenderer* sjt_parent110;

#line 24 ".\..\lib\ui\crossHairsElement.sj"
        sjt_dot1413 = _parent;
#line 38
        sjt_getValue10 = (sjt_dot1413)->_leftRightRenderer;
        if (sjt_getValue10 != 0) {
            sjt_getValue10->_refCount++;
        }

#line 38
        sjt_parent110 = (sjs_boxRenderer*)(((char*)sjt_getValue10) + sizeof(intptr_t));
#line 24
        sjt_functionParam163 = scene;
#line 0 ""
        sjf_boxRenderer_render(sjt_parent110, sjt_functionParam163);

        if (sjt_getValue10 != 0) {
            sjt_getValue10->_refCount--;
            if (sjt_getValue10->_refCount <= 0) {
                sjf_boxRenderer_destroy((sjs_boxRenderer*)(((char*)sjt_getValue10) + sizeof(intptr_t)));
            }
        }
    }

    if (sjt_isEmpty12 != 0) {
        sjt_isEmpty12->_refCount--;
        if (sjt_isEmpty12->_refCount <= 0) {
            sjf_boxRenderer_destroy((sjs_boxRenderer*)(((char*)sjt_isEmpty12) + sizeof(intptr_t)));
        }
    }
    if (sjt_isEmpty13 != 0) {
        sjt_isEmpty13->_refCount--;
        if (sjt_isEmpty13->_refCount <= 0) {
            sjf_boxRenderer_destroy((sjs_boxRenderer*)(((char*)sjt_isEmpty13) + sizeof(intptr_t)));
        }
    }
    if (sjt_isEmpty14 != 0) {
        sjt_isEmpty14->_refCount--;
        if (sjt_isEmpty14->_refCount <= 0) {
            sjf_boxRenderer_destroy((sjs_boxRenderer*)(((char*)sjt_isEmpty14) + sizeof(intptr_t)));
        }
    }
    if (sjt_isEmpty15 != 0) {
        sjt_isEmpty15->_refCount--;
        if (sjt_isEmpty15->_refCount <= 0) {
            sjf_boxRenderer_destroy((sjs_boxRenderer*)(((char*)sjt_isEmpty15) + sizeof(intptr_t)));
        }
    }
}

void sjf_crossHairsElement_setRect(sjs_crossHairsElement* _parent, sjs_rect* rect_) {
    bool result16;
    sjs_crossHairsElement* sjt_dot1388;
    sjs_rect* sjt_functionParam161;
    bool sjt_ifElse35;
    bool sjt_not8;
    sjs_rect* sjt_parent108;

#line 14 ".\..\lib\ui\crossHairsElement.sj"
    sjt_dot1388 = _parent;
#line 15 ".\..\lib\ui\rect.sj"
    sjt_parent108 = &(sjt_dot1388)->_rect;
#line 14 ".\..\lib\ui\crossHairsElement.sj"
    sjt_functionParam161 = rect_;
#line 0 ""
    sjf_rect_isEqual(sjt_parent108, sjt_functionParam161, &sjt_not8);
#line 15 ".\..\lib\ui\crossHairsElement.sj"
    result16 = !sjt_not8;
#line 15
    sjt_ifElse35 = result16;
    if (sjt_ifElse35) {
        sjs_crossHairsElement* sjt_dot1389;
        sjs_crossHairsElement* sjt_dot1390;
        sjs_crossHairsElement* sjt_dot1391;

#line 14 ".\..\lib\ui\crossHairsElement.sj"
        sjt_dot1389 = _parent;
#line 14
        sjf_rect_copy(&sjt_dot1389->_rect, rect_);
#line 14
        sjt_dot1390 = _parent;
        if (sjt_dot1390->_topDownRenderer != 0) {
            sjt_dot1390->_topDownRenderer->_refCount--;
            if (sjt_dot1390->_topDownRenderer->_refCount <= 0) {
                sjf_boxRenderer_destroy((sjs_boxRenderer*)(((char*)sjt_dot1390->_topDownRenderer) + sizeof(intptr_t)));
            }
        }

#line 17
        sjt_dot1390->_topDownRenderer = 0;
        if (sjt_dot1390->_topDownRenderer != 0) {
            sjt_dot1390->_topDownRenderer->_refCount++;
        }

#line 14
        sjt_dot1391 = _parent;
        if (sjt_dot1391->_leftRightRenderer != 0) {
            sjt_dot1391->_leftRightRenderer->_refCount--;
            if (sjt_dot1391->_leftRightRenderer->_refCount <= 0) {
                sjf_boxRenderer_destroy((sjs_boxRenderer*)(((char*)sjt_dot1391->_leftRightRenderer) + sizeof(intptr_t)));
            }
        }

#line 18
        sjt_dot1391->_leftRightRenderer = 0;
        if (sjt_dot1391->_leftRightRenderer != 0) {
            sjt_dot1391->_leftRightRenderer->_refCount++;
        }
    }
}

void sjf_cubeVertexBuffer(float x0, float x1, float y0, float y1, float z0, float z1, float s0, float s1, float t0, float t1, sjs_vertexBuffer_vertex_location_texture_normal* _return) {
    float result20;
    float result21;
    float result22;
    float result23;
    float result24;
    float result25;
    float result26;
    float result27;
    float result28;
    float result29;
    float result30;
    float result31;
    sjs_vertex_location_texture_normal sjt_call10;
    sjs_vertex_location_texture_normal sjt_call11;
    sjs_vertex_location_texture_normal sjt_call12;
    sjs_vertex_location_texture_normal sjt_call13;
    sjs_vertex_location_texture_normal sjt_call14;
    sjs_vertex_location_texture_normal sjt_call15;
    sjs_vertex_location_texture_normal sjt_call16;
    sjs_vertex_location_texture_normal sjt_call17;
    sjs_vertex_location_texture_normal sjt_call18;
    sjs_vertex_location_texture_normal sjt_call19;
    sjs_vertex_location_texture_normal sjt_call20;
    sjs_vertex_location_texture_normal sjt_call21;
    sjs_vertex_location_texture_normal sjt_call22;
    sjs_vertex_location_texture_normal sjt_call23;
    sjs_vertex_location_texture_normal sjt_call24;
    sjs_vertex_location_texture_normal sjt_call25;
    sjs_vertex_location_texture_normal sjt_call26;
    sjs_vertex_location_texture_normal sjt_call27;
    sjs_vertex_location_texture_normal sjt_call28;
    sjs_vertex_location_texture_normal sjt_call29;
    sjs_vertex_location_texture_normal sjt_call30;
    sjs_vertex_location_texture_normal sjt_call31;
    sjs_vertex_location_texture_normal sjt_call32;
    sjs_vertex_location_texture_normal sjt_call33;
    int32_t sjt_cast46;
    int32_t sjt_cast47;
    int32_t sjt_functionParam165;
    int32_t sjt_functionParam166;
    int32_t sjt_functionParam167;
    int32_t sjt_functionParam168;
    int32_t sjt_functionParam169;
    int32_t sjt_functionParam170;
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
    int32_t sjt_functionParam184;
    int32_t sjt_functionParam185;
    int32_t sjt_functionParam186;
    int32_t sjt_functionParam187;
    int32_t sjt_functionParam188;
    int32_t sjt_functionParam189;
    int32_t sjt_functionParam190;
    int32_t sjt_functionParam191;
    int32_t sjt_functionParam192;
    int32_t sjt_functionParam193;
    int32_t sjt_functionParam194;
    int32_t sjt_functionParam195;
    int32_t sjt_functionParam196;
    int32_t sjt_functionParam197;
    int32_t sjt_functionParam198;
    int32_t sjt_functionParam199;
    int32_t sjt_functionParam200;
    int32_t sjt_functionParam201;
    int32_t sjt_functionParam202;
    int32_t sjt_functionParam203;
    int32_t sjt_functionParam204;
    int32_t sjt_functionParam205;
    int32_t sjt_functionParam206;
    int32_t sjt_functionParam207;
    int32_t sjt_functionParam208;
    int32_t sjt_functionParam209;
    int32_t sjt_functionParam210;
    int32_t sjt_functionParam211;
    int32_t sjt_functionParam212;
    int32_t sjt_functionParam213;
    int32_t sjt_functionParam214;
    int32_t sjt_functionParam215;
    int32_t sjt_functionParam216;
    int32_t sjt_functionParam217;
    int32_t sjt_functionParam218;
    int32_t sjt_functionParam219;
    int32_t sjt_functionParam220;
    int32_t sjt_functionParam221;
    int32_t sjt_functionParam222;
    int32_t sjt_functionParam223;
    int32_t sjt_functionParam224;
    int32_t sjt_functionParam225;
    int32_t sjt_functionParam226;
    int32_t sjt_functionParam227;
    int32_t sjt_functionParam228;
    int32_t sjt_functionParam229;
    int32_t sjt_functionParam230;
    int32_t sjt_functionParam231;
    int32_t sjt_functionParam232;
    int32_t sjt_functionParam233;
    int32_t sjt_functionParam234;
    int32_t sjt_functionParam235;
    int32_t sjt_functionParam236;
    int32_t sjt_functionParam237;
    sjs_vertex_location_texture_normal* sjt_functionParam238;
    int32_t sjt_functionParam239;
    sjs_vertex_location_texture_normal* sjt_functionParam240;
    int32_t sjt_functionParam241;
    sjs_vertex_location_texture_normal* sjt_functionParam242;
    int32_t sjt_functionParam243;
    sjs_vertex_location_texture_normal* sjt_functionParam244;
    int32_t sjt_functionParam245;
    sjs_vertex_location_texture_normal* sjt_functionParam246;
    int32_t sjt_functionParam247;
    sjs_vertex_location_texture_normal* sjt_functionParam248;
    int32_t sjt_functionParam249;
    sjs_vertex_location_texture_normal* sjt_functionParam250;
    int32_t sjt_functionParam251;
    sjs_vertex_location_texture_normal* sjt_functionParam252;
    int32_t sjt_functionParam253;
    sjs_vertex_location_texture_normal* sjt_functionParam254;
    int32_t sjt_functionParam255;
    sjs_vertex_location_texture_normal* sjt_functionParam256;
    int32_t sjt_functionParam257;
    sjs_vertex_location_texture_normal* sjt_functionParam258;
    int32_t sjt_functionParam259;
    sjs_vertex_location_texture_normal* sjt_functionParam260;
    int32_t sjt_functionParam261;
    sjs_vertex_location_texture_normal* sjt_functionParam262;
    int32_t sjt_functionParam263;
    sjs_vertex_location_texture_normal* sjt_functionParam264;
    int32_t sjt_functionParam265;
    sjs_vertex_location_texture_normal* sjt_functionParam266;
    int32_t sjt_functionParam267;
    sjs_vertex_location_texture_normal* sjt_functionParam268;
    int32_t sjt_functionParam269;
    sjs_vertex_location_texture_normal* sjt_functionParam270;
    int32_t sjt_functionParam271;
    sjs_vertex_location_texture_normal* sjt_functionParam272;
    int32_t sjt_functionParam273;
    sjs_vertex_location_texture_normal* sjt_functionParam274;
    int32_t sjt_functionParam275;
    sjs_vertex_location_texture_normal* sjt_functionParam276;
    int32_t sjt_functionParam277;
    sjs_vertex_location_texture_normal* sjt_functionParam278;
    int32_t sjt_functionParam279;
    sjs_vertex_location_texture_normal* sjt_functionParam280;
    int32_t sjt_functionParam281;
    sjs_vertex_location_texture_normal* sjt_functionParam282;
    int32_t sjt_functionParam283;
    sjs_vertex_location_texture_normal* sjt_functionParam284;
    float sjt_negate10;
    float sjt_negate11;
    float sjt_negate12;
    float sjt_negate13;
    float sjt_negate14;
    float sjt_negate15;
    float sjt_negate16;
    float sjt_negate17;
    float sjt_negate18;
    float sjt_negate19;
    float sjt_negate20;
    float sjt_negate21;
    sjs_array_i32* sjt_parent113;
    sjs_array_i32* sjt_parent114;
    sjs_array_i32* sjt_parent115;
    sjs_array_i32* sjt_parent116;
    sjs_array_i32* sjt_parent117;
    sjs_array_i32* sjt_parent118;
    sjs_array_i32* sjt_parent119;
    sjs_array_i32* sjt_parent120;
    sjs_array_i32* sjt_parent121;
    sjs_array_i32* sjt_parent122;
    sjs_array_i32* sjt_parent123;
    sjs_array_i32* sjt_parent124;
    sjs_array_i32* sjt_parent125;
    sjs_array_i32* sjt_parent126;
    sjs_array_i32* sjt_parent127;
    sjs_array_i32* sjt_parent128;
    sjs_array_i32* sjt_parent129;
    sjs_array_i32* sjt_parent130;
    sjs_array_i32* sjt_parent131;
    sjs_array_i32* sjt_parent132;
    sjs_array_i32* sjt_parent133;
    sjs_array_i32* sjt_parent134;
    sjs_array_i32* sjt_parent135;
    sjs_array_i32* sjt_parent136;
    sjs_array_i32* sjt_parent137;
    sjs_array_i32* sjt_parent138;
    sjs_array_i32* sjt_parent139;
    sjs_array_i32* sjt_parent140;
    sjs_array_i32* sjt_parent141;
    sjs_array_i32* sjt_parent142;
    sjs_array_i32* sjt_parent143;
    sjs_array_i32* sjt_parent144;
    sjs_array_i32* sjt_parent145;
    sjs_array_i32* sjt_parent146;
    sjs_array_i32* sjt_parent147;
    sjs_array_i32* sjt_parent148;
    sjs_array_vertex_location_texture_normal* sjt_parent149;
    sjs_array_vertex_location_texture_normal* sjt_parent150;
    sjs_array_vertex_location_texture_normal* sjt_parent151;
    sjs_array_vertex_location_texture_normal* sjt_parent152;
    sjs_array_vertex_location_texture_normal* sjt_parent153;
    sjs_array_vertex_location_texture_normal* sjt_parent154;
    sjs_array_vertex_location_texture_normal* sjt_parent155;
    sjs_array_vertex_location_texture_normal* sjt_parent156;
    sjs_array_vertex_location_texture_normal* sjt_parent157;
    sjs_array_vertex_location_texture_normal* sjt_parent158;
    sjs_array_vertex_location_texture_normal* sjt_parent159;
    sjs_array_vertex_location_texture_normal* sjt_parent160;
    sjs_array_vertex_location_texture_normal* sjt_parent161;
    sjs_array_vertex_location_texture_normal* sjt_parent162;
    sjs_array_vertex_location_texture_normal* sjt_parent163;
    sjs_array_vertex_location_texture_normal* sjt_parent164;
    sjs_array_vertex_location_texture_normal* sjt_parent165;
    sjs_array_vertex_location_texture_normal* sjt_parent166;
    sjs_array_vertex_location_texture_normal* sjt_parent167;
    sjs_array_vertex_location_texture_normal* sjt_parent168;
    sjs_array_vertex_location_texture_normal* sjt_parent169;
    sjs_array_vertex_location_texture_normal* sjt_parent170;
    sjs_array_vertex_location_texture_normal* sjt_parent171;
    sjs_array_vertex_location_texture_normal* sjt_parent172;

#line 20 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjf_string_copy(&_return->format, &sjv_vertex_location_texture_normal_format);
#line 22
    _return->indices.size = 36;
#line 3 ".\..\lib\common\array.sj"
    sjt_cast46 = 0;
#line 3
    _return->indices.data = (uintptr_t)sjt_cast46;
#line 4
    _return->indices._isGlobal = false;
#line 0 ""
    sjf_array_i32(&_return->indices);
#line 22 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjs_array_i32* array1;
#line 22
    array1 = &_return->indices;
#line 22
    sjt_parent113 = array1;
#line 22
    sjt_functionParam165 = 0;
#line 23
    sjt_functionParam166 = 0;
#line 0 ""
    sjf_array_i32_initAt(sjt_parent113, sjt_functionParam165, sjt_functionParam166);
#line 22 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_parent114 = array1;
#line 22
    sjt_functionParam167 = 1;
#line 23
    sjt_functionParam168 = 1;
#line 0 ""
    sjf_array_i32_initAt(sjt_parent114, sjt_functionParam167, sjt_functionParam168);
#line 22 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_parent115 = array1;
#line 22
    sjt_functionParam169 = 2;
#line 23
    sjt_functionParam170 = 2;
#line 0 ""
    sjf_array_i32_initAt(sjt_parent115, sjt_functionParam169, sjt_functionParam170);
#line 22 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_parent116 = array1;
#line 22
    sjt_functionParam171 = 3;
#line 24
    sjt_functionParam172 = 0;
#line 0 ""
    sjf_array_i32_initAt(sjt_parent116, sjt_functionParam171, sjt_functionParam172);
#line 22 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_parent117 = array1;
#line 22
    sjt_functionParam173 = 4;
#line 24
    sjt_functionParam174 = 2;
#line 0 ""
    sjf_array_i32_initAt(sjt_parent117, sjt_functionParam173, sjt_functionParam174);
#line 22 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_parent118 = array1;
#line 22
    sjt_functionParam175 = 5;
#line 24
    sjt_functionParam176 = 3;
#line 0 ""
    sjf_array_i32_initAt(sjt_parent118, sjt_functionParam175, sjt_functionParam176);
#line 22 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_parent119 = array1;
#line 22
    sjt_functionParam177 = 6;
#line 25
    sjt_functionParam178 = 4;
#line 0 ""
    sjf_array_i32_initAt(sjt_parent119, sjt_functionParam177, sjt_functionParam178);
#line 22 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_parent120 = array1;
#line 22
    sjt_functionParam179 = 7;
#line 25
    sjt_functionParam180 = 5;
#line 0 ""
    sjf_array_i32_initAt(sjt_parent120, sjt_functionParam179, sjt_functionParam180);
#line 22 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_parent121 = array1;
#line 22
    sjt_functionParam181 = 8;
#line 25
    sjt_functionParam182 = 6;
#line 0 ""
    sjf_array_i32_initAt(sjt_parent121, sjt_functionParam181, sjt_functionParam182);
#line 22 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_parent122 = array1;
#line 22
    sjt_functionParam183 = 9;
#line 26
    sjt_functionParam184 = 4;
#line 0 ""
    sjf_array_i32_initAt(sjt_parent122, sjt_functionParam183, sjt_functionParam184);
#line 22 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_parent123 = array1;
#line 22
    sjt_functionParam185 = 10;
#line 26
    sjt_functionParam186 = 6;
#line 0 ""
    sjf_array_i32_initAt(sjt_parent123, sjt_functionParam185, sjt_functionParam186);
#line 22 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_parent124 = array1;
#line 22
    sjt_functionParam187 = 11;
#line 26
    sjt_functionParam188 = 7;
#line 0 ""
    sjf_array_i32_initAt(sjt_parent124, sjt_functionParam187, sjt_functionParam188);
#line 22 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_parent125 = array1;
#line 22
    sjt_functionParam189 = 12;
#line 27
    sjt_functionParam190 = 8;
#line 0 ""
    sjf_array_i32_initAt(sjt_parent125, sjt_functionParam189, sjt_functionParam190);
#line 22 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_parent126 = array1;
#line 22
    sjt_functionParam191 = 13;
#line 27
    sjt_functionParam192 = 9;
#line 0 ""
    sjf_array_i32_initAt(sjt_parent126, sjt_functionParam191, sjt_functionParam192);
#line 22 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_parent127 = array1;
#line 22
    sjt_functionParam193 = 14;
#line 27
    sjt_functionParam194 = 10;
#line 0 ""
    sjf_array_i32_initAt(sjt_parent127, sjt_functionParam193, sjt_functionParam194);
#line 22 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_parent128 = array1;
#line 22
    sjt_functionParam195 = 15;
#line 28
    sjt_functionParam196 = 8;
#line 0 ""
    sjf_array_i32_initAt(sjt_parent128, sjt_functionParam195, sjt_functionParam196);
#line 22 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_parent129 = array1;
#line 22
    sjt_functionParam197 = 16;
#line 28
    sjt_functionParam198 = 10;
#line 0 ""
    sjf_array_i32_initAt(sjt_parent129, sjt_functionParam197, sjt_functionParam198);
#line 22 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_parent130 = array1;
#line 22
    sjt_functionParam199 = 17;
#line 28
    sjt_functionParam200 = 11;
#line 0 ""
    sjf_array_i32_initAt(sjt_parent130, sjt_functionParam199, sjt_functionParam200);
#line 22 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_parent131 = array1;
#line 22
    sjt_functionParam201 = 18;
#line 29
    sjt_functionParam202 = 12;
#line 0 ""
    sjf_array_i32_initAt(sjt_parent131, sjt_functionParam201, sjt_functionParam202);
#line 22 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_parent132 = array1;
#line 22
    sjt_functionParam203 = 19;
#line 29
    sjt_functionParam204 = 13;
#line 0 ""
    sjf_array_i32_initAt(sjt_parent132, sjt_functionParam203, sjt_functionParam204);
#line 22 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_parent133 = array1;
#line 22
    sjt_functionParam205 = 20;
#line 29
    sjt_functionParam206 = 14;
#line 0 ""
    sjf_array_i32_initAt(sjt_parent133, sjt_functionParam205, sjt_functionParam206);
#line 22 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_parent134 = array1;
#line 22
    sjt_functionParam207 = 21;
#line 30
    sjt_functionParam208 = 12;
#line 0 ""
    sjf_array_i32_initAt(sjt_parent134, sjt_functionParam207, sjt_functionParam208);
#line 22 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_parent135 = array1;
#line 22
    sjt_functionParam209 = 22;
#line 30
    sjt_functionParam210 = 14;
#line 0 ""
    sjf_array_i32_initAt(sjt_parent135, sjt_functionParam209, sjt_functionParam210);
#line 22 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_parent136 = array1;
#line 22
    sjt_functionParam211 = 23;
#line 30
    sjt_functionParam212 = 15;
#line 0 ""
    sjf_array_i32_initAt(sjt_parent136, sjt_functionParam211, sjt_functionParam212);
#line 22 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_parent137 = array1;
#line 22
    sjt_functionParam213 = 24;
#line 31
    sjt_functionParam214 = 16;
#line 0 ""
    sjf_array_i32_initAt(sjt_parent137, sjt_functionParam213, sjt_functionParam214);
#line 22 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_parent138 = array1;
#line 22
    sjt_functionParam215 = 25;
#line 31
    sjt_functionParam216 = 17;
#line 0 ""
    sjf_array_i32_initAt(sjt_parent138, sjt_functionParam215, sjt_functionParam216);
#line 22 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_parent139 = array1;
#line 22
    sjt_functionParam217 = 26;
#line 31
    sjt_functionParam218 = 18;
#line 0 ""
    sjf_array_i32_initAt(sjt_parent139, sjt_functionParam217, sjt_functionParam218);
#line 22 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_parent140 = array1;
#line 22
    sjt_functionParam219 = 27;
#line 32
    sjt_functionParam220 = 16;
#line 0 ""
    sjf_array_i32_initAt(sjt_parent140, sjt_functionParam219, sjt_functionParam220);
#line 22 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_parent141 = array1;
#line 22
    sjt_functionParam221 = 28;
#line 32
    sjt_functionParam222 = 18;
#line 0 ""
    sjf_array_i32_initAt(sjt_parent141, sjt_functionParam221, sjt_functionParam222);
#line 22 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_parent142 = array1;
#line 22
    sjt_functionParam223 = 29;
#line 32
    sjt_functionParam224 = 19;
#line 0 ""
    sjf_array_i32_initAt(sjt_parent142, sjt_functionParam223, sjt_functionParam224);
#line 22 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_parent143 = array1;
#line 22
    sjt_functionParam225 = 30;
#line 33
    sjt_functionParam226 = 20;
#line 0 ""
    sjf_array_i32_initAt(sjt_parent143, sjt_functionParam225, sjt_functionParam226);
#line 22 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_parent144 = array1;
#line 22
    sjt_functionParam227 = 31;
#line 33
    sjt_functionParam228 = 21;
#line 0 ""
    sjf_array_i32_initAt(sjt_parent144, sjt_functionParam227, sjt_functionParam228);
#line 22 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_parent145 = array1;
#line 22
    sjt_functionParam229 = 32;
#line 33
    sjt_functionParam230 = 22;
#line 0 ""
    sjf_array_i32_initAt(sjt_parent145, sjt_functionParam229, sjt_functionParam230);
#line 22 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_parent146 = array1;
#line 22
    sjt_functionParam231 = 33;
#line 34
    sjt_functionParam232 = 20;
#line 0 ""
    sjf_array_i32_initAt(sjt_parent146, sjt_functionParam231, sjt_functionParam232);
#line 22 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_parent147 = array1;
#line 22
    sjt_functionParam233 = 34;
#line 34
    sjt_functionParam234 = 22;
#line 0 ""
    sjf_array_i32_initAt(sjt_parent147, sjt_functionParam233, sjt_functionParam234);
#line 22 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_parent148 = array1;
#line 22
    sjt_functionParam235 = 35;
#line 34
    sjt_functionParam236 = 23;
#line 0 ""
    sjf_array_i32_initAt(sjt_parent148, sjt_functionParam235, sjt_functionParam236);
#line 36 ".\..\lib\ui\vertexBufferBuilders.sj"
    _return->vertices.size = 24;
#line 3 ".\..\lib\common\array.sj"
    sjt_cast47 = 0;
#line 3
    _return->vertices.data = (uintptr_t)sjt_cast47;
#line 4
    _return->vertices._isGlobal = false;
#line 0 ""
    sjf_array_vertex_location_texture_normal(&_return->vertices);
#line 36 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjs_array_vertex_location_texture_normal* array2;
#line 36
    array2 = &_return->vertices;
#line 36
    sjt_parent149 = array2;
#line 36
    sjt_functionParam237 = 0;
#line 8
    sjt_call10.location.x = x0;
#line 8
    sjt_call10.location.y = y0;
#line 8
    sjt_call10.location.z = z0;
#line 0 ""
    sjf_vec3(&sjt_call10.location);
#line 8 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_call10.texture.x = s0;
#line 8
    sjt_call10.texture.y = t0;
#line 0 ""
    sjf_vec2(&sjt_call10.texture);
#line 37 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_call10.normal.x = 0.0f;
#line 37
    sjt_call10.normal.y = 0.0f;
#line 37
    sjt_negate10 = 1.0f;
#line 37
    result20 = -sjt_negate10;
#line 37
    sjt_call10.normal.z = result20;
#line 0 ""
    sjf_vec3(&sjt_call10.normal);
    sjf_vertex_location_texture_normal(&sjt_call10);
#line 37 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_functionParam238 = &sjt_call10;
#line 0 ""
    sjf_array_vertex_location_texture_normal_initAt(sjt_parent149, sjt_functionParam237, sjt_functionParam238);
#line 36 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_parent150 = array2;
#line 36
    sjt_functionParam239 = 1;
#line 8
    sjt_call11.location.x = x0;
#line 8
    sjt_call11.location.y = y1;
#line 8
    sjt_call11.location.z = z0;
#line 0 ""
    sjf_vec3(&sjt_call11.location);
#line 8 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_call11.texture.x = s0;
#line 8
    sjt_call11.texture.y = t1;
#line 0 ""
    sjf_vec2(&sjt_call11.texture);
#line 38 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_call11.normal.x = 0.0f;
#line 38
    sjt_call11.normal.y = 0.0f;
#line 38
    sjt_negate11 = 1.0f;
#line 38
    result21 = -sjt_negate11;
#line 38
    sjt_call11.normal.z = result21;
#line 0 ""
    sjf_vec3(&sjt_call11.normal);
    sjf_vertex_location_texture_normal(&sjt_call11);
#line 38 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_functionParam240 = &sjt_call11;
#line 0 ""
    sjf_array_vertex_location_texture_normal_initAt(sjt_parent150, sjt_functionParam239, sjt_functionParam240);
#line 36 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_parent151 = array2;
#line 36
    sjt_functionParam241 = 2;
#line 8
    sjt_call12.location.x = x1;
#line 8
    sjt_call12.location.y = y1;
#line 8
    sjt_call12.location.z = z0;
#line 0 ""
    sjf_vec3(&sjt_call12.location);
#line 8 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_call12.texture.x = s1;
#line 8
    sjt_call12.texture.y = t1;
#line 0 ""
    sjf_vec2(&sjt_call12.texture);
#line 39 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_call12.normal.x = 0.0f;
#line 39
    sjt_call12.normal.y = 0.0f;
#line 39
    sjt_negate12 = 1.0f;
#line 39
    result22 = -sjt_negate12;
#line 39
    sjt_call12.normal.z = result22;
#line 0 ""
    sjf_vec3(&sjt_call12.normal);
    sjf_vertex_location_texture_normal(&sjt_call12);
#line 39 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_functionParam242 = &sjt_call12;
#line 0 ""
    sjf_array_vertex_location_texture_normal_initAt(sjt_parent151, sjt_functionParam241, sjt_functionParam242);
#line 36 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_parent152 = array2;
#line 36
    sjt_functionParam243 = 3;
#line 8
    sjt_call13.location.x = x1;
#line 8
    sjt_call13.location.y = y0;
#line 8
    sjt_call13.location.z = z0;
#line 0 ""
    sjf_vec3(&sjt_call13.location);
#line 8 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_call13.texture.x = s1;
#line 8
    sjt_call13.texture.y = t0;
#line 0 ""
    sjf_vec2(&sjt_call13.texture);
#line 40 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_call13.normal.x = 0.0f;
#line 40
    sjt_call13.normal.y = 0.0f;
#line 40
    sjt_negate13 = 1.0f;
#line 40
    result23 = -sjt_negate13;
#line 40
    sjt_call13.normal.z = result23;
#line 0 ""
    sjf_vec3(&sjt_call13.normal);
    sjf_vertex_location_texture_normal(&sjt_call13);
#line 40 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_functionParam244 = &sjt_call13;
#line 0 ""
    sjf_array_vertex_location_texture_normal_initAt(sjt_parent152, sjt_functionParam243, sjt_functionParam244);
#line 36 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_parent153 = array2;
#line 36
    sjt_functionParam245 = 4;
#line 8
    sjt_call14.location.x = x0;
#line 8
    sjt_call14.location.y = y0;
#line 8
    sjt_call14.location.z = z1;
#line 0 ""
    sjf_vec3(&sjt_call14.location);
#line 8 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_call14.texture.x = s0;
#line 8
    sjt_call14.texture.y = t0;
#line 0 ""
    sjf_vec2(&sjt_call14.texture);
#line 41 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_call14.normal.x = 0.0f;
#line 41
    sjt_call14.normal.y = 0.0f;
#line 41
    sjt_call14.normal.z = 1.0f;
#line 0 ""
    sjf_vec3(&sjt_call14.normal);
    sjf_vertex_location_texture_normal(&sjt_call14);
#line 41 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_functionParam246 = &sjt_call14;
#line 0 ""
    sjf_array_vertex_location_texture_normal_initAt(sjt_parent153, sjt_functionParam245, sjt_functionParam246);
#line 36 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_parent154 = array2;
#line 36
    sjt_functionParam247 = 5;
#line 8
    sjt_call15.location.x = x0;
#line 8
    sjt_call15.location.y = y1;
#line 8
    sjt_call15.location.z = z1;
#line 0 ""
    sjf_vec3(&sjt_call15.location);
#line 8 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_call15.texture.x = s0;
#line 8
    sjt_call15.texture.y = t1;
#line 0 ""
    sjf_vec2(&sjt_call15.texture);
#line 42 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_call15.normal.x = 0.0f;
#line 42
    sjt_call15.normal.y = 0.0f;
#line 42
    sjt_call15.normal.z = 1.0f;
#line 0 ""
    sjf_vec3(&sjt_call15.normal);
    sjf_vertex_location_texture_normal(&sjt_call15);
#line 42 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_functionParam248 = &sjt_call15;
#line 0 ""
    sjf_array_vertex_location_texture_normal_initAt(sjt_parent154, sjt_functionParam247, sjt_functionParam248);
#line 36 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_parent155 = array2;
#line 36
    sjt_functionParam249 = 6;
#line 8
    sjt_call16.location.x = x1;
#line 8
    sjt_call16.location.y = y1;
#line 8
    sjt_call16.location.z = z1;
#line 0 ""
    sjf_vec3(&sjt_call16.location);
#line 8 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_call16.texture.x = s1;
#line 8
    sjt_call16.texture.y = t1;
#line 0 ""
    sjf_vec2(&sjt_call16.texture);
#line 43 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_call16.normal.x = 0.0f;
#line 43
    sjt_call16.normal.y = 0.0f;
#line 43
    sjt_call16.normal.z = 1.0f;
#line 0 ""
    sjf_vec3(&sjt_call16.normal);
    sjf_vertex_location_texture_normal(&sjt_call16);
#line 43 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_functionParam250 = &sjt_call16;
#line 0 ""
    sjf_array_vertex_location_texture_normal_initAt(sjt_parent155, sjt_functionParam249, sjt_functionParam250);
#line 36 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_parent156 = array2;
#line 36
    sjt_functionParam251 = 7;
#line 8
    sjt_call17.location.x = x1;
#line 8
    sjt_call17.location.y = y0;
#line 8
    sjt_call17.location.z = z1;
#line 0 ""
    sjf_vec3(&sjt_call17.location);
#line 8 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_call17.texture.x = s1;
#line 8
    sjt_call17.texture.y = t0;
#line 0 ""
    sjf_vec2(&sjt_call17.texture);
#line 44 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_call17.normal.x = 0.0f;
#line 44
    sjt_call17.normal.y = 0.0f;
#line 44
    sjt_call17.normal.z = 1.0f;
#line 0 ""
    sjf_vec3(&sjt_call17.normal);
    sjf_vertex_location_texture_normal(&sjt_call17);
#line 44 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_functionParam252 = &sjt_call17;
#line 0 ""
    sjf_array_vertex_location_texture_normal_initAt(sjt_parent156, sjt_functionParam251, sjt_functionParam252);
#line 36 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_parent157 = array2;
#line 36
    sjt_functionParam253 = 8;
#line 8
    sjt_call18.location.x = x0;
#line 8
    sjt_call18.location.y = y0;
#line 8
    sjt_call18.location.z = z0;
#line 0 ""
    sjf_vec3(&sjt_call18.location);
#line 8 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_call18.texture.x = s0;
#line 8
    sjt_call18.texture.y = t0;
#line 0 ""
    sjf_vec2(&sjt_call18.texture);
#line 45 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_negate14 = 1.0f;
#line 45
    result24 = -sjt_negate14;
#line 45
    sjt_call18.normal.x = result24;
#line 45
    sjt_call18.normal.y = 0.0f;
#line 45
    sjt_call18.normal.z = 0.0f;
#line 0 ""
    sjf_vec3(&sjt_call18.normal);
    sjf_vertex_location_texture_normal(&sjt_call18);
#line 45 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_functionParam254 = &sjt_call18;
#line 0 ""
    sjf_array_vertex_location_texture_normal_initAt(sjt_parent157, sjt_functionParam253, sjt_functionParam254);
#line 36 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_parent158 = array2;
#line 36
    sjt_functionParam255 = 9;
#line 8
    sjt_call19.location.x = x0;
#line 8
    sjt_call19.location.y = y1;
#line 8
    sjt_call19.location.z = z0;
#line 0 ""
    sjf_vec3(&sjt_call19.location);
#line 8 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_call19.texture.x = s0;
#line 8
    sjt_call19.texture.y = t1;
#line 0 ""
    sjf_vec2(&sjt_call19.texture);
#line 46 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_negate15 = 1.0f;
#line 46
    result25 = -sjt_negate15;
#line 46
    sjt_call19.normal.x = result25;
#line 46
    sjt_call19.normal.y = 0.0f;
#line 46
    sjt_call19.normal.z = 0.0f;
#line 0 ""
    sjf_vec3(&sjt_call19.normal);
    sjf_vertex_location_texture_normal(&sjt_call19);
#line 46 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_functionParam256 = &sjt_call19;
#line 0 ""
    sjf_array_vertex_location_texture_normal_initAt(sjt_parent158, sjt_functionParam255, sjt_functionParam256);
#line 36 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_parent159 = array2;
#line 36
    sjt_functionParam257 = 10;
#line 8
    sjt_call20.location.x = x0;
#line 8
    sjt_call20.location.y = y1;
#line 8
    sjt_call20.location.z = z1;
#line 0 ""
    sjf_vec3(&sjt_call20.location);
#line 8 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_call20.texture.x = s1;
#line 8
    sjt_call20.texture.y = t1;
#line 0 ""
    sjf_vec2(&sjt_call20.texture);
#line 47 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_negate16 = 1.0f;
#line 47
    result26 = -sjt_negate16;
#line 47
    sjt_call20.normal.x = result26;
#line 47
    sjt_call20.normal.y = 0.0f;
#line 47
    sjt_call20.normal.z = 0.0f;
#line 0 ""
    sjf_vec3(&sjt_call20.normal);
    sjf_vertex_location_texture_normal(&sjt_call20);
#line 47 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_functionParam258 = &sjt_call20;
#line 0 ""
    sjf_array_vertex_location_texture_normal_initAt(sjt_parent159, sjt_functionParam257, sjt_functionParam258);
#line 36 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_parent160 = array2;
#line 36
    sjt_functionParam259 = 11;
#line 8
    sjt_call21.location.x = x0;
#line 8
    sjt_call21.location.y = y0;
#line 8
    sjt_call21.location.z = z1;
#line 0 ""
    sjf_vec3(&sjt_call21.location);
#line 8 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_call21.texture.x = s1;
#line 8
    sjt_call21.texture.y = t0;
#line 0 ""
    sjf_vec2(&sjt_call21.texture);
#line 48 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_negate17 = 1.0f;
#line 48
    result27 = -sjt_negate17;
#line 48
    sjt_call21.normal.x = result27;
#line 48
    sjt_call21.normal.y = 0.0f;
#line 48
    sjt_call21.normal.z = 0.0f;
#line 0 ""
    sjf_vec3(&sjt_call21.normal);
    sjf_vertex_location_texture_normal(&sjt_call21);
#line 48 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_functionParam260 = &sjt_call21;
#line 0 ""
    sjf_array_vertex_location_texture_normal_initAt(sjt_parent160, sjt_functionParam259, sjt_functionParam260);
#line 36 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_parent161 = array2;
#line 36
    sjt_functionParam261 = 12;
#line 8
    sjt_call22.location.x = x1;
#line 8
    sjt_call22.location.y = y0;
#line 8
    sjt_call22.location.z = z0;
#line 0 ""
    sjf_vec3(&sjt_call22.location);
#line 8 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_call22.texture.x = s0;
#line 8
    sjt_call22.texture.y = t0;
#line 0 ""
    sjf_vec2(&sjt_call22.texture);
#line 49 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_call22.normal.x = 1.0f;
#line 49
    sjt_call22.normal.y = 0.0f;
#line 49
    sjt_call22.normal.z = 0.0f;
#line 0 ""
    sjf_vec3(&sjt_call22.normal);
    sjf_vertex_location_texture_normal(&sjt_call22);
#line 49 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_functionParam262 = &sjt_call22;
#line 0 ""
    sjf_array_vertex_location_texture_normal_initAt(sjt_parent161, sjt_functionParam261, sjt_functionParam262);
#line 36 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_parent162 = array2;
#line 36
    sjt_functionParam263 = 13;
#line 8
    sjt_call23.location.x = x1;
#line 8
    sjt_call23.location.y = y1;
#line 8
    sjt_call23.location.z = z0;
#line 0 ""
    sjf_vec3(&sjt_call23.location);
#line 8 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_call23.texture.x = s0;
#line 8
    sjt_call23.texture.y = t1;
#line 0 ""
    sjf_vec2(&sjt_call23.texture);
#line 50 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_call23.normal.x = 1.0f;
#line 50
    sjt_call23.normal.y = 0.0f;
#line 50
    sjt_call23.normal.z = 0.0f;
#line 0 ""
    sjf_vec3(&sjt_call23.normal);
    sjf_vertex_location_texture_normal(&sjt_call23);
#line 50 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_functionParam264 = &sjt_call23;
#line 0 ""
    sjf_array_vertex_location_texture_normal_initAt(sjt_parent162, sjt_functionParam263, sjt_functionParam264);
#line 36 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_parent163 = array2;
#line 36
    sjt_functionParam265 = 14;
#line 8
    sjt_call24.location.x = x1;
#line 8
    sjt_call24.location.y = y1;
#line 8
    sjt_call24.location.z = z1;
#line 0 ""
    sjf_vec3(&sjt_call24.location);
#line 8 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_call24.texture.x = s1;
#line 8
    sjt_call24.texture.y = t1;
#line 0 ""
    sjf_vec2(&sjt_call24.texture);
#line 51 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_call24.normal.x = 1.0f;
#line 51
    sjt_call24.normal.y = 0.0f;
#line 51
    sjt_call24.normal.z = 0.0f;
#line 0 ""
    sjf_vec3(&sjt_call24.normal);
    sjf_vertex_location_texture_normal(&sjt_call24);
#line 51 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_functionParam266 = &sjt_call24;
#line 0 ""
    sjf_array_vertex_location_texture_normal_initAt(sjt_parent163, sjt_functionParam265, sjt_functionParam266);
#line 36 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_parent164 = array2;
#line 36
    sjt_functionParam267 = 15;
#line 8
    sjt_call25.location.x = x1;
#line 8
    sjt_call25.location.y = y0;
#line 8
    sjt_call25.location.z = z1;
#line 0 ""
    sjf_vec3(&sjt_call25.location);
#line 8 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_call25.texture.x = s1;
#line 8
    sjt_call25.texture.y = t0;
#line 0 ""
    sjf_vec2(&sjt_call25.texture);
#line 52 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_call25.normal.x = 1.0f;
#line 52
    sjt_call25.normal.y = 0.0f;
#line 52
    sjt_call25.normal.z = 0.0f;
#line 0 ""
    sjf_vec3(&sjt_call25.normal);
    sjf_vertex_location_texture_normal(&sjt_call25);
#line 52 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_functionParam268 = &sjt_call25;
#line 0 ""
    sjf_array_vertex_location_texture_normal_initAt(sjt_parent164, sjt_functionParam267, sjt_functionParam268);
#line 36 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_parent165 = array2;
#line 36
    sjt_functionParam269 = 16;
#line 8
    sjt_call26.location.x = x0;
#line 8
    sjt_call26.location.y = y0;
#line 8
    sjt_call26.location.z = z0;
#line 0 ""
    sjf_vec3(&sjt_call26.location);
#line 8 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_call26.texture.x = s0;
#line 8
    sjt_call26.texture.y = t0;
#line 0 ""
    sjf_vec2(&sjt_call26.texture);
#line 53 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_call26.normal.x = 0.0f;
#line 53
    sjt_negate18 = 1.0f;
#line 53
    result28 = -sjt_negate18;
#line 53
    sjt_call26.normal.y = result28;
#line 53
    sjt_call26.normal.z = 0.0f;
#line 0 ""
    sjf_vec3(&sjt_call26.normal);
    sjf_vertex_location_texture_normal(&sjt_call26);
#line 53 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_functionParam270 = &sjt_call26;
#line 0 ""
    sjf_array_vertex_location_texture_normal_initAt(sjt_parent165, sjt_functionParam269, sjt_functionParam270);
#line 36 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_parent166 = array2;
#line 36
    sjt_functionParam271 = 17;
#line 8
    sjt_call27.location.x = x0;
#line 8
    sjt_call27.location.y = y0;
#line 8
    sjt_call27.location.z = z1;
#line 0 ""
    sjf_vec3(&sjt_call27.location);
#line 8 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_call27.texture.x = s0;
#line 8
    sjt_call27.texture.y = t1;
#line 0 ""
    sjf_vec2(&sjt_call27.texture);
#line 54 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_call27.normal.x = 0.0f;
#line 54
    sjt_negate19 = 1.0f;
#line 54
    result29 = -sjt_negate19;
#line 54
    sjt_call27.normal.y = result29;
#line 54
    sjt_call27.normal.z = 0.0f;
#line 0 ""
    sjf_vec3(&sjt_call27.normal);
    sjf_vertex_location_texture_normal(&sjt_call27);
#line 54 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_functionParam272 = &sjt_call27;
#line 0 ""
    sjf_array_vertex_location_texture_normal_initAt(sjt_parent166, sjt_functionParam271, sjt_functionParam272);
#line 36 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_parent167 = array2;
#line 36
    sjt_functionParam273 = 18;
#line 8
    sjt_call28.location.x = x1;
#line 8
    sjt_call28.location.y = y0;
#line 8
    sjt_call28.location.z = z1;
#line 0 ""
    sjf_vec3(&sjt_call28.location);
#line 8 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_call28.texture.x = s1;
#line 8
    sjt_call28.texture.y = t1;
#line 0 ""
    sjf_vec2(&sjt_call28.texture);
#line 55 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_call28.normal.x = 0.0f;
#line 55
    sjt_negate20 = 1.0f;
#line 55
    result30 = -sjt_negate20;
#line 55
    sjt_call28.normal.y = result30;
#line 55
    sjt_call28.normal.z = 0.0f;
#line 0 ""
    sjf_vec3(&sjt_call28.normal);
    sjf_vertex_location_texture_normal(&sjt_call28);
#line 55 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_functionParam274 = &sjt_call28;
#line 0 ""
    sjf_array_vertex_location_texture_normal_initAt(sjt_parent167, sjt_functionParam273, sjt_functionParam274);
#line 36 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_parent168 = array2;
#line 36
    sjt_functionParam275 = 19;
#line 8
    sjt_call29.location.x = x1;
#line 8
    sjt_call29.location.y = y0;
#line 8
    sjt_call29.location.z = z0;
#line 0 ""
    sjf_vec3(&sjt_call29.location);
#line 8 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_call29.texture.x = s1;
#line 8
    sjt_call29.texture.y = t0;
#line 0 ""
    sjf_vec2(&sjt_call29.texture);
#line 56 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_call29.normal.x = 0.0f;
#line 56
    sjt_negate21 = 1.0f;
#line 56
    result31 = -sjt_negate21;
#line 56
    sjt_call29.normal.y = result31;
#line 56
    sjt_call29.normal.z = 0.0f;
#line 0 ""
    sjf_vec3(&sjt_call29.normal);
    sjf_vertex_location_texture_normal(&sjt_call29);
#line 56 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_functionParam276 = &sjt_call29;
#line 0 ""
    sjf_array_vertex_location_texture_normal_initAt(sjt_parent168, sjt_functionParam275, sjt_functionParam276);
#line 36 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_parent169 = array2;
#line 36
    sjt_functionParam277 = 20;
#line 8
    sjt_call30.location.x = x0;
#line 8
    sjt_call30.location.y = y1;
#line 8
    sjt_call30.location.z = z0;
#line 0 ""
    sjf_vec3(&sjt_call30.location);
#line 8 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_call30.texture.x = s0;
#line 8
    sjt_call30.texture.y = t0;
#line 0 ""
    sjf_vec2(&sjt_call30.texture);
#line 57 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_call30.normal.x = 0.0f;
#line 57
    sjt_call30.normal.y = 1.0f;
#line 57
    sjt_call30.normal.z = 0.0f;
#line 0 ""
    sjf_vec3(&sjt_call30.normal);
    sjf_vertex_location_texture_normal(&sjt_call30);
#line 57 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_functionParam278 = &sjt_call30;
#line 0 ""
    sjf_array_vertex_location_texture_normal_initAt(sjt_parent169, sjt_functionParam277, sjt_functionParam278);
#line 36 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_parent170 = array2;
#line 36
    sjt_functionParam279 = 21;
#line 8
    sjt_call31.location.x = x0;
#line 8
    sjt_call31.location.y = y1;
#line 8
    sjt_call31.location.z = z1;
#line 0 ""
    sjf_vec3(&sjt_call31.location);
#line 8 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_call31.texture.x = s0;
#line 8
    sjt_call31.texture.y = t1;
#line 0 ""
    sjf_vec2(&sjt_call31.texture);
#line 58 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_call31.normal.x = 0.0f;
#line 58
    sjt_call31.normal.y = 1.0f;
#line 58
    sjt_call31.normal.z = 0.0f;
#line 0 ""
    sjf_vec3(&sjt_call31.normal);
    sjf_vertex_location_texture_normal(&sjt_call31);
#line 58 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_functionParam280 = &sjt_call31;
#line 0 ""
    sjf_array_vertex_location_texture_normal_initAt(sjt_parent170, sjt_functionParam279, sjt_functionParam280);
#line 36 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_parent171 = array2;
#line 36
    sjt_functionParam281 = 22;
#line 8
    sjt_call32.location.x = x1;
#line 8
    sjt_call32.location.y = y1;
#line 8
    sjt_call32.location.z = z1;
#line 0 ""
    sjf_vec3(&sjt_call32.location);
#line 8 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_call32.texture.x = s1;
#line 8
    sjt_call32.texture.y = t1;
#line 0 ""
    sjf_vec2(&sjt_call32.texture);
#line 59 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_call32.normal.x = 0.0f;
#line 59
    sjt_call32.normal.y = 1.0f;
#line 59
    sjt_call32.normal.z = 0.0f;
#line 0 ""
    sjf_vec3(&sjt_call32.normal);
    sjf_vertex_location_texture_normal(&sjt_call32);
#line 59 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_functionParam282 = &sjt_call32;
#line 0 ""
    sjf_array_vertex_location_texture_normal_initAt(sjt_parent171, sjt_functionParam281, sjt_functionParam282);
#line 36 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_parent172 = array2;
#line 36
    sjt_functionParam283 = 23;
#line 8
    sjt_call33.location.x = x1;
#line 8
    sjt_call33.location.y = y1;
#line 8
    sjt_call33.location.z = z0;
#line 0 ""
    sjf_vec3(&sjt_call33.location);
#line 8 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_call33.texture.x = s1;
#line 8
    sjt_call33.texture.y = t0;
#line 0 ""
    sjf_vec2(&sjt_call33.texture);
#line 60 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_call33.normal.x = 0.0f;
#line 60
    sjt_call33.normal.y = 1.0f;
#line 60
    sjt_call33.normal.z = 0.0f;
#line 0 ""
    sjf_vec3(&sjt_call33.normal);
    sjf_vertex_location_texture_normal(&sjt_call33);
#line 60 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_functionParam284 = &sjt_call33;
#line 0 ""
    sjf_array_vertex_location_texture_normal_initAt(sjt_parent172, sjt_functionParam283, sjt_functionParam284);
    sjf_vertexBuffer_vertex_location_texture_normal(_return);

    sjf_vertex_location_texture_normal_destroy(&sjt_call10);
    sjf_vertex_location_texture_normal_destroy(&sjt_call11);
    sjf_vertex_location_texture_normal_destroy(&sjt_call12);
    sjf_vertex_location_texture_normal_destroy(&sjt_call13);
    sjf_vertex_location_texture_normal_destroy(&sjt_call14);
    sjf_vertex_location_texture_normal_destroy(&sjt_call15);
    sjf_vertex_location_texture_normal_destroy(&sjt_call16);
    sjf_vertex_location_texture_normal_destroy(&sjt_call17);
    sjf_vertex_location_texture_normal_destroy(&sjt_call18);
    sjf_vertex_location_texture_normal_destroy(&sjt_call19);
    sjf_vertex_location_texture_normal_destroy(&sjt_call20);
    sjf_vertex_location_texture_normal_destroy(&sjt_call21);
    sjf_vertex_location_texture_normal_destroy(&sjt_call22);
    sjf_vertex_location_texture_normal_destroy(&sjt_call23);
    sjf_vertex_location_texture_normal_destroy(&sjt_call24);
    sjf_vertex_location_texture_normal_destroy(&sjt_call25);
    sjf_vertex_location_texture_normal_destroy(&sjt_call26);
    sjf_vertex_location_texture_normal_destroy(&sjt_call27);
    sjf_vertex_location_texture_normal_destroy(&sjt_call28);
    sjf_vertex_location_texture_normal_destroy(&sjt_call29);
    sjf_vertex_location_texture_normal_destroy(&sjt_call30);
    sjf_vertex_location_texture_normal_destroy(&sjt_call31);
    sjf_vertex_location_texture_normal_destroy(&sjt_call32);
    sjf_vertex_location_texture_normal_destroy(&sjt_call33);
}

void sjf_cubeVertexBuffer_heap(float x0, float x1, float y0, float y1, float z0, float z1, float s0, float s1, float t0, float t1, sjs_vertexBuffer_vertex_location_texture_normal_heap** _return) {
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
    sjs_vertex_location_texture_normal sjt_call34;
    sjs_vertex_location_texture_normal sjt_call35;
    sjs_vertex_location_texture_normal sjt_call36;
    sjs_vertex_location_texture_normal sjt_call37;
    sjs_vertex_location_texture_normal sjt_call38;
    sjs_vertex_location_texture_normal sjt_call39;
    sjs_vertex_location_texture_normal sjt_call40;
    sjs_vertex_location_texture_normal sjt_call41;
    sjs_vertex_location_texture_normal sjt_call42;
    sjs_vertex_location_texture_normal sjt_call43;
    sjs_vertex_location_texture_normal sjt_call44;
    sjs_vertex_location_texture_normal sjt_call45;
    sjs_vertex_location_texture_normal sjt_call46;
    sjs_vertex_location_texture_normal sjt_call47;
    sjs_vertex_location_texture_normal sjt_call48;
    sjs_vertex_location_texture_normal sjt_call49;
    sjs_vertex_location_texture_normal sjt_call50;
    sjs_vertex_location_texture_normal sjt_call51;
    sjs_vertex_location_texture_normal sjt_call52;
    sjs_vertex_location_texture_normal sjt_call53;
    sjs_vertex_location_texture_normal sjt_call54;
    sjs_vertex_location_texture_normal sjt_call55;
    sjs_vertex_location_texture_normal sjt_call56;
    sjs_vertex_location_texture_normal sjt_call57;
    int32_t sjt_cast48;
    int32_t sjt_cast49;
    int32_t sjt_functionParam285;
    int32_t sjt_functionParam286;
    int32_t sjt_functionParam287;
    int32_t sjt_functionParam288;
    int32_t sjt_functionParam289;
    int32_t sjt_functionParam290;
    int32_t sjt_functionParam291;
    int32_t sjt_functionParam292;
    int32_t sjt_functionParam293;
    int32_t sjt_functionParam294;
    int32_t sjt_functionParam295;
    int32_t sjt_functionParam296;
    int32_t sjt_functionParam297;
    int32_t sjt_functionParam298;
    int32_t sjt_functionParam299;
    int32_t sjt_functionParam300;
    int32_t sjt_functionParam301;
    int32_t sjt_functionParam302;
    int32_t sjt_functionParam303;
    int32_t sjt_functionParam304;
    int32_t sjt_functionParam305;
    int32_t sjt_functionParam306;
    int32_t sjt_functionParam307;
    int32_t sjt_functionParam308;
    int32_t sjt_functionParam309;
    int32_t sjt_functionParam310;
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
    int32_t sjt_functionParam326;
    int32_t sjt_functionParam327;
    int32_t sjt_functionParam328;
    int32_t sjt_functionParam329;
    int32_t sjt_functionParam330;
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
    int32_t sjt_functionParam343;
    int32_t sjt_functionParam344;
    int32_t sjt_functionParam345;
    int32_t sjt_functionParam346;
    int32_t sjt_functionParam347;
    int32_t sjt_functionParam348;
    int32_t sjt_functionParam349;
    int32_t sjt_functionParam350;
    int32_t sjt_functionParam351;
    int32_t sjt_functionParam352;
    int32_t sjt_functionParam353;
    int32_t sjt_functionParam354;
    int32_t sjt_functionParam355;
    int32_t sjt_functionParam356;
    int32_t sjt_functionParam357;
    sjs_vertex_location_texture_normal* sjt_functionParam358;
    int32_t sjt_functionParam359;
    sjs_vertex_location_texture_normal* sjt_functionParam360;
    int32_t sjt_functionParam361;
    sjs_vertex_location_texture_normal* sjt_functionParam362;
    int32_t sjt_functionParam363;
    sjs_vertex_location_texture_normal* sjt_functionParam364;
    int32_t sjt_functionParam365;
    sjs_vertex_location_texture_normal* sjt_functionParam366;
    int32_t sjt_functionParam367;
    sjs_vertex_location_texture_normal* sjt_functionParam368;
    int32_t sjt_functionParam369;
    sjs_vertex_location_texture_normal* sjt_functionParam370;
    int32_t sjt_functionParam371;
    sjs_vertex_location_texture_normal* sjt_functionParam372;
    int32_t sjt_functionParam373;
    sjs_vertex_location_texture_normal* sjt_functionParam374;
    int32_t sjt_functionParam375;
    sjs_vertex_location_texture_normal* sjt_functionParam376;
    int32_t sjt_functionParam377;
    sjs_vertex_location_texture_normal* sjt_functionParam378;
    int32_t sjt_functionParam379;
    sjs_vertex_location_texture_normal* sjt_functionParam380;
    int32_t sjt_functionParam381;
    sjs_vertex_location_texture_normal* sjt_functionParam382;
    int32_t sjt_functionParam383;
    sjs_vertex_location_texture_normal* sjt_functionParam384;
    int32_t sjt_functionParam385;
    sjs_vertex_location_texture_normal* sjt_functionParam386;
    int32_t sjt_functionParam387;
    sjs_vertex_location_texture_normal* sjt_functionParam388;
    int32_t sjt_functionParam389;
    sjs_vertex_location_texture_normal* sjt_functionParam390;
    int32_t sjt_functionParam391;
    sjs_vertex_location_texture_normal* sjt_functionParam392;
    int32_t sjt_functionParam393;
    sjs_vertex_location_texture_normal* sjt_functionParam394;
    int32_t sjt_functionParam395;
    sjs_vertex_location_texture_normal* sjt_functionParam396;
    int32_t sjt_functionParam397;
    sjs_vertex_location_texture_normal* sjt_functionParam398;
    int32_t sjt_functionParam399;
    sjs_vertex_location_texture_normal* sjt_functionParam400;
    int32_t sjt_functionParam401;
    sjs_vertex_location_texture_normal* sjt_functionParam402;
    int32_t sjt_functionParam403;
    sjs_vertex_location_texture_normal* sjt_functionParam404;
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
    sjs_array_i32* sjt_parent173;
    sjs_array_i32* sjt_parent174;
    sjs_array_i32* sjt_parent175;
    sjs_array_i32* sjt_parent176;
    sjs_array_i32* sjt_parent177;
    sjs_array_i32* sjt_parent178;
    sjs_array_i32* sjt_parent179;
    sjs_array_i32* sjt_parent180;
    sjs_array_i32* sjt_parent181;
    sjs_array_i32* sjt_parent182;
    sjs_array_i32* sjt_parent183;
    sjs_array_i32* sjt_parent184;
    sjs_array_i32* sjt_parent185;
    sjs_array_i32* sjt_parent186;
    sjs_array_i32* sjt_parent187;
    sjs_array_i32* sjt_parent188;
    sjs_array_i32* sjt_parent189;
    sjs_array_i32* sjt_parent190;
    sjs_array_i32* sjt_parent191;
    sjs_array_i32* sjt_parent192;
    sjs_array_i32* sjt_parent193;
    sjs_array_i32* sjt_parent194;
    sjs_array_i32* sjt_parent195;
    sjs_array_i32* sjt_parent196;
    sjs_array_i32* sjt_parent197;
    sjs_array_i32* sjt_parent198;
    sjs_array_i32* sjt_parent199;
    sjs_array_i32* sjt_parent200;
    sjs_array_i32* sjt_parent201;
    sjs_array_i32* sjt_parent202;
    sjs_array_i32* sjt_parent203;
    sjs_array_i32* sjt_parent204;
    sjs_array_i32* sjt_parent205;
    sjs_array_i32* sjt_parent206;
    sjs_array_i32* sjt_parent207;
    sjs_array_i32* sjt_parent208;
    sjs_array_vertex_location_texture_normal* sjt_parent209;
    sjs_array_vertex_location_texture_normal* sjt_parent210;
    sjs_array_vertex_location_texture_normal* sjt_parent211;
    sjs_array_vertex_location_texture_normal* sjt_parent212;
    sjs_array_vertex_location_texture_normal* sjt_parent213;
    sjs_array_vertex_location_texture_normal* sjt_parent214;
    sjs_array_vertex_location_texture_normal* sjt_parent215;
    sjs_array_vertex_location_texture_normal* sjt_parent216;
    sjs_array_vertex_location_texture_normal* sjt_parent217;
    sjs_array_vertex_location_texture_normal* sjt_parent218;
    sjs_array_vertex_location_texture_normal* sjt_parent219;
    sjs_array_vertex_location_texture_normal* sjt_parent220;
    sjs_array_vertex_location_texture_normal* sjt_parent221;
    sjs_array_vertex_location_texture_normal* sjt_parent222;
    sjs_array_vertex_location_texture_normal* sjt_parent223;
    sjs_array_vertex_location_texture_normal* sjt_parent224;
    sjs_array_vertex_location_texture_normal* sjt_parent225;
    sjs_array_vertex_location_texture_normal* sjt_parent226;
    sjs_array_vertex_location_texture_normal* sjt_parent227;
    sjs_array_vertex_location_texture_normal* sjt_parent228;
    sjs_array_vertex_location_texture_normal* sjt_parent229;
    sjs_array_vertex_location_texture_normal* sjt_parent230;
    sjs_array_vertex_location_texture_normal* sjt_parent231;
    sjs_array_vertex_location_texture_normal* sjt_parent232;

    (*_return) = (sjs_vertexBuffer_vertex_location_texture_normal_heap*)malloc(sizeof(sjs_vertexBuffer_vertex_location_texture_normal_heap));
    (*_return)->_refCount = 1;
#line 20 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjf_string_copy(&(*_return)->format, &sjv_vertex_location_texture_normal_format);
#line 22
    (*_return)->indices.size = 36;
#line 3 ".\..\lib\common\array.sj"
    sjt_cast48 = 0;
#line 3
    (*_return)->indices.data = (uintptr_t)sjt_cast48;
#line 4
    (*_return)->indices._isGlobal = false;
#line 0 ""
    sjf_array_i32(&(*_return)->indices);
#line 22 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjs_array_i32* array3;
#line 22
    array3 = &(*_return)->indices;
#line 22
    sjt_parent173 = array3;
#line 22
    sjt_functionParam285 = 0;
#line 23
    sjt_functionParam286 = 0;
#line 0 ""
    sjf_array_i32_initAt(sjt_parent173, sjt_functionParam285, sjt_functionParam286);
#line 22 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_parent174 = array3;
#line 22
    sjt_functionParam287 = 1;
#line 23
    sjt_functionParam288 = 1;
#line 0 ""
    sjf_array_i32_initAt(sjt_parent174, sjt_functionParam287, sjt_functionParam288);
#line 22 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_parent175 = array3;
#line 22
    sjt_functionParam289 = 2;
#line 23
    sjt_functionParam290 = 2;
#line 0 ""
    sjf_array_i32_initAt(sjt_parent175, sjt_functionParam289, sjt_functionParam290);
#line 22 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_parent176 = array3;
#line 22
    sjt_functionParam291 = 3;
#line 24
    sjt_functionParam292 = 0;
#line 0 ""
    sjf_array_i32_initAt(sjt_parent176, sjt_functionParam291, sjt_functionParam292);
#line 22 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_parent177 = array3;
#line 22
    sjt_functionParam293 = 4;
#line 24
    sjt_functionParam294 = 2;
#line 0 ""
    sjf_array_i32_initAt(sjt_parent177, sjt_functionParam293, sjt_functionParam294);
#line 22 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_parent178 = array3;
#line 22
    sjt_functionParam295 = 5;
#line 24
    sjt_functionParam296 = 3;
#line 0 ""
    sjf_array_i32_initAt(sjt_parent178, sjt_functionParam295, sjt_functionParam296);
#line 22 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_parent179 = array3;
#line 22
    sjt_functionParam297 = 6;
#line 25
    sjt_functionParam298 = 4;
#line 0 ""
    sjf_array_i32_initAt(sjt_parent179, sjt_functionParam297, sjt_functionParam298);
#line 22 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_parent180 = array3;
#line 22
    sjt_functionParam299 = 7;
#line 25
    sjt_functionParam300 = 5;
#line 0 ""
    sjf_array_i32_initAt(sjt_parent180, sjt_functionParam299, sjt_functionParam300);
#line 22 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_parent181 = array3;
#line 22
    sjt_functionParam301 = 8;
#line 25
    sjt_functionParam302 = 6;
#line 0 ""
    sjf_array_i32_initAt(sjt_parent181, sjt_functionParam301, sjt_functionParam302);
#line 22 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_parent182 = array3;
#line 22
    sjt_functionParam303 = 9;
#line 26
    sjt_functionParam304 = 4;
#line 0 ""
    sjf_array_i32_initAt(sjt_parent182, sjt_functionParam303, sjt_functionParam304);
#line 22 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_parent183 = array3;
#line 22
    sjt_functionParam305 = 10;
#line 26
    sjt_functionParam306 = 6;
#line 0 ""
    sjf_array_i32_initAt(sjt_parent183, sjt_functionParam305, sjt_functionParam306);
#line 22 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_parent184 = array3;
#line 22
    sjt_functionParam307 = 11;
#line 26
    sjt_functionParam308 = 7;
#line 0 ""
    sjf_array_i32_initAt(sjt_parent184, sjt_functionParam307, sjt_functionParam308);
#line 22 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_parent185 = array3;
#line 22
    sjt_functionParam309 = 12;
#line 27
    sjt_functionParam310 = 8;
#line 0 ""
    sjf_array_i32_initAt(sjt_parent185, sjt_functionParam309, sjt_functionParam310);
#line 22 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_parent186 = array3;
#line 22
    sjt_functionParam311 = 13;
#line 27
    sjt_functionParam312 = 9;
#line 0 ""
    sjf_array_i32_initAt(sjt_parent186, sjt_functionParam311, sjt_functionParam312);
#line 22 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_parent187 = array3;
#line 22
    sjt_functionParam313 = 14;
#line 27
    sjt_functionParam314 = 10;
#line 0 ""
    sjf_array_i32_initAt(sjt_parent187, sjt_functionParam313, sjt_functionParam314);
#line 22 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_parent188 = array3;
#line 22
    sjt_functionParam315 = 15;
#line 28
    sjt_functionParam316 = 8;
#line 0 ""
    sjf_array_i32_initAt(sjt_parent188, sjt_functionParam315, sjt_functionParam316);
#line 22 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_parent189 = array3;
#line 22
    sjt_functionParam317 = 16;
#line 28
    sjt_functionParam318 = 10;
#line 0 ""
    sjf_array_i32_initAt(sjt_parent189, sjt_functionParam317, sjt_functionParam318);
#line 22 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_parent190 = array3;
#line 22
    sjt_functionParam319 = 17;
#line 28
    sjt_functionParam320 = 11;
#line 0 ""
    sjf_array_i32_initAt(sjt_parent190, sjt_functionParam319, sjt_functionParam320);
#line 22 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_parent191 = array3;
#line 22
    sjt_functionParam321 = 18;
#line 29
    sjt_functionParam322 = 12;
#line 0 ""
    sjf_array_i32_initAt(sjt_parent191, sjt_functionParam321, sjt_functionParam322);
#line 22 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_parent192 = array3;
#line 22
    sjt_functionParam323 = 19;
#line 29
    sjt_functionParam324 = 13;
#line 0 ""
    sjf_array_i32_initAt(sjt_parent192, sjt_functionParam323, sjt_functionParam324);
#line 22 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_parent193 = array3;
#line 22
    sjt_functionParam325 = 20;
#line 29
    sjt_functionParam326 = 14;
#line 0 ""
    sjf_array_i32_initAt(sjt_parent193, sjt_functionParam325, sjt_functionParam326);
#line 22 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_parent194 = array3;
#line 22
    sjt_functionParam327 = 21;
#line 30
    sjt_functionParam328 = 12;
#line 0 ""
    sjf_array_i32_initAt(sjt_parent194, sjt_functionParam327, sjt_functionParam328);
#line 22 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_parent195 = array3;
#line 22
    sjt_functionParam329 = 22;
#line 30
    sjt_functionParam330 = 14;
#line 0 ""
    sjf_array_i32_initAt(sjt_parent195, sjt_functionParam329, sjt_functionParam330);
#line 22 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_parent196 = array3;
#line 22
    sjt_functionParam331 = 23;
#line 30
    sjt_functionParam332 = 15;
#line 0 ""
    sjf_array_i32_initAt(sjt_parent196, sjt_functionParam331, sjt_functionParam332);
#line 22 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_parent197 = array3;
#line 22
    sjt_functionParam333 = 24;
#line 31
    sjt_functionParam334 = 16;
#line 0 ""
    sjf_array_i32_initAt(sjt_parent197, sjt_functionParam333, sjt_functionParam334);
#line 22 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_parent198 = array3;
#line 22
    sjt_functionParam335 = 25;
#line 31
    sjt_functionParam336 = 17;
#line 0 ""
    sjf_array_i32_initAt(sjt_parent198, sjt_functionParam335, sjt_functionParam336);
#line 22 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_parent199 = array3;
#line 22
    sjt_functionParam337 = 26;
#line 31
    sjt_functionParam338 = 18;
#line 0 ""
    sjf_array_i32_initAt(sjt_parent199, sjt_functionParam337, sjt_functionParam338);
#line 22 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_parent200 = array3;
#line 22
    sjt_functionParam339 = 27;
#line 32
    sjt_functionParam340 = 16;
#line 0 ""
    sjf_array_i32_initAt(sjt_parent200, sjt_functionParam339, sjt_functionParam340);
#line 22 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_parent201 = array3;
#line 22
    sjt_functionParam341 = 28;
#line 32
    sjt_functionParam342 = 18;
#line 0 ""
    sjf_array_i32_initAt(sjt_parent201, sjt_functionParam341, sjt_functionParam342);
#line 22 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_parent202 = array3;
#line 22
    sjt_functionParam343 = 29;
#line 32
    sjt_functionParam344 = 19;
#line 0 ""
    sjf_array_i32_initAt(sjt_parent202, sjt_functionParam343, sjt_functionParam344);
#line 22 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_parent203 = array3;
#line 22
    sjt_functionParam345 = 30;
#line 33
    sjt_functionParam346 = 20;
#line 0 ""
    sjf_array_i32_initAt(sjt_parent203, sjt_functionParam345, sjt_functionParam346);
#line 22 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_parent204 = array3;
#line 22
    sjt_functionParam347 = 31;
#line 33
    sjt_functionParam348 = 21;
#line 0 ""
    sjf_array_i32_initAt(sjt_parent204, sjt_functionParam347, sjt_functionParam348);
#line 22 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_parent205 = array3;
#line 22
    sjt_functionParam349 = 32;
#line 33
    sjt_functionParam350 = 22;
#line 0 ""
    sjf_array_i32_initAt(sjt_parent205, sjt_functionParam349, sjt_functionParam350);
#line 22 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_parent206 = array3;
#line 22
    sjt_functionParam351 = 33;
#line 34
    sjt_functionParam352 = 20;
#line 0 ""
    sjf_array_i32_initAt(sjt_parent206, sjt_functionParam351, sjt_functionParam352);
#line 22 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_parent207 = array3;
#line 22
    sjt_functionParam353 = 34;
#line 34
    sjt_functionParam354 = 22;
#line 0 ""
    sjf_array_i32_initAt(sjt_parent207, sjt_functionParam353, sjt_functionParam354);
#line 22 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_parent208 = array3;
#line 22
    sjt_functionParam355 = 35;
#line 34
    sjt_functionParam356 = 23;
#line 0 ""
    sjf_array_i32_initAt(sjt_parent208, sjt_functionParam355, sjt_functionParam356);
#line 36 ".\..\lib\ui\vertexBufferBuilders.sj"
    (*_return)->vertices.size = 24;
#line 3 ".\..\lib\common\array.sj"
    sjt_cast49 = 0;
#line 3
    (*_return)->vertices.data = (uintptr_t)sjt_cast49;
#line 4
    (*_return)->vertices._isGlobal = false;
#line 0 ""
    sjf_array_vertex_location_texture_normal(&(*_return)->vertices);
#line 36 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjs_array_vertex_location_texture_normal* array4;
#line 36
    array4 = &(*_return)->vertices;
#line 36
    sjt_parent209 = array4;
#line 36
    sjt_functionParam357 = 0;
#line 8
    sjt_call34.location.x = x0;
#line 8
    sjt_call34.location.y = y0;
#line 8
    sjt_call34.location.z = z0;
#line 0 ""
    sjf_vec3(&sjt_call34.location);
#line 8 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_call34.texture.x = s0;
#line 8
    sjt_call34.texture.y = t0;
#line 0 ""
    sjf_vec2(&sjt_call34.texture);
#line 37 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_call34.normal.x = 0.0f;
#line 37
    sjt_call34.normal.y = 0.0f;
#line 37
    sjt_negate22 = 1.0f;
#line 37
    result32 = -sjt_negate22;
#line 37
    sjt_call34.normal.z = result32;
#line 0 ""
    sjf_vec3(&sjt_call34.normal);
    sjf_vertex_location_texture_normal(&sjt_call34);
#line 37 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_functionParam358 = &sjt_call34;
#line 0 ""
    sjf_array_vertex_location_texture_normal_initAt(sjt_parent209, sjt_functionParam357, sjt_functionParam358);
#line 36 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_parent210 = array4;
#line 36
    sjt_functionParam359 = 1;
#line 8
    sjt_call35.location.x = x0;
#line 8
    sjt_call35.location.y = y1;
#line 8
    sjt_call35.location.z = z0;
#line 0 ""
    sjf_vec3(&sjt_call35.location);
#line 8 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_call35.texture.x = s0;
#line 8
    sjt_call35.texture.y = t1;
#line 0 ""
    sjf_vec2(&sjt_call35.texture);
#line 38 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_call35.normal.x = 0.0f;
#line 38
    sjt_call35.normal.y = 0.0f;
#line 38
    sjt_negate23 = 1.0f;
#line 38
    result33 = -sjt_negate23;
#line 38
    sjt_call35.normal.z = result33;
#line 0 ""
    sjf_vec3(&sjt_call35.normal);
    sjf_vertex_location_texture_normal(&sjt_call35);
#line 38 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_functionParam360 = &sjt_call35;
#line 0 ""
    sjf_array_vertex_location_texture_normal_initAt(sjt_parent210, sjt_functionParam359, sjt_functionParam360);
#line 36 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_parent211 = array4;
#line 36
    sjt_functionParam361 = 2;
#line 8
    sjt_call36.location.x = x1;
#line 8
    sjt_call36.location.y = y1;
#line 8
    sjt_call36.location.z = z0;
#line 0 ""
    sjf_vec3(&sjt_call36.location);
#line 8 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_call36.texture.x = s1;
#line 8
    sjt_call36.texture.y = t1;
#line 0 ""
    sjf_vec2(&sjt_call36.texture);
#line 39 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_call36.normal.x = 0.0f;
#line 39
    sjt_call36.normal.y = 0.0f;
#line 39
    sjt_negate24 = 1.0f;
#line 39
    result34 = -sjt_negate24;
#line 39
    sjt_call36.normal.z = result34;
#line 0 ""
    sjf_vec3(&sjt_call36.normal);
    sjf_vertex_location_texture_normal(&sjt_call36);
#line 39 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_functionParam362 = &sjt_call36;
#line 0 ""
    sjf_array_vertex_location_texture_normal_initAt(sjt_parent211, sjt_functionParam361, sjt_functionParam362);
#line 36 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_parent212 = array4;
#line 36
    sjt_functionParam363 = 3;
#line 8
    sjt_call37.location.x = x1;
#line 8
    sjt_call37.location.y = y0;
#line 8
    sjt_call37.location.z = z0;
#line 0 ""
    sjf_vec3(&sjt_call37.location);
#line 8 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_call37.texture.x = s1;
#line 8
    sjt_call37.texture.y = t0;
#line 0 ""
    sjf_vec2(&sjt_call37.texture);
#line 40 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_call37.normal.x = 0.0f;
#line 40
    sjt_call37.normal.y = 0.0f;
#line 40
    sjt_negate25 = 1.0f;
#line 40
    result35 = -sjt_negate25;
#line 40
    sjt_call37.normal.z = result35;
#line 0 ""
    sjf_vec3(&sjt_call37.normal);
    sjf_vertex_location_texture_normal(&sjt_call37);
#line 40 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_functionParam364 = &sjt_call37;
#line 0 ""
    sjf_array_vertex_location_texture_normal_initAt(sjt_parent212, sjt_functionParam363, sjt_functionParam364);
#line 36 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_parent213 = array4;
#line 36
    sjt_functionParam365 = 4;
#line 8
    sjt_call38.location.x = x0;
#line 8
    sjt_call38.location.y = y0;
#line 8
    sjt_call38.location.z = z1;
#line 0 ""
    sjf_vec3(&sjt_call38.location);
#line 8 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_call38.texture.x = s0;
#line 8
    sjt_call38.texture.y = t0;
#line 0 ""
    sjf_vec2(&sjt_call38.texture);
#line 41 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_call38.normal.x = 0.0f;
#line 41
    sjt_call38.normal.y = 0.0f;
#line 41
    sjt_call38.normal.z = 1.0f;
#line 0 ""
    sjf_vec3(&sjt_call38.normal);
    sjf_vertex_location_texture_normal(&sjt_call38);
#line 41 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_functionParam366 = &sjt_call38;
#line 0 ""
    sjf_array_vertex_location_texture_normal_initAt(sjt_parent213, sjt_functionParam365, sjt_functionParam366);
#line 36 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_parent214 = array4;
#line 36
    sjt_functionParam367 = 5;
#line 8
    sjt_call39.location.x = x0;
#line 8
    sjt_call39.location.y = y1;
#line 8
    sjt_call39.location.z = z1;
#line 0 ""
    sjf_vec3(&sjt_call39.location);
#line 8 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_call39.texture.x = s0;
#line 8
    sjt_call39.texture.y = t1;
#line 0 ""
    sjf_vec2(&sjt_call39.texture);
#line 42 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_call39.normal.x = 0.0f;
#line 42
    sjt_call39.normal.y = 0.0f;
#line 42
    sjt_call39.normal.z = 1.0f;
#line 0 ""
    sjf_vec3(&sjt_call39.normal);
    sjf_vertex_location_texture_normal(&sjt_call39);
#line 42 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_functionParam368 = &sjt_call39;
#line 0 ""
    sjf_array_vertex_location_texture_normal_initAt(sjt_parent214, sjt_functionParam367, sjt_functionParam368);
#line 36 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_parent215 = array4;
#line 36
    sjt_functionParam369 = 6;
#line 8
    sjt_call40.location.x = x1;
#line 8
    sjt_call40.location.y = y1;
#line 8
    sjt_call40.location.z = z1;
#line 0 ""
    sjf_vec3(&sjt_call40.location);
#line 8 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_call40.texture.x = s1;
#line 8
    sjt_call40.texture.y = t1;
#line 0 ""
    sjf_vec2(&sjt_call40.texture);
#line 43 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_call40.normal.x = 0.0f;
#line 43
    sjt_call40.normal.y = 0.0f;
#line 43
    sjt_call40.normal.z = 1.0f;
#line 0 ""
    sjf_vec3(&sjt_call40.normal);
    sjf_vertex_location_texture_normal(&sjt_call40);
#line 43 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_functionParam370 = &sjt_call40;
#line 0 ""
    sjf_array_vertex_location_texture_normal_initAt(sjt_parent215, sjt_functionParam369, sjt_functionParam370);
#line 36 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_parent216 = array4;
#line 36
    sjt_functionParam371 = 7;
#line 8
    sjt_call41.location.x = x1;
#line 8
    sjt_call41.location.y = y0;
#line 8
    sjt_call41.location.z = z1;
#line 0 ""
    sjf_vec3(&sjt_call41.location);
#line 8 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_call41.texture.x = s1;
#line 8
    sjt_call41.texture.y = t0;
#line 0 ""
    sjf_vec2(&sjt_call41.texture);
#line 44 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_call41.normal.x = 0.0f;
#line 44
    sjt_call41.normal.y = 0.0f;
#line 44
    sjt_call41.normal.z = 1.0f;
#line 0 ""
    sjf_vec3(&sjt_call41.normal);
    sjf_vertex_location_texture_normal(&sjt_call41);
#line 44 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_functionParam372 = &sjt_call41;
#line 0 ""
    sjf_array_vertex_location_texture_normal_initAt(sjt_parent216, sjt_functionParam371, sjt_functionParam372);
#line 36 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_parent217 = array4;
#line 36
    sjt_functionParam373 = 8;
#line 8
    sjt_call42.location.x = x0;
#line 8
    sjt_call42.location.y = y0;
#line 8
    sjt_call42.location.z = z0;
#line 0 ""
    sjf_vec3(&sjt_call42.location);
#line 8 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_call42.texture.x = s0;
#line 8
    sjt_call42.texture.y = t0;
#line 0 ""
    sjf_vec2(&sjt_call42.texture);
#line 45 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_negate26 = 1.0f;
#line 45
    result36 = -sjt_negate26;
#line 45
    sjt_call42.normal.x = result36;
#line 45
    sjt_call42.normal.y = 0.0f;
#line 45
    sjt_call42.normal.z = 0.0f;
#line 0 ""
    sjf_vec3(&sjt_call42.normal);
    sjf_vertex_location_texture_normal(&sjt_call42);
#line 45 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_functionParam374 = &sjt_call42;
#line 0 ""
    sjf_array_vertex_location_texture_normal_initAt(sjt_parent217, sjt_functionParam373, sjt_functionParam374);
#line 36 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_parent218 = array4;
#line 36
    sjt_functionParam375 = 9;
#line 8
    sjt_call43.location.x = x0;
#line 8
    sjt_call43.location.y = y1;
#line 8
    sjt_call43.location.z = z0;
#line 0 ""
    sjf_vec3(&sjt_call43.location);
#line 8 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_call43.texture.x = s0;
#line 8
    sjt_call43.texture.y = t1;
#line 0 ""
    sjf_vec2(&sjt_call43.texture);
#line 46 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_negate27 = 1.0f;
#line 46
    result37 = -sjt_negate27;
#line 46
    sjt_call43.normal.x = result37;
#line 46
    sjt_call43.normal.y = 0.0f;
#line 46
    sjt_call43.normal.z = 0.0f;
#line 0 ""
    sjf_vec3(&sjt_call43.normal);
    sjf_vertex_location_texture_normal(&sjt_call43);
#line 46 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_functionParam376 = &sjt_call43;
#line 0 ""
    sjf_array_vertex_location_texture_normal_initAt(sjt_parent218, sjt_functionParam375, sjt_functionParam376);
#line 36 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_parent219 = array4;
#line 36
    sjt_functionParam377 = 10;
#line 8
    sjt_call44.location.x = x0;
#line 8
    sjt_call44.location.y = y1;
#line 8
    sjt_call44.location.z = z1;
#line 0 ""
    sjf_vec3(&sjt_call44.location);
#line 8 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_call44.texture.x = s1;
#line 8
    sjt_call44.texture.y = t1;
#line 0 ""
    sjf_vec2(&sjt_call44.texture);
#line 47 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_negate28 = 1.0f;
#line 47
    result38 = -sjt_negate28;
#line 47
    sjt_call44.normal.x = result38;
#line 47
    sjt_call44.normal.y = 0.0f;
#line 47
    sjt_call44.normal.z = 0.0f;
#line 0 ""
    sjf_vec3(&sjt_call44.normal);
    sjf_vertex_location_texture_normal(&sjt_call44);
#line 47 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_functionParam378 = &sjt_call44;
#line 0 ""
    sjf_array_vertex_location_texture_normal_initAt(sjt_parent219, sjt_functionParam377, sjt_functionParam378);
#line 36 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_parent220 = array4;
#line 36
    sjt_functionParam379 = 11;
#line 8
    sjt_call45.location.x = x0;
#line 8
    sjt_call45.location.y = y0;
#line 8
    sjt_call45.location.z = z1;
#line 0 ""
    sjf_vec3(&sjt_call45.location);
#line 8 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_call45.texture.x = s1;
#line 8
    sjt_call45.texture.y = t0;
#line 0 ""
    sjf_vec2(&sjt_call45.texture);
#line 48 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_negate29 = 1.0f;
#line 48
    result39 = -sjt_negate29;
#line 48
    sjt_call45.normal.x = result39;
#line 48
    sjt_call45.normal.y = 0.0f;
#line 48
    sjt_call45.normal.z = 0.0f;
#line 0 ""
    sjf_vec3(&sjt_call45.normal);
    sjf_vertex_location_texture_normal(&sjt_call45);
#line 48 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_functionParam380 = &sjt_call45;
#line 0 ""
    sjf_array_vertex_location_texture_normal_initAt(sjt_parent220, sjt_functionParam379, sjt_functionParam380);
#line 36 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_parent221 = array4;
#line 36
    sjt_functionParam381 = 12;
#line 8
    sjt_call46.location.x = x1;
#line 8
    sjt_call46.location.y = y0;
#line 8
    sjt_call46.location.z = z0;
#line 0 ""
    sjf_vec3(&sjt_call46.location);
#line 8 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_call46.texture.x = s0;
#line 8
    sjt_call46.texture.y = t0;
#line 0 ""
    sjf_vec2(&sjt_call46.texture);
#line 49 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_call46.normal.x = 1.0f;
#line 49
    sjt_call46.normal.y = 0.0f;
#line 49
    sjt_call46.normal.z = 0.0f;
#line 0 ""
    sjf_vec3(&sjt_call46.normal);
    sjf_vertex_location_texture_normal(&sjt_call46);
#line 49 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_functionParam382 = &sjt_call46;
#line 0 ""
    sjf_array_vertex_location_texture_normal_initAt(sjt_parent221, sjt_functionParam381, sjt_functionParam382);
#line 36 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_parent222 = array4;
#line 36
    sjt_functionParam383 = 13;
#line 8
    sjt_call47.location.x = x1;
#line 8
    sjt_call47.location.y = y1;
#line 8
    sjt_call47.location.z = z0;
#line 0 ""
    sjf_vec3(&sjt_call47.location);
#line 8 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_call47.texture.x = s0;
#line 8
    sjt_call47.texture.y = t1;
#line 0 ""
    sjf_vec2(&sjt_call47.texture);
#line 50 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_call47.normal.x = 1.0f;
#line 50
    sjt_call47.normal.y = 0.0f;
#line 50
    sjt_call47.normal.z = 0.0f;
#line 0 ""
    sjf_vec3(&sjt_call47.normal);
    sjf_vertex_location_texture_normal(&sjt_call47);
#line 50 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_functionParam384 = &sjt_call47;
#line 0 ""
    sjf_array_vertex_location_texture_normal_initAt(sjt_parent222, sjt_functionParam383, sjt_functionParam384);
#line 36 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_parent223 = array4;
#line 36
    sjt_functionParam385 = 14;
#line 8
    sjt_call48.location.x = x1;
#line 8
    sjt_call48.location.y = y1;
#line 8
    sjt_call48.location.z = z1;
#line 0 ""
    sjf_vec3(&sjt_call48.location);
#line 8 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_call48.texture.x = s1;
#line 8
    sjt_call48.texture.y = t1;
#line 0 ""
    sjf_vec2(&sjt_call48.texture);
#line 51 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_call48.normal.x = 1.0f;
#line 51
    sjt_call48.normal.y = 0.0f;
#line 51
    sjt_call48.normal.z = 0.0f;
#line 0 ""
    sjf_vec3(&sjt_call48.normal);
    sjf_vertex_location_texture_normal(&sjt_call48);
#line 51 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_functionParam386 = &sjt_call48;
#line 0 ""
    sjf_array_vertex_location_texture_normal_initAt(sjt_parent223, sjt_functionParam385, sjt_functionParam386);
#line 36 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_parent224 = array4;
#line 36
    sjt_functionParam387 = 15;
#line 8
    sjt_call49.location.x = x1;
#line 8
    sjt_call49.location.y = y0;
#line 8
    sjt_call49.location.z = z1;
#line 0 ""
    sjf_vec3(&sjt_call49.location);
#line 8 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_call49.texture.x = s1;
#line 8
    sjt_call49.texture.y = t0;
#line 0 ""
    sjf_vec2(&sjt_call49.texture);
#line 52 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_call49.normal.x = 1.0f;
#line 52
    sjt_call49.normal.y = 0.0f;
#line 52
    sjt_call49.normal.z = 0.0f;
#line 0 ""
    sjf_vec3(&sjt_call49.normal);
    sjf_vertex_location_texture_normal(&sjt_call49);
#line 52 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_functionParam388 = &sjt_call49;
#line 0 ""
    sjf_array_vertex_location_texture_normal_initAt(sjt_parent224, sjt_functionParam387, sjt_functionParam388);
#line 36 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_parent225 = array4;
#line 36
    sjt_functionParam389 = 16;
#line 8
    sjt_call50.location.x = x0;
#line 8
    sjt_call50.location.y = y0;
#line 8
    sjt_call50.location.z = z0;
#line 0 ""
    sjf_vec3(&sjt_call50.location);
#line 8 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_call50.texture.x = s0;
#line 8
    sjt_call50.texture.y = t0;
#line 0 ""
    sjf_vec2(&sjt_call50.texture);
#line 53 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_call50.normal.x = 0.0f;
#line 53
    sjt_negate30 = 1.0f;
#line 53
    result40 = -sjt_negate30;
#line 53
    sjt_call50.normal.y = result40;
#line 53
    sjt_call50.normal.z = 0.0f;
#line 0 ""
    sjf_vec3(&sjt_call50.normal);
    sjf_vertex_location_texture_normal(&sjt_call50);
#line 53 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_functionParam390 = &sjt_call50;
#line 0 ""
    sjf_array_vertex_location_texture_normal_initAt(sjt_parent225, sjt_functionParam389, sjt_functionParam390);
#line 36 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_parent226 = array4;
#line 36
    sjt_functionParam391 = 17;
#line 8
    sjt_call51.location.x = x0;
#line 8
    sjt_call51.location.y = y0;
#line 8
    sjt_call51.location.z = z1;
#line 0 ""
    sjf_vec3(&sjt_call51.location);
#line 8 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_call51.texture.x = s0;
#line 8
    sjt_call51.texture.y = t1;
#line 0 ""
    sjf_vec2(&sjt_call51.texture);
#line 54 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_call51.normal.x = 0.0f;
#line 54
    sjt_negate31 = 1.0f;
#line 54
    result41 = -sjt_negate31;
#line 54
    sjt_call51.normal.y = result41;
#line 54
    sjt_call51.normal.z = 0.0f;
#line 0 ""
    sjf_vec3(&sjt_call51.normal);
    sjf_vertex_location_texture_normal(&sjt_call51);
#line 54 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_functionParam392 = &sjt_call51;
#line 0 ""
    sjf_array_vertex_location_texture_normal_initAt(sjt_parent226, sjt_functionParam391, sjt_functionParam392);
#line 36 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_parent227 = array4;
#line 36
    sjt_functionParam393 = 18;
#line 8
    sjt_call52.location.x = x1;
#line 8
    sjt_call52.location.y = y0;
#line 8
    sjt_call52.location.z = z1;
#line 0 ""
    sjf_vec3(&sjt_call52.location);
#line 8 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_call52.texture.x = s1;
#line 8
    sjt_call52.texture.y = t1;
#line 0 ""
    sjf_vec2(&sjt_call52.texture);
#line 55 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_call52.normal.x = 0.0f;
#line 55
    sjt_negate32 = 1.0f;
#line 55
    result42 = -sjt_negate32;
#line 55
    sjt_call52.normal.y = result42;
#line 55
    sjt_call52.normal.z = 0.0f;
#line 0 ""
    sjf_vec3(&sjt_call52.normal);
    sjf_vertex_location_texture_normal(&sjt_call52);
#line 55 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_functionParam394 = &sjt_call52;
#line 0 ""
    sjf_array_vertex_location_texture_normal_initAt(sjt_parent227, sjt_functionParam393, sjt_functionParam394);
#line 36 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_parent228 = array4;
#line 36
    sjt_functionParam395 = 19;
#line 8
    sjt_call53.location.x = x1;
#line 8
    sjt_call53.location.y = y0;
#line 8
    sjt_call53.location.z = z0;
#line 0 ""
    sjf_vec3(&sjt_call53.location);
#line 8 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_call53.texture.x = s1;
#line 8
    sjt_call53.texture.y = t0;
#line 0 ""
    sjf_vec2(&sjt_call53.texture);
#line 56 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_call53.normal.x = 0.0f;
#line 56
    sjt_negate33 = 1.0f;
#line 56
    result43 = -sjt_negate33;
#line 56
    sjt_call53.normal.y = result43;
#line 56
    sjt_call53.normal.z = 0.0f;
#line 0 ""
    sjf_vec3(&sjt_call53.normal);
    sjf_vertex_location_texture_normal(&sjt_call53);
#line 56 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_functionParam396 = &sjt_call53;
#line 0 ""
    sjf_array_vertex_location_texture_normal_initAt(sjt_parent228, sjt_functionParam395, sjt_functionParam396);
#line 36 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_parent229 = array4;
#line 36
    sjt_functionParam397 = 20;
#line 8
    sjt_call54.location.x = x0;
#line 8
    sjt_call54.location.y = y1;
#line 8
    sjt_call54.location.z = z0;
#line 0 ""
    sjf_vec3(&sjt_call54.location);
#line 8 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_call54.texture.x = s0;
#line 8
    sjt_call54.texture.y = t0;
#line 0 ""
    sjf_vec2(&sjt_call54.texture);
#line 57 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_call54.normal.x = 0.0f;
#line 57
    sjt_call54.normal.y = 1.0f;
#line 57
    sjt_call54.normal.z = 0.0f;
#line 0 ""
    sjf_vec3(&sjt_call54.normal);
    sjf_vertex_location_texture_normal(&sjt_call54);
#line 57 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_functionParam398 = &sjt_call54;
#line 0 ""
    sjf_array_vertex_location_texture_normal_initAt(sjt_parent229, sjt_functionParam397, sjt_functionParam398);
#line 36 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_parent230 = array4;
#line 36
    sjt_functionParam399 = 21;
#line 8
    sjt_call55.location.x = x0;
#line 8
    sjt_call55.location.y = y1;
#line 8
    sjt_call55.location.z = z1;
#line 0 ""
    sjf_vec3(&sjt_call55.location);
#line 8 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_call55.texture.x = s0;
#line 8
    sjt_call55.texture.y = t1;
#line 0 ""
    sjf_vec2(&sjt_call55.texture);
#line 58 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_call55.normal.x = 0.0f;
#line 58
    sjt_call55.normal.y = 1.0f;
#line 58
    sjt_call55.normal.z = 0.0f;
#line 0 ""
    sjf_vec3(&sjt_call55.normal);
    sjf_vertex_location_texture_normal(&sjt_call55);
#line 58 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_functionParam400 = &sjt_call55;
#line 0 ""
    sjf_array_vertex_location_texture_normal_initAt(sjt_parent230, sjt_functionParam399, sjt_functionParam400);
#line 36 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_parent231 = array4;
#line 36
    sjt_functionParam401 = 22;
#line 8
    sjt_call56.location.x = x1;
#line 8
    sjt_call56.location.y = y1;
#line 8
    sjt_call56.location.z = z1;
#line 0 ""
    sjf_vec3(&sjt_call56.location);
#line 8 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_call56.texture.x = s1;
#line 8
    sjt_call56.texture.y = t1;
#line 0 ""
    sjf_vec2(&sjt_call56.texture);
#line 59 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_call56.normal.x = 0.0f;
#line 59
    sjt_call56.normal.y = 1.0f;
#line 59
    sjt_call56.normal.z = 0.0f;
#line 0 ""
    sjf_vec3(&sjt_call56.normal);
    sjf_vertex_location_texture_normal(&sjt_call56);
#line 59 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_functionParam402 = &sjt_call56;
#line 0 ""
    sjf_array_vertex_location_texture_normal_initAt(sjt_parent231, sjt_functionParam401, sjt_functionParam402);
#line 36 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_parent232 = array4;
#line 36
    sjt_functionParam403 = 23;
#line 8
    sjt_call57.location.x = x1;
#line 8
    sjt_call57.location.y = y1;
#line 8
    sjt_call57.location.z = z0;
#line 0 ""
    sjf_vec3(&sjt_call57.location);
#line 8 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_call57.texture.x = s1;
#line 8
    sjt_call57.texture.y = t0;
#line 0 ""
    sjf_vec2(&sjt_call57.texture);
#line 60 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_call57.normal.x = 0.0f;
#line 60
    sjt_call57.normal.y = 1.0f;
#line 60
    sjt_call57.normal.z = 0.0f;
#line 0 ""
    sjf_vec3(&sjt_call57.normal);
    sjf_vertex_location_texture_normal(&sjt_call57);
#line 60 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_functionParam404 = &sjt_call57;
#line 0 ""
    sjf_array_vertex_location_texture_normal_initAt(sjt_parent232, sjt_functionParam403, sjt_functionParam404);
    sjf_vertexBuffer_vertex_location_texture_normal_heap((*_return));

    sjf_vertex_location_texture_normal_destroy(&sjt_call34);
    sjf_vertex_location_texture_normal_destroy(&sjt_call35);
    sjf_vertex_location_texture_normal_destroy(&sjt_call36);
    sjf_vertex_location_texture_normal_destroy(&sjt_call37);
    sjf_vertex_location_texture_normal_destroy(&sjt_call38);
    sjf_vertex_location_texture_normal_destroy(&sjt_call39);
    sjf_vertex_location_texture_normal_destroy(&sjt_call40);
    sjf_vertex_location_texture_normal_destroy(&sjt_call41);
    sjf_vertex_location_texture_normal_destroy(&sjt_call42);
    sjf_vertex_location_texture_normal_destroy(&sjt_call43);
    sjf_vertex_location_texture_normal_destroy(&sjt_call44);
    sjf_vertex_location_texture_normal_destroy(&sjt_call45);
    sjf_vertex_location_texture_normal_destroy(&sjt_call46);
    sjf_vertex_location_texture_normal_destroy(&sjt_call47);
    sjf_vertex_location_texture_normal_destroy(&sjt_call48);
    sjf_vertex_location_texture_normal_destroy(&sjt_call49);
    sjf_vertex_location_texture_normal_destroy(&sjt_call50);
    sjf_vertex_location_texture_normal_destroy(&sjt_call51);
    sjf_vertex_location_texture_normal_destroy(&sjt_call52);
    sjf_vertex_location_texture_normal_destroy(&sjt_call53);
    sjf_vertex_location_texture_normal_destroy(&sjt_call54);
    sjf_vertex_location_texture_normal_destroy(&sjt_call55);
    sjf_vertex_location_texture_normal_destroy(&sjt_call56);
    sjf_vertex_location_texture_normal_destroy(&sjt_call57);
}

void sjf_f32_cos(float v, float* _return) {
    float sjv_result;

#line 10 ".\..\lib\common\math.sj"
    sjv_result = 0.0f;
#line 11
    sjv_result = cosf(v);
#line 9
    (*_return) = sjv_result;
}

void sjf_f32_sin(float v, float* _return) {
    float sjv_result;

#line 18 ".\..\lib\common\math.sj"
    sjv_result = 0.0f;
#line 19
    sjv_result = sinf(v);
#line 17
    (*_return) = sjv_result;
}

void sjf_f32_sqrt(float v, float* _return) {
    float sjv_result;

#line 2 ".\..\lib\common\math.sj"
    sjv_result = 0.0f;
#line 3
    sjv_result = sqrtf(v);
#line 1
    (*_return) = sjv_result;
}

void sjf_f32_tan(float v, float* _return) {
    float sjv_result;

#line 26 ".\..\lib\common\math.sj"
    sjv_result = 0.0f;
#line 27
    sjv_result = tanf(v);
#line 25
    (*_return) = sjv_result;
}

void sjf_fillElement(sjs_fillElement* _this) {
}

sjs_object* sjf_fillElement_asInterface(sjs_fillElement* _this, int typeId) {
    switch (typeId) {
        case sji_element_typeId:  {
            return (sjs_object*)sjf_fillElement_as_sji_element(_this);
        }
    }

    return 0;
}

sji_element* sjf_fillElement_as_sji_element(sjs_fillElement* _this) {
    sji_element* _interface;
    _interface = (sji_element*)malloc(sizeof(sji_element));
    _interface->_refCount = 1;
    _interface->_parent = (sjs_object*)_this;
    _interface->_parent->_refCount++;
    _interface->destroy = (void(*)(void*))sjf_fillElement_destroy;
    _interface->asInterface = (sjs_object*(*)(sjs_object*,int))sjf_fillElement_asInterface;
    _interface->getSize = (void(*)(void*,sjs_size*, sjs_size*))sjf_fillElement_getSize;
    _interface->getSize_heap = (void(*)(void*,sjs_size*, sjs_size_heap**))sjf_fillElement_getSize_heap;
    _interface->getRect = (void(*)(void*, sjs_rect**))sjf_fillElement_getRect;
    _interface->setRect = (void(*)(void*,sjs_rect*))sjf_fillElement_setRect;
    _interface->render = (void(*)(void*,sjs_scene2d*))sjf_fillElement_render;
    _interface->getChildren = (void(*)(void*, sjs_array_heap_element**))sjf_fillElement_getChildren;
    _interface->fireMouseEvent = (void(*)(void*,sjs_point*,int32_t))sjf_fillElement_fireMouseEvent;

    return _interface;
}

void sjf_fillElement_copy(sjs_fillElement* _this, sjs_fillElement* _from) {
#line 1 ".\..\lib\ui\fillElement.sj"
    sjf_array_heap_element_copy(&_this->children, &_from->children);
#line 1
    sjf_rect_copy(&_this->_rect, &_from->_rect);
}

void sjf_fillElement_destroy(sjs_fillElement* _this) {
}

void sjf_fillElement_fireMouseEvent(sjs_fillElement* _parent, sjs_point* point, int32_t eventId) {
    int32_t i;
    sjs_array_heap_element* sjt_dot15;
    sjs_fillElement* sjt_dot16;
    int32_t sjt_forEnd3;
    int32_t sjt_forStart3;

#line 33 ".\..\lib\ui\fillElement.sj"
    sjt_forStart3 = 0;
#line 33
    i = sjt_forStart3;
#line 32
    sjt_dot16 = _parent;
#line 1 ".\..\lib\common\array.sj"
    sjt_dot15 = &(sjt_dot16)->children;
#line 33 ".\..\lib\ui\fillElement.sj"
    sjt_forEnd3 = (sjt_dot15)->size;
    while (i < sjt_forEnd3) {
        sjs_fillElement* sjt_dot17;
        int32_t sjt_functionParam3;
        sjs_point* sjt_interfaceParam3;
        int32_t sjt_interfaceParam4;
        sjs_array_heap_element* sjt_parent5;
        sji_element* sjt_parent6;
        sji_element* sjv_child;

#line 32 ".\..\lib\ui\fillElement.sj"
        sjt_dot17 = _parent;
#line 6 ".\..\lib\common\array.sj"
        sjt_parent5 = &(sjt_dot17)->children;
#line 33 ".\..\lib\ui\fillElement.sj"
        sjt_functionParam3 = i;
#line 0 ""
        sjf_array_heap_element_getAt_heap(sjt_parent5, sjt_functionParam3, &sjv_child);
#line 7 ".\..\lib\ui\element.sj"
        sjt_parent6 = sjv_child;
#line 32 ".\..\lib\ui\fillElement.sj"
        sjt_interfaceParam3 = point;
#line 32
        sjt_interfaceParam4 = eventId;
#line 35
        sjt_parent6->fireMouseEvent((void*)(((char*)sjt_parent6->_parent) + sizeof(intptr_t)), sjt_interfaceParam3, sjt_interfaceParam4);
#line 33
        i++;

        sjv_child->_refCount--;
        if (sjv_child->_refCount <= 0) {
            sji_element_destroy(sjv_child);
        }
    }
}

void sjf_fillElement_getChildren(sjs_fillElement* _parent, sjs_array_heap_element** _return) {
    sjs_fillElement* sjt_dot14;
    sjs_array_heap_element* sjt_value1;
    sjs_array_heap_element* sjv_a;

#line 27 ".\..\lib\ui\fillElement.sj"
    sjt_dot14 = _parent;
#line 28
    sjv_a = &(sjt_dot14)->children;
#line 29
    sjt_value1 = sjv_a;
#line 29
    (*_return) = sjt_value1;
}

void sjf_fillElement_getRect(sjs_fillElement* _parent, sjs_rect** _return) {
    sjs_fillElement* sjt_dot5;

#line 9 ".\..\lib\ui\fillElement.sj"
    sjt_dot5 = _parent;
#line 9
    (*_return) = &(sjt_dot5)->_rect;
}

void sjf_fillElement_getSize(sjs_fillElement* _parent, sjs_size* maxSize, sjs_size* _return) {
    sjs_size* sjt_dot1;
    sjs_size* sjt_dot2;

#line 5 ".\..\lib\ui\fillElement.sj"
    sjt_dot1 = maxSize;
#line 6
    _return->w = (sjt_dot1)->w;
#line 5
    sjt_dot2 = maxSize;
#line 6
    _return->h = (sjt_dot2)->h;
#line 0 ""
    sjf_size(_return);
}

void sjf_fillElement_getSize_heap(sjs_fillElement* _parent, sjs_size* maxSize, sjs_size_heap** _return) {
    sjs_size* sjt_dot3;
    sjs_size* sjt_dot4;

    (*_return) = (sjs_size_heap*)malloc(sizeof(sjs_size_heap));
    (*_return)->_refCount = 1;
#line 5 ".\..\lib\ui\fillElement.sj"
    sjt_dot3 = maxSize;
#line 6
    (*_return)->w = (sjt_dot3)->w;
#line 5
    sjt_dot4 = maxSize;
#line 6
    (*_return)->h = (sjt_dot4)->h;
#line 0 ""
    sjf_size_heap((*_return));
}

void sjf_fillElement_heap(sjs_fillElement_heap* _this) {
}

sjs_object* sjf_fillElement_heap_asInterface(sjs_fillElement_heap* _this, int typeId) {
    switch (typeId) {
        case sji_element_typeId:  {
            return (sjs_object*)sjf_fillElement_heap_as_sji_element(_this);
        }
    }

    return 0;
}

sji_element* sjf_fillElement_heap_as_sji_element(sjs_fillElement_heap* _this) {
    sji_element* _interface;
    _interface = (sji_element*)malloc(sizeof(sji_element));
    _interface->_refCount = 1;
    _interface->_parent = (sjs_object*)_this;
    _interface->_parent->_refCount++;
    _interface->destroy = (void(*)(void*))sjf_fillElement_destroy;
    _interface->asInterface = (sjs_object*(*)(sjs_object*,int))sjf_fillElement_heap_asInterface;
    _interface->getSize = (void(*)(void*,sjs_size*, sjs_size*))sjf_fillElement_getSize;
    _interface->getSize_heap = (void(*)(void*,sjs_size*, sjs_size_heap**))sjf_fillElement_getSize_heap;
    _interface->getRect = (void(*)(void*, sjs_rect**))sjf_fillElement_getRect;
    _interface->setRect = (void(*)(void*,sjs_rect*))sjf_fillElement_setRect;
    _interface->render = (void(*)(void*,sjs_scene2d*))sjf_fillElement_render;
    _interface->getChildren = (void(*)(void*, sjs_array_heap_element**))sjf_fillElement_getChildren;
    _interface->fireMouseEvent = (void(*)(void*,sjs_point*,int32_t))sjf_fillElement_fireMouseEvent;

    return _interface;
}

void sjf_fillElement_render(sjs_fillElement* _parent, sjs_scene2d* scene) {
    int32_t i;
    sjs_array_heap_element* sjt_dot11;
    sjs_fillElement* sjt_dot12;
    int32_t sjt_forEnd2;
    int32_t sjt_forStart2;

#line 21 ".\..\lib\ui\fillElement.sj"
    sjt_forStart2 = 0;
#line 21
    i = sjt_forStart2;
#line 20
    sjt_dot12 = _parent;
#line 1 ".\..\lib\common\array.sj"
    sjt_dot11 = &(sjt_dot12)->children;
#line 21 ".\..\lib\ui\fillElement.sj"
    sjt_forEnd2 = (sjt_dot11)->size;
    while (i < sjt_forEnd2) {
        sjs_fillElement* sjt_dot13;
        int32_t sjt_functionParam2;
        sjs_scene2d* sjt_interfaceParam2;
        sjs_array_heap_element* sjt_parent3;
        sji_element* sjt_parent4;
        sji_element* sjv_child;

#line 20 ".\..\lib\ui\fillElement.sj"
        sjt_dot13 = _parent;
#line 6 ".\..\lib\common\array.sj"
        sjt_parent3 = &(sjt_dot13)->children;
#line 21 ".\..\lib\ui\fillElement.sj"
        sjt_functionParam2 = i;
#line 0 ""
        sjf_array_heap_element_getAt_heap(sjt_parent3, sjt_functionParam2, &sjv_child);
#line 5 ".\..\lib\ui\element.sj"
        sjt_parent4 = sjv_child;
#line 20 ".\..\lib\ui\fillElement.sj"
        sjt_interfaceParam2 = scene;
#line 23
        sjt_parent4->render((void*)(((char*)sjt_parent4->_parent) + sizeof(intptr_t)), sjt_interfaceParam2);
#line 21
        i++;

        sjv_child->_refCount--;
        if (sjv_child->_refCount <= 0) {
            sji_element_destroy(sjv_child);
        }
    }
}

void sjf_fillElement_setRect(sjs_fillElement* _parent, sjs_rect* rect_) {
    int32_t i;
    sjs_fillElement* sjt_dot6;
    sjs_array_heap_element* sjt_dot7;
    sjs_fillElement* sjt_dot8;
    int32_t sjt_forEnd1;
    int32_t sjt_forStart1;

#line 11 ".\..\lib\ui\fillElement.sj"
    sjt_dot6 = _parent;
#line 11
    sjf_rect_copy(&sjt_dot6->_rect, rect_);
#line 13
    sjt_forStart1 = 0;
#line 13
    i = sjt_forStart1;
#line 11
    sjt_dot8 = _parent;
#line 1 ".\..\lib\common\array.sj"
    sjt_dot7 = &(sjt_dot8)->children;
#line 13 ".\..\lib\ui\fillElement.sj"
    sjt_forEnd1 = (sjt_dot7)->size;
    while (i < sjt_forEnd1) {
        sjs_fillElement* sjt_dot10;
        sjs_fillElement* sjt_dot9;
        int32_t sjt_functionParam1;
        sjs_rect* sjt_interfaceParam1;
        sjs_array_heap_element* sjt_parent1;
        sji_element* sjt_parent2;
        sji_element* sjv_child;

#line 11 ".\..\lib\ui\fillElement.sj"
        sjt_dot9 = _parent;
#line 6 ".\..\lib\common\array.sj"
        sjt_parent1 = &(sjt_dot9)->children;
#line 13 ".\..\lib\ui\fillElement.sj"
        sjt_functionParam1 = i;
#line 0 ""
        sjf_array_heap_element_getAt_heap(sjt_parent1, sjt_functionParam1, &sjv_child);
#line 4 ".\..\lib\ui\element.sj"
        sjt_parent2 = sjv_child;
#line 11 ".\..\lib\ui\fillElement.sj"
        sjt_dot10 = _parent;
#line 4 ".\..\lib\ui\element.sj"
        sjt_interfaceParam1 = &(sjt_dot10)->_rect;
#line 15 ".\..\lib\ui\fillElement.sj"
        sjt_parent2->setRect((void*)(((char*)sjt_parent2->_parent) + sizeof(intptr_t)), sjt_interfaceParam1);
#line 13
        i++;

        sjv_child->_refCount--;
        if (sjv_child->_refCount <= 0) {
            sji_element_destroy(sjv_child);
        }
    }
}

void sjf_frameBuffer(sjs_frameBuffer* _this) {
#line 9 ".\..\lib\ui\frameBuffer.sj"
    glGenFramebuffers(1, &_this->frameBufferId);
#line 9
    glGenTextures(1, &_this->textureId);
#line 9
    glBindFramebuffer(GL_FRAMEBUFFER, _this->frameBufferId);
#line 9
    glBindTexture(GL_TEXTURE_2D, _this->textureId);
#line 9
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
#line 9
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
#line 9
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
#line 9
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
#line 9
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, _this->size.w, _this->size.h, 0, GL_RGBA, GL_UNSIGNED_BYTE, NULL);
#line 9
    glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, _this->textureId, 0);
#line 9
    glGenRenderbuffers(1, &_this->depthBufferId);
#line 9
    glBindRenderbuffer(GL_RENDERBUFFER, _this->depthBufferId);
#line 9
    glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH_COMPONENT16, _this->size.w, _this->size.h);
#line 9
    glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_RENDERBUFFER, _this->depthBufferId);
#line 9
    GLenum status = glCheckFramebufferStatus(GL_FRAMEBUFFER);
#line 9
    if(status != GL_FRAMEBUFFER_COMPLETE) {
#line 9
        printf("Framebuffer status: %x", (int)status);
#line 9
    }
}

void sjf_frameBuffer_copy(sjs_frameBuffer* _this, sjs_frameBuffer* _from) {
#line 1 ".\..\lib\ui\frameBuffer.sj"
    sjf_size_copy(&_this->size, &_from->size);
#line 34
    _this->frameBufferId = _from->frameBufferId;
#line 34
    _retainGLid(_this->frameBufferId);
#line 34
    _this->textureId = _from->textureId;
#line 34
    _retainGLid(_this->textureId);
#line 34
    _this->depthBufferId = _from->depthBufferId;
#line 34
    _retainGLid(_this->depthBufferId);
}

void sjf_frameBuffer_destroy(sjs_frameBuffer* _this) {
#line 43 ".\..\lib\ui\frameBuffer.sj"
    if (_releaseGLid(_this->frameBufferId)) {
#line 43
        glDeleteFramebuffers(1, &_this->frameBufferId);
#line 43
    }
#line 43
    if (_releaseGLid(_this->textureId)) {
#line 43
        glDeleteTextures(1, &_this->textureId);
#line 43
    }
#line 43
    if (_releaseGLid(_this->depthBufferId)) {
#line 43
        glDeleteRenderbuffers(1, &_this->depthBufferId);
#line 43
    }
}

void sjf_frameBuffer_heap(sjs_frameBuffer_heap* _this) {
#line 9 ".\..\lib\ui\frameBuffer.sj"
    glGenFramebuffers(1, &_this->frameBufferId);
#line 9
    glGenTextures(1, &_this->textureId);
#line 9
    glBindFramebuffer(GL_FRAMEBUFFER, _this->frameBufferId);
#line 9
    glBindTexture(GL_TEXTURE_2D, _this->textureId);
#line 9
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
#line 9
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
#line 9
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
#line 9
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
#line 9
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, _this->size.w, _this->size.h, 0, GL_RGBA, GL_UNSIGNED_BYTE, NULL);
#line 9
    glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, _this->textureId, 0);
#line 9
    glGenRenderbuffers(1, &_this->depthBufferId);
#line 9
    glBindRenderbuffer(GL_RENDERBUFFER, _this->depthBufferId);
#line 9
    glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH_COMPONENT16, _this->size.w, _this->size.h);
#line 9
    glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_RENDERBUFFER, _this->depthBufferId);
#line 9
    GLenum status = glCheckFramebufferStatus(GL_FRAMEBUFFER);
#line 9
    if(status != GL_FRAMEBUFFER_COMPLETE) {
#line 9
        printf("Framebuffer status: %x", (int)status);
#line 9
    }
}

void sjf_i32_max(int32_t a, int32_t b, int32_t* _return) {
    int32_t sjt_compare3;
    int32_t sjt_compare4;
    bool sjt_ifElse2;

#line 39 ".\..\lib\common\math.sj"
    sjt_compare3 = a;
#line 39
    sjt_compare4 = b;
#line 40
    sjt_ifElse2 = sjt_compare3 < sjt_compare4;
    if (sjt_ifElse2) {
#line 39 ".\..\lib\common\math.sj"
        (*_return) = b;
    } else {
#line 39 ".\..\lib\common\math.sj"
        (*_return) = a;
    }
}

void sjf_image(sjs_image* _this) {
    bool sjt_and13;
    bool sjt_and14;
    int32_t sjt_compare55;
    int32_t sjt_compare56;
    int32_t sjt_compare57;
    int32_t sjt_compare58;
    sjs_rect* sjt_dot1332;
    sjs_rect* sjt_dot1333;
    bool sjt_ifElse30;

#line 1 ".\..\lib\ui\image.sj"
    sjt_dot1332 = &_this->rect;
#line 6
    sjt_compare55 = (sjt_dot1332)->w;
#line 6
    sjt_compare56 = 0;
#line 6
    sjt_and13 = sjt_compare55 == sjt_compare56;
#line 1
    sjt_dot1333 = &_this->rect;
#line 6
    sjt_compare57 = (sjt_dot1333)->h;
#line 6
    sjt_compare58 = 0;
#line 6
    sjt_and14 = sjt_compare57 == sjt_compare58;
#line 6
    sjt_ifElse30 = sjt_and13 && sjt_and14;
    if (sjt_ifElse30) {
        sjs_size* sjt_dot1342;
        sjs_size* sjt_dot1343;
        sjs_texture* sjt_parent102;
        sjs_size sjv_size;

#line 1 ".\..\lib\ui\image.sj"
        sjt_parent102 = &_this->texture;
#line 0 ""
        sjf_texture_getSize(sjt_parent102, &sjv_size);
#line 8 ".\..\lib\ui\image.sj"
        _this->rect.x = 0;
#line 8
        _this->rect.y = 0;
#line 1 ".\..\lib\ui\size.sj"
        sjt_dot1342 = &sjv_size;
#line 8 ".\..\lib\ui\image.sj"
        _this->rect.w = (sjt_dot1342)->w;
#line 1 ".\..\lib\ui\size.sj"
        sjt_dot1343 = &sjv_size;
#line 8 ".\..\lib\ui\image.sj"
        _this->rect.h = (sjt_dot1343)->h;
#line 0 ""
        sjf_rect(&_this->rect);

        sjf_size_destroy(&sjv_size);
    }
}

void sjf_imageElement(sjs_imageElement* _this) {
}

sjs_object* sjf_imageElement_asInterface(sjs_imageElement* _this, int typeId) {
    switch (typeId) {
        case sji_element_typeId:  {
            return (sjs_object*)sjf_imageElement_as_sji_element(_this);
        }
    }

    return 0;
}

sji_element* sjf_imageElement_as_sji_element(sjs_imageElement* _this) {
    sji_element* _interface;
    _interface = (sji_element*)malloc(sizeof(sji_element));
    _interface->_refCount = 1;
    _interface->_parent = (sjs_object*)_this;
    _interface->_parent->_refCount++;
    _interface->destroy = (void(*)(void*))sjf_imageElement_destroy;
    _interface->asInterface = (sjs_object*(*)(sjs_object*,int))sjf_imageElement_asInterface;
    _interface->getSize = (void(*)(void*,sjs_size*, sjs_size*))sjf_imageElement_getSize;
    _interface->getSize_heap = (void(*)(void*,sjs_size*, sjs_size_heap**))sjf_imageElement_getSize_heap;
    _interface->getRect = (void(*)(void*, sjs_rect**))sjf_imageElement_getRect;
    _interface->setRect = (void(*)(void*,sjs_rect*))sjf_imageElement_setRect;
    _interface->render = (void(*)(void*,sjs_scene2d*))sjf_imageElement_render;
    _interface->getChildren = (void(*)(void*, sjs_array_heap_element**))sjf_imageElement_getChildren;
    _interface->fireMouseEvent = (void(*)(void*,sjs_point*,int32_t))sjf_imageElement_fireMouseEvent;

    return _interface;
}

void sjf_imageElement_copy(sjs_imageElement* _this, sjs_imageElement* _from) {
#line 1 ".\..\lib\ui\imageElement.sj"
    sjf_image_copy(&_this->image, &_from->image);
#line 1
    sjf_rect_copy(&_this->_rect, &_from->_rect);
#line 1
    sjf_margin_copy(&_this->_margin, &_from->_margin);
#line 0 ""
    _this->_imageRenderer = 0;
#line 1 ".\..\lib\ui\imageElement.sj"
    sjf_imageRenderer_copy((sjs_imageRenderer*)(((char*)_this->_imageRenderer) + sizeof(intptr_t)), (sjs_imageRenderer*)(((char*)_from->_imageRenderer) + sizeof(intptr_t)));
}

void sjf_imageElement_destroy(sjs_imageElement* _this) {
    if (_this->_imageRenderer != 0) {
        _this->_imageRenderer->_refCount--;
        if (_this->_imageRenderer->_refCount <= 0) {
            sjf_imageRenderer_destroy((sjs_imageRenderer*)(((char*)_this->_imageRenderer) + sizeof(intptr_t)));
        }
    }
}

void sjf_imageElement_fireMouseEvent(sjs_imageElement* _parent, sjs_point* point, int32_t eventId) {
}

void sjf_imageElement_getChildren(sjs_imageElement* _parent, sjs_array_heap_element** _return) {
#line 35 ".\..\lib\ui\imageElement.sj"
    (*_return) = 0;
}

void sjf_imageElement_getRect(sjs_imageElement* _parent, sjs_rect** _return) {
    sjs_imageElement* sjt_dot1352;

#line 11 ".\..\lib\ui\imageElement.sj"
    sjt_dot1352 = _parent;
#line 11
    (*_return) = &(sjt_dot1352)->_rect;
}

void sjf_imageElement_getSize(sjs_imageElement* _parent, sjs_size* maxSize, sjs_size* _return) {
    sjs_size* sjt_dot1348;
    sjs_size* sjt_dot1349;

#line 7 ".\..\lib\ui\imageElement.sj"
    sjt_dot1348 = maxSize;
#line 8
    _return->w = (sjt_dot1348)->w;
#line 7
    sjt_dot1349 = maxSize;
#line 8
    _return->h = (sjt_dot1349)->h;
#line 0 ""
    sjf_size(_return);
}

void sjf_imageElement_getSize_heap(sjs_imageElement* _parent, sjs_size* maxSize, sjs_size_heap** _return) {
    sjs_size* sjt_dot1350;
    sjs_size* sjt_dot1351;

    (*_return) = (sjs_size_heap*)malloc(sizeof(sjs_size_heap));
    (*_return)->_refCount = 1;
#line 7 ".\..\lib\ui\imageElement.sj"
    sjt_dot1350 = maxSize;
#line 8
    (*_return)->w = (sjt_dot1350)->w;
#line 7
    sjt_dot1351 = maxSize;
#line 8
    (*_return)->h = (sjt_dot1351)->h;
#line 0 ""
    sjf_size_heap((*_return));
}

void sjf_imageElement_heap(sjs_imageElement_heap* _this) {
}

sjs_object* sjf_imageElement_heap_asInterface(sjs_imageElement_heap* _this, int typeId) {
    switch (typeId) {
        case sji_element_typeId:  {
            return (sjs_object*)sjf_imageElement_heap_as_sji_element(_this);
        }
    }

    return 0;
}

sji_element* sjf_imageElement_heap_as_sji_element(sjs_imageElement_heap* _this) {
    sji_element* _interface;
    _interface = (sji_element*)malloc(sizeof(sji_element));
    _interface->_refCount = 1;
    _interface->_parent = (sjs_object*)_this;
    _interface->_parent->_refCount++;
    _interface->destroy = (void(*)(void*))sjf_imageElement_destroy;
    _interface->asInterface = (sjs_object*(*)(sjs_object*,int))sjf_imageElement_heap_asInterface;
    _interface->getSize = (void(*)(void*,sjs_size*, sjs_size*))sjf_imageElement_getSize;
    _interface->getSize_heap = (void(*)(void*,sjs_size*, sjs_size_heap**))sjf_imageElement_getSize_heap;
    _interface->getRect = (void(*)(void*, sjs_rect**))sjf_imageElement_getRect;
    _interface->setRect = (void(*)(void*,sjs_rect*))sjf_imageElement_setRect;
    _interface->render = (void(*)(void*,sjs_scene2d*))sjf_imageElement_render;
    _interface->getChildren = (void(*)(void*, sjs_array_heap_element**))sjf_imageElement_getChildren;
    _interface->fireMouseEvent = (void(*)(void*,sjs_point*,int32_t))sjf_imageElement_fireMouseEvent;

    return _interface;
}

void sjf_imageElement_render(sjs_imageElement* _parent, sjs_scene2d* scene) {
    bool result15;
    sjs_imageElement* sjt_dot1356;
    sjs_imageElement* sjt_dot1381;
    bool sjt_ifElse33;
    bool sjt_ifElse34;
    sjs_imageRenderer_heap* sjt_isEmpty10;
    sjs_imageRenderer_heap* sjt_isEmpty11;
    bool sjt_not7;

#line 21 ".\..\lib\ui\imageElement.sj"
    sjt_dot1356 = _parent;
#line 22
    sjt_isEmpty10 = (sjt_dot1356)->_imageRenderer;
    if (sjt_isEmpty10 != 0) {
        sjt_isEmpty10->_refCount++;
    }

#line 22
    sjt_ifElse33 = (sjt_isEmpty10 == 0);
    if (sjt_ifElse33) {
        sjs_imageElement* sjt_dot1357;
        sjs_imageElement* sjt_dot1378;
        sjs_imageElement* sjt_dot1379;
        sjs_imageElement* sjt_dot1380;
        sjs_margin* sjt_functionParam156;
        sjs_rect* sjt_parent105;
        sjs_imageRenderer_heap* sjt_value8;

#line 21 ".\..\lib\ui\imageElement.sj"
        sjt_dot1357 = _parent;
#line 0 ""
        sjt_value8 = (sjs_imageRenderer_heap*)malloc(sizeof(sjs_imageRenderer_heap));
        sjt_value8->_refCount = 1;
#line 21 ".\..\lib\ui\imageElement.sj"
        sjt_dot1378 = _parent;
#line 7 ".\..\lib\ui\rect.sj"
        sjt_parent105 = &(sjt_dot1378)->_rect;
#line 21 ".\..\lib\ui\imageElement.sj"
        sjt_dot1379 = _parent;
#line 25
        sjt_functionParam156 = &(sjt_dot1379)->_margin;
#line 0 ""
        sjf_rect_subtractMargin(sjt_parent105, sjt_functionParam156, &sjt_value8->rect);
#line 21 ".\..\lib\ui\imageElement.sj"
        sjt_dot1380 = _parent;
#line 23
        sjf_image_copy(&sjt_value8->image, &(sjt_dot1380)->image);
#line 0 ""
        sjf_imageRenderer_heap(sjt_value8);
        if (sjt_dot1357->_imageRenderer != 0) {
            sjt_dot1357->_imageRenderer->_refCount--;
            if (sjt_dot1357->_imageRenderer->_refCount <= 0) {
                sjf_imageRenderer_destroy((sjs_imageRenderer*)(((char*)sjt_dot1357->_imageRenderer) + sizeof(intptr_t)));
            }
        }

#line 23 ".\..\lib\ui\imageElement.sj"
        sjt_dot1357->_imageRenderer = sjt_value8;
        if (sjt_dot1357->_imageRenderer != 0) {
            sjt_dot1357->_imageRenderer->_refCount++;
        }

        sjt_value8->_refCount--;
        if (sjt_value8->_refCount <= 0) {
            sjf_imageRenderer_destroy((sjs_imageRenderer*)(((char*)sjt_value8) + sizeof(intptr_t)));
        }
    }

#line 21
    sjt_dot1381 = _parent;
#line 31
    sjt_isEmpty11 = (sjt_dot1381)->_imageRenderer;
    if (sjt_isEmpty11 != 0) {
        sjt_isEmpty11->_refCount++;
    }

#line 31
    sjt_not7 = (sjt_isEmpty11 == 0);
#line 31
    result15 = !sjt_not7;
#line 31
    sjt_ifElse34 = result15;
    if (sjt_ifElse34) {
        sjs_imageElement* sjt_dot1382;
        sjs_scene2d* sjt_functionParam157;
        sjs_imageRenderer_heap* sjt_getValue8;
        sjs_imageRenderer* sjt_parent106;

#line 21 ".\..\lib\ui\imageElement.sj"
        sjt_dot1382 = _parent;
#line 31
        sjt_getValue8 = (sjt_dot1382)->_imageRenderer;
        if (sjt_getValue8 != 0) {
            sjt_getValue8->_refCount++;
        }

#line 31
        sjt_parent106 = (sjs_imageRenderer*)(((char*)sjt_getValue8) + sizeof(intptr_t));
#line 21
        sjt_functionParam157 = scene;
#line 0 ""
        sjf_imageRenderer_render(sjt_parent106, sjt_functionParam157);

        if (sjt_getValue8 != 0) {
            sjt_getValue8->_refCount--;
            if (sjt_getValue8->_refCount <= 0) {
                sjf_imageRenderer_destroy((sjs_imageRenderer*)(((char*)sjt_getValue8) + sizeof(intptr_t)));
            }
        }
    }

    if (sjt_isEmpty10 != 0) {
        sjt_isEmpty10->_refCount--;
        if (sjt_isEmpty10->_refCount <= 0) {
            sjf_imageRenderer_destroy((sjs_imageRenderer*)(((char*)sjt_isEmpty10) + sizeof(intptr_t)));
        }
    }
    if (sjt_isEmpty11 != 0) {
        sjt_isEmpty11->_refCount--;
        if (sjt_isEmpty11->_refCount <= 0) {
            sjf_imageRenderer_destroy((sjs_imageRenderer*)(((char*)sjt_isEmpty11) + sizeof(intptr_t)));
        }
    }
}

void sjf_imageElement_setRect(sjs_imageElement* _parent, sjs_rect* rect_) {
    bool result14;
    sjs_imageElement* sjt_dot1353;
    sjs_rect* sjt_functionParam155;
    bool sjt_ifElse32;
    bool sjt_not6;
    sjs_rect* sjt_parent104;

#line 13 ".\..\lib\ui\imageElement.sj"
    sjt_dot1353 = _parent;
#line 15 ".\..\lib\ui\rect.sj"
    sjt_parent104 = &(sjt_dot1353)->_rect;
#line 13 ".\..\lib\ui\imageElement.sj"
    sjt_functionParam155 = rect_;
#line 0 ""
    sjf_rect_isEqual(sjt_parent104, sjt_functionParam155, &sjt_not6);
#line 14 ".\..\lib\ui\imageElement.sj"
    result14 = !sjt_not6;
#line 14
    sjt_ifElse32 = result14;
    if (sjt_ifElse32) {
        sjs_imageElement* sjt_dot1354;
        sjs_imageElement* sjt_dot1355;

#line 13 ".\..\lib\ui\imageElement.sj"
        sjt_dot1354 = _parent;
#line 13
        sjf_rect_copy(&sjt_dot1354->_rect, rect_);
#line 13
        sjt_dot1355 = _parent;
        if (sjt_dot1355->_imageRenderer != 0) {
            sjt_dot1355->_imageRenderer->_refCount--;
            if (sjt_dot1355->_imageRenderer->_refCount <= 0) {
                sjf_imageRenderer_destroy((sjs_imageRenderer*)(((char*)sjt_dot1355->_imageRenderer) + sizeof(intptr_t)));
            }
        }

#line 16
        sjt_dot1355->_imageRenderer = 0;
        if (sjt_dot1355->_imageRenderer != 0) {
            sjt_dot1355->_imageRenderer->_refCount++;
        }
    }
}

void sjf_imageRenderer(sjs_imageRenderer* _this) {
#line 21 ".\..\lib\ui\imageRenderer.sj"
    _this->buffer = vertex_buffer_new("vertex:3f,tex_coord:2f");
#line 21
    float x0 = (float)_this->rect.x;
#line 21
    float x1 = (float)(_this->rect.x + _this->image.margin.l);
#line 21
    float x2 = (float)(_this->rect.x + _this->rect.w - _this->image.margin.r);
#line 21
    float x3 = (float)(_this->rect.x + _this->rect.w);
#line 21
    float y0 = (float)_this->rect.y;
#line 21
    float y1 = (float)(_this->rect.y + _this->image.margin.t);
#line 21
    float y2 = (float)(_this->rect.y + _this->rect.h - _this->image.margin.b);
#line 21
    float y3 = (float)(_this->rect.y + _this->rect.h);
#line 21
    float s0 = (float)_this->image.rect.x / (float)_this->image.texture.size.w;
#line 21
    float s1 = (float)(_this->image.rect.x + _this->image.margin.l) / (float)_this->image.texture.size.w;
#line 21
    float s2 = (float)(_this->image.rect.x + _this->image.rect.w - _this->image.margin.r) / (float)_this->image.texture.size.w;
#line 21
    float s3 = (float)(_this->image.rect.x + _this->image.rect.w) / (float)_this->image.texture.size.w;
#line 21
    float t3 = (float)_this->image.rect.y / (float)_this->image.texture.size.h;
#line 21
    float t2 = (float)(_this->image.rect.y + _this->image.margin.b) / (float)_this->image.texture.size.h;
#line 21
    float t1 = (float)(_this->image.rect.y + _this->image.rect.h - _this->image.margin.t) / (float)_this->image.texture.size.h;
#line 21
    float t0 = (float)(_this->image.rect.y + _this->image.rect.h) / (float)_this->image.texture.size.h;
#line 21
    if (_this->image.margin.t > 0) {
#line 21
        if (_this->image.margin.l > 0) {
#line 21
            GLuint index = (GLuint)_this->buffer->vertices->size;
#line 21
            GLuint indices[] = { //
#line 21
            index, index+1, index+2,
#line 21
            index, index+2, index+3 };
#line 21
            vertex3_texture2_t vertices[] = { //
#line 21
            { x0, y0, 0.0f,  s0, t0 },
#line 21
            { x0, y1, 0.0f,  s0, t1 },
#line 21
            { x1, y1, 0.0f,  s1, t1 },
#line 21
            { x1, y0, 0.0f,  s1, t0 } };
#line 21
            vertex_buffer_push_back_indices( _this->buffer, indices, 6 );
#line 21
            vertex_buffer_push_back_vertices( _this->buffer, vertices, 4 );
#line 21
        }
#line 21
        {
#line 21
            GLuint index = (GLuint)_this->buffer->vertices->size;
#line 21
            GLuint indices[] = { //
#line 21
            index, index+1, index+2,
#line 21
            index, index+2, index+3 };
#line 21
            vertex3_texture2_t vertices[] = { //
#line 21
            { x1, y0, 0.0f,  s1, t0 },
#line 21
            { x1, y1, 0.0f,  s1, t1 },
#line 21
            { x2, y1, 0.0f,  s2, t1 },
#line 21
            { x2, y0, 0.0f,  s2, t0 } };
#line 21
            vertex_buffer_push_back_indices( _this->buffer, indices, 6 );
#line 21
            vertex_buffer_push_back_vertices( _this->buffer, vertices, 4 );
#line 21
        }
#line 21
        if (_this->image.margin.r > 0) {
#line 21
            GLuint index = (GLuint)_this->buffer->vertices->size;
#line 21
            GLuint indices[] = { //
#line 21
            index, index+1, index+2,
#line 21
            index, index+2, index+3 };
#line 21
            vertex3_texture2_t vertices[] = { //
#line 21
            { x2, y0, 0.0f,  s2, t0 },
#line 21
            { x2, y1, 0.0f,  s2, t1 },
#line 21
            { x3, y1, 0.0f,  s3, t1 },
#line 21
            { x3, y0, 0.0f,  s3, t0 } };
#line 21
            vertex_buffer_push_back_indices( _this->buffer, indices, 6 );
#line 21
            vertex_buffer_push_back_vertices( _this->buffer, vertices, 4 );
#line 21
        }
#line 21
    }
#line 21
    {
#line 21
        if (_this->image.margin.l > 0) {
#line 21
            GLuint index = (GLuint)_this->buffer->vertices->size;
#line 21
            GLuint indices[] = { //
#line 21
            index, index+1, index+2,
#line 21
            index, index+2, index+3 };
#line 21
            vertex3_texture2_t vertices[] = { //
#line 21
            { x0, y1, 0.0f,  s0, t1 },
#line 21
            { x0, y2, 0.0f,  s0, t2 },
#line 21
            { x1, y2, 0.0f,  s1, t2 },
#line 21
            { x1, y1, 0.0f,  s1, t1 } };
#line 21
            vertex_buffer_push_back_indices( _this->buffer, indices, 6 );
#line 21
            vertex_buffer_push_back_vertices( _this->buffer, vertices, 4 );
#line 21
        }
#line 21
        {
#line 21
            GLuint index = (GLuint)_this->buffer->vertices->size;
#line 21
            GLuint indices[] = { //
#line 21
            index, index+1, index+2,
#line 21
            index, index+2, index+3 };
#line 21
            vertex3_texture2_t vertices[] = { //
#line 21
            { x1, y1, 0.0f,  s1, t1 },
#line 21
            { x1, y2, 0.0f,  s1, t2 },
#line 21
            { x2, y2, 0.0f,  s2, t2 },
#line 21
            { x2, y1, 0.0f,  s2, t1 } };
#line 21
            vertex_buffer_push_back_indices( _this->buffer, indices, 6 );
#line 21
            vertex_buffer_push_back_vertices( _this->buffer, vertices, 4 );
#line 21
        }
#line 21
        if (_this->image.margin.r > 0) {
#line 21
            GLuint index = (GLuint)_this->buffer->vertices->size;
#line 21
            GLuint indices[] = { //
#line 21
            index, index+1, index+2,
#line 21
            index, index+2, index+3 };
#line 21
            vertex3_texture2_t vertices[] = { //
#line 21
            { x2, y1, 0.0f,  s2, t1 },
#line 21
            { x2, y2, 0.0f,  s2, t2 },
#line 21
            { x3, y2, 0.0f,  s3, t2 },
#line 21
            { x3, y1, 0.0f,  s3, t1 } };
#line 21
            vertex_buffer_push_back_indices( _this->buffer, indices, 6 );
#line 21
            vertex_buffer_push_back_vertices( _this->buffer, vertices, 4 );
#line 21
        }
#line 21
    }
#line 21
    if (_this->image.margin.b > 0) {
#line 21
        if (_this->image.margin.l > 0) {
#line 21
            GLuint index = (GLuint)_this->buffer->vertices->size;
#line 21
            GLuint indices[] = { //
#line 21
            index, index+1, index+2,
#line 21
            index, index+2, index+3 };
#line 21
            vertex3_texture2_t vertices[] = { //
#line 21
            { x0, y2, 0.0f,  s0, t2 },
#line 21
            { x0, y3, 0.0f,  s0, t3 },
#line 21
            { x1, y3, 0.0f,  s1, t3 },
#line 21
            { x1, y2, 0.0f,  s1, t2 } };
#line 21
            vertex_buffer_push_back_indices( _this->buffer, indices, 6 );
#line 21
            vertex_buffer_push_back_vertices( _this->buffer, vertices, 4 );
#line 21
        }
#line 21
        {
#line 21
            GLuint index = (GLuint)_this->buffer->vertices->size;
#line 21
            GLuint indices[] = { //
#line 21
            index, index+1, index+2,
#line 21
            index, index+2, index+3 };
#line 21
            vertex3_texture2_t vertices[] = { //
#line 21
            { x1, y2, 0.0f,  s1, t2 },
#line 21
            { x1, y3, 0.0f,  s1, t3 },
#line 21
            { x2, y3, 0.0f,  s2, t3 },
#line 21
            { x2, y2, 0.0f,  s2, t2 } };
#line 21
            vertex_buffer_push_back_indices( _this->buffer, indices, 6 );
#line 21
            vertex_buffer_push_back_vertices( _this->buffer, vertices, 4 );
#line 21
        }
#line 21
        if (_this->image.margin.r > 0) {
#line 21
            GLuint index = (GLuint)_this->buffer->vertices->size;
#line 21
            GLuint indices[] = { //
#line 21
            index, index+1, index+2,
#line 21
            index, index+2, index+3 };
#line 21
            vertex3_texture2_t vertices[] = { //
#line 21
            { x2, y2, 0.0f,  s2, t2 },
#line 21
            { x2, y3, 0.0f,  s2, t3 },
#line 21
            { x3, y3, 0.0f,  s3, t3 },
#line 21
            { x3, y2, 0.0f,  s3, t2 } };
#line 21
            vertex_buffer_push_back_indices( _this->buffer, indices, 6 );
#line 21
            vertex_buffer_push_back_vertices( _this->buffer, vertices, 4 );
#line 21
        }
#line 21
    }
}

void sjf_imageRenderer_copy(sjs_imageRenderer* _this, sjs_imageRenderer* _from) {
#line 1 ".\..\lib\ui\imageRenderer.sj"
    sjf_rect_copy(&_this->rect, &_from->rect);
#line 1
    sjf_image_copy(&_this->image, &_from->image);
#line 178
    _this->buffer = _from->buffer;
#line 178
    _retain(_this->buffer);
}

void sjf_imageRenderer_destroy(sjs_imageRenderer* _this) {
#line 183 ".\..\lib\ui\imageRenderer.sj"
    if (_release(_this->buffer)) {
#line 183
        vertex_buffer_delete(_this->buffer);
#line 183
    }
}

void sjf_imageRenderer_heap(sjs_imageRenderer_heap* _this) {
#line 21 ".\..\lib\ui\imageRenderer.sj"
    _this->buffer = vertex_buffer_new("vertex:3f,tex_coord:2f");
#line 21
    float x0 = (float)_this->rect.x;
#line 21
    float x1 = (float)(_this->rect.x + _this->image.margin.l);
#line 21
    float x2 = (float)(_this->rect.x + _this->rect.w - _this->image.margin.r);
#line 21
    float x3 = (float)(_this->rect.x + _this->rect.w);
#line 21
    float y0 = (float)_this->rect.y;
#line 21
    float y1 = (float)(_this->rect.y + _this->image.margin.t);
#line 21
    float y2 = (float)(_this->rect.y + _this->rect.h - _this->image.margin.b);
#line 21
    float y3 = (float)(_this->rect.y + _this->rect.h);
#line 21
    float s0 = (float)_this->image.rect.x / (float)_this->image.texture.size.w;
#line 21
    float s1 = (float)(_this->image.rect.x + _this->image.margin.l) / (float)_this->image.texture.size.w;
#line 21
    float s2 = (float)(_this->image.rect.x + _this->image.rect.w - _this->image.margin.r) / (float)_this->image.texture.size.w;
#line 21
    float s3 = (float)(_this->image.rect.x + _this->image.rect.w) / (float)_this->image.texture.size.w;
#line 21
    float t3 = (float)_this->image.rect.y / (float)_this->image.texture.size.h;
#line 21
    float t2 = (float)(_this->image.rect.y + _this->image.margin.b) / (float)_this->image.texture.size.h;
#line 21
    float t1 = (float)(_this->image.rect.y + _this->image.rect.h - _this->image.margin.t) / (float)_this->image.texture.size.h;
#line 21
    float t0 = (float)(_this->image.rect.y + _this->image.rect.h) / (float)_this->image.texture.size.h;
#line 21
    if (_this->image.margin.t > 0) {
#line 21
        if (_this->image.margin.l > 0) {
#line 21
            GLuint index = (GLuint)_this->buffer->vertices->size;
#line 21
            GLuint indices[] = { //
#line 21
            index, index+1, index+2,
#line 21
            index, index+2, index+3 };
#line 21
            vertex3_texture2_t vertices[] = { //
#line 21
            { x0, y0, 0.0f,  s0, t0 },
#line 21
            { x0, y1, 0.0f,  s0, t1 },
#line 21
            { x1, y1, 0.0f,  s1, t1 },
#line 21
            { x1, y0, 0.0f,  s1, t0 } };
#line 21
            vertex_buffer_push_back_indices( _this->buffer, indices, 6 );
#line 21
            vertex_buffer_push_back_vertices( _this->buffer, vertices, 4 );
#line 21
        }
#line 21
        {
#line 21
            GLuint index = (GLuint)_this->buffer->vertices->size;
#line 21
            GLuint indices[] = { //
#line 21
            index, index+1, index+2,
#line 21
            index, index+2, index+3 };
#line 21
            vertex3_texture2_t vertices[] = { //
#line 21
            { x1, y0, 0.0f,  s1, t0 },
#line 21
            { x1, y1, 0.0f,  s1, t1 },
#line 21
            { x2, y1, 0.0f,  s2, t1 },
#line 21
            { x2, y0, 0.0f,  s2, t0 } };
#line 21
            vertex_buffer_push_back_indices( _this->buffer, indices, 6 );
#line 21
            vertex_buffer_push_back_vertices( _this->buffer, vertices, 4 );
#line 21
        }
#line 21
        if (_this->image.margin.r > 0) {
#line 21
            GLuint index = (GLuint)_this->buffer->vertices->size;
#line 21
            GLuint indices[] = { //
#line 21
            index, index+1, index+2,
#line 21
            index, index+2, index+3 };
#line 21
            vertex3_texture2_t vertices[] = { //
#line 21
            { x2, y0, 0.0f,  s2, t0 },
#line 21
            { x2, y1, 0.0f,  s2, t1 },
#line 21
            { x3, y1, 0.0f,  s3, t1 },
#line 21
            { x3, y0, 0.0f,  s3, t0 } };
#line 21
            vertex_buffer_push_back_indices( _this->buffer, indices, 6 );
#line 21
            vertex_buffer_push_back_vertices( _this->buffer, vertices, 4 );
#line 21
        }
#line 21
    }
#line 21
    {
#line 21
        if (_this->image.margin.l > 0) {
#line 21
            GLuint index = (GLuint)_this->buffer->vertices->size;
#line 21
            GLuint indices[] = { //
#line 21
            index, index+1, index+2,
#line 21
            index, index+2, index+3 };
#line 21
            vertex3_texture2_t vertices[] = { //
#line 21
            { x0, y1, 0.0f,  s0, t1 },
#line 21
            { x0, y2, 0.0f,  s0, t2 },
#line 21
            { x1, y2, 0.0f,  s1, t2 },
#line 21
            { x1, y1, 0.0f,  s1, t1 } };
#line 21
            vertex_buffer_push_back_indices( _this->buffer, indices, 6 );
#line 21
            vertex_buffer_push_back_vertices( _this->buffer, vertices, 4 );
#line 21
        }
#line 21
        {
#line 21
            GLuint index = (GLuint)_this->buffer->vertices->size;
#line 21
            GLuint indices[] = { //
#line 21
            index, index+1, index+2,
#line 21
            index, index+2, index+3 };
#line 21
            vertex3_texture2_t vertices[] = { //
#line 21
            { x1, y1, 0.0f,  s1, t1 },
#line 21
            { x1, y2, 0.0f,  s1, t2 },
#line 21
            { x2, y2, 0.0f,  s2, t2 },
#line 21
            { x2, y1, 0.0f,  s2, t1 } };
#line 21
            vertex_buffer_push_back_indices( _this->buffer, indices, 6 );
#line 21
            vertex_buffer_push_back_vertices( _this->buffer, vertices, 4 );
#line 21
        }
#line 21
        if (_this->image.margin.r > 0) {
#line 21
            GLuint index = (GLuint)_this->buffer->vertices->size;
#line 21
            GLuint indices[] = { //
#line 21
            index, index+1, index+2,
#line 21
            index, index+2, index+3 };
#line 21
            vertex3_texture2_t vertices[] = { //
#line 21
            { x2, y1, 0.0f,  s2, t1 },
#line 21
            { x2, y2, 0.0f,  s2, t2 },
#line 21
            { x3, y2, 0.0f,  s3, t2 },
#line 21
            { x3, y1, 0.0f,  s3, t1 } };
#line 21
            vertex_buffer_push_back_indices( _this->buffer, indices, 6 );
#line 21
            vertex_buffer_push_back_vertices( _this->buffer, vertices, 4 );
#line 21
        }
#line 21
    }
#line 21
    if (_this->image.margin.b > 0) {
#line 21
        if (_this->image.margin.l > 0) {
#line 21
            GLuint index = (GLuint)_this->buffer->vertices->size;
#line 21
            GLuint indices[] = { //
#line 21
            index, index+1, index+2,
#line 21
            index, index+2, index+3 };
#line 21
            vertex3_texture2_t vertices[] = { //
#line 21
            { x0, y2, 0.0f,  s0, t2 },
#line 21
            { x0, y3, 0.0f,  s0, t3 },
#line 21
            { x1, y3, 0.0f,  s1, t3 },
#line 21
            { x1, y2, 0.0f,  s1, t2 } };
#line 21
            vertex_buffer_push_back_indices( _this->buffer, indices, 6 );
#line 21
            vertex_buffer_push_back_vertices( _this->buffer, vertices, 4 );
#line 21
        }
#line 21
        {
#line 21
            GLuint index = (GLuint)_this->buffer->vertices->size;
#line 21
            GLuint indices[] = { //
#line 21
            index, index+1, index+2,
#line 21
            index, index+2, index+3 };
#line 21
            vertex3_texture2_t vertices[] = { //
#line 21
            { x1, y2, 0.0f,  s1, t2 },
#line 21
            { x1, y3, 0.0f,  s1, t3 },
#line 21
            { x2, y3, 0.0f,  s2, t3 },
#line 21
            { x2, y2, 0.0f,  s2, t2 } };
#line 21
            vertex_buffer_push_back_indices( _this->buffer, indices, 6 );
#line 21
            vertex_buffer_push_back_vertices( _this->buffer, vertices, 4 );
#line 21
        }
#line 21
        if (_this->image.margin.r > 0) {
#line 21
            GLuint index = (GLuint)_this->buffer->vertices->size;
#line 21
            GLuint indices[] = { //
#line 21
            index, index+1, index+2,
#line 21
            index, index+2, index+3 };
#line 21
            vertex3_texture2_t vertices[] = { //
#line 21
            { x2, y2, 0.0f,  s2, t2 },
#line 21
            { x2, y3, 0.0f,  s2, t3 },
#line 21
            { x3, y3, 0.0f,  s3, t3 },
#line 21
            { x3, y2, 0.0f,  s3, t2 } };
#line 21
            vertex_buffer_push_back_indices( _this->buffer, indices, 6 );
#line 21
            vertex_buffer_push_back_vertices( _this->buffer, vertices, 4 );
#line 21
        }
#line 21
    }
}

void sjf_imageRenderer_render(sjs_imageRenderer* _parent, sjs_scene2d* scene) {
#line 9 ".\..\lib\ui\imageRenderer.sj"
    glBindTexture(GL_TEXTURE_2D, _parent->image.texture.id);
#line 9
    glUseProgram(sjv_imageShader.id);
#line 9
    glUniform1i(glGetUniformLocation(sjv_imageShader.id, "texture" ), 0 );
#line 9
    glUniformMatrix4fv(glGetUniformLocation(sjv_imageShader.id, "model" ), 1, 0, (GLfloat*)&scene->model);
#line 9
    glUniformMatrix4fv(glGetUniformLocation(sjv_imageShader.id, "view" ), 1, 0, (GLfloat*)&scene->view);
#line 9
    glUniformMatrix4fv(glGetUniformLocation(sjv_imageShader.id, "projection" ), 1, 0, (GLfloat*)&scene->projection);
#line 9
    vertex_buffer_render(_parent->buffer, GL_TRIANGLES);
}

void sjf_image_copy(sjs_image* _this, sjs_image* _from) {
#line 1 ".\..\lib\ui\image.sj"
    sjf_texture_copy(&_this->texture, &_from->texture);
#line 1
    sjf_rect_copy(&_this->rect, &_from->rect);
#line 1
    sjf_margin_copy(&_this->margin, &_from->margin);
}

void sjf_image_destroy(sjs_image* _this) {
}

void sjf_image_heap(sjs_image_heap* _this) {
    bool sjt_and15;
    bool sjt_and16;
    int32_t sjt_compare59;
    int32_t sjt_compare60;
    int32_t sjt_compare61;
    int32_t sjt_compare62;
    sjs_rect* sjt_dot1344;
    sjs_rect* sjt_dot1345;
    bool sjt_ifElse31;

#line 1 ".\..\lib\ui\rect.sj"
    sjt_dot1344 = &_this->rect;
#line 6 ".\..\lib\ui\image.sj"
    sjt_compare59 = (sjt_dot1344)->w;
#line 6
    sjt_compare60 = 0;
#line 6
    sjt_and15 = sjt_compare59 == sjt_compare60;
#line 1 ".\..\lib\ui\rect.sj"
    sjt_dot1345 = &_this->rect;
#line 6 ".\..\lib\ui\image.sj"
    sjt_compare61 = (sjt_dot1345)->h;
#line 6
    sjt_compare62 = 0;
#line 6
    sjt_and16 = sjt_compare61 == sjt_compare62;
#line 6
    sjt_ifElse31 = sjt_and15 && sjt_and16;
    if (sjt_ifElse31) {
        sjs_size* sjt_dot1346;
        sjs_size* sjt_dot1347;
        sjs_texture* sjt_parent103;
        sjs_size sjv_size;

#line 15 ".\..\lib\ui\texture.sj"
        sjt_parent103 = &_this->texture;
#line 0 ""
        sjf_texture_getSize(sjt_parent103, &sjv_size);
#line 8 ".\..\lib\ui\image.sj"
        _this->rect.x = 0;
#line 8
        _this->rect.y = 0;
#line 1 ".\..\lib\ui\size.sj"
        sjt_dot1346 = &sjv_size;
#line 8 ".\..\lib\ui\image.sj"
        _this->rect.w = (sjt_dot1346)->w;
#line 1 ".\..\lib\ui\size.sj"
        sjt_dot1347 = &sjv_size;
#line 8 ".\..\lib\ui\image.sj"
        _this->rect.h = (sjt_dot1347)->h;
#line 0 ""
        sjf_rect(&_this->rect);

        sjf_size_destroy(&sjv_size);
    }
}

void sjf_intersectTriangle_heap(sjs_vec3* orig, sjs_vec3* dir, sjs_vec3* v0, sjs_vec3* v1, sjs_vec3* v2, sjs_vec3_heap** _return) {
    float sjt_compare41;
    float sjt_compare42;
    float sjt_compare43;
    float sjt_compare44;
    sjs_vec3* sjt_functionParam91;
    sjs_vec3* sjt_functionParam92;
    sjs_vec3* sjt_functionParam93;
    sjs_vec3* sjt_functionParam94;
    bool sjt_ifElse17;
    bool sjt_ifElse18;
    sjs_vec3* sjt_parent69;
    sjs_vec3* sjt_parent70;
    sjs_vec3* sjt_parent71;
    sjs_vec3* sjt_parent72;
    float sjv_det;
    sjs_vec3 sjv_edge1;
    sjs_vec3 sjv_edge2;
    sjs_vec3 sjv_pvec;
    sjs_vec3 sjv_tvec;

#line 114 ".\..\lib\ui\vertexBuffer.sj"
    sjt_parent69 = v1;
#line 114
    sjt_functionParam91 = v0;
#line 0 ""
    sjf_vec3_subtract(sjt_parent69, sjt_functionParam91, &sjv_edge1);
#line 114 ".\..\lib\ui\vertexBuffer.sj"
    sjt_parent70 = v2;
#line 114
    sjt_functionParam92 = v0;
#line 0 ""
    sjf_vec3_subtract(sjt_parent70, sjt_functionParam92, &sjv_edge2);
#line 114 ".\..\lib\ui\vertexBuffer.sj"
    sjt_parent71 = dir;
#line 118
    sjt_functionParam93 = &sjv_edge2;
#line 0 ""
    sjf_vec3_cross(sjt_parent71, sjt_functionParam93, &sjv_pvec);
#line 46 ".\..\lib\ui\vec3.sj"
    sjt_parent72 = &sjv_edge1;
#line 119 ".\..\lib\ui\vertexBuffer.sj"
    sjt_functionParam94 = &sjv_pvec;
#line 0 ""
    sjf_vec3_dot(sjt_parent72, sjt_functionParam94, &sjv_det);
#line 120 ".\..\lib\ui\vertexBuffer.sj"
    sjt_compare41 = sjv_det;
#line 120
    sjt_compare42 = 0.0f;
#line 120
    sjt_ifElse17 = sjt_compare41 > sjt_compare42;
    if (sjt_ifElse17) {
        sjs_vec3* sjt_functionParam95;
        sjs_vec3* sjt_parent73;

#line 114 ".\..\lib\ui\vertexBuffer.sj"
        sjt_parent73 = orig;
#line 114
        sjt_functionParam95 = v0;
#line 0 ""
        sjf_vec3_subtract(sjt_parent73, sjt_functionParam95, &sjv_tvec);
    } else {
        sjs_vec3* sjt_functionParam96;
        float sjt_math2373;
        float sjt_math2374;
        sjs_vec3* sjt_parent74;

#line 123 ".\..\lib\ui\vertexBuffer.sj"
        sjt_math2373 = 0.0f;
#line 123
        sjt_math2374 = sjv_det;
#line 123
        sjv_det = sjt_math2373 - sjt_math2374;
#line 114
        sjt_parent74 = v0;
#line 114
        sjt_functionParam96 = orig;
#line 0 ""
        sjf_vec3_subtract(sjt_parent74, sjt_functionParam96, &sjv_tvec);
    }

#line 127
    sjt_compare43 = sjv_det;
#line 127
    sjt_compare44 = 0.0001f;
#line 127
    sjt_ifElse18 = sjt_compare43 < sjt_compare44;
    if (sjt_ifElse18) {
#line 128 ".\..\lib\ui\vertexBuffer.sj"
        (*_return) = 0;
        if ((*_return) != 0) {
            (*_return)->_refCount++;
        }
    } else {
        float sjt_compare45;
        float sjt_compare46;
        float sjt_compare47;
        float sjt_compare48;
        sjs_vec3* sjt_functionParam97;
        bool sjt_ifElse19;
        bool sjt_or1;
        bool sjt_or2;
        sjs_vec3* sjt_parent75;
        float sjv_u;

#line 46 ".\..\lib\ui\vec3.sj"
        sjt_parent75 = &sjv_tvec;
#line 130 ".\..\lib\ui\vertexBuffer.sj"
        sjt_functionParam97 = &sjv_pvec;
#line 0 ""
        sjf_vec3_dot(sjt_parent75, sjt_functionParam97, &sjv_u);
#line 131 ".\..\lib\ui\vertexBuffer.sj"
        sjt_compare45 = sjv_u;
#line 131
        sjt_compare46 = 0.0f;
#line 131
        sjt_or1 = sjt_compare45 < sjt_compare46;
#line 131
        sjt_compare47 = sjv_u;
#line 131
        sjt_compare48 = sjv_det;
#line 131
        sjt_or2 = sjt_compare47 > sjt_compare48;
#line 131
        sjt_ifElse19 = sjt_or1 || sjt_or2;
        if (sjt_ifElse19) {
#line 132 ".\..\lib\ui\vertexBuffer.sj"
            (*_return) = 0;
            if ((*_return) != 0) {
                (*_return)->_refCount++;
            }
        } else {
            float sjt_compare49;
            float sjt_compare50;
            float sjt_compare51;
            float sjt_compare52;
            sjs_vec3* sjt_functionParam98;
            sjs_vec3* sjt_functionParam99;
            bool sjt_ifElse20;
            float sjt_math2375;
            float sjt_math2376;
            bool sjt_or3;
            bool sjt_or4;
            sjs_vec3* sjt_parent76;
            sjs_vec3* sjt_parent77;
            sjs_vec3 sjv_qvec;
            float sjv_v;

#line 38 ".\..\lib\ui\vec3.sj"
            sjt_parent76 = &sjv_tvec;
#line 134 ".\..\lib\ui\vertexBuffer.sj"
            sjt_functionParam98 = &sjv_edge1;
#line 0 ""
            sjf_vec3_cross(sjt_parent76, sjt_functionParam98, &sjv_qvec);
#line 114 ".\..\lib\ui\vertexBuffer.sj"
            sjt_parent77 = dir;
#line 135
            sjt_functionParam99 = &sjv_qvec;
#line 0 ""
            sjf_vec3_dot(sjt_parent77, sjt_functionParam99, &sjv_v);
#line 136 ".\..\lib\ui\vertexBuffer.sj"
            sjt_compare49 = sjv_v;
#line 136
            sjt_compare50 = 0.0f;
#line 136
            sjt_or3 = sjt_compare49 < sjt_compare50;
#line 136
            sjt_math2375 = sjv_u;
#line 136
            sjt_math2376 = sjv_v;
#line 136
            sjt_compare51 = sjt_math2375 + sjt_math2376;
#line 136
            sjt_compare52 = sjv_det;
#line 136
            sjt_or4 = sjt_compare51 > sjt_compare52;
#line 136
            sjt_ifElse20 = sjt_or3 || sjt_or4;
            if (sjt_ifElse20) {
#line 137 ".\..\lib\ui\vertexBuffer.sj"
                (*_return) = 0;
                if ((*_return) != 0) {
                    (*_return)->_refCount++;
                }
            } else {
                sjs_vec3* sjt_functionParam100;
                float sjt_math2377;
                float sjt_math2378;
                float sjt_math2379;
                float sjt_math2380;
                float sjt_math2381;
                float sjt_math2382;
                float sjt_math2383;
                float sjt_math2384;
                sjs_vec3* sjt_parent78;
                sjs_vec3_heap* sjt_value2;
                float sjv_fInvDet;
                float sjv_t;

#line 46 ".\..\lib\ui\vec3.sj"
                sjt_parent78 = &sjv_edge2;
#line 140 ".\..\lib\ui\vertexBuffer.sj"
                sjt_functionParam100 = &sjv_qvec;
#line 0 ""
                sjf_vec3_dot(sjt_parent78, sjt_functionParam100, &sjv_t);
#line 141 ".\..\lib\ui\vertexBuffer.sj"
                sjt_math2377 = 1.0f;
#line 141
                sjt_math2378 = sjv_det;
#line 141
                sjv_fInvDet = sjt_math2377 / sjt_math2378;
#line 0 ""
                sjt_value2 = (sjs_vec3_heap*)malloc(sizeof(sjs_vec3_heap));
                sjt_value2->_refCount = 1;
#line 142 ".\..\lib\ui\vertexBuffer.sj"
                sjt_math2379 = sjv_u;
#line 142
                sjt_math2380 = sjv_fInvDet;
#line 142
                sjt_value2->x = sjt_math2379 * sjt_math2380;
#line 142
                sjt_math2381 = sjv_v;
#line 142
                sjt_math2382 = sjv_fInvDet;
#line 142
                sjt_value2->y = sjt_math2381 * sjt_math2382;
#line 142
                sjt_math2383 = sjv_t;
#line 142
                sjt_math2384 = sjv_fInvDet;
#line 142
                sjt_value2->z = sjt_math2383 * sjt_math2384;
#line 0 ""
                sjf_vec3_heap(sjt_value2);
#line 142 ".\..\lib\ui\vertexBuffer.sj"
                (*_return) = sjt_value2;
                if ((*_return) != 0) {
                    (*_return)->_refCount++;
                }

                sjt_value2->_refCount--;
                if (sjt_value2->_refCount <= 0) {
                    sjf_vec3_destroy((sjs_vec3*)(((char*)sjt_value2) + sizeof(intptr_t)));
                }
            }

            sjf_vec3_destroy(&sjv_qvec);
        }
    }

    sjf_vec3_destroy(&sjv_edge1);
    sjf_vec3_destroy(&sjv_edge2);
    sjf_vec3_destroy(&sjv_pvec);
    sjf_vec3_destroy(&sjv_tvec);
}

void sjf_list_heap_animation(sjs_list_heap_animation* _this) {
}

void sjf_list_heap_animation_add(sjs_list_heap_animation* _parent, sji_anon5_animation* item, int32_t* _return) {
    int32_t sjt_compare1;
    int32_t sjt_compare2;
    sjs_list_heap_animation* sjt_dot18;
    sjs_array_heap_animation* sjt_dot19;
    sjs_list_heap_animation* sjt_dot20;
    sjs_list_heap_animation* sjt_dot24;
    sjs_list_heap_animation* sjt_dot25;
    sjs_list_heap_animation* sjt_dot26;
    sjs_list_heap_animation* sjt_dot27;
    int32_t sjt_functionParam10;
    sji_anon5_animation* sjt_functionParam11;
    bool sjt_ifElse1;
    int32_t sjt_math5;
    int32_t sjt_math6;
    sjs_array_heap_animation* sjt_parent9;

#line 5 ".\..\lib\common\list.sj"
    sjt_dot18 = _parent;
#line 6
    sjt_compare1 = (sjt_dot18)->count;
#line 5
    sjt_dot20 = _parent;
#line 1 ".\..\lib\common\array.sj"
    sjt_dot19 = &(sjt_dot20)->data;
#line 6 ".\..\lib\common\list.sj"
    sjt_compare2 = (sjt_dot19)->size;
#line 6
    sjt_ifElse1 = sjt_compare1 >= sjt_compare2;
    if (sjt_ifElse1) {
        sjs_array_heap_animation* sjt_dot22;
        sjs_list_heap_animation* sjt_dot23;
        int32_t sjt_functionParam7;
        int32_t sjt_functionParam8;
        int32_t sjt_functionParam9;
        int32_t sjt_math3;
        int32_t sjt_math4;

#line 7 ".\..\lib\common\list.sj"
        sjt_functionParam8 = 10;
#line 5
        sjt_dot23 = _parent;
#line 1 ".\..\lib\common\array.sj"
        sjt_dot22 = &(sjt_dot23)->data;
#line 7 ".\..\lib\common\list.sj"
        sjt_math3 = (sjt_dot22)->size;
#line 7
        sjt_math4 = 2;
#line 7
        sjt_functionParam9 = sjt_math3 * sjt_math4;
#line 0 ""
        sjf_i32_max(sjt_functionParam8, sjt_functionParam9, &sjt_functionParam7);
        sjf_list_heap_animation_setSize(_parent, sjt_functionParam7);
    }

#line 5
    sjt_dot24 = _parent;
#line 16 ".\..\lib\common\array.sj"
    sjt_parent9 = &(sjt_dot24)->data;
#line 5 ".\..\lib\common\list.sj"
    sjt_dot25 = _parent;
#line 11
    sjt_functionParam10 = (sjt_dot25)->count;
#line 5
    sjt_functionParam11 = item;
#line 0 ""
    sjt_functionParam11->_refCount++;
    sjf_array_heap_animation_initAt(sjt_parent9, sjt_functionParam10, sjt_functionParam11);
#line 5 ".\..\lib\common\list.sj"
    sjt_dot26 = _parent;
#line 5
    sjt_dot27 = _parent;
#line 12
    sjt_math5 = (sjt_dot27)->count;
#line 12
    sjt_math6 = 1;
#line 12
    sjt_dot26->count = sjt_math5 + sjt_math6;
#line 12
    (*_return) = sjt_dot26->count;

    sjt_functionParam11->_refCount--;
    if (sjt_functionParam11->_refCount <= 0) {
        sji_anon5_animation_destroy(sjt_functionParam11);
    }
}

void sjf_list_heap_animation_copy(sjs_list_heap_animation* _this, sjs_list_heap_animation* _from) {
#line 1 ".\..\lib\common\list.sj"
    _this->count = _from->count;
#line 1
    sjf_array_heap_animation_copy(&_this->data, &_from->data);
}

void sjf_list_heap_animation_destroy(sjs_list_heap_animation* _this) {
}

void sjf_list_heap_animation_getAt_heap(sjs_list_heap_animation* _parent, int32_t index, sji_anon5_animation** _return) {
    sjs_list_heap_animation* sjt_dot1435;
    int32_t sjt_functionParam417;
    sjs_array_heap_animation* sjt_parent235;

#line 19 ".\..\lib\common\list.sj"
    sjt_dot1435 = _parent;
#line 6 ".\..\lib\common\array.sj"
    sjt_parent235 = &(sjt_dot1435)->data;
#line 19 ".\..\lib\common\list.sj"
    sjt_functionParam417 = index;
#line 0 ""
    sjf_array_heap_animation_getAt_heap(sjt_parent235, sjt_functionParam417, _return);
}

void sjf_list_heap_animation_heap(sjs_list_heap_animation_heap* _this) {
}

void sjf_list_heap_animation_removeAt(sjs_list_heap_animation* _parent, int32_t index) {
#line 28 ".\..\lib\common\list.sj"
    if (index < 0 || index >= _parent->count) {
#line 28
        halt("removeAt: out of bounds %d:%d\n", index, _parent->count);
#line 28
    }
#line 28
    sji_anon5_animation** p = (sji_anon5_animation**)_parent->data.data;
#line 28
    if (index != _parent->count - 1) {
#line 28
        memcpy(p + index, p + index + 1, _parent->count - index - 1);
#line 28
    }
#line 28
    _parent->count--;
}

void sjf_list_heap_animation_setSize(sjs_list_heap_animation* _parent, int32_t size) {
    sjs_list_heap_animation* sjt_dot21;
    int32_t sjt_functionParam6;
    sjs_array_heap_animation* sjt_parent8;

#line 15 ".\..\lib\common\list.sj"
    sjt_dot21 = _parent;
#line 58 ".\..\lib\common\array.sj"
    sjt_parent8 = &(sjt_dot21)->data;
#line 15 ".\..\lib\common\list.sj"
    sjt_functionParam6 = size;
#line 0 ""
    sjf_array_heap_animation_grow(sjt_parent8, sjt_functionParam6);
}

void sjf_list_local_cb_void(sjs_list_local_cb_void* _this) {
}

void sjf_list_local_cb_void_copy(sjs_list_local_cb_void* _this, sjs_list_local_cb_void* _from) {
#line 1 ".\..\lib\common\list.sj"
    _this->count = _from->count;
#line 1
    sjf_array_local_cb_void_copy(&_this->data, &_from->data);
}

void sjf_list_local_cb_void_destroy(sjs_list_local_cb_void* _this) {
}

void sjf_list_local_cb_void_getAt(sjs_list_local_cb_void* _parent, int32_t index, cb_void* _return) {
    sjs_list_local_cb_void* sjt_dot61;
    int32_t sjt_functionParam17;
    sjs_array_local_cb_void* sjt_parent13;

#line 19 ".\..\lib\common\list.sj"
    sjt_dot61 = _parent;
#line 6 ".\..\lib\common\array.sj"
    sjt_parent13 = &(sjt_dot61)->data;
#line 19 ".\..\lib\common\list.sj"
    sjt_functionParam17 = index;
#line 0 ""
    sjf_array_local_cb_void_getAt(sjt_parent13, sjt_functionParam17, _return);
}

void sjf_list_local_cb_void_heap(sjs_list_local_cb_void_heap* _this) {
}

void sjf_mainLoop(void) {
    int32_t result47;
    int32_t result48;
    int32_t sjt_compare75;
    int32_t sjt_compare76;
    sjs_size* sjt_dot1438;
    sjs_size* sjt_dot1439;
    int32_t sjt_functionParam420;
    sjs_size* sjt_functionParam421;
    bool sjt_ifElse44;
    sjs_rect* sjt_interfaceParam16;
    sjs_scene2d* sjt_interfaceParam17;
    int32_t sjt_negate37;
    int32_t sjt_negate38;
    sjs_anon5* sjt_parent239;
    sjs_windowRenderer* sjt_parent240;
    sjs_scene2d* sjt_parent241;
    sjs_scene2d* sjt_parent242;
    sji_element* sjt_parent243;
    sji_element* sjt_parent244;
    sjs_windowRenderer* sjt_parent245;
    int32_t sjv_mouseEvent;
    sjs_rect sjv_rect;
    sjs_size sjv_size;
    int32_t sjv_ticks;
    int32_t sjv_x;
    int32_t sjv_y;

#line 6 ".\..\lib\ui\loop.sj"
    sjv_ticks = 0;
#line 7
    sjv_ticks = SDL_GetTicks();
#line 31 ".\..\lib\ui\animation.sj"
    sjt_parent239 = &sjv_animator;
#line 10 ".\..\lib\ui\loop.sj"
    sjt_functionParam420 = sjv_ticks;
#line 0 ""
    sjf_anon5_nextFrame(sjt_parent239, sjt_functionParam420);
#line 7 ".\..\lib\ui\windowRenderer.sj"
    sjt_parent240 = &sjv_rootWindowRenderer;
#line 0 ""
    sjf_windowRenderer_getSize(sjt_parent240, &sjv_size);
#line 27 ".\..\lib\ui\scene2d.sj"
    sjt_parent241 = &sjv_rootScene;
#line 13 ".\..\lib\ui\loop.sj"
    sjt_functionParam421 = &sjv_size;
#line 0 ""
    sjf_scene2d_setSize(sjt_parent241, sjt_functionParam421);
#line 7 ".\..\lib\ui\scene2d.sj"
    sjt_parent242 = &sjv_rootScene;
#line 0 ""
    sjf_scene2d_clear(sjt_parent242);
#line 15 ".\..\lib\ui\loop.sj"
    sjv_rect.x = 0;
#line 15
    sjv_rect.y = 0;
#line 1 ".\..\lib\ui\size.sj"
    sjt_dot1438 = &sjv_size;
#line 15 ".\..\lib\ui\loop.sj"
    sjv_rect.w = (sjt_dot1438)->w;
#line 1 ".\..\lib\ui\size.sj"
    sjt_dot1439 = &sjv_size;
#line 15 ".\..\lib\ui\loop.sj"
    sjv_rect.h = (sjt_dot1439)->h;
#line 0 ""
    sjf_rect(&sjv_rect);
#line 4 ".\..\lib\ui\element.sj"
    sjt_parent243 = sjv_root;
#line 4
    sjt_interfaceParam16 = &sjv_rect;
#line 16 ".\..\lib\ui\loop.sj"
    sjt_parent243->setRect((void*)(((char*)sjt_parent243->_parent) + sizeof(intptr_t)), sjt_interfaceParam16);
#line 5 ".\..\lib\ui\element.sj"
    sjt_parent244 = sjv_root;
#line 5
    sjt_interfaceParam17 = &sjv_rootScene;
#line 17 ".\..\lib\ui\loop.sj"
    sjt_parent244->render((void*)(((char*)sjt_parent244->_parent) + sizeof(intptr_t)), sjt_interfaceParam17);
#line 16 ".\..\lib\ui\windowRenderer.sj"
    sjt_parent245 = &sjv_rootWindowRenderer;
#line 0 ""
    sjf_windowRenderer_present(sjt_parent245);
#line 20 ".\..\lib\ui\loop.sj"
    sjt_negate37 = 1;
#line 20
    result47 = -sjt_negate37;
#line 20
    sjv_mouseEvent = result47;
#line 21
    sjv_x = 0;
#line 22
    sjv_y = 0;
#line 23
    SDL_Event e;
#line 23
    while(SDL_PollEvent( &e ) != 0) {
#line 23
        switch (e.type) {
#line 23
            case SDL_QUIT:
#line 23
            exit(0);
#line 23
            break;
#line 23
            case SDL_MOUSEBUTTONDOWN:
#line 23
            printf("SDL_MOUSEBUTTONDOWN\n");
#line 23
            sjv_mouseEvent = sjv_mouseEvent_down;
#line 23
            sjv_x = e.button.x;
#line 23
            sjv_y = e.button.y;
#line 23
            break;
#line 23
            case SDL_MOUSEBUTTONUP:
#line 23
            printf("SDL_MOUSEBUTTONUP\n");
#line 23
            sjv_mouseEvent = sjv_mouseEvent_up;
#line 23
            sjv_x = e.button.x;
#line 23
            sjv_y = e.button.y;
#line 23
            break;
#line 23
            case SDL_MOUSEMOTION:
#line 23
            printf("SDL_MOUSEMOTION\n");
#line 23
            sjv_mouseEvent = sjv_mouseEvent_move;
#line 23
            sjv_x = e.motion.x;
#line 23
            sjv_y = e.motion.y;
#line 23
            break;
#line 23
        }
#line 23
    }
#line 52
    sjt_compare75 = sjv_mouseEvent;
#line 52
    sjt_negate38 = 1;
#line 52
    result48 = -sjt_negate38;
#line 52
    sjt_compare76 = result48;
#line 52
    sjt_ifElse44 = sjt_compare75 != sjt_compare76;
    if (sjt_ifElse44) {
        sjs_point sjt_call58;
        sjs_point* sjt_interfaceParam18;
        int32_t sjt_interfaceParam19;
        sji_element* sjt_parent246;

#line 7 ".\..\lib\ui\element.sj"
        sjt_parent246 = sjv_root;
#line 53 ".\..\lib\ui\loop.sj"
        sjt_call58.x = sjv_x;
#line 53
        sjt_call58.y = sjv_y;
#line 0 ""
        sjf_point(&sjt_call58);
#line 53 ".\..\lib\ui\loop.sj"
        sjt_interfaceParam18 = &sjt_call58;
#line 7 ".\..\lib\ui\element.sj"
        sjt_interfaceParam19 = sjv_mouseEvent;
#line 53 ".\..\lib\ui\loop.sj"
        sjt_parent246->fireMouseEvent((void*)(((char*)sjt_parent246->_parent) + sizeof(intptr_t)), sjt_interfaceParam18, sjt_interfaceParam19);

        sjf_point_destroy(&sjt_call58);
    }

    sjf_rect_destroy(&sjv_rect);
    sjf_size_destroy(&sjv_size);
}

void sjf_margin(sjs_margin* _this) {
}

void sjf_margin_copy(sjs_margin* _this, sjs_margin* _from) {
#line 1 ".\..\lib\ui\margin.sj"
    _this->l = _from->l;
#line 1
    _this->t = _from->t;
#line 1
    _this->r = _from->r;
#line 1
    _this->b = _from->b;
}

void sjf_margin_destroy(sjs_margin* _this) {
}

void sjf_margin_heap(sjs_margin_heap* _this) {
}

void sjf_mat4(sjs_mat4* _this) {
}

void sjf_mat4_copy(sjs_mat4* _this, sjs_mat4* _from) {
#line 1 ".\..\lib\ui\mat4.sj"
    _this->m00 = _from->m00;
#line 1
    _this->m01 = _from->m01;
#line 1
    _this->m02 = _from->m02;
#line 1
    _this->m03 = _from->m03;
#line 1
    _this->m10 = _from->m10;
#line 1
    _this->m11 = _from->m11;
#line 1
    _this->m12 = _from->m12;
#line 1
    _this->m13 = _from->m13;
#line 1
    _this->m20 = _from->m20;
#line 1
    _this->m21 = _from->m21;
#line 1
    _this->m22 = _from->m22;
#line 1
    _this->m23 = _from->m23;
#line 1
    _this->m30 = _from->m30;
#line 1
    _this->m31 = _from->m31;
#line 1
    _this->m32 = _from->m32;
#line 1
    _this->m33 = _from->m33;
}

void sjf_mat4_destroy(sjs_mat4* _this) {
}

void sjf_mat4_determinant(sjs_mat4* _parent, float* _return) {
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

#line 84 ".\..\lib\ui\mat4.sj"
    sjt_dot832 = _parent;
#line 85
    sjt_math1609 = (sjt_dot832)->m03;
#line 84
    sjt_dot833 = _parent;
#line 85
    sjt_math1610 = (sjt_dot833)->m12;
#line 85
    sjt_math1607 = sjt_math1609 * sjt_math1610;
#line 84
    sjt_dot834 = _parent;
#line 85
    sjt_math1608 = (sjt_dot834)->m21;
#line 85
    sjt_math1605 = sjt_math1607 * sjt_math1608;
#line 84
    sjt_dot835 = _parent;
#line 85
    sjt_math1606 = (sjt_dot835)->m30;
#line 85
    sjt_math1603 = sjt_math1605 * sjt_math1606;
#line 84
    sjt_dot836 = _parent;
#line 85
    sjt_math1615 = (sjt_dot836)->m02;
#line 84
    sjt_dot837 = _parent;
#line 85
    sjt_math1616 = (sjt_dot837)->m13;
#line 85
    sjt_math1613 = sjt_math1615 * sjt_math1616;
#line 84
    sjt_dot838 = _parent;
#line 85
    sjt_math1614 = (sjt_dot838)->m21;
#line 85
    sjt_math1611 = sjt_math1613 * sjt_math1614;
#line 84
    sjt_dot839 = _parent;
#line 85
    sjt_math1612 = (sjt_dot839)->m30;
#line 85
    sjt_math1604 = sjt_math1611 * sjt_math1612;
#line 85
    sjt_math1601 = sjt_math1603 - sjt_math1604;
#line 84
    sjt_dot840 = _parent;
#line 85
    sjt_math1621 = (sjt_dot840)->m03;
#line 84
    sjt_dot841 = _parent;
#line 85
    sjt_math1622 = (sjt_dot841)->m11;
#line 85
    sjt_math1619 = sjt_math1621 * sjt_math1622;
#line 84
    sjt_dot842 = _parent;
#line 85
    sjt_math1620 = (sjt_dot842)->m22;
#line 85
    sjt_math1617 = sjt_math1619 * sjt_math1620;
#line 84
    sjt_dot843 = _parent;
#line 85
    sjt_math1618 = (sjt_dot843)->m30;
#line 85
    sjt_math1602 = sjt_math1617 * sjt_math1618;
#line 85
    sjt_math1599 = sjt_math1601 - sjt_math1602;
#line 84
    sjt_dot844 = _parent;
#line 85
    sjt_math1627 = (sjt_dot844)->m01;
#line 84
    sjt_dot845 = _parent;
#line 85
    sjt_math1628 = (sjt_dot845)->m13;
#line 85
    sjt_math1625 = sjt_math1627 * sjt_math1628;
#line 84
    sjt_dot846 = _parent;
#line 85
    sjt_math1626 = (sjt_dot846)->m22;
#line 85
    sjt_math1623 = sjt_math1625 * sjt_math1626;
#line 84
    sjt_dot847 = _parent;
#line 85
    sjt_math1624 = (sjt_dot847)->m30;
#line 85
    sjt_math1600 = sjt_math1623 * sjt_math1624;
#line 85
    sjt_math1597 = sjt_math1599 + sjt_math1600;
#line 84
    sjt_dot848 = _parent;
#line 85
    sjt_math1633 = (sjt_dot848)->m02;
#line 84
    sjt_dot849 = _parent;
#line 85
    sjt_math1634 = (sjt_dot849)->m11;
#line 85
    sjt_math1631 = sjt_math1633 * sjt_math1634;
#line 84
    sjt_dot850 = _parent;
#line 85
    sjt_math1632 = (sjt_dot850)->m23;
#line 85
    sjt_math1629 = sjt_math1631 * sjt_math1632;
#line 84
    sjt_dot851 = _parent;
#line 85
    sjt_math1630 = (sjt_dot851)->m30;
#line 85
    sjt_math1598 = sjt_math1629 * sjt_math1630;
#line 85
    sjt_math1595 = sjt_math1597 + sjt_math1598;
#line 84
    sjt_dot852 = _parent;
#line 85
    sjt_math1639 = (sjt_dot852)->m01;
#line 84
    sjt_dot853 = _parent;
#line 85
    sjt_math1640 = (sjt_dot853)->m12;
#line 85
    sjt_math1637 = sjt_math1639 * sjt_math1640;
#line 84
    sjt_dot854 = _parent;
#line 85
    sjt_math1638 = (sjt_dot854)->m23;
#line 85
    sjt_math1635 = sjt_math1637 * sjt_math1638;
#line 84
    sjt_dot855 = _parent;
#line 85
    sjt_math1636 = (sjt_dot855)->m30;
#line 85
    sjt_math1596 = sjt_math1635 * sjt_math1636;
#line 85
    sjt_math1593 = sjt_math1595 - sjt_math1596;
#line 84
    sjt_dot856 = _parent;
#line 85
    sjt_math1645 = (sjt_dot856)->m03;
#line 84
    sjt_dot857 = _parent;
#line 85
    sjt_math1646 = (sjt_dot857)->m12;
#line 85
    sjt_math1643 = sjt_math1645 * sjt_math1646;
#line 84
    sjt_dot858 = _parent;
#line 85
    sjt_math1644 = (sjt_dot858)->m20;
#line 85
    sjt_math1641 = sjt_math1643 * sjt_math1644;
#line 84
    sjt_dot859 = _parent;
#line 85
    sjt_math1642 = (sjt_dot859)->m31;
#line 85
    sjt_math1594 = sjt_math1641 * sjt_math1642;
#line 85
    sjt_math1591 = sjt_math1593 - sjt_math1594;
#line 84
    sjt_dot860 = _parent;
#line 85
    sjt_math1651 = (sjt_dot860)->m02;
#line 84
    sjt_dot861 = _parent;
#line 85
    sjt_math1652 = (sjt_dot861)->m13;
#line 85
    sjt_math1649 = sjt_math1651 * sjt_math1652;
#line 84
    sjt_dot862 = _parent;
#line 85
    sjt_math1650 = (sjt_dot862)->m20;
#line 85
    sjt_math1647 = sjt_math1649 * sjt_math1650;
#line 84
    sjt_dot863 = _parent;
#line 85
    sjt_math1648 = (sjt_dot863)->m31;
#line 85
    sjt_math1592 = sjt_math1647 * sjt_math1648;
#line 85
    sjt_math1589 = sjt_math1591 + sjt_math1592;
#line 84
    sjt_dot864 = _parent;
#line 85
    sjt_math1657 = (sjt_dot864)->m03;
#line 84
    sjt_dot865 = _parent;
#line 85
    sjt_math1658 = (sjt_dot865)->m10;
#line 85
    sjt_math1655 = sjt_math1657 * sjt_math1658;
#line 84
    sjt_dot866 = _parent;
#line 85
    sjt_math1656 = (sjt_dot866)->m22;
#line 85
    sjt_math1653 = sjt_math1655 * sjt_math1656;
#line 84
    sjt_dot867 = _parent;
#line 85
    sjt_math1654 = (sjt_dot867)->m31;
#line 85
    sjt_math1590 = sjt_math1653 * sjt_math1654;
#line 85
    sjt_math1587 = sjt_math1589 + sjt_math1590;
#line 84
    sjt_dot868 = _parent;
#line 85
    sjt_math1663 = (sjt_dot868)->m00;
#line 84
    sjt_dot869 = _parent;
#line 85
    sjt_math1664 = (sjt_dot869)->m13;
#line 85
    sjt_math1661 = sjt_math1663 * sjt_math1664;
#line 84
    sjt_dot870 = _parent;
#line 85
    sjt_math1662 = (sjt_dot870)->m22;
#line 85
    sjt_math1659 = sjt_math1661 * sjt_math1662;
#line 84
    sjt_dot871 = _parent;
#line 85
    sjt_math1660 = (sjt_dot871)->m31;
#line 85
    sjt_math1588 = sjt_math1659 * sjt_math1660;
#line 85
    sjt_math1585 = sjt_math1587 - sjt_math1588;
#line 84
    sjt_dot872 = _parent;
#line 85
    sjt_math1669 = (sjt_dot872)->m02;
#line 84
    sjt_dot873 = _parent;
#line 85
    sjt_math1670 = (sjt_dot873)->m10;
#line 85
    sjt_math1667 = sjt_math1669 * sjt_math1670;
#line 84
    sjt_dot874 = _parent;
#line 85
    sjt_math1668 = (sjt_dot874)->m23;
#line 85
    sjt_math1665 = sjt_math1667 * sjt_math1668;
#line 84
    sjt_dot875 = _parent;
#line 85
    sjt_math1666 = (sjt_dot875)->m31;
#line 85
    sjt_math1586 = sjt_math1665 * sjt_math1666;
#line 85
    sjt_math1583 = sjt_math1585 - sjt_math1586;
#line 84
    sjt_dot876 = _parent;
#line 85
    sjt_math1675 = (sjt_dot876)->m00;
#line 84
    sjt_dot877 = _parent;
#line 85
    sjt_math1676 = (sjt_dot877)->m12;
#line 85
    sjt_math1673 = sjt_math1675 * sjt_math1676;
#line 84
    sjt_dot878 = _parent;
#line 85
    sjt_math1674 = (sjt_dot878)->m23;
#line 85
    sjt_math1671 = sjt_math1673 * sjt_math1674;
#line 84
    sjt_dot879 = _parent;
#line 85
    sjt_math1672 = (sjt_dot879)->m31;
#line 85
    sjt_math1584 = sjt_math1671 * sjt_math1672;
#line 85
    sjt_math1581 = sjt_math1583 + sjt_math1584;
#line 84
    sjt_dot880 = _parent;
#line 85
    sjt_math1681 = (sjt_dot880)->m03;
#line 84
    sjt_dot881 = _parent;
#line 85
    sjt_math1682 = (sjt_dot881)->m11;
#line 85
    sjt_math1679 = sjt_math1681 * sjt_math1682;
#line 84
    sjt_dot882 = _parent;
#line 85
    sjt_math1680 = (sjt_dot882)->m20;
#line 85
    sjt_math1677 = sjt_math1679 * sjt_math1680;
#line 84
    sjt_dot883 = _parent;
#line 85
    sjt_math1678 = (sjt_dot883)->m32;
#line 85
    sjt_math1582 = sjt_math1677 * sjt_math1678;
#line 85
    sjt_math1579 = sjt_math1581 + sjt_math1582;
#line 84
    sjt_dot884 = _parent;
#line 85
    sjt_math1687 = (sjt_dot884)->m01;
#line 84
    sjt_dot885 = _parent;
#line 85
    sjt_math1688 = (sjt_dot885)->m13;
#line 85
    sjt_math1685 = sjt_math1687 * sjt_math1688;
#line 84
    sjt_dot886 = _parent;
#line 85
    sjt_math1686 = (sjt_dot886)->m20;
#line 85
    sjt_math1683 = sjt_math1685 * sjt_math1686;
#line 84
    sjt_dot887 = _parent;
#line 85
    sjt_math1684 = (sjt_dot887)->m32;
#line 85
    sjt_math1580 = sjt_math1683 * sjt_math1684;
#line 85
    sjt_math1577 = sjt_math1579 - sjt_math1580;
#line 84
    sjt_dot888 = _parent;
#line 85
    sjt_math1693 = (sjt_dot888)->m03;
#line 84
    sjt_dot889 = _parent;
#line 85
    sjt_math1694 = (sjt_dot889)->m10;
#line 85
    sjt_math1691 = sjt_math1693 * sjt_math1694;
#line 84
    sjt_dot890 = _parent;
#line 85
    sjt_math1692 = (sjt_dot890)->m21;
#line 85
    sjt_math1689 = sjt_math1691 * sjt_math1692;
#line 84
    sjt_dot891 = _parent;
#line 85
    sjt_math1690 = (sjt_dot891)->m32;
#line 85
    sjt_math1578 = sjt_math1689 * sjt_math1690;
#line 85
    sjt_math1575 = sjt_math1577 - sjt_math1578;
#line 84
    sjt_dot892 = _parent;
#line 85
    sjt_math1699 = (sjt_dot892)->m00;
#line 84
    sjt_dot893 = _parent;
#line 85
    sjt_math1700 = (sjt_dot893)->m13;
#line 85
    sjt_math1697 = sjt_math1699 * sjt_math1700;
#line 84
    sjt_dot894 = _parent;
#line 85
    sjt_math1698 = (sjt_dot894)->m21;
#line 85
    sjt_math1695 = sjt_math1697 * sjt_math1698;
#line 84
    sjt_dot895 = _parent;
#line 85
    sjt_math1696 = (sjt_dot895)->m32;
#line 85
    sjt_math1576 = sjt_math1695 * sjt_math1696;
#line 85
    sjt_math1573 = sjt_math1575 + sjt_math1576;
#line 84
    sjt_dot896 = _parent;
#line 85
    sjt_math1705 = (sjt_dot896)->m01;
#line 84
    sjt_dot897 = _parent;
#line 85
    sjt_math1706 = (sjt_dot897)->m10;
#line 85
    sjt_math1703 = sjt_math1705 * sjt_math1706;
#line 84
    sjt_dot898 = _parent;
#line 85
    sjt_math1704 = (sjt_dot898)->m23;
#line 85
    sjt_math1701 = sjt_math1703 * sjt_math1704;
#line 84
    sjt_dot899 = _parent;
#line 85
    sjt_math1702 = (sjt_dot899)->m32;
#line 85
    sjt_math1574 = sjt_math1701 * sjt_math1702;
#line 85
    sjt_math1571 = sjt_math1573 + sjt_math1574;
#line 84
    sjt_dot900 = _parent;
#line 85
    sjt_math1711 = (sjt_dot900)->m00;
#line 84
    sjt_dot901 = _parent;
#line 85
    sjt_math1712 = (sjt_dot901)->m11;
#line 85
    sjt_math1709 = sjt_math1711 * sjt_math1712;
#line 84
    sjt_dot902 = _parent;
#line 85
    sjt_math1710 = (sjt_dot902)->m23;
#line 85
    sjt_math1707 = sjt_math1709 * sjt_math1710;
#line 84
    sjt_dot903 = _parent;
#line 85
    sjt_math1708 = (sjt_dot903)->m32;
#line 85
    sjt_math1572 = sjt_math1707 * sjt_math1708;
#line 85
    sjt_math1569 = sjt_math1571 - sjt_math1572;
#line 84
    sjt_dot904 = _parent;
#line 85
    sjt_math1717 = (sjt_dot904)->m02;
#line 84
    sjt_dot905 = _parent;
#line 85
    sjt_math1718 = (sjt_dot905)->m11;
#line 85
    sjt_math1715 = sjt_math1717 * sjt_math1718;
#line 84
    sjt_dot906 = _parent;
#line 85
    sjt_math1716 = (sjt_dot906)->m20;
#line 85
    sjt_math1713 = sjt_math1715 * sjt_math1716;
#line 84
    sjt_dot907 = _parent;
#line 85
    sjt_math1714 = (sjt_dot907)->m33;
#line 85
    sjt_math1570 = sjt_math1713 * sjt_math1714;
#line 85
    sjt_math1567 = sjt_math1569 - sjt_math1570;
#line 84
    sjt_dot908 = _parent;
#line 85
    sjt_math1723 = (sjt_dot908)->m01;
#line 84
    sjt_dot909 = _parent;
#line 85
    sjt_math1724 = (sjt_dot909)->m12;
#line 85
    sjt_math1721 = sjt_math1723 * sjt_math1724;
#line 84
    sjt_dot910 = _parent;
#line 85
    sjt_math1722 = (sjt_dot910)->m20;
#line 85
    sjt_math1719 = sjt_math1721 * sjt_math1722;
#line 84
    sjt_dot911 = _parent;
#line 85
    sjt_math1720 = (sjt_dot911)->m33;
#line 85
    sjt_math1568 = sjt_math1719 * sjt_math1720;
#line 85
    sjt_math1565 = sjt_math1567 + sjt_math1568;
#line 84
    sjt_dot912 = _parent;
#line 85
    sjt_math1729 = (sjt_dot912)->m02;
#line 84
    sjt_dot913 = _parent;
#line 85
    sjt_math1730 = (sjt_dot913)->m10;
#line 85
    sjt_math1727 = sjt_math1729 * sjt_math1730;
#line 84
    sjt_dot914 = _parent;
#line 85
    sjt_math1728 = (sjt_dot914)->m21;
#line 85
    sjt_math1725 = sjt_math1727 * sjt_math1728;
#line 84
    sjt_dot915 = _parent;
#line 85
    sjt_math1726 = (sjt_dot915)->m33;
#line 85
    sjt_math1566 = sjt_math1725 * sjt_math1726;
#line 85
    sjt_math1563 = sjt_math1565 + sjt_math1566;
#line 84
    sjt_dot916 = _parent;
#line 85
    sjt_math1735 = (sjt_dot916)->m00;
#line 84
    sjt_dot917 = _parent;
#line 85
    sjt_math1736 = (sjt_dot917)->m12;
#line 85
    sjt_math1733 = sjt_math1735 * sjt_math1736;
#line 84
    sjt_dot918 = _parent;
#line 85
    sjt_math1734 = (sjt_dot918)->m21;
#line 85
    sjt_math1731 = sjt_math1733 * sjt_math1734;
#line 84
    sjt_dot919 = _parent;
#line 85
    sjt_math1732 = (sjt_dot919)->m33;
#line 85
    sjt_math1564 = sjt_math1731 * sjt_math1732;
#line 85
    sjt_math1561 = sjt_math1563 - sjt_math1564;
#line 84
    sjt_dot920 = _parent;
#line 85
    sjt_math1741 = (sjt_dot920)->m01;
#line 84
    sjt_dot921 = _parent;
#line 85
    sjt_math1742 = (sjt_dot921)->m10;
#line 85
    sjt_math1739 = sjt_math1741 * sjt_math1742;
#line 84
    sjt_dot922 = _parent;
#line 85
    sjt_math1740 = (sjt_dot922)->m22;
#line 85
    sjt_math1737 = sjt_math1739 * sjt_math1740;
#line 84
    sjt_dot923 = _parent;
#line 85
    sjt_math1738 = (sjt_dot923)->m33;
#line 85
    sjt_math1562 = sjt_math1737 * sjt_math1738;
#line 85
    sjt_math1559 = sjt_math1561 - sjt_math1562;
#line 84
    sjt_dot924 = _parent;
#line 85
    sjt_math1747 = (sjt_dot924)->m00;
#line 84
    sjt_dot925 = _parent;
#line 85
    sjt_math1748 = (sjt_dot925)->m11;
#line 85
    sjt_math1745 = sjt_math1747 * sjt_math1748;
#line 84
    sjt_dot926 = _parent;
#line 85
    sjt_math1746 = (sjt_dot926)->m22;
#line 85
    sjt_math1743 = sjt_math1745 * sjt_math1746;
#line 84
    sjt_dot927 = _parent;
#line 85
    sjt_math1744 = (sjt_dot927)->m33;
#line 85
    sjt_math1560 = sjt_math1743 * sjt_math1744;
#line 85
    (*_return) = sjt_math1559 + sjt_math1560;
}

void sjf_mat4_heap(sjs_mat4_heap* _this) {
}

void sjf_mat4_identity(sjs_mat4* _return) {
#line 112 ".\..\lib\ui\mat4.sj"
    _return->m00 = 1.0f;
#line 3
    _return->m01 = 0.0f;
#line 4
    _return->m02 = 0.0f;
#line 5
    _return->m03 = 0.0f;
#line 6
    _return->m10 = 0.0f;
#line 113
    _return->m11 = 1.0f;
#line 8
    _return->m12 = 0.0f;
#line 9
    _return->m13 = 0.0f;
#line 10
    _return->m20 = 0.0f;
#line 11
    _return->m21 = 0.0f;
#line 114
    _return->m22 = 1.0f;
#line 13
    _return->m23 = 0.0f;
#line 14
    _return->m30 = 0.0f;
#line 15
    _return->m31 = 0.0f;
#line 16
    _return->m32 = 0.0f;
#line 115
    _return->m33 = 1.0f;
#line 0 ""
    sjf_mat4(_return);
}

void sjf_mat4_identity_heap(sjs_mat4_heap** _return) {
    (*_return) = (sjs_mat4_heap*)malloc(sizeof(sjs_mat4_heap));
    (*_return)->_refCount = 1;
#line 112 ".\..\lib\ui\mat4.sj"
    (*_return)->m00 = 1.0f;
#line 3
    (*_return)->m01 = 0.0f;
#line 4
    (*_return)->m02 = 0.0f;
#line 5
    (*_return)->m03 = 0.0f;
#line 6
    (*_return)->m10 = 0.0f;
#line 113
    (*_return)->m11 = 1.0f;
#line 8
    (*_return)->m12 = 0.0f;
#line 9
    (*_return)->m13 = 0.0f;
#line 10
    (*_return)->m20 = 0.0f;
#line 11
    (*_return)->m21 = 0.0f;
#line 114
    (*_return)->m22 = 1.0f;
#line 13
    (*_return)->m23 = 0.0f;
#line 14
    (*_return)->m30 = 0.0f;
#line 15
    (*_return)->m31 = 0.0f;
#line 16
    (*_return)->m32 = 0.0f;
#line 115
    (*_return)->m33 = 1.0f;
#line 0 ""
    sjf_mat4_heap((*_return));
}

void sjf_mat4_invert(sjs_mat4* _parent, sjs_mat4* _return) {
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
    sjs_mat4* sjt_dot525;
    sjs_mat4* sjt_dot526;
    sjs_mat4* sjt_dot527;
    sjs_mat4* sjt_dot528;
    sjs_mat4* sjt_dot529;
    sjs_mat4* sjt_dot530;
    sjs_mat4* sjt_dot531;
    sjs_mat4* sjt_dot532;
    sjs_mat4* sjt_dot533;
    sjs_mat4* sjt_dot534;
    sjs_mat4* sjt_dot535;
    sjs_mat4* sjt_dot536;
    sjs_mat4* sjt_dot537;
    sjs_mat4* sjt_dot538;
    sjs_mat4* sjt_dot539;
    sjs_mat4* sjt_dot540;
    sjs_mat4* sjt_dot541;
    sjs_mat4* sjt_dot542;
    sjs_mat4* sjt_dot543;
    sjs_mat4* sjt_dot544;
    sjs_mat4* sjt_dot545;
    sjs_mat4* sjt_dot546;
    sjs_mat4* sjt_dot547;
    sjs_mat4* sjt_dot548;
    sjs_mat4* sjt_dot549;
    sjs_mat4* sjt_dot550;
    sjs_mat4* sjt_dot551;
    sjs_mat4* sjt_dot552;
    sjs_mat4* sjt_dot553;
    sjs_mat4* sjt_dot554;
    sjs_mat4* sjt_dot555;
    sjs_mat4* sjt_dot556;
    sjs_mat4* sjt_dot557;
    sjs_mat4* sjt_dot558;
    sjs_mat4* sjt_dot559;
    sjs_mat4* sjt_dot560;
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
    float sjt_functionParam79;
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
    float sjt_math1557;
    float sjt_math1558;
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
    sjs_mat4* sjt_parent54;
    sjs_mat4 sjv_t;

#line 61 ".\..\lib\ui\mat4.sj"
    sjt_dot512 = _parent;
#line 63
    sjt_math961 = (sjt_dot512)->m12;
#line 61
    sjt_dot513 = _parent;
#line 63
    sjt_math962 = (sjt_dot513)->m23;
#line 63
    sjt_math959 = sjt_math961 * sjt_math962;
#line 61
    sjt_dot514 = _parent;
#line 63
    sjt_math960 = (sjt_dot514)->m31;
#line 63
    sjt_math957 = sjt_math959 * sjt_math960;
#line 61
    sjt_dot515 = _parent;
#line 63
    sjt_math965 = (sjt_dot515)->m13;
#line 61
    sjt_dot516 = _parent;
#line 63
    sjt_math966 = (sjt_dot516)->m22;
#line 63
    sjt_math963 = sjt_math965 * sjt_math966;
#line 61
    sjt_dot517 = _parent;
#line 63
    sjt_math964 = (sjt_dot517)->m31;
#line 63
    sjt_math958 = sjt_math963 * sjt_math964;
#line 63
    sjt_math955 = sjt_math957 - sjt_math958;
#line 61
    sjt_dot518 = _parent;
#line 63
    sjt_math969 = (sjt_dot518)->m13;
#line 61
    sjt_dot519 = _parent;
#line 63
    sjt_math970 = (sjt_dot519)->m21;
#line 63
    sjt_math967 = sjt_math969 * sjt_math970;
#line 61
    sjt_dot520 = _parent;
#line 63
    sjt_math968 = (sjt_dot520)->m32;
#line 63
    sjt_math956 = sjt_math967 * sjt_math968;
#line 63
    sjt_math953 = sjt_math955 + sjt_math956;
#line 61
    sjt_dot521 = _parent;
#line 63
    sjt_math973 = (sjt_dot521)->m11;
#line 61
    sjt_dot522 = _parent;
#line 63
    sjt_math974 = (sjt_dot522)->m23;
#line 63
    sjt_math971 = sjt_math973 * sjt_math974;
#line 61
    sjt_dot523 = _parent;
#line 63
    sjt_math972 = (sjt_dot523)->m32;
#line 63
    sjt_math954 = sjt_math971 * sjt_math972;
#line 63
    sjt_math951 = sjt_math953 - sjt_math954;
#line 61
    sjt_dot524 = _parent;
#line 63
    sjt_math977 = (sjt_dot524)->m12;
#line 61
    sjt_dot525 = _parent;
#line 63
    sjt_math978 = (sjt_dot525)->m21;
#line 63
    sjt_math975 = sjt_math977 * sjt_math978;
#line 61
    sjt_dot526 = _parent;
#line 63
    sjt_math976 = (sjt_dot526)->m33;
#line 63
    sjt_math952 = sjt_math975 * sjt_math976;
#line 63
    sjt_math949 = sjt_math951 - sjt_math952;
#line 61
    sjt_dot527 = _parent;
#line 63
    sjt_math981 = (sjt_dot527)->m11;
#line 61
    sjt_dot528 = _parent;
#line 63
    sjt_math982 = (sjt_dot528)->m22;
#line 63
    sjt_math979 = sjt_math981 * sjt_math982;
#line 61
    sjt_dot529 = _parent;
#line 63
    sjt_math980 = (sjt_dot529)->m33;
#line 63
    sjt_math950 = sjt_math979 * sjt_math980;
#line 63
    sjv_t.m00 = sjt_math949 + sjt_math950;
#line 61
    sjt_dot530 = _parent;
#line 64
    sjt_math995 = (sjt_dot530)->m03;
#line 61
    sjt_dot531 = _parent;
#line 64
    sjt_math996 = (sjt_dot531)->m22;
#line 64
    sjt_math993 = sjt_math995 * sjt_math996;
#line 61
    sjt_dot532 = _parent;
#line 64
    sjt_math994 = (sjt_dot532)->m31;
#line 64
    sjt_math991 = sjt_math993 * sjt_math994;
#line 61
    sjt_dot533 = _parent;
#line 64
    sjt_math999 = (sjt_dot533)->m02;
#line 61
    sjt_dot534 = _parent;
#line 64
    sjt_math1000 = (sjt_dot534)->m23;
#line 64
    sjt_math997 = sjt_math999 * sjt_math1000;
#line 61
    sjt_dot535 = _parent;
#line 64
    sjt_math998 = (sjt_dot535)->m31;
#line 64
    sjt_math992 = sjt_math997 * sjt_math998;
#line 64
    sjt_math989 = sjt_math991 - sjt_math992;
#line 61
    sjt_dot536 = _parent;
#line 64
    sjt_math1003 = (sjt_dot536)->m03;
#line 61
    sjt_dot537 = _parent;
#line 64
    sjt_math1004 = (sjt_dot537)->m21;
#line 64
    sjt_math1001 = sjt_math1003 * sjt_math1004;
#line 61
    sjt_dot538 = _parent;
#line 64
    sjt_math1002 = (sjt_dot538)->m32;
#line 64
    sjt_math990 = sjt_math1001 * sjt_math1002;
#line 64
    sjt_math987 = sjt_math989 - sjt_math990;
#line 61
    sjt_dot539 = _parent;
#line 64
    sjt_math1007 = (sjt_dot539)->m01;
#line 61
    sjt_dot540 = _parent;
#line 64
    sjt_math1008 = (sjt_dot540)->m23;
#line 64
    sjt_math1005 = sjt_math1007 * sjt_math1008;
#line 61
    sjt_dot541 = _parent;
#line 64
    sjt_math1006 = (sjt_dot541)->m32;
#line 64
    sjt_math988 = sjt_math1005 * sjt_math1006;
#line 64
    sjt_math985 = sjt_math987 + sjt_math988;
#line 61
    sjt_dot542 = _parent;
#line 64
    sjt_math1011 = (sjt_dot542)->m02;
#line 61
    sjt_dot543 = _parent;
#line 64
    sjt_math1012 = (sjt_dot543)->m21;
#line 64
    sjt_math1009 = sjt_math1011 * sjt_math1012;
#line 61
    sjt_dot544 = _parent;
#line 64
    sjt_math1010 = (sjt_dot544)->m33;
#line 64
    sjt_math986 = sjt_math1009 * sjt_math1010;
#line 64
    sjt_math983 = sjt_math985 + sjt_math986;
#line 61
    sjt_dot545 = _parent;
#line 64
    sjt_math1015 = (sjt_dot545)->m01;
#line 61
    sjt_dot546 = _parent;
#line 64
    sjt_math1016 = (sjt_dot546)->m22;
#line 64
    sjt_math1013 = sjt_math1015 * sjt_math1016;
#line 61
    sjt_dot547 = _parent;
#line 64
    sjt_math1014 = (sjt_dot547)->m33;
#line 64
    sjt_math984 = sjt_math1013 * sjt_math1014;
#line 64
    sjv_t.m01 = sjt_math983 - sjt_math984;
#line 61
    sjt_dot548 = _parent;
#line 65
    sjt_math1029 = (sjt_dot548)->m02;
#line 61
    sjt_dot549 = _parent;
#line 65
    sjt_math1030 = (sjt_dot549)->m13;
#line 65
    sjt_math1027 = sjt_math1029 * sjt_math1030;
#line 61
    sjt_dot550 = _parent;
#line 65
    sjt_math1028 = (sjt_dot550)->m31;
#line 65
    sjt_math1025 = sjt_math1027 * sjt_math1028;
#line 61
    sjt_dot551 = _parent;
#line 65
    sjt_math1033 = (sjt_dot551)->m03;
#line 61
    sjt_dot552 = _parent;
#line 65
    sjt_math1034 = (sjt_dot552)->m12;
#line 65
    sjt_math1031 = sjt_math1033 * sjt_math1034;
#line 61
    sjt_dot553 = _parent;
#line 65
    sjt_math1032 = (sjt_dot553)->m31;
#line 65
    sjt_math1026 = sjt_math1031 * sjt_math1032;
#line 65
    sjt_math1023 = sjt_math1025 - sjt_math1026;
#line 61
    sjt_dot554 = _parent;
#line 65
    sjt_math1037 = (sjt_dot554)->m03;
#line 61
    sjt_dot555 = _parent;
#line 65
    sjt_math1038 = (sjt_dot555)->m11;
#line 65
    sjt_math1035 = sjt_math1037 * sjt_math1038;
#line 61
    sjt_dot556 = _parent;
#line 65
    sjt_math1036 = (sjt_dot556)->m32;
#line 65
    sjt_math1024 = sjt_math1035 * sjt_math1036;
#line 65
    sjt_math1021 = sjt_math1023 + sjt_math1024;
#line 61
    sjt_dot557 = _parent;
#line 65
    sjt_math1041 = (sjt_dot557)->m01;
#line 61
    sjt_dot558 = _parent;
#line 65
    sjt_math1042 = (sjt_dot558)->m13;
#line 65
    sjt_math1039 = sjt_math1041 * sjt_math1042;
#line 61
    sjt_dot559 = _parent;
#line 65
    sjt_math1040 = (sjt_dot559)->m32;
#line 65
    sjt_math1022 = sjt_math1039 * sjt_math1040;
#line 65
    sjt_math1019 = sjt_math1021 - sjt_math1022;
#line 61
    sjt_dot560 = _parent;
#line 65
    sjt_math1045 = (sjt_dot560)->m02;
#line 61
    sjt_dot561 = _parent;
#line 65
    sjt_math1046 = (sjt_dot561)->m11;
#line 65
    sjt_math1043 = sjt_math1045 * sjt_math1046;
#line 61
    sjt_dot562 = _parent;
#line 65
    sjt_math1044 = (sjt_dot562)->m33;
#line 65
    sjt_math1020 = sjt_math1043 * sjt_math1044;
#line 65
    sjt_math1017 = sjt_math1019 - sjt_math1020;
#line 61
    sjt_dot563 = _parent;
#line 65
    sjt_math1049 = (sjt_dot563)->m01;
#line 61
    sjt_dot564 = _parent;
#line 65
    sjt_math1050 = (sjt_dot564)->m12;
#line 65
    sjt_math1047 = sjt_math1049 * sjt_math1050;
#line 61
    sjt_dot565 = _parent;
#line 65
    sjt_math1048 = (sjt_dot565)->m33;
#line 65
    sjt_math1018 = sjt_math1047 * sjt_math1048;
#line 65
    sjv_t.m02 = sjt_math1017 + sjt_math1018;
#line 61
    sjt_dot566 = _parent;
#line 66
    sjt_math1063 = (sjt_dot566)->m03;
#line 61
    sjt_dot567 = _parent;
#line 66
    sjt_math1064 = (sjt_dot567)->m12;
#line 66
    sjt_math1061 = sjt_math1063 * sjt_math1064;
#line 61
    sjt_dot568 = _parent;
#line 66
    sjt_math1062 = (sjt_dot568)->m21;
#line 66
    sjt_math1059 = sjt_math1061 * sjt_math1062;
#line 61
    sjt_dot569 = _parent;
#line 66
    sjt_math1067 = (sjt_dot569)->m02;
#line 61
    sjt_dot570 = _parent;
#line 66
    sjt_math1068 = (sjt_dot570)->m13;
#line 66
    sjt_math1065 = sjt_math1067 * sjt_math1068;
#line 61
    sjt_dot571 = _parent;
#line 66
    sjt_math1066 = (sjt_dot571)->m21;
#line 66
    sjt_math1060 = sjt_math1065 * sjt_math1066;
#line 66
    sjt_math1057 = sjt_math1059 - sjt_math1060;
#line 61
    sjt_dot572 = _parent;
#line 66
    sjt_math1071 = (sjt_dot572)->m03;
#line 61
    sjt_dot573 = _parent;
#line 66
    sjt_math1072 = (sjt_dot573)->m11;
#line 66
    sjt_math1069 = sjt_math1071 * sjt_math1072;
#line 61
    sjt_dot574 = _parent;
#line 66
    sjt_math1070 = (sjt_dot574)->m22;
#line 66
    sjt_math1058 = sjt_math1069 * sjt_math1070;
#line 66
    sjt_math1055 = sjt_math1057 - sjt_math1058;
#line 61
    sjt_dot575 = _parent;
#line 66
    sjt_math1075 = (sjt_dot575)->m01;
#line 61
    sjt_dot576 = _parent;
#line 66
    sjt_math1076 = (sjt_dot576)->m13;
#line 66
    sjt_math1073 = sjt_math1075 * sjt_math1076;
#line 61
    sjt_dot577 = _parent;
#line 66
    sjt_math1074 = (sjt_dot577)->m22;
#line 66
    sjt_math1056 = sjt_math1073 * sjt_math1074;
#line 66
    sjt_math1053 = sjt_math1055 + sjt_math1056;
#line 61
    sjt_dot578 = _parent;
#line 66
    sjt_math1079 = (sjt_dot578)->m02;
#line 61
    sjt_dot579 = _parent;
#line 66
    sjt_math1080 = (sjt_dot579)->m11;
#line 66
    sjt_math1077 = sjt_math1079 * sjt_math1080;
#line 61
    sjt_dot580 = _parent;
#line 66
    sjt_math1078 = (sjt_dot580)->m23;
#line 66
    sjt_math1054 = sjt_math1077 * sjt_math1078;
#line 66
    sjt_math1051 = sjt_math1053 + sjt_math1054;
#line 61
    sjt_dot581 = _parent;
#line 66
    sjt_math1083 = (sjt_dot581)->m01;
#line 61
    sjt_dot582 = _parent;
#line 66
    sjt_math1084 = (sjt_dot582)->m12;
#line 66
    sjt_math1081 = sjt_math1083 * sjt_math1084;
#line 61
    sjt_dot583 = _parent;
#line 66
    sjt_math1082 = (sjt_dot583)->m23;
#line 66
    sjt_math1052 = sjt_math1081 * sjt_math1082;
#line 66
    sjv_t.m03 = sjt_math1051 - sjt_math1052;
#line 61
    sjt_dot584 = _parent;
#line 67
    sjt_math1097 = (sjt_dot584)->m13;
#line 61
    sjt_dot585 = _parent;
#line 67
    sjt_math1098 = (sjt_dot585)->m22;
#line 67
    sjt_math1095 = sjt_math1097 * sjt_math1098;
#line 61
    sjt_dot586 = _parent;
#line 67
    sjt_math1096 = (sjt_dot586)->m30;
#line 67
    sjt_math1093 = sjt_math1095 * sjt_math1096;
#line 61
    sjt_dot587 = _parent;
#line 67
    sjt_math1101 = (sjt_dot587)->m12;
#line 61
    sjt_dot588 = _parent;
#line 67
    sjt_math1102 = (sjt_dot588)->m23;
#line 67
    sjt_math1099 = sjt_math1101 * sjt_math1102;
#line 61
    sjt_dot589 = _parent;
#line 67
    sjt_math1100 = (sjt_dot589)->m30;
#line 67
    sjt_math1094 = sjt_math1099 * sjt_math1100;
#line 67
    sjt_math1091 = sjt_math1093 - sjt_math1094;
#line 61
    sjt_dot590 = _parent;
#line 67
    sjt_math1105 = (sjt_dot590)->m13;
#line 61
    sjt_dot591 = _parent;
#line 67
    sjt_math1106 = (sjt_dot591)->m20;
#line 67
    sjt_math1103 = sjt_math1105 * sjt_math1106;
#line 61
    sjt_dot592 = _parent;
#line 67
    sjt_math1104 = (sjt_dot592)->m32;
#line 67
    sjt_math1092 = sjt_math1103 * sjt_math1104;
#line 67
    sjt_math1089 = sjt_math1091 - sjt_math1092;
#line 61
    sjt_dot593 = _parent;
#line 67
    sjt_math1109 = (sjt_dot593)->m10;
#line 61
    sjt_dot594 = _parent;
#line 67
    sjt_math1110 = (sjt_dot594)->m23;
#line 67
    sjt_math1107 = sjt_math1109 * sjt_math1110;
#line 61
    sjt_dot595 = _parent;
#line 67
    sjt_math1108 = (sjt_dot595)->m32;
#line 67
    sjt_math1090 = sjt_math1107 * sjt_math1108;
#line 67
    sjt_math1087 = sjt_math1089 + sjt_math1090;
#line 61
    sjt_dot596 = _parent;
#line 67
    sjt_math1113 = (sjt_dot596)->m12;
#line 61
    sjt_dot597 = _parent;
#line 67
    sjt_math1114 = (sjt_dot597)->m20;
#line 67
    sjt_math1111 = sjt_math1113 * sjt_math1114;
#line 61
    sjt_dot598 = _parent;
#line 67
    sjt_math1112 = (sjt_dot598)->m33;
#line 67
    sjt_math1088 = sjt_math1111 * sjt_math1112;
#line 67
    sjt_math1085 = sjt_math1087 + sjt_math1088;
#line 61
    sjt_dot599 = _parent;
#line 67
    sjt_math1117 = (sjt_dot599)->m10;
#line 61
    sjt_dot600 = _parent;
#line 67
    sjt_math1118 = (sjt_dot600)->m22;
#line 67
    sjt_math1115 = sjt_math1117 * sjt_math1118;
#line 61
    sjt_dot601 = _parent;
#line 67
    sjt_math1116 = (sjt_dot601)->m33;
#line 67
    sjt_math1086 = sjt_math1115 * sjt_math1116;
#line 67
    sjv_t.m10 = sjt_math1085 - sjt_math1086;
#line 61
    sjt_dot602 = _parent;
#line 68
    sjt_math1131 = (sjt_dot602)->m02;
#line 61
    sjt_dot603 = _parent;
#line 68
    sjt_math1132 = (sjt_dot603)->m23;
#line 68
    sjt_math1129 = sjt_math1131 * sjt_math1132;
#line 61
    sjt_dot604 = _parent;
#line 68
    sjt_math1130 = (sjt_dot604)->m30;
#line 68
    sjt_math1127 = sjt_math1129 * sjt_math1130;
#line 61
    sjt_dot605 = _parent;
#line 68
    sjt_math1135 = (sjt_dot605)->m03;
#line 61
    sjt_dot606 = _parent;
#line 68
    sjt_math1136 = (sjt_dot606)->m22;
#line 68
    sjt_math1133 = sjt_math1135 * sjt_math1136;
#line 61
    sjt_dot607 = _parent;
#line 68
    sjt_math1134 = (sjt_dot607)->m30;
#line 68
    sjt_math1128 = sjt_math1133 * sjt_math1134;
#line 68
    sjt_math1125 = sjt_math1127 - sjt_math1128;
#line 61
    sjt_dot608 = _parent;
#line 68
    sjt_math1139 = (sjt_dot608)->m03;
#line 61
    sjt_dot609 = _parent;
#line 68
    sjt_math1140 = (sjt_dot609)->m20;
#line 68
    sjt_math1137 = sjt_math1139 * sjt_math1140;
#line 61
    sjt_dot610 = _parent;
#line 68
    sjt_math1138 = (sjt_dot610)->m32;
#line 68
    sjt_math1126 = sjt_math1137 * sjt_math1138;
#line 68
    sjt_math1123 = sjt_math1125 + sjt_math1126;
#line 61
    sjt_dot611 = _parent;
#line 68
    sjt_math1143 = (sjt_dot611)->m00;
#line 61
    sjt_dot612 = _parent;
#line 68
    sjt_math1144 = (sjt_dot612)->m23;
#line 68
    sjt_math1141 = sjt_math1143 * sjt_math1144;
#line 61
    sjt_dot613 = _parent;
#line 68
    sjt_math1142 = (sjt_dot613)->m32;
#line 68
    sjt_math1124 = sjt_math1141 * sjt_math1142;
#line 68
    sjt_math1121 = sjt_math1123 - sjt_math1124;
#line 61
    sjt_dot614 = _parent;
#line 68
    sjt_math1147 = (sjt_dot614)->m02;
#line 61
    sjt_dot615 = _parent;
#line 68
    sjt_math1148 = (sjt_dot615)->m20;
#line 68
    sjt_math1145 = sjt_math1147 * sjt_math1148;
#line 61
    sjt_dot616 = _parent;
#line 68
    sjt_math1146 = (sjt_dot616)->m33;
#line 68
    sjt_math1122 = sjt_math1145 * sjt_math1146;
#line 68
    sjt_math1119 = sjt_math1121 - sjt_math1122;
#line 61
    sjt_dot617 = _parent;
#line 68
    sjt_math1151 = (sjt_dot617)->m00;
#line 61
    sjt_dot618 = _parent;
#line 68
    sjt_math1152 = (sjt_dot618)->m22;
#line 68
    sjt_math1149 = sjt_math1151 * sjt_math1152;
#line 61
    sjt_dot619 = _parent;
#line 68
    sjt_math1150 = (sjt_dot619)->m33;
#line 68
    sjt_math1120 = sjt_math1149 * sjt_math1150;
#line 68
    sjv_t.m11 = sjt_math1119 + sjt_math1120;
#line 61
    sjt_dot620 = _parent;
#line 69
    sjt_math1165 = (sjt_dot620)->m03;
#line 61
    sjt_dot621 = _parent;
#line 69
    sjt_math1166 = (sjt_dot621)->m12;
#line 69
    sjt_math1163 = sjt_math1165 * sjt_math1166;
#line 61
    sjt_dot622 = _parent;
#line 69
    sjt_math1164 = (sjt_dot622)->m30;
#line 69
    sjt_math1161 = sjt_math1163 * sjt_math1164;
#line 61
    sjt_dot623 = _parent;
#line 69
    sjt_math1169 = (sjt_dot623)->m02;
#line 61
    sjt_dot624 = _parent;
#line 69
    sjt_math1170 = (sjt_dot624)->m13;
#line 69
    sjt_math1167 = sjt_math1169 * sjt_math1170;
#line 61
    sjt_dot625 = _parent;
#line 69
    sjt_math1168 = (sjt_dot625)->m30;
#line 69
    sjt_math1162 = sjt_math1167 * sjt_math1168;
#line 69
    sjt_math1159 = sjt_math1161 - sjt_math1162;
#line 61
    sjt_dot626 = _parent;
#line 69
    sjt_math1173 = (sjt_dot626)->m03;
#line 61
    sjt_dot627 = _parent;
#line 69
    sjt_math1174 = (sjt_dot627)->m10;
#line 69
    sjt_math1171 = sjt_math1173 * sjt_math1174;
#line 61
    sjt_dot628 = _parent;
#line 69
    sjt_math1172 = (sjt_dot628)->m32;
#line 69
    sjt_math1160 = sjt_math1171 * sjt_math1172;
#line 69
    sjt_math1157 = sjt_math1159 - sjt_math1160;
#line 61
    sjt_dot629 = _parent;
#line 69
    sjt_math1177 = (sjt_dot629)->m00;
#line 61
    sjt_dot630 = _parent;
#line 69
    sjt_math1178 = (sjt_dot630)->m13;
#line 69
    sjt_math1175 = sjt_math1177 * sjt_math1178;
#line 61
    sjt_dot631 = _parent;
#line 69
    sjt_math1176 = (sjt_dot631)->m32;
#line 69
    sjt_math1158 = sjt_math1175 * sjt_math1176;
#line 69
    sjt_math1155 = sjt_math1157 + sjt_math1158;
#line 61
    sjt_dot632 = _parent;
#line 69
    sjt_math1181 = (sjt_dot632)->m02;
#line 61
    sjt_dot633 = _parent;
#line 69
    sjt_math1182 = (sjt_dot633)->m10;
#line 69
    sjt_math1179 = sjt_math1181 * sjt_math1182;
#line 61
    sjt_dot634 = _parent;
#line 69
    sjt_math1180 = (sjt_dot634)->m33;
#line 69
    sjt_math1156 = sjt_math1179 * sjt_math1180;
#line 69
    sjt_math1153 = sjt_math1155 + sjt_math1156;
#line 61
    sjt_dot635 = _parent;
#line 69
    sjt_math1185 = (sjt_dot635)->m00;
#line 61
    sjt_dot636 = _parent;
#line 69
    sjt_math1186 = (sjt_dot636)->m12;
#line 69
    sjt_math1183 = sjt_math1185 * sjt_math1186;
#line 61
    sjt_dot637 = _parent;
#line 69
    sjt_math1184 = (sjt_dot637)->m33;
#line 69
    sjt_math1154 = sjt_math1183 * sjt_math1184;
#line 69
    sjv_t.m12 = sjt_math1153 - sjt_math1154;
#line 61
    sjt_dot638 = _parent;
#line 70
    sjt_math1199 = (sjt_dot638)->m02;
#line 61
    sjt_dot639 = _parent;
#line 70
    sjt_math1200 = (sjt_dot639)->m13;
#line 70
    sjt_math1197 = sjt_math1199 * sjt_math1200;
#line 61
    sjt_dot640 = _parent;
#line 70
    sjt_math1198 = (sjt_dot640)->m20;
#line 70
    sjt_math1195 = sjt_math1197 * sjt_math1198;
#line 61
    sjt_dot641 = _parent;
#line 70
    sjt_math1203 = (sjt_dot641)->m03;
#line 61
    sjt_dot642 = _parent;
#line 70
    sjt_math1204 = (sjt_dot642)->m12;
#line 70
    sjt_math1201 = sjt_math1203 * sjt_math1204;
#line 61
    sjt_dot643 = _parent;
#line 70
    sjt_math1202 = (sjt_dot643)->m20;
#line 70
    sjt_math1196 = sjt_math1201 * sjt_math1202;
#line 70
    sjt_math1193 = sjt_math1195 - sjt_math1196;
#line 61
    sjt_dot644 = _parent;
#line 70
    sjt_math1207 = (sjt_dot644)->m03;
#line 61
    sjt_dot645 = _parent;
#line 70
    sjt_math1208 = (sjt_dot645)->m10;
#line 70
    sjt_math1205 = sjt_math1207 * sjt_math1208;
#line 61
    sjt_dot646 = _parent;
#line 70
    sjt_math1206 = (sjt_dot646)->m22;
#line 70
    sjt_math1194 = sjt_math1205 * sjt_math1206;
#line 70
    sjt_math1191 = sjt_math1193 + sjt_math1194;
#line 61
    sjt_dot647 = _parent;
#line 70
    sjt_math1211 = (sjt_dot647)->m00;
#line 61
    sjt_dot648 = _parent;
#line 70
    sjt_math1212 = (sjt_dot648)->m13;
#line 70
    sjt_math1209 = sjt_math1211 * sjt_math1212;
#line 61
    sjt_dot649 = _parent;
#line 70
    sjt_math1210 = (sjt_dot649)->m22;
#line 70
    sjt_math1192 = sjt_math1209 * sjt_math1210;
#line 70
    sjt_math1189 = sjt_math1191 - sjt_math1192;
#line 61
    sjt_dot650 = _parent;
#line 70
    sjt_math1215 = (sjt_dot650)->m02;
#line 61
    sjt_dot651 = _parent;
#line 70
    sjt_math1216 = (sjt_dot651)->m10;
#line 70
    sjt_math1213 = sjt_math1215 * sjt_math1216;
#line 61
    sjt_dot652 = _parent;
#line 70
    sjt_math1214 = (sjt_dot652)->m23;
#line 70
    sjt_math1190 = sjt_math1213 * sjt_math1214;
#line 70
    sjt_math1187 = sjt_math1189 - sjt_math1190;
#line 61
    sjt_dot653 = _parent;
#line 70
    sjt_math1219 = (sjt_dot653)->m00;
#line 61
    sjt_dot654 = _parent;
#line 70
    sjt_math1220 = (sjt_dot654)->m12;
#line 70
    sjt_math1217 = sjt_math1219 * sjt_math1220;
#line 61
    sjt_dot655 = _parent;
#line 70
    sjt_math1218 = (sjt_dot655)->m23;
#line 70
    sjt_math1188 = sjt_math1217 * sjt_math1218;
#line 70
    sjv_t.m13 = sjt_math1187 + sjt_math1188;
#line 61
    sjt_dot656 = _parent;
#line 71
    sjt_math1233 = (sjt_dot656)->m11;
#line 61
    sjt_dot657 = _parent;
#line 71
    sjt_math1234 = (sjt_dot657)->m23;
#line 71
    sjt_math1231 = sjt_math1233 * sjt_math1234;
#line 61
    sjt_dot658 = _parent;
#line 71
    sjt_math1232 = (sjt_dot658)->m30;
#line 71
    sjt_math1229 = sjt_math1231 * sjt_math1232;
#line 61
    sjt_dot659 = _parent;
#line 71
    sjt_math1237 = (sjt_dot659)->m13;
#line 61
    sjt_dot660 = _parent;
#line 71
    sjt_math1238 = (sjt_dot660)->m21;
#line 71
    sjt_math1235 = sjt_math1237 * sjt_math1238;
#line 61
    sjt_dot661 = _parent;
#line 71
    sjt_math1236 = (sjt_dot661)->m30;
#line 71
    sjt_math1230 = sjt_math1235 * sjt_math1236;
#line 71
    sjt_math1227 = sjt_math1229 - sjt_math1230;
#line 61
    sjt_dot662 = _parent;
#line 71
    sjt_math1241 = (sjt_dot662)->m13;
#line 61
    sjt_dot663 = _parent;
#line 71
    sjt_math1242 = (sjt_dot663)->m20;
#line 71
    sjt_math1239 = sjt_math1241 * sjt_math1242;
#line 61
    sjt_dot664 = _parent;
#line 71
    sjt_math1240 = (sjt_dot664)->m31;
#line 71
    sjt_math1228 = sjt_math1239 * sjt_math1240;
#line 71
    sjt_math1225 = sjt_math1227 + sjt_math1228;
#line 61
    sjt_dot665 = _parent;
#line 71
    sjt_math1245 = (sjt_dot665)->m10;
#line 61
    sjt_dot666 = _parent;
#line 71
    sjt_math1246 = (sjt_dot666)->m23;
#line 71
    sjt_math1243 = sjt_math1245 * sjt_math1246;
#line 61
    sjt_dot667 = _parent;
#line 71
    sjt_math1244 = (sjt_dot667)->m31;
#line 71
    sjt_math1226 = sjt_math1243 * sjt_math1244;
#line 71
    sjt_math1223 = sjt_math1225 - sjt_math1226;
#line 61
    sjt_dot668 = _parent;
#line 71
    sjt_math1249 = (sjt_dot668)->m11;
#line 61
    sjt_dot669 = _parent;
#line 71
    sjt_math1250 = (sjt_dot669)->m20;
#line 71
    sjt_math1247 = sjt_math1249 * sjt_math1250;
#line 61
    sjt_dot670 = _parent;
#line 71
    sjt_math1248 = (sjt_dot670)->m33;
#line 71
    sjt_math1224 = sjt_math1247 * sjt_math1248;
#line 71
    sjt_math1221 = sjt_math1223 - sjt_math1224;
#line 61
    sjt_dot671 = _parent;
#line 71
    sjt_math1253 = (sjt_dot671)->m10;
#line 61
    sjt_dot672 = _parent;
#line 71
    sjt_math1254 = (sjt_dot672)->m21;
#line 71
    sjt_math1251 = sjt_math1253 * sjt_math1254;
#line 61
    sjt_dot673 = _parent;
#line 71
    sjt_math1252 = (sjt_dot673)->m33;
#line 71
    sjt_math1222 = sjt_math1251 * sjt_math1252;
#line 71
    sjv_t.m20 = sjt_math1221 + sjt_math1222;
#line 61
    sjt_dot674 = _parent;
#line 72
    sjt_math1267 = (sjt_dot674)->m03;
#line 61
    sjt_dot675 = _parent;
#line 72
    sjt_math1268 = (sjt_dot675)->m21;
#line 72
    sjt_math1265 = sjt_math1267 * sjt_math1268;
#line 61
    sjt_dot676 = _parent;
#line 72
    sjt_math1266 = (sjt_dot676)->m30;
#line 72
    sjt_math1263 = sjt_math1265 * sjt_math1266;
#line 61
    sjt_dot677 = _parent;
#line 72
    sjt_math1271 = (sjt_dot677)->m01;
#line 61
    sjt_dot678 = _parent;
#line 72
    sjt_math1272 = (sjt_dot678)->m23;
#line 72
    sjt_math1269 = sjt_math1271 * sjt_math1272;
#line 61
    sjt_dot679 = _parent;
#line 72
    sjt_math1270 = (sjt_dot679)->m30;
#line 72
    sjt_math1264 = sjt_math1269 * sjt_math1270;
#line 72
    sjt_math1261 = sjt_math1263 - sjt_math1264;
#line 61
    sjt_dot680 = _parent;
#line 72
    sjt_math1275 = (sjt_dot680)->m03;
#line 61
    sjt_dot681 = _parent;
#line 72
    sjt_math1276 = (sjt_dot681)->m20;
#line 72
    sjt_math1273 = sjt_math1275 * sjt_math1276;
#line 61
    sjt_dot682 = _parent;
#line 72
    sjt_math1274 = (sjt_dot682)->m31;
#line 72
    sjt_math1262 = sjt_math1273 * sjt_math1274;
#line 72
    sjt_math1259 = sjt_math1261 - sjt_math1262;
#line 61
    sjt_dot683 = _parent;
#line 72
    sjt_math1279 = (sjt_dot683)->m00;
#line 61
    sjt_dot684 = _parent;
#line 72
    sjt_math1280 = (sjt_dot684)->m23;
#line 72
    sjt_math1277 = sjt_math1279 * sjt_math1280;
#line 61
    sjt_dot685 = _parent;
#line 72
    sjt_math1278 = (sjt_dot685)->m31;
#line 72
    sjt_math1260 = sjt_math1277 * sjt_math1278;
#line 72
    sjt_math1257 = sjt_math1259 + sjt_math1260;
#line 61
    sjt_dot686 = _parent;
#line 72
    sjt_math1283 = (sjt_dot686)->m01;
#line 61
    sjt_dot687 = _parent;
#line 72
    sjt_math1284 = (sjt_dot687)->m20;
#line 72
    sjt_math1281 = sjt_math1283 * sjt_math1284;
#line 61
    sjt_dot688 = _parent;
#line 72
    sjt_math1282 = (sjt_dot688)->m33;
#line 72
    sjt_math1258 = sjt_math1281 * sjt_math1282;
#line 72
    sjt_math1255 = sjt_math1257 + sjt_math1258;
#line 61
    sjt_dot689 = _parent;
#line 72
    sjt_math1287 = (sjt_dot689)->m00;
#line 61
    sjt_dot690 = _parent;
#line 72
    sjt_math1288 = (sjt_dot690)->m21;
#line 72
    sjt_math1285 = sjt_math1287 * sjt_math1288;
#line 61
    sjt_dot691 = _parent;
#line 72
    sjt_math1286 = (sjt_dot691)->m33;
#line 72
    sjt_math1256 = sjt_math1285 * sjt_math1286;
#line 72
    sjv_t.m21 = sjt_math1255 - sjt_math1256;
#line 61
    sjt_dot692 = _parent;
#line 73
    sjt_math1301 = (sjt_dot692)->m01;
#line 61
    sjt_dot693 = _parent;
#line 73
    sjt_math1302 = (sjt_dot693)->m13;
#line 73
    sjt_math1299 = sjt_math1301 * sjt_math1302;
#line 61
    sjt_dot694 = _parent;
#line 73
    sjt_math1300 = (sjt_dot694)->m30;
#line 73
    sjt_math1297 = sjt_math1299 * sjt_math1300;
#line 61
    sjt_dot695 = _parent;
#line 73
    sjt_math1305 = (sjt_dot695)->m03;
#line 61
    sjt_dot696 = _parent;
#line 73
    sjt_math1306 = (sjt_dot696)->m11;
#line 73
    sjt_math1303 = sjt_math1305 * sjt_math1306;
#line 61
    sjt_dot697 = _parent;
#line 73
    sjt_math1304 = (sjt_dot697)->m30;
#line 73
    sjt_math1298 = sjt_math1303 * sjt_math1304;
#line 73
    sjt_math1295 = sjt_math1297 - sjt_math1298;
#line 61
    sjt_dot698 = _parent;
#line 73
    sjt_math1309 = (sjt_dot698)->m03;
#line 61
    sjt_dot699 = _parent;
#line 73
    sjt_math1310 = (sjt_dot699)->m10;
#line 73
    sjt_math1307 = sjt_math1309 * sjt_math1310;
#line 61
    sjt_dot700 = _parent;
#line 73
    sjt_math1308 = (sjt_dot700)->m31;
#line 73
    sjt_math1296 = sjt_math1307 * sjt_math1308;
#line 73
    sjt_math1293 = sjt_math1295 + sjt_math1296;
#line 61
    sjt_dot701 = _parent;
#line 73
    sjt_math1313 = (sjt_dot701)->m00;
#line 61
    sjt_dot702 = _parent;
#line 73
    sjt_math1314 = (sjt_dot702)->m13;
#line 73
    sjt_math1311 = sjt_math1313 * sjt_math1314;
#line 61
    sjt_dot703 = _parent;
#line 73
    sjt_math1312 = (sjt_dot703)->m31;
#line 73
    sjt_math1294 = sjt_math1311 * sjt_math1312;
#line 73
    sjt_math1291 = sjt_math1293 - sjt_math1294;
#line 61
    sjt_dot704 = _parent;
#line 73
    sjt_math1317 = (sjt_dot704)->m01;
#line 61
    sjt_dot705 = _parent;
#line 73
    sjt_math1318 = (sjt_dot705)->m10;
#line 73
    sjt_math1315 = sjt_math1317 * sjt_math1318;
#line 61
    sjt_dot706 = _parent;
#line 73
    sjt_math1316 = (sjt_dot706)->m33;
#line 73
    sjt_math1292 = sjt_math1315 * sjt_math1316;
#line 73
    sjt_math1289 = sjt_math1291 - sjt_math1292;
#line 61
    sjt_dot707 = _parent;
#line 73
    sjt_math1321 = (sjt_dot707)->m00;
#line 61
    sjt_dot708 = _parent;
#line 73
    sjt_math1322 = (sjt_dot708)->m11;
#line 73
    sjt_math1319 = sjt_math1321 * sjt_math1322;
#line 61
    sjt_dot709 = _parent;
#line 73
    sjt_math1320 = (sjt_dot709)->m33;
#line 73
    sjt_math1290 = sjt_math1319 * sjt_math1320;
#line 73
    sjv_t.m22 = sjt_math1289 + sjt_math1290;
#line 61
    sjt_dot710 = _parent;
#line 74
    sjt_math1335 = (sjt_dot710)->m03;
#line 61
    sjt_dot711 = _parent;
#line 74
    sjt_math1336 = (sjt_dot711)->m11;
#line 74
    sjt_math1333 = sjt_math1335 * sjt_math1336;
#line 61
    sjt_dot712 = _parent;
#line 74
    sjt_math1334 = (sjt_dot712)->m20;
#line 74
    sjt_math1331 = sjt_math1333 * sjt_math1334;
#line 61
    sjt_dot713 = _parent;
#line 74
    sjt_math1339 = (sjt_dot713)->m01;
#line 61
    sjt_dot714 = _parent;
#line 74
    sjt_math1340 = (sjt_dot714)->m13;
#line 74
    sjt_math1337 = sjt_math1339 * sjt_math1340;
#line 61
    sjt_dot715 = _parent;
#line 74
    sjt_math1338 = (sjt_dot715)->m20;
#line 74
    sjt_math1332 = sjt_math1337 * sjt_math1338;
#line 74
    sjt_math1329 = sjt_math1331 - sjt_math1332;
#line 61
    sjt_dot716 = _parent;
#line 74
    sjt_math1343 = (sjt_dot716)->m03;
#line 61
    sjt_dot717 = _parent;
#line 74
    sjt_math1344 = (sjt_dot717)->m10;
#line 74
    sjt_math1341 = sjt_math1343 * sjt_math1344;
#line 61
    sjt_dot718 = _parent;
#line 74
    sjt_math1342 = (sjt_dot718)->m21;
#line 74
    sjt_math1330 = sjt_math1341 * sjt_math1342;
#line 74
    sjt_math1327 = sjt_math1329 - sjt_math1330;
#line 61
    sjt_dot719 = _parent;
#line 74
    sjt_math1347 = (sjt_dot719)->m00;
#line 61
    sjt_dot720 = _parent;
#line 74
    sjt_math1348 = (sjt_dot720)->m13;
#line 74
    sjt_math1345 = sjt_math1347 * sjt_math1348;
#line 61
    sjt_dot721 = _parent;
#line 74
    sjt_math1346 = (sjt_dot721)->m21;
#line 74
    sjt_math1328 = sjt_math1345 * sjt_math1346;
#line 74
    sjt_math1325 = sjt_math1327 + sjt_math1328;
#line 61
    sjt_dot722 = _parent;
#line 74
    sjt_math1351 = (sjt_dot722)->m01;
#line 61
    sjt_dot723 = _parent;
#line 74
    sjt_math1352 = (sjt_dot723)->m10;
#line 74
    sjt_math1349 = sjt_math1351 * sjt_math1352;
#line 61
    sjt_dot724 = _parent;
#line 74
    sjt_math1350 = (sjt_dot724)->m23;
#line 74
    sjt_math1326 = sjt_math1349 * sjt_math1350;
#line 74
    sjt_math1323 = sjt_math1325 + sjt_math1326;
#line 61
    sjt_dot725 = _parent;
#line 74
    sjt_math1355 = (sjt_dot725)->m00;
#line 61
    sjt_dot726 = _parent;
#line 74
    sjt_math1356 = (sjt_dot726)->m11;
#line 74
    sjt_math1353 = sjt_math1355 * sjt_math1356;
#line 61
    sjt_dot727 = _parent;
#line 74
    sjt_math1354 = (sjt_dot727)->m23;
#line 74
    sjt_math1324 = sjt_math1353 * sjt_math1354;
#line 74
    sjv_t.m23 = sjt_math1323 - sjt_math1324;
#line 61
    sjt_dot728 = _parent;
#line 75
    sjt_math1369 = (sjt_dot728)->m12;
#line 61
    sjt_dot729 = _parent;
#line 75
    sjt_math1370 = (sjt_dot729)->m21;
#line 75
    sjt_math1367 = sjt_math1369 * sjt_math1370;
#line 61
    sjt_dot730 = _parent;
#line 75
    sjt_math1368 = (sjt_dot730)->m30;
#line 75
    sjt_math1365 = sjt_math1367 * sjt_math1368;
#line 61
    sjt_dot731 = _parent;
#line 75
    sjt_math1373 = (sjt_dot731)->m11;
#line 61
    sjt_dot732 = _parent;
#line 75
    sjt_math1374 = (sjt_dot732)->m22;
#line 75
    sjt_math1371 = sjt_math1373 * sjt_math1374;
#line 61
    sjt_dot733 = _parent;
#line 75
    sjt_math1372 = (sjt_dot733)->m30;
#line 75
    sjt_math1366 = sjt_math1371 * sjt_math1372;
#line 75
    sjt_math1363 = sjt_math1365 - sjt_math1366;
#line 61
    sjt_dot734 = _parent;
#line 75
    sjt_math1377 = (sjt_dot734)->m12;
#line 61
    sjt_dot735 = _parent;
#line 75
    sjt_math1378 = (sjt_dot735)->m20;
#line 75
    sjt_math1375 = sjt_math1377 * sjt_math1378;
#line 61
    sjt_dot736 = _parent;
#line 75
    sjt_math1376 = (sjt_dot736)->m31;
#line 75
    sjt_math1364 = sjt_math1375 * sjt_math1376;
#line 75
    sjt_math1361 = sjt_math1363 - sjt_math1364;
#line 61
    sjt_dot737 = _parent;
#line 75
    sjt_math1381 = (sjt_dot737)->m10;
#line 61
    sjt_dot738 = _parent;
#line 75
    sjt_math1382 = (sjt_dot738)->m22;
#line 75
    sjt_math1379 = sjt_math1381 * sjt_math1382;
#line 61
    sjt_dot739 = _parent;
#line 75
    sjt_math1380 = (sjt_dot739)->m31;
#line 75
    sjt_math1362 = sjt_math1379 * sjt_math1380;
#line 75
    sjt_math1359 = sjt_math1361 + sjt_math1362;
#line 61
    sjt_dot740 = _parent;
#line 75
    sjt_math1385 = (sjt_dot740)->m11;
#line 61
    sjt_dot741 = _parent;
#line 75
    sjt_math1386 = (sjt_dot741)->m20;
#line 75
    sjt_math1383 = sjt_math1385 * sjt_math1386;
#line 61
    sjt_dot742 = _parent;
#line 75
    sjt_math1384 = (sjt_dot742)->m32;
#line 75
    sjt_math1360 = sjt_math1383 * sjt_math1384;
#line 75
    sjt_math1357 = sjt_math1359 + sjt_math1360;
#line 61
    sjt_dot743 = _parent;
#line 75
    sjt_math1389 = (sjt_dot743)->m10;
#line 61
    sjt_dot744 = _parent;
#line 75
    sjt_math1390 = (sjt_dot744)->m21;
#line 75
    sjt_math1387 = sjt_math1389 * sjt_math1390;
#line 61
    sjt_dot745 = _parent;
#line 75
    sjt_math1388 = (sjt_dot745)->m32;
#line 75
    sjt_math1358 = sjt_math1387 * sjt_math1388;
#line 75
    sjv_t.m30 = sjt_math1357 - sjt_math1358;
#line 61
    sjt_dot746 = _parent;
#line 76
    sjt_math1403 = (sjt_dot746)->m01;
#line 61
    sjt_dot747 = _parent;
#line 76
    sjt_math1404 = (sjt_dot747)->m22;
#line 76
    sjt_math1401 = sjt_math1403 * sjt_math1404;
#line 61
    sjt_dot748 = _parent;
#line 76
    sjt_math1402 = (sjt_dot748)->m30;
#line 76
    sjt_math1399 = sjt_math1401 * sjt_math1402;
#line 61
    sjt_dot749 = _parent;
#line 76
    sjt_math1407 = (sjt_dot749)->m02;
#line 61
    sjt_dot750 = _parent;
#line 76
    sjt_math1408 = (sjt_dot750)->m21;
#line 76
    sjt_math1405 = sjt_math1407 * sjt_math1408;
#line 61
    sjt_dot751 = _parent;
#line 76
    sjt_math1406 = (sjt_dot751)->m30;
#line 76
    sjt_math1400 = sjt_math1405 * sjt_math1406;
#line 76
    sjt_math1397 = sjt_math1399 - sjt_math1400;
#line 61
    sjt_dot752 = _parent;
#line 76
    sjt_math1411 = (sjt_dot752)->m02;
#line 61
    sjt_dot753 = _parent;
#line 76
    sjt_math1412 = (sjt_dot753)->m20;
#line 76
    sjt_math1409 = sjt_math1411 * sjt_math1412;
#line 61
    sjt_dot754 = _parent;
#line 76
    sjt_math1410 = (sjt_dot754)->m31;
#line 76
    sjt_math1398 = sjt_math1409 * sjt_math1410;
#line 76
    sjt_math1395 = sjt_math1397 + sjt_math1398;
#line 61
    sjt_dot755 = _parent;
#line 76
    sjt_math1415 = (sjt_dot755)->m00;
#line 61
    sjt_dot756 = _parent;
#line 76
    sjt_math1416 = (sjt_dot756)->m22;
#line 76
    sjt_math1413 = sjt_math1415 * sjt_math1416;
#line 61
    sjt_dot757 = _parent;
#line 76
    sjt_math1414 = (sjt_dot757)->m31;
#line 76
    sjt_math1396 = sjt_math1413 * sjt_math1414;
#line 76
    sjt_math1393 = sjt_math1395 - sjt_math1396;
#line 61
    sjt_dot758 = _parent;
#line 76
    sjt_math1419 = (sjt_dot758)->m01;
#line 61
    sjt_dot759 = _parent;
#line 76
    sjt_math1420 = (sjt_dot759)->m20;
#line 76
    sjt_math1417 = sjt_math1419 * sjt_math1420;
#line 61
    sjt_dot760 = _parent;
#line 76
    sjt_math1418 = (sjt_dot760)->m32;
#line 76
    sjt_math1394 = sjt_math1417 * sjt_math1418;
#line 76
    sjt_math1391 = sjt_math1393 - sjt_math1394;
#line 61
    sjt_dot761 = _parent;
#line 76
    sjt_math1423 = (sjt_dot761)->m00;
#line 61
    sjt_dot762 = _parent;
#line 76
    sjt_math1424 = (sjt_dot762)->m21;
#line 76
    sjt_math1421 = sjt_math1423 * sjt_math1424;
#line 61
    sjt_dot763 = _parent;
#line 76
    sjt_math1422 = (sjt_dot763)->m32;
#line 76
    sjt_math1392 = sjt_math1421 * sjt_math1422;
#line 76
    sjv_t.m31 = sjt_math1391 + sjt_math1392;
#line 61
    sjt_dot764 = _parent;
#line 77
    sjt_math1437 = (sjt_dot764)->m02;
#line 61
    sjt_dot765 = _parent;
#line 77
    sjt_math1438 = (sjt_dot765)->m11;
#line 77
    sjt_math1435 = sjt_math1437 * sjt_math1438;
#line 61
    sjt_dot766 = _parent;
#line 77
    sjt_math1436 = (sjt_dot766)->m30;
#line 77
    sjt_math1433 = sjt_math1435 * sjt_math1436;
#line 61
    sjt_dot767 = _parent;
#line 77
    sjt_math1441 = (sjt_dot767)->m01;
#line 61
    sjt_dot768 = _parent;
#line 77
    sjt_math1442 = (sjt_dot768)->m12;
#line 77
    sjt_math1439 = sjt_math1441 * sjt_math1442;
#line 61
    sjt_dot769 = _parent;
#line 77
    sjt_math1440 = (sjt_dot769)->m30;
#line 77
    sjt_math1434 = sjt_math1439 * sjt_math1440;
#line 77
    sjt_math1431 = sjt_math1433 - sjt_math1434;
#line 61
    sjt_dot770 = _parent;
#line 77
    sjt_math1445 = (sjt_dot770)->m02;
#line 61
    sjt_dot771 = _parent;
#line 77
    sjt_math1446 = (sjt_dot771)->m10;
#line 77
    sjt_math1443 = sjt_math1445 * sjt_math1446;
#line 61
    sjt_dot772 = _parent;
#line 77
    sjt_math1444 = (sjt_dot772)->m31;
#line 77
    sjt_math1432 = sjt_math1443 * sjt_math1444;
#line 77
    sjt_math1429 = sjt_math1431 - sjt_math1432;
#line 61
    sjt_dot773 = _parent;
#line 77
    sjt_math1449 = (sjt_dot773)->m00;
#line 61
    sjt_dot774 = _parent;
#line 77
    sjt_math1450 = (sjt_dot774)->m12;
#line 77
    sjt_math1447 = sjt_math1449 * sjt_math1450;
#line 61
    sjt_dot775 = _parent;
#line 77
    sjt_math1448 = (sjt_dot775)->m31;
#line 77
    sjt_math1430 = sjt_math1447 * sjt_math1448;
#line 77
    sjt_math1427 = sjt_math1429 + sjt_math1430;
#line 61
    sjt_dot776 = _parent;
#line 77
    sjt_math1453 = (sjt_dot776)->m01;
#line 61
    sjt_dot777 = _parent;
#line 77
    sjt_math1454 = (sjt_dot777)->m10;
#line 77
    sjt_math1451 = sjt_math1453 * sjt_math1454;
#line 61
    sjt_dot778 = _parent;
#line 77
    sjt_math1452 = (sjt_dot778)->m32;
#line 77
    sjt_math1428 = sjt_math1451 * sjt_math1452;
#line 77
    sjt_math1425 = sjt_math1427 + sjt_math1428;
#line 61
    sjt_dot779 = _parent;
#line 77
    sjt_math1457 = (sjt_dot779)->m00;
#line 61
    sjt_dot780 = _parent;
#line 77
    sjt_math1458 = (sjt_dot780)->m11;
#line 77
    sjt_math1455 = sjt_math1457 * sjt_math1458;
#line 61
    sjt_dot781 = _parent;
#line 77
    sjt_math1456 = (sjt_dot781)->m32;
#line 77
    sjt_math1426 = sjt_math1455 * sjt_math1456;
#line 77
    sjv_t.m32 = sjt_math1425 - sjt_math1426;
#line 61
    sjt_dot782 = _parent;
#line 78
    sjt_math1471 = (sjt_dot782)->m01;
#line 61
    sjt_dot783 = _parent;
#line 78
    sjt_math1472 = (sjt_dot783)->m12;
#line 78
    sjt_math1469 = sjt_math1471 * sjt_math1472;
#line 61
    sjt_dot784 = _parent;
#line 78
    sjt_math1470 = (sjt_dot784)->m20;
#line 78
    sjt_math1467 = sjt_math1469 * sjt_math1470;
#line 61
    sjt_dot785 = _parent;
#line 78
    sjt_math1475 = (sjt_dot785)->m02;
#line 61
    sjt_dot786 = _parent;
#line 78
    sjt_math1476 = (sjt_dot786)->m11;
#line 78
    sjt_math1473 = sjt_math1475 * sjt_math1476;
#line 61
    sjt_dot787 = _parent;
#line 78
    sjt_math1474 = (sjt_dot787)->m20;
#line 78
    sjt_math1468 = sjt_math1473 * sjt_math1474;
#line 78
    sjt_math1465 = sjt_math1467 - sjt_math1468;
#line 61
    sjt_dot788 = _parent;
#line 78
    sjt_math1479 = (sjt_dot788)->m02;
#line 61
    sjt_dot789 = _parent;
#line 78
    sjt_math1480 = (sjt_dot789)->m10;
#line 78
    sjt_math1477 = sjt_math1479 * sjt_math1480;
#line 61
    sjt_dot790 = _parent;
#line 78
    sjt_math1478 = (sjt_dot790)->m21;
#line 78
    sjt_math1466 = sjt_math1477 * sjt_math1478;
#line 78
    sjt_math1463 = sjt_math1465 + sjt_math1466;
#line 61
    sjt_dot791 = _parent;
#line 78
    sjt_math1483 = (sjt_dot791)->m00;
#line 61
    sjt_dot792 = _parent;
#line 78
    sjt_math1484 = (sjt_dot792)->m12;
#line 78
    sjt_math1481 = sjt_math1483 * sjt_math1484;
#line 61
    sjt_dot793 = _parent;
#line 78
    sjt_math1482 = (sjt_dot793)->m21;
#line 78
    sjt_math1464 = sjt_math1481 * sjt_math1482;
#line 78
    sjt_math1461 = sjt_math1463 - sjt_math1464;
#line 61
    sjt_dot794 = _parent;
#line 78
    sjt_math1487 = (sjt_dot794)->m01;
#line 61
    sjt_dot795 = _parent;
#line 78
    sjt_math1488 = (sjt_dot795)->m10;
#line 78
    sjt_math1485 = sjt_math1487 * sjt_math1488;
#line 61
    sjt_dot796 = _parent;
#line 78
    sjt_math1486 = (sjt_dot796)->m22;
#line 78
    sjt_math1462 = sjt_math1485 * sjt_math1486;
#line 78
    sjt_math1459 = sjt_math1461 - sjt_math1462;
#line 61
    sjt_dot797 = _parent;
#line 78
    sjt_math1491 = (sjt_dot797)->m00;
#line 61
    sjt_dot798 = _parent;
#line 78
    sjt_math1492 = (sjt_dot798)->m11;
#line 78
    sjt_math1489 = sjt_math1491 * sjt_math1492;
#line 61
    sjt_dot799 = _parent;
#line 78
    sjt_math1490 = (sjt_dot799)->m22;
#line 78
    sjt_math1460 = sjt_math1489 * sjt_math1490;
#line 78
    sjv_t.m33 = sjt_math1459 + sjt_math1460;
#line 0 ""
    sjf_mat4(&sjv_t);
#line 40 ".\..\lib\ui\mat4.sj"
    sjt_parent54 = &sjv_t;
#line 81
    sjt_math1557 = 1.0f;
#line 0 ""
    sjf_mat4_determinant(_parent, &sjt_math1558);
#line 81 ".\..\lib\ui\mat4.sj"
    sjt_functionParam79 = sjt_math1557 / sjt_math1558;
#line 0 ""
    sjf_mat4_multiply_f32(sjt_parent54, sjt_functionParam79, _return);

    sjf_mat4_destroy(&sjv_t);
}

void sjf_mat4_invert_heap(sjs_mat4* _parent, sjs_mat4_heap** _return) {
    sjs_mat4* sjt_dot1000;
    sjs_mat4* sjt_dot1001;
    sjs_mat4* sjt_dot1002;
    sjs_mat4* sjt_dot1003;
    sjs_mat4* sjt_dot1004;
    sjs_mat4* sjt_dot1005;
    sjs_mat4* sjt_dot1006;
    sjs_mat4* sjt_dot1007;
    sjs_mat4* sjt_dot1008;
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
    float sjt_functionParam80;
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
    float sjt_math2289;
    float sjt_math2290;
    float sjt_math2291;
    float sjt_math2292;
    float sjt_math2293;
    float sjt_math2294;
    sjs_mat4* sjt_parent55;
    sjs_mat4 sjv_t;

#line 61 ".\..\lib\ui\mat4.sj"
    sjt_dot928 = _parent;
#line 63
    sjt_math1761 = (sjt_dot928)->m12;
#line 61
    sjt_dot929 = _parent;
#line 63
    sjt_math1762 = (sjt_dot929)->m23;
#line 63
    sjt_math1759 = sjt_math1761 * sjt_math1762;
#line 61
    sjt_dot930 = _parent;
#line 63
    sjt_math1760 = (sjt_dot930)->m31;
#line 63
    sjt_math1757 = sjt_math1759 * sjt_math1760;
#line 61
    sjt_dot931 = _parent;
#line 63
    sjt_math1765 = (sjt_dot931)->m13;
#line 61
    sjt_dot932 = _parent;
#line 63
    sjt_math1766 = (sjt_dot932)->m22;
#line 63
    sjt_math1763 = sjt_math1765 * sjt_math1766;
#line 61
    sjt_dot933 = _parent;
#line 63
    sjt_math1764 = (sjt_dot933)->m31;
#line 63
    sjt_math1758 = sjt_math1763 * sjt_math1764;
#line 63
    sjt_math1755 = sjt_math1757 - sjt_math1758;
#line 61
    sjt_dot934 = _parent;
#line 63
    sjt_math1769 = (sjt_dot934)->m13;
#line 61
    sjt_dot935 = _parent;
#line 63
    sjt_math1770 = (sjt_dot935)->m21;
#line 63
    sjt_math1767 = sjt_math1769 * sjt_math1770;
#line 61
    sjt_dot936 = _parent;
#line 63
    sjt_math1768 = (sjt_dot936)->m32;
#line 63
    sjt_math1756 = sjt_math1767 * sjt_math1768;
#line 63
    sjt_math1753 = sjt_math1755 + sjt_math1756;
#line 61
    sjt_dot937 = _parent;
#line 63
    sjt_math1773 = (sjt_dot937)->m11;
#line 61
    sjt_dot938 = _parent;
#line 63
    sjt_math1774 = (sjt_dot938)->m23;
#line 63
    sjt_math1771 = sjt_math1773 * sjt_math1774;
#line 61
    sjt_dot939 = _parent;
#line 63
    sjt_math1772 = (sjt_dot939)->m32;
#line 63
    sjt_math1754 = sjt_math1771 * sjt_math1772;
#line 63
    sjt_math1751 = sjt_math1753 - sjt_math1754;
#line 61
    sjt_dot940 = _parent;
#line 63
    sjt_math1777 = (sjt_dot940)->m12;
#line 61
    sjt_dot941 = _parent;
#line 63
    sjt_math1778 = (sjt_dot941)->m21;
#line 63
    sjt_math1775 = sjt_math1777 * sjt_math1778;
#line 61
    sjt_dot942 = _parent;
#line 63
    sjt_math1776 = (sjt_dot942)->m33;
#line 63
    sjt_math1752 = sjt_math1775 * sjt_math1776;
#line 63
    sjt_math1749 = sjt_math1751 - sjt_math1752;
#line 61
    sjt_dot943 = _parent;
#line 63
    sjt_math1781 = (sjt_dot943)->m11;
#line 61
    sjt_dot944 = _parent;
#line 63
    sjt_math1782 = (sjt_dot944)->m22;
#line 63
    sjt_math1779 = sjt_math1781 * sjt_math1782;
#line 61
    sjt_dot945 = _parent;
#line 63
    sjt_math1780 = (sjt_dot945)->m33;
#line 63
    sjt_math1750 = sjt_math1779 * sjt_math1780;
#line 63
    sjv_t.m00 = sjt_math1749 + sjt_math1750;
#line 61
    sjt_dot946 = _parent;
#line 64
    sjt_math1795 = (sjt_dot946)->m03;
#line 61
    sjt_dot947 = _parent;
#line 64
    sjt_math1796 = (sjt_dot947)->m22;
#line 64
    sjt_math1793 = sjt_math1795 * sjt_math1796;
#line 61
    sjt_dot948 = _parent;
#line 64
    sjt_math1794 = (sjt_dot948)->m31;
#line 64
    sjt_math1791 = sjt_math1793 * sjt_math1794;
#line 61
    sjt_dot949 = _parent;
#line 64
    sjt_math1799 = (sjt_dot949)->m02;
#line 61
    sjt_dot950 = _parent;
#line 64
    sjt_math1800 = (sjt_dot950)->m23;
#line 64
    sjt_math1797 = sjt_math1799 * sjt_math1800;
#line 61
    sjt_dot951 = _parent;
#line 64
    sjt_math1798 = (sjt_dot951)->m31;
#line 64
    sjt_math1792 = sjt_math1797 * sjt_math1798;
#line 64
    sjt_math1789 = sjt_math1791 - sjt_math1792;
#line 61
    sjt_dot952 = _parent;
#line 64
    sjt_math1803 = (sjt_dot952)->m03;
#line 61
    sjt_dot953 = _parent;
#line 64
    sjt_math1804 = (sjt_dot953)->m21;
#line 64
    sjt_math1801 = sjt_math1803 * sjt_math1804;
#line 61
    sjt_dot954 = _parent;
#line 64
    sjt_math1802 = (sjt_dot954)->m32;
#line 64
    sjt_math1790 = sjt_math1801 * sjt_math1802;
#line 64
    sjt_math1787 = sjt_math1789 - sjt_math1790;
#line 61
    sjt_dot955 = _parent;
#line 64
    sjt_math1807 = (sjt_dot955)->m01;
#line 61
    sjt_dot956 = _parent;
#line 64
    sjt_math1808 = (sjt_dot956)->m23;
#line 64
    sjt_math1805 = sjt_math1807 * sjt_math1808;
#line 61
    sjt_dot957 = _parent;
#line 64
    sjt_math1806 = (sjt_dot957)->m32;
#line 64
    sjt_math1788 = sjt_math1805 * sjt_math1806;
#line 64
    sjt_math1785 = sjt_math1787 + sjt_math1788;
#line 61
    sjt_dot958 = _parent;
#line 64
    sjt_math1811 = (sjt_dot958)->m02;
#line 61
    sjt_dot959 = _parent;
#line 64
    sjt_math1812 = (sjt_dot959)->m21;
#line 64
    sjt_math1809 = sjt_math1811 * sjt_math1812;
#line 61
    sjt_dot960 = _parent;
#line 64
    sjt_math1810 = (sjt_dot960)->m33;
#line 64
    sjt_math1786 = sjt_math1809 * sjt_math1810;
#line 64
    sjt_math1783 = sjt_math1785 + sjt_math1786;
#line 61
    sjt_dot961 = _parent;
#line 64
    sjt_math1815 = (sjt_dot961)->m01;
#line 61
    sjt_dot962 = _parent;
#line 64
    sjt_math1816 = (sjt_dot962)->m22;
#line 64
    sjt_math1813 = sjt_math1815 * sjt_math1816;
#line 61
    sjt_dot963 = _parent;
#line 64
    sjt_math1814 = (sjt_dot963)->m33;
#line 64
    sjt_math1784 = sjt_math1813 * sjt_math1814;
#line 64
    sjv_t.m01 = sjt_math1783 - sjt_math1784;
#line 61
    sjt_dot964 = _parent;
#line 65
    sjt_math1829 = (sjt_dot964)->m02;
#line 61
    sjt_dot965 = _parent;
#line 65
    sjt_math1830 = (sjt_dot965)->m13;
#line 65
    sjt_math1827 = sjt_math1829 * sjt_math1830;
#line 61
    sjt_dot966 = _parent;
#line 65
    sjt_math1828 = (sjt_dot966)->m31;
#line 65
    sjt_math1825 = sjt_math1827 * sjt_math1828;
#line 61
    sjt_dot967 = _parent;
#line 65
    sjt_math1833 = (sjt_dot967)->m03;
#line 61
    sjt_dot968 = _parent;
#line 65
    sjt_math1834 = (sjt_dot968)->m12;
#line 65
    sjt_math1831 = sjt_math1833 * sjt_math1834;
#line 61
    sjt_dot969 = _parent;
#line 65
    sjt_math1832 = (sjt_dot969)->m31;
#line 65
    sjt_math1826 = sjt_math1831 * sjt_math1832;
#line 65
    sjt_math1823 = sjt_math1825 - sjt_math1826;
#line 61
    sjt_dot970 = _parent;
#line 65
    sjt_math1837 = (sjt_dot970)->m03;
#line 61
    sjt_dot971 = _parent;
#line 65
    sjt_math1838 = (sjt_dot971)->m11;
#line 65
    sjt_math1835 = sjt_math1837 * sjt_math1838;
#line 61
    sjt_dot972 = _parent;
#line 65
    sjt_math1836 = (sjt_dot972)->m32;
#line 65
    sjt_math1824 = sjt_math1835 * sjt_math1836;
#line 65
    sjt_math1821 = sjt_math1823 + sjt_math1824;
#line 61
    sjt_dot973 = _parent;
#line 65
    sjt_math1841 = (sjt_dot973)->m01;
#line 61
    sjt_dot974 = _parent;
#line 65
    sjt_math1842 = (sjt_dot974)->m13;
#line 65
    sjt_math1839 = sjt_math1841 * sjt_math1842;
#line 61
    sjt_dot975 = _parent;
#line 65
    sjt_math1840 = (sjt_dot975)->m32;
#line 65
    sjt_math1822 = sjt_math1839 * sjt_math1840;
#line 65
    sjt_math1819 = sjt_math1821 - sjt_math1822;
#line 61
    sjt_dot976 = _parent;
#line 65
    sjt_math1845 = (sjt_dot976)->m02;
#line 61
    sjt_dot977 = _parent;
#line 65
    sjt_math1846 = (sjt_dot977)->m11;
#line 65
    sjt_math1843 = sjt_math1845 * sjt_math1846;
#line 61
    sjt_dot978 = _parent;
#line 65
    sjt_math1844 = (sjt_dot978)->m33;
#line 65
    sjt_math1820 = sjt_math1843 * sjt_math1844;
#line 65
    sjt_math1817 = sjt_math1819 - sjt_math1820;
#line 61
    sjt_dot979 = _parent;
#line 65
    sjt_math1849 = (sjt_dot979)->m01;
#line 61
    sjt_dot980 = _parent;
#line 65
    sjt_math1850 = (sjt_dot980)->m12;
#line 65
    sjt_math1847 = sjt_math1849 * sjt_math1850;
#line 61
    sjt_dot981 = _parent;
#line 65
    sjt_math1848 = (sjt_dot981)->m33;
#line 65
    sjt_math1818 = sjt_math1847 * sjt_math1848;
#line 65
    sjv_t.m02 = sjt_math1817 + sjt_math1818;
#line 61
    sjt_dot982 = _parent;
#line 66
    sjt_math1863 = (sjt_dot982)->m03;
#line 61
    sjt_dot983 = _parent;
#line 66
    sjt_math1864 = (sjt_dot983)->m12;
#line 66
    sjt_math1861 = sjt_math1863 * sjt_math1864;
#line 61
    sjt_dot984 = _parent;
#line 66
    sjt_math1862 = (sjt_dot984)->m21;
#line 66
    sjt_math1859 = sjt_math1861 * sjt_math1862;
#line 61
    sjt_dot985 = _parent;
#line 66
    sjt_math1867 = (sjt_dot985)->m02;
#line 61
    sjt_dot986 = _parent;
#line 66
    sjt_math1868 = (sjt_dot986)->m13;
#line 66
    sjt_math1865 = sjt_math1867 * sjt_math1868;
#line 61
    sjt_dot987 = _parent;
#line 66
    sjt_math1866 = (sjt_dot987)->m21;
#line 66
    sjt_math1860 = sjt_math1865 * sjt_math1866;
#line 66
    sjt_math1857 = sjt_math1859 - sjt_math1860;
#line 61
    sjt_dot988 = _parent;
#line 66
    sjt_math1871 = (sjt_dot988)->m03;
#line 61
    sjt_dot989 = _parent;
#line 66
    sjt_math1872 = (sjt_dot989)->m11;
#line 66
    sjt_math1869 = sjt_math1871 * sjt_math1872;
#line 61
    sjt_dot990 = _parent;
#line 66
    sjt_math1870 = (sjt_dot990)->m22;
#line 66
    sjt_math1858 = sjt_math1869 * sjt_math1870;
#line 66
    sjt_math1855 = sjt_math1857 - sjt_math1858;
#line 61
    sjt_dot991 = _parent;
#line 66
    sjt_math1875 = (sjt_dot991)->m01;
#line 61
    sjt_dot992 = _parent;
#line 66
    sjt_math1876 = (sjt_dot992)->m13;
#line 66
    sjt_math1873 = sjt_math1875 * sjt_math1876;
#line 61
    sjt_dot993 = _parent;
#line 66
    sjt_math1874 = (sjt_dot993)->m22;
#line 66
    sjt_math1856 = sjt_math1873 * sjt_math1874;
#line 66
    sjt_math1853 = sjt_math1855 + sjt_math1856;
#line 61
    sjt_dot994 = _parent;
#line 66
    sjt_math1879 = (sjt_dot994)->m02;
#line 61
    sjt_dot995 = _parent;
#line 66
    sjt_math1880 = (sjt_dot995)->m11;
#line 66
    sjt_math1877 = sjt_math1879 * sjt_math1880;
#line 61
    sjt_dot996 = _parent;
#line 66
    sjt_math1878 = (sjt_dot996)->m23;
#line 66
    sjt_math1854 = sjt_math1877 * sjt_math1878;
#line 66
    sjt_math1851 = sjt_math1853 + sjt_math1854;
#line 61
    sjt_dot997 = _parent;
#line 66
    sjt_math1883 = (sjt_dot997)->m01;
#line 61
    sjt_dot998 = _parent;
#line 66
    sjt_math1884 = (sjt_dot998)->m12;
#line 66
    sjt_math1881 = sjt_math1883 * sjt_math1884;
#line 61
    sjt_dot999 = _parent;
#line 66
    sjt_math1882 = (sjt_dot999)->m23;
#line 66
    sjt_math1852 = sjt_math1881 * sjt_math1882;
#line 66
    sjv_t.m03 = sjt_math1851 - sjt_math1852;
#line 61
    sjt_dot1000 = _parent;
#line 67
    sjt_math1897 = (sjt_dot1000)->m13;
#line 61
    sjt_dot1001 = _parent;
#line 67
    sjt_math1898 = (sjt_dot1001)->m22;
#line 67
    sjt_math1895 = sjt_math1897 * sjt_math1898;
#line 61
    sjt_dot1002 = _parent;
#line 67
    sjt_math1896 = (sjt_dot1002)->m30;
#line 67
    sjt_math1893 = sjt_math1895 * sjt_math1896;
#line 61
    sjt_dot1003 = _parent;
#line 67
    sjt_math1901 = (sjt_dot1003)->m12;
#line 61
    sjt_dot1004 = _parent;
#line 67
    sjt_math1902 = (sjt_dot1004)->m23;
#line 67
    sjt_math1899 = sjt_math1901 * sjt_math1902;
#line 61
    sjt_dot1005 = _parent;
#line 67
    sjt_math1900 = (sjt_dot1005)->m30;
#line 67
    sjt_math1894 = sjt_math1899 * sjt_math1900;
#line 67
    sjt_math1891 = sjt_math1893 - sjt_math1894;
#line 61
    sjt_dot1006 = _parent;
#line 67
    sjt_math1905 = (sjt_dot1006)->m13;
#line 61
    sjt_dot1007 = _parent;
#line 67
    sjt_math1906 = (sjt_dot1007)->m20;
#line 67
    sjt_math1903 = sjt_math1905 * sjt_math1906;
#line 61
    sjt_dot1008 = _parent;
#line 67
    sjt_math1904 = (sjt_dot1008)->m32;
#line 67
    sjt_math1892 = sjt_math1903 * sjt_math1904;
#line 67
    sjt_math1889 = sjt_math1891 - sjt_math1892;
#line 61
    sjt_dot1009 = _parent;
#line 67
    sjt_math1909 = (sjt_dot1009)->m10;
#line 61
    sjt_dot1010 = _parent;
#line 67
    sjt_math1910 = (sjt_dot1010)->m23;
#line 67
    sjt_math1907 = sjt_math1909 * sjt_math1910;
#line 61
    sjt_dot1011 = _parent;
#line 67
    sjt_math1908 = (sjt_dot1011)->m32;
#line 67
    sjt_math1890 = sjt_math1907 * sjt_math1908;
#line 67
    sjt_math1887 = sjt_math1889 + sjt_math1890;
#line 61
    sjt_dot1012 = _parent;
#line 67
    sjt_math1913 = (sjt_dot1012)->m12;
#line 61
    sjt_dot1013 = _parent;
#line 67
    sjt_math1914 = (sjt_dot1013)->m20;
#line 67
    sjt_math1911 = sjt_math1913 * sjt_math1914;
#line 61
    sjt_dot1014 = _parent;
#line 67
    sjt_math1912 = (sjt_dot1014)->m33;
#line 67
    sjt_math1888 = sjt_math1911 * sjt_math1912;
#line 67
    sjt_math1885 = sjt_math1887 + sjt_math1888;
#line 61
    sjt_dot1015 = _parent;
#line 67
    sjt_math1917 = (sjt_dot1015)->m10;
#line 61
    sjt_dot1016 = _parent;
#line 67
    sjt_math1918 = (sjt_dot1016)->m22;
#line 67
    sjt_math1915 = sjt_math1917 * sjt_math1918;
#line 61
    sjt_dot1017 = _parent;
#line 67
    sjt_math1916 = (sjt_dot1017)->m33;
#line 67
    sjt_math1886 = sjt_math1915 * sjt_math1916;
#line 67
    sjv_t.m10 = sjt_math1885 - sjt_math1886;
#line 61
    sjt_dot1018 = _parent;
#line 68
    sjt_math1931 = (sjt_dot1018)->m02;
#line 61
    sjt_dot1019 = _parent;
#line 68
    sjt_math1932 = (sjt_dot1019)->m23;
#line 68
    sjt_math1929 = sjt_math1931 * sjt_math1932;
#line 61
    sjt_dot1020 = _parent;
#line 68
    sjt_math1930 = (sjt_dot1020)->m30;
#line 68
    sjt_math1927 = sjt_math1929 * sjt_math1930;
#line 61
    sjt_dot1021 = _parent;
#line 68
    sjt_math1935 = (sjt_dot1021)->m03;
#line 61
    sjt_dot1022 = _parent;
#line 68
    sjt_math1936 = (sjt_dot1022)->m22;
#line 68
    sjt_math1933 = sjt_math1935 * sjt_math1936;
#line 61
    sjt_dot1023 = _parent;
#line 68
    sjt_math1934 = (sjt_dot1023)->m30;
#line 68
    sjt_math1928 = sjt_math1933 * sjt_math1934;
#line 68
    sjt_math1925 = sjt_math1927 - sjt_math1928;
#line 61
    sjt_dot1024 = _parent;
#line 68
    sjt_math1939 = (sjt_dot1024)->m03;
#line 61
    sjt_dot1025 = _parent;
#line 68
    sjt_math1940 = (sjt_dot1025)->m20;
#line 68
    sjt_math1937 = sjt_math1939 * sjt_math1940;
#line 61
    sjt_dot1026 = _parent;
#line 68
    sjt_math1938 = (sjt_dot1026)->m32;
#line 68
    sjt_math1926 = sjt_math1937 * sjt_math1938;
#line 68
    sjt_math1923 = sjt_math1925 + sjt_math1926;
#line 61
    sjt_dot1027 = _parent;
#line 68
    sjt_math1943 = (sjt_dot1027)->m00;
#line 61
    sjt_dot1028 = _parent;
#line 68
    sjt_math1944 = (sjt_dot1028)->m23;
#line 68
    sjt_math1941 = sjt_math1943 * sjt_math1944;
#line 61
    sjt_dot1029 = _parent;
#line 68
    sjt_math1942 = (sjt_dot1029)->m32;
#line 68
    sjt_math1924 = sjt_math1941 * sjt_math1942;
#line 68
    sjt_math1921 = sjt_math1923 - sjt_math1924;
#line 61
    sjt_dot1030 = _parent;
#line 68
    sjt_math1947 = (sjt_dot1030)->m02;
#line 61
    sjt_dot1031 = _parent;
#line 68
    sjt_math1948 = (sjt_dot1031)->m20;
#line 68
    sjt_math1945 = sjt_math1947 * sjt_math1948;
#line 61
    sjt_dot1032 = _parent;
#line 68
    sjt_math1946 = (sjt_dot1032)->m33;
#line 68
    sjt_math1922 = sjt_math1945 * sjt_math1946;
#line 68
    sjt_math1919 = sjt_math1921 - sjt_math1922;
#line 61
    sjt_dot1033 = _parent;
#line 68
    sjt_math1951 = (sjt_dot1033)->m00;
#line 61
    sjt_dot1034 = _parent;
#line 68
    sjt_math1952 = (sjt_dot1034)->m22;
#line 68
    sjt_math1949 = sjt_math1951 * sjt_math1952;
#line 61
    sjt_dot1035 = _parent;
#line 68
    sjt_math1950 = (sjt_dot1035)->m33;
#line 68
    sjt_math1920 = sjt_math1949 * sjt_math1950;
#line 68
    sjv_t.m11 = sjt_math1919 + sjt_math1920;
#line 61
    sjt_dot1036 = _parent;
#line 69
    sjt_math1965 = (sjt_dot1036)->m03;
#line 61
    sjt_dot1037 = _parent;
#line 69
    sjt_math1966 = (sjt_dot1037)->m12;
#line 69
    sjt_math1963 = sjt_math1965 * sjt_math1966;
#line 61
    sjt_dot1038 = _parent;
#line 69
    sjt_math1964 = (sjt_dot1038)->m30;
#line 69
    sjt_math1961 = sjt_math1963 * sjt_math1964;
#line 61
    sjt_dot1039 = _parent;
#line 69
    sjt_math1969 = (sjt_dot1039)->m02;
#line 61
    sjt_dot1040 = _parent;
#line 69
    sjt_math1970 = (sjt_dot1040)->m13;
#line 69
    sjt_math1967 = sjt_math1969 * sjt_math1970;
#line 61
    sjt_dot1041 = _parent;
#line 69
    sjt_math1968 = (sjt_dot1041)->m30;
#line 69
    sjt_math1962 = sjt_math1967 * sjt_math1968;
#line 69
    sjt_math1959 = sjt_math1961 - sjt_math1962;
#line 61
    sjt_dot1042 = _parent;
#line 69
    sjt_math1973 = (sjt_dot1042)->m03;
#line 61
    sjt_dot1043 = _parent;
#line 69
    sjt_math1974 = (sjt_dot1043)->m10;
#line 69
    sjt_math1971 = sjt_math1973 * sjt_math1974;
#line 61
    sjt_dot1044 = _parent;
#line 69
    sjt_math1972 = (sjt_dot1044)->m32;
#line 69
    sjt_math1960 = sjt_math1971 * sjt_math1972;
#line 69
    sjt_math1957 = sjt_math1959 - sjt_math1960;
#line 61
    sjt_dot1045 = _parent;
#line 69
    sjt_math1977 = (sjt_dot1045)->m00;
#line 61
    sjt_dot1046 = _parent;
#line 69
    sjt_math1978 = (sjt_dot1046)->m13;
#line 69
    sjt_math1975 = sjt_math1977 * sjt_math1978;
#line 61
    sjt_dot1047 = _parent;
#line 69
    sjt_math1976 = (sjt_dot1047)->m32;
#line 69
    sjt_math1958 = sjt_math1975 * sjt_math1976;
#line 69
    sjt_math1955 = sjt_math1957 + sjt_math1958;
#line 61
    sjt_dot1048 = _parent;
#line 69
    sjt_math1981 = (sjt_dot1048)->m02;
#line 61
    sjt_dot1049 = _parent;
#line 69
    sjt_math1982 = (sjt_dot1049)->m10;
#line 69
    sjt_math1979 = sjt_math1981 * sjt_math1982;
#line 61
    sjt_dot1050 = _parent;
#line 69
    sjt_math1980 = (sjt_dot1050)->m33;
#line 69
    sjt_math1956 = sjt_math1979 * sjt_math1980;
#line 69
    sjt_math1953 = sjt_math1955 + sjt_math1956;
#line 61
    sjt_dot1051 = _parent;
#line 69
    sjt_math1985 = (sjt_dot1051)->m00;
#line 61
    sjt_dot1052 = _parent;
#line 69
    sjt_math1986 = (sjt_dot1052)->m12;
#line 69
    sjt_math1983 = sjt_math1985 * sjt_math1986;
#line 61
    sjt_dot1053 = _parent;
#line 69
    sjt_math1984 = (sjt_dot1053)->m33;
#line 69
    sjt_math1954 = sjt_math1983 * sjt_math1984;
#line 69
    sjv_t.m12 = sjt_math1953 - sjt_math1954;
#line 61
    sjt_dot1054 = _parent;
#line 70
    sjt_math1999 = (sjt_dot1054)->m02;
#line 61
    sjt_dot1055 = _parent;
#line 70
    sjt_math2000 = (sjt_dot1055)->m13;
#line 70
    sjt_math1997 = sjt_math1999 * sjt_math2000;
#line 61
    sjt_dot1056 = _parent;
#line 70
    sjt_math1998 = (sjt_dot1056)->m20;
#line 70
    sjt_math1995 = sjt_math1997 * sjt_math1998;
#line 61
    sjt_dot1057 = _parent;
#line 70
    sjt_math2003 = (sjt_dot1057)->m03;
#line 61
    sjt_dot1058 = _parent;
#line 70
    sjt_math2004 = (sjt_dot1058)->m12;
#line 70
    sjt_math2001 = sjt_math2003 * sjt_math2004;
#line 61
    sjt_dot1059 = _parent;
#line 70
    sjt_math2002 = (sjt_dot1059)->m20;
#line 70
    sjt_math1996 = sjt_math2001 * sjt_math2002;
#line 70
    sjt_math1993 = sjt_math1995 - sjt_math1996;
#line 61
    sjt_dot1060 = _parent;
#line 70
    sjt_math2007 = (sjt_dot1060)->m03;
#line 61
    sjt_dot1061 = _parent;
#line 70
    sjt_math2008 = (sjt_dot1061)->m10;
#line 70
    sjt_math2005 = sjt_math2007 * sjt_math2008;
#line 61
    sjt_dot1062 = _parent;
#line 70
    sjt_math2006 = (sjt_dot1062)->m22;
#line 70
    sjt_math1994 = sjt_math2005 * sjt_math2006;
#line 70
    sjt_math1991 = sjt_math1993 + sjt_math1994;
#line 61
    sjt_dot1063 = _parent;
#line 70
    sjt_math2011 = (sjt_dot1063)->m00;
#line 61
    sjt_dot1064 = _parent;
#line 70
    sjt_math2012 = (sjt_dot1064)->m13;
#line 70
    sjt_math2009 = sjt_math2011 * sjt_math2012;
#line 61
    sjt_dot1065 = _parent;
#line 70
    sjt_math2010 = (sjt_dot1065)->m22;
#line 70
    sjt_math1992 = sjt_math2009 * sjt_math2010;
#line 70
    sjt_math1989 = sjt_math1991 - sjt_math1992;
#line 61
    sjt_dot1066 = _parent;
#line 70
    sjt_math2015 = (sjt_dot1066)->m02;
#line 61
    sjt_dot1067 = _parent;
#line 70
    sjt_math2016 = (sjt_dot1067)->m10;
#line 70
    sjt_math2013 = sjt_math2015 * sjt_math2016;
#line 61
    sjt_dot1068 = _parent;
#line 70
    sjt_math2014 = (sjt_dot1068)->m23;
#line 70
    sjt_math1990 = sjt_math2013 * sjt_math2014;
#line 70
    sjt_math1987 = sjt_math1989 - sjt_math1990;
#line 61
    sjt_dot1069 = _parent;
#line 70
    sjt_math2019 = (sjt_dot1069)->m00;
#line 61
    sjt_dot1070 = _parent;
#line 70
    sjt_math2020 = (sjt_dot1070)->m12;
#line 70
    sjt_math2017 = sjt_math2019 * sjt_math2020;
#line 61
    sjt_dot1071 = _parent;
#line 70
    sjt_math2018 = (sjt_dot1071)->m23;
#line 70
    sjt_math1988 = sjt_math2017 * sjt_math2018;
#line 70
    sjv_t.m13 = sjt_math1987 + sjt_math1988;
#line 61
    sjt_dot1072 = _parent;
#line 71
    sjt_math2033 = (sjt_dot1072)->m11;
#line 61
    sjt_dot1073 = _parent;
#line 71
    sjt_math2034 = (sjt_dot1073)->m23;
#line 71
    sjt_math2031 = sjt_math2033 * sjt_math2034;
#line 61
    sjt_dot1074 = _parent;
#line 71
    sjt_math2032 = (sjt_dot1074)->m30;
#line 71
    sjt_math2029 = sjt_math2031 * sjt_math2032;
#line 61
    sjt_dot1075 = _parent;
#line 71
    sjt_math2037 = (sjt_dot1075)->m13;
#line 61
    sjt_dot1076 = _parent;
#line 71
    sjt_math2038 = (sjt_dot1076)->m21;
#line 71
    sjt_math2035 = sjt_math2037 * sjt_math2038;
#line 61
    sjt_dot1077 = _parent;
#line 71
    sjt_math2036 = (sjt_dot1077)->m30;
#line 71
    sjt_math2030 = sjt_math2035 * sjt_math2036;
#line 71
    sjt_math2027 = sjt_math2029 - sjt_math2030;
#line 61
    sjt_dot1078 = _parent;
#line 71
    sjt_math2041 = (sjt_dot1078)->m13;
#line 61
    sjt_dot1079 = _parent;
#line 71
    sjt_math2042 = (sjt_dot1079)->m20;
#line 71
    sjt_math2039 = sjt_math2041 * sjt_math2042;
#line 61
    sjt_dot1080 = _parent;
#line 71
    sjt_math2040 = (sjt_dot1080)->m31;
#line 71
    sjt_math2028 = sjt_math2039 * sjt_math2040;
#line 71
    sjt_math2025 = sjt_math2027 + sjt_math2028;
#line 61
    sjt_dot1081 = _parent;
#line 71
    sjt_math2045 = (sjt_dot1081)->m10;
#line 61
    sjt_dot1082 = _parent;
#line 71
    sjt_math2046 = (sjt_dot1082)->m23;
#line 71
    sjt_math2043 = sjt_math2045 * sjt_math2046;
#line 61
    sjt_dot1083 = _parent;
#line 71
    sjt_math2044 = (sjt_dot1083)->m31;
#line 71
    sjt_math2026 = sjt_math2043 * sjt_math2044;
#line 71
    sjt_math2023 = sjt_math2025 - sjt_math2026;
#line 61
    sjt_dot1084 = _parent;
#line 71
    sjt_math2049 = (sjt_dot1084)->m11;
#line 61
    sjt_dot1085 = _parent;
#line 71
    sjt_math2050 = (sjt_dot1085)->m20;
#line 71
    sjt_math2047 = sjt_math2049 * sjt_math2050;
#line 61
    sjt_dot1086 = _parent;
#line 71
    sjt_math2048 = (sjt_dot1086)->m33;
#line 71
    sjt_math2024 = sjt_math2047 * sjt_math2048;
#line 71
    sjt_math2021 = sjt_math2023 - sjt_math2024;
#line 61
    sjt_dot1087 = _parent;
#line 71
    sjt_math2053 = (sjt_dot1087)->m10;
#line 61
    sjt_dot1088 = _parent;
#line 71
    sjt_math2054 = (sjt_dot1088)->m21;
#line 71
    sjt_math2051 = sjt_math2053 * sjt_math2054;
#line 61
    sjt_dot1089 = _parent;
#line 71
    sjt_math2052 = (sjt_dot1089)->m33;
#line 71
    sjt_math2022 = sjt_math2051 * sjt_math2052;
#line 71
    sjv_t.m20 = sjt_math2021 + sjt_math2022;
#line 61
    sjt_dot1090 = _parent;
#line 72
    sjt_math2067 = (sjt_dot1090)->m03;
#line 61
    sjt_dot1091 = _parent;
#line 72
    sjt_math2068 = (sjt_dot1091)->m21;
#line 72
    sjt_math2065 = sjt_math2067 * sjt_math2068;
#line 61
    sjt_dot1092 = _parent;
#line 72
    sjt_math2066 = (sjt_dot1092)->m30;
#line 72
    sjt_math2063 = sjt_math2065 * sjt_math2066;
#line 61
    sjt_dot1093 = _parent;
#line 72
    sjt_math2071 = (sjt_dot1093)->m01;
#line 61
    sjt_dot1094 = _parent;
#line 72
    sjt_math2072 = (sjt_dot1094)->m23;
#line 72
    sjt_math2069 = sjt_math2071 * sjt_math2072;
#line 61
    sjt_dot1095 = _parent;
#line 72
    sjt_math2070 = (sjt_dot1095)->m30;
#line 72
    sjt_math2064 = sjt_math2069 * sjt_math2070;
#line 72
    sjt_math2061 = sjt_math2063 - sjt_math2064;
#line 61
    sjt_dot1096 = _parent;
#line 72
    sjt_math2075 = (sjt_dot1096)->m03;
#line 61
    sjt_dot1097 = _parent;
#line 72
    sjt_math2076 = (sjt_dot1097)->m20;
#line 72
    sjt_math2073 = sjt_math2075 * sjt_math2076;
#line 61
    sjt_dot1098 = _parent;
#line 72
    sjt_math2074 = (sjt_dot1098)->m31;
#line 72
    sjt_math2062 = sjt_math2073 * sjt_math2074;
#line 72
    sjt_math2059 = sjt_math2061 - sjt_math2062;
#line 61
    sjt_dot1099 = _parent;
#line 72
    sjt_math2079 = (sjt_dot1099)->m00;
#line 61
    sjt_dot1100 = _parent;
#line 72
    sjt_math2080 = (sjt_dot1100)->m23;
#line 72
    sjt_math2077 = sjt_math2079 * sjt_math2080;
#line 61
    sjt_dot1101 = _parent;
#line 72
    sjt_math2078 = (sjt_dot1101)->m31;
#line 72
    sjt_math2060 = sjt_math2077 * sjt_math2078;
#line 72
    sjt_math2057 = sjt_math2059 + sjt_math2060;
#line 61
    sjt_dot1102 = _parent;
#line 72
    sjt_math2083 = (sjt_dot1102)->m01;
#line 61
    sjt_dot1103 = _parent;
#line 72
    sjt_math2084 = (sjt_dot1103)->m20;
#line 72
    sjt_math2081 = sjt_math2083 * sjt_math2084;
#line 61
    sjt_dot1104 = _parent;
#line 72
    sjt_math2082 = (sjt_dot1104)->m33;
#line 72
    sjt_math2058 = sjt_math2081 * sjt_math2082;
#line 72
    sjt_math2055 = sjt_math2057 + sjt_math2058;
#line 61
    sjt_dot1105 = _parent;
#line 72
    sjt_math2087 = (sjt_dot1105)->m00;
#line 61
    sjt_dot1106 = _parent;
#line 72
    sjt_math2088 = (sjt_dot1106)->m21;
#line 72
    sjt_math2085 = sjt_math2087 * sjt_math2088;
#line 61
    sjt_dot1107 = _parent;
#line 72
    sjt_math2086 = (sjt_dot1107)->m33;
#line 72
    sjt_math2056 = sjt_math2085 * sjt_math2086;
#line 72
    sjv_t.m21 = sjt_math2055 - sjt_math2056;
#line 61
    sjt_dot1108 = _parent;
#line 73
    sjt_math2101 = (sjt_dot1108)->m01;
#line 61
    sjt_dot1109 = _parent;
#line 73
    sjt_math2102 = (sjt_dot1109)->m13;
#line 73
    sjt_math2099 = sjt_math2101 * sjt_math2102;
#line 61
    sjt_dot1110 = _parent;
#line 73
    sjt_math2100 = (sjt_dot1110)->m30;
#line 73
    sjt_math2097 = sjt_math2099 * sjt_math2100;
#line 61
    sjt_dot1111 = _parent;
#line 73
    sjt_math2105 = (sjt_dot1111)->m03;
#line 61
    sjt_dot1112 = _parent;
#line 73
    sjt_math2106 = (sjt_dot1112)->m11;
#line 73
    sjt_math2103 = sjt_math2105 * sjt_math2106;
#line 61
    sjt_dot1113 = _parent;
#line 73
    sjt_math2104 = (sjt_dot1113)->m30;
#line 73
    sjt_math2098 = sjt_math2103 * sjt_math2104;
#line 73
    sjt_math2095 = sjt_math2097 - sjt_math2098;
#line 61
    sjt_dot1114 = _parent;
#line 73
    sjt_math2109 = (sjt_dot1114)->m03;
#line 61
    sjt_dot1115 = _parent;
#line 73
    sjt_math2110 = (sjt_dot1115)->m10;
#line 73
    sjt_math2107 = sjt_math2109 * sjt_math2110;
#line 61
    sjt_dot1116 = _parent;
#line 73
    sjt_math2108 = (sjt_dot1116)->m31;
#line 73
    sjt_math2096 = sjt_math2107 * sjt_math2108;
#line 73
    sjt_math2093 = sjt_math2095 + sjt_math2096;
#line 61
    sjt_dot1117 = _parent;
#line 73
    sjt_math2113 = (sjt_dot1117)->m00;
#line 61
    sjt_dot1118 = _parent;
#line 73
    sjt_math2114 = (sjt_dot1118)->m13;
#line 73
    sjt_math2111 = sjt_math2113 * sjt_math2114;
#line 61
    sjt_dot1119 = _parent;
#line 73
    sjt_math2112 = (sjt_dot1119)->m31;
#line 73
    sjt_math2094 = sjt_math2111 * sjt_math2112;
#line 73
    sjt_math2091 = sjt_math2093 - sjt_math2094;
#line 61
    sjt_dot1120 = _parent;
#line 73
    sjt_math2117 = (sjt_dot1120)->m01;
#line 61
    sjt_dot1121 = _parent;
#line 73
    sjt_math2118 = (sjt_dot1121)->m10;
#line 73
    sjt_math2115 = sjt_math2117 * sjt_math2118;
#line 61
    sjt_dot1122 = _parent;
#line 73
    sjt_math2116 = (sjt_dot1122)->m33;
#line 73
    sjt_math2092 = sjt_math2115 * sjt_math2116;
#line 73
    sjt_math2089 = sjt_math2091 - sjt_math2092;
#line 61
    sjt_dot1123 = _parent;
#line 73
    sjt_math2121 = (sjt_dot1123)->m00;
#line 61
    sjt_dot1124 = _parent;
#line 73
    sjt_math2122 = (sjt_dot1124)->m11;
#line 73
    sjt_math2119 = sjt_math2121 * sjt_math2122;
#line 61
    sjt_dot1125 = _parent;
#line 73
    sjt_math2120 = (sjt_dot1125)->m33;
#line 73
    sjt_math2090 = sjt_math2119 * sjt_math2120;
#line 73
    sjv_t.m22 = sjt_math2089 + sjt_math2090;
#line 61
    sjt_dot1126 = _parent;
#line 74
    sjt_math2135 = (sjt_dot1126)->m03;
#line 61
    sjt_dot1127 = _parent;
#line 74
    sjt_math2136 = (sjt_dot1127)->m11;
#line 74
    sjt_math2133 = sjt_math2135 * sjt_math2136;
#line 61
    sjt_dot1128 = _parent;
#line 74
    sjt_math2134 = (sjt_dot1128)->m20;
#line 74
    sjt_math2131 = sjt_math2133 * sjt_math2134;
#line 61
    sjt_dot1129 = _parent;
#line 74
    sjt_math2139 = (sjt_dot1129)->m01;
#line 61
    sjt_dot1130 = _parent;
#line 74
    sjt_math2140 = (sjt_dot1130)->m13;
#line 74
    sjt_math2137 = sjt_math2139 * sjt_math2140;
#line 61
    sjt_dot1131 = _parent;
#line 74
    sjt_math2138 = (sjt_dot1131)->m20;
#line 74
    sjt_math2132 = sjt_math2137 * sjt_math2138;
#line 74
    sjt_math2129 = sjt_math2131 - sjt_math2132;
#line 61
    sjt_dot1132 = _parent;
#line 74
    sjt_math2143 = (sjt_dot1132)->m03;
#line 61
    sjt_dot1133 = _parent;
#line 74
    sjt_math2144 = (sjt_dot1133)->m10;
#line 74
    sjt_math2141 = sjt_math2143 * sjt_math2144;
#line 61
    sjt_dot1134 = _parent;
#line 74
    sjt_math2142 = (sjt_dot1134)->m21;
#line 74
    sjt_math2130 = sjt_math2141 * sjt_math2142;
#line 74
    sjt_math2127 = sjt_math2129 - sjt_math2130;
#line 61
    sjt_dot1135 = _parent;
#line 74
    sjt_math2147 = (sjt_dot1135)->m00;
#line 61
    sjt_dot1136 = _parent;
#line 74
    sjt_math2148 = (sjt_dot1136)->m13;
#line 74
    sjt_math2145 = sjt_math2147 * sjt_math2148;
#line 61
    sjt_dot1137 = _parent;
#line 74
    sjt_math2146 = (sjt_dot1137)->m21;
#line 74
    sjt_math2128 = sjt_math2145 * sjt_math2146;
#line 74
    sjt_math2125 = sjt_math2127 + sjt_math2128;
#line 61
    sjt_dot1138 = _parent;
#line 74
    sjt_math2151 = (sjt_dot1138)->m01;
#line 61
    sjt_dot1139 = _parent;
#line 74
    sjt_math2152 = (sjt_dot1139)->m10;
#line 74
    sjt_math2149 = sjt_math2151 * sjt_math2152;
#line 61
    sjt_dot1140 = _parent;
#line 74
    sjt_math2150 = (sjt_dot1140)->m23;
#line 74
    sjt_math2126 = sjt_math2149 * sjt_math2150;
#line 74
    sjt_math2123 = sjt_math2125 + sjt_math2126;
#line 61
    sjt_dot1141 = _parent;
#line 74
    sjt_math2155 = (sjt_dot1141)->m00;
#line 61
    sjt_dot1142 = _parent;
#line 74
    sjt_math2156 = (sjt_dot1142)->m11;
#line 74
    sjt_math2153 = sjt_math2155 * sjt_math2156;
#line 61
    sjt_dot1143 = _parent;
#line 74
    sjt_math2154 = (sjt_dot1143)->m23;
#line 74
    sjt_math2124 = sjt_math2153 * sjt_math2154;
#line 74
    sjv_t.m23 = sjt_math2123 - sjt_math2124;
#line 61
    sjt_dot1144 = _parent;
#line 75
    sjt_math2169 = (sjt_dot1144)->m12;
#line 61
    sjt_dot1145 = _parent;
#line 75
    sjt_math2170 = (sjt_dot1145)->m21;
#line 75
    sjt_math2167 = sjt_math2169 * sjt_math2170;
#line 61
    sjt_dot1146 = _parent;
#line 75
    sjt_math2168 = (sjt_dot1146)->m30;
#line 75
    sjt_math2165 = sjt_math2167 * sjt_math2168;
#line 61
    sjt_dot1147 = _parent;
#line 75
    sjt_math2173 = (sjt_dot1147)->m11;
#line 61
    sjt_dot1148 = _parent;
#line 75
    sjt_math2174 = (sjt_dot1148)->m22;
#line 75
    sjt_math2171 = sjt_math2173 * sjt_math2174;
#line 61
    sjt_dot1149 = _parent;
#line 75
    sjt_math2172 = (sjt_dot1149)->m30;
#line 75
    sjt_math2166 = sjt_math2171 * sjt_math2172;
#line 75
    sjt_math2163 = sjt_math2165 - sjt_math2166;
#line 61
    sjt_dot1150 = _parent;
#line 75
    sjt_math2177 = (sjt_dot1150)->m12;
#line 61
    sjt_dot1151 = _parent;
#line 75
    sjt_math2178 = (sjt_dot1151)->m20;
#line 75
    sjt_math2175 = sjt_math2177 * sjt_math2178;
#line 61
    sjt_dot1152 = _parent;
#line 75
    sjt_math2176 = (sjt_dot1152)->m31;
#line 75
    sjt_math2164 = sjt_math2175 * sjt_math2176;
#line 75
    sjt_math2161 = sjt_math2163 - sjt_math2164;
#line 61
    sjt_dot1153 = _parent;
#line 75
    sjt_math2181 = (sjt_dot1153)->m10;
#line 61
    sjt_dot1154 = _parent;
#line 75
    sjt_math2182 = (sjt_dot1154)->m22;
#line 75
    sjt_math2179 = sjt_math2181 * sjt_math2182;
#line 61
    sjt_dot1155 = _parent;
#line 75
    sjt_math2180 = (sjt_dot1155)->m31;
#line 75
    sjt_math2162 = sjt_math2179 * sjt_math2180;
#line 75
    sjt_math2159 = sjt_math2161 + sjt_math2162;
#line 61
    sjt_dot1156 = _parent;
#line 75
    sjt_math2185 = (sjt_dot1156)->m11;
#line 61
    sjt_dot1157 = _parent;
#line 75
    sjt_math2186 = (sjt_dot1157)->m20;
#line 75
    sjt_math2183 = sjt_math2185 * sjt_math2186;
#line 61
    sjt_dot1158 = _parent;
#line 75
    sjt_math2184 = (sjt_dot1158)->m32;
#line 75
    sjt_math2160 = sjt_math2183 * sjt_math2184;
#line 75
    sjt_math2157 = sjt_math2159 + sjt_math2160;
#line 61
    sjt_dot1159 = _parent;
#line 75
    sjt_math2189 = (sjt_dot1159)->m10;
#line 61
    sjt_dot1160 = _parent;
#line 75
    sjt_math2190 = (sjt_dot1160)->m21;
#line 75
    sjt_math2187 = sjt_math2189 * sjt_math2190;
#line 61
    sjt_dot1161 = _parent;
#line 75
    sjt_math2188 = (sjt_dot1161)->m32;
#line 75
    sjt_math2158 = sjt_math2187 * sjt_math2188;
#line 75
    sjv_t.m30 = sjt_math2157 - sjt_math2158;
#line 61
    sjt_dot1162 = _parent;
#line 76
    sjt_math2203 = (sjt_dot1162)->m01;
#line 61
    sjt_dot1163 = _parent;
#line 76
    sjt_math2204 = (sjt_dot1163)->m22;
#line 76
    sjt_math2201 = sjt_math2203 * sjt_math2204;
#line 61
    sjt_dot1164 = _parent;
#line 76
    sjt_math2202 = (sjt_dot1164)->m30;
#line 76
    sjt_math2199 = sjt_math2201 * sjt_math2202;
#line 61
    sjt_dot1165 = _parent;
#line 76
    sjt_math2207 = (sjt_dot1165)->m02;
#line 61
    sjt_dot1166 = _parent;
#line 76
    sjt_math2208 = (sjt_dot1166)->m21;
#line 76
    sjt_math2205 = sjt_math2207 * sjt_math2208;
#line 61
    sjt_dot1167 = _parent;
#line 76
    sjt_math2206 = (sjt_dot1167)->m30;
#line 76
    sjt_math2200 = sjt_math2205 * sjt_math2206;
#line 76
    sjt_math2197 = sjt_math2199 - sjt_math2200;
#line 61
    sjt_dot1168 = _parent;
#line 76
    sjt_math2211 = (sjt_dot1168)->m02;
#line 61
    sjt_dot1169 = _parent;
#line 76
    sjt_math2212 = (sjt_dot1169)->m20;
#line 76
    sjt_math2209 = sjt_math2211 * sjt_math2212;
#line 61
    sjt_dot1170 = _parent;
#line 76
    sjt_math2210 = (sjt_dot1170)->m31;
#line 76
    sjt_math2198 = sjt_math2209 * sjt_math2210;
#line 76
    sjt_math2195 = sjt_math2197 + sjt_math2198;
#line 61
    sjt_dot1171 = _parent;
#line 76
    sjt_math2215 = (sjt_dot1171)->m00;
#line 61
    sjt_dot1172 = _parent;
#line 76
    sjt_math2216 = (sjt_dot1172)->m22;
#line 76
    sjt_math2213 = sjt_math2215 * sjt_math2216;
#line 61
    sjt_dot1173 = _parent;
#line 76
    sjt_math2214 = (sjt_dot1173)->m31;
#line 76
    sjt_math2196 = sjt_math2213 * sjt_math2214;
#line 76
    sjt_math2193 = sjt_math2195 - sjt_math2196;
#line 61
    sjt_dot1174 = _parent;
#line 76
    sjt_math2219 = (sjt_dot1174)->m01;
#line 61
    sjt_dot1175 = _parent;
#line 76
    sjt_math2220 = (sjt_dot1175)->m20;
#line 76
    sjt_math2217 = sjt_math2219 * sjt_math2220;
#line 61
    sjt_dot1176 = _parent;
#line 76
    sjt_math2218 = (sjt_dot1176)->m32;
#line 76
    sjt_math2194 = sjt_math2217 * sjt_math2218;
#line 76
    sjt_math2191 = sjt_math2193 - sjt_math2194;
#line 61
    sjt_dot1177 = _parent;
#line 76
    sjt_math2223 = (sjt_dot1177)->m00;
#line 61
    sjt_dot1178 = _parent;
#line 76
    sjt_math2224 = (sjt_dot1178)->m21;
#line 76
    sjt_math2221 = sjt_math2223 * sjt_math2224;
#line 61
    sjt_dot1179 = _parent;
#line 76
    sjt_math2222 = (sjt_dot1179)->m32;
#line 76
    sjt_math2192 = sjt_math2221 * sjt_math2222;
#line 76
    sjv_t.m31 = sjt_math2191 + sjt_math2192;
#line 61
    sjt_dot1180 = _parent;
#line 77
    sjt_math2237 = (sjt_dot1180)->m02;
#line 61
    sjt_dot1181 = _parent;
#line 77
    sjt_math2238 = (sjt_dot1181)->m11;
#line 77
    sjt_math2235 = sjt_math2237 * sjt_math2238;
#line 61
    sjt_dot1182 = _parent;
#line 77
    sjt_math2236 = (sjt_dot1182)->m30;
#line 77
    sjt_math2233 = sjt_math2235 * sjt_math2236;
#line 61
    sjt_dot1183 = _parent;
#line 77
    sjt_math2241 = (sjt_dot1183)->m01;
#line 61
    sjt_dot1184 = _parent;
#line 77
    sjt_math2242 = (sjt_dot1184)->m12;
#line 77
    sjt_math2239 = sjt_math2241 * sjt_math2242;
#line 61
    sjt_dot1185 = _parent;
#line 77
    sjt_math2240 = (sjt_dot1185)->m30;
#line 77
    sjt_math2234 = sjt_math2239 * sjt_math2240;
#line 77
    sjt_math2231 = sjt_math2233 - sjt_math2234;
#line 61
    sjt_dot1186 = _parent;
#line 77
    sjt_math2245 = (sjt_dot1186)->m02;
#line 61
    sjt_dot1187 = _parent;
#line 77
    sjt_math2246 = (sjt_dot1187)->m10;
#line 77
    sjt_math2243 = sjt_math2245 * sjt_math2246;
#line 61
    sjt_dot1188 = _parent;
#line 77
    sjt_math2244 = (sjt_dot1188)->m31;
#line 77
    sjt_math2232 = sjt_math2243 * sjt_math2244;
#line 77
    sjt_math2229 = sjt_math2231 - sjt_math2232;
#line 61
    sjt_dot1189 = _parent;
#line 77
    sjt_math2249 = (sjt_dot1189)->m00;
#line 61
    sjt_dot1190 = _parent;
#line 77
    sjt_math2250 = (sjt_dot1190)->m12;
#line 77
    sjt_math2247 = sjt_math2249 * sjt_math2250;
#line 61
    sjt_dot1191 = _parent;
#line 77
    sjt_math2248 = (sjt_dot1191)->m31;
#line 77
    sjt_math2230 = sjt_math2247 * sjt_math2248;
#line 77
    sjt_math2227 = sjt_math2229 + sjt_math2230;
#line 61
    sjt_dot1192 = _parent;
#line 77
    sjt_math2253 = (sjt_dot1192)->m01;
#line 61
    sjt_dot1193 = _parent;
#line 77
    sjt_math2254 = (sjt_dot1193)->m10;
#line 77
    sjt_math2251 = sjt_math2253 * sjt_math2254;
#line 61
    sjt_dot1194 = _parent;
#line 77
    sjt_math2252 = (sjt_dot1194)->m32;
#line 77
    sjt_math2228 = sjt_math2251 * sjt_math2252;
#line 77
    sjt_math2225 = sjt_math2227 + sjt_math2228;
#line 61
    sjt_dot1195 = _parent;
#line 77
    sjt_math2257 = (sjt_dot1195)->m00;
#line 61
    sjt_dot1196 = _parent;
#line 77
    sjt_math2258 = (sjt_dot1196)->m11;
#line 77
    sjt_math2255 = sjt_math2257 * sjt_math2258;
#line 61
    sjt_dot1197 = _parent;
#line 77
    sjt_math2256 = (sjt_dot1197)->m32;
#line 77
    sjt_math2226 = sjt_math2255 * sjt_math2256;
#line 77
    sjv_t.m32 = sjt_math2225 - sjt_math2226;
#line 61
    sjt_dot1198 = _parent;
#line 78
    sjt_math2271 = (sjt_dot1198)->m01;
#line 61
    sjt_dot1199 = _parent;
#line 78
    sjt_math2272 = (sjt_dot1199)->m12;
#line 78
    sjt_math2269 = sjt_math2271 * sjt_math2272;
#line 61
    sjt_dot1200 = _parent;
#line 78
    sjt_math2270 = (sjt_dot1200)->m20;
#line 78
    sjt_math2267 = sjt_math2269 * sjt_math2270;
#line 61
    sjt_dot1201 = _parent;
#line 78
    sjt_math2275 = (sjt_dot1201)->m02;
#line 61
    sjt_dot1202 = _parent;
#line 78
    sjt_math2276 = (sjt_dot1202)->m11;
#line 78
    sjt_math2273 = sjt_math2275 * sjt_math2276;
#line 61
    sjt_dot1203 = _parent;
#line 78
    sjt_math2274 = (sjt_dot1203)->m20;
#line 78
    sjt_math2268 = sjt_math2273 * sjt_math2274;
#line 78
    sjt_math2265 = sjt_math2267 - sjt_math2268;
#line 61
    sjt_dot1204 = _parent;
#line 78
    sjt_math2279 = (sjt_dot1204)->m02;
#line 61
    sjt_dot1205 = _parent;
#line 78
    sjt_math2280 = (sjt_dot1205)->m10;
#line 78
    sjt_math2277 = sjt_math2279 * sjt_math2280;
#line 61
    sjt_dot1206 = _parent;
#line 78
    sjt_math2278 = (sjt_dot1206)->m21;
#line 78
    sjt_math2266 = sjt_math2277 * sjt_math2278;
#line 78
    sjt_math2263 = sjt_math2265 + sjt_math2266;
#line 61
    sjt_dot1207 = _parent;
#line 78
    sjt_math2283 = (sjt_dot1207)->m00;
#line 61
    sjt_dot1208 = _parent;
#line 78
    sjt_math2284 = (sjt_dot1208)->m12;
#line 78
    sjt_math2281 = sjt_math2283 * sjt_math2284;
#line 61
    sjt_dot1209 = _parent;
#line 78
    sjt_math2282 = (sjt_dot1209)->m21;
#line 78
    sjt_math2264 = sjt_math2281 * sjt_math2282;
#line 78
    sjt_math2261 = sjt_math2263 - sjt_math2264;
#line 61
    sjt_dot1210 = _parent;
#line 78
    sjt_math2287 = (sjt_dot1210)->m01;
#line 61
    sjt_dot1211 = _parent;
#line 78
    sjt_math2288 = (sjt_dot1211)->m10;
#line 78
    sjt_math2285 = sjt_math2287 * sjt_math2288;
#line 61
    sjt_dot1212 = _parent;
#line 78
    sjt_math2286 = (sjt_dot1212)->m22;
#line 78
    sjt_math2262 = sjt_math2285 * sjt_math2286;
#line 78
    sjt_math2259 = sjt_math2261 - sjt_math2262;
#line 61
    sjt_dot1213 = _parent;
#line 78
    sjt_math2291 = (sjt_dot1213)->m00;
#line 61
    sjt_dot1214 = _parent;
#line 78
    sjt_math2292 = (sjt_dot1214)->m11;
#line 78
    sjt_math2289 = sjt_math2291 * sjt_math2292;
#line 61
    sjt_dot1215 = _parent;
#line 78
    sjt_math2290 = (sjt_dot1215)->m22;
#line 78
    sjt_math2260 = sjt_math2289 * sjt_math2290;
#line 78
    sjv_t.m33 = sjt_math2259 + sjt_math2260;
#line 0 ""
    sjf_mat4(&sjv_t);
#line 40 ".\..\lib\ui\mat4.sj"
    sjt_parent55 = &sjv_t;
#line 81
    sjt_math2293 = 1.0f;
#line 0 ""
    sjf_mat4_determinant(_parent, &sjt_math2294);
#line 81 ".\..\lib\ui\mat4.sj"
    sjt_functionParam80 = sjt_math2293 / sjt_math2294;
#line 0 ""
    sjf_mat4_multiply_f32_heap(sjt_parent55, sjt_functionParam80, _return);

    sjf_mat4_destroy(&sjv_t);
}

void sjf_mat4_lookAtLH(sjs_vec3* camera, sjs_vec3* target, sjs_vec3* up, sjs_mat4* _return) {
    sjs_vec3 sjt_call3;
    sjs_vec3* sjt_dot141;
    sjs_vec3* sjt_dot142;
    sjs_vec3* sjt_dot143;
    sjs_vec3* sjt_dot144;
    sjs_vec3* sjt_dot145;
    sjs_vec3* sjt_dot146;
    sjs_vec3* sjt_dot147;
    sjs_vec3* sjt_dot148;
    sjs_vec3* sjt_dot149;
    sjs_vec3* sjt_functionParam28;
    sjs_vec3* sjt_functionParam31;
    sjs_vec3* sjt_functionParam32;
    sjs_vec3* sjt_functionParam33;
    sjs_vec3* sjt_functionParam34;
    sjs_vec3* sjt_functionParam35;
    float sjt_math185;
    float sjt_math186;
    float sjt_math197;
    float sjt_math198;
    float sjt_math199;
    float sjt_math200;
    sjs_vec3* sjt_parent17;
    sjs_vec3* sjt_parent18;
    sjs_vec3* sjt_parent19;
    sjs_vec3* sjt_parent20;
    sjs_vec3* sjt_parent21;
    sjs_vec3* sjt_parent22;
    sjs_vec3* sjt_parent23;
    sjs_vec3* sjt_parent24;
    sjs_vec3 sjv_temp;
    sjs_vec3 sjv_xaxis;
    sjs_vec3 sjv_yaxis;
    sjs_vec3 sjv_zaxis;

#line 119 ".\..\lib\ui\mat4.sj"
    sjt_parent17 = target;
#line 119
    sjt_functionParam28 = camera;
#line 0 ""
    sjf_vec3_subtract(sjt_parent17, sjt_functionParam28, &sjv_temp);
#line 29 ".\..\lib\ui\vec3.sj"
    sjt_parent18 = &sjv_temp;
#line 0 ""
    sjf_vec3_normalize(sjt_parent18, &sjv_zaxis);
#line 119 ".\..\lib\ui\mat4.sj"
    sjt_parent20 = up;
#line 122
    sjt_functionParam31 = &sjv_zaxis;
#line 0 ""
    sjf_vec3_cross(sjt_parent20, sjt_functionParam31, &sjt_call3);
#line 122 ".\..\lib\ui\mat4.sj"
    sjt_parent19 = &sjt_call3;
#line 0 ""
    sjf_vec3_normalize(sjt_parent19, &sjv_xaxis);
#line 38 ".\..\lib\ui\vec3.sj"
    sjt_parent21 = &sjv_zaxis;
#line 123 ".\..\lib\ui\mat4.sj"
    sjt_functionParam32 = &sjv_xaxis;
#line 0 ""
    sjf_vec3_cross(sjt_parent21, sjt_functionParam32, &sjv_yaxis);
#line 1 ".\..\lib\ui\vec3.sj"
    sjt_dot141 = &sjv_xaxis;
#line 124 ".\..\lib\ui\mat4.sj"
    _return->m00 = (sjt_dot141)->x;
#line 1 ".\..\lib\ui\vec3.sj"
    sjt_dot142 = &sjv_yaxis;
#line 124 ".\..\lib\ui\mat4.sj"
    _return->m01 = (sjt_dot142)->x;
#line 1 ".\..\lib\ui\vec3.sj"
    sjt_dot143 = &sjv_zaxis;
#line 124 ".\..\lib\ui\mat4.sj"
    _return->m02 = (sjt_dot143)->x;
#line 128
    _return->m03 = 0.0f;
#line 1 ".\..\lib\ui\vec3.sj"
    sjt_dot144 = &sjv_xaxis;
#line 124 ".\..\lib\ui\mat4.sj"
    _return->m10 = (sjt_dot144)->y;
#line 1 ".\..\lib\ui\vec3.sj"
    sjt_dot145 = &sjv_yaxis;
#line 124 ".\..\lib\ui\mat4.sj"
    _return->m11 = (sjt_dot145)->y;
#line 1 ".\..\lib\ui\vec3.sj"
    sjt_dot146 = &sjv_zaxis;
#line 124 ".\..\lib\ui\mat4.sj"
    _return->m12 = (sjt_dot146)->y;
#line 132
    _return->m13 = 0.0f;
#line 1 ".\..\lib\ui\vec3.sj"
    sjt_dot147 = &sjv_xaxis;
#line 124 ".\..\lib\ui\mat4.sj"
    _return->m20 = (sjt_dot147)->z;
#line 1 ".\..\lib\ui\vec3.sj"
    sjt_dot148 = &sjv_yaxis;
#line 124 ".\..\lib\ui\mat4.sj"
    _return->m21 = (sjt_dot148)->z;
#line 1 ".\..\lib\ui\vec3.sj"
    sjt_dot149 = &sjv_zaxis;
#line 124 ".\..\lib\ui\mat4.sj"
    _return->m22 = (sjt_dot149)->z;
#line 136
    _return->m23 = 0.0f;
#line 137
    sjt_math185 = 0.0f;
#line 46 ".\..\lib\ui\vec3.sj"
    sjt_parent22 = &sjv_xaxis;
#line 119 ".\..\lib\ui\mat4.sj"
    sjt_functionParam33 = camera;
#line 0 ""
    sjf_vec3_dot(sjt_parent22, sjt_functionParam33, &sjt_math186);
#line 137 ".\..\lib\ui\mat4.sj"
    _return->m30 = sjt_math185 - sjt_math186;
#line 138
    sjt_math197 = 0.0f;
#line 46 ".\..\lib\ui\vec3.sj"
    sjt_parent23 = &sjv_yaxis;
#line 119 ".\..\lib\ui\mat4.sj"
    sjt_functionParam34 = camera;
#line 0 ""
    sjf_vec3_dot(sjt_parent23, sjt_functionParam34, &sjt_math198);
#line 138 ".\..\lib\ui\mat4.sj"
    _return->m31 = sjt_math197 - sjt_math198;
#line 139
    sjt_math199 = 0.0f;
#line 46 ".\..\lib\ui\vec3.sj"
    sjt_parent24 = &sjv_zaxis;
#line 119 ".\..\lib\ui\mat4.sj"
    sjt_functionParam35 = camera;
#line 0 ""
    sjf_vec3_dot(sjt_parent24, sjt_functionParam35, &sjt_math200);
#line 139 ".\..\lib\ui\mat4.sj"
    _return->m32 = sjt_math199 - sjt_math200;
#line 140
    _return->m33 = 1.0f;
#line 0 ""
    sjf_mat4(_return);

    sjf_vec3_destroy(&sjt_call3);
    sjf_vec3_destroy(&sjv_temp);
    sjf_vec3_destroy(&sjv_xaxis);
    sjf_vec3_destroy(&sjv_yaxis);
    sjf_vec3_destroy(&sjv_zaxis);
}

void sjf_mat4_lookAtLH_heap(sjs_vec3* camera, sjs_vec3* target, sjs_vec3* up, sjs_mat4_heap** _return) {
    sjs_vec3 sjt_call4;
    sjs_vec3* sjt_dot156;
    sjs_vec3* sjt_dot157;
    sjs_vec3* sjt_dot158;
    sjs_vec3* sjt_dot159;
    sjs_vec3* sjt_dot160;
    sjs_vec3* sjt_dot161;
    sjs_vec3* sjt_dot162;
    sjs_vec3* sjt_dot163;
    sjs_vec3* sjt_dot164;
    sjs_vec3* sjt_functionParam36;
    sjs_vec3* sjt_functionParam37;
    sjs_vec3* sjt_functionParam38;
    sjs_vec3* sjt_functionParam39;
    sjs_vec3* sjt_functionParam40;
    sjs_vec3* sjt_functionParam41;
    float sjt_math201;
    float sjt_math202;
    float sjt_math203;
    float sjt_math204;
    float sjt_math205;
    float sjt_math206;
    sjs_vec3* sjt_parent25;
    sjs_vec3* sjt_parent26;
    sjs_vec3* sjt_parent27;
    sjs_vec3* sjt_parent28;
    sjs_vec3* sjt_parent29;
    sjs_vec3* sjt_parent30;
    sjs_vec3* sjt_parent31;
    sjs_vec3* sjt_parent32;
    sjs_vec3 sjv_temp;
    sjs_vec3 sjv_xaxis;
    sjs_vec3 sjv_yaxis;
    sjs_vec3 sjv_zaxis;

#line 119 ".\..\lib\ui\mat4.sj"
    sjt_parent25 = target;
#line 119
    sjt_functionParam36 = camera;
#line 0 ""
    sjf_vec3_subtract(sjt_parent25, sjt_functionParam36, &sjv_temp);
#line 29 ".\..\lib\ui\vec3.sj"
    sjt_parent26 = &sjv_temp;
#line 0 ""
    sjf_vec3_normalize(sjt_parent26, &sjv_zaxis);
#line 119 ".\..\lib\ui\mat4.sj"
    sjt_parent28 = up;
#line 122
    sjt_functionParam37 = &sjv_zaxis;
#line 0 ""
    sjf_vec3_cross(sjt_parent28, sjt_functionParam37, &sjt_call4);
#line 122 ".\..\lib\ui\mat4.sj"
    sjt_parent27 = &sjt_call4;
#line 0 ""
    sjf_vec3_normalize(sjt_parent27, &sjv_xaxis);
#line 38 ".\..\lib\ui\vec3.sj"
    sjt_parent29 = &sjv_zaxis;
#line 123 ".\..\lib\ui\mat4.sj"
    sjt_functionParam38 = &sjv_xaxis;
#line 0 ""
    sjf_vec3_cross(sjt_parent29, sjt_functionParam38, &sjv_yaxis);
    (*_return) = (sjs_mat4_heap*)malloc(sizeof(sjs_mat4_heap));
    (*_return)->_refCount = 1;
#line 1 ".\..\lib\ui\vec3.sj"
    sjt_dot156 = &sjv_xaxis;
#line 124 ".\..\lib\ui\mat4.sj"
    (*_return)->m00 = (sjt_dot156)->x;
#line 1 ".\..\lib\ui\vec3.sj"
    sjt_dot157 = &sjv_yaxis;
#line 124 ".\..\lib\ui\mat4.sj"
    (*_return)->m01 = (sjt_dot157)->x;
#line 1 ".\..\lib\ui\vec3.sj"
    sjt_dot158 = &sjv_zaxis;
#line 124 ".\..\lib\ui\mat4.sj"
    (*_return)->m02 = (sjt_dot158)->x;
#line 128
    (*_return)->m03 = 0.0f;
#line 1 ".\..\lib\ui\vec3.sj"
    sjt_dot159 = &sjv_xaxis;
#line 124 ".\..\lib\ui\mat4.sj"
    (*_return)->m10 = (sjt_dot159)->y;
#line 1 ".\..\lib\ui\vec3.sj"
    sjt_dot160 = &sjv_yaxis;
#line 124 ".\..\lib\ui\mat4.sj"
    (*_return)->m11 = (sjt_dot160)->y;
#line 1 ".\..\lib\ui\vec3.sj"
    sjt_dot161 = &sjv_zaxis;
#line 124 ".\..\lib\ui\mat4.sj"
    (*_return)->m12 = (sjt_dot161)->y;
#line 132
    (*_return)->m13 = 0.0f;
#line 1 ".\..\lib\ui\vec3.sj"
    sjt_dot162 = &sjv_xaxis;
#line 124 ".\..\lib\ui\mat4.sj"
    (*_return)->m20 = (sjt_dot162)->z;
#line 1 ".\..\lib\ui\vec3.sj"
    sjt_dot163 = &sjv_yaxis;
#line 124 ".\..\lib\ui\mat4.sj"
    (*_return)->m21 = (sjt_dot163)->z;
#line 1 ".\..\lib\ui\vec3.sj"
    sjt_dot164 = &sjv_zaxis;
#line 124 ".\..\lib\ui\mat4.sj"
    (*_return)->m22 = (sjt_dot164)->z;
#line 136
    (*_return)->m23 = 0.0f;
#line 137
    sjt_math201 = 0.0f;
#line 46 ".\..\lib\ui\vec3.sj"
    sjt_parent30 = &sjv_xaxis;
#line 119 ".\..\lib\ui\mat4.sj"
    sjt_functionParam39 = camera;
#line 0 ""
    sjf_vec3_dot(sjt_parent30, sjt_functionParam39, &sjt_math202);
#line 137 ".\..\lib\ui\mat4.sj"
    (*_return)->m30 = sjt_math201 - sjt_math202;
#line 138
    sjt_math203 = 0.0f;
#line 46 ".\..\lib\ui\vec3.sj"
    sjt_parent31 = &sjv_yaxis;
#line 119 ".\..\lib\ui\mat4.sj"
    sjt_functionParam40 = camera;
#line 0 ""
    sjf_vec3_dot(sjt_parent31, sjt_functionParam40, &sjt_math204);
#line 138 ".\..\lib\ui\mat4.sj"
    (*_return)->m31 = sjt_math203 - sjt_math204;
#line 139
    sjt_math205 = 0.0f;
#line 46 ".\..\lib\ui\vec3.sj"
    sjt_parent32 = &sjv_zaxis;
#line 119 ".\..\lib\ui\mat4.sj"
    sjt_functionParam41 = camera;
#line 0 ""
    sjf_vec3_dot(sjt_parent32, sjt_functionParam41, &sjt_math206);
#line 139 ".\..\lib\ui\mat4.sj"
    (*_return)->m32 = sjt_math205 - sjt_math206;
#line 140
    (*_return)->m33 = 1.0f;
#line 0 ""
    sjf_mat4_heap((*_return));

    sjf_vec3_destroy(&sjt_call4);
    sjf_vec3_destroy(&sjv_temp);
    sjf_vec3_destroy(&sjv_xaxis);
    sjf_vec3_destroy(&sjv_yaxis);
    sjf_vec3_destroy(&sjv_zaxis);
}

void sjf_mat4_multiply(sjs_mat4* _parent, sjs_mat4* m, sjs_mat4* _return) {
    sjs_mat4* sjt_dot222;
    sjs_mat4* sjt_dot223;
    sjs_mat4* sjt_dot224;
    sjs_mat4* sjt_dot225;
    sjs_mat4* sjt_dot226;
    sjs_mat4* sjt_dot227;
    sjs_mat4* sjt_dot228;
    sjs_mat4* sjt_dot229;
    sjs_mat4* sjt_dot230;
    sjs_mat4* sjt_dot231;
    sjs_mat4* sjt_dot232;
    sjs_mat4* sjt_dot233;
    sjs_mat4* sjt_dot234;
    sjs_mat4* sjt_dot235;
    sjs_mat4* sjt_dot236;
    sjs_mat4* sjt_dot237;
    sjs_mat4* sjt_dot238;
    sjs_mat4* sjt_dot239;
    sjs_mat4* sjt_dot240;
    sjs_mat4* sjt_dot241;
    sjs_mat4* sjt_dot242;
    sjs_mat4* sjt_dot243;
    sjs_mat4* sjt_dot244;
    sjs_mat4* sjt_dot245;
    sjs_mat4* sjt_dot246;
    sjs_mat4* sjt_dot247;
    sjs_mat4* sjt_dot248;
    sjs_mat4* sjt_dot249;
    sjs_mat4* sjt_dot250;
    sjs_mat4* sjt_dot251;
    sjs_mat4* sjt_dot252;
    sjs_mat4* sjt_dot253;
    sjs_mat4* sjt_dot254;
    sjs_mat4* sjt_dot255;
    sjs_mat4* sjt_dot256;
    sjs_mat4* sjt_dot257;
    sjs_mat4* sjt_dot258;
    sjs_mat4* sjt_dot259;
    sjs_mat4* sjt_dot260;
    sjs_mat4* sjt_dot261;
    sjs_mat4* sjt_dot262;
    sjs_mat4* sjt_dot263;
    sjs_mat4* sjt_dot264;
    sjs_mat4* sjt_dot265;
    sjs_mat4* sjt_dot266;
    sjs_mat4* sjt_dot267;
    sjs_mat4* sjt_dot268;
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

#line 19 ".\..\lib\ui\mat4.sj"
    sjt_dot222 = m;
#line 21
    sjt_math507 = (sjt_dot222)->m00;
#line 19
    sjt_dot223 = _parent;
#line 21
    sjt_math508 = (sjt_dot223)->m00;
#line 21
    sjt_math505 = sjt_math507 * sjt_math508;
#line 19
    sjt_dot224 = m;
#line 21
    sjt_math509 = (sjt_dot224)->m01;
#line 19
    sjt_dot225 = _parent;
#line 21
    sjt_math510 = (sjt_dot225)->m10;
#line 21
    sjt_math506 = sjt_math509 * sjt_math510;
#line 21
    sjt_math503 = sjt_math505 + sjt_math506;
#line 19
    sjt_dot226 = m;
#line 21
    sjt_math511 = (sjt_dot226)->m02;
#line 19
    sjt_dot227 = _parent;
#line 21
    sjt_math512 = (sjt_dot227)->m20;
#line 21
    sjt_math504 = sjt_math511 * sjt_math512;
#line 21
    sjt_math501 = sjt_math503 + sjt_math504;
#line 19
    sjt_dot228 = m;
#line 21
    sjt_math513 = (sjt_dot228)->m03;
#line 19
    sjt_dot229 = _parent;
#line 21
    sjt_math514 = (sjt_dot229)->m30;
#line 21
    sjt_math502 = sjt_math513 * sjt_math514;
#line 21
    _return->m00 = sjt_math501 + sjt_math502;
#line 19
    sjt_dot230 = m;
#line 22
    sjt_math521 = (sjt_dot230)->m00;
#line 19
    sjt_dot231 = _parent;
#line 22
    sjt_math522 = (sjt_dot231)->m01;
#line 22
    sjt_math519 = sjt_math521 * sjt_math522;
#line 19
    sjt_dot232 = m;
#line 22
    sjt_math523 = (sjt_dot232)->m01;
#line 19
    sjt_dot233 = _parent;
#line 22
    sjt_math524 = (sjt_dot233)->m11;
#line 22
    sjt_math520 = sjt_math523 * sjt_math524;
#line 22
    sjt_math517 = sjt_math519 + sjt_math520;
#line 19
    sjt_dot234 = m;
#line 22
    sjt_math525 = (sjt_dot234)->m02;
#line 19
    sjt_dot235 = _parent;
#line 22
    sjt_math526 = (sjt_dot235)->m21;
#line 22
    sjt_math518 = sjt_math525 * sjt_math526;
#line 22
    sjt_math515 = sjt_math517 + sjt_math518;
#line 19
    sjt_dot236 = m;
#line 22
    sjt_math527 = (sjt_dot236)->m03;
#line 19
    sjt_dot237 = _parent;
#line 22
    sjt_math528 = (sjt_dot237)->m31;
#line 22
    sjt_math516 = sjt_math527 * sjt_math528;
#line 22
    _return->m01 = sjt_math515 + sjt_math516;
#line 19
    sjt_dot238 = m;
#line 23
    sjt_math535 = (sjt_dot238)->m00;
#line 19
    sjt_dot239 = _parent;
#line 23
    sjt_math536 = (sjt_dot239)->m02;
#line 23
    sjt_math533 = sjt_math535 * sjt_math536;
#line 19
    sjt_dot240 = m;
#line 23
    sjt_math537 = (sjt_dot240)->m01;
#line 19
    sjt_dot241 = _parent;
#line 23
    sjt_math538 = (sjt_dot241)->m12;
#line 23
    sjt_math534 = sjt_math537 * sjt_math538;
#line 23
    sjt_math531 = sjt_math533 + sjt_math534;
#line 19
    sjt_dot242 = m;
#line 23
    sjt_math539 = (sjt_dot242)->m02;
#line 19
    sjt_dot243 = _parent;
#line 23
    sjt_math540 = (sjt_dot243)->m22;
#line 23
    sjt_math532 = sjt_math539 * sjt_math540;
#line 23
    sjt_math529 = sjt_math531 + sjt_math532;
#line 19
    sjt_dot244 = m;
#line 23
    sjt_math541 = (sjt_dot244)->m03;
#line 19
    sjt_dot245 = _parent;
#line 23
    sjt_math542 = (sjt_dot245)->m32;
#line 23
    sjt_math530 = sjt_math541 * sjt_math542;
#line 23
    _return->m02 = sjt_math529 + sjt_math530;
#line 19
    sjt_dot246 = m;
#line 24
    sjt_math549 = (sjt_dot246)->m00;
#line 19
    sjt_dot247 = _parent;
#line 24
    sjt_math550 = (sjt_dot247)->m03;
#line 24
    sjt_math547 = sjt_math549 * sjt_math550;
#line 19
    sjt_dot248 = m;
#line 24
    sjt_math551 = (sjt_dot248)->m01;
#line 19
    sjt_dot249 = _parent;
#line 24
    sjt_math552 = (sjt_dot249)->m13;
#line 24
    sjt_math548 = sjt_math551 * sjt_math552;
#line 24
    sjt_math545 = sjt_math547 + sjt_math548;
#line 19
    sjt_dot250 = m;
#line 24
    sjt_math553 = (sjt_dot250)->m02;
#line 19
    sjt_dot251 = _parent;
#line 24
    sjt_math554 = (sjt_dot251)->m23;
#line 24
    sjt_math546 = sjt_math553 * sjt_math554;
#line 24
    sjt_math543 = sjt_math545 + sjt_math546;
#line 19
    sjt_dot252 = m;
#line 24
    sjt_math555 = (sjt_dot252)->m03;
#line 19
    sjt_dot253 = _parent;
#line 24
    sjt_math556 = (sjt_dot253)->m33;
#line 24
    sjt_math544 = sjt_math555 * sjt_math556;
#line 24
    _return->m03 = sjt_math543 + sjt_math544;
#line 19
    sjt_dot254 = m;
#line 25
    sjt_math563 = (sjt_dot254)->m10;
#line 19
    sjt_dot255 = _parent;
#line 25
    sjt_math564 = (sjt_dot255)->m00;
#line 25
    sjt_math561 = sjt_math563 * sjt_math564;
#line 19
    sjt_dot256 = m;
#line 25
    sjt_math565 = (sjt_dot256)->m11;
#line 19
    sjt_dot257 = _parent;
#line 25
    sjt_math566 = (sjt_dot257)->m10;
#line 25
    sjt_math562 = sjt_math565 * sjt_math566;
#line 25
    sjt_math559 = sjt_math561 + sjt_math562;
#line 19
    sjt_dot258 = m;
#line 25
    sjt_math567 = (sjt_dot258)->m12;
#line 19
    sjt_dot259 = _parent;
#line 25
    sjt_math568 = (sjt_dot259)->m20;
#line 25
    sjt_math560 = sjt_math567 * sjt_math568;
#line 25
    sjt_math557 = sjt_math559 + sjt_math560;
#line 19
    sjt_dot260 = m;
#line 25
    sjt_math569 = (sjt_dot260)->m13;
#line 19
    sjt_dot261 = _parent;
#line 25
    sjt_math570 = (sjt_dot261)->m30;
#line 25
    sjt_math558 = sjt_math569 * sjt_math570;
#line 25
    _return->m10 = sjt_math557 + sjt_math558;
#line 19
    sjt_dot262 = m;
#line 26
    sjt_math577 = (sjt_dot262)->m10;
#line 19
    sjt_dot263 = _parent;
#line 26
    sjt_math578 = (sjt_dot263)->m01;
#line 26
    sjt_math575 = sjt_math577 * sjt_math578;
#line 19
    sjt_dot264 = m;
#line 26
    sjt_math579 = (sjt_dot264)->m11;
#line 19
    sjt_dot265 = _parent;
#line 26
    sjt_math580 = (sjt_dot265)->m11;
#line 26
    sjt_math576 = sjt_math579 * sjt_math580;
#line 26
    sjt_math573 = sjt_math575 + sjt_math576;
#line 19
    sjt_dot266 = m;
#line 26
    sjt_math581 = (sjt_dot266)->m12;
#line 19
    sjt_dot267 = _parent;
#line 26
    sjt_math582 = (sjt_dot267)->m21;
#line 26
    sjt_math574 = sjt_math581 * sjt_math582;
#line 26
    sjt_math571 = sjt_math573 + sjt_math574;
#line 19
    sjt_dot268 = m;
#line 26
    sjt_math583 = (sjt_dot268)->m13;
#line 19
    sjt_dot269 = _parent;
#line 26
    sjt_math584 = (sjt_dot269)->m31;
#line 26
    sjt_math572 = sjt_math583 * sjt_math584;
#line 26
    _return->m11 = sjt_math571 + sjt_math572;
#line 19
    sjt_dot270 = m;
#line 27
    sjt_math591 = (sjt_dot270)->m10;
#line 19
    sjt_dot271 = _parent;
#line 27
    sjt_math592 = (sjt_dot271)->m02;
#line 27
    sjt_math589 = sjt_math591 * sjt_math592;
#line 19
    sjt_dot272 = m;
#line 27
    sjt_math593 = (sjt_dot272)->m11;
#line 19
    sjt_dot273 = _parent;
#line 27
    sjt_math594 = (sjt_dot273)->m12;
#line 27
    sjt_math590 = sjt_math593 * sjt_math594;
#line 27
    sjt_math587 = sjt_math589 + sjt_math590;
#line 19
    sjt_dot274 = m;
#line 27
    sjt_math595 = (sjt_dot274)->m12;
#line 19
    sjt_dot275 = _parent;
#line 27
    sjt_math596 = (sjt_dot275)->m22;
#line 27
    sjt_math588 = sjt_math595 * sjt_math596;
#line 27
    sjt_math585 = sjt_math587 + sjt_math588;
#line 19
    sjt_dot276 = m;
#line 27
    sjt_math597 = (sjt_dot276)->m13;
#line 19
    sjt_dot277 = _parent;
#line 27
    sjt_math598 = (sjt_dot277)->m32;
#line 27
    sjt_math586 = sjt_math597 * sjt_math598;
#line 27
    _return->m12 = sjt_math585 + sjt_math586;
#line 19
    sjt_dot278 = m;
#line 28
    sjt_math605 = (sjt_dot278)->m10;
#line 19
    sjt_dot279 = _parent;
#line 28
    sjt_math606 = (sjt_dot279)->m03;
#line 28
    sjt_math603 = sjt_math605 * sjt_math606;
#line 19
    sjt_dot280 = m;
#line 28
    sjt_math607 = (sjt_dot280)->m11;
#line 19
    sjt_dot281 = _parent;
#line 28
    sjt_math608 = (sjt_dot281)->m13;
#line 28
    sjt_math604 = sjt_math607 * sjt_math608;
#line 28
    sjt_math601 = sjt_math603 + sjt_math604;
#line 19
    sjt_dot282 = m;
#line 28
    sjt_math609 = (sjt_dot282)->m12;
#line 19
    sjt_dot283 = _parent;
#line 28
    sjt_math610 = (sjt_dot283)->m23;
#line 28
    sjt_math602 = sjt_math609 * sjt_math610;
#line 28
    sjt_math599 = sjt_math601 + sjt_math602;
#line 19
    sjt_dot284 = m;
#line 28
    sjt_math611 = (sjt_dot284)->m13;
#line 19
    sjt_dot285 = _parent;
#line 28
    sjt_math612 = (sjt_dot285)->m33;
#line 28
    sjt_math600 = sjt_math611 * sjt_math612;
#line 28
    _return->m13 = sjt_math599 + sjt_math600;
#line 19
    sjt_dot286 = m;
#line 29
    sjt_math619 = (sjt_dot286)->m20;
#line 19
    sjt_dot287 = _parent;
#line 29
    sjt_math620 = (sjt_dot287)->m00;
#line 29
    sjt_math617 = sjt_math619 * sjt_math620;
#line 19
    sjt_dot288 = m;
#line 29
    sjt_math621 = (sjt_dot288)->m21;
#line 19
    sjt_dot289 = _parent;
#line 29
    sjt_math622 = (sjt_dot289)->m10;
#line 29
    sjt_math618 = sjt_math621 * sjt_math622;
#line 29
    sjt_math615 = sjt_math617 + sjt_math618;
#line 19
    sjt_dot290 = m;
#line 29
    sjt_math623 = (sjt_dot290)->m22;
#line 19
    sjt_dot291 = _parent;
#line 29
    sjt_math624 = (sjt_dot291)->m20;
#line 29
    sjt_math616 = sjt_math623 * sjt_math624;
#line 29
    sjt_math613 = sjt_math615 + sjt_math616;
#line 19
    sjt_dot292 = m;
#line 29
    sjt_math625 = (sjt_dot292)->m23;
#line 19
    sjt_dot293 = _parent;
#line 29
    sjt_math626 = (sjt_dot293)->m30;
#line 29
    sjt_math614 = sjt_math625 * sjt_math626;
#line 29
    _return->m20 = sjt_math613 + sjt_math614;
#line 19
    sjt_dot294 = m;
#line 30
    sjt_math633 = (sjt_dot294)->m20;
#line 19
    sjt_dot295 = _parent;
#line 30
    sjt_math634 = (sjt_dot295)->m01;
#line 30
    sjt_math631 = sjt_math633 * sjt_math634;
#line 19
    sjt_dot296 = m;
#line 30
    sjt_math635 = (sjt_dot296)->m21;
#line 19
    sjt_dot297 = _parent;
#line 30
    sjt_math636 = (sjt_dot297)->m11;
#line 30
    sjt_math632 = sjt_math635 * sjt_math636;
#line 30
    sjt_math629 = sjt_math631 + sjt_math632;
#line 19
    sjt_dot298 = m;
#line 30
    sjt_math637 = (sjt_dot298)->m22;
#line 19
    sjt_dot299 = _parent;
#line 30
    sjt_math638 = (sjt_dot299)->m21;
#line 30
    sjt_math630 = sjt_math637 * sjt_math638;
#line 30
    sjt_math627 = sjt_math629 + sjt_math630;
#line 19
    sjt_dot300 = m;
#line 30
    sjt_math639 = (sjt_dot300)->m23;
#line 19
    sjt_dot301 = _parent;
#line 30
    sjt_math640 = (sjt_dot301)->m31;
#line 30
    sjt_math628 = sjt_math639 * sjt_math640;
#line 30
    _return->m21 = sjt_math627 + sjt_math628;
#line 19
    sjt_dot302 = m;
#line 31
    sjt_math647 = (sjt_dot302)->m20;
#line 19
    sjt_dot303 = _parent;
#line 31
    sjt_math648 = (sjt_dot303)->m02;
#line 31
    sjt_math645 = sjt_math647 * sjt_math648;
#line 19
    sjt_dot304 = m;
#line 31
    sjt_math649 = (sjt_dot304)->m21;
#line 19
    sjt_dot305 = _parent;
#line 31
    sjt_math650 = (sjt_dot305)->m12;
#line 31
    sjt_math646 = sjt_math649 * sjt_math650;
#line 31
    sjt_math643 = sjt_math645 + sjt_math646;
#line 19
    sjt_dot306 = m;
#line 31
    sjt_math651 = (sjt_dot306)->m22;
#line 19
    sjt_dot307 = _parent;
#line 31
    sjt_math652 = (sjt_dot307)->m22;
#line 31
    sjt_math644 = sjt_math651 * sjt_math652;
#line 31
    sjt_math641 = sjt_math643 + sjt_math644;
#line 19
    sjt_dot308 = m;
#line 31
    sjt_math653 = (sjt_dot308)->m23;
#line 19
    sjt_dot309 = _parent;
#line 31
    sjt_math654 = (sjt_dot309)->m32;
#line 31
    sjt_math642 = sjt_math653 * sjt_math654;
#line 31
    _return->m22 = sjt_math641 + sjt_math642;
#line 19
    sjt_dot310 = m;
#line 32
    sjt_math661 = (sjt_dot310)->m20;
#line 19
    sjt_dot311 = _parent;
#line 32
    sjt_math662 = (sjt_dot311)->m03;
#line 32
    sjt_math659 = sjt_math661 * sjt_math662;
#line 19
    sjt_dot312 = m;
#line 32
    sjt_math663 = (sjt_dot312)->m21;
#line 19
    sjt_dot313 = _parent;
#line 32
    sjt_math664 = (sjt_dot313)->m13;
#line 32
    sjt_math660 = sjt_math663 * sjt_math664;
#line 32
    sjt_math657 = sjt_math659 + sjt_math660;
#line 19
    sjt_dot314 = m;
#line 32
    sjt_math665 = (sjt_dot314)->m22;
#line 19
    sjt_dot315 = _parent;
#line 32
    sjt_math666 = (sjt_dot315)->m23;
#line 32
    sjt_math658 = sjt_math665 * sjt_math666;
#line 32
    sjt_math655 = sjt_math657 + sjt_math658;
#line 19
    sjt_dot316 = m;
#line 32
    sjt_math667 = (sjt_dot316)->m23;
#line 19
    sjt_dot317 = _parent;
#line 32
    sjt_math668 = (sjt_dot317)->m33;
#line 32
    sjt_math656 = sjt_math667 * sjt_math668;
#line 32
    _return->m23 = sjt_math655 + sjt_math656;
#line 19
    sjt_dot318 = m;
#line 33
    sjt_math675 = (sjt_dot318)->m30;
#line 19
    sjt_dot319 = _parent;
#line 33
    sjt_math676 = (sjt_dot319)->m00;
#line 33
    sjt_math673 = sjt_math675 * sjt_math676;
#line 19
    sjt_dot320 = m;
#line 33
    sjt_math677 = (sjt_dot320)->m31;
#line 19
    sjt_dot321 = _parent;
#line 33
    sjt_math678 = (sjt_dot321)->m10;
#line 33
    sjt_math674 = sjt_math677 * sjt_math678;
#line 33
    sjt_math671 = sjt_math673 + sjt_math674;
#line 19
    sjt_dot322 = m;
#line 33
    sjt_math679 = (sjt_dot322)->m32;
#line 19
    sjt_dot323 = _parent;
#line 33
    sjt_math680 = (sjt_dot323)->m20;
#line 33
    sjt_math672 = sjt_math679 * sjt_math680;
#line 33
    sjt_math669 = sjt_math671 + sjt_math672;
#line 19
    sjt_dot324 = m;
#line 33
    sjt_math681 = (sjt_dot324)->m33;
#line 19
    sjt_dot325 = _parent;
#line 33
    sjt_math682 = (sjt_dot325)->m30;
#line 33
    sjt_math670 = sjt_math681 * sjt_math682;
#line 33
    _return->m30 = sjt_math669 + sjt_math670;
#line 19
    sjt_dot326 = m;
#line 34
    sjt_math689 = (sjt_dot326)->m30;
#line 19
    sjt_dot327 = _parent;
#line 34
    sjt_math690 = (sjt_dot327)->m01;
#line 34
    sjt_math687 = sjt_math689 * sjt_math690;
#line 19
    sjt_dot328 = m;
#line 34
    sjt_math691 = (sjt_dot328)->m31;
#line 19
    sjt_dot329 = _parent;
#line 34
    sjt_math692 = (sjt_dot329)->m11;
#line 34
    sjt_math688 = sjt_math691 * sjt_math692;
#line 34
    sjt_math685 = sjt_math687 + sjt_math688;
#line 19
    sjt_dot330 = m;
#line 34
    sjt_math693 = (sjt_dot330)->m32;
#line 19
    sjt_dot331 = _parent;
#line 34
    sjt_math694 = (sjt_dot331)->m21;
#line 34
    sjt_math686 = sjt_math693 * sjt_math694;
#line 34
    sjt_math683 = sjt_math685 + sjt_math686;
#line 19
    sjt_dot332 = m;
#line 34
    sjt_math695 = (sjt_dot332)->m33;
#line 19
    sjt_dot333 = _parent;
#line 34
    sjt_math696 = (sjt_dot333)->m31;
#line 34
    sjt_math684 = sjt_math695 * sjt_math696;
#line 34
    _return->m31 = sjt_math683 + sjt_math684;
#line 19
    sjt_dot334 = m;
#line 35
    sjt_math703 = (sjt_dot334)->m30;
#line 19
    sjt_dot335 = _parent;
#line 35
    sjt_math704 = (sjt_dot335)->m02;
#line 35
    sjt_math701 = sjt_math703 * sjt_math704;
#line 19
    sjt_dot336 = m;
#line 35
    sjt_math705 = (sjt_dot336)->m31;
#line 19
    sjt_dot337 = _parent;
#line 35
    sjt_math706 = (sjt_dot337)->m12;
#line 35
    sjt_math702 = sjt_math705 * sjt_math706;
#line 35
    sjt_math699 = sjt_math701 + sjt_math702;
#line 19
    sjt_dot338 = m;
#line 35
    sjt_math707 = (sjt_dot338)->m32;
#line 19
    sjt_dot339 = _parent;
#line 35
    sjt_math708 = (sjt_dot339)->m22;
#line 35
    sjt_math700 = sjt_math707 * sjt_math708;
#line 35
    sjt_math697 = sjt_math699 + sjt_math700;
#line 19
    sjt_dot340 = m;
#line 35
    sjt_math709 = (sjt_dot340)->m33;
#line 19
    sjt_dot341 = _parent;
#line 35
    sjt_math710 = (sjt_dot341)->m32;
#line 35
    sjt_math698 = sjt_math709 * sjt_math710;
#line 35
    _return->m32 = sjt_math697 + sjt_math698;
#line 19
    sjt_dot342 = m;
#line 36
    sjt_math717 = (sjt_dot342)->m30;
#line 19
    sjt_dot343 = _parent;
#line 36
    sjt_math718 = (sjt_dot343)->m03;
#line 36
    sjt_math715 = sjt_math717 * sjt_math718;
#line 19
    sjt_dot344 = m;
#line 36
    sjt_math719 = (sjt_dot344)->m31;
#line 19
    sjt_dot345 = _parent;
#line 36
    sjt_math720 = (sjt_dot345)->m13;
#line 36
    sjt_math716 = sjt_math719 * sjt_math720;
#line 36
    sjt_math713 = sjt_math715 + sjt_math716;
#line 19
    sjt_dot346 = m;
#line 36
    sjt_math721 = (sjt_dot346)->m32;
#line 19
    sjt_dot347 = _parent;
#line 36
    sjt_math722 = (sjt_dot347)->m23;
#line 36
    sjt_math714 = sjt_math721 * sjt_math722;
#line 36
    sjt_math711 = sjt_math713 + sjt_math714;
#line 19
    sjt_dot348 = m;
#line 36
    sjt_math723 = (sjt_dot348)->m33;
#line 19
    sjt_dot349 = _parent;
#line 36
    sjt_math724 = (sjt_dot349)->m33;
#line 36
    sjt_math712 = sjt_math723 * sjt_math724;
#line 36
    _return->m33 = sjt_math711 + sjt_math712;
#line 0 ""
    sjf_mat4(_return);
}

void sjf_mat4_multiply_f32(sjs_mat4* _parent, float x, sjs_mat4* _return) {
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

#line 40 ".\..\lib\ui\mat4.sj"
    sjt_dot800 = _parent;
#line 42
    sjt_math1493 = (sjt_dot800)->m00;
#line 40
    sjt_math1494 = x;
#line 42
    _return->m00 = sjt_math1493 * sjt_math1494;
#line 40
    sjt_dot801 = _parent;
#line 43
    sjt_math1495 = (sjt_dot801)->m01;
#line 40
    sjt_math1496 = x;
#line 43
    _return->m01 = sjt_math1495 * sjt_math1496;
#line 40
    sjt_dot802 = _parent;
#line 44
    sjt_math1497 = (sjt_dot802)->m02;
#line 40
    sjt_math1498 = x;
#line 44
    _return->m02 = sjt_math1497 * sjt_math1498;
#line 40
    sjt_dot803 = _parent;
#line 45
    sjt_math1499 = (sjt_dot803)->m03;
#line 40
    sjt_math1500 = x;
#line 45
    _return->m03 = sjt_math1499 * sjt_math1500;
#line 40
    sjt_dot804 = _parent;
#line 46
    sjt_math1501 = (sjt_dot804)->m10;
#line 40
    sjt_math1502 = x;
#line 46
    _return->m10 = sjt_math1501 * sjt_math1502;
#line 40
    sjt_dot805 = _parent;
#line 47
    sjt_math1503 = (sjt_dot805)->m11;
#line 40
    sjt_math1504 = x;
#line 47
    _return->m11 = sjt_math1503 * sjt_math1504;
#line 40
    sjt_dot806 = _parent;
#line 48
    sjt_math1505 = (sjt_dot806)->m12;
#line 40
    sjt_math1506 = x;
#line 48
    _return->m12 = sjt_math1505 * sjt_math1506;
#line 40
    sjt_dot807 = _parent;
#line 49
    sjt_math1507 = (sjt_dot807)->m13;
#line 40
    sjt_math1508 = x;
#line 49
    _return->m13 = sjt_math1507 * sjt_math1508;
#line 40
    sjt_dot808 = _parent;
#line 50
    sjt_math1509 = (sjt_dot808)->m20;
#line 40
    sjt_math1510 = x;
#line 50
    _return->m20 = sjt_math1509 * sjt_math1510;
#line 40
    sjt_dot809 = _parent;
#line 51
    sjt_math1511 = (sjt_dot809)->m21;
#line 40
    sjt_math1512 = x;
#line 51
    _return->m21 = sjt_math1511 * sjt_math1512;
#line 40
    sjt_dot810 = _parent;
#line 52
    sjt_math1513 = (sjt_dot810)->m22;
#line 40
    sjt_math1514 = x;
#line 52
    _return->m22 = sjt_math1513 * sjt_math1514;
#line 40
    sjt_dot811 = _parent;
#line 53
    sjt_math1515 = (sjt_dot811)->m23;
#line 40
    sjt_math1516 = x;
#line 53
    _return->m23 = sjt_math1515 * sjt_math1516;
#line 40
    sjt_dot812 = _parent;
#line 54
    sjt_math1517 = (sjt_dot812)->m30;
#line 40
    sjt_math1518 = x;
#line 54
    _return->m30 = sjt_math1517 * sjt_math1518;
#line 40
    sjt_dot813 = _parent;
#line 55
    sjt_math1519 = (sjt_dot813)->m31;
#line 40
    sjt_math1520 = x;
#line 55
    _return->m31 = sjt_math1519 * sjt_math1520;
#line 40
    sjt_dot814 = _parent;
#line 56
    sjt_math1521 = (sjt_dot814)->m32;
#line 40
    sjt_math1522 = x;
#line 56
    _return->m32 = sjt_math1521 * sjt_math1522;
#line 40
    sjt_dot815 = _parent;
#line 57
    sjt_math1523 = (sjt_dot815)->m33;
#line 40
    sjt_math1524 = x;
#line 57
    _return->m33 = sjt_math1523 * sjt_math1524;
#line 0 ""
    sjf_mat4(_return);
}

void sjf_mat4_multiply_f32_heap(sjs_mat4* _parent, float x, sjs_mat4_heap** _return) {
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

    (*_return) = (sjs_mat4_heap*)malloc(sizeof(sjs_mat4_heap));
    (*_return)->_refCount = 1;
#line 40 ".\..\lib\ui\mat4.sj"
    sjt_dot816 = _parent;
#line 42
    sjt_math1525 = (sjt_dot816)->m00;
#line 40
    sjt_math1526 = x;
#line 42
    (*_return)->m00 = sjt_math1525 * sjt_math1526;
#line 40
    sjt_dot817 = _parent;
#line 43
    sjt_math1527 = (sjt_dot817)->m01;
#line 40
    sjt_math1528 = x;
#line 43
    (*_return)->m01 = sjt_math1527 * sjt_math1528;
#line 40
    sjt_dot818 = _parent;
#line 44
    sjt_math1529 = (sjt_dot818)->m02;
#line 40
    sjt_math1530 = x;
#line 44
    (*_return)->m02 = sjt_math1529 * sjt_math1530;
#line 40
    sjt_dot819 = _parent;
#line 45
    sjt_math1531 = (sjt_dot819)->m03;
#line 40
    sjt_math1532 = x;
#line 45
    (*_return)->m03 = sjt_math1531 * sjt_math1532;
#line 40
    sjt_dot820 = _parent;
#line 46
    sjt_math1533 = (sjt_dot820)->m10;
#line 40
    sjt_math1534 = x;
#line 46
    (*_return)->m10 = sjt_math1533 * sjt_math1534;
#line 40
    sjt_dot821 = _parent;
#line 47
    sjt_math1535 = (sjt_dot821)->m11;
#line 40
    sjt_math1536 = x;
#line 47
    (*_return)->m11 = sjt_math1535 * sjt_math1536;
#line 40
    sjt_dot822 = _parent;
#line 48
    sjt_math1537 = (sjt_dot822)->m12;
#line 40
    sjt_math1538 = x;
#line 48
    (*_return)->m12 = sjt_math1537 * sjt_math1538;
#line 40
    sjt_dot823 = _parent;
#line 49
    sjt_math1539 = (sjt_dot823)->m13;
#line 40
    sjt_math1540 = x;
#line 49
    (*_return)->m13 = sjt_math1539 * sjt_math1540;
#line 40
    sjt_dot824 = _parent;
#line 50
    sjt_math1541 = (sjt_dot824)->m20;
#line 40
    sjt_math1542 = x;
#line 50
    (*_return)->m20 = sjt_math1541 * sjt_math1542;
#line 40
    sjt_dot825 = _parent;
#line 51
    sjt_math1543 = (sjt_dot825)->m21;
#line 40
    sjt_math1544 = x;
#line 51
    (*_return)->m21 = sjt_math1543 * sjt_math1544;
#line 40
    sjt_dot826 = _parent;
#line 52
    sjt_math1545 = (sjt_dot826)->m22;
#line 40
    sjt_math1546 = x;
#line 52
    (*_return)->m22 = sjt_math1545 * sjt_math1546;
#line 40
    sjt_dot827 = _parent;
#line 53
    sjt_math1547 = (sjt_dot827)->m23;
#line 40
    sjt_math1548 = x;
#line 53
    (*_return)->m23 = sjt_math1547 * sjt_math1548;
#line 40
    sjt_dot828 = _parent;
#line 54
    sjt_math1549 = (sjt_dot828)->m30;
#line 40
    sjt_math1550 = x;
#line 54
    (*_return)->m30 = sjt_math1549 * sjt_math1550;
#line 40
    sjt_dot829 = _parent;
#line 55
    sjt_math1551 = (sjt_dot829)->m31;
#line 40
    sjt_math1552 = x;
#line 55
    (*_return)->m31 = sjt_math1551 * sjt_math1552;
#line 40
    sjt_dot830 = _parent;
#line 56
    sjt_math1553 = (sjt_dot830)->m32;
#line 40
    sjt_math1554 = x;
#line 56
    (*_return)->m32 = sjt_math1553 * sjt_math1554;
#line 40
    sjt_dot831 = _parent;
#line 57
    sjt_math1555 = (sjt_dot831)->m33;
#line 40
    sjt_math1556 = x;
#line 57
    (*_return)->m33 = sjt_math1555 * sjt_math1556;
#line 0 ""
    sjf_mat4_heap((*_return));
}

void sjf_mat4_multiply_heap(sjs_mat4* _parent, sjs_mat4* m, sjs_mat4_heap** _return) {
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

    (*_return) = (sjs_mat4_heap*)malloc(sizeof(sjs_mat4_heap));
    (*_return)->_refCount = 1;
#line 19 ".\..\lib\ui\mat4.sj"
    sjt_dot350 = m;
#line 21
    sjt_math731 = (sjt_dot350)->m00;
#line 19
    sjt_dot351 = _parent;
#line 21
    sjt_math732 = (sjt_dot351)->m00;
#line 21
    sjt_math729 = sjt_math731 * sjt_math732;
#line 19
    sjt_dot352 = m;
#line 21
    sjt_math733 = (sjt_dot352)->m01;
#line 19
    sjt_dot353 = _parent;
#line 21
    sjt_math734 = (sjt_dot353)->m10;
#line 21
    sjt_math730 = sjt_math733 * sjt_math734;
#line 21
    sjt_math727 = sjt_math729 + sjt_math730;
#line 19
    sjt_dot354 = m;
#line 21
    sjt_math735 = (sjt_dot354)->m02;
#line 19
    sjt_dot355 = _parent;
#line 21
    sjt_math736 = (sjt_dot355)->m20;
#line 21
    sjt_math728 = sjt_math735 * sjt_math736;
#line 21
    sjt_math725 = sjt_math727 + sjt_math728;
#line 19
    sjt_dot356 = m;
#line 21
    sjt_math737 = (sjt_dot356)->m03;
#line 19
    sjt_dot357 = _parent;
#line 21
    sjt_math738 = (sjt_dot357)->m30;
#line 21
    sjt_math726 = sjt_math737 * sjt_math738;
#line 21
    (*_return)->m00 = sjt_math725 + sjt_math726;
#line 19
    sjt_dot358 = m;
#line 22
    sjt_math745 = (sjt_dot358)->m00;
#line 19
    sjt_dot359 = _parent;
#line 22
    sjt_math746 = (sjt_dot359)->m01;
#line 22
    sjt_math743 = sjt_math745 * sjt_math746;
#line 19
    sjt_dot360 = m;
#line 22
    sjt_math747 = (sjt_dot360)->m01;
#line 19
    sjt_dot361 = _parent;
#line 22
    sjt_math748 = (sjt_dot361)->m11;
#line 22
    sjt_math744 = sjt_math747 * sjt_math748;
#line 22
    sjt_math741 = sjt_math743 + sjt_math744;
#line 19
    sjt_dot362 = m;
#line 22
    sjt_math749 = (sjt_dot362)->m02;
#line 19
    sjt_dot363 = _parent;
#line 22
    sjt_math750 = (sjt_dot363)->m21;
#line 22
    sjt_math742 = sjt_math749 * sjt_math750;
#line 22
    sjt_math739 = sjt_math741 + sjt_math742;
#line 19
    sjt_dot364 = m;
#line 22
    sjt_math751 = (sjt_dot364)->m03;
#line 19
    sjt_dot365 = _parent;
#line 22
    sjt_math752 = (sjt_dot365)->m31;
#line 22
    sjt_math740 = sjt_math751 * sjt_math752;
#line 22
    (*_return)->m01 = sjt_math739 + sjt_math740;
#line 19
    sjt_dot366 = m;
#line 23
    sjt_math759 = (sjt_dot366)->m00;
#line 19
    sjt_dot367 = _parent;
#line 23
    sjt_math760 = (sjt_dot367)->m02;
#line 23
    sjt_math757 = sjt_math759 * sjt_math760;
#line 19
    sjt_dot368 = m;
#line 23
    sjt_math761 = (sjt_dot368)->m01;
#line 19
    sjt_dot369 = _parent;
#line 23
    sjt_math762 = (sjt_dot369)->m12;
#line 23
    sjt_math758 = sjt_math761 * sjt_math762;
#line 23
    sjt_math755 = sjt_math757 + sjt_math758;
#line 19
    sjt_dot370 = m;
#line 23
    sjt_math763 = (sjt_dot370)->m02;
#line 19
    sjt_dot371 = _parent;
#line 23
    sjt_math764 = (sjt_dot371)->m22;
#line 23
    sjt_math756 = sjt_math763 * sjt_math764;
#line 23
    sjt_math753 = sjt_math755 + sjt_math756;
#line 19
    sjt_dot372 = m;
#line 23
    sjt_math765 = (sjt_dot372)->m03;
#line 19
    sjt_dot373 = _parent;
#line 23
    sjt_math766 = (sjt_dot373)->m32;
#line 23
    sjt_math754 = sjt_math765 * sjt_math766;
#line 23
    (*_return)->m02 = sjt_math753 + sjt_math754;
#line 19
    sjt_dot374 = m;
#line 24
    sjt_math773 = (sjt_dot374)->m00;
#line 19
    sjt_dot375 = _parent;
#line 24
    sjt_math774 = (sjt_dot375)->m03;
#line 24
    sjt_math771 = sjt_math773 * sjt_math774;
#line 19
    sjt_dot376 = m;
#line 24
    sjt_math775 = (sjt_dot376)->m01;
#line 19
    sjt_dot377 = _parent;
#line 24
    sjt_math776 = (sjt_dot377)->m13;
#line 24
    sjt_math772 = sjt_math775 * sjt_math776;
#line 24
    sjt_math769 = sjt_math771 + sjt_math772;
#line 19
    sjt_dot378 = m;
#line 24
    sjt_math777 = (sjt_dot378)->m02;
#line 19
    sjt_dot379 = _parent;
#line 24
    sjt_math778 = (sjt_dot379)->m23;
#line 24
    sjt_math770 = sjt_math777 * sjt_math778;
#line 24
    sjt_math767 = sjt_math769 + sjt_math770;
#line 19
    sjt_dot380 = m;
#line 24
    sjt_math779 = (sjt_dot380)->m03;
#line 19
    sjt_dot381 = _parent;
#line 24
    sjt_math780 = (sjt_dot381)->m33;
#line 24
    sjt_math768 = sjt_math779 * sjt_math780;
#line 24
    (*_return)->m03 = sjt_math767 + sjt_math768;
#line 19
    sjt_dot382 = m;
#line 25
    sjt_math787 = (sjt_dot382)->m10;
#line 19
    sjt_dot383 = _parent;
#line 25
    sjt_math788 = (sjt_dot383)->m00;
#line 25
    sjt_math785 = sjt_math787 * sjt_math788;
#line 19
    sjt_dot384 = m;
#line 25
    sjt_math789 = (sjt_dot384)->m11;
#line 19
    sjt_dot385 = _parent;
#line 25
    sjt_math790 = (sjt_dot385)->m10;
#line 25
    sjt_math786 = sjt_math789 * sjt_math790;
#line 25
    sjt_math783 = sjt_math785 + sjt_math786;
#line 19
    sjt_dot386 = m;
#line 25
    sjt_math791 = (sjt_dot386)->m12;
#line 19
    sjt_dot387 = _parent;
#line 25
    sjt_math792 = (sjt_dot387)->m20;
#line 25
    sjt_math784 = sjt_math791 * sjt_math792;
#line 25
    sjt_math781 = sjt_math783 + sjt_math784;
#line 19
    sjt_dot388 = m;
#line 25
    sjt_math793 = (sjt_dot388)->m13;
#line 19
    sjt_dot389 = _parent;
#line 25
    sjt_math794 = (sjt_dot389)->m30;
#line 25
    sjt_math782 = sjt_math793 * sjt_math794;
#line 25
    (*_return)->m10 = sjt_math781 + sjt_math782;
#line 19
    sjt_dot390 = m;
#line 26
    sjt_math801 = (sjt_dot390)->m10;
#line 19
    sjt_dot391 = _parent;
#line 26
    sjt_math802 = (sjt_dot391)->m01;
#line 26
    sjt_math799 = sjt_math801 * sjt_math802;
#line 19
    sjt_dot392 = m;
#line 26
    sjt_math803 = (sjt_dot392)->m11;
#line 19
    sjt_dot393 = _parent;
#line 26
    sjt_math804 = (sjt_dot393)->m11;
#line 26
    sjt_math800 = sjt_math803 * sjt_math804;
#line 26
    sjt_math797 = sjt_math799 + sjt_math800;
#line 19
    sjt_dot394 = m;
#line 26
    sjt_math805 = (sjt_dot394)->m12;
#line 19
    sjt_dot395 = _parent;
#line 26
    sjt_math806 = (sjt_dot395)->m21;
#line 26
    sjt_math798 = sjt_math805 * sjt_math806;
#line 26
    sjt_math795 = sjt_math797 + sjt_math798;
#line 19
    sjt_dot396 = m;
#line 26
    sjt_math807 = (sjt_dot396)->m13;
#line 19
    sjt_dot397 = _parent;
#line 26
    sjt_math808 = (sjt_dot397)->m31;
#line 26
    sjt_math796 = sjt_math807 * sjt_math808;
#line 26
    (*_return)->m11 = sjt_math795 + sjt_math796;
#line 19
    sjt_dot398 = m;
#line 27
    sjt_math815 = (sjt_dot398)->m10;
#line 19
    sjt_dot399 = _parent;
#line 27
    sjt_math816 = (sjt_dot399)->m02;
#line 27
    sjt_math813 = sjt_math815 * sjt_math816;
#line 19
    sjt_dot400 = m;
#line 27
    sjt_math817 = (sjt_dot400)->m11;
#line 19
    sjt_dot401 = _parent;
#line 27
    sjt_math818 = (sjt_dot401)->m12;
#line 27
    sjt_math814 = sjt_math817 * sjt_math818;
#line 27
    sjt_math811 = sjt_math813 + sjt_math814;
#line 19
    sjt_dot402 = m;
#line 27
    sjt_math819 = (sjt_dot402)->m12;
#line 19
    sjt_dot403 = _parent;
#line 27
    sjt_math820 = (sjt_dot403)->m22;
#line 27
    sjt_math812 = sjt_math819 * sjt_math820;
#line 27
    sjt_math809 = sjt_math811 + sjt_math812;
#line 19
    sjt_dot404 = m;
#line 27
    sjt_math821 = (sjt_dot404)->m13;
#line 19
    sjt_dot405 = _parent;
#line 27
    sjt_math822 = (sjt_dot405)->m32;
#line 27
    sjt_math810 = sjt_math821 * sjt_math822;
#line 27
    (*_return)->m12 = sjt_math809 + sjt_math810;
#line 19
    sjt_dot406 = m;
#line 28
    sjt_math829 = (sjt_dot406)->m10;
#line 19
    sjt_dot407 = _parent;
#line 28
    sjt_math830 = (sjt_dot407)->m03;
#line 28
    sjt_math827 = sjt_math829 * sjt_math830;
#line 19
    sjt_dot408 = m;
#line 28
    sjt_math831 = (sjt_dot408)->m11;
#line 19
    sjt_dot409 = _parent;
#line 28
    sjt_math832 = (sjt_dot409)->m13;
#line 28
    sjt_math828 = sjt_math831 * sjt_math832;
#line 28
    sjt_math825 = sjt_math827 + sjt_math828;
#line 19
    sjt_dot410 = m;
#line 28
    sjt_math833 = (sjt_dot410)->m12;
#line 19
    sjt_dot411 = _parent;
#line 28
    sjt_math834 = (sjt_dot411)->m23;
#line 28
    sjt_math826 = sjt_math833 * sjt_math834;
#line 28
    sjt_math823 = sjt_math825 + sjt_math826;
#line 19
    sjt_dot412 = m;
#line 28
    sjt_math835 = (sjt_dot412)->m13;
#line 19
    sjt_dot413 = _parent;
#line 28
    sjt_math836 = (sjt_dot413)->m33;
#line 28
    sjt_math824 = sjt_math835 * sjt_math836;
#line 28
    (*_return)->m13 = sjt_math823 + sjt_math824;
#line 19
    sjt_dot414 = m;
#line 29
    sjt_math843 = (sjt_dot414)->m20;
#line 19
    sjt_dot415 = _parent;
#line 29
    sjt_math844 = (sjt_dot415)->m00;
#line 29
    sjt_math841 = sjt_math843 * sjt_math844;
#line 19
    sjt_dot416 = m;
#line 29
    sjt_math845 = (sjt_dot416)->m21;
#line 19
    sjt_dot417 = _parent;
#line 29
    sjt_math846 = (sjt_dot417)->m10;
#line 29
    sjt_math842 = sjt_math845 * sjt_math846;
#line 29
    sjt_math839 = sjt_math841 + sjt_math842;
#line 19
    sjt_dot418 = m;
#line 29
    sjt_math847 = (sjt_dot418)->m22;
#line 19
    sjt_dot419 = _parent;
#line 29
    sjt_math848 = (sjt_dot419)->m20;
#line 29
    sjt_math840 = sjt_math847 * sjt_math848;
#line 29
    sjt_math837 = sjt_math839 + sjt_math840;
#line 19
    sjt_dot420 = m;
#line 29
    sjt_math849 = (sjt_dot420)->m23;
#line 19
    sjt_dot421 = _parent;
#line 29
    sjt_math850 = (sjt_dot421)->m30;
#line 29
    sjt_math838 = sjt_math849 * sjt_math850;
#line 29
    (*_return)->m20 = sjt_math837 + sjt_math838;
#line 19
    sjt_dot422 = m;
#line 30
    sjt_math857 = (sjt_dot422)->m20;
#line 19
    sjt_dot423 = _parent;
#line 30
    sjt_math858 = (sjt_dot423)->m01;
#line 30
    sjt_math855 = sjt_math857 * sjt_math858;
#line 19
    sjt_dot424 = m;
#line 30
    sjt_math859 = (sjt_dot424)->m21;
#line 19
    sjt_dot425 = _parent;
#line 30
    sjt_math860 = (sjt_dot425)->m11;
#line 30
    sjt_math856 = sjt_math859 * sjt_math860;
#line 30
    sjt_math853 = sjt_math855 + sjt_math856;
#line 19
    sjt_dot426 = m;
#line 30
    sjt_math861 = (sjt_dot426)->m22;
#line 19
    sjt_dot427 = _parent;
#line 30
    sjt_math862 = (sjt_dot427)->m21;
#line 30
    sjt_math854 = sjt_math861 * sjt_math862;
#line 30
    sjt_math851 = sjt_math853 + sjt_math854;
#line 19
    sjt_dot428 = m;
#line 30
    sjt_math863 = (sjt_dot428)->m23;
#line 19
    sjt_dot429 = _parent;
#line 30
    sjt_math864 = (sjt_dot429)->m31;
#line 30
    sjt_math852 = sjt_math863 * sjt_math864;
#line 30
    (*_return)->m21 = sjt_math851 + sjt_math852;
#line 19
    sjt_dot430 = m;
#line 31
    sjt_math871 = (sjt_dot430)->m20;
#line 19
    sjt_dot431 = _parent;
#line 31
    sjt_math872 = (sjt_dot431)->m02;
#line 31
    sjt_math869 = sjt_math871 * sjt_math872;
#line 19
    sjt_dot432 = m;
#line 31
    sjt_math873 = (sjt_dot432)->m21;
#line 19
    sjt_dot433 = _parent;
#line 31
    sjt_math874 = (sjt_dot433)->m12;
#line 31
    sjt_math870 = sjt_math873 * sjt_math874;
#line 31
    sjt_math867 = sjt_math869 + sjt_math870;
#line 19
    sjt_dot434 = m;
#line 31
    sjt_math875 = (sjt_dot434)->m22;
#line 19
    sjt_dot435 = _parent;
#line 31
    sjt_math876 = (sjt_dot435)->m22;
#line 31
    sjt_math868 = sjt_math875 * sjt_math876;
#line 31
    sjt_math865 = sjt_math867 + sjt_math868;
#line 19
    sjt_dot436 = m;
#line 31
    sjt_math877 = (sjt_dot436)->m23;
#line 19
    sjt_dot437 = _parent;
#line 31
    sjt_math878 = (sjt_dot437)->m32;
#line 31
    sjt_math866 = sjt_math877 * sjt_math878;
#line 31
    (*_return)->m22 = sjt_math865 + sjt_math866;
#line 19
    sjt_dot438 = m;
#line 32
    sjt_math885 = (sjt_dot438)->m20;
#line 19
    sjt_dot439 = _parent;
#line 32
    sjt_math886 = (sjt_dot439)->m03;
#line 32
    sjt_math883 = sjt_math885 * sjt_math886;
#line 19
    sjt_dot440 = m;
#line 32
    sjt_math887 = (sjt_dot440)->m21;
#line 19
    sjt_dot441 = _parent;
#line 32
    sjt_math888 = (sjt_dot441)->m13;
#line 32
    sjt_math884 = sjt_math887 * sjt_math888;
#line 32
    sjt_math881 = sjt_math883 + sjt_math884;
#line 19
    sjt_dot442 = m;
#line 32
    sjt_math889 = (sjt_dot442)->m22;
#line 19
    sjt_dot443 = _parent;
#line 32
    sjt_math890 = (sjt_dot443)->m23;
#line 32
    sjt_math882 = sjt_math889 * sjt_math890;
#line 32
    sjt_math879 = sjt_math881 + sjt_math882;
#line 19
    sjt_dot444 = m;
#line 32
    sjt_math891 = (sjt_dot444)->m23;
#line 19
    sjt_dot445 = _parent;
#line 32
    sjt_math892 = (sjt_dot445)->m33;
#line 32
    sjt_math880 = sjt_math891 * sjt_math892;
#line 32
    (*_return)->m23 = sjt_math879 + sjt_math880;
#line 19
    sjt_dot446 = m;
#line 33
    sjt_math899 = (sjt_dot446)->m30;
#line 19
    sjt_dot447 = _parent;
#line 33
    sjt_math900 = (sjt_dot447)->m00;
#line 33
    sjt_math897 = sjt_math899 * sjt_math900;
#line 19
    sjt_dot448 = m;
#line 33
    sjt_math901 = (sjt_dot448)->m31;
#line 19
    sjt_dot449 = _parent;
#line 33
    sjt_math902 = (sjt_dot449)->m10;
#line 33
    sjt_math898 = sjt_math901 * sjt_math902;
#line 33
    sjt_math895 = sjt_math897 + sjt_math898;
#line 19
    sjt_dot450 = m;
#line 33
    sjt_math903 = (sjt_dot450)->m32;
#line 19
    sjt_dot451 = _parent;
#line 33
    sjt_math904 = (sjt_dot451)->m20;
#line 33
    sjt_math896 = sjt_math903 * sjt_math904;
#line 33
    sjt_math893 = sjt_math895 + sjt_math896;
#line 19
    sjt_dot452 = m;
#line 33
    sjt_math905 = (sjt_dot452)->m33;
#line 19
    sjt_dot453 = _parent;
#line 33
    sjt_math906 = (sjt_dot453)->m30;
#line 33
    sjt_math894 = sjt_math905 * sjt_math906;
#line 33
    (*_return)->m30 = sjt_math893 + sjt_math894;
#line 19
    sjt_dot454 = m;
#line 34
    sjt_math913 = (sjt_dot454)->m30;
#line 19
    sjt_dot455 = _parent;
#line 34
    sjt_math914 = (sjt_dot455)->m01;
#line 34
    sjt_math911 = sjt_math913 * sjt_math914;
#line 19
    sjt_dot456 = m;
#line 34
    sjt_math915 = (sjt_dot456)->m31;
#line 19
    sjt_dot457 = _parent;
#line 34
    sjt_math916 = (sjt_dot457)->m11;
#line 34
    sjt_math912 = sjt_math915 * sjt_math916;
#line 34
    sjt_math909 = sjt_math911 + sjt_math912;
#line 19
    sjt_dot458 = m;
#line 34
    sjt_math917 = (sjt_dot458)->m32;
#line 19
    sjt_dot459 = _parent;
#line 34
    sjt_math918 = (sjt_dot459)->m21;
#line 34
    sjt_math910 = sjt_math917 * sjt_math918;
#line 34
    sjt_math907 = sjt_math909 + sjt_math910;
#line 19
    sjt_dot460 = m;
#line 34
    sjt_math919 = (sjt_dot460)->m33;
#line 19
    sjt_dot461 = _parent;
#line 34
    sjt_math920 = (sjt_dot461)->m31;
#line 34
    sjt_math908 = sjt_math919 * sjt_math920;
#line 34
    (*_return)->m31 = sjt_math907 + sjt_math908;
#line 19
    sjt_dot462 = m;
#line 35
    sjt_math927 = (sjt_dot462)->m30;
#line 19
    sjt_dot463 = _parent;
#line 35
    sjt_math928 = (sjt_dot463)->m02;
#line 35
    sjt_math925 = sjt_math927 * sjt_math928;
#line 19
    sjt_dot464 = m;
#line 35
    sjt_math929 = (sjt_dot464)->m31;
#line 19
    sjt_dot465 = _parent;
#line 35
    sjt_math930 = (sjt_dot465)->m12;
#line 35
    sjt_math926 = sjt_math929 * sjt_math930;
#line 35
    sjt_math923 = sjt_math925 + sjt_math926;
#line 19
    sjt_dot466 = m;
#line 35
    sjt_math931 = (sjt_dot466)->m32;
#line 19
    sjt_dot467 = _parent;
#line 35
    sjt_math932 = (sjt_dot467)->m22;
#line 35
    sjt_math924 = sjt_math931 * sjt_math932;
#line 35
    sjt_math921 = sjt_math923 + sjt_math924;
#line 19
    sjt_dot468 = m;
#line 35
    sjt_math933 = (sjt_dot468)->m33;
#line 19
    sjt_dot469 = _parent;
#line 35
    sjt_math934 = (sjt_dot469)->m32;
#line 35
    sjt_math922 = sjt_math933 * sjt_math934;
#line 35
    (*_return)->m32 = sjt_math921 + sjt_math922;
#line 19
    sjt_dot470 = m;
#line 36
    sjt_math941 = (sjt_dot470)->m30;
#line 19
    sjt_dot471 = _parent;
#line 36
    sjt_math942 = (sjt_dot471)->m03;
#line 36
    sjt_math939 = sjt_math941 * sjt_math942;
#line 19
    sjt_dot472 = m;
#line 36
    sjt_math943 = (sjt_dot472)->m31;
#line 19
    sjt_dot473 = _parent;
#line 36
    sjt_math944 = (sjt_dot473)->m13;
#line 36
    sjt_math940 = sjt_math943 * sjt_math944;
#line 36
    sjt_math937 = sjt_math939 + sjt_math940;
#line 19
    sjt_dot474 = m;
#line 36
    sjt_math945 = (sjt_dot474)->m32;
#line 19
    sjt_dot475 = _parent;
#line 36
    sjt_math946 = (sjt_dot475)->m23;
#line 36
    sjt_math938 = sjt_math945 * sjt_math946;
#line 36
    sjt_math935 = sjt_math937 + sjt_math938;
#line 19
    sjt_dot476 = m;
#line 36
    sjt_math947 = (sjt_dot476)->m33;
#line 19
    sjt_dot477 = _parent;
#line 36
    sjt_math948 = (sjt_dot477)->m33;
#line 36
    sjt_math936 = sjt_math947 * sjt_math948;
#line 36
    (*_return)->m33 = sjt_math935 + sjt_math936;
#line 0 ""
    sjf_mat4_heap((*_return));
}

void sjf_mat4_orthographic(float left, float right, float bottom, float top, float znear, float zfar, sjs_mat4* _return) {
    float result8;
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
    float sjt_negate5;

#line 158 ".\..\lib\ui\mat4.sj"
    sjt_math427 = 2.0f;
#line 156
    sjt_math429 = right;
#line 156
    sjt_math430 = left;
#line 158
    sjt_math428 = sjt_math429 - sjt_math430;
#line 158
    _return->m00 = sjt_math427 / sjt_math428;
#line 3
    _return->m01 = 0.0f;
#line 4
    _return->m02 = 0.0f;
#line 5
    _return->m03 = 0.0f;
#line 6
    _return->m10 = 0.0f;
#line 160
    sjt_math431 = 2.0f;
#line 156
    sjt_math433 = top;
#line 156
    sjt_math434 = bottom;
#line 160
    sjt_math432 = sjt_math433 - sjt_math434;
#line 160
    _return->m11 = sjt_math431 / sjt_math432;
#line 8
    _return->m12 = 0.0f;
#line 9
    _return->m13 = 0.0f;
#line 10
    _return->m20 = 0.0f;
#line 11
    _return->m21 = 0.0f;
#line 162
    sjt_negate5 = 2.0f;
#line 162
    result8 = -sjt_negate5;
#line 162
    sjt_math435 = result8;
#line 156
    sjt_math437 = zfar;
#line 156
    sjt_math438 = znear;
#line 162
    sjt_math436 = sjt_math437 - sjt_math438;
#line 162
    _return->m22 = sjt_math435 / sjt_math436;
#line 13
    _return->m23 = 0.0f;
#line 159
    sjt_math439 = 0.0f;
#line 156
    sjt_math443 = right;
#line 156
    sjt_math444 = left;
#line 159
    sjt_math441 = sjt_math443 + sjt_math444;
#line 156
    sjt_math445 = right;
#line 156
    sjt_math446 = left;
#line 159
    sjt_math442 = sjt_math445 - sjt_math446;
#line 159
    sjt_math440 = sjt_math441 / sjt_math442;
#line 159
    _return->m30 = sjt_math439 - sjt_math440;
#line 161
    sjt_math447 = 0.0f;
#line 156
    sjt_math451 = top;
#line 156
    sjt_math452 = bottom;
#line 161
    sjt_math449 = sjt_math451 + sjt_math452;
#line 156
    sjt_math453 = top;
#line 156
    sjt_math454 = bottom;
#line 161
    sjt_math450 = sjt_math453 - sjt_math454;
#line 161
    sjt_math448 = sjt_math449 / sjt_math450;
#line 161
    _return->m31 = sjt_math447 - sjt_math448;
#line 163
    sjt_math455 = 0.0f;
#line 156
    sjt_math459 = zfar;
#line 156
    sjt_math460 = znear;
#line 163
    sjt_math457 = sjt_math459 + sjt_math460;
#line 156
    sjt_math461 = zfar;
#line 156
    sjt_math462 = znear;
#line 163
    sjt_math458 = sjt_math461 - sjt_math462;
#line 163
    sjt_math456 = sjt_math457 / sjt_math458;
#line 163
    _return->m32 = sjt_math455 - sjt_math456;
#line 164
    _return->m33 = 1.0f;
#line 0 ""
    sjf_mat4(_return);
}

void sjf_mat4_orthographic_heap(float left, float right, float bottom, float top, float znear, float zfar, sjs_mat4_heap** _return) {
    float result9;
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
    float sjt_negate6;

    (*_return) = (sjs_mat4_heap*)malloc(sizeof(sjs_mat4_heap));
    (*_return)->_refCount = 1;
#line 158 ".\..\lib\ui\mat4.sj"
    sjt_math463 = 2.0f;
#line 156
    sjt_math465 = right;
#line 156
    sjt_math466 = left;
#line 158
    sjt_math464 = sjt_math465 - sjt_math466;
#line 158
    (*_return)->m00 = sjt_math463 / sjt_math464;
#line 3
    (*_return)->m01 = 0.0f;
#line 4
    (*_return)->m02 = 0.0f;
#line 5
    (*_return)->m03 = 0.0f;
#line 6
    (*_return)->m10 = 0.0f;
#line 160
    sjt_math467 = 2.0f;
#line 156
    sjt_math469 = top;
#line 156
    sjt_math470 = bottom;
#line 160
    sjt_math468 = sjt_math469 - sjt_math470;
#line 160
    (*_return)->m11 = sjt_math467 / sjt_math468;
#line 8
    (*_return)->m12 = 0.0f;
#line 9
    (*_return)->m13 = 0.0f;
#line 10
    (*_return)->m20 = 0.0f;
#line 11
    (*_return)->m21 = 0.0f;
#line 162
    sjt_negate6 = 2.0f;
#line 162
    result9 = -sjt_negate6;
#line 162
    sjt_math471 = result9;
#line 156
    sjt_math473 = zfar;
#line 156
    sjt_math474 = znear;
#line 162
    sjt_math472 = sjt_math473 - sjt_math474;
#line 162
    (*_return)->m22 = sjt_math471 / sjt_math472;
#line 13
    (*_return)->m23 = 0.0f;
#line 159
    sjt_math475 = 0.0f;
#line 156
    sjt_math479 = right;
#line 156
    sjt_math480 = left;
#line 159
    sjt_math477 = sjt_math479 + sjt_math480;
#line 156
    sjt_math481 = right;
#line 156
    sjt_math482 = left;
#line 159
    sjt_math478 = sjt_math481 - sjt_math482;
#line 159
    sjt_math476 = sjt_math477 / sjt_math478;
#line 159
    (*_return)->m30 = sjt_math475 - sjt_math476;
#line 161
    sjt_math483 = 0.0f;
#line 156
    sjt_math487 = top;
#line 156
    sjt_math488 = bottom;
#line 161
    sjt_math485 = sjt_math487 + sjt_math488;
#line 156
    sjt_math489 = top;
#line 156
    sjt_math490 = bottom;
#line 161
    sjt_math486 = sjt_math489 - sjt_math490;
#line 161
    sjt_math484 = sjt_math485 / sjt_math486;
#line 161
    (*_return)->m31 = sjt_math483 - sjt_math484;
#line 163
    sjt_math491 = 0.0f;
#line 156
    sjt_math495 = zfar;
#line 156
    sjt_math496 = znear;
#line 163
    sjt_math493 = sjt_math495 + sjt_math496;
#line 156
    sjt_math497 = zfar;
#line 156
    sjt_math498 = znear;
#line 163
    sjt_math494 = sjt_math497 - sjt_math498;
#line 163
    sjt_math492 = sjt_math493 / sjt_math494;
#line 163
    (*_return)->m32 = sjt_math491 - sjt_math492;
#line 164
    (*_return)->m33 = 1.0f;
#line 0 ""
    sjf_mat4_heap((*_return));
}

void sjf_mat4_perspective(float fovy, float aspect, float znear, float zfar, sjs_mat4* _return) {
    float sjt_functionParam22;
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
    float sjt_math81;
    float sjt_math82;
    float sjv_xscale;
    float sjv_yscale;

#line 145 ".\..\lib\ui\mat4.sj"
    sjt_math63 = 1.0f;
#line 144
    sjt_math67 = fovy;
#line 145
    sjt_math68 = 180.0f;
#line 145
    sjt_math65 = sjt_math67 / sjt_math68;
#line 145
    sjt_math66 = 2.0f;
#line 145
    sjt_functionParam22 = sjt_math65 / sjt_math66;
#line 0 ""
    sjf_f32_tan(sjt_functionParam22, &sjt_math64);
#line 145 ".\..\lib\ui\mat4.sj"
    sjv_yscale = sjt_math63 / sjt_math64;
#line 146
    sjt_math69 = sjv_yscale;
#line 144
    sjt_math70 = aspect;
#line 146
    sjv_xscale = sjt_math69 * sjt_math70;
#line 147
    _return->m00 = sjv_xscale;
#line 3
    _return->m01 = 0.0f;
#line 4
    _return->m02 = 0.0f;
#line 5
    _return->m03 = 0.0f;
#line 6
    _return->m10 = 0.0f;
#line 147
    _return->m11 = sjv_yscale;
#line 8
    _return->m12 = 0.0f;
#line 9
    _return->m13 = 0.0f;
#line 10
    _return->m20 = 0.0f;
#line 11
    _return->m21 = 0.0f;
#line 144
    sjt_math71 = zfar;
#line 144
    sjt_math73 = zfar;
#line 144
    sjt_math74 = znear;
#line 150
    sjt_math72 = sjt_math73 - sjt_math74;
#line 150
    _return->m22 = sjt_math71 / sjt_math72;
#line 151
    _return->m23 = 1.0f;
#line 14
    _return->m30 = 0.0f;
#line 15
    _return->m31 = 0.0f;
#line 152
    sjt_math75 = 0.0f;
#line 144
    sjt_math79 = znear;
#line 144
    sjt_math80 = zfar;
#line 152
    sjt_math77 = sjt_math79 * sjt_math80;
#line 144
    sjt_math81 = zfar;
#line 144
    sjt_math82 = znear;
#line 152
    sjt_math78 = sjt_math81 - sjt_math82;
#line 152
    sjt_math76 = sjt_math77 / sjt_math78;
#line 152
    _return->m32 = sjt_math75 - sjt_math76;
#line 17
    _return->m33 = 0.0f;
#line 0 ""
    sjf_mat4(_return);
}

void sjf_mat4_perspective_heap(float fovy, float aspect, float znear, float zfar, sjs_mat4_heap** _return) {
    float sjt_functionParam23;
    float sjt_math100;
    float sjt_math101;
    float sjt_math102;
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

#line 145 ".\..\lib\ui\mat4.sj"
    sjt_math83 = 1.0f;
#line 144
    sjt_math87 = fovy;
#line 145
    sjt_math88 = 180.0f;
#line 145
    sjt_math85 = sjt_math87 / sjt_math88;
#line 145
    sjt_math86 = 2.0f;
#line 145
    sjt_functionParam23 = sjt_math85 / sjt_math86;
#line 0 ""
    sjf_f32_tan(sjt_functionParam23, &sjt_math84);
#line 145 ".\..\lib\ui\mat4.sj"
    sjv_yscale = sjt_math83 / sjt_math84;
#line 146
    sjt_math89 = sjv_yscale;
#line 144
    sjt_math90 = aspect;
#line 146
    sjv_xscale = sjt_math89 * sjt_math90;
#line 0 ""
    (*_return) = (sjs_mat4_heap*)malloc(sizeof(sjs_mat4_heap));
    (*_return)->_refCount = 1;
#line 147 ".\..\lib\ui\mat4.sj"
    (*_return)->m00 = sjv_xscale;
#line 3
    (*_return)->m01 = 0.0f;
#line 4
    (*_return)->m02 = 0.0f;
#line 5
    (*_return)->m03 = 0.0f;
#line 6
    (*_return)->m10 = 0.0f;
#line 147
    (*_return)->m11 = sjv_yscale;
#line 8
    (*_return)->m12 = 0.0f;
#line 9
    (*_return)->m13 = 0.0f;
#line 10
    (*_return)->m20 = 0.0f;
#line 11
    (*_return)->m21 = 0.0f;
#line 144
    sjt_math91 = zfar;
#line 144
    sjt_math93 = zfar;
#line 144
    sjt_math94 = znear;
#line 150
    sjt_math92 = sjt_math93 - sjt_math94;
#line 150
    (*_return)->m22 = sjt_math91 / sjt_math92;
#line 151
    (*_return)->m23 = 1.0f;
#line 14
    (*_return)->m30 = 0.0f;
#line 15
    (*_return)->m31 = 0.0f;
#line 152
    sjt_math95 = 0.0f;
#line 144
    sjt_math99 = znear;
#line 144
    sjt_math100 = zfar;
#line 152
    sjt_math97 = sjt_math99 * sjt_math100;
#line 144
    sjt_math101 = zfar;
#line 144
    sjt_math102 = znear;
#line 152
    sjt_math98 = sjt_math101 - sjt_math102;
#line 152
    sjt_math96 = sjt_math97 / sjt_math98;
#line 152
    (*_return)->m32 = sjt_math95 - sjt_math96;
#line 17
    (*_return)->m33 = 0.0f;
#line 0 ""
    sjf_mat4_heap((*_return));
}

void sjf_mat4_rotation(float angle, float x, float y, float z, sjs_mat4* _return) {
    float sjt_functionParam48;
    float sjt_functionParam49;
    float sjt_functionParam50;
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
    float sjv_c;
    float sjv_norm;
    float sjv_s;
    float sjv_xnorm;
    float sjv_ynorm;
    float sjv_znorm;

#line 169 ".\..\lib\ui\mat4.sj"
    sjt_math213 = sjv_f32_pi;
#line 168
    sjt_math214 = angle;
#line 169
    sjt_math211 = sjt_math213 * sjt_math214;
#line 169
    sjt_math212 = 180.0f;
#line 169
    sjt_functionParam48 = sjt_math211 / sjt_math212;
#line 0 ""
    sjf_f32_cos(sjt_functionParam48, &sjv_c);
#line 170 ".\..\lib\ui\mat4.sj"
    sjt_math217 = sjv_f32_pi;
#line 168
    sjt_math218 = angle;
#line 170
    sjt_math215 = sjt_math217 * sjt_math218;
#line 170
    sjt_math216 = 180.0f;
#line 170
    sjt_functionParam49 = sjt_math215 / sjt_math216;
#line 0 ""
    sjf_f32_sin(sjt_functionParam49, &sjv_s);
#line 168 ".\..\lib\ui\mat4.sj"
    sjt_math223 = x;
#line 168
    sjt_math224 = x;
#line 171
    sjt_math221 = sjt_math223 * sjt_math224;
#line 168
    sjt_math225 = y;
#line 168
    sjt_math226 = y;
#line 171
    sjt_math222 = sjt_math225 * sjt_math226;
#line 171
    sjt_math219 = sjt_math221 + sjt_math222;
#line 168
    sjt_math227 = z;
#line 168
    sjt_math228 = z;
#line 171
    sjt_math220 = sjt_math227 * sjt_math228;
#line 171
    sjt_functionParam50 = sjt_math219 + sjt_math220;
#line 0 ""
    sjf_f32_sqrt(sjt_functionParam50, &sjv_norm);
#line 168 ".\..\lib\ui\mat4.sj"
    sjt_math229 = x;
#line 173
    sjt_math230 = sjv_norm;
#line 173
    sjv_xnorm = sjt_math229 / sjt_math230;
#line 168
    sjt_math231 = y;
#line 174
    sjt_math232 = sjv_norm;
#line 174
    sjv_ynorm = sjt_math231 / sjt_math232;
#line 168
    sjt_math233 = z;
#line 175
    sjt_math234 = sjv_norm;
#line 175
    sjv_znorm = sjt_math233 / sjt_math234;
#line 178
    sjt_math239 = sjv_xnorm;
#line 178
    sjt_math240 = sjv_xnorm;
#line 178
    sjt_math237 = sjt_math239 * sjt_math240;
#line 178
    sjt_math241 = 1.0f;
#line 178
    sjt_math242 = sjv_c;
#line 178
    sjt_math238 = sjt_math241 - sjt_math242;
#line 178
    sjt_math235 = sjt_math237 * sjt_math238;
#line 178
    sjt_math236 = sjv_c;
#line 178
    _return->m00 = sjt_math235 + sjt_math236;
#line 181
    sjt_math247 = sjv_xnorm;
#line 181
    sjt_math248 = sjv_ynorm;
#line 181
    sjt_math245 = sjt_math247 * sjt_math248;
#line 181
    sjt_math249 = 1.0f;
#line 181
    sjt_math250 = sjv_c;
#line 181
    sjt_math246 = sjt_math249 - sjt_math250;
#line 181
    sjt_math243 = sjt_math245 * sjt_math246;
#line 181
    sjt_math251 = sjv_znorm;
#line 181
    sjt_math252 = sjv_s;
#line 181
    sjt_math244 = sjt_math251 * sjt_math252;
#line 181
    _return->m01 = sjt_math243 + sjt_math244;
#line 184
    sjt_math257 = sjv_xnorm;
#line 184
    sjt_math258 = sjv_znorm;
#line 184
    sjt_math255 = sjt_math257 * sjt_math258;
#line 184
    sjt_math259 = 1.0f;
#line 184
    sjt_math260 = sjv_c;
#line 184
    sjt_math256 = sjt_math259 - sjt_math260;
#line 184
    sjt_math253 = sjt_math255 * sjt_math256;
#line 184
    sjt_math261 = sjv_ynorm;
#line 184
    sjt_math262 = sjv_s;
#line 184
    sjt_math254 = sjt_math261 * sjt_math262;
#line 184
    _return->m02 = sjt_math253 - sjt_math254;
#line 5
    _return->m03 = 0.0f;
#line 179
    sjt_math267 = sjv_ynorm;
#line 179
    sjt_math268 = sjv_xnorm;
#line 179
    sjt_math265 = sjt_math267 * sjt_math268;
#line 179
    sjt_math269 = 1.0f;
#line 179
    sjt_math270 = sjv_c;
#line 179
    sjt_math266 = sjt_math269 - sjt_math270;
#line 179
    sjt_math263 = sjt_math265 * sjt_math266;
#line 179
    sjt_math271 = sjv_znorm;
#line 179
    sjt_math272 = sjv_s;
#line 179
    sjt_math264 = sjt_math271 * sjt_math272;
#line 179
    _return->m10 = sjt_math263 - sjt_math264;
#line 182
    sjt_math277 = sjv_ynorm;
#line 182
    sjt_math278 = sjv_ynorm;
#line 182
    sjt_math275 = sjt_math277 * sjt_math278;
#line 182
    sjt_math279 = 1.0f;
#line 182
    sjt_math280 = sjv_c;
#line 182
    sjt_math276 = sjt_math279 - sjt_math280;
#line 182
    sjt_math273 = sjt_math275 * sjt_math276;
#line 182
    sjt_math274 = sjv_c;
#line 182
    _return->m11 = sjt_math273 + sjt_math274;
#line 185
    sjt_math285 = sjv_ynorm;
#line 185
    sjt_math286 = sjv_znorm;
#line 185
    sjt_math283 = sjt_math285 * sjt_math286;
#line 185
    sjt_math287 = 1.0f;
#line 185
    sjt_math288 = sjv_c;
#line 185
    sjt_math284 = sjt_math287 - sjt_math288;
#line 185
    sjt_math281 = sjt_math283 * sjt_math284;
#line 185
    sjt_math289 = sjv_xnorm;
#line 185
    sjt_math290 = sjv_s;
#line 185
    sjt_math282 = sjt_math289 * sjt_math290;
#line 185
    _return->m12 = sjt_math281 + sjt_math282;
#line 9
    _return->m13 = 0.0f;
#line 180
    sjt_math295 = sjv_znorm;
#line 180
    sjt_math296 = sjv_xnorm;
#line 180
    sjt_math293 = sjt_math295 * sjt_math296;
#line 180
    sjt_math297 = 1.0f;
#line 180
    sjt_math298 = sjv_c;
#line 180
    sjt_math294 = sjt_math297 - sjt_math298;
#line 180
    sjt_math291 = sjt_math293 * sjt_math294;
#line 180
    sjt_math299 = sjv_ynorm;
#line 180
    sjt_math300 = sjv_s;
#line 180
    sjt_math292 = sjt_math299 * sjt_math300;
#line 180
    _return->m20 = sjt_math291 + sjt_math292;
#line 183
    sjt_math305 = sjv_znorm;
#line 183
    sjt_math306 = sjv_ynorm;
#line 183
    sjt_math303 = sjt_math305 * sjt_math306;
#line 183
    sjt_math307 = 1.0f;
#line 183
    sjt_math308 = sjv_c;
#line 183
    sjt_math304 = sjt_math307 - sjt_math308;
#line 183
    sjt_math301 = sjt_math303 * sjt_math304;
#line 183
    sjt_math309 = sjv_xnorm;
#line 183
    sjt_math310 = sjv_s;
#line 183
    sjt_math302 = sjt_math309 * sjt_math310;
#line 183
    _return->m21 = sjt_math301 - sjt_math302;
#line 186
    sjt_math315 = sjv_znorm;
#line 186
    sjt_math316 = sjv_znorm;
#line 186
    sjt_math313 = sjt_math315 * sjt_math316;
#line 186
    sjt_math317 = 1.0f;
#line 186
    sjt_math318 = sjv_c;
#line 186
    sjt_math314 = sjt_math317 - sjt_math318;
#line 186
    sjt_math311 = sjt_math313 * sjt_math314;
#line 186
    sjt_math312 = sjv_c;
#line 186
    _return->m22 = sjt_math311 + sjt_math312;
#line 13
    _return->m23 = 0.0f;
#line 14
    _return->m30 = 0.0f;
#line 15
    _return->m31 = 0.0f;
#line 16
    _return->m32 = 0.0f;
#line 187
    _return->m33 = 1.0f;
#line 0 ""
    sjf_mat4(_return);
}

void sjf_mat4_rotation_heap(float angle, float x, float y, float z, sjs_mat4_heap** _return) {
    float sjt_functionParam51;
    float sjt_functionParam52;
    float sjt_functionParam53;
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
    float sjv_c;
    float sjv_norm;
    float sjv_s;
    float sjv_xnorm;
    float sjv_ynorm;
    float sjv_znorm;

#line 169 ".\..\lib\ui\mat4.sj"
    sjt_math321 = sjv_f32_pi;
#line 168
    sjt_math322 = angle;
#line 169
    sjt_math319 = sjt_math321 * sjt_math322;
#line 169
    sjt_math320 = 180.0f;
#line 169
    sjt_functionParam51 = sjt_math319 / sjt_math320;
#line 0 ""
    sjf_f32_cos(sjt_functionParam51, &sjv_c);
#line 170 ".\..\lib\ui\mat4.sj"
    sjt_math325 = sjv_f32_pi;
#line 168
    sjt_math326 = angle;
#line 170
    sjt_math323 = sjt_math325 * sjt_math326;
#line 170
    sjt_math324 = 180.0f;
#line 170
    sjt_functionParam52 = sjt_math323 / sjt_math324;
#line 0 ""
    sjf_f32_sin(sjt_functionParam52, &sjv_s);
#line 168 ".\..\lib\ui\mat4.sj"
    sjt_math331 = x;
#line 168
    sjt_math332 = x;
#line 171
    sjt_math329 = sjt_math331 * sjt_math332;
#line 168
    sjt_math333 = y;
#line 168
    sjt_math334 = y;
#line 171
    sjt_math330 = sjt_math333 * sjt_math334;
#line 171
    sjt_math327 = sjt_math329 + sjt_math330;
#line 168
    sjt_math335 = z;
#line 168
    sjt_math336 = z;
#line 171
    sjt_math328 = sjt_math335 * sjt_math336;
#line 171
    sjt_functionParam53 = sjt_math327 + sjt_math328;
#line 0 ""
    sjf_f32_sqrt(sjt_functionParam53, &sjv_norm);
#line 168 ".\..\lib\ui\mat4.sj"
    sjt_math337 = x;
#line 173
    sjt_math338 = sjv_norm;
#line 173
    sjv_xnorm = sjt_math337 / sjt_math338;
#line 168
    sjt_math339 = y;
#line 174
    sjt_math340 = sjv_norm;
#line 174
    sjv_ynorm = sjt_math339 / sjt_math340;
#line 168
    sjt_math341 = z;
#line 175
    sjt_math342 = sjv_norm;
#line 175
    sjv_znorm = sjt_math341 / sjt_math342;
#line 0 ""
    (*_return) = (sjs_mat4_heap*)malloc(sizeof(sjs_mat4_heap));
    (*_return)->_refCount = 1;
#line 178 ".\..\lib\ui\mat4.sj"
    sjt_math347 = sjv_xnorm;
#line 178
    sjt_math348 = sjv_xnorm;
#line 178
    sjt_math345 = sjt_math347 * sjt_math348;
#line 178
    sjt_math349 = 1.0f;
#line 178
    sjt_math350 = sjv_c;
#line 178
    sjt_math346 = sjt_math349 - sjt_math350;
#line 178
    sjt_math343 = sjt_math345 * sjt_math346;
#line 178
    sjt_math344 = sjv_c;
#line 178
    (*_return)->m00 = sjt_math343 + sjt_math344;
#line 181
    sjt_math355 = sjv_xnorm;
#line 181
    sjt_math356 = sjv_ynorm;
#line 181
    sjt_math353 = sjt_math355 * sjt_math356;
#line 181
    sjt_math357 = 1.0f;
#line 181
    sjt_math358 = sjv_c;
#line 181
    sjt_math354 = sjt_math357 - sjt_math358;
#line 181
    sjt_math351 = sjt_math353 * sjt_math354;
#line 181
    sjt_math359 = sjv_znorm;
#line 181
    sjt_math360 = sjv_s;
#line 181
    sjt_math352 = sjt_math359 * sjt_math360;
#line 181
    (*_return)->m01 = sjt_math351 + sjt_math352;
#line 184
    sjt_math365 = sjv_xnorm;
#line 184
    sjt_math366 = sjv_znorm;
#line 184
    sjt_math363 = sjt_math365 * sjt_math366;
#line 184
    sjt_math367 = 1.0f;
#line 184
    sjt_math368 = sjv_c;
#line 184
    sjt_math364 = sjt_math367 - sjt_math368;
#line 184
    sjt_math361 = sjt_math363 * sjt_math364;
#line 184
    sjt_math369 = sjv_ynorm;
#line 184
    sjt_math370 = sjv_s;
#line 184
    sjt_math362 = sjt_math369 * sjt_math370;
#line 184
    (*_return)->m02 = sjt_math361 - sjt_math362;
#line 5
    (*_return)->m03 = 0.0f;
#line 179
    sjt_math375 = sjv_ynorm;
#line 179
    sjt_math376 = sjv_xnorm;
#line 179
    sjt_math373 = sjt_math375 * sjt_math376;
#line 179
    sjt_math377 = 1.0f;
#line 179
    sjt_math378 = sjv_c;
#line 179
    sjt_math374 = sjt_math377 - sjt_math378;
#line 179
    sjt_math371 = sjt_math373 * sjt_math374;
#line 179
    sjt_math379 = sjv_znorm;
#line 179
    sjt_math380 = sjv_s;
#line 179
    sjt_math372 = sjt_math379 * sjt_math380;
#line 179
    (*_return)->m10 = sjt_math371 - sjt_math372;
#line 182
    sjt_math385 = sjv_ynorm;
#line 182
    sjt_math386 = sjv_ynorm;
#line 182
    sjt_math383 = sjt_math385 * sjt_math386;
#line 182
    sjt_math387 = 1.0f;
#line 182
    sjt_math388 = sjv_c;
#line 182
    sjt_math384 = sjt_math387 - sjt_math388;
#line 182
    sjt_math381 = sjt_math383 * sjt_math384;
#line 182
    sjt_math382 = sjv_c;
#line 182
    (*_return)->m11 = sjt_math381 + sjt_math382;
#line 185
    sjt_math393 = sjv_ynorm;
#line 185
    sjt_math394 = sjv_znorm;
#line 185
    sjt_math391 = sjt_math393 * sjt_math394;
#line 185
    sjt_math395 = 1.0f;
#line 185
    sjt_math396 = sjv_c;
#line 185
    sjt_math392 = sjt_math395 - sjt_math396;
#line 185
    sjt_math389 = sjt_math391 * sjt_math392;
#line 185
    sjt_math397 = sjv_xnorm;
#line 185
    sjt_math398 = sjv_s;
#line 185
    sjt_math390 = sjt_math397 * sjt_math398;
#line 185
    (*_return)->m12 = sjt_math389 + sjt_math390;
#line 9
    (*_return)->m13 = 0.0f;
#line 180
    sjt_math403 = sjv_znorm;
#line 180
    sjt_math404 = sjv_xnorm;
#line 180
    sjt_math401 = sjt_math403 * sjt_math404;
#line 180
    sjt_math405 = 1.0f;
#line 180
    sjt_math406 = sjv_c;
#line 180
    sjt_math402 = sjt_math405 - sjt_math406;
#line 180
    sjt_math399 = sjt_math401 * sjt_math402;
#line 180
    sjt_math407 = sjv_ynorm;
#line 180
    sjt_math408 = sjv_s;
#line 180
    sjt_math400 = sjt_math407 * sjt_math408;
#line 180
    (*_return)->m20 = sjt_math399 + sjt_math400;
#line 183
    sjt_math413 = sjv_znorm;
#line 183
    sjt_math414 = sjv_ynorm;
#line 183
    sjt_math411 = sjt_math413 * sjt_math414;
#line 183
    sjt_math415 = 1.0f;
#line 183
    sjt_math416 = sjv_c;
#line 183
    sjt_math412 = sjt_math415 - sjt_math416;
#line 183
    sjt_math409 = sjt_math411 * sjt_math412;
#line 183
    sjt_math417 = sjv_xnorm;
#line 183
    sjt_math418 = sjv_s;
#line 183
    sjt_math410 = sjt_math417 * sjt_math418;
#line 183
    (*_return)->m21 = sjt_math409 - sjt_math410;
#line 186
    sjt_math423 = sjv_znorm;
#line 186
    sjt_math424 = sjv_znorm;
#line 186
    sjt_math421 = sjt_math423 * sjt_math424;
#line 186
    sjt_math425 = 1.0f;
#line 186
    sjt_math426 = sjv_c;
#line 186
    sjt_math422 = sjt_math425 - sjt_math426;
#line 186
    sjt_math419 = sjt_math421 * sjt_math422;
#line 186
    sjt_math420 = sjv_c;
#line 186
    (*_return)->m22 = sjt_math419 + sjt_math420;
#line 13
    (*_return)->m23 = 0.0f;
#line 14
    (*_return)->m30 = 0.0f;
#line 15
    (*_return)->m31 = 0.0f;
#line 16
    (*_return)->m32 = 0.0f;
#line 187
    (*_return)->m33 = 1.0f;
#line 0 ""
    sjf_mat4_heap((*_return));
}

void sjf_mat4_scale(float x, float y, float z, sjs_mat4* _return) {
#line 203 ".\..\lib\ui\mat4.sj"
    _return->m00 = x;
#line 3
    _return->m01 = 0.0f;
#line 4
    _return->m02 = 0.0f;
#line 5
    _return->m03 = 0.0f;
#line 6
    _return->m10 = 0.0f;
#line 203
    _return->m11 = y;
#line 8
    _return->m12 = 0.0f;
#line 9
    _return->m13 = 0.0f;
#line 10
    _return->m20 = 0.0f;
#line 11
    _return->m21 = 0.0f;
#line 203
    _return->m22 = z;
#line 13
    _return->m23 = 0.0f;
#line 14
    _return->m30 = 0.0f;
#line 15
    _return->m31 = 0.0f;
#line 16
    _return->m32 = 0.0f;
#line 208
    _return->m33 = 1.0f;
#line 0 ""
    sjf_mat4(_return);
}

void sjf_mat4_scale_heap(float x, float y, float z, sjs_mat4_heap** _return) {
    (*_return) = (sjs_mat4_heap*)malloc(sizeof(sjs_mat4_heap));
    (*_return)->_refCount = 1;
#line 203 ".\..\lib\ui\mat4.sj"
    (*_return)->m00 = x;
#line 3
    (*_return)->m01 = 0.0f;
#line 4
    (*_return)->m02 = 0.0f;
#line 5
    (*_return)->m03 = 0.0f;
#line 6
    (*_return)->m10 = 0.0f;
#line 203
    (*_return)->m11 = y;
#line 8
    (*_return)->m12 = 0.0f;
#line 9
    (*_return)->m13 = 0.0f;
#line 10
    (*_return)->m20 = 0.0f;
#line 11
    (*_return)->m21 = 0.0f;
#line 203
    (*_return)->m22 = z;
#line 13
    (*_return)->m23 = 0.0f;
#line 14
    (*_return)->m30 = 0.0f;
#line 15
    (*_return)->m31 = 0.0f;
#line 16
    (*_return)->m32 = 0.0f;
#line 208
    (*_return)->m33 = 1.0f;
#line 0 ""
    sjf_mat4_heap((*_return));
}

void sjf_mat4_transpose(sjs_mat4* _parent, sjs_mat4* _return) {
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

#line 88 ".\..\lib\ui\mat4.sj"
    sjt_dot480 = _parent;
#line 89
    _return->m00 = (sjt_dot480)->m00;
#line 88
    sjt_dot481 = _parent;
#line 89
    _return->m01 = (sjt_dot481)->m10;
#line 88
    sjt_dot482 = _parent;
#line 89
    _return->m02 = (sjt_dot482)->m20;
#line 88
    sjt_dot483 = _parent;
#line 89
    _return->m03 = (sjt_dot483)->m30;
#line 88
    sjt_dot484 = _parent;
#line 89
    _return->m10 = (sjt_dot484)->m01;
#line 88
    sjt_dot485 = _parent;
#line 89
    _return->m11 = (sjt_dot485)->m11;
#line 88
    sjt_dot486 = _parent;
#line 89
    _return->m12 = (sjt_dot486)->m21;
#line 88
    sjt_dot487 = _parent;
#line 89
    _return->m13 = (sjt_dot487)->m31;
#line 88
    sjt_dot488 = _parent;
#line 89
    _return->m20 = (sjt_dot488)->m02;
#line 88
    sjt_dot489 = _parent;
#line 89
    _return->m21 = (sjt_dot489)->m12;
#line 88
    sjt_dot490 = _parent;
#line 89
    _return->m22 = (sjt_dot490)->m22;
#line 88
    sjt_dot491 = _parent;
#line 89
    _return->m23 = (sjt_dot491)->m32;
#line 88
    sjt_dot492 = _parent;
#line 89
    _return->m30 = (sjt_dot492)->m03;
#line 88
    sjt_dot493 = _parent;
#line 89
    _return->m31 = (sjt_dot493)->m13;
#line 88
    sjt_dot494 = _parent;
#line 89
    _return->m32 = (sjt_dot494)->m23;
#line 88
    sjt_dot495 = _parent;
#line 89
    _return->m33 = (sjt_dot495)->m33;
#line 0 ""
    sjf_mat4(_return);
}

void sjf_mat4_transpose_heap(sjs_mat4* _parent, sjs_mat4_heap** _return) {
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

    (*_return) = (sjs_mat4_heap*)malloc(sizeof(sjs_mat4_heap));
    (*_return)->_refCount = 1;
#line 88 ".\..\lib\ui\mat4.sj"
    sjt_dot496 = _parent;
#line 89
    (*_return)->m00 = (sjt_dot496)->m00;
#line 88
    sjt_dot497 = _parent;
#line 89
    (*_return)->m01 = (sjt_dot497)->m10;
#line 88
    sjt_dot498 = _parent;
#line 89
    (*_return)->m02 = (sjt_dot498)->m20;
#line 88
    sjt_dot499 = _parent;
#line 89
    (*_return)->m03 = (sjt_dot499)->m30;
#line 88
    sjt_dot500 = _parent;
#line 89
    (*_return)->m10 = (sjt_dot500)->m01;
#line 88
    sjt_dot501 = _parent;
#line 89
    (*_return)->m11 = (sjt_dot501)->m11;
#line 88
    sjt_dot502 = _parent;
#line 89
    (*_return)->m12 = (sjt_dot502)->m21;
#line 88
    sjt_dot503 = _parent;
#line 89
    (*_return)->m13 = (sjt_dot503)->m31;
#line 88
    sjt_dot504 = _parent;
#line 89
    (*_return)->m20 = (sjt_dot504)->m02;
#line 88
    sjt_dot505 = _parent;
#line 89
    (*_return)->m21 = (sjt_dot505)->m12;
#line 88
    sjt_dot506 = _parent;
#line 89
    (*_return)->m22 = (sjt_dot506)->m22;
#line 88
    sjt_dot507 = _parent;
#line 89
    (*_return)->m23 = (sjt_dot507)->m32;
#line 88
    sjt_dot508 = _parent;
#line 89
    (*_return)->m30 = (sjt_dot508)->m03;
#line 88
    sjt_dot509 = _parent;
#line 89
    (*_return)->m31 = (sjt_dot509)->m13;
#line 88
    sjt_dot510 = _parent;
#line 89
    (*_return)->m32 = (sjt_dot510)->m23;
#line 88
    sjt_dot511 = _parent;
#line 89
    (*_return)->m33 = (sjt_dot511)->m33;
#line 0 ""
    sjf_mat4_heap((*_return));
}

void sjf_point(sjs_point* _this) {
}

void sjf_point_copy(sjs_point* _this, sjs_point* _from) {
#line 1 ".\..\lib\ui\point.sj"
    _this->x = _from->x;
#line 1
    _this->y = _from->y;
}

void sjf_point_destroy(sjs_point* _this) {
}

void sjf_point_heap(sjs_point_heap* _this) {
}

void sjf_property_vec3(sjs_property_vec3* _this) {
}

void sjf_property_vec3_animate(sjs_property_vec3* _parent, sjs_vec3* x, int32_t duration) {
    sjs_animation_vec3_heap* sjt_cast5;
    sjs_anon5* sjt_dot28;
    sjs_anon5* sjt_dot47;
    sjs_property_vec3* sjt_dot48;
    sjs_anon5* sjt_dot49;
    sji_anon5_animation* sjt_functionParam12;
    int32_t sjt_math61;
    int32_t sjt_math62;
    sjs_list_heap_animation* sjt_parent10;
    int32_t void1;

#line 27 ".\..\lib\ui\animation.sj"
    sjt_dot28 = &sjv_animator;
#line 5 ".\..\lib\common\list.sj"
    sjt_parent10 = &(sjt_dot28)->animations;
#line 0 ""
    sjt_cast5 = (sjs_animation_vec3_heap*)malloc(sizeof(sjs_animation_vec3_heap));
    sjt_cast5->_refCount = 1;
#line 27 ".\..\lib\ui\animation.sj"
    sjt_dot47 = &sjv_animator;
#line 21 ".\..\lib\ui\property.sj"
    sjt_cast5->start = (sjt_dot47)->current;
#line 20
    sjt_dot48 = _parent;
#line 21
    sjf_vec3_copy(&sjt_cast5->startValue, &(sjt_dot48)->t);
#line 27 ".\..\lib\ui\animation.sj"
    sjt_dot49 = &sjv_animator;
#line 24 ".\..\lib\ui\property.sj"
    sjt_math61 = (sjt_dot49)->current;
#line 20
    sjt_math62 = duration;
#line 24
    sjt_cast5->end = sjt_math61 + sjt_math62;
#line 20
    sjf_vec3_copy(&sjt_cast5->endValue, x);
#line 26
    sjs_property_vec3_heap* callback1;
#line 26
    callback1 = (sjs_property_vec3_heap*)((char*)_parent - sizeof(intptr_t));
#line 0 ""
    callback1->_refCount++;
#line 26 ".\..\lib\ui\property.sj"
    sjt_cast5->setValue.inner._parent = (void*)(sjs_property_vec3*)(((char*)callback1) + sizeof(intptr_t));
#line 26
    sjt_cast5->setValue._destroy = (void(*)(void*))sjf_property_vec3_destroy;
#line 26
    sjt_cast5->setValue.inner._cb = (void(*)(void*,sjs_vec3*))sjf_property_vec3_set;
#line 0 ""
    sjf_animation_vec3_heap(sjt_cast5);
#line 1 ".\..\lib\ui\animation.sj"
    sjt_functionParam12 = (sji_anon5_animation*)sjf_animation_vec3_heap_as_sji_anon5_animation(sjt_cast5);
#line 0 ""
    sjf_list_heap_animation_add(sjt_parent10, sjt_functionParam12, &void1);

    sjt_cast5->_refCount--;
    if (sjt_cast5->_refCount <= 0) {
        sjf_animation_vec3_destroy((sjs_animation_vec3*)(((char*)sjt_cast5) + sizeof(intptr_t)));
    }
    sjt_functionParam12->_refCount--;
    if (sjt_functionParam12->_refCount <= 0) {
        sji_anon5_animation_destroy(sjt_functionParam12);
    }
}

void sjf_property_vec3_copy(sjs_property_vec3* _this, sjs_property_vec3* _from) {
#line 1 ".\..\lib\ui\property.sj"
    sjf_vec3_copy(&_this->t, &_from->t);
#line 1
    sjf_list_local_cb_void_copy(&_this->invalidate, &_from->invalidate);
#line 1
    _this->_isDirty = _from->_isDirty;
}

void sjf_property_vec3_destroy(sjs_property_vec3* _this) {
}

void sjf_property_vec3_get(sjs_property_vec3* _parent, sjs_vec3** _return) {
    sjs_property_vec3* sjt_dot165;

#line 6 ".\..\lib\ui\property.sj"
    sjt_dot165 = _parent;
#line 6
    (*_return) = &(sjt_dot165)->t;
}

void sjf_property_vec3_getIsDirty(sjs_property_vec3* _parent, bool* _return) {
    sjs_property_vec3* sjt_dot169;
    bool sjt_ifElse8;

#line 31 ".\..\lib\ui\property.sj"
    sjt_dot169 = _parent;
#line 32
    sjt_ifElse8 = (sjt_dot169)->_isDirty;
    if (sjt_ifElse8) {
        sjs_property_vec3* sjt_dot170;

#line 31 ".\..\lib\ui\property.sj"
        sjt_dot170 = _parent;
#line 33
        sjt_dot170->_isDirty = false;
#line 34
        (*_return) = true;
    } else {
#line 36 ".\..\lib\ui\property.sj"
        (*_return) = false;
    }
}

void sjf_property_vec3_heap(sjs_property_vec3_heap* _this) {
}

void sjf_property_vec3_set(sjs_property_vec3* _parent, sjs_vec3* x) {
    bool result2;
    sjs_property_vec3* sjt_dot56;
    sjs_vec3* sjt_functionParam16;
    bool sjt_ifElse5;
    bool sjt_not1;
    sjs_vec3* sjt_parent12;

#line 8 ".\..\lib\ui\property.sj"
    sjt_dot56 = _parent;
#line 6 ".\..\lib\ui\vec3.sj"
    sjt_parent12 = &(sjt_dot56)->t;
#line 8 ".\..\lib\ui\property.sj"
    sjt_functionParam16 = x;
#line 0 ""
    sjf_vec3_isEqual(sjt_parent12, sjt_functionParam16, &sjt_not1);
#line 9 ".\..\lib\ui\property.sj"
    result2 = !sjt_not1;
#line 9
    sjt_ifElse5 = result2;
    if (sjt_ifElse5) {
        int32_t i;
        sjs_property_vec3* sjt_dot57;
        sjs_property_vec3* sjt_dot58;
        sjs_list_local_cb_void* sjt_dot59;
        sjs_property_vec3* sjt_dot60;
        int32_t sjt_forEnd4;
        int32_t sjt_forStart4;

#line 8 ".\..\lib\ui\property.sj"
        sjt_dot57 = _parent;
#line 8
        sjf_vec3_copy(&sjt_dot57->t, x);
#line 8
        sjt_dot58 = _parent;
#line 11
        sjt_dot58->_isDirty = true;
#line 12
        sjt_forStart4 = 0;
#line 12
        i = sjt_forStart4;
#line 8
        sjt_dot60 = _parent;
#line 1 ".\..\lib\common\list.sj"
        sjt_dot59 = &(sjt_dot60)->invalidate;
#line 12 ".\..\lib\ui\property.sj"
        sjt_forEnd4 = (sjt_dot59)->count;
        while (i < sjt_forEnd4) {
            cb_void sjt_callback2;
            sjs_property_vec3* sjt_dot62;
            int32_t sjt_functionParam18;
            sjs_list_local_cb_void* sjt_parent14;
            cb_void sjv_cb;

#line 8 ".\..\lib\ui\property.sj"
            sjt_dot62 = _parent;
#line 19 ".\..\lib\common\list.sj"
            sjt_parent14 = &(sjt_dot62)->invalidate;
#line 12 ".\..\lib\ui\property.sj"
            sjt_functionParam18 = i;
#line 0 ""
            sjf_list_local_cb_void_getAt(sjt_parent14, sjt_functionParam18, &sjv_cb);
#line 14 ".\..\lib\ui\property.sj"
            sjt_callback2 = sjv_cb;
#line 0 ""
            sjt_callback2._cb(sjt_callback2._parent);
#line 12 ".\..\lib\ui\property.sj"
            i++;
        }
    }
}

void sjf_rect(sjs_rect* _this) {
}

void sjf_rect_containsPoint(sjs_rect* _parent, sjs_point* point, bool* _return) {
    bool sjt_and17;
    bool sjt_and18;
    bool sjt_and19;
    bool sjt_and20;
    bool sjt_and21;
    bool sjt_and22;
    int32_t sjt_compare63;
    int32_t sjt_compare64;
    int32_t sjt_compare65;
    int32_t sjt_compare66;
    int32_t sjt_compare67;
    int32_t sjt_compare68;
    int32_t sjt_compare69;
    int32_t sjt_compare70;
    sjs_rect* sjt_dot1414;
    sjs_point* sjt_dot1415;
    sjs_rect* sjt_dot1416;
    sjs_point* sjt_dot1417;
    sjs_point* sjt_dot1418;
    sjs_rect* sjt_dot1419;
    sjs_rect* sjt_dot1420;
    sjs_point* sjt_dot1421;
    sjs_rect* sjt_dot1422;
    sjs_rect* sjt_dot1423;
    int32_t sjt_math2705;
    int32_t sjt_math2706;
    int32_t sjt_math2707;
    int32_t sjt_math2708;

#line 11 ".\..\lib\ui\rect.sj"
    sjt_dot1414 = _parent;
#line 12
    sjt_compare63 = (sjt_dot1414)->x;
#line 11
    sjt_dot1415 = point;
#line 12
    sjt_compare64 = (sjt_dot1415)->x;
#line 12
    sjt_and17 = sjt_compare63 <= sjt_compare64;
#line 11
    sjt_dot1416 = _parent;
#line 12
    sjt_compare65 = (sjt_dot1416)->y;
#line 11
    sjt_dot1417 = point;
#line 12
    sjt_compare66 = (sjt_dot1417)->x;
#line 12
    sjt_and19 = sjt_compare65 <= sjt_compare66;
#line 11
    sjt_dot1418 = point;
#line 12
    sjt_compare67 = (sjt_dot1418)->x;
#line 11
    sjt_dot1419 = _parent;
#line 12
    sjt_math2705 = (sjt_dot1419)->x;
#line 11
    sjt_dot1420 = _parent;
#line 12
    sjt_math2706 = (sjt_dot1420)->w;
#line 12
    sjt_compare68 = sjt_math2705 + sjt_math2706;
#line 12
    sjt_and21 = sjt_compare67 < sjt_compare68;
#line 11
    sjt_dot1421 = point;
#line 12
    sjt_compare69 = (sjt_dot1421)->y;
#line 11
    sjt_dot1422 = _parent;
#line 12
    sjt_math2707 = (sjt_dot1422)->y;
#line 11
    sjt_dot1423 = _parent;
#line 12
    sjt_math2708 = (sjt_dot1423)->h;
#line 12
    sjt_compare70 = sjt_math2707 + sjt_math2708;
#line 12
    sjt_and22 = sjt_compare69 < sjt_compare70;
#line 12
    sjt_and20 = sjt_and21 && sjt_and22;
#line 12
    sjt_and18 = sjt_and19 && sjt_and20;
#line 12
    (*_return) = sjt_and17 && sjt_and18;
}

void sjf_rect_copy(sjs_rect* _this, sjs_rect* _from) {
#line 1 ".\..\lib\ui\rect.sj"
    _this->x = _from->x;
#line 1
    _this->y = _from->y;
#line 1
    _this->w = _from->w;
#line 1
    _this->h = _from->h;
}

void sjf_rect_destroy(sjs_rect* _this) {
}

void sjf_rect_heap(sjs_rect_heap* _this) {
}

void sjf_rect_isEqual(sjs_rect* _parent, sjs_rect* rect, bool* _return) {
    bool sjt_and10;
    bool sjt_and5;
    bool sjt_and6;
    bool sjt_and7;
    bool sjt_and8;
    bool sjt_and9;
    int32_t sjt_compare17;
    int32_t sjt_compare18;
    int32_t sjt_compare19;
    int32_t sjt_compare20;
    int32_t sjt_compare21;
    int32_t sjt_compare22;
    int32_t sjt_compare23;
    int32_t sjt_compare24;
    sjs_rect* sjt_dot68;
    sjs_rect* sjt_dot69;
    sjs_rect* sjt_dot70;
    sjs_rect* sjt_dot71;
    sjs_rect* sjt_dot72;
    sjs_rect* sjt_dot73;
    sjs_rect* sjt_dot74;
    sjs_rect* sjt_dot75;

#line 15 ".\..\lib\ui\rect.sj"
    sjt_dot68 = _parent;
#line 16
    sjt_compare17 = (sjt_dot68)->x;
#line 15
    sjt_dot69 = rect;
#line 16
    sjt_compare18 = (sjt_dot69)->x;
#line 16
    sjt_and5 = sjt_compare17 == sjt_compare18;
#line 15
    sjt_dot70 = _parent;
#line 16
    sjt_compare19 = (sjt_dot70)->y;
#line 15
    sjt_dot71 = rect;
#line 16
    sjt_compare20 = (sjt_dot71)->y;
#line 16
    sjt_and7 = sjt_compare19 == sjt_compare20;
#line 15
    sjt_dot72 = _parent;
#line 16
    sjt_compare21 = (sjt_dot72)->w;
#line 15
    sjt_dot73 = rect;
#line 16
    sjt_compare22 = (sjt_dot73)->w;
#line 16
    sjt_and9 = sjt_compare21 == sjt_compare22;
#line 15
    sjt_dot74 = _parent;
#line 16
    sjt_compare23 = (sjt_dot74)->h;
#line 15
    sjt_dot75 = rect;
#line 16
    sjt_compare24 = (sjt_dot75)->h;
#line 16
    sjt_and10 = sjt_compare23 == sjt_compare24;
#line 16
    sjt_and8 = sjt_and9 && sjt_and10;
#line 16
    sjt_and6 = sjt_and7 && sjt_and8;
#line 16
    (*_return) = sjt_and5 && sjt_and6;
}

void sjf_rect_subtractMargin(sjs_rect* _parent, sjs_margin* margin, sjs_rect* _return) {
    sjs_rect* sjt_dot1358;
    sjs_margin* sjt_dot1359;
    sjs_rect* sjt_dot1360;
    sjs_margin* sjt_dot1361;
    sjs_rect* sjt_dot1362;
    sjs_margin* sjt_dot1363;
    sjs_margin* sjt_dot1364;
    sjs_rect* sjt_dot1365;
    sjs_margin* sjt_dot1366;
    sjs_margin* sjt_dot1367;
    int32_t sjt_math2681;
    int32_t sjt_math2682;
    int32_t sjt_math2683;
    int32_t sjt_math2684;
    int32_t sjt_math2685;
    int32_t sjt_math2686;
    int32_t sjt_math2687;
    int32_t sjt_math2688;
    int32_t sjt_math2689;
    int32_t sjt_math2690;
    int32_t sjt_math2691;
    int32_t sjt_math2692;

#line 7 ".\..\lib\ui\rect.sj"
    sjt_dot1358 = _parent;
#line 8
    sjt_math2681 = (sjt_dot1358)->x;
#line 7
    sjt_dot1359 = margin;
#line 8
    sjt_math2682 = (sjt_dot1359)->l;
#line 8
    _return->x = sjt_math2681 + sjt_math2682;
#line 7
    sjt_dot1360 = _parent;
#line 8
    sjt_math2683 = (sjt_dot1360)->y;
#line 7
    sjt_dot1361 = margin;
#line 8
    sjt_math2684 = (sjt_dot1361)->t;
#line 8
    _return->y = sjt_math2683 + sjt_math2684;
#line 7
    sjt_dot1362 = _parent;
#line 8
    sjt_math2687 = (sjt_dot1362)->w;
#line 7
    sjt_dot1363 = margin;
#line 8
    sjt_math2688 = (sjt_dot1363)->l;
#line 8
    sjt_math2685 = sjt_math2687 - sjt_math2688;
#line 7
    sjt_dot1364 = margin;
#line 8
    sjt_math2686 = (sjt_dot1364)->r;
#line 8
    _return->w = sjt_math2685 - sjt_math2686;
#line 7
    sjt_dot1365 = _parent;
#line 8
    sjt_math2691 = (sjt_dot1365)->h;
#line 7
    sjt_dot1366 = margin;
#line 8
    sjt_math2692 = (sjt_dot1366)->t;
#line 8
    sjt_math2689 = sjt_math2691 - sjt_math2692;
#line 7
    sjt_dot1367 = margin;
#line 8
    sjt_math2690 = (sjt_dot1367)->b;
#line 8
    _return->h = sjt_math2689 - sjt_math2690;
#line 0 ""
    sjf_rect(_return);
}

void sjf_rect_subtractMargin_heap(sjs_rect* _parent, sjs_margin* margin, sjs_rect_heap** _return) {
    sjs_rect* sjt_dot1368;
    sjs_margin* sjt_dot1369;
    sjs_rect* sjt_dot1370;
    sjs_margin* sjt_dot1371;
    sjs_rect* sjt_dot1372;
    sjs_margin* sjt_dot1373;
    sjs_margin* sjt_dot1374;
    sjs_rect* sjt_dot1375;
    sjs_margin* sjt_dot1376;
    sjs_margin* sjt_dot1377;
    int32_t sjt_math2693;
    int32_t sjt_math2694;
    int32_t sjt_math2695;
    int32_t sjt_math2696;
    int32_t sjt_math2697;
    int32_t sjt_math2698;
    int32_t sjt_math2699;
    int32_t sjt_math2700;
    int32_t sjt_math2701;
    int32_t sjt_math2702;
    int32_t sjt_math2703;
    int32_t sjt_math2704;

    (*_return) = (sjs_rect_heap*)malloc(sizeof(sjs_rect_heap));
    (*_return)->_refCount = 1;
#line 7 ".\..\lib\ui\rect.sj"
    sjt_dot1368 = _parent;
#line 8
    sjt_math2693 = (sjt_dot1368)->x;
#line 7
    sjt_dot1369 = margin;
#line 8
    sjt_math2694 = (sjt_dot1369)->l;
#line 8
    (*_return)->x = sjt_math2693 + sjt_math2694;
#line 7
    sjt_dot1370 = _parent;
#line 8
    sjt_math2695 = (sjt_dot1370)->y;
#line 7
    sjt_dot1371 = margin;
#line 8
    sjt_math2696 = (sjt_dot1371)->t;
#line 8
    (*_return)->y = sjt_math2695 + sjt_math2696;
#line 7
    sjt_dot1372 = _parent;
#line 8
    sjt_math2699 = (sjt_dot1372)->w;
#line 7
    sjt_dot1373 = margin;
#line 8
    sjt_math2700 = (sjt_dot1373)->l;
#line 8
    sjt_math2697 = sjt_math2699 - sjt_math2700;
#line 7
    sjt_dot1374 = margin;
#line 8
    sjt_math2698 = (sjt_dot1374)->r;
#line 8
    (*_return)->w = sjt_math2697 - sjt_math2698;
#line 7
    sjt_dot1375 = _parent;
#line 8
    sjt_math2703 = (sjt_dot1375)->h;
#line 7
    sjt_dot1376 = margin;
#line 8
    sjt_math2704 = (sjt_dot1376)->t;
#line 8
    sjt_math2701 = sjt_math2703 - sjt_math2704;
#line 7
    sjt_dot1377 = margin;
#line 8
    sjt_math2702 = (sjt_dot1377)->b;
#line 8
    (*_return)->h = sjt_math2701 - sjt_math2702;
#line 0 ""
    sjf_rect_heap((*_return));
}

void sjf_runLoop(void) {
#line 59 ".\..\lib\ui\loop.sj"
    #ifdef EMSCRIPTEN
#line 59
    emscripten_set_main_loop((em_callback_func)sjf_mainLoop, 0, 0);
#line 59
    exit(0);
#line 59
    #else
#line 59
    bool quit = false;
#line 59
    while (!quit) {
#line 59
        sjf_mainLoop();
#line 59
    }
#line 59
    #endif
}

void sjf_scene2d(sjs_scene2d* _this) {
}

void sjf_scene2dModel(sjs_scene2dModel* _this) {
    int32_t i;
    sjs_size* sjt_dot195;
    sjs_frameBuffer* sjt_dot196;
    sjs_size* sjt_dot197;
    sjs_frameBuffer* sjt_dot198;
    sjs_array_heap_element* sjt_dot199;
    int32_t sjt_forEnd8;
    int32_t sjt_forStart8;
    sjs_rect sjv_rect;

#line 59 ".\..\lib\ui\scene2dModel.sj"
    sjv_rect.x = 0;
#line 59
    sjv_rect.y = 0;
#line 1
    sjt_dot196 = &_this->frameBuffer;
#line 1 ".\..\lib\ui\size.sj"
    sjt_dot195 = &(sjt_dot196)->size;
#line 59 ".\..\lib\ui\scene2dModel.sj"
    sjv_rect.w = (sjt_dot195)->w;
#line 1
    sjt_dot198 = &_this->frameBuffer;
#line 1 ".\..\lib\ui\size.sj"
    sjt_dot197 = &(sjt_dot198)->size;
#line 59 ".\..\lib\ui\scene2dModel.sj"
    sjv_rect.h = (sjt_dot197)->h;
#line 0 ""
    sjf_rect(&sjv_rect);
#line 60 ".\..\lib\ui\scene2dModel.sj"
    sjt_forStart8 = 0;
#line 60
    i = sjt_forStart8;
#line 1
    sjt_dot199 = &_this->children;
#line 60
    sjt_forEnd8 = (sjt_dot199)->size;
    while (i < sjt_forEnd8) {
        int32_t sjt_functionParam65;
        sjs_rect* sjt_interfaceParam10;
        sjs_array_heap_element* sjt_parent44;
        sji_element* sjt_parent45;
        sji_element* sjv_child;

#line 1 ".\..\lib\ui\scene2dModel.sj"
        sjt_parent44 = &_this->children;
#line 60
        sjt_functionParam65 = i;
#line 0 ""
        sjf_array_heap_element_getAt_heap(sjt_parent44, sjt_functionParam65, &sjv_child);
#line 4 ".\..\lib\ui\element.sj"
        sjt_parent45 = sjv_child;
#line 4
        sjt_interfaceParam10 = &sjv_rect;
#line 62 ".\..\lib\ui\scene2dModel.sj"
        sjt_parent45->setRect((void*)(((char*)sjt_parent45->_parent) + sizeof(intptr_t)), sjt_interfaceParam10);
#line 60
        i++;

        sjv_child->_refCount--;
        if (sjv_child->_refCount <= 0) {
            sji_element_destroy(sjv_child);
        }
    }

    sjf_rect_destroy(&sjv_rect);
}

sjs_object* sjf_scene2dModel_asInterface(sjs_scene2dModel* _this, int typeId) {
    switch (typeId) {
        case sji_scene3dElement_model_typeId:  {
            return (sjs_object*)sjf_scene2dModel_as_sji_scene3dElement_model(_this);
        }
    }

    return 0;
}

sji_scene3dElement_model* sjf_scene2dModel_as_sji_scene3dElement_model(sjs_scene2dModel* _this) {
    sji_scene3dElement_model* _interface;
    _interface = (sji_scene3dElement_model*)malloc(sizeof(sji_scene3dElement_model));
    _interface->_refCount = 1;
    _interface->_parent = (sjs_object*)_this;
    _interface->_parent->_refCount++;
    _interface->destroy = (void(*)(void*))sjf_scene2dModel_destroy;
    _interface->asInterface = (sjs_object*(*)(sjs_object*,int))sjf_scene2dModel_asInterface;
    _interface->setWorld = (void(*)(void*,sjs_mat4*))sjf_scene2dModel_setWorld;
    _interface->render = (void(*)(void*,sjs_scene3dElement*))sjf_scene2dModel_render;
    _interface->fireMouseEvent = (void(*)(void*,sjs_scene3dElement*,sjs_point*,int32_t))sjf_scene2dModel_fireMouseEvent;

    return _interface;
}

void sjf_scene2dModel_copy(sjs_scene2dModel* _this, sjs_scene2dModel* _from) {
#line 1 ".\..\lib\ui\scene2dModel.sj"
    sjf_vertexBuffer_vertex_location_texture_normal_copy(&_this->vertexBuffer, &_from->vertexBuffer);
#line 1
    sjf_shader_copy(&_this->shader, &_from->shader);
#line 1
    sjf_frameBuffer_copy(&_this->frameBuffer, &_from->frameBuffer);
#line 1
    sjf_array_heap_element_copy(&_this->children, &_from->children);
#line 1
    sjf_scene2d_copy(&_this->_innerScene, &_from->_innerScene);
#line 1
    sjf_mat4_copy(&_this->_world, &_from->_world);
}

void sjf_scene2dModel_destroy(sjs_scene2dModel* _this) {
}

void sjf_scene2dModel_fireMouseEvent(sjs_scene2dModel* _parent, sjs_scene3dElement* scene3d, sjs_point* point, int32_t eventId) {
    bool result13;
    sjs_scene2dModel* sjt_dot1300;
    sjs_scene3dElement* sjt_dot1301;
    sjs_scene3dElement* sjt_dot1302;
    sjs_scene2dModel* sjt_dot1303;
    sjs_point* sjt_functionParam106;
    sjs_rect* sjt_functionParam107;
    sjs_mat4* sjt_functionParam108;
    sjs_mat4* sjt_functionParam109;
    sjs_mat4* sjt_functionParam110;
    bool sjt_ifElse29;
    sjs_vec2_heap* sjt_isEmpty9;
    bool sjt_not5;
    sjs_vertexBuffer_vertex_location_texture_normal* sjt_parent79;
    sjs_scene3dElement* sjt_parent80;
    sjs_vec2_heap* sjv_texture;

#line 46 ".\..\lib\ui\scene2dModel.sj"
    sjt_dot1300 = _parent;
#line 37 ".\..\lib\ui\vertexBuffer.sj"
    sjt_parent79 = &(sjt_dot1300)->vertexBuffer;
#line 46 ".\..\lib\ui\scene2dModel.sj"
    sjt_functionParam106 = point;
#line 46
    sjt_parent80 = scene3d;
#line 0 ""
    sjf_scene3dElement_getRect(sjt_parent80, &sjt_functionParam107);
#line 46 ".\..\lib\ui\scene2dModel.sj"
    sjt_dot1301 = scene3d;
#line 47
    sjt_functionParam108 = &(sjt_dot1301)->projection;
#line 46
    sjt_dot1302 = scene3d;
#line 47
    sjt_functionParam109 = &(sjt_dot1302)->view;
#line 46
    sjt_dot1303 = _parent;
#line 47
    sjt_functionParam110 = &(sjt_dot1303)->_world;
#line 0 ""
    sjf_vertexBuffer_vertex_location_texture_normal_translateScreenToTexture_heap(sjt_parent79, sjt_functionParam106, sjt_functionParam107, sjt_functionParam108, sjt_functionParam109, sjt_functionParam110, &sjv_texture);
#line 48 ".\..\lib\ui\scene2dModel.sj"
    sjt_isEmpty9 = sjv_texture;
    if (sjt_isEmpty9 != 0) {
        sjt_isEmpty9->_refCount++;
    }

#line 48
    sjt_not5 = (sjt_isEmpty9 == 0);
#line 48
    result13 = !sjt_not5;
#line 48
    sjt_ifElse29 = result13;
    if (sjt_ifElse29) {
        int32_t i;
        float sjt_cast18;
        int32_t sjt_cast19;
        float sjt_cast20;
        int32_t sjt_cast21;
        sjs_vec2* sjt_dot1304;
        sjs_size* sjt_dot1305;
        sjs_frameBuffer* sjt_dot1306;
        sjs_scene2dModel* sjt_dot1307;
        sjs_vec2* sjt_dot1308;
        sjs_size* sjt_dot1309;
        sjs_frameBuffer* sjt_dot1310;
        sjs_scene2dModel* sjt_dot1311;
        sjs_array_heap_element* sjt_dot1312;
        sjs_scene2dModel* sjt_dot1313;
        int32_t sjt_forEnd11;
        int32_t sjt_forStart11;
        float sjt_math2409;
        float sjt_math2410;
        float sjt_math2411;
        float sjt_math2412;
        sjs_point sjv_scenePoint;

#line 1 ".\..\lib\ui\vec2.sj"
        sjt_dot1304 = (sjs_vec2*)(((char*)sjv_texture) + sizeof(intptr_t));
#line 50 ".\..\lib\ui\scene2dModel.sj"
        sjt_math2409 = (sjt_dot1304)->x;
#line 46
        sjt_dot1307 = _parent;
#line 1 ".\..\lib\ui\frameBuffer.sj"
        sjt_dot1306 = &(sjt_dot1307)->frameBuffer;
#line 1 ".\..\lib\ui\size.sj"
        sjt_dot1305 = &(sjt_dot1306)->size;
#line 50 ".\..\lib\ui\scene2dModel.sj"
        sjt_cast19 = (sjt_dot1305)->w;
#line 50
        sjt_math2410 = (float)sjt_cast19;
#line 50
        sjt_cast18 = sjt_math2409 * sjt_math2410;
#line 50
        sjv_scenePoint.x = (int32_t)sjt_cast18;
#line 1 ".\..\lib\ui\vec2.sj"
        sjt_dot1308 = (sjs_vec2*)(((char*)sjv_texture) + sizeof(intptr_t));
#line 51 ".\..\lib\ui\scene2dModel.sj"
        sjt_math2411 = (sjt_dot1308)->y;
#line 46
        sjt_dot1311 = _parent;
#line 1 ".\..\lib\ui\frameBuffer.sj"
        sjt_dot1310 = &(sjt_dot1311)->frameBuffer;
#line 1 ".\..\lib\ui\size.sj"
        sjt_dot1309 = &(sjt_dot1310)->size;
#line 51 ".\..\lib\ui\scene2dModel.sj"
        sjt_cast21 = (sjt_dot1309)->h;
#line 51
        sjt_math2412 = (float)sjt_cast21;
#line 51
        sjt_cast20 = sjt_math2411 * sjt_math2412;
#line 51
        sjv_scenePoint.y = (int32_t)sjt_cast20;
#line 0 ""
        sjf_point(&sjv_scenePoint);
#line 52 ".\..\lib\ui\scene2dModel.sj"
        sjt_forStart11 = 0;
#line 52
        i = sjt_forStart11;
#line 46
        sjt_dot1313 = _parent;
#line 1 ".\..\lib\common\array.sj"
        sjt_dot1312 = &(sjt_dot1313)->children;
#line 52 ".\..\lib\ui\scene2dModel.sj"
        sjt_forEnd11 = (sjt_dot1312)->size;
        while (i < sjt_forEnd11) {
            sjs_scene2dModel* sjt_dot1314;
            int32_t sjt_functionParam111;
            sjs_point* sjt_interfaceParam12;
            int32_t sjt_interfaceParam13;
            sjs_array_heap_element* sjt_parent81;
            sji_element* sjt_parent82;
            sji_element* sjv_child;

#line 46 ".\..\lib\ui\scene2dModel.sj"
            sjt_dot1314 = _parent;
#line 6 ".\..\lib\common\array.sj"
            sjt_parent81 = &(sjt_dot1314)->children;
#line 52 ".\..\lib\ui\scene2dModel.sj"
            sjt_functionParam111 = i;
#line 0 ""
            sjf_array_heap_element_getAt_heap(sjt_parent81, sjt_functionParam111, &sjv_child);
#line 7 ".\..\lib\ui\element.sj"
            sjt_parent82 = sjv_child;
#line 7
            sjt_interfaceParam12 = &sjv_scenePoint;
#line 46 ".\..\lib\ui\scene2dModel.sj"
            sjt_interfaceParam13 = eventId;
#line 54
            sjt_parent82->fireMouseEvent((void*)(((char*)sjt_parent82->_parent) + sizeof(intptr_t)), sjt_interfaceParam12, sjt_interfaceParam13);
#line 52
            i++;

            sjv_child->_refCount--;
            if (sjv_child->_refCount <= 0) {
                sji_element_destroy(sjv_child);
            }
        }

        sjf_point_destroy(&sjv_scenePoint);
    }

    if (sjt_isEmpty9 != 0) {
        sjt_isEmpty9->_refCount--;
        if (sjt_isEmpty9->_refCount <= 0) {
            sjf_vec2_destroy((sjs_vec2*)(((char*)sjt_isEmpty9) + sizeof(intptr_t)));
        }
    }
    if (sjv_texture != 0) {
        sjv_texture->_refCount--;
        if (sjv_texture->_refCount <= 0) {
            sjf_vec2_destroy((sjs_vec2*)(((char*)sjv_texture) + sizeof(intptr_t)));
        }
    }
}

void sjf_scene2dModel_heap(sjs_scene2dModel_heap* _this) {
    int32_t i;
    sjs_size* sjt_dot1315;
    sjs_frameBuffer* sjt_dot1316;
    sjs_size* sjt_dot1317;
    sjs_frameBuffer* sjt_dot1318;
    sjs_array_heap_element* sjt_dot1319;
    int32_t sjt_forEnd12;
    int32_t sjt_forStart12;
    sjs_rect sjv_rect;

#line 59 ".\..\lib\ui\scene2dModel.sj"
    sjv_rect.x = 0;
#line 59
    sjv_rect.y = 0;
#line 1 ".\..\lib\ui\frameBuffer.sj"
    sjt_dot1316 = &_this->frameBuffer;
#line 1 ".\..\lib\ui\size.sj"
    sjt_dot1315 = &(sjt_dot1316)->size;
#line 59 ".\..\lib\ui\scene2dModel.sj"
    sjv_rect.w = (sjt_dot1315)->w;
#line 1 ".\..\lib\ui\frameBuffer.sj"
    sjt_dot1318 = &_this->frameBuffer;
#line 1 ".\..\lib\ui\size.sj"
    sjt_dot1317 = &(sjt_dot1318)->size;
#line 59 ".\..\lib\ui\scene2dModel.sj"
    sjv_rect.h = (sjt_dot1317)->h;
#line 0 ""
    sjf_rect(&sjv_rect);
#line 60 ".\..\lib\ui\scene2dModel.sj"
    sjt_forStart12 = 0;
#line 60
    i = sjt_forStart12;
#line 1 ".\..\lib\common\array.sj"
    sjt_dot1319 = &_this->children;
#line 60 ".\..\lib\ui\scene2dModel.sj"
    sjt_forEnd12 = (sjt_dot1319)->size;
    while (i < sjt_forEnd12) {
        int32_t sjt_functionParam112;
        sjs_rect* sjt_interfaceParam14;
        sjs_array_heap_element* sjt_parent83;
        sji_element* sjt_parent84;
        sji_element* sjv_child;

#line 6 ".\..\lib\common\array.sj"
        sjt_parent83 = &_this->children;
#line 60 ".\..\lib\ui\scene2dModel.sj"
        sjt_functionParam112 = i;
#line 0 ""
        sjf_array_heap_element_getAt_heap(sjt_parent83, sjt_functionParam112, &sjv_child);
#line 4 ".\..\lib\ui\element.sj"
        sjt_parent84 = sjv_child;
#line 4
        sjt_interfaceParam14 = &sjv_rect;
#line 62 ".\..\lib\ui\scene2dModel.sj"
        sjt_parent84->setRect((void*)(((char*)sjt_parent84->_parent) + sizeof(intptr_t)), sjt_interfaceParam14);
#line 60
        i++;

        sjv_child->_refCount--;
        if (sjv_child->_refCount <= 0) {
            sji_element_destroy(sjv_child);
        }
    }

    sjf_rect_destroy(&sjv_rect);
}

sjs_object* sjf_scene2dModel_heap_asInterface(sjs_scene2dModel_heap* _this, int typeId) {
    switch (typeId) {
        case sji_scene3dElement_model_typeId:  {
            return (sjs_object*)sjf_scene2dModel_heap_as_sji_scene3dElement_model(_this);
        }
    }

    return 0;
}

sji_scene3dElement_model* sjf_scene2dModel_heap_as_sji_scene3dElement_model(sjs_scene2dModel_heap* _this) {
    sji_scene3dElement_model* _interface;
    _interface = (sji_scene3dElement_model*)malloc(sizeof(sji_scene3dElement_model));
    _interface->_refCount = 1;
    _interface->_parent = (sjs_object*)_this;
    _interface->_parent->_refCount++;
    _interface->destroy = (void(*)(void*))sjf_scene2dModel_destroy;
    _interface->asInterface = (sjs_object*(*)(sjs_object*,int))sjf_scene2dModel_heap_asInterface;
    _interface->setWorld = (void(*)(void*,sjs_mat4*))sjf_scene2dModel_setWorld;
    _interface->render = (void(*)(void*,sjs_scene3dElement*))sjf_scene2dModel_render;
    _interface->fireMouseEvent = (void(*)(void*,sjs_scene3dElement*,sjs_point*,int32_t))sjf_scene2dModel_fireMouseEvent;

    return _interface;
}

void sjf_scene2dModel_render(sjs_scene2dModel* _parent, sjs_scene3dElement* scene3d) {
    int32_t i;
    sjs_mat4 sjt_call6;
    sjs_scene2dModel* sjt_dot1216;
    sjs_scene2dModel* sjt_dot214;
    sjs_frameBuffer* sjt_dot215;
    sjs_scene2dModel* sjt_dot216;
    sjs_scene2dModel* sjt_dot217;
    sjs_array_heap_element* sjt_dot218;
    sjs_scene2dModel* sjt_dot219;
    sjs_scene3dElement* sjt_dot478;
    sjs_scene2dModel* sjt_dot479;
    int32_t sjt_forEnd9;
    int32_t sjt_forStart9;
    sjs_size* sjt_functionParam76;
    sjs_mat4* sjt_functionParam78;
    sjs_scene2d* sjt_parent47;
    sjs_scene2d* sjt_parent48;
    sjs_scene3dElement* sjt_parent51;
    sjs_mat4* sjt_parent52;
    sjs_mat4* sjt_parent53;
    sjs_mat4* sjt_parent56;
    sjs_vertexBuffer_vertex_location_texture_normal* sjt_parent57;
    sjs_mat4 sjv_normalMat;
    sjs_mat4 sjv_viewWorld;

#line 15 ".\..\lib\ui\scene2dModel.sj"
    glBindFramebuffer(GL_FRAMEBUFFER, _parent->frameBuffer.frameBufferId);
#line 14
    sjt_dot214 = _parent;
#line 27 ".\..\lib\ui\scene2d.sj"
    sjt_parent47 = &(sjt_dot214)->_innerScene;
#line 14 ".\..\lib\ui\scene2dModel.sj"
    sjt_dot216 = _parent;
#line 1 ".\..\lib\ui\frameBuffer.sj"
    sjt_dot215 = &(sjt_dot216)->frameBuffer;
#line 19 ".\..\lib\ui\scene2dModel.sj"
    sjt_functionParam76 = &(sjt_dot215)->size;
#line 0 ""
    sjf_scene2d_setSize(sjt_parent47, sjt_functionParam76);
#line 14 ".\..\lib\ui\scene2dModel.sj"
    sjt_dot217 = _parent;
#line 7 ".\..\lib\ui\scene2d.sj"
    sjt_parent48 = &(sjt_dot217)->_innerScene;
#line 0 ""
    sjf_scene2d_clear(sjt_parent48);
#line 21 ".\..\lib\ui\scene2dModel.sj"
    sjt_forStart9 = 0;
#line 21
    i = sjt_forStart9;
#line 14
    sjt_dot219 = _parent;
#line 1 ".\..\lib\common\array.sj"
    sjt_dot218 = &(sjt_dot219)->children;
#line 21 ".\..\lib\ui\scene2dModel.sj"
    sjt_forEnd9 = (sjt_dot218)->size;
    while (i < sjt_forEnd9) {
        sjs_scene2dModel* sjt_dot220;
        sjs_scene2dModel* sjt_dot221;
        int32_t sjt_functionParam77;
        sjs_scene2d* sjt_interfaceParam11;
        sjs_array_heap_element* sjt_parent49;
        sji_element* sjt_parent50;
        sji_element* sjv_child;

#line 14 ".\..\lib\ui\scene2dModel.sj"
        sjt_dot220 = _parent;
#line 6 ".\..\lib\common\array.sj"
        sjt_parent49 = &(sjt_dot220)->children;
#line 21 ".\..\lib\ui\scene2dModel.sj"
        sjt_functionParam77 = i;
#line 0 ""
        sjf_array_heap_element_getAt_heap(sjt_parent49, sjt_functionParam77, &sjv_child);
#line 5 ".\..\lib\ui\element.sj"
        sjt_parent50 = sjv_child;
#line 14 ".\..\lib\ui\scene2dModel.sj"
        sjt_dot221 = _parent;
#line 5 ".\..\lib\ui\element.sj"
        sjt_interfaceParam11 = &(sjt_dot221)->_innerScene;
#line 23 ".\..\lib\ui\scene2dModel.sj"
        sjt_parent50->render((void*)(((char*)sjt_parent50->_parent) + sizeof(intptr_t)), sjt_interfaceParam11);
#line 21
        i++;

        sjv_child->_refCount--;
        if (sjv_child->_refCount <= 0) {
            sji_element_destroy(sjv_child);
        }
    }

#line 26
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
#line 14
    sjt_parent51 = scene3d;
#line 0 ""
    sjf_scene3dElement_updateViewport(sjt_parent51);
#line 14 ".\..\lib\ui\scene2dModel.sj"
    sjt_dot478 = scene3d;
#line 19 ".\..\lib\ui\mat4.sj"
    sjt_parent52 = &(sjt_dot478)->view;
#line 14 ".\..\lib\ui\scene2dModel.sj"
    sjt_dot479 = _parent;
#line 31
    sjt_functionParam78 = &(sjt_dot479)->_world;
#line 0 ""
    sjf_mat4_multiply(sjt_parent52, sjt_functionParam78, &sjv_viewWorld);
#line 61 ".\..\lib\ui\mat4.sj"
    sjt_parent56 = &sjv_viewWorld;
#line 0 ""
    sjf_mat4_invert(sjt_parent56, &sjt_call6);
#line 32 ".\..\lib\ui\scene2dModel.sj"
    sjt_parent53 = &sjt_call6;
#line 0 ""
    sjf_mat4_transpose(sjt_parent53, &sjv_normalMat);
#line 33 ".\..\lib\ui\scene2dModel.sj"
    glUseProgram(_parent->shader.id);
#line 33
    glBindTexture(GL_TEXTURE_2D, _parent->frameBuffer.textureId);
#line 33
    glUniformMatrix4fv(glGetUniformLocation(_parent->shader.id, "viewModel" ), 1, 0, (GLfloat*)&sjv_viewWorld);
#line 33
    glUniformMatrix4fv(glGetUniformLocation(_parent->shader.id, "normalMat" ), 1, 0, (GLfloat*)&sjv_normalMat);
#line 33
    glUniformMatrix4fv(glGetUniformLocation(_parent->shader.id, "projection" ), 1, 0, (GLfloat*)&scene3d->projection);
#line 33
    glUniform3fv(glGetUniformLocation(_parent->shader.id, "lightPos" ), 1, (GLfloat*)&scene3d->lightPos);
#line 33
    glUniform3fv(glGetUniformLocation(_parent->shader.id, "diffuseColor" ), 1, (GLfloat*)&scene3d->diffuseColor);
#line 33
    glUniform3fv(glGetUniformLocation(_parent->shader.id, "specColor" ), 1, (GLfloat*)&scene3d->specColor);
#line 14
    sjt_dot1216 = _parent;
#line 88 ".\..\lib\ui\vertexBuffer.sj"
    sjt_parent57 = &(sjt_dot1216)->vertexBuffer;
#line 0 ""
    sjf_vertexBuffer_vertex_location_texture_normal_render(sjt_parent57);

    sjf_mat4_destroy(&sjt_call6);
    sjf_mat4_destroy(&sjv_normalMat);
    sjf_mat4_destroy(&sjv_viewWorld);
}

void sjf_scene2dModel_setWorld(sjs_scene2dModel* _parent, sjs_mat4* world) {
    sjs_scene2dModel* sjt_dot200;

#line 9 ".\..\lib\ui\scene2dModel.sj"
    sjt_dot200 = _parent;
#line 9
    sjf_mat4_copy(&sjt_dot200->_world, world);
}

void sjf_scene2d_clear(sjs_scene2d* _parent) {
#line 8 ".\..\lib\ui\scene2d.sj"
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
#line 8
    glEnable( GL_TEXTURE_2D );
#line 8
    glDisable( GL_DEPTH_TEST );
#line 0 ""
    sjf_scene2d_updateViewport(_parent);
}

void sjf_scene2d_copy(sjs_scene2d* _this, sjs_scene2d* _from) {
#line 1 ".\..\lib\ui\scene2d.sj"
    sjf_size_copy(&_this->_size, &_from->_size);
#line 1
    sjf_mat4_copy(&_this->model, &_from->model);
#line 1
    sjf_mat4_copy(&_this->view, &_from->view);
#line 1
    sjf_mat4_copy(&_this->projection, &_from->projection);
}

void sjf_scene2d_destroy(sjs_scene2d* _this) {
}

void sjf_scene2d_heap(sjs_scene2d_heap* _this) {
}

void sjf_scene2d_setSize(sjs_scene2d* _parent, sjs_size* size) {
    bool result7;
    sjs_scene2d* sjt_dot205;
    sjs_size* sjt_functionParam66;
    bool sjt_ifElse12;
    bool sjt_not3;
    sjs_size* sjt_parent46;

#line 27 ".\..\lib\ui\scene2d.sj"
    sjt_dot205 = _parent;
#line 16 ".\..\lib\ui\size.sj"
    sjt_parent46 = &(sjt_dot205)->_size;
#line 27 ".\..\lib\ui\scene2d.sj"
    sjt_functionParam66 = size;
#line 0 ""
    sjf_size_isEqual(sjt_parent46, sjt_functionParam66, &sjt_not3);
#line 28 ".\..\lib\ui\scene2d.sj"
    result7 = !sjt_not3;
#line 28
    sjt_ifElse12 = result7;
    if (sjt_ifElse12) {
        float result10;
        float result11;
        int32_t sjt_cast12;
        int32_t sjt_cast13;
        sjs_scene2d* sjt_dot206;
        sjs_scene2d* sjt_dot207;
        sjs_size* sjt_dot208;
        sjs_scene2d* sjt_dot209;
        sjs_size* sjt_dot210;
        sjs_scene2d* sjt_dot211;
        sjs_scene2d* sjt_dot212;
        sjs_scene2d* sjt_dot213;
        float sjt_functionParam67;
        float sjt_functionParam68;
        float sjt_functionParam69;
        float sjt_functionParam70;
        float sjt_functionParam71;
        float sjt_functionParam72;
        float sjt_functionParam73;
        float sjt_functionParam74;
        float sjt_functionParam75;
        int32_t sjt_math499;
        int32_t sjt_math500;
        float sjt_negate7;
        float sjt_negate8;

#line 27 ".\..\lib\ui\scene2d.sj"
        sjt_dot206 = _parent;
#line 27
        sjf_size_copy(&sjt_dot206->_size, size);
#line 27
        sjt_dot207 = _parent;
#line 30
        sjt_functionParam67 = 0.0f;
#line 27
        sjt_dot209 = _parent;
#line 1 ".\..\lib\ui\size.sj"
        sjt_dot208 = &(sjt_dot209)->_size;
#line 30 ".\..\lib\ui\scene2d.sj"
        sjt_cast12 = (sjt_dot208)->w;
#line 30
        sjt_functionParam68 = (float)sjt_cast12;
#line 30
        sjt_math499 = 0;
#line 27
        sjt_dot211 = _parent;
#line 1 ".\..\lib\ui\size.sj"
        sjt_dot210 = &(sjt_dot211)->_size;
#line 30 ".\..\lib\ui\scene2d.sj"
        sjt_math500 = (sjt_dot210)->h;
#line 30
        sjt_cast13 = sjt_math499 - sjt_math500;
#line 30
        sjt_functionParam69 = (float)sjt_cast13;
#line 30
        sjt_functionParam70 = 0.0f;
#line 30
        sjt_negate7 = 1.0f;
#line 30
        result10 = -sjt_negate7;
#line 30
        sjt_functionParam71 = result10;
#line 30
        sjt_functionParam72 = 1.0f;
#line 0 ""
        sjf_mat4_orthographic(sjt_functionParam67, sjt_functionParam68, sjt_functionParam69, sjt_functionParam70, sjt_functionParam71, sjt_functionParam72, &sjt_dot207->projection);
#line 27 ".\..\lib\ui\scene2d.sj"
        sjt_dot212 = _parent;
#line 31
        sjt_functionParam73 = 1.0f;
#line 31
        sjt_negate8 = 1.0f;
#line 31
        result11 = -sjt_negate8;
#line 31
        sjt_functionParam74 = result11;
#line 31
        sjt_functionParam75 = 1.0f;
#line 0 ""
        sjf_mat4_scale(sjt_functionParam73, sjt_functionParam74, sjt_functionParam75, &sjt_dot212->model);
#line 27 ".\..\lib\ui\scene2d.sj"
        sjt_dot213 = _parent;
#line 0 ""
        sjf_mat4_identity(&sjt_dot213->view);
    }
}

void sjf_scene2d_updateViewport(sjs_scene2d* _parent) {
#line 18 ".\..\lib\ui\scene2d.sj"
    glViewport(0, 0, _parent->_size.w, _parent->_size.h);
}

void sjf_scene3dElement(sjs_scene3dElement* _this) {
    float result3;
    sjs_vec3 sjt_call2;
    sjs_vec3* sjt_functionParam19;
    int32_t sjt_functionParam20;
    float sjt_negate2;
    sjs_property_vec3_heap* sjt_parent15;

#line 20 ".\..\lib\ui\property.sj"
    sjt_parent15 = _this->camera;
#line 0 ""
    sjt_parent15->_refCount++;
#line 89 ".\..\lib\ui\scene3dElement.sj"
    sjt_call2.x = 0.0f;
#line 89
    sjt_call2.y = 0.0f;
#line 89
    sjt_negate2 = 10.0f;
#line 89
    result3 = -sjt_negate2;
#line 89
    sjt_call2.z = result3;
#line 0 ""
    sjf_vec3(&sjt_call2);
#line 89 ".\..\lib\ui\scene3dElement.sj"
    sjt_functionParam19 = &sjt_call2;
#line 89
    sjt_functionParam20 = 10000;
#line 0 ""
    sjf_property_vec3_animate((sjs_property_vec3*)(((char*)sjt_parent15) + sizeof(intptr_t)), sjt_functionParam19, sjt_functionParam20);

    sjt_parent15->_refCount--;
    if (sjt_parent15->_refCount <= 0) {
        sjf_property_vec3_destroy((sjs_property_vec3*)(((char*)sjt_parent15) + sizeof(intptr_t)));
    }
    sjf_vec3_destroy(&sjt_call2);
}

sjs_object* sjf_scene3dElement_asInterface(sjs_scene3dElement* _this, int typeId) {
    switch (typeId) {
        case sji_element_typeId:  {
            return (sjs_object*)sjf_scene3dElement_as_sji_element(_this);
        }
    }

    return 0;
}

sji_element* sjf_scene3dElement_as_sji_element(sjs_scene3dElement* _this) {
    sji_element* _interface;
    _interface = (sji_element*)malloc(sizeof(sji_element));
    _interface->_refCount = 1;
    _interface->_parent = (sjs_object*)_this;
    _interface->_parent->_refCount++;
    _interface->destroy = (void(*)(void*))sjf_scene3dElement_destroy;
    _interface->asInterface = (sjs_object*(*)(sjs_object*,int))sjf_scene3dElement_asInterface;
    _interface->getSize = (void(*)(void*,sjs_size*, sjs_size*))sjf_scene3dElement_getSize;
    _interface->getSize_heap = (void(*)(void*,sjs_size*, sjs_size_heap**))sjf_scene3dElement_getSize_heap;
    _interface->getRect = (void(*)(void*, sjs_rect**))sjf_scene3dElement_getRect;
    _interface->setRect = (void(*)(void*,sjs_rect*))sjf_scene3dElement_setRect;
    _interface->render = (void(*)(void*,sjs_scene2d*))sjf_scene3dElement_render;
    _interface->getChildren = (void(*)(void*, sjs_array_heap_element**))sjf_scene3dElement_getChildren;
    _interface->fireMouseEvent = (void(*)(void*,sjs_point*,int32_t))sjf_scene3dElement_fireMouseEvent;

    return _interface;
}

void sjf_scene3dElement_copy(sjs_scene3dElement* _this, sjs_scene3dElement* _from) {
#line 1 ".\..\lib\ui\scene3dElement.sj"
    sjf_array_heap_model_copy(&_this->children, &_from->children);
#line 0 ""
    _this->camera = (sjs_property_vec3_heap*)malloc(sizeof(sjs_property_vec3_heap));
    _this->camera->_refCount = 1;
#line 1 ".\..\lib\ui\scene3dElement.sj"
    sjf_property_vec3_copy((sjs_property_vec3*)(((char*)_this->camera) + sizeof(intptr_t)), (sjs_property_vec3*)(((char*)_from->camera) + sizeof(intptr_t)));
#line 1
    sjf_vec3_copy(&_this->lookAt, &_from->lookAt);
#line 1
    sjf_vec3_copy(&_this->up, &_from->up);
#line 1
    _this->fieldOfView = _from->fieldOfView;
#line 1
    _this->zNear = _from->zNear;
#line 1
    _this->zFar = _from->zFar;
#line 1
    sjf_vec3_copy(&_this->lightPos, &_from->lightPos);
#line 1
    sjf_color_copy(&_this->diffuseColor, &_from->diffuseColor);
#line 1
    sjf_color_copy(&_this->specColor, &_from->specColor);
#line 1
    sjf_mat4_copy(&_this->projection, &_from->projection);
#line 1
    sjf_mat4_copy(&_this->view, &_from->view);
#line 1
    sjf_rect_copy(&_this->_rect, &_from->_rect);
#line 1
    _this->_angle = _from->_angle;
#line 1
    _this->_isUp = _from->_isUp;
#line 1
    sjf_vertexBuffer_vertex_location_texture_normal_copy(&_this->_cube, &_from->_cube);
}

void sjf_scene3dElement_destroy(sjs_scene3dElement* _this) {
    _this->camera->_refCount--;
    if (_this->camera->_refCount <= 0) {
        sjf_property_vec3_destroy((sjs_property_vec3*)(((char*)_this->camera) + sizeof(intptr_t)));
    }
}

void sjf_scene3dElement_fireMouseEvent(sjs_scene3dElement* _parent, sjs_point* point, int32_t eventId) {
    int32_t i;
    sjs_array_heap_model* sjt_dot192;
    sjs_scene3dElement* sjt_dot193;
    int32_t sjt_forEnd7;
    int32_t sjt_forStart7;

#line 76 ".\..\lib\ui\scene3dElement.sj"
    sjt_forStart7 = 0;
#line 76
    i = sjt_forStart7;
#line 75
    sjt_dot193 = _parent;
#line 1 ".\..\lib\common\array.sj"
    sjt_dot192 = &(sjt_dot193)->children;
#line 76 ".\..\lib\ui\scene3dElement.sj"
    sjt_forEnd7 = (sjt_dot192)->size;
    while (i < sjt_forEnd7) {
        sjs_scene3dElement* sjt_dot194;
        int32_t sjt_functionParam60;
        sjs_scene3dElement* sjt_interfaceParam7;
        sjs_point* sjt_interfaceParam8;
        int32_t sjt_interfaceParam9;
        sjs_array_heap_model* sjt_parent40;
        sji_scene3dElement_model* sjt_parent41;
        sji_scene3dElement_model* sjv_child;

#line 75 ".\..\lib\ui\scene3dElement.sj"
        sjt_dot194 = _parent;
#line 6 ".\..\lib\common\array.sj"
        sjt_parent40 = &(sjt_dot194)->children;
#line 76 ".\..\lib\ui\scene3dElement.sj"
        sjt_functionParam60 = i;
#line 0 ""
        sjf_array_heap_model_getAt_heap(sjt_parent40, sjt_functionParam60, &sjv_child);
#line 4 ".\..\lib\ui\model.sj"
        sjt_parent41 = sjv_child;
#line 78 ".\..\lib\ui\scene3dElement.sj"
        sjt_interfaceParam7 = _parent;
#line 75
        sjt_interfaceParam8 = point;
#line 75
        sjt_interfaceParam9 = eventId;
#line 78
        sjt_parent41->fireMouseEvent((void*)(((char*)sjt_parent41->_parent) + sizeof(intptr_t)), sjt_interfaceParam7, sjt_interfaceParam8, sjt_interfaceParam9);
#line 76
        i++;

        sjv_child->_refCount--;
        if (sjv_child->_refCount <= 0) {
            sji_scene3dElement_model_destroy(sjv_child);
        }
    }
}

void sjf_scene3dElement_getChildren(sjs_scene3dElement* _parent, sjs_array_heap_element** _return) {
#line 72 ".\..\lib\ui\scene3dElement.sj"
    (*_return) = 0;
}

void sjf_scene3dElement_getRect(sjs_scene3dElement* _parent, sjs_rect** _return) {
    sjs_scene3dElement* sjt_dot67;

#line 23 ".\..\lib\ui\scene3dElement.sj"
    sjt_dot67 = _parent;
#line 23
    (*_return) = &(sjt_dot67)->_rect;
}

void sjf_scene3dElement_getSize(sjs_scene3dElement* _parent, sjs_size* maxSize, sjs_size* _return) {
    sjs_size* sjt_dot63;
    sjs_size* sjt_dot64;

#line 19 ".\..\lib\ui\scene3dElement.sj"
    sjt_dot63 = maxSize;
#line 20
    _return->w = (sjt_dot63)->w;
#line 19
    sjt_dot64 = maxSize;
#line 20
    _return->h = (sjt_dot64)->h;
#line 0 ""
    sjf_size(_return);
}

void sjf_scene3dElement_getSize_heap(sjs_scene3dElement* _parent, sjs_size* maxSize, sjs_size_heap** _return) {
    sjs_size* sjt_dot65;
    sjs_size* sjt_dot66;

    (*_return) = (sjs_size_heap*)malloc(sizeof(sjs_size_heap));
    (*_return)->_refCount = 1;
#line 19 ".\..\lib\ui\scene3dElement.sj"
    sjt_dot65 = maxSize;
#line 20
    (*_return)->w = (sjt_dot65)->w;
#line 19
    sjt_dot66 = maxSize;
#line 20
    (*_return)->h = (sjt_dot66)->h;
#line 0 ""
    sjf_size_heap((*_return));
}

void sjf_scene3dElement_heap(sjs_scene3dElement_heap* _this) {
    float result6;
    sjs_vec3 sjt_call5;
    sjs_vec3* sjt_functionParam61;
    int32_t sjt_functionParam62;
    float sjt_negate4;
    sjs_property_vec3_heap* sjt_parent42;

#line 20 ".\..\lib\ui\property.sj"
    sjt_parent42 = _this->camera;
#line 0 ""
    sjt_parent42->_refCount++;
#line 89 ".\..\lib\ui\scene3dElement.sj"
    sjt_call5.x = 0.0f;
#line 89
    sjt_call5.y = 0.0f;
#line 89
    sjt_negate4 = 10.0f;
#line 89
    result6 = -sjt_negate4;
#line 89
    sjt_call5.z = result6;
#line 0 ""
    sjf_vec3(&sjt_call5);
#line 89 ".\..\lib\ui\scene3dElement.sj"
    sjt_functionParam61 = &sjt_call5;
#line 89
    sjt_functionParam62 = 10000;
#line 0 ""
    sjf_property_vec3_animate((sjs_property_vec3*)(((char*)sjt_parent42) + sizeof(intptr_t)), sjt_functionParam61, sjt_functionParam62);

    sjt_parent42->_refCount--;
    if (sjt_parent42->_refCount <= 0) {
        sjf_property_vec3_destroy((sjs_property_vec3*)(((char*)sjt_parent42) + sizeof(intptr_t)));
    }
    sjf_vec3_destroy(&sjt_call5);
}

sjs_object* sjf_scene3dElement_heap_asInterface(sjs_scene3dElement_heap* _this, int typeId) {
    switch (typeId) {
        case sji_element_typeId:  {
            return (sjs_object*)sjf_scene3dElement_heap_as_sji_element(_this);
        }
    }

    return 0;
}

sji_element* sjf_scene3dElement_heap_as_sji_element(sjs_scene3dElement_heap* _this) {
    sji_element* _interface;
    _interface = (sji_element*)malloc(sizeof(sji_element));
    _interface->_refCount = 1;
    _interface->_parent = (sjs_object*)_this;
    _interface->_parent->_refCount++;
    _interface->destroy = (void(*)(void*))sjf_scene3dElement_destroy;
    _interface->asInterface = (sjs_object*(*)(sjs_object*,int))sjf_scene3dElement_heap_asInterface;
    _interface->getSize = (void(*)(void*,sjs_size*, sjs_size*))sjf_scene3dElement_getSize;
    _interface->getSize_heap = (void(*)(void*,sjs_size*, sjs_size_heap**))sjf_scene3dElement_getSize_heap;
    _interface->getRect = (void(*)(void*, sjs_rect**))sjf_scene3dElement_getRect;
    _interface->setRect = (void(*)(void*,sjs_rect*))sjf_scene3dElement_setRect;
    _interface->render = (void(*)(void*,sjs_scene2d*))sjf_scene3dElement_render;
    _interface->getChildren = (void(*)(void*, sjs_array_heap_element**))sjf_scene3dElement_getChildren;
    _interface->fireMouseEvent = (void(*)(void*,sjs_point*,int32_t))sjf_scene3dElement_fireMouseEvent;

    return _interface;
}

void sjf_scene3dElement_render(sjs_scene3dElement* _parent, sjs_scene2d* scene) {
    int32_t i;
    sjs_scene3dElement* sjt_dot171;
    sjs_scene3dElement* sjt_dot176;
    sjs_scene3dElement* sjt_dot185;
    sjs_array_heap_model* sjt_dot186;
    sjs_scene3dElement* sjt_dot187;
    sjs_array_heap_model* sjt_dot189;
    sjs_scene3dElement* sjt_dot190;
    int32_t sjt_forEnd5;
    int32_t sjt_forEnd6;
    int32_t sjt_forStart5;
    int32_t sjt_forStart6;
    float sjt_functionParam54;
    float sjt_functionParam55;
    float sjt_functionParam56;
    float sjt_functionParam57;
    bool sjt_ifElse7;
    bool sjt_ifElse9;
    sjs_property_vec3* sjt_parent34;
    sjs_mat4 sjv_world;

#line 35 ".\..\lib\ui\scene3dElement.sj"
    sjt_dot171 = _parent;
#line 31 ".\..\lib\ui\property.sj"
    sjt_parent34 = (sjs_property_vec3*)(((char*)(sjt_dot171)->camera) + sizeof(intptr_t));
#line 0 ""
    sjf_property_vec3_getIsDirty(sjt_parent34, &sjt_ifElse7);
    if (sjt_ifElse7) {
        sjs_scene3dElement* sjt_dot172;
        sjs_scene3dElement* sjt_dot173;
        sjs_scene3dElement* sjt_dot174;
        sjs_scene3dElement* sjt_dot175;
        sjs_vec3* sjt_functionParam45;
        sjs_vec3* sjt_functionParam46;
        sjs_vec3* sjt_functionParam47;
        sjs_property_vec3* sjt_parent35;

#line 35 ".\..\lib\ui\scene3dElement.sj"
        sjt_dot172 = _parent;
#line 35
        sjt_dot173 = _parent;
#line 6 ".\..\lib\ui\property.sj"
        sjt_parent35 = (sjs_property_vec3*)(((char*)(sjt_dot173)->camera) + sizeof(intptr_t));
#line 0 ""
        sjf_property_vec3_get(sjt_parent35, &sjt_functionParam45);
#line 35 ".\..\lib\ui\scene3dElement.sj"
        sjt_dot174 = _parent;
#line 37
        sjt_functionParam46 = &(sjt_dot174)->lookAt;
#line 35
        sjt_dot175 = _parent;
#line 37
        sjt_functionParam47 = &(sjt_dot175)->up;
#line 0 ""
        sjf_mat4_lookAtLH(sjt_functionParam45, sjt_functionParam46, sjt_functionParam47, &sjt_dot172->view);
    }

#line 35 ".\..\lib\ui\scene3dElement.sj"
    sjt_dot176 = _parent;
#line 40
    sjt_ifElse9 = (sjt_dot176)->_isUp;
    if (sjt_ifElse9) {
        float sjt_compare25;
        float sjt_compare26;
        sjs_scene3dElement* sjt_dot177;
        sjs_scene3dElement* sjt_dot178;
        sjs_scene3dElement* sjt_dot179;
        bool sjt_ifElse10;
        float sjt_math207;
        float sjt_math208;

#line 35 ".\..\lib\ui\scene3dElement.sj"
        sjt_dot177 = _parent;
#line 35
        sjt_dot178 = _parent;
#line 41
        sjt_math207 = (sjt_dot178)->_angle;
#line 41
        sjt_math208 = 0.2f;
#line 41
        sjt_dot177->_angle = sjt_math207 + sjt_math208;
#line 35
        sjt_dot179 = _parent;
#line 42
        sjt_compare25 = (sjt_dot179)->_angle;
#line 42
        sjt_compare26 = 180.0f;
#line 42
        sjt_ifElse10 = sjt_compare25 >= sjt_compare26;
        if (sjt_ifElse10) {
            sjs_scene3dElement* sjt_dot180;

#line 35 ".\..\lib\ui\scene3dElement.sj"
            sjt_dot180 = _parent;
#line 43
            sjt_dot180->_isUp = false;
        }
    } else {
        float result5;
        float sjt_compare27;
        float sjt_compare28;
        sjs_scene3dElement* sjt_dot181;
        sjs_scene3dElement* sjt_dot182;
        sjs_scene3dElement* sjt_dot183;
        bool sjt_ifElse11;
        float sjt_math209;
        float sjt_math210;
        float sjt_negate3;

#line 35 ".\..\lib\ui\scene3dElement.sj"
        sjt_dot181 = _parent;
#line 35
        sjt_dot182 = _parent;
#line 46
        sjt_math209 = (sjt_dot182)->_angle;
#line 46
        sjt_math210 = 0.2f;
#line 46
        sjt_dot181->_angle = sjt_math209 - sjt_math210;
#line 35
        sjt_dot183 = _parent;
#line 47
        sjt_compare27 = (sjt_dot183)->_angle;
#line 47
        sjt_negate3 = 180.0f;
#line 47
        result5 = -sjt_negate3;
#line 47
        sjt_compare28 = result5;
#line 47
        sjt_ifElse11 = sjt_compare27 <= sjt_compare28;
        if (sjt_ifElse11) {
            sjs_scene3dElement* sjt_dot184;

#line 35 ".\..\lib\ui\scene3dElement.sj"
            sjt_dot184 = _parent;
#line 48
            sjt_dot184->_isUp = true;
        }
    }

#line 35
    sjt_dot185 = _parent;
#line 51
    sjt_functionParam54 = (sjt_dot185)->_angle;
#line 51
    sjt_functionParam55 = 0.0f;
#line 51
    sjt_functionParam56 = 1.0f;
#line 51
    sjt_functionParam57 = 0.0f;
#line 0 ""
    sjf_mat4_rotation(sjt_functionParam54, sjt_functionParam55, sjt_functionParam56, sjt_functionParam57, &sjv_world);
#line 52 ".\..\lib\ui\scene3dElement.sj"
    sjt_forStart5 = 0;
#line 52
    i = sjt_forStart5;
#line 35
    sjt_dot187 = _parent;
#line 1 ".\..\lib\common\array.sj"
    sjt_dot186 = &(sjt_dot187)->children;
#line 52 ".\..\lib\ui\scene3dElement.sj"
    sjt_forEnd5 = (sjt_dot186)->size;
    while (i < sjt_forEnd5) {
        sjs_scene3dElement* sjt_dot188;
        int32_t sjt_functionParam58;
        sjs_mat4* sjt_interfaceParam5;
        sjs_array_heap_model* sjt_parent36;
        sji_scene3dElement_model* sjt_parent37;
        sji_scene3dElement_model* sjv_child;

#line 35 ".\..\lib\ui\scene3dElement.sj"
        sjt_dot188 = _parent;
#line 6 ".\..\lib\common\array.sj"
        sjt_parent36 = &(sjt_dot188)->children;
#line 52 ".\..\lib\ui\scene3dElement.sj"
        sjt_functionParam58 = i;
#line 0 ""
        sjf_array_heap_model_getAt_heap(sjt_parent36, sjt_functionParam58, &sjv_child);
#line 2 ".\..\lib\ui\model.sj"
        sjt_parent37 = sjv_child;
#line 2
        sjt_interfaceParam5 = &sjv_world;
#line 54 ".\..\lib\ui\scene3dElement.sj"
        sjt_parent37->setWorld((void*)(((char*)sjt_parent37->_parent) + sizeof(intptr_t)), sjt_interfaceParam5);
#line 52
        i++;

        sjv_child->_refCount--;
        if (sjv_child->_refCount <= 0) {
            sji_scene3dElement_model_destroy(sjv_child);
        }
    }

#line 57
    glEnable( GL_DEPTH_TEST );
#line 61
    sjt_forStart6 = 0;
#line 61
    i = sjt_forStart6;
#line 35
    sjt_dot190 = _parent;
#line 1 ".\..\lib\common\array.sj"
    sjt_dot189 = &(sjt_dot190)->children;
#line 61 ".\..\lib\ui\scene3dElement.sj"
    sjt_forEnd6 = (sjt_dot189)->size;
    while (i < sjt_forEnd6) {
        sjs_scene3dElement* sjt_dot191;
        int32_t sjt_functionParam59;
        sjs_scene3dElement* sjt_interfaceParam6;
        sjs_array_heap_model* sjt_parent38;
        sji_scene3dElement_model* sjt_parent39;
        sji_scene3dElement_model* sjv_child2;

#line 35 ".\..\lib\ui\scene3dElement.sj"
        sjt_dot191 = _parent;
#line 6 ".\..\lib\common\array.sj"
        sjt_parent38 = &(sjt_dot191)->children;
#line 61 ".\..\lib\ui\scene3dElement.sj"
        sjt_functionParam59 = i;
#line 0 ""
        sjf_array_heap_model_getAt_heap(sjt_parent38, sjt_functionParam59, &sjv_child2);
#line 3 ".\..\lib\ui\model.sj"
        sjt_parent39 = sjv_child2;
#line 63 ".\..\lib\ui\scene3dElement.sj"
        sjt_interfaceParam6 = _parent;
#line 63
        sjt_parent39->render((void*)(((char*)sjt_parent39->_parent) + sizeof(intptr_t)), sjt_interfaceParam6);
#line 61
        i++;

        sjv_child2->_refCount--;
        if (sjv_child2->_refCount <= 0) {
            sji_scene3dElement_model_destroy(sjv_child2);
        }
    }

#line 66
    glDisable( GL_DEPTH_TEST );

    sjf_mat4_destroy(&sjv_world);
}

void sjf_scene3dElement_setRect(sjs_scene3dElement* _parent, sjs_rect* rect_) {
    bool result4;
    sjs_scene3dElement* sjt_dot76;
    sjs_rect* sjt_functionParam21;
    bool sjt_ifElse6;
    bool sjt_not2;
    sjs_rect* sjt_parent16;

#line 25 ".\..\lib\ui\scene3dElement.sj"
    sjt_dot76 = _parent;
#line 15 ".\..\lib\ui\rect.sj"
    sjt_parent16 = &(sjt_dot76)->_rect;
#line 25 ".\..\lib\ui\scene3dElement.sj"
    sjt_functionParam21 = rect_;
#line 0 ""
    sjf_rect_isEqual(sjt_parent16, sjt_functionParam21, &sjt_not2);
#line 26 ".\..\lib\ui\scene3dElement.sj"
    result4 = !sjt_not2;
#line 26
    sjt_ifElse6 = result4;
    if (sjt_ifElse6) {
        int32_t sjt_cast8;
        int32_t sjt_cast9;
        sjs_scene3dElement* sjt_dot166;
        sjs_scene3dElement* sjt_dot167;
        sjs_scene3dElement* sjt_dot168;
        sjs_scene3dElement* sjt_dot77;
        sjs_scene3dElement* sjt_dot78;
        sjs_scene3dElement* sjt_dot79;
        sjs_rect* sjt_dot80;
        sjs_scene3dElement* sjt_dot81;
        sjs_rect* sjt_dot82;
        sjs_scene3dElement* sjt_dot83;
        sjs_scene3dElement* sjt_dot84;
        sjs_scene3dElement* sjt_dot85;
        sjs_scene3dElement* sjt_dot86;
        float sjt_functionParam24;
        float sjt_functionParam25;
        float sjt_functionParam26;
        float sjt_functionParam27;
        sjs_vec3* sjt_functionParam42;
        sjs_vec3* sjt_functionParam43;
        sjs_vec3* sjt_functionParam44;
        float sjt_math103;
        float sjt_math104;
        sjs_property_vec3* sjt_parent33;

#line 25 ".\..\lib\ui\scene3dElement.sj"
        sjt_dot77 = _parent;
#line 25
        sjf_rect_copy(&sjt_dot77->_rect, rect_);
#line 25
        sjt_dot78 = _parent;
#line 25
        sjt_dot79 = _parent;
#line 28
        sjt_functionParam24 = (sjt_dot79)->fieldOfView;
#line 25
        sjt_dot81 = _parent;
#line 1 ".\..\lib\ui\rect.sj"
        sjt_dot80 = &(sjt_dot81)->_rect;
#line 28 ".\..\lib\ui\scene3dElement.sj"
        sjt_cast8 = (sjt_dot80)->h;
#line 28
        sjt_math103 = (float)sjt_cast8;
#line 25
        sjt_dot83 = _parent;
#line 1 ".\..\lib\ui\rect.sj"
        sjt_dot82 = &(sjt_dot83)->_rect;
#line 28 ".\..\lib\ui\scene3dElement.sj"
        sjt_cast9 = (sjt_dot82)->w;
#line 28
        sjt_math104 = (float)sjt_cast9;
#line 28
        sjt_functionParam25 = sjt_math103 / sjt_math104;
#line 25
        sjt_dot84 = _parent;
#line 28
        sjt_functionParam26 = (sjt_dot84)->zNear;
#line 25
        sjt_dot85 = _parent;
#line 28
        sjt_functionParam27 = (sjt_dot85)->zFar;
#line 0 ""
        sjf_mat4_perspective(sjt_functionParam24, sjt_functionParam25, sjt_functionParam26, sjt_functionParam27, &sjt_dot78->projection);
#line 25 ".\..\lib\ui\scene3dElement.sj"
        sjt_dot86 = _parent;
#line 25
        sjt_dot166 = _parent;
#line 6 ".\..\lib\ui\property.sj"
        sjt_parent33 = (sjs_property_vec3*)(((char*)(sjt_dot166)->camera) + sizeof(intptr_t));
#line 0 ""
        sjf_property_vec3_get(sjt_parent33, &sjt_functionParam42);
#line 25 ".\..\lib\ui\scene3dElement.sj"
        sjt_dot167 = _parent;
#line 29
        sjt_functionParam43 = &(sjt_dot167)->lookAt;
#line 25
        sjt_dot168 = _parent;
#line 29
        sjt_functionParam44 = &(sjt_dot168)->up;
#line 0 ""
        sjf_mat4_lookAtLH(sjt_functionParam42, sjt_functionParam43, sjt_functionParam44, &sjt_dot86->view);
    }
}

void sjf_scene3dElement_updateViewport(sjs_scene3dElement* _parent) {
#line 83 ".\..\lib\ui\scene3dElement.sj"
    glViewport(_parent->_rect.x, _parent->_rect.y, _parent->_rect.w, _parent->_rect.h);
#line 83
    glEnable( GL_DEPTH_TEST );
}

void sjf_shader(sjs_shader* _this) {
#line 16 ".\..\lib\ui\shader.sj"
    _this->id = shader_load((char*)_this->vertex.data.data, (char*)_this->pixel.data.data);
}

void sjf_shader_copy(sjs_shader* _this, sjs_shader* _from) {
#line 9 ".\..\lib\ui\shader.sj"
    sjf_string_copy(&_this->vertex, &_from->vertex);
#line 9
    sjf_string_copy(&_this->pixel, &_from->pixel);
#line 21
    _this->id = _from->id;
#line 21
    _retainGLid(_this->id);
}

void sjf_shader_destroy(sjs_shader* _this) {
#line 26 ".\..\lib\ui\shader.sj"
    if (_releaseGLid(_this->id)) {
#line 26
        glDeleteShader(_this->id);
#line 26
    }
}

void sjf_shader_heap(sjs_shader_heap* _this) {
#line 16 ".\..\lib\ui\shader.sj"
    _this->id = shader_load((char*)_this->vertex.data.data, (char*)_this->pixel.data.data);
}

void sjf_size(sjs_size* _this) {
}

void sjf_size_copy(sjs_size* _this, sjs_size* _from) {
#line 1 ".\..\lib\ui\size.sj"
    _this->w = _from->w;
#line 1
    _this->h = _from->h;
}

void sjf_size_destroy(sjs_size* _this) {
}

void sjf_size_heap(sjs_size_heap* _this) {
}

void sjf_size_isEqual(sjs_size* _parent, sjs_size* size, bool* _return) {
    bool sjt_and11;
    bool sjt_and12;
    int32_t sjt_compare29;
    int32_t sjt_compare30;
    int32_t sjt_compare31;
    int32_t sjt_compare32;
    sjs_size* sjt_dot201;
    sjs_size* sjt_dot202;
    sjs_size* sjt_dot203;
    sjs_size* sjt_dot204;

#line 16 ".\..\lib\ui\size.sj"
    sjt_dot201 = _parent;
#line 17
    sjt_compare29 = (sjt_dot201)->w;
#line 16
    sjt_dot202 = size;
#line 17
    sjt_compare30 = (sjt_dot202)->w;
#line 17
    sjt_and11 = sjt_compare29 == sjt_compare30;
#line 16
    sjt_dot203 = _parent;
#line 17
    sjt_compare31 = (sjt_dot203)->h;
#line 16
    sjt_dot204 = size;
#line 17
    sjt_compare32 = (sjt_dot204)->h;
#line 17
    sjt_and12 = sjt_compare31 == sjt_compare32;
#line 17
    (*_return) = sjt_and11 && sjt_and12;
}

void sjf_sphereVertexBuffer(int32_t slices, int32_t wedges, sjs_vec3* origin, sjs_vec3* radius, sjs_vertexBuffer_vertex_location_texture_normal* _return) {
    int32_t sjt_cast22;
    int32_t sjt_cast31;
    int32_t sjt_forEnd13;
    int32_t sjt_forEnd15;
    int32_t sjt_forStart13;
    int32_t sjt_forStart15;
    int32_t sjt_math2413;
    int32_t sjt_math2414;
    int32_t sjt_math2415;
    int32_t sjt_math2416;
    int32_t sjt_math2417;
    int32_t sjt_math2418;
    int32_t sjt_math2419;
    int32_t sjt_math2420;
    int32_t sjt_math2465;
    int32_t sjt_math2466;
    int32_t sjt_math2467;
    int32_t sjt_math2468;
    sjs_array_i32 sjv_indices;
    sjs_array_vertex_location_texture_normal sjv_vertices;
    int32_t slice;

#line 91 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_math2415 = slices;
#line 97
    sjt_math2416 = 1;
#line 97
    sjt_math2413 = sjt_math2415 + sjt_math2416;
#line 91
    sjt_math2417 = wedges;
#line 97
    sjt_math2418 = 1;
#line 97
    sjt_math2414 = sjt_math2417 + sjt_math2418;
#line 97
    sjv_vertices.size = sjt_math2413 * sjt_math2414;
#line 3 ".\..\lib\common\array.sj"
    sjt_cast22 = 0;
#line 3
    sjv_vertices.data = (uintptr_t)sjt_cast22;
#line 4
    sjv_vertices._isGlobal = false;
#line 0 ""
    sjf_array_vertex_location_texture_normal(&sjv_vertices);
#line 98 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_forStart13 = 0;
#line 98
    slice = sjt_forStart13;
#line 91
    sjt_math2419 = slices;
#line 98
    sjt_math2420 = 1;
#line 98
    sjt_forEnd13 = sjt_math2419 + sjt_math2420;
    while (slice < sjt_forEnd13) {
        int32_t sjt_cast23;
        int32_t sjt_cast24;
        int32_t sjt_cast25;
        int32_t sjt_cast26;
        sjs_vec3* sjt_dot1320;
        int32_t sjt_forEnd14;
        int32_t sjt_forStart14;
        float sjt_functionParam113;
        float sjt_functionParam114;
        float sjt_math2421;
        float sjt_math2422;
        float sjt_math2423;
        float sjt_math2424;
        float sjt_math2425;
        float sjt_math2426;
        float sjt_math2427;
        float sjt_math2428;
        float sjt_math2429;
        float sjt_math2430;
        int32_t sjt_math2431;
        int32_t sjt_math2432;
        float sjv_r0;
        float sjv_theta;
        float sjv_tv;
        float sjv_y0;
        int32_t wedge;

#line 98 ".\..\lib\ui\vertexBufferBuilders.sj"
        sjt_cast23 = slice;
#line 99
        sjt_math2421 = (float)sjt_cast23;
#line 91
        sjt_cast24 = slices;
#line 99
        sjt_math2422 = (float)sjt_cast24;
#line 99
        sjv_tv = sjt_math2421 / sjt_math2422;
#line 100
        sjt_math2427 = sjv_f32_pi;
#line 98
        sjt_cast25 = slice;
#line 100
        sjt_math2428 = (float)sjt_cast25;
#line 100
        sjt_math2425 = sjt_math2427 * sjt_math2428;
#line 91
        sjt_cast26 = slices;
#line 100
        sjt_math2426 = (float)sjt_cast26;
#line 100
        sjt_math2423 = sjt_math2425 / sjt_math2426;
#line 100
        sjt_math2424 = sjv_f32_pi;
#line 100
        sjv_theta = sjt_math2423 + sjt_math2424;
#line 101
        sjt_functionParam113 = sjv_theta;
#line 0 ""
        sjf_f32_cos(sjt_functionParam113, &sjt_math2429);
#line 91 ".\..\lib\ui\vertexBufferBuilders.sj"
        sjt_dot1320 = radius;
#line 101
        sjt_math2430 = (sjt_dot1320)->y;
#line 101
        sjv_y0 = sjt_math2429 * sjt_math2430;
#line 102
        sjt_functionParam114 = sjv_theta;
#line 0 ""
        sjf_f32_sin(sjt_functionParam114, &sjv_r0);
#line 103 ".\..\lib\ui\vertexBufferBuilders.sj"
        sjt_forStart14 = 0;
#line 103
        wedge = sjt_forStart14;
#line 91
        sjt_math2431 = wedges;
#line 103
        sjt_math2432 = 1;
#line 103
        sjt_forEnd14 = sjt_math2431 + sjt_math2432;
        while (wedge < sjt_forEnd14) {
            int32_t sjt_cast27;
            int32_t sjt_cast28;
            int32_t sjt_cast29;
            int32_t sjt_cast30;
            sjs_vec3* sjt_dot1321;
            sjs_vec3* sjt_dot1322;
            sjs_vec3* sjt_dot1323;
            sjs_vec3* sjt_dot1324;
            sjs_vec3* sjt_dot1325;
            float sjt_functionParam115;
            float sjt_functionParam116;
            int32_t sjt_functionParam117;
            sjs_vertex_location_texture_normal* sjt_functionParam118;
            float sjt_math2433;
            float sjt_math2434;
            float sjt_math2435;
            float sjt_math2436;
            float sjt_math2437;
            float sjt_math2438;
            float sjt_math2439;
            float sjt_math2440;
            float sjt_math2441;
            float sjt_math2442;
            float sjt_math2443;
            float sjt_math2444;
            float sjt_math2445;
            float sjt_math2446;
            float sjt_math2447;
            float sjt_math2448;
            float sjt_math2449;
            float sjt_math2450;
            float sjt_math2451;
            float sjt_math2452;
            float sjt_math2453;
            float sjt_math2454;
            float sjt_math2455;
            float sjt_math2456;
            float sjt_math2457;
            float sjt_math2458;
            int32_t sjt_math2459;
            int32_t sjt_math2460;
            int32_t sjt_math2461;
            int32_t sjt_math2462;
            int32_t sjt_math2463;
            int32_t sjt_math2464;
            sjs_vec3* sjt_parent85;
            sjs_array_vertex_location_texture_normal* sjt_parent86;
            float sjv_angle;
            sjs_vec3 sjv_normal;
            float sjv_tu;
            sjs_vertex_location_texture_normal sjv_v;
            float sjv_x0;
            float sjv_z0;

#line 103 ".\..\lib\ui\vertexBufferBuilders.sj"
            sjt_cast27 = wedge;
#line 104
            sjt_math2433 = (float)sjt_cast27;
#line 91
            sjt_cast28 = wedges;
#line 104
            sjt_math2434 = (float)sjt_cast28;
#line 104
            sjv_tu = sjt_math2433 / sjt_math2434;
#line 105
            sjt_math2441 = 2.0f;
#line 105
            sjt_math2442 = sjv_f32_pi;
#line 105
            sjt_math2439 = sjt_math2441 * sjt_math2442;
#line 103
            sjt_cast29 = wedge;
#line 105
            sjt_math2440 = (float)sjt_cast29;
#line 105
            sjt_math2437 = sjt_math2439 * sjt_math2440;
#line 91
            sjt_cast30 = wedges;
#line 105
            sjt_math2438 = (float)sjt_cast30;
#line 105
            sjt_math2435 = sjt_math2437 / sjt_math2438;
#line 105
            sjt_math2443 = 1.5f;
#line 105
            sjt_math2444 = sjv_f32_pi;
#line 105
            sjt_math2436 = sjt_math2443 * sjt_math2444;
#line 105
            sjv_angle = sjt_math2435 - sjt_math2436;
#line 106
            sjt_functionParam115 = sjv_angle;
#line 0 ""
            sjf_f32_cos(sjt_functionParam115, &sjt_math2447);
#line 106 ".\..\lib\ui\vertexBufferBuilders.sj"
            sjt_math2448 = sjv_r0;
#line 106
            sjt_math2445 = sjt_math2447 * sjt_math2448;
#line 91
            sjt_dot1321 = radius;
#line 106
            sjt_math2446 = (sjt_dot1321)->x;
#line 106
            sjv_x0 = sjt_math2445 * sjt_math2446;
#line 107
            sjt_functionParam116 = sjv_angle;
#line 0 ""
            sjf_f32_sin(sjt_functionParam116, &sjt_math2451);
#line 107 ".\..\lib\ui\vertexBufferBuilders.sj"
            sjt_math2452 = sjv_r0;
#line 107
            sjt_math2449 = sjt_math2451 * sjt_math2452;
#line 91
            sjt_dot1322 = radius;
#line 107
            sjt_math2450 = (sjt_dot1322)->y;
#line 107
            sjv_z0 = sjt_math2449 * sjt_math2450;
#line 108
            sjv_normal.x = sjv_x0;
#line 108
            sjv_normal.y = sjv_y0;
#line 108
            sjv_normal.z = sjv_z0;
#line 0 ""
            sjf_vec3(&sjv_normal);
#line 111 ".\..\lib\ui\vertexBufferBuilders.sj"
            sjt_math2453 = sjv_x0;
#line 91
            sjt_dot1323 = origin;
#line 111
            sjt_math2454 = (sjt_dot1323)->x;
#line 111
            sjv_v.location.x = sjt_math2453 + sjt_math2454;
#line 111
            sjt_math2455 = sjv_y0;
#line 91
            sjt_dot1324 = origin;
#line 111
            sjt_math2456 = (sjt_dot1324)->y;
#line 111
            sjv_v.location.y = sjt_math2455 + sjt_math2456;
#line 111
            sjt_math2457 = sjv_z0;
#line 91
            sjt_dot1325 = origin;
#line 111
            sjt_math2458 = (sjt_dot1325)->z;
#line 111
            sjv_v.location.z = sjt_math2457 + sjt_math2458;
#line 0 ""
            sjf_vec3(&sjv_v.location);
#line 112 ".\..\lib\ui\vertexBufferBuilders.sj"
            sjv_v.texture.x = sjv_tu;
#line 112
            sjv_v.texture.y = sjv_tv;
#line 0 ""
            sjf_vec2(&sjv_v.texture);
#line 29 ".\..\lib\ui\vec3.sj"
            sjt_parent85 = &sjv_normal;
#line 0 ""
            sjf_vec3_normalize(sjt_parent85, &sjv_v.normal);
            sjf_vertex_location_texture_normal(&sjv_v);
#line 16 ".\..\lib\common\array.sj"
            sjt_parent86 = &sjv_vertices;
#line 98 ".\..\lib\ui\vertexBufferBuilders.sj"
            sjt_math2461 = slice;
#line 91
            sjt_math2463 = wedges;
#line 115
            sjt_math2464 = 1;
#line 115
            sjt_math2462 = sjt_math2463 + sjt_math2464;
#line 115
            sjt_math2459 = sjt_math2461 * sjt_math2462;
#line 103
            sjt_math2460 = wedge;
#line 115
            sjt_functionParam117 = sjt_math2459 + sjt_math2460;
#line 115
            sjt_functionParam118 = &sjv_v;
#line 0 ""
            sjf_array_vertex_location_texture_normal_initAt(sjt_parent86, sjt_functionParam117, sjt_functionParam118);
#line 103 ".\..\lib\ui\vertexBufferBuilders.sj"
            wedge++;

            sjf_vec3_destroy(&sjv_normal);
            sjf_vertex_location_texture_normal_destroy(&sjv_v);
        }

#line 98
        slice++;
    }

#line 91
    sjt_math2467 = slices;
#line 91
    sjt_math2468 = wedges;
#line 119
    sjt_math2465 = sjt_math2467 * sjt_math2468;
#line 119
    sjt_math2466 = 6;
#line 119
    sjv_indices.size = sjt_math2465 * sjt_math2466;
#line 3 ".\..\lib\common\array.sj"
    sjt_cast31 = 0;
#line 3
    sjv_indices.data = (uintptr_t)sjt_cast31;
#line 4
    sjv_indices._isGlobal = false;
#line 0 ""
    sjf_array_i32(&sjv_indices);
#line 120 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_forStart15 = 0;
#line 120
    slice = sjt_forStart15;
#line 91
    sjt_forEnd15 = slices;
    while (slice < sjt_forEnd15) {
        int32_t sjt_forEnd16;
        int32_t sjt_forStart16;
        int32_t wedge;

#line 121 ".\..\lib\ui\vertexBufferBuilders.sj"
        sjt_forStart16 = 0;
#line 121
        wedge = sjt_forStart16;
#line 91
        sjt_forEnd16 = wedges;
        while (wedge < sjt_forEnd16) {
            int32_t sjt_functionParam119;
            int32_t sjt_functionParam120;
            int32_t sjt_functionParam121;
            int32_t sjt_functionParam122;
            int32_t sjt_functionParam123;
            int32_t sjt_functionParam124;
            int32_t sjt_functionParam125;
            int32_t sjt_functionParam126;
            int32_t sjt_functionParam127;
            int32_t sjt_functionParam128;
            int32_t sjt_functionParam129;
            int32_t sjt_functionParam130;
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
            int32_t sjt_math2499;
            int32_t sjt_math2500;
            int32_t sjt_math2501;
            int32_t sjt_math2502;
            int32_t sjt_math2503;
            int32_t sjt_math2504;
            int32_t sjt_math2505;
            int32_t sjt_math2506;
            int32_t sjt_math2507;
            int32_t sjt_math2508;
            int32_t sjt_math2509;
            int32_t sjt_math2510;
            int32_t sjt_math2511;
            int32_t sjt_math2512;
            int32_t sjt_math2513;
            int32_t sjt_math2514;
            int32_t sjt_math2515;
            int32_t sjt_math2516;
            int32_t sjt_math2517;
            int32_t sjt_math2518;
            int32_t sjt_math2519;
            int32_t sjt_math2520;
            int32_t sjt_math2521;
            int32_t sjt_math2522;
            int32_t sjt_math2523;
            int32_t sjt_math2524;
            int32_t sjt_math2525;
            int32_t sjt_math2526;
            int32_t sjt_math2527;
            int32_t sjt_math2528;
            int32_t sjt_math2529;
            int32_t sjt_math2530;
            int32_t sjt_math2531;
            int32_t sjt_math2532;
            int32_t sjt_math2533;
            int32_t sjt_math2534;
            int32_t sjt_math2535;
            int32_t sjt_math2536;
            int32_t sjt_math2537;
            int32_t sjt_math2538;
            int32_t sjt_math2539;
            int32_t sjt_math2540;
            int32_t sjt_math2541;
            int32_t sjt_math2542;
            int32_t sjt_math2543;
            int32_t sjt_math2544;
            int32_t sjt_math2545;
            int32_t sjt_math2546;
            sjs_array_i32* sjt_parent87;
            sjs_array_i32* sjt_parent88;
            sjs_array_i32* sjt_parent89;
            sjs_array_i32* sjt_parent90;
            sjs_array_i32* sjt_parent91;
            sjs_array_i32* sjt_parent92;
            int32_t sjv_index0;
            int32_t sjv_index1;
            int32_t sjv_index2;
            int32_t sjv_index3;
            int32_t sjv_wedge0;
            int32_t sjv_wedge1;

#line 121 ".\..\lib\ui\vertexBufferBuilders.sj"
            sjv_wedge0 = wedge;
#line 121
            sjt_math2469 = wedge;
#line 123
            sjt_math2470 = 1;
#line 123
            sjv_wedge1 = sjt_math2469 + sjt_math2470;
#line 120
            sjt_math2473 = slice;
#line 91
            sjt_math2475 = wedges;
#line 125
            sjt_math2476 = 1;
#line 125
            sjt_math2474 = sjt_math2475 + sjt_math2476;
#line 125
            sjt_math2471 = sjt_math2473 * sjt_math2474;
#line 125
            sjt_math2472 = sjv_wedge0;
#line 125
            sjv_index0 = sjt_math2471 + sjt_math2472;
#line 120
            sjt_math2479 = slice;
#line 91
            sjt_math2481 = wedges;
#line 126
            sjt_math2482 = 1;
#line 126
            sjt_math2480 = sjt_math2481 + sjt_math2482;
#line 126
            sjt_math2477 = sjt_math2479 * sjt_math2480;
#line 126
            sjt_math2478 = sjv_wedge1;
#line 126
            sjv_index1 = sjt_math2477 + sjt_math2478;
#line 120
            sjt_math2487 = slice;
#line 127
            sjt_math2488 = 1;
#line 127
            sjt_math2485 = sjt_math2487 + sjt_math2488;
#line 91
            sjt_math2489 = wedges;
#line 127
            sjt_math2490 = 1;
#line 127
            sjt_math2486 = sjt_math2489 + sjt_math2490;
#line 127
            sjt_math2483 = sjt_math2485 * sjt_math2486;
#line 127
            sjt_math2484 = sjv_wedge1;
#line 127
            sjv_index2 = sjt_math2483 + sjt_math2484;
#line 120
            sjt_math2495 = slice;
#line 128
            sjt_math2496 = 1;
#line 128
            sjt_math2493 = sjt_math2495 + sjt_math2496;
#line 91
            sjt_math2497 = wedges;
#line 128
            sjt_math2498 = 1;
#line 128
            sjt_math2494 = sjt_math2497 + sjt_math2498;
#line 128
            sjt_math2491 = sjt_math2493 * sjt_math2494;
#line 128
            sjt_math2492 = sjv_wedge0;
#line 128
            sjv_index3 = sjt_math2491 + sjt_math2492;
#line 16 ".\..\lib\common\array.sj"
            sjt_parent87 = &sjv_indices;
#line 120 ".\..\lib\ui\vertexBufferBuilders.sj"
            sjt_math2505 = slice;
#line 91
            sjt_math2506 = wedges;
#line 130
            sjt_math2503 = sjt_math2505 * sjt_math2506;
#line 121
            sjt_math2504 = wedge;
#line 130
            sjt_math2501 = sjt_math2503 + sjt_math2504;
#line 130
            sjt_math2502 = 6;
#line 130
            sjt_math2499 = sjt_math2501 * sjt_math2502;
#line 130
            sjt_math2500 = 0;
#line 130
            sjt_functionParam119 = sjt_math2499 + sjt_math2500;
#line 130
            sjt_functionParam120 = sjv_index0;
#line 0 ""
            sjf_array_i32_initAt(sjt_parent87, sjt_functionParam119, sjt_functionParam120);
#line 16 ".\..\lib\common\array.sj"
            sjt_parent88 = &sjv_indices;
#line 120 ".\..\lib\ui\vertexBufferBuilders.sj"
            sjt_math2513 = slice;
#line 91
            sjt_math2514 = wedges;
#line 131
            sjt_math2511 = sjt_math2513 * sjt_math2514;
#line 121
            sjt_math2512 = wedge;
#line 131
            sjt_math2509 = sjt_math2511 + sjt_math2512;
#line 131
            sjt_math2510 = 6;
#line 131
            sjt_math2507 = sjt_math2509 * sjt_math2510;
#line 131
            sjt_math2508 = 1;
#line 131
            sjt_functionParam121 = sjt_math2507 + sjt_math2508;
#line 131
            sjt_functionParam122 = sjv_index1;
#line 0 ""
            sjf_array_i32_initAt(sjt_parent88, sjt_functionParam121, sjt_functionParam122);
#line 16 ".\..\lib\common\array.sj"
            sjt_parent89 = &sjv_indices;
#line 120 ".\..\lib\ui\vertexBufferBuilders.sj"
            sjt_math2521 = slice;
#line 91
            sjt_math2522 = wedges;
#line 132
            sjt_math2519 = sjt_math2521 * sjt_math2522;
#line 121
            sjt_math2520 = wedge;
#line 132
            sjt_math2517 = sjt_math2519 + sjt_math2520;
#line 132
            sjt_math2518 = 6;
#line 132
            sjt_math2515 = sjt_math2517 * sjt_math2518;
#line 132
            sjt_math2516 = 2;
#line 132
            sjt_functionParam123 = sjt_math2515 + sjt_math2516;
#line 132
            sjt_functionParam124 = sjv_index2;
#line 0 ""
            sjf_array_i32_initAt(sjt_parent89, sjt_functionParam123, sjt_functionParam124);
#line 16 ".\..\lib\common\array.sj"
            sjt_parent90 = &sjv_indices;
#line 120 ".\..\lib\ui\vertexBufferBuilders.sj"
            sjt_math2529 = slice;
#line 91
            sjt_math2530 = wedges;
#line 133
            sjt_math2527 = sjt_math2529 * sjt_math2530;
#line 121
            sjt_math2528 = wedge;
#line 133
            sjt_math2525 = sjt_math2527 + sjt_math2528;
#line 133
            sjt_math2526 = 6;
#line 133
            sjt_math2523 = sjt_math2525 * sjt_math2526;
#line 133
            sjt_math2524 = 3;
#line 133
            sjt_functionParam125 = sjt_math2523 + sjt_math2524;
#line 133
            sjt_functionParam126 = sjv_index2;
#line 0 ""
            sjf_array_i32_initAt(sjt_parent90, sjt_functionParam125, sjt_functionParam126);
#line 16 ".\..\lib\common\array.sj"
            sjt_parent91 = &sjv_indices;
#line 120 ".\..\lib\ui\vertexBufferBuilders.sj"
            sjt_math2537 = slice;
#line 91
            sjt_math2538 = wedges;
#line 134
            sjt_math2535 = sjt_math2537 * sjt_math2538;
#line 121
            sjt_math2536 = wedge;
#line 134
            sjt_math2533 = sjt_math2535 + sjt_math2536;
#line 134
            sjt_math2534 = 6;
#line 134
            sjt_math2531 = sjt_math2533 * sjt_math2534;
#line 134
            sjt_math2532 = 4;
#line 134
            sjt_functionParam127 = sjt_math2531 + sjt_math2532;
#line 134
            sjt_functionParam128 = sjv_index3;
#line 0 ""
            sjf_array_i32_initAt(sjt_parent91, sjt_functionParam127, sjt_functionParam128);
#line 16 ".\..\lib\common\array.sj"
            sjt_parent92 = &sjv_indices;
#line 120 ".\..\lib\ui\vertexBufferBuilders.sj"
            sjt_math2545 = slice;
#line 91
            sjt_math2546 = wedges;
#line 135
            sjt_math2543 = sjt_math2545 * sjt_math2546;
#line 121
            sjt_math2544 = wedge;
#line 135
            sjt_math2541 = sjt_math2543 + sjt_math2544;
#line 135
            sjt_math2542 = 6;
#line 135
            sjt_math2539 = sjt_math2541 * sjt_math2542;
#line 135
            sjt_math2540 = 5;
#line 135
            sjt_functionParam129 = sjt_math2539 + sjt_math2540;
#line 135
            sjt_functionParam130 = sjv_index0;
#line 0 ""
            sjf_array_i32_initAt(sjt_parent92, sjt_functionParam129, sjt_functionParam130);
#line 121 ".\..\lib\ui\vertexBufferBuilders.sj"
            wedge++;
        }

#line 120
        slice++;
    }

#line 139
    sjf_string_copy(&_return->format, &sjv_vertex_location_texture_normal_format);
#line 139
    sjf_array_i32_copy(&_return->indices, &sjv_indices);
#line 139
    sjf_array_vertex_location_texture_normal_copy(&_return->vertices, &sjv_vertices);
#line 0 ""
    sjf_vertexBuffer_vertex_location_texture_normal(_return);

    sjf_array_i32_destroy(&sjv_indices);
    sjf_array_vertex_location_texture_normal_destroy(&sjv_vertices);
}

void sjf_sphereVertexBuffer_heap(int32_t slices, int32_t wedges, sjs_vec3* origin, sjs_vec3* radius, sjs_vertexBuffer_vertex_location_texture_normal_heap** _return) {
    int32_t sjt_cast32;
    int32_t sjt_cast41;
    int32_t sjt_forEnd17;
    int32_t sjt_forEnd19;
    int32_t sjt_forStart17;
    int32_t sjt_forStart19;
    int32_t sjt_math2547;
    int32_t sjt_math2548;
    int32_t sjt_math2549;
    int32_t sjt_math2550;
    int32_t sjt_math2551;
    int32_t sjt_math2552;
    int32_t sjt_math2553;
    int32_t sjt_math2554;
    int32_t sjt_math2599;
    int32_t sjt_math2600;
    int32_t sjt_math2601;
    int32_t sjt_math2602;
    sjs_array_i32 sjv_indices;
    sjs_array_vertex_location_texture_normal sjv_vertices;
    int32_t slice;

#line 91 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_math2549 = slices;
#line 97
    sjt_math2550 = 1;
#line 97
    sjt_math2547 = sjt_math2549 + sjt_math2550;
#line 91
    sjt_math2551 = wedges;
#line 97
    sjt_math2552 = 1;
#line 97
    sjt_math2548 = sjt_math2551 + sjt_math2552;
#line 97
    sjv_vertices.size = sjt_math2547 * sjt_math2548;
#line 3 ".\..\lib\common\array.sj"
    sjt_cast32 = 0;
#line 3
    sjv_vertices.data = (uintptr_t)sjt_cast32;
#line 4
    sjv_vertices._isGlobal = false;
#line 0 ""
    sjf_array_vertex_location_texture_normal(&sjv_vertices);
#line 98 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_forStart17 = 0;
#line 98
    slice = sjt_forStart17;
#line 91
    sjt_math2553 = slices;
#line 98
    sjt_math2554 = 1;
#line 98
    sjt_forEnd17 = sjt_math2553 + sjt_math2554;
    while (slice < sjt_forEnd17) {
        int32_t sjt_cast33;
        int32_t sjt_cast34;
        int32_t sjt_cast35;
        int32_t sjt_cast36;
        sjs_vec3* sjt_dot1326;
        int32_t sjt_forEnd18;
        int32_t sjt_forStart18;
        float sjt_functionParam131;
        float sjt_functionParam132;
        float sjt_math2555;
        float sjt_math2556;
        float sjt_math2557;
        float sjt_math2558;
        float sjt_math2559;
        float sjt_math2560;
        float sjt_math2561;
        float sjt_math2562;
        float sjt_math2563;
        float sjt_math2564;
        int32_t sjt_math2565;
        int32_t sjt_math2566;
        float sjv_r0;
        float sjv_theta;
        float sjv_tv;
        float sjv_y0;
        int32_t wedge;

#line 98 ".\..\lib\ui\vertexBufferBuilders.sj"
        sjt_cast33 = slice;
#line 99
        sjt_math2555 = (float)sjt_cast33;
#line 91
        sjt_cast34 = slices;
#line 99
        sjt_math2556 = (float)sjt_cast34;
#line 99
        sjv_tv = sjt_math2555 / sjt_math2556;
#line 100
        sjt_math2561 = sjv_f32_pi;
#line 98
        sjt_cast35 = slice;
#line 100
        sjt_math2562 = (float)sjt_cast35;
#line 100
        sjt_math2559 = sjt_math2561 * sjt_math2562;
#line 91
        sjt_cast36 = slices;
#line 100
        sjt_math2560 = (float)sjt_cast36;
#line 100
        sjt_math2557 = sjt_math2559 / sjt_math2560;
#line 100
        sjt_math2558 = sjv_f32_pi;
#line 100
        sjv_theta = sjt_math2557 + sjt_math2558;
#line 101
        sjt_functionParam131 = sjv_theta;
#line 0 ""
        sjf_f32_cos(sjt_functionParam131, &sjt_math2563);
#line 91 ".\..\lib\ui\vertexBufferBuilders.sj"
        sjt_dot1326 = radius;
#line 101
        sjt_math2564 = (sjt_dot1326)->y;
#line 101
        sjv_y0 = sjt_math2563 * sjt_math2564;
#line 102
        sjt_functionParam132 = sjv_theta;
#line 0 ""
        sjf_f32_sin(sjt_functionParam132, &sjv_r0);
#line 103 ".\..\lib\ui\vertexBufferBuilders.sj"
        sjt_forStart18 = 0;
#line 103
        wedge = sjt_forStart18;
#line 91
        sjt_math2565 = wedges;
#line 103
        sjt_math2566 = 1;
#line 103
        sjt_forEnd18 = sjt_math2565 + sjt_math2566;
        while (wedge < sjt_forEnd18) {
            int32_t sjt_cast37;
            int32_t sjt_cast38;
            int32_t sjt_cast39;
            int32_t sjt_cast40;
            sjs_vec3* sjt_dot1327;
            sjs_vec3* sjt_dot1328;
            sjs_vec3* sjt_dot1329;
            sjs_vec3* sjt_dot1330;
            sjs_vec3* sjt_dot1331;
            float sjt_functionParam133;
            float sjt_functionParam134;
            int32_t sjt_functionParam135;
            sjs_vertex_location_texture_normal* sjt_functionParam136;
            float sjt_math2567;
            float sjt_math2568;
            float sjt_math2569;
            float sjt_math2570;
            float sjt_math2571;
            float sjt_math2572;
            float sjt_math2573;
            float sjt_math2574;
            float sjt_math2575;
            float sjt_math2576;
            float sjt_math2577;
            float sjt_math2578;
            float sjt_math2579;
            float sjt_math2580;
            float sjt_math2581;
            float sjt_math2582;
            float sjt_math2583;
            float sjt_math2584;
            float sjt_math2585;
            float sjt_math2586;
            float sjt_math2587;
            float sjt_math2588;
            float sjt_math2589;
            float sjt_math2590;
            float sjt_math2591;
            float sjt_math2592;
            int32_t sjt_math2593;
            int32_t sjt_math2594;
            int32_t sjt_math2595;
            int32_t sjt_math2596;
            int32_t sjt_math2597;
            int32_t sjt_math2598;
            sjs_vec3* sjt_parent93;
            sjs_array_vertex_location_texture_normal* sjt_parent94;
            float sjv_angle;
            sjs_vec3 sjv_normal;
            float sjv_tu;
            sjs_vertex_location_texture_normal sjv_v;
            float sjv_x0;
            float sjv_z0;

#line 103 ".\..\lib\ui\vertexBufferBuilders.sj"
            sjt_cast37 = wedge;
#line 104
            sjt_math2567 = (float)sjt_cast37;
#line 91
            sjt_cast38 = wedges;
#line 104
            sjt_math2568 = (float)sjt_cast38;
#line 104
            sjv_tu = sjt_math2567 / sjt_math2568;
#line 105
            sjt_math2575 = 2.0f;
#line 105
            sjt_math2576 = sjv_f32_pi;
#line 105
            sjt_math2573 = sjt_math2575 * sjt_math2576;
#line 103
            sjt_cast39 = wedge;
#line 105
            sjt_math2574 = (float)sjt_cast39;
#line 105
            sjt_math2571 = sjt_math2573 * sjt_math2574;
#line 91
            sjt_cast40 = wedges;
#line 105
            sjt_math2572 = (float)sjt_cast40;
#line 105
            sjt_math2569 = sjt_math2571 / sjt_math2572;
#line 105
            sjt_math2577 = 1.5f;
#line 105
            sjt_math2578 = sjv_f32_pi;
#line 105
            sjt_math2570 = sjt_math2577 * sjt_math2578;
#line 105
            sjv_angle = sjt_math2569 - sjt_math2570;
#line 106
            sjt_functionParam133 = sjv_angle;
#line 0 ""
            sjf_f32_cos(sjt_functionParam133, &sjt_math2581);
#line 106 ".\..\lib\ui\vertexBufferBuilders.sj"
            sjt_math2582 = sjv_r0;
#line 106
            sjt_math2579 = sjt_math2581 * sjt_math2582;
#line 91
            sjt_dot1327 = radius;
#line 106
            sjt_math2580 = (sjt_dot1327)->x;
#line 106
            sjv_x0 = sjt_math2579 * sjt_math2580;
#line 107
            sjt_functionParam134 = sjv_angle;
#line 0 ""
            sjf_f32_sin(sjt_functionParam134, &sjt_math2585);
#line 107 ".\..\lib\ui\vertexBufferBuilders.sj"
            sjt_math2586 = sjv_r0;
#line 107
            sjt_math2583 = sjt_math2585 * sjt_math2586;
#line 91
            sjt_dot1328 = radius;
#line 107
            sjt_math2584 = (sjt_dot1328)->y;
#line 107
            sjv_z0 = sjt_math2583 * sjt_math2584;
#line 108
            sjv_normal.x = sjv_x0;
#line 108
            sjv_normal.y = sjv_y0;
#line 108
            sjv_normal.z = sjv_z0;
#line 0 ""
            sjf_vec3(&sjv_normal);
#line 111 ".\..\lib\ui\vertexBufferBuilders.sj"
            sjt_math2587 = sjv_x0;
#line 91
            sjt_dot1329 = origin;
#line 111
            sjt_math2588 = (sjt_dot1329)->x;
#line 111
            sjv_v.location.x = sjt_math2587 + sjt_math2588;
#line 111
            sjt_math2589 = sjv_y0;
#line 91
            sjt_dot1330 = origin;
#line 111
            sjt_math2590 = (sjt_dot1330)->y;
#line 111
            sjv_v.location.y = sjt_math2589 + sjt_math2590;
#line 111
            sjt_math2591 = sjv_z0;
#line 91
            sjt_dot1331 = origin;
#line 111
            sjt_math2592 = (sjt_dot1331)->z;
#line 111
            sjv_v.location.z = sjt_math2591 + sjt_math2592;
#line 0 ""
            sjf_vec3(&sjv_v.location);
#line 112 ".\..\lib\ui\vertexBufferBuilders.sj"
            sjv_v.texture.x = sjv_tu;
#line 112
            sjv_v.texture.y = sjv_tv;
#line 0 ""
            sjf_vec2(&sjv_v.texture);
#line 29 ".\..\lib\ui\vec3.sj"
            sjt_parent93 = &sjv_normal;
#line 0 ""
            sjf_vec3_normalize(sjt_parent93, &sjv_v.normal);
            sjf_vertex_location_texture_normal(&sjv_v);
#line 16 ".\..\lib\common\array.sj"
            sjt_parent94 = &sjv_vertices;
#line 98 ".\..\lib\ui\vertexBufferBuilders.sj"
            sjt_math2595 = slice;
#line 91
            sjt_math2597 = wedges;
#line 115
            sjt_math2598 = 1;
#line 115
            sjt_math2596 = sjt_math2597 + sjt_math2598;
#line 115
            sjt_math2593 = sjt_math2595 * sjt_math2596;
#line 103
            sjt_math2594 = wedge;
#line 115
            sjt_functionParam135 = sjt_math2593 + sjt_math2594;
#line 115
            sjt_functionParam136 = &sjv_v;
#line 0 ""
            sjf_array_vertex_location_texture_normal_initAt(sjt_parent94, sjt_functionParam135, sjt_functionParam136);
#line 103 ".\..\lib\ui\vertexBufferBuilders.sj"
            wedge++;

            sjf_vec3_destroy(&sjv_normal);
            sjf_vertex_location_texture_normal_destroy(&sjv_v);
        }

#line 98
        slice++;
    }

#line 91
    sjt_math2601 = slices;
#line 91
    sjt_math2602 = wedges;
#line 119
    sjt_math2599 = sjt_math2601 * sjt_math2602;
#line 119
    sjt_math2600 = 6;
#line 119
    sjv_indices.size = sjt_math2599 * sjt_math2600;
#line 3 ".\..\lib\common\array.sj"
    sjt_cast41 = 0;
#line 3
    sjv_indices.data = (uintptr_t)sjt_cast41;
#line 4
    sjv_indices._isGlobal = false;
#line 0 ""
    sjf_array_i32(&sjv_indices);
#line 120 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_forStart19 = 0;
#line 120
    slice = sjt_forStart19;
#line 91
    sjt_forEnd19 = slices;
    while (slice < sjt_forEnd19) {
        int32_t sjt_forEnd20;
        int32_t sjt_forStart20;
        int32_t wedge;

#line 121 ".\..\lib\ui\vertexBufferBuilders.sj"
        sjt_forStart20 = 0;
#line 121
        wedge = sjt_forStart20;
#line 91
        sjt_forEnd20 = wedges;
        while (wedge < sjt_forEnd20) {
            int32_t sjt_functionParam137;
            int32_t sjt_functionParam138;
            int32_t sjt_functionParam139;
            int32_t sjt_functionParam140;
            int32_t sjt_functionParam141;
            int32_t sjt_functionParam142;
            int32_t sjt_functionParam143;
            int32_t sjt_functionParam144;
            int32_t sjt_functionParam145;
            int32_t sjt_functionParam146;
            int32_t sjt_functionParam147;
            int32_t sjt_functionParam148;
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
            int32_t sjt_math2633;
            int32_t sjt_math2634;
            int32_t sjt_math2635;
            int32_t sjt_math2636;
            int32_t sjt_math2637;
            int32_t sjt_math2638;
            int32_t sjt_math2639;
            int32_t sjt_math2640;
            int32_t sjt_math2641;
            int32_t sjt_math2642;
            int32_t sjt_math2643;
            int32_t sjt_math2644;
            int32_t sjt_math2645;
            int32_t sjt_math2646;
            int32_t sjt_math2647;
            int32_t sjt_math2648;
            int32_t sjt_math2649;
            int32_t sjt_math2650;
            int32_t sjt_math2651;
            int32_t sjt_math2652;
            int32_t sjt_math2653;
            int32_t sjt_math2654;
            int32_t sjt_math2655;
            int32_t sjt_math2656;
            int32_t sjt_math2657;
            int32_t sjt_math2658;
            int32_t sjt_math2659;
            int32_t sjt_math2660;
            int32_t sjt_math2661;
            int32_t sjt_math2662;
            int32_t sjt_math2663;
            int32_t sjt_math2664;
            int32_t sjt_math2665;
            int32_t sjt_math2666;
            int32_t sjt_math2667;
            int32_t sjt_math2668;
            int32_t sjt_math2669;
            int32_t sjt_math2670;
            int32_t sjt_math2671;
            int32_t sjt_math2672;
            int32_t sjt_math2673;
            int32_t sjt_math2674;
            int32_t sjt_math2675;
            int32_t sjt_math2676;
            int32_t sjt_math2677;
            int32_t sjt_math2678;
            int32_t sjt_math2679;
            int32_t sjt_math2680;
            sjs_array_i32* sjt_parent100;
            sjs_array_i32* sjt_parent95;
            sjs_array_i32* sjt_parent96;
            sjs_array_i32* sjt_parent97;
            sjs_array_i32* sjt_parent98;
            sjs_array_i32* sjt_parent99;
            int32_t sjv_index0;
            int32_t sjv_index1;
            int32_t sjv_index2;
            int32_t sjv_index3;
            int32_t sjv_wedge0;
            int32_t sjv_wedge1;

#line 121 ".\..\lib\ui\vertexBufferBuilders.sj"
            sjv_wedge0 = wedge;
#line 121
            sjt_math2603 = wedge;
#line 123
            sjt_math2604 = 1;
#line 123
            sjv_wedge1 = sjt_math2603 + sjt_math2604;
#line 120
            sjt_math2607 = slice;
#line 91
            sjt_math2609 = wedges;
#line 125
            sjt_math2610 = 1;
#line 125
            sjt_math2608 = sjt_math2609 + sjt_math2610;
#line 125
            sjt_math2605 = sjt_math2607 * sjt_math2608;
#line 125
            sjt_math2606 = sjv_wedge0;
#line 125
            sjv_index0 = sjt_math2605 + sjt_math2606;
#line 120
            sjt_math2613 = slice;
#line 91
            sjt_math2615 = wedges;
#line 126
            sjt_math2616 = 1;
#line 126
            sjt_math2614 = sjt_math2615 + sjt_math2616;
#line 126
            sjt_math2611 = sjt_math2613 * sjt_math2614;
#line 126
            sjt_math2612 = sjv_wedge1;
#line 126
            sjv_index1 = sjt_math2611 + sjt_math2612;
#line 120
            sjt_math2621 = slice;
#line 127
            sjt_math2622 = 1;
#line 127
            sjt_math2619 = sjt_math2621 + sjt_math2622;
#line 91
            sjt_math2623 = wedges;
#line 127
            sjt_math2624 = 1;
#line 127
            sjt_math2620 = sjt_math2623 + sjt_math2624;
#line 127
            sjt_math2617 = sjt_math2619 * sjt_math2620;
#line 127
            sjt_math2618 = sjv_wedge1;
#line 127
            sjv_index2 = sjt_math2617 + sjt_math2618;
#line 120
            sjt_math2629 = slice;
#line 128
            sjt_math2630 = 1;
#line 128
            sjt_math2627 = sjt_math2629 + sjt_math2630;
#line 91
            sjt_math2631 = wedges;
#line 128
            sjt_math2632 = 1;
#line 128
            sjt_math2628 = sjt_math2631 + sjt_math2632;
#line 128
            sjt_math2625 = sjt_math2627 * sjt_math2628;
#line 128
            sjt_math2626 = sjv_wedge0;
#line 128
            sjv_index3 = sjt_math2625 + sjt_math2626;
#line 16 ".\..\lib\common\array.sj"
            sjt_parent95 = &sjv_indices;
#line 120 ".\..\lib\ui\vertexBufferBuilders.sj"
            sjt_math2639 = slice;
#line 91
            sjt_math2640 = wedges;
#line 130
            sjt_math2637 = sjt_math2639 * sjt_math2640;
#line 121
            sjt_math2638 = wedge;
#line 130
            sjt_math2635 = sjt_math2637 + sjt_math2638;
#line 130
            sjt_math2636 = 6;
#line 130
            sjt_math2633 = sjt_math2635 * sjt_math2636;
#line 130
            sjt_math2634 = 0;
#line 130
            sjt_functionParam137 = sjt_math2633 + sjt_math2634;
#line 130
            sjt_functionParam138 = sjv_index0;
#line 0 ""
            sjf_array_i32_initAt(sjt_parent95, sjt_functionParam137, sjt_functionParam138);
#line 16 ".\..\lib\common\array.sj"
            sjt_parent96 = &sjv_indices;
#line 120 ".\..\lib\ui\vertexBufferBuilders.sj"
            sjt_math2647 = slice;
#line 91
            sjt_math2648 = wedges;
#line 131
            sjt_math2645 = sjt_math2647 * sjt_math2648;
#line 121
            sjt_math2646 = wedge;
#line 131
            sjt_math2643 = sjt_math2645 + sjt_math2646;
#line 131
            sjt_math2644 = 6;
#line 131
            sjt_math2641 = sjt_math2643 * sjt_math2644;
#line 131
            sjt_math2642 = 1;
#line 131
            sjt_functionParam139 = sjt_math2641 + sjt_math2642;
#line 131
            sjt_functionParam140 = sjv_index1;
#line 0 ""
            sjf_array_i32_initAt(sjt_parent96, sjt_functionParam139, sjt_functionParam140);
#line 16 ".\..\lib\common\array.sj"
            sjt_parent97 = &sjv_indices;
#line 120 ".\..\lib\ui\vertexBufferBuilders.sj"
            sjt_math2655 = slice;
#line 91
            sjt_math2656 = wedges;
#line 132
            sjt_math2653 = sjt_math2655 * sjt_math2656;
#line 121
            sjt_math2654 = wedge;
#line 132
            sjt_math2651 = sjt_math2653 + sjt_math2654;
#line 132
            sjt_math2652 = 6;
#line 132
            sjt_math2649 = sjt_math2651 * sjt_math2652;
#line 132
            sjt_math2650 = 2;
#line 132
            sjt_functionParam141 = sjt_math2649 + sjt_math2650;
#line 132
            sjt_functionParam142 = sjv_index2;
#line 0 ""
            sjf_array_i32_initAt(sjt_parent97, sjt_functionParam141, sjt_functionParam142);
#line 16 ".\..\lib\common\array.sj"
            sjt_parent98 = &sjv_indices;
#line 120 ".\..\lib\ui\vertexBufferBuilders.sj"
            sjt_math2663 = slice;
#line 91
            sjt_math2664 = wedges;
#line 133
            sjt_math2661 = sjt_math2663 * sjt_math2664;
#line 121
            sjt_math2662 = wedge;
#line 133
            sjt_math2659 = sjt_math2661 + sjt_math2662;
#line 133
            sjt_math2660 = 6;
#line 133
            sjt_math2657 = sjt_math2659 * sjt_math2660;
#line 133
            sjt_math2658 = 3;
#line 133
            sjt_functionParam143 = sjt_math2657 + sjt_math2658;
#line 133
            sjt_functionParam144 = sjv_index2;
#line 0 ""
            sjf_array_i32_initAt(sjt_parent98, sjt_functionParam143, sjt_functionParam144);
#line 16 ".\..\lib\common\array.sj"
            sjt_parent99 = &sjv_indices;
#line 120 ".\..\lib\ui\vertexBufferBuilders.sj"
            sjt_math2671 = slice;
#line 91
            sjt_math2672 = wedges;
#line 134
            sjt_math2669 = sjt_math2671 * sjt_math2672;
#line 121
            sjt_math2670 = wedge;
#line 134
            sjt_math2667 = sjt_math2669 + sjt_math2670;
#line 134
            sjt_math2668 = 6;
#line 134
            sjt_math2665 = sjt_math2667 * sjt_math2668;
#line 134
            sjt_math2666 = 4;
#line 134
            sjt_functionParam145 = sjt_math2665 + sjt_math2666;
#line 134
            sjt_functionParam146 = sjv_index3;
#line 0 ""
            sjf_array_i32_initAt(sjt_parent99, sjt_functionParam145, sjt_functionParam146);
#line 16 ".\..\lib\common\array.sj"
            sjt_parent100 = &sjv_indices;
#line 120 ".\..\lib\ui\vertexBufferBuilders.sj"
            sjt_math2679 = slice;
#line 91
            sjt_math2680 = wedges;
#line 135
            sjt_math2677 = sjt_math2679 * sjt_math2680;
#line 121
            sjt_math2678 = wedge;
#line 135
            sjt_math2675 = sjt_math2677 + sjt_math2678;
#line 135
            sjt_math2676 = 6;
#line 135
            sjt_math2673 = sjt_math2675 * sjt_math2676;
#line 135
            sjt_math2674 = 5;
#line 135
            sjt_functionParam147 = sjt_math2673 + sjt_math2674;
#line 135
            sjt_functionParam148 = sjv_index0;
#line 0 ""
            sjf_array_i32_initAt(sjt_parent100, sjt_functionParam147, sjt_functionParam148);
#line 121 ".\..\lib\ui\vertexBufferBuilders.sj"
            wedge++;
        }

#line 120
        slice++;
    }

#line 0 ""
    (*_return) = (sjs_vertexBuffer_vertex_location_texture_normal_heap*)malloc(sizeof(sjs_vertexBuffer_vertex_location_texture_normal_heap));
    (*_return)->_refCount = 1;
#line 139 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjf_string_copy(&(*_return)->format, &sjv_vertex_location_texture_normal_format);
#line 139
    sjf_array_i32_copy(&(*_return)->indices, &sjv_indices);
#line 139
    sjf_array_vertex_location_texture_normal_copy(&(*_return)->vertices, &sjv_vertices);
#line 0 ""
    sjf_vertexBuffer_vertex_location_texture_normal_heap((*_return));

    sjf_array_i32_destroy(&sjv_indices);
    sjf_array_vertex_location_texture_normal_destroy(&sjv_vertices);
}

void sjf_string(sjs_string* _this) {
}

void sjf_string_copy(sjs_string* _this, sjs_string* _from) {
#line 1 ".\..\lib\common\string.sj"
    _this->count = _from->count;
#line 1
    sjf_array_char_copy(&_this->data, &_from->data);
}

void sjf_string_destroy(sjs_string* _this) {
}

void sjf_string_heap(sjs_string_heap* _this) {
}

void sjf_texture(sjs_texture* _this) {
}

void sjf_textureFromPng(sjs_string* fileName, sjs_texture* _return) {
    int32_t sjv_h;
    uint32_t sjv_id;
    int32_t sjv_w;

#line 2 ".\..\lib\ui\texture.sj"
    sjv_id = (uint32_t)0u;
#line 3
    sjv_w = 0;
#line 4
    sjv_h = 0;
#line 5
    sjv_id = png_texture_load((char*)fileName->data.data, &sjv_w, &sjv_h);
#line 8
    _return->size.w = sjv_w;
#line 8
    _return->size.h = sjv_h;
#line 0 ""
    sjf_size(&_return->size);
#line 8 ".\..\lib\ui\texture.sj"
    _return->id = sjv_id;
#line 0 ""
    sjf_texture(_return);
}

void sjf_textureFromPng_heap(sjs_string* fileName, sjs_texture_heap** _return) {
    int32_t sjv_h;
    uint32_t sjv_id;
    int32_t sjv_w;

#line 2 ".\..\lib\ui\texture.sj"
    sjv_id = (uint32_t)0u;
#line 3
    sjv_w = 0;
#line 4
    sjv_h = 0;
#line 5
    sjv_id = png_texture_load((char*)fileName->data.data, &sjv_w, &sjv_h);
#line 0 ""
    (*_return) = (sjs_texture_heap*)malloc(sizeof(sjs_texture_heap));
    (*_return)->_refCount = 1;
#line 8 ".\..\lib\ui\texture.sj"
    (*_return)->size.w = sjv_w;
#line 8
    (*_return)->size.h = sjv_h;
#line 0 ""
    sjf_size(&(*_return)->size);
#line 8 ".\..\lib\ui\texture.sj"
    (*_return)->id = sjv_id;
#line 0 ""
    sjf_texture_heap((*_return));
}

void sjf_texture_copy(sjs_texture* _this, sjs_texture* _from) {
#line 11 ".\..\lib\ui\texture.sj"
    sjf_size_copy(&_this->size, &_from->size);
#line 11
    _this->id = _from->id;
#line 19
    _retainGLid(_this->id);
}

void sjf_texture_destroy(sjs_texture* _this) {
#line 23 ".\..\lib\ui\texture.sj"
    if (_releaseGLid(_this->id)) {
#line 23
        glDeleteTextures(1, &_this->id);
#line 23
    }
}

void sjf_texture_getSize(sjs_texture* _parent, sjs_size* _return) {
    sjs_size* sjt_dot1334;
    sjs_texture* sjt_dot1335;
    sjs_size* sjt_dot1336;
    sjs_texture* sjt_dot1337;

#line 15 ".\..\lib\ui\texture.sj"
    sjt_dot1335 = _parent;
#line 1 ".\..\lib\ui\size.sj"
    sjt_dot1334 = &(sjt_dot1335)->size;
#line 15 ".\..\lib\ui\texture.sj"
    _return->w = (sjt_dot1334)->w;
#line 15
    sjt_dot1337 = _parent;
#line 1 ".\..\lib\ui\size.sj"
    sjt_dot1336 = &(sjt_dot1337)->size;
#line 15 ".\..\lib\ui\texture.sj"
    _return->h = (sjt_dot1336)->h;
#line 0 ""
    sjf_size(_return);
}

void sjf_texture_getSize_heap(sjs_texture* _parent, sjs_size_heap** _return) {
    sjs_size* sjt_dot1338;
    sjs_texture* sjt_dot1339;
    sjs_size* sjt_dot1340;
    sjs_texture* sjt_dot1341;

    (*_return) = (sjs_size_heap*)malloc(sizeof(sjs_size_heap));
    (*_return)->_refCount = 1;
#line 15 ".\..\lib\ui\texture.sj"
    sjt_dot1339 = _parent;
#line 1 ".\..\lib\ui\size.sj"
    sjt_dot1338 = &(sjt_dot1339)->size;
#line 15 ".\..\lib\ui\texture.sj"
    (*_return)->w = (sjt_dot1338)->w;
#line 15
    sjt_dot1341 = _parent;
#line 1 ".\..\lib\ui\size.sj"
    sjt_dot1340 = &(sjt_dot1341)->size;
#line 15 ".\..\lib\ui\texture.sj"
    (*_return)->h = (sjt_dot1340)->h;
#line 0 ""
    sjf_size_heap((*_return));
}

void sjf_texture_heap(sjs_texture_heap* _this) {
}

void sjf_vec2(sjs_vec2* _this) {
}

void sjf_vec2_copy(sjs_vec2* _this, sjs_vec2* _from) {
#line 1 ".\..\lib\ui\vec2.sj"
    _this->x = _from->x;
#line 1
    _this->y = _from->y;
}

void sjf_vec2_destroy(sjs_vec2* _this) {
}

void sjf_vec2_heap(sjs_vec2_heap* _this) {
}

void sjf_vec3(sjs_vec3* _this) {
}

void sjf_vec3_copy(sjs_vec3* _this, sjs_vec3* _from) {
#line 1 ".\..\lib\ui\vec3.sj"
    _this->x = _from->x;
#line 1
    _this->y = _from->y;
#line 1
    _this->z = _from->z;
}

void sjf_vec3_cross(sjs_vec3* _parent, sjs_vec3* v, sjs_vec3* _return) {
    sjs_vec3* sjt_dot117;
    sjs_vec3* sjt_dot118;
    sjs_vec3* sjt_dot119;
    sjs_vec3* sjt_dot120;
    sjs_vec3* sjt_dot121;
    sjs_vec3* sjt_dot122;
    sjs_vec3* sjt_dot123;
    sjs_vec3* sjt_dot124;
    sjs_vec3* sjt_dot125;
    sjs_vec3* sjt_dot126;
    sjs_vec3* sjt_dot127;
    sjs_vec3* sjt_dot128;
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
    float sjt_math165;
    float sjt_math166;

#line 38 ".\..\lib\ui\vec3.sj"
    sjt_dot117 = _parent;
#line 40
    sjt_math151 = (sjt_dot117)->y;
#line 38
    sjt_dot118 = v;
#line 40
    sjt_math152 = (sjt_dot118)->z;
#line 40
    sjt_math149 = sjt_math151 * sjt_math152;
#line 38
    sjt_dot119 = _parent;
#line 40
    sjt_math153 = (sjt_dot119)->z;
#line 38
    sjt_dot120 = v;
#line 40
    sjt_math154 = (sjt_dot120)->y;
#line 40
    sjt_math150 = sjt_math153 * sjt_math154;
#line 40
    _return->x = sjt_math149 - sjt_math150;
#line 38
    sjt_dot121 = _parent;
#line 41
    sjt_math157 = (sjt_dot121)->z;
#line 38
    sjt_dot122 = v;
#line 41
    sjt_math158 = (sjt_dot122)->x;
#line 41
    sjt_math155 = sjt_math157 * sjt_math158;
#line 38
    sjt_dot123 = _parent;
#line 41
    sjt_math159 = (sjt_dot123)->x;
#line 38
    sjt_dot124 = v;
#line 41
    sjt_math160 = (sjt_dot124)->z;
#line 41
    sjt_math156 = sjt_math159 * sjt_math160;
#line 41
    _return->y = sjt_math155 - sjt_math156;
#line 38
    sjt_dot125 = _parent;
#line 42
    sjt_math163 = (sjt_dot125)->x;
#line 38
    sjt_dot126 = v;
#line 42
    sjt_math164 = (sjt_dot126)->y;
#line 42
    sjt_math161 = sjt_math163 * sjt_math164;
#line 38
    sjt_dot127 = _parent;
#line 42
    sjt_math165 = (sjt_dot127)->y;
#line 38
    sjt_dot128 = v;
#line 42
    sjt_math166 = (sjt_dot128)->x;
#line 42
    sjt_math162 = sjt_math165 * sjt_math166;
#line 42
    _return->z = sjt_math161 - sjt_math162;
#line 0 ""
    sjf_vec3(_return);
}

void sjf_vec3_cross_heap(sjs_vec3* _parent, sjs_vec3* v, sjs_vec3_heap** _return) {
    sjs_vec3* sjt_dot129;
    sjs_vec3* sjt_dot130;
    sjs_vec3* sjt_dot131;
    sjs_vec3* sjt_dot132;
    sjs_vec3* sjt_dot133;
    sjs_vec3* sjt_dot134;
    sjs_vec3* sjt_dot135;
    sjs_vec3* sjt_dot136;
    sjs_vec3* sjt_dot137;
    sjs_vec3* sjt_dot138;
    sjs_vec3* sjt_dot139;
    sjs_vec3* sjt_dot140;
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
    float sjt_math183;
    float sjt_math184;

    (*_return) = (sjs_vec3_heap*)malloc(sizeof(sjs_vec3_heap));
    (*_return)->_refCount = 1;
#line 38 ".\..\lib\ui\vec3.sj"
    sjt_dot129 = _parent;
#line 40
    sjt_math169 = (sjt_dot129)->y;
#line 38
    sjt_dot130 = v;
#line 40
    sjt_math170 = (sjt_dot130)->z;
#line 40
    sjt_math167 = sjt_math169 * sjt_math170;
#line 38
    sjt_dot131 = _parent;
#line 40
    sjt_math171 = (sjt_dot131)->z;
#line 38
    sjt_dot132 = v;
#line 40
    sjt_math172 = (sjt_dot132)->y;
#line 40
    sjt_math168 = sjt_math171 * sjt_math172;
#line 40
    (*_return)->x = sjt_math167 - sjt_math168;
#line 38
    sjt_dot133 = _parent;
#line 41
    sjt_math175 = (sjt_dot133)->z;
#line 38
    sjt_dot134 = v;
#line 41
    sjt_math176 = (sjt_dot134)->x;
#line 41
    sjt_math173 = sjt_math175 * sjt_math176;
#line 38
    sjt_dot135 = _parent;
#line 41
    sjt_math177 = (sjt_dot135)->x;
#line 38
    sjt_dot136 = v;
#line 41
    sjt_math178 = (sjt_dot136)->z;
#line 41
    sjt_math174 = sjt_math177 * sjt_math178;
#line 41
    (*_return)->y = sjt_math173 - sjt_math174;
#line 38
    sjt_dot137 = _parent;
#line 42
    sjt_math181 = (sjt_dot137)->x;
#line 38
    sjt_dot138 = v;
#line 42
    sjt_math182 = (sjt_dot138)->y;
#line 42
    sjt_math179 = sjt_math181 * sjt_math182;
#line 38
    sjt_dot139 = _parent;
#line 42
    sjt_math183 = (sjt_dot139)->y;
#line 38
    sjt_dot140 = v;
#line 42
    sjt_math184 = (sjt_dot140)->x;
#line 42
    sjt_math180 = sjt_math183 * sjt_math184;
#line 42
    (*_return)->z = sjt_math179 - sjt_math180;
#line 0 ""
    sjf_vec3_heap((*_return));
}

void sjf_vec3_destroy(sjs_vec3* _this) {
}

void sjf_vec3_dot(sjs_vec3* _parent, sjs_vec3* v, float* _return) {
    sjs_vec3* sjt_dot150;
    sjs_vec3* sjt_dot151;
    sjs_vec3* sjt_dot152;
    sjs_vec3* sjt_dot153;
    sjs_vec3* sjt_dot154;
    sjs_vec3* sjt_dot155;
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

#line 46 ".\..\lib\ui\vec3.sj"
    sjt_dot150 = _parent;
#line 47
    sjt_math191 = (sjt_dot150)->x;
#line 46
    sjt_dot151 = v;
#line 47
    sjt_math192 = (sjt_dot151)->x;
#line 47
    sjt_math189 = sjt_math191 * sjt_math192;
#line 46
    sjt_dot152 = _parent;
#line 47
    sjt_math193 = (sjt_dot152)->y;
#line 46
    sjt_dot153 = v;
#line 47
    sjt_math194 = (sjt_dot153)->y;
#line 47
    sjt_math190 = sjt_math193 * sjt_math194;
#line 47
    sjt_math187 = sjt_math189 + sjt_math190;
#line 46
    sjt_dot154 = _parent;
#line 47
    sjt_math195 = (sjt_dot154)->z;
#line 46
    sjt_dot155 = v;
#line 47
    sjt_math196 = (sjt_dot155)->z;
#line 47
    sjt_math188 = sjt_math195 * sjt_math196;
#line 47
    (*_return) = sjt_math187 + sjt_math188;
}

void sjf_vec3_heap(sjs_vec3_heap* _this) {
}

void sjf_vec3_interpolate(sjs_vec3* _parent, sjs_vec3* v, float percent, sjs_vec3* _return) {
    sjs_vec3* sjt_dot33;
    sjs_vec3* sjt_dot34;
    sjs_vec3* sjt_dot35;
    sjs_vec3* sjt_dot36;
    sjs_vec3* sjt_dot37;
    sjs_vec3* sjt_dot38;
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

#line 10 ".\..\lib\ui\vec3.sj"
    sjt_dot33 = _parent;
#line 12
    sjt_math15 = (sjt_dot33)->x;
#line 12
    sjt_math17 = 1.0f;
#line 10
    sjt_math18 = percent;
#line 12
    sjt_math16 = sjt_math17 - sjt_math18;
#line 12
    sjt_math13 = sjt_math15 * sjt_math16;
#line 10
    sjt_dot34 = v;
#line 12
    sjt_math19 = (sjt_dot34)->x;
#line 10
    sjt_math20 = percent;
#line 12
    sjt_math14 = sjt_math19 * sjt_math20;
#line 12
    _return->x = sjt_math13 + sjt_math14;
#line 10
    sjt_dot35 = _parent;
#line 13
    sjt_math23 = (sjt_dot35)->y;
#line 13
    sjt_math25 = 1.0f;
#line 10
    sjt_math26 = percent;
#line 13
    sjt_math24 = sjt_math25 - sjt_math26;
#line 13
    sjt_math21 = sjt_math23 * sjt_math24;
#line 10
    sjt_dot36 = v;
#line 13
    sjt_math27 = (sjt_dot36)->y;
#line 10
    sjt_math28 = percent;
#line 13
    sjt_math22 = sjt_math27 * sjt_math28;
#line 13
    _return->y = sjt_math21 + sjt_math22;
#line 10
    sjt_dot37 = _parent;
#line 14
    sjt_math31 = (sjt_dot37)->z;
#line 14
    sjt_math33 = 1.0f;
#line 10
    sjt_math34 = percent;
#line 14
    sjt_math32 = sjt_math33 - sjt_math34;
#line 14
    sjt_math29 = sjt_math31 * sjt_math32;
#line 10
    sjt_dot38 = v;
#line 14
    sjt_math35 = (sjt_dot38)->z;
#line 10
    sjt_math36 = percent;
#line 14
    sjt_math30 = sjt_math35 * sjt_math36;
#line 14
    _return->z = sjt_math29 + sjt_math30;
#line 0 ""
    sjf_vec3(_return);
}

void sjf_vec3_interpolate_heap(sjs_vec3* _parent, sjs_vec3* v, float percent, sjs_vec3_heap** _return) {
    sjs_vec3* sjt_dot39;
    sjs_vec3* sjt_dot40;
    sjs_vec3* sjt_dot41;
    sjs_vec3* sjt_dot42;
    sjs_vec3* sjt_dot43;
    sjs_vec3* sjt_dot44;
    float sjt_math37;
    float sjt_math38;
    float sjt_math39;
    float sjt_math40;
    float sjt_math41;
    float sjt_math42;
    float sjt_math43;
    float sjt_math44;
    float sjt_math45;
    float sjt_math46;
    float sjt_math47;
    float sjt_math48;
    float sjt_math49;
    float sjt_math50;
    float sjt_math51;
    float sjt_math52;
    float sjt_math53;
    float sjt_math54;
    float sjt_math55;
    float sjt_math56;
    float sjt_math57;
    float sjt_math58;
    float sjt_math59;
    float sjt_math60;

    (*_return) = (sjs_vec3_heap*)malloc(sizeof(sjs_vec3_heap));
    (*_return)->_refCount = 1;
#line 10 ".\..\lib\ui\vec3.sj"
    sjt_dot39 = _parent;
#line 12
    sjt_math39 = (sjt_dot39)->x;
#line 12
    sjt_math41 = 1.0f;
#line 10
    sjt_math42 = percent;
#line 12
    sjt_math40 = sjt_math41 - sjt_math42;
#line 12
    sjt_math37 = sjt_math39 * sjt_math40;
#line 10
    sjt_dot40 = v;
#line 12
    sjt_math43 = (sjt_dot40)->x;
#line 10
    sjt_math44 = percent;
#line 12
    sjt_math38 = sjt_math43 * sjt_math44;
#line 12
    (*_return)->x = sjt_math37 + sjt_math38;
#line 10
    sjt_dot41 = _parent;
#line 13
    sjt_math47 = (sjt_dot41)->y;
#line 13
    sjt_math49 = 1.0f;
#line 10
    sjt_math50 = percent;
#line 13
    sjt_math48 = sjt_math49 - sjt_math50;
#line 13
    sjt_math45 = sjt_math47 * sjt_math48;
#line 10
    sjt_dot42 = v;
#line 13
    sjt_math51 = (sjt_dot42)->y;
#line 10
    sjt_math52 = percent;
#line 13
    sjt_math46 = sjt_math51 * sjt_math52;
#line 13
    (*_return)->y = sjt_math45 + sjt_math46;
#line 10
    sjt_dot43 = _parent;
#line 14
    sjt_math55 = (sjt_dot43)->z;
#line 14
    sjt_math57 = 1.0f;
#line 10
    sjt_math58 = percent;
#line 14
    sjt_math56 = sjt_math57 - sjt_math58;
#line 14
    sjt_math53 = sjt_math55 * sjt_math56;
#line 10
    sjt_dot44 = v;
#line 14
    sjt_math59 = (sjt_dot44)->z;
#line 10
    sjt_math60 = percent;
#line 14
    sjt_math54 = sjt_math59 * sjt_math60;
#line 14
    (*_return)->z = sjt_math53 + sjt_math54;
#line 0 ""
    sjf_vec3_heap((*_return));
}

void sjf_vec3_isEqual(sjs_vec3* _parent, sjs_vec3* v, bool* _return) {
    bool sjt_and1;
    bool sjt_and2;
    bool sjt_and3;
    bool sjt_and4;
    float sjt_compare11;
    float sjt_compare12;
    float sjt_compare13;
    float sjt_compare14;
    float sjt_compare15;
    float sjt_compare16;
    sjs_vec3* sjt_dot50;
    sjs_vec3* sjt_dot51;
    sjs_vec3* sjt_dot52;
    sjs_vec3* sjt_dot53;
    sjs_vec3* sjt_dot54;
    sjs_vec3* sjt_dot55;

#line 6 ".\..\lib\ui\vec3.sj"
    sjt_dot50 = _parent;
#line 7
    sjt_compare11 = (sjt_dot50)->x;
#line 6
    sjt_dot51 = v;
#line 7
    sjt_compare12 = (sjt_dot51)->x;
#line 7
    sjt_and1 = sjt_compare11 == sjt_compare12;
#line 6
    sjt_dot52 = _parent;
#line 7
    sjt_compare13 = (sjt_dot52)->y;
#line 6
    sjt_dot53 = v;
#line 7
    sjt_compare14 = (sjt_dot53)->y;
#line 7
    sjt_and3 = sjt_compare13 == sjt_compare14;
#line 6
    sjt_dot54 = _parent;
#line 7
    sjt_compare15 = (sjt_dot54)->z;
#line 6
    sjt_dot55 = v;
#line 7
    sjt_compare16 = (sjt_dot55)->z;
#line 7
    sjt_and4 = sjt_compare15 == sjt_compare16;
#line 7
    sjt_and2 = sjt_and3 && sjt_and4;
#line 7
    (*_return) = sjt_and1 && sjt_and2;
}

void sjf_vec3_normalize(sjs_vec3* _parent, sjs_vec3* _return) {
    sjs_vec3* sjt_dot100;
    sjs_vec3* sjt_dot101;
    sjs_vec3* sjt_dot102;
    sjs_vec3* sjt_dot103;
    sjs_vec3* sjt_dot104;
    sjs_vec3* sjt_dot105;
    sjs_vec3* sjt_dot106;
    sjs_vec3* sjt_dot107;
    sjs_vec3* sjt_dot99;
    float sjt_functionParam29;
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
    float sjt_math131;
    float sjt_math132;
    float sjv_t;

#line 29 ".\..\lib\ui\vec3.sj"
    sjt_dot99 = _parent;
#line 30
    sjt_math121 = (sjt_dot99)->x;
#line 29
    sjt_dot100 = _parent;
#line 30
    sjt_math122 = (sjt_dot100)->x;
#line 30
    sjt_math119 = sjt_math121 * sjt_math122;
#line 29
    sjt_dot101 = _parent;
#line 30
    sjt_math123 = (sjt_dot101)->y;
#line 29
    sjt_dot102 = _parent;
#line 30
    sjt_math124 = (sjt_dot102)->y;
#line 30
    sjt_math120 = sjt_math123 * sjt_math124;
#line 30
    sjt_math117 = sjt_math119 + sjt_math120;
#line 29
    sjt_dot103 = _parent;
#line 30
    sjt_math125 = (sjt_dot103)->z;
#line 29
    sjt_dot104 = _parent;
#line 30
    sjt_math126 = (sjt_dot104)->z;
#line 30
    sjt_math118 = sjt_math125 * sjt_math126;
#line 30
    sjt_functionParam29 = sjt_math117 + sjt_math118;
#line 0 ""
    sjf_f32_sqrt(sjt_functionParam29, &sjv_t);
#line 29 ".\..\lib\ui\vec3.sj"
    sjt_dot105 = _parent;
#line 32
    sjt_math127 = (sjt_dot105)->x;
#line 32
    sjt_math128 = sjv_t;
#line 32
    _return->x = sjt_math127 / sjt_math128;
#line 29
    sjt_dot106 = _parent;
#line 33
    sjt_math129 = (sjt_dot106)->y;
#line 33
    sjt_math130 = sjv_t;
#line 33
    _return->y = sjt_math129 / sjt_math130;
#line 29
    sjt_dot107 = _parent;
#line 34
    sjt_math131 = (sjt_dot107)->z;
#line 34
    sjt_math132 = sjv_t;
#line 34
    _return->z = sjt_math131 / sjt_math132;
#line 0 ""
    sjf_vec3(_return);
}

void sjf_vec3_normalize_heap(sjs_vec3* _parent, sjs_vec3_heap** _return) {
    sjs_vec3* sjt_dot108;
    sjs_vec3* sjt_dot109;
    sjs_vec3* sjt_dot110;
    sjs_vec3* sjt_dot111;
    sjs_vec3* sjt_dot112;
    sjs_vec3* sjt_dot113;
    sjs_vec3* sjt_dot114;
    sjs_vec3* sjt_dot115;
    sjs_vec3* sjt_dot116;
    float sjt_functionParam30;
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
    float sjt_math147;
    float sjt_math148;
    float sjv_t;

#line 29 ".\..\lib\ui\vec3.sj"
    sjt_dot108 = _parent;
#line 30
    sjt_math137 = (sjt_dot108)->x;
#line 29
    sjt_dot109 = _parent;
#line 30
    sjt_math138 = (sjt_dot109)->x;
#line 30
    sjt_math135 = sjt_math137 * sjt_math138;
#line 29
    sjt_dot110 = _parent;
#line 30
    sjt_math139 = (sjt_dot110)->y;
#line 29
    sjt_dot111 = _parent;
#line 30
    sjt_math140 = (sjt_dot111)->y;
#line 30
    sjt_math136 = sjt_math139 * sjt_math140;
#line 30
    sjt_math133 = sjt_math135 + sjt_math136;
#line 29
    sjt_dot112 = _parent;
#line 30
    sjt_math141 = (sjt_dot112)->z;
#line 29
    sjt_dot113 = _parent;
#line 30
    sjt_math142 = (sjt_dot113)->z;
#line 30
    sjt_math134 = sjt_math141 * sjt_math142;
#line 30
    sjt_functionParam30 = sjt_math133 + sjt_math134;
#line 0 ""
    sjf_f32_sqrt(sjt_functionParam30, &sjv_t);
    (*_return) = (sjs_vec3_heap*)malloc(sizeof(sjs_vec3_heap));
    (*_return)->_refCount = 1;
#line 29 ".\..\lib\ui\vec3.sj"
    sjt_dot114 = _parent;
#line 32
    sjt_math143 = (sjt_dot114)->x;
#line 32
    sjt_math144 = sjv_t;
#line 32
    (*_return)->x = sjt_math143 / sjt_math144;
#line 29
    sjt_dot115 = _parent;
#line 33
    sjt_math145 = (sjt_dot115)->y;
#line 33
    sjt_math146 = sjv_t;
#line 33
    (*_return)->y = sjt_math145 / sjt_math146;
#line 29
    sjt_dot116 = _parent;
#line 34
    sjt_math147 = (sjt_dot116)->z;
#line 34
    sjt_math148 = sjv_t;
#line 34
    (*_return)->z = sjt_math147 / sjt_math148;
#line 0 ""
    sjf_vec3_heap((*_return));
}

void sjf_vec3_subtract(sjs_vec3* _parent, sjs_vec3* v, sjs_vec3* _return) {
    sjs_vec3* sjt_dot87;
    sjs_vec3* sjt_dot88;
    sjs_vec3* sjt_dot89;
    sjs_vec3* sjt_dot90;
    sjs_vec3* sjt_dot91;
    sjs_vec3* sjt_dot92;
    float sjt_math105;
    float sjt_math106;
    float sjt_math107;
    float sjt_math108;
    float sjt_math109;
    float sjt_math110;

#line 21 ".\..\lib\ui\vec3.sj"
    sjt_dot87 = _parent;
#line 23
    sjt_math105 = (sjt_dot87)->x;
#line 21
    sjt_dot88 = v;
#line 23
    sjt_math106 = (sjt_dot88)->x;
#line 23
    _return->x = sjt_math105 - sjt_math106;
#line 21
    sjt_dot89 = _parent;
#line 24
    sjt_math107 = (sjt_dot89)->y;
#line 21
    sjt_dot90 = v;
#line 24
    sjt_math108 = (sjt_dot90)->y;
#line 24
    _return->y = sjt_math107 - sjt_math108;
#line 21
    sjt_dot91 = _parent;
#line 25
    sjt_math109 = (sjt_dot91)->z;
#line 21
    sjt_dot92 = v;
#line 25
    sjt_math110 = (sjt_dot92)->z;
#line 25
    _return->z = sjt_math109 - sjt_math110;
#line 0 ""
    sjf_vec3(_return);
}

void sjf_vec3_subtract_heap(sjs_vec3* _parent, sjs_vec3* v, sjs_vec3_heap** _return) {
    sjs_vec3* sjt_dot93;
    sjs_vec3* sjt_dot94;
    sjs_vec3* sjt_dot95;
    sjs_vec3* sjt_dot96;
    sjs_vec3* sjt_dot97;
    sjs_vec3* sjt_dot98;
    float sjt_math111;
    float sjt_math112;
    float sjt_math113;
    float sjt_math114;
    float sjt_math115;
    float sjt_math116;

    (*_return) = (sjs_vec3_heap*)malloc(sizeof(sjs_vec3_heap));
    (*_return)->_refCount = 1;
#line 21 ".\..\lib\ui\vec3.sj"
    sjt_dot93 = _parent;
#line 23
    sjt_math111 = (sjt_dot93)->x;
#line 21
    sjt_dot94 = v;
#line 23
    sjt_math112 = (sjt_dot94)->x;
#line 23
    (*_return)->x = sjt_math111 - sjt_math112;
#line 21
    sjt_dot95 = _parent;
#line 24
    sjt_math113 = (sjt_dot95)->y;
#line 21
    sjt_dot96 = v;
#line 24
    sjt_math114 = (sjt_dot96)->y;
#line 24
    (*_return)->y = sjt_math113 - sjt_math114;
#line 21
    sjt_dot97 = _parent;
#line 25
    sjt_math115 = (sjt_dot97)->z;
#line 21
    sjt_dot98 = v;
#line 25
    sjt_math116 = (sjt_dot98)->z;
#line 25
    (*_return)->z = sjt_math115 - sjt_math116;
#line 0 ""
    sjf_vec3_heap((*_return));
}

void sjf_vertexBuffer_vertex_location_texture_normal(sjs_vertexBuffer_vertex_location_texture_normal* _this) {
#line 95 ".\..\lib\ui\vertexBuffer.sj"
    _this->buffer = vertex_buffer_new((char*)_this->format.data.data);
#line 95
    vertex_buffer_push_back_indices(_this->buffer, (GLuint*)_this->indices.data, _this->indices.size);
#line 95
    vertex_buffer_push_back_vertices(_this->buffer, (sjs_vertex_location_texture_normal*)_this->vertices.data, _this->vertices.size);
}

void sjf_vertexBuffer_vertex_location_texture_normal_copy(sjs_vertexBuffer_vertex_location_texture_normal* _this, sjs_vertexBuffer_vertex_location_texture_normal* _from) {
#line 7 ".\..\lib\ui\vertexBuffer.sj"
    sjf_string_copy(&_this->format, &_from->format);
#line 7
    sjf_array_i32_copy(&_this->indices, &_from->indices);
#line 7
    sjf_array_vertex_location_texture_normal_copy(&_this->vertices, &_from->vertices);
#line 102
    _this->buffer = _from->buffer;
#line 102
    _retain(_this->buffer);
}

void sjf_vertexBuffer_vertex_location_texture_normal_destroy(sjs_vertexBuffer_vertex_location_texture_normal* _this) {
#line 107 ".\..\lib\ui\vertexBuffer.sj"
    if (_release(_this->buffer)) {
#line 107
        vertex_buffer_delete(_this->buffer);
#line 107
    }
}

void sjf_vertexBuffer_vertex_location_texture_normal_heap(sjs_vertexBuffer_vertex_location_texture_normal_heap* _this) {
#line 95 ".\..\lib\ui\vertexBuffer.sj"
    _this->buffer = vertex_buffer_new((char*)_this->format.data.data);
#line 95
    vertex_buffer_push_back_indices(_this->buffer, (GLuint*)_this->indices.data, _this->indices.size);
#line 95
    vertex_buffer_push_back_vertices(_this->buffer, (sjs_vertex_location_texture_normal*)_this->vertices.data, _this->vertices.size);
}

void sjf_vertexBuffer_vertex_location_texture_normal_render(sjs_vertexBuffer_vertex_location_texture_normal* _parent) {
#line 89 ".\..\lib\ui\vertexBuffer.sj"
    vertex_buffer_render(_parent->buffer, GL_TRIANGLES);
}

void sjf_vertexBuffer_vertex_location_texture_normal_translateScreenToTexture_heap(sjs_vertexBuffer_vertex_location_texture_normal* _parent, sjs_point* screen, sjs_rect* viewport, sjs_mat4* projection, sjs_mat4* view, sjs_mat4* world, sjs_vec2_heap** _return) {
    int32_t i;
    int32_t sjt_cast14;
    int32_t sjt_cast15;
    int32_t sjt_cast16;
    int32_t sjt_cast17;
    int32_t sjt_compare33;
    int32_t sjt_compare34;
    sjs_point* sjt_dot1217;
    sjs_rect* sjt_dot1218;
    sjs_rect* sjt_dot1219;
    sjs_point* sjt_dot1220;
    sjs_rect* sjt_dot1221;
    sjs_rect* sjt_dot1222;
    sjs_vec2* sjt_dot1223;
    sjs_mat4* sjt_dot1224;
    sjs_vec2* sjt_dot1225;
    sjs_mat4* sjt_dot1226;
    sjs_vec3* sjt_dot1227;
    sjs_mat4* sjt_dot1228;
    sjs_vec3* sjt_dot1229;
    sjs_mat4* sjt_dot1230;
    sjs_vec3* sjt_dot1231;
    sjs_mat4* sjt_dot1232;
    sjs_vec3* sjt_dot1233;
    sjs_mat4* sjt_dot1234;
    sjs_vec3* sjt_dot1235;
    sjs_mat4* sjt_dot1236;
    sjs_vec3* sjt_dot1237;
    sjs_mat4* sjt_dot1238;
    sjs_vec3* sjt_dot1239;
    sjs_mat4* sjt_dot1240;
    sjs_vec3* sjt_dot1241;
    sjs_mat4* sjt_dot1242;
    sjs_vec3* sjt_dot1243;
    sjs_mat4* sjt_dot1244;
    sjs_mat4* sjt_dot1245;
    sjs_mat4* sjt_dot1246;
    sjs_mat4* sjt_dot1247;
    sjs_array_i32* sjt_dot1248;
    sjs_vertexBuffer_vertex_location_texture_normal* sjt_dot1249;
    int32_t sjt_forEnd10;
    int32_t sjt_forStart10;
    sjs_mat4* sjt_functionParam81;
    bool sjt_ifElse13;
    float sjt_math2295;
    float sjt_math2296;
    float sjt_math2297;
    float sjt_math2298;
    float sjt_math2299;
    float sjt_math2300;
    int32_t sjt_math2301;
    int32_t sjt_math2302;
    float sjt_math2303;
    float sjt_math2304;
    float sjt_math2305;
    float sjt_math2306;
    float sjt_math2307;
    float sjt_math2308;
    int32_t sjt_math2309;
    int32_t sjt_math2310;
    float sjt_math2311;
    float sjt_math2312;
    float sjt_math2313;
    float sjt_math2314;
    float sjt_math2315;
    float sjt_math2316;
    float sjt_math2317;
    float sjt_math2318;
    float sjt_math2319;
    float sjt_math2320;
    float sjt_math2321;
    float sjt_math2322;
    float sjt_math2323;
    float sjt_math2324;
    float sjt_math2325;
    float sjt_math2326;
    float sjt_math2327;
    float sjt_math2328;
    float sjt_math2329;
    float sjt_math2330;
    float sjt_math2331;
    float sjt_math2332;
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
    sjs_mat4* sjt_parent58;
    sjs_mat4* sjt_parent59;
    int32_t sjv_cTriangles;
    sjs_vec3_heap* sjv_intersection;
    sjs_mat4 sjv_m;
    sjs_vec2 sjv_start;
    sjs_vec2_heap* sjv_texture;
    sjs_vec3 sjv_v;
    sjs_vec3 sjv_vPickRayDir;
    sjs_vec3 sjv_vPickRayOrig;
    sjs_mat4 sjv_worldView;

#line 38 ".\..\lib\ui\vertexBuffer.sj"
    sjv_intersection = 0;
    if (sjv_intersection != 0) {
        sjv_intersection->_refCount++;
    }

#line 39
    sjv_texture = 0;
    if (sjv_texture != 0) {
        sjv_texture->_refCount++;
    }

#line 37
    sjt_dot1217 = screen;
#line 43
    sjt_math2301 = (sjt_dot1217)->x;
#line 37
    sjt_dot1218 = viewport;
#line 43
    sjt_math2302 = (sjt_dot1218)->x;
#line 43
    sjt_cast14 = sjt_math2301 - sjt_math2302;
#line 43
    sjt_math2299 = (float)sjt_cast14;
#line 37
    sjt_dot1219 = viewport;
#line 43
    sjt_cast15 = (sjt_dot1219)->w;
#line 43
    sjt_math2300 = (float)sjt_cast15;
#line 43
    sjt_math2297 = sjt_math2299 / sjt_math2300;
#line 43
    sjt_math2298 = 2.0f;
#line 43
    sjt_math2295 = sjt_math2297 * sjt_math2298;
#line 43
    sjt_math2296 = 1.0f;
#line 43
    sjv_start.x = sjt_math2295 - sjt_math2296;
#line 37
    sjt_dot1220 = screen;
#line 44
    sjt_math2309 = (sjt_dot1220)->y;
#line 37
    sjt_dot1221 = viewport;
#line 44
    sjt_math2310 = (sjt_dot1221)->y;
#line 44
    sjt_cast16 = sjt_math2309 - sjt_math2310;
#line 44
    sjt_math2307 = (float)sjt_cast16;
#line 37
    sjt_dot1222 = viewport;
#line 44
    sjt_cast17 = (sjt_dot1222)->h;
#line 44
    sjt_math2308 = (float)sjt_cast17;
#line 44
    sjt_math2305 = sjt_math2307 / sjt_math2308;
#line 44
    sjt_math2306 = 2.0f;
#line 44
    sjt_math2303 = sjt_math2305 * sjt_math2306;
#line 44
    sjt_math2304 = 1.0f;
#line 44
    sjv_start.y = sjt_math2303 - sjt_math2304;
#line 0 ""
    sjf_vec2(&sjv_start);
#line 1 ".\..\lib\ui\vec2.sj"
    sjt_dot1223 = &sjv_start;
#line 45 ".\..\lib\ui\vertexBuffer.sj"
    sjt_math2311 = (sjt_dot1223)->x;
#line 37
    sjt_dot1224 = projection;
#line 45
    sjt_math2312 = (sjt_dot1224)->m00;
#line 45
    sjv_v.x = sjt_math2311 / sjt_math2312;
#line 1 ".\..\lib\ui\vec2.sj"
    sjt_dot1225 = &sjv_start;
#line 45 ".\..\lib\ui\vertexBuffer.sj"
    sjt_math2313 = (sjt_dot1225)->y;
#line 37
    sjt_dot1226 = projection;
#line 45
    sjt_math2314 = (sjt_dot1226)->m11;
#line 45
    sjv_v.y = sjt_math2313 / sjt_math2314;
#line 45
    sjv_v.z = 1.0f;
#line 0 ""
    sjf_vec3(&sjv_v);
#line 37 ".\..\lib\ui\vertexBuffer.sj"
    sjt_parent58 = view;
#line 37
    sjt_functionParam81 = world;
#line 0 ""
    sjf_mat4_multiply(sjt_parent58, sjt_functionParam81, &sjv_worldView);
#line 61 ".\..\lib\ui\mat4.sj"
    sjt_parent59 = &sjv_worldView;
#line 0 ""
    sjf_mat4_invert(sjt_parent59, &sjv_m);
#line 1 ".\..\lib\ui\vec3.sj"
    sjt_dot1227 = &sjv_v;
#line 53 ".\..\lib\ui\vertexBuffer.sj"
    sjt_math2319 = (sjt_dot1227)->x;
#line 1 ".\..\lib\ui\mat4.sj"
    sjt_dot1228 = &sjv_m;
#line 53 ".\..\lib\ui\vertexBuffer.sj"
    sjt_math2320 = (sjt_dot1228)->m00;
#line 53
    sjt_math2317 = sjt_math2319 * sjt_math2320;
#line 1 ".\..\lib\ui\vec3.sj"
    sjt_dot1229 = &sjv_v;
#line 53 ".\..\lib\ui\vertexBuffer.sj"
    sjt_math2321 = (sjt_dot1229)->y;
#line 1 ".\..\lib\ui\mat4.sj"
    sjt_dot1230 = &sjv_m;
#line 53 ".\..\lib\ui\vertexBuffer.sj"
    sjt_math2322 = (sjt_dot1230)->m10;
#line 53
    sjt_math2318 = sjt_math2321 * sjt_math2322;
#line 53
    sjt_math2315 = sjt_math2317 + sjt_math2318;
#line 1 ".\..\lib\ui\vec3.sj"
    sjt_dot1231 = &sjv_v;
#line 53 ".\..\lib\ui\vertexBuffer.sj"
    sjt_math2323 = (sjt_dot1231)->z;
#line 1 ".\..\lib\ui\mat4.sj"
    sjt_dot1232 = &sjv_m;
#line 53 ".\..\lib\ui\vertexBuffer.sj"
    sjt_math2324 = (sjt_dot1232)->m20;
#line 53
    sjt_math2316 = sjt_math2323 * sjt_math2324;
#line 53
    sjv_vPickRayDir.x = sjt_math2315 + sjt_math2316;
#line 1 ".\..\lib\ui\vec3.sj"
    sjt_dot1233 = &sjv_v;
#line 54 ".\..\lib\ui\vertexBuffer.sj"
    sjt_math2329 = (sjt_dot1233)->x;
#line 1 ".\..\lib\ui\mat4.sj"
    sjt_dot1234 = &sjv_m;
#line 54 ".\..\lib\ui\vertexBuffer.sj"
    sjt_math2330 = (sjt_dot1234)->m01;
#line 54
    sjt_math2327 = sjt_math2329 * sjt_math2330;
#line 1 ".\..\lib\ui\vec3.sj"
    sjt_dot1235 = &sjv_v;
#line 54 ".\..\lib\ui\vertexBuffer.sj"
    sjt_math2331 = (sjt_dot1235)->y;
#line 1 ".\..\lib\ui\mat4.sj"
    sjt_dot1236 = &sjv_m;
#line 54 ".\..\lib\ui\vertexBuffer.sj"
    sjt_math2332 = (sjt_dot1236)->m11;
#line 54
    sjt_math2328 = sjt_math2331 * sjt_math2332;
#line 54
    sjt_math2325 = sjt_math2327 + sjt_math2328;
#line 1 ".\..\lib\ui\vec3.sj"
    sjt_dot1237 = &sjv_v;
#line 54 ".\..\lib\ui\vertexBuffer.sj"
    sjt_math2333 = (sjt_dot1237)->z;
#line 1 ".\..\lib\ui\mat4.sj"
    sjt_dot1238 = &sjv_m;
#line 54 ".\..\lib\ui\vertexBuffer.sj"
    sjt_math2334 = (sjt_dot1238)->m21;
#line 54
    sjt_math2326 = sjt_math2333 * sjt_math2334;
#line 54
    sjv_vPickRayDir.y = sjt_math2325 + sjt_math2326;
#line 1 ".\..\lib\ui\vec3.sj"
    sjt_dot1239 = &sjv_v;
#line 55 ".\..\lib\ui\vertexBuffer.sj"
    sjt_math2339 = (sjt_dot1239)->x;
#line 1 ".\..\lib\ui\mat4.sj"
    sjt_dot1240 = &sjv_m;
#line 55 ".\..\lib\ui\vertexBuffer.sj"
    sjt_math2340 = (sjt_dot1240)->m02;
#line 55
    sjt_math2337 = sjt_math2339 * sjt_math2340;
#line 1 ".\..\lib\ui\vec3.sj"
    sjt_dot1241 = &sjv_v;
#line 55 ".\..\lib\ui\vertexBuffer.sj"
    sjt_math2341 = (sjt_dot1241)->y;
#line 1 ".\..\lib\ui\mat4.sj"
    sjt_dot1242 = &sjv_m;
#line 55 ".\..\lib\ui\vertexBuffer.sj"
    sjt_math2342 = (sjt_dot1242)->m12;
#line 55
    sjt_math2338 = sjt_math2341 * sjt_math2342;
#line 55
    sjt_math2335 = sjt_math2337 + sjt_math2338;
#line 1 ".\..\lib\ui\vec3.sj"
    sjt_dot1243 = &sjv_v;
#line 55 ".\..\lib\ui\vertexBuffer.sj"
    sjt_math2343 = (sjt_dot1243)->z;
#line 1 ".\..\lib\ui\mat4.sj"
    sjt_dot1244 = &sjv_m;
#line 55 ".\..\lib\ui\vertexBuffer.sj"
    sjt_math2344 = (sjt_dot1244)->m22;
#line 55
    sjt_math2336 = sjt_math2343 * sjt_math2344;
#line 55
    sjv_vPickRayDir.z = sjt_math2335 + sjt_math2336;
#line 0 ""
    sjf_vec3(&sjv_vPickRayDir);
#line 1 ".\..\lib\ui\mat4.sj"
    sjt_dot1245 = &sjv_m;
#line 56 ".\..\lib\ui\vertexBuffer.sj"
    sjv_vPickRayOrig.x = (sjt_dot1245)->m30;
#line 1 ".\..\lib\ui\mat4.sj"
    sjt_dot1246 = &sjv_m;
#line 56 ".\..\lib\ui\vertexBuffer.sj"
    sjv_vPickRayOrig.y = (sjt_dot1246)->m31;
#line 1 ".\..\lib\ui\mat4.sj"
    sjt_dot1247 = &sjv_m;
#line 56 ".\..\lib\ui\vertexBuffer.sj"
    sjv_vPickRayOrig.z = (sjt_dot1247)->m32;
#line 0 ""
    sjf_vec3(&sjv_vPickRayOrig);
#line 37 ".\..\lib\ui\vertexBuffer.sj"
    sjt_dot1249 = _parent;
#line 1 ".\..\lib\common\array.sj"
    sjt_dot1248 = &(sjt_dot1249)->indices;
#line 58 ".\..\lib\ui\vertexBuffer.sj"
    sjt_compare33 = (sjt_dot1248)->size;
#line 58
    sjt_compare34 = 0;
#line 58
    sjt_ifElse13 = sjt_compare33 > sjt_compare34;
    if (sjt_ifElse13) {
        sjs_array_i32* sjt_dot1250;
        sjs_vertexBuffer_vertex_location_texture_normal* sjt_dot1251;
        int32_t sjt_math2345;
        int32_t sjt_math2346;

#line 37 ".\..\lib\ui\vertexBuffer.sj"
        sjt_dot1251 = _parent;
#line 1 ".\..\lib\common\array.sj"
        sjt_dot1250 = &(sjt_dot1251)->indices;
#line 58 ".\..\lib\ui\vertexBuffer.sj"
        sjt_math2345 = (sjt_dot1250)->size;
#line 58
        sjt_math2346 = 3;
#line 58
        sjv_cTriangles = sjt_math2345 / sjt_math2346;
    } else {
        sjs_array_vertex_location_texture_normal* sjt_dot1252;
        sjs_vertexBuffer_vertex_location_texture_normal* sjt_dot1253;
        int32_t sjt_math2347;
        int32_t sjt_math2348;

#line 37 ".\..\lib\ui\vertexBuffer.sj"
        sjt_dot1253 = _parent;
#line 1 ".\..\lib\common\array.sj"
        sjt_dot1252 = &(sjt_dot1253)->vertices;
#line 58 ".\..\lib\ui\vertexBuffer.sj"
        sjt_math2347 = (sjt_dot1252)->size;
#line 58
        sjt_math2348 = 3;
#line 58
        sjv_cTriangles = sjt_math2347 / sjt_math2348;
    }

#line 59
    sjt_forStart10 = 0;
#line 59
    i = sjt_forStart10;
#line 59
    sjt_forEnd10 = sjv_cTriangles;
    while (i < sjt_forEnd10) {
        bool result12;
        int32_t sjt_compare35;
        int32_t sjt_compare36;
        int32_t sjt_compare37;
        int32_t sjt_compare38;
        int32_t sjt_compare39;
        int32_t sjt_compare40;
        sjs_array_i32* sjt_dot1254;
        sjs_vertexBuffer_vertex_location_texture_normal* sjt_dot1255;
        sjs_array_i32* sjt_dot1259;
        sjs_vertexBuffer_vertex_location_texture_normal* sjt_dot1260;
        sjs_array_i32* sjt_dot1264;
        sjs_vertexBuffer_vertex_location_texture_normal* sjt_dot1265;
        sjs_vertex_location_texture_normal* sjt_dot1269;
        sjs_vertex_location_texture_normal* sjt_dot1270;
        sjs_vertex_location_texture_normal* sjt_dot1271;
        sjs_vec3* sjt_functionParam101;
        sjs_vec3* sjt_functionParam102;
        sjs_vec3* sjt_functionParam103;
        sjs_vec3* sjt_functionParam104;
        sjs_vec3* sjt_functionParam105;
        bool sjt_ifElse14;
        bool sjt_ifElse15;
        bool sjt_ifElse16;
        bool sjt_ifElse21;
        sjs_vec3_heap* sjt_isEmpty1;
        bool sjt_not4;
        sjs_vec3_heap* sjv_result;
        sjs_vertex_location_texture_normal sjv_vertex0;
        sjs_vertex_location_texture_normal sjv_vertex1;
        sjs_vertex_location_texture_normal sjv_vertex2;

#line 37 ".\..\lib\ui\vertexBuffer.sj"
        sjt_dot1255 = _parent;
#line 1 ".\..\lib\common\array.sj"
        sjt_dot1254 = &(sjt_dot1255)->indices;
#line 60 ".\..\lib\ui\vertexBuffer.sj"
        sjt_compare35 = (sjt_dot1254)->size;
#line 60
        sjt_compare36 = 0;
#line 60
        sjt_ifElse14 = sjt_compare35 > sjt_compare36;
        if (sjt_ifElse14) {
            sjs_vertexBuffer_vertex_location_texture_normal* sjt_dot1256;
            sjs_vertexBuffer_vertex_location_texture_normal* sjt_dot1257;
            int32_t sjt_functionParam82;
            int32_t sjt_functionParam83;
            int32_t sjt_math2349;
            int32_t sjt_math2350;
            int32_t sjt_math2351;
            int32_t sjt_math2352;
            sjs_array_vertex_location_texture_normal* sjt_parent60;
            sjs_array_i32* sjt_parent61;

#line 37 ".\..\lib\ui\vertexBuffer.sj"
            sjt_dot1256 = _parent;
#line 6 ".\..\lib\common\array.sj"
            sjt_parent60 = &(sjt_dot1256)->vertices;
#line 37 ".\..\lib\ui\vertexBuffer.sj"
            sjt_dot1257 = _parent;
#line 6 ".\..\lib\common\array.sj"
            sjt_parent61 = &(sjt_dot1257)->indices;
#line 59 ".\..\lib\ui\vertexBuffer.sj"
            sjt_math2351 = i;
#line 60
            sjt_math2352 = 3;
#line 60
            sjt_math2349 = sjt_math2351 * sjt_math2352;
#line 60
            sjt_math2350 = 0;
#line 60
            sjt_functionParam83 = sjt_math2349 + sjt_math2350;
#line 0 ""
            sjf_array_i32_getAt(sjt_parent61, sjt_functionParam83, &sjt_functionParam82);
            sjf_array_vertex_location_texture_normal_getAt(sjt_parent60, sjt_functionParam82, &sjv_vertex0);
        } else {
            sjs_vertexBuffer_vertex_location_texture_normal* sjt_dot1258;
            int32_t sjt_functionParam84;
            int32_t sjt_math2353;
            int32_t sjt_math2354;
            int32_t sjt_math2355;
            int32_t sjt_math2356;
            sjs_array_vertex_location_texture_normal* sjt_parent62;

#line 37 ".\..\lib\ui\vertexBuffer.sj"
            sjt_dot1258 = _parent;
#line 6 ".\..\lib\common\array.sj"
            sjt_parent62 = &(sjt_dot1258)->vertices;
#line 59 ".\..\lib\ui\vertexBuffer.sj"
            sjt_math2355 = i;
#line 60
            sjt_math2356 = 3;
#line 60
            sjt_math2353 = sjt_math2355 * sjt_math2356;
#line 60
            sjt_math2354 = 0;
#line 60
            sjt_functionParam84 = sjt_math2353 + sjt_math2354;
#line 0 ""
            sjf_array_vertex_location_texture_normal_getAt(sjt_parent62, sjt_functionParam84, &sjv_vertex0);
        }

#line 37
        sjt_dot1260 = _parent;
#line 1 ".\..\lib\common\array.sj"
        sjt_dot1259 = &(sjt_dot1260)->indices;
#line 61 ".\..\lib\ui\vertexBuffer.sj"
        sjt_compare37 = (sjt_dot1259)->size;
#line 61
        sjt_compare38 = 0;
#line 61
        sjt_ifElse15 = sjt_compare37 > sjt_compare38;
        if (sjt_ifElse15) {
            sjs_vertexBuffer_vertex_location_texture_normal* sjt_dot1261;
            sjs_vertexBuffer_vertex_location_texture_normal* sjt_dot1262;
            int32_t sjt_functionParam85;
            int32_t sjt_functionParam86;
            int32_t sjt_math2357;
            int32_t sjt_math2358;
            int32_t sjt_math2359;
            int32_t sjt_math2360;
            sjs_array_vertex_location_texture_normal* sjt_parent63;
            sjs_array_i32* sjt_parent64;

#line 37 ".\..\lib\ui\vertexBuffer.sj"
            sjt_dot1261 = _parent;
#line 6 ".\..\lib\common\array.sj"
            sjt_parent63 = &(sjt_dot1261)->vertices;
#line 37 ".\..\lib\ui\vertexBuffer.sj"
            sjt_dot1262 = _parent;
#line 6 ".\..\lib\common\array.sj"
            sjt_parent64 = &(sjt_dot1262)->indices;
#line 59 ".\..\lib\ui\vertexBuffer.sj"
            sjt_math2359 = i;
#line 61
            sjt_math2360 = 3;
#line 61
            sjt_math2357 = sjt_math2359 * sjt_math2360;
#line 61
            sjt_math2358 = 1;
#line 61
            sjt_functionParam86 = sjt_math2357 + sjt_math2358;
#line 0 ""
            sjf_array_i32_getAt(sjt_parent64, sjt_functionParam86, &sjt_functionParam85);
            sjf_array_vertex_location_texture_normal_getAt(sjt_parent63, sjt_functionParam85, &sjv_vertex1);
        } else {
            sjs_vertexBuffer_vertex_location_texture_normal* sjt_dot1263;
            int32_t sjt_functionParam87;
            int32_t sjt_math2361;
            int32_t sjt_math2362;
            int32_t sjt_math2363;
            int32_t sjt_math2364;
            sjs_array_vertex_location_texture_normal* sjt_parent65;

#line 37 ".\..\lib\ui\vertexBuffer.sj"
            sjt_dot1263 = _parent;
#line 6 ".\..\lib\common\array.sj"
            sjt_parent65 = &(sjt_dot1263)->vertices;
#line 59 ".\..\lib\ui\vertexBuffer.sj"
            sjt_math2363 = i;
#line 61
            sjt_math2364 = 3;
#line 61
            sjt_math2361 = sjt_math2363 * sjt_math2364;
#line 61
            sjt_math2362 = 1;
#line 61
            sjt_functionParam87 = sjt_math2361 + sjt_math2362;
#line 0 ""
            sjf_array_vertex_location_texture_normal_getAt(sjt_parent65, sjt_functionParam87, &sjv_vertex1);
        }

#line 37
        sjt_dot1265 = _parent;
#line 1 ".\..\lib\common\array.sj"
        sjt_dot1264 = &(sjt_dot1265)->indices;
#line 62 ".\..\lib\ui\vertexBuffer.sj"
        sjt_compare39 = (sjt_dot1264)->size;
#line 62
        sjt_compare40 = 0;
#line 62
        sjt_ifElse16 = sjt_compare39 > sjt_compare40;
        if (sjt_ifElse16) {
            sjs_vertexBuffer_vertex_location_texture_normal* sjt_dot1266;
            sjs_vertexBuffer_vertex_location_texture_normal* sjt_dot1267;
            int32_t sjt_functionParam88;
            int32_t sjt_functionParam89;
            int32_t sjt_math2365;
            int32_t sjt_math2366;
            int32_t sjt_math2367;
            int32_t sjt_math2368;
            sjs_array_vertex_location_texture_normal* sjt_parent66;
            sjs_array_i32* sjt_parent67;

#line 37 ".\..\lib\ui\vertexBuffer.sj"
            sjt_dot1266 = _parent;
#line 6 ".\..\lib\common\array.sj"
            sjt_parent66 = &(sjt_dot1266)->vertices;
#line 37 ".\..\lib\ui\vertexBuffer.sj"
            sjt_dot1267 = _parent;
#line 6 ".\..\lib\common\array.sj"
            sjt_parent67 = &(sjt_dot1267)->indices;
#line 59 ".\..\lib\ui\vertexBuffer.sj"
            sjt_math2367 = i;
#line 62
            sjt_math2368 = 3;
#line 62
            sjt_math2365 = sjt_math2367 * sjt_math2368;
#line 62
            sjt_math2366 = 2;
#line 62
            sjt_functionParam89 = sjt_math2365 + sjt_math2366;
#line 0 ""
            sjf_array_i32_getAt(sjt_parent67, sjt_functionParam89, &sjt_functionParam88);
            sjf_array_vertex_location_texture_normal_getAt(sjt_parent66, sjt_functionParam88, &sjv_vertex2);
        } else {
            sjs_vertexBuffer_vertex_location_texture_normal* sjt_dot1268;
            int32_t sjt_functionParam90;
            int32_t sjt_math2369;
            int32_t sjt_math2370;
            int32_t sjt_math2371;
            int32_t sjt_math2372;
            sjs_array_vertex_location_texture_normal* sjt_parent68;

#line 37 ".\..\lib\ui\vertexBuffer.sj"
            sjt_dot1268 = _parent;
#line 6 ".\..\lib\common\array.sj"
            sjt_parent68 = &(sjt_dot1268)->vertices;
#line 59 ".\..\lib\ui\vertexBuffer.sj"
            sjt_math2371 = i;
#line 62
            sjt_math2372 = 3;
#line 62
            sjt_math2369 = sjt_math2371 * sjt_math2372;
#line 62
            sjt_math2370 = 2;
#line 62
            sjt_functionParam90 = sjt_math2369 + sjt_math2370;
#line 0 ""
            sjf_array_vertex_location_texture_normal_getAt(sjt_parent68, sjt_functionParam90, &sjv_vertex2);
        }

#line 65
        sjt_functionParam101 = &sjv_vPickRayOrig;
#line 65
        sjt_functionParam102 = &sjv_vPickRayDir;
#line 2 ".\..\lib\ui\vertexBufferBuilders.sj"
        sjt_dot1269 = &sjv_vertex0;
#line 65 ".\..\lib\ui\vertexBuffer.sj"
        sjt_functionParam103 = &(sjt_dot1269)->location;
#line 2 ".\..\lib\ui\vertexBufferBuilders.sj"
        sjt_dot1270 = &sjv_vertex1;
#line 65 ".\..\lib\ui\vertexBuffer.sj"
        sjt_functionParam104 = &(sjt_dot1270)->location;
#line 2 ".\..\lib\ui\vertexBufferBuilders.sj"
        sjt_dot1271 = &sjv_vertex2;
#line 65 ".\..\lib\ui\vertexBuffer.sj"
        sjt_functionParam105 = &(sjt_dot1271)->location;
#line 0 ""
        sjf_intersectTriangle_heap(sjt_functionParam101, sjt_functionParam102, sjt_functionParam103, sjt_functionParam104, sjt_functionParam105, &sjv_result);
#line 66 ".\..\lib\ui\vertexBuffer.sj"
        sjt_isEmpty1 = sjv_result;
        if (sjt_isEmpty1 != 0) {
            sjt_isEmpty1->_refCount++;
        }

#line 66
        sjt_not4 = (sjt_isEmpty1 == 0);
#line 66
        result12 = !sjt_not4;
#line 66
        sjt_ifElse21 = result12;
        if (sjt_ifElse21) {
            float sjt_compare53;
            float sjt_compare54;
            bool sjt_ifElse22;
            bool sjt_ifElse23;
            bool sjt_ifElse24;
            bool sjt_ifElse26;
            bool sjt_ifElse27;
            sjs_vec3_heap* sjt_isEmpty2;
            float_option sjt_isEmpty3;
            sjs_vec3_heap* sjt_isEmpty4;
            float_option sjt_isEmpty6;
            sjs_vec3_heap* sjt_isEmpty7;
            bool sjt_or5;
            bool sjt_or6;

#line 67 ".\..\lib\ui\vertexBuffer.sj"
            sjt_isEmpty2 = sjv_intersection;
            if (sjt_isEmpty2 != 0) {
                sjt_isEmpty2->_refCount++;
            }

#line 67
            sjt_or5 = (sjt_isEmpty2 == 0);
#line 67
            sjt_isEmpty4 = sjv_result;
            if (sjt_isEmpty4 != 0) {
                sjt_isEmpty4->_refCount++;
            }

#line 67
            sjt_ifElse24 = (sjt_isEmpty4 == 0);
            if (sjt_ifElse24) {
#line 67 ".\..\lib\ui\vertexBuffer.sj"
                sjt_isEmpty3 = float_empty;
            } else {
                sjs_vec3* sjt_dot1272;
                sjs_vec3_heap* sjt_getValue1;
                float sjt_value3;
                float_option value1;

#line 67 ".\..\lib\ui\vertexBuffer.sj"
                sjt_getValue1 = sjv_result;
                if (sjt_getValue1 != 0) {
                    sjt_getValue1->_refCount++;
                }

#line 67
                sjt_dot1272 = (sjs_vec3*)(((char*)sjt_getValue1) + sizeof(intptr_t));
#line 67
                sjt_value3 = (sjt_dot1272)->z;
#line 67
                value1.isEmpty = false;
#line 67
                value1.value = sjt_value3;
#line 67
                sjt_isEmpty3 = value1;

                if (sjt_getValue1 != 0) {
                    sjt_getValue1->_refCount--;
                    if (sjt_getValue1->_refCount <= 0) {
                        sjf_vec3_destroy((sjs_vec3*)(((char*)sjt_getValue1) + sizeof(intptr_t)));
                    }
                }
            }

#line 67
            sjt_ifElse23 = sjt_isEmpty3.isEmpty;
            if (sjt_ifElse23) {
#line 67 ".\..\lib\ui\vertexBuffer.sj"
                sjt_compare53 = 0.0f;
            } else {
                float_option sjt_getValue2;
                bool sjt_ifElse25;
                sjs_vec3_heap* sjt_isEmpty5;

#line 67 ".\..\lib\ui\vertexBuffer.sj"
                sjt_isEmpty5 = sjv_result;
                if (sjt_isEmpty5 != 0) {
                    sjt_isEmpty5->_refCount++;
                }

#line 67
                sjt_ifElse25 = (sjt_isEmpty5 == 0);
                if (sjt_ifElse25) {
#line 67 ".\..\lib\ui\vertexBuffer.sj"
                    sjt_getValue2 = float_empty;
                } else {
                    sjs_vec3* sjt_dot1273;
                    sjs_vec3_heap* sjt_getValue3;
                    float sjt_value4;
                    float_option value2;

#line 67 ".\..\lib\ui\vertexBuffer.sj"
                    sjt_getValue3 = sjv_result;
                    if (sjt_getValue3 != 0) {
                        sjt_getValue3->_refCount++;
                    }

#line 67
                    sjt_dot1273 = (sjs_vec3*)(((char*)sjt_getValue3) + sizeof(intptr_t));
#line 67
                    sjt_value4 = (sjt_dot1273)->z;
#line 67
                    value2.isEmpty = false;
#line 67
                    value2.value = sjt_value4;
#line 67
                    sjt_getValue2 = value2;

                    if (sjt_getValue3 != 0) {
                        sjt_getValue3->_refCount--;
                        if (sjt_getValue3->_refCount <= 0) {
                            sjf_vec3_destroy((sjs_vec3*)(((char*)sjt_getValue3) + sizeof(intptr_t)));
                        }
                    }
                }

#line 67
                sjt_compare53 = sjt_getValue2.value;

                if (sjt_isEmpty5 != 0) {
                    sjt_isEmpty5->_refCount--;
                    if (sjt_isEmpty5->_refCount <= 0) {
                        sjf_vec3_destroy((sjs_vec3*)(((char*)sjt_isEmpty5) + sizeof(intptr_t)));
                    }
                }
            }

#line 67
            sjt_isEmpty7 = sjv_intersection;
            if (sjt_isEmpty7 != 0) {
                sjt_isEmpty7->_refCount++;
            }

#line 67
            sjt_ifElse27 = (sjt_isEmpty7 == 0);
            if (sjt_ifElse27) {
#line 67 ".\..\lib\ui\vertexBuffer.sj"
                sjt_isEmpty6 = float_empty;
            } else {
                sjs_vec3* sjt_dot1274;
                sjs_vec3_heap* sjt_getValue4;
                float sjt_value5;
                float_option value3;

#line 67 ".\..\lib\ui\vertexBuffer.sj"
                sjt_getValue4 = sjv_intersection;
                if (sjt_getValue4 != 0) {
                    sjt_getValue4->_refCount++;
                }

#line 67
                sjt_dot1274 = (sjs_vec3*)(((char*)sjt_getValue4) + sizeof(intptr_t));
#line 67
                sjt_value5 = (sjt_dot1274)->z;
#line 67
                value3.isEmpty = false;
#line 67
                value3.value = sjt_value5;
#line 67
                sjt_isEmpty6 = value3;

                if (sjt_getValue4 != 0) {
                    sjt_getValue4->_refCount--;
                    if (sjt_getValue4->_refCount <= 0) {
                        sjf_vec3_destroy((sjs_vec3*)(((char*)sjt_getValue4) + sizeof(intptr_t)));
                    }
                }
            }

#line 67
            sjt_ifElse26 = sjt_isEmpty6.isEmpty;
            if (sjt_ifElse26) {
#line 67 ".\..\lib\ui\vertexBuffer.sj"
                sjt_compare54 = 0.0f;
            } else {
                float_option sjt_getValue5;
                bool sjt_ifElse28;
                sjs_vec3_heap* sjt_isEmpty8;

#line 67 ".\..\lib\ui\vertexBuffer.sj"
                sjt_isEmpty8 = sjv_intersection;
                if (sjt_isEmpty8 != 0) {
                    sjt_isEmpty8->_refCount++;
                }

#line 67
                sjt_ifElse28 = (sjt_isEmpty8 == 0);
                if (sjt_ifElse28) {
#line 67 ".\..\lib\ui\vertexBuffer.sj"
                    sjt_getValue5 = float_empty;
                } else {
                    sjs_vec3* sjt_dot1275;
                    sjs_vec3_heap* sjt_getValue6;
                    float sjt_value6;
                    float_option value4;

#line 67 ".\..\lib\ui\vertexBuffer.sj"
                    sjt_getValue6 = sjv_intersection;
                    if (sjt_getValue6 != 0) {
                        sjt_getValue6->_refCount++;
                    }

#line 67
                    sjt_dot1275 = (sjs_vec3*)(((char*)sjt_getValue6) + sizeof(intptr_t));
#line 67
                    sjt_value6 = (sjt_dot1275)->z;
#line 67
                    value4.isEmpty = false;
#line 67
                    value4.value = sjt_value6;
#line 67
                    sjt_getValue5 = value4;

                    if (sjt_getValue6 != 0) {
                        sjt_getValue6->_refCount--;
                        if (sjt_getValue6->_refCount <= 0) {
                            sjf_vec3_destroy((sjs_vec3*)(((char*)sjt_getValue6) + sizeof(intptr_t)));
                        }
                    }
                }

#line 67
                sjt_compare54 = sjt_getValue5.value;

                if (sjt_isEmpty8 != 0) {
                    sjt_isEmpty8->_refCount--;
                    if (sjt_isEmpty8->_refCount <= 0) {
                        sjf_vec3_destroy((sjs_vec3*)(((char*)sjt_isEmpty8) + sizeof(intptr_t)));
                    }
                }
            }

#line 67
            sjt_or6 = sjt_compare53 < sjt_compare54;
#line 67
            sjt_ifElse22 = sjt_or5 || sjt_or6;
            if (sjt_ifElse22) {
                sjs_vec2* sjt_dot1276;
                sjs_vertex_location_texture_normal* sjt_dot1277;
                sjs_vec2* sjt_dot1278;
                sjs_vertex_location_texture_normal* sjt_dot1279;
                sjs_vec2* sjt_dot1280;
                sjs_vertex_location_texture_normal* sjt_dot1281;
                sjs_vec2* sjt_dot1282;
                sjs_vertex_location_texture_normal* sjt_dot1283;
                sjs_vec2* sjt_dot1284;
                sjs_vertex_location_texture_normal* sjt_dot1285;
                sjs_vec2* sjt_dot1286;
                sjs_vertex_location_texture_normal* sjt_dot1287;
                sjs_vec2* sjt_dot1288;
                sjs_vertex_location_texture_normal* sjt_dot1289;
                sjs_vec2* sjt_dot1290;
                sjs_vertex_location_texture_normal* sjt_dot1291;
                sjs_vec2* sjt_dot1292;
                sjs_vertex_location_texture_normal* sjt_dot1293;
                sjs_vec3* sjt_dot1294;
                sjs_vec3* sjt_dot1295;
                sjs_vec2* sjt_dot1296;
                sjs_vertex_location_texture_normal* sjt_dot1297;
                sjs_vec3* sjt_dot1298;
                sjs_vec3* sjt_dot1299;
                sjs_vec3_heap* sjt_getValue7;
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
                sjs_vec2_heap* sjt_value7;
                float sjv_dtu1;
                float sjv_dtu2;
                float sjv_dtv1;
                float sjv_dtv2;
                sjs_vec3_heap* sjv_t;

                if (sjv_intersection != 0) {
                    sjv_intersection->_refCount--;
                    if (sjv_intersection->_refCount <= 0) {
                        sjf_vec3_destroy((sjs_vec3*)(((char*)sjv_intersection) + sizeof(intptr_t)));
                    }
                }

#line 68 ".\..\lib\ui\vertexBuffer.sj"
                sjv_intersection = sjv_result;
                if (sjv_intersection != 0) {
                    sjv_intersection->_refCount++;
                }

#line 70
                sjt_getValue7 = sjv_intersection;
                if (sjt_getValue7 != 0) {
                    sjt_getValue7->_refCount++;
                }

#line 70
                if (sjt_getValue7 == 0) { exit(-1); }
#line 70
                sjv_t = sjt_getValue7;
#line 0 ""
                sjv_t->_refCount++;
#line 2 ".\..\lib\ui\vertexBufferBuilders.sj"
                sjt_dot1277 = &sjv_vertex1;
#line 1 ".\..\lib\ui\vec2.sj"
                sjt_dot1276 = &(sjt_dot1277)->texture;
#line 74 ".\..\lib\ui\vertexBuffer.sj"
                sjt_math2385 = (sjt_dot1276)->x;
#line 2 ".\..\lib\ui\vertexBufferBuilders.sj"
                sjt_dot1279 = &sjv_vertex0;
#line 1 ".\..\lib\ui\vec2.sj"
                sjt_dot1278 = &(sjt_dot1279)->texture;
#line 74 ".\..\lib\ui\vertexBuffer.sj"
                sjt_math2386 = (sjt_dot1278)->x;
#line 74
                sjv_dtu1 = sjt_math2385 - sjt_math2386;
#line 2 ".\..\lib\ui\vertexBufferBuilders.sj"
                sjt_dot1281 = &sjv_vertex2;
#line 1 ".\..\lib\ui\vec2.sj"
                sjt_dot1280 = &(sjt_dot1281)->texture;
#line 75 ".\..\lib\ui\vertexBuffer.sj"
                sjt_math2387 = (sjt_dot1280)->x;
#line 2 ".\..\lib\ui\vertexBufferBuilders.sj"
                sjt_dot1283 = &sjv_vertex0;
#line 1 ".\..\lib\ui\vec2.sj"
                sjt_dot1282 = &(sjt_dot1283)->texture;
#line 75 ".\..\lib\ui\vertexBuffer.sj"
                sjt_math2388 = (sjt_dot1282)->x;
#line 75
                sjv_dtu2 = sjt_math2387 - sjt_math2388;
#line 2 ".\..\lib\ui\vertexBufferBuilders.sj"
                sjt_dot1285 = &sjv_vertex1;
#line 1 ".\..\lib\ui\vec2.sj"
                sjt_dot1284 = &(sjt_dot1285)->texture;
#line 76 ".\..\lib\ui\vertexBuffer.sj"
                sjt_math2389 = (sjt_dot1284)->y;
#line 2 ".\..\lib\ui\vertexBufferBuilders.sj"
                sjt_dot1287 = &sjv_vertex0;
#line 1 ".\..\lib\ui\vec2.sj"
                sjt_dot1286 = &(sjt_dot1287)->texture;
#line 76 ".\..\lib\ui\vertexBuffer.sj"
                sjt_math2390 = (sjt_dot1286)->y;
#line 76
                sjv_dtv1 = sjt_math2389 - sjt_math2390;
#line 2 ".\..\lib\ui\vertexBufferBuilders.sj"
                sjt_dot1289 = &sjv_vertex2;
#line 1 ".\..\lib\ui\vec2.sj"
                sjt_dot1288 = &(sjt_dot1289)->texture;
#line 77 ".\..\lib\ui\vertexBuffer.sj"
                sjt_math2391 = (sjt_dot1288)->y;
#line 2 ".\..\lib\ui\vertexBufferBuilders.sj"
                sjt_dot1291 = &sjv_vertex0;
#line 1 ".\..\lib\ui\vec2.sj"
                sjt_dot1290 = &(sjt_dot1291)->texture;
#line 77 ".\..\lib\ui\vertexBuffer.sj"
                sjt_math2392 = (sjt_dot1290)->y;
#line 77
                sjv_dtv2 = sjt_math2391 - sjt_math2392;
#line 0 ""
                sjt_value7 = (sjs_vec2_heap*)malloc(sizeof(sjs_vec2_heap));
                sjt_value7->_refCount = 1;
#line 2 ".\..\lib\ui\vertexBufferBuilders.sj"
                sjt_dot1293 = &sjv_vertex0;
#line 1 ".\..\lib\ui\vec2.sj"
                sjt_dot1292 = &(sjt_dot1293)->texture;
#line 79 ".\..\lib\ui\vertexBuffer.sj"
                sjt_math2395 = (sjt_dot1292)->x;
#line 1 ".\..\lib\ui\vec3.sj"
                sjt_dot1294 = (sjs_vec3*)(((char*)sjv_t) + sizeof(intptr_t));
#line 79 ".\..\lib\ui\vertexBuffer.sj"
                sjt_math2397 = (sjt_dot1294)->x;
#line 79
                sjt_math2398 = sjv_dtu1;
#line 79
                sjt_math2396 = sjt_math2397 * sjt_math2398;
#line 79
                sjt_math2393 = sjt_math2395 + sjt_math2396;
#line 1 ".\..\lib\ui\vec3.sj"
                sjt_dot1295 = (sjs_vec3*)(((char*)sjv_t) + sizeof(intptr_t));
#line 79 ".\..\lib\ui\vertexBuffer.sj"
                sjt_math2399 = (sjt_dot1295)->y;
#line 79
                sjt_math2400 = sjv_dtu2;
#line 79
                sjt_math2394 = sjt_math2399 * sjt_math2400;
#line 79
                sjt_value7->x = sjt_math2393 + sjt_math2394;
#line 2 ".\..\lib\ui\vertexBufferBuilders.sj"
                sjt_dot1297 = &sjv_vertex0;
#line 1 ".\..\lib\ui\vec2.sj"
                sjt_dot1296 = &(sjt_dot1297)->texture;
#line 80 ".\..\lib\ui\vertexBuffer.sj"
                sjt_math2403 = (sjt_dot1296)->y;
#line 1 ".\..\lib\ui\vec3.sj"
                sjt_dot1298 = (sjs_vec3*)(((char*)sjv_t) + sizeof(intptr_t));
#line 80 ".\..\lib\ui\vertexBuffer.sj"
                sjt_math2405 = (sjt_dot1298)->x;
#line 80
                sjt_math2406 = sjv_dtv1;
#line 80
                sjt_math2404 = sjt_math2405 * sjt_math2406;
#line 80
                sjt_math2401 = sjt_math2403 + sjt_math2404;
#line 1 ".\..\lib\ui\vec3.sj"
                sjt_dot1299 = (sjs_vec3*)(((char*)sjv_t) + sizeof(intptr_t));
#line 80 ".\..\lib\ui\vertexBuffer.sj"
                sjt_math2407 = (sjt_dot1299)->y;
#line 80
                sjt_math2408 = sjv_dtv2;
#line 80
                sjt_math2402 = sjt_math2407 * sjt_math2408;
#line 80
                sjt_value7->y = sjt_math2401 + sjt_math2402;
#line 0 ""
                sjf_vec2_heap(sjt_value7);
                if (sjv_texture != 0) {
                    sjv_texture->_refCount--;
                    if (sjv_texture->_refCount <= 0) {
                        sjf_vec2_destroy((sjs_vec2*)(((char*)sjv_texture) + sizeof(intptr_t)));
                    }
                }

#line 78 ".\..\lib\ui\vertexBuffer.sj"
                sjv_texture = sjt_value7;
                if (sjv_texture != 0) {
                    sjv_texture->_refCount++;
                }

                if (sjt_getValue7 != 0) {
                    sjt_getValue7->_refCount--;
                    if (sjt_getValue7->_refCount <= 0) {
                        sjf_vec3_destroy((sjs_vec3*)(((char*)sjt_getValue7) + sizeof(intptr_t)));
                    }
                }
                sjt_value7->_refCount--;
                if (sjt_value7->_refCount <= 0) {
                    sjf_vec2_destroy((sjs_vec2*)(((char*)sjt_value7) + sizeof(intptr_t)));
                }
                sjv_t->_refCount--;
                if (sjv_t->_refCount <= 0) {
                    sjf_vec3_destroy((sjs_vec3*)(((char*)sjv_t) + sizeof(intptr_t)));
                }
            }

            if (sjt_isEmpty2 != 0) {
                sjt_isEmpty2->_refCount--;
                if (sjt_isEmpty2->_refCount <= 0) {
                    sjf_vec3_destroy((sjs_vec3*)(((char*)sjt_isEmpty2) + sizeof(intptr_t)));
                }
            }
            if (sjt_isEmpty4 != 0) {
                sjt_isEmpty4->_refCount--;
                if (sjt_isEmpty4->_refCount <= 0) {
                    sjf_vec3_destroy((sjs_vec3*)(((char*)sjt_isEmpty4) + sizeof(intptr_t)));
                }
            }
            if (sjt_isEmpty7 != 0) {
                sjt_isEmpty7->_refCount--;
                if (sjt_isEmpty7->_refCount <= 0) {
                    sjf_vec3_destroy((sjs_vec3*)(((char*)sjt_isEmpty7) + sizeof(intptr_t)));
                }
            }
        }

#line 59
        i++;

        if (sjt_isEmpty1 != 0) {
            sjt_isEmpty1->_refCount--;
            if (sjt_isEmpty1->_refCount <= 0) {
                sjf_vec3_destroy((sjs_vec3*)(((char*)sjt_isEmpty1) + sizeof(intptr_t)));
            }
        }
        if (sjv_result != 0) {
            sjv_result->_refCount--;
            if (sjv_result->_refCount <= 0) {
                sjf_vec3_destroy((sjs_vec3*)(((char*)sjv_result) + sizeof(intptr_t)));
            }
        }
        sjf_vertex_location_texture_normal_destroy(&sjv_vertex0);
        sjf_vertex_location_texture_normal_destroy(&sjv_vertex1);
        sjf_vertex_location_texture_normal_destroy(&sjv_vertex2);
    }

#line 37
    (*_return) = sjv_texture;
    if ((*_return) != 0) {
        (*_return)->_refCount++;
    }

    if (sjv_intersection != 0) {
        sjv_intersection->_refCount--;
        if (sjv_intersection->_refCount <= 0) {
            sjf_vec3_destroy((sjs_vec3*)(((char*)sjv_intersection) + sizeof(intptr_t)));
        }
    }
    if (sjv_texture != 0) {
        sjv_texture->_refCount--;
        if (sjv_texture->_refCount <= 0) {
            sjf_vec2_destroy((sjs_vec2*)(((char*)sjv_texture) + sizeof(intptr_t)));
        }
    }
    sjf_mat4_destroy(&sjv_m);
    sjf_vec2_destroy(&sjv_start);
    sjf_vec3_destroy(&sjv_v);
    sjf_vec3_destroy(&sjv_vPickRayDir);
    sjf_vec3_destroy(&sjv_vPickRayOrig);
    sjf_mat4_destroy(&sjv_worldView);
}

void sjf_vertex_location_texture_normal(sjs_vertex_location_texture_normal* _this) {
}

void sjf_vertex_location_texture_normal_copy(sjs_vertex_location_texture_normal* _this, sjs_vertex_location_texture_normal* _from) {
#line 2 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjf_vec3_copy(&_this->location, &_from->location);
#line 2
    sjf_vec2_copy(&_this->texture, &_from->texture);
#line 2
    sjf_vec3_copy(&_this->normal, &_from->normal);
}

void sjf_vertex_location_texture_normal_destroy(sjs_vertex_location_texture_normal* _this) {
}

void sjf_vertex_location_texture_normal_heap(sjs_vertex_location_texture_normal_heap* _this) {
}

void sjf_windowRenderer(sjs_windowRenderer* _this) {
#line 23 ".\..\lib\ui\windowRenderer.sj"
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
#line 23
        halt("SDL_Init Error: %s\n", SDL_GetError());
#line 23
    }
#line 23
    #ifdef __APPLE__
#line 23
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
#line 23
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);
#line 23
    #else
#line 23
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_ES);
#line 23
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
#line 23
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 0);
#line 23
    #endif
#line 23
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
#line 23
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
#line 23
    _this->win = SDL_CreateWindow("Hello World!", 100, 100, 640, 480, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
#line 23
    if (_this->win == 0) {
#line 23
        halt("SDL_CreateWindow Error: %s\n", SDL_GetError());
#line 23
    }
#line 23
    SDL_GL_CreateContext((SDL_Window*)_this->win);
#line 23
    #ifdef WIN32
#line 23
    GLint GlewInitResult = glewInit();
#line 23
    if (GLEW_OK != GlewInitResult)
#line 23
    {
#line 23
        halt("ERROR: %s\n", glewGetErrorString(GlewInitResult));
#line 23
    }
#line 23
    #endif
#line 23
    _this->ren = SDL_CreateRenderer((SDL_Window*)_this->win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
#line 23
    if (_this->ren == 0) {
#line 23
        halt("SDL_CreateRenderer Error: %s\n", SDL_GetError());
#line 23
    }
#line 23
    glClearColor( 0.0, 0.0, 0.0, 0.0 );
#line 23
    glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );
#line 23
    glEnable( GL_BLEND );
}

void sjf_windowRenderer_copy(sjs_windowRenderer* _this, sjs_windowRenderer* _from) {
#line 64 ".\..\lib\ui\windowRenderer.sj"
    _this->ren = _from->ren;
#line 64
    _retain(_this->ren);
#line 64
    _this->win = _from->win;
#line 64
    _retain(_this->win);
}

void sjf_windowRenderer_destroy(sjs_windowRenderer* _this) {
#line 71 ".\..\lib\ui\windowRenderer.sj"
    if (_release(_this->ren)) {
#line 71
        SDL_DestroyRenderer(_this->ren);
#line 71
    }
#line 71
    if (_release(_this->win)) {
#line 71
        SDL_DestroyWindow(_this->win);
#line 71
    }
}

void sjf_windowRenderer_getSize(sjs_windowRenderer* _parent, sjs_size* _return) {
    int32_t sjv_h;
    int32_t sjv_w;

#line 8 ".\..\lib\ui\windowRenderer.sj"
    sjv_w = 0;
#line 9
    sjv_h = 0;
#line 10
    SDL_GetRendererOutputSize(_parent->ren, &sjv_w, &sjv_h);
#line 13
    _return->w = sjv_w;
#line 13
    _return->h = sjv_h;
#line 0 ""
    sjf_size(_return);
}

void sjf_windowRenderer_getSize_heap(sjs_windowRenderer* _parent, sjs_size_heap** _return) {
    int32_t sjv_h;
    int32_t sjv_w;

#line 8 ".\..\lib\ui\windowRenderer.sj"
    sjv_w = 0;
#line 9
    sjv_h = 0;
#line 10
    SDL_GetRendererOutputSize(_parent->ren, &sjv_w, &sjv_h);
#line 0 ""
    (*_return) = (sjs_size_heap*)malloc(sizeof(sjs_size_heap));
    (*_return)->_refCount = 1;
#line 13 ".\..\lib\ui\windowRenderer.sj"
    (*_return)->w = sjv_w;
#line 13
    (*_return)->h = sjv_h;
#line 0 ""
    sjf_size_heap((*_return));
}

void sjf_windowRenderer_heap(sjs_windowRenderer_heap* _this) {
#line 23 ".\..\lib\ui\windowRenderer.sj"
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
#line 23
        halt("SDL_Init Error: %s\n", SDL_GetError());
#line 23
    }
#line 23
    #ifdef __APPLE__
#line 23
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
#line 23
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);
#line 23
    #else
#line 23
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_ES);
#line 23
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
#line 23
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 0);
#line 23
    #endif
#line 23
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
#line 23
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
#line 23
    _this->win = SDL_CreateWindow("Hello World!", 100, 100, 640, 480, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
#line 23
    if (_this->win == 0) {
#line 23
        halt("SDL_CreateWindow Error: %s\n", SDL_GetError());
#line 23
    }
#line 23
    SDL_GL_CreateContext((SDL_Window*)_this->win);
#line 23
    #ifdef WIN32
#line 23
    GLint GlewInitResult = glewInit();
#line 23
    if (GLEW_OK != GlewInitResult)
#line 23
    {
#line 23
        halt("ERROR: %s\n", glewGetErrorString(GlewInitResult));
#line 23
    }
#line 23
    #endif
#line 23
    _this->ren = SDL_CreateRenderer((SDL_Window*)_this->win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
#line 23
    if (_this->ren == 0) {
#line 23
        halt("SDL_CreateRenderer Error: %s\n", SDL_GetError());
#line 23
    }
#line 23
    glClearColor( 0.0, 0.0, 0.0, 0.0 );
#line 23
    glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );
#line 23
    glEnable( GL_BLEND );
}

void sjf_windowRenderer_present(sjs_windowRenderer* _parent) {
#line 17 ".\..\lib\ui\windowRenderer.sj"
    SDL_GL_SwapWindow((SDL_Window*)_parent->win);
}

void sji_anon5_animation_copy(sji_anon5_animation* _this, sji_anon5_animation* _from) {
    _this->_refCount = 1;
    _this->_parent = _from->_parent;
    _this->_parent->_refCount++;
    _this->destroy = _from->destroy;
    _this->asInterface = _from->asInterface;
    _this->nextFrame = _from->nextFrame;
}

void sji_anon5_animation_destroy(sji_anon5_animation* _this) {
    _this->_parent->_refCount--;
    if (_this->_parent->_refCount <= 0) {
        _this->destroy((void*)(((char*)_this->_parent) + sizeof(intptr_t)));
        free(_this->_parent);
    }
}

void sji_element_copy(sji_element* _this, sji_element* _from) {
    _this->_refCount = 1;
    _this->_parent = _from->_parent;
    _this->_parent->_refCount++;
    _this->destroy = _from->destroy;
    _this->asInterface = _from->asInterface;
    _this->getSize = _from->getSize;
    _this->getSize = _from->getSize;
    _this->getRect = _from->getRect;
    _this->setRect = _from->setRect;
    _this->render = _from->render;
    _this->getChildren = _from->getChildren;
    _this->fireMouseEvent = _from->fireMouseEvent;
}

void sji_element_destroy(sji_element* _this) {
    _this->_parent->_refCount--;
    if (_this->_parent->_refCount <= 0) {
        _this->destroy((void*)(((char*)_this->_parent) + sizeof(intptr_t)));
        free(_this->_parent);
    }
}

void sji_scene3dElement_model_copy(sji_scene3dElement_model* _this, sji_scene3dElement_model* _from) {
    _this->_refCount = 1;
    _this->_parent = _from->_parent;
    _this->_parent->_refCount++;
    _this->destroy = _from->destroy;
    _this->asInterface = _from->asInterface;
    _this->setWorld = _from->setWorld;
    _this->render = _from->render;
    _this->fireMouseEvent = _from->fireMouseEvent;
}

void sji_scene3dElement_model_destroy(sji_scene3dElement_model* _this) {
    _this->_parent->_refCount--;
    if (_this->_parent->_refCount <= 0) {
        _this->destroy((void*)(((char*)_this->_parent) + sizeof(intptr_t)));
        free(_this->_parent);
    }
}

int main(int argc, char** argv) {
    sjf_windowRenderer(&sjv_rootWindowRenderer);
#line 2 ".\..\lib\ui\size.sj"
    sjv_rootScene._size.w = 0;
#line 3
    sjv_rootScene._size.h = 0;
#line 0 ""
    sjf_size(&sjv_rootScene._size);
#line 2 ".\..\lib\ui\mat4.sj"
    sjv_rootScene.model.m00 = 0.0f;
#line 3
    sjv_rootScene.model.m01 = 0.0f;
#line 4
    sjv_rootScene.model.m02 = 0.0f;
#line 5
    sjv_rootScene.model.m03 = 0.0f;
#line 6
    sjv_rootScene.model.m10 = 0.0f;
#line 7
    sjv_rootScene.model.m11 = 0.0f;
#line 8
    sjv_rootScene.model.m12 = 0.0f;
#line 9
    sjv_rootScene.model.m13 = 0.0f;
#line 10
    sjv_rootScene.model.m20 = 0.0f;
#line 11
    sjv_rootScene.model.m21 = 0.0f;
#line 12
    sjv_rootScene.model.m22 = 0.0f;
#line 13
    sjv_rootScene.model.m23 = 0.0f;
#line 14
    sjv_rootScene.model.m30 = 0.0f;
#line 15
    sjv_rootScene.model.m31 = 0.0f;
#line 16
    sjv_rootScene.model.m32 = 0.0f;
#line 17
    sjv_rootScene.model.m33 = 0.0f;
#line 0 ""
    sjf_mat4(&sjv_rootScene.model);
#line 2 ".\..\lib\ui\mat4.sj"
    sjv_rootScene.view.m00 = 0.0f;
#line 3
    sjv_rootScene.view.m01 = 0.0f;
#line 4
    sjv_rootScene.view.m02 = 0.0f;
#line 5
    sjv_rootScene.view.m03 = 0.0f;
#line 6
    sjv_rootScene.view.m10 = 0.0f;
#line 7
    sjv_rootScene.view.m11 = 0.0f;
#line 8
    sjv_rootScene.view.m12 = 0.0f;
#line 9
    sjv_rootScene.view.m13 = 0.0f;
#line 10
    sjv_rootScene.view.m20 = 0.0f;
#line 11
    sjv_rootScene.view.m21 = 0.0f;
#line 12
    sjv_rootScene.view.m22 = 0.0f;
#line 13
    sjv_rootScene.view.m23 = 0.0f;
#line 14
    sjv_rootScene.view.m30 = 0.0f;
#line 15
    sjv_rootScene.view.m31 = 0.0f;
#line 16
    sjv_rootScene.view.m32 = 0.0f;
#line 17
    sjv_rootScene.view.m33 = 0.0f;
#line 0 ""
    sjf_mat4(&sjv_rootScene.view);
#line 2 ".\..\lib\ui\mat4.sj"
    sjv_rootScene.projection.m00 = 0.0f;
#line 3
    sjv_rootScene.projection.m01 = 0.0f;
#line 4
    sjv_rootScene.projection.m02 = 0.0f;
#line 5
    sjv_rootScene.projection.m03 = 0.0f;
#line 6
    sjv_rootScene.projection.m10 = 0.0f;
#line 7
    sjv_rootScene.projection.m11 = 0.0f;
#line 8
    sjv_rootScene.projection.m12 = 0.0f;
#line 9
    sjv_rootScene.projection.m13 = 0.0f;
#line 10
    sjv_rootScene.projection.m20 = 0.0f;
#line 11
    sjv_rootScene.projection.m21 = 0.0f;
#line 12
    sjv_rootScene.projection.m22 = 0.0f;
#line 13
    sjv_rootScene.projection.m23 = 0.0f;
#line 14
    sjv_rootScene.projection.m30 = 0.0f;
#line 15
    sjv_rootScene.projection.m31 = 0.0f;
#line 16
    sjv_rootScene.projection.m32 = 0.0f;
#line 17
    sjv_rootScene.projection.m33 = 0.0f;
#line 0 ""
    sjf_mat4(&sjv_rootScene.projection);
    sjf_scene2d(&sjv_rootScene);
    sjf_anon1(&sjv_console);
    sjf_anon2(&sjv_convert);
#line 33 ".\..\lib\common\math.sj"
    sjv_f32_pi = 3.14159265358979323846f;
#line 34
    sjv_u32_maxValue = (uint32_t)4294967295u;
#line 36
    sjt_negate1 = 1;
#line 36
    result1 = -sjt_negate1;
#line 36
    sjt_math1 = result1;
#line 36
    sjt_math2 = 2147483647;
#line 36
    sjv_i32_maxValue = sjt_math1 - sjt_math2;
#line 37
    sjv_i32_minValue = 2147483647;
#line 0 ""
    sjf_anon3(&sjv_parse);
    sjf_anon4(&sjv_random);
#line 2 ".\..\lib\common\list.sj"
    sjv_animator.animations.count = 0;
#line 3
    sjv_animator.animations.data.size = 0;
#line 3 ".\..\lib\common\array.sj"
    sjt_cast1 = 0;
#line 3
    sjv_animator.animations.data.data = (uintptr_t)sjt_cast1;
#line 4
    sjv_animator.animations.data._isGlobal = false;
#line 0 ""
    sjf_array_heap_animation(&sjv_animator.animations.data);
    sjf_list_heap_animation(&sjv_animator.animations);
#line 29 ".\..\lib\ui\animation.sj"
    sjv_animator.current = 0;
#line 0 ""
    sjf_anon5(&sjv_animator);
#line 2 ".\..\lib\ui\borderLayout.sj"
    sjv_borderPosition.fill = 0;
#line 3
    sjv_borderPosition.left = 1;
#line 4
    sjv_borderPosition.right = 2;
#line 5
    sjv_borderPosition.top = 3;
#line 6
    sjv_borderPosition.bottom = 4;
#line 0 ""
    sjf_anon6(&sjv_borderPosition);
#line 2 ".\..\lib\ui\buttonElement.sj"
    sjv_buttonState.normal = 0;
#line 3
    sjv_buttonState.hot = 1;
#line 4
    sjv_buttonState.pressed = 2;
#line 0 ""
    sjf_anon7(&sjv_buttonState);
    sjf_anon8(&sjv_colors);
#line 1 ".\..\lib\ui\loop.sj"
    sjv_mouseEvent_move = 0;
#line 2
    sjv_mouseEvent_up = 1;
#line 3
    sjv_mouseEvent_down = 2;
#line 1 ".\..\lib\ui\shader.sj"
    sjv_boxShader.vertex.count = 20;
#line 1
    sjv_boxShader.vertex.data.size = 21;
#line 1
    sjv_boxShader.vertex.data.data = (uintptr_t)sjg_string1;
#line 4 ".\..\lib\common\array.sj"
    sjv_boxShader.vertex.data._isGlobal = false;
#line 0 ""
    sjf_array_char(&sjv_boxShader.vertex.data);
    sjf_string(&sjv_boxShader.vertex);
#line 1 ".\..\lib\ui\shader.sj"
    sjv_boxShader.pixel.count = 20;
#line 1
    sjv_boxShader.pixel.data.size = 21;
#line 1
    sjv_boxShader.pixel.data.data = (uintptr_t)sjg_string2;
#line 4 ".\..\lib\common\array.sj"
    sjv_boxShader.pixel.data._isGlobal = false;
#line 0 ""
    sjf_array_char(&sjv_boxShader.pixel.data);
    sjf_string(&sjv_boxShader.pixel);
    sjf_shader(&sjv_boxShader);
#line 2 ".\..\lib\ui\shader.sj"
    sjv_blurHorizontalShader.vertex.count = 24;
#line 2
    sjv_blurHorizontalShader.vertex.data.size = 25;
#line 2
    sjv_blurHorizontalShader.vertex.data.data = (uintptr_t)sjg_string3;
#line 4 ".\..\lib\common\array.sj"
    sjv_blurHorizontalShader.vertex.data._isGlobal = false;
#line 0 ""
    sjf_array_char(&sjv_blurHorizontalShader.vertex.data);
    sjf_string(&sjv_blurHorizontalShader.vertex);
#line 2 ".\..\lib\ui\shader.sj"
    sjv_blurHorizontalShader.pixel.count = 28;
#line 2
    sjv_blurHorizontalShader.pixel.data.size = 29;
#line 2
    sjv_blurHorizontalShader.pixel.data.data = (uintptr_t)sjg_string4;
#line 4 ".\..\lib\common\array.sj"
    sjv_blurHorizontalShader.pixel.data._isGlobal = false;
#line 0 ""
    sjf_array_char(&sjv_blurHorizontalShader.pixel.data);
    sjf_string(&sjv_blurHorizontalShader.pixel);
    sjf_shader(&sjv_blurHorizontalShader);
#line 3 ".\..\lib\ui\shader.sj"
    sjv_blurVerticalShader.vertex.count = 24;
#line 3
    sjv_blurVerticalShader.vertex.data.size = 25;
#line 3
    sjv_blurVerticalShader.vertex.data.data = (uintptr_t)sjg_string5;
#line 4 ".\..\lib\common\array.sj"
    sjv_blurVerticalShader.vertex.data._isGlobal = false;
#line 0 ""
    sjf_array_char(&sjv_blurVerticalShader.vertex.data);
    sjf_string(&sjv_blurVerticalShader.vertex);
#line 3 ".\..\lib\ui\shader.sj"
    sjv_blurVerticalShader.pixel.count = 26;
#line 3
    sjv_blurVerticalShader.pixel.data.size = 27;
#line 3
    sjv_blurVerticalShader.pixel.data.data = (uintptr_t)sjg_string6;
#line 4 ".\..\lib\common\array.sj"
    sjv_blurVerticalShader.pixel.data._isGlobal = false;
#line 0 ""
    sjf_array_char(&sjv_blurVerticalShader.pixel.data);
    sjf_string(&sjv_blurVerticalShader.pixel);
    sjf_shader(&sjv_blurVerticalShader);
#line 4 ".\..\lib\ui\shader.sj"
    sjv_imageShader.vertex.count = 20;
#line 4
    sjv_imageShader.vertex.data.size = 21;
#line 4
    sjv_imageShader.vertex.data.data = (uintptr_t)sjg_string7;
#line 4 ".\..\lib\common\array.sj"
    sjv_imageShader.vertex.data._isGlobal = false;
#line 0 ""
    sjf_array_char(&sjv_imageShader.vertex.data);
    sjf_string(&sjv_imageShader.vertex);
#line 4 ".\..\lib\ui\shader.sj"
    sjv_imageShader.pixel.count = 20;
#line 4
    sjv_imageShader.pixel.data.size = 21;
#line 4
    sjv_imageShader.pixel.data.data = (uintptr_t)sjg_string8;
#line 4 ".\..\lib\common\array.sj"
    sjv_imageShader.pixel.data._isGlobal = false;
#line 0 ""
    sjf_array_char(&sjv_imageShader.pixel.data);
    sjf_string(&sjv_imageShader.pixel);
    sjf_shader(&sjv_imageShader);
#line 5 ".\..\lib\ui\shader.sj"
    sjv_phongColorShader.vertex.count = 26;
#line 5
    sjv_phongColorShader.vertex.data.size = 27;
#line 5
    sjv_phongColorShader.vertex.data.data = (uintptr_t)sjg_string9;
#line 4 ".\..\lib\common\array.sj"
    sjv_phongColorShader.vertex.data._isGlobal = false;
#line 0 ""
    sjf_array_char(&sjv_phongColorShader.vertex.data);
    sjf_string(&sjv_phongColorShader.vertex);
#line 5 ".\..\lib\ui\shader.sj"
    sjv_phongColorShader.pixel.count = 26;
#line 5
    sjv_phongColorShader.pixel.data.size = 27;
#line 5
    sjv_phongColorShader.pixel.data.data = (uintptr_t)sjg_string10;
#line 4 ".\..\lib\common\array.sj"
    sjv_phongColorShader.pixel.data._isGlobal = false;
#line 0 ""
    sjf_array_char(&sjv_phongColorShader.pixel.data);
    sjf_string(&sjv_phongColorShader.pixel);
    sjf_shader(&sjv_phongColorShader);
#line 6 ".\..\lib\ui\shader.sj"
    sjv_phongTextureShader.vertex.count = 30;
#line 6
    sjv_phongTextureShader.vertex.data.size = 31;
#line 6
    sjv_phongTextureShader.vertex.data.data = (uintptr_t)sjg_string11;
#line 4 ".\..\lib\common\array.sj"
    sjv_phongTextureShader.vertex.data._isGlobal = false;
#line 0 ""
    sjf_array_char(&sjv_phongTextureShader.vertex.data);
    sjf_string(&sjv_phongTextureShader.vertex);
#line 6 ".\..\lib\ui\shader.sj"
    sjv_phongTextureShader.pixel.count = 30;
#line 6
    sjv_phongTextureShader.pixel.data.size = 31;
#line 6
    sjv_phongTextureShader.pixel.data.data = (uintptr_t)sjg_string12;
#line 4 ".\..\lib\common\array.sj"
    sjv_phongTextureShader.pixel.data._isGlobal = false;
#line 0 ""
    sjf_array_char(&sjv_phongTextureShader.pixel.data);
    sjf_string(&sjv_phongTextureShader.pixel);
    sjf_shader(&sjv_phongTextureShader);
#line 7 ".\..\lib\ui\shader.sj"
    sjv_textShader.vertex.count = 24;
#line 7
    sjv_textShader.vertex.data.size = 25;
#line 7
    sjv_textShader.vertex.data.data = (uintptr_t)sjg_string13;
#line 4 ".\..\lib\common\array.sj"
    sjv_textShader.vertex.data._isGlobal = false;
#line 0 ""
    sjf_array_char(&sjv_textShader.vertex.data);
    sjf_string(&sjv_textShader.vertex);
#line 7 ".\..\lib\ui\shader.sj"
    sjv_textShader.pixel.count = 24;
#line 7
    sjv_textShader.pixel.data.size = 25;
#line 7
    sjv_textShader.pixel.data.data = (uintptr_t)sjg_string14;
#line 4 ".\..\lib\common\array.sj"
    sjv_textShader.pixel.data._isGlobal = false;
#line 0 ""
    sjf_array_char(&sjv_textShader.pixel.data);
    sjf_string(&sjv_textShader.pixel);
    sjf_shader(&sjv_textShader);
    sjf_anon9(&sjv_style);
#line 1 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjv_vertex_location_texture_normal_format.count = 32;
#line 1
    sjv_vertex_location_texture_normal_format.data.size = 33;
#line 1
    sjv_vertex_location_texture_normal_format.data.data = (uintptr_t)sjg_string15;
#line 4 ".\..\lib\common\array.sj"
    sjv_vertex_location_texture_normal_format.data._isGlobal = false;
#line 0 ""
    sjf_array_char(&sjv_vertex_location_texture_normal_format.data);
    sjf_string(&sjv_vertex_location_texture_normal_format);
    sjt_cast2 = (sjs_fillElement_heap*)malloc(sizeof(sjs_fillElement_heap));
    sjt_cast2->_refCount = 1;
#line 5 ".\app\timer.sj"
    sjt_cast2->children.size = 2;
#line 3 ".\..\lib\common\array.sj"
    sjt_cast3 = 0;
#line 3
    sjt_cast2->children.data = (uintptr_t)sjt_cast3;
#line 4
    sjt_cast2->children._isGlobal = false;
#line 0 ""
    sjf_array_heap_element(&sjt_cast2->children);
#line 5 ".\app\timer.sj"
    sjs_array_heap_element* array7;
#line 5
    array7 = &sjt_cast2->children;
#line 5
    sjt_parent7 = array7;
#line 5
    sjt_functionParam4 = 0;
#line 0 ""
    sjt_cast4 = (sjs_scene3dElement_heap*)malloc(sizeof(sjs_scene3dElement_heap));
    sjt_cast4->_refCount = 1;
#line 7 ".\app\timer.sj"
    sjt_cast4->children.size = 1;
#line 3 ".\..\lib\common\array.sj"
    sjt_cast10 = 0;
#line 3
    sjt_cast4->children.data = (uintptr_t)sjt_cast10;
#line 4
    sjt_cast4->children._isGlobal = false;
#line 0 ""
    sjf_array_heap_model(&sjt_cast4->children);
#line 7 ".\app\timer.sj"
    sjs_array_heap_model* array6;
#line 7
    array6 = &sjt_cast4->children;
#line 7
    sjt_parent43 = array6;
#line 7
    sjt_functionParam63 = 0;
#line 0 ""
    sjt_cast11 = (sjs_scene2dModel_heap*)malloc(sizeof(sjs_scene2dModel_heap));
    sjt_cast11->_refCount = 1;
#line 92 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_functionParam149 = 20;
#line 93
    sjt_functionParam150 = 40;
#line 94
    sjt_call7.x = 0.0f;
#line 94
    sjt_call7.y = 0.0f;
#line 94
    sjt_call7.z = 0.0f;
#line 0 ""
    sjf_vec3(&sjt_call7);
#line 94 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_functionParam151 = &sjt_call7;
#line 95
    sjt_call8.x = 1.0f;
#line 95
    sjt_call8.y = 1.0f;
#line 95
    sjt_call8.z = 1.0f;
#line 0 ""
    sjf_vec3(&sjt_call8);
#line 95 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_functionParam152 = &sjt_call8;
#line 0 ""
    sjf_sphereVertexBuffer(sjt_functionParam149, sjt_functionParam150, sjt_functionParam151, sjt_functionParam152, &sjt_cast11->vertexBuffer);
#line 8 ".\app\timer.sj"
    sjf_shader_copy(&sjt_cast11->shader, &sjv_phongTextureShader);
#line 4 ".\..\lib\ui\scene2dModel.sj"
    sjt_cast11->frameBuffer.size.w = 512;
#line 4
    sjt_cast11->frameBuffer.size.h = 512;
#line 0 ""
    sjf_size(&sjt_cast11->frameBuffer.size);
    sjf_frameBuffer(&sjt_cast11->frameBuffer);
#line 11 ".\app\timer.sj"
    sjt_cast11->children.size = 2;
#line 3 ".\..\lib\common\array.sj"
    sjt_cast42 = 0;
#line 3
    sjt_cast11->children.data = (uintptr_t)sjt_cast42;
#line 4
    sjt_cast11->children._isGlobal = false;
#line 0 ""
    sjf_array_heap_element(&sjt_cast11->children);
#line 11 ".\app\timer.sj"
    sjs_array_heap_element* array5;
#line 11
    array5 = &sjt_cast11->children;
#line 11
    sjt_parent101 = array5;
#line 11
    sjt_functionParam153 = 0;
#line 0 ""
    sjt_cast43 = (sjs_imageElement_heap*)malloc(sizeof(sjs_imageElement_heap));
    sjt_cast43->_refCount = 1;
#line 13 ".\app\timer.sj"
    sjt_call9.count = 15;
#line 13
    sjt_call9.data.size = 16;
#line 13
    sjt_call9.data.data = (uintptr_t)sjg_string16;
#line 4 ".\..\lib\common\array.sj"
    sjt_call9.data._isGlobal = false;
#line 0 ""
    sjf_array_char(&sjt_call9.data);
    sjf_string(&sjt_call9);
#line 13 ".\app\timer.sj"
    sjt_functionParam158 = &sjt_call9;
#line 0 ""
    sjf_textureFromPng(sjt_functionParam158, &sjt_cast43->image.texture);
#line 2 ".\..\lib\ui\rect.sj"
    sjt_cast43->image.rect.x = 0;
#line 3
    sjt_cast43->image.rect.y = 0;
#line 4
    sjt_cast43->image.rect.w = 0;
#line 5
    sjt_cast43->image.rect.h = 0;
#line 0 ""
    sjf_rect(&sjt_cast43->image.rect);
#line 13 ".\app\timer.sj"
    sjt_cast43->image.margin.l = 150;
#line 13
    sjt_cast43->image.margin.t = 50;
#line 13
    sjt_cast43->image.margin.r = 150;
#line 13
    sjt_cast43->image.margin.b = 150;
#line 0 ""
    sjf_margin(&sjt_cast43->image.margin);
    sjf_image(&sjt_cast43->image);
#line 2 ".\..\lib\ui\rect.sj"
    sjt_cast43->_rect.x = 0;
#line 3
    sjt_cast43->_rect.y = 0;
#line 4
    sjt_cast43->_rect.w = 0;
#line 5
    sjt_cast43->_rect.h = 0;
#line 0 ""
    sjf_rect(&sjt_cast43->_rect);
#line 4 ".\..\lib\ui\imageElement.sj"
    sjt_cast43->_margin.l = 10;
#line 4
    sjt_cast43->_margin.t = 10;
#line 4
    sjt_cast43->_margin.r = 10;
#line 4
    sjt_cast43->_margin.b = 10;
#line 0 ""
    sjf_margin(&sjt_cast43->_margin);
#line 5 ".\..\lib\ui\imageElement.sj"
    sjt_cast43->_imageRenderer = 0;
    if (sjt_cast43->_imageRenderer != 0) {
        sjt_cast43->_imageRenderer->_refCount++;
    }

#line 0 ""
    sjf_imageElement_heap(sjt_cast43);
#line 1 ".\..\lib\ui\element.sj"
    sjt_functionParam154 = (sji_element*)sjf_imageElement_heap_as_sji_element(sjt_cast43);
#line 0 ""
    sjf_array_heap_element_initAt(sjt_parent101, sjt_functionParam153, sjt_functionParam154);
#line 11 ".\app\timer.sj"
    sjt_parent107 = array5;
#line 11
    sjt_functionParam159 = 1;
#line 0 ""
    sjt_cast44 = (sjs_crossHairsElement_heap*)malloc(sizeof(sjs_crossHairsElement_heap));
    sjt_cast44->_refCount = 1;
#line 4 ".\..\lib\ui\color.sj"
    sjt_parent112 = &sjv_colors;
#line 0 ""
    sjf_anon8_blue(sjt_parent112, &sjt_cast44->color);
#line 2 ".\..\lib\ui\rect.sj"
    sjt_cast44->_rect.x = 0;
#line 3
    sjt_cast44->_rect.y = 0;
#line 4
    sjt_cast44->_rect.w = 0;
#line 5
    sjt_cast44->_rect.h = 0;
#line 0 ""
    sjf_rect(&sjt_cast44->_rect);
#line 4 ".\..\lib\ui\crossHairsElement.sj"
    sjt_cast44->_topDownRenderer = 0;
    if (sjt_cast44->_topDownRenderer != 0) {
        sjt_cast44->_topDownRenderer->_refCount++;
    }

#line 5
    sjt_cast44->_leftRightRenderer = 0;
    if (sjt_cast44->_leftRightRenderer != 0) {
        sjt_cast44->_leftRightRenderer->_refCount++;
    }

#line 2 ".\..\lib\ui\point.sj"
    sjt_cast44->_point.x = 0;
#line 3
    sjt_cast44->_point.y = 0;
#line 0 ""
    sjf_point(&sjt_cast44->_point);
    sjf_crossHairsElement_heap(sjt_cast44);
#line 1 ".\..\lib\ui\element.sj"
    sjt_functionParam160 = (sji_element*)sjf_crossHairsElement_heap_as_sji_element(sjt_cast44);
#line 0 ""
    sjf_array_heap_element_initAt(sjt_parent107, sjt_functionParam159, sjt_functionParam160);
#line 2 ".\..\lib\ui\size.sj"
    sjt_cast11->_innerScene._size.w = 0;
#line 3
    sjt_cast11->_innerScene._size.h = 0;
#line 0 ""
    sjf_size(&sjt_cast11->_innerScene._size);
#line 2 ".\..\lib\ui\mat4.sj"
    sjt_cast11->_innerScene.model.m00 = 0.0f;
#line 3
    sjt_cast11->_innerScene.model.m01 = 0.0f;
#line 4
    sjt_cast11->_innerScene.model.m02 = 0.0f;
#line 5
    sjt_cast11->_innerScene.model.m03 = 0.0f;
#line 6
    sjt_cast11->_innerScene.model.m10 = 0.0f;
#line 7
    sjt_cast11->_innerScene.model.m11 = 0.0f;
#line 8
    sjt_cast11->_innerScene.model.m12 = 0.0f;
#line 9
    sjt_cast11->_innerScene.model.m13 = 0.0f;
#line 10
    sjt_cast11->_innerScene.model.m20 = 0.0f;
#line 11
    sjt_cast11->_innerScene.model.m21 = 0.0f;
#line 12
    sjt_cast11->_innerScene.model.m22 = 0.0f;
#line 13
    sjt_cast11->_innerScene.model.m23 = 0.0f;
#line 14
    sjt_cast11->_innerScene.model.m30 = 0.0f;
#line 15
    sjt_cast11->_innerScene.model.m31 = 0.0f;
#line 16
    sjt_cast11->_innerScene.model.m32 = 0.0f;
#line 17
    sjt_cast11->_innerScene.model.m33 = 0.0f;
#line 0 ""
    sjf_mat4(&sjt_cast11->_innerScene.model);
#line 2 ".\..\lib\ui\mat4.sj"
    sjt_cast11->_innerScene.view.m00 = 0.0f;
#line 3
    sjt_cast11->_innerScene.view.m01 = 0.0f;
#line 4
    sjt_cast11->_innerScene.view.m02 = 0.0f;
#line 5
    sjt_cast11->_innerScene.view.m03 = 0.0f;
#line 6
    sjt_cast11->_innerScene.view.m10 = 0.0f;
#line 7
    sjt_cast11->_innerScene.view.m11 = 0.0f;
#line 8
    sjt_cast11->_innerScene.view.m12 = 0.0f;
#line 9
    sjt_cast11->_innerScene.view.m13 = 0.0f;
#line 10
    sjt_cast11->_innerScene.view.m20 = 0.0f;
#line 11
    sjt_cast11->_innerScene.view.m21 = 0.0f;
#line 12
    sjt_cast11->_innerScene.view.m22 = 0.0f;
#line 13
    sjt_cast11->_innerScene.view.m23 = 0.0f;
#line 14
    sjt_cast11->_innerScene.view.m30 = 0.0f;
#line 15
    sjt_cast11->_innerScene.view.m31 = 0.0f;
#line 16
    sjt_cast11->_innerScene.view.m32 = 0.0f;
#line 17
    sjt_cast11->_innerScene.view.m33 = 0.0f;
#line 0 ""
    sjf_mat4(&sjt_cast11->_innerScene.view);
#line 2 ".\..\lib\ui\mat4.sj"
    sjt_cast11->_innerScene.projection.m00 = 0.0f;
#line 3
    sjt_cast11->_innerScene.projection.m01 = 0.0f;
#line 4
    sjt_cast11->_innerScene.projection.m02 = 0.0f;
#line 5
    sjt_cast11->_innerScene.projection.m03 = 0.0f;
#line 6
    sjt_cast11->_innerScene.projection.m10 = 0.0f;
#line 7
    sjt_cast11->_innerScene.projection.m11 = 0.0f;
#line 8
    sjt_cast11->_innerScene.projection.m12 = 0.0f;
#line 9
    sjt_cast11->_innerScene.projection.m13 = 0.0f;
#line 10
    sjt_cast11->_innerScene.projection.m20 = 0.0f;
#line 11
    sjt_cast11->_innerScene.projection.m21 = 0.0f;
#line 12
    sjt_cast11->_innerScene.projection.m22 = 0.0f;
#line 13
    sjt_cast11->_innerScene.projection.m23 = 0.0f;
#line 14
    sjt_cast11->_innerScene.projection.m30 = 0.0f;
#line 15
    sjt_cast11->_innerScene.projection.m31 = 0.0f;
#line 16
    sjt_cast11->_innerScene.projection.m32 = 0.0f;
#line 17
    sjt_cast11->_innerScene.projection.m33 = 0.0f;
#line 0 ""
    sjf_mat4(&sjt_cast11->_innerScene.projection);
    sjf_scene2d(&sjt_cast11->_innerScene);
#line 2 ".\..\lib\ui\mat4.sj"
    sjt_cast11->_world.m00 = 0.0f;
#line 3
    sjt_cast11->_world.m01 = 0.0f;
#line 4
    sjt_cast11->_world.m02 = 0.0f;
#line 5
    sjt_cast11->_world.m03 = 0.0f;
#line 6
    sjt_cast11->_world.m10 = 0.0f;
#line 7
    sjt_cast11->_world.m11 = 0.0f;
#line 8
    sjt_cast11->_world.m12 = 0.0f;
#line 9
    sjt_cast11->_world.m13 = 0.0f;
#line 10
    sjt_cast11->_world.m20 = 0.0f;
#line 11
    sjt_cast11->_world.m21 = 0.0f;
#line 12
    sjt_cast11->_world.m22 = 0.0f;
#line 13
    sjt_cast11->_world.m23 = 0.0f;
#line 14
    sjt_cast11->_world.m30 = 0.0f;
#line 15
    sjt_cast11->_world.m31 = 0.0f;
#line 16
    sjt_cast11->_world.m32 = 0.0f;
#line 17
    sjt_cast11->_world.m33 = 0.0f;
#line 0 ""
    sjf_mat4(&sjt_cast11->_world);
    sjf_scene2dModel_heap(sjt_cast11);
#line 1 ".\..\lib\ui\model.sj"
    sjt_functionParam64 = (sji_scene3dElement_model*)sjf_scene2dModel_heap_as_sji_scene3dElement_model(sjt_cast11);
#line 0 ""
    sjf_array_heap_model_initAt(sjt_parent43, sjt_functionParam63, sjt_functionParam64);
    sjt_cast4->camera = (sjs_property_vec3_heap*)malloc(sizeof(sjs_property_vec3_heap));
    sjt_cast4->camera->_refCount = 1;
#line 3 ".\..\lib\ui\scene3dElement.sj"
    sjt_cast4->camera->t.x = 0.0f;
#line 3
    sjt_cast4->camera->t.y = 0.0f;
#line 3
    sjt_negate9 = 5.0f;
#line 3
    result19 = -sjt_negate9;
#line 3
    sjt_cast4->camera->t.z = result19;
#line 0 ""
    sjf_vec3(&sjt_cast4->camera->t);
#line 2 ".\..\lib\common\list.sj"
    sjt_cast4->camera->invalidate.count = 0;
#line 3
    sjt_cast4->camera->invalidate.data.size = 0;
#line 3 ".\..\lib\common\array.sj"
    sjt_cast45 = 0;
#line 3
    sjt_cast4->camera->invalidate.data.data = (uintptr_t)sjt_cast45;
#line 4
    sjt_cast4->camera->invalidate.data._isGlobal = false;
#line 0 ""
    sjf_array_local_cb_void(&sjt_cast4->camera->invalidate.data);
    sjf_list_local_cb_void(&sjt_cast4->camera->invalidate);
#line 4 ".\..\lib\ui\property.sj"
    sjt_cast4->camera->_isDirty = false;
#line 0 ""
    sjf_property_vec3_heap(sjt_cast4->camera);
#line 4 ".\..\lib\ui\scene3dElement.sj"
    sjt_cast4->lookAt.x = 0.0f;
#line 4
    sjt_cast4->lookAt.y = 0.0f;
#line 4
    sjt_cast4->lookAt.z = 0.0f;
#line 0 ""
    sjf_vec3(&sjt_cast4->lookAt);
#line 5 ".\..\lib\ui\scene3dElement.sj"
    sjt_cast4->up.x = 0.0f;
#line 5
    sjt_cast4->up.y = 1.0f;
#line 5
    sjt_cast4->up.z = 0.0f;
#line 0 ""
    sjf_vec3(&sjt_cast4->up);
#line 6 ".\..\lib\ui\scene3dElement.sj"
    sjt_cast4->fieldOfView = 90.0f;
#line 7
    sjt_cast4->zNear = 1.0f;
#line 8
    sjt_cast4->zFar = 20.0f;
#line 9
    sjt_cast4->lightPos.x = 1.0f;
#line 9
    sjt_cast4->lightPos.y = 1.0f;
#line 9
    sjt_cast4->lightPos.z = 1.0f;
#line 0 ""
    sjf_vec3(&sjt_cast4->lightPos);
#line 10 ".\..\lib\ui\scene3dElement.sj"
    sjt_cast4->diffuseColor.r = 0.5f;
#line 10
    sjt_cast4->diffuseColor.g = 0.5f;
#line 10
    sjt_cast4->diffuseColor.b = 0.0f;
#line 10
    sjt_cast4->diffuseColor.a = 1.0f;
#line 0 ""
    sjf_color(&sjt_cast4->diffuseColor);
#line 11 ".\..\lib\ui\scene3dElement.sj"
    sjt_cast4->specColor.r = 1.0f;
#line 11
    sjt_cast4->specColor.g = 1.0f;
#line 11
    sjt_cast4->specColor.b = 1.0f;
#line 11
    sjt_cast4->specColor.a = 1.0f;
#line 0 ""
    sjf_color(&sjt_cast4->specColor);
#line 2 ".\..\lib\ui\mat4.sj"
    sjt_cast4->projection.m00 = 0.0f;
#line 3
    sjt_cast4->projection.m01 = 0.0f;
#line 4
    sjt_cast4->projection.m02 = 0.0f;
#line 5
    sjt_cast4->projection.m03 = 0.0f;
#line 6
    sjt_cast4->projection.m10 = 0.0f;
#line 7
    sjt_cast4->projection.m11 = 0.0f;
#line 8
    sjt_cast4->projection.m12 = 0.0f;
#line 9
    sjt_cast4->projection.m13 = 0.0f;
#line 10
    sjt_cast4->projection.m20 = 0.0f;
#line 11
    sjt_cast4->projection.m21 = 0.0f;
#line 12
    sjt_cast4->projection.m22 = 0.0f;
#line 13
    sjt_cast4->projection.m23 = 0.0f;
#line 14
    sjt_cast4->projection.m30 = 0.0f;
#line 15
    sjt_cast4->projection.m31 = 0.0f;
#line 16
    sjt_cast4->projection.m32 = 0.0f;
#line 17
    sjt_cast4->projection.m33 = 0.0f;
#line 0 ""
    sjf_mat4(&sjt_cast4->projection);
#line 2 ".\..\lib\ui\mat4.sj"
    sjt_cast4->view.m00 = 0.0f;
#line 3
    sjt_cast4->view.m01 = 0.0f;
#line 4
    sjt_cast4->view.m02 = 0.0f;
#line 5
    sjt_cast4->view.m03 = 0.0f;
#line 6
    sjt_cast4->view.m10 = 0.0f;
#line 7
    sjt_cast4->view.m11 = 0.0f;
#line 8
    sjt_cast4->view.m12 = 0.0f;
#line 9
    sjt_cast4->view.m13 = 0.0f;
#line 10
    sjt_cast4->view.m20 = 0.0f;
#line 11
    sjt_cast4->view.m21 = 0.0f;
#line 12
    sjt_cast4->view.m22 = 0.0f;
#line 13
    sjt_cast4->view.m23 = 0.0f;
#line 14
    sjt_cast4->view.m30 = 0.0f;
#line 15
    sjt_cast4->view.m31 = 0.0f;
#line 16
    sjt_cast4->view.m32 = 0.0f;
#line 17
    sjt_cast4->view.m33 = 0.0f;
#line 0 ""
    sjf_mat4(&sjt_cast4->view);
#line 2 ".\..\lib\ui\rect.sj"
    sjt_cast4->_rect.x = 0;
#line 3
    sjt_cast4->_rect.y = 0;
#line 4
    sjt_cast4->_rect.w = 0;
#line 5
    sjt_cast4->_rect.h = 0;
#line 0 ""
    sjf_rect(&sjt_cast4->_rect);
#line 15 ".\..\lib\ui\scene3dElement.sj"
    sjt_cast4->_angle = 0.0f;
#line 16
    sjt_cast4->_isUp = true;
#line 9 ".\..\lib\ui\vertexBufferBuilders.sj"
    sjt_negate34 = 1.0f;
#line 9
    result44 = -sjt_negate34;
#line 9
    sjt_functionParam405 = result44;
#line 10
    sjt_functionParam406 = 1.0f;
#line 11
    sjt_negate35 = 1.0f;
#line 11
    result45 = -sjt_negate35;
#line 11
    sjt_functionParam407 = result45;
#line 12
    sjt_functionParam408 = 1.0f;
#line 13
    sjt_negate36 = 1.0f;
#line 13
    result46 = -sjt_negate36;
#line 13
    sjt_functionParam409 = result46;
#line 14
    sjt_functionParam410 = 1.0f;
#line 15
    sjt_functionParam411 = 0.0f;
#line 16
    sjt_functionParam412 = 1.0f;
#line 17
    sjt_functionParam413 = 0.0f;
#line 18
    sjt_functionParam414 = 1.0f;
#line 0 ""
    sjf_cubeVertexBuffer(sjt_functionParam405, sjt_functionParam406, sjt_functionParam407, sjt_functionParam408, sjt_functionParam409, sjt_functionParam410, sjt_functionParam411, sjt_functionParam412, sjt_functionParam413, sjt_functionParam414, &sjt_cast4->_cube);
    sjf_scene3dElement_heap(sjt_cast4);
#line 1 ".\..\lib\ui\element.sj"
    sjt_functionParam5 = (sji_element*)sjf_scene3dElement_heap_as_sji_element(sjt_cast4);
#line 0 ""
    sjf_array_heap_element_initAt(sjt_parent7, sjt_functionParam4, sjt_functionParam5);
#line 5 ".\app\timer.sj"
    sjt_parent233 = array7;
#line 5
    sjt_functionParam415 = 1;
#line 0 ""
    sjt_cast50 = (sjs_crossHairsElement_heap*)malloc(sizeof(sjs_crossHairsElement_heap));
    sjt_cast50->_refCount = 1;
#line 2 ".\..\lib\ui\color.sj"
    sjt_parent234 = &sjv_colors;
#line 0 ""
    sjf_anon8_red(sjt_parent234, &sjt_cast50->color);
#line 2 ".\..\lib\ui\rect.sj"
    sjt_cast50->_rect.x = 0;
#line 3
    sjt_cast50->_rect.y = 0;
#line 4
    sjt_cast50->_rect.w = 0;
#line 5
    sjt_cast50->_rect.h = 0;
#line 0 ""
    sjf_rect(&sjt_cast50->_rect);
#line 4 ".\..\lib\ui\crossHairsElement.sj"
    sjt_cast50->_topDownRenderer = 0;
    if (sjt_cast50->_topDownRenderer != 0) {
        sjt_cast50->_topDownRenderer->_refCount++;
    }

#line 5
    sjt_cast50->_leftRightRenderer = 0;
    if (sjt_cast50->_leftRightRenderer != 0) {
        sjt_cast50->_leftRightRenderer->_refCount++;
    }

#line 2 ".\..\lib\ui\point.sj"
    sjt_cast50->_point.x = 0;
#line 3
    sjt_cast50->_point.y = 0;
#line 0 ""
    sjf_point(&sjt_cast50->_point);
    sjf_crossHairsElement_heap(sjt_cast50);
#line 1 ".\..\lib\ui\element.sj"
    sjt_functionParam416 = (sji_element*)sjf_crossHairsElement_heap_as_sji_element(sjt_cast50);
#line 0 ""
    sjf_array_heap_element_initAt(sjt_parent233, sjt_functionParam415, sjt_functionParam416);
#line 2 ".\..\lib\ui\rect.sj"
    sjt_cast2->_rect.x = 0;
#line 3
    sjt_cast2->_rect.y = 0;
#line 4
    sjt_cast2->_rect.w = 0;
#line 5
    sjt_cast2->_rect.h = 0;
#line 0 ""
    sjf_rect(&sjt_cast2->_rect);
    sjf_fillElement_heap(sjt_cast2);
#line 1 ".\..\lib\ui\element.sj"
    sjv_root = (sji_element*)sjf_fillElement_heap_as_sji_element(sjt_cast2);
#line 0 ""
    sjf_runLoop();
    main_destroy();
    return 0;
}

void main_destroy() {

    sjt_cast11->_refCount--;
    if (sjt_cast11->_refCount <= 0) {
        sjf_scene2dModel_destroy((sjs_scene2dModel*)(((char*)sjt_cast11) + sizeof(intptr_t)));
    }
    sjt_cast2->_refCount--;
    if (sjt_cast2->_refCount <= 0) {
        sjf_fillElement_destroy((sjs_fillElement*)(((char*)sjt_cast2) + sizeof(intptr_t)));
    }
    sjt_cast4->_refCount--;
    if (sjt_cast4->_refCount <= 0) {
        sjf_scene3dElement_destroy((sjs_scene3dElement*)(((char*)sjt_cast4) + sizeof(intptr_t)));
    }
    sjt_cast43->_refCount--;
    if (sjt_cast43->_refCount <= 0) {
        sjf_imageElement_destroy((sjs_imageElement*)(((char*)sjt_cast43) + sizeof(intptr_t)));
    }
    sjt_cast44->_refCount--;
    if (sjt_cast44->_refCount <= 0) {
        sjf_crossHairsElement_destroy((sjs_crossHairsElement*)(((char*)sjt_cast44) + sizeof(intptr_t)));
    }
    sjt_cast50->_refCount--;
    if (sjt_cast50->_refCount <= 0) {
        sjf_crossHairsElement_destroy((sjs_crossHairsElement*)(((char*)sjt_cast50) + sizeof(intptr_t)));
    }
    sjt_functionParam154->_refCount--;
    if (sjt_functionParam154->_refCount <= 0) {
        sji_element_destroy(sjt_functionParam154);
    }
    sjt_functionParam160->_refCount--;
    if (sjt_functionParam160->_refCount <= 0) {
        sji_element_destroy(sjt_functionParam160);
    }
    sjt_functionParam416->_refCount--;
    if (sjt_functionParam416->_refCount <= 0) {
        sji_element_destroy(sjt_functionParam416);
    }
    sjt_functionParam5->_refCount--;
    if (sjt_functionParam5->_refCount <= 0) {
        sji_element_destroy(sjt_functionParam5);
    }
    sjt_functionParam64->_refCount--;
    if (sjt_functionParam64->_refCount <= 0) {
        sji_scene3dElement_model_destroy(sjt_functionParam64);
    }
    sjv_root->_refCount--;
    if (sjv_root->_refCount <= 0) {
        sji_element_destroy(sjv_root);
    }
    sjf_vec3_destroy(&sjt_call7);
    sjf_vec3_destroy(&sjt_call8);
    sjf_string_destroy(&sjt_call9);
    sjf_anon5_destroy(&sjv_animator);
    sjf_shader_destroy(&sjv_blurHorizontalShader);
    sjf_shader_destroy(&sjv_blurVerticalShader);
    sjf_anon6_destroy(&sjv_borderPosition);
    sjf_shader_destroy(&sjv_boxShader);
    sjf_anon7_destroy(&sjv_buttonState);
    sjf_anon8_destroy(&sjv_colors);
    sjf_anon1_destroy(&sjv_console);
    sjf_anon2_destroy(&sjv_convert);
    sjf_shader_destroy(&sjv_imageShader);
    sjf_anon3_destroy(&sjv_parse);
    sjf_shader_destroy(&sjv_phongColorShader);
    sjf_shader_destroy(&sjv_phongTextureShader);
    sjf_anon4_destroy(&sjv_random);
    sjf_scene2d_destroy(&sjv_rootScene);
    sjf_windowRenderer_destroy(&sjv_rootWindowRenderer);
    sjf_anon9_destroy(&sjv_style);
    sjf_shader_destroy(&sjv_textShader);
    sjf_string_destroy(&sjv_vertex_location_texture_normal_format);
}
