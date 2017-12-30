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
int32_t sjv_loglevel_debug;
int32_t sjv_loglevel_error;
int32_t sjv_loglevel_fatal;
int32_t sjv_loglevel_info;
int32_t sjv_loglevel_trace;
int32_t sjv_loglevel_warn;

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
sjs_array_class sjv_a = { -1 };
int32_t sjv_clocks_per_sec;
void* sjv_emptystringdata;
float sjv_f32_pi;
int32_t sjv_i32_maxvalue;
int32_t sjv_i32_minvalue;
sjs_log sjv_log = { -1 };
sjs_hash_type_bool sjv_log_excludeall = { -1 };
sjs_hash_type_bool sjv_log_includeall = { -1 };
uint32_t sjv_u32_maxvalue;

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
    if (_this->datasize < 0) {
        halt("size is less than zero");
    }
    if (!_this->data) {
        _this->data = (int*)malloc(_this->datasize * sizeof(char) + sizeof(int)) + 1;
        int* refcount = (int*)_this->data - 1;
        *refcount = 1;
        if (!_this->data) {
            halt("grow: out of memory\n");
        }
    }
}

void sjf_array_char_copy(sjs_array_char* _this, sjs_array_char* _from) {
    _this->datasize = _from->datasize;
    _this->data = _from->data;
    _this->isglobal = _from->isglobal;
    _this->count = _from->count;
    _this->data = _from->data;
    if (!_this->isglobal && _this->data) {
        int* refcount = (int*)_this->data - 1;
        *refcount = *refcount + 1;
    }
}

void sjf_array_char_destroy(sjs_array_char* _this) {
    if (!_this->isglobal && _this->data) {
        int* refcount = (int*)_this->data - 1;
        *refcount = *refcount - 1;
        if (*refcount == 0) {
            #if !true && !false
            char* p = (char*)_this->data;
            for (int i = 0; i < _this->count; i++) {
                ;
            }
            #endif
            free(refcount);
        }
    }
}

void sjf_array_char_getat(sjs_array_char* _parent, int32_t index, char* _return) {
    if (index >= _parent->count || index < 0) {
        halt("getAt: out of bounds\n");
    }
    char* p = (char*)_parent->data;
    (*_return) = p[index];
return;;       
}

void sjf_array_char_grow(sjs_array_char* _parent, int32_t newsize, sjs_array_char* _return) {
    void* sjv_newdata;

    sjv_newdata = 0;
    if (_parent->datasize != newsize) {
        if (newsize < _parent->datasize) {
            halt("grow: new size smaller than old _parent->datasize %d:%d\n", newsize, _parent->datasize);
        }
        sjv_newdata = (int*)(malloc(sizeof(int) + newsize * sizeof(char))) + 1;
        int* refcount = (int*)sjv_newdata - 1;
        *refcount = 1;
        if (!_parent->data) {
            halt("grow: out of memory\n");
        }
        char* p = (char*)_parent->data;
        char* newp = (char*)sjv_newdata;
        int count = _parent->count;
        #if true
        memcpy(newp, p, sizeof(char) * count);
        #else
        for (int i = 0; i < count; i++) {
            newp[i] = p[i];
;
        }
        #endif
    }
    _return->_refCount = 1;
    _return->datasize = newsize;
    _return->data = sjv_newdata;
    _return->isglobal = false;
    _return->count = _parent->count;
    sjf_array_char(_return);
}

void sjf_array_char_grow_heap(sjs_array_char* _parent, int32_t newsize, sjs_array_char** _return) {
    void* sjv_newdata;

    sjv_newdata = 0;
    if (_parent->datasize != newsize) {
        if (newsize < _parent->datasize) {
            halt("grow: new size smaller than old _parent->datasize %d:%d\n", newsize, _parent->datasize);
        }
        sjv_newdata = (int*)(malloc(sizeof(int) + newsize * sizeof(char))) + 1;
        int* refcount = (int*)sjv_newdata - 1;
        *refcount = 1;
        if (!_parent->data) {
            halt("grow: out of memory\n");
        }
        char* p = (char*)_parent->data;
        char* newp = (char*)sjv_newdata;
        int count = _parent->count;
        #if true
        memcpy(newp, p, sizeof(char) * count);
        #else
        for (int i = 0; i < count; i++) {
            newp[i] = p[i];
;
        }
        #endif
    }
    (*_return) = (sjs_array_char*)malloc(sizeof(sjs_array_char));
    (*_return)->_refCount = 1;
    (*_return)->datasize = newsize;
    (*_return)->data = sjv_newdata;
    (*_return)->isglobal = false;
    (*_return)->count = _parent->count;
    sjf_array_char_heap((*_return));
}

void sjf_array_char_heap(sjs_array_char* _this) {
    if (_this->datasize < 0) {
        halt("size is less than zero");
    }
    if (!_this->data) {
        _this->data = (int*)malloc(_this->datasize * sizeof(char) + sizeof(int)) + 1;
        int* refcount = (int*)_this->data - 1;
        *refcount = 1;
        if (!_this->data) {
            halt("grow: out of memory\n");
        }
    }
}

void sjf_array_char_initat(sjs_array_char* _parent, int32_t index, char item) {
    if (index != _parent->count) {
        halt("initAt: can only initialize last element\n");     
    }
    if (index >= _parent->datasize || index < 0) {
        halt("initAt: out of bounds %d:%d\n", index, _parent->datasize);
    }
    char* p = (char*)_parent->data;
    p[index] = item;
;
    _parent->count = index + 1;
}

void sjf_array_class(sjs_array_class* _this) {
    if (_this->datasize < 0) {
        halt("size is less than zero");
    }
    if (!_this->data) {
        _this->data = (int*)malloc(_this->datasize * sizeof(sjs_class) + sizeof(int)) + 1;
        int* refcount = (int*)_this->data - 1;
        *refcount = 1;
        if (!_this->data) {
            halt("grow: out of memory\n");
        }
    }
}

