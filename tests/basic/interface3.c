#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct td_sji_foo sji_foo;
typedef struct td_sjs_anon1 sjs_anon1;
typedef struct td_sjs_anon2 sjs_anon2;
typedef struct td_sjs_anon3 sjs_anon3;
typedef struct td_sjs_class sjs_class;
typedef struct td_sjs_object sjs_object;

int sji_foo_typeId = 1;
int sjs_anon1_typeId = 2;
int sjs_anon2_typeId = 3;
int sjs_anon3_typeId = 4;
int sjs_class_typeId = 5;
int sjs_object_typeId = 6;

struct td_sji_foo {
    int _refCount;
    sjs_object* _parent;
    void (*destroy)(sjs_object* _this);
    void (*test)(sjs_string* _return);
};

struct td_sjs_anon1 {
    int _refCount;
    uintptr_t _fd;
};

struct td_sjs_anon2 {
    int _refCount;
};

struct td_sjs_anon3 {
    int _refCount;
};

struct td_sjs_class {
    int _refCount;
};

struct td_sjs_object {
    int _refCount;
};

void sjf_anon1(sjs_anon1* _this, sjs_anon1** _return);
void sjf_anon1_destroy(sjs_anon1* _this);
void sjf_anon2(sjs_anon2* _this, sjs_anon2** _return);
void sjf_anon2_destroy(sjs_anon2* _this);
void sjf_anon3(sjs_anon3* _this, sjs_anon3** _return);
void sjf_anon3_destroy(sjs_anon3* _this);
void sjf_class(sjs_class* _this, sjs_class** _return);
void sjf_class_destroy(sjs_class* _this);
void sjf_global(void);

void sjf_anon1(sjs_anon1* _this, sjs_anon1** _return) {
     
		_this->_fd = (uintptr_t)stdout;
	;
    _this->_refCount++;

    *_return = _this;
}

void sjf_anon1_destroy(sjs_anon1* _this) {
}

void sjf_anon2(sjs_anon2* _this, sjs_anon2** _return) {
    _this->_refCount++;

    *_return = _this;
}

void sjf_anon2_destroy(sjs_anon2* _this) {
}

void sjf_anon3(sjs_anon3* _this, sjs_anon3** _return) {
    _this->_refCount++;

    *_return = _this;
}

void sjf_anon3_destroy(sjs_anon3* _this) {
}

void sjf_class(sjs_class* _this, sjs_class** _return) {
    _this->_refCount++;

    *_return = _this;
}

void sjf_class_destroy(sjs_class* _this) {
}

void sjf_global(void) {
    sjs_anon3 sjd_temp1;
    sjs_anon2 sjd_temp2;
    sjs_anon1 sjd_temp3;
    sjs_class sjd_temp4;
    sji_foo* a;
    sjs_anon1* console;
    sjs_anon2* parse;
    sjs_anon3* random;
    uintptr_t result1;
    sji_foo* result2;
    sjs_anon3* sjv_temp1;
    sjs_anon2* sjv_temp2;
    sjs_anon1* sjv_temp3;
    sjs_class* sjv_temp4;

    sjv_temp1 = &sjd_temp1;
    sjv_temp1->_refCount = 1;
    sjf_anon3(sjv_temp1, &sjv_temp1);
    random = sjv_temp1;
    random->_refCount++;
    sjv_temp2 = &sjd_temp2;
    sjv_temp2->_refCount = 1;
    sjf_anon2(sjv_temp2, &sjv_temp2);
    parse = sjv_temp2;
    parse->_refCount++;
    result1 = (uintptr_t)0;
    sjv_temp3 = &sjd_temp3;
    sjv_temp3->_refCount = 1;
    sjv_temp3->_fd = result1;
    sjf_anon1(sjv_temp3, &sjv_temp3);
    console = sjv_temp3;
    console->_refCount++;
    sjv_temp4 = &sjd_temp4;
    sjv_temp4->_refCount = 1;
    sjf_class(sjv_temp4, &sjv_temp4);
    result2 = (sji_foo*)sjv_temp4;
    a = result2;
    a->_refCount++;
    sjf_anon3_destroy(&sjd_temp1);
    sjf_anon2_destroy(&sjd_temp2);
    sjf_anon1_destroy(&sjd_temp3);
    sjf_class_destroy(&sjd_temp4);
}

int main() {
    sjf_global();

    return 0;
}
