#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct td_int32_option int32_option;
struct td_int32_option {
    bool isempty;
    int32_t value;
};
const int32_option int32_empty = { true };

typedef struct td_uint32_option uint32_option;
struct td_uint32_option {
    bool isempty;
    uint32_t value;
};
const uint32_option uint32_empty = { true };

typedef struct td_int64_option int64_option;
struct td_int64_option {
    bool isempty;
    int64_t value;
};
const int64_option int64_empty = { true };

typedef struct td_uint64_option uint64_option;
struct td_uint64_option {
    bool isempty;
    uint64_t value;
};
const uint64_option uint64_empty = { true };

typedef struct td_void_option void_option;
struct td_void_option {
    bool isempty;
    void* value;
};
const void_option void_empty = { true };

typedef struct td_char_option char_option;
struct td_char_option {
    bool isempty;
    char value;
};
const char_option char_empty = { true };

typedef struct td_float_option float_option;
struct td_float_option {
    bool isempty;
    float value;
};
const float_option float_empty = { true };

typedef struct td_double_option double_option;
struct td_double_option {
    bool isempty;
    double value;
};
const double_option double_empty = { true };

#define sjs_object_typeId 1
#define sjs_foo_typeId 2

typedef struct td_sjs_object sjs_object;
typedef struct td_sjs_foo sjs_foo;

struct td_sjs_object {
    intptr_t _refCount;
};

struct td_sjs_foo {
    int _refCount;
};

sjs_foo sjt_call1 = { -1 };
sjs_foo* sjt_copy1 = 0;
sjs_foo* sjt_copy2 = 0;
sjs_foo* sjt_copy3 = 0;
sjs_foo* sjt_copy4 = 0;
sjs_foo* sjt_copy5 = 0;
sjs_foo* sjv_heap_x1 = 0;
sjs_foo* sjv_heap_x2 = 0;
sjs_foo* sjv_heap_x3 = 0;
sjs_foo* sjv_heap_y = 0;
sjs_foo* sjv_local_x1 = 0;
sjs_foo* sjv_local_x2 = 0;
sjs_foo* sjv_local_x3 = 0;
sjs_foo* sjv_local_y = 0;
sjs_foo sjv_stack_x1 = { -1 };
sjs_foo sjv_stack_x2 = { -1 };
sjs_foo sjv_stack_x3 = { -1 };
sjs_foo sjv_stack_y = { -1 };

void sjf_foo(sjs_foo* _this);
void sjf_foo_copy(sjs_foo* _this, sjs_foo* _from);
void sjf_foo_destroy(sjs_foo* _this);
void sjf_foo_heap(sjs_foo* _this);
void main_destroy(void);

void sjf_foo(sjs_foo* _this) {
}

void sjf_foo_copy(sjs_foo* _this, sjs_foo* _from) {
}

void sjf_foo_destroy(sjs_foo* _this) {
}

void sjf_foo_heap(sjs_foo* _this) {
}

int main(int argc, char** argv) {
    sjv_heap_y = (sjs_foo*)malloc(sizeof(sjs_foo));
    sjv_heap_y->_refCount = 1;
    sjf_foo_heap(sjv_heap_y);
    sjv_stack_y._refCount = 1;
    sjf_foo(&sjv_stack_y);
    sjt_call1._refCount = 1;
    sjf_foo(&sjt_call1);
    sjv_local_y = &sjt_call1;
    sjv_heap_x1 = sjv_heap_y;
    sjv_heap_x1->_refCount++;
    sjt_copy1 = &sjv_stack_y;
    sjv_heap_x2 = (sjs_foo*)malloc(sizeof(sjs_foo));
    sjv_heap_x2->_refCount = 1;
    sjf_foo_copy(sjv_heap_x2, sjt_copy1);
    sjt_copy2 = sjv_local_y;
    sjv_heap_x3 = (sjs_foo*)malloc(sizeof(sjs_foo));
    sjv_heap_x3->_refCount = 1;
    sjf_foo_copy(sjv_heap_x3, sjt_copy2);
    sjt_copy3 = &sjv_stack_y;
    sjv_stack_x1._refCount = 1;
    sjf_foo_copy(&sjv_stack_x1, sjt_copy3);
    sjt_copy4 = sjv_heap_y;
    sjt_copy4->_refCount++;
    sjv_stack_x2._refCount = 1;
    sjf_foo_copy(&sjv_stack_x2, sjt_copy4);
    sjt_copy5 = sjv_local_y;
    sjv_stack_x3._refCount = 1;
    sjf_foo_copy(&sjv_stack_x3, sjt_copy5);
    sjv_local_x1 = sjv_heap_y;
    sjv_local_x2 = &sjv_stack_y;
    sjv_local_x3 = sjv_local_y;
    main_destroy();
    #ifdef _DEBUG
    printf("\npress return to end\n");
    getchar();
    #endif
    return 0;
}

void main_destroy() {

    sjt_copy4->_refCount--;
    if (sjt_copy4->_refCount <= 0) {
        weakptr_release(sjt_copy4);
        sjf_foo_destroy(sjt_copy4);
    }
    sjv_heap_x1->_refCount--;
    if (sjv_heap_x1->_refCount <= 0) {
        weakptr_release(sjv_heap_x1);
        sjf_foo_destroy(sjv_heap_x1);
    }
    sjv_heap_x2->_refCount--;
    if (sjv_heap_x2->_refCount <= 0) {
        weakptr_release(sjv_heap_x2);
        sjf_foo_destroy(sjv_heap_x2);
    }
    sjv_heap_x3->_refCount--;
    if (sjv_heap_x3->_refCount <= 0) {
        weakptr_release(sjv_heap_x3);
        sjf_foo_destroy(sjv_heap_x3);
    }
    sjv_heap_y->_refCount--;
    if (sjv_heap_y->_refCount <= 0) {
        weakptr_release(sjv_heap_y);
        sjf_foo_destroy(sjv_heap_y);
    }
    if (sjt_call1._refCount == 1) { sjf_foo_destroy(&sjt_call1); }
    if (sjv_stack_x1._refCount == 1) { sjf_foo_destroy(&sjv_stack_x1); }
    if (sjv_stack_x2._refCount == 1) { sjf_foo_destroy(&sjv_stack_x2); }
    if (sjv_stack_x3._refCount == 1) { sjf_foo_destroy(&sjv_stack_x3); }
    if (sjv_stack_y._refCount == 1) { sjf_foo_destroy(&sjv_stack_y); }
}
