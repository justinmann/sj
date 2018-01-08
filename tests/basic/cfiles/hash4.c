#include <lib/sj-lib-common/common.h>

struct {
    int refcount;
    int size;
    int count;
    char data[4];
} sjg_string1 = { 1, 4, 3, " = "};

struct {
    int refcount;
    int size;
    int count;
    char data[1];
} g_empty = { 1, 1, 0, "" };
#define sjs_hash_type_bool_typeId 15
#define sjs_log_typeId 20
#define sjs_array_char_typeId 23
#define sjs_string_typeId 21
#define sji_interface_typeId 26
#define sjs_hash_heap_iface_interface_i32_typeId 27
#define sjs_class_typeId 32
#define cb_heap_iface_interface_i32_void_typeId 37
#define cb_heap_iface_interface_i32_void_heap_typeId 37
#define cb_local_iface_interface_i32_void_typeId 46
#define cb_local_iface_interface_i32_void_heap_typeId 46

typedef struct td_sjs_hash_type_bool sjs_hash_type_bool;
typedef struct td_sjs_log sjs_log;
typedef struct td_sjs_array_char sjs_array_char;
typedef struct td_sjs_string sjs_string;
typedef struct td_sji_interface sji_interface;
typedef struct td_sji_interface_vtbl sji_interface_vtbl;
typedef struct td_sjs_hash_heap_iface_interface_i32 sjs_hash_heap_iface_interface_i32;
typedef struct td_sjs_class sjs_class;
typedef struct td_cb_heap_iface_interface_i32_void cb_heap_iface_interface_i32_void;
typedef struct td_cb_heap_iface_interface_i32_void_heap cb_heap_iface_interface_i32_void_heap;
typedef struct td_cb_local_iface_interface_i32_void cb_local_iface_interface_i32_void;
typedef struct td_cb_local_iface_interface_i32_void_heap cb_local_iface_interface_i32_void_heap;

struct td_sjs_hash_type_bool {
    int _refCount;
    void* _hash;
};

struct td_sjs_log {
    int _refCount;
    int32_t minlevel;
    sjs_hash_type_bool traceincludes;
    sjs_hash_type_bool debugincludes;
    sjs_hash_type_bool infoincludes;
    sjs_hash_type_bool warnincludes;
    sjs_hash_type_bool errorincludes;
    sjs_hash_type_bool fatalincludes;
};

struct td_sjs_array_char {
    int _refCount;
    void* v;
};

struct td_sjs_string {
    int _refCount;
    int32_t offset;
    int32_t count;
    sjs_array_char data;
    bool _isnullterminated;
};

struct td_sji_interface {
    sjs_object* _parent;
    sji_interface_vtbl* _vtbl;
};

struct td_sji_interface_vtbl {
    void (*destroy)(void* _this);
    void (*asinterface)(sjs_object* _this, int typeId, sjs_interface* _return);
    void (*getclasstype)(sjs_object* _parent, int32_t* _return);
    void (*bob)(sjs_object* _parent, int32_t* _return);
    void (*hash)(sjs_object* _parent, uint32_t* _return);
    void (*isequal)(sjs_object* _parent, sji_interface b, bool* _return);
};

struct td_sjs_hash_heap_iface_interface_i32 {
    int _refCount;
    void* _hash;
};

struct td_sjs_class {
    int _refCount;
    int32_t x;
};

struct td_cb_heap_iface_interface_i32_void {
    sjs_object* _parent;
    void (*_cb)(sjs_object* _parent, sji_interface, int32_t);
};

struct td_cb_heap_iface_interface_i32_void_heap {
    cb_heap_iface_interface_i32_void inner;
    void (*_destroy)(sjs_object*);
};

struct td_cb_local_iface_interface_i32_void {
    sjs_object* _parent;
    void (*_cb)(sjs_object* _parent, sji_interface, int32_t);
};

struct td_cb_local_iface_interface_i32_void_heap {
    cb_local_iface_interface_i32_void inner;
    void (*_destroy)(sjs_object*);
};

sji_interface_vtbl sjs_class_interface_vtbl;
#ifndef type_bool_hash_typedef
#define type_bool_hash_typedef
KHASH_INIT_TYPEDEF(type_bool_hash_type, int32_t, bool)
#endif
#ifndef type_bool_hash_typedef
#define type_bool_hash_typedef
KHASH_INIT_TYPEDEF(type_bool_hash_type, int32_t, bool)
#endif
char* string_char(sjs_string* str);
#ifndef heap_iface_interface_i32_hash_typedef
#define heap_iface_interface_i32_hash_typedef
KHASH_INIT_TYPEDEF(heap_iface_interface_i32_hash_type, sji_interface, int32_t)
#endif
#ifndef heap_iface_interface_i32_hash_typedef
#define heap_iface_interface_i32_hash_typedef
KHASH_INIT_TYPEDEF(heap_iface_interface_i32_hash_type, sji_interface, int32_t)
#endif
int32_t g_loglevel_debug;
int32_t g_loglevel_error;
int32_t g_loglevel_fatal;
int32_t g_loglevel_info;
int32_t g_loglevel_trace;
int32_t g_loglevel_warn;

sjs_hash_heap_iface_interface_i32 g_a = { -1 };
int32_option g_b;
int32_t g_clocks_per_sec;
float g_f32_pi;
int32_t g_i32_maxvalue;
int32_t g_i32_minvalue;
sjs_log g_log = { -1 };
sjs_hash_type_bool g_log_excludeall = { -1 };
sjs_hash_type_bool g_log_includeall = { -1 };
uint32_t g_u32_maxvalue;
int32_t result1;
sjs_class* sjt_call1 = 0;
sjs_class* sjt_call2 = 0;
sjs_string sjt_call8 = { -1 };
sjs_class* sjt_cast2 = 0;
sjs_class* sjt_cast4 = 0;
sjs_string* sjt_functionParam34 = 0;
int32_t sjt_functionParam35;
int32_t sjt_functionParam36;
sji_interface sjt_functionParam4 = { 0 };
int32_t sjt_functionParam5;
sji_interface sjt_functionParam6 = { 0 };
cb_heap_iface_interface_i32_void sjt_functionParam7;
sjs_hash_heap_iface_interface_i32* sjt_parent3 = 0;
sjs_hash_heap_iface_interface_i32* sjt_parent5 = 0;
sjs_hash_heap_iface_interface_i32* sjt_parent6 = 0;
sjs_hash_type_bool sjt_value1 = { -1 };