void sjf_array_class__quicksort(sjs_array_class* _parent, int32_t left, int32_t right) {
    int32_t sjt_functionParam11;
    bool sjt_while1;
    int32_t sjv_i;
    int32_t sjv_j;
    sjs_class sjv_pivot = { -1 };

    sjv_i = left;
    sjv_j = right;
    sjt_functionParam11 = (left + right) / 2;
    sjf_array_class_getat(_parent, sjt_functionParam11, &sjv_pivot);
    sjt_while1 = sjv_i <= sjv_j;
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
        sjs_class sjv_tmp = { -1 };

        sjt_functionParam12 = sjv_i;
        sjf_array_class_getat(_parent, sjt_functionParam12, &sjt_call6);
        sjt_parent6 = &sjt_call6;
        sjt_functionParam13 = &sjv_pivot;
        sjf_class_isless(sjt_parent6, sjt_functionParam13, &sjt_while2);
        while (sjt_while2) {
            sjs_class sjt_call7 = { -1 };
            int32_t sjt_functionParam14;
            sjs_class* sjt_functionParam15 = 0;
            sjs_class* sjt_parent7 = 0;

            sjv_i = sjv_i + 1;
            sjt_functionParam14 = sjv_i;
            sjf_array_class_getat(_parent, sjt_functionParam14, &sjt_call7);
            sjt_parent7 = &sjt_call7;
            sjt_functionParam15 = &sjv_pivot;
            sjf_class_isless(sjt_parent7, sjt_functionParam15, &sjt_while2);

            if (sjt_call7._refCount == 1) { sjf_class_destroy(&sjt_call7); }
;
        }

        sjt_functionParam16 = sjv_j;
        sjf_array_class_getat(_parent, sjt_functionParam16, &sjt_call8);
        sjt_parent8 = &sjt_call8;
        sjt_functionParam17 = &sjv_pivot;
        sjf_class_isgreater(sjt_parent8, sjt_functionParam17, &sjt_while3);
        while (sjt_while3) {
            sjs_class sjt_call9 = { -1 };
            int32_t sjt_functionParam18;
            sjs_class* sjt_functionParam19 = 0;
            sjs_class* sjt_parent9 = 0;

            sjv_j = sjv_j - 1;
            sjt_functionParam18 = sjv_j;
            sjf_array_class_getat(_parent, sjt_functionParam18, &sjt_call9);
            sjt_parent9 = &sjt_call9;
            sjt_functionParam19 = &sjv_pivot;
            sjf_class_isgreater(sjt_parent9, sjt_functionParam19, &sjt_while3);

            if (sjt_call9._refCount == 1) { sjf_class_destroy(&sjt_call9); }
;
        }

        if (sjv_i <= sjv_j) {
            int32_t sjt_functionParam20;
            int32_t sjt_functionParam21;
            sjs_class* sjt_functionParam22 = 0;
            int32_t sjt_functionParam23;
            int32_t sjt_functionParam24;
            sjs_class* sjt_functionParam25 = 0;

            sjt_functionParam20 = sjv_i;
            sjf_array_class_getat(_parent, sjt_functionParam20, &sjv_tmp);
            sjt_functionParam21 = sjv_i;
            sjt_functionParam23 = sjv_j;
            sjf_array_class_getat(_parent, sjt_functionParam23, &sjt_call10);
            sjt_functionParam22 = &sjt_call10;
            sjf_array_class_setat(_parent, sjt_functionParam21, sjt_functionParam22);
            sjt_functionParam24 = sjv_j;
            sjt_functionParam25 = &sjv_tmp;
            sjf_array_class_setat(_parent, sjt_functionParam24, sjt_functionParam25);
            sjv_i = sjv_i + 1;
            sjv_j = sjv_j - 1;
        }

        sjt_while1 = sjv_i <= sjv_j;

        if (sjt_call10._refCount == 1) { sjf_class_destroy(&sjt_call10); }
;
        if (sjt_call6._refCount == 1) { sjf_class_destroy(&sjt_call6); }
;
        if (sjt_call8._refCount == 1) { sjf_class_destroy(&sjt_call8); }
;
        if (sjv_tmp._refCount == 1) { sjf_class_destroy(&sjv_tmp); }
;
    }

    if (left < sjv_j) {
        int32_t sjt_functionParam26;
        int32_t sjt_functionParam27;

        sjt_functionParam26 = left;
        sjt_functionParam27 = sjv_j;
        sjf_array_class__quicksort(_parent, sjt_functionParam26, sjt_functionParam27);
    }

    if (sjv_i < right) {
        int32_t sjt_functionParam28;
        int32_t sjt_functionParam29;

        sjt_functionParam28 = sjv_i;
        sjt_functionParam29 = right;
        sjf_array_class__quicksort(_parent, sjt_functionParam28, sjt_functionParam29);
    }

    if (sjv_pivot._refCount == 1) { sjf_class_destroy(&sjv_pivot); }
;
}

