typedef struct class_class {
int _this;
math m;
}

int bar(class _parent, int x);
class class(class_class* _this);
int foo(class _parent, int x);
int sub(int x, int y);

int bar(class _parent, int x) {
    return foo((_parent), (x));
}

class class(class_class* _this) {
    return _this;
}

int foo(class _parent, int x) {
    int ifResult1;
    if ((x) > (0)) {
        ifResult1 = bar((_parent), (_parent->sub((x), (1))));
    } else {
        ifResult1 = 0;
    }
    return ifResult1;
}

int sub(int x, int y) {
    return (x) - (y);
}

int main() {
    class c;
    c = ;
    c->foo((_parent), (4));
    return 0;
}
