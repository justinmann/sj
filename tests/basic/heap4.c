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
#define sjs_a_typeId 2
#define sjs_b_typeId 3
#define sjs_c_typeId 4

typedef struct td_sjs_object sjs_object;
typedef struct td_sjs_a sjs_a;
typedef struct td_sjs_b sjs_b;
typedef struct td_sjs_c sjs_c;

struct td_sjs_object {
    intptr_t _refCount;
};

struct td_sjs_a {
    int _refCount;
};

struct td_sjs_b {
    int _refCount;
    sjs_a a;
};

struct td_sjs_c {
    int _refCount;
    sjs_b b;
};

sjs_c void1;

void sjf_a(sjs_a* _this);
void sjf_a_copy(sjs_a* _this, sjs_a* _from);
void sjf_a_destroy(sjs_a* _this);
void sjf_a_heap(sjs_a* _this);
void sjf_b(sjs_b* _this);
void sjf_b_copy(sjs_b* _this, sjs_b* _from);
void sjf_b_destroy(sjs_b* _this);
void sjf_b_heap(sjs_b* _this);
void sjf_c(sjs_c* _this);
void sjf_c_copy(sjs_c* _this, sjs_c* _from);
void sjf_c_destroy(sjs_c* _this);
void sjf_c_heap(sjs_c* _this);
void main_destroy(void);

void sjf_a(sjs_a* _this) {
}

void sjf_a_copy(sjs_a* _this, sjs_a* _from) {
}

void sjf_a_destroy(sjs_a* _this) {
}

void sjf_a_heap(sjs_a* _this) {
}

void sjf_b(sjs_b* _this) {
}

void sjf_b_copy(sjs_b* _this, sjs_b* _from) {
    sjf_a_copy(&_this->a, &_from->a);
}

void sjf_b_destroy(sjs_b* _this) {
}

void sjf_b_heap(sjs_b* _this) {
}

void sjf_c(sjs_c* _this) {
}

void sjf_c_copy(sjs_c* _this, sjs_c* _from) {
    sjf_b_copy(&_this->b, &_from->b);
}

void sjf_c_destroy(sjs_c* _this) {
}

void sjf_c_heap(sjs_c* _this) {
}

int main(int argc, char** argv) {
    sjf_a(&void1.b.a);
    sjf_b(&void1.b);
    sjf_c(&void1);
    main_destroy();
    #ifdef _DEBUG
    printf("\npress return to end\n");
    getchar();
    #endif
    return 0;
}

void main_destroy() {

    sjf_c_destroy(&void1);
}