void sjf_array_class__quicksortcallback(sjs_array_class* _parent, int32_t left, int32_t right, cb_class_class_i32 cb) {
    int32_t sjt_functionParam66;
    bool sjt_while4;
    int32_t sjv_i;
    int32_t sjv_j;
    sjs_class sjv_pivot = { -1 };

    sjv_i = left;
    sjv_j = right;
    sjt_functionParam66 = (left + right) / 2;
    sjf_array_class_getat(_parent, sjt_functionParam66, &sjv_pivot);
    sjt_while4 = sjv_i <= sjv_j;
    while (sjt_while4) {
        sjs_class sjt_call26 = { -1 };
        bool sjt_while5;
        bool sjt_while6;
        bool sjv_continue;
        sjs_class sjv_tmp = { -1 };

        sjv_continue = true;
        sjt_while5 = (sjv_i < _parent->count) && sjv_continue;
        while (sjt_while5) {
            sjs_class sjt_call24 = { -1 };
            int32_t sjt_capture1;
            sjs_class* sjt_functionParam67 = 0;
            int32_t sjt_functionParam68;
            sjs_class* sjt_functionParam69 = 0;

            sjt_functionParam68 = sjv_i;
            sjf_array_class_getat(_parent, sjt_functionParam68, &sjt_call24);
            sjt_functionParam67 = &sjt_call24;
            sjt_functionParam69 = &sjv_pivot;
            cb._cb(cb._parent, sjt_functionParam67, sjt_functionParam69, &sjt_capture1);
            sjv_continue = sjt_capture1 < 0;
            if (sjv_continue) {
                sjv_i = sjv_i + 1;
            }

            sjt_while5 = (sjv_i < _parent->count) && sjv_continue;

            if (sjt_call24._refCount == 1) { sjf_class_destroy(&sjt_call24); }
;
        }

        sjv_continue = true;
        sjt_while6 = (sjv_j >= 0) && sjv_continue;
        while (sjt_while6) {
            sjs_class sjt_call25 = { -1 };
            int32_t sjt_capture2;
            sjs_class* sjt_functionParam70 = 0;
            int32_t sjt_functionParam71;
            sjs_class* sjt_functionParam72 = 0;

            sjt_functionParam71 = sjv_j;
            sjf_array_class_getat(_parent, sjt_functionParam71, &sjt_call25);
            sjt_functionParam70 = &sjt_call25;
            sjt_functionParam72 = &sjv_pivot;
            cb._cb(cb._parent, sjt_functionParam70, sjt_functionParam72, &sjt_capture2);
            sjv_continue = sjt_capture2 > 0;
            if (sjv_continue) {
                sjv_j = sjv_j - 1;
            }

            sjt_while6 = (sjv_j >= 0) && sjv_continue;

            if (sjt_call25._refCount == 1) { sjf_class_destroy(&sjt_call25); }
;
        }

        if (sjv_i <= sjv_j) {
            int32_t sjt_functionParam73;
            int32_t sjt_functionParam74;
            sjs_class* sjt_functionParam75 = 0;
            int32_t sjt_functionParam76;
            int32_t sjt_functionParam77;
            sjs_class* sjt_functionParam78 = 0;

            sjt_functionParam73 = sjv_i;
            sjf_array_class_getat(_parent, sjt_functionParam73, &sjv_tmp);
            sjt_functionParam74 = sjv_i;
            sjt_functionParam76 = sjv_j;
            sjf_array_class_getat(_parent, sjt_functionParam76, &sjt_call26);
            sjt_functionParam75 = &sjt_call26;
            sjf_array_class_setat(_parent, sjt_functionParam74, sjt_functionParam75);
            sjt_functionParam77 = sjv_j;
            sjt_functionParam78 = &sjv_tmp;
            sjf_array_class_setat(_parent, sjt_functionParam77, sjt_functionParam78);
            sjv_i = sjv_i + 1;
            sjv_j = sjv_j - 1;
        }

        sjt_while4 = sjv_i <= sjv_j;

        if (sjt_call26._refCount == 1) { sjf_class_destroy(&sjt_call26); }
;
        if (sjv_tmp._refCount == 1) { sjf_class_destroy(&sjv_tmp); }
;
    }

    if (left < sjv_j) {
        int32_t sjt_functionParam79;
        int32_t sjt_functionParam80;
        cb_class_class_i32 sjt_functionParam81;

        sjt_functionParam79 = left;
        sjt_functionParam80 = sjv_j;
        sjt_functionParam81 = cb;
        sjf_array_class__quicksortcallback(_parent, sjt_functionParam79, sjt_functionParam80, sjt_functionParam81);
    }

    if (sjv_i < right) {
        int32_t sjt_functionParam82;
        int32_t sjt_functionParam83;
        cb_class_class_i32 sjt_functionParam84;

        sjt_functionParam82 = sjv_i;
        sjt_functionParam83 = right;
        sjt_functionParam84 = cb;
        sjf_array_class__quicksortcallback(_parent, sjt_functionParam82, sjt_functionParam83, sjt_functionParam84);
    }

    if (sjv_pivot._refCount == 1) { sjf_class_destroy(&sjv_pivot); }
;
}

void sjf_array_class_asstring(sjs_array_class* _parent, sjs_string* sep, sjs_string* _return) {
    int32_t i;
    int32_t sjt_forEnd1;
    int32_t sjt_forStart1;
    sjs_string sjv_result = { -1 };

    sjv_result._refCount = 1;
    sjv_result.count = 0;
    sjv_result.data._refCount = 1;
    sjv_result.data.datasize = 0;
    sjv_result.data.data = (void*)sjg_string2;
    sjv_result.data.isglobal = true;
    sjv_result.data.count = 0;
    sjf_array_char(&sjv_result.data);
    sjv_result._isnullterminated = false;
    sjf_string(&sjv_result);
    sjt_forStart1 = 0;
    sjt_forEnd1 = _parent->count;
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
            sjf_string_copy(&sjt_funcold2, &sjv_result);
            sjt_parent21 = &sjv_result;
            sjt_functionParam45 = sep;
            sjf_string_add(sjt_parent21, sjt_functionParam45, &sjt_funcold2);
            if (sjv_result._refCount == 1) { sjf_string_destroy(&sjv_result); }
;
            sjf_string_copy(&sjv_result, &sjt_funcold2);
        }

        sjt_funcold3._refCount = 1;
        sjf_string_copy(&sjt_funcold3, &sjv_result);
        sjt_parent22 = &sjv_result;
        sjt_functionParam53 = i;
        sjf_array_class_getat(_parent, sjt_functionParam53, &sjt_call17);
        sjt_parent25 = &sjt_call17;
        sjf_class_asstring(sjt_parent25, &sjt_call12);
        sjt_functionParam46 = &sjt_call12;
        sjf_string_add(sjt_parent22, sjt_functionParam46, &sjt_funcold3);
        if (sjv_result._refCount == 1) { sjf_string_destroy(&sjv_result); }
;
        sjf_string_copy(&sjv_result, &sjt_funcold3);
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

    _return->_refCount = 1;
    sjf_string_copy(_return, &sjv_result);

    if (sjv_result._refCount == 1) { sjf_string_destroy(&sjv_result); }
;
}

void sjf_array_class_asstring_heap(sjs_array_class* _parent, sjs_string* sep, sjs_string** _return) {
    int32_t i;
    int32_t sjt_forEnd4;
    int32_t sjt_forStart4;
    sjs_string sjv_result = { -1 };

    sjv_result._refCount = 1;
    sjv_result.count = 0;
    sjv_result.data._refCount = 1;
    sjv_result.data.datasize = 0;
    sjv_result.data.data = (void*)sjg_string2;
    sjv_result.data.isglobal = true;
    sjv_result.data.count = 0;
    sjf_array_char(&sjv_result.data);
    sjv_result._isnullterminated = false;
    sjf_string(&sjv_result);
    sjt_forStart4 = 0;
    sjt_forEnd4 = _parent->count;
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
            sjf_string_copy(&sjt_funcold4, &sjv_result);
            sjt_parent26 = &sjv_result;
            sjt_functionParam54 = sep;
            sjf_string_add(sjt_parent26, sjt_functionParam54, &sjt_funcold4);
            if (sjv_result._refCount == 1) { sjf_string_destroy(&sjv_result); }
;
            sjf_string_copy(&sjv_result, &sjt_funcold4);
        }

        sjt_funcold5._refCount = 1;
        sjf_string_copy(&sjt_funcold5, &sjv_result);
        sjt_parent27 = &sjv_result;
        sjt_functionParam56 = i;
        sjf_array_class_getat(_parent, sjt_functionParam56, &sjt_call19);
        sjt_parent28 = &sjt_call19;
        sjf_class_asstring(sjt_parent28, &sjt_call18);
        sjt_functionParam55 = &sjt_call18;
        sjf_string_add(sjt_parent27, sjt_functionParam55, &sjt_funcold5);
        if (sjv_result._refCount == 1) { sjf_string_destroy(&sjv_result); }
