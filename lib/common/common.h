#ifdef __GNUC__
    #if __x86_64__ 
        #define __LINUX__
        #define __64__
    #elif __i386__ 
        #define __LINUX__
        #define __32__
    #else
        #define __LINUX__
        #define __32__
    #endif
#elif _MSC_VER
    #if _WIN64 
        #define __WINDOWS__
        #define __64__
    #elif _WIN32 
        #define __WINDOWS__
        #define __32__
    #else
        #error "WINDOWS UNSUPPORTED BITS"
    #endif
#else
    #error "UNKNOWN PLATFORM"
#endif

#include <stdio.h>
#include <stdarg.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>
#ifdef __WINDOWS__
#include <windows.h>
#endif
#include <lib/common/khash.h>

typedef struct td_delete_cb delete_cb;
typedef struct td_delete_cb_list delete_cb_list;
typedef struct td_int32_option int32_option;
typedef struct td_uint32_option uint32_option;
typedef struct td_int64_option int64_option;
typedef struct td_uint64_option uint64_option;
typedef struct td_sjs_object sjs_object;
typedef struct td_sjs_interface sjs_interface;
typedef struct td_void_option void_option;
typedef struct td_char_option char_option;
typedef struct td_float_option float_option;
typedef struct td_double_option double_option;

struct td_delete_cb {
    void* _parent;
    void (*_cb)(void* _parent, void* object);
};

struct td_delete_cb_list {
    int size;
    delete_cb cb[5];
    delete_cb_list* next;
};

struct td_int32_option {
    bool isvalid;
    int32_t value;
};
const int32_option int32_empty = { false };

struct td_uint32_option {
    bool isvalid;
    uint32_t value;
};
const uint32_option uint32_empty = { false };

struct td_int64_option {
    bool isvalid;
    int64_t value;
};
const int64_option int64_empty = { false };

struct td_uint64_option {
    bool isvalid;
    uint64_t value;
};
const uint64_option uint64_empty = { false };

struct td_void_option {
    bool isvalid;
    void* value;
};
const void_option void_empty = { false };

struct td_char_option {
    bool isvalid;
    char value;
};
const char_option char_empty = { false };

struct td_float_option {
    bool isvalid;
    float value;
};
const float_option float_empty = { false };

struct td_double_option {
    bool isvalid;
    double value;
};
const double_option double_empty = { false };

struct td_sjs_object {
    int _refCount;
};

struct td_sjs_interface {
    sjs_object* _parent;
    void* _vtbl;
};

void halt(const char * format, ...);
void debugout(const char * format, ...);
void debugoutv(const char * format, va_list args);
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
void _object_init(sjs_object* obj, int typeid, char* funcname);
void _object_retain(sjs_object* obj, char* funcname);
void _object_release(sjs_object* obj, char* funcname);
void _object_report(void);