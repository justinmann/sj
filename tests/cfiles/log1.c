#include <lib/sj-lib-common/common.h>

struct {
    int refcount;
    int size;
    int count;
    char data[6];
} sjg_string1 = { 1, 6, 5, "trace"};
struct {
    int refcount;
    int size;
    int count;
    char data[5];
} sjg_string10 = { 1, 5, 4, "init"};
struct {
    int refcount;
    int size;
    int count;
    char data[10];
} sjg_string11 = { 1, 10, 9, "oh my god"};
struct {
    int refcount;
    int size;
    int count;
    char data[9];
} sjg_string12 = { 1, 9, 8, "doThing1"};
struct {
    int refcount;
    int size;
    int count;
    char data[5];
} sjg_string13 = { 1, 5, 4, "bool"};
struct {
    int refcount;
    int size;
    int count;
    char data[15];
} sjg_string14 = { 1, 15, 14, "()stack string"};
struct {
    int refcount;
    int size;
    int count;
    char data[5];
} sjg_string15 = { 1, 5, 4, "char"};
struct {
    int refcount;
    int size;
    int count;
    char data[4];
} sjg_string16 = { 1, 4, 3, "f32"};
struct {
    int refcount;
    int size;
    int count;
    char data[4];
} sjg_string17 = { 1, 4, 3, "f64"};
struct {
    int refcount;
    int size;
    int count;
    char data[4];
} sjg_string18 = { 1, 4, 3, "i32"};
struct {
    int refcount;
    int size;
    int count;
    char data[4];
} sjg_string19 = { 1, 4, 3, "i64"};
struct {
    int refcount;
    int size;
    int count;
    char data[6];
} sjg_string2 = { 1, 6, 5, "debug"};
struct {
    int refcount;
    int size;
    int count;
    char data[9];
} sjg_string20 = { 1, 9, 8, "loglevel"};
struct {
    int refcount;
    int size;
    int count;
    char data[4];
} sjg_string21 = { 1, 4, 3, "ptr"};
struct {
    int refcount;
    int size;
    int count;
    char data[11];
} sjg_string22 = { 1, 11, 10, "array!char"};
struct {
    int refcount;
    int size;
    int count;
    char data[6];
} sjg_string23 = { 1, 6, 5, "clone"};
struct {
    int refcount;
    int size;
    int count;
    char data[6];
} sjg_string24 = { 1, 6, 5, "getat"};
struct {
    int refcount;
    int size;
    int count;
    char data[9];
} sjg_string25 = { 1, 9, 8, "getcount"};
struct {
    int refcount;
    int size;
    int count;
    char data[14];
} sjg_string26 = { 1, 14, 13, "gettotalcount"};
struct {
    int refcount;
    int size;
    int count;
    char data[7];
} sjg_string27 = { 1, 7, 6, "initat"};
struct {
    int refcount;
    int size;
    int count;
    char data[17];
} sjg_string28 = { 1, 17, 16, "char_touppercase"};
struct {
    int refcount;
    int size;
    int count;
    char data[6];
} sjg_string29 = { 1, 6, 5, "class"};
struct {
    int refcount;
    int size;
    int count;
    char data[5];
} sjg_string3 = { 1, 5, 4, "info"};
struct {
    int refcount;
    int size;
    int count;
    char data[9];
} sjg_string30 = { 1, 9, 8, "dothing1"};
struct {
    int refcount;
    int size;
    int count;
    char data[10];
} sjg_string31 = { 1, 10, 9, "writeline"};
struct {
    int refcount;
    int size;
    int count;
    char data[7];
} sjg_string32 = { 1, 7, 6, "global"};
struct {
    int refcount;
    int size;
    int count;
    char data[18];
} sjg_string33 = { 1, 18, 17, "hash![type, bool]"};
struct {
    int refcount;
    int size;
    int count;
    char data[18];
} sjg_string34 = { 1, 18, 17, "_weakptrremovekey"};
struct {
    int refcount;
    int size;
    int count;
    char data[20];
} sjg_string35 = { 1, 20, 19, "_weakptrremovevalue"};
struct {
    int refcount;
    int size;
    int count;
    char data[8];
} sjg_string36 = { 1, 8, 7, "lambda2"};
struct {
    int refcount;
    int size;
    int count;
    char data[7];
} sjg_string37 = { 1, 7, 6, "invoke"};
struct {
    int refcount;
    int size;
    int count;
    char data[8];
} sjg_string38 = { 1, 8, 7, "lambda3"};
struct {
    int refcount;
    int size;
    int count;
    char data[8];
} sjg_string39 = { 1, 8, 7, "lambda4"};
struct {
    int refcount;
    int size;
    int count;
    char data[5];
} sjg_string4 = { 1, 5, 4, "warn"};
struct {
    int refcount;
    int size;
    int count;
    char data[4];
} sjg_string40 = { 1, 4, 3, "log"};
struct {
    int refcount;
    int size;
    int count;
    char data[7];
} sjg_string41 = { 1, 7, 6, "_write"};
struct {
    int refcount;
    int size;
    int count;
    char data[18];
} sjg_string42 = { 1, 18, 17, "loglevel_asstring"};
struct {
    int refcount;
    int size;
    int count;
    char data[7];
} sjg_string43 = { 1, 7, 6, "string"};
struct {
    int refcount;
    int size;
    int count;
    char data[4];
} sjg_string44 = { 1, 4, 3, "add"};
struct {
    int refcount;
    int size;
    int count;
    char data[14];
} sjg_string45 = { 1, 14, 13, "nullterminate"};
struct {
    int refcount;
    int size;
    int count;
    char data[12];
} sjg_string46 = { 1, 12, 11, "touppercase"};
struct {
    int refcount;
    int size;
    int count;
    char data[14];
} sjg_string47 = { 1, 14, 13, "type_asstring"};
struct {
    int refcount;
    int size;
    int count;
    char data[10];
} sjg_string48 = { 1, 10, 9, "type_hash"};
struct {
    int refcount;
    int size;
    int count;
    char data[13];
} sjg_string49 = { 1, 13, 12, "type_isequal"};
struct {
    int refcount;
    int size;
    int count;
    char data[6];
} sjg_string5 = { 1, 6, 5, "error"};
struct {
    int refcount;
    int size;
    int count;
    char data[5];
} sjg_string50 = { 1, 5, 4, "type"};
struct {
    int refcount;
    int size;
    int count;
    char data[4];
} sjg_string51 = { 1, 4, 3, "u32"};
struct {
    int refcount;
    int size;
    int count;
    char data[4];
} sjg_string52 = { 1, 4, 3, "u64"};
struct {
    int refcount;
    int size;
    int count;
    char data[5];
} sjg_string53 = { 1, 5, 4, "void"};
struct {
    int refcount;
    int size;
    int count;
    char data[6];
} sjg_string6 = { 1, 6, 5, "fatal"};
struct {
    int refcount;
    int size;
    int count;
    char data[1];
} sjg_string7 = { 1, 1, 0, ""};
struct {
    int refcount;
    int size;
    int count;
    char data[3];
} sjg_string8 = { 1, 3, 2, " ["};
struct {
    int refcount;
    int size;
    int count;
    char data[3];
} sjg_string9 = { 1, 3, 2, "] "};

struct {
    int refcount;
    int size;
    int count;
    char data[0];
} g_empty = { 1, 0, 0 };
#define sjs_hash_type_bool_typeId 15
#define sjs_log_typeId 20
#define sjs_array_char_typeId 23
#define sjs_string_typeId 21
#define sjs_class_typeId 27
#define cb_string_heap_string_typeId 30
#define cb_string_heap_string_heap_typeId 30
#define sjs_lambda3_typeId 41
#define sjs_lambda4_typeId 44
#define sjs_lambda2_typeId 47

typedef struct td_sjs_hash_type_bool sjs_hash_type_bool;
typedef struct td_sjs_log sjs_log;
typedef struct td_sjs_array_char sjs_array_char;
typedef struct td_sjs_string sjs_string;
typedef struct td_sjs_class sjs_class;
typedef struct td_cb_string_heap_string cb_string_heap_string;
typedef struct td_cb_string_heap_string_heap cb_string_heap_string_heap;
typedef struct td_sjs_lambda3 sjs_lambda3;
typedef struct td_sjs_lambda4 sjs_lambda4;
typedef struct td_sjs_lambda2 sjs_lambda2;

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

struct td_sjs_class {
    int _refCount;
};

struct td_cb_string_heap_string {
    sjs_object* _parent;
    void (*_cb)(sjs_object* _parent, sjs_string* _return);
    void (*_cb_heap)(sjs_object* _parent, sjs_string** _return);
};

struct td_cb_string_heap_string_heap {
    cb_string_heap_string inner;
    void (*_destroy)(sjs_object*);
};

struct td_sjs_lambda3 {
    int _refCount;
};

struct td_sjs_lambda4 {
    int _refCount;
};

struct td_sjs_lambda2 {
    int _refCount;
};

#ifndef type_bool_hash_typedef
#define type_bool_hash_typedef
KHASH_INIT_TYPEDEF(type_bool_hash_type, int32_t, bool)
#endif
#ifndef type_bool_hash_typedef
#define type_bool_hash_typedef
KHASH_INIT_TYPEDEF(type_bool_hash_type, int32_t, bool)
#endif
char* string_char(sjs_string* str);
int32_t g_loglevel_debug;
int32_t g_loglevel_error;
int32_t g_loglevel_fatal;
int32_t g_loglevel_info;
int32_t g_loglevel_trace;
int32_t g_loglevel_warn;

