#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define sjs_object_typeId 1
#define sjs_interface_typeId 2
#define sjs_func_typeId 3

typedef struct td_sjs_object sjs_object;
typedef struct td_sjs_interface sjs_interface;
typedef struct td_sjs_func sjs_func;

struct td_sjs_object {
    intptr_t _refCount;
};

struct td_sjs_interface {
    sjs_object* _parent;
    void* _vtbl;
};

struct td_sjs_func {
    int _refCount;
    int32_t x;
    int32_t y;
    int32_t z;
};

sjs_func void1 = { -1 };
sjs_func void2 = { -1 };

void sjf_func(sjs_func* _this);
void sjf_func_copy(sjs_func* _this, sjs_func* _from);
void sjf_func_destroy(sjs_func* _this);
void sjf_func_heap(sjs_func* _this);
void main_destroy(void);

void sjf_func(sjs_func* _this) {
}

void sjf_func_copy(sjs_func* _this, sjs_func* _from) {
    _this->x = _from->x;
    _this->y = _from->y;
    _this->z = _from->z;
}

void sjf_func_destroy(sjs_func* _this) {
}

void sjf_func_heap(sjs_func* _this) {
}

int main(int argc, char** argv) {
    void1._refCount = 1;
    void1.x = 4;
    void1.y = 5;
    void1.z = 6;
    sjf_func(&void1);
    void2._refCount = 1;
    void2.x = 7;
    void2.y = 8;
    void2.z = 9;
    sjf_func(&void2);
    main_destroy();
    #ifdef _DEBUG
    printf("\npress return to end\n");
    getchar();
    #endif
    return 0;
}

void main_destroy() {

    if (void1._refCount == 1) { sjf_func_destroy(&void1); }
    if (void2._refCount == 1) { sjf_func_destroy(&void2); }
}
