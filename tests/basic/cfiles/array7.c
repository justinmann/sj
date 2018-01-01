#include <lib/common/common.h>

const char* sjg_string1 = ", ";
const char* sjg_string2 = "";
const char* sjg_string3 = "c";

#define sjs_hash_type_bool_typeId 15
#define sjs_log_typeId 20
#define sjs_class_typeId 21
#define sjs_array_class_typeId 22
#define sjs_array_char_typeId 33
#define sjs_string_typeId 31
#define cb_class_class_i32_typeId 44
#define cb_class_class_i32_heap_typeId 44

typedef struct td_sjs_hash_type_bool sjs_hash_type_bool;
typedef struct td_sjs_log sjs_log;
typedef struct td_sjs_class sjs_class;
typedef struct td_sjs_array_class sjs_array_class;
typedef struct td_sjs_array_char sjs_array_char;
typedef struct td_sjs_string sjs_string;
typedef struct td_cb_class_class_i32 cb_class_class_i32;
typedef struct td_cb_class_class_i32_heap cb_class_class_i32_heap;

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

struct td_sjs_class {
    int _refCount;
    int32_t x;
};

struct td_sjs_array_class {
    int _refCount;
    int32_t datasize;
    void* data;
    bool isglobal;
    int32_t count;
};

struct td_sjs_array_char {
    int _refCount;
    int32_t datasize;
    void* data;
    bool isglobal;
    int32_t count;
};

struct td_sjs_string {
    int _refCount;
    int32_t count;
    sjs_array_char data;
    bool _isnullterminated;
};

struct td_cb_class_class_i32 {
    sjs_object* _parent;
    void (*_cb)(sjs_object* _parent, sjs_class*, sjs_class*, int32_t* _return);
};

struct td_cb_class_class_i32_heap {
    cb_class_class_i32 inner;
    void (*_destroy)(sjs_object*);
};

#ifndef type_bool_hash_typedef
#define type_bool_hash_typedef
KHASH_INIT_TYPEDEF(type_bool_hash_type, int32_t, bool)
#endif
#ifndef type_bool_hash_typedef
#define type_bool_hash_typedef
KHASH_INIT_TYPEDEF(type_bool_hash_type, int32_t, bool)
#endif
int32_t g_loglevel_debug;
int32_t g_loglevel_error;
int32_t g_loglevel_fatal;
int32_t g_loglevel_info;
int32_t g_loglevel_trace;
int32_t g_loglevel_warn;

sjs_array_class g_a = { -1 };
int32_t g_clocks_per_sec;
void* g_emptystringdata;
float g_f32_pi;
int32_t g_i32_maxvalue;
int32_t g_i32_minvalue;
sjs_log g_log = { -1 };
sjs_hash_type_bool g_log_excludeall = { -1 };
sjs_hash_type_bool g_log_includeall = { -1 };
uint32_t g_u32_maxvalue;
int32_t result1;
sjs_class sjt_call1 = { -1 };
sjs_string sjt_call11 = { -1 };
sjs_class sjt_call2 = { -1 };
sjs_string sjt_call20 = { -1 };
sjs_string sjt_call22 = { -1 };
sjs_string sjt_call23 = { -1 };
sjs_string sjt_call27 = { -1 };
sjs_string sjt_call28 = { -1 };
sjs_class sjt_call3 = { -1 };
sjs_class sjt_call4 = { -1 };
sjs_class sjt_call5 = { -1 };
int32_t sjt_functionParam1;
sjs_class* sjt_functionParam10 = 0;
sjs_class* sjt_functionParam2 = 0;
int32_t sjt_functionParam3;
sjs_string* sjt_functionParam35 = 0;
sjs_class* sjt_functionParam4 = 0;
int32_t sjt_functionParam5;
sjs_string* sjt_functionParam57 = 0;
sjs_class* sjt_functionParam6 = 0;
sjs_string* sjt_functionParam64 = 0;
sjs_string* sjt_functionParam65 = 0;
int32_t sjt_functionParam7;
sjs_class* sjt_functionParam8 = 0;
cb_class_class_i32 sjt_functionParam88;
int32_t sjt_functionParam9;
sjs_string* sjt_functionParam91 = 0;
sjs_string* sjt_functionParam92 = 0;
sjs_array_class* sjt_parent1 = 0;
sjs_array_class* sjt_parent10 = 0;
sjs_array_class* sjt_parent2 = 0;
sjs_array_class* sjt_parent29 = 0;
sjs_array_class* sjt_parent3 = 0;
sjs_array_class* sjt_parent30 = 0;
sjs_array_class* sjt_parent31 = 0;
sjs_array_class* sjt_parent32 = 0;
sjs_array_class* sjt_parent33 = 0;
sjs_array_class* sjt_parent4 = 0;
sjs_array_class* sjt_parent5 = 0;
sjs_hash_type_bool sjt_value1 = { -1 };

void sjf_array_char(sjs_array_char* _this);
void sjf_array_char_copy(sjs_array_char* _this, sjs_array_char* _from);
void sjf_array_char_destroy(sjs_array_char* _this);
void sjf_array_char_getat(sjs_array_char* _parent, int32_t index, char* _return);
void sjf_array_char_grow(sjs_array_char* _parent, int32_t newsize, sjs_array_char* _return);
void sjf_array_char_grow_heap(sjs_array_char* _parent, int32_t newsize, sjs_array_char** _return);
void sjf_array_char_heap(sjs_array_char* _this);
void sjf_array_char_initat(sjs_array_char* _parent, int32_t index, char item);
void sjf_array_class(sjs_array_class* _this);
void sjf_array_class__quicksort(sjs_array_class* _parent, int32_t left, int32_t right);
void sjf_array_class__quicksortcallback(sjs_array_class* _parent, int32_t left, int32_t right, cb_class_class_i32 cb);
void sjf_array_class_asstring(sjs_array_class* _parent, sjs_string* sep, sjs_string* _return);
void sjf_array_class_asstring_heap(sjs_array_class* _parent, sjs_string* sep, sjs_string** _return);
void sjf_array_class_copy(sjs_array_class* _this, sjs_array_class* _from);
void sjf_array_class_destroy(sjs_array_class* _this);
void sjf_array_class_getat(sjs_array_class* _parent, int32_t index, sjs_class* _return);
void sjf_array_class_getat_heap(sjs_array_class* _parent, int32_t index, sjs_class** _return);
void sjf_array_class_heap(sjs_array_class* _this);
void sjf_array_class_initat(sjs_array_class* _parent, int32_t index, sjs_class* item);
void sjf_array_class_reverse(sjs_array_class* _parent);
void sjf_array_class_setat(sjs_array_class* _parent, int32_t index, sjs_class* item);
void sjf_array_class_sort(sjs_array_class* _parent);
void sjf_array_class_sortcb(sjs_array_class* _parent, cb_class_class_i32 cb);
void sjf_class(sjs_class* _this);
void sjf_class_asstring(sjs_class* _parent, sjs_string* _return);
void sjf_class_asstring_heap(sjs_class* _parent, sjs_string** _return);
void sjf_class_compare(sjs_class* l, sjs_class* r, int32_t* _return);
void sjf_class_compare_callback(void * _parent, sjs_class* l, sjs_class* r, int32_t* _return);
void sjf_class_copy(sjs_class* _this, sjs_class* _from);
void sjf_class_destroy(sjs_class* _this);
void sjf_class_heap(sjs_class* _this);
void sjf_class_isgreater(sjs_class* _parent, sjs_class* c, bool* _return);
void sjf_class_isless(sjs_class* _parent, sjs_class* c, bool* _return);
void sjf_console_writeline(sjs_string* data);
void sjf_hash_type_bool(sjs_hash_type_bool* _this);
void sjf_hash_type_bool__weakptrremovekey(sjs_hash_type_bool* _parent, int32_t key);
void sjf_hash_type_bool__weakptrremovevalue(sjs_hash_type_bool* _parent, bool val);
void sjf_hash_type_bool_copy(sjs_hash_type_bool* _this, sjs_hash_type_bool* _from);
void sjf_hash_type_bool_destroy(sjs_hash_type_bool* _this);
void sjf_hash_type_bool_heap(sjs_hash_type_bool* _this);
void sjf_i32_asstring(int32_t val, int32_t base, sjs_string* _return);
void sjf_i32_asstring_heap(int32_t val, int32_t base, sjs_string** _return);
void sjf_i32_compare(int32_t l, int32_t r, int32_t* _return);
void sjf_log(sjs_log* _this);
void sjf_log_copy(sjs_log* _this, sjs_log* _from);
void sjf_log_destroy(sjs_log* _this);
void sjf_log_heap(sjs_log* _this);
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
#include <lib/common/common.c>
void sjf_array_char(sjs_array_char* _this) {
#line 309 "lib/common/array.sj"
    if (_this->datasize < 0) {
#line 310
        halt("size is less than zero");
#line 311
    }
#line 313
    if (!_this->data) {
#line 314
        _this->data = (int*)malloc(_this->datasize * sizeof(char) + sizeof(int)) + 1;
#line 315
        int* refcount = (int*)_this->data - 1;
#line 316
        *refcount = 1;
#line 317
        if (!_this->data) {
#line 318
            halt("grow: out of memory\n");
#line 319
        }
#line 320
    }
}

