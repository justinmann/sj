#include <lib/common/common.h>

const char* sjg_string1 = "";
const char* sjg_string10 = "ptr";
const char* sjg_string11 = "#iface";
const char* sjg_string12 = "array!char";
const char* sjg_string13 = "grow";
const char* sjg_string14 = "initat";
const char* sjg_string15 = "class";
const char* sjg_string16 = "b";
const char* sjg_string17 = "writeline";
const char* sjg_string18 = "global";
const char* sjg_string19 = "log";
const char* sjg_string2 = "bool";
const char* sjg_string20 = "string";
const char* sjg_string21 = "nullterminate";
const char* sjg_string22 = "type_asstring";
const char* sjg_string23 = "type";
const char* sjg_string24 = "u32";
const char* sjg_string25 = "u64";
const char* sjg_string26 = "void";
const char* sjg_string3 = "()i32";
const char* sjg_string4 = "char";
const char* sjg_string5 = "f32";
const char* sjg_string6 = "f64";
const char* sjg_string7 = "i32";
const char* sjg_string8 = "i64";
const char* sjg_string9 = "loglevel";

#define sjs_log_typeId 15
#define sjs_class_typeId 16
#define sji_iface_typeId 17
#define sjs_array_char_typeId 23
#define sjs_string_typeId 21

typedef struct td_sjs_log sjs_log;
typedef struct td_sjs_class sjs_class;
typedef struct td_sji_iface_vtbl sji_iface_vtbl;
typedef struct td_sji_iface sji_iface;
typedef struct td_sjs_array_char sjs_array_char;
typedef struct td_sjs_string sjs_string;

struct td_sjs_log {
    int _refCount;
    int32_t minlevel;
};

struct td_sjs_class {
    int _refCount;
};

struct td_sji_iface_vtbl {
    void (*destroy)(void* _this);
    void (*asinterface)(sjs_object* _this, int typeId, sjs_interface* _return);
    void (*getclasstype)(sjs_object* _parent, int32_t* _return);
};

