typedef struct class_class {
int _this;
int x;
int y;
}

class* sj_class(class_class* _this);

class* sj_class(class_class* _this) {
    return _this;
}

int main() {
    class* c;
    c = ;
    (c->x) + (c->y);
    return 0;
}
