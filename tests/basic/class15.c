typedef struct class_anon_0 {
    int _this;
}

typedef struct class_class {
    int _this;
    global _parent;
}

anon_0* sj_anon_0(class_anon_0* _this);
int sj_bar(class* _parent, int x);
class* sj_class(class_class* _this);
int sj_foo(class* _parent, int x);
int sj_sub(int x, int y);

anon_0* sj_anon_0(class_anon_0* _this) {
    return _this;
}

int sj_bar(class* _parent, int x) {
    return sj_foo((_parent), (x));
}

class* sj_class(class_class* _this) {
    return _this;
}

int sj_foo(class* _parent, int x) {
    int ifResult1;
    if ((x) > (0)) {
        ifResult1 = sj_bar((_parent), (_parentsj_sub((x), (1))));
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
    anon_0* math;
    anon_0* objectRef1;
    class* objectRef2;
    math = sj_anon_0(objectRef1);
    c = sj_class(objectRef2);
    csj_foo((_parent), (4));
    return 0;
}
