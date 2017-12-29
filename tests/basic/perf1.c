#include <lib/common/common.h>

const char* sjg_string1 = "";
const char* sjg_string2 = " kaka pipi";
const char* sjg_string3 = "timetocalc(msec): ";

#define sjs_log_typeId 1
#define sjs_array_char_typeId 2
#define sjs_string_typeId 3

typedef struct td_sjs_log sjs_log;
typedef struct td_sjs_array_char sjs_array_char;
typedef struct td_sjs_string sjs_string;

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

int32_t sjv_loglevel_debug;
int32_t sjv_loglevel_error;
int32_t sjv_loglevel_fatal;
int32_t sjv_loglevel_info;
int32_t sjv_loglevel_trace;
int32_t sjv_loglevel_warn;

int32_t i;
int32_t result1;
sjs_string sjt_call6 = { -1 };
sjs_string sjt_call7 = { -1 };
sjs_string sjt_call8 = { -1 };
int64_t sjt_cast3;
int32_t sjt_cast4;
int32_t sjt_forEnd1;
int32_t sjt_forStart1;
sjs_string* sjt_functionParam30 = 0;
sjs_string* sjt_functionParam31 = 0;
double sjt_functionParam32;
sjs_string* sjt_parent18 = 0;
int32_t sjv_clocks_per_sec;
void* sjv_emptystringdata;
int64_t sjv_end;
float sjv_f32_pi;
int32_t sjv_i32_maxvalue;
int32_t sjv_i32_minvalue;
sjs_log sjv_log = { -1 };
int64_t sjv_start;
sjs_string sjv_str = { -1 };
uint32_t sjv_u32_maxvalue;

void sjf_array_char(sjs_array_char* _this);
void sjf_array_char_copy(sjs_array_char* _this, sjs_array_char* _from);
void sjf_array_char_destroy(sjs_array_char* _this);
void sjf_array_char_getat(sjs_array_char* _parent, int32_t index, char* _return);
void sjf_array_char_grow(sjs_array_char* _parent, int32_t newsize, sjs_array_char* _return);
void sjf_array_char_grow_heap(sjs_array_char* _parent, int32_t newsize, sjs_array_char** _return);
void sjf_array_char_heap(sjs_array_char* _this);
void sjf_array_char_initat(sjs_array_char* _parent, int32_t index, char item);
void sjf_char_touppercase(char x, char* _return);
void sjf_clock(int64_t* _return);
void sjf_debug_writeline(sjs_string* data);
void sjf_f64_asstring(double val, sjs_string* _return);
void sjf_f64_asstring_heap(double val, sjs_string** _return);
void sjf_f64_pow(double x, double y, double* _return);
void sjf_f64_sqrt(double v, double* _return);
void sjf_i32_asstring(int32_t val, int32_t base, sjs_string* _return);
void sjf_i32_asstring_heap(int32_t val, int32_t base, sjs_string** _return);
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
void sjf_string_touppercase(sjs_string* _parent, sjs_string* _return);
void sjf_string_touppercase_heap(sjs_string* _parent, sjs_string** _return);
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
            char* p = (char*)_this->data;
            #if !true
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

void sjf_char_touppercase(char x, char* _return) {
    (*_return) = toupper(x);
return;
}

void sjf_clock(int64_t* _return) {
    (*_return) = clock();
return;;
}

void sjf_debug_writeline(sjs_string* data) {
    sjs_string* sjt_parent17 = 0;

    sjt_parent17 = data;
    sjf_string_nullterminate(sjt_parent17);
    debugout("%s\n", (char*)data->data.data);
}

void sjf_f64_asstring(double val, sjs_string* _return) {
    int32_t sjv_count;
    void* sjv_data;

    sjv_count = 0;
    sjv_data = 0;
    sjv_data = (int*)malloc(sizeof(int) + sizeof(char) * 256) + 1;
    int* refcount = (int*)sjv_data - 1;
    snprintf((char*)sjv_data, 256, "%lf", val);
    sjv_count = (int)strlen((char*)sjv_data);
    _return->_refCount = 1;
    _return->count = sjv_count;
    _return->data._refCount = 1;
    _return->data.datasize = sjv_count;
    _return->data.data = sjv_data;
    _return->data.isglobal = false;
    _return->data.count = sjv_count;
    sjf_array_char(&_return->data);
    _return->_isnullterminated = false;
    sjf_string(_return);
}

