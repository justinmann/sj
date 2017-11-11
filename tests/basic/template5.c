#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

#define sjs_object_typeId 1

typedef struct td_sjs_object sjs_object;

struct td_sjs_object {
    int _refCount;
};

void sjf_class_f32_func(int32_t* _return);
void sjf_class_func_i32(int32_t* _return);
void sjf_global(void);

void sjf_class_f32_func(int32_t* _return) {

    *_return = 1;
}

void sjf_class_func_i32(int32_t* _return) {

    *_return = 1;
}

void sjf_global(void) {
    int32_t b;
    int32_t d;
    int32_t result1;
    int32_t result2;

    result1 = 0;
    sjf_class_f32_func(&result1);
    b = result1;
    result2 = 0;
    sjf_class_func_i32(&result2);
    d = result2;
}

int main() {
    sjf_global();

    return 0;
}
