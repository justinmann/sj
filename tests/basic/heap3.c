#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define sjs_object_typeId 1
#define sjs_interface_typeId 2
#define sjs_foo_typeId 3
#define sjs_bar_typeId 4

typedef struct td_sjs_object sjs_object;
typedef struct td_sjs_interface sjs_interface;
typedef struct td_sjs_foo sjs_foo;
typedef struct td_sjs_bar sjs_bar;

struct td_sjs_object {
    intptr_t _refCount;
};

struct td_sjs_interface {
    sjs_object* _parent;
    void* _vtbl;
};

struct td_sjs_foo {
    int _refCount;
    int32_t x;
};

struct td_sjs_bar {
    int _refCount;
    sjs_foo f;
};

sjs_foo sjt_call1 = { -1 };
sjs_foo* sjt_dot1 = 0;
sjs_bar* sjt_functionParam1 = 0;
sjs_bar sjv_b = { -1 };

void sjf_bar(sjs_bar* _this);
void sjf_bar_copy(sjs_bar* _this, sjs_bar* _from);
void sjf_bar_destroy(sjs_bar* _this);
void sjf_bar_heap(sjs_bar* _this);
void sjf_foo(sjs_foo* _this);
void sjf_foo_copy(sjs_foo* _this, sjs_foo* _from);
void sjf_foo_destroy(sjs_foo* _this);
void sjf_foo_heap(sjs_foo* _this);
void sjf_func(sjs_bar* b, sjs_foo* _return);
void sjf_func_heap(sjs_bar* b, sjs_foo** _return);
void main_destroy(void);

void sjf_bar(sjs_bar* _this) {
}

void sjf_bar_copy(sjs_bar* _this, sjs_bar* _from) {
    _this->f._refCount = 1;
    sjf_foo_copy(&_this->f, &_from->f);
}

void sjf_bar_destroy(sjs_bar* _this) {
}

void sjf_bar_heap(sjs_bar* _this) {
}

void sjf_foo(sjs_foo* _this) {
}

void sjf_foo_copy(sjs_foo* _this, sjs_foo* _from) {
    _this->x = _from->x;
}

void sjf_foo_destroy(sjs_foo* _this) {
}

void sjf_foo_heap(sjs_foo* _this) {
}

void sjf_func(sjs_bar* b, sjs_foo* _return) {
    sjs_foo* sjt_copy1 = 0;
    sjs_bar* sjt_dot2 = 0;
    sjs_bar* sjt_dot3 = 0;

    sjt_dot2 = b;
    sjt_dot2->f._refCount = 1;
    sjt_dot2->f.x = 2;
    sjf_foo(&sjt_dot2->f);
    sjt_dot3 = b;
    sjt_copy1 = &sjt_dot3->f;
    _return->_refCount = 1;
    sjf_foo_copy(_return, sjt_copy1);
}

void sjf_func_heap(sjs_bar* b, sjs_foo** _return) {
    sjs_foo* sjt_copy2 = 0;
    sjs_bar* sjt_dot4 = 0;
    sjs_bar* sjt_dot5 = 0;

    sjt_dot4 = b;
    sjt_dot4->f._refCount = 1;
    sjt_dot4->f.x = 2;
    sjf_foo(&sjt_dot4->f);
    sjt_dot5 = b;
    sjt_copy2 = &sjt_dot5->f;
    (*_return) = (sjs_foo*)malloc(sizeof(sjs_foo));
    (*_return)->_refCount = 1;
    sjf_foo_copy((*_return), sjt_copy2);
}

int main(int argc, char** argv) {
    sjv_b._refCount = 1;
    sjv_b.f._refCount = 1;
    sjv_b.f.x = 1;
    sjf_foo(&sjv_b.f);
    sjf_bar(&sjv_b);
    sjt_functionParam1 = &sjv_b;
    sjf_func(sjt_functionParam1, &sjt_call1);
    sjt_dot1 = &sjt_call1;
    main_destroy();
    #ifdef _DEBUG
    printf("\npress return to end\n");
    getchar();
    #endif
    return 0;
}

void main_destroy() {

    if (sjt_call1._refCount == 1) { sjf_foo_destroy(&sjt_call1); }
    if (sjv_b._refCount == 1) { sjf_bar_destroy(&sjv_b); }
}