;
        sjf_string_copy(&sjv_result, &sjt_funcold5);
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

    (*_return) = (sjs_string*)malloc(sizeof(sjs_string));
    (*_return)->_refCount = 1;
    sjf_string_copy((*_return), &sjv_result);

    if (sjv_result._refCount == 1) { sjf_string_destroy(&sjv_result); }
;
}

void sjf_array_class_copy(sjs_array_class* _this, sjs_array_class* _from) {
    _this->datasize = _from->datasize;
    _this->data = _from->data;
    _this->isglobal = _from->isglobal;
    _this->count = _from->count;
    _this->data = _from->data;
    if (!_this->isglobal && _this->data) {
        int* refcount = (int*)_this->data - 1;
        *refcount = *refcount + 1;
    }
}

void sjf_array_class_destroy(sjs_array_class* _this) {
    if (!_this->isglobal && _this->data) {
        int* refcount = (int*)_this->data - 1;
        *refcount = *refcount - 1;
        if (*refcount == 0) {
            #if !false && !true
            sjs_class* p = (sjs_class*)_this->data;
            for (int i = 0; i < _this->count; i++) {
                ;
            }
            #endif
            free(refcount);
        }
    }
}

void sjf_array_class_getat(sjs_array_class* _parent, int32_t index, sjs_class* _return) {
    if (index >= _parent->count || index < 0) {
        halt("getAt: out of bounds\n");
    }
    sjs_class* p = (sjs_class*)_parent->data;
    _return->_refCount = 1;
sjf_class_copy(_return, &p[index]);
return;;       
}

void sjf_array_class_getat_heap(sjs_array_class* _parent, int32_t index, sjs_class** _return) {
    if (index >= _parent->count || index < 0) {
        halt("getAt: out of bounds\n");
    }
    sjs_class* p = (sjs_class*)_parent->data;
    (*_return) = (sjs_class*)malloc(sizeof(sjs_class));
(*_return)->_refCount = 1;
sjf_class_copy((*_return), &p[index]);
return;;       
}

void sjf_array_class_heap(sjs_array_class* _this) {
    if (_this->datasize < 0) {
        halt("size is less than zero");
    }
    if (!_this->data) {
        _this->data = (int*)malloc(_this->datasize * sizeof(sjs_class) + sizeof(int)) + 1;
        int* refcount = (int*)_this->data - 1;
        *refcount = 1;
        if (!_this->data) {
            halt("grow: out of memory\n");
        }
    }
}

void sjf_array_class_initat(sjs_array_class* _parent, int32_t index, sjs_class* item) {
    if (index != _parent->count) {
        halt("initAt: can only initialize last element\n");     
    }
    if (index >= _parent->datasize || index < 0) {
        halt("initAt: out of bounds %d:%d\n", index, _parent->datasize);
    }
    sjs_class* p = (sjs_class*)_parent->data;
    p[index]._refCount = 1;
sjf_class_copy(&p[index], item);
;
    _parent->count = index + 1;
}

void sjf_array_class_reverse(sjs_array_class* _parent) {
    int32_t i;
    int32_t sjt_forEnd5;
    int32_t sjt_forStart5;

    sjt_forStart5 = 0;
    sjt_forEnd5 = _parent->count / 2;
    i = sjt_forStart5;
    while (i < sjt_forEnd5) {
        sjs_class sjt_call21 = { -1 };
        int32_t sjt_functionParam58;
        int32_t sjt_functionParam59;
        sjs_class* sjt_functionParam60 = 0;
        int32_t sjt_functionParam61;
        int32_t sjt_functionParam62;
        sjs_class* sjt_functionParam63 = 0;
        int32_t sjv_j;
        sjs_class sjv_tmp = { -1 };

        sjv_j = (_parent->count - i) - 1;
        sjt_functionParam58 = i;
        sjf_array_class_getat(_parent, sjt_functionParam58, &sjv_tmp);
        sjt_functionParam59 = i;
        sjt_functionParam61 = sjv_j;
        sjf_array_class_getat(_parent, sjt_functionParam61, &sjt_call21);
        sjt_functionParam60 = &sjt_call21;
        sjf_array_class_setat(_parent, sjt_functionParam59, sjt_functionParam60);
        sjt_functionParam62 = sjv_j;
        sjt_functionParam63 = &sjv_tmp;
        sjf_array_class_setat(_parent, sjt_functionParam62, sjt_functionParam63);
        i++;

        if (sjt_call21._refCount == 1) { sjf_class_destroy(&sjt_call21); }
;
        if (sjv_tmp._refCount == 1) { sjf_class_destroy(&sjv_tmp); }
;
    }
}

void sjf_array_class_setat(sjs_array_class* _parent, int32_t index, sjs_class* item) {
    if (index >= _parent->count || index < 0) {
        halt("setAt: out of bounds %d:%d\n", index, _parent->count);
    }
    sjs_class* p = (sjs_class*)_parent->data;
    ;
    p[index]._refCount = 1;
sjf_class_copy(&p[index], item);
;
}

void sjf_array_class_sort(sjs_array_class* _parent) {
    if (_parent->count > 1) {
        int32_t sjt_functionParam30;
        int32_t sjt_functionParam31;

        sjt_functionParam30 = 0;
        sjt_functionParam31 = _parent->count - 1;
        sjf_array_class__quicksort(_parent, sjt_functionParam30, sjt_functionParam31);
    }
}

