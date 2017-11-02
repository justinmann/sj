typedef struct {
    sjs_global* _parent;
} sjs_class;

sjs_anon_0* sjf_anon_0(sjs_anon_0* _this);
int sjf_bar(sjs_class* _parent, int x);
sjs_class* sjf_class(sjs_class* _this);
int sjf_foo(sjs_class* _parent, int x);
int sjf_sub(int x, int y);

sjs_anon_0* sjf_anon_0(sjs_anon_0* _this) {
    return _this;
}

int sjf_bar(sjs_class* _parent, int x) {
    return sjf_foo((_parent), (x));
}

sjs_class* sjf_class(sjs_class* _this) {
    return _this;
}

int sjf_foo(sjs_class* _parent, int x) {
    int ifResult1;
    if ((x) > (0)) {
        ifResult1 = sjf_bar((_parent), (_parent->_parent->mathsjf_sub((x), (1))));
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
    sjs_anon_0* sjv_temp1;
    sjs_class* sjv_temp2;
    sjv_temp1 = malloc(sizeof(sjs_anon_0));
    math = sjf_anon_0(sjv_temp1);
    sjv_temp2 = &sjd_temp1;
    c = sjf_class(sjv_temp2);
    sjf_foo((c), (4));
    return 0;
}
