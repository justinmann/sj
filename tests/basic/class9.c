typedef struct class_class {
    int _this;
}

class* sj_class(class_class* _this);
int sj_func();

class* sj_class(class_class* _this) {
    return _this;
}

int sj_func() {
    return 1;
}

int main() {
    class* c;
    class* objectRef1;
    c = sj_class(objectRef1);
    csj_func();
    return 0;
}