void sjf_array_char(sjs_array_char* _this);
void sjf_array_char_clone(sjs_array_char* _parent, int32_t offset, int32_t count, int32_t newsize, sjs_array_char* _return);
void sjf_array_char_clone_heap(sjs_array_char* _parent, int32_t offset, int32_t count, int32_t newsize, sjs_array_char** _return);
void sjf_array_char_copy(sjs_array_char* _this, sjs_array_char* _from);
void sjf_array_char_destroy(sjs_array_char* _this);
void sjf_array_char_getat(sjs_array_char* _parent, int32_t index, char* _return);
void sjf_array_char_getcount(sjs_array_char* _parent, int32_t* _return);
void sjf_array_char_getsize(sjs_array_char* _parent, int32_t* _return);
void sjf_array_char_heap(sjs_array_char* _this);
void sjf_array_char_initat(sjs_array_char* _parent, int32_t index, char item);
void sjf_class(sjs_class* _this);
void sjf_class_as_sji_interface(sjs_class* _this, sji_interface* _return);
void sjf_class_asinterface(sjs_class* _this, int typeId, sjs_interface* _return);
void sjf_class_bob(sjs_class* _parent, int32_t* _return);
void sjf_class_copy(sjs_class* _this, sjs_class* _from);
void sjf_class_destroy(sjs_class* _this);
void sjf_class_getclasstype(sjs_object* _this, int* _return);
void sjf_class_hash(sjs_class* _parent, uint32_t* _return);
void sjf_class_heap(sjs_class* _this);
void sjf_class_isequal(sjs_class* _parent, sji_interface b, bool* _return);
void sjf_debug_writeline(sjs_string* data);
void sjf_hash_heap_iface_interface_i32(sjs_hash_heap_iface_interface_i32* _this);
void sjf_hash_heap_iface_interface_i32__weakptrremovekey(sjs_hash_heap_iface_interface_i32* _parent, sji_interface key);
void sjf_hash_heap_iface_interface_i32__weakptrremovevalue(sjs_hash_heap_iface_interface_i32* _parent, int32_t val);
void sjf_hash_heap_iface_interface_i32_copy(sjs_hash_heap_iface_interface_i32* _this, sjs_hash_heap_iface_interface_i32* _from);
void sjf_hash_heap_iface_interface_i32_destroy(sjs_hash_heap_iface_interface_i32* _this);
void sjf_hash_heap_iface_interface_i32_each(sjs_hash_heap_iface_interface_i32* _parent, cb_heap_iface_interface_i32_void cb);
void sjf_hash_heap_iface_interface_i32_getat(sjs_hash_heap_iface_interface_i32* _parent, sji_interface key, int32_option* _return);
void sjf_hash_heap_iface_interface_i32_heap(sjs_hash_heap_iface_interface_i32* _this);
void sjf_hash_heap_iface_interface_i32_setat(sjs_hash_heap_iface_interface_i32* _parent, sji_interface key, int32_t val);
void sjf_hash_type_bool(sjs_hash_type_bool* _this);
void sjf_hash_type_bool__weakptrremovekey(sjs_hash_type_bool* _parent, int32_t key);
void sjf_hash_type_bool__weakptrremovevalue(sjs_hash_type_bool* _parent, bool val);
void sjf_hash_type_bool_copy(sjs_hash_type_bool* _this, sjs_hash_type_bool* _from);
void sjf_hash_type_bool_destroy(sjs_hash_type_bool* _this);
void sjf_hash_type_bool_heap(sjs_hash_type_bool* _this);
void sjf_i32_asstring(int32_t val, int32_t base, sjs_string* _return);
void sjf_i32_asstring_heap(int32_t val, int32_t base, sjs_string** _return);
void sjf_log(sjs_log* _this);
void sjf_log_copy(sjs_log* _this, sjs_log* _from);
void sjf_log_destroy(sjs_log* _this);
void sjf_log_heap(sjs_log* _this);
void sjf_print(sji_interface k, int32_t v);
void sjf_print_callback(void * _parent, sji_interface k, int32_t v);
void sjf_string(sjs_string* _this);
void sjf_string_add(sjs_string* _parent, sjs_string* item, sjs_string* _return);
void sjf_string_add_heap(sjs_string* _parent, sjs_string* item, sjs_string** _return);
void sjf_string_copy(sjs_string* _this, sjs_string* _from);
void sjf_string_destroy(sjs_string* _this);
void sjf_string_getat(sjs_string* _parent, int32_t index, char* _return);
void sjf_string_heap(sjs_string* _this);
void sjf_string_nullterminate(sjs_string* _parent);
void sjf_type_hash(int32_t val, uint32_t* _return);
void sjf_type_isequal(int32_t l, int32_t r, bool* _return);
void sji_interface_hash(sji_interface _parent, uint32_t* _return);
void sji_interface_isequal(sji_interface _parent, sji_interface b, bool* _return);
void main_destroy(void);

#ifndef type_bool_hash_function
#define type_bool_hash_function
#if false
KHASH_INIT_FUNCTION_DEREF(type_bool_hash_type, int32_t, bool, 1, sjf_type_hash, sjf_type_isequal)
#else
KHASH_INIT_FUNCTION(type_bool_hash_type, int32_t, bool, 1, sjf_type_hash, sjf_type_isequal)
#endif
#endif
#ifndef type_bool_hash_function
#define type_bool_hash_function
#if false
KHASH_INIT_FUNCTION_DEREF(type_bool_hash_type, int32_t, bool, 1, sjf_type_hash, sjf_type_isequal)
#else
KHASH_INIT_FUNCTION(type_bool_hash_type, int32_t, bool, 1, sjf_type_hash, sjf_type_isequal)
#endif
#endif
char* string_char(sjs_string* str) {
    sjf_string_nullterminate(str);
    return ((sjs_array*)str->data.v)->data;
}
#include <lib/sj-lib-common/common.cpp>
#ifndef heap_iface_interface_i32_hash_function
#define heap_iface_interface_i32_hash_function
#if false
KHASH_INIT_FUNCTION_DEREF(heap_iface_interface_i32_hash_type, sji_interface, int32_t, 1, sji_interface_hash, sji_interface_isequal)
#else
KHASH_INIT_FUNCTION(heap_iface_interface_i32_hash_type, sji_interface, int32_t, 1, sji_interface_hash, sji_interface_isequal)
#endif
#endif
#ifndef heap_iface_interface_i32_hash_function
#define heap_iface_interface_i32_hash_function
#if false
KHASH_INIT_FUNCTION_DEREF(heap_iface_interface_i32_hash_type, sji_interface, int32_t, 1, sji_interface_hash, sji_interface_isequal)
#else
KHASH_INIT_FUNCTION(heap_iface_interface_i32_hash_type, sji_interface, int32_t, 1, sji_interface_hash, sji_interface_isequal)
#endif
#endif
void sjf_array_char(sjs_array_char* _this) {
#line 356 "lib/sj-lib-common/array.sj"
    if (_this->v == 0) {
#line 357
        _this->v = &g_empty;
#line 358
    }
#line 359
    sjs_array* arr = (sjs_array*)_this->v;
#line 360
    arr->refcount++;
}

void sjf_array_char_clone(sjs_array_char* _parent, int32_t offset, int32_t count, int32_t newsize, sjs_array_char* _return) {
    void* newv;

#line 170 "lib/sj-lib-common/array.sj"
    newv = 0;
#line 172
    sjs_array* arr = (sjs_array*)_parent->v;
#line 173
    if (offset + count > arr->count) {
#line 174
        halt("grow: offset %d count %d out of bounds %d\n", offset, count, arr->count);
#line 175
    }
#line 177
    if (count > arr->count - offset) {
#line 178
        halt("grow: new count larger than old count %d:%d\n", count, arr->count - offset);
#line 179
    }
#line 181
    sjs_array* newArr = createarray(newsize * sizeof(char));
#line 182
    if (!newArr) {
#line 183
        halt("grow: out of memory\n");
#line 184
    }
#line 186
    newv = newArr;
#line 187
    char* p = (char*)arr->data + offset;
#line 188
    char* newp = (char*)newArr->data;
#line 190
    newArr->refcount = 1;
#line 191
    newArr->size = newsize;
#line 192
    newArr->count = count;
#line 194
    #if true
#line 195
    memcpy(newp, p, sizeof(char) * count);
#line 196
    #else
#line 197
    for (int i = 0; i < count; i++) {
#line 198
        #line 171 "lib/sj-lib-common/array.sj"
newp[i] = p[i];
;
#line 199
    }
#line 200
    #endif
#line 200
    _return->_refCount = 1;
#line 202
    _return->v = newv;
#line 202
    sjf_array_char(_return);
}

void sjf_array_char_clone_heap(sjs_array_char* _parent, int32_t offset, int32_t count, int32_t newsize, sjs_array_char** _return) {
    void* newv;

#line 170 "lib/sj-lib-common/array.sj"
    newv = 0;
#line 172
    sjs_array* arr = (sjs_array*)_parent->v;
#line 173
    if (offset + count > arr->count) {
#line 174
        halt("grow: offset %d count %d out of bounds %d\n", offset, count, arr->count);
#line 175
    }
#line 177
    if (count > arr->count - offset) {
#line 178
        halt("grow: new count larger than old count %d:%d\n", count, arr->count - offset);
#line 179
    }
#line 181
    sjs_array* newArr = createarray(newsize * sizeof(char));
#line 182
    if (!newArr) {
#line 183
        halt("grow: out of memory\n");
#line 184
    }
#line 186
    newv = newArr;
#line 187
    char* p = (char*)arr->data + offset;
#line 188
    char* newp = (char*)newArr->data;
#line 190
    newArr->refcount = 1;
#line 191
    newArr->size = newsize;
#line 192
    newArr->count = count;
#line 194
    #if true
#line 195
    memcpy(newp, p, sizeof(char) * count);
#line 196
    #else
#line 197
    for (int i = 0; i < count; i++) {
#line 198
        #line 171 "lib/sj-lib-common/array.sj"
newp[i] = p[i];
;
#line 199
    }
#line 200
    #endif
#line 200
    (*_return) = (sjs_array_char*)malloc(sizeof(sjs_array_char));
#line 200
    (*_return)->_refCount = 1;
#line 202
    (*_return)->v = newv;
#line 202
    sjf_array_char_heap((*_return));
}

void sjf_array_char_copy(sjs_array_char* _this, sjs_array_char* _from) {
#line 26 "lib/sj-lib-common/array.sj"
    _this->v = _from->v;
#line 365
    sjs_array* arr = (sjs_array*)_this->v;
#line 366
    arr->refcount++;
}

