#include <lib/common/common.h>

#define sjs_log_typeId 1
#define sjs_class_typeId 2
#define sji_interface_vtbl_typeId 3
#define sji_interface_typeId 4
#define sji_interface2_vtbl_typeId 5
#define sji_interface2_typeId 6

typedef struct td_sjs_log sjs_log;
typedef struct td_sjs_class sjs_class;
typedef struct td_sji_interface_vtbl sji_interface_vtbl;
typedef struct td_sji_interface sji_interface;
typedef struct td_sji_interface2_vtbl sji_interface2_vtbl;
typedef struct td_sji_interface2 sji_interface2;

struct td_sjs_log {
    int _refCount;
    int32_t minlevel;
};

struct td_sjs_class {
    int _refCount;
    int32_t bob;
};

struct td_sji_interface_vtbl {
    void (*destroy)(void* _this);
    void (*asinterface)(sjs_object* _this, int typeId, sjs_interface* _return);
};

struct td_sji_interface {
    sjs_object* _parent;
    sji_interface_vtbl* _vtbl;
};

struct td_sji_interface2_vtbl {
    void (*destroy)(void* _this);
    void (*asinterface)(sjs_object* _this, int typeId, sjs_interface* _return);
};

struct td_sji_interface2 {
    sjs_object* _parent;
    sji_interface2_vtbl* _vtbl;
};

sji_interface_vtbl sjs_class_interface_vtbl;
int32_t sjv_loglevel_debug;
int32_t sjv_loglevel_error;
int32_t sjv_loglevel_fatal;
int32_t sjv_loglevel_info;
int32_t sjv_loglevel_trace;
int32_t sjv_loglevel_warn;

int32_t result1;
sjs_class* sjt_cast1 = 0;
sji_interface sjt_cast2 = { 0 };
sjs_class* sjt_value1 = 0;
int32_option sjv_a;
int64_option sjv_b;
uint32_option sjv_c;
uint64_option sjv_d;
float_option sjv_e;
void* sjv_emptystringdata;
double_option sjv_f;
float sjv_f32_pi;
char_option sjv_g;
void_option sjv_h;
sjs_class sjv_i = { -1 };
int32_t sjv_i32_maxvalue;
int32_t sjv_i32_minvalue;
bool sjv_j;
bool sjv_k;
sji_interface sjv_l = { 0 };
sjs_log sjv_log = { -1 };
bool sjv_m;
sjs_class* sjv_n = 0;
sjs_class* sjv_o = 0;
int32_option sjv_p;
int32_t sjv_q;
sji_interface sjv_r = { 0 };
sji_interface2 sjv_s = { 0 };
uint32_t sjv_u32_maxvalue;

void sjf_class(sjs_class* _this);
void sjf_class_as_sji_interface(sjs_class* _this, sji_interface* _return);
void sjf_class_asinterface(sjs_class* _this, int typeId, sjs_interface* _return);
void sjf_class_copy(sjs_class* _this, sjs_class* _from);
void sjf_class_destroy(sjs_class* _this);
void sjf_class_heap(sjs_class* _this);
void sjf_log(sjs_log* _this);
void sjf_log_copy(sjs_log* _this, sjs_log* _from);
void sjf_log_destroy(sjs_log* _this);
void sjf_log_heap(sjs_log* _this);
void main_destroy(void);

#include <lib/common/common.c>
void sjf_class(sjs_class* _this) {
}

void sjf_class_as_sji_interface(sjs_class* _this, sji_interface* _return) {
    _return->_parent = (sjs_object*)_this;
    _return->_vtbl = &sjs_class_interface_vtbl;
}

void sjf_class_asinterface(sjs_class* _this, int typeId, sjs_interface* _return) {
    switch (typeId) {
        case sji_interface_typeId:  {
            sjf_class_as_sji_interface(_this, (sji_interface*)_return);
            break;
        }

        default: {
            _return->_parent = 0;
            break;
        }
    }
}

void sjf_class_copy(sjs_class* _this, sjs_class* _from) {
    _this->bob = _from->bob;
}

void sjf_class_destroy(sjs_class* _this) {
}

