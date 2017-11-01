typedef struct class_class {
int _this;
int x;
}

class* sj_class(class_class* _this);
int sj_func(class* _parent);

class* sj_class(class_class* _this) {
    return _this;
}

int sj_func(class* _parent) {
    return x;
}

int main() {
    class* c;
    c = ;
    c->sj_func((_parent));
    return 0;
}
