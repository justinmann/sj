typedef struct class_class {
    int _this;
    int b;
}

class* sj_class(class_class* _this);

class* sj_class(class_class* _this) {
    return _this;
}

int main() {
    class* a;
    class* objectRef1;
    a = sj_class(objectRef1);
    a = 1;
    return 0;
}
