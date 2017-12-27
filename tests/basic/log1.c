#include <lib/common/common.h>

const char* sjg_string1 = "[";
const char* sjg_string10 = "hello";
const char* sjg_string2 = "trace";
const char* sjg_string3 = "debug";
const char* sjg_string4 = "info";
const char* sjg_string5 = "warn";
const char* sjg_string6 = "error";
const char* sjg_string7 = "fatal";
const char* sjg_string8 = "";
const char* sjg_string9 = "] ";

#define sjs_log_typeId 1
#define sjs_array_char_typeId 2
#define sjs_string_typeId 3
#define cb_string_heap_string_typeId 4
#define cb_string_heap_string_heap_typeId 5
#define sjs_lambda1_typeId 6

typedef struct td_sjs_log sjs_log;
typedef struct td_sjs_array_char sjs_array_char;
typedef struct td_sjs_string sjs_string;
typedef struct td_cb_string_heap_string cb_string_heap_string;
typedef struct td_cb_string_heap_string_heap cb_string_heap_string_heap;
typedef struct td_sjs_lambda1 sjs_lambda1;

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

struct td_cb_string_heap_string {
    sjs_object* _parent;
    void (*_cb)(sjs_object* _parent, sjs_string* _return);
    void (*_cb_heap)(sjs_object* _parent, sjs_string** _return);
};

struct td_cb_string_heap_string_heap {
    cb_string_heap_string inner;
    void (*_destroy)(sjs_object*);
};

struct td_sjs_lambda1 {
    int _refCount;
};

int32_t sjv_loglevel_debug;
int32_t sjv_loglevel_error;
int32_t sjv_loglevel_fatal;
int32_t sjv_loglevel_info;
int32_t sjv_loglevel_trace;
int32_t sjv_loglevel_warn;

int32_t result1;
sjs_lambda1 sjt_call8 = { -1 };
cb_string_heap_string sjt_functionParam27;
sjs_log* sjt_parent17 = 0;
void* sjv_emptystringdata;
float sjv_f32_pi;
int32_t sjv_i32_maxvalue;
int32_t sjv_i32_minvalue;
sjs_log sjv_log = { -1 };
uint32_t sjv_u32_maxvalue;

void sjf_array_char(sjs_array_char* _this);
void sjf_array_char_copy(sjs_array_char* _this, sjs_array_char* _from);
void sjf_array_char_destroy(sjs_array_char* _this);
void sjf_array_char_getat(sjs_array_char* _parent, int32_t index, char* _return);
void sjf_array_char_grow(sjs_array_char* _parent, int32_t newsize, sjs_array_char* _return);
void sjf_array_char_grow_heap(sjs_array_char* _parent, int32_t newsize, sjs_array_char** _return);
void sjf_array_char_heap(sjs_array_char* _this);
void sjf_array_char_initat(sjs_array_char* _parent, int32_t index, char item);
void sjf_array_char_setat(sjs_array_char* _parent, int32_t index, char item);
void sjf_debug_writeline(sjs_string* data);
void sjf_lambda1(sjs_lambda1* _this);
void sjf_lambda1_copy(sjs_lambda1* _this, sjs_lambda1* _from);
void sjf_lambda1_destroy(sjs_lambda1* _this);
void sjf_lambda1_heap(sjs_lambda1* _this);
void sjf_lambda1_invoke(sjs_lambda1* _parent, sjs_string* _return);
void sjf_lambda1_invoke_heap(sjs_lambda1* _parent, sjs_string** _return);
void sjf_log(sjs_log* _this);
void sjf_log__write(sjs_log* _parent, int32_t level, cb_string_heap_string cb);
void sjf_log_copy(sjs_log* _this, sjs_log* _from);
void sjf_log_destroy(sjs_log* _this);
void sjf_log_heap(sjs_log* _this);
void sjf_log_info(sjs_log* _parent, cb_string_heap_string cb);
void sjf_loglevel_asstring(int32_t e, sjs_string* _return);
void sjf_string(sjs_string* _this);
void sjf_string_add(sjs_string* _parent, sjs_string* item, sjs_string* _return);
void sjf_string_add_heap(sjs_string* _parent, sjs_string* item, sjs_string** _return);
void sjf_string_copy(sjs_string* _this, sjs_string* _from);
void sjf_string_destroy(sjs_string* _this);
void sjf_string_getat(sjs_string* _parent, int32_t index, char* _return);
void sjf_string_heap(sjs_string* _this);
void main_destroy(void);

