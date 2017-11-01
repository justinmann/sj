int sj_bar();
int sj_func();

int sj_bar() {
    return 9;
}

int sj_func() {
    return sj_bar();
}

int main() {
    sj_func();
    return 0;
}
