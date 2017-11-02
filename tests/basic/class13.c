typedef struct {
    sjs_math* m;
} sjs_class;

sjs_class* sjf_class(sjs_class* _this);
int sjf_class_bar(sjs_class* _parent, int x);
int sjf_class_foo(sjs_class* _parent, int x);
sjs_math* sjf_math(sjs_math* _this);
int sjf_math_sub(int x, int y);

sjs_class* sjf_class(sjs_class* _this) {
    return _this;
}

int sjf_class_bar(sjs_class* _parent, int x) {
    return sjf_class_foo((_parent), (x));
}

int sjf_class_foo(sjs_class* _parent, int x) {
    int ifResult1;
    if ((x) > (0)) {
        ifResult1 = sjf_class_bar((_parent), (_parent->msjf_math_sub((x), (1))));
    } else {
        ifResult1 = 0;
    }
    return ifResult1;
}

sjs_math* sjf_math(sjs_math* _this) {
    return _this;
}

int sjf_math_sub(int x, int y) {
    return (x) - (y);
}

int main() {
    sjs_class* c;
    sjs_math sjd_temp1;
    sjs_class sjd_temp2;
    sjs_math* sjv_temp1;
    sjs_class* sjv_temp2;
    sjv_temp1 = &sjd_temp1;
    sjv_temp2 = &sjd_temp2;
    sjv_temp2->m = sjf_math(sjv_temp1);
    c = sjf_class(sjv_temp2);
    sjf_class_foo((c), (4));
    return 0;
}
