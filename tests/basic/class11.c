typedef struct class_class {
int _this;
int x;
}

class class(class_class* _this);
class func();

class class(class_class* _this) {
    return _this;
}

class func() {
}

int main() {
    func()->x;
    return 0;
}
