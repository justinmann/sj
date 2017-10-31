typedef struct class_class {
int _this;
int x;
}

class class(class_class* _this);
int func(class _parent);

class class(class_class* _this) {
    return _this;
}

int func(class _parent) {
    return x;
}

int main() {
    class c;
    c = ;
    c->func((_parent));
    return 0;
}
