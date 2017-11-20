#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct td_int32_option int32_option;
struct td_int32_option {
    bool isEmpty;
    int32_t value;
};
const int32_option int32_empty = { true };

typedef struct td_uint32_option uint32_option;
struct td_uint32_option {
    bool isEmpty;
    uint32_t value;
};
const uint32_option uint32_empty = { true };

typedef struct td_int64_option int64_option;
struct td_int64_option {
    bool isEmpty;
    int64_t value;
};
const int64_option int64_empty = { true };

typedef struct td_uint64_option uint64_option;
struct td_uint64_option {
    bool isEmpty;
    uint64_t value;
};
const uint64_option uint64_empty = { true };

typedef struct td_uintptr_option uintptr_option;
struct td_uintptr_option {
    bool isEmpty;
    uintptr_t value;
};
const uintptr_option uintptr_empty = { true };

typedef struct td_char_option char_option;
struct td_char_option {
    bool isEmpty;
    char value;
};
const char_option char_empty = { true };

typedef struct td_float_option float_option;
struct td_float_option {
    bool isEmpty;
    float value;
};
const float_option float_empty = { true };

typedef struct td_double_option double_option;
struct td_double_option {
    bool isEmpty;
    double value;
};
const double_option double_empty = { true };

#define sjs_object_typeId 1
#define sjs_foo_typeId 2
#define sjs_foo_heap_typeId 3

typedef struct td_sjs_object sjs_object;
typedef struct td_sjs_foo sjs_foo;
typedef struct td_sjs_foo_heap sjs_foo_heap;

struct td_sjs_object {
    int _refCount;
};

struct td_sjs_foo {
    int structsNeedAValue;
};

struct td_sjs_foo_heap {
    int _refCount;
};

void sjf_foo(sjs_foo* _this);
void sjf_foo_copy(sjs_foo* _this, sjs_foo* to);
void sjf_foo_destroy(sjs_foo* _this);
void sjf_foo_heap(sjs_foo_heap* _this);


void sjf_foo(sjs_foo* _this) {
}

void sjf_foo_copy(sjs_foo* _this, sjs_foo* to) {
}

void sjf_foo_destroy(sjs_foo* _this) {
}

void sjf_foo_heap(sjs_foo_heap* _this) {
}

int main() {
    sjs_foo_heap* heap_x1;
    sjs_foo_heap* heap_x2;
    sjs_foo_heap* heap_x3;
    sjs_foo_heap* heap_y;
    sjs_foo* local_x1;
    sjs_foo* local_x2;
    sjs_foo* local_x3;
    sjs_foo* local_y;
    sjs_foo stack_x1;
    sjs_foo stack_x2;
    sjs_foo stack_x3;
    sjs_foo stack_y;

    heap_y = (sjs_foo_heap*)malloc(sizeof(sjs_foo_heap));
    heap_y->_refCount = 1;
    sjf_foo_heap(heap_y);
    sjf_foo(&stack_y);
    sjf_foo(local_y);
    heap_x1 = heap_y;
    heap_x1->_refCount++;
    heap_x2 = (sjs_foo_heap*)malloc(sizeof(sjs_foo_heap));
    heap_x2->_refCount = 1;
    sjf_foo_copy((sjs_foo*)(((char*)heap_x2) + sizeof(int)), &stack_y);
    heap_x3 = (sjs_foo_heap*)malloc(sizeof(sjs_foo_heap));
    heap_x3->_refCount = 1;
    sjf_foo_copy((sjs_foo*)(((char*)heap_x3) + sizeof(int)), local_y);
    sjf_foo_copy(&stack_x1, &stack_y);
    sjf_foo_copy(&stack_x2, (sjs_foo*)(((char*)heap_y) + sizeof(int)));
    sjf_foo_copy(&stack_x3, local_y);
    local_x1 = (sjs_foo*)(((char*)heap_y) + sizeof(int));
    local_x2 = &stack_y;
    local_x3 = local_y;

    heap_x1->_refCount--;
    if (heap_x1->_refCount <= 0) {
        sjf_foo_destroy((sjs_foo*)(((char*)heap_x1) + sizeof(int)));
    }
    heap_x2->_refCount--;
    if (heap_x2->_refCount <= 0) {
        sjf_foo_destroy((sjs_foo*)(((char*)heap_x2) + sizeof(int)));
    }
    heap_x3->_refCount--;
    if (heap_x3->_refCount <= 0) {
        sjf_foo_destroy((sjs_foo*)(((char*)heap_x3) + sizeof(int)));
    }
    heap_y->_refCount--;
    if (heap_y->_refCount <= 0) {
        sjf_foo_destroy((sjs_foo*)(((char*)heap_y) + sizeof(int)));
    }
    sjf_foo_destroy(&stack_x1);
    sjf_foo_destroy(&stack_x2);
    sjf_foo_destroy(&stack_x3);
    sjf_foo_destroy(&stack_y);
    return 0;
}
