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
}

int main() {
    sj_func()->x;
    return 0;
}