sjs_class g_c = { -1 };
int32_t g_clocks_per_sec;
float g_f32_pi;
int32_t g_i32_maxvalue;
int32_t g_i32_minvalue;
sjs_log g_log = { -1 };
sjs_hash_type_bool g_log_excludeall = { -1 };
sjs_hash_type_bool g_log_includeall = { -1 };
uint32_t g_u32_maxvalue;
int32_t result1;
sjs_class* sjt_parent42 = 0;
sjs_hash_type_bool sjt_value1 = { -1 };

void sjf_array_char(sjs_array_char* _this);
void sjf_array_char_clone(sjs_array_char* _parent, int32_t offset, int32_t count, int32_t newsize, sjs_array_char* _return);
void sjf_array_char_clone_heap(sjs_array_char* _parent, int32_t offset, int32_t count, int32_t newsize, sjs_array_char** _return);
void sjf_array_char_copy(sjs_array_char* _this, sjs_array_char* _from);
void sjf_array_char_destroy(sjs_array_char* _this);
void sjf_array_char_getat(sjs_array_char* _parent, int32_t index, char* _return);
void sjf_array_char_getcount(sjs_array_char* _parent, int32_t* _return);
void sjf_array_char_gettotalcount(sjs_array_char* _parent, int32_t* _return);
void sjf_array_char_heap(sjs_array_char* _this);
void sjf_array_char_initat(sjs_array_char* _parent, int32_t index, char item);
void sjf_char_touppercase(char x, char* _return);
void sjf_class(sjs_class* _this);
void sjf_class_copy(sjs_class* _this, sjs_class* _from);
void sjf_class_destroy(sjs_class* _this);
void sjf_class_dothing1(sjs_class* _parent);
void sjf_class_heap(sjs_class* _this);
void sjf_debug_writeline(sjs_string* data);
void sjf_hash_type_bool(sjs_hash_type_bool* _this);
void sjf_hash_type_bool__weakptrremovekey(sjs_hash_type_bool* _parent, int32_t key);
void sjf_hash_type_bool__weakptrremovevalue(sjs_hash_type_bool* _parent, bool val);
void sjf_hash_type_bool_copy(sjs_hash_type_bool* _this, sjs_hash_type_bool* _from);
void sjf_hash_type_bool_destroy(sjs_hash_type_bool* _this);
void sjf_hash_type_bool_getat(sjs_hash_type_bool* _parent, int32_t key, bool_option* _return);
void sjf_hash_type_bool_heap(sjs_hash_type_bool* _this);
void sjf_lambda2(sjs_lambda2* _this);
void sjf_lambda2_copy(sjs_lambda2* _this, sjs_lambda2* _from);
void sjf_lambda2_destroy(sjs_lambda2* _this);
void sjf_lambda2_heap(sjs_lambda2* _this);
void sjf_lambda2_invoke(sjs_lambda2* _parent, sjs_string* _return);
void sjf_lambda2_invoke_heap(sjs_lambda2* _parent, sjs_string** _return);
void sjf_lambda3(sjs_lambda3* _this);
void sjf_lambda3_copy(sjs_lambda3* _this, sjs_lambda3* _from);
void sjf_lambda3_destroy(sjs_lambda3* _this);
void sjf_lambda3_heap(sjs_lambda3* _this);
void sjf_lambda3_invoke(sjs_lambda3* _parent, sjs_string* _return);
void sjf_lambda3_invoke_heap(sjs_lambda3* _parent, sjs_string** _return);
void sjf_lambda4(sjs_lambda4* _this);
void sjf_lambda4_copy(sjs_lambda4* _this, sjs_lambda4* _from);
void sjf_lambda4_destroy(sjs_lambda4* _this);
void sjf_lambda4_heap(sjs_lambda4* _this);
void sjf_lambda4_invoke(sjs_lambda4* _parent, sjs_string* _return);
void sjf_lambda4_invoke_heap(sjs_lambda4* _parent, sjs_string** _return);
void sjf_log(sjs_log* _this);
void sjf_log__write(sjs_log* _parent, int32_t level, sjs_hash_type_bool* includes, int32_t t, cb_string_heap_string cb);
void sjf_log_copy(sjs_log* _this, sjs_log* _from);
void sjf_log_destroy(sjs_log* _this);
void sjf_log_error(sjs_log* _parent, int32_t t, cb_string_heap_string cb);
void sjf_log_heap(sjs_log* _this);
void sjf_log_info(sjs_log* _parent, int32_t t, cb_string_heap_string cb);
void sjf_loglevel_asstring(int32_t e, sjs_string* _return);
void sjf_loglevel_asstring_heap(int32_t e, sjs_string** _return);
void sjf_string(sjs_string* _this);
void sjf_string_add(sjs_string* _parent, sjs_string* item, sjs_string* _return);
void sjf_string_add_heap(sjs_string* _parent, sjs_string* item, sjs_string** _return);
void sjf_string_copy(sjs_string* _this, sjs_string* _from);
void sjf_string_destroy(sjs_string* _this);
void sjf_string_getat(sjs_string* _parent, int32_t index, char* _return);
void sjf_string_heap(sjs_string* _this);
void sjf_string_nullterminate(sjs_string* _parent);
void sjf_string_touppercase(sjs_string* _parent, sjs_string* _return);
void sjf_string_touppercase_heap(sjs_string* _parent, sjs_string** _return);
void sjf_type_asstring(int32_t t, sjs_string* _return);
void sjf_type_asstring_heap(int32_t t, sjs_string** _return);
void sjf_type_hash(int32_t val, uint32_t* _return);
void sjf_type_isequal(int32_t l, int32_t r, bool* _return);
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
    return ((sjs_array*)str->data.v)->data + str->offset;
}
#include <lib/sj-lib-common/common.cpp>
void sjf_array_char(sjs_array_char* _this) {
#line 363 "lib/sj-lib-common/array.sj"
    if (_this->v == 0) {
#line 364
        _this->v = &g_empty;
#line 365
    }
#line 366
    sjs_array* arr = (sjs_array*)_this->v;
#line 367
    arr->refcount++;
}

void sjf_array_char_clone(sjs_array_char* _parent, int32_t offset, int32_t count, int32_t newsize, sjs_array_char* _return) {
    void* newv;

#line 169 "lib/sj-lib-common/array.sj"
    newv = 0;
#line 171
    sjs_array* arr = (sjs_array*)_parent->v;
#line 172
    if (offset + count > arr->count) {
#line 173
        halt("grow: offset %d count %d out of bounds %d\n", offset, count, arr->count);
#line 174
    }
#line 176
    if (count > arr->count - offset) {
#line 177
        halt("grow: new count larger than old count %d:%d\n", count, arr->count - offset);
#line 178
    }
#line 180
    sjs_array* newArr = createarray(sizeof(char), newsize);
#line 181
    if (!newArr) {
#line 182
        halt("grow: out of memory\n");
#line 183
    }
#line 185
    newv = newArr;
#line 186
    char* p = (char*)arr->data + offset;
#line 187
    char* newp = (char*)newArr->data;
#line 189
    newArr->size = newsize;
#line 190
    newArr->count = count;
#line 192
    #if true
#line 193
    memcpy(newp, p, sizeof(char) * count);
#line 194
    #else
#line 195
    for (int i = 0; i < count; i++) {
#line 196
        #line 170 "lib/sj-lib-common/array.sj"
newp[i] = p[i];
;
#line 197
    }
#line 198
    #endif
#line 198
    _return->_refCount = 1;
#line 200
    _return->v = newv;
#line 200
    sjf_array_char(_return);
}

void sjf_array_char_clone_heap(sjs_array_char* _parent, int32_t offset, int32_t count, int32_t newsize, sjs_array_char** _return) {
    void* newv;

#line 169 "lib/sj-lib-common/array.sj"
    newv = 0;
#line 171
    sjs_array* arr = (sjs_array*)_parent->v;
#line 172
    if (offset + count > arr->count) {
#line 173
        halt("grow: offset %d count %d out of bounds %d\n", offset, count, arr->count);
#line 174
    }
#line 176
    if (count > arr->count - offset) {
#line 177
        halt("grow: new count larger than old count %d:%d\n", count, arr->count - offset);
#line 178
    }
#line 180
    sjs_array* newArr = createarray(sizeof(char), newsize);
#line 181
    if (!newArr) {
#line 182
        halt("grow: out of memory\n");
#line 183
    }
#line 185
    newv = newArr;
#line 186
    char* p = (char*)arr->data + offset;
#line 187
    char* newp = (char*)newArr->data;
#line 189
    newArr->size = newsize;
#line 190
    newArr->count = count;
#line 192
    #if true
#line 193
    memcpy(newp, p, sizeof(char) * count);
#line 194
    #else
#line 195
    for (int i = 0; i < count; i++) {
#line 196
        #line 170 "lib/sj-lib-common/array.sj"
newp[i] = p[i];
;
#line 197
    }
#line 198
    #endif
#line 198
    (*_return) = (sjs_array_char*)malloc(sizeof(sjs_array_char));
#line 198
    (*_return)->_refCount = 1;
#line 200
    (*_return)->v = newv;
#line 200
    sjf_array_char_heap((*_return));
}

void sjf_array_char_copy(sjs_array_char* _this, sjs_array_char* _from) {
#line 26 "lib/sj-lib-common/array.sj"
    _this->v = _from->v;
#line 372
    sjs_array* arr = (sjs_array*)_this->v;
#line 373
    arr->refcount++;
}

