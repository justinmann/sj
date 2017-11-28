#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct td_int32_option int32_option;
struct td_int32_option {
    bool isEmpty;
    int32_t value;
};
const int32_option int32_empty = { true };

typedef struct td_uint32_option uint32_option;
struct td_uint32_option {
    bool isEmpty;
    uint32_t value;
};
const uint32_option uint32_empty = { true };

typedef struct td_int64_option int64_option;
struct td_int64_option {
    bool isEmpty;
    int64_t value;
};
const int64_option int64_empty = { true };

typedef struct td_uint64_option uint64_option;
struct td_uint64_option {
    bool isEmpty;
    uint64_t value;
};
const uint64_option uint64_empty = { true };

typedef struct td_uintptr_option uintptr_option;
struct td_uintptr_option {
    bool isEmpty;
    uintptr_t value;
};
const uintptr_option uintptr_empty = { true };

typedef struct td_char_option char_option;
struct td_char_option {
    bool isEmpty;
    char value;
};
const char_option char_empty = { true };

typedef struct td_float_option float_option;
struct td_float_option {
    bool isEmpty;
    float value;
};
const float_option float_empty = { true };

typedef struct td_double_option double_option;
struct td_double_option {
    bool isEmpty;
    double value;
};
const double_option double_empty = { true };

#define sjs_object_typeId 1
#define sjs_class_typeId 2
#define sji_interface_typeId 3
#define sjs_class_heap_typeId 4
#define sji_interface2_typeId 5

typedef struct td_sjs_object sjs_object;
typedef struct td_sjs_class sjs_class;
typedef struct td_sji_interface sji_interface;
typedef struct td_sjs_class_heap sjs_class_heap;
typedef struct td_sji_interface2 sji_interface2;

struct td_sjs_object {
    intptr_t _refCount;
};

struct td_sjs_class {
    int32_t bob;
};

struct td_sji_interface {
    intptr_t _refCount;
    sjs_object* _parent;
    void (*destroy)(void* _this);
    sjs_object* (*asInterface)(sjs_object* _this, int typeId);
};

struct td_sjs_class_heap {
    intptr_t _refCount;
    int32_t bob;
};

struct td_sji_interface2 {
    intptr_t _refCount;
    sjs_object* _parent;
    void (*destroy)(void* _this);
    sjs_object* (*asInterface)(sjs_object* _this, int typeId);
};

sjs_class_heap* sjt_cast1;
sji_interface* sjt_cast2;
sjs_class_heap* sjt_getValue1;
bool sjt_ifElse1;
bool sjt_ifElse2;
int32_option sjt_isEmpty1;
sjs_class_heap* sjt_isEmpty2;
sji_interface* sjt_isEmpty3;
sjs_class_heap* sjt_isEmpty4;
int32_option sjt_isEmpty5;
sjs_class_heap* sjt_value1;
int32_option sjv_a;
int64_option sjv_b;
uint32_option sjv_c;
uint64_option sjv_d;
float_option sjv_e;
double_option sjv_f;
char_option sjv_g;
uintptr_option sjv_h;
sjs_class_heap* sjv_i;
bool sjv_j;
bool sjv_k;
sji_interface* sjv_l;
bool sjv_m;
sjs_class_heap* sjv_n;
sjs_class_heap* sjv_o;
int32_option sjv_p;
int32_t sjv_q;
sji_interface* sjv_r;
sji_interface2* sjv_s;

void sjf_class(sjs_class* _this);
sjs_object* sjf_class_asInterface(sjs_class* _this, int typeId);
sji_interface* sjf_class_as_sji_interface(sjs_class* _this);
void sjf_class_copy(sjs_class* _this, sjs_class* to);
void sjf_class_destroy(sjs_class* _this);
void sjf_class_heap(sjs_class_heap* _this);
sjs_object* sjf_class_heap_asInterface(sjs_class_heap* _this, int typeId);
sji_interface* sjf_class_heap_as_sji_interface(sjs_class_heap* _this);
void sji_interface2_destroy(sji_interface2* _this);
void sji_interface_destroy(sji_interface* _this);
void main_destroy(void);

void sjf_class(sjs_class* _this) {
}

sjs_object* sjf_class_asInterface(sjs_class* _this, int typeId) {
    switch (typeId) {
        case sji_interface_typeId:  {
            return (sjs_object*)sjf_class_as_sji_interface(_this);
        }
    }

    return 0;
}

