typedef struct class_class {
    int _this;
    int x;
}

class* sj_class(class_class* _this);
class* sj_func();

class* sj_class(class_class* _this) {
    return _this;
}

class* sj_func() {
    class* objectRef1;
    return sj_class(objectRef1);
}

int main() {
    sj_func()->x;
    return 0;
}
