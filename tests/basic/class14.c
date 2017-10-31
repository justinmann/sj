typedef struct class_class {
int _this;
int m;
}

int class(class_class* _this);
int inner(class _parent);

int class(class_class* _this) {
    int m;
    m = 1;
    return inner((_parent));
}

int inner(class _parent) {
    return m;
}

int main() {
    return 0;
}
