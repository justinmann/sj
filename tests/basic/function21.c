#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define sjs_object_typeId 1
#define sjs_interface_typeId 2
#define sjs_func_typeId 3

typedef struct td_sjs_object sjs_object;
typedef struct td_sjs_interface sjs_interface;
typedef struct td_sjs_func sjs_func;

struct td_sjs_object {
    intptr_t _refCount;
};

struct td_sjs_interface {
    sjs_object* _parent;
    void* _vtbl;
};

struct td_sjs_func {
    int _refCount;
};

sjs_func object1 = { -1 };
int32_t void1;

void sjf_func(sjs_func* _this, int32_t* _return);
void sjf_func_bar(sjs_func* _parent, int32_t* _return);
void sjf_func_copy(sjs_func* _this, sjs_func* _from);
void sjf_func_destroy(sjs_func* _this);
void main_destroy(void);

void sjf_func(sjs_func* _this, int32_t* _return) {
    sjf_func_bar(_this, _return);
}

void sjf_func_bar(sjs_func* _parent, int32_t* _return) {
    (*_return) = 9;
}

void sjf_func_copy(sjs_func* _this, sjs_func* _from) {
}

void sjf_func_destroy(sjs_func* _this) {
}

int main(int argc, char** argv) {
    object1._refCount = 1;
    sjf_func(&object1, &void1);
    main_destroy();
    #ifdef _DEBUG
    printf("\npress return to end\n");
    getchar();
    #endif
    return 0;
}

void main_destroy() {

    if (object1._refCount == 1) { sjf_func_destroy(&object1); }
}