struct td_sji_iface {
    sjs_object* _parent;
    sji_iface_vtbl* _vtbl;
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

sji_iface_vtbl sjs_class_iface_vtbl;
int32_t sjv_loglevel_debug;
int32_t sjv_loglevel_error;
int32_t sjv_loglevel_fatal;
int32_t sjv_loglevel_info;
int32_t sjv_loglevel_trace;
int32_t sjv_loglevel_warn;

int32_t result1;
sjs_string sjt_call10 = { -1 };
sjs_string sjt_call2 = { -1 };
sjs_string sjt_call3 = { -1 };
sjs_string sjt_call4 = { -1 };
sjs_string sjt_call5 = { -1 };
sjs_string sjt_call6 = { -1 };
sjs_string sjt_call7 = { -1 };
sjs_string sjt_call8 = { -1 };
sjs_string sjt_call9 = { -1 };
sjs_class* sjt_cast1 = 0;
sjs_string* sjt_functionParam10 = 0;
int32_t sjt_functionParam11;
sjs_string* sjt_functionParam12 = 0;
int32_t sjt_functionParam13;
sjs_string* sjt_functionParam14 = 0;
int32_t sjt_functionParam15;
sjs_string* sjt_functionParam16 = 0;
int32_t sjt_functionParam17;
sjs_string* sjt_functionParam18 = 0;
int32_t sjt_functionParam19;
sjs_string* sjt_functionParam20 = 0;
int32_t sjt_functionParam21;
sjs_string* sjt_functionParam4 = 0;
int32_t sjt_functionParam5;
sjs_string* sjt_functionParam6 = 0;
int32_t sjt_functionParam7;
sjs_string* sjt_functionParam8 = 0;
int32_t sjt_functionParam9;
sji_iface sjt_parent1 = { 0 };
sjs_class sjv_a = { -1 };
int32_t sjv_clocks_per_sec;
int32_t sjv_d1;
int32_t sjv_d2;
int32_t sjv_d3;
int32_t sjv_d4;
void* sjv_emptystringdata;
float sjv_f32_pi;
sji_iface sjv_i = { 0 };
int32_t sjv_i32_maxvalue;
int32_t sjv_i32_minvalue;
sjs_log sjv_log = { -1 };
int32_t sjv_t1;
int32_t sjv_t2;
int32_t sjv_t3;
int32_t sjv_t4;
int32_t sjv_t5;
uint32_t sjv_u32_maxvalue;

void sjf_array_char(sjs_array_char* _this);
void sjf_array_char_copy(sjs_array_char* _this, sjs_array_char* _from);
void sjf_array_char_destroy(sjs_array_char* _this);
void sjf_array_char_grow(sjs_array_char* _parent, int32_t newsize, sjs_array_char* _return);
void sjf_array_char_grow_heap(sjs_array_char* _parent, int32_t newsize, sjs_array_char** _return);
void sjf_array_char_heap(sjs_array_char* _this);
void sjf_array_char_initat(sjs_array_char* _parent, int32_t index, char item);
void sjf_class(sjs_class* _this);
void sjf_class_as_sji_iface(sjs_class* _this, sji_iface* _return);
void sjf_class_asinterface(sjs_class* _this, int typeId, sjs_interface* _return);
void sjf_class_copy(sjs_class* _this, sjs_class* _from);
void sjf_class_destroy(sjs_class* _this);
void sjf_class_getclasstype(sjs_object* _this, int* _return);
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
void sjf_type_asstring(int32_t t, sjs_string* _return);
void sjf_type_asstring_heap(int32_t t, sjs_string** _return);
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

void sjf_class(sjs_class* _this) {
}

void sjf_class_as_sji_iface(sjs_class* _this, sji_iface* _return) {
    _return->_parent = (sjs_object*)_this;
    _return->_vtbl = &sjs_class_iface_vtbl;
}

void sjf_class_asinterface(sjs_class* _this, int typeId, sjs_interface* _return) {
    switch (typeId) {
        case sji_iface_typeId:  {
            sjf_class_as_sji_iface(_this, (sji_iface*)_return);
            break;
        }

        default: {
            _return->_parent = 0;
            break;
        }
    }
}

void sjf_class_copy(sjs_class* _this, sjs_class* _from) {
}

void sjf_class_destroy(sjs_class* _this) {
}

void sjf_class_getclasstype(sjs_object* _this, int* _return) {
    *_return = 16;
}

void sjf_class_heap(sjs_class* _this) {
}

void sjf_debug_writeline(sjs_string* data) {
    sjs_string* sjt_parent4 = 0;

    sjt_parent4 = data;
    sjf_string_nullterminate(sjt_parent4);
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
        sjs_array_char* sjt_parent3 = 0;

        if ((_parent->count + 1) > (&_parent->data)->datasize) {
            int32_t sjt_functionParam1;
            sjs_array_char* sjt_parent2 = 0;

            sjt_parent2 = &_parent->data;
            sjt_functionParam1 = _parent->count + 1;
            sjf_array_char_grow(sjt_parent2, sjt_functionParam1, &sjt_call1);
            if (_parent->data._refCount == 1) { sjf_array_char_destroy(&_parent->data); }
;
            _parent->data._refCount = 1;
            sjf_array_char_copy(&_parent->data, (&sjt_call1));
        }

        sjt_parent3 = &_parent->data;
        sjt_functionParam2 = _parent->count;
        sjt_functionParam3 = '\0';
        sjf_array_char_initat(sjt_parent3, sjt_functionParam2, sjt_functionParam3);
        _parent->_isnullterminated = true;
    }

    if (sjt_call1._refCount == 1) { sjf_array_char_destroy(&sjt_call1); }
;
}

