int sjf_bar(int x);
sjs_class* sjf_class(sjs_class* _this);
int sjf_foo(int x);

int sjf_bar(int x) {
    return sjf_foo((x));
}

sjs_class* sjf_class(sjs_class* _this) {
    return _this;
}

int sjf_foo(int x) {
    int ifResult1;
    if ((x) > (0)) {
        ifResult1 = sjf_bar(((x) - (1)));
    } else {
        ifResult1 = 0;
    }
    return ifResult1;
}

int main() {
    sjs_class* c;
    sjs_class sjd_temp1;
    sjs_class* sjv_temp1;
    sjv_temp1 = &sjd_temp1;
    c = sjf_class(sjv_temp1);
    csjf_foo((4));
    return 0;
}
