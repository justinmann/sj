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
int32_option sjt_isEmpty1;
int32_t sjt_value1;
int32_option sjv_b;
int32_t sjv_c;
int32_t sjv_foo_abb;
int32_t sjv_foo_bbb;
int32_option value1;

void main_destroy(void);

int main(int argc, char** argv) {
    sjv_foo_abb = 0;
    sjv_foo_bbb = 1;
    sjt_value1 = sjv_foo_abb;
    value1.isvalid = true;
    value1.value = sjt_value1;
    sjv_b = value1;
    sjt_isEmpty1 = sjv_b;
    sjt_ifElse1 = sjt_isEmpty1.isvalid;
    if (sjt_ifElse1) {
        int32_option sjt_getValue1;

        sjt_getValue1 = sjv_b;
        sjv_c = sjt_getValue1.value;
    } else {
        sjv_c = sjv_foo_bbb;
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