void sjf_type_asstring(int32_t t, sjs_string* _return) {
    switch (t) {
        case 8:
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
        break;
        case 19:
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
        break;
        case 9:
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
        break;
        case 6:
        _return->_refCount = 1;
        _return->count = 3;
        _return->data._refCount = 1;
        _return->data.datasize = 3;
        _return->data.data = (void*)sjg_string5;
        _return->data.isglobal = true;
        _return->data.count = 3;
        sjf_array_char(&_return->data);
        _return->_isnullterminated = false;
        sjf_string(_return);
        break;
        case 7:
        _return->_refCount = 1;
        _return->count = 3;
        _return->data._refCount = 1;
        _return->data.datasize = 3;
        _return->data.data = (void*)sjg_string6;
        _return->data.isglobal = true;
        _return->data.count = 3;
        sjf_array_char(&_return->data);
        _return->_isnullterminated = false;
        sjf_string(_return);
        break;
        case 1:
        _return->_refCount = 1;
        _return->count = 3;
        _return->data._refCount = 1;
        _return->data.datasize = 3;
        _return->data.data = (void*)sjg_string7;
        _return->data.isglobal = true;
        _return->data.count = 3;
        sjf_array_char(&_return->data);
        _return->_isnullterminated = false;
        sjf_string(_return);
        break;
        case 2:
        _return->_refCount = 1;
        _return->count = 3;
        _return->data._refCount = 1;
        _return->data.datasize = 3;
        _return->data.data = (void*)sjg_string8;
        _return->data.isglobal = true;
        _return->data.count = 3;
        sjf_array_char(&_return->data);
        _return->_isnullterminated = false;
        sjf_string(_return);
        break;
        case 12:
        _return->_refCount = 1;
        _return->count = 8;
        _return->data._refCount = 1;
        _return->data.datasize = 8;
        _return->data.data = (void*)sjg_string9;
        _return->data.isglobal = true;
        _return->data.count = 8;
        sjf_array_char(&_return->data);
        _return->_isnullterminated = false;
        sjf_string(_return);
        break;
        case 5:
        _return->_refCount = 1;
        _return->count = 3;
        _return->data._refCount = 1;
        _return->data.datasize = 3;
        _return->data.data = (void*)sjg_string10;
        _return->data.isglobal = true;
        _return->data.count = 3;
        sjf_array_char(&_return->data);
        _return->_isnullterminated = false;
        sjf_string(_return);
        break;
        case 17:
        _return->_refCount = 1;
        _return->count = 6;
        _return->data._refCount = 1;
        _return->data.datasize = 6;
        _return->data.data = (void*)sjg_string11;
        _return->data.isglobal = true;
        _return->data.count = 6;
        sjf_array_char(&_return->data);
        _return->_isnullterminated = false;
        sjf_string(_return);
        break;
        case 13:
        _return->_refCount = 1;
        _return->count = 0;
        _return->data._refCount = 1;
        _return->data.datasize = 0;
        _return->data.data = (void*)sjg_string1;
        _return->data.isglobal = true;
        _return->data.count = 0;
        sjf_array_char(&_return->data);
        _return->_isnullterminated = false;
        sjf_string(_return);
        break;
        case 23:
        _return->_refCount = 1;
        _return->count = 10;
        _return->data._refCount = 1;
        _return->data.datasize = 10;
        _return->data.data = (void*)sjg_string12;
        _return->data.isglobal = true;
        _return->data.count = 10;
        sjf_array_char(&_return->data);
        _return->_isnullterminated = false;
        sjf_string(_return);
        break;
        case 24:
        _return->_refCount = 1;
        _return->count = 4;
        _return->data._refCount = 1;
        _return->data.datasize = 4;
        _return->data.data = (void*)sjg_string13;
        _return->data.isglobal = true;
        _return->data.count = 4;
        sjf_array_char(&_return->data);
        _return->_isnullterminated = false;
        sjf_string(_return);
        break;
        case 25:
        _return->_refCount = 1;
        _return->count = 6;
        _return->data._refCount = 1;
        _return->data.datasize = 6;
        _return->data.data = (void*)sjg_string14;
        _return->data.isglobal = true;
        _return->data.count = 6;
        sjf_array_char(&_return->data);
        _return->_isnullterminated = false;
        sjf_string(_return);
        break;
        case 16:
        _return->_refCount = 1;
        _return->count = 5;
        _return->data._refCount = 1;
        _return->data.datasize = 5;
        _return->data.data = (void*)sjg_string15;
        _return->data.isglobal = true;
        _return->data.count = 5;
        sjf_array_char(&_return->data);
        _return->_isnullterminated = false;
        sjf_string(_return);
        break;
        case 18:
        _return->_refCount = 1;
        _return->count = 1;
        _return->data._refCount = 1;
        _return->data.datasize = 1;
        _return->data.data = (void*)sjg_string16;
        _return->data.isglobal = true;
        _return->data.count = 1;
        sjf_array_char(&_return->data);
        _return->_isnullterminated = false;
        sjf_string(_return);
        break;
        case 20:
        _return->_refCount = 1;
        _return->count = 9;
        _return->data._refCount = 1;
        _return->data.datasize = 9;
        _return->data.data = (void*)sjg_string17;
        _return->data.isglobal = true;
        _return->data.count = 9;
        sjf_array_char(&_return->data);
        _return->_isnullterminated = false;
        sjf_string(_return);
        break;
        case 14:
        _return->_refCount = 1;
        _return->count = 6;
        _return->data._refCount = 1;
        _return->data.datasize = 6;
        _return->data.data = (void*)sjg_string18;
        _return->data.isglobal = true;
        _return->data.count = 6;
        sjf_array_char(&_return->data);
        _return->_isnullterminated = false;
        sjf_string(_return);
        break;
        case 15:
        _return->_refCount = 1;
        _return->count = 3;
        _return->data._refCount = 1;
        _return->data.datasize = 3;
        _return->data.data = (void*)sjg_string19;
        _return->data.isglobal = true;
        _return->data.count = 3;
        sjf_array_char(&_return->data);
        _return->_isnullterminated = false;
        sjf_string(_return);
        break;
        case 21:
        _return->_refCount = 1;
        _return->count = 6;
        _return->data._refCount = 1;
        _return->data.datasize = 6;
        _return->data.data = (void*)sjg_string20;
        _return->data.isglobal = true;
        _return->data.count = 6;
        sjf_array_char(&_return->data);
        _return->_isnullterminated = false;
        sjf_string(_return);
        break;
        case 22:
        _return->_refCount = 1;
        _return->count = 13;
        _return->data._refCount = 1;
        _return->data.datasize = 13;
        _return->data.data = (void*)sjg_string21;
        _return->data.isglobal = true;
        _return->data.count = 13;
        sjf_array_char(&_return->data);
        _return->_isnullterminated = false;
        sjf_string(_return);
        break;
        case 26:
        _return->_refCount = 1;
        _return->count = 13;
        _return->data._refCount = 1;
        _return->data.datasize = 13;
        _return->data.data = (void*)sjg_string22;
        _return->data.isglobal = true;
        _return->data.count = 13;
        sjf_array_char(&_return->data);
        _return->_isnullterminated = false;
        sjf_string(_return);
        break;
        case 11:
        _return->_refCount = 1;
        _return->count = 4;
        _return->data._refCount = 1;
        _return->data.datasize = 4;
        _return->data.data = (void*)sjg_string23;
        _return->data.isglobal = true;
        _return->data.count = 4;
        sjf_array_char(&_return->data);
        _return->_isnullterminated = false;
        sjf_string(_return);
        break;
        case 3:
        _return->_refCount = 1;
        _return->count = 3;
        _return->data._refCount = 1;
        _return->data.datasize = 3;
        _return->data.data = (void*)sjg_string24;
        _return->data.isglobal = true;
        _return->data.count = 3;
        sjf_array_char(&_return->data);
        _return->_isnullterminated = false;
        sjf_string(_return);
        break;
        case 4:
        _return->_refCount = 1;
        _return->count = 3;
        _return->data._refCount = 1;
        _return->data.datasize = 3;
        _return->data.data = (void*)sjg_string25;
        _return->data.isglobal = true;
        _return->data.count = 3;
        sjf_array_char(&_return->data);
        _return->_isnullterminated = false;
        sjf_string(_return);
        break;
        case 10:
        _return->_refCount = 1;
        _return->count = 4;
        _return->data._refCount = 1;
        _return->data.datasize = 4;
        _return->data.data = (void*)sjg_string26;
        _return->data.isglobal = true;
        _return->data.count = 4;
        sjf_array_char(&_return->data);
        _return->_isnullterminated = false;
        sjf_string(_return);
        break;
        default:
        _return->_refCount = 1;
        _return->count = 0;
        _return->data._refCount = 1;
        _return->data.datasize = 0;
        _return->data.data = (void*)sjg_string1;
        _return->data.isglobal = true;
        _return->data.count = 0;
        sjf_array_char(&_return->data);
        _return->_isnullterminated = false;
        sjf_string(_return);
        break;
    }
}

