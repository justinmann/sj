int func(int x);

int func(int x) {
    int ifResult1;
    if ((x) > (0)) {
        ifResult1 = func(((x) - (1)));
    } else {
        ifResult1 = 0;
    }
    return ifResult1;
}

int main() {
    func((4));
    return 0;
}