void sjf_array_char_copy(sjs_array_char* _this, sjs_array_char* _from) {
#line 1 "lib/common/array.sj"
    _this->datasize = _from->datasize;
#line 1
    _this->data = _from->data;
#line 1
    _this->isglobal = _from->isglobal;
#line 1
    _this->count = _from->count;
#line 325
    _this->data = _from->data;
#line 326
    if (!_this->isglobal && _this->data) {
#line 327
        int* refcount = (int*)_this->data - 1;
#line 328
        *refcount = *refcount + 1;
#line 329
    }
}

void sjf_array_char_destroy(sjs_array_char* _this) {
#line 333 "lib/common/array.sj"
    if (!_this->isglobal && _this->data) {
#line 334
        int* refcount = (int*)_this->data - 1;
#line 335
        *refcount = *refcount - 1;
#line 336
        if (*refcount == 0) {
#line 337
            #if !true && !false
#line 338
            char* p = (char*)_this->data;
#line 339
            for (int i = 0; i < _this->count; i++) {
#line 340
                ;
#line 341
            }
#line 342
            #endif
#line 343
            free(refcount);
#line 344
        }
#line 345
    }
}

void sjf_array_char_getat(sjs_array_char* _parent, int32_t index, char* _return) {
#line 9 "lib/common/array.sj"
    if (index >= _parent->count || index < 0) {
#line 10
        halt("getAt: out of bounds\n");
#line 11
    }
#line 13
    char* p = (char*)_parent->data;
#line 14
    #line 8 "lib/common/array.sj"
(*_return) = p[index];
return;;       
}

void sjf_array_char_grow(sjs_array_char* _parent, int32_t newsize, sjs_array_char* _return) {
    void* newdata;

#line 135 "lib/common/array.sj"
    newdata = 0;
#line 137
    if (_parent->datasize != newsize) {
#line 138
        if (newsize < _parent->datasize) {
#line 139
            halt("grow: new size smaller than old _parent->datasize %d:%d\n", newsize, _parent->datasize);
#line 140
        }
#line 142
        newdata = (int*)(malloc(sizeof(int) + newsize * sizeof(char))) + 1;
#line 143
        int* refcount = (int*)newdata - 1;
#line 144
        *refcount = 1;
#line 146
        if (!_parent->data) {
#line 147
            halt("grow: out of memory\n");
#line 148
        }
#line 150
        char* p = (char*)_parent->data;
#line 151
        char* newp = (char*)newdata;
#line 153
        int count = _parent->count;
#line 155
        #if true
#line 156
        memcpy(newp, p, sizeof(char) * count);
#line 157
        #else
#line 158
        for (int i = 0; i < count; i++) {
#line 159
            #line 136 "lib/common/array.sj"
newp[i] = p[i];
;
#line 160
        }
#line 161
        #endif
#line 162
    }
#line 162
    _return->_refCount = 1;
#line 134
    _return->datasize = newsize;
#line 164
    _return->data = newdata;
#line 4
    _return->isglobal = false;
#line 164
    _return->count = _parent->count;
#line 164
    sjf_array_char(_return);
}

void sjf_array_char_grow_heap(sjs_array_char* _parent, int32_t newsize, sjs_array_char** _return) {
    void* newdata;

#line 135 "lib/common/array.sj"
    newdata = 0;
#line 137
    if (_parent->datasize != newsize) {
#line 138
        if (newsize < _parent->datasize) {
#line 139
            halt("grow: new size smaller than old _parent->datasize %d:%d\n", newsize, _parent->datasize);
#line 140
        }
#line 142
        newdata = (int*)(malloc(sizeof(int) + newsize * sizeof(char))) + 1;
#line 143
        int* refcount = (int*)newdata - 1;
#line 144
        *refcount = 1;
#line 146
        if (!_parent->data) {
#line 147
            halt("grow: out of memory\n");
#line 148
        }
#line 150
        char* p = (char*)_parent->data;
#line 151
        char* newp = (char*)newdata;
#line 153
        int count = _parent->count;
#line 155
        #if true
#line 156
        memcpy(newp, p, sizeof(char) * count);
#line 157
        #else
#line 158
        for (int i = 0; i < count; i++) {
#line 159
            #line 136 "lib/common/array.sj"
newp[i] = p[i];
;
#line 160
        }
#line 161
        #endif
#line 162
    }
#line 162
    (*_return) = (sjs_array_char*)malloc(sizeof(sjs_array_char));
#line 162
    (*_return)->_refCount = 1;
#line 134
    (*_return)->datasize = newsize;
#line 164
    (*_return)->data = newdata;
#line 4
    (*_return)->isglobal = false;
#line 164
    (*_return)->count = _parent->count;
#line 164
    sjf_array_char_heap((*_return));
}

void sjf_array_char_heap(sjs_array_char* _this) {
#line 309 "lib/common/array.sj"
    if (_this->datasize < 0) {
#line 310
        halt("size is less than zero");
#line 311
    }
#line 313
    if (!_this->data) {
#line 314
        _this->data = (int*)malloc(_this->datasize * sizeof(char) + sizeof(int)) + 1;
#line 315
        int* refcount = (int*)_this->data - 1;
#line 316
        *refcount = 1;
#line 317
        if (!_this->data) {
#line 318
            halt("grow: out of memory\n");
#line 319
        }
#line 320
    }
}

void sjf_array_char_initat(sjs_array_char* _parent, int32_t index, char item) {
#line 36 "lib/common/array.sj"
    if (index != _parent->count) {
#line 37
        halt("initAt: can only initialize last element\n");     
#line 38
    }
#line 39
    if (index >= _parent->datasize || index < 0) {
#line 40
        halt("initAt: out of bounds %d:%d\n", index, _parent->datasize);
#line 41
    }
#line 43
    char* p = (char*)_parent->data;
#line 44
    #line 34 "lib/common/array.sj"
p[index] = item;
;
#line 45
    _parent->count = index + 1;
}

void sjf_array_class(sjs_array_class* _this) {
#line 309 "lib/common/array.sj"
    if (_this->datasize < 0) {
#line 310
        halt("size is less than zero");
#line 311
    }
#line 313
    if (!_this->data) {
#line 314
        _this->data = (int*)malloc(_this->datasize * sizeof(sjs_class) + sizeof(int)) + 1;
#line 315
        int* refcount = (int*)_this->data - 1;
#line 316
        *refcount = 1;
#line 317
        if (!_this->data) {
#line 318
            halt("grow: out of memory\n");
#line 319
        }
#line 320
    }
}

void sjf_array_class__quicksort(sjs_array_class* _parent, int32_t left, int32_t right) {
    int32_t i;
    int32_t j;
    sjs_class pivot = { -1 };
    int32_t sjt_functionParam11;
    bool sjt_while1;

#line 167 "lib/common/array.sj"
    i = left;
#line 167
    j = right;
#line 171
    sjt_functionParam11 = (left + right) / 2;
#line 171
    sjf_array_class_getat(_parent, sjt_functionParam11, &pivot);
#line 172
    sjt_while1 = i <= j;
    while (sjt_while1) {
        sjs_class sjt_call10 = { -1 };
        sjs_class sjt_call6 = { -1 };
        sjs_class sjt_call8 = { -1 };
        int32_t sjt_functionParam12;
        sjs_class* sjt_functionParam13 = 0;
        int32_t sjt_functionParam16;
        sjs_class* sjt_functionParam17 = 0;
        sjs_class* sjt_parent6 = 0;
        sjs_class* sjt_parent8 = 0;
        bool sjt_while2;
        bool sjt_while3;
        sjs_class tmp = { -1 };

#line 173 "lib/common/array.sj"
        sjt_functionParam12 = i;
#line 173
        sjf_array_class_getat(_parent, sjt_functionParam12, &sjt_call6);
#line 173
        sjt_parent6 = &sjt_call6;
#line 173
        sjt_functionParam13 = &pivot;
#line 173
        sjf_class_isless(sjt_parent6, sjt_functionParam13, &sjt_while2);
        while (sjt_while2) {
            sjs_class sjt_call7 = { -1 };
            int32_t sjt_functionParam14;
            sjs_class* sjt_functionParam15 = 0;
            sjs_class* sjt_parent7 = 0;

#line 174 "lib/common/array.sj"
            i = i + 1;
#line 173
            sjt_functionParam14 = i;
#line 173
            sjf_array_class_getat(_parent, sjt_functionParam14, &sjt_call7);
#line 173
            sjt_parent7 = &sjt_call7;
#line 173
            sjt_functionParam15 = &pivot;
#line 173
            sjf_class_isless(sjt_parent7, sjt_functionParam15, &sjt_while2);

            if (sjt_call7._refCount == 1) { sjf_class_destroy(&sjt_call7); }
;
        }

#line 177
        sjt_functionParam16 = j;
#line 177
        sjf_array_class_getat(_parent, sjt_functionParam16, &sjt_call8);
#line 177
        sjt_parent8 = &sjt_call8;
#line 177
        sjt_functionParam17 = &pivot;
#line 177
        sjf_class_isgreater(sjt_parent8, sjt_functionParam17, &sjt_while3);
        while (sjt_while3) {
            sjs_class sjt_call9 = { -1 };
            int32_t sjt_functionParam18;
            sjs_class* sjt_functionParam19 = 0;
            sjs_class* sjt_parent9 = 0;

#line 178 "lib/common/array.sj"
            j = j - 1;
#line 177
            sjt_functionParam18 = j;
#line 177
            sjf_array_class_getat(_parent, sjt_functionParam18, &sjt_call9);
#line 177
            sjt_parent9 = &sjt_call9;
#line 177
            sjt_functionParam19 = &pivot;
#line 177
            sjf_class_isgreater(sjt_parent9, sjt_functionParam19, &sjt_while3);

            if (sjt_call9._refCount == 1) { sjf_class_destroy(&sjt_call9); }
;
        }

        if (i <= j) {
            int32_t sjt_functionParam20;
            int32_t sjt_functionParam21;
            sjs_class* sjt_functionParam22 = 0;
            int32_t sjt_functionParam23;
            int32_t sjt_functionParam24;
            sjs_class* sjt_functionParam25 = 0;

#line 182 "lib/common/array.sj"
            sjt_functionParam20 = i;
#line 182
            sjf_array_class_getat(_parent, sjt_functionParam20, &tmp);
#line 183
            sjt_functionParam21 = i;
#line 183
            sjt_functionParam23 = j;
#line 183
            sjf_array_class_getat(_parent, sjt_functionParam23, &sjt_call10);
#line 183
            sjt_functionParam22 = &sjt_call10;
#line 183
            sjf_array_class_setat(_parent, sjt_functionParam21, sjt_functionParam22);
#line 184
            sjt_functionParam24 = j;
#line 184
            sjt_functionParam25 = &tmp;
#line 184
            sjf_array_class_setat(_parent, sjt_functionParam24, sjt_functionParam25);
#line 185
            i = i + 1;
#line 186
            j = j - 1;
        }

#line 172
        sjt_while1 = i <= j;

        if (sjt_call10._refCount == 1) { sjf_class_destroy(&sjt_call10); }
;
        if (sjt_call6._refCount == 1) { sjf_class_destroy(&sjt_call6); }
;
        if (sjt_call8._refCount == 1) { sjf_class_destroy(&sjt_call8); }
;
        if (tmp._refCount == 1) { sjf_class_destroy(&tmp); }
;
    }

    if (left < j) {
        int32_t sjt_functionParam26;
        int32_t sjt_functionParam27;

#line 167 "lib/common/array.sj"
        sjt_functionParam26 = left;
#line 191
        sjt_functionParam27 = j;
#line 191
        sjf_array_class__quicksort(_parent, sjt_functionParam26, sjt_functionParam27);
    }

    if (i < right) {
        int32_t sjt_functionParam28;
        int32_t sjt_functionParam29;

#line 194 "lib/common/array.sj"
        sjt_functionParam28 = i;
#line 167
        sjt_functionParam29 = right;
#line 167
        sjf_array_class__quicksort(_parent, sjt_functionParam28, sjt_functionParam29);
    }

    if (pivot._refCount == 1) { sjf_class_destroy(&pivot); }
;
}

