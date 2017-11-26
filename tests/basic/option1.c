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
    int _refCount;
};

struct td_sjs_class {
    int32_t bob;
};

struct td_sji_interface {
    int _refCount;
    sjs_object* _parent;
    void (*destroy)(void* _this);
    sjs_object* (*asInterface)(sjs_object* _this, int typeId);
};

struct td_sjs_class_heap {
    int _refCount;
    int32_t bob;
};

struct td_sji_interface2 {
    int _refCount;
    sjs_object* _parent;
    void (*destroy)(void* _this);
    sjs_object* (*asInterface)(sjs_object* _this, int typeId);
};

int32_option a;
int64_option b;
uint32_option c;
uint64_option d;
float_option e;
double_option f;
char_option g;
uintptr_option h;
sjs_class_heap* i;
bool j;
bool k;
sji_interface* l;
bool m;
sjs_class_heap* n;
sjs_class_heap* o;
int32_option p;
int32_t q;
sji_interface* r;
sji_interface2* s;
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
void main_destroy();

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

int main() {
    a = int32_empty;
    b = int64_empty;
    c = uint32_empty;
    d = uint64_empty;
    e = float_empty;
    f = double_empty;
    g = char_empty;
    h = uintptr_empty;
    i = 0;
    if (i != 0) {
        i->_refCount++;
    }

    sjt_isEmpty1 = a;
    j = sjt_isEmpty1.isEmpty;
    sjt_isEmpty2 = i;
    if (sjt_isEmpty2 != 0) {
        sjt_isEmpty2->_refCount++;
    }

    k = (sjt_isEmpty2 == 0);
    l = 0;
    if (l != 0) {
        l->_refCount++;
    }

    sjt_isEmpty3 = l;
    if (sjt_isEmpty3 != 0) {
        sjt_isEmpty3->_refCount++;
    }

    m = (sjt_isEmpty3 == 0);
    sjt_value1 = (sjs_class_heap*)malloc(sizeof(sjs_class_heap));
    sjt_value1->_refCount = 1;
    sjt_value1->bob = 0;
    sjf_class_heap(sjt_value1);
    n = sjt_value1;
    if (n != 0) {
        n->_refCount++;
    }

    sjt_getValue1 = n;
    if (sjt_getValue1 != 0) {
        sjt_getValue1->_refCount++;
    }

    if (sjt_getValue1 == 0) { exit(-1); };
    o = sjt_getValue1;
    o->_refCount++;
    sjt_isEmpty4 = n;
    if (sjt_isEmpty4 != 0) {
        sjt_isEmpty4->_refCount++;
    }

    sjt_ifElse1 = (sjt_isEmpty4 == 0);
    if (sjt_ifElse1) {
        p = int32_empty;
    } else {
        int32_t dotTemp1;
        sjs_class* sjt_dot1;
        sjs_class_heap* sjt_getValue2;
        int32_t sjt_value2;
        int32_option value1;

        sjt_getValue2 = n;
        if (sjt_getValue2 != 0) {
            sjt_getValue2->_refCount++;
        }

        sjt_dot1 = (sjs_class*)(((char*)sjt_getValue2) + sizeof(int));
        dotTemp1 = sjt_dot1->bob;
        sjt_value2 = dotTemp1;
        value1.isEmpty = false;
        value1.value = sjt_value2;
        p = value1;

        if (sjt_getValue2 != 0) {
            sjt_getValue2->_refCount--;
            if (sjt_getValue2->_refCount <= 0) {
                sjf_class_destroy((sjs_class*)(((char*)sjt_getValue2) + sizeof(int)));
            }
        }
    }

    sjt_isEmpty5 = a;
    sjt_ifElse2 = sjt_isEmpty5.isEmpty;
    if (sjt_ifElse2) {
        q = -1;
    } else {
        int32_option sjt_getValue3;

        sjt_getValue3 = a;
        q = sjt_getValue3.value;
    }

    sjt_cast1 = n;
    if (sjt_cast1 != 0) {
        sjt_cast1->_refCount++;
    }

    if (sjt_cast1 != 0) {
        r = (sji_interface*)sjf_class_heap_as_sji_interface(sjt_cast1);
    } else {
        r = 0;
        if (r != 0) {
            r->_refCount++;
        }
    }

    sjt_cast2 = r;
    if (sjt_cast2 != 0) {
        sjt_cast2->_refCount++;
    }

    if (sjt_cast2 != 0) {
        s = (sji_interface2*)sjt_cast2->asInterface(sjt_cast2->_parent, sji_interface2_typeId);
    } else {
        s = 0;
        if (s != 0) {
            s->_refCount++;
        }
    }
    main_destroy();
    return 0;
}

void main_destroy() {

    if (i != 0) {
        i->_refCount--;
        if (i->_refCount <= 0) {
            sjf_class_destroy((sjs_class*)(((char*)i) + sizeof(int)));
        }
    }
    if (l != 0) {
        l->_refCount--;
        if (l->_refCount <= 0) {
            sji_interface_destroy(l);
        }
    }
    if (n != 0) {
        n->_refCount--;
        if (n->_refCount <= 0) {
            sjf_class_destroy((sjs_class*)(((char*)n) + sizeof(int)));
        }
    }
    o->_refCount--;
    if (o->_refCount <= 0) {
        sjf_class_destroy((sjs_class*)(((char*)o) + sizeof(int)));
    }
    if (r != 0) {
        r->_refCount--;
        if (r->_refCount <= 0) {
            sji_interface_destroy(r);
        }
    }
    if (s != 0) {
        s->_refCount--;
        if (s->_refCount <= 0) {
            sji_interface2_destroy(s);
        }
    }
    if (sjt_cast1 != 0) {
        sjt_cast1->_refCount--;
        if (sjt_cast1->_refCount <= 0) {
            sjf_class_destroy((sjs_class*)(((char*)sjt_cast1) + sizeof(int)));
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
            sjf_class_destroy((sjs_class*)(((char*)sjt_getValue1) + sizeof(int)));
        }
    }
    if (sjt_isEmpty2 != 0) {
        sjt_isEmpty2->_refCount--;
        if (sjt_isEmpty2->_refCount <= 0) {
            sjf_class_destroy((sjs_class*)(((char*)sjt_isEmpty2) + sizeof(int)));
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
            sjf_class_destroy((sjs_class*)(((char*)sjt_isEmpty4) + sizeof(int)));
        }
    }
    sjt_value1->_refCount--;
    if (sjt_value1->_refCount <= 0) {
        sjf_class_destroy((sjs_class*)(((char*)sjt_value1) + sizeof(int)));
    }
}
