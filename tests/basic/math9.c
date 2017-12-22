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
    int32_t x;
};

int32_t result1;
sjs_foo* sjt_dot1 = 0;
int32_t sjt_negate1;
int32_t sjv_a;
sjs_foo sjv_f = { -1 };

void sjf_foo(sjs_foo* _this);
void sjf_foo_copy(sjs_foo* _this, sjs_foo* _from);
void sjf_foo_destroy(sjs_foo* _this);
void sjf_foo_heap(sjs_foo* _this);
void main_destroy(void);

void sjf_foo(sjs_foo* _this) {
}

void sjf_foo_copy(sjs_foo* _this, sjs_foo* _from) {
    _this->x = _from->x;
}

void sjf_foo_destroy(sjs_foo* _this) {
}

void sjf_foo_heap(sjs_foo* _this) {
}

int main(int argc, char** argv) {
    sjv_f._refCount = 1;
    sjv_f.x = 1;
    sjf_foo(&sjv_f);
    sjt_dot1 = &sjv_f;
    sjt_negate1 = (sjt_dot1)->x;
    result1 = -sjt_negate1;
    sjv_a = result1;
    main_destroy();
    #ifdef _DEBUG
    printf("\npress return to end\n");
    getchar();
    #endif
    return 0;
}

void main_destroy() {

    if (sjv_f._refCount == 1) { sjf_foo_destroy(&sjv_f); }
}
