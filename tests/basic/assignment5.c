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

int32_t sjt_math1;
int32_t sjt_math2;
int32_t sjv_x;
int32_t sjv_y;

void main_destroy(void);

int main(int argc, char** argv) {
    sjv_y = 1;
    sjv_x = 2;
    sjt_math1 = sjv_x;
    sjt_math2 = sjv_y;
    main_destroy();
    #ifdef _DEBUG
    printf("\npress return to end\n");
    getchar();
    #endif
    return 0;
}

void main_destroy() {
}