void sjf_array_class__quicksortcallback(sjs_array_class* _parent, int32_t left, int32_t right, cb_class_class_i32 cb) {
    int32_t i;
    int32_t j;
    sjs_class pivot = { -1 };
    int32_t sjt_functionParam66;
    bool sjt_while4;

#line 198 "lib/common/array.sj"
    i = left;
#line 198
    j = right;
#line 202
    sjt_functionParam66 = (left + right) / 2;
#line 202
    sjf_array_class_getat(_parent, sjt_functionParam66, &pivot);
#line 203
    sjt_while4 = i <= j;
    while (sjt_while4) {
        bool shouldcontinue;
        sjs_class sjt_call26 = { -1 };
        bool sjt_while5;
        bool sjt_while6;
        sjs_class tmp = { -1 };

#line 204 "lib/common/array.sj"
        shouldcontinue = true;
        if (i < _parent->count) {
#line 205 "lib/common/array.sj"
            sjt_while5 = shouldcontinue;
        } else {
#line 205 "lib/common/array.sj"
            sjt_while5 = false;
        }

        while (sjt_while5) {
            sjs_class sjt_call24 = { -1 };
            int32_t sjt_capture1;
            sjs_class* sjt_functionParam67 = 0;
            int32_t sjt_functionParam68;
            sjs_class* sjt_functionParam69 = 0;

#line 206 "lib/common/array.sj"
            sjt_functionParam68 = i;
#line 206
            sjf_array_class_getat(_parent, sjt_functionParam68, &sjt_call24);
#line 206
            sjt_functionParam67 = &sjt_call24;
#line 206
            sjt_functionParam69 = &pivot;
#line 206
            cb._cb(cb._parent, sjt_functionParam67, sjt_functionParam69, &sjt_capture1);
#line 206
            shouldcontinue = sjt_capture1 < 0;
            if (shouldcontinue) {
#line 208 "lib/common/array.sj"
                i = i + 1;
            }

            if (i < _parent->count) {
#line 205 "lib/common/array.sj"
                sjt_while5 = shouldcontinue;
            } else {
#line 205 "lib/common/array.sj"
                sjt_while5 = false;
            }

            if (sjt_call24._refCount == 1) { sjf_class_destroy(&sjt_call24); }
;
        }

#line 212
        shouldcontinue = true;
        if (j >= 0) {
#line 213 "lib/common/array.sj"
            sjt_while6 = shouldcontinue;
        } else {
#line 213 "lib/common/array.sj"
            sjt_while6 = false;
        }

        while (sjt_while6) {
            sjs_class sjt_call25 = { -1 };
            int32_t sjt_capture2;
            sjs_class* sjt_functionParam70 = 0;
            int32_t sjt_functionParam71;
            sjs_class* sjt_functionParam72 = 0;

#line 214 "lib/common/array.sj"
            sjt_functionParam71 = j;
#line 214
            sjf_array_class_getat(_parent, sjt_functionParam71, &sjt_call25);
#line 214
            sjt_functionParam70 = &sjt_call25;
#line 214
            sjt_functionParam72 = &pivot;
#line 214
            cb._cb(cb._parent, sjt_functionParam70, sjt_functionParam72, &sjt_capture2);
#line 214
            shouldcontinue = sjt_capture2 > 0;
            if (shouldcontinue) {
#line 216 "lib/common/array.sj"
                j = j - 1;
            }

            if (j >= 0) {
#line 213 "lib/common/array.sj"
                sjt_while6 = shouldcontinue;
            } else {
#line 213 "lib/common/array.sj"
                sjt_while6 = false;
            }

            if (sjt_call25._refCount == 1) { sjf_class_destroy(&sjt_call25); }
;
        }

        if (i <= j) {
            int32_t sjt_functionParam73;
            int32_t sjt_functionParam74;
            sjs_class* sjt_functionParam75 = 0;
            int32_t sjt_functionParam76;
            int32_t sjt_functionParam77;
            sjs_class* sjt_functionParam78 = 0;

#line 221 "lib/common/array.sj"
            sjt_functionParam73 = i;
#line 221
            sjf_array_class_getat(_parent, sjt_functionParam73, &tmp);
#line 222
            sjt_functionParam74 = i;
#line 222
            sjt_functionParam76 = j;
#line 222
            sjf_array_class_getat(_parent, sjt_functionParam76, &sjt_call26);
#line 222
            sjt_functionParam75 = &sjt_call26;
#line 222
            sjf_array_class_setat(_parent, sjt_functionParam74, sjt_functionParam75);
#line 223
            sjt_functionParam77 = j;
#line 223
            sjt_functionParam78 = &tmp;
#line 223
            sjf_array_class_setat(_parent, sjt_functionParam77, sjt_functionParam78);
#line 224
            i = i + 1;
#line 225
            j = j - 1;
        }

#line 203
        sjt_while4 = i <= j;

        if (sjt_call26._refCount == 1) { sjf_class_destroy(&sjt_call26); }
;
        if (tmp._refCount == 1) { sjf_class_destroy(&tmp); }
;
    }

    if (left < j) {
        int32_t sjt_functionParam79;
        int32_t sjt_functionParam80;
        cb_class_class_i32 sjt_functionParam81;

#line 198 "lib/common/array.sj"
        sjt_functionParam79 = left;
#line 230
        sjt_functionParam80 = j;
#line 198
        sjt_functionParam81 = cb;
#line 198
        sjf_array_class__quicksortcallback(_parent, sjt_functionParam79, sjt_functionParam80, sjt_functionParam81);
    }

    if (i < right) {
        int32_t sjt_functionParam82;
        int32_t sjt_functionParam83;
        cb_class_class_i32 sjt_functionParam84;

#line 233 "lib/common/array.sj"
        sjt_functionParam82 = i;
#line 198
        sjt_functionParam83 = right;
#line 198
        sjt_functionParam84 = cb;
#line 198
        sjf_array_class__quicksortcallback(_parent, sjt_functionParam82, sjt_functionParam83, sjt_functionParam84);
    }

    if (pivot._refCount == 1) { sjf_class_destroy(&pivot); }
;
}

