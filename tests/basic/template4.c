#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define sjs_object_typeId 1
#define sjs_interface_typeId 2

typedef struct td_sjs_object sjs_object;
typedef struct td_sjs_interface sjs_interface;

struct td_sjs_object {
    intptr_t _refCount;
};

struct td_sjs_interface {
    sjs_object* _parent;
    void* _vtbl;
};

int32_t sjv_d;

void sjf_class_func(int32_t* _return);
void sjf_func(void);
void main_destroy(void);

void sjf_class_func(int32_t* _return) {
    (*_return) = 1;
}

void sjf_func(void) {
}

int main(int argc, char** argv) {
    sjf_class_func(&sjv_d);
    main_destroy();
    #ifdef _DEBUG
    printf("\npress return to end\n");
    getchar();
    #endif
    return 0;
}

void main_destroy() {
}