void sjf_array_char_destroy(sjs_array_char* _this) {
#line 370 "lib/sj-lib-common/array.sj"
    sjs_array* arr = (sjs_array*)_this->v;
#line 371
    arr->refcount--;
#line 372
    if (arr->refcount == 0) {
#line 373
        #if !true && !false
#line 374
        char* p = (char*)arr->data;
#line 375
        for (int i = 0; i < arr->count; i++) {
#line 376
            ;
#line 377
        }
#line 378
        #endif
#line 379
        free(arr);
#line 380
    }
}

void sjf_array_char_getat(sjs_array_char* _parent, int32_t index, char* _return) {
#line 43 "lib/sj-lib-common/array.sj"
    sjs_array* arr = (sjs_array*)_parent->v;
#line 44
    if (index >= arr->count || index < 0) {
#line 45
        halt("getAt: out of bounds\n");
#line 46
    }
#line 47
    char* p = (char*)arr->data;
#line 48
    #line 42 "lib/sj-lib-common/array.sj"
(*_return) = p[index];
return;;       
}

void sjf_array_char_getcount(sjs_array_char* _parent, int32_t* _return) {
#line 31 "lib/sj-lib-common/array.sj"
    #line 30 "lib/sj-lib-common/array.sj"
(*_return) = ((sjs_array*)_parent->v)->count;
return;;
}

void sjf_array_char_getsize(sjs_array_char* _parent, int32_t* _return) {
#line 37 "lib/sj-lib-common/array.sj"
    #line 36 "lib/sj-lib-common/array.sj"
(*_return) = ((sjs_array*)_parent->v)->size;
return;;
}

void sjf_array_char_heap(sjs_array_char* _this) {
#line 356 "lib/sj-lib-common/array.sj"
    if (_this->v == 0) {
#line 357
        _this->v = &g_empty;
#line 358
    }
#line 359
    sjs_array* arr = (sjs_array*)_this->v;
#line 360
    arr->refcount++;
}

void sjf_array_char_initat(sjs_array_char* _parent, int32_t index, char item) {
#line 54 "lib/sj-lib-common/array.sj"
    sjs_array* arr = (sjs_array*)_parent->v;
#line 55
    if (index != arr->count) {
#line 56
        halt("initAt: can only initialize last element\n");     
#line 57
    }
#line 58
    if (index >= arr->size || index < 0) {
#line 59
        halt("initAt: out of bounds %d:%d\n", index, arr->size);
#line 60
    }
#line 62
    char* p = (char*)arr->data;
#line 63
    #line 52 "lib/sj-lib-common/array.sj"
p[index] = item;
;
#line 64
    arr->count = index + 1;
}

void sjf_class(sjs_class* _this) {
}

void sjf_class_as_sji_interface(sjs_class* _this, sji_interface* _return) {
    _return->_parent = (sjs_object*)_this;
    _return->_vtbl = &sjs_class_interface_vtbl;
}

void sjf_class_asinterface(sjs_class* _this, int typeId, sjs_interface* _return) {
    switch (typeId) {
        case sji_interface_typeId:  {
            sjf_class_as_sji_interface(_this, (sji_interface*)_return);
            break;
        }

        default: {
            _return->_parent = 0;
            break;
        }
    }
}

void sjf_class_bob(sjs_class* _parent, int32_t* _return) {
#line 10 "hash4.sj"
    (*_return) = _parent->x;
}

void sjf_class_copy(sjs_class* _this, sjs_class* _from) {
#line 8 "hash4.sj"
    _this->x = _from->x;
}

void sjf_class_destroy(sjs_class* _this) {
}

void sjf_class_getclasstype(sjs_object* _this, int* _return) {
    *_return = 32;
}

void sjf_class_hash(sjs_class* _parent, uint32_t* _return) {
    int32_t sjt_cast3;

    sjf_class_bob(_parent, &sjt_cast3);
#line 12 "hash4.sj"
    (*_return) = (uint32_t)sjt_cast3;
}

void sjf_class_heap(sjs_class* _this) {
}

void sjf_class_isequal(sjs_class* _parent, sji_interface b, bool* _return) {
    int32_t sjt_capture2;
    int32_t sjt_capture3;
    sji_interface sjt_parent4 = { 0 };

    sjf_class_bob(_parent, &sjt_capture2);
#line 13 "hash4.sj"
    sjt_parent4 = b;
#line 13
    sjt_parent4._vtbl->bob(sjt_parent4._parent, &sjt_capture3);
#line 13
    (*_return) = sjt_capture2 == sjt_capture3;
}

void sjf_debug_writeline(sjs_string* data) {
#line 10 "lib/sj-lib-common/debug.sj"
    debugout("%s\n", string_char(data));
}

void sjf_hash_heap_iface_interface_i32(sjs_hash_heap_iface_interface_i32* _this) {
#line 225 "lib/sj-lib-common/hash.sj"
    _this->_hash = kh_init(heap_iface_interface_i32_hash_type);
}

void sjf_hash_heap_iface_interface_i32__weakptrremovekey(sjs_hash_heap_iface_interface_i32* _parent, sji_interface key) {
#line 180 "lib/sj-lib-common/hash.sj"
    #if false
#line 181
    khash_t(heap_iface_interface_i32_hash_type)* p = (khash_t(heap_iface_interface_i32_hash_type)*)_parent->_hash;    
#line 182
    khiter_t k = kh_get(heap_iface_interface_i32_hash_type, p, key);
#line 183
    if (k != kh_end(p)) {
#line 184
        kh_del(heap_iface_interface_i32_hash_type, p, k);
#line 185
    }
#line 186
    #endif
}

void sjf_hash_heap_iface_interface_i32__weakptrremovevalue(sjs_hash_heap_iface_interface_i32* _parent, int32_t val) {
#line 192 "lib/sj-lib-common/hash.sj"
    #if false
#line 193
    khash_t(heap_iface_interface_i32_hash_type)* p = (khash_t(heap_iface_interface_i32_hash_type)*)_parent->_hash;
#line 194
    for (khiter_t k = kh_begin(p); k != kh_end(p); ++k) {
#line 195
        if (kh_exist(p, k)) {
#line 196
            int32_t t = kh_value(p, k);
#line 197
            if (t == val) {
#line 198
                kh_del(heap_iface_interface_i32_hash_type, p, k);
#line 199
            }
#line 200
        }
#line 201
    }
#line 202
    #endif
}

void sjf_hash_heap_iface_interface_i32_copy(sjs_hash_heap_iface_interface_i32* _this, sjs_hash_heap_iface_interface_i32* _from) {
#line 230 "lib/sj-lib-common/hash.sj"
    _this->_hash = _from->_hash;
#line 231
    khash_t(heap_iface_interface_i32_hash_type)* p = (khash_t(heap_iface_interface_i32_hash_type)*)_this->_hash;
#line 232
    p->refcount++;
}

void sjf_hash_heap_iface_interface_i32_destroy(sjs_hash_heap_iface_interface_i32* _this) {
#line 236 "lib/sj-lib-common/hash.sj"
    khash_t(heap_iface_interface_i32_hash_type)* p = (khash_t(heap_iface_interface_i32_hash_type)*)_this->_hash;
#line 237
    p->refcount--;
#line 238
    if (p->refcount == 0) {
#line 239
        for (khiter_t k = kh_begin(p); k != kh_end(p); ++k) {
#line 240
            if (kh_exist(p, k)) {
#line 242
                #if false
#line 243
                delete_cb cb = { p, (void(*)(void*, void*))sjf_hash_heap_iface_interface_i32__weakptrremovekey };
#line 244
                weakptr_cb_remove(kh_key(p, k)._parent, cb);
#line 245
                #else
#line 246
                if (kh_key(p, k)._parent != 0) {
    kh_key(p, k)._parent->_refCount--;
    if (kh_key(p, k)._parent->_refCount <= 0) {
        kh_key(p, k)._vtbl->destroy(kh_key(p, k)._parent);
        free(kh_key(p, k)._parent);
    }
}
;
#line 247
                #endif
#line 249
                #if false
#line 250
                delete_cb cb = { p, (void(*)(void*, void*))sjf_hash_heap_iface_interface_i32__weakptrremovevalue };
#line 251
                weakptr_cb_remove(kh_value(p, k), cb);
#line 252
                #else
#line 253
                ;
#line 254
                #endif
#line 255
            }
#line 256
        }
#line 257
        kh_destroy(heap_iface_interface_i32_hash_type, (khash_t(heap_iface_interface_i32_hash_type)*)_this->_hash);
#line 258
    }
}