void sjf_array_class_asstring(sjs_array_class* _parent, sjs_string* sep, sjs_string* _return) {
    int32_t i;
    sjs_string result = { -1 };
    int32_t sjt_forEnd1;
    int32_t sjt_forStart1;

    result._refCount = 1;
#line 259 "lib/common/array.sj"
    result.count = 0;
#line 259
    result.data._refCount = 1;
#line 259
    result.data.datasize = 0;
#line 259
    result.data.data = (void*)sjg_string2;
#line 259
    result.data.isglobal = true;
#line 259
    result.data.count = 0;
#line 259
    sjf_array_char(&result.data);
#line 14 "lib/common/string.sj"
    result._isnullterminated = false;
#line 14
    sjf_string(&result);
#line 260 "lib/common/array.sj"
    sjt_forStart1 = 0;
#line 260
    sjt_forEnd1 = _parent->count;
#line 260
    i = sjt_forStart1;
    while (i < sjt_forEnd1) {
        sjs_string sjt_call12 = { -1 };
        sjs_class sjt_call17 = { -1 };
        sjs_string sjt_funcold2 = { -1 };
        sjs_string sjt_funcold3 = { -1 };
        sjs_string* sjt_functionParam46 = 0;
        int32_t sjt_functionParam53;
        sjs_string* sjt_parent22 = 0;
        sjs_class* sjt_parent25 = 0;

        if (i != 0) {
            sjs_string* sjt_functionParam45 = 0;
            sjs_string* sjt_parent21 = 0;

            sjt_funcold2._refCount = 1;
#line 16 "lib/common/string.sj"
            sjf_string_copy(&sjt_funcold2, &result);
#line 16
            sjt_parent21 = &result;
#line 258 "lib/common/array.sj"
            sjt_functionParam45 = sep;
#line 258
            sjf_string_add(sjt_parent21, sjt_functionParam45, &sjt_funcold2);
#line 258
            if (result._refCount == 1) { sjf_string_destroy(&result); }
;
#line 16 "lib/common/string.sj"
            sjf_string_copy(&result, &sjt_funcold2);
        }

        sjt_funcold3._refCount = 1;
#line 16 "lib/common/string.sj"
        sjf_string_copy(&sjt_funcold3, &result);
#line 16
        sjt_parent22 = &result;
#line 260 "lib/common/array.sj"
        sjt_functionParam53 = i;
#line 260
        sjf_array_class_getat(_parent, sjt_functionParam53, &sjt_call17);
#line 264
        sjt_parent25 = &sjt_call17;
#line 264
        sjf_class_asstring(sjt_parent25, &sjt_call12);
#line 264
        sjt_functionParam46 = &sjt_call12;
#line 264
        sjf_string_add(sjt_parent22, sjt_functionParam46, &sjt_funcold3);
#line 264
        if (result._refCount == 1) { sjf_string_destroy(&result); }
;
#line 16 "lib/common/string.sj"
        sjf_string_copy(&result, &sjt_funcold3);
#line 260 "lib/common/array.sj"
        i++;

        if (sjt_call12._refCount == 1) { sjf_string_destroy(&sjt_call12); }
;
        if (sjt_call17._refCount == 1) { sjf_class_destroy(&sjt_call17); }
;
        if (sjt_funcold2._refCount == 1) { sjf_string_destroy(&sjt_funcold2); }
;
        if (sjt_funcold3._refCount == 1) { sjf_string_destroy(&sjt_funcold3); }
;
    }

#line 260
    _return->_refCount = 1;
#line 258
    sjf_string_copy(_return, &result);

    if (result._refCount == 1) { sjf_string_destroy(&result); }
;
}

void sjf_array_class_asstring_heap(sjs_array_class* _parent, sjs_string* sep, sjs_string** _return) {
    int32_t i;
    sjs_string result = { -1 };
    int32_t sjt_forEnd4;
    int32_t sjt_forStart4;

    result._refCount = 1;
#line 259 "lib/common/array.sj"
    result.count = 0;
#line 259
    result.data._refCount = 1;
#line 259
    result.data.datasize = 0;
#line 259
    result.data.data = (void*)sjg_string2;
#line 259
    result.data.isglobal = true;
#line 259
    result.data.count = 0;
#line 259
    sjf_array_char(&result.data);
#line 14 "lib/common/string.sj"
    result._isnullterminated = false;
#line 14
    sjf_string(&result);
#line 260 "lib/common/array.sj"
    sjt_forStart4 = 0;
#line 260
    sjt_forEnd4 = _parent->count;
#line 260
    i = sjt_forStart4;
    while (i < sjt_forEnd4) {
        sjs_string sjt_call18 = { -1 };
        sjs_class sjt_call19 = { -1 };
        sjs_string sjt_funcold4 = { -1 };
        sjs_string sjt_funcold5 = { -1 };
        sjs_string* sjt_functionParam55 = 0;
        int32_t sjt_functionParam56;
        sjs_string* sjt_parent27 = 0;
        sjs_class* sjt_parent28 = 0;

        if (i != 0) {
            sjs_string* sjt_functionParam54 = 0;
            sjs_string* sjt_parent26 = 0;

            sjt_funcold4._refCount = 1;
#line 16 "lib/common/string.sj"
            sjf_string_copy(&sjt_funcold4, &result);
#line 16
            sjt_parent26 = &result;
#line 258 "lib/common/array.sj"
            sjt_functionParam54 = sep;
#line 258
            sjf_string_add(sjt_parent26, sjt_functionParam54, &sjt_funcold4);
#line 258
            if (result._refCount == 1) { sjf_string_destroy(&result); }
;
#line 16 "lib/common/string.sj"
            sjf_string_copy(&result, &sjt_funcold4);
        }

        sjt_funcold5._refCount = 1;
#line 16 "lib/common/string.sj"
        sjf_string_copy(&sjt_funcold5, &result);
#line 16
        sjt_parent27 = &result;
#line 260 "lib/common/array.sj"
        sjt_functionParam56 = i;
#line 260
        sjf_array_class_getat(_parent, sjt_functionParam56, &sjt_call19);
#line 264
        sjt_parent28 = &sjt_call19;
#line 264
        sjf_class_asstring(sjt_parent28, &sjt_call18);
#line 264
        sjt_functionParam55 = &sjt_call18;
#line 264
        sjf_string_add(sjt_parent27, sjt_functionParam55, &sjt_funcold5);
#line 264
        if (result._refCount == 1) { sjf_string_destroy(&result); }
;
#line 16 "lib/common/string.sj"
        sjf_string_copy(&result, &sjt_funcold5);
#line 260 "lib/common/array.sj"
        i++;

        if (sjt_call18._refCount == 1) { sjf_string_destroy(&sjt_call18); }
;
        if (sjt_call19._refCount == 1) { sjf_class_destroy(&sjt_call19); }
;
        if (sjt_funcold4._refCount == 1) { sjf_string_destroy(&sjt_funcold4); }
;
        if (sjt_funcold5._refCount == 1) { sjf_string_destroy(&sjt_funcold5); }
;
    }

#line 260
    (*_return) = (sjs_string*)malloc(sizeof(sjs_string));
#line 260
    (*_return)->_refCount = 1;
#line 258
    sjf_string_copy((*_return), &result);

    if (result._refCount == 1) { sjf_string_destroy(&result); }
;
}

void sjf_array_class_copy(sjs_array_class* _this, sjs_array_class* _from) {
#line 1 "lib/common/array.sj"
    _this->datasize = _from->datasize;
#line 1
    _this->data = _from->data;
#line 1
    _this->isglobal = _from->isglobal;
#line 1
    _this->count = _from->count;
#line 325
    _this->data = _from->data;
#line 326
    if (!_this->isglobal && _this->data) {
#line 327
        int* refcount = (int*)_this->data - 1;
#line 328
        *refcount = *refcount + 1;
#line 329
    }
}

void sjf_array_class_destroy(sjs_array_class* _this) {
#line 333 "lib/common/array.sj"
    if (!_this->isglobal && _this->data) {
#line 334
        int* refcount = (int*)_this->data - 1;
#line 335
        *refcount = *refcount - 1;
#line 336
        if (*refcount == 0) {
#line 337
            #if !false && !true
#line 338
            sjs_class* p = (sjs_class*)_this->data;
#line 339
            for (int i = 0; i < _this->count; i++) {
#line 340
                ;
#line 341
            }
#line 342
            #endif
#line 343
            free(refcount);
#line 344
        }
#line 345
    }
}

void sjf_array_class_getat(sjs_array_class* _parent, int32_t index, sjs_class* _return) {
#line 9 "lib/common/array.sj"
    if (index >= _parent->count || index < 0) {
#line 10
        halt("getAt: out of bounds\n");
#line 11
    }
#line 13
    sjs_class* p = (sjs_class*)_parent->data;
#line 14
    _return->_refCount = 1;
#line 8 "lib/common/array.sj"
sjf_class_copy(_return, &p[index]);
return;;       
}

void sjf_array_class_getat_heap(sjs_array_class* _parent, int32_t index, sjs_class** _return) {
#line 9 "lib/common/array.sj"
    if (index >= _parent->count || index < 0) {
#line 10
        halt("getAt: out of bounds\n");
#line 11
    }
#line 13
    sjs_class* p = (sjs_class*)_parent->data;
#line 14
    (*_return) = (sjs_class*)malloc(sizeof(sjs_class));
(*_return)->_refCount = 1;
#line 8 "lib/common/array.sj"
sjf_class_copy((*_return), &p[index]);
return;;       
}

void sjf_array_class_heap(sjs_array_class* _this) {
#line 309 "lib/common/array.sj"
    if (_this->datasize < 0) {
#line 310
        halt("size is less than zero");
#line 311
    }
#line 313
    if (!_this->data) {
#line 314
        _this->data = (int*)malloc(_this->datasize * sizeof(sjs_class) + sizeof(int)) + 1;
#line 315
        int* refcount = (int*)_this->data - 1;
#line 316
        *refcount = 1;
#line 317
        if (!_this->data) {
#line 318
            halt("grow: out of memory\n");
#line 319
        }
#line 320
    }
}

