#include <stdio.h>
#include <stdlib.h>

int main() {
    int ifResult1;
    if (false) {
        ifResult1 = 1;
    } else {
        int ifResult2;
        if (false) {
            ifResult2 = 2;
        } else {
            int ifResult3;
            if (false) {
                ifResult3 = 2;
            } else {
                int ifResult4;
                if (false) {
                    ifResult4 = 2;
                } else {
                    int ifResult5;
                    if (false) {
                        ifResult5 = 2;
                    } else {
                        int ifResult6;
                        if (false) {
                            ifResult6 = 2;
                        } else {
                            int ifResult7;
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
    ifResult1;
    return 0;
}