void sjf_class_heap(sjs_class* _this) {
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

int main(int argc, char** argv) {
    sjs_class_interface_vtbl.destroy = (void(*)(void*))sjf_class_destroy;
    sjs_class_interface_vtbl.asinterface = (void(*)(sjs_object*,int,sjs_interface*))sjf_class_asinterface;
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
    sjv_a = int32_empty;
    sjv_b = int64_empty;
    sjv_c = uint32_empty;
    sjv_d = uint64_empty;
    sjv_e = float_empty;
    sjv_f = double_empty;
    sjv_g = char_empty;
    sjv_h = void_empty;
    sjv_i._refCount = -1;
    sjv_j = !sjv_a.isvalid;
    sjv_k = ((sjv_i._refCount != -1 ? &sjv_i : 0) == 0);
    sjv_l._parent = 0;
    sjv_m = (sjv_l._parent == 0);
    sjt_value1 = (sjs_class*)malloc(sizeof(sjs_class));
    sjt_value1->_refCount = 1;
    sjt_value1->bob = 0;
    sjf_class_heap(sjt_value1);
    sjv_n = sjt_value1;
    if (sjv_n != 0) {
        sjv_n->_refCount++;
    }

    sjv_o = sjv_n;
    if (sjv_o != 0) {
        sjv_o->_refCount++;
    }

    if (sjv_o->_refCount == -1) { exit(-1); }
    if ((sjv_n != 0)) {
        sjs_class* sjt_capture1 = 0;
        int32_t sjt_value2;
        int32_option value1;

        sjt_capture1 = sjv_n;
        sjt_value2 = sjt_capture1->bob;
        value1.isvalid = true;
        value1.value = sjt_value2;
        sjv_p = value1;
    } else {
        sjv_p = int32_empty;
    }

    if (sjv_a.isvalid) {
        int32_option sjt_getValue1;

        sjt_getValue1 = sjv_a;
        sjv_q = sjt_getValue1.value;
    } else {
        int32_t result2;

        result2 = -1;
        sjv_q = result2;
    }

    sjt_cast1 = sjv_n;
    if (sjt_cast1 != 0) {
        sjf_class_as_sji_interface(sjt_cast1, &sjv_r);
        if (sjv_r._parent != 0) {
            sjv_r._parent->_refCount++;
        }
    } else {
        sjv_r._parent = 0;
    }

    sjt_cast2 = sjv_r;
    if (sjt_cast2._parent != 0) {
        sjt_cast2._vtbl->asinterface(sjt_cast2._parent, sji_interface2_typeId, (sjs_interface*)&sjv_s);
        if (sjv_s._parent != 0) {
            sjv_s._parent->_refCount++;
        }
    } else {
        sjv_s._parent = 0;
    }
    main_destroy();
    return 0;
}

void main_destroy() {

    sjt_value1->_refCount--;
    if (sjt_value1->_refCount <= 0) {
        weakptr_release(sjt_value1);
        sjf_class_destroy(sjt_value1);
        free(sjt_value1);
    }
    if (sjv_n != 0) {
        sjv_n->_refCount--;
        if (sjv_n->_refCount <= 0) {
            weakptr_release(sjv_n);
            sjf_class_destroy(sjv_n);
            free(sjv_n);
        }
    }
    sjv_o->_refCount--;
    if (sjv_o->_refCount <= 0) {
        weakptr_release(sjv_o);
        sjf_class_destroy(sjv_o);
        free(sjv_o);
    }
    if (sjv_r._parent != 0) {
        sjv_r._parent->_refCount--;
        if (sjv_r._parent->_refCount <= 0) {
            sjv_r._vtbl->destroy(sjv_r._parent);
            free(sjv_r._parent);
        }
    }
    if (sjv_s._parent != 0) {
        sjv_s._parent->_refCount--;
        if (sjv_s._parent->_refCount <= 0) {
            sjv_s._vtbl->destroy(sjv_s._parent);
            free(sjv_s._parent);
        }
    }
    if (sjv_i._refCount == 1) { sjf_class_destroy(&sjv_i); }
;
    if (sjv_log._refCount == 1) { sjf_log_destroy(&sjv_log); }
;
}
