#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct td_sjs_object sjs_object;

int sjs_object_typeId = 1;

struct td_sjs_object {
    int _refCount;
};

void sjf_global(void);

void sjf_global(void) {
    int32_t ifResult1;

    if (false) {
        ifResult1 = 1;
    } else {
        int32_t ifResult2;

        if (false) {
            ifResult2 = 2;
        } else {
            int32_t ifResult3;

            if (false) {
                ifResult3 = 2;
            } else {
                int32_t ifResult4;

                if (false) {
                    ifResult4 = 2;
                } else {
                    int32_t ifResult5;

                    if (false) {
                        ifResult5 = 2;
                    } else {
                        int32_t ifResult6;

                        if (false) {
                            ifResult6 = 2;
                        } else {
                            int32_t ifResult7;

                            if (false) {
                                ifResult7 = 2;
                            } else {
                                ifResult7 = 3;
                            }

                            ifResult6 = ifResult7;
                        }

                        ifResult5 = ifResult6;
                    }

                    ifResult4 = ifResult5;
                }

                ifResult3 = ifResult4;
            }

            ifResult2 = ifResult3;
        }

        ifResult1 = ifResult2;
    }
}

int main() {
    sjf_global();

    return 0;
}
