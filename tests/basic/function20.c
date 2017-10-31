int bar();
int func();

int bar() {
    return 9;
}

int func() {
    return bar();
}

int main() {
    func();
    return 0;
}
