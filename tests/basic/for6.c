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

int32_t sjt_forEnd1;
int32_t sjt_forStart1;
int32_t sjv_y;
int32_t x;

void main_destroy(void);

int main(int argc, char** argv) {
    sjv_y = 0;
    sjt_forStart1 = 2;
    sjt_forEnd1 = 1;
    x = sjt_forEnd1 - 1;
    while (x >= sjt_forStart1) {
        int32_t sjt_math1;
        int32_t sjt_math2;

        sjt_math1 = sjv_y;
        sjt_math2 = x;
        sjv_y = sjt_math1 + sjt_math2;
        x--;
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
