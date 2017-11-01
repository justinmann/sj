typedef struct {
    sjs_math* m;
} sjs_class;

int sjf_bar(sjs_class* _parent, int x);
sjs_class* sjf_class(sjs_class* _this);
int sjf_foo(sjs_class* _parent, int x);
int sjf_sub(int x, int y);

int sjf_bar(sjs_class* _parent, int x) {
    return sjf_foo((_parent), (x));
}

sjs_class* sjf_class(sjs_class* _this) {
    return _this;
}

int sjf_foo(sjs_class* _parent, int x) {
    int ifResult1;
    if ((x) > (0)) {
        ifResult1 = sjf_bar((_parent), (_parentsjf_sub((x), (1))));
    } else {
        ifResult1 = 0;
    }
    return ifResult1;
}

int sjf_sub(int x, int y) {
    return (x) - (y);
}

int main() {
    sjs_class* c;
    sjs_class sjd_temp1;
    sjs_class* sjv_temp1;
    sjv_temp1 = &sjd_temp1;
    c = sjf_class(sjv_temp1);
    csjf_foo((_parent), (4));
    return 0;
}
