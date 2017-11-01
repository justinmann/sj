typedef struct class_class {
int _this;
int m;
}

int sj_class(class_class* _this);
int sj_inner(class* _parent);

int sj_class(class_class* _this) {
    int m;
    m = 1;
    return sj_inner((_parent));
}

int sj_inner(class* _parent) {
    return m;
}

int main() {
    return 0;
}