void sjf_hash_heap_iface_interface_i32_each(sjs_hash_heap_iface_interface_i32* _parent, cb_heap_iface_interface_i32_void cb) {
#line 98 "lib/sj-lib-common/hash.sj"
    khash_t(heap_iface_interface_i32_hash_type)* p = (khash_t(heap_iface_interface_i32_hash_type)*)_parent->_hash;
#line 99
    for (khiter_t k = kh_begin(p); k != kh_end(p); ++k) {
#line 100
        if (kh_exist(p, k)) {
#line 101
            cb._cb(
#line 102
            cb._parent, 
#line 103
            #if false
#line 104
            &kh_key(p, k), 
#line 105
            #else
#line 106
            kh_key(p, k), 
#line 107
            #endif
#line 109
            #if false
#line 110
            &kh_value(p, k)
#line 111
            #else
#line 112
            kh_value(p, k)
#line 113
            #endif
#line 114
            );
#line 115
        }
#line 116
    }
}

void sjf_hash_heap_iface_interface_i32_getat(sjs_hash_heap_iface_interface_i32* _parent, sji_interface key, int32_option* _return) {
#line 23 "lib/sj-lib-common/hash.sj"
    khash_t(heap_iface_interface_i32_hash_type)* p = (khash_t(heap_iface_interface_i32_hash_type)*)_parent->_hash;
#line 25
    #if false
#line 26
    khiter_t k = kh_get(heap_iface_interface_i32_hash_type, p, *key);
#line 27
    #else
#line 28
    khiter_t k = kh_get(heap_iface_interface_i32_hash_type, p, key);
#line 29
    #endif
#line 31
    if (k == kh_end(p)) {
#line 32
        #line 22 "lib/sj-lib-common/hash.sj"
(*_return) = int32_empty;
return;
#line 33
    }
#line 34
    #line 22 "lib/sj-lib-common/hash.sj"
_return->isvalid = true;
#line 22
_return->value = kh_val(p, k);
return;;
}

void sjf_hash_heap_iface_interface_i32_heap(sjs_hash_heap_iface_interface_i32* _this) {
#line 225 "lib/sj-lib-common/hash.sj"
    _this->_hash = kh_init(heap_iface_interface_i32_hash_type);
}

void sjf_hash_heap_iface_interface_i32_setat(sjs_hash_heap_iface_interface_i32* _parent, sji_interface key, int32_t val) {
#line 40 "lib/sj-lib-common/hash.sj"
    khash_t(heap_iface_interface_i32_hash_type)* p = (khash_t(heap_iface_interface_i32_hash_type)*)_parent->_hash;
#line 42
    #if false
#line 43
    khiter_t k = kh_get(heap_iface_interface_i32_hash_type, p, *key);
#line 44
    #else
#line 45
    khiter_t k = kh_get(heap_iface_interface_i32_hash_type, p, key);
#line 46
    #endif
#line 48
    if (k != kh_end(p)) {            
#line 49
    ;
#line 50
}
#line 52
int ret;
#line 53
#if false
#line 54
k = kh_put(heap_iface_interface_i32_hash_type, p, *key, &ret);
#line 55
#else
#line 56
k = kh_put(heap_iface_interface_i32_hash_type, p, key, &ret);
#line 57
#endif
#line 59
if (!ret) kh_del(heap_iface_interface_i32_hash_type, p, k);
#line 61
#if false
#line 62
delete_cb cb = { _parent, (void(*)(void*, void*))sjf_hash_heap_iface_interface_i32__weakptrremovekey };
#line 63
weakptr_cb_add(key._parent, cb);
#line 64
#else
#line 65
sji_interface t;
#line 66
#line 38 "lib/sj-lib-common/hash.sj"
t = key;
if (t._parent != 0) {
    t._parent->_refCount++;
}
;
#line 67
#endif
#line 69
#if false
#line 70
delete_cb cb = { _parent, (void(*)(void*, void*))sjf_hash_heap_iface_interface_i32__weakptrremovevalue };
#line 71
weakptr_cb_add(val, cb);
#line 72
kh_val(p, k) = val;
#line 73
#else
#line 74
#line 38 "lib/sj-lib-common/hash.sj"
kh_val(p, k) = val;
;
#line 75
#endif
}

void sjf_hash_type_bool(sjs_hash_type_bool* _this) {
#line 225 "lib/sj-lib-common/hash.sj"
    _this->_hash = kh_init(type_bool_hash_type);
}

void sjf_hash_type_bool__weakptrremovekey(sjs_hash_type_bool* _parent, int32_t key) {
#line 180 "lib/sj-lib-common/hash.sj"
    #if false
#line 181
    khash_t(type_bool_hash_type)* p = (khash_t(type_bool_hash_type)*)_parent->_hash;    
#line 182
    khiter_t k = kh_get(type_bool_hash_type, p, key);
#line 183
    if (k != kh_end(p)) {
#line 184
        kh_del(type_bool_hash_type, p, k);
#line 185
    }
#line 186
    #endif
}

void sjf_hash_type_bool__weakptrremovevalue(sjs_hash_type_bool* _parent, bool val) {
#line 192 "lib/sj-lib-common/hash.sj"
    #if false
#line 193
    khash_t(type_bool_hash_type)* p = (khash_t(type_bool_hash_type)*)_parent->_hash;
#line 194
    for (khiter_t k = kh_begin(p); k != kh_end(p); ++k) {
#line 195
        if (kh_exist(p, k)) {
#line 196
            bool t = kh_value(p, k);
#line 197
            if (t == val) {
#line 198
                kh_del(type_bool_hash_type, p, k);
#line 199
            }
#line 200
        }
#line 201
    }
#line 202
    #endif
}

void sjf_hash_type_bool_copy(sjs_hash_type_bool* _this, sjs_hash_type_bool* _from) {
#line 230 "lib/sj-lib-common/hash.sj"
    _this->_hash = _from->_hash;
#line 231
    khash_t(type_bool_hash_type)* p = (khash_t(type_bool_hash_type)*)_this->_hash;
#line 232
    p->refcount++;
}

void sjf_hash_type_bool_destroy(sjs_hash_type_bool* _this) {
#line 236 "lib/sj-lib-common/hash.sj"
    khash_t(type_bool_hash_type)* p = (khash_t(type_bool_hash_type)*)_this->_hash;
#line 237
    p->refcount--;
#line 238
    if (p->refcount == 0) {
#line 239
        for (khiter_t k = kh_begin(p); k != kh_end(p); ++k) {
#line 240
            if (kh_exist(p, k)) {
#line 242
                #if false
#line 243
                delete_cb cb = { p, (void(*)(void*, void*))sjf_hash_type_bool__weakptrremovekey };
#line 244
                weakptr_cb_remove(kh_key(p, k), cb);
#line 245
                #else
#line 246
                ;
#line 247
                #endif
#line 249
                #if false
#line 250
                delete_cb cb = { p, (void(*)(void*, void*))sjf_hash_type_bool__weakptrremovevalue };
#line 251
                weakptr_cb_remove(kh_value(p, k), cb);
#line 252
                #else
#line 253
                ;
#line 254
                #endif
#line 255
            }
#line 256
        }
#line 257
        kh_destroy(type_bool_hash_type, (khash_t(type_bool_hash_type)*)_this->_hash);
#line 258
    }
}

void sjf_hash_type_bool_heap(sjs_hash_type_bool* _this) {
#line 225 "lib/sj-lib-common/hash.sj"
    _this->_hash = kh_init(type_bool_hash_type);
}

void sjf_i32_asstring(int32_t val, int32_t base, sjs_string* _return) {
    int32_t count;
    void* vresult;

#line 23 "lib/sj-lib-common/i32.sj"
    count = 0;
#line 24
    vresult = 0;
#line 26
    sjs_array* arr = createarray(256);
#line 27
    vresult = (void*)arr;
#line 28
    char *tmp = (char*)arr->data + 128;
#line 29
    char *tp = (char*)arr->data + 128;
#line 30
    int i;
#line 31
    unsigned v;
#line 33
    int sign = (base == 10 && val < 0);    
#line 34
    if (sign)
#line 35
    v = -val;
#line 36
    else
#line 37
    v = (unsigned)val;
#line 39
    while (v || tp == tmp)
#line 40
    {
#line 41
        i = v % base;
#line 42
        v /= base; // v/=base uses less CPU clocks than v=v/base does
#line 43
        if (i < 10)
#line 44
        *tp++ = i + '0';
#line 45
        else
#line 46
        *tp++ = i + 'a' - 10;
#line 47
    }
#line 49
    int len = tp - tmp;
#line 51
    char* sp = (char*)arr->data;
#line 52
    if (sign) 
#line 53
    {
#line 54
        *sp++ = '-';
#line 55
        len++;
#line 56
    }
#line 58
    while (tp > tmp)
#line 59
    *sp++ = *--tp;
#line 61
    arr->count = len;
#line 62
    count = len;
#line 62
    _return->_refCount = 1;
#line 13 "lib/sj-lib-common/string.sj"
    _return->offset = 0;
#line 64 "lib/sj-lib-common/i32.sj"
    _return->count = count;
#line 64
    _return->data._refCount = 1;
#line 64
    _return->data.v = vresult;
#line 64
    sjf_array_char(&_return->data);
#line 16 "lib/sj-lib-common/string.sj"
    _return->_isnullterminated = false;
#line 16
    sjf_string(_return);
}