void sjf_array_class_initat(sjs_array_class* _parent, int32_t index, sjs_class* item) {
#line 36 "lib/common/array.sj"
    if (index != _parent->count) {
#line 37
        halt("initAt: can only initialize last element\n");     
#line 38
    }
#line 39
    if (index >= _parent->datasize || index < 0) {
#line 40
        halt("initAt: out of bounds %d:%d\n", index, _parent->datasize);
#line 41
    }
#line 43
    sjs_class* p = (sjs_class*)_parent->data;
#line 44
    p[index]._refCount = 1;
#line 34 "lib/common/array.sj"
sjf_class_copy(&p[index], item);
;
#line 45
    _parent->count = index + 1;
}

void sjf_array_class_reverse(sjs_array_class* _parent) {
    int32_t i;
    int32_t sjt_forEnd5;
    int32_t sjt_forStart5;

#line 250 "lib/common/array.sj"
    sjt_forStart5 = 0;
#line 250
    sjt_forEnd5 = _parent->count / 2;
#line 250
    i = sjt_forStart5;
    while (i < sjt_forEnd5) {
        int32_t j;
        sjs_class sjt_call21 = { -1 };
        int32_t sjt_functionParam58;
        int32_t sjt_functionParam59;
        sjs_class* sjt_functionParam60 = 0;
        int32_t sjt_functionParam61;
        int32_t sjt_functionParam62;
        sjs_class* sjt_functionParam63 = 0;
        sjs_class tmp = { -1 };

#line 251 "lib/common/array.sj"
        j = (_parent->count - i) - 1;
#line 250
        sjt_functionParam58 = i;
#line 250
        sjf_array_class_getat(_parent, sjt_functionParam58, &tmp);
#line 250
        sjt_functionParam59 = i;
#line 253
        sjt_functionParam61 = j;
#line 253
        sjf_array_class_getat(_parent, sjt_functionParam61, &sjt_call21);
#line 253
        sjt_functionParam60 = &sjt_call21;
#line 253
        sjf_array_class_setat(_parent, sjt_functionParam59, sjt_functionParam60);
#line 254
        sjt_functionParam62 = j;
#line 254
        sjt_functionParam63 = &tmp;
#line 254
        sjf_array_class_setat(_parent, sjt_functionParam62, sjt_functionParam63);
#line 250
        i++;

        if (sjt_call21._refCount == 1) { sjf_class_destroy(&sjt_call21); }
;
        if (tmp._refCount == 1) { sjf_class_destroy(&tmp); }
;
    }
}

void sjf_array_class_setat(sjs_array_class* _parent, int32_t index, sjs_class* item) {
#line 51 "lib/common/array.sj"
    if (index >= _parent->count || index < 0) {
#line 52
        halt("setAt: out of bounds %d:%d\n", index, _parent->count);
#line 53
    }
#line 55
    sjs_class* p = (sjs_class*)_parent->data;
#line 56
    ;
#line 57
    p[index]._refCount = 1;
#line 49 "lib/common/array.sj"
sjf_class_copy(&p[index], item);
;
}

void sjf_array_class_sort(sjs_array_class* _parent) {
    if (_parent->count > 1) {
        int32_t sjt_functionParam30;
        int32_t sjt_functionParam31;

#line 239 "lib/common/array.sj"
        sjt_functionParam30 = 0;
#line 239
        sjt_functionParam31 = _parent->count - 1;
#line 239
        sjf_array_class__quicksort(_parent, sjt_functionParam30, sjt_functionParam31);
    }
}

void sjf_array_class_sortcb(sjs_array_class* _parent, cb_class_class_i32 cb) {
    if (_parent->count > 1) {
        int32_t sjt_functionParam85;
        int32_t sjt_functionParam86;
        cb_class_class_i32 sjt_functionParam87;

#line 245 "lib/common/array.sj"
        sjt_functionParam85 = 0;
#line 245
        sjt_functionParam86 = _parent->count - 1;
#line 243
        sjt_functionParam87 = cb;
#line 243
        sjf_array_class__quicksortcallback(_parent, sjt_functionParam85, sjt_functionParam86, sjt_functionParam87);
    }
}

void sjf_class(sjs_class* _this) {
}

void sjf_class_asstring(sjs_class* _parent, sjs_string* _return) {
    sjs_string sjt_call13 = { -1 };
    sjs_string sjt_call14 = { -1 };
    sjs_string* sjt_functionParam47 = 0;
    int32_t sjt_functionParam48;
    int32_t sjt_functionParam49;
    sjs_string* sjt_parent23 = 0;

    sjt_call13._refCount = 1;
#line 14 "array7.sj"
    sjt_call13.count = 1;
#line 14
    sjt_call13.data._refCount = 1;
#line 14
    sjt_call13.data.datasize = 1;
#line 14
    sjt_call13.data.data = (void*)sjg_string3;
#line 14
    sjt_call13.data.isglobal = true;
#line 14
    sjt_call13.data.count = 1;
#line 14
    sjf_array_char(&sjt_call13.data);
#line 14 "lib/common/string.sj"
    sjt_call13._isnullterminated = false;
#line 14
    sjf_string(&sjt_call13);
#line 14 "array7.sj"
    sjt_parent23 = &sjt_call13;
#line 14
    sjt_functionParam48 = _parent->x;
#line 22 "lib/common/i32.sj"
    sjt_functionParam49 = 10;
#line 22
    sjf_i32_asstring(sjt_functionParam48, sjt_functionParam49, &sjt_call14);
#line 14 "array7.sj"
    sjt_functionParam47 = &sjt_call14;
#line 14
    sjf_string_add(sjt_parent23, sjt_functionParam47, _return);

    if (sjt_call13._refCount == 1) { sjf_string_destroy(&sjt_call13); }
;
    if (sjt_call14._refCount == 1) { sjf_string_destroy(&sjt_call14); }
;
}

void sjf_class_asstring_heap(sjs_class* _parent, sjs_string** _return) {
    sjs_string sjt_call15 = { -1 };
    sjs_string sjt_call16 = { -1 };
    sjs_string* sjt_functionParam50 = 0;
    int32_t sjt_functionParam51;
    int32_t sjt_functionParam52;
    sjs_string* sjt_parent24 = 0;

    sjt_call15._refCount = 1;
#line 14 "array7.sj"
    sjt_call15.count = 1;
#line 14
    sjt_call15.data._refCount = 1;
#line 14
    sjt_call15.data.datasize = 1;
#line 14
    sjt_call15.data.data = (void*)sjg_string3;
#line 14
    sjt_call15.data.isglobal = true;
#line 14
    sjt_call15.data.count = 1;
#line 14
    sjf_array_char(&sjt_call15.data);
#line 14 "lib/common/string.sj"
    sjt_call15._isnullterminated = false;
#line 14
    sjf_string(&sjt_call15);
#line 14 "array7.sj"
    sjt_parent24 = &sjt_call15;
#line 14
    sjt_functionParam51 = _parent->x;
#line 22 "lib/common/i32.sj"
    sjt_functionParam52 = 10;
#line 22
    sjf_i32_asstring(sjt_functionParam51, sjt_functionParam52, &sjt_call16);
#line 14 "array7.sj"
    sjt_functionParam50 = &sjt_call16;
#line 14
    sjf_string_add_heap(sjt_parent24, sjt_functionParam50, _return);

    if (sjt_call15._refCount == 1) { sjf_string_destroy(&sjt_call15); }
;
    if (sjt_call16._refCount == 1) { sjf_string_destroy(&sjt_call16); }
;
}

void sjf_class_compare(sjs_class* l, sjs_class* r, int32_t* _return) {
    int32_t sjt_functionParam89;
    int32_t sjt_functionParam90;

#line 19 "array7.sj"
    sjt_functionParam89 = l->x;
#line 19
    sjt_functionParam90 = r->x;
#line 19
    sjf_i32_compare(sjt_functionParam89, sjt_functionParam90, _return);
}

void sjf_class_compare_callback(void * _parent, sjs_class* l, sjs_class* r, int32_t* _return) {
    sjf_class_compare(l, r, _return);
}

void sjf_class_copy(sjs_class* _this, sjs_class* _from) {
#line 2 "array7.sj"
    _this->x = _from->x;
}

void sjf_class_destroy(sjs_class* _this) {
}

void sjf_class_heap(sjs_class* _this) {
}

void sjf_class_isgreater(sjs_class* _parent, sjs_class* c, bool* _return) {
#line 10 "array7.sj"
    (*_return) = _parent->x > c->x;
}

void sjf_class_isless(sjs_class* _parent, sjs_class* c, bool* _return) {
#line 6 "array7.sj"
    (*_return) = _parent->x < c->x;
}

void sjf_console_writeline(sjs_string* data) {
    sjs_string* sjt_parent13 = 0;

#line 9 "lib/common/console.sj"
    sjt_parent13 = data;
#line 9
    sjf_string_nullterminate(sjt_parent13);
#line 12
    printf("%s\n", (char*)data->data.data);
}

void sjf_hash_type_bool(sjs_hash_type_bool* _this) {
#line 225 "lib/common/hash.sj"
    _this->_hash = kh_init(type_bool_hash_type);
}

