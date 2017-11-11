#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

#define sjs_object_typeId 1

typedef struct td_sjs_object sjs_object;

struct td_sjs_object {
    int _refCount;
};

void sjf_class_bool(int32_t* _return);
void sjf_class_f32(int32_t* _return);
void sjf_class_i32(int32_t* _return);
void sjf_global(void);

void sjf_class_bool(int32_t* _return) {

    *_return = 1;
}

void sjf_class_f32(int32_t* _return) {

    *_return = 1;
}

void sjf_class_i32(int32_t* _return) {

    *_return = 1;
}

void sjf_global(void) {
    int32_t a;
    int32_t b;
    int32_t c;
    int32_t result1;
    int32_t result2;
    int32_t result3;

    result1 = 0;
    sjf_class_i32(&result1);
    a = result1;
    result2 = 0;
    sjf_class_f32(&result2);
    b = result2;
    result3 = 0;
    sjf_class_bool(&result3);
    c = result3;
}

int main() {
    sjf_global();

    return 0;
}
