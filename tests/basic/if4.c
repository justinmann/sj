int main() {
    int ifResult1;
    int ifResult2;
    if (false) {
        ifResult1 = 1;
    } else {
        if (true) {
            ifResult2 = 2;
        }
        ifResult1 = ifResult2;
    }
    ifResult1;
    return 0;
}
