int main() {
    int ifResult1;
    if (false) {
        ifResult1 = 1;
    } else {
        int ifResult2;
        if (true) {
            ifResult2 = 2;
        }
        ifResult1 = ifResult2;
    }
    ifResult1;
    return 0;
}