void sjf_type_asstring_heap(int32_t t, sjs_string** _return) {
    (*_return) = (sjs_string*)malloc(sizeof(sjs_string));
    (*_return)->_refCount = 1;
    (*_return)->count = 0;
    (*_return)->data._refCount = 1;
    (*_return)->data.datasize = 0;
    (*_return)->data.data = (void*)sjg_string1;
    (*_return)->data.isglobal = true;
    (*_return)->data.count = 0;
    sjf_array_char(&(*_return)->data);
    (*_return)->_isnullterminated = false;
    sjf_string_heap((*_return));
}

int main(int argc, char** argv) {
    sjs_class_iface_vtbl.destroy = (void(*)(void*))sjf_class_destroy;
    sjs_class_iface_vtbl.asinterface = (void(*)(sjs_object*,int,sjs_interface*))sjf_class_asinterface;
    sjs_class_iface_vtbl.getclasstype = (void(*)(sjs_object*,int*))sjf_class_getclasstype;
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
    sjv_a._refCount = 1;
    sjf_class(&sjv_a);
    sjt_cast1 = &sjv_a;
    sjf_class_as_sji_iface(sjt_cast1, &sjv_i);
    sjv_t1 = 16;
    sjv_t2 = 1;
    sjv_t3 = 19;
    sjv_t4 = 17;
    sjt_parent1 = sjv_i;
    sjt_parent1._vtbl->getclasstype(sjt_parent1._parent, &sjv_t5);
    sjv_d1 = 1;
    sjv_d2 = 16;
    sjv_d3 = 19;
    sjv_d4 = 17;
    sjt_functionParam5 = sjv_t1;
    sjf_type_asstring(sjt_functionParam5, &sjt_call2);
    sjt_functionParam4 = &sjt_call2;
    sjf_debug_writeline(sjt_functionParam4);
    sjt_functionParam7 = sjv_t2;
    sjf_type_asstring(sjt_functionParam7, &sjt_call3);
    sjt_functionParam6 = &sjt_call3;
    sjf_debug_writeline(sjt_functionParam6);
    sjt_functionParam9 = sjv_t3;
    sjf_type_asstring(sjt_functionParam9, &sjt_call4);
    sjt_functionParam8 = &sjt_call4;
    sjf_debug_writeline(sjt_functionParam8);
    sjt_functionParam11 = sjv_t4;
    sjf_type_asstring(sjt_functionParam11, &sjt_call5);
    sjt_functionParam10 = &sjt_call5;
    sjf_debug_writeline(sjt_functionParam10);
    sjt_functionParam13 = sjv_t5;
    sjf_type_asstring(sjt_functionParam13, &sjt_call6);
    sjt_functionParam12 = &sjt_call6;
    sjf_debug_writeline(sjt_functionParam12);
    sjt_functionParam15 = sjv_d1;
    sjf_type_asstring(sjt_functionParam15, &sjt_call7);
    sjt_functionParam14 = &sjt_call7;
    sjf_debug_writeline(sjt_functionParam14);
    sjt_functionParam17 = sjv_d2;
    sjf_type_asstring(sjt_functionParam17, &sjt_call8);
    sjt_functionParam16 = &sjt_call8;
    sjf_debug_writeline(sjt_functionParam16);
    sjt_functionParam19 = sjv_d3;
    sjf_type_asstring(sjt_functionParam19, &sjt_call9);
    sjt_functionParam18 = &sjt_call9;
    sjf_debug_writeline(sjt_functionParam18);
    sjt_functionParam21 = sjv_d4;
    sjf_type_asstring(sjt_functionParam21, &sjt_call10);
    sjt_functionParam20 = &sjt_call10;
    sjf_debug_writeline(sjt_functionParam20);
    main_destroy();
    return 0;
}

void main_destroy() {

    if (sjt_call10._refCount == 1) { sjf_string_destroy(&sjt_call10); }
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
    if (sjt_call8._refCount == 1) { sjf_string_destroy(&sjt_call8); }
;
    if (sjt_call9._refCount == 1) { sjf_string_destroy(&sjt_call9); }
;
    if (sjv_a._refCount == 1) { sjf_class_destroy(&sjv_a); }
;
    if (sjv_log._refCount == 1) { sjf_log_destroy(&sjv_log); }
;
}
