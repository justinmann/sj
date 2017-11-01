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
    a = ;
    a->b->sj_c((_parent));
    d = a->b;
    d->sj_c((_parent));
    return 0;
}