sji_interface* sjf_class_as_sji_interface(sjs_class* _this) {
    sji_interface* _interface;
    _interface = (sji_interface*)malloc(sizeof(sji_interface));
    _interface->_refCount = 1;
    _interface->_parent = (sjs_object*)_this;
    _interface->_parent->_refCount++;
    _interface->destroy = (void(*)(void*))sjf_class_destroy;
    _interface->asInterface = (sjs_object*(*)(sjs_object*,int))sjf_class_asInterface;

    return _interface;
}

void sjf_class_copy(sjs_class* _this, sjs_class* to) {
    _this->bob = to->bob;
}

void sjf_class_destroy(sjs_class* _this) {
}

void sjf_class_heap(sjs_class_heap* _this) {
}

sjs_object* sjf_class_heap_asInterface(sjs_class_heap* _this, int typeId) {
    switch (typeId) {
        case sji_interface_typeId:  {
            return (sjs_object*)sjf_class_heap_as_sji_interface(_this);
        }
    }

    return 0;
}

sji_interface* sjf_class_heap_as_sji_interface(sjs_class_heap* _this) {
    sji_interface* _interface;
    _interface = (sji_interface*)malloc(sizeof(sji_interface));
    _interface->_refCount = 1;
    _interface->_parent = (sjs_object*)_this;
    _interface->_parent->_refCount++;
    _interface->destroy = (void(*)(void*))sjf_class_destroy;
    _interface->asInterface = (sjs_object*(*)(sjs_object*,int))sjf_class_heap_asInterface;

    return _interface;
}

void sji_interface2_destroy(sji_interface2* _this) {
    _this->_parent->_refCount--;
    if (_this->_parent->_refCount <= 0) {
        _this->destroy(_this->_parent);
        free(_this->_parent);
    }
}

void sji_interface_destroy(sji_interface* _this) {
    _this->_parent->_refCount--;
    if (_this->_parent->_refCount <= 0) {
        _this->destroy(_this->_parent);
        free(_this->_parent);
    }
}

int main(int argc, char** argv) {
    sjv_a = int32_empty;
    sjv_b = int64_empty;
    sjv_c = uint32_empty;
    sjv_d = uint64_empty;
    sjv_e = float_empty;
    sjv_f = double_empty;
    sjv_g = char_empty;
    sjv_h = uintptr_empty;
    sjv_i = 0;
    if (sjv_i != 0) {
        sjv_i->_refCount++;
    }

    sjt_isEmpty1 = sjv_a;
    sjv_j = sjt_isEmpty1.isEmpty;
    sjt_isEmpty2 = sjv_i;
    if (sjt_isEmpty2 != 0) {
        sjt_isEmpty2->_refCount++;
    }

    sjv_k = (sjt_isEmpty2 == 0);
    sjv_l = 0;
    if (sjv_l != 0) {
        sjv_l->_refCount++;
    }

    sjt_isEmpty3 = sjv_l;
    if (sjt_isEmpty3 != 0) {
        sjt_isEmpty3->_refCount++;
    }

    sjv_m = (sjt_isEmpty3 == 0);
    sjt_value1 = (sjs_class_heap*)malloc(sizeof(sjs_class_heap));
    sjt_value1->_refCount = 1;
    sjt_value1->bob = 0;
    sjf_class_heap(sjt_value1);
    sjv_n = sjt_value1;
    if (sjv_n != 0) {
        sjv_n->_refCount++;
    }

    sjt_getValue1 = sjv_n;
    if (sjt_getValue1 != 0) {
        sjt_getValue1->_refCount++;
    }

    if (sjt_getValue1 == 0) { exit(-1); };
    sjv_o = sjt_getValue1;
    sjv_o->_refCount++;
    sjt_isEmpty4 = sjv_n;
    if (sjt_isEmpty4 != 0) {
        sjt_isEmpty4->_refCount++;
    }

    sjt_ifElse1 = (sjt_isEmpty4 == 0);
    if (sjt_ifElse1) {
        sjv_p = int32_empty;
    } else {
        int32_t dotTemp1;
        sjs_class* sjt_dot1;
        sjs_class_heap* sjt_getValue2;
        int32_t sjt_value2;
        int32_option value1;

        sjt_getValue2 = sjv_n;
        if (sjt_getValue2 != 0) {
            sjt_getValue2->_refCount++;
        }

        sjt_dot1 = (sjs_class*)(((char*)sjt_getValue2) + sizeof(intptr_t));
        dotTemp1 = sjt_dot1->bob;
        sjt_value2 = dotTemp1;
        value1.isEmpty = false;
        value1.value = sjt_value2;
        sjv_p = value1;

        if (sjt_getValue2 != 0) {
            sjt_getValue2->_refCount--;
            if (sjt_getValue2->_refCount <= 0) {
                sjf_class_destroy((sjs_class*)(((char*)sjt_getValue2) + sizeof(intptr_t)));
            }
        }
    }

    sjt_isEmpty5 = sjv_a;
    sjt_ifElse2 = sjt_isEmpty5.isEmpty;
    if (sjt_ifElse2) {
        sjv_q = -1;
    } else {
        int32_option sjt_getValue3;

        sjt_getValue3 = sjv_a;
        sjv_q = sjt_getValue3.value;
    }

    sjt_cast1 = sjv_n;
    if (sjt_cast1 != 0) {
        sjt_cast1->_refCount++;
    }

    if (sjt_cast1 != 0) {
        sjv_r = (sji_interface*)sjf_class_heap_as_sji_interface(sjt_cast1);
    } else {
        sjv_r = 0;
        if (sjv_r != 0) {
            sjv_r->_refCount++;
        }
    }

    sjt_cast2 = sjv_r;
    if (sjt_cast2 != 0) {
        sjt_cast2->_refCount++;
    }

    if (sjt_cast2 != 0) {
        sjv_s = (sji_interface2*)sjt_cast2->asInterface(sjt_cast2->_parent, sji_interface2_typeId);
    } else {
        sjv_s = 0;
        if (sjv_s != 0) {
            sjv_s->_refCount++;
        }
    }
    main_destroy();
    return 0;
}

