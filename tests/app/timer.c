
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
#define sjs_anon5_typeId 18
#define sjs_anon5_heap_typeId 19
#define sjs_anon6_typeId 20
#define sjs_anon6_heap_typeId 21
#define sjs_anon7_typeId 22
#define sjs_anon7_heap_typeId 23
#define sjs_array_char_typeId 24
#define sjs_array_char_heap_typeId 25
#define sjs_string_typeId 26
#define sjs_string_heap_typeId 27
#define sjs_shader_typeId 28
#define sjs_shader_heap_typeId 29
#define sjs_anon8_typeId 30
#define sjs_anon8_heap_typeId 31
#define sjs_array_heap_element_typeId 32
#define sjs_array_heap_element_heap_typeId 33
#define sjs_rect_typeId 34
#define sjs_rect_heap_typeId 35
#define sjs_fillElement_typeId 36
#define sjs_point_typeId 37
#define sjs_point_heap_typeId 38
#define sji_element_typeId 39
#define sjs_fillElement_heap_typeId 40
#define sjs_array_heap_model_typeId 41
#define sjs_array_heap_model_heap_typeId 42
#define sjs_vec3_typeId 43
#define sjs_vec3_heap_typeId 44
#define sjs_color_typeId 45
#define sjs_color_heap_typeId 46
#define sjs_array_i32_typeId 47
#define sjs_array_i32_heap_typeId 48
#define sjs_array_vertex_location_texture_normal_typeId 49
#define sjs_array_vertex_location_texture_normal_heap_typeId 50
#define sjs_vertexBuffer_vertex_location_texture_normal_typeId 51
#define sjs_vertexBuffer_vertex_location_texture_normal_heap_typeId 52
#define sjs_scene3dElement_typeId 53
#define sjs_scene3dElement_heap_typeId 54
#define sji_scene3dElement_model_typeId 55
#define sjs_frameBuffer_typeId 56
#define sjs_frameBuffer_heap_typeId 57
#define sjs_scene2dModel_typeId 58
#define sjs_scene2dModel_heap_typeId 59
#define sjs_vec2_typeId 60
#define sjs_vec2_heap_typeId 61
#define sjs_vertex_location_texture_normal_typeId 62
#define sjs_vertex_location_texture_normal_heap_typeId 63
#define sjs_texture_typeId 64
#define sjs_texture_heap_typeId 65
#define sjs_margin_typeId 66
#define sjs_margin_heap_typeId 67
#define sjs_image_typeId 68
#define sjs_image_heap_typeId 69
#define sjs_imageRenderer_typeId 70
#define sjs_imageRenderer_heap_typeId 71
#define sjs_imageElement_typeId 72
#define sjs_imageElement_heap_typeId 73
#define sjs_boxRenderer_typeId 74
#define sjs_boxRenderer_heap_typeId 75
#define sjs_crossHairsElement_typeId 76
#define sjs_crossHairsElement_heap_typeId 77

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
typedef struct td_sjs_anon5 sjs_anon5;
typedef struct td_sjs_anon5_heap sjs_anon5_heap;
typedef struct td_sjs_anon6 sjs_anon6;
typedef struct td_sjs_anon6_heap sjs_anon6_heap;
typedef struct td_sjs_anon7 sjs_anon7;
typedef struct td_sjs_anon7_heap sjs_anon7_heap;
typedef struct td_sjs_array_char sjs_array_char;
typedef struct td_sjs_array_char_heap sjs_array_char_heap;
typedef struct td_sjs_string sjs_string;
typedef struct td_sjs_string_heap sjs_string_heap;
typedef struct td_sjs_shader sjs_shader;
typedef struct td_sjs_shader_heap sjs_shader_heap;
typedef struct td_sjs_anon8 sjs_anon8;
typedef struct td_sjs_anon8_heap sjs_anon8_heap;
typedef struct td_sjs_array_heap_element sjs_array_heap_element;
typedef struct td_sjs_array_heap_element_heap sjs_array_heap_element_heap;
typedef struct td_sjs_rect sjs_rect;
typedef struct td_sjs_rect_heap sjs_rect_heap;
typedef struct td_sjs_fillElement sjs_fillElement;
typedef struct td_sjs_point sjs_point;
typedef struct td_sjs_point_heap sjs_point_heap;
typedef struct td_sji_element sji_element;
typedef struct td_sjs_fillElement_heap sjs_fillElement_heap;
typedef struct td_sjs_array_heap_model sjs_array_heap_model;
typedef struct td_sjs_array_heap_model_heap sjs_array_heap_model_heap;
typedef struct td_sjs_vec3 sjs_vec3;
typedef struct td_sjs_vec3_heap sjs_vec3_heap;
typedef struct td_sjs_color sjs_color;
typedef struct td_sjs_color_heap sjs_color_heap;
typedef struct td_sjs_array_i32 sjs_array_i32;
typedef struct td_sjs_array_i32_heap sjs_array_i32_heap;
typedef struct td_sjs_array_vertex_location_texture_normal sjs_array_vertex_location_texture_normal;
typedef struct td_sjs_array_vertex_location_texture_normal_heap sjs_array_vertex_location_texture_normal_heap;
typedef struct td_sjs_vertexBuffer_vertex_location_texture_normal sjs_vertexBuffer_vertex_location_texture_normal;
typedef struct td_sjs_vertexBuffer_vertex_location_texture_normal_heap sjs_vertexBuffer_vertex_location_texture_normal_heap;
typedef struct td_sjs_scene3dElement sjs_scene3dElement;
typedef struct td_sjs_scene3dElement_heap sjs_scene3dElement_heap;
typedef struct td_sji_scene3dElement_model sji_scene3dElement_model;
typedef struct td_sjs_frameBuffer sjs_frameBuffer;
typedef struct td_sjs_frameBuffer_heap sjs_frameBuffer_heap;
typedef struct td_sjs_scene2dModel sjs_scene2dModel;
typedef struct td_sjs_scene2dModel_heap sjs_scene2dModel_heap;
typedef struct td_sjs_vec2 sjs_vec2;
typedef struct td_sjs_vec2_heap sjs_vec2_heap;
typedef struct td_sjs_vertex_location_texture_normal sjs_vertex_location_texture_normal;
typedef struct td_sjs_vertex_location_texture_normal_heap sjs_vertex_location_texture_normal_heap;
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

struct td_sjs_anon5 {
    int32_t fill;
    int32_t left;
    int32_t right;
    int32_t top;
    int32_t bottom;
};

struct td_sjs_anon5_heap {
    intptr_t _refCount;
    int32_t fill;
    int32_t left;
    int32_t right;
    int32_t top;
    int32_t bottom;
};

struct td_sjs_anon6 {
    int32_t normal;
    int32_t hot;
    int32_t pressed;
};

struct td_sjs_anon6_heap {
    intptr_t _refCount;
    int32_t normal;
    int32_t hot;
    int32_t pressed;
};

struct td_sjs_anon7 {
    int structsNeedAValue;
};

struct td_sjs_anon7_heap {
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

struct td_sjs_anon8 {
    int structsNeedAValue;
};

struct td_sjs_anon8_heap {
    intptr_t _refCount;
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

struct td_sjs_fillElement {
    sjs_array_heap_element children;
    sjs_rect _rect;
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

struct td_sjs_fillElement_heap {
    intptr_t _refCount;
    sjs_array_heap_element children;
    sjs_rect _rect;
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
    sjs_vec3 camera;
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
    sjs_vertexBuffer_vertex_location_texture_normal _cube;
};

struct td_sjs_scene3dElement_heap {
    intptr_t _refCount;
    sjs_array_heap_model children;
    sjs_vec3 camera;
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
    sjs_vertexBuffer_vertex_location_texture_normal _cube;
};

struct td_sji_scene3dElement_model {
    intptr_t _refCount;
    sjs_object* _parent;
    void (*destroy)(void* _this);
    sjs_object* (*asInterface)(sjs_object* _this, int typeId);
    void (*render)(void* _parent, sjs_scene3dElement* scene3d, sjs_mat4* model);
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
};

struct td_sjs_scene2dModel_heap {
    intptr_t _refCount;
    sjs_vertexBuffer_vertex_location_texture_normal vertexBuffer;
    sjs_shader shader;
    sjs_frameBuffer frameBuffer;
    sjs_array_heap_element children;
    sjs_scene2d _innerScene;
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

sjs_string sjt_call12;
sjs_fillElement_heap* sjt_cast1;
int32_t sjt_cast14;
sjs_imageElement_heap* sjt_cast15;
sjs_crossHairsElement_heap* sjt_cast16;
int32_t sjt_cast2;
sjs_crossHairsElement_heap* sjt_cast21;
sjs_scene3dElement_heap* sjt_cast3;
int32_t sjt_cast6;
sjs_scene2dModel_heap* sjt_cast7;
sjs_anon7* sjt_dot295;
sjs_anon7* sjt_dot296;
float sjt_functionParam100;
float sjt_functionParam101;
float sjt_functionParam102;
float sjt_functionParam103;
float sjt_functionParam104;
float sjt_functionParam105;
float sjt_functionParam106;
float sjt_functionParam107;
float sjt_functionParam108;
int32_t sjt_functionParam109;
sji_element* sjt_functionParam110;
sjs_string* sjt_functionParam114;
int32_t sjt_functionParam115;
sji_element* sjt_functionParam116;
float sjt_functionParam361;
float sjt_functionParam362;
float sjt_functionParam363;
float sjt_functionParam364;
float sjt_functionParam365;
float sjt_functionParam366;
float sjt_functionParam367;
float sjt_functionParam368;
float sjt_functionParam369;
float sjt_functionParam370;
int32_t sjt_functionParam371;
sji_element* sjt_functionParam372;
int32_t sjt_functionParam4;
int32_t sjt_functionParam41;
sji_scene3dElement_model* sjt_functionParam42;
sji_element* sjt_functionParam5;
sjs_shader sjv_blurHorizontalShader;
sjs_shader sjv_blurVerticalShader;
sjs_anon5 sjv_borderPosition;
sjs_shader sjv_boxShader;
sjs_anon6 sjv_buttonState;
sjs_anon7 sjv_colors;
sjs_anon1 sjv_console;
sjs_anon4 sjv_convert;
float sjv_f32_pi;
int32_t sjv_i32_max;
int32_t sjv_i32_min;
sjs_shader sjv_imageShader;
int32_t sjv_mouseEvent_down;
int32_t sjv_mouseEvent_move;
int32_t sjv_mouseEvent_up;
sjs_anon2 sjv_parse;
sjs_shader sjv_phongColorShader;
sjs_shader sjv_phongTextureShader;
sjs_anon3 sjv_random;
sji_element* sjv_root;
sjs_scene2d sjv_rootScene;
sjs_windowRenderer sjv_rootWindowRenderer;
sjs_anon8 sjv_style;
sjs_shader sjv_textShader;
uint32_t sjv_u32_max;
sjs_string sjv_vertex_location_texture_normal_format;

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
void sjf_anon7_blue(sjs_anon7* _parent, sjs_color* _return);
void sjf_anon7_blue_heap(sjs_anon7* _parent, sjs_color_heap** _return);
void sjf_anon7_copy(sjs_anon7* _this, sjs_anon7* _from);
void sjf_anon7_destroy(sjs_anon7* _this);
void sjf_anon7_heap(sjs_anon7_heap* _this);
void sjf_anon7_red(sjs_anon7* _parent, sjs_color* _return);
void sjf_anon7_red_heap(sjs_anon7* _parent, sjs_color_heap** _return);
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
void sjf_array_i32_heap(sjs_array_i32_heap* _this);
void sjf_array_i32_initAt(sjs_array_i32* _parent, int32_t index, int32_t item);
void sjf_array_vertex_location_texture_normal(sjs_array_vertex_location_texture_normal* _this);
void sjf_array_vertex_location_texture_normal_copy(sjs_array_vertex_location_texture_normal* _this, sjs_array_vertex_location_texture_normal* _from);
void sjf_array_vertex_location_texture_normal_destroy(sjs_array_vertex_location_texture_normal* _this);
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
void sjf_planeVertexBuffer(float x0, float x1, float y0, float y1, float z0, float s0, float s1, float t0, float t1, sjs_vertexBuffer_vertex_location_texture_normal* _return);
void sjf_planeVertexBuffer_heap(float x0, float x1, float y0, float y1, float z0, float s0, float s1, float t0, float t1, sjs_vertexBuffer_vertex_location_texture_normal_heap** _return);
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
void sjf_scene2d(sjs_scene2d* _this);
void sjf_scene2dModel(sjs_scene2dModel* _this);
sjs_object* sjf_scene2dModel_asInterface(sjs_scene2dModel* _this, int typeId);
sji_scene3dElement_model* sjf_scene2dModel_as_sji_scene3dElement_model(sjs_scene2dModel* _this);
void sjf_scene2dModel_copy(sjs_scene2dModel* _this, sjs_scene2dModel* _from);
void sjf_scene2dModel_destroy(sjs_scene2dModel* _this);
void sjf_scene2dModel_heap(sjs_scene2dModel_heap* _this);
sjs_object* sjf_scene2dModel_heap_asInterface(sjs_scene2dModel_heap* _this, int typeId);
sji_scene3dElement_model* sjf_scene2dModel_heap_as_sji_scene3dElement_model(sjs_scene2dModel_heap* _this);
void sjf_scene2dModel_render(sjs_scene2dModel* _parent, sjs_scene3dElement* scene3d, sjs_mat4* model);
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
void sjf_vec3_normalize(sjs_vec3* _parent, sjs_vec3* _return);
void sjf_vec3_normalize_heap(sjs_vec3* _parent, sjs_vec3_heap** _return);
void sjf_vec3_subtract(sjs_vec3* _parent, sjs_vec3* v, sjs_vec3* _return);
void sjf_vec3_subtract_heap(sjs_vec3* _parent, sjs_vec3* v, sjs_vec3_heap** _return);
void sjf_vertexBuffer_vertex_location_texture_normal(sjs_vertexBuffer_vertex_location_texture_normal* _this);
void sjf_vertexBuffer_vertex_location_texture_normal_copy(sjs_vertexBuffer_vertex_location_texture_normal* _this, sjs_vertexBuffer_vertex_location_texture_normal* _from);
void sjf_vertexBuffer_vertex_location_texture_normal_destroy(sjs_vertexBuffer_vertex_location_texture_normal* _this);
void sjf_vertexBuffer_vertex_location_texture_normal_heap(sjs_vertexBuffer_vertex_location_texture_normal_heap* _this);
void sjf_vertexBuffer_vertex_location_texture_normal_render(sjs_vertexBuffer_vertex_location_texture_normal* _parent);
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
void sji_element_copy(sji_element* _this, sji_element* _from);
void sji_element_destroy(sji_element* _this);
void sji_scene3dElement_model_copy(sji_scene3dElement_model* _this, sji_scene3dElement_model* _from);
void sji_scene3dElement_model_destroy(sji_scene3dElement_model* _this);
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
    _this->fill = _from->fill;
    _this->left = _from->left;
    _this->right = _from->right;
    _this->top = _from->top;
    _this->bottom = _from->bottom;
}

void sjf_anon5_destroy(sjs_anon5* _this) {
}

void sjf_anon5_heap(sjs_anon5_heap* _this) {
}

void sjf_anon6(sjs_anon6* _this) {
}

void sjf_anon6_copy(sjs_anon6* _this, sjs_anon6* _from) {
    _this->normal = _from->normal;
    _this->hot = _from->hot;
    _this->pressed = _from->pressed;
}

void sjf_anon6_destroy(sjs_anon6* _this) {
}

void sjf_anon6_heap(sjs_anon6_heap* _this) {
}

void sjf_anon7(sjs_anon7* _this) {
}

void sjf_anon7_blue(sjs_anon7* _parent, sjs_color* _return) {
    _return->r = 0.0f;
    _return->g = 0.0f;
    _return->b = 1.0f;
    _return->a = 1.0f;
    sjf_color(_return);
}

void sjf_anon7_blue_heap(sjs_anon7* _parent, sjs_color_heap** _return) {
    (*_return) = (sjs_color_heap*)malloc(sizeof(sjs_color_heap));
    (*_return)->_refCount = 1;
    (*_return)->r = 0.0f;
    (*_return)->g = 0.0f;
    (*_return)->b = 1.0f;
    (*_return)->a = 1.0f;
    sjf_color_heap((*_return));
}

void sjf_anon7_copy(sjs_anon7* _this, sjs_anon7* _from) {
}

void sjf_anon7_destroy(sjs_anon7* _this) {
}

void sjf_anon7_heap(sjs_anon7_heap* _this) {
}

void sjf_anon7_red(sjs_anon7* _parent, sjs_color* _return) {
    _return->r = 1.0f;
    _return->g = 0.0f;
    _return->b = 0.0f;
    _return->a = 1.0f;
    sjf_color(_return);
}

void sjf_anon7_red_heap(sjs_anon7* _parent, sjs_color_heap** _return) {
    (*_return) = (sjs_color_heap*)malloc(sizeof(sjs_color_heap));
    (*_return)->_refCount = 1;
    (*_return)->r = 1.0f;
    (*_return)->g = 0.0f;
    (*_return)->b = 0.0f;
    (*_return)->a = 1.0f;
    sjf_color_heap((*_return));
}

void sjf_anon8(sjs_anon8* _this) {
}

void sjf_anon8_copy(sjs_anon8* _this, sjs_anon8* _from) {
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

void sjf_array_heap_element_initAt(sjs_array_heap_element* _parent, int32_t index, sji_element* item) {
    if (index >= _parent->size || index < 0) {
        printf("setAt: out of bounds %d:%d\n", index, _parent->size);
        exit(-1);
    }
    sji_element** p = (sji_element**)_parent->data;
    p[index] = item;
    p[index]->_refCount++;
    ;
}

void sjf_array_heap_model(sjs_array_heap_model* _this) {
    if (_this->size < 0) {
        exit(-1);
    }
    if (_this->data) {
        _this->_isGlobal = true;
    } else {
        _this->data = (uintptr_t)calloc(_this->size * sizeof(sji_scene3dElement_model*), 1);
        if (!_this->data) {
            printf("grow: out of memory\n");
            exit(-1);
        }
    }
}

void sjf_array_heap_model_copy(sjs_array_heap_model* _this, sjs_array_heap_model* _from) {
    _this->size = _from->size;
    _this->data = _from->data;
    _this->_isGlobal = _from->_isGlobal;
    _this->data = _from->data;
    if (!_this->_isGlobal && _this->data) {
        _retain((void*)_this->data);
    }
}

void sjf_array_heap_model_destroy(sjs_array_heap_model* _this) {
    if (!_this->_isGlobal && _this->data) {
        if (_release((void*)_this->data)) {
            free((sji_scene3dElement_model**)_this->data);
        }
    }
}

void sjf_array_heap_model_getAt_heap(sjs_array_heap_model* _parent, int32_t index, sji_scene3dElement_model** _return) {
    if (index >= _parent->size || index < 0) {
        printf("getAt: out of bounds\n");
        exit(-1);
    }
    sji_scene3dElement_model** p = (sji_scene3dElement_model**)_parent->data;
    (*_return) = p[index];
    (*_return)->_refCount++;
    ;
}

void sjf_array_heap_model_heap(sjs_array_heap_model_heap* _this) {
    if (_this->size < 0) {
        exit(-1);
    }
    if (_this->data) {
        _this->_isGlobal = true;
    } else {
        _this->data = (uintptr_t)calloc(_this->size * sizeof(sji_scene3dElement_model*), 1);
        if (!_this->data) {
            printf("grow: out of memory\n");
            exit(-1);
        }
    }
}

void sjf_array_heap_model_initAt(sjs_array_heap_model* _parent, int32_t index, sji_scene3dElement_model* item) {
    if (index >= _parent->size || index < 0) {
        printf("setAt: out of bounds %d:%d\n", index, _parent->size);
        exit(-1);
    }
    sji_scene3dElement_model** p = (sji_scene3dElement_model**)_parent->data;
    p[index] = item;
    p[index]->_refCount++;
    ;
}

void sjf_array_i32(sjs_array_i32* _this) {
    if (_this->size < 0) {
        exit(-1);
    }
    if (_this->data) {
        _this->_isGlobal = true;
    } else {
        _this->data = (uintptr_t)calloc(_this->size * sizeof(int32_t), 1);
        if (!_this->data) {
            printf("grow: out of memory\n");
            exit(-1);
        }
    }
}

void sjf_array_i32_copy(sjs_array_i32* _this, sjs_array_i32* _from) {
    _this->size = _from->size;
    _this->data = _from->data;
    _this->_isGlobal = _from->_isGlobal;
    _this->data = _from->data;
    if (!_this->_isGlobal && _this->data) {
        _retain((void*)_this->data);
    }
}

void sjf_array_i32_destroy(sjs_array_i32* _this) {
    if (!_this->_isGlobal && _this->data) {
        if (_release((void*)_this->data)) {
            free((int32_t*)_this->data);
        }
    }
}

void sjf_array_i32_heap(sjs_array_i32_heap* _this) {
    if (_this->size < 0) {
        exit(-1);
    }
    if (_this->data) {
        _this->_isGlobal = true;
    } else {
        _this->data = (uintptr_t)calloc(_this->size * sizeof(int32_t), 1);
        if (!_this->data) {
            printf("grow: out of memory\n");
            exit(-1);
        }
    }
}

void sjf_array_i32_initAt(sjs_array_i32* _parent, int32_t index, int32_t item) {
    if (index >= _parent->size || index < 0) {
        printf("setAt: out of bounds %d:%d\n", index, _parent->size);
        exit(-1);
    }
    int32_t* p = (int32_t*)_parent->data;
    p[index] = item;
    ;
}

void sjf_array_vertex_location_texture_normal(sjs_array_vertex_location_texture_normal* _this) {
    if (_this->size < 0) {
        exit(-1);
    }
    if (_this->data) {
        _this->_isGlobal = true;
    } else {
        _this->data = (uintptr_t)calloc(_this->size * sizeof(sjs_vertex_location_texture_normal), 1);
        if (!_this->data) {
            printf("grow: out of memory\n");
            exit(-1);
        }
    }
}

void sjf_array_vertex_location_texture_normal_copy(sjs_array_vertex_location_texture_normal* _this, sjs_array_vertex_location_texture_normal* _from) {
    _this->size = _from->size;
    _this->data = _from->data;
    _this->_isGlobal = _from->_isGlobal;
    _this->data = _from->data;
    if (!_this->_isGlobal && _this->data) {
        _retain((void*)_this->data);
    }
}

void sjf_array_vertex_location_texture_normal_destroy(sjs_array_vertex_location_texture_normal* _this) {
    if (!_this->_isGlobal && _this->data) {
        if (_release((void*)_this->data)) {
            free((sjs_vertex_location_texture_normal*)_this->data);
        }
    }
}

void sjf_array_vertex_location_texture_normal_heap(sjs_array_vertex_location_texture_normal_heap* _this) {
    if (_this->size < 0) {
        exit(-1);
    }
    if (_this->data) {
        _this->_isGlobal = true;
    } else {
        _this->data = (uintptr_t)calloc(_this->size * sizeof(sjs_vertex_location_texture_normal), 1);
        if (!_this->data) {
            printf("grow: out of memory\n");
            exit(-1);
        }
    }
}

void sjf_array_vertex_location_texture_normal_initAt(sjs_array_vertex_location_texture_normal* _parent, int32_t index, sjs_vertex_location_texture_normal* item) {
    if (index >= _parent->size || index < 0) {
        printf("setAt: out of bounds %d:%d\n", index, _parent->size);
        exit(-1);
    }
    sjs_vertex_location_texture_normal* p = (sjs_vertex_location_texture_normal*)_parent->data;
    sjf_vertex_location_texture_normal_copy(&p[index], item);
    ;
}

void sjf_boxRenderer(sjs_boxRenderer* _this) {
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

void sjf_boxRenderer_copy(sjs_boxRenderer* _this, sjs_boxRenderer* _from) {
    sjf_rect_copy(&_this->rect, &_from->rect);
    sjf_color_copy(&_this->color, &_from->color);
    _this->buffer = _from->buffer;
    _retain(_this->buffer);
}

void sjf_boxRenderer_destroy(sjs_boxRenderer* _this) {
    if (_release(_this->buffer)) {
        vertex_buffer_delete(_this->buffer);
    }
}

void sjf_boxRenderer_heap(sjs_boxRenderer_heap* _this) {
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

void sjf_boxRenderer_render(sjs_boxRenderer* _parent, sjs_scene2d* scene) {
    glUseProgram(sjv_boxShader.id);
    glUniformMatrix4fv(glGetUniformLocation(sjv_boxShader.id, "model" ), 1, 0, (GLfloat*)&scene->model);
    glUniformMatrix4fv(glGetUniformLocation(sjv_boxShader.id, "view" ), 1, 0, (GLfloat*)&scene->view);
    glUniformMatrix4fv(glGetUniformLocation(sjv_boxShader.id, "projection" ), 1, 0, (GLfloat*)&scene->projection);
    vertex_buffer_render(_parent->buffer, GL_TRIANGLES);
}

void sjf_color(sjs_color* _this) {
}

void sjf_color_copy(sjs_color* _this, sjs_color* _from) {
    _this->r = _from->r;
    _this->g = _from->g;
    _this->b = _from->b;
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
    sjf_color_copy(&_this->color, &_from->color);
    sjf_rect_copy(&_this->_rect, &_from->_rect);
    _this->_topDownRenderer = 0;
    sjf_boxRenderer_copy((sjs_boxRenderer*)(((char*)_this->_topDownRenderer) + sizeof(intptr_t)), (sjs_boxRenderer*)(((char*)_from->_topDownRenderer) + sizeof(intptr_t)));
    _this->_leftRightRenderer = 0;
    sjf_boxRenderer_copy((sjs_boxRenderer*)(((char*)_this->_leftRightRenderer) + sizeof(intptr_t)), (sjs_boxRenderer*)(((char*)_from->_leftRightRenderer) + sizeof(intptr_t)));
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
    sjs_rect* sjt_dot290;
    sjs_point* sjt_functionParam120;
    bool sjt_ifElse13;

    sjt_dot290 = &(_parent)->_rect;
    sjt_functionParam120 = point;
    sjf_rect_containsPoint(sjt_dot290, sjt_functionParam120, &sjt_ifElse13);
    if (sjt_ifElse13) {
        int32_t sjt_compare29;
        int32_t sjt_compare30;
        bool sjt_ifElse14;

        sjt_compare29 = eventId;
        sjt_compare30 = sjv_mouseEvent_move;
        sjt_ifElse14 = sjt_compare29 == sjt_compare30;
        if (sjt_ifElse14) {
            sjf_point_copy(&_parent->_point, point);
            if (_parent->_topDownRenderer != 0) {
                _parent->_topDownRenderer->_refCount--;
                if (_parent->_topDownRenderer->_refCount <= 0) {
                    sjf_boxRenderer_destroy((sjs_boxRenderer*)(((char*)_parent->_topDownRenderer) + sizeof(intptr_t)));
                }
            }

            _parent->_topDownRenderer = 0;
            if (_parent->_topDownRenderer != 0) {
                _parent->_topDownRenderer->_refCount++;
            }

            if (_parent->_leftRightRenderer != 0) {
                _parent->_leftRightRenderer->_refCount--;
                if (_parent->_leftRightRenderer->_refCount <= 0) {
                    sjf_boxRenderer_destroy((sjs_boxRenderer*)(((char*)_parent->_leftRightRenderer) + sizeof(intptr_t)));
                }
            }

            _parent->_leftRightRenderer = 0;
            if (_parent->_leftRightRenderer != 0) {
                _parent->_leftRightRenderer->_refCount++;
            }
        }
    }
}

void sjf_crossHairsElement_getChildren(sjs_crossHairsElement* _parent, sjs_array_heap_element** _return) {
    (*_return) = 0;
}

void sjf_crossHairsElement_getRect(sjs_crossHairsElement* _parent, sjs_rect** _return) {
    (*_return) = &(_parent)->_rect;
}

void sjf_crossHairsElement_getSize(sjs_crossHairsElement* _parent, sjs_size* maxSize, sjs_size* _return) {
    sjs_size* sjt_dot277;
    sjs_size* sjt_dot278;

    sjt_dot277 = maxSize;
    _return->w = (sjt_dot277)->w;
    sjt_dot278 = maxSize;
    _return->h = (sjt_dot278)->h;
    sjf_size(_return);
}

void sjf_crossHairsElement_getSize_heap(sjs_crossHairsElement* _parent, sjs_size* maxSize, sjs_size_heap** _return) {
    sjs_size* sjt_dot279;
    sjs_size* sjt_dot280;

    (*_return) = (sjs_size_heap*)malloc(sizeof(sjs_size_heap));
    (*_return)->_refCount = 1;
    sjt_dot279 = maxSize;
    (*_return)->w = (sjt_dot279)->w;
    sjt_dot280 = maxSize;
    (*_return)->h = (sjt_dot280)->h;
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
    bool result6;
    bool result7;
    bool sjt_ifElse10;
    bool sjt_ifElse11;
    bool sjt_ifElse12;
    bool sjt_ifElse9;
    sjs_boxRenderer_heap* sjt_isEmpty3;
    sjs_boxRenderer_heap* sjt_isEmpty4;
    sjs_boxRenderer_heap* sjt_isEmpty5;
    sjs_boxRenderer_heap* sjt_isEmpty6;
    bool sjt_not6;
    bool sjt_not7;

    sjt_isEmpty3 = (_parent)->_topDownRenderer;
    if (sjt_isEmpty3 != 0) {
        sjt_isEmpty3->_refCount++;
    }

    sjt_ifElse9 = (sjt_isEmpty3 == 0);
    if (sjt_ifElse9) {
        sjs_point* sjt_dot282;
        sjs_rect* sjt_dot283;
        sjs_rect* sjt_dot284;
        sjs_boxRenderer_heap* sjt_value3;

        sjt_value3 = (sjs_boxRenderer_heap*)malloc(sizeof(sjs_boxRenderer_heap));
        sjt_value3->_refCount = 1;
        sjt_dot282 = &(_parent)->_point;
        sjt_value3->rect.x = (sjt_dot282)->x;
        sjt_dot283 = &(_parent)->_rect;
        sjt_value3->rect.y = (sjt_dot283)->y;
        sjt_value3->rect.w = 1;
        sjt_dot284 = &(_parent)->_rect;
        sjt_value3->rect.h = (sjt_dot284)->h;
        sjf_rect(&sjt_value3->rect);
        sjf_color_copy(&sjt_value3->color, &(_parent)->color);
        sjf_boxRenderer_heap(sjt_value3);
        if (_parent->_topDownRenderer != 0) {
            _parent->_topDownRenderer->_refCount--;
            if (_parent->_topDownRenderer->_refCount <= 0) {
                sjf_boxRenderer_destroy((sjs_boxRenderer*)(((char*)_parent->_topDownRenderer) + sizeof(intptr_t)));
            }
        }

        _parent->_topDownRenderer = sjt_value3;
        if (_parent->_topDownRenderer != 0) {
            _parent->_topDownRenderer->_refCount++;
        }

        sjt_value3->_refCount--;
        if (sjt_value3->_refCount <= 0) {
            sjf_boxRenderer_destroy((sjs_boxRenderer*)(((char*)sjt_value3) + sizeof(intptr_t)));
        }
    } else {
    }

    sjt_isEmpty4 = (_parent)->_leftRightRenderer;
    if (sjt_isEmpty4 != 0) {
        sjt_isEmpty4->_refCount++;
    }

    sjt_ifElse10 = (sjt_isEmpty4 == 0);
    if (sjt_ifElse10) {
        sjs_rect* sjt_dot285;
        sjs_point* sjt_dot286;
        sjs_rect* sjt_dot287;
        sjs_boxRenderer_heap* sjt_value4;

        sjt_value4 = (sjs_boxRenderer_heap*)malloc(sizeof(sjs_boxRenderer_heap));
        sjt_value4->_refCount = 1;
        sjt_dot285 = &(_parent)->_rect;
        sjt_value4->rect.x = (sjt_dot285)->x;
        sjt_dot286 = &(_parent)->_point;
        sjt_value4->rect.y = (sjt_dot286)->y;
        sjt_dot287 = &(_parent)->_rect;
        sjt_value4->rect.w = (sjt_dot287)->w;
        sjt_value4->rect.h = 1;
        sjf_rect(&sjt_value4->rect);
        sjf_color_copy(&sjt_value4->color, &(_parent)->color);
        sjf_boxRenderer_heap(sjt_value4);
        if (_parent->_leftRightRenderer != 0) {
            _parent->_leftRightRenderer->_refCount--;
            if (_parent->_leftRightRenderer->_refCount <= 0) {
                sjf_boxRenderer_destroy((sjs_boxRenderer*)(((char*)_parent->_leftRightRenderer) + sizeof(intptr_t)));
            }
        }

        _parent->_leftRightRenderer = sjt_value4;
        if (_parent->_leftRightRenderer != 0) {
            _parent->_leftRightRenderer->_refCount++;
        }

        sjt_value4->_refCount--;
        if (sjt_value4->_refCount <= 0) {
            sjf_boxRenderer_destroy((sjs_boxRenderer*)(((char*)sjt_value4) + sizeof(intptr_t)));
        }
    } else {
    }

    sjt_isEmpty5 = (_parent)->_topDownRenderer;
    if (sjt_isEmpty5 != 0) {
        sjt_isEmpty5->_refCount++;
    }

    sjt_not6 = (sjt_isEmpty5 == 0);
    result6 = !sjt_not6;
    sjt_ifElse11 = result6;
    if (sjt_ifElse11) {
        sjs_boxRenderer* sjt_dot288;
        sjs_scene2d* sjt_functionParam118;
        sjs_boxRenderer_heap* sjt_getValue2;

        sjt_getValue2 = (_parent)->_topDownRenderer;
        if (sjt_getValue2 != 0) {
            sjt_getValue2->_refCount++;
        }

        sjt_dot288 = (sjs_boxRenderer*)(((char*)sjt_getValue2) + sizeof(intptr_t));
        sjt_functionParam118 = scene;
        sjf_boxRenderer_render(sjt_dot288, sjt_functionParam118);

        if (sjt_getValue2 != 0) {
            sjt_getValue2->_refCount--;
            if (sjt_getValue2->_refCount <= 0) {
                sjf_boxRenderer_destroy((sjs_boxRenderer*)(((char*)sjt_getValue2) + sizeof(intptr_t)));
            }
        }
    }

    sjt_isEmpty6 = (_parent)->_leftRightRenderer;
    if (sjt_isEmpty6 != 0) {
        sjt_isEmpty6->_refCount++;
    }

    sjt_not7 = (sjt_isEmpty6 == 0);
    result7 = !sjt_not7;
    sjt_ifElse12 = result7;
    if (sjt_ifElse12) {
        sjs_boxRenderer* sjt_dot289;
        sjs_scene2d* sjt_functionParam119;
        sjs_boxRenderer_heap* sjt_getValue3;

        sjt_getValue3 = (_parent)->_leftRightRenderer;
        if (sjt_getValue3 != 0) {
            sjt_getValue3->_refCount++;
        }

        sjt_dot289 = (sjs_boxRenderer*)(((char*)sjt_getValue3) + sizeof(intptr_t));
        sjt_functionParam119 = scene;
        sjf_boxRenderer_render(sjt_dot289, sjt_functionParam119);

        if (sjt_getValue3 != 0) {
            sjt_getValue3->_refCount--;
            if (sjt_getValue3->_refCount <= 0) {
                sjf_boxRenderer_destroy((sjs_boxRenderer*)(((char*)sjt_getValue3) + sizeof(intptr_t)));
            }
        }
    }

    if (sjt_isEmpty3 != 0) {
        sjt_isEmpty3->_refCount--;
        if (sjt_isEmpty3->_refCount <= 0) {
            sjf_boxRenderer_destroy((sjs_boxRenderer*)(((char*)sjt_isEmpty3) + sizeof(intptr_t)));
        }
    }
    if (sjt_isEmpty4 != 0) {
        sjt_isEmpty4->_refCount--;
        if (sjt_isEmpty4->_refCount <= 0) {
            sjf_boxRenderer_destroy((sjs_boxRenderer*)(((char*)sjt_isEmpty4) + sizeof(intptr_t)));
        }
    }
    if (sjt_isEmpty5 != 0) {
        sjt_isEmpty5->_refCount--;
        if (sjt_isEmpty5->_refCount <= 0) {
            sjf_boxRenderer_destroy((sjs_boxRenderer*)(((char*)sjt_isEmpty5) + sizeof(intptr_t)));
        }
    }
    if (sjt_isEmpty6 != 0) {
        sjt_isEmpty6->_refCount--;
        if (sjt_isEmpty6->_refCount <= 0) {
            sjf_boxRenderer_destroy((sjs_boxRenderer*)(((char*)sjt_isEmpty6) + sizeof(intptr_t)));
        }
    }
}

void sjf_crossHairsElement_setRect(sjs_crossHairsElement* _parent, sjs_rect* rect_) {
    bool result5;
    sjs_rect* sjt_dot281;
    sjs_rect* sjt_functionParam117;
    bool sjt_ifElse8;
    bool sjt_not5;

    sjt_dot281 = &(_parent)->_rect;
    sjt_functionParam117 = rect_;
    sjf_rect_isEqual(sjt_dot281, sjt_functionParam117, &sjt_not5);
    result5 = !sjt_not5;
    sjt_ifElse8 = result5;
    if (sjt_ifElse8) {
        sjf_rect_copy(&_parent->_rect, rect_);
        if (_parent->_topDownRenderer != 0) {
            _parent->_topDownRenderer->_refCount--;
            if (_parent->_topDownRenderer->_refCount <= 0) {
                sjf_boxRenderer_destroy((sjs_boxRenderer*)(((char*)_parent->_topDownRenderer) + sizeof(intptr_t)));
            }
        }

        _parent->_topDownRenderer = 0;
        if (_parent->_topDownRenderer != 0) {
            _parent->_topDownRenderer->_refCount++;
        }

        if (_parent->_leftRightRenderer != 0) {
            _parent->_leftRightRenderer->_refCount--;
            if (_parent->_leftRightRenderer->_refCount <= 0) {
                sjf_boxRenderer_destroy((sjs_boxRenderer*)(((char*)_parent->_leftRightRenderer) + sizeof(intptr_t)));
            }
        }

        _parent->_leftRightRenderer = 0;
        if (_parent->_leftRightRenderer != 0) {
            _parent->_leftRightRenderer->_refCount++;
        }
    }
}

void sjf_cubeVertexBuffer(float x0, float x1, float y0, float y1, float z0, float z1, float s0, float s1, float t0, float t1, sjs_vertexBuffer_vertex_location_texture_normal* _return) {
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
    sjs_vertex_location_texture_normal sjt_call34;
    sjs_vertex_location_texture_normal sjt_call35;
    sjs_vertex_location_texture_normal sjt_call36;
    int32_t sjt_cast17;
    int32_t sjt_cast18;
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
    int32_t sjt_functionParam131;
    int32_t sjt_functionParam132;
    int32_t sjt_functionParam133;
    int32_t sjt_functionParam134;
    int32_t sjt_functionParam135;
    int32_t sjt_functionParam136;
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
    int32_t sjt_functionParam149;
    int32_t sjt_functionParam150;
    int32_t sjt_functionParam151;
    int32_t sjt_functionParam152;
    int32_t sjt_functionParam153;
    int32_t sjt_functionParam154;
    int32_t sjt_functionParam155;
    int32_t sjt_functionParam156;
    int32_t sjt_functionParam157;
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
    sjs_vertex_location_texture_normal* sjt_functionParam194;
    int32_t sjt_functionParam195;
    sjs_vertex_location_texture_normal* sjt_functionParam196;
    int32_t sjt_functionParam197;
    sjs_vertex_location_texture_normal* sjt_functionParam198;
    int32_t sjt_functionParam199;
    sjs_vertex_location_texture_normal* sjt_functionParam200;
    int32_t sjt_functionParam201;
    sjs_vertex_location_texture_normal* sjt_functionParam202;
    int32_t sjt_functionParam203;
    sjs_vertex_location_texture_normal* sjt_functionParam204;
    int32_t sjt_functionParam205;
    sjs_vertex_location_texture_normal* sjt_functionParam206;
    int32_t sjt_functionParam207;
    sjs_vertex_location_texture_normal* sjt_functionParam208;
    int32_t sjt_functionParam209;
    sjs_vertex_location_texture_normal* sjt_functionParam210;
    int32_t sjt_functionParam211;
    sjs_vertex_location_texture_normal* sjt_functionParam212;
    int32_t sjt_functionParam213;
    sjs_vertex_location_texture_normal* sjt_functionParam214;
    int32_t sjt_functionParam215;
    sjs_vertex_location_texture_normal* sjt_functionParam216;
    int32_t sjt_functionParam217;
    sjs_vertex_location_texture_normal* sjt_functionParam218;
    int32_t sjt_functionParam219;
    sjs_vertex_location_texture_normal* sjt_functionParam220;
    int32_t sjt_functionParam221;
    sjs_vertex_location_texture_normal* sjt_functionParam222;
    int32_t sjt_functionParam223;
    sjs_vertex_location_texture_normal* sjt_functionParam224;
    int32_t sjt_functionParam225;
    sjs_vertex_location_texture_normal* sjt_functionParam226;
    int32_t sjt_functionParam227;
    sjs_vertex_location_texture_normal* sjt_functionParam228;
    int32_t sjt_functionParam229;
    sjs_vertex_location_texture_normal* sjt_functionParam230;
    int32_t sjt_functionParam231;
    sjs_vertex_location_texture_normal* sjt_functionParam232;
    int32_t sjt_functionParam233;
    sjs_vertex_location_texture_normal* sjt_functionParam234;
    int32_t sjt_functionParam235;
    sjs_vertex_location_texture_normal* sjt_functionParam236;
    int32_t sjt_functionParam237;
    sjs_vertex_location_texture_normal* sjt_functionParam238;
    int32_t sjt_functionParam239;
    sjs_vertex_location_texture_normal* sjt_functionParam240;

    sjf_string_copy(&_return->format, &sjv_vertex_location_texture_normal_format);
    _return->indices.size = 36;
    sjt_cast17 = 0;
    _return->indices.data = (uintptr_t)sjt_cast17;
    _return->indices._isGlobal = false;
    sjf_array_i32(&_return->indices);
    sjt_functionParam121 = 0;
    sjt_functionParam122 = 0;
    sjf_array_i32_initAt(&_return->indices, sjt_functionParam121, sjt_functionParam122);
    sjt_functionParam123 = 1;
    sjt_functionParam124 = 1;
    sjf_array_i32_initAt(&_return->indices, sjt_functionParam123, sjt_functionParam124);
    sjt_functionParam125 = 2;
    sjt_functionParam126 = 2;
    sjf_array_i32_initAt(&_return->indices, sjt_functionParam125, sjt_functionParam126);
    sjt_functionParam127 = 3;
    sjt_functionParam128 = 0;
    sjf_array_i32_initAt(&_return->indices, sjt_functionParam127, sjt_functionParam128);
    sjt_functionParam129 = 4;
    sjt_functionParam130 = 2;
    sjf_array_i32_initAt(&_return->indices, sjt_functionParam129, sjt_functionParam130);
    sjt_functionParam131 = 5;
    sjt_functionParam132 = 3;
    sjf_array_i32_initAt(&_return->indices, sjt_functionParam131, sjt_functionParam132);
    sjt_functionParam133 = 6;
    sjt_functionParam134 = 4;
    sjf_array_i32_initAt(&_return->indices, sjt_functionParam133, sjt_functionParam134);
    sjt_functionParam135 = 7;
    sjt_functionParam136 = 5;
    sjf_array_i32_initAt(&_return->indices, sjt_functionParam135, sjt_functionParam136);
    sjt_functionParam137 = 8;
    sjt_functionParam138 = 6;
    sjf_array_i32_initAt(&_return->indices, sjt_functionParam137, sjt_functionParam138);
    sjt_functionParam139 = 9;
    sjt_functionParam140 = 4;
    sjf_array_i32_initAt(&_return->indices, sjt_functionParam139, sjt_functionParam140);
    sjt_functionParam141 = 10;
    sjt_functionParam142 = 6;
    sjf_array_i32_initAt(&_return->indices, sjt_functionParam141, sjt_functionParam142);
    sjt_functionParam143 = 11;
    sjt_functionParam144 = 7;
    sjf_array_i32_initAt(&_return->indices, sjt_functionParam143, sjt_functionParam144);
    sjt_functionParam145 = 12;
    sjt_functionParam146 = 8;
    sjf_array_i32_initAt(&_return->indices, sjt_functionParam145, sjt_functionParam146);
    sjt_functionParam147 = 13;
    sjt_functionParam148 = 9;
    sjf_array_i32_initAt(&_return->indices, sjt_functionParam147, sjt_functionParam148);
    sjt_functionParam149 = 14;
    sjt_functionParam150 = 10;
    sjf_array_i32_initAt(&_return->indices, sjt_functionParam149, sjt_functionParam150);
    sjt_functionParam151 = 15;
    sjt_functionParam152 = 8;
    sjf_array_i32_initAt(&_return->indices, sjt_functionParam151, sjt_functionParam152);
    sjt_functionParam153 = 16;
    sjt_functionParam154 = 10;
    sjf_array_i32_initAt(&_return->indices, sjt_functionParam153, sjt_functionParam154);
    sjt_functionParam155 = 17;
    sjt_functionParam156 = 11;
    sjf_array_i32_initAt(&_return->indices, sjt_functionParam155, sjt_functionParam156);
    sjt_functionParam157 = 18;
    sjt_functionParam158 = 12;
    sjf_array_i32_initAt(&_return->indices, sjt_functionParam157, sjt_functionParam158);
    sjt_functionParam159 = 19;
    sjt_functionParam160 = 13;
    sjf_array_i32_initAt(&_return->indices, sjt_functionParam159, sjt_functionParam160);
    sjt_functionParam161 = 20;
    sjt_functionParam162 = 14;
    sjf_array_i32_initAt(&_return->indices, sjt_functionParam161, sjt_functionParam162);
    sjt_functionParam163 = 21;
    sjt_functionParam164 = 12;
    sjf_array_i32_initAt(&_return->indices, sjt_functionParam163, sjt_functionParam164);
    sjt_functionParam165 = 22;
    sjt_functionParam166 = 14;
    sjf_array_i32_initAt(&_return->indices, sjt_functionParam165, sjt_functionParam166);
    sjt_functionParam167 = 23;
    sjt_functionParam168 = 15;
    sjf_array_i32_initAt(&_return->indices, sjt_functionParam167, sjt_functionParam168);
    sjt_functionParam169 = 24;
    sjt_functionParam170 = 16;
    sjf_array_i32_initAt(&_return->indices, sjt_functionParam169, sjt_functionParam170);
    sjt_functionParam171 = 25;
    sjt_functionParam172 = 17;
    sjf_array_i32_initAt(&_return->indices, sjt_functionParam171, sjt_functionParam172);
    sjt_functionParam173 = 26;
    sjt_functionParam174 = 18;
    sjf_array_i32_initAt(&_return->indices, sjt_functionParam173, sjt_functionParam174);
    sjt_functionParam175 = 27;
    sjt_functionParam176 = 16;
    sjf_array_i32_initAt(&_return->indices, sjt_functionParam175, sjt_functionParam176);
    sjt_functionParam177 = 28;
    sjt_functionParam178 = 18;
    sjf_array_i32_initAt(&_return->indices, sjt_functionParam177, sjt_functionParam178);
    sjt_functionParam179 = 29;
    sjt_functionParam180 = 19;
    sjf_array_i32_initAt(&_return->indices, sjt_functionParam179, sjt_functionParam180);
    sjt_functionParam181 = 30;
    sjt_functionParam182 = 20;
    sjf_array_i32_initAt(&_return->indices, sjt_functionParam181, sjt_functionParam182);
    sjt_functionParam183 = 31;
    sjt_functionParam184 = 21;
    sjf_array_i32_initAt(&_return->indices, sjt_functionParam183, sjt_functionParam184);
    sjt_functionParam185 = 32;
    sjt_functionParam186 = 22;
    sjf_array_i32_initAt(&_return->indices, sjt_functionParam185, sjt_functionParam186);
    sjt_functionParam187 = 33;
    sjt_functionParam188 = 20;
    sjf_array_i32_initAt(&_return->indices, sjt_functionParam187, sjt_functionParam188);
    sjt_functionParam189 = 34;
    sjt_functionParam190 = 22;
    sjf_array_i32_initAt(&_return->indices, sjt_functionParam189, sjt_functionParam190);
    sjt_functionParam191 = 35;
    sjt_functionParam192 = 23;
    sjf_array_i32_initAt(&_return->indices, sjt_functionParam191, sjt_functionParam192);
    _return->vertices.size = 24;
    sjt_cast18 = 0;
    _return->vertices.data = (uintptr_t)sjt_cast18;
    _return->vertices._isGlobal = false;
    sjf_array_vertex_location_texture_normal(&_return->vertices);
    sjt_functionParam193 = 0;
    sjt_call13.location.x = x0;
    sjt_call13.location.y = y0;
    sjt_call13.location.z = z0;
    sjf_vec3(&sjt_call13.location);
    sjt_call13.texture.x = s0;
    sjt_call13.texture.y = t0;
    sjf_vec2(&sjt_call13.texture);
    sjt_call13.normal.x = 0.0f;
    sjt_call13.normal.y = 0.0f;
    sjt_call13.normal.z = -1.0f;
    sjf_vec3(&sjt_call13.normal);
    sjf_vertex_location_texture_normal(&sjt_call13);
    sjt_functionParam194 = &sjt_call13;
    sjf_array_vertex_location_texture_normal_initAt(&_return->vertices, sjt_functionParam193, sjt_functionParam194);
    sjt_functionParam195 = 1;
    sjt_call14.location.x = x0;
    sjt_call14.location.y = y1;
    sjt_call14.location.z = z0;
    sjf_vec3(&sjt_call14.location);
    sjt_call14.texture.x = s0;
    sjt_call14.texture.y = t1;
    sjf_vec2(&sjt_call14.texture);
    sjt_call14.normal.x = 0.0f;
    sjt_call14.normal.y = 0.0f;
    sjt_call14.normal.z = -1.0f;
    sjf_vec3(&sjt_call14.normal);
    sjf_vertex_location_texture_normal(&sjt_call14);
    sjt_functionParam196 = &sjt_call14;
    sjf_array_vertex_location_texture_normal_initAt(&_return->vertices, sjt_functionParam195, sjt_functionParam196);
    sjt_functionParam197 = 2;
    sjt_call15.location.x = x1;
    sjt_call15.location.y = y1;
    sjt_call15.location.z = z0;
    sjf_vec3(&sjt_call15.location);
    sjt_call15.texture.x = s1;
    sjt_call15.texture.y = t1;
    sjf_vec2(&sjt_call15.texture);
    sjt_call15.normal.x = 0.0f;
    sjt_call15.normal.y = 0.0f;
    sjt_call15.normal.z = -1.0f;
    sjf_vec3(&sjt_call15.normal);
    sjf_vertex_location_texture_normal(&sjt_call15);
    sjt_functionParam198 = &sjt_call15;
    sjf_array_vertex_location_texture_normal_initAt(&_return->vertices, sjt_functionParam197, sjt_functionParam198);
    sjt_functionParam199 = 3;
    sjt_call16.location.x = x1;
    sjt_call16.location.y = y0;
    sjt_call16.location.z = z0;
    sjf_vec3(&sjt_call16.location);
    sjt_call16.texture.x = s1;
    sjt_call16.texture.y = t0;
    sjf_vec2(&sjt_call16.texture);
    sjt_call16.normal.x = 0.0f;
    sjt_call16.normal.y = 0.0f;
    sjt_call16.normal.z = -1.0f;
    sjf_vec3(&sjt_call16.normal);
    sjf_vertex_location_texture_normal(&sjt_call16);
    sjt_functionParam200 = &sjt_call16;
    sjf_array_vertex_location_texture_normal_initAt(&_return->vertices, sjt_functionParam199, sjt_functionParam200);
    sjt_functionParam201 = 4;
    sjt_call17.location.x = x0;
    sjt_call17.location.y = y0;
    sjt_call17.location.z = z1;
    sjf_vec3(&sjt_call17.location);
    sjt_call17.texture.x = s0;
    sjt_call17.texture.y = t0;
    sjf_vec2(&sjt_call17.texture);
    sjt_call17.normal.x = 0.0f;
    sjt_call17.normal.y = 0.0f;
    sjt_call17.normal.z = 1.0f;
    sjf_vec3(&sjt_call17.normal);
    sjf_vertex_location_texture_normal(&sjt_call17);
    sjt_functionParam202 = &sjt_call17;
    sjf_array_vertex_location_texture_normal_initAt(&_return->vertices, sjt_functionParam201, sjt_functionParam202);
    sjt_functionParam203 = 5;
    sjt_call18.location.x = x0;
    sjt_call18.location.y = y1;
    sjt_call18.location.z = z1;
    sjf_vec3(&sjt_call18.location);
    sjt_call18.texture.x = s0;
    sjt_call18.texture.y = t1;
    sjf_vec2(&sjt_call18.texture);
    sjt_call18.normal.x = 0.0f;
    sjt_call18.normal.y = 0.0f;
    sjt_call18.normal.z = 1.0f;
    sjf_vec3(&sjt_call18.normal);
    sjf_vertex_location_texture_normal(&sjt_call18);
    sjt_functionParam204 = &sjt_call18;
    sjf_array_vertex_location_texture_normal_initAt(&_return->vertices, sjt_functionParam203, sjt_functionParam204);
    sjt_functionParam205 = 6;
    sjt_call19.location.x = x1;
    sjt_call19.location.y = y1;
    sjt_call19.location.z = z1;
    sjf_vec3(&sjt_call19.location);
    sjt_call19.texture.x = s1;
    sjt_call19.texture.y = t1;
    sjf_vec2(&sjt_call19.texture);
    sjt_call19.normal.x = 0.0f;
    sjt_call19.normal.y = 0.0f;
    sjt_call19.normal.z = 1.0f;
    sjf_vec3(&sjt_call19.normal);
    sjf_vertex_location_texture_normal(&sjt_call19);
    sjt_functionParam206 = &sjt_call19;
    sjf_array_vertex_location_texture_normal_initAt(&_return->vertices, sjt_functionParam205, sjt_functionParam206);
    sjt_functionParam207 = 7;
    sjt_call20.location.x = x1;
    sjt_call20.location.y = y0;
    sjt_call20.location.z = z1;
    sjf_vec3(&sjt_call20.location);
    sjt_call20.texture.x = s1;
    sjt_call20.texture.y = t0;
    sjf_vec2(&sjt_call20.texture);
    sjt_call20.normal.x = 0.0f;
    sjt_call20.normal.y = 0.0f;
    sjt_call20.normal.z = 1.0f;
    sjf_vec3(&sjt_call20.normal);
    sjf_vertex_location_texture_normal(&sjt_call20);
    sjt_functionParam208 = &sjt_call20;
    sjf_array_vertex_location_texture_normal_initAt(&_return->vertices, sjt_functionParam207, sjt_functionParam208);
    sjt_functionParam209 = 8;
    sjt_call21.location.x = x0;
    sjt_call21.location.y = y0;
    sjt_call21.location.z = z0;
    sjf_vec3(&sjt_call21.location);
    sjt_call21.texture.x = s0;
    sjt_call21.texture.y = t0;
    sjf_vec2(&sjt_call21.texture);
    sjt_call21.normal.x = -1.0f;
    sjt_call21.normal.y = 0.0f;
    sjt_call21.normal.z = 0.0f;
    sjf_vec3(&sjt_call21.normal);
    sjf_vertex_location_texture_normal(&sjt_call21);
    sjt_functionParam210 = &sjt_call21;
    sjf_array_vertex_location_texture_normal_initAt(&_return->vertices, sjt_functionParam209, sjt_functionParam210);
    sjt_functionParam211 = 9;
    sjt_call22.location.x = x0;
    sjt_call22.location.y = y1;
    sjt_call22.location.z = z0;
    sjf_vec3(&sjt_call22.location);
    sjt_call22.texture.x = s0;
    sjt_call22.texture.y = t1;
    sjf_vec2(&sjt_call22.texture);
    sjt_call22.normal.x = -1.0f;
    sjt_call22.normal.y = 0.0f;
    sjt_call22.normal.z = 0.0f;
    sjf_vec3(&sjt_call22.normal);
    sjf_vertex_location_texture_normal(&sjt_call22);
    sjt_functionParam212 = &sjt_call22;
    sjf_array_vertex_location_texture_normal_initAt(&_return->vertices, sjt_functionParam211, sjt_functionParam212);
    sjt_functionParam213 = 10;
    sjt_call23.location.x = x0;
    sjt_call23.location.y = y1;
    sjt_call23.location.z = z1;
    sjf_vec3(&sjt_call23.location);
    sjt_call23.texture.x = s1;
    sjt_call23.texture.y = t1;
    sjf_vec2(&sjt_call23.texture);
    sjt_call23.normal.x = -1.0f;
    sjt_call23.normal.y = 0.0f;
    sjt_call23.normal.z = 0.0f;
    sjf_vec3(&sjt_call23.normal);
    sjf_vertex_location_texture_normal(&sjt_call23);
    sjt_functionParam214 = &sjt_call23;
    sjf_array_vertex_location_texture_normal_initAt(&_return->vertices, sjt_functionParam213, sjt_functionParam214);
    sjt_functionParam215 = 11;
    sjt_call24.location.x = x0;
    sjt_call24.location.y = y0;
    sjt_call24.location.z = z1;
    sjf_vec3(&sjt_call24.location);
    sjt_call24.texture.x = s1;
    sjt_call24.texture.y = t0;
    sjf_vec2(&sjt_call24.texture);
    sjt_call24.normal.x = -1.0f;
    sjt_call24.normal.y = 0.0f;
    sjt_call24.normal.z = 0.0f;
    sjf_vec3(&sjt_call24.normal);
    sjf_vertex_location_texture_normal(&sjt_call24);
    sjt_functionParam216 = &sjt_call24;
    sjf_array_vertex_location_texture_normal_initAt(&_return->vertices, sjt_functionParam215, sjt_functionParam216);
    sjt_functionParam217 = 12;
    sjt_call25.location.x = x1;
    sjt_call25.location.y = y0;
    sjt_call25.location.z = z0;
    sjf_vec3(&sjt_call25.location);
    sjt_call25.texture.x = s0;
    sjt_call25.texture.y = t0;
    sjf_vec2(&sjt_call25.texture);
    sjt_call25.normal.x = 1.0f;
    sjt_call25.normal.y = 0.0f;
    sjt_call25.normal.z = 0.0f;
    sjf_vec3(&sjt_call25.normal);
    sjf_vertex_location_texture_normal(&sjt_call25);
    sjt_functionParam218 = &sjt_call25;
    sjf_array_vertex_location_texture_normal_initAt(&_return->vertices, sjt_functionParam217, sjt_functionParam218);
    sjt_functionParam219 = 13;
    sjt_call26.location.x = x1;
    sjt_call26.location.y = y1;
    sjt_call26.location.z = z0;
    sjf_vec3(&sjt_call26.location);
    sjt_call26.texture.x = s0;
    sjt_call26.texture.y = t1;
    sjf_vec2(&sjt_call26.texture);
    sjt_call26.normal.x = 1.0f;
    sjt_call26.normal.y = 0.0f;
    sjt_call26.normal.z = 0.0f;
    sjf_vec3(&sjt_call26.normal);
    sjf_vertex_location_texture_normal(&sjt_call26);
    sjt_functionParam220 = &sjt_call26;
    sjf_array_vertex_location_texture_normal_initAt(&_return->vertices, sjt_functionParam219, sjt_functionParam220);
    sjt_functionParam221 = 14;
    sjt_call27.location.x = x1;
    sjt_call27.location.y = y1;
    sjt_call27.location.z = z1;
    sjf_vec3(&sjt_call27.location);
    sjt_call27.texture.x = s1;
    sjt_call27.texture.y = t1;
    sjf_vec2(&sjt_call27.texture);
    sjt_call27.normal.x = 1.0f;
    sjt_call27.normal.y = 0.0f;
    sjt_call27.normal.z = 0.0f;
    sjf_vec3(&sjt_call27.normal);
    sjf_vertex_location_texture_normal(&sjt_call27);
    sjt_functionParam222 = &sjt_call27;
    sjf_array_vertex_location_texture_normal_initAt(&_return->vertices, sjt_functionParam221, sjt_functionParam222);
    sjt_functionParam223 = 15;
    sjt_call28.location.x = x1;
    sjt_call28.location.y = y0;
    sjt_call28.location.z = z1;
    sjf_vec3(&sjt_call28.location);
    sjt_call28.texture.x = s1;
    sjt_call28.texture.y = t0;
    sjf_vec2(&sjt_call28.texture);
    sjt_call28.normal.x = 1.0f;
    sjt_call28.normal.y = 0.0f;
    sjt_call28.normal.z = 0.0f;
    sjf_vec3(&sjt_call28.normal);
    sjf_vertex_location_texture_normal(&sjt_call28);
    sjt_functionParam224 = &sjt_call28;
    sjf_array_vertex_location_texture_normal_initAt(&_return->vertices, sjt_functionParam223, sjt_functionParam224);
    sjt_functionParam225 = 16;
    sjt_call29.location.x = x0;
    sjt_call29.location.y = y0;
    sjt_call29.location.z = z0;
    sjf_vec3(&sjt_call29.location);
    sjt_call29.texture.x = s0;
    sjt_call29.texture.y = t0;
    sjf_vec2(&sjt_call29.texture);
    sjt_call29.normal.x = 0.0f;
    sjt_call29.normal.y = -1.0f;
    sjt_call29.normal.z = 0.0f;
    sjf_vec3(&sjt_call29.normal);
    sjf_vertex_location_texture_normal(&sjt_call29);
    sjt_functionParam226 = &sjt_call29;
    sjf_array_vertex_location_texture_normal_initAt(&_return->vertices, sjt_functionParam225, sjt_functionParam226);
    sjt_functionParam227 = 17;
    sjt_call30.location.x = x0;
    sjt_call30.location.y = y0;
    sjt_call30.location.z = z1;
    sjf_vec3(&sjt_call30.location);
    sjt_call30.texture.x = s0;
    sjt_call30.texture.y = t1;
    sjf_vec2(&sjt_call30.texture);
    sjt_call30.normal.x = 0.0f;
    sjt_call30.normal.y = -1.0f;
    sjt_call30.normal.z = 0.0f;
    sjf_vec3(&sjt_call30.normal);
    sjf_vertex_location_texture_normal(&sjt_call30);
    sjt_functionParam228 = &sjt_call30;
    sjf_array_vertex_location_texture_normal_initAt(&_return->vertices, sjt_functionParam227, sjt_functionParam228);
    sjt_functionParam229 = 18;
    sjt_call31.location.x = x1;
    sjt_call31.location.y = y0;
    sjt_call31.location.z = z1;
    sjf_vec3(&sjt_call31.location);
    sjt_call31.texture.x = s1;
    sjt_call31.texture.y = t1;
    sjf_vec2(&sjt_call31.texture);
    sjt_call31.normal.x = 0.0f;
    sjt_call31.normal.y = -1.0f;
    sjt_call31.normal.z = 0.0f;
    sjf_vec3(&sjt_call31.normal);
    sjf_vertex_location_texture_normal(&sjt_call31);
    sjt_functionParam230 = &sjt_call31;
    sjf_array_vertex_location_texture_normal_initAt(&_return->vertices, sjt_functionParam229, sjt_functionParam230);
    sjt_functionParam231 = 19;
    sjt_call32.location.x = x1;
    sjt_call32.location.y = y0;
    sjt_call32.location.z = z0;
    sjf_vec3(&sjt_call32.location);
    sjt_call32.texture.x = s1;
    sjt_call32.texture.y = t0;
    sjf_vec2(&sjt_call32.texture);
    sjt_call32.normal.x = 0.0f;
    sjt_call32.normal.y = -1.0f;
    sjt_call32.normal.z = 0.0f;
    sjf_vec3(&sjt_call32.normal);
    sjf_vertex_location_texture_normal(&sjt_call32);
    sjt_functionParam232 = &sjt_call32;
    sjf_array_vertex_location_texture_normal_initAt(&_return->vertices, sjt_functionParam231, sjt_functionParam232);
    sjt_functionParam233 = 20;
    sjt_call33.location.x = x0;
    sjt_call33.location.y = y1;
    sjt_call33.location.z = z0;
    sjf_vec3(&sjt_call33.location);
    sjt_call33.texture.x = s0;
    sjt_call33.texture.y = t0;
    sjf_vec2(&sjt_call33.texture);
    sjt_call33.normal.x = 0.0f;
    sjt_call33.normal.y = 1.0f;
    sjt_call33.normal.z = 0.0f;
    sjf_vec3(&sjt_call33.normal);
    sjf_vertex_location_texture_normal(&sjt_call33);
    sjt_functionParam234 = &sjt_call33;
    sjf_array_vertex_location_texture_normal_initAt(&_return->vertices, sjt_functionParam233, sjt_functionParam234);
    sjt_functionParam235 = 21;
    sjt_call34.location.x = x0;
    sjt_call34.location.y = y1;
    sjt_call34.location.z = z1;
    sjf_vec3(&sjt_call34.location);
    sjt_call34.texture.x = s0;
    sjt_call34.texture.y = t1;
    sjf_vec2(&sjt_call34.texture);
    sjt_call34.normal.x = 0.0f;
    sjt_call34.normal.y = 1.0f;
    sjt_call34.normal.z = 0.0f;
    sjf_vec3(&sjt_call34.normal);
    sjf_vertex_location_texture_normal(&sjt_call34);
    sjt_functionParam236 = &sjt_call34;
    sjf_array_vertex_location_texture_normal_initAt(&_return->vertices, sjt_functionParam235, sjt_functionParam236);
    sjt_functionParam237 = 22;
    sjt_call35.location.x = x1;
    sjt_call35.location.y = y1;
    sjt_call35.location.z = z1;
    sjf_vec3(&sjt_call35.location);
    sjt_call35.texture.x = s1;
    sjt_call35.texture.y = t1;
    sjf_vec2(&sjt_call35.texture);
    sjt_call35.normal.x = 0.0f;
    sjt_call35.normal.y = 1.0f;
    sjt_call35.normal.z = 0.0f;
    sjf_vec3(&sjt_call35.normal);
    sjf_vertex_location_texture_normal(&sjt_call35);
    sjt_functionParam238 = &sjt_call35;
    sjf_array_vertex_location_texture_normal_initAt(&_return->vertices, sjt_functionParam237, sjt_functionParam238);
    sjt_functionParam239 = 23;
    sjt_call36.location.x = x1;
    sjt_call36.location.y = y1;
    sjt_call36.location.z = z0;
    sjf_vec3(&sjt_call36.location);
    sjt_call36.texture.x = s1;
    sjt_call36.texture.y = t0;
    sjf_vec2(&sjt_call36.texture);
    sjt_call36.normal.x = 0.0f;
    sjt_call36.normal.y = 1.0f;
    sjt_call36.normal.z = 0.0f;
    sjf_vec3(&sjt_call36.normal);
    sjf_vertex_location_texture_normal(&sjt_call36);
    sjt_functionParam240 = &sjt_call36;
    sjf_array_vertex_location_texture_normal_initAt(&_return->vertices, sjt_functionParam239, sjt_functionParam240);
    sjf_vertexBuffer_vertex_location_texture_normal(_return);

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
    sjf_vertex_location_texture_normal_destroy(&sjt_call34);
    sjf_vertex_location_texture_normal_destroy(&sjt_call35);
    sjf_vertex_location_texture_normal_destroy(&sjt_call36);
}

void sjf_cubeVertexBuffer_heap(float x0, float x1, float y0, float y1, float z0, float z1, float s0, float s1, float t0, float t1, sjs_vertexBuffer_vertex_location_texture_normal_heap** _return) {
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
    sjs_vertex_location_texture_normal sjt_call58;
    sjs_vertex_location_texture_normal sjt_call59;
    sjs_vertex_location_texture_normal sjt_call60;
    int32_t sjt_cast19;
    int32_t sjt_cast20;
    int32_t sjt_functionParam241;
    int32_t sjt_functionParam242;
    int32_t sjt_functionParam243;
    int32_t sjt_functionParam244;
    int32_t sjt_functionParam245;
    int32_t sjt_functionParam246;
    int32_t sjt_functionParam247;
    int32_t sjt_functionParam248;
    int32_t sjt_functionParam249;
    int32_t sjt_functionParam250;
    int32_t sjt_functionParam251;
    int32_t sjt_functionParam252;
    int32_t sjt_functionParam253;
    int32_t sjt_functionParam254;
    int32_t sjt_functionParam255;
    int32_t sjt_functionParam256;
    int32_t sjt_functionParam257;
    int32_t sjt_functionParam258;
    int32_t sjt_functionParam259;
    int32_t sjt_functionParam260;
    int32_t sjt_functionParam261;
    int32_t sjt_functionParam262;
    int32_t sjt_functionParam263;
    int32_t sjt_functionParam264;
    int32_t sjt_functionParam265;
    int32_t sjt_functionParam266;
    int32_t sjt_functionParam267;
    int32_t sjt_functionParam268;
    int32_t sjt_functionParam269;
    int32_t sjt_functionParam270;
    int32_t sjt_functionParam271;
    int32_t sjt_functionParam272;
    int32_t sjt_functionParam273;
    int32_t sjt_functionParam274;
    int32_t sjt_functionParam275;
    int32_t sjt_functionParam276;
    int32_t sjt_functionParam277;
    int32_t sjt_functionParam278;
    int32_t sjt_functionParam279;
    int32_t sjt_functionParam280;
    int32_t sjt_functionParam281;
    int32_t sjt_functionParam282;
    int32_t sjt_functionParam283;
    int32_t sjt_functionParam284;
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
    sjs_vertex_location_texture_normal* sjt_functionParam314;
    int32_t sjt_functionParam315;
    sjs_vertex_location_texture_normal* sjt_functionParam316;
    int32_t sjt_functionParam317;
    sjs_vertex_location_texture_normal* sjt_functionParam318;
    int32_t sjt_functionParam319;
    sjs_vertex_location_texture_normal* sjt_functionParam320;
    int32_t sjt_functionParam321;
    sjs_vertex_location_texture_normal* sjt_functionParam322;
    int32_t sjt_functionParam323;
    sjs_vertex_location_texture_normal* sjt_functionParam324;
    int32_t sjt_functionParam325;
    sjs_vertex_location_texture_normal* sjt_functionParam326;
    int32_t sjt_functionParam327;
    sjs_vertex_location_texture_normal* sjt_functionParam328;
    int32_t sjt_functionParam329;
    sjs_vertex_location_texture_normal* sjt_functionParam330;
    int32_t sjt_functionParam331;
    sjs_vertex_location_texture_normal* sjt_functionParam332;
    int32_t sjt_functionParam333;
    sjs_vertex_location_texture_normal* sjt_functionParam334;
    int32_t sjt_functionParam335;
    sjs_vertex_location_texture_normal* sjt_functionParam336;
    int32_t sjt_functionParam337;
    sjs_vertex_location_texture_normal* sjt_functionParam338;
    int32_t sjt_functionParam339;
    sjs_vertex_location_texture_normal* sjt_functionParam340;
    int32_t sjt_functionParam341;
    sjs_vertex_location_texture_normal* sjt_functionParam342;
    int32_t sjt_functionParam343;
    sjs_vertex_location_texture_normal* sjt_functionParam344;
    int32_t sjt_functionParam345;
    sjs_vertex_location_texture_normal* sjt_functionParam346;
    int32_t sjt_functionParam347;
    sjs_vertex_location_texture_normal* sjt_functionParam348;
    int32_t sjt_functionParam349;
    sjs_vertex_location_texture_normal* sjt_functionParam350;
    int32_t sjt_functionParam351;
    sjs_vertex_location_texture_normal* sjt_functionParam352;
    int32_t sjt_functionParam353;
    sjs_vertex_location_texture_normal* sjt_functionParam354;
    int32_t sjt_functionParam355;
    sjs_vertex_location_texture_normal* sjt_functionParam356;
    int32_t sjt_functionParam357;
    sjs_vertex_location_texture_normal* sjt_functionParam358;
    int32_t sjt_functionParam359;
    sjs_vertex_location_texture_normal* sjt_functionParam360;

    (*_return) = (sjs_vertexBuffer_vertex_location_texture_normal_heap*)malloc(sizeof(sjs_vertexBuffer_vertex_location_texture_normal_heap));
    (*_return)->_refCount = 1;
    sjf_string_copy(&(*_return)->format, &sjv_vertex_location_texture_normal_format);
    (*_return)->indices.size = 36;
    sjt_cast19 = 0;
    (*_return)->indices.data = (uintptr_t)sjt_cast19;
    (*_return)->indices._isGlobal = false;
    sjf_array_i32(&(*_return)->indices);
    sjt_functionParam241 = 0;
    sjt_functionParam242 = 0;
    sjf_array_i32_initAt(&(*_return)->indices, sjt_functionParam241, sjt_functionParam242);
    sjt_functionParam243 = 1;
    sjt_functionParam244 = 1;
    sjf_array_i32_initAt(&(*_return)->indices, sjt_functionParam243, sjt_functionParam244);
    sjt_functionParam245 = 2;
    sjt_functionParam246 = 2;
    sjf_array_i32_initAt(&(*_return)->indices, sjt_functionParam245, sjt_functionParam246);
    sjt_functionParam247 = 3;
    sjt_functionParam248 = 0;
    sjf_array_i32_initAt(&(*_return)->indices, sjt_functionParam247, sjt_functionParam248);
    sjt_functionParam249 = 4;
    sjt_functionParam250 = 2;
    sjf_array_i32_initAt(&(*_return)->indices, sjt_functionParam249, sjt_functionParam250);
    sjt_functionParam251 = 5;
    sjt_functionParam252 = 3;
    sjf_array_i32_initAt(&(*_return)->indices, sjt_functionParam251, sjt_functionParam252);
    sjt_functionParam253 = 6;
    sjt_functionParam254 = 4;
    sjf_array_i32_initAt(&(*_return)->indices, sjt_functionParam253, sjt_functionParam254);
    sjt_functionParam255 = 7;
    sjt_functionParam256 = 5;
    sjf_array_i32_initAt(&(*_return)->indices, sjt_functionParam255, sjt_functionParam256);
    sjt_functionParam257 = 8;
    sjt_functionParam258 = 6;
    sjf_array_i32_initAt(&(*_return)->indices, sjt_functionParam257, sjt_functionParam258);
    sjt_functionParam259 = 9;
    sjt_functionParam260 = 4;
    sjf_array_i32_initAt(&(*_return)->indices, sjt_functionParam259, sjt_functionParam260);
    sjt_functionParam261 = 10;
    sjt_functionParam262 = 6;
    sjf_array_i32_initAt(&(*_return)->indices, sjt_functionParam261, sjt_functionParam262);
    sjt_functionParam263 = 11;
    sjt_functionParam264 = 7;
    sjf_array_i32_initAt(&(*_return)->indices, sjt_functionParam263, sjt_functionParam264);
    sjt_functionParam265 = 12;
    sjt_functionParam266 = 8;
    sjf_array_i32_initAt(&(*_return)->indices, sjt_functionParam265, sjt_functionParam266);
    sjt_functionParam267 = 13;
    sjt_functionParam268 = 9;
    sjf_array_i32_initAt(&(*_return)->indices, sjt_functionParam267, sjt_functionParam268);
    sjt_functionParam269 = 14;
    sjt_functionParam270 = 10;
    sjf_array_i32_initAt(&(*_return)->indices, sjt_functionParam269, sjt_functionParam270);
    sjt_functionParam271 = 15;
    sjt_functionParam272 = 8;
    sjf_array_i32_initAt(&(*_return)->indices, sjt_functionParam271, sjt_functionParam272);
    sjt_functionParam273 = 16;
    sjt_functionParam274 = 10;
    sjf_array_i32_initAt(&(*_return)->indices, sjt_functionParam273, sjt_functionParam274);
    sjt_functionParam275 = 17;
    sjt_functionParam276 = 11;
    sjf_array_i32_initAt(&(*_return)->indices, sjt_functionParam275, sjt_functionParam276);
    sjt_functionParam277 = 18;
    sjt_functionParam278 = 12;
    sjf_array_i32_initAt(&(*_return)->indices, sjt_functionParam277, sjt_functionParam278);
    sjt_functionParam279 = 19;
    sjt_functionParam280 = 13;
    sjf_array_i32_initAt(&(*_return)->indices, sjt_functionParam279, sjt_functionParam280);
    sjt_functionParam281 = 20;
    sjt_functionParam282 = 14;
    sjf_array_i32_initAt(&(*_return)->indices, sjt_functionParam281, sjt_functionParam282);
    sjt_functionParam283 = 21;
    sjt_functionParam284 = 12;
    sjf_array_i32_initAt(&(*_return)->indices, sjt_functionParam283, sjt_functionParam284);
    sjt_functionParam285 = 22;
    sjt_functionParam286 = 14;
    sjf_array_i32_initAt(&(*_return)->indices, sjt_functionParam285, sjt_functionParam286);
    sjt_functionParam287 = 23;
    sjt_functionParam288 = 15;
    sjf_array_i32_initAt(&(*_return)->indices, sjt_functionParam287, sjt_functionParam288);
    sjt_functionParam289 = 24;
    sjt_functionParam290 = 16;
    sjf_array_i32_initAt(&(*_return)->indices, sjt_functionParam289, sjt_functionParam290);
    sjt_functionParam291 = 25;
    sjt_functionParam292 = 17;
    sjf_array_i32_initAt(&(*_return)->indices, sjt_functionParam291, sjt_functionParam292);
    sjt_functionParam293 = 26;
    sjt_functionParam294 = 18;
    sjf_array_i32_initAt(&(*_return)->indices, sjt_functionParam293, sjt_functionParam294);
    sjt_functionParam295 = 27;
    sjt_functionParam296 = 16;
    sjf_array_i32_initAt(&(*_return)->indices, sjt_functionParam295, sjt_functionParam296);
    sjt_functionParam297 = 28;
    sjt_functionParam298 = 18;
    sjf_array_i32_initAt(&(*_return)->indices, sjt_functionParam297, sjt_functionParam298);
    sjt_functionParam299 = 29;
    sjt_functionParam300 = 19;
    sjf_array_i32_initAt(&(*_return)->indices, sjt_functionParam299, sjt_functionParam300);
    sjt_functionParam301 = 30;
    sjt_functionParam302 = 20;
    sjf_array_i32_initAt(&(*_return)->indices, sjt_functionParam301, sjt_functionParam302);
    sjt_functionParam303 = 31;
    sjt_functionParam304 = 21;
    sjf_array_i32_initAt(&(*_return)->indices, sjt_functionParam303, sjt_functionParam304);
    sjt_functionParam305 = 32;
    sjt_functionParam306 = 22;
    sjf_array_i32_initAt(&(*_return)->indices, sjt_functionParam305, sjt_functionParam306);
    sjt_functionParam307 = 33;
    sjt_functionParam308 = 20;
    sjf_array_i32_initAt(&(*_return)->indices, sjt_functionParam307, sjt_functionParam308);
    sjt_functionParam309 = 34;
    sjt_functionParam310 = 22;
    sjf_array_i32_initAt(&(*_return)->indices, sjt_functionParam309, sjt_functionParam310);
    sjt_functionParam311 = 35;
    sjt_functionParam312 = 23;
    sjf_array_i32_initAt(&(*_return)->indices, sjt_functionParam311, sjt_functionParam312);
    (*_return)->vertices.size = 24;
    sjt_cast20 = 0;
    (*_return)->vertices.data = (uintptr_t)sjt_cast20;
    (*_return)->vertices._isGlobal = false;
    sjf_array_vertex_location_texture_normal(&(*_return)->vertices);
    sjt_functionParam313 = 0;
    sjt_call37.location.x = x0;
    sjt_call37.location.y = y0;
    sjt_call37.location.z = z0;
    sjf_vec3(&sjt_call37.location);
    sjt_call37.texture.x = s0;
    sjt_call37.texture.y = t0;
    sjf_vec2(&sjt_call37.texture);
    sjt_call37.normal.x = 0.0f;
    sjt_call37.normal.y = 0.0f;
    sjt_call37.normal.z = -1.0f;
    sjf_vec3(&sjt_call37.normal);
    sjf_vertex_location_texture_normal(&sjt_call37);
    sjt_functionParam314 = &sjt_call37;
    sjf_array_vertex_location_texture_normal_initAt(&(*_return)->vertices, sjt_functionParam313, sjt_functionParam314);
    sjt_functionParam315 = 1;
    sjt_call38.location.x = x0;
    sjt_call38.location.y = y1;
    sjt_call38.location.z = z0;
    sjf_vec3(&sjt_call38.location);
    sjt_call38.texture.x = s0;
    sjt_call38.texture.y = t1;
    sjf_vec2(&sjt_call38.texture);
    sjt_call38.normal.x = 0.0f;
    sjt_call38.normal.y = 0.0f;
    sjt_call38.normal.z = -1.0f;
    sjf_vec3(&sjt_call38.normal);
    sjf_vertex_location_texture_normal(&sjt_call38);
    sjt_functionParam316 = &sjt_call38;
    sjf_array_vertex_location_texture_normal_initAt(&(*_return)->vertices, sjt_functionParam315, sjt_functionParam316);
    sjt_functionParam317 = 2;
    sjt_call39.location.x = x1;
    sjt_call39.location.y = y1;
    sjt_call39.location.z = z0;
    sjf_vec3(&sjt_call39.location);
    sjt_call39.texture.x = s1;
    sjt_call39.texture.y = t1;
    sjf_vec2(&sjt_call39.texture);
    sjt_call39.normal.x = 0.0f;
    sjt_call39.normal.y = 0.0f;
    sjt_call39.normal.z = -1.0f;
    sjf_vec3(&sjt_call39.normal);
    sjf_vertex_location_texture_normal(&sjt_call39);
    sjt_functionParam318 = &sjt_call39;
    sjf_array_vertex_location_texture_normal_initAt(&(*_return)->vertices, sjt_functionParam317, sjt_functionParam318);
    sjt_functionParam319 = 3;
    sjt_call40.location.x = x1;
    sjt_call40.location.y = y0;
    sjt_call40.location.z = z0;
    sjf_vec3(&sjt_call40.location);
    sjt_call40.texture.x = s1;
    sjt_call40.texture.y = t0;
    sjf_vec2(&sjt_call40.texture);
    sjt_call40.normal.x = 0.0f;
    sjt_call40.normal.y = 0.0f;
    sjt_call40.normal.z = -1.0f;
    sjf_vec3(&sjt_call40.normal);
    sjf_vertex_location_texture_normal(&sjt_call40);
    sjt_functionParam320 = &sjt_call40;
    sjf_array_vertex_location_texture_normal_initAt(&(*_return)->vertices, sjt_functionParam319, sjt_functionParam320);
    sjt_functionParam321 = 4;
    sjt_call41.location.x = x0;
    sjt_call41.location.y = y0;
    sjt_call41.location.z = z1;
    sjf_vec3(&sjt_call41.location);
    sjt_call41.texture.x = s0;
    sjt_call41.texture.y = t0;
    sjf_vec2(&sjt_call41.texture);
    sjt_call41.normal.x = 0.0f;
    sjt_call41.normal.y = 0.0f;
    sjt_call41.normal.z = 1.0f;
    sjf_vec3(&sjt_call41.normal);
    sjf_vertex_location_texture_normal(&sjt_call41);
    sjt_functionParam322 = &sjt_call41;
    sjf_array_vertex_location_texture_normal_initAt(&(*_return)->vertices, sjt_functionParam321, sjt_functionParam322);
    sjt_functionParam323 = 5;
    sjt_call42.location.x = x0;
    sjt_call42.location.y = y1;
    sjt_call42.location.z = z1;
    sjf_vec3(&sjt_call42.location);
    sjt_call42.texture.x = s0;
    sjt_call42.texture.y = t1;
    sjf_vec2(&sjt_call42.texture);
    sjt_call42.normal.x = 0.0f;
    sjt_call42.normal.y = 0.0f;
    sjt_call42.normal.z = 1.0f;
    sjf_vec3(&sjt_call42.normal);
    sjf_vertex_location_texture_normal(&sjt_call42);
    sjt_functionParam324 = &sjt_call42;
    sjf_array_vertex_location_texture_normal_initAt(&(*_return)->vertices, sjt_functionParam323, sjt_functionParam324);
    sjt_functionParam325 = 6;
    sjt_call43.location.x = x1;
    sjt_call43.location.y = y1;
    sjt_call43.location.z = z1;
    sjf_vec3(&sjt_call43.location);
    sjt_call43.texture.x = s1;
    sjt_call43.texture.y = t1;
    sjf_vec2(&sjt_call43.texture);
    sjt_call43.normal.x = 0.0f;
    sjt_call43.normal.y = 0.0f;
    sjt_call43.normal.z = 1.0f;
    sjf_vec3(&sjt_call43.normal);
    sjf_vertex_location_texture_normal(&sjt_call43);
    sjt_functionParam326 = &sjt_call43;
    sjf_array_vertex_location_texture_normal_initAt(&(*_return)->vertices, sjt_functionParam325, sjt_functionParam326);
    sjt_functionParam327 = 7;
    sjt_call44.location.x = x1;
    sjt_call44.location.y = y0;
    sjt_call44.location.z = z1;
    sjf_vec3(&sjt_call44.location);
    sjt_call44.texture.x = s1;
    sjt_call44.texture.y = t0;
    sjf_vec2(&sjt_call44.texture);
    sjt_call44.normal.x = 0.0f;
    sjt_call44.normal.y = 0.0f;
    sjt_call44.normal.z = 1.0f;
    sjf_vec3(&sjt_call44.normal);
    sjf_vertex_location_texture_normal(&sjt_call44);
    sjt_functionParam328 = &sjt_call44;
    sjf_array_vertex_location_texture_normal_initAt(&(*_return)->vertices, sjt_functionParam327, sjt_functionParam328);
    sjt_functionParam329 = 8;
    sjt_call45.location.x = x0;
    sjt_call45.location.y = y0;
    sjt_call45.location.z = z0;
    sjf_vec3(&sjt_call45.location);
    sjt_call45.texture.x = s0;
    sjt_call45.texture.y = t0;
    sjf_vec2(&sjt_call45.texture);
    sjt_call45.normal.x = -1.0f;
    sjt_call45.normal.y = 0.0f;
    sjt_call45.normal.z = 0.0f;
    sjf_vec3(&sjt_call45.normal);
    sjf_vertex_location_texture_normal(&sjt_call45);
    sjt_functionParam330 = &sjt_call45;
    sjf_array_vertex_location_texture_normal_initAt(&(*_return)->vertices, sjt_functionParam329, sjt_functionParam330);
    sjt_functionParam331 = 9;
    sjt_call46.location.x = x0;
    sjt_call46.location.y = y1;
    sjt_call46.location.z = z0;
    sjf_vec3(&sjt_call46.location);
    sjt_call46.texture.x = s0;
    sjt_call46.texture.y = t1;
    sjf_vec2(&sjt_call46.texture);
    sjt_call46.normal.x = -1.0f;
    sjt_call46.normal.y = 0.0f;
    sjt_call46.normal.z = 0.0f;
    sjf_vec3(&sjt_call46.normal);
    sjf_vertex_location_texture_normal(&sjt_call46);
    sjt_functionParam332 = &sjt_call46;
    sjf_array_vertex_location_texture_normal_initAt(&(*_return)->vertices, sjt_functionParam331, sjt_functionParam332);
    sjt_functionParam333 = 10;
    sjt_call47.location.x = x0;
    sjt_call47.location.y = y1;
    sjt_call47.location.z = z1;
    sjf_vec3(&sjt_call47.location);
    sjt_call47.texture.x = s1;
    sjt_call47.texture.y = t1;
    sjf_vec2(&sjt_call47.texture);
    sjt_call47.normal.x = -1.0f;
    sjt_call47.normal.y = 0.0f;
    sjt_call47.normal.z = 0.0f;
    sjf_vec3(&sjt_call47.normal);
    sjf_vertex_location_texture_normal(&sjt_call47);
    sjt_functionParam334 = &sjt_call47;
    sjf_array_vertex_location_texture_normal_initAt(&(*_return)->vertices, sjt_functionParam333, sjt_functionParam334);
    sjt_functionParam335 = 11;
    sjt_call48.location.x = x0;
    sjt_call48.location.y = y0;
    sjt_call48.location.z = z1;
    sjf_vec3(&sjt_call48.location);
    sjt_call48.texture.x = s1;
    sjt_call48.texture.y = t0;
    sjf_vec2(&sjt_call48.texture);
    sjt_call48.normal.x = -1.0f;
    sjt_call48.normal.y = 0.0f;
    sjt_call48.normal.z = 0.0f;
    sjf_vec3(&sjt_call48.normal);
    sjf_vertex_location_texture_normal(&sjt_call48);
    sjt_functionParam336 = &sjt_call48;
    sjf_array_vertex_location_texture_normal_initAt(&(*_return)->vertices, sjt_functionParam335, sjt_functionParam336);
    sjt_functionParam337 = 12;
    sjt_call49.location.x = x1;
    sjt_call49.location.y = y0;
    sjt_call49.location.z = z0;
    sjf_vec3(&sjt_call49.location);
    sjt_call49.texture.x = s0;
    sjt_call49.texture.y = t0;
    sjf_vec2(&sjt_call49.texture);
    sjt_call49.normal.x = 1.0f;
    sjt_call49.normal.y = 0.0f;
    sjt_call49.normal.z = 0.0f;
    sjf_vec3(&sjt_call49.normal);
    sjf_vertex_location_texture_normal(&sjt_call49);
    sjt_functionParam338 = &sjt_call49;
    sjf_array_vertex_location_texture_normal_initAt(&(*_return)->vertices, sjt_functionParam337, sjt_functionParam338);
    sjt_functionParam339 = 13;
    sjt_call50.location.x = x1;
    sjt_call50.location.y = y1;
    sjt_call50.location.z = z0;
    sjf_vec3(&sjt_call50.location);
    sjt_call50.texture.x = s0;
    sjt_call50.texture.y = t1;
    sjf_vec2(&sjt_call50.texture);
    sjt_call50.normal.x = 1.0f;
    sjt_call50.normal.y = 0.0f;
    sjt_call50.normal.z = 0.0f;
    sjf_vec3(&sjt_call50.normal);
    sjf_vertex_location_texture_normal(&sjt_call50);
    sjt_functionParam340 = &sjt_call50;
    sjf_array_vertex_location_texture_normal_initAt(&(*_return)->vertices, sjt_functionParam339, sjt_functionParam340);
    sjt_functionParam341 = 14;
    sjt_call51.location.x = x1;
    sjt_call51.location.y = y1;
    sjt_call51.location.z = z1;
    sjf_vec3(&sjt_call51.location);
    sjt_call51.texture.x = s1;
    sjt_call51.texture.y = t1;
    sjf_vec2(&sjt_call51.texture);
    sjt_call51.normal.x = 1.0f;
    sjt_call51.normal.y = 0.0f;
    sjt_call51.normal.z = 0.0f;
    sjf_vec3(&sjt_call51.normal);
    sjf_vertex_location_texture_normal(&sjt_call51);
    sjt_functionParam342 = &sjt_call51;
    sjf_array_vertex_location_texture_normal_initAt(&(*_return)->vertices, sjt_functionParam341, sjt_functionParam342);
    sjt_functionParam343 = 15;
    sjt_call52.location.x = x1;
    sjt_call52.location.y = y0;
    sjt_call52.location.z = z1;
    sjf_vec3(&sjt_call52.location);
    sjt_call52.texture.x = s1;
    sjt_call52.texture.y = t0;
    sjf_vec2(&sjt_call52.texture);
    sjt_call52.normal.x = 1.0f;
    sjt_call52.normal.y = 0.0f;
    sjt_call52.normal.z = 0.0f;
    sjf_vec3(&sjt_call52.normal);
    sjf_vertex_location_texture_normal(&sjt_call52);
    sjt_functionParam344 = &sjt_call52;
    sjf_array_vertex_location_texture_normal_initAt(&(*_return)->vertices, sjt_functionParam343, sjt_functionParam344);
    sjt_functionParam345 = 16;
    sjt_call53.location.x = x0;
    sjt_call53.location.y = y0;
    sjt_call53.location.z = z0;
    sjf_vec3(&sjt_call53.location);
    sjt_call53.texture.x = s0;
    sjt_call53.texture.y = t0;
    sjf_vec2(&sjt_call53.texture);
    sjt_call53.normal.x = 0.0f;
    sjt_call53.normal.y = -1.0f;
    sjt_call53.normal.z = 0.0f;
    sjf_vec3(&sjt_call53.normal);
    sjf_vertex_location_texture_normal(&sjt_call53);
    sjt_functionParam346 = &sjt_call53;
    sjf_array_vertex_location_texture_normal_initAt(&(*_return)->vertices, sjt_functionParam345, sjt_functionParam346);
    sjt_functionParam347 = 17;
    sjt_call54.location.x = x0;
    sjt_call54.location.y = y0;
    sjt_call54.location.z = z1;
    sjf_vec3(&sjt_call54.location);
    sjt_call54.texture.x = s0;
    sjt_call54.texture.y = t1;
    sjf_vec2(&sjt_call54.texture);
    sjt_call54.normal.x = 0.0f;
    sjt_call54.normal.y = -1.0f;
    sjt_call54.normal.z = 0.0f;
    sjf_vec3(&sjt_call54.normal);
    sjf_vertex_location_texture_normal(&sjt_call54);
    sjt_functionParam348 = &sjt_call54;
    sjf_array_vertex_location_texture_normal_initAt(&(*_return)->vertices, sjt_functionParam347, sjt_functionParam348);
    sjt_functionParam349 = 18;
    sjt_call55.location.x = x1;
    sjt_call55.location.y = y0;
    sjt_call55.location.z = z1;
    sjf_vec3(&sjt_call55.location);
    sjt_call55.texture.x = s1;
    sjt_call55.texture.y = t1;
    sjf_vec2(&sjt_call55.texture);
    sjt_call55.normal.x = 0.0f;
    sjt_call55.normal.y = -1.0f;
    sjt_call55.normal.z = 0.0f;
    sjf_vec3(&sjt_call55.normal);
    sjf_vertex_location_texture_normal(&sjt_call55);
    sjt_functionParam350 = &sjt_call55;
    sjf_array_vertex_location_texture_normal_initAt(&(*_return)->vertices, sjt_functionParam349, sjt_functionParam350);
    sjt_functionParam351 = 19;
    sjt_call56.location.x = x1;
    sjt_call56.location.y = y0;
    sjt_call56.location.z = z0;
    sjf_vec3(&sjt_call56.location);
    sjt_call56.texture.x = s1;
    sjt_call56.texture.y = t0;
    sjf_vec2(&sjt_call56.texture);
    sjt_call56.normal.x = 0.0f;
    sjt_call56.normal.y = -1.0f;
    sjt_call56.normal.z = 0.0f;
    sjf_vec3(&sjt_call56.normal);
    sjf_vertex_location_texture_normal(&sjt_call56);
    sjt_functionParam352 = &sjt_call56;
    sjf_array_vertex_location_texture_normal_initAt(&(*_return)->vertices, sjt_functionParam351, sjt_functionParam352);
    sjt_functionParam353 = 20;
    sjt_call57.location.x = x0;
    sjt_call57.location.y = y1;
    sjt_call57.location.z = z0;
    sjf_vec3(&sjt_call57.location);
    sjt_call57.texture.x = s0;
    sjt_call57.texture.y = t0;
    sjf_vec2(&sjt_call57.texture);
    sjt_call57.normal.x = 0.0f;
    sjt_call57.normal.y = 1.0f;
    sjt_call57.normal.z = 0.0f;
    sjf_vec3(&sjt_call57.normal);
    sjf_vertex_location_texture_normal(&sjt_call57);
    sjt_functionParam354 = &sjt_call57;
    sjf_array_vertex_location_texture_normal_initAt(&(*_return)->vertices, sjt_functionParam353, sjt_functionParam354);
    sjt_functionParam355 = 21;
    sjt_call58.location.x = x0;
    sjt_call58.location.y = y1;
    sjt_call58.location.z = z1;
    sjf_vec3(&sjt_call58.location);
    sjt_call58.texture.x = s0;
    sjt_call58.texture.y = t1;
    sjf_vec2(&sjt_call58.texture);
    sjt_call58.normal.x = 0.0f;
    sjt_call58.normal.y = 1.0f;
    sjt_call58.normal.z = 0.0f;
    sjf_vec3(&sjt_call58.normal);
    sjf_vertex_location_texture_normal(&sjt_call58);
    sjt_functionParam356 = &sjt_call58;
    sjf_array_vertex_location_texture_normal_initAt(&(*_return)->vertices, sjt_functionParam355, sjt_functionParam356);
    sjt_functionParam357 = 22;
    sjt_call59.location.x = x1;
    sjt_call59.location.y = y1;
    sjt_call59.location.z = z1;
    sjf_vec3(&sjt_call59.location);
    sjt_call59.texture.x = s1;
    sjt_call59.texture.y = t1;
    sjf_vec2(&sjt_call59.texture);
    sjt_call59.normal.x = 0.0f;
    sjt_call59.normal.y = 1.0f;
    sjt_call59.normal.z = 0.0f;
    sjf_vec3(&sjt_call59.normal);
    sjf_vertex_location_texture_normal(&sjt_call59);
    sjt_functionParam358 = &sjt_call59;
    sjf_array_vertex_location_texture_normal_initAt(&(*_return)->vertices, sjt_functionParam357, sjt_functionParam358);
    sjt_functionParam359 = 23;
    sjt_call60.location.x = x1;
    sjt_call60.location.y = y1;
    sjt_call60.location.z = z0;
    sjf_vec3(&sjt_call60.location);
    sjt_call60.texture.x = s1;
    sjt_call60.texture.y = t0;
    sjf_vec2(&sjt_call60.texture);
    sjt_call60.normal.x = 0.0f;
    sjt_call60.normal.y = 1.0f;
    sjt_call60.normal.z = 0.0f;
    sjf_vec3(&sjt_call60.normal);
    sjf_vertex_location_texture_normal(&sjt_call60);
    sjt_functionParam360 = &sjt_call60;
    sjf_array_vertex_location_texture_normal_initAt(&(*_return)->vertices, sjt_functionParam359, sjt_functionParam360);
    sjf_vertexBuffer_vertex_location_texture_normal_heap((*_return));

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
    sjf_vertex_location_texture_normal_destroy(&sjt_call58);
    sjf_vertex_location_texture_normal_destroy(&sjt_call59);
    sjf_vertex_location_texture_normal_destroy(&sjt_call60);
}

void sjf_f32_cos(float v, float* _return) {
    float sjv_result;

    sjv_result = 0.0f;
    sjv_result = cosf(v);
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
    sjf_array_heap_element_copy(&_this->children, &_from->children);
    sjf_rect_copy(&_this->_rect, &_from->_rect);
}

void sjf_fillElement_destroy(sjs_fillElement* _this) {
}

void sjf_fillElement_fireMouseEvent(sjs_fillElement* _parent, sjs_point* point, int32_t eventId) {
    int32_t i;
    sjs_array_heap_element* sjt_dot11;
    int32_t sjt_forEnd3;
    int32_t sjt_forStart3;

    sjt_forStart3 = 0;
    i = sjt_forStart3;
    sjt_dot11 = &(_parent)->children;
    sjt_forEnd3 = (sjt_dot11)->size;
    while (i < sjt_forEnd3) {
        sjs_array_heap_element* sjt_dot12;
        sji_element* sjt_dot13;
        int32_t sjt_functionParam3;
        sjs_point* sjt_interfaceParam3;
        int32_t sjt_interfaceParam4;
        sji_element* sjv_child;

        sjt_dot12 = &(_parent)->children;
        sjt_functionParam3 = i;
        sjf_array_heap_element_getAt_heap(sjt_dot12, sjt_functionParam3, &sjv_child);
        sjt_dot13 = sjv_child;
        sjt_interfaceParam3 = point;
        sjt_interfaceParam4 = eventId;
        sjt_dot13->fireMouseEvent((void*)(((char*)sjt_dot13->_parent) + sizeof(intptr_t)), sjt_interfaceParam3, sjt_interfaceParam4);
        i++;

        sjv_child->_refCount--;
        if (sjv_child->_refCount <= 0) {
            sji_element_destroy(sjv_child);
        }
    }
}

void sjf_fillElement_getChildren(sjs_fillElement* _parent, sjs_array_heap_element** _return) {
    sjs_array_heap_element* sjt_value1;
    sjs_array_heap_element* sjv_a;

    sjv_a = &(_parent)->children;
    sjt_value1 = sjv_a;
    (*_return) = sjt_value1;
}

void sjf_fillElement_getRect(sjs_fillElement* _parent, sjs_rect** _return) {
    (*_return) = &(_parent)->_rect;
}

void sjf_fillElement_getSize(sjs_fillElement* _parent, sjs_size* maxSize, sjs_size* _return) {
    sjs_size* sjt_dot1;
    sjs_size* sjt_dot2;

    sjt_dot1 = maxSize;
    _return->w = (sjt_dot1)->w;
    sjt_dot2 = maxSize;
    _return->h = (sjt_dot2)->h;
    sjf_size(_return);
}

void sjf_fillElement_getSize_heap(sjs_fillElement* _parent, sjs_size* maxSize, sjs_size_heap** _return) {
    sjs_size* sjt_dot3;
    sjs_size* sjt_dot4;

    (*_return) = (sjs_size_heap*)malloc(sizeof(sjs_size_heap));
    (*_return)->_refCount = 1;
    sjt_dot3 = maxSize;
    (*_return)->w = (sjt_dot3)->w;
    sjt_dot4 = maxSize;
    (*_return)->h = (sjt_dot4)->h;
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
    sjs_array_heap_element* sjt_dot8;
    int32_t sjt_forEnd2;
    int32_t sjt_forStart2;

    sjt_forStart2 = 0;
    i = sjt_forStart2;
    sjt_dot8 = &(_parent)->children;
    sjt_forEnd2 = (sjt_dot8)->size;
    while (i < sjt_forEnd2) {
        sji_element* sjt_dot10;
        sjs_array_heap_element* sjt_dot9;
        int32_t sjt_functionParam2;
        sjs_scene2d* sjt_interfaceParam2;
        sji_element* sjv_child;

        sjt_dot9 = &(_parent)->children;
        sjt_functionParam2 = i;
        sjf_array_heap_element_getAt_heap(sjt_dot9, sjt_functionParam2, &sjv_child);
        sjt_dot10 = sjv_child;
        sjt_interfaceParam2 = scene;
        sjt_dot10->render((void*)(((char*)sjt_dot10->_parent) + sizeof(intptr_t)), sjt_interfaceParam2);
        i++;

        sjv_child->_refCount--;
        if (sjv_child->_refCount <= 0) {
            sji_element_destroy(sjv_child);
        }
    }
}

void sjf_fillElement_setRect(sjs_fillElement* _parent, sjs_rect* rect_) {
    int32_t i;
    sjs_array_heap_element* sjt_dot5;
    int32_t sjt_forEnd1;
    int32_t sjt_forStart1;

    sjf_rect_copy(&_parent->_rect, rect_);
    sjt_forStart1 = 0;
    i = sjt_forStart1;
    sjt_dot5 = &(_parent)->children;
    sjt_forEnd1 = (sjt_dot5)->size;
    while (i < sjt_forEnd1) {
        sjs_array_heap_element* sjt_dot6;
        sji_element* sjt_dot7;
        int32_t sjt_functionParam1;
        sjs_rect* sjt_interfaceParam1;
        sji_element* sjv_child;

        sjt_dot6 = &(_parent)->children;
        sjt_functionParam1 = i;
        sjf_array_heap_element_getAt_heap(sjt_dot6, sjt_functionParam1, &sjv_child);
        sjt_dot7 = sjv_child;
        sjt_interfaceParam1 = &(_parent)->_rect;
        sjt_dot7->setRect((void*)(((char*)sjt_dot7->_parent) + sizeof(intptr_t)), sjt_interfaceParam1);
        i++;

        sjv_child->_refCount--;
        if (sjv_child->_refCount <= 0) {
            sji_element_destroy(sjv_child);
        }
    }
}

void sjf_frameBuffer(sjs_frameBuffer* _this) {
    glGenFramebuffers(1, &_this->frameBufferId);
    glGenTextures(1, &_this->textureId);
    glBindFramebuffer(GL_FRAMEBUFFER, _this->frameBufferId);
    glBindTexture(GL_TEXTURE_2D, _this->textureId);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, _this->size.w, _this->size.h, 0, GL_RGBA, GL_UNSIGNED_BYTE, NULL);
    glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, _this->textureId, 0);
    glGenRenderbuffers(1, &_this->depthBufferId);
    glBindRenderbuffer(GL_RENDERBUFFER, _this->depthBufferId);
    glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH_COMPONENT16, _this->size.w, _this->size.h);
    glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_RENDERBUFFER, _this->depthBufferId);
    GLenum status = glCheckFramebufferStatus(GL_FRAMEBUFFER);
    if(status != GL_FRAMEBUFFER_COMPLETE) {
        printf("Framebuffer status: %x", (int)status);
    }
}

void sjf_frameBuffer_copy(sjs_frameBuffer* _this, sjs_frameBuffer* _from) {
    sjf_size_copy(&_this->size, &_from->size);
    _this->frameBufferId = _from->frameBufferId;
    _retainGLid(_this->frameBufferId);
    _this->textureId = _from->textureId;
    _retainGLid(_this->textureId);
    _this->depthBufferId = _from->depthBufferId;
    _retainGLid(_this->depthBufferId);
}

void sjf_frameBuffer_destroy(sjs_frameBuffer* _this) {
    if (_releaseGLid(_this->frameBufferId)) {
        glDeleteFramebuffers(1, &_this->frameBufferId);
    }
    if (_releaseGLid(_this->textureId)) {
        glDeleteTextures(1, &_this->textureId);
    }
    if (_releaseGLid(_this->depthBufferId)) {
        glDeleteRenderbuffers(1, &_this->depthBufferId);
    }
}

void sjf_frameBuffer_heap(sjs_frameBuffer_heap* _this) {
    glGenFramebuffers(1, &_this->frameBufferId);
    glGenTextures(1, &_this->textureId);
    glBindFramebuffer(GL_FRAMEBUFFER, _this->frameBufferId);
    glBindTexture(GL_TEXTURE_2D, _this->textureId);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, _this->size.w, _this->size.h, 0, GL_RGBA, GL_UNSIGNED_BYTE, NULL);
    glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, _this->textureId, 0);
    glGenRenderbuffers(1, &_this->depthBufferId);
    glBindRenderbuffer(GL_RENDERBUFFER, _this->depthBufferId);
    glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH_COMPONENT16, _this->size.w, _this->size.h);
    glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_RENDERBUFFER, _this->depthBufferId);
    GLenum status = glCheckFramebufferStatus(GL_FRAMEBUFFER);
    if(status != GL_FRAMEBUFFER_COMPLETE) {
        printf("Framebuffer status: %x", (int)status);
    }
}

void sjf_image(sjs_image* _this) {
    bool sjt_and10;
    bool sjt_and9;
    int32_t sjt_compare13;
    int32_t sjt_compare14;
    int32_t sjt_compare15;
    int32_t sjt_compare16;
    sjs_rect* sjt_dot244;
    sjs_rect* sjt_dot245;
    bool sjt_ifElse3;

    sjt_dot244 = &_this->rect;
    sjt_compare13 = (sjt_dot244)->w;
    sjt_compare14 = 0;
    sjt_and9 = sjt_compare13 == sjt_compare14;
    sjt_dot245 = &_this->rect;
    sjt_compare15 = (sjt_dot245)->h;
    sjt_compare16 = 0;
    sjt_and10 = sjt_compare15 == sjt_compare16;
    sjt_ifElse3 = sjt_and9 && sjt_and10;
    if (sjt_ifElse3) {
        sjs_texture* sjt_dot246;
        sjs_size* sjt_dot251;
        sjs_size* sjt_dot252;
        sjs_size sjv_size;

        sjt_dot246 = &_this->texture;
        sjf_texture_getSize(sjt_dot246, &sjv_size);
        _this->rect.x = 0;
        _this->rect.y = 0;
        sjt_dot251 = &sjv_size;
        _this->rect.w = (sjt_dot251)->w;
        sjt_dot252 = &sjv_size;
        _this->rect.h = (sjt_dot252)->h;
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

void sjf_imageElement_fireMouseEvent(sjs_imageElement* _parent, sjs_point* point, int32_t eventId) {
}

void sjf_imageElement_getChildren(sjs_imageElement* _parent, sjs_array_heap_element** _return) {
    (*_return) = 0;
}

void sjf_imageElement_getRect(sjs_imageElement* _parent, sjs_rect** _return) {
    (*_return) = &(_parent)->_rect;
}

void sjf_imageElement_getSize(sjs_imageElement* _parent, sjs_size* maxSize, sjs_size* _return) {
    sjs_size* sjt_dot258;
    sjs_size* sjt_dot259;

    sjt_dot258 = maxSize;
    _return->w = (sjt_dot258)->w;
    sjt_dot259 = maxSize;
    _return->h = (sjt_dot259)->h;
    sjf_size(_return);
}

void sjf_imageElement_getSize_heap(sjs_imageElement* _parent, sjs_size* maxSize, sjs_size_heap** _return) {
    sjs_size* sjt_dot260;
    sjs_size* sjt_dot261;

    (*_return) = (sjs_size_heap*)malloc(sizeof(sjs_size_heap));
    (*_return)->_refCount = 1;
    sjt_dot260 = maxSize;
    (*_return)->w = (sjt_dot260)->w;
    sjt_dot261 = maxSize;
    (*_return)->h = (sjt_dot261)->h;
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
    bool result4;
    bool sjt_ifElse6;
    bool sjt_ifElse7;
    sjs_imageRenderer_heap* sjt_isEmpty1;
    sjs_imageRenderer_heap* sjt_isEmpty2;
    bool sjt_not4;

    sjt_isEmpty1 = (_parent)->_imageRenderer;
    if (sjt_isEmpty1 != 0) {
        sjt_isEmpty1->_refCount++;
    }

    sjt_ifElse6 = (sjt_isEmpty1 == 0);
    if (sjt_ifElse6) {
        sjs_rect* sjt_dot263;
        sjs_margin* sjt_functionParam112;
        sjs_imageRenderer_heap* sjt_value2;

        sjt_value2 = (sjs_imageRenderer_heap*)malloc(sizeof(sjs_imageRenderer_heap));
        sjt_value2->_refCount = 1;
        sjt_dot263 = &(_parent)->_rect;
        sjt_functionParam112 = &(_parent)->_margin;
        sjf_rect_subtractMargin(sjt_dot263, sjt_functionParam112, &sjt_value2->rect);
        sjf_image_copy(&sjt_value2->image, &(_parent)->image);
        sjf_imageRenderer_heap(sjt_value2);
        if (_parent->_imageRenderer != 0) {
            _parent->_imageRenderer->_refCount--;
            if (_parent->_imageRenderer->_refCount <= 0) {
                sjf_imageRenderer_destroy((sjs_imageRenderer*)(((char*)_parent->_imageRenderer) + sizeof(intptr_t)));
            }
        }

        _parent->_imageRenderer = sjt_value2;
        if (_parent->_imageRenderer != 0) {
            _parent->_imageRenderer->_refCount++;
        }

        sjt_value2->_refCount--;
        if (sjt_value2->_refCount <= 0) {
            sjf_imageRenderer_destroy((sjs_imageRenderer*)(((char*)sjt_value2) + sizeof(intptr_t)));
        }
    }

    sjt_isEmpty2 = (_parent)->_imageRenderer;
    if (sjt_isEmpty2 != 0) {
        sjt_isEmpty2->_refCount++;
    }

    sjt_not4 = (sjt_isEmpty2 == 0);
    result4 = !sjt_not4;
    sjt_ifElse7 = result4;
    if (sjt_ifElse7) {
        sjs_imageRenderer* sjt_dot276;
        sjs_scene2d* sjt_functionParam113;
        sjs_imageRenderer_heap* sjt_getValue1;

        sjt_getValue1 = (_parent)->_imageRenderer;
        if (sjt_getValue1 != 0) {
            sjt_getValue1->_refCount++;
        }

        sjt_dot276 = (sjs_imageRenderer*)(((char*)sjt_getValue1) + sizeof(intptr_t));
        sjt_functionParam113 = scene;
        sjf_imageRenderer_render(sjt_dot276, sjt_functionParam113);

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
    bool result3;
    sjs_rect* sjt_dot262;
    sjs_rect* sjt_functionParam111;
    bool sjt_ifElse5;
    bool sjt_not3;

    sjt_dot262 = &(_parent)->_rect;
    sjt_functionParam111 = rect_;
    sjf_rect_isEqual(sjt_dot262, sjt_functionParam111, &sjt_not3);
    result3 = !sjt_not3;
    sjt_ifElse5 = result3;
    if (sjt_ifElse5) {
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

void sjf_imageRenderer_render(sjs_imageRenderer* _parent, sjs_scene2d* scene) {
    glBindTexture(GL_TEXTURE_2D, _parent->image.texture.id);
    glUseProgram(sjv_imageShader.id);
    glUniform1i(glGetUniformLocation(sjv_imageShader.id, "texture" ), 0 );
    glUniformMatrix4fv(glGetUniformLocation(sjv_imageShader.id, "model" ), 1, 0, (GLfloat*)&scene->model);
    glUniformMatrix4fv(glGetUniformLocation(sjv_imageShader.id, "view" ), 1, 0, (GLfloat*)&scene->view);
    glUniformMatrix4fv(glGetUniformLocation(sjv_imageShader.id, "projection" ), 1, 0, (GLfloat*)&scene->projection);
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
    sjs_rect* dotTemp5;
    sjs_rect* dotTemp6;
    bool sjt_and11;
    bool sjt_and12;
    int32_t sjt_compare17;
    int32_t sjt_compare18;
    int32_t sjt_compare19;
    int32_t sjt_compare20;
    sjs_rect* sjt_dot253;
    sjs_rect* sjt_dot254;
    bool sjt_ifElse4;

    dotTemp5 = &_this->rect;
    sjt_dot253 = dotTemp5;
    sjt_compare17 = (sjt_dot253)->w;
    sjt_compare18 = 0;
    sjt_and11 = sjt_compare17 == sjt_compare18;
    dotTemp6 = &_this->rect;
    sjt_dot254 = dotTemp6;
    sjt_compare19 = (sjt_dot254)->h;
    sjt_compare20 = 0;
    sjt_and12 = sjt_compare19 == sjt_compare20;
    sjt_ifElse4 = sjt_and11 && sjt_and12;
    if (sjt_ifElse4) {
        sjs_texture* dotTemp7;
        sjs_texture* sjt_dot255;
        sjs_size* sjt_dot256;
        sjs_size* sjt_dot257;
        sjs_size sjv_size;

        dotTemp7 = &_this->texture;
        sjt_dot255 = dotTemp7;
        sjf_texture_getSize(sjt_dot255, &sjv_size);
        _this->rect.x = 0;
        _this->rect.y = 0;
        sjt_dot256 = &sjv_size;
        _this->rect.w = (sjt_dot256)->w;
        sjt_dot257 = &sjv_size;
        _this->rect.h = (sjt_dot257)->h;
        sjf_rect(&_this->rect);

        sjf_size_destroy(&sjv_size);
    }
}

void sjf_mainLoop(void) {
    int32_t sjt_compare31;
    int32_t sjt_compare32;
    sjs_windowRenderer* sjt_dot297;
    sjs_scene2d* sjt_dot298;
    sjs_scene2d* sjt_dot299;
    sjs_size* sjt_dot300;
    sjs_size* sjt_dot301;
    sji_element* sjt_dot302;
    sji_element* sjt_dot303;
    sjs_windowRenderer* sjt_dot304;
    sjs_size* sjt_functionParam373;
    bool sjt_ifElse15;
    sjs_rect* sjt_interfaceParam10;
    sjs_scene2d* sjt_interfaceParam11;
    int32_t sjv_mouseEvent;
    sjs_rect sjv_rect;
    sjs_size sjv_size;
    int32_t sjv_x;
    int32_t sjv_y;

    sjt_dot297 = &sjv_rootWindowRenderer;
    sjf_windowRenderer_getSize(sjt_dot297, &sjv_size);
    sjt_dot298 = &sjv_rootScene;
    sjt_functionParam373 = &sjv_size;
    sjf_scene2d_setSize(sjt_dot298, sjt_functionParam373);
    sjt_dot299 = &sjv_rootScene;
    sjf_scene2d_clear(sjt_dot299);
    sjv_rect.x = 0;
    sjv_rect.y = 0;
    sjt_dot300 = &sjv_size;
    sjv_rect.w = (sjt_dot300)->w;
    sjt_dot301 = &sjv_size;
    sjv_rect.h = (sjt_dot301)->h;
    sjf_rect(&sjv_rect);
    sjt_dot302 = sjv_root;
    sjt_interfaceParam10 = &sjv_rect;
    sjt_dot302->setRect((void*)(((char*)sjt_dot302->_parent) + sizeof(intptr_t)), sjt_interfaceParam10);
    sjt_dot303 = sjv_root;
    sjt_interfaceParam11 = &sjv_rootScene;
    sjt_dot303->render((void*)(((char*)sjt_dot303->_parent) + sizeof(intptr_t)), sjt_interfaceParam11);
    sjt_dot304 = &sjv_rootWindowRenderer;
    sjf_windowRenderer_present(sjt_dot304);
    sjv_mouseEvent = -1;
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
            sjv_mouseEvent = sjv_mouseEvent_down;
            sjv_x = e.button.x;
            sjv_y = e.button.y;
            break;
            case SDL_MOUSEBUTTONUP:
            printf("SDL_MOUSEBUTTONUP\n");
            sjv_mouseEvent = sjv_mouseEvent_up;
            sjv_x = e.button.x;
            sjv_y = e.button.y;
            break;
            case SDL_MOUSEMOTION:
            printf("SDL_MOUSEMOTION\n");
            sjv_mouseEvent = sjv_mouseEvent_move;
            sjv_x = e.motion.x;
            sjv_y = e.motion.y;
            break;
        }
    }
    sjt_compare31 = sjv_mouseEvent;
    sjt_compare32 = -1;
    sjt_ifElse15 = sjt_compare31 != sjt_compare32;
    if (sjt_ifElse15) {
        sjs_point sjt_call61;
        sji_element* sjt_dot305;
        sjs_point* sjt_interfaceParam12;
        int32_t sjt_interfaceParam13;

        sjt_dot305 = sjv_root;
        sjt_call61.x = sjv_x;
        sjt_call61.y = sjv_y;
        sjf_point(&sjt_call61);
        sjt_interfaceParam12 = &sjt_call61;
        sjt_interfaceParam13 = sjv_mouseEvent;
        sjt_dot305->fireMouseEvent((void*)(((char*)sjt_dot305->_parent) + sizeof(intptr_t)), sjt_interfaceParam12, sjt_interfaceParam13);

        sjf_point_destroy(&sjt_call61);
    }

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

    sjt_math1545 = (_parent)->m03;
    sjt_math1546 = (_parent)->m12;
    sjt_math1543 = sjt_math1545 * sjt_math1546;
    sjt_math1544 = (_parent)->m21;
    sjt_math1541 = sjt_math1543 * sjt_math1544;
    sjt_math1542 = (_parent)->m30;
    sjt_math1539 = sjt_math1541 * sjt_math1542;
    sjt_math1551 = (_parent)->m02;
    sjt_math1552 = (_parent)->m13;
    sjt_math1549 = sjt_math1551 * sjt_math1552;
    sjt_math1550 = (_parent)->m21;
    sjt_math1547 = sjt_math1549 * sjt_math1550;
    sjt_math1548 = (_parent)->m30;
    sjt_math1540 = sjt_math1547 * sjt_math1548;
    sjt_math1537 = sjt_math1539 - sjt_math1540;
    sjt_math1557 = (_parent)->m03;
    sjt_math1558 = (_parent)->m11;
    sjt_math1555 = sjt_math1557 * sjt_math1558;
    sjt_math1556 = (_parent)->m22;
    sjt_math1553 = sjt_math1555 * sjt_math1556;
    sjt_math1554 = (_parent)->m30;
    sjt_math1538 = sjt_math1553 * sjt_math1554;
    sjt_math1535 = sjt_math1537 - sjt_math1538;
    sjt_math1563 = (_parent)->m01;
    sjt_math1564 = (_parent)->m13;
    sjt_math1561 = sjt_math1563 * sjt_math1564;
    sjt_math1562 = (_parent)->m22;
    sjt_math1559 = sjt_math1561 * sjt_math1562;
    sjt_math1560 = (_parent)->m30;
    sjt_math1536 = sjt_math1559 * sjt_math1560;
    sjt_math1533 = sjt_math1535 + sjt_math1536;
    sjt_math1569 = (_parent)->m02;
    sjt_math1570 = (_parent)->m11;
    sjt_math1567 = sjt_math1569 * sjt_math1570;
    sjt_math1568 = (_parent)->m23;
    sjt_math1565 = sjt_math1567 * sjt_math1568;
    sjt_math1566 = (_parent)->m30;
    sjt_math1534 = sjt_math1565 * sjt_math1566;
    sjt_math1531 = sjt_math1533 + sjt_math1534;
    sjt_math1575 = (_parent)->m01;
    sjt_math1576 = (_parent)->m12;
    sjt_math1573 = sjt_math1575 * sjt_math1576;
    sjt_math1574 = (_parent)->m23;
    sjt_math1571 = sjt_math1573 * sjt_math1574;
    sjt_math1572 = (_parent)->m30;
    sjt_math1532 = sjt_math1571 * sjt_math1572;
    sjt_math1529 = sjt_math1531 - sjt_math1532;
    sjt_math1581 = (_parent)->m03;
    sjt_math1582 = (_parent)->m12;
    sjt_math1579 = sjt_math1581 * sjt_math1582;
    sjt_math1580 = (_parent)->m20;
    sjt_math1577 = sjt_math1579 * sjt_math1580;
    sjt_math1578 = (_parent)->m31;
    sjt_math1530 = sjt_math1577 * sjt_math1578;
    sjt_math1527 = sjt_math1529 - sjt_math1530;
    sjt_math1587 = (_parent)->m02;
    sjt_math1588 = (_parent)->m13;
    sjt_math1585 = sjt_math1587 * sjt_math1588;
    sjt_math1586 = (_parent)->m20;
    sjt_math1583 = sjt_math1585 * sjt_math1586;
    sjt_math1584 = (_parent)->m31;
    sjt_math1528 = sjt_math1583 * sjt_math1584;
    sjt_math1525 = sjt_math1527 + sjt_math1528;
    sjt_math1593 = (_parent)->m03;
    sjt_math1594 = (_parent)->m10;
    sjt_math1591 = sjt_math1593 * sjt_math1594;
    sjt_math1592 = (_parent)->m22;
    sjt_math1589 = sjt_math1591 * sjt_math1592;
    sjt_math1590 = (_parent)->m31;
    sjt_math1526 = sjt_math1589 * sjt_math1590;
    sjt_math1523 = sjt_math1525 + sjt_math1526;
    sjt_math1599 = (_parent)->m00;
    sjt_math1600 = (_parent)->m13;
    sjt_math1597 = sjt_math1599 * sjt_math1600;
    sjt_math1598 = (_parent)->m22;
    sjt_math1595 = sjt_math1597 * sjt_math1598;
    sjt_math1596 = (_parent)->m31;
    sjt_math1524 = sjt_math1595 * sjt_math1596;
    sjt_math1521 = sjt_math1523 - sjt_math1524;
    sjt_math1605 = (_parent)->m02;
    sjt_math1606 = (_parent)->m10;
    sjt_math1603 = sjt_math1605 * sjt_math1606;
    sjt_math1604 = (_parent)->m23;
    sjt_math1601 = sjt_math1603 * sjt_math1604;
    sjt_math1602 = (_parent)->m31;
    sjt_math1522 = sjt_math1601 * sjt_math1602;
    sjt_math1519 = sjt_math1521 - sjt_math1522;
    sjt_math1611 = (_parent)->m00;
    sjt_math1612 = (_parent)->m12;
    sjt_math1609 = sjt_math1611 * sjt_math1612;
    sjt_math1610 = (_parent)->m23;
    sjt_math1607 = sjt_math1609 * sjt_math1610;
    sjt_math1608 = (_parent)->m31;
    sjt_math1520 = sjt_math1607 * sjt_math1608;
    sjt_math1517 = sjt_math1519 + sjt_math1520;
    sjt_math1617 = (_parent)->m03;
    sjt_math1618 = (_parent)->m11;
    sjt_math1615 = sjt_math1617 * sjt_math1618;
    sjt_math1616 = (_parent)->m20;
    sjt_math1613 = sjt_math1615 * sjt_math1616;
    sjt_math1614 = (_parent)->m32;
    sjt_math1518 = sjt_math1613 * sjt_math1614;
    sjt_math1515 = sjt_math1517 + sjt_math1518;
    sjt_math1623 = (_parent)->m01;
    sjt_math1624 = (_parent)->m13;
    sjt_math1621 = sjt_math1623 * sjt_math1624;
    sjt_math1622 = (_parent)->m20;
    sjt_math1619 = sjt_math1621 * sjt_math1622;
    sjt_math1620 = (_parent)->m32;
    sjt_math1516 = sjt_math1619 * sjt_math1620;
    sjt_math1513 = sjt_math1515 - sjt_math1516;
    sjt_math1629 = (_parent)->m03;
    sjt_math1630 = (_parent)->m10;
    sjt_math1627 = sjt_math1629 * sjt_math1630;
    sjt_math1628 = (_parent)->m21;
    sjt_math1625 = sjt_math1627 * sjt_math1628;
    sjt_math1626 = (_parent)->m32;
    sjt_math1514 = sjt_math1625 * sjt_math1626;
    sjt_math1511 = sjt_math1513 - sjt_math1514;
    sjt_math1635 = (_parent)->m00;
    sjt_math1636 = (_parent)->m13;
    sjt_math1633 = sjt_math1635 * sjt_math1636;
    sjt_math1634 = (_parent)->m21;
    sjt_math1631 = sjt_math1633 * sjt_math1634;
    sjt_math1632 = (_parent)->m32;
    sjt_math1512 = sjt_math1631 * sjt_math1632;
    sjt_math1509 = sjt_math1511 + sjt_math1512;
    sjt_math1641 = (_parent)->m01;
    sjt_math1642 = (_parent)->m10;
    sjt_math1639 = sjt_math1641 * sjt_math1642;
    sjt_math1640 = (_parent)->m23;
    sjt_math1637 = sjt_math1639 * sjt_math1640;
    sjt_math1638 = (_parent)->m32;
    sjt_math1510 = sjt_math1637 * sjt_math1638;
    sjt_math1507 = sjt_math1509 + sjt_math1510;
    sjt_math1647 = (_parent)->m00;
    sjt_math1648 = (_parent)->m11;
    sjt_math1645 = sjt_math1647 * sjt_math1648;
    sjt_math1646 = (_parent)->m23;
    sjt_math1643 = sjt_math1645 * sjt_math1646;
    sjt_math1644 = (_parent)->m32;
    sjt_math1508 = sjt_math1643 * sjt_math1644;
    sjt_math1505 = sjt_math1507 - sjt_math1508;
    sjt_math1653 = (_parent)->m02;
    sjt_math1654 = (_parent)->m11;
    sjt_math1651 = sjt_math1653 * sjt_math1654;
    sjt_math1652 = (_parent)->m20;
    sjt_math1649 = sjt_math1651 * sjt_math1652;
    sjt_math1650 = (_parent)->m33;
    sjt_math1506 = sjt_math1649 * sjt_math1650;
    sjt_math1503 = sjt_math1505 - sjt_math1506;
    sjt_math1659 = (_parent)->m01;
    sjt_math1660 = (_parent)->m12;
    sjt_math1657 = sjt_math1659 * sjt_math1660;
    sjt_math1658 = (_parent)->m20;
    sjt_math1655 = sjt_math1657 * sjt_math1658;
    sjt_math1656 = (_parent)->m33;
    sjt_math1504 = sjt_math1655 * sjt_math1656;
    sjt_math1501 = sjt_math1503 + sjt_math1504;
    sjt_math1665 = (_parent)->m02;
    sjt_math1666 = (_parent)->m10;
    sjt_math1663 = sjt_math1665 * sjt_math1666;
    sjt_math1664 = (_parent)->m21;
    sjt_math1661 = sjt_math1663 * sjt_math1664;
    sjt_math1662 = (_parent)->m33;
    sjt_math1502 = sjt_math1661 * sjt_math1662;
    sjt_math1499 = sjt_math1501 + sjt_math1502;
    sjt_math1671 = (_parent)->m00;
    sjt_math1672 = (_parent)->m12;
    sjt_math1669 = sjt_math1671 * sjt_math1672;
    sjt_math1670 = (_parent)->m21;
    sjt_math1667 = sjt_math1669 * sjt_math1670;
    sjt_math1668 = (_parent)->m33;
    sjt_math1500 = sjt_math1667 * sjt_math1668;
    sjt_math1497 = sjt_math1499 - sjt_math1500;
    sjt_math1677 = (_parent)->m01;
    sjt_math1678 = (_parent)->m10;
    sjt_math1675 = sjt_math1677 * sjt_math1678;
    sjt_math1676 = (_parent)->m22;
    sjt_math1673 = sjt_math1675 * sjt_math1676;
    sjt_math1674 = (_parent)->m33;
    sjt_math1498 = sjt_math1673 * sjt_math1674;
    sjt_math1495 = sjt_math1497 - sjt_math1498;
    sjt_math1683 = (_parent)->m00;
    sjt_math1684 = (_parent)->m11;
    sjt_math1681 = sjt_math1683 * sjt_math1684;
    sjt_math1682 = (_parent)->m22;
    sjt_math1679 = sjt_math1681 * sjt_math1682;
    sjt_math1680 = (_parent)->m33;
    sjt_math1496 = sjt_math1679 * sjt_math1680;
    (*_return) = sjt_math1495 + sjt_math1496;
}

void sjf_mat4_heap(sjs_mat4_heap* _this) {
}

void sjf_mat4_identity(sjs_mat4* _return) {
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

void sjf_mat4_identity_heap(sjs_mat4_heap** _return) {
    (*_return) = (sjs_mat4_heap*)malloc(sizeof(sjs_mat4_heap));
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
    sjs_mat4* sjt_dot234;
    float sjt_functionParam57;
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
    float sjt_math1493;
    float sjt_math1494;
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
    sjs_mat4 sjv_t;

    sjt_math897 = (_parent)->m12;
    sjt_math898 = (_parent)->m23;
    sjt_math895 = sjt_math897 * sjt_math898;
    sjt_math896 = (_parent)->m31;
    sjt_math893 = sjt_math895 * sjt_math896;
    sjt_math901 = (_parent)->m13;
    sjt_math902 = (_parent)->m22;
    sjt_math899 = sjt_math901 * sjt_math902;
    sjt_math900 = (_parent)->m31;
    sjt_math894 = sjt_math899 * sjt_math900;
    sjt_math891 = sjt_math893 - sjt_math894;
    sjt_math905 = (_parent)->m13;
    sjt_math906 = (_parent)->m21;
    sjt_math903 = sjt_math905 * sjt_math906;
    sjt_math904 = (_parent)->m32;
    sjt_math892 = sjt_math903 * sjt_math904;
    sjt_math889 = sjt_math891 + sjt_math892;
    sjt_math909 = (_parent)->m11;
    sjt_math910 = (_parent)->m23;
    sjt_math907 = sjt_math909 * sjt_math910;
    sjt_math908 = (_parent)->m32;
    sjt_math890 = sjt_math907 * sjt_math908;
    sjt_math887 = sjt_math889 - sjt_math890;
    sjt_math913 = (_parent)->m12;
    sjt_math914 = (_parent)->m21;
    sjt_math911 = sjt_math913 * sjt_math914;
    sjt_math912 = (_parent)->m33;
    sjt_math888 = sjt_math911 * sjt_math912;
    sjt_math885 = sjt_math887 - sjt_math888;
    sjt_math917 = (_parent)->m11;
    sjt_math918 = (_parent)->m22;
    sjt_math915 = sjt_math917 * sjt_math918;
    sjt_math916 = (_parent)->m33;
    sjt_math886 = sjt_math915 * sjt_math916;
    sjv_t.m00 = sjt_math885 + sjt_math886;
    sjt_math931 = (_parent)->m03;
    sjt_math932 = (_parent)->m22;
    sjt_math929 = sjt_math931 * sjt_math932;
    sjt_math930 = (_parent)->m31;
    sjt_math927 = sjt_math929 * sjt_math930;
    sjt_math935 = (_parent)->m02;
    sjt_math936 = (_parent)->m23;
    sjt_math933 = sjt_math935 * sjt_math936;
    sjt_math934 = (_parent)->m31;
    sjt_math928 = sjt_math933 * sjt_math934;
    sjt_math925 = sjt_math927 - sjt_math928;
    sjt_math939 = (_parent)->m03;
    sjt_math940 = (_parent)->m21;
    sjt_math937 = sjt_math939 * sjt_math940;
    sjt_math938 = (_parent)->m32;
    sjt_math926 = sjt_math937 * sjt_math938;
    sjt_math923 = sjt_math925 - sjt_math926;
    sjt_math943 = (_parent)->m01;
    sjt_math944 = (_parent)->m23;
    sjt_math941 = sjt_math943 * sjt_math944;
    sjt_math942 = (_parent)->m32;
    sjt_math924 = sjt_math941 * sjt_math942;
    sjt_math921 = sjt_math923 + sjt_math924;
    sjt_math947 = (_parent)->m02;
    sjt_math948 = (_parent)->m21;
    sjt_math945 = sjt_math947 * sjt_math948;
    sjt_math946 = (_parent)->m33;
    sjt_math922 = sjt_math945 * sjt_math946;
    sjt_math919 = sjt_math921 + sjt_math922;
    sjt_math951 = (_parent)->m01;
    sjt_math952 = (_parent)->m22;
    sjt_math949 = sjt_math951 * sjt_math952;
    sjt_math950 = (_parent)->m33;
    sjt_math920 = sjt_math949 * sjt_math950;
    sjv_t.m01 = sjt_math919 - sjt_math920;
    sjt_math965 = (_parent)->m02;
    sjt_math966 = (_parent)->m13;
    sjt_math963 = sjt_math965 * sjt_math966;
    sjt_math964 = (_parent)->m31;
    sjt_math961 = sjt_math963 * sjt_math964;
    sjt_math969 = (_parent)->m03;
    sjt_math970 = (_parent)->m12;
    sjt_math967 = sjt_math969 * sjt_math970;
    sjt_math968 = (_parent)->m31;
    sjt_math962 = sjt_math967 * sjt_math968;
    sjt_math959 = sjt_math961 - sjt_math962;
    sjt_math973 = (_parent)->m03;
    sjt_math974 = (_parent)->m11;
    sjt_math971 = sjt_math973 * sjt_math974;
    sjt_math972 = (_parent)->m32;
    sjt_math960 = sjt_math971 * sjt_math972;
    sjt_math957 = sjt_math959 + sjt_math960;
    sjt_math977 = (_parent)->m01;
    sjt_math978 = (_parent)->m13;
    sjt_math975 = sjt_math977 * sjt_math978;
    sjt_math976 = (_parent)->m32;
    sjt_math958 = sjt_math975 * sjt_math976;
    sjt_math955 = sjt_math957 - sjt_math958;
    sjt_math981 = (_parent)->m02;
    sjt_math982 = (_parent)->m11;
    sjt_math979 = sjt_math981 * sjt_math982;
    sjt_math980 = (_parent)->m33;
    sjt_math956 = sjt_math979 * sjt_math980;
    sjt_math953 = sjt_math955 - sjt_math956;
    sjt_math985 = (_parent)->m01;
    sjt_math986 = (_parent)->m12;
    sjt_math983 = sjt_math985 * sjt_math986;
    sjt_math984 = (_parent)->m33;
    sjt_math954 = sjt_math983 * sjt_math984;
    sjv_t.m02 = sjt_math953 + sjt_math954;
    sjt_math999 = (_parent)->m03;
    sjt_math1000 = (_parent)->m12;
    sjt_math997 = sjt_math999 * sjt_math1000;
    sjt_math998 = (_parent)->m21;
    sjt_math995 = sjt_math997 * sjt_math998;
    sjt_math1003 = (_parent)->m02;
    sjt_math1004 = (_parent)->m13;
    sjt_math1001 = sjt_math1003 * sjt_math1004;
    sjt_math1002 = (_parent)->m21;
    sjt_math996 = sjt_math1001 * sjt_math1002;
    sjt_math993 = sjt_math995 - sjt_math996;
    sjt_math1007 = (_parent)->m03;
    sjt_math1008 = (_parent)->m11;
    sjt_math1005 = sjt_math1007 * sjt_math1008;
    sjt_math1006 = (_parent)->m22;
    sjt_math994 = sjt_math1005 * sjt_math1006;
    sjt_math991 = sjt_math993 - sjt_math994;
    sjt_math1011 = (_parent)->m01;
    sjt_math1012 = (_parent)->m13;
    sjt_math1009 = sjt_math1011 * sjt_math1012;
    sjt_math1010 = (_parent)->m22;
    sjt_math992 = sjt_math1009 * sjt_math1010;
    sjt_math989 = sjt_math991 + sjt_math992;
    sjt_math1015 = (_parent)->m02;
    sjt_math1016 = (_parent)->m11;
    sjt_math1013 = sjt_math1015 * sjt_math1016;
    sjt_math1014 = (_parent)->m23;
    sjt_math990 = sjt_math1013 * sjt_math1014;
    sjt_math987 = sjt_math989 + sjt_math990;
    sjt_math1019 = (_parent)->m01;
    sjt_math1020 = (_parent)->m12;
    sjt_math1017 = sjt_math1019 * sjt_math1020;
    sjt_math1018 = (_parent)->m23;
    sjt_math988 = sjt_math1017 * sjt_math1018;
    sjv_t.m03 = sjt_math987 - sjt_math988;
    sjt_math1033 = (_parent)->m13;
    sjt_math1034 = (_parent)->m22;
    sjt_math1031 = sjt_math1033 * sjt_math1034;
    sjt_math1032 = (_parent)->m30;
    sjt_math1029 = sjt_math1031 * sjt_math1032;
    sjt_math1037 = (_parent)->m12;
    sjt_math1038 = (_parent)->m23;
    sjt_math1035 = sjt_math1037 * sjt_math1038;
    sjt_math1036 = (_parent)->m30;
    sjt_math1030 = sjt_math1035 * sjt_math1036;
    sjt_math1027 = sjt_math1029 - sjt_math1030;
    sjt_math1041 = (_parent)->m13;
    sjt_math1042 = (_parent)->m20;
    sjt_math1039 = sjt_math1041 * sjt_math1042;
    sjt_math1040 = (_parent)->m32;
    sjt_math1028 = sjt_math1039 * sjt_math1040;
    sjt_math1025 = sjt_math1027 - sjt_math1028;
    sjt_math1045 = (_parent)->m10;
    sjt_math1046 = (_parent)->m23;
    sjt_math1043 = sjt_math1045 * sjt_math1046;
    sjt_math1044 = (_parent)->m32;
    sjt_math1026 = sjt_math1043 * sjt_math1044;
    sjt_math1023 = sjt_math1025 + sjt_math1026;
    sjt_math1049 = (_parent)->m12;
    sjt_math1050 = (_parent)->m20;
    sjt_math1047 = sjt_math1049 * sjt_math1050;
    sjt_math1048 = (_parent)->m33;
    sjt_math1024 = sjt_math1047 * sjt_math1048;
    sjt_math1021 = sjt_math1023 + sjt_math1024;
    sjt_math1053 = (_parent)->m10;
    sjt_math1054 = (_parent)->m22;
    sjt_math1051 = sjt_math1053 * sjt_math1054;
    sjt_math1052 = (_parent)->m33;
    sjt_math1022 = sjt_math1051 * sjt_math1052;
    sjv_t.m10 = sjt_math1021 - sjt_math1022;
    sjt_math1067 = (_parent)->m02;
    sjt_math1068 = (_parent)->m23;
    sjt_math1065 = sjt_math1067 * sjt_math1068;
    sjt_math1066 = (_parent)->m30;
    sjt_math1063 = sjt_math1065 * sjt_math1066;
    sjt_math1071 = (_parent)->m03;
    sjt_math1072 = (_parent)->m22;
    sjt_math1069 = sjt_math1071 * sjt_math1072;
    sjt_math1070 = (_parent)->m30;
    sjt_math1064 = sjt_math1069 * sjt_math1070;
    sjt_math1061 = sjt_math1063 - sjt_math1064;
    sjt_math1075 = (_parent)->m03;
    sjt_math1076 = (_parent)->m20;
    sjt_math1073 = sjt_math1075 * sjt_math1076;
    sjt_math1074 = (_parent)->m32;
    sjt_math1062 = sjt_math1073 * sjt_math1074;
    sjt_math1059 = sjt_math1061 + sjt_math1062;
    sjt_math1079 = (_parent)->m00;
    sjt_math1080 = (_parent)->m23;
    sjt_math1077 = sjt_math1079 * sjt_math1080;
    sjt_math1078 = (_parent)->m32;
    sjt_math1060 = sjt_math1077 * sjt_math1078;
    sjt_math1057 = sjt_math1059 - sjt_math1060;
    sjt_math1083 = (_parent)->m02;
    sjt_math1084 = (_parent)->m20;
    sjt_math1081 = sjt_math1083 * sjt_math1084;
    sjt_math1082 = (_parent)->m33;
    sjt_math1058 = sjt_math1081 * sjt_math1082;
    sjt_math1055 = sjt_math1057 - sjt_math1058;
    sjt_math1087 = (_parent)->m00;
    sjt_math1088 = (_parent)->m22;
    sjt_math1085 = sjt_math1087 * sjt_math1088;
    sjt_math1086 = (_parent)->m33;
    sjt_math1056 = sjt_math1085 * sjt_math1086;
    sjv_t.m11 = sjt_math1055 + sjt_math1056;
    sjt_math1101 = (_parent)->m03;
    sjt_math1102 = (_parent)->m12;
    sjt_math1099 = sjt_math1101 * sjt_math1102;
    sjt_math1100 = (_parent)->m30;
    sjt_math1097 = sjt_math1099 * sjt_math1100;
    sjt_math1105 = (_parent)->m02;
    sjt_math1106 = (_parent)->m13;
    sjt_math1103 = sjt_math1105 * sjt_math1106;
    sjt_math1104 = (_parent)->m30;
    sjt_math1098 = sjt_math1103 * sjt_math1104;
    sjt_math1095 = sjt_math1097 - sjt_math1098;
    sjt_math1109 = (_parent)->m03;
    sjt_math1110 = (_parent)->m10;
    sjt_math1107 = sjt_math1109 * sjt_math1110;
    sjt_math1108 = (_parent)->m32;
    sjt_math1096 = sjt_math1107 * sjt_math1108;
    sjt_math1093 = sjt_math1095 - sjt_math1096;
    sjt_math1113 = (_parent)->m00;
    sjt_math1114 = (_parent)->m13;
    sjt_math1111 = sjt_math1113 * sjt_math1114;
    sjt_math1112 = (_parent)->m32;
    sjt_math1094 = sjt_math1111 * sjt_math1112;
    sjt_math1091 = sjt_math1093 + sjt_math1094;
    sjt_math1117 = (_parent)->m02;
    sjt_math1118 = (_parent)->m10;
    sjt_math1115 = sjt_math1117 * sjt_math1118;
    sjt_math1116 = (_parent)->m33;
    sjt_math1092 = sjt_math1115 * sjt_math1116;
    sjt_math1089 = sjt_math1091 + sjt_math1092;
    sjt_math1121 = (_parent)->m00;
    sjt_math1122 = (_parent)->m12;
    sjt_math1119 = sjt_math1121 * sjt_math1122;
    sjt_math1120 = (_parent)->m33;
    sjt_math1090 = sjt_math1119 * sjt_math1120;
    sjv_t.m12 = sjt_math1089 - sjt_math1090;
    sjt_math1135 = (_parent)->m02;
    sjt_math1136 = (_parent)->m13;
    sjt_math1133 = sjt_math1135 * sjt_math1136;
    sjt_math1134 = (_parent)->m20;
    sjt_math1131 = sjt_math1133 * sjt_math1134;
    sjt_math1139 = (_parent)->m03;
    sjt_math1140 = (_parent)->m12;
    sjt_math1137 = sjt_math1139 * sjt_math1140;
    sjt_math1138 = (_parent)->m20;
    sjt_math1132 = sjt_math1137 * sjt_math1138;
    sjt_math1129 = sjt_math1131 - sjt_math1132;
    sjt_math1143 = (_parent)->m03;
    sjt_math1144 = (_parent)->m10;
    sjt_math1141 = sjt_math1143 * sjt_math1144;
    sjt_math1142 = (_parent)->m22;
    sjt_math1130 = sjt_math1141 * sjt_math1142;
    sjt_math1127 = sjt_math1129 + sjt_math1130;
    sjt_math1147 = (_parent)->m00;
    sjt_math1148 = (_parent)->m13;
    sjt_math1145 = sjt_math1147 * sjt_math1148;
    sjt_math1146 = (_parent)->m22;
    sjt_math1128 = sjt_math1145 * sjt_math1146;
    sjt_math1125 = sjt_math1127 - sjt_math1128;
    sjt_math1151 = (_parent)->m02;
    sjt_math1152 = (_parent)->m10;
    sjt_math1149 = sjt_math1151 * sjt_math1152;
    sjt_math1150 = (_parent)->m23;
    sjt_math1126 = sjt_math1149 * sjt_math1150;
    sjt_math1123 = sjt_math1125 - sjt_math1126;
    sjt_math1155 = (_parent)->m00;
    sjt_math1156 = (_parent)->m12;
    sjt_math1153 = sjt_math1155 * sjt_math1156;
    sjt_math1154 = (_parent)->m23;
    sjt_math1124 = sjt_math1153 * sjt_math1154;
    sjv_t.m13 = sjt_math1123 + sjt_math1124;
    sjt_math1169 = (_parent)->m11;
    sjt_math1170 = (_parent)->m23;
    sjt_math1167 = sjt_math1169 * sjt_math1170;
    sjt_math1168 = (_parent)->m30;
    sjt_math1165 = sjt_math1167 * sjt_math1168;
    sjt_math1173 = (_parent)->m13;
    sjt_math1174 = (_parent)->m21;
    sjt_math1171 = sjt_math1173 * sjt_math1174;
    sjt_math1172 = (_parent)->m30;
    sjt_math1166 = sjt_math1171 * sjt_math1172;
    sjt_math1163 = sjt_math1165 - sjt_math1166;
    sjt_math1177 = (_parent)->m13;
    sjt_math1178 = (_parent)->m20;
    sjt_math1175 = sjt_math1177 * sjt_math1178;
    sjt_math1176 = (_parent)->m31;
    sjt_math1164 = sjt_math1175 * sjt_math1176;
    sjt_math1161 = sjt_math1163 + sjt_math1164;
    sjt_math1181 = (_parent)->m10;
    sjt_math1182 = (_parent)->m23;
    sjt_math1179 = sjt_math1181 * sjt_math1182;
    sjt_math1180 = (_parent)->m31;
    sjt_math1162 = sjt_math1179 * sjt_math1180;
    sjt_math1159 = sjt_math1161 - sjt_math1162;
    sjt_math1185 = (_parent)->m11;
    sjt_math1186 = (_parent)->m20;
    sjt_math1183 = sjt_math1185 * sjt_math1186;
    sjt_math1184 = (_parent)->m33;
    sjt_math1160 = sjt_math1183 * sjt_math1184;
    sjt_math1157 = sjt_math1159 - sjt_math1160;
    sjt_math1189 = (_parent)->m10;
    sjt_math1190 = (_parent)->m21;
    sjt_math1187 = sjt_math1189 * sjt_math1190;
    sjt_math1188 = (_parent)->m33;
    sjt_math1158 = sjt_math1187 * sjt_math1188;
    sjv_t.m20 = sjt_math1157 + sjt_math1158;
    sjt_math1203 = (_parent)->m03;
    sjt_math1204 = (_parent)->m21;
    sjt_math1201 = sjt_math1203 * sjt_math1204;
    sjt_math1202 = (_parent)->m30;
    sjt_math1199 = sjt_math1201 * sjt_math1202;
    sjt_math1207 = (_parent)->m01;
    sjt_math1208 = (_parent)->m23;
    sjt_math1205 = sjt_math1207 * sjt_math1208;
    sjt_math1206 = (_parent)->m30;
    sjt_math1200 = sjt_math1205 * sjt_math1206;
    sjt_math1197 = sjt_math1199 - sjt_math1200;
    sjt_math1211 = (_parent)->m03;
    sjt_math1212 = (_parent)->m20;
    sjt_math1209 = sjt_math1211 * sjt_math1212;
    sjt_math1210 = (_parent)->m31;
    sjt_math1198 = sjt_math1209 * sjt_math1210;
    sjt_math1195 = sjt_math1197 - sjt_math1198;
    sjt_math1215 = (_parent)->m00;
    sjt_math1216 = (_parent)->m23;
    sjt_math1213 = sjt_math1215 * sjt_math1216;
    sjt_math1214 = (_parent)->m31;
    sjt_math1196 = sjt_math1213 * sjt_math1214;
    sjt_math1193 = sjt_math1195 + sjt_math1196;
    sjt_math1219 = (_parent)->m01;
    sjt_math1220 = (_parent)->m20;
    sjt_math1217 = sjt_math1219 * sjt_math1220;
    sjt_math1218 = (_parent)->m33;
    sjt_math1194 = sjt_math1217 * sjt_math1218;
    sjt_math1191 = sjt_math1193 + sjt_math1194;
    sjt_math1223 = (_parent)->m00;
    sjt_math1224 = (_parent)->m21;
    sjt_math1221 = sjt_math1223 * sjt_math1224;
    sjt_math1222 = (_parent)->m33;
    sjt_math1192 = sjt_math1221 * sjt_math1222;
    sjv_t.m21 = sjt_math1191 - sjt_math1192;
    sjt_math1237 = (_parent)->m01;
    sjt_math1238 = (_parent)->m13;
    sjt_math1235 = sjt_math1237 * sjt_math1238;
    sjt_math1236 = (_parent)->m30;
    sjt_math1233 = sjt_math1235 * sjt_math1236;
    sjt_math1241 = (_parent)->m03;
    sjt_math1242 = (_parent)->m11;
    sjt_math1239 = sjt_math1241 * sjt_math1242;
    sjt_math1240 = (_parent)->m30;
    sjt_math1234 = sjt_math1239 * sjt_math1240;
    sjt_math1231 = sjt_math1233 - sjt_math1234;
    sjt_math1245 = (_parent)->m03;
    sjt_math1246 = (_parent)->m10;
    sjt_math1243 = sjt_math1245 * sjt_math1246;
    sjt_math1244 = (_parent)->m31;
    sjt_math1232 = sjt_math1243 * sjt_math1244;
    sjt_math1229 = sjt_math1231 + sjt_math1232;
    sjt_math1249 = (_parent)->m00;
    sjt_math1250 = (_parent)->m13;
    sjt_math1247 = sjt_math1249 * sjt_math1250;
    sjt_math1248 = (_parent)->m31;
    sjt_math1230 = sjt_math1247 * sjt_math1248;
    sjt_math1227 = sjt_math1229 - sjt_math1230;
    sjt_math1253 = (_parent)->m01;
    sjt_math1254 = (_parent)->m10;
    sjt_math1251 = sjt_math1253 * sjt_math1254;
    sjt_math1252 = (_parent)->m33;
    sjt_math1228 = sjt_math1251 * sjt_math1252;
    sjt_math1225 = sjt_math1227 - sjt_math1228;
    sjt_math1257 = (_parent)->m00;
    sjt_math1258 = (_parent)->m11;
    sjt_math1255 = sjt_math1257 * sjt_math1258;
    sjt_math1256 = (_parent)->m33;
    sjt_math1226 = sjt_math1255 * sjt_math1256;
    sjv_t.m22 = sjt_math1225 + sjt_math1226;
    sjt_math1271 = (_parent)->m03;
    sjt_math1272 = (_parent)->m11;
    sjt_math1269 = sjt_math1271 * sjt_math1272;
    sjt_math1270 = (_parent)->m20;
    sjt_math1267 = sjt_math1269 * sjt_math1270;
    sjt_math1275 = (_parent)->m01;
    sjt_math1276 = (_parent)->m13;
    sjt_math1273 = sjt_math1275 * sjt_math1276;
    sjt_math1274 = (_parent)->m20;
    sjt_math1268 = sjt_math1273 * sjt_math1274;
    sjt_math1265 = sjt_math1267 - sjt_math1268;
    sjt_math1279 = (_parent)->m03;
    sjt_math1280 = (_parent)->m10;
    sjt_math1277 = sjt_math1279 * sjt_math1280;
    sjt_math1278 = (_parent)->m21;
    sjt_math1266 = sjt_math1277 * sjt_math1278;
    sjt_math1263 = sjt_math1265 - sjt_math1266;
    sjt_math1283 = (_parent)->m00;
    sjt_math1284 = (_parent)->m13;
    sjt_math1281 = sjt_math1283 * sjt_math1284;
    sjt_math1282 = (_parent)->m21;
    sjt_math1264 = sjt_math1281 * sjt_math1282;
    sjt_math1261 = sjt_math1263 + sjt_math1264;
    sjt_math1287 = (_parent)->m01;
    sjt_math1288 = (_parent)->m10;
    sjt_math1285 = sjt_math1287 * sjt_math1288;
    sjt_math1286 = (_parent)->m23;
    sjt_math1262 = sjt_math1285 * sjt_math1286;
    sjt_math1259 = sjt_math1261 + sjt_math1262;
    sjt_math1291 = (_parent)->m00;
    sjt_math1292 = (_parent)->m11;
    sjt_math1289 = sjt_math1291 * sjt_math1292;
    sjt_math1290 = (_parent)->m23;
    sjt_math1260 = sjt_math1289 * sjt_math1290;
    sjv_t.m23 = sjt_math1259 - sjt_math1260;
    sjt_math1305 = (_parent)->m12;
    sjt_math1306 = (_parent)->m21;
    sjt_math1303 = sjt_math1305 * sjt_math1306;
    sjt_math1304 = (_parent)->m30;
    sjt_math1301 = sjt_math1303 * sjt_math1304;
    sjt_math1309 = (_parent)->m11;
    sjt_math1310 = (_parent)->m22;
    sjt_math1307 = sjt_math1309 * sjt_math1310;
    sjt_math1308 = (_parent)->m30;
    sjt_math1302 = sjt_math1307 * sjt_math1308;
    sjt_math1299 = sjt_math1301 - sjt_math1302;
    sjt_math1313 = (_parent)->m12;
    sjt_math1314 = (_parent)->m20;
    sjt_math1311 = sjt_math1313 * sjt_math1314;
    sjt_math1312 = (_parent)->m31;
    sjt_math1300 = sjt_math1311 * sjt_math1312;
    sjt_math1297 = sjt_math1299 - sjt_math1300;
    sjt_math1317 = (_parent)->m10;
    sjt_math1318 = (_parent)->m22;
    sjt_math1315 = sjt_math1317 * sjt_math1318;
    sjt_math1316 = (_parent)->m31;
    sjt_math1298 = sjt_math1315 * sjt_math1316;
    sjt_math1295 = sjt_math1297 + sjt_math1298;
    sjt_math1321 = (_parent)->m11;
    sjt_math1322 = (_parent)->m20;
    sjt_math1319 = sjt_math1321 * sjt_math1322;
    sjt_math1320 = (_parent)->m32;
    sjt_math1296 = sjt_math1319 * sjt_math1320;
    sjt_math1293 = sjt_math1295 + sjt_math1296;
    sjt_math1325 = (_parent)->m10;
    sjt_math1326 = (_parent)->m21;
    sjt_math1323 = sjt_math1325 * sjt_math1326;
    sjt_math1324 = (_parent)->m32;
    sjt_math1294 = sjt_math1323 * sjt_math1324;
    sjv_t.m30 = sjt_math1293 - sjt_math1294;
    sjt_math1339 = (_parent)->m01;
    sjt_math1340 = (_parent)->m22;
    sjt_math1337 = sjt_math1339 * sjt_math1340;
    sjt_math1338 = (_parent)->m30;
    sjt_math1335 = sjt_math1337 * sjt_math1338;
    sjt_math1343 = (_parent)->m02;
    sjt_math1344 = (_parent)->m21;
    sjt_math1341 = sjt_math1343 * sjt_math1344;
    sjt_math1342 = (_parent)->m30;
    sjt_math1336 = sjt_math1341 * sjt_math1342;
    sjt_math1333 = sjt_math1335 - sjt_math1336;
    sjt_math1347 = (_parent)->m02;
    sjt_math1348 = (_parent)->m20;
    sjt_math1345 = sjt_math1347 * sjt_math1348;
    sjt_math1346 = (_parent)->m31;
    sjt_math1334 = sjt_math1345 * sjt_math1346;
    sjt_math1331 = sjt_math1333 + sjt_math1334;
    sjt_math1351 = (_parent)->m00;
    sjt_math1352 = (_parent)->m22;
    sjt_math1349 = sjt_math1351 * sjt_math1352;
    sjt_math1350 = (_parent)->m31;
    sjt_math1332 = sjt_math1349 * sjt_math1350;
    sjt_math1329 = sjt_math1331 - sjt_math1332;
    sjt_math1355 = (_parent)->m01;
    sjt_math1356 = (_parent)->m20;
    sjt_math1353 = sjt_math1355 * sjt_math1356;
    sjt_math1354 = (_parent)->m32;
    sjt_math1330 = sjt_math1353 * sjt_math1354;
    sjt_math1327 = sjt_math1329 - sjt_math1330;
    sjt_math1359 = (_parent)->m00;
    sjt_math1360 = (_parent)->m21;
    sjt_math1357 = sjt_math1359 * sjt_math1360;
    sjt_math1358 = (_parent)->m32;
    sjt_math1328 = sjt_math1357 * sjt_math1358;
    sjv_t.m31 = sjt_math1327 + sjt_math1328;
    sjt_math1373 = (_parent)->m02;
    sjt_math1374 = (_parent)->m11;
    sjt_math1371 = sjt_math1373 * sjt_math1374;
    sjt_math1372 = (_parent)->m30;
    sjt_math1369 = sjt_math1371 * sjt_math1372;
    sjt_math1377 = (_parent)->m01;
    sjt_math1378 = (_parent)->m12;
    sjt_math1375 = sjt_math1377 * sjt_math1378;
    sjt_math1376 = (_parent)->m30;
    sjt_math1370 = sjt_math1375 * sjt_math1376;
    sjt_math1367 = sjt_math1369 - sjt_math1370;
    sjt_math1381 = (_parent)->m02;
    sjt_math1382 = (_parent)->m10;
    sjt_math1379 = sjt_math1381 * sjt_math1382;
    sjt_math1380 = (_parent)->m31;
    sjt_math1368 = sjt_math1379 * sjt_math1380;
    sjt_math1365 = sjt_math1367 - sjt_math1368;
    sjt_math1385 = (_parent)->m00;
    sjt_math1386 = (_parent)->m12;
    sjt_math1383 = sjt_math1385 * sjt_math1386;
    sjt_math1384 = (_parent)->m31;
    sjt_math1366 = sjt_math1383 * sjt_math1384;
    sjt_math1363 = sjt_math1365 + sjt_math1366;
    sjt_math1389 = (_parent)->m01;
    sjt_math1390 = (_parent)->m10;
    sjt_math1387 = sjt_math1389 * sjt_math1390;
    sjt_math1388 = (_parent)->m32;
    sjt_math1364 = sjt_math1387 * sjt_math1388;
    sjt_math1361 = sjt_math1363 + sjt_math1364;
    sjt_math1393 = (_parent)->m00;
    sjt_math1394 = (_parent)->m11;
    sjt_math1391 = sjt_math1393 * sjt_math1394;
    sjt_math1392 = (_parent)->m32;
    sjt_math1362 = sjt_math1391 * sjt_math1392;
    sjv_t.m32 = sjt_math1361 - sjt_math1362;
    sjt_math1407 = (_parent)->m01;
    sjt_math1408 = (_parent)->m12;
    sjt_math1405 = sjt_math1407 * sjt_math1408;
    sjt_math1406 = (_parent)->m20;
    sjt_math1403 = sjt_math1405 * sjt_math1406;
    sjt_math1411 = (_parent)->m02;
    sjt_math1412 = (_parent)->m11;
    sjt_math1409 = sjt_math1411 * sjt_math1412;
    sjt_math1410 = (_parent)->m20;
    sjt_math1404 = sjt_math1409 * sjt_math1410;
    sjt_math1401 = sjt_math1403 - sjt_math1404;
    sjt_math1415 = (_parent)->m02;
    sjt_math1416 = (_parent)->m10;
    sjt_math1413 = sjt_math1415 * sjt_math1416;
    sjt_math1414 = (_parent)->m21;
    sjt_math1402 = sjt_math1413 * sjt_math1414;
    sjt_math1399 = sjt_math1401 + sjt_math1402;
    sjt_math1419 = (_parent)->m00;
    sjt_math1420 = (_parent)->m12;
    sjt_math1417 = sjt_math1419 * sjt_math1420;
    sjt_math1418 = (_parent)->m21;
    sjt_math1400 = sjt_math1417 * sjt_math1418;
    sjt_math1397 = sjt_math1399 - sjt_math1400;
    sjt_math1423 = (_parent)->m01;
    sjt_math1424 = (_parent)->m10;
    sjt_math1421 = sjt_math1423 * sjt_math1424;
    sjt_math1422 = (_parent)->m22;
    sjt_math1398 = sjt_math1421 * sjt_math1422;
    sjt_math1395 = sjt_math1397 - sjt_math1398;
    sjt_math1427 = (_parent)->m00;
    sjt_math1428 = (_parent)->m11;
    sjt_math1425 = sjt_math1427 * sjt_math1428;
    sjt_math1426 = (_parent)->m22;
    sjt_math1396 = sjt_math1425 * sjt_math1426;
    sjv_t.m33 = sjt_math1395 + sjt_math1396;
    sjf_mat4(&sjv_t);
    sjt_dot234 = &sjv_t;
    sjt_math1493 = 1.0f;
    sjf_mat4_determinant(_parent, &sjt_math1494);
    sjt_functionParam57 = sjt_math1493 / sjt_math1494;
    sjf_mat4_multiply_f32(sjt_dot234, sjt_functionParam57, _return);

    sjf_mat4_destroy(&sjv_t);
}

void sjf_mat4_invert_heap(sjs_mat4* _parent, sjs_mat4_heap** _return) {
    sjs_mat4* sjt_dot235;
    float sjt_functionParam58;
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
    sjs_mat4 sjv_t;

    sjt_math1697 = (_parent)->m12;
    sjt_math1698 = (_parent)->m23;
    sjt_math1695 = sjt_math1697 * sjt_math1698;
    sjt_math1696 = (_parent)->m31;
    sjt_math1693 = sjt_math1695 * sjt_math1696;
    sjt_math1701 = (_parent)->m13;
    sjt_math1702 = (_parent)->m22;
    sjt_math1699 = sjt_math1701 * sjt_math1702;
    sjt_math1700 = (_parent)->m31;
    sjt_math1694 = sjt_math1699 * sjt_math1700;
    sjt_math1691 = sjt_math1693 - sjt_math1694;
    sjt_math1705 = (_parent)->m13;
    sjt_math1706 = (_parent)->m21;
    sjt_math1703 = sjt_math1705 * sjt_math1706;
    sjt_math1704 = (_parent)->m32;
    sjt_math1692 = sjt_math1703 * sjt_math1704;
    sjt_math1689 = sjt_math1691 + sjt_math1692;
    sjt_math1709 = (_parent)->m11;
    sjt_math1710 = (_parent)->m23;
    sjt_math1707 = sjt_math1709 * sjt_math1710;
    sjt_math1708 = (_parent)->m32;
    sjt_math1690 = sjt_math1707 * sjt_math1708;
    sjt_math1687 = sjt_math1689 - sjt_math1690;
    sjt_math1713 = (_parent)->m12;
    sjt_math1714 = (_parent)->m21;
    sjt_math1711 = sjt_math1713 * sjt_math1714;
    sjt_math1712 = (_parent)->m33;
    sjt_math1688 = sjt_math1711 * sjt_math1712;
    sjt_math1685 = sjt_math1687 - sjt_math1688;
    sjt_math1717 = (_parent)->m11;
    sjt_math1718 = (_parent)->m22;
    sjt_math1715 = sjt_math1717 * sjt_math1718;
    sjt_math1716 = (_parent)->m33;
    sjt_math1686 = sjt_math1715 * sjt_math1716;
    sjv_t.m00 = sjt_math1685 + sjt_math1686;
    sjt_math1731 = (_parent)->m03;
    sjt_math1732 = (_parent)->m22;
    sjt_math1729 = sjt_math1731 * sjt_math1732;
    sjt_math1730 = (_parent)->m31;
    sjt_math1727 = sjt_math1729 * sjt_math1730;
    sjt_math1735 = (_parent)->m02;
    sjt_math1736 = (_parent)->m23;
    sjt_math1733 = sjt_math1735 * sjt_math1736;
    sjt_math1734 = (_parent)->m31;
    sjt_math1728 = sjt_math1733 * sjt_math1734;
    sjt_math1725 = sjt_math1727 - sjt_math1728;
    sjt_math1739 = (_parent)->m03;
    sjt_math1740 = (_parent)->m21;
    sjt_math1737 = sjt_math1739 * sjt_math1740;
    sjt_math1738 = (_parent)->m32;
    sjt_math1726 = sjt_math1737 * sjt_math1738;
    sjt_math1723 = sjt_math1725 - sjt_math1726;
    sjt_math1743 = (_parent)->m01;
    sjt_math1744 = (_parent)->m23;
    sjt_math1741 = sjt_math1743 * sjt_math1744;
    sjt_math1742 = (_parent)->m32;
    sjt_math1724 = sjt_math1741 * sjt_math1742;
    sjt_math1721 = sjt_math1723 + sjt_math1724;
    sjt_math1747 = (_parent)->m02;
    sjt_math1748 = (_parent)->m21;
    sjt_math1745 = sjt_math1747 * sjt_math1748;
    sjt_math1746 = (_parent)->m33;
    sjt_math1722 = sjt_math1745 * sjt_math1746;
    sjt_math1719 = sjt_math1721 + sjt_math1722;
    sjt_math1751 = (_parent)->m01;
    sjt_math1752 = (_parent)->m22;
    sjt_math1749 = sjt_math1751 * sjt_math1752;
    sjt_math1750 = (_parent)->m33;
    sjt_math1720 = sjt_math1749 * sjt_math1750;
    sjv_t.m01 = sjt_math1719 - sjt_math1720;
    sjt_math1765 = (_parent)->m02;
    sjt_math1766 = (_parent)->m13;
    sjt_math1763 = sjt_math1765 * sjt_math1766;
    sjt_math1764 = (_parent)->m31;
    sjt_math1761 = sjt_math1763 * sjt_math1764;
    sjt_math1769 = (_parent)->m03;
    sjt_math1770 = (_parent)->m12;
    sjt_math1767 = sjt_math1769 * sjt_math1770;
    sjt_math1768 = (_parent)->m31;
    sjt_math1762 = sjt_math1767 * sjt_math1768;
    sjt_math1759 = sjt_math1761 - sjt_math1762;
    sjt_math1773 = (_parent)->m03;
    sjt_math1774 = (_parent)->m11;
    sjt_math1771 = sjt_math1773 * sjt_math1774;
    sjt_math1772 = (_parent)->m32;
    sjt_math1760 = sjt_math1771 * sjt_math1772;
    sjt_math1757 = sjt_math1759 + sjt_math1760;
    sjt_math1777 = (_parent)->m01;
    sjt_math1778 = (_parent)->m13;
    sjt_math1775 = sjt_math1777 * sjt_math1778;
    sjt_math1776 = (_parent)->m32;
    sjt_math1758 = sjt_math1775 * sjt_math1776;
    sjt_math1755 = sjt_math1757 - sjt_math1758;
    sjt_math1781 = (_parent)->m02;
    sjt_math1782 = (_parent)->m11;
    sjt_math1779 = sjt_math1781 * sjt_math1782;
    sjt_math1780 = (_parent)->m33;
    sjt_math1756 = sjt_math1779 * sjt_math1780;
    sjt_math1753 = sjt_math1755 - sjt_math1756;
    sjt_math1785 = (_parent)->m01;
    sjt_math1786 = (_parent)->m12;
    sjt_math1783 = sjt_math1785 * sjt_math1786;
    sjt_math1784 = (_parent)->m33;
    sjt_math1754 = sjt_math1783 * sjt_math1784;
    sjv_t.m02 = sjt_math1753 + sjt_math1754;
    sjt_math1799 = (_parent)->m03;
    sjt_math1800 = (_parent)->m12;
    sjt_math1797 = sjt_math1799 * sjt_math1800;
    sjt_math1798 = (_parent)->m21;
    sjt_math1795 = sjt_math1797 * sjt_math1798;
    sjt_math1803 = (_parent)->m02;
    sjt_math1804 = (_parent)->m13;
    sjt_math1801 = sjt_math1803 * sjt_math1804;
    sjt_math1802 = (_parent)->m21;
    sjt_math1796 = sjt_math1801 * sjt_math1802;
    sjt_math1793 = sjt_math1795 - sjt_math1796;
    sjt_math1807 = (_parent)->m03;
    sjt_math1808 = (_parent)->m11;
    sjt_math1805 = sjt_math1807 * sjt_math1808;
    sjt_math1806 = (_parent)->m22;
    sjt_math1794 = sjt_math1805 * sjt_math1806;
    sjt_math1791 = sjt_math1793 - sjt_math1794;
    sjt_math1811 = (_parent)->m01;
    sjt_math1812 = (_parent)->m13;
    sjt_math1809 = sjt_math1811 * sjt_math1812;
    sjt_math1810 = (_parent)->m22;
    sjt_math1792 = sjt_math1809 * sjt_math1810;
    sjt_math1789 = sjt_math1791 + sjt_math1792;
    sjt_math1815 = (_parent)->m02;
    sjt_math1816 = (_parent)->m11;
    sjt_math1813 = sjt_math1815 * sjt_math1816;
    sjt_math1814 = (_parent)->m23;
    sjt_math1790 = sjt_math1813 * sjt_math1814;
    sjt_math1787 = sjt_math1789 + sjt_math1790;
    sjt_math1819 = (_parent)->m01;
    sjt_math1820 = (_parent)->m12;
    sjt_math1817 = sjt_math1819 * sjt_math1820;
    sjt_math1818 = (_parent)->m23;
    sjt_math1788 = sjt_math1817 * sjt_math1818;
    sjv_t.m03 = sjt_math1787 - sjt_math1788;
    sjt_math1833 = (_parent)->m13;
    sjt_math1834 = (_parent)->m22;
    sjt_math1831 = sjt_math1833 * sjt_math1834;
    sjt_math1832 = (_parent)->m30;
    sjt_math1829 = sjt_math1831 * sjt_math1832;
    sjt_math1837 = (_parent)->m12;
    sjt_math1838 = (_parent)->m23;
    sjt_math1835 = sjt_math1837 * sjt_math1838;
    sjt_math1836 = (_parent)->m30;
    sjt_math1830 = sjt_math1835 * sjt_math1836;
    sjt_math1827 = sjt_math1829 - sjt_math1830;
    sjt_math1841 = (_parent)->m13;
    sjt_math1842 = (_parent)->m20;
    sjt_math1839 = sjt_math1841 * sjt_math1842;
    sjt_math1840 = (_parent)->m32;
    sjt_math1828 = sjt_math1839 * sjt_math1840;
    sjt_math1825 = sjt_math1827 - sjt_math1828;
    sjt_math1845 = (_parent)->m10;
    sjt_math1846 = (_parent)->m23;
    sjt_math1843 = sjt_math1845 * sjt_math1846;
    sjt_math1844 = (_parent)->m32;
    sjt_math1826 = sjt_math1843 * sjt_math1844;
    sjt_math1823 = sjt_math1825 + sjt_math1826;
    sjt_math1849 = (_parent)->m12;
    sjt_math1850 = (_parent)->m20;
    sjt_math1847 = sjt_math1849 * sjt_math1850;
    sjt_math1848 = (_parent)->m33;
    sjt_math1824 = sjt_math1847 * sjt_math1848;
    sjt_math1821 = sjt_math1823 + sjt_math1824;
    sjt_math1853 = (_parent)->m10;
    sjt_math1854 = (_parent)->m22;
    sjt_math1851 = sjt_math1853 * sjt_math1854;
    sjt_math1852 = (_parent)->m33;
    sjt_math1822 = sjt_math1851 * sjt_math1852;
    sjv_t.m10 = sjt_math1821 - sjt_math1822;
    sjt_math1867 = (_parent)->m02;
    sjt_math1868 = (_parent)->m23;
    sjt_math1865 = sjt_math1867 * sjt_math1868;
    sjt_math1866 = (_parent)->m30;
    sjt_math1863 = sjt_math1865 * sjt_math1866;
    sjt_math1871 = (_parent)->m03;
    sjt_math1872 = (_parent)->m22;
    sjt_math1869 = sjt_math1871 * sjt_math1872;
    sjt_math1870 = (_parent)->m30;
    sjt_math1864 = sjt_math1869 * sjt_math1870;
    sjt_math1861 = sjt_math1863 - sjt_math1864;
    sjt_math1875 = (_parent)->m03;
    sjt_math1876 = (_parent)->m20;
    sjt_math1873 = sjt_math1875 * sjt_math1876;
    sjt_math1874 = (_parent)->m32;
    sjt_math1862 = sjt_math1873 * sjt_math1874;
    sjt_math1859 = sjt_math1861 + sjt_math1862;
    sjt_math1879 = (_parent)->m00;
    sjt_math1880 = (_parent)->m23;
    sjt_math1877 = sjt_math1879 * sjt_math1880;
    sjt_math1878 = (_parent)->m32;
    sjt_math1860 = sjt_math1877 * sjt_math1878;
    sjt_math1857 = sjt_math1859 - sjt_math1860;
    sjt_math1883 = (_parent)->m02;
    sjt_math1884 = (_parent)->m20;
    sjt_math1881 = sjt_math1883 * sjt_math1884;
    sjt_math1882 = (_parent)->m33;
    sjt_math1858 = sjt_math1881 * sjt_math1882;
    sjt_math1855 = sjt_math1857 - sjt_math1858;
    sjt_math1887 = (_parent)->m00;
    sjt_math1888 = (_parent)->m22;
    sjt_math1885 = sjt_math1887 * sjt_math1888;
    sjt_math1886 = (_parent)->m33;
    sjt_math1856 = sjt_math1885 * sjt_math1886;
    sjv_t.m11 = sjt_math1855 + sjt_math1856;
    sjt_math1901 = (_parent)->m03;
    sjt_math1902 = (_parent)->m12;
    sjt_math1899 = sjt_math1901 * sjt_math1902;
    sjt_math1900 = (_parent)->m30;
    sjt_math1897 = sjt_math1899 * sjt_math1900;
    sjt_math1905 = (_parent)->m02;
    sjt_math1906 = (_parent)->m13;
    sjt_math1903 = sjt_math1905 * sjt_math1906;
    sjt_math1904 = (_parent)->m30;
    sjt_math1898 = sjt_math1903 * sjt_math1904;
    sjt_math1895 = sjt_math1897 - sjt_math1898;
    sjt_math1909 = (_parent)->m03;
    sjt_math1910 = (_parent)->m10;
    sjt_math1907 = sjt_math1909 * sjt_math1910;
    sjt_math1908 = (_parent)->m32;
    sjt_math1896 = sjt_math1907 * sjt_math1908;
    sjt_math1893 = sjt_math1895 - sjt_math1896;
    sjt_math1913 = (_parent)->m00;
    sjt_math1914 = (_parent)->m13;
    sjt_math1911 = sjt_math1913 * sjt_math1914;
    sjt_math1912 = (_parent)->m32;
    sjt_math1894 = sjt_math1911 * sjt_math1912;
    sjt_math1891 = sjt_math1893 + sjt_math1894;
    sjt_math1917 = (_parent)->m02;
    sjt_math1918 = (_parent)->m10;
    sjt_math1915 = sjt_math1917 * sjt_math1918;
    sjt_math1916 = (_parent)->m33;
    sjt_math1892 = sjt_math1915 * sjt_math1916;
    sjt_math1889 = sjt_math1891 + sjt_math1892;
    sjt_math1921 = (_parent)->m00;
    sjt_math1922 = (_parent)->m12;
    sjt_math1919 = sjt_math1921 * sjt_math1922;
    sjt_math1920 = (_parent)->m33;
    sjt_math1890 = sjt_math1919 * sjt_math1920;
    sjv_t.m12 = sjt_math1889 - sjt_math1890;
    sjt_math1935 = (_parent)->m02;
    sjt_math1936 = (_parent)->m13;
    sjt_math1933 = sjt_math1935 * sjt_math1936;
    sjt_math1934 = (_parent)->m20;
    sjt_math1931 = sjt_math1933 * sjt_math1934;
    sjt_math1939 = (_parent)->m03;
    sjt_math1940 = (_parent)->m12;
    sjt_math1937 = sjt_math1939 * sjt_math1940;
    sjt_math1938 = (_parent)->m20;
    sjt_math1932 = sjt_math1937 * sjt_math1938;
    sjt_math1929 = sjt_math1931 - sjt_math1932;
    sjt_math1943 = (_parent)->m03;
    sjt_math1944 = (_parent)->m10;
    sjt_math1941 = sjt_math1943 * sjt_math1944;
    sjt_math1942 = (_parent)->m22;
    sjt_math1930 = sjt_math1941 * sjt_math1942;
    sjt_math1927 = sjt_math1929 + sjt_math1930;
    sjt_math1947 = (_parent)->m00;
    sjt_math1948 = (_parent)->m13;
    sjt_math1945 = sjt_math1947 * sjt_math1948;
    sjt_math1946 = (_parent)->m22;
    sjt_math1928 = sjt_math1945 * sjt_math1946;
    sjt_math1925 = sjt_math1927 - sjt_math1928;
    sjt_math1951 = (_parent)->m02;
    sjt_math1952 = (_parent)->m10;
    sjt_math1949 = sjt_math1951 * sjt_math1952;
    sjt_math1950 = (_parent)->m23;
    sjt_math1926 = sjt_math1949 * sjt_math1950;
    sjt_math1923 = sjt_math1925 - sjt_math1926;
    sjt_math1955 = (_parent)->m00;
    sjt_math1956 = (_parent)->m12;
    sjt_math1953 = sjt_math1955 * sjt_math1956;
    sjt_math1954 = (_parent)->m23;
    sjt_math1924 = sjt_math1953 * sjt_math1954;
    sjv_t.m13 = sjt_math1923 + sjt_math1924;
    sjt_math1969 = (_parent)->m11;
    sjt_math1970 = (_parent)->m23;
    sjt_math1967 = sjt_math1969 * sjt_math1970;
    sjt_math1968 = (_parent)->m30;
    sjt_math1965 = sjt_math1967 * sjt_math1968;
    sjt_math1973 = (_parent)->m13;
    sjt_math1974 = (_parent)->m21;
    sjt_math1971 = sjt_math1973 * sjt_math1974;
    sjt_math1972 = (_parent)->m30;
    sjt_math1966 = sjt_math1971 * sjt_math1972;
    sjt_math1963 = sjt_math1965 - sjt_math1966;
    sjt_math1977 = (_parent)->m13;
    sjt_math1978 = (_parent)->m20;
    sjt_math1975 = sjt_math1977 * sjt_math1978;
    sjt_math1976 = (_parent)->m31;
    sjt_math1964 = sjt_math1975 * sjt_math1976;
    sjt_math1961 = sjt_math1963 + sjt_math1964;
    sjt_math1981 = (_parent)->m10;
    sjt_math1982 = (_parent)->m23;
    sjt_math1979 = sjt_math1981 * sjt_math1982;
    sjt_math1980 = (_parent)->m31;
    sjt_math1962 = sjt_math1979 * sjt_math1980;
    sjt_math1959 = sjt_math1961 - sjt_math1962;
    sjt_math1985 = (_parent)->m11;
    sjt_math1986 = (_parent)->m20;
    sjt_math1983 = sjt_math1985 * sjt_math1986;
    sjt_math1984 = (_parent)->m33;
    sjt_math1960 = sjt_math1983 * sjt_math1984;
    sjt_math1957 = sjt_math1959 - sjt_math1960;
    sjt_math1989 = (_parent)->m10;
    sjt_math1990 = (_parent)->m21;
    sjt_math1987 = sjt_math1989 * sjt_math1990;
    sjt_math1988 = (_parent)->m33;
    sjt_math1958 = sjt_math1987 * sjt_math1988;
    sjv_t.m20 = sjt_math1957 + sjt_math1958;
    sjt_math2003 = (_parent)->m03;
    sjt_math2004 = (_parent)->m21;
    sjt_math2001 = sjt_math2003 * sjt_math2004;
    sjt_math2002 = (_parent)->m30;
    sjt_math1999 = sjt_math2001 * sjt_math2002;
    sjt_math2007 = (_parent)->m01;
    sjt_math2008 = (_parent)->m23;
    sjt_math2005 = sjt_math2007 * sjt_math2008;
    sjt_math2006 = (_parent)->m30;
    sjt_math2000 = sjt_math2005 * sjt_math2006;
    sjt_math1997 = sjt_math1999 - sjt_math2000;
    sjt_math2011 = (_parent)->m03;
    sjt_math2012 = (_parent)->m20;
    sjt_math2009 = sjt_math2011 * sjt_math2012;
    sjt_math2010 = (_parent)->m31;
    sjt_math1998 = sjt_math2009 * sjt_math2010;
    sjt_math1995 = sjt_math1997 - sjt_math1998;
    sjt_math2015 = (_parent)->m00;
    sjt_math2016 = (_parent)->m23;
    sjt_math2013 = sjt_math2015 * sjt_math2016;
    sjt_math2014 = (_parent)->m31;
    sjt_math1996 = sjt_math2013 * sjt_math2014;
    sjt_math1993 = sjt_math1995 + sjt_math1996;
    sjt_math2019 = (_parent)->m01;
    sjt_math2020 = (_parent)->m20;
    sjt_math2017 = sjt_math2019 * sjt_math2020;
    sjt_math2018 = (_parent)->m33;
    sjt_math1994 = sjt_math2017 * sjt_math2018;
    sjt_math1991 = sjt_math1993 + sjt_math1994;
    sjt_math2023 = (_parent)->m00;
    sjt_math2024 = (_parent)->m21;
    sjt_math2021 = sjt_math2023 * sjt_math2024;
    sjt_math2022 = (_parent)->m33;
    sjt_math1992 = sjt_math2021 * sjt_math2022;
    sjv_t.m21 = sjt_math1991 - sjt_math1992;
    sjt_math2037 = (_parent)->m01;
    sjt_math2038 = (_parent)->m13;
    sjt_math2035 = sjt_math2037 * sjt_math2038;
    sjt_math2036 = (_parent)->m30;
    sjt_math2033 = sjt_math2035 * sjt_math2036;
    sjt_math2041 = (_parent)->m03;
    sjt_math2042 = (_parent)->m11;
    sjt_math2039 = sjt_math2041 * sjt_math2042;
    sjt_math2040 = (_parent)->m30;
    sjt_math2034 = sjt_math2039 * sjt_math2040;
    sjt_math2031 = sjt_math2033 - sjt_math2034;
    sjt_math2045 = (_parent)->m03;
    sjt_math2046 = (_parent)->m10;
    sjt_math2043 = sjt_math2045 * sjt_math2046;
    sjt_math2044 = (_parent)->m31;
    sjt_math2032 = sjt_math2043 * sjt_math2044;
    sjt_math2029 = sjt_math2031 + sjt_math2032;
    sjt_math2049 = (_parent)->m00;
    sjt_math2050 = (_parent)->m13;
    sjt_math2047 = sjt_math2049 * sjt_math2050;
    sjt_math2048 = (_parent)->m31;
    sjt_math2030 = sjt_math2047 * sjt_math2048;
    sjt_math2027 = sjt_math2029 - sjt_math2030;
    sjt_math2053 = (_parent)->m01;
    sjt_math2054 = (_parent)->m10;
    sjt_math2051 = sjt_math2053 * sjt_math2054;
    sjt_math2052 = (_parent)->m33;
    sjt_math2028 = sjt_math2051 * sjt_math2052;
    sjt_math2025 = sjt_math2027 - sjt_math2028;
    sjt_math2057 = (_parent)->m00;
    sjt_math2058 = (_parent)->m11;
    sjt_math2055 = sjt_math2057 * sjt_math2058;
    sjt_math2056 = (_parent)->m33;
    sjt_math2026 = sjt_math2055 * sjt_math2056;
    sjv_t.m22 = sjt_math2025 + sjt_math2026;
    sjt_math2071 = (_parent)->m03;
    sjt_math2072 = (_parent)->m11;
    sjt_math2069 = sjt_math2071 * sjt_math2072;
    sjt_math2070 = (_parent)->m20;
    sjt_math2067 = sjt_math2069 * sjt_math2070;
    sjt_math2075 = (_parent)->m01;
    sjt_math2076 = (_parent)->m13;
    sjt_math2073 = sjt_math2075 * sjt_math2076;
    sjt_math2074 = (_parent)->m20;
    sjt_math2068 = sjt_math2073 * sjt_math2074;
    sjt_math2065 = sjt_math2067 - sjt_math2068;
    sjt_math2079 = (_parent)->m03;
    sjt_math2080 = (_parent)->m10;
    sjt_math2077 = sjt_math2079 * sjt_math2080;
    sjt_math2078 = (_parent)->m21;
    sjt_math2066 = sjt_math2077 * sjt_math2078;
    sjt_math2063 = sjt_math2065 - sjt_math2066;
    sjt_math2083 = (_parent)->m00;
    sjt_math2084 = (_parent)->m13;
    sjt_math2081 = sjt_math2083 * sjt_math2084;
    sjt_math2082 = (_parent)->m21;
    sjt_math2064 = sjt_math2081 * sjt_math2082;
    sjt_math2061 = sjt_math2063 + sjt_math2064;
    sjt_math2087 = (_parent)->m01;
    sjt_math2088 = (_parent)->m10;
    sjt_math2085 = sjt_math2087 * sjt_math2088;
    sjt_math2086 = (_parent)->m23;
    sjt_math2062 = sjt_math2085 * sjt_math2086;
    sjt_math2059 = sjt_math2061 + sjt_math2062;
    sjt_math2091 = (_parent)->m00;
    sjt_math2092 = (_parent)->m11;
    sjt_math2089 = sjt_math2091 * sjt_math2092;
    sjt_math2090 = (_parent)->m23;
    sjt_math2060 = sjt_math2089 * sjt_math2090;
    sjv_t.m23 = sjt_math2059 - sjt_math2060;
    sjt_math2105 = (_parent)->m12;
    sjt_math2106 = (_parent)->m21;
    sjt_math2103 = sjt_math2105 * sjt_math2106;
    sjt_math2104 = (_parent)->m30;
    sjt_math2101 = sjt_math2103 * sjt_math2104;
    sjt_math2109 = (_parent)->m11;
    sjt_math2110 = (_parent)->m22;
    sjt_math2107 = sjt_math2109 * sjt_math2110;
    sjt_math2108 = (_parent)->m30;
    sjt_math2102 = sjt_math2107 * sjt_math2108;
    sjt_math2099 = sjt_math2101 - sjt_math2102;
    sjt_math2113 = (_parent)->m12;
    sjt_math2114 = (_parent)->m20;
    sjt_math2111 = sjt_math2113 * sjt_math2114;
    sjt_math2112 = (_parent)->m31;
    sjt_math2100 = sjt_math2111 * sjt_math2112;
    sjt_math2097 = sjt_math2099 - sjt_math2100;
    sjt_math2117 = (_parent)->m10;
    sjt_math2118 = (_parent)->m22;
    sjt_math2115 = sjt_math2117 * sjt_math2118;
    sjt_math2116 = (_parent)->m31;
    sjt_math2098 = sjt_math2115 * sjt_math2116;
    sjt_math2095 = sjt_math2097 + sjt_math2098;
    sjt_math2121 = (_parent)->m11;
    sjt_math2122 = (_parent)->m20;
    sjt_math2119 = sjt_math2121 * sjt_math2122;
    sjt_math2120 = (_parent)->m32;
    sjt_math2096 = sjt_math2119 * sjt_math2120;
    sjt_math2093 = sjt_math2095 + sjt_math2096;
    sjt_math2125 = (_parent)->m10;
    sjt_math2126 = (_parent)->m21;
    sjt_math2123 = sjt_math2125 * sjt_math2126;
    sjt_math2124 = (_parent)->m32;
    sjt_math2094 = sjt_math2123 * sjt_math2124;
    sjv_t.m30 = sjt_math2093 - sjt_math2094;
    sjt_math2139 = (_parent)->m01;
    sjt_math2140 = (_parent)->m22;
    sjt_math2137 = sjt_math2139 * sjt_math2140;
    sjt_math2138 = (_parent)->m30;
    sjt_math2135 = sjt_math2137 * sjt_math2138;
    sjt_math2143 = (_parent)->m02;
    sjt_math2144 = (_parent)->m21;
    sjt_math2141 = sjt_math2143 * sjt_math2144;
    sjt_math2142 = (_parent)->m30;
    sjt_math2136 = sjt_math2141 * sjt_math2142;
    sjt_math2133 = sjt_math2135 - sjt_math2136;
    sjt_math2147 = (_parent)->m02;
    sjt_math2148 = (_parent)->m20;
    sjt_math2145 = sjt_math2147 * sjt_math2148;
    sjt_math2146 = (_parent)->m31;
    sjt_math2134 = sjt_math2145 * sjt_math2146;
    sjt_math2131 = sjt_math2133 + sjt_math2134;
    sjt_math2151 = (_parent)->m00;
    sjt_math2152 = (_parent)->m22;
    sjt_math2149 = sjt_math2151 * sjt_math2152;
    sjt_math2150 = (_parent)->m31;
    sjt_math2132 = sjt_math2149 * sjt_math2150;
    sjt_math2129 = sjt_math2131 - sjt_math2132;
    sjt_math2155 = (_parent)->m01;
    sjt_math2156 = (_parent)->m20;
    sjt_math2153 = sjt_math2155 * sjt_math2156;
    sjt_math2154 = (_parent)->m32;
    sjt_math2130 = sjt_math2153 * sjt_math2154;
    sjt_math2127 = sjt_math2129 - sjt_math2130;
    sjt_math2159 = (_parent)->m00;
    sjt_math2160 = (_parent)->m21;
    sjt_math2157 = sjt_math2159 * sjt_math2160;
    sjt_math2158 = (_parent)->m32;
    sjt_math2128 = sjt_math2157 * sjt_math2158;
    sjv_t.m31 = sjt_math2127 + sjt_math2128;
    sjt_math2173 = (_parent)->m02;
    sjt_math2174 = (_parent)->m11;
    sjt_math2171 = sjt_math2173 * sjt_math2174;
    sjt_math2172 = (_parent)->m30;
    sjt_math2169 = sjt_math2171 * sjt_math2172;
    sjt_math2177 = (_parent)->m01;
    sjt_math2178 = (_parent)->m12;
    sjt_math2175 = sjt_math2177 * sjt_math2178;
    sjt_math2176 = (_parent)->m30;
    sjt_math2170 = sjt_math2175 * sjt_math2176;
    sjt_math2167 = sjt_math2169 - sjt_math2170;
    sjt_math2181 = (_parent)->m02;
    sjt_math2182 = (_parent)->m10;
    sjt_math2179 = sjt_math2181 * sjt_math2182;
    sjt_math2180 = (_parent)->m31;
    sjt_math2168 = sjt_math2179 * sjt_math2180;
    sjt_math2165 = sjt_math2167 - sjt_math2168;
    sjt_math2185 = (_parent)->m00;
    sjt_math2186 = (_parent)->m12;
    sjt_math2183 = sjt_math2185 * sjt_math2186;
    sjt_math2184 = (_parent)->m31;
    sjt_math2166 = sjt_math2183 * sjt_math2184;
    sjt_math2163 = sjt_math2165 + sjt_math2166;
    sjt_math2189 = (_parent)->m01;
    sjt_math2190 = (_parent)->m10;
    sjt_math2187 = sjt_math2189 * sjt_math2190;
    sjt_math2188 = (_parent)->m32;
    sjt_math2164 = sjt_math2187 * sjt_math2188;
    sjt_math2161 = sjt_math2163 + sjt_math2164;
    sjt_math2193 = (_parent)->m00;
    sjt_math2194 = (_parent)->m11;
    sjt_math2191 = sjt_math2193 * sjt_math2194;
    sjt_math2192 = (_parent)->m32;
    sjt_math2162 = sjt_math2191 * sjt_math2192;
    sjv_t.m32 = sjt_math2161 - sjt_math2162;
    sjt_math2207 = (_parent)->m01;
    sjt_math2208 = (_parent)->m12;
    sjt_math2205 = sjt_math2207 * sjt_math2208;
    sjt_math2206 = (_parent)->m20;
    sjt_math2203 = sjt_math2205 * sjt_math2206;
    sjt_math2211 = (_parent)->m02;
    sjt_math2212 = (_parent)->m11;
    sjt_math2209 = sjt_math2211 * sjt_math2212;
    sjt_math2210 = (_parent)->m20;
    sjt_math2204 = sjt_math2209 * sjt_math2210;
    sjt_math2201 = sjt_math2203 - sjt_math2204;
    sjt_math2215 = (_parent)->m02;
    sjt_math2216 = (_parent)->m10;
    sjt_math2213 = sjt_math2215 * sjt_math2216;
    sjt_math2214 = (_parent)->m21;
    sjt_math2202 = sjt_math2213 * sjt_math2214;
    sjt_math2199 = sjt_math2201 + sjt_math2202;
    sjt_math2219 = (_parent)->m00;
    sjt_math2220 = (_parent)->m12;
    sjt_math2217 = sjt_math2219 * sjt_math2220;
    sjt_math2218 = (_parent)->m21;
    sjt_math2200 = sjt_math2217 * sjt_math2218;
    sjt_math2197 = sjt_math2199 - sjt_math2200;
    sjt_math2223 = (_parent)->m01;
    sjt_math2224 = (_parent)->m10;
    sjt_math2221 = sjt_math2223 * sjt_math2224;
    sjt_math2222 = (_parent)->m22;
    sjt_math2198 = sjt_math2221 * sjt_math2222;
    sjt_math2195 = sjt_math2197 - sjt_math2198;
    sjt_math2227 = (_parent)->m00;
    sjt_math2228 = (_parent)->m11;
    sjt_math2225 = sjt_math2227 * sjt_math2228;
    sjt_math2226 = (_parent)->m22;
    sjt_math2196 = sjt_math2225 * sjt_math2226;
    sjv_t.m33 = sjt_math2195 + sjt_math2196;
    sjf_mat4(&sjv_t);
    sjt_dot235 = &sjv_t;
    sjt_math2229 = 1.0f;
    sjf_mat4_determinant(_parent, &sjt_math2230);
    sjt_functionParam58 = sjt_math2229 / sjt_math2230;
    sjf_mat4_multiply_f32_heap(sjt_dot235, sjt_functionParam58, _return);

    sjf_mat4_destroy(&sjv_t);
}

void sjf_mat4_lookAtLH(sjs_vec3* camera, sjs_vec3* target, sjs_vec3* up, sjs_mat4* _return) {
    sjs_vec3 sjt_call1;
    sjs_vec3* sjt_dot25;
    sjs_vec3* sjt_dot32;
    sjs_vec3* sjt_dot33;
    sjs_vec3* sjt_dot34;
    sjs_vec3* sjt_dot47;
    sjs_vec3* sjt_dot48;
    sjs_vec3* sjt_dot49;
    sjs_vec3* sjt_dot50;
    sjs_vec3* sjt_dot51;
    sjs_vec3* sjt_dot52;
    sjs_vec3* sjt_dot53;
    sjs_vec3* sjt_dot54;
    sjs_vec3* sjt_dot55;
    sjs_vec3* sjt_dot56;
    sjs_vec3* sjt_dot57;
    sjs_vec3* sjt_dot61;
    sjs_vec3* sjt_dot62;
    sjs_vec3* sjt_functionParam13;
    sjs_vec3* sjt_functionParam16;
    sjs_vec3* sjt_functionParam17;
    sjs_vec3* sjt_functionParam18;
    sjs_vec3* sjt_functionParam19;
    sjs_vec3* sjt_functionParam20;
    float sjt_math123;
    float sjt_math124;
    float sjt_math135;
    float sjt_math136;
    float sjt_math137;
    float sjt_math138;
    sjs_vec3 sjv_temp;
    sjs_vec3 sjv_xaxis;
    sjs_vec3 sjv_yaxis;
    sjs_vec3 sjv_zaxis;

    sjt_dot25 = target;
    sjt_functionParam13 = camera;
    sjf_vec3_subtract(sjt_dot25, sjt_functionParam13, &sjv_temp);
    sjt_dot32 = &sjv_temp;
    sjf_vec3_normalize(sjt_dot32, &sjv_zaxis);
    sjt_dot34 = up;
    sjt_functionParam16 = &sjv_zaxis;
    sjf_vec3_cross(sjt_dot34, sjt_functionParam16, &sjt_call1);
    sjt_dot33 = &sjt_call1;
    sjf_vec3_normalize(sjt_dot33, &sjv_xaxis);
    sjt_dot47 = &sjv_zaxis;
    sjt_functionParam17 = &sjv_xaxis;
    sjf_vec3_cross(sjt_dot47, sjt_functionParam17, &sjv_yaxis);
    sjt_dot48 = &sjv_xaxis;
    _return->m00 = (sjt_dot48)->x;
    sjt_dot49 = &sjv_yaxis;
    _return->m01 = (sjt_dot49)->x;
    sjt_dot50 = &sjv_zaxis;
    _return->m02 = (sjt_dot50)->x;
    _return->m03 = 0.0f;
    sjt_dot51 = &sjv_xaxis;
    _return->m10 = (sjt_dot51)->y;
    sjt_dot52 = &sjv_yaxis;
    _return->m11 = (sjt_dot52)->y;
    sjt_dot53 = &sjv_zaxis;
    _return->m12 = (sjt_dot53)->y;
    _return->m13 = 0.0f;
    sjt_dot54 = &sjv_xaxis;
    _return->m20 = (sjt_dot54)->z;
    sjt_dot55 = &sjv_yaxis;
    _return->m21 = (sjt_dot55)->z;
    sjt_dot56 = &sjv_zaxis;
    _return->m22 = (sjt_dot56)->z;
    _return->m23 = 0.0f;
    sjt_math123 = 0.0f;
    sjt_dot57 = &sjv_xaxis;
    sjt_functionParam18 = camera;
    sjf_vec3_dot(sjt_dot57, sjt_functionParam18, &sjt_math124);
    _return->m30 = sjt_math123 - sjt_math124;
    sjt_math135 = 0.0f;
    sjt_dot61 = &sjv_yaxis;
    sjt_functionParam19 = camera;
    sjf_vec3_dot(sjt_dot61, sjt_functionParam19, &sjt_math136);
    _return->m31 = sjt_math135 - sjt_math136;
    sjt_math137 = 0.0f;
    sjt_dot62 = &sjv_zaxis;
    sjt_functionParam20 = camera;
    sjf_vec3_dot(sjt_dot62, sjt_functionParam20, &sjt_math138);
    _return->m32 = sjt_math137 - sjt_math138;
    _return->m33 = 1.0f;
    sjf_mat4(_return);

    sjf_vec3_destroy(&sjt_call1);
    sjf_vec3_destroy(&sjv_temp);
    sjf_vec3_destroy(&sjv_xaxis);
    sjf_vec3_destroy(&sjv_yaxis);
    sjf_vec3_destroy(&sjv_zaxis);
}

void sjf_mat4_lookAtLH_heap(sjs_vec3* camera, sjs_vec3* target, sjs_vec3* up, sjs_mat4_heap** _return) {
    sjs_vec3 sjt_call2;
    sjs_vec3* sjt_dot63;
    sjs_vec3* sjt_dot64;
    sjs_vec3* sjt_dot65;
    sjs_vec3* sjt_dot66;
    sjs_vec3* sjt_dot67;
    sjs_vec3* sjt_dot68;
    sjs_vec3* sjt_dot69;
    sjs_vec3* sjt_dot70;
    sjs_vec3* sjt_dot71;
    sjs_vec3* sjt_dot72;
    sjs_vec3* sjt_dot73;
    sjs_vec3* sjt_dot74;
    sjs_vec3* sjt_dot75;
    sjs_vec3* sjt_dot76;
    sjs_vec3* sjt_dot77;
    sjs_vec3* sjt_dot78;
    sjs_vec3* sjt_dot79;
    sjs_vec3* sjt_functionParam21;
    sjs_vec3* sjt_functionParam22;
    sjs_vec3* sjt_functionParam23;
    sjs_vec3* sjt_functionParam24;
    sjs_vec3* sjt_functionParam25;
    sjs_vec3* sjt_functionParam26;
    float sjt_math139;
    float sjt_math140;
    float sjt_math141;
    float sjt_math142;
    float sjt_math143;
    float sjt_math144;
    sjs_vec3 sjv_temp;
    sjs_vec3 sjv_xaxis;
    sjs_vec3 sjv_yaxis;
    sjs_vec3 sjv_zaxis;

    sjt_dot63 = target;
    sjt_functionParam21 = camera;
    sjf_vec3_subtract(sjt_dot63, sjt_functionParam21, &sjv_temp);
    sjt_dot64 = &sjv_temp;
    sjf_vec3_normalize(sjt_dot64, &sjv_zaxis);
    sjt_dot66 = up;
    sjt_functionParam22 = &sjv_zaxis;
    sjf_vec3_cross(sjt_dot66, sjt_functionParam22, &sjt_call2);
    sjt_dot65 = &sjt_call2;
    sjf_vec3_normalize(sjt_dot65, &sjv_xaxis);
    sjt_dot67 = &sjv_zaxis;
    sjt_functionParam23 = &sjv_xaxis;
    sjf_vec3_cross(sjt_dot67, sjt_functionParam23, &sjv_yaxis);
    (*_return) = (sjs_mat4_heap*)malloc(sizeof(sjs_mat4_heap));
    (*_return)->_refCount = 1;
    sjt_dot68 = &sjv_xaxis;
    (*_return)->m00 = (sjt_dot68)->x;
    sjt_dot69 = &sjv_yaxis;
    (*_return)->m01 = (sjt_dot69)->x;
    sjt_dot70 = &sjv_zaxis;
    (*_return)->m02 = (sjt_dot70)->x;
    (*_return)->m03 = 0.0f;
    sjt_dot71 = &sjv_xaxis;
    (*_return)->m10 = (sjt_dot71)->y;
    sjt_dot72 = &sjv_yaxis;
    (*_return)->m11 = (sjt_dot72)->y;
    sjt_dot73 = &sjv_zaxis;
    (*_return)->m12 = (sjt_dot73)->y;
    (*_return)->m13 = 0.0f;
    sjt_dot74 = &sjv_xaxis;
    (*_return)->m20 = (sjt_dot74)->z;
    sjt_dot75 = &sjv_yaxis;
    (*_return)->m21 = (sjt_dot75)->z;
    sjt_dot76 = &sjv_zaxis;
    (*_return)->m22 = (sjt_dot76)->z;
    (*_return)->m23 = 0.0f;
    sjt_math139 = 0.0f;
    sjt_dot77 = &sjv_xaxis;
    sjt_functionParam24 = camera;
    sjf_vec3_dot(sjt_dot77, sjt_functionParam24, &sjt_math140);
    (*_return)->m30 = sjt_math139 - sjt_math140;
    sjt_math141 = 0.0f;
    sjt_dot78 = &sjv_yaxis;
    sjt_functionParam25 = camera;
    sjf_vec3_dot(sjt_dot78, sjt_functionParam25, &sjt_math142);
    (*_return)->m31 = sjt_math141 - sjt_math142;
    sjt_math143 = 0.0f;
    sjt_dot79 = &sjv_zaxis;
    sjt_functionParam26 = camera;
    sjf_vec3_dot(sjt_dot79, sjt_functionParam26, &sjt_math144);
    (*_return)->m32 = sjt_math143 - sjt_math144;
    (*_return)->m33 = 1.0f;
    sjf_mat4_heap((*_return));

    sjf_vec3_destroy(&sjt_call2);
    sjf_vec3_destroy(&sjv_temp);
    sjf_vec3_destroy(&sjv_xaxis);
    sjf_vec3_destroy(&sjv_yaxis);
    sjf_vec3_destroy(&sjv_zaxis);
}

void sjf_mat4_multiply(sjs_mat4* _parent, sjs_mat4* m, sjs_mat4* _return) {
    sjs_mat4* sjt_dot104;
    sjs_mat4* sjt_dot105;
    sjs_mat4* sjt_dot106;
    sjs_mat4* sjt_dot107;
    sjs_mat4* sjt_dot108;
    sjs_mat4* sjt_dot109;
    sjs_mat4* sjt_dot110;
    sjs_mat4* sjt_dot111;
    sjs_mat4* sjt_dot112;
    sjs_mat4* sjt_dot113;
    sjs_mat4* sjt_dot114;
    sjs_mat4* sjt_dot115;
    sjs_mat4* sjt_dot116;
    sjs_mat4* sjt_dot117;
    sjs_mat4* sjt_dot118;
    sjs_mat4* sjt_dot119;
    sjs_mat4* sjt_dot120;
    sjs_mat4* sjt_dot121;
    sjs_mat4* sjt_dot122;
    sjs_mat4* sjt_dot123;
    sjs_mat4* sjt_dot124;
    sjs_mat4* sjt_dot125;
    sjs_mat4* sjt_dot126;
    sjs_mat4* sjt_dot127;
    sjs_mat4* sjt_dot128;
    sjs_mat4* sjt_dot129;
    sjs_mat4* sjt_dot130;
    sjs_mat4* sjt_dot131;
    sjs_mat4* sjt_dot132;
    sjs_mat4* sjt_dot133;
    sjs_mat4* sjt_dot134;
    sjs_mat4* sjt_dot135;
    sjs_mat4* sjt_dot136;
    sjs_mat4* sjt_dot137;
    sjs_mat4* sjt_dot138;
    sjs_mat4* sjt_dot139;
    sjs_mat4* sjt_dot140;
    sjs_mat4* sjt_dot141;
    sjs_mat4* sjt_dot142;
    sjs_mat4* sjt_dot143;
    sjs_mat4* sjt_dot144;
    sjs_mat4* sjt_dot145;
    sjs_mat4* sjt_dot146;
    sjs_mat4* sjt_dot147;
    sjs_mat4* sjt_dot148;
    sjs_mat4* sjt_dot149;
    sjs_mat4* sjt_dot150;
    sjs_mat4* sjt_dot151;
    sjs_mat4* sjt_dot152;
    sjs_mat4* sjt_dot153;
    sjs_mat4* sjt_dot154;
    sjs_mat4* sjt_dot155;
    sjs_mat4* sjt_dot156;
    sjs_mat4* sjt_dot157;
    sjs_mat4* sjt_dot158;
    sjs_mat4* sjt_dot159;
    sjs_mat4* sjt_dot160;
    sjs_mat4* sjt_dot161;
    sjs_mat4* sjt_dot162;
    sjs_mat4* sjt_dot163;
    sjs_mat4* sjt_dot164;
    sjs_mat4* sjt_dot165;
    sjs_mat4* sjt_dot166;
    sjs_mat4* sjt_dot167;
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

    sjt_dot104 = m;
    sjt_math443 = (sjt_dot104)->m00;
    sjt_math444 = (_parent)->m00;
    sjt_math441 = sjt_math443 * sjt_math444;
    sjt_dot105 = m;
    sjt_math445 = (sjt_dot105)->m01;
    sjt_math446 = (_parent)->m10;
    sjt_math442 = sjt_math445 * sjt_math446;
    sjt_math439 = sjt_math441 + sjt_math442;
    sjt_dot106 = m;
    sjt_math447 = (sjt_dot106)->m02;
    sjt_math448 = (_parent)->m20;
    sjt_math440 = sjt_math447 * sjt_math448;
    sjt_math437 = sjt_math439 + sjt_math440;
    sjt_dot107 = m;
    sjt_math449 = (sjt_dot107)->m03;
    sjt_math450 = (_parent)->m30;
    sjt_math438 = sjt_math449 * sjt_math450;
    _return->m00 = sjt_math437 + sjt_math438;
    sjt_dot108 = m;
    sjt_math457 = (sjt_dot108)->m00;
    sjt_math458 = (_parent)->m01;
    sjt_math455 = sjt_math457 * sjt_math458;
    sjt_dot109 = m;
    sjt_math459 = (sjt_dot109)->m01;
    sjt_math460 = (_parent)->m11;
    sjt_math456 = sjt_math459 * sjt_math460;
    sjt_math453 = sjt_math455 + sjt_math456;
    sjt_dot110 = m;
    sjt_math461 = (sjt_dot110)->m02;
    sjt_math462 = (_parent)->m21;
    sjt_math454 = sjt_math461 * sjt_math462;
    sjt_math451 = sjt_math453 + sjt_math454;
    sjt_dot111 = m;
    sjt_math463 = (sjt_dot111)->m03;
    sjt_math464 = (_parent)->m31;
    sjt_math452 = sjt_math463 * sjt_math464;
    _return->m01 = sjt_math451 + sjt_math452;
    sjt_dot112 = m;
    sjt_math471 = (sjt_dot112)->m00;
    sjt_math472 = (_parent)->m02;
    sjt_math469 = sjt_math471 * sjt_math472;
    sjt_dot113 = m;
    sjt_math473 = (sjt_dot113)->m01;
    sjt_math474 = (_parent)->m12;
    sjt_math470 = sjt_math473 * sjt_math474;
    sjt_math467 = sjt_math469 + sjt_math470;
    sjt_dot114 = m;
    sjt_math475 = (sjt_dot114)->m02;
    sjt_math476 = (_parent)->m22;
    sjt_math468 = sjt_math475 * sjt_math476;
    sjt_math465 = sjt_math467 + sjt_math468;
    sjt_dot115 = m;
    sjt_math477 = (sjt_dot115)->m03;
    sjt_math478 = (_parent)->m32;
    sjt_math466 = sjt_math477 * sjt_math478;
    _return->m02 = sjt_math465 + sjt_math466;
    sjt_dot116 = m;
    sjt_math485 = (sjt_dot116)->m00;
    sjt_math486 = (_parent)->m03;
    sjt_math483 = sjt_math485 * sjt_math486;
    sjt_dot117 = m;
    sjt_math487 = (sjt_dot117)->m01;
    sjt_math488 = (_parent)->m13;
    sjt_math484 = sjt_math487 * sjt_math488;
    sjt_math481 = sjt_math483 + sjt_math484;
    sjt_dot118 = m;
    sjt_math489 = (sjt_dot118)->m02;
    sjt_math490 = (_parent)->m23;
    sjt_math482 = sjt_math489 * sjt_math490;
    sjt_math479 = sjt_math481 + sjt_math482;
    sjt_dot119 = m;
    sjt_math491 = (sjt_dot119)->m03;
    sjt_math492 = (_parent)->m33;
    sjt_math480 = sjt_math491 * sjt_math492;
    _return->m03 = sjt_math479 + sjt_math480;
    sjt_dot120 = m;
    sjt_math499 = (sjt_dot120)->m10;
    sjt_math500 = (_parent)->m00;
    sjt_math497 = sjt_math499 * sjt_math500;
    sjt_dot121 = m;
    sjt_math501 = (sjt_dot121)->m11;
    sjt_math502 = (_parent)->m10;
    sjt_math498 = sjt_math501 * sjt_math502;
    sjt_math495 = sjt_math497 + sjt_math498;
    sjt_dot122 = m;
    sjt_math503 = (sjt_dot122)->m12;
    sjt_math504 = (_parent)->m20;
    sjt_math496 = sjt_math503 * sjt_math504;
    sjt_math493 = sjt_math495 + sjt_math496;
    sjt_dot123 = m;
    sjt_math505 = (sjt_dot123)->m13;
    sjt_math506 = (_parent)->m30;
    sjt_math494 = sjt_math505 * sjt_math506;
    _return->m10 = sjt_math493 + sjt_math494;
    sjt_dot124 = m;
    sjt_math513 = (sjt_dot124)->m10;
    sjt_math514 = (_parent)->m01;
    sjt_math511 = sjt_math513 * sjt_math514;
    sjt_dot125 = m;
    sjt_math515 = (sjt_dot125)->m11;
    sjt_math516 = (_parent)->m11;
    sjt_math512 = sjt_math515 * sjt_math516;
    sjt_math509 = sjt_math511 + sjt_math512;
    sjt_dot126 = m;
    sjt_math517 = (sjt_dot126)->m12;
    sjt_math518 = (_parent)->m21;
    sjt_math510 = sjt_math517 * sjt_math518;
    sjt_math507 = sjt_math509 + sjt_math510;
    sjt_dot127 = m;
    sjt_math519 = (sjt_dot127)->m13;
    sjt_math520 = (_parent)->m31;
    sjt_math508 = sjt_math519 * sjt_math520;
    _return->m11 = sjt_math507 + sjt_math508;
    sjt_dot128 = m;
    sjt_math527 = (sjt_dot128)->m10;
    sjt_math528 = (_parent)->m02;
    sjt_math525 = sjt_math527 * sjt_math528;
    sjt_dot129 = m;
    sjt_math529 = (sjt_dot129)->m11;
    sjt_math530 = (_parent)->m12;
    sjt_math526 = sjt_math529 * sjt_math530;
    sjt_math523 = sjt_math525 + sjt_math526;
    sjt_dot130 = m;
    sjt_math531 = (sjt_dot130)->m12;
    sjt_math532 = (_parent)->m22;
    sjt_math524 = sjt_math531 * sjt_math532;
    sjt_math521 = sjt_math523 + sjt_math524;
    sjt_dot131 = m;
    sjt_math533 = (sjt_dot131)->m13;
    sjt_math534 = (_parent)->m32;
    sjt_math522 = sjt_math533 * sjt_math534;
    _return->m12 = sjt_math521 + sjt_math522;
    sjt_dot132 = m;
    sjt_math541 = (sjt_dot132)->m10;
    sjt_math542 = (_parent)->m03;
    sjt_math539 = sjt_math541 * sjt_math542;
    sjt_dot133 = m;
    sjt_math543 = (sjt_dot133)->m11;
    sjt_math544 = (_parent)->m13;
    sjt_math540 = sjt_math543 * sjt_math544;
    sjt_math537 = sjt_math539 + sjt_math540;
    sjt_dot134 = m;
    sjt_math545 = (sjt_dot134)->m12;
    sjt_math546 = (_parent)->m23;
    sjt_math538 = sjt_math545 * sjt_math546;
    sjt_math535 = sjt_math537 + sjt_math538;
    sjt_dot135 = m;
    sjt_math547 = (sjt_dot135)->m13;
    sjt_math548 = (_parent)->m33;
    sjt_math536 = sjt_math547 * sjt_math548;
    _return->m13 = sjt_math535 + sjt_math536;
    sjt_dot136 = m;
    sjt_math555 = (sjt_dot136)->m20;
    sjt_math556 = (_parent)->m00;
    sjt_math553 = sjt_math555 * sjt_math556;
    sjt_dot137 = m;
    sjt_math557 = (sjt_dot137)->m21;
    sjt_math558 = (_parent)->m10;
    sjt_math554 = sjt_math557 * sjt_math558;
    sjt_math551 = sjt_math553 + sjt_math554;
    sjt_dot138 = m;
    sjt_math559 = (sjt_dot138)->m22;
    sjt_math560 = (_parent)->m20;
    sjt_math552 = sjt_math559 * sjt_math560;
    sjt_math549 = sjt_math551 + sjt_math552;
    sjt_dot139 = m;
    sjt_math561 = (sjt_dot139)->m23;
    sjt_math562 = (_parent)->m30;
    sjt_math550 = sjt_math561 * sjt_math562;
    _return->m20 = sjt_math549 + sjt_math550;
    sjt_dot140 = m;
    sjt_math569 = (sjt_dot140)->m20;
    sjt_math570 = (_parent)->m01;
    sjt_math567 = sjt_math569 * sjt_math570;
    sjt_dot141 = m;
    sjt_math571 = (sjt_dot141)->m21;
    sjt_math572 = (_parent)->m11;
    sjt_math568 = sjt_math571 * sjt_math572;
    sjt_math565 = sjt_math567 + sjt_math568;
    sjt_dot142 = m;
    sjt_math573 = (sjt_dot142)->m22;
    sjt_math574 = (_parent)->m21;
    sjt_math566 = sjt_math573 * sjt_math574;
    sjt_math563 = sjt_math565 + sjt_math566;
    sjt_dot143 = m;
    sjt_math575 = (sjt_dot143)->m23;
    sjt_math576 = (_parent)->m31;
    sjt_math564 = sjt_math575 * sjt_math576;
    _return->m21 = sjt_math563 + sjt_math564;
    sjt_dot144 = m;
    sjt_math583 = (sjt_dot144)->m20;
    sjt_math584 = (_parent)->m02;
    sjt_math581 = sjt_math583 * sjt_math584;
    sjt_dot145 = m;
    sjt_math585 = (sjt_dot145)->m21;
    sjt_math586 = (_parent)->m12;
    sjt_math582 = sjt_math585 * sjt_math586;
    sjt_math579 = sjt_math581 + sjt_math582;
    sjt_dot146 = m;
    sjt_math587 = (sjt_dot146)->m22;
    sjt_math588 = (_parent)->m22;
    sjt_math580 = sjt_math587 * sjt_math588;
    sjt_math577 = sjt_math579 + sjt_math580;
    sjt_dot147 = m;
    sjt_math589 = (sjt_dot147)->m23;
    sjt_math590 = (_parent)->m32;
    sjt_math578 = sjt_math589 * sjt_math590;
    _return->m22 = sjt_math577 + sjt_math578;
    sjt_dot148 = m;
    sjt_math597 = (sjt_dot148)->m20;
    sjt_math598 = (_parent)->m03;
    sjt_math595 = sjt_math597 * sjt_math598;
    sjt_dot149 = m;
    sjt_math599 = (sjt_dot149)->m21;
    sjt_math600 = (_parent)->m13;
    sjt_math596 = sjt_math599 * sjt_math600;
    sjt_math593 = sjt_math595 + sjt_math596;
    sjt_dot150 = m;
    sjt_math601 = (sjt_dot150)->m22;
    sjt_math602 = (_parent)->m23;
    sjt_math594 = sjt_math601 * sjt_math602;
    sjt_math591 = sjt_math593 + sjt_math594;
    sjt_dot151 = m;
    sjt_math603 = (sjt_dot151)->m23;
    sjt_math604 = (_parent)->m33;
    sjt_math592 = sjt_math603 * sjt_math604;
    _return->m23 = sjt_math591 + sjt_math592;
    sjt_dot152 = m;
    sjt_math611 = (sjt_dot152)->m30;
    sjt_math612 = (_parent)->m00;
    sjt_math609 = sjt_math611 * sjt_math612;
    sjt_dot153 = m;
    sjt_math613 = (sjt_dot153)->m31;
    sjt_math614 = (_parent)->m10;
    sjt_math610 = sjt_math613 * sjt_math614;
    sjt_math607 = sjt_math609 + sjt_math610;
    sjt_dot154 = m;
    sjt_math615 = (sjt_dot154)->m32;
    sjt_math616 = (_parent)->m20;
    sjt_math608 = sjt_math615 * sjt_math616;
    sjt_math605 = sjt_math607 + sjt_math608;
    sjt_dot155 = m;
    sjt_math617 = (sjt_dot155)->m33;
    sjt_math618 = (_parent)->m30;
    sjt_math606 = sjt_math617 * sjt_math618;
    _return->m30 = sjt_math605 + sjt_math606;
    sjt_dot156 = m;
    sjt_math625 = (sjt_dot156)->m30;
    sjt_math626 = (_parent)->m01;
    sjt_math623 = sjt_math625 * sjt_math626;
    sjt_dot157 = m;
    sjt_math627 = (sjt_dot157)->m31;
    sjt_math628 = (_parent)->m11;
    sjt_math624 = sjt_math627 * sjt_math628;
    sjt_math621 = sjt_math623 + sjt_math624;
    sjt_dot158 = m;
    sjt_math629 = (sjt_dot158)->m32;
    sjt_math630 = (_parent)->m21;
    sjt_math622 = sjt_math629 * sjt_math630;
    sjt_math619 = sjt_math621 + sjt_math622;
    sjt_dot159 = m;
    sjt_math631 = (sjt_dot159)->m33;
    sjt_math632 = (_parent)->m31;
    sjt_math620 = sjt_math631 * sjt_math632;
    _return->m31 = sjt_math619 + sjt_math620;
    sjt_dot160 = m;
    sjt_math639 = (sjt_dot160)->m30;
    sjt_math640 = (_parent)->m02;
    sjt_math637 = sjt_math639 * sjt_math640;
    sjt_dot161 = m;
    sjt_math641 = (sjt_dot161)->m31;
    sjt_math642 = (_parent)->m12;
    sjt_math638 = sjt_math641 * sjt_math642;
    sjt_math635 = sjt_math637 + sjt_math638;
    sjt_dot162 = m;
    sjt_math643 = (sjt_dot162)->m32;
    sjt_math644 = (_parent)->m22;
    sjt_math636 = sjt_math643 * sjt_math644;
    sjt_math633 = sjt_math635 + sjt_math636;
    sjt_dot163 = m;
    sjt_math645 = (sjt_dot163)->m33;
    sjt_math646 = (_parent)->m32;
    sjt_math634 = sjt_math645 * sjt_math646;
    _return->m32 = sjt_math633 + sjt_math634;
    sjt_dot164 = m;
    sjt_math653 = (sjt_dot164)->m30;
    sjt_math654 = (_parent)->m03;
    sjt_math651 = sjt_math653 * sjt_math654;
    sjt_dot165 = m;
    sjt_math655 = (sjt_dot165)->m31;
    sjt_math656 = (_parent)->m13;
    sjt_math652 = sjt_math655 * sjt_math656;
    sjt_math649 = sjt_math651 + sjt_math652;
    sjt_dot166 = m;
    sjt_math657 = (sjt_dot166)->m32;
    sjt_math658 = (_parent)->m23;
    sjt_math650 = sjt_math657 * sjt_math658;
    sjt_math647 = sjt_math649 + sjt_math650;
    sjt_dot167 = m;
    sjt_math659 = (sjt_dot167)->m33;
    sjt_math660 = (_parent)->m33;
    sjt_math648 = sjt_math659 * sjt_math660;
    _return->m33 = sjt_math647 + sjt_math648;
    sjf_mat4(_return);
}

void sjf_mat4_multiply_f32(sjs_mat4* _parent, float x, sjs_mat4* _return) {
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

    sjt_math1429 = (_parent)->m00;
    sjt_math1430 = x;
    _return->m00 = sjt_math1429 * sjt_math1430;
    sjt_math1431 = (_parent)->m01;
    sjt_math1432 = x;
    _return->m01 = sjt_math1431 * sjt_math1432;
    sjt_math1433 = (_parent)->m02;
    sjt_math1434 = x;
    _return->m02 = sjt_math1433 * sjt_math1434;
    sjt_math1435 = (_parent)->m03;
    sjt_math1436 = x;
    _return->m03 = sjt_math1435 * sjt_math1436;
    sjt_math1437 = (_parent)->m10;
    sjt_math1438 = x;
    _return->m10 = sjt_math1437 * sjt_math1438;
    sjt_math1439 = (_parent)->m11;
    sjt_math1440 = x;
    _return->m11 = sjt_math1439 * sjt_math1440;
    sjt_math1441 = (_parent)->m12;
    sjt_math1442 = x;
    _return->m12 = sjt_math1441 * sjt_math1442;
    sjt_math1443 = (_parent)->m13;
    sjt_math1444 = x;
    _return->m13 = sjt_math1443 * sjt_math1444;
    sjt_math1445 = (_parent)->m20;
    sjt_math1446 = x;
    _return->m20 = sjt_math1445 * sjt_math1446;
    sjt_math1447 = (_parent)->m21;
    sjt_math1448 = x;
    _return->m21 = sjt_math1447 * sjt_math1448;
    sjt_math1449 = (_parent)->m22;
    sjt_math1450 = x;
    _return->m22 = sjt_math1449 * sjt_math1450;
    sjt_math1451 = (_parent)->m23;
    sjt_math1452 = x;
    _return->m23 = sjt_math1451 * sjt_math1452;
    sjt_math1453 = (_parent)->m30;
    sjt_math1454 = x;
    _return->m30 = sjt_math1453 * sjt_math1454;
    sjt_math1455 = (_parent)->m31;
    sjt_math1456 = x;
    _return->m31 = sjt_math1455 * sjt_math1456;
    sjt_math1457 = (_parent)->m32;
    sjt_math1458 = x;
    _return->m32 = sjt_math1457 * sjt_math1458;
    sjt_math1459 = (_parent)->m33;
    sjt_math1460 = x;
    _return->m33 = sjt_math1459 * sjt_math1460;
    sjf_mat4(_return);
}

void sjf_mat4_multiply_f32_heap(sjs_mat4* _parent, float x, sjs_mat4_heap** _return) {
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

    (*_return) = (sjs_mat4_heap*)malloc(sizeof(sjs_mat4_heap));
    (*_return)->_refCount = 1;
    sjt_math1461 = (_parent)->m00;
    sjt_math1462 = x;
    (*_return)->m00 = sjt_math1461 * sjt_math1462;
    sjt_math1463 = (_parent)->m01;
    sjt_math1464 = x;
    (*_return)->m01 = sjt_math1463 * sjt_math1464;
    sjt_math1465 = (_parent)->m02;
    sjt_math1466 = x;
    (*_return)->m02 = sjt_math1465 * sjt_math1466;
    sjt_math1467 = (_parent)->m03;
    sjt_math1468 = x;
    (*_return)->m03 = sjt_math1467 * sjt_math1468;
    sjt_math1469 = (_parent)->m10;
    sjt_math1470 = x;
    (*_return)->m10 = sjt_math1469 * sjt_math1470;
    sjt_math1471 = (_parent)->m11;
    sjt_math1472 = x;
    (*_return)->m11 = sjt_math1471 * sjt_math1472;
    sjt_math1473 = (_parent)->m12;
    sjt_math1474 = x;
    (*_return)->m12 = sjt_math1473 * sjt_math1474;
    sjt_math1475 = (_parent)->m13;
    sjt_math1476 = x;
    (*_return)->m13 = sjt_math1475 * sjt_math1476;
    sjt_math1477 = (_parent)->m20;
    sjt_math1478 = x;
    (*_return)->m20 = sjt_math1477 * sjt_math1478;
    sjt_math1479 = (_parent)->m21;
    sjt_math1480 = x;
    (*_return)->m21 = sjt_math1479 * sjt_math1480;
    sjt_math1481 = (_parent)->m22;
    sjt_math1482 = x;
    (*_return)->m22 = sjt_math1481 * sjt_math1482;
    sjt_math1483 = (_parent)->m23;
    sjt_math1484 = x;
    (*_return)->m23 = sjt_math1483 * sjt_math1484;
    sjt_math1485 = (_parent)->m30;
    sjt_math1486 = x;
    (*_return)->m30 = sjt_math1485 * sjt_math1486;
    sjt_math1487 = (_parent)->m31;
    sjt_math1488 = x;
    (*_return)->m31 = sjt_math1487 * sjt_math1488;
    sjt_math1489 = (_parent)->m32;
    sjt_math1490 = x;
    (*_return)->m32 = sjt_math1489 * sjt_math1490;
    sjt_math1491 = (_parent)->m33;
    sjt_math1492 = x;
    (*_return)->m33 = sjt_math1491 * sjt_math1492;
    sjf_mat4_heap((*_return));
}

void sjf_mat4_multiply_heap(sjs_mat4* _parent, sjs_mat4* m, sjs_mat4_heap** _return) {
    sjs_mat4* sjt_dot168;
    sjs_mat4* sjt_dot169;
    sjs_mat4* sjt_dot170;
    sjs_mat4* sjt_dot171;
    sjs_mat4* sjt_dot172;
    sjs_mat4* sjt_dot173;
    sjs_mat4* sjt_dot174;
    sjs_mat4* sjt_dot175;
    sjs_mat4* sjt_dot176;
    sjs_mat4* sjt_dot177;
    sjs_mat4* sjt_dot178;
    sjs_mat4* sjt_dot179;
    sjs_mat4* sjt_dot180;
    sjs_mat4* sjt_dot181;
    sjs_mat4* sjt_dot182;
    sjs_mat4* sjt_dot183;
    sjs_mat4* sjt_dot184;
    sjs_mat4* sjt_dot185;
    sjs_mat4* sjt_dot186;
    sjs_mat4* sjt_dot187;
    sjs_mat4* sjt_dot188;
    sjs_mat4* sjt_dot189;
    sjs_mat4* sjt_dot190;
    sjs_mat4* sjt_dot191;
    sjs_mat4* sjt_dot192;
    sjs_mat4* sjt_dot193;
    sjs_mat4* sjt_dot194;
    sjs_mat4* sjt_dot195;
    sjs_mat4* sjt_dot196;
    sjs_mat4* sjt_dot197;
    sjs_mat4* sjt_dot198;
    sjs_mat4* sjt_dot199;
    sjs_mat4* sjt_dot200;
    sjs_mat4* sjt_dot201;
    sjs_mat4* sjt_dot202;
    sjs_mat4* sjt_dot203;
    sjs_mat4* sjt_dot204;
    sjs_mat4* sjt_dot205;
    sjs_mat4* sjt_dot206;
    sjs_mat4* sjt_dot207;
    sjs_mat4* sjt_dot208;
    sjs_mat4* sjt_dot209;
    sjs_mat4* sjt_dot210;
    sjs_mat4* sjt_dot211;
    sjs_mat4* sjt_dot212;
    sjs_mat4* sjt_dot213;
    sjs_mat4* sjt_dot214;
    sjs_mat4* sjt_dot215;
    sjs_mat4* sjt_dot216;
    sjs_mat4* sjt_dot217;
    sjs_mat4* sjt_dot218;
    sjs_mat4* sjt_dot219;
    sjs_mat4* sjt_dot220;
    sjs_mat4* sjt_dot221;
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

    (*_return) = (sjs_mat4_heap*)malloc(sizeof(sjs_mat4_heap));
    (*_return)->_refCount = 1;
    sjt_dot168 = m;
    sjt_math667 = (sjt_dot168)->m00;
    sjt_math668 = (_parent)->m00;
    sjt_math665 = sjt_math667 * sjt_math668;
    sjt_dot169 = m;
    sjt_math669 = (sjt_dot169)->m01;
    sjt_math670 = (_parent)->m10;
    sjt_math666 = sjt_math669 * sjt_math670;
    sjt_math663 = sjt_math665 + sjt_math666;
    sjt_dot170 = m;
    sjt_math671 = (sjt_dot170)->m02;
    sjt_math672 = (_parent)->m20;
    sjt_math664 = sjt_math671 * sjt_math672;
    sjt_math661 = sjt_math663 + sjt_math664;
    sjt_dot171 = m;
    sjt_math673 = (sjt_dot171)->m03;
    sjt_math674 = (_parent)->m30;
    sjt_math662 = sjt_math673 * sjt_math674;
    (*_return)->m00 = sjt_math661 + sjt_math662;
    sjt_dot172 = m;
    sjt_math681 = (sjt_dot172)->m00;
    sjt_math682 = (_parent)->m01;
    sjt_math679 = sjt_math681 * sjt_math682;
    sjt_dot173 = m;
    sjt_math683 = (sjt_dot173)->m01;
    sjt_math684 = (_parent)->m11;
    sjt_math680 = sjt_math683 * sjt_math684;
    sjt_math677 = sjt_math679 + sjt_math680;
    sjt_dot174 = m;
    sjt_math685 = (sjt_dot174)->m02;
    sjt_math686 = (_parent)->m21;
    sjt_math678 = sjt_math685 * sjt_math686;
    sjt_math675 = sjt_math677 + sjt_math678;
    sjt_dot175 = m;
    sjt_math687 = (sjt_dot175)->m03;
    sjt_math688 = (_parent)->m31;
    sjt_math676 = sjt_math687 * sjt_math688;
    (*_return)->m01 = sjt_math675 + sjt_math676;
    sjt_dot176 = m;
    sjt_math695 = (sjt_dot176)->m00;
    sjt_math696 = (_parent)->m02;
    sjt_math693 = sjt_math695 * sjt_math696;
    sjt_dot177 = m;
    sjt_math697 = (sjt_dot177)->m01;
    sjt_math698 = (_parent)->m12;
    sjt_math694 = sjt_math697 * sjt_math698;
    sjt_math691 = sjt_math693 + sjt_math694;
    sjt_dot178 = m;
    sjt_math699 = (sjt_dot178)->m02;
    sjt_math700 = (_parent)->m22;
    sjt_math692 = sjt_math699 * sjt_math700;
    sjt_math689 = sjt_math691 + sjt_math692;
    sjt_dot179 = m;
    sjt_math701 = (sjt_dot179)->m03;
    sjt_math702 = (_parent)->m32;
    sjt_math690 = sjt_math701 * sjt_math702;
    (*_return)->m02 = sjt_math689 + sjt_math690;
    sjt_dot180 = m;
    sjt_math709 = (sjt_dot180)->m00;
    sjt_math710 = (_parent)->m03;
    sjt_math707 = sjt_math709 * sjt_math710;
    sjt_dot181 = m;
    sjt_math711 = (sjt_dot181)->m01;
    sjt_math712 = (_parent)->m13;
    sjt_math708 = sjt_math711 * sjt_math712;
    sjt_math705 = sjt_math707 + sjt_math708;
    sjt_dot182 = m;
    sjt_math713 = (sjt_dot182)->m02;
    sjt_math714 = (_parent)->m23;
    sjt_math706 = sjt_math713 * sjt_math714;
    sjt_math703 = sjt_math705 + sjt_math706;
    sjt_dot183 = m;
    sjt_math715 = (sjt_dot183)->m03;
    sjt_math716 = (_parent)->m33;
    sjt_math704 = sjt_math715 * sjt_math716;
    (*_return)->m03 = sjt_math703 + sjt_math704;
    sjt_dot184 = m;
    sjt_math723 = (sjt_dot184)->m10;
    sjt_math724 = (_parent)->m00;
    sjt_math721 = sjt_math723 * sjt_math724;
    sjt_dot185 = m;
    sjt_math725 = (sjt_dot185)->m11;
    sjt_math726 = (_parent)->m10;
    sjt_math722 = sjt_math725 * sjt_math726;
    sjt_math719 = sjt_math721 + sjt_math722;
    sjt_dot186 = m;
    sjt_math727 = (sjt_dot186)->m12;
    sjt_math728 = (_parent)->m20;
    sjt_math720 = sjt_math727 * sjt_math728;
    sjt_math717 = sjt_math719 + sjt_math720;
    sjt_dot187 = m;
    sjt_math729 = (sjt_dot187)->m13;
    sjt_math730 = (_parent)->m30;
    sjt_math718 = sjt_math729 * sjt_math730;
    (*_return)->m10 = sjt_math717 + sjt_math718;
    sjt_dot188 = m;
    sjt_math737 = (sjt_dot188)->m10;
    sjt_math738 = (_parent)->m01;
    sjt_math735 = sjt_math737 * sjt_math738;
    sjt_dot189 = m;
    sjt_math739 = (sjt_dot189)->m11;
    sjt_math740 = (_parent)->m11;
    sjt_math736 = sjt_math739 * sjt_math740;
    sjt_math733 = sjt_math735 + sjt_math736;
    sjt_dot190 = m;
    sjt_math741 = (sjt_dot190)->m12;
    sjt_math742 = (_parent)->m21;
    sjt_math734 = sjt_math741 * sjt_math742;
    sjt_math731 = sjt_math733 + sjt_math734;
    sjt_dot191 = m;
    sjt_math743 = (sjt_dot191)->m13;
    sjt_math744 = (_parent)->m31;
    sjt_math732 = sjt_math743 * sjt_math744;
    (*_return)->m11 = sjt_math731 + sjt_math732;
    sjt_dot192 = m;
    sjt_math751 = (sjt_dot192)->m10;
    sjt_math752 = (_parent)->m02;
    sjt_math749 = sjt_math751 * sjt_math752;
    sjt_dot193 = m;
    sjt_math753 = (sjt_dot193)->m11;
    sjt_math754 = (_parent)->m12;
    sjt_math750 = sjt_math753 * sjt_math754;
    sjt_math747 = sjt_math749 + sjt_math750;
    sjt_dot194 = m;
    sjt_math755 = (sjt_dot194)->m12;
    sjt_math756 = (_parent)->m22;
    sjt_math748 = sjt_math755 * sjt_math756;
    sjt_math745 = sjt_math747 + sjt_math748;
    sjt_dot195 = m;
    sjt_math757 = (sjt_dot195)->m13;
    sjt_math758 = (_parent)->m32;
    sjt_math746 = sjt_math757 * sjt_math758;
    (*_return)->m12 = sjt_math745 + sjt_math746;
    sjt_dot196 = m;
    sjt_math765 = (sjt_dot196)->m10;
    sjt_math766 = (_parent)->m03;
    sjt_math763 = sjt_math765 * sjt_math766;
    sjt_dot197 = m;
    sjt_math767 = (sjt_dot197)->m11;
    sjt_math768 = (_parent)->m13;
    sjt_math764 = sjt_math767 * sjt_math768;
    sjt_math761 = sjt_math763 + sjt_math764;
    sjt_dot198 = m;
    sjt_math769 = (sjt_dot198)->m12;
    sjt_math770 = (_parent)->m23;
    sjt_math762 = sjt_math769 * sjt_math770;
    sjt_math759 = sjt_math761 + sjt_math762;
    sjt_dot199 = m;
    sjt_math771 = (sjt_dot199)->m13;
    sjt_math772 = (_parent)->m33;
    sjt_math760 = sjt_math771 * sjt_math772;
    (*_return)->m13 = sjt_math759 + sjt_math760;
    sjt_dot200 = m;
    sjt_math779 = (sjt_dot200)->m20;
    sjt_math780 = (_parent)->m00;
    sjt_math777 = sjt_math779 * sjt_math780;
    sjt_dot201 = m;
    sjt_math781 = (sjt_dot201)->m21;
    sjt_math782 = (_parent)->m10;
    sjt_math778 = sjt_math781 * sjt_math782;
    sjt_math775 = sjt_math777 + sjt_math778;
    sjt_dot202 = m;
    sjt_math783 = (sjt_dot202)->m22;
    sjt_math784 = (_parent)->m20;
    sjt_math776 = sjt_math783 * sjt_math784;
    sjt_math773 = sjt_math775 + sjt_math776;
    sjt_dot203 = m;
    sjt_math785 = (sjt_dot203)->m23;
    sjt_math786 = (_parent)->m30;
    sjt_math774 = sjt_math785 * sjt_math786;
    (*_return)->m20 = sjt_math773 + sjt_math774;
    sjt_dot204 = m;
    sjt_math793 = (sjt_dot204)->m20;
    sjt_math794 = (_parent)->m01;
    sjt_math791 = sjt_math793 * sjt_math794;
    sjt_dot205 = m;
    sjt_math795 = (sjt_dot205)->m21;
    sjt_math796 = (_parent)->m11;
    sjt_math792 = sjt_math795 * sjt_math796;
    sjt_math789 = sjt_math791 + sjt_math792;
    sjt_dot206 = m;
    sjt_math797 = (sjt_dot206)->m22;
    sjt_math798 = (_parent)->m21;
    sjt_math790 = sjt_math797 * sjt_math798;
    sjt_math787 = sjt_math789 + sjt_math790;
    sjt_dot207 = m;
    sjt_math799 = (sjt_dot207)->m23;
    sjt_math800 = (_parent)->m31;
    sjt_math788 = sjt_math799 * sjt_math800;
    (*_return)->m21 = sjt_math787 + sjt_math788;
    sjt_dot208 = m;
    sjt_math807 = (sjt_dot208)->m20;
    sjt_math808 = (_parent)->m02;
    sjt_math805 = sjt_math807 * sjt_math808;
    sjt_dot209 = m;
    sjt_math809 = (sjt_dot209)->m21;
    sjt_math810 = (_parent)->m12;
    sjt_math806 = sjt_math809 * sjt_math810;
    sjt_math803 = sjt_math805 + sjt_math806;
    sjt_dot210 = m;
    sjt_math811 = (sjt_dot210)->m22;
    sjt_math812 = (_parent)->m22;
    sjt_math804 = sjt_math811 * sjt_math812;
    sjt_math801 = sjt_math803 + sjt_math804;
    sjt_dot211 = m;
    sjt_math813 = (sjt_dot211)->m23;
    sjt_math814 = (_parent)->m32;
    sjt_math802 = sjt_math813 * sjt_math814;
    (*_return)->m22 = sjt_math801 + sjt_math802;
    sjt_dot212 = m;
    sjt_math821 = (sjt_dot212)->m20;
    sjt_math822 = (_parent)->m03;
    sjt_math819 = sjt_math821 * sjt_math822;
    sjt_dot213 = m;
    sjt_math823 = (sjt_dot213)->m21;
    sjt_math824 = (_parent)->m13;
    sjt_math820 = sjt_math823 * sjt_math824;
    sjt_math817 = sjt_math819 + sjt_math820;
    sjt_dot214 = m;
    sjt_math825 = (sjt_dot214)->m22;
    sjt_math826 = (_parent)->m23;
    sjt_math818 = sjt_math825 * sjt_math826;
    sjt_math815 = sjt_math817 + sjt_math818;
    sjt_dot215 = m;
    sjt_math827 = (sjt_dot215)->m23;
    sjt_math828 = (_parent)->m33;
    sjt_math816 = sjt_math827 * sjt_math828;
    (*_return)->m23 = sjt_math815 + sjt_math816;
    sjt_dot216 = m;
    sjt_math835 = (sjt_dot216)->m30;
    sjt_math836 = (_parent)->m00;
    sjt_math833 = sjt_math835 * sjt_math836;
    sjt_dot217 = m;
    sjt_math837 = (sjt_dot217)->m31;
    sjt_math838 = (_parent)->m10;
    sjt_math834 = sjt_math837 * sjt_math838;
    sjt_math831 = sjt_math833 + sjt_math834;
    sjt_dot218 = m;
    sjt_math839 = (sjt_dot218)->m32;
    sjt_math840 = (_parent)->m20;
    sjt_math832 = sjt_math839 * sjt_math840;
    sjt_math829 = sjt_math831 + sjt_math832;
    sjt_dot219 = m;
    sjt_math841 = (sjt_dot219)->m33;
    sjt_math842 = (_parent)->m30;
    sjt_math830 = sjt_math841 * sjt_math842;
    (*_return)->m30 = sjt_math829 + sjt_math830;
    sjt_dot220 = m;
    sjt_math849 = (sjt_dot220)->m30;
    sjt_math850 = (_parent)->m01;
    sjt_math847 = sjt_math849 * sjt_math850;
    sjt_dot221 = m;
    sjt_math851 = (sjt_dot221)->m31;
    sjt_math852 = (_parent)->m11;
    sjt_math848 = sjt_math851 * sjt_math852;
    sjt_math845 = sjt_math847 + sjt_math848;
    sjt_dot222 = m;
    sjt_math853 = (sjt_dot222)->m32;
    sjt_math854 = (_parent)->m21;
    sjt_math846 = sjt_math853 * sjt_math854;
    sjt_math843 = sjt_math845 + sjt_math846;
    sjt_dot223 = m;
    sjt_math855 = (sjt_dot223)->m33;
    sjt_math856 = (_parent)->m31;
    sjt_math844 = sjt_math855 * sjt_math856;
    (*_return)->m31 = sjt_math843 + sjt_math844;
    sjt_dot224 = m;
    sjt_math863 = (sjt_dot224)->m30;
    sjt_math864 = (_parent)->m02;
    sjt_math861 = sjt_math863 * sjt_math864;
    sjt_dot225 = m;
    sjt_math865 = (sjt_dot225)->m31;
    sjt_math866 = (_parent)->m12;
    sjt_math862 = sjt_math865 * sjt_math866;
    sjt_math859 = sjt_math861 + sjt_math862;
    sjt_dot226 = m;
    sjt_math867 = (sjt_dot226)->m32;
    sjt_math868 = (_parent)->m22;
    sjt_math860 = sjt_math867 * sjt_math868;
    sjt_math857 = sjt_math859 + sjt_math860;
    sjt_dot227 = m;
    sjt_math869 = (sjt_dot227)->m33;
    sjt_math870 = (_parent)->m32;
    sjt_math858 = sjt_math869 * sjt_math870;
    (*_return)->m32 = sjt_math857 + sjt_math858;
    sjt_dot228 = m;
    sjt_math877 = (sjt_dot228)->m30;
    sjt_math878 = (_parent)->m03;
    sjt_math875 = sjt_math877 * sjt_math878;
    sjt_dot229 = m;
    sjt_math879 = (sjt_dot229)->m31;
    sjt_math880 = (_parent)->m13;
    sjt_math876 = sjt_math879 * sjt_math880;
    sjt_math873 = sjt_math875 + sjt_math876;
    sjt_dot230 = m;
    sjt_math881 = (sjt_dot230)->m32;
    sjt_math882 = (_parent)->m23;
    sjt_math874 = sjt_math881 * sjt_math882;
    sjt_math871 = sjt_math873 + sjt_math874;
    sjt_dot231 = m;
    sjt_math883 = (sjt_dot231)->m33;
    sjt_math884 = (_parent)->m33;
    sjt_math872 = sjt_math883 * sjt_math884;
    (*_return)->m33 = sjt_math871 + sjt_math872;
    sjf_mat4_heap((*_return));
}

void sjf_mat4_orthographic(float left, float right, float bottom, float top, float znear, float zfar, sjs_mat4* _return) {
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

    sjt_math363 = 2.0f;
    sjt_math365 = right;
    sjt_math366 = left;
    sjt_math364 = sjt_math365 - sjt_math366;
    _return->m00 = sjt_math363 / sjt_math364;
    _return->m01 = 0.0f;
    _return->m02 = 0.0f;
    _return->m03 = 0.0f;
    _return->m10 = 0.0f;
    sjt_math367 = 2.0f;
    sjt_math369 = top;
    sjt_math370 = bottom;
    sjt_math368 = sjt_math369 - sjt_math370;
    _return->m11 = sjt_math367 / sjt_math368;
    _return->m12 = 0.0f;
    _return->m13 = 0.0f;
    _return->m20 = 0.0f;
    _return->m21 = 0.0f;
    sjt_math371 = -2.0f;
    sjt_math373 = zfar;
    sjt_math374 = znear;
    sjt_math372 = sjt_math373 - sjt_math374;
    _return->m22 = sjt_math371 / sjt_math372;
    _return->m23 = 0.0f;
    sjt_math375 = 0.0f;
    sjt_math379 = right;
    sjt_math380 = left;
    sjt_math377 = sjt_math379 + sjt_math380;
    sjt_math381 = right;
    sjt_math382 = left;
    sjt_math378 = sjt_math381 - sjt_math382;
    sjt_math376 = sjt_math377 / sjt_math378;
    _return->m30 = sjt_math375 - sjt_math376;
    sjt_math383 = 0.0f;
    sjt_math387 = top;
    sjt_math388 = bottom;
    sjt_math385 = sjt_math387 + sjt_math388;
    sjt_math389 = top;
    sjt_math390 = bottom;
    sjt_math386 = sjt_math389 - sjt_math390;
    sjt_math384 = sjt_math385 / sjt_math386;
    _return->m31 = sjt_math383 - sjt_math384;
    sjt_math391 = 0.0f;
    sjt_math395 = zfar;
    sjt_math396 = znear;
    sjt_math393 = sjt_math395 + sjt_math396;
    sjt_math397 = zfar;
    sjt_math398 = znear;
    sjt_math394 = sjt_math397 - sjt_math398;
    sjt_math392 = sjt_math393 / sjt_math394;
    _return->m32 = sjt_math391 - sjt_math392;
    _return->m33 = 1.0f;
    sjf_mat4(_return);
}

void sjf_mat4_orthographic_heap(float left, float right, float bottom, float top, float znear, float zfar, sjs_mat4_heap** _return) {
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
    float sjt_math427;
    float sjt_math428;
    float sjt_math429;
    float sjt_math430;
    float sjt_math431;
    float sjt_math432;
    float sjt_math433;
    float sjt_math434;

    (*_return) = (sjs_mat4_heap*)malloc(sizeof(sjs_mat4_heap));
    (*_return)->_refCount = 1;
    sjt_math399 = 2.0f;
    sjt_math401 = right;
    sjt_math402 = left;
    sjt_math400 = sjt_math401 - sjt_math402;
    (*_return)->m00 = sjt_math399 / sjt_math400;
    (*_return)->m01 = 0.0f;
    (*_return)->m02 = 0.0f;
    (*_return)->m03 = 0.0f;
    (*_return)->m10 = 0.0f;
    sjt_math403 = 2.0f;
    sjt_math405 = top;
    sjt_math406 = bottom;
    sjt_math404 = sjt_math405 - sjt_math406;
    (*_return)->m11 = sjt_math403 / sjt_math404;
    (*_return)->m12 = 0.0f;
    (*_return)->m13 = 0.0f;
    (*_return)->m20 = 0.0f;
    (*_return)->m21 = 0.0f;
    sjt_math407 = -2.0f;
    sjt_math409 = zfar;
    sjt_math410 = znear;
    sjt_math408 = sjt_math409 - sjt_math410;
    (*_return)->m22 = sjt_math407 / sjt_math408;
    (*_return)->m23 = 0.0f;
    sjt_math411 = 0.0f;
    sjt_math415 = right;
    sjt_math416 = left;
    sjt_math413 = sjt_math415 + sjt_math416;
    sjt_math417 = right;
    sjt_math418 = left;
    sjt_math414 = sjt_math417 - sjt_math418;
    sjt_math412 = sjt_math413 / sjt_math414;
    (*_return)->m30 = sjt_math411 - sjt_math412;
    sjt_math419 = 0.0f;
    sjt_math423 = top;
    sjt_math424 = bottom;
    sjt_math421 = sjt_math423 + sjt_math424;
    sjt_math425 = top;
    sjt_math426 = bottom;
    sjt_math422 = sjt_math425 - sjt_math426;
    sjt_math420 = sjt_math421 / sjt_math422;
    (*_return)->m31 = sjt_math419 - sjt_math420;
    sjt_math427 = 0.0f;
    sjt_math431 = zfar;
    sjt_math432 = znear;
    sjt_math429 = sjt_math431 + sjt_math432;
    sjt_math433 = zfar;
    sjt_math434 = znear;
    sjt_math430 = sjt_math433 - sjt_math434;
    sjt_math428 = sjt_math429 / sjt_math430;
    (*_return)->m32 = sjt_math427 - sjt_math428;
    (*_return)->m33 = 1.0f;
    sjf_mat4_heap((*_return));
}

void sjf_mat4_perspective(float fovy, float aspect, float znear, float zfar, sjs_mat4* _return) {
    float sjt_functionParam7;
    float sjt_math1;
    float sjt_math10;
    float sjt_math11;
    float sjt_math12;
    float sjt_math13;
    float sjt_math14;
    float sjt_math15;
    float sjt_math16;
    float sjt_math17;
    float sjt_math18;
    float sjt_math19;
    float sjt_math2;
    float sjt_math20;
    float sjt_math3;
    float sjt_math4;
    float sjt_math5;
    float sjt_math6;
    float sjt_math7;
    float sjt_math8;
    float sjt_math9;
    float sjv_xscale;
    float sjv_yscale;

    sjt_math1 = 1.0f;
    sjt_math5 = fovy;
    sjt_math6 = 180.0f;
    sjt_math3 = sjt_math5 / sjt_math6;
    sjt_math4 = 2.0f;
    sjt_functionParam7 = sjt_math3 / sjt_math4;
    sjf_f32_tan(sjt_functionParam7, &sjt_math2);
    sjv_yscale = sjt_math1 / sjt_math2;
    sjt_math7 = sjv_yscale;
    sjt_math8 = aspect;
    sjv_xscale = sjt_math7 * sjt_math8;
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
    sjt_math9 = zfar;
    sjt_math11 = zfar;
    sjt_math12 = znear;
    sjt_math10 = sjt_math11 - sjt_math12;
    _return->m22 = sjt_math9 / sjt_math10;
    _return->m23 = 1.0f;
    _return->m30 = 0.0f;
    _return->m31 = 0.0f;
    sjt_math13 = 0.0f;
    sjt_math17 = znear;
    sjt_math18 = zfar;
    sjt_math15 = sjt_math17 * sjt_math18;
    sjt_math19 = zfar;
    sjt_math20 = znear;
    sjt_math16 = sjt_math19 - sjt_math20;
    sjt_math14 = sjt_math15 / sjt_math16;
    _return->m32 = sjt_math13 - sjt_math14;
    _return->m33 = 0.0f;
    sjf_mat4(_return);
}

void sjf_mat4_perspective_heap(float fovy, float aspect, float znear, float zfar, sjs_mat4_heap** _return) {
    float sjt_functionParam8;
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
    float sjt_math37;
    float sjt_math38;
    float sjt_math39;
    float sjt_math40;
    float sjv_xscale;
    float sjv_yscale;

    sjt_math21 = 1.0f;
    sjt_math25 = fovy;
    sjt_math26 = 180.0f;
    sjt_math23 = sjt_math25 / sjt_math26;
    sjt_math24 = 2.0f;
    sjt_functionParam8 = sjt_math23 / sjt_math24;
    sjf_f32_tan(sjt_functionParam8, &sjt_math22);
    sjv_yscale = sjt_math21 / sjt_math22;
    sjt_math27 = sjv_yscale;
    sjt_math28 = aspect;
    sjv_xscale = sjt_math27 * sjt_math28;
    (*_return) = (sjs_mat4_heap*)malloc(sizeof(sjs_mat4_heap));
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
    sjt_math29 = zfar;
    sjt_math31 = zfar;
    sjt_math32 = znear;
    sjt_math30 = sjt_math31 - sjt_math32;
    (*_return)->m22 = sjt_math29 / sjt_math30;
    (*_return)->m23 = 1.0f;
    (*_return)->m30 = 0.0f;
    (*_return)->m31 = 0.0f;
    sjt_math33 = 0.0f;
    sjt_math37 = znear;
    sjt_math38 = zfar;
    sjt_math35 = sjt_math37 * sjt_math38;
    sjt_math39 = zfar;
    sjt_math40 = znear;
    sjt_math36 = sjt_math39 - sjt_math40;
    sjt_math34 = sjt_math35 / sjt_math36;
    (*_return)->m32 = sjt_math33 - sjt_math34;
    (*_return)->m33 = 0.0f;
    sjf_mat4_heap((*_return));
}

void sjf_mat4_rotation(float angle, float x, float y, float z, sjs_mat4* _return) {
    float sjt_functionParam30;
    float sjt_functionParam31;
    float sjt_functionParam32;
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
    float sjt_math183;
    float sjt_math184;
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
    float sjt_math195;
    float sjt_math196;
    float sjt_math197;
    float sjt_math198;
    float sjt_math199;
    float sjt_math200;
    float sjt_math201;
    float sjt_math202;
    float sjt_math203;
    float sjt_math204;
    float sjt_math205;
    float sjt_math206;
    float sjt_math207;
    float sjt_math208;
    float sjt_math209;
    float sjt_math210;
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
    float sjv_c;
    float sjv_norm;
    float sjv_s;
    float sjv_xnorm;
    float sjv_ynorm;
    float sjv_znorm;

    sjt_math149 = sjv_f32_pi;
    sjt_math150 = angle;
    sjt_math147 = sjt_math149 * sjt_math150;
    sjt_math148 = 180.0f;
    sjt_functionParam30 = sjt_math147 / sjt_math148;
    sjf_f32_cos(sjt_functionParam30, &sjv_c);
    sjt_math153 = sjv_f32_pi;
    sjt_math154 = angle;
    sjt_math151 = sjt_math153 * sjt_math154;
    sjt_math152 = 180.0f;
    sjt_functionParam31 = sjt_math151 / sjt_math152;
    sjf_f32_sin(sjt_functionParam31, &sjv_s);
    sjt_math159 = x;
    sjt_math160 = x;
    sjt_math157 = sjt_math159 * sjt_math160;
    sjt_math161 = y;
    sjt_math162 = y;
    sjt_math158 = sjt_math161 * sjt_math162;
    sjt_math155 = sjt_math157 + sjt_math158;
    sjt_math163 = z;
    sjt_math164 = z;
    sjt_math156 = sjt_math163 * sjt_math164;
    sjt_functionParam32 = sjt_math155 + sjt_math156;
    sjf_f32_sqrt(sjt_functionParam32, &sjv_norm);
    sjt_math165 = x;
    sjt_math166 = sjv_norm;
    sjv_xnorm = sjt_math165 / sjt_math166;
    sjt_math167 = y;
    sjt_math168 = sjv_norm;
    sjv_ynorm = sjt_math167 / sjt_math168;
    sjt_math169 = z;
    sjt_math170 = sjv_norm;
    sjv_znorm = sjt_math169 / sjt_math170;
    sjt_math175 = sjv_xnorm;
    sjt_math176 = sjv_xnorm;
    sjt_math173 = sjt_math175 * sjt_math176;
    sjt_math177 = 1.0f;
    sjt_math178 = sjv_c;
    sjt_math174 = sjt_math177 - sjt_math178;
    sjt_math171 = sjt_math173 * sjt_math174;
    sjt_math172 = sjv_c;
    _return->m00 = sjt_math171 + sjt_math172;
    sjt_math183 = sjv_xnorm;
    sjt_math184 = sjv_ynorm;
    sjt_math181 = sjt_math183 * sjt_math184;
    sjt_math185 = 1.0f;
    sjt_math186 = sjv_c;
    sjt_math182 = sjt_math185 - sjt_math186;
    sjt_math179 = sjt_math181 * sjt_math182;
    sjt_math187 = sjv_znorm;
    sjt_math188 = sjv_s;
    sjt_math180 = sjt_math187 * sjt_math188;
    _return->m01 = sjt_math179 + sjt_math180;
    sjt_math193 = sjv_xnorm;
    sjt_math194 = sjv_znorm;
    sjt_math191 = sjt_math193 * sjt_math194;
    sjt_math195 = 1.0f;
    sjt_math196 = sjv_c;
    sjt_math192 = sjt_math195 - sjt_math196;
    sjt_math189 = sjt_math191 * sjt_math192;
    sjt_math197 = sjv_ynorm;
    sjt_math198 = sjv_s;
    sjt_math190 = sjt_math197 * sjt_math198;
    _return->m02 = sjt_math189 - sjt_math190;
    _return->m03 = 0.0f;
    sjt_math203 = sjv_ynorm;
    sjt_math204 = sjv_xnorm;
    sjt_math201 = sjt_math203 * sjt_math204;
    sjt_math205 = 1.0f;
    sjt_math206 = sjv_c;
    sjt_math202 = sjt_math205 - sjt_math206;
    sjt_math199 = sjt_math201 * sjt_math202;
    sjt_math207 = sjv_znorm;
    sjt_math208 = sjv_s;
    sjt_math200 = sjt_math207 * sjt_math208;
    _return->m10 = sjt_math199 - sjt_math200;
    sjt_math213 = sjv_ynorm;
    sjt_math214 = sjv_ynorm;
    sjt_math211 = sjt_math213 * sjt_math214;
    sjt_math215 = 1.0f;
    sjt_math216 = sjv_c;
    sjt_math212 = sjt_math215 - sjt_math216;
    sjt_math209 = sjt_math211 * sjt_math212;
    sjt_math210 = sjv_c;
    _return->m11 = sjt_math209 + sjt_math210;
    sjt_math221 = sjv_ynorm;
    sjt_math222 = sjv_znorm;
    sjt_math219 = sjt_math221 * sjt_math222;
    sjt_math223 = 1.0f;
    sjt_math224 = sjv_c;
    sjt_math220 = sjt_math223 - sjt_math224;
    sjt_math217 = sjt_math219 * sjt_math220;
    sjt_math225 = sjv_xnorm;
    sjt_math226 = sjv_s;
    sjt_math218 = sjt_math225 * sjt_math226;
    _return->m12 = sjt_math217 + sjt_math218;
    _return->m13 = 0.0f;
    sjt_math231 = sjv_znorm;
    sjt_math232 = sjv_xnorm;
    sjt_math229 = sjt_math231 * sjt_math232;
    sjt_math233 = 1.0f;
    sjt_math234 = sjv_c;
    sjt_math230 = sjt_math233 - sjt_math234;
    sjt_math227 = sjt_math229 * sjt_math230;
    sjt_math235 = sjv_ynorm;
    sjt_math236 = sjv_s;
    sjt_math228 = sjt_math235 * sjt_math236;
    _return->m20 = sjt_math227 + sjt_math228;
    sjt_math241 = sjv_znorm;
    sjt_math242 = sjv_ynorm;
    sjt_math239 = sjt_math241 * sjt_math242;
    sjt_math243 = 1.0f;
    sjt_math244 = sjv_c;
    sjt_math240 = sjt_math243 - sjt_math244;
    sjt_math237 = sjt_math239 * sjt_math240;
    sjt_math245 = sjv_xnorm;
    sjt_math246 = sjv_s;
    sjt_math238 = sjt_math245 * sjt_math246;
    _return->m21 = sjt_math237 - sjt_math238;
    sjt_math251 = sjv_znorm;
    sjt_math252 = sjv_znorm;
    sjt_math249 = sjt_math251 * sjt_math252;
    sjt_math253 = 1.0f;
    sjt_math254 = sjv_c;
    sjt_math250 = sjt_math253 - sjt_math254;
    sjt_math247 = sjt_math249 * sjt_math250;
    sjt_math248 = sjv_c;
    _return->m22 = sjt_math247 + sjt_math248;
    _return->m23 = 0.0f;
    _return->m30 = 0.0f;
    _return->m31 = 0.0f;
    _return->m32 = 0.0f;
    _return->m33 = 1.0f;
    sjf_mat4(_return);
}

void sjf_mat4_rotation_heap(float angle, float x, float y, float z, sjs_mat4_heap** _return) {
    float sjt_functionParam33;
    float sjt_functionParam34;
    float sjt_functionParam35;
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
    float sjv_c;
    float sjv_norm;
    float sjv_s;
    float sjv_xnorm;
    float sjv_ynorm;
    float sjv_znorm;

    sjt_math257 = sjv_f32_pi;
    sjt_math258 = angle;
    sjt_math255 = sjt_math257 * sjt_math258;
    sjt_math256 = 180.0f;
    sjt_functionParam33 = sjt_math255 / sjt_math256;
    sjf_f32_cos(sjt_functionParam33, &sjv_c);
    sjt_math261 = sjv_f32_pi;
    sjt_math262 = angle;
    sjt_math259 = sjt_math261 * sjt_math262;
    sjt_math260 = 180.0f;
    sjt_functionParam34 = sjt_math259 / sjt_math260;
    sjf_f32_sin(sjt_functionParam34, &sjv_s);
    sjt_math267 = x;
    sjt_math268 = x;
    sjt_math265 = sjt_math267 * sjt_math268;
    sjt_math269 = y;
    sjt_math270 = y;
    sjt_math266 = sjt_math269 * sjt_math270;
    sjt_math263 = sjt_math265 + sjt_math266;
    sjt_math271 = z;
    sjt_math272 = z;
    sjt_math264 = sjt_math271 * sjt_math272;
    sjt_functionParam35 = sjt_math263 + sjt_math264;
    sjf_f32_sqrt(sjt_functionParam35, &sjv_norm);
    sjt_math273 = x;
    sjt_math274 = sjv_norm;
    sjv_xnorm = sjt_math273 / sjt_math274;
    sjt_math275 = y;
    sjt_math276 = sjv_norm;
    sjv_ynorm = sjt_math275 / sjt_math276;
    sjt_math277 = z;
    sjt_math278 = sjv_norm;
    sjv_znorm = sjt_math277 / sjt_math278;
    (*_return) = (sjs_mat4_heap*)malloc(sizeof(sjs_mat4_heap));
    (*_return)->_refCount = 1;
    sjt_math283 = sjv_xnorm;
    sjt_math284 = sjv_xnorm;
    sjt_math281 = sjt_math283 * sjt_math284;
    sjt_math285 = 1.0f;
    sjt_math286 = sjv_c;
    sjt_math282 = sjt_math285 - sjt_math286;
    sjt_math279 = sjt_math281 * sjt_math282;
    sjt_math280 = sjv_c;
    (*_return)->m00 = sjt_math279 + sjt_math280;
    sjt_math291 = sjv_xnorm;
    sjt_math292 = sjv_ynorm;
    sjt_math289 = sjt_math291 * sjt_math292;
    sjt_math293 = 1.0f;
    sjt_math294 = sjv_c;
    sjt_math290 = sjt_math293 - sjt_math294;
    sjt_math287 = sjt_math289 * sjt_math290;
    sjt_math295 = sjv_znorm;
    sjt_math296 = sjv_s;
    sjt_math288 = sjt_math295 * sjt_math296;
    (*_return)->m01 = sjt_math287 + sjt_math288;
    sjt_math301 = sjv_xnorm;
    sjt_math302 = sjv_znorm;
    sjt_math299 = sjt_math301 * sjt_math302;
    sjt_math303 = 1.0f;
    sjt_math304 = sjv_c;
    sjt_math300 = sjt_math303 - sjt_math304;
    sjt_math297 = sjt_math299 * sjt_math300;
    sjt_math305 = sjv_ynorm;
    sjt_math306 = sjv_s;
    sjt_math298 = sjt_math305 * sjt_math306;
    (*_return)->m02 = sjt_math297 - sjt_math298;
    (*_return)->m03 = 0.0f;
    sjt_math311 = sjv_ynorm;
    sjt_math312 = sjv_xnorm;
    sjt_math309 = sjt_math311 * sjt_math312;
    sjt_math313 = 1.0f;
    sjt_math314 = sjv_c;
    sjt_math310 = sjt_math313 - sjt_math314;
    sjt_math307 = sjt_math309 * sjt_math310;
    sjt_math315 = sjv_znorm;
    sjt_math316 = sjv_s;
    sjt_math308 = sjt_math315 * sjt_math316;
    (*_return)->m10 = sjt_math307 - sjt_math308;
    sjt_math321 = sjv_ynorm;
    sjt_math322 = sjv_ynorm;
    sjt_math319 = sjt_math321 * sjt_math322;
    sjt_math323 = 1.0f;
    sjt_math324 = sjv_c;
    sjt_math320 = sjt_math323 - sjt_math324;
    sjt_math317 = sjt_math319 * sjt_math320;
    sjt_math318 = sjv_c;
    (*_return)->m11 = sjt_math317 + sjt_math318;
    sjt_math329 = sjv_ynorm;
    sjt_math330 = sjv_znorm;
    sjt_math327 = sjt_math329 * sjt_math330;
    sjt_math331 = 1.0f;
    sjt_math332 = sjv_c;
    sjt_math328 = sjt_math331 - sjt_math332;
    sjt_math325 = sjt_math327 * sjt_math328;
    sjt_math333 = sjv_xnorm;
    sjt_math334 = sjv_s;
    sjt_math326 = sjt_math333 * sjt_math334;
    (*_return)->m12 = sjt_math325 + sjt_math326;
    (*_return)->m13 = 0.0f;
    sjt_math339 = sjv_znorm;
    sjt_math340 = sjv_xnorm;
    sjt_math337 = sjt_math339 * sjt_math340;
    sjt_math341 = 1.0f;
    sjt_math342 = sjv_c;
    sjt_math338 = sjt_math341 - sjt_math342;
    sjt_math335 = sjt_math337 * sjt_math338;
    sjt_math343 = sjv_ynorm;
    sjt_math344 = sjv_s;
    sjt_math336 = sjt_math343 * sjt_math344;
    (*_return)->m20 = sjt_math335 + sjt_math336;
    sjt_math349 = sjv_znorm;
    sjt_math350 = sjv_ynorm;
    sjt_math347 = sjt_math349 * sjt_math350;
    sjt_math351 = 1.0f;
    sjt_math352 = sjv_c;
    sjt_math348 = sjt_math351 - sjt_math352;
    sjt_math345 = sjt_math347 * sjt_math348;
    sjt_math353 = sjv_xnorm;
    sjt_math354 = sjv_s;
    sjt_math346 = sjt_math353 * sjt_math354;
    (*_return)->m21 = sjt_math345 - sjt_math346;
    sjt_math359 = sjv_znorm;
    sjt_math360 = sjv_znorm;
    sjt_math357 = sjt_math359 * sjt_math360;
    sjt_math361 = 1.0f;
    sjt_math362 = sjv_c;
    sjt_math358 = sjt_math361 - sjt_math362;
    sjt_math355 = sjt_math357 * sjt_math358;
    sjt_math356 = sjv_c;
    (*_return)->m22 = sjt_math355 + sjt_math356;
    (*_return)->m23 = 0.0f;
    (*_return)->m30 = 0.0f;
    (*_return)->m31 = 0.0f;
    (*_return)->m32 = 0.0f;
    (*_return)->m33 = 1.0f;
    sjf_mat4_heap((*_return));
}

void sjf_mat4_scale(float x, float y, float z, sjs_mat4* _return) {
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

void sjf_mat4_scale_heap(float x, float y, float z, sjs_mat4_heap** _return) {
    (*_return) = (sjs_mat4_heap*)malloc(sizeof(sjs_mat4_heap));
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
    _return->m00 = (_parent)->m00;
    _return->m01 = (_parent)->m10;
    _return->m02 = (_parent)->m20;
    _return->m03 = (_parent)->m30;
    _return->m10 = (_parent)->m01;
    _return->m11 = (_parent)->m11;
    _return->m12 = (_parent)->m21;
    _return->m13 = (_parent)->m31;
    _return->m20 = (_parent)->m02;
    _return->m21 = (_parent)->m12;
    _return->m22 = (_parent)->m22;
    _return->m23 = (_parent)->m32;
    _return->m30 = (_parent)->m03;
    _return->m31 = (_parent)->m13;
    _return->m32 = (_parent)->m23;
    _return->m33 = (_parent)->m33;
    sjf_mat4(_return);
}

void sjf_mat4_transpose_heap(sjs_mat4* _parent, sjs_mat4_heap** _return) {
    (*_return) = (sjs_mat4_heap*)malloc(sizeof(sjs_mat4_heap));
    (*_return)->_refCount = 1;
    (*_return)->m00 = (_parent)->m00;
    (*_return)->m01 = (_parent)->m10;
    (*_return)->m02 = (_parent)->m20;
    (*_return)->m03 = (_parent)->m30;
    (*_return)->m10 = (_parent)->m01;
    (*_return)->m11 = (_parent)->m11;
    (*_return)->m12 = (_parent)->m21;
    (*_return)->m13 = (_parent)->m31;
    (*_return)->m20 = (_parent)->m02;
    (*_return)->m21 = (_parent)->m12;
    (*_return)->m22 = (_parent)->m22;
    (*_return)->m23 = (_parent)->m32;
    (*_return)->m30 = (_parent)->m03;
    (*_return)->m31 = (_parent)->m13;
    (*_return)->m32 = (_parent)->m23;
    (*_return)->m33 = (_parent)->m33;
    sjf_mat4_heap((*_return));
}

void sjf_planeVertexBuffer(float x0, float x1, float y0, float y1, float z0, float s0, float s1, float t0, float t1, sjs_vertexBuffer_vertex_location_texture_normal* _return) {
    sjs_vertex_location_texture_normal sjt_call4;
    sjs_vertex_location_texture_normal sjt_call5;
    sjs_vertex_location_texture_normal sjt_call6;
    sjs_vertex_location_texture_normal sjt_call7;
    int32_t sjt_cast10;
    int32_t sjt_cast11;
    int32_t sjt_functionParam60;
    int32_t sjt_functionParam61;
    int32_t sjt_functionParam62;
    int32_t sjt_functionParam63;
    int32_t sjt_functionParam64;
    int32_t sjt_functionParam65;
    int32_t sjt_functionParam66;
    int32_t sjt_functionParam67;
    int32_t sjt_functionParam68;
    int32_t sjt_functionParam69;
    int32_t sjt_functionParam70;
    int32_t sjt_functionParam71;
    int32_t sjt_functionParam72;
    sjs_vertex_location_texture_normal* sjt_functionParam73;
    int32_t sjt_functionParam74;
    sjs_vertex_location_texture_normal* sjt_functionParam75;
    int32_t sjt_functionParam76;
    sjs_vertex_location_texture_normal* sjt_functionParam77;
    int32_t sjt_functionParam78;
    sjs_vertex_location_texture_normal* sjt_functionParam79;

    sjf_string_copy(&_return->format, &sjv_vertex_location_texture_normal_format);
    _return->indices.size = 6;
    sjt_cast10 = 0;
    _return->indices.data = (uintptr_t)sjt_cast10;
    _return->indices._isGlobal = false;
    sjf_array_i32(&_return->indices);
    sjt_functionParam60 = 0;
    sjt_functionParam61 = 0;
    sjf_array_i32_initAt(&_return->indices, sjt_functionParam60, sjt_functionParam61);
    sjt_functionParam62 = 1;
    sjt_functionParam63 = 1;
    sjf_array_i32_initAt(&_return->indices, sjt_functionParam62, sjt_functionParam63);
    sjt_functionParam64 = 2;
    sjt_functionParam65 = 2;
    sjf_array_i32_initAt(&_return->indices, sjt_functionParam64, sjt_functionParam65);
    sjt_functionParam66 = 3;
    sjt_functionParam67 = 0;
    sjf_array_i32_initAt(&_return->indices, sjt_functionParam66, sjt_functionParam67);
    sjt_functionParam68 = 4;
    sjt_functionParam69 = 2;
    sjf_array_i32_initAt(&_return->indices, sjt_functionParam68, sjt_functionParam69);
    sjt_functionParam70 = 5;
    sjt_functionParam71 = 3;
    sjf_array_i32_initAt(&_return->indices, sjt_functionParam70, sjt_functionParam71);
    _return->vertices.size = 4;
    sjt_cast11 = 0;
    _return->vertices.data = (uintptr_t)sjt_cast11;
    _return->vertices._isGlobal = false;
    sjf_array_vertex_location_texture_normal(&_return->vertices);
    sjt_functionParam72 = 0;
    sjt_call4.location.x = x0;
    sjt_call4.location.y = y0;
    sjt_call4.location.z = z0;
    sjf_vec3(&sjt_call4.location);
    sjt_call4.texture.x = s0;
    sjt_call4.texture.y = t0;
    sjf_vec2(&sjt_call4.texture);
    sjt_call4.normal.x = 0.0f;
    sjt_call4.normal.y = 0.0f;
    sjt_call4.normal.z = -1.0f;
    sjf_vec3(&sjt_call4.normal);
    sjf_vertex_location_texture_normal(&sjt_call4);
    sjt_functionParam73 = &sjt_call4;
    sjf_array_vertex_location_texture_normal_initAt(&_return->vertices, sjt_functionParam72, sjt_functionParam73);
    sjt_functionParam74 = 1;
    sjt_call5.location.x = x0;
    sjt_call5.location.y = y1;
    sjt_call5.location.z = z0;
    sjf_vec3(&sjt_call5.location);
    sjt_call5.texture.x = s0;
    sjt_call5.texture.y = t1;
    sjf_vec2(&sjt_call5.texture);
    sjt_call5.normal.x = 0.0f;
    sjt_call5.normal.y = 0.0f;
    sjt_call5.normal.z = -1.0f;
    sjf_vec3(&sjt_call5.normal);
    sjf_vertex_location_texture_normal(&sjt_call5);
    sjt_functionParam75 = &sjt_call5;
    sjf_array_vertex_location_texture_normal_initAt(&_return->vertices, sjt_functionParam74, sjt_functionParam75);
    sjt_functionParam76 = 2;
    sjt_call6.location.x = x1;
    sjt_call6.location.y = y1;
    sjt_call6.location.z = z0;
    sjf_vec3(&sjt_call6.location);
    sjt_call6.texture.x = s1;
    sjt_call6.texture.y = t1;
    sjf_vec2(&sjt_call6.texture);
    sjt_call6.normal.x = 0.0f;
    sjt_call6.normal.y = 0.0f;
    sjt_call6.normal.z = -1.0f;
    sjf_vec3(&sjt_call6.normal);
    sjf_vertex_location_texture_normal(&sjt_call6);
    sjt_functionParam77 = &sjt_call6;
    sjf_array_vertex_location_texture_normal_initAt(&_return->vertices, sjt_functionParam76, sjt_functionParam77);
    sjt_functionParam78 = 3;
    sjt_call7.location.x = x1;
    sjt_call7.location.y = y0;
    sjt_call7.location.z = z0;
    sjf_vec3(&sjt_call7.location);
    sjt_call7.texture.x = s1;
    sjt_call7.texture.y = t0;
    sjf_vec2(&sjt_call7.texture);
    sjt_call7.normal.x = 0.0f;
    sjt_call7.normal.y = 0.0f;
    sjt_call7.normal.z = -1.0f;
    sjf_vec3(&sjt_call7.normal);
    sjf_vertex_location_texture_normal(&sjt_call7);
    sjt_functionParam79 = &sjt_call7;
    sjf_array_vertex_location_texture_normal_initAt(&_return->vertices, sjt_functionParam78, sjt_functionParam79);
    sjf_vertexBuffer_vertex_location_texture_normal(_return);

    sjf_vertex_location_texture_normal_destroy(&sjt_call4);
    sjf_vertex_location_texture_normal_destroy(&sjt_call5);
    sjf_vertex_location_texture_normal_destroy(&sjt_call6);
    sjf_vertex_location_texture_normal_destroy(&sjt_call7);
}

void sjf_planeVertexBuffer_heap(float x0, float x1, float y0, float y1, float z0, float s0, float s1, float t0, float t1, sjs_vertexBuffer_vertex_location_texture_normal_heap** _return) {
    sjs_vertex_location_texture_normal sjt_call10;
    sjs_vertex_location_texture_normal sjt_call11;
    sjs_vertex_location_texture_normal sjt_call8;
    sjs_vertex_location_texture_normal sjt_call9;
    int32_t sjt_cast12;
    int32_t sjt_cast13;
    int32_t sjt_functionParam80;
    int32_t sjt_functionParam81;
    int32_t sjt_functionParam82;
    int32_t sjt_functionParam83;
    int32_t sjt_functionParam84;
    int32_t sjt_functionParam85;
    int32_t sjt_functionParam86;
    int32_t sjt_functionParam87;
    int32_t sjt_functionParam88;
    int32_t sjt_functionParam89;
    int32_t sjt_functionParam90;
    int32_t sjt_functionParam91;
    int32_t sjt_functionParam92;
    sjs_vertex_location_texture_normal* sjt_functionParam93;
    int32_t sjt_functionParam94;
    sjs_vertex_location_texture_normal* sjt_functionParam95;
    int32_t sjt_functionParam96;
    sjs_vertex_location_texture_normal* sjt_functionParam97;
    int32_t sjt_functionParam98;
    sjs_vertex_location_texture_normal* sjt_functionParam99;

    (*_return) = (sjs_vertexBuffer_vertex_location_texture_normal_heap*)malloc(sizeof(sjs_vertexBuffer_vertex_location_texture_normal_heap));
    (*_return)->_refCount = 1;
    sjf_string_copy(&(*_return)->format, &sjv_vertex_location_texture_normal_format);
    (*_return)->indices.size = 6;
    sjt_cast12 = 0;
    (*_return)->indices.data = (uintptr_t)sjt_cast12;
    (*_return)->indices._isGlobal = false;
    sjf_array_i32(&(*_return)->indices);
    sjt_functionParam80 = 0;
    sjt_functionParam81 = 0;
    sjf_array_i32_initAt(&(*_return)->indices, sjt_functionParam80, sjt_functionParam81);
    sjt_functionParam82 = 1;
    sjt_functionParam83 = 1;
    sjf_array_i32_initAt(&(*_return)->indices, sjt_functionParam82, sjt_functionParam83);
    sjt_functionParam84 = 2;
    sjt_functionParam85 = 2;
    sjf_array_i32_initAt(&(*_return)->indices, sjt_functionParam84, sjt_functionParam85);
    sjt_functionParam86 = 3;
    sjt_functionParam87 = 0;
    sjf_array_i32_initAt(&(*_return)->indices, sjt_functionParam86, sjt_functionParam87);
    sjt_functionParam88 = 4;
    sjt_functionParam89 = 2;
    sjf_array_i32_initAt(&(*_return)->indices, sjt_functionParam88, sjt_functionParam89);
    sjt_functionParam90 = 5;
    sjt_functionParam91 = 3;
    sjf_array_i32_initAt(&(*_return)->indices, sjt_functionParam90, sjt_functionParam91);
    (*_return)->vertices.size = 4;
    sjt_cast13 = 0;
    (*_return)->vertices.data = (uintptr_t)sjt_cast13;
    (*_return)->vertices._isGlobal = false;
    sjf_array_vertex_location_texture_normal(&(*_return)->vertices);
    sjt_functionParam92 = 0;
    sjt_call8.location.x = x0;
    sjt_call8.location.y = y0;
    sjt_call8.location.z = z0;
    sjf_vec3(&sjt_call8.location);
    sjt_call8.texture.x = s0;
    sjt_call8.texture.y = t0;
    sjf_vec2(&sjt_call8.texture);
    sjt_call8.normal.x = 0.0f;
    sjt_call8.normal.y = 0.0f;
    sjt_call8.normal.z = -1.0f;
    sjf_vec3(&sjt_call8.normal);
    sjf_vertex_location_texture_normal(&sjt_call8);
    sjt_functionParam93 = &sjt_call8;
    sjf_array_vertex_location_texture_normal_initAt(&(*_return)->vertices, sjt_functionParam92, sjt_functionParam93);
    sjt_functionParam94 = 1;
    sjt_call9.location.x = x0;
    sjt_call9.location.y = y1;
    sjt_call9.location.z = z0;
    sjf_vec3(&sjt_call9.location);
    sjt_call9.texture.x = s0;
    sjt_call9.texture.y = t1;
    sjf_vec2(&sjt_call9.texture);
    sjt_call9.normal.x = 0.0f;
    sjt_call9.normal.y = 0.0f;
    sjt_call9.normal.z = -1.0f;
    sjf_vec3(&sjt_call9.normal);
    sjf_vertex_location_texture_normal(&sjt_call9);
    sjt_functionParam95 = &sjt_call9;
    sjf_array_vertex_location_texture_normal_initAt(&(*_return)->vertices, sjt_functionParam94, sjt_functionParam95);
    sjt_functionParam96 = 2;
    sjt_call10.location.x = x1;
    sjt_call10.location.y = y1;
    sjt_call10.location.z = z0;
    sjf_vec3(&sjt_call10.location);
    sjt_call10.texture.x = s1;
    sjt_call10.texture.y = t1;
    sjf_vec2(&sjt_call10.texture);
    sjt_call10.normal.x = 0.0f;
    sjt_call10.normal.y = 0.0f;
    sjt_call10.normal.z = -1.0f;
    sjf_vec3(&sjt_call10.normal);
    sjf_vertex_location_texture_normal(&sjt_call10);
    sjt_functionParam97 = &sjt_call10;
    sjf_array_vertex_location_texture_normal_initAt(&(*_return)->vertices, sjt_functionParam96, sjt_functionParam97);
    sjt_functionParam98 = 3;
    sjt_call11.location.x = x1;
    sjt_call11.location.y = y0;
    sjt_call11.location.z = z0;
    sjf_vec3(&sjt_call11.location);
    sjt_call11.texture.x = s1;
    sjt_call11.texture.y = t0;
    sjf_vec2(&sjt_call11.texture);
    sjt_call11.normal.x = 0.0f;
    sjt_call11.normal.y = 0.0f;
    sjt_call11.normal.z = -1.0f;
    sjf_vec3(&sjt_call11.normal);
    sjf_vertex_location_texture_normal(&sjt_call11);
    sjt_functionParam99 = &sjt_call11;
    sjf_array_vertex_location_texture_normal_initAt(&(*_return)->vertices, sjt_functionParam98, sjt_functionParam99);
    sjf_vertexBuffer_vertex_location_texture_normal_heap((*_return));

    sjf_vertex_location_texture_normal_destroy(&sjt_call10);
    sjf_vertex_location_texture_normal_destroy(&sjt_call11);
    sjf_vertex_location_texture_normal_destroy(&sjt_call8);
    sjf_vertex_location_texture_normal_destroy(&sjt_call9);
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
    bool sjt_and13;
    bool sjt_and14;
    bool sjt_and15;
    bool sjt_and16;
    bool sjt_and17;
    bool sjt_and18;
    int32_t sjt_compare21;
    int32_t sjt_compare22;
    int32_t sjt_compare23;
    int32_t sjt_compare24;
    int32_t sjt_compare25;
    int32_t sjt_compare26;
    int32_t sjt_compare27;
    int32_t sjt_compare28;
    sjs_point* sjt_dot291;
    sjs_point* sjt_dot292;
    sjs_point* sjt_dot293;
    sjs_point* sjt_dot294;
    int32_t sjt_math2255;
    int32_t sjt_math2256;
    int32_t sjt_math2257;
    int32_t sjt_math2258;

    sjt_compare21 = (_parent)->x;
    sjt_dot291 = point;
    sjt_compare22 = (sjt_dot291)->x;
    sjt_and13 = sjt_compare21 <= sjt_compare22;
    sjt_compare23 = (_parent)->y;
    sjt_dot292 = point;
    sjt_compare24 = (sjt_dot292)->x;
    sjt_and15 = sjt_compare23 <= sjt_compare24;
    sjt_dot293 = point;
    sjt_compare25 = (sjt_dot293)->x;
    sjt_math2255 = (_parent)->x;
    sjt_math2256 = (_parent)->w;
    sjt_compare26 = sjt_math2255 + sjt_math2256;
    sjt_and17 = sjt_compare25 < sjt_compare26;
    sjt_dot294 = point;
    sjt_compare27 = (sjt_dot294)->y;
    sjt_math2257 = (_parent)->y;
    sjt_math2258 = (_parent)->h;
    sjt_compare28 = sjt_math2257 + sjt_math2258;
    sjt_and18 = sjt_compare27 < sjt_compare28;
    sjt_and16 = sjt_and17 && sjt_and18;
    sjt_and14 = sjt_and15 && sjt_and16;
    (*_return) = sjt_and13 && sjt_and14;
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
    bool sjt_and1;
    bool sjt_and2;
    bool sjt_and3;
    bool sjt_and4;
    bool sjt_and5;
    bool sjt_and6;
    int32_t sjt_compare1;
    int32_t sjt_compare2;
    int32_t sjt_compare3;
    int32_t sjt_compare4;
    int32_t sjt_compare5;
    int32_t sjt_compare6;
    int32_t sjt_compare7;
    int32_t sjt_compare8;
    sjs_rect* sjt_dot19;
    sjs_rect* sjt_dot20;
    sjs_rect* sjt_dot21;
    sjs_rect* sjt_dot22;

    sjt_compare1 = (_parent)->x;
    sjt_dot19 = rect;
    sjt_compare2 = (sjt_dot19)->x;
    sjt_and1 = sjt_compare1 == sjt_compare2;
    sjt_compare3 = (_parent)->y;
    sjt_dot20 = rect;
    sjt_compare4 = (sjt_dot20)->y;
    sjt_and3 = sjt_compare3 == sjt_compare4;
    sjt_compare5 = (_parent)->w;
    sjt_dot21 = rect;
    sjt_compare6 = (sjt_dot21)->w;
    sjt_and5 = sjt_compare5 == sjt_compare6;
    sjt_compare7 = (_parent)->h;
    sjt_dot22 = rect;
    sjt_compare8 = (sjt_dot22)->h;
    sjt_and6 = sjt_compare7 == sjt_compare8;
    sjt_and4 = sjt_and5 && sjt_and6;
    sjt_and2 = sjt_and3 && sjt_and4;
    (*_return) = sjt_and1 && sjt_and2;
}

void sjf_rect_subtractMargin(sjs_rect* _parent, sjs_margin* margin, sjs_rect* _return) {
    sjs_margin* sjt_dot264;
    sjs_margin* sjt_dot265;
    sjs_margin* sjt_dot266;
    sjs_margin* sjt_dot267;
    sjs_margin* sjt_dot268;
    sjs_margin* sjt_dot269;
    int32_t sjt_math2231;
    int32_t sjt_math2232;
    int32_t sjt_math2233;
    int32_t sjt_math2234;
    int32_t sjt_math2235;
    int32_t sjt_math2236;
    int32_t sjt_math2237;
    int32_t sjt_math2238;
    int32_t sjt_math2239;
    int32_t sjt_math2240;
    int32_t sjt_math2241;
    int32_t sjt_math2242;

    sjt_math2231 = (_parent)->x;
    sjt_dot264 = margin;
    sjt_math2232 = (sjt_dot264)->l;
    _return->x = sjt_math2231 + sjt_math2232;
    sjt_math2233 = (_parent)->y;
    sjt_dot265 = margin;
    sjt_math2234 = (sjt_dot265)->t;
    _return->y = sjt_math2233 + sjt_math2234;
    sjt_math2237 = (_parent)->w;
    sjt_dot266 = margin;
    sjt_math2238 = (sjt_dot266)->l;
    sjt_math2235 = sjt_math2237 - sjt_math2238;
    sjt_dot267 = margin;
    sjt_math2236 = (sjt_dot267)->r;
    _return->w = sjt_math2235 - sjt_math2236;
    sjt_math2241 = (_parent)->h;
    sjt_dot268 = margin;
    sjt_math2242 = (sjt_dot268)->t;
    sjt_math2239 = sjt_math2241 - sjt_math2242;
    sjt_dot269 = margin;
    sjt_math2240 = (sjt_dot269)->b;
    _return->h = sjt_math2239 - sjt_math2240;
    sjf_rect(_return);
}

void sjf_rect_subtractMargin_heap(sjs_rect* _parent, sjs_margin* margin, sjs_rect_heap** _return) {
    sjs_margin* sjt_dot270;
    sjs_margin* sjt_dot271;
    sjs_margin* sjt_dot272;
    sjs_margin* sjt_dot273;
    sjs_margin* sjt_dot274;
    sjs_margin* sjt_dot275;
    int32_t sjt_math2243;
    int32_t sjt_math2244;
    int32_t sjt_math2245;
    int32_t sjt_math2246;
    int32_t sjt_math2247;
    int32_t sjt_math2248;
    int32_t sjt_math2249;
    int32_t sjt_math2250;
    int32_t sjt_math2251;
    int32_t sjt_math2252;
    int32_t sjt_math2253;
    int32_t sjt_math2254;

    (*_return) = (sjs_rect_heap*)malloc(sizeof(sjs_rect_heap));
    (*_return)->_refCount = 1;
    sjt_math2243 = (_parent)->x;
    sjt_dot270 = margin;
    sjt_math2244 = (sjt_dot270)->l;
    (*_return)->x = sjt_math2243 + sjt_math2244;
    sjt_math2245 = (_parent)->y;
    sjt_dot271 = margin;
    sjt_math2246 = (sjt_dot271)->t;
    (*_return)->y = sjt_math2245 + sjt_math2246;
    sjt_math2249 = (_parent)->w;
    sjt_dot272 = margin;
    sjt_math2250 = (sjt_dot272)->l;
    sjt_math2247 = sjt_math2249 - sjt_math2250;
    sjt_dot273 = margin;
    sjt_math2248 = (sjt_dot273)->r;
    (*_return)->w = sjt_math2247 - sjt_math2248;
    sjt_math2253 = (_parent)->h;
    sjt_dot274 = margin;
    sjt_math2254 = (sjt_dot274)->t;
    sjt_math2251 = sjt_math2253 - sjt_math2254;
    sjt_dot275 = margin;
    sjt_math2252 = (sjt_dot275)->b;
    (*_return)->h = sjt_math2251 - sjt_math2252;
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

void sjf_scene2d(sjs_scene2d* _this) {
}

void sjf_scene2dModel(sjs_scene2dModel* _this) {
    int32_t i;
    sjs_size* sjt_dot83;
    sjs_frameBuffer* sjt_dot84;
    sjs_size* sjt_dot85;
    sjs_frameBuffer* sjt_dot86;
    sjs_array_heap_element* sjt_dot87;
    int32_t sjt_forEnd5;
    int32_t sjt_forStart5;
    sjs_rect sjv_rect;

    sjv_rect.x = 0;
    sjv_rect.y = 0;
    sjt_dot84 = &_this->frameBuffer;
    sjt_dot83 = &(sjt_dot84)->size;
    sjv_rect.w = (sjt_dot83)->w;
    sjt_dot86 = &_this->frameBuffer;
    sjt_dot85 = &(sjt_dot86)->size;
    sjv_rect.h = (sjt_dot85)->h;
    sjf_rect(&sjv_rect);
    sjt_forStart5 = 0;
    i = sjt_forStart5;
    sjt_dot87 = &_this->children;
    sjt_forEnd5 = (sjt_dot87)->size;
    while (i < sjt_forEnd5) {
        sjs_array_heap_element* sjt_dot88;
        sji_element* sjt_dot89;
        int32_t sjt_functionParam43;
        sjs_rect* sjt_interfaceParam7;
        sji_element* sjv_child;

        sjt_dot88 = &_this->children;
        sjt_functionParam43 = i;
        sjf_array_heap_element_getAt_heap(sjt_dot88, sjt_functionParam43, &sjv_child);
        sjt_dot89 = sjv_child;
        sjt_interfaceParam7 = &sjv_rect;
        sjt_dot89->setRect((void*)(((char*)sjt_dot89->_parent) + sizeof(intptr_t)), sjt_interfaceParam7);
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
    _interface->render = (void(*)(void*,sjs_scene3dElement*,sjs_mat4*))sjf_scene2dModel_render;

    return _interface;
}

void sjf_scene2dModel_copy(sjs_scene2dModel* _this, sjs_scene2dModel* _from) {
    sjf_vertexBuffer_vertex_location_texture_normal_copy(&_this->vertexBuffer, &_from->vertexBuffer);
    sjf_shader_copy(&_this->shader, &_from->shader);
    sjf_frameBuffer_copy(&_this->frameBuffer, &_from->frameBuffer);
    sjf_array_heap_element_copy(&_this->children, &_from->children);
    sjf_scene2d_copy(&_this->_innerScene, &_from->_innerScene);
}

void sjf_scene2dModel_destroy(sjs_scene2dModel* _this) {
}

void sjf_scene2dModel_heap(sjs_scene2dModel_heap* _this) {
    sjs_frameBuffer* dotTemp1;
    sjs_frameBuffer* dotTemp2;
    sjs_array_heap_element* dotTemp3;
    int32_t i;
    sjs_size* sjt_dot237;
    sjs_frameBuffer* sjt_dot238;
    sjs_size* sjt_dot239;
    sjs_frameBuffer* sjt_dot240;
    sjs_array_heap_element* sjt_dot241;
    int32_t sjt_forEnd7;
    int32_t sjt_forStart7;
    sjs_rect sjv_rect;

    sjv_rect.x = 0;
    sjv_rect.y = 0;
    dotTemp1 = &_this->frameBuffer;
    sjt_dot238 = dotTemp1;
    sjt_dot237 = &(sjt_dot238)->size;
    sjv_rect.w = (sjt_dot237)->w;
    dotTemp2 = &_this->frameBuffer;
    sjt_dot240 = dotTemp2;
    sjt_dot239 = &(sjt_dot240)->size;
    sjv_rect.h = (sjt_dot239)->h;
    sjf_rect(&sjv_rect);
    sjt_forStart7 = 0;
    i = sjt_forStart7;
    dotTemp3 = &_this->children;
    sjt_dot241 = dotTemp3;
    sjt_forEnd7 = (sjt_dot241)->size;
    while (i < sjt_forEnd7) {
        sjs_array_heap_element* dotTemp4;
        sjs_array_heap_element* sjt_dot242;
        sji_element* sjt_dot243;
        int32_t sjt_functionParam59;
        sjs_rect* sjt_interfaceParam9;
        sji_element* sjv_child;

        dotTemp4 = &_this->children;
        sjt_dot242 = dotTemp4;
        sjt_functionParam59 = i;
        sjf_array_heap_element_getAt_heap(sjt_dot242, sjt_functionParam59, &sjv_child);
        sjt_dot243 = sjv_child;
        sjt_interfaceParam9 = &sjv_rect;
        sjt_dot243->setRect((void*)(((char*)sjt_dot243->_parent) + sizeof(intptr_t)), sjt_interfaceParam9);
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
    _interface->render = (void(*)(void*,sjs_scene3dElement*,sjs_mat4*))sjf_scene2dModel_render;

    return _interface;
}

void sjf_scene2dModel_render(sjs_scene2dModel* _parent, sjs_scene3dElement* scene3d, sjs_mat4* model) {
    int32_t i;
    sjs_mat4 sjt_call3;
    sjs_scene3dElement* sjt_dot101;
    sjs_mat4* sjt_dot102;
    sjs_scene3dElement* sjt_dot103;
    sjs_mat4* sjt_dot232;
    sjs_mat4* sjt_dot233;
    sjs_vertexBuffer_vertex_location_texture_normal* sjt_dot236;
    sjs_scene2d* sjt_dot90;
    sjs_frameBuffer* sjt_dot96;
    sjs_scene2d* sjt_dot97;
    sjs_array_heap_element* sjt_dot98;
    int32_t sjt_forEnd6;
    int32_t sjt_forStart6;
    sjs_size* sjt_functionParam54;
    sjs_mat4* sjt_functionParam56;
    sjs_mat4 sjv_normalMat;
    sjs_mat4 sjv_viewModel;

    glBindFramebuffer(GL_FRAMEBUFFER, _parent->frameBuffer.frameBufferId);
    sjt_dot90 = &(_parent)->_innerScene;
    sjt_dot96 = &(_parent)->frameBuffer;
    sjt_functionParam54 = &(sjt_dot96)->size;
    sjf_scene2d_setSize(sjt_dot90, sjt_functionParam54);
    sjt_dot97 = &(_parent)->_innerScene;
    sjf_scene2d_clear(sjt_dot97);
    sjt_forStart6 = 0;
    i = sjt_forStart6;
    sjt_dot98 = &(_parent)->children;
    sjt_forEnd6 = (sjt_dot98)->size;
    while (i < sjt_forEnd6) {
        sji_element* sjt_dot100;
        sjs_array_heap_element* sjt_dot99;
        int32_t sjt_functionParam55;
        sjs_scene2d* sjt_interfaceParam8;
        sji_element* sjv_child;

        sjt_dot99 = &(_parent)->children;
        sjt_functionParam55 = i;
        sjf_array_heap_element_getAt_heap(sjt_dot99, sjt_functionParam55, &sjv_child);
        sjt_dot100 = sjv_child;
        sjt_interfaceParam8 = &(_parent)->_innerScene;
        sjt_dot100->render((void*)(((char*)sjt_dot100->_parent) + sizeof(intptr_t)), sjt_interfaceParam8);
        i++;

        sjv_child->_refCount--;
        if (sjv_child->_refCount <= 0) {
            sji_element_destroy(sjv_child);
        }
    }

    glBindFramebuffer(GL_FRAMEBUFFER, 0);
    sjt_dot101 = scene3d;
    sjf_scene3dElement_updateViewport(sjt_dot101);
    sjt_dot103 = scene3d;
    sjt_dot102 = &(sjt_dot103)->view;
    sjt_functionParam56 = model;
    sjf_mat4_multiply(sjt_dot102, sjt_functionParam56, &sjv_viewModel);
    sjt_dot233 = &sjv_viewModel;
    sjf_mat4_invert(sjt_dot233, &sjt_call3);
    sjt_dot232 = &sjt_call3;
    sjf_mat4_transpose(sjt_dot232, &sjv_normalMat);
    glUseProgram(_parent->shader.id);
    glBindTexture(GL_TEXTURE_2D, _parent->frameBuffer.textureId);
    glUniformMatrix4fv(glGetUniformLocation(_parent->shader.id, "viewModel" ), 1, 0, (GLfloat*)&sjv_viewModel);
    glUniformMatrix4fv(glGetUniformLocation(_parent->shader.id, "normalMat" ), 1, 0, (GLfloat*)&sjv_normalMat);
    glUniformMatrix4fv(glGetUniformLocation(_parent->shader.id, "projection" ), 1, 0, (GLfloat*)&scene3d->projection);
    glUniform3fv(glGetUniformLocation(_parent->shader.id, "lightPos" ), 1, (GLfloat*)&scene3d->lightPos);
    glUniform3fv(glGetUniformLocation(_parent->shader.id, "diffuseColor" ), 1, (GLfloat*)&scene3d->diffuseColor);
    glUniform3fv(glGetUniformLocation(_parent->shader.id, "specColor" ), 1, (GLfloat*)&scene3d->specColor);
    sjt_dot236 = &(_parent)->vertexBuffer;
    sjf_vertexBuffer_vertex_location_texture_normal_render(sjt_dot236);

    sjf_mat4_destroy(&sjt_call3);
    sjf_mat4_destroy(&sjv_normalMat);
    sjf_mat4_destroy(&sjv_viewModel);
}

void sjf_scene2d_clear(sjs_scene2d* _parent) {
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
    glEnable( GL_TEXTURE_2D );
    glDisable( GL_DEPTH_TEST );
    sjf_scene2d_updateViewport(_parent);
}

void sjf_scene2d_copy(sjs_scene2d* _this, sjs_scene2d* _from) {
    sjf_size_copy(&_this->_size, &_from->_size);
    sjf_mat4_copy(&_this->model, &_from->model);
    sjf_mat4_copy(&_this->view, &_from->view);
    sjf_mat4_copy(&_this->projection, &_from->projection);
}

void sjf_scene2d_destroy(sjs_scene2d* _this) {
}

void sjf_scene2d_heap(sjs_scene2d_heap* _this) {
}

void sjf_scene2d_setSize(sjs_scene2d* _parent, sjs_size* size) {
    bool result2;
    sjs_size* sjt_dot91;
    sjs_size* sjt_functionParam44;
    bool sjt_ifElse2;
    bool sjt_not2;

    sjt_dot91 = &(_parent)->_size;
    sjt_functionParam44 = size;
    sjf_size_isEqual(sjt_dot91, sjt_functionParam44, &sjt_not2);
    result2 = !sjt_not2;
    sjt_ifElse2 = result2;
    if (sjt_ifElse2) {
        int32_t sjt_cast8;
        int32_t sjt_cast9;
        sjs_size* sjt_dot94;
        sjs_size* sjt_dot95;
        float sjt_functionParam45;
        float sjt_functionParam46;
        float sjt_functionParam47;
        float sjt_functionParam48;
        float sjt_functionParam49;
        float sjt_functionParam50;
        float sjt_functionParam51;
        float sjt_functionParam52;
        float sjt_functionParam53;
        int32_t sjt_math435;
        int32_t sjt_math436;

        sjf_size_copy(&_parent->_size, size);
        sjt_functionParam45 = 0.0f;
        sjt_dot94 = &(_parent)->_size;
        sjt_cast8 = (sjt_dot94)->w;
        sjt_functionParam46 = (float)sjt_cast8;
        sjt_math435 = 0;
        sjt_dot95 = &(_parent)->_size;
        sjt_math436 = (sjt_dot95)->h;
        sjt_cast9 = sjt_math435 - sjt_math436;
        sjt_functionParam47 = (float)sjt_cast9;
        sjt_functionParam48 = 0.0f;
        sjt_functionParam49 = -1.0f;
        sjt_functionParam50 = 1.0f;
        sjf_mat4_orthographic(sjt_functionParam45, sjt_functionParam46, sjt_functionParam47, sjt_functionParam48, sjt_functionParam49, sjt_functionParam50, &_parent->projection);
        sjt_functionParam51 = 1.0f;
        sjt_functionParam52 = -1.0f;
        sjt_functionParam53 = 1.0f;
        sjf_mat4_scale(sjt_functionParam51, sjt_functionParam52, sjt_functionParam53, &_parent->model);
        sjf_mat4_identity(&_parent->view);
    }
}

void sjf_scene2d_updateViewport(sjs_scene2d* _parent) {
    glViewport(0, 0, _parent->_size.w, _parent->_size.h);
}

void sjf_scene3dElement(sjs_scene3dElement* _this) {
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
    sjf_array_heap_model_copy(&_this->children, &_from->children);
    sjf_vec3_copy(&_this->camera, &_from->camera);
    sjf_vec3_copy(&_this->lookAt, &_from->lookAt);
    sjf_vec3_copy(&_this->up, &_from->up);
    _this->fieldOfView = _from->fieldOfView;
    _this->zNear = _from->zNear;
    _this->zFar = _from->zFar;
    sjf_vec3_copy(&_this->lightPos, &_from->lightPos);
    sjf_color_copy(&_this->diffuseColor, &_from->diffuseColor);
    sjf_color_copy(&_this->specColor, &_from->specColor);
    sjf_mat4_copy(&_this->projection, &_from->projection);
    sjf_mat4_copy(&_this->view, &_from->view);
    sjf_rect_copy(&_this->_rect, &_from->_rect);
    _this->_angle = _from->_angle;
    sjf_vertexBuffer_vertex_location_texture_normal_copy(&_this->_cube, &_from->_cube);
}

void sjf_scene3dElement_destroy(sjs_scene3dElement* _this) {
}

void sjf_scene3dElement_fireMouseEvent(sjs_scene3dElement* _parent, sjs_point* point, int32_t eventId) {
}

void sjf_scene3dElement_getChildren(sjs_scene3dElement* _parent, sjs_array_heap_element** _return) {
    (*_return) = 0;
}

void sjf_scene3dElement_getRect(sjs_scene3dElement* _parent, sjs_rect** _return) {
    (*_return) = &(_parent)->_rect;
}

void sjf_scene3dElement_getSize(sjs_scene3dElement* _parent, sjs_size* maxSize, sjs_size* _return) {
    sjs_size* sjt_dot14;
    sjs_size* sjt_dot15;

    sjt_dot14 = maxSize;
    _return->w = (sjt_dot14)->w;
    sjt_dot15 = maxSize;
    _return->h = (sjt_dot15)->h;
    sjf_size(_return);
}

void sjf_scene3dElement_getSize_heap(sjs_scene3dElement* _parent, sjs_size* maxSize, sjs_size_heap** _return) {
    sjs_size* sjt_dot16;
    sjs_size* sjt_dot17;

    (*_return) = (sjs_size_heap*)malloc(sizeof(sjs_size_heap));
    (*_return)->_refCount = 1;
    sjt_dot16 = maxSize;
    (*_return)->w = (sjt_dot16)->w;
    sjt_dot17 = maxSize;
    (*_return)->h = (sjt_dot17)->h;
    sjf_size_heap((*_return));
}

void sjf_scene3dElement_heap(sjs_scene3dElement_heap* _this) {
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
    sjs_array_heap_model* sjt_dot80;
    int32_t sjt_forEnd4;
    int32_t sjt_forStart4;
    float sjt_functionParam36;
    float sjt_functionParam37;
    float sjt_functionParam38;
    float sjt_functionParam39;
    float sjt_math145;
    float sjt_math146;
    sjs_mat4 sjv_model;

    sjt_math145 = (_parent)->_angle;
    sjt_math146 = 0.2f;
    _parent->_angle = sjt_math145 + sjt_math146;
    sjt_functionParam36 = (_parent)->_angle;
    sjt_functionParam37 = 0.0f;
    sjt_functionParam38 = 1.0f;
    sjt_functionParam39 = 0.0f;
    sjf_mat4_rotation(sjt_functionParam36, sjt_functionParam37, sjt_functionParam38, sjt_functionParam39, &sjv_model);
    glEnable( GL_DEPTH_TEST );
    sjt_forStart4 = 0;
    i = sjt_forStart4;
    sjt_dot80 = &(_parent)->children;
    sjt_forEnd4 = (sjt_dot80)->size;
    while (i < sjt_forEnd4) {
        sjs_array_heap_model* sjt_dot81;
        sji_scene3dElement_model* sjt_dot82;
        int32_t sjt_functionParam40;
        sjs_scene3dElement* sjt_interfaceParam5;
        sjs_mat4* sjt_interfaceParam6;
        sji_scene3dElement_model* sjv_child;

        sjt_dot81 = &(_parent)->children;
        sjt_functionParam40 = i;
        sjf_array_heap_model_getAt_heap(sjt_dot81, sjt_functionParam40, &sjv_child);
        sjt_dot82 = sjv_child;
        sjt_interfaceParam5 = _parent;
        sjt_interfaceParam6 = &sjv_model;
        sjt_dot82->render((void*)(((char*)sjt_dot82->_parent) + sizeof(intptr_t)), sjt_interfaceParam5, sjt_interfaceParam6);
        i++;

        sjv_child->_refCount--;
        if (sjv_child->_refCount <= 0) {
            sji_scene3dElement_model_destroy(sjv_child);
        }
    }

    glDisable( GL_DEPTH_TEST );

    sjf_mat4_destroy(&sjv_model);
}

void sjf_scene3dElement_setRect(sjs_scene3dElement* _parent, sjs_rect* rect_) {
    bool result1;
    sjs_rect* sjt_dot18;
    sjs_rect* sjt_functionParam6;
    bool sjt_ifElse1;
    bool sjt_not1;

    sjt_dot18 = &(_parent)->_rect;
    sjt_functionParam6 = rect_;
    sjf_rect_isEqual(sjt_dot18, sjt_functionParam6, &sjt_not1);
    result1 = !sjt_not1;
    sjt_ifElse1 = result1;
    if (sjt_ifElse1) {
        int32_t sjt_cast4;
        int32_t sjt_cast5;
        sjs_rect* sjt_dot23;
        sjs_rect* sjt_dot24;
        float sjt_functionParam10;
        float sjt_functionParam11;
        float sjt_functionParam12;
        sjs_vec3* sjt_functionParam27;
        sjs_vec3* sjt_functionParam28;
        sjs_vec3* sjt_functionParam29;
        float sjt_functionParam9;
        float sjt_math41;
        float sjt_math42;

        sjf_rect_copy(&_parent->_rect, rect_);
        sjt_functionParam9 = (_parent)->fieldOfView;
        sjt_dot23 = &(_parent)->_rect;
        sjt_cast4 = (sjt_dot23)->h;
        sjt_math41 = (float)sjt_cast4;
        sjt_dot24 = &(_parent)->_rect;
        sjt_cast5 = (sjt_dot24)->w;
        sjt_math42 = (float)sjt_cast5;
        sjt_functionParam10 = sjt_math41 / sjt_math42;
        sjt_functionParam11 = (_parent)->zNear;
        sjt_functionParam12 = (_parent)->zFar;
        sjf_mat4_perspective(sjt_functionParam9, sjt_functionParam10, sjt_functionParam11, sjt_functionParam12, &_parent->projection);
        sjt_functionParam27 = &(_parent)->camera;
        sjt_functionParam28 = &(_parent)->lookAt;
        sjt_functionParam29 = &(_parent)->up;
        sjf_mat4_lookAtLH(sjt_functionParam27, sjt_functionParam28, sjt_functionParam29, &_parent->view);
    }
}

void sjf_scene3dElement_updateViewport(sjs_scene3dElement* _parent) {
    glViewport(_parent->_rect.x, _parent->_rect.y, _parent->_rect.w, _parent->_rect.h);
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

void sjf_size_isEqual(sjs_size* _parent, sjs_size* size, bool* _return) {
    bool sjt_and7;
    bool sjt_and8;
    int32_t sjt_compare10;
    int32_t sjt_compare11;
    int32_t sjt_compare12;
    int32_t sjt_compare9;
    sjs_size* sjt_dot92;
    sjs_size* sjt_dot93;

    sjt_compare9 = (_parent)->w;
    sjt_dot92 = size;
    sjt_compare10 = (sjt_dot92)->w;
    sjt_and7 = sjt_compare9 == sjt_compare10;
    sjt_compare11 = (_parent)->h;
    sjt_dot93 = size;
    sjt_compare12 = (sjt_dot93)->h;
    sjt_and8 = sjt_compare11 == sjt_compare12;
    (*_return) = sjt_and7 && sjt_and8;
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
    sjs_size* sjt_dot247;
    sjs_size* sjt_dot248;

    sjt_dot247 = &(_parent)->size;
    _return->w = (sjt_dot247)->w;
    sjt_dot248 = &(_parent)->size;
    _return->h = (sjt_dot248)->h;
    sjf_size(_return);
}

void sjf_texture_getSize_heap(sjs_texture* _parent, sjs_size_heap** _return) {
    sjs_size* sjt_dot249;
    sjs_size* sjt_dot250;

    (*_return) = (sjs_size_heap*)malloc(sizeof(sjs_size_heap));
    (*_return)->_refCount = 1;
    sjt_dot249 = &(_parent)->size;
    (*_return)->w = (sjt_dot249)->w;
    sjt_dot250 = &(_parent)->size;
    (*_return)->h = (sjt_dot250)->h;
    sjf_size_heap((*_return));
}

void sjf_texture_heap(sjs_texture_heap* _this) {
}

void sjf_vec2(sjs_vec2* _this) {
}

void sjf_vec2_copy(sjs_vec2* _this, sjs_vec2* _from) {
    _this->x = _from->x;
    _this->y = _from->y;
}

void sjf_vec2_destroy(sjs_vec2* _this) {
}

void sjf_vec2_heap(sjs_vec2_heap* _this) {
}

void sjf_vec3(sjs_vec3* _this) {
}

void sjf_vec3_copy(sjs_vec3* _this, sjs_vec3* _from) {
    _this->x = _from->x;
    _this->y = _from->y;
    _this->z = _from->z;
}

void sjf_vec3_cross(sjs_vec3* _parent, sjs_vec3* v, sjs_vec3* _return) {
    sjs_vec3* sjt_dot35;
    sjs_vec3* sjt_dot36;
    sjs_vec3* sjt_dot37;
    sjs_vec3* sjt_dot38;
    sjs_vec3* sjt_dot39;
    sjs_vec3* sjt_dot40;
    float sjt_math100;
    float sjt_math101;
    float sjt_math102;
    float sjt_math103;
    float sjt_math104;
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

    sjt_math89 = (_parent)->y;
    sjt_dot35 = v;
    sjt_math90 = (sjt_dot35)->z;
    sjt_math87 = sjt_math89 * sjt_math90;
    sjt_math91 = (_parent)->z;
    sjt_dot36 = v;
    sjt_math92 = (sjt_dot36)->y;
    sjt_math88 = sjt_math91 * sjt_math92;
    _return->x = sjt_math87 - sjt_math88;
    sjt_math95 = (_parent)->z;
    sjt_dot37 = v;
    sjt_math96 = (sjt_dot37)->x;
    sjt_math93 = sjt_math95 * sjt_math96;
    sjt_math97 = (_parent)->x;
    sjt_dot38 = v;
    sjt_math98 = (sjt_dot38)->z;
    sjt_math94 = sjt_math97 * sjt_math98;
    _return->y = sjt_math93 - sjt_math94;
    sjt_math101 = (_parent)->x;
    sjt_dot39 = v;
    sjt_math102 = (sjt_dot39)->y;
    sjt_math99 = sjt_math101 * sjt_math102;
    sjt_math103 = (_parent)->y;
    sjt_dot40 = v;
    sjt_math104 = (sjt_dot40)->x;
    sjt_math100 = sjt_math103 * sjt_math104;
    _return->z = sjt_math99 - sjt_math100;
    sjf_vec3(_return);
}

void sjf_vec3_cross_heap(sjs_vec3* _parent, sjs_vec3* v, sjs_vec3_heap** _return) {
    sjs_vec3* sjt_dot41;
    sjs_vec3* sjt_dot42;
    sjs_vec3* sjt_dot43;
    sjs_vec3* sjt_dot44;
    sjs_vec3* sjt_dot45;
    sjs_vec3* sjt_dot46;
    float sjt_math105;
    float sjt_math106;
    float sjt_math107;
    float sjt_math108;
    float sjt_math109;
    float sjt_math110;
    float sjt_math111;
    float sjt_math112;
    float sjt_math113;
    float sjt_math114;
    float sjt_math115;
    float sjt_math116;
    float sjt_math117;
    float sjt_math118;
    float sjt_math119;
    float sjt_math120;
    float sjt_math121;
    float sjt_math122;

    (*_return) = (sjs_vec3_heap*)malloc(sizeof(sjs_vec3_heap));
    (*_return)->_refCount = 1;
    sjt_math107 = (_parent)->y;
    sjt_dot41 = v;
    sjt_math108 = (sjt_dot41)->z;
    sjt_math105 = sjt_math107 * sjt_math108;
    sjt_math109 = (_parent)->z;
    sjt_dot42 = v;
    sjt_math110 = (sjt_dot42)->y;
    sjt_math106 = sjt_math109 * sjt_math110;
    (*_return)->x = sjt_math105 - sjt_math106;
    sjt_math113 = (_parent)->z;
    sjt_dot43 = v;
    sjt_math114 = (sjt_dot43)->x;
    sjt_math111 = sjt_math113 * sjt_math114;
    sjt_math115 = (_parent)->x;
    sjt_dot44 = v;
    sjt_math116 = (sjt_dot44)->z;
    sjt_math112 = sjt_math115 * sjt_math116;
    (*_return)->y = sjt_math111 - sjt_math112;
    sjt_math119 = (_parent)->x;
    sjt_dot45 = v;
    sjt_math120 = (sjt_dot45)->y;
    sjt_math117 = sjt_math119 * sjt_math120;
    sjt_math121 = (_parent)->y;
    sjt_dot46 = v;
    sjt_math122 = (sjt_dot46)->x;
    sjt_math118 = sjt_math121 * sjt_math122;
    (*_return)->z = sjt_math117 - sjt_math118;
    sjf_vec3_heap((*_return));
}

void sjf_vec3_destroy(sjs_vec3* _this) {
}

void sjf_vec3_dot(sjs_vec3* _parent, sjs_vec3* v, float* _return) {
    sjs_vec3* sjt_dot58;
    sjs_vec3* sjt_dot59;
    sjs_vec3* sjt_dot60;
    float sjt_math125;
    float sjt_math126;
    float sjt_math127;
    float sjt_math128;
    float sjt_math129;
    float sjt_math130;
    float sjt_math131;
    float sjt_math132;
    float sjt_math133;
    float sjt_math134;

    sjt_math129 = (_parent)->x;
    sjt_dot58 = v;
    sjt_math130 = (sjt_dot58)->x;
    sjt_math127 = sjt_math129 * sjt_math130;
    sjt_math131 = (_parent)->y;
    sjt_dot59 = v;
    sjt_math132 = (sjt_dot59)->y;
    sjt_math128 = sjt_math131 * sjt_math132;
    sjt_math125 = sjt_math127 + sjt_math128;
    sjt_math133 = (_parent)->z;
    sjt_dot60 = v;
    sjt_math134 = (sjt_dot60)->z;
    sjt_math126 = sjt_math133 * sjt_math134;
    (*_return) = sjt_math125 + sjt_math126;
}

void sjf_vec3_heap(sjs_vec3_heap* _this) {
}

void sjf_vec3_normalize(sjs_vec3* _parent, sjs_vec3* _return) {
    float sjt_functionParam14;
    float sjt_math55;
    float sjt_math56;
    float sjt_math57;
    float sjt_math58;
    float sjt_math59;
    float sjt_math60;
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
    float sjv_t;

    sjt_math59 = (_parent)->x;
    sjt_math60 = (_parent)->x;
    sjt_math57 = sjt_math59 * sjt_math60;
    sjt_math61 = (_parent)->y;
    sjt_math62 = (_parent)->y;
    sjt_math58 = sjt_math61 * sjt_math62;
    sjt_math55 = sjt_math57 + sjt_math58;
    sjt_math63 = (_parent)->z;
    sjt_math64 = (_parent)->z;
    sjt_math56 = sjt_math63 * sjt_math64;
    sjt_functionParam14 = sjt_math55 + sjt_math56;
    sjf_f32_sqrt(sjt_functionParam14, &sjv_t);
    sjt_math65 = (_parent)->x;
    sjt_math66 = sjv_t;
    _return->x = sjt_math65 / sjt_math66;
    sjt_math67 = (_parent)->y;
    sjt_math68 = sjv_t;
    _return->y = sjt_math67 / sjt_math68;
    sjt_math69 = (_parent)->z;
    sjt_math70 = sjv_t;
    _return->z = sjt_math69 / sjt_math70;
    sjf_vec3(_return);
}

void sjf_vec3_normalize_heap(sjs_vec3* _parent, sjs_vec3_heap** _return) {
    float sjt_functionParam15;
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
    float sjt_math83;
    float sjt_math84;
    float sjt_math85;
    float sjt_math86;
    float sjv_t;

    sjt_math75 = (_parent)->x;
    sjt_math76 = (_parent)->x;
    sjt_math73 = sjt_math75 * sjt_math76;
    sjt_math77 = (_parent)->y;
    sjt_math78 = (_parent)->y;
    sjt_math74 = sjt_math77 * sjt_math78;
    sjt_math71 = sjt_math73 + sjt_math74;
    sjt_math79 = (_parent)->z;
    sjt_math80 = (_parent)->z;
    sjt_math72 = sjt_math79 * sjt_math80;
    sjt_functionParam15 = sjt_math71 + sjt_math72;
    sjf_f32_sqrt(sjt_functionParam15, &sjv_t);
    (*_return) = (sjs_vec3_heap*)malloc(sizeof(sjs_vec3_heap));
    (*_return)->_refCount = 1;
    sjt_math81 = (_parent)->x;
    sjt_math82 = sjv_t;
    (*_return)->x = sjt_math81 / sjt_math82;
    sjt_math83 = (_parent)->y;
    sjt_math84 = sjv_t;
    (*_return)->y = sjt_math83 / sjt_math84;
    sjt_math85 = (_parent)->z;
    sjt_math86 = sjv_t;
    (*_return)->z = sjt_math85 / sjt_math86;
    sjf_vec3_heap((*_return));
}

void sjf_vec3_subtract(sjs_vec3* _parent, sjs_vec3* v, sjs_vec3* _return) {
    sjs_vec3* sjt_dot26;
    sjs_vec3* sjt_dot27;
    sjs_vec3* sjt_dot28;
    float sjt_math43;
    float sjt_math44;
    float sjt_math45;
    float sjt_math46;
    float sjt_math47;
    float sjt_math48;

    sjt_math43 = (_parent)->x;
    sjt_dot26 = v;
    sjt_math44 = (sjt_dot26)->x;
    _return->x = sjt_math43 - sjt_math44;
    sjt_math45 = (_parent)->y;
    sjt_dot27 = v;
    sjt_math46 = (sjt_dot27)->y;
    _return->y = sjt_math45 - sjt_math46;
    sjt_math47 = (_parent)->z;
    sjt_dot28 = v;
    sjt_math48 = (sjt_dot28)->z;
    _return->z = sjt_math47 - sjt_math48;
    sjf_vec3(_return);
}

void sjf_vec3_subtract_heap(sjs_vec3* _parent, sjs_vec3* v, sjs_vec3_heap** _return) {
    sjs_vec3* sjt_dot29;
    sjs_vec3* sjt_dot30;
    sjs_vec3* sjt_dot31;
    float sjt_math49;
    float sjt_math50;
    float sjt_math51;
    float sjt_math52;
    float sjt_math53;
    float sjt_math54;

    (*_return) = (sjs_vec3_heap*)malloc(sizeof(sjs_vec3_heap));
    (*_return)->_refCount = 1;
    sjt_math49 = (_parent)->x;
    sjt_dot29 = v;
    sjt_math50 = (sjt_dot29)->x;
    (*_return)->x = sjt_math49 - sjt_math50;
    sjt_math51 = (_parent)->y;
    sjt_dot30 = v;
    sjt_math52 = (sjt_dot30)->y;
    (*_return)->y = sjt_math51 - sjt_math52;
    sjt_math53 = (_parent)->z;
    sjt_dot31 = v;
    sjt_math54 = (sjt_dot31)->z;
    (*_return)->z = sjt_math53 - sjt_math54;
    sjf_vec3_heap((*_return));
}

void sjf_vertexBuffer_vertex_location_texture_normal(sjs_vertexBuffer_vertex_location_texture_normal* _this) {
    _this->buffer = vertex_buffer_new((char*)_this->format.data.data);
    vertex_buffer_push_back_indices(_this->buffer, (GLuint*)_this->indices.data, _this->indices.size);
    vertex_buffer_push_back_vertices(_this->buffer, (sjs_vertex_location_texture_normal*)_this->vertices.data, _this->vertices.size);
}

void sjf_vertexBuffer_vertex_location_texture_normal_copy(sjs_vertexBuffer_vertex_location_texture_normal* _this, sjs_vertexBuffer_vertex_location_texture_normal* _from) {
    sjf_string_copy(&_this->format, &_from->format);
    sjf_array_i32_copy(&_this->indices, &_from->indices);
    sjf_array_vertex_location_texture_normal_copy(&_this->vertices, &_from->vertices);
    _this->buffer = _from->buffer;
    _retain(_this->buffer);
}

void sjf_vertexBuffer_vertex_location_texture_normal_destroy(sjs_vertexBuffer_vertex_location_texture_normal* _this) {
    if (_release(_this->buffer)) {
        vertex_buffer_delete(_this->buffer);
    }
}

void sjf_vertexBuffer_vertex_location_texture_normal_heap(sjs_vertexBuffer_vertex_location_texture_normal_heap* _this) {
    _this->buffer = vertex_buffer_new((char*)_this->format.data.data);
    vertex_buffer_push_back_indices(_this->buffer, (GLuint*)_this->indices.data, _this->indices.size);
    vertex_buffer_push_back_vertices(_this->buffer, (sjs_vertex_location_texture_normal*)_this->vertices.data, _this->vertices.size);
}

void sjf_vertexBuffer_vertex_location_texture_normal_render(sjs_vertexBuffer_vertex_location_texture_normal* _parent) {
    vertex_buffer_render(_parent->buffer, GL_TRIANGLES);
}

void sjf_vertex_location_texture_normal(sjs_vertex_location_texture_normal* _this) {
}

void sjf_vertex_location_texture_normal_copy(sjs_vertex_location_texture_normal* _this, sjs_vertex_location_texture_normal* _from) {
    sjf_vec3_copy(&_this->location, &_from->location);
    sjf_vec2_copy(&_this->texture, &_from->texture);
    sjf_vec3_copy(&_this->normal, &_from->normal);
}

void sjf_vertex_location_texture_normal_destroy(sjs_vertex_location_texture_normal* _this) {
}

void sjf_vertex_location_texture_normal_heap(sjs_vertex_location_texture_normal_heap* _this) {
}

void sjf_windowRenderer(sjs_windowRenderer* _this) {
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

void sjf_windowRenderer_copy(sjs_windowRenderer* _this, sjs_windowRenderer* _from) {
    _this->ren = _from->ren;
    _retain(_this->ren);
    _this->win = _from->win;
    _retain(_this->win);
}

void sjf_windowRenderer_destroy(sjs_windowRenderer* _this) {
    if (_release(_this->ren)) {
        SDL_DestroyRenderer(_this->ren);
    }
    if (_release(_this->win)) {
        SDL_DestroyWindow(_this->win);
    }
}

void sjf_windowRenderer_getSize(sjs_windowRenderer* _parent, sjs_size* _return) {
    int32_t sjv_h;
    int32_t sjv_w;

    sjv_w = 0;
    sjv_h = 0;
    SDL_GetRendererOutputSize(_parent->ren, &sjv_w, &sjv_h);
    _return->w = sjv_w;
    _return->h = sjv_h;
    sjf_size(_return);
}

void sjf_windowRenderer_getSize_heap(sjs_windowRenderer* _parent, sjs_size_heap** _return) {
    int32_t sjv_h;
    int32_t sjv_w;

    sjv_w = 0;
    sjv_h = 0;
    SDL_GetRendererOutputSize(_parent->ren, &sjv_w, &sjv_h);
    (*_return) = (sjs_size_heap*)malloc(sizeof(sjs_size_heap));
    (*_return)->_refCount = 1;
    (*_return)->w = sjv_w;
    (*_return)->h = sjv_h;
    sjf_size_heap((*_return));
}

void sjf_windowRenderer_heap(sjs_windowRenderer_heap* _this) {
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

void sjf_windowRenderer_present(sjs_windowRenderer* _parent) {
    SDL_GL_SwapWindow((SDL_Window*)_parent->win);
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
    _this->render = _from->render;
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
    sjv_rootScene._size.w = 0;
    sjv_rootScene._size.h = 0;
    sjf_size(&sjv_rootScene._size);
    sjv_rootScene.model.m00 = 0.0f;
    sjv_rootScene.model.m01 = 0.0f;
    sjv_rootScene.model.m02 = 0.0f;
    sjv_rootScene.model.m03 = 0.0f;
    sjv_rootScene.model.m10 = 0.0f;
    sjv_rootScene.model.m11 = 0.0f;
    sjv_rootScene.model.m12 = 0.0f;
    sjv_rootScene.model.m13 = 0.0f;
    sjv_rootScene.model.m20 = 0.0f;
    sjv_rootScene.model.m21 = 0.0f;
    sjv_rootScene.model.m22 = 0.0f;
    sjv_rootScene.model.m23 = 0.0f;
    sjv_rootScene.model.m30 = 0.0f;
    sjv_rootScene.model.m31 = 0.0f;
    sjv_rootScene.model.m32 = 0.0f;
    sjv_rootScene.model.m33 = 0.0f;
    sjf_mat4(&sjv_rootScene.model);
    sjv_rootScene.view.m00 = 0.0f;
    sjv_rootScene.view.m01 = 0.0f;
    sjv_rootScene.view.m02 = 0.0f;
    sjv_rootScene.view.m03 = 0.0f;
    sjv_rootScene.view.m10 = 0.0f;
    sjv_rootScene.view.m11 = 0.0f;
    sjv_rootScene.view.m12 = 0.0f;
    sjv_rootScene.view.m13 = 0.0f;
    sjv_rootScene.view.m20 = 0.0f;
    sjv_rootScene.view.m21 = 0.0f;
    sjv_rootScene.view.m22 = 0.0f;
    sjv_rootScene.view.m23 = 0.0f;
    sjv_rootScene.view.m30 = 0.0f;
    sjv_rootScene.view.m31 = 0.0f;
    sjv_rootScene.view.m32 = 0.0f;
    sjv_rootScene.view.m33 = 0.0f;
    sjf_mat4(&sjv_rootScene.view);
    sjv_rootScene.projection.m00 = 0.0f;
    sjv_rootScene.projection.m01 = 0.0f;
    sjv_rootScene.projection.m02 = 0.0f;
    sjv_rootScene.projection.m03 = 0.0f;
    sjv_rootScene.projection.m10 = 0.0f;
    sjv_rootScene.projection.m11 = 0.0f;
    sjv_rootScene.projection.m12 = 0.0f;
    sjv_rootScene.projection.m13 = 0.0f;
    sjv_rootScene.projection.m20 = 0.0f;
    sjv_rootScene.projection.m21 = 0.0f;
    sjv_rootScene.projection.m22 = 0.0f;
    sjv_rootScene.projection.m23 = 0.0f;
    sjv_rootScene.projection.m30 = 0.0f;
    sjv_rootScene.projection.m31 = 0.0f;
    sjv_rootScene.projection.m32 = 0.0f;
    sjv_rootScene.projection.m33 = 0.0f;
    sjf_mat4(&sjv_rootScene.projection);
    sjf_scene2d(&sjv_rootScene);
    sjf_anon1(&sjv_console);
    sjf_anon2(&sjv_parse);
    sjf_anon3(&sjv_random);
    sjf_anon4(&sjv_convert);
    sjv_f32_pi = 3.14159265358979323846f;
    sjv_i32_max = (-2147483647 - 1);
    sjv_i32_min = 2147483647;
    sjv_u32_max = (uint32_t)4294967295u;
    sjv_borderPosition.fill = 0;
    sjv_borderPosition.left = 1;
    sjv_borderPosition.right = 2;
    sjv_borderPosition.top = 3;
    sjv_borderPosition.bottom = 4;
    sjf_anon5(&sjv_borderPosition);
    sjv_buttonState.normal = 0;
    sjv_buttonState.hot = 1;
    sjv_buttonState.pressed = 2;
    sjf_anon6(&sjv_buttonState);
    sjf_anon7(&sjv_colors);
    sjv_mouseEvent_move = 0;
    sjv_mouseEvent_up = 1;
    sjv_mouseEvent_down = 2;
    sjv_boxShader.vertex.count = 20;
    sjv_boxShader.vertex.data.size = 21;
    sjv_boxShader.vertex.data.data = (uintptr_t)sjg_string1;
    sjv_boxShader.vertex.data._isGlobal = false;
    sjf_array_char(&sjv_boxShader.vertex.data);
    sjf_string(&sjv_boxShader.vertex);
    sjv_boxShader.pixel.count = 20;
    sjv_boxShader.pixel.data.size = 21;
    sjv_boxShader.pixel.data.data = (uintptr_t)sjg_string2;
    sjv_boxShader.pixel.data._isGlobal = false;
    sjf_array_char(&sjv_boxShader.pixel.data);
    sjf_string(&sjv_boxShader.pixel);
    sjf_shader(&sjv_boxShader);
    sjv_blurHorizontalShader.vertex.count = 24;
    sjv_blurHorizontalShader.vertex.data.size = 25;
    sjv_blurHorizontalShader.vertex.data.data = (uintptr_t)sjg_string3;
    sjv_blurHorizontalShader.vertex.data._isGlobal = false;
    sjf_array_char(&sjv_blurHorizontalShader.vertex.data);
    sjf_string(&sjv_blurHorizontalShader.vertex);
    sjv_blurHorizontalShader.pixel.count = 28;
    sjv_blurHorizontalShader.pixel.data.size = 29;
    sjv_blurHorizontalShader.pixel.data.data = (uintptr_t)sjg_string4;
    sjv_blurHorizontalShader.pixel.data._isGlobal = false;
    sjf_array_char(&sjv_blurHorizontalShader.pixel.data);
    sjf_string(&sjv_blurHorizontalShader.pixel);
    sjf_shader(&sjv_blurHorizontalShader);
    sjv_blurVerticalShader.vertex.count = 24;
    sjv_blurVerticalShader.vertex.data.size = 25;
    sjv_blurVerticalShader.vertex.data.data = (uintptr_t)sjg_string5;
    sjv_blurVerticalShader.vertex.data._isGlobal = false;
    sjf_array_char(&sjv_blurVerticalShader.vertex.data);
    sjf_string(&sjv_blurVerticalShader.vertex);
    sjv_blurVerticalShader.pixel.count = 26;
    sjv_blurVerticalShader.pixel.data.size = 27;
    sjv_blurVerticalShader.pixel.data.data = (uintptr_t)sjg_string6;
    sjv_blurVerticalShader.pixel.data._isGlobal = false;
    sjf_array_char(&sjv_blurVerticalShader.pixel.data);
    sjf_string(&sjv_blurVerticalShader.pixel);
    sjf_shader(&sjv_blurVerticalShader);
    sjv_imageShader.vertex.count = 20;
    sjv_imageShader.vertex.data.size = 21;
    sjv_imageShader.vertex.data.data = (uintptr_t)sjg_string7;
    sjv_imageShader.vertex.data._isGlobal = false;
    sjf_array_char(&sjv_imageShader.vertex.data);
    sjf_string(&sjv_imageShader.vertex);
    sjv_imageShader.pixel.count = 20;
    sjv_imageShader.pixel.data.size = 21;
    sjv_imageShader.pixel.data.data = (uintptr_t)sjg_string8;
    sjv_imageShader.pixel.data._isGlobal = false;
    sjf_array_char(&sjv_imageShader.pixel.data);
    sjf_string(&sjv_imageShader.pixel);
    sjf_shader(&sjv_imageShader);
    sjv_phongColorShader.vertex.count = 26;
    sjv_phongColorShader.vertex.data.size = 27;
    sjv_phongColorShader.vertex.data.data = (uintptr_t)sjg_string9;
    sjv_phongColorShader.vertex.data._isGlobal = false;
    sjf_array_char(&sjv_phongColorShader.vertex.data);
    sjf_string(&sjv_phongColorShader.vertex);
    sjv_phongColorShader.pixel.count = 26;
    sjv_phongColorShader.pixel.data.size = 27;
    sjv_phongColorShader.pixel.data.data = (uintptr_t)sjg_string10;
    sjv_phongColorShader.pixel.data._isGlobal = false;
    sjf_array_char(&sjv_phongColorShader.pixel.data);
    sjf_string(&sjv_phongColorShader.pixel);
    sjf_shader(&sjv_phongColorShader);
    sjv_phongTextureShader.vertex.count = 30;
    sjv_phongTextureShader.vertex.data.size = 31;
    sjv_phongTextureShader.vertex.data.data = (uintptr_t)sjg_string11;
    sjv_phongTextureShader.vertex.data._isGlobal = false;
    sjf_array_char(&sjv_phongTextureShader.vertex.data);
    sjf_string(&sjv_phongTextureShader.vertex);
    sjv_phongTextureShader.pixel.count = 30;
    sjv_phongTextureShader.pixel.data.size = 31;
    sjv_phongTextureShader.pixel.data.data = (uintptr_t)sjg_string12;
    sjv_phongTextureShader.pixel.data._isGlobal = false;
    sjf_array_char(&sjv_phongTextureShader.pixel.data);
    sjf_string(&sjv_phongTextureShader.pixel);
    sjf_shader(&sjv_phongTextureShader);
    sjv_textShader.vertex.count = 24;
    sjv_textShader.vertex.data.size = 25;
    sjv_textShader.vertex.data.data = (uintptr_t)sjg_string13;
    sjv_textShader.vertex.data._isGlobal = false;
    sjf_array_char(&sjv_textShader.vertex.data);
    sjf_string(&sjv_textShader.vertex);
    sjv_textShader.pixel.count = 24;
    sjv_textShader.pixel.data.size = 25;
    sjv_textShader.pixel.data.data = (uintptr_t)sjg_string14;
    sjv_textShader.pixel.data._isGlobal = false;
    sjf_array_char(&sjv_textShader.pixel.data);
    sjf_string(&sjv_textShader.pixel);
    sjf_shader(&sjv_textShader);
    sjf_anon8(&sjv_style);
    sjv_vertex_location_texture_normal_format.count = 32;
    sjv_vertex_location_texture_normal_format.data.size = 33;
    sjv_vertex_location_texture_normal_format.data.data = (uintptr_t)sjg_string15;
    sjv_vertex_location_texture_normal_format.data._isGlobal = false;
    sjf_array_char(&sjv_vertex_location_texture_normal_format.data);
    sjf_string(&sjv_vertex_location_texture_normal_format);
    sjt_cast1 = (sjs_fillElement_heap*)malloc(sizeof(sjs_fillElement_heap));
    sjt_cast1->_refCount = 1;
    sjt_cast1->children.size = 2;
    sjt_cast2 = 0;
    sjt_cast1->children.data = (uintptr_t)sjt_cast2;
    sjt_cast1->children._isGlobal = false;
    sjf_array_heap_element(&sjt_cast1->children);
    sjt_functionParam4 = 0;
    sjt_cast3 = (sjs_scene3dElement_heap*)malloc(sizeof(sjs_scene3dElement_heap));
    sjt_cast3->_refCount = 1;
    sjt_cast3->children.size = 1;
    sjt_cast6 = 0;
    sjt_cast3->children.data = (uintptr_t)sjt_cast6;
    sjt_cast3->children._isGlobal = false;
    sjf_array_heap_model(&sjt_cast3->children);
    sjt_functionParam41 = 0;
    sjt_cast7 = (sjs_scene2dModel_heap*)malloc(sizeof(sjs_scene2dModel_heap));
    sjt_cast7->_refCount = 1;
    sjt_functionParam100 = -1.0f;
    sjt_functionParam101 = 1.0f;
    sjt_functionParam102 = -1.0f;
    sjt_functionParam103 = 1.0f;
    sjt_functionParam104 = 0.0f;
    sjt_functionParam105 = 0.0f;
    sjt_functionParam106 = 1.0f;
    sjt_functionParam107 = 0.0f;
    sjt_functionParam108 = 1.0f;
    sjf_planeVertexBuffer(sjt_functionParam100, sjt_functionParam101, sjt_functionParam102, sjt_functionParam103, sjt_functionParam104, sjt_functionParam105, sjt_functionParam106, sjt_functionParam107, sjt_functionParam108, &sjt_cast7->vertexBuffer);
    sjf_shader_copy(&sjt_cast7->shader, &sjv_phongTextureShader);
    sjt_cast7->frameBuffer.size.w = 512;
    sjt_cast7->frameBuffer.size.h = 512;
    sjf_size(&sjt_cast7->frameBuffer.size);
    sjf_frameBuffer(&sjt_cast7->frameBuffer);
    sjt_cast7->children.size = 2;
    sjt_cast14 = 0;
    sjt_cast7->children.data = (uintptr_t)sjt_cast14;
    sjt_cast7->children._isGlobal = false;
    sjf_array_heap_element(&sjt_cast7->children);
    sjt_functionParam109 = 0;
    sjt_cast15 = (sjs_imageElement_heap*)malloc(sizeof(sjs_imageElement_heap));
    sjt_cast15->_refCount = 1;
    sjt_call12.count = 15;
    sjt_call12.data.size = 16;
    sjt_call12.data.data = (uintptr_t)sjg_string16;
    sjt_call12.data._isGlobal = false;
    sjf_array_char(&sjt_call12.data);
    sjf_string(&sjt_call12);
    sjt_functionParam114 = &sjt_call12;
    sjf_textureFromPng(sjt_functionParam114, &sjt_cast15->image.texture);
    sjt_cast15->image.rect.x = 0;
    sjt_cast15->image.rect.y = 0;
    sjt_cast15->image.rect.w = 0;
    sjt_cast15->image.rect.h = 0;
    sjf_rect(&sjt_cast15->image.rect);
    sjt_cast15->image.margin.l = 150;
    sjt_cast15->image.margin.t = 50;
    sjt_cast15->image.margin.r = 150;
    sjt_cast15->image.margin.b = 150;
    sjf_margin(&sjt_cast15->image.margin);
    sjf_image(&sjt_cast15->image);
    sjt_cast15->_rect.x = 0;
    sjt_cast15->_rect.y = 0;
    sjt_cast15->_rect.w = 0;
    sjt_cast15->_rect.h = 0;
    sjf_rect(&sjt_cast15->_rect);
    sjt_cast15->_margin.l = 10;
    sjt_cast15->_margin.t = 10;
    sjt_cast15->_margin.r = 10;
    sjt_cast15->_margin.b = 10;
    sjf_margin(&sjt_cast15->_margin);
    sjt_cast15->_imageRenderer = 0;
    if (sjt_cast15->_imageRenderer != 0) {
        sjt_cast15->_imageRenderer->_refCount++;
    }

    sjf_imageElement_heap(sjt_cast15);
    sjt_functionParam110 = (sji_element*)sjf_imageElement_heap_as_sji_element(sjt_cast15);
    sjf_array_heap_element_initAt(&sjt_cast7->children, sjt_functionParam109, sjt_functionParam110);
    sjt_functionParam115 = 1;
    sjt_cast16 = (sjs_crossHairsElement_heap*)malloc(sizeof(sjs_crossHairsElement_heap));
    sjt_cast16->_refCount = 1;
    sjt_dot295 = &sjv_colors;
    sjf_anon7_blue(sjt_dot295, &sjt_cast16->color);
    sjt_cast16->_rect.x = 0;
    sjt_cast16->_rect.y = 0;
    sjt_cast16->_rect.w = 0;
    sjt_cast16->_rect.h = 0;
    sjf_rect(&sjt_cast16->_rect);
    sjt_cast16->_topDownRenderer = 0;
    if (sjt_cast16->_topDownRenderer != 0) {
        sjt_cast16->_topDownRenderer->_refCount++;
    }

    sjt_cast16->_leftRightRenderer = 0;
    if (sjt_cast16->_leftRightRenderer != 0) {
        sjt_cast16->_leftRightRenderer->_refCount++;
    }

    sjt_cast16->_point.x = 0;
    sjt_cast16->_point.y = 0;
    sjf_point(&sjt_cast16->_point);
    sjf_crossHairsElement_heap(sjt_cast16);
    sjt_functionParam116 = (sji_element*)sjf_crossHairsElement_heap_as_sji_element(sjt_cast16);
    sjf_array_heap_element_initAt(&sjt_cast7->children, sjt_functionParam115, sjt_functionParam116);
    sjt_cast7->_innerScene._size.w = 0;
    sjt_cast7->_innerScene._size.h = 0;
    sjf_size(&sjt_cast7->_innerScene._size);
    sjt_cast7->_innerScene.model.m00 = 0.0f;
    sjt_cast7->_innerScene.model.m01 = 0.0f;
    sjt_cast7->_innerScene.model.m02 = 0.0f;
    sjt_cast7->_innerScene.model.m03 = 0.0f;
    sjt_cast7->_innerScene.model.m10 = 0.0f;
    sjt_cast7->_innerScene.model.m11 = 0.0f;
    sjt_cast7->_innerScene.model.m12 = 0.0f;
    sjt_cast7->_innerScene.model.m13 = 0.0f;
    sjt_cast7->_innerScene.model.m20 = 0.0f;
    sjt_cast7->_innerScene.model.m21 = 0.0f;
    sjt_cast7->_innerScene.model.m22 = 0.0f;
    sjt_cast7->_innerScene.model.m23 = 0.0f;
    sjt_cast7->_innerScene.model.m30 = 0.0f;
    sjt_cast7->_innerScene.model.m31 = 0.0f;
    sjt_cast7->_innerScene.model.m32 = 0.0f;
    sjt_cast7->_innerScene.model.m33 = 0.0f;
    sjf_mat4(&sjt_cast7->_innerScene.model);
    sjt_cast7->_innerScene.view.m00 = 0.0f;
    sjt_cast7->_innerScene.view.m01 = 0.0f;
    sjt_cast7->_innerScene.view.m02 = 0.0f;
    sjt_cast7->_innerScene.view.m03 = 0.0f;
    sjt_cast7->_innerScene.view.m10 = 0.0f;
    sjt_cast7->_innerScene.view.m11 = 0.0f;
    sjt_cast7->_innerScene.view.m12 = 0.0f;
    sjt_cast7->_innerScene.view.m13 = 0.0f;
    sjt_cast7->_innerScene.view.m20 = 0.0f;
    sjt_cast7->_innerScene.view.m21 = 0.0f;
    sjt_cast7->_innerScene.view.m22 = 0.0f;
    sjt_cast7->_innerScene.view.m23 = 0.0f;
    sjt_cast7->_innerScene.view.m30 = 0.0f;
    sjt_cast7->_innerScene.view.m31 = 0.0f;
    sjt_cast7->_innerScene.view.m32 = 0.0f;
    sjt_cast7->_innerScene.view.m33 = 0.0f;
    sjf_mat4(&sjt_cast7->_innerScene.view);
    sjt_cast7->_innerScene.projection.m00 = 0.0f;
    sjt_cast7->_innerScene.projection.m01 = 0.0f;
    sjt_cast7->_innerScene.projection.m02 = 0.0f;
    sjt_cast7->_innerScene.projection.m03 = 0.0f;
    sjt_cast7->_innerScene.projection.m10 = 0.0f;
    sjt_cast7->_innerScene.projection.m11 = 0.0f;
    sjt_cast7->_innerScene.projection.m12 = 0.0f;
    sjt_cast7->_innerScene.projection.m13 = 0.0f;
    sjt_cast7->_innerScene.projection.m20 = 0.0f;
    sjt_cast7->_innerScene.projection.m21 = 0.0f;
    sjt_cast7->_innerScene.projection.m22 = 0.0f;
    sjt_cast7->_innerScene.projection.m23 = 0.0f;
    sjt_cast7->_innerScene.projection.m30 = 0.0f;
    sjt_cast7->_innerScene.projection.m31 = 0.0f;
    sjt_cast7->_innerScene.projection.m32 = 0.0f;
    sjt_cast7->_innerScene.projection.m33 = 0.0f;
    sjf_mat4(&sjt_cast7->_innerScene.projection);
    sjf_scene2d(&sjt_cast7->_innerScene);
    sjf_scene2dModel_heap(sjt_cast7);
    sjt_functionParam42 = (sji_scene3dElement_model*)sjf_scene2dModel_heap_as_sji_scene3dElement_model(sjt_cast7);
    sjf_array_heap_model_initAt(&sjt_cast3->children, sjt_functionParam41, sjt_functionParam42);
    sjt_cast3->camera.x = 0.0f;
    sjt_cast3->camera.y = 0.0f;
    sjt_cast3->camera.z = -5.0f;
    sjf_vec3(&sjt_cast3->camera);
    sjt_cast3->lookAt.x = 0.0f;
    sjt_cast3->lookAt.y = 0.0f;
    sjt_cast3->lookAt.z = 0.0f;
    sjf_vec3(&sjt_cast3->lookAt);
    sjt_cast3->up.x = 0.0f;
    sjt_cast3->up.y = 1.0f;
    sjt_cast3->up.z = 0.0f;
    sjf_vec3(&sjt_cast3->up);
    sjt_cast3->fieldOfView = 90.0f;
    sjt_cast3->zNear = 1.0f;
    sjt_cast3->zFar = 20.0f;
    sjt_cast3->lightPos.x = 1.0f;
    sjt_cast3->lightPos.y = 1.0f;
    sjt_cast3->lightPos.z = 1.0f;
    sjf_vec3(&sjt_cast3->lightPos);
    sjt_cast3->diffuseColor.r = 0.5f;
    sjt_cast3->diffuseColor.g = 0.5f;
    sjt_cast3->diffuseColor.b = 0.0f;
    sjt_cast3->diffuseColor.a = 1.0f;
    sjf_color(&sjt_cast3->diffuseColor);
    sjt_cast3->specColor.r = 1.0f;
    sjt_cast3->specColor.g = 1.0f;
    sjt_cast3->specColor.b = 1.0f;
    sjt_cast3->specColor.a = 1.0f;
    sjf_color(&sjt_cast3->specColor);
    sjt_cast3->projection.m00 = 0.0f;
    sjt_cast3->projection.m01 = 0.0f;
    sjt_cast3->projection.m02 = 0.0f;
    sjt_cast3->projection.m03 = 0.0f;
    sjt_cast3->projection.m10 = 0.0f;
    sjt_cast3->projection.m11 = 0.0f;
    sjt_cast3->projection.m12 = 0.0f;
    sjt_cast3->projection.m13 = 0.0f;
    sjt_cast3->projection.m20 = 0.0f;
    sjt_cast3->projection.m21 = 0.0f;
    sjt_cast3->projection.m22 = 0.0f;
    sjt_cast3->projection.m23 = 0.0f;
    sjt_cast3->projection.m30 = 0.0f;
    sjt_cast3->projection.m31 = 0.0f;
    sjt_cast3->projection.m32 = 0.0f;
    sjt_cast3->projection.m33 = 0.0f;
    sjf_mat4(&sjt_cast3->projection);
    sjt_cast3->view.m00 = 0.0f;
    sjt_cast3->view.m01 = 0.0f;
    sjt_cast3->view.m02 = 0.0f;
    sjt_cast3->view.m03 = 0.0f;
    sjt_cast3->view.m10 = 0.0f;
    sjt_cast3->view.m11 = 0.0f;
    sjt_cast3->view.m12 = 0.0f;
    sjt_cast3->view.m13 = 0.0f;
    sjt_cast3->view.m20 = 0.0f;
    sjt_cast3->view.m21 = 0.0f;
    sjt_cast3->view.m22 = 0.0f;
    sjt_cast3->view.m23 = 0.0f;
    sjt_cast3->view.m30 = 0.0f;
    sjt_cast3->view.m31 = 0.0f;
    sjt_cast3->view.m32 = 0.0f;
    sjt_cast3->view.m33 = 0.0f;
    sjf_mat4(&sjt_cast3->view);
    sjt_cast3->_rect.x = 0;
    sjt_cast3->_rect.y = 0;
    sjt_cast3->_rect.w = 0;
    sjt_cast3->_rect.h = 0;
    sjf_rect(&sjt_cast3->_rect);
    sjt_cast3->_angle = 0.0f;
    sjt_functionParam361 = -1.0f;
    sjt_functionParam362 = 1.0f;
    sjt_functionParam363 = -1.0f;
    sjt_functionParam364 = 1.0f;
    sjt_functionParam365 = -1.0f;
    sjt_functionParam366 = 1.0f;
    sjt_functionParam367 = 0.0f;
    sjt_functionParam368 = 1.0f;
    sjt_functionParam369 = 0.0f;
    sjt_functionParam370 = 1.0f;
    sjf_cubeVertexBuffer(sjt_functionParam361, sjt_functionParam362, sjt_functionParam363, sjt_functionParam364, sjt_functionParam365, sjt_functionParam366, sjt_functionParam367, sjt_functionParam368, sjt_functionParam369, sjt_functionParam370, &sjt_cast3->_cube);
    sjf_scene3dElement_heap(sjt_cast3);
    sjt_functionParam5 = (sji_element*)sjf_scene3dElement_heap_as_sji_element(sjt_cast3);
    sjf_array_heap_element_initAt(&sjt_cast1->children, sjt_functionParam4, sjt_functionParam5);
    sjt_functionParam371 = 1;
    sjt_cast21 = (sjs_crossHairsElement_heap*)malloc(sizeof(sjs_crossHairsElement_heap));
    sjt_cast21->_refCount = 1;
    sjt_dot296 = &sjv_colors;
    sjf_anon7_red(sjt_dot296, &sjt_cast21->color);
    sjt_cast21->_rect.x = 0;
    sjt_cast21->_rect.y = 0;
    sjt_cast21->_rect.w = 0;
    sjt_cast21->_rect.h = 0;
    sjf_rect(&sjt_cast21->_rect);
    sjt_cast21->_topDownRenderer = 0;
    if (sjt_cast21->_topDownRenderer != 0) {
        sjt_cast21->_topDownRenderer->_refCount++;
    }

    sjt_cast21->_leftRightRenderer = 0;
    if (sjt_cast21->_leftRightRenderer != 0) {
        sjt_cast21->_leftRightRenderer->_refCount++;
    }

    sjt_cast21->_point.x = 0;
    sjt_cast21->_point.y = 0;
    sjf_point(&sjt_cast21->_point);
    sjf_crossHairsElement_heap(sjt_cast21);
    sjt_functionParam372 = (sji_element*)sjf_crossHairsElement_heap_as_sji_element(sjt_cast21);
    sjf_array_heap_element_initAt(&sjt_cast1->children, sjt_functionParam371, sjt_functionParam372);
    sjt_cast1->_rect.x = 0;
    sjt_cast1->_rect.y = 0;
    sjt_cast1->_rect.w = 0;
    sjt_cast1->_rect.h = 0;
    sjf_rect(&sjt_cast1->_rect);
    sjf_fillElement_heap(sjt_cast1);
    sjv_root = (sji_element*)sjf_fillElement_heap_as_sji_element(sjt_cast1);
    sjf_runLoop();
    main_destroy();
    return 0;
}

void main_destroy() {

    sjt_cast1->_refCount--;
    if (sjt_cast1->_refCount <= 0) {
        sjf_fillElement_destroy((sjs_fillElement*)(((char*)sjt_cast1) + sizeof(intptr_t)));
    }
    sjt_cast15->_refCount--;
    if (sjt_cast15->_refCount <= 0) {
        sjf_imageElement_destroy((sjs_imageElement*)(((char*)sjt_cast15) + sizeof(intptr_t)));
    }
    sjt_cast16->_refCount--;
    if (sjt_cast16->_refCount <= 0) {
        sjf_crossHairsElement_destroy((sjs_crossHairsElement*)(((char*)sjt_cast16) + sizeof(intptr_t)));
    }
    sjt_cast21->_refCount--;
    if (sjt_cast21->_refCount <= 0) {
        sjf_crossHairsElement_destroy((sjs_crossHairsElement*)(((char*)sjt_cast21) + sizeof(intptr_t)));
    }
    sjt_cast3->_refCount--;
    if (sjt_cast3->_refCount <= 0) {
        sjf_scene3dElement_destroy((sjs_scene3dElement*)(((char*)sjt_cast3) + sizeof(intptr_t)));
    }
    sjt_cast7->_refCount--;
    if (sjt_cast7->_refCount <= 0) {
        sjf_scene2dModel_destroy((sjs_scene2dModel*)(((char*)sjt_cast7) + sizeof(intptr_t)));
    }
    sjt_functionParam110->_refCount--;
    if (sjt_functionParam110->_refCount <= 0) {
        sji_element_destroy(sjt_functionParam110);
    }
    sjt_functionParam116->_refCount--;
    if (sjt_functionParam116->_refCount <= 0) {
        sji_element_destroy(sjt_functionParam116);
    }
    sjt_functionParam372->_refCount--;
    if (sjt_functionParam372->_refCount <= 0) {
        sji_element_destroy(sjt_functionParam372);
    }
    sjt_functionParam42->_refCount--;
    if (sjt_functionParam42->_refCount <= 0) {
        sji_scene3dElement_model_destroy(sjt_functionParam42);
    }
    sjt_functionParam5->_refCount--;
    if (sjt_functionParam5->_refCount <= 0) {
        sji_element_destroy(sjt_functionParam5);
    }
    sjv_root->_refCount--;
    if (sjv_root->_refCount <= 0) {
        sji_element_destroy(sjv_root);
    }
    sjf_string_destroy(&sjt_call12);
    sjf_shader_destroy(&sjv_blurHorizontalShader);
    sjf_shader_destroy(&sjv_blurVerticalShader);
    sjf_anon5_destroy(&sjv_borderPosition);
    sjf_shader_destroy(&sjv_boxShader);
    sjf_anon6_destroy(&sjv_buttonState);
    sjf_anon7_destroy(&sjv_colors);
    sjf_anon1_destroy(&sjv_console);
    sjf_anon4_destroy(&sjv_convert);
    sjf_shader_destroy(&sjv_imageShader);
    sjf_anon2_destroy(&sjv_parse);
    sjf_shader_destroy(&sjv_phongColorShader);
    sjf_shader_destroy(&sjv_phongTextureShader);
    sjf_anon3_destroy(&sjv_random);
    sjf_scene2d_destroy(&sjv_rootScene);
    sjf_windowRenderer_destroy(&sjv_rootWindowRenderer);
    sjf_anon8_destroy(&sjv_style);
    sjf_shader_destroy(&sjv_textShader);
    sjf_string_destroy(&sjv_vertex_location_texture_normal_format);
}
