#include <lib/common/common.h>

#define sjs_log_typeId 1
#define sjs_class_typeId 2
#define sji_iface_vtbl_typeId 3
#define sji_iface_typeId 4

typedef struct td_sjs_log sjs_log;
typedef struct td_sjs_class sjs_class;
typedef struct td_sji_iface_vtbl sji_iface_vtbl;
typedef struct td_sji_iface sji_iface;

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
};

struct td_sji_iface {
    sjs_object* _parent;
    sji_iface_vtbl* _vtbl;
};

sji_iface_vtbl sjs_class_iface_vtbl;
int32_t sjv_loglevel_debug;
int32_t sjv_loglevel_error;
int32_t sjv_loglevel_fatal;
int32_t sjv_loglevel_info;
int32_t sjv_loglevel_trace;
int32_t sjv_loglevel_warn;

int32_t result1;
sjs_class* sjt_parent1 = 0;
sjs_class* sjv_c = 0;
void* sjv_emptystringdata;
float sjv_f32_pi;
int32_t sjv_i32_maxvalue;
int32_t sjv_i32_minvalue;
sji_iface sjv_keep = { 0 };
sjs_log sjv_log = { -1 };
uint32_t sjv_u32_maxvalue;

void sjf_class_as_sji_iface(sjs_class* _this, sji_iface* _return);
void sjf_class_asinterface(sjs_class* _this, int typeId, sjs_interface* _return);
void sjf_class_copy(sjs_class* _this, sjs_class* _from);
void sjf_class_destroy(sjs_class* _this);
void sjf_class_func(sjs_class* _parent);
void sjf_class_heap(sjs_class* _this);
void sjf_log(sjs_log* _this);
void sjf_log_copy(sjs_log* _this, sjs_log* _from);
void sjf_log_destroy(sjs_log* _this);
void sjf_log_heap(sjs_log* _this);
void sjf_store_heap(sji_iface a, sji_iface* _return);
void main_destroy(void);

#include <lib/common/common.c>
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

void sjf_class_func(sjs_class* _parent) {
    sjs_class* sjt_cast1 = 0;
    sji_iface sjt_functionParam1 = { 0 };
    sji_iface sjt_void1 = { 0 };

    sjt_cast1 = _parent;
    sjf_class_as_sji_iface(sjt_cast1, &sjt_functionParam1);
    if (sjt_functionParam1._parent != 0) {
        sjt_functionParam1._parent->_refCount++;
    }

    sjf_store_heap(sjt_functionParam1, &sjt_void1);

    if (sjt_functionParam1._parent != 0) {
        sjt_functionParam1._parent->_refCount--;
        if (sjt_functionParam1._parent->_refCount <= 0) {
            sjt_functionParam1._vtbl->destroy(sjt_functionParam1._parent);
            free(sjt_functionParam1._parent);
        }
    }
    if (sjt_void1._parent != 0) {
        sjt_void1._parent->_refCount--;
        if (sjt_void1._parent->_refCount <= 0) {
            sjt_void1._vtbl->destroy(sjt_void1._parent);
            free(sjt_void1._parent);
        }
    }
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

void sjf_store_heap(sji_iface a, sji_iface* _return) {
    if (sjv_keep._parent != 0) {
        sjv_keep._parent->_refCount--;
        if (sjv_keep._parent->_refCount <= 0) {
            sjv_keep._vtbl->destroy(sjv_keep._parent);
            free(sjv_keep._parent);
        }
    }

    sjv_keep = a;
    if (sjv_keep._parent != 0) {
        sjv_keep._parent->_refCount++;
    }

    (*_return) = sjv_keep;
    if ((*_return)._parent != 0) {
        (*_return)._parent->_refCount++;
    }
}

int main(int argc, char** argv) {
    sjs_class_iface_vtbl.destroy = (void(*)(void*))sjf_class_destroy;
    sjs_class_iface_vtbl.asinterface = (void(*)(sjs_object*,int,sjs_interface*))sjf_class_asinterface;
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
    sjv_keep._parent = 0;
    sjv_c = (sjs_class*)malloc(sizeof(sjs_class));
    sjv_c->_refCount = 1;
    sjf_class_heap(sjv_c);
    sjt_parent1 = sjv_c;
    sjt_parent1->_refCount++;
    sjf_class_func(sjt_parent1);
    main_destroy();
    return 0;
}

void main_destroy() {

    sjt_parent1->_refCount--;
    if (sjt_parent1->_refCount <= 0) {
        weakptr_release(sjt_parent1);
        sjf_class_destroy(sjt_parent1);
        free(sjt_parent1);
    }
    sjv_c->_refCount--;
    if (sjv_c->_refCount <= 0) {
        weakptr_release(sjv_c);
        sjf_class_destroy(sjv_c);
        free(sjv_c);
    }
    if (sjv_keep._parent != 0) {
        sjv_keep._parent->_refCount--;
        if (sjv_keep._parent->_refCount <= 0) {
            sjv_keep._vtbl->destroy(sjv_keep._parent);
            free(sjv_keep._parent);
        }
    }
    if (sjv_log._refCount == 1) { sjf_log_destroy(&sjv_log); }
;
}
