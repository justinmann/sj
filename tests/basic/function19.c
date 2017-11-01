int sj_func(int x);

int sj_func(int x) {
    int ifResult1;
    if ((x) > (0)) {
        ifResult1 = sj_func(((x) - (1)));
    } else {
        ifResult1 = 0;
    }
    return ifResult1;
}

int main() {
    sj_func((4));
    return 0;
}
