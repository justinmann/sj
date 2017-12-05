
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
#define uthash_fatal(msg) exit(-1)        /* fatal OOM error */
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
#define HASH_OOPS(...) do { fprintf(stderr,__VA_ARGS__); exit(-1); } while (0)
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

const char* sjg_string1 = "shaders/v3f-t2f-c4f.vert";
const char* sjg_string2 = "shaders/v3f-t2f-c4f.frag";
const char* sjg_string3 = "shaders/v3f-c4f.vert";
const char* sjg_string4 = "shaders/v3f-c4f.frag";
const char* sjg_string5 = "shaders/v3f-t2f.vert";
const char* sjg_string6 = "shaders/v3f-t2f.frag";
const char* sjg_string7 = "assets/test.png";


typedef struct pointer_td pointer;
struct pointer_td {
    void* ptr;
    int refCount;
    UT_hash_handle hh;
};
pointer* g_pointers = 0;


typedef struct GLid_td GLid_s;
struct GLid_td {
    GLuint id;
    int refCount;
    UT_hash_handle hh;
};
GLid_s* g_GLids = 0;


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


/**
*
*/
typedef union
{
    float data[16];    /**< All compoments at once     */
    struct {
        float m00, m01, m02, m03;
        float m10, m11, m12, m13;
        float m20, m21, m22, m23;
        float m30, m31, m32, m33;
    };
} mat4;


typedef struct {
    float x, y, z;    // position
    float s, t;       // texture
    float r, g, b, a; // color
} vertex3_texture2_color3_t;


typedef struct {
    float x, y, z;    // position
    float r, g, b, a; // color
} vertex3_color4_t;


typedef struct {
    float x, y, z;    // position
    float s, t;       // texture
} vertex3_texture2_t;

#define sjs_object_typeId 1
#define sjs_anon1_typeId 2
#define sjs_anon1_heap_typeId 3
#define sjs_anon2_typeId 4
#define sjs_anon2_heap_typeId 5
#define sjs_anon3_typeId 6
#define sjs_anon3_heap_typeId 7
#define sjs_anon4_typeId 8
#define sjs_anon4_heap_typeId 9
#define sjs_size_typeId 10
#define sjs_size_heap_typeId 11
#define sjs_surface2d_typeId 12
#define sjs_surface2d_heap_typeId 13
#define sjs_anon5_typeId 14
#define sjs_anon5_heap_typeId 15
#define sjs_anon6_typeId 16
#define sjs_anon6_heap_typeId 17
#define sjs_anon7_typeId 18
#define sjs_anon7_heap_typeId 19
#define sjs_anon8_typeId 20
#define sjs_anon8_heap_typeId 21
#define sjs_array_char_typeId 22
#define sjs_array_char_heap_typeId 23
#define sjs_string_typeId 24
#define sjs_string_heap_typeId 25
#define sjs_shader_typeId 26
#define sjs_shader_heap_typeId 27
#define sjs_rect_typeId 28
#define sjs_rect_heap_typeId 29
#define sjs_texture_typeId 30
#define sjs_texture_heap_typeId 31
#define sjs_margin_typeId 32
#define sjs_margin_heap_typeId 33
#define sjs_image_typeId 34
#define sjs_image_heap_typeId 35
#define sjs_imageRenderer_typeId 36
#define sjs_imageRenderer_heap_typeId 37
#define sjs_imageElement_typeId 38
#define sjs_array_heap_element_typeId 39
#define sjs_array_heap_element_heap_typeId 40
#define sji_element_typeId 41
#define sjs_imageElement_heap_typeId 42
#define sjs_point_typeId 43
#define sjs_point_heap_typeId 44
#define sji_fireMouseUp_mouseHandler_typeId 45

typedef struct td_sjs_object sjs_object;
typedef struct td_sjs_anon1 sjs_anon1;
typedef struct td_sjs_anon1_heap sjs_anon1_heap;
typedef struct td_sjs_anon2 sjs_anon2;
typedef struct td_sjs_anon2_heap sjs_anon2_heap;
typedef struct td_sjs_anon3 sjs_anon3;
typedef struct td_sjs_anon3_heap sjs_anon3_heap;
typedef struct td_sjs_anon4 sjs_anon4;
typedef struct td_sjs_anon4_heap sjs_anon4_heap;
typedef struct td_sjs_size sjs_size;
typedef struct td_sjs_size_heap sjs_size_heap;
typedef struct td_sjs_surface2d sjs_surface2d;
typedef struct td_sjs_surface2d_heap sjs_surface2d_heap;
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
typedef struct td_sjs_rect sjs_rect;
typedef struct td_sjs_rect_heap sjs_rect_heap;
typedef struct td_sjs_texture sjs_texture;
typedef struct td_sjs_texture_heap sjs_texture_heap;
typedef struct td_sjs_margin sjs_margin;
typedef struct td_sjs_margin_heap sjs_margin_heap;
typedef struct td_sjs_image sjs_image;
typedef struct td_sjs_image_heap sjs_image_heap;
typedef struct td_sjs_imageRenderer sjs_imageRenderer;
typedef struct td_sjs_imageRenderer_heap sjs_imageRenderer_heap;
typedef struct td_sjs_imageElement sjs_imageElement;
typedef struct td_sjs_array_heap_element sjs_array_heap_element;
typedef struct td_sjs_array_heap_element_heap sjs_array_heap_element_heap;
typedef struct td_sji_element sji_element;
typedef struct td_sjs_imageElement_heap sjs_imageElement_heap;
typedef struct td_sjs_point sjs_point;
typedef struct td_sjs_point_heap sjs_point_heap;
typedef struct td_sji_fireMouseUp_mouseHandler sji_fireMouseUp_mouseHandler;