#include <lib/common/common.c>
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
        sjv_newdata = malloc(newsize * sizeof(char));
        if (!_parent->data) {
            halt("grow: out of memory\n");
        }
        char* p = (char*)_parent->data;
        char* newp = (char*)sjv_newdata;
        int count = _parent->count;
        for (int i = 0; i < count; i++) {
            newp[i] = p[i];
;
        }
    }
    _return->_refCount = 1;
    _return->datasize = newsize;
    _return->data = sjv_newdata;
    _return->_isglobal = false;
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
        sjv_newdata = malloc(newsize * sizeof(char));
        if (!_parent->data) {
            halt("grow: out of memory\n");
        }
        char* p = (char*)_parent->data;
        char* newp = (char*)sjv_newdata;
        int count = _parent->count;
        for (int i = 0; i < count; i++) {
            newp[i] = p[i];
;
        }
    }
    (*_return) = (sjs_array_char*)malloc(sizeof(sjs_array_char));
    (*_return)->_refCount = 1;
    (*_return)->datasize = newsize;
    (*_return)->data = sjv_newdata;
    (*_return)->_isglobal = false;
    (*_return)->count = _parent->count;
    sjf_array_char_heap((*_return));
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

void sjf_array_char_setat(sjs_array_char* _parent, int32_t index, char item) {
    if (index >= _parent->count || index < 0) {
        halt("setAt: out of bounds %d:%d\n", index, _parent->count);
    }
    char* p = (char*)_parent->data;
    ;
    p[index] = item;
;
}

void sjf_debug_writeline(sjs_string* data) {
    debugout("%s\n", (char*)data->data.data);
}

void sjf_lambda1(sjs_lambda1* _this) {
}

void sjf_lambda1_copy(sjs_lambda1* _this, sjs_lambda1* _from) {
}

void sjf_lambda1_destroy(sjs_lambda1* _this) {
}

void sjf_lambda1_heap(sjs_lambda1* _this) {
}

void sjf_lambda1_invoke(sjs_lambda1* _parent, sjs_string* _return) {
    _return->_refCount = 1;
    _return->count = 5;
    _return->data._refCount = 1;
    _return->data.datasize = 6;
    _return->data.data = (void*)sjg_string10;
    _return->data._isglobal = true;
    _return->data.count = 6;
    sjf_array_char(&_return->data);
    sjf_string(_return);
}

void sjf_lambda1_invoke_heap(sjs_lambda1* _parent, sjs_string** _return) {
    (*_return) = (sjs_string*)malloc(sizeof(sjs_string));
    (*_return)->_refCount = 1;
    (*_return)->count = 5;
    (*_return)->data._refCount = 1;
    (*_return)->data.datasize = 6;
    (*_return)->data.data = (void*)sjg_string10;
    (*_return)->data._isglobal = true;
    (*_return)->data.count = 6;
    sjf_array_char(&(*_return)->data);
    sjf_string_heap((*_return));
}

void sjf_log(sjs_log* _this) {
}

