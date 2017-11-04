#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int32_t sjf_global();

int32_t sjf_global() {
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
    return ifResult1;
}

int main() {
    int32_t result1;
    result1 = sjf_global();
    return 0;
}