void sjf_i32_asstring_heap(int32_t val, int32_t base, sjs_string** _return) {
    int32_t count;
    void* vresult;

#line 23 "lib/sj-lib-common/i32.sj"
    count = 0;
#line 24
    vresult = 0;
#line 26
    sjs_array* arr = createarray(256);
#line 27
    vresult = (void*)arr;
#line 28
    char *tmp = (char*)arr->data + 128;
#line 29
    char *tp = (char*)arr->data + 128;
#line 30
    int i;
#line 31
    unsigned v;
#line 33
    int sign = (base == 10 && val < 0);    
#line 34
    if (sign)
#line 35
    v = -val;
#line 36
    else
#line 37
    v = (unsigned)val;
#line 39
    while (v || tp == tmp)
#line 40
    {
#line 41
        i = v % base;
#line 42
        v /= base; // v/=base uses less CPU clocks than v=v/base does
#line 43
        if (i < 10)
#line 44
        *tp++ = i + '0';
#line 45
        else
#line 46
        *tp++ = i + 'a' - 10;
#line 47
    }
#line 49
    int len = tp - tmp;
#line 51
    char* sp = (char*)arr->data;
#line 52
    if (sign) 
#line 53
    {
#line 54
        *sp++ = '-';
#line 55
        len++;
#line 56
    }
#line 58
    while (tp > tmp)
#line 59
    *sp++ = *--tp;
#line 61
    arr->count = len;
#line 62
    count = len;
#line 62
    (*_return) = (sjs_string*)malloc(sizeof(sjs_string));
#line 62
    (*_return)->_refCount = 1;
#line 13 "lib/sj-lib-common/string.sj"
    (*_return)->offset = 0;
#line 64 "lib/sj-lib-common/i32.sj"
    (*_return)->count = count;
#line 64
    (*_return)->data._refCount = 1;
#line 64
    (*_return)->data.v = vresult;
#line 64
    sjf_array_char(&(*_return)->data);
#line 16 "lib/sj-lib-common/string.sj"
    (*_return)->_isnullterminated = false;
#line 16
    sjf_string_heap((*_return));
}

void sjf_log(sjs_log* _this) {
}

void sjf_log_copy(sjs_log* _this, sjs_log* _from) {
#line 13 "lib/sj-lib-common/log.sj"
    _this->minlevel = _from->minlevel;
#line 13
    sjs_hash_type_bool* copyoption2 = (_from->traceincludes._refCount != -1 ? &_from->traceincludes : 0);
    if (copyoption2 != 0) {
        _this->traceincludes._refCount = 1;
#line 13 "lib/sj-lib-common/log.sj"
        sjf_hash_type_bool_copy(&_this->traceincludes, copyoption2);
    } else {
        _this->traceincludes._refCount = -1;
    }

#line 13
    sjs_hash_type_bool* copyoption3 = (_from->debugincludes._refCount != -1 ? &_from->debugincludes : 0);
    if (copyoption3 != 0) {
        _this->debugincludes._refCount = 1;
#line 13 "lib/sj-lib-common/log.sj"
        sjf_hash_type_bool_copy(&_this->debugincludes, copyoption3);
    } else {
        _this->debugincludes._refCount = -1;
    }

#line 13
    sjs_hash_type_bool* copyoption4 = (_from->infoincludes._refCount != -1 ? &_from->infoincludes : 0);
    if (copyoption4 != 0) {
        _this->infoincludes._refCount = 1;
#line 13 "lib/sj-lib-common/log.sj"
        sjf_hash_type_bool_copy(&_this->infoincludes, copyoption4);
    } else {
        _this->infoincludes._refCount = -1;
    }

#line 13
    sjs_hash_type_bool* copyoption5 = (_from->warnincludes._refCount != -1 ? &_from->warnincludes : 0);
    if (copyoption5 != 0) {
        _this->warnincludes._refCount = 1;
#line 13 "lib/sj-lib-common/log.sj"
        sjf_hash_type_bool_copy(&_this->warnincludes, copyoption5);
    } else {
        _this->warnincludes._refCount = -1;
    }

#line 13
    sjs_hash_type_bool* copyoption6 = (_from->errorincludes._refCount != -1 ? &_from->errorincludes : 0);
    if (copyoption6 != 0) {
        _this->errorincludes._refCount = 1;
#line 13 "lib/sj-lib-common/log.sj"
        sjf_hash_type_bool_copy(&_this->errorincludes, copyoption6);
    } else {
        _this->errorincludes._refCount = -1;
    }

#line 13
    sjs_hash_type_bool* copyoption7 = (_from->fatalincludes._refCount != -1 ? &_from->fatalincludes : 0);
    if (copyoption7 != 0) {
        _this->fatalincludes._refCount = 1;
#line 13 "lib/sj-lib-common/log.sj"
        sjf_hash_type_bool_copy(&_this->fatalincludes, copyoption7);
    } else {
        _this->fatalincludes._refCount = -1;
    }
}

void sjf_log_destroy(sjs_log* _this) {
    if (_this->traceincludes._refCount == 1) { sjf_hash_type_bool_destroy(&_this->traceincludes); }
;
    if (_this->debugincludes._refCount == 1) { sjf_hash_type_bool_destroy(&_this->debugincludes); }
;
    if (_this->infoincludes._refCount == 1) { sjf_hash_type_bool_destroy(&_this->infoincludes); }
;
    if (_this->warnincludes._refCount == 1) { sjf_hash_type_bool_destroy(&_this->warnincludes); }
;
    if (_this->errorincludes._refCount == 1) { sjf_hash_type_bool_destroy(&_this->errorincludes); }
;
    if (_this->fatalincludes._refCount == 1) { sjf_hash_type_bool_destroy(&_this->fatalincludes); }
;
}

void sjf_log_heap(sjs_log* _this) {
}

void sjf_print(sji_interface k, int32_t v) {
    sjs_string sjt_call3 = { -1 };
    sjs_string sjt_call4 = { -1 };
    sjs_string sjt_call5 = { -1 };
    sjs_string sjt_call6 = { -1 };
    sjs_string sjt_call7 = { -1 };
    int32_t sjt_functionParam28;
    int32_t sjt_functionParam29;
    sjs_string* sjt_functionParam30 = 0;
    sjs_string* sjt_functionParam31 = 0;
    int32_t sjt_functionParam32;
    int32_t sjt_functionParam33;
    sjs_string* sjt_functionParam8 = 0;
    sjs_string* sjt_parent24 = 0;
    sjs_string* sjt_parent25 = 0;
    sji_interface sjt_parent26 = { 0 };

#line 23 "hash4.sj"
    sjt_parent26 = k;
#line 24
    sjt_parent26._vtbl->bob(sjt_parent26._parent, &sjt_functionParam28);
#line 22 "lib/sj-lib-common/i32.sj"
    sjt_functionParam29 = 10;
#line 22
    sjf_i32_asstring(sjt_functionParam28, sjt_functionParam29, &sjt_call5);
#line 24 "hash4.sj"
    sjt_parent25 = &sjt_call5;
#line 24
    sjt_call6._refCount = 1;
#line 24
    sjt_call6.offset = 0;
#line 24
    sjt_call6.count = 3;
#line 24
    sjt_call6.data._refCount = 1;
#line 24
    sjt_call6.data.v = &sjg_string1;
#line 24
    sjf_array_char(&sjt_call6.data);
#line 16 "lib/sj-lib-common/string.sj"
    sjt_call6._isnullterminated = false;
#line 16
    sjf_string(&sjt_call6);
#line 24 "hash4.sj"
    sjt_functionParam30 = &sjt_call6;
#line 24
    sjf_string_add(sjt_parent25, sjt_functionParam30, &sjt_call4);
#line 24
    sjt_parent24 = &sjt_call4;
#line 23
    sjt_functionParam32 = v;
#line 22 "lib/sj-lib-common/i32.sj"
    sjt_functionParam33 = 10;
#line 22
    sjf_i32_asstring(sjt_functionParam32, sjt_functionParam33, &sjt_call7);
#line 24 "hash4.sj"
    sjt_functionParam31 = &sjt_call7;
#line 24
    sjf_string_add(sjt_parent24, sjt_functionParam31, &sjt_call3);
#line 24
    sjt_functionParam8 = &sjt_call3;
#line 24
    sjf_debug_writeline(sjt_functionParam8);

    if (sjt_call3._refCount == 1) { sjf_string_destroy(&sjt_call3); }
;
    if (sjt_call4._refCount == 1) { sjf_string_destroy(&sjt_call4); }
;
    if (sjt_call5._refCount == 1) { sjf_string_destroy(&sjt_call5); }
;
    if (sjt_call6._refCount == 1) { sjf_string_destroy(&sjt_call6); }
;
    if (sjt_call7._refCount == 1) { sjf_string_destroy(&sjt_call7); }
;
}

