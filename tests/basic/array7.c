



#include <stdarg.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


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

const char* sjg_string1 = ", ";
const char* sjg_string3 = "";
const char* sjg_string4 = "c";


typedef struct pointer_td pointer;
struct pointer_td {
    void* ptr;
    int refCount;
    UT_hash_handle hh;
};
pointer* g_pointers = 0;

#define sjs_object_typeId 1
#define sjs_anon1_typeId 2
#define sjs_anon1_heap_typeId 3
#define sjs_anon2_typeId 4
#define sjs_anon2_heap_typeId 5
#define sjs_anon3_typeId 6
#define sjs_anon3_heap_typeId 7
#define sjs_class_typeId 8
#define sjs_class_heap_typeId 9
#define sjs_array_class_typeId 10
#define sjs_array_class_heap_typeId 11
#define sjs_array_char_typeId 12
#define sjs_array_char_heap_typeId 13
#define sjs_string_typeId 14
#define sjs_string_heap_typeId 15

typedef struct td_sjs_object sjs_object;
typedef struct td_sjs_anon1 sjs_anon1;
typedef struct td_sjs_anon1_heap sjs_anon1_heap;
typedef struct td_sjs_anon2 sjs_anon2;
typedef struct td_sjs_anon2_heap sjs_anon2_heap;
typedef struct td_sjs_anon3 sjs_anon3;
typedef struct td_sjs_anon3_heap sjs_anon3_heap;
typedef struct td_sjs_class sjs_class;
typedef struct td_sjs_class_heap sjs_class_heap;
typedef struct td_sjs_array_class sjs_array_class;
typedef struct td_sjs_array_class_heap sjs_array_class_heap;
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

struct td_sjs_class {
    int32_t x;
};

struct td_sjs_class_heap {
    intptr_t _refCount;
    int32_t x;
};

struct td_sjs_array_class {
    int32_t dataSize;
    uintptr_t data;
    bool _isGlobal;
    int32_t count;
};

struct td_sjs_array_class_heap {
    intptr_t _refCount;
    int32_t dataSize;
    uintptr_t data;
    bool _isGlobal;
    int32_t count;
};

struct td_sjs_array_char {
    int32_t dataSize;
    uintptr_t data;
    bool _isGlobal;
    int32_t count;
};

