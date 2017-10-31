typedef struct class_class {
int _this;
}

class class(class_class* _this);
int func();

class class(class_class* _this) {
    return _this;
}

int func() {
    return 1;
}

int main() {
    class c;
    c = ;
    c->func();
    return 0;
}
