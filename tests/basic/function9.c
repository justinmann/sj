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

int32_t sjt_functionParam1;
int32_t sjt_functionParam2;
int32_t void1;

void sjf_func(int32_t x, int32_t y, int32_t* _return);
void main_destroy(void);

void sjf_func(int32_t x, int32_t y, int32_t* _return) {
    int32_t sjt_math1;
    int32_t sjt_math2;

    sjt_math1 = x;
    sjt_math2 = y;
    (*_return) = sjt_math1 + sjt_math2;
}

int main(int argc, char** argv) {
    sjt_functionParam1 = 2;
    sjt_functionParam2 = 1;
    sjf_func(sjt_functionParam1, sjt_functionParam2, &void1);
    main_destroy();
    #ifdef _DEBUG
    printf("\npress return to end\n");
    getchar();
    #endif
    return 0;
}

void main_destroy() {
}
