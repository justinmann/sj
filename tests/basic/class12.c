typedef struct class_class {
int _this;
}

int bar(int x);
class class(class_class* _this);
int foo(int x);

int bar(int x) {
    return foo((x));
}

class class(class_class* _this) {
    return _this;
}

int foo(int x) {
    int ifResult1;
    if ((x) > (0)) {
        ifResult1 = bar(((x) - (1)));
    } else {
        ifResult1 = 0;
    }
    return ifResult1;
}

int main() {
    class c;
    c = ;
    c->foo((4));
    return 0;
}
