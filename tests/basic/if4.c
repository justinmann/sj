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

bool sjt_ifElse1;

void main_destroy(void);

int main(int argc, char** argv) {
    sjt_ifElse1 = false;
    if (sjt_ifElse1) {
    } else {
        bool sjt_ifElse2;

        sjt_ifElse2 = true;
        if (sjt_ifElse2) {
        }
    }
    main_destroy();
    #ifdef _DEBUG
    printf("\npress return to end\n");
    getchar();
    #endif
    return 0;
}

void main_destroy() {
}
