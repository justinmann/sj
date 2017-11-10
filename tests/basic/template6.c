#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

typedef struct td_sjs_object sjs_object;

int sjs_object_typeId = 1;

struct td_sjs_object {
    int _refCount;
};

void sjf_class_func_i32(int32_t* _return);
void sjf_global(void);

void sjf_class_func_i32(int32_t* _return) {

    *_return = 1;
}

void sjf_global(void) {
    int32_t d;
    int32_t result1;

    result1 = 0;
    sjf_class_func_i32(&result1);
    d = result1;
}

int main() {
    sjf_global();

    return 0;
}
