#include <lib/common/common.h>

const char* sjg_string1 = "false";
const char* sjg_string2 = "true";

#define sjs_log_typeId 15
#define sjs_class_typeId 16
#define sjs_array_char_typeId 20
#define sjs_string_typeId 18

typedef struct td_sjs_log sjs_log;
typedef struct td_sjs_class sjs_class;
typedef struct td_sjs_array_char sjs_array_char;
typedef struct td_sjs_string sjs_string;

struct td_sjs_log {
    int _refCount;
    int32_t minlevel;
};

struct td_sjs_class {
    int _refCount;
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

int32_t sjv_loglevel_debug;
int32_t sjv_loglevel_error;
int32_t sjv_loglevel_fatal;
int32_t sjv_loglevel_info;
int32_t sjv_loglevel_trace;
int32_t sjv_loglevel_warn;

int32_t result1;
sjs_string sjt_call2 = { -1 };
sjs_string sjt_call3 = { -1 };
sjs_string sjt_call4 = { -1 };
sjs_string sjt_call5 = { -1 };
sjs_string sjt_call6 = { -1 };
sjs_string sjt_call7 = { -1 };
sjs_class* sjt_funcold1 = 0;
sjs_string* sjt_functionParam10 = 0;
bool sjt_functionParam11;
sjs_string* sjt_functionParam12 = 0;
bool sjt_functionParam13;
sjs_string* sjt_functionParam14 = 0;
bool sjt_functionParam15;
sjs_string* sjt_functionParam4 = 0;
bool sjt_functionParam5;
sjs_string* sjt_functionParam6 = 0;
bool sjt_functionParam7;
sjs_string* sjt_functionParam8 = 0;
bool sjt_functionParam9;
sjs_class* sjv_c = 0;
int32_t sjv_clocks_per_sec;
sjs_class* sjv_d = 0;
sjs_class* sjv_e = 0;
void* sjv_emptystringdata;
float sjv_f32_pi;
int32_t sjv_i32_maxvalue;
int32_t sjv_i32_minvalue;
sjs_log sjv_log = { -1 };
uint32_t sjv_u32_maxvalue;

void sjf_array_char(sjs_array_char* _this);
void sjf_array_char_copy(sjs_array_char* _this, sjs_array_char* _from);
void sjf_array_char_destroy(sjs_array_char* _this);
void sjf_array_char_grow(sjs_array_char* _parent, int32_t newsize, sjs_array_char* _return);
void sjf_array_char_grow_heap(sjs_array_char* _parent, int32_t newsize, sjs_array_char** _return);
void sjf_array_char_heap(sjs_array_char* _this);
void sjf_array_char_initat(sjs_array_char* _parent, int32_t index, char item);
void sjf_bool_asstring(bool val, sjs_string* _return);
void sjf_bool_asstring_heap(bool val, sjs_string** _return);
void sjf_class(sjs_class* _this);
void sjf_class_copy(sjs_class* _this, sjs_class* _from);
void sjf_class_destroy(sjs_class* _this);
void sjf_class_heap(sjs_class* _this);
void sjf_debug_writeline(sjs_string* data);
void sjf_log(sjs_log* _this);
void sjf_log_copy(sjs_log* _this, sjs_log* _from);
void sjf_log_destroy(sjs_log* _this);
void sjf_log_heap(sjs_log* _this);
void sjf_string(sjs_string* _this);
void sjf_string_copy(sjs_string* _this, sjs_string* _from);
void sjf_string_destroy(sjs_string* _this);
void sjf_string_heap(sjs_string* _this);
void sjf_string_nullterminate(sjs_string* _parent);
void main_destroy(void);

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

void sjf_bool_asstring(bool val, sjs_string* _return) {
    if (val) {
        _return->_refCount = 1;
        _return->count = 4;
        _return->data._refCount = 1;
        _return->data.datasize = 4;
        _return->data.data = (void*)sjg_string2;
        _return->data.isglobal = true;
        _return->data.count = 4;
        sjf_array_char(&_return->data);
        _return->_isnullterminated = false;
        sjf_string(_return);
    } else {
        _return->_refCount = 1;
        _return->count = 5;
        _return->data._refCount = 1;
        _return->data.datasize = 5;
        _return->data.data = (void*)sjg_string1;
        _return->data.isglobal = true;
        _return->data.count = 5;
        sjf_array_char(&_return->data);
        _return->_isnullterminated = false;
        sjf_string(_return);
    }
}

void sjf_bool_asstring_heap(bool val, sjs_string** _return) {
    if (val) {
        (*_return) = (sjs_string*)malloc(sizeof(sjs_string));
        (*_return)->_refCount = 1;
        (*_return)->count = 4;
        (*_return)->data._refCount = 1;
        (*_return)->data.datasize = 4;
        (*_return)->data.data = (void*)sjg_string2;
        (*_return)->data.isglobal = true;
        (*_return)->data.count = 4;
        sjf_array_char(&(*_return)->data);
        (*_return)->_isnullterminated = false;
        sjf_string_heap((*_return));
    } else {
        (*_return) = (sjs_string*)malloc(sizeof(sjs_string));
        (*_return)->_refCount = 1;
        (*_return)->count = 5;
        (*_return)->data._refCount = 1;
        (*_return)->data.datasize = 5;
        (*_return)->data.data = (void*)sjg_string1;
        (*_return)->data.isglobal = true;
        (*_return)->data.count = 5;
        sjf_array_char(&(*_return)->data);
        (*_return)->_isnullterminated = false;
        sjf_string_heap((*_return));
    }
}

void sjf_class(sjs_class* _this) {
}

void sjf_class_copy(sjs_class* _this, sjs_class* _from) {
}

void sjf_class_destroy(sjs_class* _this) {
}

void sjf_class_heap(sjs_class* _this) {
}

void sjf_debug_writeline(sjs_string* data) {
    sjs_string* sjt_parent3 = 0;

    sjt_parent3 = data;
    sjf_string_nullterminate(sjt_parent3);
    debugout("%s\n", (char*)data->data.data);
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

void sjf_string_heap(sjs_string* _this) {
}

void sjf_string_nullterminate(sjs_string* _parent) {
    bool result2;
    bool result3;
    sjs_array_char sjt_call1 = { -1 };

    result2 = !(&_parent->data)->isglobal;
    result3 = !_parent->_isnullterminated;
    if (result2 || result3) {
        int32_t sjt_functionParam2;
        char sjt_functionParam3;
        sjs_array_char* sjt_parent2 = 0;

        if ((_parent->count + 1) > (&_parent->data)->datasize) {
            int32_t sjt_functionParam1;
            sjs_array_char* sjt_parent1 = 0;

            sjt_parent1 = &_parent->data;
            sjt_functionParam1 = _parent->count + 1;
            sjf_array_char_grow(sjt_parent1, sjt_functionParam1, &sjt_call1);
            if (_parent->data._refCount == 1) { sjf_array_char_destroy(&_parent->data); }
;
            _parent->data._refCount = 1;
            sjf_array_char_copy(&_parent->data, (&sjt_call1));
        }

        sjt_parent2 = &_parent->data;
        sjt_functionParam2 = _parent->count;
        sjt_functionParam3 = '\0';
        sjf_array_char_initat(sjt_parent2, sjt_functionParam2, sjt_functionParam3);
        _parent->_isnullterminated = true;
    }

    if (sjt_call1._refCount == 1) { sjf_array_char_destroy(&sjt_call1); }
;
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
    sjv_log._refCount = 1;
    sjv_log.minlevel = sjv_loglevel_warn;
    sjf_log(&sjv_log);
    sjv_emptystringdata = 0;
    sjv_emptystringdata = "";
    ptr_init();
    weakptr_init();
    sjv_clocks_per_sec = 0;
    sjv_clocks_per_sec = CLOCKS_PER_SEC;
    sjv_c = (sjs_class*)malloc(sizeof(sjs_class));
    sjv_c->_refCount = 1;
    sjf_class_heap(sjv_c);
    sjv_d = sjv_c;
    delete_cb weakptrcb1 = { &sjv_d, weakptr_clear };
    if (sjv_d != 0) { weakptr_cb_add(sjv_d, weakptrcb1); }
    sjv_e = sjv_c;
    delete_cb weakptrcb2 = { &sjv_e, weakptr_clear };
    if (sjv_e != 0) { weakptr_cb_add(sjv_e, weakptrcb2); }
    sjt_functionParam5 = (sjv_d == 0);
    sjf_bool_asstring(sjt_functionParam5, &sjt_call2);
    sjt_functionParam4 = &sjt_call2;
    sjf_debug_writeline(sjt_functionParam4);
    sjt_functionParam7 = (sjv_e == 0);
    sjf_bool_asstring(sjt_functionParam7, &sjt_call3);
    sjt_functionParam6 = &sjt_call3;
    sjf_debug_writeline(sjt_functionParam6);
    delete_cb weakptrcb3 = { &sjv_e, weakptr_clear };
    if (sjv_e != 0) { weakptr_cb_remove(sjv_e, weakptrcb3); }
    delete_cb weakptrcb4 = { &sjv_e, weakptr_clear };
    if (sjv_e != 0) { weakptr_cb_remove(sjv_e, weakptrcb4); }
    sjv_e = 0;
    delete_cb weakptrcb5 = { &sjv_e, weakptr_clear };
    if (sjv_e != 0) { weakptr_cb_add(sjv_e, weakptrcb5); }
    sjt_functionParam9 = (sjv_d == 0);
    sjf_bool_asstring(sjt_functionParam9, &sjt_call4);
    sjt_functionParam8 = &sjt_call4;
    sjf_debug_writeline(sjt_functionParam8);
    sjt_functionParam11 = (sjv_e == 0);
    sjf_bool_asstring(sjt_functionParam11, &sjt_call5);
    sjt_functionParam10 = &sjt_call5;
    sjf_debug_writeline(sjt_functionParam10);
    sjt_funcold1 = sjv_c;
    sjv_c = (sjs_class*)malloc(sizeof(sjs_class));
    sjv_c->_refCount = 1;
    sjf_class_heap(sjv_c);
    sjt_funcold1->_refCount--;
    if (sjt_funcold1->_refCount <= 0) {
        weakptr_release(sjt_funcold1);
        sjf_class_destroy(sjt_funcold1);
        free(sjt_funcold1);
    }

    sjt_functionParam13 = (sjv_d == 0);
    sjf_bool_asstring(sjt_functionParam13, &sjt_call6);
    sjt_functionParam12 = &sjt_call6;
    sjf_debug_writeline(sjt_functionParam12);
    sjt_functionParam15 = (sjv_e == 0);
    sjf_bool_asstring(sjt_functionParam15, &sjt_call7);
    sjt_functionParam14 = &sjt_call7;
    sjf_debug_writeline(sjt_functionParam14);
    main_destroy();
    return 0;
}

void main_destroy() {

    sjv_c->_refCount--;
    if (sjv_c->_refCount <= 0) {
        weakptr_release(sjv_c);
        sjf_class_destroy(sjv_c);
        free(sjv_c);
    }
    delete_cb weakptrcb6 = { &sjv_d, weakptr_clear };
    if (sjv_d != 0) { weakptr_cb_remove(sjv_d, weakptrcb6); }
    delete_cb weakptrcb7 = { &sjv_e, weakptr_clear };
    if (sjv_e != 0) { weakptr_cb_remove(sjv_e, weakptrcb7); }
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
    if (sjt_call7._refCount == 1) { sjf_string_destroy(&sjt_call7); }
;
    if (sjv_log._refCount == 1) { sjf_log_destroy(&sjv_log); }
;
}
