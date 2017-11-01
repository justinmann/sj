int sjf_func(int x);

int sjf_func(int x) {
    int ifResult1;
    if ((x) > (0)) {
        ifResult1 = sjf_func(((x) - (1)));
    } else {
        ifResult1 = 0;
    }
    return ifResult1;
}

int main() {
    sjf_func((4));
    return 0;
}
