#include <stdbool.h>
#include <stdint.h>
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

#define sji_interface_typeId 1
#define sji_interface2_typeId 2
#define sjs_class_typeId 3
#define sjs_object_typeId 4

typedef struct td_sji_interface sji_interface;
typedef struct td_sji_interface2 sji_interface2;
typedef struct td_sjs_class sjs_class;
typedef struct td_sjs_object sjs_object;

struct td_sji_interface {
    int _refCount;
    sjs_object* _parent;
    void (*destroy)(sjs_object* _this);
    sjs_object* (*asInterface)(sjs_object* _this, int typeId);
};

struct td_sji_interface2 {
    int _refCount;
    sjs_object* _parent;
    void (*destroy)(sjs_object* _this);
    sjs_object* (*asInterface)(sjs_object* _this, int typeId);
};

struct td_sjs_class {
    int _refCount;
    int32_t bob;
};

struct td_sjs_object {
    int _refCount;
};

void sjf_class(sjs_class* _this, sjs_class** _return);
sjs_object* sjf_class_asInterface(sjs_class* _this, int typeId);
sji_interface* sjf_class_as_sji_interface(sjs_class* _this);
void sjf_class_destroy(sjs_class* _this);
void sjf_global(void);
void sji_interface2_destroy(sji_interface2* _this);
void sji_interface_destroy(sji_interface* _this);

void sjf_class(sjs_class* _this, sjs_class** _return) {
    _this->_refCount++;

    *_return = _this;
}

sjs_object* sjf_class_asInterface(sjs_class* _this, int typeId) {
    switch (typeId) {
        case sji_interface_typeId: return (sjs_object*)sjf_class_as_sji_interface(_this);
    }

    return 0;
}

sji_interface* sjf_class_as_sji_interface(sjs_class* _this) {
    sji_interface* _interface = (sji_interface*)malloc(sizeof(sji_interface));
    _interface->_refCount = 1;
    _interface->_parent = (sjs_object*)_this;
    _interface->_parent->_refCount++;
    _interface->destroy = (void(*)(sjs_object*))sjf_class_destroy;
    _interface->asInterface = (sjs_object*(*)(sjs_object*,int))sjf_class_asInterface;
    return _interface;
}

void sjf_class_destroy(sjs_class* _this) {
}

void sjf_global(void) {
    sjs_class sjd_temp1;
    int32_option a;
    int64_option b;
    uint32_option c;
    uint64_option d;
    float_option e;
    double_option f;
    char_option g;
    uintptr_option h;
    sjs_class* i;
    int32_option ifResult1;
    int32_t ifResult2;
    bool j;
    bool k;
    sji_interface* l;
    bool m;
    sjs_class* n;
    sjs_class* o;
    int32_option p;
    int32_t q;
    sji_interface* r;
    sji_interface* result1;
    sji_interface2* result2;
    sji_interface2* s;
    sjs_class* sjv_temp1;

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

    j = a.isEmpty;

    k = (i == 0);

    l = 0;

    if (l != 0) {
        l->_refCount++;
    }

    m = (l == 0);

    sjv_temp1 = &sjd_temp1;

    sjv_temp1->_refCount = 1;

    sjv_temp1->bob = 0;

    sjf_class(sjv_temp1, &sjv_temp1);

    n = sjv_temp1;

    if (n != 0) {
        n->_refCount++;
    }

    if (n == 0) { exit(-1); };

    o = n;

    o->_refCount++;

    if (n == 0) {
        ifResult1 = int32_empty;
    } else {
        int32_t dotTemp1;
        int32_option value1;

        dotTemp1 = n->bob;
        value1.isEmpty = false;
        value1.value = dotTemp1;
        ifResult1 = value1;
    }

    p = ifResult1;

    if (a.isEmpty) {
        ifResult2 = -1;
    } else {
        ifResult2 = a.value;
    }

    q = ifResult2;

    if (n != 0) {
        result1 = sjf_class_as_sji_interface(n);
    } else {
        result1 = 0;
    }

    r = result1;

    if (r != 0) {
        r->_refCount++;
    }

    if (result1 != 0) {
        result1->_refCount--;
        if (result1->_refCount <= 0) {
            sji_interface_destroy(result1);
            free(result1);
        }
    }

    if (r != 0) {
        result2 = (sji_interface2*)r->asInterface(r->_parent, sji_interface2_typeId);
    } else {
        result2 = 0;
    }

    s = result2;

    if (s != 0) {
        s->_refCount++;
    }

    if (result2 != 0) {
        result2->_refCount--;
        if (result2->_refCount <= 0) {
            sji_interface2_destroy(result2);
            free(result2);
        }
    }

    if (r != 0) {
        r->_refCount--;
        if (r->_refCount <= 0) {
            sji_interface_destroy(r);
            free(r);
        }
    }
    if (s != 0) {
        s->_refCount--;
        if (s->_refCount <= 0) {
            sji_interface2_destroy(s);
            free(s);
        }
    }
    sjf_class_destroy(&sjd_temp1);
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
    sjf_global();

    return 0;
}