void main_destroy() {

    if (sjt_cast1 != 0) {
        sjt_cast1->_refCount--;
        if (sjt_cast1->_refCount <= 0) {
            sjf_class_destroy((sjs_class*)(((char*)sjt_cast1) + sizeof(intptr_t)));
        }
    }
    if (sjt_cast2 != 0) {
        sjt_cast2->_refCount--;
        if (sjt_cast2->_refCount <= 0) {
            sji_interface_destroy(sjt_cast2);
        }
    }
    if (sjt_getValue1 != 0) {
        sjt_getValue1->_refCount--;
        if (sjt_getValue1->_refCount <= 0) {
            sjf_class_destroy((sjs_class*)(((char*)sjt_getValue1) + sizeof(intptr_t)));
        }
    }
    if (sjt_isEmpty2 != 0) {
        sjt_isEmpty2->_refCount--;
        if (sjt_isEmpty2->_refCount <= 0) {
            sjf_class_destroy((sjs_class*)(((char*)sjt_isEmpty2) + sizeof(intptr_t)));
        }
    }
    if (sjt_isEmpty3 != 0) {
        sjt_isEmpty3->_refCount--;
        if (sjt_isEmpty3->_refCount <= 0) {
            sji_interface_destroy(sjt_isEmpty3);
        }
    }
    if (sjt_isEmpty4 != 0) {
        sjt_isEmpty4->_refCount--;
        if (sjt_isEmpty4->_refCount <= 0) {
            sjf_class_destroy((sjs_class*)(((char*)sjt_isEmpty4) + sizeof(intptr_t)));
        }
    }
    sjt_value1->_refCount--;
    if (sjt_value1->_refCount <= 0) {
        sjf_class_destroy((sjs_class*)(((char*)sjt_value1) + sizeof(intptr_t)));
    }
    if (sjv_i != 0) {
        sjv_i->_refCount--;
        if (sjv_i->_refCount <= 0) {
            sjf_class_destroy((sjs_class*)(((char*)sjv_i) + sizeof(intptr_t)));
        }
    }
    if (sjv_l != 0) {
        sjv_l->_refCount--;
        if (sjv_l->_refCount <= 0) {
            sji_interface_destroy(sjv_l);
        }
    }
    if (sjv_n != 0) {
        sjv_n->_refCount--;
        if (sjv_n->_refCount <= 0) {
            sjf_class_destroy((sjs_class*)(((char*)sjv_n) + sizeof(intptr_t)));
        }
    }
    sjv_o->_refCount--;
    if (sjv_o->_refCount <= 0) {
        sjf_class_destroy((sjs_class*)(((char*)sjv_o) + sizeof(intptr_t)));
    }
    if (sjv_r != 0) {
        sjv_r->_refCount--;
        if (sjv_r->_refCount <= 0) {
            sji_interface_destroy(sjv_r);
        }
    }
    if (sjv_s != 0) {
        sjv_s->_refCount--;
        if (sjv_s->_refCount <= 0) {
            sji_interface2_destroy(sjv_s);
        }
    }
}