void sjf_array_class_sortcb(sjs_array_class* _parent, cb_class_class_i32 cb) {
    if (_parent->count > 1) {
        int32_t sjt_functionParam85;
        int32_t sjt_functionParam86;
        cb_class_class_i32 sjt_functionParam87;

        sjt_functionParam85 = 0;
        sjt_functionParam86 = _parent->count - 1;
        sjt_functionParam87 = cb;
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
    sjt_call13.count = 1;
    sjt_call13.data._refCount = 1;
    sjt_call13.data.datasize = 1;
    sjt_call13.data.data = (void*)sjg_string3;
    sjt_call13.data.isglobal = true;
    sjt_call13.data.count = 1;
    sjf_array_char(&sjt_call13.data);
    sjt_call13._isnullterminated = false;
    sjf_string(&sjt_call13);
    sjt_parent23 = &sjt_call13;
    sjt_functionParam48 = _parent->x;
    sjt_functionParam49 = 10;
    sjf_i32_asstring(sjt_functionParam48, sjt_functionParam49, &sjt_call14);
    sjt_functionParam47 = &sjt_call14;
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
    sjt_call15.count = 1;
    sjt_call15.data._refCount = 1;
    sjt_call15.data.datasize = 1;
    sjt_call15.data.data = (void*)sjg_string3;
    sjt_call15.data.isglobal = true;
    sjt_call15.data.count = 1;
    sjf_array_char(&sjt_call15.data);
    sjt_call15._isnullterminated = false;
    sjf_string(&sjt_call15);
    sjt_parent24 = &sjt_call15;
    sjt_functionParam51 = _parent->x;
    sjt_functionParam52 = 10;
    sjf_i32_asstring(sjt_functionParam51, sjt_functionParam52, &sjt_call16);
    sjt_functionParam50 = &sjt_call16;
    sjf_string_add_heap(sjt_parent24, sjt_functionParam50, _return);

    if (sjt_call15._refCount == 1) { sjf_string_destroy(&sjt_call15); }
;
    if (sjt_call16._refCount == 1) { sjf_string_destroy(&sjt_call16); }
;
}

void sjf_class_compare(sjs_class* l, sjs_class* r, int32_t* _return) {
    int32_t sjt_functionParam89;
    int32_t sjt_functionParam90;

    sjt_functionParam89 = l->x;
    sjt_functionParam90 = r->x;
    sjf_i32_compare(sjt_functionParam89, sjt_functionParam90, _return);
}

void sjf_class_compare_callback(void * _parent, sjs_class* l, sjs_class* r, int32_t* _return) {
    sjf_class_compare(l, r, _return);
}

void sjf_class_copy(sjs_class* _this, sjs_class* _from) {
    _this->x = _from->x;
}

void sjf_class_destroy(sjs_class* _this) {
}

void sjf_class_heap(sjs_class* _this) {
}

void sjf_class_isgreater(sjs_class* _parent, sjs_class* c, bool* _return) {
    (*_return) = _parent->x > c->x;
}

void sjf_class_isless(sjs_class* _parent, sjs_class* c, bool* _return) {
    (*_return) = _parent->x < c->x;
}

void sjf_console_writeline(sjs_string* data) {
    sjs_string* sjt_parent13 = 0;

    sjt_parent13 = data;
    sjf_string_nullterminate(sjt_parent13);
    printf("%s\n", (char*)data->data.data);
}

void sjf_hash_type_bool(sjs_hash_type_bool* _this) {
    _this->_hash = kh_init(type_bool_hash_type);
}

void sjf_hash_type_bool__weakptrremovekey(sjs_hash_type_bool* _parent, int32_t key) {
    #if false
    khash_t(type_bool_hash_type)* p = (khash_t(type_bool_hash_type)*)_parent->_hash;    
    khiter_t k = kh_get(type_bool_hash_type, p, key);
    if (k != kh_end(p)) {
        kh_del(type_bool_hash_type, p, k);
    }
    #endif
}

void sjf_hash_type_bool__weakptrremovevalue(sjs_hash_type_bool* _parent, bool val) {
    #if false
    khash_t(type_bool_hash_type)* p = (khash_t(type_bool_hash_type)*)_parent->_hash;
    for (khiter_t k = kh_begin(p); k != kh_end(p); ++k) {
        if (kh_exist(p, k)) {
            bool t = kh_value(p, k);
            if (t == val) {
                kh_del(type_bool_hash_type, p, k);
            }
        }
    }
    #endif
}

void sjf_hash_type_bool_copy(sjs_hash_type_bool* _this, sjs_hash_type_bool* _from) {
    _this->_hash = _from->_hash;
    khash_t(type_bool_hash_type)* p = (khash_t(type_bool_hash_type)*)_this->_hash;
    p->refcount++;
}

void sjf_hash_type_bool_destroy(sjs_hash_type_bool* _this) {
    khash_t(type_bool_hash_type)* p = (khash_t(type_bool_hash_type)*)_this->_hash;
    p->refcount--;
    if (p->refcount == 0) {
        for (khiter_t k = kh_begin(p); k != kh_end(p); ++k) {
            if (kh_exist(p, k)) {
                #if false
                delete_cb cb = { p, (void(*)(void*, void*))sjf_hash_type_bool__weakptrremovekey };
                weakptr_cb_remove(kh_key(p, k), cb);
                #else
                ;
                #endif
                #if false
                delete_cb cb = { p, (void(*)(void*, void*))sjf_hash_type_bool__weakptrremovevalue };
                weakptr_cb_remove(kh_value(p, k), cb);
                #else
                ;
                #endif
            }
        }
        kh_destroy(type_bool_hash_type, _this->_hash);
    }
}

void sjf_hash_type_bool_heap(sjs_hash_type_bool* _this) {
    _this->_hash = kh_init(type_bool_hash_type);
}

void sjf_i32_asstring(int32_t val, int32_t base, sjs_string* _return) {
    int32_t sjv_count;
    void* sjv_data;

    sjv_count = 0;
    sjv_data = 0;
    sjv_data = (int*)malloc(sizeof(int) + sizeof(char) * 256) + 1;
    int* refcount = (int*)sjv_data - 1;
    *refcount = 1;
    char *tmp = (char*)sjv_data + 128;
    char *tp = (char*)sjv_data + 128;
    int i;
    unsigned v;
    int sign = (base == 10 && val < 0);    
    if (sign)
    v = -val;
    else
    v = (unsigned)val;
    while (v || tp == tmp)
    {
        i = v % base;
        v /= base; // v/=base uses less CPU clocks than v=v/base does
        if (i < 10)
        *tp++ = i + '0';
        else
        *tp++ = i + 'a' - 10;
    }
    int len = tp - tmp;
    char* sp = (char*)sjv_data;
    if (sign) 
    {
        *sp++ = '-';
        len++;
    }
    while (tp > tmp)
    *sp++ = *--tp;
    sjv_count = len;
    _return->_refCount = 1;
    _return->count = sjv_count;
    _return->data._refCount = 1;
    _return->data.datasize = 256;
    _return->data.data = sjv_data;
    _return->data.isglobal = false;
    _return->data.count = sjv_count;
    sjf_array_char(&_return->data);
    _return->_isnullterminated = false;
    sjf_string(_return);
}

void sjf_i32_asstring_heap(int32_t val, int32_t base, sjs_string** _return) {
    int32_t sjv_count;
    void* sjv_data;

    sjv_count = 0;
    sjv_data = 0;
    sjv_data = (int*)malloc(sizeof(int) + sizeof(char) * 256) + 1;
    int* refcount = (int*)sjv_data - 1;
    *refcount = 1;
    char *tmp = (char*)sjv_data + 128;
    char *tp = (char*)sjv_data + 128;
    int i;
    unsigned v;
    int sign = (base == 10 && val < 0);    
    if (sign)
    v = -val;
    else
    v = (unsigned)val;
    while (v || tp == tmp)
    {
        i = v % base;
        v /= base; // v/=base uses less CPU clocks than v=v/base does
        if (i < 10)
        *tp++ = i + '0';
        else
        *tp++ = i + 'a' - 10;
    }
    int len = tp - tmp;
    char* sp = (char*)sjv_data;
    if (sign) 
    {
        *sp++ = '-';
        len++;
    }
    while (tp > tmp)
    *sp++ = *--tp;
    sjv_count = len;
    (*_return) = (sjs_string*)malloc(sizeof(sjs_string));
    (*_return)->_refCount = 1;
    (*_return)->count = sjv_count;
    (*_return)->data._refCount = 1;
    (*_return)->data.datasize = 256;
    (*_return)->data.data = sjv_data;
    (*_return)->data.isglobal = false;
    (*_return)->data.count = sjv_count;
    sjf_array_char(&(*_return)->data);
    (*_return)->_isnullterminated = false;
    sjf_string_heap((*_return));
}

void sjf_i32_compare(int32_t l, int32_t r, int32_t* _return) {
    if (l == r) {
        (*_return) = 0;
    } else {
        if (l < r) {
            int32_t result4;

            result4 = -1;
            (*_return) = result4;
        } else {
            (*_return) = 1;
        }
    }
}

void sjf_log(sjs_log* _this) {
}

void sjf_log_copy(sjs_log* _this, sjs_log* _from) {
    _this->minlevel = _from->minlevel;
    sjs_hash_type_bool* copyoption1 = (_from->traceincludes._refCount != -1 ? &_from->traceincludes : 0);
    if (copyoption1 != 0) {
        _this->traceincludes._refCount = 1;
        sjf_hash_type_bool_copy(&_this->traceincludes, copyoption1);
    } else {
        _this->traceincludes._refCount = -1;
    }

    sjs_hash_type_bool* copyoption2 = (_from->debugincludes._refCount != -1 ? &_from->debugincludes : 0);
    if (copyoption2 != 0) {
        _this->debugincludes._refCount = 1;
        sjf_hash_type_bool_copy(&_this->debugincludes, copyoption2);
    } else {
        _this->debugincludes._refCount = -1;
    }

    sjs_hash_type_bool* copyoption3 = (_from->infoincludes._refCount != -1 ? &_from->infoincludes : 0);
    if (copyoption3 != 0) {
        _this->infoincludes._refCount = 1;
        sjf_hash_type_bool_copy(&_this->infoincludes, copyoption3);
    } else {
        _this->infoincludes._refCount = -1;
    }

    sjs_hash_type_bool* copyoption4 = (_from->warnincludes._refCount != -1 ? &_from->warnincludes : 0);
    if (copyoption4 != 0) {
        _this->warnincludes._refCount = 1;
        sjf_hash_type_bool_copy(&_this->warnincludes, copyoption4);
    } else {
        _this->warnincludes._refCount = -1;
    }

    sjs_hash_type_bool* copyoption5 = (_from->errorincludes._refCount != -1 ? &_from->errorincludes : 0);
    if (copyoption5 != 0) {
        _this->errorincludes._refCount = 1;
        sjf_hash_type_bool_copy(&_this->errorincludes, copyoption5);
    } else {
        _this->errorincludes._refCount = -1;
    }

    sjs_hash_type_bool* copyoption6 = (_from->fatalincludes._refCount != -1 ? &_from->fatalincludes : 0);
    if (copyoption6 != 0) {
        _this->fatalincludes._refCount = 1;
        sjf_hash_type_bool_copy(&_this->fatalincludes, copyoption6);
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
    sjs_array_char sjv_newdata = { -1 };

    if (item->count == 0) {
        _return->_refCount = 1;
        _return->count = _parent->count;
        _return->data._refCount = 1;
        sjf_array_char_copy(&_return->data, &_parent->data);
        _return->_isnullterminated = false;
        sjf_string(_return);
    } else {
        int32_t i;
        int32_t sjt_forEnd2;
        int32_t sjt_forStart2;
        int32_t sjv_newcount;

        if ((_parent->count + item->count) > (&_parent->data)->datasize) {
            int32_t sjt_functionParam36;
            sjs_array_char* sjt_parent14 = 0;

            sjt_parent14 = &_parent->data;
            sjt_functionParam36 = ((((_parent->count + item->count) - 1) / 256) + 1) * 256;
            sjf_array_char_grow(sjt_parent14, sjt_functionParam36, &sjv_newdata);
        } else {
            sjv_newdata._refCount = 1;
            sjf_array_char_copy(&sjv_newdata, &_parent->data);
        }

        sjv_newcount = _parent->count;
        sjt_forStart2 = 0;
        sjt_forEnd2 = item->count;
        i = sjt_forStart2;
        while (i < sjt_forEnd2) {
            int32_t sjt_functionParam37;
            char sjt_functionParam38;
            int32_t sjt_functionParam40;
            sjs_array_char* sjt_parent15 = 0;
            sjs_string* sjt_parent17 = 0;

            sjt_parent15 = &sjv_newdata;
            sjt_functionParam37 = sjv_newcount;
            sjt_parent17 = item;
            sjt_functionParam40 = i;
            sjf_string_getat(sjt_parent17, sjt_functionParam40, &sjt_functionParam38);
            sjf_array_char_initat(sjt_parent15, sjt_functionParam37, sjt_functionParam38);
            sjv_newcount = sjv_newcount + 1;
            i++;
        }

        _return->_refCount = 1;
        _return->count = sjv_newcount;
        _return->data._refCount = 1;
        sjf_array_char_copy(&_return->data, &sjv_newdata);
        _return->_isnullterminated = false;
        sjf_string(_return);
    }

    if (sjv_newdata._refCount == 1) { sjf_array_char_destroy(&sjv_newdata); }
;
}

void sjf_string_add_heap(sjs_string* _parent, sjs_string* item, sjs_string** _return) {
    sjs_array_char sjv_newdata = { -1 };

    if (item->count == 0) {
        (*_return) = (sjs_string*)malloc(sizeof(sjs_string));
        (*_return)->_refCount = 1;
        (*_return)->count = _parent->count;
        (*_return)->data._refCount = 1;
        sjf_array_char_copy(&(*_return)->data, &_parent->data);
        (*_return)->_isnullterminated = false;
        sjf_string_heap((*_return));
    } else {
        int32_t i;
        int32_t sjt_forEnd3;
        int32_t sjt_forStart3;
        int32_t sjv_newcount;

        if ((_parent->count + item->count) > (&_parent->data)->datasize) {
            int32_t sjt_functionParam41;
            sjs_array_char* sjt_parent18 = 0;

            sjt_parent18 = &_parent->data;
            sjt_functionParam41 = ((((_parent->count + item->count) - 1) / 256) + 1) * 256;
            sjf_array_char_grow(sjt_parent18, sjt_functionParam41, &sjv_newdata);
        } else {
            sjv_newdata._refCount = 1;
            sjf_array_char_copy(&sjv_newdata, &_parent->data);
        }

        sjv_newcount = _parent->count;
        sjt_forStart3 = 0;
        sjt_forEnd3 = item->count;
        i = sjt_forStart3;
        while (i < sjt_forEnd3) {
            int32_t sjt_functionParam42;
            char sjt_functionParam43;
            int32_t sjt_functionParam44;
            sjs_array_char* sjt_parent19 = 0;
            sjs_string* sjt_parent20 = 0;

            sjt_parent19 = &sjv_newdata;
            sjt_functionParam42 = sjv_newcount;
            sjt_parent20 = item;
            sjt_functionParam44 = i;
            sjf_string_getat(sjt_parent20, sjt_functionParam44, &sjt_functionParam43);
            sjf_array_char_initat(sjt_parent19, sjt_functionParam42, sjt_functionParam43);
            sjv_newcount = sjv_newcount + 1;
            i++;
        }

        (*_return) = (sjs_string*)malloc(sizeof(sjs_string));
        (*_return)->_refCount = 1;
        (*_return)->count = sjv_newcount;
        (*_return)->data._refCount = 1;
        sjf_array_char_copy(&(*_return)->data, &sjv_newdata);
        (*_return)->_isnullterminated = false;
        sjf_string_heap((*_return));
    }

    if (sjv_newdata._refCount == 1) { sjf_array_char_destroy(&sjv_newdata); }
;
}

void sjf_string_copy(sjs_string* _this, sjs_string* _from) {
    _this->count = _from->count;
    _this->data._refCount = 1;
    sjf_array_char_copy(&_this->data, &_from->data);
    _this->_isnullterminated = _from->_isnullterminated;
}

void sjf_string_destroy(sjs_string* _this) {
    if (_this->data._refCount == 1) { sjf_array_char_destroy(&_this->data); }
;
}

void sjf_string_getat(sjs_string* _parent, int32_t index, char* _return) {
    int32_t sjt_functionParam39;
    sjs_array_char* sjt_parent16 = 0;

    sjt_parent16 = &_parent->data;
    sjt_functionParam39 = index;
    sjf_array_char_getat(sjt_parent16, sjt_functionParam39, _return);
}

void sjf_string_heap(sjs_string* _this) {
}

void sjf_string_nullterminate(sjs_string* _parent) {
    bool result2;
    bool result3;
    sjs_array_char sjt_funcold1 = { -1 };

    result2 = !(&_parent->data)->isglobal;
    result3 = !_parent->_isnullterminated;
    if (result2 || result3) {
        int32_t sjt_functionParam33;
        char sjt_functionParam34;
        sjs_array_char* sjt_parent12 = 0;

        if ((_parent->count + 1) > (&_parent->data)->datasize) {
            int32_t sjt_functionParam32;
            sjs_array_char* sjt_parent11 = 0;

            sjt_funcold1._refCount = 1;
            sjf_array_char_copy(&sjt_funcold1, &_parent->data);
            sjt_parent11 = &_parent->data;
            sjt_functionParam32 = _parent->count + 1;
            sjf_array_char_grow(sjt_parent11, sjt_functionParam32, &sjt_funcold1);
            if (_parent->data._refCount == 1) { sjf_array_char_destroy(&_parent->data); }
;
            sjf_array_char_copy(&_parent->data, &sjt_funcold1);
        }

        sjt_parent12 = &_parent->data;
        sjt_functionParam33 = _parent->count;
        sjt_functionParam34 = '\0';
        sjf_array_char_initat(sjt_parent12, sjt_functionParam33, sjt_functionParam34);
        _parent->_isnullterminated = true;
    }

    if (sjt_funcold1._refCount == 1) { sjf_array_char_destroy(&sjt_funcold1); }
;
}

void sjf_type_hash(int32_t val, uint32_t* _return) {
    int32_t sjt_cast1;

    sjt_cast1 = val;
    (*_return) = (uint32_t)sjt_cast1;
}

void sjf_type_isequal(int32_t l, int32_t r, bool* _return) {
    (*_return) = l == r;
}

int main(int argc, char** argv) {
    sjv_loglevel_trace = 0;
    sjv_loglevel_debug = 1;
    sjv_loglevel_info = 2;
    sjv_loglevel_warn = 3;
    sjv_loglevel_error = 4;
    sjv_loglevel_fatal = 5;
    sjv_f32_pi = 3.14159265358979323846f;
    sjv_u32_maxvalue = (uint32_t)4294967295u;
    result1 = -1;
    sjv_i32_maxvalue = result1 - 2147483647;
    sjv_i32_minvalue = 2147483647;
    sjv_log_includeall._refCount = -1;
    sjv_log_excludeall._refCount = 1;
    sjv_log_excludeall._refCount = 1;
    sjf_hash_type_bool(&sjv_log_excludeall);
    sjv_log._refCount = 1;
    sjv_log.minlevel = sjv_loglevel_warn;
    sjs_hash_type_bool* copyoption7 = (sjv_log_includeall._refCount != -1 ? &sjv_log_includeall : 0);
    if (copyoption7 != 0) {
        sjv_log.traceincludes._refCount = 1;
        sjf_hash_type_bool_copy(&sjv_log.traceincludes, copyoption7);
    } else {
        sjv_log.traceincludes._refCount = -1;
    }

    sjs_hash_type_bool* copyoption8 = (sjv_log_includeall._refCount != -1 ? &sjv_log_includeall : 0);
    if (copyoption8 != 0) {
        sjv_log.debugincludes._refCount = 1;
        sjf_hash_type_bool_copy(&sjv_log.debugincludes, copyoption8);
    } else {
        sjv_log.debugincludes._refCount = -1;
    }

    sjs_hash_type_bool* copyoption9 = (sjv_log_includeall._refCount != -1 ? &sjv_log_includeall : 0);
    if (copyoption9 != 0) {
        sjv_log.infoincludes._refCount = 1;
        sjf_hash_type_bool_copy(&sjv_log.infoincludes, copyoption9);
    } else {
        sjv_log.infoincludes._refCount = -1;
    }

    sjs_hash_type_bool* copyoption10 = (sjv_log_includeall._refCount != -1 ? &sjv_log_includeall : 0);
    if (copyoption10 != 0) {
        sjv_log.warnincludes._refCount = 1;
        sjf_hash_type_bool_copy(&sjv_log.warnincludes, copyoption10);
    } else {
        sjv_log.warnincludes._refCount = -1;
    }

    sjs_hash_type_bool* copyoption11 = (sjv_log_includeall._refCount != -1 ? &sjv_log_includeall : 0);
    if (copyoption11 != 0) {
        sjv_log.errorincludes._refCount = 1;
        sjf_hash_type_bool_copy(&sjv_log.errorincludes, copyoption11);
    } else {
        sjv_log.errorincludes._refCount = -1;
    }

    sjs_hash_type_bool* copyoption12 = (sjv_log_includeall._refCount != -1 ? &sjv_log_includeall : 0);
    if (copyoption12 != 0) {
        sjv_log.fatalincludes._refCount = 1;
        sjf_hash_type_bool_copy(&sjv_log.fatalincludes, copyoption12);
    } else {
        sjv_log.fatalincludes._refCount = -1;
    }

    sjf_log(&sjv_log);
    sjv_emptystringdata = 0;
    sjv_emptystringdata = "";
    ptr_init();
    weakptr_init();
    sjv_clocks_per_sec = 0;
    sjv_clocks_per_sec = CLOCKS_PER_SEC;
    sjv_a._refCount = 1;
    sjv_a.datasize = 5;
    sjv_a.data = 0;
    sjv_a.isglobal = false;
    sjv_a.count = 0;
    sjf_array_class(&sjv_a);
    sjs_array_class* array1;
    array1 = &sjv_a;
    sjt_parent1 = array1;
    sjt_functionParam1 = 0;
    sjt_call1._refCount = 1;
    sjt_call1.x = 1;
    sjf_class(&sjt_call1);
    sjt_functionParam2 = &sjt_call1;
    sjf_array_class_initat(sjt_parent1, sjt_functionParam1, sjt_functionParam2);
    sjt_parent2 = array1;
    sjt_functionParam3 = 1;
    sjt_call2._refCount = 1;
    sjt_call2.x = 4;
    sjf_class(&sjt_call2);
    sjt_functionParam4 = &sjt_call2;
    sjf_array_class_initat(sjt_parent2, sjt_functionParam3, sjt_functionParam4);
    sjt_parent3 = array1;
    sjt_functionParam5 = 2;
    sjt_call3._refCount = 1;
    sjt_call3.x = 5;
    sjf_class(&sjt_call3);
    sjt_functionParam6 = &sjt_call3;
    sjf_array_class_initat(sjt_parent3, sjt_functionParam5, sjt_functionParam6);
    sjt_parent4 = array1;
    sjt_functionParam7 = 3;
    sjt_call4._refCount = 1;
    sjt_call4.x = 6;
    sjf_class(&sjt_call4);
    sjt_functionParam8 = &sjt_call4;
    sjf_array_class_initat(sjt_parent4, sjt_functionParam7, sjt_functionParam8);
    sjt_parent5 = array1;
    sjt_functionParam9 = 4;
    sjt_call5._refCount = 1;
    sjt_call5.x = 2;
    sjf_class(&sjt_call5);
    sjt_functionParam10 = &sjt_call5;
    sjf_array_class_initat(sjt_parent5, sjt_functionParam9, sjt_functionParam10);
    sjt_parent10 = &sjv_a;
    sjf_array_class_sort(sjt_parent10);
    sjt_parent29 = &sjv_a;
    sjt_call20._refCount = 1;
    sjt_call20.count = 2;
    sjt_call20.data._refCount = 1;
    sjt_call20.data.datasize = 2;
    sjt_call20.data.data = (void*)sjg_string1;
    sjt_call20.data.isglobal = true;
    sjt_call20.data.count = 2;
    sjf_array_char(&sjt_call20.data);
    sjt_call20._isnullterminated = false;
    sjf_string(&sjt_call20);
    sjt_functionParam57 = &sjt_call20;
    sjf_array_class_asstring(sjt_parent29, sjt_functionParam57, &sjt_call11);
    sjt_functionParam35 = &sjt_call11;
    sjf_console_writeline(sjt_functionParam35);
    sjt_parent30 = &sjv_a;
    sjf_array_class_reverse(sjt_parent30);
    sjt_parent31 = &sjv_a;
    sjt_call23._refCount = 1;
    sjt_call23.count = 2;
    sjt_call23.data._refCount = 1;
    sjt_call23.data.datasize = 2;
    sjt_call23.data.data = (void*)sjg_string1;
    sjt_call23.data.isglobal = true;
    sjt_call23.data.count = 2;
    sjf_array_char(&sjt_call23.data);
    sjt_call23._isnullterminated = false;
    sjf_string(&sjt_call23);
    sjt_functionParam65 = &sjt_call23;
    sjf_array_class_asstring(sjt_parent31, sjt_functionParam65, &sjt_call22);
    sjt_functionParam64 = &sjt_call22;
    sjf_console_writeline(sjt_functionParam64);
    sjt_parent32 = &sjv_a;
    sjt_functionParam88._parent = (sjs_object*)1;
    sjt_functionParam88._cb = (void(*)(sjs_object*,sjs_class*,sjs_class*, int32_t*))sjf_class_compare_callback;
    sjf_array_class_sortcb(sjt_parent32, sjt_functionParam88);
    sjt_parent33 = &sjv_a;
    sjt_call28._refCount = 1;
    sjt_call28.count = 2;
    sjt_call28.data._refCount = 1;
    sjt_call28.data.datasize = 2;
    sjt_call28.data.data = (void*)sjg_string1;
    sjt_call28.data.isglobal = true;
    sjt_call28.data.count = 2;
    sjf_array_char(&sjt_call28.data);
    sjt_call28._isnullterminated = false;
    sjf_string(&sjt_call28);
    sjt_functionParam92 = &sjt_call28;
    sjf_array_class_asstring(sjt_parent33, sjt_functionParam92, &sjt_call27);
    sjt_functionParam91 = &sjt_call27;
    sjf_console_writeline(sjt_functionParam91);
    main_destroy();
    return 0;
}

void main_destroy() {

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
    if (sjv_a._refCount == 1) { sjf_array_class_destroy(&sjv_a); }
;
    if (sjv_log._refCount == 1) { sjf_log_destroy(&sjv_log); }
;
    if (sjv_log_excludeall._refCount == 1) { sjf_hash_type_bool_destroy(&sjv_log_excludeall); }
;
    if (sjv_log_includeall._refCount == 1) { sjf_hash_type_bool_destroy(&sjv_log_includeall); }
;
}
