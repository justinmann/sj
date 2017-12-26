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
#include <lib/common/khash.h>
#include <lib/common/value_option_types.h>
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
#define sjs_array_heap_class_typeId 4
#define sjs_list_heap_class_typeId 5

typedef struct td_sjs_object sjs_object;
typedef struct td_sjs_interface sjs_interface;
typedef struct td_sjs_class sjs_class;
typedef struct td_sjs_array_heap_class sjs_array_heap_class;
typedef struct td_sjs_list_heap_class sjs_list_heap_class;

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

struct td_sjs_array_heap_class {
    int _refCount;
    int32_t datasize;
    void* data;
    bool _isglobal;
    int32_t count;
};

struct td_sjs_list_heap_class {
    int _refCount;
    sjs_array_heap_class array;
};

void debugout(const char * format, ...);
void debugoutv(const char * format, va_list args);
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
#include <lib/common/object.h>
int32_t i;
int32_t result1;
int32_t sjt_forEnd1;
int32_t sjt_forStart1;
int32_t sjt_math1;
int32_t sjt_math2;
int32_t sjt_negate1;
sjs_list_heap_class sjv_a = { -1 };
void* sjv_emptystringdata;
float sjv_f32_pi;
int32_t sjv_i32_maxvalue;
int32_t sjv_i32_minvalue;
uint32_t sjv_u32_maxvalue;

void sjf_array_heap_class(sjs_array_heap_class* _this);
void sjf_array_heap_class_copy(sjs_array_heap_class* _this, sjs_array_heap_class* _from);
void sjf_array_heap_class_destroy(sjs_array_heap_class* _this);
void sjf_array_heap_class_grow(sjs_array_heap_class* _parent, int32_t newsize, sjs_array_heap_class* _return);
void sjf_array_heap_class_grow_heap(sjs_array_heap_class* _parent, int32_t newsize, sjs_array_heap_class** _return);
void sjf_array_heap_class_heap(sjs_array_heap_class* _this);
void sjf_array_heap_class_initat(sjs_array_heap_class* _parent, int32_t index, sjs_class* item);
void sjf_class(sjs_class* _this);
void sjf_class_copy(sjs_class* _this, sjs_class* _from);
void sjf_class_destroy(sjs_class* _this);
void sjf_class_heap(sjs_class* _this);
void sjf_i32_max(int32_t a, int32_t b, int32_t* _return);
void sjf_list_heap_class(sjs_list_heap_class* _this);
void sjf_list_heap_class_add(sjs_list_heap_class* _parent, sjs_class* item);
void sjf_list_heap_class_copy(sjs_list_heap_class* _this, sjs_list_heap_class* _from);
void sjf_list_heap_class_destroy(sjs_list_heap_class* _this);
void sjf_list_heap_class_heap(sjs_list_heap_class* _this);
void main_destroy(void);