void sjf_print_callback(void * _parent, sji_interface k, int32_t v) {
    sjf_print(k, v);
}

void sjf_string(sjs_string* _this) {
}

void sjf_string_add(sjs_string* _parent, sjs_string* item, sjs_string* _return) {
    sjs_array_char newdata = { -1 };

    if (item->count == 0) {
        _return->_refCount = 1;
#line 20 "lib/sj-lib-common/string.sj"
        sjf_string_copy(_return, _parent);
    } else {
        bool sjt_capture4;
        int32_t sjt_capture5;
        sjs_array_char* sjt_parent7 = 0;

#line 35 "lib/sj-lib-common/array.sj"
        sjt_parent7 = &_parent->data;
#line 35
        sjf_array_char_getsize(sjt_parent7, &sjt_capture5);
        if (((_parent->offset + _parent->count) + item->count) < sjt_capture5) {
            int32_t sjt_capture6;
            sjs_array_char* sjt_parent8 = 0;

#line 29 "lib/sj-lib-common/array.sj"
            sjt_parent8 = &_parent->data;
#line 29
            sjf_array_char_getcount(sjt_parent8, &sjt_capture6);
#line 24 "lib/sj-lib-common/string.sj"
            sjt_capture4 = ((_parent->offset + _parent->count) == sjt_capture6);
        } else {
#line 24 "lib/sj-lib-common/string.sj"
            sjt_capture4 = false;
        }

        if (sjt_capture4) {
            int32_t i;
            int32_t newcount;
            int32_t sjt_forEnd1;
            int32_t sjt_forStart1;

#line 25 "lib/sj-lib-common/string.sj"
            newcount = _parent->count;
#line 27
            sjt_forStart1 = 0;
#line 27
            sjt_forEnd1 = item->count;
#line 27
            i = sjt_forStart1;
            while (i < sjt_forEnd1) {
                char sjt_functionParam10;
                int32_t sjt_functionParam12;
                int32_t sjt_functionParam9;
                sjs_string* sjt_parent11 = 0;
                sjs_array_char* sjt_parent9 = 0;

#line 52 "lib/sj-lib-common/array.sj"
                sjt_parent9 = &_parent->data;
#line 28 "lib/sj-lib-common/string.sj"
                sjt_functionParam9 = newcount;
#line 18
                sjt_parent11 = item;
#line 27
                sjt_functionParam12 = i;
#line 27
                sjf_string_getat(sjt_parent11, sjt_functionParam12, &sjt_functionParam10);
#line 27
                sjf_array_char_initat(sjt_parent9, sjt_functionParam9, sjt_functionParam10);
#line 29
                newcount = newcount + 1;
#line 27
                i++;
            }

#line 27
            _return->_refCount = 1;
#line 32
            _return->offset = _parent->offset;
#line 32
            _return->count = newcount;
#line 32
            _return->data._refCount = 1;
#line 32
            sjf_array_char_copy(&_return->data, &_parent->data);
#line 16
            _return->_isnullterminated = false;
#line 16
            sjf_string(_return);
        } else {
            int32_t i;
            int32_t newcount;
            int32_t sjt_forEnd2;
            int32_t sjt_forStart2;
            int32_t sjt_functionParam13;
            int32_t sjt_functionParam14;
            int32_t sjt_functionParam15;
            sjs_array_char* sjt_parent12 = 0;
            sjs_array_char* sjt_parent13 = 0;

#line 169 "lib/sj-lib-common/array.sj"
            sjt_parent12 = &_parent->data;
#line 34 "lib/sj-lib-common/string.sj"
            sjt_functionParam13 = _parent->offset;
#line 34
            sjt_functionParam14 = _parent->count;
#line 34
            sjt_functionParam15 = ((((_parent->count + item->count) - 1) / 256) + 1) * 256;
#line 34
            sjf_array_char_clone(sjt_parent12, sjt_functionParam13, sjt_functionParam14, sjt_functionParam15, &newdata);
#line 29 "lib/sj-lib-common/array.sj"
            sjt_parent13 = &newdata;
#line 29
            sjf_array_char_getcount(sjt_parent13, &newcount);
#line 37 "lib/sj-lib-common/string.sj"
            sjt_forStart2 = 0;
#line 37
            sjt_forEnd2 = item->count;
#line 37
            i = sjt_forStart2;
            while (i < sjt_forEnd2) {
                int32_t sjt_functionParam16;
                char sjt_functionParam17;
                int32_t sjt_functionParam18;
                sjs_array_char* sjt_parent14 = 0;
                sjs_string* sjt_parent15 = 0;

#line 52 "lib/sj-lib-common/array.sj"
                sjt_parent14 = &newdata;
#line 38 "lib/sj-lib-common/string.sj"
                sjt_functionParam16 = newcount;
#line 18
                sjt_parent15 = item;
#line 37
                sjt_functionParam18 = i;
#line 37
                sjf_string_getat(sjt_parent15, sjt_functionParam18, &sjt_functionParam17);
#line 37
                sjf_array_char_initat(sjt_parent14, sjt_functionParam16, sjt_functionParam17);
#line 39
                newcount = newcount + 1;
#line 37
                i++;
            }

#line 37
            _return->_refCount = 1;
#line 42
            _return->offset = 0;
#line 42
            _return->count = newcount;
#line 42
            _return->data._refCount = 1;
#line 42
            sjf_array_char_copy(&_return->data, &newdata);
#line 16
            _return->_isnullterminated = false;
#line 16
            sjf_string(_return);
        }
    }

    if (newdata._refCount == 1) { sjf_array_char_destroy(&newdata); }
;
}

