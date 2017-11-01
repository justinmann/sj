typedef struct class_class {
int _this;
}

int sj_bar(int x);
class* sj_class(class_class* _this);
int sj_foo(int x);

int sj_bar(int x) {
    return sj_foo((x));
}

class* sj_class(class_class* _this) {
    return _this;
}

int sj_foo(int x) {
    int ifResult1;
    if ((x) > (0)) {
        ifResult1 = sj_bar(((x) - (1)));
    } else {
        ifResult1 = 0;
    }
    return ifResult1;
}

int main() {
    class* c;
    c = ;
    c->sj_foo((4));
    return 0;
}
