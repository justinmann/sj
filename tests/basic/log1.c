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
    bool isglobal;
    int32_t count;
};

struct td_sjs_string {
    int _refCount;
    int32_t count;
    sjs_array_char data;
    bool _isnullterminated;
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
sjs_lambda1 sjt_call9 = { -1 };
cb_string_heap_string sjt_functionParam20;
sjs_log* sjt_parent14 = 0;
int32_t sjv_clocks_per_sec;
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

void sjf_debug_writeline(sjs_string* data) {
    sjs_string* sjt_parent3 = 0;

    sjt_parent3 = data;
    sjf_string_nullterminate(sjt_parent3);
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
    _return->data.datasize = 5;
    _return->data.data = (void*)sjg_string10;
    _return->data.isglobal = true;
    _return->data.count = 5;
    sjf_array_char(&_return->data);
    _return->_isnullterminated = false;
    sjf_string(_return);
}

void sjf_lambda1_invoke_heap(sjs_lambda1* _parent, sjs_string** _return) {
    (*_return) = (sjs_string*)malloc(sizeof(sjs_string));
    (*_return)->_refCount = 1;
    (*_return)->count = 5;
    (*_return)->data._refCount = 1;
    (*_return)->data.datasize = 5;
    (*_return)->data.data = (void*)sjg_string10;
    (*_return)->data.isglobal = true;
    (*_return)->data.count = 5;
    sjf_array_char(&(*_return)->data);
    (*_return)->_isnullterminated = false;
    sjf_string_heap((*_return));
}

void sjf_log(sjs_log* _this) {
}

void sjf_log__write(sjs_log* _parent, int32_t level, cb_string_heap_string cb) {
    sjs_string sjt_call2 = { -1 };
    sjs_string sjt_call3 = { -1 };
    sjs_string sjt_call4 = { -1 };
    sjs_string sjt_call5 = { -1 };
    sjs_string sjt_call6 = { -1 };
    sjs_string sjt_call7 = { -1 };
    sjs_string sjt_call8 = { -1 };
    sjs_string* sjt_functionParam14 = 0;
    int32_t sjt_functionParam15;
    sjs_string* sjt_functionParam16 = 0;
    sjs_string* sjt_functionParam17 = 0;
    sjs_string* sjt_functionParam4 = 0;
    sjs_string* sjt_parent11 = 0;
    sjs_string* sjt_parent12 = 0;
    sjs_string* sjt_parent13 = 0;

    sjt_call5._refCount = 1;
    sjt_call5.count = 1;
    sjt_call5.data._refCount = 1;
    sjt_call5.data.datasize = 1;
    sjt_call5.data.data = (void*)sjg_string1;
    sjt_call5.data.isglobal = true;
    sjt_call5.data.count = 1;
    sjf_array_char(&sjt_call5.data);
    sjt_call5._isnullterminated = false;
    sjf_string(&sjt_call5);
    sjt_parent13 = &sjt_call5;
    sjt_functionParam15 = level;
    sjf_loglevel_asstring(sjt_functionParam15, &sjt_call6);
    sjt_functionParam14 = &sjt_call6;
    sjf_string_add(sjt_parent13, sjt_functionParam14, &sjt_call4);
    sjt_parent12 = &sjt_call4;
    sjt_call7._refCount = 1;
    sjt_call7.count = 2;
    sjt_call7.data._refCount = 1;
    sjt_call7.data.datasize = 2;
    sjt_call7.data.data = (void*)sjg_string9;
    sjt_call7.data.isglobal = true;
    sjt_call7.data.count = 2;
    sjf_array_char(&sjt_call7.data);
    sjt_call7._isnullterminated = false;
    sjf_string(&sjt_call7);
    sjt_functionParam16 = &sjt_call7;
    sjf_string_add(sjt_parent12, sjt_functionParam16, &sjt_call3);
    sjt_parent11 = &sjt_call3;
    cb._cb(cb._parent, &sjt_call8);
    sjt_functionParam17 = &sjt_call8;
    sjf_string_add(sjt_parent11, sjt_functionParam17, &sjt_call2);
    sjt_functionParam4 = &sjt_call2;
    sjf_debug_writeline(sjt_functionParam4);

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
    if (sjt_call8._refCount == 1) { sjf_string_destroy(&sjt_call8); }
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
    if (sjv_loglevel_info >= _parent->minlevel) {
        int32_t sjt_functionParam18;
        cb_string_heap_string sjt_functionParam19;

        sjt_functionParam18 = sjv_loglevel_info;
        sjt_functionParam19 = cb;
        sjf_log__write(_parent, sjt_functionParam18, sjt_functionParam19);
    }
}

void sjf_loglevel_asstring(int32_t e, sjs_string* _return) {
    int32_t underscore1;

    underscore1 = e;
    if (underscore1 == 0) {
        _return->_refCount = 1;
        _return->count = 5;
        _return->data._refCount = 1;
        _return->data.datasize = 5;
        _return->data.data = (void*)sjg_string2;
        _return->data.isglobal = true;
        _return->data.count = 5;
        sjf_array_char(&_return->data);
        _return->_isnullterminated = false;
        sjf_string(_return);
    } else {
        if (underscore1 == 1) {
            _return->_refCount = 1;
            _return->count = 5;
            _return->data._refCount = 1;
            _return->data.datasize = 5;
            _return->data.data = (void*)sjg_string3;
            _return->data.isglobal = true;
            _return->data.count = 5;
            sjf_array_char(&_return->data);
            _return->_isnullterminated = false;
            sjf_string(_return);
        } else {
            if (underscore1 == 2) {
                _return->_refCount = 1;
                _return->count = 4;
                _return->data._refCount = 1;
                _return->data.datasize = 4;
                _return->data.data = (void*)sjg_string4;
                _return->data.isglobal = true;
                _return->data.count = 4;
                sjf_array_char(&_return->data);
                _return->_isnullterminated = false;
                sjf_string(_return);
            } else {
                if (underscore1 == 3) {
                    _return->_refCount = 1;
                    _return->count = 4;
                    _return->data._refCount = 1;
                    _return->data.datasize = 4;
                    _return->data.data = (void*)sjg_string5;
                    _return->data.isglobal = true;
                    _return->data.count = 4;
                    sjf_array_char(&_return->data);
                    _return->_isnullterminated = false;
                    sjf_string(_return);
                } else {
                    if (underscore1 == 4) {
                        _return->_refCount = 1;
                        _return->count = 5;
                        _return->data._refCount = 1;
                        _return->data.datasize = 5;
                        _return->data.data = (void*)sjg_string6;
                        _return->data.isglobal = true;
                        _return->data.count = 5;
                        sjf_array_char(&_return->data);
                        _return->_isnullterminated = false;
                        sjf_string(_return);
                    } else {
                        if (underscore1 == 5) {
                            _return->_refCount = 1;
                            _return->count = 5;
                            _return->data._refCount = 1;
                            _return->data.datasize = 5;
                            _return->data.data = (void*)sjg_string7;
                            _return->data.isglobal = true;
                            _return->data.count = 5;
                            sjf_array_char(&_return->data);
                            _return->_isnullterminated = false;
                            sjf_string(_return);
                        } else {
                            _return->_refCount = 1;
                            _return->count = 0;
                            _return->data._refCount = 1;
                            _return->data.datasize = 0;
                            _return->data.data = (void*)sjg_string8;
                            _return->data.isglobal = true;
                            _return->data.count = 0;
                            sjf_array_char(&_return->data);
                            _return->_isnullterminated = false;
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

    if (item->count == 0) {
        _return->_refCount = 1;
        _return->count = _parent->count;
        _return->data._refCount = 1;
        sjf_array_char_copy(&_return->data, (&_parent->data));
        _return->_isnullterminated = false;
        sjf_string(_return);
    } else {
        int32_t i;
        int32_t sjt_forEnd1;
        int32_t sjt_forStart1;
        int32_t sjv_newcount;

        if ((_parent->count + item->count) > (&_parent->data)->datasize) {
            int32_t sjt_functionParam5;
            sjs_array_char* sjt_parent4 = 0;

            sjt_parent4 = &_parent->data;
            sjt_functionParam5 = ((((_parent->count + item->count) - 1) / 256) + 1) * 256;
            sjf_array_char_grow(sjt_parent4, sjt_functionParam5, &sjv_newdata);
        } else {
            sjv_newdata._refCount = 1;
            sjf_array_char_copy(&sjv_newdata, (&_parent->data));
        }

        sjv_newcount = _parent->count;
        sjt_forStart1 = 0;
        sjt_forEnd1 = item->count;
        i = sjt_forStart1;
        while (i < sjt_forEnd1) {
            int32_t sjt_functionParam6;
            char sjt_functionParam7;
            int32_t sjt_functionParam9;
            sjs_array_char* sjt_parent5 = 0;
            sjs_string* sjt_parent7 = 0;

            sjt_parent5 = &sjv_newdata;
            sjt_functionParam6 = sjv_newcount;
            sjt_parent7 = item;
            sjt_functionParam9 = i;
            sjf_string_getat(sjt_parent7, sjt_functionParam9, &sjt_functionParam7);
            sjf_array_char_initat(sjt_parent5, sjt_functionParam6, sjt_functionParam7);
            sjv_newcount = sjv_newcount + 1;
            i++;
        }

        _return->_refCount = 1;
        _return->count = sjv_newcount;
        _return->data._refCount = 1;
        sjf_array_char_copy(&_return->data, (&sjv_newdata));
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
        sjf_array_char_copy(&(*_return)->data, (&_parent->data));
        (*_return)->_isnullterminated = false;
        sjf_string_heap((*_return));
    } else {
        int32_t i;
        int32_t sjt_forEnd2;
        int32_t sjt_forStart2;
        int32_t sjv_newcount;

        if ((_parent->count + item->count) > (&_parent->data)->datasize) {
            int32_t sjt_functionParam10;
            sjs_array_char* sjt_parent8 = 0;

            sjt_parent8 = &_parent->data;
            sjt_functionParam10 = ((((_parent->count + item->count) - 1) / 256) + 1) * 256;
            sjf_array_char_grow(sjt_parent8, sjt_functionParam10, &sjv_newdata);
        } else {
            sjv_newdata._refCount = 1;
            sjf_array_char_copy(&sjv_newdata, (&_parent->data));
        }

        sjv_newcount = _parent->count;
        sjt_forStart2 = 0;
        sjt_forEnd2 = item->count;
        i = sjt_forStart2;
        while (i < sjt_forEnd2) {
            int32_t sjt_functionParam11;
            char sjt_functionParam12;
            int32_t sjt_functionParam13;
            sjs_string* sjt_parent10 = 0;
            sjs_array_char* sjt_parent9 = 0;

            sjt_parent9 = &sjv_newdata;
            sjt_functionParam11 = sjv_newcount;
            sjt_parent10 = item;
            sjt_functionParam13 = i;
            sjf_string_getat(sjt_parent10, sjt_functionParam13, &sjt_functionParam12);
            sjf_array_char_initat(sjt_parent9, sjt_functionParam11, sjt_functionParam12);
            sjv_newcount = sjv_newcount + 1;
            i++;
        }

        (*_return) = (sjs_string*)malloc(sizeof(sjs_string));
        (*_return)->_refCount = 1;
        (*_return)->count = sjv_newcount;
        (*_return)->data._refCount = 1;
        sjf_array_char_copy(&(*_return)->data, (&sjv_newdata));
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
    int32_t sjt_functionParam8;
    sjs_array_char* sjt_parent6 = 0;

    sjt_parent6 = &_parent->data;
    sjt_functionParam8 = index;
    sjf_array_char_getat(sjt_parent6, sjt_functionParam8, _return);
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
    (&sjv_log)->minlevel = sjv_loglevel_info;
    sjt_parent14 = &sjv_log;
    sjs_lambda1* lambainit1;
    sjt_call9._refCount = 1;
    sjf_lambda1(&sjt_call9);
    lambainit1 = &sjt_call9;
    sjt_functionParam20._parent = (sjs_object*)lambainit1;
    sjt_functionParam20._cb = (void(*)(sjs_object*, sjs_string*))sjf_lambda1_invoke;
    sjt_functionParam20._cb_heap = (void(*)(sjs_object*, sjs_string**))sjf_lambda1_invoke_heap;
    sjf_log_info(sjt_parent14, sjt_functionParam20);
    main_destroy();
    return 0;
}

void main_destroy() {

    if (sjt_call9._refCount == 1) { sjf_lambda1_destroy(&sjt_call9); }
;
    if (sjv_log._refCount == 1) { sjf_log_destroy(&sjv_log); }
;
}