void sjf_string_add_heap(sjs_string* _parent, sjs_string* item, sjs_string** _return) {
    sjs_array_char newdata = { -1 };

    if (item->count == 0) {
        (*_return) = (sjs_string*)malloc(sizeof(sjs_string));
        (*_return)->_refCount = 1;
#line 20 "lib/sj-lib-common/string.sj"
        sjf_string_copy((*_return), _parent);
    } else {
        bool sjt_capture7;
        int32_t sjt_capture8;
        sjs_array_char* sjt_parent16 = 0;

#line 35 "lib/sj-lib-common/array.sj"
        sjt_parent16 = &_parent->data;
#line 35
        sjf_array_char_getsize(sjt_parent16, &sjt_capture8);
        if (((_parent->offset + _parent->count) + item->count) < sjt_capture8) {
            int32_t sjt_capture9;
            sjs_array_char* sjt_parent17 = 0;

#line 29 "lib/sj-lib-common/array.sj"
            sjt_parent17 = &_parent->data;
#line 29
            sjf_array_char_getcount(sjt_parent17, &sjt_capture9);
#line 24 "lib/sj-lib-common/string.sj"
            sjt_capture7 = ((_parent->offset + _parent->count) == sjt_capture9);
        } else {
#line 24 "lib/sj-lib-common/string.sj"
            sjt_capture7 = false;
        }

        if (sjt_capture7) {
            int32_t i;
            int32_t newcount;
            int32_t sjt_forEnd3;
            int32_t sjt_forStart3;

#line 25 "lib/sj-lib-common/string.sj"
            newcount = _parent->count;
#line 27
            sjt_forStart3 = 0;
#line 27
            sjt_forEnd3 = item->count;
#line 27
            i = sjt_forStart3;
            while (i < sjt_forEnd3) {
                int32_t sjt_functionParam19;
                char sjt_functionParam20;
                int32_t sjt_functionParam21;
                sjs_array_char* sjt_parent18 = 0;
                sjs_string* sjt_parent19 = 0;

#line 52 "lib/sj-lib-common/array.sj"
                sjt_parent18 = &_parent->data;
#line 28 "lib/sj-lib-common/string.sj"
                sjt_functionParam19 = newcount;
#line 18
                sjt_parent19 = item;
#line 27
                sjt_functionParam21 = i;
#line 27
                sjf_string_getat(sjt_parent19, sjt_functionParam21, &sjt_functionParam20);
#line 27
                sjf_array_char_initat(sjt_parent18, sjt_functionParam19, sjt_functionParam20);
#line 29
                newcount = newcount + 1;
#line 27
                i++;
            }

#line 27
            (*_return) = (sjs_string*)malloc(sizeof(sjs_string));
#line 27
            (*_return)->_refCount = 1;
#line 32
            (*_return)->offset = _parent->offset;
#line 32
            (*_return)->count = newcount;
#line 32
            (*_return)->data._refCount = 1;
#line 32
            sjf_array_char_copy(&(*_return)->data, &_parent->data);
#line 16
            (*_return)->_isnullterminated = false;
#line 16
            sjf_string_heap((*_return));
        } else {
            int32_t i;
            int32_t newcount;
            int32_t sjt_forEnd4;
            int32_t sjt_forStart4;
            int32_t sjt_functionParam22;
            int32_t sjt_functionParam23;
            int32_t sjt_functionParam24;
            sjs_array_char* sjt_parent20 = 0;
            sjs_array_char* sjt_parent21 = 0;

#line 169 "lib/sj-lib-common/array.sj"
            sjt_parent20 = &_parent->data;
#line 34 "lib/sj-lib-common/string.sj"
            sjt_functionParam22 = _parent->offset;
#line 34
            sjt_functionParam23 = _parent->count;
#line 34
            sjt_functionParam24 = ((((_parent->count + item->count) - 1) / 256) + 1) * 256;
#line 34
            sjf_array_char_clone(sjt_parent20, sjt_functionParam22, sjt_functionParam23, sjt_functionParam24, &newdata);
#line 29 "lib/sj-lib-common/array.sj"
            sjt_parent21 = &newdata;
#line 29
            sjf_array_char_getcount(sjt_parent21, &newcount);
#line 37 "lib/sj-lib-common/string.sj"
            sjt_forStart4 = 0;
#line 37
            sjt_forEnd4 = item->count;
#line 37
            i = sjt_forStart4;
            while (i < sjt_forEnd4) {
                int32_t sjt_functionParam25;
                char sjt_functionParam26;
                int32_t sjt_functionParam27;
                sjs_array_char* sjt_parent22 = 0;
                sjs_string* sjt_parent23 = 0;

#line 52 "lib/sj-lib-common/array.sj"
                sjt_parent22 = &newdata;
#line 38 "lib/sj-lib-common/string.sj"
                sjt_functionParam25 = newcount;
#line 18
                sjt_parent23 = item;
#line 37
                sjt_functionParam27 = i;
#line 37
                sjf_string_getat(sjt_parent23, sjt_functionParam27, &sjt_functionParam26);
#line 37
                sjf_array_char_initat(sjt_parent22, sjt_functionParam25, sjt_functionParam26);
#line 39
                newcount = newcount + 1;
#line 37
                i++;
            }

#line 37
            (*_return) = (sjs_string*)malloc(sizeof(sjs_string));
#line 37
            (*_return)->_refCount = 1;
#line 42
            (*_return)->offset = 0;
#line 42
            (*_return)->count = newcount;
#line 42
            (*_return)->data._refCount = 1;
#line 42
            sjf_array_char_copy(&(*_return)->data, &newdata);
#line 16
            (*_return)->_isnullterminated = false;
#line 16
            sjf_string_heap((*_return));
        }
    }

    if (newdata._refCount == 1) { sjf_array_char_destroy(&newdata); }
;
}

void sjf_string_copy(sjs_string* _this, sjs_string* _from) {
#line 12 "lib/sj-lib-common/string.sj"
    _this->offset = _from->offset;
#line 12
    _this->count = _from->count;
#line 12
    _this->data._refCount = 1;
#line 12
    sjf_array_char_copy(&_this->data, &_from->data);
#line 12
    _this->_isnullterminated = _from->_isnullterminated;
}

void sjf_string_destroy(sjs_string* _this) {
    if (_this->data._refCount == 1) { sjf_array_char_destroy(&_this->data); }
;
}

void sjf_string_getat(sjs_string* _parent, int32_t index, char* _return) {
    int32_t sjt_functionParam11;
    sjs_array_char* sjt_parent10 = 0;

#line 41 "lib/sj-lib-common/array.sj"
    sjt_parent10 = &_parent->data;
#line 64 "lib/sj-lib-common/string.sj"
    sjt_functionParam11 = _parent->offset + index;
#line 64
    sjf_array_char_getat(sjt_parent10, sjt_functionParam11, _return);
}

void sjf_string_heap(sjs_string* _this) {
}

void sjf_string_nullterminate(sjs_string* _parent) {
    bool result2;
    sjs_array_char sjt_funcold1 = { -1 };

#line 133 "lib/sj-lib-common/string.sj"
    result2 = !_parent->_isnullterminated;
    if (result2) {
        int32_t sjt_capture1;
        sjs_array_char* sjt_parent1 = 0;

#line 35 "lib/sj-lib-common/array.sj"
        sjt_parent1 = &_parent->data;
#line 35
        sjf_array_char_getsize(sjt_parent1, &sjt_capture1);
        if ((_parent->count + 1) > sjt_capture1) {
            int32_t sjt_functionParam1;
            int32_t sjt_functionParam2;
            int32_t sjt_functionParam3;
            sjs_array_char* sjt_parent2 = 0;

            sjt_funcold1._refCount = 1;
#line 169 "lib/sj-lib-common/array.sj"
            sjf_array_char_copy(&sjt_funcold1, &_parent->data);
#line 169
            sjt_parent2 = &_parent->data;
#line 135 "lib/sj-lib-common/string.sj"
            sjt_functionParam1 = _parent->offset;
#line 135
            sjt_functionParam2 = _parent->count;
#line 135
            sjt_functionParam3 = _parent->count + 1;
#line 135
            sjf_array_char_clone(sjt_parent2, sjt_functionParam1, sjt_functionParam2, sjt_functionParam3, &sjt_funcold1);
#line 135
            if (_parent->data._refCount == 1) { sjf_array_char_destroy(&_parent->data); }
;
#line 169 "lib/sj-lib-common/array.sj"
            sjf_array_char_copy(&_parent->data, &sjt_funcold1);
#line 136 "lib/sj-lib-common/string.sj"
            _parent->offset = 0;
        }

#line 139 "lib/sj-lib-common/string.sj"
        ((sjs_array*)_parent->data.v)->data[_parent->count] = 0;
#line 141
        _parent->_isnullterminated = true;
    }

    if (sjt_funcold1._refCount == 1) { sjf_array_char_destroy(&sjt_funcold1); }
;
}

void sjf_type_hash(int32_t val, uint32_t* _return) {
    int32_t sjt_cast1;

#line 5 "lib/sj-lib-common/type.sj"
    sjt_cast1 = val;
#line 6
    (*_return) = (uint32_t)sjt_cast1;
}

void sjf_type_isequal(int32_t l, int32_t r, bool* _return) {
#line 10 "lib/sj-lib-common/type.sj"
    (*_return) = l == r;
}

void sji_interface_hash(sji_interface _parent, uint32_t* _return) {
    _parent._vtbl->hash(_parent._parent, _return);
}

void sji_interface_isequal(sji_interface _parent, sji_interface b, bool* _return) {
    _parent._vtbl->isequal(_parent._parent, b, _return);
}

