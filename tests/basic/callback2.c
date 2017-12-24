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
#define sjs_sum_typeId 3
#define sjs_class_i32_typeId 4
#define cb_i32_void_typeId 5
#define cb_i32_void_heap_typeId 6
#define sjs_array_i32_typeId 7

typedef struct td_sjs_object sjs_object;
typedef struct td_sjs_interface sjs_interface;
typedef struct td_sjs_sum sjs_sum;
typedef struct td_sjs_class_i32 sjs_class_i32;
typedef struct td_cb_i32_void cb_i32_void;
typedef struct td_cb_i32_void_heap cb_i32_void_heap;
typedef struct td_sjs_array_i32 sjs_array_i32;

struct td_sjs_object {
    intptr_t _refCount;
};

struct td_sjs_interface {
    sjs_object* _parent;
    void* _vtbl;
};

struct td_sjs_sum {
    int _refCount;
    int32_t total;
};

struct td_sjs_class_i32 {
    int _refCount;
    int32_t item1;
    int32_t item2;
};

struct td_cb_i32_void {
    sjs_object* _parent;
    void (*_cb)(sjs_object* _parent, int32_t);
};

struct td_cb_i32_void_heap {
    cb_i32_void inner;
    void (*_destroy)(sjs_object*);
};

struct td_sjs_array_i32 {
    int _refCount;
    int32_t datasize;
    void* data;
    bool _isglobal;
    int32_t count;
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
cb_i32_void sjt_functionParam10;
cb_i32_void_heap sjt_functionParam3;
int32_t sjt_functionParam4;
int32_t sjt_functionParam5;
int32_t sjt_functionParam6;
int32_t sjt_functionParam7;
int32_t sjt_math1;
int32_t sjt_math2;
int32_t sjt_negate1;
sjs_class_i32* sjt_parent1 = 0;
sjs_array_i32* sjt_parent2 = 0;
sjs_array_i32* sjt_parent3 = 0;
sjs_array_i32* sjt_parent4 = 0;
sjs_array_i32 sjv_a = { -1 };
sjs_class_i32 sjv_c = { -1 };
void* sjv_emptystringdata;
float sjv_f32_pi;
int32_t sjv_i32_maxvalue;
int32_t sjv_i32_minvalue;
sjs_sum* sjv_s = 0;
uint32_t sjv_u32_maxvalue;

void sjf_array_i32(sjs_array_i32* _this);
void sjf_array_i32_copy(sjs_array_i32* _this, sjs_array_i32* _from);
void sjf_array_i32_destroy(sjs_array_i32* _this);
void sjf_array_i32_each(sjs_array_i32* _parent, cb_i32_void cb);
void sjf_array_i32_getat(sjs_array_i32* _parent, int32_t index, int32_t* _return);
void sjf_array_i32_heap(sjs_array_i32* _this);
void sjf_array_i32_initat(sjs_array_i32* _parent, int32_t index, int32_t item);
void sjf_class_i32(sjs_class_i32* _this);
void sjf_class_i32_copy(sjs_class_i32* _this, sjs_class_i32* _from);
void sjf_class_i32_destroy(sjs_class_i32* _this);
void sjf_class_i32_each(sjs_class_i32* _parent, cb_i32_void_heap cb);
void sjf_class_i32_heap(sjs_class_i32* _this);
void sjf_sum(sjs_sum* _this);
void sjf_sum_copy(sjs_sum* _this, sjs_sum* _from);
void sjf_sum_destroy(sjs_sum* _this);
void sjf_sum_heap(sjs_sum* _this);
void sjf_sum_invoke(sjs_sum* _parent, int32_t a);
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
void sjf_array_i32(sjs_array_i32* _this) {
    if (_this->datasize < 0) {
        halt("size is less than zero");
    }
    if (!_this->data) {
        _this->data = malloc(_this->datasize * sizeof(int32_t));
        if (!_this->data) {
            halt("grow: out of memory\n");
        }
    }
}

void sjf_array_i32_copy(sjs_array_i32* _this, sjs_array_i32* _from) {
    _this->datasize = _from->datasize;
    _this->data = _from->data;
    _this->_isglobal = _from->_isglobal;
    _this->count = _from->count;
    _this->data = _from->data;
    if (!_this->_isglobal && _this->data) {
        ptr_retain(_this->data);
    }
}

void sjf_array_i32_destroy(sjs_array_i32* _this) {
    if (!_this->_isglobal && _this->data) {
        if (ptr_release(_this->data)) {
            int32_t* p = (int32_t*)_this->data;
            for (int i = 0; i < _this->count; i++) {
                ;
            }
            free(p);
        }
    }
}

void sjf_array_i32_each(sjs_array_i32* _parent, cb_i32_void cb) {
    int32_t i;
    sjs_array_i32* sjt_dot5 = 0;
    int32_t sjt_forEnd1;
    int32_t sjt_forStart1;

    sjt_forStart1 = 0;
    sjt_dot5 = _parent;
    sjt_forEnd1 = (sjt_dot5)->count;
    i = sjt_forStart1;
    while (i < sjt_forEnd1) {
        cb_i32_void sjt_callback3;
        int32_t sjt_functionParam8;
        int32_t sjt_functionParam9;

        sjt_callback3 = cb;
        sjt_functionParam9 = i;
        sjf_array_i32_getat(_parent, sjt_functionParam9, &sjt_functionParam8);
        sjt_callback3._cb(sjt_callback3._parent, sjt_functionParam8);
        i++;
    }
}

void sjf_array_i32_getat(sjs_array_i32* _parent, int32_t index, int32_t* _return) {
    if (index >= _parent->count || index < 0) {
        halt("getAt: out of bounds\n");
    }
    int32_t* p = (int32_t*)_parent->data;
    (*_return) = p[index];
return;;       
}

void sjf_array_i32_heap(sjs_array_i32* _this) {
    if (_this->datasize < 0) {
        halt("size is less than zero");
    }
    if (!_this->data) {
        _this->data = malloc(_this->datasize * sizeof(int32_t));
        if (!_this->data) {
            halt("grow: out of memory\n");
        }
    }
}

void sjf_array_i32_initat(sjs_array_i32* _parent, int32_t index, int32_t item) {
    if (index != _parent->count) {
        halt("initAt: can only initialize last element\n");     
    }
    if (index >= _parent->datasize || index < 0) {
        halt("initAt: out of bounds %d:%d\n", index, _parent->datasize);
    }
    int32_t* p = (int32_t*)_parent->data;
    p[index] = item;
;
    _parent->count = index + 1;
}

void sjf_class_i32(sjs_class_i32* _this) {
}

void sjf_class_i32_copy(sjs_class_i32* _this, sjs_class_i32* _from) {
    _this->item1 = _from->item1;
    _this->item2 = _from->item2;
}

void sjf_class_i32_destroy(sjs_class_i32* _this) {
}

void sjf_class_i32_each(sjs_class_i32* _parent, cb_i32_void_heap cb) {
    cb_i32_void sjt_callback1;
    cb_i32_void sjt_callback2;
    sjs_class_i32* sjt_dot1 = 0;
    sjs_class_i32* sjt_dot2 = 0;
    int32_t sjt_functionParam1;
    int32_t sjt_functionParam2;

    sjt_callback1 = cb.inner;
    sjt_dot1 = _parent;
    sjt_functionParam1 = (sjt_dot1)->item1;
    sjt_callback1._cb(sjt_callback1._parent, sjt_functionParam1);
    sjt_callback2 = cb.inner;
    sjt_dot2 = _parent;
    sjt_functionParam2 = (sjt_dot2)->item2;
    sjt_callback2._cb(sjt_callback2._parent, sjt_functionParam2);
}

void sjf_class_i32_heap(sjs_class_i32* _this) {
}

void sjf_sum(sjs_sum* _this) {
}

void sjf_sum_copy(sjs_sum* _this, sjs_sum* _from) {
    _this->total = _from->total;
}

void sjf_sum_destroy(sjs_sum* _this) {
}

void sjf_sum_heap(sjs_sum* _this) {
}

void sjf_sum_invoke(sjs_sum* _parent, int32_t a) {
    sjs_sum* sjt_dot3 = 0;
    sjs_sum* sjt_dot4 = 0;
    int32_t sjt_math3;
    int32_t sjt_math4;

    sjt_dot3 = _parent;
    sjt_dot4 = _parent;
    sjt_math3 = (sjt_dot4)->total;
    sjt_math4 = a;
    sjt_dot3->total = sjt_math3 + sjt_math4;
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
    sjv_s = (sjs_sum*)malloc(sizeof(sjs_sum));
    sjv_s->_refCount = 1;
    sjv_s->total = 0;
    sjf_sum_heap(sjv_s);
    sjv_c._refCount = 1;
    sjv_c.item1 = 3;
    sjv_c.item2 = 4;
    sjf_class_i32(&sjv_c);
    sjt_parent1 = &sjv_c;
    sjt_functionParam3.inner._parent = (sjs_object*)sjv_s;
    sjt_functionParam3.inner._parent->_refCount++;
    sjt_functionParam3._destroy = (void(*)(sjs_object*))sjf_sum_destroy;
    sjt_functionParam3.inner._cb = (void(*)(sjs_object*,int32_t))sjf_sum_invoke;
    sjf_class_i32_each(sjt_parent1, sjt_functionParam3);
    sjv_a._refCount = 1;
    sjv_a.datasize = 2;
    sjv_a.data = 0;
    sjv_a._isglobal = false;
    sjv_a.count = 0;
    sjf_array_i32(&sjv_a);
    sjs_array_i32* array1;
    array1 = &sjv_a;
    sjt_parent2 = array1;
    sjt_functionParam4 = 0;
    sjt_functionParam5 = 1;
    sjf_array_i32_initat(sjt_parent2, sjt_functionParam4, sjt_functionParam5);
    sjt_parent3 = array1;
    sjt_functionParam6 = 1;
    sjt_functionParam7 = 2;
    sjf_array_i32_initat(sjt_parent3, sjt_functionParam6, sjt_functionParam7);
    sjt_parent4 = &sjv_a;
    sjt_functionParam10._parent = (sjs_object*)sjv_s;
    sjt_functionParam10._cb = (void(*)(sjs_object*,int32_t))sjf_sum_invoke;
    sjf_array_i32_each(sjt_parent4, sjt_functionParam10);
    main_destroy();
    #ifdef _DEBUG
    printf("\npress return to end\n");
    getchar();
    #endif
    return 0;
}

void main_destroy() {

    if ((uintptr_t)sjt_functionParam3.inner._parent > 1) {
        sjt_functionParam3.inner._parent->_refCount--;
        if (sjt_functionParam3.inner._parent->_refCount <= 0) {
            sjt_functionParam3._destroy(sjt_functionParam3.inner._parent);
            free(sjt_functionParam3.inner._parent);
        }
    }
    sjv_s->_refCount--;
    if (sjv_s->_refCount <= 0) {
        weakptr_release(sjv_s);
        sjf_sum_destroy(sjv_s);
        free(sjv_s);
    }
    if (sjv_a._refCount == 1) { sjf_array_i32_destroy(&sjv_a); }
    if (sjv_c._refCount == 1) { sjf_class_i32_destroy(&sjv_c); }
}
