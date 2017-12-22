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
float sjt_math10;
double sjt_math11;
double sjt_math12;
int32_t sjt_math2;
uint32_t sjt_math3;
uint32_t sjt_math4;
uint64_t sjt_math5;
uint64_t sjt_math6;
int64_t sjt_math7;
int64_t sjt_math8;
float sjt_math9;
int32_t sjv_a;
uint32_t sjv_b;
uint64_t sjv_c;
int64_t sjv_d;
float sjv_e;
double sjv_f;

void main_destroy(void);

int main(int argc, char** argv) {
    sjt_math1 = 4;
    sjt_math2 = 5;
    sjv_a = sjt_math1 + sjt_math2;
    sjt_math3 = (uint32_t)4u;
    sjt_math4 = (uint32_t)5u;
    sjv_b = sjt_math3 + sjt_math4;
    sjt_math5 = 4ull;
    sjt_math6 = 5ull;
    sjv_c = sjt_math5 + sjt_math6;
    sjt_math7 = 4ll;
    sjt_math8 = 5ll;
    sjv_d = sjt_math7 + sjt_math8;
    sjt_math9 = 4.0f;
    sjt_math10 = 5.0f;
    sjv_e = sjt_math9 + sjt_math10;
    sjt_math11 = 4.0;
    sjt_math12 = 5.0;
    sjv_f = sjt_math11 + sjt_math12;
    main_destroy();
    #ifdef _DEBUG
    printf("\npress return to end\n");
    getchar();
    #endif
    return 0;
}

void main_destroy() {
}
