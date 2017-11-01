typedef struct class_a {
    int _this;
    int x;
    aa b;
}

a* sj_a(class_a* _this);
int sj_c(aa* _parent);

a* sj_a(class_a* _this) {
    return _this;
}

int sj_c(aa* _parent) {
    return x;
}

int main() {
    a* a;
    aa* d;
    a* objectRef1;
    a = sj_a(objectRef1);
    a->bsj_c((_parent));
    d = a->b;
    dsj_c((_parent));
    return 0;
}