struct td_sjs_array_char_heap {
    intptr_t _refCount;
    int32_t dataSize;
    uintptr_t data;
    bool _isGlobal;
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


void _retain(void* ptr);
bool _release(void* ptr);

int32_t result1;
sjs_class sjt_call1;
sjs_string sjt_call11;
sjs_string sjt_call16;
sjs_string sjt_call18;
sjs_string sjt_call19;
sjs_class sjt_call2;
sjs_string sjt_call20;
sjs_string sjt_call21;
sjs_class sjt_call3;
sjs_class sjt_call4;
sjs_class sjt_call5;
int32_t sjt_cast1;
int32_t sjt_cast2;
int32_t sjt_functionParam1;
sjs_class* sjt_functionParam10;
sjs_class* sjt_functionParam2;
int32_t sjt_functionParam3;
sjs_string* sjt_functionParam32;
sjs_class* sjt_functionParam4;
int32_t sjt_functionParam5;
sjs_string* sjt_functionParam50;
sjs_string* sjt_functionParam57;
sjs_string* sjt_functionParam58;
sjs_string* sjt_functionParam59;
sjs_class* sjt_functionParam6;
sjs_string* sjt_functionParam60;
int32_t sjt_functionParam7;
sjs_class* sjt_functionParam8;
int32_t sjt_functionParam9;
int32_t sjt_math1;
int32_t sjt_math2;
int32_t sjt_negate1;
sjs_array_class* sjt_parent1;
sjs_array_class* sjt_parent10;
sjs_anon1* sjt_parent11;
sjs_array_class* sjt_parent2;
sjs_array_class* sjt_parent23;
sjs_array_class* sjt_parent24;
sjs_anon1* sjt_parent25;
sjs_array_class* sjt_parent26;
sjs_array_class* sjt_parent27;
sjs_anon1* sjt_parent28;
sjs_array_class* sjt_parent29;
sjs_array_class* sjt_parent3;
sjs_array_class* sjt_parent4;
sjs_array_class* sjt_parent5;
sjs_array_class sjv_a;
sjs_anon1 sjv_console;
uintptr_t sjv_emptyStringData;
float sjv_f32_pi;
int32_t sjv_i32_maxValue;
int32_t sjv_i32_minValue;
sjs_anon2 sjv_parse;
sjs_anon3 sjv_random;
uint32_t sjv_u32_maxValue;

void sjf_anon1(sjs_anon1* _this);
void sjf_anon1_copy(sjs_anon1* _this, sjs_anon1* _from);
void sjf_anon1_destroy(sjs_anon1* _this);
void sjf_anon1_heap(sjs_anon1_heap* _this);
void sjf_anon1_writeLine(sjs_anon1* _parent, sjs_string* data);
void sjf_anon2(sjs_anon2* _this);
void sjf_anon2_copy(sjs_anon2* _this, sjs_anon2* _from);
void sjf_anon2_destroy(sjs_anon2* _this);
void sjf_anon2_heap(sjs_anon2_heap* _this);
void sjf_anon3(sjs_anon3* _this);
void sjf_anon3_copy(sjs_anon3* _this, sjs_anon3* _from);
void sjf_anon3_destroy(sjs_anon3* _this);
void sjf_anon3_heap(sjs_anon3_heap* _this);
void sjf_array_char(sjs_array_char* _this);
void sjf_array_char_copy(sjs_array_char* _this, sjs_array_char* _from);
void sjf_array_char_destroy(sjs_array_char* _this);
void sjf_array_char_getAt(sjs_array_char* _parent, int32_t index, char* _return);
void sjf_array_char_grow(sjs_array_char* _parent, int32_t new_size);
void sjf_array_char_heap(sjs_array_char_heap* _this);
void sjf_array_char_initAt(sjs_array_char* _parent, int32_t index, char item);
void sjf_array_char_setAt(sjs_array_char* _parent, int32_t index, char item);
void sjf_array_class(sjs_array_class* _this);
void sjf_array_class__quickSort(sjs_array_class* _parent, int32_t left, int32_t right);
void sjf_array_class_copy(sjs_array_class* _this, sjs_array_class* _from);
void sjf_array_class_destroy(sjs_array_class* _this);
void sjf_array_class_getAt(sjs_array_class* _parent, int32_t index, sjs_class* _return);
void sjf_array_class_heap(sjs_array_class_heap* _this);
void sjf_array_class_initAt(sjs_array_class* _parent, int32_t index, sjs_class* item);
void sjf_array_class_reverse(sjs_array_class* _parent);
void sjf_array_class_setAt(sjs_array_class* _parent, int32_t index, sjs_class* item);
void sjf_array_class_sort(sjs_array_class* _parent);
void sjf_array_class_toString(sjs_array_class* _parent, sjs_string* sep, sjs_string* _return);
void sjf_class(sjs_class* _this);
void sjf_class_copy(sjs_class* _this, sjs_class* _from);
void sjf_class_destroy(sjs_class* _this);
void sjf_class_heap(sjs_class_heap* _this);
void sjf_class_isGreater(sjs_class* _parent, sjs_class* c, bool* _return);
void sjf_class_isLess(sjs_class* _parent, sjs_class* c, bool* _return);
void sjf_class_toString(sjs_class* _parent, sjs_string* _return);
void sjf_i32_toString(int32_t val, int32_t base, int32_t minLength, sjs_string* _return);
void sjf_i32_toString_heap(int32_t val, int32_t base, int32_t minLength, sjs_string_heap** _return);
void sjf_string(sjs_string* _this);
void sjf_string_add(sjs_string* _parent, sjs_string* item, sjs_string** _return);
void sjf_string_copy(sjs_string* _this, sjs_string* _from);
void sjf_string_destroy(sjs_string* _this);
void sjf_string_getAt(sjs_string* _parent, int32_t index, char* _return);
void sjf_string_heap(sjs_string_heap* _this);
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

void sjf_anon1(sjs_anon1* _this) {
}

void sjf_anon1_copy(sjs_anon1* _this, sjs_anon1* _from) {
}

void sjf_anon1_destroy(sjs_anon1* _this) {
}

void sjf_anon1_heap(sjs_anon1_heap* _this) {
}

void sjf_anon1_writeLine(sjs_anon1* _parent, sjs_string* data) {
#line 13 "lib/common/console.sj"
    printf("%s\n", (char*)data->data.data);
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

void sjf_array_char(sjs_array_char* _this) {
#line 255 "lib/common/array.sj"
    if (_this->dataSize < 0) {
#line 255
        halt("size is less than zero");
#line 255
    }
#line 255
    if (!_this->data) {
#line 255
        _this->data = (uintptr_t)malloc(_this->dataSize * sizeof(char));
#line 255
        if (!_this->data) {
#line 255
            halt("grow: out of memory\n");
#line 255
        }
#line 255
    }
}

void sjf_array_char_copy(sjs_array_char* _this, sjs_array_char* _from) {
#line 1 "lib/common/array.sj"
    _this->dataSize = _from->dataSize;
#line 1
    _this->data = _from->data;
#line 1
    _this->_isGlobal = _from->_isGlobal;
#line 1
    _this->count = _from->count;
#line 269
    _this->data = _from->data;
#line 269
    if (!_this->_isGlobal && _this->data) {
#line 269
        _retain((void*)_this->data);
#line 269
    }
}

void sjf_array_char_destroy(sjs_array_char* _this) {
#line 276 "lib/common/array.sj"
    if (!_this->_isGlobal && _this->data) {
#line 276
        if (_release((void*)_this->data)) {
#line 276
            free((char*)_this->data);
#line 276
        }
#line 276
    }
}

void sjf_array_char_getAt(sjs_array_char* _parent, int32_t index, char* _return) {
#line 7 "lib/common/array.sj"
    if (index >= _parent->count || index < 0) {
#line 7
        halt("getAt: out of bounds\n");
#line 7
    }
#line 7
    char* p = (char*)_parent->data;
#line 7
    #line 7 "lib/common/array.sj"
#line 7
    (*_return) = p[index];
#line 7
    ;
}

void sjf_array_char_grow(sjs_array_char* _parent, int32_t new_size) {
#line 114 "lib/common/array.sj"
    if (_parent->dataSize != new_size) {
#line 114
        if (new_size < _parent->dataSize) {
#line 114
            halt("grow: new size smaller than old _parent->dataSize %d:%d\n", new_size, _parent->dataSize);
#line 114
        }
#line 114
        if (_parent->_isGlobal) {
#line 114
            _parent->_isGlobal = false;
#line 114
            char* p = (char*)_parent->data;
#line 114
            _parent->data = (uintptr_t)malloc(new_size * sizeof(char));
#line 114
            if (!_parent->data) {
#line 114
                halt("grow: out of memory\n");
#line 114
            }
#line 114
            memcpy((void*)_parent->data, p, _parent->dataSize * sizeof(char));
#line 114
        } else {
#line 114
            _parent->data = (uintptr_t)realloc((void*)_parent->data, new_size * sizeof(char));
#line 114
            if (!_parent->data) {
#line 114
                halt("grow: out of memory\n");
#line 114
            }
#line 114
            memset((char*)_parent->data + _parent->dataSize, 0, (new_size - _parent->dataSize) * sizeof(char));
#line 114
        }
#line 114
        _parent->dataSize = new_size;
#line 114
    }
}

void sjf_array_char_heap(sjs_array_char_heap* _this) {
#line 255 "lib/common/array.sj"
    if (_this->dataSize < 0) {
#line 255
        halt("size is less than zero");
#line 255
    }
#line 255
    if (!_this->data) {
#line 255
        _this->data = (uintptr_t)malloc(_this->dataSize * sizeof(char));
#line 255
        if (!_this->data) {
#line 255
            halt("grow: out of memory\n");
#line 255
        }
#line 255
    }
}

void sjf_array_char_initAt(sjs_array_char* _parent, int32_t index, char item) {
#line 18 "lib/common/array.sj"
    if (index != _parent->count) {
#line 18
        halt("initAt: can only initialize last element\n");
#line 18
    }
#line 18
    if (index >= _parent->dataSize || index < 0) {
#line 18
        halt("initAt: out of bounds %d:%d\n", index, _parent->dataSize);
#line 18
    }
#line 18
    char* p = (char*)_parent->data;
#line 18
    #line 17 "lib/common/array.sj"
#line 18
    p[index] = item;
#line 18
    ;
#line 18
    _parent->count = index + 1;
}

void sjf_array_char_setAt(sjs_array_char* _parent, int32_t index, char item) {
#line 33 "lib/common/array.sj"
    if (index >= _parent->count || index < 0) {
#line 33
        halt("setAt: out of bounds %d:%d\n", index, _parent->count);
#line 33
    }
#line 33
    char* p = (char*)_parent->data;
#line 33
    ;
#line 33
    #line 32 "lib/common/array.sj"
#line 33
    p[index] = item;
#line 33
    ;
}

void sjf_array_class(sjs_array_class* _this) {
#line 255 "lib/common/array.sj"
    if (_this->dataSize < 0) {
#line 255
        halt("size is less than zero");
#line 255
    }
#line 255
    if (!_this->data) {
#line 255
        _this->data = (uintptr_t)malloc(_this->dataSize * sizeof(sjs_class));
#line 255
        if (!_this->data) {
#line 255
            halt("grow: out of memory\n");
#line 255
        }
#line 255
    }
}

void sjf_array_class__quickSort(sjs_array_class* _parent, int32_t left, int32_t right) {
    int32_t sjt_compare1;
    int32_t sjt_compare11;
    int32_t sjt_compare12;
    int32_t sjt_compare13;
    int32_t sjt_compare14;
    int32_t sjt_compare2;
    int32_t sjt_functionParam11;
    bool sjt_ifElse2;
    bool sjt_ifElse3;
    int32_t sjt_math3;
    int32_t sjt_math4;
    int32_t sjt_math5;
    int32_t sjt_math6;
    bool sjt_while1;
    int32_t sjv_i;
    int32_t sjv_j;
    sjs_class sjv_pivot;

#line 141 "lib/common/array.sj"
    sjv_i = left;
#line 141
    sjv_j = right;
#line 141
    sjt_math5 = left;
#line 141
    sjt_math6 = right;
#line 145
    sjt_math3 = sjt_math5 + sjt_math6;
#line 145
    sjt_math4 = 2;
#line 145
    sjt_functionParam11 = sjt_math3 / sjt_math4;
#line 145
    sjf_array_class_getAt(_parent, sjt_functionParam11, &sjv_pivot);
#line 146
    sjt_compare1 = sjv_i;
#line 146
    sjt_compare2 = sjv_j;
#line 146
    sjt_while1 = sjt_compare1 <= sjt_compare2;
    while (sjt_while1) {
        sjs_class sjt_call6;
        sjs_class sjt_call8;
        int32_t sjt_compare10;
        int32_t sjt_compare7;
        int32_t sjt_compare8;
        int32_t sjt_compare9;
        int32_t sjt_functionParam12;
        sjs_class* sjt_functionParam13;
        int32_t sjt_functionParam16;
        sjs_class* sjt_functionParam17;
        bool sjt_ifElse1;
        sjs_class* sjt_parent6;
        sjs_class* sjt_parent8;
        bool sjt_while2;
        bool sjt_while3;

#line 147 "lib/common/array.sj"
        sjt_functionParam12 = sjv_i;
#line 147
        sjf_array_class_getAt(_parent, sjt_functionParam12, &sjt_call6);
#line 147
        sjt_parent6 = &sjt_call6;
#line 147
        sjt_functionParam13 = &sjv_pivot;
#line 147
        sjf_class_isLess(sjt_parent6, sjt_functionParam13, &sjt_while2);
        while (sjt_while2) {
            sjs_class sjt_call7;
            int32_t sjt_functionParam14;
            sjs_class* sjt_functionParam15;
            int32_t sjt_math7;
            int32_t sjt_math8;
            sjs_class* sjt_parent7;

#line 148 "lib/common/array.sj"
            sjt_math7 = sjv_i;
#line 148
            sjt_math8 = 1;
#line 148
            sjv_i = sjt_math7 + sjt_math8;
#line 147
            sjt_functionParam14 = sjv_i;
#line 147
            sjf_array_class_getAt(_parent, sjt_functionParam14, &sjt_call7);
#line 147
            sjt_parent7 = &sjt_call7;
#line 147
            sjt_functionParam15 = &sjv_pivot;
#line 147
            sjf_class_isLess(sjt_parent7, sjt_functionParam15, &sjt_while2);

            sjf_class_destroy(&sjt_call7);
        }

#line 151
        sjt_functionParam16 = sjv_j;
#line 151
        sjf_array_class_getAt(_parent, sjt_functionParam16, &sjt_call8);
#line 151
        sjt_parent8 = &sjt_call8;
#line 151
        sjt_functionParam17 = &sjv_pivot;
#line 151
        sjf_class_isGreater(sjt_parent8, sjt_functionParam17, &sjt_while3);
        while (sjt_while3) {
            sjs_class sjt_call9;
            int32_t sjt_functionParam18;
            sjs_class* sjt_functionParam19;
            int32_t sjt_math10;
            int32_t sjt_math9;
            sjs_class* sjt_parent9;

#line 152 "lib/common/array.sj"
            sjt_math9 = sjv_j;
#line 152
            sjt_math10 = 1;
#line 152
            sjv_j = sjt_math9 - sjt_math10;
#line 151
            sjt_functionParam18 = sjv_j;
#line 151
            sjf_array_class_getAt(_parent, sjt_functionParam18, &sjt_call9);
#line 151
            sjt_parent9 = &sjt_call9;
#line 151
            sjt_functionParam19 = &sjv_pivot;
#line 151
            sjf_class_isGreater(sjt_parent9, sjt_functionParam19, &sjt_while3);

            sjf_class_destroy(&sjt_call9);
        }

#line 155
        sjt_compare7 = sjv_i;
#line 155
        sjt_compare8 = sjv_j;
#line 155
        sjt_ifElse1 = sjt_compare7 <= sjt_compare8;
        if (sjt_ifElse1) {
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

#line 156 "lib/common/array.sj"
            sjt_functionParam20 = sjv_i;
#line 156
            sjf_array_class_getAt(_parent, sjt_functionParam20, &sjv_tmp);
#line 157
            sjt_functionParam21 = sjv_i;
#line 157
            sjt_functionParam23 = sjv_j;
#line 157
            sjf_array_class_getAt(_parent, sjt_functionParam23, &sjt_call10);
#line 157
            sjt_functionParam22 = &sjt_call10;
#line 157
            sjf_array_class_setAt(_parent, sjt_functionParam21, sjt_functionParam22);
#line 158
            sjt_functionParam24 = sjv_j;
#line 158
            sjt_functionParam25 = &sjv_tmp;
#line 158
            sjf_array_class_setAt(_parent, sjt_functionParam24, sjt_functionParam25);
#line 159
            sjt_math11 = sjv_i;
#line 159
            sjt_math12 = 1;
#line 159
            sjv_i = sjt_math11 + sjt_math12;
#line 160
            sjt_math13 = sjv_j;
#line 160
            sjt_math14 = 1;
#line 160
            sjv_j = sjt_math13 - sjt_math14;

            sjf_class_destroy(&sjt_call10);
            sjf_class_destroy(&sjv_tmp);
        }

#line 146
        sjt_compare9 = sjv_i;
#line 146
        sjt_compare10 = sjv_j;
#line 146
        sjt_while1 = sjt_compare9 <= sjt_compare10;

        sjf_class_destroy(&sjt_call6);
        sjf_class_destroy(&sjt_call8);
    }

#line 141
    sjt_compare11 = left;
#line 164
    sjt_compare12 = sjv_j;
#line 164
    sjt_ifElse2 = sjt_compare11 < sjt_compare12;
    if (sjt_ifElse2) {
        int32_t sjt_functionParam26;
        int32_t sjt_functionParam27;

#line 141 "lib/common/array.sj"
        sjt_functionParam26 = left;
#line 165
        sjt_functionParam27 = sjv_j;
#line 165
        sjf_array_class__quickSort(_parent, sjt_functionParam26, sjt_functionParam27);
    }

#line 167
    sjt_compare13 = sjv_i;
#line 141
    sjt_compare14 = right;
#line 167
    sjt_ifElse3 = sjt_compare13 < sjt_compare14;
    if (sjt_ifElse3) {
        int32_t sjt_functionParam28;
        int32_t sjt_functionParam29;

#line 168 "lib/common/array.sj"
        sjt_functionParam28 = sjv_i;
#line 141
        sjt_functionParam29 = right;
#line 141
        sjf_array_class__quickSort(_parent, sjt_functionParam28, sjt_functionParam29);
    }

    sjf_class_destroy(&sjv_pivot);
}

void sjf_array_class_copy(sjs_array_class* _this, sjs_array_class* _from) {
#line 1 "lib/common/array.sj"
    _this->dataSize = _from->dataSize;
#line 1
    _this->data = _from->data;
#line 1
    _this->_isGlobal = _from->_isGlobal;
#line 1
    _this->count = _from->count;
#line 269
    _this->data = _from->data;
#line 269
    if (!_this->_isGlobal && _this->data) {
#line 269
        _retain((void*)_this->data);
#line 269
    }
}

void sjf_array_class_destroy(sjs_array_class* _this) {
#line 276 "lib/common/array.sj"
    if (!_this->_isGlobal && _this->data) {
#line 276
        if (_release((void*)_this->data)) {
#line 276
            free((sjs_class*)_this->data);
#line 276
        }
#line 276
    }
}

void sjf_array_class_getAt(sjs_array_class* _parent, int32_t index, sjs_class* _return) {
#line 7 "lib/common/array.sj"
    if (index >= _parent->count || index < 0) {
#line 7
        halt("getAt: out of bounds\n");
#line 7
    }
#line 7
    sjs_class* p = (sjs_class*)_parent->data;
#line 7
    #line 7 "lib/common/array.sj"
#line 7
    sjf_class_copy(_return, &p[index]);
#line 7
    ;
}

void sjf_array_class_heap(sjs_array_class_heap* _this) {
#line 255 "lib/common/array.sj"
    if (_this->dataSize < 0) {
#line 255
        halt("size is less than zero");
#line 255
    }
#line 255
    if (!_this->data) {
#line 255
        _this->data = (uintptr_t)malloc(_this->dataSize * sizeof(sjs_class));
#line 255
        if (!_this->data) {
#line 255
            halt("grow: out of memory\n");
#line 255
        }
#line 255
    }
}

void sjf_array_class_initAt(sjs_array_class* _parent, int32_t index, sjs_class* item) {
#line 18 "lib/common/array.sj"
    if (index != _parent->count) {
#line 18
        halt("initAt: can only initialize last element\n");
#line 18
    }
#line 18
    if (index >= _parent->dataSize || index < 0) {
#line 18
        halt("initAt: out of bounds %d:%d\n", index, _parent->dataSize);
#line 18
    }
#line 18
    sjs_class* p = (sjs_class*)_parent->data;
#line 18
    #line 17 "lib/common/array.sj"
#line 18
    sjf_class_copy(&p[index], item);
#line 18
    ;
#line 18
    _parent->count = index + 1;
}

void sjf_array_class_reverse(sjs_array_class* _parent) {
    int32_t i;
    sjs_array_class* sjt_dot28;
    int32_t sjt_forEnd3;
    int32_t sjt_forStart3;
    int32_t sjt_math37;
    int32_t sjt_math38;

#line 212 "lib/common/array.sj"
    sjt_forStart3 = 0;
#line 211
    sjt_dot28 = _parent;
#line 212
    sjt_math37 = (sjt_dot28)->count;
#line 212
    sjt_math38 = 2;
#line 212
    sjt_forEnd3 = sjt_math37 / sjt_math38;
#line 212
    i = sjt_forStart3;
    while (i < sjt_forEnd3) {
        sjs_class sjt_call17;
        sjs_array_class* sjt_dot29;
        int32_t sjt_functionParam51;
        int32_t sjt_functionParam52;
        sjs_class* sjt_functionParam53;
        int32_t sjt_functionParam54;
        int32_t sjt_functionParam55;
        sjs_class* sjt_functionParam56;
        int32_t sjt_math39;
        int32_t sjt_math40;
        int32_t sjt_math41;
        int32_t sjt_math42;
        int32_t sjv_j;
        sjs_class sjv_tmp;

#line 211 "lib/common/array.sj"
        sjt_dot29 = _parent;
#line 213
        sjt_math41 = (sjt_dot29)->count;
#line 212
        sjt_math42 = i;
#line 213
        sjt_math39 = sjt_math41 - sjt_math42;
#line 213
        sjt_math40 = 1;
#line 213
        sjv_j = sjt_math39 - sjt_math40;
#line 212
        sjt_functionParam51 = i;
#line 212
        sjf_array_class_getAt(_parent, sjt_functionParam51, &sjv_tmp);
#line 212
        sjt_functionParam52 = i;
#line 215
        sjt_functionParam54 = sjv_j;
#line 215
        sjf_array_class_getAt(_parent, sjt_functionParam54, &sjt_call17);
#line 215
        sjt_functionParam53 = &sjt_call17;
#line 215
        sjf_array_class_setAt(_parent, sjt_functionParam52, sjt_functionParam53);
#line 216
        sjt_functionParam55 = sjv_j;
#line 216
        sjt_functionParam56 = &sjv_tmp;
#line 216
        sjf_array_class_setAt(_parent, sjt_functionParam55, sjt_functionParam56);
#line 212
        i++;

        sjf_class_destroy(&sjt_call17);
        sjf_class_destroy(&sjv_tmp);
    }
}

void sjf_array_class_setAt(sjs_array_class* _parent, int32_t index, sjs_class* item) {
#line 33 "lib/common/array.sj"
    if (index >= _parent->count || index < 0) {
#line 33
        halt("setAt: out of bounds %d:%d\n", index, _parent->count);
#line 33
    }
#line 33
    sjs_class* p = (sjs_class*)_parent->data;
#line 33
    ;
#line 33
    #line 32 "lib/common/array.sj"
#line 33
    sjf_class_copy(&p[index], item);
#line 33
    ;
}

void sjf_array_class_sort(sjs_array_class* _parent) {
    sjs_array_class* sjt_dot5;
    int32_t sjt_functionParam30;
    int32_t sjt_functionParam31;
    int32_t sjt_math15;
    int32_t sjt_math16;

#line 204 "lib/common/array.sj"
    sjt_functionParam30 = 0;
#line 203
    sjt_dot5 = _parent;
#line 204
    sjt_math15 = (sjt_dot5)->count;
#line 204
    sjt_math16 = 1;
#line 204
    sjt_functionParam31 = sjt_math15 - sjt_math16;
#line 204
    sjf_array_class__quickSort(_parent, sjt_functionParam30, sjt_functionParam31);
}

void sjf_array_class_toString(sjs_array_class* _parent, sjs_string* sep, sjs_string* _return) {
    int32_t i;
    sjs_string* sjt_copy4;
    sjs_array_class* sjt_dot6;
    int32_t sjt_forEnd1;
    int32_t sjt_forStart1;
    sjs_string sjv_result;

#line 221 "lib/common/array.sj"
    sjv_result.count = 0;
#line 221
    sjv_result.data.dataSize = 1;
#line 221
    sjv_result.data.data = (uintptr_t)sjg_string3;
#line 221
    sjv_result.data._isGlobal = true;
#line 221
    sjv_result.data.count = 1;
#line 221
    sjf_array_char(&sjv_result.data);
#line 221
    sjf_string(&sjv_result);
#line 222
    sjt_forStart1 = 0;
#line 220
    sjt_dot6 = _parent;
#line 222
    sjt_forEnd1 = (sjt_dot6)->count;
#line 222
    i = sjt_forStart1;
    while (i < sjt_forEnd1) {
        sjs_string sjt_call12;
        sjs_class sjt_call15;
        int32_t sjt_compare15;
        int32_t sjt_compare16;
        sjs_string* sjt_copy2;
        sjs_string* sjt_functionParam44;
        int32_t sjt_functionParam49;
        bool sjt_ifElse4;
        sjs_string* sjt_parent20;
        sjs_class* sjt_parent22;

#line 222 "lib/common/array.sj"
        sjt_compare15 = i;
#line 223
        sjt_compare16 = 0;
#line 223
        sjt_ifElse4 = sjt_compare15 != sjt_compare16;
        if (sjt_ifElse4) {
            sjs_string* sjt_copy1;
            sjs_string* sjt_functionParam43;
            sjs_string* sjt_parent19;

#line 15 "lib/common/string.sj"
            sjt_parent19 = &sjv_result;
#line 220 "lib/common/array.sj"
            sjt_functionParam43 = sep;
#line 220
            sjf_string_add(sjt_parent19, sjt_functionParam43, &sjt_copy1);
#line 224
            sjf_string_copy(&sjv_result, sjt_copy1);
        }

#line 15 "lib/common/string.sj"
        sjt_parent20 = &sjv_result;
#line 222 "lib/common/array.sj"
        sjt_functionParam49 = i;
#line 222
        sjf_array_class_getAt(_parent, sjt_functionParam49, &sjt_call15);
#line 226
        sjt_parent22 = &sjt_call15;
#line 226
        sjf_class_toString(sjt_parent22, &sjt_call12);
#line 226
        sjt_functionParam44 = &sjt_call12;
#line 226
        sjf_string_add(sjt_parent20, sjt_functionParam44, &sjt_copy2);
#line 226
        sjf_string_copy(&sjv_result, sjt_copy2);
#line 222
        i++;

        sjf_string_destroy(&sjt_call12);
        sjf_class_destroy(&sjt_call15);
    }

#line 228
    sjt_copy4 = &sjv_result;
#line 228
    sjf_string_copy(_return, sjt_copy4);

    sjf_string_destroy(&sjv_result);
}

void sjf_class(sjs_class* _this) {
}

void sjf_class_copy(sjs_class* _this, sjs_class* _from) {
#line 4 "array7.sj"
    _this->x = _from->x;
}

void sjf_class_destroy(sjs_class* _this) {
}

void sjf_class_heap(sjs_class_heap* _this) {
}

void sjf_class_isGreater(sjs_class* _parent, sjs_class* c, bool* _return) {
    int32_t sjt_compare5;
    int32_t sjt_compare6;
    sjs_class* sjt_dot3;
    sjs_class* sjt_dot4;

#line 11 "array7.sj"
    sjt_dot3 = _parent;
#line 12
    sjt_compare5 = (sjt_dot3)->x;
#line 11
    sjt_dot4 = c;
#line 12
    sjt_compare6 = (sjt_dot4)->x;
#line 12
    (*_return) = sjt_compare5 > sjt_compare6;
}

void sjf_class_isLess(sjs_class* _parent, sjs_class* c, bool* _return) {
    int32_t sjt_compare3;
    int32_t sjt_compare4;
    sjs_class* sjt_dot1;
    sjs_class* sjt_dot2;

#line 7 "array7.sj"
    sjt_dot1 = _parent;
#line 8
    sjt_compare3 = (sjt_dot1)->x;
#line 7
    sjt_dot2 = c;
#line 8
    sjt_compare4 = (sjt_dot2)->x;
#line 8
    (*_return) = sjt_compare3 < sjt_compare4;
}

void sjf_class_toString(sjs_class* _parent, sjs_string* _return) {
    sjs_string sjt_call13;
    sjs_string sjt_call14;
    sjs_string* sjt_copy3;
    sjs_class* sjt_dot27;
    sjs_string* sjt_functionParam45;
    int32_t sjt_functionParam46;
    int32_t sjt_functionParam47;
    int32_t sjt_functionParam48;
    sjs_string* sjt_parent21;

#line 16 "array7.sj"
    sjt_call13.count = 1;
#line 16
    sjt_call13.data.dataSize = 2;
#line 16
    sjt_call13.data.data = (uintptr_t)sjg_string4;
#line 16
    sjt_call13.data._isGlobal = true;
#line 16
    sjt_call13.data.count = 2;
#line 16
    sjf_array_char(&sjt_call13.data);
#line 16
    sjf_string(&sjt_call13);
#line 16
    sjt_parent21 = &sjt_call13;
#line 15
    sjt_dot27 = _parent;
#line 16
    sjt_functionParam46 = (sjt_dot27)->x;
#line 22 "lib/common/i32.sj"
    sjt_functionParam47 = 10;
#line 22
    sjt_functionParam48 = 0;
#line 22
    sjf_i32_toString(sjt_functionParam46, sjt_functionParam47, sjt_functionParam48, &sjt_call14);
#line 16 "array7.sj"
    sjt_functionParam45 = &sjt_call14;
#line 16
    sjf_string_add(sjt_parent21, sjt_functionParam45, &sjt_copy3);
#line 16
    sjf_string_copy(_return, sjt_copy3);

    sjf_string_destroy(&sjt_call13);
    sjf_string_destroy(&sjt_call14);
}

void sjf_i32_toString(int32_t val, int32_t base, int32_t minLength, sjs_string* _return) {
    int32_t sjt_cast4;
    int32_t sjt_math29;
    int32_t sjt_math30;
    int32_t sjt_math31;
    int32_t sjt_math32;
    int32_t sjv_count;
    uintptr_t sjv_data;

#line 23 "lib/common/i32.sj"
    sjv_count = 0;
#line 24
    sjt_cast4 = 0;
#line 24
    sjv_data = (uintptr_t)sjt_cast4;
#line 25
    if (base < 2) {
#line 25
        halt("base is too small");
#line 25
    }
#line 25
    if (base > 16) {
#line 25
        halt("base is too large");
#line 25
    }
#line 25
    char buf[32] = { 0 };
#line 25
    int i = 30;
#line 25
    do {
#line 25
        buf[i] = "0123456789ABCDEF"[val % base];
#line 25
        i--;
#line 25
        val /= base;
#line 25
    } while (val && i);
#line 25
    sjv_count = 30 - i;
#line 25
    if (sjv_count < minLength) {
#line 25
    }
#line 25
    sjv_data = (uintptr_t)malloc(sizeof(char) * (sjv_count + 1));
#line 25
    memcpy((void*)sjv_data, &buf[i+1], sjv_count + 1);
#line 49
    _return->count = sjv_count;
#line 49
    sjt_math29 = sjv_count;
#line 49
    sjt_math30 = 1;
#line 49
    _return->data.dataSize = sjt_math29 + sjt_math30;
#line 49
    _return->data.data = sjv_data;
#line 4 "lib/common/array.sj"
    _return->data._isGlobal = false;
#line 49 "lib/common/i32.sj"
    sjt_math31 = sjv_count;
#line 49
    sjt_math32 = 1;
#line 49
    _return->data.count = sjt_math31 + sjt_math32;
#line 49
    sjf_array_char(&_return->data);
#line 49
    sjf_string(_return);
}

void sjf_i32_toString_heap(int32_t val, int32_t base, int32_t minLength, sjs_string_heap** _return) {
    int32_t sjt_cast5;
    int32_t sjt_math33;
    int32_t sjt_math34;
    int32_t sjt_math35;
    int32_t sjt_math36;
    int32_t sjv_count;
    uintptr_t sjv_data;

#line 23 "lib/common/i32.sj"
    sjv_count = 0;
#line 24
    sjt_cast5 = 0;
#line 24
    sjv_data = (uintptr_t)sjt_cast5;
#line 25
    if (base < 2) {
#line 25
        halt("base is too small");
#line 25
    }
#line 25
    if (base > 16) {
#line 25
        halt("base is too large");
#line 25
    }
#line 25
    char buf[32] = { 0 };
#line 25
    int i = 30;
#line 25
    do {
#line 25
        buf[i] = "0123456789ABCDEF"[val % base];
#line 25
        i--;
#line 25
        val /= base;
#line 25
    } while (val && i);
#line 25
    sjv_count = 30 - i;
#line 25
    if (sjv_count < minLength) {
#line 25
    }
#line 25
    sjv_data = (uintptr_t)malloc(sizeof(char) * (sjv_count + 1));
#line 25
    memcpy((void*)sjv_data, &buf[i+1], sjv_count + 1);
#line 25
    (*_return) = (sjs_string_heap*)malloc(sizeof(sjs_string_heap));
#line 25
    (*_return)->_refCount = 1;
#line 49
    (*_return)->count = sjv_count;
#line 49
    sjt_math33 = sjv_count;
#line 49
    sjt_math34 = 1;
#line 49
    (*_return)->data.dataSize = sjt_math33 + sjt_math34;
#line 49
    (*_return)->data.data = sjv_data;
#line 4 "lib/common/array.sj"
    (*_return)->data._isGlobal = false;
#line 49 "lib/common/i32.sj"
    sjt_math35 = sjv_count;
#line 49
    sjt_math36 = 1;
#line 49
    (*_return)->data.count = sjt_math35 + sjt_math36;
#line 49
    sjf_array_char(&(*_return)->data);
#line 49
    sjf_string_heap((*_return));
}

void sjf_string(sjs_string* _this) {
}

void sjf_string_add(sjs_string* _parent, sjs_string* item, sjs_string** _return) {
    int32_t sjt_compare17;
    int32_t sjt_compare18;
    sjs_string* sjt_dot7;
    bool sjt_ifElse5;

#line 15 "lib/common/string.sj"
    sjt_dot7 = item;
#line 16
    sjt_compare17 = (sjt_dot7)->count;
#line 16
    sjt_compare18 = 0;
#line 16
    sjt_ifElse5 = sjt_compare17 > sjt_compare18;
    if (sjt_ifElse5) {
        int32_t i;
        int32_t sjt_cast3;
        int32_t sjt_compare19;
        int32_t sjt_compare20;
        sjs_array_char* sjt_dot10;
        sjs_string* sjt_dot11;
        sjs_string* sjt_dot15;
        sjs_string* sjt_dot16;
        sjs_string* sjt_dot18;
        sjs_string* sjt_dot19;
        sjs_string* sjt_dot20;
        sjs_string* sjt_dot25;
        sjs_string* sjt_dot26;
        sjs_string* sjt_dot8;
        sjs_string* sjt_dot9;
        int32_t sjt_forEnd2;
        int32_t sjt_forStart2;
        int32_t sjt_functionParam34;
        char sjt_functionParam35;
        int32_t sjt_functionParam37;
        int32_t sjt_functionParam41;
        char sjt_functionParam42;
        bool sjt_ifElse6;
        int32_t sjt_math17;
        int32_t sjt_math18;
        int32_t sjt_math19;
        int32_t sjt_math20;
        int32_t sjt_math25;
        int32_t sjt_math26;
        sjs_array_char* sjt_parent13;
        sjs_string* sjt_parent15;
        sjs_array_char* sjt_parent18;

#line 15 "lib/common/string.sj"
        sjt_dot8 = _parent;
#line 17
        sjt_math19 = (sjt_dot8)->count;
#line 15
        sjt_dot9 = item;
#line 17
        sjt_math20 = (sjt_dot9)->count;
#line 17
        sjt_math17 = sjt_math19 + sjt_math20;
#line 17
        sjt_math18 = 1;
#line 17
        sjt_compare19 = sjt_math17 + sjt_math18;
#line 15
        sjt_dot11 = _parent;
#line 1 "lib/common/array.sj"
        sjt_dot10 = &(sjt_dot11)->data;
#line 17 "lib/common/string.sj"
        sjt_compare20 = (sjt_dot10)->dataSize;
#line 17
        sjt_ifElse6 = sjt_compare19 > sjt_compare20;
        if (sjt_ifElse6) {
            sjs_string* sjt_dot12;
            sjs_string* sjt_dot13;
            sjs_string* sjt_dot14;
            int32_t sjt_functionParam33;
            int32_t sjt_math21;
            int32_t sjt_math22;
            int32_t sjt_math23;
            int32_t sjt_math24;
            sjs_array_char* sjt_parent12;

#line 15 "lib/common/string.sj"
            sjt_dot12 = _parent;
#line 113 "lib/common/array.sj"
            sjt_parent12 = &(sjt_dot12)->data;
#line 15 "lib/common/string.sj"
            sjt_dot13 = _parent;
#line 18
            sjt_math23 = (sjt_dot13)->count;
#line 15
            sjt_dot14 = item;
#line 18
            sjt_math24 = (sjt_dot14)->count;
#line 18
            sjt_math21 = sjt_math23 + sjt_math24;
#line 18
            sjt_math22 = 1;
#line 18
            sjt_functionParam33 = sjt_math21 + sjt_math22;
#line 18
            sjf_array_char_grow(sjt_parent12, sjt_functionParam33);
        }

#line 15
        sjt_dot15 = _parent;
#line 32 "lib/common/array.sj"
        sjt_parent13 = &(sjt_dot15)->data;
#line 15 "lib/common/string.sj"
        sjt_dot16 = _parent;
#line 22
        sjt_functionParam34 = (sjt_dot16)->count;
#line 15
        sjt_parent15 = item;
#line 22
        sjt_functionParam37 = 0;
#line 22
        sjf_string_getAt(sjt_parent15, sjt_functionParam37, &sjt_functionParam35);
#line 22
        sjf_array_char_setAt(sjt_parent13, sjt_functionParam34, sjt_functionParam35);
#line 15
        sjt_dot18 = _parent;
#line 15
        sjt_dot19 = _parent;
#line 23
        sjt_math25 = (sjt_dot19)->count;
#line 23
        sjt_math26 = 1;
#line 23
        sjt_dot18->count = sjt_math25 + sjt_math26;
#line 25
        sjt_forStart2 = 1;
#line 15
        sjt_dot20 = item;
#line 25
        sjt_forEnd2 = (sjt_dot20)->count;
#line 25
        i = sjt_forStart2;
        while (i < sjt_forEnd2) {
            sjs_string* sjt_dot21;
            sjs_string* sjt_dot22;
            sjs_string* sjt_dot23;
            sjs_string* sjt_dot24;
            int32_t sjt_functionParam38;
            char sjt_functionParam39;
            int32_t sjt_functionParam40;
            int32_t sjt_math27;
            int32_t sjt_math28;
            sjs_array_char* sjt_parent16;
            sjs_string* sjt_parent17;

#line 15 "lib/common/string.sj"
            sjt_dot21 = _parent;
#line 17 "lib/common/array.sj"
            sjt_parent16 = &(sjt_dot21)->data;
#line 15 "lib/common/string.sj"
            sjt_dot22 = _parent;
#line 26
            sjt_functionParam38 = (sjt_dot22)->count;
#line 15
            sjt_parent17 = item;
#line 25
            sjt_functionParam40 = i;
#line 25
            sjf_string_getAt(sjt_parent17, sjt_functionParam40, &sjt_functionParam39);
#line 25
            sjf_array_char_initAt(sjt_parent16, sjt_functionParam38, sjt_functionParam39);
#line 15
            sjt_dot23 = _parent;
#line 15
            sjt_dot24 = _parent;
#line 27
            sjt_math27 = (sjt_dot24)->count;
#line 27
            sjt_math28 = 1;
#line 27
            sjt_dot23->count = sjt_math27 + sjt_math28;
#line 25
            i++;
        }

#line 15
        sjt_dot25 = _parent;
#line 17 "lib/common/array.sj"
        sjt_parent18 = &(sjt_dot25)->data;
#line 15 "lib/common/string.sj"
        sjt_dot26 = _parent;
#line 30
        sjt_functionParam41 = (sjt_dot26)->count;
#line 30
        sjt_cast3 = 0;
#line 30
        sjt_functionParam42 = (char)sjt_cast3;
#line 30
        sjf_array_char_initAt(sjt_parent18, sjt_functionParam41, sjt_functionParam42);
    }

#line 32
    (*_return) = _parent;
}

void sjf_string_copy(sjs_string* _this, sjs_string* _from) {
#line 6 "lib/common/string.sj"
    _this->count = _from->count;
#line 6
    sjf_array_char_copy(&_this->data, &_from->data);
}

void sjf_string_destroy(sjs_string* _this) {
}

void sjf_string_getAt(sjs_string* _parent, int32_t index, char* _return) {
    sjs_string* sjt_dot17;
    int32_t sjt_functionParam36;
    sjs_array_char* sjt_parent14;

#line 35 "lib/common/string.sj"
    sjt_dot17 = _parent;
#line 7 "lib/common/array.sj"
    sjt_parent14 = &(sjt_dot17)->data;
#line 35 "lib/common/string.sj"
    sjt_functionParam36 = index;
#line 35
    sjf_array_char_getAt(sjt_parent14, sjt_functionParam36, _return);
}

void sjf_string_heap(sjs_string_heap* _this) {
}

int main(int argc, char** argv) {
    sjf_anon1(&sjv_console);
#line 1 "lib/common/f32.sj"
    sjv_f32_pi = 3.14159265358979323846f;
#line 1 "lib/common/i32.sj"
    sjv_u32_maxValue = (uint32_t)4294967295u;
#line 3
    sjt_negate1 = 1;
#line 3
    result1 = -sjt_negate1;
#line 3
    sjt_math1 = result1;
#line 3
    sjt_math2 = 2147483647;
#line 3
    sjv_i32_maxValue = sjt_math1 - sjt_math2;
#line 4
    sjv_i32_minValue = 2147483647;
#line 4
    sjf_anon2(&sjv_parse);
#line 4
    sjf_anon3(&sjv_random);
#line 1 "lib/common/string.sj"
    sjt_cast1 = 0;
#line 1
    sjv_emptyStringData = (uintptr_t)sjt_cast1;
#line 2
    sjv_emptyStringData = (uintptr_t)"";
#line 21 "array7.sj"
    sjv_a.dataSize = 5;
#line 3 "lib/common/array.sj"
    sjt_cast2 = 0;
#line 3
    sjv_a.data = (uintptr_t)sjt_cast2;
#line 4
    sjv_a._isGlobal = false;
#line 5
    sjv_a.count = 0;
#line 5
    sjf_array_class(&sjv_a);
#line 21 "array7.sj"
    sjs_array_class* array1;
#line 21
    array1 = &sjv_a;
#line 21
    sjt_parent1 = array1;
#line 21
    sjt_functionParam1 = 0;
#line 21
    sjt_call1.x = 1;
#line 21
    sjf_class(&sjt_call1);
#line 21
    sjt_functionParam2 = &sjt_call1;
#line 21
    sjf_array_class_initAt(sjt_parent1, sjt_functionParam1, sjt_functionParam2);
#line 21
    sjt_parent2 = array1;
#line 21
    sjt_functionParam3 = 1;
#line 21
    sjt_call2.x = 4;
#line 21
    sjf_class(&sjt_call2);
#line 21
    sjt_functionParam4 = &sjt_call2;
#line 21
    sjf_array_class_initAt(sjt_parent2, sjt_functionParam3, sjt_functionParam4);
#line 21
    sjt_parent3 = array1;
#line 21
    sjt_functionParam5 = 2;
#line 21
    sjt_call3.x = 5;
#line 21
    sjf_class(&sjt_call3);
#line 21
    sjt_functionParam6 = &sjt_call3;
#line 21
    sjf_array_class_initAt(sjt_parent3, sjt_functionParam5, sjt_functionParam6);
#line 21
    sjt_parent4 = array1;
#line 21
    sjt_functionParam7 = 3;
#line 21
    sjt_call4.x = 6;
#line 21
    sjf_class(&sjt_call4);
#line 21
    sjt_functionParam8 = &sjt_call4;
#line 21
    sjf_array_class_initAt(sjt_parent4, sjt_functionParam7, sjt_functionParam8);
#line 21
    sjt_parent5 = array1;
#line 21
    sjt_functionParam9 = 4;
#line 21
    sjt_call5.x = 2;
#line 21
    sjf_class(&sjt_call5);
#line 21
    sjt_functionParam10 = &sjt_call5;
#line 21
    sjf_array_class_initAt(sjt_parent5, sjt_functionParam9, sjt_functionParam10);
#line 203 "lib/common/array.sj"
    sjt_parent10 = &sjv_a;
#line 203
    sjf_array_class_sort(sjt_parent10);
#line 12 "lib/common/console.sj"
    sjt_parent11 = &sjv_console;
#line 220 "lib/common/array.sj"
    sjt_parent23 = &sjv_a;
#line 220
    sjt_call16.count = 2;
#line 220
    sjt_call16.data.dataSize = 3;
#line 220
    sjt_call16.data.data = (uintptr_t)sjg_string1;
#line 220
    sjt_call16.data._isGlobal = true;
#line 220
    sjt_call16.data.count = 3;
#line 220
    sjf_array_char(&sjt_call16.data);
#line 220
    sjf_string(&sjt_call16);
#line 220
    sjt_functionParam50 = &sjt_call16;
#line 220
    sjf_array_class_toString(sjt_parent23, sjt_functionParam50, &sjt_call11);
#line 23 "array7.sj"
    sjt_functionParam32 = &sjt_call11;
#line 23
    sjf_anon1_writeLine(sjt_parent11, sjt_functionParam32);
#line 211 "lib/common/array.sj"
    sjt_parent24 = &sjv_a;
#line 211
    sjf_array_class_reverse(sjt_parent24);
#line 12 "lib/common/console.sj"
    sjt_parent25 = &sjv_console;
#line 220 "lib/common/array.sj"
    sjt_parent26 = &sjv_a;
#line 220
    sjt_call19.count = 2;
#line 220
    sjt_call19.data.dataSize = 3;
#line 220
    sjt_call19.data.data = (uintptr_t)sjg_string1;
#line 220
    sjt_call19.data._isGlobal = true;
#line 220
    sjt_call19.data.count = 3;
#line 220
    sjf_array_char(&sjt_call19.data);
#line 220
    sjf_string(&sjt_call19);
#line 220
    sjt_functionParam58 = &sjt_call19;
#line 220
    sjf_array_class_toString(sjt_parent26, sjt_functionParam58, &sjt_call18);
#line 26 "array7.sj"
    sjt_functionParam57 = &sjt_call18;
#line 26
    sjf_anon1_writeLine(sjt_parent25, sjt_functionParam57);
#line 203 "lib/common/array.sj"
    sjt_parent27 = &sjv_a;
#line 203
    sjf_array_class_sort(sjt_parent27);
#line 12 "lib/common/console.sj"
    sjt_parent28 = &sjv_console;
#line 220 "lib/common/array.sj"
    sjt_parent29 = &sjv_a;
#line 220
    sjt_call21.count = 2;
#line 220
    sjt_call21.data.dataSize = 3;
#line 220
    sjt_call21.data.data = (uintptr_t)sjg_string1;
#line 220
    sjt_call21.data._isGlobal = true;
#line 220
    sjt_call21.data.count = 3;
#line 220
    sjf_array_char(&sjt_call21.data);
#line 220
    sjf_string(&sjt_call21);
#line 220
    sjt_functionParam60 = &sjt_call21;
#line 220
    sjf_array_class_toString(sjt_parent29, sjt_functionParam60, &sjt_call20);
#line 29 "array7.sj"
    sjt_functionParam59 = &sjt_call20;
#line 29
    sjf_anon1_writeLine(sjt_parent28, sjt_functionParam59);
    main_destroy();
    return 0;
}

void main_destroy() {

    sjf_class_destroy(&sjt_call1);
    sjf_string_destroy(&sjt_call11);
    sjf_string_destroy(&sjt_call16);
    sjf_string_destroy(&sjt_call18);
    sjf_string_destroy(&sjt_call19);
    sjf_class_destroy(&sjt_call2);
    sjf_string_destroy(&sjt_call20);
    sjf_string_destroy(&sjt_call21);
    sjf_class_destroy(&sjt_call3);
    sjf_class_destroy(&sjt_call4);
    sjf_class_destroy(&sjt_call5);
    sjf_array_class_destroy(&sjv_a);
    sjf_anon1_destroy(&sjv_console);
    sjf_anon2_destroy(&sjv_parse);
    sjf_anon3_destroy(&sjv_random);
}