void sjf_hash_type_bool__weakptrremovekey(sjs_hash_type_bool* _parent, int32_t key) {
#line 180 "lib/common/hash.sj"
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
#line 192 "lib/common/hash.sj"
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
#line 230 "lib/common/hash.sj"
    _this->_hash = _from->_hash;
#line 231
    khash_t(type_bool_hash_type)* p = (khash_t(type_bool_hash_type)*)_this->_hash;
#line 232
    p->refcount++;
}

void sjf_hash_type_bool_destroy(sjs_hash_type_bool* _this) {
#line 236 "lib/common/hash.sj"
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
        kh_destroy(type_bool_hash_type, _this->_hash);
#line 258
    }
}

void sjf_hash_type_bool_heap(sjs_hash_type_bool* _this) {
#line 225 "lib/common/hash.sj"
    _this->_hash = kh_init(type_bool_hash_type);
}

void sjf_i32_asstring(int32_t val, int32_t base, sjs_string* _return) {
    int32_t count;
    void* data;

#line 23 "lib/common/i32.sj"
    count = 0;
#line 24
    data = 0;
#line 26
    data = (int*)malloc(sizeof(int) + sizeof(char) * 256) + 1;
#line 27
    int* refcount = (int*)data - 1;
#line 28
    *refcount = 1;
#line 30
    char *tmp = (char*)data + 128;
#line 31
    char *tp = (char*)data + 128;
#line 32
    int i;
#line 33
    unsigned v;
#line 35
    int sign = (base == 10 && val < 0);    
#line 36
    if (sign)
#line 37
    v = -val;
#line 38
    else
#line 39
    v = (unsigned)val;
#line 41
    while (v || tp == tmp)
#line 42
    {
#line 43
        i = v % base;
#line 44
        v /= base; // v/=base uses less CPU clocks than v=v/base does
#line 45
        if (i < 10)
#line 46
        *tp++ = i + '0';
#line 47
        else
#line 48
        *tp++ = i + 'a' - 10;
#line 49
    }
#line 51
    int len = tp - tmp;
#line 53
    char* sp = (char*)data;
#line 54
    if (sign) 
#line 55
    {
#line 56
        *sp++ = '-';
#line 57
        len++;
#line 58
    }
#line 60
    while (tp > tmp)
#line 61
    *sp++ = *--tp;
#line 63
    count = len;
#line 63
    _return->_refCount = 1;
#line 65
    _return->count = count;
#line 65
    _return->data._refCount = 1;
#line 65
    _return->data.datasize = 256;
#line 65
    _return->data.data = data;
#line 4 "lib/common/array.sj"
    _return->data.isglobal = false;
#line 65 "lib/common/i32.sj"
    _return->data.count = count;
#line 65
    sjf_array_char(&_return->data);
#line 14 "lib/common/string.sj"
    _return->_isnullterminated = false;
#line 14
    sjf_string(_return);
}

void sjf_i32_asstring_heap(int32_t val, int32_t base, sjs_string** _return) {
    int32_t count;
    void* data;

#line 23 "lib/common/i32.sj"
    count = 0;
#line 24
    data = 0;
#line 26
    data = (int*)malloc(sizeof(int) + sizeof(char) * 256) + 1;
#line 27
    int* refcount = (int*)data - 1;
#line 28
    *refcount = 1;
#line 30
    char *tmp = (char*)data + 128;
#line 31
    char *tp = (char*)data + 128;
#line 32
    int i;
#line 33
    unsigned v;
#line 35
    int sign = (base == 10 && val < 0);    
#line 36
    if (sign)
#line 37
    v = -val;
#line 38
    else
#line 39
    v = (unsigned)val;
#line 41
    while (v || tp == tmp)
#line 42
    {
#line 43
        i = v % base;
#line 44
        v /= base; // v/=base uses less CPU clocks than v=v/base does
#line 45
        if (i < 10)
#line 46
        *tp++ = i + '0';
#line 47
        else
#line 48
        *tp++ = i + 'a' - 10;
#line 49
    }
#line 51
    int len = tp - tmp;
#line 53
    char* sp = (char*)data;
#line 54
    if (sign) 
#line 55
    {
#line 56
        *sp++ = '-';
#line 57
        len++;
#line 58
    }
#line 60
    while (tp > tmp)
#line 61
    *sp++ = *--tp;
#line 63
    count = len;
#line 63
    (*_return) = (sjs_string*)malloc(sizeof(sjs_string));
#line 63
    (*_return)->_refCount = 1;
#line 65
    (*_return)->count = count;
#line 65
    (*_return)->data._refCount = 1;
#line 65
    (*_return)->data.datasize = 256;
#line 65
    (*_return)->data.data = data;
#line 4 "lib/common/array.sj"
    (*_return)->data.isglobal = false;
#line 65 "lib/common/i32.sj"
    (*_return)->data.count = count;
#line 65
    sjf_array_char(&(*_return)->data);
#line 14 "lib/common/string.sj"
    (*_return)->_isnullterminated = false;
#line 14
    sjf_string_heap((*_return));
}

void sjf_i32_compare(int32_t l, int32_t r, int32_t* _return) {
    if (l == r) {
#line 70 "lib/common/i32.sj"
        (*_return) = 0;
    } else {
        if (l < r) {
            int32_t result4;

#line 72 "lib/common/i32.sj"
            result4 = -1;
#line 72
            (*_return) = result4;
        } else {
#line 74 "lib/common/i32.sj"
            (*_return) = 1;
        }
    }
}

void sjf_log(sjs_log* _this) {
}

