#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define sjs_object_typeId 1
#define sjs_interface_typeId 2
#define sjs_class_i32_typeId 3

typedef struct td_sjs_object sjs_object;
typedef struct td_sjs_interface sjs_interface;
typedef struct td_sjs_class_i32 sjs_class_i32;

struct td_sjs_object {
    intptr_t _refCount;
};

struct td_sjs_interface {
    sjs_object* _parent;
    void* _vtbl;
};

struct td_sjs_class_i32 {
    int _refCount;
};

sjs_class_i32 sjv_c = { -1 };

void sjf_class_i32(sjs_class_i32* _this);
void sjf_class_i32_copy(sjs_class_i32* _this, sjs_class_i32* _from);
void sjf_class_i32_destroy(sjs_class_i32* _this);
void sjf_class_i32_heap(sjs_class_i32* _this);
void main_destroy(void);

void sjf_class_i32(sjs_class_i32* _this) {
}

void sjf_class_i32_copy(sjs_class_i32* _this, sjs_class_i32* _from) {
}

void sjf_class_i32_destroy(sjs_class_i32* _this) {
}

void sjf_class_i32_heap(sjs_class_i32* _this) {
}

int main(int argc, char** argv) {
    sjv_c._refCount = 1;
    sjf_class_i32(&sjv_c);
    main_destroy();
    #ifdef _DEBUG
    printf("\npress return to end\n");
    getchar();
    #endif
    return 0;
}

void main_destroy() {

    if (sjv_c._refCount == 1) { sjf_class_i32_destroy(&sjv_c); }
}