void sjf_f64_asstring_heap(double val, sjs_string** _return) {
    int32_t sjv_count;
    void* sjv_data;

    sjv_count = 0;
    sjv_data = 0;
    sjv_data = (int*)malloc(sizeof(int) + sizeof(char) * 256) + 1;
    int* refcount = (int*)sjv_data - 1;
    snprintf((char*)sjv_data, 256, "%lf", val);
    sjv_count = (int)strlen((char*)sjv_data);
    (*_return) = (sjs_string*)malloc(sizeof(sjs_string));
    (*_return)->_refCount = 1;
    (*_return)->count = sjv_count;
    (*_return)->data._refCount = 1;
    (*_return)->data.datasize = sjv_count;
    (*_return)->data.data = sjv_data;
    (*_return)->data.isglobal = false;
    (*_return)->data.count = sjv_count;
    sjf_array_char(&(*_return)->data);
    (*_return)->_isnullterminated = false;
    sjf_string_heap((*_return));
}

void sjf_f64_pow(double x, double y, double* _return) {
    (*_return) = pow(x, y);
return;;
}

void sjf_f64_sqrt(double v, double* _return) {
    (*_return) = sqrt(v);
return;;
}

void sjf_i32_asstring(int32_t val, int32_t base, sjs_string* _return) {
    int32_t sjv_count;
    void* sjv_data;

    sjv_count = 0;
    sjv_data = 0;
    sjv_data = (int*)malloc(sizeof(int) + sizeof(char) * 256) + 1;
    int* refcount = (int*)sjv_data - 1;
    *refcount = 1;
    ltoa(val, sjv_data, base);
    sjv_count = strlen((char*)sjv_data);
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
    ltoa(val, sjv_data, base);
    sjv_count = strlen((char*)sjv_data);
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
        int32_t sjt_forEnd2;
        int32_t sjt_forStart2;
        int32_t sjv_newcount;

        if ((_parent->count + item->count) > (&_parent->data)->datasize) {
            int32_t sjt_functionParam6;
            sjs_array_char* sjt_parent1 = 0;

            sjt_parent1 = &_parent->data;
            sjt_functionParam6 = ((((_parent->count + item->count) - 1) / 256) + 1) * 256;
            sjf_array_char_grow(sjt_parent1, sjt_functionParam6, &sjv_newdata);
        } else {
            sjv_newdata._refCount = 1;
            sjf_array_char_copy(&sjv_newdata, (&_parent->data));
        }

        sjv_newcount = _parent->count;
        sjt_forStart2 = 0;
        sjt_forEnd2 = item->count;
        i = sjt_forStart2;
        while (i < sjt_forEnd2) {
            int32_t sjt_functionParam10;
            int32_t sjt_functionParam7;
            char sjt_functionParam8;
            sjs_array_char* sjt_parent2 = 0;
            sjs_string* sjt_parent4 = 0;

            sjt_parent2 = &sjv_newdata;
            sjt_functionParam7 = sjv_newcount;
            sjt_parent4 = item;
            sjt_functionParam10 = i;
            sjf_string_getat(sjt_parent4, sjt_functionParam10, &sjt_functionParam8);
            sjf_array_char_initat(sjt_parent2, sjt_functionParam7, sjt_functionParam8);
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
        int32_t sjt_forEnd3;
        int32_t sjt_forStart3;
        int32_t sjv_newcount;

        if ((_parent->count + item->count) > (&_parent->data)->datasize) {
            int32_t sjt_functionParam11;
            sjs_array_char* sjt_parent5 = 0;

            sjt_parent5 = &_parent->data;
            sjt_functionParam11 = ((((_parent->count + item->count) - 1) / 256) + 1) * 256;
            sjf_array_char_grow(sjt_parent5, sjt_functionParam11, &sjv_newdata);
        } else {
            sjv_newdata._refCount = 1;
            sjf_array_char_copy(&sjv_newdata, (&_parent->data));
        }

        sjv_newcount = _parent->count;
        sjt_forStart3 = 0;
        sjt_forEnd3 = item->count;
        i = sjt_forStart3;
        while (i < sjt_forEnd3) {
            int32_t sjt_functionParam12;
            char sjt_functionParam13;
            int32_t sjt_functionParam14;
            sjs_array_char* sjt_parent6 = 0;
            sjs_string* sjt_parent7 = 0;

            sjt_parent6 = &sjv_newdata;
            sjt_functionParam12 = sjv_newcount;
            sjt_parent7 = item;
            sjt_functionParam14 = i;
            sjf_string_getat(sjt_parent7, sjt_functionParam14, &sjt_functionParam13);
            sjf_array_char_initat(sjt_parent6, sjt_functionParam12, sjt_functionParam13);
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
    int32_t sjt_functionParam9;
    sjs_array_char* sjt_parent3 = 0;

    sjt_parent3 = &_parent->data;
    sjt_functionParam9 = index;
    sjf_array_char_getat(sjt_parent3, sjt_functionParam9, _return);
}

void sjf_string_heap(sjs_string* _this) {
}

void sjf_string_nullterminate(sjs_string* _parent) {
    bool result2;
    bool result3;
    sjs_array_char sjt_call5 = { -1 };

    result2 = !(&_parent->data)->isglobal;
    result3 = !_parent->_isnullterminated;
    if (result2 || result3) {
        int32_t sjt_functionParam28;
        char sjt_functionParam29;
        sjs_array_char* sjt_parent16 = 0;

        if ((_parent->count + 1) > (&_parent->data)->datasize) {
            int32_t sjt_functionParam27;
            sjs_array_char* sjt_parent15 = 0;

            sjt_parent15 = &_parent->data;
            sjt_functionParam27 = _parent->count + 1;
            sjf_array_char_grow(sjt_parent15, sjt_functionParam27, &sjt_call5);
            if (_parent->data._refCount == 1) { sjf_array_char_destroy(&_parent->data); }
;
            _parent->data._refCount = 1;
            sjf_array_char_copy(&_parent->data, (&sjt_call5));
        }

        sjt_parent16 = &_parent->data;
        sjt_functionParam28 = _parent->count;
        sjt_functionParam29 = '\0';
        sjf_array_char_initat(sjt_parent16, sjt_functionParam28, sjt_functionParam29);
        _parent->_isnullterminated = true;
    }

    if (sjt_call5._refCount == 1) { sjf_array_char_destroy(&sjt_call5); }
;
}

void sjf_string_touppercase(sjs_string* _parent, sjs_string* _return) {
    int32_t i;
    int32_t sjt_forEnd4;
    int32_t sjt_forStart4;
    sjs_array_char sjv_a = { -1 };

    sjv_a._refCount = 1;
    sjv_a.datasize = (((_parent->count - 1) / 256) + 1) * 256;
    sjv_a.data = 0;
    sjv_a.isglobal = false;
    sjv_a.count = 0;
    sjf_array_char(&sjv_a);
    sjt_forStart4 = 0;
    sjt_forEnd4 = _parent->count;
    i = sjt_forStart4;
    while (i < sjt_forEnd4) {
        int32_t sjt_functionParam16;
        char sjt_functionParam17;
        char sjt_functionParam18;
        int32_t sjt_functionParam19;
        sjs_array_char* sjt_parent10 = 0;
        sjs_array_char* sjt_parent9 = 0;

        sjt_parent9 = &sjv_a;
        sjt_functionParam16 = i;
        sjt_parent10 = &_parent->data;
        sjt_functionParam19 = i;
        sjf_array_char_getat(sjt_parent10, sjt_functionParam19, &sjt_functionParam18);
        sjf_char_touppercase(sjt_functionParam18, &sjt_functionParam17);
        sjf_array_char_initat(sjt_parent9, sjt_functionParam16, sjt_functionParam17);
        i++;
    }

    _return->_refCount = 1;
    _return->count = _parent->count;
    _return->data._refCount = 1;
    sjf_array_char_copy(&_return->data, (&sjv_a));
    _return->_isnullterminated = false;
    sjf_string(_return);

    if (sjv_a._refCount == 1) { sjf_array_char_destroy(&sjv_a); }
;
}

void sjf_string_touppercase_heap(sjs_string* _parent, sjs_string** _return) {
    int32_t i;
    int32_t sjt_forEnd5;
    int32_t sjt_forStart5;
    sjs_array_char sjv_a = { -1 };

    sjv_a._refCount = 1;
    sjv_a.datasize = (((_parent->count - 1) / 256) + 1) * 256;
    sjv_a.data = 0;
    sjv_a.isglobal = false;
    sjv_a.count = 0;
    sjf_array_char(&sjv_a);
    sjt_forStart5 = 0;
    sjt_forEnd5 = _parent->count;
    i = sjt_forStart5;
    while (i < sjt_forEnd5) {
        int32_t sjt_functionParam20;
        char sjt_functionParam21;
        char sjt_functionParam22;
        int32_t sjt_functionParam23;
        sjs_array_char* sjt_parent11 = 0;
        sjs_array_char* sjt_parent12 = 0;

        sjt_parent11 = &sjv_a;
        sjt_functionParam20 = i;
        sjt_parent12 = &_parent->data;
        sjt_functionParam23 = i;
        sjf_array_char_getat(sjt_parent12, sjt_functionParam23, &sjt_functionParam22);
        sjf_char_touppercase(sjt_functionParam22, &sjt_functionParam21);
        sjf_array_char_initat(sjt_parent11, sjt_functionParam20, sjt_functionParam21);
        i++;
    }

    (*_return) = (sjs_string*)malloc(sizeof(sjs_string));
    (*_return)->_refCount = 1;
    (*_return)->count = _parent->count;
    (*_return)->data._refCount = 1;
    sjf_array_char_copy(&(*_return)->data, (&sjv_a));
    (*_return)->_isnullterminated = false;
    sjf_string_heap((*_return));

    if (sjv_a._refCount == 1) { sjf_array_char_destroy(&sjv_a); }
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
    sjf_clock(&sjv_start);
    sjv_str._refCount = 1;
    sjv_str.count = 0;
    sjv_str.data._refCount = 1;
    sjv_str.data.datasize = 0;
    sjv_str.data.data = (void*)sjg_string1;
    sjv_str.data.isglobal = true;
    sjv_str.data.count = 0;
    sjf_array_char(&sjv_str.data);
    sjv_str._isnullterminated = false;
    sjf_string(&sjv_str);
    sjt_forStart1 = 0;
    sjt_forEnd1 = 5000000;
    i = sjt_forStart1;
    while (i < sjt_forEnd1) {
        sjs_string sjt_call1 = { -1 };
        sjs_string sjt_call2 = { -1 };
        sjs_string sjt_call3 = { -1 };
        sjs_string sjt_call4 = { -1 };
        int32_t sjt_cast1;
        int32_t sjt_cast2;
        double sjt_functionParam1;
        sjs_string* sjt_functionParam15 = 0;
        double sjt_functionParam2;
        double sjt_functionParam3;
        int32_t sjt_functionParam4;
        int32_t sjt_functionParam5;
        sjs_string* sjt_parent13 = 0;
        sjs_string* sjt_parent8 = 0;
        double sjt_void1;
        double sjt_void2;
        int32_t sjv_j;
        sjs_string sjv_s1 = { -1 };
        sjs_string sjv_s2 = { -1 };
        sjs_string sjv_s3 = { -1 };

        sjt_cast1 = i;
        sjt_functionParam1 = (double)sjt_cast1;
        sjf_f64_sqrt(sjt_functionParam1, &sjt_void1);
        sjt_cast2 = i;
        sjt_functionParam2 = (double)sjt_cast2;
        sjt_functionParam3 = 2.56;
        sjf_f64_pow(sjt_functionParam2, sjt_functionParam3, &sjt_void2);
        sjv_j = i * 745;
        sjt_functionParam4 = i;
        sjt_functionParam5 = 10;
        sjf_i32_asstring(sjt_functionParam4, sjt_functionParam5, &sjv_s1);
        sjt_parent8 = &sjv_s1;
        sjt_call1._refCount = 1;
        sjt_call1.count = 10;
        sjt_call1.data._refCount = 1;
        sjt_call1.data.datasize = 10;
        sjt_call1.data.data = (void*)sjg_string2;
        sjt_call1.data.isglobal = true;
        sjt_call1.data.count = 10;
        sjf_array_char(&sjt_call1.data);
        sjt_call1._isnullterminated = false;
        sjf_string(&sjt_call1);
        sjt_functionParam15 = &sjt_call1;
        sjf_string_add(sjt_parent8, sjt_functionParam15, &sjv_s2);
        sjt_parent13 = &sjv_s2;
        sjf_string_touppercase(sjt_parent13, &sjv_s3);
        if ((i % 300) == 0) {
            sjt_call2._refCount = 1;
            sjt_call2.count = 0;
            sjt_call2.data._refCount = 1;
            sjt_call2.data.datasize = 0;
            sjt_call2.data.data = (void*)sjg_string1;
            sjt_call2.data.isglobal = true;
            sjt_call2.data.count = 0;
            sjf_array_char(&sjt_call2.data);
            sjt_call2._isnullterminated = false;
            sjf_string(&sjt_call2);
            if (sjv_str._refCount == 1) { sjf_string_destroy(&sjv_str); }
;
            sjv_str._refCount = 1;
            sjf_string_copy(&sjv_str, (&sjt_call2));
        } else {
            sjs_string* sjt_functionParam24 = 0;
            int32_t sjt_functionParam25;
            int32_t sjt_functionParam26;
            sjs_string* sjt_parent14 = 0;

            sjt_parent14 = &sjv_str;
            sjt_functionParam25 = i;
            sjt_functionParam26 = 16;
            sjf_i32_asstring(sjt_functionParam25, sjt_functionParam26, &sjt_call4);
            sjt_functionParam24 = &sjt_call4;
            sjf_string_add(sjt_parent14, sjt_functionParam24, &sjt_call3);
            if (sjv_str._refCount == 1) { sjf_string_destroy(&sjv_str); }
;
            sjv_str._refCount = 1;
            sjf_string_copy(&sjv_str, (&sjt_call3));
        }

        i++;

        if (sjt_call1._refCount == 1) { sjf_string_destroy(&sjt_call1); }
;
        if (sjt_call2._refCount == 1) { sjf_string_destroy(&sjt_call2); }
;
        if (sjt_call3._refCount == 1) { sjf_string_destroy(&sjt_call3); }
;
        if (sjt_call4._refCount == 1) { sjf_string_destroy(&sjt_call4); }
;
        if (sjv_s1._refCount == 1) { sjf_string_destroy(&sjv_s1); }
;
        if (sjv_s2._refCount == 1) { sjf_string_destroy(&sjv_s2); }
;
        if (sjv_s3._refCount == 1) { sjf_string_destroy(&sjv_s3); }
;
    }

    sjf_clock(&sjv_end);
    sjt_call7._refCount = 1;
    sjt_call7.count = 18;
    sjt_call7.data._refCount = 1;
    sjt_call7.data.datasize = 18;
    sjt_call7.data.data = (void*)sjg_string3;
    sjt_call7.data.isglobal = true;
    sjt_call7.data.count = 18;
    sjf_array_char(&sjt_call7.data);
    sjt_call7._isnullterminated = false;
    sjf_string(&sjt_call7);
    sjt_parent18 = &sjt_call7;
    sjt_cast3 = sjv_end - sjv_start;
    sjt_cast4 = sjv_clocks_per_sec;
    sjt_functionParam32 = ((double)sjt_cast3 * 1000.0) / (double)sjt_cast4;
    sjf_f64_asstring(sjt_functionParam32, &sjt_call8);
    sjt_functionParam31 = &sjt_call8;
    sjf_string_add(sjt_parent18, sjt_functionParam31, &sjt_call6);
    sjt_functionParam30 = &sjt_call6;
    sjf_debug_writeline(sjt_functionParam30);
    main_destroy();
    return 0;
}

void main_destroy() {

    if (sjt_call6._refCount == 1) { sjf_string_destroy(&sjt_call6); }
;
    if (sjt_call7._refCount == 1) { sjf_string_destroy(&sjt_call7); }
;
    if (sjt_call8._refCount == 1) { sjf_string_destroy(&sjt_call8); }
;
    if (sjv_log._refCount == 1) { sjf_log_destroy(&sjv_log); }
;
    if (sjv_str._refCount == 1) { sjf_string_destroy(&sjv_str); }
;
}