void sjf_log_copy(sjs_log* _this, sjs_log* _from) {
#line 13 "lib/common/log.sj"
    _this->minlevel = _from->minlevel;
#line 13
    sjs_hash_type_bool* copyoption2 = (_from->traceincludes._refCount != -1 ? &_from->traceincludes : 0);
    if (copyoption2 != 0) {
        _this->traceincludes._refCount = 1;
#line 13 "lib/common/log.sj"
        sjf_hash_type_bool_copy(&_this->traceincludes, copyoption2);
    } else {
        _this->traceincludes._refCount = -1;
    }

#line 13
    sjs_hash_type_bool* copyoption3 = (_from->debugincludes._refCount != -1 ? &_from->debugincludes : 0);
    if (copyoption3 != 0) {
        _this->debugincludes._refCount = 1;
#line 13 "lib/common/log.sj"
        sjf_hash_type_bool_copy(&_this->debugincludes, copyoption3);
    } else {
        _this->debugincludes._refCount = -1;
    }

#line 13
    sjs_hash_type_bool* copyoption4 = (_from->infoincludes._refCount != -1 ? &_from->infoincludes : 0);
    if (copyoption4 != 0) {
        _this->infoincludes._refCount = 1;
#line 13 "lib/common/log.sj"
        sjf_hash_type_bool_copy(&_this->infoincludes, copyoption4);
    } else {
        _this->infoincludes._refCount = -1;
    }

#line 13
    sjs_hash_type_bool* copyoption5 = (_from->warnincludes._refCount != -1 ? &_from->warnincludes : 0);
    if (copyoption5 != 0) {
        _this->warnincludes._refCount = 1;
#line 13 "lib/common/log.sj"
        sjf_hash_type_bool_copy(&_this->warnincludes, copyoption5);
    } else {
        _this->warnincludes._refCount = -1;
    }

#line 13
    sjs_hash_type_bool* copyoption6 = (_from->errorincludes._refCount != -1 ? &_from->errorincludes : 0);
    if (copyoption6 != 0) {
        _this->errorincludes._refCount = 1;
#line 13 "lib/common/log.sj"
        sjf_hash_type_bool_copy(&_this->errorincludes, copyoption6);
    } else {
        _this->errorincludes._refCount = -1;
    }

#line 13
    sjs_hash_type_bool* copyoption7 = (_from->fatalincludes._refCount != -1 ? &_from->fatalincludes : 0);
    if (copyoption7 != 0) {
        _this->fatalincludes._refCount = 1;
#line 13 "lib/common/log.sj"
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

void sjf_string(sjs_string* _this) {
}

void sjf_string_add(sjs_string* _parent, sjs_string* item, sjs_string* _return) {
    sjs_array_char newdata = { -1 };

    if (item->count == 0) {
        _return->_refCount = 1;
#line 18 "lib/common/string.sj"
        _return->count = _parent->count;
#line 18
        _return->data._refCount = 1;
#line 18
        sjf_array_char_copy(&_return->data, &_parent->data);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
    } else {
        int32_t i;
        int32_t newcount;
        int32_t sjt_forEnd2;
        int32_t sjt_forStart2;

        if ((_parent->count + item->count) > (&_parent->data)->datasize) {
            int32_t sjt_functionParam36;
            sjs_array_char* sjt_parent14 = 0;

#line 134 "lib/common/array.sj"
            sjt_parent14 = &_parent->data;
#line 21 "lib/common/string.sj"
            sjt_functionParam36 = ((((_parent->count + item->count) - 1) / 256) + 1) * 256;
#line 21
            sjf_array_char_grow(sjt_parent14, sjt_functionParam36, &newdata);
        } else {
            newdata._refCount = 1;
#line 20 "lib/common/string.sj"
            sjf_array_char_copy(&newdata, &_parent->data);
        }

#line 25 "lib/common/string.sj"
        newcount = _parent->count;
#line 27
        sjt_forStart2 = 0;
#line 27
        sjt_forEnd2 = item->count;
#line 27
        i = sjt_forStart2;
        while (i < sjt_forEnd2) {
            int32_t sjt_functionParam37;
            char sjt_functionParam38;
            int32_t sjt_functionParam40;
            sjs_array_char* sjt_parent15 = 0;
            sjs_string* sjt_parent17 = 0;

#line 34 "lib/common/array.sj"
            sjt_parent15 = &newdata;
#line 28 "lib/common/string.sj"
            sjt_functionParam37 = newcount;
#line 16
            sjt_parent17 = item;
#line 27
            sjt_functionParam40 = i;
#line 27
            sjf_string_getat(sjt_parent17, sjt_functionParam40, &sjt_functionParam38);
#line 27
            sjf_array_char_initat(sjt_parent15, sjt_functionParam37, sjt_functionParam38);
#line 29
            newcount = newcount + 1;
#line 27
            i++;
        }

#line 27
        _return->_refCount = 1;
#line 32
        _return->count = newcount;
#line 32
        _return->data._refCount = 1;
#line 32
        sjf_array_char_copy(&_return->data, &newdata);
#line 14
        _return->_isnullterminated = false;
#line 14
        sjf_string(_return);
    }

    if (newdata._refCount == 1) { sjf_array_char_destroy(&newdata); }
;
}

void sjf_string_add_heap(sjs_string* _parent, sjs_string* item, sjs_string** _return) {
    sjs_array_char newdata = { -1 };

    if (item->count == 0) {
        (*_return) = (sjs_string*)malloc(sizeof(sjs_string));
        (*_return)->_refCount = 1;
#line 18 "lib/common/string.sj"
        (*_return)->count = _parent->count;
#line 18
        (*_return)->data._refCount = 1;
#line 18
        sjf_array_char_copy(&(*_return)->data, &_parent->data);
#line 14
        (*_return)->_isnullterminated = false;
#line 14
        sjf_string_heap((*_return));
    } else {
        int32_t i;
        int32_t newcount;
        int32_t sjt_forEnd3;
        int32_t sjt_forStart3;

        if ((_parent->count + item->count) > (&_parent->data)->datasize) {
            int32_t sjt_functionParam41;
            sjs_array_char* sjt_parent18 = 0;

#line 134 "lib/common/array.sj"
            sjt_parent18 = &_parent->data;
#line 21 "lib/common/string.sj"
            sjt_functionParam41 = ((((_parent->count + item->count) - 1) / 256) + 1) * 256;
#line 21
            sjf_array_char_grow(sjt_parent18, sjt_functionParam41, &newdata);
        } else {
            newdata._refCount = 1;
#line 20 "lib/common/string.sj"
            sjf_array_char_copy(&newdata, &_parent->data);
        }

#line 25 "lib/common/string.sj"
        newcount = _parent->count;
#line 27
        sjt_forStart3 = 0;
#line 27
        sjt_forEnd3 = item->count;
#line 27
        i = sjt_forStart3;
        while (i < sjt_forEnd3) {
            int32_t sjt_functionParam42;
            char sjt_functionParam43;
            int32_t sjt_functionParam44;
            sjs_array_char* sjt_parent19 = 0;
            sjs_string* sjt_parent20 = 0;

#line 34 "lib/common/array.sj"
            sjt_parent19 = &newdata;
#line 28 "lib/common/string.sj"
            sjt_functionParam42 = newcount;
#line 16
            sjt_parent20 = item;
#line 27
            sjt_functionParam44 = i;
#line 27
            sjf_string_getat(sjt_parent20, sjt_functionParam44, &sjt_functionParam43);
#line 27
            sjf_array_char_initat(sjt_parent19, sjt_functionParam42, sjt_functionParam43);
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
        (*_return)->count = newcount;
#line 32
        (*_return)->data._refCount = 1;
#line 32
        sjf_array_char_copy(&(*_return)->data, &newdata);
#line 14
        (*_return)->_isnullterminated = false;
#line 14
        sjf_string_heap((*_return));
    }

    if (newdata._refCount == 1) { sjf_array_char_destroy(&newdata); }
;
}

void sjf_string_copy(sjs_string* _this, sjs_string* _from) {
#line 6 "lib/common/string.sj"
    _this->count = _from->count;
#line 6
    _this->data._refCount = 1;
#line 6
    sjf_array_char_copy(&_this->data, &_from->data);
#line 6
    _this->_isnullterminated = _from->_isnullterminated;
}

void sjf_string_destroy(sjs_string* _this) {
    if (_this->data._refCount == 1) { sjf_array_char_destroy(&_this->data); }
;
}

void sjf_string_getat(sjs_string* _parent, int32_t index, char* _return) {
    int32_t sjt_functionParam39;
    sjs_array_char* sjt_parent16 = 0;

#line 7 "lib/common/array.sj"
    sjt_parent16 = &_parent->data;
#line 36 "lib/common/string.sj"
    sjt_functionParam39 = index;
#line 36
    sjf_array_char_getat(sjt_parent16, sjt_functionParam39, _return);
}

void sjf_string_heap(sjs_string* _this) {
}

void sjf_string_nullterminate(sjs_string* _parent) {
    bool result2;
    bool result3;
    sjs_array_char sjt_funcold1 = { -1 };

#line 73 "lib/common/string.sj"
    result2 = !(&_parent->data)->isglobal;
#line 73
    result3 = !_parent->_isnullterminated;
    if (result2 || result3) {
        int32_t sjt_functionParam33;
        char sjt_functionParam34;
        sjs_array_char* sjt_parent12 = 0;

        if ((_parent->count + 1) > (&_parent->data)->datasize) {
            int32_t sjt_functionParam32;
            sjs_array_char* sjt_parent11 = 0;

            sjt_funcold1._refCount = 1;
#line 134 "lib/common/array.sj"
            sjf_array_char_copy(&sjt_funcold1, &_parent->data);
#line 134
            sjt_parent11 = &_parent->data;
#line 75 "lib/common/string.sj"
            sjt_functionParam32 = _parent->count + 1;
#line 75
            sjf_array_char_grow(sjt_parent11, sjt_functionParam32, &sjt_funcold1);
#line 75
            if (_parent->data._refCount == 1) { sjf_array_char_destroy(&_parent->data); }
;
#line 134 "lib/common/array.sj"
            sjf_array_char_copy(&_parent->data, &sjt_funcold1);
        }

#line 34 "lib/common/array.sj"
        sjt_parent12 = &_parent->data;
#line 77 "lib/common/string.sj"
        sjt_functionParam33 = _parent->count;
#line 77
        sjt_functionParam34 = '\0';
#line 77
        sjf_array_char_initat(sjt_parent12, sjt_functionParam33, sjt_functionParam34);
#line 78
        _parent->_isnullterminated = true;
    }

    if (sjt_funcold1._refCount == 1) { sjf_array_char_destroy(&sjt_funcold1); }
;
}

void sjf_type_hash(int32_t val, uint32_t* _return) {
    int32_t sjt_cast1;

#line 5 "lib/common/type.sj"
    sjt_cast1 = val;
#line 6
    (*_return) = (uint32_t)sjt_cast1;
}

void sjf_type_isequal(int32_t l, int32_t r, bool* _return) {
#line 10 "lib/common/type.sj"
    (*_return) = l == r;
}

int main(int argc, char** argv) {
#line 1 "lib/common/log.sj"
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
#line 1 "lib/common/f32.sj"
    g_f32_pi = 3.14159265358979323846f;
#line 1 "lib/common/i32.sj"
    g_u32_maxvalue = (uint32_t)4294967295u;
#line 3
    result1 = -1;
#line 3
    g_i32_maxvalue = result1 - 2147483647;
#line 4
    g_i32_minvalue = 2147483647;
#line 10 "lib/common/log.sj"
    g_log_includeall._refCount = -1;
#line 10
    sjt_value1._refCount = 1;
#line 10
    sjf_hash_type_bool(&sjt_value1);
#line 11
    sjs_hash_type_bool* copyoption1 = &sjt_value1;
    if (copyoption1 != 0) {
        g_log_excludeall._refCount = 1;
#line 11 "lib/common/log.sj"
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
#line 13 "lib/common/log.sj"
        sjf_hash_type_bool_copy(&g_log.traceincludes, copyoption8);
    } else {
        g_log.traceincludes._refCount = -1;
    }

#line 13
    sjs_hash_type_bool* copyoption9 = (g_log_includeall._refCount != -1 ? &g_log_includeall : 0);
    if (copyoption9 != 0) {
        g_log.debugincludes._refCount = 1;
#line 13 "lib/common/log.sj"
        sjf_hash_type_bool_copy(&g_log.debugincludes, copyoption9);
    } else {
        g_log.debugincludes._refCount = -1;
    }

#line 13
    sjs_hash_type_bool* copyoption10 = (g_log_includeall._refCount != -1 ? &g_log_includeall : 0);
    if (copyoption10 != 0) {
        g_log.infoincludes._refCount = 1;
#line 13 "lib/common/log.sj"
        sjf_hash_type_bool_copy(&g_log.infoincludes, copyoption10);
    } else {
        g_log.infoincludes._refCount = -1;
    }

#line 13
    sjs_hash_type_bool* copyoption11 = (g_log_includeall._refCount != -1 ? &g_log_includeall : 0);
    if (copyoption11 != 0) {
        g_log.warnincludes._refCount = 1;
#line 13 "lib/common/log.sj"
        sjf_hash_type_bool_copy(&g_log.warnincludes, copyoption11);
    } else {
        g_log.warnincludes._refCount = -1;
    }

#line 13
    sjs_hash_type_bool* copyoption12 = (g_log_includeall._refCount != -1 ? &g_log_includeall : 0);
    if (copyoption12 != 0) {
        g_log.errorincludes._refCount = 1;
#line 13 "lib/common/log.sj"
        sjf_hash_type_bool_copy(&g_log.errorincludes, copyoption12);
    } else {
        g_log.errorincludes._refCount = -1;
    }

#line 13
    sjs_hash_type_bool* copyoption13 = (g_log_includeall._refCount != -1 ? &g_log_includeall : 0);
    if (copyoption13 != 0) {
        g_log.fatalincludes._refCount = 1;
#line 13 "lib/common/log.sj"
        sjf_hash_type_bool_copy(&g_log.fatalincludes, copyoption13);
    } else {
        g_log.fatalincludes._refCount = -1;
    }

#line 13
    sjf_log(&g_log);
#line 1 "lib/common/string.sj"
    g_emptystringdata = 0;
#line 3
    g_emptystringdata = "";
#line 2 "lib/common/weakptr.sj"
    ptr_init();
#line 3
    weakptr_init();
#line 7 "lib/common/clock.sj"
    g_clocks_per_sec = 0;
#line 9
    g_clocks_per_sec = CLOCKS_PER_SEC;
#line 9
    g_a._refCount = 1;
#line 23 "array7.sj"
    g_a.datasize = 5;
#line 3 "lib/common/array.sj"
    g_a.data = 0;
#line 4
    g_a.isglobal = false;
#line 5
    g_a.count = 0;
#line 5
    sjf_array_class(&g_a);
#line 23 "array7.sj"
    sjs_array_class* array1;
#line 23
    array1 = &g_a;
#line 23
    sjt_parent1 = array1;
#line 23
    sjt_functionParam1 = 0;
#line 23
    sjt_call1._refCount = 1;
#line 23
    sjt_call1.x = 1;
#line 23
    sjf_class(&sjt_call1);
#line 23
    sjt_functionParam2 = &sjt_call1;
#line 23
    sjf_array_class_initat(sjt_parent1, sjt_functionParam1, sjt_functionParam2);
#line 23
    sjt_parent2 = array1;
#line 23
    sjt_functionParam3 = 1;
#line 23
    sjt_call2._refCount = 1;
#line 23
    sjt_call2.x = 4;
#line 23
    sjf_class(&sjt_call2);
#line 23
    sjt_functionParam4 = &sjt_call2;
#line 23
    sjf_array_class_initat(sjt_parent2, sjt_functionParam3, sjt_functionParam4);
#line 23
    sjt_parent3 = array1;
#line 23
    sjt_functionParam5 = 2;
#line 23
    sjt_call3._refCount = 1;
#line 23
    sjt_call3.x = 5;
#line 23
    sjf_class(&sjt_call3);
#line 23
    sjt_functionParam6 = &sjt_call3;
#line 23
    sjf_array_class_initat(sjt_parent3, sjt_functionParam5, sjt_functionParam6);
#line 23
    sjt_parent4 = array1;
#line 23
    sjt_functionParam7 = 3;
#line 23
    sjt_call4._refCount = 1;
#line 23
    sjt_call4.x = 6;
#line 23
    sjf_class(&sjt_call4);
#line 23
    sjt_functionParam8 = &sjt_call4;
#line 23
    sjf_array_class_initat(sjt_parent4, sjt_functionParam7, sjt_functionParam8);
#line 23
    sjt_parent5 = array1;
#line 23
    sjt_functionParam9 = 4;
#line 23
    sjt_call5._refCount = 1;
#line 23
    sjt_call5.x = 2;
#line 23
    sjf_class(&sjt_call5);
#line 23
    sjt_functionParam10 = &sjt_call5;
#line 23
    sjf_array_class_initat(sjt_parent5, sjt_functionParam9, sjt_functionParam10);
#line 237 "lib/common/array.sj"
    sjt_parent10 = &g_a;
#line 237
    sjf_array_class_sort(sjt_parent10);
#line 258
    sjt_parent29 = &g_a;
#line 258
    sjt_call20._refCount = 1;
#line 258
    sjt_call20.count = 2;
#line 258
    sjt_call20.data._refCount = 1;
#line 258
    sjt_call20.data.datasize = 2;
#line 258
    sjt_call20.data.data = (void*)sjg_string1;
#line 258
    sjt_call20.data.isglobal = true;
#line 258
    sjt_call20.data.count = 2;
#line 258
    sjf_array_char(&sjt_call20.data);
#line 14 "lib/common/string.sj"
    sjt_call20._isnullterminated = false;
#line 14
    sjf_string(&sjt_call20);
#line 258 "lib/common/array.sj"
    sjt_functionParam57 = &sjt_call20;
#line 258
    sjf_array_class_asstring(sjt_parent29, sjt_functionParam57, &sjt_call11);
#line 25 "array7.sj"
    sjt_functionParam35 = &sjt_call11;
#line 25
    sjf_console_writeline(sjt_functionParam35);
#line 249 "lib/common/array.sj"
    sjt_parent30 = &g_a;
#line 249
    sjf_array_class_reverse(sjt_parent30);
#line 258
    sjt_parent31 = &g_a;
#line 258
    sjt_call23._refCount = 1;
#line 258
    sjt_call23.count = 2;
#line 258
    sjt_call23.data._refCount = 1;
#line 258
    sjt_call23.data.datasize = 2;
#line 258
    sjt_call23.data.data = (void*)sjg_string1;
#line 258
    sjt_call23.data.isglobal = true;
#line 258
    sjt_call23.data.count = 2;
#line 258
    sjf_array_char(&sjt_call23.data);
#line 14 "lib/common/string.sj"
    sjt_call23._isnullterminated = false;
#line 14
    sjf_string(&sjt_call23);
#line 258 "lib/common/array.sj"
    sjt_functionParam65 = &sjt_call23;
#line 258
    sjf_array_class_asstring(sjt_parent31, sjt_functionParam65, &sjt_call22);
#line 28 "array7.sj"
    sjt_functionParam64 = &sjt_call22;
#line 28
    sjf_console_writeline(sjt_functionParam64);
#line 243 "lib/common/array.sj"
    sjt_parent32 = &g_a;
#line 30 "array7.sj"
    sjt_functionParam88._parent = (sjs_object*)1;
#line 30
    sjt_functionParam88._cb = (void(*)(sjs_object*,sjs_class*,sjs_class*, int32_t*))sjf_class_compare_callback;
#line 30
    sjf_array_class_sortcb(sjt_parent32, sjt_functionParam88);
#line 258 "lib/common/array.sj"
    sjt_parent33 = &g_a;
#line 258
    sjt_call28._refCount = 1;
#line 258
    sjt_call28.count = 2;
#line 258
    sjt_call28.data._refCount = 1;
#line 258
    sjt_call28.data.datasize = 2;
#line 258
    sjt_call28.data.data = (void*)sjg_string1;
#line 258
    sjt_call28.data.isglobal = true;
#line 258
    sjt_call28.data.count = 2;
#line 258
    sjf_array_char(&sjt_call28.data);
#line 14 "lib/common/string.sj"
    sjt_call28._isnullterminated = false;
#line 14
    sjf_string(&sjt_call28);
#line 258 "lib/common/array.sj"
    sjt_functionParam92 = &sjt_call28;
#line 258
    sjf_array_class_asstring(sjt_parent33, sjt_functionParam92, &sjt_call27);
#line 31 "array7.sj"
    sjt_functionParam91 = &sjt_call27;
#line 31
    sjf_console_writeline(sjt_functionParam91);
    main_destroy();
    return 0;
}

void main_destroy() {

    if (g_a._refCount == 1) { sjf_array_class_destroy(&g_a); }
;
    if (g_log._refCount == 1) { sjf_log_destroy(&g_log); }
;
    if (g_log_excludeall._refCount == 1) { sjf_hash_type_bool_destroy(&g_log_excludeall); }
;
    if (g_log_includeall._refCount == 1) { sjf_hash_type_bool_destroy(&g_log_includeall); }
;
    if (sjt_call1._refCount == 1) { sjf_class_destroy(&sjt_call1); }
;
    if (sjt_call11._refCount == 1) { sjf_string_destroy(&sjt_call11); }
;
    if (sjt_call2._refCount == 1) { sjf_class_destroy(&sjt_call2); }
;
    if (sjt_call20._refCount == 1) { sjf_string_destroy(&sjt_call20); }
;
    if (sjt_call22._refCount == 1) { sjf_string_destroy(&sjt_call22); }
;
    if (sjt_call23._refCount == 1) { sjf_string_destroy(&sjt_call23); }
;
    if (sjt_call27._refCount == 1) { sjf_string_destroy(&sjt_call27); }
;
    if (sjt_call28._refCount == 1) { sjf_string_destroy(&sjt_call28); }
;
    if (sjt_call3._refCount == 1) { sjf_class_destroy(&sjt_call3); }
;
    if (sjt_call4._refCount == 1) { sjf_class_destroy(&sjt_call4); }
;
    if (sjt_call5._refCount == 1) { sjf_class_destroy(&sjt_call5); }
;
    if (sjt_value1._refCount == 1) { sjf_hash_type_bool_destroy(&sjt_value1); }
;
}