struct td_sjs_object {
    intptr_t _refCount;
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

struct td_sjs_size {
    int32_t w;
    int32_t h;
};

struct td_sjs_size_heap {
    intptr_t _refCount;
    int32_t w;
    int32_t h;
};

struct td_sjs_surface2d {
    sjs_size _size;
    SDL_Window* win;
    SDL_Renderer* ren;
    mat4 model;
    mat4 view;
    mat4 projection;
};

struct td_sjs_surface2d_heap {
    intptr_t _refCount;
    sjs_size _size;
    SDL_Window* win;
    SDL_Renderer* ren;
    mat4 model;
    mat4 view;
    mat4 projection;
};

struct td_sjs_anon5 {
    int32_t normal;
    int32_t hot;
    int32_t pressed;
};

struct td_sjs_anon5_heap {
    intptr_t _refCount;
    int32_t normal;
    int32_t hot;
    int32_t pressed;
};

struct td_sjs_anon6 {
    int structsNeedAValue;
};

struct td_sjs_anon6_heap {
    intptr_t _refCount;
};

struct td_sjs_anon7 {
    int structsNeedAValue;
};

struct td_sjs_anon7_heap {
    intptr_t _refCount;
};

struct td_sjs_anon8 {
    int32_t fill;
    int32_t left;
    int32_t right;
    int32_t top;
    int32_t bottom;
};

struct td_sjs_anon8_heap {
    intptr_t _refCount;
    int32_t fill;
    int32_t left;
    int32_t right;
    int32_t top;
    int32_t bottom;
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

struct td_sji_element {
    intptr_t _refCount;
    sjs_object* _parent;
    void (*destroy)(void* _this);
    sjs_object* (*asInterface)(sjs_object* _this, int typeId);
    void (*getSize)(void* _parent, sjs_size* maxSize, sjs_size* _return);
    void (*getSize_heap)(void* _parent, sjs_size* maxSize, sjs_size_heap** _return);
    void (*getRect)(void* _parent, sjs_rect** _return);
    void (*setRect)(void* _parent, sjs_rect* rect);
    void (*render)(void* _parent, sjs_surface2d* surface);
    void (*getChildren)(void* _parent, sjs_array_heap_element** _return);
};

struct td_sjs_imageElement_heap {
    intptr_t _refCount;
    sjs_image image;
    sjs_rect _rect;
    sjs_margin _margin;
    sjs_imageRenderer_heap* _imageRenderer;
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

struct td_sji_fireMouseUp_mouseHandler {
    intptr_t _refCount;
    sjs_object* _parent;
    void (*destroy)(void* _this);
    sjs_object* (*asInterface)(sjs_object* _this, int typeId);
    void (*onMouseUp)(void* _parent, sjs_point* point);
    void (*onMouseDown)(void* _parent, sjs_point* point);
    void (*onMouseMove)(void* _parent, sjs_point* point);
};


void _retain(void* ptr);
bool _release(void* ptr);


void _retainGLid(GLuint id);
bool _releaseGLid(GLuint id);


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


mat4 *
mat4_new( void );
void
mat4_set_identity( mat4 *self );
void
mat4_set_zero( mat4 *self );
void
mat4_multiply( mat4 *self, mat4 *other );
void
mat4_set_orthographic( mat4 *self,
float left,   float right,
float bottom, float top,
float znear,  float zfar );
void
mat4_set_perspective( mat4 *self,
float fovy,  float aspect,
float zNear, float zFar);
void
mat4_set_frustum( mat4 *self,
float left,   float right,
float bottom, float top,
float znear,  float zfar );
void
mat4_set_rotation( mat4 *self,
float angle,
float x, float y, float z);
void
mat4_set_translation( mat4 *self,
float x, float y, float z);
void
mat4_set_scaling( mat4 *self,
float x, float y, float z);
void
mat4_rotate( mat4 *self,
float angle,
float x, float y, float z);
void
mat4_translate( mat4 *self,
float x, float y, float z);
void
mat4_scale( mat4 *self,
float x, float y, float z);


void add_text(vertex_buffer_t * buffer, texture_font_t * font, char *text, vec4 * color, vec2 * pen);
vec2 get_text_size(texture_font_t * font, char *text);

sjs_string sjt_call1;
sjs_imageElement_heap* sjt_cast1;
sjs_string* sjt_functionParam4;
sjs_anon8 sjv_borderPosition;
sjs_shader sjv_boxShader;
sjs_anon5 sjv_buttonState;
sjs_anon6 sjv_colors;
sjs_anon1 sjv_console;
sjs_anon4 sjv_convert;
int32_t sjv_frame;
int32_t sjv_i32_max;
int32_t sjv_i32_min;
sjs_shader sjv_imageShader;
sjs_anon2 sjv_parse;
sjs_anon3 sjv_random;
sji_element* sjv_root;
sjs_surface2d sjv_rootSurface;
sjs_anon7 sjv_style;
sjs_shader sjv_textShader;
uint32_t sjv_u32_max;

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
void sjf_anon6(sjs_anon6* _this);
void sjf_anon6_copy(sjs_anon6* _this, sjs_anon6* _from);
void sjf_anon6_destroy(sjs_anon6* _this);
void sjf_anon6_heap(sjs_anon6_heap* _this);
void sjf_anon7(sjs_anon7* _this);
void sjf_anon7_copy(sjs_anon7* _this, sjs_anon7* _from);
void sjf_anon7_destroy(sjs_anon7* _this);
void sjf_anon7_heap(sjs_anon7_heap* _this);
void sjf_anon8(sjs_anon8* _this);
void sjf_anon8_copy(sjs_anon8* _this, sjs_anon8* _from);
void sjf_anon8_destroy(sjs_anon8* _this);
void sjf_anon8_heap(sjs_anon8_heap* _this);
void sjf_array_char(sjs_array_char* _this);
void sjf_array_char_copy(sjs_array_char* _this, sjs_array_char* _from);
void sjf_array_char_destroy(sjs_array_char* _this);
void sjf_array_char_heap(sjs_array_char_heap* _this);
void sjf_array_heap_element(sjs_array_heap_element* _this);
void sjf_array_heap_element_copy(sjs_array_heap_element* _this, sjs_array_heap_element* _from);
void sjf_array_heap_element_destroy(sjs_array_heap_element* _this);
void sjf_array_heap_element_getAt_heap(sjs_array_heap_element* _parent, int32_t index, sji_element** _return);
void sjf_array_heap_element_heap(sjs_array_heap_element_heap* _this);
void sjf_fireMouseDown(sji_element* element, sjs_point* point);
void sjf_fireMouseUp(sji_element* element, sjs_point* point);
void sjf_image(sjs_image* _this);
void sjf_imageElement(sjs_imageElement* _this);
sjs_object* sjf_imageElement_asInterface(sjs_imageElement* _this, int typeId);
sji_element* sjf_imageElement_as_sji_element(sjs_imageElement* _this);
void sjf_imageElement_copy(sjs_imageElement* _this, sjs_imageElement* _from);
void sjf_imageElement_destroy(sjs_imageElement* _this);
void sjf_imageElement_getChildren(sjs_imageElement* _parent, sjs_array_heap_element** _return);
void sjf_imageElement_getRect(sjs_imageElement* _parent, sjs_rect** _return);
void sjf_imageElement_getSize(sjs_imageElement* _parent, sjs_size* maxSize, sjs_size* _return);
void sjf_imageElement_getSize_heap(sjs_imageElement* _parent, sjs_size* maxSize, sjs_size_heap** _return);
void sjf_imageElement_heap(sjs_imageElement_heap* _this);
sjs_object* sjf_imageElement_heap_asInterface(sjs_imageElement_heap* _this, int typeId);
sji_element* sjf_imageElement_heap_as_sji_element(sjs_imageElement_heap* _this);
void sjf_imageElement_render(sjs_imageElement* _parent, sjs_surface2d* surface);
void sjf_imageElement_setRect(sjs_imageElement* _parent, sjs_rect* rect_);
void sjf_imageRenderer(sjs_imageRenderer* _this);
void sjf_imageRenderer_copy(sjs_imageRenderer* _this, sjs_imageRenderer* _from);
void sjf_imageRenderer_destroy(sjs_imageRenderer* _this);
void sjf_imageRenderer_heap(sjs_imageRenderer_heap* _this);
void sjf_imageRenderer_render(sjs_imageRenderer* _parent, sjs_surface2d* surface);
void sjf_image_copy(sjs_image* _this, sjs_image* _from);
void sjf_image_destroy(sjs_image* _this);
void sjf_image_heap(sjs_image_heap* _this);
void sjf_mainLoop(void);
void sjf_margin(sjs_margin* _this);
void sjf_margin_copy(sjs_margin* _this, sjs_margin* _from);
void sjf_margin_destroy(sjs_margin* _this);
void sjf_margin_heap(sjs_margin_heap* _this);
void sjf_point(sjs_point* _this);
void sjf_point_copy(sjs_point* _this, sjs_point* _from);
void sjf_point_destroy(sjs_point* _this);
void sjf_point_heap(sjs_point_heap* _this);
void sjf_rect(sjs_rect* _this);
void sjf_rect_containsPoint(sjs_rect* _parent, sjs_point* point, bool* _return);
void sjf_rect_copy(sjs_rect* _this, sjs_rect* _from);
void sjf_rect_destroy(sjs_rect* _this);
void sjf_rect_heap(sjs_rect_heap* _this);
void sjf_rect_isEqual(sjs_rect* _parent, sjs_rect* rect, bool* _return);
void sjf_rect_subtractMargin(sjs_rect* _parent, sjs_margin* margin, sjs_rect* _return);
void sjf_rect_subtractMargin_heap(sjs_rect* _parent, sjs_margin* margin, sjs_rect_heap** _return);
void sjf_runLoop(void);
void sjf_shader(sjs_shader* _this);
void sjf_shader_copy(sjs_shader* _this, sjs_shader* _from);
void sjf_shader_destroy(sjs_shader* _this);
void sjf_shader_heap(sjs_shader_heap* _this);
void sjf_size(sjs_size* _this);
void sjf_size_copy(sjs_size* _this, sjs_size* _from);
void sjf_size_destroy(sjs_size* _this);
void sjf_size_heap(sjs_size_heap* _this);
void sjf_string(sjs_string* _this);
void sjf_string_copy(sjs_string* _this, sjs_string* _from);
void sjf_string_destroy(sjs_string* _this);
void sjf_string_heap(sjs_string_heap* _this);
void sjf_surface2d(sjs_surface2d* _this);
void sjf_surface2d_clear(sjs_surface2d* _parent);
void sjf_surface2d_copy(sjs_surface2d* _this, sjs_surface2d* _from);
void sjf_surface2d_destroy(sjs_surface2d* _this);
void sjf_surface2d_getSize(sjs_surface2d* _parent, sjs_size* _return);
void sjf_surface2d_getSize_heap(sjs_surface2d* _parent, sjs_size_heap** _return);
void sjf_surface2d_heap(sjs_surface2d_heap* _this);
void sjf_surface2d_present(sjs_surface2d* _parent);
void sjf_texture(sjs_texture* _this);
void sjf_textureFromPng(sjs_string* fileName, sjs_texture* _return);
void sjf_textureFromPng_heap(sjs_string* fileName, sjs_texture_heap** _return);
void sjf_texture_copy(sjs_texture* _this, sjs_texture* _from);
void sjf_texture_destroy(sjs_texture* _this);
void sjf_texture_getSize(sjs_texture* _parent, sjs_size* _return);
void sjf_texture_getSize_heap(sjs_texture* _parent, sjs_size_heap** _return);
void sjf_texture_heap(sjs_texture_heap* _this);
void sji_element_copy(sji_element* _this, sji_element* _from);
void sji_element_destroy(sji_element* _this);
void sji_fireMouseUp_mouseHandler_copy(sji_fireMouseUp_mouseHandler* _this, sji_fireMouseUp_mouseHandler* _from);
void sji_fireMouseUp_mouseHandler_destroy(sji_fireMouseUp_mouseHandler* _this);
void main_destroy(void);


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
    size_t cpylen, orglen, retlen, tolen, fromlen = strlen(from);
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
            fprintf( stderr, "%s: %s\n", source, messages );
            exit( EXIT_FAILURE );
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
            fprintf( stderr, "%s\n", messages );
            exit(1);
        }
        return handle;
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
            fprintf( stderr,
            "line %d: No more memory for allocating data\n", __LINE__ );
            exit( EXIT_FAILURE );
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
            fprintf( stderr,
            "line %d: No more memory for allocating data\n", __LINE__ );
            exit( EXIT_FAILURE );
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
            fprintf( stderr,
            "line %d: No more memory for allocating data\n", __LINE__ );
            exit( EXIT_FAILURE );
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