void sjf_log__write(sjs_log* _parent, int32_t level, cb_string_heap_string cb) {
    sjs_string sjt_call1 = { -1 };
    sjs_string sjt_call2 = { -1 };
    sjs_string sjt_call3 = { -1 };
    sjs_string sjt_call4 = { -1 };
    sjs_string sjt_call5 = { -1 };
    sjs_string sjt_call6 = { -1 };
    sjs_string sjt_call7 = { -1 };
    sjs_string* sjt_functionParam1 = 0;
    sjs_string* sjt_functionParam21 = 0;
    int32_t sjt_functionParam22;
    sjs_string* sjt_functionParam23 = 0;
    sjs_string* sjt_functionParam24 = 0;
    sjs_string* sjt_parent14 = 0;
    sjs_string* sjt_parent15 = 0;
    sjs_string* sjt_parent16 = 0;

    sjt_call4._refCount = 1;
    sjt_call4.count = 1;
    sjt_call4.data._refCount = 1;
    sjt_call4.data.datasize = 2;
    sjt_call4.data.data = (void*)sjg_string1;
    sjt_call4.data._isglobal = true;
    sjt_call4.data.count = 2;
    sjf_array_char(&sjt_call4.data);
    sjf_string(&sjt_call4);
    sjt_parent16 = &sjt_call4;
    sjt_functionParam22 = level;
    sjf_loglevel_asstring(sjt_functionParam22, &sjt_call5);
    sjt_functionParam21 = &sjt_call5;
    sjf_string_add(sjt_parent16, sjt_functionParam21, &sjt_call3);
    sjt_parent15 = &sjt_call3;
    sjt_call6._refCount = 1;
    sjt_call6.count = 2;
    sjt_call6.data._refCount = 1;
    sjt_call6.data.datasize = 3;
    sjt_call6.data.data = (void*)sjg_string9;
    sjt_call6.data._isglobal = true;
    sjt_call6.data.count = 3;
    sjf_array_char(&sjt_call6.data);
    sjf_string(&sjt_call6);
    sjt_functionParam23 = &sjt_call6;
    sjf_string_add(sjt_parent15, sjt_functionParam23, &sjt_call2);
    sjt_parent14 = &sjt_call2;
    cb._cb(cb._parent, &sjt_call7);
    sjt_functionParam24 = &sjt_call7;
    sjf_string_add(sjt_parent14, sjt_functionParam24, &sjt_call1);
    sjt_functionParam1 = &sjt_call1;
    sjf_debug_writeline(sjt_functionParam1);

    if (sjt_call1._refCount == 1) { sjf_string_destroy(&sjt_call1); }
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
    if (sjt_call7._refCount == 1) { sjf_string_destroy(&sjt_call7); }
;
}

void sjf_log_copy(sjs_log* _this, sjs_log* _from) {
    _this->minlevel = _from->minlevel;
}

void sjf_log_destroy(sjs_log* _this) {
}

void sjf_log_heap(sjs_log* _this) {
}

void sjf_log_info(sjs_log* _parent, cb_string_heap_string cb) {
    if ((sjv_loglevel_info >= _parent->minlevel)) {
        int32_t sjt_functionParam25;
        cb_string_heap_string sjt_functionParam26;

        sjt_functionParam25 = sjv_loglevel_info;
        sjt_functionParam26 = cb;
        sjf_log__write(_parent, sjt_functionParam25, sjt_functionParam26);
    }
}

