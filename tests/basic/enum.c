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

int32_option sjv_b;
int32_t sjv_bar2_a;
int32_t sjv_bar2_b;
int32_t sjv_bar2_c;
int32_t sjv_bar_a;
int32_t sjv_bar_b;
int32_t sjv_bar_c;

void sjf_func(int32_option* _return);
void main_destroy(void);

void sjf_func(int32_option* _return) {
    int32_t sjt_value1;
    int32_option value1;

    sjt_value1 = sjv_bar_a;
    value1.isvalid = true;
    value1.value = sjt_value1;
    (*_return) = value1;
}

int main(int argc, char** argv) {
    sjv_bar_a = 0;
    sjv_bar_b = 1;
    sjv_bar_c = 2;
    sjv_bar2_a = 0;
    sjv_bar2_b = 1;
    sjv_bar2_c = 2;
    sjf_func(&sjv_b);
    main_destroy();
    #ifdef _DEBUG
    printf("\npress return to end\n");
    getchar();
    #endif
    return 0;
}

void main_destroy() {
}
