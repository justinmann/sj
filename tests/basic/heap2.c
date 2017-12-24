#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define sjs_object_typeId 1
#define sjs_interface_typeId 2
#define sjs_data_typeId 3
#define sjs_class_typeId 4

typedef struct td_sjs_object sjs_object;
typedef struct td_sjs_interface sjs_interface;
typedef struct td_sjs_data sjs_data;
typedef struct td_sjs_class sjs_class;

struct td_sjs_object {
    intptr_t _refCount;
};

struct td_sjs_interface {
    sjs_object* _parent;
    void* _vtbl;
};

struct td_sjs_data {
    int _refCount;
    int32_t x;
};

struct td_sjs_class {
    int _refCount;
    sjs_data data;
};

sjs_class* sjt_parent1 = 0;
sjs_class sjv_c = { -1 };
sjs_data sjv_d = { -1 };

void sjf_class(sjs_class* _this);
void sjf_class_copy(sjs_class* _this, sjs_class* _from);
void sjf_class_destroy(sjs_class* _this);
void sjf_class_get(sjs_class* _parent, sjs_data* _return);
void sjf_class_get_heap(sjs_class* _parent, sjs_data** _return);
void sjf_class_heap(sjs_class* _this);
void sjf_data(sjs_data* _this);
void sjf_data_copy(sjs_data* _this, sjs_data* _from);
void sjf_data_destroy(sjs_data* _this);
void sjf_data_heap(sjs_data* _this);
void main_destroy(void);

void sjf_class(sjs_class* _this) {
}

void sjf_class_copy(sjs_class* _this, sjs_class* _from) {
    _this->data._refCount = 1;
    sjf_data_copy(&_this->data, &_from->data);
}

void sjf_class_destroy(sjs_class* _this) {
}

void sjf_class_get(sjs_class* _parent, sjs_data* _return) {
    sjs_data* sjt_copy1 = 0;
    sjs_class* sjt_dot1 = 0;

    sjt_dot1 = _parent;
    sjt_copy1 = &(sjt_dot1)->data;
    _return->_refCount = 1;
    sjf_data_copy(_return, sjt_copy1);
}

void sjf_class_get_heap(sjs_class* _parent, sjs_data** _return) {
    sjs_data* sjt_copy2 = 0;
    sjs_class* sjt_dot2 = 0;

    sjt_dot2 = _parent;
    sjt_copy2 = &(sjt_dot2)->data;
    (*_return) = (sjs_data*)malloc(sizeof(sjs_data));
    (*_return)->_refCount = 1;
    sjf_data_copy((*_return), sjt_copy2);
}

void sjf_class_heap(sjs_class* _this) {
}

void sjf_data(sjs_data* _this) {
}

void sjf_data_copy(sjs_data* _this, sjs_data* _from) {
    _this->x = _from->x;
}

void sjf_data_destroy(sjs_data* _this) {
}

void sjf_data_heap(sjs_data* _this) {
}

int main(int argc, char** argv) {
    sjv_c._refCount = 1;
    sjv_c.data._refCount = 1;
    sjv_c.data.x = 0;
    sjf_data(&sjv_c.data);
    sjf_class(&sjv_c);
    sjt_parent1 = &sjv_c;
    sjf_class_get(sjt_parent1, &sjv_d);
    main_destroy();
    #ifdef _DEBUG
    printf("\npress return to end\n");
    getchar();
    #endif
    return 0;
}

void main_destroy() {

    if (sjv_c._refCount == 1) { sjf_class_destroy(&sjv_c); }
    if (sjv_d._refCount == 1) { sjf_data_destroy(&sjv_d); }
}