void sjf_loglevel_asstring(int32_t e, sjs_string* _return) {
    int32_t underscore1;

    underscore1 = e;
    if ((underscore1 == 0)) {
        _return->_refCount = 1;
        _return->count = 5;
        _return->data._refCount = 1;
        _return->data.datasize = 6;
        _return->data.data = (void*)sjg_string2;
        _return->data._isglobal = true;
        _return->data.count = 6;
        sjf_array_char(&_return->data);
        sjf_string(_return);
    } else {
        if ((underscore1 == 1)) {
            _return->_refCount = 1;
            _return->count = 5;
            _return->data._refCount = 1;
            _return->data.datasize = 6;
            _return->data.data = (void*)sjg_string3;
            _return->data._isglobal = true;
            _return->data.count = 6;
            sjf_array_char(&_return->data);
            sjf_string(_return);
        } else {
            if ((underscore1 == 2)) {
                _return->_refCount = 1;
                _return->count = 4;
                _return->data._refCount = 1;
                _return->data.datasize = 5;
                _return->data.data = (void*)sjg_string4;
                _return->data._isglobal = true;
                _return->data.count = 5;
                sjf_array_char(&_return->data);
                sjf_string(_return);
            } else {
                if ((underscore1 == 3)) {
                    _return->_refCount = 1;
                    _return->count = 4;
                    _return->data._refCount = 1;
                    _return->data.datasize = 5;
                    _return->data.data = (void*)sjg_string5;
                    _return->data._isglobal = true;
                    _return->data.count = 5;
                    sjf_array_char(&_return->data);
                    sjf_string(_return);
                } else {
                    if ((underscore1 == 4)) {
                        _return->_refCount = 1;
                        _return->count = 5;
                        _return->data._refCount = 1;
                        _return->data.datasize = 6;
                        _return->data.data = (void*)sjg_string6;
                        _return->data._isglobal = true;
                        _return->data.count = 6;
                        sjf_array_char(&_return->data);
                        sjf_string(_return);
                    } else {
                        if ((underscore1 == 5)) {
                            _return->_refCount = 1;
                            _return->count = 5;
                            _return->data._refCount = 1;
                            _return->data.datasize = 6;
                            _return->data.data = (void*)sjg_string7;
                            _return->data._isglobal = true;
                            _return->data.count = 6;
                            sjf_array_char(&_return->data);
                            sjf_string(_return);
                        } else {
                            _return->_refCount = 1;
                            _return->count = 0;
                            _return->data._refCount = 1;
                            _return->data.datasize = 1;
                            _return->data.data = (void*)sjg_string8;
                            _return->data._isglobal = true;
                            _return->data.count = 1;
                            sjf_array_char(&_return->data);
                            sjf_string(_return);
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
    sjs_array_char sjv_newdata = { -1 };

    if ((item->count == 0)) {
        _return->_refCount = 1;
        _return->count = _parent->count;
        _return->data._refCount = 1;
        sjf_array_char_copy(&_return->data, (&_parent->data));
        sjf_string(_return);
    } else {
        int32_t i;
        int32_t sjt_cast1;
        int32_t sjt_forEnd1;
        int32_t sjt_forStart1;
        int32_t sjt_functionParam10;
        char sjt_functionParam11;
        int32_t sjt_functionParam2;
        int32_t sjt_functionParam3;
        char sjt_functionParam4;
        int32_t sjt_functionParam6;
        sjs_array_char* sjt_parent1 = 0;
        sjs_array_char* sjt_parent2 = 0;
        sjs_string* sjt_parent4 = 0;
        sjs_array_char* sjt_parent7 = 0;
        int32_t sjv_newcount;

        sjt_parent1 = &_parent->data;
        sjt_functionParam2 = (_parent->count + item->count) + 1;
        sjf_array_char_grow(sjt_parent1, sjt_functionParam2, &sjv_newdata);
        sjv_newcount = _parent->count;
        sjt_parent2 = &sjv_newdata;
        sjt_functionParam3 = sjv_newcount;
        sjt_parent4 = item;
        sjt_functionParam6 = 0;
        sjf_string_getat(sjt_parent4, sjt_functionParam6, &sjt_functionParam4);
        sjf_array_char_setat(sjt_parent2, sjt_functionParam3, sjt_functionParam4);
        sjv_newcount = sjv_newcount + 1;
        sjt_forStart1 = 1;
        sjt_forEnd1 = item->count;
        i = sjt_forStart1;
        while (i < sjt_forEnd1) {
            int32_t sjt_functionParam7;
            char sjt_functionParam8;
            int32_t sjt_functionParam9;
            sjs_array_char* sjt_parent5 = 0;
            sjs_string* sjt_parent6 = 0;

            sjt_parent5 = &sjv_newdata;
            sjt_functionParam7 = sjv_newcount;
            sjt_parent6 = item;
            sjt_functionParam9 = i;
            sjf_string_getat(sjt_parent6, sjt_functionParam9, &sjt_functionParam8);
            sjf_array_char_initat(sjt_parent5, sjt_functionParam7, sjt_functionParam8);
            sjv_newcount = sjv_newcount + 1;
            i++;
        }

        sjt_parent7 = &sjv_newdata;
        sjt_functionParam10 = sjv_newcount;
        sjt_cast1 = 0;
        sjt_functionParam11 = (char)sjt_cast1;
        sjf_array_char_initat(sjt_parent7, sjt_functionParam10, sjt_functionParam11);
        _return->_refCount = 1;
        _return->count = sjv_newcount;
        _return->data._refCount = 1;
        sjf_array_char_copy(&_return->data, (&sjv_newdata));
        sjf_string(_return);
    }

    if (sjv_newdata._refCount == 1) { sjf_array_char_destroy(&sjv_newdata); }
;
}

void sjf_string_add_heap(sjs_string* _parent, sjs_string* item, sjs_string** _return) {
    sjs_array_char sjv_newdata = { -1 };

    if ((item->count == 0)) {
        (*_return) = (sjs_string*)malloc(sizeof(sjs_string));
        (*_return)->_refCount = 1;
        (*_return)->count = _parent->count;
        (*_return)->data._refCount = 1;
        sjf_array_char_copy(&(*_return)->data, (&_parent->data));
        sjf_string_heap((*_return));
    } else {
        int32_t i;
        int32_t sjt_cast2;
        int32_t sjt_forEnd2;
        int32_t sjt_forStart2;
        int32_t sjt_functionParam12;
        int32_t sjt_functionParam13;
        char sjt_functionParam14;
        int32_t sjt_functionParam15;
        int32_t sjt_functionParam19;
        char sjt_functionParam20;
        sjs_string* sjt_parent10 = 0;
        sjs_array_char* sjt_parent13 = 0;
        sjs_array_char* sjt_parent8 = 0;
        sjs_array_char* sjt_parent9 = 0;
        int32_t sjv_newcount;

        sjt_parent8 = &_parent->data;
        sjt_functionParam12 = (_parent->count + item->count) + 1;
        sjf_array_char_grow(sjt_parent8, sjt_functionParam12, &sjv_newdata);
        sjv_newcount = _parent->count;
        sjt_parent9 = &sjv_newdata;
        sjt_functionParam13 = sjv_newcount;
        sjt_parent10 = item;
        sjt_functionParam15 = 0;
        sjf_string_getat(sjt_parent10, sjt_functionParam15, &sjt_functionParam14);
        sjf_array_char_setat(sjt_parent9, sjt_functionParam13, sjt_functionParam14);
        sjv_newcount = sjv_newcount + 1;
        sjt_forStart2 = 1;
        sjt_forEnd2 = item->count;
        i = sjt_forStart2;
        while (i < sjt_forEnd2) {
            int32_t sjt_functionParam16;
            char sjt_functionParam17;
            int32_t sjt_functionParam18;
            sjs_array_char* sjt_parent11 = 0;
            sjs_string* sjt_parent12 = 0;

            sjt_parent11 = &sjv_newdata;
            sjt_functionParam16 = sjv_newcount;
            sjt_parent12 = item;
            sjt_functionParam18 = i;
            sjf_string_getat(sjt_parent12, sjt_functionParam18, &sjt_functionParam17);
            sjf_array_char_initat(sjt_parent11, sjt_functionParam16, sjt_functionParam17);
            sjv_newcount = sjv_newcount + 1;
            i++;
        }

        sjt_parent13 = &sjv_newdata;
        sjt_functionParam19 = sjv_newcount;
        sjt_cast2 = 0;
        sjt_functionParam20 = (char)sjt_cast2;
        sjf_array_char_initat(sjt_parent13, sjt_functionParam19, sjt_functionParam20);
        (*_return) = (sjs_string*)malloc(sizeof(sjs_string));
        (*_return)->_refCount = 1;
        (*_return)->count = sjv_newcount;
        (*_return)->data._refCount = 1;
        sjf_array_char_copy(&(*_return)->data, (&sjv_newdata));
        sjf_string_heap((*_return));
    }

    if (sjv_newdata._refCount == 1) { sjf_array_char_destroy(&sjv_newdata); }
;
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

void sjf_string_getat(sjs_string* _parent, int32_t index, char* _return) {
    int32_t sjt_functionParam5;
    sjs_array_char* sjt_parent3 = 0;

    sjt_parent3 = &_parent->data;
    sjt_functionParam5 = index;
    sjf_array_char_getat(sjt_parent3, sjt_functionParam5, _return);
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
    (&sjv_log)->minlevel = sjv_loglevel_info;
    sjt_parent17 = &sjv_log;
    sjs_lambda1* lambainit1;
    sjt_call8._refCount = 1;
    sjf_lambda1(&sjt_call8);
    lambainit1 = &sjt_call8;
    sjt_functionParam27._parent = (sjs_object*)lambainit1;
    sjt_functionParam27._cb = (void(*)(sjs_object*, sjs_string*))sjf_lambda1_invoke;
    sjt_functionParam27._cb_heap = (void(*)(sjs_object*, sjs_string**))sjf_lambda1_invoke_heap;
    sjf_log_info(sjt_parent17, sjt_functionParam27);
    main_destroy();
    return 0;
}

void main_destroy() {

    if (sjt_call8._refCount == 1) { sjf_lambda1_destroy(&sjt_call8); }
;
    if (sjv_log._refCount == 1) { sjf_log_destroy(&sjv_log); }
;
}
