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
const char* sjg_string1 = "Shall we play\n";
const char* sjg_string2 = "Too high\n";
const char* sjg_string3 = "Too Low\n";
const char* sjg_string4 = "Correct\n";

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
#define sjs_log_typeId 3
#define sjs_array_char_typeId 4
#define sjs_string_typeId 5

typedef struct td_sjs_object sjs_object;
typedef struct td_sjs_interface sjs_interface;
typedef struct td_sjs_log sjs_log;
typedef struct td_sjs_array_char sjs_array_char;
typedef struct td_sjs_string sjs_string;

struct td_sjs_object {
    intptr_t _refCount;
};

struct td_sjs_interface {
    sjs_object* _parent;
    void* _vtbl;
};

struct td_sjs_log {
    int _refCount;
    int32_t minlevel;
};

struct td_sjs_array_char {
    int _refCount;
    int32_t datasize;
    void* data;
    bool _isglobal;
    int32_t count;
};

struct td_sjs_string {
    int _refCount;
    int32_t count;
    sjs_array_char data;
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
int32_t sjv_loglevel_debug;
int32_t sjv_loglevel_error;
int32_t sjv_loglevel_fatal;
int32_t sjv_loglevel_info;
int32_t sjv_loglevel_trace;
int32_t sjv_loglevel_warn;

int32_t result1;
bool result2;
sjs_string sjt_call1 = { -1 };
sjs_string sjt_call4 = { -1 };
sjs_string* sjt_functionParam1 = 0;
sjs_string* sjt_functionParam5 = 0;
int32_t sjt_math1;
int32_t sjt_math2;
int32_t sjt_math3;
int32_t sjt_math4;
int32_t sjt_math5;
int32_t sjt_math6;
int32_t sjt_negate1;
bool sjt_not1;
bool sjt_while1;
void* sjv_emptystringdata;
float sjv_f32_pi;
int32_t sjv_i32_maxvalue;
int32_t sjv_i32_minvalue;
bool sjv_iscorrect;
sjs_log sjv_log = { -1 };
int32_t sjv_num;
uint32_t sjv_u32_maxvalue;

void sjf_array_char(sjs_array_char* _this);
void sjf_array_char_copy(sjs_array_char* _this, sjs_array_char* _from);
void sjf_array_char_destroy(sjs_array_char* _this);
void sjf_array_char_heap(sjs_array_char* _this);
void sjf_console_readline(sjs_string* _return);
void sjf_console_readline_heap(sjs_string** _return);
void sjf_console_write(sjs_string* data);
void sjf_i32_random(int32_t* _return);
void sjf_log(sjs_log* _this);
void sjf_log_copy(sjs_log* _this, sjs_log* _from);
void sjf_log_destroy(sjs_log* _this);
void sjf_log_heap(sjs_log* _this);
void sjf_string(sjs_string* _this);
void sjf_string_asi32(sjs_string* text, int32_t* _return);
void sjf_string_copy(sjs_string* _this, sjs_string* _from);
void sjf_string_destroy(sjs_string* _this);
void sjf_string_heap(sjs_string* _this);
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
void sjf_array_char(sjs_array_char* _this) {
    if (_this->datasize < 0) {
        halt("size is less than zero");
    }
    if (!_this->data) {
        _this->data = malloc(_this->datasize * sizeof(char));
        if (!_this->data) {
            halt("grow: out of memory\n");
        }
    }
}

void sjf_array_char_copy(sjs_array_char* _this, sjs_array_char* _from) {
    _this->datasize = _from->datasize;
    _this->data = _from->data;
    _this->_isglobal = _from->_isglobal;
    _this->count = _from->count;
    _this->data = _from->data;
    if (!_this->_isglobal && _this->data) {
        ptr_retain(_this->data);
    }
}

void sjf_array_char_destroy(sjs_array_char* _this) {
    if (!_this->_isglobal && _this->data) {
        if (ptr_release(_this->data)) {
            char* p = (char*)_this->data;
            for (int i = 0; i < _this->count; i++) {
                ;
            }
            free(p);
        }
    }
}

void sjf_array_char_heap(sjs_array_char* _this) {
    if (_this->datasize < 0) {
        halt("size is less than zero");
    }
    if (!_this->data) {
        _this->data = malloc(_this->datasize * sizeof(char));
        if (!_this->data) {
            halt("grow: out of memory\n");
        }
    }
}

void sjf_console_readline(sjs_string* _return) {
    int32_t sjt_math7;
    int32_t sjt_math8;
    void* sjv_console_data;
    int32_t sjv_console_size;

    sjv_console_data = 0;
    sjv_console_size = 1024;
    char* str = (char*)malloc(size);
    int index = 0;
    char ch = ' ';
    do {
        ch = getchar();
        if (ch != '\n') {
            str[index] = ch;
            index++;
            if (index >= size) {
                size *= 2;
                str = (char*)realloc(str, size);
            }
        }
    } while (ch != '\n');
    str[index] = 0;
    index++;
    data = (void*)str;
    size = index;
    _return->_refCount = 1;
    sjt_math7 = sjv_console_size;
    sjt_math8 = 1;
    _return->count = sjt_math7 - sjt_math8;
    _return->data._refCount = 1;
    _return->data.datasize = sjv_console_size;
    _return->data.data = sjv_console_data;
    _return->data._isglobal = false;
    _return->data.count = sjv_console_size;
    sjf_array_char(&_return->data);
    sjf_string(_return);
}

void sjf_console_readline_heap(sjs_string** _return) {
    int32_t sjt_math10;
    int32_t sjt_math9;
    void* sjv_console_data;
    int32_t sjv_console_size;

    sjv_console_data = 0;
    sjv_console_size = 1024;
    char* str = (char*)malloc(size);
    int index = 0;
    char ch = ' ';
    do {
        ch = getchar();
        if (ch != '\n') {
            str[index] = ch;
            index++;
            if (index >= size) {
                size *= 2;
                str = (char*)realloc(str, size);
            }
        }
    } while (ch != '\n');
    str[index] = 0;
    index++;
    data = (void*)str;
    size = index;
    (*_return) = (sjs_string*)malloc(sizeof(sjs_string));
    (*_return)->_refCount = 1;
    sjt_math9 = sjv_console_size;
    sjt_math10 = 1;
    (*_return)->count = sjt_math9 - sjt_math10;
    (*_return)->data._refCount = 1;
    (*_return)->data.datasize = sjv_console_size;
    (*_return)->data.data = sjv_console_data;
    (*_return)->data._isglobal = false;
    (*_return)->data.count = sjv_console_size;
    sjf_array_char(&(*_return)->data);
    sjf_string_heap((*_return));
}

void sjf_console_write(sjs_string* data) {
    printf("%s", (char*)data->data.data);
}

void sjf_i32_random(int32_t* _return) {
    int32_t sjv_x;

    sjv_x = 0;
    sjv_x = rand();
    (*_return) = sjv_x;
}

void sjf_log(sjs_log* _this) {
}

void sjf_log_copy(sjs_log* _this, sjs_log* _from) {
    _this->minlevel = _from->minlevel;
}

void sjf_log_destroy(sjs_log* _this) {
}

void sjf_log_heap(sjs_log* _this) {
}

void sjf_string(sjs_string* _this) {
}

void sjf_string_asi32(sjs_string* text, int32_t* _return) {
    int32_t sjv_x;

    sjv_x = 0;
    char* e;
    int v = (int)strtol((char*)text->data.data, &e, 10);
    if (*e != '\0') {
        sjv_x = 0;
    }
    else {
        sjv_x = v;
    }
    (*_return) = sjv_x;
}

void sjf_string_copy(sjs_string* _this, sjs_string* _from) {
    _this->count = _from->count;
    _this->data._refCount = 1;
    sjf_array_char_copy(&_this->data, &_from->data);
}

void sjf_string_destroy(sjs_string* _this) {
    if (_this->data._refCount == 1) { sjf_array_char_destroy(&_this->data); }
;
}

void sjf_string_heap(sjs_string* _this) {
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
    sjt_negate1 = 1;
    result1 = -sjt_negate1;
    sjt_math1 = result1;
    sjt_math2 = 2147483647;
    sjv_i32_maxvalue = sjt_math1 - sjt_math2;
    sjv_i32_minvalue = 2147483647;
    sjv_log._refCount = 1;
    sjv_log.minlevel = sjv_loglevel_warn;
    sjf_log(&sjv_log);
    sjv_emptystringdata = 0;
    sjv_emptystringdata = "";
    ptr_init();
    weakptr_init();
    sjt_call1._refCount = 1;
    sjt_call1.count = 15;
    sjt_call1.data._refCount = 1;
    sjt_call1.data.datasize = 16;
    sjt_call1.data.data = (void*)sjg_string1;
    sjt_call1.data._isglobal = true;
    sjt_call1.data.count = 16;
    sjf_array_char(&sjt_call1.data);
    sjf_string(&sjt_call1);
    sjt_functionParam1 = &sjt_call1;
    sjf_console_write(sjt_functionParam1);
    sjf_i32_random(&sjt_math5);
    sjt_math6 = 10;
    sjt_math3 = sjt_math5 % sjt_math6;
    sjt_math4 = 1;
    sjv_num = sjt_math3 + sjt_math4;
    sjv_iscorrect = false;
    sjt_not1 = sjv_iscorrect;
    result2 = !sjt_not1;
    sjt_while1 = result2;
    while (sjt_while1) {
        bool result3;
        sjs_string sjt_call2 = { -1 };
        sjs_string sjt_call3 = { -1 };
        int32_t sjt_compare1;
        int32_t sjt_compare2;
        sjs_string* sjt_functionParam2 = 0;
        bool sjt_ifElse1;
        bool sjt_not2;
        int32_t sjv_guess;
        sjs_string sjv_str = { -1 };

        sjf_console_readline(&sjv_str);
        sjt_functionParam2 = &sjv_str;
        sjf_string_asi32(sjt_functionParam2, &sjv_guess);
        sjt_compare1 = sjv_guess;
        sjt_compare2 = sjv_num;
        sjt_ifElse1 = sjt_compare1 < sjt_compare2;
        if (sjt_ifElse1) {
            sjs_string* sjt_functionParam3 = 0;

            sjt_call2._refCount = 1;
            sjt_call2.count = 9;
            sjt_call2.data._refCount = 1;
            sjt_call2.data.datasize = 10;
            sjt_call2.data.data = (void*)sjg_string3;
            sjt_call2.data._isglobal = true;
            sjt_call2.data.count = 10;
            sjf_array_char(&sjt_call2.data);
            sjf_string(&sjt_call2);
            sjt_functionParam3 = &sjt_call2;
            sjf_console_write(sjt_functionParam3);
            sjv_iscorrect = false;
        } else {
            int32_t sjt_compare3;
            int32_t sjt_compare4;
            bool sjt_ifElse2;

            sjt_compare3 = sjv_guess;
            sjt_compare4 = sjv_num;
            sjt_ifElse2 = sjt_compare3 > sjt_compare4;
            if (sjt_ifElse2) {
                sjs_string* sjt_functionParam4 = 0;

                sjt_call3._refCount = 1;
                sjt_call3.count = 10;
                sjt_call3.data._refCount = 1;
                sjt_call3.data.datasize = 11;
                sjt_call3.data.data = (void*)sjg_string2;
                sjt_call3.data._isglobal = true;
                sjt_call3.data.count = 11;
                sjf_array_char(&sjt_call3.data);
                sjf_string(&sjt_call3);
                sjt_functionParam4 = &sjt_call3;
                sjf_console_write(sjt_functionParam4);
                sjv_iscorrect = false;
            } else {
                sjv_iscorrect = true;
            }
        }

        sjt_not2 = sjv_iscorrect;
        result3 = !sjt_not2;
        sjt_while1 = result3;

        if (sjt_call2._refCount == 1) { sjf_string_destroy(&sjt_call2); }
;
        if (sjt_call3._refCount == 1) { sjf_string_destroy(&sjt_call3); }
;
        if (sjv_str._refCount == 1) { sjf_string_destroy(&sjv_str); }
;
    }

    sjt_call4._refCount = 1;
    sjt_call4.count = 9;
    sjt_call4.data._refCount = 1;
    sjt_call4.data.datasize = 10;
    sjt_call4.data.data = (void*)sjg_string4;
    sjt_call4.data._isglobal = true;
    sjt_call4.data.count = 10;
    sjf_array_char(&sjt_call4.data);
    sjf_string(&sjt_call4);
    sjt_functionParam5 = &sjt_call4;
    sjf_console_write(sjt_functionParam5);
    main_destroy();
    #ifdef _DEBUG
    printf("\npress return to end\n");
    getchar();
    #endif
    return 0;
}

void main_destroy() {

    if (sjt_call1._refCount == 1) { sjf_string_destroy(&sjt_call1); }
;
    if (sjt_call4._refCount == 1) { sjf_string_destroy(&sjt_call4); }
;
    if (sjv_log._refCount == 1) { sjf_log_destroy(&sjv_log); }
;
}