void debugout(const char * format, ...) {
    va_list args;
    va_start(args, format);
    debugoutv(format, args);
    va_end(args);
}
void debugoutv(const char * format, va_list args) {
    #ifdef _WINDOWS
    char text[1024];
    vsnprintf(text, sizeof(text), format, args);
    OutputDebugStringA(text);
    #else
    vfprintf(stderr, format, args);
    #endif
}
void halt(const char * format, ...) {
    va_list args;
    va_start(args, format);
    debugoutv(format, args);
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
#include <lib/common/object.c>
void sjf_array_heap_class(sjs_array_heap_class* _this) {
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

void sjf_array_heap_class_copy(sjs_array_heap_class* _this, sjs_array_heap_class* _from) {
    _this->datasize = _from->datasize;
    _this->data = _from->data;
    _this->_isglobal = _from->_isglobal;
    _this->count = _from->count;
    _this->data = _from->data;
    if (!_this->_isglobal && _this->data) {
        ptr_retain(_this->data);
    }
}

void sjf_array_heap_class_destroy(sjs_array_heap_class* _this) {
    if (!_this->_isglobal && _this->data) {
        if (ptr_release(_this->data)) {
            sjs_class** p = (sjs_class**)_this->data;
            for (int i = 0; i < _this->count; i++) {
                p[i]->_refCount--;
if (p[i]->_refCount <= 0) {
    weakptr_release(p[i]);
    sjf_class_destroy(p[i]);
    free(p[i]);
}
;
            }
            free(p);
        }
    }
}

void sjf_array_heap_class_grow(sjs_array_heap_class* _parent, int32_t newsize, sjs_array_heap_class* _return) {
    sjs_array_heap_class* sjt_dot6 = 0;
    void* sjv_newdata;

    sjv_newdata = 0;
    if (_parent->datasize != newsize) {
        if (newsize < _parent->datasize) {
            halt("grow: new size smaller than old _parent->datasize %d:%d\n", newsize, _parent->datasize);
        }
        sjv_newdata = malloc(newsize * sizeof(sjs_class*));
        if (!_parent->data) {
            halt("grow: out of memory\n");
        }
        sjs_class** p = (sjs_class**)_parent->data;
        sjs_class** newp = (sjs_class**)sjv_newdata;
        int count = _parent->count;
        for (int i = 0; i < count; i++) {
            newp[i] = p[i];
newp[i]->_refCount++;
;
        }
    }
    _return->_refCount = 1;
    _return->datasize = newsize;
    _return->data = sjv_newdata;
    _return->_isglobal = false;
    sjt_dot6 = _parent;
    _return->count = sjt_dot6->count;
    sjf_array_heap_class(_return);
}

void sjf_array_heap_class_grow_heap(sjs_array_heap_class* _parent, int32_t newsize, sjs_array_heap_class** _return) {
    sjs_array_heap_class* sjt_dot7 = 0;
    void* sjv_newdata;

    sjv_newdata = 0;
    if (_parent->datasize != newsize) {
        if (newsize < _parent->datasize) {
            halt("grow: new size smaller than old _parent->datasize %d:%d\n", newsize, _parent->datasize);
        }
        sjv_newdata = malloc(newsize * sizeof(sjs_class*));
        if (!_parent->data) {
            halt("grow: out of memory\n");
        }
        sjs_class** p = (sjs_class**)_parent->data;
        sjs_class** newp = (sjs_class**)sjv_newdata;
        int count = _parent->count;
        for (int i = 0; i < count; i++) {
            newp[i] = p[i];
newp[i]->_refCount++;
;
        }
    }
    (*_return) = (sjs_array_heap_class*)malloc(sizeof(sjs_array_heap_class));
    (*_return)->_refCount = 1;
    (*_return)->datasize = newsize;
    (*_return)->data = sjv_newdata;
    (*_return)->_isglobal = false;
    sjt_dot7 = _parent;
    (*_return)->count = sjt_dot7->count;
    sjf_array_heap_class_heap((*_return));
}

void sjf_array_heap_class_heap(sjs_array_heap_class* _this) {
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

void sjf_array_heap_class_initat(sjs_array_heap_class* _parent, int32_t index, sjs_class* item) {
    if (index != _parent->count) {
        halt("initAt: can only initialize last element\n");     
    }
    if (index >= _parent->datasize || index < 0) {
        halt("initAt: out of bounds %d:%d\n", index, _parent->datasize);
    }
    sjs_class** p = (sjs_class**)_parent->data;
    p[index] = item;
p[index]->_refCount++;
;
    _parent->count = index + 1;
}

void sjf_class(sjs_class* _this) {
}

void sjf_class_copy(sjs_class* _this, sjs_class* _from) {
    _this->x = _from->x;
}

void sjf_class_destroy(sjs_class* _this) {
}

void sjf_class_heap(sjs_class* _this) {
}

void sjf_i32_max(int32_t a, int32_t b, int32_t* _return) {
    int32_t sjt_compare3;
    int32_t sjt_compare4;
    bool sjt_ifElse2;

    sjt_compare3 = a;
    sjt_compare4 = b;
    sjt_ifElse2 = sjt_compare3 < sjt_compare4;
    if (sjt_ifElse2) {
        (*_return) = b;
    } else {
        (*_return) = a;
    }
}

void sjf_list_heap_class(sjs_list_heap_class* _this) {
}

void sjf_list_heap_class_add(sjs_list_heap_class* _parent, sjs_class* item) {
    sjs_array_heap_class sjt_call1 = { -1 };
    int32_t sjt_compare1;
    int32_t sjt_compare2;
    sjs_array_heap_class* sjt_dot1 = 0;
    sjs_list_heap_class* sjt_dot11 = 0;
    sjs_array_heap_class* sjt_dot12 = 0;
    sjs_list_heap_class* sjt_dot13 = 0;
    sjs_list_heap_class* sjt_dot2 = 0;
    sjs_array_heap_class* sjt_dot3 = 0;
    sjs_list_heap_class* sjt_dot4 = 0;
    int32_t sjt_functionParam4;
    sjs_class* sjt_functionParam5 = 0;
    bool sjt_ifElse1;
    sjs_array_heap_class* sjt_parent2 = 0;

    sjt_dot2 = _parent;
    sjt_dot1 = &sjt_dot2->array;
    sjt_compare1 = sjt_dot1->count;
    sjt_dot4 = _parent;
    sjt_dot3 = &sjt_dot4->array;
    sjt_compare2 = sjt_dot3->datasize;
    sjt_ifElse1 = sjt_compare1 >= sjt_compare2;
    if (sjt_ifElse1) {
        sjs_array_heap_class* sjt_copy1 = 0;
        sjs_list_heap_class* sjt_dot10 = 0;
        sjs_list_heap_class* sjt_dot5 = 0;
        sjs_list_heap_class* sjt_dot8 = 0;
        sjs_array_heap_class* sjt_dot9 = 0;
        int32_t sjt_functionParam1;
        int32_t sjt_functionParam2;
        int32_t sjt_functionParam3;
        int32_t sjt_math3;
        int32_t sjt_math4;
        sjs_array_heap_class* sjt_parent1 = 0;

        sjt_dot5 = _parent;
        sjt_dot8 = _parent;
        sjt_parent1 = &sjt_dot8->array;
        sjt_functionParam2 = 10;
        sjt_dot10 = _parent;
        sjt_dot9 = &sjt_dot10->array;
        sjt_math3 = sjt_dot9->datasize;
        sjt_math4 = 2;
        sjt_functionParam3 = sjt_math3 * sjt_math4;
        sjf_i32_max(sjt_functionParam2, sjt_functionParam3, &sjt_functionParam1);
        sjf_array_heap_class_grow(sjt_parent1, sjt_functionParam1, &sjt_call1);
        sjt_copy1 = &sjt_call1;
        if (sjt_dot5->array._refCount == 1) { sjf_array_heap_class_destroy(&sjt_dot5->array); }
;
        sjt_dot5->array._refCount = 1;
        sjf_array_heap_class_copy(&sjt_dot5->array, sjt_copy1);
    }

    sjt_dot11 = _parent;
    sjt_parent2 = &sjt_dot11->array;
    sjt_dot13 = _parent;
    sjt_dot12 = &sjt_dot13->array;
    sjt_functionParam4 = sjt_dot12->count;
    sjt_functionParam5 = item;
    sjt_functionParam5->_refCount++;
    sjf_array_heap_class_initat(sjt_parent2, sjt_functionParam4, sjt_functionParam5);

    sjt_functionParam5->_refCount--;
    if (sjt_functionParam5->_refCount <= 0) {
        weakptr_release(sjt_functionParam5);
        sjf_class_destroy(sjt_functionParam5);
        free(sjt_functionParam5);
    }
    if (sjt_call1._refCount == 1) { sjf_array_heap_class_destroy(&sjt_call1); }
;
}

void sjf_list_heap_class_copy(sjs_list_heap_class* _this, sjs_list_heap_class* _from) {
    _this->array._refCount = 1;
    sjf_array_heap_class_copy(&_this->array, &_from->array);
}

void sjf_list_heap_class_destroy(sjs_list_heap_class* _this) {
    if (_this->array._refCount == 1) { sjf_array_heap_class_destroy(&_this->array); }
;
}

void sjf_list_heap_class_heap(sjs_list_heap_class* _this) {
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
    sjv_a.array._refCount = 1;
    sjv_a.array.datasize = 0;
    sjv_a.array.data = 0;
    sjv_a.array._isglobal = false;
    sjv_a.array.count = 0;
    sjf_array_heap_class(&sjv_a.array);
    sjf_list_heap_class(&sjv_a);
    sjt_forStart1 = 0;
    sjt_forEnd1 = 100;
    i = sjt_forStart1;
    while (i < sjt_forEnd1) {
        sjs_class* sjt_functionParam6 = 0;
        sjs_list_heap_class* sjt_parent3 = 0;

        sjt_parent3 = &sjv_a;
        sjt_functionParam6 = (sjs_class*)malloc(sizeof(sjs_class));
        sjt_functionParam6->_refCount = 1;
        sjt_functionParam6->x = i;
        sjf_class_heap(sjt_functionParam6);
        sjf_list_heap_class_add(sjt_parent3, sjt_functionParam6);
        i++;

        sjt_functionParam6->_refCount--;
        if (sjt_functionParam6->_refCount <= 0) {
            weakptr_release(sjt_functionParam6);
            sjf_class_destroy(sjt_functionParam6);
            free(sjt_functionParam6);
        }
    }
    main_destroy();
    #ifdef _DEBUG
    printf("\npress return to end\n");
    getchar();
    #endif
    return 0;
}

void main_destroy() {

    if (sjv_a._refCount == 1) { sjf_list_heap_class_destroy(&sjv_a); }
;
}
