typedef struct class_class {
    int _this;
    math m;
}

int sj_bar(class* _parent, int x);
class* sj_class(class_class* _this);
int sj_foo(class* _parent, int x);
int sj_sub(int x, int y);

int sj_bar(class* _parent, int x) {
    return sj_foo((_parent), (x));
}

class* sj_class(class_class* _this) {
    return _this;
}

int sj_foo(class* _parent, int x) {
    int ifResult1;
    if ((x) > (0)) {
        ifResult1 = sj_bar((_parent), (_parent->sj_sub((x), (1))));
    } else {
        ifResult1 = 0;
    }
    return ifResult1;
}

int sj_sub(int x, int y) {
    return (x) - (y);
}

int main() {
    class* c;
    class* objectRef1;
    c = sj_class(objectRef1);
    c->sj_foo((_parent), (4));
    return 0;
}
