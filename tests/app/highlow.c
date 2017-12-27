#include <lib/common/common.h>

const char* sjg_string1 = "Shall we play\n";
const char* sjg_string2 = "Too high\n";
const char* sjg_string3 = "Too Low\n";
const char* sjg_string4 = "Correct\n";

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
    bool _isglobal;
    int32_t count;
};

struct td_sjs_string {
    int _refCount;
    int32_t count;
    sjs_array_char data;
};

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
int32_t sjt_capture1;
sjs_string* sjt_functionParam1 = 0;
sjs_string* sjt_functionParam5 = 0;
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
    _return->count = sjv_console_size - 1;
    _return->data._refCount = 1;
    _return->data.datasize = sjv_console_size;
    _return->data.data = sjv_console_data;
    _return->data._isglobal = false;
    _return->data.count = sjv_console_size;
    sjf_array_char(&_return->data);
    sjf_string(_return);
}

void sjf_console_readline_heap(sjs_string** _return) {
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
    (*_return)->count = sjv_console_size - 1;
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
    sjf_i32_random(&sjt_capture1);
    sjv_num = (sjt_capture1 % 10) + 1;
    sjv_iscorrect = false;
    result2 = !sjv_iscorrect;
    sjt_while1 = result2;
    while (sjt_while1) {
        bool result3;
        sjs_string sjt_call2 = { -1 };
        sjs_string sjt_call3 = { -1 };
        sjs_string* sjt_functionParam2 = 0;
        int32_t sjv_guess;
        sjs_string sjv_str = { -1 };

        sjf_console_readline(&sjv_str);
        sjt_functionParam2 = &sjv_str;
        sjf_string_asi32(sjt_functionParam2, &sjv_guess);
        if ((sjv_guess < sjv_num)) {
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
            if ((sjv_guess > sjv_num)) {
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

        result3 = !sjv_iscorrect;
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