    // ------------------------------------------------------------- vector_new ---
    vector_t *
    vector_new( size_t item_size )
    {
        vector_t *self = (vector_t *) malloc( sizeof(vector_t) );
        assert( item_size );
        if( !self )
        {
            fprintf( stderr,
            "line %d: No more memory for allocating data\n", __LINE__ );
            exit( EXIT_FAILURE );
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


    mat4 *
    mat4_new( void )
    {
        mat4 *self = (mat4 *) malloc( sizeof(mat4) );
        return self;
    }
    void
    mat4_set_zero( mat4 *self )
    {
        if (!self)
        return;
        memset( self, 0, sizeof( mat4 ));
    }
    void
    mat4_set_identity( mat4 *self )
    {
        if (!self)
        return;
        memset( self, 0, sizeof( mat4 ));
        self->m00 = 1.0;
        self->m11 = 1.0;
        self->m22 = 1.0;
        self->m33 = 1.0;
    }
    void
    mat4_multiply( mat4 *self, mat4 *other )
    {
        mat4 m;
        size_t i;
        if (!self || !other)
        return;
        for( i=0; i<4; ++i )
        {
            m.data[i*4+0] =
            (self->data[i*4+0] * other->data[0*4+0]) +
            (self->data[i*4+1] * other->data[1*4+0]) +
            (self->data[i*4+2] * other->data[2*4+0]) +
            (self->data[i*4+3] * other->data[3*4+0]) ;
            m.data[i*4+1] =
            (self->data[i*4+0] * other->data[0*4+1]) +
            (self->data[i*4+1] * other->data[1*4+1]) +
            (self->data[i*4+2] * other->data[2*4+1]) +
            (self->data[i*4+3] * other->data[3*4+1]) ;
            m.data[i*4+2] =
            (self->data[i*4+0] * other->data[0*4+2]) +
            (self->data[i*4+1] * other->data[1*4+2]) +
            (self->data[i*4+2] * other->data[2*4+2]) +
            (self->data[i*4+3] * other->data[3*4+2]) ;
            m.data[i*4+3] =
            (self->data[i*4+0] * other->data[0*4+3]) +
            (self->data[i*4+1] * other->data[1*4+3]) +
            (self->data[i*4+2] * other->data[2*4+3]) +
            (self->data[i*4+3] * other->data[3*4+3]) ;
        }
        memcpy( self, &m, sizeof( mat4 ) );
    }
    void
    mat4_set_orthographic( mat4 *self,
    float left,   float right,
    float bottom, float top,
    float znear,  float zfar )
    {
        if (!self)
        return;
        if (left == right || bottom == top || znear == zfar)
        return;
        mat4_set_zero( self );
        self->m00 = +2.0f/(right-left);
        self->m30 = -(right+left)/(right-left);
        self->m11 = +2.0f/(top-bottom);
        self->m31 = -(top+bottom)/(top-bottom);
        self->m22 = -2.0f/(zfar-znear);
        self->m32 = -(zfar+znear)/(zfar-znear);
        self->m33 = 1.0f;
    }
    void
    mat4_set_perspective( mat4 *self,
    float fovy,  float aspect,
    float znear, float zfar)
    {
        float h, w;
        if (!self)
        return;
        if (znear == zfar)
        return;
        h = (float)tan(fovy / 360.0 * M_PI) * znear;
        w = h * aspect;
        mat4_set_frustum( self, -w, w, -h, h, znear, zfar );
    }
    void
    mat4_set_frustum( mat4 *self,
    float left,   float right,
    float bottom, float top,
    float znear,  float zfar )
    {
        if (!self)
        return;
        if (left == right || bottom == top || znear == zfar)
        return;
        mat4_set_zero( self );
        self->m00 = (2.0f*znear)/(right-left);
        self->m20 = (right+left)/(right-left);
        self->m11 = (2.0f*znear)/(top-bottom);
        self->m21 = (top+bottom)/(top-bottom);
        self->m22 = -(zfar+znear)/(zfar-znear);
        self->m32 = -(2.0f*zfar*znear)/(zfar-znear);
        self->m23 = -1.0f;
    }
    void
    mat4_set_rotation( mat4 *self,
    float angle,
    float x, float y, float z)
    {
        float c, s, norm;
        if (!self)
        return;
        c = (float)cos( M_PI*angle/180.0 );
        s = (float)sin( M_PI*angle/180.0 );
        norm = (float)sqrt(x*x+y*y+z*z);
        x /= norm; y /= norm; z /= norm;
        mat4_set_identity( self );
        self->m00 = x*x*(1-c)+c;
        self->m10 = y*x*(1-c)-z*s;
        self->m20 = z*x*(1-c)+y*s;
        self->m01 =  x*y*(1-c)+z*s;
        self->m11 =  y*y*(1-c)+c;
        self->m21 =  z*y*(1-c)-x*s;
        self->m02 = x*z*(1-c)-y*s;
        self->m12 = y*z*(1-c)+x*s;
        self->m22 = z*z*(1-c)+c;
    }
    void
    mat4_set_translation( mat4 *self,
    float x, float y, float z)
    {
        if (!self)
        return;
        mat4_set_identity( self );
        self-> m30 = x;
        self-> m31 = y;
        self-> m32 = z;
    }
    void
    mat4_set_scaling( mat4 *self,
    float x, float y, float z)
    {
        if (!self)
        return;
        mat4_set_identity( self );
        self-> m00 = x;
        self-> m11 = y;
        self-> m22 = z;
    }
    void
    mat4_rotate( mat4 *self,
    float angle,
    float x, float y, float z)
    {
        mat4 m;
        if (!self)
        return;
        mat4_set_rotation( &m, angle, x, y, z);
        mat4_multiply( self, &m );
    }
    void
    mat4_translate( mat4 *self,
    float x, float y, float z)
    {
        mat4 m;
        if (!self)
        return;
        mat4_set_translation( &m, x, y, z);
        mat4_multiply( self, &m );
    }
    void
    mat4_scale( mat4 *self,
    float x, float y, float z)
    {
        mat4 m;
        if (!self)
        return;
        mat4_set_scaling( &m, x, y, z);
        mat4_multiply( self, &m );
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
    _this->normal = _from->normal;
    _this->hot = _from->hot;
    _this->pressed = _from->pressed;
}

void sjf_anon5_destroy(sjs_anon5* _this) {
}

void sjf_anon5_heap(sjs_anon5_heap* _this) {
}

void sjf_anon6(sjs_anon6* _this) {
}

void sjf_anon6_copy(sjs_anon6* _this, sjs_anon6* _from) {
}

void sjf_anon6_destroy(sjs_anon6* _this) {
}

void sjf_anon6_heap(sjs_anon6_heap* _this) {
}

void sjf_anon7(sjs_anon7* _this) {
}

void sjf_anon7_copy(sjs_anon7* _this, sjs_anon7* _from) {
}

void sjf_anon7_destroy(sjs_anon7* _this) {
}

void sjf_anon7_heap(sjs_anon7_heap* _this) {
}

void sjf_anon8(sjs_anon8* _this) {
}

void sjf_anon8_copy(sjs_anon8* _this, sjs_anon8* _from) {
    _this->fill = _from->fill;
    _this->left = _from->left;
    _this->right = _from->right;
    _this->top = _from->top;
    _this->bottom = _from->bottom;
}

void sjf_anon8_destroy(sjs_anon8* _this) {
}

void sjf_anon8_heap(sjs_anon8_heap* _this) {
}

void sjf_array_char(sjs_array_char* _this) {
    if (_this->size < 0) {
        exit(-1);
    }
    if (_this->data) {
        _this->_isGlobal = true;
    } else {
        _this->data = (uintptr_t)calloc(_this->size * sizeof(char), 1);
        if (!_this->data) {
            printf("grow: out of memory\n");
            exit(-1);
        }
    }
}

void sjf_array_char_copy(sjs_array_char* _this, sjs_array_char* _from) {
    _this->size = _from->size;
    _this->data = _from->data;
    _this->_isGlobal = _from->_isGlobal;
    _this->data = _from->data;
    if (!_this->_isGlobal && _this->data) {
        _retain((void*)_this->data);
    }
}

void sjf_array_char_destroy(sjs_array_char* _this) {
    if (!_this->_isGlobal && _this->data) {
        if (_release((void*)_this->data)) {
            free((char*)_this->data);
        }
    }
}

void sjf_array_char_heap(sjs_array_char_heap* _this) {
    if (_this->size < 0) {
        exit(-1);
    }
    if (_this->data) {
        _this->_isGlobal = true;
    } else {
        _this->data = (uintptr_t)calloc(_this->size * sizeof(char), 1);
        if (!_this->data) {
            printf("grow: out of memory\n");
            exit(-1);
        }
    }
}

void sjf_array_heap_element(sjs_array_heap_element* _this) {
    if (_this->size < 0) {
        exit(-1);
    }
    if (_this->data) {
        _this->_isGlobal = true;
    } else {
        _this->data = (uintptr_t)calloc(_this->size * sizeof(sji_element*), 1);
        if (!_this->data) {
            printf("grow: out of memory\n");
            exit(-1);
        }
    }
}

void sjf_array_heap_element_copy(sjs_array_heap_element* _this, sjs_array_heap_element* _from) {
    _this->size = _from->size;
    _this->data = _from->data;
    _this->_isGlobal = _from->_isGlobal;
    _this->data = _from->data;
    if (!_this->_isGlobal && _this->data) {
        _retain((void*)_this->data);
    }
}

void sjf_array_heap_element_destroy(sjs_array_heap_element* _this) {
    if (!_this->_isGlobal && _this->data) {
        if (_release((void*)_this->data)) {
            free((sji_element**)_this->data);
        }
    }
}

void sjf_array_heap_element_getAt_heap(sjs_array_heap_element* _parent, int32_t index, sji_element** _return) {
    if (index >= _parent->size || index < 0) {
        printf("getAt: out of bounds\n");
        exit(-1);
    }
    sji_element** p = (sji_element**)_parent->data;
    (*_return) = p[index];
    (*_return)->_refCount++;
    ;
}

void sjf_array_heap_element_heap(sjs_array_heap_element_heap* _this) {
    if (_this->size < 0) {
        exit(-1);
    }
    if (_this->data) {
        _this->_isGlobal = true;
    } else {
        _this->data = (uintptr_t)calloc(_this->size * sizeof(sji_element*), 1);
        if (!_this->data) {
            printf("grow: out of memory\n");
            exit(-1);
        }
    }
}

void sjf_fireMouseDown(sji_element* element, sjs_point* point) {
    bool result6;
    sji_element* sjt_cast3;
    sjs_rect* sjt_dot61;
    sji_element* sjt_dot62;
    sji_element* sjt_dot64;
    sjs_point* sjt_functionParam11;
    bool sjt_ifElse12;
    bool sjt_ifElse14;
    sjs_array_heap_element* sjt_isEmpty6;
    bool sjt_not6;
    sjs_array_heap_element* sjv_children;
    sji_fireMouseUp_mouseHandler* sjv_mouseHandler;

    sjt_cast3 = element;
    sjt_cast3->_refCount++;
    sjv_mouseHandler = (sji_fireMouseUp_mouseHandler*)sjt_cast3->asInterface(sjt_cast3->_parent, sji_fireMouseUp_mouseHandler_typeId);
    sjt_dot62 = element;
    sjt_dot62->getRect((void*)(((char*)sjt_dot62->_parent) + sizeof(intptr_t)), &sjt_dot61);
    sjt_functionParam11 = point;
    sjf_rect_containsPoint(sjt_dot61, sjt_functionParam11, &sjt_ifElse12);
    if (sjt_ifElse12) {
        bool result5;
        bool sjt_ifElse13;
        sji_fireMouseUp_mouseHandler* sjt_isEmpty5;
        bool sjt_not5;

        sjt_isEmpty5 = sjv_mouseHandler;
        if (sjt_isEmpty5 != 0) {
            sjt_isEmpty5->_refCount++;
        }

        sjt_not5 = (sjt_isEmpty5 == 0);
        result5 = !sjt_not5;
        sjt_ifElse13 = result5;
        if (sjt_ifElse13) {
            sji_fireMouseUp_mouseHandler* sjt_dot63;
            sji_fireMouseUp_mouseHandler* sjt_getValue4;
            sjs_point* sjt_interfaceParam4;

            sjt_getValue4 = sjv_mouseHandler;
            if (sjt_getValue4 != 0) {
                sjt_getValue4->_refCount++;
            }

            sjt_dot63 = sjt_getValue4;
            sjt_interfaceParam4 = point;
            sjt_dot63->onMouseDown((void*)(((char*)sjt_dot63->_parent) + sizeof(intptr_t)), sjt_interfaceParam4);

            if (sjt_getValue4 != 0) {
                sjt_getValue4->_refCount--;
                if (sjt_getValue4->_refCount <= 0) {
                    sji_fireMouseUp_mouseHandler_destroy(sjt_getValue4);
                }
            }
        }

        if (sjt_isEmpty5 != 0) {
            sjt_isEmpty5->_refCount--;
            if (sjt_isEmpty5->_refCount <= 0) {
                sji_fireMouseUp_mouseHandler_destroy(sjt_isEmpty5);
            }
        }
    }

    sjt_dot64 = element;
    sjt_dot64->getChildren((void*)(((char*)sjt_dot64->_parent) + sizeof(intptr_t)), &sjv_children);
    sjt_isEmpty6 = sjv_children;
    sjt_not6 = (sjt_isEmpty6 == 0);
    result6 = !sjt_not6;
    sjt_ifElse14 = result6;
    if (sjt_ifElse14) {
        int32_t i;
        sjs_array_heap_element* sjt_dot65;
        int32_t sjt_forEnd2;
        int32_t sjt_forStart2;
        sjs_array_heap_element* sjt_getValue5;
        sjs_array_heap_element* sjv_c;

        sjt_getValue5 = sjv_children;
        if (sjt_getValue5 == 0) { exit(-1); }
        sjv_c = sjt_getValue5;
        sjt_forStart2 = 0;
        i = sjt_forStart2;
        sjt_dot65 = sjv_c;
        sjt_forEnd2 = (sjt_dot65)->size;
        while (i < sjt_forEnd2) {
            sjs_array_heap_element* sjt_dot66;
            sji_element* sjt_functionParam12;
            int32_t sjt_functionParam13;
            sjs_point* sjt_functionParam14;

            sjt_dot66 = sjv_c;
            sjt_functionParam13 = i;
            sjf_array_heap_element_getAt_heap(sjt_dot66, sjt_functionParam13, &sjt_functionParam12);
            sjt_functionParam14 = point;
            sjf_fireMouseDown(sjt_functionParam12, sjt_functionParam14);
            i++;

            sjt_functionParam12->_refCount--;
            if (sjt_functionParam12->_refCount <= 0) {
                sji_element_destroy(sjt_functionParam12);
            }
        }
    }

    sjt_cast3->_refCount--;
    if (sjt_cast3->_refCount <= 0) {
        sji_element_destroy(sjt_cast3);
    }
    if (sjv_mouseHandler != 0) {
        sjv_mouseHandler->_refCount--;
        if (sjv_mouseHandler->_refCount <= 0) {
            sji_fireMouseUp_mouseHandler_destroy(sjv_mouseHandler);
        }
    }
}

void sjf_fireMouseUp(sji_element* element, sjs_point* point) {
    bool result4;
    sji_element* sjt_cast2;
    sjs_rect* sjt_dot51;
    sji_element* sjt_dot52;
    sji_element* sjt_dot58;
    sjs_point* sjt_functionParam5;
    bool sjt_ifElse10;
    bool sjt_ifElse8;
    sjs_array_heap_element* sjt_isEmpty4;
    bool sjt_not4;
    sjs_array_heap_element* sjv_children;
    sji_fireMouseUp_mouseHandler* sjv_mouseHandler;

    sjt_cast2 = element;
    sjt_cast2->_refCount++;
    sjv_mouseHandler = (sji_fireMouseUp_mouseHandler*)sjt_cast2->asInterface(sjt_cast2->_parent, sji_fireMouseUp_mouseHandler_typeId);
    sjt_dot52 = element;
    sjt_dot52->getRect((void*)(((char*)sjt_dot52->_parent) + sizeof(intptr_t)), &sjt_dot51);
    sjt_functionParam5 = point;
    sjf_rect_containsPoint(sjt_dot51, sjt_functionParam5, &sjt_ifElse8);
    if (sjt_ifElse8) {
        bool result3;
        bool sjt_ifElse9;
        sji_fireMouseUp_mouseHandler* sjt_isEmpty3;
        bool sjt_not3;

        sjt_isEmpty3 = sjv_mouseHandler;
        if (sjt_isEmpty3 != 0) {
            sjt_isEmpty3->_refCount++;
        }

        sjt_not3 = (sjt_isEmpty3 == 0);
        result3 = !sjt_not3;
        sjt_ifElse9 = result3;
        if (sjt_ifElse9) {
            sji_fireMouseUp_mouseHandler* sjt_dot57;
            sji_fireMouseUp_mouseHandler* sjt_getValue2;
            sjs_point* sjt_interfaceParam3;

            sjt_getValue2 = sjv_mouseHandler;
            if (sjt_getValue2 != 0) {
                sjt_getValue2->_refCount++;
            }

            sjt_dot57 = sjt_getValue2;
            sjt_interfaceParam3 = point;
            sjt_dot57->onMouseUp((void*)(((char*)sjt_dot57->_parent) + sizeof(intptr_t)), sjt_interfaceParam3);

            if (sjt_getValue2 != 0) {
                sjt_getValue2->_refCount--;
                if (sjt_getValue2->_refCount <= 0) {
                    sji_fireMouseUp_mouseHandler_destroy(sjt_getValue2);
                }
            }
        }

        if (sjt_isEmpty3 != 0) {
            sjt_isEmpty3->_refCount--;
            if (sjt_isEmpty3->_refCount <= 0) {
                sji_fireMouseUp_mouseHandler_destroy(sjt_isEmpty3);
            }
        }
    }

    sjt_dot58 = element;
    sjt_dot58->getChildren((void*)(((char*)sjt_dot58->_parent) + sizeof(intptr_t)), &sjv_children);
    sjt_isEmpty4 = sjv_children;
    sjt_not4 = (sjt_isEmpty4 == 0);
    result4 = !sjt_not4;
    sjt_ifElse10 = result4;
    if (sjt_ifElse10) {
        int32_t i;
        sjs_array_heap_element* sjt_dot59;
        int32_t sjt_forEnd1;
        int32_t sjt_forStart1;
        sjs_array_heap_element* sjt_getValue3;
        sjs_array_heap_element* sjv_c;

        sjt_getValue3 = sjv_children;
        if (sjt_getValue3 == 0) { exit(-1); }
        sjv_c = sjt_getValue3;
        sjt_forStart1 = 0;
        i = sjt_forStart1;
        sjt_dot59 = sjv_c;
        sjt_forEnd1 = (sjt_dot59)->size;
        while (i < sjt_forEnd1) {
            sjs_array_heap_element* sjt_dot60;
            sji_element* sjt_functionParam6;
            int32_t sjt_functionParam7;
            sjs_point* sjt_functionParam8;

            sjt_dot60 = sjv_c;
            sjt_functionParam7 = i;
            sjf_array_heap_element_getAt_heap(sjt_dot60, sjt_functionParam7, &sjt_functionParam6);
            sjt_functionParam8 = point;
            sjf_fireMouseUp(sjt_functionParam6, sjt_functionParam8);
            i++;

            sjt_functionParam6->_refCount--;
            if (sjt_functionParam6->_refCount <= 0) {
                sji_element_destroy(sjt_functionParam6);
            }
        }
    }

    sjt_cast2->_refCount--;
    if (sjt_cast2->_refCount <= 0) {
        sji_element_destroy(sjt_cast2);
    }
    if (sjv_mouseHandler != 0) {
        sjv_mouseHandler->_refCount--;
        if (sjv_mouseHandler->_refCount <= 0) {
            sji_fireMouseUp_mouseHandler_destroy(sjv_mouseHandler);
        }
    }
}

void sjf_image(sjs_image* _this) {
    bool sjt_and1;
    bool sjt_and2;
    int32_t sjt_compare1;
    int32_t sjt_compare2;
    int32_t sjt_compare3;
    int32_t sjt_compare4;
    sjs_rect* sjt_dot1;
    sjs_rect* sjt_dot2;
    bool sjt_ifElse1;

    sjt_dot1 = &_this->rect;
    sjt_compare1 = (sjt_dot1)->w;
    sjt_compare2 = 0;
    sjt_and1 = sjt_compare1 == sjt_compare2;
    sjt_dot2 = &_this->rect;
    sjt_compare3 = (sjt_dot2)->h;
    sjt_compare4 = 0;
    sjt_and2 = sjt_compare3 == sjt_compare4;
    sjt_ifElse1 = sjt_and1 && sjt_and2;
    if (sjt_ifElse1) {
        sjs_texture* sjt_dot3;
        sjs_size* sjt_dot8;
        sjs_size* sjt_dot9;
        sjs_size sjv_size;

        sjt_dot3 = &_this->texture;
        sjf_texture_getSize(sjt_dot3, &sjv_size);
        _this->rect.x = 0;
        _this->rect.y = 0;
        sjt_dot8 = &sjv_size;
        _this->rect.w = (sjt_dot8)->w;
        sjt_dot9 = &sjv_size;
        _this->rect.h = (sjt_dot9)->h;
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
    _interface->render = (void(*)(void*,sjs_surface2d*))sjf_imageElement_render;
    _interface->getChildren = (void(*)(void*, sjs_array_heap_element**))sjf_imageElement_getChildren;

    return _interface;
}

void sjf_imageElement_copy(sjs_imageElement* _this, sjs_imageElement* _from) {
    sjf_image_copy(&_this->image, &_from->image);
    sjf_rect_copy(&_this->_rect, &_from->_rect);
    sjf_margin_copy(&_this->_margin, &_from->_margin);
    _this->_imageRenderer = 0;
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

void sjf_imageElement_getChildren(sjs_imageElement* _parent, sjs_array_heap_element** _return) {
    (*_return) = 0;
}

void sjf_imageElement_getRect(sjs_imageElement* _parent, sjs_rect** _return) {
    (*_return) = &(_parent)->_rect;
}

void sjf_imageElement_getSize(sjs_imageElement* _parent, sjs_size* maxSize, sjs_size* _return) {
    sjs_size* sjt_dot15;
    sjs_size* sjt_dot16;

    sjt_dot15 = maxSize;
    _return->w = (sjt_dot15)->w;
    sjt_dot16 = maxSize;
    _return->h = (sjt_dot16)->h;
    sjf_size(_return);
}

void sjf_imageElement_getSize_heap(sjs_imageElement* _parent, sjs_size* maxSize, sjs_size_heap** _return) {
    sjs_size* sjt_dot17;
    sjs_size* sjt_dot18;

    (*_return) = (sjs_size_heap*)malloc(sizeof(sjs_size_heap));
    (*_return)->_refCount = 1;
    sjt_dot17 = maxSize;
    (*_return)->w = (sjt_dot17)->w;
    sjt_dot18 = maxSize;
    (*_return)->h = (sjt_dot18)->h;
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
    _interface->render = (void(*)(void*,sjs_surface2d*))sjf_imageElement_render;
    _interface->getChildren = (void(*)(void*, sjs_array_heap_element**))sjf_imageElement_getChildren;

    return _interface;
}

void sjf_imageElement_render(sjs_imageElement* _parent, sjs_surface2d* surface) {
    bool result2;
    bool sjt_ifElse4;
    bool sjt_ifElse5;
    sjs_imageRenderer_heap* sjt_isEmpty1;
    sjs_imageRenderer_heap* sjt_isEmpty2;
    bool sjt_not2;

    sjt_isEmpty1 = (_parent)->_imageRenderer;
    if (sjt_isEmpty1 != 0) {
        sjt_isEmpty1->_refCount++;
    }

    sjt_ifElse4 = (sjt_isEmpty1 == 0);
    if (sjt_ifElse4) {
        sjs_rect* sjt_dot24;
        sjs_margin* sjt_functionParam2;
        sjs_imageRenderer_heap* sjt_value1;

        sjt_value1 = (sjs_imageRenderer_heap*)malloc(sizeof(sjs_imageRenderer_heap));
        sjt_value1->_refCount = 1;
        sjt_dot24 = &(_parent)->_rect;
        sjt_functionParam2 = &(_parent)->_margin;
        sjf_rect_subtractMargin(sjt_dot24, sjt_functionParam2, &sjt_value1->rect);
        sjf_image_copy(&sjt_value1->image, &(_parent)->image);
        sjf_imageRenderer_heap(sjt_value1);
        if (_parent->_imageRenderer != 0) {
            _parent->_imageRenderer->_refCount--;
            if (_parent->_imageRenderer->_refCount <= 0) {
                sjf_imageRenderer_destroy((sjs_imageRenderer*)(((char*)_parent->_imageRenderer) + sizeof(intptr_t)));
            }
        }

        _parent->_imageRenderer = sjt_value1;
        if (_parent->_imageRenderer != 0) {
            _parent->_imageRenderer->_refCount++;
        }

        sjt_value1->_refCount--;
        if (sjt_value1->_refCount <= 0) {
            sjf_imageRenderer_destroy((sjs_imageRenderer*)(((char*)sjt_value1) + sizeof(intptr_t)));
        }
    }

    sjt_isEmpty2 = (_parent)->_imageRenderer;
    if (sjt_isEmpty2 != 0) {
        sjt_isEmpty2->_refCount++;
    }

    sjt_not2 = (sjt_isEmpty2 == 0);
    result2 = !sjt_not2;
    sjt_ifElse5 = result2;
    if (sjt_ifElse5) {
        sjs_imageRenderer* sjt_dot37;
        sjs_surface2d* sjt_functionParam3;
        sjs_imageRenderer_heap* sjt_getValue1;

        sjt_getValue1 = (_parent)->_imageRenderer;
        if (sjt_getValue1 != 0) {
            sjt_getValue1->_refCount++;
        }

        sjt_dot37 = (sjs_imageRenderer*)(((char*)sjt_getValue1) + sizeof(intptr_t));
        sjt_functionParam3 = surface;
        sjf_imageRenderer_render(sjt_dot37, sjt_functionParam3);

        if (sjt_getValue1 != 0) {
            sjt_getValue1->_refCount--;
            if (sjt_getValue1->_refCount <= 0) {
                sjf_imageRenderer_destroy((sjs_imageRenderer*)(((char*)sjt_getValue1) + sizeof(intptr_t)));
            }
        }
    }

    if (sjt_isEmpty1 != 0) {
        sjt_isEmpty1->_refCount--;
        if (sjt_isEmpty1->_refCount <= 0) {
            sjf_imageRenderer_destroy((sjs_imageRenderer*)(((char*)sjt_isEmpty1) + sizeof(intptr_t)));
        }
    }
    if (sjt_isEmpty2 != 0) {
        sjt_isEmpty2->_refCount--;
        if (sjt_isEmpty2->_refCount <= 0) {
            sjf_imageRenderer_destroy((sjs_imageRenderer*)(((char*)sjt_isEmpty2) + sizeof(intptr_t)));
        }
    }
}

void sjf_imageElement_setRect(sjs_imageElement* _parent, sjs_rect* rect_) {
    bool result1;
    sjs_rect* sjt_dot19;
    sjs_rect* sjt_functionParam1;
    bool sjt_ifElse3;
    bool sjt_not1;

    sjt_dot19 = &(_parent)->_rect;
    sjt_functionParam1 = rect_;
    sjf_rect_isEqual(sjt_dot19, sjt_functionParam1, &sjt_not1);
    result1 = !sjt_not1;
    sjt_ifElse3 = result1;
    if (sjt_ifElse3) {
        sjf_rect_copy(&_parent->_rect, rect_);
        if (_parent->_imageRenderer != 0) {
            _parent->_imageRenderer->_refCount--;
            if (_parent->_imageRenderer->_refCount <= 0) {
                sjf_imageRenderer_destroy((sjs_imageRenderer*)(((char*)_parent->_imageRenderer) + sizeof(intptr_t)));
            }
        }

        _parent->_imageRenderer = 0;
        if (_parent->_imageRenderer != 0) {
            _parent->_imageRenderer->_refCount++;
        }
    } else {
    }
}

void sjf_imageRenderer(sjs_imageRenderer* _this) {
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

void sjf_imageRenderer_copy(sjs_imageRenderer* _this, sjs_imageRenderer* _from) {
    sjf_rect_copy(&_this->rect, &_from->rect);
    sjf_image_copy(&_this->image, &_from->image);
    _this->buffer = _from->buffer;
    _retain(_this->buffer);
}

void sjf_imageRenderer_destroy(sjs_imageRenderer* _this) {
    if (_release(_this->buffer)) {
        vertex_buffer_delete(_this->buffer);
    }
}

void sjf_imageRenderer_heap(sjs_imageRenderer_heap* _this) {
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

void sjf_imageRenderer_render(sjs_imageRenderer* _parent, sjs_surface2d* surface) {
    glBindTexture(GL_TEXTURE_2D, _parent->image.texture.id);
    glUseProgram(sjv_imageShader.id);
    glUniform1i(glGetUniformLocation(sjv_imageShader.id, "texture" ), 0 );
    glUniformMatrix4fv(glGetUniformLocation(sjv_imageShader.id, "model" ), 1, 0, surface->model.data);
    glUniformMatrix4fv(glGetUniformLocation(sjv_imageShader.id, "view" ), 1, 0, surface->view.data);
    glUniformMatrix4fv(glGetUniformLocation(sjv_imageShader.id, "projection" ), 1, 0, surface->projection.data);
    vertex_buffer_render(_parent->buffer, GL_TRIANGLES);
}

void sjf_image_copy(sjs_image* _this, sjs_image* _from) {
    sjf_texture_copy(&_this->texture, &_from->texture);
    sjf_rect_copy(&_this->rect, &_from->rect);
    sjf_margin_copy(&_this->margin, &_from->margin);
}

void sjf_image_destroy(sjs_image* _this) {
}

void sjf_image_heap(sjs_image_heap* _this) {
    sjs_rect* dotTemp1;
    sjs_rect* dotTemp2;
    bool sjt_and3;
    bool sjt_and4;
    int32_t sjt_compare5;
    int32_t sjt_compare6;
    int32_t sjt_compare7;
    int32_t sjt_compare8;
    sjs_rect* sjt_dot10;
    sjs_rect* sjt_dot11;
    bool sjt_ifElse2;

    dotTemp1 = &_this->rect;
    sjt_dot10 = dotTemp1;
    sjt_compare5 = (sjt_dot10)->w;
    sjt_compare6 = 0;
    sjt_and3 = sjt_compare5 == sjt_compare6;
    dotTemp2 = &_this->rect;
    sjt_dot11 = dotTemp2;
    sjt_compare7 = (sjt_dot11)->h;
    sjt_compare8 = 0;
    sjt_and4 = sjt_compare7 == sjt_compare8;
    sjt_ifElse2 = sjt_and3 && sjt_and4;
    if (sjt_ifElse2) {
        sjs_texture* dotTemp3;
        sjs_texture* sjt_dot12;
        sjs_size* sjt_dot13;
        sjs_size* sjt_dot14;
        sjs_size sjv_size;

        dotTemp3 = &_this->texture;
        sjt_dot12 = dotTemp3;
        sjf_texture_getSize(sjt_dot12, &sjv_size);
        _this->rect.x = 0;
        _this->rect.y = 0;
        sjt_dot13 = &sjv_size;
        _this->rect.w = (sjt_dot13)->w;
        sjt_dot14 = &sjv_size;
        _this->rect.h = (sjt_dot14)->h;
        sjf_rect(&_this->rect);

        sjf_size_destroy(&sjv_size);
    }
}

void sjf_mainLoop(void) {
    sjs_surface2d* sjt_dot38;
    sjs_surface2d* sjt_dot41;
    sjs_size* sjt_dot46;
    sjs_size* sjt_dot47;
    sji_element* sjt_dot48;
    sji_element* sjt_dot49;
    sjs_surface2d* sjt_dot50;
    bool sjt_ifElse11;
    bool sjt_ifElse7;
    sjs_rect* sjt_interfaceParam1;
    sjs_surface2d* sjt_interfaceParam2;
    int32_t sjt_math29;
    int32_t sjt_math30;
    bool sjv_isMouseDown;
    bool sjv_isMouseUp;
    sjs_rect sjv_rect;
    sjs_size sjv_size;
    int32_t sjv_x;
    int32_t sjv_y;

    sjt_dot38 = &sjv_rootSurface;
    sjf_surface2d_clear(sjt_dot38);
    sjt_dot41 = &sjv_rootSurface;
    sjf_surface2d_getSize(sjt_dot41, &sjv_size);
    sjv_rect.x = 0;
    sjv_rect.y = 0;
    sjt_dot46 = &sjv_size;
    sjv_rect.w = (sjt_dot46)->w;
    sjt_dot47 = &sjv_size;
    sjv_rect.h = (sjt_dot47)->h;
    sjf_rect(&sjv_rect);
    sjt_dot48 = sjv_root;
    sjt_interfaceParam1 = &sjv_rect;
    sjt_dot48->setRect((void*)(((char*)sjt_dot48->_parent) + sizeof(intptr_t)), sjt_interfaceParam1);
    sjt_dot49 = sjv_root;
    sjt_interfaceParam2 = &sjv_rootSurface;
    sjt_dot49->render((void*)(((char*)sjt_dot49->_parent) + sizeof(intptr_t)), sjt_interfaceParam2);
    sjt_dot50 = &sjv_rootSurface;
    sjf_surface2d_present(sjt_dot50);
    sjv_isMouseUp = false;
    sjv_isMouseDown = false;
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
            sjv_isMouseDown = true;
            sjv_x = e.button.x;
            sjv_y = e.button.x;
            break;
            case SDL_MOUSEBUTTONUP:
            printf("SDL_MOUSEBUTTONUP\n");
            sjv_isMouseUp = true;
            sjv_x = e.button.x;
            sjv_y = e.button.x;
            break;
        }
    }
    sjt_ifElse7 = sjv_isMouseUp;
    if (sjt_ifElse7) {
        sjs_point sjt_call2;
        sjs_point* sjt_functionParam10;
        sji_element* sjt_functionParam9;

        sjt_functionParam9 = sjv_root;
        sjt_functionParam9->_refCount++;
        sjt_call2.x = sjv_x;
        sjt_call2.y = sjv_y;
        sjf_point(&sjt_call2);
        sjt_functionParam10 = &sjt_call2;
        sjf_fireMouseUp(sjt_functionParam9, sjt_functionParam10);

        sjt_functionParam9->_refCount--;
        if (sjt_functionParam9->_refCount <= 0) {
            sji_element_destroy(sjt_functionParam9);
        }
        sjf_point_destroy(&sjt_call2);
    }

    sjt_ifElse11 = sjv_isMouseDown;
    if (sjt_ifElse11) {
        sjs_point sjt_call3;
        sji_element* sjt_functionParam15;
        sjs_point* sjt_functionParam16;

        sjt_functionParam15 = sjv_root;
        sjt_functionParam15->_refCount++;
        sjt_call3.x = sjv_x;
        sjt_call3.y = sjv_y;
        sjf_point(&sjt_call3);
        sjt_functionParam16 = &sjt_call3;
        sjf_fireMouseDown(sjt_functionParam15, sjt_functionParam16);

        sjt_functionParam15->_refCount--;
        if (sjt_functionParam15->_refCount <= 0) {
            sji_element_destroy(sjt_functionParam15);
        }
        sjf_point_destroy(&sjt_call3);
    }

    sjt_math29 = sjv_frame;
    sjt_math30 = 1;
    sjv_frame = sjt_math29 + sjt_math30;

    sjf_rect_destroy(&sjv_rect);
    sjf_size_destroy(&sjv_size);
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

void sjf_margin_heap(sjs_margin_heap* _this) {
}

void sjf_point(sjs_point* _this) {
}

void sjf_point_copy(sjs_point* _this, sjs_point* _from) {
    _this->x = _from->x;
    _this->y = _from->y;
}

void sjf_point_destroy(sjs_point* _this) {
}

void sjf_point_heap(sjs_point_heap* _this) {
}

void sjf_rect(sjs_rect* _this) {
}

void sjf_rect_containsPoint(sjs_rect* _parent, sjs_point* point, bool* _return) {
    bool sjt_and11;
    bool sjt_and12;
    bool sjt_and13;
    bool sjt_and14;
    bool sjt_and15;
    bool sjt_and16;
    int32_t sjt_compare21;
    int32_t sjt_compare22;
    int32_t sjt_compare23;
    int32_t sjt_compare24;
    int32_t sjt_compare25;
    int32_t sjt_compare26;
    int32_t sjt_compare27;
    int32_t sjt_compare28;
    sjs_point* sjt_dot53;
    sjs_point* sjt_dot54;
    sjs_point* sjt_dot55;
    sjs_point* sjt_dot56;
    int32_t sjt_math25;
    int32_t sjt_math26;
    int32_t sjt_math27;
    int32_t sjt_math28;

    sjt_compare21 = (_parent)->x;
    sjt_dot53 = point;
    sjt_compare22 = (sjt_dot53)->x;
    sjt_and11 = sjt_compare21 <= sjt_compare22;
    sjt_compare23 = (_parent)->y;
    sjt_dot54 = point;
    sjt_compare24 = (sjt_dot54)->x;
    sjt_and13 = sjt_compare23 <= sjt_compare24;
    sjt_dot55 = point;
    sjt_compare25 = (sjt_dot55)->x;
    sjt_math25 = (_parent)->x;
    sjt_math26 = (_parent)->w;
    sjt_compare26 = sjt_math25 + sjt_math26;
    sjt_and15 = sjt_compare25 < sjt_compare26;
    sjt_dot56 = point;
    sjt_compare27 = (sjt_dot56)->y;
    sjt_math27 = (_parent)->y;
    sjt_math28 = (_parent)->h;
    sjt_compare28 = sjt_math27 + sjt_math28;
    sjt_and16 = sjt_compare27 < sjt_compare28;
    sjt_and14 = sjt_and15 && sjt_and16;
    sjt_and12 = sjt_and13 && sjt_and14;
    (*_return) = sjt_and11 && sjt_and12;
}

void sjf_rect_copy(sjs_rect* _this, sjs_rect* _from) {
    _this->x = _from->x;
    _this->y = _from->y;
    _this->w = _from->w;
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
    int32_t sjt_compare10;
    int32_t sjt_compare11;
    int32_t sjt_compare12;
    int32_t sjt_compare13;
    int32_t sjt_compare14;
    int32_t sjt_compare15;
    int32_t sjt_compare16;
    int32_t sjt_compare9;
    sjs_rect* sjt_dot20;
    sjs_rect* sjt_dot21;
    sjs_rect* sjt_dot22;
    sjs_rect* sjt_dot23;

    sjt_compare9 = (_parent)->x;
    sjt_dot20 = rect;
    sjt_compare10 = (sjt_dot20)->x;
    sjt_and5 = sjt_compare9 == sjt_compare10;
    sjt_compare11 = (_parent)->y;
    sjt_dot21 = rect;
    sjt_compare12 = (sjt_dot21)->y;
    sjt_and7 = sjt_compare11 == sjt_compare12;
    sjt_compare13 = (_parent)->w;
    sjt_dot22 = rect;
    sjt_compare14 = (sjt_dot22)->w;
    sjt_and9 = sjt_compare13 == sjt_compare14;
    sjt_compare15 = (_parent)->h;
    sjt_dot23 = rect;
    sjt_compare16 = (sjt_dot23)->h;
    sjt_and10 = sjt_compare15 == sjt_compare16;
    sjt_and8 = sjt_and9 && sjt_and10;
    sjt_and6 = sjt_and7 && sjt_and8;
    (*_return) = sjt_and5 && sjt_and6;
}

void sjf_rect_subtractMargin(sjs_rect* _parent, sjs_margin* margin, sjs_rect* _return) {
    sjs_margin* sjt_dot25;
    sjs_margin* sjt_dot26;
    sjs_margin* sjt_dot27;
    sjs_margin* sjt_dot28;
    sjs_margin* sjt_dot29;
    sjs_margin* sjt_dot30;
    int32_t sjt_math1;
    int32_t sjt_math10;
    int32_t sjt_math11;
    int32_t sjt_math12;
    int32_t sjt_math2;
    int32_t sjt_math3;
    int32_t sjt_math4;
    int32_t sjt_math5;
    int32_t sjt_math6;
    int32_t sjt_math7;
    int32_t sjt_math8;
    int32_t sjt_math9;

    sjt_math1 = (_parent)->x;
    sjt_dot25 = margin;
    sjt_math2 = (sjt_dot25)->l;
    _return->x = sjt_math1 + sjt_math2;
    sjt_math3 = (_parent)->y;
    sjt_dot26 = margin;
    sjt_math4 = (sjt_dot26)->t;
    _return->y = sjt_math3 + sjt_math4;
    sjt_math7 = (_parent)->w;
    sjt_dot27 = margin;
    sjt_math8 = (sjt_dot27)->l;
    sjt_math5 = sjt_math7 - sjt_math8;
    sjt_dot28 = margin;
    sjt_math6 = (sjt_dot28)->r;
    _return->w = sjt_math5 - sjt_math6;
    sjt_math11 = (_parent)->h;
    sjt_dot29 = margin;
    sjt_math12 = (sjt_dot29)->t;
    sjt_math9 = sjt_math11 - sjt_math12;
    sjt_dot30 = margin;
    sjt_math10 = (sjt_dot30)->b;
    _return->h = sjt_math9 - sjt_math10;
    sjf_rect(_return);
}

void sjf_rect_subtractMargin_heap(sjs_rect* _parent, sjs_margin* margin, sjs_rect_heap** _return) {
    sjs_margin* sjt_dot31;
    sjs_margin* sjt_dot32;
    sjs_margin* sjt_dot33;
    sjs_margin* sjt_dot34;
    sjs_margin* sjt_dot35;
    sjs_margin* sjt_dot36;
    int32_t sjt_math13;
    int32_t sjt_math14;
    int32_t sjt_math15;
    int32_t sjt_math16;
    int32_t sjt_math17;
    int32_t sjt_math18;
    int32_t sjt_math19;
    int32_t sjt_math20;
    int32_t sjt_math21;
    int32_t sjt_math22;
    int32_t sjt_math23;
    int32_t sjt_math24;

    (*_return) = (sjs_rect_heap*)malloc(sizeof(sjs_rect_heap));
    (*_return)->_refCount = 1;
    sjt_math13 = (_parent)->x;
    sjt_dot31 = margin;
    sjt_math14 = (sjt_dot31)->l;
    (*_return)->x = sjt_math13 + sjt_math14;
    sjt_math15 = (_parent)->y;
    sjt_dot32 = margin;
    sjt_math16 = (sjt_dot32)->t;
    (*_return)->y = sjt_math15 + sjt_math16;
    sjt_math19 = (_parent)->w;
    sjt_dot33 = margin;
    sjt_math20 = (sjt_dot33)->l;
    sjt_math17 = sjt_math19 - sjt_math20;
    sjt_dot34 = margin;
    sjt_math18 = (sjt_dot34)->r;
    (*_return)->w = sjt_math17 - sjt_math18;
    sjt_math23 = (_parent)->h;
    sjt_dot35 = margin;
    sjt_math24 = (sjt_dot35)->t;
    sjt_math21 = sjt_math23 - sjt_math24;
    sjt_dot36 = margin;
    sjt_math22 = (sjt_dot36)->b;
    (*_return)->h = sjt_math21 - sjt_math22;
    sjf_rect_heap((*_return));
}

void sjf_runLoop(void) {
    #ifdef EMSCRIPTEN
    emscripten_set_main_loop((em_callback_func)sjf_mainLoop, 0, 0);
    exit(0);
    #else
    bool quit = false;
    while (!quit) {
        sjf_mainLoop();
    }
    #endif
}

void sjf_shader(sjs_shader* _this) {
    _this->id = shader_load((char*)_this->vertex.data.data, (char*)_this->pixel.data.data);
}

void sjf_shader_copy(sjs_shader* _this, sjs_shader* _from) {
    sjf_string_copy(&_this->vertex, &_from->vertex);
    sjf_string_copy(&_this->pixel, &_from->pixel);
    _this->id = _from->id;
    _retainGLid(_this->id);
}

void sjf_shader_destroy(sjs_shader* _this) {
    if (_releaseGLid(_this->id)) {
        glDeleteShader(_this->id);
    }
}

void sjf_shader_heap(sjs_shader_heap* _this) {
    _this->id = shader_load((char*)_this->vertex.data.data, (char*)_this->pixel.data.data);
}

void sjf_size(sjs_size* _this) {
}

void sjf_size_copy(sjs_size* _this, sjs_size* _from) {
    _this->w = _from->w;
    _this->h = _from->h;
}

void sjf_size_destroy(sjs_size* _this) {
}

void sjf_size_heap(sjs_size_heap* _this) {
}

void sjf_string(sjs_string* _this) {
}

void sjf_string_copy(sjs_string* _this, sjs_string* _from) {
    _this->count = _from->count;
    sjf_array_char_copy(&_this->data, &_from->data);
}

void sjf_string_destroy(sjs_string* _this) {
}

void sjf_string_heap(sjs_string_heap* _this) {
}

void sjf_surface2d(sjs_surface2d* _this) {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        printf("SDL_Init Error: %s\n", SDL_GetError());
        exit(-1);
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
        printf("SDL_CreateWindow Error: %s\n", SDL_GetError());
        exit(-1);
    }
    SDL_GL_CreateContext((SDL_Window*)_this->win);
    #ifdef WIN32
    GLint GlewInitResult = glewInit();
    if (GLEW_OK != GlewInitResult)
    {
        printf("ERROR: %s\n", glewGetErrorString(GlewInitResult));
        exit(EXIT_FAILURE);
    }
    #endif
    _this->ren = SDL_CreateRenderer((SDL_Window*)_this->win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (_this->ren == 0) {
        printf("SDL_CreateRenderer Error: %s\n", SDL_GetError());
        exit(-1);
    }
    glClearColor( 0.0, 0.0, 0.0, 0.0 );
    glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );
    glEnable( GL_BLEND );
}

void sjf_surface2d_clear(sjs_surface2d* _parent) {
    int32_t sjt_compare17;
    int32_t sjt_compare18;
    int32_t sjt_compare19;
    int32_t sjt_compare20;
    sjs_size* sjt_dot39;
    sjs_size* sjt_dot40;
    bool sjt_ifElse6;
    bool sjt_or1;
    bool sjt_or2;
    int32_t sjv_h;
    int32_t sjv_w;

    sjv_w = 0;
    sjv_h = 0;
    SDL_GetRendererOutputSize(_parent->ren, &sjv_w, &sjv_h);
    sjt_compare17 = sjv_w;
    sjt_dot39 = &(_parent)->_size;
    sjt_compare18 = (sjt_dot39)->w;
    sjt_or1 = sjt_compare17 != sjt_compare18;
    sjt_compare19 = sjv_h;
    sjt_dot40 = &(_parent)->_size;
    sjt_compare20 = (sjt_dot40)->h;
    sjt_or2 = sjt_compare19 != sjt_compare20;
    sjt_ifElse6 = sjt_or1 || sjt_or2;
    if (sjt_ifElse6) {
        _parent->_size.w = sjv_w;
        _parent->_size.h = sjv_h;
        sjf_size(&_parent->_size);
        glViewport(0, 0, _parent->_size.w, _parent->_size.h);
        mat4_set_orthographic( &_parent->projection, 0.0f, (float)_parent->_size.w, (float)-_parent->_size.h, 0.0f, -1.0f, 1.0f);
        mat4_set_identity( &_parent->model );
        mat4_scale(&_parent->model, 1.0f, -1.0f, 1.0f);
        mat4_set_identity( &_parent->view );
    }

    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
    glEnable( GL_TEXTURE_2D );
    glDisable( GL_DEPTH_TEST );
}

void sjf_surface2d_copy(sjs_surface2d* _this, sjs_surface2d* _from) {
    sjf_size_copy(&_this->_size, &_from->_size);
    _this->ren = _from->ren;
    _retain(_this->ren);
    _this->win = _from->win;
    _retain(_this->win);
}

void sjf_surface2d_destroy(sjs_surface2d* _this) {
    if (_release(_this->ren)) {
        SDL_DestroyRenderer(_this->ren);
    }
    if (_release(_this->win)) {
        SDL_DestroyWindow(_this->win);
    }
}

void sjf_surface2d_getSize(sjs_surface2d* _parent, sjs_size* _return) {
    sjs_size* sjt_dot42;
    sjs_size* sjt_dot43;

    sjt_dot42 = &(_parent)->_size;
    _return->w = (sjt_dot42)->w;
    sjt_dot43 = &(_parent)->_size;
    _return->h = (sjt_dot43)->h;
    sjf_size(_return);
}

void sjf_surface2d_getSize_heap(sjs_surface2d* _parent, sjs_size_heap** _return) {
    sjs_size* sjt_dot44;
    sjs_size* sjt_dot45;

    (*_return) = (sjs_size_heap*)malloc(sizeof(sjs_size_heap));
    (*_return)->_refCount = 1;
    sjt_dot44 = &(_parent)->_size;
    (*_return)->w = (sjt_dot44)->w;
    sjt_dot45 = &(_parent)->_size;
    (*_return)->h = (sjt_dot45)->h;
    sjf_size_heap((*_return));
}

void sjf_surface2d_heap(sjs_surface2d_heap* _this) {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        printf("SDL_Init Error: %s\n", SDL_GetError());
        exit(-1);
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
        printf("SDL_CreateWindow Error: %s\n", SDL_GetError());
        exit(-1);
    }
    SDL_GL_CreateContext((SDL_Window*)_this->win);
    #ifdef WIN32
    GLint GlewInitResult = glewInit();
    if (GLEW_OK != GlewInitResult)
    {
        printf("ERROR: %s\n", glewGetErrorString(GlewInitResult));
        exit(EXIT_FAILURE);
    }
    #endif
    _this->ren = SDL_CreateRenderer((SDL_Window*)_this->win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (_this->ren == 0) {
        printf("SDL_CreateRenderer Error: %s\n", SDL_GetError());
        exit(-1);
    }
    glClearColor( 0.0, 0.0, 0.0, 0.0 );
    glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );
    glEnable( GL_BLEND );
}

void sjf_surface2d_present(sjs_surface2d* _parent) {
    SDL_GL_SwapWindow((SDL_Window*)_parent->win);
}

void sjf_texture(sjs_texture* _this) {
}

void sjf_textureFromPng(sjs_string* fileName, sjs_texture* _return) {
    int32_t sjv_h;
    uint32_t sjv_id;
    int32_t sjv_w;

    sjv_id = (uint32_t)0u;
    sjv_w = 0;
    sjv_h = 0;
    sjv_id = png_texture_load((char*)fileName->data.data, &sjv_w, &sjv_h);
    _return->size.w = sjv_w;
    _return->size.h = sjv_h;
    sjf_size(&_return->size);
    _return->id = sjv_id;
    sjf_texture(_return);
}

void sjf_textureFromPng_heap(sjs_string* fileName, sjs_texture_heap** _return) {
    int32_t sjv_h;
    uint32_t sjv_id;
    int32_t sjv_w;

    sjv_id = (uint32_t)0u;
    sjv_w = 0;
    sjv_h = 0;
    sjv_id = png_texture_load((char*)fileName->data.data, &sjv_w, &sjv_h);
    (*_return) = (sjs_texture_heap*)malloc(sizeof(sjs_texture_heap));
    (*_return)->_refCount = 1;
    (*_return)->size.w = sjv_w;
    (*_return)->size.h = sjv_h;
    sjf_size(&(*_return)->size);
    (*_return)->id = sjv_id;
    sjf_texture_heap((*_return));
}

void sjf_texture_copy(sjs_texture* _this, sjs_texture* _from) {
    sjf_size_copy(&_this->size, &_from->size);
    _this->id = _from->id;
    _retainGLid(_this->id);
}

void sjf_texture_destroy(sjs_texture* _this) {
    if (_releaseGLid(_this->id)) {
        glDeleteTextures(1, &_this->id);
    }
}

void sjf_texture_getSize(sjs_texture* _parent, sjs_size* _return) {
    sjs_size* sjt_dot4;
    sjs_size* sjt_dot5;

    sjt_dot4 = &(_parent)->size;
    _return->w = (sjt_dot4)->w;
    sjt_dot5 = &(_parent)->size;
    _return->h = (sjt_dot5)->h;
    sjf_size(_return);
}

void sjf_texture_getSize_heap(sjs_texture* _parent, sjs_size_heap** _return) {
    sjs_size* sjt_dot6;
    sjs_size* sjt_dot7;

    (*_return) = (sjs_size_heap*)malloc(sizeof(sjs_size_heap));
    (*_return)->_refCount = 1;
    sjt_dot6 = &(_parent)->size;
    (*_return)->w = (sjt_dot6)->w;
    sjt_dot7 = &(_parent)->size;
    (*_return)->h = (sjt_dot7)->h;
    sjf_size_heap((*_return));
}

void sjf_texture_heap(sjs_texture_heap* _this) {
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
}

void sji_element_destroy(sji_element* _this) {
    _this->_parent->_refCount--;
    if (_this->_parent->_refCount <= 0) {
        _this->destroy((void*)(((char*)_this->_parent) + sizeof(intptr_t)));
        free(_this->_parent);
    }
}

void sji_fireMouseUp_mouseHandler_copy(sji_fireMouseUp_mouseHandler* _this, sji_fireMouseUp_mouseHandler* _from) {
    _this->_refCount = 1;
    _this->_parent = _from->_parent;
    _this->_parent->_refCount++;
    _this->destroy = _from->destroy;
    _this->asInterface = _from->asInterface;
    _this->onMouseUp = _from->onMouseUp;
    _this->onMouseDown = _from->onMouseDown;
    _this->onMouseMove = _from->onMouseMove;
}

void sji_fireMouseUp_mouseHandler_destroy(sji_fireMouseUp_mouseHandler* _this) {
    _this->_parent->_refCount--;
    if (_this->_parent->_refCount <= 0) {
        _this->destroy((void*)(((char*)_this->_parent) + sizeof(intptr_t)));
        free(_this->_parent);
    }
}

int main(int argc, char** argv) {
    sjv_i32_max = (-2147483647 - 1);
    sjv_i32_min = 2147483647;
    sjv_u32_max = (uint32_t)4294967295u;
    sjv_frame = 0;
    sjf_anon1(&sjv_console);
    sjf_anon2(&sjv_parse);
    sjf_anon3(&sjv_random);
    sjf_anon4(&sjv_convert);
    sjv_rootSurface._size.w = 0;
    sjv_rootSurface._size.h = 0;
    sjf_size(&sjv_rootSurface._size);
    sjf_surface2d(&sjv_rootSurface);
    sjv_buttonState.normal = 0;
    sjv_buttonState.hot = 1;
    sjv_buttonState.pressed = 2;
    sjf_anon5(&sjv_buttonState);
    sjf_anon6(&sjv_colors);
    sjf_anon7(&sjv_style);
    sjv_borderPosition.fill = 0;
    sjv_borderPosition.left = 1;
    sjv_borderPosition.right = 2;
    sjv_borderPosition.top = 3;
    sjv_borderPosition.bottom = 4;
    sjf_anon8(&sjv_borderPosition);
    sjv_textShader.vertex.count = 24;
    sjv_textShader.vertex.data.size = 25;
    sjv_textShader.vertex.data.data = (uintptr_t)sjg_string1;
    sjv_textShader.vertex.data._isGlobal = false;
    sjf_array_char(&sjv_textShader.vertex.data);
    sjf_string(&sjv_textShader.vertex);
    sjv_textShader.pixel.count = 24;
    sjv_textShader.pixel.data.size = 25;
    sjv_textShader.pixel.data.data = (uintptr_t)sjg_string2;
    sjv_textShader.pixel.data._isGlobal = false;
    sjf_array_char(&sjv_textShader.pixel.data);
    sjf_string(&sjv_textShader.pixel);
    sjf_shader(&sjv_textShader);
    sjv_boxShader.vertex.count = 20;
    sjv_boxShader.vertex.data.size = 21;
    sjv_boxShader.vertex.data.data = (uintptr_t)sjg_string3;
    sjv_boxShader.vertex.data._isGlobal = false;
    sjf_array_char(&sjv_boxShader.vertex.data);
    sjf_string(&sjv_boxShader.vertex);
    sjv_boxShader.pixel.count = 20;
    sjv_boxShader.pixel.data.size = 21;
    sjv_boxShader.pixel.data.data = (uintptr_t)sjg_string4;
    sjv_boxShader.pixel.data._isGlobal = false;
    sjf_array_char(&sjv_boxShader.pixel.data);
    sjf_string(&sjv_boxShader.pixel);
    sjf_shader(&sjv_boxShader);
    sjv_imageShader.vertex.count = 20;
    sjv_imageShader.vertex.data.size = 21;
    sjv_imageShader.vertex.data.data = (uintptr_t)sjg_string5;
    sjv_imageShader.vertex.data._isGlobal = false;
    sjf_array_char(&sjv_imageShader.vertex.data);
    sjf_string(&sjv_imageShader.vertex);
    sjv_imageShader.pixel.count = 20;
    sjv_imageShader.pixel.data.size = 21;
    sjv_imageShader.pixel.data.data = (uintptr_t)sjg_string6;
    sjv_imageShader.pixel.data._isGlobal = false;
    sjf_array_char(&sjv_imageShader.pixel.data);
    sjf_string(&sjv_imageShader.pixel);
    sjf_shader(&sjv_imageShader);
    sjt_cast1 = (sjs_imageElement_heap*)malloc(sizeof(sjs_imageElement_heap));
    sjt_cast1->_refCount = 1;
    sjt_call1.count = 15;
    sjt_call1.data.size = 16;
    sjt_call1.data.data = (uintptr_t)sjg_string7;
    sjt_call1.data._isGlobal = false;
    sjf_array_char(&sjt_call1.data);
    sjf_string(&sjt_call1);
    sjt_functionParam4 = &sjt_call1;
    sjf_textureFromPng(sjt_functionParam4, &sjt_cast1->image.texture);
    sjt_cast1->image.rect.x = 0;
    sjt_cast1->image.rect.y = 0;
    sjt_cast1->image.rect.w = 0;
    sjt_cast1->image.rect.h = 0;
    sjf_rect(&sjt_cast1->image.rect);
    sjt_cast1->image.margin.l = 150;
    sjt_cast1->image.margin.t = 50;
    sjt_cast1->image.margin.r = 150;
    sjt_cast1->image.margin.b = 150;
    sjf_margin(&sjt_cast1->image.margin);
    sjf_image(&sjt_cast1->image);
    sjt_cast1->_rect.x = 0;
    sjt_cast1->_rect.y = 0;
    sjt_cast1->_rect.w = 0;
    sjt_cast1->_rect.h = 0;
    sjf_rect(&sjt_cast1->_rect);
    sjt_cast1->_margin.l = 10;
    sjt_cast1->_margin.t = 10;
    sjt_cast1->_margin.r = 10;
    sjt_cast1->_margin.b = 10;
    sjf_margin(&sjt_cast1->_margin);
    sjt_cast1->_imageRenderer = 0;
    if (sjt_cast1->_imageRenderer != 0) {
        sjt_cast1->_imageRenderer->_refCount++;
    }

    sjf_imageElement_heap(sjt_cast1);
    sjv_root = (sji_element*)sjf_imageElement_heap_as_sji_element(sjt_cast1);
    sjf_runLoop();
    main_destroy();
    return 0;
}

void main_destroy() {

    sjt_cast1->_refCount--;
    if (sjt_cast1->_refCount <= 0) {
        sjf_imageElement_destroy((sjs_imageElement*)(((char*)sjt_cast1) + sizeof(intptr_t)));
    }
    sjv_root->_refCount--;
    if (sjv_root->_refCount <= 0) {
        sji_element_destroy(sjv_root);
    }
    sjf_string_destroy(&sjt_call1);
    sjf_anon8_destroy(&sjv_borderPosition);
    sjf_shader_destroy(&sjv_boxShader);
    sjf_anon5_destroy(&sjv_buttonState);
    sjf_anon6_destroy(&sjv_colors);
    sjf_anon1_destroy(&sjv_console);
    sjf_anon4_destroy(&sjv_convert);
    sjf_shader_destroy(&sjv_imageShader);
    sjf_anon2_destroy(&sjv_parse);
    sjf_anon3_destroy(&sjv_random);
    sjf_surface2d_destroy(&sjv_rootSurface);
    sjf_anon7_destroy(&sjv_style);
    sjf_shader_destroy(&sjv_textShader);
}
