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

int32_t sjt_compare1;
int32_t sjt_compare2;
bool sjt_while1;
int32_t sjv_x;

void main_destroy(void);

int main(int argc, char** argv) {
    sjv_x = 10;
    sjt_compare1 = sjv_x;
    sjt_compare2 = 0;
    sjt_while1 = sjt_compare1 > sjt_compare2;
    while (sjt_while1) {
        int32_t sjt_compare3;
        int32_t sjt_compare4;
        int32_t sjt_math1;
        int32_t sjt_math2;

        sjt_math1 = sjv_x;
        sjt_math2 = 1;
        sjv_x = sjt_math1 - sjt_math2;
        sjt_compare3 = sjv_x;
        sjt_compare4 = 0;
        sjt_while1 = sjt_compare3 > sjt_compare4;
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