void sjf_array_char_destroy(sjs_array_char* _this) {
#line 377 "lib/sj-lib-common/array.sj"
    sjs_array* arr = (sjs_array*)_this->v;
#line 378
    arr->refcount--;
#line 379
    if (arr->refcount == 0) {
#line 380
        #if !true && !false
#line 381
        char* p = (char*)arr->data;
#line 382
        for (int i = 0; i < arr->count; i++) {
#line 383
            ;
#line 384
        }
#line 385
        #endif
#line 386
        free(arr);
#line 387
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

void sjf_array_char_gettotalcount(sjs_array_char* _parent, int32_t* _return) {
#line 37 "lib/sj-lib-common/array.sj"
    #line 36 "lib/sj-lib-common/array.sj"
(*_return) = ((sjs_array*)_parent->v)->size;
return;;
}

void sjf_array_char_heap(sjs_array_char* _this) {
#line 363 "lib/sj-lib-common/array.sj"
    if (_this->v == 0) {
#line 364
        _this->v = &g_empty;
#line 365
    }
#line 366
    sjs_array* arr = (sjs_array*)_this->v;
#line 367
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

void sjf_char_touppercase(char x, char* _return) {
#line 3 "lib/sj-lib-common/char.sj"
    #line 2 "lib/sj-lib-common/char.sj"
(*_return) = toupper(x);
return;
}

void sjf_class(sjs_class* _this) {
    sjs_lambda3 sjt_call28 = { -1 };
    sjs_lambda4 sjt_call29 = { -1 };
    int32_t sjt_functionParam51;
    cb_string_heap_string sjt_functionParam52;
    int32_t sjt_functionParam57;
    cb_string_heap_string sjt_functionParam58;
    sjs_log* sjt_parent37 = 0;
    sjs_log* sjt_parent38 = 0;

#line 30 "lib/sj-lib-common/log.sj"
    sjt_parent37 = &g_log;
#line 6 "log1.sj"
    sjt_functionParam51 = 27;
#line 6
    sjs_lambda3* lambainit1;
#line 6
    sjt_call28._refCount = 1;
#line 6
    sjf_lambda3(&sjt_call28);
#line 6
    lambainit1 = &sjt_call28;
#line 6
    sjt_functionParam52._parent = (sjs_object*)lambainit1;
#line 6
    sjt_functionParam52._cb = (void(*)(sjs_object*, sjs_string*))sjf_lambda3_invoke;
#line 6
    sjt_functionParam52._cb_heap = (void(*)(sjs_object*, sjs_string**))sjf_lambda3_invoke_heap;
#line 6
    sjf_log_info(sjt_parent37, sjt_functionParam51, sjt_functionParam52);
#line 38 "lib/sj-lib-common/log.sj"
    sjt_parent38 = &g_log;
#line 7 "log1.sj"
    sjt_functionParam57 = 27;
#line 7
    sjs_lambda4* lambainit2;
#line 7
    sjt_call29._refCount = 1;
#line 7
    sjf_lambda4(&sjt_call29);
#line 7
    lambainit2 = &sjt_call29;
#line 7
    sjt_functionParam58._parent = (sjs_object*)lambainit2;
#line 7
    sjt_functionParam58._cb = (void(*)(sjs_object*, sjs_string*))sjf_lambda4_invoke;
#line 7
    sjt_functionParam58._cb_heap = (void(*)(sjs_object*, sjs_string**))sjf_lambda4_invoke_heap;
#line 7
    sjf_log_error(sjt_parent38, sjt_functionParam57, sjt_functionParam58);

    if (sjt_call28._refCount == 1) { sjf_lambda3_destroy(&sjt_call28); }
;
    if (sjt_call29._refCount == 1) { sjf_lambda4_destroy(&sjt_call29); }
;
}

void sjf_class_copy(sjs_class* _this, sjs_class* _from) {
}

void sjf_class_destroy(sjs_class* _this) {
}

void sjf_class_dothing1(sjs_class* _parent) {
    sjs_lambda2 sjt_call32 = { -1 };
    int32_t sjt_functionParam63;
    cb_string_heap_string sjt_functionParam64;
    sjs_log* sjt_parent41 = 0;

#line 30 "lib/sj-lib-common/log.sj"
    sjt_parent41 = &g_log;
#line 3 "log1.sj"
    sjt_functionParam63 = 27;
#line 3
    sjs_lambda2* lambainit5;
#line 3
    sjt_call32._refCount = 1;
#line 3
    sjf_lambda2(&sjt_call32);
#line 3
    lambainit5 = &sjt_call32;
#line 3
    sjt_functionParam64._parent = (sjs_object*)lambainit5;
#line 3
    sjt_functionParam64._cb = (void(*)(sjs_object*, sjs_string*))sjf_lambda2_invoke;
#line 3
    sjt_functionParam64._cb_heap = (void(*)(sjs_object*, sjs_string**))sjf_lambda2_invoke_heap;
#line 3
    sjf_log_info(sjt_parent41, sjt_functionParam63, sjt_functionParam64);

    if (sjt_call32._refCount == 1) { sjf_lambda2_destroy(&sjt_call32); }
;
}

void sjf_class_heap(sjs_class* _this) {
    sjs_lambda3 sjt_call30 = { -1 };
    sjs_lambda4 sjt_call31 = { -1 };
    int32_t sjt_functionParam59;
    cb_string_heap_string sjt_functionParam60;
    int32_t sjt_functionParam61;
    cb_string_heap_string sjt_functionParam62;
    sjs_log* sjt_parent39 = 0;
    sjs_log* sjt_parent40 = 0;

#line 30 "lib/sj-lib-common/log.sj"
    sjt_parent39 = &g_log;
#line 6 "log1.sj"
    sjt_functionParam59 = 27;
#line 6
    sjs_lambda3* lambainit3;
#line 6
    sjt_call30._refCount = 1;
#line 6
    sjf_lambda3(&sjt_call30);
#line 6
    lambainit3 = &sjt_call30;
#line 6
    sjt_functionParam60._parent = (sjs_object*)lambainit3;
#line 6
    sjt_functionParam60._cb = (void(*)(sjs_object*, sjs_string*))sjf_lambda3_invoke;
#line 6
    sjt_functionParam60._cb_heap = (void(*)(sjs_object*, sjs_string**))sjf_lambda3_invoke_heap;
#line 6
    sjf_log_info(sjt_parent39, sjt_functionParam59, sjt_functionParam60);
#line 38 "lib/sj-lib-common/log.sj"
    sjt_parent40 = &g_log;
#line 7 "log1.sj"
    sjt_functionParam61 = 27;
#line 7
    sjs_lambda4* lambainit4;
#line 7
    sjt_call31._refCount = 1;
#line 7
    sjf_lambda4(&sjt_call31);
#line 7
    lambainit4 = &sjt_call31;
#line 7
    sjt_functionParam62._parent = (sjs_object*)lambainit4;
#line 7
    sjt_functionParam62._cb = (void(*)(sjs_object*, sjs_string*))sjf_lambda4_invoke;
#line 7
    sjt_functionParam62._cb_heap = (void(*)(sjs_object*, sjs_string**))sjf_lambda4_invoke_heap;
#line 7
    sjf_log_error(sjt_parent40, sjt_functionParam61, sjt_functionParam62);

    if (sjt_call30._refCount == 1) { sjf_lambda3_destroy(&sjt_call30); }
;
    if (sjt_call31._refCount == 1) { sjf_lambda4_destroy(&sjt_call31); }
;
}

void sjf_debug_writeline(sjs_string* data) {
#line 10 "lib/sj-lib-common/debug.sj"
    debugout("%s\n", string_char(data));
}

void sjf_hash_type_bool(sjs_hash_type_bool* _this) {
#line 233 "lib/sj-lib-common/hash.sj"
    _this->_hash = kh_init(type_bool_hash_type);
}

void sjf_hash_type_bool__weakptrremovekey(sjs_hash_type_bool* _parent, int32_t key) {
#line 188 "lib/sj-lib-common/hash.sj"
    #if false
#line 189
    khash_t(type_bool_hash_type)* p = (khash_t(type_bool_hash_type)*)_parent->_hash;    
#line 190
    khiter_t k = kh_get(type_bool_hash_type, p, key);
#line 191
    if (k != kh_end(p)) {
#line 192
        kh_del(type_bool_hash_type, p, k);
#line 193
    }
#line 194
    #endif
}

void sjf_hash_type_bool__weakptrremovevalue(sjs_hash_type_bool* _parent, bool val) {
#line 200 "lib/sj-lib-common/hash.sj"
    #if false
#line 201
    khash_t(type_bool_hash_type)* p = (khash_t(type_bool_hash_type)*)_parent->_hash;
#line 202
    for (khiter_t k = kh_begin(p); k != kh_end(p); ++k) {
#line 203
        if (kh_exist(p, k)) {
#line 204
            bool t = kh_value(p, k);
#line 205
            if (t == val) {
#line 206
                kh_del(type_bool_hash_type, p, k);
#line 207
            }
#line 208
        }
#line 209
    }
#line 210
    #endif
}

void sjf_hash_type_bool_copy(sjs_hash_type_bool* _this, sjs_hash_type_bool* _from) {
#line 238 "lib/sj-lib-common/hash.sj"
    _this->_hash = _from->_hash;
#line 239
    khash_t(type_bool_hash_type)* p = (khash_t(type_bool_hash_type)*)_this->_hash;
#line 240
    p->refcount++;
}

void sjf_hash_type_bool_destroy(sjs_hash_type_bool* _this) {
#line 244 "lib/sj-lib-common/hash.sj"
    khash_t(type_bool_hash_type)* p = (khash_t(type_bool_hash_type)*)_this->_hash;
#line 245
    p->refcount--;
#line 246
    if (p->refcount == 0) {
#line 247
        for (khiter_t k = kh_begin(p); k != kh_end(p); ++k) {
#line 248
            if (kh_exist(p, k)) {
#line 250
                #if false
#line 251
                delete_cb cb = { p, (void(*)(void*, void*))sjf_hash_type_bool__weakptrremovekey };
#line 252
                weakptr_cb_remove(kh_key(p, k), cb);
#line 253
                #else
#line 254
                ;
#line 255
                #endif
#line 257
                #if false
#line 258
                delete_cb cb = { p, (void(*)(void*, void*))sjf_hash_type_bool__weakptrremovevalue };
#line 259
                weakptr_cb_remove(kh_value(p, k), cb);
#line 260
                #else
#line 261
                ;
#line 262
                #endif
#line 263
            }
#line 264
        }
#line 265
        kh_destroy(type_bool_hash_type, (khash_t(type_bool_hash_type)*)_this->_hash);
#line 266
    }
}

void sjf_hash_type_bool_getat(sjs_hash_type_bool* _parent, int32_t key, bool_option* _return) {
#line 23 "lib/sj-lib-common/hash.sj"
    khash_t(type_bool_hash_type)* p = (khash_t(type_bool_hash_type)*)_parent->_hash;
#line 25
    #if false
#line 26
    khiter_t k = kh_get(type_bool_hash_type, p, *key);
#line 27
    #else
#line 28
    khiter_t k = kh_get(type_bool_hash_type, p, key);
#line 29
    #endif
#line 31
    if (k == kh_end(p)) {
#line 32
        #line 22 "lib/sj-lib-common/hash.sj"
(*_return) = bool_empty;
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

void sjf_hash_type_bool_heap(sjs_hash_type_bool* _this) {
#line 233 "lib/sj-lib-common/hash.sj"
    _this->_hash = kh_init(type_bool_hash_type);
}

void sjf_lambda2(sjs_lambda2* _this) {
}

void sjf_lambda2_copy(sjs_lambda2* _this, sjs_lambda2* _from) {
}

void sjf_lambda2_destroy(sjs_lambda2* _this) {
}

void sjf_lambda2_heap(sjs_lambda2* _this) {
}

void sjf_lambda2_invoke(sjs_lambda2* _parent, sjs_string* _return) {
    _return->_refCount = 1;
#line 3 "log1.sj"
    _return->offset = 0;
#line 3
    _return->count = 8;
#line 3
    _return->data._refCount = 1;
#line 3
    _return->data.v = &sjg_string12;
#line 3
    sjf_array_char(&_return->data);
#line 16 "lib/sj-lib-common/string.sj"
    _return->_isnullterminated = false;
#line 16
    sjf_string(_return);
}

void sjf_lambda2_invoke_heap(sjs_lambda2* _parent, sjs_string** _return) {
    (*_return) = (sjs_string*)malloc(sizeof(sjs_string));
    (*_return)->_refCount = 1;
#line 3 "log1.sj"
    (*_return)->offset = 0;
#line 3
    (*_return)->count = 8;
#line 3
    (*_return)->data._refCount = 1;
#line 3
    (*_return)->data.v = &sjg_string12;
#line 3
    sjf_array_char(&(*_return)->data);
#line 16 "lib/sj-lib-common/string.sj"
    (*_return)->_isnullterminated = false;
#line 16
    sjf_string_heap((*_return));
}

void sjf_lambda3(sjs_lambda3* _this) {
}

void sjf_lambda3_copy(sjs_lambda3* _this, sjs_lambda3* _from) {
}

void sjf_lambda3_destroy(sjs_lambda3* _this) {
}

void sjf_lambda3_heap(sjs_lambda3* _this) {
}

void sjf_lambda3_invoke(sjs_lambda3* _parent, sjs_string* _return) {
    _return->_refCount = 1;
#line 6 "log1.sj"
    _return->offset = 0;
#line 6
    _return->count = 4;
#line 6
    _return->data._refCount = 1;
#line 6
    _return->data.v = &sjg_string10;
#line 6
    sjf_array_char(&_return->data);
#line 16 "lib/sj-lib-common/string.sj"
    _return->_isnullterminated = false;
#line 16
    sjf_string(_return);
}

void sjf_lambda3_invoke_heap(sjs_lambda3* _parent, sjs_string** _return) {
    (*_return) = (sjs_string*)malloc(sizeof(sjs_string));
    (*_return)->_refCount = 1;
#line 6 "log1.sj"
    (*_return)->offset = 0;
#line 6
    (*_return)->count = 4;
#line 6
    (*_return)->data._refCount = 1;
#line 6
    (*_return)->data.v = &sjg_string10;
#line 6
    sjf_array_char(&(*_return)->data);
#line 16 "lib/sj-lib-common/string.sj"
    (*_return)->_isnullterminated = false;
#line 16
    sjf_string_heap((*_return));
}

void sjf_lambda4(sjs_lambda4* _this) {
}

void sjf_lambda4_copy(sjs_lambda4* _this, sjs_lambda4* _from) {
}

void sjf_lambda4_destroy(sjs_lambda4* _this) {
}

void sjf_lambda4_heap(sjs_lambda4* _this) {
}

void sjf_lambda4_invoke(sjs_lambda4* _parent, sjs_string* _return) {
    _return->_refCount = 1;
#line 7 "log1.sj"
    _return->offset = 0;
#line 7
    _return->count = 9;
#line 7
    _return->data._refCount = 1;
#line 7
    _return->data.v = &sjg_string11;
#line 7
    sjf_array_char(&_return->data);
#line 16 "lib/sj-lib-common/string.sj"
    _return->_isnullterminated = false;
#line 16
    sjf_string(_return);
}

void sjf_lambda4_invoke_heap(sjs_lambda4* _parent, sjs_string** _return) {
    (*_return) = (sjs_string*)malloc(sizeof(sjs_string));
    (*_return)->_refCount = 1;
#line 7 "log1.sj"
    (*_return)->offset = 0;
#line 7
    (*_return)->count = 9;
#line 7
    (*_return)->data._refCount = 1;
#line 7
    (*_return)->data.v = &sjg_string11;
#line 7
    sjf_array_char(&(*_return)->data);
#line 16 "lib/sj-lib-common/string.sj"
    (*_return)->_isnullterminated = false;
#line 16
    sjf_string_heap((*_return));
}

void sjf_log(sjs_log* _this) {
}

void sjf_log__write(sjs_log* _parent, int32_t level, sjs_hash_type_bool* includes, int32_t t, cb_string_heap_string cb) {
    if (level >= _parent->minlevel) {
        if ((includes != 0)) {
            sjs_hash_type_bool* ifValue1 = 0;
            sjs_string sjt_call1 = { -1 };
            sjs_string sjt_call14 = { -1 };
            sjs_string sjt_call15 = { -1 };
            sjs_string sjt_call16 = { -1 };
            sjs_string sjt_call17 = { -1 };
            sjs_string sjt_call2 = { -1 };
            sjs_string sjt_call3 = { -1 };
            sjs_string sjt_call4 = { -1 };
            sjs_string sjt_call5 = { -1 };
            sjs_string sjt_call6 = { -1 };
            bool sjt_capture3;
            bool_option sjt_capture4;
            int32_t sjt_functionParam4;
            sjs_hash_type_bool* sjt_parent4 = 0;

#line 46 "lib/sj-lib-common/log.sj"
            ifValue1 = includes;
#line 21 "lib/sj-lib-common/hash.sj"
            sjt_parent4 = ifValue1;
#line 46 "lib/sj-lib-common/log.sj"
            sjt_functionParam4 = t;
#line 46
            sjf_hash_type_bool_getat(sjt_parent4, sjt_functionParam4, &sjt_capture4);
            if (sjt_capture4.isvalid) {
                int32_t sjt_functionParam5;
                bool_option sjt_getValue1;
                sjs_hash_type_bool* sjt_parent5 = 0;

#line 21 "lib/sj-lib-common/hash.sj"
                sjt_parent5 = ifValue1;
#line 46 "lib/sj-lib-common/log.sj"
                sjt_functionParam5 = t;
#line 46
                sjf_hash_type_bool_getat(sjt_parent5, sjt_functionParam5, &sjt_getValue1);
#line 49
                sjt_capture3 = sjt_getValue1.value;
            } else {
#line 49 "lib/sj-lib-common/log.sj"
                sjt_capture3 = false;
            }

            if (sjt_capture3) {
                int32_t sjt_functionParam34;
                sjs_string* sjt_functionParam35 = 0;
                sjs_string* sjt_functionParam36 = 0;
                int32_t sjt_functionParam37;
                sjs_string* sjt_functionParam38 = 0;
                sjs_string* sjt_functionParam39 = 0;
                sjs_string* sjt_functionParam6 = 0;
                sjs_string* sjt_parent23 = 0;
                sjs_string* sjt_parent24 = 0;
                sjs_string* sjt_parent25 = 0;
                sjs_string* sjt_parent26 = 0;
                sjs_string* sjt_parent31 = 0;

#line 46 "lib/sj-lib-common/log.sj"
                sjt_functionParam34 = level;
#line 46
                sjf_loglevel_asstring(sjt_functionParam34, &sjt_call6);
#line 50
                sjt_parent31 = &sjt_call6;
#line 50
                sjf_string_touppercase(sjt_parent31, &sjt_call5);
#line 50
                sjt_parent26 = &sjt_call5;
#line 50
                sjt_call14._refCount = 1;
#line 50
                sjt_call14.offset = 0;
#line 50
                sjt_call14.count = 2;
#line 50
                sjt_call14.data._refCount = 1;
#line 50
                sjt_call14.data.v = &sjg_string8;
#line 50
                sjf_array_char(&sjt_call14.data);
#line 16 "lib/sj-lib-common/string.sj"
                sjt_call14._isnullterminated = false;
#line 16
                sjf_string(&sjt_call14);
#line 50 "lib/sj-lib-common/log.sj"
                sjt_functionParam35 = &sjt_call14;
#line 50
                sjf_string_add(sjt_parent26, sjt_functionParam35, &sjt_call4);
#line 50
                sjt_parent25 = &sjt_call4;
#line 46
                sjt_functionParam37 = t;
#line 46
                sjf_type_asstring(sjt_functionParam37, &sjt_call15);
#line 50
                sjt_functionParam36 = &sjt_call15;
#line 50
                sjf_string_add(sjt_parent25, sjt_functionParam36, &sjt_call3);
#line 50
                sjt_parent24 = &sjt_call3;
#line 50
                sjt_call16._refCount = 1;
#line 50
                sjt_call16.offset = 0;
#line 50
                sjt_call16.count = 2;
#line 50
                sjt_call16.data._refCount = 1;
#line 50
                sjt_call16.data.v = &sjg_string9;
#line 50
                sjf_array_char(&sjt_call16.data);
#line 16 "lib/sj-lib-common/string.sj"
                sjt_call16._isnullterminated = false;
#line 16
                sjf_string(&sjt_call16);
#line 50 "lib/sj-lib-common/log.sj"
                sjt_functionParam38 = &sjt_call16;
#line 50
                sjf_string_add(sjt_parent24, sjt_functionParam38, &sjt_call2);
#line 50
                sjt_parent23 = &sjt_call2;
#line 50
                cb._cb(cb._parent, &sjt_call17);
#line 50
                sjt_functionParam39 = &sjt_call17;
#line 50
                sjf_string_add(sjt_parent23, sjt_functionParam39, &sjt_call1);
#line 50
                sjt_functionParam6 = &sjt_call1;
#line 50
                sjf_debug_writeline(sjt_functionParam6);
            }

            if (sjt_call1._refCount == 1) { sjf_string_destroy(&sjt_call1); }
;
            if (sjt_call14._refCount == 1) { sjf_string_destroy(&sjt_call14); }
;
            if (sjt_call15._refCount == 1) { sjf_string_destroy(&sjt_call15); }
;
            if (sjt_call16._refCount == 1) { sjf_string_destroy(&sjt_call16); }
;
            if (sjt_call17._refCount == 1) { sjf_string_destroy(&sjt_call17); }
;
            if (sjt_call2._refCount == 1) { sjf_string_destroy(&sjt_call2); }
;
            if (sjt_call3._refCount == 1) { sjf_string_destroy(&sjt_call3); }
;
            if (sjt_call4._refCount == 1) { sjf_string_destroy(&sjt_call4); }
;
            if (sjt_call5._refCount == 1) { sjf_string_destroy(&sjt_call5); }
;
            if (sjt_call6._refCount == 1) { sjf_string_destroy(&sjt_call6); }
;
        } else {
            sjs_string sjt_call18 = { -1 };
            sjs_string sjt_call19 = { -1 };
            sjs_string sjt_call20 = { -1 };
            sjs_string sjt_call21 = { -1 };
            sjs_string sjt_call22 = { -1 };
            sjs_string sjt_call23 = { -1 };
            sjs_string sjt_call24 = { -1 };
            sjs_string sjt_call25 = { -1 };
            sjs_string sjt_call26 = { -1 };
            sjs_string sjt_call27 = { -1 };
            sjs_string* sjt_functionParam40 = 0;
            int32_t sjt_functionParam41;
            sjs_string* sjt_functionParam42 = 0;
            sjs_string* sjt_functionParam43 = 0;
            int32_t sjt_functionParam44;
            sjs_string* sjt_functionParam45 = 0;
            sjs_string* sjt_functionParam46 = 0;
            sjs_string* sjt_parent32 = 0;
            sjs_string* sjt_parent33 = 0;
            sjs_string* sjt_parent34 = 0;
            sjs_string* sjt_parent35 = 0;
            sjs_string* sjt_parent36 = 0;

#line 46 "lib/sj-lib-common/log.sj"
            sjt_functionParam41 = level;
#line 46
            sjf_loglevel_asstring(sjt_functionParam41, &sjt_call23);
#line 53
            sjt_parent36 = &sjt_call23;
#line 53
            sjf_string_touppercase(sjt_parent36, &sjt_call22);
#line 53
            sjt_parent35 = &sjt_call22;
#line 53
            sjt_call24._refCount = 1;
#line 53
            sjt_call24.offset = 0;
#line 53
            sjt_call24.count = 2;
#line 53
            sjt_call24.data._refCount = 1;
#line 53
            sjt_call24.data.v = &sjg_string8;
#line 53
            sjf_array_char(&sjt_call24.data);
#line 16 "lib/sj-lib-common/string.sj"
            sjt_call24._isnullterminated = false;
#line 16
            sjf_string(&sjt_call24);
#line 53 "lib/sj-lib-common/log.sj"
            sjt_functionParam42 = &sjt_call24;
#line 53
            sjf_string_add(sjt_parent35, sjt_functionParam42, &sjt_call21);
#line 53
            sjt_parent34 = &sjt_call21;
#line 46
            sjt_functionParam44 = t;
#line 46
            sjf_type_asstring(sjt_functionParam44, &sjt_call25);
#line 53
            sjt_functionParam43 = &sjt_call25;
#line 53
            sjf_string_add(sjt_parent34, sjt_functionParam43, &sjt_call20);
#line 53
            sjt_parent33 = &sjt_call20;
#line 53
            sjt_call26._refCount = 1;
#line 53
            sjt_call26.offset = 0;
#line 53
            sjt_call26.count = 2;
#line 53
            sjt_call26.data._refCount = 1;
#line 53
            sjt_call26.data.v = &sjg_string9;
#line 53
            sjf_array_char(&sjt_call26.data);
#line 16 "lib/sj-lib-common/string.sj"
            sjt_call26._isnullterminated = false;
#line 16
            sjf_string(&sjt_call26);
#line 53 "lib/sj-lib-common/log.sj"
            sjt_functionParam45 = &sjt_call26;
#line 53
            sjf_string_add(sjt_parent33, sjt_functionParam45, &sjt_call19);
#line 53
            sjt_parent32 = &sjt_call19;
#line 53
            cb._cb(cb._parent, &sjt_call27);
#line 53
            sjt_functionParam46 = &sjt_call27;
#line 53
            sjf_string_add(sjt_parent32, sjt_functionParam46, &sjt_call18);
#line 53
            sjt_functionParam40 = &sjt_call18;
#line 53
            sjf_debug_writeline(sjt_functionParam40);

            if (sjt_call18._refCount == 1) { sjf_string_destroy(&sjt_call18); }
;
            if (sjt_call19._refCount == 1) { sjf_string_destroy(&sjt_call19); }
;
            if (sjt_call20._refCount == 1) { sjf_string_destroy(&sjt_call20); }
;
            if (sjt_call21._refCount == 1) { sjf_string_destroy(&sjt_call21); }
;
            if (sjt_call22._refCount == 1) { sjf_string_destroy(&sjt_call22); }
;
            if (sjt_call23._refCount == 1) { sjf_string_destroy(&sjt_call23); }
;
            if (sjt_call24._refCount == 1) { sjf_string_destroy(&sjt_call24); }
;
            if (sjt_call25._refCount == 1) { sjf_string_destroy(&sjt_call25); }
;
            if (sjt_call26._refCount == 1) { sjf_string_destroy(&sjt_call26); }
;
            if (sjt_call27._refCount == 1) { sjf_string_destroy(&sjt_call27); }
;
        }
    }
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

void sjf_log_error(sjs_log* _parent, int32_t t, cb_string_heap_string cb) {
    int32_t sjt_functionParam53;
    sjs_hash_type_bool* sjt_functionParam54 = 0;
    int32_t sjt_functionParam55;
    cb_string_heap_string sjt_functionParam56;

#line 39 "lib/sj-lib-common/log.sj"
    sjt_functionParam53 = g_loglevel_error;
#line 39
    sjt_functionParam54 = (_parent->errorincludes._refCount != -1 ? &_parent->errorincludes : 0);
#line 38
    sjt_functionParam55 = t;
#line 38
    sjt_functionParam56 = cb;
#line 38
    sjf_log__write(_parent, sjt_functionParam53, sjt_functionParam54, sjt_functionParam55, sjt_functionParam56);
}

void sjf_log_heap(sjs_log* _this) {
}

void sjf_log_info(sjs_log* _parent, int32_t t, cb_string_heap_string cb) {
    int32_t sjt_functionParam47;
    sjs_hash_type_bool* sjt_functionParam48 = 0;
    int32_t sjt_functionParam49;
    cb_string_heap_string sjt_functionParam50;

#line 31 "lib/sj-lib-common/log.sj"
    sjt_functionParam47 = g_loglevel_info;
#line 31
    sjt_functionParam48 = (_parent->infoincludes._refCount != -1 ? &_parent->infoincludes : 0);
#line 30
    sjt_functionParam49 = t;
#line 30
    sjt_functionParam50 = cb;
#line 30
    sjf_log__write(_parent, sjt_functionParam47, sjt_functionParam48, sjt_functionParam49, sjt_functionParam50);
}

void sjf_loglevel_asstring(int32_t e, sjs_string* _return) {
    int32_t underscore1;

#line 1 "lib/sj-lib-common/log.sj"
    underscore1 = e;
    if (underscore1 == 0) {
        _return->_refCount = 1;
#line 1 "lib/sj-lib-common/log.sj"
        _return->offset = 0;
#line 1
        _return->count = 5;
#line 1
        _return->data._refCount = 1;
#line 1
        _return->data.v = &sjg_string1;
#line 1
        sjf_array_char(&_return->data);
#line 16 "lib/sj-lib-common/string.sj"
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
    } else {
        if (underscore1 == 1) {
            _return->_refCount = 1;
#line 1 "lib/sj-lib-common/log.sj"
            _return->offset = 0;
#line 1
            _return->count = 5;
#line 1
            _return->data._refCount = 1;
#line 1
            _return->data.v = &sjg_string2;
#line 1
            sjf_array_char(&_return->data);
#line 16 "lib/sj-lib-common/string.sj"
            _return->_isnullterminated = false;
#line 16
            sjf_string(_return);
        } else {
            if (underscore1 == 2) {
                _return->_refCount = 1;
#line 1 "lib/sj-lib-common/log.sj"
                _return->offset = 0;
#line 1
                _return->count = 4;
#line 1
                _return->data._refCount = 1;
#line 1
                _return->data.v = &sjg_string3;
#line 1
                sjf_array_char(&_return->data);
#line 16 "lib/sj-lib-common/string.sj"
                _return->_isnullterminated = false;
#line 16
                sjf_string(_return);
            } else {
                if (underscore1 == 3) {
                    _return->_refCount = 1;
#line 1 "lib/sj-lib-common/log.sj"
                    _return->offset = 0;
#line 1
                    _return->count = 4;
#line 1
                    _return->data._refCount = 1;
#line 1
                    _return->data.v = &sjg_string4;
#line 1
                    sjf_array_char(&_return->data);
#line 16 "lib/sj-lib-common/string.sj"
                    _return->_isnullterminated = false;
#line 16
                    sjf_string(_return);
                } else {
                    if (underscore1 == 4) {
                        _return->_refCount = 1;
#line 1 "lib/sj-lib-common/log.sj"
                        _return->offset = 0;
#line 1
                        _return->count = 5;
#line 1
                        _return->data._refCount = 1;
#line 1
                        _return->data.v = &sjg_string5;
#line 1
                        sjf_array_char(&_return->data);
#line 16 "lib/sj-lib-common/string.sj"
                        _return->_isnullterminated = false;
#line 16
                        sjf_string(_return);
                    } else {
                        if (underscore1 == 5) {
                            _return->_refCount = 1;
#line 1 "lib/sj-lib-common/log.sj"
                            _return->offset = 0;
#line 1
                            _return->count = 5;
#line 1
                            _return->data._refCount = 1;
#line 1
                            _return->data.v = &sjg_string6;
#line 1
                            sjf_array_char(&_return->data);
#line 16 "lib/sj-lib-common/string.sj"
                            _return->_isnullterminated = false;
#line 16
                            sjf_string(_return);
                        } else {
                            _return->_refCount = 1;
#line 1 "lib/sj-lib-common/log.sj"
                            _return->offset = 0;
#line 1
                            _return->count = 0;
#line 1
                            _return->data._refCount = 1;
#line 1
                            _return->data.v = &sjg_string7;
#line 1
                            sjf_array_char(&_return->data);
#line 16 "lib/sj-lib-common/string.sj"
                            _return->_isnullterminated = false;
#line 16
                            sjf_string(_return);
                        }
                    }
                }
            }
        }
    }
}

void sjf_loglevel_asstring_heap(int32_t e, sjs_string** _return) {
    int32_t underscore2;

#line 1 "lib/sj-lib-common/log.sj"
    underscore2 = e;
    if (underscore2 == 0) {
        sjs_string sjt_call7 = { -1 };

        sjt_call7._refCount = 1;
#line 1 "lib/sj-lib-common/log.sj"
        sjt_call7.offset = 0;
#line 1
        sjt_call7.count = 5;
#line 1
        sjt_call7.data._refCount = 1;
#line 1
        sjt_call7.data.v = &sjg_string1;
#line 1
        sjf_array_char(&sjt_call7.data);
#line 16 "lib/sj-lib-common/string.sj"
        sjt_call7._isnullterminated = false;
#line 16
        sjf_string(&sjt_call7);
#line 16
        (*_return) = (sjs_string*)malloc(sizeof(sjs_string));
#line 16
        (*_return)->_refCount = 1;
#line 1 "lib/sj-lib-common/log.sj"
        sjf_string_copy((*_return), &sjt_call7);

        if (sjt_call7._refCount == 1) { sjf_string_destroy(&sjt_call7); }
;
    } else {
        if (underscore2 == 1) {
            sjs_string sjt_call8 = { -1 };

            sjt_call8._refCount = 1;
#line 1 "lib/sj-lib-common/log.sj"
            sjt_call8.offset = 0;
#line 1
            sjt_call8.count = 5;
#line 1
            sjt_call8.data._refCount = 1;
#line 1
            sjt_call8.data.v = &sjg_string2;
#line 1
            sjf_array_char(&sjt_call8.data);
#line 16 "lib/sj-lib-common/string.sj"
            sjt_call8._isnullterminated = false;
#line 16
            sjf_string(&sjt_call8);
#line 16
            (*_return) = (sjs_string*)malloc(sizeof(sjs_string));
#line 16
            (*_return)->_refCount = 1;
#line 1 "lib/sj-lib-common/log.sj"
            sjf_string_copy((*_return), &sjt_call8);

            if (sjt_call8._refCount == 1) { sjf_string_destroy(&sjt_call8); }
;
        } else {
            if (underscore2 == 2) {
                sjs_string sjt_call9 = { -1 };

                sjt_call9._refCount = 1;
#line 1 "lib/sj-lib-common/log.sj"
                sjt_call9.offset = 0;
#line 1
                sjt_call9.count = 4;
#line 1
                sjt_call9.data._refCount = 1;
#line 1
                sjt_call9.data.v = &sjg_string3;
#line 1
                sjf_array_char(&sjt_call9.data);
#line 16 "lib/sj-lib-common/string.sj"
                sjt_call9._isnullterminated = false;
#line 16
                sjf_string(&sjt_call9);
#line 16
                (*_return) = (sjs_string*)malloc(sizeof(sjs_string));
#line 16
                (*_return)->_refCount = 1;
#line 1 "lib/sj-lib-common/log.sj"
                sjf_string_copy((*_return), &sjt_call9);

                if (sjt_call9._refCount == 1) { sjf_string_destroy(&sjt_call9); }
;
            } else {
                if (underscore2 == 3) {
                    sjs_string sjt_call10 = { -1 };

                    sjt_call10._refCount = 1;
#line 1 "lib/sj-lib-common/log.sj"
                    sjt_call10.offset = 0;
#line 1
                    sjt_call10.count = 4;
#line 1
                    sjt_call10.data._refCount = 1;
#line 1
                    sjt_call10.data.v = &sjg_string4;
#line 1
                    sjf_array_char(&sjt_call10.data);
#line 16 "lib/sj-lib-common/string.sj"
                    sjt_call10._isnullterminated = false;
#line 16
                    sjf_string(&sjt_call10);
#line 16
                    (*_return) = (sjs_string*)malloc(sizeof(sjs_string));
#line 16
                    (*_return)->_refCount = 1;
#line 1 "lib/sj-lib-common/log.sj"
                    sjf_string_copy((*_return), &sjt_call10);

                    if (sjt_call10._refCount == 1) { sjf_string_destroy(&sjt_call10); }
;
                } else {
                    if (underscore2 == 4) {
                        sjs_string sjt_call11 = { -1 };

                        sjt_call11._refCount = 1;
#line 1 "lib/sj-lib-common/log.sj"
                        sjt_call11.offset = 0;
#line 1
                        sjt_call11.count = 5;
#line 1
                        sjt_call11.data._refCount = 1;
#line 1
                        sjt_call11.data.v = &sjg_string5;
#line 1
                        sjf_array_char(&sjt_call11.data);
#line 16 "lib/sj-lib-common/string.sj"
                        sjt_call11._isnullterminated = false;
#line 16
                        sjf_string(&sjt_call11);
#line 16
                        (*_return) = (sjs_string*)malloc(sizeof(sjs_string));
#line 16
                        (*_return)->_refCount = 1;
#line 1 "lib/sj-lib-common/log.sj"
                        sjf_string_copy((*_return), &sjt_call11);

                        if (sjt_call11._refCount == 1) { sjf_string_destroy(&sjt_call11); }
;
                    } else {
                        if (underscore2 == 5) {
                            sjs_string sjt_call12 = { -1 };

                            sjt_call12._refCount = 1;
#line 1 "lib/sj-lib-common/log.sj"
                            sjt_call12.offset = 0;
#line 1
                            sjt_call12.count = 5;
#line 1
                            sjt_call12.data._refCount = 1;
#line 1
                            sjt_call12.data.v = &sjg_string6;
#line 1
                            sjf_array_char(&sjt_call12.data);
#line 16 "lib/sj-lib-common/string.sj"
                            sjt_call12._isnullterminated = false;
#line 16
                            sjf_string(&sjt_call12);
#line 16
                            (*_return) = (sjs_string*)malloc(sizeof(sjs_string));
#line 16
                            (*_return)->_refCount = 1;
#line 1 "lib/sj-lib-common/log.sj"
                            sjf_string_copy((*_return), &sjt_call12);

                            if (sjt_call12._refCount == 1) { sjf_string_destroy(&sjt_call12); }
;
                        } else {
                            sjs_string sjt_call13 = { -1 };

                            sjt_call13._refCount = 1;
#line 1 "lib/sj-lib-common/log.sj"
                            sjt_call13.offset = 0;
#line 1
                            sjt_call13.count = 0;
#line 1
                            sjt_call13.data._refCount = 1;
#line 1
                            sjt_call13.data.v = &sjg_string7;
#line 1
                            sjf_array_char(&sjt_call13.data);
#line 16 "lib/sj-lib-common/string.sj"
                            sjt_call13._isnullterminated = false;
#line 16
                            sjf_string(&sjt_call13);
#line 16
                            (*_return) = (sjs_string*)malloc(sizeof(sjs_string));
#line 16
                            (*_return)->_refCount = 1;
#line 1 "lib/sj-lib-common/log.sj"
                            sjf_string_copy((*_return), &sjt_call13);

                            if (sjt_call13._refCount == 1) { sjf_string_destroy(&sjt_call13); }
;
                        }
                    }
                }
            }
        }
    }
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
        bool sjt_capture5;
        int32_t sjt_capture6;
        sjs_array_char* sjt_parent6 = 0;

#line 35 "lib/sj-lib-common/array.sj"
        sjt_parent6 = &_parent->data;
#line 35
        sjf_array_char_gettotalcount(sjt_parent6, &sjt_capture6);
        if (((_parent->offset + _parent->count) + item->count) < sjt_capture6) {
            int32_t sjt_capture7;
            sjs_array_char* sjt_parent7 = 0;

#line 29 "lib/sj-lib-common/array.sj"
            sjt_parent7 = &_parent->data;
#line 29
            sjf_array_char_getcount(sjt_parent7, &sjt_capture7);
#line 24 "lib/sj-lib-common/string.sj"
            sjt_capture5 = ((_parent->offset + _parent->count) == sjt_capture7);
        } else {
#line 24 "lib/sj-lib-common/string.sj"
            sjt_capture5 = false;
        }

        if (sjt_capture5) {
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
                int32_t sjt_functionParam10;
                int32_t sjt_functionParam7;
                char sjt_functionParam8;
                sjs_string* sjt_parent10 = 0;
                sjs_array_char* sjt_parent8 = 0;

#line 52 "lib/sj-lib-common/array.sj"
                sjt_parent8 = &_parent->data;
#line 28 "lib/sj-lib-common/string.sj"
                sjt_functionParam7 = newcount;
#line 18
                sjt_parent10 = item;
#line 27
                sjt_functionParam10 = i;
#line 27
                sjf_string_getat(sjt_parent10, sjt_functionParam10, &sjt_functionParam8);
#line 27
                sjf_array_char_initat(sjt_parent8, sjt_functionParam7, sjt_functionParam8);
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
            int32_t sjt_functionParam11;
            int32_t sjt_functionParam12;
            int32_t sjt_functionParam13;
            sjs_array_char* sjt_parent11 = 0;
            sjs_array_char* sjt_parent12 = 0;

#line 168 "lib/sj-lib-common/array.sj"
            sjt_parent11 = &_parent->data;
#line 34 "lib/sj-lib-common/string.sj"
            sjt_functionParam11 = _parent->offset;
#line 34
            sjt_functionParam12 = _parent->count;
#line 34
            sjt_functionParam13 = ((((_parent->count + item->count) - 1) / 256) + 1) * 256;
#line 34
            sjf_array_char_clone(sjt_parent11, sjt_functionParam11, sjt_functionParam12, sjt_functionParam13, &newdata);
#line 29 "lib/sj-lib-common/array.sj"
            sjt_parent12 = &newdata;
#line 29
            sjf_array_char_getcount(sjt_parent12, &newcount);
#line 37 "lib/sj-lib-common/string.sj"
            sjt_forStart2 = 0;
#line 37
            sjt_forEnd2 = item->count;
#line 37
            i = sjt_forStart2;
            while (i < sjt_forEnd2) {
                int32_t sjt_functionParam14;
                char sjt_functionParam15;
                int32_t sjt_functionParam16;
                sjs_array_char* sjt_parent13 = 0;
                sjs_string* sjt_parent14 = 0;

#line 52 "lib/sj-lib-common/array.sj"
                sjt_parent13 = &newdata;
#line 38 "lib/sj-lib-common/string.sj"
                sjt_functionParam14 = newcount;
#line 18
                sjt_parent14 = item;
#line 37
                sjt_functionParam16 = i;
#line 37
                sjf_string_getat(sjt_parent14, sjt_functionParam16, &sjt_functionParam15);
#line 37
                sjf_array_char_initat(sjt_parent13, sjt_functionParam14, sjt_functionParam15);
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
        bool sjt_capture8;
        int32_t sjt_capture9;
        sjs_array_char* sjt_parent15 = 0;

#line 35 "lib/sj-lib-common/array.sj"
        sjt_parent15 = &_parent->data;
#line 35
        sjf_array_char_gettotalcount(sjt_parent15, &sjt_capture9);
        if (((_parent->offset + _parent->count) + item->count) < sjt_capture9) {
            int32_t sjt_capture10;
            sjs_array_char* sjt_parent16 = 0;

#line 29 "lib/sj-lib-common/array.sj"
            sjt_parent16 = &_parent->data;
#line 29
            sjf_array_char_getcount(sjt_parent16, &sjt_capture10);
#line 24 "lib/sj-lib-common/string.sj"
            sjt_capture8 = ((_parent->offset + _parent->count) == sjt_capture10);
        } else {
#line 24 "lib/sj-lib-common/string.sj"
            sjt_capture8 = false;
        }

        if (sjt_capture8) {
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
                int32_t sjt_functionParam17;
                char sjt_functionParam18;
                int32_t sjt_functionParam19;
                sjs_array_char* sjt_parent17 = 0;
                sjs_string* sjt_parent18 = 0;

#line 52 "lib/sj-lib-common/array.sj"
                sjt_parent17 = &_parent->data;
#line 28 "lib/sj-lib-common/string.sj"
                sjt_functionParam17 = newcount;
#line 18
                sjt_parent18 = item;
#line 27
                sjt_functionParam19 = i;
#line 27
                sjf_string_getat(sjt_parent18, sjt_functionParam19, &sjt_functionParam18);
#line 27
                sjf_array_char_initat(sjt_parent17, sjt_functionParam17, sjt_functionParam18);
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
            int32_t sjt_functionParam20;
            int32_t sjt_functionParam21;
            int32_t sjt_functionParam22;
            sjs_array_char* sjt_parent19 = 0;
            sjs_array_char* sjt_parent20 = 0;

#line 168 "lib/sj-lib-common/array.sj"
            sjt_parent19 = &_parent->data;
#line 34 "lib/sj-lib-common/string.sj"
            sjt_functionParam20 = _parent->offset;
#line 34
            sjt_functionParam21 = _parent->count;
#line 34
            sjt_functionParam22 = ((((_parent->count + item->count) - 1) / 256) + 1) * 256;
#line 34
            sjf_array_char_clone(sjt_parent19, sjt_functionParam20, sjt_functionParam21, sjt_functionParam22, &newdata);
#line 29 "lib/sj-lib-common/array.sj"
            sjt_parent20 = &newdata;
#line 29
            sjf_array_char_getcount(sjt_parent20, &newcount);
#line 37 "lib/sj-lib-common/string.sj"
            sjt_forStart4 = 0;
#line 37
            sjt_forEnd4 = item->count;
#line 37
            i = sjt_forStart4;
            while (i < sjt_forEnd4) {
                int32_t sjt_functionParam23;
                char sjt_functionParam24;
                int32_t sjt_functionParam25;
                sjs_array_char* sjt_parent21 = 0;
                sjs_string* sjt_parent22 = 0;

#line 52 "lib/sj-lib-common/array.sj"
                sjt_parent21 = &newdata;
#line 38 "lib/sj-lib-common/string.sj"
                sjt_functionParam23 = newcount;
#line 18
                sjt_parent22 = item;
#line 37
                sjt_functionParam25 = i;
#line 37
                sjf_string_getat(sjt_parent22, sjt_functionParam25, &sjt_functionParam24);
#line 37
                sjf_array_char_initat(sjt_parent21, sjt_functionParam23, sjt_functionParam24);
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
    int32_t sjt_functionParam9;
    sjs_array_char* sjt_parent9 = 0;

#line 41 "lib/sj-lib-common/array.sj"
    sjt_parent9 = &_parent->data;
#line 64 "lib/sj-lib-common/string.sj"
    sjt_functionParam9 = _parent->offset + index;
#line 64
    sjf_array_char_getat(sjt_parent9, sjt_functionParam9, _return);
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
        int32_t sjt_capture2;
        sjs_array_char* sjt_parent1 = 0;
        sjs_array_char* sjt_parent2 = 0;

#line 35 "lib/sj-lib-common/array.sj"
        sjt_parent1 = &_parent->data;
#line 35
        sjf_array_char_gettotalcount(sjt_parent1, &sjt_capture1);
#line 29
        sjt_parent2 = &_parent->data;
#line 29
        sjf_array_char_getcount(sjt_parent2, &sjt_capture2);
        if ((((_parent->offset + _parent->count) + 1) > sjt_capture1) || ((_parent->offset + _parent->count) != sjt_capture2)) {
            int32_t sjt_functionParam1;
            int32_t sjt_functionParam2;
            int32_t sjt_functionParam3;
            sjs_array_char* sjt_parent3 = 0;

#line 168 "lib/sj-lib-common/array.sj"
            sjt_parent3 = &_parent->data;
#line 135 "lib/sj-lib-common/string.sj"
            sjt_functionParam1 = _parent->offset;
#line 135
            sjt_functionParam2 = _parent->count;
#line 135
            sjt_functionParam3 = _parent->count + 1;
#line 135
            sjf_array_char_clone(sjt_parent3, sjt_functionParam1, sjt_functionParam2, sjt_functionParam3, &sjt_funcold1);
#line 135
            if (_parent->data._refCount == 1) { sjf_array_char_destroy(&_parent->data); }
;
#line 168 "lib/sj-lib-common/array.sj"
            sjf_array_char_copy(&_parent->data, &sjt_funcold1);
#line 136 "lib/sj-lib-common/string.sj"
            _parent->offset = 0;
        }

#line 139 "lib/sj-lib-common/string.sj"
        ((sjs_array*)_parent->data.v)->data[_parent->offset + _parent->count] = 0;
#line 141
        _parent->_isnullterminated = true;
    }

    if (sjt_funcold1._refCount == 1) { sjf_array_char_destroy(&sjt_funcold1); }
;
}

void sjf_string_touppercase(sjs_string* _parent, sjs_string* _return) {
    sjs_array_char a = { -1 };
    int32_t i;
    int32_t sjt_forEnd5;
    int32_t sjt_forStart5;
    void* v;

#line 120 "lib/sj-lib-common/string.sj"
    v = 0;
#line 122
    sjs_array* arr = createarray(1, ((_parent->count - 1) / 256 + 1) * 256);
#line 123
    v = arr;
#line 123
    a._refCount = 1;
#line 125
    a.v = v;
#line 125
    sjf_array_char(&a);
#line 126
    sjt_forStart5 = 0;
#line 126
    sjt_forEnd5 = _parent->count;
#line 126
    i = sjt_forStart5;
    while (i < sjt_forEnd5) {
        int32_t sjt_functionParam26;
        char sjt_functionParam27;
        char sjt_functionParam28;
        int32_t sjt_functionParam29;
        sjs_array_char* sjt_parent27 = 0;
        sjs_array_char* sjt_parent28 = 0;

#line 52 "lib/sj-lib-common/array.sj"
        sjt_parent27 = &a;
#line 126 "lib/sj-lib-common/string.sj"
        sjt_functionParam26 = i;
#line 41 "lib/sj-lib-common/array.sj"
        sjt_parent28 = &_parent->data;
#line 126 "lib/sj-lib-common/string.sj"
        sjt_functionParam29 = i;
#line 126
        sjf_array_char_getat(sjt_parent28, sjt_functionParam29, &sjt_functionParam28);
#line 126
        sjf_char_touppercase(sjt_functionParam28, &sjt_functionParam27);
#line 126
        sjf_array_char_initat(sjt_parent27, sjt_functionParam26, sjt_functionParam27);
#line 126
        i++;
    }

#line 126
    _return->_refCount = 1;
#line 13
    _return->offset = 0;
#line 129
    _return->count = _parent->count;
#line 129
    _return->data._refCount = 1;
#line 129
    sjf_array_char_copy(&_return->data, &a);
#line 16
    _return->_isnullterminated = false;
#line 16
    sjf_string(_return);

    if (a._refCount == 1) { sjf_array_char_destroy(&a); }
;
}

void sjf_string_touppercase_heap(sjs_string* _parent, sjs_string** _return) {
    sjs_array_char a = { -1 };
    int32_t i;
    int32_t sjt_forEnd6;
    int32_t sjt_forStart6;
    void* v;

#line 120 "lib/sj-lib-common/string.sj"
    v = 0;
#line 122
    sjs_array* arr = createarray(1, ((_parent->count - 1) / 256 + 1) * 256);
#line 123
    v = arr;
#line 123
    a._refCount = 1;
#line 125
    a.v = v;
#line 125
    sjf_array_char(&a);
#line 126
    sjt_forStart6 = 0;
#line 126
    sjt_forEnd6 = _parent->count;
#line 126
    i = sjt_forStart6;
    while (i < sjt_forEnd6) {
        int32_t sjt_functionParam30;
        char sjt_functionParam31;
        char sjt_functionParam32;
        int32_t sjt_functionParam33;
        sjs_array_char* sjt_parent29 = 0;
        sjs_array_char* sjt_parent30 = 0;

#line 52 "lib/sj-lib-common/array.sj"
        sjt_parent29 = &a;
#line 126 "lib/sj-lib-common/string.sj"
        sjt_functionParam30 = i;
#line 41 "lib/sj-lib-common/array.sj"
        sjt_parent30 = &_parent->data;
#line 126 "lib/sj-lib-common/string.sj"
        sjt_functionParam33 = i;
#line 126
        sjf_array_char_getat(sjt_parent30, sjt_functionParam33, &sjt_functionParam32);
#line 126
        sjf_char_touppercase(sjt_functionParam32, &sjt_functionParam31);
#line 126
        sjf_array_char_initat(sjt_parent29, sjt_functionParam30, sjt_functionParam31);
#line 126
        i++;
    }

#line 126
    (*_return) = (sjs_string*)malloc(sizeof(sjs_string));
#line 126
    (*_return)->_refCount = 1;
#line 13
    (*_return)->offset = 0;
#line 129
    (*_return)->count = _parent->count;
#line 129
    (*_return)->data._refCount = 1;
#line 129
    sjf_array_char_copy(&(*_return)->data, &a);
#line 16
    (*_return)->_isnullterminated = false;
#line 16
    sjf_string_heap((*_return));

    if (a._refCount == 1) { sjf_array_char_destroy(&a); }
;
}

void sjf_type_asstring(int32_t t, sjs_string* _return) {
    switch (t) {
        case 8:
        _return->_refCount = 1;
        _return->offset = 0;
        _return->count = 4;
        _return->data._refCount = 1;
        _return->data.v = &sjg_string13;
        sjf_array_char(&_return->data);
#line 16 "lib/sj-lib-common/string.sj"
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 30:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 14;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string14;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 9:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 4;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string15;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 6:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 3;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string16;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 7:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 3;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string17;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 1:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 3;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string18;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 2:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 3;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string19;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 12:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 8;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string20;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 5:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 3;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string21;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 13:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 0;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string7;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 23:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 10;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string22;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 26:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 5;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string23;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 35:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 5;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string24;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 25:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 8;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string25;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 24:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 13;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string26;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 34:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 6;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string27;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 36:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 16;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string28;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 27:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 5;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string29;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 46:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 8;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string30;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 31:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 9;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string31;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 14:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 6;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string32;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 15:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 17;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string33;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 18:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 17;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string34;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 19:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 19;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string35;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 40:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 5;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string24;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 47:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 7;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string36;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 48:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 6;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string37;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 41:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 7;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string38;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 42:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 6;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string37;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 44:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 7;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string39;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 45:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 6;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string37;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 20:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 3;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string40;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 29:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 6;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string41;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 43:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 5;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string5;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 28:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 4;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string3;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 32:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 17;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string42;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 21:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 6;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string43;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 37:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 3;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string44;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 38:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 5;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string24;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 22:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 13;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string45;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 33:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 11;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string46;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 39:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 13;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string47;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 16:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 9;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string48;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 17:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 12;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string49;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 11:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 4;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string50;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 3:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 3;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string51;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 4:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 3;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string52;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        case 10:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 4;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string53;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
        default:
#line 16
        _return->_refCount = 1;
#line 16
        _return->offset = 0;
#line 16
        _return->count = 0;
#line 16
        _return->data._refCount = 1;
#line 16
        _return->data.v = &sjg_string7;
#line 16
        sjf_array_char(&_return->data);
#line 16
        _return->_isnullterminated = false;
#line 16
        sjf_string(_return);
#line 16
        break;
#line 16
    }
}

void sjf_type_asstring_heap(int32_t t, sjs_string** _return) {
    (*_return) = (sjs_string*)malloc(sizeof(sjs_string));
    (*_return)->_refCount = 1;
#line 2 "lib/sj-lib-common/type.sj"
    (*_return)->offset = 0;
#line 2
    (*_return)->count = 0;
#line 2
    (*_return)->data._refCount = 1;
#line 2
    (*_return)->data.v = &sjg_string7;
#line 2
    sjf_array_char(&(*_return)->data);
#line 16 "lib/sj-lib-common/string.sj"
    (*_return)->_isnullterminated = false;
#line 16
    sjf_string_heap((*_return));
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

int main(int argc, char** argv) {
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
#line 11 "log1.sj"
    (&g_log)->minlevel = g_loglevel_info;
#line 11
    g_c._refCount = 1;
#line 11
    sjf_class(&g_c);
#line 2
    sjt_parent42 = &g_c;
#line 2
    sjf_class_dothing1(sjt_parent42);
    main_destroy();
    return 0;
}

void main_destroy() {

    if (g_c._refCount == 1) { sjf_class_destroy(&g_c); }
;
    if (g_log._refCount == 1) { sjf_log_destroy(&g_log); }
;
    if (g_log_excludeall._refCount == 1) { sjf_hash_type_bool_destroy(&g_log_excludeall); }
;
    if (g_log_includeall._refCount == 1) { sjf_hash_type_bool_destroy(&g_log_includeall); }
;
    if (sjt_value1._refCount == 1) { sjf_hash_type_bool_destroy(&sjt_value1); }
;
}