int main(int argc, char** argv) {
    sjs_class_interface_vtbl.destroy = (void(*)(void*))sjf_class_destroy;
    sjs_class_interface_vtbl.asinterface = (void(*)(sjs_object*,int,sjs_interface*))sjf_class_asinterface;
    sjs_class_interface_vtbl.getclasstype = (void(*)(sjs_object*,int*))sjf_class_getclasstype;
    sjs_class_interface_vtbl.bob = (void(*)(sjs_object*, int32_t*))sjf_class_bob;
    sjs_class_interface_vtbl.hash = (void(*)(sjs_object*, uint32_t*))sjf_class_hash;
    sjs_class_interface_vtbl.isequal = (void(*)(sjs_object*,sji_interface, bool*))sjf_class_isequal;
#line 1 "lib/sj-lib-common/log.sj"
    g_loglevel_trace = 0;
#line 1
    g_loglevel_debug = 1;
#line 1
    g_loglevel_info = 2;
#line 1
    g_loglevel_warn = 3;
#line 1
    g_loglevel_error = 4;
#line 1
    g_loglevel_fatal = 5;
#line 1 "lib/sj-lib-common/f32.sj"
    g_f32_pi = 3.14159265358979323846f;
#line 1 "lib/sj-lib-common/i32.sj"
    g_u32_maxvalue = (uint32_t)4294967295u;
#line 3
    result1 = -1;
#line 3
    g_i32_maxvalue = result1 - 2147483647;
#line 4
    g_i32_minvalue = 2147483647;
#line 10 "lib/sj-lib-common/log.sj"
    g_log_includeall._refCount = -1;
#line 10
    sjt_value1._refCount = 1;
#line 10
    sjf_hash_type_bool(&sjt_value1);
#line 11
    sjs_hash_type_bool* copyoption1 = &sjt_value1;
    if (copyoption1 != 0) {
        g_log_excludeall._refCount = 1;
#line 11 "lib/sj-lib-common/log.sj"
        sjf_hash_type_bool_copy(&g_log_excludeall, copyoption1);
    } else {
        g_log_excludeall._refCount = -1;
    }

#line 11
    g_log._refCount = 1;
#line 13
    g_log.minlevel = g_loglevel_warn;
#line 13
    sjs_hash_type_bool* copyoption8 = (g_log_includeall._refCount != -1 ? &g_log_includeall : 0);
    if (copyoption8 != 0) {
        g_log.traceincludes._refCount = 1;
#line 13 "lib/sj-lib-common/log.sj"
        sjf_hash_type_bool_copy(&g_log.traceincludes, copyoption8);
    } else {
        g_log.traceincludes._refCount = -1;
    }

#line 13
    sjs_hash_type_bool* copyoption9 = (g_log_includeall._refCount != -1 ? &g_log_includeall : 0);
    if (copyoption9 != 0) {
        g_log.debugincludes._refCount = 1;
#line 13 "lib/sj-lib-common/log.sj"
        sjf_hash_type_bool_copy(&g_log.debugincludes, copyoption9);
    } else {
        g_log.debugincludes._refCount = -1;
    }

#line 13
    sjs_hash_type_bool* copyoption10 = (g_log_includeall._refCount != -1 ? &g_log_includeall : 0);
    if (copyoption10 != 0) {
        g_log.infoincludes._refCount = 1;
#line 13 "lib/sj-lib-common/log.sj"
        sjf_hash_type_bool_copy(&g_log.infoincludes, copyoption10);
    } else {
        g_log.infoincludes._refCount = -1;
    }

#line 13
    sjs_hash_type_bool* copyoption11 = (g_log_includeall._refCount != -1 ? &g_log_includeall : 0);
    if (copyoption11 != 0) {
        g_log.warnincludes._refCount = 1;
#line 13 "lib/sj-lib-common/log.sj"
        sjf_hash_type_bool_copy(&g_log.warnincludes, copyoption11);
    } else {
        g_log.warnincludes._refCount = -1;
    }

#line 13
    sjs_hash_type_bool* copyoption12 = (g_log_includeall._refCount != -1 ? &g_log_includeall : 0);
    if (copyoption12 != 0) {
        g_log.errorincludes._refCount = 1;
#line 13 "lib/sj-lib-common/log.sj"
        sjf_hash_type_bool_copy(&g_log.errorincludes, copyoption12);
    } else {
        g_log.errorincludes._refCount = -1;
    }

#line 13
    sjs_hash_type_bool* copyoption13 = (g_log_includeall._refCount != -1 ? &g_log_includeall : 0);
    if (copyoption13 != 0) {
        g_log.fatalincludes._refCount = 1;
#line 13 "lib/sj-lib-common/log.sj"
        sjf_hash_type_bool_copy(&g_log.fatalincludes, copyoption13);
    } else {
        g_log.fatalincludes._refCount = -1;
    }

#line 13
    sjf_log(&g_log);
#line 2 "lib/sj-lib-common/weakptr.sj"
    ptr_init();
#line 3
    weakptr_init();
#line 7 "lib/sj-lib-common/clock.sj"
    g_clocks_per_sec = 0;
#line 9
    g_clocks_per_sec = CLOCKS_PER_SEC;
#line 9
    g_a._refCount = 1;
#line 9
    sjf_hash_heap_iface_interface_i32(&g_a);
#line 38 "lib/sj-lib-common/hash.sj"
    sjt_parent3 = &g_a;
#line 38
    sjt_call1 = (sjs_class*)malloc(sizeof(sjs_class));
#line 38
    sjt_call1->_refCount = 1;
#line 17 "hash4.sj"
    sjt_call1->x = 32;
#line 17
    sjf_class_heap(sjt_call1);
#line 17
    sjt_cast2 = sjt_call1;
#line 2
    sjf_class_as_sji_interface(sjt_cast2, &sjt_functionParam4);
    if (sjt_functionParam4._parent != 0) {
        sjt_functionParam4._parent->_refCount++;
    }

#line 17
    sjt_functionParam5 = 1;
#line 17
    sjf_hash_heap_iface_interface_i32_setat(sjt_parent3, sjt_functionParam4, sjt_functionParam5);
#line 21 "lib/sj-lib-common/hash.sj"
    sjt_parent5 = &g_a;
#line 21
    sjt_call2 = (sjs_class*)malloc(sizeof(sjs_class));
#line 21
    sjt_call2->_refCount = 1;
#line 18 "hash4.sj"
    sjt_call2->x = 1;
#line 18
    sjf_class_heap(sjt_call2);
#line 18
    sjt_cast4 = sjt_call2;
#line 2
    sjf_class_as_sji_interface(sjt_cast4, &sjt_functionParam6);
    if (sjt_functionParam6._parent != 0) {
        sjt_functionParam6._parent->_refCount++;
    }

#line 2
    sjf_hash_heap_iface_interface_i32_getat(sjt_parent5, sjt_functionParam6, &g_b);
#line 96 "lib/sj-lib-common/hash.sj"
    sjt_parent6 = &g_a;
#line 20 "hash4.sj"
    sjt_functionParam7._parent = (sjs_object*)1;
#line 20
    sjt_functionParam7._cb = (void(*)(sjs_object*,sji_interface,int32_t))sjf_print_callback;
#line 20
    sjf_hash_heap_iface_interface_i32_each(sjt_parent6, sjt_functionParam7);
    if (g_b.isvalid) {
        int32_option sjt_getValue1;

#line 21 "hash4.sj"
        sjt_getValue1 = g_b;
#line 21
        sjt_functionParam35 = sjt_getValue1.value;
    } else {
        int32_t result3;

#line 21 "hash4.sj"
        result3 = -1;
#line 21
        sjt_functionParam35 = result3;
    }

#line 22 "lib/sj-lib-common/i32.sj"
    sjt_functionParam36 = 10;
#line 22
    sjf_i32_asstring(sjt_functionParam35, sjt_functionParam36, &sjt_call8);
#line 21 "hash4.sj"
    sjt_functionParam34 = &sjt_call8;
#line 21
    sjf_debug_writeline(sjt_functionParam34);
    main_destroy();
    return 0;
}

void main_destroy() {

    sjt_call1->_refCount--;
    if (sjt_call1->_refCount <= 0) {
        weakptr_release(sjt_call1);
        sjf_class_destroy(sjt_call1);
        free(sjt_call1);
    }
    sjt_call2->_refCount--;
    if (sjt_call2->_refCount <= 0) {
        weakptr_release(sjt_call2);
        sjf_class_destroy(sjt_call2);
        free(sjt_call2);
    }
    if (sjt_functionParam4._parent != 0) {
        sjt_functionParam4._parent->_refCount--;
        if (sjt_functionParam4._parent->_refCount <= 0) {
            sjt_functionParam4._vtbl->destroy(sjt_functionParam4._parent);
            free(sjt_functionParam4._parent);
        }
    }
    if (sjt_functionParam6._parent != 0) {
        sjt_functionParam6._parent->_refCount--;
        if (sjt_functionParam6._parent->_refCount <= 0) {
            sjt_functionParam6._vtbl->destroy(sjt_functionParam6._parent);
            free(sjt_functionParam6._parent);
        }
    }
    if (g_a._refCount == 1) { sjf_hash_heap_iface_interface_i32_destroy(&g_a); }
;
    if (g_log._refCount == 1) { sjf_log_destroy(&g_log); }
;
    if (g_log_excludeall._refCount == 1) { sjf_hash_type_bool_destroy(&g_log_excludeall); }
;
    if (g_log_includeall._refCount == 1) { sjf_hash_type_bool_destroy(&g_log_includeall); }
;
    if (sjt_call8._refCount == 1) { sjf_string_destroy(&sjt_call8); }
;
    if (sjt_value1._refCount == 1) { sjf_hash_type_bool_destroy(&sjt_value1); }
;
}
