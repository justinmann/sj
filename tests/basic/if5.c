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

bool sjt_ifElse1;

void main_destroy(void);

int main(int argc, char** argv) {
    sjt_ifElse1 = false;
    if (sjt_ifElse1) {
    } else {
        bool sjt_ifElse2;

        sjt_ifElse2 = false;
        if (sjt_ifElse2) {
        } else {
            bool sjt_ifElse3;

            sjt_ifElse3 = false;
            if (sjt_ifElse3) {
            } else {
                bool sjt_ifElse4;

                sjt_ifElse4 = false;
                if (sjt_ifElse4) {
                } else {
                    bool sjt_ifElse5;

                    sjt_ifElse5 = false;
                    if (sjt_ifElse5) {
                    } else {
                        bool sjt_ifElse6;

                        sjt_ifElse6 = false;
                        if (sjt_ifElse6) {
                        } else {
                            bool sjt_ifElse7;

                            sjt_ifElse7 = false;
                            if (sjt_ifElse7) {
                            } else {
                            }
                        }
                    }
                }
            }
        }
    }
    main_destroy();
    #ifdef _DEBUG
    printf("\npress return to end\n");
    getchar();
    #endif
    return 0;
}

void main_destroy() {
}
