#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define sjs_object_typeId 1
#define sjs_interface_typeId 2
#define sjs_foo_typeId 3

typedef struct td_sjs_object sjs_object;
typedef struct td_sjs_interface sjs_interface;
typedef struct td_sjs_foo sjs_foo;

struct td_sjs_object {
    intptr_t _refCount;
};

struct td_sjs_interface {
    sjs_object* _parent;
    void* _vtbl;
};

struct td_sjs_foo {
    int _refCount;
};

sjs_foo sjv_a = { -1 };

void sjf_bar(sjs_foo* _return);
void sjf_bar_heap(sjs_foo** _return);
void sjf_foo(sjs_foo* _this);
void sjf_foo_copy(sjs_foo* _this, sjs_foo* _from);
void sjf_foo_destroy(sjs_foo* _this);
void sjf_foo_heap(sjs_foo* _this);
void main_destroy(void);

void sjf_bar(sjs_foo* _return) {
    _return->_refCount = 1;
    sjf_foo(_return);
}

void sjf_bar_heap(sjs_foo** _return) {
    (*_return) = (sjs_foo*)malloc(sizeof(sjs_foo));
    (*_return)->_refCount = 1;
    sjf_foo_heap((*_return));
}

void sjf_foo(sjs_foo* _this) {
}

void sjf_foo_copy(sjs_foo* _this, sjs_foo* _from) {
}

void sjf_foo_destroy(sjs_foo* _this) {
}

void sjf_foo_heap(sjs_foo* _this) {
}

int main(int argc, char** argv) {
    sjf_bar(&sjv_a);
    main_destroy();
    #ifdef _DEBUG
    printf("\npress return to end\n");
    getchar();
    #endif
    return 0;
}

void main_destroy() {

    if (sjv_a._refCount == 1) { sjf_foo_destroy(&sjv_a); }
}
