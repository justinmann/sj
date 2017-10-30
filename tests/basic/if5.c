int main() {
    int ifResult1;
    int ifResult2;
    int ifResult3;
    int ifResult4;
    int ifResult5;
    int ifResult6;
    int ifResult7;
    if (false) {
        ifResult1 = 1;
    } else {
        if (false) {
            ifResult2 = 2;
        } else {
            if (false) {
                ifResult3 = 2;
            } else {
                if (false) {
                    ifResult4 = 2;
                } else {
                    if (false) {
                        ifResult5 = 2;
                    } else {
                        if (false) {
                            ifResult6 = 2;
                        } else {
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
